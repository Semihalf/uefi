#define BDK_INITIAL_STACK_SIZE 256

    .global _start
    .global __bdk_remote_console

    .macro exception_stub label
exception_\label:
    stp     x0, x1, [sp], -16
    mov     x1, 0 /* FIXME __bdk_exception2 */
    adr     x0, exception_\label
    br      x1
    .endm

    #
    # This is our entry point. The processor starts fetching instructions here
    #
    .section .init
_start:
    b   __init  /* This is replaced with the header, so jump to __init */
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
    # Exception handlers
    #
.org 0x200
     exception_stub tlb
.org 0x280
     exception_stub xtlb
.org 0x300
     exception_stub cache
.org 0x380
     exception_stub general
.org 0x400
     exception_stub interrupt
.org 0x480
     exception_stub ejtag

.org 0x500
__bdk_remote_console:
    # 0x500 - 0x700 is used for the remote console, see bdk-fs-remote.c
    # 0x700 - 0x1000 is unused
__bdk_initial_stack:
    # 0x1000 - 0x2000 is initial stack

.org 0x2000
__init:
    /* Figure out the location of code as an offset from our link address */
1:
    adr     x0, 1b          /* Jump to label, saving our PC in RA */
    mov     x1, 1b          /* VA of label 1 */
    sub     x0, x0, x1      /* x0 = offset to add to VA to get current address */
    cbz     x0, after_relocate /* Skip relocate if we're already there */
#if 0
    /* Copy copy_code to L2 at address 0 */
    li      a0, 0x80000100  /* Where we are putting copy_code */
    dla     a1, copy_code   /* Load the address of the copy_code */
    pref    30, (a0)        /* Prepare to store to zero the entire cache line */
    daddu   a1, s0          /* Convert it into the current location */
    li      a2, 128         /* We're copying 128 bytes */
1:
    ld      t0, (a1)        /* Copy loop, load */
    daddu   a1, 8           /* Increment source */
    sd     t0, (a0)         /* Store */
    dsubu   a2, 8           /* Decriment remaining */
    bnez    a2, 1b          /* Branch if we're not done */
     daddu   a0, 8          /* Increment dest in delay slot */

    /* Flush pending writes and jump to the copy code in L2 */
    sync                    /* Force out all writes */
    cache   0, ($0)         /* Flush Icache */
    li      a0, 0x80000100  /* Load new location of copy_code */
    j       a0              /* Jump to it */
.align 3
copy_code:
    li      a0, 0x80002000  /* Where we're copying to (skip first 0x2000) */
    dla     a1, __init      /* VA of __init */
    daddu   a1, s0          /* Convert __start to the current location */
                            /* We're copy all data defined by the header */
    lhu     a2, OFFSET_HEADER_LENGTH-0x2000(a1)
    lw      t0, OFFSET_DATA_LENGTH-0x2000(a1)
    addu    a2, 7           /* Add 7 to _end so that it will be 8 byte aligned after mask */
    addu    a2, t0          /* Length = header + data */
    and     a2, -8          /* Strip off lower bits, rounding to 8 byte */
    subu    a2, 0x2000      /* Subtract out the 0x2000 we skipped from the length */
1:
    ld      t0, (a1)        /* Copy loop, load */
    daddu   a1, 8           /* Increment source */
    sd     t0, (a0)         /* Store */
    dsubu   a2, 8           /* Decriment remaining */
    bnez    a2, 1b          /* Branch if we're not done */
     daddu   a0, 8          /* Increment dest in delay slot */
    sync                    /* Force out all writes */
    dla     t0, after_relocate  /* Code we need to run next */
    dla     t1, __start     /* Get VA of __start */
    dsubu   t0, t1          /* Find offset of after_relocate from __start */
    addu    t0, 0x80000000  /* Add KSEG0 */
    j       t0              /* Jump to final location of after_relocate */
     cache  0, ($0)         /* Flush Icache in the delay slot */

    /* Note the above code is run at a gofoy address, so it is disconnected
        from the code below */
#endif
after_relocate:
    /* Enable FP */
    /* FIXME */
    /* Initialise gp */
    /* adr     x29, _gp */
    /* Initialise the stack */
    adr     x0, __bdk_initial_stack
    add     x0, x0, BDK_INITIAL_STACK_SIZE
    msr     SP_EL0, x0
    /* Setup so a eret will return with EL3 and using SP_EL0 */
    adr     x0, __bdk_init
    msr     ELR_EL3, x0
    mov     x0, 0x000003cc /* DAIF=0xf, EL=3, SP=0 */
    msr     SPSR_EL3, x0
    eret
1:  b       1b              /* Infinite loop we should never reach */

