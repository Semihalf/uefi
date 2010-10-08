#include <bdk.h>

char bdk_exception_stack[1024];

void bdk_exception_handler(uint64_t saved_regs[34])
{
    // FIXME
    extern void platform_eth_force_interrupt();

    int cause;
    BDK_MF_COP0(cause, COP0_CAUSE);
    if (cause & (1<<15))
    {
        uint32_t compare;
        BDK_MF_COP0(compare, COP0_COMPARE);
        compare += bdk_clock_get_rate(BDK_CLOCK_CORE) / 10;
        BDK_MT_COP0(compare, COP0_COMPARE);
        platform_eth_force_interrupt();
    }
}
