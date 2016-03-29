#ifndef __BDK_CSRS_CER_H__
#define __BDK_CSRS_CER_H__
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
 * Cavium CER.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration cer_bar_e
 *
 * CER Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CER_BAR_E_CER_PF_BAR0 (0x87e007000000ll)
#define BDK_CER_BAR_E_CER_PF_BAR4 (0x87e007f00000ll)

/**
 * Enumeration cer_serr_e
 *
 * CER RAS Error Record Type Enumeration
 * Enumerates the error record types in CER_ERR()_STATUS[SERR].
 */
#define BDK_CER_SERR_E_ASSERTION (4)
#define BDK_CER_SERR_E_CAM_DATA (6)
#define BDK_CER_SERR_E_CAM_TAG (7)
#define BDK_CER_SERR_E_DATAPATH (5)
#define BDK_CER_SERR_E_EXT_DATA (0xc)
#define BDK_CER_SERR_E_EXT_TO (0x13)
#define BDK_CER_SERR_E_IMPDEF1 (1)
#define BDK_CER_SERR_E_INT_TO (0x14)
#define BDK_CER_SERR_E_NONE (0)
#define BDK_CER_SERR_E_PIN (3)
#define BDK_CER_SERR_E_PRODUCER_ADDRCTL (0xb)
#define BDK_CER_SERR_E_PRODUCER_DATA (0xa)
#define BDK_CER_SERR_E_REG_CTL (0x11)
#define BDK_CER_SERR_E_REG_DATA (0x10)
#define BDK_CER_SERR_E_SLAVE (0x12)
#define BDK_CER_SERR_E_SRAM_DATA (2)
#define BDK_CER_SERR_E_SW_BAD_ACCESS (0xe)
#define BDK_CER_SERR_E_SW_BAD_ADDR (0xd)
#define BDK_CER_SERR_E_SW_BAD_STATE (0xf)
#define BDK_CER_SERR_E_TLB_ADDRCTL (9)
#define BDK_CER_SERR_E_TLB_DATA (8)

/**
 * Register (RSL) cer_bp_test
 *
 * INTERNAL: CER PF Backpressure Test Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_bp_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = FIXME.
                                                                 <62> = FIXME.
                                                                 <61> = Reserved.
                                                                 <60> = Reserved. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
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
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=75% of the time, 0x2=50% of the time,
                                                                 0x3=25% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = FIXME.
                                                                 <62> = FIXME.
                                                                 <61> = Reserved.
                                                                 <60> = Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_bp_test_s cn; */
} bdk_cer_bp_test_t;

#define BDK_CER_BP_TEST BDK_CER_BP_TEST_FUNC()
static inline uint64_t BDK_CER_BP_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_BP_TEST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007001100ll;
    __bdk_csr_fatal("CER_BP_TEST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_BP_TEST bdk_cer_bp_test_t
#define bustype_BDK_CER_BP_TEST BDK_CSR_TYPE_RSL
#define basename_BDK_CER_BP_TEST "CER_BP_TEST"
#define device_bar_BDK_CER_BP_TEST 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_BP_TEST 0
#define arguments_BDK_CER_BP_TEST -1,-1,-1,-1

/**
 * Register (RSL32b) cer_cidr0
 *
 * CER Component Identification Register 0
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_cidr0_s cn; */
} bdk_cer_cidr0_t;

#define BDK_CER_CIDR0 BDK_CER_CIDR0_FUNC()
static inline uint64_t BDK_CER_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_CIDR0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000ff0ll;
    __bdk_csr_fatal("CER_CIDR0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_CIDR0 bdk_cer_cidr0_t
#define bustype_BDK_CER_CIDR0 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_CIDR0 "CER_CIDR0"
#define device_bar_BDK_CER_CIDR0 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_CIDR0 0
#define arguments_BDK_CER_CIDR0 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_cidr1
 *
 * CER Component Identification Register 1
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_cidr1_s cn; */
} bdk_cer_cidr1_t;

#define BDK_CER_CIDR1 BDK_CER_CIDR1_FUNC()
static inline uint64_t BDK_CER_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_CIDR1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000ff4ll;
    __bdk_csr_fatal("CER_CIDR1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_CIDR1 bdk_cer_cidr1_t
#define bustype_BDK_CER_CIDR1 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_CIDR1 "CER_CIDR1"
#define device_bar_BDK_CER_CIDR1 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_CIDR1 0
#define arguments_BDK_CER_CIDR1 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_cidr2
 *
 * CER Component Identification Register 2
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_cidr2_s cn; */
} bdk_cer_cidr2_t;

#define BDK_CER_CIDR2 BDK_CER_CIDR2_FUNC()
static inline uint64_t BDK_CER_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_CIDR2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000ff8ll;
    __bdk_csr_fatal("CER_CIDR2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_CIDR2 bdk_cer_cidr2_t
#define bustype_BDK_CER_CIDR2 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_CIDR2 "CER_CIDR2"
#define device_bar_BDK_CER_CIDR2 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_CIDR2 0
#define arguments_BDK_CER_CIDR2 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_cidr3
 *
 * CER Component Identification Register 3
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_cidr3_s cn; */
} bdk_cer_cidr3_t;

#define BDK_CER_CIDR3 BDK_CER_CIDR3_FUNC()
static inline uint64_t BDK_CER_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_CIDR3_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000ffcll;
    __bdk_csr_fatal("CER_CIDR3", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_CIDR3 bdk_cer_cidr3_t
#define bustype_BDK_CER_CIDR3 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_CIDR3 "CER_CIDR3"
#define device_bar_BDK_CER_CIDR3 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_CIDR3 0
#define arguments_BDK_CER_CIDR3 -1,-1,-1,-1

/**
 * Register (RSL) cer_const
 *
 * CER Constants Register
 * This register contains implementation-related parameters.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_const_s cn; */
} bdk_cer_const_t;

#define BDK_CER_CONST BDK_CER_CONST_FUNC()
static inline uint64_t BDK_CER_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007001000ll;
    __bdk_csr_fatal("CER_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_CONST bdk_cer_const_t
#define bustype_BDK_CER_CONST BDK_CSR_TYPE_RSL
#define basename_BDK_CER_CONST "CER_CONST"
#define device_bar_BDK_CER_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_CONST 0
#define arguments_BDK_CER_CONST -1,-1,-1,-1

/**
 * Register (RSL) cer_const1
 *
 * CER Constants 1 Register
 * This register contains implementation-related parameters.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_const1_s cn; */
} bdk_cer_const1_t;

#define BDK_CER_CONST1 BDK_CER_CONST1_FUNC()
static inline uint64_t BDK_CER_CONST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_CONST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007001008ll;
    __bdk_csr_fatal("CER_CONST1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_CONST1 bdk_cer_const1_t
#define bustype_BDK_CER_CONST1 BDK_CSR_TYPE_RSL
#define basename_BDK_CER_CONST1 "CER_CONST1"
#define device_bar_BDK_CER_CONST1 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_CONST1 0
#define arguments_BDK_CER_CONST1 -1,-1,-1,-1

/**
 * Register (RSL) cer_eco
 *
 * INTERNAL: CER ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_eco_s
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
    /* struct bdk_cer_eco_s cn; */
} bdk_cer_eco_t;

