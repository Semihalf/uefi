#ifndef __BDK_CSRS_MCC_H__
#define __BDK_CSRS_MCC_H__
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
 * Cavium MCC.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration mcc_bar_e
 *
 * MCC Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_MCC_BAR_E_MCCX_PF_BAR0(a) (0x87e038000000ll + 0x1000000ll * (a))
#define BDK_MCC_BAR_E_MCCX_PF_BAR0_SIZE 0x800000ull

/**
 * Register (RSL) mcc#_bist_ctl
 *
 * MCC BIST Control Registers
 * This register has fields to control BIST operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_mccx_bist_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t start_bist            : 1;  /**< [  1:  1](R/W) Start BIST for wbf and rbf memories. */
        uint64_t clear_bist            : 1;  /**< [  0:  0](R/W) Start clear BIST for wbf and rbf memories. */
#else /* Word 0 - Little Endian */
        uint64_t clear_bist            : 1;  /**< [  0:  0](R/W) Start clear BIST for wbf and rbf memories. */
        uint64_t start_bist            : 1;  /**< [  1:  1](R/W) Start BIST for wbf and rbf memories. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mccx_bist_ctl_s cn; */
} bdk_mccx_bist_ctl_t;

static inline uint64_t BDK_MCCX_BIST_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MCCX_BIST_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x87e038000100ll + 0x1000000ll * ((a) & 0x1);
    __bdk_csr_fatal("MCCX_BIST_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_MCCX_BIST_CTL(a) bdk_mccx_bist_ctl_t
#define bustype_BDK_MCCX_BIST_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MCCX_BIST_CTL(a) "MCCX_BIST_CTL"
#define device_bar_BDK_MCCX_BIST_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MCCX_BIST_CTL(a) (a)
#define arguments_BDK_MCCX_BIST_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) mcc#_config
 *
 * MCC Configuration Register
 * This register controls certain parameters required for memory configuration.
 */
typedef union
{
    uint64_t u;
    struct bdk_mccx_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t scramble_ena          : 1;  /**< [  2:  2](R/W) When set, enable the scramble/descramble logic for secure transactions. */
        uint64_t dram_ecc_ena          : 1;  /**< [  1:  1](R/W) ECC enable. When set, enables the 8b ECC check/correct logic. Should be 1 when used with
                                                                 DIMMs with ECC; 0, otherwise.

                                                                 0 = DQ<71:64> are driven to 0x0. See SEC_ERR, DED_ERR, LMC()_FADR, and
                                                                 LMC()_ECC_SYND for diagnostics information when there is an error.

                                                                 1 = DQ<71:64> on write operations contains the ECC code generated for the 64
                                                                 bits of data which will be written in the memory. Later on read operations, used
                                                                 to check for single-bit error (which will be auto-corrected) and double-bit
                                                                 error (which will be reported).

                                                                 Internal:
                                                                 FIXME SEC_ERR etc in above paragraph don't exist. */
        uint64_t dis_tadecc            : 1;  /**< [  0:  0](R/W) When set, disable both ECC checking on incoming write data from TAD and
                                                                 ECC generation on outgoing read data to the mesh. */
#else /* Word 0 - Little Endian */
        uint64_t dis_tadecc            : 1;  /**< [  0:  0](R/W) When set, disable both ECC checking on incoming write data from TAD and
                                                                 ECC generation on outgoing read data to the mesh. */
        uint64_t dram_ecc_ena          : 1;  /**< [  1:  1](R/W) ECC enable. When set, enables the 8b ECC check/correct logic. Should be 1 when used with
                                                                 DIMMs with ECC; 0, otherwise.

                                                                 0 = DQ<71:64> are driven to 0x0. See SEC_ERR, DED_ERR, LMC()_FADR, and
                                                                 LMC()_ECC_SYND for diagnostics information when there is an error.

                                                                 1 = DQ<71:64> on write operations contains the ECC code generated for the 64
                                                                 bits of data which will be written in the memory. Later on read operations, used
                                                                 to check for single-bit error (which will be auto-corrected) and double-bit
                                                                 error (which will be reported).

                                                                 Internal:
                                                                 FIXME SEC_ERR etc in above paragraph don't exist. */
        uint64_t scramble_ena          : 1;  /**< [  2:  2](R/W) When set, enable the scramble/descramble logic for secure transactions. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mccx_config_s cn; */
} bdk_mccx_config_t;

static inline uint64_t BDK_MCCX_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MCCX_CONFIG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x87e038000020ll + 0x1000000ll * ((a) & 0x1);
    __bdk_csr_fatal("MCCX_CONFIG", 1, a, 0, 0, 0);
}

