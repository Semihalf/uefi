/**
 * @file
 *
 * Functions for controlling the system configuration.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

#define BDK_CONFIG_MANUFACTURING_ADDRESS 0xff0000 /* 16MB - 64KB */

typedef enum
{
    /* Board manufacturing data */
    BDK_CONFIG_BOARD_MODEL,         /* No parameters */
    BDK_CONFIG_BOARD_REVISION,      /* No parameters */
    BDK_CONFIG_BOARD_SERIAL,        /* No parameters */
    BDK_CONFIG_MAC_ADDRESS,         /* No parameters */
    BDK_CONFIG_MAC_ADDRESS_NUM,     /* No parameters */

    /* Board generic */
    BDK_CONFIG_BMC_TWSI,            /* No parameters */
    BDK_CONFIG_WATCHDOG_TIMEOUT,    /* No parameters */
    BDK_CONFIG_TWSI_WRITE,          /* Parameters: Write number */
    BDK_CONFIG_MDIO_WRITE,          /* Parameters: Write number */

    /* Board wiring of network ports and PHYs */
    BDK_CONFIG_PHY_ADDRESS,         /* Parameters: Node, Interface, Port */
    BDK_CONFIG_BGX_ENABLE,          /* Parameters: Node, BGX, Port */

    /* BDK Configuration params */
    BDK_CONFIG_NUM_PACKET_BUFFERS,
    BDK_CONFIG_PACKET_BUFFER_SIZE,
    BDK_CONFIG_SHOW_LINK_STATUS,
    BDK_CONFIG_COREMASK,
    BDK_CONFIG_BOOT_MENU_TIMEOUT,
    BDK_CONFIG_BOOT_PATH_OPTION,
    BDK_CONFIG_TRACE,

    /* Chip feature items */
    BDK_CONFIG_MULTI_NODE,          /* No parameters */
    BDK_CONFIG_PCIE_EA,             /* No parameters */

    /* QLM related config */
    BDK_CONFIG_QLM_AUTO_CONFIG,     /* Parameters: Node */
    BDK_CONFIG_QLM_MODE,            /* Parameters: Node, QLM */
    BDK_CONFIG_QLM_FREQ,            /* Parameters: Node, QLM */
    BDK_CONFIG_QLM_CLK,             /* Parameters: Node, QLM */
    BDK_CONFIG_QLM_TUNING_TX_SWING, /* Parameters: Node, QLM, Lane */
    BDK_CONFIG_QLM_TUNING_TX_PREMPTAP, /* Parameters: Node, QLM, Lane */
    BDK_CONFIG_QLM_TUNING_TX_GAIN,  /* Parameters: Node, QLM, Lane */
    BDK_CONFIG_QLM_TUNING_TX_VBOOST, /* Parameters: Node, QLM, Lane */

    /* DRAM configuration options */
    BDK_CONFIG_DRAM_NODE,                                           /* Parameters: Node */
    BDK_CONFIG_DDR_SPEED,                                           /* Parameters: Node */
    BDK_CONFIG_DDR_ALT_REFCLK,                                      /* Parameters: Node */
    BDK_CONFIG_DDR_SPD_ADDR,                                        /* Parameters: DIMM, LMC, Node */
    BDK_CONFIG_DDR_SPD_DATA,                                        /* Parameters: DIMM, LMC, Node */
    BDK_CONFIG_DDR_RANKS_DQX_CTL,                                   /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
    BDK_CONFIG_DDR_RANKS_WODT_MASK,                                 /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_PASR,                                /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_ASR,                                 /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_SRT,                                 /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR,                              /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_DIC,                                 /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM,                             /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE1_DB_OUTPUT_IMPEDANCE,                 /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK,                            /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE,                          /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE,                          /* Parameters: Num Ranks, Num DIMMs, Rank, LMC, Node */
    BDK_CONFIG_DDR_RANKS_MODE2_VREFDQ_TRAIN_EN,                     /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
    BDK_CONFIG_DDR_RANKS_RODT_CTL,                                  /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
    BDK_CONFIG_DDR_RANKS_RODT_MASK,                                 /* Parameters: Num Ranks, Num DIMMs, LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MIN_RTT_NOM_IDX,                          /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MAX_RTT_NOM_IDX,                          /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MIN_RODT_CTL,                             /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MAX_RODT_CTL,                             /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_CK_CTL,                                   /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_CMD_CTL,                                  /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_CTL_CTL,                                  /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MIN_CAS_LATENCY,                          /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_OFFSET_EN,                                /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_OFFSET,                                   /* Parameters: Type(UDIMM,RDIMM), LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMPUTE,                           /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_DDR_RTT_NOM_AUTO,                         /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_DDR_RODT_CTL_AUTO,                        /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMP_OFFSET,                       /* Parameters: Type(UDIMM,RDIMM), LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_RLEVEL_AVERAGE_LOOPS,                     /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_DDR2T,                                    /* Parameters: Type(UDIMM,RDIMM), LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_DISABLE_SEQUENTIAL_DELAY_CHECK,           /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MAXIMUM_ADJACENT_RLEVEL_DELAY_INCREMENT,  /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_PARITY,                                   /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_FPRCH2,                                   /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MODE32B,                                  /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_MEASURED_VREF,                            /* Parameters: LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_DLL_WRITE_OFFSET,                         /* Parameters: Byte, LMC, Node */
    BDK_CONFIG_DDR_CUSTOM_DLL_READ_OFFSET,                          /* Parameters: Byte, LMC, Node */

    /* High level DRAM options */
    BDK_CONFIG_DRAM_VERBOSE,        /* Parameters: Node */
    BDK_CONFIG_DRAM_BOOT_TEST,      /* Parameters: Node */
    BDK_CONFIG_DRAM_CONFIG_GPIO,    /* No parameters */

    /* USB */
    BDK_CONFIG_USB_PWR_GPIO,        /* Parameters: Node, Port */

    /* How EYE diagrams are captured from a QLM */
    BDK_CONFIG_EYE_ZEROS,           /* No parameters */
    BDK_CONFIG_EYE_SAMPLE_TIME,     /* No parameters */
    BDK_CONFIG_EYE_SETTLE_TIME,     /* No parameters */

    __BDK_CONFIG_END
} bdk_config_t;

