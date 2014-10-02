#include <bdk.h>
#include <stdio.h>

typedef struct
{
    uint64_t gpr[32]; /* SP is x31 */
    __uint128_t fpr[32];
} except_regs_t;

void __bdk_exception_handler(except_regs_t *exc)
{
    const char *BANNER = "**********************************************************************************\n";
    uint64_t pc;
    BDK_MRS(ELR_EL3, pc);
    bdk_sys_esr_elx_t esr;
    BDK_MRS(ESR_EL3, esr.u);
    printf(BANNER);
    printf("Node %d, Core %d: Unhandled Exception\n", bdk_numa_local(), bdk_get_core_num());
    printf("ESR EC=0x%02x ISS=0x%x\n", esr.s.ec, esr.s.iss);
    printf(BANNER);
    printf("pc : 0x%016lx    esr: 0x%08x\n", pc, esr.u);
    for (int reg=0; reg<16; reg++)
    {
        printf("x%02d: 0x%016lx    x%02d: 0x%016lx\n",
            reg, exc->gpr[reg], reg+16, exc->gpr[reg+16]);
    }
    printf("\n");
    for (int reg=0; reg<16; reg++)
    {
        printf("q%02d: 0x%016lx_%016lx  q%02d: 0x%016lx_%016lx\n",
            reg,    (uint64_t)(exc->fpr[reg] >> 64),    (uint64_t)exc->fpr[reg],
            reg+16, (uint64_t)(exc->fpr[reg+16] >> 64), (uint64_t)exc->fpr[reg+16]);
    }
    printf("\n");
    uint64_t *stack = (uint64_t *)exc->gpr[31];
    for (int i = 0; i < 16; i++)
    {
        printf("stack[0x%016lx] = 0x%016lx\n", stack, *stack);
        stack++;
    }
    printf(BANNER);
    __bdk_die();
}
