#ifndef __BDK_CSRS_PEM_H__
#define __BDK_CSRS_PEM_H__
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
 * Cavium PEM.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration pem_bar_e
 *
 * PEM Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_PEM_BAR_E_PEMX_PF_BAR0(a) (0x87e0c0000000ll + 0x1000000ll * (a))
#define BDK_PEM_BAR_E_PEMX_PF_BAR4(a) (0x87e0c0f00000ll + 0x1000000ll * (a))

/**
 * Enumeration pem_int_vec_e
 *
 * PEM MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_PEM_INT_VEC_E_DBG_INFO_CN9 (0xb)
#define BDK_PEM_INT_VEC_E_DBG_INFO_CN81XX (0xb)
#define BDK_PEM_INT_VEC_E_DBG_INFO_CN88XX (0xd)
#define BDK_PEM_INT_VEC_E_DBG_INFO_CN83XX (0xb)
#define BDK_PEM_INT_VEC_E_ERROR_AERI (0)
#define BDK_PEM_INT_VEC_E_ERROR_AERI_CLEAR (1)
#define BDK_PEM_INT_VEC_E_ERROR_PMEI (2)
#define BDK_PEM_INT_VEC_E_ERROR_PMEI_CLEAR (3)
#define BDK_PEM_INT_VEC_E_HP_INT (0xe)
#define BDK_PEM_INT_VEC_E_HP_INT_CLEAR (0xf)
#define BDK_PEM_INT_VEC_E_HP_PMEI (1)
#define BDK_PEM_INT_VEC_E_INTA_CN9 (2)
#define BDK_PEM_INT_VEC_E_INTA_CN81XX (2)
#define BDK_PEM_INT_VEC_E_INTA_CN88XX (4)
#define BDK_PEM_INT_VEC_E_INTA_CN83XX (2)
#define BDK_PEM_INT_VEC_E_INTA_CLEAR_CN9 (3)
#define BDK_PEM_INT_VEC_E_INTA_CLEAR_CN81XX (3)
#define BDK_PEM_INT_VEC_E_INTA_CLEAR_CN88XX (5)
#define BDK_PEM_INT_VEC_E_INTA_CLEAR_CN83XX (3)
#define BDK_PEM_INT_VEC_E_INTB_CN9 (4)
#define BDK_PEM_INT_VEC_E_INTB_CN81XX (4)
#define BDK_PEM_INT_VEC_E_INTB_CN88XX (6)
#define BDK_PEM_INT_VEC_E_INTB_CN83XX (4)
#define BDK_PEM_INT_VEC_E_INTB_CLEAR_CN9 (5)
#define BDK_PEM_INT_VEC_E_INTB_CLEAR_CN81XX (5)
#define BDK_PEM_INT_VEC_E_INTB_CLEAR_CN88XX (7)
#define BDK_PEM_INT_VEC_E_INTB_CLEAR_CN83XX (5)
#define BDK_PEM_INT_VEC_E_INTC_CN9 (6)
#define BDK_PEM_INT_VEC_E_INTC_CN81XX (6)
#define BDK_PEM_INT_VEC_E_INTC_CN88XX (8)
#define BDK_PEM_INT_VEC_E_INTC_CN83XX (6)
#define BDK_PEM_INT_VEC_E_INTC_CLEAR_CN9 (7)
#define BDK_PEM_INT_VEC_E_INTC_CLEAR_CN81XX (7)
#define BDK_PEM_INT_VEC_E_INTC_CLEAR_CN88XX (9)
#define BDK_PEM_INT_VEC_E_INTC_CLEAR_CN83XX (7)
#define BDK_PEM_INT_VEC_E_INTD_CN9 (8)
#define BDK_PEM_INT_VEC_E_INTD_CN81XX (8)
#define BDK_PEM_INT_VEC_E_INTD_CN88XX (0xa)
#define BDK_PEM_INT_VEC_E_INTD_CN83XX (8)
#define BDK_PEM_INT_VEC_E_INTD_CLEAR_CN9 (9)
#define BDK_PEM_INT_VEC_E_INTD_CLEAR_CN81XX (9)
#define BDK_PEM_INT_VEC_E_INTD_CLEAR_CN88XX (0xb)
#define BDK_PEM_INT_VEC_E_INTD_CLEAR_CN83XX (9)
#define BDK_PEM_INT_VEC_E_INT_SUM_CN9 (0xa)
#define BDK_PEM_INT_VEC_E_INT_SUM_CN81XX (0xa)
#define BDK_PEM_INT_VEC_E_INT_SUM_CN88XX (0xc)
#define BDK_PEM_INT_VEC_E_INT_SUM_CN83XX (0xa)

/**
 * Register (RSL) pem#_bar1_index#
 *
 * PEM BAR1 Index 0-15 Register
 * This register contains the address index and control bits for access to memory ranges of BAR1.
 * The index is built from supplied address [25:22].
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_bar1_indexx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t addr_idx              : 27; /**< [ 30:  4](R/W) Address index. Address bits [48:22] sent to L2C. */
        uint64_t ca                    : 1;  /**< [  3:  3](R/W) Cached. Set to 1 when access is not to be cached in L2. */
        uint64_t end_swp               : 2;  /**< [  2:  1](R/W) Endian-swap mode. */
        uint64_t addr_v                : 1;  /**< [  0:  0](R/W) Address valid. Set to 1 when the selected address range is valid. */
#else /* Word 0 - Little Endian */
        uint64_t addr_v                : 1;  /**< [  0:  0](R/W) Address valid. Set to 1 when the selected address range is valid. */
        uint64_t end_swp               : 2;  /**< [  2:  1](R/W) Endian-swap mode. */
        uint64_t ca                    : 1;  /**< [  3:  3](R/W) Cached. Set to 1 when access is not to be cached in L2. */
        uint64_t addr_idx              : 27; /**< [ 30:  4](R/W) Address index. Address bits [48:22] sent to L2C. */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_bar1_indexx_s cn9; */
    struct bdk_pemx_bar1_indexx_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t addr_idx              : 27; /**< [ 30:  4](R/W) Address index. Address bits [48:22] sent to L2C. */
        uint64_t ca                    : 1;  /**< [  3:  3](R/W) Cached. Set to 1 when access is not to be cached in L2. */
        uint64_t reserved_1_2          : 2;
        uint64_t addr_v                : 1;  /**< [  0:  0](R/W) Address valid. Set to 1 when the selected address range is valid. */
#else /* Word 0 - Little Endian */
        uint64_t addr_v                : 1;  /**< [  0:  0](R/W) Address valid. Set to 1 when the selected address range is valid. */
        uint64_t reserved_1_2          : 2;
        uint64_t ca                    : 1;  /**< [  3:  3](R/W) Cached. Set to 1 when access is not to be cached in L2. */
        uint64_t addr_idx              : 27; /**< [ 30:  4](R/W) Address index. Address bits [48:22] sent to L2C. */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_bar1_indexx_cn81xx cn88xx; */
    /* struct bdk_pemx_bar1_indexx_s cn83xx; */
} bdk_pemx_bar1_indexx_t;

static inline uint64_t BDK_PEMX_BAR1_INDEXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR1_INDEXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=2) && (b<=15)))
        return 0x87e0c0000100ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=15)))
        return 0x87e0c0000100ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=5) && (b<=15)))
        return 0x87e0c0000100ll + 0x1000000ll * ((a) & 0x7) + 8ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=15)))
        return 0x87e0c0000100ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xf);
    __bdk_csr_fatal("PEMX_BAR1_INDEXX", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_BAR1_INDEXX(a,b) bdk_pemx_bar1_indexx_t
#define bustype_BDK_PEMX_BAR1_INDEXX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BAR1_INDEXX(a,b) "PEMX_BAR1_INDEXX"
#define device_bar_BDK_PEMX_BAR1_INDEXX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_BAR1_INDEXX(a,b) (a)
#define arguments_BDK_PEMX_BAR1_INDEXX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_bar2_mask
 *
 * PEM BAR2 Mask Register
 * This register contains the mask pattern that is ANDed with the address from the PCIe core for
 * BAR2 hits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_bar2_mask_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t mask                  : 45; /**< [ 48:  4](R/W) The value to be ANDed with the address sent to memory (to IOB). */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t mask                  : 45; /**< [ 48:  4](R/W) The value to be ANDed with the address sent to memory (to IOB). */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_bar2_mask_s cn9; */
    struct bdk_pemx_bar2_mask_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t mask                  : 45; /**< [ 48:  4](R/W) The value to be ANDED with the address sent to memory. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t mask                  : 45; /**< [ 48:  4](R/W) The value to be ANDED with the address sent to memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_bar2_mask_cn81xx cn88xx; */
    /* struct bdk_pemx_bar2_mask_s cn83xx; */
} bdk_pemx_bar2_mask_t;

static inline uint64_t BDK_PEMX_BAR2_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR2_MASK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c00000b0ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c00000b0ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c00000b0ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c00000b0ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_BAR2_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_BAR2_MASK(a) bdk_pemx_bar2_mask_t
#define bustype_BDK_PEMX_BAR2_MASK(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BAR2_MASK(a) "PEMX_BAR2_MASK"
#define device_bar_BDK_PEMX_BAR2_MASK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_BAR2_MASK(a) (a)
#define arguments_BDK_PEMX_BAR2_MASK(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_bar_ctl
 *
 * PEM BAR Control Register
 * This register contains control for BAR accesses.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_bar_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t bar2_ebit             : 6;  /**< [ 24: 19](R/W) Address bits to be mapped to BAR2's ESX<1:0>. The value of this register
                                                                 signifies the address bit that maps to BAR2's ESX<0>. The value of this register
                                                                 plus 1, signifies the address bit that maps to BAR2's ESX<1>. When 0x0, BAR2's
                                                                 CAX is disabled; otherwise must be 16 to 62 inclusive. */
        uint64_t bar2_cbit             : 6;  /**< [ 18: 13](R/W) Address bit to be mapped to BAR2's CAX. When 0x0, BAR2's CAX is disabled;
                                                                 otherwise must be 16 to 63 inclusive. */
        uint64_t bar2_siz              : 6;  /**< [ 12:  7](R/W) BAR2 size. Encoded similar to PCIEEP()_CFG190[RBARS]. Used in RC mode to create
                                                                 a mask that is ANDED with the address prior to applying [BAR2_ESX] and
                                                                 [BAR2_CAX]. Defaults to 0x1D (512 TB). */
        uint64_t bar1_siz              : 3;  /**< [  6:  4](R/W) PCIe Port 0 BAR1 size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB; 2^26.
                                                                 0x2 = 128 MB; 2^27.
                                                                 0x3 = 256 MB; 2^28.
                                                                 0x4 = 512 MB; 2^29.
                                                                 0x5 = 1024 MB; 2^30.
                                                                 0x6 = 2048 MB; 2^31.
                                                                 0x7 = Reserved. */
        uint64_t bar2_enb              : 1;  /**< [  3:  3](R/W) When set to 1, BAR2 is enabled and will respond; when clear, BAR2 access will cause UR responses. */
        uint64_t bar2_esx              : 2;  /**< [  2:  1](R/W) Value is XORed with PCIe addresses as defined by [BAR2_CBIT] to determine the
                                                                 endian swap mode. */
        uint64_t bar2_cax              : 1;  /**< [  0:  0](R/W) Value is XORed with PCIe address as defined by [BAR2_CBIT] to determine the L2
                                                                 cache attribute. Not cached in L2 if XOR result is 1. */
#else /* Word 0 - Little Endian */
        uint64_t bar2_cax              : 1;  /**< [  0:  0](R/W) Value is XORed with PCIe address as defined by [BAR2_CBIT] to determine the L2
                                                                 cache attribute. Not cached in L2 if XOR result is 1. */
        uint64_t bar2_esx              : 2;  /**< [  2:  1](R/W) Value is XORed with PCIe addresses as defined by [BAR2_CBIT] to determine the
                                                                 endian swap mode. */
        uint64_t bar2_enb              : 1;  /**< [  3:  3](R/W) When set to 1, BAR2 is enabled and will respond; when clear, BAR2 access will cause UR responses. */
        uint64_t bar1_siz              : 3;  /**< [  6:  4](R/W) PCIe Port 0 BAR1 size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB; 2^26.
                                                                 0x2 = 128 MB; 2^27.
                                                                 0x3 = 256 MB; 2^28.
                                                                 0x4 = 512 MB; 2^29.
                                                                 0x5 = 1024 MB; 2^30.
                                                                 0x6 = 2048 MB; 2^31.
                                                                 0x7 = Reserved. */
        uint64_t bar2_siz              : 6;  /**< [ 12:  7](R/W) BAR2 size. Encoded similar to PCIEEP()_CFG190[RBARS]. Used in RC mode to create
                                                                 a mask that is ANDED with the address prior to applying [BAR2_ESX] and
                                                                 [BAR2_CAX]. Defaults to 0x1D (512 TB). */
        uint64_t bar2_cbit             : 6;  /**< [ 18: 13](R/W) Address bit to be mapped to BAR2's CAX. When 0x0, BAR2's CAX is disabled;
                                                                 otherwise must be 16 to 63 inclusive. */
        uint64_t bar2_ebit             : 6;  /**< [ 24: 19](R/W) Address bits to be mapped to BAR2's ESX<1:0>. The value of this register
                                                                 signifies the address bit that maps to BAR2's ESX<0>. The value of this register
                                                                 plus 1, signifies the address bit that maps to BAR2's ESX<1>. When 0x0, BAR2's
                                                                 CAX is disabled; otherwise must be 16 to 62 inclusive. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_bar_ctl_s cn9; */
    struct bdk_pemx_bar_ctl_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t bar1_siz              : 3;  /**< [  6:  4](R/W) PCIe Port 0 BAR1 size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB; 2^26.
                                                                 0x2 = 128 MB; 2^27.
                                                                 0x3 = 256 MB; 2^28.
                                                                 0x4 = 512 MB; 2^29.
                                                                 0x5 = 1024 MB; 2^30.
                                                                 0x6 = 2048 MB; 2^31.
                                                                 0x7 = Reserved. */
        uint64_t bar2_enb              : 1;  /**< [  3:  3](R/W) When set to 1, BAR2 is enabled and will respond; when clear, BAR2 access will cause UR responses. */
        uint64_t reserved_1_2          : 2;
        uint64_t bar2_cax              : 1;  /**< [  0:  0](R/W) Value is XORed with PCIe address <49> to determine the L2 cache attribute. Not cached in
                                                                 L2 if XOR result is 1. */
#else /* Word 0 - Little Endian */
        uint64_t bar2_cax              : 1;  /**< [  0:  0](R/W) Value is XORed with PCIe address <49> to determine the L2 cache attribute. Not cached in
                                                                 L2 if XOR result is 1. */
        uint64_t reserved_1_2          : 2;
        uint64_t bar2_enb              : 1;  /**< [  3:  3](R/W) When set to 1, BAR2 is enabled and will respond; when clear, BAR2 access will cause UR responses. */
        uint64_t bar1_siz              : 3;  /**< [  6:  4](R/W) PCIe Port 0 BAR1 size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB; 2^26.
                                                                 0x2 = 128 MB; 2^27.
                                                                 0x3 = 256 MB; 2^28.
                                                                 0x4 = 512 MB; 2^29.
                                                                 0x5 = 1024 MB; 2^30.
                                                                 0x6 = 2048 MB; 2^31.
                                                                 0x7 = Reserved. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_bar_ctl_cn81xx cn88xx; */
    /* struct bdk_pemx_bar_ctl_s cn83xx; */
} bdk_pemx_bar_ctl_t;

