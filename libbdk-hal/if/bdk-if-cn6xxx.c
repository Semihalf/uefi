#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

#define USE_PER_PORT_BACKPRESSURE 1
#define PIP_IP_OFFSET 2
#define BDK_PKO_MAX_OUTPUT_QUEUES 256
static __bdk_if_port_t *__bdk_if_ipd_map[0x1000];

/**
 * One time init of global Packet Input
 *
 * @return Zero on success, negative on failure
 */
static int pki_global_init(void)
{
    /* Skip one cache line so we have room to put the WQE at the
        beginning of the packet buffer */
    BDK_CSR_MODIFY(c, BDK_IPD_1ST_MBUFF_SKIP,
        c.s.skip_sz = 16);
    /* Set the back field in the first pointer to account for the
        cache line we skipped */
    BDK_CSR_MODIFY(c, BDK_IPD_1ST_NEXT_PTR_BACK,
        c.s.back = 1);

    /* Chained buffers don't have any skip */
    BDK_CSR_MODIFY(c, BDK_IPD_NOT_1ST_MBUFF_SKIP,
        c.s.skip_sz = 0);
    /* Set the chained back field to match*/
    BDK_CSR_MODIFY(c, BDK_IPD_2ND_NEXT_PTR_BACK,
        c.s.back = 0);

    /* Set the Buffer pool size */
    BDK_CSR_MODIFY(c, BDK_IPD_PACKET_MBUFF_SIZE,
        c.s.mb_size = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL)/8);

    BDK_CSR_MODIFY(c, BDK_IPD_CTL_STATUS,
        c.s.no_wptr = 1;    /* Store WQE in packet */
        c.s.len_m8 = 1;     /* Use correct lengths */
        c.s.addpkt = USE_PER_PORT_BACKPRESSURE; /* Increment backpressure accounting for every packet */
        c.s.pbp_en = 1;     /* Enable per port backpressure accounting */
        c.s.opc_mode = 1);  /* Store into L2 */

    /* Needed to support dynamic short */
    BDK_CSR_WRITE(BDK_PIP_IP_OFFSET, PIP_IP_OFFSET);

    /* Configure to allow max sized frames */
    BDK_CSR_MODIFY(pip_frm_len_chkx, BDK_PIP_FRM_LEN_CHKX(0),
        pip_frm_len_chkx.s.minlen = 64;
        pip_frm_len_chkx.s.maxlen = -1);

    /* Don't use clear on read as it has problems on CN68XX pass 1.x */
    BDK_CSR_MODIFY(c, BDK_PIP_STAT_CTL,
        c.s.mode = 0;
        c.s.rdclr = 0);

    int thresh_pass = 64;
    int thresh_drop = 32;
    /* Skip RED on CN61XX as we have too few buffers for it to work */
    if (OCTEON_IS_MODEL(OCTEON_CN61XX) && !__bdk_is_dram_enabled())
    {
        thresh_pass = 1;
        thresh_drop = 0;
    }

    for (int queue=0; queue<8; queue++)
    {
        /* Set RED to begin dropping packets when we're low on buffers */
        BDK_CSR_MODIFY(c, BDK_IPD_QOSX_RED_MARKS(queue),
            c.s.drop = thresh_drop;
            c.s.pass = thresh_pass);

        /* Use the actual queue 0 counter, not the average */
        BDK_CSR_MODIFY(c, BDK_IPD_RED_QUEX_PARAM(queue),
            c.s.prb_con = (255ul<<24) / (thresh_pass - thresh_drop);
            c.s.avg_con = 1;
            c.s.new_con = 255;
            c.s.use_pcnt = 1);
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
    static int qos = 0;
    static int next_free_pknd = 0;

    if (handle->ipd_port != -1)
    {
        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
            handle->pknd = next_free_pknd++;
        else
            handle->pknd = handle->ipd_port;
        if (handle->ipd_port >= 0x1000)
            bdk_fatal("IPD port too large for mapping table\n");
        __bdk_if_ipd_map[handle->ipd_port] = handle;
    }

    /* Have each port go to a different SSO queue */
    BDK_CSR_MODIFY(port_config, BDK_PIP_PRT_CFGX(handle->pknd),
        port_config.s.dyn_rs = 1;
        port_config.s.qos = qos;
        port_config.s.mode = bdk_config_get(BDK_CONFIG_INPUT_PORT_SKIP_MODE));

    /* Process the headers and place the IP header in the work queue */
    BDK_CSR_MODIFY(tag_config, BDK_PIP_PRT_TAGX(handle->pknd),
        tag_config.s.inc_prt_flag  = 1;
        tag_config.s.tcp6_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.tcp4_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.ip6_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.ip4_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.non_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.grp = 0);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Set the default BPID to match the PKND */
        BDK_CSR_MODIFY(c, BDK_PIP_PRT_CFGBX(handle->pknd), c.s.bpid = handle->pknd);
        /* Don't strip off FCS. We might want to see it when debugging */
        BDK_CSR_MODIFY(c, BDK_PIP_SUB_PKIND_FCSX(handle->pknd/64), c.s.port_bit &= ~(1ull<<(handle->pknd&63)));
        /* Enable checking of the FCS */
        BDK_CSR_MODIFY(c, BDK_PIP_PRT_CFGX(handle->pknd), c.s.crc_en = !!(handle->flags & BDK_IF_FLAGS_HAS_FCS));
        /* Backpressure when this port has 256 buffers in use */
        BDK_CSR_MODIFY(c, BDK_IPD_BPIDX_MBUF_TH(handle->pknd),
            c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
            c.s.page_cnt = 1);
        /* Enable RED dropping */
        BDK_CSR_MODIFY(c, BDK_IPD_RED_BPID_ENABLEX(handle->pknd/64), c.s.prt_enb |= 1ull<<(handle->pknd&63));
    }
    else
    {
        /* Don't strip off FCS. We might want to see it when debugging */
        BDK_CSR_MODIFY(c, BDK_IPD_SUB_PORT_FCS, c.u64 &= ~(1ull<<(handle->pknd)));
        if (handle->ipd_port < 36)
        {
            /* Backpressure when this port has 256 buffers in use */
            BDK_CSR_MODIFY(c, BDK_IPD_PORTX_BP_PAGE_CNT(handle->ipd_port),
                c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
                c.s.page_cnt = 1);
            /* Enable RED dropping */
            BDK_CSR_MODIFY(c, BDK_IPD_RED_PORT_ENABLE, c.s.prt_enb |= 1ull<<handle->ipd_port);
        }
        else if (handle->ipd_port < 40)
        {
            /* Backpressure when this port has 256 buffers in use */
            BDK_CSR_MODIFY(c, BDK_IPD_PORTX_BP_PAGE_CNT2(handle->ipd_port),
                c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
                c.s.page_cnt = 1);
            /* Enable RED dropping */
            BDK_CSR_MODIFY(c, BDK_IPD_RED_PORT_ENABLE2, c.s.prt_enb |= 1ull<<(handle->ipd_port-36));
        }
        else
        {
            /* Backpressure when this port has 256 buffers in use */
            BDK_CSR_MODIFY(c, BDK_IPD_PORTX_BP_PAGE_CNT3(handle->ipd_port),
                c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
                c.s.page_cnt = 1);
            /* Enable RED dropping */
            BDK_CSR_MODIFY(c, BDK_IPD_RED_PORT_ENABLE2, c.s.prt_enb |= 1ull<<(handle->ipd_port-36));
        }
    }

    /* Have the next port use a different input queue */
    qos = (qos + 1) & 7;

    return 0;
}