#define BDK_CER_ECO BDK_CER_ECO_FUNC()
static inline uint64_t BDK_CER_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007001200ll;
    __bdk_csr_fatal("CER_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_ECO bdk_cer_eco_t
#define bustype_BDK_CER_ECO BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ECO "CER_ECO"
#define device_bar_BDK_CER_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ECO 0
#define arguments_BDK_CER_ECO -1,-1,-1,-1

/**
 * Register (RSL) cer_err#_addr
 *
 * CER Error Record Address Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nsec                  : 1;  /**< [ 63: 63](R/W/H) Non-secure.
                                                                 0 = The physical address is secure.
                                                                 1 = The physical address is nonsecure. */
        uint64_t si                    : 1;  /**< [ 62: 62](R/W/H) Secure incorrect.
                                                                 0 = [NS] is correct. That is, it matches the programmers' view of the non-secure
                                                                 attribute for this recorded location.
                                                                 1 = [NS] might not be correct. */
        uint64_t ai                    : 1;  /**< [ 61: 61](R/W/H) Address incomplete or incorrect.
                                                                 0 = [PADDR] is correct. That is, it matches the programmers' view of the
                                                                 physical address for this recorded location.
                                                                 1 = [PADDR] might not be correct. */
        uint64_t reserved_56_60        : 5;
        uint64_t paddr                 : 56; /**< [ 55:  0](R/W/H) The associated physical address of the error record.  It is implementation
                                                                 defined how the recorded physical addresses map to the software-visible physical
                                                                 addresses. Software might have to reconstruct the actual physical addresses
                                                                 using the identity of the node and knowledge of the system.

                                                                 For CNXXXX, <55:52> are read-only 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t paddr                 : 56; /**< [ 55:  0](R/W/H) The associated physical address of the error record.  It is implementation
                                                                 defined how the recorded physical addresses map to the software-visible physical
                                                                 addresses. Software might have to reconstruct the actual physical addresses
                                                                 using the identity of the node and knowledge of the system.

                                                                 For CNXXXX, <55:52> are read-only 0x0. */
        uint64_t reserved_56_60        : 5;
        uint64_t ai                    : 1;  /**< [ 61: 61](R/W/H) Address incomplete or incorrect.
                                                                 0 = [PADDR] is correct. That is, it matches the programmers' view of the
                                                                 physical address for this recorded location.
                                                                 1 = [PADDR] might not be correct. */
        uint64_t si                    : 1;  /**< [ 62: 62](R/W/H) Secure incorrect.
                                                                 0 = [NS] is correct. That is, it matches the programmers' view of the non-secure
                                                                 attribute for this recorded location.
                                                                 1 = [NS] might not be correct. */
        uint64_t nsec                  : 1;  /**< [ 63: 63](R/W/H) Non-secure.
                                                                 0 = The physical address is secure.
                                                                 1 = The physical address is nonsecure. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errx_addr_s cn; */
} bdk_cer_errx_addr_t;

