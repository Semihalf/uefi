#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

#define USE_SOFTWARE_COUNTERS 0

extern const __bdk_if_ops_t __bdk_if_ops_sgmii;
extern const __bdk_if_ops_t __bdk_if_ops_xaui;
extern const __bdk_if_ops_t __bdk_if_ops_dpi;
extern const __bdk_if_ops_t __bdk_if_ops_loop;
extern const __bdk_if_ops_t __bdk_if_ops_srio;
extern const __bdk_if_ops_t __bdk_if_ops_mgmt;
extern const __bdk_if_ops_t __bdk_if_ops_ilk;

static const __bdk_if_ops_t *__bdk_if_ops[__BDK_IF_LAST] = {
    [BDK_IF_SGMII] = &__bdk_if_ops_sgmii,
    [BDK_IF_XAUI] = &__bdk_if_ops_xaui,
    [BDK_IF_DPI] = &__bdk_if_ops_dpi,
    [BDK_IF_LOOP] = &__bdk_if_ops_loop,
    [BDK_IF_SRIO] = &__bdk_if_ops_srio,
    [BDK_IF_MGMT] = &__bdk_if_ops_mgmt,
    [BDK_IF_ILK] = &__bdk_if_ops_ilk,
};

static __bdk_if_port_t *__bdk_if_head;
static __bdk_if_port_t *__bdk_if_tail;
static __bdk_if_port_t *__bdk_if_poll_head;
static __bdk_if_port_t *__bdk_if_ipd_map[0x1000];

/**
 * One time init of the SSO
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_if_setup_sso(void)
{
    const int SSO_RWQ_SIZE = 256;
    const int SSO_RWQ_COUNT = 8 + 128;

    /* SSO in CN63XX doesn't need any setup */
    if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 0;

    /* Set work timeout to 16k cycles */
    BDK_CSR_MODIFY(c, BDK_SSO_NW_TIM,
        c.s.nw_tim = 16);

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
        c.s.dwb = 1; /* Use 2 cache line DWB for RWQ */
        c.s.rwen = 1);
    return 0;
}


/**
 * One time init of global IPD/PIP
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_if_setup_ipd_global(void)
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
        c.s.pbp_en = 1;     /* Enable per port backpressure accounting */
        c.s.opc_mode = 1);  /* Store into L2 */

    /* Needed to support dynamic short */
    BDK_CSR_WRITE(BDK_PIP_IP_OFFSET, 4);

    /* Configure to allow max sized frames */
    BDK_CSR_MODIFY(pip_frm_len_chkx, BDK_PIP_FRM_LEN_CHKX(0),
        pip_frm_len_chkx.s.minlen = 64;
        pip_frm_len_chkx.s.maxlen = -1);

    /* Don't use clear on read as it has problems on CN68XX pass 1.x */
    BDK_CSR_MODIFY(c, BDK_PIP_STAT_CTL,
        c.s.mode = 0;
        c.s.rdclr = 0);

    for (int queue=0; queue<8; queue++)
    {
        int thresh_pass = 64;
        int thresh_drop = 32;

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
 * Configure PIP/IPD for a specific port. This is called for each
 * port on every interface that is connected to PIP/IPD.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_if_setup_ipd(bdk_if_handle_t handle)
{
    static int qos = 0;

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
        /* Don't strip off FCS. We might want to see it when debugging */
        BDK_CSR_MODIFY(c, BDK_PIP_SUB_PKIND_FCSX(handle->pknd/64), c.s.port_bit &= ~(1ull<<(handle->pknd&63)));
        /* Enable checking of the FCS */
        BDK_CSR_MODIFY(c, BDK_PIP_PRT_CFGX(handle->pknd), c.s.crc_en = handle->has_fcs);
        /* Enable RED dropping */
        BDK_CSR_MODIFY(c, BDK_IPD_RED_BPID_ENABLEX(handle->pknd/64), c.s.prt_enb |= 1ull<<(handle->pknd&63));
    }
    else
    {
        /* Don't strip off FCS. We might want to see it when debugging */
        BDK_CSR_MODIFY(c, BDK_IPD_SUB_PORT_FCS, c.u64 &= ~(1ull<<(handle->pknd)));
    }

    /* Have the next port use a different input queue */
    qos = (qos + 1) & 7;

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
static int __bdk_if_setup_pko(bdk_if_handle_t handle)
{
    const int buffers_per_queue = 4;
    int num_queues = 1;

    /* Allocate command buffers per queue */
    if (bdk_fpa_fill_pool(BDK_FPA_OUTPUT_BUFFER_POOL, num_queues*buffers_per_queue))
        return -1;

    if (bdk_cmd_queue_initialize(&handle->cmd_queue, BDK_FPA_OUTPUT_BUFFER_POOL,
        bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)))
        return -1;

    int result = bdk_pko_config_port(handle->pko_port, num_queues, 0, &handle->cmd_queue);
    if (result < 0)
        return result;
    handle->pko_queue = result;
    return 0;
}


