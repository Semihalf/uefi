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
    volatile u64 *lsr_ptr = (volatile u64 *)0x8001180000000828ull;
    volatile u64 *rbr_ptr = (volatile u64 *)0x8001180000000800ull;

    if (timeout == PLATFORM_UART_INFINITE_TIMEOUT)
    {
        while ((*lsr_ptr & 1) == 0) {}
        return *rbr_ptr;
    }
    else if (*lsr_ptr & 1)
        return *rbr_ptr;
    else
        return -1;
}

static inline u64 octeon_get_clock_count(void)
{
    u64 cycle;
    asm volatile ("rdhwr %0, $31" : "=r" (cycle));
    return cycle;
}

static inline u64 octeon_get_clock_rate(void)
{
    const u64 REF_CLOCK = 50000000;
    static u64 rate_eclk = 0;

    if (!rate_eclk)
    {
        u64 mio_rst_boot = *(volatile u64*)0x8001180000001600ull;
        rate_eclk =  REF_CLOCK * ((mio_rst_boot>>30) & 0x3f);
    }
    return rate_eclk;
}

void platform_s_timer_delay( unsigned id, u32 delay_us )
{
    u64 delay = octeon_get_clock_rate() * delay_us / 1000000;
    u64 finish = octeon_get_clock_count() + delay;
    while (octeon_get_clock_count() < finish) {}
}

u32 platform_s_timer_op( unsigned id, int op, u32 data )
{
    switch( op )
    {
        case PLATFORM_TIMER_OP_START:
            return (u32)octeon_get_clock_count();

        case PLATFORM_TIMER_OP_READ:
            return (u32)octeon_get_clock_count();

        case PLATFORM_TIMER_OP_GET_MAX_DELAY:
            return platform_timer_get_diff_us( id, 0, 0xFFFFFFFF );

        case PLATFORM_TIMER_OP_GET_MIN_DELAY:
            return platform_timer_get_diff_us( id, 0, 1 );

        case PLATFORM_TIMER_OP_SET_CLOCK:
            return octeon_get_clock_rate();

        case PLATFORM_TIMER_OP_GET_CLOCK:
            return octeon_get_clock_rate();
    }
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

