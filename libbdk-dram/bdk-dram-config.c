#include <stdint.h>

#include "bdk_lib_octeon_shared.h"
#include "cvmx.h"
#include "lib_octeon_shared.h"
extern int global_ddr_clock_initialized;

/**
 * Given a predefined board name, lookup the DRAM configuration
 * for it. A copy is returned, so the user must free this later.
 * If the board name is NULL, then an empty (all zero) structure
 * is returned.
 *
 * @param board_name Name of the board to lookup. NULL or empty string for
 *          an empty config.
 *
 * @return A copy of the requested DRAM config structure, or NULL on
 *         failure.
 */
board_table_entry_t *bdk_dram_lookup_board(const char *board_name)
{
    const board_table_entry_t *board = NULL;
    if (board_name && board_name[0])
        board = lookup_board_table_entry(0, (char*)board_name);


    board_table_entry_t *copy = malloc(sizeof(board_table_entry_t));
    if (!copy)
        return NULL;

    if (!board)
        memset(copy, 0x0, sizeof(board_table_entry_t));
    else
        *copy = *board;
    return copy;
}


/**
 * Given a DRAM configuration, configure the hardware to match.
 * Note that a copy of the configuration is made, so the caller
 * may dispose of the structure after the call.
 *
 * @param board  DRAM configuration
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
int bdk_dram_config_raw(const board_table_entry_t *board)
{
    uint32_t cpu_id = cvmx_get_proc_id();
    uint32_t interface_mask = 0;
    uint32_t measured_ddr_hertz;
    uint32_t ddr_clock_hertz = 533000000; 
    int interface_index;

    board_table_entry_t current_board_config = *board;

    /* Get pointer to ddr configuration that we will use.  Hardcode to first config, as
    ** multiple configs are only used in very limited circumstances. We really only care about
    ** the ddr_config member.*/
    ddr_configuration_t *ddr_config = current_board_config.chip_ddr_config[0].ddr_config;

    if (current_board_config.default_ddr_clock_hz)
        ddr_clock_hertz = board->default_ddr_clock_hz;

    /* We need to calculate the interface mask based on the provided SPD addresses/contents.  This would
    ** normally be done by the lookup function in lib_octeon_shared, but since we are allowing user-modified
    ** structures, we need to do this here. Enable interfaces that have SPD addresses or contents associated with them.
    ** We hardcode the use of the first ddr configuration.  Multiple are used only to support very uncommon cases,
    ** none of which apply to 6XXX chips yet. */
    for (interface_index=0; interface_index<4; ++interface_index) {
        if (ddr_config[interface_index].dimm_config_table[0].spd_addrs[0]
            || ddr_config[interface_index].dimm_config_table[0].spd_ptrs[0]) {
            interface_mask |= 1 << interface_index;
        }
    }

    /* We need to clear this global if we want this to work more than once.... */
    global_ddr_clock_initialized = 0;
    int mbytes = octeon_ddr_initialize(cpu_id,
                              cvmx_clock_get_rate(CVMX_CLOCK_CORE),
                              ddr_clock_hertz,
                              current_board_config.default_ddr_ref_hz,
                              interface_mask,
                              ddr_config,
                              &measured_ddr_hertz,
                              current_board_config.board_type,
                              0,
                              0);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        return -1;
    }

    /* Store the amount of memory in the environment */
    char buffer[8];
    snprintf(buffer, sizeof(buffer), "%d", mbytes);
    buffer[sizeof(buffer)-1] = 0;
    setenv("dram_size_mbytes", buffer, 1);

    printf("DRAM: %d MB, %d MHz\n", mbytes, measured_ddr_hertz/1000000);
    return mbytes;
}


/**
 * Configure DRAM for a particular board
 *
 * @param board_name Board name to configure
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
int bdk_dram_config(const char *board_name)
{
    const board_table_entry_t *board = lookup_board_table_entry(0, (char*)board_name);
    if (!board)
    {
        printf("ERROR: Failed to find board table entry\n");
        return -1;
    }

    return bdk_dram_config_raw(board);
}

/**
 * Enable or disable verbose output during dram config
 *
 * @param is_verbose Non zero if verbose mose should be on
 */
void bdk_dram_verbose(int is_verbose)
{
    if (is_verbose)
        setenv("ddr_verbose", "yes", 1);
    else
        unsetenv("ddr_verbose");
}

