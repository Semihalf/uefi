#include <bdk.h>

#include "driver/cortina-bdk.h"

#define ATF_ADDRESS 0x00400000

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(CCPI);
    BDK_REQUIRE(FS_BOOT);
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
    BDK_REQUIRE(FS_ROM);
    BDK_REQUIRE(MDIO);
    BDK_REQUIRE(ECAM);
    BDK_REQUIRE(DRIVER);

    BDK_REQUIRE(CORTINA);
}

#define CORTINA_INF_FILE_NAME   "/rom/cortina.inf"
#define CORTINA_INF_MAX_SIZE    128


#define CORTINA_BUS_ID      1
#define CORTINA_PHY_ID      0

#define MODULE_TWSI_ADDR        0x50

#define MODULE_MEDIA_NONE       0
#define MODULE_MEDIA_UNKNOWN    1
#define MODULE_MEDIA_FIBER      2
#define MODULE_MEDIA_COPPER     3
#define MODULE_MEDIA_RESERVED   4

/*
 * Value  Description of Media Connector
 *  00h   Unknown or unspecified
 *  01h   SC (Subscriber Connector)
 *  02h   Fibre Channel Style 1 copper connector
 *  03h   Fibre Channel Style 2 copper connector
 *  04h   BNC/TNC (Bayonet/Threaded Neill-Concelman)
 *  05h   Fibre Channel coax headers
 *  06h   Fiber Jack
 *  07h   LC (Lucent Connector)
 *  08h   MT-RJ (Mechanical Transfer - Registered Jack)
 *  09h   MU (Multiple Optical)
 *  0Ah   SG
 *  0Bh   Optical Pigtail
 *  0Ch   MPO 1x12 (Multifiber Parallel Optic)
 *  0Dh   MPO 2x16
 * -1Fh   Reserved
 *
 *  20h   HSSDC II (High Speed Serial Data Connector)
 *  21h   Copper pigtail
 *  22h   RJ45 (Registered Jack)
 *  23h   No separable connector
 *  24h   MXC 2x16
 * -7Fh Reserved
 *
 *  80h-FFh Vendor specific
 *
 *  Note: 01h to 05h are not SFP-compatible, and are included for
 *  compatibility with GBIC standards.
 *
 *  FFh is used to determine that no plug has been inserted.
 */
#define MODULE_MEDIA(id) \
            ( (id) == 0xFF)                    ? MODULE_MEDIA_NONE : \
            ( (id) == 0x00)                    ? MODULE_MEDIA_UNKNOWN : \
            (((id) >= 0x01) && ((id) <= 0x0D)) ? MODULE_MEDIA_FIBER : \
            (((id) >= 0x20) && ((id) <= 0x24)) ? MODULE_MEDIA_COPPER : \
                                                 MODULE_MEDIA_RESERVED

#define MEDIA_STR(t) \
            (t) == MODULE_MEDIA_NONE    ? "NONE" : \
            (t) == MODULE_MEDIA_UNKNOWN ? "UNKNOWN" : \
            (t) == MODULE_MEDIA_FIBER   ? "FIBER" : \
            (t) == MODULE_MEDIA_COPPER  ? "COPPER" : \
                                          "RESERVED or INVALID"

#define PORT_TYPE_NONE  0
#define PORT_TYPE_SFP   1
#define PORT_TYPE_QSFP  2

/* Board configuration of the boards */
struct port_config_d
{
    int        type;
    bdk_node_t node;
    int        twsi_bus;
    int        phy_channel[4];
};

static struct port_config_d port_cfg_crb_1s[] =
{
    /* Port type      Node TWSI PHY Channels  */
    { PORT_TYPE_SFP,  0,   2,   { 7, -1, -1, -1 }, }, /* SFP+ Port 0 */
    { PORT_TYPE_SFP,  0,   3,   { 6, -1, -1, -1 }, }, /* SFP+ Port 1 */
    { PORT_TYPE_QSFP, 0,   0,   { 0,  1,  2,  3 }, }, /* QSFP+ Port */
    { PORT_TYPE_NONE, 0,   0,   { 0,  0,  0,  0 }, },
};