static inline uint64_t BDK_CER_ERRX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=2))
        return 0x87e007000018ll + 0x40ll * ((a) & 0x3);
    __bdk_csr_fatal("CER_ERRX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRX_ADDR(a) bdk_cer_errx_addr_t
#define bustype_BDK_CER_ERRX_ADDR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRX_ADDR(a) "CER_ERRX_ADDR"
#define device_bar_BDK_CER_ERRX_ADDR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRX_ADDR(a) (a)
#define arguments_BDK_CER_ERRX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_err#_ctlr
 *
 * CER Error Record Control Register
 * This register contains enable bits for the record.
 * Internal:
 * Non-implemented bits are RO 0x0.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errx_ctlr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t wdui                  : 1;  /**< [ 11: 11](R/W) Error recovery interrupt for deferred errors on writes. See [RDUI]. */
        uint64_t rdui                  : 1;  /**< [ 10: 10](R/W) Error recovery for deferred read error interrupt enable. When enabled the error
                                                                 recovery interrupt is also generated for all Deferred read errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wcfi                  : 1;  /**< [  9:  9](R/W) Fault handling interrupt for corrected errors on writes. See [RCFI]. */
        uint64_t rcfi                  : 1;  /**< [  8:  8](R/W) Fault handling interrupt enable for corrected errors on reads.

                                                                 For corrected error counters, only generated when the counter overflows.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wue                   : 1;  /**< [  7:  7](R/W) Error reporting on writes. See [RU]. */
        uint64_t wfi                   : 1;  /**< [  6:  6](R/W) Fault handling interrupt on writes. See [RFI] */
        uint64_t wui                   : 1;  /**< [  5:  5](R/W) Error recovery interrupt on writes. See [RUI]. */
        uint64_t rue                   : 1;  /**< [  4:  4](R/W) Uncorrected error on read reporting enable. When enabled, responses to
                                                                 transactions that detect an uncorrected error that cannot be deferred are
                                                                 signaled as a detected error (external abort).

                                                                 0 = External abort response for uncorrected errors disabled.
                                                                 1 = External abort response for uncorrected errors enabled. */
        uint64_t rfi                   : 1;  /**< [  3:  3](R/W) Read fault handling interrupt enable. When enabled the fault handling interrupt
                                                                 is generated for all detected Deferred errors and Uncorrected errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. The fault handling
                                                                 interrupt is never generated for consumed errors. */
        uint64_t rui                   : 1;  /**< [  2:  2](R/W) Read uncorrected error recovery interrupt enable. When enabled, the error
                                                                 recovery interrupt is generated for all detected uncorrected errors that are not
                                                                 deferred.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t reserved_1            : 1;
        uint64_t ed                    : 1;  /**< [  0:  0](R/W) Enable error detection and correction at the node.
                                                                 0 = Error detection and correction disabled.
                                                                 1 = Error detection and correction enabled.

                                                                 For CNXXXX CER, this bit is ignored.

                                                                 For CNXXXX AP, this bit resets to 1 as correction works from time zero. */
#else /* Word 0 - Little Endian */
        uint64_t ed                    : 1;  /**< [  0:  0](R/W) Enable error detection and correction at the node.
                                                                 0 = Error detection and correction disabled.
                                                                 1 = Error detection and correction enabled.

                                                                 For CNXXXX CER, this bit is ignored.

                                                                 For CNXXXX AP, this bit resets to 1 as correction works from time zero. */
        uint64_t reserved_1            : 1;
        uint64_t rui                   : 1;  /**< [  2:  2](R/W) Read uncorrected error recovery interrupt enable. When enabled, the error
                                                                 recovery interrupt is generated for all detected uncorrected errors that are not
                                                                 deferred.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t rfi                   : 1;  /**< [  3:  3](R/W) Read fault handling interrupt enable. When enabled the fault handling interrupt
                                                                 is generated for all detected Deferred errors and Uncorrected errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. The fault handling
                                                                 interrupt is never generated for consumed errors. */
        uint64_t rue                   : 1;  /**< [  4:  4](R/W) Uncorrected error on read reporting enable. When enabled, responses to
                                                                 transactions that detect an uncorrected error that cannot be deferred are
                                                                 signaled as a detected error (external abort).

                                                                 0 = External abort response for uncorrected errors disabled.
                                                                 1 = External abort response for uncorrected errors enabled. */
        uint64_t wui                   : 1;  /**< [  5:  5](R/W) Error recovery interrupt on writes. See [RUI]. */
        uint64_t wfi                   : 1;  /**< [  6:  6](R/W) Fault handling interrupt on writes. See [RFI] */
        uint64_t wue                   : 1;  /**< [  7:  7](R/W) Error reporting on writes. See [RU]. */
        uint64_t rcfi                  : 1;  /**< [  8:  8](R/W) Fault handling interrupt enable for corrected errors on reads.

                                                                 For corrected error counters, only generated when the counter overflows.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wcfi                  : 1;  /**< [  9:  9](R/W) Fault handling interrupt for corrected errors on writes. See [RCFI]. */
        uint64_t rdui                  : 1;  /**< [ 10: 10](R/W) Error recovery for deferred read error interrupt enable. When enabled the error
                                                                 recovery interrupt is also generated for all Deferred read errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wdui                  : 1;  /**< [ 11: 11](R/W) Error recovery interrupt for deferred errors on writes. See [RDUI]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    struct bdk_cer_errx_ctlr_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t reserved_12_31        : 20;
        uint64_t wdui                  : 1;  /**< [ 11: 11](R/W) Error recovery interrupt for deferred errors on writes. See [RDUI]. */
        uint64_t rdui                  : 1;  /**< [ 10: 10](R/W) Error recovery for deferred read error interrupt enable. When enabled the error
                                                                 recovery interrupt is also generated for all Deferred read errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wcfi                  : 1;  /**< [  9:  9](R/W) Fault handling interrupt for corrected errors on writes. See [RCFI]. */
        uint64_t rcfi                  : 1;  /**< [  8:  8](R/W) Fault handling interrupt enable for corrected errors on reads.

                                                                 For corrected error counters, only generated when the counter overflows.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wue                   : 1;  /**< [  7:  7](R/W) Error reporting on writes. See [RU]. */
        uint64_t wfi                   : 1;  /**< [  6:  6](R/W) Fault handling interrupt on writes. See [RFI] */
        uint64_t wui                   : 1;  /**< [  5:  5](R/W) Error recovery interrupt on writes. See [RUI]. */
        uint64_t rue                   : 1;  /**< [  4:  4](R/W) Uncorrected error on read reporting enable. When enabled, responses to
                                                                 transactions that detect an uncorrected error that cannot be deferred are
                                                                 signaled as a detected error (external abort).

                                                                 0 = External abort response for uncorrected errors disabled.
                                                                 1 = External abort response for uncorrected errors enabled. */
        uint64_t rfi                   : 1;  /**< [  3:  3](R/W) Read fault handling interrupt enable. When enabled the fault handling interrupt
                                                                 is generated for all detected Deferred errors and Uncorrected errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. The fault handling
                                                                 interrupt is never generated for consumed errors. */
        uint64_t rui                   : 1;  /**< [  2:  2](R/W) Read uncorrected error recovery interrupt enable. When enabled, the error
                                                                 recovery interrupt is generated for all detected uncorrected errors that are not
                                                                 deferred.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t reserved_1            : 1;
        uint64_t ed                    : 1;  /**< [  0:  0](R/W) Enable error detection and correction at the node.
                                                                 0 = Error detection and correction disabled.
                                                                 1 = Error detection and correction enabled.

                                                                 For CNXXXX CER, this bit is ignored.

                                                                 For CNXXXX AP, this bit resets to 1 as correction works from time zero. */
#else /* Word 0 - Little Endian */
        uint64_t ed                    : 1;  /**< [  0:  0](R/W) Enable error detection and correction at the node.
                                                                 0 = Error detection and correction disabled.
                                                                 1 = Error detection and correction enabled.

                                                                 For CNXXXX CER, this bit is ignored.

                                                                 For CNXXXX AP, this bit resets to 1 as correction works from time zero. */
        uint64_t reserved_1            : 1;
        uint64_t rui                   : 1;  /**< [  2:  2](R/W) Read uncorrected error recovery interrupt enable. When enabled, the error
                                                                 recovery interrupt is generated for all detected uncorrected errors that are not
                                                                 deferred.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t rfi                   : 1;  /**< [  3:  3](R/W) Read fault handling interrupt enable. When enabled the fault handling interrupt
                                                                 is generated for all detected Deferred errors and Uncorrected errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. The fault handling
                                                                 interrupt is never generated for consumed errors. */
        uint64_t rue                   : 1;  /**< [  4:  4](R/W) Uncorrected error on read reporting enable. When enabled, responses to
                                                                 transactions that detect an uncorrected error that cannot be deferred are
                                                                 signaled as a detected error (external abort).

                                                                 0 = External abort response for uncorrected errors disabled.
                                                                 1 = External abort response for uncorrected errors enabled. */
        uint64_t wui                   : 1;  /**< [  5:  5](R/W) Error recovery interrupt on writes. See [RUI]. */
        uint64_t wfi                   : 1;  /**< [  6:  6](R/W) Fault handling interrupt on writes. See [RFI] */
        uint64_t wue                   : 1;  /**< [  7:  7](R/W) Error reporting on writes. See [RU]. */
        uint64_t rcfi                  : 1;  /**< [  8:  8](R/W) Fault handling interrupt enable for corrected errors on reads.

                                                                 For corrected error counters, only generated when the counter overflows.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wcfi                  : 1;  /**< [  9:  9](R/W) Fault handling interrupt for corrected errors on writes. See [RCFI]. */
        uint64_t rdui                  : 1;  /**< [ 10: 10](R/W) Error recovery for deferred read error interrupt enable. When enabled the error
                                                                 recovery interrupt is also generated for all Deferred read errors.

                                                                 The interrupt is generated even if the error syndrome is discarded because the
                                                                 error record already records a higher priority error. */
        uint64_t wdui                  : 1;  /**< [ 11: 11](R/W) Error recovery interrupt for deferred errors on writes. See [RDUI]. */
        uint64_t reserved_12_31        : 20;
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn;
} bdk_cer_errx_ctlr_t;

