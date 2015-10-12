#include <bdk.h>

void menu_board(bdk_menu_t *parent, char key, void *arg)
{
    bdk_menu_t menu;
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - Board");
        bdk_menu_item(&menu, 'B', "Board Model Number", NULL, NULL);
        bdk_menu_item(&menu, 'R', "Board Revision", NULL, NULL);
        bdk_menu_item(&menu, 'S', "Serial Number", NULL, NULL);
        bdk_menu_item(&menu, 'M', "Base MAC Address", NULL, NULL);
        bdk_menu_item(&menu, 'N', "Number of MAC Addresses", NULL, NULL);
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
