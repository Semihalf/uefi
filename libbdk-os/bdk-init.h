/**
 * @file
 *
 * Core initialization functions
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup thread Threading library
 * @{
 */

/**
 * Call this function to take secondary cores out of reset and have
 * them start running threads
 *
 * @param coremask Cores to start. Zero is a shortcut for all.
 *
 * @return Zero on success, negative on failure.
 */
extern int bdk_init_cores(uint64_t coremask);

/** @}  */
