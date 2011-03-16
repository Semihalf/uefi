#include <stdint.h>

#include "bdk_lib_octeon_shared.h"
#include "cvmx.h"
#include "lib_octeon_shared.h"

/**
 * We keep a copy of the last DRAM config that was used. This way
 * anyone can ask what the current config is after initialization
 * is complete.
 */
static board_table_entry_t current_board_config;


/**
 * Given a predefined board name, lookup the DRAM configuration
 * for it. A copy is returned, so the user must free this later.
 * If the board name is NULL, then the current running config is
 * returned. This will be all zeros if DRAM hasn't been configured
 * yet.
 *
 * @param board_name Name of the board to lookup. NULL or empty string for the
 *                   current config.
 *
 * @return A copy of the requested DRAM config structure, or NULL on
 *         failure.
 */
board_table_entry_t *bdk_dram_lookup_board(const char *board_name)
{
    const board_table_entry_t *board;
    if (board_name && board_name[0])
        board = lookup_board_table_entry(0, (char*)board_name);
    else
        board = &current_board_config;

    if (!board)
        return NULL;

    board_table_entry_t *copy = malloc(sizeof(board_table_entry_t));
    if (!copy)
        return NULL;

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
    uint32_t interface_mask;
    uint32_t measured_ddr_hertz;

    current_board_config = *board;

    const ddr_configuration_t *ddr = lookup_ddr_config_structure(cpu_id, current_board_config.board_type, 0, 0, &interface_mask);
    if (!ddr)
    {
        printf("ERROR: Failed to find DDR table entry\n");
        return -1;
    }

    if (current_board_config.default_ddr_clock_hz == 0)
        current_board_config.default_ddr_clock_hz = 533000000;

    int mbytes = octeon_ddr_initialize(cpu_id,
                              cvmx_clock_get_rate(CVMX_CLOCK_CORE),
                              current_board_config.default_ddr_clock_hz,
                              current_board_config.default_ddr_ref_hz,
                              interface_mask,
                              ddr,
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

    printf("DRAM: %d MB\n", mbytes);
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

