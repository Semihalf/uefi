#include <bdk.h>
#include <ctype.h>

#ifndef MFG_SYSTEM_LEVEL_TEST
#define MFG_SYSTEM_LEVEL_TEST 0
#endif

/* This variable gets set to non-zero if any configuration error is detected
   such that we can't proceed through the normal boot path */
static int is_misconfigured = 0;

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
    bdk_boot_status_ok();
    bdk_menu_t menu;
    while (1)
    {
        bdk_menu_init(&menu, "Boot Options");
        if (!is_misconfigured) // Hidden if no board configuration
            bdk_menu_item(&menu, 'N', "Boot Normally", NULL, NULL);
        bdk_menu_item(&menu, 'S', "Enter Setup", NULL, NULL);
        if (!is_misconfigured) // Hidden if no board configuration
            bdk_menu_item(&menu, 'D', "Enter Diagnostics", NULL, NULL);
        bdk_menu_item(&menu, 'E', "Enter Diagnostics, skipping Setup", NULL, NULL);
        bdk_menu_item(&menu, 'F', "Select Image from Flash", NULL, NULL);
        bdk_menu_item(&menu, 'X', "Upload File to FatFS using Xmodem", NULL, NULL);
        bdk_menu_item(&menu, 'W', "Burn boot flash using Xmodem", NULL, NULL);
        bdk_menu_item(&menu, 'U', "Change baud rate and flow control", NULL, NULL);
        bdk_menu_item(&menu, 'R', "Reboot", NULL, NULL);

        switch (bdk_menu_display(&menu))
        {
            case 'N':
                bdk_image_boot("/fatfs/init.bin", 0, 0); /* Boot normally */
                break;
            case 'S':
                bdk_image_boot("/fatfs/setup.bin", 0, 0);
                break;
            case 'D':
                bdk_image_boot("/fatfs/init.bin", 0, 1); /* Boot diagnostics */
                break;
            case 'E':
                bdk_image_boot("/fatfs/diagnostics.bin", 0, 0);
                break;
            case 'F':
                bdk_image_choose("BOOT:");
                break;
            case 'X':
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
            case 'W':
            {
                bdk_xmodem_upload("/boot", 0);
                break;
            }
            case 'U':
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
            case 'R':
                printf("Rebooting THUNDERX\n");
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

    /* Get the address of the version field in our header */
    uint64_t version_offset = offsetof(bdk_image_header_t, version);
    uint64_t version_pa = bdk_numa_get_address(node, version_offset);
    const char *version = bdk_phys_to_ptr(version_pa);

    printf(
        "=========================\n"
        "Cavium THUNDERX Boot Stub\n"
        "=========================\n"
        "Firmware Version: %s\n"
        "BDK Version: %s\n"
        "\n"
        "Board Model:    %s\n"
        "Board Revision: %s\n"
        "Board Serial:   %s\n"
        "\n",
        version,
        bdk_version_string(),
        bdk_config_get_str(BDK_CONFIG_BOARD_MODEL),
        bdk_config_get_str(BDK_CONFIG_BOARD_REVISION),
        bdk_config_get_str(BDK_CONFIG_BOARD_SERIAL));
    bdk_boot_info_strapping(bdk_numa_master());

    if (MFG_SYSTEM_LEVEL_TEST)
    {
        bdk_bist_check();
        bdk_image_boot("/fatfs/init.bin", 0, 0);
    }

    /* If no DRAM config got the boot menu */
    const char *dram_config = bdk_config_get_str(BDK_CONFIG_DRAM_NODE, node);
    if ((dram_config == NULL) && !bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        is_misconfigured = 1;
        goto menu;
    }

    int boot_timeout = bdk_config_get_int(BDK_CONFIG_BOOT_MENU_TIMEOUT);
    printf("\nPress 'B' within %d seconds for boot menu\n", boot_timeout);
    int key;
    do
    {
        key = bdk_readline_getkey(boot_timeout * 1000000);
    } while ((key != -1) && (key != 'B') && (key != 'b'));

    if (key == -1)
        bdk_image_boot("/fatfs/init.bin", 0, 0);

menu:
    boot_menu();
}

