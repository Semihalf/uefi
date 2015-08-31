#ifndef __BDK_CSRS_SSOW_H__
#define __BDK_CSRS_SSOW_H__
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
 * Cavium SSOW.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ssow_bar_e
 *
 * SSO Work Slot Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_SSOW_BAR_E_SSOW_PF_BAR0 (0x861000000000ll) /**< Base address for standard PF registers. */
#define BDK_SSOW_BAR_E_SSOW_VFX_BAR0(a) (0x861800000000ll + 0x100000ll * (a)) /**< (0..31)Base address for SR-IOV registers. */

/**
 * Structure ssow_clr_nsched_addr_s
 *
 * SSO Clear Noschedule Address Structure
 * This structure determines the address offset for SSOW_VHWS()_OP_CLR_NSCHED.
 */
union bdk_ssow_clr_nsched_addr_s
{
    uint32_t u;
    struct bdk_ssow_clr_nsched_addr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t index                 : 13; /**< [ 15:  3] Index to clear. */
        uint32_t reserved_0_2          : 3;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_2          : 3;
        uint32_t index                 : 13; /**< [ 15:  3] Index to clear. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_clr_nsched_addr_s_s cn; */
};

/**
 * Structure ssow_get_work_addr_s
 *
 * SSO Get-Work Address Structure
 * This structure determines the address offset for SSOW_VHWS()_OP_GET_WORK0 and
 * SSOW_VHWS()_OP_GET_WORK1.
 */
union bdk_ssow_get_work_addr_s
{
    uint32_t u;
    struct bdk_ssow_get_work_addr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_19_31        : 13;
        uint32_t indexed               : 1;  /**< [ 18: 18] Indexed get work. If set, indexed get work, specified in [INDEX_GRP_MASK]. */
        uint32_t grouped               : 1;  /**< [ 17: 17] Get from a specific group number, specified in [INDEX_GRP_MASK]. */
        uint32_t waitw                 : 1;  /**< [ 16: 16] If set, wait for work; don't return load result until work is available or timeout. Must
                                                                 be zero if [INDEXED] is set. */
        uint32_t index_grp_mask        : 12; /**< [ 15:  4] Index or group or masks.

                                                                 If [INDEXED] = 1, <15:4> provides the index to get work from.

                                                                 If [GROUPED] = 1, <13:4> provides the group number.

                                                                 Otherwise, <5:4> indicates how to use the mask sets in SSO_HWS()_S()_GRPMSK()
                                                                 (<15:6> are ignored):
                                                                 0x0 = use mask set 0 as high priority, and mask set 1 as lower priority if no groups
                                                                 satisfy mask set 0.
                                                                 0x1 = use mask set 0.
                                                                 0x2 = use mask set 1.
                                                                 0x3 = reserved. */
        uint32_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_3          : 4;
        uint32_t index_grp_mask        : 12; /**< [ 15:  4] Index or group or masks.

                                                                 If [INDEXED] = 1, <15:4> provides the index to get work from.

                                                                 If [GROUPED] = 1, <13:4> provides the group number.

                                                                 Otherwise, <5:4> indicates how to use the mask sets in SSO_HWS()_S()_GRPMSK()
                                                                 (<15:6> are ignored):
                                                                 0x0 = use mask set 0 as high priority, and mask set 1 as lower priority if no groups
                                                                 satisfy mask set 0.
                                                                 0x1 = use mask set 0.
                                                                 0x2 = use mask set 1.
                                                                 0x3 = reserved. */
        uint32_t waitw                 : 1;  /**< [ 16: 16] If set, wait for work; don't return load result until work is available or timeout. Must
                                                                 be zero if [INDEXED] is set. */
        uint32_t grouped               : 1;  /**< [ 17: 17] Get from a specific group number, specified in [INDEX_GRP_MASK]. */
        uint32_t indexed               : 1;  /**< [ 18: 18] Indexed get work. If set, indexed get work, specified in [INDEX_GRP_MASK]. */
        uint32_t reserved_19_31        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_get_work_addr_s_s cn; */
};

/**
 * Register (NCB) ssow_vhws#_grpmsk_chg#
 *
 * SSO Work Slot VF Tag Status Registers
 * These registers change which group or groups a HWS belongs to. Two registers are
 * provided so 4 bits may be changed using a multi-word store instruction (STP, ST1 or
 * LMTDMA).
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_grpmsk_chgx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_25_63        : 39;
        uint64_t set                   : 1;  /**< [ 24: 24](RO/H) Set/clear membership.

                                                                 0 = Disable this HWS's membership in the group [GRP].  This clears the
                                                                 corresponding bit in SSO_HWS(<hws>)_S(<s>)_GRPMSK()<g>, where <hws> is
                                                                 determined from this register address, <s> is from [MSKSET], and <g> is [GRP].

                                                                 1 = Enable this HWS's membership in the group [GRP].  This sets the
                                                                 corresponding bit in SSO_HWS(<hws>)_S(<s>)_GRPMSK()<g>, where <hws> is
                                                                 determined from this register address, <s> is from [MSKSET], and <g> is [GRP]. */
        uint64_t reserved_17_23        : 7;
        uint64_t mskset                : 1;  /**< [ 16: 16](WO) Set number to enable/diable membership in. */
        uint64_t reserved_6_15         : 10;
        uint64_t grp                   : 6;  /**< [  5:  0](WO) Group number to enable/disable membership in. */
