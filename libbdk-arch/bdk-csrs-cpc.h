#ifndef __BDK_CSRS_CPC_H__
#define __BDK_CSRS_CPC_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.

 *   * Neither the name of Cavium Inc. nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium CPC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration cpc_bar_e
 *
 * CPC Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CPC_BAR_E_CPC_PF_BAR0 (0x86d000000000ll)
#define BDK_CPC_BAR_E_CPC_PF_BAR0_SIZE 0x100000ull
#define BDK_CPC_BAR_E_CPC_PF_BAR4 (0x86d000100000ll)
#define BDK_CPC_BAR_E_CPC_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration cpc_xcp_map_e
 *
 * XCP mapping Enumeration
 * Enumerates the XCP to MCP or SCP mapping.
 */
#define BDK_CPC_XCP_MAP_E_CPC_XCP_MCP (1)
#define BDK_CPC_XCP_MAP_E_CPC_XCP_SCP (0)

/**
 * Register (NCB32b) cpc_const
 *
 * CPC Constants Register
 */
typedef union
{
    uint32_t u;
    struct bdk_cpc_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cores                 : 8;  /**< [  7:  0](RO) Indicates number of XCP cores within CPC. */
#else /* Word 0 - Little Endian */
        uint32_t cores                 : 8;  /**< [  7:  0](RO) Indicates number of XCP cores within CPC. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cpc_const_s cn; */
} bdk_cpc_const_t;

#define BDK_CPC_CONST BDK_CPC_CONST_FUNC()
static inline uint64_t BDK_CPC_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPC_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x86d000000000ll;
    __bdk_csr_fatal("CPC_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CPC_CONST bdk_cpc_const_t
#define bustype_BDK_CPC_CONST BDK_CSR_TYPE_NCB32b
#define basename_BDK_CPC_CONST "CPC_CONST"
#define device_bar_BDK_CPC_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_CPC_CONST 0
#define arguments_BDK_CPC_CONST -1,-1,-1,-1

/**
 * Register (NCB32b) cpc_eco
 *
 * INTERNAL: CPC ECO Register
 */
typedef union
{
    uint32_t u;
    struct bdk_cpc_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint32_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cpc_eco_s cn; */
} bdk_cpc_eco_t;

#define BDK_CPC_ECO BDK_CPC_ECO_FUNC()
static inline uint64_t BDK_CPC_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPC_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x86d000000100ll;
    __bdk_csr_fatal("CPC_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CPC_ECO bdk_cpc_eco_t
#define bustype_BDK_CPC_ECO BDK_CSR_TYPE_NCB32b
#define basename_BDK_CPC_ECO "CPC_ECO"
#define device_bar_BDK_CPC_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_CPC_ECO 0
#define arguments_BDK_CPC_ECO -1,-1,-1,-1

/**
 * Register (NCB) cpc_ram_mem#
 *
 * CPC RAM Memory Registers
 * These registers access the CPC RAM memory space.
 */
typedef union
{
    uint64_t u;
    struct bdk_cpc_ram_memx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO) RAM data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO) RAM data. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cpc_ram_memx_s cn; */
} bdk_cpc_ram_memx_t;

