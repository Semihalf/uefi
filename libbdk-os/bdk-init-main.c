#include <bdk.h>
#include <stdio.h>


/**
 * Do per core initialization of system registers
 */
static void __bdk_init_sysreg(void)
{
    /* Errata (AP-22500) GlobalSync request during a multi-cycle ATOMIC
       stalls forever */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
    {
        /* Disable compare and swap on CN88XX pass 1.x */
        bdk_sys_cvmctl_el1_t cvmctl_el1;
        /* Sadly, our own silly compiler doesn't unstand our registers */
        BDK_MRS(s3_0_c11_c0_0, cvmctl_el1.u);
        cvmctl_el1.s.disable_casp = 1;
        cvmctl_el1.s.disable_cas = 1;
        BDK_MSR(s3_0_c11_c0_0, cvmctl_el1.u);
    }
}

/**
 * Run on each node as a thread to perform error reporting
 *
 * @param arg
 * @param arg1
 */
static void __bdk_error_poll(int arg, void *arg1)
{
    while (bdk_error_check)
    {
        bdk_error_check(bdk_numa_local());
        bdk_wait_usec(100000);
    }
}

/**
 * Perfome one time initalization for a node. Called for each node.
 */
static void __bdk_init_local_node(void)
{
    bdk_node_t node = bdk_numa_local();

    BDK_TRACE(INIT, "N%d: Performing node initialization\n", node);

    BDK_TRACE(INIT, "N%d: Initialize L2\n", node);
    bdk_l2c_initialize(node);
    BDK_TRACE(INIT, "N%d: Initialize random number generator\n", node);
    bdk_rng_enable(node);

    if (BDK_IS_REQUIRED(PCIE))
    {
        BDK_TRACE(INIT, "N%d: Performing global PCIe initialization\n", node);
        bdk_pcie_global_initialize(node);
    }
    if (BDK_IS_REQUIRED(QLM))
    {
        BDK_TRACE(INIT, "N%d: Performing global QLM initialization\n", node);
        bdk_qlm_init(node);
    }
    if (BDK_IS_REQUIRED(TWSI))
    {
        BDK_TRACE(INIT, "N%d: Initialize TWSI\n", node);
        bdk_twsix_initialize(node);
    }
    if (bdk_mdio_initialize)
    {
        BDK_TRACE(INIT, "N%d: Initialize MDIO\n", node);
        bdk_mdio_initialize(node);
    }

    /* Allow all IO units to access secure memory */
    for (int smmu = 0; smmu < 4; smmu++)
    {
        BDK_TRACE(INIT, "N%d: Initialize SMMU%d\n", node, smmu);
        for (int id = 0; id < 2048; id++)
            BDK_CSR_WRITE(bdk_numa_local(), BDK_SMMUX_SSDRX(smmu, id), 0);
    }


    if (BDK_IS_REQUIRED(ERROR_DECODE) && !bdk_is_simulation())
    {
        BDK_TRACE(INIT, "N%d: Enabling error reporting\n", node);
        bdk_error_enable(node);
        if (bdk_error_check)
        {
            if (bdk_thread_create(node, 0, __bdk_error_poll, 0, NULL, 0))
                bdk_fatal("Create of error poll thread failed\n");
        }
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
    const bdk_node_t node = bdk_numa_local();
    /* All cores start running threads here. Only the setup required to get
        threading up is done. More init is needed. This code will be locked to
        a single core with threads being spawned for each core */

    /* Unlock the global stack now that we aren't using it anymore */
    extern volatile uint64_t __bdk_initial_stack_start;
    BDK_WMB;
    __bdk_initial_stack_start = 0;
    BDK_WMB;

    /* Init any system registers that need to be done on every core */
    BDK_TRACE(INIT, "N%d: Initialize system registers on Core %d\n", node, bdk_get_core_num());
    __bdk_init_sysreg();

    /* Perform one time init that must be done on the master node. This
       will not be run on the other nodes */
    if (bdk_is_boot_core())
    {
        BDK_TRACE(INIT, "Performing common initialization\n");

        __bdk_config_init(); /* Some config setting are dynamically updated */

        BDK_TRACE(INIT, "N%d: Setup environment\n", node);
        extern char **environ;
        environ = calloc(sizeof(*environ), 1);
        if (!environ)
            bdk_error("Failed to allocate environment, setenv will crash\n");
    }

    /* Perform initialization that needs to be done once per node */
    if (bdk_get_core_num() == 0)
        __bdk_init_local_node();

    /* Core 0 start main as another thread. We create a new thread so that
        the coremask will allow all cores in case the application
        goes multicore later */
    if (bdk_is_boot_core())
    {
        extern int main(int argc, const char *argv);
        BDK_TRACE(INIT, "Switching to main\n");
        if (bdk_thread_create(node, 0, (bdk_thread_func_t)main, arg, arg1, BDK_THREAD_MAIN_STACK_SIZE))
            bdk_fatal("Create of main thread failed\n");

        /* The following code doesn't do anything useful. It forces a link
            dependency on bdk_require_depends(), which forces link dependency
            on needed components using BDK_REQUIRE() */
        __bdk_require_depends();
    }
}

