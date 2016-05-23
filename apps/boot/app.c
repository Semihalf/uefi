#include <bdk.h>
#include <ctype.h>

#ifndef MFG_SYSTEM_LEVEL_TEST
#define MFG_SYSTEM_LEVEL_TEST 0
#endif

/* This variable gets set to non-zero if any configuration error is detected
   such that we can't proceed through the normal boot path */
static int is_misconfigured = 0;

/* Filename of the next stage, default is init.bin */
static const char *next_stage = NULL;

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(FS_BOOT);
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(MPI);
}

void boot_menu(void)
{
    bdk_menu_t menu;
    while (1)
    {
        bdk_menu_init(&menu, "Boot Options");
        if (!is_misconfigured) // Hidden if no board configuration
            bdk_menu_item(&menu, 'N', "Boot Normally", NULL, NULL);
        if (!is_misconfigured && next_stage) // Hidden if no custom next stage is configured
            bdk_menu_item(&menu, 'I', "Boot Normally (ignoring custom boot stages)", NULL, NULL);
        bdk_menu_item(&menu, 'S', "Enter Setup", NULL, NULL);
        if (!is_misconfigured) // Hidden if no board configuration
            bdk_menu_item(&menu, 'D', "Enter Diagnostics", NULL, NULL);
        bdk_menu_item(&menu, 'E', "Enter Diagnostics, skipping Setup", NULL, NULL);
        bdk_menu_item(&menu, 'F', "Select Image from Flash", NULL, NULL);
        bdk_menu_item(&menu, 'X', "Upload File to FatFS using Xmodem", NULL, NULL);
        bdk_menu_item(&menu, 'W', "Burn boot flash using Xmodem", NULL, NULL);
        bdk_menu_item(&menu, 'U', "Change baud rate and flow control", NULL, NULL);
        bdk_menu_item(&menu, 'R', "Reboot", NULL, NULL);

        int key = bdk_menu_display(&menu);

        switch (key)
        {
            case 'N': /* Boot normally */
                bdk_image_boot(next_stage ? next_stage : "/fatfs/init.bin", 0);
                break;
            case 'I': /* Force-boot init.bin (skip any custom stage) */
                bdk_image_boot("/fatfs/init.bin", 0);
                break;
            case 'S': /* Enter Setup */
                bdk_image_boot("/fatfs/setup.bin", 0);
                break;
            case 'D': /* Boot diagnostics */
                bdk_config_set_int(1, BDK_CONFIG_BOOT_PATH_OPTION);
                bdk_image_boot("/fatfs/init.bin", 0);
                break;
            case 'E': /* Enter diagnostics directly */
                bdk_image_boot("/fatfs/diagnostics.bin", 0);
                break;
            case 'F': /* Select an image */
                bdk_image_choose("BOOT:");
                break;
            case 'X': /* Xmodem to FatFS */
            {
                const char *filename = bdk_readline("Filename: ", NULL, 0);
                if (!filename || 0 == strlen(filename))
                {
                    bdk_error("Illegal filename\n");
                    break;
                }

                char name[_MAX_LFN +1];
                snprintf(name, sizeof(name), "/fatfs/%s", filename);
                bdk_xmodem_upload(name, 0);
                break;
            }
            case 'W': /* Xmodem to ram flash */
            {
                bdk_xmodem_upload("/boot", 0);
                break;
            }
            case 'U': /* Change baud rate */
            {
                const char *baud = bdk_readline("Baudrate: ", NULL, 0);
                if ((baud[0] == 0) || (baud[0] == 3))
                    break;
                int baudrate = atoi(baud);
                if ((baudrate < 9600) || (baudrate > 4000000))
                {
                    bdk_error("Illegal baudrate\n");
                    break;
                }
                const char *flow = bdk_readline("Use hardware flow control(y/n) [n]: ", NULL, 0);
                if (flow[0] == 3)
                    break;
                int use_flow = (toupper((int)*flow) == 'Y');
                printf("Changing baudrate to %d\n", baudrate);
                fflush(NULL);
                bdk_wait_usec(500000);
                bdk_set_baudrate(bdk_numa_local(), 0, baudrate, use_flow);
                printf("Baudrate is now %d\n", baudrate);
                break;
            }
            case 'R': /* Reboot */
                printf("Rebooting\n");
                bdk_reset_chip(bdk_numa_master());
                break;
            default:
                bdk_error("Invalid choice\n");
                break;
        }
    }
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
    bdk_gpio_initialize(node, 10, 1, 1);
    bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_STARTING);

    const char *board = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
    if (strncasecmp(board, "EBB88", 5) == 0)
    {
        bdk_evb_display_init(node);
        bdk_evb_display_write_str(node, "Cavium");
    }

    /* Get the address of the version field in our header */
    uint64_t version_offset = offsetof(bdk_image_header_t, version);
    uint64_t version_pa = bdk_numa_get_address(node, version_offset);
    const char *version = bdk_phys_to_ptr(version_pa);

    printf(
        "================\n"
        "Cavium Boot Stub\n"
        "================\n"
        "Firmware Version: %s\n"
        "BDK Version: %s\n"
        "\n"
        "Board Model:    %s\n"
        "Board Revision: %s\n"
        "Board Serial:   %s\n"
        "\n",
        version,
        bdk_version_string(),
        board,
        bdk_config_get_str(BDK_CONFIG_BOARD_REVISION),
        bdk_config_get_str(BDK_CONFIG_BOARD_SERIAL));
    bdk_boot_info_strapping(bdk_numa_master());

    /* Check if the next boot stage is configured. */
    next_stage = bdk_config_get_str(BDK_CONFIG_BOOT_NEXT_STAGE, "BOOT");

    /* If no DRAM config goto the boot menu. First check for SPD addresses */
    int spd_addr = bdk_config_get_int(BDK_CONFIG_DDR_SPD_ADDR, 0 /* DIMM */, 0 /* LMC */, bdk_numa_master());
    if ((spd_addr == 0) && !bdk_is_platform(BDK_PLATFORM_ASIM) && !bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        /* Not found, try SPD data */
        int spd_size = 0;
        const void *spd_data = bdk_config_get_blob(&spd_size, BDK_CONFIG_DDR_SPD_DATA, 0 /* DIMM */, 0 /* LMC */, bdk_numa_master());
        if ((spd_data == NULL) || (spd_size == 0))
        {
            /* No dram config found, jump to the boot menu */
            is_misconfigured = 1;
            goto menu;
        }

    }

    if (MFG_SYSTEM_LEVEL_TEST)
    {
        bdk_bist_check();
        bdk_image_boot("/fatfs/init.bin", 0);
    }

    bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_WAITING_FOR_KEY);

    int boot_timeout = bdk_config_get_int(BDK_CONFIG_BOOT_MENU_TIMEOUT);
    printf("\nPress 'B' within %d seconds for boot menu\n", boot_timeout);
    int key;
    do
    {
        key = bdk_readline_getkey(boot_timeout * 1000000);
    } while ((key != -1) && (key != 'B') && (key != 'b'));

    if (key == -1)
    {
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_NO_BOOT_MENU_KEY);
        if (next_stage)
        {
            bdk_image_boot(next_stage, 0);

            printf("**********************************************************************\n");
            printf("* WARNING\n");
            printf("*\n");
            printf("* Next boot stage file is configured as:\n");
            printf("*    %s\n", next_stage);
            printf("* but loading the stage failed. Loading INIT instead.\n");
            printf("**********************************************************************\n");
        }

        bdk_image_boot("/fatfs/init.bin", 0);
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_LOAD_FAILED);
    }
    else
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_BOOT_MENU_KEY);

menu:
    boot_menu();
}

