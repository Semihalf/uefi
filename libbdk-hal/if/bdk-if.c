#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

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


/**
 * One time init of the SSO
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_if_setup_sso(void)
{
    const int SSO_RWQ_SIZE = 512;
    const int SSO_RWQ_COUNT = 8 + 128;

    /* SSO in CN63XX doesn't need any setup */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 0;

    /* Set work timeout to 16k cycles */
    BDK_CSR_MODIFY(c, BDK_SSO_NW_TIM,
        c.s.nw_tim = 16);

    /* Initialize the SSO memory queues */
    for (int i=0; i<8; i++)
    {
        void *buffer = memalign(BDK_CACHE_LINE_SIZE, SSO_RWQ_SIZE);
        if (!buffer)
        {
            bdk_error("Failed to allocate buffer for SSO queue %d\n", i);
            return -1;
        }
        BDK_CSR_WRITE(BDK_SSO_RWQ_HEAD_PTRX(i), bdk_ptr_to_phys(buffer));
        BDK_CSR_WRITE(BDK_SSO_RWQ_TAIL_PTRX(i), bdk_ptr_to_phys(buffer));
    }

    /* Initialize the RWQ list */
    for (int i=0; i<SSO_RWQ_COUNT; i++)
    {
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_SSO_RWQ_PSH_FPTR, full, ==, 0, 1000))
        {
            bdk_error("BDK_SSO_RWQ_PSH_FPTR[FULL] is stuck\n");
            return -1;
        }

        void *buffer = memalign(BDK_CACHE_LINE_SIZE, SSO_RWQ_SIZE);
        if (!buffer)
        {
            bdk_error("Failed to allocate buffer for SSO RWQ\n");
            return -1;
        }
        BDK_CSR_WRITE(BDK_SSO_RWQ_PSH_FPTR, bdk_ptr_to_phys(buffer));
    }

    /* Enable the SSO RWI/RWO operations */
    BDK_CSR_MODIFY(c, BDK_SSO_CFG,
        c.s.rwen = 1);
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

    int result = bdk_pko_config_port(handle->pko_port, num_queues, 0);
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

    if (__bdk_if_ops[iftype]->if_init(handle))
    {
        bdk_error("if_init indirect call failed\n");
        goto fail;
    }

    if (handle->ipd_port != -1)
    {
        static int next_free_pknd = 0;
        if (OCTEON_IS_MODEL(OCTEON_CN63XX))
            handle->pknd = handle->ipd_port;
        else
            handle->pknd = next_free_pknd++;
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

    printf("%s: pknd=%d, ipd_port=%d, pko_port=%d, pko_queue=%d\n",
            bdk_if_name(handle), handle->pknd,
            handle->ipd_port, handle->pko_port, handle->pko_queue);

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
    int result = 0;
    int num_packet_buffers = 256;

    /* Setup the FPA, packet and WQE buffers */
    bdk_fpa_enable();
    bdk_fpa_fill_pool(BDK_FPA_PACKET_POOL, num_packet_buffers);
    bdk_fpa_fill_pool(BDK_FPA_WQE_POOL, num_packet_buffers);

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

    /* Setup the global packet input options */
    int first_skip = bdk_config_get(BDK_CONFIG_FIRST_MBUFF_SKIP);
    int other_skip = bdk_config_get(BDK_CONFIG_NOT_FIRST_MBUFF_SKIP);
    bdk_ipd_config(bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL)/8,
                    first_skip/8, other_skip/8,
                    (first_skip+8) / 128, /* The +8 is to account for the next ptr */
                    (other_skip+8) / 128, /* The +8 is to account for the next ptr */
                    BDK_FPA_WQE_POOL,
                    BDK_IPD_OPC_MODE_STF, /* All blocks into L2 */
                    1); /* Enable backpressure */
    BDK_CSR_WRITE(BDK_PIP_IP_OFFSET, 4); /* Needed to support dynamic short */

    /* Make sure SMI/MDIO is enabled so we can query PHYs */
    for (int i=0; i<2; i++)
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
    bdk_ipd_enable();

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

    bdk_pip_port_status_t pip;
    bdk_pip_get_port_status(handle->pknd, 1, &pip);
    handle->stats.rx.dropped_octets += pip.dropped_octets;
    handle->stats.rx.dropped_packets += pip.dropped_packets;
    handle->stats.rx.octets += pip.octets;
    handle->stats.rx.packets += pip.packets;
    handle->stats.rx.errors += pip.inb_errors;

    /* Add fake etherent CRC to loop ports */
    if (handle->iftype == BDK_IF_LOOP)
    {
        handle->stats.rx.dropped_octets += pip.dropped_packets * 4;
        handle->stats.rx.octets += pip.packets * 4;
    }

    bdk_pko_reg_read_idx_t pko_reg_read_idx;
    bdk_pko_mem_count0_t pko_mem_count0;
    bdk_pko_mem_count1_t pko_mem_count1;

    pko_reg_read_idx.u64 = 0;
    pko_reg_read_idx.s.index = handle->pko_port;
    BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, pko_reg_read_idx.u64);

    pko_mem_count0.u64 = BDK_CSR_READ(BDK_PKO_MEM_COUNT0);
    uint64_t tx_packets = pko_mem_count0.s.count;
    pko_mem_count0.s.count = handle->pko_port;
    BDK_CSR_WRITE(BDK_PKO_MEM_COUNT0, pko_mem_count0.u64);

    pko_mem_count1.u64 = BDK_CSR_READ(BDK_PKO_MEM_COUNT1);
    uint64_t tx_octets = pko_mem_count1.s.count;
    pko_mem_count1.s.count = handle->pko_port;
    BDK_CSR_WRITE(BDK_PKO_MEM_COUNT1, pko_mem_count1.u64);

    handle->stats.tx.packets += tx_packets;
    handle->stats.tx.octets += tx_octets;

    /* Add the etherent CRC to the TX octets */
    handle->stats.tx.octets += tx_packets * 4;

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
    if (__bdk_if_ops[handle->iftype]->if_transmit)
        return __bdk_if_ops[handle->iftype]->if_transmit(handle, packet);

    bdk_pko_command_word0_t pko_command;
    pko_command.u64 = 0;
    pko_command.s.segs = packet->segments;
    pko_command.s.total_bytes = packet->length;

    int result = bdk_pko_send_packet_finish(handle->pko_port, handle->pko_queue, pko_command, packet->packet, BDK_PKO_LOCK_CMD_QUEUE);

    /* Create some simple stats in the simulator for testing */
    if (bdk_is_simulation() && (result==0))
    {
        handle->stats.tx.octets += packet->length;
        handle->stats.tx.packets++;
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
        if (OCTEON_IS_MODEL(OCTEON_CN63XX))
            ipd_port = wqe->word1.v1.ipprt;

        /* FIXME: This is a slow way of finding the IF handle */
        __bdk_if_port_t *handle = __bdk_if_head;
        while (handle)
        {
            if (handle->ipd_port == ipd_port)
                break;
            handle = handle->next;
        }

        packet->if_handle = handle;
        packet->length = wqe->word1.s.len;
        if (wqe->word2.s.re)
            packet->rx_error = wqe->word2.s.opcode;
        else
            packet->rx_error = 0;

        if (wqe->word2.s.bufs == 0)
        {
            packet->segments = 1;
            packet->packet.u64 = 0;
            packet->packet.s.pool = BDK_FPA_WQE_POOL;
            packet->packet.s.size = 128;
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
            bdk_fpa_free(wqe, BDK_FPA_WQE_POOL, 0);
        }

        if (bdk_unlikely(!packet->if_handle))
        {
            bdk_error("Unable to find IF for ipd_port %d\n", ipd_port);
            bdk_if_free(packet);
            return -1;
        }

        /* Create some simple stats in the simulator for testing */
        if (bdk_is_simulation())
        {
            packet->if_handle->stats.rx.octets += packet->length + 4; /* Add CRC */
            packet->if_handle->stats.rx.packets++;
        }
        return 0;
    }

    for (bdk_if_handle_t handle=bdk_if_next_port(NULL); handle!=NULL; handle=bdk_if_next_port(handle))
    {
        if (__bdk_if_ops[handle->iftype]->if_receive)
        {
            if (__bdk_if_ops[handle->iftype]->if_receive(handle, packet) == 0)
                return 0;
        }
    }

    return 1;
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
    while (number_buffers--)
    {
        /* Remember the back pointer is in cache lines, not 64bit words */
        uint64_t start_of_buffer = ((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
        /* Read pointer to next buffer before we free the current buffer. */
        bdk_buf_ptr_t next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
        bdk_fpa_free(bdk_phys_to_ptr(start_of_buffer), buffer_ptr.s.pool, 0);
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