static inline uint64_t BDK_CER_ERRX_CTLR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRX_CTLR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=2))
        return 0x87e007000008ll + 0x40ll * ((a) & 0x3);
    __bdk_csr_fatal("CER_ERRX_CTLR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRX_CTLR(a) bdk_cer_errx_ctlr_t
#define bustype_BDK_CER_ERRX_CTLR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRX_CTLR(a) "CER_ERRX_CTLR"
#define device_bar_BDK_CER_ERRX_CTLR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRX_CTLR(a) (a)
#define arguments_BDK_CER_ERRX_CTLR(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_err#_fr
 *
 * CER Error Record Feature Register
 * This register defines which of the common architecturally-defined features are
 * implemented and, of the implemented features, which are software programmable. If a
 * single node has multiple records then only the first record has a populated error
 * feature register. If any other record is selected, bits <63:0> of the error feature
 * register are 0x0.
 *
 * Internal:
 * Architecture requires zeroing <31:0>, extending to <63:32> is implementation defined.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errx_fr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t dui                   : 2;  /**< [ 17: 16](RO) Error recovery interrupt for deferred errors. If this feature is implemented,
                                                                 then the error recovery interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t rp                    : 1;  /**< [ 15: 15](RO) When [CEC] is non-zero, whether a repeat counter is implemented.
                                                                 0 = A single CE counter is implemented..
                                                                 1 = A first (repeat) counter and a second (other) counter are
                                                                 implemented. The repeat counter is the same size as the primary
                                                                 error counter. */
        uint64_t cec                   : 3;  /**< [ 14: 12](RO) Indicates a standard correctable error counter mechanism in CDC_ERR()_MISC0.
                                                                 0x0 = Does not implement the standardized error counter model.
                                                                 0x2 = Implements an 8-bit error counter in CDC_ERR()_MISC0<39:32>.
                                                                 0x4 = Implements a 16-bit error counter in CDC_ERR()_MISC0<47:32>.

                                                                 All other values are reserved. */
        uint64_t cfi                   : 2;  /**< [ 11: 10](RO) Fault handling interrupt for corrected errors. If this feature is implemented,
                                                                 then the fault handling interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t ue                    : 2;  /**< [  9:  8](RO) Uncorrected error reporting.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t fi                    : 2;  /**< [  7:  6](RO) Fault handling interrupt.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t ui                    : 2;  /**< [  5:  4](RO) Uncorrected error recovery interrupt. 0x0 = Does not support feature. 0x1 = Feature always
                                                                 enabled. 0x2 = Feature is controllable. 0x3 = Feature is controllable with independent
                                                                 controls for reads and writes. */
        uint64_t reserved_2_3          : 2;
        uint64_t ed                    : 2;  /**< [  1:  0](RO) Error detection and correction.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable. */
#else /* Word 0 - Little Endian */
        uint64_t ed                    : 2;  /**< [  1:  0](RO) Error detection and correction.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable. */
        uint64_t reserved_2_3          : 2;
        uint64_t ui                    : 2;  /**< [  5:  4](RO) Uncorrected error recovery interrupt. 0x0 = Does not support feature. 0x1 = Feature always
                                                                 enabled. 0x2 = Feature is controllable. 0x3 = Feature is controllable with independent
                                                                 controls for reads and writes. */
        uint64_t fi                    : 2;  /**< [  7:  6](RO) Fault handling interrupt.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t ue                    : 2;  /**< [  9:  8](RO) Uncorrected error reporting.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t cfi                   : 2;  /**< [ 11: 10](RO) Fault handling interrupt for corrected errors. If this feature is implemented,
                                                                 then the fault handling interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t cec                   : 3;  /**< [ 14: 12](RO) Indicates a standard correctable error counter mechanism in CDC_ERR()_MISC0.
                                                                 0x0 = Does not implement the standardized error counter model.
                                                                 0x2 = Implements an 8-bit error counter in CDC_ERR()_MISC0<39:32>.
                                                                 0x4 = Implements a 16-bit error counter in CDC_ERR()_MISC0<47:32>.

                                                                 All other values are reserved. */
        uint64_t rp                    : 1;  /**< [ 15: 15](RO) When [CEC] is non-zero, whether a repeat counter is implemented.
                                                                 0 = A single CE counter is implemented..
                                                                 1 = A first (repeat) counter and a second (other) counter are
                                                                 implemented. The repeat counter is the same size as the primary
                                                                 error counter. */
        uint64_t dui                   : 2;  /**< [ 17: 16](RO) Error recovery interrupt for deferred errors. If this feature is implemented,
                                                                 then the error recovery interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    struct bdk_cer_errx_fr_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t reserved_18_31        : 14;
        uint64_t dui                   : 2;  /**< [ 17: 16](RO) Error recovery interrupt for deferred errors. If this feature is implemented,
                                                                 then the error recovery interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t rp                    : 1;  /**< [ 15: 15](RO) When [CEC] is non-zero, whether a repeat counter is implemented.
                                                                 0 = A single CE counter is implemented..
                                                                 1 = A first (repeat) counter and a second (other) counter are
                                                                 implemented. The repeat counter is the same size as the primary
                                                                 error counter. */
        uint64_t cec                   : 3;  /**< [ 14: 12](RO) Indicates a standard correctable error counter mechanism in CDC_ERR()_MISC0.
                                                                 0x0 = Does not implement the standardized error counter model.
                                                                 0x2 = Implements an 8-bit error counter in CDC_ERR()_MISC0<39:32>.
                                                                 0x4 = Implements a 16-bit error counter in CDC_ERR()_MISC0<47:32>.

                                                                 All other values are reserved. */
        uint64_t cfi                   : 2;  /**< [ 11: 10](RO) Fault handling interrupt for corrected errors. If this feature is implemented,
                                                                 then the fault handling interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t ue                    : 2;  /**< [  9:  8](RO) Uncorrected error reporting.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t fi                    : 2;  /**< [  7:  6](RO) Fault handling interrupt.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t ui                    : 2;  /**< [  5:  4](RO) Uncorrected error recovery interrupt. 0x0 = Does not support feature. 0x1 = Feature always
                                                                 enabled. 0x2 = Feature is controllable. 0x3 = Feature is controllable with independent
                                                                 controls for reads and writes. */
        uint64_t reserved_2_3          : 2;
        uint64_t ed                    : 2;  /**< [  1:  0](RO) Error detection and correction.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable. */
#else /* Word 0 - Little Endian */
        uint64_t ed                    : 2;  /**< [  1:  0](RO) Error detection and correction.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable. */
        uint64_t reserved_2_3          : 2;
        uint64_t ui                    : 2;  /**< [  5:  4](RO) Uncorrected error recovery interrupt. 0x0 = Does not support feature. 0x1 = Feature always
                                                                 enabled. 0x2 = Feature is controllable. 0x3 = Feature is controllable with independent
                                                                 controls for reads and writes. */
        uint64_t fi                    : 2;  /**< [  7:  6](RO) Fault handling interrupt.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t ue                    : 2;  /**< [  9:  8](RO) Uncorrected error reporting.
                                                                 0x0 = Does not support feature.
                                                                 0x1 = Feature always enabled.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t cfi                   : 2;  /**< [ 11: 10](RO) Fault handling interrupt for corrected errors. If this feature is implemented,
                                                                 then the fault handling interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t cec                   : 3;  /**< [ 14: 12](RO) Indicates a standard correctable error counter mechanism in CDC_ERR()_MISC0.
                                                                 0x0 = Does not implement the standardized error counter model.
                                                                 0x2 = Implements an 8-bit error counter in CDC_ERR()_MISC0<39:32>.
                                                                 0x4 = Implements a 16-bit error counter in CDC_ERR()_MISC0<47:32>.

                                                                 All other values are reserved. */
        uint64_t rp                    : 1;  /**< [ 15: 15](RO) When [CEC] is non-zero, whether a repeat counter is implemented.
                                                                 0 = A single CE counter is implemented..
                                                                 1 = A first (repeat) counter and a second (other) counter are
                                                                 implemented. The repeat counter is the same size as the primary
                                                                 error counter. */
        uint64_t dui                   : 2;  /**< [ 17: 16](RO) Error recovery interrupt for deferred errors. If this feature is implemented,
                                                                 then the error recovery interrupt must be implemented.

                                                                 0x0 = Does not support feature.
                                                                 0x1 = Reserved.
                                                                 0x2 = Feature is controllable.
                                                                 0x3 = Feature is controllable with independent controls for reads and writes. */
        uint64_t reserved_18_31        : 14;
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } cn;
} bdk_cer_errx_fr_t;

static inline uint64_t BDK_CER_ERRX_FR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRX_FR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=2))
        return 0x87e007000000ll + 0x40ll * ((a) & 0x3);
    __bdk_csr_fatal("CER_ERRX_FR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRX_FR(a) bdk_cer_errx_fr_t
#define bustype_BDK_CER_ERRX_FR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRX_FR(a) "CER_ERRX_FR"
#define device_bar_BDK_CER_ERRX_FR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRX_FR(a) (a)
#define arguments_BDK_CER_ERRX_FR(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_err#_misc0
 *
 * CER Error Record Miscellanious Syndrome Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errx_misc0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t of                    : 1;  /**< [ 47: 47](R/W/H) Sticky overflow bit. Indicates [CEC] counter has overflowed. The fault handling
                                                                 interrupt is generated when the corrected fault handling interrupt is enabled
                                                                 and the overflow bit is set to 1.

                                                                 Internal:
                                                                 When [CEC] is RO 0x0, this is always set on a correctable (counter overflows immediately). */
        uint64_t cec                   : 15; /**< [ 46: 32](RO) Reserved for corrected error count, in blocks with 16-bit correctable error counters.
                                                                 Internal:
                                                                 LMC will implement this field as R/W/H. */
        uint64_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_31         : 32;
        uint64_t cec                   : 15; /**< [ 46: 32](RO) Reserved for corrected error count, in blocks with 16-bit correctable error counters.
                                                                 Internal:
                                                                 LMC will implement this field as R/W/H. */
        uint64_t of                    : 1;  /**< [ 47: 47](R/W/H) Sticky overflow bit. Indicates [CEC] counter has overflowed. The fault handling
                                                                 interrupt is generated when the corrected fault handling interrupt is enabled
                                                                 and the overflow bit is set to 1.

                                                                 Internal:
                                                                 When [CEC] is RO 0x0, this is always set on a correctable (counter overflows immediately). */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errx_misc0_s cn; */
} bdk_cer_errx_misc0_t;

