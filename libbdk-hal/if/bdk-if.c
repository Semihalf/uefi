#include <bdk.h>

extern __bdk_if_ops_t __bdk_if_ops_sgmii;
extern __bdk_if_ops_t __bdk_if_ops_xaui;
extern __bdk_if_ops_t __bdk_if_ops_dpi;
extern __bdk_if_ops_t __bdk_if_ops_loop;
extern __bdk_if_ops_t __bdk_if_ops_srio;
extern __bdk_if_ops_t __bdk_if_ops_mgmt;

static const __bdk_if_ops_t *__bdk_if_ops[__BDK_IF_LAST] = {
    [BDK_IF_SGMII] = &__bdk_if_ops_sgmii,
    [BDK_IF_XAUI] = &__bdk_if_ops_xaui,
    [BDK_IF_DPI] = &__bdk_if_ops_dpi,
    [BDK_IF_LOOP] = &__bdk_if_ops_loop,
    [BDK_IF_SRIO] = &__bdk_if_ops_srio,
    [BDK_IF_MGMT] = &__bdk_if_ops_mgmt,
};

static __bdk_if_port_t *__bdk_if_head;
static __bdk_if_port_t *__bdk_if_tail;

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
    static int next_free_queue = 0;
    int num_queues = 1;

    handle->pko_queue = next_free_queue;
    handle->pko_port = handle->pknd;
    next_free_queue += num_queues;

    return bdk_pko_config_port(handle->pko_port, handle->pko_queue, num_queues, NULL);
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
    bdk_if_handle_t handle = calloc(1, sizeof(bdk_if_handle_t));
    if (!handle)
        goto fail;

    handle->iftype = iftype;
    handle->interface = interface;
    handle->index = index;
    handle->pknd = 0; // FIXME
    handle->next = NULL;

    if (handle->pknd != -1)
    {
        if (__bdk_if_setup_ipd(handle))
            goto fail;
        if (__bdk_if_setup_pko(handle))
            goto fail;
    }

    if (__bdk_if_ops[iftype]->if_init(handle))
        goto fail;

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

    /* Set the number of packet and WQE entries to be 16 less than the
        number of SSO entries. This way we never spill to ram */
    int num_packet_buffers = bdk_sso_get_num_entries() - 16;
    bdk_fpa_enable();
    bdk_fpa_fill_pool(BDK_FPA_PACKET_POOL, num_packet_buffers);
    bdk_fpa_fill_pool(BDK_FPA_WQE_POOL, num_packet_buffers);
    bdk_fpa_fill_pool(BDK_FPA_OUTPUT_BUFFER_POOL, BDK_PKO_MAX_OUTPUT_QUEUES*2);

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
                    BDK_IPD_OPC_MODE_STF,
                    1);
    BDK_CSR_WRITE(BDK_PIP_IP_OFFSET, 4);

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


bdk_if_handle_t bdk_if_get_handle_rx(int ipd_port)
{
    return NULL;
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
    return __bdk_if_ops[handle->iftype]->if_enable(handle);
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
    return __bdk_if_ops[handle->iftype]->if_link_autoconf(handle);
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
    return __bdk_if_ops[handle->iftype]->if_transmit(handle, packet);
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
    return -1;
}


/**
 * Free a packet back to the FPA pools
 *
 * @param packet Packet to free. Only the data is freed. The bdk_if_packet_t structure
 *               is not freed.
 */
void bdk_if_free(bdk_if_packet_t *packet)
{
}


/**
 * Common transmit routine for ports connected to PKO
 *
 * @param handle Handle to port
 * @param packet Packet to transmit
 *
 * @return Zero on success, negative on failure.
 */
int __bdk_if_transmit_pko(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    bdk_pko_command_word0_t pko_command;
    pko_command.u64 = 0;
    pko_command.s.segs = packet->segments;
    pko_command.s.total_bytes = packet->length;
    bdk_pko_send_packet_prepare(handle->pko_port, handle->pko_queue, BDK_PKO_LOCK_CMD_QUEUE);
    return bdk_pko_send_packet_finish(handle->pko_port, handle->pko_queue, pko_command, packet->packet, BDK_PKO_LOCK_CMD_QUEUE);
}


/**
 * Common receive routine for ports connected to PIP/IPD
 *
 * @param packet Packet received from PIP/IPD
 *
 * @return Zero on sucess, negative on failure.
 */
int __bdk_if_receive_sso(bdk_if_packet_t *packet)
{
    return -1;
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

