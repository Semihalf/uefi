#include <bdk.h>
#include "platform.h"
#include "common.h"

#define HEAP_BASE 0x8000000030000000
void *memory_start_address = (void*)HEAP_BASE;
void *memory_end_address = (void*)HEAP_BASE + (1<<20);

/**
 * Octeon platform init
 *
 * @return
 */
int platform_init()
{
    /* Setup eLua */
    cmn_platform_init();

    //platform_eth_initialize();

    return PLATFORM_OK;
}

/**
 * Set global interrupt state
 *
 * @param status
 *
 * @return
 */
int platform_cpu_set_global_interrupts( int status )
{
    int old_status;

    if (status == PLATFORM_CPU_ENABLE)
        BDK_EI(old_status);
    else
        BDK_DI(old_status);

    return (old_status) ? PLATFORM_CPU_ENABLE : PLATFORM_CPU_DISABLE;
}

/**
 * Get global interrupt state
 *
 * @return
 */
int platform_cpu_get_global_interrupts()
{
    int status;
    BDK_MF_COP0(status, COP0_STATUS);
    return (status & 1) ? PLATFORM_CPU_ENABLE : PLATFORM_CPU_DISABLE;
}

/**
 * Enable / disable an interrupt
 *
 * @param id
 * @param resnum
 * @param status
 *
 * @return
 */
int platform_cpu_set_interrupt( elua_int_id id, elua_int_resnum resnum, int status )
{
    // FIXME
    return 0;
}

/**
 * Get the CPU frequency
 *
 * @return
 */
u32 platform_cpu_get_frequency()
{
    return bdk_clock_get_rate(BDK_CLOCK_CORE);
}