static struct port_config_d port_cfg_crb_2s[] =
{
    /* Port type      Node TWSI PHY Channels  */
    { PORT_TYPE_SFP,  0,   3,   { 1, -1, -1, -1 }, }, /* SFP+ Port 0 */
    { PORT_TYPE_SFP,  1,   3,   { 0, -1, -1, -1 }, }, /* SFP+ Port 1 */
    { PORT_TYPE_QSFP, 0,   4,   { 4,  5,  6,  7 }, }, /* QSFP+ Port */
    { PORT_TYPE_NONE, 0,   0,   { 0,  0,  0,  0 }, },
};

static uint8_t cortina_get_module_type_id(bdk_node_t node, int twsi_port, uint8_t dev_addr, int port_type)
{
    /* QSFP+ data starts at offset 128 */
    int offset = (port_type == PORT_TYPE_SFP ? 0 : 128);
    return (uint8_t) bdk_twsix_read_ia(node, twsi_port, dev_addr, offset + 2, 1, 1);
}

static void cortina_check_fw_update(int force_update)
{
    bdk_node_t node = 0;
    int bus_id = CORTINA_BUS_ID;
    int phy_id = CORTINA_PHY_ID;

    FILE *fp = fopen(CORTINA_INF_FILE_NAME, "r");
    if (!fp)
    {
        printf("CORTINA: ERROR: Could not open file " CORTINA_INF_FILE_NAME ".\n");
        goto out;
    }

    /* Sanity check: File size
     * Note:
     *   SEEK_END is not supported, hence we manually count bytes in file. */
    int filesize = 0;
    while (EOF != fgetc(fp))
        filesize++;

    if (filesize >= CORTINA_INF_MAX_SIZE)
    {
        printf("CORTINA: ERROR: " CORTINA_INF_FILE_NAME " file to big (%d bytes). Aborting.\n",
                filesize);
        goto out;
    }
    rewind(fp);

    /* Read the data from the inf file. */
    char file_name[CORTINA_INF_MAX_SIZE];
    char mode[CORTINA_INF_MAX_SIZE];
    uint16_t file_day_month, file_year, file_time;
    uint16_t rom_day_month,  rom_year,  rom_time;

    int n = fscanf(fp, "%hx %hx %hx %s %s", &file_day_month, &file_year, &file_time, file_name, mode);
    if (n != 5)
    {
        printf("CORTINA: ERROR: Could not read " CORTINA_INF_FILE_NAME " file entries. Aborting.\n");
        goto out;
    }

    /* Check if 'date match' update is configured in the .inf file */
    int firmware_must_match = 0;

    if (0 == strcmp("match", mode))
    {
        printf("CORTINA: Firmware update on date mismatch is configured in " CORTINA_INF_FILE_NAME " file.\n");
        firmware_must_match = 1;
    }
    else if (0 != strcmp("auto", mode))
    {
        printf("CORTINA: WARNING: Unknown update mode '%s' in "
                CORTINA_INF_FILE_NAME " file. Assuming 'auto'\n", mode);
    }

    /* Get date stamps from Cortina ROM. */
    int rc = bdk_cortina_get_fw_date(node, bus_id, phy_id, 0 /* die */, &rom_day_month, &rom_year, &rom_time);
    if (rc)
    {
        printf("CORTINA: ERROR: Could not read ROM firmware date stamp (rc=%d). Aborting.\n", rc);
        goto out;
    }

    printf("CORTINA: Image file name is:   %s\n", file_name);
    printf("CORTINA: Image file date is:   0x%04x 0x%04x 0x%04x\n", file_day_month, file_year, file_time);
    printf("CORTINA: ROM firmware date is: 0x%04x 0x%04x 0x%04x\n", rom_day_month, rom_year, rom_time);

    /* Check if the image in the file is newer or different than the ROM image. */
    int firmware_newer = (file_year > rom_year) ||
                         ((file_year == rom_year) && (file_day_month > rom_day_month)) ||
                         ((file_year == rom_year) && (file_day_month == rom_day_month) && (file_time > rom_time));

    int firmware_different =
                         ((file_year != rom_year) || (file_day_month != rom_day_month) || (file_time != rom_time));

    if (firmware_newer || force_update || (firmware_must_match && firmware_different))
    {
        if (force_update)
            printf("CORTINA: Forcing Firmware Update...\n");
        else if (firmware_must_match)
            printf("CORTINA: Firmware date is not same as image. Updating...\n");
        else
            printf("CORTINA: Firmware is not up to date. Updating...\n");

        if (0 == bdk_cortina_update_eeprom(node, bus_id, phy_id, 0 /* channel */, file_name))
        {
            /* At this time the PHY has been hard RESET and re-read the EEPROM.
             * Check the date code again to see whether or not the image
             * actually made it onto the EEPROM. If it did not, it likely means
             * that the EEPROM's write enable jumper was not inserted.
             */
            bdk_cortina_get_fw_date(node, bus_id, phy_id, 0 /* die */, &rom_day_month, &rom_year, &rom_time);

            /* Check if the image in the file is newer than the ROM image. */
            firmware_different =
                         ((file_year != rom_year) || (file_day_month != rom_day_month) || (file_time != rom_time));
            if (firmware_different)
            {
                printf("\nCORTINA: **********************************************************************\n");
                printf("CORTINA: *\n");
                printf("CORTINA: * WARNING   WARNING   WARNING   WARNING   WARNING   WARNING\n");
                printf("CORTINA: *\n");
                printf("CORTINA: **********************************************************************\n");
                printf("CORTINA: *\n");
                printf("CORTINA: * The image was not written successfully to the EEPROM. It is\n");
                printf("CORTINA: * likely that the WRITE ENABLE JUMPER on the board has not been\n");
                printf("CORTINA: * set. Please check and set the jumper and reboot the system.\n");
                printf("CORTINA: *\n");
                printf("CORTINA: **********************************************************************\n");

                bdk_wait_usec(10 * 1000000);
            }
            else
            {
                printf("CORTINA: Update complete.\n");
            }
        }
        else
        {
            printf("CORTINA: Update FAILED.\n");
        }
    }
    else
    {
        printf("CORTINA: Firmware is up to date.\n");
    }

out:
    if (fp)
        fclose(fp);
}

