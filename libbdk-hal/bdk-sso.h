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
 * Function called as a thread body to continuously read from the SSO and process
 * packets
 *
 * @param arg    Unused
 * @param arg1   Unused
 */
extern void bdk_sso_thread_read(int arg, void *arg1);

/** @} */
