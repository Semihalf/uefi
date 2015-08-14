/**
 * @file
 *
 * Interface to the SSO.
 *
 * @addtogroup hal
 * @{
 */

/**
 * Initialize the SSO
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_sso_init(bdk_node_t node);

/**
 * Register a bdk-if handle with the SSO code so the SSO can be used to receive
 * traffic from it.
 *
 * @param handle Handle to register
 */
extern void bdk_sso_register_handle(bdk_if_handle_t handle);

/**
 * Convert a WQE into a BDK packet
 *
 * @param work   Pointer to WQE to convert
 * @param packet Packet to receive the data
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_sso_wqe_to_packet(const void *work, bdk_if_packet_t *packet);

/** @} */
