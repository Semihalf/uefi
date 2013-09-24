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

    /* Setup LMTDMA to cache line 1 */
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        BDK_MF_COP0(memctl, COP0_CVMMEMCTL);
        memctl |= 1ull<<51;     // Enable LMTDMA
        memctl |= 1ull<<45;     // Use cache line 1
        BDK_MT_COP0(memctl, COP0_CVMMEMCTL);
        /* Zero the LMT cache line */
        for (int i=128; i<256; i+=8)
            bdk_scratch_write64(i, 0);
    }
}


static void __bdk_setup_bootbus(bdk_node_t node)
{
    /* Set each region to be max size, 256MB. Align regions such that
        a 128MB flash would alias to allow the MIPS boot region to see
        the first 4MB. This is only needed on region 0, but we do it on
        all regions to make the code easier */
    for (int region=0; region<8; region++)
    {
        BDK_CSR_MODIFY(c, node, BDK_MIO_BOOT_REG_CFGX(region),
            c.s.size = 0xfff;
            c.s.base = 0x0fc0 + region*0x2000);
    }
}

static void __bdk_error_poll(int arg, void *arg1)
{
    while (bdk_error_check)
    {
        bdk_error_check(bdk_numa_local());
        bdk_wait_usec(100000);
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
    bdk_node_t node = bdk_numa_local();
    /* All cores start running threads here. Only the setup required to get
        threading up is done. More init is needed. This code will be locked to
        a singel core with threads being spawned for each core */

    __bdk_init_cop0();

    if (bdk_is_boot_core())
    {
        if (BDK_SHOW_BOOT_BANNERS)
            printf("Performing common initialization\n");

        bdk_l2c_initialize(node);
        __bdk_config_init(); /* Some config setting are dynamically updated */

        extern char **environ;
        environ = calloc(sizeof(*environ), 1);
        if (!environ)
            bdk_error("Failed to allocate environment, setenv will crash\n");

        if (!bdk_is_simulation())
            __bdk_setup_bootbus(node);

        bdk_twsix_initialize(node);
        bdk_qlm_init(node);
        if (bdk_error_enable)
        {
            if (BDK_SHOW_BOOT_BANNERS)
                printf("Enabling error reporting\n");
            bdk_error_enable(node);
        }

        if (BDK_SHOW_BOOT_BANNERS)
        {
            for (int i=0; i<2; i++)
            {
                /* Always enable flow control in the simulator. The simulator reports
                    CTS=0, but it prevents the FIFO being overrun */
                if (!bdk_is_simulation() && BDK_CSR_WAIT_FOR_FIELD(node, BDK_MIO_UARTX_MSR(i), cts, ==, 1, 1000))
                {
                    bdk_warn("Not enabling hardware flow control on UART%d as CTS appears stuck\n", i);
                }
                else
                {
                    printf("Enabling hardware flow control on UART%d\n", i);
                    bdk_set_baudrate(node, i, 115200, 1);
                }
            }
        }

        /* Make sure SMI/MDIO is enabled so we can query PHYs */
        int num_mdio = (OCTEON_IS_MODEL(OCTEON_CN78XX)) ? 4 : 2;
        for (int i=0; i<num_mdio; i++)
        {
            BDK_CSR_INIT(smix_en, node, BDK_SMIX_EN(i));
            if (!smix_en.s.en)
            {
                smix_en.s.en = 1;
                BDK_CSR_WRITE(node, BDK_SMIX_EN(i), smix_en.u64);
            }
        }
    }

    /* Core 0 start main as another thread. We create a new thread so that
        the coremask will allow all cores in case the application
        goes multicore later */
    if (bdk_is_boot_core())
    {
        extern int main(int argc, const char *argv);
        if (BDK_SHOW_BOOT_BANNERS)
            printf("Switching to main\n");
        if (bdk_thread_create(node, 0, (bdk_thread_func_t)main, arg, arg1, BDK_THREAD_MAIN_STACK_SIZE))
            bdk_fatal("Create of main thread failed\n");
        if (&bdk_error_check && bdk_error_check)
            if (bdk_thread_create(node, 0, __bdk_error_poll, 0, NULL, 0))
                bdk_fatal("Create of error poll thread failed\n");

        /* The following code doesn't do anything useful. It forces a link
            dependency on bdk_require_depends(), which forces link dependency
            on needed components using BDK_REQUIRE() */
        __bdk_require_depends();
    }
}