/**
 * Initialize a port for use. All memory is allocated dynmically
 * as each port is added. This should only be called once for each
 * port. After this call the port needs to be enabled before use.
 *
 * @param iftype    Type of the port to init
 * @param interface Which interface for the port. This always starts at zero and
 *                  increments.
 * @param index     Specific index for this port on the interface.
 *
 * @return New port handle, or NULL on failure.
 */
static bdk_if_handle_t bdk_if_init_port(bdk_if_t iftype, int interface, int index)
{
    bdk_if_handle_t handle = calloc(1, sizeof(__bdk_if_port_t));
    if (!handle)
    {
        bdk_error("bdk_if_init_port() failed to allocate if handle\n");
        goto fail;
    }

    handle->iftype = iftype;
    handle->interface = interface;
    handle->index = index;
    handle->next = NULL;
    handle->pknd = -1;
    handle->ipd_port = -1;
    handle->pko_port = -1;
    handle->pko_queue = -1;
    handle->has_fcs = 0;

    if (__bdk_if_ops[iftype]->if_probe(handle))
    {
        bdk_error("if_probe indirect call failed\n");
        goto fail;
    }

    if (handle->ipd_port != -1)
    {
        static int next_free_pknd = 0;
        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
            handle->pknd = next_free_pknd++;
        else
            handle->pknd = handle->ipd_port;
        if (handle->ipd_port >= 0x1000)
            bdk_fatal("IPD port too large for mapping table\n");
        __bdk_if_ipd_map[handle->ipd_port] = handle;
    }

    if (__bdk_if_ops[iftype]->if_init(handle))
    {
        bdk_error("if_init indirect call failed\n");
        goto fail;
    }

    if (handle->ipd_port != -1)
    {
        if (__bdk_if_setup_ipd(handle))
        {
            bdk_error("__bdk_if_setup_ipd() failed\n");
            goto fail;
        }
        if (__bdk_if_setup_pko(handle))
        {
            bdk_error("__bdk_if_setup_pko() failed\n");
            goto fail;
        }
    }

    /* Put interfaces requiring polling in the poll list */
    if (__bdk_if_ops[handle->iftype]->if_receive)
    {
        handle->poll_next = __bdk_if_poll_head;
        __bdk_if_poll_head = handle;
    }

    if (__bdk_if_tail)
        __bdk_if_tail->next = handle;
    else
        __bdk_if_head = handle;
    __bdk_if_tail = handle;

    return handle;

fail:
    if (handle)
        free(handle);
    return NULL;
}


/**
 * Initialize all packet interfaces of all types for use. This
 * is the one call needed to get all interfaces configured. Enable
 * needs to be called on each handle before actual packets flow.
 *
 * @return Zero on success, negative on failure
 */
