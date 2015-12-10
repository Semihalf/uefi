#ifndef __BDK_CSRS_SSO_H__
#define __BDK_CSRS_SSO_H__
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
 * Cavium SSO.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration sso_bar_e
 *
 * SSO Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_SSO_BAR_E_SSO_PF_BAR0 (0x860000000000ll) /**< Base address for standard PF registers. */
#define BDK_SSO_BAR_E_SSO_PF_BAR4 (0x860700000000ll) /**< Base address for MSI-X PF registers. */
#define BDK_SSO_BAR_E_SSO_VFX_BAR0(a) (0x860800000000ll + 0x100000ll * (a)) /**< Base address for standard VF registers. */
#define BDK_SSO_BAR_E_SSO_VFX_BAR4(a) (0x860c00000000ll + 0x100000ll * (a)) /**< Base address for MSI-X VF registers. */

/**
 * Enumeration sso_pf_int_vec_e
 *
 * SSO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_SSO_PF_INT_VEC_E_ERR0 (0) /**< See interrupt clears SSO_ERR0, interrupt sets SSO_ERR0_W1S,
                                       enable clears SSO_ERR0_ENA_W1C, and enable sets SSO_ERR0_ENA_W1S. */
#define BDK_SSO_PF_INT_VEC_E_ERR1 (1) /**< See interrupt clears SSO_ERR1, interrupt sets SSO_ERR1_W1S,
                                       enable clears SSO_ERR1_ENA_W1C, and enable sets SSO_ERR1_ENA_W1S. */
#define BDK_SSO_PF_INT_VEC_E_ERR2 (2) /**< See interrupt clears SSO_ERR2, interrupt sets SSO_ERR2_W1S,
                                       enable clears SSO_ERR2_ENA_W1C, and enable sets SSO_ERR2_ENA_W1S. */
#define BDK_SSO_PF_INT_VEC_E_MBOXX(a) (3 + (a)) /**< See interrupt clears SSO_PF_MBOX_INT(),
                                       interrupt sets SSO_PF_MBOX_INT_W1S(),
                                       enable clears SSO_PF_MBOX_ENA_W1C(),
                                       and enable sets SSO_PF_MBOX_ENA_W1S(). */

/**
 * Enumeration sso_tt_e
 *
 * SSO Tag Type Enumeration
 * Enumerates the different SSO tag types.
 */
#define BDK_SSO_TT_E_ATOMIC (1) /**< ATOMIC tag type. */
#define BDK_SSO_TT_E_EMPTY (3) /**< Not an actual tag type, but indicates an empty work slot, or in ALLOC_WE operations to
                                       indicate no valid allocation. */
#define BDK_SSO_TT_E_ORDERED (0) /**< ORDERED tag type. */
#define BDK_SSO_TT_E_UNTAGGED (2) /**< UNTAGGED tag type. */

/**
 * Enumeration sso_vf_int_vec_e
 *
 * SSO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_SSO_VF_INT_VEC_E_GRP (0) /**< See interrupt clears SSO_VHGRP(0..63)_INT[EXE_INT,AQ_INT],
                                       interrupt sets SSO_VHGRP(0..63)_INT_W1S[EXE_INT,AQ_INT],
                                       enable clears SSO_VHGRP(0..63)_INT_ENA_W1C[EXE_INT,AQ_INT],
                                       and enable sets SSO_VHGRP(0..63)_INT_ENA_W1S[EXE_INT,AQ_INT]. */

/**
 * Enumeration sso_wa_e
 *
 * SSO Work Add Interface Enumeration
 * Enumerates the different SSO work-add interfaces bit fields in SSO_AW_INP_CTL[WA_DIS].
 */
#define BDK_SSO_WA_E_ADDWQ (3) /**< Software add-work interface. */
#define BDK_SSO_WA_E_CPT0 (2) /**< CPT0 add-work interface. */
#define BDK_SSO_WA_E_CPT1 (4) /**< CPT1 add-work interface. */
#define BDK_SSO_WA_E_DDF (0xc) /**< DDF add-work interface. */
#define BDK_SSO_WA_E_DFA (5) /**< DFA add-work interface. */
#define BDK_SSO_WA_E_DPI (6) /**< DPI add-work interface. */
#define BDK_SSO_WA_E_HNA (7) /**< HNA add-work interface. */
#define BDK_SSO_WA_E_IOBN (0) /**< Not a real add-work slot. */
#define BDK_SSO_WA_E_PKI (1) /**< PKI add-work interface. */
#define BDK_SSO_WA_E_PKO (8) /**< PKO add-work interface. */
#define BDK_SSO_WA_E_RAD (9) /**< RAD add-work interface. */
#define BDK_SSO_WA_E_TIM (0xa) /**< TIM add-work interface. */
#define BDK_SSO_WA_E_ZIP (0xb) /**< ZIP add-work interface. */

/**
 * Register (NCB) sso_active_cycles0
 *
 * SSO Active Cycles Register
 * This register counts every coprocessor-clock cycle that the SSO clocks are active in AW.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_active_cycles0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts the number of active cycles in each conditional clock domain. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts the number of active cycles in each conditional clock domain. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_active_cycles0_s cn; */
} bdk_sso_active_cycles0_t;

#define BDK_SSO_ACTIVE_CYCLES0 BDK_SSO_ACTIVE_CYCLES0_FUNC()
static inline uint64_t BDK_SSO_ACTIVE_CYCLES0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ACTIVE_CYCLES0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001100ll;
    __bdk_csr_fatal("SSO_ACTIVE_CYCLES0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ACTIVE_CYCLES0 bdk_sso_active_cycles0_t
#define bustype_BDK_SSO_ACTIVE_CYCLES0 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ACTIVE_CYCLES0 "SSO_ACTIVE_CYCLES0"
#define device_bar_BDK_SSO_ACTIVE_CYCLES0 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ACTIVE_CYCLES0 0
#define arguments_BDK_SSO_ACTIVE_CYCLES0 -1,-1,-1,-1

/**
 * Register (NCB) sso_active_cycles1
 *
 * SSO Active Cycles Register
 * This register counts every coprocessor-clock cycle that the SSO clocks are active in GW.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_active_cycles1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts the number of active cycles in each conditional clock domain in AW. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts the number of active cycles in each conditional clock domain in AW. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_active_cycles1_s cn; */
} bdk_sso_active_cycles1_t;

#define BDK_SSO_ACTIVE_CYCLES1 BDK_SSO_ACTIVE_CYCLES1_FUNC()
static inline uint64_t BDK_SSO_ACTIVE_CYCLES1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ACTIVE_CYCLES1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001108ll;
    __bdk_csr_fatal("SSO_ACTIVE_CYCLES1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ACTIVE_CYCLES1 bdk_sso_active_cycles1_t
#define bustype_BDK_SSO_ACTIVE_CYCLES1 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ACTIVE_CYCLES1 "SSO_ACTIVE_CYCLES1"
#define device_bar_BDK_SSO_ACTIVE_CYCLES1 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ACTIVE_CYCLES1 0
#define arguments_BDK_SSO_ACTIVE_CYCLES1 -1,-1,-1,-1

/**
 * Register (NCB) sso_active_cycles2
 *
 * SSO Active Cycles Register
 * This register counts every coprocessor-clock cycle that the SSO clocks are active in WS.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_active_cycles2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts the number of active cycles in each conditional clock domain. */
#else /* Word 0 - Little Endian */
        uint64_t act_cyc               : 64; /**< [ 63:  0](RO/H) Counts the number of active cycles in each conditional clock domain. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_active_cycles2_s cn; */
} bdk_sso_active_cycles2_t;

#define BDK_SSO_ACTIVE_CYCLES2 BDK_SSO_ACTIVE_CYCLES2_FUNC()
static inline uint64_t BDK_SSO_ACTIVE_CYCLES2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ACTIVE_CYCLES2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001110ll;
    __bdk_csr_fatal("SSO_ACTIVE_CYCLES2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ACTIVE_CYCLES2 bdk_sso_active_cycles2_t
#define bustype_BDK_SSO_ACTIVE_CYCLES2 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ACTIVE_CYCLES2 "SSO_ACTIVE_CYCLES2"
#define device_bar_BDK_SSO_ACTIVE_CYCLES2 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ACTIVE_CYCLES2 0
#define arguments_BDK_SSO_ACTIVE_CYCLES2 -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_add
 *
 * SSO Work-Entries Add Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_add_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t rsvd_free             : 14; /**< [ 29: 16](WO) Written value is added to SSO_AW_WE[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t rsvd_free             : 14; /**< [ 29: 16](WO) Written value is added to SSO_AW_WE[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_add_s cn; */
} bdk_sso_aw_add_t;

#define BDK_SSO_AW_ADD BDK_SSO_AW_ADD_FUNC()
static inline uint64_t BDK_SSO_AW_ADD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_ADD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002080ll;
    __bdk_csr_fatal("SSO_AW_ADD", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_ADD bdk_sso_aw_add_t
#define bustype_BDK_SSO_AW_ADD BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_ADD "SSO_AW_ADD"
#define device_bar_BDK_SSO_AW_ADD 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_ADD 0
#define arguments_BDK_SSO_AW_ADD -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_cfg
 *
 * SSO Add-Work Configuration Register
 * This register controls the operation of the add-work block (AW).
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t ldt_short             : 1;  /**< [  8:  8](R/W) Use LDT to bypass L2 allocations when reading short form work. */
        uint64_t lol                   : 1;  /**< [  7:  7](R/W) Reserved. */
        uint64_t xaq_alloc_dis         : 1;  /**< [  6:  6](R/W) Disable FPA alloc requests to fill the SSO page cache. Also all existing cached free
                                                                 buffers will be returned to FPA and will not be cached. */
        uint64_t ocla_bp               : 1;  /**< [  5:  5](R/W) OCLA backpressure enable. When OCLA FIFOs are near full, allow OCLA to backpressure AW pipeline. */
        uint64_t xaq_byp_dis           : 1;  /**< [  4:  4](R/W) Disable bypass path in add-work engine. For diagnostic use only. */
        uint64_t stt                   : 1;  /**< [  3:  3](R/W) Use STT to bypass L2 allocation for XAQ store operations. */
        uint64_t ldt                   : 1;  /**< [  2:  2](R/W) Use LDT to bypass L2 allocation for XAQ load operations. */
        uint64_t ldwb                  : 1;  /**< [  1:  1](R/W) When reading XAQ cache lines, use LDWB transactions to invalidate the cache line. */
        uint64_t rwen                  : 1;  /**< [  0:  0](R/W) Enable XAQ operations. This bit should be set after SSO_XAQ()_HEAD_PTR and
                                                                 SSO_XAQ()_TAIL_PTR have been programmed. If cleared, all cached buffers will be
                                                                 returned from the FPA as soon as possible, and TAQ arbitration is simplified. */
#else /* Word 0 - Little Endian */
        uint64_t rwen                  : 1;  /**< [  0:  0](R/W) Enable XAQ operations. This bit should be set after SSO_XAQ()_HEAD_PTR and
                                                                 SSO_XAQ()_TAIL_PTR have been programmed. If cleared, all cached buffers will be
                                                                 returned from the FPA as soon as possible, and TAQ arbitration is simplified. */
        uint64_t ldwb                  : 1;  /**< [  1:  1](R/W) When reading XAQ cache lines, use LDWB transactions to invalidate the cache line. */
        uint64_t ldt                   : 1;  /**< [  2:  2](R/W) Use LDT to bypass L2 allocation for XAQ load operations. */
        uint64_t stt                   : 1;  /**< [  3:  3](R/W) Use STT to bypass L2 allocation for XAQ store operations. */
        uint64_t xaq_byp_dis           : 1;  /**< [  4:  4](R/W) Disable bypass path in add-work engine. For diagnostic use only. */
        uint64_t ocla_bp               : 1;  /**< [  5:  5](R/W) OCLA backpressure enable. When OCLA FIFOs are near full, allow OCLA to backpressure AW pipeline. */
        uint64_t xaq_alloc_dis         : 1;  /**< [  6:  6](R/W) Disable FPA alloc requests to fill the SSO page cache. Also all existing cached free
                                                                 buffers will be returned to FPA and will not be cached. */
        uint64_t lol                   : 1;  /**< [  7:  7](R/W) Reserved. */
        uint64_t ldt_short             : 1;  /**< [  8:  8](R/W) Use LDT to bypass L2 allocations when reading short form work. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_cfg_s cn; */
} bdk_sso_aw_cfg_t;

#define BDK_SSO_AW_CFG BDK_SSO_AW_CFG_FUNC()
static inline uint64_t BDK_SSO_AW_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010f0ll;
    __bdk_csr_fatal("SSO_AW_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_CFG bdk_sso_aw_cfg_t
#define bustype_BDK_SSO_AW_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_CFG "SSO_AW_CFG"
#define device_bar_BDK_SSO_AW_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_CFG 0
#define arguments_BDK_SSO_AW_CFG -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_eco
 *
 * INTERNAL: SSO_AW ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_eco_s
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
    /* struct bdk_sso_aw_eco_s cn; */
} bdk_sso_aw_eco_t;

#define BDK_SSO_AW_ECO BDK_SSO_AW_ECO_FUNC()
static inline uint64_t BDK_SSO_AW_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001030ll;
    __bdk_csr_fatal("SSO_AW_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_ECO bdk_sso_aw_eco_t
#define bustype_BDK_SSO_AW_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_ECO "SSO_AW_ECO"
#define device_bar_BDK_SSO_AW_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_ECO 0
#define arguments_BDK_SSO_AW_ECO -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_inp_ctl
 *
 * SSO Add-Work Input Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_inp_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t wa_dis                : 13; /**< [ 12:  0](R/W) Add-work input disable.  Each bit corresponds to a hardware input queue, and if
                                                                 set add-works from the corresponding coprocessor will be dropped.
                                                                 Bit numbers enumerated by SSO_WA_E. */
#else /* Word 0 - Little Endian */
        uint64_t wa_dis                : 13; /**< [ 12:  0](R/W) Add-work input disable.  Each bit corresponds to a hardware input queue, and if
                                                                 set add-works from the corresponding coprocessor will be dropped.
                                                                 Bit numbers enumerated by SSO_WA_E. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_inp_ctl_s cn; */
} bdk_sso_aw_inp_ctl_t;

#define BDK_SSO_AW_INP_CTL BDK_SSO_AW_INP_CTL_FUNC()
static inline uint64_t BDK_SSO_AW_INP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_INP_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002070ll;
    __bdk_csr_fatal("SSO_AW_INP_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_INP_CTL bdk_sso_aw_inp_ctl_t
#define bustype_BDK_SSO_AW_INP_CTL BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_INP_CTL "SSO_AW_INP_CTL"
#define device_bar_BDK_SSO_AW_INP_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_INP_CTL 0
#define arguments_BDK_SSO_AW_INP_CTL -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_read_arb
 *
 * SSO Read Arbitration Register
 * This register fine tunes the AW read arbiter and is for diagnostic use.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_read_arb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t xaq_lev               : 6;  /**< [ 29: 24](RO/H) Current number of XAQ reads outstanding. */
        uint64_t reserved_21_23        : 3;
        uint64_t xaq_min               : 5;  /**< [ 20: 16](R/W) Number of read slots reserved for XAQ exclusive use. Values > 16 will not result in
                                                                 additional XAQ reads in flight, but will reduce maximum AW_TAG reads in flight. */
        uint64_t reserved_14_15        : 2;
        uint64_t aw_tag_lev            : 6;  /**< [ 13:  8](RO/H) Current number of tag reads outstanding. */
        uint64_t reserved_5_7          : 3;
        uint64_t aw_tag_min            : 5;  /**< [  4:  0](R/W) Number of read slots reserved for AQ tag read exclusive use. */
#else /* Word 0 - Little Endian */
        uint64_t aw_tag_min            : 5;  /**< [  4:  0](R/W) Number of read slots reserved for AQ tag read exclusive use. */
        uint64_t reserved_5_7          : 3;
        uint64_t aw_tag_lev            : 6;  /**< [ 13:  8](RO/H) Current number of tag reads outstanding. */
        uint64_t reserved_14_15        : 2;
        uint64_t xaq_min               : 5;  /**< [ 20: 16](R/W) Number of read slots reserved for XAQ exclusive use. Values > 16 will not result in
                                                                 additional XAQ reads in flight, but will reduce maximum AW_TAG reads in flight. */
        uint64_t reserved_21_23        : 3;
        uint64_t xaq_lev               : 6;  /**< [ 29: 24](RO/H) Current number of XAQ reads outstanding. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_read_arb_s cn; */
} bdk_sso_aw_read_arb_t;

#define BDK_SSO_AW_READ_ARB BDK_SSO_AW_READ_ARB_FUNC()
static inline uint64_t BDK_SSO_AW_READ_ARB_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_READ_ARB_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002090ll;
    __bdk_csr_fatal("SSO_AW_READ_ARB", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_READ_ARB bdk_sso_aw_read_arb_t
#define bustype_BDK_SSO_AW_READ_ARB BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_READ_ARB "SSO_AW_READ_ARB"
#define device_bar_BDK_SSO_AW_READ_ARB 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_READ_ARB 0
#define arguments_BDK_SSO_AW_READ_ARB -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_status
 *
 * SSO Add-Work Status Register
 * This register indicates the status of the add-work block (AW).
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t xaq_buf_cached        : 6;  /**< [  5:  0](RO/H) Indicates number of FPA buffers cached inside SSO. */
#else /* Word 0 - Little Endian */
        uint64_t xaq_buf_cached        : 6;  /**< [  5:  0](RO/H) Indicates number of FPA buffers cached inside SSO. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_status_s cn; */
} bdk_sso_aw_status_t;

#define BDK_SSO_AW_STATUS BDK_SSO_AW_STATUS_FUNC()
static inline uint64_t BDK_SSO_AW_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010e0ll;
    __bdk_csr_fatal("SSO_AW_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_STATUS bdk_sso_aw_status_t
#define bustype_BDK_SSO_AW_STATUS BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_STATUS "SSO_AW_STATUS"
#define device_bar_BDK_SSO_AW_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_STATUS 0
#define arguments_BDK_SSO_AW_STATUS -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_tag_latency_pc
 *
 * SSO Short Form Tag Requests Perf-Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_tag_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for tag read returns. This may be divided by SSO_AW_TAG_REQ_PC to
                                                                 determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for tag read returns. This may be divided by SSO_AW_TAG_REQ_PC to
                                                                 determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_tag_latency_pc_s cn; */
} bdk_sso_aw_tag_latency_pc_t;

#define BDK_SSO_AW_TAG_LATENCY_PC BDK_SSO_AW_TAG_LATENCY_PC_FUNC()
static inline uint64_t BDK_SSO_AW_TAG_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_TAG_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020a8ll;
    __bdk_csr_fatal("SSO_AW_TAG_LATENCY_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_TAG_LATENCY_PC bdk_sso_aw_tag_latency_pc_t
#define bustype_BDK_SSO_AW_TAG_LATENCY_PC BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_TAG_LATENCY_PC "SSO_AW_TAG_LATENCY_PC"
#define device_bar_BDK_SSO_AW_TAG_LATENCY_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_TAG_LATENCY_PC 0
#define arguments_BDK_SSO_AW_TAG_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_tag_req_pc
 *
 * SSO Short Form Tag Latency Perf-Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_tag_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of tag read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of tag read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_tag_req_pc_s cn; */
} bdk_sso_aw_tag_req_pc_t;

#define BDK_SSO_AW_TAG_REQ_PC BDK_SSO_AW_TAG_REQ_PC_FUNC()
static inline uint64_t BDK_SSO_AW_TAG_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_TAG_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020a0ll;
    __bdk_csr_fatal("SSO_AW_TAG_REQ_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_TAG_REQ_PC bdk_sso_aw_tag_req_pc_t
#define bustype_BDK_SSO_AW_TAG_REQ_PC BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_TAG_REQ_PC "SSO_AW_TAG_REQ_PC"
#define device_bar_BDK_SSO_AW_TAG_REQ_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_TAG_REQ_PC 0
#define arguments_BDK_SSO_AW_TAG_REQ_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_aw_we
 *
 * SSO Work-Entries Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_aw_we_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](R/W/H) Number of free reserved entries. Used to ensure that each group can get a specific number
                                                                 of entries. Must always be greater than or equal to the sum across all
                                                                 SSO_GRP()_IAQ_THR[RSVD_THR], and will generally be equal to that sum unless changes
                                                                 to RSVD_THR are going to be made. To prevent races, software should not change this
                                                                 register when SSO is being used; instead use SSO_AW_ADD[RSVD_FREE]. */
        uint64_t reserved_13_15        : 3;
        uint64_t free_cnt              : 13; /**< [ 12:  0](RO/H) Number of total free entries. */
#else /* Word 0 - Little Endian */
        uint64_t free_cnt              : 13; /**< [ 12:  0](RO/H) Number of total free entries. */
        uint64_t reserved_13_15        : 3;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](R/W/H) Number of free reserved entries. Used to ensure that each group can get a specific number
                                                                 of entries. Must always be greater than or equal to the sum across all
                                                                 SSO_GRP()_IAQ_THR[RSVD_THR], and will generally be equal to that sum unless changes
                                                                 to RSVD_THR are going to be made. To prevent races, software should not change this
                                                                 register when SSO is being used; instead use SSO_AW_ADD[RSVD_FREE]. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_aw_we_s cn; */
} bdk_sso_aw_we_t;

#define BDK_SSO_AW_WE BDK_SSO_AW_WE_FUNC()
static inline uint64_t BDK_SSO_AW_WE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_AW_WE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001080ll;
    __bdk_csr_fatal("SSO_AW_WE", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_AW_WE bdk_sso_aw_we_t
#define bustype_BDK_SSO_AW_WE BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_AW_WE "SSO_AW_WE"
#define device_bar_BDK_SSO_AW_WE 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_AW_WE 0
#define arguments_BDK_SSO_AW_WE -1,-1,-1,-1

/**
 * Register (NCB) sso_bist_status0
 *
 * SSO BIST Status Register
 * Contains the BIST status for the SSO memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_bist_status0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t bist                  : 11; /**< [ 10:  0](RO/H) Memory BIST status. 0 = pass, 1 = fail.
                                                                 Internal:
                                                                 <10> = MEMMGT.
                                                                  <9> = WES.
                                                                  <8> = FFF.
                                                                  <7> = XAQ.
                                                                  <6> = QTC.
                                                                  <5> = INP.
                                                                  <4> = LLM.
                                                                  <3> = TIAQ_HPTR.
                                                                  <2> = TIAQ_TPTR.
                                                                  <1> = TOAQ_HPTR.
                                                                  <0> = TOAQ_TPTR. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 11; /**< [ 10:  0](RO/H) Memory BIST status. 0 = pass, 1 = fail.
                                                                 Internal:
                                                                 <10> = MEMMGT.
                                                                  <9> = WES.
                                                                  <8> = FFF.
                                                                  <7> = XAQ.
                                                                  <6> = QTC.
                                                                  <5> = INP.
                                                                  <4> = LLM.
                                                                  <3> = TIAQ_HPTR.
                                                                  <2> = TIAQ_TPTR.
                                                                  <1> = TOAQ_HPTR.
                                                                  <0> = TOAQ_TPTR. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_bist_status0_s cn; */
} bdk_sso_bist_status0_t;

