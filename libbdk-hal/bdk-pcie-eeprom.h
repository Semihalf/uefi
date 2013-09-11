/**
 * @file
 *
 * Interface to programming the PCIe EEPROM
 *
 * <hr>$Revision: 51109 $<hr>
 *
 * @addtogroup hal
 * @{
 */

#define BDK_PCIE_EEPROM_PREAMBLE 0x9da1

/**
 * Read the specified offset in the PCIe EEPROM and returns its
 * value. In the case the EEPROM isn't there or can't be read -1
 * is returned.
 *
 * @param node      Numa node request is for
 * @param pcie_port PCIe port to access
 * @param offset    Offset in bytes, Must be a multiple of 8
 *
 * @return Value read or -1 if the read failed
 */
extern uint64_t bdk_pcie_eeprom_read(bdk_node_t node, int pcie_port, int offset);

/**
 * Write a value to the PCIe EEPROM. The value should be of the
 * format bdk_pemx_spi_data_t.
 *
 * @param node      Numa node request is for
 * @param pcie_port PCIe port to access
 * @param offset    Offset to write. Must be a multiple of 8 bytes.
 * @param value     Value to write
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pcie_eeprom_write(bdk_node_t node, int pcie_port, int offset, uint64_t value);

/** @} */
