#include <bdk.h>
#include <stdio.h>
#include <unistd.h>

static int64_t __bdk_alive_coremask;
int __bdk_is_simulation;

static void __bdk_init_uart(int uart)
{
    /* Setup the UART */
    BDK_CSR_MODIFY(u, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 1; /* Divisor Latch Address bit */
        u.s.eps = 0; /* Even Parity Select bit */
        u.s.pen = 0; /* Parity Enable bit */
        u.s.stop = 0; /* Stop Control bit */
        u.s.cls = 3); /* Character Length Select */

    /* FCR is a write only register */
    BDK_CSR_WRITE(BDK_MIO_UARTX_FCR(uart), 7);

    int divisor = bdk_clock_get_rate(BDK_CLOCK_SCLK) / 115200 / 16;
    if (bdk_is_simulation())
        divisor = 1;

    BDK_CSR_WRITE(BDK_MIO_UARTX_DLH(uart), divisor>>8);
    BDK_CSR_WRITE(BDK_MIO_UARTX_DLL(uart), divisor & 0xff);

    BDK_CSR_MODIFY(u, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 0); /* Divisor Latch Address bit */
    BDK_CSR_READ(BDK_MIO_UARTX_LCR(uart));
    bdk_wait(1000);
}

static void __bdk_init_exception(void)
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

    /* Sync cycle counter */
    uint64_t core_rate = bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000000;
    uint64_t sclk_rate = bdk_clock_get_rate(BDK_CLOCK_SCLK) / 1000000;
    BDK_SYNC;
    /* Stagger the reads of SCK as we seem to get bad results on CN68XX
        pass 1.x if all cores do this at the same time */
    bdk_wait(bdk_get_core_num() << 8);
    uint64_t core_cycle = bdk_clock_get_count(BDK_CLOCK_SCLK) * core_rate / sclk_rate;
    BDK_MT_COP0(core_cycle, COP0_CVMCOUNT);

    static const char BANNER_1[] = "Bringup and Diagnostic Kit (BDK)\n";
    static const char BANNER_2[] = "Locking L2 cache\n";
    static const char BANNER_3[] = "Transferring to thread scheduler\n";

    BDK_MT_COP0(0, COP0_USERLOCAL);

    /* Initialize async WQE area with no work */
    bdk_scratch_write64(BDK_IF_SCR_WORK, 1ull<<63);

    if (bdk_get_core_num() == 0)
    {
        /* Initialize the is_simulation flag */
        {
            BDK_CSR_INIT(dbg, BDK_SLI_DBG_SELECT);
            BDK_CSR_DEFINE(tmp, BDK_SLI_DBG_SELECT);
            tmp = dbg;
            tmp.s.dbg_sel = 1;
            BDK_CSR_WRITE(BDK_SLI_DBG_SELECT, tmp.u64);
            tmp.u64 = BDK_CSR_READ(BDK_SLI_DBG_SELECT);
            BDK_CSR_WRITE(BDK_SLI_DBG_SELECT, dbg.u64);
            __bdk_is_simulation = (tmp.s.dbg_sel == 0);
        }

        __bdk_init_uart(0);
        __bdk_init_uart(1);

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_1, sizeof(BANNER_1)-1);
        __bdk_init_exception();

        /* Only lock L2 if DDR3 isn't initialized */
        BDK_CSR_INIT(lmcx_ddr_pll_ctl, BDK_LMCX_DDR_PLL_CTL(0));
        if ((lmcx_ddr_pll_ctl.s.reset_n == 0) && !bdk_is_simulation())
        {
            if (BDK_SHOW_BOOT_BANNERS)
                write(1, BANNER_2, sizeof(BANNER_2)-1);
            bdk_l2c_lock_mem_region(0, bdk_l2c_get_num_sets() * bdk_l2c_get_num_assoc() * BDK_CACHE_LINE_SIZE);
            /* The above locking will cause L2 to load zeros without DRAM setup.
                This will cause L2C_TADX_INT[rddislmc], which we suppress below */
            BDK_CSR_DEFINE(l2c_tadx_int, BDK_L2C_TADX_INT(0));
            l2c_tadx_int.u64 = 0;
            l2c_tadx_int.s.rddislmc = 1;
            if (!OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_X))
                BDK_CSR_WRITE(BDK_L2C_TADX_INT(0), l2c_tadx_int.u64);
            if (OCTEON_IS_MODEL(OCTEON_CN68XX))
            {
                BDK_CSR_WRITE(BDK_L2C_TADX_INT(1), l2c_tadx_int.u64);
                BDK_CSR_WRITE(BDK_L2C_TADX_INT(2), l2c_tadx_int.u64);
                BDK_CSR_WRITE(BDK_L2C_TADX_INT(3), l2c_tadx_int.u64);
            }
        }

        if (BDK_SHOW_BOOT_BANNERS)
            write(1, BANNER_3, sizeof(BANNER_3)-1);
        bdk_thread_initialize();
    }

    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(1<<22); // Clear BEV
    BDK_MT_COP0(status, COP0_STATUS);

    bdk_atomic_add64(&__bdk_alive_coremask, 1ull<<bdk_get_core_num());
    bdk_thread_first(__bdk_init_main, 0, NULL, 0);
}

int bdk_init_cores(uint64_t coremask)
{
    extern void __bdk_reset_vector(void);

    /* Install reset vector */
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_ADR, 0);
    const uint64_t *src = (const uint64_t *)__bdk_reset_vector;
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, 0xffffffff80002000);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_CFGX(0), 0x81fc0000ull);
    BDK_CSR_READ(BDK_MIO_BOOT_LOC_CFGX(0));

    /* Choose all cores by default */
    if (coremask == 0)
        coremask = -1;

    /* Limit to the cores that aren't already running */
    coremask &= ~__bdk_alive_coremask;

    /* Limit to the cores that exist */
    coremask &= (1ull<<bdk_octeon_num_cores()) - 1;

    /* First send a NMI */
    BDK_CSR_WRITE(BDK_CIU_NMI, coremask);

    /* Then take cores out of reset */
    uint64_t reset = BDK_CSR_READ(BDK_CIU_PP_RST);
    if (reset & coremask)
    {
        reset &= ~coremask;
        BDK_CSR_WRITE(BDK_CIU_PP_RST, reset);
    }

    /* Wait up to 10ms for the cores to boot */
    uint64_t timeout = bdk_clock_get_rate(BDK_CLOCK_CORE) / 100 + bdk_clock_get_count(BDK_CLOCK_CORE);
    while ((bdk_clock_get_count(BDK_CLOCK_CORE) < timeout) && ((bdk_atomic_get64(&__bdk_alive_coremask) & coremask) != coremask))
    {
        /* Tight spin */
    }

    if ((bdk_atomic_get64(&__bdk_alive_coremask) & coremask) != coremask)
    {
        bdk_error("Some cores failed to start. Alive mask 0x%lx, requested 0x%lx\n",
            __bdk_alive_coremask, coremask);
        return -1;
    }

    return 0;
}
