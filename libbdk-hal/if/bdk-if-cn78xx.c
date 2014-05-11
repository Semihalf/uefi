#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

/* PKO uses three scratch dwords, two for commands and one for return status */
#define BDK_IF_SCR_PKO(dword) (BDK_IF_SCR_LMTDMA + (dword<<3))

static const int PKO_QUEUES_PER_CHANNEL = 1;
static const int PKO_POOL_BUFFERS = 256;
static const int MAX_SSO_ENTRIES = 1024;
static const int PKO_DEPTH_LIMIT = 256; /* Max packets to have pending in PKO queues */
extern const uint64_t __BDK_PKI_MICROCODE_CN78XX[];
extern const int __BDK_PKI_MICROCODE_CN78XX_LENGTH;

typedef struct
{
    /* PKI global variables */
    __bdk_if_port_t *__bdk_if_ipd_map[0x1000]; /* Channels is 12 bits in WQE */
    int next_free_qpg_table;
    int next_free_pknd;
    int next_wqe_grp;

    /* PKO global variables */
    uint64_t pko_free_fifo_mask;    /* PKO_PTGFX_CFG(7) is reserved for NULL MAC */
    int pko_next_free_port_queue;   /* L1 = Port Queues are 0-31 */
    int pko_next_free_l2_queue;     /* L2 = Channel Queues 0-511 */
    int pko_next_free_l3_queue;     /* L3 = Channel Queues 0-511 */
    int pko_next_free_l4_queue;     /* L4 = Channel Queues 0-511 */
    int pko_next_free_l5_queue;     /* L5 = Channel Queues 0-511 */
    int pko_next_free_descr_queue;  /* L6 = Descriptor Queues 0-1023 */
} global_node_state_t;

static global_node_state_t global_node_state[BDK_NUMA_MAX_NODES];

/**
 * One time init of global Packet Input
 *
 * @return Zero on success, negative on failure
 */
static int pki_global_init(bdk_node_t node)
{
    global_node_state_t *node_state = &global_node_state[node];
    bdk_zero_memory(node_state, sizeof(*node_state));
    node_state->pko_free_fifo_mask = 0x0fffffff; /* PKO_PTGFX_CFG(7) is reserved for NULL MAC */

    /* Load microcode */
    for (int i=0; i<__BDK_PKI_MICROCODE_CN78XX_LENGTH; i++)
        BDK_CSR_WRITE(node, BDK_PKI_IMEMX(i), __BDK_PKI_MICROCODE_CN78XX[i]);

    /* Setup all Auras to support backpressure */
    for (int aura=0; aura<1024; aura++)
    {
        BDK_CSR_MODIFY(c, node, BDK_PKI_AURAX_CFG(aura),
            c.s.pkt_add = 0; /* Increment was already done in FPA alloc */
            c.s.ena_red = 1; /* Enable RED */
            c.s.ena_drop = 1; /* Enable drop */
            c.s.ena_bp = 1; /* Enable backpressure */
            c.s.bpid = aura); /* 1:1 mapping between aura and bpid */
    }
    /* Setup defaults for PKNDs on all parsing clusters */
    for (int cluster=0; cluster<4; cluster++)
    {
        for (int pknd=0; pknd<64; pknd++)
        {
            /* Set all PKNDS to be the correct SSO tag type */
            BDK_CSR_MODIFY(c, node, BDK_PKI_CLX_STYLEX_ALG(cluster, pknd),
                c.s.tt = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE));
            /* Set all PKNDS to use style of same number */
            BDK_CSR_MODIFY(c, node, BDK_PKI_CLX_PKINDX_STYLE(cluster, pknd),
                c.s.pm = 0;
                c.s.style = pknd);
        }
    }
    /* Allow PKI to parse Higig headers. The BDK currently doesn't use
        any other parsing */
    BDK_CSR_MODIFY(c, node, BDK_PKI_GBL_PEN,
        c.s.hg_pen = 1);
    /* Put all clusters in same cluster group */
    BDK_CSR_MODIFY(c, node, BDK_PKI_ICGX_CFG(0),
        c.s.clusters = 0xf);
    /* Set how the styles buffer to memory */
    for (int style=0; style<64; style++)
    {
        BDK_CSR_MODIFY(c, node, BDK_PKI_STYLEX_BUF(style),
            c.s.pkt_lend = 0; /* Use big endian */
            c.s.wqe_hsz = 0; /* WQE uses word 0..4 */
            c.s.wqe_skip = 0; /* WQE starts at beginning of buffer */
            c.s.first_skip = 5; /* Room for WQE */
            c.s.later_skip = 0; /* NO 2nd skip */
            c.s.opc_mode = 1; /* all packet data and next-buffer pointers are written into the cache */
            c.s.dis_wq_dat = 0; /* Packet follows WQE */
            c.s.mb_size = bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0)/8);
        /* OR bits for WQE word 2 */
        BDK_CSR_WRITE(node, BDK_PKI_STYLEX_WQ2(style), 0);
        /* OR bits for WQE word 4 */
        BDK_CSR_WRITE(node, BDK_PKI_STYLEX_WQ4(style), 0);
    }
    return 0;
}

