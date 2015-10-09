#ifndef __BDK_CSRS_BCH_H__
#define __BDK_CSRS_BCH_H__
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
 * Cavium BCH.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration bch_bar_e
 *
 * BCH Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_BCH_BAR_E_BCH_PF_BAR0 (0x871000000000ll) /**< Base address for standard registers. */
#define BDK_BCH_BAR_E_BCH_PF_BAR4 (0x871000f00000ll) /**< Base address for MSI-X registers. */
#define BDK_BCH_BAR_E_BCH_VFX_BAR0(a) (0x871001000000ll + 0x100000ll * (a)) /**< Base address for standard registers. */

/**
 * Enumeration bch_int_vec_e
 *
 * BCH MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_BCH_INT_VEC_E_ERR (0) /**< See interrupt clears BCH_ERR_INT, interrupt sets BCH_ERR_INT_W1S, enable clears
                                       BCH_ERR_INT_ENA_W1C, and enable sets BCH_ERR_INT_ENA_W1S. */

/**
 * Structure bch_cword_s
 *
 * BCH Command Instruction Word Structure
 */
union bdk_bch_cword_s
{
    uint64_t u;
    struct bdk_bch_cword_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ecc_gen               : 1;  /**< [ 63: 63] Indicates the BCH function:
                                                                   0 = Perform a block correction.
                                                                   1 = Perform a parity generation. */
        uint64_t reserved_36_62        : 27;
        uint64_t ecc_level             : 4;  /**< [ 35: 32] Indicates the maximum number of errors within a data block that can be corrected.
                                                                 The number of parity bytes is equal to ceiling(15 * [ECC_LEVEL])/8.
                                                                 Must be 4, 8, 16, 24, 32, 40, 48, 56, 60, or 64. */
        uint64_t reserved_12_31        : 20;
        uint64_t size                  : 12; /**< [ 11:  0] Indicates the size in bytes of the data block. SIZE must be a multiple of two
                                                                 bytes (i.e. [SIZE]<0> must be 0). */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 12; /**< [ 11:  0] Indicates the size in bytes of the data block. SIZE must be a multiple of two
                                                                 bytes (i.e. [SIZE]<0> must be 0). */
        uint64_t reserved_12_31        : 20;
        uint64_t ecc_level             : 4;  /**< [ 35: 32] Indicates the maximum number of errors within a data block that can be corrected.
                                                                 The number of parity bytes is equal to ceiling(15 * [ECC_LEVEL])/8.
                                                                 Must be 4, 8, 16, 24, 32, 40, 48, 56, 60, or 64. */
        uint64_t reserved_36_62        : 27;
        uint64_t ecc_gen               : 1;  /**< [ 63: 63] Indicates the BCH function:
                                                                   0 = Perform a block correction.
                                                                   1 = Perform a parity generation. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_cword_s_s cn; */
};

/**
 * Structure bch_iword_s
 *
 * BCH Input Instruction Word Structure
 */
union bdk_bch_iword_s
{
    uint64_t u;
    struct bdk_bch_iword_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_57_63        : 7;
        uint64_t nc                    : 1;  /**< [ 56: 56] When set, indicates that BCH should not allocate L2 cache space for the input
                                                                 data on L2 cache misses. */
        uint64_t reserved_49_55        : 7;
        uint64_t ptr                   : 49; /**< [ 48:  0] Indicates the starting IOVA of input data in L2/DRAM. PTR must be naturally
                                                                 aligned on an eight-byte boundary (i.e. <2:0> must be 0s). */
#else /* Word 0 - Little Endian */
        uint64_t ptr                   : 49; /**< [ 48:  0] Indicates the starting IOVA of input data in L2/DRAM. PTR must be naturally
                                                                 aligned on an eight-byte boundary (i.e. <2:0> must be 0s). */
        uint64_t reserved_49_55        : 7;
        uint64_t nc                    : 1;  /**< [ 56: 56] When set, indicates that BCH should not allocate L2 cache space for the input
                                                                 data on L2 cache misses. */
        uint64_t reserved_57_63        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_iword_s_s cn; */
};

/**
 * Structure bch_oword_s
 *
 * BCH Output Instruction Word Structure
 */
