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
#define BDK_BRD_CFG_DDR_UDIMM_SPEED         "DDR.SPEED.UDIMM.N%d"
#define BDK_BRD_CFG_DDR_RDIMM_SPEED         "DDR.SPEED.RDIMM.N%d"
#define BDK_BRD_CFG_BMC_TWSI                "BRD.CFG.BMC_TWSI"
#define BDK_BRD_CFG_MULTI_NODE              "BRD.CFG.MULTI_NODE"
#define BDK_BRD_CFG_DRAM_VERBOSE            "BRD.CFG.DRAM_VERBOSE"
#define BDK_BRD_CFG_DIAGS_GPIO_VALUE        "BRD.CFG.DIAGS_GPIO_VALUE"
#define BDK_BRD_CFG_DIAGS_GPIO              "BRD.CFG.DIAGS_GPIO"
#define BDK_BRD_CFG_BOARD                   "BRD.CFG.BOARD"

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
#define BDK_BRD_CFG_DISABLE_TWSI            "BRD.CFG.DISABLE_TWSI"
#define BDK_BRD_CFG_DISABLE_DRAM            "BRD.CFG.DISABLE_DRAM"
#define BDK_BRD_CFG_DISABLE_CCPI            "BRD.CFG.DISABLE_CCPI"
#define BDK_BRD_CFG_DISABLE_QLM             "BRD.CFG.DISABLE_QLM"
#define BDK_BRD_CFG_DISABLE_BGX             "BRD.CFG.DISABLE_BGX"
#define BDK_BRD_CFG_DISABLE_USB             "BRD.CFG.DISABLE_USB"
#define BDK_BRD_CFG_DISABLE_PCI             "BRD.CFG.DISABLE_PCI"

/**
 * Get a board configuration variable as integer
 *
 * @param format    Format for the variable name. Follows printf convention.
 *
 * @return          Variable value in long format
 */
extern long bdk_brd_cfg_get_int(const char *format, ...);

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
 * @param format    Format for the variable name. Follows printf convention.
 *
 * @return          Variable value in string format
 */
extern const char *bdk_brd_cfg_get_str(const char *format, ...);

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
