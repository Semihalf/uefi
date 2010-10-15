#include <bdk.h>

void bdk_init(void)
{
    extern int main(int argc, const char *argv);
    extern void _gp;

    uint64_t data_physical = 0x1fc00000; // FIXME bdk_ptr_to_phys(&gp);

    /* We must rlocate our data section if it is on the bootbus */
    if ((data_physical >= 0x10000000) && (data_physical < 0x20000000))
    {
        extern void _fdata; /* Beginning of .data section */
        extern void _edata; /* End of .data section, beginning of .bss */
        extern void _end;   /* End of entire .data */
        void *new_loc = bdk_phys_to_ptr(0x500);
        memmove(new_loc, &_fdata, (&_edata - &_fdata));
        memset(new_loc + (&_edata - &_fdata), 0, &_end - &_edata);
        BDK_MT_COP0(7, COP0_ENTRYLO0);
        BDK_MT_COP0(1, COP0_ENTRYLO1);
        BDK_MT_COP0(0xc0000000, COP0_ENTRYHI);
        BDK_MT_COP0(1, COP0_INDEX);
        BDK_TLBWI;
    }

    bdk_thread_initialize();

    if (bdk_thread_create(-1, (bdk_thread_func_t)main, 0, NULL))
        bdk_fatal("Create of main thread failed\n");

    bdk_thread_yield();
    bdk_thread_destroy();
}