static inline uint64_t BDK_CER_ERRX_MISC0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRX_MISC0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=2))
        return 0x87e007000020ll + 0x40ll * ((a) & 0x3);
    __bdk_csr_fatal("CER_ERRX_MISC0", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRX_MISC0(a) bdk_cer_errx_misc0_t
#define bustype_BDK_CER_ERRX_MISC0(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRX_MISC0(a) "CER_ERRX_MISC0"
#define device_bar_BDK_CER_ERRX_MISC0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRX_MISC0(a) (a)
#define arguments_BDK_CER_ERRX_MISC0(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_err#_misc1
 *
 * CER Error Record Miscellanious Syndrome Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errx_misc1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tbd                   : 64; /**< [ 63:  0](R/W/H) Implementation defined error syndrome. */
#else /* Word 0 - Little Endian */
        uint64_t tbd                   : 64; /**< [ 63:  0](R/W/H) Implementation defined error syndrome. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errx_misc1_s cn; */
} bdk_cer_errx_misc1_t;

static inline uint64_t BDK_CER_ERRX_MISC1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRX_MISC1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=2))
        return 0x87e007000028ll + 0x40ll * ((a) & 0x3);
    __bdk_csr_fatal("CER_ERRX_MISC1", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRX_MISC1(a) bdk_cer_errx_misc1_t
#define bustype_BDK_CER_ERRX_MISC1(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRX_MISC1(a) "CER_ERRX_MISC1"
#define device_bar_BDK_CER_ERRX_MISC1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRX_MISC1(a) (a)
#define arguments_BDK_CER_ERRX_MISC1(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_err#_status
 *
 * CER Error Record Primaray Status Register
 * Indicates the error record information.
 *
 * After reading the status register, software must W1C the valid bits to allow new
 * errors to be recorded.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t av                    : 1;  /**< [ 31: 31](R/W1C/H) Address valid. CER_ERR()_ADDR contains a physical address associated with the
                                                                 highest priority error recorded by this record.

                                                                 Direct writes to this bit are ignored if any of the [CE], [DE], or [UE] bits is
                                                                 set, and the highest priority of these is not being cleared to 0 in the same
                                                                 write. */
        uint64_t v                     : 1;  /**< [ 30: 30](R/W1C/H) Status register valid.  CER_ERR()_STATUS valid. At least one error has been recorded.

                                                                 Direct writes to this bit are ignored if any of the [UE], [DE], or [CE] bits is
                                                                 set and is not being cleared to 0 in the same write. */
        uint64_t ue                    : 1;  /**< [ 29: 29](R/W1C/H) Uncorrected error(s).
                                                                 0 = No errors that could not be corrected or deferred.
                                                                 1 = At least one error detected that has not been corrected or deferred.

                                                                 Direct writes to this bit are ignored if [OF] is set and is not being cleared to
                                                                 zero in the same write. */
        uint64_t er                    : 1;  /**< [ 28: 28](R/W1C/H) Error reported.
                                                                 0 = No external abort reported.
                                                                 1 = The applicable one of the CER_ERR()_CTLR{WUE},[RUE],[UE] bits was set when
                                                                 an uncorrected error was detected, meaning an external abort was signaled to the
                                                                 master making the access.

                                                                 Direct writes to this bit are ignored if any of [CE], [DE], or [UE] is set, and
                                                                 the highest priority of these is not being cleared to 0 in the same write.

                                                                 Cleared for a corrected error.

                                                                 Internal:
                                                                 It is implementation defined whether this bit can be set for a deferred error. */
        uint64_t of                    : 1;  /**< [ 27: 27](R/W1C/H) Overflow. Multiple errors detected. This bit is set when:

                                                                 * An uncorrected error is detected and the previous error syndrome is kept
                                                                 because [UE] = 1.

                                                                 * A deferred error is detected and the previous error syndrome is kept is
                                                                 discarded because [DE] = 1.

                                                                 * A corrected error is detected and the corrected error counter overflows (or
                                                                 is not implemented).

                                                                 For more information see the ARM RAS standard.

                                                                 In CER, this bit only asserts if error events are lost (FIFO overfilled). */
        uint64_t mv                    : 1;  /**< [ 26: 26](R/W1C/H) Miscellaneous registers valid. The CER_ERR()_MISC0 and CER_ERR()_MISC1 contains
                                                                 additional information for an error recorded by this record.

                                                                 Direct writes to this bit are ignored if any of [CE], [DE], or [UE] is set, and
                                                                 the highest priority of these is not being cleared to 0 in the same write. This
                                                                 bit is read/write-one-to-clear. */
        uint64_t ce                    : 2;  /**< [ 25: 24](R/W1C/H) Corrected error(s).
                                                                 0x0 = No corrected errors recorded.
                                                                 0x1 = At least one transient corrected error recorded.
                                                                 0x2 = At least one corrected error recorded.
                                                                 0x3 = At least one persistent corrected error recorded.

                                                                 For CNXXXX, only codes 0x0 and 0x3 are used. */
        uint64_t de                    : 1;  /**< [ 23: 23](R/W1C/H) Deferred error(s). At least one error was not corrected and deferred.

                                                                 Direct writes to this bit are ignored if [OF] is set and is not being cleared
                                                                 to 0 in the same write. */
        uint64_t pn                    : 1;  /**< [ 22: 22](R/W1C/H) Poison.
                                                                 0 = Uncorrected or deferred error from a corrupted value. If a node
                                                                 detects a corrupted value and defers the error by producing poison, then this
                                                                 bit is set to 0 at the producer node.

                                                                 1 = Uncorrected error or Deferred error from a poisoned value. Indicates that an
                                                                 error was due to detecting a poison value rather than detecting a corrupted
                                                                 value.

                                                                 Valid only if at least one of [UE] or [DE] are set, otherwise 0x0.

                                                                 Direct writes to this bit are ignored if any of [CE], [DE], or [UE] is set, and
                                                                 the highest priority of these is not being cleared to 0 in the same write. */
        uint64_t uet                   : 2;  /**< [ 21: 20](R/W1C/H) Uncorrected error type. Describes the state of the component after detecting
                                                                 or consuming an uncorrected error.

                                                                 0x0 = Uncorrected error, Uncontainable error (UC).
                                                                 0x1 = Uncorrected error, Unrecoverable error (UEU).
                                                                 0x2 = Uncorrected error, Latent or restartable error (UEO).
                                                                 0x3 = Uncorrected error, Signaled or recoverable error (UER).

                                                                 Valid only if [UE] is set, otherwise 0x0.

                                                                 Direct writes to this field are ignored if any of [CE], [DE], or [UE] is set,
                                                                 and the highest priority of these is not being cleared to 0 in the same write. */
        uint64_t reserved_16_19        : 4;
        uint64_t ierr                  : 8;  /**< [ 15:  8](R/W/H) Implementation defined  error code.

                                                                 Direct writes to this field are ignored if any of the [CE], [DE], or [UE] is
                                                                 set, and the highest priority of these is not being cleared to 0 in the same
                                                                 write. */
        uint64_t serr                  : 8;  /**< [  7:  0](R/W) Architecturally-defined primary error code. Indicates the type of error
                                                                 enumerated by CER_SERR_E.

                                                                 Direct writes to this field are ignored if any of the [CE], [DE], or [UE] is
                                                                 set, and the highest priority of these is not being cleared to 0 in the same
                                                                 write. */
#else /* Word 0 - Little Endian */
        uint64_t serr                  : 8;  /**< [  7:  0](R/W) Architecturally-defined primary error code. Indicates the type of error
                                                                 enumerated by CER_SERR_E.

                                                                 Direct writes to this field are ignored if any of the [CE], [DE], or [UE] is
                                                                 set, and the highest priority of these is not being cleared to 0 in the same
                                                                 write. */
        uint64_t ierr                  : 8;  /**< [ 15:  8](R/W/H) Implementation defined  error code.

                                                                 Direct writes to this field are ignored if any of the [CE], [DE], or [UE] is
                                                                 set, and the highest priority of these is not being cleared to 0 in the same
                                                                 write. */
        uint64_t reserved_16_19        : 4;
        uint64_t uet                   : 2;  /**< [ 21: 20](R/W1C/H) Uncorrected error type. Describes the state of the component after detecting
                                                                 or consuming an uncorrected error.

                                                                 0x0 = Uncorrected error, Uncontainable error (UC).
                                                                 0x1 = Uncorrected error, Unrecoverable error (UEU).
                                                                 0x2 = Uncorrected error, Latent or restartable error (UEO).
                                                                 0x3 = Uncorrected error, Signaled or recoverable error (UER).

                                                                 Valid only if [UE] is set, otherwise 0x0.

                                                                 Direct writes to this field are ignored if any of [CE], [DE], or [UE] is set,
                                                                 and the highest priority of these is not being cleared to 0 in the same write. */
        uint64_t pn                    : 1;  /**< [ 22: 22](R/W1C/H) Poison.
                                                                 0 = Uncorrected or deferred error from a corrupted value. If a node
                                                                 detects a corrupted value and defers the error by producing poison, then this
                                                                 bit is set to 0 at the producer node.

                                                                 1 = Uncorrected error or Deferred error from a poisoned value. Indicates that an
                                                                 error was due to detecting a poison value rather than detecting a corrupted
                                                                 value.

                                                                 Valid only if at least one of [UE] or [DE] are set, otherwise 0x0.

                                                                 Direct writes to this bit are ignored if any of [CE], [DE], or [UE] is set, and
                                                                 the highest priority of these is not being cleared to 0 in the same write. */
        uint64_t de                    : 1;  /**< [ 23: 23](R/W1C/H) Deferred error(s). At least one error was not corrected and deferred.

                                                                 Direct writes to this bit are ignored if [OF] is set and is not being cleared
                                                                 to 0 in the same write. */
        uint64_t ce                    : 2;  /**< [ 25: 24](R/W1C/H) Corrected error(s).
                                                                 0x0 = No corrected errors recorded.
                                                                 0x1 = At least one transient corrected error recorded.
                                                                 0x2 = At least one corrected error recorded.
                                                                 0x3 = At least one persistent corrected error recorded.

                                                                 For CNXXXX, only codes 0x0 and 0x3 are used. */
        uint64_t mv                    : 1;  /**< [ 26: 26](R/W1C/H) Miscellaneous registers valid. The CER_ERR()_MISC0 and CER_ERR()_MISC1 contains
                                                                 additional information for an error recorded by this record.

                                                                 Direct writes to this bit are ignored if any of [CE], [DE], or [UE] is set, and
                                                                 the highest priority of these is not being cleared to 0 in the same write. This
                                                                 bit is read/write-one-to-clear. */
        uint64_t of                    : 1;  /**< [ 27: 27](R/W1C/H) Overflow. Multiple errors detected. This bit is set when:

                                                                 * An uncorrected error is detected and the previous error syndrome is kept
                                                                 because [UE] = 1.

                                                                 * A deferred error is detected and the previous error syndrome is kept is
                                                                 discarded because [DE] = 1.

                                                                 * A corrected error is detected and the corrected error counter overflows (or
                                                                 is not implemented).

                                                                 For more information see the ARM RAS standard.

                                                                 In CER, this bit only asserts if error events are lost (FIFO overfilled). */
        uint64_t er                    : 1;  /**< [ 28: 28](R/W1C/H) Error reported.
                                                                 0 = No external abort reported.
                                                                 1 = The applicable one of the CER_ERR()_CTLR{WUE},[RUE],[UE] bits was set when
                                                                 an uncorrected error was detected, meaning an external abort was signaled to the
                                                                 master making the access.

                                                                 Direct writes to this bit are ignored if any of [CE], [DE], or [UE] is set, and
                                                                 the highest priority of these is not being cleared to 0 in the same write.

                                                                 Cleared for a corrected error.

                                                                 Internal:
                                                                 It is implementation defined whether this bit can be set for a deferred error. */
        uint64_t ue                    : 1;  /**< [ 29: 29](R/W1C/H) Uncorrected error(s).
                                                                 0 = No errors that could not be corrected or deferred.
                                                                 1 = At least one error detected that has not been corrected or deferred.

                                                                 Direct writes to this bit are ignored if [OF] is set and is not being cleared to
                                                                 zero in the same write. */
        uint64_t v                     : 1;  /**< [ 30: 30](R/W1C/H) Status register valid.  CER_ERR()_STATUS valid. At least one error has been recorded.

                                                                 Direct writes to this bit are ignored if any of the [UE], [DE], or [CE] bits is
                                                                 set and is not being cleared to 0 in the same write. */
        uint64_t av                    : 1;  /**< [ 31: 31](R/W1C/H) Address valid. CER_ERR()_ADDR contains a physical address associated with the
                                                                 highest priority error recorded by this record.

                                                                 Direct writes to this bit are ignored if any of the [CE], [DE], or [UE] bits is
                                                                 set, and the highest priority of these is not being cleared to 0 in the same
                                                                 write. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errx_status_s cn; */
} bdk_cer_errx_status_t;

