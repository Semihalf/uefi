#ifndef __BDK_CSRS_PEM_H__
#define __BDK_CSRS_PEM_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2015  Cavium Inc. (support@cavium.com). All rights
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
#define BDK_PEM_BAR_E_PEMX_PF_BAR0(a) (0x87e0c0000000ll + 0x1000000ll * (a)) /**< (0..5)Base address for standard registers. */
#define BDK_PEM_BAR_E_PEMX_PF_BAR4(a) (0x87e0c0f00000ll + 0x1000000ll * (a)) /**< (0..5)Base address for MSI-X registers. */

/**
 * Enumeration pem_int_vec_e
 *
 * PEM MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_PEM_INT_VEC_E_DBG_INFO (0xd) /**< See interrupt clears PEM(0..5)_DBG_INFO,
                                       interrupt sets PEM(0..5)_DBG_INFO_W1S,
                                       enable clears PEM(0..5)_DBG_ENA_W1C,
                                       and enable sets PEM(0..5)_DBG_ENA_W1S. */
#define BDK_PEM_INT_VEC_E_ERROR_AERI (0) /**< See PCIERC()_CFG076. */
#define BDK_PEM_INT_VEC_E_ERROR_AERI_CLEAR (1) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_ERROR_PMEI (2) /**< See PCIERC()_CFG036. */
#define BDK_PEM_INT_VEC_E_ERROR_PMEI_CLEAR (3) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_HP_INT_CN88XX (0xe) /**< PCI hot-plug interrupt set vector. Added in pass 2. */
#define BDK_PEM_INT_VEC_E_HP_INT_CN83XX (0xe) /**< PCI hot-plug interrupt set vector. */
#define BDK_PEM_INT_VEC_E_HP_INT_CLEAR_CN88XX (0xf) /**< Level sensitive interrupt clear vector. Added in pass 2. */
#define BDK_PEM_INT_VEC_E_HP_INT_CLEAR_CN83XX (0xf) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_INTA (4) /**< PCI INTA legacy interrupt set vector. */
#define BDK_PEM_INT_VEC_E_INTA_CLEAR (5) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_INTB (6) /**< PCI INTB legacy interrupt set vector. */
#define BDK_PEM_INT_VEC_E_INTB_CLEAR (7) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_INTC (8) /**< PCI INTC legacy interrupt set vector. */
#define BDK_PEM_INT_VEC_E_INTC_CLEAR (9) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_INTD (0xa) /**< PCI INTD legacy interrupt set vector. */
#define BDK_PEM_INT_VEC_E_INTD_CLEAR (0xb) /**< Level sensitive interrupt clear vector. */
#define BDK_PEM_INT_VEC_E_INT_SUM (0xc) /**< See interrupt clears PEM(0..5)_INT_SUM,
                                       interrupt sets PEM(0..5)_INT_SUM_W1S,
                                       enable clears PEM(0..5)_INT_ENA_W1C,
                                       and enable sets PEM(0..5)_INT_ENA_W1S. */

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
        uint64_t reserved_1_2          : 2;
        uint64_t addr_v                : 1;  /**< [  0:  0](R/W) Address valid. Set to 1 when the selected address range is valid. */
#else /* Word 0 - Little Endian */
        uint64_t addr_v                : 1;  /**< [  0:  0](R/W) Address valid. Set to 1 when the selected address range is valid. */
        uint64_t reserved_1_2          : 2;
        uint64_t ca                    : 1;  /**< [  3:  3](R/W) Cached. Set to 1 when access is not to be cached in L2. */
        uint64_t addr_idx              : 27; /**< [ 30:  4](R/W) Address index. Address bits [48:22] sent to L2C. */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_bar1_indexx_s cn; */
} bdk_pemx_bar1_indexx_t;

static inline uint64_t BDK_PEMX_BAR1_INDEXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR1_INDEXX(unsigned long a, unsigned long b)
{
    if ((a<=5) && (b<=15))
        return 0x87e0c0000100ll + 0x1000000ll * ((a) & 0x7) + 8ll * ((b) & 0xf);
    __bdk_csr_fatal("PEMX_BAR1_INDEXX", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_BAR1_INDEXX(a,b) bdk_pemx_bar1_indexx_t
#define bustype_BDK_PEMX_BAR1_INDEXX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BAR1_INDEXX(a,b) "PEMX_BAR1_INDEXX"
#define busnum_BDK_PEMX_BAR1_INDEXX(a,b) (a)
#define arguments_BDK_PEMX_BAR1_INDEXX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_bar2_mask
 *
 * PEM BAR2 Mask Register
 * This register contains the mask pattern that is ANDed with the address from the PCIe core for
 * BAR2 hits. This allows the effective size of RC BAR2 to be shrunk. Must not be changed
 * from its reset value in EP mode.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_bar2_mask_s
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
    } s;
    /* struct bdk_pemx_bar2_mask_s cn; */
} bdk_pemx_bar2_mask_t;