static inline uint64_t BDK_CPC_RAM_MEMX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPC_RAM_MEMX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=65535))
        return 0x86d000080000ll + 8ll * ((a) & 0xffff);
    __bdk_csr_fatal("CPC_RAM_MEMX", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPC_RAM_MEMX(a) bdk_cpc_ram_memx_t
#define bustype_BDK_CPC_RAM_MEMX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPC_RAM_MEMX(a) "CPC_RAM_MEMX"
#define device_bar_BDK_CPC_RAM_MEMX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPC_RAM_MEMX(a) (a)
#define arguments_BDK_CPC_RAM_MEMX(a) (a),-1,-1,-1

/**
 * Register (NCB32b) cpc_ram_permit#
 *
 * CPC RAM Permit Registers
 * These registers are used to control the RAM space access permissions of the MIPS and AP cores
 * The RAM is split into 32 secure regions.
 */
typedef union
{
    uint32_t u;
    struct bdk_cpc_ram_permitx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_4_31         : 28;
        uint32_t permitdis             : 4;  /**< [  3:  0](R/W) Access permission of each access group.
                                                                 <3> if set disallows MCP access.
                                                                 <2> if set disallows SCP access.
                                                                 <1> if set disallows AP secure access.
                                                                 <0> indicates AP nonsecure access. */
#else /* Word 0 - Little Endian */
        uint32_t permitdis             : 4;  /**< [  3:  0](R/W) Access permission of each access group.
                                                                 <3> if set disallows MCP access.
                                                                 <2> if set disallows SCP access.
                                                                 <1> if set disallows AP secure access.
                                                                 <0> indicates AP nonsecure access. */
        uint32_t reserved_4_31         : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cpc_ram_permitx_s cn; */
} bdk_cpc_ram_permitx_t;

static inline uint64_t BDK_CPC_RAM_PERMITX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPC_RAM_PERMITX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=31))
        return 0x86d000000200ll + 8ll * ((a) & 0x1f);
    __bdk_csr_fatal("CPC_RAM_PERMITX", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPC_RAM_PERMITX(a) bdk_cpc_ram_permitx_t
#define bustype_BDK_CPC_RAM_PERMITX(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_CPC_RAM_PERMITX(a) "CPC_RAM_PERMITX"
#define device_bar_BDK_CPC_RAM_PERMITX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPC_RAM_PERMITX(a) (a)
#define arguments_BDK_CPC_RAM_PERMITX(a) (a),-1,-1,-1

/**
 * Register (NCB) cpc_rom_mem#
 *
 * CPC ROM Memory Registers
 * These registers access the CPC ROM memory space.
 */
typedef union
{
    uint64_t u;
    struct bdk_cpc_rom_memx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO) ROM data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](RO) ROM data. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cpc_rom_memx_s cn; */
} bdk_cpc_rom_memx_t;

static inline uint64_t BDK_CPC_ROM_MEMX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPC_ROM_MEMX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=6145))
        return 0x86d000010000ll + 8ll * ((a) & 0x1fff);
    __bdk_csr_fatal("CPC_ROM_MEMX", 1, a, 0, 0, 0);
}

#define typedef_BDK_CPC_ROM_MEMX(a) bdk_cpc_rom_memx_t
#define bustype_BDK_CPC_ROM_MEMX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_CPC_ROM_MEMX(a) "CPC_ROM_MEMX"
#define device_bar_BDK_CPC_ROM_MEMX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CPC_ROM_MEMX(a) (a)
#define arguments_BDK_CPC_ROM_MEMX(a) (a),-1,-1,-1

/**
 * Register (NCB32b) cpc_timer
 *
 * CPC Timer Register
 * This register contains the common timer register for the XCP cores.
 */
typedef union
{
    uint32_t u;
    struct bdk_cpc_timer_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tmr                   : 32; /**< [ 31:  0](R/W/H) Free running count of coprocessor clock cycles. */
#else /* Word 0 - Little Endian */
        uint32_t tmr                   : 32; /**< [ 31:  0](R/W/H) Free running count of coprocessor clock cycles. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cpc_timer_s cn; */
} bdk_cpc_timer_t;

#define BDK_CPC_TIMER BDK_CPC_TIMER_FUNC()
static inline uint64_t BDK_CPC_TIMER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CPC_TIMER_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x86d000000104ll;
    __bdk_csr_fatal("CPC_TIMER", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CPC_TIMER bdk_cpc_timer_t
#define bustype_BDK_CPC_TIMER BDK_CSR_TYPE_NCB32b
#define basename_BDK_CPC_TIMER "CPC_TIMER"
#define device_bar_BDK_CPC_TIMER 0x0 /* PF_BAR0 */
#define busnum_BDK_CPC_TIMER 0
#define arguments_BDK_CPC_TIMER -1,-1,-1,-1

#endif /* __BDK_CSRS_CPC_H__ */
