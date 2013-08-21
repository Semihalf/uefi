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
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    const char *board_name;
    int ddr_clock_hertz;

    printf("BDK version: %s\n", bdk_version_string());
    /* Figure out our DRAM parameters */
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        board_name = "ebb7800";
        ddr_clock_hertz = 667000000;
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        board_name = "ebb7000";
        ddr_clock_hertz = 533000000;
    }
    else
    {
        board_name = "ebb6100";
        ddr_clock_hertz = 533000000;
    }

    /* Prompt the user for a different DRAM frequency than our default. Wait
        for up to 1 second for the response */
    int timeout = 3000000; /* us */
    do
    {
        /* Build the prompt */
        char prompt[64];
        sprintf(prompt, "DRAM frequency in Hz [%d]: ", ddr_clock_hertz);
        /* Prompt the user */
        const char *response = bdk_readline(prompt, NULL, timeout);
        /* Disable the timeout in case we got invalid input. If we got an
            invalid input, require a good input. */
        timeout = 0;
        /* Convert the inout to a number */
        if (response != NULL)
        {
            ddr_clock_hertz = atoi(response);
            if (strstr(response, "verbose"))
                setenv("ddr_verbose", "yes",  1);
        }
        /* The range is arbitrary and simply meant to keep the number
            somewhat sane. The range is very high in case people want to
            try stuff that won't work */
    } while ((ddr_clock_hertz < 100000000) || (ddr_clock_hertz > 1600000000));
    printf("\nUsing DRAM frequency of %d Hz\n", ddr_clock_hertz);

    /* Initialize DRAM */
    bdk_dram_config(board_name, ddr_clock_hertz);
    /* Unlock L2 after DRAM is setup */
    bdk_l2c_flush(bdk_numa_local());

    /* Find Uboot */
    void *image = bdk_phys_to_ptr((1ull<<48) | 0xfc00000);
    int image_size = 0;
    for (int i=0; i<31; i++)
    {
        image += 0x10000;
        uint32_t magic = *(uint32_t*)(image + 8);
        if (magic == 0x424f4f54) /* BOOT */
        {
            uint16_t header_len = *(uint16_t*)(image + 16);
            uint32_t data_len = *(uint32_t*)(image + 24);
            image_size = data_len + header_len;
            break;
        }
    }

    /* Start Uboot */
    if (image_size)
    {
        extern void bdk_write_env(void);
        /* Uboot needs to be 4MB aligned */
        memcpy((void*)0xffffffff80400000, image, image_size);
        bdk_write_env();
        return bdk_jump_address(0xffffffff80400000);
    }
    else
        printf("Unable to find bootloader\n");
}
