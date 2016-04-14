#include <bdk.h>
#include "menu-common.h"

void menu_power(bdk_menu_t *parent, char key, void *arg)
{
    bdk_menu_t menu;
    const struct menu_add_info info[] =
    {
        { .key = 'T', .name = "Thermal Trip Temperature", .config = BDK_CONFIG_VRM_TEMP_TRIP,
            .is_num = 1, .units = "C", .param = MENU_PARAM_NODE },
        { .key = 'H', .name = "Maximum Operating Temperature", .config = BDK_CONFIG_VRM_TEMP_HIGH,
            .is_num = 1, .units = "C", .param = MENU_PARAM_NODE },
        { .key = 'L', .name = "Normal Operating Temperature", .config = BDK_CONFIG_VRM_TEMP_LOW,
            .is_num = 1, .units = "C", .param = MENU_PARAM_NODE },
        { .key = 'M', .name = "Maximum Operating Throttle", .config = BDK_CONFIG_VRM_THROTTLE_THERM,
            .is_num = 1, .units = "%", .param = MENU_PARAM_NODE },
        { .key = 'N', .name = "Normal Operating Throttle", .config = BDK_CONFIG_VRM_THROTTLE_NORMAL,
            .is_num = 1, .units = "%", .param = MENU_PARAM_NODE },
        { .key = 0, },
    };
    do
    {
        bdk_menu_init(&menu, "Setup - Power");
        int i = 0;
        while (info[i].key)
        {
            menu_add_config(&menu, &info[i]);
            i++;
        }
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
