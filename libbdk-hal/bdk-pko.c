#include <bdk.h>

#define PKO_MAX_DQ 256 /* CN83XX, Must be a define as it sizes static arrays */
static const int PKO_QUEUES_PER_CHANNEL = 1;
static const int PKO_DEPTH_LIMIT = 4096 / 8; /* Max command words to have pending in PKO queues */

/* PKO global variables */
typedef struct
{
    uint8_t pko_pending[PKO_MAX_DQ];/* Queue depth in SW before updating HW */
    int64_t pko_depth[PKO_MAX_DQ];  /* Queue depth, updated with atomics from HW */
    uint64_t pko_depth_address;     /* Cached physical address of pko_depth[] (above) */
    uint64_t pko_free_fifo_mask;    /* PKO_PTGFX_CFG(7) is reserved for NULL MAC */
    int pko_next_free_port_queue;   /* L1 = Port Queues are 0-15 (CN83XX) */
    int pko_next_free_l2_queue;     /* L2 = Channel Queues 0-255 (CN83XX) */
    int pko_next_free_l3_queue;     /* L3 = Channel Queues 0-255 (CN83XX) */
    int pko_next_free_descr_queue;  /* L6 = Descriptor Queues 0-255 (CN83XX) */
} global_node_state_t;

static global_node_state_t global_node_state[BDK_NUMA_MAX_NODES];

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
int bdk_pko_global_init(bdk_node_t node)
{
    global_node_state_t *node_state = &global_node_state[node];
    memset(node_state, 0, sizeof(*node_state));
    node_state->pko_free_fifo_mask = 0x0fffffff; /* PKO_PTGFX_CFG(7) is reserved for NULL MAC */
    node_state->pko_depth_address = bdk_ptr_to_phys(node_state->pko_depth);

    int num_buffers = 128;
    /* Use more buffers when dram is available */
    if (__bdk_is_dram_enabled(node))
        num_buffers = 1024;
    if (bdk_fpa_fill_pool(node, BDK_FPA_PKO_POOL, num_buffers))
        return -1;
    const int aura = BDK_FPA_PKO_POOL; /* Use 1:1 mapping aura */
    BDK_CSR_MODIFY(c, node, BDK_PKO_DPFI_FPA_AURA,
        c.s.node = node;
        c.s.laura = aura);
    BDK_CSR_MODIFY(c, node, BDK_PKO_DPFI_ENA,
        c.s.enable = 1);
    BDK_CSR_MODIFY(c, node, BDK_PKO_PTF_IOBP_CFG,
        c.s.iobp1_magic_addr = bdk_numa_get_address(bdk_numa_master(), 0) >> 7;
        c.s.max_read_size = 16); /* Recommended by Joe Tompkins */
    BDK_CSR_MODIFY(c, node, BDK_PKO_PDM_CFG,
        c.s.pko_pad_minlen = 60);
    /* Configure format 0 so that if marking is used, yellow packets are
       marked with a 1 and red packets are marked with a 2. Set the mask
       so we change all four possible bits. Set the offset to 12, which causes
       the bits to be the lower 4 bits of the IPv4 TOS byte */
    BDK_CSR_MODIFY(c, node, BDK_PKO_FORMATX_CTL(0),
        c.s.offset = 12; /* Skip IP header, Lower 4 bits of TOS */
        c.s.y_mask = 0xe; /* Clear bits 3:1 */
        c.s.y_val = 0x1; /* Set bit 0 */
        c.s.r_mask = 0xd; /* Clear bits 3:2,0 */
        c.s.r_val = 0x2); /* Set bit 1 */
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
    cfg.s.rate = 1; /* Default rate for all ports is 12.5 Gb/s */
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
                    cfg.s.size = 4; /* 10kb */
                    cfg.s.rate = 3; /* Large FIFOs are for 40G links, use 50 Gb/s */
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
                    cfg.s.size = 3; /* 5kb, 5kb */
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

    /* Setup PKO MCI1 credits */
    int mac_buffering;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
    {
        switch (lmac)
        {
            case 0: /* LBK */
                mac_buffering = 4096; /* From HRM 11.14.1 */
                break;
            case 1: /* DPI */
                mac_buffering = 2048; /* From HRM 11.14.1 */
                break;
            default: /* BGX */
                mac_buffering = size * 8192; /* 8KB, 16KB, or 32KB */
                break;
        }
    }
    else
        bdk_fatal("Update __bdk_pko_allocate_fifo() for this chip");
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
int bdk_pko_port_init(bdk_if_handle_t handle)
{
    global_node_state_t *node_state = &global_node_state[handle->node];
    int pq;     /* L1 = port queue */
    int sq_l2;  /* L2 = schedule queue feeding PQ */
    int sq_l3;  /* L3 = schedule queue feeding L2 */
    int dq;     /* L4 = descriptor queue feeding L3 */

    if (node_state->pko_next_free_l2_queue >= PKO_MAX_DQ)
    {
        bdk_error("pko_port_init: Ran out of L2 queues\n");
        return -1;
    }
    if (node_state->pko_next_free_l3_queue >= PKO_MAX_DQ)
    {
        bdk_error("pko_port_init: Ran out of L3 queues\n");
        return -1;
    }
    if (node_state->pko_next_free_descr_queue > PKO_MAX_DQ - PKO_QUEUES_PER_CHANNEL)
    {
        bdk_error("pko_port_init: Ran out of descriptor (L6) queues\n");
        return -1;
    }

    if ((handle->index == 0) || (handle->iftype == BDK_IF_BGX))
    {
        if (node_state->pko_next_free_port_queue >= 16)
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
            BDK_CSR_INIT(config, handle->node, BDK_BGXX_CMRX_CONFIG(handle->interface, handle->index));
            switch (config.s.lmac_type)
            {
                case 0: /* SGMII - 1 lane each */
                case 5: /* RGMII */
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
                    skid_max_cnt = 1;
                    fcs_ena = 1;
                    break;
                case 1: /* 10GBASE-X/XAUI or DXAUI - 4 lanes each */
                    fifo_size = 4;
                    fcs_ena = 1;
                    skid_max_cnt = 2;
                    break;
                case 4: /* 40GBASE-R - 4 lanes each */
                default:
                    fifo_size = 4;
                    fcs_ena = 1;
                    skid_max_cnt = 2;
                    break;
            }
            lmac = 2 + 4 * handle->interface + port;
            compressed_channel_id = BDK_PKI_CHAN_E_BGXX_LMACX_CHX(handle->interface, handle->index, 0 /* channel */);
            break;
        }
        case BDK_IF_PCIE:
            lmac = 1;
            fifo_size = 4;
            fcs_ena = 0;
            skid_max_cnt = 2;
            compressed_channel_id = BDK_PKI_CHAN_E_DPI_CHX(handle->index);
            break;
        case BDK_IF_LBK:
            lmac = 0;
            fifo_size = 4;
            fcs_ena = 0;
            skid_max_cnt = 2;
            compressed_channel_id = BDK_PKI_CHAN_E_LBKX_CHX(handle->interface, handle->index);
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
        BDK_CSR_WRITE(handle->node, BDK_PKO_MACX_CFG(lmac), pko_macx_cfg.u);
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
        c.s.cc_channel = handle->pki_channel);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L3_SQX_SCHEDULE(sq_l3),
        c.s.prio = 0;
        c.s.rr_quantum = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_L3_SQX_TOPOLOGY(sq_l3),
        c.s.prio_anchor = dq;
        c.s.parent = sq_l2;
        c.s.rr_prio = 0);
    /* Program L4 = descriptor queue */
    for (int q=0; q<PKO_QUEUES_PER_CHANNEL; q++)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_DQX_SCHEDULE(dq+q),
            c.s.prio = 0;
            c.s.rr_quantum = 0);
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_DQX_TOPOLOGY(dq+q),
            c.s.parent = sq_l3);
    }
    if (compressed_channel_id != -1)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_LUTX(compressed_channel_id),
            c.s.valid = 1;
            c.s.pq_idx = pq;
            c.s.queue_number = sq_l2); /* Would be sql_l3 if PKO_CHANNEL_LEVEL[cc_level]=1 */
    }
    handle->pko_queue = dq;

    /* Have the PKO DQ watermarks count packets. This way they are equivalent
       to the queue depth */
    BDK_CSR_MODIFY(c, handle->node, BDK_PKO_VDQX_WM_CTL(dq),
        c.s.kind = 1);

    return 0;
}

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
int bdk_pko_enable(bdk_node_t node)
{
    global_node_state_t *node_state = &global_node_state[node];

    /* Take FIFOs out of reset */
    /* CN83XX: 0-4 for PKO_PTGFX_CFG */
    int num_ptgfx = 5;
    for (int i = 0; i < num_ptgfx; i++)
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

    int dq_inc = 1;
    /* Open all configured descriptor queues */
    for (int dq=0; dq<node_state->pko_next_free_descr_queue; dq+=dq_inc)
    {
        BDK_CSR_INIT(pko_open, node, BDK_PKO_VDQX_OP_OPEN(dq));
        if (pko_open.s.dqstatus != BDK_PKO_DQSTATUS_E_PASS)
            bdk_error("PKO open failed with response 0x%lx\n", pko_open.u);
    }
    return 0;
}

