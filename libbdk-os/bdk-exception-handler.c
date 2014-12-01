#include <bdk.h>
#include <stdio.h>

typedef struct
{
    uint64_t gpr[32]; /* SP is x31 */
    __uint128_t fpr[32];
} except_regs_t;

static const char *EC_STRING[64] = {
    [0x0] = "UNKNOWN",
    [0x1] = "WFE_WFI",
    [0x3] = "MCR_CP15",
    [0x4] = "MCRR_CP15",
    [0x5] = "MCR_CP14",
    [0x6] = "LDC_CP15",
    [0x7] = "ACCESS_SIMD_FP",
    [0x8] = "MRC_CP10",
    [0xc] = "MCRR_CP14",
    [0xe] = "ILLEGAL_INSTR_STATE",
    [0x11] = "SVC_AARCH32",
    [0x12] = "HVC_AARCH32",
    [0x13] = "SMC_AARCH32",
    [0x15] = "SVC_AARCH64",
    [0x16] = "HVC_AARCH64",
    [0x17] = "SMC_AARCH64",
    [0x18] = "MSR_AARCH64",
    [0x20] = "INSTR_ABORT_LOWER_EL",
    [0x21] = "INSTR_ABORT_CURRENT_EL",
    [0x22] = "PC_ALIGNMENT",
    [0x24] = "DATA_ABORT_LOWER_EL",
    [0x25] = "DATA_ABORT_CURRENT_EL",
    [0x26] = "STACK_ALIGNMENT",
    [0x28] = "FLOATING_POINT_AARCH32",
    [0x2c] = "FLOATING_POINT_AARCH64",
    [0x2f] = "SERROR",
    [0x30] = "DEBUG_BP_LOWER_EL",
    [0x31] = "DEBUG_BP_CURRENT_EL",
    [0x32] = "DEBUG_STEP_LOWER_EL",
    [0x33] = "DEBUG_STEP_CURRENT_EL",
    [0x34] = "DEBUG_WP_LOWER_EL",
    [0x35] = "DEBUG_WP_CURRENT_EL",
    [0x38] = "DEBUG_BKPT",
    [0x3a] = "DEBUG_A32_VECTOR",
    [0x3c] = "DEBUG_BRK",
};

static const char *FCS_STRING[64] = {
    [0x00] = "ADDRESS_SIZE_L0",
    [0x01] = "ADDRESS_SIZE_L1",
    [0x02] = "ADDRESS_SIZE_L2",
    [0x03] = "ADDRESS_SIZE_L3",
    [0x04] = "TRANSLATION_L0",
    [0x05] = "TRANSLATION_L1",
    [0x06] = "TRANSLATION_L2",
    [0x07] = "TRANSLATION_L3",
    [0x08] = "ACCESS_FLAG_L0",
    [0x09] = "ACCESS_FLAG_L1",
    [0x0a] = "ACCESS_FLAG_L2",
    [0x0b] = "ACCESS_FLAG_L3",
    [0x0c] = "PERMISSION_L0",
    [0x0d] = "PERMISSION_L1",
    [0x0e] = "PERMISSION_L2",
    [0x0f] = "PERMISSION_L3",
    [0x10] = "EXTERNAL_ABORT",
    [0x11] = "ASYNC_EXTERNAL_ABORT",
    [0x14] = "WALK_ABORT_L0",
    [0x15] = "WALK_ABORT_L1",
    [0x16] = "WALK_ABORT_L2",
    [0x17] = "WALK_ABORT_L3",
    [0x18] = "MEMORY_PARITY",
    [0x1c] = "WALK_PARITY_L0",
    [0x1d] = "WALK_PARITY_L1",
    [0x1e] = "WALK_PARITY_L2",
    [0x1f] = "WALK_PARITY_L3",
    [0x21] = "ALIGNMENT",
    [0x22] = "DEBUG_EVENT",
    [0x30] = "TLB_CONFLICT",
    [0x34] = "LOCKDOWN",
    [0x35] = "IMP_DEFIEND_1",
    [0x3a] = "IMP_DEFINED_2",
    [0x3d] = "SECTION_DOMAIN",
    [0x3e] = "PAGE_DOMAIN",
};

void __bdk_exception_handler(except_regs_t *exc)
{
    const char *BANNER = "**********************************************************************************\n";
    uint64_t pc;
    BDK_MRS(ELR_EL3, pc);
    bdk_sys_esr_elx_t esr;
    BDK_MRS(ESR_EL3, esr.u);
    bdk_sys_far_elx_t far;
    BDK_MRS(FAR_EL3, far.u);
    printf(BANNER);
    printf("Node %d, Core %d: Unhandled Exception\n", bdk_numa_local(), bdk_get_core_num());
    printf("ESR EC=0x%02x(%s) ISS=0x%x", esr.s.ec,
        EC_STRING[esr.s.ec] ? EC_STRING[esr.s.ec] : "Unknown",
        esr.s.iss);
    if ((esr.s.ec == 0x24) || (esr.s.ec == 0x25))
    {
        printf("(");
        if (esr.s.iss & (1<<24)) printf(" VALID");
        if (esr.s.iss & (1<<21)) printf(" SIGN_EXTEND");
        if (esr.s.iss & (1<<15)) printf(" 64BIT");
        if (esr.s.iss & (1<<14)) printf(" ACQUIRE");
        if (esr.s.iss & (1<<9)) printf(" EXTERNAL");
        if (esr.s.iss & (1<<8)) printf(" CACHE");
        if (esr.s.iss & (1<<7)) printf(" S1PTW");
        if (esr.s.iss & (1<<6)) printf(" WRITE");
        if (FCS_STRING[esr.s.iss & 0x3f])
        {
            printf(" ");
            printf(FCS_STRING[esr.s.iss & 0x3f]);
        }
        printf(")");
    }
    printf("\n");
    printf(BANNER);
    printf("pc : 0x%016lx    esr: 0x%08x\n", pc, esr.u);
    printf("far: 0x%016lx\n", far.u);
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
        printf("stack[0x%016lx] = 0x%016lx\n", (uint64_t)stack, *stack);
        stack++;
    }
    printf(BANNER);
    __bdk_die();
}
