#define RST_PP_RESET 0x87E006001740

    .section .text
    .global __bdk_reset_thread
__bdk_reset_thread:
    /* Switch to the exception stack so we can free our thread context */
    adr     x10, __bdk_initial_stack_end
    msr     SPSel, 1            /* We can't change SP_EL0 if we're using it */
    msr     SP_EL0, x10         /* Update the stack */
    msr     SPSel, 0            /* Use the new stack */
    /* Lock the stack in case other cores try using it */
    adr     x10, __bdk_initial_stack_start
    mov     x12, 1
1:  ldxr    x11, [x10]
    cbnz    x11, 1b
    stxr    w11, x12, [x10]
    cbnz    w11, 1b

    /* Free the thread context */
    mrs     x0, TPIDR_EL3
    bl      free

    /* Unlock the exception stack */
    adr     x0, __bdk_initial_stack_start
    dmb     sy
    str     xzr, [x0]
    sev

    /* Make sure the write buffer is idle and the dcache is empty */
    dsb     sy
    sys     #0,c11,c0,#2, xzr

    /* Load the address of RST_PP_RESET */
    mov     x0, RST_PP_RESET >> 32
    lsl     x0, x0, 32
    mov     x1, (RST_PP_RESET & 0xffff0000)
    orr     x0, x0, x1
    mov     x1, (RST_PP_RESET & 0xffff)
    orr     x0, x0, x1

    /* Create a bitmask representing this core */
    mrs     x2, MPIDR_EL1   /* Core ID is split into bits [15:8] and [3:0] */
    ubfx    x3, x2, 0, 4    /* low = bits [3:0] */
    ubfx    x4, x2, 8, 8    /* high = bits [15:8] */
    lsl     x4, x4, 4       /* high = high << 4 */
    orr     x3, x3, x4      /* core = high | low */
    mov     x2, 1           /* mask = 1 */
    lsl     x2, x2, x3      /* mask <<= core */

    /* Put the core in reset */
    ldr     x1, [x0]        /* Read current reset */
    orr     x1, x1, x2      /* add my core mask */
    str     x1, [x0]        /* Write new reset */

    /* Spin until we die */
1:  b       1b

