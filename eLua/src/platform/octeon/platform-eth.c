#include <bdk.h>
#include "platform.h"

void platform_eth_send_packet( const void* src, u32 size )
{
}

u32 platform_eth_get_packet_nb( void* buf, u32 maxlen )
{
    return 0;
}

void platform_eth_force_interrupt()
{
}

u32 platform_eth_get_elapsed_time()
{
    return 0;
}

