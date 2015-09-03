#ifndef __BDK_CSRS_SMMU_H__
#define __BDK_CSRS_SMMU_H__
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
 * Cavium SMMU.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration smmu_bar_e
 *
 * SMMU Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_SMMU_BAR_E_SMMUX_PF_BAR0(a) (0x830000000000ll + 0x1000000000ll * (a)) /**< Base address for standard registers. */
#define BDK_SMMU_BAR_E_SMMUX_PF_BAR4(a) (0x83000f000000ll + 0x1000000000ll * (a)) /**< Base address for MSI-X registers. */

/**
 * Enumeration smmu_ctype_e
 *
 * SMMU Context Bank Type Enumeration
 * Enumerates the values of SMMU()_CBAR()[CTYPE].
 */
#define BDK_SMMU_CTYPE_E_STAGE1_BYP2 (1) /**< Stage 1 contact with stage 2 bypass. */
#define BDK_SMMU_CTYPE_E_STAGE1_FAULT2 (2) /**< Stage 1 contact with stage 2 fault. */
#define BDK_SMMU_CTYPE_E_STAGE1_STAGE2 (3) /**< Stage 1 contact with stage 2 nested translation. */
#define BDK_SMMU_CTYPE_E_STAGE2 (0) /**< Stage 2 context. */

/**
 * Enumeration smmu_int_vec_e
 *
 * SMMU MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_SMMU_INT_VEC_E_CBX_FSR_CN81XX(a) (0 + 2 * (a)) /**< See interrupt clears SMMU(0)_CB(0..63)_FSR[MULTI, ASF, TMBMCF, EF, PF, AFF, TF], sets
                                       SMMU(0)_CB(0..63)_FSRRESTORE[MULTI, ASF, TMBMCF, EF, PF, AFF, TF], and enables
                                       SMMU(0)_CB(0..63)_SCTLR[CFIE, CFIE, CFIE, CFIE, CFIE, CFIE, CFIE]. (CFIE is a common
                                       enable.) */
#define BDK_SMMU_INT_VEC_E_CBX_FSR_CN88XX(a) (0 + 2 * (a)) /**< See interrupt clears SMMU(0..3)_CB(0..127)_FSR[MULTI, ASF, TMBMCF, EF, PF, AFF, TF], sets
                                       SMMU(0..3)_CB(0..127)_FSRRESTORE[MULTI, ASF, TMBMCF, EF, PF, AFF, TF], and enables
                                       SMMU(0..3)_CB(0..127)_SCTLR[CFIE, CFIE, CFIE, CFIE, CFIE, CFIE, CFIE]. (CFIE is a common
                                       enable.) */
#define BDK_SMMU_INT_VEC_E_CBX_FSR_CN83XX(a) (0 + 2 * (a)) /**< See interrupt clears SMMU(0..3)_CB(0..127)_FSR[MULTI, ASF, TMBMCF, EF, PF, AFF, TF], sets
                                       SMMU(0..3)_CB(0..127)_FSRRESTORE[MULTI, ASF, TMBMCF, EF, PF, AFF, TF], and enables
                                       SMMU(0..3)_CB(0..127)_SCTLR[CFIE, CFIE, CFIE, CFIE, CFIE, CFIE, CFIE]. (CFIE is a common
                                       enable.) */
#define BDK_SMMU_INT_VEC_E_CBX_FSR_CLEAR(a) (1 + 2 * (a)) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_ERRFLG_CN81XX (0x84) /**< See interrupt clears SMMU(0)_ERR_INT, interrupt sets SMMU(0)_ERR_INT_W1S, enable
                                       clears SMMU(0)_ERR_ENA_W1C, and enable sets SMMU(0)_ERR_ENA_W1S. */
#define BDK_SMMU_INT_VEC_E_ERRFLG_CN88XX (0x104) /**< See interrupt clears SMMU(0..3)_ERR_INT, interrupt sets SMMU(0..3)_ERR_INT_W1S, enable
                                       clears SMMU(0..3)_ERR_ENA_W1C, and enable sets SMMU(0..3)_ERR_ENA_W1S. */
#define BDK_SMMU_INT_VEC_E_ERRFLG_CN83XX (0x104) /**< See interrupt clears SMMU(0..3)_ERR_INT, interrupt sets SMMU(0..3)_ERR_INT_W1S, enable
                                       clears SMMU(0..3)_ERR_ENA_W1C, and enable sets SMMU(0..3)_ERR_ENA_W1S. */
#define BDK_SMMU_INT_VEC_E_ERR_CLEAR_CN81XX (0x85) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_ERR_CLEAR_CN88XX (0x105) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_ERR_CLEAR_CN83XX (0x105) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_NSGFSR_CN81XX (0x80) /**< See interrupt clears SMMU(0)_(S)GFSR[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF,
                                       ICF], sets SMMU(0)_(S)GFSRRESTORE[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF, ICF]
                                       and enables SMMU(0)_(S)CR0[GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE].
                                       (GFIE is a common enable.) Applies only to non-secure mode. */
#define BDK_SMMU_INT_VEC_E_NSGFSR_CN88XX (0x100) /**< See interrupt clears SMMU(0..3)_(S)GFSR[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF,
                                       ICF], sets SMMU(0..3)_(S)GFSRRESTORE[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF, ICF]
                                       and enables SMMU(0..3)_(S)CR0[GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE].
                                       (GFIE is a common enable.) Applies only to non-secure mode. */
#define BDK_SMMU_INT_VEC_E_NSGFSR_CN83XX (0x100) /**< See interrupt clears SMMU(0..3)_(S)GFSR[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF,
                                       ICF], sets SMMU(0..3)_(S)GFSRRESTORE[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF, ICF]
                                       and enables SMMU(0..3)_(S)CR0[GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE].
                                       (GFIE is a common enable.) Applies only to non-secure mode. */
#define BDK_SMMU_INT_VEC_E_NSGFSR_CLEAR_CN81XX (0x81) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_NSGFSR_CLEAR_CN88XX (0x101) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_NSGFSR_CLEAR_CN83XX (0x101) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_SGFSR_CN81XX (0x82) /**< See interrupt clears SMMU(0)_(S)GFSR[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF,
                                       ICF], sets SMMU(0)_(S)GFSRRESTORE[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF, ICF]
                                       and enables SMMU(0)_(S)CR0[GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE].
                                       (GFIE is a common enable.) Applies only to secure mode. */
#define BDK_SMMU_INT_VEC_E_SGFSR_CN88XX (0x102) /**< See interrupt clears SMMU(0..3)_(S)GFSR[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF,
                                       ICF], sets SMMU(0..3)_(S)GFSRRESTORE[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF, ICF]
                                       and enables SMMU(0..3)_(S)CR0[GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE].
                                       (GFIE is a common enable.) Applies only to secure mode. */
#define BDK_SMMU_INT_VEC_E_SGFSR_CN83XX (0x102) /**< See interrupt clears SMMU(0..3)_(S)GFSR[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF,
                                       ICF], sets SMMU(0..3)_(S)GFSRRESTORE[MULTI, UUT, FP, EF, CAF, UCIF, UCBF, SMCF, USF, ICF]
                                       and enables SMMU(0..3)_(S)CR0[GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE, GFIE].
                                       (GFIE is a common enable.) Applies only to secure mode. */
#define BDK_SMMU_INT_VEC_E_SGFSR_CLEAR_CN81XX (0x83) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_SGFSR_CLEAR_CN88XX (0x103) /**< Level sensitive interrupt clear vector. */
#define BDK_SMMU_INT_VEC_E_SGFSR_CLEAR_CN83XX (0x103) /**< Level sensitive interrupt clear vector. */

/**
 * Register (NCB) smmu#_active_pc
 *
 * SMMU Active Cycles Register
 * This register counts every core-clock cycle that the SMMU clocks are active.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_active_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](RO/H) Counts the number of active core-clock cycles in the conditional clock domain. INTERNAL:
                                                                 Values are duplicated across each SMMU that shares an IOB. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](RO/H) Counts the number of active core-clock cycles in the conditional clock domain. INTERNAL:
                                                                 Values are duplicated across each SMMU that shares an IOB. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_active_pc_s cn; */
} bdk_smmux_active_pc_t;

static inline uint64_t BDK_SMMUX_ACTIVE_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ACTIVE_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021000ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021000ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021000ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ACTIVE_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ACTIVE_PC(a) bdk_smmux_active_pc_t
#define bustype_BDK_SMMUX_ACTIVE_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ACTIVE_PC(a) "SMMUX_ACTIVE_PC"
#define busnum_BDK_SMMUX_ACTIVE_PC(a) (a)
#define arguments_BDK_SMMUX_ACTIVE_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_bist_status
 *
 * SMMU BIST Status Register
 * Contains the BIST status for the memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bist                  : 64; /**< [ 63:  0](RO) Memory BIST status. 0 = pass, 1 = fail. INTERNAL: Values are duplicated across each SMMU
                                                                 that shares an IOB.
                                                                 <23> = CSR_VMID_CAM.
                                                                 <22> = CSR_ASID_CAM.
                                                                 <21> = SIL_CAM.
                                                                 <20> = MSIX.
                                                                 <19> = WCTL.
                                                                 <18> = XL_MFIFO.
                                                                 <17> = TCTL.
                                                                 <16> = CONTEXT_IDR.
                                                                 <15> = CB_FRSYNRA.
                                                                 <14> = CB_IPAFAR.
                                                                 <13> = CB_FSYNR0.
                                                                 <12> = CB_FAR.
                                                                 <11> = S2CR.
                                                                 <10> = CB_ACTLR.
                                                                 <9> = CB_TCR2.
                                                                 <8> = SSDR.
                                                                 <7> = SCTLR.
                                                                 <6> = CB_TTBR0.
                                                                 <5> = CB_TTBR1.
                                                                 <4> = CB_TCR.
                                                                 <3> = CBA2R.
                                                                 <2> = CBAR.
                                                                 <1> = CB_MAIR0.
                                                                 <0> = CB_MAIR1. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 64; /**< [ 63:  0](RO) Memory BIST status. 0 = pass, 1 = fail. INTERNAL: Values are duplicated across each SMMU
                                                                 that shares an IOB.
                                                                 <23> = CSR_VMID_CAM.
                                                                 <22> = CSR_ASID_CAM.
                                                                 <21> = SIL_CAM.
                                                                 <20> = MSIX.
                                                                 <19> = WCTL.
                                                                 <18> = XL_MFIFO.
                                                                 <17> = TCTL.
                                                                 <16> = CONTEXT_IDR.
                                                                 <15> = CB_FRSYNRA.
                                                                 <14> = CB_IPAFAR.
                                                                 <13> = CB_FSYNR0.
                                                                 <12> = CB_FAR.
                                                                 <11> = S2CR.
                                                                 <10> = CB_ACTLR.
                                                                 <9> = CB_TCR2.
                                                                 <8> = SSDR.
                                                                 <7> = SCTLR.
                                                                 <6> = CB_TTBR0.
                                                                 <5> = CB_TTBR1.
                                                                 <4> = CB_TCR.
                                                                 <3> = CBA2R.
                                                                 <2> = CBAR.
                                                                 <1> = CB_MAIR0.
                                                                 <0> = CB_MAIR1. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_bist_status_s cn; */
} bdk_smmux_bist_status_t;

static inline uint64_t BDK_SMMUX_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020010ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020010ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020010ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_BIST_STATUS(a) bdk_smmux_bist_status_t
#define bustype_BDK_SMMUX_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_BIST_STATUS(a) "SMMUX_BIST_STATUS"
#define busnum_BDK_SMMUX_BIST_STATUS(a) (a)
#define arguments_BDK_SMMUX_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_cb#_actlr
 *
 * SMMU Context Auxiliary Control Register
 * This register contains implementation specific context fields.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_actlr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t qos                   : 4;  /**< [ 31: 28](R/W) L2C quality-of-service value to use for transactions to this context. */
        uint32_t reserved_16_27        : 12;
        uint32_t dis_bnk               : 16; /**< [ 15:  0](R/W) Bitmask of sections of TLB to disable for fills caused by transactions to this
                                                                 context. May be used to partition the TLB to achieve QoS; note the WCU is not likewise
                                                                 partitioned. If a context is marked secure but accessed insecurely, than this register is
                                                                 RAZ/WI. For nested translations, the primary context's DIS_BNK is used. */
#else /* Word 0 - Little Endian */
        uint32_t dis_bnk               : 16; /**< [ 15:  0](R/W) Bitmask of sections of TLB to disable for fills caused by transactions to this
                                                                 context. May be used to partition the TLB to achieve QoS; note the WCU is not likewise
                                                                 partitioned. If a context is marked secure but accessed insecurely, than this register is
                                                                 RAZ/WI. For nested translations, the primary context's DIS_BNK is used. */
        uint32_t reserved_16_27        : 12;
        uint32_t qos                   : 4;  /**< [ 31: 28](R/W) L2C quality-of-service value to use for transactions to this context. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_actlr_s cn; */
} bdk_smmux_cbx_actlr_t;

static inline uint64_t BDK_SMMUX_CBX_ACTLR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_ACTLR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000004ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000004ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000004ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_ACTLR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_ACTLR(a,b) bdk_smmux_cbx_actlr_t
#define bustype_BDK_SMMUX_CBX_ACTLR(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_ACTLR(a,b) "SMMUX_CBX_ACTLR"
#define busnum_BDK_SMMUX_CBX_ACTLR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_ACTLR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_contextidr
 *
 * SMMU Context Identification Register
 * Identifies the current process identifier. Used only by software.
 * This register is used by stage 1 context banks.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_contextidr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t procid                : 32; /**< [ 31:  0](R/W) Process identifier. Used only by software. */
#else /* Word 0 - Little Endian */
        uint32_t procid                : 32; /**< [ 31:  0](R/W) Process identifier. Used only by software. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_contextidr_s cn; */
} bdk_smmux_cbx_contextidr_t;

static inline uint64_t BDK_SMMUX_CBX_CONTEXTIDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_CONTEXTIDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000034ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000034ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000034ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_CONTEXTIDR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_CONTEXTIDR(a,b) bdk_smmux_cbx_contextidr_t
#define bustype_BDK_SMMUX_CBX_CONTEXTIDR(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_CONTEXTIDR(a,b) "SMMUX_CBX_CONTEXTIDR"
#define busnum_BDK_SMMUX_CBX_CONTEXTIDR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_CONTEXTIDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_far
 *
 * SMMU Context Fault Address Register
 * This register is used by both stage 1 and stage 2 context banks. This register might be
 * updated as the result of:
 *
 * 1. A stage 2 only context fault for an upstream client device. The IPA supplied by the
 * upstream client device is recorded.
 *
 * 2. A nested stage 1 + stage 2 fault. The VA supplied by the upstream client device to the
 * stage 1 context is recorded. Note: the IPA is not recorded but the fault is tagged as nested
 * and the index of the stage 1 context is recorded in SMMU()_CB()_FSYNR0.
 *
 * 3. An ATOS operation at stage 1 in a nested context that faults at stage 2. The VA supplied by
 * to the global or stage 1 address translation operation is recorded. The IPA is recorded in
 * SMMU()_CB()_IPAFAR below and the fault is tagged as nested. The index of the stage 1
 * context is recorded in SMMU()_CB()_FSYNR0.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_far_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t faddr                 : 37; /**< [ 48: 12](R/W/H) Fault address, the input IOVA of the faulting access. This register might be updated as
                                                                 the result of a translation fault for an upstream client device. For CNXXXX <11:0> are
                                                                 always zero. */
        uint64_t reserved_0_11         : 12;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_11         : 12;
        uint64_t faddr                 : 37; /**< [ 48: 12](R/W/H) Fault address, the input IOVA of the faulting access. This register might be updated as
                                                                 the result of a translation fault for an upstream client device. For CNXXXX <11:0> are
                                                                 always zero. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_far_s cn; */
} bdk_smmux_cbx_far_t;

static inline uint64_t BDK_SMMUX_CBX_FAR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FAR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000060ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000060ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000060ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_FAR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_FAR(a,b) bdk_smmux_cbx_far_t
#define bustype_BDK_SMMUX_CBX_FAR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_FAR(a,b) "SMMUX_CBX_FAR"
#define busnum_BDK_SMMUX_CBX_FAR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_FAR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_fsr
 *
 * SMMU Context Translation Fault Status Register
 * Provides memory system fault status information. This register is used by both stage 1 and
 * stage 2 context banks.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_fsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t multi                 : 1;  /**< [ 31: 31](R/W1C/H) Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in SMMU()_(S)GFSR was nonzero. */
        uint32_t ss                    : 1;  /**< [ 30: 30](RO) Stalled status.
                                                                 0 = SMMU not stalled due to a fault in this bank.
                                                                 1 = SMMU stalled due to a fault in this bank.

                                                                 For CNXXXX always zero, no stalls. */
        uint32_t reserved_11_29        : 19;
        uint32_t fmt                   : 2;  /**< [ 10:  9](RO) Translation scheme.
                                                                 0x0 = AArch32 short-descriptor translation scheme.
                                                                 0x1 = AArch32 long-descriptor translation scheme.
                                                                 0x2 = AArch64 translation scheme.
                                                                 0x3 = Reserved.

                                                                 For CNXXXX always AArch64. */
        uint32_t uut                   : 1;  /**< [  8:  8](RAZ) Unsupported upstream transaction fault. */
        uint32_t asf                   : 1;  /**< [  7:  7](R/W1C/H) Incorrect address size fault. */
        uint32_t tlblkf                : 1;  /**< [  6:  6](RAZ) TLB lock fault. For CNXXXX always zero, no TLB locks. */
        uint32_t tlbmcf                : 1;  /**< [  5:  5](R/W1C/H) TLB match conflict fault. */
        uint32_t ef                    : 1;  /**< [  4:  4](R/W1C/H) External fault. */
        uint32_t pf                    : 1;  /**< [  3:  3](R/W1C/H) Permission fault.
                                                                 0 = No permission fault.
                                                                 1 = Fault caused by insufficient permission to complete a memory access has occurred. */
        uint32_t aff                   : 1;  /**< [  2:  2](R/W1C/H) Access flag fault.
                                                                 0 = No access flag fault.
                                                                 1 = Fault caused by the access flag being set for the address being accessed has occurred. */
        uint32_t tf                    : 1;  /**< [  1:  1](R/W1C/H) Translation fault.
                                                                 0 = No translation fault.
                                                                 1 = Translation fault has occurred. The mapping for the address being accessed is invalid. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t tf                    : 1;  /**< [  1:  1](R/W1C/H) Translation fault.
                                                                 0 = No translation fault.
                                                                 1 = Translation fault has occurred. The mapping for the address being accessed is invalid. */
        uint32_t aff                   : 1;  /**< [  2:  2](R/W1C/H) Access flag fault.
                                                                 0 = No access flag fault.
                                                                 1 = Fault caused by the access flag being set for the address being accessed has occurred. */
        uint32_t pf                    : 1;  /**< [  3:  3](R/W1C/H) Permission fault.
                                                                 0 = No permission fault.
                                                                 1 = Fault caused by insufficient permission to complete a memory access has occurred. */
        uint32_t ef                    : 1;  /**< [  4:  4](R/W1C/H) External fault. */
        uint32_t tlbmcf                : 1;  /**< [  5:  5](R/W1C/H) TLB match conflict fault. */
        uint32_t tlblkf                : 1;  /**< [  6:  6](RAZ) TLB lock fault. For CNXXXX always zero, no TLB locks. */
        uint32_t asf                   : 1;  /**< [  7:  7](R/W1C/H) Incorrect address size fault. */
        uint32_t uut                   : 1;  /**< [  8:  8](RAZ) Unsupported upstream transaction fault. */
        uint32_t fmt                   : 2;  /**< [ 10:  9](RO) Translation scheme.
                                                                 0x0 = AArch32 short-descriptor translation scheme.
                                                                 0x1 = AArch32 long-descriptor translation scheme.
                                                                 0x2 = AArch64 translation scheme.
                                                                 0x3 = Reserved.

                                                                 For CNXXXX always AArch64. */
        uint32_t reserved_11_29        : 19;
        uint32_t ss                    : 1;  /**< [ 30: 30](RO) Stalled status.
                                                                 0 = SMMU not stalled due to a fault in this bank.
                                                                 1 = SMMU stalled due to a fault in this bank.

                                                                 For CNXXXX always zero, no stalls. */
        uint32_t multi                 : 1;  /**< [ 31: 31](R/W1C/H) Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in SMMU()_(S)GFSR was nonzero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_fsr_s cn; */
} bdk_smmux_cbx_fsr_t;

static inline uint64_t BDK_SMMUX_CBX_FSR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000058ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000058ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000058ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_FSR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_FSR(a,b) bdk_smmux_cbx_fsr_t
#define bustype_BDK_SMMUX_CBX_FSR(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_FSR(a,b) "SMMUX_CBX_FSR"
#define busnum_BDK_SMMUX_CBX_FSR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_FSR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_fsrrestore
 *
 * SMMU Context Translation Fault Restore Register
 * Restores the SMMU()_CB()_FSR register after reset. This register is used by both
 * stage 1 and stage 2 context banks.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_fsrrestore_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t restore               : 32; /**< [ 31:  0](WO) Writes bits in corresponding SMMU()_CB()_FSR. */
#else /* Word 0 - Little Endian */
        uint32_t restore               : 32; /**< [ 31:  0](WO) Writes bits in corresponding SMMU()_CB()_FSR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_fsrrestore_s cn; */
} bdk_smmux_cbx_fsrrestore_t;

static inline uint64_t BDK_SMMUX_CBX_FSRRESTORE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSRRESTORE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x83000100005cll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x83000100005cll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x83000100005cll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_FSRRESTORE", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_FSRRESTORE(a,b) bdk_smmux_cbx_fsrrestore_t
#define bustype_BDK_SMMUX_CBX_FSRRESTORE(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_FSRRESTORE(a,b) "SMMUX_CBX_FSRRESTORE"
#define busnum_BDK_SMMUX_CBX_FSRRESTORE(a,b) (a)
#define arguments_BDK_SMMUX_CBX_FSRRESTORE(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_fsynr0
 *
 * SMMU Context Fault Syndrome Register 0
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_fsynr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t s1cbndx               : 8;  /**< [ 23: 16](R/W/H) Stage 1 context bank index associated with the transaction that caused the fault. For
                                                                 nested translation, this field contains the stage 1 translation context bank index for
                                                                 processing the transaction. For stage 2 only translation, this field is UNKNOWN.
                                                                 This field is only present in a stage 2 format translation context bank. In a stage 1
                                                                 format translation context bank, it is UNKNOWN. */
        uint32_t reserved_12_15        : 4;
        uint32_t afr                   : 1;  /**< [ 11: 11](R/W/H) Asynchronous fault recorded.
                                                                 0 = A fault was recorded synchronously.
                                                                 1 = A fault was recorded asynchronously. */
        uint32_t ptwf                  : 1;  /**< [ 10: 10](R/W/H) A walk fault on a translation table access.
                                                                 0 = A walk fault did not occur.
                                                                 1 = A walk fault occurred during processing of a translation table walk. */
        uint32_t atof                  : 1;  /**< [  9:  9](RO) Stage 2 address translation operation fault. ATOs not supported. */
        uint32_t nsattr                : 1;  /**< [  8:  8](R/W/H) Non-secure attribute.
                                                                 0 = The input transaction after SMMU()_S2CR()[NSCFG] had secure attribute.
                                                                 1 = The input transaction after SMMU()_S2CR()[NSCFG] had non-secure attribute. */
        uint32_t nsstate               : 1;  /**< [  7:  7](RO) Stage 2 non-secure state:
                                                                 0 = The transaction is associated with a secure client.
                                                                 1 = The transaction is associated with a non-secure client. */
        uint32_t ind                   : 1;  /**< [  6:  6](R/W/H) Instruction, not data.
                                                                 0 = Data.
                                                                 1 = Instruction. */
        uint32_t pnu                   : 1;  /**< [  5:  5](R/W/H) Privileged, not unprivileged.
                                                                 0 = Unprivileged.
                                                                 1 = Privileged. */
        uint32_t wnr                   : 1;  /**< [  4:  4](R/W/H) Write, not read. */
        uint32_t s1ptwf                : 1;  /**< [  3:  3](R/W/H) Stage 2 walk fault during stage 2 translation of a stage 1 translation table walk. */
        uint32_t nested                : 1;  /**< [  2:  2](R/W/H) Indicates whether the fault is due to a nested stage 1 translation.
                                                                 0 = The fault is related to a stage 2 only translation.
                                                                 1 = The fault is related to a nested stage1 and stage 2 translation.

                                                                 When NESTED is set to zero:
                                                                 * SMMU()_CB()_FAR records the IPA that faulted at stage 2
                                                                 * SMMU()_CB()_FSYNR0[S1CBNDX] is UNKNOWN.
                                                                 * SMMU()_CB()_IPAFAR also records the IPA that faulted at stage 2

                                                                 When NESTED is set to one:
                                                                 * SMMU()_CB()_FAR records the virtual address of the requested translation.
                                                                 * SMMU()_CB()_FSYNR0[S1CBNDX] indicates the stage 1 context bank that caused the
                                                                 translation.
                                                                 * SMMU()_CB()_IPAFAR records the IPA that faulted at stage 2.
                                                                 This bit is RAZ/WI if SMMU()_IDR0[NTS] == 0. */
        uint32_t plvl                  : 2;  /**< [  1:  0](R/W/H) Translation table level for fault.
                                                                 0 = Reserved.
                                                                 1 = level 1.
                                                                 2 = level 2.
                                                                 3 = level 3. */
#else /* Word 0 - Little Endian */
        uint32_t plvl                  : 2;  /**< [  1:  0](R/W/H) Translation table level for fault.
                                                                 0 = Reserved.
                                                                 1 = level 1.
                                                                 2 = level 2.
                                                                 3 = level 3. */
        uint32_t nested                : 1;  /**< [  2:  2](R/W/H) Indicates whether the fault is due to a nested stage 1 translation.
                                                                 0 = The fault is related to a stage 2 only translation.
                                                                 1 = The fault is related to a nested stage1 and stage 2 translation.

                                                                 When NESTED is set to zero:
                                                                 * SMMU()_CB()_FAR records the IPA that faulted at stage 2
                                                                 * SMMU()_CB()_FSYNR0[S1CBNDX] is UNKNOWN.
                                                                 * SMMU()_CB()_IPAFAR also records the IPA that faulted at stage 2

                                                                 When NESTED is set to one:
                                                                 * SMMU()_CB()_FAR records the virtual address of the requested translation.
                                                                 * SMMU()_CB()_FSYNR0[S1CBNDX] indicates the stage 1 context bank that caused the
                                                                 translation.
                                                                 * SMMU()_CB()_IPAFAR records the IPA that faulted at stage 2.
                                                                 This bit is RAZ/WI if SMMU()_IDR0[NTS] == 0. */
        uint32_t s1ptwf                : 1;  /**< [  3:  3](R/W/H) Stage 2 walk fault during stage 2 translation of a stage 1 translation table walk. */
        uint32_t wnr                   : 1;  /**< [  4:  4](R/W/H) Write, not read. */
        uint32_t pnu                   : 1;  /**< [  5:  5](R/W/H) Privileged, not unprivileged.
                                                                 0 = Unprivileged.
                                                                 1 = Privileged. */
        uint32_t ind                   : 1;  /**< [  6:  6](R/W/H) Instruction, not data.
                                                                 0 = Data.
                                                                 1 = Instruction. */
        uint32_t nsstate               : 1;  /**< [  7:  7](RO) Stage 2 non-secure state:
                                                                 0 = The transaction is associated with a secure client.
                                                                 1 = The transaction is associated with a non-secure client. */
        uint32_t nsattr                : 1;  /**< [  8:  8](R/W/H) Non-secure attribute.
                                                                 0 = The input transaction after SMMU()_S2CR()[NSCFG] had secure attribute.
                                                                 1 = The input transaction after SMMU()_S2CR()[NSCFG] had non-secure attribute. */
        uint32_t atof                  : 1;  /**< [  9:  9](RO) Stage 2 address translation operation fault. ATOs not supported. */
        uint32_t ptwf                  : 1;  /**< [ 10: 10](R/W/H) A walk fault on a translation table access.
                                                                 0 = A walk fault did not occur.
                                                                 1 = A walk fault occurred during processing of a translation table walk. */
        uint32_t afr                   : 1;  /**< [ 11: 11](R/W/H) Asynchronous fault recorded.
                                                                 0 = A fault was recorded synchronously.
                                                                 1 = A fault was recorded asynchronously. */
        uint32_t reserved_12_15        : 4;
        uint32_t s1cbndx               : 8;  /**< [ 23: 16](R/W/H) Stage 1 context bank index associated with the transaction that caused the fault. For
                                                                 nested translation, this field contains the stage 1 translation context bank index for
                                                                 processing the transaction. For stage 2 only translation, this field is UNKNOWN.
                                                                 This field is only present in a stage 2 format translation context bank. In a stage 1
                                                                 format translation context bank, it is UNKNOWN. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_fsynr0_s cn; */
} bdk_smmux_cbx_fsynr0_t;

static inline uint64_t BDK_SMMUX_CBX_FSYNR0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSYNR0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000068ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000068ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000068ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_FSYNR0", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_FSYNR0(a,b) bdk_smmux_cbx_fsynr0_t
#define bustype_BDK_SMMUX_CBX_FSYNR0(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_FSYNR0(a,b) "SMMUX_CBX_FSYNR0"
#define busnum_BDK_SMMUX_CBX_FSYNR0(a,b) (a)
#define arguments_BDK_SMMUX_CBX_FSYNR0(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_fsynr1
 *
 * SMMU Context Fault Syndrome Register 1
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_fsynr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_fsynr1_s cn; */
} bdk_smmux_cbx_fsynr1_t;

static inline uint64_t BDK_SMMUX_CBX_FSYNR1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSYNR1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x83000100006cll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x83000100006cll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x83000100006cll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_FSYNR1", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_FSYNR1(a,b) bdk_smmux_cbx_fsynr1_t
#define bustype_BDK_SMMUX_CBX_FSYNR1(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_FSYNR1(a,b) "SMMUX_CBX_FSYNR1"
#define busnum_BDK_SMMUX_CBX_FSYNR1(a,b) (a)
#define arguments_BDK_SMMUX_CBX_FSYNR1(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_ipafar
 *
 * SMMU Context IPA Fault Address Register
 * IPA for a nested translation that faults in stage 2 (analogous to HPFAR in the processor).
 *
 * Unlike SMMU()_CB()_FAR this register will zero extend 32-bit writes to the upper 32-bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_ipafar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t faddr                 : 37; /**< [ 48: 12](R/W/H) Fault address, the input IOVA of the faulting access. This register might be updated as
                                                                 the result of a translation fault for an upstream client device. The least significant 12
                                                                 bits of this register are shared with SMMU()_CB()_FAR. */
        uint64_t reserved_0_11         : 12;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_11         : 12;
        uint64_t faddr                 : 37; /**< [ 48: 12](R/W/H) Fault address, the input IOVA of the faulting access. This register might be updated as
                                                                 the result of a translation fault for an upstream client device. The least significant 12
                                                                 bits of this register are shared with SMMU()_CB()_FAR. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_ipafar_s cn; */
} bdk_smmux_cbx_ipafar_t;

static inline uint64_t BDK_SMMUX_CBX_IPAFAR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_IPAFAR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000070ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000070ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000070ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_IPAFAR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_IPAFAR(a,b) bdk_smmux_cbx_ipafar_t
#define bustype_BDK_SMMUX_CBX_IPAFAR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_IPAFAR(a,b) "SMMUX_CBX_IPAFAR"
#define busnum_BDK_SMMUX_CBX_IPAFAR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_IPAFAR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_mair0
 *
 * SMMU Context Memory Attribute Indirection Register 0
 * Provides a revised version of the TEX-Remap system to redirect the selection of memory
 * attributes from the translation table entries.
 * This register is used by stage 1 context banks.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_mair0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t attr3                 : 8;  /**< [ 31: 24](R/W) Memory attributes. */
        uint32_t attr2                 : 8;  /**< [ 23: 16](R/W) Memory attributes. */
        uint32_t attr1                 : 8;  /**< [ 15:  8](R/W) Memory attributes. */
        uint32_t attr0                 : 8;  /**< [  7:  0](R/W) Memory attributes. */
#else /* Word 0 - Little Endian */
        uint32_t attr0                 : 8;  /**< [  7:  0](R/W) Memory attributes. */
        uint32_t attr1                 : 8;  /**< [ 15:  8](R/W) Memory attributes. */
        uint32_t attr2                 : 8;  /**< [ 23: 16](R/W) Memory attributes. */
        uint32_t attr3                 : 8;  /**< [ 31: 24](R/W) Memory attributes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_mair0_s cn; */
} bdk_smmux_cbx_mair0_t;

