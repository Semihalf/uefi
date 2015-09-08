#include <bdk.h>

/**
 * Query NIC and fill in the transmit stats for the supplied
 * interface handle.
 *
 * @param handle Port handle
 */
void bdk_nic_fill_tx_stats(bdk_if_handle_t handle)
{
    /* Account for TX adding FCS */
    const int bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
    const int vnic = handle->vnic;

    BDK_CSR_INIT(octs, handle->node, BDK_NIC_VNICX_TX_STATX(vnic, BDK_NIC_STAT_VNIC_TX_E_TX_OCTS));
    BDK_CSR_INIT(pkts, handle->node, BDK_NIC_VNICX_TX_STATX(vnic, BDK_NIC_STAT_VNIC_TX_E_TX_UCAST));
    BDK_CSR_INIT(drps, handle->node, BDK_NIC_VNICX_TX_STATX(vnic, BDK_NIC_STAT_VNIC_TX_E_TX_DROP));

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = bdk_update_stat_with_overflow(octs.u, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = bdk_update_stat_with_overflow(pkts.u, handle->stats.tx.packets, 48);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    handle->stats.tx.dropped_packets = bdk_update_stat_with_overflow(drps.u, handle->stats.tx.dropped_packets, 48);
    /* Dropped Octets are not available */
}

/**
 * Query NIC and fill in the receive stats for the supplied
 * interface handle.
 *
 * @param handle Port handle
 */
void bdk_nic_fill_rx_stats(bdk_if_handle_t handle)
{
    /* Account for RX FCS */
    const int bytes_off_rx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
    const int vnic = handle->vnic;

    /* Read the RX statistics. These do not include the ethernet FCS */
    BDK_CSR_INIT(rx_red, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_RED));
    BDK_CSR_INIT(rx_red_octets, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_RED_OCTS));
    BDK_CSR_INIT(rx_ovr, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_ORUN));
    BDK_CSR_INIT(rx_ovr_octets, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_ORUN_OCTS));
    uint64_t drops = rx_red.u + rx_ovr.u;
    uint64_t drop_octets = rx_red_octets.u + rx_ovr_octets.u;

    /* Drop and error counters */
    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_octets = bdk_update_stat_with_overflow(drop_octets, handle->stats.rx.dropped_octets, 48);
    handle->stats.rx.dropped_packets = bdk_update_stat_with_overflow(drops, handle->stats.rx.dropped_packets, 48);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;

    /* Normal RX stats are done by software on receive */
}
