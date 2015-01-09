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
 * Initialize the TNS block to handle packet processing (NON-BYPASS) mode.
 * TNS at power-up will be in BYPASS mode where packets from the vNIC pipes
 * to the BGx ports will be direct.  This is normally called automatically
 * in bdk-init-main.c.
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
 * Write out a block of data to starting at 'address'.  We allow
 * an address to be specified instead of a register, so that we
 * can do bulk loads using the *SST* registers in the DataPath.
 *
 * @param node    Node to use in a Numa setup
 * @param address Register address to write to
 * @param *dataw  Array of 32-bit values. dataw[0] is bits[31:0].
 * @param cnt     Number of 32-bit entries in dataw
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_tns_write_data(bdk_node_t node, uint32_t address, uint32_t *dataw, int cnt);

/**
 * Read in a block of data starting from 'address' for 'cnt' number of
 * 32-bit words.  The caller must supply an array of 32-bit unsigned
 * values to store the data and the number of 32-bit words to read.
 *
 * @param node    Node to use in a Numa setup
 * @param address Register address to read from
 * @param *dataw  Array of 32-bit values.  dataw[0] will contain the bits[31:0], etc.
 * @param cnt     Number of 32-bit entries in dataw.
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_tns_read_data(bdk_node_t node, uint32_t address, uint32_t *dataw, int cnt);

/** @} */