static inline uint64_t BDK_PEMX_BAR2_MASK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR2_MASK(unsigned long a)
{
    if (a<=5)
        return 0x87e0c00000b0ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_BAR2_MASK", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_BAR2_MASK(a) bdk_pemx_bar2_mask_t
#define bustype_BDK_PEMX_BAR2_MASK(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BAR2_MASK(a) "PEMX_BAR2_MASK"
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
        uint64_t reserved_7_63         : 57;
        uint64_t bar1_siz              : 3;  /**< [  6:  4](R/W) PCIe Port 0 Bar1 Size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB.
                                                                 0x2 = 128 MB.
                                                                 0x3 = 256 MB.
                                                                 0x4 = 512 MB.
                                                                 0x5 = 1024 MB.
                                                                 0x6 = 2048 MB.
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
        uint64_t bar1_siz              : 3;  /**< [  6:  4](R/W) PCIe Port 0 Bar1 Size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB.
                                                                 0x2 = 128 MB.
                                                                 0x3 = 256 MB.
                                                                 0x4 = 512 MB.
                                                                 0x5 = 1024 MB.
                                                                 0x6 = 2048 MB.
                                                                 0x7 = Reserved. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_bar_ctl_s cn; */
} bdk_pemx_bar_ctl_t;

static inline uint64_t BDK_PEMX_BAR_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR_CTL(unsigned long a)
{
    if (a<=5)
        return 0x87e0c00000a8ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_BAR_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_BAR_CTL(a) bdk_pemx_bar_ctl_t
#define bustype_BDK_PEMX_BAR_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BAR_CTL(a) "PEMX_BAR_CTL"
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
        uint64_t reserved_26_63        : 38;
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) Rx queue header memory buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) Rx queue header memory buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) Rx queue data buffer 0. */
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) Rx queue data buffer 1. */
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
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) Rx queue data buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) Rx queue data buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) Rx queue header memory buffer 1. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) Rx queue header memory buffer 0. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_bist_status_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) Rx queue header memory buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) Rx queue header memory buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) Rx queue data buffer 0. */
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) Rx queue data buffer 1. */
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
        uint64_t rqdatab1              : 1;  /**< [ 20: 20](RO) Rx queue data buffer 1. */
        uint64_t rqdatab0              : 1;  /**< [ 21: 21](RO) Rx queue data buffer 0. */
        uint64_t rqhdrb1               : 1;  /**< [ 22: 22](RO) Rx queue header memory buffer 1. */
        uint64_t rqhdrb0               : 1;  /**< [ 23: 23](RO) Rx queue header memory buffer 0. */
        uint64_t sot                   : 1;  /**< [ 24: 24](RO) Start of transfer memory. */
        uint64_t retryc                : 1;  /**< [ 25: 25](RO) Retry buffer memory C. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_pemx_bist_status_cn83xx cn88xxp2; */
    /* struct bdk_pemx_bist_status_s cn88xxp1; */
} bdk_pemx_bist_status_t;

static inline uint64_t BDK_PEMX_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BIST_STATUS(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000468ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_BIST_STATUS(a) bdk_pemx_bist_status_t
#define bustype_BDK_PEMX_BIST_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_BIST_STATUS(a) "PEMX_BIST_STATUS"
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
    } s;
    /* struct bdk_pemx_cfg_s cn; */
} bdk_pemx_cfg_t;

static inline uint64_t BDK_PEMX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000410ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CFG(a) bdk_pemx_cfg_t
#define bustype_BDK_PEMX_CFG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CFG(a) "PEMX_CFG"
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
        uint64_t addr                  : 32; /**< [ 31:  0](R/W/H) Address to read. A write to this register starts a read operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 <11:0> The offset of the PCIe core CFG register being accessed. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 32; /**< [ 31:  0](R/W/H) Address to read. A write to this register starts a read operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 <11:0> The offset of the PCIe core CFG register being accessed. */
        uint64_t data                  : 32; /**< [ 63: 32](R/W/H) Data. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_cfg_rd_s cn; */
} bdk_pemx_cfg_rd_t;

static inline uint64_t BDK_PEMX_CFG_RD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG_RD(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000030ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CFG_RD", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CFG_RD(a) bdk_pemx_cfg_rd_t
#define bustype_BDK_PEMX_CFG_RD(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CFG_RD(a) "PEMX_CFG_RD"
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
    } s;
    /* struct bdk_pemx_cfg_wr_s cn; */
} bdk_pemx_cfg_wr_t;

