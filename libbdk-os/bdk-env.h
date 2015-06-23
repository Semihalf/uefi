#ifndef __ENV_H__
#define __ENV_H__
/**
 * @file bdk-env.h
 *
 * Functions for reading and writing environment variable files.
 *
 * @{
 */

/*
 * Default filename and max file line length for the BDK configuration file to
 * save environment variables.
 */
#define BDK_ENV_CFG_FILE_NAME           "/fatfs/bdk.cfg"
#define BDK_ENV_CFG_FILE_LINE_MAX_LEN   100

/*
 * Table to hold cached environment variables that have been read from file.
 */
#define BDK_ENV_MAX_ENTRIES         128
#define BDK_ENV_ENTRY_NAME_MAX_LEN  32
#define BDK_ENV_ENTRY_VAL_MAX_LEN   32

/**
 * Set an environment variable
 *
 * @param name      Variable name
 * @param value     Variable value. If value is NULL then the variable will be
 *                  deleted.
 *
 * @return  None
 */
extern void bdk_setenv(const char *name, const char *value);

/**
 * Get an environment variable
 *
 * @param name      Variable name
 *
 * @return  String of variable value. NULL if variable does not exist or on
 *          error
 */
extern const char *bdk_getenv(const char *name);

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

/** @} */
#endif /* __ENV_H__ */


