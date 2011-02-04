#include <stdint.h>

#define OCTEON_MODEL OCTEON_CN38XX_PASS2

#include "cvmx.h"
#include "lib_octeon_shared.h"

int bdk_dram_config(const char *board_name)
{
    uint32_t cpu_id = cvmx_get_proc_id();
    uint32_t interface_mask;
    uint32_t measured_ddr_hertz;
    int ddr_hertz = 533000000;
    int ddr_ref_hertz = 0;

    const board_table_entry_t *board = lookup_board_table_entry(0, (char*)board_name);
    if (!board)
    {
        printf("ERROR: Failed to find board table entry\n");
        return -1;
    }

    const ddr_configuration_t *ddr = lookup_ddr_config_structure(cpu_id, board->board_type, 0, 0, &interface_mask);
    if (!ddr)
    {
        printf("ERROR: Failed to find DDR table entry\n");
        return -1;
    }

    int mbytes = octeon_ddr_initialize(cpu_id,
                              cvmx_clock_get_rate(CVMX_CLOCK_CORE),
                              ddr_hertz,
                              ddr_ref_hertz,
                              interface_mask,
                              ddr,
                              &measured_ddr_hertz,
                              board->board_type,
                              0,
                              0);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        return -1;
    }

    printf("DRAM: %d MB\n", mbytes);
    return mbytes;
}