union bdk_bch_oword_s
{
    uint64_t u;
    struct bdk_bch_oword_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t fw                    : 1;  /**< [ 57: 57] When set, indicates that BCH can modify any byte in any (128-byte) cache line
                                                                 touched by L2/DRAM addresses BCH_OWORD_S[PTR] through BCH_OWORD_S[PTR] + SIZE -
                                                                 1, where SIZE is BCH_CWORD_S[SIZE] when BCH_CWORD_S[ECC_GEN] = 0, else SIZE is
                                                                 the number of parity bytes selected by BCH_CWORD_S[ECC_LEVEL]. Setting FW can
                                                                 improve hardware performance, as some DRAM load operations can be avoided on L2
                                                                 cache misses. */
        uint64_t nc                    : 1;  /**< [ 56: 56] When set, indicates that BCH should not allocate L2 cache space for the parity/
                                                                 correction data on L2 cache misses. */
        uint64_t reserved_49_55        : 7;
        uint64_t ptr                   : 49; /**< [ 48:  0] Indicates the starting IOVA of the L2/DRAM buffer that will receive the
                                                                 parity/correction data. PTR must be naturally-aligned on an eight-byte boundary
                                                                 (i.e. <2:0> must be 0s). */
#else /* Word 0 - Little Endian */
        uint64_t ptr                   : 49; /**< [ 48:  0] Indicates the starting IOVA of the L2/DRAM buffer that will receive the
                                                                 parity/correction data. PTR must be naturally-aligned on an eight-byte boundary
                                                                 (i.e. <2:0> must be 0s). */
        uint64_t reserved_49_55        : 7;
        uint64_t nc                    : 1;  /**< [ 56: 56] When set, indicates that BCH should not allocate L2 cache space for the parity/
                                                                 correction data on L2 cache misses. */
        uint64_t fw                    : 1;  /**< [ 57: 57] When set, indicates that BCH can modify any byte in any (128-byte) cache line
                                                                 touched by L2/DRAM addresses BCH_OWORD_S[PTR] through BCH_OWORD_S[PTR] + SIZE -
                                                                 1, where SIZE is BCH_CWORD_S[SIZE] when BCH_CWORD_S[ECC_GEN] = 0, else SIZE is
                                                                 the number of parity bytes selected by BCH_CWORD_S[ECC_LEVEL]. Setting FW can
                                                                 improve hardware performance, as some DRAM load operations can be avoided on L2
                                                                 cache misses. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_oword_s_s cn; */
};

/**
 * Structure bch_res_s
 *
 * BCH Result Structure
 */
union bdk_bch_res_s
{
    uint32_t u;
    struct bdk_bch_res_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t done                  : 1;  /**< [ 15: 15] Done. */
        uint32_t uncorr                : 1;  /**< [ 14: 14] Uncorrectable error. */
        uint32_t erased                : 1;  /**< [ 13: 13] Erased. */
        uint32_t reserved_7_12         : 6;
        uint32_t num_errors            : 7;  /**< [  6:  0] Number of errors. */
#else /* Word 0 - Little Endian */
        uint32_t num_errors            : 7;  /**< [  6:  0] Number of errors. */
        uint32_t reserved_7_12         : 6;
        uint32_t erased                : 1;  /**< [ 13: 13] Erased. */
        uint32_t uncorr                : 1;  /**< [ 14: 14] Uncorrectable error. */
        uint32_t done                  : 1;  /**< [ 15: 15] Done. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_res_s_s cn; */
};

/**
 * Structure bch_rword_s
 *
 * BCH Result Instruction Word Structure
 */
union bdk_bch_rword_s
{
    uint64_t u;
    struct bdk_bch_rword_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 49; /**< [ 48:  0] Indicates the starting IOVA of the L2/DRAM buffer that will receive the
                                                                 2-byte BCH_RES_S. PTR must be naturally-aligned on an two boundary
                                                                 (i.e. <0> must be 0s). */
#else /* Word 0 - Little Endian */
        uint64_t ptr                   : 49; /**< [ 48:  0] Indicates the starting IOVA of the L2/DRAM buffer that will receive the
                                                                 2-byte BCH_RES_S. PTR must be naturally-aligned on an two boundary
                                                                 (i.e. <0> must be 0s). */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_rword_s_s cn; */
};

