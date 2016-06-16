#ifndef __BDK_CSRS_XCP_H__
#define __BDK_CSRS_XCP_H__
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
 * Cavium XCP.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration xcp_bar_e
 *
 * XCP Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_XCP_BAR_E_XCPX_PF_BAR0(a) (0x82c000000000ll + 0x1000000000ll * (a))
#define BDK_XCP_BAR_E_XCPX_PF_BAR0_SIZE 0x100000ull
#define BDK_XCP_BAR_E_XCPX_PF_BAR4(a) (0x82c000100000ll + 0x1000000000ll * (a))
#define BDK_XCP_BAR_E_XCPX_PF_BAR4_SIZE 0x100000ull

/**
 * Enumeration xcp_ncb_tx_cmd_e
 *
 * INTERNAL: XCP Transaction Command Enumeration
 *
 * Enumerates the different transaction commands for XCP.
 */
#define BDK_XCP_NCB_TX_CMD_E_INVALID (0)
#define BDK_XCP_NCB_TX_CMD_E_INVALIDATE (4)
#define BDK_XCP_NCB_TX_CMD_E_READ (1)
#define BDK_XCP_NCB_TX_CMD_E_SYNC (3)
#define BDK_XCP_NCB_TX_CMD_E_WRITE (2)

/**
 * Register (NCB32b) xcp#_cfg
 *
 * XCP Configuration Register
 * This register contains the configuration bits for XCP.
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t sync_inv_rdc          : 1;  /**< [  1:  1](R/W) If set, invalidate all windows read caches on a sync operation. */
        uint32_t ro_dis                : 1;  /**< [  0:  0](R/W) Disable for XCP_NCB relaxed ordering (ro) bit on NCBI transactions. */
#else /* Word 0 - Little Endian */
        uint32_t ro_dis                : 1;  /**< [  0:  0](R/W) Disable for XCP_NCB relaxed ordering (ro) bit on NCBI transactions. */
        uint32_t sync_inv_rdc          : 1;  /**< [  1:  1](R/W) If set, invalidate all windows read caches on a sync operation. */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_cfg_s cn; */
} bdk_xcpx_cfg_t;

static inline uint64_t BDK_XCPX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x82c000000200ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("XCPX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_XCPX_CFG(a) bdk_xcpx_cfg_t
#define bustype_BDK_XCPX_CFG(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_CFG(a) "XCPX_CFG"
#define device_bar_BDK_XCPX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_CFG(a) (a)
#define arguments_BDK_XCPX_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB32b) xcp#_const
 *
 * XCP Constants Register
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t wins                  : 8;  /**< [  7:  0](RO) Number of windows supported. */
#else /* Word 0 - Little Endian */
        uint32_t wins                  : 8;  /**< [  7:  0](RO) Number of windows supported. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_const_s cn; */
} bdk_xcpx_const_t;

static inline uint64_t BDK_XCPX_CONST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_CONST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x82c000000000ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("XCPX_CONST", 1, a, 0, 0, 0);
}

#define typedef_BDK_XCPX_CONST(a) bdk_xcpx_const_t
#define bustype_BDK_XCPX_CONST(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_CONST(a) "XCPX_CONST"
#define device_bar_BDK_XCPX_CONST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_CONST(a) (a)
#define arguments_BDK_XCPX_CONST(a) (a),-1,-1,-1

/**
 * Register (NCB32b) xcp#_eco
 *
 * INTERNAL: XCP ECO Register
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint32_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_eco_s cn; */
} bdk_xcpx_eco_t;

