#ifndef __BOOT_COMMON_H__
#define __BOOT_COMMON_H__

#include <bdk.h>

/* Enable or disable detailed tracing of the boot stub (0 or 1) */
#define BDK_TRACE_ENABLE_BOOT_STUB 0

/* Address of the diagnostics in flash (512KB is right after boot stubs) */
#define DIAGS_ADDRESS 0x00080000
/* Address of ATF in flash */
#define ATF_ADDRESS 0x00400000

void print_node_strapping(bdk_node_t node);
const char *boot_device_name_for_boot_method(int boot_method);

/* Weakly bound default functions. Can be overwritten by board specific
 * functions in board/$(BOARD_TYPE)/board_init.c
 */
void board_init_early() BDK_WEAK;
void board_init_late() BDK_WEAK;

#endif /* __BOOT_COMMON_H__ */
