#include <bdk.h>
#include <stdio.h>

char bdk_exception_stack[1024];

static const char reg_names[][3] = {  "r0","at","v0","v1","a0","a1","a2","a3",
                                      "t0","t1","t2","t3","t4","t5","t6","t7",
                                      "s0","s1","s2","s3","s4","s5","s6","s7",
                                      "t8","t9","k0","k1","gp","sp","s8","ra" };
/* Textual descriptions of cause codes */
static const char cause_names[][32] = {
        /*  0 */ "Interrupt",
        /*  1 */ "TLB modification",
        /*  2 */ "tlb load/fetch",
        /*  3 */ "tlb store",
        /*  4 */ "address exc, load/fetch",
        /*  5 */ "address exc, store",
        /*  6 */ "bus error, instruction fetch",
        /*  7 */ "bus error, load/store",
        /*  8 */ "syscall",
        /*  9 */ "breakpoint",
        /* 10 */ "reserved instruction",
        /* 11 */ "cop unusable",
        /* 12 */ "arithmetic overflow",
        /* 13 */ "trap",
        /* 14 */ "",
        /* 15 */ "floating point exc",
        /* 16 */ "",
        /* 17 */ "",
        /* 18 */ "cop2 exception",
        /* 19 */ "",
        /* 20 */ "",
        /* 21 */ "",
        /* 22 */ "mdmx unusable",
        /* 23 */ "watch",
        /* 24 */ "machine check",
        /* 25 */ "",
        /* 26 */ "",
        /* 27 */ "",
        /* 28 */ "",
        /* 29 */ "",
        /* 30 */ "cache error",
        /* 31 */ ""
};

void __bdk_exception_handler(uint64_t saved_regs[34])
{
    uint64_t r;
    int reg;

    printf("******************************************************************\n");
    BDK_MF_COP0(r, COP0_CAUSE);
    const char *str = cause_names[(r >> 2) & 0x1f];
    printf("Core %d: Unhandled Exception. Cause register decodes to:\n%s\n", bdk_get_core_num(), str && *str ? str : "Reserved exception cause");
    printf("******************************************************************\n");
    for (reg=0; reg<16; reg++)
    {
        printf("%3s ($%02d): 0x%016lx \t %3s ($%02d): 0x%016lx\n",
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
    while (1) {}
}