static inline uint64_t BDK_SMMUX_CBX_MAIR0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_MAIR0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000038ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000038ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000038ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_MAIR0", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_MAIR0(a,b) bdk_smmux_cbx_mair0_t
#define bustype_BDK_SMMUX_CBX_MAIR0(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_MAIR0(a,b) "SMMUX_CBX_MAIR0"
#define busnum_BDK_SMMUX_CBX_MAIR0(a,b) (a)
#define arguments_BDK_SMMUX_CBX_MAIR0(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_mair1
 *
 * SMMU Context Memory Attribute Indirection Register 1
 * Provides a revised version of the TEX-Remap system to redirect the selection of memory
 * attributes from the translation table entries.
 * This register is used by stage 1 context banks.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_mair1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t attr7                 : 8;  /**< [ 31: 24](R/W) Memory attributes. */
        uint32_t attr6                 : 8;  /**< [ 23: 16](R/W) Memory attributes. */
        uint32_t attr5                 : 8;  /**< [ 15:  8](R/W) Memory attributes. */
        uint32_t attr4                 : 8;  /**< [  7:  0](R/W) Memory attributes. */
#else /* Word 0 - Little Endian */
        uint32_t attr4                 : 8;  /**< [  7:  0](R/W) Memory attributes. */
        uint32_t attr5                 : 8;  /**< [ 15:  8](R/W) Memory attributes. */
        uint32_t attr6                 : 8;  /**< [ 23: 16](R/W) Memory attributes. */
        uint32_t attr7                 : 8;  /**< [ 31: 24](R/W) Memory attributes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_mair1_s cn; */
} bdk_smmux_cbx_mair1_t;

static inline uint64_t BDK_SMMUX_CBX_MAIR1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_MAIR1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x83000100003cll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x83000100003cll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x83000100003cll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_MAIR1", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_MAIR1(a,b) bdk_smmux_cbx_mair1_t
#define bustype_BDK_SMMUX_CBX_MAIR1(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_MAIR1(a,b) "SMMUX_CBX_MAIR1"
#define busnum_BDK_SMMUX_CBX_MAIR1(a,b) (a)
#define arguments_BDK_SMMUX_CBX_MAIR1(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_resume
 *
 * SMMU Context Resume Register 1
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_resume_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_resume_s cn; */
} bdk_smmux_cbx_resume_t;

static inline uint64_t BDK_SMMUX_CBX_RESUME(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_RESUME(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000008ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000008ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000008ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_RESUME", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_RESUME(a,b) bdk_smmux_cbx_resume_t
#define bustype_BDK_SMMUX_CBX_RESUME(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_RESUME(a,b) "SMMUX_CBX_RESUME"
#define busnum_BDK_SMMUX_CBX_RESUME(a,b) (a)
#define arguments_BDK_SMMUX_CBX_RESUME(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_sctlr
 *
 * SMMU Context System Control Register
 * Provides top-level control of the translation system for the related translation context bank.
 * This register is used by both stage 1 and stage 2 context banks.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_sctlr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t uci                   : 1;  /**< [ 30: 30](R/W) For stage 1, user cache maintenance operation enable.
                                                                 0 = User level cache maintenance operations are disabled.
                                                                 1 = User level cache maintenance operations are enabled.

                                                                 This field is ignored when SMMU()_CBA2R()[VA64] is zero.

                                                                 For stage 2, reserved. */
        uint32_t nscfg                 : 2;  /**< [ 29: 28](R/W) For stage 1, non-secure configuration. Controls the non-secure attribute for any
                                                                 transaction where the translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0. [NSCFG] only exists in a translation context bank
                                                                 reserved by secure software. In a non-secure translation context bank, this field is
                                                                 UNK/SBZP.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure.

                                                                 For stage 2, reserved. */
        uint32_t wacfg                 : 2;  /**< [ 27: 26](RO) Write-allocate configuration. Controls the allocation hint for write accesses where the
                                                                 translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 25: 24](RO) Read-allocate configuration. Controls the allocation hint for read accesses where the
                                                                 translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t shcfg                 : 2;  /**< [ 23: 22](RO) Shared configuration. Controls the sharable attribute of a transaction where the
                                                                 translation context bank is disabled.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
        uint32_t fb                    : 1;  /**< [ 21: 21](RAZ) For stage 1, force broadcast. Forces the broadcast of TLB maintenance operations. Ignored
                                                                 in CNXXXX, as NCB clients do not initiate invalidates.

                                                                 For stage 2, reserved. */
        uint32_t mtcfg                 : 1;  /**< [ 20: 20](R/W) For stage 1, memory type configuration. Applies to transactions when the translation
                                                                 context bank is disabled.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes.

                                                                 For stage 2, reserved. */
        uint32_t memattr               : 4;  /**< [ 19: 16](R/W) Memory attributes for bypass transactions if MTCFG == 1. */
        uint32_t transcfg_bsu          : 2;  /**< [ 15: 14](RO) For stage 1, transient allocate configuration. Not implemented in CNXXXX.

                                                                 For stage 2, barrier sharability upgrade. Not implemented in CNXXXX. */
        uint32_t ptw                   : 1;  /**< [ 13: 13](R/W) For stage 1, reserved.

                                                                 For stage 2, protected translation walk for stage 1 followed by stage 2 translations:
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 2 permission fault if a stage 1 translation walk is to an area of memory
                                                                 that has the device or strongly-ordered memory attribute in the stage 2 translation
                                                                 tables. */
        uint32_t asidpne               : 1;  /**< [ 12: 12](RO) For stage 1, address space identifier private namespace enable hint.
                                                                 0 = SMMU ASID values for this translation context bank are coordinated with wider
                                                                 system.
                                                                 1 = SMMU ASID values for this translation context bank are a private namespace not
                                                                 coordinated with the wider system.

                                                                 Hint ignored in CNXXXX, always system wide.

                                                                 For stage 2, reserved. */
        uint32_t reserved_11           : 1;
        uint32_t uwxn                  : 1;  /**< [ 10: 10](RO) For stage 1, unprivileged writable execute never.
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 1 permission fault if an instruction fetch occurs from a memory location
                                                                 that permits writes for unprivileged access.

                                                                 For stage 2, reserved.

                                                                 CNXXXX not implemented, no instruction stream. */
        uint32_t wxn                   : 1;  /**< [  9:  9](RO) For stage 1, writable execute never.
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 1 permission fault if an instruction fetch occurs from a memory location
                                                                 that permits writes.

                                                                 For stage 2, reserved.

                                                                 CNXXXX not implemented, no instruction stream. */
        uint32_t hupcf                 : 1;  /**< [  8:  8](RO) Hit under previous context fault.
                                                                 0 = Stall or terminate subsequent transactions in the presence of an outstanding context
                                                                 fault.
                                                                 1 = Process all subsequent transactions independently of any outstanding context fault.

                                                                 CNXXXX ignores, always processes. */
        uint32_t cfcfg                 : 1;  /**< [  7:  7](RO) Context fault configuration.
                                                                 0 = Terminate.
                                                                 1 = Stall.

                                                                 CNXXXX ignores, always terminates. */
        uint32_t cfie                  : 1;  /**< [  6:  6](R/W) Context fault interrupt enable.
                                                                 0 = Do not raise an interrupt when a context fault occurs.
                                                                 1 = Raise an interrupt when a context fault occurs. */
        uint32_t cfre                  : 1;  /**< [  5:  5](R/W) Context fault report enable.
                                                                 0 = Do not return an abort when a context fault occurs.
                                                                 1 = Return an abort when a context fault occurs. */
        uint32_t ebig                  : 1;  /**< [  4:  4](R/W) Endianness, indicates the endian format of translation tables.
                                                                 0 = Little endian.
                                                                 1 = Big endian. */
        uint32_t affd                  : 1;  /**< [  3:  3](R/W) Access flag fault disable.
                                                                 0 = Access flag faults are enabled.
                                                                 1 = Access flag faults are disabled.

                                                                 It is expected that software will issue TLB maintenance operations if this bit is
                                                                 modified. If page tables are shared with the processor, then any descriptor with AF zero
                                                                 will not be held in a processor TLB entry. However, such descriptors might be held in SMMU
                                                                 TLBs. This means that page table maintenance software that changes descriptors must be
                                                                 aware that the old descriptor might be cached in the SMMU. */
        uint32_t afe                   : 1;  /**< [  2:  2](RO) Access flag enable. In ARMv8 this bit has no effect and the SMMU behaves as if the
                                                                 bit were set. Software should treat this bit as UNK/SBOP. */
        uint32_t tre                   : 1;  /**< [  1:  1](RO) TEX remap enable. In ARMv8 this bit has no effect. */
        uint32_t m                     : 1;  /**< [  0:  0](R/W) MMU enable.
                                                                 0 = MMU behavior for this translation context bank is disabled.
                                                                 1 = MMU behavior for this translation context bank is enabled. */
#else /* Word 0 - Little Endian */
        uint32_t m                     : 1;  /**< [  0:  0](R/W) MMU enable.
                                                                 0 = MMU behavior for this translation context bank is disabled.
                                                                 1 = MMU behavior for this translation context bank is enabled. */
        uint32_t tre                   : 1;  /**< [  1:  1](RO) TEX remap enable. In ARMv8 this bit has no effect. */
        uint32_t afe                   : 1;  /**< [  2:  2](RO) Access flag enable. In ARMv8 this bit has no effect and the SMMU behaves as if the
                                                                 bit were set. Software should treat this bit as UNK/SBOP. */
        uint32_t affd                  : 1;  /**< [  3:  3](R/W) Access flag fault disable.
                                                                 0 = Access flag faults are enabled.
                                                                 1 = Access flag faults are disabled.

                                                                 It is expected that software will issue TLB maintenance operations if this bit is
                                                                 modified. If page tables are shared with the processor, then any descriptor with AF zero
                                                                 will not be held in a processor TLB entry. However, such descriptors might be held in SMMU
                                                                 TLBs. This means that page table maintenance software that changes descriptors must be
                                                                 aware that the old descriptor might be cached in the SMMU. */
        uint32_t ebig                  : 1;  /**< [  4:  4](R/W) Endianness, indicates the endian format of translation tables.
                                                                 0 = Little endian.
                                                                 1 = Big endian. */
        uint32_t cfre                  : 1;  /**< [  5:  5](R/W) Context fault report enable.
                                                                 0 = Do not return an abort when a context fault occurs.
                                                                 1 = Return an abort when a context fault occurs. */
        uint32_t cfie                  : 1;  /**< [  6:  6](R/W) Context fault interrupt enable.
                                                                 0 = Do not raise an interrupt when a context fault occurs.
                                                                 1 = Raise an interrupt when a context fault occurs. */
        uint32_t cfcfg                 : 1;  /**< [  7:  7](RO) Context fault configuration.
                                                                 0 = Terminate.
                                                                 1 = Stall.

                                                                 CNXXXX ignores, always terminates. */
        uint32_t hupcf                 : 1;  /**< [  8:  8](RO) Hit under previous context fault.
                                                                 0 = Stall or terminate subsequent transactions in the presence of an outstanding context
                                                                 fault.
                                                                 1 = Process all subsequent transactions independently of any outstanding context fault.

                                                                 CNXXXX ignores, always processes. */
        uint32_t wxn                   : 1;  /**< [  9:  9](RO) For stage 1, writable execute never.
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 1 permission fault if an instruction fetch occurs from a memory location
                                                                 that permits writes.

                                                                 For stage 2, reserved.

                                                                 CNXXXX not implemented, no instruction stream. */
        uint32_t uwxn                  : 1;  /**< [ 10: 10](RO) For stage 1, unprivileged writable execute never.
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 1 permission fault if an instruction fetch occurs from a memory location
                                                                 that permits writes for unprivileged access.

                                                                 For stage 2, reserved.

                                                                 CNXXXX not implemented, no instruction stream. */
        uint32_t reserved_11           : 1;
        uint32_t asidpne               : 1;  /**< [ 12: 12](RO) For stage 1, address space identifier private namespace enable hint.
                                                                 0 = SMMU ASID values for this translation context bank are coordinated with wider
                                                                 system.
                                                                 1 = SMMU ASID values for this translation context bank are a private namespace not
                                                                 coordinated with the wider system.

                                                                 Hint ignored in CNXXXX, always system wide.

                                                                 For stage 2, reserved. */
        uint32_t ptw                   : 1;  /**< [ 13: 13](R/W) For stage 1, reserved.

                                                                 For stage 2, protected translation walk for stage 1 followed by stage 2 translations:
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 2 permission fault if a stage 1 translation walk is to an area of memory
                                                                 that has the device or strongly-ordered memory attribute in the stage 2 translation
                                                                 tables. */
        uint32_t transcfg_bsu          : 2;  /**< [ 15: 14](RO) For stage 1, transient allocate configuration. Not implemented in CNXXXX.

                                                                 For stage 2, barrier sharability upgrade. Not implemented in CNXXXX. */
        uint32_t memattr               : 4;  /**< [ 19: 16](R/W) Memory attributes for bypass transactions if MTCFG == 1. */
        uint32_t mtcfg                 : 1;  /**< [ 20: 20](R/W) For stage 1, memory type configuration. Applies to transactions when the translation
                                                                 context bank is disabled.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes.

                                                                 For stage 2, reserved. */
        uint32_t fb                    : 1;  /**< [ 21: 21](RAZ) For stage 1, force broadcast. Forces the broadcast of TLB maintenance operations. Ignored
                                                                 in CNXXXX, as NCB clients do not initiate invalidates.

                                                                 For stage 2, reserved. */
        uint32_t shcfg                 : 2;  /**< [ 23: 22](RO) Shared configuration. Controls the sharable attribute of a transaction where the
                                                                 translation context bank is disabled.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 25: 24](RO) Read-allocate configuration. Controls the allocation hint for read accesses where the
                                                                 translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t wacfg                 : 2;  /**< [ 27: 26](RO) Write-allocate configuration. Controls the allocation hint for write accesses where the
                                                                 translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t nscfg                 : 2;  /**< [ 29: 28](R/W) For stage 1, non-secure configuration. Controls the non-secure attribute for any
                                                                 transaction where the translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0. [NSCFG] only exists in a translation context bank
                                                                 reserved by secure software. In a non-secure translation context bank, this field is
                                                                 UNK/SBZP.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure.

                                                                 For stage 2, reserved. */
        uint32_t uci                   : 1;  /**< [ 30: 30](R/W) For stage 1, user cache maintenance operation enable.
                                                                 0 = User level cache maintenance operations are disabled.
                                                                 1 = User level cache maintenance operations are enabled.

                                                                 This field is ignored when SMMU()_CBA2R()[VA64] is zero.

                                                                 For stage 2, reserved. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_sctlr_s cn; */
} bdk_smmux_cbx_sctlr_t;

static inline uint64_t BDK_SMMUX_CBX_SCTLR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_SCTLR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000000ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000000ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000000ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_SCTLR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_SCTLR(a,b) bdk_smmux_cbx_sctlr_t
#define bustype_BDK_SMMUX_CBX_SCTLR(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_SCTLR(a,b) "SMMUX_CBX_SCTLR"
#define busnum_BDK_SMMUX_CBX_SCTLR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_SCTLR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_tcr
 *
 * SMMU Context Translation Control Register
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_tcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tg1                   : 2;  /**< [ 31: 30](R/W) For stage 1, page size granule for TTBR1.
                                                                 0x0 = Reserved.
                                                                 0x1 = 16 KB page granule.
                                                                 0x2 = 4 KB page granule.
                                                                 0x3 = 64 KB page granule.

                                                                 Note the encoding is different from the [TG0] encoding.
                                                                 For stage 2, reserved. */
        uint32_t sh1                   : 2;  /**< [ 29: 28](R/W) For stage 1, sharability attributes for the memory associated with the translation table
                                                                 walks using TTBR1.

                                                                 For stage 2, reserved. */
        uint32_t orgn1                 : 2;  /**< [ 27: 26](R/W) For stage 1, outer cachability attributes for TTBR1 table walks.

                                                                 For stage 2, reserved. */
        uint32_t irgn1                 : 2;  /**< [ 25: 24](R/W) For stage 1, inner cachability attributes for TTBR1 table walks.

                                                                 For stage 2, reserved. */
        uint32_t epd1                  : 1;  /**< [ 23: 23](R/W) For stage 1, Translation walk disable for TTBR1 region. This bit controls whether a
                                                                 translation table walk is performed on a TLB miss when SMMU()_CB()_TTBR1 is
                                                                 used:
                                                                 0 = If a TLB miss occurs when TTBR1 is used a translation table walk is performed.
                                                                 1 = If a TLB miss occurs when TTBR1 is used no translation table walk is performed and a
                                                                 L1 Translation fault is returned.

                                                                 For stage 2, reserved. */
        uint32_t a1                    : 1;  /**< [ 22: 22](R/W) For stage 1, select ASID from TTBRn register.
                                                                 0 = Select ASID from SMMU()_CB()_TTBR0.
                                                                 1 = Select ASID from SMMU()_CB()_TTBR1.

                                                                 For stage 2, reserved. */
        uint32_t t1sz_pasize           : 6;  /**< [ 21: 16](R/W) For stage 1, <21:16> is size offset of the SMMU()_CB()_TCR addressed region,
                                                                 encoded as a six-bit unsigned number, giving the size of the region as 2^(64-T1SZ).

                                                                 For stage 2, <21:19> is reserved, <18:16> is PASize, the size of the physical address
                                                                 (i.e. the output address):
                                                                 0x0 = 32 bits (4 GBytes).
                                                                 0x1 = 36 bits (64 GBytes).
                                                                 0x2 = 40 bits (1 TByte).
                                                                 0x3 = 42 bits (4 TByte).
                                                                 0x4 = 44 bits (16 TByte).
                                                                 0x5 = 48 bits (256 TByte).
                                                                 0x6-0x7 = Reserved. Treat as 48 bits. */
        uint32_t tg0                   : 2;  /**< [ 15: 14](R/W) Page size granule for TTBR0.
                                                                 0x0 = 4 KB page granule.
                                                                 0x1 = 64 KB page granule.
                                                                 0x2 = 16 KB page granule.
                                                                 0x3 = Reserved.

                                                                 Note the encoding is different from the [TG1] encoding. */
        uint32_t sh0                   : 2;  /**< [ 13: 12](R/W) Sharability attributes for the memory associated with the translation table walks using TTBR0. */
        uint32_t orgn0                 : 2;  /**< [ 11: 10](RO) Outer cachability attributes for TTBR0 table walks.
                                                                 Ignored in CNXXXX. */
        uint32_t irgn0                 : 2;  /**< [  9:  8](RO) Inner cachability attributes for TTBR0 table walks.
                                                                 Ignored in CNXXXX. */
        uint32_t epd0_sl0              : 2;  /**< [  7:  6](R/W) For stage 1, <6> is reserved. <7> is EPD0, translation walk disable for TTBR0 region. This
                                                                 bit is RES0 for hypervisor and monitor contexts. This bit controls whether a translation
                                                                 table walk is performed on a TLB miss when TTBR0 is used:
                                                                 0 = If aTLB miss occurs when TTBR0 is used a translation table walk is performed.
                                                                 1 = If a TLB miss occurs when TTBR0 is used no translation table walk is performed and a
                                                                 L1 Translation fault is returned.

                                                                 For stage 2, <7:6> is SL0, starting level of the addressed regions. For 4kB page granule
                                                                 size (TG0 == 0):
                                                                 0 = Level 2.
                                                                 1 = Level 1.
                                                                 2 = Level 0.
                                                                 3 = Reserved.

                                                                 For 64kB page granule size (TG0 == 1):
                                                                 0 = Level 3.
                                                                 1 = Level 2.
                                                                 2 = Level 1.
                                                                 3 = Reserved. */
        uint32_t t0sz                  : 6;  /**< [  5:  0](R/W) Size offset of the TTBR0 addressed region, encoded as a six-bit unsigned number giving the
                                                                 size of the region as 2^(64-T0SZ). */
#else /* Word 0 - Little Endian */
        uint32_t t0sz                  : 6;  /**< [  5:  0](R/W) Size offset of the TTBR0 addressed region, encoded as a six-bit unsigned number giving the
                                                                 size of the region as 2^(64-T0SZ). */
        uint32_t epd0_sl0              : 2;  /**< [  7:  6](R/W) For stage 1, <6> is reserved. <7> is EPD0, translation walk disable for TTBR0 region. This
                                                                 bit is RES0 for hypervisor and monitor contexts. This bit controls whether a translation
                                                                 table walk is performed on a TLB miss when TTBR0 is used:
                                                                 0 = If aTLB miss occurs when TTBR0 is used a translation table walk is performed.
                                                                 1 = If a TLB miss occurs when TTBR0 is used no translation table walk is performed and a
                                                                 L1 Translation fault is returned.

                                                                 For stage 2, <7:6> is SL0, starting level of the addressed regions. For 4kB page granule
                                                                 size (TG0 == 0):
                                                                 0 = Level 2.
                                                                 1 = Level 1.
                                                                 2 = Level 0.
                                                                 3 = Reserved.

                                                                 For 64kB page granule size (TG0 == 1):
                                                                 0 = Level 3.
                                                                 1 = Level 2.
                                                                 2 = Level 1.
                                                                 3 = Reserved. */
        uint32_t irgn0                 : 2;  /**< [  9:  8](RO) Inner cachability attributes for TTBR0 table walks.
                                                                 Ignored in CNXXXX. */
        uint32_t orgn0                 : 2;  /**< [ 11: 10](RO) Outer cachability attributes for TTBR0 table walks.
                                                                 Ignored in CNXXXX. */
        uint32_t sh0                   : 2;  /**< [ 13: 12](R/W) Sharability attributes for the memory associated with the translation table walks using TTBR0. */
        uint32_t tg0                   : 2;  /**< [ 15: 14](R/W) Page size granule for TTBR0.
                                                                 0x0 = 4 KB page granule.
                                                                 0x1 = 64 KB page granule.
                                                                 0x2 = 16 KB page granule.
                                                                 0x3 = Reserved.

                                                                 Note the encoding is different from the [TG1] encoding. */
        uint32_t t1sz_pasize           : 6;  /**< [ 21: 16](R/W) For stage 1, <21:16> is size offset of the SMMU()_CB()_TCR addressed region,
                                                                 encoded as a six-bit unsigned number, giving the size of the region as 2^(64-T1SZ).

                                                                 For stage 2, <21:19> is reserved, <18:16> is PASize, the size of the physical address
                                                                 (i.e. the output address):
                                                                 0x0 = 32 bits (4 GBytes).
                                                                 0x1 = 36 bits (64 GBytes).
                                                                 0x2 = 40 bits (1 TByte).
                                                                 0x3 = 42 bits (4 TByte).
                                                                 0x4 = 44 bits (16 TByte).
                                                                 0x5 = 48 bits (256 TByte).
                                                                 0x6-0x7 = Reserved. Treat as 48 bits. */
        uint32_t a1                    : 1;  /**< [ 22: 22](R/W) For stage 1, select ASID from TTBRn register.
                                                                 0 = Select ASID from SMMU()_CB()_TTBR0.
                                                                 1 = Select ASID from SMMU()_CB()_TTBR1.

                                                                 For stage 2, reserved. */
        uint32_t epd1                  : 1;  /**< [ 23: 23](R/W) For stage 1, Translation walk disable for TTBR1 region. This bit controls whether a
                                                                 translation table walk is performed on a TLB miss when SMMU()_CB()_TTBR1 is
                                                                 used:
                                                                 0 = If a TLB miss occurs when TTBR1 is used a translation table walk is performed.
                                                                 1 = If a TLB miss occurs when TTBR1 is used no translation table walk is performed and a
                                                                 L1 Translation fault is returned.

                                                                 For stage 2, reserved. */
        uint32_t irgn1                 : 2;  /**< [ 25: 24](R/W) For stage 1, inner cachability attributes for TTBR1 table walks.

                                                                 For stage 2, reserved. */
        uint32_t orgn1                 : 2;  /**< [ 27: 26](R/W) For stage 1, outer cachability attributes for TTBR1 table walks.

                                                                 For stage 2, reserved. */
        uint32_t sh1                   : 2;  /**< [ 29: 28](R/W) For stage 1, sharability attributes for the memory associated with the translation table
                                                                 walks using TTBR1.

                                                                 For stage 2, reserved. */
        uint32_t tg1                   : 2;  /**< [ 31: 30](R/W) For stage 1, page size granule for TTBR1.
                                                                 0x0 = Reserved.
                                                                 0x1 = 16 KB page granule.
                                                                 0x2 = 4 KB page granule.
                                                                 0x3 = 64 KB page granule.

                                                                 Note the encoding is different from the [TG0] encoding.
                                                                 For stage 2, reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tcr_s cn; */
} bdk_smmux_cbx_tcr_t;

static inline uint64_t BDK_SMMUX_CBX_TCR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TCR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000030ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000030ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000030ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TCR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TCR(a,b) bdk_smmux_cbx_tcr_t
#define bustype_BDK_SMMUX_CBX_TCR(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_TCR(a,b) "SMMUX_CBX_TCR"
#define busnum_BDK_SMMUX_CBX_TCR(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TCR(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_tcr2
 *
 * SMMU Context Translation Control 2 Register
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_tcr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t nscfg1                : 1;  /**< [ 30: 30](R/W) Non-secure attribute for the memory associated with translation table walks using
                                                                 SMMU()_CB()_TTBR1. This field only applies for secure owned context banks,
                                                                 otherwise this field is ignored. */
        uint32_t reserved_18_29        : 12;
        uint32_t sep                   : 3;  /**< [ 17: 15](R/W) Sign extension position. The bit position from which to sign-extend the stage 1 input
                                                                 address when required.
                                                                 0x0 = Bit [31].
                                                                 0x1 = Bit [35].
                                                                 0x2 = Bit [39].
                                                                 0x3 = Bit [41].
                                                                 0x4 = Bit [43].
                                                                 0x5 = Bit [47].
                                                                 0x6 = Reserved. This must be treated as 0x7.
                                                                 0x7 = Explicit sign bit provided by device (as bit [48]). If bit[48] is not provided it is
                                                                 treated as zero.

                                                                 If SEP specifies a bit above that implemented on the upstream input address bus, addresses
                                                                 will be zero-extended. Sign-extension does not apply to address translation operations.
                                                                 For hypervisor and monitor contexts this field is ignored.

                                                                 If the value of SEP is changed, then software must invalidate any affected TLB entries. */
        uint32_t nscfg0                : 1;  /**< [ 14: 14](R/W) Non-secure attribute for the memory associated with translation table walks using
                                                                 SMMU()_CB()_TTBR0. This field only applies for secure owned context banks,
                                                                 otherwise this field is ignored. */
        uint32_t reserved_12_13        : 2;
        uint32_t hd                    : 1;  /**< [ 11: 11](RO) Hardware management of dirty bit.
                                                                 In CNXXXX, not implemented. */
        uint32_t ha                    : 1;  /**< [ 10: 10](RO) Hardware management of access flag.
                                                                 In CNXXXX, not implemented. */
        uint32_t had1                  : 1;  /**< [  9:  9](R/W) Hierarchical attribute disable 1 for the TTBR1 region. Similar to [HAD0]. */
        uint32_t had0                  : 1;  /**< [  8:  8](R/W) For stage 1, hierarchical attribute disable 0 for the TTBR0 region.
                                                                 This field is ignored as not supported when SMMU()_IDR2[HADS] is zero.
                                                                 This field is ignored when SMMU()_CBA2R()[VA64] is zero.
                                                                 0 = Hierarchical attributes are enabled.
                                                                 1 = Hierarchical attributes are disabled.

                                                                 For stage 2, reserved. */
        uint32_t reserved_7            : 1;
        uint32_t tbi1                  : 1;  /**< [  6:  6](R/W) Top byte ignored. Indicates whether the top byte of the input address should be used for
                                                                 address match for the TTBR1 region. */
        uint32_t tbi0                  : 1;  /**< [  5:  5](R/W) Top byte ignored. Indicates whether the top byte of the input address should be used for
                                                                 address match for the TTBR0 region. */
        uint32_t as                    : 1;  /**< [  4:  4](R/W) ASID Size.
                                                                 0 = 8 bit. Note: 8 bit ASIDs are zero extended to 16 bits for all TLB matching purposes.
                                                                 1 = 16 bit. */
        uint32_t reserved_3            : 1;
        uint32_t pasize                : 3;  /**< [  2:  0](R/W) The size of the physical address:
                                                                 0x0 = 32 bits (4 GBytes).
                                                                 0x1 = 36 bits (64 GBytes).
                                                                 0x2 = 40 bits (1 TByte).
                                                                 0x3 = 42 bits (4 TByte).
                                                                 0x4 = 44 bits (16 TByte).
                                                                 0x5 = 48 bits (256 TByte).
                                                                 0x6-0x7. Reserved. Treat as 48 bits. */
#else /* Word 0 - Little Endian */
        uint32_t pasize                : 3;  /**< [  2:  0](R/W) The size of the physical address:
                                                                 0x0 = 32 bits (4 GBytes).
                                                                 0x1 = 36 bits (64 GBytes).
                                                                 0x2 = 40 bits (1 TByte).
                                                                 0x3 = 42 bits (4 TByte).
                                                                 0x4 = 44 bits (16 TByte).
                                                                 0x5 = 48 bits (256 TByte).
                                                                 0x6-0x7. Reserved. Treat as 48 bits. */
        uint32_t reserved_3            : 1;
        uint32_t as                    : 1;  /**< [  4:  4](R/W) ASID Size.
                                                                 0 = 8 bit. Note: 8 bit ASIDs are zero extended to 16 bits for all TLB matching purposes.
                                                                 1 = 16 bit. */
        uint32_t tbi0                  : 1;  /**< [  5:  5](R/W) Top byte ignored. Indicates whether the top byte of the input address should be used for
                                                                 address match for the TTBR0 region. */
        uint32_t tbi1                  : 1;  /**< [  6:  6](R/W) Top byte ignored. Indicates whether the top byte of the input address should be used for
                                                                 address match for the TTBR1 region. */
        uint32_t reserved_7            : 1;
        uint32_t had0                  : 1;  /**< [  8:  8](R/W) For stage 1, hierarchical attribute disable 0 for the TTBR0 region.
                                                                 This field is ignored as not supported when SMMU()_IDR2[HADS] is zero.
                                                                 This field is ignored when SMMU()_CBA2R()[VA64] is zero.
                                                                 0 = Hierarchical attributes are enabled.
                                                                 1 = Hierarchical attributes are disabled.

                                                                 For stage 2, reserved. */
        uint32_t had1                  : 1;  /**< [  9:  9](R/W) Hierarchical attribute disable 1 for the TTBR1 region. Similar to [HAD0]. */
        uint32_t ha                    : 1;  /**< [ 10: 10](RO) Hardware management of access flag.
                                                                 In CNXXXX, not implemented. */
        uint32_t hd                    : 1;  /**< [ 11: 11](RO) Hardware management of dirty bit.
                                                                 In CNXXXX, not implemented. */
        uint32_t reserved_12_13        : 2;
        uint32_t nscfg0                : 1;  /**< [ 14: 14](R/W) Non-secure attribute for the memory associated with translation table walks using
                                                                 SMMU()_CB()_TTBR0. This field only applies for secure owned context banks,
                                                                 otherwise this field is ignored. */
        uint32_t sep                   : 3;  /**< [ 17: 15](R/W) Sign extension position. The bit position from which to sign-extend the stage 1 input
                                                                 address when required.
                                                                 0x0 = Bit [31].
                                                                 0x1 = Bit [35].
                                                                 0x2 = Bit [39].
                                                                 0x3 = Bit [41].
                                                                 0x4 = Bit [43].
                                                                 0x5 = Bit [47].
                                                                 0x6 = Reserved. This must be treated as 0x7.
                                                                 0x7 = Explicit sign bit provided by device (as bit [48]). If bit[48] is not provided it is
                                                                 treated as zero.

                                                                 If SEP specifies a bit above that implemented on the upstream input address bus, addresses
                                                                 will be zero-extended. Sign-extension does not apply to address translation operations.
                                                                 For hypervisor and monitor contexts this field is ignored.

                                                                 If the value of SEP is changed, then software must invalidate any affected TLB entries. */
        uint32_t reserved_18_29        : 12;
        uint32_t nscfg1                : 1;  /**< [ 30: 30](R/W) Non-secure attribute for the memory associated with translation table walks using
                                                                 SMMU()_CB()_TTBR1. This field only applies for secure owned context banks,
                                                                 otherwise this field is ignored. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tcr2_s cn; */
} bdk_smmux_cbx_tcr2_t;

