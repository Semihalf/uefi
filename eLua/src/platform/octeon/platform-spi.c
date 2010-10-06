#include <bdk.h>
#include "platform.h"

int platform_spi_exists( unsigned id )
{
    return 0;
}

u32 platform_spi_setup( unsigned id, int mode, u32 clock, unsigned cpol, unsigned cpha, unsigned databits )
{
    return 0;
}

spi_data_type platform_spi_send_recv( unsigned id, spi_data_type data )
{
    return 0;
}

void platform_spi_select( unsigned id, int is_select )
{
}

