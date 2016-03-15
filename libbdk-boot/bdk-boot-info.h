/**
 * @file
 *
 * Functions for displaying and retrieving infomration about the
 * boot environment
 *
 * @addtogroup boot
 * @{
 */


/**
 * Display information about strapping and other hard configuration items for
 * the specified node
 *
 * @param node   Node to display
 */
void bdk_boot_info_strapping(bdk_node_t node);

/**
 * Return a string containing information about the chip's manufacture wafer
 *
 * @param node   Node to query
 *
 * @return Static string, reused on each call
 */
const char* bdk_boot_info_wafer(bdk_node_t node);

/** @} */
