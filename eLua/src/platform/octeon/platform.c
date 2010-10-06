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

