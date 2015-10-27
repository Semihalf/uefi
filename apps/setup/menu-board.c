#include <bdk.h>
#include <libfdt.h>

static void prompt_board_model(bdk_menu_t *parent, char key, void *arg)
{
    const char *str = bdk_readline("Board Model: ", NULL, 0);
    if (str[0])
        bdk_config_set_str(str, BDK_CONFIG_BOARD_MODEL);
}

static void prompt_board_revision(bdk_menu_t *parent, char key, void *arg)
{
    const char *str = bdk_readline("Board Revision: ", NULL, 0);
    if (str[0])
        bdk_config_set_str(str, BDK_CONFIG_BOARD_REVISION);
}

static void prompt_board_serial(bdk_menu_t *parent, char key, void *arg)
{
    const char *str = bdk_readline("Board Serial: ", NULL, 0);
    if (str[0])
        bdk_config_set_str(str, BDK_CONFIG_BOARD_SERIAL);
}

static void prompt_board_mac(bdk_menu_t *parent, char key, void *arg)
{
    const char *str = bdk_readline("Board MAC Address: ", NULL, 0);
    long v = 0;
    int count = sscanf(str, "%li", &v);
    if (count == 1)
        bdk_config_set_int(v, BDK_CONFIG_MAC_ADDRESS);
}

static void prompt_board_mac_num(bdk_menu_t *parent, char key, void *arg)
{
    const char *str = bdk_readline("Board Number of MAC Addresses: ", NULL, 0);
    int v = 0;
    int count = sscanf(str, "%i", &v);
    if (count == 1)
        bdk_config_set_int(v, BDK_CONFIG_MAC_ADDRESS_NUM);
}

static void write_board_fdt(bdk_menu_t *parent, char key, void *arg)
{
    const int FDT_SIZE = 0x10000;
    void *fdt = calloc(1, FDT_SIZE);
    if (!fdt)
    {
        bdk_error("Unable to allocate memory for FDT\n");
        return;
    }
    if (fdt_create_empty_tree(fdt, FDT_SIZE) < 0)
    {
        bdk_error("Unable to create FDT for board\n");
        return;
    }
    int chosen = fdt_add_subnode(fdt, 0, "chosen");
    if (chosen < 0)
    {
        bdk_error("Unable to create chosen node in FDT\n");
        return;
    }
    int node = fdt_add_subnode(fdt, chosen, "cavium-bdk");
    if (node < 0)
    {
        bdk_error("Unable to create cavium-bdk node in FDT\n");
        return;
    }

    const char *model = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
    const char *revision = bdk_config_get_str(BDK_CONFIG_BOARD_REVISION);
    const char *serial = bdk_config_get_str(BDK_CONFIG_BOARD_SERIAL);
    int64_t mac = bdk_config_get_int(BDK_CONFIG_MAC_ADDRESS);
    int64_t num_mac = bdk_config_get_int(BDK_CONFIG_MAC_ADDRESS_NUM);
    char str[20];

    int status = fdt_setprop_string(fdt, node, "BOARD-MODEL", model);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return;
    }

    status = fdt_setprop_string(fdt, node, "BOARD-REVISION", revision);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return;
    }

    status = fdt_setprop_string(fdt, node, "BOARD-SERIAL", serial);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return;
    }

    snprintf(str, sizeof(str), "0x%lx", mac);
    status = fdt_setprop_string(fdt, node, "BOARD-MAC-ADDRESS", str);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return;
    }

    snprintf(str, sizeof(str), "%ld", num_mac);
    status = fdt_setprop_string(fdt, node, "BOARD-MAC-ADDRESS-NUM", str);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return;
    }
    status = fdt_pack(fdt);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return;
    }

    /* Calculate a CRC32 of the FDT */
    int fdt_size = fdt_totalsize(fdt);
    uint32_t crc32 = bdk_crc32(fdt, fdt_size, 0);

    FILE *outf = fopen("/boot", "wb");
    if (!outf)
    {
        bdk_error("Failed to open flash");
        return;
    }
    fseek(outf, BDK_CONFIG_MANUFACTURING_ADDRESS, SEEK_SET);
    if (fwrite(fdt, fdt_size, 1, outf) != 1)
        bdk_error("Failed to write flash");
    /* Save the CRC32 in the same endianness as the FDT */
    crc32 = cpu_to_fdt32(crc32);
    if (fwrite(&crc32, sizeof(crc32), 1, outf) != 1)
        bdk_error("Failed to write flash");
    fclose(outf);
    free(fdt);
}

void menu_board(bdk_menu_t *parent, char key, void *arg)
{
    char str[64];
    bdk_menu_t menu;
    do
    {
        bdk_menu_init(&menu, "THUNDERX Setup - Board");

        const char *model = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
        const char *revision = bdk_config_get_str(BDK_CONFIG_BOARD_REVISION);
        const char *serial = bdk_config_get_str(BDK_CONFIG_BOARD_SERIAL);
        int64_t mac = bdk_config_get_int(BDK_CONFIG_MAC_ADDRESS);
        int64_t num_mac = bdk_config_get_int(BDK_CONFIG_MAC_ADDRESS_NUM);

        snprintf(str, sizeof(str), "Board Model Number (%s)", model);
        bdk_menu_item(&menu, 'B', str, prompt_board_model, NULL);

        snprintf(str, sizeof(str), "Board Revision (%s)", revision);
        bdk_menu_item(&menu, 'R', str, prompt_board_revision, NULL);

        snprintf(str, sizeof(str), "Serial Number (%s)", serial);
        bdk_menu_item(&menu, 'S', str, prompt_board_serial, NULL);

        snprintf(str, sizeof(str), "Base MAC Address (0x%lx)", mac);
        bdk_menu_item(&menu, 'M', str, prompt_board_mac, NULL);

        snprintf(str, sizeof(str), "Number of MAC Addresses (%d)", (int)num_mac);
        bdk_menu_item(&menu, 'N', str, prompt_board_mac_num, NULL);

        bdk_menu_item(&menu, 'W', "Save to Flash", write_board_fdt, NULL);
        bdk_menu_item(&menu, 'Q', "Return to main menu", NULL, NULL);
        key = bdk_menu_display(&menu);
    } while (key != 'Q');
}
