/**
 * @file
 *
 * Functions for determining the current chip features.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup chips Chips and features
 * @{
 */


/**
 * Return true if the software is currently running on the
 * software simulator.
 *
 * @return Non zero if simulation
 */
static inline int bdk_is_simulation(void) __attribute__ ((pure));
static inline int bdk_is_simulation(void)
{
    extern int __bdk_is_simulation;
    return __bdk_is_simulation;
}

/** @} */
