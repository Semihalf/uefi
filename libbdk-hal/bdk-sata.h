/**
 * @file
 *
 * This file provides a SATA driver
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Return the number of SATA controllers on the chip
 *
 * @param node   Node to query
 *
 * @return Number of controllers, could be zero.
 */
int bdk_sata_get_controllers(bdk_node_t node);

/**
 * Initialize a SATA controller and begin device detection
 *
 * @param node       Node to initialize
 * @param controller Which controller to initalize
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_initialize(bdk_node_t node, int controller);

/**
 * Shutdown a SATA controller
 *
 * @param node       Node to access
 * @param controller Controller to shutdown
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_shutdown(bdk_node_t node, int controller);

/**
 * Return the number of SATA ports connected to this AHCI controller
 *
 * @param node       Node to query
 * @param controller SATA controller
 *
 * @return Number of ports. Zero if the controller doesn't connect to a QLM.
 */
int bdk_sata_get_ports(bdk_node_t node, int controller);

/**
 * Identify the SATA device connected to a controller
 *
 * @param node       Node to query
 * @param controller Controller to query
 * @param port       Which SATA port on the controller, zero based
 *
 * @return Size of the disk in bytes
 */
uint64_t bdk_sata_identify(bdk_node_t node, int controller, int port);

/**
 * Read data from a SATA device
 *
 * @param node       Node the controller is on
 * @param controller Which controller
 * @param port       Which port on the controller, zero based
 * @param lba        48 bit Block address to read
 * @param sectors    Number of 512 bytes sectors to read
 * @param buffer     Buffer to receive the data. Must be at least 512 * sectors in size
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_read(bdk_node_t node, int controller, int port, uint64_t lba, int sectors, void *buffer);

/**
 * Write data to a SATA device
 *
 * @param node       Node the controller is on
 * @param controller Which controller
 * @param port       Which port on the controller, zero based
 * @param lba        48 bit Block address to write
 * @param sectors    Number of 512 bytes sectors to write
 * @param buffer     Data buffer to write. Must be at least 512 * sectors in size
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_write(bdk_node_t node, int controller, int port, uint64_t lba, int sectors, const void *buffer);

/** @} */
