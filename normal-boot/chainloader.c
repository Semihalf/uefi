#include <bdk.h>
#include <malloc.h>

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
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
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
    uint64_t boot_count = 0;
    if (!bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        boot_count = BDK_CSR_READ(node, BDK_GSERX_SCRATCH(0));
        boot_count++;
        BDK_CSR_WRITE(node, BDK_GSERX_SCRATCH(0), boot_count);
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

    /* Load and transfer control to next image */
    BDK_TRACE(CHAINLOADER, "Looking for BDK image\n");
    boot_image("/fatfs/stage1.bin", 0);

    bdk_error("Image load failed\n");
}