#define BDK_SSO_BIST_STATUS0 BDK_SSO_BIST_STATUS0_FUNC()
static inline uint64_t BDK_SSO_BIST_STATUS0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_BIST_STATUS0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001200ll;
    __bdk_csr_fatal("SSO_BIST_STATUS0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_BIST_STATUS0 bdk_sso_bist_status0_t
#define bustype_BDK_SSO_BIST_STATUS0 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_BIST_STATUS0 "SSO_BIST_STATUS0"
#define device_bar_BDK_SSO_BIST_STATUS0 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_BIST_STATUS0 0
#define arguments_BDK_SSO_BIST_STATUS0 -1,-1,-1,-1

/**
 * Register (NCB) sso_bist_status1
 *
 * SSO BIST Status 1 Register
 * Contains the BIST status for the SSO memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_bist_status1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t bist                  : 8;  /**< [  7:  0](RO/H) Memory BIST status. 0 = pass, 1 = fail.
                                                                 Internal:
                                                                 <7> = MBOX_MEM,
                                                                 <6> = THRINT.
                                                                 <5> = MASK.
                                                                 <4> = GDW.
                                                                 <3> = QIDX.
                                                                 <2> = TPTR.
                                                                 <1> = HPTR.
                                                                 <0> = CNTR. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 8;  /**< [  7:  0](RO/H) Memory BIST status. 0 = pass, 1 = fail.
                                                                 Internal:
                                                                 <7> = MBOX_MEM,
                                                                 <6> = THRINT.
                                                                 <5> = MASK.
                                                                 <4> = GDW.
                                                                 <3> = QIDX.
                                                                 <2> = TPTR.
                                                                 <1> = HPTR.
                                                                 <0> = CNTR. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_bist_status1_s cn; */
} bdk_sso_bist_status1_t;

#define BDK_SSO_BIST_STATUS1 BDK_SSO_BIST_STATUS1_FUNC()
static inline uint64_t BDK_SSO_BIST_STATUS1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_BIST_STATUS1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001208ll;
    __bdk_csr_fatal("SSO_BIST_STATUS1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_BIST_STATUS1 bdk_sso_bist_status1_t
#define bustype_BDK_SSO_BIST_STATUS1 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_BIST_STATUS1 "SSO_BIST_STATUS1"
#define device_bar_BDK_SSO_BIST_STATUS1 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_BIST_STATUS1 0
#define arguments_BDK_SSO_BIST_STATUS1 -1,-1,-1,-1

/**
 * Register (NCB) sso_bist_status2
 *
 * SSO BIST Status 2 Register
 * Contains the BIST status for the SSO memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_bist_status2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t bist                  : 10; /**< [  9:  0](RO/H) Memory BIST status. 0 = pass, 1 = fail.
                                                                 Internal:
                                                                 <9> = PCC.
                                                                 <8> = PC_WS.
                                                                 <7> = PC_WA.
                                                                 <6> = PC_TS.
                                                                 <5> = PC_DS.
                                                                 <4> = NCB0.
                                                                 <3> = PND.
                                                                 <2> = OTH.
                                                                 <1> = NIDX.
                                                                 <0> = PIDX. */
#else /* Word 0 - Little Endian */
        uint64_t bist                  : 10; /**< [  9:  0](RO/H) Memory BIST status. 0 = pass, 1 = fail.
                                                                 Internal:
                                                                 <9> = PCC.
                                                                 <8> = PC_WS.
                                                                 <7> = PC_WA.
                                                                 <6> = PC_TS.
                                                                 <5> = PC_DS.
                                                                 <4> = NCB0.
                                                                 <3> = PND.
                                                                 <2> = OTH.
                                                                 <1> = NIDX.
                                                                 <0> = PIDX. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_bist_status2_s cn; */
} bdk_sso_bist_status2_t;

#define BDK_SSO_BIST_STATUS2 BDK_SSO_BIST_STATUS2_FUNC()
static inline uint64_t BDK_SSO_BIST_STATUS2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_BIST_STATUS2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001210ll;
    __bdk_csr_fatal("SSO_BIST_STATUS2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_BIST_STATUS2 bdk_sso_bist_status2_t
#define bustype_BDK_SSO_BIST_STATUS2 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_BIST_STATUS2 "SSO_BIST_STATUS2"
#define device_bar_BDK_SSO_BIST_STATUS2 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_BIST_STATUS2 0
#define arguments_BDK_SSO_BIST_STATUS2 -1,-1,-1,-1

/**
 * Register (NCB) sso_bp_test0
 *
 * INTERNAL: SSO Backpressure Test Register 0
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_bp_test0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=25% of the time, 0x2=50% of the time,
                                                                 0x3=75% of the time.
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
                                                                 defined as 0x0=100% of the time, 0x1=25% of the time, 0x2=50% of the time,
                                                                 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_bp_test0_s cn; */
} bdk_sso_bp_test0_t;

#define BDK_SSO_BP_TEST0 BDK_SSO_BP_TEST0_FUNC()
static inline uint64_t BDK_SSO_BP_TEST0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_BP_TEST0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001300ll;
    __bdk_csr_fatal("SSO_BP_TEST0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_BP_TEST0 bdk_sso_bp_test0_t
#define bustype_BDK_SSO_BP_TEST0 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_BP_TEST0 "SSO_BP_TEST0"
#define device_bar_BDK_SSO_BP_TEST0 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_BP_TEST0 0
#define arguments_BDK_SSO_BP_TEST0 -1,-1,-1,-1

/**
 * Register (NCB) sso_bp_test1
 *
 * INTERNAL: SSO Backpressure Test Register 1
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_bp_test1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=25% of the time, 0x2=50% of the time,
                                                                 0x3=75% of the time.
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
                                                                 defined as 0x0=100% of the time, 0x1=25% of the time, 0x2=50% of the time,
                                                                 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_bp_test1_s cn; */
} bdk_sso_bp_test1_t;

#define BDK_SSO_BP_TEST1 BDK_SSO_BP_TEST1_FUNC()
static inline uint64_t BDK_SSO_BP_TEST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_BP_TEST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001310ll;
    __bdk_csr_fatal("SSO_BP_TEST1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_BP_TEST1 bdk_sso_bp_test1_t
#define bustype_BDK_SSO_BP_TEST1 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_BP_TEST1 "SSO_BP_TEST1"
#define device_bar_BDK_SSO_BP_TEST1 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_BP_TEST1 0
#define arguments_BDK_SSO_BP_TEST1 -1,-1,-1,-1

/**
 * Register (NCB) sso_bp_test2
 *
 * INTERNAL: SSO Backpressure Test Register 2
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_bp_test2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
        uint64_t reserved_24_59        : 36;
        uint64_t bp_cfg                : 8;  /**< [ 23: 16](R/W) Backpressure weight. For diagnostic use only.
                                                                 Internal:
                                                                 There are 2 backpressure configuration bits per enable, with the two bits
                                                                 defined as 0x0=100% of the time, 0x1=25% of the time, 0x2=50% of the time,
                                                                 0x3=75% of the time.
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
                                                                 defined as 0x0=100% of the time, 0x1=25% of the time, 0x2=50% of the time,
                                                                 0x3=75% of the time.
                                                                   <23:22> = BP_CFG3.
                                                                   <21:20> = BP_CFG2.
                                                                   <19:18> = BP_CFG1.
                                                                   <17:16> = BP_CFG0. */
        uint64_t reserved_24_59        : 36;
        uint64_t enable                : 4;  /**< [ 63: 60](R/W) Enable test mode. For diagnostic use only.
                                                                 Internal:
                                                                 Once a bit is set, random backpressure is generated
                                                                 at the corresponding point to allow for more frequent backpressure.
                                                                 <63> = Reserved. FIXME - add some.
                                                                 <62> = Reserved. FIXME - add some.
                                                                 <61> = Reserved. FIXME - add some.
                                                                 <60> = Reserved. FIXME - add some. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_bp_test2_s cn; */
} bdk_sso_bp_test2_t;

#define BDK_SSO_BP_TEST2 BDK_SSO_BP_TEST2_FUNC()
static inline uint64_t BDK_SSO_BP_TEST2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_BP_TEST2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001320ll;
    __bdk_csr_fatal("SSO_BP_TEST2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_BP_TEST2 bdk_sso_bp_test2_t
#define bustype_BDK_SSO_BP_TEST2 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_BP_TEST2 "SSO_BP_TEST2"
#define device_bar_BDK_SSO_BP_TEST2 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_BP_TEST2 0
#define arguments_BDK_SSO_BP_TEST2 -1,-1,-1,-1

/**
 * Register (NCB) sso_const
 *
 * SSO Constants Register
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t hws                   : 8;  /**< [ 63: 56](RO) Number of hardware work slots. */
        uint64_t taq_b                 : 8;  /**< [ 55: 48](RAZ) Number of TAQ entries per line.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t taq_a                 : 16; /**< [ 47: 32](RO) Number of TAQ lines.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t iue                   : 16; /**< [ 31: 16](RO) Number of in-unit entries. */
        uint64_t grp                   : 16; /**< [ 15:  0](RO) Number of groups. */
#else /* Word 0 - Little Endian */
        uint64_t grp                   : 16; /**< [ 15:  0](RO) Number of groups. */
        uint64_t iue                   : 16; /**< [ 31: 16](RO) Number of in-unit entries. */
        uint64_t taq_a                 : 16; /**< [ 47: 32](RO) Number of TAQ lines.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t taq_b                 : 8;  /**< [ 55: 48](RAZ) Number of TAQ entries per line.  Multiply [TAQ_A] times [TAQ_B] to find total entries. */
        uint64_t hws                   : 8;  /**< [ 63: 56](RO) Number of hardware work slots. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_const_s cn; */
} bdk_sso_const_t;

#define BDK_SSO_CONST BDK_SSO_CONST_FUNC()
static inline uint64_t BDK_SSO_CONST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_CONST_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001000ll;
    __bdk_csr_fatal("SSO_CONST", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_CONST bdk_sso_const_t
#define bustype_BDK_SSO_CONST BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_CONST "SSO_CONST"
#define device_bar_BDK_SSO_CONST 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_CONST 0
#define arguments_BDK_SSO_CONST -1,-1,-1,-1

/**
 * Register (NCB) sso_const1
 *
 * SSO Constants Register 1
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t maps                  : 12; /**< [ 43: 32](RO) Number of entries in SSO_PF_MAP(). */
        uint64_t xae_waes              : 16; /**< [ 31: 16](RO) Number of WAEs (work entries) in a XAQ buffer. */
        uint64_t xaq_buf_size          : 16; /**< [ 15:  0](RO) Number of bytes in a XAQ buffer. */
#else /* Word 0 - Little Endian */
        uint64_t xaq_buf_size          : 16; /**< [ 15:  0](RO) Number of bytes in a XAQ buffer. */
        uint64_t xae_waes              : 16; /**< [ 31: 16](RO) Number of WAEs (work entries) in a XAQ buffer. */
        uint64_t maps                  : 12; /**< [ 43: 32](RO) Number of entries in SSO_PF_MAP(). */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_const1_s cn; */
} bdk_sso_const1_t;

#define BDK_SSO_CONST1 BDK_SSO_CONST1_FUNC()
static inline uint64_t BDK_SSO_CONST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_CONST1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001008ll;
    __bdk_csr_fatal("SSO_CONST1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_CONST1 bdk_sso_const1_t
#define bustype_BDK_SSO_CONST1 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_CONST1 "SSO_CONST1"
#define device_bar_BDK_SSO_CONST1 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_CONST1 0
#define arguments_BDK_SSO_CONST1 -1,-1,-1,-1

/**
 * Register (NCB) sso_ecc_ctl0
 *
 * SSO ECC Control 0 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ecc_ctl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t memmgt_flip           : 2;  /**< [ 32: 31](R/W) MEMMGT flip syndrome bits on write. */
        uint64_t memmgt_cdis           : 1;  /**< [ 30: 30](R/W) MEMMGT ECC correction disable. */
        uint64_t toaqt_flip            : 2;  /**< [ 29: 28](R/W) TOAQT flip syndrome bits on write. */
        uint64_t toaqt_cdis            : 1;  /**< [ 27: 27](R/W) TOAQT ECC correction disable. */
        uint64_t toaqh_flip            : 2;  /**< [ 26: 25](R/W) TOAQH flip syndrome bits on write. */
        uint64_t toaqh_cdis            : 1;  /**< [ 24: 24](R/W) TOAQH ECC correction disable. */
        uint64_t tiaqt_flip            : 2;  /**< [ 23: 22](R/W) TIAQT flip syndrome bits on write. */
        uint64_t tiaqt_cdis            : 1;  /**< [ 21: 21](R/W) TIAQT ECC correction disable. */
        uint64_t tiaqh_flip            : 2;  /**< [ 20: 19](R/W) TIAQH flip syndrome bits on write. */
        uint64_t tiaqh_cdis            : 1;  /**< [ 18: 18](R/W) TIAQH ECC correction disable. */
        uint64_t llm_flip              : 2;  /**< [ 17: 16](R/W) LLM flip syndrome bits on write. */
        uint64_t llm_cdis              : 1;  /**< [ 15: 15](R/W) LLM ECC correction disable. */
        uint64_t inp_flip              : 2;  /**< [ 14: 13](R/W) INP flip syndrome bits on write. */
        uint64_t inp_cdis              : 1;  /**< [ 12: 12](R/W) INP ECC correction disable. */
        uint64_t qtc_flip              : 2;  /**< [ 11: 10](R/W) QTC flip syndrome bits on write. */
        uint64_t qtc_cdis              : 1;  /**< [  9:  9](R/W) QTC ECC correction disable. */
        uint64_t xaq_flip              : 2;  /**< [  8:  7](R/W) XAQ flip syndrome bits on write. */
        uint64_t xaq_cdis              : 1;  /**< [  6:  6](R/W) XAQ ECC correction disable. */
        uint64_t fff_flip              : 2;  /**< [  5:  4](R/W) FFF flip syndrome bits on write. */
        uint64_t fff_cdis              : 1;  /**< [  3:  3](R/W) FFF ECC correction disable. */
        uint64_t wes_flip              : 2;  /**< [  2:  1](R/W) WES flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t wes_cdis              : 1;  /**< [  0:  0](R/W) WES ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t wes_cdis              : 1;  /**< [  0:  0](R/W) WES ECC correction disable. */
        uint64_t wes_flip              : 2;  /**< [  2:  1](R/W) WES flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t fff_cdis              : 1;  /**< [  3:  3](R/W) FFF ECC correction disable. */
        uint64_t fff_flip              : 2;  /**< [  5:  4](R/W) FFF flip syndrome bits on write. */
        uint64_t xaq_cdis              : 1;  /**< [  6:  6](R/W) XAQ ECC correction disable. */
        uint64_t xaq_flip              : 2;  /**< [  8:  7](R/W) XAQ flip syndrome bits on write. */
        uint64_t qtc_cdis              : 1;  /**< [  9:  9](R/W) QTC ECC correction disable. */
        uint64_t qtc_flip              : 2;  /**< [ 11: 10](R/W) QTC flip syndrome bits on write. */
        uint64_t inp_cdis              : 1;  /**< [ 12: 12](R/W) INP ECC correction disable. */
        uint64_t inp_flip              : 2;  /**< [ 14: 13](R/W) INP flip syndrome bits on write. */
        uint64_t llm_cdis              : 1;  /**< [ 15: 15](R/W) LLM ECC correction disable. */
        uint64_t llm_flip              : 2;  /**< [ 17: 16](R/W) LLM flip syndrome bits on write. */
        uint64_t tiaqh_cdis            : 1;  /**< [ 18: 18](R/W) TIAQH ECC correction disable. */
        uint64_t tiaqh_flip            : 2;  /**< [ 20: 19](R/W) TIAQH flip syndrome bits on write. */
        uint64_t tiaqt_cdis            : 1;  /**< [ 21: 21](R/W) TIAQT ECC correction disable. */
        uint64_t tiaqt_flip            : 2;  /**< [ 23: 22](R/W) TIAQT flip syndrome bits on write. */
        uint64_t toaqh_cdis            : 1;  /**< [ 24: 24](R/W) TOAQH ECC correction disable. */
        uint64_t toaqh_flip            : 2;  /**< [ 26: 25](R/W) TOAQH flip syndrome bits on write. */
        uint64_t toaqt_cdis            : 1;  /**< [ 27: 27](R/W) TOAQT ECC correction disable. */
        uint64_t toaqt_flip            : 2;  /**< [ 29: 28](R/W) TOAQT flip syndrome bits on write. */
        uint64_t memmgt_cdis           : 1;  /**< [ 30: 30](R/W) MEMMGT ECC correction disable. */
        uint64_t memmgt_flip           : 2;  /**< [ 32: 31](R/W) MEMMGT flip syndrome bits on write. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ecc_ctl0_s cn; */
} bdk_sso_ecc_ctl0_t;

#define BDK_SSO_ECC_CTL0 BDK_SSO_ECC_CTL0_FUNC()
static inline uint64_t BDK_SSO_ECC_CTL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ECC_CTL0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001280ll;
    __bdk_csr_fatal("SSO_ECC_CTL0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ECC_CTL0 bdk_sso_ecc_ctl0_t
#define bustype_BDK_SSO_ECC_CTL0 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ECC_CTL0 "SSO_ECC_CTL0"
#define device_bar_BDK_SSO_ECC_CTL0 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ECC_CTL0 0
#define arguments_BDK_SSO_ECC_CTL0 -1,-1,-1,-1

/**
 * Register (NCB) sso_ecc_ctl1
 *
 * SSO ECC Control 1 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ecc_ctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t mbox_mem_flip         : 2;  /**< [ 23: 22](R/W) MBOX_MEM flip syndrome bits on write. */
        uint64_t mbox_mem_cdis         : 1;  /**< [ 21: 21](R/W) MBOX_MEM ECC correction disable. */
        uint64_t thrint_flip           : 2;  /**< [ 20: 19](R/W) THRINT flip syndrome bits on write. */
        uint64_t thrint_cdis           : 1;  /**< [ 18: 18](R/W) THRINT ECC correction disable. */
        uint64_t mask_flip             : 2;  /**< [ 17: 16](R/W) MASK flip syndrome bits on write. */
        uint64_t mask_cdis             : 1;  /**< [ 15: 15](R/W) MASK ECC correction disable. */
        uint64_t gdw_flip              : 2;  /**< [ 14: 13](R/W) GDW flip syndrome bits on write. */
        uint64_t gdw_cdis              : 1;  /**< [ 12: 12](R/W) GDW ECC correction disable. */
        uint64_t qidx_flip             : 2;  /**< [ 11: 10](R/W) QIDX flip syndrome bits on write. */
        uint64_t qidx_cdis             : 1;  /**< [  9:  9](R/W) QIDX ECC correction disable. */
        uint64_t tptr_flip             : 2;  /**< [  8:  7](R/W) TPTR flip syndrome bits on write. */
        uint64_t tptr_cdis             : 1;  /**< [  6:  6](R/W) TPTR ECC correction disable. */
        uint64_t hptr_flip             : 2;  /**< [  5:  4](R/W) HPTR flip syndrome bits on write. */
        uint64_t hptr_cdis             : 1;  /**< [  3:  3](R/W) HPTR ECC correction disable. */
        uint64_t cntr_flip             : 2;  /**< [  2:  1](R/W) CNTR flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t cntr_cdis             : 1;  /**< [  0:  0](R/W) CNTR ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_cdis             : 1;  /**< [  0:  0](R/W) CNTR ECC correction disable. */
        uint64_t cntr_flip             : 2;  /**< [  2:  1](R/W) CNTR flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t hptr_cdis             : 1;  /**< [  3:  3](R/W) HPTR ECC correction disable. */
        uint64_t hptr_flip             : 2;  /**< [  5:  4](R/W) HPTR flip syndrome bits on write. */
        uint64_t tptr_cdis             : 1;  /**< [  6:  6](R/W) TPTR ECC correction disable. */
        uint64_t tptr_flip             : 2;  /**< [  8:  7](R/W) TPTR flip syndrome bits on write. */
        uint64_t qidx_cdis             : 1;  /**< [  9:  9](R/W) QIDX ECC correction disable. */
        uint64_t qidx_flip             : 2;  /**< [ 11: 10](R/W) QIDX flip syndrome bits on write. */
        uint64_t gdw_cdis              : 1;  /**< [ 12: 12](R/W) GDW ECC correction disable. */
        uint64_t gdw_flip              : 2;  /**< [ 14: 13](R/W) GDW flip syndrome bits on write. */
        uint64_t mask_cdis             : 1;  /**< [ 15: 15](R/W) MASK ECC correction disable. */
        uint64_t mask_flip             : 2;  /**< [ 17: 16](R/W) MASK flip syndrome bits on write. */
        uint64_t thrint_cdis           : 1;  /**< [ 18: 18](R/W) THRINT ECC correction disable. */
        uint64_t thrint_flip           : 2;  /**< [ 20: 19](R/W) THRINT flip syndrome bits on write. */
        uint64_t mbox_mem_cdis         : 1;  /**< [ 21: 21](R/W) MBOX_MEM ECC correction disable. */
        uint64_t mbox_mem_flip         : 2;  /**< [ 23: 22](R/W) MBOX_MEM flip syndrome bits on write. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ecc_ctl1_s cn; */
} bdk_sso_ecc_ctl1_t;

