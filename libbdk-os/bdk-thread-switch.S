
    /* X0 is the new context, TPIDR_EL3 is the old one. TPIDR_EL3
        can be zero. If X1 is non zero the old context is freed */
    .section .text
    .global __bdk_thread_switch
__bdk_thread_switch:
    mrs     x10, TPIDR_EL3          /* Get the current context */
    cbz     x10, skip_save          /* Skip save if current context is zero */

    msr     TPIDR_EL3, x0           /* Store new context */
    stp     x0, x1,[x10, 16 * 1]    /* GPR Registers start 16 bytes in, after next and pc */
    stp     x2, x3,[x10, 16 * 2]
    stp     x4, x5,[x10, 16 * 3]
    stp     x6, x7,[x10, 16 * 4]
    stp     x8, x9,[x10, 16 * 5]
    stp     x10, x11,[x10, 16 * 6]  /* Note that x10 was corrupted */
    stp     x12, x13,[x10, 16 * 7]
    stp     x14, x15,[x10, 16 * 8]
    stp     x16, x17,[x10, 16 * 9]
    stp     x18, x19,[x10, 16 * 10]
    stp     x20, x21,[x10, 16 * 11]
    stp     x22, x23,[x10, 16 * 12]
    stp     x24, x25,[x10, 16 * 13]
    stp     x26, x27,[x10, 16 * 14]
    stp     x28, x29,[x10, 16 * 15]
    mrs     x11, SP_EL0             /* Assume we're using SP_EL0 for the stack pointer */
    stp     x30, x11,[x10, 16 * 16] /* SP is last */
    stp     q0, q1,[x10, 16 * 17]   /* FPR */
    stp     q2, q3,[x10, 16 * 19]
    stp     q4, q5,[x10, 16 * 21]
    stp     q6, q7,[x10, 16 * 23]
    stp     q8, q9,[x10, 16 * 25]
    stp     q10, q11,[x10, 16 * 27]
    stp     q12, q13,[x10, 16 * 29]
    stp     q14, q15,[x10, 16 * 31]
    stp     q16, q17,[x10, 16 * 33]
    stp     q18, q19,[x10, 16 * 35]
    stp     q20, q21,[x10, 16 * 37]
    stp     q22, q23,[x10, 16 * 39]
    stp     q24, q25,[x10, 16 * 41]
    stp     q26, q27,[x10, 16 * 43]
    stp     q28, q29,[x10, 16 * 45]
    stp     q30, q31,[x10, 16 * 47]
    adr     x10, .                  /* Store the PC */
    str     x10,[x10, 8]
    dsb     st                      /* We're done with the old context, push writes out */

skip_save:
    mrs     x11, TPIDR_EL3          /* Put the new context in x11 */
    ldr     x12, [x11, 16 * 16]     /* SP is last of GPR */
    msr     SP_EL0, x12             /* Assume we're using SP_EL0 for the stack pointer */
    ldp     x0, x1,[x10, 16 * 1]    /* GPR Registers start 16 bytes in, after next and pc */
    ldp     x2, x3,[x10, 16 * 2]
    ldp     x4, x5,[x10, 16 * 3]
    ldp     x6, x7,[x10, 16 * 4]
    ldp     x8, x9,[x10, 16 * 5]
    /* x10 and x11 are not restored. Temps containing old and new context */
    ldp     x12, x13,[x10, 16 * 7]
    ldp     x14, x15,[x10, 16 * 8]
    ldp     x16, x17,[x10, 16 * 9]
    ldp     x18, x19,[x10, 16 * 10]
    ldp     x20, x21,[x10, 16 * 11]
    ldp     x22, x23,[x10, 16 * 12]
    ldp     x24, x25,[x10, 16 * 13]
    ldp     x26, x27,[x10, 16 * 14]
    ldp     x28, x29,[x10, 16 * 15]
    ldr     x30,[x10, 16 * 16]       /* SP was restored above */
    ldp     q0, q1,[x10, 16 * 17]    /* FPR */
    ldp     q2, q3,[x10, 16 * 19]
    ldp     q4, q5,[x10, 16 * 21]
    ldp     q6, q7,[x10, 16 * 23]
    ldp     q8, q9,[x10, 16 * 25]
    ldp     q10, q11,[x10, 16 * 27]
    ldp     q12, q13,[x10, 16 * 29]
    ldp     q14, q15,[x10, 16 * 31]
    ldp     q16, q17,[x10, 16 * 33]
    ldp     q18, q19,[x10, 16 * 35]
    ldp     q20, q21,[x10, 16 * 37]
    ldp     q22, q23,[x10, 16 * 39]
    ldp     q24, q25,[x10, 16 * 41]
    ldp     q26, q27,[x10, 16 * 43]
    ldp     q28, q29,[x10, 16 * 45]
    ldp     q30, q31,[x10, 16 * 47]

    stp     x0,x1,[sp],-16   /* Save x0-x1,x30 before making a call */
    str     x30,[sp],-8
    mov     x0, x10             /* Old context */
    ldr     x1, [x10, 16+8]     /* Free flag from call */

    /* At this point the values in new context is all restored such that
        a yield in this call will not cause problems. A0 is the old context,
        A1 is the delete flag originally passed in */
    bl      __bdk_thread_switch_complete

    ldp     x0,x1,[sp], 16      /* Restore x0-x1,x30 after call */
    ldr     x30, [sp], 8
    ret