int bdk_if_init(void)
{
    /* Return without doing anything if we've already been called */
    if (__bdk_if_head)
        return 0;

    int result = 0;
    int num_packet_buffers = 1536;

    /* CN68XX pass 1.x needs some tweaks for 6.25Ghz. This
        will apply them if necessary */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS1_X))
        bdk_qlm_cn68xx_6250();

    /* Setup the FPA packet buffers */
    bdk_fpa_enable();
    bdk_fpa_fill_pool(BDK_FPA_PACKET_POOL, num_packet_buffers);

    /* Setup the SSO */
    if (__bdk_if_setup_sso())
        return -1;

    /* Disable tagwait FAU timeout. This needs to be done before anyone might
        start packet output using tags */
    bdk_iob0_fau_timeout_t fau_to;
    fau_to.u64 = 0;
    fau_to.s.tout_val = 0xfff;
    fau_to.s.tout_enb = 0;
    BDK_CSR_WRITE(BDK_IOB0_FAU_TIMEOUT, fau_to.u64);

    /* Tell L2 to give the IOB statically higher priority compared to the
        cores. This avoids conditions where IO blocks might be starved under
        very high L2 loads */
    bdk_l2c_ctl_t l2c_ctl;
    l2c_ctl.u64 = BDK_CSR_READ(BDK_L2C_CTL);
    l2c_ctl.s.rsp_arb_mode = 1;
    l2c_ctl.s.xmc_arb_mode = 0;
    BDK_CSR_WRITE(BDK_L2C_CTL, l2c_ctl.u64);

    /* Setup the common global IPD/PIP settings. Per port stuff will be
        done later */
    if (__bdk_if_setup_ipd_global())
        return -1;

    /* Make sure SMI/MDIO is enabled so we can query PHYs */
    int num_mdio = (OCTEON_IS_MODEL(OCTEON_CN68XX)) ? 4 : 2;
    for (int i=0; i<num_mdio; i++)
    {
        BDK_CSR_INIT(smix_en, BDK_SMIX_EN(i));
        if (!smix_en.s.en)
        {
            smix_en.s.en = 1;
            BDK_CSR_WRITE(BDK_SMIX_EN(i), smix_en.u64);
        }
    }

    bdk_pko_initialize();

    /* Loop through all types */
    for (bdk_if_t iftype=BDK_IF_SGMII; iftype<__BDK_IF_LAST; iftype++)
    {
        /* Loop through all interfaces for each type */
        int num_interfaces = bdk_if_num_interfaces(iftype);
        for (int interface=0; interface<num_interfaces; interface++)
        {
            /* Loop through all indexes for each interface */
            int num_index = bdk_if_num_ports(iftype, interface);
            for (int index=0; index<num_index; index++)
            {
                bdk_if_handle_t handle = bdk_if_init_port(iftype, interface, index);
                if (!handle)
                    result--;
            }
        }
    }

    bdk_pko_enable();

    /* Enable IPD */
    BDK_CSR_MODIFY(c, BDK_IPD_CTL_STATUS,
        c.s.ipd_en = 1);

    return result;
}


/**
 * Get the number of interfaces for the given type
 *
 * @param iftype Interface type
 *
 * @return Number of interface. Zero if unsupported.
 */
int bdk_if_num_interfaces(bdk_if_t iftype)
{
    return __bdk_if_ops[iftype]->if_num_interfaces();
}


/**
 * For a given interface, return the number of ports supported
 * by that interface.
 *
 * @param iftype    Interface type
 * @param interface Interface number
 *
 * @return Number of ports. Zero if unsupported.
 */
int bdk_if_num_ports(bdk_if_t iftype, int interface)
{
    return __bdk_if_ops[iftype]->if_num_ports(interface);
}


/**
 * Get the next valid port handle after the supplied handle. Returns
 * the first port handle when argument is NULL. This meant to make it
 * easy to write loops that iterate over ports.
 *
 * @param handle Port to get handle after. NULL means get the first port.
 *
 * @return Next port handle or NULL when the end is reached.
 */
bdk_if_handle_t bdk_if_next_port(bdk_if_handle_t handle)
{
    if (handle)
        return handle->next;
    else
        return __bdk_if_head;
}


/**
 * Enable the given port for packet IO
 *
 * @param handle Handle to enable
 *
 * @return Zero on sucess, negative on failure
 */
int bdk_if_enable(bdk_if_handle_t handle)
{
    int status = __bdk_if_ops[handle->iftype]->if_enable(handle);
    if (status == 0)
        bdk_if_link_autoconf(handle);
    return status;
}


/**
 * Disable the given port for packet IO
 *
 * @param handle Handle to disable
 *
 * @return Zero on sucess, negative on failure
 */
int bdk_if_disable(bdk_if_handle_t handle)
{
    return __bdk_if_ops[handle->iftype]->if_disable(handle);
}


/**
 * Return the human readable name of a handle
 *
 * @param handle Handle to name
 *
 * @return Static shared buffer for the name
 */
