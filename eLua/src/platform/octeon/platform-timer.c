#include <bdk.h>
#include "platform.h"

void platform_s_timer_delay( unsigned id, u32 delay_us )
{
    bdk_wait_usec(delay_us);
}

u32 platform_s_timer_op( unsigned id, int op, u32 data )
{
    switch( op )
    {
        case PLATFORM_TIMER_OP_START:
            return (u32)bdk_clock_get_count(BDK_CLOCK_CORE);

        case PLATFORM_TIMER_OP_READ:
            return (u32)bdk_clock_get_count(BDK_CLOCK_CORE);

        case PLATFORM_TIMER_OP_GET_MAX_DELAY:
            return platform_timer_get_diff_us( id, 0, 0xFFFFFFFF );

        case PLATFORM_TIMER_OP_GET_MIN_DELAY:
            return platform_timer_get_diff_us( id, 0, 1 );

        case PLATFORM_TIMER_OP_SET_CLOCK:
            return bdk_clock_get_rate(BDK_CLOCK_CORE);

        case PLATFORM_TIMER_OP_GET_CLOCK:
            return bdk_clock_get_rate(BDK_CLOCK_CORE);
    }
    return 0;
}

