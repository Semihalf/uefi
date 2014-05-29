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

/**
 * Configure DRAM for a particular board
 *
 * @param node       Node ID to configure DRAM on
 * @param board_name Board name to configure
 * @param ddr_clock_hertz
 *                   DDR clock in hertz
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
extern int bdk_dram_config(int node, const char *board_name, int ddr_clock_hertz);

/**
 * Get the amount of DRAM configured for a node. This is read from the LMC
 * controller after DRAM is setup.
 *
 * @param node   Node to query
 *
 * @return Size in megabytes
 */
extern uint64_t bdk_dram_get_size_mbytes(int node);

/** @} */
