#include <bdk.h>

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(TWSI);
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    printf("BDK version: %s\n", bdk_version_string());
    if (!OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        bdk_fatal("This binary only supports CN70XX and CN71XX");
    }

    /* Use a fixed DRAM configuration that should work on most boards. If it
       doesn't, the BDK can' be used */
    const char *board_name = "evb7000";
    const int ddr_clock_hertz = 400 * 1000000;
    setenv("ddr_ranks", "1",  1);
    setenv("limit_dram_mbytes", "64",  1);
    //setenv("ddr_verbose", "yes",  1);

    printf("Initializing DRAM with conservative settings...\n");
    int dram_mb = bdk_dram_config(bdk_numa_local(), board_name, ddr_clock_hertz);
    if (dram_mb <= 0)
        bdk_fatal("DRAM initialization failed\n");

    printf("Clearing DRAM...\n");
    uint64_t dram_bytes = (uint64_t)dram_mb << 20;
    uint64_t start = bdk_l2c_get_cache_size_bytes(bdk_numa_local());
    uint64_t end = 256 << 20;
    if (end > dram_bytes)
        end = dram_bytes;
    bdk_zero_memory(bdk_phys_to_ptr(start), end - start);
    if (dram_bytes > end)
        bdk_zero_memory(bdk_phys_to_ptr(512<<20), dram_bytes - (256<<20));

    printf("Searching for second stage...\n");
    /* Find Uboot */
    void *image = bdk_phys_to_ptr((1ull<<48) | 0xfc00000);
    int image_size = 0;
    for (int i=0; i<31; i++)
    {
        image += 0x10000;
        uint32_t magic = *(uint32_t*)(image + 8);
        BDK_TRACE("\tChecking magic 0x%08x at address %p\n", magic, image);
        if (magic == 0x424f4f54) /* BOOT */
        {
            BDK_TRACE("\tFound at address %p\n", image);
            uint16_t header_len = *(uint16_t*)(image + 16);
            uint32_t data_len = *(uint32_t*)(image + 24);
            image_size = data_len + header_len;
            break;
        }
    }
    if (!image_size)
        bdk_fatal("Unable to find image\n");

    /* Put some sanity tests on the image size in case reading from NOR
       gave us a bogus image (64KB through 64MB is valid) */
    if ((image_size < 0x10000) || (image_size > 0x4000000))
        bdk_fatal("Unexpected image size of %d bytes\n", image_size);

    printf("Loading second stage of %d bytes...\n", image_size);
    void *load_ptr = (void *)0xffffffff80400000;
    /* Uboot needs to be 4MB aligned */
    memcpy(load_ptr, image, image_size);

    printf("Verifing second stage...\n");
    if (memcmp(load_ptr, image, image_size))
    {
        bdk_fatal("Verification failed, most likely DRAM isn't working\n");
        return -1;
    }

    printf("Unlock L2 before jumping to second stage...\n");
    bdk_l2c_flush(bdk_numa_local());
    /* Clear the L2C_TADX_INT[noway] bit as it will be set during the
       image load */
    BDK_CSR_DEFINE(ciu_cib_l2c_rawx, BDK_CIU_CIB_L2C_RAWX(0));
    ciu_cib_l2c_rawx.u = 0;
    ciu_cib_l2c_rawx.s.tadx_int_noway = 1;
    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_CIB_L2C_RAWX(0), ciu_cib_l2c_rawx.u);
    BDK_CSR_DEFINE(l2c_tadx_int, BDK_L2C_TADX_INT(0));
    l2c_tadx_int.u = 0;
    l2c_tadx_int.s.noway = 1;
    BDK_CSR_WRITE(bdk_numa_local(), BDK_L2C_TADX_INT(0), l2c_tadx_int.u);

    /* This is needed for Uboot, but the BDK doesn't need it */
    //BDK_TRACE("Saving environment\n");
    //extern void bdk_write_env(void);
    //bdk_write_env();

    printf("Jumping to second stage\n\n");
    return bdk_jump_address(0xffffffff80400000);
}