#define BDK_SSO_ECC_CTL1 BDK_SSO_ECC_CTL1_FUNC()
static inline uint64_t BDK_SSO_ECC_CTL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ECC_CTL1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001288ll;
    __bdk_csr_fatal("SSO_ECC_CTL1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ECC_CTL1 bdk_sso_ecc_ctl1_t
#define bustype_BDK_SSO_ECC_CTL1 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ECC_CTL1 "SSO_ECC_CTL1"
#define device_bar_BDK_SSO_ECC_CTL1 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ECC_CTL1 0
#define arguments_BDK_SSO_ECC_CTL1 -1,-1,-1,-1

/**
 * Register (NCB) sso_ecc_ctl2
 *
 * SSO ECC Control 2 Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ecc_ctl2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t pcc_flip              : 2;  /**< [ 17: 16](R/W) PCC flip syndrome bits on write. */
        uint64_t pcc_cdis              : 1;  /**< [ 15: 15](R/W) PCC ECC correction disable. */
        uint64_t ncbo_flip             : 2;  /**< [ 14: 13](R/W) NCBO flip syndrome bits on write. */
        uint64_t ncbo_cdis             : 1;  /**< [ 12: 12](R/W) NCBO ECC correction disable. */
        uint64_t pnd_flip              : 2;  /**< [ 11: 10](R/W) PND flip syndrome bits on write. */
        uint64_t pnd_cdis              : 1;  /**< [  9:  9](R/W) PND ECC correction disable. */
        uint64_t oth_flip              : 2;  /**< [  8:  7](R/W) OTH flip syndrome bits on write. */
        uint64_t oth_cdis              : 1;  /**< [  6:  6](R/W) OTH ECC correction disable. */
        uint64_t nidx_flip             : 2;  /**< [  5:  4](R/W) NIDX flip syndrome bits on write. */
        uint64_t nidx_cdis             : 1;  /**< [  3:  3](R/W) NIDX ECC correction disable. */
        uint64_t pidx_flip             : 2;  /**< [  2:  1](R/W) PIDX flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t pidx_cdis             : 1;  /**< [  0:  0](R/W) PIDX ECC correction disable. */
#else /* Word 0 - Little Endian */
        uint64_t pidx_cdis             : 1;  /**< [  0:  0](R/W) PIDX ECC correction disable. */
        uint64_t pidx_flip             : 2;  /**< [  2:  1](R/W) PIDX flip syndrome bits on write. Flip syndrome bits <1:0> on writes to the ram to test
                                                                 single-bit or double-bit error handling. */
        uint64_t nidx_cdis             : 1;  /**< [  3:  3](R/W) NIDX ECC correction disable. */
        uint64_t nidx_flip             : 2;  /**< [  5:  4](R/W) NIDX flip syndrome bits on write. */
        uint64_t oth_cdis              : 1;  /**< [  6:  6](R/W) OTH ECC correction disable. */
        uint64_t oth_flip              : 2;  /**< [  8:  7](R/W) OTH flip syndrome bits on write. */
        uint64_t pnd_cdis              : 1;  /**< [  9:  9](R/W) PND ECC correction disable. */
        uint64_t pnd_flip              : 2;  /**< [ 11: 10](R/W) PND flip syndrome bits on write. */
        uint64_t ncbo_cdis             : 1;  /**< [ 12: 12](R/W) NCBO ECC correction disable. */
        uint64_t ncbo_flip             : 2;  /**< [ 14: 13](R/W) NCBO flip syndrome bits on write. */
        uint64_t pcc_cdis              : 1;  /**< [ 15: 15](R/W) PCC ECC correction disable. */
        uint64_t pcc_flip              : 2;  /**< [ 17: 16](R/W) PCC flip syndrome bits on write. */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ecc_ctl2_s cn; */
} bdk_sso_ecc_ctl2_t;

#define BDK_SSO_ECC_CTL2 BDK_SSO_ECC_CTL2_FUNC()
static inline uint64_t BDK_SSO_ECC_CTL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ECC_CTL2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001290ll;
    __bdk_csr_fatal("SSO_ECC_CTL2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ECC_CTL2 bdk_sso_ecc_ctl2_t
#define bustype_BDK_SSO_ECC_CTL2 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ECC_CTL2 "SSO_ECC_CTL2"
#define device_bar_BDK_SSO_ECC_CTL2 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ECC_CTL2 0
#define arguments_BDK_SSO_ECC_CTL2 -1,-1,-1,-1

/**
 * Register (NCB) sso_err0
 *
 * SSO Error 0 Register
 * This register contains ECC and other miscellaneous error bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1C/H) Double-bit error for MEMMGT RAM. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1C/H) Single-bit error for MEMMGT RAM. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Double-bit error for TOAQT RAM. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Single-bit error for TOAQT RAM. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Double-bit error for TOAQH RAM. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Single-bit error for TOAQH RAM. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Double-bit error for TIAQT RAM. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Single-bit error for TIAQT RAM. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Double-bit error for TIAQH RAM. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Single-bit error for TIAQH RAM. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for LLM RAM. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for LLM RAM. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for INP RAM. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for INP RAM. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for QTC RAM. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for QTC RAM. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for XAQ RAM. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for XAQ RAM. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for  RAM. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for  RAM. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for WES RAM. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for WES RAM. */
        uint64_t reserved_9_31         : 23;
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1C/H) Coprocessor add-work dropped due to SSO_PF_MAP() having a double hit. When a
                                                                 request thus dropped, even if this bit is already set, SSO_UNMAP_INFO is loaded. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1C/H) Coprocessor add-work dropped due to that coprocessor requesting with GMID not
                                                                 mapped in SSO_PF_MAP(). When a request thus dropped, even if this bit is already
                                                                 set, SSO_UNMAP_INFO is loaded. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1C/H) Coprocessor add-work dropped due to that coprocessor requesting with
                                                                 GMID=0x0. See PKI_QPG_TBLB()[GMID], TIM_RING()_GMCTL[GMID], and other GMID
                                                                 registers. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1C/H) Add work dropped due to wrong command/DID requested. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1C/H) Received add work with tag specified as EMPTY. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1C/H) Add work to disabled group. An ADDWQ was received and dropped to a group with
                                                                 SSO_GRP()_IAQ_THR[RSVD_THR] = 0. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Bad-fill-packet error. The WAE VLD_CRC field was incorrect, or the XAQ next address was
                                                                 zero. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1C/H) Out-of-memory error. (ADDWQ request is dropped.) */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Free-page error. The free page error bit asserts when a new FPA page is requested and FPA
                                                                 indicates there are no remaining free pages. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Free-page error. The free page error bit asserts when a new FPA page is requested and FPA
                                                                 indicates there are no remaining free pages. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1C/H) Out-of-memory error. (ADDWQ request is dropped.) */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Bad-fill-packet error. The WAE VLD_CRC field was incorrect, or the XAQ next address was
                                                                 zero. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1C/H) Add work to disabled group. An ADDWQ was received and dropped to a group with
                                                                 SSO_GRP()_IAQ_THR[RSVD_THR] = 0. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1C/H) Received add work with tag specified as EMPTY. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1C/H) Add work dropped due to wrong command/DID requested. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1C/H) Coprocessor add-work dropped due to that coprocessor requesting with
                                                                 GMID=0x0. See PKI_QPG_TBLB()[GMID], TIM_RING()_GMCTL[GMID], and other GMID
                                                                 registers. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1C/H) Coprocessor add-work dropped due to that coprocessor requesting with GMID not
                                                                 mapped in SSO_PF_MAP(). When a request thus dropped, even if this bit is already
                                                                 set, SSO_UNMAP_INFO is loaded. */
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1C/H) Coprocessor add-work dropped due to SSO_PF_MAP() having a double hit. When a
                                                                 request thus dropped, even if this bit is already set, SSO_UNMAP_INFO is loaded. */
        uint64_t reserved_9_31         : 23;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for WES RAM. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for WES RAM. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for  RAM. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for  RAM. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for XAQ RAM. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for XAQ RAM. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for QTC RAM. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for QTC RAM. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for INP RAM. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for INP RAM. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for LLM RAM. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for LLM RAM. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Single-bit error for TIAQH RAM. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Double-bit error for TIAQH RAM. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Single-bit error for TIAQT RAM. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Double-bit error for TIAQT RAM. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Single-bit error for TOAQH RAM. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Double-bit error for TOAQH RAM. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Single-bit error for TOAQT RAM. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Double-bit error for TOAQT RAM. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1C/H) Single-bit error for MEMMGT RAM. */
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1C/H) Double-bit error for MEMMGT RAM. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err0_s cn; */
} bdk_sso_err0_t;

#define BDK_SSO_ERR0 BDK_SSO_ERR0_FUNC()
static inline uint64_t BDK_SSO_ERR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR0_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001220ll;
    __bdk_csr_fatal("SSO_ERR0", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR0 bdk_sso_err0_t
#define bustype_BDK_SSO_ERR0 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR0 "SSO_ERR0"
#define device_bar_BDK_SSO_ERR0 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR0 0
#define arguments_BDK_SSO_ERR0 -1,-1,-1,-1

/**
 * Register (NCB) sso_err0_ena_w1c
 *
 * SSO Error 0 Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err0_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for SSO_ERR0[MEMMGT_DBE]. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for SSO_ERR0[MEMMGT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_DBE]. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_SBE]. */
        uint64_t reserved_9_31         : 23;
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID0]. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR0[AWEMPTY]. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR0[GRPDIS]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR0[BFP]. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR0[AWE]. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR0[FPE]. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR0[FPE]. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR0[AWE]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR0[BFP]. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR0[GRPDIS]. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR0[AWEMPTY]. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID0]. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t reserved_9_31         : 23;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR0[WES_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR0[FFF_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR0[QTC_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR0[INP_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR0[LLM_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1C/H) Reads or clears enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1C/H) Reads or clears enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1C/H) Reads or clears enable for SSO_ERR0[MEMMGT_SBE]. */
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1C/H) Reads or clears enable for SSO_ERR0[MEMMGT_DBE]. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err0_ena_w1c_s cn; */
} bdk_sso_err0_ena_w1c_t;