/**
 * Enable PKI after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pki_enable(void)
{
    /* Enable IPD */
    BDK_CSR_MODIFY(c, BDK_IPD_CTL_STATUS, c.s.ipd_en = 1);
    return 0;
}

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
static int pko_global_init(void)
{
    BDK_CSR_DEFINE(config, BDK_PKO_REG_CMD_BUF);
    config.u64 = 0;
    config.s.pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    config.s.size = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL) / 8;
    BDK_CSR_WRITE(BDK_PKO_REG_CMD_BUF, config.u64);

    /* Clear out all queue state */
    if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_QUEUE_PTRS);
        BDK_CSR_DEFINE(ptrs1, BDK_PKO_REG_QUEUE_PTRS1);

        ptrs.u64 = 0;
        ptrs.s.tail = 1;
        ptrs.s.port = -1;
        ptrs1.u64 = 0;

        for (int i=0; i<BDK_PKO_MAX_OUTPUT_QUEUES; i++)
        {
            ptrs1.s.qid7 = i>>7;
            ptrs.s.queue = i & 0x3f;
            BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_PTRS1, ptrs1.u64);
            BDK_CSR_WRITE(BDK_PKO_MEM_QUEUE_PTRS, ptrs.u64);
        }
    }
    else
    {
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IQUEUE_PTRS);
        ptrs.u64 = 0;
        ptrs.s.tail = 1;
        ptrs.s.ipid = -1;
        for (int i=0; i<BDK_PKO_MAX_OUTPUT_QUEUES; i++)
        {
            ptrs.s.qid = i;
            BDK_CSR_WRITE(BDK_PKO_MEM_IQUEUE_PTRS, ptrs.u64);
        }
    }
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
    int num_queues = sizeof(handle->cmd_queue) / sizeof(handle->cmd_queue[0]);
    for (int queue=0; queue<num_queues; queue++)
    {
        if (bdk_cmd_queue_initialize(&handle->cmd_queue[queue]))
            return -1;
    }

    int result = bdk_pko_config_port(handle->pko_port, num_queues, 0, handle->cmd_queue);
    if (result < 0)
        return result;
    handle->pko_queue = result;

    BDK_CSR_WRITE(BDK_PKO_MEM_COUNT0, handle->pko_port);
    BDK_CSR_WRITE(BDK_PKO_MEM_COUNT1, handle->pko_port);

    return 0;
}

