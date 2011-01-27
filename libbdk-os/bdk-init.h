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

/**
 * This function is the first function run on all cores once the
 * threading system takes over.
 *
 * @param arg
 * @param arg1
 */
extern void bdk_init_main(int arg, void *arg1);

/** @}  */
