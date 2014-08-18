/**
 * @file
 *
 * Functions for configuring DRAM.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup dram DRAM related functions
 * @{
 */
#include "../libdram/libdram.h"

/**
 * Lookup a DRAM configuration by name and intialize dram with it
 *
 * @param node   Node to configure
 * @param config_name
 *               Name of the configuration to use
 * @param ddr_clock_override
 *               If non zero, override the DRAM frequency specified in the config with
 *               this value
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
extern int bdk_dram_config(int node, const char *config_name, int ddr_clock_override);

/**
 * Get the amount of DRAM configured for a node. This is read from the LMC
 * controller after DRAM is setup.
 *
 * @param node   Node to query
 *
 * @return Size in megabytes
 */
extern uint64_t bdk_dram_get_size_mbytes(int node);

extern int __bdk_dram_get_num_lmc();

/** @} */