/**
 * Configure packet input for a specific port. This is called for each
 * port on every interface that is connected to packet input.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int pki_port_init(bdk_if_handle_t handle)
{
    global_node_state_t *node_state = &global_node_state[handle->node];
    /* Make sure we have room in the QPG table */
    if (node_state->next_free_qpg_table >= 2048)
    {
        bdk_error("PKI QPG table full\n");
        return -1;
    }

    if ((handle->index == 0) && (node_state->next_free_pknd >= 64))
    {
        bdk_error("PKI ran out of PKNDs\n");
        return -1;
    }

    /* FIXME: How many buffers should be given to each aura? */
    int aura = bdk_fpa_init_aura(handle->node, -1, BDK_FPA_PACKET_POOL, bdk_config_get(BDK_CONFIG_NUM_PACKET_BUFFERS));
    if (aura < 0)
        return -1;
    handle->aura = aura;

    /* Find the PKND for this port. This code only works since the
        ports are enumerated in order */
    if ((handle->index == 0) || (handle->iftype == BDK_IF_LOOP))
        handle->pknd = node_state->next_free_pknd++;
    else
        handle->pknd = node_state->next_free_pknd - 1;

    // Setup QPG table per channel
    int qpg = node_state->next_free_qpg_table++;

    /* Set PKI to use the right backpressure id for this port. We use
        a 1:1 mapping between aura and bpid */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKI_CHANX_CFG(handle->ipd_port),
        c.s.bpid = handle->aura);
    /* Setup all PKI clusters */
    for (int cluster=0; cluster<4; cluster++)
    {
        /* The following calculation only works since intefaces are
            enumerated in order */
        int qpg_base = qpg - handle->index;
        int style = handle->pknd;
        /* Configure PKI style */
        BDK_CSR_MODIFY(c, handle->node, BDK_PKI_CLX_STYLEX_CFG(cluster, style),
            c.s.lenerr_en = 0; /* Don't check L2 length */
            c.s.fcs_strip = 0; /* Don't strip FCS */
            c.s.fcs_chk = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 1 : 0;
            c.s.qpg_dis_padd = 1; /* Don't use QPG for port */
            c.s.qpg_dis_grp = 0; /* Use QPG for group */
            c.s.qpg_dis_aura = 0; /* Use QPG for aura */
            c.s.qpg_base = qpg_base); /* Base for QPG */
        /* FIXME: Tell PKI to compute checksum */
        BDK_CSR_MODIFY(c, handle->node, BDK_PKI_CLX_STYLEX_CFG2(cluster, style),
            c.s.csum_lb = 0);
    }
    /* Tell PKI to use cluster group 0 for this PKND */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKI_PKINDX_ICGSEL(handle->pknd),
        c.s.icg = 0);
    /* Round robbin through groups. It isn't obvious, but the node
        number is embedded into the group */
    int wqe_grp = node_state->next_wqe_grp | (handle->node << 8);
    node_state->next_wqe_grp = (node_state->next_wqe_grp+1) & 255;
    BDK_CSR_MODIFY(c, handle->node, BDK_PKI_QPG_TBLX(qpg),
        c.s.padd = 0; /* Set WQE[CHAN] */
        c.s.grp_ok = wqe_grp; /* Set WQE[GRP] */
        c.s.grp_bad = wqe_grp; /* Set WQE[GRP] */
        c.s.laura = handle->aura); /* Set WQE[AURA] */

    /* We lookup the handle using the PKI input channel */
    node_state->__bdk_if_ipd_map[handle->ipd_port] = handle;
    //bdk_dprintf("%s: pknd=%d, ipd_port=0x%x, aura=%d\n",
    //    bdk_if_name(handle), handle->pknd, handle->ipd_port, handle->aura);
    return 0;
}

/**
 * Enable PKI after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pki_enable(bdk_node_t node)
{
    BDK_CSR_MODIFY(c, node, BDK_PKI_BUF_CTL,
        c.s.fpa_wait = 1; /* Wait for FPA so drops are less often */
        c.s.pbp_en = 1; /* Enable backpressure */
        c.s.pki_en = 1); /* Enable PKI */
    /* Enable cluster group 0 */
    BDK_CSR_MODIFY(c, node, BDK_PKI_ICGX_CFG(0),
        c.s.pena = 1);
    return 0;
}

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
static int pko_global_init(bdk_node_t node)
{
    if (bdk_fpa_fill_pool(node, BDK_FPA_PKO_POOL, PKO_POOL_BUFFERS))
        return -1;
    const int aura = BDK_FPA_PKO_POOL; /* Use 1:1 mapping aura */
    BDK_CSR_MODIFY(c, node, BDK_PKO_DPFI_FPA_AURA,
        c.s.node = node;
        c.s.laura = aura);
    BDK_CSR_MODIFY(c, node, BDK_PKO_DPFI_ENA,
        c.s.enable = 1);
    BDK_CSR_MODIFY(c, node, BDK_PKO_PTF_IOBP_CFG,
        c.s.max_read_size = 72);
    BDK_CSR_MODIFY(c, node, BDK_PKO_PDM_CFG,
        c.s.pko_pad_minlen = 60);
    return 0;
}

/**
 * Dynamically allocate a PKO fifo for a port
 *
 * @param lmac   Logical mac to use (0-27)
 * @param size   The size needed in 2.5kb chunks (1,2,4).
 *
 * @return Fifo number of negative on failure
 */
