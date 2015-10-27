/**
 * Passed to menu_add_config() to add simple configuration items to menus. This
 * structure must not go out of scope until the menu is closed.
 */
struct menu_add_info
{
    char key;           /* Key user should press */
    const char *name;   /* Menu item name */
    const char *units;  /* Menu item units, or NULL if N/A */
    bdk_config_t config;/* Config entry matching this item */
    int is_num;         /* 0 for strings, 1 for decimal params, 2 for hex */
};

/**
 * It is common to have a menu entry change a single configuration parameter. This
 * function makes it convientent to add these entries.
 *
 * @param menu   Menu to add the item onto
 * @param info   Information about the configuration item being added
 */
void menu_add_config(bdk_menu_t *menu, const struct menu_add_info *info);

