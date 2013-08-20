#include <bdk.h>
#include <stdio.h>
#include <unistd.h>

static int64_t __bdk_alive_coremask[BDK_NUMA_MAX_NODES];
int __bdk_is_simulation;

/**
 * Set the baud rate on a UART
 *
 * @param uart     uart to set
 * @param baudrate Baud rate (9600, 19200, 115200, etc)
 * @param use_flow_control
 *                 Non zero if hardware flow control should be enabled
 */
void bdk_set_baudrate(bdk_node_t node, int uart, int baudrate, int use_flow_control)
{
    /* Setup the UART */
    BDK_CSR_MODIFY(u, node, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 1; /* Divisor Latch Address bit */
        u.s.eps = 0; /* Even Parity Select bit */
        u.s.pen = 0; /* Parity Enable bit */
        u.s.stop = 0; /* Stop Control bit */
        u.s.cls = 3); /* Character Length Select */

    /* FCR is a write only register */
    BDK_CSR_WRITE(node, BDK_MIO_UARTX_FCR(uart), 7);

    int divisor = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / baudrate / 16;
    if (bdk_is_simulation())
        divisor = 1;

    BDK_CSR_WRITE(node, BDK_MIO_UARTX_DLH(uart), divisor>>8);
    BDK_CSR_WRITE(node, BDK_MIO_UARTX_DLL(uart), divisor & 0xff);

    BDK_CSR_MODIFY(u, node, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 0); /* Divisor Latch Address bit */
    BDK_CSR_READ(node, BDK_MIO_UARTX_LCR(uart));
    bdk_wait(1000);

    use_flow_control = !!use_flow_control;
    BDK_CSR_MODIFY(mcr, node, BDK_MIO_UARTX_MCR(uart),
        mcr.s.afce = use_flow_control;
        mcr.s.rts = use_flow_control);
}

static void __bdk_init_exception(bdk_node_t node)
{
    extern void __bdk_exception(void);

    /* Install exception vectors */
    void *ebase = (void*)0xffffffff80000000l;
    BDK_MT_COP0(ebase, COP0_EBASE);
    memcpy(ebase, &__bdk_exception, 0x80); /* TLB */
    memcpy(ebase + 0x80, &__bdk_exception, 0x80); /* XTLB */
    memcpy(ebase + 0x100, &__bdk_exception, 0x80); /* Cache Error */
    memcpy(ebase + 0x180, &__bdk_exception, 0x80); /* General Exception */
    memcpy(ebase + 0x200, &__bdk_exception, 0x80); /* Interrupt */
    BDK_SYNC;
    BDK_ICACHE_INVALIDATE;
}

