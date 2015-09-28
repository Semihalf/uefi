#include <bdk.h>

/**
 * Configure DRAM on a specific node
 *
 * @param node   Node to configure
 * @param prompt_for_speed
 *               If non-zero, the DRAM init code will prompt for the DRAM clock speed. This is
 *               used for SLT and should not be used otherwise.
 */
void bdk_boot_dram(bdk_node_t node, int prompt_for_speed)
{
    /* Don't ru nfor nodes that don't exist */
    if (!bdk_numa_exists(node))
        return;

    /* Lookup the DRAM config to use */
    const char *dram_config = bdk_brd_cfg_get_str(NULL, BDK_BRD_CFG_DRAM_NODE, node);
    if (dram_config == NULL)
        return;

    /* Make sure the DRAM verbose level is set correctly */
    int dram_verbose = bdk_brd_cfg_get_int(0, BDK_BRD_CFG_DRAM_VERBOSE);
    if (dram_verbose)
    {
        char buf[8];
        snprintf(buf, sizeof(buf), "%d", dram_verbose);
        setenv("ddr_verbose", buf, 1);
    }

    /* Prompt for the speed if necessary */
    int dram_speed = 0;
    if (prompt_for_speed)
    {
        const char *input = bdk_readline("DDR Clock in MHz:", NULL, 0);
        dram_speed = atoi(input);
        dram_speed *= 1000000;
    }

    BDK_TRACE(INIT, "Initializing DRAM on node %d\n", node);
    int mbytes = bdk_dram_config(node, dram_config, dram_speed);

    if (mbytes <= 0)
    {
        bdk_error("N%d: Failed DRAM init\n", node);
        /* Reset on failure if we're using the watchdog */
        if (bdk_watchdog_is_running())
            bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
        return;
    }

    /* Poke the watchdog */
    bdk_watchdog_poke();

    /* Report DRAM status */
    uint32_t freq = libdram_get_freq(node);
    freq = (freq + 500000) / 1000000;
    printf("Node %d: DRAM: %d MB, %u MHz\n", node, mbytes, freq);

    if (node == bdk_numa_master())
    {
        /* Unlock L2 now that DRAM works */
        uint64_t l2_size = bdk_l2c_get_cache_size_bytes(node);
        BDK_TRACE(INIT, "Unlocking L2\n");
        bdk_l2c_unlock_mem_region(node, 0, l2_size);
    }
    else if (bdk_watchdog_is_running())
    {
        /* Wake up one core on the other node */
        bdk_init_cores(node, 1);
        /* Run the address test to make sure DRAM works */
        if (bdk_dram_test(13, 0, 0x10000000000ull, BDK_DRAM_TEST_NO_STATS))
            bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
        /* Put other node core back in reset */
        BDK_CSR_WRITE(node, BDK_RST_PP_RESET, -1);
        /* Clear DRAM on first node */
        uint64_t skip = bdk_dram_get_top_of_bdk();
        bdk_zero_memory(bdk_phys_to_ptr(bdk_numa_get_address(bdk_numa_master(), skip)),
            ((uint64_t)mbytes << 20) - skip);
        /* Poke the watchdog */
        bdk_watchdog_poke();
        /* Clear DRAM on second node */
        bdk_zero_memory(bdk_phys_to_ptr(bdk_numa_get_address(node, 0)), (uint64_t)mbytes << 20);
    }

    /* Poke the watchdog */
    bdk_watchdog_poke();
}