static int __bdk_pko_allocate_fifo(bdk_node_t node, int lmac, int size)
{
    global_node_state_t *node_state = &global_node_state[node];
    /* Start at 0 znd look for a fifo location that has enough
        consecutive space */
    int fifo = 0;
    while (fifo < 32)
    {
        /* Buid a mask representing what this fifo would use */
        uint64_t mask = bdk_build_mask(size) << fifo;
        /* Stop search if all bits are free */
        if ((mask & node_state->pko_free_fifo_mask) == mask)
        {
            /* Found a spot, mark it used and stop searching */
            node_state->pko_free_fifo_mask &= ~mask;
            break;
        }
        /* Increment by size to keep alignment */
        fifo += size;
    }
    /* Check if didn't have space */
    if (fifo >= 32)
    {
        bdk_error("pko_allocate_fifo: Tried to allocate too many fifos\n");
        return -1;
    }
    /* Program the PKO fifo. Each PKO_PTGFX_CFG represents a cluster of four
        FIFOs */
    int index = fifo >> 2;
    BDK_CSR_INIT(cfg, node, BDK_PKO_PTGFX_CFG(index));
    cfg.s.reset = 1;
    switch (cfg.s.size)
    {
        case 0: /* 2.5kb, 2.5kb, 2.5kb, 2.5kb */
            switch (size)
            {
                case 1:
                    cfg.s.size = 0; /* 2.5kb for all */
                    break;
                case 2:
                    cfg.s.size = 1; /* 5kb, 2.5kb, 2.5kb */
                    break;
                default: /* 4 */
                    cfg.s.size = 3; /* 10kb */
                    break;
            }
            break;
        case 1: /* 5kb, 2.5kb, 2.5kb */
            /* Can only possible combine the two 2.5kb */
            switch (size)
            {
                case 1:
                    /* No change */
                    cfg.s.size = 1; /* 5kb, 2.5kb, 2.5kb */
                    break;
                case 2:
                    /* 2nd buffer is now 5kb */
                    cfg.s.size = 2; /* 5kb, 5kb */
                    break;
                default: /* 4 */
                    /* This shouldn't be possible */
                    bdk_fatal("Illegal fifo size\n");
                    break;
            }
            break;
        case 2: /* 2.5kb, 5kb - already allocated */
            /* This shouldn't be possible */
            bdk_fatal("Illegal fifo size\n");
            break;
        case 3: /* 5kb, 5kb - already allocated */
            /* This shouldn't be possible */
            bdk_fatal("Illegal fifo size\n");
            break;
        default: /* 10kb - already allocated */
            /* This shouldn't be possible */
            bdk_fatal("Illegal fifo size\n");
            break;
    }
    BDK_CSR_WRITE(node, BDK_PKO_PTGFX_CFG(index), cfg.u);

    /* Setup PKO MCI0 credits */
    int pko_peb_buffering = size * (1024 + 512); /* 2.5KB per fifo */
    int mac_buffering;
    switch (lmac)
    {
        case 0: /* LBK */
            mac_buffering = 4096; /* From HRM */
            break;
        case 1: /* DPI */
            mac_buffering = 2048; /* From o78/packet/clear78.c */
            break;
        case 2: /* ILK0 */
        case 3: /* ILK1 */
            mac_buffering = 4096; /* From o78/packet/clear78.c */
            break;
        default: /* BGX */
            mac_buffering = size * 8192; /* 8KB, 16KB, or 32KB */
            break;
    }
    BDK_CSR_WRITE(node, BDK_PKO_MCI0_MAX_CREDX(lmac), (pko_peb_buffering + mac_buffering) / 16);
    /* Confine the credits to not overflow the LBK FIFO */
    BDK_CSR_MODIFY(c, node, BDK_PKO_MCI1_MAX_CREDX(lmac),
        c.s.max_cred_lim = mac_buffering / 16);
    return fifo;
}

