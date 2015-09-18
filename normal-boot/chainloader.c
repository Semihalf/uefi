#include <bdk.h>
#include <malloc.h>

#include "boot-common.h"

#ifndef MFG_SYSTEM_LEVEL_TEST
#define MFG_SYSTEM_LEVEL_TEST 0
#endif

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

    /* Get the address of the version field in our header */
    uint64_t version_offset = offsetof(bdk_image_header_t, version);
    uint64_t version_pa = bdk_numa_get_address(node, version_offset);
    const char *version = bdk_phys_to_ptr(version_pa);

    printf(
        "===========================\n"
        "Cavium THUNDERX Chainloader\n"
        "===========================\n"
        "Version: %s\n"
        "Boot Attempt: %lu\n"
        "\n",
        version, boot_count);
    bdk_boot_info_strapping(bdk_numa_master());
    if (MFG_SYSTEM_LEVEL_TEST)
    {
        bdk_bist_check();
    }

    /* Load and transfer control to next image */
    BDK_TRACE(CHAINLOADER, "Looking for BDK image\n");
    bdk_image_boot("/fatfs/stage1.bin", 0);

    bdk_error("Image load failed\n");
}

