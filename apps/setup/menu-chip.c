#include <bdk.h>

static void item_boot_delay(bdk_menu_t *parent, char key, void *arg)
{
    const char *str = bdk_readline("Delay for boot menu (seconds): ", NULL, 0);
    int v = 0;
    int count = sscanf(str, "%i", &v);
    if (count == 1)
        bdk_config_set_int(v, BDK_CONFIG_BOOT_MENU_TIMEOUT);
    else
        bdk_error("Inavlid input\n");
}

void menu_chip(bdk_menu_t *parent, char key, void *arg)
{
    char str[64];
    bdk_menu_t menu;
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - Chip");

        snprintf(str, sizeof(str), "Delay for Boot Menu (%ld seconds)", bdk_config_get_int(BDK_CONFIG_BOOT_MENU_TIMEOUT));
        bdk_menu_item(&menu, 'D', str, item_boot_delay, NULL);

        bdk_menu_item(&menu, '8', "Support ARM v8.1 Extensions", NULL, NULL);
        bdk_menu_item(&menu, 'I', "Support WFI Power Saving", NULL, NULL);
        bdk_menu_item(&menu, 'E', "Support WFE Power Saving", NULL, NULL);
        bdk_menu_item(&menu, 'P', "Support Core Power Gating", NULL, NULL);
        bdk_menu_item(&menu, 'T', "Max Power Throttling", NULL, NULL);
        bdk_menu_item(&menu, 'N', "Support Multi-node", NULL, NULL);
        bdk_menu_item(&menu, 'A', "Support PCI Enhanced Allocation", NULL, NULL);
        bdk_menu_item(&menu, 'B', "Uart Console Baud Rate", NULL, NULL);
        bdk_menu_item(&menu, 'F', "Uart Console Flow Control", NULL, NULL);
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