/**
 * Configure PKO for a specific port. This is called for each
 * port on every interface that connects to PKO.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int pko_port_init(bdk_if_handle_t handle)
{
    global_node_state_t *node_state = &global_node_state[handle->node];
    int pq;     /* L1 = port queue */
    int sq_l2;  /* L2 = schedule queue feeding PQ */
    int sq_l3;  /* L3 = schedule queue feeding L2 */
    int sq_l4;  /* L4 = schedule queue feeding L3 */
    int sq_l5;  /* L5 = schedule queue feeding L4 */
    int dq;     /* L6 = descriptor queue feeding L5 */

    if (node_state->pko_next_free_l2_queue >= 512)
    {
        bdk_error("pko_port_init: Ran out of L2 queues\n");
        return -1;
    }
    if (node_state->pko_next_free_l3_queue >= 512)
    {
        bdk_error("pko_port_init: Ran out of L3 queues\n");
        return -1;
    }
    if (node_state->pko_next_free_l4_queue >= 1024)
    {
        bdk_error("pko_port_init: Ran out of L4 queues\n");
        return -1;
    }
    if (node_state->pko_next_free_l5_queue >= 1024)
    {
        bdk_error("pko_port_init: Ran out of L5 queues\n");
        return -1;
    }
    if (node_state->pko_next_free_descr_queue > 1024 - PKO_QUEUES_PER_CHANNEL)
    {
        bdk_error("pko_port_init: Ran out of descriptor (L6) queues\n");
        return -1;
    }

    if ((handle->index == 0) || (handle->iftype == BDK_IF_BGX))
    {
        if (node_state->pko_next_free_port_queue >= 32)
        {
            bdk_error("pko_port_init: Ran out of port (L1) queues\n");
            return -1;
        }
        pq = node_state->pko_next_free_port_queue++;
    }
    else
    {
        /* This relies on channels being initialized in order */
        pq = node_state->pko_next_free_port_queue - 1;
    }

    sq_l2 = node_state->pko_next_free_l2_queue++;
    sq_l3 = node_state->pko_next_free_l3_queue++;
    sq_l4 = node_state->pko_next_free_l4_queue++;
    sq_l5 = node_state->pko_next_free_l5_queue++;
    dq = node_state->pko_next_free_descr_queue;
    node_state->pko_next_free_descr_queue += PKO_QUEUES_PER_CHANNEL;

    int lmac;
    int fcs_ena;
    int skid_max_cnt;
    int fifo_size;
    int compressed_channel_id; /* compressed_channel_id comes from the LUT
                                    compressed channel inside
                                    "PKO Technical Specification1.docx" */
    switch (handle->iftype)
    {
        case BDK_IF_BGX:
        {
            int port = handle->index;
            BDK_CSR_INIT(config, handle->node, BDK_BGXX_CMRX_CONFIG(handle->interface, 0));
            switch (config.s.lmac_type)
            {
                case 0: /* SGMII - 1 lane each */
                    fifo_size = 1;
                    fcs_ena = 1;
                    skid_max_cnt = 0;
                    break;
                case 3: /* 10GBASE-R - 1 lane each */
                    fifo_size = 1;
                    fcs_ena = 1;
                    skid_max_cnt = 0;
                    break;
                case 2: /* Reduced XAUI - 2 lanes each */
                    fifo_size = 2;
                    fcs_ena = 1;
                    skid_max_cnt = 1;
                    if (bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + handle->interface))
                        port = port >> 4;
                    break;
                case 1: /* 10GBASE-X/XAUI or DXAUI - 4 lanes each */
                    fifo_size = 4;
                    fcs_ena = 1;
                    skid_max_cnt = 2;
                    if (bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + handle->interface))
                        port = port >> 4;
                    break;
                case 4: /* 40GBASE-R - 4 lanes each */
                default:
                    fifo_size = 4;
                    fcs_ena = 1;
                    skid_max_cnt = 2;
                    break;
            }
            lmac = 4 + 4 * handle->interface + port;
            compressed_channel_id = 512 + handle->interface * 64 + handle->index;
            break;
        }
        case BDK_IF_DPI:
            lmac = 1;
            fifo_size = 4;
            fcs_ena = 0;
            skid_max_cnt = 2;
            compressed_channel_id = 896 + handle->index;
            break;
        case BDK_IF_LOOP:
            lmac = 0;
            fifo_size = 4;
            fcs_ena = 0;
            skid_max_cnt = 2;
            compressed_channel_id = 960 + handle->index;
            break;
        case BDK_IF_ILK:
            lmac = 2 + handle->interface;
            fifo_size = 4;
            fcs_ena = 0;
            skid_max_cnt = 2;
            compressed_channel_id = handle->interface * 256 + handle->index;
            break;
        default:
            return -1;
    }

    /* Get the FIFO number for this lmac */
    BDK_CSR_INIT(pko_macx_cfg, handle->node, BDK_PKO_MACX_CFG(lmac));
    if (pko_macx_cfg.s.fifo_num == 0x1f)
    {
        int fifo = __bdk_pko_allocate_fifo(handle->node, lmac, fifo_size);
        if (fifo<0)
            return -1;
        pko_macx_cfg.s.fifo_num = fifo;
        pko_macx_cfg.s.min_pad_ena = 0; /* Don't use padding due to Errata (PKO-20715) */
        pko_macx_cfg.s.fcs_ena = fcs_ena; /* FCS */
        pko_macx_cfg.s.fcs_sop_off = 0; /* No FCS offset */
        pko_macx_cfg.s.skid_max_cnt = skid_max_cnt;
        BDK_CSR_WRITE(handle->node, BDK_PKO_MACX_CFG(lmac), pko_macx_cfg.u64);
    }
    //printf("%s: PKO using lmac %d, fifo_size %d, fifo %d, compressed_chan %d, pq %d, l2 %d, l3 %d, l4 %d, l5 %d, dq %d\n",
        //handle->name, lmac, fifo_size, pko_macx_cfg.s.fifo_num, compressed_channel_id, pq, sq_l2, sq_l3, sq_l4, sq_l5, dq);

    /* Program L1 = port queue */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L1_SQX_TOPOLOGY(pq),
        c.s.prio_anchor = sq_l2;
        c.s.link = lmac;
        c.s.rr_prio = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L1_SQX_SHAPE(pq),
        c.s.link = lmac);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L1_SQX_LINK(pq),
        c.s.link = lmac;
        c.s.cc_enable = 0);
    /* Program L2 = schedule queue */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L2_SQX_SCHEDULE(sq_l2),
        c.s.prio = 0;
        c.s.rr_quantum = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L2_SQX_TOPOLOGY(sq_l2),
        c.s.prio_anchor = sq_l3;
        c.s.parent = pq;
        c.s.rr_prio = 0);
    /* Program L3 = schedule queue */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L3_L2_SQX_CHANNEL(sq_l3),
        c.s.cc_channel = handle->ipd_port);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L3_SQX_SCHEDULE(sq_l3),
        c.s.prio = 0;
        c.s.rr_quantum = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L3_SQX_TOPOLOGY(sq_l3),
        c.s.prio_anchor = sq_l4;
        c.s.parent = sq_l2;
        c.s.rr_prio = 0);
    /* Program L4 = schedule queue */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L4_SQX_SCHEDULE(sq_l4),
        c.s.prio = 0;
        c.s.rr_quantum = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L4_SQX_TOPOLOGY(sq_l4),
        c.s.prio_anchor = sq_l5;
        c.s.parent = sq_l3;
        c.s.rr_prio = 0);
    /* Program L5 = schedule queue */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L5_SQX_SCHEDULE(sq_l5),
        c.s.prio = 0;
        c.s.rr_quantum = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L5_SQX_TOPOLOGY(sq_l5),
        c.s.prio_anchor = dq;
        c.s.parent = sq_l4;
        c.s.rr_prio = 0);
    /* Program L6 = descriptor queue */
    for (int q=0; q<PKO_QUEUES_PER_CHANNEL; q++)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_DQX_SCHEDULE(dq+q),
            c.s.prio = 0;
            c.s.rr_quantum = 0);
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_DQX_TOPOLOGY(dq+q),
            c.s.parent = sq_l5);
    }
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_LUTX(compressed_channel_id),
        c.s.valid = 1;
        c.s.pq_idx = pq;
        c.s.queue_number = sq_l5);
    handle->pko_port = pq;
    handle->pko_queue = dq;

    /* Have the PKO DQ watermarks count packets. This way they are equivalent
       to the queue depth */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_DQX_WM_CTL(dq),
        c.s.kind = 1);

    //bdk_dprintf("%s: pko mac=%d, pq=%d, l2=%d, l3=%d, l4=%d, l5=%d, dq=%d\n",
    //    bdk_if_name(handle), lmac, pq, sq_l2, sq_l3, sq_l4, sq_l5, dq);

    return 0;
}

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pko_enable(bdk_node_t node)
{
    const global_node_state_t *node_state = &global_node_state[node];

    /* Take FIFOs out of reset */
    for (int i = 0; i < 8; i++)
        BDK_CSR_MODIFY(c, node, BDK_PKO_PTGFX_CFG(i),
            c.s.reset = 0);

    /* Enable the FPA interface */
    BDK_CSR_MODIFY(c, node, BDK_PKO_DPFI_ENA,
        c.s.enable = 1);

    /* Wait for PKO to be ready (100us) */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PKO_STATUS, pko_rdy, ==, 1, 100))
    {
        bdk_error("PKO: Timeout waiting for ready\n");
        return -1;
    }

    BDK_CSR_MODIFY(c, node, BDK_PKO_ENABLE,
        c.s.enable = 1);
    /* Read needed to make sure enable is done before accesses below */
    BDK_CSR_READ(node, BDK_PKO_ENABLE);

    /* Open all configured descriptor queues */
    for (int dq=0; dq<node_state->pko_next_free_descr_queue; dq++)
    {
        uint64_t pko_address = 1ull<<63;
        pko_address |= 1ull<<48;
        pko_address |= 0x51ull<<40;
        pko_address |= (uint64_t)node<<36;
        pko_address |= 1ull<<32; /* Open */
        pko_address |= (uint64_t)dq<<16;
        uint64_t pko_resp = bdk_read64_uint64(pko_address);
        if (pko_resp >> 60)
            bdk_error("PKO open failed with response 0x%lx\n", pko_resp);
    }
    return 0;
}

