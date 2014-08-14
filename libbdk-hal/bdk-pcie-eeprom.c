#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(PCIE_EEPROM);

#if 0 /* PCIe EEPROM access not supported on CN88XX. Likely needed on other chips */

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
uint64_t bdk_pcie_eeprom_read(bdk_node_t node, int pcie_port, int offset)
{
    /* Make sure the interface is idle before we start */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_SPI_CTL(pcie_port), start_busy, ==, 0, 10000))
    {
        bdk_error("PCIe EEPROM read: PEMX_SPI_CTL[start_busy] is stuck on\n");
        return -1;
    }

    /* Issue the read */
    bdk_pemx_spi_ctl_t spi_ctl;
    spi_ctl.u = 0;
    spi_ctl.s.start_busy = 1;
    spi_ctl.s.cmd = 0x3; /* Read */
    spi_ctl.s.adr = offset;
    BDK_CSR_WRITE(node, BDK_PEMX_SPI_CTL(pcie_port), spi_ctl.u);

    /* Wait for complete, up to 100ms */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_SPI_CTL(pcie_port), start_busy, ==, 0, 100000))
    {
        bdk_error("PCIe EEPROM read: timeout\n");
        return -1;
    }

    /* Return the result */
    return BDK_CSR_READ(node, BDK_PEMX_SPI_DATA(pcie_port));
}

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
int bdk_pcie_eeprom_write(bdk_node_t node, int pcie_port, int offset, uint64_t value)
{
    bdk_pemx_spi_ctl_t spi_ctl;

    /* Make sure the interface is idle before we start */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_SPI_CTL(pcie_port), start_busy, ==, 0, 10000))
    {
        bdk_error("PCIe EEPROM write: PEMX_SPI_CTL[start_busy] is stuck on\n");
        return -1;
    }

    /* Enable writes to the EEPROM */
    spi_ctl.u = 0;
    spi_ctl.s.start_busy = 1;
    spi_ctl.s.cmd = 0x6; /* Write enable */
    BDK_CSR_WRITE(node, BDK_PEMX_SPI_CTL(pcie_port), spi_ctl.u);

    /* Wait for complete, up to 10ms */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_SPI_CTL(pcie_port), start_busy, ==, 0, 10000))
    {
        bdk_error("PCIe EEPROM write: Timeout on write enable\n");
        return -1;
    }

    /* Setup the data */
    BDK_CSR_WRITE(node, BDK_PEMX_SPI_DATA(pcie_port), value);
    BDK_CSR_READ(node, BDK_PEMX_SPI_DATA(pcie_port));

    /* Perform the write */
    spi_ctl.u = 0;
    spi_ctl.s.start_busy = 1;
    spi_ctl.s.cmd = 0x2; /* Write */
    spi_ctl.s.adr = offset;
    BDK_CSR_WRITE(node, BDK_PEMX_SPI_CTL(pcie_port), spi_ctl.u);

    /* Wait for complete, up to 100ms */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_SPI_CTL(pcie_port), start_busy, ==, 0, 100000))
    {
        bdk_error("PCIe EEPROM write: Timeout on write\n");
        return -1;
    }

    /* Disable writes to the EEPROM */
    spi_ctl.u = 0;
    spi_ctl.s.start_busy = 1;
    spi_ctl.s.cmd = 0x4; /* Write disable */
    BDK_CSR_WRITE(node, BDK_PEMX_SPI_CTL(pcie_port), spi_ctl.u);

    /* Wait for complete, up to 10ms */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_SPI_CTL(pcie_port), start_busy, ==, 0, 10000))
    {
        bdk_error("PCIe EEPROM write: Timeout on write disable\n");
        return -1;
    }

    /* All done */
    return 0;
}

#endif
