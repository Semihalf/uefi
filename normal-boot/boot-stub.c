#include <bdk.h>
#include <malloc.h>
#include <board.h>
#include "boot-common.h"

/* How long to wait for selection of diagnostics (seconds) */
#define DIAGS_TIMEOUT 3
/* How long to wait for selection of safe boot (seconds) */
#define SAFE_BOOT_TIMEOUT 1

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(QLM);
    BDK_REQUIRE(MDIO);
    BDK_REQUIRE(PCIE);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(RNG);
    BDK_REQUIRE(KEY_MEMORY);
    BDK_REQUIRE(MPI);
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(TWSI);
    BDK_REQUIRE(USB);
}

extern int bdk_fs_fatfs_init(void);
extern const char *boot_device_volstr_for_boot_method(int boot_method);

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_node_t node = bdk_numa_local();

    /* Initialize the FAT filesystems be need to load the next stage */
    bdk_fs_fatfs_init();

    /* Check for safe mode boot.
     *
     * This allows the user to boot in safe mode in case the configuration file
     * does not work on the system and prevents boot.
     */
    char *cfgfile;

    printf("Press X to boot in safe mode...\n");
    int key = bdk_readline_getkey(SAFE_BOOT_TIMEOUT * 1000000);
    if ((key == 'x') || (key == 'X'))
    {
        printf("=================================================\n"
               "= BOOTING in SAFE MODE\n"
               "=================================================\n");

        /* Use the safe mode configuration file. */
        cfgfile = BDK_ENV_CFG_FILE_NAME_SAFE_MODE;
    }
    else
    {
        cfgfile = NULL; /* NULL == default filename */
    }

    if (bdk_loadenv(cfgfile))
        bdk_warn("Could not read environment variables from config file. "
                 "Will use empty configuration...\n");

    /* Enable watchdog */
    watchdog_set(WATCHDOG_TIMEOUT);

    boot_read_config();     /* Load configuration settings from config file */


    board_init_early();     /* Do board specific early initialization */


    boot_init_twsi();       /* Initialize TWSI interface TBD as a slave */


    /* Send status to the BMC: Started boot stub */
    update_bmc_status(BMC_STATUS_BOOT_STUB_STARTING);


    /* Initializing UART was done earlier in the BDK
     * Determine how we booted and display a banner
     */
    int boot_method;
    BDK_TRACE(BOOT_STUB, "Extracting strapping options\n");
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);


    /* boot_volume_id   - FATFS VOlume ID for loading stage1/2 from FAT filesystem */
    const char *boot_volume_id   = boot_device_volstr_for_boot_method(boot_method);
    if (!boot_volume_id)
    {
        bdk_error("No valid boot volume id found for boot method (%d)\n", boot_method);
    }

    printf(
        "=========================\n"
        "Cavium THUNDERX BDK image\n"
        "=========================\n"
        "BDK version: %s\n"
        "\n",
        bdk_version_string());


    watchdog_poke();


    boot_init_ccpi();       /* Set up CCPI */
    update_bmc_status(BMC_STATUS_BOOT_STUB_CCPI_COMPLETE);



    boot_init_dram(BDK_NODE_0); /* Initialize DRAM on node 0 */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE);
    boot_init_dram(BDK_NODE_1); /* Initialize DRAM on node 1 */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE);



    boot_init_qlm_clk();    /* Initialize QLM clocks */
    boot_init_qlm_mode();   /* Initialize QLM modes */
    update_bmc_status(BMC_STATUS_BOOT_STUB_QLM_COMPLETE);


    boot_init_bgx();


    boot_init_usb();


    watchdog_poke();


    boot_init_pci();


    board_init_late();


    /* Select ATF or diagnostics image */
    int use_atf = 1;

    /* A GPIO can be used to select diagnostics without input */
    int DIAGS_GPIO_VALUE = bdk_brd_cfg_get_int(BDK_BRD_CFG_DIAGS_GPIO_VALUE);
    if (-1 != DIAGS_GPIO_VALUE)
    {
        int DIAGS_GPIO = bdk_brd_cfg_get_int(BDK_BRD_CFG_DIAGS_GPIO);
        int gpio = bdk_gpio_read(bdk_numa_master()) >> DIAGS_GPIO;
        gpio &= 1;
        if (gpio == DIAGS_GPIO_VALUE)
        {
            printf("\nStarting diagnostics based on GPIO%d\n", DIAGS_GPIO);
            use_atf = 0;
        }
    }

    /* Poke the watchdog */
    watchdog_poke();

    /* Check for 'D' override */
    if (use_atf && (DIAGS_TIMEOUT > 0))
    {
        printf("\nPress 'D' within %d seconds to boot diagnostics\n", DIAGS_TIMEOUT);
        int key = bdk_readline_getkey(DIAGS_TIMEOUT * 1000000);
        use_atf = !((key == 'd') || (key == 'D'));
    }

    /* Poke the watchdog */
    watchdog_poke();

    /* Send status to the BMC: Loading ATF */
    if (use_atf)
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_ATF);
    else
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS);

    /* Transfer control to next image */
    if (use_atf)
    {
        /* Try to load ATF image from raw flash */
        const char *boot_device_name = boot_device_name_for_boot_method(boot_method);
        BDK_TRACE(BOOT_STUB, "Looking for ATF image\n");
        boot_image(boot_device_name, ATF_ADDRESS);
        bdk_error("Unable to load image\n");
        printf("Trying diagnostics\n");
    }

    /* Load Diagnostics from FAT fs */
    char filename[64];
    BDK_TRACE(BOOT_STUB, "Looking for Diagnostics image\n");
    snprintf(filename, sizeof(filename), "/fatfs/%s:/stage2.bin", boot_volume_id);
    boot_image(filename, 0);

    bdk_error("Image load failed\n");
}
