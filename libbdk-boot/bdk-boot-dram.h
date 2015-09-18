/**
 * @file
 *
 * Boot services for DRAM
 *
 * @addtogroup boot
 * @{
 */

/**
 * Configure DRAM on a specific node
 *
 * @param node   Node to configure
 * @param prompt_for_speed
 *               If non-zero, the DRAM init code will prompt for the DRAM clock speed. This is
 *               used for SLT and should not be used otherwise.
 */
extern void bdk_boot_dram(bdk_node_t node, int prompt_for_speed);

/** @} */