#else /* Word 0 - Little Endian */
        uint64_t grp                   : 6;  /**< [  5:  0](WO) Group number to enable/disable membership in. */
        uint64_t reserved_6_15         : 10;
        uint64_t mskset                : 1;  /**< [ 16: 16](WO) Set number to enable/diable membership in. */
        uint64_t reserved_17_23        : 7;
        uint64_t set                   : 1;  /**< [ 24: 24](RO/H) Set/clear membership.

                                                                 0 = Disable this HWS's membership in the group [GRP].  This clears the
                                                                 corresponding bit in SSO_HWS(<hws>)_S(<s>)_GRPMSK()<g>, where <hws> is
                                                                 determined from this register address, <s> is from [MSKSET], and <g> is [GRP].

                                                                 1 = Enable this HWS's membership in the group [GRP].  This sets the
                                                                 corresponding bit in SSO_HWS(<hws>)_S(<s>)_GRPMSK()<g>, where <hws> is
                                                                 determined from this register address, <s> is from [MSKSET], and <g> is [GRP]. */
        uint64_t reserved_25_63        : 39;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_grpmsk_chgx_s cn; */
} bdk_ssow_vhwsx_grpmsk_chgx_t;

static inline uint64_t BDK_SSOW_VHWSX_GRPMSK_CHGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_GRPMSK_CHGX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=31) && (b<=3)))
        return 0x861800000080ll + 0x100000ll * ((a) & 0x1f) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("SSOW_VHWSX_GRPMSK_CHGX", 2, a, b, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_GRPMSK_CHGX(a,b) bdk_ssow_vhwsx_grpmsk_chgx_t
#define bustype_BDK_SSOW_VHWSX_GRPMSK_CHGX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_GRPMSK_CHGX(a,b) "SSOW_VHWSX_GRPMSK_CHGX"
#define busnum_BDK_SSOW_VHWSX_GRPMSK_CHGX(a,b) (a)
#define arguments_BDK_SSOW_VHWSX_GRPMSK_CHGX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) ssow_vhws#_links
 *
 * SSO Work Slot VF Links Status Registers
 * Returns status of each HWS.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_links_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tailc                 : 1;  /**< [ 63: 63](RO/H) Set when this SSO entry is the tail of the conflicted tail chain, and so there are no
                                                                 additional conflicts on this tag chain. */
        uint64_t reserved_58_62        : 5;
        uint64_t index                 : 10; /**< [ 57: 48](RO/H) The SSO entry attached to the HWS. */
        uint64_t reserved_36_47        : 12;
        uint64_t grp                   : 8;  /**< [ 35: 28](RO/H) The group attached to the HWS (updated when new tag list entered on SWTAG_FULL).
                                                                 INTERNAL: The upper two bits are hardcoded to the node number. */
        uint64_t head                  : 1;  /**< [ 27: 27](RO/H) Set when this SSO entry is at the head of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t tail                  : 1;  /**< [ 26: 26](RO/H) Set when this SSO entry is at the tail of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t reserved_21_25        : 5;
        uint64_t revlink_index         : 10; /**< [ 20: 11](RO/H) Prior SSO entry in the tag list when HEAD=0 and TT is not UNTAGGED nor EMPTY, otherwise
                                                                 unpredictable. */
        uint64_t link_index_vld        : 1;  /**< [ 10: 10](RO/H) Indicates [LINK_INDEX] is valid. LINK_INDEX_VLD is itself valid when TAIL=1 and
                                                                 TT=ATOMIC, otherwise unpredictable. */
        uint64_t link_index            : 10; /**< [  9:  0](RO/H) Next SSO entry in the tag list when [LINK_INDEX_VLD]=1, [TAILC]=0 and
                                                                 [TT]=ATOMIC, otherwise unpredictable. */
#else /* Word 0 - Little Endian */
        uint64_t link_index            : 10; /**< [  9:  0](RO/H) Next SSO entry in the tag list when [LINK_INDEX_VLD]=1, [TAILC]=0 and
                                                                 [TT]=ATOMIC, otherwise unpredictable. */
        uint64_t link_index_vld        : 1;  /**< [ 10: 10](RO/H) Indicates [LINK_INDEX] is valid. LINK_INDEX_VLD is itself valid when TAIL=1 and
                                                                 TT=ATOMIC, otherwise unpredictable. */
        uint64_t revlink_index         : 10; /**< [ 20: 11](RO/H) Prior SSO entry in the tag list when HEAD=0 and TT is not UNTAGGED nor EMPTY, otherwise
                                                                 unpredictable. */
        uint64_t reserved_21_25        : 5;
        uint64_t tail                  : 1;  /**< [ 26: 26](RO/H) Set when this SSO entry is at the tail of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t head                  : 1;  /**< [ 27: 27](RO/H) Set when this SSO entry is at the head of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t grp                   : 8;  /**< [ 35: 28](RO/H) The group attached to the HWS (updated when new tag list entered on SWTAG_FULL).
                                                                 INTERNAL: The upper two bits are hardcoded to the node number. */
        uint64_t reserved_36_47        : 12;
        uint64_t index                 : 10; /**< [ 57: 48](RO/H) The SSO entry attached to the HWS. */
        uint64_t reserved_58_62        : 5;
        uint64_t tailc                 : 1;  /**< [ 63: 63](RO/H) Set when this SSO entry is the tail of the conflicted tail chain, and so there are no
                                                                 additional conflicts on this tag chain. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_links_s cn; */
} bdk_ssow_vhwsx_links_t;