const char *bdk_if_name(bdk_if_handle_t handle)
{
    static char buffer[16];
    snprintf(buffer, sizeof(buffer), "%s%d%d", __bdk_if_ops[handle->iftype]->name, handle->interface, handle->index);
    buffer[sizeof(buffer)-1] = 0;
    return buffer;
}


/**
 * Get the link status for the port
 *
 * @param handle Handle of port
 *
 * @return Link status
 */
bdk_if_link_t bdk_if_link_get(bdk_if_handle_t handle)
{
    return __bdk_if_ops[handle->iftype]->if_link_get(handle);
}


/**
 * Get the link status for the port and configure it for that speed
 *
 * @param handle Handle of port
 *
 * @return Link status
 */
bdk_if_link_t bdk_if_link_autoconf(bdk_if_handle_t handle)
{
    bdk_if_link_t link_info = bdk_if_link_get(handle);

    if (link_info.u64 != handle->link_info.u64)
    {
        handle->link_info = link_info;
        if (__bdk_if_ops[handle->iftype]->if_link_set)
            __bdk_if_ops[handle->iftype]->if_link_set(handle, handle->link_info);
    }
    return handle->link_info;
}


/**
 * Update a statistic that has a limited bit with. The hardware stats counters
 * add up all packets but overflow with limited precision. This function checks
 * for overflow and returns the correct sum.
 *
 * @param new_value New hardware value, limited to bit_size precision
 * @param old_value Old value return by this function. This is a full 64 bit value.
 * @param bit_size  The number of bits in the hardware counter
 *
 * @return New counter value, accounting for overflow
 */
static uint64_t update_stat_with_overflow(uint64_t new_value, uint64_t old_value, int bit_size)
{
    uint64_t mask = bdk_build_mask(bit_size);
    uint64_t tmp = old_value & bdk_build_mask(bit_size);

    /* On overflow we need to add 1 in the upper bits */
    if (tmp > new_value)
        new_value += 1ull<<bit_size;

    /* Add in the upper bits from the old value */
    new_value += old_value & ~mask;

    return new_value;
}


/**
 * Get the interface RX and TX counters.
 *
 * @param handle Handle of port
 *
 * @return Statistics
 */
const bdk_if_stats_t *bdk_if_get_stats(bdk_if_handle_t handle)
{
    if (__bdk_if_ops[handle->iftype]->if_get_stats)
        return __bdk_if_ops[handle->iftype]->if_get_stats(handle);

    if (USE_SOFTWARE_COUNTERS || bdk_is_simulation())
        return &handle->stats;

    int bytes_off_tx;
    int bytes_off_rx;

    switch (handle->iftype)
    {
        case BDK_IF_SRIO:
            /* Subtract SRIO header */
            bytes_off_tx = -(int)sizeof(bdk_srio_tx_message_header_t);
            bytes_off_rx = -(int)sizeof(bdk_srio_rx_message_header_t);
            break;
        default:
            /* Account for TX lack of FCS for most ports */
            bytes_off_tx = handle->has_fcs ? 4 : 0;
            bytes_off_rx = 0;
            break;
    }

    bdk_pip_stat0_x_t stat0;
    bdk_pip_stat1_x_t stat1;
    bdk_pip_stat2_x_t stat2;

    if (!OCTEON_IS_MODEL(OCTEON_CN68XX) && (handle->pknd >= 40))
    {
        stat0.u64 = BDK_CSR_READ(BDK_PIP_XSTAT0_PRTX(handle->pknd));
        stat1.u64 = BDK_CSR_READ(BDK_PIP_XSTAT1_PRTX(handle->pknd));
        stat2.u64 = BDK_CSR_READ(BDK_PIP_XSTAT2_PRTX(handle->pknd));
    }
    else
    {
        stat0.u64 = BDK_CSR_READ(BDK_PIP_STAT0_X(handle->pknd));
        stat1.u64 = BDK_CSR_READ(BDK_PIP_STAT1_X(handle->pknd));
        stat2.u64 = BDK_CSR_READ(BDK_PIP_STAT2_X(handle->pknd));
    }
    BDK_CSR_INIT(pip_stat_inb_errsx, BDK_PIP_STAT_INB_ERRS_PKNDX(handle->pknd));

    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_octets = update_stat_with_overflow(stat0.s.drp_octs, handle->stats.rx.dropped_octets, 32);
    handle->stats.rx.dropped_packets = update_stat_with_overflow(stat0.s.drp_pkts, handle->stats.rx.dropped_packets, 32);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;

    handle->stats.rx.octets -= handle->stats.rx.packets * bytes_off_rx;
    handle->stats.rx.octets = update_stat_with_overflow(stat1.s.octs, handle->stats.rx.octets, 48);
    handle->stats.rx.packets = update_stat_with_overflow(stat2.s.pkts, handle->stats.rx.packets, 32);
    handle->stats.rx.errors = update_stat_with_overflow(pip_stat_inb_errsx.s.errs, handle->stats.rx.errors, 16);
    handle->stats.rx.octets += handle->stats.rx.packets * bytes_off_rx;

    bdk_pko_reg_read_idx_t pko_reg_read_idx;
    pko_reg_read_idx.u64 = 0;
    pko_reg_read_idx.s.index = handle->pko_port;
    BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, pko_reg_read_idx.u64);
    BDK_CSR_INIT(pko_mem_count0, BDK_PKO_MEM_COUNT0);
    BDK_CSR_INIT(pko_mem_count1, BDK_PKO_MEM_COUNT1);

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = update_stat_with_overflow(pko_mem_count1.s.count, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = update_stat_with_overflow(pko_mem_count0.s.count, handle->stats.tx.packets, 32);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    return &handle->stats;
}


