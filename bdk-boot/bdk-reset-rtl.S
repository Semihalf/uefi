#include "machine/asm.h"
#include "machine/regdef.h"
#include "../libbdk-arch/bdk-asm.h"

    .globl __start

    .section .text
    .ent __start
__start:
    .set noat
    move $1, $0
    .set at
    move $2, $0
    move $3, $0
    move $4, $0
    move $5, $0
    move $6, $0
    move $7, $0
    move $8, $0
    move $9, $0
    move $10, $0
    move $11, $0
    move $12, $0
    move $13, $0
    move $14, $0
    move $15, $0
    move $16, $0
    move $17, $0
    move $18, $0
    move $19, $0
    move $20, $0
    move $21, $0
    move $22, $0
    move $23, $0
    move $24, $0
    move $25, $0
    move $26, $0
    move $27, $0
    move $28, $0
    move $29, $0
    move $30, $0
    move $31, $0
    mtlo    $0
    mthi    $0
    dmtc0 $0, COP0_XCONTEXT
    dmtc0 $0, COP0_WATCHLO0
    dmtc0 $0, COP0_WATCHLO1
    dmtc0 $0, COP0_WATCHHI0
    dmtc0 $0, COP0_WATCHHI1
    dmtc0 $0, COP0_EPC
    dmtc0 $0, COP0_ERROREPC
    dmtc0 $0, COP0_CACHEERRI
    dmtc0 $0, COP0_CACHEERRD
    dmtc0 $0, COP0_CAUSE
    dmtc0 $0, COP0_HWRENA

    li      t0, 0x80000000
    j       t0
    .end __start