void __bdk_init(long base_address) __attribute((noreturn));
void __bdk_init(long base_address)
{
    /* Enable RDHWR */
    BDK_MT_COP0(0xe000000f, COP0_HWRENA);

    /* Clear cause */
    BDK_MT_COP0(0, COP0_CAUSE);

    /* Clear ENTRYHI[ASID] to keep simulator happy */
    BDK_MT_COP0(0, COP0_ENTRYHI);

    /* Disable ERL, EXL, and IE */
    uint32_t status;
    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(0xff<<8);   /* Clear IM enables */
    status |= 1<<23;        /* Enable 64bit user opcodes */
    status |= 7<<5;         /* Enable 64bit in Kernel, super, and user */
    status &= ~(3<<3);      /* Set kernel mode */
    status &= ~(1<<2);      /* Disable ERL */
    status &= ~(1<<1);      /* Disable EXL */
    status &= ~(1<<0);      /* Disable IE */
    BDK_MT_COP0(status, COP0_STATUS);

    /* Use unaligned instructions */
    uint64_t cvmctl;
    BDK_MF_COP0(cvmctl, COP0_CVMCTL);
    cvmctl |= 1<<12;    /* Use unaligned instructions */
    cvmctl |= 1<<14;    /* Fix unaligned accesses */
    BDK_MT_COP0(cvmctl, COP0_CVMCTL);

    bdk_node_t node = bdk_numa_local();
    bdk_numa_set_running(node);

    /* Sync cycle counter */
    uint64_t core_rate = bdk_clock_get_rate(node, BDK_CLOCK_CORE) / 1000000;
    uint64_t sclk_rate = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000;
    BDK_SYNC;
    uint64_t core_cycle = bdk_clock_get_count(BDK_CLOCK_SCLK) * core_rate / sclk_rate;
    BDK_MT_COP0(core_cycle, COP0_CVMCOUNT);

    static const char BANNER_1[] = "Bringup and Diagnostic Kit (BDK)\n";
    static const char BANNER_2[] = "Locking L2 cache\n";
    static const char BANNER_3[] = "Transferring to thread scheduler\n";

    BDK_MT_COP0(0, COP0_USERLOCAL);

    /* Initialize async WQE area with no work */
    bdk_scratch_write64(BDK_IF_SCR_WORK, 1ull<<63);

    if (bdk_is_boot_core())
    {
        /* Shut off cores in reset to save power. This is a new feature in
            Octeon 3. It is optional, but probably good practice. When taking
            cores out of reset, it will be necessary t oclear the correct bit
            that was set here */
        if (OCTEON_IS_MODEL(OCTEON_CN70XX) || OCTEON_IS_MODEL(OCTEON_CN78XX))
        {
            /* Get a list of cores in reset */
            uint64_t reset = BDK_CSR_READ(node, BDK_CIU_PP_RST);
            /* Power off the core in reset */
            BDK_CSR_WRITE(node, BDK_RST_PP_POWER, reset);
        }

        /* Initialize the is_simulation flag */
        if (OCTEON_IS_MODEL(OCTEON_CN78XX) || OCTEON_IS_MODEL(OCTEON_CN70XX))
        {
            BDK_CSR_INIT(c, node, BDK_OCLAX_CONST(0));
            __bdk_is_simulation = (c.u == 0);
        }
        else
        {
            BDK_CSR_INIT(dbg, node, BDK_SLI_DBG_SELECT);
            BDK_CSR_DEFINE(tmp, BDK_SLI_DBG_SELECT);
            tmp = dbg;
            tmp.s.dbg_sel = 1;
            BDK_CSR_WRITE(node, BDK_SLI_DBG_SELECT, tmp.u64);
            tmp.u64 = BDK_CSR_READ(node, BDK_SLI_DBG_SELECT);
            BDK_CSR_WRITE(node, BDK_SLI_DBG_SELECT, dbg.u64);
            __bdk_is_simulation = (tmp.s.dbg_sel == 0);
        }

        bdk_set_baudrate(node, 0, 115200, 0);
        bdk_set_baudrate(node, 1, 115200, 0);
        bdk_fs_set_uart_node(node);

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_1, sizeof(BANNER_1)-1);
        __bdk_init_exception(node);

        /* Only lock L2 if DDR3 isn't initialized */
        BDK_CSR_INIT(lmcx_ddr_pll_ctl, node, BDK_LMCX_DDR_PLL_CTL(0));
        if ((lmcx_ddr_pll_ctl.s.reset_n == 0) && !bdk_is_simulation())
        {
            if (BDK_SHOW_BOOT_BANNERS)
                write(1, BANNER_2, sizeof(BANNER_2)-1);
            bdk_l2c_lock_mem_region(node, 0, bdk_l2c_get_num_sets(node) * bdk_l2c_get_num_assoc(node) * BDK_CACHE_LINE_SIZE);
            /* The above locking will cause L2 to load zeros without DRAM setup.
                This will cause L2C_TADX_INT[rddislmc], which we suppress below */
            BDK_CSR_DEFINE(l2c_tadx_int, BDK_L2C_TADX_INT(0));
            l2c_tadx_int.u64 = 0;
            if (OCTEON_IS_MODEL(OCTEON_CN70XX) || OCTEON_IS_MODEL(OCTEON_CN78XX))
                l2c_tadx_int.cn78xx.rddislmc = 1;
            else
                l2c_tadx_int.cn70xx.rddislmc = 1;
            BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(0), l2c_tadx_int.u64);
            if (OCTEON_IS_MODEL(OCTEON_CN68XX) || OCTEON_IS_MODEL(OCTEON_CN78XX))
            {
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(1), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(2), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(3), l2c_tadx_int.u64);
            }
            if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            {
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(4), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(5), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(6), l2c_tadx_int.u64);
                BDK_CSR_WRITE(node, BDK_L2C_TADX_INT(7), l2c_tadx_int.u64);
            }
        }

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_3, sizeof(BANNER_3)-1);
        bdk_thread_initialize();
    }

    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(1<<22); // Clear BEV
    BDK_MT_COP0(status, COP0_STATUS);

    bdk_atomic_add64(&__bdk_alive_coremask[node], bdk_core_to_mask());
    bdk_thread_first(__bdk_init_main, 0, NULL, 0);
}