#define BDK_SSO_ERR0_ENA_W1C BDK_SSO_ERR0_ENA_W1C_FUNC()
static inline uint64_t BDK_SSO_ERR0_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR0_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001230ll;
    __bdk_csr_fatal("SSO_ERR0_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR0_ENA_W1C bdk_sso_err0_ena_w1c_t
#define bustype_BDK_SSO_ERR0_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR0_ENA_W1C "SSO_ERR0_ENA_W1C"
#define device_bar_BDK_SSO_ERR0_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR0_ENA_W1C 0
#define arguments_BDK_SSO_ERR0_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) sso_err0_ena_w1s
 *
 * SSO Error 0 Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err0_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for SSO_ERR0[MEMMGT_DBE]. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for SSO_ERR0[MEMMGT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_DBE]. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_SBE]. */
        uint64_t reserved_9_31         : 23;
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID0]. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR0[AWEMPTY]. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR0[GRPDIS]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR0[BFP]. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR0[AWE]. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR0[FPE]. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR0[FPE]. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR0[AWE]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR0[BFP]. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR0[GRPDIS]. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR0[AWEMPTY]. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID0]. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR0[GMID_MULTI]. */
        uint64_t reserved_9_31         : 23;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR0[WES_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR0[FFF_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR0[XAQ_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR0[QTC_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR0[INP_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR0[LLM_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets enable for SSO_ERR0[TIAQT_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets enable for SSO_ERR0[TOAQT_DBE]. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets enable for SSO_ERR0[MEMMGT_SBE]. */
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets enable for SSO_ERR0[MEMMGT_DBE]. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err0_ena_w1s_s cn; */
} bdk_sso_err0_ena_w1s_t;

#define BDK_SSO_ERR0_ENA_W1S BDK_SSO_ERR0_ENA_W1S_FUNC()
static inline uint64_t BDK_SSO_ERR0_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR0_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001238ll;
    __bdk_csr_fatal("SSO_ERR0_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR0_ENA_W1S bdk_sso_err0_ena_w1s_t
#define bustype_BDK_SSO_ERR0_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR0_ENA_W1S "SSO_ERR0_ENA_W1S"
#define device_bar_BDK_SSO_ERR0_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR0_ENA_W1S 0
#define arguments_BDK_SSO_ERR0_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err0_w1s
 *
 * SSO Error 0 Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err0_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets SSO_ERR0[MEMMGT_DBE]. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets SSO_ERR0[MEMMGT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR0[LLM_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR0[LLM_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR0[INP_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR0[INP_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR0[QTC_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR0[QTC_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR0[XAQ_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR0[XAQ_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR0[FFF_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR0[FFF_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR0[WES_DBE]. */
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR0[WES_SBE]. */
        uint64_t reserved_9_31         : 23;
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR0[GMID_MULTI]. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR0[GMID0]. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR0[AWEMPTY]. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR0[GRPDIS]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR0[BFP]. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR0[AWE]. */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR0[FPE]. */
#else /* Word 0 - Little Endian */
        uint64_t fpe                   : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR0[FPE]. */
        uint64_t awe                   : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR0[AWE]. */
        uint64_t bfp                   : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR0[BFP]. */
        uint64_t grpdis                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR0[GRPDIS]. */
        uint64_t awempty               : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR0[AWEMPTY]. */
        uint64_t addwq_dropped         : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR0[ADDWQ_DROPPED]. */
        uint64_t gmid0                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR0[GMID0]. */
        uint64_t gmid_unmap            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR0[GMID_UNMAP]. */
        uint64_t gmid_multi            : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR0[GMID_MULTI]. */
        uint64_t reserved_9_31         : 23;
        uint64_t wes_sbe               : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR0[WES_SBE]. */
        uint64_t wes_dbe               : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR0[WES_DBE]. */
        uint64_t fff_sbe               : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR0[FFF_SBE]. */
        uint64_t fff_dbe               : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR0[FFF_DBE]. */
        uint64_t xaq_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR0[XAQ_SBE]. */
        uint64_t xaq_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR0[XAQ_DBE]. */
        uint64_t qtc_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR0[QTC_SBE]. */
        uint64_t qtc_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR0[QTC_DBE]. */
        uint64_t inp_sbe               : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR0[INP_SBE]. */
        uint64_t inp_dbe               : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR0[INP_DBE]. */
        uint64_t llm_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR0[LLM_SBE]. */
        uint64_t llm_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR0[LLM_DBE]. */
        uint64_t tiaqh_sbe             : 1;  /**< [ 44: 44](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_SBE]. */
        uint64_t tiaqh_dbe             : 1;  /**< [ 45: 45](R/W1S/H) Reads or sets SSO_ERR0[TIAQH_DBE]. */
        uint64_t tiaqt_sbe             : 1;  /**< [ 46: 46](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_SBE]. */
        uint64_t tiaqt_dbe             : 1;  /**< [ 47: 47](R/W1S/H) Reads or sets SSO_ERR0[TIAQT_DBE]. */
        uint64_t toaqh_sbe             : 1;  /**< [ 48: 48](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_SBE]. */
        uint64_t toaqh_dbe             : 1;  /**< [ 49: 49](R/W1S/H) Reads or sets SSO_ERR0[TOAQH_DBE]. */
        uint64_t toaqt_sbe             : 1;  /**< [ 50: 50](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_SBE]. */
        uint64_t toaqt_dbe             : 1;  /**< [ 51: 51](R/W1S/H) Reads or sets SSO_ERR0[TOAQT_DBE]. */
        uint64_t memmgt_sbe            : 1;  /**< [ 52: 52](R/W1S/H) Reads or sets SSO_ERR0[MEMMGT_SBE]. */
        uint64_t memmgt_dbe            : 1;  /**< [ 53: 53](R/W1S/H) Reads or sets SSO_ERR0[MEMMGT_DBE]. */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err0_w1s_s cn; */
} bdk_sso_err0_w1s_t;

#define BDK_SSO_ERR0_W1S BDK_SSO_ERR0_W1S_FUNC()
static inline uint64_t BDK_SSO_ERR0_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR0_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001228ll;
    __bdk_csr_fatal("SSO_ERR0_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR0_W1S bdk_sso_err0_w1s_t
#define bustype_BDK_SSO_ERR0_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR0_W1S "SSO_ERR0_W1S"
#define device_bar_BDK_SSO_ERR0_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR0_W1S 0
#define arguments_BDK_SSO_ERR0_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err1
 *
 * SSO Error 1 Register
 * This register contains ECC and other miscellaneous error bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Double-bit error for MBOX_MEM RAM. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Single-bit error for MBOX_MEM RAM. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Double-bit error for THRINT RAM. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Single-bit error for THRINT RAM. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Double-bit error for MASK RAM. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Single-bit error for MASK RAM. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Double-bit error for GDW RAM. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Single-bit error for GDW RAM. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Double-bit error for QIDX RAM. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Single-bit error for QIDX RAM. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Double-bit error for TPTR RAM. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Single-bit error for TPTR RAM. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Double-bit error for HPTR RAM. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Single-bit error for HPTR RAM. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Double-bit error for CNTR RAM. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Single-bit error for CNTR RAM. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Single-bit error for CNTR RAM. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Double-bit error for CNTR RAM. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Single-bit error for HPTR RAM. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Double-bit error for HPTR RAM. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Single-bit error for TPTR RAM. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Double-bit error for TPTR RAM. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Single-bit error for QIDX RAM. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Double-bit error for QIDX RAM. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Single-bit error for GDW RAM. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Double-bit error for GDW RAM. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Single-bit error for MASK RAM. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Double-bit error for MASK RAM. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Single-bit error for THRINT RAM. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Double-bit error for THRINT RAM. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Single-bit error for MBOX_MEM RAM. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Double-bit error for MBOX_MEM RAM. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err1_s cn; */
} bdk_sso_err1_t;

#define BDK_SSO_ERR1 BDK_SSO_ERR1_FUNC()
static inline uint64_t BDK_SSO_ERR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR1_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001240ll;
    __bdk_csr_fatal("SSO_ERR1", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR1 bdk_sso_err1_t
#define bustype_BDK_SSO_ERR1 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR1 "SSO_ERR1"
#define device_bar_BDK_SSO_ERR1 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR1 0
#define arguments_BDK_SSO_ERR1 -1,-1,-1,-1

/**
 * Register (NCB) sso_err1_ena_w1c
 *
 * SSO Error 1 Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err1_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SSO_ERR1[GDW_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SSO_ERR1[MASK_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err1_ena_w1c_s cn; */
} bdk_sso_err1_ena_w1c_t;

#define BDK_SSO_ERR1_ENA_W1C BDK_SSO_ERR1_ENA_W1C_FUNC()
static inline uint64_t BDK_SSO_ERR1_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR1_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001250ll;
    __bdk_csr_fatal("SSO_ERR1_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR1_ENA_W1C bdk_sso_err1_ena_w1c_t
#define bustype_BDK_SSO_ERR1_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR1_ENA_W1C "SSO_ERR1_ENA_W1C"
#define device_bar_BDK_SSO_ERR1_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR1_ENA_W1C 0
#define arguments_BDK_SSO_ERR1_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) sso_err1_ena_w1s
 *
 * SSO Error 1 Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err1_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_ERR1[CNTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_ERR1[HPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SSO_ERR1[TPTR_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SSO_ERR1[QIDX_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SSO_ERR1[GDW_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SSO_ERR1[MASK_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for SSO_ERR1[THRINT_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err1_ena_w1s_s cn; */
} bdk_sso_err1_ena_w1s_t;

#define BDK_SSO_ERR1_ENA_W1S BDK_SSO_ERR1_ENA_W1S_FUNC()
static inline uint64_t BDK_SSO_ERR1_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR1_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001258ll;
    __bdk_csr_fatal("SSO_ERR1_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR1_ENA_W1S bdk_sso_err1_ena_w1s_t
#define bustype_BDK_SSO_ERR1_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR1_ENA_W1S "SSO_ERR1_ENA_W1S"
#define device_bar_BDK_SSO_ERR1_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR1_ENA_W1S 0
#define arguments_BDK_SSO_ERR1_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err1_w1s
 *
 * SSO Error 1 Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err1_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets SSO_ERR1[THRINT_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets SSO_ERR1[THRINT_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SSO_ERR1[MASK_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SSO_ERR1[MASK_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SSO_ERR1[GDW_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR1[GDW_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR1[QIDX_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR1[QIDX_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR1[TPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR1[TPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR1[HPTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR1[HPTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR1[CNTR_DBE]. */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR1[CNTR_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t cntr_sbe              : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_ERR1[CNTR_SBE]. */
        uint64_t cntr_dbe              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_ERR1[CNTR_DBE]. */
        uint64_t hptr_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_ERR1[HPTR_SBE]. */
        uint64_t hptr_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_ERR1[HPTR_DBE]. */
        uint64_t tptr_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SSO_ERR1[TPTR_SBE]. */
        uint64_t tptr_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SSO_ERR1[TPTR_DBE]. */
        uint64_t qidx_sbe              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SSO_ERR1[QIDX_SBE]. */
        uint64_t qidx_dbe              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SSO_ERR1[QIDX_DBE]. */
        uint64_t gdw_sbe               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SSO_ERR1[GDW_SBE]. */
        uint64_t gdw_dbe               : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SSO_ERR1[GDW_DBE]. */
        uint64_t mask_sbe              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SSO_ERR1[MASK_SBE]. */
        uint64_t mask_dbe              : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SSO_ERR1[MASK_DBE]. */
        uint64_t thrint_sbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets SSO_ERR1[THRINT_SBE]. */
        uint64_t thrint_dbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets SSO_ERR1[THRINT_DBE]. */
        uint64_t mbox_mem_sbe          : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_SBE]. */
        uint64_t mbox_mem_dbe          : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets SSO_ERR1[MBOX_MEM_DBE]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err1_w1s_s cn; */
} bdk_sso_err1_w1s_t;

#define BDK_SSO_ERR1_W1S BDK_SSO_ERR1_W1S_FUNC()
static inline uint64_t BDK_SSO_ERR1_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR1_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001248ll;
    __bdk_csr_fatal("SSO_ERR1_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR1_W1S bdk_sso_err1_w1s_t
#define bustype_BDK_SSO_ERR1_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR1_W1S "SSO_ERR1_W1S"
#define device_bar_BDK_SSO_ERR1_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR1_W1S 0
#define arguments_BDK_SSO_ERR1_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err2
 *
 * SSO Error 2 Register
 * This register contains ECC and other miscellaneous error bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for PCC RAM. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for PCC RAM. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for NCBO RAM. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for NCBO RAM. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for PND RAM. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for PND RAM. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for odd OTH RAM. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for odd OTH RAM. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for IDX RAM. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for IDX RAM. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for FIDX RAM. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for FIDX RAM. */
        uint64_t reserved_13_31        : 19;
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1C/H) Illegal operation errors:
                                                                 <12> = Received command before SSO_RESET[BUSY] cleared.
                                                                 <11> = Reserved.
                                                                 <10> = Reserved.
                                                                 <9> = Received illegal opcode.
                                                                 <8> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE from work
                                                                 slot with CLR_NSCHED pending.
                                                                 <7> = Received CLR_NSCHED from work slot with SWTAG_DESCH/DESCH/CLR_NSCHED pending.
                                                                 <6> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with ALLOC_WE pending.
                                                                 <5> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with GET_WORK pending.
                                                                 <4> = Received SWTAG_FULL/SWTAG_DESCH with tag specified as UNTAGGED.
                                                                 <3> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH with tag specified as EMPTY.
                                                                 <2> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/GET_WORK from work slot with pending tag
                                                                 switch to ORDERED or ATOMIC.
                                                                 <1> = Received SWTAG/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in UNTAGGED state.
                                                                 <0> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in EMPTY
                                                                 state. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1C/H) Illegal operation errors:
                                                                 <12> = Received command before SSO_RESET[BUSY] cleared.
                                                                 <11> = Reserved.
                                                                 <10> = Reserved.
                                                                 <9> = Received illegal opcode.
                                                                 <8> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE from work
                                                                 slot with CLR_NSCHED pending.
                                                                 <7> = Received CLR_NSCHED from work slot with SWTAG_DESCH/DESCH/CLR_NSCHED pending.
                                                                 <6> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with ALLOC_WE pending.
                                                                 <5> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP/GET_WORK/ALLOC_WE/CLR_NSCHED
                                                                 from work slot with GET_WORK pending.
                                                                 <4> = Received SWTAG_FULL/SWTAG_DESCH with tag specified as UNTAGGED.
                                                                 <3> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH with tag specified as EMPTY.
                                                                 <2> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/GET_WORK from work slot with pending tag
                                                                 switch to ORDERED or ATOMIC.
                                                                 <1> = Received SWTAG/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in UNTAGGED state.
                                                                 <0> = Received SWTAG/SWTAG_FULL/SWTAG_DESCH/DESCH/UPD_WQP_GRP from work slot in EMPTY
                                                                 state. */
        uint64_t reserved_13_31        : 19;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Single-bit error for FIDX RAM. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Double-bit error for FIDX RAM. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Single-bit error for IDX RAM. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Double-bit error for IDX RAM. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Single-bit error for odd OTH RAM. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Double-bit error for odd OTH RAM. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Single-bit error for PND RAM. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Double-bit error for PND RAM. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Single-bit error for NCBO RAM. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Double-bit error for NCBO RAM. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Single-bit error for PCC RAM. */
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Double-bit error for PCC RAM. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err2_s cn; */
} bdk_sso_err2_t;

#define BDK_SSO_ERR2 BDK_SSO_ERR2_FUNC()
static inline uint64_t BDK_SSO_ERR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR2_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001260ll;
    __bdk_csr_fatal("SSO_ERR2", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR2 bdk_sso_err2_t
#define bustype_BDK_SSO_ERR2 BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR2 "SSO_ERR2"
#define device_bar_BDK_SSO_ERR2 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR2 0
#define arguments_BDK_SSO_ERR2 -1,-1,-1,-1

/**
 * Register (NCB) sso_err2_ena_w1c
 *
 * SSO Error 2 Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err2_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t reserved_13_31        : 19;
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1C/H) Reads or clears enable for SSO_ERR2[IOP]. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1C/H) Reads or clears enable for SSO_ERR2[IOP]. */
        uint64_t reserved_13_31        : 19;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for SSO_ERR2[OTH_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for SSO_ERR2[PND_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1C/H) Reads or clears enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_SBE]. */
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1C/H) Reads or clears enable for SSO_ERR2[PCC_DBE]. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err2_ena_w1c_s cn; */
} bdk_sso_err2_ena_w1c_t;

#define BDK_SSO_ERR2_ENA_W1C BDK_SSO_ERR2_ENA_W1C_FUNC()
static inline uint64_t BDK_SSO_ERR2_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR2_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001270ll;
    __bdk_csr_fatal("SSO_ERR2_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR2_ENA_W1C bdk_sso_err2_ena_w1c_t
#define bustype_BDK_SSO_ERR2_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR2_ENA_W1C "SSO_ERR2_ENA_W1C"
#define device_bar_BDK_SSO_ERR2_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR2_ENA_W1C 0
#define arguments_BDK_SSO_ERR2_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) sso_err2_ena_w1s
 *
 * SSO Error 2 Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err2_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t reserved_13_31        : 19;
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1S/H) Reads or sets enable for SSO_ERR2[IOP]. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1S/H) Reads or sets enable for SSO_ERR2[IOP]. */
        uint64_t reserved_13_31        : 19;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for SSO_ERR2[PIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for SSO_ERR2[NIDX_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for SSO_ERR2[OTH_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for SSO_ERR2[PND_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets enable for SSO_ERR2[NCBO_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_SBE]. */
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets enable for SSO_ERR2[PCC_DBE]. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err2_ena_w1s_s cn; */
} bdk_sso_err2_ena_w1s_t;

#define BDK_SSO_ERR2_ENA_W1S BDK_SSO_ERR2_ENA_W1S_FUNC()
static inline uint64_t BDK_SSO_ERR2_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR2_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001278ll;
    __bdk_csr_fatal("SSO_ERR2_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR2_ENA_W1S bdk_sso_err2_ena_w1s_t
#define bustype_BDK_SSO_ERR2_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR2_ENA_W1S "SSO_ERR2_ENA_W1S"
#define device_bar_BDK_SSO_ERR2_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR2_ENA_W1S 0
#define arguments_BDK_SSO_ERR2_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_err2_w1s
 *
 * SSO Error 2 Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_err2_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR2[PCC_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR2[PCC_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR2[NCBO_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR2[NCBO_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR2[PND_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR2[PND_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR2[OTH_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR2[OTH_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR2[NIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR2[NIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR2[PIDX_DBE]. */
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR2[PIDX_SBE]. */
        uint64_t reserved_13_31        : 19;
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1S/H) Reads or sets SSO_ERR2[IOP]. */
#else /* Word 0 - Little Endian */
        uint64_t iop                   : 13; /**< [ 12:  0](R/W1S/H) Reads or sets SSO_ERR2[IOP]. */
        uint64_t reserved_13_31        : 19;
        uint64_t pidx_sbe              : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets SSO_ERR2[PIDX_SBE]. */
        uint64_t pidx_dbe              : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets SSO_ERR2[PIDX_DBE]. */
        uint64_t nidx_sbe              : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets SSO_ERR2[NIDX_SBE]. */
        uint64_t nidx_dbe              : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets SSO_ERR2[NIDX_DBE]. */
        uint64_t oth_sbe               : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets SSO_ERR2[OTH_SBE]. */
        uint64_t oth_dbe               : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets SSO_ERR2[OTH_DBE]. */
        uint64_t pnd_sbe               : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets SSO_ERR2[PND_SBE]. */
        uint64_t pnd_dbe               : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets SSO_ERR2[PND_DBE]. */
        uint64_t ncbo_sbe              : 1;  /**< [ 40: 40](R/W1S/H) Reads or sets SSO_ERR2[NCBO_SBE]. */
        uint64_t ncbo_dbe              : 1;  /**< [ 41: 41](R/W1S/H) Reads or sets SSO_ERR2[NCBO_DBE]. */
        uint64_t pcc_sbe               : 1;  /**< [ 42: 42](R/W1S/H) Reads or sets SSO_ERR2[PCC_SBE]. */
        uint64_t pcc_dbe               : 1;  /**< [ 43: 43](R/W1S/H) Reads or sets SSO_ERR2[PCC_DBE]. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_err2_w1s_s cn; */
} bdk_sso_err2_w1s_t;

#define BDK_SSO_ERR2_W1S BDK_SSO_ERR2_W1S_FUNC()
static inline uint64_t BDK_SSO_ERR2_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_ERR2_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001268ll;
    __bdk_csr_fatal("SSO_ERR2_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_ERR2_W1S bdk_sso_err2_w1s_t
#define bustype_BDK_SSO_ERR2_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_ERR2_W1S "SSO_ERR2_W1S"
#define device_bar_BDK_SSO_ERR2_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_ERR2_W1S 0
#define arguments_BDK_SSO_ERR2_W1S -1,-1,-1,-1

/**
 * Register (NCB) sso_grp#_ds_pc
 *
 * SSO Deschedule Performance Counter Register
 * Counts the number of deschedule requests for each group. Counter rolls over through zero when
 * max value exceeded.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_ds_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Deschedule performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Deschedule performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_ds_pc_s cn; */
} bdk_sso_grpx_ds_pc_t;

static inline uint64_t BDK_SSO_GRPX_DS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_DS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001400ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_DS_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_DS_PC(a) bdk_sso_grpx_ds_pc_t
#define bustype_BDK_SSO_GRPX_DS_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_DS_PC(a) "SSO_GRPX_DS_PC"
#define device_bar_BDK_SSO_GRPX_DS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_DS_PC(a) (a)
#define arguments_BDK_SSO_GRPX_DS_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_ext_pc
 *
 * SSO External Schedule Performance Counter Register
 * Counts the number of cache lines of WAEs sent to L2/DDR. Counter rolls over through zero when
 * max value exceeded.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_ext_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) External admission queue cache lines written. Each write corresponds to 11 WAEs. Writes
                                                                 are for diagnostic use only, and defined only when neither work nor GET_WORKs are present
                                                                 in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) External admission queue cache lines written. Each write corresponds to 11 WAEs. Writes
                                                                 are for diagnostic use only, and defined only when neither work nor GET_WORKs are present
                                                                 in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_ext_pc_s cn; */
} bdk_sso_grpx_ext_pc_t;

static inline uint64_t BDK_SSO_GRPX_EXT_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_EXT_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001100ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_EXT_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_EXT_PC(a) bdk_sso_grpx_ext_pc_t
#define bustype_BDK_SSO_GRPX_EXT_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_EXT_PC(a) "SSO_GRPX_EXT_PC"
#define device_bar_BDK_SSO_GRPX_EXT_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_EXT_PC(a) (a)
#define arguments_BDK_SSO_GRPX_EXT_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_iaq_thr
 *
 * SSO In-unit Admission Queue Threshold Registers
 * These registers contain the thresholds for allocating SSO in-unit admission queue entries.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_iaq_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t grp_cnt               : 13; /**< [ 60: 48](RO/H) Group's entry count. Number of internal entries allocated to IAQ, conflicted work, or CQ
                                                                 in this group.

                                                                 Internal:
                                                                 Increments on admission to IAQ, decrements on scheduling into
                                                                 work slot. */
        uint64_t reserved_45_47        : 3;
        uint64_t max_thr               : 13; /**< [ 44: 32](R/W) Max threshold for this internal admission queue. If non-zero, must be >= [RSVD_THR] + 4.
                                                                 To insure full streaming performance to all cores, should be at least 208. Must not be
                                                                 changed after traffic is sent to this group. */
        uint64_t reserved_13_31        : 19;
        uint64_t rsvd_thr              : 13; /**< [ 12:  0](R/W) Reserved threshold for this internal group queue. Should be at least 1 for any groups that
                                                                 must make forward progress when other group's work is pending. Updates to this field must
                                                                 also update SSO_AW_ADD[RSVD_FREE]. Must not be changed after traffic is sent to this
                                                                 group. */
#else /* Word 0 - Little Endian */
        uint64_t rsvd_thr              : 13; /**< [ 12:  0](R/W) Reserved threshold for this internal group queue. Should be at least 1 for any groups that
                                                                 must make forward progress when other group's work is pending. Updates to this field must
                                                                 also update SSO_AW_ADD[RSVD_FREE]. Must not be changed after traffic is sent to this
                                                                 group. */
        uint64_t reserved_13_31        : 19;
        uint64_t max_thr               : 13; /**< [ 44: 32](R/W) Max threshold for this internal admission queue. If non-zero, must be >= [RSVD_THR] + 4.
                                                                 To insure full streaming performance to all cores, should be at least 208. Must not be
                                                                 changed after traffic is sent to this group. */
        uint64_t reserved_45_47        : 3;
        uint64_t grp_cnt               : 13; /**< [ 60: 48](RO/H) Group's entry count. Number of internal entries allocated to IAQ, conflicted work, or CQ
                                                                 in this group.

                                                                 Internal:
                                                                 Increments on admission to IAQ, decrements on scheduling into
                                                                 work slot. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_iaq_thr_s cn; */
} bdk_sso_grpx_iaq_thr_t;

static inline uint64_t BDK_SSO_GRPX_IAQ_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_IAQ_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000000ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_IAQ_THR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_IAQ_THR(a) bdk_sso_grpx_iaq_thr_t
#define bustype_BDK_SSO_GRPX_IAQ_THR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_IAQ_THR(a) "SSO_GRPX_IAQ_THR"
#define device_bar_BDK_SSO_GRPX_IAQ_THR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_IAQ_THR(a) (a)
#define arguments_BDK_SSO_GRPX_IAQ_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_pri
 *
 * SSO Group Priority Register
 * Controls the priority and group affinity arbitration for each group.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_pri_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t wgt_left              : 6;  /**< [ 29: 24](RO/H) Cross-group arbitration credits remaining on this group. */
        uint64_t reserved_22_23        : 2;
        uint64_t weight                : 6;  /**< [ 21: 16](R/W) Cross-group arbitration weight to apply to this group. Must be >= 0x2. */
        uint64_t reserved_12_15        : 4;
        uint64_t affinity              : 4;  /**< [ 11:  8](R/W) Processor affinity arbitration weight to apply to this group. If zero, affinity
                                                                 is disabled. A change to AFFINITY will not take effect until the old AFFINITY's
                                                                 value loaded into SSO_HWS()_ARB[AFF_LEFT] has drained to zero. */
        uint64_t reserved_3_7          : 5;
        uint64_t pri                   : 3;  /**< [  2:  0](R/W) Priority for this group relative to other groups. To prevent a HWS from receiving work on
                                                                 a group use SSO_HWS()_S()_GRPMSK().
                                                                 0x0 = highest priority.
                                                                 0x7 = lowest priority.

                                                                 Changing priority while GET_WORKs are in flight may result in a GET_WORK using either the
                                                                 old or new priority, or a mix thereof. */
#else /* Word 0 - Little Endian */
        uint64_t pri                   : 3;  /**< [  2:  0](R/W) Priority for this group relative to other groups. To prevent a HWS from receiving work on
                                                                 a group use SSO_HWS()_S()_GRPMSK().
                                                                 0x0 = highest priority.
                                                                 0x7 = lowest priority.

                                                                 Changing priority while GET_WORKs are in flight may result in a GET_WORK using either the
                                                                 old or new priority, or a mix thereof. */
        uint64_t reserved_3_7          : 5;
        uint64_t affinity              : 4;  /**< [ 11:  8](R/W) Processor affinity arbitration weight to apply to this group. If zero, affinity
                                                                 is disabled. A change to AFFINITY will not take effect until the old AFFINITY's
                                                                 value loaded into SSO_HWS()_ARB[AFF_LEFT] has drained to zero. */
        uint64_t reserved_12_15        : 4;
        uint64_t weight                : 6;  /**< [ 21: 16](R/W) Cross-group arbitration weight to apply to this group. Must be >= 0x2. */
        uint64_t reserved_22_23        : 2;
        uint64_t wgt_left              : 6;  /**< [ 29: 24](RO/H) Cross-group arbitration credits remaining on this group. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_pri_s cn; */
} bdk_sso_grpx_pri_t;

static inline uint64_t BDK_SSO_GRPX_PRI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_PRI(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000200ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_PRI", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_PRI(a) bdk_sso_grpx_pri_t
#define bustype_BDK_SSO_GRPX_PRI(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_PRI(a) "SSO_GRPX_PRI"
#define device_bar_BDK_SSO_GRPX_PRI(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_PRI(a) (a)
#define arguments_BDK_SSO_GRPX_PRI(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_taq_thr
 *
 * SSO Transitory Admission Queue Threshold Registers
 * These registers contain the thresholds for allocating SSO transitory admission queue storage
 * buffers.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_taq_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_59_63        : 5;
        uint64_t grp_cnt               : 11; /**< [ 58: 48](RO/H) Group's entry count. Number of transitory admission buffers allocated to this group. */
        uint64_t reserved_43_47        : 5;
        uint64_t max_thr               : 11; /**< [ 42: 32](R/W) Max threshold for this transitory admission queue, in buffers of 11 entries. Must be >= 3,
                                                                 must be >= [RSVD_THR], and to insure full streaming performance on this group, should be
                                                                 at least 16 buffers. SSO may exceed this count using unreserved free buffers if and only
                                                                 if persistently backpressured by IOBI. Must not be changed after traffic is sent to this
                                                                 group. */
        uint64_t reserved_11_31        : 21;
        uint64_t rsvd_thr              : 11; /**< [ 10:  0](R/W) Reserved threshold for this transitory admission queue, in buffers of 11 entries. Must be
                                                                 at least 3 buffers for any groups that are to be used. Changes to this field must also
                                                                 update SSO_TAQ_ADD[RSVD_FREE]. Must not be changed after traffic is sent to this group. */
#else /* Word 0 - Little Endian */
        uint64_t rsvd_thr              : 11; /**< [ 10:  0](R/W) Reserved threshold for this transitory admission queue, in buffers of 11 entries. Must be
                                                                 at least 3 buffers for any groups that are to be used. Changes to this field must also
                                                                 update SSO_TAQ_ADD[RSVD_FREE]. Must not be changed after traffic is sent to this group. */
        uint64_t reserved_11_31        : 21;
        uint64_t max_thr               : 11; /**< [ 42: 32](R/W) Max threshold for this transitory admission queue, in buffers of 11 entries. Must be >= 3,
                                                                 must be >= [RSVD_THR], and to insure full streaming performance on this group, should be
                                                                 at least 16 buffers. SSO may exceed this count using unreserved free buffers if and only
                                                                 if persistently backpressured by IOBI. Must not be changed after traffic is sent to this
                                                                 group. */
        uint64_t reserved_43_47        : 5;
        uint64_t grp_cnt               : 11; /**< [ 58: 48](RO/H) Group's entry count. Number of transitory admission buffers allocated to this group. */
        uint64_t reserved_59_63        : 5;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_taq_thr_s cn; */
} bdk_sso_grpx_taq_thr_t;

static inline uint64_t BDK_SSO_GRPX_TAQ_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_TAQ_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000100ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_TAQ_THR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_TAQ_THR(a) bdk_sso_grpx_taq_thr_t
#define bustype_BDK_SSO_GRPX_TAQ_THR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_TAQ_THR(a) "SSO_GRPX_TAQ_THR"
#define device_bar_BDK_SSO_GRPX_TAQ_THR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_TAQ_THR(a) (a)
#define arguments_BDK_SSO_GRPX_TAQ_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_ts_pc
 *
 * SSO Tag Switch Performance Counter Register
 * Counts the number of tag switch requests for each group being switched to. Counter rolls over
 * through zero when max value exceeded.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_ts_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Tag switch performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Tag switch performance counter. Writes are for diagnostic use only, and defined only when
                                                                 neither work nor GET_WORKs are present in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_ts_pc_s cn; */
} bdk_sso_grpx_ts_pc_t;

static inline uint64_t BDK_SSO_GRPX_TS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_TS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001300ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_TS_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_TS_PC(a) bdk_sso_grpx_ts_pc_t
#define bustype_BDK_SSO_GRPX_TS_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_TS_PC(a) "SSO_GRPX_TS_PC"
#define device_bar_BDK_SSO_GRPX_TS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_TS_PC(a) (a)
#define arguments_BDK_SSO_GRPX_TS_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_wa_pc
 *
 * SSO Work-Add Performance Counter Registers
 * Counts the number of add new work requests for each group. The counter rolls over through zero
 * when the max value exceeded.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_wa_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work add performance counter for group. Increments when work moves into IAQ. Writes are
                                                                 for diagnostic use only, and defined only when neither work nor GET_WORKs are present in
                                                                 the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work add performance counter for group. Increments when work moves into IAQ. Writes are
                                                                 for diagnostic use only, and defined only when neither work nor GET_WORKs are present in
                                                                 the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_wa_pc_s cn; */
} bdk_sso_grpx_wa_pc_t;

static inline uint64_t BDK_SSO_GRPX_WA_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_WA_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001200ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_WA_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_WA_PC(a) bdk_sso_grpx_wa_pc_t
#define bustype_BDK_SSO_GRPX_WA_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_WA_PC(a) "SSO_GRPX_WA_PC"
#define device_bar_BDK_SSO_GRPX_WA_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_WA_PC(a) (a)
#define arguments_BDK_SSO_GRPX_WA_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_grp#_ws_pc
 *
 * SSO Work-Schedule Performance Counter Registers
 * Counts the number of work schedules for each group. The counter rolls over through zero when
 * the maximum value is exceeded.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_grpx_ws_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work schedule performance counter for group. Writes are for diagnostic use only, and
                                                                 defined only when neither work nor GET_WORKs are present in the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Work schedule performance counter for group. Writes are for diagnostic use only, and
                                                                 defined only when neither work nor GET_WORKs are present in the SSO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_grpx_ws_pc_s cn; */
} bdk_sso_grpx_ws_pc_t;

static inline uint64_t BDK_SSO_GRPX_WS_PC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GRPX_WS_PC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020001000ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_GRPX_WS_PC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_GRPX_WS_PC(a) bdk_sso_grpx_ws_pc_t
#define bustype_BDK_SSO_GRPX_WS_PC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GRPX_WS_PC(a) "SSO_GRPX_WS_PC"
#define device_bar_BDK_SSO_GRPX_WS_PC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GRPX_WS_PC(a) (a)
#define arguments_BDK_SSO_GRPX_WS_PC(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_gw_eco
 *
 * INTERNAL: SSO_GW ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_gw_eco_s
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
    /* struct bdk_sso_gw_eco_s cn; */
} bdk_sso_gw_eco_t;

#define BDK_SSO_GW_ECO BDK_SSO_GW_ECO_FUNC()
static inline uint64_t BDK_SSO_GW_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GW_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001038ll;
    __bdk_csr_fatal("SSO_GW_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_GW_ECO bdk_sso_gw_eco_t
#define bustype_BDK_SSO_GW_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GW_ECO "SSO_GW_ECO"
#define device_bar_BDK_SSO_GW_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GW_ECO 0
#define arguments_BDK_SSO_GW_ECO -1,-1,-1,-1

/**
 * Register (NCB) sso_gwe_cfg
 *
 * SSO Get-Work Examiner Configuration Register
 * This register controls the operation of the get-work examiner (GWE).
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_gwe_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t dis_wgt_credit        : 1;  /**< [  8:  8](R/W) Disable group weight credits. When set, groups have infinite weight credit. */
        uint64_t ws_retries            : 8;  /**< [  7:  0](R/W) Work slot retries. When a given work-slot performs this number of retries without
                                                                 successfully finding work then NO_WORK will be returned. Values 0, 1, 2, 3 are reserved. */
#else /* Word 0 - Little Endian */
        uint64_t ws_retries            : 8;  /**< [  7:  0](R/W) Work slot retries. When a given work-slot performs this number of retries without
                                                                 successfully finding work then NO_WORK will be returned. Values 0, 1, 2, 3 are reserved. */
        uint64_t dis_wgt_credit        : 1;  /**< [  8:  8](R/W) Disable group weight credits. When set, groups have infinite weight credit. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_gwe_cfg_s cn; */
} bdk_sso_gwe_cfg_t;

#define BDK_SSO_GWE_CFG BDK_SSO_GWE_CFG_FUNC()
static inline uint64_t BDK_SSO_GWE_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GWE_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001098ll;
    __bdk_csr_fatal("SSO_GWE_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_GWE_CFG bdk_sso_gwe_cfg_t
#define bustype_BDK_SSO_GWE_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GWE_CFG "SSO_GWE_CFG"
#define device_bar_BDK_SSO_GWE_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GWE_CFG 0
#define arguments_BDK_SSO_GWE_CFG -1,-1,-1,-1

/**
 * Register (NCB) sso_gwe_random
 *
 * SSO Get-Work Examiner Random Register
 * This register contains the random search start position for the get-work examiner (GWE).
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_gwe_random_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t rnd                   : 16; /**< [ 15:  0](R/W/H) Current random value, with low 8 bits indicating first group to start next get-work search
                                                                 at. Changes on each work search, even if unsuccessful or retried. For diagnostic use only,
                                                                 must not be zero.

                                                                 Internal:
                                                                 Uses 16, 15, 13, 4 tap LFSR (this choice is important to
                                                                 insure even group probabilities) with the formula:
                                                                 _ grp_to_start_arb_at = RND[7:0];
                                                                 _ RND_next[15:8] = RND[7:0];
                                                                 _ RND_next[7] = ^(RND[15:0] & 0xd008);
                                                                 _ RND_next[6] = ^(RND[15:0] & 0x6804);
                                                                 _ RND_next[5] = ^(RND[15:0] & 0x3402);
                                                                 _ RND_next[4] = ^(RND[15:0] & 0x1a01);
                                                                 _ RND_next[3] = ^(RND[15:0] & 0xdd08);
                                                                 _ RND_next[2] = ^(RND[15:0] & 0x6e84);
                                                                 _ RND_next[1] = ^(RND[15:0] & 0x3742);
                                                                 _ RND_next[0] = ^(RND[15:0] & 0x1ba1); */
#else /* Word 0 - Little Endian */
        uint64_t rnd                   : 16; /**< [ 15:  0](R/W/H) Current random value, with low 8 bits indicating first group to start next get-work search
                                                                 at. Changes on each work search, even if unsuccessful or retried. For diagnostic use only,
                                                                 must not be zero.

                                                                 Internal:
                                                                 Uses 16, 15, 13, 4 tap LFSR (this choice is important to
                                                                 insure even group probabilities) with the formula:
                                                                 _ grp_to_start_arb_at = RND[7:0];
                                                                 _ RND_next[15:8] = RND[7:0];
                                                                 _ RND_next[7] = ^(RND[15:0] & 0xd008);
                                                                 _ RND_next[6] = ^(RND[15:0] & 0x6804);
                                                                 _ RND_next[5] = ^(RND[15:0] & 0x3402);
                                                                 _ RND_next[4] = ^(RND[15:0] & 0x1a01);
                                                                 _ RND_next[3] = ^(RND[15:0] & 0xdd08);
                                                                 _ RND_next[2] = ^(RND[15:0] & 0x6e84);
                                                                 _ RND_next[1] = ^(RND[15:0] & 0x3742);
                                                                 _ RND_next[0] = ^(RND[15:0] & 0x1ba1); */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_gwe_random_s cn; */
} bdk_sso_gwe_random_t;

#define BDK_SSO_GWE_RANDOM BDK_SSO_GWE_RANDOM_FUNC()
static inline uint64_t BDK_SSO_GWE_RANDOM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_GWE_RANDOM_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010b0ll;
    __bdk_csr_fatal("SSO_GWE_RANDOM", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_GWE_RANDOM bdk_sso_gwe_random_t
#define bustype_BDK_SSO_GWE_RANDOM BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_GWE_RANDOM "SSO_GWE_RANDOM"
#define device_bar_BDK_SSO_GWE_RANDOM 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_GWE_RANDOM 0
#define arguments_BDK_SSO_GWE_RANDOM -1,-1,-1,-1

/**
 * Register (NCB) sso_hws#_arb
 *
 * SSO HWS Arbitration State Register
 * For diagnostic use, returns the group affinity arbitration state for each HWS.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_hwsx_arb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t aff_left              : 4;  /**< [ 19: 16](RO/H) HWS affinity arbitration credits remaining on the last serviced group. */
        uint64_t reserved_8_15         : 8;
        uint64_t last_grp              : 8;  /**< [  7:  0](RO/H) Last group number serviced by this HWS. */
#else /* Word 0 - Little Endian */
        uint64_t last_grp              : 8;  /**< [  7:  0](RO/H) Last group number serviced by this HWS. */
        uint64_t reserved_8_15         : 8;
        uint64_t aff_left              : 4;  /**< [ 19: 16](RO/H) HWS affinity arbitration credits remaining on the last serviced group. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_hwsx_arb_s cn; */
} bdk_sso_hwsx_arb_t;

static inline uint64_t BDK_SSO_HWSX_ARB(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_HWSX_ARB(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x860040000000ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSO_HWSX_ARB", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_HWSX_ARB(a) bdk_sso_hwsx_arb_t
#define bustype_BDK_SSO_HWSX_ARB(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_HWSX_ARB(a) "SSO_HWSX_ARB"
#define device_bar_BDK_SSO_HWSX_ARB(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_HWSX_ARB(a) (a)
#define arguments_BDK_SSO_HWSX_ARB(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_hws#_s#_grpmsk#
 *
 * SSO HWS Group Mask Registers
 * These registers select which group or groups a HWS belongs to. There are 2 sets of masks per
 * HWS, each with 1 register corresponding to 64 groups.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_hwsx_sx_grpmskx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t grp_msk               : 64; /**< [ 63:  0](R/W) HWS group mask. A one in any bit position sets the HWS's membership in the
                                                                 corresponding group for groups <63:0>.

                                                                 A value of 0x0 in GRPMSK for a given HWS prevents the HWS from receiving new
                                                                 work. HWSs that will never receive work should use GRPMSK=0x0; while this
                                                                 setting is not special in SSO, for backward and forward compatibility this may
                                                                 enable reallocation of internal resources to the remaining (non-zero-mask)
                                                                 hardware work-slots.

                                                                 This register is intended only for large-scale save-restore of masks.
                                                                 Individual changes should use SSOW_VHWS()_GRPMSK_CHG().

                                                                 Internal:
                                                                 SSO virtualization will only allow PF access; this register will only be used
                                                                 for paging HWS in or out.  Guests must use SSOW_VHWS()_GRPMSK_CHG(). */
#else /* Word 0 - Little Endian */
        uint64_t grp_msk               : 64; /**< [ 63:  0](R/W) HWS group mask. A one in any bit position sets the HWS's membership in the
                                                                 corresponding group for groups <63:0>.

                                                                 A value of 0x0 in GRPMSK for a given HWS prevents the HWS from receiving new
                                                                 work. HWSs that will never receive work should use GRPMSK=0x0; while this
                                                                 setting is not special in SSO, for backward and forward compatibility this may
                                                                 enable reallocation of internal resources to the remaining (non-zero-mask)
                                                                 hardware work-slots.

                                                                 This register is intended only for large-scale save-restore of masks.
                                                                 Individual changes should use SSOW_VHWS()_GRPMSK_CHG().

                                                                 Internal:
                                                                 SSO virtualization will only allow PF access; this register will only be used
                                                                 for paging HWS in or out.  Guests must use SSOW_VHWS()_GRPMSK_CHG(). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_hwsx_sx_grpmskx_s cn; */
} bdk_sso_hwsx_sx_grpmskx_t;

static inline uint64_t BDK_SSO_HWSX_SX_GRPMSKX(unsigned long a, unsigned long b, unsigned long c) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_HWSX_SX_GRPMSKX(unsigned long a, unsigned long b, unsigned long c)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=1) && (c==0)))
        return 0x860040001000ll + 0x100000ll * ((a) & 0x1f) + 0x20ll * ((b) & 0x1) + 8ll * ((c) & 0x0);
    __bdk_csr_fatal("SSO_HWSX_SX_GRPMSKX", 3, a, b, c, 0);
}

#define typedef_BDK_SSO_HWSX_SX_GRPMSKX(a,b,c) bdk_sso_hwsx_sx_grpmskx_t
#define bustype_BDK_SSO_HWSX_SX_GRPMSKX(a,b,c) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_HWSX_SX_GRPMSKX(a,b,c) "SSO_HWSX_SX_GRPMSKX"
#define device_bar_BDK_SSO_HWSX_SX_GRPMSKX(a,b,c) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_HWSX_SX_GRPMSKX(a,b,c) (a)
#define arguments_BDK_SSO_HWSX_SX_GRPMSKX(a,b,c) (a),(b),(c),-1

/**
 * Register (NCB) sso_ient#_grp
 *
 * SSO Internal Entry Group Registers
 * Returns unit memory status for an index.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ientx_grp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t head                  : 1;  /**< [ 61: 61](RO/H) SSO entry is at the head of a tag chain that is descheduled. */
        uint64_t nosched               : 1;  /**< [ 60: 60](RO/H) The nosched bit for the SSO entry. */
        uint64_t reserved_56_59        : 4;
        uint64_t grp                   : 8;  /**< [ 55: 48](RO/H) Group of the SSO entry.
                                                                 Internal:
                                                                 The upper bits are not stored in the RAM, but rather indicate the OCI node number. */
        uint64_t reserved_0_47         : 48;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_47         : 48;
        uint64_t grp                   : 8;  /**< [ 55: 48](RO/H) Group of the SSO entry.
                                                                 Internal:
                                                                 The upper bits are not stored in the RAM, but rather indicate the OCI node number. */
        uint64_t reserved_56_59        : 4;
        uint64_t nosched               : 1;  /**< [ 60: 60](RO/H) The nosched bit for the SSO entry. */
        uint64_t head                  : 1;  /**< [ 61: 61](RO/H) SSO entry is at the head of a tag chain that is descheduled. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ientx_grp_s cn; */
} bdk_sso_ientx_grp_t;

static inline uint64_t BDK_SSO_IENTX_GRP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IENTX_GRP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0020000ll + 8ll * ((a) & 0x3ff);
    __bdk_csr_fatal("SSO_IENTX_GRP", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IENTX_GRP(a) bdk_sso_ientx_grp_t
#define bustype_BDK_SSO_IENTX_GRP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IENTX_GRP(a) "SSO_IENTX_GRP"
#define device_bar_BDK_SSO_IENTX_GRP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IENTX_GRP(a) (a)
#define arguments_BDK_SSO_IENTX_GRP(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_links
 *
 * SSO Internal Entry Links Registers
 * Returns unit memory status for an index.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ientx_links_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_26_63        : 38;
        uint64_t prev_index            : 10; /**< [ 25: 16](RO/H) The previous entry in the tag chain. Unpredictable if the entry is at the head of the list
                                                                 or the head of a conflicted tag chain. */
        uint64_t reserved_11_15        : 5;
        uint64_t next_index_vld        : 1;  /**< [ 10: 10](RO/H) The [NEXT_INDEX] is valid. Unpredictable unless the entry is the tail entry of an atomic tag chain. */
        uint64_t next_index            : 10; /**< [  9:  0](RO/H) The next entry in the tag chain or conflicted tag chain. Unpredictable if the entry is at
                                                                 the tail of the list. */
#else /* Word 0 - Little Endian */
        uint64_t next_index            : 10; /**< [  9:  0](RO/H) The next entry in the tag chain or conflicted tag chain. Unpredictable if the entry is at
                                                                 the tail of the list. */
        uint64_t next_index_vld        : 1;  /**< [ 10: 10](RO/H) The [NEXT_INDEX] is valid. Unpredictable unless the entry is the tail entry of an atomic tag chain. */
        uint64_t reserved_11_15        : 5;
        uint64_t prev_index            : 10; /**< [ 25: 16](RO/H) The previous entry in the tag chain. Unpredictable if the entry is at the head of the list
                                                                 or the head of a conflicted tag chain. */
        uint64_t reserved_26_63        : 38;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ientx_links_s cn; */
} bdk_sso_ientx_links_t;

static inline uint64_t BDK_SSO_IENTX_LINKS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IENTX_LINKS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0060000ll + 8ll * ((a) & 0x3ff);
    __bdk_csr_fatal("SSO_IENTX_LINKS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IENTX_LINKS(a) bdk_sso_ientx_links_t
#define bustype_BDK_SSO_IENTX_LINKS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IENTX_LINKS(a) "SSO_IENTX_LINKS"
#define device_bar_BDK_SSO_IENTX_LINKS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IENTX_LINKS(a) (a)
#define arguments_BDK_SSO_IENTX_LINKS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_pendtag
 *
 * SSO Internal Entry Pending Tag Registers
 * Returns unit memory status for an index.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ientx_pendtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_38_63        : 26;
        uint64_t pend_switch           : 1;  /**< [ 37: 37](RO/H) Set when there is a pending non-UNTAGGED SWTAG or SWTAG_FULL and the SSO entry has not
                                                                 left the list for the original tag. */
        uint64_t reserved_34_36        : 3;
        uint64_t pend_tt               : 2;  /**< [ 33: 32](RO/H) The next tag type for the new tag list when PEND_SWITCH is set. Enumerated by SSO_TT_E. */
        uint64_t pend_tag              : 32; /**< [ 31:  0](RO/H) The next tag for the new tag list when PEND_SWITCH is set. */
#else /* Word 0 - Little Endian */
        uint64_t pend_tag              : 32; /**< [ 31:  0](RO/H) The next tag for the new tag list when PEND_SWITCH is set. */
        uint64_t pend_tt               : 2;  /**< [ 33: 32](RO/H) The next tag type for the new tag list when PEND_SWITCH is set. Enumerated by SSO_TT_E. */
        uint64_t reserved_34_36        : 3;
        uint64_t pend_switch           : 1;  /**< [ 37: 37](RO/H) Set when there is a pending non-UNTAGGED SWTAG or SWTAG_FULL and the SSO entry has not
                                                                 left the list for the original tag. */
        uint64_t reserved_38_63        : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ientx_pendtag_s cn; */
} bdk_sso_ientx_pendtag_t;

static inline uint64_t BDK_SSO_IENTX_PENDTAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IENTX_PENDTAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0040000ll + 8ll * ((a) & 0x3ff);
    __bdk_csr_fatal("SSO_IENTX_PENDTAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IENTX_PENDTAG(a) bdk_sso_ientx_pendtag_t
#define bustype_BDK_SSO_IENTX_PENDTAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IENTX_PENDTAG(a) "SSO_IENTX_PENDTAG"
#define device_bar_BDK_SSO_IENTX_PENDTAG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IENTX_PENDTAG(a) (a)
#define arguments_BDK_SSO_IENTX_PENDTAG(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_qlinks
 *
 * SSO Internal Queue Links Registers
 * Returns unit memory status for an index.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ientx_qlinks_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t next_index            : 12; /**< [ 11:  0](RO/H) The next entry in the AQ/CQ/DQ. */
#else /* Word 0 - Little Endian */
        uint64_t next_index            : 12; /**< [ 11:  0](RO/H) The next entry in the AQ/CQ/DQ. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ientx_qlinks_s cn; */
} bdk_sso_ientx_qlinks_t;

static inline uint64_t BDK_SSO_IENTX_QLINKS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IENTX_QLINKS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0080000ll + 8ll * ((a) & 0x3ff);
    __bdk_csr_fatal("SSO_IENTX_QLINKS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IENTX_QLINKS(a) bdk_sso_ientx_qlinks_t
#define bustype_BDK_SSO_IENTX_QLINKS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IENTX_QLINKS(a) "SSO_IENTX_QLINKS"
#define device_bar_BDK_SSO_IENTX_QLINKS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IENTX_QLINKS(a) (a)
#define arguments_BDK_SSO_IENTX_QLINKS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_tag
 *
 * SSO Internal Entry Tag Registers
 * Returns unit memory status for an index.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ientx_tag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_39_63        : 25;
        uint64_t tailc                 : 1;  /**< [ 38: 38](RO/H) The SSO entry is the tail of tag chain that is conflicted. No conflicted chain exists if
                                                                 TAIL is also set on the same entry. */
        uint64_t tail                  : 1;  /**< [ 37: 37](RO/H) The SSO entry is the tail of tag chain that is descheduled.
                                                                 Internal:
                                                                 Read from the SOC. */
        uint64_t reserved_34_36        : 3;
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the SSO entry. Enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the SSO entry. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the SSO entry. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the SSO entry. Enumerated by SSO_TT_E. */
        uint64_t reserved_34_36        : 3;
        uint64_t tail                  : 1;  /**< [ 37: 37](RO/H) The SSO entry is the tail of tag chain that is descheduled.
                                                                 Internal:
                                                                 Read from the SOC. */
        uint64_t tailc                 : 1;  /**< [ 38: 38](RO/H) The SSO entry is the tail of tag chain that is conflicted. No conflicted chain exists if
                                                                 TAIL is also set on the same entry. */
        uint64_t reserved_39_63        : 25;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ientx_tag_s cn; */
} bdk_sso_ientx_tag_t;

static inline uint64_t BDK_SSO_IENTX_TAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IENTX_TAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a0000000ll + 8ll * ((a) & 0x3ff);
    __bdk_csr_fatal("SSO_IENTX_TAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IENTX_TAG(a) bdk_sso_ientx_tag_t
#define bustype_BDK_SSO_IENTX_TAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IENTX_TAG(a) "SSO_IENTX_TAG"
#define device_bar_BDK_SSO_IENTX_TAG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IENTX_TAG(a) (a)
#define arguments_BDK_SSO_IENTX_TAG(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ient#_wqp
 *
 * SSO Internal Entry WQP Registers
 * Returns unit memory status for an index.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ientx_wqp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the SSO entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the SSO entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ientx_wqp_s cn; */
} bdk_sso_ientx_wqp_t;

static inline uint64_t BDK_SSO_IENTX_WQP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IENTX_WQP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1023))
        return 0x8600a00a0000ll + 8ll * ((a) & 0x3ff);
    __bdk_csr_fatal("SSO_IENTX_WQP", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IENTX_WQP(a) bdk_sso_ientx_wqp_t
#define bustype_BDK_SSO_IENTX_WQP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IENTX_WQP(a) "SSO_IENTX_WQP"
#define device_bar_BDK_SSO_IENTX_WQP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IENTX_WQP(a) (a)
#define arguments_BDK_SSO_IENTX_WQP(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_conf#
 *
 * SSO Conflicted List State Registers
 * Returns list status for the conflicted list indexed by group.  Register
 * fields are identical to those in SSO_IPL_IAQ() above.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ipl_confx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ipl_confx_s cn; */
} bdk_sso_ipl_confx_t;

static inline uint64_t BDK_SSO_IPL_CONFX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IPL_CONFX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860080080000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_IPL_CONFX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IPL_CONFX(a) bdk_sso_ipl_confx_t
#define bustype_BDK_SSO_IPL_CONFX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IPL_CONFX(a) "SSO_IPL_CONFX"
#define device_bar_BDK_SSO_IPL_CONFX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IPL_CONFX(a) (a)
#define arguments_BDK_SSO_IPL_CONFX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_desched#
 *
 * SSO Deschedule List State Registers
 * Returns list status for the deschedule list indexed by group.  Register
 * fields are identical to those in SSO_IPL_IAQ() above.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ipl_deschedx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ipl_deschedx_s cn; */
} bdk_sso_ipl_deschedx_t;

static inline uint64_t BDK_SSO_IPL_DESCHEDX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IPL_DESCHEDX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860080060000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_IPL_DESCHEDX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IPL_DESCHEDX(a) bdk_sso_ipl_deschedx_t
#define bustype_BDK_SSO_IPL_DESCHEDX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IPL_DESCHEDX(a) "SSO_IPL_DESCHEDX"
#define device_bar_BDK_SSO_IPL_DESCHEDX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IPL_DESCHEDX(a) (a)
#define arguments_BDK_SSO_IPL_DESCHEDX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_free#
 *
 * SSO Free List State Registers
 * Returns list status.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ipl_freex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t qnum_head             : 3;  /**< [ 61: 59](RO/H) Subqueue with current head. */
        uint64_t qnum_tail             : 3;  /**< [ 58: 56](RO/H) Subqueue for next tail. */
        uint64_t reserved_28_55        : 28;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in this subqueue. */
        uint64_t reserved_23_26        : 4;
        uint64_t queue_head            : 10; /**< [ 22: 13](RO/H) Index of entry at the head of this subqueue. */
        uint64_t reserved_10_12        : 3;
        uint64_t queue_tail            : 10; /**< [  9:  0](RO/H) Index of entry at the tail of this subqueue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 10; /**< [  9:  0](RO/H) Index of entry at the tail of this subqueue. */
        uint64_t reserved_10_12        : 3;
        uint64_t queue_head            : 10; /**< [ 22: 13](RO/H) Index of entry at the head of this subqueue. */
        uint64_t reserved_23_26        : 4;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in this subqueue. */
        uint64_t reserved_28_55        : 28;
        uint64_t qnum_tail             : 3;  /**< [ 58: 56](RO/H) Subqueue for next tail. */
        uint64_t qnum_head             : 3;  /**< [ 61: 59](RO/H) Subqueue with current head. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ipl_freex_s cn; */
} bdk_sso_ipl_freex_t;

static inline uint64_t BDK_SSO_IPL_FREEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IPL_FREEX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=4))
        return 0x860080000000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("SSO_IPL_FREEX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IPL_FREEX(a) bdk_sso_ipl_freex_t
#define bustype_BDK_SSO_IPL_FREEX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IPL_FREEX(a) "SSO_IPL_FREEX"
#define device_bar_BDK_SSO_IPL_FREEX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IPL_FREEX(a) (a)
#define arguments_BDK_SSO_IPL_FREEX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_ipl_iaq#
 *
 * SSO IAQ List State Registers
 * Returns list status for the internal admission queue indexed by group.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ipl_iaqx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
#else /* Word 0 - Little Endian */
        uint64_t queue_tail            : 12; /**< [ 11:  0](RO/H) Index of entry at the tail of the queue. */
        uint64_t reserved_12           : 1;
        uint64_t queue_head            : 12; /**< [ 24: 13](RO/H) Index of entry at the head of the queue. */
        uint64_t reserved_25           : 1;
        uint64_t queue_one             : 1;  /**< [ 26: 26](RO/H) Exactly one valid entry is in the queue. */
        uint64_t queue_val             : 1;  /**< [ 27: 27](RO/H) One or more valid entries are in the queue. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ipl_iaqx_s cn; */
} bdk_sso_ipl_iaqx_t;

static inline uint64_t BDK_SSO_IPL_IAQX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_IPL_IAQX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860080040000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_IPL_IAQX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_IPL_IAQX(a) bdk_sso_ipl_iaqx_t
#define bustype_BDK_SSO_IPL_IAQX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_IPL_IAQX(a) "SSO_IPL_IAQX"
#define device_bar_BDK_SSO_IPL_IAQX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_IPL_IAQX(a) (a)
#define arguments_BDK_SSO_IPL_IAQX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_nos_cnt
 *
 * SSO No-schedule Count Register
 * Contains the number of work-queue entries on the no-schedule list.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_nos_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t nos_cnt               : 13; /**< [ 12:  0](RO/H) Number of work-queue entries on the no-schedule list. */
#else /* Word 0 - Little Endian */
        uint64_t nos_cnt               : 13; /**< [ 12:  0](RO/H) Number of work-queue entries on the no-schedule list. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_nos_cnt_s cn; */
} bdk_sso_nos_cnt_t;

#define BDK_SSO_NOS_CNT BDK_SSO_NOS_CNT_FUNC()
static inline uint64_t BDK_SSO_NOS_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_NOS_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001040ll;
    __bdk_csr_fatal("SSO_NOS_CNT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_NOS_CNT bdk_sso_nos_cnt_t
#define bustype_BDK_SSO_NOS_CNT BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_NOS_CNT "SSO_NOS_CNT"
#define device_bar_BDK_SSO_NOS_CNT 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_NOS_CNT 0
#define arguments_BDK_SSO_NOS_CNT -1,-1,-1,-1

/**
 * Register (NCB) sso_nw_tim
 *
 * SSO New-Work Timer Period Register
 * Sets the minimum period for a new-work-request timeout. The period is specified in n-1
 * notation, with the increment value of 1024 clock cycles. Thus, a value of 0x0 in this register
 * translates to 1024 cycles, 0x1 translates to 2048 cycles, 0x2 translates to 3072 cycles, etc.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_nw_tim_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t nw_tim                : 10; /**< [  9:  0](R/W) New-work-timer period.
                                                                 0x0 = 1024 clock cycles.
                                                                 0x1 = 2048 clock cycles.
                                                                 0x2 = 3072 clock cycles.
                                                                 _ ... etc. */
#else /* Word 0 - Little Endian */
        uint64_t nw_tim                : 10; /**< [  9:  0](R/W) New-work-timer period.
                                                                 0x0 = 1024 clock cycles.
                                                                 0x1 = 2048 clock cycles.
                                                                 0x2 = 3072 clock cycles.
                                                                 _ ... etc. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_nw_tim_s cn; */
} bdk_sso_nw_tim_t;

#define BDK_SSO_NW_TIM BDK_SSO_NW_TIM_FUNC()
static inline uint64_t BDK_SSO_NW_TIM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_NW_TIM_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001028ll;
    __bdk_csr_fatal("SSO_NW_TIM", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_NW_TIM bdk_sso_nw_tim_t
#define bustype_BDK_SSO_NW_TIM BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_NW_TIM "SSO_NW_TIM"
#define device_bar_BDK_SSO_NW_TIM 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_NW_TIM 0
#define arguments_BDK_SSO_NW_TIM -1,-1,-1,-1

/**
 * Register (NCB) sso_page_cnt
 *
 * SSO In-use Page Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_page_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t cnt                   : 32; /**< [ 31:  0](R/W/H) In-use page count. Number of pages SSO has allocated and not yet returned. Excludes unused
                                                                 pointers cached in SSO. Hardware updates this register. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 32; /**< [ 31:  0](R/W/H) In-use page count. Number of pages SSO has allocated and not yet returned. Excludes unused
                                                                 pointers cached in SSO. Hardware updates this register. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_page_cnt_s cn; */
} bdk_sso_page_cnt_t;

#define BDK_SSO_PAGE_CNT BDK_SSO_PAGE_CNT_FUNC()
static inline uint64_t BDK_SSO_PAGE_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PAGE_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001090ll;
    __bdk_csr_fatal("SSO_PAGE_CNT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_PAGE_CNT bdk_sso_page_cnt_t
#define bustype_BDK_SSO_PAGE_CNT BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PAGE_CNT "SSO_PAGE_CNT"
#define device_bar_BDK_SSO_PAGE_CNT 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PAGE_CNT 0
#define arguments_BDK_SSO_PAGE_CNT -1,-1,-1,-1

/**
 * Register (NCB) sso_pf_map#
 *
 * SSO PF VF Mapping Registers
 * These registers map GMIDs and guest groups to hardware groups.
 *
 * * Regardless of this mapping table, GMID 0x0 is always invalid and use of 0x0 will
 * cause a SSO_ERR0[GMID0] error.
 *
 * * else, regardless of this mapping table, GMID 0x1 is always a one-to-one mapping of
 * GGRP into VHGRP.
 *
 * * else (excluding GMID 0x0 and 0x1), if a request hits duplicate entries a
 * SSO_ERR0[GMID_MULTI] error will be reported.
 *
 * * else (excluding GMID 0x0 and 0x1), if a request does not hit any entries a
 * SSO_ERR0[GMID_UNMAP] error will be reported.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_mapx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t valid                 : 1;  /**< [ 63: 63](R/W) This entry is valid for matching. */
        uint64_t reserved_38_62        : 25;
        uint64_t vhgrp                 : 6;  /**< [ 37: 32](R/W) When [VALID] is set and this entry matches, the VHGRP the request's add-work
                                                                 will be added to. */
        uint64_t reserved_26_31        : 6;
        uint64_t ggrp                  : 10; /**< [ 25: 16](R/W) Guest group. When [VALID] is set, the guest's group to which this entry will be
                                                                 compared. */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine ID. When [VALID], the guest machine identifier to which [GGRP]
                                                                 belongs, and to which this entry will be compared. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine ID. When [VALID], the guest machine identifier to which [GGRP]
                                                                 belongs, and to which this entry will be compared. */
        uint64_t ggrp                  : 10; /**< [ 25: 16](R/W) Guest group. When [VALID] is set, the guest's group to which this entry will be
                                                                 compared. */
        uint64_t reserved_26_31        : 6;
        uint64_t vhgrp                 : 6;  /**< [ 37: 32](R/W) When [VALID] is set and this entry matches, the VHGRP the request's add-work
                                                                 will be added to. */
        uint64_t reserved_38_62        : 25;
        uint64_t valid                 : 1;  /**< [ 63: 63](R/W) This entry is valid for matching. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_mapx_s cn; */
} bdk_sso_pf_mapx_t;

static inline uint64_t BDK_SSO_PF_MAPX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MAPX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=71))
        return 0x860000004000ll + 8ll * ((a) & 0x7f);
    __bdk_csr_fatal("SSO_PF_MAPX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MAPX(a) bdk_sso_pf_mapx_t
#define bustype_BDK_SSO_PF_MAPX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MAPX(a) "SSO_PF_MAPX"
#define device_bar_BDK_SSO_PF_MAPX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_MAPX(a) (a)
#define arguments_BDK_SSO_PF_MAPX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_ena_w1c#
 *
 * SSO PF Mailbox Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_mbox_ena_w1cx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) Reads or clears enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_mbox_ena_w1cx_s cn; */
} bdk_sso_pf_mbox_ena_w1cx_t;

static inline uint64_t BDK_SSO_PF_MBOX_ENA_W1CX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MBOX_ENA_W1CX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x860000001480ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("SSO_PF_MBOX_ENA_W1CX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MBOX_ENA_W1CX(a) bdk_sso_pf_mbox_ena_w1cx_t
#define bustype_BDK_SSO_PF_MBOX_ENA_W1CX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MBOX_ENA_W1CX(a) "SSO_PF_MBOX_ENA_W1CX"
#define device_bar_BDK_SSO_PF_MBOX_ENA_W1CX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_MBOX_ENA_W1CX(a) (a)
#define arguments_BDK_SSO_PF_MBOX_ENA_W1CX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_ena_w1s#
 *
 * SSO PF Mailbox Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_mbox_ena_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets enable for SSO_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_mbox_ena_w1sx_s cn; */
} bdk_sso_pf_mbox_ena_w1sx_t;

static inline uint64_t BDK_SSO_PF_MBOX_ENA_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MBOX_ENA_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8600000014c0ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("SSO_PF_MBOX_ENA_W1SX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MBOX_ENA_W1SX(a) bdk_sso_pf_mbox_ena_w1sx_t
#define bustype_BDK_SSO_PF_MBOX_ENA_W1SX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MBOX_ENA_W1SX(a) "SSO_PF_MBOX_ENA_W1SX"
#define device_bar_BDK_SSO_PF_MBOX_ENA_W1SX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_MBOX_ENA_W1SX(a) (a)
#define arguments_BDK_SSO_PF_MBOX_ENA_W1SX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_int#
 *
 * SSO PF Mailbox Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_mbox_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) is written. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1C/H) One interrupt bit per VF. Each bit is set when the associated
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) is written. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_mbox_intx_s cn; */
} bdk_sso_pf_mbox_intx_t;

static inline uint64_t BDK_SSO_PF_MBOX_INTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MBOX_INTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x860000001400ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("SSO_PF_MBOX_INTX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MBOX_INTX(a) bdk_sso_pf_mbox_intx_t
#define bustype_BDK_SSO_PF_MBOX_INTX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MBOX_INTX(a) "SSO_PF_MBOX_INTX"
#define device_bar_BDK_SSO_PF_MBOX_INTX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_MBOX_INTX(a) (a)
#define arguments_BDK_SSO_PF_MBOX_INTX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_mbox_int_w1s#
 *
 * SSO PF Mailbox Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_mbox_int_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets SSO_PF_MBOX_INT(0)[MBOX]. */
#else /* Word 0 - Little Endian */
        uint64_t mbox                  : 64; /**< [ 63:  0](R/W1S/H) Reads or sets SSO_PF_MBOX_INT(0)[MBOX]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_mbox_int_w1sx_s cn; */
} bdk_sso_pf_mbox_int_w1sx_t;

static inline uint64_t BDK_SSO_PF_MBOX_INT_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MBOX_INT_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x860000001440ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("SSO_PF_MBOX_INT_W1SX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MBOX_INT_W1SX(a) bdk_sso_pf_mbox_int_w1sx_t
#define bustype_BDK_SSO_PF_MBOX_INT_W1SX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MBOX_INT_W1SX(a) "SSO_PF_MBOX_INT_W1SX"
#define device_bar_BDK_SSO_PF_MBOX_INT_W1SX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_MBOX_INT_W1SX(a) (a)
#define arguments_BDK_SSO_PF_MBOX_INT_W1SX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_msix_pba#
 *
 * SSO MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the SSO_PF_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_PF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_PF_INT_VEC_E. Bits that have no associated SSO_PF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_PF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_PF_INT_VEC_E. Bits that have no associated SSO_PF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_msix_pbax_s cn; */
} bdk_sso_pf_msix_pbax_t;

static inline uint64_t BDK_SSO_PF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x8607000f0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("SSO_PF_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MSIX_PBAX(a) bdk_sso_pf_msix_pbax_t
#define bustype_BDK_SSO_PF_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MSIX_PBAX(a) "SSO_PF_MSIX_PBAX"
#define device_bar_BDK_SSO_PF_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_SSO_PF_MSIX_PBAX(a) (a)
#define arguments_BDK_SSO_PF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_msix_vec#_addr
 *
 * SSO MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the SSO_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SSO_PF_MSIX_VEC()_ADDR, SSO_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SSO_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SSO_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SSO_PF_MSIX_VEC()_ADDR, SSO_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SSO_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SSO_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_msix_vecx_addr_s cn; */
} bdk_sso_pf_msix_vecx_addr_t;

static inline uint64_t BDK_SSO_PF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x860700000000ll + 0x10ll * ((a) & 0x3);
    __bdk_csr_fatal("SSO_PF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MSIX_VECX_ADDR(a) bdk_sso_pf_msix_vecx_addr_t
#define bustype_BDK_SSO_PF_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MSIX_VECX_ADDR(a) "SSO_PF_MSIX_VECX_ADDR"
#define device_bar_BDK_SSO_PF_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_SSO_PF_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_SSO_PF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_msix_vec#_ctl
 *
 * SSO MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the SSO_PF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_msix_vecx_ctl_s
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
    /* struct bdk_sso_pf_msix_vecx_ctl_s cn; */
} bdk_sso_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_SSO_PF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x860700000008ll + 0x10ll * ((a) & 0x3);
    __bdk_csr_fatal("SSO_PF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_MSIX_VECX_CTL(a) bdk_sso_pf_msix_vecx_ctl_t
#define bustype_BDK_SSO_PF_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_MSIX_VECX_CTL(a) "SSO_PF_MSIX_VECX_CTL"
#define device_bar_BDK_SSO_PF_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_SSO_PF_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_SSO_PF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_vhgrp#_aq_limit
 *
 * SSO Admission Queue Limit Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_vhgrpx_aq_limit_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t aq_limit              : 33; /**< [ 32:  0](RO/H) AQ limit. If an add work is requested to a group where [AQ_LIMIT] <=
                                                                 SSO_VHGRP()_AQ_CNT[AQ_CNT], then the add work is dropped and
                                                                 SSO_VHGRP()_INT[AQ_LIMIT] is set. When 0x0, limiting is disabled. Due to
                                                                 pipelining, hardware may exceed this limit by up to TBD entries. */
#else /* Word 0 - Little Endian */
        uint64_t aq_limit              : 33; /**< [ 32:  0](RO/H) AQ limit. If an add work is requested to a group where [AQ_LIMIT] <=
                                                                 SSO_VHGRP()_AQ_CNT[AQ_CNT], then the add work is dropped and
                                                                 SSO_VHGRP()_INT[AQ_LIMIT] is set. When 0x0, limiting is disabled. Due to
                                                                 pipelining, hardware may exceed this limit by up to TBD entries. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_vhgrpx_aq_limit_s cn; */
} bdk_sso_pf_vhgrpx_aq_limit_t;

static inline uint64_t BDK_SSO_PF_VHGRPX_AQ_LIMIT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_VHGRPX_AQ_LIMIT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860020000220ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_PF_VHGRPX_AQ_LIMIT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_PF_VHGRPX_AQ_LIMIT(a) bdk_sso_pf_vhgrpx_aq_limit_t
#define bustype_BDK_SSO_PF_VHGRPX_AQ_LIMIT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_VHGRPX_AQ_LIMIT(a) "SSO_PF_VHGRPX_AQ_LIMIT"
#define device_bar_BDK_SSO_PF_VHGRPX_AQ_LIMIT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_VHGRPX_AQ_LIMIT(a) (a)
#define arguments_BDK_SSO_PF_VHGRPX_AQ_LIMIT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_pf_vhgrp#_mbox#
 *
 * SSO PF/VF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_pf_vhgrpx_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 SSO_VHGRP()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing SSO_PF_VHGRP(0..63)_MBOX(0) (but not
                                                                 SSO_VHGRP(0..63)_PF_MBOX(0)) will set the corresponding
                                                                 SSO_VHGRP()_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 SSO_VHGRP()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing SSO_PF_VHGRP(0..63)_MBOX(0) (but not
                                                                 SSO_VHGRP(0..63)_PF_MBOX(0)) will set the corresponding
                                                                 SSO_VHGRP()_INT[MBOX] which if appropriately enabled will send an interrupt
                                                                 to the VF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_pf_vhgrpx_mboxx_s cn; */
} bdk_sso_pf_vhgrpx_mboxx_t;

static inline uint64_t BDK_SSO_PF_VHGRPX_MBOXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_PF_VHGRPX_MBOXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b<=1)))
        return 0x860020000400ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("SSO_PF_VHGRPX_MBOXX", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_PF_VHGRPX_MBOXX(a,b) bdk_sso_pf_vhgrpx_mboxx_t
#define bustype_BDK_SSO_PF_VHGRPX_MBOXX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_PF_VHGRPX_MBOXX(a,b) "SSO_PF_VHGRPX_MBOXX"
#define device_bar_BDK_SSO_PF_VHGRPX_MBOXX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_PF_VHGRPX_MBOXX(a,b) (a)
#define arguments_BDK_SSO_PF_VHGRPX_MBOXX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_reset
 *
 * SSO Soft Reset Register
 * Writing a 1 to SSO_RESET[RESET] resets the SSO. After receiving a store to this CSR, the SSO
 * must not be sent any other operations for 2500 coprocessor (SCLK) cycles. Note that the
 * contents of this register are reset along with the rest of the SSO.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Initialization in progress. After reset asserts, SSO will set this bit until internal
                                                                 structures are initialized. This bit must read as zero before any configuration may be
                                                                 done. */
        uint64_t reserved_1_62         : 62;
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1/H) Reset the SSO. */
#else /* Word 0 - Little Endian */
        uint64_t reset                 : 1;  /**< [  0:  0](R/W1/H) Reset the SSO. */
        uint64_t reserved_1_62         : 62;
        uint64_t busy                  : 1;  /**< [ 63: 63](RO/H) Initialization in progress. After reset asserts, SSO will set this bit until internal
                                                                 structures are initialized. This bit must read as zero before any configuration may be
                                                                 done. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_reset_s cn; */
} bdk_sso_reset_t;

#define BDK_SSO_RESET BDK_SSO_RESET_FUNC()
static inline uint64_t BDK_SSO_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_RESET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000010f8ll;
    __bdk_csr_fatal("SSO_RESET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_RESET bdk_sso_reset_t
#define bustype_BDK_SSO_RESET BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_RESET "SSO_RESET"
#define device_bar_BDK_SSO_RESET 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_RESET 0
#define arguments_BDK_SSO_RESET -1,-1,-1,-1

/**
 * Register (NCB) sso_taq#_link
 *
 * SSO Transitory Admission Queue Link Registers
 * Returns TAQ status for a given line.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_taqx_link_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t next                  : 11; /**< [ 10:  0](RO/H) Next TAQ entry in linked list. Only valid when not at the tail of the list. */
#else /* Word 0 - Little Endian */
        uint64_t next                  : 11; /**< [ 10:  0](RO/H) Next TAQ entry in linked list. Only valid when not at the tail of the list. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_taqx_link_s cn; */
} bdk_sso_taqx_link_t;

static inline uint64_t BDK_SSO_TAQX_LINK(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TAQX_LINK(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=319))
        return 0x8600c0000000ll + 0x1000ll * ((a) & 0x1ff);
    __bdk_csr_fatal("SSO_TAQX_LINK", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_TAQX_LINK(a) bdk_sso_taqx_link_t
#define bustype_BDK_SSO_TAQX_LINK(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TAQX_LINK(a) "SSO_TAQX_LINK"
#define device_bar_BDK_SSO_TAQX_LINK(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TAQX_LINK(a) (a)
#define arguments_BDK_SSO_TAQX_LINK(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_taq#_wae#_tag
 *
 * SSO Transitory Admission Queue Tag Registers
 * Returns TAQ status for a given line and WAE within that line.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_taqx_waex_tag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the TAQ entry. Enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the TAQ entry. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag of the TAQ entry. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type of the TAQ entry. Enumerated by SSO_TT_E. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_taqx_waex_tag_s cn; */
} bdk_sso_taqx_waex_tag_t;

static inline uint64_t BDK_SSO_TAQX_WAEX_TAG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TAQX_WAEX_TAG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=319) && (b<=10)))
        return 0x8600d0000000ll + 0x1000ll * ((a) & 0x1ff) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("SSO_TAQX_WAEX_TAG", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_TAQX_WAEX_TAG(a,b) bdk_sso_taqx_waex_tag_t
#define bustype_BDK_SSO_TAQX_WAEX_TAG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TAQX_WAEX_TAG(a,b) "SSO_TAQX_WAEX_TAG"
#define device_bar_BDK_SSO_TAQX_WAEX_TAG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TAQX_WAEX_TAG(a,b) (a)
#define arguments_BDK_SSO_TAQX_WAEX_TAG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_taq#_wae#_wqp
 *
 * SSO Transitory Admission Queue Pointer Registers
 * Returns TAQ status for a given line and WAE within that line.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_taqx_waex_wqp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the TAQ entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](RO/H) Work queue IOVA held in the TAQ entry.
                                                                 Bits <63:49> are a sign extension of <48>.  Bits <2:0> are 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_taqx_waex_wqp_s cn; */
} bdk_sso_taqx_waex_wqp_t;

static inline uint64_t BDK_SSO_TAQX_WAEX_WQP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TAQX_WAEX_WQP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=319) && (b<=10)))
        return 0x8600d0000008ll + 0x1000ll * ((a) & 0x1ff) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("SSO_TAQX_WAEX_WQP", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_TAQX_WAEX_WQP(a,b) bdk_sso_taqx_waex_wqp_t
#define bustype_BDK_SSO_TAQX_WAEX_WQP(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TAQX_WAEX_WQP(a,b) "SSO_TAQX_WAEX_WQP"
#define device_bar_BDK_SSO_TAQX_WAEX_WQP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TAQX_WAEX_WQP(a,b) (a)
#define arguments_BDK_SSO_TAQX_WAEX_WQP(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_taq_add
 *
 * SSO Transitory Admission Queue Add Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_taq_add_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](WO) Written value is added to SSO_TAQ_CNT[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t rsvd_free             : 13; /**< [ 28: 16](WO) Written value is added to SSO_TAQ_CNT[RSVD_FREE] to prevent races between software and
                                                                 hardware changes. This is a two's complement value so subtraction may also be performed. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_taq_add_s cn; */
} bdk_sso_taq_add_t;

#define BDK_SSO_TAQ_ADD BDK_SSO_TAQ_ADD_FUNC()
static inline uint64_t BDK_SSO_TAQ_ADD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TAQ_ADD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020e0ll;
    __bdk_csr_fatal("SSO_TAQ_ADD", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_TAQ_ADD bdk_sso_taq_add_t
#define bustype_BDK_SSO_TAQ_ADD BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TAQ_ADD "SSO_TAQ_ADD"
#define device_bar_BDK_SSO_TAQ_ADD 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TAQ_ADD 0
#define arguments_BDK_SSO_TAQ_ADD -1,-1,-1,-1

/**
 * Register (NCB) sso_taq_cnt
 *
 * SSO Transitory Admission Queue Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_taq_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t rsvd_free             : 11; /**< [ 26: 16](R/W/H) Number of free reserved buffers. Used to insure each group may get a specific number of
                                                                 buffers. Must always be greater than or equal to the sum across all
                                                                 SSO_GRP()_TAQ_THR[RSVD_THR], and will generally be equal to that sum unless changes
                                                                 to RSVD_THR are going to be made. To prevent races, software should not change this
                                                                 register when SSO is being used; instead use SSO_TAQ_ADD[RSVD_FREE]. Legal values are
                                                                 0..0x140 */
        uint64_t reserved_11_15        : 5;
        uint64_t free_cnt              : 11; /**< [ 10:  0](RO/H) Number of total free buffers. */
#else /* Word 0 - Little Endian */
        uint64_t free_cnt              : 11; /**< [ 10:  0](RO/H) Number of total free buffers. */
        uint64_t reserved_11_15        : 5;
        uint64_t rsvd_free             : 11; /**< [ 26: 16](R/W/H) Number of free reserved buffers. Used to insure each group may get a specific number of
                                                                 buffers. Must always be greater than or equal to the sum across all
                                                                 SSO_GRP()_TAQ_THR[RSVD_THR], and will generally be equal to that sum unless changes
                                                                 to RSVD_THR are going to be made. To prevent races, software should not change this
                                                                 register when SSO is being used; instead use SSO_TAQ_ADD[RSVD_FREE]. Legal values are
                                                                 0..0x140 */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_taq_cnt_s cn; */
} bdk_sso_taq_cnt_t;

#define BDK_SSO_TAQ_CNT BDK_SSO_TAQ_CNT_FUNC()
static inline uint64_t BDK_SSO_TAQ_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TAQ_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020c0ll;
    __bdk_csr_fatal("SSO_TAQ_CNT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_TAQ_CNT bdk_sso_taq_cnt_t
#define bustype_BDK_SSO_TAQ_CNT BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TAQ_CNT "SSO_TAQ_CNT"
#define device_bar_BDK_SSO_TAQ_CNT 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TAQ_CNT 0
#define arguments_BDK_SSO_TAQ_CNT -1,-1,-1,-1

/**
 * Register (NCB) sso_tiaq#_status
 *
 * SSO Transitory Input Admission Queue Status Registers
 * Returns TAQ inbound status indexed by group.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_tiaqx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wae_head              : 4;  /**< [ 63: 60](RO/H) Head's WAE number within current cache line, 0-10. This provides the second index into
                                                                 SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) When [WAE_USED] is non-zero, this provides the next free WAE number in the cache
                                                                 line of the tail entry. If 0x0, the next entry will be placed at the beginning of
                                                                 a new cache line. This provides the second index into SSO_TAQ()_WAE()_TAG and
                                                                 SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_47_55        : 9;
        uint64_t wae_used              : 15; /**< [ 46: 32](RO/H) Number of WAEs in use. */
        uint64_t reserved_23_31        : 9;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
#else /* Word 0 - Little Endian */
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_23_31        : 9;
        uint64_t wae_used              : 15; /**< [ 46: 32](RO/H) Number of WAEs in use. */
        uint64_t reserved_47_55        : 9;
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) When [WAE_USED] is non-zero, this provides the next free WAE number in the cache
                                                                 line of the tail entry. If 0x0, the next entry will be placed at the beginning of
                                                                 a new cache line. This provides the second index into SSO_TAQ()_WAE()_TAG and
                                                                 SSO_TAQ()_WAE()_WQP. */
        uint64_t wae_head              : 4;  /**< [ 63: 60](RO/H) Head's WAE number within current cache line, 0-10. This provides the second index into
                                                                 SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_tiaqx_status_s cn; */
} bdk_sso_tiaqx_status_t;

static inline uint64_t BDK_SSO_TIAQX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TIAQX_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000c0000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_TIAQX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_TIAQX_STATUS(a) bdk_sso_tiaqx_status_t
#define bustype_BDK_SSO_TIAQX_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TIAQX_STATUS(a) "SSO_TIAQX_STATUS"
#define device_bar_BDK_SSO_TIAQX_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TIAQX_STATUS(a) (a)
#define arguments_BDK_SSO_TIAQX_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_toaq#_status
 *
 * SSO Transitory Output Admission Queue Status Registers
 * Returns TAQ outbound status indexed by group.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_toaqx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t ext_vld               : 1;  /**< [ 61: 61](RO/H) External queuing is in use on this group. */
        uint64_t partial               : 1;  /**< [ 60: 60](RO/H) Partial cache line is allocated to tail of queue. */
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) If PARTIAL is set, this provides the next free WAE number in the cache line of the tail
                                                                 entry. If PARTIAL is clear, the next entry will be placed at the beginning of a new cache
                                                                 line. This provides the
                                                                 second index into SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_43_55        : 13;
        uint64_t cl_used               : 11; /**< [ 42: 32](RO/H) Number of cache lines in use. */
        uint64_t reserved_23_31        : 9;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
#else /* Word 0 - Little Endian */
        uint64_t ent_tail              : 11; /**< [ 10:  0](RO/H) Tail's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_11           : 1;
        uint64_t ent_head              : 11; /**< [ 22: 12](RO/H) Head's entry number. This provides the first index into SSO_TAQ()_WAE()_TAG
                                                                 and SSO_TAQ()_WAE()_WQP. */
        uint64_t reserved_23_31        : 9;
        uint64_t cl_used               : 11; /**< [ 42: 32](RO/H) Number of cache lines in use. */
        uint64_t reserved_43_55        : 13;
        uint64_t wae_tail              : 4;  /**< [ 59: 56](RO/H) If PARTIAL is set, this provides the next free WAE number in the cache line of the tail
                                                                 entry. If PARTIAL is clear, the next entry will be placed at the beginning of a new cache
                                                                 line. This provides the
                                                                 second index into SSO_TAQ()_WAE()_TAG and SSO_TAQ()_WAE()_WQP. */
        uint64_t partial               : 1;  /**< [ 60: 60](RO/H) Partial cache line is allocated to tail of queue. */
        uint64_t ext_vld               : 1;  /**< [ 61: 61](RO/H) External queuing is in use on this group. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_toaqx_status_s cn; */
} bdk_sso_toaqx_status_t;

static inline uint64_t BDK_SSO_TOAQX_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_TOAQX_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000d0000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_TOAQX_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_TOAQX_STATUS(a) bdk_sso_toaqx_status_t
#define bustype_BDK_SSO_TOAQX_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_TOAQX_STATUS(a) "SSO_TOAQX_STATUS"
#define device_bar_BDK_SSO_TOAQX_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_TOAQX_STATUS(a) (a)
#define arguments_BDK_SSO_TOAQX_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_unmap_info
 *
 * SSO Unmapped Error Information Register
 * When any SSO_ERR0[GMID_UNMAP] error occurs, this register is latched with
 * information from the original request.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_unmap_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t gmid                  : 16; /**< [ 15:  0](RO/H) Failing GMID. */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](RO/H) Failing GMID. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_unmap_info_s cn; */
} bdk_sso_unmap_info_t;

#define BDK_SSO_UNMAP_INFO BDK_SSO_UNMAP_INFO_FUNC()
static inline uint64_t BDK_SSO_UNMAP_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_UNMAP_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000012f0ll;
    __bdk_csr_fatal("SSO_UNMAP_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_UNMAP_INFO bdk_sso_unmap_info_t
#define bustype_BDK_SSO_UNMAP_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_UNMAP_INFO "SSO_UNMAP_INFO"
#define device_bar_BDK_SSO_UNMAP_INFO 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_UNMAP_INFO 0
#define arguments_BDK_SSO_UNMAP_INFO -1,-1,-1,-1

/**
 * Register (NCB) sso_vf#_msix_pba#
 *
 * SSO MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the SSO_VF_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vfx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_VF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_VF_INT_VEC_E. Bits that have no associated SSO_VF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SSO_VF_MSIX_VEC()_CTL, enumerated by
                                                                 SSO_VF_INT_VEC_E. Bits that have no associated SSO_VF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vfx_msix_pbax_s cn; */
} bdk_sso_vfx_msix_pbax_t;

static inline uint64_t BDK_SSO_VFX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VFX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x860c000f0000ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("SSO_VFX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_VFX_MSIX_PBAX(a,b) bdk_sso_vfx_msix_pbax_t
#define bustype_BDK_SSO_VFX_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VFX_MSIX_PBAX(a,b) "SSO_VFX_MSIX_PBAX"
#define device_bar_BDK_SSO_VFX_MSIX_PBAX(a,b) 0x14 /* VF_BAR4 */
#define busnum_BDK_SSO_VFX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_SSO_VFX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vf#_msix_vec#_addr
 *
 * SSO MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the SSO_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vfx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_SSO_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](RAZ) Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_SSO_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vfx_msix_vecx_addr_s cn; */
} bdk_sso_vfx_msix_vecx_addr_t;

