#include "machine/asm.h"
#include "machine/regdef.h"
#include "../libbdk-arch/bdk-asm.h"

    .globl __start

    .section .text
    .ent __start
__start:
    li      t0, 0x80000000
    j       t0
    .end __start

