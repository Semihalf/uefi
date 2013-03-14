#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

/* PKO uses three scratch dwords, two for commands and one for return status */
#define BDK_IF_SCR_PKO(dword) (BDK_IF_SCR_LMTDMA + (dword<<3))

static __bdk_if_port_t *__bdk_if_ipd_map[0x1000]; /* Channels is 12 bits in WQE */
static int next_free_qpg_table = 0;
static int next_free_pknd = 0;
static int next_wqe_grp = 0;
static uint64_t free_fifo_mask = 0x0fffffff; /* PKO_PTGFX_CFG(7) is reserved for NULL MAC */

/**
 * One time init of global Packet Input
 *
 * @return Zero on success, negative on failure
 */
static int pki_global_init(void)
{
    bdk_zero_memory(__bdk_if_ipd_map, sizeof(__bdk_if_ipd_map));

    /* Setup all Auras to support backpressure */
    for (int aura=0; aura<1024; aura++)
    {
        BDK_CSR_MODIFY(c, BDK_PKI_AURAX_CFG(aura),
            c.s.pkt_add = 2; /* Actual number of buffers allocated */
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
            BDK_CSR_MODIFY(c, BDK_PKI_CLX_STYLEX_ALG_2(cluster, pknd),
                c.s.tt = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE));
            /* Set all PKNDS to use style of same number */
            BDK_CSR_MODIFY(c, BDK_PKI_CLX_PKINDX_STYLE_2(cluster, pknd),
                c.s.pm = 0;
                c.s.style = pknd);
        }
    }
    /* Allow PKI to parse Higig headers. The BDK currently doesn't use
        any other parsing */
    BDK_CSR_MODIFY(c, BDK_PKI_GBL_PEN,
        c.s.hg_pen = 1);
    /* Put all clusters in same cluster group */
    BDK_CSR_MODIFY(c, BDK_PKI_ICGX_CFG(0),
        c.s.clusters = 0xf);
    /* Set how the styles buffer to memory */
    for (int style=0; style<64; style++)
    {
        BDK_CSR_MODIFY(c, BDK_PKI_STYLEX_BUF(style),
            c.s.pkt_lend = 0; /* Use big endian */
            c.s.wqe_hsz = 0; /* WQE uses word 0..4 */
            c.s.wqe_skip = 0; /* WQE starts at beginning of buffer */
            c.s.first_skip = 5; /* Room for WQE */
            c.s.later_skip = 0; /* NO 2nd skip */
            c.s.opc_mode = 1; /* all packet data and next-buffer pointers are written into the cache */
            c.s.dis_wq_dat = 0; /* Packet follows WQE */
            c.s.mb_size = bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0)/8);
        /* OR bits for WQE word 2 */
        BDK_CSR_WRITE(BDK_PKI_STYLEX_WQ2(style), 0);
        /* OR bits for WQE word 4 */
        BDK_CSR_WRITE(BDK_PKI_STYLEX_WQ4(style), 0);
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
    /* Make sure we have room in the QPG table */
    if (next_free_qpg_table >= 2048)
    {
        bdk_error("PKI QPG table full\n");
        return -1;
    }

    if ((handle->index == 0) && (next_free_pknd >= 64))
    {
        bdk_error("PKI ran out of PKNDs\n");
        return -1;
    }

    /* FIXME: How many buffers should be given to each aura? */
    int aura = bdk_fpa_init_aura(-1, BDK_FPA_PACKET_POOL, 1024);
    if (aura < 0)
        return -1;
    handle->aura = aura;

    /* Find the PKND for this port. This code only works since the
        ports are enumerated in order */
    if (handle->index == 0)
        handle->pknd = next_free_pknd++;
    else
        handle->pknd = next_free_pknd - 1;

    // Setup QPG table per channel
    int qpg = next_free_qpg_table++;

    /* Set PKI to use the right backpressure id for this port. We use
        a 1:1 mapping between aura and bpid */
    BDK_CSR_MODIFY(c, BDK_PKI_CHANX_CFG(handle->ipd_port),
        c.s.bpid = handle->aura);
    /* Setup all PKI clusters */
    for (int cluster=0; cluster<4; cluster++)
    {
        /* The following calculation only works since intefaces are
            enumerated in order */
        int qpg_base = qpg - handle->index;
        int style = handle->pknd;
        /* Configure PKI style */
        BDK_CSR_MODIFY(c, BDK_PKI_CLX_STYLEX_CFG_2(cluster, style),
            c.s.lenerr_en = 0; /* Don't check L2 length */
            c.s.fcs_strip = 0; /* Don't strip FCS */
            c.s.fcs_chk = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 1 : 0;
            c.s.qpg_dis_padd = 0; /* Use QPG for port */
            c.s.qpg_dis_grp = 0; /* Use QPG for group */
            c.s.qpg_dis_aura = 0; /* Use QPG for aura */
            c.s.qpg_base = qpg_base); /* Base for QPG */
        /* FIXME: Tell PKI to compute checksum */
        BDK_CSR_MODIFY(c, BDK_PKI_CLX_STYLEX_CFG2_2(cluster, style),
            c.s.csum_lb = 0);
    }
    /* Tell PKI to use cluster group 0 for this PKND */
    BDK_CSR_MODIFY(c, BDK_PKI_PKINDX_ICGSEL(handle->pknd),
        c.s.icg = 0);
    /* Round robbin through groups */
    int wqe_grp = next_wqe_grp;
    next_wqe_grp = (next_wqe_grp+1) & 255;
    BDK_CSR_MODIFY(c, BDK_PKI_QPG_TBLX(qpg),
        c.s.padd = handle->ipd_port; /* Set WQE[CHAN] */
        c.s.grp_ok = wqe_grp; /* Set WQE[GRP] */
        c.s.grp_bad = wqe_grp; /* Set WQE[GRP] */
        c.s.aura = handle->aura); /* Set WQE[AURA] */

    /* We lookup the handle using the PKI input channel */
    __bdk_if_ipd_map[handle->ipd_port] = handle;
    return 0;
}