static inline uint64_t BDK_SSOW_VHWSX_LINKS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_LINKS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000310ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_LINKS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_LINKS(a) bdk_ssow_vhwsx_links_t
#define bustype_BDK_SSOW_VHWSX_LINKS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_LINKS(a) "SSOW_VHWSX_LINKS"
#define busnum_BDK_SSOW_VHWSX_LINKS(a) (a)
#define arguments_BDK_SSOW_VHWSX_LINKS(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_alloc_we
 *
 * SSO Work Slot VF Allocate Work Entry Operation Register
 * A read to this register allocates a work entry.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_alloc_we_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t state                 : 2;  /**< [  1:  0](RO/H) See SSO_TT_E enumeration; returns EMPTY on failure. */
#else /* Word 0 - Little Endian */
        uint64_t state                 : 2;  /**< [  1:  0](RO/H) See SSO_TT_E enumeration; returns EMPTY on failure. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_alloc_we_s cn; */
} bdk_ssow_vhwsx_op_alloc_we_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_ALLOC_WE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_ALLOC_WE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000410ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_ALLOC_WE", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_ALLOC_WE(a) bdk_ssow_vhwsx_op_alloc_we_t
#define bustype_BDK_SSOW_VHWSX_OP_ALLOC_WE(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_ALLOC_WE(a) "SSOW_VHWSX_OP_ALLOC_WE"
#define busnum_BDK_SSOW_VHWSX_OP_ALLOC_WE(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_ALLOC_WE(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_clr_nsched
 *
 * SSO Work Slot VF Clear Noschedule Operation Register
 * A write to this register performs a CLR_NSCHED.
 *
 * The address offset is calculated using SSOW_CLR_NSCHED_ADDR_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_clr_nsched_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t wqp                   : 49; /**< [ 48:  0](WO) IOVA of the work-queue entry to CLR_NSCHED on. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 49; /**< [ 48:  0](WO) IOVA of the work-queue entry to CLR_NSCHED on. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_clr_nsched_s cn; */
} bdk_ssow_vhwsx_op_clr_nsched_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_CLR_NSCHED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_CLR_NSCHED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800010000ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_CLR_NSCHED", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_CLR_NSCHED(a) bdk_ssow_vhwsx_op_clr_nsched_t
#define bustype_BDK_SSOW_VHWSX_OP_CLR_NSCHED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_CLR_NSCHED(a) "SSOW_VHWSX_OP_CLR_NSCHED"
#define busnum_BDK_SSOW_VHWSX_OP_CLR_NSCHED(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_CLR_NSCHED(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_desched
 *
 * SSO Work Slot VF Deschedule Operation Register
 * A write to this register performs a deschedule operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_desched_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_desched_s cn; */
} bdk_ssow_vhwsx_op_desched_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_DESCHED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_DESCHED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000860ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_DESCHED", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_DESCHED(a) bdk_ssow_vhwsx_op_desched_t
#define bustype_BDK_SSOW_VHWSX_OP_DESCHED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_DESCHED(a) "SSOW_VHWSX_OP_DESCHED"
#define busnum_BDK_SSOW_VHWSX_OP_DESCHED(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_DESCHED(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_desched_nosch
 *
 * SSO Work Slot VF Deschedule Noschedule Operation Register
 * A write to this register performs a deschedule nosched operation.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_desched_nosch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_desched_nosch_s cn; */
} bdk_ssow_vhwsx_op_desched_nosch_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000870ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_DESCHED_NOSCH", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(a) bdk_ssow_vhwsx_op_desched_nosch_t
#define bustype_BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(a) "SSOW_VHWSX_OP_DESCHED_NOSCH"
#define busnum_BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_DESCHED_NOSCH(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_get_work0
 *
 * SSO Work Slot VF Get-Work Operation Register 0
 * A read to this register performs a get work. A single-transaction 128-bit load (LDP)
 * may be used to GET_WORK0 and GET_WORK1 to perform a single get work and return both
 * the tag and WQP.
 *
 * The address offset is calculated using SSOW_GET_WORK_ADDR_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_get_work0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t index                 : 14; /**< [ 63: 50](RO/H) Index for the work-queue entry. Unpredictable when SSOW_VHWS()_OP_GET_WORK1[NO_WORK] set. */
        uint64_t reserved_44_49        : 6;
        uint64_t grp                   : 10; /**< [ 43: 34](RO/H) Group of the returned work. Returns zero if [RTNGRP] was clear in the request, else
                                                                 unpredictable if [NO_WORK] set. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) Tag type of returned work, enumerated by SSO_TT_E. Returns zero if [RTNGRP] was clear in
                                                                 the request, otherwise if [NO_WORK] set returns EMPTY if the work slot was previously
                                                                 empty, else UNTAGGED. */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) Tag of the work-queue entry. Unpredictable when SSOW_VHWS()_OP_GET_WORK1[NO_WORK] set. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) Tag of the work-queue entry. Unpredictable when SSOW_VHWS()_OP_GET_WORK1[NO_WORK] set. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) Tag type of returned work, enumerated by SSO_TT_E. Returns zero if [RTNGRP] was clear in
                                                                 the request, otherwise if [NO_WORK] set returns EMPTY if the work slot was previously
                                                                 empty, else UNTAGGED. */
        uint64_t grp                   : 10; /**< [ 43: 34](RO/H) Group of the returned work. Returns zero if [RTNGRP] was clear in the request, else
                                                                 unpredictable if [NO_WORK] set. */
        uint64_t reserved_44_49        : 6;
        uint64_t index                 : 14; /**< [ 63: 50](RO/H) Index for the work-queue entry. Unpredictable when SSOW_VHWS()_OP_GET_WORK1[NO_WORK] set. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_get_work0_s cn; */
} bdk_ssow_vhwsx_op_get_work0_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_GET_WORK0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_GET_WORK0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800080000ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_GET_WORK0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_GET_WORK0(a) bdk_ssow_vhwsx_op_get_work0_t
#define bustype_BDK_SSOW_VHWSX_OP_GET_WORK0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_GET_WORK0(a) "SSOW_VHWSX_OP_GET_WORK0"
#define busnum_BDK_SSOW_VHWSX_OP_GET_WORK0(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_GET_WORK0(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_get_work1
 *
 * SSO Work Slot VF Get-Work Operation Register 1
 * A read to this register performs a get work. A single-transaction 128-bit load (LDP)
 * may be used to GET_WORK0 and GET_WORK1 to perform a single get work and return both
 * the tag and WQP.
 *
 * The address offset is calculated using SSOW_GET_WORK_ADDR_S.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_get_work1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t no_work               : 1;  /**< [ 63: 63](RO/H) Set when no new work-queue entry was returned. */
        uint64_t pend_switch           : 1;  /**< [ 62: 62](RO/H) Pending Switch. Set in the result of an indexed GET_WORK when there is a pending SWTAG,
                                                                 SWTAG_FULL, or SWTAG_DESCHED to ORDERED or ATOMIC. Always clear otherwise. (The DESCHED
                                                                 portion of a SWTAG_DESCHED cannot still be pending.) */
        uint64_t reserved_49_61        : 13;
        uint64_t wqp                   : 49; /**< [ 48:  0](RO/H) IOVA of the work-queue entry. Unpredictable when [NO_WORK] = 1. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 49; /**< [ 48:  0](RO/H) IOVA of the work-queue entry. Unpredictable when [NO_WORK] = 1. */
        uint64_t reserved_49_61        : 13;
        uint64_t pend_switch           : 1;  /**< [ 62: 62](RO/H) Pending Switch. Set in the result of an indexed GET_WORK when there is a pending SWTAG,
                                                                 SWTAG_FULL, or SWTAG_DESCHED to ORDERED or ATOMIC. Always clear otherwise. (The DESCHED
                                                                 portion of a SWTAG_DESCHED cannot still be pending.) */
        uint64_t no_work               : 1;  /**< [ 63: 63](RO/H) Set when no new work-queue entry was returned. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_get_work1_s cn; */
} bdk_ssow_vhwsx_op_get_work1_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_GET_WORK1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_GET_WORK1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800080008ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_GET_WORK1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_GET_WORK1(a) bdk_ssow_vhwsx_op_get_work1_t
#define bustype_BDK_SSOW_VHWSX_OP_GET_WORK1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_GET_WORK1(a) "SSOW_VHWSX_OP_GET_WORK1"
#define busnum_BDK_SSOW_VHWSX_OP_GET_WORK1(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_GET_WORK1(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtag_desched
 *
 * SSO Work Slot VF Switch Tag Deschedule Operation Register
 * A write to this register performs a switch tag.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtag_desched_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. */
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtag_desched_s cn; */
} bdk_ssow_vhwsx_op_swtag_desched_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000cc0ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTAG_DESCHED", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(a) bdk_ssow_vhwsx_op_swtag_desched_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(a) "SSOW_VHWSX_OP_SWTAG_DESCHED"
#define busnum_BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTAG_DESCHED(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtag_full0
 *
 * SSO Work Slot VF Switch Tag Full Operation Register 0
 * A write to this register performs a switch tag.
 *
 * A 128-bit store (STP) must be used to SSOW_VHWS()_OP_SWTAG_FULL0 and
 * SSOW_VHWS()_OP_SWTAG_FULL1.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtag_full0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. */
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtag_full0_s cn; */
} bdk_ssow_vhwsx_op_swtag_full0_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_FULL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_FULL0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000ca0ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTAG_FULL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTAG_FULL0(a) bdk_ssow_vhwsx_op_swtag_full0_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTAG_FULL0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTAG_FULL0(a) "SSOW_VHWSX_OP_SWTAG_FULL0"
#define busnum_BDK_SSOW_VHWSX_OP_SWTAG_FULL0(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTAG_FULL0(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtag_full1
 *
 * SSO Work Slot VF Switch Tag Full Operation Register 1
 * A write to this register performs a switch tag.
 *
 * A 128-bit store (STP) may be used to SSOW_VHWS()_OP_SWTAG_FULL0 and
 * SSOW_VHWS()_OP_SWTAG_FULL1.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtag_full1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t wqp                   : 49; /**< [ 48:  0](WO) IOVA of the work-queue entry to switch to. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 49; /**< [ 48:  0](WO) IOVA of the work-queue entry to switch to. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtag_full1_s cn; */
} bdk_ssow_vhwsx_op_swtag_full1_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_FULL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_FULL1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000ca8ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTAG_FULL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTAG_FULL1(a) bdk_ssow_vhwsx_op_swtag_full1_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTAG_FULL1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTAG_FULL1(a) "SSOW_VHWSX_OP_SWTAG_FULL1"
#define busnum_BDK_SSOW_VHWSX_OP_SWTAG_FULL1(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTAG_FULL1(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtag_norm
 *
 * SSO Work Slot VF Switch Tag Normal Operation Register
 * A write to this register performs a switch tag.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtag_norm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. TT must be ORDERED or ATOMIC. */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. TT must be ORDERED or ATOMIC. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtag_norm_s cn; */
} bdk_ssow_vhwsx_op_swtag_norm_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_NORM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_NORM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000c80ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTAG_NORM", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTAG_NORM(a) bdk_ssow_vhwsx_op_swtag_norm_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTAG_NORM(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTAG_NORM(a) "SSOW_VHWSX_OP_SWTAG_NORM"
#define busnum_BDK_SSOW_VHWSX_OP_SWTAG_NORM(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTAG_NORM(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtag_nosched
 *
 * SSO Work Slot VF Switch Tag Nosched Operation Register
 * A write to this register performs a switch tag.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtag_nosched_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](WO) Tag to switch to. */
        uint64_t tt                    : 2;  /**< [ 33: 32](WO) The type of the tag, enumerated by SSO_TT_E. */
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtag_nosched_s cn; */
} bdk_ssow_vhwsx_op_swtag_nosched_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x8618000008d0ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTAG_NOSCHED", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(a) bdk_ssow_vhwsx_op_swtag_nosched_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(a) "SSOW_VHWSX_OP_SWTAG_NOSCHED"
#define busnum_BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTAG_NOSCHED(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtag_untag
 *
 * SSO Work Slot VF Switch Tag Untagged Operation Register
 * A write to this register performs a switch tag to UNTAGGED.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtag_untag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtag_untag_s cn; */
} bdk_ssow_vhwsx_op_swtag_untag_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000490ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTAG_UNTAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(a) bdk_ssow_vhwsx_op_swtag_untag_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(a) "SSOW_VHWSX_OP_SWTAG_UNTAG"
#define busnum_BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTAG_UNTAG(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtp_clr
 *
 * SSO Work Slot VF Clear Switch Tag Operation Register
 * A write to this register clears the switch-tag pending bit. The data is ignored.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtp_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtp_clr_s cn; */
} bdk_ssow_vhwsx_op_swtp_clr_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTP_CLR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTP_CLR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000820ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTP_CLR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTP_CLR(a) bdk_ssow_vhwsx_op_swtp_clr_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTP_CLR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTP_CLR(a) "SSOW_VHWSX_OP_SWTP_CLR"
#define busnum_BDK_SSOW_VHWSX_OP_SWTP_CLR(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTP_CLR(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_swtp_set
 *
 * SSO Work Slot VF Set Switch Tag Operation Register
 * A write to this register clears the switch-tag pending bit. The data is ignored.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_swtp_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_swtp_set_s cn; */
} bdk_ssow_vhwsx_op_swtp_set_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_SWTP_SET(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_SWTP_SET(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000c20ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_SWTP_SET", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_SWTP_SET(a) bdk_ssow_vhwsx_op_swtp_set_t
#define bustype_BDK_SSOW_VHWSX_OP_SWTP_SET(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_SWTP_SET(a) "SSOW_VHWSX_OP_SWTP_SET"
#define busnum_BDK_SSOW_VHWSX_OP_SWTP_SET(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_SWTP_SET(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_upd_wqp_grp0
 *
 * SSO Work Slot VF Update WQP/Group Operation Register 0
 * A write to this register updates the WQP or group.
 *
 * A 128-bit store (STP) may be used to SSOW_VHWS()_OP_UPD_WQP_GRP0 and
 * SSOW_VHWS()_OP_UPD_WQP_GRP1 to update both the WQP and group.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_upd_wqp_grp0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t reserved_0_33         : 34;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_33         : 34;
        uint64_t grp                   : 10; /**< [ 43: 34](WO) Group that the work-queue entry will switch to. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_upd_wqp_grp0_s cn; */
} bdk_ssow_vhwsx_op_upd_wqp_grp0_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000440ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_UPD_WQP_GRP0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(a) bdk_ssow_vhwsx_op_upd_wqp_grp0_t
#define bustype_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(a) "SSOW_VHWSX_OP_UPD_WQP_GRP0"
#define busnum_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP0(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_op_upd_wqp_grp1
 *
 * SSO Work Slot VF Switch Tag Full Operation Register 1
 * A write to this register performs a switch tag.
 *
 * A 128-bit store (STP) may be used to SSOW_VHWS()_OP_UPD_WQP_GRP0 and
 * SSOW_VHWS()_OP_UPD_WQP_GRP1 to update both the WQP and group.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_op_upd_wqp_grp1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t wqp                   : 49; /**< [ 48:  0](WO) IOVA of the work-queue entry to switch to. */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 49; /**< [ 48:  0](WO) IOVA of the work-queue entry to switch to. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_op_upd_wqp_grp1_s cn; */
} bdk_ssow_vhwsx_op_upd_wqp_grp1_t;

