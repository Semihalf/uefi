#include <machine/asm.h>
#include <machine/regdef.h>

.set noreorder
.set noat

LEAF(bdk_exception)
    dla     k0, bdk_exception2
    jalr    k1, k0  /* Save our address in k1, so we can tell which vector we are coming from. */
     nop
END(bdk_exception)

#define REGISTERS 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,/* k0 26,*/27,28,29,30,31
#define BDK_EXCEPTION_STACK_SIZE 1024

LEAF(bdk_exception2)
    dla     k0, bdk_exception_stack
    daddu   k0, BDK_EXCEPTION_STACK_SIZE - 8*34
    .irp    n, REGISTERS
    sd	    $\n, \n*8(k0)
    .endr
    mfhi    t0
    mflo    t1
    dla     t9, bdk_exception_handler
    sd      t0, 32*8(k0)
    sd      t1, 33*8(k0)

    jal     t9
     move   a0, k0

    ld      t0, 32*8(k0)
    ld      t1, 33*8(k0)
    mthi    t0
    mtlo    t1
    .irp    n, REGISTERS
    ld	    $\n, \n*8(k0)
    .endr

    eret
END(bdk_exception2)

