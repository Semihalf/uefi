#include <bdk.h>


static void __bdk_init_cop0(void)
{
    int status;
    BDK_MF_COP0(status, COP0_STATUS);
    status |= 1<<30;        // Enable COP2
    BDK_MT_COP0(status, COP0_STATUS);

    uint64_t ctl;
    BDK_MF_COP0(ctl, COP0_CVMCTL);
    ctl &= ~(7<<7);         // Set perf interrupts to IRQ 6
    ctl |= 6<<7;
    BDK_MT_COP0(ctl, COP0_CVMCTL);

    uint64_t memctl;
    BDK_MF_COP0(memctl, COP0_CVMMEMCTL);
    memctl |= 7ull<<37;     // Max pause time
    memctl |= 1ull<<35;     // Marked WB entries timeout same as normal
    memctl &= ~(0xf<<11);   // Set WBTHRESH=4
    memctl |= 4<<11;
    memctl &= -64;          // Setup two lines of scratch
    memctl |= 2;
    BDK_MT_COP0(memctl, COP0_CVMMEMCTL);

    /* Sync cycle counter */
    uint64_t core_cycle = bdk_clock_get_count(BDK_CLOCK_SCLK) * bdk_clock_get_rate(BDK_CLOCK_CORE) / bdk_clock_get_rate(BDK_CLOCK_SCLK);
    BDK_MT_COP0(core_cycle, COP0_CVMCOUNT);
}

/**
 * This function is the first function run on all cores once the
 * threading system takes over.
 *
 * @param arg
 * @param arg1
 */
void bdk_init_main(int arg, void *arg1)
{
    /* All cores start running threads here. Only the setup required to get
        threading up is done. More init is needed. This code will be locked to
        a singel core with threads being spawned for each core */

    __bdk_init_cop0();

    /* Core 0 start main as another thread. We create a new thread so that
        the coremask will allow all cores in case the application
        goes multicore later */
    if (bdk_get_core_num() == 0)
    {
        extern int main(int argc, const char *argv);
        if (bdk_thread_create(0, (bdk_thread_func_t)main, arg, arg1))
            bdk_fatal("Create of main thread failed\n");
    }
}