static inline uint64_t BDK_PEMX_CFG_WR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG_WR(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000028ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CFG_WR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CFG_WR(a) bdk_pemx_cfg_wr_t
#define bustype_BDK_PEMX_CFG_WR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CFG_WR(a) "PEMX_CFG_WR"
#define busnum_BDK_PEMX_CFG_WR(a) (a)
#define arguments_BDK_PEMX_CFG_WR(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_clk_en
 *
 * PEM3 Clock Enable Register
 * This register contains the clock enable for ECLK and PCE_CLK.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_clk_en_s
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
    } s;
    /* struct bdk_pemx_clk_en_s cn; */
} bdk_pemx_clk_en_t;

static inline uint64_t BDK_PEMX_CLK_EN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CLK_EN(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000400ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CLK_EN", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CLK_EN(a) bdk_pemx_clk_en_t
#define bustype_BDK_PEMX_CLK_EN(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CLK_EN(a) "PEMX_CLK_EN"
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
    if (a<=5)
        return 0x87e0c0000098ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CPL_LUT_VALID", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CPL_LUT_VALID(a) bdk_pemx_cpl_lut_valid_t
#define bustype_BDK_PEMX_CPL_LUT_VALID(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CPL_LUT_VALID(a) "PEMX_CPL_LUT_VALID"
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
        uint64_t reserved_51_63        : 13;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_48_49        : 2;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
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
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_49        : 2;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_ctl_status_cn83xx
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
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
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
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
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
    } cn83xx;
    struct bdk_pemx_ctl_status_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_55_63        : 9;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM. Added in pass 2 to improve
                                                                 small TLP performance. */
        uint64_t reserved_51           : 1;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_48_49        : 2;
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t reserved_32_33        : 2;
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
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
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
        uint64_t reserved_32_33        : 2;
        uint64_t pbus                  : 8;  /**< [ 41: 34](RO/H) Primary bus number. */
        uint64_t dnum                  : 5;  /**< [ 46: 42](RO/H) Primary bus device number. */
        uint64_t auto_sd               : 1;  /**< [ 47: 47](RO/H) Link hardware autonomous speed disable. */
        uint64_t reserved_48_49        : 2;
        uint64_t inv_dpar              : 1;  /**< [ 50: 50](R/W) Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
        uint64_t reserved_51           : 1;
        uint64_t inb_grant_limit       : 3;  /**< [ 54: 52](R/W) The number of inbound TLPs allowed in flight in PEM. Added in pass 2 to improve
                                                                 small TLP performance. */
        uint64_t reserved_55_63        : 9;
#endif /* Word 0 - End */
    } cn88xxp2;
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
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
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
        uint64_t cfg_rtry              : 16; /**< [ 31: 16](R/W) The time times 0x10000 coprocessor-clocks to wait for a CPL to a configuration
                                                                 read that does not carry a retry status. Until such time that the timeout occurs
                                                                 and retry status is received for a configuration read, the read will be
                                                                 resent. A value of 0 disables retries and treats a CPL Retry as a CPL UR.

                                                                 To use, it is recommended CFG_RTRY be set value corresponding to 200ms or less, although
                                                                 the PCI Express Base Specification allows up to 900ms for a device to send a successful
                                                                 completion.  When enabled, only one CFG RD may be issued until either successful
                                                                 completion or CPL UR. */
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
} bdk_pemx_ctl_status_t;

static inline uint64_t BDK_PEMX_CTL_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CTL_STATUS(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000000ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CTL_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CTL_STATUS(a) bdk_pemx_ctl_status_t
#define bustype_BDK_PEMX_CTL_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CTL_STATUS(a) "PEMX_CTL_STATUS"
#define busnum_BDK_PEMX_CTL_STATUS(a) (a)
#define arguments_BDK_PEMX_CTL_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) pem#_ctl_status2
 *
 * PEM Diagnostic Status Register
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
    if (a<=5)
        return 0x87e0c0000008ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_CTL_STATUS2", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_CTL_STATUS2(a) bdk_pemx_ctl_status2_t
#define bustype_BDK_PEMX_CTL_STATUS2(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_CTL_STATUS2(a) "PEMX_CTL_STATUS2"
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
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
    } s;
    struct bdk_pemx_dbg_ena_w1c_cn83xx
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
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
    } cn83xx;
    struct bdk_pemx_dbg_ena_w1c_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Added in pass 2.0. Reads or clears enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
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
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Added in pass 2.0. Reads or clears enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_dbg_ena_w1c_s cn88xxp1; */
} bdk_pemx_dbg_ena_w1c_t;

static inline uint64_t BDK_PEMX_DBG_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_ENA_W1C(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000458ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_DBG_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_ENA_W1C(a) bdk_pemx_dbg_ena_w1c_t
#define bustype_BDK_PEMX_DBG_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_ENA_W1C(a) "PEMX_DBG_ENA_W1C"
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
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
    } s;
    struct bdk_pemx_dbg_ena_w1s_cn83xx
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
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
    } cn83xx;
    struct bdk_pemx_dbg_ena_w1s_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Added in pass 2.0. Reads or sets enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for PEM(0..5)_DBG_INFO[RAWWPP]. */
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
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Added in pass 2.0. Reads or sets enable for PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_dbg_ena_w1s_s cn88xxp1; */
} bdk_pemx_dbg_ena_w1s_t;

