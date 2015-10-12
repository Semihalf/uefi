#include <bdk.h>

void menu_chip(bdk_menu_t *parent, char key, void *arg)
{
    bdk_menu_t menu;
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - Chip");
        bdk_menu_item(&menu, 'D', "Delay for Boot Menu", NULL, NULL);
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