/**
 * Initialize the SSO
 *
 * @return Zero on success, negative on failure
 */
static int sso_init(bdk_node_t node)
{
    /* Setup an FPA pool to store the SSO queues */
    int num_blocks = 256 + 48 + ((MAX_SSO_ENTRIES+25)/26);
    if (bdk_fpa_fill_pool(node, BDK_FPA_SSO_POOL, num_blocks))
        return -1;
    const int aura = BDK_FPA_SSO_POOL; /* Use 1:1 mapping aura */

    /* Initialize the 256 group/qos queues */
    for (int grp=0; grp<256; grp++)
    {
        void *buffer = bdk_fpa_alloc(node, aura);
        if (buffer == NULL)
        {
            bdk_error("sso_init: Failed to allocate buffer\n");
            return -1;
        }
        uint64_t addr = bdk_ptr_to_phys(buffer);
        BDK_CSR_MODIFY(c, node, BDK_SSO_XAQX_HEAD_PTR(grp),
            c.s.ptr = addr >> 7;
            c.s.cl = 0);
        BDK_CSR_MODIFY(c, node, BDK_SSO_XAQX_HEAD_NEXT(grp),
            c.s.ptr = addr >> 7);
        BDK_CSR_MODIFY(c, node, BDK_SSO_XAQX_TAIL_PTR(grp),
            c.s.ptr = addr >> 7;
            c.s.cl = 0);
        BDK_CSR_MODIFY(c, node, BDK_SSO_XAQX_TAIL_NEXT(grp),
            c.s.ptr = addr >> 7);
    }
    /* Set the aura number */
    BDK_CSR_MODIFY(c, node, BDK_SSO_XAQ_AURA,
        c.s.laura = aura);
    /* Set work timeout to 1k cycles. The 78 simulator has a bug where it
       waits for this time even if there is work available */
    BDK_CSR_MODIFY(c, node, BDK_SSO_NW_TIM,
        c.s.nw_tim = 0);
    /* Setup how the SSO accesses memory */
    BDK_CSR_MODIFY(c, node, BDK_SSO_AW_CFG,
        c.s.rwen = 1);
    return 0;
}

