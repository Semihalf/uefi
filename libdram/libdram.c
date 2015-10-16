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

static void bdk_dram_clear_mem(bdk_node_t node)
{
    if (!bdk_is_platform(BDK_PLATFORM_ASIM)) {
	uint64_t mbytes = bdk_dram_get_size_mbytes(node);
	uint64_t skip = (node == bdk_numa_master()) ? bdk_dram_get_top_of_bdk() : 0;
	uint64_t len =  (mbytes << 20) - skip;

	BDK_TRACE(DRAM, "N%d: Clearing DRAM\n", node);
	printf("N%d: Clearing DRAM: start 0x%lx length 0x%lx\n", node, skip, len);
	bdk_zero_memory(bdk_phys_to_ptr(bdk_numa_get_address(node, skip)), len);
	BDK_TRACE(DRAM, "N%d: DRAM clear complete\n", node);
    }
}

static void bdk_dram_clear_ecc(bdk_node_t node)
{
    /* Clear any DRAM errors set during init */
    BDK_TRACE(DRAM, "N%d: Clearing LMC ECC errors\n", node);
    int num_lmc = __bdk_dram_get_num_lmc(node);
    for (int lmc = 0; lmc < num_lmc; lmc++) {
        DRAM_CSR_WRITE(node, BDK_LMCX_INT(lmc), BDK_CSR_READ(node, BDK_LMCX_INT(lmc)));
    }
}

// this routine simply makes the calls to the tuning routines and returns any errors
static int bdk_libdram_tune_node(int node)
{
    int errs, tot_errs;

    // Automatically tune the data byte DLL read offsets
    BDK_TRACE(DRAM, "N%d: Starting DLL Read Offset Tuning for LMCs\n", node);
    errs = perform_dll_offset_tuning(node, 2); 
    BDK_TRACE(DRAM, "N%d: Finished DLL Read Offset Tuning for LMCs, %d errors)\n",
	      node, errs);
    tot_errs = errs;

    // Automatically tune the ECC byte DLL read offsets
    BDK_TRACE(DRAM, "N%d: Starting ECC DLL Read Offset Tuning for LMCs\n", node);
    errs = perform_ECC_dll_offset_tuning(node, 2); 
    BDK_TRACE(DRAM, "N%d: Finished ECC DLL Read Offset Tuning for LMCs, %d errors)\n",
	      node, errs);
    tot_errs += errs;

    return tot_errs;
}

// this routine makes the calls to the tuning routines when criteria are met
// intended to be called for automated tuning, to apply filtering...
static int bdk_libdram_maybe_tune_node(int node)
{
    int tot_errs;

    // FIXME: allow an override here so that all configs can be tuned
    if (getenv("ddr_tune_all_configs") != NULL) // just being defined is enough...
	return bdk_libdram_tune_node(node);

    // filter the tuning calls here...
    // determine if we should/can run automatically for this configureation
    // FIXME: for now, limit to DDR4, RDIMMs over 1880, UDIMMs over 1050
    // FIXME: allow ability to override this behavior also, at a later date...
    // FIXME: *only* 1-slot configs for now...
    uint32_t ddr_speed = libdram_get_freq_from_pll(node, 0) / 1000000; // sample LMC0
    BDK_CSR_INIT(lmc_config, node, BDK_LMCX_CONFIG(0)); // sample LMC0
    int is_1slot = (lmc_config.s.init_status < 4); // HACK, should do better

    if (__bdk_dram_is_ddr4(node, 0) && is_1slot) {
	if (__bdk_dram_is_rdimm(node, 0) && (ddr_speed > 940)) {
	    printf("N%d: DDR4 RDIMM %d MHz eligible for auto-tuning.\n",
		   node, ddr_speed);
	    // FIXME? allow override to NOT do tuning?
	} else
	if (!__bdk_dram_is_rdimm(node, 0) && (ddr_speed > 1050)) {
	    printf("N%d: DDR4 UDIMM %d MHz eligible for auto-tuning.\n",
		   node, ddr_speed);
	    // FIXME? allow override to NOT do tuning?
	} else {
	    printf("N%d: DDR4 DIMM at %d MHz, low speed not eligible for auto-tuning.\n",
		   node, ddr_speed);
	    // FIXME? allow override to do tuning?
	    return 0;
	}
    } else {
	printf("N%d: DDR3 or 2-slot is not currently eligible for auto-tuning.\n", node);
	// FIXME? allow override to do tuning?
	return 0;
    }

    // call the tuning routines, done filtering...
    tot_errs = bdk_libdram_tune_node(node);

    return tot_errs;
}

/**
 * This is the main DRAM init function. Users of libdram should call this function,
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
    int errs;

    // look for an envvar or board config option to select 100 MHz or default to 50 MHz refclk
    // assumption: the alternate refclk is setup for 100MHz
    // note: we only need to turn on the alternate refclk select bit in LMC0
    int ddr_refclk_hertz = bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);
    int alt_refclk = bdk_brd_cfg_get_int(0, BDK_BRD_CFG_DDR_ALT_REFCLK, node);

    str = getenv("ddr_100mhz_refclk");
    if (str)
        alt_refclk = strtoul(str, NULL, 0) * 100;

    if (alt_refclk) { // if alternate clock was selected, we also need to set the bit and wait a little...
	ddr_refclk_hertz = alt_refclk * 1000000;
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
    BDK_TRACE(DRAM, "N%d: DRAM init returned %d, measured %u Hz\n",
	      node, mbytes, measured_ddr_hertz[node]);

    // call the tuning routines, with filtering...
    BDK_TRACE(DRAM, "N%d: Calling DRAM tuning\n", node);
    errs = bdk_libdram_maybe_tune_node(node);
    BDK_TRACE(DRAM, "N%d: DRAM tuning returned %d errors\n",
	      node, errs);

    // finally, clear memory and any left-over ECC errors
    bdk_dram_clear_mem(node);
    bdk_dram_clear_ecc(node);

    return mbytes;
}

/**
 * This is the main DRAM tuning function. Users of libdram should call this function,
 * avoiding the other internal function. As a rule, functions starting with
 * "libdram_*" are part of the external API and should be used.
 *
 * @param node   Node to tune. This may not be the same node as the one running the code
 *
 * @return Success or Fail
 */
int libdram_tune(int node)
{
    int tot_errs;
    const char *str;

    // check: maybe verbose was not set during init, but is now set...
    str = getenv("ddr_verbose");
    if (str)
        dram_verbosity = strtoul(str, NULL, 0);
    else
        dram_verbosity = 0;

    // call the tuning routines, no filtering...
    tot_errs = bdk_libdram_tune_node(node);

    // make sure to clear memory and any ECC errs when done... 
    bdk_dram_clear_mem(node);
    bdk_dram_clear_ecc(node);

    return tot_errs;
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