/**
 * Register (NCB) bch_bist_result
 *
 * BCH PF BIST Result Register
 * This register provides access to internal BIST results. Each bit is the BIST result of an
 * individual memory (per bit, 0 = pass, 1 = fail).
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_bist_result_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t ncb_oub               : 1;  /**< [  5:  5](RO) BIST result of the NCB_OUB memories. */
        uint64_t ncb_inb               : 1;  /**< [  4:  4](RO) BIST result of the NCB_INB memories. */
        uint64_t dat                   : 4;  /**< [  3:  0](RO) BIST result of the DAT memories. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 4;  /**< [  3:  0](RO) BIST result of the DAT memories. */
        uint64_t ncb_inb               : 1;  /**< [  4:  4](RO) BIST result of the NCB_INB memories. */
        uint64_t ncb_oub               : 1;  /**< [  5:  5](RO) BIST result of the NCB_OUB memories. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_bist_result_s cn; */
} bdk_bch_bist_result_t;

#define BDK_BCH_BIST_RESULT BDK_BCH_BIST_RESULT_FUNC()
static inline uint64_t BDK_BCH_BIST_RESULT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_BIST_RESULT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000080ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000080ll;
    __bdk_csr_fatal("BCH_BIST_RESULT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_BIST_RESULT bdk_bch_bist_result_t
#define bustype_BDK_BCH_BIST_RESULT BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_BIST_RESULT "BCH_BIST_RESULT"
#define device_bar_BDK_BCH_BIST_RESULT 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_BIST_RESULT 0
#define arguments_BDK_BCH_BIST_RESULT -1,-1,-1,-1

/**
 * Register (NCB) bch_bp_test
 *
 * INTERNAL: BCH Backpressure Test Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_bp_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = When set,disables popping of NCBO FIFO,also credits won't be returned.
                                                                 <61> = When set,disables popping of NCBI FIFO,also credits won't be returned.
                                                                 <60> = When set,enables backpressure on the FPA(XPD) interface. Applicable for T83, has no
                                                                 effect in T81. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = Reserved.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_12_15        : 4;
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
#else /* Word 0 - Little Endian */
        uint64_t lfsr_freq             : 12; /**< [ 11:  0](R/W) Test LFSR update frequency in coprocessor-clocks minus one. */
        uint64_t reserved_12_15        : 4;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 BP_CFG bits per enable.  The definition is 0x0=100% of the time,
                                                                   0x1=25% of the time, 0x2=50% of the time, 0x3=75% of the time.
                                                                   <23:22> = Reserved.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved.
                                                                 <62> = When set,disables popping of NCBO FIFO,also credits won't be returned.
                                                                 <61> = When set,disables popping of NCBI FIFO,also credits won't be returned.
                                                                 <60> = When set,enables backpressure on the FPA(XPD) interface. Applicable for T83, has no
                                                                 effect in T81. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_bp_test_s cn; */
} bdk_bch_bp_test_t;

#define BDK_BCH_BP_TEST BDK_BCH_BP_TEST_FUNC()
static inline uint64_t BDK_BCH_BP_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_BP_TEST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000040ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000040ll;
    __bdk_csr_fatal("BCH_BP_TEST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_BP_TEST bdk_bch_bp_test_t
#define bustype_BDK_BCH_BP_TEST BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_BP_TEST "BCH_BP_TEST"
#define device_bar_BDK_BCH_BP_TEST 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_BP_TEST 0
#define arguments_BDK_BCH_BP_TEST -1,-1,-1,-1

/**
 * Register (NCB) bch_ctl
 *
 * BCH PF Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse (lasts for 4 cycles). */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1) Reset one-shot pulse (lasts for 4 cycles). */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_ctl_s cn; */
} bdk_bch_ctl_t;

#define BDK_BCH_CTL BDK_BCH_CTL_FUNC()
static inline uint64_t BDK_BCH_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000000ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000000ll;
    __bdk_csr_fatal("BCH_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_CTL bdk_bch_ctl_t
#define bustype_BDK_BCH_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_CTL "BCH_CTL"
#define device_bar_BDK_BCH_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_CTL 0
#define arguments_BDK_BCH_CTL -1,-1,-1,-1

/**
 * Register (NCB) bch_eco
 *
 * INTERNAL: BCH PF ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_eco_s cn; */
} bdk_bch_eco_t;

