#ifndef __DRAM_INTERNAL_H__
#define __DRAM_INTERNAL_H__

/**
 * This header defines all internal API for libdram. None
 * of these functions should be called by users of the library.
 * This is the only header that DRAM files should include
 * from the libdram directory
 */

#include "libdram.h"
#include "lib_octeon_shared.h"
#include "dram-print.h"
#include "dram-util.h"
#include "dram-csr.h"
#include "dram-env.h"
#include "dram-gpio.h"
#include "dram-spd.h"
#include "dram-l2c.h"
#include "dram-init-ddr3.h"

#define RLEVEL_AVG_LOOPS_DEFAULT 1

#define RLEVEL_AVG_LOOPS_DEBUG   0
typedef struct {
    int delay;
    int loop_total;
    int loop_count;
#if RLEVEL_AVG_LOOPS_DEBUG
    int last;
    int diffs;
#endif
} rlevel_byte_data_t;


#define SET_DDR_DLL_CTL3(field, expr)                   \
    do {                                                \
        ddr_dll_ctl3.s.field = (expr);                  \
    } while (0)

#define ENCODE_DLL90_BYTE_SEL(byte_sel) ((byte_sel)+1)

#define GET_DDR_DLL_CTL3(field)                         \
    (ddr_dll_ctl3.s.field)


#define RLEVEL_BITMASK_TRAILING_BITS_ERROR      5
#define RLEVEL_BITMASK_BUBBLE_BITS_ERROR        4
#define RLEVEL_BITMASK_NARROW_ERROR             6
#define RLEVEL_BITMASK_BLANK_ERROR              100
#define RLEVEL_NONSEQUENTIAL_DELAY_ERROR        50
#define RLEVEL_ADJACENT_DELAY_ERROR             30

#define TWO_LMC_MASK  0x03
#define FOUR_LMC_MASK 0x0f
#define ONE_DIMM_MASK 0x01
#define TWO_DIMM_MASK 0x03

extern int initialize_ddr_clock(bdk_node_t node,
    const ddr_configuration_t *ddr_configuration, uint32_t cpu_hertz,
    uint32_t ddr_hertz, uint32_t ddr_ref_hertz, int ddr_interface_num,
    uint32_t ddr_interface_mask);
extern int test_dram_byte(uint64_t p, int count, int byte, uint64_t bitmask);
extern int test_dram_byte_hw(bdk_node_t node, int ddr_interface_num,
                             uint64_t p, int count, int byte, uint64_t bitmask);

extern int get_dimm_part_number(char *buffer, bdk_node_t node,
                                const dimm_config_t *dimm_config, int dimm_index);

extern int octeon_ddr_initialize(bdk_node_t node, uint32_t cpu_hertz,
    uint32_t ddr_hertz, uint32_t ddr_ref_hertz, uint32_t ddr_interface_mask,
    const ddr_configuration_t *ddr_configuration, uint32_t *measured_ddr_hertz,
    int board_type, int board_rev_maj, int board_rev_min);

extern uint64_t divide_nint(uint64_t dividend, uint64_t divisor);

#endif /* __DRAM_INTERNAL_H__ */