static inline uint64_t BDK_SMMUX_CBX_TCR2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TCR2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000010ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000010ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000010ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TCR2", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TCR2(a,b) bdk_smmux_cbx_tcr2_t
#define bustype_BDK_SMMUX_CBX_TCR2(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_TCR2(a,b) "SMMUX_CBX_TCR2"
#define busnum_BDK_SMMUX_CBX_TCR2(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TCR2(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_tlbiall
 *
 * SMMU Context Invalidate Entire TLB Register
 * Invalidates all of the TLB entries, and only has to apply to TLB entries associated with the
 * VMID used for the stage 1 translation context bank. If SMMU()_CBAR()[HYPC] has the
 * value 1, this operation only has to apply to TLB entries associated with hypervisor contexts.
 * if SMMU()_CBAR()[MONC] has the value 1, this operation only has to apply to TLB
 * entries associated with monitor contexts. The VMID is therefore irrelevant to the operation.
 * This operation only has to apply to TLB entries associated with the security domain that the
 * Stage 1 translation context bank is a member of.
 * Register fields are identical to those in SMMU()_TLBIALLH.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_tlbiall_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbiall_s cn; */
} bdk_smmux_cbx_tlbiall_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIALL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIALL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000618ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000618ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000618ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIALL", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIALL(a,b) bdk_smmux_cbx_tlbiall_t
#define bustype_BDK_SMMUX_CBX_TLBIALL(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_TLBIALL(a,b) "SMMUX_CBX_TLBIALL"
#define busnum_BDK_SMMUX_CBX_TLBIALL(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIALL(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_tlbiasid
 *
 * SMMU Context Invalid TLB by ASID Register
 * Invalidates all of the TLB entries that match the ASID provided as an argument. This operation
 * only has to apply to non-global TLB entries that match the VMID used for the stage 1
 * translation context bank. For MONC and HYPC contexts, this operation has no effect and
 * is ignored.
 * This operation only has to apply to TLB entries associated with the security domain that the
 * Stage 1 translation context bank is a member of.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_tlbiasid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t asid                  : 16; /**< [ 15:  0](WO) ASID to invalidate. */
#else /* Word 0 - Little Endian */
        uint32_t asid                  : 16; /**< [ 15:  0](WO) ASID to invalidate. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbiasid_s cn; */
} bdk_smmux_cbx_tlbiasid_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIASID(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIASID(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000610ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000610ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000610ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIASID", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIASID(a,b) bdk_smmux_cbx_tlbiasid_t
#define bustype_BDK_SMMUX_CBX_TLBIASID(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_TLBIASID(a,b) "SMMUX_CBX_TLBIASID"
#define busnum_BDK_SMMUX_CBX_TLBIASID(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIASID(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_tlbiipas2
 *
 * SMMU Context Invalidate TLB by IPA Register
 * Invalidates all TLB entries that  match the specified IPA. this operation does not need to
 * apply to caching structures that combines both stage 1 and stage 2 translation table entries,
 * but must apply to caching structures that contain information only from stage 2 translation
 * table entries. For those implementations that choose to store the IPA in a combined stage 1
 * and stage 2 TLB entry, this operation is only required to match those entries that have the
 * same VMID as specified by the stage 2 bank.
 * An incoming transaction directed at an S2 context might result in S2-only TLB entries which
 * will be affected by this operation.
 * However, an incoming transaction directed to a S1 + S2 nested context might result in S1+S2
 * TLB entries. Such entries might not be affected by this operation. Thus in order to change a
 * Stage 2 page table entry then software must invalidate all stage 1 contexts (using an
 * SMMU()_TLBIVMIDS1 operation).
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_tlbiipas2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t address               : 36; /**< [ 35:  0](WO) IPA<47:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 ARMv8 processor TLB invalidation instructions. If the page size for stage 2 is 64kB then
                                                                 bits corresponding to address<15:12> are ignored. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 36; /**< [ 35:  0](WO) IPA<47:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 ARMv8 processor TLB invalidation instructions. If the page size for stage 2 is 64kB then
                                                                 bits corresponding to address<15:12> are ignored. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbiipas2_s cn; */
} bdk_smmux_cbx_tlbiipas2_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000630ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000630ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000630ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIIPAS2", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIIPAS2(a,b) bdk_smmux_cbx_tlbiipas2_t
#define bustype_BDK_SMMUX_CBX_TLBIIPAS2(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TLBIIPAS2(a,b) "SMMUX_CBX_TLBIIPAS2"
#define busnum_BDK_SMMUX_CBX_TLBIIPAS2(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIIPAS2(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_tlbiipas2l
 *
 * SMMU Invalidate TLB by IPA Last Level Register
 * Operates exactly as SMMU()_CB()_TLBIIPAS2, but only invalidating those that
 * correspond to the last level of the translation table walk.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_tlbiipas2l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t address               : 36; /**< [ 35:  0](WO) IPA<47:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 ARMv8 processor TLB invalidation instructions. If the page size for stage 2 is 64kB then
                                                                 bits corresponding to address<15:12> are ignored. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 36; /**< [ 35:  0](WO) IPA<47:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 ARMv8 processor TLB invalidation instructions. If the page size for stage 2 is 64kB then
                                                                 bits corresponding to address<15:12> are ignored. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbiipas2l_s cn; */
} bdk_smmux_cbx_tlbiipas2l_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2L(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2L(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000638ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000638ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000638ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIIPAS2L", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIIPAS2L(a,b) bdk_smmux_cbx_tlbiipas2l_t
#define bustype_BDK_SMMUX_CBX_TLBIIPAS2L(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TLBIIPAS2L(a,b) "SMMUX_CBX_TLBIIPAS2L"
#define busnum_BDK_SMMUX_CBX_TLBIIPAS2L(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIIPAS2L(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_tlbiva
 *
 * SMMU Context Invalidate TLB by VA Register
 * Invalidates all of the TLB entries that match the VA and ASID provided as arguments. This
 * operation only applies to TLB entries associated with the VMID used for a stage 1 translation
 * context bank. The ASID is not checked for global entries in the TLB. If
 * SMMU()_CBAR()[HYPC] is set, this operation only applies to TLB entries associated
 * with hypervisor contexts. The VMID and ASID are therefore irrelevant to the operation. This
 * operation only applies to TLB entries associated with the security domain that the stage 1
 * translation context bank is a member of.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_tlbiva_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t asid                  : 16; /**< [ 63: 48](WO) ASID for which the TLB invalidation should be performed. */
        uint64_t reserved_44_47        : 4;
        uint64_t address               : 44; /**< [ 43:  0](WO) Address<55:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 the ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then the bits
                                                                 corresponding to address<15:12> are ignored. The address will be extended to bit <63> by
                                                                 copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](WO) Address<55:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 the ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then the bits
                                                                 corresponding to address<15:12> are ignored. The address will be extended to bit <63> by
                                                                 copying bit <55>. */
        uint64_t reserved_44_47        : 4;
        uint64_t asid                  : 16; /**< [ 63: 48](WO) ASID for which the TLB invalidation should be performed. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbiva_s cn; */
} bdk_smmux_cbx_tlbiva_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVA(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000600ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000600ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000600ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIVA", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIVA(a,b) bdk_smmux_cbx_tlbiva_t
#define bustype_BDK_SMMUX_CBX_TLBIVA(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TLBIVA(a,b) "SMMUX_CBX_TLBIVA"
#define busnum_BDK_SMMUX_CBX_TLBIVA(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIVA(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_tlbivaa
 *
 * SMMU Context Invalidate TLB by VA All ASID Register
 * Invalidates all of the TLB entries that match the VA provided as an argument, regardless of
 * the ASID. This operation only has to apply to TLB entries associated with the VMID used for a
 * Stage 1 translation context bank. If SMMU()_CBAR()[HYPC] is set, this operation is
 * unpredictable. This operation only has to apply to TLB entries associated with the security
 * domain that the stage 1 translation context bank is a member of.
 * Register fields are identical to those in SMMU()_TLBIVAH64.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_tlbivaa_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbivaa_s cn; */
} bdk_smmux_cbx_tlbivaa_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVAA(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVAA(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000608ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000608ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000608ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIVAA", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIVAA(a,b) bdk_smmux_cbx_tlbivaa_t
#define bustype_BDK_SMMUX_CBX_TLBIVAA(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TLBIVAA(a,b) "SMMUX_CBX_TLBIVAA"
#define busnum_BDK_SMMUX_CBX_TLBIVAA(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIVAA(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_tlbivaal
 *
 * SMMU Context Invalidate TLB by VA all ASID Last Level Register
 * Operates exactly as SMMU()_CB()_TLBIVAA, but only invalidating those that correspond
 * to the last level of the translation table walk.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_tlbivaal_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbivaal_s cn; */
} bdk_smmux_cbx_tlbivaal_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVAAL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVAAL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000628ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000628ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000628ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIVAAL", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIVAAL(a,b) bdk_smmux_cbx_tlbivaal_t
#define bustype_BDK_SMMUX_CBX_TLBIVAAL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TLBIVAAL(a,b) "SMMUX_CBX_TLBIVAAL"
#define busnum_BDK_SMMUX_CBX_TLBIVAAL(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIVAAL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_tlbival
 *
 * SMMU Context Invalidate TLB by VA Last Level Register
 * Operates exactly as SMMU()_CB()_TLBIVA, but only invalidating those that correspond
 * to the last level of the translation table walk.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_tlbival_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t asid                  : 16; /**< [ 63: 48](WO) ASID for which the TLB invalidation should be performed. */
        uint64_t reserved_44_47        : 4;
        uint64_t address               : 44; /**< [ 43:  0](WO) Address<55:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 the ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then the bits
                                                                 corresponding to address<15:12> are ignored. The address will be extended to bit <63> by
                                                                 copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](WO) Address<55:12> to be invalidated. Note this matches the format of the address supplied to
                                                                 the ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then the bits
                                                                 corresponding to address<15:12> are ignored. The address will be extended to bit <63> by
                                                                 copying bit <55>. */
        uint64_t reserved_44_47        : 4;
        uint64_t asid                  : 16; /**< [ 63: 48](WO) ASID for which the TLB invalidation should be performed. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbival_s cn; */
} bdk_smmux_cbx_tlbival_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVAL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVAL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000620ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000620ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000620ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBIVAL", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBIVAL(a,b) bdk_smmux_cbx_tlbival_t
#define bustype_BDK_SMMUX_CBX_TLBIVAL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TLBIVAL(a,b) "SMMUX_CBX_TLBIVAL"
#define busnum_BDK_SMMUX_CBX_TLBIVAL(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBIVAL(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_tlbstatus
 *
 * SMMU Context TLB Synchronize Status Register
 * Gives the status of a TLB maintenance operation. Register fields are identical to those in
 * SMMU()_(S)TLBGSTATUS.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_tlbstatus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t gsactive              : 1;  /**< [  0:  0](RO/H) Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
#else /* Word 0 - Little Endian */
        uint32_t gsactive              : 1;  /**< [  0:  0](RO/H) Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbstatus_s cn; */
} bdk_smmux_cbx_tlbstatus_t;

static inline uint64_t BDK_SMMUX_CBX_TLBSTATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBSTATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x8300010007f4ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x8300010007f4ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x8300010007f4ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBSTATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBSTATUS(a,b) bdk_smmux_cbx_tlbstatus_t
#define bustype_BDK_SMMUX_CBX_TLBSTATUS(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_TLBSTATUS(a,b) "SMMUX_CBX_TLBSTATUS"
#define busnum_BDK_SMMUX_CBX_TLBSTATUS(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBSTATUS(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cb#_tlbsync
 *
 * SMMU Context TLB Synchronize Invalidate Register
 * Starts a context synchronization operation that ensures the completion of any previously
 * accepted TLB Invalidate operation. Register fields are identical to those in
 * SMMU()_(S)TLBGSYNC.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbx_tlbsync_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_tlbsync_s cn; */
} bdk_smmux_cbx_tlbsync_t;

static inline uint64_t BDK_SMMUX_CBX_TLBSYNC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBSYNC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x8300010007f0ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x8300010007f0ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x8300010007f0ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TLBSYNC", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TLBSYNC(a,b) bdk_smmux_cbx_tlbsync_t
#define bustype_BDK_SMMUX_CBX_TLBSYNC(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBX_TLBSYNC(a,b) "SMMUX_CBX_TLBSYNC"
#define busnum_BDK_SMMUX_CBX_TLBSYNC(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TLBSYNC(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_ttbr0
 *
 * SMMU Context Translation Table Base Register 0
 * Holds the base address of translation tables. This register is used by both stage 1 and stage
 * 2 context banks.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_ttbr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t asid                  : 16; /**< [ 63: 48](R/W) Address space ID associated with this base address. The selection between
                                                                 SMMU()_CB()_TTBR0[ASID] and SMMU()_CB()_TTBR1[ASID] is determined by
                                                                 SMMU()_CB()_TCR[A1]. Bits [15:8] are only valid if
                                                                 SMMU()_CB()_TCR2[AS] ==1 and RES0 otherwise. */
        uint64_t addr                  : 44; /**< [ 47:  4](R/W) Translation table base address. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 44; /**< [ 47:  4](R/W) Translation table base address. */
        uint64_t asid                  : 16; /**< [ 63: 48](R/W) Address space ID associated with this base address. The selection between
                                                                 SMMU()_CB()_TTBR0[ASID] and SMMU()_CB()_TTBR1[ASID] is determined by
                                                                 SMMU()_CB()_TCR[A1]. Bits [15:8] are only valid if
                                                                 SMMU()_CB()_TCR2[AS] ==1 and RES0 otherwise. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_ttbr0_s cn; */
} bdk_smmux_cbx_ttbr0_t;

static inline uint64_t BDK_SMMUX_CBX_TTBR0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TTBR0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000020ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000020ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000020ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TTBR0", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TTBR0(a,b) bdk_smmux_cbx_ttbr0_t
#define bustype_BDK_SMMUX_CBX_TTBR0(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TTBR0(a,b) "SMMUX_CBX_TTBR0"
#define busnum_BDK_SMMUX_CBX_TTBR0(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TTBR0(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_cb#_ttbr1
 *
 * SMMU Context Translation Table Base Register 1
 * Holds the base address of translation tables. This register is used by stage 1 context banks.
 * Register fields are identical to those in SMMU()_CB()_TTBR0.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_cbx_ttbr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t asid                  : 16; /**< [ 63: 48](R/W) Address space ID associated with this base address. The selection between
                                                                 SMMU()_CB()_TTBR0[ASID] and SMMU()_CB()_TTBR1[ASID] is determined by
                                                                 SMMU()_CB()_TCR[A1]. Bits [15:8] are only valid if
                                                                 SMMU()_CB()_TCR2[AS] ==1 and RES0 otherwise. */
        uint64_t addr                  : 44; /**< [ 47:  4](R/W) Translation table base address. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t addr                  : 44; /**< [ 47:  4](R/W) Translation table base address. */
        uint64_t asid                  : 16; /**< [ 63: 48](R/W) Address space ID associated with this base address. The selection between
                                                                 SMMU()_CB()_TTBR0[ASID] and SMMU()_CB()_TTBR1[ASID] is determined by
                                                                 SMMU()_CB()_TCR[A1]. Bits [15:8] are only valid if
                                                                 SMMU()_CB()_TCR2[AS] ==1 and RES0 otherwise. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbx_ttbr1_s cn; */
} bdk_smmux_cbx_ttbr1_t;

static inline uint64_t BDK_SMMUX_CBX_TTBR1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TTBR1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830001000028ll + 0x1000000000ll * ((a) & 0x0) + 0x10000ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830001000028ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830001000028ll + 0x1000000000ll * ((a) & 0x3) + 0x10000ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBX_TTBR1", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBX_TTBR1(a,b) bdk_smmux_cbx_ttbr1_t
#define bustype_BDK_SMMUX_CBX_TTBR1(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_CBX_TTBR1(a,b) "SMMUX_CBX_TTBR1"
#define busnum_BDK_SMMUX_CBX_TTBR1(a,b) (a)
#define arguments_BDK_SMMUX_CBX_TTBR1(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cba2r#
 *
 * SMMU Context Bank Attribute 2 Register
 * Extended attributes for context bank n.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cba2rx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vmid16                : 16; /**< [ 31: 16](R/W/H) Virtual machine identifier.

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is clear, or when
                                                                 SMMU()_IDR2[VMID16S] is clear.

                                                                 INTERNAL: In 88xx pass 1, writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
        uint32_t reserved_2_15         : 14;
        uint32_t monc                  : 1;  /**< [  1:  1](R/W) Designates a secure monitor context bank (EL3):
                                                                   0 = Non-monitor context. Use VMID or ASID for TLB tagging.
                                                                   1 = Monitor context. Do not use VMID or ASID for TLB tagging.

                                                                 Ignored if the bank is non-secure, or SMMU()_CBAR()[CTYPE] != 0x1. */
        uint32_t va64                  : 1;  /**< [  0:  0](RO) Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
#else /* Word 0 - Little Endian */
        uint32_t va64                  : 1;  /**< [  0:  0](RO) Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
        uint32_t monc                  : 1;  /**< [  1:  1](R/W) Designates a secure monitor context bank (EL3):
                                                                   0 = Non-monitor context. Use VMID or ASID for TLB tagging.
                                                                   1 = Monitor context. Do not use VMID or ASID for TLB tagging.

                                                                 Ignored if the bank is non-secure, or SMMU()_CBAR()[CTYPE] != 0x1. */
        uint32_t reserved_2_15         : 14;
        uint32_t vmid16                : 16; /**< [ 31: 16](R/W/H) Virtual machine identifier.

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is clear, or when
                                                                 SMMU()_IDR2[VMID16S] is clear.

                                                                 INTERNAL: In 88xx pass 1, writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
#endif /* Word 0 - End */
    } s;
    struct bdk_smmux_cba2rx_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vmid16                : 16; /**< [ 31: 16](R/W/H) Virtual machine identifier.

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is clear, or when
                                                                 SMMU()_IDR2[VMID16S] is clear.

                                                                 INTERNAL: In 88xx pass 1, writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
        uint32_t reserved_3_15         : 13;
        uint32_t e2hc                  : 1;  /**< [  2:  2](R/W) Reserved. */
        uint32_t monc                  : 1;  /**< [  1:  1](R/W) Designates a secure monitor context bank (EL3):
                                                                   0 = Non-monitor context. Use VMID or ASID for TLB tagging.
                                                                   1 = Monitor context. Do not use VMID or ASID for TLB tagging.

                                                                 Ignored if the bank is non-secure, or SMMU()_CBAR()[CTYPE] != 0x1. */
        uint32_t va64                  : 1;  /**< [  0:  0](RO) Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
#else /* Word 0 - Little Endian */
        uint32_t va64                  : 1;  /**< [  0:  0](RO) Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
        uint32_t monc                  : 1;  /**< [  1:  1](R/W) Designates a secure monitor context bank (EL3):
                                                                   0 = Non-monitor context. Use VMID or ASID for TLB tagging.
                                                                   1 = Monitor context. Do not use VMID or ASID for TLB tagging.

                                                                 Ignored if the bank is non-secure, or SMMU()_CBAR()[CTYPE] != 0x1. */
        uint32_t e2hc                  : 1;  /**< [  2:  2](R/W) Reserved. */
        uint32_t reserved_3_15         : 13;
        uint32_t vmid16                : 16; /**< [ 31: 16](R/W/H) Virtual machine identifier.

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is clear, or when
                                                                 SMMU()_IDR2[VMID16S] is clear.

                                                                 INTERNAL: In 88xx pass 1, writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_smmux_cba2rx_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vmid16                : 16; /**< [ 31: 16](R/W/H) Virtual machine identifier.

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is clear, or when
                                                                 SMMU()_IDR2[VMID16S] is clear.

                                                                 INTERNAL: In 88xx pass 1, writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
        uint32_t reserved_3_15         : 13;
        uint32_t reserved_2            : 1;
        uint32_t monc                  : 1;  /**< [  1:  1](R/W) Designates a secure monitor context bank (EL3):
                                                                   0 = Non-monitor context. Use VMID or ASID for TLB tagging.
                                                                   1 = Monitor context. Do not use VMID or ASID for TLB tagging.

                                                                 Ignored if the bank is non-secure, or SMMU()_CBAR()[CTYPE] != 0x1. */
        uint32_t va64                  : 1;  /**< [  0:  0](RO) Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
#else /* Word 0 - Little Endian */
        uint32_t va64                  : 1;  /**< [  0:  0](RO) Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
        uint32_t monc                  : 1;  /**< [  1:  1](R/W) Designates a secure monitor context bank (EL3):
                                                                   0 = Non-monitor context. Use VMID or ASID for TLB tagging.
                                                                   1 = Monitor context. Do not use VMID or ASID for TLB tagging.

                                                                 Ignored if the bank is non-secure, or SMMU()_CBAR()[CTYPE] != 0x1. */
        uint32_t reserved_2            : 1;
        uint32_t reserved_3_15         : 13;
        uint32_t vmid16                : 16; /**< [ 31: 16](R/W/H) Virtual machine identifier.

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is clear, or when
                                                                 SMMU()_IDR2[VMID16S] is clear.

                                                                 INTERNAL: In 88xx pass 1, writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_cba2rx_cn81xx cn83xx; */
    /* struct bdk_smmux_cba2rx_cn81xx cn88xxp2; */
} bdk_smmux_cba2rx_t;

static inline uint64_t BDK_SMMUX_CBA2RX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBA2RX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830000010800ll + 0x1000000000ll * ((a) & 0x0) + 4ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830000010800ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830000010800ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBA2RX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBA2RX(a,b) bdk_smmux_cba2rx_t
#define bustype_BDK_SMMUX_CBA2RX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBA2RX(a,b) "SMMUX_CBA2RX"
#define busnum_BDK_SMMUX_CBA2RX(a,b) (a)
#define arguments_BDK_SMMUX_CBA2RX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cbar#
 *
 * SMMU Context Bank Attribute Register
 * Specifies configuration attributes for translation context bank n. This field has different
 * layouts based on the CTYPE field value.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbarx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t wacfg                 : 2;  /**< [ 23: 22](RO) If CTYPE=1 or 3, write allocate configuration hint.

                                                                 If CTYPE=0/2, reserved.

                                                                 CNXXXX ignores the hint. INTERNAL: Requested filed with ARM to make RO. */
        uint32_t racfg                 : 2;  /**< [ 21: 20](RO) If CTYPE=1 or 3, read allocate configuration hint.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 CNXXXX ignores the hint. INTERNAL: Requested filed with ARM to make RO. */
        uint32_t bsu                   : 2;  /**< [ 19: 18](RO) Barrier sharability upgrade. Not implemented in CNXXXX. */
        uint32_t ctype                 : 2;  /**< [ 17: 16](R/W) Register type.   Indicates the context format. Enumerated by SMMU_CTYPE_E. */
        uint32_t memattr_cbndx4        : 4;  /**< [ 15: 12](R/W) Memory attributes, or context bank index <7:4>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, combined with the shared attributes of the previous translation stage.

                                                                 If CTYPE=3, context bank index <7:4>, see [BPSHCFG_CNBDX0]. */
        uint32_t fb_cbndx3             : 1;  /**< [ 11: 11](R/W) Force broadcast of TLB and cache maintenance operations or context bank index<3>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, force broadcast mode. Ignored in CNXXXX, as NCB clients do not initiate
                                                                 invalidates.

                                                                 If CTYPE=3, context bank index <3>, see [BPSHCFG_CNBDX0]. */
        uint32_t hypc_cbndx2           : 1;  /**< [ 10: 10](R/W) Hypervisor context or E2HC context or context bank index <2>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, and SMMU()_(S)CR0[HYPMODE]=0, hypervisor context.
                                                                 0 = Non-hypervisor context. Use VMID and ASID for TLB tagging.
                                                                 1 = Hypervisor context. Do not use VMID and ASID for TLB tagging.

                                                                 If CTYPE=1, and SMMU()_(S)CR0[HYPMODE]=1, E2HC context.  In CNXXXX, E2HC or
                                                                 non-E2HC must be set identically across all SMMUs.
                                                                 0 = Non-E2HC context.
                                                                 1 = E2HC context.

                                                                 In an interaction with the security extensions, the following restrictions apply to secure
                                                                 software: If SMMU()_SCR1[GASRAE]=0, Secure software must not set HYPC to 1 for any
                                                                 secure translation context bank. If SMMU()_SCR1[GASRAE]=1, Secure software must not
                                                                 set HYPC to 1 for any non-secure translation context bank. Otherwise, UNPREDICTABLE
                                                                 behavior might occur.

                                                                 If CTYPE=3, context bank index <2>, see [BPSHCFG_CNBDX0]. */
        uint32_t bpshcfg_cbndx0        : 2;  /**< [  9:  8](R/W) Bypass shared configuration or context bank index <1:0>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, bypass shared configuration mode. CNXXXX ignores the value, R/W for software
                                                                 only.

                                                                 If CTYPE=3, context bank index <1:0>. The translation context bank index used for the
                                                                 stage 2 translation context bank in a nested translation. The full 8-bit context bank
                                                                 index is shared between the [MEMATTR_CBNDX4], [FB_CBNDX3], [HYPC_CBNDX2] and
                                                                 [BPSHCFG_CBNDX0] fields. Behavior is UNPREDICTABLE if the SMMU()_CBAR() register
                                                                 associated with the translation context specified by SMMU()_CBAR()[CBNDX] has
                                                                 any value other than 0x0 to specify a stage 2 translation context bank.) */
        uint32_t vmid                  : 8;  /**< [  7:  0](R/W/H) Virtual machine identifier associated with context bank.
                                                                 Writes to this field are zero extended to form a 16-bit internal VMID.
                                                                 See also SMMU()_CBA2R()[VMID16].

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is set. */
#else /* Word 0 - Little Endian */
        uint32_t vmid                  : 8;  /**< [  7:  0](R/W/H) Virtual machine identifier associated with context bank.
                                                                 Writes to this field are zero extended to form a 16-bit internal VMID.
                                                                 See also SMMU()_CBA2R()[VMID16].

                                                                 This field is RAZ when SMMU()_(S)CR0[VMID16EN] is set. */
        uint32_t bpshcfg_cbndx0        : 2;  /**< [  9:  8](R/W) Bypass shared configuration or context bank index <1:0>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, bypass shared configuration mode. CNXXXX ignores the value, R/W for software
                                                                 only.

                                                                 If CTYPE=3, context bank index <1:0>. The translation context bank index used for the
                                                                 stage 2 translation context bank in a nested translation. The full 8-bit context bank
                                                                 index is shared between the [MEMATTR_CBNDX4], [FB_CBNDX3], [HYPC_CBNDX2] and
                                                                 [BPSHCFG_CBNDX0] fields. Behavior is UNPREDICTABLE if the SMMU()_CBAR() register
                                                                 associated with the translation context specified by SMMU()_CBAR()[CBNDX] has
                                                                 any value other than 0x0 to specify a stage 2 translation context bank.) */
        uint32_t hypc_cbndx2           : 1;  /**< [ 10: 10](R/W) Hypervisor context or E2HC context or context bank index <2>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, and SMMU()_(S)CR0[HYPMODE]=0, hypervisor context.
                                                                 0 = Non-hypervisor context. Use VMID and ASID for TLB tagging.
                                                                 1 = Hypervisor context. Do not use VMID and ASID for TLB tagging.

                                                                 If CTYPE=1, and SMMU()_(S)CR0[HYPMODE]=1, E2HC context.  In CNXXXX, E2HC or
                                                                 non-E2HC must be set identically across all SMMUs.
                                                                 0 = Non-E2HC context.
                                                                 1 = E2HC context.

                                                                 In an interaction with the security extensions, the following restrictions apply to secure
                                                                 software: If SMMU()_SCR1[GASRAE]=0, Secure software must not set HYPC to 1 for any
                                                                 secure translation context bank. If SMMU()_SCR1[GASRAE]=1, Secure software must not
                                                                 set HYPC to 1 for any non-secure translation context bank. Otherwise, UNPREDICTABLE
                                                                 behavior might occur.

                                                                 If CTYPE=3, context bank index <2>, see [BPSHCFG_CNBDX0]. */
        uint32_t fb_cbndx3             : 1;  /**< [ 11: 11](R/W) Force broadcast of TLB and cache maintenance operations or context bank index<3>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, force broadcast mode. Ignored in CNXXXX, as NCB clients do not initiate
                                                                 invalidates.

                                                                 If CTYPE=3, context bank index <3>, see [BPSHCFG_CNBDX0]. */
        uint32_t memattr_cbndx4        : 4;  /**< [ 15: 12](R/W) Memory attributes, or context bank index <7:4>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, combined with the shared attributes of the previous translation stage.

                                                                 If CTYPE=3, context bank index <7:4>, see [BPSHCFG_CNBDX0]. */
        uint32_t ctype                 : 2;  /**< [ 17: 16](R/W) Register type.   Indicates the context format. Enumerated by SMMU_CTYPE_E. */
        uint32_t bsu                   : 2;  /**< [ 19: 18](RO) Barrier sharability upgrade. Not implemented in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 21: 20](RO) If CTYPE=1 or 3, read allocate configuration hint.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 CNXXXX ignores the hint. INTERNAL: Requested filed with ARM to make RO. */
        uint32_t wacfg                 : 2;  /**< [ 23: 22](RO) If CTYPE=1 or 3, write allocate configuration hint.

                                                                 If CTYPE=0/2, reserved.

                                                                 CNXXXX ignores the hint. INTERNAL: Requested filed with ARM to make RO. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbarx_s cn; */
} bdk_smmux_cbarx_t;

static inline uint64_t BDK_SMMUX_CBARX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBARX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830000010000ll + 0x1000000000ll * ((a) & 0x0) + 4ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830000010000ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830000010000ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBARX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBARX(a,b) bdk_smmux_cbarx_t
#define bustype_BDK_SMMUX_CBARX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBARX(a,b) "SMMUX_CBARX"
#define busnum_BDK_SMMUX_CBARX(a,b) (a)
#define arguments_BDK_SMMUX_CBARX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cbfrsynra#
 *
 * SMMU Context Bank Fault Restricted Syndrome A Register
 * Gives fault syndrome information about the access that caused an exception in the associated
 * translation.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cbfrsynrax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssd_index             : 16; /**< [ 31: 16](SRO/H) SSD index of the transaction that caused the fault. Only accessible to configuration
                                                                 accesses by secure software, else RAZ/WI. For CNXXXX, set on a fault to always match
                                                                 STREAMID. INTERNAL: Requested ARM extend this into <31>. */
        uint32_t streamid              : 16; /**< [ 15:  0](R/W/H) Stream ID of the transaction that caused the fault. */
#else /* Word 0 - Little Endian */
        uint32_t streamid              : 16; /**< [ 15:  0](R/W/H) Stream ID of the transaction that caused the fault. */
        uint32_t ssd_index             : 16; /**< [ 31: 16](SRO/H) SSD index of the transaction that caused the fault. Only accessible to configuration
                                                                 accesses by secure software, else RAZ/WI. For CNXXXX, set on a fault to always match
                                                                 STREAMID. INTERNAL: Requested ARM extend this into <31>. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cbfrsynrax_s cn; */
} bdk_smmux_cbfrsynrax_t;

static inline uint64_t BDK_SMMUX_CBFRSYNRAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBFRSYNRAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=63)))
        return 0x830000010400ll + 0x1000000000ll * ((a) & 0x0) + 4ll * ((b) & 0x3f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830000010400ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830000010400ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_CBFRSYNRAX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_CBFRSYNRAX(a,b) bdk_smmux_cbfrsynrax_t
#define bustype_BDK_SMMUX_CBFRSYNRAX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CBFRSYNRAX(a,b) "SMMUX_CBFRSYNRAX"
#define busnum_BDK_SMMUX_CBFRSYNRAX(a,b) (a)
#define arguments_BDK_SMMUX_CBFRSYNRAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_cidr0
 *
 * SMMU Component Identification Register 0
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cidr0_s cn; */
} bdk_smmux_cidr0_t;

static inline uint64_t BDK_SMMUX_CIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000ff0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000ff0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000ff0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_CIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_CIDR0(a) bdk_smmux_cidr0_t
#define bustype_BDK_SMMUX_CIDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CIDR0(a) "SMMUX_CIDR0"
#define busnum_BDK_SMMUX_CIDR0(a) (a)
#define arguments_BDK_SMMUX_CIDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_cidr1
 *
 * SMMU Component Identification Register 1
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cidr1_s cn; */
} bdk_smmux_cidr1_t;

