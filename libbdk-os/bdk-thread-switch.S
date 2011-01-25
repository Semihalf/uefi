#include <machine/asm.h>
#include <machine/regdef.h>
#include "../libbdk-arch/bdk-asm.h"

/* k0(26) and k1(27) are not saved */
#define SAVE_REGISTERS 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,28,29,30,31
/* k0(26), k1(27), are not restored. a0(4), a1(5), sp(29), and ra(31) are restored in other code */
#define RESTORE_REGISTERS 1,2,3,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,28,30

.set noat
.set noreorder
    /* A0 is the new context, COP0_USERLOCAL is the old one. COP0_USERLOCAL
        can be zero. If A1 is non zero the old context is freed */
LEAF(__bdk_thread_switch)
    pref    0, 0(a0)            /* Prefetch the new context */
    pref    0, 128(a0)
    pref    0, 256(a0)
    di      k1                  /* Disable interrupts while we switch */
    dmfc0   k0, COP0_USERLOCAL  /* Get the current context */
    beqz    k0, skip_save       /* Skip save if current context is zero */
     dmtc0  a0, COP0_USERLOCAL  /* Store new context in delay slot */

    .irp    n, SAVE_REGISTERS   /* Save all the general registers */
    sd	    $\n, \n*8(k0)
    .endr

    mflo    t8                  /* Get the divide state */
    mfhi    t9
    sd      ra, 33*8(k0)        /* Store the PC */
    sd      t8, 34*8(k0)        /* Save LO */
    sd      t9, 35*8(k0)        /* Save HI */
    syncw                       /* We're done with the old context, push writes out */

skip_save:
    move    a0, k0              /* Put the old context in a0 */
    dmfc0   k0, COP0_USERLOCAL  /* Put the new context in k0 */
    ld      sp, 29*8(k0)        /* Restore the Stack */
    ld      t8, 34*8(k0)        /* Restore mult/divide state */
    ld      t9, 35*8(k0)
    mtlo    t8
    mthi    t9

    daddu   sp, -32             /* Save A0, A1, A2, PC as we clobber them in a call */
    ld	    t8, 4*8(k0)         /* Get saved A0 */
    ld	    t9, 5*8(k0)         /* Get saved A1 */
    sd      t8, (sp)
    sd      t9, 8(sp)
    ld	    t8, 6*8(k0)         /* Get saved A2 */
    ld	    t9, 33*8(k0)        /* Get saved PC */
    sd      t8, 16(sp)
    sd      t9, 24(sp)

    .irp    n, RESTORE_REGISTERS/* Restore most of the general registers */
    ld	    $\n, \n*8(k0)
    .endr

    /* At this point the values in new context is all restored such that
        a yield in this call will not cause problems. A0 is the old context,
        A1 is the delete flag originally passed in. After the EI in hte delay
        slot, K0 and K1 are no longer needed and can be clobbered by a
        interrupt/exception */
    jal     __bdk_thread_switch_complete
     ei     k1                  /* Enable interrupts */

    ld      a0, (sp)            /* Restore A0, A1, A2, and PC */
    ld      a1, 8(sp)
    ld      a2, 16(sp)
    ld      ra, 24(sp)
    jr      ra
     daddu  sp, 32
END(__bdk_thread_switch)