#define typedef_BDK_MCCX_CONFIG(a) bdk_mccx_config_t
#define bustype_BDK_MCCX_CONFIG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MCCX_CONFIG(a) "MCCX_CONFIG"
#define device_bar_BDK_MCCX_CONFIG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MCCX_CONFIG(a) (a)
#define arguments_BDK_MCCX_CONFIG(a) (a),-1,-1,-1

/**
 * Register (RSL) mcc#_eco
 *
 * INTERNAL: MCC ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mccx_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Reserved for ECO usage. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mccx_eco_s cn; */
} bdk_mccx_eco_t;

static inline uint64_t BDK_MCCX_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MCCX_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x87e038000040ll + 0x1000000ll * ((a) & 0x1);
    __bdk_csr_fatal("MCCX_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_MCCX_ECO(a) bdk_mccx_eco_t
#define bustype_BDK_MCCX_ECO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MCCX_ECO(a) "MCCX_ECO"
#define device_bar_BDK_MCCX_ECO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MCCX_ECO(a) (a)
#define arguments_BDK_MCCX_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) mcc#_scramble_cfg0
 *
 * MCC Scramble Configuration 0 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mccx_scramble_cfg0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t key                   : 64; /**< [ 63:  0](R/W) Lower 64-bit scramble key for data. Prior to enabling scrambling this key should be
                                                                 generated from a cryptographically-secure random number generator such as RNM_RANDOM. */
#else /* Word 0 - Little Endian */
        uint64_t key                   : 64; /**< [ 63:  0](R/W) Lower 64-bit scramble key for data. Prior to enabling scrambling this key should be
                                                                 generated from a cryptographically-secure random number generator such as RNM_RANDOM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mccx_scramble_cfg0_s cn; */
} bdk_mccx_scramble_cfg0_t;

static inline uint64_t BDK_MCCX_SCRAMBLE_CFG0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MCCX_SCRAMBLE_CFG0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x87e038000030ll + 0x1000000ll * ((a) & 0x1);
    __bdk_csr_fatal("MCCX_SCRAMBLE_CFG0", 1, a, 0, 0, 0);
}

#define typedef_BDK_MCCX_SCRAMBLE_CFG0(a) bdk_mccx_scramble_cfg0_t
#define bustype_BDK_MCCX_SCRAMBLE_CFG0(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MCCX_SCRAMBLE_CFG0(a) "MCCX_SCRAMBLE_CFG0"
#define device_bar_BDK_MCCX_SCRAMBLE_CFG0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MCCX_SCRAMBLE_CFG0(a) (a)
#define arguments_BDK_MCCX_SCRAMBLE_CFG0(a) (a),-1,-1,-1

/**
 * Register (RSL) mcc#_scramble_cfg1
 *
 * MCC Scramble Configuration 1 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_mccx_scramble_cfg1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t key                   : 64; /**< [ 63:  0](R/W) Upper 64-bit scramble key for data. Prior to enabling scrambling this key should be
                                                                 generated from a cryptographically-secure random number generator such as RNM_RANDOM. */
#else /* Word 0 - Little Endian */
        uint64_t key                   : 64; /**< [ 63:  0](R/W) Upper 64-bit scramble key for data. Prior to enabling scrambling this key should be
                                                                 generated from a cryptographically-secure random number generator such as RNM_RANDOM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_mccx_scramble_cfg1_s cn; */
} bdk_mccx_scramble_cfg1_t;

static inline uint64_t BDK_MCCX_SCRAMBLE_CFG1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MCCX_SCRAMBLE_CFG1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=1))
        return 0x87e038000038ll + 0x1000000ll * ((a) & 0x1);
    __bdk_csr_fatal("MCCX_SCRAMBLE_CFG1", 1, a, 0, 0, 0);
}

#define typedef_BDK_MCCX_SCRAMBLE_CFG1(a) bdk_mccx_scramble_cfg1_t
#define bustype_BDK_MCCX_SCRAMBLE_CFG1(a) BDK_CSR_TYPE_RSL
#define basename_BDK_MCCX_SCRAMBLE_CFG1(a) "MCCX_SCRAMBLE_CFG1"
#define device_bar_BDK_MCCX_SCRAMBLE_CFG1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_MCCX_SCRAMBLE_CFG1(a) (a)
#define arguments_BDK_MCCX_SCRAMBLE_CFG1(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_MCC_H__ */
