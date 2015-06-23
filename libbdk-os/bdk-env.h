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
 * Default filename and max file line length for the BDK configuration file to
 * save environment variables.
 */
#define BDK_ENV_CFG_FILE_NAME           "/fatfs/bdk.cfg"

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
/** @} */
#endif /* __BDK_ENV_H__ */
