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

/** @} */
