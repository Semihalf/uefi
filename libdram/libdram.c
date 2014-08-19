#include <bdk.h>
#include "dram-internal.h"

int dram_verbose_on;

int libdram_config(int node, const dram_config_t *dram_config, int ddr_clock_override)
{
    const ddr_configuration_t *ddr_config = dram_config->config;
    int ddr_clock_hertz = (ddr_clock_override) ? ddr_clock_override : dram_config->ddr_clock_hertz;

    BDK_TRACE("N%d: DRAM init thread started (hertz=%d, config=%p)\n", node, ddr_clock_hertz, dram_config);

    dram_verbose_on = (getenv("ddr_verbose")) ? 1 : 0;

    /* We need to calculate the interface mask based on the provided SPD
       addresses/contents */
    uint32_t interface_mask = 0;
    for (int i = 0; i < 4; i++)
    {
        if (ddr_config[i].dimm_config_table[0].spd_addrs[0] ||
            ddr_config[i].dimm_config_table[0].spd_ptrs[0])
            interface_mask |= 1 << i;
    }

    /* We need to clear this global if we want this to work more than once.... */
    extern int global_ddr_clock_initialized;
    global_ddr_clock_initialized = 0;
    BDK_TRACE("N%d: Calling DRAM init\n", node);
    uint32_t measured_ddr_hertz = 0;
    int mbytes = octeon_ddr_initialize(node,
        bdk_clock_get_rate(node, BDK_CLOCK_CORE),
        ddr_clock_hertz,
        bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF),
        interface_mask,
        ddr_config,
        &measured_ddr_hertz,
        0,
        0,
        0);
    BDK_TRACE("N%d: DRAM init returned %d, measured %u Hz\n", node, mbytes, measured_ddr_hertz);
    return mbytes;
}