static inline uint64_t BDK_XCPX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x82c000000100ll + 0x1000000000ll * ((a) & 0x0);
    __bdk_csr_fatal("XCPX_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_XCPX_ECO(a) bdk_xcpx_eco_t
#define bustype_BDK_XCPX_ECO(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_ECO(a) "XCPX_ECO"
#define device_bar_BDK_XCPX_ECO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_ECO(a) (a)
#define arguments_BDK_XCPX_ECO(a) (a),-1,-1,-1

/**
 * Register (NCB32b) xcp#_seg#_map_reg
 *
 * XCP Segment Mapping Register
 * This register contains the segment mapping from the MIPS core addresses
 * to sections of the CPC RAM.
 * * SEG0 corresponds to kuseg.
 * * SEG1 corresponds to kseg0/kseg1.
 * * SEG2 corresponds to kseg2.
 * * SEG3 corresponds to kseg3.
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_segx_map_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_11_31        : 21;
        uint32_t top                   : 6;  /**< [ 10:  5](R/W) Upper address <18:14> top limit for this segment. */
        uint32_t base                  : 5;  /**< [  4:  0](R/W) CPC RAM base address <18:14> for this segment. */
#else /* Word 0 - Little Endian */
        uint32_t base                  : 5;  /**< [  4:  0](R/W) CPC RAM base address <18:14> for this segment. */
        uint32_t top                   : 6;  /**< [ 10:  5](R/W) Upper address <18:14> top limit for this segment. */
        uint32_t reserved_11_31        : 21;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_segx_map_reg_s cn; */
} bdk_xcpx_segx_map_reg_t;

static inline uint64_t BDK_XCPX_SEGX_MAP_REG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_SEGX_MAP_REG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x82c000000600ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("XCPX_SEGX_MAP_REG", 2, a, b, 0, 0);
}

#define typedef_BDK_XCPX_SEGX_MAP_REG(a,b) bdk_xcpx_segx_map_reg_t
#define bustype_BDK_XCPX_SEGX_MAP_REG(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_SEGX_MAP_REG(a,b) "XCPX_SEGX_MAP_REG"
#define device_bar_BDK_XCPX_SEGX_MAP_REG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_SEGX_MAP_REG(a,b) (a)
#define arguments_BDK_XCPX_SEGX_MAP_REG(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) xcp#_win#_addr
 *
 * XCP Window Address Register
 * This register contains the upper address bits for the XCP core RSL/NCB access windows.
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_winx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t addr                  : 29; /**< [ 28:  0](R/W) IOVA bits 52:24. If {RSL_NCB_N] = 1 (RSL), only IOVA 47:24 are used (as a physical
                                                                 address). */
#else /* Word 0 - Little Endian */
        uint32_t addr                  : 29; /**< [ 28:  0](R/W) IOVA bits 52:24. If {RSL_NCB_N] = 1 (RSL), only IOVA 47:24 are used (as a physical
                                                                 address). */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_winx_addr_s cn; */
} bdk_xcpx_winx_addr_t;

