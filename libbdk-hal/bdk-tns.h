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
 * Initialize the TNS layer
 */
extern int bdk_tns_initialize(bdk_node_t node) BDK_WEAK;

/**
 * Write a block of data to a TNS register
 */
extern int bdk_tns_write_data(bdk_node_t node, uint32_t address, uint32_t *dataw, int cnt);

/**
 * Read a block of data from a TNS register
 */
extern int bdk_tns_read_data(bdk_node_t node, uint32_t address, uint32_t *dataw, int cnt);

/** @} */
