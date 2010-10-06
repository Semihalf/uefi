#include <bdk.h>
#include "platform.h"

u32 platform_can_setup( unsigned id, u32 clock )
{
    return 0;
}

void platform_can_send( unsigned id, u32 canid, u8 idtype, u8 len, const u8 *data )
{
}

void platform_can_recv( unsigned id, u32 *canid, u8 *idtype, u8 *len, u8 *data )
{
}