static inline uint64_t BDK_SMMUX_CIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000ff4ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000ff4ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000ff4ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_CIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_CIDR1(a) bdk_smmux_cidr1_t
#define bustype_BDK_SMMUX_CIDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CIDR1(a) "SMMUX_CIDR1"
#define busnum_BDK_SMMUX_CIDR1(a) (a)
#define arguments_BDK_SMMUX_CIDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_cidr2
 *
 * SMMU Component Identification Register 2
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cidr2_s cn; */
} bdk_smmux_cidr2_t;

static inline uint64_t BDK_SMMUX_CIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000ff8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000ff8ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000ff8ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_CIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_CIDR2(a) bdk_smmux_cidr2_t
#define bustype_BDK_SMMUX_CIDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CIDR2(a) "SMMUX_CIDR2"
#define busnum_BDK_SMMUX_CIDR2(a) (a)
#define arguments_BDK_SMMUX_CIDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_cidr3
 *
 * SMMU Component Identification Register 3
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_cidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
#else /* Word 0 - Little Endian */
        uint32_t preamble              : 8;  /**< [  7:  0](RO) Preamble identification value. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_cidr3_s cn; */
} bdk_smmux_cidr3_t;

static inline uint64_t BDK_SMMUX_CIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000ffcll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000ffcll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000ffcll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_CIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_CIDR3(a) bdk_smmux_cidr3_t
#define bustype_BDK_SMMUX_CIDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_CIDR3(a) "SMMUX_CIDR3"
#define busnum_BDK_SMMUX_CIDR3(a) (a)
#define arguments_BDK_SMMUX_CIDR3(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_debug
 *
 * SMMU Debug Registers
 * This register contains debug information. Added in pass 2.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t inflight              : 9;  /**< [ 29: 21](RO/H) Valid entries in inflight queue. */
        uint64_t walker                : 5;  /**< [ 20: 16](RO/H) Walkers active. */
        uint64_t translation_ch1       : 8;  /**< [ 15:  8](RO/H) Channel 1 translations in progress. */
        uint64_t translation_ch0       : 8;  /**< [  7:  0](RO/H) Channel 0 translations in progress. */
#else /* Word 0 - Little Endian */
        uint64_t translation_ch0       : 8;  /**< [  7:  0](RO/H) Channel 0 translations in progress. */
        uint64_t translation_ch1       : 8;  /**< [ 15:  8](RO/H) Channel 1 translations in progress. */
        uint64_t walker                : 5;  /**< [ 20: 16](RO/H) Walkers active. */
        uint64_t inflight              : 9;  /**< [ 29: 21](RO/H) Valid entries in inflight queue. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_debug_s cn; */
} bdk_smmux_debug_t;

static inline uint64_t BDK_SMMUX_DEBUG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_DEBUG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021070ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021070ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && (a<=3))
        return 0x830000021070ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_DEBUG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_DEBUG(a) bdk_smmux_debug_t
#define bustype_BDK_SMMUX_DEBUG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_DEBUG(a) "SMMUX_DEBUG"
#define busnum_BDK_SMMUX_DEBUG(a) (a)
#define arguments_BDK_SMMUX_DEBUG(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_diag_ctl
 *
 * SMMU Secure Diagnostic Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_diag_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t pg_cmb                : 2;  /**< [ 16: 15](SRO) Reserved. */
        uint64_t force_clks_active     : 1;  /**< [ 14: 14](SR/W) Forces the conditional clocks to be always on. For diagnostic use only. */
        uint64_t walkers               : 6;  /**< [ 13:  8](SR/W) Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
        uint64_t reserved_7            : 1;
        uint64_t throttle              : 1;  /**< [  6:  6](SR/W) Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
        uint64_t dis_bcstr             : 1;  /**< [  5:  5](SR/W) Reserved. */
        uint64_t dis_wcs1              : 2;  /**< [  4:  3](SR/W) Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_wcs2              : 2;  /**< [  2:  1](SR/W) Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_tlb               : 1;  /**< [  0:  0](SR/W) Disables hitting in the TLB. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t dis_tlb               : 1;  /**< [  0:  0](SR/W) Disables hitting in the TLB. For diagnostic use only. */
        uint64_t dis_wcs2              : 2;  /**< [  2:  1](SR/W) Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_wcs1              : 2;  /**< [  4:  3](SR/W) Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_bcstr             : 1;  /**< [  5:  5](SR/W) Reserved. */
        uint64_t throttle              : 1;  /**< [  6:  6](SR/W) Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
        uint64_t reserved_7            : 1;
        uint64_t walkers               : 6;  /**< [ 13:  8](SR/W) Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
        uint64_t force_clks_active     : 1;  /**< [ 14: 14](SR/W) Forces the conditional clocks to be always on. For diagnostic use only. */
        uint64_t pg_cmb                : 2;  /**< [ 16: 15](SRO) Reserved. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_diag_ctl_s cn88xxp1; */
    struct bdk_smmux_diag_ctl_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t pg_cmb                : 2;  /**< [ 16: 15](SR/W) Page combining.
                                                                 0x0 = Transactions into the TLB that miss that are to the same 4 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.
                                                                 0x1 = Transactions into the TLB that miss that are to the same 64 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.  This will
                                                                 improve performance, but must only be used when 64 KB is the smallest granule
                                                                 size used across all contexts in the SMMU (all SMMU()_CB()_TCR[TG0,TG1] = 0x3).
                                                                 0x2 = Every transaction into the TLB that misses will require a page table
                                                                 walk. For diagnostic use only.
                                                                 0x3 = Reserved. */
        uint64_t force_clks_active     : 1;  /**< [ 14: 14](SR/W) Forces the conditional clocks to be always on. For diagnostic use only. */
        uint64_t walkers               : 6;  /**< [ 13:  8](SR/W) Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
        uint64_t reserved_7            : 1;
        uint64_t throttle              : 1;  /**< [  6:  6](SR/W) Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
        uint64_t dis_bcstr             : 1;  /**< [  5:  5](SR/W) Reserved. */
        uint64_t dis_wcs1              : 2;  /**< [  4:  3](SR/W) Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_wcs2              : 2;  /**< [  2:  1](SR/W) Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_tlb               : 1;  /**< [  0:  0](SR/W) Disables hitting in the TLB. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t dis_tlb               : 1;  /**< [  0:  0](SR/W) Disables hitting in the TLB. For diagnostic use only. */
        uint64_t dis_wcs2              : 2;  /**< [  2:  1](SR/W) Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_wcs1              : 2;  /**< [  4:  3](SR/W) Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_bcstr             : 1;  /**< [  5:  5](SR/W) Reserved. */
        uint64_t throttle              : 1;  /**< [  6:  6](SR/W) Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
        uint64_t reserved_7            : 1;
        uint64_t walkers               : 6;  /**< [ 13:  8](SR/W) Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
        uint64_t force_clks_active     : 1;  /**< [ 14: 14](SR/W) Forces the conditional clocks to be always on. For diagnostic use only. */
        uint64_t pg_cmb                : 2;  /**< [ 16: 15](SR/W) Page combining.
                                                                 0x0 = Transactions into the TLB that miss that are to the same 4 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.
                                                                 0x1 = Transactions into the TLB that miss that are to the same 64 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.  This will
                                                                 improve performance, but must only be used when 64 KB is the smallest granule
                                                                 size used across all contexts in the SMMU (all SMMU()_CB()_TCR[TG0,TG1] = 0x3).
                                                                 0x2 = Every transaction into the TLB that misses will require a page table
                                                                 walk. For diagnostic use only.
                                                                 0x3 = Reserved. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_diag_ctl_cn81xx cn83xx; */
    struct bdk_smmux_diag_ctl_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t pg_cmb                : 2;  /**< [ 16: 15](SR/W) Page combining.
                                                                 0x0 = Transactions into the TLB that miss that are to the same 4 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.
                                                                 0x1 = Transactions into the TLB that miss that are to the same 64 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.  This will
                                                                 improve performance, but must only be used when 64 KB is the smallest granule
                                                                 size used across all contexts in the SMMU (all SMMU()_CB()_TCR[TG0,TG1] = 0x3).
                                                                 0x2 = Every transaction into the TLB that misses will require a page table
                                                                 walk. For diagnostic use only.
                                                                 0x3 = Reserved.

                                                                 Added in pass 2. */
        uint64_t force_clks_active     : 1;  /**< [ 14: 14](SR/W) Forces the conditional clocks to be always on. For diagnostic use only. */
        uint64_t walkers               : 6;  /**< [ 13:  8](SR/W) Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
        uint64_t reserved_7            : 1;
        uint64_t throttle              : 1;  /**< [  6:  6](SR/W) Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
        uint64_t dis_bcstr             : 1;  /**< [  5:  5](SR/W) Reserved. */
        uint64_t dis_wcs1              : 2;  /**< [  4:  3](SR/W) Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_wcs2              : 2;  /**< [  2:  1](SR/W) Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_tlb               : 1;  /**< [  0:  0](SR/W) Disables hitting in the TLB. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t dis_tlb               : 1;  /**< [  0:  0](SR/W) Disables hitting in the TLB. For diagnostic use only. */
        uint64_t dis_wcs2              : 2;  /**< [  2:  1](SR/W) Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_wcs1              : 2;  /**< [  4:  3](SR/W) Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
        uint64_t dis_bcstr             : 1;  /**< [  5:  5](SR/W) Reserved. */
        uint64_t throttle              : 1;  /**< [  6:  6](SR/W) Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
        uint64_t reserved_7            : 1;
        uint64_t walkers               : 6;  /**< [ 13:  8](SR/W) Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
        uint64_t force_clks_active     : 1;  /**< [ 14: 14](SR/W) Forces the conditional clocks to be always on. For diagnostic use only. */
        uint64_t pg_cmb                : 2;  /**< [ 16: 15](SR/W) Page combining.
                                                                 0x0 = Transactions into the TLB that miss that are to the same 4 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.
                                                                 0x1 = Transactions into the TLB that miss that are to the same 64 KB page as an
                                                                 already outstanding miss are combined into a single page table walk.  This will
                                                                 improve performance, but must only be used when 64 KB is the smallest granule
                                                                 size used across all contexts in the SMMU (all SMMU()_CB()_TCR[TG0,TG1] = 0x3).
                                                                 0x2 = Every transaction into the TLB that misses will require a page table
                                                                 walk. For diagnostic use only.
                                                                 0x3 = Reserved.

                                                                 Added in pass 2. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_smmux_diag_ctl_t;

static inline uint64_t BDK_SMMUX_DIAG_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_DIAG_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020030ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020030ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020030ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_DIAG_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_DIAG_CTL(a) bdk_smmux_diag_ctl_t
#define bustype_BDK_SMMUX_DIAG_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_DIAG_CTL(a) "SMMUX_DIAG_CTL"
#define busnum_BDK_SMMUX_DIAG_CTL(a) (a)
#define arguments_BDK_SMMUX_DIAG_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_ecc_ctl_0
 *
 * SMMU Secure ECC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_ecc_ctl_0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_21_63        : 43;
        uint64_t ram_cdis              : 21; /**< [ 20:  0](SR/W) RAM ECC correction disable. Each bit corresponds to a different RAM. INTERNAL: Bits
                                                                 do not match SMMU()_ERR_INT[RAM_SBE].
                                                                 <20> = WCTL.
                                                                 <19> = TCTL.
                                                                 <18> = XL_MFIFO.
                                                                 <17> = MSIX.
                                                                 <16> = CONTEXT_IDR.
                                                                 <15> = CB_FRSYNRA.
                                                                 <14> = CB_IPAFAR.
                                                                 <13> = CB_FSYNR0.
                                                                 <12> = CB_FAR.
                                                                 <11> = S2CR.
                                                                 <10> = CB_ACTLR.
                                                                 <9>  = CB_TCR2.
                                                                 <8>  = SSDR.
                                                                 <7>  = SCTLR.
                                                                 <6>  = CB_MAIR0.
                                                                 <5>  = CB_MAIR1.
                                                                 <4>  = CBAR.
                                                                 <3>  = CBA2R.
                                                                 <2>  = CB_TTBR0.
                                                                 <1>  = CB_TTBR1.
                                                                 <0>  = CB_TCR. */
#else /* Word 0 - Little Endian */
        uint64_t ram_cdis              : 21; /**< [ 20:  0](SR/W) RAM ECC correction disable. Each bit corresponds to a different RAM. INTERNAL: Bits
                                                                 do not match SMMU()_ERR_INT[RAM_SBE].
                                                                 <20> = WCTL.
                                                                 <19> = TCTL.
                                                                 <18> = XL_MFIFO.
                                                                 <17> = MSIX.
                                                                 <16> = CONTEXT_IDR.
                                                                 <15> = CB_FRSYNRA.
                                                                 <14> = CB_IPAFAR.
                                                                 <13> = CB_FSYNR0.
                                                                 <12> = CB_FAR.
                                                                 <11> = S2CR.
                                                                 <10> = CB_ACTLR.
                                                                 <9>  = CB_TCR2.
                                                                 <8>  = SSDR.
                                                                 <7>  = SCTLR.
                                                                 <6>  = CB_MAIR0.
                                                                 <5>  = CB_MAIR1.
                                                                 <4>  = CBAR.
                                                                 <3>  = CBA2R.
                                                                 <2>  = CB_TTBR0.
                                                                 <1>  = CB_TTBR1.
                                                                 <0>  = CB_TCR. */
        uint64_t reserved_21_63        : 43;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_ecc_ctl_0_s cn; */
} bdk_smmux_ecc_ctl_0_t;

static inline uint64_t BDK_SMMUX_ECC_CTL_0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ECC_CTL_0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000200f0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000200f0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000200f0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ECC_CTL_0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ECC_CTL_0(a) bdk_smmux_ecc_ctl_0_t
#define bustype_BDK_SMMUX_ECC_CTL_0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ECC_CTL_0(a) "SMMUX_ECC_CTL_0"
#define busnum_BDK_SMMUX_ECC_CTL_0(a) (a)
#define arguments_BDK_SMMUX_ECC_CTL_0(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_ecc_ctl_1
 *
 * SMMU Secure ECC Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_ecc_ctl_1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_flip1             : 21; /**< [ 52: 32](SR/W) Flip syndrome bits on write. Flip syndrome bit <1> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. INTERNAL: Bits enumerated by
                                                                 SMMU()_ECC_CTL_0[RAM_CDIS]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_flip0             : 21; /**< [ 20:  0](SR/W) Flip syndrome bits on write. Flip syndrome bit <0> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. INTERNAL: Bits enumerated by
                                                                 SMMU()_ECC_CTL_0[RAM_CDIS]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_flip0             : 21; /**< [ 20:  0](SR/W) Flip syndrome bits on write. Flip syndrome bit <0> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. INTERNAL: Bits enumerated by
                                                                 SMMU()_ECC_CTL_0[RAM_CDIS]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_flip1             : 21; /**< [ 52: 32](SR/W) Flip syndrome bits on write. Flip syndrome bit <1> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. INTERNAL: Bits enumerated by
                                                                 SMMU()_ECC_CTL_0[RAM_CDIS]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_ecc_ctl_1_s cn; */
} bdk_smmux_ecc_ctl_1_t;

static inline uint64_t BDK_SMMUX_ECC_CTL_1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ECC_CTL_1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000200f8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000200f8ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000200f8ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ECC_CTL_1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ECC_CTL_1(a) bdk_smmux_ecc_ctl_1_t
#define bustype_BDK_SMMUX_ECC_CTL_1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ECC_CTL_1(a) "SMMUX_ECC_CTL_1"
#define busnum_BDK_SMMUX_ECC_CTL_1(a) (a)
#define arguments_BDK_SMMUX_ECC_CTL_1(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_err_ena_w1c
 *
 * SMMU ECC Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1C/H) Reads or clears enable for SMMU(0..3)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1C/H) Reads or clears enable for SMMU(0..3)_ERR_INT[RAM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1C/H) Reads or clears enable for SMMU(0..3)_ERR_INT[RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1C/H) Reads or clears enable for SMMU(0..3)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    struct bdk_smmux_err_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1C/H) Reads or clears enable for SMMU(0)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1C/H) Reads or clears enable for SMMU(0)_ERR_INT[RAM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1C/H) Reads or clears enable for SMMU(0)_ERR_INT[RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1C/H) Reads or clears enable for SMMU(0)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_err_ena_w1c_s cn88xx; */
    /* struct bdk_smmux_err_ena_w1c_s cn83xx; */
} bdk_smmux_err_ena_w1c_t;

static inline uint64_t BDK_SMMUX_ERR_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000200a0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000200a0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000200a0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ERR_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ERR_ENA_W1C(a) bdk_smmux_err_ena_w1c_t
#define bustype_BDK_SMMUX_ERR_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ERR_ENA_W1C(a) "SMMUX_ERR_ENA_W1C"
#define busnum_BDK_SMMUX_ERR_ENA_W1C(a) (a)
#define arguments_BDK_SMMUX_ERR_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_err_ena_w1s
 *
 * SMMU ECC Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets enable for SMMU(0..3)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets enable for SMMU(0..3)_ERR_INT[RAM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets enable for SMMU(0..3)_ERR_INT[RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets enable for SMMU(0..3)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    struct bdk_smmux_err_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets enable for SMMU(0)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets enable for SMMU(0)_ERR_INT[RAM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets enable for SMMU(0)_ERR_INT[RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets enable for SMMU(0)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_err_ena_w1s_s cn88xx; */
    /* struct bdk_smmux_err_ena_w1s_s cn83xx; */
} bdk_smmux_err_ena_w1s_t;

static inline uint64_t BDK_SMMUX_ERR_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000200b0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000200b0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000200b0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ERR_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ERR_ENA_W1S(a) bdk_smmux_err_ena_w1s_t
#define bustype_BDK_SMMUX_ERR_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ERR_ENA_W1S(a) "SMMUX_ERR_ENA_W1S"
#define busnum_BDK_SMMUX_ERR_ENA_W1S(a) (a)
#define arguments_BDK_SMMUX_ERR_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_err_int
 *
 * SMMU Error Interrupt Register
 * Internal:
 * This register contains ECC and other miscellaneous error bits.  INTERNAL: Errors are only
 * reported in the lowest number SMMU in each SMMU that shares an IOB.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1C/H) Double-bit error detected in internal RAM. INTERNAL: Bits enumerated by [RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1C/H) Single-bit error detected in internal RAM.
                                                                 <20> = TCTL.
                                                                 <19> = WCTL.
                                                                 <18> = XL_MFIFO.
                                                                 <17> = MSIX.
                                                                 <16> = CONTEXT_IDR.
                                                                 <15> = CB_FRSYNRA.
                                                                 <14> = CB_IPAFAR.
                                                                 <13> = CB_FSYNR0.
                                                                 <12> = CB_FAR.
                                                                 <11> = S2CR.
                                                                 <10> = CB_ACTLR.
                                                                 <9>  = CB_TCR2.
                                                                 <8>  = SSDR.
                                                                 <7>  = SCTLR.
                                                                 <6>  = CB_MAIR0.
                                                                 <5>  = CB_MAIR1.
                                                                 <4>  = CBAR.
                                                                 <3>  = CBA2R.
                                                                 <2>  = CB_TTBR0.
                                                                 <1>  = CB_TTBR1.
                                                                 <0>  = CB_TCR. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1C/H) Single-bit error detected in internal RAM.
                                                                 <20> = TCTL.
                                                                 <19> = WCTL.
                                                                 <18> = XL_MFIFO.
                                                                 <17> = MSIX.
                                                                 <16> = CONTEXT_IDR.
                                                                 <15> = CB_FRSYNRA.
                                                                 <14> = CB_IPAFAR.
                                                                 <13> = CB_FSYNR0.
                                                                 <12> = CB_FAR.
                                                                 <11> = S2CR.
                                                                 <10> = CB_ACTLR.
                                                                 <9>  = CB_TCR2.
                                                                 <8>  = SSDR.
                                                                 <7>  = SCTLR.
                                                                 <6>  = CB_MAIR0.
                                                                 <5>  = CB_MAIR1.
                                                                 <4>  = CBAR.
                                                                 <3>  = CBA2R.
                                                                 <2>  = CB_TTBR0.
                                                                 <1>  = CB_TTBR1.
                                                                 <0>  = CB_TCR. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1C/H) Double-bit error detected in internal RAM. INTERNAL: Bits enumerated by [RAM_SBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_err_int_s cn; */
} bdk_smmux_err_int_t;

static inline uint64_t BDK_SMMUX_ERR_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020080ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020080ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020080ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ERR_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ERR_INT(a) bdk_smmux_err_int_t
#define bustype_BDK_SMMUX_ERR_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ERR_INT(a) "SMMUX_ERR_INT"
#define busnum_BDK_SMMUX_ERR_INT(a) (a)
#define arguments_BDK_SMMUX_ERR_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_err_int_w1s
 *
 * SMMU ECC Interrupt Set Register
 * This register sets interrupt bits.
 * Internal:
 * INTERNAL: Errors are only reported in the lowest number SMMU in each SMMU that shares an IOB.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets SMMU(0..3)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets SMMU(0..3)_ERR_INT[RAM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets SMMU(0..3)_ERR_INT[RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets SMMU(0..3)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } s;
    struct bdk_smmux_err_int_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_53_63        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets SMMU(0)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets SMMU(0)_ERR_INT[RAM_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ram_sbe               : 21; /**< [ 20:  0](R/W1S/H) Reads or sets SMMU(0)_ERR_INT[RAM_SBE]. */
        uint64_t reserved_21_31        : 11;
        uint64_t ram_dbe               : 21; /**< [ 52: 32](R/W1S/H) Reads or sets SMMU(0)_ERR_INT[RAM_DBE]. */
        uint64_t reserved_53_63        : 11;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_err_int_w1s_s cn88xx; */
    /* struct bdk_smmux_err_int_w1s_s cn83xx; */
} bdk_smmux_err_int_w1s_t;

static inline uint64_t BDK_SMMUX_ERR_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020090ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020090ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020090ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_ERR_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_ERR_INT_W1S(a) bdk_smmux_err_int_w1s_t
#define bustype_BDK_SMMUX_ERR_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_ERR_INT_W1S(a) "SMMUX_ERR_INT_W1S"
#define busnum_BDK_SMMUX_ERR_INT_W1S(a) (a)
#define arguments_BDK_SMMUX_ERR_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr0
 *
 * SMMU Identification Register 0
 * Provides SMMU capability information.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ses                   : 1;  /**< [ 31: 31](SRO) Security extensions support. */
        uint32_t s1ts                  : 1;  /**< [ 30: 30](RO) Stage 1 translation support. */
        uint32_t s2ts                  : 1;  /**< [ 29: 29](RO) Stage 2 translation support.
                                                                 0 = Stage 2 translations are not supported.
                                                                 1 = Stage 2 translations are supported.

                                                                 As stage 2 translation is not supported for secure client accesses, the value returned in
                                                                 this field relates to SMMU capabilities for non-secure client accesses. */
        uint32_t nts                   : 1;  /**< [ 28: 28](RO) Nested translation support.
                                                                 As stage 2 (and therefore nested) translation is not supported for secure client accesses,
                                                                 the value returned in this field relates to SMMU capabilities for non-secure client
                                                                 accesses. */
        uint32_t sms                   : 1;  /**< [ 27: 27](RO) Stream match support. */
        uint32_t atosns                : 1;  /**< [ 26: 26](RO) Address translations operation not supported.

                                                                 Address translation operations are deprecated in SMMUv2 and in CNXXXX not
                                                                 supported. */
        uint32_t ptfs                  : 2;  /**< [ 25: 24](RO) Page table format supported.
                                                                 0x0 = V7L and V7S supported.
                                                                 0x1 = V7L format supported.
                                                                 0x2 = Only the V8 format is supported.
                                                                 0x3 = Reserved.

                                                                 In CNXXXX V8 only. */
        uint32_t numirpt               : 8;  /**< [ 23: 16](RO) Number of implemented context fault interrupts. Always 0x1 in ARMv8. */
        uint32_t exsmrgs               : 1;  /**< [ 15: 15](RAZ) Extended stream matching extension supported. */
        uint32_t cttw                  : 1;  /**< [ 14: 14](RO) Coherent translation table walk supported. */
        uint32_t btm                   : 1;  /**< [ 13: 13](RO) Broadcast TLB maintenance supported. */
        uint32_t numsidb               : 4;  /**< [ 12:  9](RO) Number of supported stream ID bits. */
        uint32_t exids                 : 1;  /**< [  8:  8](RO) Extended stream IDs are supported. */
        uint32_t numsmrg               : 8;  /**< [  7:  0](RO/H) Number of supported stream mapping registers groups. Access to this field by non-secure
                                                                 software gives the value configured in SMMU()_SCR1[NSNUMSMRGO]. */
#else /* Word 0 - Little Endian */
        uint32_t numsmrg               : 8;  /**< [  7:  0](RO/H) Number of supported stream mapping registers groups. Access to this field by non-secure
                                                                 software gives the value configured in SMMU()_SCR1[NSNUMSMRGO]. */
        uint32_t exids                 : 1;  /**< [  8:  8](RO) Extended stream IDs are supported. */
        uint32_t numsidb               : 4;  /**< [ 12:  9](RO) Number of supported stream ID bits. */
        uint32_t btm                   : 1;  /**< [ 13: 13](RO) Broadcast TLB maintenance supported. */
        uint32_t cttw                  : 1;  /**< [ 14: 14](RO) Coherent translation table walk supported. */
        uint32_t exsmrgs               : 1;  /**< [ 15: 15](RAZ) Extended stream matching extension supported. */
        uint32_t numirpt               : 8;  /**< [ 23: 16](RO) Number of implemented context fault interrupts. Always 0x1 in ARMv8. */
        uint32_t ptfs                  : 2;  /**< [ 25: 24](RO) Page table format supported.
                                                                 0x0 = V7L and V7S supported.
                                                                 0x1 = V7L format supported.
                                                                 0x2 = Only the V8 format is supported.
                                                                 0x3 = Reserved.

                                                                 In CNXXXX V8 only. */
        uint32_t atosns                : 1;  /**< [ 26: 26](RO) Address translations operation not supported.

                                                                 Address translation operations are deprecated in SMMUv2 and in CNXXXX not
                                                                 supported. */
        uint32_t sms                   : 1;  /**< [ 27: 27](RO) Stream match support. */
        uint32_t nts                   : 1;  /**< [ 28: 28](RO) Nested translation support.
                                                                 As stage 2 (and therefore nested) translation is not supported for secure client accesses,
                                                                 the value returned in this field relates to SMMU capabilities for non-secure client
                                                                 accesses. */
        uint32_t s2ts                  : 1;  /**< [ 29: 29](RO) Stage 2 translation support.
                                                                 0 = Stage 2 translations are not supported.
                                                                 1 = Stage 2 translations are supported.

                                                                 As stage 2 translation is not supported for secure client accesses, the value returned in
                                                                 this field relates to SMMU capabilities for non-secure client accesses. */
        uint32_t s1ts                  : 1;  /**< [ 30: 30](RO) Stage 1 translation support. */
        uint32_t ses                   : 1;  /**< [ 31: 31](SRO) Security extensions support. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr0_s cn; */
} bdk_smmux_idr0_t;

static inline uint64_t BDK_SMMUX_IDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000020ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000020ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000020ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR0(a) bdk_smmux_idr0_t
#define bustype_BDK_SMMUX_IDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR0(a) "SMMUX_IDR0"
#define busnum_BDK_SMMUX_IDR0(a) (a)
#define arguments_BDK_SMMUX_IDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr1
 *
 * SMMU Identification Register 1
 * Provides SMMU capability information.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pagesize              : 1;  /**< [ 31: 31](RO) Indicates the size of each page in the SMMU register map.
                                                                 0 = Each page consumes 4 Kbytes.
                                                                 1 = Each page consumes 64 Kbytes. */
        uint32_t numpagendxb           : 3;  /**< [ 30: 28](RO) Indicates how many pagesize pages occupy the global address space or the translation
                                                                 context address space where the number of pages is equal to 2^(NUMPAGENDXB + 1). */
        uint32_t reserved_26_27        : 2;
        uint32_t hafdbs                : 2;  /**< [ 25: 24](RO) Hardware access flag and dirty bit management supported.
                                                                 0x0 = No support for hardware update of either Access flag or Dirty bit information.
                                                                 0x1 = Support for hardware update of Access flag, but no support for hardware update of
                                                                 Dirty bit information.
                                                                 0x2 = Reserved.
                                                                 0x3 = Support for hardware update of both Access flag and Dirty bit information.

                                                                 CNXXXX does not support hardware access and dirty management. */
        uint32_t nums2cb               : 8;  /**< [ 23: 16](RO) Number of stage 2 context banks. Indicates the number of translation context banks that
                                                                 only support the stage 2 translation format. */
        uint32_t smcd                  : 1;  /**< [ 15: 15](RO) Stream match conflict detection.
                                                                 0 = The detection of all stream match conflicts is not guaranteed.
                                                                 1 = The detection of all stream match conflicts is guaranteed.

                                                                 CNXXXX detects stream match conflicts. */
        uint32_t reserved_14           : 1;
        uint32_t ssdtp                 : 2;  /**< [ 13: 12](SRO) Security state determination table present.
                                                                 0x0 = The security state determination address space is UNK/WI.
                                                                 0x1 = The security state determination address space is populated for up to 15-bit
                                                                 streams.
                                                                 0x2 = Reserved.
                                                                 0x3 = The security state determination address space is populated for up to 16-bit
                                                                 streams.

                                                                 CNXXXX implements a 16-bit security state determination table. */
        uint32_t numssdndxb            : 4;  /**< [ 11:  8](SRO) Indicates the number of SSD_Index bits for indexing the security state determination table. */
        uint32_t numcb                 : 8;  /**< [  7:  0](RO/H) Indicates the total number of implemented translation context banks in the range 0-128.
                                                                 The value reported in NUMCB includes translation context banks that only support stage 2
                                                                 format. The number of translation context banks that support the stage 1 format is given
                                                                 by [NUMCB] - [NUMS2CB]. A read of this field by non-secure software gives the value
                                                                 configured in [NSNUMCBO]. */
#else /* Word 0 - Little Endian */
        uint32_t numcb                 : 8;  /**< [  7:  0](RO/H) Indicates the total number of implemented translation context banks in the range 0-128.
                                                                 The value reported in NUMCB includes translation context banks that only support stage 2
                                                                 format. The number of translation context banks that support the stage 1 format is given
                                                                 by [NUMCB] - [NUMS2CB]. A read of this field by non-secure software gives the value
                                                                 configured in [NSNUMCBO]. */
        uint32_t numssdndxb            : 4;  /**< [ 11:  8](SRO) Indicates the number of SSD_Index bits for indexing the security state determination table. */
        uint32_t ssdtp                 : 2;  /**< [ 13: 12](SRO) Security state determination table present.
                                                                 0x0 = The security state determination address space is UNK/WI.
                                                                 0x1 = The security state determination address space is populated for up to 15-bit
                                                                 streams.
                                                                 0x2 = Reserved.
                                                                 0x3 = The security state determination address space is populated for up to 16-bit
                                                                 streams.

                                                                 CNXXXX implements a 16-bit security state determination table. */
        uint32_t reserved_14           : 1;
        uint32_t smcd                  : 1;  /**< [ 15: 15](RO) Stream match conflict detection.
                                                                 0 = The detection of all stream match conflicts is not guaranteed.
                                                                 1 = The detection of all stream match conflicts is guaranteed.

                                                                 CNXXXX detects stream match conflicts. */
        uint32_t nums2cb               : 8;  /**< [ 23: 16](RO) Number of stage 2 context banks. Indicates the number of translation context banks that
                                                                 only support the stage 2 translation format. */
        uint32_t hafdbs                : 2;  /**< [ 25: 24](RO) Hardware access flag and dirty bit management supported.
                                                                 0x0 = No support for hardware update of either Access flag or Dirty bit information.
                                                                 0x1 = Support for hardware update of Access flag, but no support for hardware update of
                                                                 Dirty bit information.
                                                                 0x2 = Reserved.
                                                                 0x3 = Support for hardware update of both Access flag and Dirty bit information.

                                                                 CNXXXX does not support hardware access and dirty management. */
        uint32_t reserved_26_27        : 2;
        uint32_t numpagendxb           : 3;  /**< [ 30: 28](RO) Indicates how many pagesize pages occupy the global address space or the translation
                                                                 context address space where the number of pages is equal to 2^(NUMPAGENDXB + 1). */
        uint32_t pagesize              : 1;  /**< [ 31: 31](RO) Indicates the size of each page in the SMMU register map.
                                                                 0 = Each page consumes 4 Kbytes.
                                                                 1 = Each page consumes 64 Kbytes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr1_s cn; */
} bdk_smmux_idr1_t;

