#include <bdk.h>
#include "platform.h"

int platform_i2c_exists( unsigned id )
{
    return 0;
}

u32 platform_i2c_setup( unsigned id, u32 speed )
{
    return 0;
}

void platform_i2c_send_start( unsigned id )
{
}

void platform_i2c_send_stop( unsigned id )
{
}

int platform_i2c_send_address( unsigned id, u16 address, int direction )
{
    return 0;
}

int platform_i2c_send_byte( unsigned id, u8 data )
{
    return 0;
}

int platform_i2c_recv_byte( unsigned id, int ack )
{
    return 0;
}

