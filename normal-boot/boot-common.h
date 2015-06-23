#ifndef __BOOT_COMMON_H__
#define __BOOT_COMMON_H__

#include <bdk.h>

/* Enable or disable detailed tracing of the boot stub (0 or 1) */
#define BDK_TRACE_ENABLE_BOOT_STUB 0

typedef enum
{
    BMC_STATUS_BOOT_STUB_STARTING               = 0x000,
    BMC_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE    = 0x001,
    BMC_STATUS_BOOT_STUB_CCPI_COMPLETE          = 0x002,
    BMC_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE    = 0x003,
    BMC_STATUS_BOOT_STUB_QLM_COMPLETE           = 0x004,
    BMC_STATUS_BOOT_STUB_LOADING_ATF            = 0x005,
    BMC_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS    = 0x006,
    BMC_STATUS_BOOT_STUB_COMPLETE               = 0x007,
    BMC_STATUS_REQUEST_POWER_CYCLE              = 0x0f2,
} bmc_status_t;

/* Control whether the boot stub request power cycles from the BMC (0 or 1).
   This is only useful in conjuction with WATCHDOG_TIMEOUT */
#define USE_POWER_CYCLE (WATCHDOG_TIMEOUT != 0)

/* Address of the diagnostics in flash (512KB is right after boot stubs) */
#define DIAGS_ADDRESS 0x00080000
/* Address of ATF in flash */
#define ATF_ADDRESS 0x00400000

/* Filename for bootstrap (ATF) image on FAT filesystem, if available */
#define BOOTSTRAP_IMAGE_FILENAME "bootstrap.bin"

void boot_read_config();

void print_node_strapping(bdk_node_t node);
void update_bmc_status(bmc_status_t status);
const char *boot_device_name_for_boot_method(int boot_method);
void reset_or_power_cycle(void);

void boot_image(const char *filename, uint64_t loc);

void boot_init_twsi();
void boot_init_dram(bdk_node_t node);
void boot_init_ccpi_link();
void boot_init_ccpi_node();
void boot_init_qlm_clk();
void boot_init_qlm_mode();
void boot_init_bgx();
void boot_init_usb();
void boot_init_pci();

void watchdog_set(int timeout);
void watchdog_poke();
void watchdog_disable();

/* Weakly bound default functions. Can be overwritten by board specific
 * functions in board/$(BOARD_TYPE)/board_init.c
 */
void board_init_early() BDK_WEAK;
void board_init_late() BDK_WEAK;

#endif /* __BOOT_COMMON_H__ */
