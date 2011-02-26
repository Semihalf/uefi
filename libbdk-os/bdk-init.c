#include <bdk.h>
#include <stdio.h>
#include <unistd.h>

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

static void bdk_init_stage2(void) __attribute((noreturn, noinline));
static void bdk_init_stage2(void)
{
    extern void _fbss;  /* Beginning of .bss */
    extern void _ebss;  /* End of .bss */
    static const char BANNER_1[] = "Bring and Diagnostic Kit (BDK)\n";
    static const char BANNER_2[] = "Setting up global data\n";
    static const char BANNER_3[] = "Clearing BSS\n";
    static const char BANNER_4[] = "Transferring to thread scheduler\n";

    BDK_MT_COP0(0, COP0_USERLOCAL);

    if (bdk_get_core_num() == 0)
    {
        __bdk_init_uart(0);
        __bdk_init_uart(1);

        write(1, BANNER_1, sizeof(BANNER_1)-1);
        __bdk_init_exception();

        write(1, BANNER_2, sizeof(BANNER_2)-1);
        bdk_l2c_lock_mem_region(0, bdk_l2c_get_num_sets() * (bdk_l2c_get_num_assoc()-1) * BDK_CACHE_LINE_SIZE);

        /* Zero BSS */
        write(1, BANNER_3, sizeof(BANNER_3)-1);
        memset(&_fbss, 0, &_ebss - &_fbss);

        write(1, BANNER_4, sizeof(BANNER_4)-1);
        bdk_thread_initialize();
    }

    int status;
    BDK_MF_COP0(status, COP0_STATUS);
    status &= ~(1<<22); // Clear BEV
    BDK_MT_COP0(status, COP0_STATUS);

    if (bdk_thread_create(1ull<<bdk_get_core_num(), __bdk_init_main, 0, NULL, 0))
        bdk_fatal("Create of __bdk_init_main thread failed\n");
    bdk_thread_destroy();
}

void __bdk_init(long base_address) __attribute((noreturn));
void __bdk_init(long base_address)
{
    /* Although we are running C code, we have not setup the TLB yet. This
        means that all data accessed will fault and we can't make subroutine
        calls. Once the basic TLB stuff is setup, we will jump to
        bdk_init_stage2(), which is a normal C environment */
    extern void _fdata; /* Beginning of .data section */
    const uint64_t mask_512MB = 0x1fffffff;

    /* Enable RDHWR */
    BDK_MT_COP0(0xe000000f, COP0_HWRENA);

    /* Clear cause */
    BDK_MT_COP0(0, COP0_CAUSE);

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

    /* Clear the TLB */
    BDK_MT_COP0(0, COP0_ENTRYLO0);
    BDK_MT_COP0(0, COP0_ENTRYLO1);
    BDK_MT_COP0(0, COP0_PAGEMASK);
    uint64_t vaddr = 3ull<<62;
    int count = 128;
    while (count-- > 0)
    {
        uint64_t index;
        do
        {
            BDK_MT_COP0(vaddr, COP0_ENTRYHI);
            BDK_TLBP;
            BDK_MF_COP0(index, COP0_INDEX);
            vaddr += 0x2000;
        } while ((index & (1ull<<31)) == 0);
        BDK_MT_COP0(count, COP0_INDEX);
        BDK_TLBWI;
    }

    /* Enable RI/XI and large physical addresses */
    BDK_MT_COP0(7<<29, COP0_PAGEGRAIN);
    /* Use 4MB pages */
    BDK_MT_COP0((4<<(20+1))-1, COP0_PAGEMASK);

    /* Create an EntryLo */
    uint64_t entrylo = 0 >> 6; /* Map PA of zero */
    entrylo |= 3; /* Set Valid and Global */

    /* Add TLB for Text */
    const uint64_t vma_text = ~mask_512MB & (long)&__bdk_init;
    BDK_MT_COP0(entrylo, COP0_ENTRYLO0);
    BDK_MT_COP0(1, COP0_ENTRYLO1); /* Global bit must be set in both */
    BDK_MT_COP0(vma_text, COP0_ENTRYHI);
    BDK_MT_COP0(0, COP0_INDEX);
    BDK_TLBWI;

    /* Add TLB for Data */
    const uint64_t vma_data = ~mask_512MB & (long)&_fdata;
    entrylo |= 4; /* Set dirty */
    BDK_MT_COP0(entrylo, COP0_ENTRYLO0);
    BDK_MT_COP0(1, COP0_ENTRYLO1); /* Global bit must be set in both */
    BDK_MT_COP0(vma_data, COP0_ENTRYHI);
    BDK_MT_COP0(1, COP0_INDEX);
    BDK_TLBWI;

    /* Set wired to be two entries */
    BDK_MT_COP0(2, COP0_WIRED);

    asm volatile ("j %0" :: "r" (&bdk_init_stage2) : "memory");
    /* We never get here, but the C complier doesn't know that */
    while (1) {}
}

int bdk_init_cores(uint64_t coremask)
{
    extern void __bdk_reset_vector(void);

    /* Install reset vector */
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_CFGX(0), 0x81fc0000ull);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_ADR, 0);
    const uint64_t *src = (const uint64_t *)__bdk_reset_vector;
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, 0xffffffff80000000 | bdk_ptr_to_phys((void*)0xffffffffe0000500));
    BDK_CSR_READ(BDK_MIO_BOOT_LOC_CFGX(0));

    /* Choose all cores by default */
    if (coremask == 0)
        coremask = -1;

    /* Don't touch this core */
    coremask &= ~(1ull<<bdk_get_core_num());

    /* Limit to the cores that already exist */
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

    return 0;
}