/**
 * Get the current TX queue depth. Note that this operation may be slow
 * and adversly affect packet IO performance.
 *
 * @param handle Port to check
 *
 * @return Depth of the queue in packets
 */
int bdk_pko_get_queue_depth(bdk_if_handle_t handle)
{
    return BDK_CSR_READ(handle->node, BDK_PKO_DQX_WM_CNT(handle->pko_queue));
}

/**
 * Set PKO shapping as a specific queue level
 *
 * @param node       Node to shape
 * @param queue      Queue to shape
 * @param level      Level in PKO
 * @param is_red     Non-zero of the rate is for the yellow/red transition. Zero for the
 *                   green/yellow transition.
 * @param is_packets Non-zero if the rate is packets/sec, otherwise rate is bits/sec
 * @param rate       Desired rate. A rate of zero disables shaping
 *
 * @return Zero on success, negative on failure
 */
int bdk_pko_shape(bdk_node_t node, int queue, int level, int is_red, int is_packets, uint64_t rate)
{
    const int BURST_TIME = 10; /* us */
    /* Figure out how many times per second the shaper updates. L1 is every
       48 cycles, all other level are every 768 cycles */
    uint64_t sclk = bdk_clock_get_rate(node, BDK_CLOCK_SCLK);
    uint64_t tick = (level == 1) ? 48 : 768;
    uint64_t tick_per_sec = (sclk + tick/2) / tick;
    BDK_TRACE(PKO, "SCLK = %lu, tick = %lu, ticks/sec = %lu\n", sclk, tick, tick_per_sec);
    /* Average over the longer time period, 2^12 ticks */
    int rate_divider_exponent = 12; /* Max value is 1<<12 ticks */
retry_lower_divider:
    BDK_TRACE(PKO, "Trying rate divider exponent %d\n", rate_divider_exponent);
    /* RATE (bytes/second) = (tick_per_sec) * ((1.RATE_MANTISSA) << RATE_EXPONENT) / (1 << RATE_DIVIDER_EXPONENT) */
    uint64_t raw_rate = ((rate << rate_divider_exponent) + tick_per_sec/2) / tick_per_sec;
    if (is_packets)
        BDK_TRACE(PKO, "    rate = %lu packets/sec, raw_rate = %lu (packets/tick << %d)\n", rate, raw_rate, rate_divider_exponent);
    else
    {
        raw_rate = (raw_rate + 4) / 8; /* Convert to bytes */
        BDK_TRACE(PKO, "    rate = %lu bits/sec, raw_rate = %lu (bytes/tick << %d)\n", rate, raw_rate, rate_divider_exponent);
    }
    /* The below calculations scale the rate between 0x100 and 0x1ff. These are
       actually floating point, so they represent 1.xx. Multiply by 256 to
       account for this */
    raw_rate <<= 8;
    /* Scale to fit in range */
    int rate_exponent = 0;
    while (raw_rate >= 0x200)
    {
        rate_exponent++;
        raw_rate >>= 1;
    }
    /* Rate exponent is limited to 8 bits */
    if (rate_exponent > 0xff)
    {
        if (rate_divider_exponent)
        {
            BDK_TRACE(PKO, "    Rate too larger, reducing rate divider exponent\n");
            rate_divider_exponent--;
            goto retry_lower_divider;
        }
        rate_exponent = 0xff;
        raw_rate = 0x1ff;
    }
    BDK_TRACE(PKO, "    rate_exponent = %d, raw_rate = 0x%lx (should be 0x1xx)\n", rate_exponent, raw_rate);
    /* The mantissa implies the top bit, so and it off */
    int rate_mantissa = raw_rate & 0xff;
    /* Calculate the burst as rate * BURST_TIME */
    uint64_t ticks_per_burst = BURST_TIME * tick_per_sec / 1000000;
    uint64_t burst = raw_rate * ticks_per_burst;
    /* Scale to fit in range */
    int burst_exponent = rate_exponent;
    while (burst >= 0x200)
    {
        burst_exponent++;
        burst >>= 1;
    }
    /* Burst exponent is limited to 4 bits enocded in -1 notation */
    if (burst_exponent > 0x10)
    {
        if (rate_divider_exponent)
        {
            BDK_TRACE(PKO, "    Burst too larger, reducing rate divider exponent\n");
            rate_divider_exponent--;
            goto retry_lower_divider;
        }
        burst_exponent = 0x10;
        burst = 0xff;
    }
    BDK_TRACE(PKO, "    burst_exponent = %d, burst = 0x%lx (should be 0x1xx)\n", burst_exponent, burst);
    /* The mantissa implies the top bit, so and it off */
    int burst_mantissa = burst & 0xff;
    /* All of this is only enable of rate is not zero */
    int enable = (rate != 0);

    if (is_red)
    {
        bdk_pko_dqx_pir_t pir = {.u = 0};
        pir.s.burst_exponent = (burst_exponent) ? burst_exponent - 1 : 0; /* Encoded in -1 notation */
        pir.s.burst_mantissa = burst_mantissa;
        pir.s.rate_divider_exponent = rate_divider_exponent;
        pir.s.rate_exponent = rate_exponent;
        pir.s.rate_mantissa = rate_mantissa;
        pir.s.enable = enable;
        switch (level)
        {
            case 0:
                BDK_CSR_WRITE(node, BDK_PKO_DQX_PIR(queue), pir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_DQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            case 1:
                bdk_error("PKO: Level %d doesn't support yellow/red rate limiting\n", level);
                return -1;
            case 2:
                BDK_CSR_WRITE(node, BDK_PKO_L2_SQX_PIR(queue), pir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_L2_SQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            case 3:
                BDK_CSR_WRITE(node, BDK_PKO_L3_SQX_PIR(queue), pir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_L3_SQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            default:
                bdk_error("PKO: Invalid level %d\n", level);
                return -1;
        }
    }
    else
    {
        bdk_pko_dqx_cir_t cir = {.u = 0};
        cir.s.burst_exponent = (burst_exponent) ? burst_exponent - 1 : 0; /* Encoded in -1 notation */
        cir.s.burst_mantissa = burst_mantissa;
        cir.s.rate_divider_exponent = rate_divider_exponent;
        cir.s.rate_exponent = rate_exponent;
        cir.s.rate_mantissa = rate_mantissa;
        cir.s.enable = enable;
        switch (level)
        {
            case 0:
                BDK_CSR_WRITE(node, BDK_PKO_DQX_CIR(queue), cir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_DQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            case 1:
                BDK_CSR_WRITE(node, BDK_PKO_L1_SQX_CIR(queue), cir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_L1_SQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            case 2:
                BDK_CSR_WRITE(node, BDK_PKO_L2_SQX_CIR(queue), cir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_L2_SQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            case 3:
                BDK_CSR_WRITE(node, BDK_PKO_L3_SQX_CIR(queue), cir.u);
                BDK_CSR_MODIFY(c, node, BDK_PKO_L3_SQX_SHAPE(queue),
                    c.s.length_disable = is_packets;
                    c.s.adjust = is_packets);
                return 0;
            default:
                bdk_error("PKO: Invalid level %d\n", level);
                return -1;
        }
    }
}

/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
int bdk_pko_transmit(bdk_if_handle_t handle, const bdk_if_packet_t *packet)
{
    global_node_state_t *node_state = &global_node_state[handle->node];

    /* Flush pending writes */
    BDK_WMB;

    int64_t *pko_depth_ptr = node_state->pko_depth + handle->pko_queue;
    int64_t pko_depth = *(volatile int64_t *)pko_depth_ptr;
    if (pko_depth >= PKO_DEPTH_LIMIT)
    {
        //bdk_error("%s: PKO transmit aborted due queue depth\n", bdk_if_name(handle));
        return -1;
    }

    int lmt_status;
    do
    {
        /* To reduce NCB bus traffic, we decrement the queue depth for PKO
           every ~256 commands instead of on every packet. Pending and pko offset
           are 1 byte each, we write at most 15 words, round up to 16 */
        int pko_pending = node_state->pko_pending[handle->pko_queue];
        int need_decrement = (pko_pending >= (256 - 16));
        int lmstore_words = 0;
        /* Build the three PKO comamnd words we need */
        union bdk_pko_send_hdr_s pko_send_hdr_s;
        pko_send_hdr_s.u = 0;
        pko_send_hdr_s.s.df = 1;
        pko_send_hdr_s.s.format = 0; /* We don't use this? */
        pko_send_hdr_s.s.total = packet->length;
        pko_send_hdr_s.s.l3ptr = 14; /* This is the offset of the IP header created by traffic-gen */

        bdk_lmt_cancel();
        bdk_lmt_store(lmstore_words, pko_send_hdr_s.u);
        lmstore_words++;

        /* PKO allows a max of 15 minus header and decrement */
        for (int seg = 0; seg < packet->segments; seg++)
        {
            bdk_packet_ptr_t ptr = packet->packet[seg];
            union bdk_pko_send_gather_s pko_send_gather_s;
            pko_send_gather_s.u = 0;
            pko_send_gather_s.s.size = ptr.s.size;
            pko_send_gather_s.s.subdc3 = 0x1;
            pko_send_gather_s.s.addr = ptr.s.address;
            bdk_lmt_store(lmstore_words, pko_send_gather_s.u);
            lmstore_words++;
        }

        /* Memory decrement when done */
        if (need_decrement)
        {
            union bdk_pko_send_mem_s pko_send_mem_s;
            pko_send_mem_s.u = 0;
            pko_send_mem_s.s.offset = pko_pending;
            pko_send_mem_s.s.alg = 9; /* Subtract */
            pko_send_mem_s.s.subdc4 = 0xc;
            pko_send_mem_s.s.addr = node_state->pko_depth_address + handle->pko_queue * 8;
            bdk_lmt_store(lmstore_words, pko_send_mem_s.u);
            pko_pending = 0;
            lmstore_words++;
        }

        /* Build LMTDMA store data */
        uint64_t io_address = BDK_PKO_VDQX_OP_SENDX(handle->pko_queue, lmstore_words);
        io_address = bdk_numa_get_address(handle->node, io_address);

        /* Increment the PKO depth. PKO will decrement it when its done. This
           will invalidate our L1 copy, so do it last before submit. It needs
           to be before the submit to insure the depth never goes negative */
        node_state->pko_pending[handle->pko_queue] = pko_pending + lmstore_words;
        bdk_atomic_add64_nosync(pko_depth_ptr, lmstore_words);

        /* Issue LMTST, retrying if hardware says we should */
        lmt_status = bdk_lmt_submit(io_address);
    } while (lmt_status == 0);

    return 0;
}

/**
 * Query PKO and fill in the receive stats for the supplied
 * interface handle. The interface must use PKO for TX.
 *
 * @param handle Port handle
 *
 * @return
 */
void bdk_pko_fill_tx_stats(bdk_if_handle_t handle)
{
    /* Account for TX adding FCS */
    const int bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;

    BDK_CSR_INIT(pkts, handle->node, BDK_PKO_DQX_PACKETS(handle->pko_queue));
    BDK_CSR_INIT(octs, handle->node, BDK_PKO_DQX_BYTES(handle->pko_queue));
    BDK_CSR_INIT(drps, handle->node, BDK_PKO_DQX_DROPPED_PACKETS(handle->pko_queue));
    BDK_CSR_INIT(doct, handle->node, BDK_PKO_DQX_DROPPED_BYTES(handle->pko_queue));

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.packets = bdk_update_stat_with_overflow(pkts.u, handle->stats.tx.packets, 40);
    handle->stats.tx.octets = bdk_update_stat_with_overflow(octs.u, handle->stats.tx.octets, 48);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    handle->stats.tx.dropped_packets -= handle->stats.tx.dropped_packets * bytes_off_tx;
    handle->stats.tx.dropped_packets = bdk_update_stat_with_overflow(drps.u, handle->stats.tx.dropped_packets, 40);
    handle->stats.tx.dropped_octets = bdk_update_stat_with_overflow(doct.u, handle->stats.tx.dropped_octets, 48);
    handle->stats.tx.dropped_packets += handle->stats.tx.dropped_packets * bytes_off_tx;
}
