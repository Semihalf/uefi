/**
 * @file
 *
 * Interface to Core, IO and DDR Clock.
 *
 * <hr>$Revision: 45089 $<hr>
*/

/**
 * Enumeration of different Clocks in Octeon.
 */
typedef enum{
    BDK_CLOCK_RCLK,        /**< Clock used by cores, coherent bus and L2 cache. */
    BDK_CLOCK_SCLK,        /**< Clock used by IO blocks. */
    BDK_CLOCK_CORE,        /**< Alias for BDK_CLOCK_RCLK */
    BDK_CLOCK_TIM,         /**< Alias for BDK_CLOCK_SCLK */
    BDK_CLOCK_IPD,         /**< Alias for BDK_CLOCK_SCLK */
} bdk_clock_t;

/**
 * Get cycle count based on the clock type.
 *
 * @param clock - Enumeration of the clock type.
 * @return      - Get the number of cycles executed so far.
 */
static inline uint64_t bdk_clock_get_count(bdk_clock_t clock)
{
    switch(clock)
    {
        case BDK_CLOCK_RCLK:
        case BDK_CLOCK_CORE:
        {
            uint64_t cycle;
            BDK_RDHWR(cycle, 31);
            return(cycle);
        }

        case BDK_CLOCK_SCLK:
        case BDK_CLOCK_TIM:
        case BDK_CLOCK_IPD:
            return BDK_CSR_READ(BDK_IPD_CLK_COUNT);
    }
    return 0;
}

extern uint64_t bdk_clock_get_rate(bdk_clock_t clock);

