/**
 * @file
 *
 * Interface to Core, IO and DDR Clock.
 *
 * <hr>$Revision: 45089 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Enumeration of different Clocks.
 */
typedef enum{
    BDK_CLOCK_RCLK,        /**< Clock used by cores, coherent bus and L2 cache. */
    BDK_CLOCK_SCLK,        /**< Clock used by IO blocks. */
    BDK_CLOCK_CORE,        /**< Alias for BDK_CLOCK_RCLK */
} bdk_clock_t;

/**
 * Get cycle count based on the clock type.
 *
 * @param clock - Enumeration of the clock type.
 * @return      - Get the number of cycles executed so far.
 */
static inline uint64_t bdk_clock_get_count(bdk_clock_t clock) __attribute__ ((always_inline));
static inline uint64_t bdk_clock_get_count(bdk_clock_t clock)
{
    switch(clock)
    {
        case BDK_CLOCK_RCLK:
        case BDK_CLOCK_CORE:
        {
            uint64_t count;
            BDK_MRS(CNTPCT_EL0, count);
            return count;// FIXME: Read RCLK
        }

        case BDK_CLOCK_SCLK:
        {
            uint64_t count;
            BDK_MRS(CNTPCT_EL0, count);
            return count;// FIXME: Read SCLK
        }
    }
    return 0;
}

extern uint64_t bdk_clock_get_rate(bdk_node_t node, bdk_clock_t clock) __attribute__ ((pure));

/** @} */