static inline uint64_t BDK_CER_ERRX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRX_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=2))
        return 0x87e007000010ll + 0x40ll * ((a) & 0x3);
    __bdk_csr_fatal("CER_ERRX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRX_STATUS(a) bdk_cer_errx_status_t
#define bustype_BDK_CER_ERRX_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRX_STATUS(a) "CER_ERRX_STATUS"
#define device_bar_BDK_CER_ERRX_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRX_STATUS(a) (a)
#define arguments_BDK_CER_ERRX_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_errdevaff
 *
 * CER Device Affinity Register
 * For a group that has an affinity to a PE or cluster of PEs, this register is a
 * read-only copy of AP_MPIDR_EL1.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errdevaff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t devaff                : 64; /**< [ 63:  0](RO) For CNXXXX CER, indicates no CPU affinity for CER block.
                                                                 Internal:
                                                                 For AP version of this register, define as an inherit of AP_MIDR_EL1. */
#else /* Word 0 - Little Endian */
        uint64_t devaff                : 64; /**< [ 63:  0](RO) For CNXXXX CER, indicates no CPU affinity for CER block.
                                                                 Internal:
                                                                 For AP version of this register, define as an inherit of AP_MIDR_EL1. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errdevaff_s cn; */
} bdk_cer_errdevaff_t;