static inline uint64_t BDK_PEMX_BAR_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c00000a8ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c00000a8ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c00000a8ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c00000a8ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_BAR_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_BAR_CTL(a) bdk_pemx_bar_ctl_t
#define bustype_BDK_PEMX_BAR_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BAR_CTL(a) "PEMX_BAR_CTL"
#define device_bar_BDK_PEMX_BAR_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_BAR_CTL(a) (a)
#define arguments_BDK_PEMX_BAR_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_bist_status
 *
 * PEM BIST Status Register
 * This register contains results from BIST runs of PEM's memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t tlpan_d0              : 1;  /**< [ 19: 19](RO) BIST Status for the tlp_n_afifo_data0. */
        uint64_t tlpan_d1              : 1;  /**< [ 18: 18](RO) BIST Status for the tlp_n_afifo_data1. */
        uint64_t tlpan_ctl             : 1;  /**< [ 17: 17](RO) BIST Status for the tlp_n_afifo_ctl. */
        uint64_t tlpap_d0              : 1;  /**< [ 16: 16](RO) BIST Status for the tlp_p_afifo_data0. */
        uint64_t reserved_10_15        : 6;
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
#else /* Word 0 - Little Endian */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t reserved_10_15        : 6;
        uint64_t tlpap_d0              : 1;  /**< [ 16: 16](RO) BIST Status for the tlp_p_afifo_data0. */
        uint64_t tlpan_ctl             : 1;  /**< [ 17: 17](RO) BIST Status for the tlp_n_afifo_ctl. */
        uint64_t tlpan_d1              : 1;  /**< [ 18: 18](RO) BIST Status for the tlp_n_afifo_data1. */
        uint64_t tlpan_d0              : 1;  /**< [ 19: 19](RO) BIST Status for the tlp_n_afifo_data0. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_bist_status_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) RX queue header memory buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) RX queue header memory buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) RX queue data buffer 0. */
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) RX queue data buffer 1. */
        uint64_t tlpan_d0              : 1;  /**< [ 19: 19](RO) BIST Status for the tlp_n_afifo_data0. */
        uint64_t tlpan_d1              : 1;  /**< [ 18: 18](RO) BIST Status for the tlp_n_afifo_data1. */
        uint64_t tlpan_ctl             : 1;  /**< [ 17: 17](RO) BIST Status for the tlp_n_afifo_ctl. */
        uint64_t tlpap_d0              : 1;  /**< [ 16: 16](RO) BIST Status for the tlp_p_afifo_data0. */
        uint64_t tlpap_d1              : 1;  /**< [ 15: 15](RO) BIST Status for the tlp_p_afifo_data1. */
        uint64_t tlpap_ctl             : 1;  /**< [ 14: 14](RO) BIST Status for the tlp_p_afifo_ctl. */
        uint64_t tlpac_d0              : 1;  /**< [ 13: 13](RO) BIST Status for the tlp_c_afifo_data0. */
        uint64_t tlpac_d1              : 1;  /**< [ 12: 12](RO) BIST Status for the tlp_c_afifo_data1. */
        uint64_t tlpac_ctl             : 1;  /**< [ 11: 11](RO) BIST Status for the tlp_c_afifo_ctl. */
        uint64_t peai_p2e              : 1;  /**< [ 10: 10](RO) BIST Status for the peai__pesc_fifo. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
#else /* Word 0 - Little Endian */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t peai_p2e              : 1;  /**< [ 10: 10](RO) BIST Status for the peai__pesc_fifo. */
        uint64_t tlpac_ctl             : 1;  /**< [ 11: 11](RO) BIST Status for the tlp_c_afifo_ctl. */
        uint64_t tlpac_d1              : 1;  /**< [ 12: 12](RO) BIST Status for the tlp_c_afifo_data1. */
        uint64_t tlpac_d0              : 1;  /**< [ 13: 13](RO) BIST Status for the tlp_c_afifo_data0. */
        uint64_t tlpap_ctl             : 1;  /**< [ 14: 14](RO) BIST Status for the tlp_p_afifo_ctl. */
        uint64_t tlpap_d1              : 1;  /**< [ 15: 15](RO) BIST Status for the tlp_p_afifo_data1. */
        uint64_t tlpap_d0              : 1;  /**< [ 16: 16](RO) BIST Status for the tlp_p_afifo_data0. */
        uint64_t tlpan_ctl             : 1;  /**< [ 17: 17](RO) BIST Status for the tlp_n_afifo_ctl. */
        uint64_t tlpan_d1              : 1;  /**< [ 18: 18](RO) BIST Status for the tlp_n_afifo_data1. */
        uint64_t tlpan_d0              : 1;  /**< [ 19: 19](RO) BIST Status for the tlp_n_afifo_data0. */
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) RX queue data buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) RX queue data buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) RX queue header memory buffer 1. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) RX queue header memory buffer 0. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_bist_status_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t retryc                : 1;  /**< [ 15: 15](RO) Retry buffer memory C. */
        uint64_t sot                   : 1;  /**< [ 14: 14](RO) Start of transfer memory. */
        uint64_t rqhdrb0               : 1;  /**< [ 13: 13](RO) RX queue header memory buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 12: 12](RO) RX queue header memory buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 11: 11](RO) RX queue data buffer 0. */
        uint64_t rqdatab1              : 1;  /**< [ 10: 10](RO) RX queue data buffer 1. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
#else /* Word 0 - Little Endian */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t rqdatab1              : 1;  /**< [ 10: 10](RO) RX queue data buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 11: 11](RO) RX queue data buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 12: 12](RO) RX queue header memory buffer 1. */
        uint64_t rqhdrb0               : 1;  /**< [ 13: 13](RO) RX queue header memory buffer 0. */
        uint64_t sot                   : 1;  /**< [ 14: 14](RO) Start of transfer memory. */
        uint64_t retryc                : 1;  /**< [ 15: 15](RO) Retry buffer memory C. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_bist_status_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) RX queue header memory buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) RX queue header memory buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) RX queue data buffer 0. */
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) RX queue data buffer 1. */
        uint64_t tlpan_d0              : 1;  /**< [ 19: 19](RO) Reserved. */
        uint64_t tlpan_d1              : 1;  /**< [ 18: 18](RO) Reserved. */
        uint64_t tlpan_ctl             : 1;  /**< [ 17: 17](RO) Reserved. */
        uint64_t tlpap_d0              : 1;  /**< [ 16: 16](RO) Reserved. */
        uint64_t tlpap_d1              : 1;  /**< [ 15: 15](RO) Reserved. */
        uint64_t tlpap_ctl             : 1;  /**< [ 14: 14](RO) Reserved. */
        uint64_t tlpac_d0              : 1;  /**< [ 13: 13](RO) Reserved. */
        uint64_t tlpac_d1              : 1;  /**< [ 12: 12](RO) Reserved. */
        uint64_t tlpac_ctl             : 1;  /**< [ 11: 11](RO) Reserved. */
        uint64_t peai_p2e              : 1;  /**< [ 10: 10](RO) Reserved. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
#else /* Word 0 - Little Endian */
        uint64_t m2s                   : 1;  /**< [  0:  0](RO) BIST status for m2s_fifo. */
        uint64_t tlpc_ctl              : 1;  /**< [  1:  1](RO) BIST status for tlp_c_fifo_ctl. */
        uint64_t tlpc_d1               : 1;  /**< [  2:  2](RO) BIST status for tlp_c_fifo_data1. */
        uint64_t tlpc_d0               : 1;  /**< [  3:  3](RO) BIST status for tlp_c_fifo_data0. */
        uint64_t tlpp_ctl              : 1;  /**< [  4:  4](RO) BIST status for tlp_p_fifo_ctl. */
        uint64_t tlpp_d1               : 1;  /**< [  5:  5](RO) BIST status for tlp_p_fifo_data1. */
        uint64_t tlpp_d0               : 1;  /**< [  6:  6](RO) BIST status for tlp_p_fifo_data0. */
        uint64_t tlpn_ctl              : 1;  /**< [  7:  7](RO) BIST status for tlp_n_fifo_ctl. */
        uint64_t tlpn_d1               : 1;  /**< [  8:  8](RO) BIST status for tlp_n_fifo_data1. */
        uint64_t tlpn_d0               : 1;  /**< [  9:  9](RO) BIST status for tlp_n_fifo_data0. */
        uint64_t peai_p2e              : 1;  /**< [ 10: 10](RO) Reserved. */
        uint64_t tlpac_ctl             : 1;  /**< [ 11: 11](RO) Reserved. */
        uint64_t tlpac_d1              : 1;  /**< [ 12: 12](RO) Reserved. */
        uint64_t tlpac_d0              : 1;  /**< [ 13: 13](RO) Reserved. */
        uint64_t tlpap_ctl             : 1;  /**< [ 14: 14](RO) Reserved. */
        uint64_t tlpap_d1              : 1;  /**< [ 15: 15](RO) Reserved. */
        uint64_t tlpap_d0              : 1;  /**< [ 16: 16](RO) Reserved. */
        uint64_t tlpan_ctl             : 1;  /**< [ 17: 17](RO) Reserved. */
        uint64_t tlpan_d1              : 1;  /**< [ 18: 18](RO) Reserved. */
        uint64_t tlpan_d0              : 1;  /**< [ 19: 19](RO) Reserved. */
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) RX queue data buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) RX queue data buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) RX queue header memory buffer 1. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) RX queue header memory buffer 0. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_bist_status_cn9 cn83xx; */
    /* struct bdk_pemx_bist_status_cn81xx cn88xxp2; */
} bdk_pemx_bist_status_t;

static inline uint64_t BDK_PEMX_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000468ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000468ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000468ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000468ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_BIST_STATUS(a) bdk_pemx_bist_status_t
#define bustype_BDK_PEMX_BIST_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BIST_STATUS(a) "PEMX_BIST_STATUS"
#define device_bar_BDK_PEMX_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_BIST_STATUS(a) (a)
#define arguments_BDK_PEMX_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_cfg
 *
 * PEM Application Configuration Register
 * Configuration of the PCIe Application.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t lanes4                : 1;  /**< [  5:  5](R/W) Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 4 lanes. When clear, the PEM is
                                                                 configured for a maximum of 2 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W/H) Enables overwriting the value for lane swapping. The reset value is captured on
                                                                 cold reset by the pin straps (see PEM()_STRAP[PILANESWAP]). When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t lanes8                : 1;  /**< [  3:  3](R/W/H) Enables overwriting the value for the maximum number of lanes. The reset value
                                                                 is captured on cold reset by the pin straps (see PEM()_STRAP[PILANES8]). When set, the
                                                                 PEM is configured for a maximum of 8 lanes. When clear, the PEM is configured for a
                                                                 maximum of 4 lanes. This value is used to set the maximum link width field in the core's
                                                                 link capabilities register (CFG031) to indicate the maximum number of lanes
                                                                 supported. Note that less lanes than the specified maximum can be configured for use via
                                                                 the core's link control register (CFG032) negotiated link width field. */
        uint64_t hostmd                : 1;  /**< [  2:  2](R/W/H) Enables overwriting the value for host mode. The reset value is captured on
                                                                 cold reset by the pin straps. (See PEM()_STRAP[PIMODE]. The HOSTMD reset value is the
                                                                 bit-wise AND of the PIMODE straps.  When set, the PEM is configured to be a root complex.
                                                                 When clear, the PEM is configured to be an end point. */
        uint64_t md                    : 2;  /**< [  1:  0](R/W/H) Enables overwriting the value for speed. The reset value is captured on cold
                                                                 reset by the pin straps (see PEM()_STRAP[PIMODE]). For a root complex configuration
                                                                 that is not running at Gen3 speed, the HOSTMD bit of this register must be set when this
                                                                 field is changed.
                                                                 0x0 = Gen1 speed.
                                                                 0x1 = Gen2 speed.
                                                                 0x2 = Gen3 speed.
                                                                 0x3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t md                    : 2;  /**< [  1:  0](R/W/H) Enables overwriting the value for speed. The reset value is captured on cold
                                                                 reset by the pin straps (see PEM()_STRAP[PIMODE]). For a root complex configuration
                                                                 that is not running at Gen3 speed, the HOSTMD bit of this register must be set when this
                                                                 field is changed.
                                                                 0x0 = Gen1 speed.
                                                                 0x1 = Gen2 speed.
                                                                 0x2 = Gen3 speed.
                                                                 0x3 = Reserved. */
        uint64_t hostmd                : 1;  /**< [  2:  2](R/W/H) Enables overwriting the value for host mode. The reset value is captured on
                                                                 cold reset by the pin straps. (See PEM()_STRAP[PIMODE]. The HOSTMD reset value is the
                                                                 bit-wise AND of the PIMODE straps.  When set, the PEM is configured to be a root complex.
                                                                 When clear, the PEM is configured to be an end point. */
        uint64_t lanes8                : 1;  /**< [  3:  3](R/W/H) Enables overwriting the value for the maximum number of lanes. The reset value
                                                                 is captured on cold reset by the pin straps (see PEM()_STRAP[PILANES8]). When set, the
                                                                 PEM is configured for a maximum of 8 lanes. When clear, the PEM is configured for a
                                                                 maximum of 4 lanes. This value is used to set the maximum link width field in the core's
                                                                 link capabilities register (CFG031) to indicate the maximum number of lanes
                                                                 supported. Note that less lanes than the specified maximum can be configured for use via
                                                                 the core's link control register (CFG032) negotiated link width field. */
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W/H) Enables overwriting the value for lane swapping. The reset value is captured on
                                                                 cold reset by the pin straps (see PEM()_STRAP[PILANESWAP]). When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t lanes4                : 1;  /**< [  5:  5](R/W) Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 4 lanes. When clear, the PEM is
                                                                 configured for a maximum of 2 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_cfg_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W/H) Enables overwriting the value for lane swapping. The reset value is captured on
                                                                 cold reset by the pin straps (see PEM()_STRAP[PILANESWAP]). When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t lanes8                : 1;  /**< [  3:  3](R/W/H) Enables overwriting the value for the maximum number of lanes. The reset value
                                                                 is captured on cold reset by the pin straps (see PEM()_STRAP[PILANES8]). When set, the
                                                                 PEM is configured for a maximum of 8 lanes. When clear, the PEM is configured for a
                                                                 maximum of 4 lanes. This value is used to set the maximum link width field in the core's
                                                                 link capabilities register (CFG031) to indicate the maximum number of lanes
                                                                 supported. Note that less lanes than the specified maximum can be configured for use via
                                                                 the core's link control register (CFG032) negotiated link width field. */
        uint64_t hostmd                : 1;  /**< [  2:  2](R/W/H) Enables overwriting the value for host mode. The reset value is captured on
                                                                 cold reset by the pin straps. (See PEM()_STRAP[PIMODE]. The HOSTMD reset value is the
                                                                 bit-wise AND of the PIMODE straps.  When set, the PEM is configured to be a root complex.
                                                                 When clear, the PEM is configured to be an end point. */
        uint64_t md                    : 2;  /**< [  1:  0](R/W/H) Enables overwriting the value for speed. The reset value is captured on cold
                                                                 reset by the pin straps (see PEM()_STRAP[PIMODE]). For a root complex configuration
                                                                 that is not running at Gen3 speed, the HOSTMD bit of this register must be set when this
                                                                 field is changed.
                                                                 0x0 = Gen1 speed.
                                                                 0x1 = Gen2 speed.
                                                                 0x2 = Gen3 speed.
                                                                 0x3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t md                    : 2;  /**< [  1:  0](R/W/H) Enables overwriting the value for speed. The reset value is captured on cold
                                                                 reset by the pin straps (see PEM()_STRAP[PIMODE]). For a root complex configuration
                                                                 that is not running at Gen3 speed, the HOSTMD bit of this register must be set when this
                                                                 field is changed.
                                                                 0x0 = Gen1 speed.
                                                                 0x1 = Gen2 speed.
                                                                 0x2 = Gen3 speed.
                                                                 0x3 = Reserved. */
        uint64_t hostmd                : 1;  /**< [  2:  2](R/W/H) Enables overwriting the value for host mode. The reset value is captured on
                                                                 cold reset by the pin straps. (See PEM()_STRAP[PIMODE]. The HOSTMD reset value is the
                                                                 bit-wise AND of the PIMODE straps.  When set, the PEM is configured to be a root complex.
                                                                 When clear, the PEM is configured to be an end point. */
        uint64_t lanes8                : 1;  /**< [  3:  3](R/W/H) Enables overwriting the value for the maximum number of lanes. The reset value
                                                                 is captured on cold reset by the pin straps (see PEM()_STRAP[PILANES8]). When set, the
                                                                 PEM is configured for a maximum of 8 lanes. When clear, the PEM is configured for a
                                                                 maximum of 4 lanes. This value is used to set the maximum link width field in the core's
                                                                 link capabilities register (CFG031) to indicate the maximum number of lanes
                                                                 supported. Note that less lanes than the specified maximum can be configured for use via
                                                                 the core's link control register (CFG032) negotiated link width field. */
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W/H) Enables overwriting the value for lane swapping. The reset value is captured on
                                                                 cold reset by the pin straps (see PEM()_STRAP[PILANESWAP]). When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_cfg_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t lanes4                : 1;  /**< [  5:  5](R/W) Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 4 lanes. When clear, the PEM is
                                                                 configured for a maximum of 2 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W) Determines lane swapping. When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t reserved_2_3          : 2;
        uint64_t md                    : 2;  /**< [  1:  0](R/W) Determines the speed.
                                                                   0x0 = Gen1 speed.
                                                                   0x1 = Gen2 speed.
                                                                   0x2 = Gen3 speed.
                                                                   0x3 = Gen3 speed. */
#else /* Word 0 - Little Endian */
        uint64_t md                    : 2;  /**< [  1:  0](R/W) Determines the speed.
                                                                   0x0 = Gen1 speed.
                                                                   0x1 = Gen2 speed.
                                                                   0x2 = Gen3 speed.
                                                                   0x3 = Gen3 speed. */
        uint64_t reserved_2_3          : 2;
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W) Determines lane swapping. When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t lanes4                : 1;  /**< [  5:  5](R/W) Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 4 lanes. When clear, the PEM is
                                                                 configured for a maximum of 2 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_pemx_cfg_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W/H) Determines lane swapping. When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t lanes8                : 1;  /**< [  3:  3](R/W/H) Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 8 lanes. When clear, the PEM is
                                                                 configured for a maximum of 4 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
        uint64_t reserved_2            : 1;
        uint64_t md                    : 2;  /**< [  1:  0](R/W/H) Determines the speed.
                                                                   0x0 = Gen1 speed.
                                                                   0x1 = Gen2 speed.
                                                                   0x2 = Gen3 speed.
                                                                   0x3 = Gen3 speed. */
#else /* Word 0 - Little Endian */
        uint64_t md                    : 2;  /**< [  1:  0](R/W/H) Determines the speed.
                                                                   0x0 = Gen1 speed.
                                                                   0x1 = Gen2 speed.
                                                                   0x2 = Gen3 speed.
                                                                   0x3 = Gen3 speed. */
        uint64_t reserved_2            : 1;
        uint64_t lanes8                : 1;  /**< [  3:  3](R/W/H) Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 8 lanes. When clear, the PEM is
                                                                 configured for a maximum of 4 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
        uint64_t laneswap              : 1;  /**< [  4:  4](R/W/H) Determines lane swapping. When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_pemx_cfg_cn9 cn83xx; */
} bdk_pemx_cfg_t;

static inline uint64_t BDK_PEMX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000410ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000410ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000410ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000410ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CFG(a) bdk_pemx_cfg_t
#define bustype_BDK_PEMX_CFG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CFG(a) "PEMX_CFG"
#define device_bar_BDK_PEMX_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CFG(a) (a)
#define arguments_BDK_PEMX_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_cfg_rd
 *
 * PEM Configuration Read Register
 * This register allows read access to the configuration in the PCIe core.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_cfg_rd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data. */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W) Address to read. A write to this register starts a read operation.
                                                                 Following are the subfields of the ADDR field.

                                                                 <31:24> = Reserved. Must be zero.

                                                                 <23>    = When clear, the read accesses the physical function. When set,
                                                                         the read accesses the virtual function selected by <22:12>.
                                                                         Must be zero when SR-IOV is not used in the physical function.
                                                                         Must be zero in RC mode.

                                                                 <22:18> = Reserved. Must be zero.

                                                                 <17:12> = The selected virtual function. Must be zero when <23> is
                                                                         clear. Must be zero in RC mode.

                                                                 <11:0>  = Selects the PCIe config space register being read in the
                                                                         function.

                                                                 Internal:
                                                                 <31>    = asserts dbi_cs2 at PCIe core.
                                                                   <23>    = dbi_vfunc_active to the core.
                                                                   <22:12> = dbi_vfunc_num to the core. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W) Address to read. A write to this register starts a read operation.
                                                                 Following are the subfields of the ADDR field.

                                                                 <31:24> = Reserved. Must be zero.

                                                                 <23>    = When clear, the read accesses the physical function. When set,
                                                                         the read accesses the virtual function selected by <22:12>.
                                                                         Must be zero when SR-IOV is not used in the physical function.
                                                                         Must be zero in RC mode.

                                                                 <22:18> = Reserved. Must be zero.

                                                                 <17:12> = The selected virtual function. Must be zero when <23> is
                                                                         clear. Must be zero in RC mode.

                                                                 <11:0>  = Selects the PCIe config space register being read in the
                                                                         function.

                                                                 Internal:
                                                                 <31>    = asserts dbi_cs2 at PCIe core.
                                                                   <23>    = dbi_vfunc_active to the core.
                                                                   <22:12> = dbi_vfunc_num to the core. */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_cfg_rd_s cn9; */
    struct bdk_pemx_cfg_rd_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data. */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W/H) Address to read. A write to this register starts a read operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 <11:0> The offset of the PCIe core CFG register being accessed. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W/H) Address to read. A write to this register starts a read operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 <11:0> The offset of the PCIe core CFG register being accessed. */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_cfg_rd_cn81xx cn88xx; */
    /* struct bdk_pemx_cfg_rd_s cn83xx; */
} bdk_pemx_cfg_rd_t;

