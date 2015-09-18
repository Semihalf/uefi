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
 * Query the hardware and determine the filename representing the boot device
 *
 * @return String represent the boot device. An example would be
 *         "/dev/n0.mmc0"
 */
const char* bdk_boot_info_bootdev(void);

/** @} */
