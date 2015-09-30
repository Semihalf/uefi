#include <bdk.h>

/**
 * Initialize the CCPI links, but don't bringup the other nodes
 */
void bdk_boot_ccpi_link(void)
{
    /* multi_node: 0 = off, 1 = on, 2 = auto detect */
    int multi_node = bdk_brd_cfg_get_int(2, BDK_BRD_CFG_MULTI_NODE);
    if (!multi_node)
        return;

    BDK_TRACE(INIT, "Initializing CCPI links\n");
    if (__bdk_init_ccpi_links(0))
    {
        bdk_config_set(BDK_CONFIG_ENABLE_MULTINODE, 0);
        if (1 == multi_node) /* fail case for 'on' setting */
        {
            printf("CCPI: Link timeout\n");
            /* Reset on failure if we're using the watchdog */
            if (bdk_watchdog_is_running())
                bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
        }
        else /* fail case for 'auto' setting */
            BDK_TRACE(INIT, "Auto configured 1 node.\n");
    }
    else
    {
        bdk_config_set(BDK_CONFIG_ENABLE_MULTINODE, 1);
        if (2 == multi_node) /* success case for 'auto' setting */
            BDK_TRACE(INIT, "Auto configured 2 nodes.\n");
    }

    bdk_watchdog_poke();
}

/**
 * Bringup the other nodes
 */
void bdk_boot_ccpi_nodes(void)
{
    if (!bdk_config_get(BDK_CONFIG_ENABLE_MULTINODE))
        return;

    BDK_TRACE(INIT, "Initializing CCPI\n");
    __bdk_init_ccpi_multinode();
    /* Reset if CCPI failed */
    if (bdk_numa_is_only_one() && bdk_watchdog_is_running())
        bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);

    bdk_watchdog_poke();
}