static inline uint64_t BDK_PEMX_CFG_RD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG_RD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000030ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000030ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000030ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000030ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CFG_RD", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CFG_RD(a) bdk_pemx_cfg_rd_t
#define bustype_BDK_PEMX_CFG_RD(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CFG_RD(a) "PEMX_CFG_RD"
#define device_bar_BDK_PEMX_CFG_RD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CFG_RD(a) (a)
#define arguments_BDK_PEMX_CFG_RD(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_cfg_wr
 *
 * PEM Configuration Write Register
 * This register allows write access to the configuration in the PCIe core.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_cfg_wr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 32; /**< [ 63: 32](R/W) Data to write. A write to this register starts a write operation. */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W) Address to write. A write to this register starts a write operation.
                                                                 Following are the subfields of the ADDR field.

                                                                 <31>    = When clear, the write is the same as a config space write received
                                                                         from external. When set, the write can modify more fields than
                                                                         an external write could (i.e. configuration mask register).

                                                                         Corresponds to the CS2 field in Byte2 of the EEPROM.

                                                                 <30:24> = Reserved. Must be zero.

                                                                 <23>    = When clear, the write accesses the physical function. When set,
                                                                         the write accesses the virtual function selected by <22:12>.
                                                                         Must be zero when SR-IOV is not used in the physical function.
                                                                         Must be zero in RC mode.

                                                                 <22:18> = Reserved. Must be zero.

                                                                 <17:12> = The selected virtual function. Must be zero when <23> is
                                                                         clear. Must be zero in RC mode.

                                                                 <11:0>  = Selects the PCIe config space register being written in the
                                                                         function.

                                                                 Internal:
                                                                 <31>    = asserts dbi_cs2 at PCIe core.
                                                                   <23>    = dbi_vfunc_active to the core.
                                                                   <22:12> = dbi_vfunc_num to the core. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W) Address to write. A write to this register starts a write operation.
                                                                 Following are the subfields of the ADDR field.

                                                                 <31>    = When clear, the write is the same as a config space write received
                                                                         from external. When set, the write can modify more fields than
                                                                         an external write could (i.e. configuration mask register).

                                                                         Corresponds to the CS2 field in Byte2 of the EEPROM.

                                                                 <30:24> = Reserved. Must be zero.

                                                                 <23>    = When clear, the write accesses the physical function. When set,
                                                                         the write accesses the virtual function selected by <22:12>.
                                                                         Must be zero when SR-IOV is not used in the physical function.
                                                                         Must be zero in RC mode.

                                                                 <22:18> = Reserved. Must be zero.

                                                                 <17:12> = The selected virtual function. Must be zero when <23> is
                                                                         clear. Must be zero in RC mode.

                                                                 <11:0>  = Selects the PCIe config space register being written in the
                                                                         function.

                                                                 Internal:
                                                                 <31>    = asserts dbi_cs2 at PCIe core.
                                                                   <23>    = dbi_vfunc_active to the core.
                                                                   <22:12> = dbi_vfunc_num to the core. */
        uint64_t data                  : 32; /**< [ 63: 32](R/W) Data to write. A write to this register starts a write operation. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_cfg_wr_s cn9; */
    struct bdk_pemx_cfg_wr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data to write. A write to this register starts a write operation. */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W/H) Address to write. A write to this register starts a write operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 <31>   When set, asserts dbi_cs2 at PCIe core.
                                                                 <11:0> The offset of the PCIe core CFG register being accessed. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W/H) Address to write. A write to this register starts a write operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 <31>   When set, asserts dbi_cs2 at PCIe core.
                                                                 <11:0> The offset of the PCIe core CFG register being accessed. */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data to write. A write to this register starts a write operation. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_cfg_wr_cn81xx cn88xx; */
    /* struct bdk_pemx_cfg_wr_s cn83xx; */
} bdk_pemx_cfg_wr_t;

static inline uint64_t BDK_PEMX_CFG_WR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG_WR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000028ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000028ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000028ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000028ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CFG_WR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CFG_WR(a) bdk_pemx_cfg_wr_t
#define bustype_BDK_PEMX_CFG_WR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CFG_WR(a) "PEMX_CFG_WR"
#define device_bar_BDK_PEMX_CFG_WR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CFG_WR(a) (a)
#define arguments_BDK_PEMX_CFG_WR(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_clk_en
 *
 * PEM Clock Enable Register
 * This register contains the clock enable for CSCLK and PCE_CLK.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_clk_en_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t pceclk_gate           : 1;  /**< [  1:  1](R/W/H) When set, PCE_CLK is gated off. When clear, PCE_CLK is enabled.
                                                                 PEM0 & PEM2 will come up with clocks disabled when configured as
                                                                 an RC i.e. PEM()_STRAP[PIMODE] set to 0x3.
                                                                 PEM1 & PEM3 always come up with clocks disabled. */
        uint64_t csclk_gate            : 1;  /**< [  0:  0](R/W/H) When set, ECLK is gated off. When clear, ECLK is enabled.
                                                                 PEM0 & PEM2 will come up with clocks disabled when configured as
                                                                 an RC i.e. PEM()_STRAP[PIMODE] set to 0x3.
                                                                 PEM1 & PEM3 always come up with clocks disabled. */
#else /* Word 0 - Little Endian */
        uint64_t csclk_gate            : 1;  /**< [  0:  0](R/W/H) When set, ECLK is gated off. When clear, ECLK is enabled.
                                                                 PEM0 & PEM2 will come up with clocks disabled when configured as
                                                                 an RC i.e. PEM()_STRAP[PIMODE] set to 0x3.
                                                                 PEM1 & PEM3 always come up with clocks disabled. */
        uint64_t pceclk_gate           : 1;  /**< [  1:  1](R/W/H) When set, PCE_CLK is gated off. When clear, PCE_CLK is enabled.
                                                                 PEM0 & PEM2 will come up with clocks disabled when configured as
                                                                 an RC i.e. PEM()_STRAP[PIMODE] set to 0x3.
                                                                 PEM1 & PEM3 always come up with clocks disabled. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_clk_en_s cn9; */
    struct bdk_pemx_clk_en_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t pceclk_gate           : 1;  /**< [  1:  1](R/W/H) When set, PCE_CLK is gated off. When clear, PCE_CLK is enabled.
                                                                 Software should set this bit when the PEM is in reset or otherwise not
                                                                 being used in order to reduce power. */
        uint64_t csclk_gate            : 1;  /**< [  0:  0](R/W/H) When set, CSCLK is gated off. When clear, CSCLK is enabled.
                                                                 Software should set this bit when the PEM is in reset or otherwise not
                                                                 being used in order to reduce power. */
#else /* Word 0 - Little Endian */
        uint64_t csclk_gate            : 1;  /**< [  0:  0](R/W/H) When set, CSCLK is gated off. When clear, CSCLK is enabled.
                                                                 Software should set this bit when the PEM is in reset or otherwise not
                                                                 being used in order to reduce power. */
        uint64_t pceclk_gate           : 1;  /**< [  1:  1](R/W/H) When set, PCE_CLK is gated off. When clear, PCE_CLK is enabled.
                                                                 Software should set this bit when the PEM is in reset or otherwise not
                                                                 being used in order to reduce power. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_clk_en_cn81xx cn88xx; */
    /* struct bdk_pemx_clk_en_s cn83xx; */
} bdk_pemx_clk_en_t;

static inline uint64_t BDK_PEMX_CLK_EN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CLK_EN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000400ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000400ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000400ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000400ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CLK_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CLK_EN(a) bdk_pemx_clk_en_t
#define bustype_BDK_PEMX_CLK_EN(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CLK_EN(a) "PEMX_CLK_EN"
#define device_bar_BDK_PEMX_CLK_EN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CLK_EN(a) (a)
#define arguments_BDK_PEMX_CLK_EN(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_cpl_lut_valid
 *
 * PEM Completion Lookup Table Valid Register
 * This register specifies the bit set for an outstanding tag read.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_cpl_lut_valid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tag                   : 64; /**< [ 63:  0](RO/H) Bit vector set corresponds to an outstanding tag. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 64; /**< [ 63:  0](RO/H) Bit vector set corresponds to an outstanding tag. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_cpl_lut_valid_s cn; */
} bdk_pemx_cpl_lut_valid_t;

static inline uint64_t BDK_PEMX_CPL_LUT_VALID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CPL_LUT_VALID(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000098ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000098ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000098ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000098ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CPL_LUT_VALID", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CPL_LUT_VALID(a) bdk_pemx_cpl_lut_valid_t
#define bustype_BDK_PEMX_CPL_LUT_VALID(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CPL_LUT_VALID(a) "PEMX_CPL_LUT_VALID"
#define device_bar_BDK_PEMX_CPL_LUT_VALID(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CPL_LUT_VALID(a) (a)
#define arguments_BDK_PEMX_CPL_LUT_VALID(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_ctl_status
 *
 * PEM Control Status Register
 * This is a general control and status register of the PEM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_ctl_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM. */
        uint64_t rd_flt                : 1;  /**< [ 51: 51](RO) Read fault.

                                                                   0 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and non-fault.
                                                                       This is compatible with CN88XX pass 1.0.
                                                                   1 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and fault. In the case of a read by a core,
                                                                       this fault will cause a synchronous external abort in the core.

                                                                 Config reads which are terminated by PCIe with an error (UR, etc), or config reads
                                                                 when the PEM is disabled or link is down, will return to the NCB/cores all-ones and
                                                                 non-fault regardless of this bit. */
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_48_49        : 2;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t pm_xpme               : 1;  /**< [ 10: 10](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_pme port. EP mode. */
        uint64_t ob_p_cmd              : 1;  /**< [  9:  9](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core outband_pwrup_cmd
                                                                 port. EP mode. */
        uint64_t reserved_7_8          : 2;
        uint64_t nf_ecrc               : 1;  /**< [  6:  6](R/W) Do not forward peer-to-peer ECRC TLPs. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
#else /* Word 0 - Little Endian */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t nf_ecrc               : 1;  /**< [  6:  6](R/W) Do not forward peer-to-peer ECRC TLPs. */
        uint64_t reserved_7_8          : 2;
        uint64_t ob_p_cmd              : 1;  /**< [  9:  9](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core outband_pwrup_cmd
                                                                 port. EP mode. */
        uint64_t pm_xpme               : 1;  /**< [ 10: 10](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_pme port. EP mode. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_49        : 2;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t rd_flt                : 1;  /**< [ 51: 51](RO) Read fault.

                                                                   0 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and non-fault.
                                                                       This is compatible with CN88XX pass 1.0.
                                                                   1 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and fault. In the case of a read by a core,
                                                                       this fault will cause a synchronous external abort in the core.

                                                                 Config reads which are terminated by PCIe with an error (UR, etc), or config reads
                                                                 when the PEM is disabled or link is down, will return to the NCB/cores all-ones and
                                                                 non-fault regardless of this bit. */
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM. */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_ctl_status_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t rd_flt                : 1;  /**< [ 51: 51](RO) Read fault.

                                                                   0 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and non-fault.
                                                                       This is compatible with CN88XX pass 1.0.
                                                                   1 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and fault. In the case of a read by a core,
                                                                       this fault will cause a synchronous external abort in the core.

                                                                 Config reads which are terminated by PCIe with an error (UR, etc), or config reads
                                                                 when the PEM is disabled or link is down, will return to the NCB/cores all-ones and
                                                                 non-fault regardless of this bit. */
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_48_49        : 2;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t reserved_6_10         : 5;
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
#else /* Word 0 - Little Endian */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t reserved_6_10         : 5;
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_49        : 2;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t rd_flt                : 1;  /**< [ 51: 51](RO) Read fault.

                                                                   0 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and non-fault.
                                                                       This is compatible with CN88XX pass 1.0.
                                                                   1 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and fault. In the case of a read by a core,
                                                                       this fault will cause a synchronous external abort in the core.

                                                                 Config reads which are terminated by PCIe with an error (UR, etc), or config reads
                                                                 when the PEM is disabled or link is down, will return to the NCB/cores all-ones and
                                                                 non-fault regardless of this bit. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_ctl_status_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t pm_xpme               : 1;  /**< [ 10: 10](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_pme port. EP mode. */
        uint64_t ob_p_cmd              : 1;  /**< [  9:  9](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core outband_pwrup_cmd
                                                                 port. EP mode. */
        uint64_t reserved_8            : 1;
        uint64_t reserved_7            : 1;
        uint64_t nf_ecrc               : 1;  /**< [  6:  6](R/W) Do not forward peer-to-peer ECRC TLPs. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
#else /* Word 0 - Little Endian */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t nf_ecrc               : 1;  /**< [  6:  6](R/W) Do not forward peer-to-peer ECRC TLPs. */
        uint64_t reserved_7            : 1;
        uint64_t reserved_8            : 1;
        uint64_t ob_p_cmd              : 1;  /**< [  9:  9](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core outband_pwrup_cmd
                                                                 port. EP mode. */
        uint64_t pm_xpme               : 1;  /**< [ 10: 10](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_pme port. EP mode. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_ctl_status_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM.to improve
                                                                 small TLP performance. */
        uint64_t reserved_51           : 1;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_48_49        : 2;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t reserved_6_10         : 5;
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
#else /* Word 0 - Little Endian */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t reserved_6_10         : 5;
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_49        : 2;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_51           : 1;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM.to improve
                                                                 small TLP performance. */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_ctl_status_cn9 cn83xx; */
    struct bdk_pemx_ctl_status_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM. */
        uint64_t reserved_51           : 1;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_48_49        : 2;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t reserved_6_10         : 5;
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
#else /* Word 0 - Little Endian */
        uint64_t inv_lcrc              : 1;  /**< [  0:  0](R/W) When set, causes the LSB of the LCRC to be inverted. */
        uint64_t inv_ecrc              : 1;  /**< [  1:  1](R/W) When set, causes the LSB of the ECRC to be inverted. */
        uint64_t fast_lm               : 1;  /**< [  2:  2](R/W) When set, forces fast link mode. */
        uint64_t ro_ctlp               : 1;  /**< [  3:  3](R/W) When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
        uint64_t lnk_enb               : 1;  /**< [  4:  4](R/W) When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
        uint64_t dly_one               : 1;  /**< [  5:  5](R/W/H) When set the output client state machines will wait one cycle before starting a new TLP out. */
        uint64_t reserved_6_10         : 5;
        uint64_t pm_xtoff              : 1;  /**< [ 11: 11](R/W/H) When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
        uint64_t spares                : 4;  /**< [ 15: 12](R/W) Spare flops. */
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time in units of 0x10000 in coprocessor clocks to wait for a CPL to a
                                                                 configuration read that does not carry a retry status. Until such time that the
                                                                 timeout occurs and retry status is received for a configuration read, the read
                                                                 will be resent. A value of 0 disables retries and treats a CPL retry as a CPL
                                                                 UR.

                                                                 To use, it is recommended [CFG_RTRY] be set value corresponding to 200ms or
                                                                 less, although the PCI Express Base Specification allows up to 900ms for a
                                                                 device to send a successful completion.  When enabled, only one CFG RD may be
                                                                 issued until either successful completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_49        : 2;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_51           : 1;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM. */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pemx_ctl_status_t;

static inline uint64_t BDK_PEMX_CTL_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CTL_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000000ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000000ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000000ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CTL_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CTL_STATUS(a) bdk_pemx_ctl_status_t
#define bustype_BDK_PEMX_CTL_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CTL_STATUS(a) "PEMX_CTL_STATUS"
#define device_bar_BDK_PEMX_CTL_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CTL_STATUS(a) (a)
#define arguments_BDK_PEMX_CTL_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_ctl_status2
 *
 * PEM Control Status 2 Register
 * This register contains additional general control and status of the PEM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_ctl_status2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t no_fwd_prg            : 16; /**< [ 15:  0](R/W) The time * 0x10000 in core clocks to wait for the TLP FIFOs to be able to unload an entry.
                                                                 If there is no forward progress, such that the timeout occurs, credits are returned to the
                                                                 SLI and an interrupt (if enabled) is asserted. Any more TLPs received are dropped on the
                                                                 floor and the credits associated with those TLPs are returned as well. Note that 0xFFFF is
                                                                 a reserved value that will put the PEM in the 'forward progress stopped' state
                                                                 immediately. This state holds until a MAC reset is received. */
#else /* Word 0 - Little Endian */
        uint64_t no_fwd_prg            : 16; /**< [ 15:  0](R/W) The time * 0x10000 in core clocks to wait for the TLP FIFOs to be able to unload an entry.
                                                                 If there is no forward progress, such that the timeout occurs, credits are returned to the
                                                                 SLI and an interrupt (if enabled) is asserted. Any more TLPs received are dropped on the
                                                                 floor and the credits associated with those TLPs are returned as well. Note that 0xFFFF is
                                                                 a reserved value that will put the PEM in the 'forward progress stopped' state
                                                                 immediately. This state holds until a MAC reset is received. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_ctl_status2_s cn; */
} bdk_pemx_ctl_status2_t;

static inline uint64_t BDK_PEMX_CTL_STATUS2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CTL_STATUS2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000008ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000008ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000008ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000008ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_CTL_STATUS2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CTL_STATUS2(a) bdk_pemx_ctl_status2_t
#define bustype_BDK_PEMX_CTL_STATUS2(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CTL_STATUS2(a) "PEMX_CTL_STATUS2"
#define device_bar_BDK_PEMX_CTL_STATUS2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_CTL_STATUS2(a) (a)
#define arguments_BDK_PEMX_CTL_STATUS2(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_dbg_ena_w1c
 *
 * PEM Debug Information Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_dbg_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t reserved_51_55        : 5;
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t reserved_32           : 1;
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t reserved_32           : 1;
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t reserved_51_55        : 5;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_dbg_ena_w1c_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_dbg_ena_w1c_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RASDP]. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_D_DBE]. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_D_SBE]. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_C_DBE]. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[BMD_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[BMD_E]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_C_SBE]. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_C_DBE]. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_D_SBE]. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[M2S_D_DBE]. */
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..3)_DBG_INFO[RASDP]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_dbg_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Reads or clears enable for PEM(0..2)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_dbg_ena_w1c_cn9 cn83xx; */
    struct bdk_pemx_dbg_ena_w1c_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pemx_dbg_ena_w1c_t;

static inline uint64_t BDK_PEMX_DBG_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000458ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000458ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000458ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000458ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_DBG_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_ENA_W1C(a) bdk_pemx_dbg_ena_w1c_t
#define bustype_BDK_PEMX_DBG_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_ENA_W1C(a) "PEMX_DBG_ENA_W1C"
#define device_bar_BDK_PEMX_DBG_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_DBG_ENA_W1C(a) (a)
#define arguments_BDK_PEMX_DBG_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_dbg_ena_w1s
 *
 * PEM Debug Information Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_dbg_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t reserved_51_55        : 5;
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t reserved_32           : 1;
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t reserved_32           : 1;
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t reserved_51_55        : 5;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_dbg_ena_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_dbg_ena_w1s_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RASDP]. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_D_DBE]. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_D_SBE]. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_C_DBE]. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[BMD_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[BMD_E]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_C_SBE]. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_C_DBE]. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_D_SBE]. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[M2S_D_DBE]. */
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..3)_DBG_INFO[RASDP]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_dbg_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets enable for PEM(0..2)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_dbg_ena_w1s_cn9 cn83xx; */
    struct bdk_pemx_dbg_ena_w1s_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pemx_dbg_ena_w1s_t;

