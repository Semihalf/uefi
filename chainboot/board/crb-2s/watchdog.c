#include <bdk.h>

void watchdog_set(int timeout)
{
    BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()),
        c.s.len = timeout;
        c.s.mode = 3);
}

void watchdog_poke()
{
    BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);
}

void watchdog_disable()
{
    BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()), 0);
}
