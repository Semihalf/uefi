#include <bdk.h>
#include <stdarg.h>

typedef enum
{
    BDK_CONFIG_TYPE_INT,
    BDK_CONFIG_TYPE_STR
} bdk_config_type_t;

typedef struct
{
    const char *format;     /* Printf style format string to create the item name */
    const char *help;       /* Help string for display to the user */
    const bdk_config_type_t ctype;/* Type of this item */
    int64_t default_value;  /* Default value when no present. String defaults are cast to pointers from this */
    const int64_t min_value;/* Minimum valid value for INT parameters. Unused for Strings */
    const int64_t max_value;/* Maximum valid value for INT parameters. Unused for Strings */
} bdk_config_info_t;

static bdk_config_info_t config_info[__BDK_CONFIG_END] = {
    /* Board manufacturing data */
    [BDK_CONFIG_BOARD_MODEL] = {
        .format = "BOARD-MODEL", /* String, No parameters */
        .help =
            "Board model number. This is used to determine the name of the\n"
            "configuration file containing the boards default settings. This\n"
            "parameter is stored in a static board manufacturing area at the\n"
            "top of the boot flash.",
        .ctype = BDK_CONFIG_TYPE_STR,
        .default_value = (long)"unknown",
    },
    [BDK_CONFIG_BOARD_REVISION] = {
        .format = "BOARD-REVISION", /* String, No parameters */
        .help =
            "The board revision level. This parameter is stored in a static\n"
            "board manufacturing area at the top of the boot flash.",
        .ctype = BDK_CONFIG_TYPE_STR,
        .default_value = (long)"unknown",
    },
    [BDK_CONFIG_BOARD_SERIAL] = {
        .format = "BOARD-SERIAL", /* String, No parameters */
        .help =
            "Unique string used as a serial number. This parameter is stored\n"
            "in a static board manufacturing area at the top of the boot flash.",
        .ctype = BDK_CONFIG_TYPE_STR,
        .default_value = (long)"unknown",
    },
    [BDK_CONFIG_MAC_ADDRESS] = {
        .format = "BOARD-MAC-ADDRESS", /* Int64, No parameters */
        .help =
            "The first MAC address assigned to the THUNDERX network ports. MAC\n"
            "addresses are in a contiguous block starting at this address and\n"
            "containing BOARD-MAC-ADDRESS-NUM number of addresses. The format\n"
            "of this parameter is 0xXXXXXXXXXXXX, 12 hex digits startign with\n"
            "'0x'.This parameter is stored in a static board manufacturing\n"
            "area at the top of the boot flash.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Default updated at boot based on fuses */
        .min_value = 0,
        .max_value = 0xffffffffffffll,
    },
    [BDK_CONFIG_MAC_ADDRESS_NUM] = {
        .format = "BOARD-MAC-ADDRESS-NUM", /* Int, No parameters */
        .help =
            "The number of MAC addresses assigned to the THUNDERX network\n"
            "ports. See BOARD-MAC-ADDRESS for the actual MAC address numeric\n"
            "value.This parameter is stored in a static board manufacturing\n"
            "area at the top of the boot flash.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0,
        .min_value = 0,
        .max_value = 256,
    },

    /* Board generic */
    [BDK_CONFIG_BMC_TWSI] = {
        .format = "BMC-TWSI", /* No parameters */
        .help =
            "THUNDERX TWSI port connected to the BMC for IPMI traffic.\n"
            "-1 = No connection exists. 0+ is TWSI bus number.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* TWSI bus number, -1 = disabled */
        .min_value = -1,
        .max_value = 5,
    },
    [BDK_CONFIG_WATCHDOG_TIMEOUT] = {
        .format = "WATCHDOG-TIMEOUT", /* No parameters */
        .help =
            "This specifies a watchdog timer should run during boot and reset\n"
            "the chip if boot hangs for soem reason. The timeout is specified\n"
            "in milliseconds. Zero disables the watchdog.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = disabled */
        .min_value = 0,
        .max_value = 10000,
    },
    [BDK_CONFIG_TWSI_WRITE] = {
        .format = "TWSI-WRITE-%d", /* Parameters: Write number */
        .help =
            "Allow a sequence of TWSI writes to be performed during boot. Each\n"
            "TWSI-WRITE-# line is executed in sequence starting with\n"
            "TWSI-WRITE-0 and incrementing the number. The TWSI write format is:\n"
            "    node,twsi_id,dev_addr,internal_addr,num_bytes,ia_width_bytes,data\n"
            "node           = ThunderX node ID the twsi bus is on. -1 means the local node\n"
            "twsi_id        = ThunderX twsi bus to use\n"
            "dev_addr       = TWSI bus address\n"
            "internal_addr  = TWSI internal address, zero if not used\n"
            "num_bytes      = Number of bytes to write (1-8)\n"
            "ia_width_bytes = Internal address width in bytes (0-2)\n"
            "data           = Data to write as a 64bit number",
        .ctype = BDK_CONFIG_TYPE_STR,
    },
    [BDK_CONFIG_MDIO_WRITE] = {
        .format = "MDIO-WRITE-%d", /* Parameters: Write number */
        .help =
            "Allow a sequence of MDIO writes to be performed during boot. Each\n"
            "MDIO-WRITE-# line is executed in sequence starting with\n"
            "MDIO-WRITE-0 and incrementing the number. The MDIO write format is:\n"
            "    clause,node,bus_id,phy_id,device,location,val\n"
            "clause   = MDIO clause for the write (22 or 45)\n"
            "node     = ThunderX node the MDIO bus is connected, -1 for local\n"
            "bus_id   = ThunderX MDIO bus to use\n"
            "phy_id   = MDIO address\n"
            "device   = Clause 45 internal device address, zero for clause 22\n"
            "location = MDIO register\n"
            "val      = Value to write",
        .ctype = BDK_CONFIG_TYPE_STR,
    },

    /* Board wiring of network ports and PHYs */
    [BDK_CONFIG_PHY_ADDRESS] = {
        .format = "PHY-ADDRESS.N%d.BGX%d.P%d", /* Parameters: Node, Interface, Port */
        .help =
            "PHY address encoding:\n"
            "    Bits[31:24]: Node ID, 0xff for node the etherent device is on\n"
            "    Bits[23:16]: Only used for TWSI\n"
            "    Bits[15:12]: PHY connection type (0=MDIO, 1=Fixed, 2=TWSI)\n"
            "For MDIO:\n"
            "    Bits[31:24]: Node ID, 0xff for node the etherent device is on\n"
            "    Bits[23:16]: 0\n"
            "    Bits[15:12]: 0=MDIO\n"
            "    Bits[11:8]: MDIO bus number\n"
            "    Bits[7:0]: MDIO address\n"
            "For Fixed:\n"
            "    Bits[31:24]: 0\n"
            "    Bits[23:16]: Zero\n"
            "    Bits[15:12]: 1=Fixed\n"
            "    Bits[11:0]:  0 = 1Gb, 1 = 100Mb\n"
            "For TWSI:\n"
            "    Bits[31:24]: Node ID, 0xff for node the etherent device is on\n"
            "    Bits[23:16]: TWSI internal address width in bytes (0-2)\n"
            "    Bits[15:12]: 2=TWSI\n"
            "    Bits[11:8]: TWSI bus number\n"
            "    Bits[7:0]: TWSI address",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default to no PHY */
        .min_value = -1,
        .max_value = 0xffffffffll,
    },
    [BDK_CONFIG_BGX_ENABLE] = {
        .format = "BGX-ENABLE.N%d.BGX%d.P%d", /* Parameters: Node, BGX, Port */
        .help =
            "Independent enables for each BGX port of THUNDERX. Use this to\n"
            "disable ports that are not wired on a board. Default is that all\n"
            "ports are enabled.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1, /* 0 = disable, 1 = enable */
        .min_value = 0,
        .max_value = 1,
    },

    /* BDK Configuration params */
    [BDK_CONFIG_NUM_PACKET_BUFFERS] = {
        .format = "BDK-NUM-PACKET-BUFFERS",
        .help = "Number of packet buffers in the BDK.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Default updated at boot */
        .min_value = 0,
        .max_value = 1000000,
    },
    [BDK_CONFIG_PACKET_BUFFER_SIZE] = {
        .format = "BDK-PACKET-BUFFER-SIZE",
        .help = "The size of each packet buffer in the BDK.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1024, /* bytes */
        .min_value = 128,
        .max_value = 32768,
    },
    [BDK_CONFIG_SHOW_LINK_STATUS] = {
        .format = "BDK-SHOW-LINK-STATUS",
        .help = "Controls whether the BDK displays link status messages.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 1, /* 0 = off, 1 = on */
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_COREMASK] = {
        .format = "BDK-COREMASK",
        .help = "Controls the cores used by the BDK. Zero means all cores.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Zero means all cores */
        .min_value = 0,
        .max_value = 0xffffffffffffll,
    },
    [BDK_CONFIG_BOOT_MENU_TIMEOUT] = {
        .format = "BDK-BOOT-MENU-TIMEOUT",
        .help = "Timeout for the boot menu in seconds.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 10, /* seconds */
        .min_value = 0,
        .max_value = 300,
    },

    /* Chip feature items */
    [BDK_CONFIG_MULTI_NODE] = {
        .format = "MULTI-NODE", /* No parameters */
        .help =
            "Determine how multi-node is supported for this system:\n"
            "    0 = Multi-node is not supported\n"
            "    1 = Multi-node is supported and booting requires two nodes\n"
            "    2 = Multi-node is auto detected. Two nodes are used if\n"
            "        if available, otherwise fall back to single node.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 2, /* 2 = Auto */
        .min_value = 0,
        .max_value = 2,
    },

    /* QLM related config */
    [BDK_CONFIG_QLM_AUTO_CONFIG] = {
        .format = "QLM-AUTO-CONFIG", /* Parameters: Node */
        .help =
            "For Cavium evaluation boards, query the MCU for QLM setup\n"
            "information. The MCU supplies a TWSI protocol for THUNDERX to\n"
            "query the modules plugged in and automatically set the QLMs to\n"
            "the correct mode. This should only be enabled(1) on Cavium\n"
            "EBB8XXX boards. Other boards should have it disabled(0).",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = off, 1 = on */
        .min_value = 0,
        .max_value = 1,
    },
    [BDK_CONFIG_QLM_MODE] = {
        .format = "QLM-MODE.N%d.QLM%d", /* Parameters: Node, QLM */
        .help =
            "Set the mode of a QLM. The possible mode strings are:\n"
            "    DISABLED\n"
            "    PCIE_1X1\n"
            "    PCIE_2X1\n"
            "    PCIE_1X2\n"
            "    PCIE_1X4\n"
            "    PCIE_1X8\n"
            "    SATA_4X1\n"
            "    SATA_2X1\n"
            "    ILK\n"
            "    SGMII_4X1\n"
            "    SGMII_2X1\n"
            "    XAUI_1X4\n"
            "    RXAUI_2X2\n"
            "    RXAUI_1X2\n"
            "    OCI\n"
            "    XFI_4X1\n"
            "    XFI_2X1\n"
            "    XLAUI_1X4\n"
            "    10G_KR_4X1\n"
            "    10G_KR_2X1\n"
            "    40G_KR4_1X4",
        .ctype = BDK_CONFIG_TYPE_STR,
    },
    [BDK_CONFIG_QLM_FREQ] = {
        .format = "QLM-FREQ.N%d.QLM%d", /* Parameters: Node, QLM */
        .help =
            "Set the speed of a QLM in Mhz. The possible speeds are:\n"
            "    1250\n"
            "    1500\n"
            "    2500\n"
            "    3000\n"
            "    3125\n"
            "    5000\n"
            "    6000\n"
            "    6250\n"
            "    8000\n"
            "   10312",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Mhz */
        .min_value = 0,
        .max_value = 10312,
    },
    [BDK_CONFIG_QLM_CLK] = {
        .format = "QLM-CLK.N%d.QLM%d", /* Parameters: Node, QLM */
        .help =
            "Set the source of the QLM reference clock:\n"
            "    0 = Common clock 0\n"
            "    1 = Common clokc 1\n"
            "    2 = QLM external reference",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 2, /* 2 = External */
        .min_value = 0,
        .max_value = 2,
    },
    [BDK_CONFIG_QLM_TUNING_TX_SWING] = {
        .format = "QLM-TUNING-TX-SWING.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .help =
            "Setting of GSERX_LANEX_TX_CFG_0[CFG_TX_SWING] for the QLM. This\n"
            "should only be used for QLMs used for BGX and CCPI not using KR\n"
            "training.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 31,
    },
    [BDK_CONFIG_QLM_TUNING_TX_PREMPTAP] = {
        .format = "QLM-TUNING-TX-PREMPTAP.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .help =
            "Setting of GSERX_LANEX_TX_PRE_EMPHASIS[CFG_TX_PREMPTAP] for the\n"
            "QLM. This should only be used for QLMs used for BGX and CCPI not\n"
            "using KR training. CFG_TX_PREMPTAP:\n"
            "    Bits[8:5] = Tx Post Tap; Bits[3:0] = Tx Pre Tap",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 511,
    },
    [BDK_CONFIG_QLM_TUNING_TX_GAIN] = {
        .format = "QLM-TUNING-TX-GAIN.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .help =
            "Setting of GSERX_LANEX_TX_CFG_3[PCS_SDS_TX_GAIN] for the QLM. This\n"
            "should only be used for QLMs used for BGX and CCPI not using KR\n"
            "training.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 7,
    },
    [BDK_CONFIG_QLM_TUNING_TX_VBOOST] = {
        .format = "QLM-TUNING-TX-VBOOST.N%d.QLM%d.LANE%d", /* Parameters: Node, QLM, Lane */
        .help =
            "Setting of GSERX_LANEX_TX_CFG_3[CFG_TX_VBOOST_EN] for the QLM. This\n"
            "should only be used for QLMs used for BGX and CCPI not using KR\n"
            "training.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* Default of no tuning */
        .min_value = -1,
        .max_value = 1,
    },

    /* High level DRAM options */
    [BDK_CONFIG_DRAM_NODE] = {
        .format = "DDR-CONFIG.N%d", /* Parameters: Node */
        .help =
            "DRAM configuration name to use for the board. This coresponds to\n"
            "a file in lib-dram/configs/config-*.c. FIXME",
        .ctype = BDK_CONFIG_TYPE_STR,
    },
    [BDK_CONFIG_DDR_UDIMM_SPEED] = {
        .format = "DDR-SPEED-UDIMM.N%d", /* Parameters: Node */
        .help = "FIXME",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* In MT/s */
        .min_value = 0,
        .max_value = 2400,
    },
    [BDK_CONFIG_DDR_RDIMM_SPEED] = {
        .format = "DDR-SPEED-RDIMM.N%d", /* Parameters: Node */
        .help = "FIXME",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* In MT/s */
        .min_value = 0,
        .max_value = 2400,
    },
    [BDK_CONFIG_DDR_ALT_REFCLK] = {
        .format = "DDR-ALT-REFCLK.N%d", /* Parameters: Node */
        .help =
            "Set to use a an alternate reference clock for DRAM than the usual\n"
            "50Mhz reference. The value of here specifies the frequency of the\n"
            "alternate clock in Mhz. Currently the only supported reference\n"
            "clock frequencies are 50Mhz and 100Mhz.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* Mhz */
        .min_value = 0,
        .max_value = 100,
    },
    [BDK_CONFIG_DRAM_VERBOSE] = {
        .format = "DDR-VERBOSE", /* Parameters: Node */
        .help =
            "Specify the debug logging level during DRAM initialization. Zero\n"
            "disables debug logging. The possible debug levels are:\n"
            "    TBD",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = off */
        .min_value = 0,
        .max_value = 255,
    },
    [BDK_CONFIG_DRAM_BOOT_TEST] = {
        .format = "DDR-TEST-BOOT.N%d", /* Parameters: Node */
        .help =
            "Run a short DRAM test after DRAM is initialized as quick check\n"
            "for functionality. This is normally not needed required. Boards\n"
            "with poor DRAM power supplies may use this to detect failures\n"
            "during boot. This should be used in combination with the watchdog\n"
            "timer.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 0, /* 0 = off, 1 = on */
        .min_value = 0,
        .max_value = 1,
    },

    /* USB */
    [BDK_CONFIG_USB_PWR_GPIO] = {
        .format = "USB-PWR-GPIO.N%d.PORT%d", /* Parameters: Node, Port */
        .help =
            "Specify a THUNDERX GPIO used to control power for a USB port. When\n"
            "set, the USB host controller will toggle the GPIO automatically\n"
            "during USB reset events. The default value assumes THUNDERX has no\n"
            "control of the USB power and it is always on.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = -1, /* GPIO number, or -1 for none */
        .min_value = -1,
        .max_value = 49,
    },

    /* How EYE diagrams are captured from a QLM */
    [BDK_CONFIG_EYE_ZEROS] = {
        .format = "QLM-EYE-NUM-ZEROS", /* No parameters */
        .help = "Number of reading with no errors to signal the start of an\n"
                "eye. The default value should be good for most cases.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 2,
        .min_value = 1,
        .max_value = 63,
    },
    [BDK_CONFIG_EYE_SAMPLE_TIME] = {
        .format = "QLM-EYE-SAMPLE-TIME", /* No parameters */
        .help = "Time to sample at each location in microseconds. The default\n"
                "value should be good for most cases.",
        .ctype = BDK_CONFIG_TYPE_INT,
        .default_value = 400, /* us */
        .min_value = 20, /* us */
        .max_value = 10000000, /* us */
    },
    [BDK_CONFIG_EYE_SETTLE_TIME] = {
        .format = "QLM-EYE-SETTLE-TIME", /* No parameters */
        .help = "Time to settle after each movement in microseconds. The\n"
                "default value should be good for most cases.",
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
static const char *get_value(const char *name)
{
    char n[64];
    strncpy(n, name, sizeof(n));
    n[sizeof(n)-1] = '\0';

    while (*n)
    {
        const char *val = getenv(n);
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

    const char *val = get_value(name);
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

    const char *val = get_value(name);
    if (val)
        return val;
    else
        return (const char *)config_info[cfg_item].default_value;
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

    if ((value < config_info[cfg_item].min_value) || (value > config_info[cfg_item].max_value))
    {
        bdk_error("Set out of range for %s = \"0x%lx\", ignoring\n", name, value);
        return;
    }

    snprintf(valstr, sizeof(valstr), "0x%lx", value);
    setenv(name, valstr, 1);
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

    if (value)
       setenv(name, value, 1);
    else
       unsetenv(name);
}

/**
 * Display the active configuration
 */
void bdk_config_show(void)
{
    extern char **environ;
    if (!environ)
    {
        bdk_error("Environment not allocated\n");
        return;
    }

    char **ptr = environ;
    while (*ptr)
    {
        printf("    %s\n", *ptr);
        ptr++;
    }
}

/**
 * Display a list of all posssible config items with help text
 */
void bdk_config_help(void)
{
    for (bdk_config_t cfg = 0; cfg < __BDK_CONFIG_END; cfg++)
        printf("\n%s:\n%s\n", config_info[cfg].format, config_info[cfg].help);
}

static int config_read(const char *filename)
{
    char line[128];

    FILE *fp = fopen(filename, "r");
    if (!fp)
        return -1;

    while (fgets(line, sizeof(line), fp))
    {
        char *pv = line;
        char *p;

        /* ignore comments, empty lines and lines that start with a whitespace */
        if ('#' == *pv || '\n' == *pv || '\t' == *pv || ' ' == *pv)
            continue;

        /* find the '=' */
        pv = strchr(pv, '=');
        if (!pv)
        {
            bdk_warn("Malformed entry in BDK configuration file. Missing '=':\n"
                     "  %s\n", line);
            continue; /* no '=' in line, skip */
        }
        *pv = '\0'; /* split name and value */
        pv++;       /* now points to value */

        /* find '\n' and remove it */
        p = strchr(pv, '\n');
        if (p)
            *p = '\0';
        else
            bdk_warn("Possibly truncated variable '%s', value '%s'\n", line, pv);

        /* set variable */
        if (0 != setenv(line, pv, 1))
            break; /* bail on error */
    }

    fclose(fp);
    return 0;
}

/**
 * Internal BDK function to initialize the config system. Must be called before
 * any configuration functions are called
 */
void __bdk_config_init(void)
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

    config_read("/fatfs/default.cfg");
}