static inline uint64_t BDK_PEMX_DBG_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000460ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000460ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000460ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000460ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_DBG_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_ENA_W1S(a) bdk_pemx_dbg_ena_w1s_t
#define bustype_BDK_PEMX_DBG_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_ENA_W1S(a) "PEMX_DBG_ENA_W1S"
#define device_bar_BDK_PEMX_DBG_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_DBG_ENA_W1S(a) (a)
#define arguments_BDK_PEMX_DBG_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_dbg_info
 *
 * PEM Debug Information Register
 * This is a debug information register of the PEM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_dbg_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Detected a M2S FIFO parity error. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Detected a core header queue bank1 double bit error. */
        uint64_t reserved_51_55        : 5;
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t reserved_32           : 1;
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Received unlock message (EP mode only).
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message. This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message.
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message.
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP not to be forwarded to the peer.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. This legacy interrupt is deprecated and is never set. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. This legacy interrupt is deprecated and is never set. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP not to be forwarded to the peer.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message.
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message.
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message. This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Received unlock message (EP mode only).
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t reserved_32           : 1;
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t reserved_51_55        : 5;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Detected a core header queue bank1 double bit error. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Detected a M2S FIFO parity error. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_dbg_info_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Detected a core header queue bank1 double bit error. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Detected a core header queue bank1 single bit error. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Detected a core header queue bank0 double bit error. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Detected a core header queue bank0 single bit error. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Detected a core retry RAM double bit error. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Detected a core retry RAM single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Detected a data queue RAM parity error. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent.
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent.
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Detected a data queue RAM parity error. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Detected a core retry RAM single bit error. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Detected a core retry RAM double bit error. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Detected a core header queue bank0 single bit error. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Detected a core header queue bank0 double bit error. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Detected a core header queue bank1 single bit error. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Detected a core header queue bank1 double bit error. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_dbg_info_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1C/H) Core entered RAS data protection error mode. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1C/H) Detected a M2S data fifo double bit error. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1C/H) Detected a M2S data fifo single bit error. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1C/H) Detected a M2S data fifo double bit error. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1C/H) Detected a M2S control fifo single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1C/H) A NP or P TLP was seen in the outbound path, but it was not allowed to master the bus.
                                                                 If a PF TLP and the PCIEEP()_CFG001[ME] is not set.
                                                                 For VF TLP, either the PCIEEP()_CFG001[ME]/PCIEEPVF()_CFG001[ME] are not set. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Received unlock message (EP mode only).
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message. This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message.
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message.
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP not to be forwarded to the peer.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. This legacy interrupt is deprecated and is never set. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. This legacy interrupt is deprecated and is never set. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP not to be forwarded to the peer.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message.
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message.
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message. This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1C/H) Received unlock message (EP mode only).
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1C/H) A NP or P TLP was seen in the outbound path, but it was not allowed to master the bus.
                                                                 If a PF TLP and the PCIEEP()_CFG001[ME] is not set.
                                                                 For VF TLP, either the PCIEEP()_CFG001[ME]/PCIEEPVF()_CFG001[ME] are not set. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1C/H) Detected a M2S control fifo single bit error. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1C/H) Detected a M2S data fifo double bit error. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1C/H) Detected a M2S data fifo single bit error. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1C/H) Detected a M2S data fifo double bit error. */
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1C/H) Core entered RAS data protection error mode. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_dbg_info_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Detected a M2S FIFO parity error. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Detected a core header queue bank1 double bit error. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Detected a core header queue bank1 single bit error. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Detected a core header queue bank0 double bit error. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Detected a core header queue bank0 single bit error. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Detected a core retry RAM double bit error. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Detected a core retry RAM single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Detected a data queue RAM parity error. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent.
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent.
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp violates address/length rules, this bit is set as well.

                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error.
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP.
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set.

                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only).
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message.
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred.
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.

                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded.
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error.
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP).
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer).
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8 B/10 B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7).

                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation.
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored.

                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion.
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status.
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support.
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP.
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload.
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1C/H) Received an ECRC error. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1C/H) Lack of forward progress at TLP FIFOs timeout occurred. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1C/H) Detected a data queue RAM parity error. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1C/H) Detected a TLP posted FIFO data0 single bit error. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1C/H) Detected a TLP posted FIFO data0 double bit error. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1C/H) Detected a TLP posted FIFO data1 single bit error. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1C/H) Detected a TLP posted FIFO data1 double bit error. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1C/H) Detected a TLP posted FIFO control single bit error. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1C/H) Detected a TLP posted FIFO control double bit error. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1C/H) Detected a TLP NP FIFO data0 single bit error. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1C/H) Detected a TLP NP FIFO data0 double bit error. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1C/H) Detected a TLP NP FIFO data1 single bit error. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1C/H) Detected a TLP NP FIFO data1 double bit error. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1C/H) Detected a TLP NP FIFO control single bit error. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1C/H) Detected a TLP NP FIFO control double bit error. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1C/H) Detected a TLP CPL FIFO data0 single bit error. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1C/H) Detected a TLP CPL FIFO data0 double bit error. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1C/H) Detected a TLP CPL FIFO data1 single bit error. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1C/H) Detected a TLP CPL FIFO data1 double bit error. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1C/H) Detected a TLP CPL FIFO control single bit error. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1C/H) Detected a TLP CPL FIFO control double bit error. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1C/H) Detected a core retry RAM single bit error. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1C/H) Detected a core retry RAM double bit error. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1C/H) Detected a core header queue bank0 single bit error. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1C/H) Detected a core header queue bank0 double bit error. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1C/H) Detected a core header queue bank1 single bit error. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1C/H) Detected a core header queue bank1 double bit error. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Detected a M2S FIFO parity error. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_dbg_info_cn9 cn83xx; */
    /* struct bdk_pemx_dbg_info_cn81xx cn88xxp2; */
} bdk_pemx_dbg_info_t;

static inline uint64_t BDK_PEMX_DBG_INFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_INFO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000448ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000448ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000448ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000448ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_DBG_INFO", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_INFO(a) bdk_pemx_dbg_info_t
#define bustype_BDK_PEMX_DBG_INFO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_INFO(a) "PEMX_DBG_INFO"
#define device_bar_BDK_PEMX_DBG_INFO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_DBG_INFO(a) (a)
#define arguments_BDK_PEMX_DBG_INFO(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_dbg_info_w1s
 *
 * PEM Debug Information Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_dbg_info_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t reserved_51_55        : 5;
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t reserved_32           : 1;
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t reserved_32           : 1;
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t reserved_51_55        : 5;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_dbg_info_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_dbg_info_w1s_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RASDP]. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_D_DBE]. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_D_SBE]. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_C_DBE]. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[BMD_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rumep                 : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RUMEP].
                                                                 Internal:
                                                                 pedc_radm_msg_unlock. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[LOFP]. */
        uint64_t bmd_e                 : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[BMD_E]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[C_C_DBE]. */
        uint64_t m2s_c_sbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_C_SBE]. */
        uint64_t m2s_c_dbe             : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_C_DBE]. */
        uint64_t m2s_d_sbe             : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_D_SBE]. */
        uint64_t m2s_d_dbe             : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[M2S_D_DBE]. */
        uint64_t rasdp                 : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..3)_DBG_INFO[RASDP]. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_dbg_info_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets PEM(0..2)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_dbg_info_w1s_cn9 cn83xx; */
    struct bdk_pemx_dbg_info_w1s_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON].
                                                                 Internal:
                                                                 peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL].
                                                                 Internal:
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE].
                                                                 Internal:
                                                                 pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON].
                                                                 Internal:
                                                                 pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC].
                                                                 Internal:
                                                                 pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC].
                                                                 Internal:
                                                                 pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC].
                                                                 Internal:
                                                                 pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC].
                                                                 Internal:
                                                                 pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC].
                                                                 Internal:
                                                                 pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM].
                                                                 Internal:
                                                                 pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO].
                                                                 Internal:
                                                                 pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE].
                                                                 Internal:
                                                                 xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE].
                                                                 Internal:
                                                                 xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE].
                                                                 Internal:
                                                                 rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE].
                                                                 Internal:
                                                                 rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD].
                                                                 Internal:
                                                                 rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT].
                                                                 Internal:
                                                                 rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE].
                                                                 Internal:
                                                                 rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV].
                                                                 Internal:
                                                                 (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO].
                                                                 Internal:
                                                                 radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC].
                                                                 Internal:
                                                                 radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA].
                                                                 Internal:
                                                                 radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS].
                                                                 Internal:
                                                                 radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP].
                                                                 Internal:
                                                                 radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP].
                                                                 Internal:
                                                                 radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP].
                                                                 Internal:
                                                                 radm_rcvd_wreq_poisoned. */
        uint64_t ecrc_e                : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ECRC_E]. */
        uint64_t lofp                  : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[LOFP]. */
        uint64_t datq_pe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DATQ_PE]. */
        uint64_t p_d0_sbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_SBE]. */
        uint64_t p_d0_dbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D0_DBE]. */
        uint64_t p_d1_sbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_SBE]. */
        uint64_t p_d1_dbe              : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_D1_DBE]. */
        uint64_t p_c_sbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_SBE]. */
        uint64_t p_c_dbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[P_C_DBE]. */
        uint64_t n_d0_sbe              : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_SBE]. */
        uint64_t n_d0_dbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D0_DBE]. */
        uint64_t n_d1_sbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_SBE]. */
        uint64_t n_d1_dbe              : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_D1_DBE]. */
        uint64_t n_c_sbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_SBE]. */
        uint64_t n_c_dbe               : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[N_C_DBE]. */
        uint64_t c_d0_sbe              : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_SBE]. */
        uint64_t c_d0_dbe              : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D0_DBE]. */
        uint64_t c_d1_sbe              : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_SBE]. */
        uint64_t c_d1_dbe              : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_D1_DBE]. */
        uint64_t c_c_sbe               : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_SBE]. */
        uint64_t c_c_dbe               : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[C_C_DBE]. */
        uint64_t rtry_sbe              : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_SBE]. */
        uint64_t rtry_dbe              : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTRY_DBE]. */
        uint64_t qhdr_b0_sbe           : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_SBE]. */
        uint64_t qhdr_b0_dbe           : 1;  /**< [ 54: 54](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B0_DBE]. */
        uint64_t qhdr_b1_sbe           : 1;  /**< [ 55: 55](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_SBE]. */
        uint64_t qhdr_b1_dbe           : 1;  /**< [ 56: 56](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[QHDR_B1_DBE]. */
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pemx_dbg_info_w1s_t;

static inline uint64_t BDK_PEMX_DBG_INFO_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_INFO_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000450ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000450ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000450ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000450ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_DBG_INFO_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_INFO_W1S(a) bdk_pemx_dbg_info_w1s_t
#define bustype_BDK_PEMX_DBG_INFO_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_INFO_W1S(a) "PEMX_DBG_INFO_W1S"
#define device_bar_BDK_PEMX_DBG_INFO_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_DBG_INFO_W1S(a) (a)
#define arguments_BDK_PEMX_DBG_INFO_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_debug
 *
 * PEM Debug Register
 * This register contains status of level interrupts for debugging purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t inv_m2s_par           : 1;  /**< [  7:  7](R/W) Invert the generated parity to be written into the M2S FIFO
                                                                 to force a parity error when it is later read. */
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
        uint64_t inv_m2s_par           : 1;  /**< [  7:  7](R/W) Invert the generated parity to be written into the M2S FIFO
                                                                 to force a parity error when it is later read. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_debug_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_debug_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t intval                : 6;  /**< [  5:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t intval                : 6;  /**< [  5:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_debug_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t inv_m2s_par           : 1;  /**< [  7:  7](R/W) Invert the generated parity to be written into the M2S FIFO
                                                                 to force a parity error when it is later read. */
        uint64_t reserved_6            : 1;
        uint64_t intval                : 6;  /**< [  5:  0](RO/H) Status of INTX, HP_PMEI, and AERI interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t intval                : 6;  /**< [  5:  0](RO/H) Status of INTX, HP_PMEI, and AERI interrupts. */
        uint64_t reserved_6            : 1;
        uint64_t inv_m2s_par           : 1;  /**< [  7:  7](R/W) Invert the generated parity to be written into the M2S FIFO
                                                                 to force a parity error when it is later read. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_debug_cn9 cn83xx; */
    /* struct bdk_pemx_debug_s cn88xxp2; */
} bdk_pemx_debug_t;

static inline uint64_t BDK_PEMX_DEBUG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DEBUG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000480ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000480ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000480ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000480ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_DEBUG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DEBUG(a) bdk_pemx_debug_t
#define bustype_BDK_PEMX_DEBUG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DEBUG(a) "PEMX_DEBUG"
#define device_bar_BDK_PEMX_DEBUG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_DEBUG(a) (a)
#define arguments_BDK_PEMX_DEBUG(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_diag_status
 *
 * PEM Diagnostic Status Register
 * This register contains selection control for the core diagnostic bus.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_diag_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t pwrdwn                : 3;  /**< [  8:  6](RO/H) Current mac_phy_powerdown state. */
        uint64_t pm_dst                : 3;  /**< [  5:  3](RO/H) Current power management DSTATE. */
        uint64_t pm_stat               : 1;  /**< [  2:  2](RO) Power management status. */
        uint64_t pm_en                 : 1;  /**< [  1:  1](RO) Power management event enable. */
        uint64_t aux_en                : 1;  /**< [  0:  0](RO) Auxiliary power enable. */
#else /* Word 0 - Little Endian */
        uint64_t aux_en                : 1;  /**< [  0:  0](RO) Auxiliary power enable. */
        uint64_t pm_en                 : 1;  /**< [  1:  1](RO) Power management event enable. */
        uint64_t pm_stat               : 1;  /**< [  2:  2](RO) Power management status. */
        uint64_t pm_dst                : 3;  /**< [  5:  3](RO/H) Current power management DSTATE. */
        uint64_t pwrdwn                : 3;  /**< [  8:  6](RO/H) Current mac_phy_powerdown state. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_diag_status_s cn9; */
    struct bdk_pemx_diag_status_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t pwrdwn                : 3;  /**< [  8:  6](RO/H) Current mac_phy_powerdown state. */
        uint64_t pm_dst                : 3;  /**< [  5:  3](RO/H) Current power management DSTATE. */
        uint64_t pm_stat               : 1;  /**< [  2:  2](RO) Power management status. */
        uint64_t pm_en                 : 1;  /**< [  1:  1](RO) Power management event enable. */
        uint64_t aux_en                : 1;  /**< [  0:  0](RO) Auxiliary power enable. Always read as zero as auxiliary power is not supported. */
#else /* Word 0 - Little Endian */
        uint64_t aux_en                : 1;  /**< [  0:  0](RO) Auxiliary power enable. Always read as zero as auxiliary power is not supported. */
        uint64_t pm_en                 : 1;  /**< [  1:  1](RO) Power management event enable. */
        uint64_t pm_stat               : 1;  /**< [  2:  2](RO) Power management status. */
        uint64_t pm_dst                : 3;  /**< [  5:  3](RO/H) Current power management DSTATE. */
        uint64_t pwrdwn                : 3;  /**< [  8:  6](RO/H) Current mac_phy_powerdown state. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_diag_status_cn81xx cn88xx; */
    /* struct bdk_pemx_diag_status_s cn83xx; */
} bdk_pemx_diag_status_t;