#define BDK_BCH_ECO BDK_BCH_ECO_FUNC()
static inline uint64_t BDK_BCH_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000030ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000030ll;
    __bdk_csr_fatal("BCH_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_ECO bdk_bch_eco_t
#define bustype_BDK_BCH_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_ECO "BCH_ECO"
#define device_bar_BDK_BCH_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_ECO 0
#define arguments_BDK_BCH_ECO -1,-1,-1,-1

/**
 * Register (NCB) bch_err_cfg
 *
 * BCH PF Error Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_err_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t dat_flip              : 2;  /**< [ 17: 16](R/W) Testing feature. Flip syndrome bits <1:0> on writes to the DAT ram to test single-bit or
                                                                 double-bit errors. */
        uint64_t reserved_1_15         : 15;
        uint64_t dat_cor_dis           : 1;  /**< [  0:  0](R/W) Disable ECC corrector on DAT RAM. */
#else /* Word 0 - Little Endian */
        uint64_t dat_cor_dis           : 1;  /**< [  0:  0](R/W) Disable ECC corrector on DAT RAM. */
        uint64_t reserved_1_15         : 15;
        uint64_t dat_flip              : 2;  /**< [ 17: 16](R/W) Testing feature. Flip syndrome bits <1:0> on writes to the DAT ram to test single-bit or
                                                                 double-bit errors. */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_err_cfg_s cn; */
} bdk_bch_err_cfg_t;

#define BDK_BCH_ERR_CFG BDK_BCH_ERR_CFG_FUNC()
static inline uint64_t BDK_BCH_ERR_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_ERR_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000010ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000010ll;
    __bdk_csr_fatal("BCH_ERR_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_ERR_CFG bdk_bch_err_cfg_t
#define bustype_BDK_BCH_ERR_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_ERR_CFG "BCH_ERR_CFG"
#define device_bar_BDK_BCH_ERR_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_ERR_CFG 0
#define arguments_BDK_BCH_ERR_CFG -1,-1,-1,-1

/**
 * Register (NCB) bch_err_int
 *
 * BCH PF Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1C/H) An ECC uncorrectable error has occurred in the DAT RAM. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1C/H) An ECC correctable error has occurred in the DAT RAM. */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1C/H) Error bit indicating a doorbell count has overflowed. */
#else /* Word 0 - Little Endian */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1C/H) Error bit indicating a doorbell count has overflowed. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1C/H) An ECC correctable error has occurred in the DAT RAM. */
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1C/H) An ECC uncorrectable error has occurred in the DAT RAM. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_err_int_s cn; */
} bdk_bch_err_int_t;

#define BDK_BCH_ERR_INT BDK_BCH_ERR_INT_FUNC()
static inline uint64_t BDK_BCH_ERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_ERR_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000088ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000088ll;
    __bdk_csr_fatal("BCH_ERR_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_ERR_INT bdk_bch_err_int_t
#define bustype_BDK_BCH_ERR_INT BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_ERR_INT "BCH_ERR_INT"
#define device_bar_BDK_BCH_ERR_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_ERR_INT 0
#define arguments_BDK_BCH_ERR_INT -1,-1,-1,-1

/**
 * Register (NCB) bch_err_int_ena_w1c
 *
 * BCH PF Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_err_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for BCH_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for BCH_ERR_INT[DAT_SBE]. */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for BCH_ERR_INT[DOORBELL]. */
#else /* Word 0 - Little Endian */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for BCH_ERR_INT[DOORBELL]. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for BCH_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for BCH_ERR_INT[DAT_DBE]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_err_int_ena_w1c_s cn; */
} bdk_bch_err_int_ena_w1c_t;

#define BDK_BCH_ERR_INT_ENA_W1C BDK_BCH_ERR_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_BCH_ERR_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_ERR_INT_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x8710000000a0ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8710000000a0ll;
    __bdk_csr_fatal("BCH_ERR_INT_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_ERR_INT_ENA_W1C bdk_bch_err_int_ena_w1c_t
#define bustype_BDK_BCH_ERR_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_ERR_INT_ENA_W1C "BCH_ERR_INT_ENA_W1C"
#define device_bar_BDK_BCH_ERR_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_ERR_INT_ENA_W1C 0
#define arguments_BDK_BCH_ERR_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) bch_err_int_ena_w1s
 *
 * BCH PF Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_err_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for BCH_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for BCH_ERR_INT[DAT_SBE]. */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for BCH_ERR_INT[DOORBELL]. */
#else /* Word 0 - Little Endian */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for BCH_ERR_INT[DOORBELL]. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for BCH_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for BCH_ERR_INT[DAT_DBE]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_err_int_ena_w1s_s cn; */
} bdk_bch_err_int_ena_w1s_t;

