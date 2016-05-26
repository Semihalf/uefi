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
 * XCP Transaction Command Enumeration
 * Enumerates the different transaction commands for XCP.
 * Internal:
 * FIXME is enum internal?
 */
#define BDK_XCP_NCB_TX_CMD_E_INVALID (0)
#define BDK_XCP_NCB_TX_CMD_E_INVALIDATE (4)
#define BDK_XCP_NCB_TX_CMD_E_READ (1)
#define BDK_XCP_NCB_TX_CMD_E_SYNC (3)
#define BDK_XCP_NCB_TX_CMD_E_WRITE (2)

/**
 * Register (NCB32b) xcp#_win#_addr
 *
 * XCP RSL/NCB WINDOW ADDRESS Register
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
        return 0x82c000000200ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
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
 * XCP RSL/NCB WINDOW CONFIG Register
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
        return 0x82c000000100ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
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
 * XCP RSL/NCB WINDOW INVALIDATE Register
 * This register contains the invalidate bits for the XCP core RSL/NCB access windows.
 */
typedef union
{
    uint32_t u;
    struct bdk_xcpx_winx_inv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t invalidate            : 1;  /**< [  0:  0](WO) Writing a 1 will invalidate this window's read cache, and flush the write buffer. */
#else /* Word 0 - Little Endian */
        uint32_t invalidate            : 1;  /**< [  0:  0](WO) Writing a 1 will invalidate this window's read cache, and flush the write buffer. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcpx_winx_inv_s cn; */
} bdk_xcpx_winx_inv_t;

static inline uint64_t BDK_XCPX_WINX_INV(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCPX_WINX_INV(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a==0) && (b<=3)))
        return 0x82c000000000ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("XCPX_WINX_INV", 2, a, b, 0, 0);
}

#define typedef_BDK_XCPX_WINX_INV(a,b) bdk_xcpx_winx_inv_t
#define bustype_BDK_XCPX_WINX_INV(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_XCPX_WINX_INV(a,b) "XCPX_WINX_INV"
#define device_bar_BDK_XCPX_WINX_INV(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_XCPX_WINX_INV(a,b) (a)
#define arguments_BDK_XCPX_WINX_INV(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_XCP_H__ */
