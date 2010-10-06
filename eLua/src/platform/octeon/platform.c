#include <bdk.h>
#include "platform.h"
#include "common.h"

char memory[1<<20];
void *memory_start_address;
void *memory_end_address;

/**
 * Octeon platform init
 *
 * @return
 */
int platform_init()
{
    memory_start_address = memory;
    memory_end_address = memory_start_address + sizeof(memory);
    cmn_platform_init();
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