static void cortina_port_autoconfigure()
{
    struct port_config_d *ports;

    int bus_id = CORTINA_BUS_ID;
    int phy_id = CORTINA_PHY_ID;

    /* Get the board type. At this point the cortina app only supports crb-1s
     * and crb-2s. We test for crb-1s and if it's not, we assume crb-2s.
     */
    const char *board = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
    if (0 == strcasecmp(board, "CRB-1S"))
    {
        ports = port_cfg_crb_1s;
    }
    else
    {
        board = "CRB-2S";
        ports = port_cfg_crb_2s;
    }
    printf("CORTINA: Assuming board type: %s\n", board);

    /* Scan ports and detect interface types. */
    printf("CORTINA: Scanning ports...\n");
    while (ports->type != PORT_TYPE_NONE)
    {
        uint8_t port_type_id = cortina_get_module_type_id(
                                ports->node, ports->twsi_bus, MODULE_TWSI_ADDR, ports->type);
        int media = MODULE_MEDIA(port_type_id);

        /* Skip ports that have no or unknown modules installed */
        if ((MODULE_MEDIA_NONE == media) || (MODULE_MEDIA_RESERVED == media))
        {
            if (ports->type == PORT_TYPE_QSFP)
            {
                media = MODULE_MEDIA_FIBER;
                printf("CORTINA: QSFP+ Module not found, assuming %s\n", MEDIA_STR(media));
            }
            else
            {
                ports++;
                continue;
            }
        }
        else
        {
            printf("CORTINA: Found %s module type ID 0x%02x: %s\n",
                                    ports->type == PORT_TYPE_SFP ? "SFP+" : "QSFP+",
                                    port_type_id, MEDIA_STR(media));
        }

        /* Configure PHY for port */
        int phy;
        for (phy = 0; phy < 4; phy++)
        {
            int ch = ports->phy_channel[phy];
            if (ch >= 0)
            {
                printf("CORTINA:         Configuring PHY %d (Channel %d) to %s mode.\n",
                                                    ch+1, ch, MEDIA_STR(media));
                if (MODULE_MEDIA_FIBER == media)
                    bdk_cortina_switch_optical_mode_line(ports->node, bus_id, phy_id, ch);
                else
                    bdk_cortina_switch_copper_mode_line(ports->node, bus_id, phy_id, ch);
            }
        }
        ports++;
    }
}