/**
 * Enable PKI after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pki_enable(void)
{
    BDK_CSR_MODIFY(c, BDK_PKI_BUF_CTL,
        c.s.pbp_en = 1; /* Enable backpressure */
        c.s.pki_en = 1); /* Enable PKI */
    /* Enable cluster group 0 */
    BDK_CSR_MODIFY(c, BDK_PKI_ICGX_CFG(0),
        c.s.pena = 1);
    return 0;
}

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
static int pko_global_init(void)
{
    return 0;
}

/**
 * Dynamically allocate a PKO fifo for a port
 *
 * @param size   The size needed in 2.5kb chunks (1,2,4).
 *
 * @return Fifo number of negative on failure
 */
int __bdk_pko_allocate_fifo(int size)
{
    /* Start at 0 znd look for a fifo location that has enough
        consecutive space */
    int fifo = 0;
    while (fifo < 32)
    {
        /* Buid a mask representing what this fifo would use */
        uint64_t mask = bdk_build_mask(size) << fifo;
        /* Stop search if all bits are free */
        if ((mask & free_fifo_mask) == 0)
        {
            /* Found a spot, mark it used and stop searching */
            free_fifo_mask |= mask;
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
    /* Program the PKO fifo */
    int index = fifo >> 2;
    BDK_CSR_INIT(cfg, BDK_PKO_PTGFX_CFG(index));
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
    BDK_CSR_WRITE(BDK_PKO_PTGFX_CFG(index), cfg.u);
    return 0;
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
    return 0;
}

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pko_enable(void)
{
    BDK_CSR_MODIFY(c, BDK_PKO_ENABLE,
        c.s.enable = 1);
    return 0;
}

/**
 * Initialize the SSO
 *
 * @return Zero on success, negative on failure
 */
static int sso_init(void)
{
    int grp;

    /* Setup an FPA pool to store the SSO queues */
    const int MAX_SSO_ENTRIES = 4096;
    int num_blocks = 256 + 48 + ((MAX_SSO_ENTRIES+25)/26);
    if (bdk_fpa_fill_pool(BDK_FPA_SSO_POOL, num_blocks))
        return -1;
    const int aura = BDK_FPA_SSO_POOL; /* Use 1:1 mapping aura */

    /* Initialize the 256 group/qos queues */
    for (grp=0; grp<256; grp++)
    {
        void *buffer = bdk_fpa_alloc(aura);
        if (buffer == NULL)
        {
            bdk_error("sso_init: Failed to allocate buffer\n");
            return -1;
        }
        uint64_t addr = bdk_ptr_to_phys(buffer);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_HEAD_PTR(grp),
            c.s.ptr = addr;
            c.s.cl = 0);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_HEAD_NEXT(grp),
            c.s.ptr = addr);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_TAIL_PTR(grp),
            c.s.ptr = addr;
            c.s.cl = 0);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_TAIL_NEXT(grp),
            c.s.ptr = addr);
        /* Prefetch one cache line into L1 when a core gets work */
        BDK_CSR_MODIFY(c, BDK_SSO_GRPX_PREF(grp),
            c.s.clines = 1);
    }
    /* Set the aura number */
    BDK_CSR_MODIFY(c, BDK_SSO_XAQ_AURA,
        c.s.aura = aura);
    /* Set work timeout to 1023 * 1k cycles */
    BDK_CSR_MODIFY(c, BDK_SSO_NW_TIM,
        c.s.nw_tim = 1023);
    /* Setup how the SSO accesses memory */
    BDK_CSR_MODIFY(c, BDK_SSO_AW_CFG,
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

    bdk_dprintf("SSO work %p\n"
        "  word0: 0x%016lx [aura=%d, apad=%d, chan=%d, bufs=%d, style=%d, pknd=%d]\n"
        "  word1: 0x%016lx [len=%d, grp=%d, tt=%d, tag=%d]\n"
        "  word2: 0x%016lx\n"
        "  word3: 0x%016lx [size=%d, dwd=%d, addr=0x%lx]\n"
        "  word4: 0x%016lx [vlptr=%d, lgptr=%d, lfptr=%d, leptr=%d, ldptr=%d, lcptr=%d, lbptr=%d, laptr=%d\n"
        "  word5: 0x%016lx\n"
        "  word6: 0x%016lx\n"
        "  word7: 0x%016lx\n",
        wqe,
        wqe->word0.u64,         /* word0 */
        wqe->word0.v3.aura,
        wqe->word0.v3.apad,
        wqe->word0.v3.chan,
        wqe->word0.v3.bufs,
        wqe->word0.v3.style,
        wqe->word0.v3.pknd,
        wqe->word1.u64,         /* word1 */
        wqe->word1.v3.len,
        wqe->word1.v3.grp,
        wqe->word1.v3.tt,
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

    packet->if_handle = __bdk_if_ipd_map[wqe->word0.v3.chan];
    bdk_dprintf("  Maps to %s, port=%d, aura=%d, pknd=%d\n",
        packet->if_handle->name, packet->if_handle->ipd_port,
        packet->if_handle->aura, packet->if_handle->pknd);
    packet->length = wqe->word1.v3.len;
    packet->segments = wqe->word0.v3.bufs;
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
            uint64_t    aura            :12;    /**< Aura to return buffers to */
            uint64_t    reserved_47     : 1;
            uint64_t    ckl4            : 1;    /**< Checksum L4 (TCP/UDP) */
            uint64_t    ckl3            : 1;    /**< Checksum L3 (IP) */
            uint64_t    ds              : 1;    /**< Don't send */
            uint64_t    le              : 1;    /**< Little endian */
            uint64_t    n2              : 1;    /**< No L2 allocate */
            uint64_t    ii              : 1;    /**< Ignore I bit */
            uint64_t    df              : 1;    /**< Don't free */
            uint64_t    format          : 8;    /**< Format index */
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
            uint64_t    reserved_26_35  :10;
            uint64_t    dq              :10;    /**< Descriptor queue to add to */
            uint64_t    reserved_0_15   :16;
        } s;
    } bdk_pko_send_dma_s_t;
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

    /* Build the two PKO comamnd words we need */
    bdk_pko_send_hdr_s_t pko_send_hdr_s;
    pko_send_hdr_s.u = 0;
    pko_send_hdr_s.s.aura = handle->aura;
    pko_send_hdr_s.s.n2 = 1;
    pko_send_hdr_s.s.format = 0; /* We don't use this? */
    pko_send_hdr_s.s.total = packet->length;

    bdk_pko_send_link_s_t pko_send_link_s;
    pko_send_link_s = packet->packet;

    /* Write the PKO commands to scratch */
    bdk_scratch_write64(BDK_IF_SCR_PKO(0), pko_send_hdr_s.u);
    bdk_scratch_write64(BDK_IF_SCR_PKO(1), pko_send_link_s.u64);
    bdk_scratch_write64(BDK_IF_SCR_PKO(2), -1);

    /* Build LMTDMA store data */
    bdk_pko_send_dma_s_t pko_send_dma_s;
    pko_send_dma_s.u = 0;
    pko_send_dma_s.s.scraddr = BDK_IF_SCR_PKO(2) >> 3;
    pko_send_dma_s.s.rtnlen = 1; /* One result work */
    pko_send_dma_s.s.did = 0x51;
    pko_send_dma_s.s.node = 0; // FIXME: Node number
    pko_send_dma_s.s.dq = handle->pko_queue;

    /* Issue LMTDMA with 2 dwords of data */
    bdk_write64_uint64(BDK_LMTDMA_ADDR(2), pko_send_dma_s.u);

    /* Wait for transmit to be queued */
    BDK_SYNCIOBDMA;

    /* Check transmit status */
    bdk_pko_query_rtn_s_t status;
    status.u = bdk_scratch_read64(BDK_IF_SCR_PKO(2));
    if (bdk_unlikely(status.s.dqstatus))
    {
        bdk_error("PKO transmit failed with status 0x%x\n", status.s.dqstatus);
        return -1;
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
    const int FPA_SIZE = bdk_fpa_get_block_size(aura);
    bdk_buf_ptr_t *buffer_ptr = &packet->packet;

    /* Start off with an empty packet */
    packet->length = 0;
    packet->segments = 0;

    /* Add buffers while the packet is less that the needed length */
    while (packet->length < length)
    {
        void *buffer = bdk_fpa_alloc(aura);
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
    const int aura = packet->if_handle->aura;
    int number_buffers = packet->segments;
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    bdk_buf_ptr_t next_buffer_ptr;
    BDK_SYNCW;
    while (number_buffers--)
    {
        /* Read pointer to next buffer before we free the current buffer. */
        if (number_buffers)
            next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
        __bdk_fpa_raw_free(buffer_ptr.v3.addr, aura, 0);
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

