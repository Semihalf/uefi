#include <bdk.h>
#include <stdio.h>

char bdk_exception_stack[1024];

static const char reg_names[][3] = {  "r0","at","v0","v1","a0","a1","a2","a3",
                                      "a4","a5","a6","a7","t0","t1","t2","t3",
                                      "s0","s1","s2","s3","s4","s5","s6","s7",
                                      "t8","t9","k0","k1","gp","sp","s8","ra" };
/* Textual descriptions of cause codes */
static const char *cause_names[] = {
        /*  0 */ "Interrupt",
        /*  1 */ "TLB modification",
        /*  2 */ "TLB load/fetch",
        /*  3 */ "TLB store",
        /*  4 */ "Address exc, load/fetch",
        /*  5 */ "Address exc, store",
        /*  6 */ "Bus error, instruction fetch",
        /*  7 */ "Bus error, load/store",
        /*  8 */ "Syscall",
        /*  9 */ "Breakpoint",
        /* 10 */ "Reserved instruction",
        /* 11 */ "Coprocessor unusable",
        /* 12 */ "Arithmetic overflow",
        /* 13 */ "Trap",
        /* 14 */ "Reserved",
        /* 15 */ "Floating point",
        /* 16 */ "Implementation dependent",
        /* 17 */ "Implementation dependent",
        /* 18 */ "COP2 exception",
        /* 19 */ "TLB read inhibit",
        /* 20 */ "TLB execution inhibit",
        /* 21 */ "Reserved",
        /* 22 */ "MDMX unusable",
        /* 23 */ "Watch",
        /* 24 */ "Machine check",
        /* 25 */ "Reserved",
        /* 26 */ "Reserved",
        /* 27 */ "Reserved",
        /* 28 */ "Reserved",
        /* 29 */ "Reserved",
        /* 30 */ "Cache error",
        /* 31 */ "Reserved"
};

void __bdk_exception_handler(uint64_t saved_regs[34])
{
    uint64_t r;
    int reg;

    printf("******************************************************************\n");
    BDK_MF_COP0(r, COP0_CAUSE);
    const char *str = cause_names[(r >> 2) & 0x1f];
    printf("Core %d: Unhandled Exception. Cause register decodes to:\n%s\n", bdk_get_core_num(), str);
    printf("******************************************************************\n");
    for (reg=0; reg<16; reg++)
    {
        printf("%3s (r%02d): 0x%016lx \t %3s (r%02d): 0x%016lx\n",
            reg_names[reg], reg, saved_regs[reg],
            reg_names[reg+16], reg+16, saved_regs[reg+16]);
    }
    printf("%3s      : 0x%016lx \t %3s      : 0x%016lx\n",
        "lo", saved_regs[32], "hi", saved_regs[33]);

    BDK_MF_COP0(r, COP0_CAUSE);
    printf("COP0_CAUSE:     0x%016lx\n", r);
    BDK_MF_COP0(r, COP0_STATUS);
    printf("COP0_STATUS:    0x%016lx\n", r);
    BDK_MF_COP0(r, COP0_BADVADDR);
    printf("COP0_BADVADDR:  0x%016lx\n", r);
    BDK_MF_COP0(r, COP0_EPC);
    printf("COP0_EPC:       0x%016lx\n", r);
    printf("******************************************************************\n");
    for (int i=0; i<128; i+=8)
        printf("stack[0x%02x] = 0x%016lx\n", i, *(uint64_t*)(saved_regs[29] + i));
    printf("******************************************************************\n");
    while (1) {}
}