#define BDK_BCH_ERR_INT_ENA_W1S BDK_BCH_ERR_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_BCH_ERR_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_ERR_INT_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x8710000000a8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8710000000a8ll;
    __bdk_csr_fatal("BCH_ERR_INT_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_ERR_INT_ENA_W1S bdk_bch_err_int_ena_w1s_t
#define bustype_BDK_BCH_ERR_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_ERR_INT_ENA_W1S "BCH_ERR_INT_ENA_W1S"
#define device_bar_BDK_BCH_ERR_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_ERR_INT_ENA_W1S 0
#define arguments_BDK_BCH_ERR_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) bch_err_int_w1s
 *
 * BCH PF Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets BCH_ERR_INT[DAT_DBE]. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets BCH_ERR_INT[DAT_SBE]. */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets BCH_ERR_INT[DOORBELL]. */
#else /* Word 0 - Little Endian */
        uint64_t doorbell              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets BCH_ERR_INT[DOORBELL]. */
        uint64_t dat_sbe               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets BCH_ERR_INT[DAT_SBE]. */
        uint64_t dat_dbe               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets BCH_ERR_INT[DAT_DBE]. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_err_int_w1s_s cn; */
} bdk_bch_err_int_w1s_t;

#define BDK_BCH_ERR_INT_W1S BDK_BCH_ERR_INT_W1S_FUNC()
static inline uint64_t BDK_BCH_ERR_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_ERR_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x871000000090ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x871000000090ll;
    __bdk_csr_fatal("BCH_ERR_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_BCH_ERR_INT_W1S bdk_bch_err_int_w1s_t
#define bustype_BDK_BCH_ERR_INT_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_ERR_INT_W1S "BCH_ERR_INT_W1S"
#define device_bar_BDK_BCH_ERR_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_ERR_INT_W1S 0
#define arguments_BDK_BCH_ERR_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) bch_pf_msix_pba#
 *
 * BCH PF MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the BCH_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated BCH_MSIX_VEC()_CTL, enumerated by
                                                                 BCH_INT_VEC_E. Bits that have no associated BCH_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated BCH_MSIX_VEC()_CTL, enumerated by
                                                                 BCH_INT_VEC_E. Bits that have no associated BCH_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_pf_msix_pbax_s cn; */
} bdk_bch_pf_msix_pbax_t;

static inline uint64_t BDK_BCH_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871000ff0000ll + 8ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871000ff0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_PF_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_PF_MSIX_PBAX(a) bdk_bch_pf_msix_pbax_t
#define bustype_BDK_BCH_PF_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_PF_MSIX_PBAX(a) "BCH_PF_MSIX_PBAX"
#define device_bar_BDK_BCH_PF_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_BCH_PF_MSIX_PBAX(a) (a)
#define arguments_BDK_BCH_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_pf_msix_vec#_addr
 *
 * BCH PF MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the BCH_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's BCH_MSIX_VEC()_ADDR, BCH_MSIX_VEC()_CTL, and corresponding
                                                                 bit of BCH_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_BCH_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's BCH_MSIX_VEC()_ADDR, BCH_MSIX_VEC()_CTL, and corresponding
                                                                 bit of BCH_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_BCH_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_pf_msix_vecx_addr_s cn; */
} bdk_bch_pf_msix_vecx_addr_t;

static inline uint64_t BDK_BCH_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871000f00000ll + 0x10ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871000f00000ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_PF_MSIX_VECX_ADDR(a) bdk_bch_pf_msix_vecx_addr_t
#define bustype_BDK_BCH_PF_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_PF_MSIX_VECX_ADDR(a) "BCH_PF_MSIX_VECX_ADDR"
#define device_bar_BDK_BCH_PF_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_BCH_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_BCH_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_pf_msix_vec#_ctl
 *
 * BCH PF MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the BCH_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_pf_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_pf_msix_vecx_ctl_s cn; */
} bdk_bch_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_BCH_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871000f00008ll + 0x10ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871000f00008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_PF_MSIX_VECX_CTL(a) bdk_bch_pf_msix_vecx_ctl_t
#define bustype_BDK_BCH_PF_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_PF_MSIX_VECX_CTL(a) "BCH_PF_MSIX_VECX_CTL"
#define device_bar_BDK_BCH_PF_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_BCH_PF_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_BCH_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_pf_q#_gmctl
 *
 * BCH PF Queue Guest Machine Control Register
 * Internal:
 * Make register internal in CN81xx, visible in CN83xx.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_pf_qx_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free operations initiated by this queue.
                                                                 Must be non-zero or FPA will drop requests. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Guest machine identifier. The GMID to send to FPA for all
                                                                 buffer free operations initiated by this queue.
                                                                 Must be non-zero or FPA will drop requests. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_pf_qx_gmctl_s cn; */
} bdk_bch_pf_qx_gmctl_t;

