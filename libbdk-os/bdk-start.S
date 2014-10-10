
    .global _start
    .global __bdk_start
    .global __bdk_remote_console
    .global __bdk_initial_stack_start
    .global __bdk_initial_stack_end

    .section .init
_start:
    b   __bdk_start
    .word   0
    # BDK image heade for Thunder is
    #   Offset  Size    Description
    #   0x00    4       Raw instruction for skipping header (above)
    #   0x04    4       Length of the image, includes header
    #   0x08    8       Magic string "THUNDERX"
    #   0x10    4       CRC32 of image + header. These bytes are zero when calculating the CRC
    #   0x14    4       Zero, reserved for future use
    #   0x18    64      ASCII Image name. Must always end in zero
    #   0x58    32      ASCII Version. Must always end in zero
    #   0x78    136     Zero, reserved for future use
    #   0x100   -       Beginning of image. Header is always 256 bytes.

    #
    # This is our entry point. The processor starts fetching instructions here,
    # 256 bytes into the image. Everything before this is header data
    #
.org 0x100
__bdk_start:
    ic      ialluis
    # Setup L2 to allow secure access to all of the address space
    #define L2C_ASC_REGIONX 0x87E080800000
    #define REGIONX_START   0x1000
    #define REGIONX_END     0x1008
    #define REGIONX_ATTR    0x1010
    mov     x0, L2C_ASC_REGIONX >> 32
    lsl     x0, x0, 32
    mov     x1, (L2C_ASC_REGIONX & 0xffffffff)
    orr     x0, x0, x1
    str     xzr, [x0, REGIONX_START]    /* Start of zero */
    mov     x1, 0xfffff00000            /* End of max address */
    str     x1, [x0, REGIONX_END]
    mov     x1, 2                       /* Secure only access */
    str     x1, [x0, REGIONX_ATTR]
    /* Update way partition to allow core 0 to write to L2 */
    #define L2C_WPAR_PP0_OFFSET 0x40000
    mov     x1, L2C_WPAR_PP0_OFFSET
    str     xzr, [x0, x1]
    ldr     xzr, [x0, x1]       /* Read back to make sure done */

    /* Relocate ourself if we aren't running at our link address */
    mov     x0, _start          /* x0 = _start location based on PC */
    adr     x1, _start          /* x1 = _start location as an absolute */
    cmp     x0, x1              /* See if we're running at the right location */
    b.eq    after_relocate      /* Skip relocate if we're already there */
    ldr     w2, [x1, 4]         /* w2 = Image length we need to copy */
    b       copy_code
    /* Align on a cache line so the entire code copy is in one cache line.
        No Icache misses */
.align 7
copy_code:
    ldp     q0, q1, [x1], 32    /* Load 32 bytes */
    subs    w2, w2, 32          /* Subtract 32 from length, setting flags */
    stp     q0, q1, [x0], 32    /* Store 32 bytes */
    b.gt    copy_code           /* Repeat if length is still positive */
    dmb     sy                  /* Force writes to L2 */
    mov     x0, after_relocate  /* Load the actual location we're suppose to be at */
    br      x0                  /* Branch to relocated code */

after_relocate:
    ic      ialluis             /* Clear the icache now that all code is correct */

    /* Calculate a CRC32 over the image before C corrupts global variables */
    adr     x10, _start         /* x10 = Address we're CRCing */
    ldr     w1, [x10, 4]        /* w1 = CRC left to do (Image length) */
    mov     w0, -1              /* w0 is the CRC, init with -1 */
    ldp     x3, x4, [x10]       /* Load first 16 bytes, CRC them */
    crc32x  w0, w0, x3
    crc32x  w0, w0, x4
    crc32w  w0, w0, wzr         /* Skip the CRC in the image */
    ldr     w3, [x10, 0x14]     /* Reserved 4 bytes */
    crc32w  w0, w0, w3
    ldr     x3, [x10, 0x18]     /* Next 8 bytes to get us aligned again */
    crc32x  w0, w0, x3
    add     x10, x10, 32        /* We've processed 32 bytes */
    sub     w1, w1, 32
crc_loop:
    ldp     x3, x4, [x10], 16   /* Load and CRC next 16 bytes */
    sub     w1, w1, 16          /* Update amount left */
    crc32x  w0, w0, x3
    cmp     w1, 16
    crc32x  w0, w0, x4
    bge     crc_loop
    cmp     w1, 8
    b.lt    crc_skip8
    ldr     x3, [x10], 8
    sub     w1, w1, 8
    crc32x  w0, w0, x3
crc_skip8:
    cmp     w1, 4
    b.lt    crc_skip4
    ldr     w3, [x10], 4
    sub     w1, w1, 4
    crc32w  w0, w0, w3
crc_skip4:
    cmp     w1, 2
    b.lt    crc_skip2
    ldrh    w3, [x10], 2
    sub     w1, w1, 2
    crc32h  w0, w0, w3
crc_skip2:
    cbz     w1, crc_done
    ldrb    w3, [x10]
    crc32b  w0, w0, w3
crc_done:
    mvn     w0, w0              /* Result must be inverted */

    /* w0 contains the image CRC */

    /* Initialise the stack */
    adr     x10, __bdk_initial_stack_end
    msr     SPSel, 1            /* We can't change SP_EL0 if we're using it */
    msr     SP_EL0, x10         /* Update the stack */
    msr     SPSel, 0            /* Use the new stack */
    /* Lock the stack in case other cores boot */
    adr     x10, __bdk_initial_stack_start
    mov     x12, 1
    sevl
1:  ldxr    x11, [x10]
    wfe
    cbnz    x11, 1b
    stxr    w11, x12, [x10]
    cbnz    w11, 1b
    /* Jump to C code */
    bl      __bdk_init
1:  b       1b              /* Infinite loop we should never reach */

    .macro exception_stub label
    .global __bdk_exception_\label
    .align 7
__bdk_exception_\label:
    b       __bdk_exception2
    .endm

.align 11   /* Must be 2KB aligned */
    exception_stub current_el_sync_sp0
    exception_stub current_el_irq_sp0
    exception_stub current_el_fiq_sp0
    exception_stub current_el_serror_sp0
    exception_stub current_el_sync_spx
    exception_stub current_el_irq_spx
    exception_stub current_el_fiq_spx
    exception_stub current_el_serror_spx
    exception_stub lower_el_sync_sp0
    exception_stub lower_el_irq_sp0
    exception_stub lower_el_fiq_sp0
    exception_stub lower_el_serror_sp0
    exception_stub lower_el_sync_spx
    exception_stub lower_el_irq_spx
    exception_stub lower_el_fiq_spx
    exception_stub lower_el_serror_spx

.align 12
__bdk_initial_stack_start:
    .dword   0
.align 12
__bdk_initial_stack_end:

