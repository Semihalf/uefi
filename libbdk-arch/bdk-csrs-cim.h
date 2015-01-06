#ifndef __BDK_CSRS_CIM__
#define __BDK_CSRS_CIM__
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
 * Cavium CIM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * NCB - cim#_icc_ap0r0_el1
 *
 * Physical active priorities group 0 EL1 AP0Rn registers provide support for preserving and
 * restoring the group0 active priorities in power-management implementations.
 * This register tracks which preemption levels are active in the CPU interface, and is
 * used to determine the current active priority. Corresponding bits are set in this register
 * when an interrupt is acknowledged. Priority, and the least significant set bit is cleared
 * on EOI.
 */
typedef union bdk_cimx_icc_ap0r0_el1 {
	uint64_t u;
	struct bdk_cimx_icc_ap0r0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ap                          : 32; /**< R/W - Operates in conjunction with all other AP0Rn and with CIM()_ICC_BPR0_EL1.
                                                                 Each bit in {AP0R3, ..., AP0R0} corresponds to a priority group as defined by
                                                                 CIM()_ICC_BPR0_EL1.
                                                                 A set bit indicates an active priority group.

                                                                 The setting is done on interrupt acknowledge by CPU (CIM()_ICC_IAR0_EL1 read).

                                                                 The resetting is done on EOI write by CPU, regardless of the value of EOIMODE, i.e.:

                                                                   1. If EOIMODE==1, EOIR write indicates priority drop causing AP0Rx[y] reset, followed by
                                                                 IST, DIR write and interrupt deactivation.

                                                                   2. If EOIMODE==0, EOIR write indicates interrupt deactivation causing AP0Rx[y] reset.

                                                                 Usage cases:
                                                                 \<pre\>
                                                                 Min            Max groups   Max preempt   ICC_AP0Rn
                                                                 ICC_BPR0_EL1   pri bits     levels        Implemented
                                                                 ============   ==========   ===========   =====================
                                                                 3              4             16           ICC_AP0R0[15:0]
                                                                 2              5             32           ICC_AP0R0[31:0]
                                                                 1              6             64           {ICC_AP0R1, ICC_AP0R0}
                                                                 0              7            128           {ICC_AP0R3, ICC_AP0R2,
                                                                 \</pre\> */
#else
		uint64_t ap                          : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_icc_ap0r0_el1_s    cn88xx; */
	/* struct bdk_cimx_icc_ap0r0_el1_s    cn88xxp1; */
} bdk_cimx_icc_ap0r0_el1_t;

static inline uint64_t BDK_CIMX_ICC_AP0R0_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_AP0R0_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063220ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_AP0R0_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_AP0R0_EL1(...) bdk_cimx_icc_ap0r0_el1_t
#define bustype_BDK_CIMX_ICC_AP0R0_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_AP0R0_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_AP0R0_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_AP0R0_EL1(...) "CIMX_ICC_AP0R0_EL1"


/**
 * NCB - cim#_icc_ap1r0_el1_ns
 *
 * Physical non-secure active priorities group 1 EL1 AP1Rn registers provide support for
 * preserving and restoring the group1 active priorities in power-management implementations.
 * This register tracks which preemption levels are active in the CPU interface, and is
 * used to determine the current active priority. Corresponding bits are set in this register
 * when an interrupt is acknowledged. Priority, and the least significant set bit is cleared
 * on EOI.
 */
typedef union bdk_cimx_icc_ap1r0_el1_ns {
	uint64_t u;
	struct bdk_cimx_icc_ap1r0_el1_ns_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ap                          : 32; /**< R/W/H - "Operates in conjunction with all other non-secure AND possibly secure AP1Rn
                                                                 and with CIM()_ICC_BPR1_EL1_NS.
                                                                 Each bit in NS {AP1R3, ..., AP1R0} corresponds to a priority group as defined by
                                                                 CIM()_ICC_BPR1_EL1_NS.
                                                                 A set bit indicates an active priority group.

                                                                 The setting is done on interrupt acknowledge by CPU (CIM()_ICC_IAR1_EL1 read).

                                                                 The resetting is done on EOI write by CPU, regardless of the value of EOIMODE, i.e.:

                                                                   1. If EOIMODE==1, EOIR write indicates priority drop causing AP1Rx[y] reset, followed by
                                                                 IST, DIR write and interrupt deactivation.

                                                                   2. If EOIMODE==0, EOIR write indicates interrupt deactivation causing AP1Rx[y] reset.

                                                                 Usage cases ("EL1" omitted for simplicity):

                                                                 \<pre\>
                                                                 Min            Max groups   Max preempt   Non-secure view of
                                                                 ICC_BPR1_EL1   pri bits     levels        ICC_AP1Rn_NS
                                                                 ============   ==========   ===========   ============
                                                                 4              4               16         {8'h00,
                                                                                                           ICC_AP1R0_NS[15:8]}
                                                                 3              5               32         {16'h0000,
                                                                                                           ICC_AP1R0_NS[31:16]}
                                                                 2              6               64         {32'h0000_0000,
                                                                                                           ICC_AP1R1_NS}
                                                                 1              7              128         {32'h0000_0000,
                                                                                                           32'h0000_0000,
                                                                                                           ICC_AP1R3_NS,
                                                                                                           ICC_AP1R2_NS}
                                                                 \</pre\>

                                                                 In CNXXXX, a system supporting two security states, where GICD_(S)CTLR[DS] is zero, non-
                                                                 secure
                                                                 accesses see a shifted view of priorities." */
#else
		uint64_t ap                          : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_icc_ap1r0_el1_ns_s cn88xx; */
	/* struct bdk_cimx_icc_ap1r0_el1_ns_s cn88xxp1; */
} bdk_cimx_icc_ap1r0_el1_ns_t;

static inline uint64_t BDK_CIMX_ICC_AP1R0_EL1_NS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_AP1R0_EL1_NS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063240ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_AP1R0_EL1_NS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_AP1R0_EL1_NS(...) bdk_cimx_icc_ap1r0_el1_ns_t
#define bustype_BDK_CIMX_ICC_AP1R0_EL1_NS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_AP1R0_EL1_NS(p1) (p1)
#define arguments_BDK_CIMX_ICC_AP1R0_EL1_NS(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_AP1R0_EL1_NS(...) "CIMX_ICC_AP1R0_EL1_NS"


/**
 * NCB - cim#_icc_ap1r0_el1_s
 *
 * Physical secure active priorities group 1 EL1 AP1Rn registers provide support for preserving
 * and restoring the group1 active priorities in power-management implementations.
 * This register tracks which preemption levels are active in the CPU interface, and is
 * used to determine the current active priority. Corresponding bits are set in this register
 * when an interrupt is acknowledged. Priority, and the least significant set bit is cleared
 * on EOI.
 */
typedef union bdk_cimx_icc_ap1r0_el1_s {
	uint64_t u;
	struct bdk_cimx_icc_ap1r0_el1_s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ap                          : 32; /**< R/W/H - "Operates in conjunction with all other secure AP1Rn and with
                                                                 CIM()_ICC_BPR1_EL1_S.
                                                                 Each bit in S {AP1R3, ..., AP1R0} corresponds to a priority group as defined by
                                                                 CIM()_ICC_BPR1_EL1_S.

                                                                 A set bit indicates an active priority group.

                                                                 The setting is done on interrupt acknowledge by CPU (CIM()_ICC_IAR1_EL1 read).

                                                                 The resetting is done on EOI write by CPU, regardless of the value of EOIMODE, i.e.:

                                                                   1. If EOIMODE==1, EOIR write indicates priority drop causing AP1Rx[y] reset, followed by
                                                                 IST, DIR write and interrupt deactivation.

                                                                   2. If EOIMODE==0, EOIR write indicates interrupt deactivation causing AP1Rx[y] reset.

                                                                 Usage cases (EL1 omitted for simplicity):

                                                                 \<pre\>
                                                                 Min          Max groups   Max preempt   ICC_AP1Rn_S
                                                                 ICC_BPR1_S   pri bits     levels        Implemented
                                                                 ==========   ==========   ===========   =====================
                                                                 3            4              16          ICC_AP1R0_S[15:0]
                                                                 2            5              32          ICC_AP1R0_S[31:0]
                                                                 1            6              64          {ICC_AP1R1_S,
                                                                                                          ICC_AP1R0_S}
                                                                 0            7             128          {ICC_AP1R3_S,
                                                                                                          ICC_AP1R2_S,
                                                                                                          ICC_AP1R1_S,
                                                                                                          ICC_AP1R0_S}
                                                                 \</pre\>

                                                                 In CNXXXX, a systems supporting two security states, where GICD_(S)CTLR[DS] is
                                                                 zero, non-secure accesses see a shifted view of priorities." */
#else
		uint64_t ap                          : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_icc_ap1r0_el1_s_s  cn88xx; */
	/* struct bdk_cimx_icc_ap1r0_el1_s_s  cn88xxp1; */
} bdk_cimx_icc_ap1r0_el1_s_t;