static inline uint64_t BDK_PEMX_DIAG_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DIAG_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000020ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000020ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000020ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000020ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_DIAG_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DIAG_STATUS(a) bdk_pemx_diag_status_t
#define bustype_BDK_PEMX_DIAG_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DIAG_STATUS(a) "PEMX_DIAG_STATUS"
#define device_bar_BDK_PEMX_DIAG_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_DIAG_STATUS(a) (a)
#define arguments_BDK_PEMX_DIAG_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_ecc_ena
 *
 * PEM ECC Enable Register
 * Contains enables for TLP FIFO ECC RAMs.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_ecc_ena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_35_63        : 29;
        uint64_t qhdr_b1_ena           : 1;  /**< [ 34: 34](R/W) ECC enable for Core's Q HDR Bank1 RAM. */
        uint64_t qhdr_b0_ena           : 1;  /**< [ 33: 33](R/W) ECC enable for Core's Q HDR Bank0 RAM. */
        uint64_t rtry_ena              : 1;  /**< [ 32: 32](R/W) ECC enable for Core's RETRY RA. */
        uint64_t reserved_11_31        : 21;
        uint64_t m2s_c_ena             : 1;  /**< [ 10: 10](R/W) ECC enable for M2S Control FIFO. */
        uint64_t m2s_d_ena             : 1;  /**< [  9:  9](R/W) ECC enable for M2S Data FIFO. */
        uint64_t c_c_ena               : 1;  /**< [  8:  8](R/W) ECC enable for TLP CPL control FIFO. */
        uint64_t c_d1_ena              : 1;  /**< [  7:  7](R/W) ECC enable for TLP CPL data1 FIFO. */
        uint64_t c_d0_ena              : 1;  /**< [  6:  6](R/W) ECC enable for TLP CPL data0 FIFO. */
        uint64_t n_c_ena               : 1;  /**< [  5:  5](R/W) ECC enable for TLP NP control FIFO. */
        uint64_t n_d1_ena              : 1;  /**< [  4:  4](R/W) ECC enable for TLP NP data1 FIFO. */
        uint64_t n_d0_ena              : 1;  /**< [  3:  3](R/W) ECC enable for TLP NP data0 FIFO. */
        uint64_t p_c_ena               : 1;  /**< [  2:  2](R/W) ECC enable for TLP posted control FIFO. */
        uint64_t p_d1_ena              : 1;  /**< [  1:  1](R/W) ECC enable for TLP posted data1 FIFO. */
        uint64_t p_d0_ena              : 1;  /**< [  0:  0](R/W) ECC enable for TLP posted data0 FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t p_d0_ena              : 1;  /**< [  0:  0](R/W) ECC enable for TLP posted data0 FIFO. */
        uint64_t p_d1_ena              : 1;  /**< [  1:  1](R/W) ECC enable for TLP posted data1 FIFO. */
        uint64_t p_c_ena               : 1;  /**< [  2:  2](R/W) ECC enable for TLP posted control FIFO. */
        uint64_t n_d0_ena              : 1;  /**< [  3:  3](R/W) ECC enable for TLP NP data0 FIFO. */
        uint64_t n_d1_ena              : 1;  /**< [  4:  4](R/W) ECC enable for TLP NP data1 FIFO. */
        uint64_t n_c_ena               : 1;  /**< [  5:  5](R/W) ECC enable for TLP NP control FIFO. */
        uint64_t c_d0_ena              : 1;  /**< [  6:  6](R/W) ECC enable for TLP CPL data0 FIFO. */
        uint64_t c_d1_ena              : 1;  /**< [  7:  7](R/W) ECC enable for TLP CPL data1 FIFO. */
        uint64_t c_c_ena               : 1;  /**< [  8:  8](R/W) ECC enable for TLP CPL control FIFO. */
        uint64_t m2s_d_ena             : 1;  /**< [  9:  9](R/W) ECC enable for M2S Data FIFO. */
        uint64_t m2s_c_ena             : 1;  /**< [ 10: 10](R/W) ECC enable for M2S Control FIFO. */
        uint64_t reserved_11_31        : 21;
        uint64_t rtry_ena              : 1;  /**< [ 32: 32](R/W) ECC enable for Core's RETRY RA. */
        uint64_t qhdr_b0_ena           : 1;  /**< [ 33: 33](R/W) ECC enable for Core's Q HDR Bank0 RAM. */
        uint64_t qhdr_b1_ena           : 1;  /**< [ 34: 34](R/W) ECC enable for Core's Q HDR Bank1 RAM. */
        uint64_t reserved_35_63        : 29;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_ecc_ena_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t m2s_c_ena             : 1;  /**< [ 10: 10](R/W) ECC enable for M2S Control FIFO. */
        uint64_t m2s_d_ena             : 1;  /**< [  9:  9](R/W) ECC enable for M2S Data FIFO. */
        uint64_t c_c_ena               : 1;  /**< [  8:  8](R/W) ECC enable for TLP CPL control FIFO. */
        uint64_t c_d1_ena              : 1;  /**< [  7:  7](R/W) ECC enable for TLP CPL data1 FIFO. */
        uint64_t c_d0_ena              : 1;  /**< [  6:  6](R/W) ECC enable for TLP CPL data0 FIFO. */
        uint64_t n_c_ena               : 1;  /**< [  5:  5](R/W) ECC enable for TLP NP control FIFO. */
        uint64_t n_d1_ena              : 1;  /**< [  4:  4](R/W) ECC enable for TLP NP data1 FIFO. */
        uint64_t n_d0_ena              : 1;  /**< [  3:  3](R/W) ECC enable for TLP NP data0 FIFO. */
        uint64_t p_c_ena               : 1;  /**< [  2:  2](R/W) ECC enable for TLP posted control FIFO. */
        uint64_t p_d1_ena              : 1;  /**< [  1:  1](R/W) ECC enable for TLP posted data1 FIFO. */
        uint64_t p_d0_ena              : 1;  /**< [  0:  0](R/W) ECC enable for TLP posted data0 FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t p_d0_ena              : 1;  /**< [  0:  0](R/W) ECC enable for TLP posted data0 FIFO. */
        uint64_t p_d1_ena              : 1;  /**< [  1:  1](R/W) ECC enable for TLP posted data1 FIFO. */
        uint64_t p_c_ena               : 1;  /**< [  2:  2](R/W) ECC enable for TLP posted control FIFO. */
        uint64_t n_d0_ena              : 1;  /**< [  3:  3](R/W) ECC enable for TLP NP data0 FIFO. */
        uint64_t n_d1_ena              : 1;  /**< [  4:  4](R/W) ECC enable for TLP NP data1 FIFO. */
        uint64_t n_c_ena               : 1;  /**< [  5:  5](R/W) ECC enable for TLP NP control FIFO. */
        uint64_t c_d0_ena              : 1;  /**< [  6:  6](R/W) ECC enable for TLP CPL data0 FIFO. */
        uint64_t c_d1_ena              : 1;  /**< [  7:  7](R/W) ECC enable for TLP CPL data1 FIFO. */
        uint64_t c_c_ena               : 1;  /**< [  8:  8](R/W) ECC enable for TLP CPL control FIFO. */
        uint64_t m2s_d_ena             : 1;  /**< [  9:  9](R/W) ECC enable for M2S Data FIFO. */
        uint64_t m2s_c_ena             : 1;  /**< [ 10: 10](R/W) ECC enable for M2S Control FIFO. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_ecc_ena_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_35_63        : 29;
        uint64_t qhdr_b1_ena           : 1;  /**< [ 34: 34](R/W) ECC enable for Core's Q HDR Bank1 RAM. */
        uint64_t qhdr_b0_ena           : 1;  /**< [ 33: 33](R/W) ECC enable for Core's Q HDR Bank0 RAM. */
        uint64_t rtry_ena              : 1;  /**< [ 32: 32](R/W) ECC enable for Core's RETRY RA. */
        uint64_t reserved_9_31         : 23;
        uint64_t c_c_ena               : 1;  /**< [  8:  8](R/W) ECC enable for TLP CPL control FIFO. */
        uint64_t c_d1_ena              : 1;  /**< [  7:  7](R/W) ECC enable for TLP CPL data1 FIFO. */
        uint64_t c_d0_ena              : 1;  /**< [  6:  6](R/W) ECC enable for TLP CPL data0 FIFO. */
        uint64_t n_c_ena               : 1;  /**< [  5:  5](R/W) ECC enable for TLP NP control FIFO. */
        uint64_t n_d1_ena              : 1;  /**< [  4:  4](R/W) ECC enable for TLP NP data1 FIFO. */
        uint64_t n_d0_ena              : 1;  /**< [  3:  3](R/W) ECC enable for TLP NP data0 FIFO. */
        uint64_t p_c_ena               : 1;  /**< [  2:  2](R/W) ECC enable for TLP posted control FIFO. */
        uint64_t p_d1_ena              : 1;  /**< [  1:  1](R/W) ECC enable for TLP posted data1 FIFO. */
        uint64_t p_d0_ena              : 1;  /**< [  0:  0](R/W) ECC enable for TLP posted data0 FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t p_d0_ena              : 1;  /**< [  0:  0](R/W) ECC enable for TLP posted data0 FIFO. */
        uint64_t p_d1_ena              : 1;  /**< [  1:  1](R/W) ECC enable for TLP posted data1 FIFO. */
        uint64_t p_c_ena               : 1;  /**< [  2:  2](R/W) ECC enable for TLP posted control FIFO. */
        uint64_t n_d0_ena              : 1;  /**< [  3:  3](R/W) ECC enable for TLP NP data0 FIFO. */
        uint64_t n_d1_ena              : 1;  /**< [  4:  4](R/W) ECC enable for TLP NP data1 FIFO. */
        uint64_t n_c_ena               : 1;  /**< [  5:  5](R/W) ECC enable for TLP NP control FIFO. */
        uint64_t c_d0_ena              : 1;  /**< [  6:  6](R/W) ECC enable for TLP CPL data0 FIFO. */
        uint64_t c_d1_ena              : 1;  /**< [  7:  7](R/W) ECC enable for TLP CPL data1 FIFO. */
        uint64_t c_c_ena               : 1;  /**< [  8:  8](R/W) ECC enable for TLP CPL control FIFO. */
        uint64_t reserved_9_31         : 23;
        uint64_t rtry_ena              : 1;  /**< [ 32: 32](R/W) ECC enable for Core's RETRY RA. */
        uint64_t qhdr_b0_ena           : 1;  /**< [ 33: 33](R/W) ECC enable for Core's Q HDR Bank0 RAM. */
        uint64_t qhdr_b1_ena           : 1;  /**< [ 34: 34](R/W) ECC enable for Core's Q HDR Bank1 RAM. */
        uint64_t reserved_35_63        : 29;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_ecc_ena_cn81xx cn88xx; */
    /* struct bdk_pemx_ecc_ena_cn9 cn83xx; */
} bdk_pemx_ecc_ena_t;

static inline uint64_t BDK_PEMX_ECC_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECC_ENA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000470ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000470ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000470ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000470ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_ECC_ENA", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ECC_ENA(a) bdk_pemx_ecc_ena_t
#define bustype_BDK_PEMX_ECC_ENA(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ECC_ENA(a) "PEMX_ECC_ENA"
#define device_bar_BDK_PEMX_ECC_ENA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_ECC_ENA(a) (a)
#define arguments_BDK_PEMX_ECC_ENA(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_ecc_synd_ctrl
 *
 * PEM ECC Syndrome Control Register
 * This register contains syndrome control for TLP FIFO ECC RAMs.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_ecc_synd_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t qhdr_b1_syn           : 2;  /**< [ 37: 36](R/W) Syndrome flip bits for Core's Q HDR Bank1 RAM. */
        uint64_t qhdr_b0_syn           : 2;  /**< [ 35: 34](R/W) Syndrome flip bits for Core's Q HDR Bank0 RAM. */
        uint64_t rtry_syn              : 2;  /**< [ 33: 32](R/W) Syndrome flip bits for Core's RETRY RAM. */
        uint64_t reserved_22_31        : 10;
        uint64_t m2s_c_syn             : 2;  /**< [ 21: 20](R/W) Syndrome flip bits for M2S Control FIFO. */
        uint64_t m2s_d_syn             : 2;  /**< [ 19: 18](R/W) Syndrome flip bits for M2S Data FIFO. */
        uint64_t c_c_syn               : 2;  /**< [ 17: 16](R/W) Syndrome flip bits for TLP CPL control FIFO. */
        uint64_t c_d1_syn              : 2;  /**< [ 15: 14](R/W) Syndrome flip bits for TLP CPL data1 FIFO. */
        uint64_t c_d0_syn              : 2;  /**< [ 13: 12](R/W) Syndrome flip bits for TLP CPL data0 FIFO. */
        uint64_t n_c_syn               : 2;  /**< [ 11: 10](R/W) Syndrome flip bits for TLP NP control FIFO. */
        uint64_t n_d1_syn              : 2;  /**< [  9:  8](R/W) Syndrome flip bits for TLP NP data1 FIFO. */
        uint64_t n_d0_syn              : 2;  /**< [  7:  6](R/W) Syndrome flip bits for TLP NP data0 FIFO. */
        uint64_t p_c_syn               : 2;  /**< [  5:  4](R/W) Syndrome flip bits for TLP posted control FIFO. */
        uint64_t p_d1_syn              : 2;  /**< [  3:  2](R/W) Syndrome flip bits for TLP posted data1 FIFO. */
        uint64_t p_d0_syn              : 2;  /**< [  1:  0](R/W) Syndrome flip bits for TLP posted data0 FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t p_d0_syn              : 2;  /**< [  1:  0](R/W) Syndrome flip bits for TLP posted data0 FIFO. */
        uint64_t p_d1_syn              : 2;  /**< [  3:  2](R/W) Syndrome flip bits for TLP posted data1 FIFO. */
        uint64_t p_c_syn               : 2;  /**< [  5:  4](R/W) Syndrome flip bits for TLP posted control FIFO. */
        uint64_t n_d0_syn              : 2;  /**< [  7:  6](R/W) Syndrome flip bits for TLP NP data0 FIFO. */
        uint64_t n_d1_syn              : 2;  /**< [  9:  8](R/W) Syndrome flip bits for TLP NP data1 FIFO. */
        uint64_t n_c_syn               : 2;  /**< [ 11: 10](R/W) Syndrome flip bits for TLP NP control FIFO. */
        uint64_t c_d0_syn              : 2;  /**< [ 13: 12](R/W) Syndrome flip bits for TLP CPL data0 FIFO. */
        uint64_t c_d1_syn              : 2;  /**< [ 15: 14](R/W) Syndrome flip bits for TLP CPL data1 FIFO. */
        uint64_t c_c_syn               : 2;  /**< [ 17: 16](R/W) Syndrome flip bits for TLP CPL control FIFO. */
        uint64_t m2s_d_syn             : 2;  /**< [ 19: 18](R/W) Syndrome flip bits for M2S Data FIFO. */
        uint64_t m2s_c_syn             : 2;  /**< [ 21: 20](R/W) Syndrome flip bits for M2S Control FIFO. */
        uint64_t reserved_22_31        : 10;
        uint64_t rtry_syn              : 2;  /**< [ 33: 32](R/W) Syndrome flip bits for Core's RETRY RAM. */
        uint64_t qhdr_b0_syn           : 2;  /**< [ 35: 34](R/W) Syndrome flip bits for Core's Q HDR Bank0 RAM. */
        uint64_t qhdr_b1_syn           : 2;  /**< [ 37: 36](R/W) Syndrome flip bits for Core's Q HDR Bank1 RAM. */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_ecc_synd_ctrl_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t m2s_c_syn             : 2;  /**< [ 21: 20](R/W) Syndrome flip bits for M2S Control FIFO. */
        uint64_t m2s_d_syn             : 2;  /**< [ 19: 18](R/W) Syndrome flip bits for M2S Data FIFO. */
        uint64_t c_c_syn               : 2;  /**< [ 17: 16](R/W) Syndrome flip bits for TLP CPL control FIFO. */
        uint64_t c_d1_syn              : 2;  /**< [ 15: 14](R/W) Syndrome flip bits for TLP CPL data1 FIFO. */
        uint64_t c_d0_syn              : 2;  /**< [ 13: 12](R/W) Syndrome flip bits for TLP CPL data0 FIFO. */
        uint64_t n_c_syn               : 2;  /**< [ 11: 10](R/W) Syndrome flip bits for TLP NP control FIFO. */
        uint64_t n_d1_syn              : 2;  /**< [  9:  8](R/W) Syndrome flip bits for TLP NP data1 FIFO. */
        uint64_t n_d0_syn              : 2;  /**< [  7:  6](R/W) Syndrome flip bits for TLP NP data0 FIFO. */
        uint64_t p_c_syn               : 2;  /**< [  5:  4](R/W) Syndrome flip bits for TLP posted control FIFO. */
        uint64_t p_d1_syn              : 2;  /**< [  3:  2](R/W) Syndrome flip bits for TLP posted data1 FIFO. */
        uint64_t p_d0_syn              : 2;  /**< [  1:  0](R/W) Syndrome flip bits for TLP posted data0 FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t p_d0_syn              : 2;  /**< [  1:  0](R/W) Syndrome flip bits for TLP posted data0 FIFO. */
        uint64_t p_d1_syn              : 2;  /**< [  3:  2](R/W) Syndrome flip bits for TLP posted data1 FIFO. */
        uint64_t p_c_syn               : 2;  /**< [  5:  4](R/W) Syndrome flip bits for TLP posted control FIFO. */
        uint64_t n_d0_syn              : 2;  /**< [  7:  6](R/W) Syndrome flip bits for TLP NP data0 FIFO. */
        uint64_t n_d1_syn              : 2;  /**< [  9:  8](R/W) Syndrome flip bits for TLP NP data1 FIFO. */
        uint64_t n_c_syn               : 2;  /**< [ 11: 10](R/W) Syndrome flip bits for TLP NP control FIFO. */
        uint64_t c_d0_syn              : 2;  /**< [ 13: 12](R/W) Syndrome flip bits for TLP CPL data0 FIFO. */
        uint64_t c_d1_syn              : 2;  /**< [ 15: 14](R/W) Syndrome flip bits for TLP CPL data1 FIFO. */
        uint64_t c_c_syn               : 2;  /**< [ 17: 16](R/W) Syndrome flip bits for TLP CPL control FIFO. */
        uint64_t m2s_d_syn             : 2;  /**< [ 19: 18](R/W) Syndrome flip bits for M2S Data FIFO. */
        uint64_t m2s_c_syn             : 2;  /**< [ 21: 20](R/W) Syndrome flip bits for M2S Control FIFO. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_ecc_synd_ctrl_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t qhdr_b1_syn           : 2;  /**< [ 37: 36](R/W) Syndrome flip bits for Core's Q HDR Bank1 RAM. */
        uint64_t qhdr_b0_syn           : 2;  /**< [ 35: 34](R/W) Syndrome flip bits for Core's Q HDR Bank0 RAM. */
        uint64_t rtry_syn              : 2;  /**< [ 33: 32](R/W) Syndrome flip bits for Core's RETRY RAM. */
        uint64_t reserved_18_31        : 14;
        uint64_t c_c_syn               : 2;  /**< [ 17: 16](R/W) Syndrome flip bits for TLP CPL control FIFO. */
        uint64_t c_d1_syn              : 2;  /**< [ 15: 14](R/W) Syndrome flip bits for TLP CPL data1 FIFO. */
        uint64_t c_d0_syn              : 2;  /**< [ 13: 12](R/W) Syndrome flip bits for TLP CPL data0 FIFO. */
        uint64_t n_c_syn               : 2;  /**< [ 11: 10](R/W) Syndrome flip bits for TLP NP control FIFO. */
        uint64_t n_d1_syn              : 2;  /**< [  9:  8](R/W) Syndrome flip bits for TLP NP data1 FIFO. */
        uint64_t n_d0_syn              : 2;  /**< [  7:  6](R/W) Syndrome flip bits for TLP NP data0 FIFO. */
        uint64_t p_c_syn               : 2;  /**< [  5:  4](R/W) Syndrome flip bits for TLP posted control FIFO. */
        uint64_t p_d1_syn              : 2;  /**< [  3:  2](R/W) Syndrome flip bits for TLP posted data1 FIFO. */
        uint64_t p_d0_syn              : 2;  /**< [  1:  0](R/W) Syndrome flip bits for TLP posted data0 FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t p_d0_syn              : 2;  /**< [  1:  0](R/W) Syndrome flip bits for TLP posted data0 FIFO. */
        uint64_t p_d1_syn              : 2;  /**< [  3:  2](R/W) Syndrome flip bits for TLP posted data1 FIFO. */
        uint64_t p_c_syn               : 2;  /**< [  5:  4](R/W) Syndrome flip bits for TLP posted control FIFO. */
        uint64_t n_d0_syn              : 2;  /**< [  7:  6](R/W) Syndrome flip bits for TLP NP data0 FIFO. */
        uint64_t n_d1_syn              : 2;  /**< [  9:  8](R/W) Syndrome flip bits for TLP NP data1 FIFO. */
        uint64_t n_c_syn               : 2;  /**< [ 11: 10](R/W) Syndrome flip bits for TLP NP control FIFO. */
        uint64_t c_d0_syn              : 2;  /**< [ 13: 12](R/W) Syndrome flip bits for TLP CPL data0 FIFO. */
        uint64_t c_d1_syn              : 2;  /**< [ 15: 14](R/W) Syndrome flip bits for TLP CPL data1 FIFO. */
        uint64_t c_c_syn               : 2;  /**< [ 17: 16](R/W) Syndrome flip bits for TLP CPL control FIFO. */
        uint64_t reserved_18_31        : 14;
        uint64_t rtry_syn              : 2;  /**< [ 33: 32](R/W) Syndrome flip bits for Core's RETRY RAM. */
        uint64_t qhdr_b0_syn           : 2;  /**< [ 35: 34](R/W) Syndrome flip bits for Core's Q HDR Bank0 RAM. */
        uint64_t qhdr_b1_syn           : 2;  /**< [ 37: 36](R/W) Syndrome flip bits for Core's Q HDR Bank1 RAM. */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_ecc_synd_ctrl_cn81xx cn88xx; */
    /* struct bdk_pemx_ecc_synd_ctrl_cn9 cn83xx; */
} bdk_pemx_ecc_synd_ctrl_t;

static inline uint64_t BDK_PEMX_ECC_SYND_CTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECC_SYND_CTRL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000478ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000478ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000478ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000478ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_ECC_SYND_CTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ECC_SYND_CTRL(a) bdk_pemx_ecc_synd_ctrl_t
#define bustype_BDK_PEMX_ECC_SYND_CTRL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ECC_SYND_CTRL(a) "PEMX_ECC_SYND_CTRL"
#define device_bar_BDK_PEMX_ECC_SYND_CTRL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_ECC_SYND_CTRL(a) (a)
#define arguments_BDK_PEMX_ECC_SYND_CTRL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_eco
 *
 * INTERNAL: PEM ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 8;  /**< [  7:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_eco_s cn; */
} bdk_pemx_eco_t;

