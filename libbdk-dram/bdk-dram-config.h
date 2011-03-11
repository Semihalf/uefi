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

/** @} */
