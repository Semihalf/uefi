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
 * @param board_name Board name to configure
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
extern int bdk_dram_config(const char *board_name);

/**
 * Enable or disable verbose output during dram config
 *
 * @param is_verbose Non zero if verbose mose should be on
 */
extern void bdk_dram_verbose(int is_verbose);

/** @} */
