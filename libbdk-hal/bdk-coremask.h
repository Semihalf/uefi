/**
 * @file
 *
 * Module to support operations on bitmap of cores. Coremask can be used to
 * select a specific core, a group of cores, or all available cores, for
 * initialization and differentiation of roles within a single shared binary
 * executable image.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 */

/*
 * coremask is simply unsigned int (32 bits).
 *
 * NOTE: supports up to 32 cores maximum.
 *
 * union of coremasks is simply bitwise-or.
 * intersection of coremasks is simply bitwise-and.
 *
 */

#define  BDK_COREMASK_MAX  0xFFFFFFFFu    /* maximum supported mask */


/**
 * Compute coremask for a specific core.
 *
 * @param  core_id  The core ID
 *
 * @return  coremask for a specific core
 *
 */
static inline unsigned int bdk_coremask_core(unsigned int core_id)
{
    return (1u << core_id);
}

/**
 * Compute coremask for num_cores cores starting with core 0.
 *
 * @param  num_cores  number of cores
 *
 * @return  coremask for num_cores cores
 *
 */
static inline unsigned int bdk_coremask_numcores(unsigned int num_cores)
{
    return (BDK_COREMASK_MAX >> (32 - num_cores));
}

/**
 * Compute coremask for a range of cores from core low to core high.
 *
 * @param  low   first core in the range
 * @param  high  last core in the range
 *
 * @return  coremask for the range of cores
 *
 */
static inline unsigned int bdk_coremask_range(unsigned int low, unsigned int high)
{
    return ((BDK_COREMASK_MAX >> (31 - high + low)) << low);
}


/**
 * Test to see if current core is a member of coremask.
 *
 * @param  coremask  the coremask to test against
 *
 * @return  1 if current core is a member of coremask, 0 otherwise
 *
 */
static inline int bdk_coremask_is_member(unsigned int coremask)
{
    return ((bdk_coremask_core(bdk_get_core_num()) & coremask) != 0);
}

/**
 * Test to see if current core is first core in coremask.
 *
 * @param  coremask  the coremask to test against
 *
 * @return  1 if current core is first core in the coremask, 0 otherwise
 *
 */
static inline int bdk_coremask_first_core(unsigned int coremask)
{
    return bdk_coremask_is_member(coremask)
        && ((bdk_get_core_num() == 0) ||
            ((bdk_coremask_numcores(bdk_get_core_num()) & coremask) == 0));
}

/**
 * Wait (stall) until all cores in the given coremask has reached this point
 * in the program execution before proceeding.
 *
 * @param  coremask  the group of cores performing the barrier sync
 *
 */
extern void bdk_coremask_barrier_sync(unsigned int coremask);