static inline uint64_t BDK_PEMX_DBG_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_ENA_W1S(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000460ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_DBG_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_ENA_W1S(a) bdk_pemx_dbg_ena_w1s_t
#define bustype_BDK_PEMX_DBG_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_ENA_W1S(a) "PEMX_DBG_ENA_W1S"
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload. INTERNAL: radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload. INTERNAL: radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP. INTERNAL: radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support. INTERNAL: radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status. INTERNAL: radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status. INTERNAL: radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion. INTERNAL: radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. INTERNAL: radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation. INTERNAL: (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8B/10B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7). INTERNAL: rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer). INTERNAL: rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP). INTERNAL: rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error. INTERNAL: rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error. INTERNAL: rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded. INTERNAL: xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.
                                                                 INTERNAL: xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred. INTERNAL: pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message. INTERNAL: pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only). INTERNAL: pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only). INTERNAL: pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. INTERNAL: pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only). INTERNAL: pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only). INTERNAL: pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP. INTERNAL: pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error. INTERNAL: pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error. INTERNAL: pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 INTERNAL: pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. INTERNAL: peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. INTERNAL: peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 INTERNAL: pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error. INTERNAL: pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error. INTERNAL: pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP. INTERNAL: pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only). INTERNAL: pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only). INTERNAL: pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. INTERNAL: pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only). INTERNAL: pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only). INTERNAL: pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message. INTERNAL: pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred. INTERNAL: pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.
                                                                 INTERNAL: xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded. INTERNAL: xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error. INTERNAL: rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error. INTERNAL: rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP). INTERNAL: rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer). INTERNAL: rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8B/10B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7). INTERNAL: rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation. INTERNAL: (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. INTERNAL: radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion. INTERNAL: radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status. INTERNAL: radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status. INTERNAL: radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support. INTERNAL: radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP. INTERNAL: radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload. INTERNAL: radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload. INTERNAL: radm_rcvd_wreq_poisoned. */
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
    } s;
    struct bdk_pemx_dbg_info_cn83xx
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload. INTERNAL: radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload. INTERNAL: radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP. INTERNAL: radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support. INTERNAL: radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status. INTERNAL: radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status. INTERNAL: radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion. INTERNAL: radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. INTERNAL: radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation. INTERNAL: (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8B/10B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7). INTERNAL: rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer). INTERNAL: rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP). INTERNAL: rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error. INTERNAL: rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error. INTERNAL: rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded. INTERNAL: xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.
                                                                 INTERNAL: xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred. INTERNAL: pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message. INTERNAL: pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only). INTERNAL: pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only). INTERNAL: pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. INTERNAL: pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only). INTERNAL: pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only). INTERNAL: pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP. INTERNAL: pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error. INTERNAL: pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error. INTERNAL: pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 INTERNAL: pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. INTERNAL: peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. INTERNAL: peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 INTERNAL: pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error. INTERNAL: pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error. INTERNAL: pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP. INTERNAL: pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only). INTERNAL: pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only). INTERNAL: pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. INTERNAL: pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only). INTERNAL: pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only). INTERNAL: pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message. INTERNAL: pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred. INTERNAL: pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.
                                                                 INTERNAL: xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded. INTERNAL: xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error. INTERNAL: rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error. INTERNAL: rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP). INTERNAL: rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer). INTERNAL: rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8B/10B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7). INTERNAL: rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation. INTERNAL: (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. INTERNAL: radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion. INTERNAL: radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status. INTERNAL: radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status. INTERNAL: radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support. INTERNAL: radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP. INTERNAL: radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload. INTERNAL: radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload. INTERNAL: radm_rcvd_wreq_poisoned. */
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
    } cn83xx;
    struct bdk_pemx_dbg_info_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Detected a M2S FIFO parity error. Added in pass 2. */
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload. INTERNAL: radm_rcvd_wreq_poisoned. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload. INTERNAL: radm_rcvd_cpl_poisoned. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP. INTERNAL: radm_mlf_tlp_err. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support. INTERNAL: radm_rcvd_ur_req. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status. INTERNAL: radm_rcvd_cpl_ca. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status. INTERNAL: radm_rcvd_cpl_ur. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion. INTERNAL: radm_unexp_cpl_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. INTERNAL: radm_qoverflow. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation. INTERNAL: (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8B/10B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7). INTERNAL: rmlh_rcvd_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer). INTERNAL: rtlh_fc_prot_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP). INTERNAL: rdlh_prot_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error. INTERNAL: rdlh_bad_tlp_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error. INTERNAL: rdlh_bad_dllp_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded. INTERNAL: xdlh_replay_num_rlover_err. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.
                                                                 INTERNAL: xdlh_replay_timeout_err. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred. INTERNAL: pedc_radm_cpl_timeout. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message. INTERNAL: pedc_radm_vendor_msg. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only). INTERNAL: pedc_radm_pm_to_ack. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only). INTERNAL: pedc_radm_pm_pme. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. INTERNAL: pedc_radm_fatal_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only). INTERNAL: pedc_radm_nonfatal_err. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only). INTERNAL: pedc_radm_correctable_err. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP. INTERNAL: pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error. INTERNAL: pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error. INTERNAL: pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 INTERNAL: pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. INTERNAL: peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1C/H) Poisoned TLP sent. INTERNAL: peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1C/H) Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 INTERNAL: pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1C/H) Received TLP has link layer error. INTERNAL: pedc_radm_trgt1_dllp_abort &
                                                                 pedc__radm_trgt1_eot. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1C/H) Received ECRC error. INTERNAL: pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1C/H) Received poisoned TLP. INTERNAL: pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1C/H) Received correctable error message (RC mode only). INTERNAL: pedc_radm_correctable_err. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1C/H) Received nonfatal error message (RC mode only). INTERNAL: pedc_radm_nonfatal_err. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1C/H) Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. INTERNAL: pedc_radm_fatal_err. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1C/H) Received PME message (RC mode only). INTERNAL: pedc_radm_pm_pme. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1C/H) Received PME turnoff acknowledge message (RC mode only). INTERNAL: pedc_radm_pm_to_ack. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1C/H) Received vendor-defined message. INTERNAL: pedc_radm_vendor_msg. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1C/H) A completion timeout occurred. INTERNAL: pedc_radm_cpl_timeout. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1C/H) Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load.
                                                                 INTERNAL: xdlh_replay_timeout_err. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1C/H) Maximum number of retries exceeded. INTERNAL: xdlh_replay_num_rlover_err. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1C/H) Received DLLP with datalink layer error. INTERNAL: rdlh_bad_dllp_err. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1C/H) Received TLP with datalink layer error. INTERNAL: rdlh_bad_tlp_err. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1C/H) DLLP protocol error (out of sequence DLLP). INTERNAL: rdlh_prot_err. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1C/H) Flow control protocol violation (watchdog timer). INTERNAL: rtlh_fc_prot_err. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1C/H) PHY reported an 8B/10B decode error (RxStatus = 0x4) or disparity error (RxStatus =
                                                                 0x7). INTERNAL: rmlh_rcvd_err. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1C/H) Flow control update violation. INTERNAL: (opt. checks) int_xadm_fc_prot_err. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1C/H) Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. INTERNAL: radm_qoverflow. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1C/H) Received an unexpected completion. INTERNAL: radm_unexp_cpl_err. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1C/H) Received a completion with UR status. INTERNAL: radm_rcvd_cpl_ur. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1C/H) Received a completion with CA status. INTERNAL: radm_rcvd_cpl_ca. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1C/H) Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1C/H) Received a request which device does not support. INTERNAL: radm_rcvd_ur_req. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1C/H) Received a malformed TLP. INTERNAL: radm_mlf_tlp_err. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1C/H) Received a completion with poisoned payload. INTERNAL: radm_rcvd_cpl_poisoned. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1C/H) Received a write with poisoned payload. INTERNAL: radm_rcvd_wreq_poisoned. */
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
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1C/H) Detected a M2S FIFO parity error. Added in pass 2. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_dbg_info_s cn88xxp1; */
} bdk_pemx_dbg_info_t;

