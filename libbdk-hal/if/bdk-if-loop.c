#include <bdk.h>

/* LOOP in thunder (CN83XX specifically) is four independent
   looping device that each support up to 64 different channels.
   - LOOP 0 connects PKO to PKI
   - LOOP 1 connects NIC to PKI
   - LOOP 2 connects PKO to NIC
   - LOOP 3 connects NIC to NIC
   */

static int if_num_interfaces(bdk_node_t node)
{
    /* We only support LOOP block 0, PKO to PKI right now */
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 1;
    else
        return 0;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    /* Could be up to 64, but 4 seems enough for testing */
    return 4;
}

static int if_probe(bdk_if_handle_t handle)
{
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "LOOP%d", handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.LOOP%d", handle->node, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;

    /* Use PKI_CHAN_E channel numbers 0 - 63 */
    handle->pki_channel = BDK_PKI_CHAN_E_LOOPBACK_CHX(handle->index);
    /* Tell bdk-if we are going ot use PKO. This value gets overwritten
       with the correct PKO queue */
    handle->pko_queue = 1;

    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    /* Record the PKND for this port. Use the same PKND for all 4 loop
       paths (see comment at top of file) */
    for (int loop = 0; loop < 4; loop++)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_LBKX_CHX_PKIND(loop, handle->index),
            c.s.pkind = handle->pknd);
    }
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    return 0;
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
    /* Device is always loopback */
    return 0;
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
    bdk_pki_fill_rx_stats(handle);
    bdk_pko_fill_tx_stats(handle);
    return &handle->stats;
}

__bdk_if_ops_t __bdk_if_ops_loop = {
    .priv_size = 0,
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_get_stats = if_get_stats,
    .if_transmit = bdk_pko_transmit,
    .if_loopback = if_loopback,
    .if_get_queue_depth = bdk_pko_get_queue_depth,
};