static inline uint64_t BDK_SMMUX_IDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000024ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000024ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000024ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR1(a) bdk_smmux_idr1_t
#define bustype_BDK_SMMUX_IDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR1(a) "SMMUX_IDR1"
#define busnum_BDK_SMMUX_IDR1(a) (a)
#define arguments_BDK_SMMUX_IDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr2
 *
 * SMMU Identification Register 2
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t dipans                : 1;  /**< [ 30: 30](RO) Privileged access never support.
                                                                 When set, indicates supports ARM v8.1 privileged access never.
                                                                 See SMMU()_S2CR()[PRIVCFG].

                                                                 Note unlike the processor architecture, DIPAN applies to both instruction and data
                                                                 transactions; thus to distinguish the two features then the SMMU feature is called DIPAN
                                                                 whilst the processor architecture version is called PAN. */
        uint32_t compindexs            : 1;  /**< [ 29: 29](RO) StreamID compressed indexing support. */
        uint32_t hads                  : 1;  /**< [ 28: 28](RO) Hierarchical attribute disable support.
                                                                 When set, indicates supports ARM v8.1 hierarchical attribute disables.
                                                                 See SMMU()_CB()_TCR2[HAD0]. */
        uint32_t e2hs                  : 1;  /**< [ 27: 27](RO) E2H context (E2HC) supported.
                                                                 When set, indicates supports ARM v8.1 virtual host extension contexts.
                                                                 See SMMU()_CBA2R()[E2HC]. */
        uint32_t exnumsmrg             : 11; /**< [ 26: 16](RO) For extended stream match extension, the number of extended stream match
                                                                 register groups supported.

                                                                 For CNXXXX, 0x0 as extended stream match extension is not supported. */
        uint32_t vmid16s               : 1;  /**< [ 15: 15](RO) When set, indicates that 16-bit VMIDs are supported (ARMv8 large system extensions). */
        uint32_t ptfsv8_64kb           : 1;  /**< [ 14: 14](RO) When set, indicates that ARMv8 page tables using 64kb page granule are supported. */
        uint32_t ptfsv8_16kb           : 1;  /**< [ 13: 13](RO) When set, indicates that ARMv8 page tables using 16kb page granule are supported. */
        uint32_t ptfsv8_4kb            : 1;  /**< [ 12: 12](RO) When set, indicates that ARMv8 page tables using 4kb page granule are supported. */
        uint32_t ubs                   : 4;  /**< [ 11:  8](RO) Upstream bus size.  This field specifies the maximum width of any upstream address port
                                                                 used by client devices to perform address translations.
                                                                 0x5 = 48-bit + 1 sign bit. */
        uint32_t oas                   : 4;  /**< [  7:  4](RO) Output address size. The maximum PA size supported.
                                                                 0x5 = 48-bit. */
        uint32_t ias                   : 4;  /**< [  3:  0](RO) Intermediate address size. The maximum IPA size supported.
                                                                 0x5 = 48-bit. */
#else /* Word 0 - Little Endian */
        uint32_t ias                   : 4;  /**< [  3:  0](RO) Intermediate address size. The maximum IPA size supported.
                                                                 0x5 = 48-bit. */
        uint32_t oas                   : 4;  /**< [  7:  4](RO) Output address size. The maximum PA size supported.
                                                                 0x5 = 48-bit. */
        uint32_t ubs                   : 4;  /**< [ 11:  8](RO) Upstream bus size.  This field specifies the maximum width of any upstream address port
                                                                 used by client devices to perform address translations.
                                                                 0x5 = 48-bit + 1 sign bit. */
        uint32_t ptfsv8_4kb            : 1;  /**< [ 12: 12](RO) When set, indicates that ARMv8 page tables using 4kb page granule are supported. */
        uint32_t ptfsv8_16kb           : 1;  /**< [ 13: 13](RO) When set, indicates that ARMv8 page tables using 16kb page granule are supported. */
        uint32_t ptfsv8_64kb           : 1;  /**< [ 14: 14](RO) When set, indicates that ARMv8 page tables using 64kb page granule are supported. */
        uint32_t vmid16s               : 1;  /**< [ 15: 15](RO) When set, indicates that 16-bit VMIDs are supported (ARMv8 large system extensions). */
        uint32_t exnumsmrg             : 11; /**< [ 26: 16](RO) For extended stream match extension, the number of extended stream match
                                                                 register groups supported.

                                                                 For CNXXXX, 0x0 as extended stream match extension is not supported. */
        uint32_t e2hs                  : 1;  /**< [ 27: 27](RO) E2H context (E2HC) supported.
                                                                 When set, indicates supports ARM v8.1 virtual host extension contexts.
                                                                 See SMMU()_CBA2R()[E2HC]. */
        uint32_t hads                  : 1;  /**< [ 28: 28](RO) Hierarchical attribute disable support.
                                                                 When set, indicates supports ARM v8.1 hierarchical attribute disables.
                                                                 See SMMU()_CB()_TCR2[HAD0]. */
        uint32_t compindexs            : 1;  /**< [ 29: 29](RO) StreamID compressed indexing support. */
        uint32_t dipans                : 1;  /**< [ 30: 30](RO) Privileged access never support.
                                                                 When set, indicates supports ARM v8.1 privileged access never.
                                                                 See SMMU()_S2CR()[PRIVCFG].

                                                                 Note unlike the processor architecture, DIPAN applies to both instruction and data
                                                                 transactions; thus to distinguish the two features then the SMMU feature is called DIPAN
                                                                 whilst the processor architecture version is called PAN. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr2_s cn; */
} bdk_smmux_idr2_t;

static inline uint64_t BDK_SMMUX_IDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000028ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000028ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000028ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR2(a) bdk_smmux_idr2_t
#define bustype_BDK_SMMUX_IDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR2(a) "SMMUX_IDR2"
#define busnum_BDK_SMMUX_IDR2(a) (a)
#define arguments_BDK_SMMUX_IDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr3
 *
 * SMMU Identification Register 3
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr3_s cn; */
} bdk_smmux_idr3_t;

static inline uint64_t BDK_SMMUX_IDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x83000000002cll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x83000000002cll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x83000000002cll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR3(a) bdk_smmux_idr3_t
#define bustype_BDK_SMMUX_IDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR3(a) "SMMUX_IDR3"
#define busnum_BDK_SMMUX_IDR3(a) (a)
#define arguments_BDK_SMMUX_IDR3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr4
 *
 * SMMU Identification Register 4
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr4_s cn; */
} bdk_smmux_idr4_t;

static inline uint64_t BDK_SMMUX_IDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000030ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000030ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000030ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR4", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR4(a) bdk_smmux_idr4_t
#define bustype_BDK_SMMUX_IDR4(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR4(a) "SMMUX_IDR4"
#define busnum_BDK_SMMUX_IDR4(a) (a)
#define arguments_BDK_SMMUX_IDR4(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr5
 *
 * SMMU Identification Register 5
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr5_s cn; */
} bdk_smmux_idr5_t;

static inline uint64_t BDK_SMMUX_IDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR5(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000034ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000034ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000034ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR5", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR5(a) bdk_smmux_idr5_t
#define bustype_BDK_SMMUX_IDR5(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR5(a) "SMMUX_IDR5"
#define busnum_BDK_SMMUX_IDR5(a) (a)
#define arguments_BDK_SMMUX_IDR5(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr6
 *
 * SMMU Identification Register 6
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr6_s cn; */
} bdk_smmux_idr6_t;

static inline uint64_t BDK_SMMUX_IDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR6(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000038ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000038ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000038ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR6", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR6(a) bdk_smmux_idr6_t
#define bustype_BDK_SMMUX_IDR6(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR6(a) "SMMUX_IDR6"
#define busnum_BDK_SMMUX_IDR6(a) (a)
#define arguments_BDK_SMMUX_IDR6(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_idr7
 *
 * SMMU Identification Register 7
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_idr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t major                 : 4;  /**< [  7:  4](RO) The major part of the implementation version number.
                                                                 For CNXXXX from PCCPF_SMMU()_REV[RID]<7:4>. */
        uint32_t minor                 : 4;  /**< [  3:  0](RO) The minor part of the implementation version number.
                                                                 For CNXXXX from PCCPF_SMMU()_REV[RID]<3:0>. */
#else /* Word 0 - Little Endian */
        uint32_t minor                 : 4;  /**< [  3:  0](RO) The minor part of the implementation version number.
                                                                 For CNXXXX from PCCPF_SMMU()_REV[RID]<3:0>. */
        uint32_t major                 : 4;  /**< [  7:  4](RO) The major part of the implementation version number.
                                                                 For CNXXXX from PCCPF_SMMU()_REV[RID]<7:4>. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_idr7_s cn; */
} bdk_smmux_idr7_t;

static inline uint64_t BDK_SMMUX_IDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR7(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x83000000003cll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x83000000003cll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x83000000003cll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_IDR7", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_IDR7(a) bdk_smmux_idr7_t
#define bustype_BDK_SMMUX_IDR7(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_IDR7(a) "SMMUX_IDR7"
#define busnum_BDK_SMMUX_IDR7(a) (a)
#define arguments_BDK_SMMUX_IDR7(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_look_par
 *
 * SMMU Secure Diagnostic Lookup Result Register
 * Receives the physical address from a SMMU()_LOOK_REQ operation. For diagnostic use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_look_par_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pa                    : 36; /**< [ 47: 12](SRO/H) If [FAULT]=0, physical address of the completed lookup. */
        uint64_t reserved_3_11         : 9;
        uint64_t nsec                  : 1;  /**< [  2:  2](SRO/H) If [FAULT]=0, non-secure. The final resolved secure state for the translation, matching
                                                                 the non-secure bit passed to the L2 cache. */
        uint64_t active                : 1;  /**< [  1:  1](SRO/H) Translation in progress. Set on write to SMMU()_LOOK_REQ[GO], cleared when translation
                                                                 has completed. */
        uint64_t fault                 : 1;  /**< [  0:  0](SRO/H) Fault. If 0 indicates completed successfully. If 1, the fault will not be recorded in the
                                                                 error registers. */
#else /* Word 0 - Little Endian */
        uint64_t fault                 : 1;  /**< [  0:  0](SRO/H) Fault. If 0 indicates completed successfully. If 1, the fault will not be recorded in the
                                                                 error registers. */
        uint64_t active                : 1;  /**< [  1:  1](SRO/H) Translation in progress. Set on write to SMMU()_LOOK_REQ[GO], cleared when translation
                                                                 has completed. */
        uint64_t nsec                  : 1;  /**< [  2:  2](SRO/H) If [FAULT]=0, non-secure. The final resolved secure state for the translation, matching
                                                                 the non-secure bit passed to the L2 cache. */
        uint64_t reserved_3_11         : 9;
        uint64_t pa                    : 36; /**< [ 47: 12](SRO/H) If [FAULT]=0, physical address of the completed lookup. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_look_par_s cn; */
} bdk_smmux_look_par_t;

static inline uint64_t BDK_SMMUX_LOOK_PAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_LOOK_PAR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020120ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020120ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020120ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_LOOK_PAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_LOOK_PAR(a) bdk_smmux_look_par_t
#define bustype_BDK_SMMUX_LOOK_PAR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_LOOK_PAR(a) "SMMUX_LOOK_PAR"
#define busnum_BDK_SMMUX_LOOK_PAR(a) (a)
#define arguments_BDK_SMMUX_LOOK_PAR(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_look_req
 *
 * SMMU Secure Diagnostic Lookup Request Register
 * For diagnostic use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_look_req_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t va                    : 37; /**< [ 48: 12](SR/W) Virtual address to lookup. */
        uint64_t reserved_3_11         : 9;
        uint64_t rd                    : 1;  /**< [  2:  2](SR/W) Read operation lookup; page must allow reads. Either a read or write operation must be asserted. */
        uint64_t wr                    : 1;  /**< [  1:  1](SR/W) Write operation lookup; page must allow writes. Either a read or write operation must be asserted. */
        uint64_t go                    : 1;  /**< [  0:  0](SWO) Write a one to request translation begin. Read SMMU()_LOOK_PAR[ACTIVE] to determine
                                                                 when the translation completes. */
#else /* Word 0 - Little Endian */
        uint64_t go                    : 1;  /**< [  0:  0](SWO) Write a one to request translation begin. Read SMMU()_LOOK_PAR[ACTIVE] to determine
                                                                 when the translation completes. */
        uint64_t wr                    : 1;  /**< [  1:  1](SR/W) Write operation lookup; page must allow writes. Either a read or write operation must be asserted. */
        uint64_t rd                    : 1;  /**< [  2:  2](SR/W) Read operation lookup; page must allow reads. Either a read or write operation must be asserted. */
        uint64_t reserved_3_11         : 9;
        uint64_t va                    : 37; /**< [ 48: 12](SR/W) Virtual address to lookup. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_look_req_s cn; */
} bdk_smmux_look_req_t;

static inline uint64_t BDK_SMMUX_LOOK_REQ(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_LOOK_REQ(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020100ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020100ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020100ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_LOOK_REQ", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_LOOK_REQ(a) bdk_smmux_look_req_t
#define bustype_BDK_SMMUX_LOOK_REQ(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_LOOK_REQ(a) "SMMUX_LOOK_REQ"
#define busnum_BDK_SMMUX_LOOK_REQ(a) (a)
#define arguments_BDK_SMMUX_LOOK_REQ(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_look_strm
 *
 * SMMU Secure Diagnostic Lookup Stream Register
 * Specifies additional lookup values for the next SMMU()_LOOK_REQ
 * operation. For diagnostic use only.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_look_strm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t stream                : 16; /**< [ 15:  0](SR/W) Stream ID. */
#else /* Word 0 - Little Endian */
        uint64_t stream                : 16; /**< [ 15:  0](SR/W) Stream ID. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_look_strm_s cn; */
} bdk_smmux_look_strm_t;

static inline uint64_t BDK_SMMUX_LOOK_STRM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_LOOK_STRM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000020110ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000020110ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000020110ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_LOOK_STRM", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_LOOK_STRM(a) bdk_smmux_look_strm_t
#define bustype_BDK_SMMUX_LOOK_STRM(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_LOOK_STRM(a) "SMMUX_LOOK_STRM"
#define busnum_BDK_SMMUX_LOOK_STRM(a) (a)
#define arguments_BDK_SMMUX_LOOK_STRM(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_msix_pba#
 *
 * SMMU MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the SMMU_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for each interrupt, enumerated by SMMU_INT_VEC_E. Bits that have no
                                                                 associated SMMU_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for each interrupt, enumerated by SMMU_INT_VEC_E. Bits that have no
                                                                 associated SMMU_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_msix_pbax_s cn; */
} bdk_smmux_msix_pbax_t;

static inline uint64_t BDK_SMMUX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=2)))
        return 0x83000f0f0000ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=4)))
        return 0x83000f0f0000ll + 0x1000000000ll * ((a) & 0x3) + 8ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=4)))
        return 0x83000f0f0000ll + 0x1000000000ll * ((a) & 0x3) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("SMMUX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_MSIX_PBAX(a,b) bdk_smmux_msix_pbax_t
#define bustype_BDK_SMMUX_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_MSIX_PBAX(a,b) "SMMUX_MSIX_PBAX"
#define busnum_BDK_SMMUX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_SMMUX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_msix_vec#_addr
 *
 * SMMU MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the SMMU_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SMMU()_MSIX_VEC()_ADDR, SMMU()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SMMU()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SMMU(0..3)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SMMU()_MSIX_VEC()_ADDR, SMMU()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SMMU()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SMMU(0..3)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    struct bdk_smmux_msix_vecx_addr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SMMU()_MSIX_VEC()_ADDR, SMMU()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SMMU()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SMMU(0)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SMMU()_MSIX_VEC()_ADDR, SMMU()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SMMU()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SMMU(0)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_msix_vecx_addr_s cn88xx; */
    /* struct bdk_smmux_msix_vecx_addr_s cn83xx; */
} bdk_smmux_msix_vecx_addr_t;

static inline uint64_t BDK_SMMUX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=133)))
        return 0x83000f000000ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=261)))
        return 0x83000f000000ll + 0x1000000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x1ff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=261)))
        return 0x83000f000000ll + 0x1000000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x1ff);
    __bdk_csr_fatal("SMMUX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_MSIX_VECX_ADDR(a,b) bdk_smmux_msix_vecx_addr_t
#define bustype_BDK_SMMUX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_MSIX_VECX_ADDR(a,b) "SMMUX_MSIX_VECX_ADDR"
#define busnum_BDK_SMMUX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_SMMUX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_msix_vec#_ctl
 *
 * SMMU MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the SMMU_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_msix_vecx_ctl_s
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
    /* struct bdk_smmux_msix_vecx_ctl_s cn; */
} bdk_smmux_msix_vecx_ctl_t;

static inline uint64_t BDK_SMMUX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=133)))
        return 0x83000f000008ll + 0x1000000000ll * ((a) & 0x0) + 0x10ll * ((b) & 0xff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=261)))
        return 0x83000f000008ll + 0x1000000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x1ff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=261)))
        return 0x83000f000008ll + 0x1000000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x1ff);
    __bdk_csr_fatal("SMMUX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_MSIX_VECX_CTL(a,b) bdk_smmux_msix_vecx_ctl_t
#define bustype_BDK_SMMUX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_MSIX_VECX_CTL(a,b) "SMMUX_MSIX_VECX_CTL"
#define busnum_BDK_SMMUX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_SMMUX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_ns_hit_perf
 *
 * SMMU Non-secure Hits Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_ns_hit_perf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Counts the number of hits in non-secure mode. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Counts the number of hits in non-secure mode. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_ns_hit_perf_s cn; */
} bdk_smmux_ns_hit_perf_t;

static inline uint64_t BDK_SMMUX_NS_HIT_PERF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NS_HIT_PERF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021010ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021010ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021010ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NS_HIT_PERF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NS_HIT_PERF(a) bdk_smmux_ns_hit_perf_t
#define bustype_BDK_SMMUX_NS_HIT_PERF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_NS_HIT_PERF(a) "SMMUX_NS_HIT_PERF"
#define busnum_BDK_SMMUX_NS_HIT_PERF(a) (a)
#define arguments_BDK_SMMUX_NS_HIT_PERF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nsacr
 *
 * SMMU Secure Alias for Auxiliary Configuration Register
 * Provides secure alias for non-secure register SMMU()_(S)ACR.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nsacr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t qos                   : 4;  /**< [ 31: 28](R/W) L2C quality-of-service value to use for standard transactions that are not by a specific
                                                                 context, and so SMMU()_CB()_ACTLR[QOS] is not applicable. */
        uint32_t qos_walk              : 4;  /**< [ 27: 24](R/W) L2C quality-of-service value to use for page table walks. For optimal performance, this
                                                                 typically would be set to the most preferential QoS value of zero. */
        uint32_t reserved_0_23         : 24;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_23         : 24;
        uint32_t qos_walk              : 4;  /**< [ 27: 24](R/W) L2C quality-of-service value to use for page table walks. For optimal performance, this
                                                                 typically would be set to the most preferential QoS value of zero. */
        uint32_t qos                   : 4;  /**< [ 31: 28](R/W) L2C quality-of-service value to use for standard transactions that are not by a specific
                                                                 context, and so SMMU()_CB()_ACTLR[QOS] is not applicable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsacr_s cn; */
} bdk_smmux_nsacr_t;

static inline uint64_t BDK_SMMUX_NSACR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSACR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000410ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000410ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000410ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSACR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSACR(a) bdk_smmux_nsacr_t
#define bustype_BDK_SMMUX_NSACR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSACR(a) "SMMUX_NSACR"
#define busnum_BDK_SMMUX_NSACR(a) (a)
#define arguments_BDK_SMMUX_NSACR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nscr0
 *
 * SMMU Secure Alias for Configuration Register 0
 * Provides secure alias for non-secure register SMMU()_(S)CR0.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nscr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vmid16en              : 1;  /**< [ 31: 31](R/W) Handling of 16-bit VMID extension:
                                                                 0 = 8-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBAR()[VMID].
                                                                 The SMMU()_CBA2R()[VMID16] field is RAZ.

                                                                 1 = 16-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBA2R()[VMID16].
                                                                 The SMMU()_CBAR()[VMID] field is RAZ.

                                                                 Only exists in the non-secure copy of this register.

                                                                 In pass 1, this field must be 0. */
        uint32_t hypmode               : 1;  /**< [ 30: 30](R/W) Hypervisor mode. Selects which hypervisor context is used:
                                                                   0 = When SMMU()_CBAR()[TYPE] = 0x1, SMMU()_CBAR()<10> represents HYPC.
                                                                   1 = When SMMU()_CBARn()[TYPE] = 0x1, SMMU()_CBAR()<10> represents E2HC.

                                                                 If this bit is changed, TLB maintenance is required.

                                                                 Only exists in the non secure copy of this register. */
        uint32_t nscfg                 : 2;  /**< [ 29: 28](SR/W) Non-secure configuration. Only exist in secure copy of register, RES0 in non-secure copy.
                                                                 This field only applies to secure transactions bypassing the SMMU stream mapping
                                                                 process.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure. */
        uint32_t wacfg                 : 2;  /**< [ 27: 26](RO) Write-allocate configuration, controls the allocation hint for write accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 25: 24](RO) Read-allocate configuration, controls the allocation hint for read accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t shcfg                 : 2;  /**< [ 23: 22](RO) Shared configuration. Applies to transactions that bypass the stream mapping table.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
        uint32_t smcfcfg               : 1;  /**< [ 21: 21](RO) Stream match conflict fault configuration. Controls transactions with multiple matches in
                                                                 the stream mapping table.
                                                                 0 = Permit the transaction to bypass the SMMU.
                                                                 1 = Raise a stream match conflict fault.

                                                                 CNXXXX detects all stream match conflicts and always faults. */
        uint32_t mtcfg                 : 1;  /**< [ 20: 20](R/W) Memory type configuration, applies to transactions that bypass the stream mapping table.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes. */
        uint32_t memattr               : 4;  /**< [ 19: 16](R/W) Memory attributes for bypass transactions if MTCFG == 1. */
        uint32_t bsu                   : 2;  /**< [ 15: 14](RO) Barrier sharability upgrade. Upgrades the sharability of barriers issued by client devices
                                                                 that are not mapped to a translation context bank by setting the minimum sharability
                                                                 domain applied to any barrier.  Applies to transactions bypassing the stream mapping
                                                                 table.
                                                                 00 = No effect.
                                                                 01 = Inner sharable.
                                                                 10 = Outer sharable.
                                                                 11 = Full system.

                                                                 Ignored in CNXXXX. */
        uint32_t fb                    : 1;  /**< [ 13: 13](R/W) Force broadcast of TLB and instruction cache maintenance operations. Applies to
                                                                 transactions bypassing the stream mapping table. Affects client TLB maintenance, BPIALL
                                                                 and ICIALLU operations. If FB=1, any affected operation is modified to the equivalent
                                                                 broadcast variant in the inner shareable domain.
                                                                 0 = Process affected operations as presented.
                                                                 1 = Upgrade affected operations to be broadcast within the inner sharable domain.

                                                                 Ignored in CNXXXX, as NCB clients do not initiate invalidates. */
        uint32_t ptm                   : 1;  /**< [ 12: 12](R/W) Private TLB maintenance hint.
                                                                 0 = Process affected operations as presented.
                                                                 1 = SMMU TLBs are privately managed and are not require to respond to broadcast TLB
                                                                 maintenance operations from the wider system.

                                                                 CNXXXX honors this hint, but both the secure and non-secure version must be set for
                                                                 private management. INTERNAL: Note when set SMMU always still sends a response for the
                                                                 invalidates, it just does not perform the invalidation action against the TLB/WCU. */
        uint32_t vmidpne               : 1;  /**< [ 11: 11](RO) Reserved. */
        uint32_t usfcfg                : 1;  /**< [ 10: 10](R/W) Unidentified stream fault configuration.
                                                                 0 = Permit any transaction that does not match any entries in the stream matching table to
                                                                 pass through.
                                                                 1 = Raise an unidentified stream fault on any transaction that does not match any stream
                                                                 matching table entry. */
        uint32_t gse                   : 1;  /**< [  9:  9](RO) Global stall enable.
                                                                 0 = Do not enforce global stalling across contexts.
                                                                 1 = Enforce global stalling across contexts.

                                                                 In CNXXXX always 0, no stalling. */
        uint32_t stalld                : 1;  /**< [  8:  8](RO) Stall disable.
                                                                 0 = Permit per-context stalling on context faults.
                                                                 1 = Disable per-context stalling on context faults, or not programmable.

                                                                 In CNXXXX always 1, no stalling. */
        uint32_t transientcfg          : 2;  /**< [  7:  6](RO) Transient configuration controls the transient allocation hint.
                                                                 00 = Default transient allocation attributes.
                                                                 01 = Reserved.
                                                                 10 = Non-transient.
                                                                 11 = Transient.

                                                                 Not implemented in CNXXXX. */
        uint32_t gcfgfie               : 1;  /**< [  5:  5](RO) Global configuration fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global configuration fault.
                                                                 1 = Raise an interrupt on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t gcfgfre               : 1;  /**< [  4:  4](RO) Global configuration fault report enable.
                                                                 0 = Do not return an abort on a global configuration fault
                                                                 1 = Return an abort on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t exidenable            : 1;  /**< [  3:  3](R/W) Extended stream ID enable.
                                                                 0 = For this SSD, SMMU()_SMR() has the format with the VALID bit in the
                                                                 SMMU()_SMR(). The SMMU()_S2CR()[EXIDVALID] is ignored.
                                                                 1 = For this SSD, SMMU()_SMR() has the extended id format and the valid bit is
                                                                 held in the corresponding SMMU()_S2CR()[EXIDVALID].

                                                                 Software should only change [EXIDENABLE] when all SMMU()_S2CR().[EXIDVALID] == 0
                                                                 and SMMU()_SMR().[EXMASK[15]/VALID] == 0 for the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use. */
        uint32_t gfie                  : 1;  /**< [  2:  2](R/W) Global fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global fault.
                                                                 1 = Raise an interrupt on a global fault. */
        uint32_t gfre                  : 1;  /**< [  1:  1](R/W) Global fault report enable.
                                                                 0 = Do not return an abort on a global fault.
                                                                 1 = Return an abort on a global fault. */
        uint32_t clientpd              : 1;  /**< [  0:  0](R/W) Client port disable.
                                                                 0 = Each SMMU client access is subject to translation, access control and attribute
                                                                 generation.
                                                                 1 = Each SMMU client access bypasses translation, access control and attribute generation. */
#else /* Word 0 - Little Endian */
        uint32_t clientpd              : 1;  /**< [  0:  0](R/W) Client port disable.
                                                                 0 = Each SMMU client access is subject to translation, access control and attribute
                                                                 generation.
                                                                 1 = Each SMMU client access bypasses translation, access control and attribute generation. */
        uint32_t gfre                  : 1;  /**< [  1:  1](R/W) Global fault report enable.
                                                                 0 = Do not return an abort on a global fault.
                                                                 1 = Return an abort on a global fault. */
        uint32_t gfie                  : 1;  /**< [  2:  2](R/W) Global fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global fault.
                                                                 1 = Raise an interrupt on a global fault. */
        uint32_t exidenable            : 1;  /**< [  3:  3](R/W) Extended stream ID enable.
                                                                 0 = For this SSD, SMMU()_SMR() has the format with the VALID bit in the
                                                                 SMMU()_SMR(). The SMMU()_S2CR()[EXIDVALID] is ignored.
                                                                 1 = For this SSD, SMMU()_SMR() has the extended id format and the valid bit is
                                                                 held in the corresponding SMMU()_S2CR()[EXIDVALID].

                                                                 Software should only change [EXIDENABLE] when all SMMU()_S2CR().[EXIDVALID] == 0
                                                                 and SMMU()_SMR().[EXMASK[15]/VALID] == 0 for the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use. */
        uint32_t gcfgfre               : 1;  /**< [  4:  4](RO) Global configuration fault report enable.
                                                                 0 = Do not return an abort on a global configuration fault
                                                                 1 = Return an abort on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t gcfgfie               : 1;  /**< [  5:  5](RO) Global configuration fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global configuration fault.
                                                                 1 = Raise an interrupt on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t transientcfg          : 2;  /**< [  7:  6](RO) Transient configuration controls the transient allocation hint.
                                                                 00 = Default transient allocation attributes.
                                                                 01 = Reserved.
                                                                 10 = Non-transient.
                                                                 11 = Transient.

                                                                 Not implemented in CNXXXX. */
        uint32_t stalld                : 1;  /**< [  8:  8](RO) Stall disable.
                                                                 0 = Permit per-context stalling on context faults.
                                                                 1 = Disable per-context stalling on context faults, or not programmable.

                                                                 In CNXXXX always 1, no stalling. */
        uint32_t gse                   : 1;  /**< [  9:  9](RO) Global stall enable.
                                                                 0 = Do not enforce global stalling across contexts.
                                                                 1 = Enforce global stalling across contexts.

                                                                 In CNXXXX always 0, no stalling. */
        uint32_t usfcfg                : 1;  /**< [ 10: 10](R/W) Unidentified stream fault configuration.
                                                                 0 = Permit any transaction that does not match any entries in the stream matching table to
                                                                 pass through.
                                                                 1 = Raise an unidentified stream fault on any transaction that does not match any stream
                                                                 matching table entry. */
        uint32_t vmidpne               : 1;  /**< [ 11: 11](RO) Reserved. */
        uint32_t ptm                   : 1;  /**< [ 12: 12](R/W) Private TLB maintenance hint.
                                                                 0 = Process affected operations as presented.
                                                                 1 = SMMU TLBs are privately managed and are not require to respond to broadcast TLB
                                                                 maintenance operations from the wider system.

                                                                 CNXXXX honors this hint, but both the secure and non-secure version must be set for
                                                                 private management. INTERNAL: Note when set SMMU always still sends a response for the
                                                                 invalidates, it just does not perform the invalidation action against the TLB/WCU. */
        uint32_t fb                    : 1;  /**< [ 13: 13](R/W) Force broadcast of TLB and instruction cache maintenance operations. Applies to
                                                                 transactions bypassing the stream mapping table. Affects client TLB maintenance, BPIALL
                                                                 and ICIALLU operations. If FB=1, any affected operation is modified to the equivalent
                                                                 broadcast variant in the inner shareable domain.
                                                                 0 = Process affected operations as presented.
                                                                 1 = Upgrade affected operations to be broadcast within the inner sharable domain.

                                                                 Ignored in CNXXXX, as NCB clients do not initiate invalidates. */
        uint32_t bsu                   : 2;  /**< [ 15: 14](RO) Barrier sharability upgrade. Upgrades the sharability of barriers issued by client devices
                                                                 that are not mapped to a translation context bank by setting the minimum sharability
                                                                 domain applied to any barrier.  Applies to transactions bypassing the stream mapping
                                                                 table.
                                                                 00 = No effect.
                                                                 01 = Inner sharable.
                                                                 10 = Outer sharable.
                                                                 11 = Full system.

                                                                 Ignored in CNXXXX. */
        uint32_t memattr               : 4;  /**< [ 19: 16](R/W) Memory attributes for bypass transactions if MTCFG == 1. */
        uint32_t mtcfg                 : 1;  /**< [ 20: 20](R/W) Memory type configuration, applies to transactions that bypass the stream mapping table.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes. */
        uint32_t smcfcfg               : 1;  /**< [ 21: 21](RO) Stream match conflict fault configuration. Controls transactions with multiple matches in
                                                                 the stream mapping table.
                                                                 0 = Permit the transaction to bypass the SMMU.
                                                                 1 = Raise a stream match conflict fault.

                                                                 CNXXXX detects all stream match conflicts and always faults. */
        uint32_t shcfg                 : 2;  /**< [ 23: 22](RO) Shared configuration. Applies to transactions that bypass the stream mapping table.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 25: 24](RO) Read-allocate configuration, controls the allocation hint for read accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t wacfg                 : 2;  /**< [ 27: 26](RO) Write-allocate configuration, controls the allocation hint for write accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t nscfg                 : 2;  /**< [ 29: 28](SR/W) Non-secure configuration. Only exist in secure copy of register, RES0 in non-secure copy.
                                                                 This field only applies to secure transactions bypassing the SMMU stream mapping
                                                                 process.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure. */
        uint32_t hypmode               : 1;  /**< [ 30: 30](R/W) Hypervisor mode. Selects which hypervisor context is used:
                                                                   0 = When SMMU()_CBAR()[TYPE] = 0x1, SMMU()_CBAR()<10> represents HYPC.
                                                                   1 = When SMMU()_CBARn()[TYPE] = 0x1, SMMU()_CBAR()<10> represents E2HC.

                                                                 If this bit is changed, TLB maintenance is required.

                                                                 Only exists in the non secure copy of this register. */
        uint32_t vmid16en              : 1;  /**< [ 31: 31](R/W) Handling of 16-bit VMID extension:
                                                                 0 = 8-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBAR()[VMID].
                                                                 The SMMU()_CBA2R()[VMID16] field is RAZ.

                                                                 1 = 16-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBA2R()[VMID16].
                                                                 The SMMU()_CBAR()[VMID] field is RAZ.

                                                                 Only exists in the non-secure copy of this register.

                                                                 In pass 1, this field must be 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nscr0_s cn; */
} bdk_smmux_nscr0_t;