static inline uint64_t BDK_SSO_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VFX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x860c00000000ll + 0x100000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("SSO_VFX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_VFX_MSIX_VECX_ADDR(a,b) bdk_sso_vfx_msix_vecx_addr_t
#define bustype_BDK_SSO_VFX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VFX_MSIX_VECX_ADDR(a,b) "SSO_VFX_MSIX_VECX_ADDR"
#define device_bar_BDK_SSO_VFX_MSIX_VECX_ADDR(a,b) 0x14 /* VF_BAR4 */
#define busnum_BDK_SSO_VFX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_SSO_VFX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vf#_msix_vec#_ctl
 *
 * SSO MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the SSO_VF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vfx_msix_vecx_ctl_s
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
    /* struct bdk_sso_vfx_msix_vecx_ctl_s cn; */
} bdk_sso_vfx_msix_vecx_ctl_t;

static inline uint64_t BDK_SSO_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VFX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b==0)))
        return 0x860c00000008ll + 0x100000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("SSO_VFX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_VFX_MSIX_VECX_CTL(a,b) bdk_sso_vfx_msix_vecx_ctl_t
#define bustype_BDK_SSO_VFX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VFX_MSIX_VECX_CTL(a,b) "SSO_VFX_MSIX_VECX_CTL"
#define device_bar_BDK_SSO_VFX_MSIX_VECX_CTL(a,b) 0x14 /* VF_BAR4 */
#define busnum_BDK_SSO_VFX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_SSO_VFX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_vhgrp#_aq_cnt
 *
 * SSO Admission Queue Count Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_aq_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t aq_cnt                : 33; /**< [ 32:  0](RO/H) Number of total in-unit, transitional and external admission queue entries for this group. */
#else /* Word 0 - Little Endian */
        uint64_t aq_cnt                : 33; /**< [ 32:  0](RO/H) Number of total in-unit, transitional and external admission queue entries for this group. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_aq_cnt_s cn; */
} bdk_sso_vhgrpx_aq_cnt_t;