/**
 * Convert a WQE into a BDK packet
 *
 * @param work   Pointer to WQE to convert
 * @param packet Packet to receive the data
 *
 * @return Zero on success, negative on failure
 */
static int sso_wqe_to_packet(const void *work, bdk_if_packet_t *packet)
{
    const bdk_wqe_t *wqe = work;
    const bdk_node_t input_node = wqe->word0.v3.node;
    const global_node_state_t *node_state = &global_node_state[input_node];
#if 0
    const char *tag_type = "illegal";
    switch (wqe->word1.v3.tt)
    {
        case BDK_WQE_TAG_TYPE_ORDERED:
            tag_type = "ordered";
            break;
        case BDK_WQE_TAG_TYPE_ATOMIC:
            tag_type = "atomic";
            break;
        case BDK_WQE_TAG_TYPE_NULL:
            tag_type = "null";
            break;
        case BDK_WQE_TAG_TYPE_NULL_NULL:
            tag_type = "null_null";
            break;
    }

    bdk_dprintf("N%d: SSO work %p\n"
        "  word0: 0x%016lx [node %d, aura=%d, apad=%d, chan=0x%x, bufs=%d, style=%d, pknd=%d]\n"
        "  word1: 0x%016lx [len=%d, node=%d, grp=%d, tt=%s, tag=0x%08x]\n"
        "  word2: 0x%016lx\n"
        "  word3: 0x%016lx [size=%d, dwd=%d, addr=0x%lx]\n"
        "  word4: 0x%016lx [vlptr=%d, lgptr=%d, lfptr=%d, leptr=%d, ldptr=%d, lcptr=%d, lbptr=%d, laptr=%d\n"
        "  word5: 0x%016lx\n"
        "  word6: 0x%016lx\n"
        "  word7: 0x%016lx\n",
        bdk_numa_local(), wqe,
        wqe->word0.u64,         /* word0 */
        wqe->word0.v3.node,
        wqe->word0.v3.aura,
        wqe->word0.v3.apad,
        wqe->word0.v3.chan,
        wqe->word0.v3.bufs,
        wqe->word0.v3.style,
        wqe->word0.v3.pknd,
        wqe->word1.u64,         /* word1 */
        wqe->word1.v3.len,
        wqe->word1.v3.node,
        wqe->word1.v3.grp,
        tag_type,
        wqe->word1.v3.tag,
        wqe->word2.u64,         /* word2 */
        wqe->packet_ptr.u64,    /* word3 */
        wqe->packet_ptr.v3.size,
        wqe->packet_ptr.v3.dwd,
        (uint64_t)wqe->packet_ptr.v3.addr,
        wqe->word4.u64,         /* word4 */
        wqe->word4.v3.vlptr,
        wqe->word4.v3.lgptr,
        wqe->word4.v3.lfptr,
        wqe->word4.v3.leptr,
        wqe->word4.v3.ldptr,
        wqe->word4.v3.lcptr,
        wqe->word4.v3.lbptr,
        wqe->word4.v3.laptr,
        wqe->unused[0],         /* word5 */
        wqe->unused[1],         /* word6 */
        wqe->unused[2]);        /* word7 */
#endif
    packet->if_handle = node_state->__bdk_if_ipd_map[wqe->word0.v3.chan];
    //bdk_dprintf("  Maps to %s, port=%d, aura=%d, pknd=%d\n",
        //bdk_if_name(packet->if_handle), packet->if_handle->ipd_port,
        //packet->if_handle->aura, packet->if_handle->pknd);
    packet->length = wqe->word1.v3.len;
    packet->segments = wqe->word0.v3.bufs;
    packet->aura = wqe->word0.v3.aura;
    packet->packet = wqe->packet_ptr;
    if (bdk_unlikely(wqe->word2.v3.errlev || wqe->word2.v3.opcode))
        packet->rx_error = wqe->word2.u64 & 0x7ff;
    else
        packet->rx_error = 0;

    if (bdk_unlikely(!packet->if_handle))
    {
        bdk_error("Unable to find IF for packet to port %d\n", wqe->word0.v3.chan);
        return -1;
    }

    /* Errata (PKI-20776) PKI_BUFLINK_S's are endian-swapped
       CN78XX pass 1.x has a bug where the packet pointer in each segment is
       written in the opposite endianness of the configured mode. Fix these
       here */
    if (OCTEON_IS_MODEL(OCTEON_CN78XX_PASS1_X))
    {
        bdk_buf_ptr_t buffer_next = packet->packet;
        int segments = packet->segments - 1;
        while (segments--)
        {
            bdk_buf_ptr_t next = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_next.v3.addr - 8);
            next.u64 = bdk_swap64(next.u64);
            *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_next.v3.addr - 8) = next;
            buffer_next = next;
        }
    }

    return 0;
}

