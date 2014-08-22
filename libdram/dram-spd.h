/**
 * Functions, enumarations, and structures related to DIMM SPDs.
 * Everything in this file is internal to libdram.
 */

/* data field addresses in the DDR2 SPD eeprom */
typedef enum ddr2_spd_addrs {
    DDR2_SPD_BYTES_PROGRAMMED	= 0,
    DDR2_SPD_TOTAL_BYTES	= 1,
    DDR2_SPD_MEM_TYPE		= 2,
    DDR2_SPD_NUM_ROW_BITS	= 3,
    DDR2_SPD_NUM_COL_BITS	= 4,
    DDR2_SPD_NUM_RANKS		= 5,
    DDR2_SPD_CYCLE_CLX		= 9,
    DDR2_SPD_CONFIG_TYPE	= 11,
    DDR2_SPD_REFRESH		= 12,
    DDR2_SPD_SDRAM_WIDTH	= 13,
    DDR2_SPD_BURST_LENGTH	= 16,
    DDR2_SPD_NUM_BANKS		= 17,
    DDR2_SPD_CAS_LATENCY	= 18,
    DDR2_SPD_DIMM_TYPE		= 20,
    DDR2_SPD_CYCLE_CLX1		= 23,
    DDR2_SPD_CYCLE_CLX2		= 25,
    DDR2_SPD_TRP		= 27,
    DDR2_SPD_TRRD 		= 28,
    DDR2_SPD_TRCD 		= 29,
    DDR2_SPD_TRAS 		= 30,
    DDR2_SPD_TWR 		= 36,
    DDR2_SPD_TWTR 		= 37,
    DDR2_SPD_TRFC_EXT		= 40,
    DDR2_SPD_TRFC 		= 42,
    DDR2_SPD_CHECKSUM		= 63,
    DDR2_SPD_MFR_ID		= 64
} ddr2_spd_addr_t;

/* data field addresses in the DDR2 SPD eeprom */
typedef enum ddr3_spd_addrs {
    DDR3_SPD_BYTES_PROGRAMMED				=  0,
    DDR3_SPD_REVISION					=  1,
    DDR3_SPD_KEY_BYTE_DEVICE_TYPE			=  2,
    DDR3_SPD_KEY_BYTE_MODULE_TYPE			=  3,
    DDR3_SPD_DENSITY_BANKS				=  4,
    DDR3_SPD_ADDRESSING_ROW_COL_BITS			=  5,
    DDR3_SPD_NOMINAL_VOLTAGE				=  6,
    DDR3_SPD_MODULE_ORGANIZATION			=  7,
    DDR3_SPD_MEMORY_BUS_WIDTH				=  8,
    DDR3_SPD_FINE_TIMEBASE_DIVIDEND_DIVISOR		=  9,
    DDR3_SPD_MEDIUM_TIMEBASE_DIVIDEND			= 10,
    DDR3_SPD_MEDIUM_TIMEBASE_DIVISOR			= 11,
    DDR3_SPD_MINIMUM_CYCLE_TIME_TCKMIN			= 12,
    DDR3_SPD_CAS_LATENCIES_LSB				= 14,
    DDR3_SPD_CAS_LATENCIES_MSB				= 15,
    DDR3_SPD_MIN_CAS_LATENCY_TAAMIN			= 16,
    DDR3_SPD_MIN_WRITE_RECOVERY_TWRMIN			= 17,
    DDR3_SPD_MIN_RAS_CAS_DELAY_TRCDMIN			= 18,
    DDR3_SPD_MIN_ROW_ACTIVE_DELAY_TRRDMIN		= 19,
    DDR3_SPD_MIN_ROW_PRECHARGE_DELAY_TRPMIN		= 20,
    DDR3_SPD_UPPER_NIBBLES_TRAS_TRC			= 21,
    DDR3_SPD_MIN_ACTIVE_PRECHARGE_LSB_TRASMIN		= 22,
    DDR3_SPD_MIN_ACTIVE_REFRESH_LSB_TRCMIN		= 23,
    DDR3_SPD_MIN_REFRESH_RECOVERY_LSB_TRFCMIN		= 24,
    DDR3_SPD_MIN_REFRESH_RECOVERY_MSB_TRFCMIN           = 25,
    DDR3_SPD_MIN_INTERNAL_WRITE_READ_CMD_TWTRMIN        = 26,
    DDR3_SPD_MIN_INTERNAL_READ_PRECHARGE_CMD_TRTPMIN    = 27,
    DDR3_SPD_UPPER_NIBBLE_TFAW                          = 28,
    DDR3_SPD_MIN_FOUR_ACTIVE_WINDOW_TFAWMIN             = 29,
    DDR3_SPD_MINIMUM_CYCLE_TIME_FINE_TCKMIN		= 34,
    DDR3_SPD_MIN_CAS_LATENCY_FINE_TAAMIN		= 35,
    DDR3_SPD_MIN_RAS_CAS_DELAY_FINE_TRCDMIN		= 36,
    DDR3_SPD_MIN_ROW_PRECHARGE_DELAY_FINE_TRPMIN	= 37,
    DDR3_SPD_MIN_ACTIVE_REFRESH_LSB_FINE_TRCMIN		= 38,
    DDR3_SPD_ADDRESS_MAPPING                            = 63,
    DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE      = 126,
    DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE      = 127
} ddr3_spd_addr_t;

extern int read_spd(bdk_node_t node, const dimm_config_t *dimm_config,
    int dimm_index, int spd_field);
extern int validate_dimm(bdk_node_t node, const dimm_config_t *dimm_config,
    int dimm_index);
extern void report_ddr3_dimm(bdk_node_t node, const dimm_config_t *dimm_config,
    int upper_dimm, int dimm);