static inline uint64_t BDK_PEMX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000010ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000010ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ECO(a) bdk_pemx_eco_t
#define bustype_BDK_PEMX_ECO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ECO(a) "PEMX_ECO"
#define device_bar_BDK_PEMX_ECO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_ECO(a) (a)
#define arguments_BDK_PEMX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_erom#
 *
 * PEM Expansion ROM Registers
 * This register accesses the external EEPROM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_eromx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t erom                  : 64; /**< [ 63:  0](R/W/H) PCIe express read transactions to BAR3 (through PCIEEP()_CFG012) will appear as
                                                                 RSL reads to this register.

                                                                 Although 512 KB is advertised from PCIEEP()_CFG012, only the first 510 KB is
                                                                 actually accessible, and reads above 510 KB will return ones, writes are NOP.

                                                                 Accessible through PEM2 if EP PEM0 is an RC, otherwise accessible through PEM0.
                                                                 Access from a PEM that doesn't own the EEPROM will return fault. */
#else /* Word 0 - Little Endian */
        uint64_t erom                  : 64; /**< [ 63:  0](R/W/H) PCIe express read transactions to BAR3 (through PCIEEP()_CFG012) will appear as
                                                                 RSL reads to this register.

                                                                 Although 512 KB is advertised from PCIEEP()_CFG012, only the first 510 KB is
                                                                 actually accessible, and reads above 510 KB will return ones, writes are NOP.

                                                                 Accessible through PEM2 if EP PEM0 is an RC, otherwise accessible through PEM0.
                                                                 Access from a PEM that doesn't own the EEPROM will return fault. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_eromx_s cn; */
} bdk_pemx_eromx_t;

static inline uint64_t BDK_PEMX_EROMX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_EROMX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=65535)))
        return 0x87e0c0080000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xffff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=65535)))
        return 0x87e0c0080000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0xffff);
    __bdk_csr_fatal("PEMX_EROMX", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_EROMX(a,b) bdk_pemx_eromx_t
#define bustype_BDK_PEMX_EROMX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_EROMX(a,b) "PEMX_EROMX"
#define device_bar_BDK_PEMX_EROMX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_EROMX(a,b) (a)
#define arguments_BDK_PEMX_EROMX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_flr_glblcnt_ctl
 *
 * PEM FLR Global Count Control Register
 * Function level reset global counter control.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_flr_glblcnt_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t chge                  : 1;  /**< [  3:  3](R/W) When set, the default 25ms expiration of the function level reset
                                                                 global counter can be changed. */
        uint64_t inc                   : 1;  /**< [  2:  2](R/W) When CHGE is set, this bit determines if the 25ms expiration of the function
                                                                 level reset global counter will be increased (set) or decreased (not set). */
        uint64_t delta                 : 2;  /**< [  1:  0](R/W) When CHGE is set, this field determines the delta time to increase/decrease
                                                                 the 25 ms expiration of the function level reset global counter.
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 4 ms.
                                                                 0x3 = 8 ms. */
#else /* Word 0 - Little Endian */
        uint64_t delta                 : 2;  /**< [  1:  0](R/W) When CHGE is set, this field determines the delta time to increase/decrease
                                                                 the 25 ms expiration of the function level reset global counter.
                                                                 0x0 = 1 ms.
                                                                 0x1 = 2 ms.
                                                                 0x2 = 4 ms.
                                                                 0x3 = 8 ms. */
        uint64_t inc                   : 1;  /**< [  2:  2](R/W) When CHGE is set, this bit determines if the 25ms expiration of the function
                                                                 level reset global counter will be increased (set) or decreased (not set). */
        uint64_t chge                  : 1;  /**< [  3:  3](R/W) When set, the default 25ms expiration of the function level reset
                                                                 global counter can be changed. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_flr_glblcnt_ctl_s cn; */
} bdk_pemx_flr_glblcnt_ctl_t;

static inline uint64_t BDK_PEMX_FLR_GLBLCNT_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_FLR_GLBLCNT_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000210ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000210ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_FLR_GLBLCNT_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_FLR_GLBLCNT_CTL(a) bdk_pemx_flr_glblcnt_ctl_t
#define bustype_BDK_PEMX_FLR_GLBLCNT_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_FLR_GLBLCNT_CTL(a) "PEMX_FLR_GLBLCNT_CTL"
#define device_bar_BDK_PEMX_FLR_GLBLCNT_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_FLR_GLBLCNT_CTL(a) (a)
#define arguments_BDK_PEMX_FLR_GLBLCNT_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_flr_pf0_vf_stopreq
 *
 * PEM PF0 Virtual Function Stop Request Lower Register
 * PF0 virtual function level reset stop outbound requests register.
 * Hardware automatically sets the STOPREQ bit for the VF when it enters a
 * function level reset (FLR).  Software is responsible for clearing the STOPREQ
 * bit but must not do so prior to hardware taking down the FLR, which could be
 * as long as 100 ms.  It may be appropriate for software to wait longer before clearing
 * STOPREQ, software may need to drain deep DPI queues for example.
 *
 * Whenever PEM receives a request mastered by Octeon over S2M (i.e. P or NP),
 * when STOPREQ is set for the function, PEM will discard the outgoing request
 * before sending it to the PCIe core.  If a NP, PEM will schedule an immediate
 * SWI_RSP_ERROR completion for the request - no timeout is required.
 * In both cases, the PEM()_INT_SUM[BMD_E] bit will be set and a error
 * interrupt is generated.
 *
 * STOPREQ mimics the behavior of PCIEEPVF()_CFG001.ME for outbound requests that will
 * master the PCIe bus (P and NP).
 *
 * Note that STOPREQ will have no effect on completions returned by Octeon over the S2M.
 *
 * Note that STOPREQ will have no effect on M2S traffic.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_flr_pf0_vf_stopreq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t vf_stopreq_lo         : 64; /**< [ 63:  0](R/W1C/H) STOPREQ for the 64 VFs in PF0. */
#else /* Word 0 - Little Endian */
        uint64_t vf_stopreq_lo         : 64; /**< [ 63:  0](R/W1C/H) STOPREQ for the 64 VFs in PF0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_flr_pf0_vf_stopreq_s cn; */
} bdk_pemx_flr_pf0_vf_stopreq_t;

static inline uint64_t BDK_PEMX_FLR_PF0_VF_STOPREQ(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_FLR_PF0_VF_STOPREQ(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000220ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000220ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_FLR_PF0_VF_STOPREQ", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_FLR_PF0_VF_STOPREQ(a) bdk_pemx_flr_pf0_vf_stopreq_t
#define bustype_BDK_PEMX_FLR_PF0_VF_STOPREQ(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_FLR_PF0_VF_STOPREQ(a) "PEMX_FLR_PF0_VF_STOPREQ"
#define device_bar_BDK_PEMX_FLR_PF0_VF_STOPREQ(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_FLR_PF0_VF_STOPREQ(a) (a)
#define arguments_BDK_PEMX_FLR_PF0_VF_STOPREQ(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_flr_pf_stopreq
 *
 * PEM PF Stop Request Register
 * PF function level reset stop outbound requests register.
 * Hardware automatically sets the STOPREQ bit for the PF when it enters a
 * function level reset (FLR).  Software is responsible for clearing the STOPREQ
 * bit but must not do so prior to hardware taking down the FLR, which could be
 * as long as 100 ms.  It may be appropriate for software to wait longer before clearing
 * STOPREQ, software may need to drain deep DPI queues for example.
 * Whenever PEM receives a PF or child VF request mastered by Octeon over S2M (i.e. P or NP),
 * when STOPREQ is set for the function, PEM will discard the outgoing request
 * before sending it to the PCIe core.  If a NP, PEM will schedule an immediate
 * SWI_RSP_ERROR completion for the request - no timeout is required.
 * In both cases, the PEM(0..3)_INT_SUM[PBMD_E] bit will be set and a error
 * interrupt is generated.
 * STOPREQ mimics the behavior of PCIEEP()_CFG001.ME for outbound requests that will
 * master the PCIe bus (P and NP).
 * Note that STOPREQ will have no effect on completions returned by Octeon over the S2M.
 * Note that STOPREQ will have no effect on M2S traffic.
 * Note that when PF0_STOPREQ is set, none of the PEM()_FLR_PF0_VF_STOPREQ[VF_STOPREQ]
 * will be set.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_flr_pf_stopreq_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pf0_stopreq           : 1;  /**< [  0:  0](R/W1C/H) PF0 STOPREQ bit. */
#else /* Word 0 - Little Endian */
        uint64_t pf0_stopreq           : 1;  /**< [  0:  0](R/W1C/H) PF0 STOPREQ bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_flr_pf_stopreq_s cn; */
} bdk_pemx_flr_pf_stopreq_t;

static inline uint64_t BDK_PEMX_FLR_PF_STOPREQ(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_FLR_PF_STOPREQ(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000218ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000218ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_FLR_PF_STOPREQ", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_FLR_PF_STOPREQ(a) bdk_pemx_flr_pf_stopreq_t
#define bustype_BDK_PEMX_FLR_PF_STOPREQ(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_FLR_PF_STOPREQ(a) "PEMX_FLR_PF_STOPREQ"
#define device_bar_BDK_PEMX_FLR_PF_STOPREQ(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_FLR_PF_STOPREQ(a) (a)
#define arguments_BDK_PEMX_FLR_PF_STOPREQ(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_flr_stopreq_ctl
 *
 * PEM FLR Global Count Control Register
 * Function level reset STOPREQ control register.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_flr_stopreq_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t stopreqclr            : 1;  /**< [  0:  0](R/W) When [STOPREQCLR] is clear, only software (and reset) can clear
                                                                 PEM()_FLR_PF_STOPREQ[STOPREQ] and PEM()_FLR_PF0_VF_STOPREQ[STOPREQ]
                                                                 bits. When STOPREQCLR is set, PEM hardware
                                                                 also clears the STOPREQ bit when PEM completes an FLR to the PCIe core. In the
                                                                 case of a VF, only one STOPREQ bit gets cleared upon each FLR ack when
                                                                 STOPREQCLR mode bit is set. The srst will assert upon a PF
                                                                 FLR, and srst could be used to reset all STOPREQ bits regardless of
                                                                 STOPREQCLR. Otherwise (e.g. OCTEON), where a PF FLR does not
                                                                 assert srst. */
#else /* Word 0 - Little Endian */
        uint64_t stopreqclr            : 1;  /**< [  0:  0](R/W) When [STOPREQCLR] is clear, only software (and reset) can clear
                                                                 PEM()_FLR_PF_STOPREQ[STOPREQ] and PEM()_FLR_PF0_VF_STOPREQ[STOPREQ]
                                                                 bits. When STOPREQCLR is set, PEM hardware
                                                                 also clears the STOPREQ bit when PEM completes an FLR to the PCIe core. In the
                                                                 case of a VF, only one STOPREQ bit gets cleared upon each FLR ack when
                                                                 STOPREQCLR mode bit is set. The srst will assert upon a PF
                                                                 FLR, and srst could be used to reset all STOPREQ bits regardless of
                                                                 STOPREQCLR. Otherwise (e.g. OCTEON), where a PF FLR does not
                                                                 assert srst. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_flr_stopreq_ctl_s cn; */
} bdk_pemx_flr_stopreq_ctl_t;

static inline uint64_t BDK_PEMX_FLR_STOPREQ_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_FLR_STOPREQ_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000238ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000238ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_FLR_STOPREQ_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_FLR_STOPREQ_CTL(a) bdk_pemx_flr_stopreq_ctl_t
#define bustype_BDK_PEMX_FLR_STOPREQ_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_FLR_STOPREQ_CTL(a) "PEMX_FLR_STOPREQ_CTL"
#define device_bar_BDK_PEMX_FLR_STOPREQ_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_FLR_STOPREQ_CTL(a) (a)
#define arguments_BDK_PEMX_FLR_STOPREQ_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_flr_zombie_ctl
 *
 * PEM FLR Global Count Control Register
 * Function level reset global zombie counter control register.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_flr_zombie_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t exp                   : 10; /**< [  9:  0](R/W) The expiration value for the inbound shared global zombie counter.  The global zombie
                                                                 counter
                                                                 continuously counts the number of cycles where the PCIe core was allowed to send
                                                                 either a posted request or a completion to the PEM.  When the global zombie counter
                                                                 reaches expiration (EXP), it resets to zero and all the nonzero per PCIe tag zombie
                                                                 counters are decremented.  When a per PCIe tag zombie counter decrements to zero, a
                                                                 SWI_RSP_ERROR is
                                                                 sent to the M2S bus and its associated PCIe tag is returned to the pool.
                                                                 This field allows software programmability control of the zombie counter expiration. */
#else /* Word 0 - Little Endian */
        uint64_t exp                   : 10; /**< [  9:  0](R/W) The expiration value for the inbound shared global zombie counter.  The global zombie
                                                                 counter
                                                                 continuously counts the number of cycles where the PCIe core was allowed to send
                                                                 either a posted request or a completion to the PEM.  When the global zombie counter
                                                                 reaches expiration (EXP), it resets to zero and all the nonzero per PCIe tag zombie
                                                                 counters are decremented.  When a per PCIe tag zombie counter decrements to zero, a
                                                                 SWI_RSP_ERROR is
                                                                 sent to the M2S bus and its associated PCIe tag is returned to the pool.
                                                                 This field allows software programmability control of the zombie counter expiration. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_flr_zombie_ctl_s cn; */
} bdk_pemx_flr_zombie_ctl_t;

static inline uint64_t BDK_PEMX_FLR_ZOMBIE_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_FLR_ZOMBIE_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000230ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000230ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_FLR_ZOMBIE_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_FLR_ZOMBIE_CTL(a) bdk_pemx_flr_zombie_ctl_t
#define bustype_BDK_PEMX_FLR_ZOMBIE_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_FLR_ZOMBIE_CTL(a) "PEMX_FLR_ZOMBIE_CTL"
#define device_bar_BDK_PEMX_FLR_ZOMBIE_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_FLR_ZOMBIE_CTL(a) (a)
#define arguments_BDK_PEMX_FLR_ZOMBIE_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_inb_read_credits
 *
 * PEM In-flight Read Credits Register
 * This register contains the number of in-flight read operations from PCIe core to SLI.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_inb_read_credits_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 6; maximum number is 64. */
#else /* Word 0 - Little Endian */
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 6; maximum number is 64. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_inb_read_credits_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 2; maximum number is 64. */
#else /* Word 0 - Little Endian */
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 2; maximum number is 64. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } cn88xxp1;
    /* struct bdk_pemx_inb_read_credits_s cn9; */
    /* struct bdk_pemx_inb_read_credits_s cn81xx; */
    /* struct bdk_pemx_inb_read_credits_s cn83xx; */
    /* struct bdk_pemx_inb_read_credits_s cn88xxp2; */
} bdk_pemx_inb_read_credits_t;

static inline uint64_t BDK_PEMX_INB_READ_CREDITS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INB_READ_CREDITS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c00000b8ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c00000b8ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c00000b8ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c00000b8ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_INB_READ_CREDITS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INB_READ_CREDITS(a) bdk_pemx_inb_read_credits_t
#define bustype_BDK_PEMX_INB_READ_CREDITS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INB_READ_CREDITS(a) "PEMX_INB_READ_CREDITS"
#define device_bar_BDK_PEMX_INB_READ_CREDITS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_INB_READ_CREDITS(a) (a)
#define arguments_BDK_PEMX_INB_READ_CREDITS(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_int_ena_w1c
 *
 * PEM Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_B1]. */
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_B3]. */
        uint64_t reserved_2            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2            : 1;
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_B3]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..3)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_int_ena_w1c_s cn9; */
    struct bdk_pemx_int_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UP_B1]. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..2)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_pemx_int_ena_w1c_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UP_B1]. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_pemx_int_ena_w1c_s cn83xx; */
} bdk_pemx_int_ena_w1c_t;

static inline uint64_t BDK_PEMX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000438ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000438ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000438ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000438ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_ENA_W1C(a) bdk_pemx_int_ena_w1c_t
#define bustype_BDK_PEMX_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_ENA_W1C(a) "PEMX_INT_ENA_W1C"
#define device_bar_BDK_PEMX_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_INT_ENA_W1C(a) (a)
#define arguments_BDK_PEMX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_int_ena_w1s
 *
 * PEM Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_B1]. */
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_B3]. */
        uint64_t reserved_2            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2            : 1;
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_B3]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..3)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_int_ena_w1s_s cn9; */
    struct bdk_pemx_int_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UP_B1]. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..2)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_pemx_int_ena_w1s_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UP_B1]. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_pemx_int_ena_w1s_s cn83xx; */
} bdk_pemx_int_ena_w1s_t;

static inline uint64_t BDK_PEMX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000440ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000440ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000440ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000440ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_ENA_W1S(a) bdk_pemx_int_ena_w1s_t
#define bustype_BDK_PEMX_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_ENA_W1S(a) "PEMX_INT_ENA_W1S"
#define device_bar_BDK_PEMX_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_INT_ENA_W1S(a) (a)
#define arguments_BDK_PEMX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_int_sum
 *
 * PEM Interrupt Summary Register
 * This register contains the different interrupt summary bits of the PEM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_int_sum_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Had a CRS timeout when retries were disabled. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Had a CRS timeout when retries were enabled. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Received read lock TLP. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Received N-TLP for unknown BAR. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Received N-TLP for BAR2 when BAR2 is disabled. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Received N-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Received P-TLP for an unknown BAR. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Received P-TLP for BAR2 when BAR2 is disabled. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Received P-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1C/H) Received P-TLP for Expansion ROM (BAR3 EP Mode). */
        uint64_t reserved_2            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) System error, RC mode only.
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) System error, RC mode only.
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2            : 1;
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1C/H) Received P-TLP for Expansion ROM (BAR3 EP Mode). */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Received P-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Received P-TLP for BAR2 when BAR2 is disabled. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Received P-TLP for an unknown BAR. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Received N-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Received N-TLP for BAR2 when BAR2 is disabled. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Received N-TLP for unknown BAR. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Received read lock TLP. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Had a CRS timeout when retries were enabled. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Had a CRS timeout when retries were disabled. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_int_sum_s cn9; */
    struct bdk_pemx_int_sum_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Had a CRS timeout when retries were disabled. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Had a CRS timeout when retries were enabled. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Received read lock TLP. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Received N-TLP for unknown BAR. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Received N-TLP for BAR2 when BAR2 is disabled. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Received N-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Received P-TLP for an unknown BAR. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Received P-TLP for BAR2 when BAR2 is disabled. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Received P-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) System error, RC mode only.
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) System error, RC mode only.
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1C/H) Received P-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1C/H) Received P-TLP for BAR2 when BAR2 is disabled. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1C/H) Received P-TLP for an unknown BAR. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1C/H) Received N-TLP for BAR1 when BAR1 index valid is not set. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1C/H) Received N-TLP for BAR2 when BAR2 is disabled. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1C/H) Received N-TLP for unknown BAR. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1C/H) Received read lock TLP. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1C/H) Had a CRS timeout when retries were enabled. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1C/H) Had a CRS timeout when retries were disabled. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_int_sum_cn81xx cn88xx; */
    /* struct bdk_pemx_int_sum_s cn83xx; */
} bdk_pemx_int_sum_t;

