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

typedef struct {
	int delay;
	int loop_total;
	int loop_count;
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
#define RLEVEL_BITMASK_NARROW_ERROR             18
#define RLEVEL_BITMASK_BLANK_ERROR              100
#define RLEVEL_NONSEQUENTIAL_DELAY_ERROR        50
#define RLEVEL_ADJACENT_DELAY_ERROR             30

extern int initialize_ddr_clock(bdk_node_t node,
    const ddr_configuration_t *ddr_configuration, uint32_t cpu_hertz,
    uint32_t ddr_hertz, uint32_t ddr_ref_hertz, int ddr_interface_num,
    uint32_t ddr_interface_mask);
extern int test_dram_byte(uint64_t p, int count, int byte, uint64_t bitmask);

extern int octeon_ddr_initialize(bdk_node_t node, uint32_t cpu_hertz,
    uint32_t ddr_hertz, uint32_t ddr_ref_hertz, uint32_t ddr_interface_mask,
    const ddr_configuration_t *ddr_configuration, uint32_t *measured_ddr_hertz,
    int board_type, int board_rev_maj, int board_rev_min);

#endif /* __DRAM_INTERNAL_H__ */