static inline uint64_t BDK_PEMX_DBG_INFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_INFO(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000448ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_DBG_INFO", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_INFO(a) bdk_pemx_dbg_info_t
#define bustype_BDK_PEMX_DBG_INFO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_INFO(a) "PEMX_DBG_INFO"
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP]. */
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
    } s;
    struct bdk_pemx_dbg_info_w1s_cn83xx
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP]. */
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
    } cn83xx;
    struct bdk_pemx_dbg_info_w1s_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Added in pass 2.0. Reads or sets PEM(0..5)_DBG_INFO[M2S_PE]. */
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
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t reserved_10           : 1;
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON]. */
#else /* Word 0 - Little Endian */
        uint64_t spoison               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[SPOISON]. */
        uint64_t rtlpmal               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPMAL]. */
        uint64_t rtlplle               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTLPLLE]. */
        uint64_t recrce                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RECRCE]. */
        uint64_t rpoison               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPOISON]. */
        uint64_t rcemrc                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RCEMRC]. */
        uint64_t rnfemrc               : 1;  /**< [  6:  6](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RNFEMRC]. */
        uint64_t rfemrc                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RFEMRC]. */
        uint64_t rpmerc                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPMERC]. */
        uint64_t rptamrc               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPTAMRC]. */
        uint64_t reserved_10           : 1;
        uint64_t rvdm                  : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RVDM]. */
        uint64_t acto                  : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[ACTO]. */
        uint64_t rte                   : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTE]. */
        uint64_t mre                   : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[MRE]. */
        uint64_t rdwdle                : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RDWDLE]. */
        uint64_t rtwdle                : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RTWDLE]. */
        uint64_t dpeoosd               : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[DPEOOSD]. */
        uint64_t fcpvwt                : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCPVWT]. */
        uint64_t rpe                   : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RPE]. */
        uint64_t fcuv                  : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[FCUV]. */
        uint64_t rqo                   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RQO]. */
        uint64_t rauc                  : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAUC]. */
        uint64_t racur                 : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACUR]. */
        uint64_t racca                 : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACCA]. */
        uint64_t caar                  : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[CAAR]. */
        uint64_t rarwdns               : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RARWDNS]. */
        uint64_t ramtlp                : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAMTLP]. */
        uint64_t racpp                 : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RACPP]. */
        uint64_t rawwpp                : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets PEM(0..5)_DBG_INFO[RAWWPP]. */
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
        uint64_t m2s_pe                : 1;  /**< [ 57: 57](R/W1S/H) Added in pass 2.0. Reads or sets PEM(0..5)_DBG_INFO[M2S_PE]. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_dbg_info_w1s_s cn88xxp1; */
} bdk_pemx_dbg_info_w1s_t;