static inline uint64_t BDK_SSO_VHGRPX_AQ_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_AQ_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8608000001c0ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_AQ_CNT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_AQ_CNT(a) bdk_sso_vhgrpx_aq_cnt_t
#define bustype_BDK_SSO_VHGRPX_AQ_CNT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_AQ_CNT(a) "SSO_VHGRPX_AQ_CNT"
#define device_bar_BDK_SSO_VHGRPX_AQ_CNT(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_AQ_CNT(a) (a)
#define arguments_BDK_SSO_VHGRPX_AQ_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_aq_thr
 *
 * SSO Total Admission Queue Threshold Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_aq_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t aq_thr                : 33; /**< [ 32:  0](R/W) Total admission queue entry threshold. Compared against SSO_VHGRP()_AQ_CNT for
                                                                 triggering AQ interrupts. */
#else /* Word 0 - Little Endian */
        uint64_t aq_thr                : 33; /**< [ 32:  0](R/W) Total admission queue entry threshold. Compared against SSO_VHGRP()_AQ_CNT for
                                                                 triggering AQ interrupts. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_aq_thr_s cn; */
} bdk_sso_vhgrpx_aq_thr_t;

static inline uint64_t BDK_SSO_VHGRPX_AQ_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_AQ_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8608000001e0ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_AQ_THR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_AQ_THR(a) bdk_sso_vhgrpx_aq_thr_t
#define bustype_BDK_SSO_VHGRPX_AQ_THR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_AQ_THR(a) "SSO_VHGRPX_AQ_THR"
#define device_bar_BDK_SSO_VHGRPX_AQ_THR(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_AQ_THR(a) (a)
#define arguments_BDK_SSO_VHGRPX_AQ_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int
 *
 * SSO Group Interrupt Register
 * Contains the per-group interrupts and are used to clear these interrupts. For more information
 * on this register, refer to Interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) PF to VF mailbox interrupt. Set when SSO_VHGRP(0..63)_MBOX(0) is written. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1C/H) Group AQ exceeded allocation limit. Set when SSO_VHGRP()_AQ_CNT[AQ_CNT] >=
                                                                 SSO_GRP()_AQ_LIMIT[AQ_LIMIT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Work-executable interrupt. Generally used to indicate work is waiting for software.
                                                                 Set by hardware whenever:

                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] >= SSO_VHGRP()_INT_THR [IAQ_THR] and [IAQ_THR] != 0
                                                                 and [EXE_DIS] is clear.

                                                                 * SSO_VHGRP()_INT_CNT[DS_CNT] >= SSO_VHGRP()_INT_THR[DS_THR] and [DS_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[CQ_CNT] >= SSO_VHGRP()_INT_THR[CQ_THR] and [CQ_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0 and SSO_VHGRP()_INT_THR[TC_EN] is set and at least one of the following is
                                                                 true:
                                                                 _ SSO_VHGRP()_INT_CNT[IAQ_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[DS_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[CQ_CNT] > 0 */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) External group queue threshold interrupt. Set if SSO_VHGRP()_AQ_CNT changes, and the
                                                                 resulting value is equal to SSO_VHGRP()_AQ_THR. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) External group queue threshold interrupt. Set if SSO_VHGRP()_AQ_CNT changes, and the
                                                                 resulting value is equal to SSO_VHGRP()_AQ_THR. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Work-executable interrupt. Generally used to indicate work is waiting for software.
                                                                 Set by hardware whenever:

                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] >= SSO_VHGRP()_INT_THR [IAQ_THR] and [IAQ_THR] != 0
                                                                 and [EXE_DIS] is clear.

                                                                 * SSO_VHGRP()_INT_CNT[DS_CNT] >= SSO_VHGRP()_INT_THR[DS_THR] and [DS_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[CQ_CNT] >= SSO_VHGRP()_INT_THR[CQ_THR] and [CQ_THR] != 0.

                                                                 * SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0 and SSO_VHGRP()_INT_THR[TC_EN] is set and at least one of the following is
                                                                 true:
                                                                 _ SSO_VHGRP()_INT_CNT[IAQ_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[DS_CNT] > 0
                                                                 _ SSO_VHGRP()_INT_CNT[CQ_CNT] > 0 */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1C/H) Group AQ exceeded allocation limit. Set when SSO_VHGRP()_AQ_CNT[AQ_CNT] >=
                                                                 SSO_GRP()_AQ_LIMIT[AQ_LIMIT]. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) PF to VF mailbox interrupt. Set when SSO_VHGRP(0..63)_MBOX(0) is written. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_int_s cn; */
} bdk_sso_vhgrpx_int_t;

