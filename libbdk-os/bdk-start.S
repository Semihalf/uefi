#include "machine/asm.h"
#include "machine/regdef.h"
#include "../libbdk-arch/bdk-asm.h"

#define STACK_CACHE_LINES 6      /* Number of cache lines to use in scratch for a stack */

    .globl __start
    .globl __init
    .globl __bdk_reset_vector

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
    b   _init               /* This is replaced with the header, so jump to __init */
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
_init:
    /* Enable 64bit addressing */
    MFC0    t0, COP0_STATUS
    or      t0, 1<<7
    MTC0    t0, COP0_STATUS

    /* Check if we need relocation */
    dmfc0   t0, COP0_EBASE  /* Only core zero needs to do relocation */
    and     t0, 0x3ff       /* Core nubmer is lower 10 bits */
    bnez    t0, after_relocate
     nop

    /* Figure out the location of code as an offset from our link address */
    dla     t1, 1f          /* VA of label 1 */
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     nop
1:
    dsubu   s0, ra, t1      /* s0 = offset to add to VA to get current address */

    /* See if we're running from a bootbus address */
    dsra    t0, ra, 28              /* Shift PC 28 bits, leaving the top nibble */
    li      t1, 0xfffffffb          /* Bootbus address starts with 0xb, sign extended */
    bne     t0, t1, skip_l2_disidxalias /* only run the next code if we're not in flash */
     nop

    /* Disable L2 indexed aliasing if we're running from flash. Indexed
        aliasing won't allow us to lock a linear range into L2 */
    dli     t0, 0x8001180080800000  /* L2C_CTL address */
    ld      t1, (t0)                /* Load L2C_CTL */
    ori     t1, 1                   /* Set L2C_CTL[disidxalias] */
    sd      t1, (t0)                /* Store L2C_CTL */
    ld      $0, (t0)                /* Read L2C_CTL to make sure the update is complete */

skip_l2_disidxalias:
    /* Copy copy_code to L2 at address 0 */
    li      a0, 0x80000000  /* Where we are putting copy_code */
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
    li      a0, 0x80000000  /* Load new location of copy_code */
    j       a0              /* Jump to it */
     nop
.align 3
copy_code:
    dla     a2, _end        /* We're copy everything up to __end */
    dla     a1, _init       /* VA of _init */
    daddu   a2, 7           /* Add 7 to _end so that it will be 8 byte aligned after mask */
    li      a0, 0x80000500  /* Where we're copying to */
    and     a2, 0x0ffffff8  /* Strip off upper bits of _end to remove VA bits and round to 8 byte */
    daddu   a1, s0          /* Convert __start to the current location */
    dsubu   a2, 0x500       /* Subtract out the 0x500 we skipped from the length */
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
    bgezal  $0, 1f          /* Jump to label, saving our PC in RA */
     nop
1:  ld      k0, 16(ra)
    nop
    j       k0
     nop
    .dword   0              /* ld above loads this, so replace with real address */
    .set pop
    .end __bdk_reset_vector