static inline uint64_t BDK_PEMX_INT_SUM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_SUM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000428ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000428ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000428ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000428ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_INT_SUM", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_SUM(a) bdk_pemx_int_sum_t
#define bustype_BDK_PEMX_INT_SUM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_SUM(a) "PEMX_INT_SUM"
#define device_bar_BDK_PEMX_INT_SUM(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_INT_SUM(a) (a)
#define arguments_BDK_PEMX_INT_SUM(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_int_sum_w1s
 *
 * PEM Interrupt Summary Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_B1]. */
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_B3]. */
        uint64_t reserved_2            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2            : 1;
        uint64_t up_b3                 : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_B3]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..3)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_int_sum_w1s_s cn9; */
    struct bdk_pemx_int_sum_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UP_B1]. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..2)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_pemx_int_sum_w1s_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[CRS_DR]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[CRS_ER]. */
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[RDLK]. */
        uint64_t reserved_10           : 1;
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UN_BX]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UN_B2]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UN_B1]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UP_BX]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UP_B2]. */
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UP_B1]. */
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[SE].
                                                                 Internal:
                                                                 cfg_sys_err_rc. */
        uint64_t reserved_2_3          : 2;
        uint64_t up_b1                 : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UP_B1]. */
        uint64_t up_b2                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UP_B2]. */
        uint64_t up_bx                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UP_BX]. */
        uint64_t un_b1                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UN_B1]. */
        uint64_t un_b2                 : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UN_B2]. */
        uint64_t un_bx                 : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[UN_BX]. */
        uint64_t reserved_10           : 1;
        uint64_t rdlk                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[RDLK]. */
        uint64_t crs_er                : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[CRS_ER]. */
        uint64_t crs_dr                : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[CRS_DR]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_pemx_int_sum_w1s_s cn83xx; */
} bdk_pemx_int_sum_w1s_t;

static inline uint64_t BDK_PEMX_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_SUM_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000430ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000430ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000430ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000430ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_INT_SUM_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_SUM_W1S(a) bdk_pemx_int_sum_w1s_t
#define bustype_BDK_PEMX_INT_SUM_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_SUM_W1S(a) "PEMX_INT_SUM_W1S"
#define device_bar_BDK_PEMX_INT_SUM_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_INT_SUM_W1S(a) (a)
#define arguments_BDK_PEMX_INT_SUM_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_latency_pc
 *
 * PEM Latency Count Register
 * This register contains read latency count for debugging purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t latency               : 64; /**< [ 63:  0](RO/H) Total read latency count in units of coprocessor-clocks measured from
                                                                 SLI read request until first data is returned from remote memory aggregated
                                                                 across all non-masked SWI tags. */
#else /* Word 0 - Little Endian */
        uint64_t latency               : 64; /**< [ 63:  0](RO/H) Total read latency count in units of coprocessor-clocks measured from
                                                                 SLI read request until first data is returned from remote memory aggregated
                                                                 across all non-masked SWI tags. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_latency_pc_s cn; */
} bdk_pemx_latency_pc_t;

static inline uint64_t BDK_PEMX_LATENCY_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_LATENCY_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000490ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000490ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_LATENCY_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_LATENCY_PC(a) bdk_pemx_latency_pc_t
#define bustype_BDK_PEMX_LATENCY_PC(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_LATENCY_PC(a) "PEMX_LATENCY_PC"
#define device_bar_BDK_PEMX_LATENCY_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_LATENCY_PC(a) (a)
#define arguments_BDK_PEMX_LATENCY_PC(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_latency_pc_ctl
 *
 * PEM Latency Control Register
 * This register controls read latency monitoring for debugging purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_latency_pc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t complete              : 1;  /**< [  1:  1](RO/H) When software causes a rising edge on [ACTIVE], hardware will clear this
                                                                 bit. Later, when software clears [ACTIVE], hardware will wait for all
                                                                 outstanding reads to get their first data returned and then set this bit to
                                                                 indicate that measurement operations are completed. */
        uint64_t active                : 1;  /**< [  0:  0](R/W) When a software write causes a rising edge on this bit, PEM will begin a
                                                                 measurement which will include PEM clearing PEM()_LATENCY_PC and PEM()_READS_PC
                                                                 to reset all counting as well as PEM clearing PEM()_LATENCY_CTL[COMPLETE]. Only
                                                                 SLI SWI reads that occur after this rising edge will be considered. When
                                                                 software wants to halt measurement, it can clear this bit which will block
                                                                 further reads from being considered. When software reads
                                                                 PEM()_LATENCY_CTL[COMPLETE] as set, it can know that all measurement is
                                                                 completed and PEM()_LATENCY_PC and PEM()_READS_PC reflect a completely accurate
                                                                 and stable set of values. */
#else /* Word 0 - Little Endian */
        uint64_t active                : 1;  /**< [  0:  0](R/W) When a software write causes a rising edge on this bit, PEM will begin a
                                                                 measurement which will include PEM clearing PEM()_LATENCY_PC and PEM()_READS_PC
                                                                 to reset all counting as well as PEM clearing PEM()_LATENCY_CTL[COMPLETE]. Only
                                                                 SLI SWI reads that occur after this rising edge will be considered. When
                                                                 software wants to halt measurement, it can clear this bit which will block
                                                                 further reads from being considered. When software reads
                                                                 PEM()_LATENCY_CTL[COMPLETE] as set, it can know that all measurement is
                                                                 completed and PEM()_LATENCY_PC and PEM()_READS_PC reflect a completely accurate
                                                                 and stable set of values. */
        uint64_t complete              : 1;  /**< [  1:  1](RO/H) When software causes a rising edge on [ACTIVE], hardware will clear this
                                                                 bit. Later, when software clears [ACTIVE], hardware will wait for all
                                                                 outstanding reads to get their first data returned and then set this bit to
                                                                 indicate that measurement operations are completed. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_latency_pc_ctl_s cn; */
} bdk_pemx_latency_pc_ctl_t;

static inline uint64_t BDK_PEMX_LATENCY_PC_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_LATENCY_PC_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c00004c0ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c00004c0ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_LATENCY_PC_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_LATENCY_PC_CTL(a) bdk_pemx_latency_pc_ctl_t
#define bustype_BDK_PEMX_LATENCY_PC_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_LATENCY_PC_CTL(a) "PEMX_LATENCY_PC_CTL"
#define device_bar_BDK_PEMX_LATENCY_PC_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_LATENCY_PC_CTL(a) (a)
#define arguments_BDK_PEMX_LATENCY_PC_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_latency_pc_mask#
 *
 * PEM Latency Counts Low Register
 * This register contains read latency masking for debugging purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_latency_pc_maskx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mask                  : 64; /**< [ 63:  0](R/W) Each bit of MASK corresponds to one SWI tag value. PEM()_LATENCY_PC_MASK(0)
                                                                 corresponds to SWI tags [63:0], PEM()_LATENCY_PC_MASK(1) corresponds to
                                                                 SWI tags [127:64].  If a bit of [MASK] is set, then its SWI tag will NOT be
                                                                 included in the values reported in PEM()_LATENCY_PC and PEM()_READS_PC. */
#else /* Word 0 - Little Endian */
        uint64_t mask                  : 64; /**< [ 63:  0](R/W) Each bit of MASK corresponds to one SWI tag value. PEM()_LATENCY_PC_MASK(0)
                                                                 corresponds to SWI tags [63:0], PEM()_LATENCY_PC_MASK(1) corresponds to
                                                                 SWI tags [127:64].  If a bit of [MASK] is set, then its SWI tag will NOT be
                                                                 included in the values reported in PEM()_LATENCY_PC and PEM()_READS_PC. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_latency_pc_maskx_s cn; */
} bdk_pemx_latency_pc_maskx_t;

static inline uint64_t BDK_PEMX_LATENCY_PC_MASKX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_LATENCY_PC_MASKX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=1)))
        return 0x87e0c00004a0ll + 0x1000000ll * ((a) & 0x3) + 0x100ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=1)))
        return 0x87e0c00004a0ll + 0x1000000ll * ((a) & 0x3) + 0x100ll * ((b) & 0x1);
    __bdk_csr_fatal("PEMX_LATENCY_PC_MASKX", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_LATENCY_PC_MASKX(a,b) bdk_pemx_latency_pc_maskx_t
#define bustype_BDK_PEMX_LATENCY_PC_MASKX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_LATENCY_PC_MASKX(a,b) "PEMX_LATENCY_PC_MASKX"
#define device_bar_BDK_PEMX_LATENCY_PC_MASKX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_LATENCY_PC_MASKX(a,b) (a)
#define arguments_BDK_PEMX_LATENCY_PC_MASKX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_msix_pba#
 *
 * PEM MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the PEM_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated PEM_MSIX_VEC()_CTL, enumerated by PEM_INT_VEC_E. Bits
                                                                 that have no associated PEM_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated PEM_MSIX_VEC()_CTL, enumerated by PEM_INT_VEC_E. Bits
                                                                 that have no associated PEM_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_msix_pbax_s cn; */
} bdk_pemx_msix_pbax_t;

static inline uint64_t BDK_PEMX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=2) && (b==0)))
        return 0x87e0c0ff0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b==0)))
        return 0x87e0c0ff0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=5) && (b==0)))
        return 0x87e0c0ff0000ll + 0x1000000ll * ((a) & 0x7) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b==0)))
        return 0x87e0c0ff0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("PEMX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_MSIX_PBAX(a,b) bdk_pemx_msix_pbax_t
#define bustype_BDK_PEMX_MSIX_PBAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_MSIX_PBAX(a,b) "PEMX_MSIX_PBAX"
#define device_bar_BDK_PEMX_MSIX_PBAX(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_PEMX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_PEMX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_msix_vec#_addr
 *
 * PEM MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the PEM_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PEM(0..3)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PEM(0..3)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_msix_vecx_addr_s cn9; */
    struct bdk_pemx_msix_vecx_addr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PEM(0..2)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PEM(0..2)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_pemx_msix_vecx_addr_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PEM(0..5)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_PEM(0..5)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_pemx_msix_vecx_addr_s cn83xx; */
} bdk_pemx_msix_vecx_addr_t;

static inline uint64_t BDK_PEMX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=2) && (b<=11)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=11)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((a<=5) && (b<=13)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=5) && (b<=15)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=11)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("PEMX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_MSIX_VECX_ADDR(a,b) bdk_pemx_msix_vecx_addr_t
#define bustype_BDK_PEMX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_MSIX_VECX_ADDR(a,b) "PEMX_MSIX_VECX_ADDR"
#define device_bar_BDK_PEMX_MSIX_VECX_ADDR(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_PEMX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_PEMX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_msix_vec#_ctl
 *
 * PEM MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the PEM_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_msix_vecx_ctl_s cn; */
} bdk_pemx_msix_vecx_ctl_t;

static inline uint64_t BDK_PEMX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=2) && (b<=11)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=11)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((a<=5) && (b<=13)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=5) && (b<=15)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=11)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("PEMX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_MSIX_VECX_CTL(a,b) bdk_pemx_msix_vecx_ctl_t
#define bustype_BDK_PEMX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_MSIX_VECX_CTL(a,b) "PEMX_MSIX_VECX_CTL"
#define device_bar_BDK_PEMX_MSIX_VECX_CTL(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_PEMX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_PEMX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_on
 *
 * PEM On Status Register
 * This register indicates that PEM is configured and ready.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_on_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t pemoor                : 1;  /**< [  1:  1](RO/H) Indication to software that the PEM has been taken out of reset (i.e. BIST is done) and it
                                                                 is safe to configure core CSRs. */
        uint64_t pemon                 : 1;  /**< [  0:  0](R/W/H) Indication to the GSER that the PEM is out of reset, configured, and ready to send/receive
                                                                 traffic. Setting this bit takes the configured PIPE out of reset. */
#else /* Word 0 - Little Endian */
        uint64_t pemon                 : 1;  /**< [  0:  0](R/W/H) Indication to the GSER that the PEM is out of reset, configured, and ready to send/receive
                                                                 traffic. Setting this bit takes the configured PIPE out of reset. */
        uint64_t pemoor                : 1;  /**< [  1:  1](RO/H) Indication to software that the PEM has been taken out of reset (i.e. BIST is done) and it
                                                                 is safe to configure core CSRs. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_on_s cn; */
} bdk_pemx_on_t;

static inline uint64_t BDK_PEMX_ON(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ON(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000420ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000420ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000420ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000420ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_ON", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ON(a) bdk_pemx_on_t
#define bustype_BDK_PEMX_ON(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ON(a) "PEMX_ON"
#define device_bar_BDK_PEMX_ON(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_ON(a) (a)
#define arguments_BDK_PEMX_ON(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_p2n_bar0_start
 *
 * PEM PCIe to SLI BAR0 Start Register
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the SLI in RC mode.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_p2n_bar0_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_p2n_bar0_start_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 41; /**< [ 63: 23](R/W) The starting address of the 8 MB BAR0 address space. */
        uint64_t reserved_0_22         : 23;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_22         : 23;
        uint64_t addr                  : 41; /**< [ 63: 23](R/W) The starting address of the 8 MB BAR0 address space. */
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_p2n_bar0_start_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 50; /**< [ 63: 14](R/W) The starting address of the 16KB BAR0 address space. */
        uint64_t reserved_0_13         : 14;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_13         : 14;
        uint64_t addr                  : 50; /**< [ 63: 14](R/W) The starting address of the 16KB BAR0 address space. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_p2n_bar0_start_cn81xx cn88xx; */
    /* struct bdk_pemx_p2n_bar0_start_cn9 cn83xx; */
} bdk_pemx_p2n_bar0_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR0_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR0_START(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000080ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000080ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000080ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000080ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_P2N_BAR0_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_P2N_BAR0_START(a) bdk_pemx_p2n_bar0_start_t
#define bustype_BDK_PEMX_P2N_BAR0_START(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2N_BAR0_START(a) "PEMX_P2N_BAR0_START"
#define device_bar_BDK_PEMX_P2N_BAR0_START(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_P2N_BAR0_START(a) (a)
#define arguments_BDK_PEMX_P2N_BAR0_START(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_p2n_bar1_start
 *
 * PEM PCIe to SLI BAR1 Start Register
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the SLI in RC mode.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_p2n_bar1_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 38; /**< [ 63: 26](R/W) The starting address of the 64 MB BAR1 address space. */
        uint64_t reserved_0_25         : 26;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_25         : 26;
        uint64_t addr                  : 38; /**< [ 63: 26](R/W) The starting address of the 64 MB BAR1 address space. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_p2n_bar1_start_s cn; */
} bdk_pemx_p2n_bar1_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR1_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR1_START(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000088ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000088ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000088ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000088ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_P2N_BAR1_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_P2N_BAR1_START(a) bdk_pemx_p2n_bar1_start_t
#define bustype_BDK_PEMX_P2N_BAR1_START(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2N_BAR1_START(a) "PEMX_P2N_BAR1_START"
#define device_bar_BDK_PEMX_P2N_BAR1_START(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_P2N_BAR1_START(a) (a)
#define arguments_BDK_PEMX_P2N_BAR1_START(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_p2n_bar2_start
 *
 * PEM PCIe to SLI BAR2 Start Register
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the SLI in RC mode.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_p2n_bar2_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_p2n_bar2_start_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 44; /**< [ 63: 20](R/W) The starting address of the BAR2 address space, sized as configured by the
                                                                 PEM()_BAR_CTL[BAR2_SIZ]
                                                                 which defaults to ADDR<63:50> and used to determine a RC bar2 hit. */
        uint64_t reserved_0_19         : 20;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_19         : 20;
        uint64_t addr                  : 44; /**< [ 63: 20](R/W) The starting address of the BAR2 address space, sized as configured by the
                                                                 PEM()_BAR_CTL[BAR2_SIZ]
                                                                 which defaults to ADDR<63:50> and used to determine a RC bar2 hit. */
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_p2n_bar2_start_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 14; /**< [ 63: 50](R/W) The starting address of the 2^50 address space
                                                                 that is the BAR2 address space. */
        uint64_t spares                : 2;  /**< [ 49: 48](R/W) Spare flops. */
        uint64_t reserved_0_47         : 48;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_47         : 48;
        uint64_t spares                : 2;  /**< [ 49: 48](R/W) Spare flops. */
        uint64_t addr                  : 14; /**< [ 63: 50](R/W) The starting address of the 2^50 address space
                                                                 that is the BAR2 address space. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_p2n_bar2_start_cn81xx cn88xx; */
    /* struct bdk_pemx_p2n_bar2_start_cn9 cn83xx; */
} bdk_pemx_p2n_bar2_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR2_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR2_START(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000090ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000090ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000090ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000090ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_P2N_BAR2_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_P2N_BAR2_START(a) bdk_pemx_p2n_bar2_start_t
#define bustype_BDK_PEMX_P2N_BAR2_START(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2N_BAR2_START(a) "PEMX_P2N_BAR2_START"
#define device_bar_BDK_PEMX_P2N_BAR2_START(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_P2N_BAR2_START(a) (a)
#define arguments_BDK_PEMX_P2N_BAR2_START(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_p2p_bar#_end
 *
 * PEM Peer-to-Peer BAR0 End Register
 * This register specifies the ending address for memory requests that are to be forwarded to the
 * PCIe peer port.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_p2p_barx_end_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 52; /**< [ 63: 12](R/W) The ending address of the address window created by this field and the
                                                                 PEM_P2P_BAR0_START[63:12] field. The full 64 bits of the address are created by:
                                                                 {ADDR[63:12], 12'b0}. */
        uint64_t reserved_0_11         : 12;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_11         : 12;
        uint64_t addr                  : 52; /**< [ 63: 12](R/W) The ending address of the address window created by this field and the
                                                                 PEM_P2P_BAR0_START[63:12] field. The full 64 bits of the address are created by:
                                                                 {ADDR[63:12], 12'b0}. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_p2p_barx_end_s cn; */
} bdk_pemx_p2p_barx_end_t;

static inline uint64_t BDK_PEMX_P2P_BARX_END(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2P_BARX_END(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=3)))
        return 0x87e0c0000048ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0c0000048ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("PEMX_P2P_BARX_END", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_P2P_BARX_END(a,b) bdk_pemx_p2p_barx_end_t
#define bustype_BDK_PEMX_P2P_BARX_END(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2P_BARX_END(a,b) "PEMX_P2P_BARX_END"
#define device_bar_BDK_PEMX_P2P_BARX_END(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_P2P_BARX_END(a,b) (a)
#define arguments_BDK_PEMX_P2P_BARX_END(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_p2p_bar#_start
 *
 * PEM Peer-to-Peer BAR0 Start Register
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the PCIe peer port.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_p2p_barx_start_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 52; /**< [ 63: 12](R/W) The starting address of the address window created by this field and the
                                                                 PEM_P2P_BAR0_END[63:12] field. The full 64-bits of the address are created by:
                                                                 {ADDR[63:12], 12'b0}. */
        uint64_t reserved_2_11         : 10;
        uint64_t dst                   : 2;  /**< [  1:  0](R/W) The destination peer of the address window created by this field and the
                                                                 PEM_P2P_BAR0_END[63:12] field. It is illegal to configure the destination peer to match
                                                                 the source. */
#else /* Word 0 - Little Endian */
        uint64_t dst                   : 2;  /**< [  1:  0](R/W) The destination peer of the address window created by this field and the
                                                                 PEM_P2P_BAR0_END[63:12] field. It is illegal to configure the destination peer to match
                                                                 the source. */
        uint64_t reserved_2_11         : 10;
        uint64_t addr                  : 52; /**< [ 63: 12](R/W) The starting address of the address window created by this field and the
                                                                 PEM_P2P_BAR0_END[63:12] field. The full 64-bits of the address are created by:
                                                                 {ADDR[63:12], 12'b0}. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_p2p_barx_start_s cn; */
} bdk_pemx_p2p_barx_start_t;