int bdk_init_cores(bdk_node_t node, uint64_t coremask)
{
    extern void __bdk_reset_vector(void);
    extern void __bdk_reset_vector_data(void);

    /* Install reset vector */
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_ADR, 0);
    int length = (__bdk_reset_vector_data - __bdk_reset_vector)/8;
    if (length > 16)
    {
        bdk_error("Reset vector too large. No secondary cores can boot\n");
        return -1;
    }
    const uint64_t *src = (const uint64_t *)__bdk_reset_vector;
    while (length--)
        BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_DAT, *src++);
    /* We will now be at __bdk_reset_vector_data. Write the jump address
        and KSEGNODE */
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_DAT, 0xffffffff80002000);
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_DAT, bdk_numa_master());
    /* Now set the address and enable it */
    BDK_CSR_WRITE(node, BDK_MIO_BOOT_LOC_CFGX(0), 0x81fc0000ull);
    BDK_CSR_READ(node, BDK_MIO_BOOT_LOC_CFGX(0));

    /* Choose all cores by default */
    if (coremask == 0)
        coremask = -1;

    /* Limit to the cores that aren't already running */
    coremask &= ~__bdk_alive_coremask[node];

    /* Limit to the cores that are specified in configuration menu */
    uint64_t config_coremask = bdk_config_get(BDK_CONFIG_COREMASK);
    if (config_coremask)
        coremask &= config_coremask;

    /* Limit to the cores that exist */
    coremask &= (1ull<<bdk_octeon_num_cores(node)) - 1;

    /* First send a NMI */
    BDK_CSR_WRITE(node, BDK_CIU_NMI, coremask);

    /* Then take cores out of reset */
    uint64_t reset = BDK_CSR_READ(node, BDK_CIU_PP_RST);
    if (reset & coremask)
    {
        reset &= ~coremask;
        BDK_CSR_WRITE(node, BDK_CIU_PP_RST, reset);
    }

    if (OCTEON_IS_MODEL(OCTEON_CN70XX) || OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        /* We may also need to turn power on (new in Octeon 3) */
        uint64_t power = BDK_CSR_READ(node, BDK_RST_PP_POWER);
        if (power & coremask)
        {
            reset &= ~coremask;
            BDK_CSR_WRITE(node, BDK_RST_PP_POWER, power);
        }
    }

    /* Wait up to 100us for the cores to boot */
    uint64_t timeout = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 10000 + bdk_clock_get_count(BDK_CLOCK_CORE);
    while ((bdk_clock_get_count(BDK_CLOCK_CORE) < timeout) && ((bdk_atomic_get64(&__bdk_alive_coremask[node]) & coremask) != coremask))
    {
        /* Tight spin */
    }

    if ((bdk_atomic_get64(&__bdk_alive_coremask[node]) & coremask) != coremask)
    {
        bdk_error("Node %d: Some cores failed to start. Alive mask 0x%lx, requested 0x%lx\n",
            node, __bdk_alive_coremask[node], coremask);
        return -1;
    }

    return 0;
}

/**
 * Call this function to take secondary nodes and cores out of
 * reset and have them start running threads
 *
 * @return Zero on success, negative on failure.
 */
int bdk_init_nodes(void)
{
    int result = 0;
    for (int node=0; node<BDK_NUMA_MAX_NODES; node++)
    {
        if ((1<<node) & bdk_numa_get_exists_mask())
            result |= bdk_init_cores(node, 0);
    }
    return result;
}

