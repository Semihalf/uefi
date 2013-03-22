#include "machine/asm.h"
#include "machine/regdef.h"
#include "../libbdk-arch/bdk-asm.h"

    .globl __start
    .globl __init

    #
    # This is our entry point. The processor starts fetching instructions here
    #
    .section .text
    .set push
    .set noreorder
    .ent __start
__start:
    /* Enable 64bit addressing */
    MFC0    t0, COP0_STATUS
    or      t0, 1<<7
    MTC0    t0, COP0_STATUS

    dli     k0, 0x8001011000000100 /* CIU_PP_RST */
    ld      k1, 0(k0)
    and     k1, -2
    sd      k1, 0(k0)
1:  b 1b
     wait
    nop
    .set pop
    .end __start