/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
static int pko_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    typedef union
    {
        uint64_t u;
        struct
        {
            uint64_t    reserved_60_63  : 4;
            uint64_t    node            : 2;    /**< Node for aura */
            uint64_t    aura            :10;    /**< Aura to return buffers to */
            uint64_t    ckl4            : 2;    /**< Checksum L4 (TCP/UDP) */
            uint64_t    ckl3            : 1;    /**< Checksum L3 (IP) */
            uint64_t    ds              : 1;    /**< Don't send */
            uint64_t    le              : 1;    /**< Little endian */
            uint64_t    n2              : 1;    /**< No L2 allocate */
            uint64_t    ii              : 1;    /**< Ignore I bit */
            uint64_t    df              : 1;    /**< Don't free */
            uint64_t    reserved_39     : 1;    /**< Was FCS, now what? */
            uint64_t    format          : 7;    /**< Format index */
            uint64_t    l4ptr           : 8;    /**< Layer 4 offset */
            uint64_t    l3Ptr           : 8;    /**< Layer 3 offset */
            uint64_t    total           :16;    /**< Total byte count */
        } s;
    } bdk_pko_send_hdr_s_t;
    typedef bdk_buf_ptr_t bdk_pko_send_link_s_t;
    typedef union
    {
        uint64_t u;
        struct
        {
            uint64_t    scraddr         : 8;    /**< CVMSEG location for response */
            uint64_t    rtnlen          : 8;    /**< Length of return in 8 byte words */
            uint64_t    did             : 8;    /**< PKO DID of 0x51 */
            uint64_t    node            : 4;    /**< OCI Node number */
            uint64_t    reserved_34_35  : 2;
            uint64_t    dqop            : 2;    /**< Indicates the operation that PKO will perform. SEND=0,OPEN=1,CLOSE=2,QUERY=3 */
            uint64_t    reserved_26_31  : 6;
            uint64_t    dq              :10;    /**< Descriptor queue to add to */
            uint64_t    reserved_0_15   :16;
        } s;
    } bdk_pko_send_dma_s_t;
    typedef union
    {
        uint64_t u;
        struct
        {
            uint64_t    reserved_63     : 1;
            uint64_t    wmem            : 1;    /**< Wait for memory */
            uint64_t    dsz             : 2;    /**< Memory data size. Use 0 for 64bit due to Errata PKO-19988 */
            uint64_t    alg             : 4;    /**< Algorithm to use */
            uint64_t    offset          : 8;    /**< Adder offset */
            uint64_t    subdc4          : 4;    /**< Must be 0xC */
            uint64_t    reserved_42_43  : 2;
            uint64_t    addr            :42;    /**< Address */
        } s;
    } bdk_pko_send_mem_s_t;
    typedef union
    {
        uint64_t u;
        struct
        {
            uint64_t    dqstatus        : 4;    /**< Success/failure: 0=pass */
            uint64_t    reserved_59_50  :10;
            uint64_t    dqop            : 2;    /**< Indictates operation that returned the status */
            uint64_t    depth           :48;    /**< Queue depth */
        } s;
    } bdk_pko_query_rtn_s_t;

    /* Flush pending writes */
    BDK_SYNCW;

    if (handle->pko_depth >= PKO_DEPTH_LIMIT)
    {
        //bdk_error("%s: PKO transmit aborted due queue depth\n", bdk_if_name(handle));
        return -1;
    }

    /* Build the three PKO comamnd words we need */
    bdk_pko_send_hdr_s_t pko_send_hdr_s;
    pko_send_hdr_s.u = 0;
    pko_send_hdr_s.s.node = packet->if_handle->node;
    pko_send_hdr_s.s.aura = packet->aura;
    pko_send_hdr_s.s.df = packet->packet.v3.i;
    pko_send_hdr_s.s.ii = 1;
    pko_send_hdr_s.s.format = 0; /* We don't use this? */
    pko_send_hdr_s.s.total = packet->length;
    /* Packet pointer */
    bdk_pko_send_link_s_t pko_send_link_s;
    pko_send_link_s = packet->packet;
    /* Memory decrement when done */
    bdk_pko_send_mem_s_t pko_send_mem_s;
    pko_send_mem_s.u = 0;
    pko_send_mem_s.s.offset = 1;
    pko_send_mem_s.s.alg = 9; /* Subtract */
    pko_send_mem_s.s.subdc4 = 0xc;
    pko_send_mem_s.s.addr = bdk_ptr_to_phys(&handle->pko_depth);

    /* Errata (PKO-20715) PKO problems with min padding
       Due to this errata, we are doing padding in software. This code
       assumes the runt packet is in a single buffer and we can just spew
       the data after it as our padding */
    if ((packet->length < 60) && (handle->flags & BDK_IF_FLAGS_HAS_FCS))
    {
        pko_send_hdr_s.s.total = 60;
        pko_send_link_s.v3.size = 60;
    }

    /* Build LMTDMA store data */
    bdk_pko_send_dma_s_t pko_send_dma_s;
    pko_send_dma_s.u = 0;
    //pko_send_dma_s.s.scraddr = BDK_IF_SCR_PKO(2) >> 3;
    //pko_send_dma_s.s.rtnlen = 0; /* No result expected */
    pko_send_dma_s.s.did = 0x51;
    pko_send_dma_s.s.node = handle->node;
    pko_send_dma_s.s.dqop = 0; /* 0=Send */
    pko_send_dma_s.s.dq = handle->pko_queue;

    /* Increment the PKO depth. PKO will decrement it when its done. This
       will invalidate our L1 copy, so do it last before submit. It needs
       to be before the submit to insure the depth never goes negative */
    bdk_atomic_add64_nosync(&handle->pko_depth, 1);

    /* Write the PKO commands to scratch */
    bdk_scratch_write64(BDK_IF_SCR_PKO(0), pko_send_hdr_s.u);
    bdk_scratch_write64(BDK_IF_SCR_PKO(1), pko_send_link_s.u64);
    bdk_scratch_write64(BDK_IF_SCR_PKO(2), pko_send_mem_s.u);

    /* Issue LMTDMA with 2 dwords of data, no response */
    bdk_write64_uint64(BDK_LMTDMA_ADDR(3), pko_send_dma_s.u);

    /* Updates the statistics in software if need to. The simulator
        doesn't implement the hardware counters */
    if (bdk_unlikely(bdk_is_simulation()))
    {
        int octets = pko_send_hdr_s.s.total;
        if (handle->flags & BDK_IF_FLAGS_HAS_FCS)
            octets += 4;
        bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.octets, octets);
        bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.packets, 1);
    }
    return 0;
}