static inline uint64_t BDK_SMMUX_NSCR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSCR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000400ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000400ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000400ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSCR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSCR0(a) bdk_smmux_nscr0_t
#define bustype_BDK_SMMUX_NSCR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSCR0(a) "SMMUX_NSCR0"
#define busnum_BDK_SMMUX_NSCR0(a) (a)
#define arguments_BDK_SMMUX_NSCR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nscr2
 *
 * SMMU Secure Alias for Configuration Register 2
 * Provides secure alias for non-secure register SMMU()_(S)CR2.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nscr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t exsmrgenable          : 1;  /**< [ 31: 31](RO) Enables extended stream matching extension.
                                                                 In CNXXXX, extended stream matching is not implemented. */
        uint32_t exnssmrgdisable       : 1;  /**< [ 30: 30](SRO) Disables use of extended stream match register groups by non-secure software.
                                                                 Only exists in the secure copy of this register.

                                                                 In CNXXXX, extended stream matching is not implemented. */
        uint32_t compindexenable       : 1;  /**< [ 29: 29](RO) StreamID compressed index match enable.

                                                                 In CNXXXX, StreamID compressed indexing is not implemented. */
        uint32_t reserved_16_28        : 13;
        uint32_t bpvmid                : 16; /**< [ 15:  0](RAZ) Bypass VMID. VMID field applied to client transactions that bypass the SMMU. In CNXXXX,
                                                                 not supported. INTERNAL: If L2C adds support for QoS on a per VMID basis the L2C will also
                                                                 have a `secure' QoS setting, so this field should remain not required. */
#else /* Word 0 - Little Endian */
        uint32_t bpvmid                : 16; /**< [ 15:  0](RAZ) Bypass VMID. VMID field applied to client transactions that bypass the SMMU. In CNXXXX,
                                                                 not supported. INTERNAL: If L2C adds support for QoS on a per VMID basis the L2C will also
                                                                 have a `secure' QoS setting, so this field should remain not required. */
        uint32_t reserved_16_28        : 13;
        uint32_t compindexenable       : 1;  /**< [ 29: 29](RO) StreamID compressed index match enable.

                                                                 In CNXXXX, StreamID compressed indexing is not implemented. */
        uint32_t exnssmrgdisable       : 1;  /**< [ 30: 30](SRO) Disables use of extended stream match register groups by non-secure software.
                                                                 Only exists in the secure copy of this register.

                                                                 In CNXXXX, extended stream matching is not implemented. */
        uint32_t exsmrgenable          : 1;  /**< [ 31: 31](RO) Enables extended stream matching extension.
                                                                 In CNXXXX, extended stream matching is not implemented. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nscr2_s cn; */
} bdk_smmux_nscr2_t;

static inline uint64_t BDK_SMMUX_NSCR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSCR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000408ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000408ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000408ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSCR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSCR2(a) bdk_smmux_nscr2_t
#define bustype_BDK_SMMUX_NSCR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSCR2(a) "SMMUX_NSCR2"
#define busnum_BDK_SMMUX_NSCR2(a) (a)
#define arguments_BDK_SMMUX_NSCR2(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_nsgfar
 *
 * SMMU Secure Alias for Global Fault Address Register
 * Provides secure alias for non-secure register SMMU()_(S)GFAR.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_nsgfar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t faddr                 : 49; /**< [ 48:  0](R/W/H) Fault address, the input IOVA of the faulty access. For configuration access faults,
                                                                 this is the physical address resulting in the fault. For other fault classes it is the
                                                                 input address of the faulting access, which the system can interpret in a number of ways.
                                                                 This register is updated before a valid context has been determined. Hence, no sign
                                                                 extension can have been performed.

                                                                 For CNXXXX <11:0> are always zero. */
#else /* Word 0 - Little Endian */
        uint64_t faddr                 : 49; /**< [ 48:  0](R/W/H) Fault address, the input IOVA of the faulty access. For configuration access faults,
                                                                 this is the physical address resulting in the fault. For other fault classes it is the
                                                                 input address of the faulting access, which the system can interpret in a number of ways.
                                                                 This register is updated before a valid context has been determined. Hence, no sign
                                                                 extension can have been performed.

                                                                 For CNXXXX <11:0> are always zero. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsgfar_s cn; */
} bdk_smmux_nsgfar_t;

static inline uint64_t BDK_SMMUX_NSGFAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFAR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000440ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000440ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000440ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSGFAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSGFAR(a) bdk_smmux_nsgfar_t
#define bustype_BDK_SMMUX_NSGFAR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_NSGFAR(a) "SMMUX_NSGFAR"
#define busnum_BDK_SMMUX_NSGFAR(a) (a)
#define arguments_BDK_SMMUX_NSGFAR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nsgfsr
 *
 * SMMU Secure Alias for Global Fault Status Register
 * Provides secure alias for non-secure register SMMU()_(S)GFSR.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nsgfsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t multi                 : 1;  /**< [ 31: 31](R/W1C/H) Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in this register was nonzero. */
        uint32_t reserved_9_30         : 22;
        uint32_t uut                   : 1;  /**< [  8:  8](R/W1C/H) Unsupported upstream transaction.
                                                                 0 = No unsupported upstream transaction fault.
                                                                 1 = Unsupported upstream transaction fault caused by receipt of an unsupported client
                                                                 transaction from an upstream device. */
        uint32_t pf                    : 1;  /**< [  7:  7](R/W1C/H) Permission fault. In SMMU_GFSR, this field is reserved. In SMMU_SGFSR, this field records
                                                                 global SMMU()_SCR1[SIF] faults.
                                                                 Note if a transaction is associated with a particular translation context bank, faults are
                                                                 recorded in SMMU()_CB()_FSR instead of SMMU_SGFSR. */
        uint32_t ef                    : 1;  /**< [  6:  6](R/W1C/H) External fault. */
        uint32_t caf                   : 1;  /**< [  5:  5](RO) Configuration access fault.
                                                                 For CNXXXX always zero, no configuration faults. */
        uint32_t ucif                  : 1;  /**< [  4:  4](R/W1C/H) Unimplemented context interrupt fault. */
        uint32_t ucbf                  : 1;  /**< [  3:  3](R/W1C/H) Unimplemented context bank fault. */
        uint32_t smcf                  : 1;  /**< [  2:  2](R/W1C/H) Stream match conflict fault. */
        uint32_t usf                   : 1;  /**< [  1:  1](R/W1C/H) Unidentified stream fault. */
        uint32_t icf                   : 1;  /**< [  0:  0](R/W1C/H) Invalid context fault. */
#else /* Word 0 - Little Endian */
        uint32_t icf                   : 1;  /**< [  0:  0](R/W1C/H) Invalid context fault. */
        uint32_t usf                   : 1;  /**< [  1:  1](R/W1C/H) Unidentified stream fault. */
        uint32_t smcf                  : 1;  /**< [  2:  2](R/W1C/H) Stream match conflict fault. */
        uint32_t ucbf                  : 1;  /**< [  3:  3](R/W1C/H) Unimplemented context bank fault. */
        uint32_t ucif                  : 1;  /**< [  4:  4](R/W1C/H) Unimplemented context interrupt fault. */
        uint32_t caf                   : 1;  /**< [  5:  5](RO) Configuration access fault.
                                                                 For CNXXXX always zero, no configuration faults. */
        uint32_t ef                    : 1;  /**< [  6:  6](R/W1C/H) External fault. */
        uint32_t pf                    : 1;  /**< [  7:  7](R/W1C/H) Permission fault. In SMMU_GFSR, this field is reserved. In SMMU_SGFSR, this field records
                                                                 global SMMU()_SCR1[SIF] faults.
                                                                 Note if a transaction is associated with a particular translation context bank, faults are
                                                                 recorded in SMMU()_CB()_FSR instead of SMMU_SGFSR. */
        uint32_t uut                   : 1;  /**< [  8:  8](R/W1C/H) Unsupported upstream transaction.
                                                                 0 = No unsupported upstream transaction fault.
                                                                 1 = Unsupported upstream transaction fault caused by receipt of an unsupported client
                                                                 transaction from an upstream device. */
        uint32_t reserved_9_30         : 22;
        uint32_t multi                 : 1;  /**< [ 31: 31](R/W1C/H) Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in this register was nonzero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsgfsr_s cn; */
} bdk_smmux_nsgfsr_t;

static inline uint64_t BDK_SMMUX_NSGFSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000448ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000448ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000448ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSGFSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSGFSR(a) bdk_smmux_nsgfsr_t
#define bustype_BDK_SMMUX_NSGFSR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSGFSR(a) "SMMUX_NSGFSR"
#define busnum_BDK_SMMUX_NSGFSR(a) (a)
#define arguments_BDK_SMMUX_NSGFSR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nsgfsrrestore
 *
 * SMMU Secure Alias for Global Fault Status Restore Register
 * Provides secure alias for non-secure register SMMU()_(S)GFSRRESTORE.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nsgfsrrestore_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t restore               : 32; /**< [ 31:  0](WO) Writes bits in corresponding SMMU()_(S)GFSR. */
#else /* Word 0 - Little Endian */
        uint32_t restore               : 32; /**< [ 31:  0](WO) Writes bits in corresponding SMMU()_(S)GFSR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsgfsrrestore_s cn; */
} bdk_smmux_nsgfsrrestore_t;

static inline uint64_t BDK_SMMUX_NSGFSRRESTORE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSRRESTORE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x83000000044cll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x83000000044cll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x83000000044cll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSGFSRRESTORE", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSGFSRRESTORE(a) bdk_smmux_nsgfsrrestore_t
#define bustype_BDK_SMMUX_NSGFSRRESTORE(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSGFSRRESTORE(a) "SMMUX_NSGFSRRESTORE"
#define busnum_BDK_SMMUX_NSGFSRRESTORE(a) (a)
#define arguments_BDK_SMMUX_NSGFSRRESTORE(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nsgfsynr0
 *
 * SMMU Secure Alias for Global Fault Syndrome Register 0
 * Provides secure alias for non-secure register SMMU()_(S)GFSYNR0.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nsgfsynr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t imp                   : 8;  /**< [ 15:  8](RO) Reserved for implementation. */
        uint32_t reserved_7            : 1;
        uint32_t ats                   : 1;  /**< [  6:  6](RO) Address translation operation fault. For CNXXXX zero, SMMU()_IDR0[ATOSNS] not supported. */
        uint32_t nsattr                : 1;  /**< [  5:  5](R/W/H) Non-secure attribute.
                                                                 0 = The faulty transaction has the secure attribute.
                                                                 1 = The faulty transaction has the non-secure attribute. */
        uint32_t nsstate               : 1;  /**< [  4:  4](SR/W/H) Non-secure state.
                                                                 0 = The faulty transaction is associated with a secure device.
                                                                 1 = The faulty transaction is associated with a non-secure device.

                                                                 This field is only valid for the secure state.

                                                                 This field may read 1 in the event that a fault is encountered in relation to a
                                                                 non-secure client device and where SMMU()_SCR1[GEFRO]=1. */
        uint32_t ind                   : 1;  /**< [  3:  3](R/W/H) Instruction not data.
                                                                 0 = The faulty transaction has the data access attribute.
                                                                 1 = The faulty transaction has the instruction access attribute. */
        uint32_t pnu                   : 1;  /**< [  2:  2](R/W/H) Privileged not unprivileged.
                                                                 0 = The faulty transaction has the unprivileged attribute.
                                                                 1 = The faulty transaction has the privileged attribute. */
        uint32_t wnr                   : 1;  /**< [  1:  1](R/W/H) Write not read.
                                                                 0 = The faulty transaction is a read.
                                                                 1 = The faulty transaction is a write. */
        uint32_t nested                : 1;  /**< [  0:  0](R/W/H) Nested fault.
                                                                 0 = The fault occurred in the initial stream context.
                                                                 1 = The fault occurred in a nested context.

                                                                 This bit is reserved in SMMU_SGFSYNR0. */
#else /* Word 0 - Little Endian */
        uint32_t nested                : 1;  /**< [  0:  0](R/W/H) Nested fault.
                                                                 0 = The fault occurred in the initial stream context.
                                                                 1 = The fault occurred in a nested context.

                                                                 This bit is reserved in SMMU_SGFSYNR0. */
        uint32_t wnr                   : 1;  /**< [  1:  1](R/W/H) Write not read.
                                                                 0 = The faulty transaction is a read.
                                                                 1 = The faulty transaction is a write. */
        uint32_t pnu                   : 1;  /**< [  2:  2](R/W/H) Privileged not unprivileged.
                                                                 0 = The faulty transaction has the unprivileged attribute.
                                                                 1 = The faulty transaction has the privileged attribute. */
        uint32_t ind                   : 1;  /**< [  3:  3](R/W/H) Instruction not data.
                                                                 0 = The faulty transaction has the data access attribute.
                                                                 1 = The faulty transaction has the instruction access attribute. */
        uint32_t nsstate               : 1;  /**< [  4:  4](SR/W/H) Non-secure state.
                                                                 0 = The faulty transaction is associated with a secure device.
                                                                 1 = The faulty transaction is associated with a non-secure device.

                                                                 This field is only valid for the secure state.

                                                                 This field may read 1 in the event that a fault is encountered in relation to a
                                                                 non-secure client device and where SMMU()_SCR1[GEFRO]=1. */
        uint32_t nsattr                : 1;  /**< [  5:  5](R/W/H) Non-secure attribute.
                                                                 0 = The faulty transaction has the secure attribute.
                                                                 1 = The faulty transaction has the non-secure attribute. */
        uint32_t ats                   : 1;  /**< [  6:  6](RO) Address translation operation fault. For CNXXXX zero, SMMU()_IDR0[ATOSNS] not supported. */
        uint32_t reserved_7            : 1;
        uint32_t imp                   : 8;  /**< [ 15:  8](RO) Reserved for implementation. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsgfsynr0_s cn; */
} bdk_smmux_nsgfsynr0_t;

static inline uint64_t BDK_SMMUX_NSGFSYNR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSYNR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000450ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000450ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000450ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSGFSYNR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSGFSYNR0(a) bdk_smmux_nsgfsynr0_t
#define bustype_BDK_SMMUX_NSGFSYNR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSGFSYNR0(a) "SMMUX_NSGFSYNR0"
#define busnum_BDK_SMMUX_NSGFSYNR0(a) (a)
#define arguments_BDK_SMMUX_NSGFSYNR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nsgfsynr1
 *
 * SMMU Secure Alias for Global Fault Syndrome Register 1
 * Provides secure alias for non-secure register SMMU()_(S)GFSYNR1.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nsgfsynr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssd_index             : 16; /**< [ 31: 16](SRO/H) The SSD_Index of the transaction that caused the fault. The SSD_Index field is only
                                                                 accessible to configuration accesses by secure software. Non-secure configuration accesses
                                                                 treat this field as RAZ/WI.

                                                                 For CNXXXX, the SSD_INDEX is always the same as [STREAMID]. */
        uint32_t streamid              : 16; /**< [ 15:  0](R/W/H) The stream ID of the transaction that caused the fault. */
#else /* Word 0 - Little Endian */
        uint32_t streamid              : 16; /**< [ 15:  0](R/W/H) The stream ID of the transaction that caused the fault. */
        uint32_t ssd_index             : 16; /**< [ 31: 16](SRO/H) The SSD_Index of the transaction that caused the fault. The SSD_Index field is only
                                                                 accessible to configuration accesses by secure software. Non-secure configuration accesses
                                                                 treat this field as RAZ/WI.

                                                                 For CNXXXX, the SSD_INDEX is always the same as [STREAMID]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsgfsynr1_s cn; */
} bdk_smmux_nsgfsynr1_t;

static inline uint64_t BDK_SMMUX_NSGFSYNR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSYNR1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000454ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000454ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000454ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSGFSYNR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSGFSYNR1(a) bdk_smmux_nsgfsynr1_t
#define bustype_BDK_SMMUX_NSGFSYNR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSGFSYNR1(a) "SMMUX_NSGFSYNR1"
#define busnum_BDK_SMMUX_NSGFSYNR1(a) (a)
#define arguments_BDK_SMMUX_NSGFSYNR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nsgfsynr2
 *
 * SMMU Secure Alias for Global Fault Syndrome Register 2
 * Provides secure alias for non-secure register SMMU()_(S)GFSYNR2.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nsgfsynr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsgfsynr2_s cn; */
} bdk_smmux_nsgfsynr2_t;

static inline uint64_t BDK_SMMUX_NSGFSYNR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSYNR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000458ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000458ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000458ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSGFSYNR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSGFSYNR2(a) bdk_smmux_nsgfsynr2_t
#define bustype_BDK_SMMUX_NSGFSYNR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSGFSYNR2(a) "SMMUX_NSGFSYNR2"
#define busnum_BDK_SMMUX_NSGFSYNR2(a) (a)
#define arguments_BDK_SMMUX_NSGFSYNR2(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_nsmiss_perf
 *
 * SMMU Non-secure Misses Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_nsmiss_perf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Counts the number of lookup requests in non-secure mode which missed the IOTLB.
                                                                 Also includes sign-extension position translation faults. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Counts the number of lookup requests in non-secure mode which missed the IOTLB.
                                                                 Also includes sign-extension position translation faults. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsmiss_perf_s cn; */
} bdk_smmux_nsmiss_perf_t;

static inline uint64_t BDK_SMMUX_NSMISS_PERF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSMISS_PERF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021030ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021030ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021030ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSMISS_PERF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSMISS_PERF(a) bdk_smmux_nsmiss_perf_t
#define bustype_BDK_SMMUX_NSMISS_PERF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_NSMISS_PERF(a) "SMMUX_NSMISS_PERF"
#define busnum_BDK_SMMUX_NSMISS_PERF(a) (a)
#define arguments_BDK_SMMUX_NSMISS_PERF(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_nsptread_perf
 *
 * SMMU Non-secure Page Table Reads Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_nsptread_perf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Counts the number of page table reads issued to non-secure memory. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Counts the number of page table reads issued to non-secure memory. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nsptread_perf_s cn; */
} bdk_smmux_nsptread_perf_t;

static inline uint64_t BDK_SMMUX_NSPTREAD_PERF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSPTREAD_PERF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021050ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021050ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021050ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSPTREAD_PERF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSPTREAD_PERF(a) bdk_smmux_nsptread_perf_t
#define bustype_BDK_SMMUX_NSPTREAD_PERF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_NSPTREAD_PERF(a) "SMMUX_NSPTREAD_PERF"
#define busnum_BDK_SMMUX_NSPTREAD_PERF(a) (a)
#define arguments_BDK_SMMUX_NSPTREAD_PERF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nstlbgstatus
 *
 * SMMU Non-Secure Alias Global Synchronize TLB Status Register
 * Gives the status of a TLB maintenance operation.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nstlbgstatus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t gsactive              : 1;  /**< [  0:  0](RO/H) Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
#else /* Word 0 - Little Endian */
        uint32_t gsactive              : 1;  /**< [  0:  0](RO/H) Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nstlbgstatus_s cn; */
} bdk_smmux_nstlbgstatus_t;

static inline uint64_t BDK_SMMUX_NSTLBGSTATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSTLBGSTATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000474ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000474ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000474ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSTLBGSTATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSTLBGSTATUS(a) bdk_smmux_nstlbgstatus_t
#define bustype_BDK_SMMUX_NSTLBGSTATUS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSTLBGSTATUS(a) "SMMUX_NSTLBGSTATUS"
#define busnum_BDK_SMMUX_NSTLBGSTATUS(a) (a)
#define arguments_BDK_SMMUX_NSTLBGSTATUS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_nstlbgsync
 *
 * SMMU Non-Secure Alias Global Synchronize TLB Invalidate Register
 * Starts a global synchronization operation that ensures the completion of any previously
 * accepted TLB invalidate operation.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_nstlbgsync_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_nstlbgsync_s cn; */
} bdk_smmux_nstlbgsync_t;

static inline uint64_t BDK_SMMUX_NSTLBGSYNC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSTLBGSYNC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000470ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000470ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000470ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_NSTLBGSYNC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_NSTLBGSYNC(a) bdk_smmux_nstlbgsync_t
#define bustype_BDK_SMMUX_NSTLBGSYNC(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_NSTLBGSYNC(a) "SMMUX_NSTLBGSYNC"
#define busnum_BDK_SMMUX_NSTLBGSYNC(a) (a)
#define arguments_BDK_SMMUX_NSTLBGSYNC(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr0
 *
 * SMMU Component Identification Register 0
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::SMMU. */
#else /* Word 0 - Little Endian */
        uint32_t partnum0              : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::SMMU. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_pidr0_s cn; */
} bdk_smmux_pidr0_t;

static inline uint64_t BDK_SMMUX_PIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fe0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fe0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fe0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR0(a) bdk_smmux_pidr0_t
#define bustype_BDK_SMMUX_PIDR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR0(a) "SMMUX_PIDR0"
#define busnum_BDK_SMMUX_PIDR0(a) (a)
#define arguments_BDK_SMMUX_PIDR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr1
 *
 * SMMU Peripheral Identification Register 1
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr1_s
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
    /* struct bdk_smmux_pidr1_s cn; */
} bdk_smmux_pidr1_t;

static inline uint64_t BDK_SMMUX_PIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fe4ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fe4ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fe4ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR1(a) bdk_smmux_pidr1_t
#define bustype_BDK_SMMUX_PIDR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR1(a) "SMMUX_PIDR1"
#define busnum_BDK_SMMUX_PIDR1(a) (a)
#define arguments_BDK_SMMUX_PIDR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr2
 *
 * SMMU Peripheral Identification Register 2
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr2_s
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
    /* struct bdk_smmux_pidr2_s cn; */
} bdk_smmux_pidr2_t;

static inline uint64_t BDK_SMMUX_PIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fe8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fe8ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fe8ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR2(a) bdk_smmux_pidr2_t
#define bustype_BDK_SMMUX_PIDR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR2(a) "SMMUX_PIDR2"
#define busnum_BDK_SMMUX_PIDR2(a) (a)
#define arguments_BDK_SMMUX_PIDR2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr3
 *
 * SMMU Peripheral Identification Register 3
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr3_s
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
    /* struct bdk_smmux_pidr3_s cn; */
} bdk_smmux_pidr3_t;

static inline uint64_t BDK_SMMUX_PIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fecll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fecll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fecll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR3(a) bdk_smmux_pidr3_t
#define bustype_BDK_SMMUX_PIDR3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR3(a) "SMMUX_PIDR3"
#define busnum_BDK_SMMUX_PIDR3(a) (a)
#define arguments_BDK_SMMUX_PIDR3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr4
 *
 * SMMU Peripheral Identification Register 0
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t jepcont               : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. Indicates Cavium. */
        uint32_t pagecnt               : 4;  /**< [  7:  4](RO) Number of log-2 4 KB blocks occupied. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_pidr4_s cn; */
} bdk_smmux_pidr4_t;

static inline uint64_t BDK_SMMUX_PIDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fd0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fd0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fd0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR4", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR4(a) bdk_smmux_pidr4_t
#define bustype_BDK_SMMUX_PIDR4(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR4(a) "SMMUX_PIDR4"
#define busnum_BDK_SMMUX_PIDR4(a) (a)
#define arguments_BDK_SMMUX_PIDR4(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr5
 *
 * SMMU Peripheral Identification Register 5
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_pidr5_s cn; */
} bdk_smmux_pidr5_t;

static inline uint64_t BDK_SMMUX_PIDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR5(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fd4ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fd4ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fd4ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR5", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR5(a) bdk_smmux_pidr5_t
#define bustype_BDK_SMMUX_PIDR5(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR5(a) "SMMUX_PIDR5"
#define busnum_BDK_SMMUX_PIDR5(a) (a)
#define arguments_BDK_SMMUX_PIDR5(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr6
 *
 * SMMU Peripheral Identification Register 6
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_pidr6_s cn; */
} bdk_smmux_pidr6_t;

static inline uint64_t BDK_SMMUX_PIDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR6(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fd8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fd8ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fd8ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR6", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR6(a) bdk_smmux_pidr6_t
#define bustype_BDK_SMMUX_PIDR6(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR6(a) "SMMUX_PIDR6"
#define busnum_BDK_SMMUX_PIDR6(a) (a)
#define arguments_BDK_SMMUX_PIDR6(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_pidr7
 *
 * SMMU Peripheral Identification Register 7
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_pidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_pidr7_s cn; */
} bdk_smmux_pidr7_t;

static inline uint64_t BDK_SMMUX_PIDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR7(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000fdcll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000fdcll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000fdcll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_PIDR7", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_PIDR7(a) bdk_smmux_pidr7_t
#define bustype_BDK_SMMUX_PIDR7(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_PIDR7(a) "SMMUX_PIDR7"
#define busnum_BDK_SMMUX_PIDR7(a) (a)
#define arguments_BDK_SMMUX_PIDR7(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_s2cr#
 *
 * SMMU Stream to Context Register
 * Specifies the translation context for processing a transaction where the transaction matches
 * the stream mapping group to which this register belongs.
 * An SMMU()_S2CR() register reserved by secure software using
 * SMMU()_SCR1[NSNUMSMRGO] must only specify a translation context bank that is reserved by
 * secure software. An SMMU()_S2CR() register that is accessible from the non-secure
 * state must only specify a translation context bank that is not reserved by secure software
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_s2crx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t imp                   : 2;  /**< [ 31: 30](RAZ) Reserved. */
        uint32_t transientcfg          : 2;  /**< [ 29: 28](RO) For CTYPE=0 or 1, transient allocate configuration.

                                                                 0 = Use the default transient allocation attributes.
                                                                 1 = Reserved.
                                                                 2 = Non-transient.
                                                                 3 = Transient.

                                                                 For CTYPE=2, reserved.

                                                                 In CNXXXX this field is not implemented. */
        uint32_t instcfg_fb            : 2;  /**< [ 27: 26](RAZ) For CTYPE=0, <27:26> is INSTCFG, instruction fetch attribute configuration. This
                                                                 field does not apply to writes.
                                                                   0x0 = Default instruction fetch attribute.
                                                                   0x1 = Reserved.
                                                                   0x2 = Data.
                                                                   0x3 = Instruction.

                                                                 For CTYPE=1, <27> reserved, <26> is FB, force broadcast. Force broadcast of TLB and
                                                                 instruction cache maintenance operations. Ignored in CNXXXX, as NCB clients do not
                                                                 initiate invalidates.

                                                                 For CTYPE=2, reserved. */
        uint32_t privcfg_bsu           : 2;  /**< [ 25: 24](R/W) For CTYPE=0, PRIVCFG, privileged attribute configuration.

                                                                 0 = Default privilege attribute.

                                                                 1 = Privledged access never.  This encoding is reserved if SMMU()_IDR2[DIPANS] is
                                                                     clear.
                                                                     When a context bank is configured to use this encoding, then any transaction from
                                                                     the upstream device is considered to be marked as privileged and any attempt to access
                                                                     a user-accessible page will result in a permission fault.  Thus a device that is
                                                                     expected to operate only on privileged data will fault if it is misprogrammed and
                                                                     tries to access user data accessible through the corresponding context bank.
                                                                     For SMMU()_S2CR() that are configured as bypass, then there is no associated
                                                                     context bank and no permission checks.
                                                                     Thus the only effect of this bit is to mark the downstream transaction as privileged;
                                                                     it behaves identically to encoding 0x3, "Privileged".
                                                                     For E2HC banks then there are two levels of privilege and this encoding behaves as
                                                                     normal.

                                                                 2 = Unprivileged.

                                                                 3 = Privileged.

                                                                 For CTYPE=1, BSU, barrier shareability upgrade. Ignored in CNXXXX.

                                                                 For CTYPE=2, reserved. */
        uint32_t wacfg                 : 2;  /**< [ 23: 22](RO) For CTYPE=0 or 1, write allocate configuration.

                                                                 0 = Default allocation attribute.
                                                                 1 = Reserved.
                                                                 2 = Write-allocate.
                                                                 3 = No write-allocate.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
        uint32_t racfg                 : 2;  /**< [ 21: 20](RO) For CTYPE=0 or 1, read allocate configuration.

                                                                 0 = Default allocation attribute.
                                                                 1 = Reserved.
                                                                 2 = Read-allocate.
                                                                 3 = No read-allocate.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
        uint32_t nscfg                 : 2;  /**< [ 19: 18](SR/W) For CTYPE=0 or 1, Non-secure configuration.

                                                                 0 = Default security attribute.
                                                                 1 = Reserved.
                                                                 2 = Secure configuration.
                                                                 3 = Non secure configuration.

                                                                 For CTYPE=2, reserved.

                                                                 This field exists only for secure stream mapping register groups. */
        uint32_t ctype                 : 2;  /**< [ 17: 16](R/W) Context register type. Indicates the meaning of the remaining fields in this register:
                                                                 0 = Translation context bank index.
                                                                 1 = Bypass mode.
                                                                 2 = Fault, no index.
                                                                 3 = Reserved. */
        uint32_t memattr               : 4;  /**< [ 15: 12](R/W) For CTYPE=0 or 1, memory attributes.

                                                                 For CTYPE=2, reserved. */
        uint32_t mtcfg                 : 1;  /**< [ 11: 11](R/W) For CTYPE=0 or 1, memory type configuration.

                                                                 0 = Default memory attributes.
                                                                 1 = [MEMATTR] field attributes.

                                                                 For CTYPE=2, reserved. */
        uint32_t exidvalid             : 1;  /**< [ 10: 10](R/W) Extended ID valid.
                                                                 0 = The stream match register group is valid if SMMU()_SMR()[VALID] is set and
                                                                 SMMU()_(S)CR0[EXIDENABLE] is clear, for backward compatibility.
                                                                 1 = The stream match register group is valid and SMMU()_SMR()[VALID] is used as
                                                                 an extra mask bit. CNXXXX recommends this setting. */
        uint32_t shcfg                 : 2;  /**< [  9:  8](RO) For CTYPE=0 or 1, Sharability configuration.
                                                                 0 = Default sharability attribute.
                                                                 1 = Outer sharable.
                                                                 2 = Inner sharable.
                                                                 3 = Non-sharable.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
        uint32_t cbndx                 : 8;  /**< [  7:  0](R/W) For CTYPE=0, Context bank index.

                                                                 For CTYPE=1, VMID, not implemented in CNXXXX.

                                                                 For CTYPE=2, reserved.

                                                                 A secure SMMU()_S2CR() register configured to specify a translation context bank
                                                                 is only permitted to specify a CBNDX corresponding to a translation context bank that is
                                                                 also reserved by secure software, or specify a translation context bank configured for the
                                                                 Stage 1 context with stage 2 bypass format. */
#else /* Word 0 - Little Endian */
        uint32_t cbndx                 : 8;  /**< [  7:  0](R/W) For CTYPE=0, Context bank index.

                                                                 For CTYPE=1, VMID, not implemented in CNXXXX.

                                                                 For CTYPE=2, reserved.

                                                                 A secure SMMU()_S2CR() register configured to specify a translation context bank
                                                                 is only permitted to specify a CBNDX corresponding to a translation context bank that is
                                                                 also reserved by secure software, or specify a translation context bank configured for the
                                                                 Stage 1 context with stage 2 bypass format. */
        uint32_t shcfg                 : 2;  /**< [  9:  8](RO) For CTYPE=0 or 1, Sharability configuration.
                                                                 0 = Default sharability attribute.
                                                                 1 = Outer sharable.
                                                                 2 = Inner sharable.
                                                                 3 = Non-sharable.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
        uint32_t exidvalid             : 1;  /**< [ 10: 10](R/W) Extended ID valid.
                                                                 0 = The stream match register group is valid if SMMU()_SMR()[VALID] is set and
                                                                 SMMU()_(S)CR0[EXIDENABLE] is clear, for backward compatibility.
                                                                 1 = The stream match register group is valid and SMMU()_SMR()[VALID] is used as
                                                                 an extra mask bit. CNXXXX recommends this setting. */
        uint32_t mtcfg                 : 1;  /**< [ 11: 11](R/W) For CTYPE=0 or 1, memory type configuration.

                                                                 0 = Default memory attributes.
                                                                 1 = [MEMATTR] field attributes.

                                                                 For CTYPE=2, reserved. */
        uint32_t memattr               : 4;  /**< [ 15: 12](R/W) For CTYPE=0 or 1, memory attributes.

                                                                 For CTYPE=2, reserved. */
        uint32_t ctype                 : 2;  /**< [ 17: 16](R/W) Context register type. Indicates the meaning of the remaining fields in this register:
                                                                 0 = Translation context bank index.
                                                                 1 = Bypass mode.
                                                                 2 = Fault, no index.
                                                                 3 = Reserved. */
        uint32_t nscfg                 : 2;  /**< [ 19: 18](SR/W) For CTYPE=0 or 1, Non-secure configuration.

                                                                 0 = Default security attribute.
                                                                 1 = Reserved.
                                                                 2 = Secure configuration.
                                                                 3 = Non secure configuration.

                                                                 For CTYPE=2, reserved.

                                                                 This field exists only for secure stream mapping register groups. */
        uint32_t racfg                 : 2;  /**< [ 21: 20](RO) For CTYPE=0 or 1, read allocate configuration.

                                                                 0 = Default allocation attribute.
                                                                 1 = Reserved.
                                                                 2 = Read-allocate.
                                                                 3 = No read-allocate.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
        uint32_t wacfg                 : 2;  /**< [ 23: 22](RO) For CTYPE=0 or 1, write allocate configuration.

                                                                 0 = Default allocation attribute.
                                                                 1 = Reserved.
                                                                 2 = Write-allocate.
                                                                 3 = No write-allocate.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
        uint32_t privcfg_bsu           : 2;  /**< [ 25: 24](R/W) For CTYPE=0, PRIVCFG, privileged attribute configuration.

                                                                 0 = Default privilege attribute.

                                                                 1 = Privledged access never.  This encoding is reserved if SMMU()_IDR2[DIPANS] is
                                                                     clear.
                                                                     When a context bank is configured to use this encoding, then any transaction from
                                                                     the upstream device is considered to be marked as privileged and any attempt to access
                                                                     a user-accessible page will result in a permission fault.  Thus a device that is
                                                                     expected to operate only on privileged data will fault if it is misprogrammed and
                                                                     tries to access user data accessible through the corresponding context bank.
                                                                     For SMMU()_S2CR() that are configured as bypass, then there is no associated
                                                                     context bank and no permission checks.
                                                                     Thus the only effect of this bit is to mark the downstream transaction as privileged;
                                                                     it behaves identically to encoding 0x3, "Privileged".
                                                                     For E2HC banks then there are two levels of privilege and this encoding behaves as
                                                                     normal.

                                                                 2 = Unprivileged.

                                                                 3 = Privileged.

                                                                 For CTYPE=1, BSU, barrier shareability upgrade. Ignored in CNXXXX.

                                                                 For CTYPE=2, reserved. */
        uint32_t instcfg_fb            : 2;  /**< [ 27: 26](RAZ) For CTYPE=0, <27:26> is INSTCFG, instruction fetch attribute configuration. This
                                                                 field does not apply to writes.
                                                                   0x0 = Default instruction fetch attribute.
                                                                   0x1 = Reserved.
                                                                   0x2 = Data.
                                                                   0x3 = Instruction.

                                                                 For CTYPE=1, <27> reserved, <26> is FB, force broadcast. Force broadcast of TLB and
                                                                 instruction cache maintenance operations. Ignored in CNXXXX, as NCB clients do not
                                                                 initiate invalidates.

                                                                 For CTYPE=2, reserved. */
        uint32_t transientcfg          : 2;  /**< [ 29: 28](RO) For CTYPE=0 or 1, transient allocate configuration.

                                                                 0 = Use the default transient allocation attributes.
                                                                 1 = Reserved.
                                                                 2 = Non-transient.
                                                                 3 = Transient.

                                                                 For CTYPE=2, reserved.

                                                                 In CNXXXX this field is not implemented. */
        uint32_t imp                   : 2;  /**< [ 31: 30](RAZ) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_s2crx_s cn; */
} bdk_smmux_s2crx_t;