/**
 * Internal BDK function to initialize the config system. Must be called before
 * any configuration functions are called
 */
extern void __bdk_config_init(void);

/**
 * Return a help string for the given configuration parameter
 *
 * @param cfg_item Configuration parameter to get help for
 *
 * @return Help string for the user
 */
extern const char *bdk_config_get_help(bdk_config_t cfg_item);

/**
 * Get an integer configuration item
 *
 * @param cfg_item  Config item to get. If the item takes parameters (see bdk_config_t), then the
 *                  parameters are listed following cfg_item.
 *
 * @return The value of the configuration item, or def_value if the item is not set
 */
extern int64_t bdk_config_get_int(bdk_config_t cfg_item, ...);

/**
 * Get a string configuration item
 *
 * @param cfg_item  Config item to get. If the item takes parameters (see bdk_config_t), then the
 *                  parameters are listed following cfg_item.
 *
 * @return The value of the configuration item, or def_value if the item is not set
 */
extern const char *bdk_config_get_str(bdk_config_t cfg_item, ...);

/**
 * Get a binary blob
 *
 * @param blob_size Integer to receive the size of the blob
 * @param cfg_item  Config item to get. If the item takes parameters (see bdk_config_t), then the
 *                  parameters are listed following cfg_item.
 *
 * @return The value of the configuration item, or def_value if the item is not set
 */
extern const void *bdk_config_get_blob(int *blob_size, bdk_config_t cfg_item, ...);

/**
 * Set an integer configuration item. Note this only sets the item in memory,
 * persistent storage is not updated.
 *
 * @param value    Configuration item value
 * @param cfg_item Config item to set. If the item takes parameters (see bdk_config_t), then the
 *                 parameters are listed following cfg_item.
 */
extern void bdk_config_set_int(int64_t value, bdk_config_t cfg_item, ...);

/**
 * Set an integer configuration item. Note this only sets the item in memory,
 * persistent storage is not updated.
 *
 * @param value    Configuration item value
 * @param cfg_item Config item to set. If the item takes parameters (see bdk_config_t), then the
 *                 parameters are listed following cfg_item.
 */
extern void bdk_config_set_str(const char *value, bdk_config_t cfg_item, ...);

/**
 * Set a blob configuration item. Note this only sets the
 * item in memory, persistent storage is not updated.
 *
 * @param size     Size of the item in bytes. A size of zero removes the device tree field
 * @param value    Configuration item value
 * @param cfg_item Config item to set. If the item takes parameters (see bdk_config_t), then the
 *                 parameters are listed following cfg_item.
 */
extern void bdk_config_set_blob(int size, const void *value, bdk_config_t cfg_item, ...);

/**
 * Display the active configuration
 */
extern void bdk_config_show(void);

/**
 * Display a list of all posssible config items with help text
 */
extern void bdk_config_help(void);

/**
 * Save the current configuration to flash
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_config_save(void);

/**
 * Takes the current live device tree and exports it to a memory address suitable
 * for passing to the enxt binary in register X1.
 *
 * @return Physical address of the device tree, or 0 on failure
 */
extern uint64_t __bdk_config_export_to_mem(void);

/** @} */