static inline uint64_t BDK_PEMX_DBG_INFO_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_INFO_W1S(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000450ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_DBG_INFO_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DBG_INFO_W1S(a) bdk_pemx_dbg_info_w1s_t
#define bustype_BDK_PEMX_DBG_INFO_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DBG_INFO_W1S(a) "PEMX_DBG_INFO_W1S"
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
        uint64_t reserved_7_63         : 57;
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_debug_cn83xx
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
    } cn83xx;
    struct bdk_pemx_debug_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t inv_m2s_par           : 1;  /**< [  7:  7](R/W) Invert the generated parity to be written into the M2S FIFO
                                                                 to force a parity error when it is later read. Added in pass 2. */
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t intval                : 7;  /**< [  6:  0](RO/H) Status of INTX, PMEI, and AERI interrupts. */
        uint64_t inv_m2s_par           : 1;  /**< [  7:  7](R/W) Invert the generated parity to be written into the M2S FIFO
                                                                 to force a parity error when it is later read. Added in pass 2. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_debug_s cn88xxp1; */
} bdk_pemx_debug_t;

static inline uint64_t BDK_PEMX_DEBUG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DEBUG(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000480ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_DEBUG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DEBUG(a) bdk_pemx_debug_t
#define bustype_BDK_PEMX_DEBUG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DEBUG(a) "PEMX_DEBUG"
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
        uint64_t aux_en                : 1;  /**< [  0:  0](RO) Auxiliary power enable. Always read as zero as auxiliary power is not supported. */
#else /* Word 0 - Little Endian */
        uint64_t aux_en                : 1;  /**< [  0:  0](RO) Auxiliary power enable. Always read as zero as auxiliary power is not supported. */
        uint64_t pm_en                 : 1;  /**< [  1:  1](RO) Power management event enable. */
        uint64_t pm_stat               : 1;  /**< [  2:  2](RO) Power management status. */
        uint64_t pm_dst                : 3;  /**< [  5:  3](RO/H) Current power management DSTATE. */
        uint64_t pwrdwn                : 3;  /**< [  8:  6](RO/H) Current mac_phy_powerdown state. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_diag_status_s cn; */
} bdk_pemx_diag_status_t;

static inline uint64_t BDK_PEMX_DIAG_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DIAG_STATUS(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000020ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_DIAG_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_DIAG_STATUS(a) bdk_pemx_diag_status_t
#define bustype_BDK_PEMX_DIAG_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_DIAG_STATUS(a) "PEMX_DIAG_STATUS"
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
    } s;
    /* struct bdk_pemx_ecc_ena_s cn; */
} bdk_pemx_ecc_ena_t;

static inline uint64_t BDK_PEMX_ECC_ENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECC_ENA(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000470ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_ECC_ENA", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ECC_ENA(a) bdk_pemx_ecc_ena_t
#define bustype_BDK_PEMX_ECC_ENA(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ECC_ENA(a) "PEMX_ECC_ENA"
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
    } s;
    /* struct bdk_pemx_ecc_synd_ctrl_s cn; */
} bdk_pemx_ecc_synd_ctrl_t;

