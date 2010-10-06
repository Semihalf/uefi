// eLua platform configuration

#ifndef __PLATFORM_CONF_H__
#define __PLATFORM_CONF_H__

#include "auxmods.h"
#include "type.h"
#include "stacks.h"

// *****************************************************************************
// Define here what components you want for this platform

#define BUILD_XMODEM
#define BUILD_SHELL
#define BUILD_ROMFS
//#define BUILD_MMCFS
#define BUILD_TERM
#define BUILD_UIP
#define BUILD_DHCPC
#define BUILD_DNS
#define BUILD_CON_GENERIC
//#define BUILD_ADC
#define BUILD_RPC
//#define BUILD_CON_TCP

#define TERM_LINES    25
#define TERM_COLS     80
#define CON_UART_SPEED 115200

// *****************************************************************************
// Auxiliary libraries that will be compiled for this platform

#define LUA_PLATFORM_LIBS_ROM \
    _ROM(AUXLIB_PIO, luaopen_pio, pio_map) \
    _ROM(AUXLIB_SPI, luaopen_spi, spi_map) \
    /* _ROM(AUXLIB_CAN, luaopen_can, can_map) */ \
    _ROM(AUXLIB_TMR, luaopen_tmr, tmr_map) \
    _ROM(AUXLIB_PD, luaopen_pd, pd_map) \
    _ROM(AUXLIB_UART, luaopen_uart, uart_map) \
    _ROM(AUXLIB_TERM, luaopen_term, term_map) \
    _ROM(AUXLIB_PWM, luaopen_pwm, pwm_map) \
    _ROM(AUXLIB_PACK, luaopen_pack, pack_map) \
    _ROM(AUXLIB_BIT, luaopen_bit, bit_map) \
    _ROM(AUXLIB_NET, luaopen_net, net_map) \
    _ROM(AUXLIB_CPU, luaopen_cpu, cpu_map) \
    /* _ROM(AUXLIB_ADC, luaopen_adc, adc_map) */ \
    _ROM(AUXLIB_RPC, luaopen_rpc, rpc_map) \
    _ROM(AUXLIB_BITARRAY, luaopen_bitarray, bitarray_map) \
    _ROM(AUXLIB_ELUA, luaopen_elua, elua_map) \
    _ROM(AUXLIB_I2C, luaopen_i2c, i2c_map) \
    _ROM( LUA_MATHLIBNAME, luaopen_math, math_map )

// Bogus defines for common.c
#define CON_UART_ID           0
#define CON_TIMER_ID          0

// *****************************************************************************
// Configuration data

// Static TCP/IP configuration
#define ELUA_CONF_IPADDR0     10
#define ELUA_CONF_IPADDR1     0
#define ELUA_CONF_IPADDR2     0
#define ELUA_CONF_IPADDR3     2

#define ELUA_CONF_NETMASK0    255
#define ELUA_CONF_NETMASK1    255
#define ELUA_CONF_NETMASK2    255
#define ELUA_CONF_NETMASK3    0

#define ELUA_CONF_DEFGW0      10
#define ELUA_CONF_DEFGW1      0
#define ELUA_CONF_DEFGW2      0
#define ELUA_CONF_DEFGW3      1

#define ELUA_CONF_DNS0        10
#define ELUA_CONF_DNS1        0
#define ELUA_CONF_DNS2        0
#define ELUA_CONF_DNS3        1

// Virtual timers (0 if not used)
#define VTMR_NUM_TIMERS       0

// Number of resources (0 if not available/not implemented)
#define NUM_PIO               1
#define NUM_SPI               0
#define NUM_UART              2
#define NUM_TIMER             2
#define NUM_PWM               0
#define NUM_ADC               0
#define NUM_CAN               0

// CPU frequency (needed by the CPU module, 0 if not used)
#define CPU_FREQUENCY         0

// PIO prefix ('0' for P0, P1, ... or 'A' for PA, PB, ...)
#define PIO_PREFIX            'A'
// Pins per port configuration:
// #define PIO_PINS_PER_PORT (n) if each port has the same number of pins, or
// #define PIO_PIN_ARRAY { n1, n2, ... } to define pins per port in an array
// Use #define PIO_PINS_PER_PORT 0 if this isn't needed
#define PIO_PINS_PER_PORT     0

// Allocator data: define your free memory zones here in two arrays
// (start address and end address)
extern void *memory_start_address;
extern void *memory_end_address;
#define MEM_START_ADDRESS     { ( void* )memory_start_address }
#define MEM_END_ADDRESS       { ( void* )memory_end_address }

#endif // #ifndef __PLATFORM_CONF_H__
