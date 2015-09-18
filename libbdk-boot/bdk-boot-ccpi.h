/**
 * @file
 *
 * Boot services for CCPI
 *
 * @addtogroup boot
 * @{
 */

/**
 * Initialize the CCPI links, but don't bringup the other nodes
 */
extern void bdk_boot_ccpi_link(void);

/**
 * Bringup the other nodes
 */
extern void bdk_boot_ccpi_nodes(void);

/** @} */
