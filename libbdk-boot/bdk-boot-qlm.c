/***********************license start***********************************
* Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
* reserved.
*
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*
*   * Neither the name of Cavium Inc. nor the names of
*     its contributors may be used to endorse or promote products
*     derived from this software without specific prior written
*     permission.
*
* This Software, including technical data, may be subject to U.S. export
* control laws, including the U.S. Export Administration Act and its
* associated regulations, and may be subject to export or import
* regulations in other countries.
*
* TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
* AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR
* WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
* TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
* REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
* DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
* OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
* PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT,
* QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK
* ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
***********************license end**************************************/
#include <bdk.h>

static void boot_init_qlm_clk(void)
{
    /* Setup reference clocks */
    for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
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
        for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
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
        for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
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
