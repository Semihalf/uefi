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
 * save environment variables.
 */
#define BDK_ENV_CFG_FILE_NAME           "/fatfs/default.cfg"
#define BDK_ENV_CFG_FILE_NAME_SAVE_MODE "/fatfs/save-mode.cfg"

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
#define BRD_CFG_QLM_MODE    "QLM.MODE.N%d.I%d"
#define BRD_CFG_QLM_FREQ    "QLM.FREQ.N%d.I%d"

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
