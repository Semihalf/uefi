
    .global _start
    .global __bdk_start
    .global __bdk_remote_console
    .global __bdk_exception_base

    .section .init
_start:
    b   __bdk_start /* This is replaced with the header, so jump to __bdk_start */
    .word 0     /* Header Magic     (4 bytes) */
    .word 0     /* Header CRC       (4 bytes) */
#define OFFSET_HEADER_LENGTH 16
    .hword 0    /* Header length    (2 bytes) */
    .hword 0    /* Header major rev (2 bytes) */
    .hword 0    /* Header minor rev (2 bytes) */
    .hword 0    /* Board type       (2 bytes) */
#define OFFSET_DATA_LENGTH 24
    .word 0     /* Data length      (4 bytes) */
    .word 0     /* Data CRC         (4 bytes) */

    #
    # This is our entry point. The processor starts fetching instructions here,
    # 256 bytes into the image. Everything before this is header data
    #
.org 0x100
    b   __bdk_start
__bdk_remote_console:
    # 0x100 - 0x300 is used for the remote console, see bdk-fs-remote.c
.org 0x300
__bdk_initial_stack:
    # 0x280 - 0x1000 is initial stack
.org 0x1000
__bdk_start:
    # Setup L2 to allow secure access to all of the address space
    #define L2C_ASC_REGIONX 0x87E080800000
    #define REGIONX_START   0x1000
    #define REGIONX_END     0x1008
    #define REGIONX_ATTR    0x1010
    mov     x0, L2C_ASC_REGIONX >> 32
    lsl     x0, x0, 32
    mov     x1, (L2C_ASC_REGIONX & 0xffffffff)
    orr      x0, x0, x1
    str     xzr, [x0, REGIONX_START]    /* Start of zero */
    mov     x1, 0xfffff00000            /* End of max address */
    str     x1, [x0, REGIONX_END]
    mov     x1, 2                       /* Secure only access */
    str     x1, [x0, REGIONX_ATTR]
    /* Figure out the location of code as an offset from our link address */
1:
    adr     x0, 1b          /* Jump to label, saving our PC in RA */
    mov     x1, 1b          /* VA of label 1 */
    cmp     x0, x1
    b.eq    after_relocate /* Skip relocate if we're already there */

    mov     x0, _start
    adr     x1, _start
    adr     x2, _end
copy_code:
    ldp     q0, q1, [x1], 32
    stp     q0, q1, [x0], 32
    cmp     x1, x2
    b.lt    copy_code
    dmb     sy
    mov     x0, after_relocate
    ic      ialluis
    br      x0

after_relocate:
    /* Initialise the stack */
    adr     x0, __bdk_start
    msr     SP_EL0, x0
    msr     SPSel, 0
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

