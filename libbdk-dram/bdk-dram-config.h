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
 * @param ddr_clock_override
 *               If non zero, override the DRAM frequency specified in the config with
 *               this value
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
extern int bdk_dram_config(int node, int ddr_clock_override);

/**
 * Do DRAM configuration tuning
 *
 * @param node   Node to tune
 *
 * @return Success or Fail
 */
extern int bdk_dram_tune(int node);

/**
 * Do DRAM Margin all tests
 *
 * @param node   Node to tune
 *
 * @return None
 */
extern void bdk_dram_margin_all(int node);

/**
 * Get the amount of DRAM configured for a node. This is read from the LMC
 * controller after DRAM is setup.
 *
 * @param node   Node to query
 *
 * @return Size in megabytes
 */
extern uint64_t bdk_dram_get_size_mbytes(int node);

/**
 * Return the string of info about the current node's DRAM configuration.
 *
 * @param index  node to retrieve
 *
 * @return String or NULL
 */
extern const char* bdk_dram_get_info_string(int node);

/**
 * Return the highest address currently used by the BDK. This address will
 * be about 4MB above the top of the BDK to make sure small growths between the
 * call and its use don't cause corruption. Any call to memory allocation can
 * change this value.
 *
 * @return Size of the BDK in bytes
 */
extern uint64_t bdk_dram_get_top_of_bdk(void);

/**
 * Convert the supplied DRAM config into a device tree. The conversion modifies
 * the current in memory device tree by adding items that would create this DRAM
 * config. This function doesn't check for conflicting entries already in the
 * device tree, so care must be used. Use bdk_config_show() to display the device
 * tree as a DTS the user can cut/paste.
 *
 * @param node   Node the config is for
 * @param cfg    Config to convert
 */
extern void __bdk_dram_convert_to_dts(bdk_node_t node, const dram_config_t *cfg);

extern int __bdk_dram_get_num_lmc(bdk_node_t node);
extern int __bdk_dram_is_ddr4(bdk_node_t node, int lmc);
extern int __bdk_dram_is_rdimm(bdk_node_t node, int lmc);
extern uint32_t __bdk_dram_get_row_mask(bdk_node_t node, int lmc);
extern uint32_t __bdk_dram_get_col_mask(bdk_node_t node, int lmc);
extern int __bdk_dram_get_num_bank_bits(bdk_node_t node, int lmc);

/** @} */
