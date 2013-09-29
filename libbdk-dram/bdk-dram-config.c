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
ddr_config_table_t *bdk_dram_lookup_board(const char *board_name)
{
    static ddr_config_table_t current_ddr;

    if (board_name && board_name[0])
    {
        const board_table_entry_t *board = lookup_board_table_entry(0, (char*)board_name);
        if (!board)
            return NULL;
        /* Only use the first config */
        memcpy(&current_ddr, board->chip_ddr_config, sizeof(current_ddr));
    }
    else
    {
        int num_cfg = sizeof(current_ddr.ddr_config) / sizeof(current_ddr.ddr_config[0]);
        int num_ddr = sizeof(current_ddr.ddr_config[0].dimm_config_table) / sizeof(current_ddr.ddr_config[0].dimm_config_table[0]);
        int num_dimm = sizeof(current_ddr.ddr_config[0].dimm_config_table[0].spd_ptrs) / sizeof(current_ddr.ddr_config[0].dimm_config_table[0].spd_ptrs[0]);
        for (int cfg=0; cfg<num_cfg; cfg++)
        {
            for (int ddr=0; ddr<num_ddr; ddr++)
            {
                for (int dimm=0; dimm<num_dimm; dimm++)
                {
                    void *p = current_ddr.ddr_config[cfg].dimm_config_table[ddr].spd_ptrs[dimm];
                    if (p)
                        free(p);
                }
            }
        }
        memset(&current_ddr, 0, sizeof(current_ddr));
    }

    return &current_ddr;
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

int bdk_dram_config_raw(const ddr_config_table_t *ddr_config_table, int ddr_clock_hertz)
{
    uint32_t cpu_id = cvmx_get_proc_id();
    uint32_t interface_mask = 0;
    uint32_t measured_ddr_hertz;
    int interface_index;

    const ddr_configuration_t *ddr_config = ddr_config_table->ddr_config;

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
                              50000000,
                              interface_mask,
                              ddr_config,
                              &measured_ddr_hertz,
                              0,
                              0,
                              0);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        return -1;
    }

    /* Clear any DRAM errors set during init */
    cvmx_write_csr(CVMX_CIU_CIB_LMCX_RAWX(0,0), cvmx_read_csr(CVMX_CIU_CIB_LMCX_RAWX(0,0)));
    cvmx_write_csr(CVMX_LMCX_INT(0), cvmx_read_csr(CVMX_LMCX_INT(0)));

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
 * @param ddr_clock_hertz
 *                   DDR clock in hertz
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
int bdk_dram_config(const char *board_name, int ddr_clock_hertz)
{
    ddr_config_table_t *ddr_config = bdk_dram_lookup_board(board_name);
    if (!ddr_config)
        return -1;
    return bdk_dram_config_raw(ddr_config, ddr_clock_hertz);
}