static inline uint64_t BDK_BCH_PF_QX_GMCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_PF_QX_GMCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871000000100ll + 8ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871000000100ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_PF_QX_GMCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_PF_QX_GMCTL(a) bdk_bch_pf_qx_gmctl_t
#define bustype_BDK_BCH_PF_QX_GMCTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_PF_QX_GMCTL(a) "BCH_PF_QX_GMCTL"
#define device_bar_BDK_BCH_PF_QX_GMCTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_BCH_PF_QX_GMCTL(a) (a)
#define arguments_BDK_BCH_PF_QX_GMCTL(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_vq#_cmd_buf
 *
 * BCH Queue Command Buffer Register
 * This register sets the command-buffer parameters.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_vqx_cmd_buf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t aura                  : 12; /**< [ 59: 48](R/W) Aura to use when freeing command-buffer segments. For frees to work [DFB] must
                                                                 be clear, and for the FPA to not discard the request BCH_PF_Q()_GMCTL[GMID]
                                                                 must be non-zero. */
        uint64_t ldwb                  : 1;  /**< [ 47: 47](R/W) When reading commands that end on cache line boundaries, use load-and-don't write back commands. */
        uint64_t dfb                   : 1;  /**< [ 46: 46](R/W) Don't free buffers to the FPA. */
        uint64_t size                  : 13; /**< [ 45: 33](R/W) Number of uint64s per command buffer segment. */
        uint64_t reserved_0_32         : 33;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_32         : 33;
        uint64_t size                  : 13; /**< [ 45: 33](R/W) Number of uint64s per command buffer segment. */
        uint64_t dfb                   : 1;  /**< [ 46: 46](R/W) Don't free buffers to the FPA. */
        uint64_t ldwb                  : 1;  /**< [ 47: 47](R/W) When reading commands that end on cache line boundaries, use load-and-don't write back commands. */
        uint64_t aura                  : 12; /**< [ 59: 48](R/W) Aura to use when freeing command-buffer segments. For frees to work [DFB] must
                                                                 be clear, and for the FPA to not discard the request BCH_PF_Q()_GMCTL[GMID]
                                                                 must be non-zero. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_vqx_cmd_buf_s cn; */
} bdk_bch_vqx_cmd_buf_t;

static inline uint64_t BDK_BCH_VQX_CMD_BUF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_VQX_CMD_BUF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871001000008ll + 0x100000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871001000008ll + 0x100000ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_VQX_CMD_BUF", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_VQX_CMD_BUF(a) bdk_bch_vqx_cmd_buf_t
#define bustype_BDK_BCH_VQX_CMD_BUF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_VQX_CMD_BUF(a) "BCH_VQX_CMD_BUF"
#define device_bar_BDK_BCH_VQX_CMD_BUF(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_BCH_VQX_CMD_BUF(a) (a)
#define arguments_BDK_BCH_VQX_CMD_BUF(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_vq#_cmd_ptr
 *
 * BCH Queue Command Buffer Pointer Register
 * This register sets the command-buffer parameters.
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_vqx_cmd_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W) Initial command-buffer IOVA <41:7> (128-byte aligned). Overwritten each time the
                                                                 command-buffer segment is exhausted. */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W) Initial command-buffer IOVA <41:7> (128-byte aligned). Overwritten each time the
                                                                 command-buffer segment is exhausted. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_vqx_cmd_ptr_s cn; */
} bdk_bch_vqx_cmd_ptr_t;

