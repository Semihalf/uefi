#include <bdk.h>

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(CCPI);
    BDK_REQUIRE(CSR_DB);
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(DRAM_TEST);
    BDK_REQUIRE(ERROR_DECODE);
    BDK_REQUIRE(FS_BOOT);
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MEM);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
    BDK_REQUIRE(FS_PCIE);
    BDK_REQUIRE(FS_RAM);
    BDK_REQUIRE(FS_ROM);
    BDK_REQUIRE(FS_SATA);
    BDK_REQUIRE(FS_XMODEM);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(SGPIO);
    BDK_REQUIRE(KEY_MEMORY);
    BDK_REQUIRE(MDIO);
    BDK_REQUIRE(MPI);
    BDK_REQUIRE(PCIE);
    BDK_REQUIRE(POWER_BURN);
    BDK_REQUIRE(QLM);
    BDK_REQUIRE(QLM_MARGIN);
    BDK_REQUIRE(RNM);
    BDK_REQUIRE(SATA);
    BDK_REQUIRE(TRAFFIC_GEN);
    BDK_REQUIRE(TWSI);
    BDK_REQUIRE(USB);
    BDK_REQUIRE(ECAM);
    BDK_REQUIRE(DRIVER);

    BDK_REQUIRE(DRIVER_CCPI);
    BDK_REQUIRE(DRIVER_SMMU);
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_boot_status(BDK_BOOT_STATUS_DIAG_STARTING);
    bdk_watchdog_disable();
    bdk_boot_status(BDK_BOOT_STATUS_DIAG_COMPLETE);
    /* Start Lua. It will execute init.lua */
    return bdk_lua_start();
}