static inline uint64_t BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000448ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_OP_UPD_WQP_GRP1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(a) bdk_ssow_vhwsx_op_upd_wqp_grp1_t
#define bustype_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(a) "SSOW_VHWSX_OP_UPD_WQP_GRP1"
#define busnum_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(a) (a)
#define arguments_BDK_SSOW_VHWSX_OP_UPD_WQP_GRP1(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_pendtag
 *
 * SSO Work Slot VF Pending Tag Status Registers
 * Returns status of each HWS.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_pendtag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend_switch           : 1;  /**< [ 63: 63](RO/H) Set when there is a pending SWTAG, SWTAG_DESCHED, or SWTAG_FULL to ORDERED or ATOMIC. If
                                                                 the register read was issued after an indexed GET_WORK, the DESCHED portion of a
                                                                 SWTAG_DESCHED cannot still be pending. */
        uint64_t pend_get_work         : 1;  /**< [ 62: 62](RO/H) Set when there is a pending GET_WORK. */
        uint64_t pend_get_work_wait    : 1;  /**< [ 61: 61](RO/H) When PEND_GET_WORK is set, indicates that the WAITW bit was set. */
        uint64_t pend_nosched          : 1;  /**< [ 60: 60](RO/H) Set when nosched is desired and PEND_DESCHED is set. */
        uint64_t pend_nosched_clr      : 1;  /**< [ 59: 59](RO/H) Set when there is a pending CLR_NSCHED. */
        uint64_t pend_desched          : 1;  /**< [ 58: 58](RO/H) Set when there is a pending DESCHED or SWTAG_DESCHED. */
        uint64_t pend_alloc_we         : 1;  /**< [ 57: 57](RO/H) Set when there is a pending ALLOC_WE. */
        uint64_t pend_gw_insert        : 1;  /**< [ 56: 56](RO/H) Set when there is a pending GET_WORK insertion. */
        uint64_t reserved_54_55        : 2;
        uint64_t pend_index            : 10; /**< [ 53: 44](RO/H) The index when PEND_NOSCHED_CLR is set. */
        uint64_t reserved_34_43        : 10;
        uint64_t pend_tt               : 2;  /**< [ 33: 32](RO/H) The tag type when PEND_SWITCH is set. */
        uint64_t pend_tag              : 32; /**< [ 31:  0](RO/H) The tag when PEND_SWITCH is set. */
