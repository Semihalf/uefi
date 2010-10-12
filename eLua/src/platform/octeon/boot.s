
/***********************license start***************
 * Copyright (c) 2003-2007 Cavium Networks (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *     * Neither the name of Cavium Networks nor the names of
 *       its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS
 * OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
 * RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
 * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
 * DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
 * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
 * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET
 * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT
 * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 *
 *
 * For any questions regarding licensing please contact marketing@caviumnetworks.com
 *
 ***********************license end**************************************/
#include "machine/asm.h"
#include "machine/regdef.h"
#include "../../../../libbdk-arch/bdk-asm.h"

#define STACK_CACHE_LINES 54      /* Number of cache lines to use in scratch for a stack */

    .globl __start

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
    dmfc0   t0, COP0_CVMCTL
    or      t0, 1<<12           /* Use unaligned instructions */
    or      t0, 1<<14           /* Fix unaligned accesses */
    dmtc0   t0, COP0_CVMCTL

    li      t0, 7<<29           /* Enable RI/XI and large physical addresses */
    mtc0    t0, COP0_PAGEGRAIN
    li      t0, (4<<(20+1))-1   /* Use 4MB pages */
    mtc0    t0, COP0_PAGEMASK

    # Get my current location in memory
    bal     1f
1:
    dla     t0, 1b
    and     t0, 0xffff
    dsubu   a0, ra, t0
    and     a0, 0x1fffffff

    # Convert the PA to an EntryLo
    dsrl    a0, 6
    or      a0, 3               /* Set Valid and Global */

    # Add TLB for Text
    dmtc0   a0, COP0_ENTRYLO0
    li      t0, 1
    dmtc0   t0, COP0_ENTRYLO1
    li      t0, 0xe0000000
    dmtc0   t0, COP0_ENTRYHI
    dmtc0   $0, COP0_INDEX
    tlbwi

    # Add TLB for Data
    or      a0, 4 /* Set dirty */
    dmtc0   a0, COP0_ENTRYLO0
    li      t0, 1
    dmtc0   t0, COP0_ENTRYLO1
    dmtc0   t0, COP0_INDEX
    li      t0, 0xc0000000
    dmtc0   t0, COP0_ENTRYHI
    tlbwi

    # Set wired to be two entries
    li      t0, 2
    dmtc0   t0, COP0_WIRED

    # Clear cause
    mtc0    $0, COP0_CAUSE

    # Disable ERL, EXL, and IE
    mfc0    t0, COP0_STATUS
    and     t0, ~(0xff<<8)      /* Clear IM enables */
    and     t0, ~(3<<3)         /* Set kernel mode */
    and     t0, ~(1<<2)         /* Disable ERL */
    and     t0, ~(1<<1)         /* Disable EXL */
    and     t0, ~(1<<0)         /* Disable IE */
    mtc0    t0, COP0_STATUS

    # Setup stack in scratch so we can jump to C code
    dmfc0   t0, COP0_CVMMEMCTL
    and     t0, -64
    or      t0, STACK_CACHE_LINES | (1<<8)
    dmtc0   t0, COP0_CVMMEMCTL
    li      sp, -32768 + STACK_CACHE_LINES * 128

    dla     gp,_gp          # initialise $gp
    move    ra, zero
    move    fp, sp

    # Jump to C code
    dla     t0, main
    jal     t0
     nop

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
.org 0x500
    .set pop
    .end __start


