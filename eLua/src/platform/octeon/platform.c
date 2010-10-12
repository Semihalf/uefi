#include <bdk.h>
#include "platform.h"
#include "common.h"

void *memory_start_address;
void *memory_end_address;

/**
 * Octeon platform init
 *
 * @return
 */
int platform_init()
{
    extern void bdk_exception(void);
    uint32_t ebase;

    /* Setup the HEAP */
    memory_start_address = bdk_phys_to_ptr(0x30000000);
    memory_end_address = memory_start_address + (1<<20);

    /* Setup eLua */
    cmn_platform_init();

    platform_cpu_set_global_interrupts(PLATFORM_CPU_DISABLE);

    /* Install exception vectors */
    ebase = 0x80000000;
    BDK_MT_COP0(ebase, COP0_EBASE);
    void *ebase_ptr = (void*)(int)ebase;
    memcpy(ebase_ptr, (void*)bdk_exception, 0x80); /* TLB */
    memcpy(ebase_ptr + 0x80, (void*)bdk_exception, 0x80); /* XTLB */
    memcpy(ebase_ptr + 0x100, (void*)bdk_exception, 0x80); /* Cache Error */
    memcpy(ebase_ptr + 0x180, (void*)bdk_exception, 0x80); /* General Exception */
    memcpy(ebase_ptr + 0x200, (void*)bdk_exception, 0x80); /* Interrupt */
    BDK_SYNC;
    BDK_ICACHE_INVALIDATE;

    int status;
    BDK_MF_COP0(status, COP0_STATUS);
    //status |= 1<<15; // Enable interrupt 7
    status &= ~(1<<22); // Clear BEV
    status &= ~(3<<1); // Clear ERL and EXC
    BDK_MT_COP0(status, COP0_STATUS);

    platform_uart_setup(0, 115200, 8, 0, 1);

    //platform_eth_initialize();

    platform_cpu_set_global_interrupts(PLATFORM_CPU_ENABLE);

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

void *memcpy(void *dest, const void *src, size_t n)
{
    char *d = dest;
    const char *s = src;
    while (n--)
        *d++ = *s++;
    return dest;
}

int memcmp(const void *s1, const void *s2, size_t n)
{
    const char *p1 = s1;
    const char *p2 = s2;
    while (n--)
    {
        int r = (*p1 - *p2);
        if (r)
            return r;
    }
    return 0;
}