static inline uint64_t BDK_SMMUX_S2CRX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_S2CRX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=127)))
        return 0x830000000c00ll + 0x1000000000ll * ((a) & 0x0) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830000000c00ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830000000c00ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_S2CRX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_S2CRX(a,b) bdk_smmux_s2crx_t
#define bustype_BDK_SMMUX_S2CRX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_S2CRX(a,b) "SMMUX_S2CRX"
#define busnum_BDK_SMMUX_S2CRX(a,b) (a)
#define arguments_BDK_SMMUX_S2CRX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_s_hit_perf
 *
 * SMMU Secure Hits Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_s_hit_perf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) Counts the number of hits in secure mode. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) Counts the number of hits in secure mode. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_s_hit_perf_s cn; */
} bdk_smmux_s_hit_perf_t;

static inline uint64_t BDK_SMMUX_S_HIT_PERF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_S_HIT_PERF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021020ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021020ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021020ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_S_HIT_PERF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_S_HIT_PERF(a) bdk_smmux_s_hit_perf_t
#define bustype_BDK_SMMUX_S_HIT_PERF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_S_HIT_PERF(a) "SMMUX_S_HIT_PERF"
#define busnum_BDK_SMMUX_S_HIT_PERF(a) (a)
#define arguments_BDK_SMMUX_S_HIT_PERF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_sacr
 *
 * SMMU (Secure) Auxiliary Control Register
 * This register contains implementation specific context fields.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_sacr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t qos                   : 4;  /**< [ 31: 28](R/W) L2C quality-of-service value to use for standard transactions that are not by a specific
                                                                 context, and so SMMU()_CB()_ACTLR[QOS] is not applicable. */
        uint32_t qos_walk              : 4;  /**< [ 27: 24](R/W) L2C quality-of-service value to use for page table walks. For optimal performance, this
                                                                 typically would be set to the most preferential QoS value of zero. */
        uint32_t reserved_0_23         : 24;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_23         : 24;
        uint32_t qos_walk              : 4;  /**< [ 27: 24](R/W) L2C quality-of-service value to use for page table walks. For optimal performance, this
                                                                 typically would be set to the most preferential QoS value of zero. */
        uint32_t qos                   : 4;  /**< [ 31: 28](R/W) L2C quality-of-service value to use for standard transactions that are not by a specific
                                                                 context, and so SMMU()_CB()_ACTLR[QOS] is not applicable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sacr_s cn; */
} bdk_smmux_sacr_t;

static inline uint64_t BDK_SMMUX_SACR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SACR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000010ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000010ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000010ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SACR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SACR(a) bdk_smmux_sacr_t
#define bustype_BDK_SMMUX_SACR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SACR(a) "SMMUX_SACR"
#define busnum_BDK_SMMUX_SACR(a) (a)
#define arguments_BDK_SMMUX_SACR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_scr0
 *
 * SMMU (Secure) Configuration Register 0
 * The non-secure version of this register does not provide full top-level control of the SMMU.
 * Some fields only apply to secure or non-secure transactions.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_scr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vmid16en              : 1;  /**< [ 31: 31](R/W) Handling of 16-bit VMID extension:
                                                                 0 = 8-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBAR()[VMID].
                                                                 The SMMU()_CBA2R()[VMID16] field is RAZ.

                                                                 1 = 16-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBA2R()[VMID16].
                                                                 The SMMU()_CBAR()[VMID] field is RAZ.

                                                                 Only exists in the non-secure copy of this register.

                                                                 In pass 1, this field must be 0. */
        uint32_t hypmode               : 1;  /**< [ 30: 30](R/W) Hypervisor mode. Selects which hypervisor context is used:
                                                                   0 = When SMMU()_CBAR()[TYPE] = 0x1, SMMU()_CBAR()<10> represents HYPC.
                                                                   1 = When SMMU()_CBARn()[TYPE] = 0x1, SMMU()_CBAR()<10> represents E2HC.

                                                                 If this bit is changed, TLB maintenance is required.

                                                                 Only exists in the non secure copy of this register. */
        uint32_t nscfg                 : 2;  /**< [ 29: 28](SR/W) Non-secure configuration. Only exist in secure copy of register, RES0 in non-secure copy.
                                                                 This field only applies to secure transactions bypassing the SMMU stream mapping
                                                                 process.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure. */
        uint32_t wacfg                 : 2;  /**< [ 27: 26](RO) Write-allocate configuration, controls the allocation hint for write accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 25: 24](RO) Read-allocate configuration, controls the allocation hint for read accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t shcfg                 : 2;  /**< [ 23: 22](RO) Shared configuration. Applies to transactions that bypass the stream mapping table.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
        uint32_t smcfcfg               : 1;  /**< [ 21: 21](RO) Stream match conflict fault configuration. Controls transactions with multiple matches in
                                                                 the stream mapping table.
                                                                 0 = Permit the transaction to bypass the SMMU.
                                                                 1 = Raise a stream match conflict fault.

                                                                 CNXXXX detects all stream match conflicts and always faults. */
        uint32_t mtcfg                 : 1;  /**< [ 20: 20](R/W) Memory type configuration, applies to transactions that bypass the stream mapping table.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes. */
        uint32_t memattr               : 4;  /**< [ 19: 16](R/W) Memory attributes for bypass transactions if MTCFG == 1. */
        uint32_t bsu                   : 2;  /**< [ 15: 14](RO) Barrier sharability upgrade. Upgrades the sharability of barriers issued by client devices
                                                                 that are not mapped to a translation context bank by setting the minimum sharability
                                                                 domain applied to any barrier.  Applies to transactions bypassing the stream mapping
                                                                 table.
                                                                 00 = No effect.
                                                                 01 = Inner sharable.
                                                                 10 = Outer sharable.
                                                                 11 = Full system.

                                                                 Ignored in CNXXXX. */
        uint32_t fb                    : 1;  /**< [ 13: 13](R/W) Force broadcast of TLB and instruction cache maintenance operations. Applies to
                                                                 transactions bypassing the stream mapping table. Affects client TLB maintenance, BPIALL
                                                                 and ICIALLU operations. If FB=1, any affected operation is modified to the equivalent
                                                                 broadcast variant in the inner shareable domain.
                                                                 0 = Process affected operations as presented.
                                                                 1 = Upgrade affected operations to be broadcast within the inner sharable domain.

                                                                 Ignored in CNXXXX, as NCB clients do not initiate invalidates. */
        uint32_t ptm                   : 1;  /**< [ 12: 12](R/W) Private TLB maintenance hint.
                                                                 0 = Process affected operations as presented.
                                                                 1 = SMMU TLBs are privately managed and are not require to respond to broadcast TLB
                                                                 maintenance operations from the wider system.

                                                                 CNXXXX honors this hint, but both the secure and non-secure version must be set for
                                                                 private management. INTERNAL: Note when set SMMU always still sends a response for the
                                                                 invalidates, it just does not perform the invalidation action against the TLB/WCU. */
        uint32_t vmidpne               : 1;  /**< [ 11: 11](RO) Reserved. */
        uint32_t usfcfg                : 1;  /**< [ 10: 10](R/W) Unidentified stream fault configuration.
                                                                 0 = Permit any transaction that does not match any entries in the stream matching table to
                                                                 pass through.
                                                                 1 = Raise an unidentified stream fault on any transaction that does not match any stream
                                                                 matching table entry. */
        uint32_t gse                   : 1;  /**< [  9:  9](RO) Global stall enable.
                                                                 0 = Do not enforce global stalling across contexts.
                                                                 1 = Enforce global stalling across contexts.

                                                                 In CNXXXX always 0, no stalling. */
        uint32_t stalld                : 1;  /**< [  8:  8](RO) Stall disable.
                                                                 0 = Permit per-context stalling on context faults.
                                                                 1 = Disable per-context stalling on context faults, or not programmable.

                                                                 In CNXXXX always 1, no stalling. */
        uint32_t transientcfg          : 2;  /**< [  7:  6](RO) Transient configuration controls the transient allocation hint.
                                                                 00 = Default transient allocation attributes.
                                                                 01 = Reserved.
                                                                 10 = Non-transient.
                                                                 11 = Transient.

                                                                 Not implemented in CNXXXX. */
        uint32_t gcfgfie               : 1;  /**< [  5:  5](RO) Global configuration fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global configuration fault.
                                                                 1 = Raise an interrupt on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t gcfgfre               : 1;  /**< [  4:  4](RO) Global configuration fault report enable.
                                                                 0 = Do not return an abort on a global configuration fault
                                                                 1 = Return an abort on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t exidenable            : 1;  /**< [  3:  3](R/W) Extended stream ID enable.
                                                                 0 = For this SSD, SMMU()_SMR() has the format with the VALID bit in the
                                                                 SMMU()_SMR(). The SMMU()_S2CR()[EXIDVALID] is ignored.
                                                                 1 = For this SSD, SMMU()_SMR() has the extended id format and the valid bit is
                                                                 held in the corresponding SMMU()_S2CR()[EXIDVALID].

                                                                 Software should only change [EXIDENABLE] when all SMMU()_S2CR().[EXIDVALID] == 0
                                                                 and SMMU()_SMR().[EXMASK[15]/VALID] == 0 for the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use. */
        uint32_t gfie                  : 1;  /**< [  2:  2](R/W) Global fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global fault.
                                                                 1 = Raise an interrupt on a global fault. */
        uint32_t gfre                  : 1;  /**< [  1:  1](R/W) Global fault report enable.
                                                                 0 = Do not return an abort on a global fault.
                                                                 1 = Return an abort on a global fault. */
        uint32_t clientpd              : 1;  /**< [  0:  0](R/W) Client port disable.
                                                                 0 = Each SMMU client access is subject to translation, access control and attribute
                                                                 generation.
                                                                 1 = Each SMMU client access bypasses translation, access control and attribute generation. */
#else /* Word 0 - Little Endian */
        uint32_t clientpd              : 1;  /**< [  0:  0](R/W) Client port disable.
                                                                 0 = Each SMMU client access is subject to translation, access control and attribute
                                                                 generation.
                                                                 1 = Each SMMU client access bypasses translation, access control and attribute generation. */
        uint32_t gfre                  : 1;  /**< [  1:  1](R/W) Global fault report enable.
                                                                 0 = Do not return an abort on a global fault.
                                                                 1 = Return an abort on a global fault. */
        uint32_t gfie                  : 1;  /**< [  2:  2](R/W) Global fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global fault.
                                                                 1 = Raise an interrupt on a global fault. */
        uint32_t exidenable            : 1;  /**< [  3:  3](R/W) Extended stream ID enable.
                                                                 0 = For this SSD, SMMU()_SMR() has the format with the VALID bit in the
                                                                 SMMU()_SMR(). The SMMU()_S2CR()[EXIDVALID] is ignored.
                                                                 1 = For this SSD, SMMU()_SMR() has the extended id format and the valid bit is
                                                                 held in the corresponding SMMU()_S2CR()[EXIDVALID].

                                                                 Software should only change [EXIDENABLE] when all SMMU()_S2CR().[EXIDVALID] == 0
                                                                 and SMMU()_SMR().[EXMASK[15]/VALID] == 0 for the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use. */
        uint32_t gcfgfre               : 1;  /**< [  4:  4](RO) Global configuration fault report enable.
                                                                 0 = Do not return an abort on a global configuration fault
                                                                 1 = Return an abort on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t gcfgfie               : 1;  /**< [  5:  5](RO) Global configuration fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global configuration fault.
                                                                 1 = Raise an interrupt on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
        uint32_t transientcfg          : 2;  /**< [  7:  6](RO) Transient configuration controls the transient allocation hint.
                                                                 00 = Default transient allocation attributes.
                                                                 01 = Reserved.
                                                                 10 = Non-transient.
                                                                 11 = Transient.

                                                                 Not implemented in CNXXXX. */
        uint32_t stalld                : 1;  /**< [  8:  8](RO) Stall disable.
                                                                 0 = Permit per-context stalling on context faults.
                                                                 1 = Disable per-context stalling on context faults, or not programmable.

                                                                 In CNXXXX always 1, no stalling. */
        uint32_t gse                   : 1;  /**< [  9:  9](RO) Global stall enable.
                                                                 0 = Do not enforce global stalling across contexts.
                                                                 1 = Enforce global stalling across contexts.

                                                                 In CNXXXX always 0, no stalling. */
        uint32_t usfcfg                : 1;  /**< [ 10: 10](R/W) Unidentified stream fault configuration.
                                                                 0 = Permit any transaction that does not match any entries in the stream matching table to
                                                                 pass through.
                                                                 1 = Raise an unidentified stream fault on any transaction that does not match any stream
                                                                 matching table entry. */
        uint32_t vmidpne               : 1;  /**< [ 11: 11](RO) Reserved. */
        uint32_t ptm                   : 1;  /**< [ 12: 12](R/W) Private TLB maintenance hint.
                                                                 0 = Process affected operations as presented.
                                                                 1 = SMMU TLBs are privately managed and are not require to respond to broadcast TLB
                                                                 maintenance operations from the wider system.

                                                                 CNXXXX honors this hint, but both the secure and non-secure version must be set for
                                                                 private management. INTERNAL: Note when set SMMU always still sends a response for the
                                                                 invalidates, it just does not perform the invalidation action against the TLB/WCU. */
        uint32_t fb                    : 1;  /**< [ 13: 13](R/W) Force broadcast of TLB and instruction cache maintenance operations. Applies to
                                                                 transactions bypassing the stream mapping table. Affects client TLB maintenance, BPIALL
                                                                 and ICIALLU operations. If FB=1, any affected operation is modified to the equivalent
                                                                 broadcast variant in the inner shareable domain.
                                                                 0 = Process affected operations as presented.
                                                                 1 = Upgrade affected operations to be broadcast within the inner sharable domain.

                                                                 Ignored in CNXXXX, as NCB clients do not initiate invalidates. */
        uint32_t bsu                   : 2;  /**< [ 15: 14](RO) Barrier sharability upgrade. Upgrades the sharability of barriers issued by client devices
                                                                 that are not mapped to a translation context bank by setting the minimum sharability
                                                                 domain applied to any barrier.  Applies to transactions bypassing the stream mapping
                                                                 table.
                                                                 00 = No effect.
                                                                 01 = Inner sharable.
                                                                 10 = Outer sharable.
                                                                 11 = Full system.

                                                                 Ignored in CNXXXX. */
        uint32_t memattr               : 4;  /**< [ 19: 16](R/W) Memory attributes for bypass transactions if MTCFG == 1. */
        uint32_t mtcfg                 : 1;  /**< [ 20: 20](R/W) Memory type configuration, applies to transactions that bypass the stream mapping table.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes. */
        uint32_t smcfcfg               : 1;  /**< [ 21: 21](RO) Stream match conflict fault configuration. Controls transactions with multiple matches in
                                                                 the stream mapping table.
                                                                 0 = Permit the transaction to bypass the SMMU.
                                                                 1 = Raise a stream match conflict fault.

                                                                 CNXXXX detects all stream match conflicts and always faults. */
        uint32_t shcfg                 : 2;  /**< [ 23: 22](RO) Shared configuration. Applies to transactions that bypass the stream mapping table.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
        uint32_t racfg                 : 2;  /**< [ 25: 24](RO) Read-allocate configuration, controls the allocation hint for read accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t wacfg                 : 2;  /**< [ 27: 26](RO) Write-allocate configuration, controls the allocation hint for write accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
        uint32_t nscfg                 : 2;  /**< [ 29: 28](SR/W) Non-secure configuration. Only exist in secure copy of register, RES0 in non-secure copy.
                                                                 This field only applies to secure transactions bypassing the SMMU stream mapping
                                                                 process.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure. */
        uint32_t hypmode               : 1;  /**< [ 30: 30](R/W) Hypervisor mode. Selects which hypervisor context is used:
                                                                   0 = When SMMU()_CBAR()[TYPE] = 0x1, SMMU()_CBAR()<10> represents HYPC.
                                                                   1 = When SMMU()_CBARn()[TYPE] = 0x1, SMMU()_CBAR()<10> represents E2HC.

                                                                 If this bit is changed, TLB maintenance is required.

                                                                 Only exists in the non secure copy of this register. */
        uint32_t vmid16en              : 1;  /**< [ 31: 31](R/W) Handling of 16-bit VMID extension:
                                                                 0 = 8-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBAR()[VMID].
                                                                 The SMMU()_CBA2R()[VMID16] field is RAZ.

                                                                 1 = 16-bit VMIDs are in use.
                                                                 The VMID is held in SMMU()_CBA2R()[VMID16].
                                                                 The SMMU()_CBAR()[VMID] field is RAZ.

                                                                 Only exists in the non-secure copy of this register.

                                                                 In pass 1, this field must be 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_scr0_s cn; */
} bdk_smmux_scr0_t;

static inline uint64_t BDK_SMMUX_SCR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SCR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000000ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000000ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000000ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SCR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SCR0(a) bdk_smmux_scr0_t
#define bustype_BDK_SMMUX_SCR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SCR0(a) "SMMUX_SCR0"
#define busnum_BDK_SMMUX_SCR0(a) (a)
#define arguments_BDK_SMMUX_SCR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_scr1
 *
 * SMMU Secure Configuration Register 1
 * Provides top-level secure control of the SMMU.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_scr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t nscompindexdisable    : 1;  /**< [ 29: 29](SRO) Non-secure compressed index disable.
                                                                 In CNXXXX stream compressed indexing is not implemented. */
        uint32_t nscafro               : 1;  /**< [ 28: 28](SRO) Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
        uint32_t spmen                 : 1;  /**< [ 27: 27](SR/W) Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
        uint32_t sif                   : 1;  /**< [ 26: 26](SR/W) Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
        uint32_t gefro                 : 1;  /**< [ 25: 25](SR/W) Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
        uint32_t gasrae                : 1;  /**< [ 24: 24](SR/W) Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
        uint32_t nsnumirpto            : 8;  /**< [ 23: 16](SRO) Non-secure number of interrupts override. Always 1 in ARMv8. */
        uint32_t nsnumsmrgo            : 8;  /**< [ 15:  8](SR/W) Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
        uint32_t nsnumcbo              : 8;  /**< [  7:  0](SR/W) Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
#else /* Word 0 - Little Endian */
        uint32_t nsnumcbo              : 8;  /**< [  7:  0](SR/W) Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
        uint32_t nsnumsmrgo            : 8;  /**< [ 15:  8](SR/W) Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
        uint32_t nsnumirpto            : 8;  /**< [ 23: 16](SRO) Non-secure number of interrupts override. Always 1 in ARMv8. */
        uint32_t gasrae                : 1;  /**< [ 24: 24](SR/W) Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
        uint32_t gefro                 : 1;  /**< [ 25: 25](SR/W) Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
        uint32_t sif                   : 1;  /**< [ 26: 26](SR/W) Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
        uint32_t spmen                 : 1;  /**< [ 27: 27](SR/W) Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
        uint32_t nscafro               : 1;  /**< [ 28: 28](SRO) Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
        uint32_t nscompindexdisable    : 1;  /**< [ 29: 29](SRO) Non-secure compressed index disable.
                                                                 In CNXXXX stream compressed indexing is not implemented. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    struct bdk_smmux_scr1_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t nshypmodedisable      : 1;  /**< [ 30: 30](SR/W) Reserved. */
        uint32_t nscompindexdisable    : 1;  /**< [ 29: 29](SRO) Non-secure compressed index disable.
                                                                 In CNXXXX stream compressed indexing is not implemented. */
        uint32_t nscafro               : 1;  /**< [ 28: 28](SRO) Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
        uint32_t spmen                 : 1;  /**< [ 27: 27](SR/W) Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
        uint32_t sif                   : 1;  /**< [ 26: 26](SR/W) Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
        uint32_t gefro                 : 1;  /**< [ 25: 25](SR/W) Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
        uint32_t gasrae                : 1;  /**< [ 24: 24](SR/W) Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
        uint32_t nsnumirpto            : 8;  /**< [ 23: 16](SRO) Non-secure number of interrupts override. Always 1 in ARMv8. */
        uint32_t nsnumsmrgo            : 8;  /**< [ 15:  8](SR/W) Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
        uint32_t nsnumcbo              : 8;  /**< [  7:  0](SR/W) Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
#else /* Word 0 - Little Endian */
        uint32_t nsnumcbo              : 8;  /**< [  7:  0](SR/W) Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
        uint32_t nsnumsmrgo            : 8;  /**< [ 15:  8](SR/W) Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
        uint32_t nsnumirpto            : 8;  /**< [ 23: 16](SRO) Non-secure number of interrupts override. Always 1 in ARMv8. */
        uint32_t gasrae                : 1;  /**< [ 24: 24](SR/W) Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
        uint32_t gefro                 : 1;  /**< [ 25: 25](SR/W) Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
        uint32_t sif                   : 1;  /**< [ 26: 26](SR/W) Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
        uint32_t spmen                 : 1;  /**< [ 27: 27](SR/W) Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
        uint32_t nscafro               : 1;  /**< [ 28: 28](SRO) Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
        uint32_t nscompindexdisable    : 1;  /**< [ 29: 29](SRO) Non-secure compressed index disable.
                                                                 In CNXXXX stream compressed indexing is not implemented. */
        uint32_t nshypmodedisable      : 1;  /**< [ 30: 30](SR/W) Reserved. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_smmux_scr1_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t reserved_30           : 1;
        uint32_t nscompindexdisable    : 1;  /**< [ 29: 29](SRO) Non-secure compressed index disable.
                                                                 In CNXXXX stream compressed indexing is not implemented. */
        uint32_t nscafro               : 1;  /**< [ 28: 28](SRO) Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
        uint32_t spmen                 : 1;  /**< [ 27: 27](SR/W) Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
        uint32_t sif                   : 1;  /**< [ 26: 26](SR/W) Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
        uint32_t gefro                 : 1;  /**< [ 25: 25](SR/W) Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
        uint32_t gasrae                : 1;  /**< [ 24: 24](SR/W) Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
        uint32_t nsnumirpto            : 8;  /**< [ 23: 16](SRO) Non-secure number of interrupts override. Always 1 in ARMv8. */
        uint32_t nsnumsmrgo            : 8;  /**< [ 15:  8](SR/W) Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
        uint32_t nsnumcbo              : 8;  /**< [  7:  0](SR/W) Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
#else /* Word 0 - Little Endian */
        uint32_t nsnumcbo              : 8;  /**< [  7:  0](SR/W) Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
        uint32_t nsnumsmrgo            : 8;  /**< [ 15:  8](SR/W) Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
        uint32_t nsnumirpto            : 8;  /**< [ 23: 16](SRO) Non-secure number of interrupts override. Always 1 in ARMv8. */
        uint32_t gasrae                : 1;  /**< [ 24: 24](SR/W) Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
        uint32_t gefro                 : 1;  /**< [ 25: 25](SR/W) Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
        uint32_t sif                   : 1;  /**< [ 26: 26](SR/W) Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
        uint32_t spmen                 : 1;  /**< [ 27: 27](SR/W) Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
        uint32_t nscafro               : 1;  /**< [ 28: 28](SRO) Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
        uint32_t nscompindexdisable    : 1;  /**< [ 29: 29](SRO) Non-secure compressed index disable.
                                                                 In CNXXXX stream compressed indexing is not implemented. */
        uint32_t reserved_30           : 1;
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_smmux_scr1_cn81xx cn83xx; */
    /* struct bdk_smmux_scr1_cn81xx cn88xxp2; */
} bdk_smmux_scr1_t;

static inline uint64_t BDK_SMMUX_SCR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SCR1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000004ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000004ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000004ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SCR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SCR1(a) bdk_smmux_scr1_t
#define bustype_BDK_SMMUX_SCR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SCR1(a) "SMMUX_SCR1"
#define busnum_BDK_SMMUX_SCR1(a) (a)
#define arguments_BDK_SMMUX_SCR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_scr2
 *
 * SMMU (Secure) Control Register 2
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_scr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t exsmrgenable          : 1;  /**< [ 31: 31](RO) Enables extended stream matching extension.
                                                                 In CNXXXX, extended stream matching is not implemented. */
        uint32_t exnssmrgdisable       : 1;  /**< [ 30: 30](SRO) Disables use of extended stream match register groups by non-secure software.
                                                                 Only exists in the secure copy of this register.

                                                                 In CNXXXX, extended stream matching is not implemented. */
        uint32_t compindexenable       : 1;  /**< [ 29: 29](RO) StreamID compressed index match enable.

                                                                 In CNXXXX, StreamID compressed indexing is not implemented. */
        uint32_t reserved_16_28        : 13;
        uint32_t bpvmid                : 16; /**< [ 15:  0](RAZ) Bypass VMID. VMID field applied to client transactions that bypass the SMMU. In CNXXXX,
                                                                 not supported. INTERNAL: If L2C adds support for QoS on a per VMID basis the L2C will also
                                                                 have a `secure' QoS setting, so this field should remain not required. */
#else /* Word 0 - Little Endian */
        uint32_t bpvmid                : 16; /**< [ 15:  0](RAZ) Bypass VMID. VMID field applied to client transactions that bypass the SMMU. In CNXXXX,
                                                                 not supported. INTERNAL: If L2C adds support for QoS on a per VMID basis the L2C will also
                                                                 have a `secure' QoS setting, so this field should remain not required. */
        uint32_t reserved_16_28        : 13;
        uint32_t compindexenable       : 1;  /**< [ 29: 29](RO) StreamID compressed index match enable.

                                                                 In CNXXXX, StreamID compressed indexing is not implemented. */
        uint32_t exnssmrgdisable       : 1;  /**< [ 30: 30](SRO) Disables use of extended stream match register groups by non-secure software.
                                                                 Only exists in the secure copy of this register.

                                                                 In CNXXXX, extended stream matching is not implemented. */
        uint32_t exsmrgenable          : 1;  /**< [ 31: 31](RO) Enables extended stream matching extension.
                                                                 In CNXXXX, extended stream matching is not implemented. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_scr2_s cn; */
} bdk_smmux_scr2_t;

static inline uint64_t BDK_SMMUX_SCR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SCR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000008ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000008ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000008ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SCR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SCR2(a) bdk_smmux_scr2_t
#define bustype_BDK_SMMUX_SCR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SCR2(a) "SMMUX_SCR2"
#define busnum_BDK_SMMUX_SCR2(a) (a)
#define arguments_BDK_SMMUX_SCR2(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_sgfar
 *
 * SMMU (Secure) Global Fault Address Register
 * Contains the input address of an erroneous request reported by SMMU()_(S)GFSR.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_sgfar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t faddr                 : 49; /**< [ 48:  0](R/W/H) Fault address, the input IOVA of the faulty access. For configuration access faults,
                                                                 this is the physical address resulting in the fault. For other fault classes it is the
                                                                 input address of the faulting access, which the system can interpret in a number of ways.
                                                                 This register is updated before a valid context has been determined. Hence, no sign
                                                                 extension can have been performed.

                                                                 For CNXXXX <11:0> are always zero. */
#else /* Word 0 - Little Endian */
        uint64_t faddr                 : 49; /**< [ 48:  0](R/W/H) Fault address, the input IOVA of the faulty access. For configuration access faults,
                                                                 this is the physical address resulting in the fault. For other fault classes it is the
                                                                 input address of the faulting access, which the system can interpret in a number of ways.
                                                                 This register is updated before a valid context has been determined. Hence, no sign
                                                                 extension can have been performed.

                                                                 For CNXXXX <11:0> are always zero. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sgfar_s cn; */
} bdk_smmux_sgfar_t;

static inline uint64_t BDK_SMMUX_SGFAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFAR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000040ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000040ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000040ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SGFAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SGFAR(a) bdk_smmux_sgfar_t
#define bustype_BDK_SMMUX_SGFAR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_SGFAR(a) "SMMUX_SGFAR"
#define busnum_BDK_SMMUX_SGFAR(a) (a)
#define arguments_BDK_SMMUX_SGFAR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_sgfsr
 *
 * SMMU (Secure) Global Fault Status Register
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_sgfsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t multi                 : 1;  /**< [ 31: 31](R/W1C/H) Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in this register was nonzero. */
        uint32_t reserved_9_30         : 22;
        uint32_t uut                   : 1;  /**< [  8:  8](R/W1C/H) Unsupported upstream transaction.
                                                                 0 = No unsupported upstream transaction fault.
                                                                 1 = Unsupported upstream transaction fault caused by receipt of an unsupported client
                                                                 transaction from an upstream device. */
        uint32_t pf                    : 1;  /**< [  7:  7](R/W1C/H) Permission fault. In SMMU_GFSR, this field is reserved. In SMMU_SGFSR, this field records
                                                                 global SMMU()_SCR1[SIF] faults.
                                                                 Note if a transaction is associated with a particular translation context bank, faults are
                                                                 recorded in SMMU()_CB()_FSR instead of SMMU_SGFSR. */
        uint32_t ef                    : 1;  /**< [  6:  6](R/W1C/H) External fault. */
        uint32_t caf                   : 1;  /**< [  5:  5](RO) Configuration access fault.
                                                                 For CNXXXX always zero, no configuration faults. */
        uint32_t ucif                  : 1;  /**< [  4:  4](R/W1C/H) Unimplemented context interrupt fault. */
        uint32_t ucbf                  : 1;  /**< [  3:  3](R/W1C/H) Unimplemented context bank fault. */
        uint32_t smcf                  : 1;  /**< [  2:  2](R/W1C/H) Stream match conflict fault. */
        uint32_t usf                   : 1;  /**< [  1:  1](R/W1C/H) Unidentified stream fault. */
        uint32_t icf                   : 1;  /**< [  0:  0](R/W1C/H) Invalid context fault. */
