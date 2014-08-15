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
 * Given a DRAM configuration, configure the hardware to match.
 * Note that a copy of the configuration is made, so the caller
 * may dispose of the structure after the call.
 *
 * @param node       Node to configure
 * @param ddr_config DRAM config structure
 * @param ddr_clock_hertz
 *                   DRAM frequency in hertz
 *
 * @return Amount of DRAM in MB, or negative on failure
 */

extern int bdk_dram_config(int node, const ddr_configuration_t *ddr_config, int ddr_clock_hertz);

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
