#include <bdk.h>

static void boot_init_qlm_clk(void)
{
    /* Setup reference clocks */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (!bdk_numa_exists(n))
            continue;

        int num_qlms = bdk_qlm_get_num(n);

        BDK_TRACE(INIT, "Initializing QLM clocks on Node %d\n", n);
        for (int qlm = 0; qlm < num_qlms; qlm++)
        {
            bdk_qlm_clock_t clk = bdk_config_get_int(BDK_CONFIG_QLM_CLK, n, qlm);
            if (BDK_QLM_CLK_LAST == clk) /* no entry */
                continue;

            if (clk > BDK_QLM_CLK_LAST)
            {
                bdk_warn("Invalid clock source %d for QLM%d on node %d. Not configuring.\n",
                         clk, qlm, n);
                continue;
            }

            if (0 != bdk_qlm_set_clock(n, qlm, clk))
            {
                bdk_error("Error setting clock source %d for QLM%d on node %d. Ignoring.\n",
                          clk, qlm, n);
            }
        }
    }
}

static void boot_init_qlm_mode(void)
{
    /* Check if QLM autoconfig is requested */
    int qlm_auto = bdk_config_get_int(BDK_CONFIG_QLM_AUTO_CONFIG);
    if (qlm_auto)
    {
        /* Auto configuration of QLMs
         */
        for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
        {
            if (bdk_numa_exists(n))
            {
                BDK_TRACE(INIT, "Initializing QLMs on Node %d\n", n);
                bdk_qlm_auto_config(n);
            }
        }
    }
    else
    {
        /* Initialize the QLMs based on configuration file settings
         */
        for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
        {
            if (!bdk_numa_exists(n))
                continue;

            int num_qlms = bdk_qlm_get_num(n);

            BDK_TRACE(INIT, "Initializing QLMs on Node %d\n", n);
            for (int qlm = 0; qlm < num_qlms; qlm++)
            {
                const char *cfg_val;

                cfg_val = bdk_config_get_str(BDK_CONFIG_QLM_MODE, n, qlm);
                if (!cfg_val)
                    continue;

                int mode = bdk_qlm_cfg_string_to_mode(cfg_val);
                if (-1 == mode)
                {
                    bdk_error("Invalid QLM mode string '%s' for QLM%d on node %d. "
                                "Not configuring.\n", cfg_val, qlm, n);
                    continue;
                }
                int freq = bdk_config_get_int(BDK_CONFIG_QLM_FREQ, n, qlm);
                if (-1 == freq)
                {
                    bdk_error("No frequency setting for QLM%d on node %d. "
                                "Not configuring.\n", qlm, n);
                    continue;
                }

                bdk_qlm_set_mode(n, qlm, mode, freq, 0);
            }
        }
    }
}

/**
 * Configure QLM on all nodes as part of booting
 */
void bdk_boot_qlm(void)
{
    boot_init_qlm_clk();
    boot_init_qlm_mode();
}
