/**
 * @file
 *
 * Interface to the PKO.
 *
 * @addtogroup hal
 * @{
 */

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_global_init(bdk_node_t node);

/**
 * Configure PKO for a specific port. This is called for each
 * port on every interface that connects to PKO.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_port_init(bdk_if_handle_t handle);

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_enable(bdk_node_t node);

/**
 * Get the current TX queue depth. Note that this operation may be slow
 * and adversly affect packet IO performance.
 *
 * @param handle Port to check
 *
 * @return Depth of the queue in packets
 */
extern int bdk_pko_get_queue_depth(bdk_if_handle_t handle);

/**
 * Set PKO shapping as a specific queue level
 *
 * @param node       Node to shape
 * @param queue      Queue to shape
 * @param level      Level in PKO
 * @param is_red     Non-zero of the rate is for the yellow/red transition. Zero for the
 *                   green/yellow transition.
 * @param is_packets Non-zero if the rate is packets/sec, otherwise rate is bits/sec
 * @param rate       Desired rate. A rate of zero disables shaping
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_shape(bdk_node_t node, int queue, int level, int is_red, int is_packets, uint64_t rate);

/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_transmit(bdk_if_handle_t handle, const bdk_if_packet_t *packet);

/**
 * Query PKO and fill in the receive stats for the supplied
 * interface handle. The interface must use PKO for TX.
 *
 * @param handle Port handle
 *
 * @return
 */
extern void bdk_pko_fill_tx_stats(bdk_if_handle_t handle);

/** @} */
