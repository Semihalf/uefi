#include <bdk.h>
#include "platform.h"

/**
 * Wait for the specified micorseconds to pass
 *
 * @param id
 * @param delay_us
 */
void platform_s_timer_delay( unsigned id, u32 delay_us )
{
    bdk_wait_usec(delay_us);
}

/**
 * Tiemr control function
 *
 * @param id
 * @param op
 * @param data
 *
 * @return
 */
u32 platform_s_timer_op( unsigned id, int op, u32 data )
{
    int clock;
    switch (id)
    {
        case 0:
            /* Using the core cycle counter */
            clock = BDK_CLOCK_CORE;
            break;
        case 1:
            /* Using the IO cycle counter */
            clock = BDK_CLOCK_SCLK;
            break;
        default:
            return 0;
    }

    switch( op )
    {
        case PLATFORM_TIMER_OP_START:
            /* Timer is always running, so we don't need to start it */
            return (u32)bdk_clock_get_count(clock);

        case PLATFORM_TIMER_OP_READ:
            return (u32)bdk_clock_get_count(clock);

        case PLATFORM_TIMER_OP_GET_MAX_DELAY:
            /* Really is 64bit, but eLua doesn't understand anything bigger than 32 bits */
            return platform_timer_get_diff_us( id, 0, 0xFFFFFFFF );

        case PLATFORM_TIMER_OP_GET_MIN_DELAY:
            return platform_timer_get_diff_us( id, 0, 1 );

        case PLATFORM_TIMER_OP_SET_CLOCK:
            /* You can't change the timer's tick rate */
            return bdk_clock_get_rate(clock);

        case PLATFORM_TIMER_OP_GET_CLOCK:
            /* Return the clock rate */
            return bdk_clock_get_rate(clock);
    }
    return 0;
}