static inline uint64_t BDK_CIMX_ICC_AP1R0_EL1_S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_AP1R0_EL1_S(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000067240ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_AP1R0_EL1_S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_AP1R0_EL1_S(...) bdk_cimx_icc_ap1r0_el1_s_t
#define bustype_BDK_CIMX_ICC_AP1R0_EL1_S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_AP1R0_EL1_S(p1) (p1)
#define arguments_BDK_CIMX_ICC_AP1R0_EL1_S(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_AP1R0_EL1_S(...) "CIMX_ICC_AP1R0_EL1_S"


/**
 * NCB - cim#_icc_asgi1r_el1
 *
 * When CIM()_ICC_ASGI1R_EL1 is written, this results in the generation of interrupts to a
 * set of
 * processors
 * a.b.c.{target list}, where target list is a set of up to sixteen processors within the
 * affinity cluster defines by a.b.c.*.
 *
 * If SRE is set only for secure EL3, software executing at EL3 might use the system
 * register interface to generate SGIs. Hence, the distributor
 *       must always correctly handle generate SGI packets received from CPU interface regardless
 * of the ARE settings for a security state.
 *
 * Virtual accesses to these registers always trap to EL2 (HYP_TRAP).
 *
 * Accesses to these registers trap to EL2 (HYP_TRAP) if CIM()_ICH_HCR_EL2[TC] == 1.
 *
 * This register provides software the ability to generate group 1 SGIs for the other security
 * state. That is, non-secure EL1 / EL2 accesses may generate secure group 1 interrupts and
 * secure EL1 / EL3 may generate non-secure group 1 interrupts.
 */
typedef union bdk_cimx_icc_asgi1r_el1 {
	uint64_t u;
	struct bdk_cimx_icc_asgi1r_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t affinity3                   : 8;  /**< WO - Affinity 3. The affinity 3 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t reserved_41_47              : 7;
		uint64_t irm                         : 1;  /**< WO - Interrupt routing mode.
                                                                 When this field is one, the TGTLIST, AFFINITY1, AFFINITY2 and AFFINITY3
                                                                 fields are reserved. */
		uint64_t affinity2                   : 8;  /**< WO - Affinity 2. The affinity 2 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t reserved_28_31              : 4;
		uint64_t intid                       : 4;  /**< WO - SGI Interrupt ID. */
		uint64_t affinity1                   : 8;  /**< WO - Affinity 1. The affinity 1 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t tgtlist                     : 16; /**< WO - The set of processor for which SGI interrupts will be generated. Each bit corresponds to
                                                                 the processor within a cluster with an AFFINITY0 equal to the bit number.
                                                                 If a bit is one and the bit does not correspond to a valid target processor, the bit
                                                                 must be ignored by the distributor. In such cases, a distributor may optionally generate
                                                                 an SEI.
                                                                 This restricts distribution of SGIs to the first 16 processors of an affinity 1
                                                                 cluster.

                                                                 If software specifies AFFINITY3 (if appropriate), AFFINITY2 and AFFINITY1 values
                                                                 that do not correspond to a valid set of target processors the Distributor must
                                                                 acknowledge and discard the generate SGI packet. It may optionally generate an SEI. */
#else
		uint64_t tgtlist                     : 16;
		uint64_t affinity1                   : 8;
		uint64_t intid                       : 4;
		uint64_t reserved_28_31              : 4;
		uint64_t affinity2                   : 8;
		uint64_t irm                         : 1;
		uint64_t reserved_41_47              : 7;
		uint64_t affinity3                   : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_cimx_icc_asgi1r_el1_s   cn88xx; */
	/* struct bdk_cimx_icc_asgi1r_el1_s   cn88xxp1; */
} bdk_cimx_icc_asgi1r_el1_t;

static inline uint64_t BDK_CIMX_ICC_ASGI1R_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_ASGI1R_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000632F8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_ASGI1R_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_ASGI1R_EL1(...) bdk_cimx_icc_asgi1r_el1_t
#define bustype_BDK_CIMX_ICC_ASGI1R_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_ASGI1R_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_ASGI1R_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_ASGI1R_EL1(...) "CIMX_ICC_ASGI1R_EL1"


/**
 * NCB - cim#_icc_bpr0_el1
 *
 * The register defines the point at which the priority value fields split into two
 * parts, the group priority field and the subpriority field. The group priority field
 * is used to determine interrupt preemption.
 */
typedef union bdk_cimx_icc_bpr0_el1 {
	uint64_t u;
	struct bdk_cimx_icc_bpr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t bp_min                      : 2;  /**< RO/H - Minimum Binary Point Value.
                                                                 In CNXXXX, this field is always 2 as only 32 priorities are implemented.
                                                                 Value BP below can be programmed to is BP_MIN..7. */
		uint64_t bp                          : 3;  /**< R/W - Binary point.
                                                                 When determining preemption, all interrupts with the same group priority are
                                                                 considered to have equal priority, regardless of the subpriority. This means that there
                                                                 can only be one interrupt active
                                                                 at each group priority. The active group priority is also known as the preemption level.

                                                                 The GIC uses the group priority field to determine whether a pending interrupt has
                                                                 sufficient priority to preempt an
                                                                 active interrupt, as follows:

                                                                 1. For a pending interrupt to preempt an active interrupt, its group priority must be
                                                                 higher than the group priority
                                                                    of the active interrupt. That is, the value of the group priority field for the new
                                                                 interrupt must be less than the
                                                                    value of the group priority field of the running priority.

                                                                 2. If there are no active interrupts on the CPU interface, the highest priority pending
                                                                 interrupt can be signaled
                                                                    to a processor, regardless of the group priority.

                                                                 In each case, the pending interrupt priority is compared with the priority mask, and the
                                                                 interrupt is signaled only if it is not masked.

                                                                 The binary point field in the BP controls the split of the priority bits into the two
                                                                 parts. This 3-bit field
                                                                 specifies how many of the least significant bits of the 8-bit interrupt priority field are
                                                                 excluded from the group
                                                                 priority field:

                                                                 \<pre\>
                                                                      Group Priority   Subpriority   Field with
                                                                 BP   Field            Field         Binary Point
                                                                 ==   ==============   ===========   ============
                                                                 0    [7:1]            [0]           ggggggg.s
                                                                 1    [7:2]            [1:0]         gggggg.ss
                                                                 ...
                                                                 6    [7]              [6:0]         g.sssssss
                                                                 7    No preemption    [7:0]         .ssssssss
                                                                 \</pre\>

                                                                 In CNXXXX, only 5 priority bits are implemented:

                                                                 \<pre\>
                                                                      Group Priority   Subpriority   Field with
                                                                 BP   Field            Field         Binary Point
                                                                 ==   ==============   ===========   ============
                                                                 2    [7:3]            [2:0]         ggggg.sss
                                                                 3    [7:4]            [3:0]         gggg.ssss
                                                                 4    [7:5]            [4:0]         ggg.sssss
                                                                 5    [7:6]            [5:0]         gg.ssssss
                                                                 6    [7:7]            [6:0]         g.sssssss
                                                                 7    No preemption    [7:0]         .ssssssss
                                                                 \</pre\>

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which FIQ is routed.

                                                                 The minimum binary value programmable is BP_MIN. Attempt to set it to a lower value
                                                                 automatically sets it to the minimum value BP_MIN
                                                                 CIM()_ICC_CTLR_EL3[CBPR_EL1S] and CIM()_ICC_CTLR_EL3[CBPR_EL1NS] may cause
                                                                 this register to be
                                                                 read/written to by CPU if CIM()_ICC_BPR1_EL1 is accessed - see descriptions
                                                                       of CIM()_ICC_BPR1_EL1_NS and CIM()_ICC_BPR1_EL1_S
                                                                 Processor accesses in virtual mode read from/write to
                                                                 CIM()_ICH_VMCR_EL2[VBPR0]. */
#else
		uint64_t bp                          : 3;
		uint64_t bp_min                      : 2;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_cimx_icc_bpr0_el1_s     cn88xx; */
	/* struct bdk_cimx_icc_bpr0_el1_s     cn88xxp1; */
} bdk_cimx_icc_bpr0_el1_t;

static inline uint64_t BDK_CIMX_ICC_BPR0_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_BPR0_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063218ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_BPR0_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_BPR0_EL1(...) bdk_cimx_icc_bpr0_el1_t
#define bustype_BDK_CIMX_ICC_BPR0_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_BPR0_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_BPR0_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_BPR0_EL1(...) "CIMX_ICC_BPR0_EL1"


/**
 * NCB - cim#_icc_bpr1_el1_ns
 *
 * Physical non-secure binary point group 1 el1 register.
 *
 */
typedef union bdk_cimx_icc_bpr1_el1_ns {
	uint64_t u;
	struct bdk_cimx_icc_bpr1_el1_ns_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t bp_min                      : 2;  /**< RO/H - Minimum Binary Point Value.
                                                                 In CNXXXX, this field is always 3 as only 32 priorities are implemented leading to a
                                                                 maximum non-secure BP + 1.
                                                                 Value BP below can be programmed to BP_MIN..7. */
		uint64_t bp                          : 3;  /**< R/W - Binary point.
                                                                 See CIM()_ICC_BPR0_EL1.
                                                                 In addition, following holds:

                                                                 1. If CIM()_ICC_CTLR_EL3[CBPR_EL1S] is one:

                                                                 _   CPU writes to CIM()_ICC_BPR1_EL1 at secure EL1 will modify
                                                                     CIM()_ICC_BPR0_EL1.

                                                                 _   CPU reads  of CIM()_ICC_BPR1_EL1 at secure EL1 will return the value of
                                                                     CIM()_ICC_BPR0_EL1.

                                                                 2. If CIM()_ICC_CTLR_EL3[CBPR_EL1NS] is one, non-secure accesses at EL1 or EL2 behave
                                                                 as defined in the table below.

                                                                 \<pre\>
                                                                 SCR_EL3[IRQ]  HCR_EL2[HMO]   Description
                                                                 ============  ============   ===================================
                                                                       1             0        Inaccessible to non-secure EL1/EL2.

                                                                       1             1        Non-secure EL1 access is virtual.
                                                                                              Inaccessible to EL2.

                                                                       0             1        Non-secure EL1 access is virtual.
                                                                                              Non-secure EL2 reads return
                                                                                              (CIM()_ICC_BPR0_EL1 + 1)
                                                                                              saturated to 0x7.
                                                                                              Non-secure EL2 writes are ignored.

                                                                       0             0        Non-secure EL1 / EL2 reads return
                                                                                              (CIM()_ICC_BPR0_EL1 + 1)
                                                                                              saturated to 0x7.
                                                                                              Non-secure EL1 / EL2 writes
                                                                                              are ignored.
                                                                 \</pre\>

                                                                 3. When operating at EL3, this (CIM()_ICC_BPR1_EL1_NS) is returned if
                                                                 SCR_EL3[NS] == 1 and
                                                                 CIM()_ICC_CTLR_EL3[CBPR_EL1_{S,NS}] are ignored.

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which IRQ is routed.

                                                                 The minimum binary value programmable is BP_MIN. Attempt to set it to a lower value
                                                                 automatically sets it to the minimum value BP_MIN.

                                                                 Processor accesses in virtual mode read from/write to CIM()_ICH_VMCR_EL2[VBPR1]. */
#else
		uint64_t bp                          : 3;
		uint64_t bp_min                      : 2;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_cimx_icc_bpr1_el1_ns_s  cn88xx; */
	/* struct bdk_cimx_icc_bpr1_el1_ns_s  cn88xxp1; */
} bdk_cimx_icc_bpr1_el1_ns_t;

static inline uint64_t BDK_CIMX_ICC_BPR1_EL1_NS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_BPR1_EL1_NS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063318ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_BPR1_EL1_NS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_BPR1_EL1_NS(...) bdk_cimx_icc_bpr1_el1_ns_t
#define bustype_BDK_CIMX_ICC_BPR1_EL1_NS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_BPR1_EL1_NS(p1) (p1)
#define arguments_BDK_CIMX_ICC_BPR1_EL1_NS(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_BPR1_EL1_NS(...) "CIMX_ICC_BPR1_EL1_NS"


/**
 * NCB - cim#_icc_bpr1_el1_s
 *
 * Physical secure Binary Point group 1 EL1 Register
 *
 */
typedef union bdk_cimx_icc_bpr1_el1_s {
	uint64_t u;
	struct bdk_cimx_icc_bpr1_el1_s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t bp_min                      : 2;  /**< RO/H - Minimum binary point value.
                                                                 In CNXXXX, this field is always 0x2 as only 32 priorities are implemented.
                                                                 Value BP below can be programmed to is BP_MIN..7. */
		uint64_t bp                          : 3;  /**< R/W - Binary point.
                                                                 See CIM()_ICC_BPR0_EL1.
                                                                 In addition, following holds:

                                                                 1. If CIM()_ICC_CTLR_EL3[CBPR_EL1S] is one:

                                                                     o CPU writes to CIM()_ICC_BPR1_EL1 at secure EL1 will modify
                                                                 CIM()_ICC_BPR0_EL1.

                                                                     o CPU reads  of CIM()_ICC_BPR1_EL1 at secure EL1 will return the value of
                                                                 CIM()_ICC_BPR0_EL1.

                                                                 2. If CIM()_ICC_CTLR_EL3[CBPR_EL1NS] is one, non-secure accesses at EL1 or EL2 behave
                                                                 as defined in the table below

                                                                 \<pre\>
                                                                 SCR_EL3[IRQ]  HCR_EL2[HMO]   Description
                                                                 ============  ============   ===================================
                                                                       1            0         Inaccessible to non-secure EL1/EL2.

                                                                       1            1         Non-secure EL1 access is virtual.
                                                                                              Inaccessible to EL2.

                                                                       0            1         Non-secure EL1 access is virtual.
                                                                                              Non-secure EL2 reads return
                                                                                              (CIM()_ICC_BPR0_EL1 + 1)
                                                                                              saturated to 0x7.
                                                                                              Non-secure EL2 writes are ignored.

                                                                       0            0         Non-secure EL1 / EL2 reads return
                                                                                              (CIM()_ICC_BPR0_EL1 + 1)
                                                                                              saturated to 0x7.
                                                                                              Non-secure EL1 / EL2 writes
                                                                                              are ignored.
                                                                 \</pre\>

                                                                 3. When operating at EL3, this (CIM()_ICC_BPR1_EL1_S) is returned if
                                                                 SCR_EL3[NS] == 0 and CIM()_ICC_CTLR_EL3[CBPR_EL1{S,NS}] are ignored.

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which IRQ is routed.

                                                                 The minimum binary value programmable is BP_MIN. Attempt to set it to a lower value
                                                                       automatically sets it to the minimum value BP_MIN.

                                                                 Processor accesses in virtual mode read from/write to CIM()_ICH_VMCR_EL2[VBPR1]. */
#else
		uint64_t bp                          : 3;
		uint64_t bp_min                      : 2;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_cimx_icc_bpr1_el1_s_s   cn88xx; */
	/* struct bdk_cimx_icc_bpr1_el1_s_s   cn88xxp1; */
} bdk_cimx_icc_bpr1_el1_s_t;

static inline uint64_t BDK_CIMX_ICC_BPR1_EL1_S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_BPR1_EL1_S(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000067318ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_BPR1_EL1_S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_BPR1_EL1_S(...) bdk_cimx_icc_bpr1_el1_s_t
#define bustype_BDK_CIMX_ICC_BPR1_EL1_S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_BPR1_EL1_S(p1) (p1)
#define arguments_BDK_CIMX_ICC_BPR1_EL1_S(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_BPR1_EL1_S(...) "CIMX_ICC_BPR1_EL1_S"


/**
 * NCB - cim#_icc_ctlr_el1_ns
 *
 * This non-secure register governs aspects of the behavior of the GIC CPU interface and
 * provides information about the features implemented for.
 * It is accessed in EL1 non-secure mode.
 */
typedef union bdk_cimx_icc_ctlr_el1_ns {
	uint64_t u;
	struct bdk_cimx_icc_ctlr_el1_ns_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t a3v                         : 1;  /**< RO/H - Support for affinity 3 in SGI.
                                                                 In CNXXXX, this bit is always 0 as affinity3 is always 0. */
		uint64_t seis                        : 1;  /**< RO/H - Support local generation of SEIs.
                                                                 In CNXXXX, this bit is always 0 as SEIs aren't implemented. */
		uint64_t idbits                      : 3;  /**< RO/H - The number of physical interrupt identifier bits supported.
                                                                 In CNXXXX, this field is always 0x1 as 24-bit interrupt IDs are supported in the CIM. */
		uint64_t pribits                     : 3;  /**< RO/H - The number of priority bits implemented, minus one.
                                                                 In CNXXXX, this field is always 4 as only 32 priorities are implement. */
		uint64_t reserved_7_7                : 1;
		uint64_t pmhe                        : 1;  /**< R/W/H - Priority mask hint enable. If EL3 is present this bit is an alias of
                                                                 CIM()_ICC_CTLR_EL3[PMHE]. */
		uint64_t reserved_2_5                : 4;
		uint64_t eoimode                     : 1;  /**< R/W/H - EOI mode.
                                                                 The EOI mode for the non-secure state; this bit is a read/write alias of
                                                                 CIM()_ICC_CTLR_EL3[EOIMODE_EL1NS].
                                                                 Virtual accesses modify CIM()_ICH_VMCR_EL2[VEOIM]. */
		uint64_t cbpr                        : 1;  /**< R/W/H - Common binary point register.
                                                                 This bit is an alias of CIM()_ICC_CTLR_EL3[CBPR_EL1NS].

                                                                 Virtual accesses modify CIM()_ICH_VMCR_EL2[VCBPR].

                                                                 When accessed at EL1, EL2 or EL3 and DS == 0, this bit is read-only

                                                                 When accessed at EL1, EL2 or EL3 and DS == 1, this bit is read-write

                                                                 This bit affects virtual access to CIM()_ICC_BPR1_EL1. */
#else
		uint64_t cbpr                        : 1;
		uint64_t eoimode                     : 1;
		uint64_t reserved_2_5                : 4;
		uint64_t pmhe                        : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t pribits                     : 3;
		uint64_t idbits                      : 3;
		uint64_t seis                        : 1;
		uint64_t a3v                         : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_cimx_icc_ctlr_el1_ns_s  cn88xx; */
	/* struct bdk_cimx_icc_ctlr_el1_ns_s  cn88xxp1; */
} bdk_cimx_icc_ctlr_el1_ns_t;

static inline uint64_t BDK_CIMX_ICC_CTLR_EL1_NS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_CTLR_EL1_NS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063320ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_CTLR_EL1_NS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_CTLR_EL1_NS(...) bdk_cimx_icc_ctlr_el1_ns_t
#define bustype_BDK_CIMX_ICC_CTLR_EL1_NS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_CTLR_EL1_NS(p1) (p1)
#define arguments_BDK_CIMX_ICC_CTLR_EL1_NS(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_CTLR_EL1_NS(...) "CIMX_ICC_CTLR_EL1_NS"


/**
 * NCB - cim#_icc_ctlr_el1_s
 *
 * This secure register governs aspects of the behavior of the GIC CPU interface and provides
 * information about the features implemented.
 * It is accessed in EL1 Secure mode
 */
typedef union bdk_cimx_icc_ctlr_el1_s {
	uint64_t u;
	struct bdk_cimx_icc_ctlr_el1_s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t a3v                         : 1;  /**< RO/H - Support for affinity 3 in SGI.
                                                                 In CNXXXX, this bit is always 0 as affinity3 is always 0. */
		uint64_t seis                        : 1;  /**< RO/H - Support local generation of SEIs.
                                                                 In CNXXXX, this bit is always 0 as SEIs are not implemented. */
		uint64_t idbits                      : 3;  /**< RO/H - The number of physical interrupt identifier bits supported.
                                                                 In CNXXXX, this field is always 0x1 as 24-bit interrupt IDs are supported in the CIM. */
		uint64_t pribits                     : 3;  /**< RO/H - The number of priority bits implemented, minus one.
                                                                 In CNXXXX, this field is always 4 as only 32 priorities are implemented. */
		uint64_t reserved_7_7                : 1;
		uint64_t pmhe                        : 1;  /**< R/W/H - Priority mask hint enable. If EL3 is present this bit is an alias of
                                                                 CIM()_ICC_CTLR_EL3[PMHE]. */
		uint64_t reserved_2_5                : 4;
		uint64_t eoimode                     : 1;  /**< R/W/H - EOI mode.
                                                                 The EOI mode for the secure state; this bit is a read/write alias of
                                                                 CIM()_ICC_CTLR_EL3[EOIMODE_EL1S].
                                                                 Virtual accesses modify CIM()_ICH_VMCR_EL2[VEOIM]. */
		uint64_t cbpr                        : 1;  /**< R/W/H - Common binary point register.
                                                                 This bit is an alias of CIM()_ICC_CTLR_EL3[CBPR_EL1S].

                                                                 Virtual accesses modify CIM()_ICH_VMCR_EL2[VCBPR].

                                                                 When accessed at EL1, EL2 or EL3 and DS == 0, this bit is read-only.

                                                                 When accessed at EL1, EL2 or EL3 and DS == 1, this bit is read-write.

                                                                 This bit affects virtual access to CIM()_ICC_BPR1_EL1. */
#else
		uint64_t cbpr                        : 1;
		uint64_t eoimode                     : 1;
		uint64_t reserved_2_5                : 4;
		uint64_t pmhe                        : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t pribits                     : 3;
		uint64_t idbits                      : 3;
		uint64_t seis                        : 1;
		uint64_t a3v                         : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_cimx_icc_ctlr_el1_s_s   cn88xx; */
	/* struct bdk_cimx_icc_ctlr_el1_s_s   cn88xxp1; */
} bdk_cimx_icc_ctlr_el1_s_t;

static inline uint64_t BDK_CIMX_ICC_CTLR_EL1_S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_CTLR_EL1_S(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000067320ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_CTLR_EL1_S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_CTLR_EL1_S(...) bdk_cimx_icc_ctlr_el1_s_t
#define bustype_BDK_CIMX_ICC_CTLR_EL1_S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_CTLR_EL1_S(p1) (p1)
#define arguments_BDK_CIMX_ICC_CTLR_EL1_S(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_CTLR_EL1_S(...) "CIMX_ICC_CTLR_EL1_S"


/**
 * NCB - cim#_icc_ctlr_el3
 *
 * This secure register governs aspects of the behavior of the GIC CPU interface and provides
 * information about the features implemented.
 * It is accessed in EL3 mode.
 */
typedef union bdk_cimx_icc_ctlr_el3 {
	uint64_t u;
	struct bdk_cimx_icc_ctlr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t a3v                         : 1;  /**< RO/H - Support for affinity 3 in SGI.
                                                                 In CNXXXX, this bit is always 0, as affinity 3 is not implemented. */
		uint64_t seis                        : 1;  /**< RO/H - Support local generation of SEIs.
                                                                 In CNXXXX, this bit is always 0 as SEIs are not implemented. */
		uint64_t idbits                      : 3;  /**< RO/H - The number of physical interrupt identifier bits supported.
                                                                 In CNXXXX, this field is always 0x1 as 24-bit interrupt IDs are supported in the CIM. */
		uint64_t pribits                     : 3;  /**< RO/H - The number of priority bits implemented, minus one.
                                                                 In CNXXXX, this field is always 4 as only 32 priorities are implemented. */
		uint64_t reserved_7_7                : 1;
		uint64_t pmhe                        : 1;  /**< R/W/H - Priority mask hint enable. When set, enables use of the PMR as a hint for interrupt
                                                                 distribution.

                                                                 When changing PMHE from zero to one, software must write to
                                                                 CIM()_ICC_PMR_EL1 to ensure the distributor is informed of the value of PMR.

                                                                 When changing PMHE from one to zero, software must write CIM()_ICC_PMR_EL1
                                                                 to 0xff prior to writing PMHE to zero. */
		uint64_t rm                          : 1;  /**< R/W - Routing modifier.
                                                                 Legacy bit from GICv2.
                                                                 In CNXXXX, this bit is always 0 because the secure copy of CIM()_ICC_SRE_EL1[SRE]
                                                                 is one. */
		uint64_t eoimode_el1ns               : 1;  /**< R/W/H - EOI mode for interrupts handled at non-secure EL1/2 (i.e. the accesses to EOIR
                                                                 and DIR are performed at non-secure EL1/2). */
		uint64_t eoimode_el1s                : 1;  /**< R/W/H - EOI mode for interrupts handled at secure EL1 (i.e. the accesses to EOIR and DIR
                                                                 are performed at non-secure EL1). */
		uint64_t eoimode_el3                 : 1;  /**< R/W - EOI mode for interrupts handled at EL3 when EL3 is using AArch64. */
		uint64_t cbpr_el1ns                  : 1;  /**< R/W/H - Non-secure common binary point register.
                                                                 When set, non-secure EL1 and non-secure EL2 accesses to
                                                                 CIM()_ICC_BPR1_EL1 access the state of
                                                                 CIM()_ICC_BPR0_EL1. CIM()_ICC_BPR0_EL1 is used to determine the pre-emption
                                                                 group for non-secure group 1 interrupts. */
		uint64_t cbpr_el1s                   : 1;  /**< R/W/H - Secure common binary point register.
                                                                 When set, secure EL1 and EL3 accesses when EL3 is using AArch32 and not in monitor mode
                                                                 accesses to CIM()_ICC_BPR1_EL1 access the state of CIM()_ICC_BPR0_EL1.
                                                                 CIM()_ICC_BPR0_EL1 is used to determine the pre-emption group for secure group 1
                                                                 interrupts. */
#else
		uint64_t cbpr_el1s                   : 1;
		uint64_t cbpr_el1ns                  : 1;
		uint64_t eoimode_el3                 : 1;
		uint64_t eoimode_el1s                : 1;
		uint64_t eoimode_el1ns               : 1;
		uint64_t rm                          : 1;
		uint64_t pmhe                        : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t pribits                     : 3;
		uint64_t idbits                      : 3;
		uint64_t seis                        : 1;
		uint64_t a3v                         : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_cimx_icc_ctlr_el3_s     cn88xx; */
	/* struct bdk_cimx_icc_ctlr_el3_s     cn88xxp1; */
} bdk_cimx_icc_ctlr_el3_t;

static inline uint64_t BDK_CIMX_ICC_CTLR_EL3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_CTLR_EL3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B00007B320ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_CTLR_EL3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_CTLR_EL3(...) bdk_cimx_icc_ctlr_el3_t
#define bustype_BDK_CIMX_ICC_CTLR_EL3(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_CTLR_EL3(p1) (p1)
#define arguments_BDK_CIMX_ICC_CTLR_EL3(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_CTLR_EL3(...) "CIMX_ICC_CTLR_EL3"


/**
 * NCB - cim#_icc_dir_el1
 *
 * Start of pseudocode WriteICC_DIR_EL1.
 * When interrupt priority drop is separated from interrupt deactivation a write to this register
 * deactivates the specified interrupt.
 *
 * Writes to this register only have an effect when either:
 *
 * 1. For secure accesses to the register, CIM()_ICC_CTLR_EL3[EOIMODE_EL1S] is set to 1.
 *
 * 2. For non-secure accesses to the register, CIM()_ICC_CTLR_EL3[EOIMODE_EL1NS] is set to
 * 1.
 */
typedef union bdk_cimx_icc_dir_el1 {
	uint64_t u;
	struct bdk_cimx_icc_dir_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t intid                       : 20; /**< WO - Interrupt ID. Secure write to CIM()_ICC_DIR_EL1 deactivates the specified
                                                                 interrupt, regardless of whether that interrupt is in group 0 or group 1
                                                                 Non-secure write to CIM()_ICC_DIR_EL1 deactivates the specified interrupt only
                                                                 if that interrupt is in group 1.

                                                                 A valid write is one that specifies an interrupt that is active, and for which
                                                                 there has been a successful write to CIM()_ICC_EOIR0_EL1 or CIM()_ICC_EOIR1_EL1.

                                                                 If the relevant EOIMODE bit is 0 then the effect of this register access is ignored
                                                                 and SEI is generated.

                                                                 If the interrupt identified in the CIM()_ICC_DIR_EL1 is not active, and is not a
                                                                 spurious interrupt, the deactivate packet sent will cause distributor to
                                                                 generate SEI. This means any CIM()_ICC_DIR_EL1 write must identify an interrupt
                                                                 for which there has been a valid CIM()_ICC_EOIR0_EL1 or CIM()_ICC_EOIR1_EL1
                                                                 write.

                                                                 If the relevant EOIMODE bit is 1 and no EOI has been issued for value written to
                                                                 CIM()_ICC_DIR_EL1 the active priority for the interrupt will remain set (because
                                                                 no EOI was issued). However, the system behavior is unpredictable.

                                                                 Unlike CIM()_ICC_EOIR0_EL1 and CIM()_ICC_EOIR1_EL1 writes, there is no ordering
                                                                 requirement for
                                                                 CIM()_ICC_DIR_EL1 writes, provided they meet the other requirements given above.
                                                                 Accesses to this register trap to EL2 (HYP_TRAP) if CIM()_ICH_HCR_EL2[TC] == 1. */
#else
		uint64_t intid                       : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_dir_el1_s      cn88xx; */
	/* struct bdk_cimx_icc_dir_el1_s      cn88xxp1; */
} bdk_cimx_icc_dir_el1_t;

static inline uint64_t BDK_CIMX_ICC_DIR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_DIR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000632C8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_DIR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_DIR_EL1(...) bdk_cimx_icc_dir_el1_t
#define bustype_BDK_CIMX_ICC_DIR_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_DIR_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_DIR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_DIR_EL1(...) "CIMX_ICC_DIR_EL1"


/**
 * NCB - cim#_icc_eoir0_el1
 *
 * Start of pseudocode WriteICC_EOIR0_EL1. A processor writes to this register to inform the CPU
 * interface either:
 *
 * 1. That it has completed the processing of the specified group 0 interrupt.
 *
 * 2. Or when the appropriate CIM()_ICC_CTLR[EOIMODE] bit is set to 1, to indicate that the
 * interface should perform
 * priority drop for the specified group 0 interrupt by clearing a bit in
 * CIM()_ICC_AP0Rn_EL1.
 */
typedef union bdk_cimx_icc_eoir0_el1 {
	uint64_t u;
	struct bdk_cimx_icc_eoir0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t eoiintid                    : 20; /**< WO - End of interrupt ID.
                                                                 Software must ensure the interrupt identifier written to CIM()_ICC_EOIR0_EL1 is
                                                                 identical to the identifier returned by the last read of an interrupt acknowledge
                                                                 register and that this identifier was read from CIM()_ICC_IAR0_EL1 while operating
                                                                 in the same security state as that in which the write occurs, otherwise the system
                                                                 behavior is unpredictable.

                                                                 For nested interrupts, the order of writes to CIM()_ICC_EOIR0_EL1 must be the
                                                                 reverse of the order of interrupt acknowledgement.

                                                                 Behavior is unpredictable if either:

                                                                 _ 1. The ordering constraints on reads from the CIM()_ICC_IAR0_EL1 and writes
                                                                 to the CIM()_ICC_EOIR0_EL1 are not maintained.

                                                                 _ 2. The value in a write to the CIM()_ICC_EOIR0_EL1 does not match an active
                                                                 interrupt, or the ID of a spurious interrupt.

                                                                 The effect of writing to CIM()_ICC_EOIR0_EL1 with a valid interrupt ID is
                                                                 unpredictable if any of the following apply:

                                                                 _ 1. The value written does not match the last valid interrupt value read from the
                                                                 Interrupt acknowledge register, or the security states in which the read from
                                                                 CIM()_ICC_IAR0_EL1 and writes to the CIM()_ICC_EOIR0_EL1 differ.

                                                                 _ 2. There is no outstanding acknowledged interrupt.

                                                                 _ 3. The indicated interrupt has already been subject to an EOI request.

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which FIQ is routed. */
#else
		uint64_t eoiintid                    : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_eoir0_el1_s    cn88xx; */
	/* struct bdk_cimx_icc_eoir0_el1_s    cn88xxp1; */
} bdk_cimx_icc_eoir0_el1_t;

static inline uint64_t BDK_CIMX_ICC_EOIR0_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_EOIR0_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063208ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_EOIR0_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_EOIR0_EL1(...) bdk_cimx_icc_eoir0_el1_t
#define bustype_BDK_CIMX_ICC_EOIR0_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_EOIR0_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_EOIR0_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_EOIR0_EL1(...) "CIMX_ICC_EOIR0_EL1"


/**
 * NCB - cim#_icc_eoir1_el1
 *
 * Start of pseudocode WriteICC_EOIR1_EL1. A processor writes to this register to inform the CPU
 * interface either:
 *
 * 1. That it has completed the processing of the specified group 1 interrupt.
 *
 * 2. Or when the appropriate CIM()_ICC_CTLR[EOIMODE] bit is set to 1, to indicate that the
 * interface should perform
 * priority drop for the specified group 1 interrupt by clearing a bit in
 * CIM()_ICC_AP1Rn_EL1.
 */
typedef union bdk_cimx_icc_eoir1_el1 {
	uint64_t u;
	struct bdk_cimx_icc_eoir1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t eoiintid                    : 20; /**< WO - End of interrupt ID.
                                                                 Software must ensure the interrupt identifier written to CIM()_ICC_EOIR1_EL1 is
                                                                 identical to the
                                                                 identifier returned by the last
                                                                 read of an interrupt acknowledge register and that this identifier was read from
                                                                 CIM()_ICC_IAR1_EL1 while operating in the same
                                                                 security state as that in which the write occurs, otherwise the system behavior is
                                                                 unpredictable.

                                                                 For nested interrupts, the order of writes to CIM()_ICC_EOIR1_EL1 must be the reverse
                                                                 of the order of interrupt acknowledgement.

                                                                 Behavior is unpredictable if either:

                                                                   1. The ordering constraints on reads from the CIM()_ICC_IAR1_EL1 and writes to the
                                                                 CIM()_ICC_EOIR1_EL1 are not maintained.

                                                                   2. The value in a write to the CIM()_ICC_EOIR1_EL1 does not match an active
                                                                 interrupt, or theID of a spurious interrupt.

                                                                 The effect of writing to CIM()_ICC_EOI1_EL1 with a valid interrupt ID is
                                                                 unpredictable if any of the following apply:

                                                                   1. The value written does not match the last valid interrupt value read from the
                                                                 Interrupt acknowledge register,
                                                                      or the security states in which the read from CIM()_ICC_IAR1_EL1 and write to
                                                                 the CIM()_ICC_EOIR1_EL1 differ.

                                                                   2. There is no outstanding acknowledged interrupt.

                                                                   3. The indicated interrupt has already been subject to an EOI request.

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which IRQ is routed. */
#else
		uint64_t eoiintid                    : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_eoir1_el1_s    cn88xx; */
	/* struct bdk_cimx_icc_eoir1_el1_s    cn88xxp1; */
} bdk_cimx_icc_eoir1_el1_t;

static inline uint64_t BDK_CIMX_ICC_EOIR1_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_EOIR1_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063308ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_EOIR1_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_EOIR1_EL1(...) bdk_cimx_icc_eoir1_el1_t
#define bustype_BDK_CIMX_ICC_EOIR1_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_EOIR1_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_EOIR1_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_EOIR1_EL1(...) "CIMX_ICC_EOIR1_EL1"


/**
 * NCB - cim#_icc_hppir0_el1
 *
 * Result of pseudocode ReadICC_HPPIR0_EL1. Indicates the interrupt ID of the highest priority
 * pending
 * Group 0 interrupt on the CPU interface.
 */
typedef union bdk_cimx_icc_hppir0_el1 {
	uint64_t u;
	struct bdk_cimx_icc_hppir0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t pendintid                   : 20; /**< RO/H - Pending interrupt ID.
                                                                 Whether the value returned by a read of CIM()_ICC_HPPIR0_EL1 is a valid interrupt ID
                                                                 can depend on:

                                                                 1. Whether the highest priority pending interrupt is configured as a group 0 or a group 1
                                                                 interrupt.

                                                                 2. Whether the register access is secure or non-secure.

                                                                 Reads of the CIM()_ICC_HPPIR0_EL1 that do not return a valid interrupt ID return a
                                                                 spurrious interrupt ID, ID 1022 or 1023.

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which FIQ is routed.

                                                                 ARM clarified CIM()_ICC_HPPIR0_EL1 is agnostic of level/edge triggering therefore
                                                                 "active and pending" means "active" only for CIM. */
#else
		uint64_t pendintid                   : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_hppir0_el1_s   cn88xx; */
	/* struct bdk_cimx_icc_hppir0_el1_s   cn88xxp1; */
} bdk_cimx_icc_hppir0_el1_t;

static inline uint64_t BDK_CIMX_ICC_HPPIR0_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_HPPIR0_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063210ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_HPPIR0_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_HPPIR0_EL1(...) bdk_cimx_icc_hppir0_el1_t
#define bustype_BDK_CIMX_ICC_HPPIR0_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_HPPIR0_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_HPPIR0_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_HPPIR0_EL1(...) "CIMX_ICC_HPPIR0_EL1"


/**
 * NCB - cim#_icc_hppir1_el1
 *
 * Result of pseudocode ReadICC_HPPIR1_EL1. Indicates the Interrupt ID of the highest priority
 * pending
 * group 1 interrupt on the CPU interface.
 */
typedef union bdk_cimx_icc_hppir1_el1 {
	uint64_t u;
	struct bdk_cimx_icc_hppir1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t pendintid                   : 20; /**< RO/H - Pending Interrupt ID.
                                                                 Whether the value returned by a read of CIM()_ICC_HPPIR0_EL1 is a valid interrupt ID
                                                                 can depend on:

                                                                 1. Whether the highest priority pending interrupt is configured as a group 0 or a group 1
                                                                 interrupt.

                                                                 2. Whether the register access is secure or non-secure.

                                                                 Reads of the CIM()_ICC_HPPIR0_EL1 that do not return a valid interrupt ID return a
                                                                 spurious interrupt ID, ID 1022 or 1023.

                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which FIQ is routed.

                                                                 ARM clarified CIM()_ICC_HPPIR0_EL1 is agnostic of level/edge triggering therefore
                                                                 "active and pending" means "active" only for CIM. */
#else
		uint64_t pendintid                   : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_hppir1_el1_s   cn88xx; */
	/* struct bdk_cimx_icc_hppir1_el1_s   cn88xxp1; */
} bdk_cimx_icc_hppir1_el1_t;

static inline uint64_t BDK_CIMX_ICC_HPPIR1_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_HPPIR1_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063310ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_HPPIR1_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_HPPIR1_EL1(...) bdk_cimx_icc_hppir1_el1_t
#define bustype_BDK_CIMX_ICC_HPPIR1_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_HPPIR1_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_HPPIR1_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_HPPIR1_EL1(...) "CIMX_ICC_HPPIR1_EL1"


/**
 * NCB - cim#_icc_iar0_el1
 *
 * Result of pseudocode ReadICC_IAR0_EL1. The processor reads this register
 * to obtain the interrupt ID of the signaled group 0 interrupt. This
 * read acts as an acknowledge for the interrupt and activates pseudocode ReadICC_IAR1_EL1.
 */
typedef union bdk_cimx_icc_iar0_el1 {
	uint64_t u;
	struct bdk_cimx_icc_iar0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t intid                       : 20; /**< RO/H - Interrupt ID.
                                                                 The intent is that the CPU receives a special purpose ID that indicates the target
                                                                 security domain if the interrupt is destined for EL1/EL2.

                                                                 Any effects of the processor reading this register on the signaling of interrupt
                                                                 exceptions to the processor must be observed when the instruction is architecturally
                                                                 executed.

                                                                 Because direct reads of system registers by the processor may occur in any order, if
                                                                 software wishes to perform multiple accesses to this register without an intervening
                                                                 exception it must use an appropriate barrier to guarantee the ordering of these accesses. */
#else
		uint64_t intid                       : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_iar0_el1_s     cn88xx; */
	/* struct bdk_cimx_icc_iar0_el1_s     cn88xxp1; */
} bdk_cimx_icc_iar0_el1_t;

static inline uint64_t BDK_CIMX_ICC_IAR0_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IAR0_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063200ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IAR0_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IAR0_EL1(...) bdk_cimx_icc_iar0_el1_t
#define bustype_BDK_CIMX_ICC_IAR0_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IAR0_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_IAR0_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IAR0_EL1(...) "CIMX_ICC_IAR0_EL1"


/**
 * NCB - cim#_icc_iar1_el1
 *
 * Result of pseudocode ReadICC_IAR1_EL1. The processor reads this register
 * to obtain the interrupt ID of the signaled group 1 interrupt. This
 * read acts as an acknowledge for the interrupt and activates pseudocode ReadICC_IAR1_EL1.
 */
typedef union bdk_cimx_icc_iar1_el1 {
	uint64_t u;
	struct bdk_cimx_icc_iar1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t intid                       : 20; /**< RO/H - Interrupt ID.
                                                                 The intent is that the CPU will receive a spurious ID if the interrupt is a secure
                                                                 Group 0 ID or if the interrupt is destined for the other security domain.

                                                                 Any effects of reading this register on the signaling of interrupt exceptions to the
                                                                 processor must be observed when the instruction is architecturally executed.

                                                                 Because direct reads of system registers may occur in any order, if software wishes
                                                                 to perform multiple accesses to this register without an intervening exception it must use
                                                                 an appropriate barrier to guarantee the ordering of these accesses. */
#else
		uint64_t intid                       : 20;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_cimx_icc_iar1_el1_s     cn88xx; */
	/* struct bdk_cimx_icc_iar1_el1_s     cn88xxp1; */
} bdk_cimx_icc_iar1_el1_t;

static inline uint64_t BDK_CIMX_ICC_IAR1_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IAR1_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063300ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IAR1_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IAR1_EL1(...) bdk_cimx_icc_iar1_el1_t
#define bustype_BDK_CIMX_ICC_IAR1_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IAR1_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_IAR1_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IAR1_EL1(...) "CIMX_ICC_IAR1_EL1"


/**
 * NCB - cim#_icc_igrpen0_el1
 *
 * Physical group 0 enabled EL1 Register
 *
 */
typedef union bdk_cimx_icc_igrpen0_el1 {
	uint64_t u;
	struct bdk_cimx_icc_igrpen0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t en                          : 1;  /**< R/W - Enable.
                                                                 This register controls whether group 0 interrupts are enabled or not.
                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which FIQ is routed.

                                                                 Virtual accesses to this register update CIM()_ICH_VMCR_EL2[VENG0].

                                                                 If an interrupt is pending within the CPU interface when enable becomes zero, the
                                                                 interrupt must be released to allow the distributor to forward the interrupt to a
                                                                 different processor. */
#else
		uint64_t en                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_cimx_icc_igrpen0_el1_s  cn88xx; */
	/* struct bdk_cimx_icc_igrpen0_el1_s  cn88xxp1; */
} bdk_cimx_icc_igrpen0_el1_t;

static inline uint64_t BDK_CIMX_ICC_IGRPEN0_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IGRPEN0_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063330ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IGRPEN0_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IGRPEN0_EL1(...) bdk_cimx_icc_igrpen0_el1_t
#define bustype_BDK_CIMX_ICC_IGRPEN0_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IGRPEN0_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_IGRPEN0_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IGRPEN0_EL1(...) "CIMX_ICC_IGRPEN0_EL1"


/**
 * NCB - cim#_icc_igrpen1_el1_ns
 *
 * Physical non-secure group 1 enabled for state determined from SCR_EL3[NS] EL1 Register
 *
 */
typedef union bdk_cimx_icc_igrpen1_el1_ns {
	uint64_t u;
	struct bdk_cimx_icc_igrpen1_el1_ns_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t en                          : 1;  /**< R/W/H - Enable.
                                                                 This register controls whether group 1 interrupts are enabled or not when SCR_EL3[NS] == 1
                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which IRQ is routed.

                                                                 Virtual accesses to this register update CIM()_ICH_VMCR_EL2[VENG1].

                                                                 If an interrupt is pending within the CPU interface when [EN] becomes zero, the
                                                                 interrupt must be released to allow the distributor to forward the interrupt to a
                                                                 different processor. */
#else
		uint64_t en                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_cimx_icc_igrpen1_el1_ns_s cn88xx; */
	/* struct bdk_cimx_icc_igrpen1_el1_ns_s cn88xxp1; */
} bdk_cimx_icc_igrpen1_el1_ns_t;

static inline uint64_t BDK_CIMX_ICC_IGRPEN1_EL1_NS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IGRPEN1_EL1_NS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063338ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IGRPEN1_EL1_NS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IGRPEN1_EL1_NS(...) bdk_cimx_icc_igrpen1_el1_ns_t
#define bustype_BDK_CIMX_ICC_IGRPEN1_EL1_NS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IGRPEN1_EL1_NS(p1) (p1)
#define arguments_BDK_CIMX_ICC_IGRPEN1_EL1_NS(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IGRPEN1_EL1_NS(...) "CIMX_ICC_IGRPEN1_EL1_NS"


/**
 * NCB - cim#_icc_igrpen1_el1_s
 *
 * Physical secure group 1 enabled for state determined from SCR_EL3[NS] EL1 register
 *
 */
typedef union bdk_cimx_icc_igrpen1_el1_s {
	uint64_t u;
	struct bdk_cimx_icc_igrpen1_el1_s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t en                          : 1;  /**< R/W/H - Enable.
                                                                 This register controls whether group 1 interrupts are enabled or not when SCR_EL3[NS] == 0
                                                                 The lowest exception level at which this register may be accessed is governed by the
                                                                 exception level to which IRQ is routed.

                                                                 Virtual accesses to this register update CIM()_ICH_VMCR_EL2[VENG1].

                                                                 If an interrupt is pending within the CPU interface when EN becomes zero, the
                                                                 interrupt must be released to allow the distributor to forward the interrupt to a
                                                                 different processor. */
#else
		uint64_t en                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_cimx_icc_igrpen1_el1_s_s cn88xx; */
	/* struct bdk_cimx_icc_igrpen1_el1_s_s cn88xxp1; */
} bdk_cimx_icc_igrpen1_el1_s_t;

static inline uint64_t BDK_CIMX_ICC_IGRPEN1_EL1_S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IGRPEN1_EL1_S(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000067338ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IGRPEN1_EL1_S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IGRPEN1_EL1_S(...) bdk_cimx_icc_igrpen1_el1_s_t
#define bustype_BDK_CIMX_ICC_IGRPEN1_EL1_S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IGRPEN1_EL1_S(p1) (p1)
#define arguments_BDK_CIMX_ICC_IGRPEN1_EL1_S(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IGRPEN1_EL1_S(...) "CIMX_ICC_IGRPEN1_EL1_S"


/**
 * NCB - cim#_icc_igrpen1_el3
 *
 * Physical secure group 1 enabled for both security states.
 *
 */
typedef union bdk_cimx_icc_igrpen1_el3 {
	uint64_t u;
	struct bdk_cimx_icc_igrpen1_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t engrp1_s                    : 1;  /**< R/W/H - Enable group 1 secure.
                                                                 If an interrupt is pending within the CPU interface when an Enable becomes zero, the
                                                                 interrupt must be released to allow the distributor to forward the interrupt to a
                                                                 different processor. */
		uint64_t engrp1_ns                   : 1;  /**< R/W/H - Enable group 1 non-secure.
                                                                 If an interrupt is pending within the CPU interface when an Enable becomes zero, the
                                                                 interrupt must be released to allow the distributor to forward the interrupt to a
                                                                 different processor. */
#else
		uint64_t engrp1_ns                   : 1;
		uint64_t engrp1_s                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_cimx_icc_igrpen1_el3_s  cn88xx; */
	/* struct bdk_cimx_icc_igrpen1_el3_s  cn88xxp1; */
} bdk_cimx_icc_igrpen1_el3_t;

static inline uint64_t BDK_CIMX_ICC_IGRPEN1_EL3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IGRPEN1_EL3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B00007B338ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IGRPEN1_EL3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IGRPEN1_EL3(...) bdk_cimx_icc_igrpen1_el3_t
#define bustype_BDK_CIMX_ICC_IGRPEN1_EL3(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IGRPEN1_EL3(p1) (p1)
#define arguments_BDK_CIMX_ICC_IGRPEN1_EL3(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IGRPEN1_EL3(...) "CIMX_ICC_IGRPEN1_EL3"


/**
 * NCB - cim#_icc_imp0
 *
 * Register used by CIM internally for storage. Inaccessible to cores.
 *
 */
typedef union bdk_cimx_icc_imp0 {
	uint64_t u;
	struct bdk_cimx_icc_imp0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t scratch                     : 26; /**< RO/H - Testing area. */
		uint64_t ds                          : 1;  /**< RO/H - Disable security.
                                                                 Local version of GICD_(S)CTLR[DS] maintained by (a limited number of) downstream
                                                                 writes from redistributor. Specifically, it is permissible to get a downstream write from
                                                                 RDB which sets DS to 1 at some point. However, behavior is architecturally undefined if
                                                                 RDB ever follows that with a DS resetting downstream write. */
#else
		uint64_t ds                          : 1;
		uint64_t scratch                     : 26;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_cimx_icc_imp0_s         cn88xx; */
	/* struct bdk_cimx_icc_imp0_s         cn88xxp1; */
} bdk_cimx_icc_imp0_t;

static inline uint64_t BDK_CIMX_ICC_IMP0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_IMP0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B00007C000ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_IMP0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_IMP0(...) bdk_cimx_icc_imp0_t
#define bustype_BDK_CIMX_ICC_IMP0(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_IMP0(p1) (p1)
#define arguments_BDK_CIMX_ICC_IMP0(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_IMP0(...) "CIMX_ICC_IMP0"


/**
 * NCB - cim#_icc_pmr_el1
 *
 * Result of pseudocode ReadICC_PMR_EL1 for read access, activation of WriteICC_PMR_EL1 for write
 * access in physical mode.
 *
 * Read of or write to CIM()_ICH_VMCR_EL2[PMR] in virtual mode.
 *
 * Provides an interrupt priority filter. Only interrupts with higher priority than the value in
 * this register are signaled to the processor.
 */
typedef union bdk_cimx_icc_pmr_el1 {
	uint64_t u;
	struct bdk_cimx_icc_pmr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t pri                         : 8;  /**< R/W - Priority.
                                                                 If the priority of an interrupt is higher than the value indicated by this field, the
                                                                 interface signals the interrupt to the processor.

                                                                 A Non-secure access to this register can only read or write a value that corresponds to
                                                                 the lower half of the priority range.
                                                                 If a secure write has programmed the CIM()_ICC_PMR_EL1 with a value that corresponds
                                                                 to a value in
                                                                 the upper half of the priority range then:

                                                                 _ 1. Any non-secure read of the CIM()_ICC_PMR_EL1 returns 0x00, regardless of the
                                                                 value held in the
                                                                 register.

                                                                 _ 2. Any non-secure write to the CIM()_ICC_PMR_EL1 is ignored.

                                                                 When determining interrupt preemption, the priority value can be split into two parts,
                                                                 using CIM()_ICC_BPR.

                                                                 Higher priority corresponds to a lower priority field value.

                                                                 If the GIC supports fewer than 256 priority levels then some bits are RAZ/WI, as
                                                                 follows:

                                                                 _     128 supported levels Bit [0] = 0
                                                                 _     ...
                                                                 _     16  supported levels Bit [3:0] = 0x0

                                                                 Accesses to this register trap to EL2 (HYP_TRAP) if CIM()_ICH_HCR_EL2[TC] == 1.

                                                                 An access is virtual when accessed at non-secure EL1 and either of FIQ and IRQ have
                                                                 been virtualized. That is, when
                                                                 _     (PSTATE[EL] == 1 && SCR_EL3[NS] == 1 && (HCR_EL2[FMO] == 1 || HCR_EL2[IMO] == 1)). */
#else
		uint64_t pri                         : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_cimx_icc_pmr_el1_s      cn88xx; */
	/* struct bdk_cimx_icc_pmr_el1_s      cn88xxp1; */
} bdk_cimx_icc_pmr_el1_t;

static inline uint64_t BDK_CIMX_ICC_PMR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_PMR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000061180ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_PMR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_PMR_EL1(...) bdk_cimx_icc_pmr_el1_t
#define bustype_BDK_CIMX_ICC_PMR_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_PMR_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_PMR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_PMR_EL1(...) "CIMX_ICC_PMR_EL1"


/**
 * NCB - cim#_icc_rpr_el1
 *
 * Result of pseudocode ReadICC_RPR_EL1. Indicates the running priority of the CPU interface.
 *
 */
typedef union bdk_cimx_icc_rpr_el1 {
	uint64_t u;
	struct bdk_cimx_icc_rpr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t pri                         : 8;  /**< RO/H - Priority.
                                                                 The current running priority on the CPU interface.
                                                                 ARM clarified that this register returns the "normal" priority (not group priority) of the
                                                                 current active interrupt.
                                                                 If there is no active interrupt on the CPU interface, the value returned is the idle
                                                                 priority.

                                                                 The value returned by a non-secure read of the priority field is:

                                                                   1. 0x00 if the field value is less than 0x80

                                                                   2. The non-secure view of the priority value if the field value is 0x80 or more.

                                                                 Virtual accesses to this register trap to EL2 (HYP_TRAP) if
                                                                 CIM()_ICH_HCR_EL2[TC] == 1. */
#else
		uint64_t pri                         : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_cimx_icc_rpr_el1_s      cn88xx; */
	/* struct bdk_cimx_icc_rpr_el1_s      cn88xxp1; */
} bdk_cimx_icc_rpr_el1_t;

static inline uint64_t BDK_CIMX_ICC_RPR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_RPR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000632D8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_RPR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_RPR_EL1(...) bdk_cimx_icc_rpr_el1_t
#define bustype_BDK_CIMX_ICC_RPR_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_RPR_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_RPR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_RPR_EL1(...) "CIMX_ICC_RPR_EL1"


/**
 * NCB - cim#_icc_sgi0r_el1
 *
 * When CIM()_ICC_SGI0R_EL1 is written, this results in the generation of interrupts to a
 * set of
 * processors
 * a.b.c.{target list}, where target list is a set of up to sixteen processors within the
 * affinity cluster defines by a.b.c.*.
 *
 * If SRE is set only for secure EL3, software executing at EL3 might use the system
 * register interface to generate SGIs. Hence, the distributor
 *       must always correctly handle generate SGI packets received from CPU interface regardless
 * of the ARE settings for a security state.
 *
 * Virtual accesses to these registers always trap to EL2 (HYP_TRAP).
 *
 * Accesses to these registers trap to EL2 (HYP_TRAP) if CIM()_ICH_HCR_EL2[TC] == 1.
 *
 * This register provides software the ability to generate secure group 0 SGIs, including from
 * the non-secure state, when permitted by GICR_NSACR.
 */
typedef union bdk_cimx_icc_sgi0r_el1 {
	uint64_t u;
	struct bdk_cimx_icc_sgi0r_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t affinity3                   : 8;  /**< WO - Affinity 3. The affinity 3 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t reserved_41_47              : 7;
		uint64_t irm                         : 1;  /**< WO - Interrupt routing mode.
                                                                 When this field is one, the TGTLIST, AFFINITY1, AFFINITY2 and AFFINITY3
                                                                 fields are reserved. */
		uint64_t affinity2                   : 8;  /**< WO - Affinity 2. The affinity 2 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t reserved_28_31              : 4;
		uint64_t intid                       : 4;  /**< WO - SGI Interrupt ID. */
		uint64_t affinity1                   : 8;  /**< WO - Affinity 1. The affinity 1 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t tgtlist                     : 16; /**< WO - The set of processor for which SGI interrupts will be generated. Each bit corresponds to
                                                                 the processor within a cluster with an affinity 0 value equal to the bit number.

                                                                 If a bit is one and the bit does not correspond to a valid target processor, the bit
                                                                 must be ignored by the distributor. In such cases, a distributor may optionally generate
                                                                 an SEI.
                                                                 This restricts distribution of SGIs to the first 16 processors of an affinity 1
                                                                 cluster.

                                                                 If software specifies affinity 3 (if appropriate), affinity 2 and affinity 1 values
                                                                 that do not correspond to a valid set of target processors the distributor must
                                                                 acknowledge and discard the generate SGI packet. It may optionally generate an SEI. */
#else
		uint64_t tgtlist                     : 16;
		uint64_t affinity1                   : 8;
		uint64_t intid                       : 4;
		uint64_t reserved_28_31              : 4;
		uint64_t affinity2                   : 8;
		uint64_t irm                         : 1;
		uint64_t reserved_41_47              : 7;
		uint64_t affinity3                   : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_cimx_icc_sgi0r_el1_s    cn88xx; */
	/* struct bdk_cimx_icc_sgi0r_el1_s    cn88xxp1; */
} bdk_cimx_icc_sgi0r_el1_t;

static inline uint64_t BDK_CIMX_ICC_SGI0R_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_SGI0R_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000632E8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_SGI0R_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_SGI0R_EL1(...) bdk_cimx_icc_sgi0r_el1_t
#define bustype_BDK_CIMX_ICC_SGI0R_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_SGI0R_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_SGI0R_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_SGI0R_EL1(...) "CIMX_ICC_SGI0R_EL1"


/**
 * NCB - cim#_icc_sgi1r_el1
 *
 * When CIM()_ICC_SGI1R_EL1 is written, this results in the generation of interrupts to a
 * set of
 * processors
 * a.b.c.{target list}, where target list is a set of up to sixteen processors within the
 * affinity cluster defines by a.b.c.*.
 *
 * If SRE is set only for secure EL3, software executing at EL3 might use the system
 * register interface to generate SGIs. Hence, the distributor
 *       must always correctly handle generate SGI packets received from CPU interface regardless
 * of the ARE settings for a security state.
 *
 * Virtual accesses to these registers always trap to EL2 (HYP_TRAP).
 *
 * Accesses to these registers trap to EL2 (HYP_TRAP) if CIM()_ICH_HCR_EL2[TC] == 1;
 *
 * This register provides software the ability to generate group 1 SGIs for its own security
 * state. That is, non-secure EL1 / EL2 accesses may generate non-secure group 1 interrupts and
 * secure EL1 / EL3 may generate secure group 1 interrupts.
 */
typedef union bdk_cimx_icc_sgi1r_el1 {
	uint64_t u;
	struct bdk_cimx_icc_sgi1r_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t affinity3                   : 8;  /**< WO - Affinity 3. The affinity 3 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t reserved_41_47              : 7;
		uint64_t irm                         : 1;  /**< WO - Interrupt routing mode.
                                                                 When this field is one, the TGTLIST, AFFINITY1, AFFINITY2 and AFFINITY3
                                                                 fields are reserved. */
		uint64_t affinity2                   : 8;  /**< WO - Affinity 2. The affinity 2 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t reserved_28_31              : 4;
		uint64_t intid                       : 4;  /**< WO - SGI Interrupt ID. */
		uint64_t affinity1                   : 8;  /**< WO - Affinity 1. The affinity 1 value of the affinity path of the cluster for which SGI
                                                                 interrupts will be generated. */
		uint64_t tgtlist                     : 16; /**< WO - The set of processor for which SGI interrupts will be generated. Each bit corresponds to
                                                                 the processor within a cluster with an affinity 0 value equal to the bit number.

                                                                 If a bit is one and the bit does not correspond to a valid target processor, the bit
                                                                 must be ignored by the distributor. In such cases, a distributor may optionally generate
                                                                 an.
                                                                 This restricts distribution of SGIs to the first 16 processors of an affinity 1
                                                                 cluster.

                                                                 If software specifies AFFINITY3 (if appropriate), AFFINITY2 and AFFINITY1 values
                                                                 that do not correspond to a valid set of target processors the distributor must
                                                                 acknowledge and discard the generate SGI packet. It may optionally generate an SEI. */
#else
		uint64_t tgtlist                     : 16;
		uint64_t affinity1                   : 8;
		uint64_t intid                       : 4;
		uint64_t reserved_28_31              : 4;
		uint64_t affinity2                   : 8;
		uint64_t irm                         : 1;
		uint64_t reserved_41_47              : 7;
		uint64_t affinity3                   : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_cimx_icc_sgi1r_el1_s    cn88xx; */
	/* struct bdk_cimx_icc_sgi1r_el1_s    cn88xxp1; */
} bdk_cimx_icc_sgi1r_el1_t;

static inline uint64_t BDK_CIMX_ICC_SGI1R_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_SGI1R_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000632F0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_SGI1R_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_SGI1R_EL1(...) bdk_cimx_icc_sgi1r_el1_t
#define bustype_BDK_CIMX_ICC_SGI1R_EL1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_SGI1R_EL1(p1) (p1)
#define arguments_BDK_CIMX_ICC_SGI1R_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_SGI1R_EL1(...) "CIMX_ICC_SGI1R_EL1"


/**
 * NCB - cim#_icc_sre_el1_ns
 *
 * This non-secure register governs whether the system register interface or the memory mapped
 * interface to the GIC CPU interface is to be used for EL0/1.
 */
typedef union bdk_cimx_icc_sre_el1_ns {
	uint64_t u;
	struct bdk_cimx_icc_sre_el1_ns_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t dib                         : 1;  /**< RO/H - Disable IRQ bypass.
                                                                 In CNXXXX, this bit is always 1 as IRQ bypass is always disabled. */
		uint64_t dfb                         : 1;  /**< RO/H - Disable FIQ bypass.
                                                                 In CNXXXX, this bit is always 1 as FIQ bypass is always disabled. */
		uint64_t sre                         : 1;  /**< RO/H - System Register Enable.
                                                                 In CNXXXX, this bit is always 1 as all registers are implemented locally. */
#else
		uint64_t sre                         : 1;
		uint64_t dfb                         : 1;
		uint64_t dib                         : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_cimx_icc_sre_el1_ns_s   cn88xx; */
	/* struct bdk_cimx_icc_sre_el1_ns_s   cn88xxp1; */
} bdk_cimx_icc_sre_el1_ns_t;

static inline uint64_t BDK_CIMX_ICC_SRE_EL1_NS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_SRE_EL1_NS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000063328ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_SRE_EL1_NS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_SRE_EL1_NS(...) bdk_cimx_icc_sre_el1_ns_t
#define bustype_BDK_CIMX_ICC_SRE_EL1_NS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_SRE_EL1_NS(p1) (p1)
#define arguments_BDK_CIMX_ICC_SRE_EL1_NS(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_SRE_EL1_NS(...) "CIMX_ICC_SRE_EL1_NS"


/**
 * NCB - cim#_icc_sre_el1_s
 *
 * This secure register governs whether the system register interface or the memory mapped
 * interface to the GIC CPU interface is to be used for EL0/1.
 */
typedef union bdk_cimx_icc_sre_el1_s {
	uint64_t u;
	struct bdk_cimx_icc_sre_el1_s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t dib                         : 1;  /**< RO/H - Disable IRQ bypass.
                                                                 In CNXXXX, this bit is always 1 as IRQ bypass is always disabled. */
		uint64_t dfb                         : 1;  /**< RO/H - Disable FIQ bypass.
                                                                 In CNXXXX, this bit is always 1 as FIQ bypass is always disabled. */
		uint64_t sre                         : 1;  /**< RO/H - System Register Enable.
                                                                 In CNXXXX, this bit is always 1 as all registers are implemented locally. */
#else
		uint64_t sre                         : 1;
		uint64_t dfb                         : 1;
		uint64_t dib                         : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_cimx_icc_sre_el1_s_s    cn88xx; */
	/* struct bdk_cimx_icc_sre_el1_s_s    cn88xxp1; */
} bdk_cimx_icc_sre_el1_s_t;

static inline uint64_t BDK_CIMX_ICC_SRE_EL1_S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_SRE_EL1_S(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000067328ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_SRE_EL1_S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_SRE_EL1_S(...) bdk_cimx_icc_sre_el1_s_t
#define bustype_BDK_CIMX_ICC_SRE_EL1_S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_SRE_EL1_S(p1) (p1)
#define arguments_BDK_CIMX_ICC_SRE_EL1_S(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_SRE_EL1_S(...) "CIMX_ICC_SRE_EL1_S"


/**
 * NCB - cim#_icc_sre_el2
 *
 * This secure register governs whether the system register interface or the memory mapped
 * interface to the GIC CPU interface is to be used for EL2.
 */
typedef union bdk_cimx_icc_sre_el2 {
	uint64_t u;
	struct bdk_cimx_icc_sre_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t en                          : 1;  /**< R/W - Enables lower exception level access to CIM()_ICC_SRE_EL1.
                                                                 0 = non-secure EL1 accesses to CIM()_ICC_SRE_EL1 trap to EL2.
                                                                 1 = non-secure EL1 accesses to CIM()_ICC_SRE_EL1 are permitted if
                                                                 CIM()_ICC_SRE_EL3[EN] is one, otherwise non-secure EL1 accesses
                                                                 to CIM()_ICC_SRE_EL1 trap to EL3. */
		uint64_t dib                         : 1;  /**< RO/H - Disable IRQ bypass.
                                                                 In CNXXXX, this bit is always 1 as IRQ bypass is always disabled. */
		uint64_t dfb                         : 1;  /**< RO/H - Disable FIQ bypass.
                                                                 In CNXXXX, this bit is always 1 as FIQ bypass is always disabled. */
		uint64_t sre                         : 1;  /**< RO/H - System Register Enable.
                                                                 In CNXXXX, this bit is always 1 as all registers are implemented locally. */
#else
		uint64_t sre                         : 1;
		uint64_t dfb                         : 1;
		uint64_t dib                         : 1;
		uint64_t en                          : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_cimx_icc_sre_el2_s      cn88xx; */
	/* struct bdk_cimx_icc_sre_el2_s      cn88xxp1; */
} bdk_cimx_icc_sre_el2_t;

static inline uint64_t BDK_CIMX_ICC_SRE_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_SRE_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000073268ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_SRE_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_SRE_EL2(...) bdk_cimx_icc_sre_el2_t
#define bustype_BDK_CIMX_ICC_SRE_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_SRE_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICC_SRE_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_SRE_EL2(...) "CIMX_ICC_SRE_EL2"


/**
 * NCB - cim#_icc_sre_el3
 *
 * This secure register governs whether the system register interface or the memory mapped
 * interface to the GIC CPU interface is to be used for EL3.
 */
typedef union bdk_cimx_icc_sre_el3 {
	uint64_t u;
	struct bdk_cimx_icc_sre_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t en                          : 1;  /**< R/W - Enables lower exception level access to CIM()_ICC_SRE_EL1/2.
                                                                 0 = EL1/2 accesses to CIM()_ICC_SRE_EL1/2 trap to EL3.
                                                                 1 = EL2 accesses to CIM()_ICC_SRE_EL2 are permitted. */
		uint64_t dib                         : 1;  /**< RO/H - Disable IRQ bypass.
                                                                 In CNXXXX, this bit is always 1 as IRQ bypass is always disabled. */
		uint64_t dfb                         : 1;  /**< RO/H - Disable FIQ bypass.
                                                                 In CNXXXX, this bit is always 1 as FIQ bypass is always disabled. */
		uint64_t sre                         : 1;  /**< RO/H - System Register Enable.
                                                                 In CNXXXX, this bit is always 1 as all registers are implemented locally. */
#else
		uint64_t sre                         : 1;
		uint64_t dfb                         : 1;
		uint64_t dib                         : 1;
		uint64_t en                          : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_cimx_icc_sre_el3_s      cn88xx; */
	/* struct bdk_cimx_icc_sre_el3_s      cn88xxp1; */
} bdk_cimx_icc_sre_el3_t;

static inline uint64_t BDK_CIMX_ICC_SRE_EL3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICC_SRE_EL3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B00007B328ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICC_SRE_EL3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICC_SRE_EL3(...) bdk_cimx_icc_sre_el3_t
#define bustype_BDK_CIMX_ICC_SRE_EL3(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICC_SRE_EL3(p1) (p1)
#define arguments_BDK_CIMX_ICC_SRE_EL3(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICC_SRE_EL3(...) "CIMX_ICC_SRE_EL3"


/**
 * NCB - cim#_ich_ap0r0_el2
 *
 * Hypervisor active priorities group 0 Register0 for EL2 Register.
 * This register tracks which preemption levels are active in the virtual CPU interface for
 * Group 0, and is used to determine the current active priority. Corresponding bits are
 * set in this register when an interrupt is acknowledged, based on CIM()_ICH_LRn_EL2.
 * Priority, and the least significant set bit is cleared on EOI.
 *
 * The number of register implemented depends on how many bits of priority are implemented
 * in CIM()_ICH_LRn_EL2 (this number can be discovered from
 * CIM()_ICH_VTR_EL2[PRIBITS]); they range between 5 and 7, see 5.9.10 for details.
 *
 * Only a single interrupt group can be active for any active priority bit in
 * CIM()_ICH_AP0Rn_EL2 and CIM()_ICH_AP1Rn_EL2. This means that:
 *
 *   1. Writes to CIM()_ICH_AP0Rn_EL2 with bits set to one will set bits to one in
 *      CIM()_ICH_AP0Rn_EL2 and will set the corresponding bits to zero
 *      in CIM()_ICH_AP1Rn_EL2
 *
 *   2. Writes to CIM()_ICH_AP0Rn_EL2 with bits set to zero will set bits to zero bits
 *     in CIM()_ICH_AP0Rn_EL2 and will not affect CIM()_ICH_AP1Rn_EL2.
 *
 * A maximum of 7 bits of priority (rather than 8) are supported by the
 * CIM()_ICC_AP0R{0..3}_EL1 and CIM()_ICC_AP1R{0..3}_EL1 registers because when
 * the binary point value is zero, the group priority field is bits [7:1] of the priority
 * and bit [0] is never used for pre-emption. The description of this register and fields
 * also applies to CIM()_ICH_AP0R1_EL2 .. CIM()_ICH_AP0R3_EL3.
 */
typedef union bdk_cimx_ich_ap0r0_el2 {
	uint64_t u;
	struct bdk_cimx_ich_ap0r0_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ap                          : 32; /**< R/W/H - Operates in conjunction with all other AP0R and with the appropriate BPR
                                                                 register.
                                                                 A set bit indicates an active priority group.
                                                                 For usage cases see CIM()_ICC_AP0R. */
#else
		uint64_t ap                          : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_ich_ap0r0_el2_s    cn88xx; */
	/* struct bdk_cimx_ich_ap0r0_el2_s    cn88xxp1; */
} bdk_cimx_ich_ap0r0_el2_t;

static inline uint64_t BDK_CIMX_ICH_AP0R0_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_AP0R0_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000073200ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_AP0R0_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_AP0R0_EL2(...) bdk_cimx_ich_ap0r0_el2_t
#define bustype_BDK_CIMX_ICH_AP0R0_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_AP0R0_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_AP0R0_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_AP0R0_EL2(...) "CIMX_ICH_AP0R0_EL2"


/**
 * NCB - cim#_ich_ap1r0_el2
 *
 * This register tracks which preemption levels are active in the virtual CPU interface for
 * Group 1, and is used to determine the current active priority. Corresponding bits are
 * set in this register when an interrupt is acknowledged, based on CIM()_ICH_LRn.
 *
 * Priority, and the least significant set bit is cleared on EOI. The number of register
 * implemented depends on how many bits of priority are implemented in CIM()_ICH_LRn_EL2
 * (this number can be discovered from CIM()_ICH_VTR_EL2[PRIBITS]); they range
 * between 5 and 7. Only a single interrupt group can be active for any active priority bit in
 * CIM()_ICH_AP0Rn_EL2 and CIM()_ICH_AP1Rn_EL2. This means that writes to
 * CIM()_ICH_AP1Rn_EL2 with bits set to one will set bits to one in
 * CIM()_ICH_AP1Rn_EL2 only if the corresponding bits are zero in CIM()_ICH_AP0Rn_EL2
 * The description of this register and fields also applies to CIM()_ICH_AP1R1_EL2
 * CIM()_ICH_AP1R3_EL3.
 */
typedef union bdk_cimx_ich_ap1r0_el2 {
	uint64_t u;
	struct bdk_cimx_ich_ap1r0_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ap                          : 32; /**< R/W/H - Operates in conjunction with all other AP1R and with the appropriate BPR
                                                                 register.
                                                                 A set bit indicates an active priority group.
                                                                 For usage cases see CIM()_ICC_AP1R. */
#else
		uint64_t ap                          : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_ich_ap1r0_el2_s    cn88xx; */
	/* struct bdk_cimx_ich_ap1r0_el2_s    cn88xxp1; */
} bdk_cimx_ich_ap1r0_el2_t;

static inline uint64_t BDK_CIMX_ICH_AP1R0_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_AP1R0_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B000073240ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_AP1R0_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_AP1R0_EL2(...) bdk_cimx_ich_ap1r0_el2_t
#define bustype_BDK_CIMX_ICH_AP1R0_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_AP1R0_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_AP1R0_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_AP1R0_EL2(...) "CIMX_ICH_AP1R0_EL2"


/**
 * NCB - cim#_ich_eisr_el2
 *
 * When a maintenance interrupt is received, these registers help determine which list
 * registers have outstanding EOI interrupts that require servicing.
 */
typedef union bdk_cimx_ich_eisr_el2 {
	uint64_t u;
	struct bdk_cimx_ich_eisr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t lreoisb                     : 16; /**< RO/H - List register EOI status bits.
                                                                 CIM()_ICH_EISR_EL2[LREOISB[n]] == 1 indicates CIM()_ICH_LRn has an EOI.
                                                                 For any CIM()_ICH_LRn, the corresponding status bit is set to 1 if

                                                                 _ (CIM()_ICH_LRn[State] ==00 &&
                                                                 _  CIM()_ICH_LRn[HW]    ==0    &&
                                                                 _  CIM()_ICH_LRn[EOI]   ==1). */
#else
		uint64_t lreoisb                     : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_cimx_ich_eisr_el2_s     cn88xx; */
	/* struct bdk_cimx_ich_eisr_el2_s     cn88xxp1; */
} bdk_cimx_ich_eisr_el2_t;

static inline uint64_t BDK_CIMX_ICH_EISR_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_EISR_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000732D8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_EISR_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_EISR_EL2(...) bdk_cimx_ich_eisr_el2_t
#define bustype_BDK_CIMX_ICH_EISR_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_EISR_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_EISR_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_EISR_EL2(...) "CIMX_ICH_EISR_EL2"


/**
 * NCB - cim#_ich_elsr_el2
 *
 * These registers can be used to locate a usable list register when the hypervisor is
 * delivering an interrupt to a guest OS.
 *
 * INTERNAL: This register was renamed ICH_ELRSR_EL2 in OBAN of 2014-06-13 after
 * release v20 of GIC v3.
 */
typedef union bdk_cimx_ich_elsr_el2 {
	uint64_t u;
	struct bdk_cimx_ich_elsr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t lrsb                        : 16; /**< RO/H - List register status bits.
                                                                 For CIM()_ICH_ELSR_EL2[LREOISB[n]] each bit:
                                                                 0 = The corresponding list register, if implemented, contains a valid interrupt. Using
                                                                 this list register can result in overwriting a valid interrupt.
                                                                 1 = The corresponding list register does not contain a valid interrupt. The list register
                                                                 is empty and can be used without overwriting a valid interrupt or
                                                                 losing an EOI maintenance interrupt.

                                                                 For any CIM()_ICH_LRn, the corresponding status bit is set to 1 if

                                                                 _ (CIM()_ICH_LRn[State] ==00 &&
                                                                 _  (CIM()_ICH_LRn[HW]   ==1       ||
                                                                 _   CIM()_ICH_LRn[EOI]  ==0)). */
#else
		uint64_t lrsb                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_cimx_ich_elsr_el2_s     cn88xx; */
	/* struct bdk_cimx_ich_elsr_el2_s     cn88xxp1; */
} bdk_cimx_ich_elsr_el2_t;

static inline uint64_t BDK_CIMX_ICH_ELSR_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_ELSR_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000732E8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_ELSR_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_ELSR_EL2(...) bdk_cimx_ich_elsr_el2_t
#define bustype_BDK_CIMX_ICH_ELSR_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_ELSR_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_ELSR_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_ELSR_EL2(...) "CIMX_ICH_ELSR_EL2"


/**
 * NCB - cim#_ich_hcr_el2
 *
 * This register controls the environment for guest operating systems.
 *
 */
typedef union bdk_cimx_ich_hcr_el2 {
	uint64_t u;
	struct bdk_cimx_ich_hcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eoicount                    : 5;  /**< R/W/H - This field is incremented whenever a successful write to a virtual EOIR or DIR register
                                                                 would have resulted in a virtual interrupt deactivation. That is:

                                                                 * A virtual write to EOIR with a valid interrupt identifier that is not in the LPI range
                                                                 (i.e. \< 8192) when EOI mode is zero and no list register was found.

                                                                 * Or, a virtual write to DIR with a valid interrupt identifier that is not in the LPI
                                                                 range
                                                                 (i.e. \< 8192) when EOI mode is one and no list register was found.

                                                                 This allows software to manage more active interrupts than there are implemented list
                                                                 registers. */
		uint64_t reserved_14_26              : 13;
		uint64_t tsei                        : 1;  /**< R/W - Trap all locally generated SEIs.
                                                                 This bit allows the hypervisor to intercept locally generated SEIs that would
                                                                 otherwise be taken by a guest operating system at non-secure EL1.
                                                                 0 = Locally generated SEIs do not cause a trap to EL2.
                                                                 1 = Locally generated SEIs trap to EL2.

                                                                 Virtual SEIs caused by writes to CIM()_ICH_VSEIR_EL2 are unaffected
                                                                 by this bit.

                                                                 This bit is reserved when CIM()_ICH_VTR_EL2[SEIS] is zero. */
		uint64_t tall1                       : 1;  /**< R/W - Trap all non-secure EL1 accesses to CIM()_ICC_* system registers for group 1
                                                                 interrupts.
                                                                 0 = Non-secure EL1 accesses to CIM()_ICC_* registers for group 1 interrupts proceed
                                                                 as normal.
                                                                 1 = Any non-secure EL1 accesses to CIM()_ICC_* registers for group 1 interrupts trap
                                                                 to EL2. */
		uint64_t tall0                       : 1;  /**< R/W - Trap all non-secure EL1 accesses to CIM()_ICC_* system registers for group 0
                                                                 interrupts.
                                                                 0 = Non-secure EL1 accesses to CIM()_ICC_* registers for group 0 interrupts proceed
                                                                 as normal.
                                                                 1 = Any non-secure EL1 accesses to CIM()_ICC_* registers for group 0 interrupts trap
                                                                 to EL2. */
		uint64_t tc                          : 1;  /**< R/W - Trap all non-secure EL1 accesses to system register common to group 0 and group 1.
                                                                 0 = Non-secure EL1 accesses to common registers proceed as normal.
                                                                 1 = Any non-secure EL1 access to common registers trap to EL2.

                                                                 Affects accesses to CIM()_ICC_SGI0R_EL1, CIM()_ICC_SGI1R_EL1,
                                                                 CIM()_ICC_ASGI1R_EL1,
                                                                 CIM()_ICC_CTLR_EL1, CIM()_ICC_DIR_EL1, CIM()_ICC_PMR_EL1 and
                                                                 CIM()_ICC_RPR_EL1. */
		uint64_t vare                        : 1;  /**< R/W - Virtual ARE.
                                                                 0 = The guest operating system does not use affinity routing and expects a source CPU ID
                                                                 for SGIs. The guest operating system does not support LPIs and software
                                                                 must ensure that no LPIs are presented to the guest using either the list registers or
                                                                 from the distributor.
                                                                 1 = The guest operating system uses affinity routing.

                                                                 This bit has no hardware effect. */
		uint64_t reserved_8_8                : 1;
		uint64_t vgrp1die                    : 1;  /**< R/W - VM Disable group 1 interrupt enable.
                                                                 Enables the signaling of a maintenance interrupt while signaling of group 1 interrupts
                                                                 from
                                                                 the virtual CPU interface to the connected virtual machine is disabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while CIM()_ICH_VMCR_EL2[VENG1]==0. */
		uint64_t vgrp1eie                    : 1;  /**< R/W - VM Enable group 1 interrupt enable.
                                                                 Enables the signaling of a maintenance interrupt while signaling of group 1 interrupts
                                                                 from
                                                                 the virtual CPU interface to the connected virtual machine is enabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while CIM()_ICH_VMCR_EL2[VENG1]==1. */
		uint64_t vgrp0die                    : 1;  /**< R/W - VM Disable group 0 interrupt enable.
                                                                 Enables the signaling of a maintenance interrupt while signaling of group 0 interrupts
                                                                 from
                                                                 the virtual CPU interface to the connected virtual machine is disabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while CIM()_ICH_VMCR_EL2[VENG0]==0. */
		uint64_t vgrp0eie                    : 1;  /**< R/W - VM Enable group 0 interrupt enable.
                                                                 Enables the signaling of a maintenance interrupt while signaling of group 0 interrupts
                                                                 from
                                                                 the virtual CPU interface to the connected virtual machine is enabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while CIM()_ICH_VMCR_EL2[VENG0]==1. */
		uint64_t npie                        : 1;  /**< R/W - No pending interrupt enable. Enables the signaling of a maintenance interrupt while
                                                                 no pending interrupts are present in the list registers;
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while the list registers contain no interrupts
                                                                 in the pending state. */
		uint64_t lrenpie                     : 1;  /**< R/W - List register entry not present interrupt enable. Enables the signaling of a maintenance
                                                                 interrupt while the virtual CPU interface does not have a corresponding valid list
                                                                 register
                                                                 entry for an EOI request:
                                                                   0 = Maintenance interrupt disabled.
                                                                   1 = A maintenance interrupt is asserted while the EOICount field is not 0.

                                                                 Unlike in GICv2, no maintenance interrupt is generated for an EOI that specifies an ID
                                                                 corresponding to the highest priority virtual LPI sent from the distributor. */
		uint64_t uie                         : 1;  /**< R/W - Underflow interrupt enable. Enables the signaling of a maintenance interrupt when the
                                                                 List registers are empty, or hold only one valid entry:
                                                                   0 = Maintenance interrupt disabled.
                                                                   1 = A maintenance interrupt is asserted if none, or only one, of the list register
                                                                   entries is marked as a valid interrupt. */
		uint64_t en                          : 1;  /**< R/W - Enable. Global enable bit for the virtual CPU interface:
                                                                   0 = Virtual CPU interface operation disabled.
                                                                   1 = Virtual CPU interface operation enabled.

                                                                 When this field is set to 0:

                                                                   1. The virtual CPU interface does not signal any maintenance interrupts.

                                                                   2. The virtual CPU interface does not signal any virtual interrupts (including virtual
                                                                 system errors).

                                                                   3. virtual access to an interrupt acknowledge register returns a spurious interrupt ID. */
#else
		uint64_t en                          : 1;
		uint64_t uie                         : 1;
		uint64_t lrenpie                     : 1;
		uint64_t npie                        : 1;
		uint64_t vgrp0eie                    : 1;
		uint64_t vgrp0die                    : 1;
		uint64_t vgrp1eie                    : 1;
		uint64_t vgrp1die                    : 1;
		uint64_t reserved_8_8                : 1;
		uint64_t vare                        : 1;
		uint64_t tc                          : 1;
		uint64_t tall0                       : 1;
		uint64_t tall1                       : 1;
		uint64_t tsei                        : 1;
		uint64_t reserved_14_26              : 13;
		uint64_t eoicount                    : 5;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_ich_hcr_el2_s      cn88xx; */
	/* struct bdk_cimx_ich_hcr_el2_s      cn88xxp1; */
} bdk_cimx_ich_hcr_el2_t;

static inline uint64_t BDK_CIMX_ICH_HCR_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_HCR_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000732C0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_HCR_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_HCR_EL2(...) bdk_cimx_ich_hcr_el2_t
#define bustype_BDK_CIMX_ICH_HCR_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_HCR_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_HCR_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_HCR_EL2(...) "CIMX_ICH_HCR_EL2"


/**
 * NCB - cim#_ich_lr#_el2
 *
 * Provides interrupt context information for the virtual CPU interface.
 * The number of list registers provided is specified by CIM()_ICH_VTR_EL2[LISTREGS].
 */
typedef union bdk_cimx_ich_lrx_el2 {
	uint64_t u;
	struct bdk_cimx_ich_lrx_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t state                       : 2;  /**< R/W/H - The state of the interrupt:
                                                                 0x0 = Invalid.
                                                                 0x1 = Pending.
                                                                 0x2 = Active.
                                                                 0x3 = Reserved.

                                                                 The GIC updates these state bits as virtual interrupts proceed through the interrupt
                                                                 life cycle. Entries in the invalid state are ignored, except for the purpose of
                                                                 generating virtual maintenance interrupts.

                                                                 For hardware interrupts, the pending and active state is held in the physical
                                                                 distributor rather than the virtual
                                                                 CPU interface. A hypervisor must only use the pending and active state for software
                                                                 originated interrupts, which are typically associated with virtual devices, or SGIs. */
		uint64_t hw                          : 1;  /**< R/W - Indicates whether this virtual interrupt is a hardware interrupt, meaning that it
                                                                 corresponds to a physical interrupt.
                                                                 Deactivation of the virtual interrupt also causes the deactivation of the physical
                                                                 interrupt with the ID that the PHYSID field indicates.
                                                                 0 = The interrupt is triggered entirely in software. No notification is sent to the
                                                                     Distributor when the virtual interrupt is deactivated.
                                                                 1 = A hardware interrupt. A deactivate interrupt request is sent to the distributor
                                                                     when the virtual interrupt is deactivated, using bits [19:10], the PHYSID,
                                                                     to indicate the physical interrupt ID.

                                                                 If CIM()_ICC_CTLR_EL1[EOIMODE] (== CIM()_ICH_VMCR_EL2[VEOIM] when accessed
                                                                 in virtual mode) == 0, this request corresponds to a write to the WriteICV_EOIR0_EL1
                                                                 or WriteICV_EOIR1_EL1, otherwise it corresponds to a write to the WriteICV_DIR_EL1.

                                                                 It is a programming error if the hypervisor sets this bit to one and uses the
                                                                 active and pending state. If this happens, interrupt corresponding to physical ID will
                                                                 be deactivated twice and system behavior might be unpredictable. */
		uint64_t grp                         : 1;  /**< R/W - Indicates whether this virtual interrupt is a group 1 virtual interrupt.

                                                                 0 = This is a group 0 virtual interrupt. CIM()_ICH_VMCR_EL2[VFIQEN]
                                                                     determines whether it is signaled as a virtual IRQ or as a virtual FIQ,
                                                                     and CIM()_ICC_IGRPEN0_EL1[EN] (== CIM()_ICH_VMCR_EL2[VENG0]
                                                                     when accessed in virtual mode) enables signaling of this interrupt
                                                                     to the virtual machine.

                                                                 1 = This is a group 1 virtual interrupt, signaled as a virtual IRQ.
                                                                     CIM()_ICC_IGRPEN1_EL1_S/NS[EN] (== CIM()_ICH_VMCR_EL2[VENG1]
                                                                     when accessed in virtual mode) enables the signaling of this interrupt
                                                                     to the virtual machine.

                                                                 The CIM()_ICH_VMCR_EL2[VCBPR] bit controls which BPR register is
                                                                 used to determine if a pending group 1 interrupt has sufficient priority to
                                                                 preempt current execution. */
		uint64_t reserved_56_59              : 4;
		uint64_t pri                         : 8;  /**< R/W - Priority. The priority of this interrupt.
                                                                 It is implementation defined how many bits are implemented, though at least five
                                                                 bits must be implemented. Unimplemented bits are RAZ and start from bit [48].
                                                                 Number of implemented bits determines how many CIM()_ICH_APRn registers exist.
                                                                 It is a programming error if the priority is set to the lowest implemented priority
                                                                 (i.e. the highest numeric value). Interrupts with this value can never assert
                                                                 an interrupt request as the value can never preempt and the value effectively means
                                                                 idle. */
		uint64_t reserved_42_47              : 6;
		uint64_t physid                      : 10; /**< R/W - Physical ID.
                                                                 The function of this field depends on the value of the HW bit as follows:

                                                                 0 = Bit [41]. EOI. It indicates whether this interrupt triggers a maintenance interrupt.
                                                                                 0 = No maintenance interrupt is asserted.
                                                                                 1 = A maintenance interrupt is asserted to signal EOI when the interrupt
                                                                                     state is invalid, which typically occurs when the interrupt is
                                                                                     deactivated.

                                                                 _ Bits [40:32]. Reserved.

                                                                 _ In GICv2, if the Physical ID specified an SGI, behavior was unpredictable. In
                                                                           GICv3, hardware deactivation of SGIs is fully supported.

                                                                 _ A hardware physical identifier is only required in list registers for
                                                                           interrupts that require an EOI or Deactivate. Hence, only 10 bits of
                                                                           physical ID are required, regardless of the number specified by
                                                                           CIM()_ICC_CTLR_EL1[IDBITS].

                                                                 1 = Field indicates the physical interrupt ID that the hypervisor forwards to the
                                                                 Distributor. */
		uint64_t virtid                      : 32; /**< R/W - Virtual ID.
                                                                 This ID is returned to the guest OS when the interrupt is acknowledged through the VM
                                                                 interrupt acknowledge register, ReadICV_IAR{0,1}_EL1.
                                                                 Each valid interrupt stored in the List registers must have a unique VirtualID for that
                                                                 virtual CPU interface.

                                                                 If the value of VirtualID is 1020-1023, behavior is unpredictable.

                                                                 When VARE is zero, software must ensure the correct Source CPU ID is provided in
                                                                 bits [12:10].

                                                                 Software must ensure there is only a single valid entry for a given Virtual ID.

                                                                 It is implementation defined how many bits are implemented, though at least 16
                                                                 bits must be implemented; unimplemented bits are RAZ. The number of implemented
                                                                 bits can be discovered from CIM()_ICH_VTR_EL2[IDBITS]. */
#else
		uint64_t virtid                      : 32;
		uint64_t physid                      : 10;
		uint64_t reserved_42_47              : 6;
		uint64_t pri                         : 8;
		uint64_t reserved_56_59              : 4;
		uint64_t grp                         : 1;
		uint64_t hw                          : 1;
		uint64_t state                       : 2;
#endif
	} s;
	/* struct bdk_cimx_ich_lrx_el2_s      cn88xx; */
	/* struct bdk_cimx_ich_lrx_el2_s      cn88xxp1; */
} bdk_cimx_ich_lrx_el2_t;

static inline uint64_t BDK_CIMX_ICH_LRX_EL2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_LRX_EL2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 15)))
		return 0x000087B000073300ull + (param1 & 63) * 0x80000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_CIMX_ICH_LRX_EL2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_LRX_EL2(...) bdk_cimx_ich_lrx_el2_t
#define bustype_BDK_CIMX_ICH_LRX_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_LRX_EL2(p1,p2) (p1)
#define arguments_BDK_CIMX_ICH_LRX_EL2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_CIMX_ICH_LRX_EL2(...) "CIMX_ICH_LRX_EL2"


/**
 * NCB - cim#_ich_misr_el2
 *
 * This register is used to determine the status of maintenance interrupts.
 *
 */
typedef union bdk_cimx_ich_misr_el2 {
	uint64_t u;
	struct bdk_cimx_ich_misr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t vgrp1d                      : 1;  /**< RO/H - Disabled group 1 maintenance interrupt. Asserted whenever CIM()_ICH_HCR_EL2[VGRP1DIE]
                                                                 is set and CIM()_ICH_VMCR_EL2[VENG1]==0. */
		uint64_t vgrp1e                      : 1;  /**< RO/H - Enabled group 1 maintenance interrupt. Asserted whenever CIM()_ICH_HCR_EL2[VGRP1EIE]
                                                                 is set and CIM()_ICH_VMCR_EL2[VENG1]==1. */
		uint64_t vgrp0d                      : 1;  /**< RO/H - Disabled group 0 maintenance interrupt. Asserted whenever CIM()_ICH_HCR_EL2[VGRP0DIE]
                                                                 is set and CIM()_ICH_VMCR_EL2[VENG0]==0. */
		uint64_t vgrp0e                      : 1;  /**< RO/H - Enabled group 0 maintenance interrupt. Asserted whenever CIM()_ICH_HCR_EL2[VGRP0EIE]
                                                                 is set and CIM()_ICH_VMCR_EL2[VENG0]==1. */
		uint64_t np                          : 1;  /**< RO/H - No pending maintenance interrupt. Asserted whenever CIM()_ICH_HCR_EL2[NPIE]==1 and no
                                                                 list register is in pending state.
                                                                 A list register is in the pending state only if CIM()_ICH_LRn_EL2[STATE]
                                                                 is pending. The state pending and active is not included. */
		uint64_t lrenp                       : 1;  /**< RO/H - List register entry not present maintenance interrupt. Asserted whenever
                                                                 CIM()_ICH_HCR_EL2[LRENPIE]==1 and CIM()_ICH_HCR_EL2[EOICOUNT] is non-zero. */
		uint64_t u                           : 1;  /**< RO/H - Underflow maintenance interrupt. Asserted whenever CIM()_ICH_HCR_EL2[UIE] is set and
                                                                 if none, or only one, of the list register entries are marked as a valid interrupt
                                                                 (corresponding CIM()_ICH_LR()_EL2[STATE] != 0x0). */
		uint64_t eoi                         : 1;  /**< RO/H - EOI maintenance interrupt. Asserted whenever at least one list register is asserting an
                                                                 EOI Interrupt. At least one bit in CIM()_ICH_EISR_EL2==1. */
#else
		uint64_t eoi                         : 1;
		uint64_t u                           : 1;
		uint64_t lrenp                       : 1;
		uint64_t np                          : 1;
		uint64_t vgrp0e                      : 1;
		uint64_t vgrp0d                      : 1;
		uint64_t vgrp1e                      : 1;
		uint64_t vgrp1d                      : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_cimx_ich_misr_el2_s     cn88xx; */
	/* struct bdk_cimx_ich_misr_el2_s     cn88xxp1; */
} bdk_cimx_ich_misr_el2_t;

static inline uint64_t BDK_CIMX_ICH_MISR_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_MISR_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000732D0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_MISR_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_MISR_EL2(...) bdk_cimx_ich_misr_el2_t
#define bustype_BDK_CIMX_ICH_MISR_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_MISR_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_MISR_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_MISR_EL2(...) "CIMX_ICH_MISR_EL2"


/**
 * NCB - cim#_ich_vmcr_el2
 *
 * This register allows the hypervisor to save and restore the virtual machine view of the GIC state.
 *
 */
typedef union bdk_cimx_ich_vmcr_el2 {
	uint64_t u;
	struct bdk_cimx_ich_vmcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t vpmr                        : 8;  /**< R/W - Virtual priority mask. Visible to the guest as CIM()_ICC_PMR_EL1 */
		uint64_t vbpr0                       : 3;  /**< R/W - Virtual BPR0. Visible to the guest as CIM()_ICC_BPR0_EL1 */
		uint64_t vbpr1                       : 3;  /**< R/W - Virtual BPR1. Visible to the guest as CIM()_ICC_BPR1_EL1.
                                                                 This field is always accessible to EL2 accesses, regardless of the setting of the
                                                                 VCBPR field. */
		uint64_t reserved_10_17              : 8;
		uint64_t veoim                       : 1;  /**< R/W/H - Virtual EOI mode. Visible to the guest as CIM()_ICC_CTLR_EL1[EOIMODE]
                                                                 INTERNAL: An implementation might choose to make this field RAO/WI. */
		uint64_t reserved_6_8                : 3;
		uint64_t vensei                      : 1;  /**< RO/H - Virtual SEI enable. Visible to the guest as CIM()_ICC_SEIEN_EL1[EN].
                                                                 0 = Virtual SEIs will not be reported to non-secure EL1 including any valid SEI in
                                                                 CIM()_ICH_VSEIR_EL2.
                                                                 1 = Virtual SEIs will be reported to non-secure EL1 including any valid SEI in
                                                                 CIM()_ICH_VSEIR_EL2.

                                                                 If CIM()_ICH_VTR_EL2[SEIS] is one, this bit also covers reporting of SEIs locally
                                                                 generated by the CPU interface logic.

                                                                 In CNXXXX, this bit is always 0 as SEIs are not implemented. */
		uint64_t vcbpr                       : 1;  /**< R/W/H - Visible to the guest as CIM()_ICC_CTLR_EL1[CBPR].
                                                                 0 = Virtual reads and writes to CIM()_ICC_BPR1_EL1 access
                                                                 CIM()_ICH_VMCR_EL2[VBPR1].
                                                                 1 = Virtual reads of CIM()_ICC_BPR1_EL1 return (CIM()_ICH_VMCR_EL2[VBPR0] + 1,
                                                                 saturated to 0x7) and virtual writes to CIM()_ICC_BPR1_EL1 are ignored.

                                                                 This bit has no effect on accesses to GICV_ABPR but does affect preemption. */
		uint64_t vfiqen                      : 1;  /**< RO/H - Virtual group IRQ enable:
                                                                 0 = Signal virtual group 0 with vIRQ.
                                                                 1 = Signal virtual group 0 with vFIQ.

                                                                 In CNXXXX, this bit is always 1 as the non-secure copy of CIM()_ICC_SRE_EL1[SRE]
                                                                 is always one. */
		uint64_t vackctl                     : 1;  /**< RO/H - Legacy bit from GICv2 does not affect hardware operation.
                                                                 In CNXXXX, this bit is always 0 because the non-secure copy of CIM()_ICC_SRE_EL1[SRE]
                                                                 is always one. */
		uint64_t veng1                       : 1;  /**< R/W/H - Virtual group 1 interrupt enable. Visible to the guest as CIM()_ICC_IGRPEN1_EL1_S/NS[EN]. */
		uint64_t veng0                       : 1;  /**< R/W/H - Virtual group 0 interrupt enable. Visible to the guest as CIM()_ICC_IGRPEN0_EL1[EN]. */
#else
		uint64_t veng0                       : 1;
		uint64_t veng1                       : 1;
		uint64_t vackctl                     : 1;
		uint64_t vfiqen                      : 1;
		uint64_t vcbpr                       : 1;
		uint64_t vensei                      : 1;
		uint64_t reserved_6_8                : 3;
		uint64_t veoim                       : 1;
		uint64_t reserved_10_17              : 8;
		uint64_t vbpr1                       : 3;
		uint64_t vbpr0                       : 3;
		uint64_t vpmr                        : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_ich_vmcr_el2_s     cn88xx; */
	/* struct bdk_cimx_ich_vmcr_el2_s     cn88xxp1; */
} bdk_cimx_ich_vmcr_el2_t;

static inline uint64_t BDK_CIMX_ICH_VMCR_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_VMCR_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000732F8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_VMCR_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_VMCR_EL2(...) bdk_cimx_ich_vmcr_el2_t
#define bustype_BDK_CIMX_ICH_VMCR_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_VMCR_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_VMCR_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_VMCR_EL2(...) "CIMX_ICH_VMCR_EL2"


/**
 * NCB - cim#_ich_vtr_el2
 *
 * This register describes the number of implemented virtual priority bits and list registers.
 *
 */
typedef union bdk_cimx_ich_vtr_el2 {
	uint64_t u;
	struct bdk_cimx_ich_vtr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pribits                     : 3;  /**< RO/H - The number of priority bits implemented, minus one.
                                                                 In CNXXXX, this field is always 4 as only 32 priorities are implemented. */
		uint64_t prebits                     : 3;  /**< RO/H - The number of preemption bits implemented, minus one.
                                                                 In CNXXXX, this field is always 4 as preemption is allowed on same granularity as
                                                                 priority.
                                                                 The value of this field must be less than or equal to PRIbits (above).
                                                                 This field determines the minimum value of CIM()_ICH_VMCR_EL2[VBPR0]. */
		uint64_t idbits                      : 3;  /**< RO/H - The number of virtual interrupt identifier bits supported:
                                                                 0x0 = 16 bits.
                                                                 0x1 = 24 bits.
                                                                 else = Reserved.

                                                                 In CNXXXX, this field is always 0x1 as 24-bit interrupt IDs are implemented. */
		uint64_t seis                        : 1;  /**< RO/H - Read-only and writes are ignored.
                                                                 0 = The virtual CPU interface logic does not support local generation of SEIs by the CPU
                                                                 interface.
                                                                 1 = The virtual CPU interface logic supports local generation of SEIs by the CPU
                                                                 interface.

                                                                 Virtual system errors may still be generated by writing to CIM()_ICH_VSEIR_EL2
                                                                 regardless of the value of this field.
                                                                 In CNXXXX, this bit is always 0 as SEIs are not implemented. */
		uint64_t a3v                         : 1;  /**< RO/H - Affinity 3 support:
                                                                 0 = The CPU interface logic does not support non-zero values of affinity 3 in SGI
                                                                 generation system registers.
                                                                 1 = The CPU interface logic supports non-zero values of affinity 3 in SGI generation
                                                                 system registers.

                                                                 In CNXXXX, this bit is always 0 as affinity3 is always 0. */
		uint64_t reserved_5_20               : 16;
		uint64_t listregs                    : 5;  /**< RO/H - The number of implemented list registers, minus one.
                                                                 For example, a value of 0xf indicates that the maximum of 16 list registers are
                                                                 implemented.
                                                                 In CNXXXX, this field is always 0xf as 16 list registers are implemented. */
#else
		uint64_t listregs                    : 5;
		uint64_t reserved_5_20               : 16;
		uint64_t a3v                         : 1;
		uint64_t seis                        : 1;
		uint64_t idbits                      : 3;
		uint64_t prebits                     : 3;
		uint64_t pribits                     : 3;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_cimx_ich_vtr_el2_s      cn88xx; */
	/* struct bdk_cimx_ich_vtr_el2_s      cn88xxp1; */
} bdk_cimx_ich_vtr_el2_t;

static inline uint64_t BDK_CIMX_ICH_VTR_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CIMX_ICH_VTR_EL2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087B0000732C8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CIMX_ICH_VTR_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CIMX_ICH_VTR_EL2(...) bdk_cimx_ich_vtr_el2_t
#define bustype_BDK_CIMX_ICH_VTR_EL2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_CIMX_ICH_VTR_EL2(p1) (p1)
#define arguments_BDK_CIMX_ICH_VTR_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_CIMX_ICH_VTR_EL2(...) "CIMX_ICH_VTR_EL2"

#endif /* __BDK_CSRS_CIM__ */
