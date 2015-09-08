/**
 * @file
 *
 * Interface to the NIC.
 *
 * @addtogroup hal
 * @{
 */

/**
 * Query NIC and fill in the transmit stats for the supplied
 * interface handle.
 *
 * @param handle Port handle
 */
extern void bdk_nic_fill_tx_stats(bdk_if_handle_t handle);

/**
 * Query NIC and fill in the receive stats for the supplied
 * interface handle.
 *
 * @param handle Port handle
 */
extern void bdk_nic_fill_rx_stats(bdk_if_handle_t handle);

/** @} */