#else /* Word 0 - Little Endian */
        uint64_t pend_tag              : 32; /**< [ 31:  0](RO/H) The tag when PEND_SWITCH is set. */
        uint64_t pend_tt               : 2;  /**< [ 33: 32](RO/H) The tag type when PEND_SWITCH is set. */
        uint64_t reserved_34_43        : 10;
        uint64_t pend_index            : 10; /**< [ 53: 44](RO/H) The index when PEND_NOSCHED_CLR is set. */
        uint64_t reserved_54_55        : 2;
        uint64_t pend_gw_insert        : 1;  /**< [ 56: 56](RO/H) Set when there is a pending GET_WORK insertion. */
        uint64_t pend_alloc_we         : 1;  /**< [ 57: 57](RO/H) Set when there is a pending ALLOC_WE. */
        uint64_t pend_desched          : 1;  /**< [ 58: 58](RO/H) Set when there is a pending DESCHED or SWTAG_DESCHED. */
        uint64_t pend_nosched_clr      : 1;  /**< [ 59: 59](RO/H) Set when there is a pending CLR_NSCHED. */
        uint64_t pend_nosched          : 1;  /**< [ 60: 60](RO/H) Set when nosched is desired and PEND_DESCHED is set. */
        uint64_t pend_get_work_wait    : 1;  /**< [ 61: 61](RO/H) When PEND_GET_WORK is set, indicates that the WAITW bit was set. */
        uint64_t pend_get_work         : 1;  /**< [ 62: 62](RO/H) Set when there is a pending GET_WORK. */
        uint64_t pend_switch           : 1;  /**< [ 63: 63](RO/H) Set when there is a pending SWTAG, SWTAG_DESCHED, or SWTAG_FULL to ORDERED or ATOMIC. If
                                                                 the register read was issued after an indexed GET_WORK, the DESCHED portion of a
                                                                 SWTAG_DESCHED cannot still be pending. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_pendtag_s cn; */
} bdk_ssow_vhwsx_pendtag_t;

