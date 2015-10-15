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
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(DRAM_TEST);
    BDK_REQUIRE(ENVIRONMENT);
    BDK_REQUIRE(FS_BOOT);
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
    BDK_REQUIRE(FS_XMODEM);
    BDK_REQUIRE(MPI);
}

extern void menu_board(bdk_menu_t *menu, char key, void *arg);
extern void menu_chip(bdk_menu_t *menu, char key, void *arg);
extern void menu_dram(bdk_menu_t *menu, char key, void *arg);

void item_reboot(bdk_menu_t *menu, char key, void *arg)
{
    printf("Rebooting THUNDERX\n");
    bdk_reset_chip(bdk_numa_master());
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_watchdog_disable();
    bdk_boot_status_ok();

    bdk_menu_t menu;
    while (1)
    {
        bdk_menu_init(&menu, "THUNDERX Setup");
        bdk_menu_item(&menu, 'B', "Board Manufacturing Data", menu_board, NULL);
        bdk_menu_item(&menu, 'C', "Chip Features", menu_chip, NULL);
        bdk_menu_item(&menu, 'D', "DRAM Options", menu_dram, NULL);
        bdk_menu_item(&menu, 'R', "Reboot", item_reboot, NULL);
        bdk_menu_display(&menu);
    }
    return 0;
}
