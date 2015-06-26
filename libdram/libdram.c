#include <bdk.h>
#include "dram-internal.h"

/* This global variable is accessed through dram_is_verbose() to determine
   the verbosity level. Use that function instead of setting it directly */
dram_verbosity_t dram_verbosity = OFF; /* init this here so we could set a non-zero default */

static uint32_t measured_ddr_hertz[BDK_NUMA_MAX_NODES];

/* The various DRAM configs in the libdram/configs directory need space
   to store the DRAM config. Since only one config is ever in active use
   at a time, store the configs in __libdram_global_cfg. In a multi-node
   setup, independent calls to get the DRAM config will load first node 0's
   config, then node 1's */
dram_config_t __libdram_global_cfg;

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
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
        return bdk_dram_get_size_mbytes(node);

    const char *str;
    const ddr_configuration_t *ddr_config = dram_config->config;
    int ddr_clock_hertz = (ddr_clock_override) ? ddr_clock_override : dram_config->ddr_clock_hertz;

    // look for an envvar to select 100 MHz or default to 50 MHz refclk
    // assumption: the alternate refclk is setup for 100MHz
    // note: we only need to turn on the alternate refclk select bit in LMC0
    int ddr_refclk_hertz = bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);
    str = getenv("ddr_100mhz_refclk");
    if (str) { // if 100MHz selected, we also need to set the bit and wait a little...
        ddr_refclk_hertz = 100000000; // FIXME: assumption of the frequency
	DRAM_CSR_MODIFY(c, node, BDK_LMCX_DDR_PLL_CTL(0), c.s.dclk_alt_refclk_sel = 1);
	bdk_wait_usec(1000); // wait 1 msec
    }

    BDK_TRACE(DRAM, "N%d: DRAM init started (hertz=%d, refclk=%d, config=%p)\n",
	      node, ddr_clock_hertz, ddr_refclk_hertz, dram_config);

    str = getenv("ddr_verbose");
    if (str)
        dram_verbosity = strtoul(str, NULL, 0);
    else
        dram_verbosity = 0;

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
    measured_ddr_hertz[node] = 0;
    int mbytes = octeon_ddr_initialize(node,
        bdk_clock_get_rate(node, BDK_CLOCK_RCLK),
        ddr_clock_hertz,
        ddr_refclk_hertz,
        interface_mask,
        ddr_config,
        &measured_ddr_hertz[node],
        0,
        0,
        0);
    BDK_TRACE(DRAM, "N%d: DRAM init returned %d, measured %u Hz\n", node, mbytes, measured_ddr_hertz[node]);

    BDK_TRACE(DRAM, "N%d: Clearing DRAM\n", node);
    uint64_t skip = 0;
    if ((bdk_node_t)node == bdk_numa_master())
        skip = bdk_dram_get_top_of_bdk();
    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
        bdk_zero_memory(bdk_phys_to_ptr(bdk_numa_get_address(node, skip)),
        ((uint64_t)mbytes << 20) - skip);
    BDK_TRACE(DRAM, "N%d: DRAM clear complete\n", node);

    /* Clear any DRAM errors set during init */
    BDK_TRACE(DRAM, "N%d: Clearing LMC errors\n", node);
    int num_lmc = __bdk_dram_get_num_lmc(node);
    for (int lmc = 0; lmc < num_lmc; lmc++)
    {
        DRAM_CSR_WRITE(node, BDK_LMCX_INT(lmc), BDK_CSR_READ(node, BDK_LMCX_INT(lmc)));
    }

    return mbytes;
}

/**
 * Get the measured DRAM frequency after a call to libdram_config
 *
 * @param node   Node to get frequency for
 *
 * @return Frequency in Hz
 */
uint32_t libdram_get_freq(int node)
{
    return measured_ddr_hertz[node];
}

/**
 * Get the measured DRAM frequency from the DDR_PLL_CTL CSR
 *
 * @param node   Node to get frequency for
 *
 * @return Frequency in Hz
 */
uint32_t libdram_get_freq_from_pll(int node, int lmc)
{
    static const uint8_t _en[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
    BDK_CSR_INIT(c, node, BDK_LMCX_DDR_PLL_CTL(0));
    // we check the alternate refclk select bit in LMC0 to indicate 100MHz use
    // assumption: the alternate refclk is setup for 100MHz
    uint64_t ddr_ref_hertz = (c.s.dclk_alt_refclk_sel) ? 100000000 : bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);
    uint64_t en = _en[c.s.ddr_ps_en];
    uint64_t calculated_ddr_hertz = ddr_ref_hertz * (c.s.clkf + 1) / ((c.s.clkr + 1) * en);
    return calculated_ddr_hertz;
}

#ifndef DRAM_CSR_WRITE_INLINE
void dram_csr_write(bdk_node_t node, const char *csr_name, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    if (dram_is_verbose(TRACE_CSR_WRITES))
        printf("DDR Config %s[%016lx] => %016lx\n", csr_name, address, value);
    bdk_csr_write(node, type, busnum, size, address, value);
}
#endif