static inline uint64_t BDK_SSOW_VHWSX_PENDTAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_PENDTAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000340ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_PENDTAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_PENDTAG(a) bdk_ssow_vhwsx_pendtag_t
#define bustype_BDK_SSOW_VHWSX_PENDTAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_PENDTAG(a) "SSOW_VHWSX_PENDTAG"
#define busnum_BDK_SSOW_VHWSX_PENDTAG(a) (a)
#define arguments_BDK_SSOW_VHWSX_PENDTAG(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_pendwqp
 *
 * SSO Work Slot VF Pending WQP Status Registers
 * Returns status of each HWS.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_pendwqp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t pend_wqp              : 49; /**< [ 48:  0](RO/H) The WQP when PEND_NOSCHED_CLR is set. */
#else /* Word 0 - Little Endian */
        uint64_t pend_wqp              : 49; /**< [ 48:  0](RO/H) The WQP when PEND_NOSCHED_CLR is set. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_pendwqp_s cn; */
} bdk_ssow_vhwsx_pendwqp_t;

static inline uint64_t BDK_SSOW_VHWSX_PENDWQP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_PENDWQP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000348ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_PENDWQP", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_PENDWQP(a) bdk_ssow_vhwsx_pendwqp_t
#define bustype_BDK_SSOW_VHWSX_PENDWQP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_PENDWQP(a) "SSOW_VHWSX_PENDWQP"
#define busnum_BDK_SSOW_VHWSX_PENDWQP(a) (a)
#define arguments_BDK_SSOW_VHWSX_PENDWQP(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_swtp
 *
 * SSO Work Slot VF Switch Tag Pending Register
 * This register returns the state of the switch-tag pending bit.
 *
 * IMPORTANT: Although this register is located in SSO I/O address space, the state of
 * this register is cached inside the cores, and so loads to this register can
 * typically be returned with L1Dcache-like timing.
 *
 * INTERNAL: The address of this register is decoded by AP MEM.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_swtp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t pendsw                : 1;  /**< [  0:  0](RO/H) Switch-tag pending. */
