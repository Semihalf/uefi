#include <bdk.h>
#include <stdio.h>


static void __bdk_init_sysreg(void)
{
    // FIXME: Setup Thunder sysreg
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

    __bdk_init_sysreg();

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

        if (!bdk_is_simulation()) // FIXME: Not modelled in asim
        {
            if (BDK_IS_REQUIRED(TWSI))
                bdk_twsix_initialize(node);
            if (BDK_IS_REQUIRED(QLM))
                bdk_qlm_init(node);
            if (bdk_error_enable)
            {
                if (BDK_SHOW_BOOT_BANNERS)
                    printf("Enabling error reporting\n");
                bdk_error_enable(node);
            }
        }

        if (BDK_SHOW_BOOT_BANNERS)
        {
            for (int i=0; i<2; i++)
            {
                /* Always enable flow control in the simulator. The simulator reports
                    CTS=0, but it prevents the FIFO being overrun */
                if (!bdk_is_simulation() && BDK_CSR_WAIT_FOR_FIELD(node, BDK_UAAX_FR(i), cts, ==, 1, 1000))
                    printf("Hardware flow control disabled on UART%d\n", i);
                else
                {
                    bdk_set_baudrate(node, i, BDK_UART_BAUDRATE, 1);
                    printf("Hardware flow control enabled on UART%d\n", i);
                }
            }
        }

        /* Make sure SMI/MDIO is enabled so we can query PHYs */
        int num_mdio = bdk_is_simulation() ? 0 : 4; // FIXME: Not modelled in asim
        for (int i=0; i<num_mdio; i++)
        {
            BDK_CSR_INIT(smix_en, node, BDK_SMI_X_EN(i));
            if (!smix_en.s.en)
            {
                smix_en.s.en = 1;
                BDK_CSR_WRITE(node, BDK_SMI_X_EN(i), smix_en.u);
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