/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
int bdk_if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    if (bdk_unlikely(__bdk_if_ops[handle->iftype]->if_transmit))
        return __bdk_if_ops[handle->iftype]->if_transmit(handle, packet);

    if (bdk_unlikely(packet->segments >= 64))
    {
        bdk_error("PKO can't transmit packets with more than 63 segments\n");
        return -1;
    }

    bdk_pko_command_word0_t pko_command;
    pko_command.u64 = 0;
    pko_command.s.dontfree = packet->packet.s.i;
    pko_command.s.ignore_i = 1;
    pko_command.s.segs = packet->segments;
    pko_command.s.total_bytes = packet->length;
    bdk_buf_ptr_t buf = packet->packet;
    buf.s.i = 0;

    bdk_cmd_queue_result_t result = bdk_cmd_queue_write2(&handle->cmd_queue, 1, pko_command.u64, buf.u64);

    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
    {
        bdk_pko_doorbell(handle->pko_port, handle->pko_queue, 2);
        /* Updates the statistics in software if need to. The simulator
            doesn't implement the hardware counters */
        if (USE_SOFTWARE_COUNTERS || bdk_is_simulation())
        {
            int octets = pko_command.s.total_bytes;
            if (handle->has_fcs)
                octets += 4;
            bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.octets, octets);
            bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.packets, 1);
        }
    }
    return result;
}


/**
 * Receive a packet from any enabled interface.
 *
 * @param packet Receives the packet. Unmodified if no packet is found.
 *
 * @return Zero on getting a packet, positive on no packets available,
 *         negative on failure.
 */