#else /* Word 0 - Little Endian */
        uint32_t icf                   : 1;  /**< [  0:  0](R/W1C/H) Invalid context fault. */
        uint32_t usf                   : 1;  /**< [  1:  1](R/W1C/H) Unidentified stream fault. */
        uint32_t smcf                  : 1;  /**< [  2:  2](R/W1C/H) Stream match conflict fault. */
        uint32_t ucbf                  : 1;  /**< [  3:  3](R/W1C/H) Unimplemented context bank fault. */
        uint32_t ucif                  : 1;  /**< [  4:  4](R/W1C/H) Unimplemented context interrupt fault. */
        uint32_t caf                   : 1;  /**< [  5:  5](RO) Configuration access fault.
                                                                 For CNXXXX always zero, no configuration faults. */
        uint32_t ef                    : 1;  /**< [  6:  6](R/W1C/H) External fault. */
        uint32_t pf                    : 1;  /**< [  7:  7](R/W1C/H) Permission fault. In SMMU_GFSR, this field is reserved. In SMMU_SGFSR, this field records
                                                                 global SMMU()_SCR1[SIF] faults.
                                                                 Note if a transaction is associated with a particular translation context bank, faults are
                                                                 recorded in SMMU()_CB()_FSR instead of SMMU_SGFSR. */
        uint32_t uut                   : 1;  /**< [  8:  8](R/W1C/H) Unsupported upstream transaction.
                                                                 0 = No unsupported upstream transaction fault.
                                                                 1 = Unsupported upstream transaction fault caused by receipt of an unsupported client
                                                                 transaction from an upstream device. */
        uint32_t reserved_9_30         : 22;
        uint32_t multi                 : 1;  /**< [ 31: 31](R/W1C/H) Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in this register was nonzero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sgfsr_s cn; */
} bdk_smmux_sgfsr_t;

static inline uint64_t BDK_SMMUX_SGFSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000048ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000048ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000048ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SGFSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SGFSR(a) bdk_smmux_sgfsr_t
#define bustype_BDK_SMMUX_SGFSR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SGFSR(a) "SMMUX_SGFSR"
#define busnum_BDK_SMMUX_SGFSR(a) (a)
#define arguments_BDK_SMMUX_SGFSR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_sgfsrrestore
 *
 * SMMU (Secure) Global Fault Status Restore Register
 * Restores the SMMU()_(S)GFSR register after reset.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_sgfsrrestore_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t restore               : 32; /**< [ 31:  0](WO) Writes bits in corresponding SMMU()_(S)GFSR. */
#else /* Word 0 - Little Endian */
        uint32_t restore               : 32; /**< [ 31:  0](WO) Writes bits in corresponding SMMU()_(S)GFSR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sgfsrrestore_s cn; */
} bdk_smmux_sgfsrrestore_t;

static inline uint64_t BDK_SMMUX_SGFSRRESTORE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSRRESTORE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x83000000004cll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x83000000004cll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x83000000004cll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SGFSRRESTORE", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SGFSRRESTORE(a) bdk_smmux_sgfsrrestore_t
#define bustype_BDK_SMMUX_SGFSRRESTORE(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SGFSRRESTORE(a) "SMMUX_SGFSRRESTORE"
#define busnum_BDK_SMMUX_SGFSRRESTORE(a) (a)
#define arguments_BDK_SMMUX_SGFSRRESTORE(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_sgfsynr0
 *
 * SMMU (Secure) Global Fault Syndrome Register 0
 * Contains fault syndrome information relating to SMMU()_(S)GFSR.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_sgfsynr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t imp                   : 8;  /**< [ 15:  8](RO) Reserved for implementation. */
        uint32_t reserved_7            : 1;
        uint32_t ats                   : 1;  /**< [  6:  6](RO) Address translation operation fault. For CNXXXX zero, SMMU()_IDR0[ATOSNS] not supported. */
        uint32_t nsattr                : 1;  /**< [  5:  5](R/W/H) Non-secure attribute.
                                                                 0 = The faulty transaction has the secure attribute.
                                                                 1 = The faulty transaction has the non-secure attribute. */
        uint32_t nsstate               : 1;  /**< [  4:  4](SR/W/H) Non-secure state.
                                                                 0 = The faulty transaction is associated with a secure device.
                                                                 1 = The faulty transaction is associated with a non-secure device.

                                                                 This field is only valid for the secure state.

                                                                 This field may read 1 in the event that a fault is encountered in relation to a
                                                                 non-secure client device and where SMMU()_SCR1[GEFRO]=1. */
        uint32_t ind                   : 1;  /**< [  3:  3](R/W/H) Instruction not data.
                                                                 0 = The faulty transaction has the data access attribute.
                                                                 1 = The faulty transaction has the instruction access attribute. */
        uint32_t pnu                   : 1;  /**< [  2:  2](R/W/H) Privileged not unprivileged.
                                                                 0 = The faulty transaction has the unprivileged attribute.
                                                                 1 = The faulty transaction has the privileged attribute. */
        uint32_t wnr                   : 1;  /**< [  1:  1](R/W/H) Write not read.
                                                                 0 = The faulty transaction is a read.
                                                                 1 = The faulty transaction is a write. */
        uint32_t nested                : 1;  /**< [  0:  0](R/W/H) Nested fault.
                                                                 0 = The fault occurred in the initial stream context.
                                                                 1 = The fault occurred in a nested context.

                                                                 This bit is reserved in SMMU_SGFSYNR0. */
#else /* Word 0 - Little Endian */
        uint32_t nested                : 1;  /**< [  0:  0](R/W/H) Nested fault.
                                                                 0 = The fault occurred in the initial stream context.
                                                                 1 = The fault occurred in a nested context.

                                                                 This bit is reserved in SMMU_SGFSYNR0. */
        uint32_t wnr                   : 1;  /**< [  1:  1](R/W/H) Write not read.
                                                                 0 = The faulty transaction is a read.
                                                                 1 = The faulty transaction is a write. */
        uint32_t pnu                   : 1;  /**< [  2:  2](R/W/H) Privileged not unprivileged.
                                                                 0 = The faulty transaction has the unprivileged attribute.
                                                                 1 = The faulty transaction has the privileged attribute. */
        uint32_t ind                   : 1;  /**< [  3:  3](R/W/H) Instruction not data.
                                                                 0 = The faulty transaction has the data access attribute.
                                                                 1 = The faulty transaction has the instruction access attribute. */
        uint32_t nsstate               : 1;  /**< [  4:  4](SR/W/H) Non-secure state.
                                                                 0 = The faulty transaction is associated with a secure device.
                                                                 1 = The faulty transaction is associated with a non-secure device.

                                                                 This field is only valid for the secure state.

                                                                 This field may read 1 in the event that a fault is encountered in relation to a
                                                                 non-secure client device and where SMMU()_SCR1[GEFRO]=1. */
        uint32_t nsattr                : 1;  /**< [  5:  5](R/W/H) Non-secure attribute.
                                                                 0 = The faulty transaction has the secure attribute.
                                                                 1 = The faulty transaction has the non-secure attribute. */
        uint32_t ats                   : 1;  /**< [  6:  6](RO) Address translation operation fault. For CNXXXX zero, SMMU()_IDR0[ATOSNS] not supported. */
        uint32_t reserved_7            : 1;
        uint32_t imp                   : 8;  /**< [ 15:  8](RO) Reserved for implementation. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sgfsynr0_s cn; */
} bdk_smmux_sgfsynr0_t;

static inline uint64_t BDK_SMMUX_SGFSYNR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSYNR0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000050ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000050ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000050ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SGFSYNR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SGFSYNR0(a) bdk_smmux_sgfsynr0_t
#define bustype_BDK_SMMUX_SGFSYNR0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SGFSYNR0(a) "SMMUX_SGFSYNR0"
#define busnum_BDK_SMMUX_SGFSYNR0(a) (a)
#define arguments_BDK_SMMUX_SGFSYNR0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_sgfsynr1
 *
 * SMMU (Secure) Global Fault Syndrome Register 1
 * Contains fault syndrome information relating to SMMU()_(S)GFSR.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_sgfsynr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssd_index             : 16; /**< [ 31: 16](SRO/H) The SSD_Index of the transaction that caused the fault. The SSD_Index field is only
                                                                 accessible to configuration accesses by secure software. Non-secure configuration accesses
                                                                 treat this field as RAZ/WI.

                                                                 For CNXXXX, the SSD_INDEX is always the same as [STREAMID]. */
        uint32_t streamid              : 16; /**< [ 15:  0](R/W/H) The stream ID of the transaction that caused the fault. */
#else /* Word 0 - Little Endian */
        uint32_t streamid              : 16; /**< [ 15:  0](R/W/H) The stream ID of the transaction that caused the fault. */
        uint32_t ssd_index             : 16; /**< [ 31: 16](SRO/H) The SSD_Index of the transaction that caused the fault. The SSD_Index field is only
                                                                 accessible to configuration accesses by secure software. Non-secure configuration accesses
                                                                 treat this field as RAZ/WI.

                                                                 For CNXXXX, the SSD_INDEX is always the same as [STREAMID]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sgfsynr1_s cn; */
} bdk_smmux_sgfsynr1_t;

static inline uint64_t BDK_SMMUX_SGFSYNR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSYNR1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000054ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000054ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000054ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SGFSYNR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SGFSYNR1(a) bdk_smmux_sgfsynr1_t
#define bustype_BDK_SMMUX_SGFSYNR1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SGFSYNR1(a) "SMMUX_SGFSYNR1"
#define busnum_BDK_SMMUX_SGFSYNR1(a) (a)
#define arguments_BDK_SMMUX_SGFSYNR1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_sgfsynr2
 *
 * SMMU (Secure) Global Fault Syndrome Register 2
 * Not implemented in CNXXXX.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_sgfsynr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sgfsynr2_s cn; */
} bdk_smmux_sgfsynr2_t;

static inline uint64_t BDK_SMMUX_SGFSYNR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSYNR2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000058ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000058ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000058ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SGFSYNR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SGFSYNR2(a) bdk_smmux_sgfsynr2_t
#define bustype_BDK_SMMUX_SGFSYNR2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SGFSYNR2(a) "SMMUX_SGFSYNR2"
#define busnum_BDK_SMMUX_SGFSYNR2(a) (a)
#define arguments_BDK_SMMUX_SGFSYNR2(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_smiss_perf
 *
 * SMMU Secure Misses Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_smiss_perf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) Counts the number of lookup requests in secure mode which missed the IOTLB.
                                                                 Also includes sign-extension position translation faults. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) Counts the number of lookup requests in secure mode which missed the IOTLB.
                                                                 Also includes sign-extension position translation faults. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_smiss_perf_s cn; */
} bdk_smmux_smiss_perf_t;

static inline uint64_t BDK_SMMUX_SMISS_PERF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SMISS_PERF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021040ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021040ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021040ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SMISS_PERF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SMISS_PERF(a) bdk_smmux_smiss_perf_t
#define bustype_BDK_SMMUX_SMISS_PERF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_SMISS_PERF(a) "SMMUX_SMISS_PERF"
#define busnum_BDK_SMMUX_SMISS_PERF(a) (a)
#define arguments_BDK_SMMUX_SMISS_PERF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_smr#
 *
 * SMMU Stream Match Register
 * Match a transaction with a particular stream mapping register group. The stream match register
 * table can have multiple entries matching the same stream id value during configuration,
 * providing software has the necessary precautions before configuration takes effect. For
 * example: 1. disable the stream source and ensure that no outstanding transactions from that
 * source are in progress disable one or more of the SMMU()_SMR() table entries using
 * the corresponding SMMU()_SMR()[VALID] bit, 2. disable the SMMU completely with
 * SMMU()_CB()_SCTLR[M].
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_smrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t exmask_valid          : 16; /**< [ 31: 16](R/W) Masking of stream id bits irrelevent to the matching process.

                                                                 If MASK<i>==1, ID<i> is ignored.

                                                                 If MASK<i>==0, ID<i> is relevant for matching.

                                                                 Note <31> indicates VALID if SMMU()_(S)CR0[EXIDENABLE] is zero. */
        uint32_t exid                  : 16; /**< [ 15:  0](R/W/H) Stream identifier to match after masking. In CNXXXX, if a bit is ignored (MASK<i>==1), the
                                                                 respective EXID<i> bit will be cleared by hardware. */
#else /* Word 0 - Little Endian */
        uint32_t exid                  : 16; /**< [ 15:  0](R/W/H) Stream identifier to match after masking. In CNXXXX, if a bit is ignored (MASK<i>==1), the
                                                                 respective EXID<i> bit will be cleared by hardware. */
        uint32_t exmask_valid          : 16; /**< [ 31: 16](R/W) Masking of stream id bits irrelevent to the matching process.

                                                                 If MASK<i>==1, ID<i> is ignored.

                                                                 If MASK<i>==0, ID<i> is relevant for matching.

                                                                 Note <31> indicates VALID if SMMU()_(S)CR0[EXIDENABLE] is zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_smrx_s cn; */
} bdk_smmux_smrx_t;

static inline uint64_t BDK_SMMUX_SMRX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SMRX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=127)))
        return 0x830000000800ll + 0x1000000000ll * ((a) & 0x0) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=127)))
        return 0x830000000800ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=127)))
        return 0x830000000800ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7f);
    __bdk_csr_fatal("SMMUX_SMRX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_SMRX(a,b) bdk_smmux_smrx_t
#define bustype_BDK_SMMUX_SMRX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SMRX(a,b) "SMMUX_SMRX"
#define busnum_BDK_SMMUX_SMRX(a,b) (a)
#define arguments_BDK_SMMUX_SMRX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) smmu#_sptread_perf
 *
 * SMMU Secure Page Table Reads Performance Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_sptread_perf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) Counts the number of page table reads issued to secure memory. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](SR/W/H) Counts the number of page table reads issued to secure memory. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_sptread_perf_s cn; */
} bdk_smmux_sptread_perf_t;

static inline uint64_t BDK_SMMUX_SPTREAD_PERF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SPTREAD_PERF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000021060ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000021060ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000021060ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_SPTREAD_PERF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_SPTREAD_PERF(a) bdk_smmux_sptread_perf_t
#define bustype_BDK_SMMUX_SPTREAD_PERF(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_SPTREAD_PERF(a) "SMMUX_SPTREAD_PERF"
#define busnum_BDK_SMMUX_SPTREAD_PERF(a) (a)
#define arguments_BDK_SMMUX_SPTREAD_PERF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_ssdr#
 *
 * SMMU Security State Definition Register
 * Internal:
 * INTERNAL: Address offset from SMM_GSSD_BASE.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_ssdrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssd                   : 32; /**< [ 31:  0](SR/W) Security state definition, where each bit corresponds to a SSD_Index:
                                                                 0 = Corresponding SSD_Index is acting for the secure domain.
                                                                 1 = Non-secure domain.

                                                                 Only accessible to secure software, else RAZ/WI. CNXXXX indexes this table by stream
                                                                 identifier, and uses the result of this table to also promote interrupts to secure
                                                                 interrupts. */
#else /* Word 0 - Little Endian */
        uint32_t ssd                   : 32; /**< [ 31:  0](SR/W) Security state definition, where each bit corresponds to a SSD_Index:
                                                                 0 = Corresponding SSD_Index is acting for the secure domain.
                                                                 1 = Non-secure domain.

                                                                 Only accessible to secure software, else RAZ/WI. CNXXXX indexes this table by stream
                                                                 identifier, and uses the result of this table to also promote interrupts to secure
                                                                 interrupts. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_ssdrx_s cn; */
} bdk_smmux_ssdrx_t;

static inline uint64_t BDK_SMMUX_SSDRX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SSDRX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=2047)))
        return 0x830000040000ll + 0x1000000000ll * ((a) & 0x0) + 4ll * ((b) & 0x7ff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=2047)))
        return 0x830000040000ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7ff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=2047)))
        return 0x830000040000ll + 0x1000000000ll * ((a) & 0x3) + 4ll * ((b) & 0x7ff);
    __bdk_csr_fatal("SMMUX_SSDRX", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_SSDRX(a,b) bdk_smmux_ssdrx_t
#define bustype_BDK_SMMUX_SSDRX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_SSDRX(a,b) "SMMUX_SSDRX"
#define busnum_BDK_SMMUX_SSDRX(a,b) (a)
#define arguments_BDK_SMMUX_SSDRX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_stlbgstatus
 *
 * SMMU (Secure) Global Synchronize TLB Status Register
 * Gives the status of a TLB maintenance operation. Register fields are identical to those in
 * SMMU()_(S)TLBGSTATUS.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_stlbgstatus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t gsactive              : 1;  /**< [  0:  0](RO/H) Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
#else /* Word 0 - Little Endian */
        uint32_t gsactive              : 1;  /**< [  0:  0](RO/H) Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_stlbgstatus_s cn; */
} bdk_smmux_stlbgstatus_t;

static inline uint64_t BDK_SMMUX_STLBGSTATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBGSTATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000074ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000074ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000074ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_STLBGSTATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_STLBGSTATUS(a) bdk_smmux_stlbgstatus_t
#define bustype_BDK_SMMUX_STLBGSTATUS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_STLBGSTATUS(a) "SMMUX_STLBGSTATUS"
#define busnum_BDK_SMMUX_STLBGSTATUS(a) (a)
#define arguments_BDK_SMMUX_STLBGSTATUS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_stlbgsync
 *
 * SMMU (Secure) Global Synchronize TLB Invalidate Register
 * Starts a global synchronization operation that ensures the completion of any previously
 * accepted TLB invalidate operation. Register fields are identical to those in
 * SMMU()_(S)TLBGSYNC.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_stlbgsync_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_stlbgsync_s cn; */
} bdk_smmux_stlbgsync_t;

static inline uint64_t BDK_SMMUX_STLBGSYNC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBGSYNC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000070ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000070ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000070ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_STLBGSYNC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_STLBGSYNC(a) bdk_smmux_stlbgsync_t
#define bustype_BDK_SMMUX_STLBGSYNC(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_STLBGSYNC(a) "SMMUX_STLBGSYNC"
#define busnum_BDK_SMMUX_STLBGSYNC(a) (a)
#define arguments_BDK_SMMUX_STLBGSYNC(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_stlbiall
 *
 * SMMU Secure TLB Invalidate All Register
 * Invalidates all unlocked secure entries in the TLB. Register fields are identical to those in
 * SMMU()_TLBIALLH.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_stlbiall_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](SWO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](SWO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_stlbiall_s cn; */
} bdk_smmux_stlbiall_t;

static inline uint64_t BDK_SMMUX_STLBIALL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIALL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000060ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000060ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000060ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_STLBIALL", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_STLBIALL(a) bdk_smmux_stlbiall_t
#define bustype_BDK_SMMUX_STLBIALL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_STLBIALL(a) "SMMUX_STLBIALL"
#define busnum_BDK_SMMUX_STLBIALL(a) (a)
#define arguments_BDK_SMMUX_STLBIALL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_stlbiallm
 *
 * SMMU Secure TLB Invalidate All Monitor Register
 * Invalidate all unlocked secure monitor entries in the TLB. Register fields are identical to
 * those in SMMU()_TLBIALLH.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_stlbiallm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](SWO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](SWO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_stlbiallm_s cn; */
} bdk_smmux_stlbiallm_t;

static inline uint64_t BDK_SMMUX_STLBIALLM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIALLM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000000bcll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000000bcll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000000bcll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_STLBIALLM", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_STLBIALLM(a) bdk_smmux_stlbiallm_t
#define bustype_BDK_SMMUX_STLBIALLM(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_STLBIALLM(a) "SMMUX_STLBIALLM"
#define busnum_BDK_SMMUX_STLBIALLM(a) (a)
#define arguments_BDK_SMMUX_STLBIALLM(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_stlbivalm
 *
 * SMMU Secure Invalidate Monitor TLB by VA Last Register
 * This secure 64-bit register operates exactly as SMMU()_STLBIVAM, except the invalidation
 * need only apply to the caching of entries returned from the last level of translation table
 * walk. This 64-bit register supports the ARMv8 TLB invalidation operation address format.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_stlbivalm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t address               : 44; /**< [ 43:  0](SWO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](SWO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_stlbivalm_s cn; */
} bdk_smmux_stlbivalm_t;

static inline uint64_t BDK_SMMUX_STLBIVALM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIVALM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000000a0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000000a0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000000a0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_STLBIVALM", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_STLBIVALM(a) bdk_smmux_stlbivalm_t
#define bustype_BDK_SMMUX_STLBIVALM(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_STLBIVALM(a) "SMMUX_STLBIVALM"
#define busnum_BDK_SMMUX_STLBIVALM(a) (a)
#define arguments_BDK_SMMUX_STLBIVALM(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_stlbivam
 *
 * SMMU Secure Invalidate Monitor TLB by VA Register
 * This secure 64-bit register invalidates all monitor TLB entries that associated with the
 * specified virtual address and applies to all unlocked entries within the TLB. This 64-bit
 * register supports the ARMv8 TLB invalidation operation address format. Register fields are
 * identical to those in SMMU()_TLBIVAH64.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_stlbivam_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t address               : 44; /**< [ 43:  0](SWO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](SWO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_stlbivam_s cn; */
} bdk_smmux_stlbivam_t;

static inline uint64_t BDK_SMMUX_STLBIVAM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIVAM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000000a8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000000a8ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000000a8ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_STLBIVAM", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_STLBIVAM(a) bdk_smmux_stlbivam_t
#define bustype_BDK_SMMUX_STLBIVAM(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_STLBIVAM(a) "SMMUX_STLBIVAM"
#define busnum_BDK_SMMUX_STLBIVAM(a) (a)
#define arguments_BDK_SMMUX_STLBIVAM(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_tlb#_dat
 *
 * SMMU Secure TLB Diagnostic Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_tlbx_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO/H) Internal TLB state, for diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO/H) Internal TLB state, for diagnostic use only. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbx_dat_s cn; */
} bdk_smmux_tlbx_dat_t;

static inline uint64_t BDK_SMMUX_TLBX_DAT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBX_DAT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=4095)))
        return 0x830000028000ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0xfff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=4095)))
        return 0x830000028000ll + 0x1000000000ll * ((a) & 0x3) + 8ll * ((b) & 0xfff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=4095)))
        return 0x830000028000ll + 0x1000000000ll * ((a) & 0x3) + 8ll * ((b) & 0xfff);
    __bdk_csr_fatal("SMMUX_TLBX_DAT", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_TLBX_DAT(a,b) bdk_smmux_tlbx_dat_t
#define bustype_BDK_SMMUX_TLBX_DAT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_TLBX_DAT(a,b) "SMMUX_TLBX_DAT"
#define busnum_BDK_SMMUX_TLBX_DAT(a,b) (a)
#define arguments_BDK_SMMUX_TLBX_DAT(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) smmu#_tlbiallh
 *
 * SMMU TLB Invalidate Hypervisor Register
 * Invalidate all hypervisor tagged entries in the TLB, regardless of the security state of each
 * entry. It can optionally apply to all unlocked entries.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_tlbiallh_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbiallh_s cn; */
} bdk_smmux_tlbiallh_t;

static inline uint64_t BDK_SMMUX_TLBIALLH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIALLH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x83000000006cll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x83000000006cll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x83000000006cll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIALLH", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIALLH(a) bdk_smmux_tlbiallh_t
#define bustype_BDK_SMMUX_TLBIALLH(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_TLBIALLH(a) "SMMUX_TLBIALLH"
#define busnum_BDK_SMMUX_TLBIALLH(a) (a)
#define arguments_BDK_SMMUX_TLBIALLH(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_tlbiallnsnh
 *
 * SMMU TLB Invalidate Non-Secure Non-Hypervisor Register
 * Invalidate all non-secure, non-hypervisor tagged entries in the TLB. Register fields are
 * identical to those in SMMU()_TLBIALLH. It can optionally apply to all unlocked entries.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_tlbiallnsnh_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#else /* Word 0 - Little Endian */
        uint32_t command               : 32; /**< [ 31:  0](WO) Any write to this register will perform the synchronization. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbiallnsnh_s cn; */
} bdk_smmux_tlbiallnsnh_t;

static inline uint64_t BDK_SMMUX_TLBIALLNSNH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIALLNSNH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000068ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000068ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000068ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIALLNSNH", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIALLNSNH(a) bdk_smmux_tlbiallnsnh_t
#define bustype_BDK_SMMUX_TLBIALLNSNH(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_TLBIALLNSNH(a) "SMMUX_TLBIALLNSNH"
#define busnum_BDK_SMMUX_TLBIALLNSNH(a) (a)
#define arguments_BDK_SMMUX_TLBIALLNSNH(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_tlbivah
 *
 * SMMU TLB Invalidate Hypervisor Legacy Register
 * Backward compatible version of SMMU()_TLBIVAH64.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_tlbivah_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbivah_s cn; */
} bdk_smmux_tlbivah_t;

static inline uint64_t BDK_SMMUX_TLBIVAH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVAH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000078ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000078ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000078ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIVAH", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIVAH(a) bdk_smmux_tlbivah_t
#define bustype_BDK_SMMUX_TLBIVAH(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_TLBIVAH(a) "SMMUX_TLBIVAH"
#define busnum_BDK_SMMUX_TLBIVAH(a) (a)
#define arguments_BDK_SMMUX_TLBIVAH(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_tlbivah64
 *
 * SMMU Invalidate Hypervisor TLB by VA Register
 * Invalidate all hypervisor tagged entries in the TLB, regardless of the security tagging
 * associated with the entry. It can optionally apply to all unlocked entries.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_tlbivah64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbivah64_s cn; */
} bdk_smmux_tlbivah64_t;

static inline uint64_t BDK_SMMUX_TLBIVAH64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVAH64(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000000c0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000000c0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000000c0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIVAH64", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIVAH64(a) bdk_smmux_tlbivah64_t
#define bustype_BDK_SMMUX_TLBIVAH64(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_TLBIVAH64(a) "SMMUX_TLBIVAH64"
#define busnum_BDK_SMMUX_TLBIVAH64(a) (a)
#define arguments_BDK_SMMUX_TLBIVAH64(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_tlbivalh64
 *
 * SMMU Invalidate Hypervisor TLB by VA Last Register
 * This 64-bit register operates exactly as SMMU()_TLBIVAH64, except the
 * invalidation need only apply to the caching of entries returned from the last level of
 * translation table walk. This 64-bit register supports the ARMv8 TLB invalidation operation
 * address format.
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_tlbivalh64_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
#else /* Word 0 - Little Endian */
        uint64_t address               : 44; /**< [ 43:  0](WO) Virtual address <55:12> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS<15:12> are ignored. The address will be extended to bit <63>
                                                                 by copying bit <55>. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbivalh64_s cn; */
} bdk_smmux_tlbivalh64_t;

static inline uint64_t BDK_SMMUX_TLBIVALH64(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVALH64(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000000b0ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000000b0ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000000b0ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIVALH64", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIVALH64(a) bdk_smmux_tlbivalh64_t
#define bustype_BDK_SMMUX_TLBIVALH64(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_TLBIVALH64(a) "SMMUX_TLBIVALH64"
#define busnum_BDK_SMMUX_TLBIVALH64(a) (a)
#define arguments_BDK_SMMUX_TLBIVALH64(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_tlbivmid
 *
 * SMMU TLB Invalidate VMID Register
 * Invalidate all non-secure, non-hypervisor TLB entries having the specified VMID. It can
 * optionally apply to all entries.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_tlbivmid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t vmid                  : 16; /**< [ 15:  0](WO) The virtual machine identifier to use in the invalidate operation. INTERNAL: Bits 15:8
                                                                 defined by the large system extensions. */
#else /* Word 0 - Little Endian */
        uint32_t vmid                  : 16; /**< [ 15:  0](WO) The virtual machine identifier to use in the invalidate operation. INTERNAL: Bits 15:8
                                                                 defined by the large system extensions. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbivmid_s cn; */
} bdk_smmux_tlbivmid_t;

static inline uint64_t BDK_SMMUX_TLBIVMID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVMID(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x830000000064ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x830000000064ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x830000000064ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIVMID", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIVMID(a) bdk_smmux_tlbivmid_t
#define bustype_BDK_SMMUX_TLBIVMID(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_TLBIVMID(a) "SMMUX_TLBIVMID"
#define busnum_BDK_SMMUX_TLBIVMID(a) (a)
#define arguments_BDK_SMMUX_TLBIVMID(a) (a),-1,-1,-1

/**
 * Register (NCB32b) smmu#_tlbivmids1
 *
 * SMMU TLB Invalidate by VMID Register
 * Invalidate all non-secure, non-hypervisor TLB entries having the specified VMID. In an
 * implementation using combined S1 + S2 TLB entries, this operation must invalidate any entries
 * tagged with a valid matching VMID. It operates exactly as SMMU()_TLBIVMID, except it only
 * applies to caching of entries containing information from the first stage of translation.
 */
typedef union
{
    uint32_t u;
    struct bdk_smmux_tlbivmids1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t vmid                  : 16; /**< [ 15:  0](WO) The virtual machine identifier to use in the invalidate operation. INTERNAL: Bits 15:8
                                                                 defined by the large system extensions. */
#else /* Word 0 - Little Endian */
        uint32_t vmid                  : 16; /**< [ 15:  0](WO) The virtual machine identifier to use in the invalidate operation. INTERNAL: Bits 15:8
                                                                 defined by the large system extensions. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_tlbivmids1_s cn; */
} bdk_smmux_tlbivmids1_t;

static inline uint64_t BDK_SMMUX_TLBIVMIDS1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVMIDS1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x8300000000b8ll + 0x1000000000ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x8300000000b8ll + 0x1000000000ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=3))
        return 0x8300000000b8ll + 0x1000000000ll * ((a) & 0x3);
    __bdk_csr_fatal("SMMUX_TLBIVMIDS1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SMMUX_TLBIVMIDS1(a) bdk_smmux_tlbivmids1_t
#define bustype_BDK_SMMUX_TLBIVMIDS1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SMMUX_TLBIVMIDS1(a) "SMMUX_TLBIVMIDS1"
#define busnum_BDK_SMMUX_TLBIVMIDS1(a) (a)
#define arguments_BDK_SMMUX_TLBIVMIDS1(a) (a),-1,-1,-1

/**
 * Register (NCB) smmu#_wcu#_dat
 *
 * SMMU Secure Walker Cache Diagnostic Data Register
 */
typedef union
{
    uint64_t u;
    struct bdk_smmux_wcux_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO/H) Internal WCU state, for diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 64; /**< [ 63:  0](SRO/H) Internal WCU state, for diagnostic use only. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_smmux_wcux_dat_s cn; */
} bdk_smmux_wcux_dat_t;

static inline uint64_t BDK_SMMUX_WCUX_DAT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_WCUX_DAT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a==0) && (b<=2047)))
        return 0x830000024000ll + 0x1000000000ll * ((a) & 0x0) + 8ll * ((b) & 0x7ff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=3) && (b<=2047)))
        return 0x830000024000ll + 0x1000000000ll * ((a) & 0x3) + 8ll * ((b) & 0x7ff);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && ((a<=3) && (b<=2047)))
        return 0x830000024000ll + 0x1000000000ll * ((a) & 0x3) + 8ll * ((b) & 0x7ff);
    __bdk_csr_fatal("SMMUX_WCUX_DAT", 2, a, b, 0, 0);
}

#define typedef_BDK_SMMUX_WCUX_DAT(a,b) bdk_smmux_wcux_dat_t
#define bustype_BDK_SMMUX_WCUX_DAT(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SMMUX_WCUX_DAT(a,b) "SMMUX_WCUX_DAT"
#define busnum_BDK_SMMUX_WCUX_DAT(a,b) (a)
#define arguments_BDK_SMMUX_WCUX_DAT(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_SMMU_H__ */