static inline uint64_t BDK_XCPX_WINX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_WINX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x82c000000400ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("XCPX_WINX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_XCPX_WINX_ADDR(a,b) bdk_xcpx_winx_addr_t
#define bustype_BDK_XCPX_WINX_ADDR(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_WINX_ADDR(a,b) "XCPX_WINX_ADDR"
#define device_bar_BDK_XCPX_WINX_ADDR(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_WINX_ADDR(a,b) (a)
#define arguments_BDK_XCPX_WINX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) xcp#_win#_cfg
 *
 * XCP Window Configuration Register
 * This register contains the control bits for the XCP core RSL/NCB access windows.
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_winx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_6_31         : 26;
        uint32_t b64                   : 1;  /**< [  5:  5](R/W) 64-bit window. If [RSL_NCB_N] is set, specifices if the window access size.
                                                                 0 = 32 bit.
                                                                 1 = 64 bit. */
        uint32_t rsl_ncb_n             : 1;  /**< [  4:  4](R/W) RSL or NCB window type.
                                                                 0 = NCB.  Accesses may be cached, based on [CACHABLE] and [ACCUM_DIS].
                                                                 1 = RSL.  Accesses will never be cached. */
        uint32_t secure                : 1;  /**< [  3:  3](R/W) Secure-world transaction.
                                                                 0 = Nonsecure world for RSL or NCB transactions.
                                                                 1 = Secure world for RSL or NCB transactions. */
        uint32_t phys                  : 1;  /**< [  2:  2](R/W) Physical address.
                                                                 0 = Virtual address. NCB IOVAs will be translated by the SMMU.
                                                                 1 = Physical address. NCB IOVAs bypass SMMU translation, and IOVA <52> is ignored.

                                                                 Ignored and acts as if set when [RSL_NCB_N] = 1 (RSL). */
        uint32_t accum_dis             : 1;  /**< [  1:  1](R/W) Accumulation disable.
                                                                   0 = Window will accumulate writes.
                                                                   1 = Writes are not accumulated, every write is sent to NCB.

                                                                 Ignored and acts as if set when [RSL_NCB_N] = 1 (RSL). */
        uint32_t cacheable             : 1;  /**< [  0:  0](R/W) Cacheable.
                                                                   0 = Not cachable.
                                                                   1 = Cachable.

                                                                 Ignored and acts as if clear when [RSL_NCB_N] = 1 (RSL). */
#else /* Word 0 - Little Endian */
        uint32_t cacheable             : 1;  /**< [  0:  0](R/W) Cacheable.
                                                                   0 = Not cachable.
                                                                   1 = Cachable.

                                                                 Ignored and acts as if clear when [RSL_NCB_N] = 1 (RSL). */
        uint32_t accum_dis             : 1;  /**< [  1:  1](R/W) Accumulation disable.
                                                                   0 = Window will accumulate writes.
                                                                   1 = Writes are not accumulated, every write is sent to NCB.

                                                                 Ignored and acts as if set when [RSL_NCB_N] = 1 (RSL). */
        uint32_t phys                  : 1;  /**< [  2:  2](R/W) Physical address.
                                                                 0 = Virtual address. NCB IOVAs will be translated by the SMMU.
                                                                 1 = Physical address. NCB IOVAs bypass SMMU translation, and IOVA <52> is ignored.

                                                                 Ignored and acts as if set when [RSL_NCB_N] = 1 (RSL). */
        uint32_t secure                : 1;  /**< [  3:  3](R/W) Secure-world transaction.
                                                                 0 = Nonsecure world for RSL or NCB transactions.
                                                                 1 = Secure world for RSL or NCB transactions. */
        uint32_t rsl_ncb_n             : 1;  /**< [  4:  4](R/W) RSL or NCB window type.
                                                                 0 = NCB.  Accesses may be cached, based on [CACHABLE] and [ACCUM_DIS].
                                                                 1 = RSL.  Accesses will never be cached. */
        uint32_t b64                   : 1;  /**< [  5:  5](R/W) 64-bit window. If [RSL_NCB_N] is set, specifices if the window access size.
                                                                 0 = 32 bit.
                                                                 1 = 64 bit. */
        uint32_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_winx_cfg_s cn; */
} bdk_xcpx_winx_cfg_t;

static inline uint64_t BDK_XCPX_WINX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_WINX_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x82c000000300ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("XCPX_WINX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_XCPX_WINX_CFG(a,b) bdk_xcpx_winx_cfg_t
#define bustype_BDK_XCPX_WINX_CFG(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_WINX_CFG(a,b) "XCPX_WINX_CFG"
#define device_bar_BDK_XCPX_WINX_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_WINX_CFG(a,b) (a)
#define arguments_BDK_XCPX_WINX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) xcp#_win#_inv
 *
 * XCP Window Invalidate Register
 * This register contains the invalidate bits for the RSL/NCB window 0-3 for the MIPS core to
 * read/write from/to to reach Thunder memory.
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_winx_inv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t invalidate            : 1;  /**< [  0:  0](WO) Writing a 1 will invalidate this window's read cache and flush the write cache. */
#else /* Word 0 - Little Endian */
        uint32_t invalidate            : 1;  /**< [  0:  0](WO) Writing a 1 will invalidate this window's read cache and flush the write cache. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_winx_inv_s cn; */
} bdk_xcpx_winx_inv_t;

static inline uint64_t BDK_XCPX_WINX_INV(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_WINX_INV(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x82c000000500ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("XCPX_WINX_INV", 2, a, b, 0, 0);
}

#define typedef_BDK_XCPX_WINX_INV(a,b) bdk_xcpx_winx_inv_t
#define bustype_BDK_XCPX_WINX_INV(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_WINX_INV(a,b) "XCPX_WINX_INV"
#define device_bar_BDK_XCPX_WINX_INV(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_WINX_INV(a,b) (a)
#define arguments_BDK_XCPX_WINX_INV(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_XCP_H__ */
