#include <machine/asm.h>
#include <machine/regdef.h>
#include "../libbdk-arch/bdk-asm.h"

/* k0(26) and k1(27) are not saved */
#define REGISTERS 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,28,29,30,31

.set noat
.set noreorder
    /* A0 is the new context, COP0_USERLOCAL is the old one. COP0_USERLOCAL
        can be zero. If A1 is non zero the old context is freed */
LEAF(__bdk_thread_switch)
    pref    0, 0(a0)            /* Prefetch the new context */
    di      k1                  /* Disable interrupts while we switch */
    dmfc0   k0, COP0_USERLOCAL  /* Get the current context */
    pref    0, 128(a0)
    pref    0, 256(a0)
    beqz    k0, no_free_old     /* Skip save if current context is zero */
     dmtc0  a0, COP0_USERLOCAL  /* Store new context in delay slot */

    .irp    n, REGISTERS        /* Save all the general registers */
    sd	    $\n, \n*8(k0)
    .endr

    mfhi    t0                  /* Save the mult/divide state */
    mflo    t1
    sd      t0, 34*8(k0)
    sd      t1, 35*8(k0)
    sd      ra, 33*8(k0)        /* Store the PC */

    beqz    a1, no_free_old     /* Skip deleting the old context if a1==0 */
     ld     sp, 29*8(a0)        /* Swap stacks */
    jal     free                /* Call free old context using new context stack */
     move   a0, k0

no_free_old:
    dmfc0   k0, COP0_USERLOCAL  /* Put the new context in k0 */
    ld      t0, 34*8(k0)        /* Restore mult/divide state */
    ld      t1, 35*8(k0)
    mthi    t0
    mtlo    t1

    .irp    n, REGISTERS        /* Restore all the general registers */
    ld	    $\n, \n*8(k0)
    .endr

    ld      k0, 33*8(k0)        /* Load the PC */
    j       k0                  /* Jump to the new PC */
     ei     k1                  /* Enable interrupts */
END(__bdk_thread_switch)

