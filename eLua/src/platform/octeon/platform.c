#include "platform.h"
#include "common.h"

char memory[1<<20];
void *memory_start_address;
void *memory_end_address;
//void *__cvmx_pci_console_write_ptr = NULL;

int platform_init()
{
    memory_start_address = memory;
    memory_end_address = memory_start_address + sizeof(memory);
    cmn_platform_init();
  return PLATFORM_OK;
}


// ****************************************************************************
// "Dummy" UART functions

u32 platform_uart_setup( unsigned id, u32 baud, int databits, int parity, int stopbits )
{
  return 0;
}

void platform_uart_send( unsigned id, u8 data )
{
    u64 lsrval;

    /* Spin until there is room */
    do
    {
        lsrval = *(volatile u64*)0x8001180000000828ull;
    } while ((lsrval & (1<<5)) == 0);
    /* Write the byte */
    *(volatile u64*)0x8001180000000840ull = data;
}

int platform_s_uart_recv( unsigned id, s32 timeout )
{
    u64 lsrval = *(volatile u64*)0x8001180000000828ull;

    if (lsrval & 1)
        return *(volatile u64*)0x8001180000000800ull;
    else
        return 0;
}

// ****************************************************************************
// "Dummy" timer functions

void platform_s_timer_delay( unsigned id, u32 delay_us )
{
}

u32 platform_s_timer_op( unsigned id, int op, u32 data )
{
  return 0;
}

u32 platform_pwm_op( unsigned id, int op, u32 data )
{
    return 0;
}
u32 platform_pwm_setup( unsigned id, u32 frequency, unsigned duty )
{
    return 0;
}

pio_type platform_pio_op( unsigned port, pio_type pinmask, int op )
{
    return 0;
}

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

int platform_cpu_set_global_interrupts( int status )
{
    return 0;
}

int platform_cpu_get_global_interrupts()
{
    return 0;
}

int platform_cpu_set_interrupt( elua_int_id id, elua_int_resnum resnum, int status )
{
    return 0;
}

int platform_cpu_get_interrupt( elua_int_id id, elua_int_resnum resnum )
{
    return 0;
}

u32 platform_cpu_get_frequency()
{
    return 0;
}


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

