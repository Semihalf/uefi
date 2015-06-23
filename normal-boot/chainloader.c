#include <bdk.h>
#include <malloc.h>
#include <board.h>

#include "boot-common.h"

/* Enable or disable detailed tracing of the boot stub (0 or 1) */
#define BDK_TRACE_ENABLE_CHAINLOADER 0

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(MPI);
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_node_t node = bdk_numa_local();

    /* Drive GPIO 10 high, signalling success transferring from the boot ROM */
    BDK_TRACE(CHAINLOADER, "Driving GPIO10 high\n");
    bdk_gpio_initialize(node, 10, 1, 1);

    /* Update the boot counter held in GESR0_SCRATCH */
    uint64_t boot_count = BDK_CSR_READ(node, BDK_GSERX_SCRATCH(0));
    boot_count++;
    BDK_CSR_WRITE(node, BDK_GSERX_SCRATCH(0), boot_count);

    BDK_TRACE(CHAINLOADER, "Extracting strapping options\n");

    /* Initializing UART was done earlier in the BDK
     * Determine how we booted and display a banner
     */
    int boot_method;
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);

    /* remove this declaration once we find a good header file for this API. */
    extern const char *boot_device_volstr_for_boot_method(int boot_method);
    const char *boot_volume_id = boot_device_volstr_for_boot_method(boot_method);
    if (!boot_volume_id)
    {
        bdk_error("No valid boot volume id found for boot method (%d)\n", boot_method);
    }

    printf(
        "===========================\n"
        "Cavium THUNDERX Chainloader\n"
        "===========================\n"
        "Chainloader version: %s\n"
        "Boot Attempt: %lu\n"
        "\n",
        bdk_version_string(), boot_count);
    print_node_strapping(bdk_numa_master());

    /* Initialize the FAT filesystems be need to load the next stage */
    extern int bdk_fs_fatfs_init(void);
    bdk_fs_fatfs_init();

    /* Load the next image */
    /* Transfer control to next image */
    char filename[64];
    BDK_TRACE(CHAINLOADER, "Looking for BDK image\n");
    snprintf(filename, sizeof(filename), "/fatfs/%s:/stage1.bin", boot_volume_id);
    boot_image(filename, 0);

    bdk_error("Image load failed\n");
}

