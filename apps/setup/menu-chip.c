#include <bdk.h>
#include "menu-common.h"

void menu_chip(bdk_menu_t *parent, char key, void *arg)
{
    bdk_menu_t menu;
    const struct menu_add_info info[] =
    {
        { .key = 'D', .name = "Delay for Boot Menu", .config = BDK_CONFIG_BOOT_MENU_TIMEOUT,
            .is_num = 1, .units = "s" },
        { .key = 'N', .name = "Support Multi-node", .config = BDK_CONFIG_MULTI_NODE,
            .is_num = 1 },
        { .key = 'W', .name = "Watchdog Timeout", .config = BDK_CONFIG_WATCHDOG_TIMEOUT,
            .is_num = 1, .units = "ms" },
        { .key = 'T', .name = "BDK Tracing Level", .config = BDK_CONFIG_TRACE,
            .is_num = 2, .units = "bitmask" },
        { .key = 'C', .name = "BDK Allowed Coremask", .config = BDK_CONFIG_COREMASK,
            .is_num = 2, .units = "bitmask" },
        { .key = 0, },
    };
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - Chip");
        int i = 0;
        while (info[i].key)
        {
            menu_add_config(&menu, &info[i]);
            i++;
        }
        //bdk_menu_item(&menu, '8', "Support ARM v8.1 Extensions", NULL, NULL);
        //bdk_menu_item(&menu, 'I', "Support WFI Power Saving", NULL, NULL);
        //bdk_menu_item(&menu, 'E', "Support WFE Power Saving", NULL, NULL);
        //bdk_menu_item(&menu, 'P', "Support Core Power Gating", NULL, NULL);
        //bdk_menu_item(&menu, 'T', "Max Power Throttling", NULL, NULL);
        //bdk_menu_item(&menu, 'A', "Support PCI Enhanced Allocation", NULL, NULL);
        //bdk_menu_item(&menu, 'B', "Uart Console Baud Rate", NULL, NULL);
        //bdk_menu_item(&menu, 'F', "Uart Console Flow Control", NULL, NULL);
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
