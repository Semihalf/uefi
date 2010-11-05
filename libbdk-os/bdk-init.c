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
    bdk_wait(1000);
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
    BDK_MT_COP0(status, COP0_STATUS);

    uint64_t memctl;
    BDK_MF_COP0(memctl, COP0_CVMMEMCTL);
    memctl |= 7ull<<37; // Max pause time
    BDK_MT_COP0(memctl, COP0_CVMMEMCTL);
}

static void __bdk_init_relocate_data(void)
{
    extern void _fdata; /* Beginning of .data section */
    extern void _edata; /* End of .data section, beginning of .bss */
    uint64_t data_physical = bdk_ptr_to_phys(&_fdata);

    /* We must rlocate our data section if it is on the bootbus */
    if ((data_physical >= 0x10000000) && (data_physical < 0x20000000))
    {
        void *new_loc = bdk_phys_to_ptr(bdk_build_mask(29) & (long)&_fdata);
        if (bdk_get_core_num() == 0)
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

static void bdk_init_stage2(void) __attribute((noreturn, noinline));
static void bdk_init_stage2(void)
{
    extern int main(int argc, const char *argv);
    extern void _fbss;  /* Beginning of .bss */
    extern void _ebss;  /* End of .bss */
    const char BANNER_1[] = "Bring and Diagnostic Kit (BDK)\n";
    const char BANNER_2[] = "Setting up global data\n";
    const char BANNER_3[] = "Clearing BSS\n";
    const char BANNER_4[] = "Creating main thread\n";
    const char BANNER_5[] = "Transfering to thread scheduler\n";

    BDK_MT_COP0(0, COP0_USERLOCAL);

    if (bdk_get_core_num() == 0)
    {
        __bdk_init_uart(0);

        write(1, BANNER_1, sizeof(BANNER_1)-1);
        __bdk_init_exception();

        write(1, BANNER_2, sizeof(BANNER_2)-1);
        __bdk_init_relocate_data();

        /* Zero BSS */
        write(1, BANNER_3, sizeof(BANNER_3)-1);
        memset(&_fbss, 0, &_ebss - &_fbss);

        write(1, BANNER_4, sizeof(BANNER_4)-1);
        bdk_thread_initialize();
        if (bdk_thread_create(-1, (bdk_thread_func_t)main, 0, NULL))
            bdk_fatal("Create of main thread failed\n");

        write(1, BANNER_5, sizeof(BANNER_5)-1);
    }
    else
        __bdk_init_relocate_data();

    __bdk_init_cop0();
    bdk_thread_destroy();
}

void bdk_init(long base_address) __attribute((noreturn));
void bdk_init(long base_address)
{
    /* Although we are running C code, we have not setup the TLB yet. This
        means that all data accessed will fault and we can't make subroutine
        calls. Once the basic TLB stuff is setup, we will jump to
        bdk_init_stage2(), which is a normal C environment */
    extern void _fdata; /* Beginning of .data section */
    extern void bdk_init_trampoline(uint64_t cfg, void *new_pc);
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

    /* The passed base_address is the location of bdk_init in our current
        virtual address space. We should be using KSEG0, so strip off the
        upper bits to get the physical address. Subtract off bdk_init will
        give the location of __start */
    uint64_t paddr = base_address & mask_512MB;
    paddr -= mask_512MB & (long)&bdk_init;
    int flash_shift = paddr - 0x1fc00000;
    if (flash_shift < 0)
        flash_shift = 0;
    paddr -= flash_shift;

    /* Convert the PA to an EntryLo */
    uint64_t entrylo = paddr >> 6;
    entrylo |= 3; /* Set Valid and Global */

    /* Add TLB for Text */
    const uint64_t vma_text = ~mask_512MB & (long)&bdk_init;
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

    BDK_SYNC;
    BDK_ICACHE_INVALIDATE;

    /* We're ready to go if we don't need to align flash */
    if (!flash_shift || bdk_get_core_num())
    {
        asm volatile ("j %0" :: "r" (&bdk_init_stage2) : "memory");
        /* We never get here, but the C complier doesn't know that */
        while (1) {}
    }

    const int FLASH_MAX_SIZE = 64;
    volatile uint64_t *MIO_BOOT_REG_CFGX = (uint64_t *)0x8001180000000000ull;
    volatile uint64_t *MIO_BOOT_LOC_CFGX = (uint64_t *)0x8001180000000080ull;
    volatile uint64_t *MIO_BOOT_LOC_ADR = (uint64_t *)0x8001180000000090ull;
    volatile uint64_t *MIO_BOOT_LOC_DAT = (uint64_t *)0x8001180000000098ull;

    /* Setup a trampoline to setup MIO_BOOT_REG_CFG0 and jump to C code */
    uint64_t *src = (uint64_t*)(long)(paddr + flash_shift + ((long)&bdk_init_trampoline & mask_512MB) + 0xffffffff80000000ull);
    *MIO_BOOT_LOC_CFGX = 0x81fc0000ull;
    *MIO_BOOT_LOC_ADR = 0;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;
    *MIO_BOOT_LOC_DAT = *src++;

    uint64_t mio_boot_reg_cfg0 = *MIO_BOOT_REG_CFGX;
    /* We are running from the bootbus, so remap region 0 so that
        we get more space and we are aligned on a 4MB boundary. We can't
        use the normal CSR stuff as we can't call functions yet */
    /* Clear size and address */
    mio_boot_reg_cfg0 &= ~0x0fffffff;
    /* Set size to FLASH_MAX_SIZE + 4MB in 64KB chunks. This allows the
        beginning 4MB to alias to the MIPS exception vectors */
    mio_boot_reg_cfg0 |= (((FLASH_MAX_SIZE+4) << (20 - 16)) - 1) << 16;
    /* Set the address to 0x1fc0000 minus FLASH_MAX_SIZE */
    mio_boot_reg_cfg0 |= (0x1fc00000 - (FLASH_MAX_SIZE<<20) - flash_shift) >> 16;

    /* FIXME: Simulator doesn't relocate bootbus right */
    base_address = 0x1fc00000;// - (FLASH_MAX_SIZE<<20);

    /* It is finally safe to start running normal C code */
    /* Use a trampoline to setup MIO_BOOT_REG_CFG0 and jump to C code */
    void (*trampoline)(uint64_t cfg, void * new_pc);
    trampoline = (void*)(long)0xffffffffbfc00000ull;
    trampoline(mio_boot_reg_cfg0, &bdk_init_stage2);

    /* We never get here, but the C complier doesn't know that */
    while (1) {}
}

int bdk_init_cores(uint64_t coremask)
{
    extern void bdk_reset_vector(void);

    /* Install reset vector */
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_CFGX(0), 0x81fc0000ull);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_ADR, 0);
    const uint64_t *src = (const uint64_t *)bdk_reset_vector;
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, *src++);
    BDK_CSR_WRITE(BDK_MIO_BOOT_LOC_DAT, 0xffffffff80000000 | bdk_ptr_to_phys((void*)0xffffffffe0000500));
    BDK_CSR_READ(BDK_MIO_BOOT_LOC_CFGX(0));

    /* Choose all cores by default */
    if (coremask == 0)
        coremask = -1;

    /* Don't touch this core */
    coremask &= ~(1<<bdk_get_core_num());

    /* Limit to the cores that already exist */
    coremask &= (1<<bdk_octeon_num_cores()) - 1;

    /* First send a NMI */
    BDK_CSR_WRITE(BDK_CIU_NMI, coremask);

    /* Then take cores out of reset */
    uint64_t reset = BDK_CSR_READ(BDK_CIU_PP_RST);
    reset &= ~coremask;
    BDK_CSR_WRITE(BDK_CIU_PP_RST, reset);

    return 0;
}