static void cortina_boot_next_stage()
{
    printf("\nCORTINA: Loading next stage...\n");

    /* Check if the next boot stage is configured. */
    const char *next_stage = bdk_config_get_str(BDK_CONFIG_BOOT_NEXT_STAGE, "CORTINA");
    if (next_stage)
        bdk_image_boot(next_stage, 0);

    /* Default: Boot into ATF */
    bdk_image_boot("/boot", ATF_ADDRESS);
    bdk_error("Unable to load image\n");
    printf("Trying diagnostics\n");

    /* Load Diagnostics from FAT fs */
    bdk_image_boot("/fatfs/diagnostics.bin", 0);
}

static void cortina_menu(void)
{
    int key;

    printf("CORTINA: Press 'M' within 2 seconds for Cortina menu\n");
    do
    {
        key = bdk_readline_getkey(2 * 1000000);
    } while ((key != -1) && (key != 'M') && (key != 'm'));

    if (key == -1)
        return;

    bdk_menu_t menu;
    while (1)
    {
        bdk_menu_init(&menu, "Cortina Options");
        bdk_menu_item(&menu, 'C', "Continue Normal Boot Process", NULL, NULL);
        bdk_menu_item(&menu, 'S', "Skip Cortina Configuration and Boot Next Stage", NULL, NULL);
        bdk_menu_item(&menu, 'A', "Run Port Autoconfiguration", NULL, NULL);
        bdk_menu_item(&menu, 'P', "Print Port Configuration", NULL, NULL);
        bdk_menu_item(&menu, 'D', "Print Firmware Date Stamp", NULL, NULL);
        bdk_menu_item(&menu, 'U', "Run Firmware Update Checker", NULL, NULL);
        bdk_menu_item(&menu, 'F', "Force Firmware Update", NULL, NULL);

        int key = bdk_menu_display(&menu);
        switch (key)
        {
            case 'C': /* Continue Normal Boot Process */
                return;
            case 'S': /* Boot Next Stage, skipping Cortina Configuration */
                cortina_boot_next_stage();
                break;
            case 'A': /* Run Port Autoconfiguration */
                cortina_port_autoconfigure();
                break;
            case 'P': /* Show PHY Modes */
                bdk_cortina_show_phy_modes(0 /*node */, CORTINA_BUS_ID, CORTINA_PHY_ID);
                break;
            case 'D': /* Print Firmware Date Stamp */
                bdk_cortina_print_ts(0 /* node */, CORTINA_BUS_ID, CORTINA_PHY_ID, 0 /* die */);
                break;
            case 'U': /* Run Firmware Update Checker */
                cortina_check_fw_update(0 /* don't force update */);
                break;
            case 'F': /* Force Firmware Update */
                cortina_check_fw_update(1 /* force update */);
                break;
            default:
                bdk_error("Invalid choice\n");
                break;
        }
    }
}

/**
 * Main entry point
 */
int main(int argc, const char **argv)
{
    /* Enable watchdog. Must be after loading the config so we know the
       watchdog timeout */
    bdk_watchdog_set(0);

    /* Check for menu key */
    cortina_menu();

    /* Check if we need a firmware update */
    printf("\nCORTINA: Running CORTINA PHY firmware updater...\n");
    cortina_check_fw_update(0 /* don't force update */);

/* Auto configuring modules is causing problems during system testing.
 * Disabling this feature for now until the root cause has been determined.
 *
 * We still want the PHY image updater, though, hence we are not disabling the
 * whole Cortina boot stage.
 */
#if 0
    /* Autoconfigure SFP+ and QSFP+ ports */
    printf("\nCORTINA: Running CORTINA PHY port auto configuration...\n");
    cortina_port_autoconfigure();
#endif

    cortina_boot_next_stage();
}
