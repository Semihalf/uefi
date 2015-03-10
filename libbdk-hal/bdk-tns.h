/**
 * @file
 *
 * Thunder Network Switch interface.
 *
 * $Revision$
 *
 * @addtogroup hal
 * @{
 */

/**
 * Initialize the TNS block to enable clocks, allow register accesses, and
 * perform some basic initialization in anticipation of future packet
 * processing.
 *
 * TNS at power-up will be in BYPASS mode where packets from the vNIC pipes
 * to the BGX ports will be direct, and this will not change that.
 *
 * This is normally called automatically in bdk-init-main.c.
 *
 * @param node Node to initialize
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_tns_initialize(bdk_node_t node) BDK_WEAK;

/**
 * Disable TNS from processing packets.  After this, TNS must be fully
 * initialized.  The NIC and BGX blocks must already be stopped before
 * calling this function.
 *
 * Nota Bene: In CN88XX_PASS_1 there is a bug that prevents TNS DataPath
 *            from draining packets.  So ensure that NIC and BGX have
 *            also drained their packet queues.
 *
 * @param node
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_tns_shutdown(bdk_node_t node);

/**
 * Set the TNS 'profile' to passthru.  I.e. do the necessary writes
 * to the TNS datapath and TNS sst (Search, SDE, and TxQ) registers
 * to configure the TNS to allow vNIC0..vNIC7 <-> LMAC0..LMAC7 traffic
 * to flow straight through TNS (although the actual enabling of using
 * the TNS is done elsewhere (in traffic-gen.))
 *
 * @param node Node to configure
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_tns_profile_passthru(bdk_node_t node) BDK_WEAK;

/**
 * Set the TNS 'profile' to bgxloopback.  I.e. do the necessary writes
 * to the TNS datapath and TNS sst (Search, SDE, and TxQ) registers
 * to configure the TNS to allow any packets received on LMAC0..LMAC7
 * (BGX ports) to be reflected back to the same port after hitting the
 * TNS (although the actual enabling of using the TNS is done elsewhere
 * (in traffic-gen.))
 *
 * @param node Node to configure
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_tns_profile_bgxloopback(bdk_node_t node) BDK_WEAK;

/** @} */