static inline uint64_t BDK_SSO_VHGRPX_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000100ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_INT(a) bdk_sso_vhgrpx_int_t
#define bustype_BDK_SSO_VHGRPX_INT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_INT(a) "SSO_VHGRPX_INT"
#define device_bar_BDK_SSO_VHGRPX_INT(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_INT(a) (a)
#define arguments_BDK_SSO_VHGRPX_INT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_cnt
 *
 * SSO Work-Queue Interrupt Count Registers
 * These registers contain a read-only copy of the counts used to trigger work-queue interrupts
 * (one per group). For more information on this register, refer to Interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_int_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t tc_cnt                : 13; /**< [ 60: 48](RO/H) Time counter current value for this group. Hardware sets this field to the value of
                                                                 SSO_VHGRP()_INT_THR[TC_THR] whenever:
                                                                 * Corresponding SSO_VHGRP()_INT_CNT[IAQ_CNT, DS_CNT and CQ_CNT] are all equal to 0.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_INT] is written with a one to clear by software.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_DIS] is written with a one to set by software.
                                                                 * Corresponding SSO_VHGRP()_INT_THR is written by software.
                                                                 * TC_CNT is equal to 1 and periodic counter SSO_WQ_INT_PC[PC] is equal to 0.

                                                                 Otherwise, hardware decrements this field whenever the periodic counter SSO_WQ_INT_PC[PC]
                                                                 is equal to 0. This field is 0 whenever SSO_VHGRP()_INT_THR[TC_THR] is equal to 0. */
        uint64_t reserved_45_47        : 3;
        uint64_t cq_cnt                : 13; /**< [ 44: 32](RO/H) Conflicted queue executable count for this group. */
        uint64_t reserved_29_31        : 3;
        uint64_t ds_cnt                : 13; /**< [ 28: 16](RO/H) Deschedule executable count for this group. */
        uint64_t reserved_13_15        : 3;
        uint64_t iaq_cnt               : 13; /**< [ 12:  0](RO/H) Work-queue entries for this in-unit admission queue. */
#else /* Word 0 - Little Endian */
        uint64_t iaq_cnt               : 13; /**< [ 12:  0](RO/H) Work-queue entries for this in-unit admission queue. */
        uint64_t reserved_13_15        : 3;
        uint64_t ds_cnt                : 13; /**< [ 28: 16](RO/H) Deschedule executable count for this group. */
        uint64_t reserved_29_31        : 3;
        uint64_t cq_cnt                : 13; /**< [ 44: 32](RO/H) Conflicted queue executable count for this group. */
        uint64_t reserved_45_47        : 3;
        uint64_t tc_cnt                : 13; /**< [ 60: 48](RO/H) Time counter current value for this group. Hardware sets this field to the value of
                                                                 SSO_VHGRP()_INT_THR[TC_THR] whenever:
                                                                 * Corresponding SSO_VHGRP()_INT_CNT[IAQ_CNT, DS_CNT and CQ_CNT] are all equal to 0.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_INT] is written with a one to clear by software.
                                                                 * Corresponding SSO_VHGRP()_INT[EXE_DIS] is written with a one to set by software.
                                                                 * Corresponding SSO_VHGRP()_INT_THR is written by software.
                                                                 * TC_CNT is equal to 1 and periodic counter SSO_WQ_INT_PC[PC] is equal to 0.

                                                                 Otherwise, hardware decrements this field whenever the periodic counter SSO_WQ_INT_PC[PC]
                                                                 is equal to 0. This field is 0 whenever SSO_VHGRP()_INT_THR[TC_THR] is equal to 0. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_int_cnt_s cn; */
} bdk_sso_vhgrpx_int_cnt_t;

static inline uint64_t BDK_SSO_VHGRPX_INT_CNT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_INT_CNT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000180ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_INT_CNT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_INT_CNT(a) bdk_sso_vhgrpx_int_cnt_t
#define bustype_BDK_SSO_VHGRPX_INT_CNT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_INT_CNT(a) "SSO_VHGRPX_INT_CNT"
#define device_bar_BDK_SSO_VHGRPX_INT_CNT(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_INT_CNT(a) (a)
#define arguments_BDK_SSO_VHGRPX_INT_CNT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_ena_w1c
 *
 * SSO Group Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[MBOX]. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[AQ_LIMIT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[EXE_INT]. */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[AQ_INT]. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[AQ_INT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[EXE_INT]. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[AQ_LIMIT]. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SSO_VHGRP(0..63)_INT[MBOX]. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_int_ena_w1c_s cn; */
} bdk_sso_vhgrpx_int_ena_w1c_t;

static inline uint64_t BDK_SSO_VHGRPX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000118ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_INT_ENA_W1C(a) bdk_sso_vhgrpx_int_ena_w1c_t
#define bustype_BDK_SSO_VHGRPX_INT_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_INT_ENA_W1C(a) "SSO_VHGRPX_INT_ENA_W1C"
#define device_bar_BDK_SSO_VHGRPX_INT_ENA_W1C(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_INT_ENA_W1C(a) (a)
#define arguments_BDK_SSO_VHGRPX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_ena_w1s
 *
 * SSO Group Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[MBOX]. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[AQ_LIMIT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[EXE_INT]. */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[AQ_INT]. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[AQ_INT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[EXE_INT]. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[AQ_LIMIT]. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SSO_VHGRP(0..63)_INT[MBOX]. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_int_ena_w1s_s cn; */
} bdk_sso_vhgrpx_int_ena_w1s_t;

static inline uint64_t BDK_SSO_VHGRPX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000110ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_INT_ENA_W1S(a) bdk_sso_vhgrpx_int_ena_w1s_t
#define bustype_BDK_SSO_VHGRPX_INT_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_INT_ENA_W1S(a) "SSO_VHGRPX_INT_ENA_W1S"
#define device_bar_BDK_SSO_VHGRPX_INT_ENA_W1S(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_INT_ENA_W1S(a) (a)
#define arguments_BDK_SSO_VHGRPX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_thr
 *
 * SSO Work-Queue Interrupt Threshold Registers
 * These registers contain the thresholds for enabling and setting work-queue interrupts (one per
 * group). For more information on this register, refer to Interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_int_thr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tc_en                 : 1;  /**< [ 63: 63](R/W) Time counter interrupt enable for this group. This field must be zero when [TC_THR] is 0. */
        uint64_t reserved_61_62        : 2;
        uint64_t tc_thr                : 13; /**< [ 60: 48](R/W) Time counter interrupt threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT]. When this field is equal to 0,
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is zero. */
        uint64_t reserved_45_47        : 3;
        uint64_t cq_thr                : 13; /**< [ 44: 32](R/W) Conflicted queue count threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[CQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t ds_thr                : 13; /**< [ 28: 16](R/W) Deschedule count threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[DS_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_13_15        : 3;
        uint64_t iaq_thr               : 13; /**< [ 12:  0](R/W) In-unit admission queue threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[IAQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
#else /* Word 0 - Little Endian */
        uint64_t iaq_thr               : 13; /**< [ 12:  0](R/W) In-unit admission queue threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[IAQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_13_15        : 3;
        uint64_t ds_thr                : 13; /**< [ 28: 16](R/W) Deschedule count threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[DS_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_29_31        : 3;
        uint64_t cq_thr                : 13; /**< [ 44: 32](R/W) Conflicted queue count threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[CQ_CNT]. When this field is 0, the threshold interrupt is
                                                                 disabled. */
        uint64_t reserved_45_47        : 3;
        uint64_t tc_thr                : 13; /**< [ 60: 48](R/W) Time counter interrupt threshold for this group. Compared against
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT]. When this field is equal to 0,
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is zero. */
        uint64_t reserved_61_62        : 2;
        uint64_t tc_en                 : 1;  /**< [ 63: 63](R/W) Time counter interrupt enable for this group. This field must be zero when [TC_THR] is 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_int_thr_s cn; */
} bdk_sso_vhgrpx_int_thr_t;

static inline uint64_t BDK_SSO_VHGRPX_INT_THR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_INT_THR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000140ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_INT_THR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_INT_THR(a) bdk_sso_vhgrpx_int_thr_t
#define bustype_BDK_SSO_VHGRPX_INT_THR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_INT_THR(a) "SSO_VHGRPX_INT_THR"
#define device_bar_BDK_SSO_VHGRPX_INT_THR(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_INT_THR(a) (a)
#define arguments_BDK_SSO_VHGRPX_INT_THR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_int_w1s
 *
 * SSO Group Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
        uint64_t reserved_4_62         : 59;
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[MBOX]. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[AQ_LIMIT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[EXE_INT]. */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[AQ_INT]. */
#else /* Word 0 - Little Endian */
        uint64_t aq_int                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[AQ_INT]. */
        uint64_t exe_int               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[EXE_INT]. */
        uint64_t aq_limit              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[AQ_LIMIT]. */
        uint64_t mbox                  : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SSO_VHGRP(0..63)_INT[MBOX]. */
        uint64_t reserved_4_62         : 59;
        uint64_t exe_dis               : 1;  /**< [ 63: 63](R/W1S/H) Executable interrupt temporary disable. Corresponding [EXE_INT] bit cannot be set due to
                                                                 IAQ_CNT/IAQ_THR check when this bit is set. [EXE_DIS] is cleared by hardware whenever:
                                                                 * SSO_VHGRP()_INT_CNT[IAQ_CNT] is zero, or
                                                                 * The hardware decrements the time counter for this group to zero, i.e.
                                                                 SSO_VHGRP()_INT_CNT[TC_CNT] is equal to 1 when periodic counter SSO_WQ_INT_PC[PC] is
                                                                 equal to 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_int_w1s_s cn; */
} bdk_sso_vhgrpx_int_w1s_t;

static inline uint64_t BDK_SSO_VHGRPX_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000108ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_INT_W1S(a) bdk_sso_vhgrpx_int_w1s_t
#define bustype_BDK_SSO_VHGRPX_INT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_INT_W1S(a) "SSO_VHGRPX_INT_W1S"
#define device_bar_BDK_SSO_VHGRPX_INT_W1S(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_INT_W1S(a) (a)
#define arguments_BDK_SSO_VHGRPX_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_op_add_work0
 *
 * SSO Add Work Register 0
 * See SSO_VHGRP()_OP_ADD_WORK1.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_op_add_work0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) Tag type to add, enumerated by SSO_TT_E.  Must not be EMPTY. */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag of the work-queue entry, if [TT] is ATOMIC or ORDERED. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag of the work-queue entry, if [TT] is ATOMIC or ORDERED. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) Tag type to add, enumerated by SSO_TT_E.  Must not be EMPTY. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_op_add_work0_s cn; */
} bdk_sso_vhgrpx_op_add_work0_t;

