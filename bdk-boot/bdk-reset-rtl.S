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

    dmtc0 $0, COP0_INDEX
    dmtc0 $0, COP0_RANDOM
    dmtc0 $0, COP0_ENTRYLO0
    dmtc0 $0, COP0_ENTRYLO1
    dmtc0 $0, COP0_CONTEXT
    dmtc0 $0, COP0_USERLOCAL
    dmtc0 $0, COP0_PAGEMASK
    dmtc0 $0, COP0_PAGEGRAIN
    dmtc0 $0, COP0_WIRED
    dmtc0 $0, COP0_HWRENA
    dmtc0 $0, COP0_BADVADDR
    dmtc0 $0, COP0_COUNT
    dmtc0 $0, COP0_CVMCOUNT
    /* dmtc0 $0, COP0_CVMCTL */
    dmtc0 $0, COP0_ENTRYHI
    dmtc0 $0, COP0_COMPARE
    /* dmtc0 $0, COP0_POWTHROTTLE */
    /* dmtc0 $0, COP0_CVMMEMCTL */
    /* dmtc0 $0, COP0_STATUS */
    dmtc0 $0, COP0_INTCTL
    dmtc0 $0, COP0_SRSCTL
    dmtc0 $0, COP0_CAUSE
    dmtc0 $0, COP0_EPC
    /* dmtc0 $0, COP0_PRID */
    dmtc0 $0, COP0_EBASE
    /* dmtc0 $0, COP0_CONFIG */
    /* dmtc0 $0, COP0_CONFIG1 */
    /* dmtc0 $0, COP0_CONFIG2 */
    /* dmtc0 $0, COP0_CONFIG3 */
    /* dmtc0 $0, COP0_CONFIG4 */
    dmtc0 $0, COP0_WATCHLO0
    dmtc0 $0, COP0_WATCHLO1
    dmtc0 $0, COP0_WATCHHI0
    dmtc0 $0, COP0_WATCHHI1
    dmtc0 $0, COP0_XCONTEXT
    dmtc0 $0, COP0_MULTICOREDEBUG
    /* dmtc0 $0, COP0_DEBUG */
    /* dmtc0 $0, COP0_DEBUG2 */
    dmtc0 $0, COP0_DEPC
    dmtc0 $0, COP0_PERFCONTROL0
    dmtc0 $0, COP0_PERFCONTROL1
    dmtc0 $0, COP0_PERFVALUE0
    dmtc0 $0, COP0_PERFVALUE1
    dmtc0 $0, COP0_CACHEERRI
    dmtc0 $0, COP0_CACHEERRD
    dmtc0 $0, COP0_TAGLOI
    dmtc0 $0, COP0_TAGLOD
    dmtc0 $0, COP0_DATALOI
    dmtc0 $0, COP0_DATALOD
    dmtc0 $0, COP0_TAGHI
    dmtc0 $0, COP0_DATAHII
    dmtc0 $0, COP0_DATAHID
    dmtc0 $0, COP0_ERROREPC
    dmtc0 $0, COP0_DESAVE
    dmtc0 $0, COP0_KSCRATCH1
    dmtc0 $0, COP0_KSCRATCH2
    dmtc0 $0, COP0_KSCRATCH3

    /* Clear extended multiplier */
    MTM0 $0
    MTM1 $0
    MTM2 $0
    MTP2 $0
    MTP1 $0
    MTP0 $0

    li      t0, 0x80100000
    j       t0
    .end __start

