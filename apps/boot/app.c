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
    while (1)
    {
        printf("\n");
        printf("============\n");
        printf("Boot Options\n");
        printf("============\n");
        if (!is_misconfigured)
            printf("B) Boot Normally\n"); // Hidden if no board configuration
        printf("S) Enter Setup\n");
        if (!is_misconfigured)
            printf("D) Enter Diagnostics\n"); // Hidden if no board configuration
        printf("E) Enter Diagnostics, skipping Setup\n");
        printf("F) Select Image from Flash\n");
        printf("X) Upload File using Xmodem\n");
        printf("\n");
        printf("Choice: ");
        int key = bdk_readline_getkey(-1);
        key = toupper(key);
        printf("%c\n", key);
        switch (key)
        {
            case 'B':
                bdk_image_boot("/fatfs/init.bin", 0);
                break;
            case 'S':
                bdk_image_boot("/fatfs/setup.bin", 0);
                break;
            case 'D':
                /* FIXME: Update config to boot diagnostics */
                bdk_image_boot("/fatfs/init.bin", 0);
                break;
            case 'E':
                bdk_image_boot("/fatfs/diagnostics.bin", 0);
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
        "Version: %s\n"
        "\n",
        version);
    bdk_boot_info_strapping(bdk_numa_master());

    /* Check if the board static manufacturing data is present */
    if (0)
        goto menu;

    /* Load the board static manufacturing data. Display the board data to the
        user */
    if (0)
        goto menu;

    /* Check if a board configuration "dev-tree/default.dtb" and load it */
    if (bdk_loadenv(NULL))
    {
        is_misconfigured = 1;
        goto menu;
    }

    if (MFG_SYSTEM_LEVEL_TEST)
    {
        bdk_bist_check();
    }

    /* If no DRAM config got the boot menu */
    const char *dram_config = bdk_brd_cfg_get_str(NULL, BDK_BRD_CFG_DRAM_NODE, node);
    if (dram_config == NULL)
    {
        is_misconfigured = 1;
        goto menu;
    }

    int boot_timeout = bdk_brd_cfg_get_int(3, "BOOT-MENU-TIMEOUT");
    printf("\nPress 'ESC' within %d seconds for boot menu\n", boot_timeout);
    int key;
    do
    {
        key = bdk_readline_getkey(boot_timeout * 1000000);
    } while ((key != -1) && (key != 27));

    if (key == -1)
        bdk_image_boot("/fatfs/init.bin", 0);

menu:
    boot_menu();
}