static inline uint64_t BDK_SSO_VHGRPX_OP_ADD_WORK0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_OP_ADD_WORK0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000800ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_OP_ADD_WORK0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_OP_ADD_WORK0(a) bdk_sso_vhgrpx_op_add_work0_t
#define bustype_BDK_SSO_VHGRPX_OP_ADD_WORK0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_OP_ADD_WORK0(a) "SSO_VHGRPX_OP_ADD_WORK0"
#define device_bar_BDK_SSO_VHGRPX_OP_ADD_WORK0(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_OP_ADD_WORK0(a) (a)
#define arguments_BDK_SSO_VHGRPX_OP_ADD_WORK0(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_op_add_work1
 *
 * SSO Add Work Register 1
 * A write to this register performs an add work. Either:
 *   * A single-transaction 128-bit store (SDP) is used to ADD_WORK0 and ADD_WORK1 to
 *   perform a single add work with both a tag and work pointer.
 *   * Or, a single 64-bit store is used to ADD_WORK1 to perform a single add work which
 *   is untagged.
 *   * Writing SSO_VHGRP()_OP_ADD_WORK0 without a simultanious write to ADD_WORK1
 *   as described above is ignored.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_op_add_work1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](WO) IOVA of the work-queue entry.  Bits <63:49> and <2:0> are ignored. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 64; /**< [ 63:  0](WO) IOVA of the work-queue entry.  Bits <63:49> and <2:0> are ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_op_add_work1_s cn; */
} bdk_sso_vhgrpx_op_add_work1_t;

static inline uint64_t BDK_SSO_VHGRPX_OP_ADD_WORK1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_OP_ADD_WORK1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860800000808ll + 0x100000ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_VHGRPX_OP_ADD_WORK1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_OP_ADD_WORK1(a) bdk_sso_vhgrpx_op_add_work1_t
#define bustype_BDK_SSO_VHGRPX_OP_ADD_WORK1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_OP_ADD_WORK1(a) "SSO_VHGRPX_OP_ADD_WORK1"
#define device_bar_BDK_SSO_VHGRPX_OP_ADD_WORK1(a) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_OP_ADD_WORK1(a) (a)
#define arguments_BDK_SSO_VHGRPX_OP_ADD_WORK1(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_vhgrp#_pf_mbox#
 *
 * SSO VF/PF Mailbox Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_vhgrpx_pf_mboxx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using SSO_PF_VHGRP()_MBOX(). MBOX(0)
                                                                 is typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) (but not SSO_PF_VHGRP(0..63)_MBOX(1)) will set the
                                                                 corresponding SSO_PF_MBOX_INT() bit, which if appropriately enabled will send
                                                                 an interrupt to the PF. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W/H) Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using SSO_PF_VHGRP()_MBOX(). MBOX(0)
                                                                 is typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 SSO_VHGRP(0..63)_PF_MBOX(1) (but not SSO_PF_VHGRP(0..63)_MBOX(1)) will set the
                                                                 corresponding SSO_PF_MBOX_INT() bit, which if appropriately enabled will send
                                                                 an interrupt to the PF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_vhgrpx_pf_mboxx_s cn; */
} bdk_sso_vhgrpx_pf_mboxx_t;

static inline uint64_t BDK_SSO_VHGRPX_PF_MBOXX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_VHGRPX_PF_MBOXX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=63) && (b<=1)))
        return 0x860800000200ll + 0x100000ll * ((a) & 0x3f) + 8ll * ((b) & 0x1);
    __bdk_csr_fatal("SSO_VHGRPX_PF_MBOXX", 2, a, b, 0, 0);
}

#define typedef_BDK_SSO_VHGRPX_PF_MBOXX(a,b) bdk_sso_vhgrpx_pf_mboxx_t
#define bustype_BDK_SSO_VHGRPX_PF_MBOXX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_VHGRPX_PF_MBOXX(a,b) "SSO_VHGRPX_PF_MBOXX"
#define device_bar_BDK_SSO_VHGRPX_PF_MBOXX(a,b) 0x10 /* VF_BAR0 */
#define busnum_BDK_SSO_VHGRPX_PF_MBOXX(a,b) (a)
#define arguments_BDK_SSO_VHGRPX_PF_MBOXX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sso_wq_int_pc
 *
 * SSO Work-Queue Interrupt Periodic Counter Register
 * Contains the threshold value for the work-executable interrupt periodic counter and also a
 * read-only copy of the periodic counter. For more information on this register, refer to
 * Interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_wq_int_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t pc                    : 28; /**< [ 59: 32](RO/H) Work-executable interrupt periodic counter. */
        uint64_t reserved_28_31        : 4;
        uint64_t pc_thr                : 20; /**< [ 27:  8](R/W) Work-executable interrupt periodic counter threshold. Zero disables the counter.
                                                                 If non-zero, the value must be >= 3. */
        uint64_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_7          : 8;
        uint64_t pc_thr                : 20; /**< [ 27:  8](R/W) Work-executable interrupt periodic counter threshold. Zero disables the counter.
                                                                 If non-zero, the value must be >= 3. */
        uint64_t reserved_28_31        : 4;
        uint64_t pc                    : 28; /**< [ 59: 32](RO/H) Work-executable interrupt periodic counter. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_wq_int_pc_s cn; */
} bdk_sso_wq_int_pc_t;

#define BDK_SSO_WQ_INT_PC BDK_SSO_WQ_INT_PC_FUNC()
static inline uint64_t BDK_SSO_WQ_INT_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_WQ_INT_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001020ll;
    __bdk_csr_fatal("SSO_WQ_INT_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_WQ_INT_PC bdk_sso_wq_int_pc_t
#define bustype_BDK_SSO_WQ_INT_PC BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_WQ_INT_PC "SSO_WQ_INT_PC"
#define device_bar_BDK_SSO_WQ_INT_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_WQ_INT_PC 0
#define arguments_BDK_SSO_WQ_INT_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_ws_cfg
 *
 * SSO Configuration Register
 * This register contains various SSO work-slot configuration bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ws_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t ocla_bp               : 8;  /**< [ 55: 48](R/W) Enable OCLA backpressure stalls. For diagnostic use only.
                                                                 Internal:
                                                                 <55> = NCBB input fifo stall (ncbo).
                                                                 <54> = Work-slot response. (arbrsp).
                                                                 <53> = Work-slot switching of descheduled work entries. (arbx).
                                                                 <52> = Work-slot SWTAG response. (arbs).
                                                                 <51> = Work-slot access to get-work engine. (arbgw).
                                                                 <50> = Work-slot CAM access. (arbc).
                                                                 <49> = Work-slot RAM access. (arbr).
                                                                 <48> = Work-slot pushes to AQ, CQ, DQ. (arbq). */
        uint64_t reserved_8_47         : 40;
        uint64_t sai_flush             : 1;  /**< [  7:  7](R/W1) When written with one, send a pulse to invalidate the VHWS switch tag cache
                                                                 inside the cores.  Reads as zero. For diagnostic use only. */
        uint64_t aw_clk_dis            : 1;  /**< [  6:  6](R/W) Reserved. */
        uint64_t gw_clk_dis            : 1;  /**< [  5:  5](R/W) Reserved. */
        uint64_t disable_pw            : 1;  /**< [  4:  4](R/W) Reserved. */
        uint64_t arbc_step_en          : 1;  /**< [  3:  3](R/W) Enable single-stepping WS CAM arbiter, twice per 16 clocks. For diagnostic use only. */
        uint64_t ncbo_step_en          : 1;  /**< [  2:  2](R/W) Enable single-stepping commands from NCBO, once per 32 clocks. For diagnostic use only. */
        uint64_t soc_ccam_dis          : 1;  /**< [  1:  1](R/W) Disable power saving SOC conditional CAM. */
        uint64_t sso_cclk_dis          : 1;  /**< [  0:  0](R/W) Disable power saving SSO conditional clocking, */
#else /* Word 0 - Little Endian */
        uint64_t sso_cclk_dis          : 1;  /**< [  0:  0](R/W) Disable power saving SSO conditional clocking, */
        uint64_t soc_ccam_dis          : 1;  /**< [  1:  1](R/W) Disable power saving SOC conditional CAM. */
        uint64_t ncbo_step_en          : 1;  /**< [  2:  2](R/W) Enable single-stepping commands from NCBO, once per 32 clocks. For diagnostic use only. */
        uint64_t arbc_step_en          : 1;  /**< [  3:  3](R/W) Enable single-stepping WS CAM arbiter, twice per 16 clocks. For diagnostic use only. */
        uint64_t disable_pw            : 1;  /**< [  4:  4](R/W) Reserved. */
        uint64_t gw_clk_dis            : 1;  /**< [  5:  5](R/W) Reserved. */
        uint64_t aw_clk_dis            : 1;  /**< [  6:  6](R/W) Reserved. */
        uint64_t sai_flush             : 1;  /**< [  7:  7](R/W1) When written with one, send a pulse to invalidate the VHWS switch tag cache
                                                                 inside the cores.  Reads as zero. For diagnostic use only. */
        uint64_t reserved_8_47         : 40;
        uint64_t ocla_bp               : 8;  /**< [ 55: 48](R/W) Enable OCLA backpressure stalls. For diagnostic use only.
                                                                 Internal:
                                                                 <55> = NCBB input fifo stall (ncbo).
                                                                 <54> = Work-slot response. (arbrsp).
                                                                 <53> = Work-slot switching of descheduled work entries. (arbx).
                                                                 <52> = Work-slot SWTAG response. (arbs).
                                                                 <51> = Work-slot access to get-work engine. (arbgw).
                                                                 <50> = Work-slot CAM access. (arbc).
                                                                 <49> = Work-slot RAM access. (arbr).
                                                                 <48> = Work-slot pushes to AQ, CQ, DQ. (arbq). */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_ws_cfg_s cn; */
} bdk_sso_ws_cfg_t;

#define BDK_SSO_WS_CFG BDK_SSO_WS_CFG_FUNC()
static inline uint64_t BDK_SSO_WS_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_WS_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001088ll;
    __bdk_csr_fatal("SSO_WS_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_WS_CFG bdk_sso_ws_cfg_t
#define bustype_BDK_SSO_WS_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_WS_CFG "SSO_WS_CFG"
#define device_bar_BDK_SSO_WS_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_WS_CFG 0
#define arguments_BDK_SSO_WS_CFG -1,-1,-1,-1

/**
 * Register (NCB) sso_ws_eco
 *
 * INTERNAL: SSO_WS ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_ws_eco_s
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
    /* struct bdk_sso_ws_eco_s cn; */
} bdk_sso_ws_eco_t;

#define BDK_SSO_WS_ECO BDK_SSO_WS_ECO_FUNC()
static inline uint64_t BDK_SSO_WS_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_WS_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000001048ll;
    __bdk_csr_fatal("SSO_WS_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_WS_ECO bdk_sso_ws_eco_t
#define bustype_BDK_SSO_WS_ECO BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_WS_ECO "SSO_WS_ECO"
#define device_bar_BDK_SSO_WS_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_WS_ECO 0
#define arguments_BDK_SSO_WS_ECO -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq#_head_next
 *
 * SSO External Admission Queue Head Next Register
 * These registers contain the pointer to the next buffer to become the head when the final cache
 * line in this buffer is read.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaqx_head_next_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaqx_head_next_s cn; */
} bdk_sso_xaqx_head_next_t;

static inline uint64_t BDK_SSO_XAQX_HEAD_NEXT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQX_HEAD_NEXT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000a0000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_XAQX_HEAD_NEXT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQX_HEAD_NEXT(a) bdk_sso_xaqx_head_next_t
#define bustype_BDK_SSO_XAQX_HEAD_NEXT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQX_HEAD_NEXT(a) "SSO_XAQX_HEAD_NEXT"
#define device_bar_BDK_SSO_XAQX_HEAD_NEXT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQX_HEAD_NEXT(a) (a)
#define arguments_BDK_SSO_XAQX_HEAD_NEXT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_head_ptr
 *
 * SSO External Admission Queue Head Pointer Register
 * These registers contain the pointer to the first entry of the external linked list(s) for a
 * particular group. Software must initialize the external linked list(s) by programming
 * SSO_XAQ()_HEAD_PTR, SSO_XAQ()_HEAD_NEXT, SSO_XAQ()_TAIL_PTR and
 * SSO_XAQ()_TAIL_NEXT to identical values.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaqx_head_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_5_6          : 2;
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
        uint64_t reserved_5_6          : 2;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaqx_head_ptr_s cn; */
} bdk_sso_xaqx_head_ptr_t;

static inline uint64_t BDK_SSO_XAQX_HEAD_PTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQX_HEAD_PTR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860000080000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_XAQX_HEAD_PTR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQX_HEAD_PTR(a) bdk_sso_xaqx_head_ptr_t
#define bustype_BDK_SSO_XAQX_HEAD_PTR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQX_HEAD_PTR(a) "SSO_XAQX_HEAD_PTR"
#define device_bar_BDK_SSO_XAQX_HEAD_PTR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQX_HEAD_PTR(a) (a)
#define arguments_BDK_SSO_XAQX_HEAD_PTR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_memmgt
 *
 * SSO External Admission Queue Memory Management Register
 * These registers configure the XAQ memory management.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaqx_memmgt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t strm                  : 8;  /**< [  7:  0](R/W) Stream identifier bits <7:0>. Resets and typically programmed to the index (XAQ
                                                                 and VF number) plus one, to match standard SR-IOV function number assignment. */
#else /* Word 0 - Little Endian */
        uint64_t strm                  : 8;  /**< [  7:  0](R/W) Stream identifier bits <7:0>. Resets and typically programmed to the index (XAQ
                                                                 and VF number) plus one, to match standard SR-IOV function number assignment. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaqx_memmgt_s cn; */
} bdk_sso_xaqx_memmgt_t;

static inline uint64_t BDK_SSO_XAQX_MEMMGT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQX_MEMMGT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000e0000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_XAQX_MEMMGT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQX_MEMMGT(a) bdk_sso_xaqx_memmgt_t
#define bustype_BDK_SSO_XAQX_MEMMGT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQX_MEMMGT(a) "SSO_XAQX_MEMMGT"
#define device_bar_BDK_SSO_XAQX_MEMMGT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQX_MEMMGT(a) (a)
#define arguments_BDK_SSO_XAQX_MEMMGT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_tail_next
 *
 * SSO External Admission Queue Tail Next Register
 * These registers contain the pointer to the next buffer to become the tail when the final cache
 * line in this buffer is written.  Register fields are identical to those in
 * SSO_XAQ()_HEAD_NEXT above.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaqx_tail_next_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_0_6          : 7;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_6          : 7;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaqx_tail_next_s cn; */
} bdk_sso_xaqx_tail_next_t;

static inline uint64_t BDK_SSO_XAQX_TAIL_NEXT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQX_TAIL_NEXT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x8600000b0000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_XAQX_TAIL_NEXT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQX_TAIL_NEXT(a) bdk_sso_xaqx_tail_next_t
#define bustype_BDK_SSO_XAQX_TAIL_NEXT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQX_TAIL_NEXT(a) "SSO_XAQX_TAIL_NEXT"
#define device_bar_BDK_SSO_XAQX_TAIL_NEXT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQX_TAIL_NEXT(a) (a)
#define arguments_BDK_SSO_XAQX_TAIL_NEXT(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq#_tail_ptr
 *
 * SSO External Admission Queue Tail Pointer Register
 * These registers contain the pointer to the last entry of the external linked list(s) for a
 * particular group.  Register fields are identical to those in SSO_XAQ()_HEAD_PTR above.
 * Software must initialize the external linked list(s) by programming
 * SSO_XAQ()_HEAD_PTR, SSO_XAQ()_HEAD_NEXT, SSO_XAQ()_TAIL_PTR and
 * SSO_XAQ()_TAIL_NEXT to identical values.
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaqx_tail_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_5_6          : 2;
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
#else /* Word 0 - Little Endian */
        uint64_t cl                    : 5;  /**< [  4:  0](R/W/H) Cache line number in buffer. Cache line zero contains the next pointer. */
        uint64_t reserved_5_6          : 2;
        uint64_t ptr                   : 42; /**< [ 48:  7](R/W/H) IOVA pointer, divided by 128 bytes.
                                                                 Internal:
                                                                 For peak performance, all XAQ buffers should reside on the local node's memory. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaqx_tail_ptr_s cn; */
} bdk_sso_xaqx_tail_ptr_t;

static inline uint64_t BDK_SSO_XAQX_TAIL_PTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQX_TAIL_PTR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=63))
        return 0x860000090000ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("SSO_XAQX_TAIL_PTR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQX_TAIL_PTR(a) bdk_sso_xaqx_tail_ptr_t
#define bustype_BDK_SSO_XAQX_TAIL_PTR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQX_TAIL_PTR(a) "SSO_XAQX_TAIL_PTR"
#define device_bar_BDK_SSO_XAQX_TAIL_PTR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQX_TAIL_PTR(a) (a)
#define arguments_BDK_SSO_XAQX_TAIL_PTR(a) (a),-1,-1,-1

/**
 * Register (NCB) sso_xaq_aura
 *
 * SSO External Admission Queue Aura Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaq_aura_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t laura                 : 12; /**< [ 11:  0](R/W) FPA guest-aura to use for SSO XAQ allocations and frees. The FPA guest-aura
                                                                 selected by LAURA must correspond to a pool where the buffers (after any
                                                                 FPA_POOL()_CFG[BUF_OFFSET]) are at least 4 KB.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and SSO_XAQ_GMCTL[GMID] as valid. */
#else /* Word 0 - Little Endian */
        uint64_t laura                 : 12; /**< [ 11:  0](R/W) FPA guest-aura to use for SSO XAQ allocations and frees. The FPA guest-aura
                                                                 selected by LAURA must correspond to a pool where the buffers (after any
                                                                 FPA_POOL()_CFG[BUF_OFFSET]) are at least 4 KB.
                                                                 For the FPA to not discard the request, FPA_PF_MAP() must map
                                                                 [AURA] and SSO_XAQ_GMCTL[GMID] as valid. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaq_aura_s cn; */
} bdk_sso_xaq_aura_t;

#define BDK_SSO_XAQ_AURA BDK_SSO_XAQ_AURA_FUNC()
static inline uint64_t BDK_SSO_XAQ_AURA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQ_AURA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002100ll;
    __bdk_csr_fatal("SSO_XAQ_AURA", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQ_AURA bdk_sso_xaq_aura_t
#define bustype_BDK_SSO_XAQ_AURA BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQ_AURA "SSO_XAQ_AURA"
#define device_bar_BDK_SSO_XAQ_AURA 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQ_AURA 0
#define arguments_BDK_SSO_XAQ_AURA -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq_gmctl
 *
 * SSO External Admission Queue Guest Machine Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaq_gmctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all buffer
                                                                 free/allocates.
                                                                 Must be non-zero or FPA will drop requests; see FPA_PF_MAP(). */
#else /* Word 0 - Little Endian */
        uint64_t gmid                  : 16; /**< [ 15:  0](R/W) Guest machine identifier. The GMID to send to FPA for all buffer
                                                                 free/allocates.
                                                                 Must be non-zero or FPA will drop requests; see FPA_PF_MAP(). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaq_gmctl_s cn; */
} bdk_sso_xaq_gmctl_t;

#define BDK_SSO_XAQ_GMCTL BDK_SSO_XAQ_GMCTL_FUNC()
static inline uint64_t BDK_SSO_XAQ_GMCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQ_GMCTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x860000002110ll;
    __bdk_csr_fatal("SSO_XAQ_GMCTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQ_GMCTL bdk_sso_xaq_gmctl_t
#define bustype_BDK_SSO_XAQ_GMCTL BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQ_GMCTL "SSO_XAQ_GMCTL"
#define device_bar_BDK_SSO_XAQ_GMCTL 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQ_GMCTL 0
#define arguments_BDK_SSO_XAQ_GMCTL -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq_latency_pc
 *
 * SSO External Admission Queue Latency Perf-Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaq_latency_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for XAQ read returns. This may be divided by SSO_XAQ_REQ_PC to
                                                                 determine the average read latency. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of cycles waiting for XAQ read returns. This may be divided by SSO_XAQ_REQ_PC to
                                                                 determine the average read latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaq_latency_pc_s cn; */
} bdk_sso_xaq_latency_pc_t;

#define BDK_SSO_XAQ_LATENCY_PC BDK_SSO_XAQ_LATENCY_PC_FUNC()
static inline uint64_t BDK_SSO_XAQ_LATENCY_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQ_LATENCY_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020b8ll;
    __bdk_csr_fatal("SSO_XAQ_LATENCY_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQ_LATENCY_PC bdk_sso_xaq_latency_pc_t
#define bustype_BDK_SSO_XAQ_LATENCY_PC BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQ_LATENCY_PC "SSO_XAQ_LATENCY_PC"
#define device_bar_BDK_SSO_XAQ_LATENCY_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQ_LATENCY_PC 0
#define arguments_BDK_SSO_XAQ_LATENCY_PC -1,-1,-1,-1

/**
 * Register (NCB) sso_xaq_req_pc
 *
 * SSO External Admission Queue Requests Perf-Count Register
 */
typedef union
{
    uint64_t u;
    struct bdk_sso_xaq_req_pc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of XAQ read requests. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 64; /**< [ 63:  0](R/W/H) Number of XAQ read requests. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_sso_xaq_req_pc_s cn; */
} bdk_sso_xaq_req_pc_t;

#define BDK_SSO_XAQ_REQ_PC BDK_SSO_XAQ_REQ_PC_FUNC()
static inline uint64_t BDK_SSO_XAQ_REQ_PC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSO_XAQ_REQ_PC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8600000020b0ll;
    __bdk_csr_fatal("SSO_XAQ_REQ_PC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_SSO_XAQ_REQ_PC bdk_sso_xaq_req_pc_t
#define bustype_BDK_SSO_XAQ_REQ_PC BDK_CSR_TYPE_NCB
#define basename_BDK_SSO_XAQ_REQ_PC "SSO_XAQ_REQ_PC"
#define device_bar_BDK_SSO_XAQ_REQ_PC 0x0 /* PF_BAR0 */
#define busnum_BDK_SSO_XAQ_REQ_PC 0
#define arguments_BDK_SSO_XAQ_REQ_PC -1,-1,-1,-1

#endif /* __BDK_CSRS_SSO_H__ */
