#include <bdk.h>

BDK_REQUIRE_DEFINE(DRAM_CONFIG);

/**
 * Given a DRAM configuration, configure the hardware to match.
 * Note that a copy of the configuration is made, so the caller
 * may dispose of the structure after the call.
 *
 * @param node       Node to configure
 * @param ddr_config DRAM config structure
 * @param ddr_clock_hertz
 *                   DRAM frequency in hertz
 *
 * @return Amount of DRAM in MB, or negative on failure
 */

int bdk_dram_config(int node, const ddr_configuration_t *ddr_config, int ddr_clock_hertz)
{
    BDK_TRACE("N%d: DRAM init (hertz=%d, config=%p)\n", node, ddr_clock_hertz, ddr_config);
    int mbytes = libdram_config(node, ddr_config, ddr_clock_hertz);
    BDK_TRACE("N%d: DRAM init returned %d\n", node, mbytes);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        return -1;
    }

    /* Clear any DRAM errors set during init */
    BDK_TRACE("N%d: Clearing L2 errors\n", node);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_WRITE(node, BDK_LMCX_INT(0), BDK_CSR_READ(node, BDK_LMCX_INT(0)));
        BDK_CSR_WRITE(node, BDK_LMCX_INT(1), BDK_CSR_READ(node, BDK_LMCX_INT(1)));
        BDK_CSR_WRITE(node, BDK_LMCX_INT(2), BDK_CSR_READ(node, BDK_LMCX_INT(2)));
        BDK_CSR_WRITE(node, BDK_LMCX_INT(3), BDK_CSR_READ(node, BDK_LMCX_INT(3)));
    }

    printf("BDK DRAM: %d MB, %d MHz\n", mbytes, ((ddr_clock_hertz + 500000) /1000000));
    return mbytes;
}

