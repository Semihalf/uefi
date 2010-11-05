#include "machine/asm.h"
#include "machine/regdef.h"
#include "../libbdk-arch/bdk-asm.h"

#define STACK_CACHE_LINES 54      /* Number of cache lines to use in scratch for a stack */

    .globl __start
    .globl __init
    .globl bdk_init_trampoline
    .globl bdk_reset_vector

    .macro exception_stub label
exception_\label:
    dla     k0, bdk_exception2
    jalr    k1, k0  /* Save our address in k1, so we can tell which vector we are coming from. */
    .endm


    #
    # This is our entry point. The processor starts fetching instructions here
    #
    .section .init
    .ent __start
__start:
    b   __init
     nop

    #
    # Exception handlers
    #
    .set push
    .set noat
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
    .set pop

    .set push
    .set noreorder
.org 0x500
__init:
    # Initialise gp
    dla     gp, _gp

    # Setup stack in scratch so we can jump to C code
    dmfc0   t0, COP0_CVMMEMCTL
    and     t0, -64
    or      t0, STACK_CACHE_LINES | (7<<6)
    dmtc0   t0, COP0_CVMMEMCTL
    li      sp, -32768 + STACK_CACHE_LINES * 128

    # Convert bdk_init into an address based on my current location
    li      t0, 0x1fffffff  /* 512MB mask */
    dla     a0, bdk_init    /* Virtual address of bdk_init */
    and     a0, t0          /* Offset from zero of bdk_init in image */
    dla     t1, 1f          /* Address of the upcomming label when image was linked */
    dla     t0, __start     /* Virtual address of __start */
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     dsubu  t1, t0          /* T1 is the offset of the label from the beginning of the image */
1:  dsubu   ra, t1          /* RA is the current location of __start */
    daddu   a0, ra          /* Add RA to A0, getting the current address of bdk_init() */
    jal     a0              /* Call bdk_init(). Its address is in A0 */
     nop
.org 0x580
    .set pop
    .end __start

    .section .text
    .ent bdk_init_trampoline
    .set push
    .set noreorder
    .align 3
bdk_init_trampoline:
    dli     t0, 0x8001180000000000
    sd      a0,0(t0)
    ld      a0,0(t0)
    j       a1
     nop
    .set pop
    .end bdk_init_trampoline

    .ent bdk_reset_vector
    .set push
    .set noreorder
    .align 3
bdk_reset_vector:
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     nop
1:  ld      k0, 16(ra)
    nop
    j       k0
     nop
    .dword   0              /* ld above loads this, so replace with real address */
    .set pop
    .end bdk_reset_vector

