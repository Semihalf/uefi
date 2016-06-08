#include <bdk.h>

/* Network support for LBK hardware, the internal loopback only devices */

/**
 * Determine how many LBK interfaces are supported on this chip. Each interface
 * can support multiple channels.
 *
 * @param node   Node to query
 *
 * @return Number of LBK interfaces, zero if not supported
 */
static int if_num_interfaces(bdk_node_t node)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
    {
        /*  LBK 0 connects PKO to PKI
            LBK 1 connects NIC to PKI
            LBK 2 connects PKO to NIC
            LBK 3 connects NIC to NIC */
        return 4;
    }
    else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
    {
        /* LBK 0 connects NIC to NIC */
        return 1;
    }
    else
        return 0; /* No LBK interfaces */
}

/**
 * Return the number of channels to support for each LBK interface. LBK can
 * support many channels, so we normally return less than the hardware max.
 *
 * @param node      Node to query
 * @param interface LBK interface to query
 *
 * @return Number of channels. Zero means skip this interface
 */
static int if_num_ports(bdk_node_t node, int interface)
{
    int desired = 4; /* Could be up to 64, but 4 seems enough for testing */
    BDK_CSR_INIT(lbkx_const, node, BDK_LBKX_CONST(interface));
    if (desired > lbkx_const.s.chan)
        desired = lbkx_const.s.chan;
    return desired;
}

/**
 * Probe performs initial LBK setup before and packet movement is setup
 *
 * @param handle LBK channel to probe
 *
 * @return Zero on success, negative on failure
 */
static int if_probe(bdk_if_handle_t handle)
{
    /* Set the port name */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "LBK%d.%d", handle->interface, handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.LBK%d.%d", handle->node, handle->interface, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;

    /* Read info about LBK */
    BDK_CSR_INIT(lbkx_const, handle->node, BDK_LBKX_CONST(handle->interface));

    /* FIXME: Do something with LBK FIFO size */
    int fifo_size = lbkx_const.s.buf_size;
    if (fifo_size == 0)
        bdk_fatal("%s: FIFO size is zero\n", handle->name);
    else if (0 == handle->index)
        printf("LBKX_CONST(%d) : chan %d dest %d src %d buf_size 0x%x\n",
               handle->interface, lbkx_const.s.chan, lbkx_const.s.dest, lbkx_const.s.src, lbkx_const.s.buf_size);

    /* Setup input path */
    switch (lbkx_const.s.src)
    {
        case BDK_LBK_CONNECT_E_NICX(0):
            /* Tell bdk-if we are going ot use NIC. This value gets overwritten
               with the correct VNIC */
            handle->nic_id = 1;
            break;
        case BDK_LBK_CONNECT_E_PKOX(0):
            /* Tell bdk-if we are going ot use PKO. This value gets overwritten
               with the correct PKO queue */
            handle->pko_queue = 1;
            break;
        default:
            bdk_error("%s: Invalid input enumeration\n", handle->name);
            return -1;
    }

    /* Setup output path */
    switch (lbkx_const.s.dest)
    {
        case BDK_LBK_CONNECT_E_NICX(0):
            /* Tell bdk-if we are going ot use NIC. This value gets overwritten
               with the correct VNIC */
            handle->nic_id = 1;
            break;
        case BDK_LBK_CONNECT_E_PKIX(0):
            /* Use PKI_CHAN_E channel numbers 0 - 63 */
            handle->pki_channel = BDK_PKI_CHAN_E_LBKX_CHX(handle->interface, handle->index);
            break;
        default:
            bdk_error("%s: Invalid output enumeration\n", handle->name);
            return -1;
    }
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    /* Record the PKND for this port */
    BDK_CSR_MODIFY(c, handle->node, BDK_LBKX_CHX_PKIND(handle->interface, handle->index),
        c.s.pkind = handle->pknd);

    if (handle->nic_id)
    {
        BDK_CSR_INIT(lbkx_const, handle->node, BDK_LBKX_CONST(handle->interface));
        if (CAVIUM_IS_MODEL(CAVIUM_CN81XX)) {
            /* Errata LBK-28315 LBKX_CONST[buf_size] is wrong. The value is suppose
               to be 0x3000, not 0x1000 */
            if (lbkx_const.s.buf_size == 0x1000) {
                lbkx_const.s.buf_size = 0x3000;
            }
        }
        if (bdk_nic_port_init(handle, BDK_NIC_TYPE_LBK, lbkx_const.s.buf_size))
            return -1;
    }

    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    return 0; /* LBK is always enabled */
}

static int if_disable(bdk_if_handle_t handle)
{
    return 0; /* LBK is always enabled, no disable */
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    /* Report 10Gbps as a made up speed */
    bdk_if_link_t result;
    result.u64 = 0;
    result.s.speed = 10000;
    result.s.full_duplex = 1;
    result.s.up = 1;

    return result;
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    return 0; /* Device is always loopback */
}

/**
 * Get the interface RX and TX counters.
 *
 * @param handle Handle of port
 *
 * @return Statistics
 */
static const bdk_if_stats_t *if_get_stats(bdk_if_handle_t handle)
{
    if (handle->pki_channel == -1)
        bdk_nic_fill_rx_stats(handle);
    else
        bdk_pki_fill_rx_stats(handle);

    if (handle->pko_queue == -1)
        bdk_nic_fill_tx_stats(handle);
    else
        bdk_pko_fill_tx_stats(handle);

    return &handle->stats;
}

static int if_transmit(bdk_if_handle_t handle, const bdk_if_packet_t *packet)
{
    if (handle->pko_queue == -1)
        return bdk_nic_transmit(handle, packet);
    else
        return bdk_pko_transmit(handle, packet);
}

static int if_get_queue_depth(bdk_if_handle_t handle)
{
    if (handle->pko_queue == -1)
        return bdk_nic_get_queue_depth(handle);
    else
        return bdk_pko_get_queue_depth(handle);
}

__bdk_if_ops_t __bdk_if_ops_lbk = {
    .priv_size = 0,
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_get_stats = if_get_stats,
    .if_transmit = if_transmit,
    .if_loopback = if_loopback,
    .if_get_queue_depth = if_get_queue_depth,
};