#define BDK_CER_ERRDEVAFF BDK_CER_ERRDEVAFF_FUNC()
static inline uint64_t BDK_CER_ERRDEVAFF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRDEVAFF_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fa8ll;
    __bdk_csr_fatal("CER_ERRDEVAFF", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_ERRDEVAFF bdk_cer_errdevaff_t
#define bustype_BDK_CER_ERRDEVAFF BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRDEVAFF "CER_ERRDEVAFF"
#define device_bar_BDK_CER_ERRDEVAFF 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRDEVAFF 0
#define arguments_BDK_CER_ERRDEVAFF -1,-1,-1,-1

/**
 * Register (RSL32b) cer_errdevarch
 *
 * CER Device Architecture Register
 * This register identifies the programmers' model architecture of the component.
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_errdevarch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t architect             : 11; /**< [ 31: 21](RO) Architect of the component.  Indicates ARM. */
        uint32_t present               : 1;  /**< [ 20: 20](RO) Defines that this register is present. */
        uint32_t revision              : 4;  /**< [ 19: 16](RO) Defines the architecture revision.
                                                                 0x0 = RAS system architecture v1.0. */
        uint32_t archver               : 4;  /**< [ 15: 12](RO) Defines the architecture version of the component.
                                                                 0x0 = RAS system architecture v1.0. */
        uint32_t archpart              : 12; /**< [ 11:  0](RO) Defines the architecture of the component.
                                                                 0xA00 = RAS system architecture. */
#else /* Word 0 - Little Endian */
        uint32_t archpart              : 12; /**< [ 11:  0](RO) Defines the architecture of the component.
                                                                 0xA00 = RAS system architecture. */
        uint32_t archver               : 4;  /**< [ 15: 12](RO) Defines the architecture version of the component.
                                                                 0x0 = RAS system architecture v1.0. */
        uint32_t revision              : 4;  /**< [ 19: 16](RO) Defines the architecture revision.
                                                                 0x0 = RAS system architecture v1.0. */
        uint32_t present               : 1;  /**< [ 20: 20](RO) Defines that this register is present. */
        uint32_t architect             : 11; /**< [ 31: 21](RO) Architect of the component.  Indicates ARM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errdevarch_s cn; */
} bdk_cer_errdevarch_t;

#define BDK_CER_ERRDEVARCH BDK_CER_ERRDEVARCH_FUNC()
static inline uint64_t BDK_CER_ERRDEVARCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRDEVARCH_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fbcll;
    __bdk_csr_fatal("CER_ERRDEVARCH", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_ERRDEVARCH bdk_cer_errdevarch_t
#define bustype_BDK_CER_ERRDEVARCH BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_ERRDEVARCH "CER_ERRDEVARCH"
#define device_bar_BDK_CER_ERRDEVARCH 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRDEVARCH 0
#define arguments_BDK_CER_ERRDEVARCH -1,-1,-1,-1

/**
 * Register (RSL) cer_errgsr#
 *
 * CER Group Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errgsrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t s                     : 64; /**< [ 63:  0](RO/H) Shows the status for the records, a read-only copy of CER_ERR()_STATUS[V]:
                                                                    0 = No error.
                                                                    1 = One or more errors.

                                                                 Each bit corresponds to the status for 64 records, in groups of
                                                                 64 determined by the address index to this register.

                                                                 Bits above the maximum implemented index number are 0. */
#else /* Word 0 - Little Endian */
        uint64_t s                     : 64; /**< [ 63:  0](RO/H) Shows the status for the records, a read-only copy of CER_ERR()_STATUS[V]:
                                                                    0 = No error.
                                                                    1 = One or more errors.

                                                                 Each bit corresponds to the status for 64 records, in groups of
                                                                 64 determined by the address index to this register.

                                                                 Bits above the maximum implemented index number are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errgsrx_s cn; */
} bdk_cer_errgsrx_t;

static inline uint64_t BDK_CER_ERRGSRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRGSRX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x87e007000e00ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("CER_ERRGSRX", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRGSRX(a) bdk_cer_errgsrx_t
#define bustype_BDK_CER_ERRGSRX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRGSRX(a) "CER_ERRGSRX"
#define device_bar_BDK_CER_ERRGSRX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRGSRX(a) (a)
#define arguments_BDK_CER_ERRGSRX(a) (a),-1,-1,-1

/**
 * Register (RSL32b) cer_erridr
 *
 * CER Error Record ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_erridr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t num                   : 32; /**< [ 31:  0](RO) Number of records in this group. */
#else /* Word 0 - Little Endian */
        uint32_t num                   : 32; /**< [ 31:  0](RO) Number of records in this group. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_erridr_s cn; */
} bdk_cer_erridr_t;

#define BDK_CER_ERRIDR BDK_CER_ERRIDR_FUNC()
static inline uint64_t BDK_CER_ERRIDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRIDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fc8ll;
    __bdk_csr_fatal("CER_ERRIDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_ERRIDR bdk_cer_erridr_t
#define bustype_BDK_CER_ERRIDR BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_ERRIDR "CER_ERRIDR"
#define device_bar_BDK_CER_ERRIDR 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRIDR 0
#define arguments_BDK_CER_ERRIDR -1,-1,-1,-1

/**
 * Register (RSL) cer_errirqcr#
 *
 * CER Error Interrupt Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_errirqcrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_errirqcrx_s cn; */
} bdk_cer_errirqcrx_t;

static inline uint64_t BDK_CER_ERRIRQCRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_ERRIRQCRX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=14))
        return 0x87e007000e80ll + 8ll * ((a) & 0xf);
    __bdk_csr_fatal("CER_ERRIRQCRX", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_ERRIRQCRX(a) bdk_cer_errirqcrx_t
#define bustype_BDK_CER_ERRIRQCRX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_ERRIRQCRX(a) "CER_ERRIRQCRX"
#define device_bar_BDK_CER_ERRIRQCRX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_ERRIRQCRX(a) (a)
#define arguments_BDK_CER_ERRIRQCRX(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_fixme_for_csr3
 *
 * INTERNAL: CER General Purpose Scratch Register
 *
 * These registers are only reset by hardware during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_fixme_for_csr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t fixme_for_csr3        : 8;  /**< [  7:  0](R/W) General purpose scratch register. */
#else /* Word 0 - Little Endian */
        uint64_t fixme_for_csr3        : 8;  /**< [  7:  0](R/W) General purpose scratch register. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_fixme_for_csr3_s cn; */
} bdk_cer_fixme_for_csr3_t;

#define BDK_CER_FIXME_FOR_CSR3 BDK_CER_FIXME_FOR_CSR3_FUNC()
static inline uint64_t BDK_CER_FIXME_FOR_CSR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_FIXME_FOR_CSR3_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007001300ll;
    __bdk_csr_fatal("CER_FIXME_FOR_CSR3", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_FIXME_FOR_CSR3 bdk_cer_fixme_for_csr3_t
#define bustype_BDK_CER_FIXME_FOR_CSR3 BDK_CSR_TYPE_RSL
#define basename_BDK_CER_FIXME_FOR_CSR3 "CER_FIXME_FOR_CSR3"
#define device_bar_BDK_CER_FIXME_FOR_CSR3 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_FIXME_FOR_CSR3 0
#define arguments_BDK_CER_FIXME_FOR_CSR3 -1,-1,-1,-1

/**
 * Register (RSL) cer_msix_pba#
 *
 * CER MSI-X Pending-Bit-Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the
 * CER_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CER()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CER_PF_INT_VEC_E. Bits that have no associated CER_PF_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CER()_PF_MSIX_VEC()_CTL, enumerated by
                                                                 CER_PF_INT_VEC_E. Bits that have no associated CER_PF_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_msix_pbax_s cn; */
} bdk_cer_msix_pbax_t;

