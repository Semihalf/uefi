#ifndef __BDK_ENV_H__
#define __BDK_ENV_H__
/**
 * @file bdk-env.h
 *
 * Functions for reading and writing environment variable files.
 *
 * @{
 */

/*
 * Default filename for the board configuration file.
 */
#define BDK_BRD_CFG_MAX_VAR_NAME_LEN    200

/*
 * Default filename and max file line length for the BDK configuration file to
 * safe environment variables.
 */
#define BDK_ENV_CFG_FILE_NAME           "/fatfs/default.cfg"
#define BDK_ENV_CFG_FILE_NAME_SAFE_MODE "/fatfs/safe-mode.cfg"

/*
 * Maximum line length allowed for key/value pair in configuration file.
 */
#define BDK_ENV_MAX_LINE_LEN            256

/**
 * Load a set of environment variables from file
 *
 * @param filename  Name of configuration file (NULL == use default name)
 *
 * @return 0 == OK, -1 == error
 */
extern int bdk_loadenv(const char *filename);

/**
 * Save the current set of environment variables to file
 *
 * @param filename  Name of configuration file (NULL == use default name)
 *
 * @return 0 == OK, -1 == error
 */
extern int bdk_saveenv(const char *filename);

/**
 * Set or delete an environment variable
 *
 * @param name      Name of the variable
 * @param value     Value of the variable (NULL == delete the variable)
 *
 * @return
 */
extern void bdk_setenv(const char *name, const char *value);

/**
 * Print the list of environment variables
 *
 * @return
 */
extern void bdk_showenv(void);


/*
 * Definitions related to board configuration.
 */
#define BDK_BRD_CFG_QLM_MODE                "QLM.MODE.N%d.QLM%d"
#define BDK_BRD_CFG_QLM_FREQ                "QLM.FREQ.N%d.QLM%d"
#define BDK_BRD_CFG_QLM_CLK                 "QLM.CLK.N%d.QLM%d"
#define BDK_BRD_CFG_QLM_TUNING_TX_SWING     "QLM.TUNING.TX_SWING.N%d.QLM%d.LANE%d"
#define BDK_BRD_CFG_QLM_TUNING_TX_PREMPTAP  "QLM.TUNING.TX_PREMPTAP.N%d.QLM%d.LANE%d"
#define BDK_BRD_CFG_QLM_TUNING_TX_GAIN      "QLM.TUNING.TX_GAIN.N%d.QLM%d.LANE%d"
#define BDK_BRD_CFG_QLM_TUNING_TX_VBOOST    "QLM.TUNING.TX_VBOOST.N%d.QLM%d.LANE%d"
#define BDK_BRD_CFG_DDR_UDIMM_SPEED         "DDR.SPEED.UDIMM.N%d"
#define BDK_BRD_CFG_DDR_RDIMM_SPEED         "DDR.SPEED.RDIMM.N%d"
#define BDK_BRD_CFG_BGX_ENABLE              "BGX.ENABLE.N%d.BGX%d.P%d"
#define BDK_BRD_CFG_BMC_TWSI                "BRD.CFG.BMC_TWSI"
#define BDK_BRD_CFG_MULTI_NODE              "BRD.CFG.MULTI_NODE"
#define BDK_BRD_CFG_DRAM_VERBOSE            "BRD.CFG.DRAM_VERBOSE"
#define BDK_BRD_CFG_DIAGS_GPIO_VALUE        "BRD.CFG.DIAGS_GPIO_VALUE"
#define BDK_BRD_CFG_DIAGS_GPIO              "BRD.CFG.DIAGS_GPIO"
#define BDK_BRD_CFG_BOARD                   "BRD.CFG.BOARD"
#define BDK_BRD_CFG_USB_PWR_GPIO            "BRD.CFG.USB_PWR_GPIO.N%d"
#define BDK_BRD_CFG_QLM_MODE_AUTO_CONFIG    "BRD.CFG.QLM_MODE_AUTO_CONFIG"
#define BDK_BRD_CFG_WATCHDOG_TIMEOUT        "BRD.CFG.WATCHDOG_TIMEOUT"
#define BDK_BRD_CFG_DRAM_NODE               "BRD.CFG.DRAM.N%d"

/*
 * Definitions controlling how EYE diagrams are captured from a QLM
 */
#define BDK_QLM_CFG_EYE_ZEROS               "QLM.EYE.NUM_ZEROS"     /* Number of consecutive zeros that signals an eye (default 2) */
#define BDK_QLM_CFG_EYE_SAMPLE_TIME         "QLM.EYE.SAMPLE_TIME"   /* Time (us) to count errors at each location (default 400us) */
#define BDK_QLM_CFG_EYE_SETTLE_TIME         "QLM.EYE.SETTLE_TIME"   /* Time (us) to settle between location movements (Default 50us) */

/*
 * Which peripherals to configure at boot time.
 *
 * By default the generic boot code tries to initialize all peripherals on the
 * board. Initialization of peripherals can be disabled by adding:
 *
 *   BRD.CFG.DISABLE_xxxx=1
 *
 * to the configuration file, where xxxx is the ID of the peripheral.
 */
#define BDK_BRD_CFG_DISABLE_DRAM            "BRD.CFG.DISABLE_DRAM"
#define BDK_BRD_CFG_DISABLE_CCPI            "BRD.CFG.DISABLE_CCPI"
#define BDK_BRD_CFG_DISABLE_QLM             "BRD.CFG.DISABLE_QLM"
#define BDK_BRD_CFG_DISABLE_BGX             "BRD.CFG.DISABLE_BGX"
#define BDK_BRD_CFG_DISABLE_USB             "BRD.CFG.DISABLE_USB"
#define BDK_BRD_CFG_DISABLE_PCI             "BRD.CFG.DISABLE_PCI"

/**
 * Get a board configuration variable as integer
 *
 * @param dflt      Default value to return on error.
 * @param format    Format for the variable name. Follows printf convention.
 *
 * @return          Variable value in int64_t format
 */
extern int64_t bdk_brd_cfg_get_int(int64_t dflt, const char *format, ...);

/**
 * Set a board configuration variable as long
 *
 * @param format    Format for the variable name. Follows printf convention.
 * @param value     Value to set
 *
 * @return
 */
extern void bdk_brd_cfg_set_int(long value, const char *format, ...);

/**
 * Get a board configuration variable as string
 *
 * @param dflt      Default value to return on error.
 * @param format    Format for the variable name. Follows printf convention.
 *
 * @return          Variable value in string format
 */
extern const char *bdk_brd_cfg_get_str(const char *dflt, const char *format, ...);

/**
 * Set a board configuration variable as string
 *
 * @param format    Format for the variable name. Follows printf convention.
 * @param value     Value to set
 *
 * @return
 */
extern void bdk_brd_cfg_set_str(const char *value, const char *format, ...);

/** @} */
#endif /* __BDK_ENV_H__ */