/**
 * Allocate a packet with buffers for the supplied amount of data
 *
 * @param packet Packet to get buffers for
 * @param length Length of the final packet in bytes
 *
 * @return Zero on success, negative on failure.
 */
static int packet_alloc(bdk_if_packet_t *packet, int length)
{
    const int aura = packet->if_handle->aura;
    const int FPA_SIZE = bdk_fpa_get_block_size(packet->if_handle->node, aura);
    bdk_buf_ptr_t *buffer_ptr = &packet->packet;

    /* Start off with an empty packet */
    packet->length = 0;
    packet->segments = 0;
    packet->aura = aura;

    /* Add buffers while the packet is less that the needed length */
    while (packet->length < length)
    {
        void *buffer = bdk_fpa_alloc(packet->if_handle->node, aura);
        if (!buffer)
        {
            /* Free all buffers allocates so far */
            bdk_if_free(packet);
            return -1;
        }
        /* Fill in the packet link pointer */
        buffer_ptr->u64 = 0;
        buffer_ptr->v3.size = FPA_SIZE - 8;
        buffer_ptr->v3.addr = bdk_ptr_to_phys(buffer) + 8;
        packet->length += FPA_SIZE - 8;
        packet->segments++;
        /* The next chain pointer is at the beginning of the buffer */
        buffer_ptr = buffer;
    }
    /* Fix length as it will likely be too large since we increment in FPA
        chunks */
    packet->length = length;
    return 0;
}

/**
 * Free a packet back to the FPA pools
 *
 * @param packet Packet to free. Only the data is freed. The bdk_if_packet_t structure
 *               is not freed.
 */
static void packet_free(bdk_if_packet_t *packet)
{
    const int aura = packet->aura;
    int number_buffers = packet->segments;
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    bdk_buf_ptr_t next_buffer_ptr;
    BDK_SYNCW;
    while (number_buffers--)
    {
        /* Read pointer to next buffer before we free the current buffer. */
        if (number_buffers)
            next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
        __bdk_fpa_raw_free(packet->if_handle->node, buffer_ptr.v3.addr, aura, 0);
        buffer_ptr = next_buffer_ptr;
    }
}

/**
 * Read data from a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to read from.
 * @param location Location to read
 * @param length   Length of data to read
 * @param data     Buffer to receive the data
 */
static void packet_read(bdk_if_packet_t *packet, int location, int length, void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to read past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.v3.size)
    {
        location -= buffer_ptr.v3.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
    }

    const uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
    uint8_t *out_data = data;
    while (length > 0)
    {
        *out_data = ptr[location];
        out_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.v3.size))
        {
            location -= buffer_ptr.v3.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
        }
    }
}

/**
 * Write data into a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to write to.
 * @param location Location to write
 * @param length   Length of data to write
 * @param data     Data to write
 */
static void packet_write(bdk_if_packet_t *packet, int location, int length, const void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to write past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.v3.size)
    {
        location -= buffer_ptr.v3.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
    }

    uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
    const uint8_t *in_data = data;
    while (length > 0)
    {
        ptr[location] = *in_data;
        in_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.v3.size))
        {
            location -= buffer_ptr.v3.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
        }
    }
}

__bdk_if_global_ops_t __bdk_if_global_ops_cn78xx = {
    .pki_global_init = pki_global_init,
    .pki_port_init = pki_port_init,
    .pki_enable = pki_enable,
    .pko_global_init = pko_global_init,
    .pko_port_init = pko_port_init,
    .pko_enable = pko_enable,
    .sso_init = sso_init,
    .sso_wqe_to_packet = sso_wqe_to_packet,
    .pko_transmit = pko_transmit,
    .packet_alloc = packet_alloc,
    .packet_free = packet_free,
    .packet_read = packet_read,
    .packet_write = packet_write,
};

