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
    BDK_REQUIRE(PCIE);
    BDK_REQUIRE(FS_PCIE);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(RNG);
    BDK_REQUIRE(TRA);
    BDK_REQUIRE(KEY_MEMORY);
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(DRAM_TEST);
    BDK_REQUIRE(ENVIRONMENT);
    BDK_REQUIRE(LWIP);
    BDK_REQUIRE(FS_TCP);
    BDK_REQUIRE(TELNET);
    BDK_REQUIRE(TFTP);
    BDK_REQUIRE(FS_XMODEM);
    BDK_REQUIRE(FS_RAM);
    BDK_REQUIRE(CSR_DB);
    BDK_REQUIRE(TRAFFIC_GEN);
    BDK_REQUIRE(ERROR_DECODE);
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    /* Start Lua. It will execute /rom/init.lua */
    return bdk_lua_start();
}
