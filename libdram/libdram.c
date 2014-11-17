#include <bdk.h>
#include "dram-internal.h"

/* This global variable is accessed through dram_is_verbose() to determine
   ther verbosity level. Use that function instead of it directly */
dram_verbosity_t dram_verbosity;

/**
 * This the main DRAM init function. Users of libdram should call this function,
 * avoiding the other internal function. As a rule, functions starting with
 * "libdram_*" are part of the external API and should be used.
 *
 * @param node   Node to initialize. This may not be the same node as the one running the code
 * @param dram_config
 *               DRAM configuration to use
 * @param ddr_clock_override
 *               If non-zeo, this overrides the DRAM clock speed in the config structure. This
 *               allows quickly testing of different DRAM speeds without modifying the basic
 *               config. If zero, the DRAM speed in the config is used.
 *
 * @return Amount of memory in MB. Zero or negative is a failure.
 */
int libdram_config(int node, const dram_config_t *dram_config, int ddr_clock_override)
{
    char *str;
    const ddr_configuration_t *ddr_config = dram_config->config;
    int ddr_clock_hertz = (ddr_clock_override) ? ddr_clock_override : dram_config->ddr_clock_hertz;

    BDK_TRACE(DRAM, "N%d: DRAM init started (hertz=%d, config=%p)\n", node, ddr_clock_hertz, dram_config);

    str = getenv("ddr_verbose");
    dram_verbosity = strtoul(str, NULL, 0);

    /* We need to calculate the interface mask based on the provided SPD
       addresses/contents */
    uint32_t interface_mask = 0;
    for (int i = 0; i < 4; i++)
    {
        if (ddr_config[i].dimm_config_table[0].spd_addrs[0] ||
            ddr_config[i].dimm_config_table[0].spd_ptrs[0])
            interface_mask |= 1 << i;
    }

    BDK_TRACE(DRAM, "N%d: Calling DRAM init\n", node);
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
    BDK_TRACE(DRAM, "N%d: DRAM init returned %d, measured %u Hz\n", node, mbytes, measured_ddr_hertz);
    return mbytes;
}