static int __bdk_pko_memory_per_engine(int engine)
{
    extern int bdk_pko_next_free_engine;
    /* CN68XX has 40KB to divide between the engines in 2KB chunks */
    int size_per_engine = 40 / 2 / bdk_pko_next_free_engine;
    int size;

    if (engine >= bdk_pko_next_free_engine)
    {
        /* Unused engines get no space */
        size = 0;
    }
    else if (engine == bdk_pko_next_free_engine-1)
    {
        /* The last engine gets all the space lost by rounding. This means
            the ILK gets the most space */
        size = 40 / 2 - engine * size_per_engine;
    }
    else
    {
        /* All other engines get the same space */
        size = size_per_engine;
    }

    return size;
}

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pko_enable(void)
{
    extern int bdk_pko_next_free_queue;
    extern int bdk_pko_next_free_engine;
    bdk_pko_reg_flags_t flags;

    /* If we aren't using all of the queues optimize PKO's internal memory */
    /* <=32 is only supported on CN68XX */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX) && (bdk_pko_next_free_queue <= 32))
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 3);
    else if (bdk_pko_next_free_queue <= 64)
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 2);
    else if (bdk_pko_next_free_queue <= 128)
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 1);

    /* Optimize the PKO engine memory */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        for (int i=0; i<2; i++)
        {
            BDK_CSR_INIT(engine_storage, BDK_PKO_REG_ENGINE_STORAGEX(i));
            engine_storage.s.engine0 = __bdk_pko_memory_per_engine(16*i + 0);
            engine_storage.s.engine1 = __bdk_pko_memory_per_engine(16*i + 1);
            engine_storage.s.engine2 = __bdk_pko_memory_per_engine(16*i + 2);
            engine_storage.s.engine3 = __bdk_pko_memory_per_engine(16*i + 3);
            engine_storage.s.engine4 = __bdk_pko_memory_per_engine(16*i + 4);
            engine_storage.s.engine5 = __bdk_pko_memory_per_engine(16*i + 5);
            engine_storage.s.engine6 = __bdk_pko_memory_per_engine(16*i + 6);
            engine_storage.s.engine7 = __bdk_pko_memory_per_engine(16*i + 7);
            engine_storage.s.engine8 = __bdk_pko_memory_per_engine(16*i + 8);
            engine_storage.s.engine9 = __bdk_pko_memory_per_engine(16*i + 9);
            engine_storage.s.engine10 = __bdk_pko_memory_per_engine(16*i + 10);
            engine_storage.s.engine11 = __bdk_pko_memory_per_engine(16*i + 11);
            engine_storage.s.engine12 = __bdk_pko_memory_per_engine(16*i + 12);
            engine_storage.s.engine13 = __bdk_pko_memory_per_engine(16*i + 13);
            engine_storage.s.engine14 = __bdk_pko_memory_per_engine(16*i + 14);
            engine_storage.s.engine15 = __bdk_pko_memory_per_engine(16*i + 15);
            BDK_CSR_WRITE(BDK_PKO_REG_ENGINE_STORAGEX(i), engine_storage.u64);
        }
        /* Enable using the internal storage for all engines */
        BDK_CSR_WRITE(BDK_PKO_REG_ENGINE_THRESH, (1<<bdk_pko_next_free_engine)-1);
    }

    flags.u64 = BDK_CSR_READ(BDK_PKO_REG_FLAGS);
    if (flags.s.ena_pko)
        bdk_warn("Enabling PKO when PKO already enabled.\n");

    flags.s.ena_dwb = BDK_USE_DWB;
    flags.s.ena_pko = 1;
    flags.s.store_be =1;  /* always enable big endian for 3-word command. Does nothing for 2-word */
    BDK_CSR_WRITE(BDK_PKO_REG_FLAGS, flags.u64);
    return 0;
}

