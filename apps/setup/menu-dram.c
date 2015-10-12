#include <bdk.h>

void menu_dram(bdk_menu_t *parent, char key, void *arg)
{
    bdk_menu_t menu;
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - DRAM");
        bdk_menu_item(&menu, 'N', "Number of LMC Controllers", NULL, NULL);
        bdk_menu_item(&menu, 'D', "DRAM Type", NULL, NULL);
        bdk_menu_item(&menu, 'A', "DIMM SPD Addresses", NULL, NULL);
        bdk_menu_item(&menu, 'S', "DRAM Speed", NULL, NULL);
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