#else /* Word 0 - Little Endian */
        uint64_t pendsw                : 1;  /**< [  0:  0](RO/H) Switch-tag pending. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_swtp_s cn; */
} bdk_ssow_vhwsx_swtp_t;

static inline uint64_t BDK_SSOW_VHWSX_SWTP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_SWTP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000400ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_SWTP", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_SWTP(a) bdk_ssow_vhwsx_swtp_t
#define bustype_BDK_SSOW_VHWSX_SWTP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_SWTP(a) "SSOW_VHWSX_SWTP"
#define busnum_BDK_SSOW_VHWSX_SWTP(a) (a)
#define arguments_BDK_SSOW_VHWSX_SWTP(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_tag
 *
 * SSO Work Slot VF Tag Status Registers
 * Returns status of each HWS.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_tag_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tailc                 : 1;  /**< [ 63: 63](RO/H) Set when this SSO entry is the tail of the conflicted tail chain, and so there are no
                                                                 additional conflicts on this tag chain. */
        uint64_t reserved_58_62        : 5;
        uint64_t index                 : 10; /**< [ 57: 48](RO/H) The SSO entry attached to the HWS. */
        uint64_t reserved_44_47        : 4;
        uint64_t grp                   : 8;  /**< [ 43: 36](RO/H) The group attached to the HWS (updated when new tag list entered on SWTAG_FULL).
                                                                 INTERNAL: The upper two bits are hardcoded to the node number. */
        uint64_t head                  : 1;  /**< [ 35: 35](RO/H) Set when this SSO entry is at the head of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t tail                  : 1;  /**< [ 34: 34](RO/H) Set when this SSO entry is at the tail of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type attached to the HWS (updated when new tag list entered on SWTAG, SWTAG_FULL,
                                                                 or SWTAG_DESCHED.) */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag attached to the HWS (updated when new tag list entered on SWTAG, SWTAG_FULL, or
                                                                 SWTAG_DESCHED.) */
