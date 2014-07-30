    .section .text
    .global __bdk_exception
__bdk_exception:
    stp     x0, x1, [sp], -16
    mov     x1, __bdk_exception2
    adr     x0, .-8
    br      x1

    .global __bdk_exception2
__bdk_exception2:
    /* x0,x1 were already saved in __bdk_exception */
    sub     sp, sp, 16 * 45
    stp     x2, x3, [sp, 16 * 1]
    stp     x4, x5, [sp, 16 * 2]
    stp     x6, x7, [sp, 16 * 3]
    stp     x8, x9, [sp, 16 * 4]
    stp     x10, x11, [sp, 16 * 5]
    stp     x12, x13, [sp, 16 * 6]
    stp     x14, x15, [sp, 16 * 7]
    stp     x16, x17, [sp, 16 * 8]
    stp     x18, x19, [sp, 16 * 9]
    stp     x20, x21, [sp, 16 * 10]
    stp     x22, x23, [sp, 16 * 11]
    stp     x24, x25, [sp, 16 * 12]
    stp     x26, x27, [sp, 16 * 13]
    stp     x28, x29, [sp, 16 * 14]
    mrs     x10, SP_EL0
    stp     x30, x10, [sp, 16 * 15]
    stp     q0, q1, [sp, 16 * 16]
    stp     q2, q3, [sp, 16 * 18]
    stp     q4, q5, [sp, 16 * 20]
    stp     q6, q7, [sp, 16 * 22]
    stp     q8, q9, [sp, 16 * 24]
    stp     q10, q11, [sp, 16 * 26]
    stp     q12, q13, [sp, 16 * 28]
    stp     q14, q15, [sp, 16 * 30]
    stp     q16, q17, [sp, 16 * 32]
    stp     q18, q19, [sp, 16 * 34]
    stp     q20, q21, [sp, 16 * 36]
    stp     q22, q23, [sp, 16 * 38]
    stp     q24, q25, [sp, 16 * 40]
    stp     q26, q27, [sp, 16 * 42]
    stp     q28, q29, [sp, 16 * 44]
    stp     q30, q31, [sp, 16 * 46]

    bl      __bdk_exception_handler
    /* Should never get here */
    eret