int bdk_if_receive(bdk_if_packet_t *packet)
{
    /* Get work without waiting */
    uint64_t raw_work = bdk_read64_uint64(0x8001600000000000ull);
    if ((raw_work>>63) == 0)
    {
        bdk_wqe_t *wqe = (bdk_wqe_t*)bdk_phys_to_ptr(raw_work);

        /* Get the IPD port number */
        int ipd_port = wqe->word2.s.port;
        if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
            ipd_port = wqe->word1.v1.ipprt;

        packet->if_handle = __bdk_if_ipd_map[ipd_port];
        packet->length = wqe->word1.s.len;
        if (wqe->word2.s.re)
            packet->rx_error = wqe->word2.s.opcode;
        else
            packet->rx_error = 0;

        if (wqe->word2.s.bufs == 0)
        {
            packet->segments = 1;
            packet->packet.u64 = 0;
            packet->packet.s.back = 0;
            packet->packet.s.pool = BDK_FPA_PACKET_POOL;
            packet->packet.s.size = 128; // FIXME packet size
            packet->packet.s.addr = bdk_ptr_to_phys(wqe->packet_data);
            if (bdk_likely(!wqe->word2.s.ni))
            {
                packet->packet.s.addr += (4<<3) - wqe->word2.ip.ip_offset;
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

        /* Updates the statistics in software if need to. The simulator
            doesn't implement the hardware counters */
        if (USE_SOFTWARE_COUNTERS || bdk_is_simulation())
        {
            int octets = wqe->word1.s.len;
            bdk_atomic_add64_nosync((int64_t*)&packet->if_handle->stats.rx.octets, octets);
            bdk_atomic_add64_nosync((int64_t*)&packet->if_handle->stats.rx.packets, 1);
            if (packet->rx_error)
                bdk_atomic_add64_nosync((int64_t*)&packet->if_handle->stats.rx.errors, 1);
        }
        return 0;
    }

    for (bdk_if_handle_t handle=__bdk_if_poll_head; handle!=NULL; handle=handle->poll_next)
    {
        if (__bdk_if_ops[handle->iftype]->if_receive(handle, packet) == 0)
            return 0;
    }

    return 1;
}


/**
 * Allocate a packet with buffers for the supplied amount of data
 *
 * @param packet Packet to get buffers for
 * @param length Length of the final packet in bytes
 *
 * @return Zero on success, negative on failure.
 */
int bdk_if_alloc(bdk_if_packet_t *packet, int length)
{
    const int FPA_SIZE = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL);
    bdk_buf_ptr_t *buffer_ptr = &packet->packet;

    /* Start off with an empty packet */
    packet->length = 0;
    packet->segments = 0;

    /* Add buffers while the packet is less that the needed length */
    while (packet->length < length)
    {
        void *buffer = bdk_fpa_alloc(BDK_FPA_PACKET_POOL);
        if (!buffer)
        {
            /* Free all buffers allocates so far */
            bdk_if_free(packet);
            return -1;
        }
        /* Fill in the packet link pointer */
        buffer_ptr->u64 = 0;
        buffer_ptr->s.pool = BDK_FPA_PACKET_POOL;
        buffer_ptr->s.size = FPA_SIZE - 8;
        buffer_ptr->s.addr = bdk_ptr_to_phys(buffer) + 8;
        packet->length += buffer_ptr->s.size;
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
 * Read data from a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to read from.
 * @param location Location to read
 * @param length   Length of data to read
 * @param data     Buffer to receive the data
 */
void bdk_if_packet_read(bdk_if_packet_t *packet, int location, int length, void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to read past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.s.size)
    {
        location -= buffer_ptr.s.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }

    const uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    uint8_t *out_data = data;
    while (length > 0)
    {
        *out_data = ptr[location];
        out_data++;
        location++;
        length--;
        if (location >= buffer_ptr.s.size)
        {
            location -= buffer_ptr.s.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
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
void bdk_if_packet_write(bdk_if_packet_t *packet, int location, int length, const void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to write past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.s.size)
    {
        location -= buffer_ptr.s.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }

    uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    const uint8_t *in_data = data;
    while (length > 0)
    {
        ptr[location] = *in_data;
        in_data++;
        location++;
        length--;
        if (location >= buffer_ptr.s.size)
        {
            location -= buffer_ptr.s.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
        }
    }
}


/**
 * Free a packet back to the FPA pools
 *
 * @param packet Packet to free. Only the data is freed. The bdk_if_packet_t structure
 *               is not freed.
 */
void bdk_if_free(bdk_if_packet_t *packet)
{
    int number_buffers = packet->segments;
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    BDK_SYNCW;
    while (number_buffers--)
    {
        /* Remember the back pointer is in cache lines, not 64bit words */
        uint64_t start_of_buffer = ((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
        /* Read pointer to next buffer before we free the current buffer. */
        bdk_buf_ptr_t next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
        __bdk_fpa_raw_free(start_of_buffer, buffer_ptr.s.pool, 0);
        buffer_ptr = next_buffer_ptr;
    }
}


/**
 * Get the GMX block number for ports that use GMX
 *
 * @param handle Port handle
 *
 * @return GMX block number
 */
int __bdk_if_get_gmx_block(bdk_if_handle_t handle)
{
    return handle->interface;
}


/**
 * Get the GMX index number for ports that use GMX
 *
 * @param handle Port handle
 *
 * @return GMX index number
 */
int __bdk_if_get_gmx_index(bdk_if_handle_t handle)
{
    return handle->index;
}