static inline uint64_t BDK_BCH_VQX_CMD_PTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_VQX_CMD_PTR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871001000020ll + 0x100000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871001000020ll + 0x100000ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_VQX_CMD_PTR", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_VQX_CMD_PTR(a) bdk_bch_vqx_cmd_ptr_t
#define bustype_BDK_BCH_VQX_CMD_PTR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_VQX_CMD_PTR(a) "BCH_VQX_CMD_PTR"
#define device_bar_BDK_BCH_VQX_CMD_PTR(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_BCH_VQX_CMD_PTR(a) (a)
#define arguments_BDK_BCH_VQX_CMD_PTR(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_vq#_ctl
 *
 * BCH Queue Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_vqx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_22_63        : 42;
        uint64_t early_term            : 4;  /**< [ 21: 18](R/W) Threshold of zero delta interations before declaring early termination.
                                                                 0 will force all iterations to run.  For diagnostic use only. */
        uint64_t one_cmd               : 1;  /**< [ 17: 17](RAZ) Execute a single operation at a time.  For diagnostic use only. */
        uint64_t erase_disable         : 1;  /**< [ 16: 16](R/W) When ERASE_DISABLE=0, erased blocks bypass the BCH correction.   The 16B result word
                                                                 contains an erased block indication.

                                                                 A block is considered erased if the number of zeros found in the block (data+ECC) is
                                                                 less than half the ECC level.   For instance, a 2 KB block using ECC32 is considered
                                                                 erased if few than 16 zeroes are found in the 2048+60 bytes. */
        uint64_t reserved_6_15         : 10;
        uint64_t max_read              : 4;  /**< [  5:  2](R/W) Maximum number of outstanding data read commands. MAX_READ is a throttle to control IOB
                                                                 usage. Values greater than 0x8 are illegal. */
        uint64_t cmd_be                : 1;  /**< [  1:  1](R/W) Command queue and result word is big endian. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t cmd_be                : 1;  /**< [  1:  1](R/W) Command queue and result word is big endian. */
        uint64_t max_read              : 4;  /**< [  5:  2](R/W) Maximum number of outstanding data read commands. MAX_READ is a throttle to control IOB
                                                                 usage. Values greater than 0x8 are illegal. */
        uint64_t reserved_6_15         : 10;
        uint64_t erase_disable         : 1;  /**< [ 16: 16](R/W) When ERASE_DISABLE=0, erased blocks bypass the BCH correction.   The 16B result word
                                                                 contains an erased block indication.

                                                                 A block is considered erased if the number of zeros found in the block (data+ECC) is
                                                                 less than half the ECC level.   For instance, a 2 KB block using ECC32 is considered
                                                                 erased if few than 16 zeroes are found in the 2048+60 bytes. */
        uint64_t one_cmd               : 1;  /**< [ 17: 17](RAZ) Execute a single operation at a time.  For diagnostic use only. */
        uint64_t early_term            : 4;  /**< [ 21: 18](R/W) Threshold of zero delta interations before declaring early termination.
                                                                 0 will force all iterations to run.  For diagnostic use only. */
        uint64_t reserved_22_63        : 42;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_vqx_ctl_s cn; */
} bdk_bch_vqx_ctl_t;

static inline uint64_t BDK_BCH_VQX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_VQX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871001000000ll + 0x100000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871001000000ll + 0x100000ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_VQX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_VQX_CTL(a) bdk_bch_vqx_ctl_t
#define bustype_BDK_BCH_VQX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_VQX_CTL(a) "BCH_VQX_CTL"
#define device_bar_BDK_BCH_VQX_CTL(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_BCH_VQX_CTL(a) (a)
#define arguments_BDK_BCH_VQX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) bch_vq#_doorbell
 *
 * BCH Queue Doorbell Register
 */
typedef union
{
    uint64_t u;
    struct bdk_bch_vqx_doorbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the instruction doorbell
                                                                 count. */
#else /* Word 0 - Little Endian */
        uint64_t dbell_cnt             : 20; /**< [ 19:  0](R/W/H) Number of instruction queue 64-bit words to add to the instruction doorbell
                                                                 count. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_bch_vqx_doorbell_s cn; */
} bdk_bch_vqx_doorbell_t;

static inline uint64_t BDK_BCH_VQX_DOORBELL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BCH_VQX_DOORBELL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x871001000800ll + 0x100000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x871001000800ll + 0x100000ll * ((a) & 0x0);
    __bdk_csr_fatal("BCH_VQX_DOORBELL", 1, a, 0, 0, 0);
}

#define typedef_BDK_BCH_VQX_DOORBELL(a) bdk_bch_vqx_doorbell_t
#define bustype_BDK_BCH_VQX_DOORBELL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_BCH_VQX_DOORBELL(a) "BCH_VQX_DOORBELL"
#define device_bar_BDK_BCH_VQX_DOORBELL(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_BCH_VQX_DOORBELL(a) (a)
#define arguments_BDK_BCH_VQX_DOORBELL(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_BCH_H__ */