static inline uint64_t BDK_CER_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x87e007ff0008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("CER_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_MSIX_PBAX(a) bdk_cer_msix_pbax_t
#define bustype_BDK_CER_MSIX_PBAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_MSIX_PBAX(a) "CER_MSIX_PBAX"
#define device_bar_BDK_CER_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_CER_MSIX_PBAX(a) (a)
#define arguments_BDK_CER_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_msix_vec#_addr
 *
 * CER MSI-X Vector-Table Address Registers
 * This register is the MSI-X vector table, indexed by the CER_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t addr                  : 51; /**< [ 52:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's CER()_PF_MSIX_VEC()_ADDR, CER()_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CER()_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_CER_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's CER()_PF_MSIX_VEC()_ADDR, CER()_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CER()_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_CER_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 51; /**< [ 52:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_msix_vecx_addr_s cn; */
} bdk_cer_msix_vecx_addr_t;

static inline uint64_t BDK_CER_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x87e007f00000ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("CER_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_MSIX_VECX_ADDR(a) bdk_cer_msix_vecx_addr_t
#define bustype_BDK_CER_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_MSIX_VECX_ADDR(a) "CER_MSIX_VECX_ADDR"
#define device_bar_BDK_CER_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_CER_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_CER_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) cer_msix_vec#_ctl
 *
 * CER MSI-X Vector-Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the CER_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cer_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 32; /**< [ 31:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_msix_vecx_ctl_s cn; */
} bdk_cer_msix_vecx_ctl_t;

static inline uint64_t BDK_CER_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a==0))
        return 0x87e007f00008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("CER_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CER_MSIX_VECX_CTL(a) bdk_cer_msix_vecx_ctl_t
#define bustype_BDK_CER_MSIX_VECX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CER_MSIX_VECX_CTL(a) "CER_MSIX_VECX_CTL"
#define device_bar_BDK_CER_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_CER_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_CER_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL32b) cer_pidr0
 *
 * CER Peripheral Identification Register 0
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::RAS. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::RAS. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr0_s cn; */
} bdk_cer_pidr0_t;

#define BDK_CER_PIDR0 BDK_CER_PIDR0_FUNC()
static inline uint64_t BDK_CER_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fe0ll;
    __bdk_csr_fatal("CER_PIDR0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR0 bdk_cer_pidr0_t
#define bustype_BDK_CER_PIDR0 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR0 "CER_PIDR0"
#define device_bar_BDK_CER_PIDR0 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR0 0
#define arguments_BDK_CER_PIDR0 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr1
 *
 * CER Peripheral Identification Register 1
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t partnum1              : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t idcode                : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr1_s cn; */
} bdk_cer_pidr1_t;

#define BDK_CER_PIDR1 BDK_CER_PIDR1_FUNC()
static inline uint64_t BDK_CER_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fe4ll;
    __bdk_csr_fatal("CER_PIDR1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR1 bdk_cer_pidr1_t
#define bustype_BDK_CER_PIDR1 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR1 "CER_PIDR1"
#define device_bar_BDK_CER_PIDR1 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR1 0
#define arguments_BDK_CER_PIDR1 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr2
 *
 * CER Peripheral Identification Register 2
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) SMMU Revision.
                                                                 0x0 = SMMUv1.
                                                                 0x1 = SMMUv2. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t idcode                : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) SMMU Revision.
                                                                 0x0 = SMMUv1.
                                                                 0x1 = SMMUv2. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr2_s cn; */
} bdk_cer_pidr2_t;

#define BDK_CER_PIDR2 BDK_CER_PIDR2_FUNC()
static inline uint64_t BDK_CER_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fe8ll;
    __bdk_csr_fatal("CER_PIDR2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR2 bdk_cer_pidr2_t
#define bustype_BDK_CER_PIDR2 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR2 "CER_PIDR2"
#define device_bar_BDK_CER_PIDR2 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR2 0
#define arguments_BDK_CER_PIDR2 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr3
 *
 * CER Peripheral Identification Register 3
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cust                  : 4;  /**< [  3:  0](RO) Customer modified. 1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr3_s cn; */
} bdk_cer_pidr3_t;

#define BDK_CER_PIDR3 BDK_CER_PIDR3_FUNC()
static inline uint64_t BDK_CER_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR3_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fecll;
    __bdk_csr_fatal("CER_PIDR3", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR3 bdk_cer_pidr3_t
#define bustype_BDK_CER_PIDR3 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR3 "CER_PIDR3"
#define device_bar_BDK_CER_PIDR3 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR3 0
#define arguments_BDK_CER_PIDR3 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr4
 *
 * CER Peripheral Identification Register 4
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied.
                                                                 Internal:
                                                                 FIXME to indicate number of 4KB pages. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied.
                                                                 Internal:
                                                                 FIXME to indicate number of 4KB pages. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr4_s cn; */
} bdk_cer_pidr4_t;

#define BDK_CER_PIDR4 BDK_CER_PIDR4_FUNC()
static inline uint64_t BDK_CER_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR4_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fd0ll;
    __bdk_csr_fatal("CER_PIDR4", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR4 bdk_cer_pidr4_t
#define bustype_BDK_CER_PIDR4 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR4 "CER_PIDR4"
#define device_bar_BDK_CER_PIDR4 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR4 0
#define arguments_BDK_CER_PIDR4 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr5
 *
 * CER Peripheral Identification Register 5
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr5_s cn; */
} bdk_cer_pidr5_t;

#define BDK_CER_PIDR5 BDK_CER_PIDR5_FUNC()
static inline uint64_t BDK_CER_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR5_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fd4ll;
    __bdk_csr_fatal("CER_PIDR5", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR5 bdk_cer_pidr5_t
#define bustype_BDK_CER_PIDR5 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR5 "CER_PIDR5"
#define device_bar_BDK_CER_PIDR5 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR5 0
#define arguments_BDK_CER_PIDR5 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr6
 *
 * CER Peripheral Identification Register 6
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr6_s cn; */
} bdk_cer_pidr6_t;

#define BDK_CER_PIDR6 BDK_CER_PIDR6_FUNC()
static inline uint64_t BDK_CER_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR6_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fd8ll;
    __bdk_csr_fatal("CER_PIDR6", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR6 bdk_cer_pidr6_t
#define bustype_BDK_CER_PIDR6 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR6 "CER_PIDR6"
#define device_bar_BDK_CER_PIDR6 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR6 0
#define arguments_BDK_CER_PIDR6 -1,-1,-1,-1

/**
 * Register (RSL32b) cer_pidr7
 *
 * CER Peripheral Identification Register 7
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_cer_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cer_pidr7_s cn; */
} bdk_cer_pidr7_t;

#define BDK_CER_PIDR7 BDK_CER_PIDR7_FUNC()
static inline uint64_t BDK_CER_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CER_PIDR7_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e007000fdcll;
    __bdk_csr_fatal("CER_PIDR7", 0, 0, 0, 0, 0);
}

#define typedef_BDK_CER_PIDR7 bdk_cer_pidr7_t
#define bustype_BDK_CER_PIDR7 BDK_CSR_TYPE_RSL32b
#define basename_BDK_CER_PIDR7 "CER_PIDR7"
#define device_bar_BDK_CER_PIDR7 0x0 /* PF_BAR0 */
#define busnum_BDK_CER_PIDR7 0
#define arguments_BDK_CER_PIDR7 -1,-1,-1,-1

#endif /* __BDK_CSRS_CER_H__ */