static inline uint64_t BDK_PEMX_ECC_SYND_CTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECC_SYND_CTRL(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000478ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_ECC_SYND_CTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ECC_SYND_CTRL(a) bdk_pemx_ecc_synd_ctrl_t
#define bustype_BDK_PEMX_ECC_SYND_CTRL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ECC_SYND_CTRL(a) "PEMX_ECC_SYND_CTRL"
#define busnum_BDK_PEMX_ECC_SYND_CTRL(a) (a)
#define arguments_BDK_PEMX_ECC_SYND_CTRL(a) (a),-1,-1,-1

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
                                                                 2; maximum number is 64. */
#else /* Word 0 - Little Endian */
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 2; maximum number is 64. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    struct bdk_pemx_inb_read_credits_cn83xx
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
    } cn83xx;
    struct bdk_pemx_inb_read_credits_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 6 (changed for pass 2); maximum number is 64. */
#else /* Word 0 - Little Endian */
        uint64_t num                   : 7;  /**< [  6:  0](R/W) The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 6 (changed for pass 2); maximum number is 64. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_inb_read_credits_s cn88xxp1; */
} bdk_pemx_inb_read_credits_t;

static inline uint64_t BDK_PEMX_INB_READ_CREDITS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INB_READ_CREDITS(unsigned long a)
{
    if (a<=5)
        return 0x87e0c00000b8ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_INB_READ_CREDITS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INB_READ_CREDITS(a) bdk_pemx_inb_read_credits_t
#define bustype_BDK_PEMX_INB_READ_CREDITS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INB_READ_CREDITS(a) "PEMX_INB_READ_CREDITS"
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
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[SE]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PEM(0..5)_INT_SUM[SE]. */
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
    } s;
    /* struct bdk_pemx_int_ena_w1c_s cn; */
} bdk_pemx_int_ena_w1c_t;

static inline uint64_t BDK_PEMX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_ENA_W1C(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000438ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_ENA_W1C(a) bdk_pemx_int_ena_w1c_t
#define bustype_BDK_PEMX_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_ENA_W1C(a) "PEMX_INT_ENA_W1C"
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
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[SE]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PEM(0..5)_INT_SUM[SE]. */
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
    } s;
    /* struct bdk_pemx_int_ena_w1s_s cn; */
} bdk_pemx_int_ena_w1s_t;

static inline uint64_t BDK_PEMX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_ENA_W1S(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000440ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_ENA_W1S(a) bdk_pemx_int_ena_w1s_t
#define bustype_BDK_PEMX_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_ENA_W1S(a) "PEMX_INT_ENA_W1S"
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
        uint64_t reserved_2_3          : 2;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) System error, RC mode only.  (cfg_sys_err_rc) */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1C/H) System error, RC mode only.  (cfg_sys_err_rc) */
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
    } s;
    /* struct bdk_pemx_int_sum_s cn; */
} bdk_pemx_int_sum_t;

static inline uint64_t BDK_PEMX_INT_SUM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_SUM(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000428ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_INT_SUM", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_SUM(a) bdk_pemx_int_sum_t
#define bustype_BDK_PEMX_INT_SUM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_SUM(a) "PEMX_INT_SUM"
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
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[SE]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t se                    : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PEM(0..5)_INT_SUM[SE]. */
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
    } s;
    /* struct bdk_pemx_int_sum_w1s_s cn; */
} bdk_pemx_int_sum_w1s_t;

