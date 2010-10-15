#include <bdk.h>

static void __bdk_init_uart(int uart)
{
    /* Setup the UART */
    BDK_CSR_MODIFY(u, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 1; /* Divisor Latch Address bit */
        u.s.eps = 0; /* Even Parity Select bit */
        u.s.pen = 0; /* Parity Enable bit */
        u.s.stop = 0; /* Stop Control bit */
        u.s.cls = 3); /* Character Length Select */

    BDK_CSR_MODIFY(u, BDK_MIO_UARTX_FCR(uart),
        u.s.en = 1);

    int divisor = bdk_clock_get_rate(BDK_CLOCK_SCLK) / 115200 / 16;
    if (bdk_is_simulation())
        divisor = 1;

    BDK_CSR_WRITE(BDK_MIO_UARTX_DLH(uart), divisor>>8);
    BDK_CSR_WRITE(BDK_MIO_UARTX_DLL(uart), divisor & 0xff);

    BDK_CSR_MODIFY(u, BDK_MIO_UARTX_LCR(uart),
        u.s.dlab = 0); /* Divisor Latch Address bit */
    BDK_CSR_READ(BDK_MIO_UARTX_LCR(uart));
}

static void __bdk_init_exception(void)
{
    extern void bdk_exception(void);

    /* Install exception vectors */
    void *ebase = (void*)0xffffffff80000000l;
    BDK_MT_COP0(ebase, COP0_EBASE);
    memcpy(ebase, &bdk_exception, 0x80); /* TLB */
    memcpy(ebase + 0x80, &bdk_exception, 0x80); /* XTLB */
    memcpy(ebase + 0x100, &bdk_exception, 0x80); /* Cache Error */
    memcpy(ebase + 0x180, &bdk_exception, 0x80); /* General Exception */
    memcpy(ebase + 0x200, &bdk_exception, 0x80); /* Interrupt */
    BDK_SYNC;
    BDK_ICACHE_INVALIDATE;
}

static void __bdk_init_cop0(void)
{
    int status;
    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(1<<22); // Clear BEV
    status &= ~(3<<1); // Clear ERL and EXC
    BDK_MT_COP0(status, COP0_STATUS);
}

static void __bdk_init_relocate_data(void)
{
    extern void _fdata; /* Beginning of .data section */
    extern void _edata; /* End of .data section, beginning of .bss */
    uint64_t data_physical = bdk_ptr_to_phys(&_fdata);

    /* We must rlocate our data section if it is on the bootbus */
    if ((data_physical >= 0x10000000) && (data_physical < 0x20000000))
    {
        void *new_loc = bdk_phys_to_ptr(0x500);
        memmove(new_loc, &_fdata, (&_edata - &_fdata));
        uint64_t entryhi = (long)&_fdata;
        entryhi &= ~bdk_build_mask(13);
        BDK_MT_COP0(entryhi, COP0_ENTRYHI);
        BDK_TLBP;
        BDK_MT_COP0(7, COP0_ENTRYLO0);
        BDK_MT_COP0(1, COP0_ENTRYLO1);
        BDK_TLBWI;
    }
}

void bdk_init(void)
{
    extern int main(int argc, const char *argv);
    extern void _edata; /* End of .data section, beginning of .bss */
    extern void _end;   /* End of entire .data */

    if (bdk_get_core_num() == 0)
    {
        __bdk_init_uart(0);
        __bdk_init_exception();
        __bdk_init_relocate_data();

        /* Zero BSS */
        memset(&_edata, 0, &_end - &_edata);

        bdk_thread_initialize();

        if (bdk_thread_create(-1, (bdk_thread_func_t)main, 0, NULL))
            bdk_fatal("Create of main thread failed\n");
    }

    __bdk_init_cop0();

    bdk_thread_yield();
    bdk_thread_destroy();
}
