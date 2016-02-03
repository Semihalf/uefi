#include <bdk.h>
#include "cs4224_api.h"
#include "cortina-bdk.h"
BDK_REQUIRE_DEFINE(CORTINA);

int bdk_cortina_get_fw_date(bdk_node_t node, int bus_id, int phy_id, int die_id,
                            uint16_t *date0, uint16_t *date1, uint16_t *date2)
{
    cs_uint32 slice = MK_SLICE(bus_id, phy_id, die_id);
    int rv;

    rv  = cs4224_reg_get(slice, CS4224_GLOBAL_UCODE_TIMESTAMP0, (cs_uint16 *) date0);
    rv |= cs4224_reg_get(slice, CS4224_GLOBAL_UCODE_TIMESTAMP1, (cs_uint16 *) date1);
    rv |= cs4224_reg_get(slice, CS4224_GLOBAL_UCODE_TIMESTAMP2, (cs_uint16 *) date2);
    return rv;
}

int bdk_cortina_print_ts(bdk_node_t node, int bus_id, int phy_id, int die_id)
{
    cs_uint16 date0, date1, date2;
    int rv;

    rv = bdk_cortina_get_fw_date(node, bus_id, phy_id, die_id, &date0, &date1, &date2);
    if( rv )
        printf("CORTINA: WARNING: bdk_cortina_get_fw_date() returned: %d\n", rv);
    printf("CORTINA: Firmware date stamps: 0x%x, 0x%x, 0x%x\n", date0, date1, date2);
    return rv;
}

int bdk_cortina_update_eeprom(bdk_node_t node, int bus_id, int phy_id, int chn_id,
                              const char *file_name)
{
    cs_uint32 slice = MK_SLICE(bus_id, phy_id, chn_id);
    int rv;

    rv = cs4224_ucode_data_prgm_from_file_bin(slice, file_name);
    if( rv != 0 )
    {
        printf("CORTINA: ERROR: firmware update failed, error code: %d\n", rv);
    }
    else
    {
        // Issue PHY hard RESET to re-read firmware image from EEPROM
        cs_uint32 die = slice & 0xFFFFFF00;

        /* reset die 0, which is always present */
        rv = cs4224_hard_reset_die(die);
        if (rv)
            printf("CORTINA: ERROR: Could not hard RESET after update, error code: %d\n", rv);
    }
    return rv;
}


#define CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE24_LSB 0x1AB0
#define CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE22_MSB 0x1AAD
#define CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE22_LSB 0x1AAC

static int bdk_cortina_wait_activity_completed(cs_uint32 slice, cs_uint16 reg)
{
    /* Wait for activity bit to clear */
    int timeout = 1000; /* in msec */
    cs_uint16 data;

    cs4224_reg_get_channel(slice, reg, &data);
    while ((data & 0x01) && timeout--)
    {
        CS_UDELAY(1000);
        cs4224_reg_get(slice, reg, &data);
    }
    if (timeout < 0)
    {
        printf("CORTINA: WARNING: Mode switch timed out.\n");
        return -1;
    }
    return 0;
}

#define MODE_STR(m) ((m) == 0x9 ? "FIBER " : (m) == 0x5 ? "COPPER" : " ---- ")
void bdk_cortina_show_phy_modes(bdk_node_t node, int bus_id, int phy_id)
{
    cs_uint16 mode_host;
    cs_uint16 mode_line;
    int ch;
    for (ch = 0; ch < 8; ch++)
    {
        cs_uint32 slice = MK_SLICE(bus_id, phy_id, ch);
        cs4224_reg_get_channel(slice, CS4224_PP_LINE_SDS_DSP_MSEQ_SPARE22_LSB, &mode_line);
        cs4224_reg_get_channel(slice, CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE22_LSB, &mode_host);
        printf("CORTINA: PHY %d (Channel %d) Mode: HOST %s (0x%04x)  -  LINE %s (0x0%04x)\n",
                        ch+1, ch, MODE_STR(mode_host), mode_host, MODE_STR(mode_line), mode_line);
    }
}

int bdk_cortina_switch_optical_mode_line(bdk_node_t node, int bus_id, int phy_id, int chn_id)
{
    cs_uint32 slice = MK_SLICE(bus_id, phy_id, chn_id);

    /* switch from DAC to SR mode */
    /* page 17 2.a */
    cs4224_reg_set_channel(slice, CS4224_PP_LINE_SDS_DSP_MSEQ_SPARE22_MSB, 0x0000);
    /* page 17 2.b */
    cs4224_reg_set_channel(slice, CS4224_PP_LINE_SDS_DSP_MSEQ_SPARE24_LSB, 0x0009);
    /* page 17 2.c (iii) */
    /* Wait for activity bit to clear */
    if (bdk_cortina_wait_activity_completed(slice, CS4224_PP_LINE_SDS_DSP_MSEQ_SPARE24_LSB))
    {
        printf("CORTINA: WARNING: Setting LINE side optical mode failed.\n");
        return -1;
    }
    return 0;
}

int bdk_cortina_switch_optical_mode_host(bdk_node_t node, int bus_id, int phy_id, int chn_id)
{
    cs_uint32 slice = MK_SLICE(bus_id, phy_id, chn_id);

    /* page 17 2.d */
    cs4224_reg_set_channel(slice, CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE22_MSB, 0x0000);
    /* page 17 2.e */
    cs4224_reg_set_channel(slice, CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE24_LSB, 0x0009);
    /* page 17 2.f(i) */
    /* Wait for activity bit to clear */
    if (bdk_cortina_wait_activity_completed(slice, CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE24_LSB))
    {
        printf("CORTINA: WARNING: Setting HOST side optical mode failed.\n");
        return -1;
    }
    return 0;
}

int bdk_cortina_switch_copper_mode_line(bdk_node_t node, int bus_id, int phy_id, int chn_id)
{
    cs_uint32 slice = MK_SLICE(bus_id, phy_id, chn_id);

    /* switch from DAC to SR mode */
    cs4224_reg_set_channel(slice, CS4224_PP_LINE_SDS_DSP_MSEQ_SPARE24_LSB, 0x0005);
    if (bdk_cortina_wait_activity_completed(slice, CS4224_PP_LINE_SDS_DSP_MSEQ_SPARE24_LSB))
    {
        printf("CORTINA: WARNING: Setting LINE side copper mode failed.\n");
        return -1;
    }
    return 0;
}

int bdk_cortina_switch_copper_mode_host(bdk_node_t node, int bus_id, int phy_id, int chn_id)
{
    cs_uint32 slice = MK_SLICE(bus_id, phy_id, chn_id);

    cs4224_reg_set_channel(slice, CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE24_LSB, 0x0005);
    if (bdk_cortina_wait_activity_completed(slice, CS4224_PP_HOST_SDS_DSP_MSEQ_SPARE24_LSB))
    {
        printf("CORTINA: WARNING: Setting HOST side copper mode failed.\n");
        return -1;
    }
    return 0;
}
