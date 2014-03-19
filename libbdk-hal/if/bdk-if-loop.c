#include <bdk.h>

static int if_num_interfaces(bdk_node_t node)
{
    extern __bdk_if_ops_t __bdk_if_ops_loop;
    if (!OCTEON_IS_MODEL(OCTEON_CN78XX))
        __bdk_if_ops_loop.if_get_stats = NULL;
    return 1;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return 4;
    else
        return 4;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Change name to be "LOOP" with a single number */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "LOOP%d", handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.LOOP%d", handle->node, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        /* Use PKI_CHAN_E channel numbers 0 - 63 */
        handle->ipd_port = handle->index;
    }
    else
    {
        /* Use IPD ports 36 - 39 */
        handle->ipd_port = 36 + handle->index;
    }

    return 0;
}

static int if_init_cn78xx(bdk_if_handle_t handle)
{
    const int MAC_NUMBER = 0x0; /* Constant from cn78xx */
    if (handle->index == 0)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_MACX_CFG(MAC_NUMBER),
            c.s.fcs_ena = 0; /* No FCS */
            c.s.fcs_sop_off = 0; /* No FCS offset */
            c.s.skid_max_cnt = 2); /* All credits to one MAC */
    }
    /* Record the PKND for this port */
    BDK_CSR_MODIFY(c, handle->node, BDK_LBK_CHX_PKIND(handle->index),
        c.s.pkind = handle->pknd);
    return 0;
}

static int if_init_cn6xxx(bdk_if_handle_t handle)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0);
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return if_init_cn78xx(handle);
    else
        return if_init_cn6xxx(handle);
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
    bdk_if_link_t result;
    result.u64 = 0;
    result.s.speed = 10000;
    result.s.full_duplex = 1;
    result.s.up = 1;

    return result;
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
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
    if (bdk_unlikely(bdk_is_simulation()))
        return &handle->stats;

    /* Account for TX lack of FCS for most ports */
    const int bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
    const int bytes_off_rx = 0;

    /* Read the RX statistics from PKI */
    BDK_CSR_INIT(rx_packets, handle->node, BDK_PKI_STATX_STAT0(handle->pknd));
    BDK_CSR_INIT(rx_octets, handle->node, BDK_PKI_STATX_STAT1(handle->pknd));
    BDK_CSR_INIT(rx_dropped_packets, handle->node, BDK_PKI_STATX_STAT3(handle->pknd));
    BDK_CSR_INIT(rx_dropped_octets, handle->node, BDK_PKI_STATX_STAT4(handle->pknd));
    BDK_CSR_INIT(rx_errors, handle->node, BDK_PKI_STATX_STAT7(handle->pknd));

    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_octets = bdk_update_stat_with_overflow(
        rx_dropped_octets.s.drp_octs, handle->stats.rx.dropped_octets, 48);
    handle->stats.rx.dropped_packets = bdk_update_stat_with_overflow(
        rx_dropped_packets.s.drp_pkts, handle->stats.rx.dropped_packets, 48);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;

    handle->stats.rx.octets -= handle->stats.rx.packets * bytes_off_rx;
    handle->stats.rx.octets = bdk_update_stat_with_overflow(
        rx_octets.s.octs, handle->stats.rx.octets, 48);
    handle->stats.rx.packets = bdk_update_stat_with_overflow(
        rx_packets.s.pkts, handle->stats.rx.packets, 48);
    handle->stats.rx.errors = bdk_update_stat_with_overflow(
        rx_errors.s.fcs, handle->stats.rx.errors, 48);
    handle->stats.rx.octets += handle->stats.rx.packets * bytes_off_rx;

    /* Read the RX statistics from PKO */
    BDK_CSR_INIT(tx_octets, handle->node, BDK_PKO_DQX_BYTES(handle->pko_queue));
    BDK_CSR_INIT(tx_packets, handle->node, BDK_PKO_DQX_PACKETS(handle->pko_queue));

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = bdk_update_stat_with_overflow(tx_octets.s.count, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = bdk_update_stat_with_overflow(tx_packets.s.count, handle->stats.tx.packets, 40);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    return &handle->stats;
}

__bdk_if_ops_t __bdk_if_ops_loop = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_loopback = if_loopback,
    .if_get_stats = if_get_stats,
};

