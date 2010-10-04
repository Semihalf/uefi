
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

#define OCTEON_CN52XX                   0x000d0700
#define OCTEON_CN63XX                   0x000d9000
#define OCTEON_REFERENCE_CLOCK          50      /* Most all Octeon boards use a 50Mhz reference clock */
#define UART_PORT                       0       /* Output to the first uart. This can be 0 or 1 */
#define UART_BAUD_RATE                  115200  /* Baud rate for the uart */
#define STACK_CACHE_LINES               54      /* Number of cache lines to use in scratch for a stack */
#define NAND_BOOT_TIM_MULT              8       /* NAND timing values for early boot */
/* IMPORTANT: NAND_BOOT_PAGE_BITS _must_ be updated to match the NAND part used. */
#define NAND_BOOT_PAGE_BITS             12      /* NAND on EBB6300 uses 4096 byte pages, or 1<<12 bits */
#define NAND_BOOT_ADDRESS_CYCLES        5       /* Number of NAND address cycles to strobe. Normally either 4 or 5 */
#define USE_INDEX_ALIASING              1       /* Should L2 index alias be used? */
//#define USE_LONG_BIST                   1       /* Run long BIST on L2? */

/* These defines are Octeon CSRs and register offsets from the manual */
#define NDF_BT_PG_INFO      0x8001070001000018
#define NPEI_DBG_DATA       0x80011F0000008510
#define MIO_RST_BOOT        0x8001180000001600
#define L2C_DBG             0x8001180080000030
#define L2C_CFG             0x8001180080000000
#define L2T_ERR             0x8001180080000008
#define L2C_LCKOFF          0x8001180080000060
#define L2C_LCKBASE         0x8001180080000058
#define L2C_CTL             0x8001180080800000
#define L2C_BST_MEM0        0x8001180080C007F8
#define UART_BASE(port)     0x8001180000000800+0x400*(port)
#define UART_LCR            0x18
#define UART_FCR            0x50
#define UART_DLL            0x80
#define UART_DLH            0x88
#define UART_LSR            0x28
#define UART_THR            0x40
#define UART_USR            0x138
#define COP0_CVMCTL         $9,7
#define COP0_CVMMMECTL      $11,7
#define COP0_STATUS         $12,0

    # Global symbols for jumps
    .globl __start
    .globl main
    .globl uart_write_char
    .globl uart_write_string
    .globl uart_write_hex
    .globl jump_to_bootloader
    .globl handle_exception_stub

    # This macro converts a symbol into a relative offset so we can use symbols
    # in flash that are linked at L2 addresses. This macro clobbers "ra".
    .macro dla_rel output, symbol
    dla     \output, \symbol
    dla     ra, 1f
    dsubu   \output, ra
    bgezal  $0, 1f
     nop
1:  daddu   \output, ra
    .endm


    #
    # This is our entry point. The processor starts fetching instructions here
    #
    .text
    .set noreorder
    .ent __start
__start:
    # Setup stack in scratch so we can jump to C code
    dmfc0   t0, COP0_CVMMMECTL
    and     t0, -64
    or      t0, STACK_CACHE_LINES | (1<<8)
    dmtc0   t0, COP0_CVMMMECTL
    li      sp, -32768 + STACK_CACHE_LINES * 128

    dla     gp,_gp          # initialise $gp
    move    ra, zero
    move    fp, sp

    # Jump to C code
    dla     t0, main
    jal     t0
     nop
     .end __start


