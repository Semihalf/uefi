#include <bdk.h>
#include <stdarg.h>
#include <libfdt.h>

typedef enum
{
    BDK_CONFIG_TYPE_INT,
    BDK_CONFIG_TYPE_STR,
    BDK_CONFIG_TYPE_STR_LIST,
} bdk_config_type_t;

typedef struct
{
    const char *format;     /* Printf style format string to create the item name */
    const bdk_config_type_t ctype;/* Type of this item */
    int64_t default_value;  /* Default value when no present. String defaults are cast to pointers from this */
    const int64_t min_value;/* Minimum valid value for INT parameters. Unused for Strings */
    const int64_t max_value;/* Maximum valid value for INT parameters. Unused for Strings */
} bdk_config_info_t;

/* Tracing defaults to the level specified here before config files are loaded */
uint64_t bdk_trace_enables = 0;

/* Global variables that contain the config inside a FDT */
static void *config_fdt;
static int config_node;

static bdk_config_info_t config_info[__BDK_CONFIG_END] = {
    /* Board manufacturing data */
    [BDK_CONFIG_BOARD_MODEL] = {
        .format = "BOARD-MODEL", /* String, No parameters */
        .ctype = BDK_CONFIG_TYPE_STR,
        .default_value = (long)"unknown",
    },
    [BDK_CONFIG_BOARD_REVISION] = {
        .format = "BOARD-REVISION", /* String, No parameters */
        .ctype = BDK_CONFIG_TYPE_STR,
        .default_value = (long)"unknown",
    },
    [BDK_CONFIG_BOARD_SERIAL] = {
        .format = "BOARD-SERIAL", /* String, No parameters */
        .ctype = BDK_CONFIG_TYPE_STR,
        .default_value = (long)"unknown",
    },
    [BDK_CONFIG_MAC_ADDRESS] = {
        .format = "BOARD-MAC-ADDRESS", /* Int64, No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Default updated at boot based on fuses */
        .min_value = 0,
        .max_value = 0xffffffffffffll,
    },
    [BDK_CONFIG_MAC_ADDRESS_NUM] = {
        .format = "BOARD-MAC-ADDRESS-NUM", /* Int, No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 256,
    },

    /* Board generic */
    [BDK_CONFIG_BMC_TWSI] = {
        .format = "BMC-TWSI", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* TWSI bus number, -1 = disabled */
        .min_value = -1,
        .max_value = 5,
    },
    [BDK_CONFIG_WATCHDOG_TIMEOUT] = {
        .format = "WATCHDOG-TIMEOUT", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = disabled */
        .min_value = 0,
        .max_value = 10000,
    },
    [BDK_CONFIG_TWSI_WRITE] = {
        .format = "TWSI-WRITE", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_STR_LIST,
    },
    [BDK_CONFIG_MDIO_WRITE] = {
        .format = "MDIO-WRITE", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_STR_LIST,
    },

    /* Board wiring of network ports and PHYs */
    [BDK_CONFIG_PHY_ADDRESS] = {
        .format = "PHY-ADDRESS.N%d.BGX%d.P%d", /* Parameters: Node, Interface, Port */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default to no PHY */
        .min_value = -1,
        .max_value = 0xffffffffll,
    },
    [BDK_CONFIG_BGX_ENABLE] = {
        .format = "BGX-ENABLE.N%d.BGX%d.P%d", /* Parameters: Node, BGX, Port */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1, /* 0 = disable, 1 = enable */
        .min_value = 0,
        .max_value = 1,
    },

    /* BDK Configuration params */
    [BDK_CONFIG_NUM_PACKET_BUFFERS] = {
        .format = "BDK-NUM-PACKET-BUFFERS",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Default updated at boot */
        .min_value = 0,
        .max_value = 1000000,
    },
    [BDK_CONFIG_PACKET_BUFFER_SIZE] = {
        .format = "BDK-PACKET-BUFFER-SIZE",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1024, /* bytes */
        .min_value = 128,
        .max_value = 32768,
    },
    [BDK_CONFIG_SHOW_LINK_STATUS] = {
        .format = "BDK-SHOW-LINK-STATUS",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1, /* 0 = off, 1 = on */
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_COREMASK] = {
        .format = "BDK-COREMASK",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Zero means all cores */
        .min_value = 0,
        .max_value = 0xffffffffffffll,
    },
    [BDK_CONFIG_BOOT_MENU_TIMEOUT] = {
        .format = "BDK-BOOT-MENU-TIMEOUT",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 10, /* seconds */
        .min_value = 0,
        .max_value = 300,
    },
    [BDK_CONFIG_BOOT_PATH_OPTION] = {
        .format = "BDK-BOOT-PATH-OPTION",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = normal, 1 = diagnostics */
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_TRACE] = {
        .format = "BDK-CONFIG-TRACE",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* bitmask */
        .min_value = 0,
        .max_value = 0x7fffffffffffffffull,
    },

    /* Chip feature items */
    [BDK_CONFIG_MULTI_NODE] = {
        .format = "MULTI-NODE", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 2, /* 2 = Auto */
        .min_value = 0,
        .max_value = 2,
    },
    [BDK_CONFIG_PCIE_EA] = {
        .format = "PCIE-ENHANCED-ALLOCATION", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1, /* 1 = EA supported, 0 = EA not supported */
        .min_value = 0,
        .max_value = 1,
    },

    /* QLM related config */
    [BDK_CONFIG_QLM_AUTO_CONFIG] = {
        .format = "QLM-AUTO-CONFIG", /* Parameters: Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = off, 1 = on */
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_QLM_MODE] = {
        .format = "QLM-MODE.N%d.QLM%d", /* Parameters: Node, QLM */
        .ctype = BDK_CONFIG_TYPE_STR,
    },
    [BDK_CONFIG_QLM_FREQ] = {
        .format = "QLM-FREQ.N%d.QLM%d", /* Parameters: Node, QLM */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Mhz */
        .min_value = 0,
        .max_value = 10312,
    },
    [BDK_CONFIG_QLM_CLK] = {
        .format = "QLM-CLK.N%d.QLM%d", /* Parameters: Node, QLM */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 2, /* 2 = External */
        .min_value = 0,
        .max_value = 2,
    },
    [BDK_CONFIG_QLM_TUNING_TX_SWING] = {
        .format = "QLM-TUNING-TX-SWING.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 31,
    },
    [BDK_CONFIG_QLM_TUNING_TX_PREMPTAP] = {
        .format = "QLM-TUNING-TX-PREMPTAP.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 511,
    },
    [BDK_CONFIG_QLM_TUNING_TX_GAIN] = {
        .format = "QLM-TUNING-TX-GAIN.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 7,
    },
    [BDK_CONFIG_QLM_TUNING_TX_VBOOST] = {
        .format = "QLM-TUNING-TX-VBOOST.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 1,
    },

    /* DRAM configuration options */
    [BDK_CONFIG_DRAM_NODE] = {
        .format = "DDR-CONFIG.N%d", /* Parameters: Node */
        .ctype = BDK_CONFIG_TYPE_STR,
    },
    [BDK_CONFIG_DDR_SPEED] = {
        .format = "DDR-SPEED.N%d", /* Parameters: Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* In MT/s */
        .min_value = 0,
        .max_value = 2400,
    },
    [BDK_CONFIG_DDR_ALT_REFCLK] = {
        .format = "DDR-ALT-REFCLK.N%d", /* Parameters: Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Mhz */
        .min_value = 0,
        .max_value = 100,
    },
    [BDK_CONFIG_DDR_SPD_ADDR] = {
        .format = "DDR-CONFIG-SPD-ADDR.DIMM%d.LMC%d.N%d", /* Parameters: DIMM, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_SPD_DATA] = {
        .format = "DDR-CONFIG-SPD-DATA.DIMM%d.LMC%d.N%d", /* Parameters: DIMM, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_STR,
    },
    [BDK_CONFIG_DDR_RANKS_DQX_CTL] = {
        .format = "DDR-CONFIG-DQX-CTL.RANKS%d.DIMMS%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xf,
    },
    [BDK_CONFIG_DDR_RANKS_WODT_MASK] = {
        .format = "DDR-CONFIG-WODT-MASK.RANKS%d.DIMMS%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xfffffff,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_PASR] = {
        .format = "DDR-CONFIG-MODE1-PASR.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x7,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_ASR] = {
        .format = "DDR-CONFIG-MODE1-ASR.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_SRT] = {
        .format = "DDR-CONFIG-MODE1-SRT.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR] = {
        .format = "DDR-CONFIG-MODE1-RTT-WR.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT, // Split for extension bit
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x7,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_DIC] = {
        .format = "DDR-CONFIG-MODE1-DIC.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x3,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM] = {
        .format = "DDR-CONFIG-MODE1-RTT-NOM.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x7,
    },
    [BDK_CONFIG_DDR_RANKS_MODE1_DB_OUTPUT_IMPEDANCE] = {
        .format = "DDR-CONFIG-MODE1-DB-OUTPUT-IMPEDANCE.RANKS%d.DIMMS%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT, // Not per RANK, only one
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x7,
    },
    [BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK] = {
        .format = "DDR-CONFIG-MODE2-RTT-PARK.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x7,
    },
    [BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE] = {
        .format = "DDR-CONFIG-MODE2-VREF-VALUE.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0x3f,
    },
    [BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE] = {
        .format = "DDR-CONFIG-MODE2-VREF-RANGE.RANKS%d.DIMMS%d.RANK%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_RANKS_MODE2_VREFDQ_TRAIN_EN] = {
        .format = "DDR-CONFIG-MODE2-VREFDQ-TRAIN-EN.RANKS%d.DIMMS%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT, // Not per RANK, only one
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },

    [BDK_CONFIG_DDR_RANKS_RODT_CTL] = {
        .format = "DDR-CONFIG-RODT-CTL.RANKS%d.DIMMS%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xf,
    },
    [BDK_CONFIG_DDR_RANKS_RODT_MASK] = {
        .format = "DDR-CONFIG-RODT-MASK.RANKS%d.DIMMS%d.LMC%d.N%d", /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xfffffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_MIN_RTT_NOM_IDX] = {
        .format = "DDR-CONFIG-CUSTOM-MIN-RTT-NOM-IDX.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1,
        .min_value = 0,
        .max_value = 7,
    },
    [BDK_CONFIG_DDR_CUSTOM_MAX_RTT_NOM_IDX] = {
        .format = "DDR-CONFIG-CUSTOM-MAX-RTT-NOM-IDX.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 5,
        .min_value = 0,
        .max_value = 7,
    },
    [BDK_CONFIG_DDR_CUSTOM_MIN_RODT_CTL] = {
        .format = "DDR-CONFIG-CUSTOM-MIN-RODT-CTL.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1,
        .min_value = 0,
        .max_value = 7,
    },
    [BDK_CONFIG_DDR_CUSTOM_MAX_RODT_CTL] = {
        .format = "DDR-CONFIG-CUSTOM-MAX-RODT-CTL.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 5,
        .min_value = 0,
        .max_value = 7,
    },
    [BDK_CONFIG_DDR_CUSTOM_CK_CTL] = {
        .format = "DDR-CONFIG-CUSTOM-CK-CTL.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_CMD_CTL] = {
        .format = "DDR-CONFIG-CUSTOM-CMD-CTL.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_CTL_CTL] = {
        .format = "DDR-CONFIG-CUSTOM-CTL-CTL.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xf,
    },
    [BDK_CONFIG_DDR_CUSTOM_MIN_CAS_LATENCY] = {
        .format = "DDR-CONFIG-CUSTOM-MIN-CAS-LATENCY.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_OFFSET_EN] = {
        .format = "DDR-CONFIG-CUSTOM-OFFSET-EN.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_OFFSET] = {
        .format = "DDR-CONFIG-CUSTOM-OFFSET.%s.LMC%d.N%d", /* Parameters: Type(UDIMM,RDIMM), LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT, // UDIMM or RDIMM
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xf,
    },
    [BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMPUTE] = {
        .format = "DDR-CONFIG-CUSTOM-RLEVEL-COMPUTE.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_DDR_RTT_NOM_AUTO] = {
        .format = "DDR-CONFIG-CUSTOM-DDR-RTT-NOM-AUTO.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_DDR_RODT_CTL_AUTO] = {
        .format = "DDR-CONFIG-CUSTOM-DDR-RODT-CTL-AUTO.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMP_OFFSET] = {
        .format = "DDR-CONFIG-CUSTOM-RLEVEL-COMP-OFFSET.%s.LMC%d.N%d", /* Parameters: Type(UDIMM,RDIMM), LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT, // UDIMM or RDIMM
        .default_value = 2,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_RLEVEL_AVERAGE_LOOPS] = {
        .format = "DDR-CONFIG-CUSTOM-RLEVEL-AVERAGE-LOOPS.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_DDR2T] = {
        .format = "DDR-CONFIG-CUSTOM-DDR2T.%s.LMC%d.N%d", /* Parameters: Type(UDIMM,RDIMM), LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT, // UDIMM or RDIMM
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_DISABLE_SEQUENTIAL_DELAY_CHECK] = {
        .format = "DDR-CONFIG-CUSTOM-DISABLE-SEQUENTIAL-DELAY-CHECK.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_MAXIMUM_ADJACENT_RLEVEL_DELAY_INCREMENT] = {
        .format = "DDR-CONFIG-CUSTOM-MAXIMUM-ADJACENT-RLEVEL-DELAY-INCREMENT.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xffff,
    },
    [BDK_CONFIG_DDR_CUSTOM_PARITY] = {
        .format = "DDR-CONFIG-CUSTOM-PARITY.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_FPRCH2] = {
        .format = "DDR-CONFIG-CUSTOM-FPRCH2.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 0xf,
    },
    [BDK_CONFIG_DDR_CUSTOM_MODE32B] = {
        .format = "DDR-CONFIG-CUSTOM-MODE32B.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_MEASURED_VREF] = {
        .format = "DDR-CONFIG-CUSTOM-MEASURED-VREF.LMC%d.N%d", /* Parameters: LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DDR_CUSTOM_DLL_WRITE_OFFSET] = {
        .format = "DDR-CONFIG-CUSTOM-DLL-WRITE-OFFSET.BYTE%d.LMC%d.N%d", /* Parameters: Byte, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = -63,
        .max_value = 63,
    },
    [BDK_CONFIG_DDR_CUSTOM_DLL_READ_OFFSET] = {
        .format = "DDR-CONFIG-CUSTOM-DLL-READ-OFFSET.BYTE%d.LMC%d.N%d", /* Parameters: Byte, LMC, Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = -63,
        .max_value = 63,
    },

    /* High level DRAM options */
    [BDK_CONFIG_DRAM_VERBOSE] = {
        .format = "DDR-VERBOSE", /* Parameters: Node */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = off */
        .min_value = 0,
        .max_value = 255,
    },
    [BDK_CONFIG_DRAM_BOOT_TEST] = {
        .format = "DDR-TEST-BOOT", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = off, 1 = on */
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_DRAM_CONFIG_GPIO] = {
        .format = "DDR-CONFIG-GPIO", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* -1 = disabled, otherwise GPIO number */
        .min_value = -1,
        .max_value = 63,
    },

    /* USB */
    [BDK_CONFIG_USB_PWR_GPIO] = {
        .format = "USB-PWR-GPIO.N%d.PORT%d", /* Parameters: Node, Port */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* GPIO number, or -1 for none */
        .min_value = -1,
        .max_value = 49,
    },

    /* How EYE diagrams are captured from a QLM */
    [BDK_CONFIG_EYE_ZEROS] = {
        .format = "QLM-EYE-NUM-ZEROS", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 2,
        .min_value = 1,
        .max_value = 63,
    },
    [BDK_CONFIG_EYE_SAMPLE_TIME] = {
        .format = "QLM-EYE-SAMPLE-TIME", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 400, /* us */
        .min_value = 20, /* us */
        .max_value = 10000000, /* us */
    },
    [BDK_CONFIG_EYE_SETTLE_TIME] = {
        .format = "QLM-EYE-SETTLE-TIME", /* No parameters */
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 50, /* us */
        .min_value = 20, /* us */
        .max_value = 100000, /* us */
    },
};

/**
 * Look up a configuration item in the environment.
 *
 * @param name
 *
 * @return
 */
static const char *get_value(const char *name, int *blob_size)
{
    if (!config_fdt)
    {
        bdk_error("bdk-config asked for %s before configuration loaded\n", name);
        return NULL;
    }

    char n[64];
    strncpy(n, name, sizeof(n));
    n[sizeof(n)-1] = '\0';

    while (*n)
    {
        const char *val = fdt_getprop(config_fdt, config_node, n, blob_size);
        if (val)
            return val;

        char *p = strrchr(n, '.');
        if (p)
            *p = '\0';
        else
            break;
    }
    return NULL;
}

/**
 * Get an integer configuration item
 *
 * @param cfg_item  Config item to get. If the item takes parameters (see bdk_config_t), then the
 *                  parameters are listed following cfg_item.
 *
 * @return The value of the configuration item, or def_value if the item is not set
 */
int64_t bdk_config_get_int(bdk_config_t cfg_item, ...)
{
    /* Make sure the correct access function was called */
    if (config_info[cfg_item].ctype != BDK_CONFIG_TYPE_INT)
        bdk_fatal("bdk_config_get_int() called for %s, not an int\n",
            config_info[cfg_item].format);

    char name[64];
    va_list args;
    va_start(args, cfg_item);
    vsnprintf(name, sizeof(name)-1, config_info[cfg_item].format, args);
    va_end(args);

    const char *val = get_value(name, NULL);
    if (val)
    {
        int64_t tmp;
        if (sscanf(val, "%li", &tmp) == 1)
        {
            if ((tmp < config_info[cfg_item].min_value) || (tmp > config_info[cfg_item].max_value))
            {
                bdk_warn("Out of range for %s = \"%s\", using default\n", name, val);
                return config_info[cfg_item].default_value;
            }
            return tmp;
        }
        else
        {
            bdk_warn("Failed to parse %s = \"%s\", using default\n", name, val);
            return config_info[cfg_item].default_value;
        }
    }
    else
        return config_info[cfg_item].default_value;
}

/**
 * Get a string configuration item
 *
 * @param cfg_item  Config item to get. If the item takes parameters (see bdk_config_t), then the
 *                  parameters are listed following cfg_item.
 *
 * @return The value of the configuration item, or def_value if the item is not set
 */
const char *bdk_config_get_str(bdk_config_t cfg_item, ...)
{
    /* Make sure the correct access function was called */
    if (config_info[cfg_item].ctype != BDK_CONFIG_TYPE_STR)
        bdk_fatal("bdk_config_get_str() called for %s, not a str\n",
            config_info[cfg_item].format);

    char name[64];
    va_list args;
    va_start(args, cfg_item);
    vsnprintf(name, sizeof(name)-1, config_info[cfg_item].format, args);
    va_end(args);

    const char *val = get_value(name, NULL);
    if (val)
        return val;
    else
        return (const char *)config_info[cfg_item].default_value;
}

/**
 * Get a binary blob
 *
 * @param blob_size Integer to receive the size of the blob
 * @param cfg_item  Config item to get. If the item takes parameters (see bdk_config_t), then the
 *                  parameters are listed following cfg_item.
 *
 * @return The value of the configuration item, or def_value if the item is not set
 */
const void* bdk_config_get_blob(int *blob_size, bdk_config_t cfg_item, ...)
{
    char name[64];
    va_list args;
    va_start(args, cfg_item);
    vsnprintf(name, sizeof(name)-1, config_info[cfg_item].format, args);
    va_end(args);

    const void *val = get_value(name, blob_size);
    if (val)
        return val;
    else
        return (const void *)config_info[cfg_item].default_value;
}

/**
 * Set an integer configuration item. Note this only sets the item in memory,
 * persistent storage is not updated.
 *
 * @param value    Configuration item value
 * @param cfg_item Config item to set. If the item takes parameters (see bdk_config_t), then the
 *                 parameters are listed following cfg_item.
 */
void bdk_config_set_int(int64_t value, bdk_config_t cfg_item, ...)
{
    /* Make sure the correct access function was called */
    if (config_info[cfg_item].ctype != BDK_CONFIG_TYPE_INT)
        bdk_fatal("bdk_config_set_int() called for %s, not an int\n",
            config_info[cfg_item].format);

    char name[64];
    char valstr[20];
    va_list args;
    va_start(args, cfg_item);
    vsnprintf(name, sizeof(name)-1, config_info[cfg_item].format, args);
    va_end(args);

    if (!config_fdt)
    {
        bdk_error("bdk-config set %s before configuration loaded\n", name);
        return;
    }
    if ((value < config_info[cfg_item].min_value) || (value > config_info[cfg_item].max_value))
    {
        bdk_error("Set out of range for %s = \"0x%lx\", ignoring\n", name, value);
        return;
    }

    snprintf(valstr, sizeof(valstr), "0x%lx", value);

    int status = fdt_setprop_string(config_fdt, config_node, name, valstr);
    if (status < 0)
        bdk_fatal("Failed to set %s=%s in FDT\n", name, valstr);
}

/**
 * Set an integer configuration item. Note this only sets the item in memory,
 * persistent storage is not updated.
 *
 * @param value    Configuration item value
 * @param cfg_item Config item to set. If the item takes parameters (see bdk_config_t), then the
 *                 parameters are listed following cfg_item.
 */
void bdk_config_set_str(const char *value, bdk_config_t cfg_item, ...)
{
    /* Make sure the correct access function was called */
    if (config_info[cfg_item].ctype != BDK_CONFIG_TYPE_STR)
        bdk_fatal("bdk_config_set_str() called for %s, not a str\n",
            config_info[cfg_item].format);

    char name[64];
    va_list args;

    va_start(args, cfg_item);
    vsnprintf(name, sizeof(name)-1, config_info[cfg_item].format, args);
    va_end(args);

    if (!config_fdt)
    {
        bdk_error("bdk-config set %s before configuration loaded\n", name);
        return;
    }

    int status;
    if (value)
        status = fdt_setprop_string(config_fdt, config_node, name, value);
    else
        status = fdt_delprop(config_fdt, config_node, name);

    if ((status < 0) && (status != -FDT_ERR_NOTFOUND))
        bdk_fatal("Failed to set %s=%s in FDT\n", name, value);
}

/**
 * Set a blob configuration item. Note this only sets the
 * item in memory, persistent storage is not updated.
 *
 * @param size     Size of the item in bytes. A size of zero removes the device tree field
 * @param value    Configuration item value
 * @param cfg_item Config item to set. If the item takes parameters (see bdk_config_t), then the
 *                 parameters are listed following cfg_item.
 */
void bdk_config_set_blob(int size, const void *value, bdk_config_t cfg_item, ...)
{
    /* Make sure the correct access function was called */
    if (config_info[cfg_item].ctype != BDK_CONFIG_TYPE_STR)
        bdk_fatal("bdk_config_set_blob() called for %s, not a str\n",
            config_info[cfg_item].format);

    char name[64];
    va_list args;

    va_start(args, cfg_item);
    vsnprintf(name, sizeof(name)-1, config_info[cfg_item].format, args);
    va_end(args);

    if (!config_fdt)
    {
        bdk_error("bdk-config set %s before configuration loaded\n", name);
        return;
    }

    int status;
    if (size)
        status = fdt_setprop(config_fdt, config_node, name, value, size);
    else
        status = fdt_delprop(config_fdt, config_node, name);

    if ((status < 0) && (status != -FDT_ERR_NOTFOUND))
        bdk_fatal("Failed to set %s in FDT\n", name);
}

/**
 * Multiple functions need to display the config item help string in a format
 * suitable for inclusion in a device tree. This function displays the help
 * message properly indented and such.
 *
 * @param cfg    Config item to display help for
 */
static void display_help(bdk_config_t cfg)
{
    /* Print the help text as a comment before the entry */
    /* Indent with tabs like Linux requires */
    printf("\n");
    printf("\t/* ");
    const char *ptr = bdk_config_get_help(cfg);
    while (*ptr)
    {
        putchar(*ptr);
        if (*ptr == '\n')
            putchar('\t');
        ptr++;
    }
    printf(" */\n");
    /* Print the parameter and its default value a comment. This will be
       a reference that is easy for the user to change */
    printf("\t//%s = ", config_info[cfg].format);
    switch (config_info[cfg].ctype)
    {
        case BDK_CONFIG_TYPE_INT:
            if (config_info[cfg].default_value < 10)
                printf("\"%ld\"", config_info[cfg].default_value);
            else
                printf("\"0x%lx\"", config_info[cfg].default_value);
            break;
        case BDK_CONFIG_TYPE_STR:
        case BDK_CONFIG_TYPE_STR_LIST:
            if (config_info[cfg].default_value)
                printf("\"%s\"", (const char *)config_info[cfg].default_value);
            else
                printf("\"\"");
            break;
    }
    printf(";\n");
}

/**
 * Display the active configuration as a valid device tree
 */
void bdk_config_show(void)
{
    /* Output the standard DTS headers */
    printf("/dts-v1/;\n");
    printf("\n");
    printf("/ {\n");
    printf("cavium,bdk {\n");
    for (bdk_config_t cfg = 0; cfg < __BDK_CONFIG_END; cfg++)
    {
        /* Show the help message */
        display_help(cfg);

        /* Figure out how much of the config item is fixed versus
           the optional parameters */
        const char *format = config_info[cfg].format;
        const char *format_param = strchr(format, '.');
        int format_length = 0;
        if (format_param)
            format_length = format_param - format;

        /* Loop through all device tree entries displaying the ones that
           match this format */
        int offset = fdt_first_property_offset(config_fdt, config_node);
        while (offset >= 0)
        {
            /* Get the device tree item */
            const char *name = NULL;
            int data_size = 0;
            const char *data = fdt_getprop_by_offset(config_fdt, offset, &name, &data_size);
            const char *data_end = data + data_size;
            /* Find the first param */
            const char *name_param = strchr(name, '.');
            int name_length = 0;
            if (name_param)
            {
                /* We want to compare up to the first param */
                name_length = name_param - name;
                /* If the lengths are different not including the parameters,
                   then we force a full matchn which will always fail */
                if (name_length != format_length)
                    name_length = 0;
            }
            else /* No params, match base of format */
                name_length = format_length;

            /* Check if it matches the current config format */
            int match;
            if (name_length)
            {
                /* Check the prefix */
                match = strncmp(name, format, name_length);
                if (match == 0)
                {
                    /* Prefix matched. We only really match if the next
                       character is the end of the string or a '.' */
                    if ((name[name_length] != 0) && (name[name_length] != '.'))
                        match = 1;
                }
            }
            else
                match = strcmp(name, format);
            /* Print matching entries */
            if (match == 0)
            {
                printf("\t%s = \"%s\"", name, data);
                data += strlen(data) + 1;
                while (data < data_end)
                {
                    printf(",\n\t\t\"%s\"", data);
                    data += strlen(data) + 1;
                }
                printf(";\n");
            }
            offset = fdt_next_property_offset(config_fdt, offset);
        }
    }
    /* Output the standard DTS footers */
    printf("}; /* cavium,bdk */\n");
    printf("}; /* / */\n");
}

/**
 * Display a list of all possible config items with help text
 */
void bdk_config_help(void)
{
    /* Write out formatted as part of a device tree source (dts) file */
    printf("/dts-v1/;\n");
    printf("\n");
    printf("/ {\n");
    printf("cavium,bdk {\n");
    for (bdk_config_t cfg = 0; cfg < __BDK_CONFIG_END; cfg++)
        display_help(cfg);
    printf("}; /* cavium,bdk */\n");
    printf("}; /* / */\n");
}


/**
 * Save the current configuration to flash
 *
 * @return Zero on success, negative on failure
 */
int bdk_config_save(void)
{
    /* Pack the FDT so it uses less space */
    int status = fdt_pack(config_fdt);
    if (status < 0)
    {
        bdk_error("FDT error %d: %s\n", status, fdt_strerror(status));
        return -1;
    }

    /* Calculate a CRC32 of the FDT */
    int fdt_size = fdt_totalsize(config_fdt);
    uint32_t crc32 = bdk_crc32(config_fdt, fdt_size, 0);

    /* Open the output file */
    FILE *outf = fopen("/fatfs/default.dtb", "wb");
    if (!outf)
    {
        bdk_error("Failed to open flash");
        return -1;
    }

    /* Write the FDT */
    if (fwrite(config_fdt, fdt_size, 1, outf) != 1)
    {
        bdk_error("Failed to write FDT");
        fclose(outf);
        return -1;
    }

    /* Save the CRC32 in the same endianness as the FDT */
    crc32 = cpu_to_fdt32(crc32);
    if (fwrite(&crc32, sizeof(crc32), 1, outf) != 1)
    {
        bdk_error("Failed to write FDT CRC32");
        fclose(outf);
        return -1;
    }

    fclose(outf);
    return 0;
}

/**
 * Takes the current live device tree and exports it to a memory address suitable
 * for passing to the next binary in register X1.
 *
 * @return Physical address of the device tree, or 0 on failure
 */
uint64_t __bdk_config_export_to_mem(void)
{
    extern caddr_t sbrk(int incr);
    void *end_ptr = sbrk(0);
    bdk_node_t node = bdk_numa_master();
    int fdt_size = fdt_totalsize(config_fdt);

    /* Round size up to 4KB boundary */
    fdt_size = (fdt_size + 0xfff) & -4096;
    /* First try 4MB - FDT size as this keeps the FDT in the 4MB secure space
        setup by ATF */
    void *fdt_ptr = bdk_phys_to_ptr(0x400000 - fdt_size);
    if (!__bdk_is_dram_enabled(node))
    {
        /* Address must be in L2 */
        int l2_size = bdk_l2c_get_cache_size_bytes(node);
        void *l2_ptr = bdk_phys_to_ptr(l2_size - fdt_size);
        if (l2_ptr < fdt_ptr)
            fdt_ptr = l2_ptr;
        if (fdt_ptr < end_ptr)
        {
            bdk_error("No room for FDT to pass to next binary\n");
            return 0;
        }
    }
    else
    {
        /* We have DRAM, make sure we're past the end of this image */
        if (fdt_ptr < end_ptr)
            fdt_ptr = end_ptr;
    }
    fdt_move(config_fdt, fdt_ptr, fdt_size);
    return bdk_ptr_to_phys(fdt_ptr);
}

/**
 * Some of the default config values can vary based on runtime parameters. This
 * function sets those default parameters. It must be run before anyone calls
 * bdk_config_get_*().
 */
static void config_set_defaults(void)
{
    /* This is Cavium's OUI with the local admin bit. We will use this as a
        default as it won't collide with official addresses, but is sort of
        part of the Cavium range. The lower three bytes will be updated with
        the wafer info */
    uint64_t mac_address = 0x020fb7000000ull;
    /* Set the lower MAC address bits based on the chip manufacturing
        information. This should give reasonable MAC address defaults
        for production parts */
    BDK_CSR_INIT(fus_dat0, bdk_numa_local(), BDK_MIO_FUS_DAT0);
    mac_address |= fus_dat0.u & 0xffffff;
    config_info[BDK_CONFIG_MAC_ADDRESS].default_value = mac_address;

    /* Set the number of packet buffers */
    int num_packet_buffers = 4096;
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        num_packet_buffers = 4;
    /* If DRAM is setup, allocate 8K buffers for 8 ports plus some slop */
    if (__bdk_is_dram_enabled(bdk_numa_master()))
        num_packet_buffers = 8192 * 16 + 1024;
    config_info[BDK_CONFIG_NUM_PACKET_BUFFERS].default_value = num_packet_buffers;
    config_info[BDK_CONFIG_PACKET_BUFFER_SIZE].default_value = 1024;

    /* Asim doesn't scale to 48 cores well. Limit to 4 */
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
        config_info[BDK_CONFIG_COREMASK].default_value = 0xf;
    /* CN88XX pass 1.x doesn't support EA */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        config_info[BDK_CONFIG_PCIE_EA].default_value = 0;
    /* Emulator only supports 4 cores */
    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
        config_info[BDK_CONFIG_COREMASK].default_value = 0xf;
}

/**
 * BDK configuration items are stored in a device tree so thay can be passed to
 * other software later. This function creates the initial empty device tree
 * used for BDK configuration items. The values will be populated as configuration
 * files are read from flash.
 */
static void config_setup_fdt(void)
{
    const int FDT_SIZE = 0x10000;
    config_fdt = calloc(1, FDT_SIZE);
    if (!config_fdt)
        bdk_fatal("Unable to allocate memory for config FDT\n");
    if (fdt_create_empty_tree(config_fdt, FDT_SIZE) < 0)
        bdk_fatal("Unable to create FDT for config\n");
    config_node = fdt_add_subnode(config_fdt, 0, "cavium,bdk");
    if (config_node < 0)
        bdk_fatal("Unable to create cavium,bdk node in FDT\n");
}

/**
 * Parse a FDT and copy its properties to our configuration FDT
 *
 * @param fdt    FDT to parse
 */
static int config_parse_fdt(const void *fdt, const char *base_path)
{
    /* Check the FDT header */
    int result = fdt_check_header(fdt);
    if (result)
        goto fail;

    /* Find our node */
    result = fdt_path_offset(fdt, base_path);
    if (result < 0)
        goto fail;

    /* Copy all parameters to our in memory FDT */
    int offset = fdt_first_property_offset(fdt, result);
    while (offset >= 0)
    {
        const char *name = NULL;
        int blob_size = 0;
        const char *data = fdt_getprop_by_offset(fdt, offset, &name, &blob_size);
        result = fdt_setprop(config_fdt, config_node, name, data, blob_size);
        offset = fdt_next_property_offset(fdt, offset);
    }
    return 0;
fail:
    bdk_error("FDT error %d: %s\n", result, fdt_strerror(result));
    return -1;
}

/**
 * Load a FDT from a file and pull in its configuration properties
 *
 * @param filename File to read from
 * @param offset   Offset into the file to read from
 *
 * @return Zero on success, negative on failure
 */
static int config_load_file(const char *filename, uint64_t offset)
{
    /* Attempt to open the input file */
    FILE *inf = fopen(filename, "rb");
    if (!inf)
        return -1; /* Fails silently so we can search for DTB files */

    int ftd_size = 0x10000; /* Assume 64KB is big enough for FDT */
    if (offset)
        fseek(inf, offset, SEEK_SET);

    /* The device tree is too large for the stack so we have to malloc() */
    void *fdt = malloc(ftd_size);
    if (!fdt)
    {
        bdk_error("Unable to allocate memory to load FDT\n");
        fclose(inf);
        return -1;
    }

    /* Read the entire device tree */
    int count = fread(fdt, 1, ftd_size, inf);
    fclose(inf);

    /* Make sure the read succeeded */
    if (count < (int)sizeof(struct fdt_header))
    {
        bdk_error("Unable to read %s\n", filename);
        free(fdt);
        return -1;
    }

    if (fdt_check_header(fdt))
    {
        bdk_error("Invalid FDT header read from %s\n", filename);
        free(fdt);
        return -1;
    }

    /* Make sure we read enough data to contain the FDT */
    int correct_size = fdt_totalsize(fdt);
    if (count < correct_size)
    {
        bdk_error("Unable to read FDT from %s\n", filename);
        free(fdt);
        return -1;
    }

    /* Check if a CRC32 was added on the end of the FDT */
    if (count >= correct_size + 4)
    {
        uint32_t crc32 = bdk_crc32(fdt, correct_size, 0);
        uint32_t correct_crc32 = *(uint32_t *)((const char *)fdt + correct_size);
        /* CRC32 is stored in same endianness as FDT */
        correct_crc32 = fdt32_to_cpu(correct_crc32);
        if (crc32 != correct_crc32)
        {
            bdk_error("FDT failed CRC32 verification (%s)\n", filename);
            free(fdt);
            return -1;
        }
        //printf("PASS: FDT CRC32 verification (%s)\n", filename);
    }

    /* Parse the device tree, adding its configuration to ours */
    if (config_parse_fdt(fdt, "/cavium,bdk"))
    {
        free(fdt);
        return -1;
    }

    free(fdt);
    return 0;
}

/**
 * Internal BDK function to initialize the config system. Must be called before
 * any configuration functions are called
 */
void __bdk_config_init(void)
{
    /* Set default that can vary dynamically at runtime */
    config_set_defaults();

    /* Regsiter X1 is expected to be a device tree when we boot. Check that
       the physical address seems correct, then load the device tree */
    if ((__bdk_init_reg_x1 > 0) &&          /* Not zero */
        (__bdk_init_reg_x1 < 0x400000) &&   /* In the lower 4MB */
        ((__bdk_init_reg_x1 & 0xfff) == 0)) /* Aligned on a 4KB boundary */
    {
        const void *fdt = (const void *)__bdk_init_reg_x1;
        /* Check the FDT header */
        int result = fdt_check_header(fdt);
        if (result)
            result = -1; /* Invalid tree */
        else
            result = fdt_path_offset(fdt, "/cavium,bdk"); /* Find our node */
        /* If tree is valid so far, attempt to move it into our memory space */
        if (result > 0)
        {
            /* 4KB extra room for growth */
            const int fdt_size = fdt_totalsize(fdt) + 4096;
            config_fdt = calloc(1, fdt_size);
            if (config_fdt)
            {
                int result = fdt_move(fdt, config_fdt, fdt_size);
                if (result == 0)
                {
                    /* Find our node */
                    config_node = fdt_path_offset(config_fdt, "/cavium,bdk");
                    if (config_node > 0)
                    {
                        printf("Using configuration from previous image\n");
                        goto done;
                    }
                    else
                    {
                        bdk_error("Unable to find BDK node after move\n");
                        free(config_fdt);
                        config_node = 0;
                        config_fdt = NULL;
                    }
                }
                else
                {
                    bdk_error("Unable to move passed device tree\n");
                    free(config_fdt);
                    config_fdt = NULL;
                }
            }
            else
                bdk_error("Failed to allocate memory for passed device tree (%d bytes)\n", fdt_size);
        }
    }

    /* Create the global device tree used to store config items */
    config_setup_fdt();

    if (bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
            bdk_config_set_str("ASIM-CN88XX", BDK_CONFIG_BOARD_MODEL);
        else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
            bdk_config_set_str("ASIM-CN83XX", BDK_CONFIG_BOARD_MODEL);
        else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
            bdk_config_set_str("ASIM-CN81XX", BDK_CONFIG_BOARD_MODEL);
    }
    /* Load manufacturing data from the top 64KB of flash */
    else if (config_load_file("/boot", BDK_CONFIG_MANUFACTURING_ADDRESS) != 0)
    {
        printf("\33[1m"); /* Bold */
        bdk_warn("\n");
        bdk_warn("********************************************************\n");
        bdk_warn("* Board manufacturing information not found.  Program\n");
        bdk_warn("* the board manufacturing information in the Setup menu.\n");
        bdk_warn("********************************************************\n");
        bdk_warn("\n");
        printf("\33[0m"); /* Normal */
        goto done;
    }

    /* Load default.dtb if it is there */
    if (config_load_file("/fatfs/default.dtb", 0) == 0)
        goto done;

    const char *model = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
    const char *revision = bdk_config_get_str(BDK_CONFIG_BOARD_REVISION);

    /* Load BOARD-REVISION.cfg if it is there */
    if (model && revision)
    {
        char filename[64];
        snprintf(filename, sizeof(filename), "/fatfs/%s-%s.dtb", model, revision);
        if (config_load_file(filename, 0) == 0)
            goto done;
    }

    /* Load BOARD.cfg if it is there */
    if (model)
    {
        char filename[64];
        snprintf(filename, sizeof(filename), "/fatfs/%s.dtb", model);
        if (config_load_file(filename, 0) == 0)
            goto done;
    }

    /* No board specific configuration was found. Warn the user */
    printf("\33[1m"); /* Bold */
    bdk_warn("\n");
    bdk_warn("********************************************************\n");
    bdk_warn("* Board configuration file not found. Either the board\n");
    bdk_warn("* model is incorrect, or factory settings are not\n");
    bdk_warn("* available. DTB file not found for board \"%s\".\n", model);
    bdk_warn("********************************************************\n");
    bdk_warn("\n");
    printf("\33[0m"); /* Normal */

done:
    /* Load the tracing level */
    bdk_trace_enables = bdk_config_get_int(BDK_CONFIG_TRACE);
}
