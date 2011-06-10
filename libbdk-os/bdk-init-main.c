#include <bdk.h>
#include <stdio.h>


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


static void __bdk_setup_bootbus(void)
{
    const int region_size = 256 << 20;
    /* Skip region 0 as it's location is set earlier in boot. We reserve
        0-region_size to be used by region 0. Normally it only uses a small
        part of that */
    for (int region=1; region<8; region++)
    {
        /* Set each region to be region_size, one after the other. We're
            going to use 64bit addressing to access them, so we cna make
            them big */
        BDK_CSR_MODIFY(c, BDK_MIO_BOOT_REG_CFGX(region),
            c.s.size = (region_size >> 16) - 1;
            c.s.base = region_size >> 16);
    }
}


/**
 * This function is the first function run on all cores once the
 * threading system takes over.
 *
 * @param arg
 * @param arg1
 */
void __bdk_init_main(int arg, void *arg1)
{
    /* All cores start running threads here. Only the setup required to get
        threading up is done. More init is needed. This code will be locked to
        a singel core with threads being spawned for each core */

    __bdk_init_cop0();

    if (bdk_get_core_num() == 0)
    {
        printf("Performing common initialization\n");

        bdk_l2c_initialize();

        if (!bdk_is_simulation())
            __bdk_setup_bootbus();

        bdk_qlm_init();
        bdk_fpa_enable();
        bdk_dma_engine_initialize();

        if (BDK_CSR_WAIT_FOR_FIELD(BDK_MIO_UARTX_MSR(0), cts, ==, 1, 1000))
        {
            bdk_warn("Not enabling hardware flow control on UART0 as CTS appears stuck\n");
        }
        else
        {
            printf("Enabling hardware flow control on UART0\n");
            BDK_CSR_MODIFY(mcr, BDK_MIO_UARTX_MCR(0),
                mcr.s.afce = 1;
                mcr.s.rts = 1);
        }

        /* Set the lower MAC address bits based on the chip manufacturing
            information. This should give reasonable MAC address defaults
            for production parts */
        BDK_CSR_INIT(fus_dat0, BDK_MIO_FUS_DAT0);
        uint64_t mac_address = bdk_config_get(BDK_CONFIG_MAC_ADDRESS);
        mac_address |= fus_dat0.u64 & 0xffffff;
        bdk_config_set(BDK_CONFIG_MAC_ADDRESS, mac_address);
    }

    /* Core 0 start main as another thread. We create a new thread so that
        the coremask will allow all cores in case the application
        goes multicore later */
    if (bdk_get_core_num() == 0)
    {
        extern int main(int argc, const char *argv);
        printf("Switching to main\n");
        if (bdk_thread_create(0, (bdk_thread_func_t)main, arg, arg1, 0))
            bdk_fatal("Create of main thread failed\n");
    }
}