static inline uint64_t BDK_PEMX_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_SUM_W1S(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000430ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_INT_SUM_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_INT_SUM_W1S(a) bdk_pemx_int_sum_w1s_t
#define bustype_BDK_PEMX_INT_SUM_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_INT_SUM_W1S(a) "PEMX_INT_SUM_W1S"
#define busnum_BDK_PEMX_INT_SUM_W1S(a) (a)
#define arguments_BDK_PEMX_INT_SUM_W1S(a) (a),-1,-1,-1

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
    if ((a<=5) && (b==0))
        return 0x87e0c0ff0000ll + 0x1000000ll * ((a) & 0x7) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("PEMX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_MSIX_PBAX(a,b) bdk_pemx_msix_pbax_t
#define bustype_BDK_PEMX_MSIX_PBAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_MSIX_PBAX(a,b) "PEMX_MSIX_PBAX"
#define busnum_BDK_PEMX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_PEMX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_msix_vec#_addr
 *
 * PEM MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the PEM_INT_VEC_E enumeration.
 * Changed in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_pemx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_PEM(0..5)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_PEM(0..5)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_msix_vecx_addr_s cn; */
} bdk_pemx_msix_vecx_addr_t;

static inline uint64_t BDK_PEMX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=5) && (b<=15)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((a<=5) && (b<=13)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=5) && (b<=15)))
        return 0x87e0c0f00000ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("PEMX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_MSIX_VECX_ADDR(a,b) bdk_pemx_msix_vecx_addr_t
#define bustype_BDK_PEMX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_MSIX_VECX_ADDR(a,b) "PEMX_MSIX_VECX_ADDR"
#define busnum_BDK_PEMX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_PEMX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_msix_vec#_ctl
 *
 * PEM MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the PEM_INT_VEC_E enumeration.
 * Changed in pass 2.
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=5) && (b<=15)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((a<=5) && (b<=13)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=5) && (b<=15)))
        return 0x87e0c0f00008ll + 0x1000000ll * ((a) & 0x7) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("PEMX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_PEMX_MSIX_VECX_CTL(a,b) bdk_pemx_msix_vecx_ctl_t
#define bustype_BDK_PEMX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_MSIX_VECX_CTL(a,b) "PEMX_MSIX_VECX_CTL"
#define busnum_BDK_PEMX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_PEMX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) pem#_on
 *
 * PEM3 On Status Register
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
        uint64_t pemon                 : 1;  /**< [  0:  0](R/W/H) Indication to the QLM that the PEM is out of reset, configured, and ready to send/receive
                                                                 traffic. Setting this bit takes the configured PIPE out of reset. */
#else /* Word 0 - Little Endian */
        uint64_t pemon                 : 1;  /**< [  0:  0](R/W/H) Indication to the QLM that the PEM is out of reset, configured, and ready to send/receive
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
    if (a<=5)
        return 0x87e0c0000420ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_ON", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_ON(a) bdk_pemx_on_t
#define bustype_BDK_PEMX_ON(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_ON(a) "PEMX_ON"
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
        uint64_t addr                  : 50; /**< [ 63: 14](R/W) The starting address of the 16KB BAR0 address space. */
        uint64_t reserved_0_13         : 14;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_13         : 14;
        uint64_t addr                  : 50; /**< [ 63: 14](R/W) The starting address of the 16KB BAR0 address space. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_p2n_bar0_start_s cn; */
} bdk_pemx_p2n_bar0_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR0_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR0_START(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000080ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_P2N_BAR0_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_P2N_BAR0_START(a) bdk_pemx_p2n_bar0_start_t
#define bustype_BDK_PEMX_P2N_BAR0_START(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2N_BAR0_START(a) "PEMX_P2N_BAR0_START"
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
        uint64_t addr                  : 38; /**< [ 63: 26](R/W) The starting address of the 64MB BAR1 address space. */
        uint64_t reserved_0_25         : 26;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_25         : 26;
        uint64_t addr                  : 38; /**< [ 63: 26](R/W) The starting address of the 64MB BAR1 address space. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pemx_p2n_bar1_start_s cn; */
} bdk_pemx_p2n_bar1_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR1_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR1_START(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000088ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_P2N_BAR1_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_P2N_BAR1_START(a) bdk_pemx_p2n_bar1_start_t
#define bustype_BDK_PEMX_P2N_BAR1_START(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2N_BAR1_START(a) "PEMX_P2N_BAR1_START"
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
    } s;
    /* struct bdk_pemx_p2n_bar2_start_s cn; */
} bdk_pemx_p2n_bar2_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR2_START(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR2_START(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000090ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_P2N_BAR2_START", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_P2N_BAR2_START(a) bdk_pemx_p2n_bar2_start_t
#define bustype_BDK_PEMX_P2N_BAR2_START(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_P2N_BAR2_START(a) "PEMX_P2N_BAR2_START"
#define busnum_BDK_PEMX_P2N_BAR2_START(a) (a)
#define arguments_BDK_PEMX_P2N_BAR2_START(a) (a),-1,-1,-1

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
    } s;
    struct bdk_pemx_tlp_credits_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x20
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
#else /* Word 0 - Little Endian */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x20
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn83xx;
    struct bdk_pemx_tlp_credits_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 (changed for pass 2) and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x20
                                                                 (changed for pass 2) and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 (changed for pass 2) and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
#else /* Word 0 - Little Endian */
        uint64_t sli_p                 : 8;  /**< [  7:  0](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 (changed for pass 2) and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_np                : 8;  /**< [ 15:  8](R/W) TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x20
                                                                 (changed for pass 2) and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t sli_cpl               : 8;  /**< [ 23: 16](R/W) TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0xff
                                                                 (changed for pass 2) and this value is not dependent of the number of PEMS wire-OR'd
                                                                 together. Software should reprogram this register for performance reasons. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn88xxp2;
    /* struct bdk_pemx_tlp_credits_s cn88xxp1; */
} bdk_pemx_tlp_credits_t;

static inline uint64_t BDK_PEMX_TLP_CREDITS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_TLP_CREDITS(unsigned long a)
{
    if (a<=5)
        return 0x87e0c0000038ll + 0x1000000ll * ((a) & 0x7);
    __bdk_csr_fatal("PEMX_TLP_CREDITS", 1, a, 0, 0, 0);
}

#define typedef_BDK_PEMX_TLP_CREDITS(a) bdk_pemx_tlp_credits_t
#define bustype_BDK_PEMX_TLP_CREDITS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PEMX_TLP_CREDITS(a) "PEMX_TLP_CREDITS"
#define busnum_BDK_PEMX_TLP_CREDITS(a) (a)
#define arguments_BDK_PEMX_TLP_CREDITS(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PEM_H__ */
