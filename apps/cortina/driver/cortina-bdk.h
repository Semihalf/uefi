#ifndef __CORTINA_BDK_H__
#define __CORTINA_BDK_H__

#include <bdk.h>

/**
 * @file
 *
 * Cortina BDK driver api.
 *
 */

/* Make a CS api 'slice' from MDIO bus, phy and dev)  These are decoded
 * cs_rtos.c by the Thunder specific read/write functions. */
#define MK_SLICE(bus, phy, chn) (((bus & 0xff) << 24) | ((phy & 0xffff) << 8) | (chn & 0xff))

#define SLICE_TO_NODE(s) bdk_numa_local()
#define SLICE_TO_BUS(s)  (((s) >> 24) & 0xFF)
#define SLICE_TO_PHY(s)  (((s) >> 8 ) & 0xFFFF)
#define SLICE_TO_DIE(s)  ( (s)        & 0x01)

void dump_modes(bdk_node_t node, int bus_id, int phy_id);

int bdk_cortina_get_fw_date(bdk_node_t node, int bus_id, int phy_id, int die_id,
                            uint16_t *rom_day_month, uint16_t *rom_year, uint16_t *rom_time);
int bdk_cortina_print_ts(bdk_node_t node, int bus_id, int phy_id, int die_id);
int bdk_cortina_update_eeprom(bdk_node_t node, int bus_id, int phy_id, int chn_id,
                              const char *file_name);

void bdk_cortina_show_phy_modes(bdk_node_t node, int bus_id, int phy_id);
int bdk_cortina_switch_optical_mode_line(bdk_node_t node, int bus_id, int phy_id, int chn_id);
int bdk_cortina_switch_optical_mode_host(bdk_node_t node, int bus_id, int phy_id, int chn_id);
int bdk_cortina_switch_copper_mode_line(bdk_node_t node, int bus_id, int phy_id, int chn_id);
int bdk_cortina_switch_copper_mode_host(bdk_node_t node, int bus_id, int phy_id, int chn_id);

#endif
