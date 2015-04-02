#include <bdk.h>
#include <stdio.h>


/**
 * Do per core initialization of system registers
 */
static void __bdk_init_sysreg(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
    {
        bdk_sys_cvmctl_el1_t cvmctl_el1;
        BDK_MRS(s3_0_c11_c0_0, cvmctl_el1.u);

        /* Errara (AP-22934) CIM module has incorrect conditional clock */
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_0))
            cvmctl_el1.s.force_issue_clock = 1;

        /* Errata (AP-22500) GlobalSync request during a multi-cycle ATOMIC
           stalls forever */
        /* Disable compare and swap on CN88XX pass 1.x */
        cvmctl_el1.s.disable_casp = 1;
        cvmctl_el1.s.disable_cas = 1;

        BDK_MSR(s3_0_c11_c0_0, cvmctl_el1.u);
    }

    /* The defaults for write buffer timeouts are poor */
    bdk_sys_cvmmemctl0_el1_t cvmmemctl0_el1;
    BDK_MRS(s3_0_c11_c0_4, cvmmemctl0_el1.u);
    cvmmemctl0_el1.s.wbftonshena = 1; /* NSH has 2^18 timeout. All BDK mem is NSH */
    cvmmemctl0_el1.s.wbftomrgclrena = 1; /* Reset timer on merge. Hardware default is brain dead */
    BDK_MSR(s3_0_c11_c0_4, cvmmemctl0_el1.u);
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
 * Perform one time initialization for a node. Called for each
 * node from the master node.
 */
void __bdk_init_node(bdk_node_t node)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && !bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        /* Disable the CCPI lane timers as early as possible. This will make
           the hardware wait forever for CCPI lane to come up */
        for (int i = 0; i<6; i++)
        {
            BDK_CSR_MODIFY(c, node, BDK_OCX_QLMX_CFG(i),
                c.s.timer_dis = 1);
        }
    }

    /* Enable the timer. Do this first as many things depend on the clock */
    bdk_clock_setup(node);

    BDK_TRACE(INIT, "N%d: Performing node initialization\n", node);

    /* Allow CAP access from cores so we can read system registers through
       memory mapped addresses. See bdk_sysreg_read() */
    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
        BDK_CSR_MODIFY(c, node, BDK_DAP_IMP_DAR, c.s.caben = 1);

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
    if (BDK_IS_REQUIRED(MDIO))
    {
        BDK_TRACE(INIT, "N%d: Initialize MDIO\n", node);
        bdk_mdio_initialize(node);
    }

    /* Allow all IO units to access secure memory */
    for (int smmu = 0; smmu < 4; smmu++)
    {
        BDK_TRACE(INIT, "N%d: Initialize SMMU%d\n", node, smmu);
        for (int id = 0; id < 2048; id++)
            BDK_CSR_WRITE(node, BDK_SMMUX_SSDRX(smmu, id), 0);
    }

    if (BDK_IS_REQUIRED(TNS))
    {
        BDK_TRACE(INIT, "N%d: Initialize TNS\n", node);
        bdk_tns_initialize(node);
    }

    if (BDK_IS_REQUIRED(ERROR_DECODE) && !bdk_is_platform(BDK_PLATFORM_ASIM))
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
        BDK_TRACE(INIT, "N%d: Performing common initialization\n", node);

        __bdk_config_init(); /* Some config setting are dynamically updated */

        BDK_TRACE(INIT, "N%d: Setup environment\n", node);
        extern char **environ;
        environ = calloc(sizeof(*environ), 1);
        if (!environ)
            bdk_error("Failed to allocate environment, setenv will crash\n");

        BDK_TRACE(INIT, "N%d: Checking if CCPI is already up and has other nodes\n", node);
        BDK_CSR_INIT(l2c_oci_ctl, node, BDK_L2C_OCI_CTL);
        for (bdk_node_t n = 0; n < BDK_NUMA_MAX_NODES; n++)
        {
            if (l2c_oci_ctl.s.enaoci & (1 << n))
            {
                BDK_TRACE(INIT, "N%d:     Found node %d\n", node, n);
                bdk_numa_set_exists(n);
            }
        }
        if (!bdk_numa_is_only_one())
            bdk_config_set(BDK_CONFIG_ENABLE_MULTINODE, 1);
    }

    /* Core 0 start main as another thread. We create a new thread so that
        the coremask will allow all cores in case the application
        goes multicore later */
    if (bdk_is_boot_core())
    {
        __bdk_init_node(node);
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

