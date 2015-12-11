#include <bdk.h>

/**
 * Initialize the CCPI links, but don't bringup the other nodes
 *
 * @return Zero on success, negative on failure
 */
static int bdk_boot_ccpi_link(void)
{
    /* multi_node: 0 = off, 1 = on, 2 = auto detect */
    int multi_node = bdk_config_get_int(BDK_CONFIG_MULTI_NODE);
    if (!multi_node)
        return -1;

    BDK_TRACE(INIT, "Initializing CCPI links\n");
    int status = __bdk_init_ccpi_links(0);
    bdk_watchdog_poke();

    if (status)
    {
        bdk_config_set_int(0, BDK_CONFIG_MULTI_NODE);
        if (1 == multi_node) /* fail case for 'on' setting */
        {
            printf("CCPI: Link timeout\n");
            /* Reset on failure if we're using the watchdog */
            if (bdk_watchdog_is_running())
                bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
            return -1;
        }
        else /* fail case for 'auto' setting */
        {
            BDK_TRACE(INIT, "Auto configured 1 node.\n");
            return 0;
        }
    }
    else
    {
        if (2 == multi_node) /* success case for 'auto' setting */
            BDK_TRACE(INIT, "Auto configured 2 nodes.\n");
        return 0;
    }
}

/**
 * Bringup the other nodes
 */
static void bdk_boot_ccpi_nodes(void)
{
    int multi_node = bdk_config_get_int(BDK_CONFIG_MULTI_NODE);
    if (!multi_node)
        return;

    BDK_TRACE(INIT, "Initializing CCPI\n");
    __bdk_init_ccpi_multinode();
    /* Reset if CCPI failed */
    if (bdk_numa_is_only_one() && bdk_watchdog_is_running())
        bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);

    bdk_watchdog_poke();
}

/**
 * Initialize the CCPI links and bringup the other nodes
 */
void bdk_boot_ccpi(void)
{
    /* Only CN88XX supports CCPI */
    if (!CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return;
    if (bdk_boot_ccpi_link() == 0)
        bdk_boot_ccpi_nodes();
}