#else /* Word 0 - Little Endian */
        uint64_t tag                   : 32; /**< [ 31:  0](RO/H) The tag attached to the HWS (updated when new tag list entered on SWTAG, SWTAG_FULL, or
                                                                 SWTAG_DESCHED.) */
        uint64_t tt                    : 2;  /**< [ 33: 32](RO/H) The tag type attached to the HWS (updated when new tag list entered on SWTAG, SWTAG_FULL,
                                                                 or SWTAG_DESCHED.) */
        uint64_t tail                  : 1;  /**< [ 34: 34](RO/H) Set when this SSO entry is at the tail of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t head                  : 1;  /**< [ 35: 35](RO/H) Set when this SSO entry is at the head of its tag list, or when in the UNTAGGED or EMPTY state. */
        uint64_t grp                   : 8;  /**< [ 43: 36](RO/H) The group attached to the HWS (updated when new tag list entered on SWTAG_FULL).
                                                                 INTERNAL: The upper two bits are hardcoded to the node number. */
        uint64_t reserved_44_47        : 4;
        uint64_t index                 : 10; /**< [ 57: 48](RO/H) The SSO entry attached to the HWS. */
        uint64_t reserved_58_62        : 5;
        uint64_t tailc                 : 1;  /**< [ 63: 63](RO/H) Set when this SSO entry is the tail of the conflicted tail chain, and so there are no
                                                                 additional conflicts on this tag chain. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_tag_s cn; */
} bdk_ssow_vhwsx_tag_t;

static inline uint64_t BDK_SSOW_VHWSX_TAG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_TAG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000300ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_TAG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_TAG(a) bdk_ssow_vhwsx_tag_t
#define bustype_BDK_SSOW_VHWSX_TAG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_TAG(a) "SSOW_VHWSX_TAG"
#define busnum_BDK_SSOW_VHWSX_TAG(a) (a)
#define arguments_BDK_SSOW_VHWSX_TAG(a) (a),-1,-1,-1

/**
 * Register (NCB) ssow_vhws#_wqp
 *
 * SSO Work Slot VF WQP Status Registers
 * Returns status of each HWS.
 */
typedef union
{
    uint64_t u;
    struct bdk_ssow_vhwsx_wqp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t wqp                   : 49; /**< [ 48:  0](RO/H) The WQP attached to the HWS (updated when new tag list entered on SWTAG_FULL.) */
#else /* Word 0 - Little Endian */
        uint64_t wqp                   : 49; /**< [ 48:  0](RO/H) The WQP attached to the HWS (updated when new tag list entered on SWTAG_FULL.) */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ssow_vhwsx_wqp_s cn; */
} bdk_ssow_vhwsx_wqp_t;

static inline uint64_t BDK_SSOW_VHWSX_WQP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SSOW_VHWSX_WQP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=31))
        return 0x861800000308ll + 0x100000ll * ((a) & 0x1f);
    __bdk_csr_fatal("SSOW_VHWSX_WQP", 1, a, 0, 0, 0);
}

#define typedef_BDK_SSOW_VHWSX_WQP(a) bdk_ssow_vhwsx_wqp_t
#define bustype_BDK_SSOW_VHWSX_WQP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SSOW_VHWSX_WQP(a) "SSOW_VHWSX_WQP"
#define busnum_BDK_SSOW_VHWSX_WQP(a) (a)
#define arguments_BDK_SSOW_VHWSX_WQP(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_SSOW_H__ */
