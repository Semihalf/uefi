#include "machine/asm.h"
#include "machine/regdef.h"
#include "../libbdk-arch/bdk-asm.h"

#define STACK_CACHE_LINES 54      /* Number of cache lines to use in scratch for a stack */

    .globl __start
    .globl __init
    .globl __bdk_reset_vector
    .globl __bdk_reset_vector_data
    .globl __bdk_remote_console

    .macro exception_stub label
exception_\label:
    dla     k0, __bdk_exception2
    jalr    k1, k0  /* Save our address in k1, so we can tell which vector we are coming from. */
    .endm


    #
    # This is our entry point. The processor starts fetching instructions here
    #
    .section .init
    .ent __start
__start:
    b   __init              /* This is replaced with the header, so jump to __init */
     nop
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
__bdk_remote_console:
    # 0x500 - 0x700 is used for the remote console, see bdk-fs-remote.c
    # 0x700 - 0x1000 is unused
    # 0x1000 - 0x2000 is reserved for a Uboot style environment

.org 0x2000
__init:
    /* Clear all registers in case we are running in RTL sim. They start off
        unpredicatable */
    .set push
    .set noat
    move $1, $0
    .set pop
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

    /* Clear many COP0 registers in case we are running in RTL sim.
        They start off unpredicatable */
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
    li k0, 0x4400004
    dmtc0 k0, COP0_STATUS
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

    dmfc0 t0, COP0_CVMCTL
    and   t0, 1 << 27  /* nomul */
    bnez  t0, nomul
    nop
    /* Clear extended multiplier for RTL sim */
    MTM0 $0
    MTM1 $0
    MTM2 $0
    MTP0 $0
    MTP1 $0
    MTP2 $0
nomul:

    /* Enable 64bit addressing and FP */
    MFC0    t0, COP0_STATUS
    or      t0, 1<<7    /* KX */
    or      t0, 1<<29   /* CU1 */
    MTC0    t0, COP0_STATUS
    CTC1    zero, $31

    /* Figure out the location of code as an offset from our link address */
    dla     t1, 1f          /* VA of label 1 */
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     nop
1:
    dsubu   s0, ra, t1      /* s0 = offset to add to VA to get current address */
    li      t0, 0xc0400000  /* Skip relocate if we're already there */
    beq     t0, s0, after_relocate
     nop

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
     nop
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

after_relocate:
    # Initialise gp
    dla     gp, _gp

    # Setup stack in scratch so we can jump to C code
    dmfc0   t0, COP0_CVMMEMCTL
    and     t0, -64
    or      t0, STACK_CACHE_LINES | (7<<6)
    dmtc0   t0, COP0_CVMMEMCTL
    li      sp, -32768 + STACK_CACHE_LINES * 128

    # Zero the scratch stack. This is needed due to an errata on CN63XXp1
    li      t0, STACK_CACHE_LINES * 128 / 8
    li      t1, -32768
1:  sd      $0, (t1)
    sub     t0, 1
    bnez    t0, 1b
     daddu   t1, 8

    # Convert __bdk_init into an address based on my current location
    li      t0, 0x1fffffff  /* 512MB mask */
    dla     a0, __bdk_init  /* Virtual address of __bdk_init */
    and     a0, t0          /* Offset from zero of __bdk_init in image */
    dla     t1, 1f          /* Address of the upcomming label when image was linked */
    dla     t0, __start     /* Virtual address of __start */
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     dsubu  t1, t0          /* T1 is the offset of the label from the beginning of the image */
1:  dsubu   ra, t1          /* RA is the current location of __start */
    daddu   a0, ra          /* Add RA to A0, getting the current address of __bdk_init() */
    jal     a0              /* Call __bdk_init(). Its address is in A0 */
     nop

.align 7
    .set pop
    .end __start

    .section .text
    .ent __bdk_reset_vector
    .set push
    .set noreorder
    .align 3
__bdk_reset_vector:
    /* Figure out the location of code as an offset from our link address */
    dla     t1, 1f          /* VA of label 1 */
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     nop
1:
    dsubu   s0, ra, t1      /* s0 = offset to add to VA to get current address */
    dla     t1, __bdk_reset_vector_data
    daddu   t1, s0          /* This is the real location of __bdk_reset_vector_data */

    /* Read Processor ID and only set KSEGNODE on chips that support it  */
    dmfc0   k0, COP0_PRID
    ext     k0, k0, 8, 16   /* Extract bits 23:16 */
    li      k1, 0x0d95      /* CN78XX CPU Processor ID */
    bne     k0, k1, 1f      /* Branch if not CN78XX */
     ld     k1, 8(t1)       /* Desired KSEGNODE is 2nd dword */
    dmfc0   k0, COP0_CVMMEMCTL2
    ins     k0, k1, 12, 2   /* Set KSEGNODE */
    ld      k1, 0(t1)       /* Jump address is 1st DWORD */
    j       k1
     dmtc0  k0, COP0_CVMMEMCTL2 /* Set in delay slot so next isntruction gets update */
1:  ld      k0, 0(t1)       /* Jump address is 1st DWORD */
    j       k0
     nop
    .align 3
__bdk_reset_vector_data:
    .dword   0              /* ld above loads this, so replace with real address */
    .dword   0              /* ld above loads this, so replace with KSEGNODE */
    .set pop
    .end __bdk_reset_vector