static inline uint64_t BDK_PEMX_P2P_BARX_START(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2P_BARX_START(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=3)))
        return 0x87e0c0000040ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0c0000040ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("PEMX_P2P_BARX_START", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_P2P_BARX_START(a,b) bdk_pemx_p2p_barx_start_t
#define bustype_BDK_PEMX_P2P_BARX_START(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2P_BARX_START(a,b) "PEMX_P2P_BARX_START"
#define device_bar_BDK_PEMX_P2P_BARX_START(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_P2P_BARX_START(a,b) (a)
#define arguments_BDK_PEMX_P2P_BARX_START(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_qlm
 *
 * PEM QLM Configuration Register
 * This register configures the PEM QLM.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_qlm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pem_tdlm              : 1;  /**< [  0:  0](R/W/H) When set, PEM2/PEM3 is configured to send/receive traffic to TDLM5/TDLM6.
                                                                 When clear, PEM2/PEM3 is configured to send/receive traffic to QLM2(QLM3)/QLM3.
                                                                 Note that this bit can only be set for PEM2 or PEM3, for all other PEMs it has no
                                                                 function.
                                                                 Note that this bit must only be set when both the associated PHYs and PEM2/PEM3 are in
                                                                 reset.
                                                                 These conditions can be assured by setting the PEM(2/3)_ON[PEMON] bit after setting this
                                                                 bit. */
#else /* Word 0 - Little Endian */
        uint64_t pem_tdlm              : 1;  /**< [  0:  0](R/W/H) When set, PEM2/PEM3 is configured to send/receive traffic to TDLM5/TDLM6.
                                                                 When clear, PEM2/PEM3 is configured to send/receive traffic to QLM2(QLM3)/QLM3.
                                                                 Note that this bit can only be set for PEM2 or PEM3, for all other PEMs it has no
                                                                 function.
                                                                 Note that this bit must only be set when both the associated PHYs and PEM2/PEM3 are in
                                                                 reset.
                                                                 These conditions can be assured by setting the PEM(2/3)_ON[PEMON] bit after setting this
                                                                 bit. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_qlm_s cn; */
} bdk_pemx_qlm_t;

static inline uint64_t BDK_PEMX_QLM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_QLM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000418ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000418ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_QLM", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_QLM(a) bdk_pemx_qlm_t
#define bustype_BDK_PEMX_QLM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_QLM(a) "PEMX_QLM"
#define device_bar_BDK_PEMX_QLM(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_QLM(a) (a)
#define arguments_BDK_PEMX_QLM(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_ras_tba_ctl
 *
 * PEM RAS Time Based Analysis Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_ras_tba_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t tba_ctrl              : 2;  /**< [  1:  0](WO) Controls the start/end of time based analysis (TBA) in the core.  Note that TBA can also
                                                                 be controlled
                                                                 by setting the contents of PCIEEP()_CFG114/RC()_CFG114, and that TBA_CTRL will also
                                                                 affect the contents of PCIEEP()_CFG114/RC()_CFG114[TIMER_START].
                                                                 0x0 = No action.
                                                                 0x1 = Start time based analysis.
                                                                 0x2 = End time based anaylsis.
                                                                       Only used if PCIEEP()_CFG114/RC()_CFG114[TBASE_DUR_SEL] is set to manual control,
                                                                       otherwise it is ignored.
                                                                 0x3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t tba_ctrl              : 2;  /**< [  1:  0](WO) Controls the start/end of time based analysis (TBA) in the core.  Note that TBA can also
                                                                 be controlled
                                                                 by setting the contents of PCIEEP()_CFG114/RC()_CFG114, and that TBA_CTRL will also
                                                                 affect the contents of PCIEEP()_CFG114/RC()_CFG114[TIMER_START].
                                                                 0x0 = No action.
                                                                 0x1 = Start time based analysis.
                                                                 0x2 = End time based anaylsis.
                                                                       Only used if PCIEEP()_CFG114/RC()_CFG114[TBASE_DUR_SEL] is set to manual control,
                                                                       otherwise it is ignored.
                                                                 0x3 = Reserved. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_ras_tba_ctl_s cn; */
} bdk_pemx_ras_tba_ctl_t;

static inline uint64_t BDK_PEMX_RAS_TBA_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_RAS_TBA_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000240ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000240ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_RAS_TBA_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_RAS_TBA_CTL(a) bdk_pemx_ras_tba_ctl_t
#define bustype_BDK_PEMX_RAS_TBA_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_RAS_TBA_CTL(a) "PEMX_RAS_TBA_CTL"
#define device_bar_BDK_PEMX_RAS_TBA_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_RAS_TBA_CTL(a) (a)
#define arguments_BDK_PEMX_RAS_TBA_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_reads_pc
 *
 * PEM Read Count Register
 * This register contains read count for debugging purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_reads_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reads                 : 64; /**< [ 63:  0](RO/H) Total number of SLI reads from remote memory aggregated across all
                                                                 non-masked SWI tags.  Software can calculate the average read latency
                                                                 to first data per SLI read request by dividing PEM()_LATENCY_PC[LATENCY]
                                                                 by PEM()_READS_PC[READS]. */
#else /* Word 0 - Little Endian */
        uint64_t reads                 : 64; /**< [ 63:  0](RO/H) Total number of SLI reads from remote memory aggregated across all
                                                                 non-masked SWI tags.  Software can calculate the average read latency
                                                                 to first data per SLI read request by dividing PEM()_LATENCY_PC[LATENCY]
                                                                 by PEM()_READS_PC[READS]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_reads_pc_s cn; */
} bdk_pemx_reads_pc_t;

static inline uint64_t BDK_PEMX_READS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_READS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000498ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000498ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_READS_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_READS_PC(a) bdk_pemx_reads_pc_t
#define bustype_BDK_PEMX_READS_PC(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_READS_PC(a) "PEMX_READS_PC"
#define device_bar_BDK_PEMX_READS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_READS_PC(a) (a)
#define arguments_BDK_PEMX_READS_PC(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_spi_ctl
 *
 * PEM SPI Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_spi_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t start_busy            : 1;  /**< [ 15: 15](R/W) Start/busy status. Starts SPI xctn when written; reads 1 when EEPROM busy, 0 when complete. */
        uint64_t tvalid                : 1;  /**< [ 14: 14](R/W) Reads 1 if at least one valid entry was read from EEPROM and written to a CSR. Write to
                                                                 clear status. */
        uint64_t cmd                   : 3;  /**< [ 13: 11](R/W) SPI commands; WREN (110), WRDI (100), READ (011), WRITE (010), RDSR (101), WRSR (001).
                                                                 Unsupported Commands; Read Identification, Read Data at Higher Speed, Page Program,
                                                                 Sector Erase, Bulk Erase, Deep Power-down, and Release from Deep Power-Down. */
        uint64_t adr                   : 11; /**< [ 10:  0](R/W) EEPROM read/write address. */
#else /* Word 0 - Little Endian */
        uint64_t adr                   : 11; /**< [ 10:  0](R/W) EEPROM read/write address. */
        uint64_t cmd                   : 3;  /**< [ 13: 11](R/W) SPI commands; WREN (110), WRDI (100), READ (011), WRITE (010), RDSR (101), WRSR (001).
                                                                 Unsupported Commands; Read Identification, Read Data at Higher Speed, Page Program,
                                                                 Sector Erase, Bulk Erase, Deep Power-down, and Release from Deep Power-Down. */
        uint64_t tvalid                : 1;  /**< [ 14: 14](R/W) Reads 1 if at least one valid entry was read from EEPROM and written to a CSR. Write to
                                                                 clear status. */
        uint64_t start_busy            : 1;  /**< [ 15: 15](R/W) Start/busy status. Starts SPI xctn when written; reads 1 when EEPROM busy, 0 when complete. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_spi_ctl_s cn; */
} bdk_pemx_spi_ctl_t;

static inline uint64_t BDK_PEMX_SPI_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_SPI_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000180ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000180ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_SPI_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_SPI_CTL(a) bdk_pemx_spi_ctl_t
#define bustype_BDK_PEMX_SPI_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_SPI_CTL(a) "PEMX_SPI_CTL"
#define device_bar_BDK_PEMX_SPI_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_SPI_CTL(a) (a)
#define arguments_BDK_PEMX_SPI_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_spi_data
 *
 * PEM SPI Data Register
 * This register contains the most recently read or written SPI data and is unpredictable upon
 * power-up.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_spi_data_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t preamble              : 16; /**< [ 63: 48](R/W/H) EEPROM PREAMBLE read or write data. */
        uint64_t reserved_45_47        : 3;
        uint64_t cs2                   : 1;  /**< [ 44: 44](R/W/H) EEPROM CS2 read or write data bit. */
        uint64_t adr                   : 12; /**< [ 43: 32](R/W/H) EEPROM CFG ADR read or write data. */
        uint64_t data                  : 32; /**< [ 31:  0](R/W/H) EEPROM DATA read or write data. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W/H) EEPROM DATA read or write data. */
        uint64_t adr                   : 12; /**< [ 43: 32](R/W/H) EEPROM CFG ADR read or write data. */
        uint64_t cs2                   : 1;  /**< [ 44: 44](R/W/H) EEPROM CS2 read or write data bit. */
        uint64_t reserved_45_47        : 3;
        uint64_t preamble              : 16; /**< [ 63: 48](R/W/H) EEPROM PREAMBLE read or write data. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_spi_data_s cn; */
} bdk_pemx_spi_data_t;

static inline uint64_t BDK_PEMX_SPI_DATA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_SPI_DATA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000188ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000188ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_SPI_DATA", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_SPI_DATA(a) bdk_pemx_spi_data_t
#define bustype_BDK_PEMX_SPI_DATA(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_SPI_DATA(a) "PEMX_SPI_DATA"
#define device_bar_BDK_PEMX_SPI_DATA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_SPI_DATA(a) (a)
#define arguments_BDK_PEMX_SPI_DATA(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_strap
 *
 * PEM Pin Strapping Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_strap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t pilaneswap            : 1;  /**< [  3:  3](RO/H) The value of PCIE*_REV_LANES, which is captured on chip cold reset. It is not
                                                                 affected by any other reset.  When set, lane swapping is performed to/from the
                                                                 SerDes. When clear, no lane swapping is performed. */
        uint64_t pilanes8              : 1;  /**< [  2:  2](RO/H) The value of bit <2> of PCIE*_MODE<2:0>, which is captured on chip cold reset. It is not
                                                                 affected by any other reset.  When set, the PEM is configured for a maximum of
                                                                 8-lanes, When clear, the PEM is configured for a maximum of 4-lanes. */
        uint64_t pimode                : 2;  /**< [  1:  0](RO/H) The value of PCIE*_MODE<1:0>, which are captured on chip cold reset. They are
                                                                 not affected by any other reset.
                                                                 0x0 = EP mode, Gen1 speed.
                                                                 0x1 = EP mode, Gen2 speed.
                                                                 0x2 = EP mode, Gen3 speed.
                                                                 0x3 = RC mode, defaults to Gen3 speed. */
#else /* Word 0 - Little Endian */
        uint64_t pimode                : 2;  /**< [  1:  0](RO/H) The value of PCIE*_MODE<1:0>, which are captured on chip cold reset. They are
                                                                 not affected by any other reset.
                                                                 0x0 = EP mode, Gen1 speed.
                                                                 0x1 = EP mode, Gen2 speed.
                                                                 0x2 = EP mode, Gen3 speed.
                                                                 0x3 = RC mode, defaults to Gen3 speed. */
        uint64_t pilanes8              : 1;  /**< [  2:  2](RO/H) The value of bit <2> of PCIE*_MODE<2:0>, which is captured on chip cold reset. It is not
                                                                 affected by any other reset.  When set, the PEM is configured for a maximum of
                                                                 8-lanes, When clear, the PEM is configured for a maximum of 4-lanes. */
        uint64_t pilaneswap            : 1;  /**< [  3:  3](RO/H) The value of PCIE*_REV_LANES, which is captured on chip cold reset. It is not
                                                                 affected by any other reset.  When set, lane swapping is performed to/from the
                                                                 SerDes. When clear, no lane swapping is performed. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_strap_s cn; */
} bdk_pemx_strap_t;

static inline uint64_t BDK_PEMX_STRAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_STRAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000408ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000408ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_STRAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_STRAP(a) bdk_pemx_strap_t
#define bustype_BDK_PEMX_STRAP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_STRAP(a) "PEMX_STRAP"
#define device_bar_BDK_PEMX_STRAP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_STRAP(a) (a)
#define arguments_BDK_PEMX_STRAP(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_tlp_credits
 *
 * PEM TLP Credits Register
 * This register specifies the number of credits for use in moving TLPs. When this register is
 * written, the credit values are reset to the register value. A write to this register should
 * take place before traffic flow starts.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_tlp_credits_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pem_cpl               : 12; /**< [ 63: 52](R/W) TLP 16 B credits for completion TLPs in the peer. Legal values are 0x42 to 0x104. */
        uint64_t pem_np                : 8;  /**< [ 51: 44](R/W) TLP 16 B credits for nonposted TLPs in the peer. Legal values are 0x4 to 0x20. */
        uint64_t pem_p                 : 12; /**< [ 43: 32](R/W) TLP 16 B credits for posted TLPs in the peer. Legal values are 0x42 to 0x104. */
        uint64_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_31         : 32;
        uint64_t pem_p                 : 12; /**< [ 43: 32](R/W) TLP 16 B credits for posted TLPs in the peer. Legal values are 0x42 to 0x104. */
        uint64_t pem_np                : 8;  /**< [ 51: 44](R/W) TLP 16 B credits for nonposted TLPs in the peer. Legal values are 0x4 to 0x20. */
        uint64_t pem_cpl               : 12; /**< [ 63: 52](R/W) TLP 16 B credits for completion TLPs in the peer. Legal values are 0x42 to 0x104. */
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_tlp_credits_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0x80 and this
                                                                 value is not dependent of the number of PEMS wire-OR'd together. Software should
                                                                 reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x10 and this
                                                                 value is not dependent of the number of PEMS wire-OR'd together. Software should
                                                                 reprogram this register for performance reasons. */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Posted TLPs in the SLI. Legal values are 0x24 to 0x80 and this value
                                                                 is not dependent of the number of PEMS wire-OR'd together. Software should reprogram this
                                                                 register for performance reasons. */
#else /* Word 0 - Little Endian */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Posted TLPs in the SLI. Legal values are 0x24 to 0x80 and this value
                                                                 is not dependent of the number of PEMS wire-OR'd together. Software should reprogram this
                                                                 register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x10 and this
                                                                 value is not dependent of the number of PEMS wire-OR'd together. Software should
                                                                 reprogram this register for performance reasons. */
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0x80 and this
                                                                 value is not dependent of the number of PEMS wire-OR'd together. Software should
                                                                 reprogram this register for performance reasons. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pemx_tlp_credits_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pem_cpl               : 12; /**< [ 63: 52](R/W) TLP 16 B credits for completion TLPs in the peer. Legal values are 0x42 to 0x104. */
        uint64_t pem_np                : 8;  /**< [ 51: 44](R/W) TLP 16 B credits for nonposted TLPs in the peer. Legal values are 0x4 to 0x20. */
        uint64_t pem_p                 : 12; /**< [ 43: 32](R/W) TLP 16 B credits for posted TLPs in the peer. Legal values are 0x42 to 0x104. */
        uint64_t sli_cpl               : 12; /**< [ 31: 20](R/W) TLP 16 B credits for completion TLPs in the SLI. Legal values are 0x41 to 0x104
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 19: 12](R/W) TLP 16 B credits for non-posted TLPs in the SLI. Legal values are 0x3 to 0x20
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_p                 : 12; /**< [ 11:  0](R/W) TLP 16 B credits for posted TLPs in the SLI. Legal values are 0x41 to 0x104 and this value
                                                                 is not dependent of the number of PEMS wire-OR'd together. Software should reprogram this
                                                                 register for performance reasons. */
#else /* Word 0 - Little Endian */
        uint64_t sli_p                 : 12; /**< [ 11:  0](R/W) TLP 16 B credits for posted TLPs in the SLI. Legal values are 0x41 to 0x104 and this value
                                                                 is not dependent of the number of PEMS wire-OR'd together. Software should reprogram this
                                                                 register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 19: 12](R/W) TLP 16 B credits for non-posted TLPs in the SLI. Legal values are 0x3 to 0x20
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_cpl               : 12; /**< [ 31: 20](R/W) TLP 16 B credits for completion TLPs in the SLI. Legal values are 0x41 to 0x104
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t pem_p                 : 12; /**< [ 43: 32](R/W) TLP 16 B credits for posted TLPs in the peer. Legal values are 0x42 to 0x104. */
        uint64_t pem_np                : 8;  /**< [ 51: 44](R/W) TLP 16 B credits for nonposted TLPs in the peer. Legal values are 0x4 to 0x20. */
        uint64_t pem_cpl               : 12; /**< [ 63: 52](R/W) TLP 16 B credits for completion TLPs in the peer. Legal values are 0x42 to 0x104. */
#endif /* Word 0 - End */
    } cn9;
    struct bdk_pemx_tlp_credits_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0x4F
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x8 to 0x17
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0x4F
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
#else /* Word 0 - Little Endian */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0x4F
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x8 to 0x17
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0x4F
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pemx_tlp_credits_cn9 cn83xx; */
    struct bdk_pemx_tlp_credits_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16 B credits for non-posted TLPs in the SLI. Legal values are 0x4 to 0x20
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
#else /* Word 0 - Little Endian */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16 B credits for non-posted TLPs in the SLI. Legal values are 0x4 to 0x20
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pemx_tlp_credits_t;

static inline uint64_t BDK_PEMX_TLP_CREDITS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_TLP_CREDITS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0c0000038ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0c0000038ll + 0x1000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0c0000038ll + 0x1000000ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0c0000038ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("PEMX_TLP_CREDITS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_TLP_CREDITS(a) bdk_pemx_tlp_credits_t
#define bustype_BDK_PEMX_TLP_CREDITS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_TLP_CREDITS(a) "PEMX_TLP_CREDITS"
#define device_bar_BDK_PEMX_TLP_CREDITS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_PEMX_TLP_CREDITS(a) (a)
#define arguments_BDK_PEMX_TLP_CREDITS(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PEM_H__ */
