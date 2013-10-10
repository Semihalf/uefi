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
    BDK_REQUIRE(PCIE_EEPROM);
    BDK_REQUIRE(FS_PCIE);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(RNG);
    BDK_REQUIRE(KEY_MEMORY);
    BDK_REQUIRE(MPI);
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(DRAM_TEST);
    BDK_REQUIRE(ENVIRONMENT);
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
    if (!bdk_is_simulation())
    {
        /* Verify the RCLK is running at the expected rate compared to the SCLK */
        uint64_t rclk_start = bdk_clock_get_count(BDK_CLOCK_RCLK);
        uint64_t sclk_start = bdk_clock_get_count(BDK_CLOCK_SCLK);
        bdk_wait_usec(10000);
        uint64_t rclk_end = bdk_clock_get_count(BDK_CLOCK_RCLK);
        uint64_t sclk_end = bdk_clock_get_count(BDK_CLOCK_SCLK);

        uint64_t rclk_delta = rclk_end - rclk_start;
        uint64_t sclk_delta = sclk_end - sclk_start;

        uint64_t rclk_rate = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_RCLK);
        uint64_t sclk_rate = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_SCLK);
        uint64_t rate = rclk_delta * sclk_rate / sclk_delta;
        uint64_t r_min = rclk_rate - (rclk_rate/64);
        uint64_t r_max = rclk_rate + (rclk_rate/64);

        if ((rate < r_min) || (rate > r_max))
            bdk_fatal("RCLK rate doesn't match multiplier (measured %lu, expected %lu)\n",
                rate, rclk_rate);
    }

    /* Start Lua. It will execute /rom/init.lua */
    return bdk_lua_start();
}
