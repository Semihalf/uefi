#define GPR_OFFSET(reg) 16 + reg * 8
#define FPR_OFFSET(reg) GPR_OFFSET(32) + reg * 16

    /* X0 is the new context, TPIDR_EL3 is the old one. TPIDR_EL3
        can be zero. If X1 is non zero the old context is freed */
    .section .text
    .global __bdk_thread_switch
__bdk_thread_switch:
    mrs     x10, TPIDR_EL3          /* Get the current context */
    cbz     x10, skip_save          /* Skip save if current context is zero */

    stp     x0, x1,[x10, GPR_OFFSET(0)]
    stp     x2, x3,[x10, GPR_OFFSET(2)]
    stp     x4, x5,[x10, GPR_OFFSET(4)]
    stp     x6, x7,[x10, GPR_OFFSET(6)]
    stp     x8, x9,[x10, GPR_OFFSET(8)]
    stp     x10, x11,[x10, GPR_OFFSET(10)]  /* Note that x10 was corrupted */
    mov     x11, sp
    stp     x12, x13,[x10, GPR_OFFSET(12)]
    stp     x14, x15,[x10, GPR_OFFSET(14)]
    stp     x16, x17,[x10, GPR_OFFSET(16)]
    stp     x18, x19,[x10, GPR_OFFSET(18)]
    stp     x20, x21,[x10, GPR_OFFSET(20)]
    stp     x22, x23,[x10, GPR_OFFSET(22)]
    stp     x24, x25,[x10, GPR_OFFSET(24)]
    stp     x26, x27,[x10, GPR_OFFSET(26)]
    stp     x28, x29,[x10, GPR_OFFSET(28)]
    stp     x30, x11,[x10, GPR_OFFSET(30)]  /* SP is last */
    stp     q0, q1,[x10, FPR_OFFSET(0)]
    stp     q2, q3,[x10, FPR_OFFSET(2)]
    stp     q4, q5,[x10, FPR_OFFSET(4)]
    stp     q6, q7,[x10, FPR_OFFSET(6)]
    stp     q8, q9,[x10, FPR_OFFSET(8)]
    stp     q10, q11,[x10, FPR_OFFSET(10)]
    stp     q12, q13,[x10, FPR_OFFSET(12)]
    stp     q14, q15,[x10, FPR_OFFSET(14)]
    stp     q16, q17,[x10, FPR_OFFSET(16)]
    stp     q18, q19,[x10, FPR_OFFSET(18)]
    stp     q20, q21,[x10, FPR_OFFSET(20)]
    stp     q22, q23,[x10, FPR_OFFSET(22)]
    stp     q24, q25,[x10, FPR_OFFSET(24)]
    stp     q26, q27,[x10, FPR_OFFSET(26)]
    stp     q28, q29,[x10, FPR_OFFSET(28)]
    stp     q30, q31,[x10, FPR_OFFSET(30)]
    dmb     st /* We're done with the old context, push writes out */

skip_save:
    /* Switch to the new thread stack so we can call C functions */
    ldr     x11, [x0, GPR_OFFSET(31)]   /* SP is last of GPR */
    mov     sp, x11
    msr     TPIDR_EL3, x0               /* Store new context */

    /* Store the old context and the don't free to the stack so we can
        restore regsiters */
    stp     x10, x1, [sp, -16]!

    /* Restore our thread context */
    mrs     x11, TPIDR_EL3              /* Put the new context in x11 */
    ldp     x0, x1,[x11, GPR_OFFSET(0)]
    ldp     x2, x3,[x11, GPR_OFFSET(2)]
    ldp     x4, x5,[x11, GPR_OFFSET(4)]
    ldp     x6, x7,[x11, GPR_OFFSET(6)]
    ldp     x8, x9,[x11, GPR_OFFSET(8)]
    /* x10 and x11 are not restored. Temps containing old and new context */
    ldp     x12, x13,[x11, GPR_OFFSET(12)]
    ldp     x14, x15,[x11, GPR_OFFSET(14)]
    ldp     x16, x17,[x11, GPR_OFFSET(16)]
    ldp     x18, x19,[x11, GPR_OFFSET(18)]
    ldp     x20, x21,[x11, GPR_OFFSET(20)]
    ldp     x22, x23,[x11, GPR_OFFSET(22)]
    ldp     x24, x25,[x11, GPR_OFFSET(24)]
    ldp     x26, x27,[x11, GPR_OFFSET(26)]
    ldp     x28, x29,[x11, GPR_OFFSET(28)]
    ldr     x30,[x11, GPR_OFFSET(30)]   /* SP was restored above */
    ldp     q0, q1,[x11, FPR_OFFSET(0)]
    ldp     q2, q3,[x11, FPR_OFFSET(2)]
    ldp     q4, q5,[x11, FPR_OFFSET(4)]
    ldp     q6, q7,[x11, FPR_OFFSET(6)]
    ldp     q8, q9,[x11, FPR_OFFSET(8)]
    ldp     q10, q11,[x11, FPR_OFFSET(10)]
    ldp     q12, q13,[x11, FPR_OFFSET(12)]
    ldp     q14, q15,[x11, FPR_OFFSET(14)]
    ldp     q16, q17,[x11, FPR_OFFSET(16)]
    ldp     q18, q19,[x11, FPR_OFFSET(18)]
    ldp     q20, q21,[x11, FPR_OFFSET(20)]
    ldp     q22, q23,[x11, FPR_OFFSET(22)]
    ldp     q24, q25,[x11, FPR_OFFSET(24)]
    ldp     q26, q27,[x11, FPR_OFFSET(26)]
    ldp     q28, q29,[x11, FPR_OFFSET(28)]
    ldp     q30, q31,[x11, FPR_OFFSET(30)]

    /* Call switch complete */
    stp     x0, x1, [sp, -16]!
    stp     x30, xzr, [sp, -16]!
    ldp     x0, x1, [sp, 32]
    bl      __bdk_thread_switch_complete
    ldp     x30, xzr, [sp], 16
    ldp     x0, x1, [sp], 16
    add     sp, sp, 16
    ret

