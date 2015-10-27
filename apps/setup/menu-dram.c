#include <bdk.h>
#include "menu-common.h"

void menu_dram(bdk_menu_t *parent, char key, void *arg)
{
    bdk_menu_t menu;
    const struct menu_add_info info[] =
    {
        { .key = 'V', .name = "DRAM Verbose level", .config = BDK_CONFIG_DRAM_VERBOSE,
            .is_num = 1 },
        { .key = 0, },
    };
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - DRAM");
        int i = 0;
        while (info[i].key)
        {
            menu_add_config(&menu, &info[i]);
            i++;
        }
        bdk_menu_item(&menu, 'N', "Number of LMC Controllers", NULL, NULL);
        bdk_menu_item(&menu, 'D', "DRAM Type", NULL, NULL);
        bdk_menu_item(&menu, 'A', "DIMM SPD Addresses", NULL, NULL);
        bdk_menu_item(&menu, 'S', "DRAM Speed", NULL, NULL);
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