/**
 * Initialize the SSO
 *
 * @return Zero on success, negative on failure
 */
static int sso_init(void)
{
    const int SSO_RWQ_SIZE = 256;
    const int SSO_RWQ_COUNT = 8 + 128;

    /* Disable tagwait FAU timeout. This needs to be done before anyone might
        start packet output using tags */
    bdk_iob0_fau_timeout_t fau_to;
    fau_to.u64 = 0;
    fau_to.s.tout_val = 0xfff;
    fau_to.s.tout_enb = 0;
    if (OCTEON_IS_MODEL(OCTEON_CN70XX))
        BDK_CSR_WRITE(BDK_IOB_FAU_TIMEOUT, fau_to.u64);
    else
        BDK_CSR_WRITE(BDK_IOB0_FAU_TIMEOUT, fau_to.u64);

    /* Only CN68XX needs setup */
    if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 0;

    /* Errata FPA-15816 in CN68XX pass 1.x has the pool 8 threshold wrong */
    BDK_CSR_MODIFY(c, BDK_FPA_FPF8_MARKS,
        c.s.fpf_wr = 164);

    /* Set work timeout to 1k cycles. Due to a bug in Octeon 2, reads
        from scratch will always wait for get_work to complete, so we
        want this fast */
    BDK_CSR_MODIFY(c, BDK_SSO_NW_TIM,
        c.s.nw_tim = 0);

    void *buffer = memalign(BDK_CACHE_LINE_SIZE, SSO_RWQ_SIZE*(16+SSO_RWQ_COUNT));
    if (!buffer)
    {
        bdk_error("Failed to allocate buffers for SSO\n");
        return -1;
    }

    /* Initialize the SSO memory queues */
    for (int i=0; i<8; i++)
    {
        BDK_CSR_WRITE(BDK_SSO_RWQ_HEAD_PTRX(i), bdk_ptr_to_phys(buffer));
        BDK_CSR_WRITE(BDK_SSO_RWQ_TAIL_PTRX(i), bdk_ptr_to_phys(buffer));
        buffer += SSO_RWQ_SIZE;
    }

    /* Initialize the RWQ list */
    for (int i=0; i<SSO_RWQ_COUNT; i++)
    {
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_SSO_RWQ_PSH_FPTR, full, ==, 0, 1000))
        {
            bdk_error("BDK_SSO_RWQ_PSH_FPTR[FULL] is stuck\n");
            return -1;
        }

        BDK_CSR_WRITE(BDK_SSO_RWQ_PSH_FPTR, bdk_ptr_to_phys(buffer));
        buffer += SSO_RWQ_SIZE;
    }

    /* Enable the SSO RWI/RWO operations */
    BDK_CSR_MODIFY(c, BDK_SSO_CFG,
        c.s.dwb = BDK_USE_DWB; /* Use 2 cache line DWB for RWQ */
        c.s.rwen = 1);

    /* Workaround for errata (SSO-16306) Some customers report SSO can hang */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X))
        BDK_CSR_MODIFY(c, BDK_SSO_GWE_CFG, c.cn68xx.gwe_rah = 1);

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

    /* Get the IPD port number */
    int ipd_port = wqe->word2.s.port;
    if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
        ipd_port = wqe->word1.v1.ipprt;

    packet->if_handle = __bdk_if_ipd_map[ipd_port];
    packet->length = wqe->word1.s.len;
    if (bdk_unlikely(wqe->word2.s.re))
        packet->rx_error = wqe->word2.s.opcode;
    else
        packet->rx_error = 0;

    if (bdk_likely(wqe->word2.s.bufs == 0))
    {
        packet->segments = 1;
        packet->packet.u64 = 0;
        packet->packet.s.back = 0;
        packet->packet.s.pool = BDK_FPA_PACKET_POOL;
        packet->packet.s.size = 128; // FIXME packet size
        packet->packet.s.addr = bdk_ptr_to_phys((void*)wqe->packet_data);
        if (bdk_likely(!wqe->word2.s.ni))
        {
            packet->packet.s.addr += (PIP_IP_OFFSET<<3) - wqe->word2.ip.ip_offset;
            packet->packet.s.addr += (wqe->word2.ip.v6^1)<<2;
        }
        else
        {
            /* WARNING: This code assume that the packet is not RAW. If it was,
                we would use PIP_GBL_CFG[RAW_SHF] instead of
                PIP_GBL_CFG[NIP_SHF] */
            BDK_CSR_INIT(pip_gbl_cfg, BDK_PIP_GBL_CFG);
            packet->packet.s.addr += pip_gbl_cfg.s.nip_shf;
        }
    }
    else
    {
        packet->segments = wqe->word2.s.bufs;
        packet->packet = wqe->packet_ptr;
    }

    if (bdk_unlikely(!packet->if_handle))
    {
        bdk_error("Unable to find IF for ipd_port %d\n", ipd_port);
        bdk_if_free(packet);
        return -1;
    }

    if (USE_PER_PORT_BACKPRESSURE)
    {
        /* Subtract this packet's segemnts from the port's IPD usage */
        BDK_CSR_DEFINE(page_cnt, BDK_IPD_SUB_PORT_BP_PAGE_CNT);
        page_cnt.u64 = 0;
        page_cnt.s.port = packet->if_handle->pknd;
        page_cnt.s.page_cnt = (wqe->word2.s.bufs == 0) ? -1 : -packet->segments-1;
        BDK_CSR_WRITE(BDK_IPD_SUB_PORT_BP_PAGE_CNT, page_cnt.u64);
    }
    return 0;
}

__bdk_if_global_ops_t __bdk_if_global_ops_cn6xxx = {
    .pki_global_init = pki_global_init,
    .pki_port_init = pki_port_init,
    .pki_enable = pki_enable,
    .pko_global_init = pko_global_init,
    .pko_port_init = pko_port_init,
    .pko_enable = pko_enable,
    .sso_init = sso_init,
    .sso_wqe_to_packet = sso_wqe_to_packet,
};

