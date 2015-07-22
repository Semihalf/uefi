#ifndef __BDK_CSRS_AP__
#define __BDK_CSRS_AP__
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
 * Cavium AP.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * SYSREG - ap_actlr_el#
 *
 * These registers are implementation defined for implementation specific control functionality
 * while executing at the associated execution level, or, in the case of ACTLR_EL1, while
 * executing at EL0.
 */
typedef union bdk_ap_actlr_elx {
	uint64_t u;
	struct bdk_ap_actlr_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_actlr_elx_s          cn88xx; */
	/* struct bdk_ap_actlr_elx_s          cn88xxp1; */
} bdk_ap_actlr_elx_t;

static inline uint64_t BDK_AP_ACTLR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ACTLR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x0000030001000100ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_ACTLR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ACTLR_ELX(...) bdk_ap_actlr_elx_t
#define bustype_BDK_AP_ACTLR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ACTLR_ELX(p1) (p1)
#define arguments_BDK_AP_ACTLR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ACTLR_ELX(...) "AP_ACTLR_ELX"


/**
 * SYSREG - ap_afsr#_el#
 *
 * Provides additional implementation defined fault status
 * information for exceptions taken to EL*.
 */
typedef union bdk_ap_afsrx_elx {
	uint32_t u;
	struct bdk_ap_afsrx_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_afsrx_elx_s          cn88xx; */
	/* struct bdk_ap_afsrx_elx_s          cn88xxp1; */
} bdk_ap_afsrx_elx_t;

static inline uint64_t BDK_AP_AFSRX_ELX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_AFSRX_ELX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && (((param2 >= 1) && (param2 <= 3))))
		return 0x0000030005010000ull + (param1 & 1) * 0x100ull + (param2 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_AFSRX_ELX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_AP_AFSRX_ELX(...) bdk_ap_afsrx_elx_t
#define bustype_BDK_AP_AFSRX_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_AFSRX_ELX(p1,p2) (p1)
#define arguments_BDK_AP_AFSRX_ELX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_AP_AFSRX_ELX(...) "AP_AFSRX_ELX"


/**
 * SYSREG - ap_afsr#_el12
 *
 * Alias of AFSR(n)_EL1 when accessed from EL2 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_afsrx_el12 {
	uint32_t u;
	struct bdk_ap_afsrx_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_afsrx_el12_s         cn88xx; */
	/* struct bdk_ap_afsrx_el12_s         cn88xxp1; */
} bdk_ap_afsrx_el12_t;

static inline uint64_t BDK_AP_AFSRX_EL12(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_AFSRX_EL12(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000030505010000ull + (param1 & 1) * 0x100ull;
	csr_fatal("BDK_AP_AFSRX_EL12", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_AFSRX_EL12(...) bdk_ap_afsrx_el12_t
#define bustype_BDK_AP_AFSRX_EL12(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_AFSRX_EL12(p1) (p1)
#define arguments_BDK_AP_AFSRX_EL12(p1) (p1),-1,-1,-1
#define basename_BDK_AP_AFSRX_EL12(...) "AP_AFSRX_EL12"


/**
 * SYSREG - ap_aidr_el1
 *
 * Provides implementation defined identification information.
 *
 */
typedef union bdk_ap_aidr_el1 {
	uint64_t u;
	struct bdk_ap_aidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_aidr_el1_s           cn88xx; */
	/* struct bdk_ap_aidr_el1_s           cn88xxp1; */
} bdk_ap_aidr_el1_t;

#define BDK_AP_AIDR_EL1 BDK_AP_AIDR_EL1_FUNC()
static inline uint64_t BDK_AP_AIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_AIDR_EL1_FUNC(void)
{
	return 0x0000030100000700ull;
}
#define typedef_BDK_AP_AIDR_EL1 bdk_ap_aidr_el1_t
#define bustype_BDK_AP_AIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_AIDR_EL1 0
#define arguments_BDK_AP_AIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_AIDR_EL1 "AP_AIDR_EL1"


/**
 * SYSREG - ap_amair_el#
 *
 * Provides implementation defined memory attributes for the
 * memory regions specified by MAIR_EL*.
 */
typedef union bdk_ap_amair_elx {
	uint64_t u;
	struct bdk_ap_amair_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_amair_elx_s          cn88xx; */
	/* struct bdk_ap_amair_elx_s          cn88xxp1; */
} bdk_ap_amair_elx_t;

static inline uint64_t BDK_AP_AMAIR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_AMAIR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x000003000A030000ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_AMAIR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_AMAIR_ELX(...) bdk_ap_amair_elx_t
#define bustype_BDK_AP_AMAIR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_AMAIR_ELX(p1) (p1)
#define arguments_BDK_AP_AMAIR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_AMAIR_ELX(...) "AP_AMAIR_ELX"


/**
 * SYSREG - ap_amair_el12
 *
 * Alias of AMAIR_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_amair_el12 {
	uint64_t u;
	struct bdk_ap_amair_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_amair_el12_s         cn88xx; */
	/* struct bdk_ap_amair_el12_s         cn88xxp1; */
} bdk_ap_amair_el12_t;

#define BDK_AP_AMAIR_EL12 BDK_AP_AMAIR_EL12_FUNC()
static inline uint64_t BDK_AP_AMAIR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_AMAIR_EL12_FUNC(void)
{
	return 0x000003050A030000ull;
}
#define typedef_BDK_AP_AMAIR_EL12 bdk_ap_amair_el12_t
#define bustype_BDK_AP_AMAIR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_AMAIR_EL12 0
#define arguments_BDK_AP_AMAIR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_AMAIR_EL12 "AP_AMAIR_EL12"


/**
 * SYSREG - ap_ccsidr_el1
 *
 * This register provides information about the architecture of the currently selected
 * cache.
 */
typedef union bdk_ap_ccsidr_el1 {
	uint32_t u;
	struct bdk_ap_ccsidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t wt                          : 1;  /**< RO - Indicates whether the selected cache level supports write-through.
                                                                 0 = Write-through not supported.
                                                                 1 = Write-through supported.

                                                                 For CNXXXX does not apply as hardware managed coherence. */
		uint32_t wb                          : 1;  /**< RO - Indicates whether the selected cache level supports write-back.
                                                                 0 = Write-back not supported.
                                                                 1 = Write-back supported.

                                                                 For CNXXXX does not apply as hardware managed coherence. */
		uint32_t ra                          : 1;  /**< RO - Indicates whether the selected cache level supports read-allocation.
                                                                 0 = Read-allocation not supported.
                                                                 1 = Read-allocation supported.

                                                                 For CNXXXX does not apply as hardware managed coherence. */
		uint32_t wa                          : 1;  /**< RO - Indicates whether the selected cache level supports write-allocation.
                                                                 0 = Write-allocation not supported.
                                                                 1 = Write-allocation supported.

                                                                 For CNXXXX does not apply as hardware managed coherence. */
		uint32_t numsets                     : 15; /**< RO - Number of sets in cache minus 1, therefore a value of 0
                                                                 indicates 1 set in the cache. The number of sets does not have
                                                                 to be a power of 2.

                                                                 For CNXXXX L1D (AP_CSSELR_EL1[LEVEL] = 0x0, AP_CSSELR_EL1[IND] = 0), is 0x7.
                                                                 For CNXXXX L1I (AP_CSSELR_EL1[LEVEL] = 0x0, AP_CSSELR_EL1[IND] = 1), is 0x15.
                                                                 For CNXXXX L2 (AP_CSSELR_EL1[LEVEL] = 0x1, AP_CSSELR_EL1[IND] = 0), is 0x8191. */
		uint32_t associativity               : 10; /**< RO - Associativity of cache minus 1, therefore a value of 0 indicates
                                                                 an associativity of 1. The associativity does not have to be a
                                                                 power of 2.

                                                                 For CNXXXX L1D (AP_CSSELR_EL1[LEVEL] = 0x0, AP_CSSELR_EL1[IND] = 0), is 0x31.
                                                                 For CNXXXX L1I (AP_CSSELR_EL1[LEVEL] = 0x0, AP_CSSELR_EL1[IND] = 1), is 0x38.
                                                                 For CNXXXX L2 (AP_CSSELR_EL1[LEVEL] = 0x1, AP_CSSELR_EL1[IND] = 0), is 0x15. */
		uint32_t linesize                    : 3;  /**< RO - Cache-line size, in (Log2(Number of bytes in cache line)) - 4.

                                                                 For CNXXXX, 128 bytes. */
#else
		uint32_t linesize                    : 3;
		uint32_t associativity               : 10;
		uint32_t numsets                     : 15;
		uint32_t wa                          : 1;
		uint32_t ra                          : 1;
		uint32_t wb                          : 1;
		uint32_t wt                          : 1;
#endif
	} s;
	/* struct bdk_ap_ccsidr_el1_s         cn88xx; */
	/* struct bdk_ap_ccsidr_el1_s         cn88xxp1; */
} bdk_ap_ccsidr_el1_t;

#define BDK_AP_CCSIDR_EL1 BDK_AP_CCSIDR_EL1_FUNC()
static inline uint64_t BDK_AP_CCSIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CCSIDR_EL1_FUNC(void)
{
	return 0x0000030100000000ull;
}
#define typedef_BDK_AP_CCSIDR_EL1 bdk_ap_ccsidr_el1_t
#define bustype_BDK_AP_CCSIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CCSIDR_EL1 0
#define arguments_BDK_AP_CCSIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CCSIDR_EL1 "AP_CCSIDR_EL1"


/**
 * SYSREG - ap_clidr_el1
 *
 * This register identifies the type of cache, or caches, implemented at each level, up
 * to a maximum of seven levels. Also identifies the Level of Coherence (LoC) and Level
 * of Unification (LoU) for the cache hierarchy.
 */
typedef union bdk_ap_clidr_el1 {
	uint32_t u;
	struct bdk_ap_clidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t louu                        : 3;  /**< RO - Level of unification uniprocessor for the cache hierarchy. */
		uint32_t loc                         : 3;  /**< RO - Level of coherence for the cache hierarchy.

                                                                 For CN88XX, 0x1 for pass 1, 0x0 for pass 2 and subsequent chips. */
		uint32_t louis                       : 3;  /**< RO - Level of unification inner shareable for the cache hierarchy. */
		uint32_t ctype7                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 All other values are reserved.

                                                                 For CNXXXX, no L7 cache. */
		uint32_t ctype6                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 For CNXXXX, no L6 cache. */
		uint32_t ctype5                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 For CNXXXX, no L5 cache. */
		uint32_t ctype4                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 For CNXXXX, no L4 cache. */
		uint32_t ctype3                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 For CNXXXX, no L3 cache. */
		uint32_t ctype2                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 For CNXXXX, L2 cache is unified. */
		uint32_t ctype1                      : 3;  /**< RO - Cache type fields. Indicate the type of cache implemented at
                                                                     each level, from Level 1 up to a maximum of seven levels of
                                                                     cache hierarchy.
                                                                 0x0 = No cache.
                                                                 0x1 = Instruction cache only.
                                                                 0x2 = Data cache only.
                                                                 0x3 = Separate instruction and data caches.
                                                                 0x4 = Unified cache.

                                                                 For CNXXXX, L1 Dcache and Icache are independent. */
#else
		uint32_t ctype1                      : 3;
		uint32_t ctype2                      : 3;
		uint32_t ctype3                      : 3;
		uint32_t ctype4                      : 3;
		uint32_t ctype5                      : 3;
		uint32_t ctype6                      : 3;
		uint32_t ctype7                      : 3;
		uint32_t louis                       : 3;
		uint32_t loc                         : 3;
		uint32_t louu                        : 3;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_ap_clidr_el1_s          cn88xx; */
	/* struct bdk_ap_clidr_el1_s          cn88xxp1; */
} bdk_ap_clidr_el1_t;

#define BDK_AP_CLIDR_EL1 BDK_AP_CLIDR_EL1_FUNC()
static inline uint64_t BDK_AP_CLIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CLIDR_EL1_FUNC(void)
{
	return 0x0000030100000100ull;
}
#define typedef_BDK_AP_CLIDR_EL1 bdk_ap_clidr_el1_t
#define bustype_BDK_AP_CLIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CLIDR_EL1 0
#define arguments_BDK_AP_CLIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CLIDR_EL1 "AP_CLIDR_EL1"


/**
 * SYSREG - ap_cntfrq_el0
 *
 * Holds the clock frequency of the system counter.
 *
 */
typedef union bdk_ap_cntfrq_el0 {
	uint32_t u;
	struct bdk_ap_cntfrq_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Clock frequency. Indicates the system counter clock frequency,
                                                                 in Hz. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_cntfrq_el0_s         cn88xx; */
	/* struct bdk_ap_cntfrq_el0_s         cn88xxp1; */
} bdk_ap_cntfrq_el0_t;

#define BDK_AP_CNTFRQ_EL0 BDK_AP_CNTFRQ_EL0_FUNC()
static inline uint64_t BDK_AP_CNTFRQ_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTFRQ_EL0_FUNC(void)
{
	return 0x000003030E000000ull;
}
#define typedef_BDK_AP_CNTFRQ_EL0 bdk_ap_cntfrq_el0_t
#define bustype_BDK_AP_CNTFRQ_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTFRQ_EL0 0
#define arguments_BDK_AP_CNTFRQ_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTFRQ_EL0 "AP_CNTFRQ_EL0"


/**
 * SYSREG - ap_cnthctl_el2
 *
 * Controls the generation of an event stream from the physical
 *     counter, and access from non-secure EL1 to the physical
 *     counter and the non-secure EL1 physical timer.
 *
 * This register is at the same select as AP_CNTHCTL_EL2_E2H and is used when E2H=0.
 */
typedef union bdk_ap_cnthctl_el2 {
	uint32_t u;
	struct bdk_ap_cnthctl_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t evnti                       : 4;  /**< R/W - Selects which bit (0 to 15) of the corresponding counter
                                                                 register ( AP_CNTPCT_EL0 or AP_CNTVCT_EL0) is the trigger for the
                                                                 event stream generated from that counter, when that stream is
                                                                 enabled. */
		uint32_t evntdir                     : 1;  /**< R/W - Controls which transition of the counter register ( AP_CNTPCT_EL0
                                                                     or AP_CNTVCT_EL0) trigger bit, defined by EVNTI, generates an
                                                                     event when the event stream is enabled:
                                                                 0 = A 0 to 1 transition of the trigger bit triggers an event.
                                                                 1 = A 1 to 0 transition of the trigger bit triggers an event. */
		uint32_t evnten                      : 1;  /**< R/W - Enables the generation of an event stream from the
                                                                     corresponding counter:
                                                                 0 = Disables the event stream.
                                                                 1 = Enables the event stream. */
		uint32_t el1pcen                     : 1;  /**< R/W - Controls whether the physical timer registers are accessible
                                                                     from non-secure EL1 and EL0 modes:
                                                                 If EL3 is implemented and EL2 is not implemented, this bit is
                                                                     treated as if it is 1 for all purposes other than reading the
                                                                     register.
                                                                 0 = The AP_CNTP_CVAL_EL0, AP_CNTP_TVAL_EL0, and AP_CNTP_CTL_EL0 registers
                                                                     are not accessible from non-secure EL1 and EL0 modes.
                                                                 1 = The AP_CNTP_CVAL_EL0, AP_CNTP_TVAL_EL0, and AP_CNTP_CTL_EL0 registers
                                                                     are accessible from non-secure EL1 and EL0 modes. */
		uint32_t el1pcten                    : 1;  /**< R/W - Controls whether the physical counter, AP_CNTPCT_EL0, is
                                                                     accessible from non-secure EL1 and EL0 modes:
                                                                 If EL3 is implemented and EL2 is not implemented, this bit is
                                                                     treated as if it is 1 for all purposes other than reading the
                                                                     register.
                                                                 0 = The AP_CNTPCT_EL0 register is not accessible from non-secure EL1
                                                                     and EL0 modes.
                                                                 1 = The AP_CNTPCT_EL0 register is accessible from non-secure EL1 and
                                                                     EL0 modes. */
#else
		uint32_t el1pcten                    : 1;
		uint32_t el1pcen                     : 1;
		uint32_t evnten                      : 1;
		uint32_t evntdir                     : 1;
		uint32_t evnti                       : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ap_cnthctl_el2_s        cn88xx; */
	/* struct bdk_ap_cnthctl_el2_s        cn88xxp1; */
} bdk_ap_cnthctl_el2_t;

#define BDK_AP_CNTHCTL_EL2 BDK_AP_CNTHCTL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHCTL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHCTL_EL2_FUNC(void)
{
	return 0x000003040E010000ull;
}
#define typedef_BDK_AP_CNTHCTL_EL2 bdk_ap_cnthctl_el2_t
#define bustype_BDK_AP_CNTHCTL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHCTL_EL2 0
#define arguments_BDK_AP_CNTHCTL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHCTL_EL2 "AP_CNTHCTL_EL2"


/**
 * SYSREG - ap_cnthctl_el2_e2h
 *
 * This register is at the same select as AP_CNTHCTL_EL2 and is used when E2H=1.
 *
 */
typedef union bdk_ap_cnthctl_el2_e2h {
	uint32_t u;
	struct bdk_ap_cnthctl_el2_e2h_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t el1pcen                     : 1;  /**< R/W - Controls whether physical timer register accessing instuctions
                                                                 are accessible from non-secure EL1 and EL0:
                                                                 0 = The following system register accessing instructions in AARCH64,
                                                                     and their equivalent instructions in AARCH32, are trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 0 and the instructions are executed at
                                                                     non-secure EL1, or non-secure EL0 unless trapped to EL1 as a
                                                                     result of controls in the AP_CNTKCTL_EL1
                                                                       Op0=3, op1=3, CRn=14, CRm=2, Op2=0   AP_CNTP_TVAL_EL0
                                                                       Op0=3, op1=3, CRn=14, CRm=2, Op2=1   AP_CNTP_CTL_EL0
                                                                       Op0=3, op1=3, CRn=14, CRm=2, Op2=2   AP_CNTP_CVAL_EL0
                                                                     This bit does not cause any instructions to be trapped to EL2
                                                                     when AP_HCR_EL2[TGE]==1.

                                                                 1 = This bit does not cause any instructions to be trapped to EL2. */
		uint32_t el1pten                     : 1;  /**< R/W - Controls whether the physical counter is accessible from non-secure
                                                                 EL1 and EL0.
                                                                 0 = The following system register accessing instructions in AARCH64,
                                                                     and their equivlent instructions in AARCH32, are trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 0 and the instructions are executed at non-secure
                                                                     EL1, or non-secure EL0 unless trapped to EL1 as a result of controls
                                                                     in AP_CNTKCTL_EL1.
                                                                       Op0=3, op1=3, CRn=14, CRm=0, Op2=1   AP_CNTPCT_EL0
                                                                     This bit does not cause any instructions to be trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 1.

                                                                 1 = This bit does not cause any instructions to be trapped to EL2. */
		uint32_t el0pten                     : 1;  /**< R/W - Controls whether the physical timer register accessing instructions are
                                                                 accessible from non-secure EL0 when AP_HCR_EL2[TGE]==1.
                                                                 0 = The following system register accessing instructions in AARCH64,
                                                                     and their equivlent instructions in AARCH32, are trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 1 and the instructions are executed at non-secure
                                                                     EL0.
                                                                       Op0=3, op1=3, CRn=14, CRm=2, Op2=0   AP_CNTP_TVAL_EL0
                                                                       Op0=3, op1=3, CRn=14, CRm=2, Op2=1   AP_CNTP_CTL_EL0
                                                                       Op0=3, op1=3, CRn=14, CRm=2, Op2=2   AP_CNTP_CVAL_EL0
                                                                     This bit does not cause any instructions to be trapped to EL2
                                                                     when AP_HCR_EL2[TGE]==0.

                                                                 1 = This bit does not cause any instructions to be trapped to EL2. */
		uint32_t el0vten                     : 1;  /**< R/W - Controls whether the virtual timer register accessing instructions are
                                                                 accessible from non-secure EL0 when AP_HCR_EL2[TGE]==1.
                                                                 0 = The following system register accessing instructions in AARCH64,
                                                                     and their equivlent instructions in AARCH32, are trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 1 and the instructions are executed at non-secure
                                                                     EL0.
                                                                       Op0=3, op1=3, CRn=14, CRm=3, Op2=0   AP_CNTV_TVAL_EL0
                                                                       Op0=3, op1=3, CRn=14, CRm=3, Op2=1   AP_CNTV_CTL_EL0
                                                                       Op0=3, op1=3, CRn=14, CRm=3, Op2=2   AP_CNTV_CVAL_EL0
                                                                     This bit does not cause any instructions to be trapped to EL2
                                                                     when AP_HCR_EL2[TGE]==0.

                                                                 1 = This bit does not cause any instructions to be trapped to EL2. */
		uint32_t evnti                       : 4;  /**< R/W - Selects which bit (0 to 15) of the corresponding counter
                                                                 register ( AP_CNTPCT_EL0 or AP_CNTVCT_EL0) is the trigger for the
                                                                 event stream generated from that counter, when that stream is
                                                                 enabled. */
		uint32_t evntdir                     : 1;  /**< R/W - Controls which transition of the counter register ( AP_CNTPCT_EL0
                                                                     or AP_CNTVCT_EL0) trigger bit, defined by EVNTI, generates an
                                                                     event when the event stream is enabled:
                                                                 0 = A 0 to 1 transition of the trigger bit triggers an event.
                                                                 1 = A 1 to 0 transition of the trigger bit triggers an event. */
		uint32_t evnten                      : 1;  /**< R/W - Enables the generation of an event stream from the
                                                                     corresponding counter:
                                                                 0 = Disables the event stream.
                                                                 1 = Enables the event stream. */
		uint32_t el0vcten                    : 1;  /**< R/W - Controls whether the virtual counter registers are accessible
                                                                     from non-secure EL1 and EL0 when AP_HCR_EL2[TGE]==1:
                                                                 0 = The following system register accessing instructions in AARCH64,
                                                                     and their equivlent instructions in AARCH32, are trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 1 and the instructions are executed at non-secure
                                                                     EL0.
                                                                       Op0=3, op1=3, CRn=14, CRm=0, Op2=2   AP_CNTVCT_EL0
                                                                     In addition, if EL0PCTEN == 0, then the following System Register
                                                                     accessing instructions in AARCH64, and their equivlent instructions
                                                                     in AARCH32, are trapped to EL2 when executed at non-secure EL0 when
                                                                     AP_HCR_EL2[TGE]==1.
                                                                       Op0=3, op1=3, CRn=14, CRm=0, Op2=0   AP_CNTFRQ_EL0
                                                                     This bit does not cause any instructions to be trapped to EL2
                                                                     when AP_HCR_EL2[TGE]==0.

                                                                 1 = This bit does not cause any instructions to be trapped to EL2. */
		uint32_t el0pcten                    : 1;  /**< R/W - Controls whether physical counter register accessing instructions
                                                                 are accessible from non-secure EL0 when AP_HCR_EL2[TGE]==1:
                                                                 0 = The following system register accessing instructions in AARCH64,
                                                                     and their equivlent instructions in AARCH32, are trapped to EL2
                                                                     when AP_HCR_EL2[TGE] == 1 and the instructions are executed at non-secure
                                                                     EL0.
                                                                       Op0=3, op1=3, CRn=14, CRm=0, Op2=1   AP_CNTPCT_EL0
                                                                     In addition, if EL0PCTEN == 0, then the following System Register
                                                                     accessing instructions in AARCH64, and their equivlent instructions
                                                                     in AARCH32, are trapped to EL2 when executed at non-secure EL0 when
                                                                     AP_HCR_EL2[TGE]==1.
                                                                       Op0=3, op1=3, CRn=14, CRm=0, Op2=0   AP_CNTFRQ_EL0
                                                                     This bit does not cause any instructions to be trapped to EL2
                                                                     when AP_HCR_EL2[TGE]==0.

                                                                 1 = This bit does not cause any instructions to be trapped to EL2. */
#else
		uint32_t el0pcten                    : 1;
		uint32_t el0vcten                    : 1;
		uint32_t evnten                      : 1;
		uint32_t evntdir                     : 1;
		uint32_t evnti                       : 4;
		uint32_t el0vten                     : 1;
		uint32_t el0pten                     : 1;
		uint32_t el1pten                     : 1;
		uint32_t el1pcen                     : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_ap_cnthctl_el2_e2h_s    cn88xx; */
	/* struct bdk_ap_cnthctl_el2_e2h_s    cn88xxp1; */
} bdk_ap_cnthctl_el2_e2h_t;

#define BDK_AP_CNTHCTL_EL2_E2H BDK_AP_CNTHCTL_EL2_E2H_FUNC()
static inline uint64_t BDK_AP_CNTHCTL_EL2_E2H_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHCTL_EL2_E2H_FUNC(void)
{
	return 0x000003040E010010ull;
}
#define typedef_BDK_AP_CNTHCTL_EL2_E2H bdk_ap_cnthctl_el2_e2h_t
#define bustype_BDK_AP_CNTHCTL_EL2_E2H BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHCTL_EL2_E2H 0
#define arguments_BDK_AP_CNTHCTL_EL2_E2H -1,-1,-1,-1
#define basename_BDK_AP_CNTHCTL_EL2_E2H "AP_CNTHCTL_EL2_E2H"


/**
 * SYSREG - ap_cnthp_ctl_el2
 *
 * Control register for the EL2 physical timer.
 *
 */
typedef union bdk_ap_cnthp_ctl_el2 {
	uint32_t u;
	struct bdk_ap_cnthp_ctl_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t istatus                     : 1;  /**< RO - The status of the timer interrupt. This bit is read-only.
                                                                 A register write that sets IMASK to 1 latches this bit to
                                                                     reflect the status of the interrupt immediately before that
                                                                     write.
                                                                 0 = Interrupt not asserted.
                                                                 1 = Interrupt asserted. */
		uint32_t imask                       : 1;  /**< R/W - Timer interrupt mask bit.
                                                                 0 = Timer interrupt is not masked.
                                                                 1 = Timer interrupt is masked. */
		uint32_t enable                      : 1;  /**< R/W - Enables the timer.
                                                                 Disabling the timer masks the timer interrupt, but the timer
                                                                     value continues to count down.
                                                                 0 = Timer disabled.
                                                                 1 = Timer enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t imask                       : 1;
		uint32_t istatus                     : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_cnthp_ctl_el2_s      cn88xx; */
	/* struct bdk_ap_cnthp_ctl_el2_s      cn88xxp1; */
} bdk_ap_cnthp_ctl_el2_t;

#define BDK_AP_CNTHP_CTL_EL2 BDK_AP_CNTHP_CTL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHP_CTL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHP_CTL_EL2_FUNC(void)
{
	return 0x000003040E020100ull;
}
#define typedef_BDK_AP_CNTHP_CTL_EL2 bdk_ap_cnthp_ctl_el2_t
#define bustype_BDK_AP_CNTHP_CTL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHP_CTL_EL2 0
#define arguments_BDK_AP_CNTHP_CTL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHP_CTL_EL2 "AP_CNTHP_CTL_EL2"


/**
 * SYSREG - ap_cnthp_cval_el2
 *
 * Holds the compare value for the EL2 physical timer.
 *
 */
typedef union bdk_ap_cnthp_cval_el2 {
	uint64_t u;
	struct bdk_ap_cnthp_cval_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - EL2 physical timer compare value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cnthp_cval_el2_s     cn88xx; */
	/* struct bdk_ap_cnthp_cval_el2_s     cn88xxp1; */
} bdk_ap_cnthp_cval_el2_t;

#define BDK_AP_CNTHP_CVAL_EL2 BDK_AP_CNTHP_CVAL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHP_CVAL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHP_CVAL_EL2_FUNC(void)
{
	return 0x000003040E020200ull;
}
#define typedef_BDK_AP_CNTHP_CVAL_EL2 bdk_ap_cnthp_cval_el2_t
#define bustype_BDK_AP_CNTHP_CVAL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHP_CVAL_EL2 0
#define arguments_BDK_AP_CNTHP_CVAL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHP_CVAL_EL2 "AP_CNTHP_CVAL_EL2"


/**
 * SYSREG - ap_cnthp_tval_el2
 *
 * Holds the timer value for the EL2 physical timer.
 *
 */
typedef union bdk_ap_cnthp_tval_el2 {
	uint32_t u;
	struct bdk_ap_cnthp_tval_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - EL2 physical timer value. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_cnthp_tval_el2_s     cn88xx; */
	/* struct bdk_ap_cnthp_tval_el2_s     cn88xxp1; */
} bdk_ap_cnthp_tval_el2_t;

#define BDK_AP_CNTHP_TVAL_EL2 BDK_AP_CNTHP_TVAL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHP_TVAL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHP_TVAL_EL2_FUNC(void)
{
	return 0x000003040E020000ull;
}
#define typedef_BDK_AP_CNTHP_TVAL_EL2 bdk_ap_cnthp_tval_el2_t
#define bustype_BDK_AP_CNTHP_TVAL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHP_TVAL_EL2 0
#define arguments_BDK_AP_CNTHP_TVAL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHP_TVAL_EL2 "AP_CNTHP_TVAL_EL2"


/**
 * SYSREG - ap_cnthv_ctl_el2
 *
 * v8.1 Control register for the EL2 virtual timer.
 *
 */
typedef union bdk_ap_cnthv_ctl_el2 {
	uint32_t u;
	struct bdk_ap_cnthv_ctl_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t istatus                     : 1;  /**< RO - The status of the timer interrupt. This bit is read-only.
                                                                 A register write that sets IMASK to 1 latches this bit to
                                                                     reflect the status of the interrupt immediately before that
                                                                     write.
                                                                 0 = Interrupt not asserted.
                                                                 1 = Interrupt asserted. */
		uint32_t imask                       : 1;  /**< R/W - Timer interrupt mask bit.
                                                                 0 = Timer interrupt is not masked.
                                                                 1 = Timer interrupt is masked. */
		uint32_t enable                      : 1;  /**< R/W - Enables the timer.
                                                                 Disabling the timer masks the timer interrupt, but the timer
                                                                     value continues to count down.
                                                                 0 = Timer disabled.
                                                                 1 = Timer enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t imask                       : 1;
		uint32_t istatus                     : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_cnthv_ctl_el2_s      cn88xx; */
	/* struct bdk_ap_cnthv_ctl_el2_s      cn88xxp1; */
} bdk_ap_cnthv_ctl_el2_t;

#define BDK_AP_CNTHV_CTL_EL2 BDK_AP_CNTHV_CTL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHV_CTL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHV_CTL_EL2_FUNC(void)
{
	return 0x000003040E030100ull;
}
#define typedef_BDK_AP_CNTHV_CTL_EL2 bdk_ap_cnthv_ctl_el2_t
#define bustype_BDK_AP_CNTHV_CTL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHV_CTL_EL2 0
#define arguments_BDK_AP_CNTHV_CTL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHV_CTL_EL2 "AP_CNTHV_CTL_EL2"


/**
 * SYSREG - ap_cnthv_cval_el2
 *
 * v8.1 Holds the compare value for the EL2 virtual timer.
 *
 */
typedef union bdk_ap_cnthv_cval_el2 {
	uint64_t u;
	struct bdk_ap_cnthv_cval_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - EL2 physical timer compare value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cnthv_cval_el2_s     cn88xx; */
	/* struct bdk_ap_cnthv_cval_el2_s     cn88xxp1; */
} bdk_ap_cnthv_cval_el2_t;

#define BDK_AP_CNTHV_CVAL_EL2 BDK_AP_CNTHV_CVAL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHV_CVAL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHV_CVAL_EL2_FUNC(void)
{
	return 0x000003040E030200ull;
}
#define typedef_BDK_AP_CNTHV_CVAL_EL2 bdk_ap_cnthv_cval_el2_t
#define bustype_BDK_AP_CNTHV_CVAL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHV_CVAL_EL2 0
#define arguments_BDK_AP_CNTHV_CVAL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHV_CVAL_EL2 "AP_CNTHV_CVAL_EL2"


/**
 * SYSREG - ap_cnthv_tval_el2
 *
 * v8.1 Holds the timer value for the EL2 virtual timer.
 *
 */
typedef union bdk_ap_cnthv_tval_el2 {
	uint32_t u;
	struct bdk_ap_cnthv_tval_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - EL2 virtual timer value. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_cnthv_tval_el2_s     cn88xx; */
	/* struct bdk_ap_cnthv_tval_el2_s     cn88xxp1; */
} bdk_ap_cnthv_tval_el2_t;

#define BDK_AP_CNTHV_TVAL_EL2 BDK_AP_CNTHV_TVAL_EL2_FUNC()
static inline uint64_t BDK_AP_CNTHV_TVAL_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTHV_TVAL_EL2_FUNC(void)
{
	return 0x000003040E030000ull;
}
#define typedef_BDK_AP_CNTHV_TVAL_EL2 bdk_ap_cnthv_tval_el2_t
#define bustype_BDK_AP_CNTHV_TVAL_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTHV_TVAL_EL2 0
#define arguments_BDK_AP_CNTHV_TVAL_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTHV_TVAL_EL2 "AP_CNTHV_TVAL_EL2"


/**
 * SYSREG - ap_cntkctl_el1
 *
 * Controls the generation of an event stream from the virtual
 * counter, and access from EL0 to the physical counter, virtual
 * counter, EL1 physical timers, and the virtual timer.
 */
typedef union bdk_ap_cntkctl_el1 {
	uint32_t u;
	struct bdk_ap_cntkctl_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t el0pten                     : 1;  /**< R/W - Controls whether the physical timer registers are accessible
                                                                     from EL0 modes:
                                                                 0 = The AP_CNTP_CVAL_EL0, AP_CNTP_CTL_EL0, and AP_CNTP_TVAL_EL0 registers
                                                                     are not accessible from EL0.
                                                                 1 = The AP_CNTP_CVAL_EL0, AP_CNTP_CTL_EL0, and AP_CNTP_TVAL_EL0 registers
                                                                     are accessible from EL0. */
		uint32_t el0vten                     : 1;  /**< R/W - Controls whether the virtual timer registers are accessible
                                                                     from EL0 modes:
                                                                 0 = The AP_CNTV_CVAL_EL0, AP_CNTV_CTL_EL0, and AP_CNTV_TVAL_EL0 registers
                                                                     are not accessible from EL0.
                                                                 1 = The AP_CNTV_CVAL_EL0, AP_CNTV_CTL_EL0, and AP_CNTV_TVAL_EL0 registers
                                                                     are accessible from EL0. */
		uint32_t evnti                       : 4;  /**< R/W - Selects which bit (0 to 15) of the corresponding counter
                                                                 register ( AP_CNTPCT_EL0 or AP_CNTVCT_EL0) is the trigger for the
                                                                 event stream generated from that counter, when that stream is
                                                                 enabled. */
		uint32_t evntdir                     : 1;  /**< R/W - Controls which transition of the counter register ( AP_CNTPCT_EL0
                                                                     or AP_CNTVCT_EL0) trigger bit, defined by EVNTI, generates an
                                                                     event when the event stream is enabled:
                                                                 0 = A 0 to 1 transition of the trigger bit triggers an event.
                                                                 1 = A 1 to 0 transition of the trigger bit triggers an event. */
		uint32_t evnten                      : 1;  /**< R/W - Enables the generation of an event stream from the
                                                                     corresponding counter:
                                                                 0 = Disables the event stream.
                                                                 1 = Enables the event stream. */
		uint32_t el0vcten                    : 1;  /**< R/W - Controls whether the virtual counter, AP_CNTVCT_EL0, and the
                                                                     frequency register AP_CNTFRQ_EL0, are accessible from EL0 modes:
                                                                 0 =  AP_CNTVCT_EL0 is not accessible from EL0. If EL0PCTEN is set to
                                                                     0, AP_CNTFRQ_EL0 is not accessible from EL0.
                                                                 1 =  AP_CNTVCT_EL0 and AP_CNTFRQ_EL0 are accessible from EL0. */
		uint32_t el0pcten                    : 1;  /**< R/W - Controls whether the physical counter, AP_CNTPCT_EL0, and the
                                                                     frequency register AP_CNTFRQ_EL0, are accessible from EL0 modes:
                                                                 0 =  AP_CNTPCT_EL0 is not accessible from EL0 modes. If EL0VCTEN is
                                                                     set to 0, AP_CNTFRQ_EL0 is not accessible from EL0.
                                                                 1 =  AP_CNTPCT_EL0 and AP_CNTFRQ_EL0 are accessible from EL0. */
#else
		uint32_t el0pcten                    : 1;
		uint32_t el0vcten                    : 1;
		uint32_t evnten                      : 1;
		uint32_t evntdir                     : 1;
		uint32_t evnti                       : 4;
		uint32_t el0vten                     : 1;
		uint32_t el0pten                     : 1;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_ap_cntkctl_el1_s        cn88xx; */
	/* struct bdk_ap_cntkctl_el1_s        cn88xxp1; */
} bdk_ap_cntkctl_el1_t;

#define BDK_AP_CNTKCTL_EL1 BDK_AP_CNTKCTL_EL1_FUNC()
static inline uint64_t BDK_AP_CNTKCTL_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTKCTL_EL1_FUNC(void)
{
	return 0x000003000E010000ull;
}
#define typedef_BDK_AP_CNTKCTL_EL1 bdk_ap_cntkctl_el1_t
#define bustype_BDK_AP_CNTKCTL_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTKCTL_EL1 0
#define arguments_BDK_AP_CNTKCTL_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CNTKCTL_EL1 "AP_CNTKCTL_EL1"


/**
 * SYSREG - ap_cntkctl_el12
 *
 * Alias of AP_CNTKCTL_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntkctl_el12 {
	uint32_t u;
	struct bdk_ap_cntkctl_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_cntkctl_el12_s       cn88xx; */
	/* struct bdk_ap_cntkctl_el12_s       cn88xxp1; */
} bdk_ap_cntkctl_el12_t;

#define BDK_AP_CNTKCTL_EL12 BDK_AP_CNTKCTL_EL12_FUNC()
static inline uint64_t BDK_AP_CNTKCTL_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTKCTL_EL12_FUNC(void)
{
	return 0x000003050E010000ull;
}
#define typedef_BDK_AP_CNTKCTL_EL12 bdk_ap_cntkctl_el12_t
#define bustype_BDK_AP_CNTKCTL_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTKCTL_EL12 0
#define arguments_BDK_AP_CNTKCTL_EL12 -1,-1,-1,-1
#define basename_BDK_AP_CNTKCTL_EL12 "AP_CNTKCTL_EL12"


/**
 * SYSREG - ap_cntp_ctl_el0
 *
 * Control register for the EL1 physical timer.
 *
 */
typedef union bdk_ap_cntp_ctl_el0 {
	uint32_t u;
	struct bdk_ap_cntp_ctl_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t istatus                     : 1;  /**< RO - The status of the timer interrupt. This bit is read-only.
                                                                 A register write that sets IMASK to 1 latches this bit to
                                                                     reflect the status of the interrupt immediately before that
                                                                     write.
                                                                 0 = Interrupt not asserted.
                                                                 1 = Interrupt asserted. */
		uint32_t imask                       : 1;  /**< R/W - Timer interrupt mask bit.
                                                                 0 = Timer interrupt is not masked.
                                                                 1 = Timer interrupt is masked. */
		uint32_t enable                      : 1;  /**< R/W - Enables the timer.
                                                                 Disabling the timer masks the timer interrupt, but the timer
                                                                     value continues to count down.
                                                                 0 = Timer disabled.
                                                                 1 = Timer enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t imask                       : 1;
		uint32_t istatus                     : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_cntp_ctl_el0_s       cn88xx; */
	/* struct bdk_ap_cntp_ctl_el0_s       cn88xxp1; */
} bdk_ap_cntp_ctl_el0_t;

#define BDK_AP_CNTP_CTL_EL0 BDK_AP_CNTP_CTL_EL0_FUNC()
static inline uint64_t BDK_AP_CNTP_CTL_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTP_CTL_EL0_FUNC(void)
{
	return 0x000003030E020100ull;
}
#define typedef_BDK_AP_CNTP_CTL_EL0 bdk_ap_cntp_ctl_el0_t
#define bustype_BDK_AP_CNTP_CTL_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTP_CTL_EL0 0
#define arguments_BDK_AP_CNTP_CTL_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTP_CTL_EL0 "AP_CNTP_CTL_EL0"


/**
 * SYSREG - ap_cntp_ctl_el02
 *
 * Alias of AP_CNTP_CTL_EL0 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntp_ctl_el02 {
	uint32_t u;
	struct bdk_ap_cntp_ctl_el02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_cntp_ctl_el02_s      cn88xx; */
	/* struct bdk_ap_cntp_ctl_el02_s      cn88xxp1; */
} bdk_ap_cntp_ctl_el02_t;

#define BDK_AP_CNTP_CTL_EL02 BDK_AP_CNTP_CTL_EL02_FUNC()
static inline uint64_t BDK_AP_CNTP_CTL_EL02_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTP_CTL_EL02_FUNC(void)
{
	return 0x000003050E020100ull;
}
#define typedef_BDK_AP_CNTP_CTL_EL02 bdk_ap_cntp_ctl_el02_t
#define bustype_BDK_AP_CNTP_CTL_EL02 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTP_CTL_EL02 0
#define arguments_BDK_AP_CNTP_CTL_EL02 -1,-1,-1,-1
#define basename_BDK_AP_CNTP_CTL_EL02 "AP_CNTP_CTL_EL02"


/**
 * SYSREG - ap_cntp_cval_el0
 *
 * Holds the compare value for the EL1 physical timer.
 *
 */
typedef union bdk_ap_cntp_cval_el0 {
	uint64_t u;
	struct bdk_ap_cntp_cval_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - EL1 physical timer compare value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cntp_cval_el0_s      cn88xx; */
	/* struct bdk_ap_cntp_cval_el0_s      cn88xxp1; */
} bdk_ap_cntp_cval_el0_t;

#define BDK_AP_CNTP_CVAL_EL0 BDK_AP_CNTP_CVAL_EL0_FUNC()
static inline uint64_t BDK_AP_CNTP_CVAL_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTP_CVAL_EL0_FUNC(void)
{
	return 0x000003030E020200ull;
}
#define typedef_BDK_AP_CNTP_CVAL_EL0 bdk_ap_cntp_cval_el0_t
#define bustype_BDK_AP_CNTP_CVAL_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTP_CVAL_EL0 0
#define arguments_BDK_AP_CNTP_CVAL_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTP_CVAL_EL0 "AP_CNTP_CVAL_EL0"


/**
 * SYSREG - ap_cntp_cval_el02
 *
 * Alias of AP_CNTP_CVAL_EL0 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntp_cval_el02 {
	uint64_t u;
	struct bdk_ap_cntp_cval_el02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_cntp_cval_el02_s     cn88xx; */
	/* struct bdk_ap_cntp_cval_el02_s     cn88xxp1; */
} bdk_ap_cntp_cval_el02_t;

#define BDK_AP_CNTP_CVAL_EL02 BDK_AP_CNTP_CVAL_EL02_FUNC()
static inline uint64_t BDK_AP_CNTP_CVAL_EL02_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTP_CVAL_EL02_FUNC(void)
{
	return 0x000003050E020200ull;
}
#define typedef_BDK_AP_CNTP_CVAL_EL02 bdk_ap_cntp_cval_el02_t
#define bustype_BDK_AP_CNTP_CVAL_EL02 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTP_CVAL_EL02 0
#define arguments_BDK_AP_CNTP_CVAL_EL02 -1,-1,-1,-1
#define basename_BDK_AP_CNTP_CVAL_EL02 "AP_CNTP_CVAL_EL02"


/**
 * SYSREG - ap_cntp_tval_el0
 *
 * Holds the timer value for the EL1 physical timer.
 *
 */
typedef union bdk_ap_cntp_tval_el0 {
	uint32_t u;
	struct bdk_ap_cntp_tval_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - EL1 physical timer value. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_cntp_tval_el0_s      cn88xx; */
	/* struct bdk_ap_cntp_tval_el0_s      cn88xxp1; */
} bdk_ap_cntp_tval_el0_t;

#define BDK_AP_CNTP_TVAL_EL0 BDK_AP_CNTP_TVAL_EL0_FUNC()
static inline uint64_t BDK_AP_CNTP_TVAL_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTP_TVAL_EL0_FUNC(void)
{
	return 0x000003030E020000ull;
}
#define typedef_BDK_AP_CNTP_TVAL_EL0 bdk_ap_cntp_tval_el0_t
#define bustype_BDK_AP_CNTP_TVAL_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTP_TVAL_EL0 0
#define arguments_BDK_AP_CNTP_TVAL_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTP_TVAL_EL0 "AP_CNTP_TVAL_EL0"


/**
 * SYSREG - ap_cntp_tval_el02
 *
 * Alias of CNTP_TVAL_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntp_tval_el02 {
	uint32_t u;
	struct bdk_ap_cntp_tval_el02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_cntp_tval_el02_s     cn88xx; */
	/* struct bdk_ap_cntp_tval_el02_s     cn88xxp1; */
} bdk_ap_cntp_tval_el02_t;

#define BDK_AP_CNTP_TVAL_EL02 BDK_AP_CNTP_TVAL_EL02_FUNC()
static inline uint64_t BDK_AP_CNTP_TVAL_EL02_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTP_TVAL_EL02_FUNC(void)
{
	return 0x000003050E020000ull;
}
#define typedef_BDK_AP_CNTP_TVAL_EL02 bdk_ap_cntp_tval_el02_t
#define bustype_BDK_AP_CNTP_TVAL_EL02 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTP_TVAL_EL02 0
#define arguments_BDK_AP_CNTP_TVAL_EL02 -1,-1,-1,-1
#define basename_BDK_AP_CNTP_TVAL_EL02 "AP_CNTP_TVAL_EL02"


/**
 * SYSREG - ap_cntpct_el0
 *
 * Holds the 64-bit physical count value.
 *
 */
typedef union bdk_ap_cntpct_el0 {
	uint64_t u;
	struct bdk_ap_cntpct_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO - Physical count value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cntpct_el0_s         cn88xx; */
	/* struct bdk_ap_cntpct_el0_s         cn88xxp1; */
} bdk_ap_cntpct_el0_t;

#define BDK_AP_CNTPCT_EL0 BDK_AP_CNTPCT_EL0_FUNC()
static inline uint64_t BDK_AP_CNTPCT_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTPCT_EL0_FUNC(void)
{
	return 0x000003030E000100ull;
}
#define typedef_BDK_AP_CNTPCT_EL0 bdk_ap_cntpct_el0_t
#define bustype_BDK_AP_CNTPCT_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTPCT_EL0 0
#define arguments_BDK_AP_CNTPCT_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTPCT_EL0 "AP_CNTPCT_EL0"


/**
 * SYSREG - ap_cntps_ctl_el1
 *
 * Control register for the secure physical timer, usually
 * accessible at EL3 but configurably accessible at EL1 in Secure
 * state.
 */
typedef union bdk_ap_cntps_ctl_el1 {
	uint32_t u;
	struct bdk_ap_cntps_ctl_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t istatus                     : 1;  /**< RO - The status of the timer interrupt. This bit is read-only.
                                                                 A register write that sets IMASK to 1 latches this bit to
                                                                     reflect the status of the interrupt immediately before that
                                                                     write.
                                                                 0 = Interrupt not asserted.
                                                                 1 = Interrupt asserted. */
		uint32_t imask                       : 1;  /**< R/W - Timer interrupt mask bit.
                                                                 0 = Timer interrupt is not masked.
                                                                 1 = Timer interrupt is masked. */
		uint32_t enable                      : 1;  /**< R/W - Enables the timer.
                                                                 Disabling the timer masks the timer interrupt, but the timer
                                                                     value continues to count down.
                                                                 0 = Timer disabled.
                                                                 1 = Timer enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t imask                       : 1;
		uint32_t istatus                     : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_cntps_ctl_el1_s      cn88xx; */
	/* struct bdk_ap_cntps_ctl_el1_s      cn88xxp1; */
} bdk_ap_cntps_ctl_el1_t;

#define BDK_AP_CNTPS_CTL_EL1 BDK_AP_CNTPS_CTL_EL1_FUNC()
static inline uint64_t BDK_AP_CNTPS_CTL_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTPS_CTL_EL1_FUNC(void)
{
	return 0x000003070E020100ull;
}
#define typedef_BDK_AP_CNTPS_CTL_EL1 bdk_ap_cntps_ctl_el1_t
#define bustype_BDK_AP_CNTPS_CTL_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTPS_CTL_EL1 0
#define arguments_BDK_AP_CNTPS_CTL_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CNTPS_CTL_EL1 "AP_CNTPS_CTL_EL1"


/**
 * SYSREG - ap_cntps_cval_el1
 *
 * Holds the compare value for the secure physical timer, usually
 * accessible at EL3 but configurably accessible at EL1 in Secure
 * state.
 */
typedef union bdk_ap_cntps_cval_el1 {
	uint64_t u;
	struct bdk_ap_cntps_cval_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Secure physical timer compare value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cntps_cval_el1_s     cn88xx; */
	/* struct bdk_ap_cntps_cval_el1_s     cn88xxp1; */
} bdk_ap_cntps_cval_el1_t;

#define BDK_AP_CNTPS_CVAL_EL1 BDK_AP_CNTPS_CVAL_EL1_FUNC()
static inline uint64_t BDK_AP_CNTPS_CVAL_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTPS_CVAL_EL1_FUNC(void)
{
	return 0x000003070E020200ull;
}
#define typedef_BDK_AP_CNTPS_CVAL_EL1 bdk_ap_cntps_cval_el1_t
#define bustype_BDK_AP_CNTPS_CVAL_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTPS_CVAL_EL1 0
#define arguments_BDK_AP_CNTPS_CVAL_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CNTPS_CVAL_EL1 "AP_CNTPS_CVAL_EL1"


/**
 * SYSREG - ap_cntps_tval_el1
 *
 * Holds the timer value for the secure physical timer, usually
 * accessible at EL3 but configurably accessible at EL1 in Secure
 * state.
 */
typedef union bdk_ap_cntps_tval_el1 {
	uint32_t u;
	struct bdk_ap_cntps_tval_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Secure physical timer value. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_cntps_tval_el1_s     cn88xx; */
	/* struct bdk_ap_cntps_tval_el1_s     cn88xxp1; */
} bdk_ap_cntps_tval_el1_t;

#define BDK_AP_CNTPS_TVAL_EL1 BDK_AP_CNTPS_TVAL_EL1_FUNC()
static inline uint64_t BDK_AP_CNTPS_TVAL_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTPS_TVAL_EL1_FUNC(void)
{
	return 0x000003070E020000ull;
}
#define typedef_BDK_AP_CNTPS_TVAL_EL1 bdk_ap_cntps_tval_el1_t
#define bustype_BDK_AP_CNTPS_TVAL_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTPS_TVAL_EL1 0
#define arguments_BDK_AP_CNTPS_TVAL_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CNTPS_TVAL_EL1 "AP_CNTPS_TVAL_EL1"


/**
 * SYSREG - ap_cntv_ctl_el0
 *
 * Control register for the virtual timer.
 *
 */
typedef union bdk_ap_cntv_ctl_el0 {
	uint32_t u;
	struct bdk_ap_cntv_ctl_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t istatus                     : 1;  /**< RO - The status of the timer interrupt. This bit is read-only.
                                                                 A register write that sets IMASK to 1 latches this bit to
                                                                     reflect the status of the interrupt immediately before that
                                                                     write.
                                                                 0 = Interrupt not asserted.
                                                                 1 = Interrupt asserted. */
		uint32_t imask                       : 1;  /**< R/W - Timer interrupt mask bit.
                                                                 0 = Timer interrupt is not masked.
                                                                 1 = Timer interrupt is masked. */
		uint32_t enable                      : 1;  /**< R/W - Enables the timer.
                                                                 Disabling the timer masks the timer interrupt, but the timer
                                                                     value continues to count down.
                                                                 0 = Timer disabled.
                                                                 1 = Timer enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t imask                       : 1;
		uint32_t istatus                     : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_cntv_ctl_el0_s       cn88xx; */
	/* struct bdk_ap_cntv_ctl_el0_s       cn88xxp1; */
} bdk_ap_cntv_ctl_el0_t;

#define BDK_AP_CNTV_CTL_EL0 BDK_AP_CNTV_CTL_EL0_FUNC()
static inline uint64_t BDK_AP_CNTV_CTL_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTV_CTL_EL0_FUNC(void)
{
	return 0x000003030E030100ull;
}
#define typedef_BDK_AP_CNTV_CTL_EL0 bdk_ap_cntv_ctl_el0_t
#define bustype_BDK_AP_CNTV_CTL_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTV_CTL_EL0 0
#define arguments_BDK_AP_CNTV_CTL_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTV_CTL_EL0 "AP_CNTV_CTL_EL0"


/**
 * SYSREG - ap_cntv_ctl_el02
 *
 * Alias of AP_CNTV_CTL_EL0 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntv_ctl_el02 {
	uint32_t u;
	struct bdk_ap_cntv_ctl_el02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_cntv_ctl_el02_s      cn88xx; */
	/* struct bdk_ap_cntv_ctl_el02_s      cn88xxp1; */
} bdk_ap_cntv_ctl_el02_t;

#define BDK_AP_CNTV_CTL_EL02 BDK_AP_CNTV_CTL_EL02_FUNC()
static inline uint64_t BDK_AP_CNTV_CTL_EL02_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTV_CTL_EL02_FUNC(void)
{
	return 0x000003050E030100ull;
}
#define typedef_BDK_AP_CNTV_CTL_EL02 bdk_ap_cntv_ctl_el02_t
#define bustype_BDK_AP_CNTV_CTL_EL02 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTV_CTL_EL02 0
#define arguments_BDK_AP_CNTV_CTL_EL02 -1,-1,-1,-1
#define basename_BDK_AP_CNTV_CTL_EL02 "AP_CNTV_CTL_EL02"


/**
 * SYSREG - ap_cntv_cval_el0
 *
 * Holds the compare value for the virtual timer.
 *
 */
typedef union bdk_ap_cntv_cval_el0 {
	uint64_t u;
	struct bdk_ap_cntv_cval_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Virtual timer compare value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cntv_cval_el0_s      cn88xx; */
	/* struct bdk_ap_cntv_cval_el0_s      cn88xxp1; */
} bdk_ap_cntv_cval_el0_t;

#define BDK_AP_CNTV_CVAL_EL0 BDK_AP_CNTV_CVAL_EL0_FUNC()
static inline uint64_t BDK_AP_CNTV_CVAL_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTV_CVAL_EL0_FUNC(void)
{
	return 0x000003030E030200ull;
}
#define typedef_BDK_AP_CNTV_CVAL_EL0 bdk_ap_cntv_cval_el0_t
#define bustype_BDK_AP_CNTV_CVAL_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTV_CVAL_EL0 0
#define arguments_BDK_AP_CNTV_CVAL_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTV_CVAL_EL0 "AP_CNTV_CVAL_EL0"


/**
 * SYSREG - ap_cntv_cval_el02
 *
 * Alias of AP_CNTV_CVAL_EL0 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntv_cval_el02 {
	uint64_t u;
	struct bdk_ap_cntv_cval_el02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_cntv_cval_el02_s     cn88xx; */
	/* struct bdk_ap_cntv_cval_el02_s     cn88xxp1; */
} bdk_ap_cntv_cval_el02_t;

#define BDK_AP_CNTV_CVAL_EL02 BDK_AP_CNTV_CVAL_EL02_FUNC()
static inline uint64_t BDK_AP_CNTV_CVAL_EL02_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTV_CVAL_EL02_FUNC(void)
{
	return 0x000003050E030200ull;
}
#define typedef_BDK_AP_CNTV_CVAL_EL02 bdk_ap_cntv_cval_el02_t
#define bustype_BDK_AP_CNTV_CVAL_EL02 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTV_CVAL_EL02 0
#define arguments_BDK_AP_CNTV_CVAL_EL02 -1,-1,-1,-1
#define basename_BDK_AP_CNTV_CVAL_EL02 "AP_CNTV_CVAL_EL02"


/**
 * SYSREG - ap_cntv_tval_el0
 *
 * Holds the timer value for the virtual timer.
 *
 */
typedef union bdk_ap_cntv_tval_el0 {
	uint32_t u;
	struct bdk_ap_cntv_tval_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Virtual timer value. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_cntv_tval_el0_s      cn88xx; */
	/* struct bdk_ap_cntv_tval_el0_s      cn88xxp1; */
} bdk_ap_cntv_tval_el0_t;

#define BDK_AP_CNTV_TVAL_EL0 BDK_AP_CNTV_TVAL_EL0_FUNC()
static inline uint64_t BDK_AP_CNTV_TVAL_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTV_TVAL_EL0_FUNC(void)
{
	return 0x000003030E030000ull;
}
#define typedef_BDK_AP_CNTV_TVAL_EL0 bdk_ap_cntv_tval_el0_t
#define bustype_BDK_AP_CNTV_TVAL_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTV_TVAL_EL0 0
#define arguments_BDK_AP_CNTV_TVAL_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTV_TVAL_EL0 "AP_CNTV_TVAL_EL0"


/**
 * SYSREG - ap_cntv_tval_el02
 *
 * Alias of AP_CNTV_TVAL_EL0 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cntv_tval_el02 {
	uint32_t u;
	struct bdk_ap_cntv_tval_el02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_cntv_tval_el02_s     cn88xx; */
	/* struct bdk_ap_cntv_tval_el02_s     cn88xxp1; */
} bdk_ap_cntv_tval_el02_t;

#define BDK_AP_CNTV_TVAL_EL02 BDK_AP_CNTV_TVAL_EL02_FUNC()
static inline uint64_t BDK_AP_CNTV_TVAL_EL02_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTV_TVAL_EL02_FUNC(void)
{
	return 0x000003050E030000ull;
}
#define typedef_BDK_AP_CNTV_TVAL_EL02 bdk_ap_cntv_tval_el02_t
#define bustype_BDK_AP_CNTV_TVAL_EL02 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTV_TVAL_EL02 0
#define arguments_BDK_AP_CNTV_TVAL_EL02 -1,-1,-1,-1
#define basename_BDK_AP_CNTV_TVAL_EL02 "AP_CNTV_TVAL_EL02"


/**
 * SYSREG - ap_cntvct_el0
 *
 * Holds the 64-bit virtual count value.
 *
 */
typedef union bdk_ap_cntvct_el0 {
	uint64_t u;
	struct bdk_ap_cntvct_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO - Virtual count value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cntvct_el0_s         cn88xx; */
	/* struct bdk_ap_cntvct_el0_s         cn88xxp1; */
} bdk_ap_cntvct_el0_t;

#define BDK_AP_CNTVCT_EL0 BDK_AP_CNTVCT_EL0_FUNC()
static inline uint64_t BDK_AP_CNTVCT_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTVCT_EL0_FUNC(void)
{
	return 0x000003030E000200ull;
}
#define typedef_BDK_AP_CNTVCT_EL0 bdk_ap_cntvct_el0_t
#define bustype_BDK_AP_CNTVCT_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTVCT_EL0 0
#define arguments_BDK_AP_CNTVCT_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CNTVCT_EL0 "AP_CNTVCT_EL0"


/**
 * SYSREG - ap_cntvoff_el2
 *
 * Holds the 64-bit virtual offset.
 *
 */
typedef union bdk_ap_cntvoff_el2 {
	uint64_t u;
	struct bdk_ap_cntvoff_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Virtual offset. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cntvoff_el2_s        cn88xx; */
	/* struct bdk_ap_cntvoff_el2_s        cn88xxp1; */
} bdk_ap_cntvoff_el2_t;

#define BDK_AP_CNTVOFF_EL2 BDK_AP_CNTVOFF_EL2_FUNC()
static inline uint64_t BDK_AP_CNTVOFF_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CNTVOFF_EL2_FUNC(void)
{
	return 0x000003040E000300ull;
}
#define typedef_BDK_AP_CNTVOFF_EL2 bdk_ap_cntvoff_el2_t
#define bustype_BDK_AP_CNTVOFF_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CNTVOFF_EL2 0
#define arguments_BDK_AP_CNTVOFF_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CNTVOFF_EL2 "AP_CNTVOFF_EL2"


/**
 * SYSREG - ap_contextidr_el1
 *
 * Identifies the current Process Identifier.
 *
 */
typedef union bdk_ap_contextidr_el1 {
	uint32_t u;
	struct bdk_ap_contextidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t procid                      : 32; /**< R/W - Process Identifier. This field must be programmed with a
                                                                 unique value that identifies the current process. The bottom 8
                                                                 bits of this register are not used to hold the ASID. */
#else
		uint32_t procid                      : 32;
#endif
	} s;
	/* struct bdk_ap_contextidr_el1_s     cn88xx; */
	/* struct bdk_ap_contextidr_el1_s     cn88xxp1; */
} bdk_ap_contextidr_el1_t;

#define BDK_AP_CONTEXTIDR_EL1 BDK_AP_CONTEXTIDR_EL1_FUNC()
static inline uint64_t BDK_AP_CONTEXTIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CONTEXTIDR_EL1_FUNC(void)
{
	return 0x000003000D000100ull;
}
#define typedef_BDK_AP_CONTEXTIDR_EL1 bdk_ap_contextidr_el1_t
#define bustype_BDK_AP_CONTEXTIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CONTEXTIDR_EL1 0
#define arguments_BDK_AP_CONTEXTIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CONTEXTIDR_EL1 "AP_CONTEXTIDR_EL1"


/**
 * SYSREG - ap_contextidr_el12
 *
 * Alias of AP_CONTEXTIDR_EL1 when accessed at EL2/2 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_contextidr_el12 {
	uint32_t u;
	struct bdk_ap_contextidr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_contextidr_el12_s    cn88xx; */
	/* struct bdk_ap_contextidr_el12_s    cn88xxp1; */
} bdk_ap_contextidr_el12_t;

#define BDK_AP_CONTEXTIDR_EL12 BDK_AP_CONTEXTIDR_EL12_FUNC()
static inline uint64_t BDK_AP_CONTEXTIDR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CONTEXTIDR_EL12_FUNC(void)
{
	return 0x000003050D000100ull;
}
#define typedef_BDK_AP_CONTEXTIDR_EL12 bdk_ap_contextidr_el12_t
#define bustype_BDK_AP_CONTEXTIDR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CONTEXTIDR_EL12 0
#define arguments_BDK_AP_CONTEXTIDR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_CONTEXTIDR_EL12 "AP_CONTEXTIDR_EL12"


/**
 * SYSREG - ap_contextidr_el2
 *
 * v8.1: Identifies the current Process Identifier.
 *
 */
typedef union bdk_ap_contextidr_el2 {
	uint32_t u;
	struct bdk_ap_contextidr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t procid                      : 32; /**< R/W - v8.1: Process Identifier. This field must be programmed with a
                                                                 unique value that identifies the current process. The bottom 8
                                                                 bits of this register are not used to hold the ASID. */
#else
		uint32_t procid                      : 32;
#endif
	} s;
	/* struct bdk_ap_contextidr_el2_s     cn88xx; */
	/* struct bdk_ap_contextidr_el2_s     cn88xxp1; */
} bdk_ap_contextidr_el2_t;

#define BDK_AP_CONTEXTIDR_EL2 BDK_AP_CONTEXTIDR_EL2_FUNC()
static inline uint64_t BDK_AP_CONTEXTIDR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CONTEXTIDR_EL2_FUNC(void)
{
	return 0x000003040D000100ull;
}
#define typedef_BDK_AP_CONTEXTIDR_EL2 bdk_ap_contextidr_el2_t
#define bustype_BDK_AP_CONTEXTIDR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CONTEXTIDR_EL2 0
#define arguments_BDK_AP_CONTEXTIDR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CONTEXTIDR_EL2 "AP_CONTEXTIDR_EL2"


/**
 * SYSREG - ap_cpacr_el1
 *
 * Controls access to Trace, Floating-point, and Advanced SIMD
 * functionality.
 */
typedef union bdk_ap_cpacr_el1 {
	uint32_t u;
	struct bdk_ap_cpacr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_22_31              : 10;
		uint32_t fpen                        : 2;  /**< R/W - Causes instructions that access the registers associated with
                                                                     Floating Point and Advanced SIMD execution to trap to EL1 when
                                                                     executed from EL0 or EL1.
                                                                 0x0 = Causes any instructions in EL0 or EL1 that use the registers
                                                                     associated with Floating Point and Advanced SIMD execution to
                                                                     be trapped.
                                                                 0x1 = Causes any instructions in EL0 that use the registers
                                                                     associated with Floating Point and Advanced SIMD execution to
                                                                     be trapped, but does not cause any instruction in EL1 to be
                                                                     trapped.
                                                                 0x2 = Causes any instructions in EL0 or EL1 that use the registers
                                                                     associated with Floating Point and Advanced SIMD execution to
                                                                     be trapped.
                                                                 0x3 = Does not cause any instruction to be trapped. */
		uint32_t reserved_0_19               : 20;
#else
		uint32_t reserved_0_19               : 20;
		uint32_t fpen                        : 2;
		uint32_t reserved_22_31              : 10;
#endif
	} s;
	/* struct bdk_ap_cpacr_el1_s          cn88xx; */
	/* struct bdk_ap_cpacr_el1_s          cn88xxp1; */
} bdk_ap_cpacr_el1_t;

#define BDK_AP_CPACR_EL1 BDK_AP_CPACR_EL1_FUNC()
static inline uint64_t BDK_AP_CPACR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CPACR_EL1_FUNC(void)
{
	return 0x0000030001000200ull;
}
#define typedef_BDK_AP_CPACR_EL1 bdk_ap_cpacr_el1_t
#define bustype_BDK_AP_CPACR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CPACR_EL1 0
#define arguments_BDK_AP_CPACR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CPACR_EL1 "AP_CPACR_EL1"


/**
 * SYSREG - ap_cpacr_el12
 *
 * Alias of AP_CPACR_EL1 when accessed from EL2 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_cpacr_el12 {
	uint32_t u;
	struct bdk_ap_cpacr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_cpacr_el12_s         cn88xx; */
	/* struct bdk_ap_cpacr_el12_s         cn88xxp1; */
} bdk_ap_cpacr_el12_t;

#define BDK_AP_CPACR_EL12 BDK_AP_CPACR_EL12_FUNC()
static inline uint64_t BDK_AP_CPACR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CPACR_EL12_FUNC(void)
{
	return 0x0000030501000200ull;
}
#define typedef_BDK_AP_CPACR_EL12 bdk_ap_cpacr_el12_t
#define bustype_BDK_AP_CPACR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CPACR_EL12 0
#define arguments_BDK_AP_CPACR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_CPACR_EL12 "AP_CPACR_EL12"


/**
 * SYSREG - ap_cptr_el2
 *
 * Controls trapping to EL2 of access to CPACR, AP_CPACR_EL1, Trace
 *     functionality and registers associated with Floating Point and
 *     Advanced SIMD execution. Also controls EL2 access to this
 *     functionality.
 *
 * This register is at the same select as AP_CPTR_EL2_E2H and is used when E2H=0.
 */
typedef union bdk_ap_cptr_el2 {
	uint32_t u;
	struct bdk_ap_cptr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tcpac                       : 1;  /**< R/W - This causes a direct access to CPACR or AP_CPACR_EL1 from EL1 to
                                                                     trap to EL2.
                                                                 0 = Does not cause access to CPACR or AP_CPACR_EL1 to be trapped.
                                                                 1 = Causes access to CPACR or AP_CPACR_EL1 to be trapped. */
		uint32_t reserved_14_30              : 17;
		uint32_t rsvd_12_13                  : 2;  /**< RO - Reserved 1. */
		uint32_t reserved_11_11              : 1;
		uint32_t tfp                         : 1;  /**< R/W - This causes instructions that access the registers associated
                                                                     with Floating Point and Advanced SIMD execution to trap to EL2
                                                                     when executed from EL0, EL1, or EL2, unless trapped to EL1.

                                                                 0 = Does not cause any instruction to be trapped.
                                                                 1 = Causes any instructions that use the registers associated with
                                                                     Floating Point and Advanced SIMD execution to be trapped. */
		uint32_t rsvd_0_9                    : 10; /**< RO - Reserved 1. */
#else
		uint32_t rsvd_0_9                    : 10;
		uint32_t tfp                         : 1;
		uint32_t reserved_11_11              : 1;
		uint32_t rsvd_12_13                  : 2;
		uint32_t reserved_14_30              : 17;
		uint32_t tcpac                       : 1;
#endif
	} s;
	/* struct bdk_ap_cptr_el2_s           cn88xx; */
	/* struct bdk_ap_cptr_el2_s           cn88xxp1; */
} bdk_ap_cptr_el2_t;

#define BDK_AP_CPTR_EL2 BDK_AP_CPTR_EL2_FUNC()
static inline uint64_t BDK_AP_CPTR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CPTR_EL2_FUNC(void)
{
	return 0x0000030401010200ull;
}
#define typedef_BDK_AP_CPTR_EL2 bdk_ap_cptr_el2_t
#define bustype_BDK_AP_CPTR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CPTR_EL2 0
#define arguments_BDK_AP_CPTR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CPTR_EL2 "AP_CPTR_EL2"


/**
 * SYSREG - ap_cptr_el2_e2h
 *
 * Controls trapping to EL2 of access to CPACR, AP_CPACR_EL1, Trace
 *     functionality and registers associated with Floating Point and
 *     Advanced SIMD execution. Also controls EL2 access to this
 *     functionality.
 *
 * This register is at the same select as AP_CPTR_EL2 and is used when E2H=1.
 */
typedef union bdk_ap_cptr_el2_e2h {
	uint32_t u;
	struct bdk_ap_cptr_el2_e2h_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tcpac                       : 1;  /**< R/W - This causes a direct access to CPACR or AP_CPACR_EL1 from EL1 to
                                                                     trap to EL2. When AP_HCR_EL2[TGE] == 0:
                                                                 0 = Does not cause access to CPACR or AP_CPACR_EL1 to be trapped.
                                                                 1 = Causes access to CPACR or AP_CPACR_EL1 to be trapped.

                                                                 When AP_HCR_EL2[TGE] == 1, this bit is ignored by hardware and
                                                                 does not cause access to the AP_CPACR_EL1 to be trapped. */
		uint32_t reserved_22_30              : 9;
		uint32_t fpen                        : 2;  /**< R/W - This causes instructions that access the registers associated with
                                                                 Floating Point and Advanced SIMD execution to trap to EL2 when executed
                                                                 from EL0 or EL2.
                                                                 0x0 = This field value causes any instructions that use the registers
                                                                      associated with Floating Point and Advanced SIMD execution to be
                                                                      trapped in the following cases:
                                                                        * When AP_HCR_EL2[TGE] == 0, when the instruction is executed at
                                                                          EL0, EL1 or EL2 unless the instruction is trapped to EL1 as
                                                                          a result of the AP_CPACR_EL1[FPEN] bit.
                                                                        * When AP_HCR_EL2[TGE] == 1, when the instruction is executed at
                                                                          EL0 or EL2.

                                                                 0x1 = This field value causes any instructions executed at EL0 that use
                                                                      the registerss associated with Floating Point or Advanced SIMD
                                                                      execution to be trapped when AP_HCR_EL2[TGE]==1 only.  It does not
                                                                      cause any instruction executed at EL1 or EL2 to be trapped and
                                                                      it does not cause any instruction to be trapped when AP_HCR_EL2[TGE]==0.

                                                                 0x2 = This field value causes any instructions that use the registers
                                                                      associated with Floating Point and Advanced SIMD execution to be
                                                                      trapped in the following cases:
                                                                        * When AP_HCR_EL2[TGE] == 0, when the instruction is executed at
                                                                          EL0, EL1 or EL2 unless the instruction is trapped to EL2 as
                                                                          a result of the AP_CPACR_EL1[FPEN] bit.
                                                                        * When AP_HCR_EL2[TGE] == 1, when the instruction is executed at
                                                                          EL0 or EL2.

                                                                 0x3 = This field value does not cause any instruction to be trapped. */
		uint32_t reserved_0_19               : 20;
#else
		uint32_t reserved_0_19               : 20;
		uint32_t fpen                        : 2;
		uint32_t reserved_22_30              : 9;
		uint32_t tcpac                       : 1;
#endif
	} s;
	/* struct bdk_ap_cptr_el2_e2h_s       cn88xx; */
	/* struct bdk_ap_cptr_el2_e2h_s       cn88xxp1; */
} bdk_ap_cptr_el2_e2h_t;

#define BDK_AP_CPTR_EL2_E2H BDK_AP_CPTR_EL2_E2H_FUNC()
static inline uint64_t BDK_AP_CPTR_EL2_E2H_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CPTR_EL2_E2H_FUNC(void)
{
	return 0x0000030401010210ull;
}
#define typedef_BDK_AP_CPTR_EL2_E2H bdk_ap_cptr_el2_e2h_t
#define bustype_BDK_AP_CPTR_EL2_E2H BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CPTR_EL2_E2H 0
#define arguments_BDK_AP_CPTR_EL2_E2H -1,-1,-1,-1
#define basename_BDK_AP_CPTR_EL2_E2H "AP_CPTR_EL2_E2H"


/**
 * SYSREG - ap_cptr_el3
 *
 * Controls trapping to EL3 of access to AP_CPACR_EL1, Trace
 * functionality and registers associated with Floating Point and
 * Advanced SIMD execution. Also controls EL3 access to this
 * functionality.
 */
typedef union bdk_ap_cptr_el3 {
	uint32_t u;
	struct bdk_ap_cptr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tcpac                       : 1;  /**< R/W - This causes a direct access to the AP_CPACR_EL1 from EL1 or the
                                                                     AP_CPTR_EL2 from EL2 to trap to EL3 unless it is trapped at EL2.

                                                                 0 = Does not cause access to the AP_CPACR_EL1 or AP_CPTR_EL2 to be
                                                                     trapped.
                                                                 1 = Causes access to the AP_CPACR_EL1 or AP_CPTR_EL2 to be trapped. */
		uint32_t reserved_11_30              : 20;
		uint32_t tfp                         : 1;  /**< R/W - This causes instructions that access the registers associated
                                                                     with Floating Point and Advanced SIMD execution to trap to EL3
                                                                     when executed from any Exception level, unless trapped to EL1
                                                                     or EL2.
                                                                 0 = Does not cause any instruction to be trapped.
                                                                 1 = Causes any instructions that use the registers associated with
                                                                     Floating Point and Advanced SIMD execution to be trapped. */
		uint32_t reserved_0_9                : 10;
#else
		uint32_t reserved_0_9                : 10;
		uint32_t tfp                         : 1;
		uint32_t reserved_11_30              : 20;
		uint32_t tcpac                       : 1;
#endif
	} s;
	/* struct bdk_ap_cptr_el3_s           cn88xx; */
	/* struct bdk_ap_cptr_el3_s           cn88xxp1; */
} bdk_ap_cptr_el3_t;

#define BDK_AP_CPTR_EL3 BDK_AP_CPTR_EL3_FUNC()
static inline uint64_t BDK_AP_CPTR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CPTR_EL3_FUNC(void)
{
	return 0x0000030601010200ull;
}
#define typedef_BDK_AP_CPTR_EL3 bdk_ap_cptr_el3_t
#define bustype_BDK_AP_CPTR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CPTR_EL3 0
#define arguments_BDK_AP_CPTR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CPTR_EL3 "AP_CPTR_EL3"


/**
 * SYSREG - ap_csselr_el1
 *
 * Selects the current Cache Size ID Register, AP_CCSIDR_EL1, by
 * specifying the required cache level and the cache type (either
 * instruction or data cache).
 */
typedef union bdk_ap_csselr_el1 {
	uint32_t u;
	struct bdk_ap_csselr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t level                       : 3;  /**< R/W - Cache level of required cache. */
		uint32_t ind                         : 1;  /**< R/W - Instruction not Data bit.
                                                                 0 = Data or unified cache.
                                                                 1 = Instruction cache. */
#else
		uint32_t ind                         : 1;
		uint32_t level                       : 3;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_ap_csselr_el1_s         cn88xx; */
	/* struct bdk_ap_csselr_el1_s         cn88xxp1; */
} bdk_ap_csselr_el1_t;

#define BDK_AP_CSSELR_EL1 BDK_AP_CSSELR_EL1_FUNC()
static inline uint64_t BDK_AP_CSSELR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CSSELR_EL1_FUNC(void)
{
	return 0x0000030200000000ull;
}
#define typedef_BDK_AP_CSSELR_EL1 bdk_ap_csselr_el1_t
#define bustype_BDK_AP_CSSELR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CSSELR_EL1 0
#define arguments_BDK_AP_CSSELR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CSSELR_EL1 "AP_CSSELR_EL1"


/**
 * SYSREG - ap_ctr_el0
 *
 * This register provides information about the architecture of the caches.
 *
 */
typedef union bdk_ap_ctr_el0 {
	uint32_t u;
	struct bdk_ap_ctr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rsvd_31                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_28_30              : 3;
		uint32_t cwg                         : 4;  /**< RO - Cache writeback granule. Log2 of the number of
                                                                    words of the maximum size of memory that can be overwritten as
                                                                    a result of the eviction of a cache entry that has had a
                                                                    memory location in it modified.

                                                                 The architectural maximum of 512 words (2KB) must be assumed.

                                                                 The cache writeback granule can be determined from maximum
                                                                    cache line size encoded in the Cache Size ID Registers. */
		uint32_t erg                         : 4;  /**< RO - Exclusives reservation granule. Log2 of the number
                                                                 of words of the maximum size of the reservation granule that
                                                                 has been implemented for the Load-Exclusive and
                                                                 Store-Exclusive instructions. */
		uint32_t dminline                    : 4;  /**< RO - Log2 of the number of words in the smallest cache
                                                                     line of all the data caches and unified caches that are
                                                                     controlled by the PE.

                                                                 For CNXXXX, 128 bytes. */
		uint32_t l1ip                        : 2;  /**< RO - Level 1 instruction cache policy. Indicates the indexing and
                                                                     tagging policy for the L1 instruction cache.

                                                                 0x1 = ASID-tagged virtual index, virtual tag (AIVIVT).
                                                                 0x2 = Virtual index, physical tag (VIPT).
                                                                 0x3 = Physical index, physical tag (PIPT). */
		uint32_t reserved_4_13               : 10;
		uint32_t iminline                    : 4;  /**< RO - Log2 of the number of words in the smallest cache line of all the instruction
                                                                 caches that are controlled by the PE.

                                                                 For CNXXXX, 128 bytes. */
#else
		uint32_t iminline                    : 4;
		uint32_t reserved_4_13               : 10;
		uint32_t l1ip                        : 2;
		uint32_t dminline                    : 4;
		uint32_t erg                         : 4;
		uint32_t cwg                         : 4;
		uint32_t reserved_28_30              : 3;
		uint32_t rsvd_31                     : 1;
#endif
	} s;
	/* struct bdk_ap_ctr_el0_s            cn88xx; */
	/* struct bdk_ap_ctr_el0_s            cn88xxp1; */
} bdk_ap_ctr_el0_t;

#define BDK_AP_CTR_EL0 BDK_AP_CTR_EL0_FUNC()
static inline uint64_t BDK_AP_CTR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CTR_EL0_FUNC(void)
{
	return 0x0000030300000100ull;
}
#define typedef_BDK_AP_CTR_EL0 bdk_ap_ctr_el0_t
#define bustype_BDK_AP_CTR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CTR_EL0 0
#define arguments_BDK_AP_CTR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_CTR_EL0 "AP_CTR_EL0"


/**
 * SYSREG - ap_currentel
 *
 * Holds the current Exception level.
 *
 */
typedef union bdk_ap_currentel {
	uint32_t u;
	struct bdk_ap_currentel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t el                          : 2;  /**< RO - Current Exception level.
                                                                 0x0 = EL0.
                                                                 0x1 = EL1.
                                                                 0x2 = EL2.
                                                                 0x3 = EL3. */
		uint32_t reserved_0_1                : 2;
#else
		uint32_t reserved_0_1                : 2;
		uint32_t el                          : 2;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_ap_currentel_s          cn88xx; */
	/* struct bdk_ap_currentel_s          cn88xxp1; */
} bdk_ap_currentel_t;

#define BDK_AP_CURRENTEL BDK_AP_CURRENTEL_FUNC()
static inline uint64_t BDK_AP_CURRENTEL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CURRENTEL_FUNC(void)
{
	return 0x0000030004020200ull;
}
#define typedef_BDK_AP_CURRENTEL bdk_ap_currentel_t
#define bustype_BDK_AP_CURRENTEL BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CURRENTEL 0
#define arguments_BDK_AP_CURRENTEL -1,-1,-1,-1
#define basename_BDK_AP_CURRENTEL "AP_CURRENTEL"


/**
 * SYSREG - ap_cvm_access_el1
 *
 * This register controls trapping on register accesses.
 *
 * Read/write access at EL1, EL2 and EL3.
 *
 * Note that AP_HCR_EL2[TIDCP] can also prevent all CVM* access at EL1
 * and below and takes priority over AP_CVM_ACCESS_EL1.
 *
 * Note that AP_CVM_ACCESS_EL1 can grant access to EL0 for AP_CVM_*_EL1
 * registers. This is non standard. A some point AP_CVM_ACCESS_EL1 may be
 * depreciated.
 *
 * A 1 in the appropriate bit in the AP_CVM_ACCESS_ELn register prevents
 * any access at lower exception levels.
 *
 * INTERNAL: If access is denied at multiple exception levels then the
 * trap occurs at the lowest. This is similar to ARM's
 * AP_CPACR_EL1/AP_CPTR_EL2/AP_CPTR_EL3.
 */
typedef union bdk_ap_cvm_access_el1 {
	uint64_t u;
	struct bdk_ap_cvm_access_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t cvm_cache                   : 1;  /**< R/W - A Cvm_Cache instruction with the exception level lower than 1 traps to EL1 unless
                                                                 AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then EL2. */
		uint64_t reserved_6_7                : 2;
		uint64_t cvm_evattid                 : 1;  /**< R/W - A read operation to AP_CVM_EVATTID with the exception level lower than 1 traps
                                                                 to EL1 unless AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then EL2. */
		uint64_t cvm_i_d_cache               : 1;  /**< R/W - A read or write operation to AP_CVM_Icache* or AP_CVM_Dcache* with the exception
                                                                 level lower than 1 traps to EL1 unless AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then
                                                                 EL2. */
		uint64_t cvm_err                     : 1;  /**< R/W - A read or write operation to AP_CVM_ERR* with the exception level lower than 1
                                                                 traps to EL1 unless AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then EL2. */
		uint64_t cvm_bist                    : 1;  /**< R/W - A read or write operation to AP_CVM_BIST* with the exception level lower than 1
                                                                 traps to EL1 unless AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then EL2. */
		uint64_t powthrottle                 : 1;  /**< R/W - A read or write operation to PowThrottle with the exception level lower than 1
                                                                 traps to EL1 unless AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then EL2. */
		uint64_t cvm_ctl                     : 1;  /**< R/W - A read or write operation to AP_CVM_CTL or AP_CVM_MEMCTL with the exception
                                                                 level lower than 1 traps to EL1 unless AP_HCR_EL2[TGE] && !AP_SCR_EL3[NS], then
                                                                 EL2. */
#else
		uint64_t cvm_ctl                     : 1;
		uint64_t powthrottle                 : 1;
		uint64_t cvm_bist                    : 1;
		uint64_t cvm_err                     : 1;
		uint64_t cvm_i_d_cache               : 1;
		uint64_t cvm_evattid                 : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t cvm_cache                   : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ap_cvm_access_el1_s     cn88xx; */
	/* struct bdk_ap_cvm_access_el1_s     cn88xxp1; */
} bdk_ap_cvm_access_el1_t;

#define BDK_AP_CVM_ACCESS_EL1 BDK_AP_CVM_ACCESS_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_ACCESS_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ACCESS_EL1_FUNC(void)
{
	return 0x000003000B000300ull;
}
#define typedef_BDK_AP_CVM_ACCESS_EL1 bdk_ap_cvm_access_el1_t
#define bustype_BDK_AP_CVM_ACCESS_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ACCESS_EL1 0
#define arguments_BDK_AP_CVM_ACCESS_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ACCESS_EL1 "AP_CVM_ACCESS_EL1"


/**
 * SYSREG - ap_cvm_access_el2
 *
 * This register controls trap/access of Cavium registers. Read/write access at EL2 and EL3.
 *
 */
typedef union bdk_ap_cvm_access_el2 {
	uint64_t u;
	struct bdk_ap_cvm_access_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t cvm_cache                   : 1;  /**< R/W - A Cvm_Cache instruction with the exception level lower than 2 traps to EL2 unless
                                                                 prohibited by AP_CVM_ACCESS_EL1 or AP_SCR_EL3[NS] = 0. */
		uint64_t reserved_6_7                : 2;
		uint64_t cvm_evattid                 : 1;  /**< R/W - A read operation to AP_CVM_EVATTID with the exception level lower than 2 traps
                                                                 to EL2 unless prohibited by AP_CVM_ACCESS_EL1 or AP_SCR_EL3[NS] = 0. */
		uint64_t cvm_i_d_cache               : 1;  /**< R/W - A read or write operation to AP_CVM_Icache* or AP_CVM_Dcache* with the exception
                                                                 level lower than 2 traps to EL2 unless prohibited by AP_CVM_ACCESS_EL1 or
                                                                 AP_SCR_EL3[NS] = 0. */
		uint64_t cvm_err                     : 1;  /**< R/W - A read or write operation to AP_CVM_ERR* with the exception level lower than 2
                                                                 traps to EL2 unless prohibited by AP_CVM_ACCESS_EL1 or AP_SCR_EL3[NS] = 0. */
		uint64_t cvm_bist                    : 1;  /**< R/W - A read or write operation to AP_CVM_BIST* with the exception level lower than 2
                                                                 traps to EL2 unless prohibited by AP_CVM_ACCESS_EL1 or AP_SCR_EL3[NS] = 0. */
		uint64_t powthrottle                 : 1;  /**< R/W - A read or write operation to PowThrottle with the exception level lower than 2 traps to
                                                                 EL2 unless prohibited by AP_CVM_ACCESS_EL1 or AP_SCR_EL3[NS] = 0. */
		uint64_t cvm_ctl                     : 1;  /**< R/W - A read or write operation to AP_CVM_CTL or AP_CVM_MEMCTL with the exception
                                                                 level lower than 2 traps to EL2 unless prohibited by AP_CVM_ACCESS_EL1 or
                                                                 AP_SCR_EL3[NS] = 0. */
#else
		uint64_t cvm_ctl                     : 1;
		uint64_t powthrottle                 : 1;
		uint64_t cvm_bist                    : 1;
		uint64_t cvm_err                     : 1;
		uint64_t cvm_i_d_cache               : 1;
		uint64_t cvm_evattid                 : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t cvm_cache                   : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ap_cvm_access_el2_s     cn88xx; */
	/* struct bdk_ap_cvm_access_el2_s     cn88xxp1; */
} bdk_ap_cvm_access_el2_t;

#define BDK_AP_CVM_ACCESS_EL2 BDK_AP_CVM_ACCESS_EL2_FUNC()
static inline uint64_t BDK_AP_CVM_ACCESS_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ACCESS_EL2_FUNC(void)
{
	return 0x000003040B000300ull;
}
#define typedef_BDK_AP_CVM_ACCESS_EL2 bdk_ap_cvm_access_el2_t
#define bustype_BDK_AP_CVM_ACCESS_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ACCESS_EL2 0
#define arguments_BDK_AP_CVM_ACCESS_EL2 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ACCESS_EL2 "AP_CVM_ACCESS_EL2"


/**
 * SYSREG - ap_cvm_access_el3
 *
 * INTERNAL: Software should expose the CvmCACHE instruction to EL2 or
 * EL1 with extreme caution. Exposing this instruction to lower
 * exception levels may cause non-secure state to mess with secure
 * state, which would cause a security hole.
 */
typedef union bdk_ap_cvm_access_el3 {
	uint64_t u;
	struct bdk_ap_cvm_access_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t cvm_cache                   : 1;  /**< R/W - A Cvm_Cache instruction with the exception level lower than 3 traps to EL3 unles */
		uint64_t reserved_6_7                : 2;
		uint64_t cvm_evattid                 : 1;  /**< R/W - A read or write operation to AP_CVM_EVATTID with the exception level lower than 3 traps to
                                                                 EL3 unless prohibited by AP_CVM_ACCESS_EL2, AP_CVM_ACCESS_EL1, or AP_HCR_EL2[TIDCP]. */
		uint64_t cvm_i_d_cache               : 1;  /**< R/W - A read or write operation to AP_CVM_ICACHE* or AP_CVM_DCACHE* with the exception level
                                                                 lower
                                                                 than 3 traps to EL3 unless prohibited by AP_CVM_ACCESS_EL2, AP_CVM_ACCESS_EL1, or
                                                                 AP_HCR_EL2[TIDCP]. */
		uint64_t cvm_err                     : 1;  /**< R/W - A read or write operation to AP_CVM_ERR* with the exception level lower than 3 traps to
                                                                 EL3
                                                                 unless prohibited by AP_CVM_ACCESS_EL2, AP_CVM_ACCESS_EL1, or AP_HCR_EL2[TIDCP]. */
		uint64_t cvm_bist                    : 1;  /**< R/W - A read or write operation to AP_CVM_BIST* with the exception level lower than 3 traps to
                                                                 EL3
                                                                 unless prohibited by AP_CVM_ACCESS_EL2, AP_CVM_ACCESS_EL1, or AP_HCR_EL2[TIDCP]. */
		uint64_t powthrottle                 : 1;  /**< R/W - A read or write operation to PowThrottle with the exception level lower than 3 traps to
                                                                 EL3 unless prohibited by AP_CVM_ACCESS_EL2, AP_CVM_ACCESS_EL1, or AP_HCR_EL2[TIDCP]. */
		uint64_t cvm_ctl                     : 1;  /**< R/W - A read or write operation to AP_CVM_CTL or AP_CVM_MEMCTL with the exception
                                                                 level lower than 3 traps to EL3 unless prohibited by AP_CVM_ACCESS_EL2,
                                                                 AP_CVM_ACCESS_EL1, or AP_HCR_EL2[TIDCP]. */
#else
		uint64_t cvm_ctl                     : 1;
		uint64_t powthrottle                 : 1;
		uint64_t cvm_bist                    : 1;
		uint64_t cvm_err                     : 1;
		uint64_t cvm_i_d_cache               : 1;
		uint64_t cvm_evattid                 : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t cvm_cache                   : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ap_cvm_access_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_access_el3_s     cn88xxp1; */
} bdk_ap_cvm_access_el3_t;

#define BDK_AP_CVM_ACCESS_EL3 BDK_AP_CVM_ACCESS_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_ACCESS_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ACCESS_EL3_FUNC(void)
{
	return 0x000003060B000300ull;
}
#define typedef_BDK_AP_CVM_ACCESS_EL3 bdk_ap_cvm_access_el3_t
#define bustype_BDK_AP_CVM_ACCESS_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ACCESS_EL3 0
#define arguments_BDK_AP_CVM_ACCESS_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ACCESS_EL3 "AP_CVM_ACCESS_EL3"


/**
 * SYSREG - ap_cvm_bist0_el1
 *
 * This register indicates BIST status, where a 1 in a bit position indicates defective.
 *
 */
typedef union bdk_ap_cvm_bist0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_bist0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_35_63              : 29;
		uint64_t fuse_controller_reports_hard_repair : 1;/**< RO - Fuse controller reports hard repair. */
		uint64_t clear_bist_was_run          : 1;  /**< RO - Clear BIST was run. */
		uint64_t manufacturing_mode          : 1;  /**< RO - Manufacturing mode. */
		uint64_t icache_data_banks_with_unrepairable_defects : 8;/**< RO - Icache data banks with unrepairable defects. */
		uint64_t icache_data_banks_with_defects : 8;/**< RO - Icache data banks with defects. */
		uint64_t reserved_8_15               : 8;
		uint64_t aes_roms_defective          : 1;  /**< RO - AES ROMs defective. */
		uint64_t fpu_roms_defective          : 1;  /**< RO - FPU ROMs defective. */
		uint64_t fpu_rf_defective            : 1;  /**< RO - FPU/SIMD RF defective. */
		uint64_t integer_rf_defective        : 1;  /**< RO - Integer RF defective. */
		uint64_t jrt_defective               : 1;  /**< RO - JRT defective. */
		uint64_t bht_defective               : 1;  /**< RO - BHT defective. */
		uint64_t icache_tag_defective        : 1;  /**< RO - Icache tag defective. */
		uint64_t icache_data_defective       : 1;  /**< RO - Icache data defective/unrepairable. */
#else
		uint64_t icache_data_defective       : 1;
		uint64_t icache_tag_defective        : 1;
		uint64_t bht_defective               : 1;
		uint64_t jrt_defective               : 1;
		uint64_t integer_rf_defective        : 1;
		uint64_t fpu_rf_defective            : 1;
		uint64_t fpu_roms_defective          : 1;
		uint64_t aes_roms_defective          : 1;
		uint64_t reserved_8_15               : 8;
		uint64_t icache_data_banks_with_defects : 8;
		uint64_t icache_data_banks_with_unrepairable_defects : 8;
		uint64_t manufacturing_mode          : 1;
		uint64_t clear_bist_was_run          : 1;
		uint64_t fuse_controller_reports_hard_repair : 1;
		uint64_t reserved_35_63              : 29;
#endif
	} s;
	/* struct bdk_ap_cvm_bist0_el1_s      cn88xx; */
	/* struct bdk_ap_cvm_bist0_el1_s      cn88xxp1; */
} bdk_ap_cvm_bist0_el1_t;

#define BDK_AP_CVM_BIST0_EL1 BDK_AP_CVM_BIST0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_BIST0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_BIST0_EL1_FUNC(void)
{
	return 0x000003000B010000ull;
}
#define typedef_BDK_AP_CVM_BIST0_EL1 bdk_ap_cvm_bist0_el1_t
#define bustype_BDK_AP_CVM_BIST0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_BIST0_EL1 0
#define arguments_BDK_AP_CVM_BIST0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_BIST0_EL1 "AP_CVM_BIST0_EL1"


/**
 * SYSREG - ap_cvm_bist1_el1
 *
 * This register indicates BIST status, where a 1 in a bit position indicates defective.
 *
 */
typedef union bdk_ap_cvm_bist1_el1 {
	uint64_t u;
	struct bdk_ap_cvm_bist1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t icache_bank7                : 6;  /**< RO - Icache bank7 bad set, 0x3F means no defect. */
		uint64_t icache_bank6                : 6;  /**< RO - Icache bank6 bad set, 0x3F means no defect. */
		uint64_t icache_bank5                : 6;  /**< RO - Icache bank5 bad set, 0x3F means no defect. */
		uint64_t icache_bank4                : 6;  /**< RO - Icache bank4 bad set, 0x3F means no defect. */
		uint64_t icache_bank3                : 6;  /**< RO - Icache bank3 bad set, 0x3F means no defect. */
		uint64_t icache_bank2                : 6;  /**< RO - Icache bank2 bad set, 0x3F means no defect. */
		uint64_t icache_bank1                : 6;  /**< RO - Icache bank1 bad set, 0x3F means no defect. */
		uint64_t icache_bank0                : 6;  /**< RO - Icache bank0 bad set, 0x3F means no defect. */
#else
		uint64_t icache_bank0                : 6;
		uint64_t icache_bank1                : 6;
		uint64_t icache_bank2                : 6;
		uint64_t icache_bank3                : 6;
		uint64_t icache_bank4                : 6;
		uint64_t icache_bank5                : 6;
		uint64_t icache_bank6                : 6;
		uint64_t icache_bank7                : 6;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_cvm_bist1_el1_s      cn88xx; */
	/* struct bdk_ap_cvm_bist1_el1_s      cn88xxp1; */
} bdk_ap_cvm_bist1_el1_t;

#define BDK_AP_CVM_BIST1_EL1 BDK_AP_CVM_BIST1_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_BIST1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_BIST1_EL1_FUNC(void)
{
	return 0x000003000B010100ull;
}
#define typedef_BDK_AP_CVM_BIST1_EL1 bdk_ap_cvm_bist1_el1_t
#define bustype_BDK_AP_CVM_BIST1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_BIST1_EL1 0
#define arguments_BDK_AP_CVM_BIST1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_BIST1_EL1 "AP_CVM_BIST1_EL1"


/**
 * SYSREG - ap_cvm_bist2_el1
 *
 * This register indicates BIST status, where a 1 in a bit position indicates defective.
 *
 */
typedef union bdk_ap_cvm_bist2_el1 {
	uint64_t u;
	struct bdk_ap_cvm_bist2_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t wcu                         : 1;  /**< RO - WCU defective. */
		uint64_t dut                         : 1;  /**< RO - DUT defective. */
		uint64_t wbf                         : 1;  /**< RO - WBF defective. */
		uint64_t maf                         : 1;  /**< RO - MAF defective. */
		uint64_t utlb                        : 1;  /**< RO - UTLB defective. */
		uint64_t mtlb                        : 1;  /**< RO - MTLB defective. */
		uint64_t l1dp                        : 1;  /**< RO - Dcache PTAG defective. */
		uint64_t l1dv                        : 1;  /**< RO - Dcache VTAG defective. */
		uint64_t l1dd                        : 1;  /**< RO - Dcache Data defective. */
#else
		uint64_t l1dd                        : 1;
		uint64_t l1dv                        : 1;
		uint64_t l1dp                        : 1;
		uint64_t mtlb                        : 1;
		uint64_t utlb                        : 1;
		uint64_t maf                         : 1;
		uint64_t wbf                         : 1;
		uint64_t dut                         : 1;
		uint64_t wcu                         : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ap_cvm_bist2_el1_s      cn88xx; */
	/* struct bdk_ap_cvm_bist2_el1_s      cn88xxp1; */
} bdk_ap_cvm_bist2_el1_t;

#define BDK_AP_CVM_BIST2_EL1 BDK_AP_CVM_BIST2_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_BIST2_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_BIST2_EL1_FUNC(void)
{
	return 0x000003000B010400ull;
}
#define typedef_BDK_AP_CVM_BIST2_EL1 bdk_ap_cvm_bist2_el1_t
#define bustype_BDK_AP_CVM_BIST2_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_BIST2_EL1 0
#define arguments_BDK_AP_CVM_BIST2_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_BIST2_EL1 "AP_CVM_BIST2_EL1"


/**
 * SYSREG - ap_cvm_bist3_el1
 *
 * This register indicates BIST status, where a 1 in a bit position indicates defective.
 *
 */
typedef union bdk_ap_cvm_bist3_el1 {
	uint64_t u;
	struct bdk_ap_cvm_bist3_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t set7                        : 6;  /**< RO - Dcache set7 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set6                        : 6;  /**< RO - Dcache set6 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set5                        : 6;  /**< RO - Dcache set5 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set4                        : 6;  /**< RO - Dcache set4 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set3                        : 6;  /**< RO - Dcache set3 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set2                        : 6;  /**< RO - Dcache set2 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set1                        : 6;  /**< RO - Dcache set1 bad way, 0x3F = no defect, 0x3E = multiple defects. */
		uint64_t set0                        : 6;  /**< RO - Dcache set0 bad way, 0x3F = no defect, 0x3E = multiple defects. */
#else
		uint64_t set0                        : 6;
		uint64_t set1                        : 6;
		uint64_t set2                        : 6;
		uint64_t set3                        : 6;
		uint64_t set4                        : 6;
		uint64_t set5                        : 6;
		uint64_t set6                        : 6;
		uint64_t set7                        : 6;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_cvm_bist3_el1_s      cn88xx; */
	/* struct bdk_ap_cvm_bist3_el1_s      cn88xxp1; */
} bdk_ap_cvm_bist3_el1_t;

#define BDK_AP_CVM_BIST3_EL1 BDK_AP_CVM_BIST3_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_BIST3_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_BIST3_EL1_FUNC(void)
{
	return 0x000003000B010500ull;
}
#define typedef_BDK_AP_CVM_BIST3_EL1 bdk_ap_cvm_bist3_el1_t
#define bustype_BDK_AP_CVM_BIST3_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_BIST3_EL1 0
#define arguments_BDK_AP_CVM_BIST3_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_BIST3_EL1 "AP_CVM_BIST3_EL1"


/**
 * SYSREG - ap_cvm_dcachedata0_el1
 */
typedef union bdk_ap_cvm_dcachedata0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_dcachedata0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO - Dcache data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_dcachedata0_el1_s cn88xx; */
	/* struct bdk_ap_cvm_dcachedata0_el1_s cn88xxp1; */
} bdk_ap_cvm_dcachedata0_el1_t;

#define BDK_AP_CVM_DCACHEDATA0_EL1 BDK_AP_CVM_DCACHEDATA0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_DCACHEDATA0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DCACHEDATA0_EL1_FUNC(void)
{
	return 0x000003000B030400ull;
}
#define typedef_BDK_AP_CVM_DCACHEDATA0_EL1 bdk_ap_cvm_dcachedata0_el1_t
#define bustype_BDK_AP_CVM_DCACHEDATA0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DCACHEDATA0_EL1 0
#define arguments_BDK_AP_CVM_DCACHEDATA0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DCACHEDATA0_EL1 "AP_CVM_DCACHEDATA0_EL1"


/**
 * SYSREG - ap_cvm_dcachedata1_el1
 */
typedef union bdk_ap_cvm_dcachedata1_el1 {
	uint64_t u;
	struct bdk_ap_cvm_dcachedata1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t parity                      : 8;  /**< RO - Parity bits. */
#else
		uint64_t parity                      : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_ap_cvm_dcachedata1_el1_s cn88xx; */
	/* struct bdk_ap_cvm_dcachedata1_el1_s cn88xxp1; */
} bdk_ap_cvm_dcachedata1_el1_t;

#define BDK_AP_CVM_DCACHEDATA1_EL1 BDK_AP_CVM_DCACHEDATA1_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_DCACHEDATA1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DCACHEDATA1_EL1_FUNC(void)
{
	return 0x000003000B030500ull;
}
#define typedef_BDK_AP_CVM_DCACHEDATA1_EL1 bdk_ap_cvm_dcachedata1_el1_t
#define bustype_BDK_AP_CVM_DCACHEDATA1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DCACHEDATA1_EL1 0
#define arguments_BDK_AP_CVM_DCACHEDATA1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DCACHEDATA1_EL1 "AP_CVM_DCACHEDATA1_EL1"


/**
 * SYSREG - ap_cvm_dcacheptag0_el1
 */
typedef union bdk_ap_cvm_dcacheptag0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_dcacheptag0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t nsec                        : 1;  /**< RO - Not-shared. */
		uint64_t ptag                        : 33; /**< RO - Physical tag \<42:10\>. */
		uint64_t reserved_1_9                : 9;
		uint64_t valid                       : 1;  /**< RO - Valid. */
#else
		uint64_t valid                       : 1;
		uint64_t reserved_1_9                : 9;
		uint64_t ptag                        : 33;
		uint64_t nsec                        : 1;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_ap_cvm_dcacheptag0_el1_s cn88xx; */
	/* struct bdk_ap_cvm_dcacheptag0_el1_s cn88xxp1; */
} bdk_ap_cvm_dcacheptag0_el1_t;

#define BDK_AP_CVM_DCACHEPTAG0_EL1 BDK_AP_CVM_DCACHEPTAG0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_DCACHEPTAG0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DCACHEPTAG0_EL1_FUNC(void)
{
	return 0x000003000B040400ull;
}
#define typedef_BDK_AP_CVM_DCACHEPTAG0_EL1 bdk_ap_cvm_dcacheptag0_el1_t
#define bustype_BDK_AP_CVM_DCACHEPTAG0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DCACHEPTAG0_EL1 0
#define arguments_BDK_AP_CVM_DCACHEPTAG0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DCACHEPTAG0_EL1 "AP_CVM_DCACHEPTAG0_EL1"


/**
 * SYSREG - ap_cvm_dcachevtag0_el1
 */
typedef union bdk_ap_cvm_dcachevtag0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_dcachevtag0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t eva_vmid                    : 4;  /**< RO - Entry EVA_VMID. */
		uint64_t reserved_49_55              : 7;
		uint64_t r                           : 1;  /**< RO - Entry R. */
		uint64_t vtag                        : 38; /**< RO - Entry VTAG\<47:10\>. */
		uint64_t eva_asid                    : 6;  /**< RO - Entry EVA_ASID. */
		uint64_t ng                          : 1;  /**< RO - Entry NG. */
		uint64_t el_1or0                     : 1;  /**< RO - Entry is EL0 or EL1. */
		uint64_t nsec                        : 1;  /**< RO - Entry is NS. */
		uint64_t valid                       : 1;  /**< RO - Entry valid. */
#else
		uint64_t valid                       : 1;
		uint64_t nsec                        : 1;
		uint64_t el_1or0                     : 1;
		uint64_t ng                          : 1;
		uint64_t eva_asid                    : 6;
		uint64_t vtag                        : 38;
		uint64_t r                           : 1;
		uint64_t reserved_49_55              : 7;
		uint64_t eva_vmid                    : 4;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_ap_cvm_dcachevtag0_el1_s cn88xx; */
	/* struct bdk_ap_cvm_dcachevtag0_el1_s cn88xxp1; */
} bdk_ap_cvm_dcachevtag0_el1_t;

#define BDK_AP_CVM_DCACHEVTAG0_EL1 BDK_AP_CVM_DCACHEVTAG0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_DCACHEVTAG0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DCACHEVTAG0_EL1_FUNC(void)
{
	return 0x000003000B030600ull;
}
#define typedef_BDK_AP_CVM_DCACHEVTAG0_EL1 bdk_ap_cvm_dcachevtag0_el1_t
#define bustype_BDK_AP_CVM_DCACHEVTAG0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DCACHEVTAG0_EL1 0
#define arguments_BDK_AP_CVM_DCACHEVTAG0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DCACHEVTAG0_EL1 "AP_CVM_DCACHEVTAG0_EL1"


/**
 * SYSREG - ap_cvm_dcachevtag1_el1
 */
typedef union bdk_ap_cvm_dcachevtag1_el1 {
	uint64_t u;
	struct bdk_ap_cvm_dcachevtag1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t ent1                        : 9;  /**< RO - ENT1. */
		uint64_t reserved_9_15               : 7;
		uint64_t ent2                        : 9;  /**< RO - ENT2. */
#else
		uint64_t ent2                        : 9;
		uint64_t reserved_9_15               : 7;
		uint64_t ent1                        : 9;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_ap_cvm_dcachevtag1_el1_s cn88xx; */
	/* struct bdk_ap_cvm_dcachevtag1_el1_s cn88xxp1; */
} bdk_ap_cvm_dcachevtag1_el1_t;

#define BDK_AP_CVM_DCACHEVTAG1_EL1 BDK_AP_CVM_DCACHEVTAG1_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_DCACHEVTAG1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DCACHEVTAG1_EL1_FUNC(void)
{
	return 0x000003000B030700ull;
}
#define typedef_BDK_AP_CVM_DCACHEVTAG1_EL1 bdk_ap_cvm_dcachevtag1_el1_t
#define bustype_BDK_AP_CVM_DCACHEVTAG1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DCACHEVTAG1_EL1 0
#define arguments_BDK_AP_CVM_DCACHEVTAG1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DCACHEVTAG1_EL1 "AP_CVM_DCACHEVTAG1_EL1"


/**
 * SYSREG - ap_cvm_debug0_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug0_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug0_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t current_pc                  : 64; /**< RO - Current PC. */
#else
		uint64_t current_pc                  : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_debug0_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug0_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug0_el3_t;

#define BDK_AP_CVM_DEBUG0_EL3 BDK_AP_CVM_DEBUG0_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG0_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG0_EL3_FUNC(void)
{
	return 0x000003060B040000ull;
}
#define typedef_BDK_AP_CVM_DEBUG0_EL3 bdk_ap_cvm_debug0_el3_t
#define bustype_BDK_AP_CVM_DEBUG0_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG0_EL3 0
#define arguments_BDK_AP_CVM_DEBUG0_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG0_EL3 "AP_CVM_DEBUG0_EL3"


/**
 * SYSREG - ap_cvm_debug1_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug1_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug1_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t current_fetch               : 64; /**< RO - Current fetcher address. */
#else
		uint64_t current_fetch               : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_debug1_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug1_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug1_el3_t;

#define BDK_AP_CVM_DEBUG1_EL3 BDK_AP_CVM_DEBUG1_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG1_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG1_EL3_FUNC(void)
{
	return 0x000003060B040100ull;
}
#define typedef_BDK_AP_CVM_DEBUG1_EL3 bdk_ap_cvm_debug1_el3_t
#define bustype_BDK_AP_CVM_DEBUG1_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG1_EL3 0
#define arguments_BDK_AP_CVM_DEBUG1_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG1_EL3 "AP_CVM_DEBUG1_EL3"


/**
 * SYSREG - ap_cvm_debug2_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug2_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug2_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t last_ifill                  : 64; /**< RO - Last ifill address. */
#else
		uint64_t last_ifill                  : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_debug2_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug2_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug2_el3_t;

#define BDK_AP_CVM_DEBUG2_EL3 BDK_AP_CVM_DEBUG2_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG2_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG2_EL3_FUNC(void)
{
	return 0x000003060B040200ull;
}
#define typedef_BDK_AP_CVM_DEBUG2_EL3 bdk_ap_cvm_debug2_el3_t
#define bustype_BDK_AP_CVM_DEBUG2_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG2_EL3 0
#define arguments_BDK_AP_CVM_DEBUG2_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG2_EL3 "AP_CVM_DEBUG2_EL3"


/**
 * SYSREG - ap_cvm_debug3_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug3_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug3_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t last_committed              : 64; /**< RO - Last committed instruction PC. */
#else
		uint64_t last_committed              : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_debug3_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug3_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug3_el3_t;

#define BDK_AP_CVM_DEBUG3_EL3 BDK_AP_CVM_DEBUG3_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG3_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG3_EL3_FUNC(void)
{
	return 0x000003060B040300ull;
}
#define typedef_BDK_AP_CVM_DEBUG3_EL3 bdk_ap_cvm_debug3_el3_t
#define bustype_BDK_AP_CVM_DEBUG3_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG3_EL3 0
#define arguments_BDK_AP_CVM_DEBUG3_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG3_EL3 "AP_CVM_DEBUG3_EL3"


/**
 * SYSREG - ap_cvm_debug4_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug4_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug4_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t dual_issue_reason           : 8;  /**< RO - Reason dual issue didn't occur. */
		uint64_t issue_reason                : 8;  /**< RO - Reason issue didn't occur. */
		uint64_t reserved_5_7                : 3;
		uint64_t mem_stall_4a                : 1;  /**< RO - Memory Stall stage 4a. */
		uint64_t waiting_for_pfill_4a        : 1;  /**< RO - Waiting for PFILL stage 4a. */
		uint64_t waiting_for_ifill_4a        : 1;  /**< RO - Waiting for IFILL stage 4a. */
		uint64_t exception_level             : 2;  /**< RO - Current exception level. */
#else
		uint64_t exception_level             : 2;
		uint64_t waiting_for_ifill_4a        : 1;
		uint64_t waiting_for_pfill_4a        : 1;
		uint64_t mem_stall_4a                : 1;
		uint64_t reserved_5_7                : 3;
		uint64_t issue_reason                : 8;
		uint64_t dual_issue_reason           : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_ap_cvm_debug4_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug4_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug4_el3_t;

#define BDK_AP_CVM_DEBUG4_EL3 BDK_AP_CVM_DEBUG4_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG4_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG4_EL3_FUNC(void)
{
	return 0x000003060B050000ull;
}
#define typedef_BDK_AP_CVM_DEBUG4_EL3 bdk_ap_cvm_debug4_el3_t
#define bustype_BDK_AP_CVM_DEBUG4_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG4_EL3 0
#define arguments_BDK_AP_CVM_DEBUG4_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG4_EL3 "AP_CVM_DEBUG4_EL3"


/**
 * SYSREG - ap_cvm_debug6_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug6_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug6_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_41_63              : 23;
		uint64_t power_off                   : 1;
		uint64_t power_longterm              : 8;
		uint64_t power_setting               : 8;
		uint64_t reserved_22_23              : 2;
		uint64_t interval_power              : 22;
#else
		uint64_t interval_power              : 22;
		uint64_t reserved_22_23              : 2;
		uint64_t power_setting               : 8;
		uint64_t power_longterm              : 8;
		uint64_t power_off                   : 1;
		uint64_t reserved_41_63              : 23;
#endif
	} s;
	/* struct bdk_ap_cvm_debug6_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug6_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug6_el3_t;

#define BDK_AP_CVM_DEBUG6_EL3 BDK_AP_CVM_DEBUG6_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG6_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG6_EL3_FUNC(void)
{
	return 0x000003060B050200ull;
}
#define typedef_BDK_AP_CVM_DEBUG6_EL3 bdk_ap_cvm_debug6_el3_t
#define bustype_BDK_AP_CVM_DEBUG6_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG6_EL3 0
#define arguments_BDK_AP_CVM_DEBUG6_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG6_EL3 "AP_CVM_DEBUG6_EL3"


/**
 * SYSREG - ap_cvm_debug7_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug7_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug7_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_debug7_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug7_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug7_el3_t;

#define BDK_AP_CVM_DEBUG7_EL3 BDK_AP_CVM_DEBUG7_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG7_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG7_EL3_FUNC(void)
{
	return 0x000003060B050300ull;
}
#define typedef_BDK_AP_CVM_DEBUG7_EL3 bdk_ap_cvm_debug7_el3_t
#define bustype_BDK_AP_CVM_DEBUG7_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG7_EL3 0
#define arguments_BDK_AP_CVM_DEBUG7_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG7_EL3 "AP_CVM_DEBUG7_EL3"


/**
 * SYSREG - ap_cvm_debug8_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug8_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug8_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rdb_dsc_set_arry_1          : 18; /**< RO - Bits 17..0 of rdb_dsc_set_arry[1]. */
		uint64_t rdb_dsc_set_arry_0          : 36; /**< RO - Rdb_dsc_set_arry[0]. */
		uint64_t uwr_ack_def_cnt             : 2;  /**< RO - Upstream write message ack count. */
		uint64_t sgi_ack_def_cnt             : 2;  /**< RO - SGI generate message ack count. */
		uint64_t dct_ack_def_cnt             : 2;  /**< RO - Deactivate message ack count. */
		uint64_t act_ack_def_cnt             : 2;  /**< RO - Activate message ack count. */
		uint64_t clr_ack_def_cnt             : 2;  /**< RO - Clear message ack count. */
#else
		uint64_t clr_ack_def_cnt             : 2;
		uint64_t act_ack_def_cnt             : 2;
		uint64_t dct_ack_def_cnt             : 2;
		uint64_t sgi_ack_def_cnt             : 2;
		uint64_t uwr_ack_def_cnt             : 2;
		uint64_t rdb_dsc_set_arry_0          : 36;
		uint64_t rdb_dsc_set_arry_1          : 18;
#endif
	} s;
	/* struct bdk_ap_cvm_debug8_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug8_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug8_el3_t;

#define BDK_AP_CVM_DEBUG8_EL3 BDK_AP_CVM_DEBUG8_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG8_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG8_EL3_FUNC(void)
{
	return 0x000003060B070000ull;
}
#define typedef_BDK_AP_CVM_DEBUG8_EL3 bdk_ap_cvm_debug8_el3_t
#define bustype_BDK_AP_CVM_DEBUG8_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG8_EL3 0
#define arguments_BDK_AP_CVM_DEBUG8_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG8_EL3 "AP_CVM_DEBUG8_EL3"


/**
 * SYSREG - ap_cvm_debug9_el3
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_debug9_el3 {
	uint64_t u;
	struct bdk_ap_cvm_debug9_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t dsc_fsm_enc_state_1         : 4;  /**< RO - DSC FSM ENC state\<1\>. */
		uint64_t dsc_fsm_enc_state_0         : 4;  /**< RO - DSC FSM ENC state\<0\>. */
		uint64_t clr_fsm_enc_state           : 3;  /**< RO - CLR FSM ENC state. */
		uint64_t qsc_fsm_enc_state           : 3;  /**< RO - QSC FSM ENC state. */
		uint64_t dsc_fifo                    : 4;  /**< RO - DSC FIFO. */
		uint64_t ppi_fifo                    : 4;  /**< RO - PPI FIFO. */
		uint64_t cdc_fifo                    : 4;  /**< RO - CDC FIFO. */
		uint64_t eac_fifo                    : 4;  /**< RO - EAC FIFO. */
		uint64_t rdb_dsc_set_arry_1          : 18; /**< RO - rdb_dsc_set_arry[1]\<35:18\>. */
#else
		uint64_t rdb_dsc_set_arry_1          : 18;
		uint64_t eac_fifo                    : 4;
		uint64_t cdc_fifo                    : 4;
		uint64_t ppi_fifo                    : 4;
		uint64_t dsc_fifo                    : 4;
		uint64_t qsc_fsm_enc_state           : 3;
		uint64_t clr_fsm_enc_state           : 3;
		uint64_t dsc_fsm_enc_state_0         : 4;
		uint64_t dsc_fsm_enc_state_1         : 4;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_cvm_debug9_el3_s     cn88xx; */
	/* struct bdk_ap_cvm_debug9_el3_s     cn88xxp1; */
} bdk_ap_cvm_debug9_el3_t;

#define BDK_AP_CVM_DEBUG9_EL3 BDK_AP_CVM_DEBUG9_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DEBUG9_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DEBUG9_EL3_FUNC(void)
{
	return 0x000003060B070100ull;
}
#define typedef_BDK_AP_CVM_DEBUG9_EL3 bdk_ap_cvm_debug9_el3_t
#define bustype_BDK_AP_CVM_DEBUG9_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DEBUG9_EL3 0
#define arguments_BDK_AP_CVM_DEBUG9_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DEBUG9_EL3 "AP_CVM_DEBUG9_EL3"


/**
 * SYSREG - ap_cvm_dll_observabilty_el3
 */
typedef union bdk_ap_cvm_dll_observabilty_el3 {
	uint64_t u;
	struct bdk_ap_cvm_dll_observabilty_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t max_seen                    : 12; /**< RO - Maximum setting seen. */
		uint64_t min_seen                    : 12; /**< RO - Minimum setting seen. */
		uint64_t rclk_dll_lock               : 1;  /**< RO - rclk_dll__lock. */
		uint64_t dll_state                   : 3;  /**< RO - dll_state\<2:0\>. */
		uint64_t dll_setting                 : 12; /**< RO - dll_setting\<11:0\>. */
		uint64_t raw_dly_elem_enable         : 16; /**< RO - raw_dly_elem_enable\<15:0\>. */
		uint64_t clk_invert                  : 1;  /**< RO - clk_invert. */
		uint64_t pd_pos_rclk_refclk          : 1;  /**< RO - pd_pos_rclk_refclk. */
		uint64_t pdl_rclk_refclk             : 1;  /**< RO - pdl_rclk_refclk. */
		uint64_t pdr_rclk_refclk             : 1;  /**< RO - pdr_rclk_refclk. */
#else
		uint64_t pdr_rclk_refclk             : 1;
		uint64_t pdl_rclk_refclk             : 1;
		uint64_t pd_pos_rclk_refclk          : 1;
		uint64_t clk_invert                  : 1;
		uint64_t raw_dly_elem_enable         : 16;
		uint64_t dll_setting                 : 12;
		uint64_t dll_state                   : 3;
		uint64_t rclk_dll_lock               : 1;
		uint64_t min_seen                    : 12;
		uint64_t max_seen                    : 12;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_ap_cvm_dll_observabilty_el3_s cn88xx; */
	/* struct bdk_ap_cvm_dll_observabilty_el3_s cn88xxp1; */
} bdk_ap_cvm_dll_observabilty_el3_t;

#define BDK_AP_CVM_DLL_OBSERVABILTY_EL3 BDK_AP_CVM_DLL_OBSERVABILTY_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_DLL_OBSERVABILTY_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_DLL_OBSERVABILTY_EL3_FUNC(void)
{
	return 0x000003060B050100ull;
}
#define typedef_BDK_AP_CVM_DLL_OBSERVABILTY_EL3 bdk_ap_cvm_dll_observabilty_el3_t
#define bustype_BDK_AP_CVM_DLL_OBSERVABILTY_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_DLL_OBSERVABILTY_EL3 0
#define arguments_BDK_AP_CVM_DLL_OBSERVABILTY_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_DLL_OBSERVABILTY_EL3 "AP_CVM_DLL_OBSERVABILTY_EL3"


/**
 * SYSREG - ap_cvm_erricache_el1
 */
typedef union bdk_ap_cvm_erricache_el1 {
	uint64_t u;
	struct bdk_ap_cvm_erricache_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t set                         : 6;  /**< R/W - Set which had the parity error. */
		uint64_t va                          : 8;  /**< R/W - VA\<10:3\> of address which had the parity error. */
		uint64_t reserved_1_2                : 2;
		uint64_t icache_data_error           : 1;  /**< R/W - Icache data error. */
#else
		uint64_t icache_data_error           : 1;
		uint64_t reserved_1_2                : 2;
		uint64_t va                          : 8;
		uint64_t set                         : 6;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_ap_cvm_erricache_el1_s  cn88xx; */
	/* struct bdk_ap_cvm_erricache_el1_s  cn88xxp1; */
} bdk_ap_cvm_erricache_el1_t;

#define BDK_AP_CVM_ERRICACHE_EL1 BDK_AP_CVM_ERRICACHE_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_ERRICACHE_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ERRICACHE_EL1_FUNC(void)
{
	return 0x000003000B020000ull;
}
#define typedef_BDK_AP_CVM_ERRICACHE_EL1 bdk_ap_cvm_erricache_el1_t
#define bustype_BDK_AP_CVM_ERRICACHE_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ERRICACHE_EL1 0
#define arguments_BDK_AP_CVM_ERRICACHE_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ERRICACHE_EL1 "AP_CVM_ERRICACHE_EL1"


/**
 * SYSREG - ap_cvm_errmem_el1
 */
typedef union bdk_ap_cvm_errmem_el1 {
	uint64_t u;
	struct bdk_ap_cvm_errmem_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t gsynctonosw                 : 1;  /**< R/W - Global sync timeout, no report to software. Added in CN88XX pass 2. */
		uint64_t gsynctodis                  : 1;  /**< R/W - Global sync timeout disable. Added in CN88XX pass 2. */
		uint64_t gsyncto                     : 1;  /**< R/W - Global sync timeout. Added in CN88XX pass 2. */
		uint64_t wcumultdis                  : 1;  /**< R/W - WCU multiple match error disable. */
		uint64_t wcumult                     : 1;  /**< R/W - WCU multiple match error. */
		uint64_t mtlbmultdis                 : 1;  /**< R/W - MTLB multiple match error disable. */
		uint64_t mtlbmult                    : 1;  /**< R/W - MTLB multiple match error. */
		uint64_t barriertoforce              : 1;  /**< R/W - Barrier timeout force. Bit is cleared when error is forced. */
		uint64_t barriertonosw               : 1;  /**< R/W - Barrier timeout, no report to software. */
		uint64_t barriertodis                : 1;  /**< R/W - Barrier timeout disable. */
		uint64_t barrierto                   : 1;  /**< R/W - Barrier timeout. */
		uint64_t rbftoforce                  : 1;  /**< R/W - Read buffer timeout force. Bit is cleared when error is forced. */
		uint64_t rbftonosw                   : 1;  /**< R/W - Read buffer timeout, no report to software. */
		uint64_t rbftodis                    : 1;  /**< R/W - Read buffer timeout disable. */
		uint64_t rbfto                       : 1;  /**< R/W - Read buffer timeout. */
		uint64_t wcuperrforce                : 1;  /**< R/W - WCU parity error force. Bit is cleared when error is forced on next write operation. */
		uint64_t wcuperrnosw                 : 1;  /**< R/W - WCU parity error, no report to software. */
		uint64_t wcuperrdis                  : 1;  /**< R/W - WCU parity error disable. */
		uint64_t wcuperr                     : 1;  /**< R/W - WCU parity error. */
		uint64_t wbfdbeforce                 : 1;  /**< R/W - Write-buffer DBE force. Bit is cleared when error is forced on next write operation. */
		uint64_t wbfsbeforce                 : 1;  /**< R/W - Write-buffer SBE force. Bit is cleared when error is forced on next write operation. */
		uint64_t wbfperrnosw                 : 1;  /**< R/W - Write-buffer parity error, no report to software. */
		uint64_t wbfperrdis                  : 1;  /**< R/W - Write-buffer parity error disable. */
		uint64_t wbfperr                     : 1;  /**< R/W - Write-buffer parity error. */
		uint64_t mafperrforce                : 1;  /**< R/W - MAF parity error force. Bit is cleared when error is forced on next write operation. */
		uint64_t mafperrnosw                 : 1;  /**< R/W - MAF parity error, no report to software. */
		uint64_t mafperrdis                  : 1;  /**< R/W - MAF parity error disable. */
		uint64_t mafperr                     : 1;  /**< R/W - MAF parity error. */
		uint64_t utlbperrforce               : 1;  /**< R/W - uTLB parity error force. Bit is cleared when error is forced on next write operation. */
		uint64_t utlbperrnosw                : 1;  /**< R/W - uTLB parity error, no report to software. */
		uint64_t utlbperrdis                 : 1;  /**< R/W - uTLB parity error disable. */
		uint64_t utlbperr                    : 1;  /**< R/W - uTLB parity error. */
		uint64_t mtlbperrforce               : 1;  /**< R/W - MTLB parity error force. Bit is cleared when error is forced on next write operation. */
		uint64_t mtlbperrnosw                : 1;  /**< R/W - MTLB parity error, no report to software. */
		uint64_t mtlbperrdis                 : 1;  /**< R/W - MTLB parity error disable. */
		uint64_t mtlbperr                    : 1;  /**< R/W - MTLB parity error. */
		uint64_t l1dperrforce                : 1;  /**< R/W - Dcache parity error force. Bit is cleared when error is forced on next write operation. */
		uint64_t l1dperrnosw                 : 1;  /**< R/W - Dcache parity error, no report to software. */
		uint64_t l1dperrdis                  : 1;  /**< R/W - Dcache parity error disable. */
		uint64_t l1dperr                     : 1;  /**< R/W - Dcache parity error. */
		uint64_t l1dway                      : 5;  /**< R/W - Indicates Dcache way. */
		uint64_t l1dset                      : 3;  /**< R/W - Indicates Dcache set. */
#else
		uint64_t l1dset                      : 3;
		uint64_t l1dway                      : 5;
		uint64_t l1dperr                     : 1;
		uint64_t l1dperrdis                  : 1;
		uint64_t l1dperrnosw                 : 1;
		uint64_t l1dperrforce                : 1;
		uint64_t mtlbperr                    : 1;
		uint64_t mtlbperrdis                 : 1;
		uint64_t mtlbperrnosw                : 1;
		uint64_t mtlbperrforce               : 1;
		uint64_t utlbperr                    : 1;
		uint64_t utlbperrdis                 : 1;
		uint64_t utlbperrnosw                : 1;
		uint64_t utlbperrforce               : 1;
		uint64_t mafperr                     : 1;
		uint64_t mafperrdis                  : 1;
		uint64_t mafperrnosw                 : 1;
		uint64_t mafperrforce                : 1;
		uint64_t wbfperr                     : 1;
		uint64_t wbfperrdis                  : 1;
		uint64_t wbfperrnosw                 : 1;
		uint64_t wbfsbeforce                 : 1;
		uint64_t wbfdbeforce                 : 1;
		uint64_t wcuperr                     : 1;
		uint64_t wcuperrdis                  : 1;
		uint64_t wcuperrnosw                 : 1;
		uint64_t wcuperrforce                : 1;
		uint64_t rbfto                       : 1;
		uint64_t rbftodis                    : 1;
		uint64_t rbftonosw                   : 1;
		uint64_t rbftoforce                  : 1;
		uint64_t barrierto                   : 1;
		uint64_t barriertodis                : 1;
		uint64_t barriertonosw               : 1;
		uint64_t barriertoforce              : 1;
		uint64_t mtlbmult                    : 1;
		uint64_t mtlbmultdis                 : 1;
		uint64_t wcumult                     : 1;
		uint64_t wcumultdis                  : 1;
		uint64_t gsyncto                     : 1;
		uint64_t gsynctodis                  : 1;
		uint64_t gsynctonosw                 : 1;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_cvm_errmem_el1_s     cn88xx; */
	/* struct bdk_ap_cvm_errmem_el1_s     cn88xxp1; */
} bdk_ap_cvm_errmem_el1_t;

#define BDK_AP_CVM_ERRMEM_EL1 BDK_AP_CVM_ERRMEM_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_ERRMEM_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ERRMEM_EL1_FUNC(void)
{
	return 0x000003000B020400ull;
}
#define typedef_BDK_AP_CVM_ERRMEM_EL1 bdk_ap_cvm_errmem_el1_t
#define bustype_BDK_AP_CVM_ERRMEM_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ERRMEM_EL1 0
#define arguments_BDK_AP_CVM_ERRMEM_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ERRMEM_EL1 "AP_CVM_ERRMEM_EL1"


/**
 * SYSREG - ap_cvm_evattid_el1
 *
 * This register is for diagnostic use only.
 *
 */
typedef union bdk_ap_cvm_evattid_el1 {
	uint64_t u;
	struct bdk_ap_cvm_evattid_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26;
		uint64_t el2_asid                    : 6;  /**< R/W - Current EL2 EVA ASID. */
		uint64_t reserved_20_31              : 12;
		uint64_t el1_vmid                    : 4;  /**< R/W - Current EL1 EVA VMID. */
		uint64_t reserved_6_15               : 10;
		uint64_t el1_asid                    : 6;  /**< R/W - Current EL1 EVA ASID. */
#else
		uint64_t el1_asid                    : 6;
		uint64_t reserved_6_15               : 10;
		uint64_t el1_vmid                    : 4;
		uint64_t reserved_20_31              : 12;
		uint64_t el2_asid                    : 6;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
	/* struct bdk_ap_cvm_evattid_el1_s    cn88xx; */
	/* struct bdk_ap_cvm_evattid_el1_s    cn88xxp1; */
} bdk_ap_cvm_evattid_el1_t;

#define BDK_AP_CVM_EVATTID_EL1 BDK_AP_CVM_EVATTID_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_EVATTID_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_EVATTID_EL1_FUNC(void)
{
	return 0x000003000B020500ull;
}
#define typedef_BDK_AP_CVM_EVATTID_EL1 bdk_ap_cvm_evattid_el1_t
#define bustype_BDK_AP_CVM_EVATTID_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_EVATTID_EL1 0
#define arguments_BDK_AP_CVM_EVATTID_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_EVATTID_EL1 "AP_CVM_EVATTID_EL1"


/**
 * SYSREG - ap_cvm_icachedata0_el1
 */
typedef union bdk_ap_cvm_icachedata0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_icachedata0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO - Icache data\<63:0\> from an Icache read operation. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_icachedata0_el1_s cn88xx; */
	/* struct bdk_ap_cvm_icachedata0_el1_s cn88xxp1; */
} bdk_ap_cvm_icachedata0_el1_t;

#define BDK_AP_CVM_ICACHEDATA0_EL1 BDK_AP_CVM_ICACHEDATA0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_ICACHEDATA0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ICACHEDATA0_EL1_FUNC(void)
{
	return 0x000003000B030000ull;
}
#define typedef_BDK_AP_CVM_ICACHEDATA0_EL1 bdk_ap_cvm_icachedata0_el1_t
#define bustype_BDK_AP_CVM_ICACHEDATA0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ICACHEDATA0_EL1 0
#define arguments_BDK_AP_CVM_ICACHEDATA0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ICACHEDATA0_EL1 "AP_CVM_ICACHEDATA0_EL1"


/**
 * SYSREG - ap_cvm_icachedata1_el1
 */
typedef union bdk_ap_cvm_icachedata1_el1 {
	uint64_t u;
	struct bdk_ap_cvm_icachedata1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t data                        : 2;  /**< RO - Icache data\<65:64\> from an Icache read operation. */
#else
		uint64_t data                        : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ap_cvm_icachedata1_el1_s cn88xx; */
	/* struct bdk_ap_cvm_icachedata1_el1_s cn88xxp1; */
} bdk_ap_cvm_icachedata1_el1_t;

#define BDK_AP_CVM_ICACHEDATA1_EL1 BDK_AP_CVM_ICACHEDATA1_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_ICACHEDATA1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ICACHEDATA1_EL1_FUNC(void)
{
	return 0x000003000B030100ull;
}
#define typedef_BDK_AP_CVM_ICACHEDATA1_EL1 bdk_ap_cvm_icachedata1_el1_t
#define bustype_BDK_AP_CVM_ICACHEDATA1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ICACHEDATA1_EL1 0
#define arguments_BDK_AP_CVM_ICACHEDATA1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ICACHEDATA1_EL1 "AP_CVM_ICACHEDATA1_EL1"


/**
 * SYSREG - ap_cvm_icachetag0_el1
 */
typedef union bdk_ap_cvm_icachetag0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_icachetag0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t valid                       : 1;  /**< RO - Valid. */
		uint64_t va                          : 40; /**< RO - VA in tags. */
		uint64_t asid_valid_ignored          : 1;  /**< RO - ASID valid is ignored. */
		uint64_t asid_index                  : 6;  /**< RO - ASID index. */
		uint64_t vmid_index                  : 4;  /**< RO - VMID index. */
#else
		uint64_t vmid_index                  : 4;
		uint64_t asid_index                  : 6;
		uint64_t asid_valid_ignored          : 1;
		uint64_t va                          : 40;
		uint64_t valid                       : 1;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_ap_cvm_icachetag0_el1_s cn88xx; */
	/* struct bdk_ap_cvm_icachetag0_el1_s cn88xxp1; */
} bdk_ap_cvm_icachetag0_el1_t;

#define BDK_AP_CVM_ICACHETAG0_EL1 BDK_AP_CVM_ICACHETAG0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_ICACHETAG0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_ICACHETAG0_EL1_FUNC(void)
{
	return 0x000003000B030200ull;
}
#define typedef_BDK_AP_CVM_ICACHETAG0_EL1 bdk_ap_cvm_icachetag0_el1_t
#define bustype_BDK_AP_CVM_ICACHETAG0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_ICACHETAG0_EL1 0
#define arguments_BDK_AP_CVM_ICACHETAG0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_ICACHETAG0_EL1 "AP_CVM_ICACHETAG0_EL1"


/**
 * SYSREG - ap_cvm_memdebug0_el3
 */
typedef union bdk_ap_cvm_memdebug0_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug0_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug0_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug0_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug0_el3_t;

#define BDK_AP_CVM_MEMDEBUG0_EL3 BDK_AP_CVM_MEMDEBUG0_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG0_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG0_EL3_FUNC(void)
{
	return 0x000003060B040400ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG0_EL3 bdk_ap_cvm_memdebug0_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG0_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG0_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG0_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG0_EL3 "AP_CVM_MEMDEBUG0_EL3"


/**
 * SYSREG - ap_cvm_memdebug1_el3
 */
typedef union bdk_ap_cvm_memdebug1_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug1_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug1_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug1_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug1_el3_t;

#define BDK_AP_CVM_MEMDEBUG1_EL3 BDK_AP_CVM_MEMDEBUG1_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG1_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG1_EL3_FUNC(void)
{
	return 0x000003060B040500ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG1_EL3 bdk_ap_cvm_memdebug1_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG1_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG1_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG1_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG1_EL3 "AP_CVM_MEMDEBUG1_EL3"


/**
 * SYSREG - ap_cvm_memdebug2_el3
 */
typedef union bdk_ap_cvm_memdebug2_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug2_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug2_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug2_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug2_el3_t;

#define BDK_AP_CVM_MEMDEBUG2_EL3 BDK_AP_CVM_MEMDEBUG2_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG2_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG2_EL3_FUNC(void)
{
	return 0x000003060B040600ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG2_EL3 bdk_ap_cvm_memdebug2_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG2_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG2_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG2_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG2_EL3 "AP_CVM_MEMDEBUG2_EL3"


/**
 * SYSREG - ap_cvm_memdebug3_el3
 */
typedef union bdk_ap_cvm_memdebug3_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug3_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug3_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug3_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug3_el3_t;

#define BDK_AP_CVM_MEMDEBUG3_EL3 BDK_AP_CVM_MEMDEBUG3_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG3_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG3_EL3_FUNC(void)
{
	return 0x000003060B040700ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG3_EL3 bdk_ap_cvm_memdebug3_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG3_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG3_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG3_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG3_EL3 "AP_CVM_MEMDEBUG3_EL3"


/**
 * SYSREG - ap_cvm_memdebug4_el3
 */
typedef union bdk_ap_cvm_memdebug4_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug4_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug4_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug4_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug4_el3_t;

#define BDK_AP_CVM_MEMDEBUG4_EL3 BDK_AP_CVM_MEMDEBUG4_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG4_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG4_EL3_FUNC(void)
{
	return 0x000003060B050400ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG4_EL3 bdk_ap_cvm_memdebug4_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG4_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG4_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG4_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG4_EL3 "AP_CVM_MEMDEBUG4_EL3"


/**
 * SYSREG - ap_cvm_memdebug5_el3
 */
typedef union bdk_ap_cvm_memdebug5_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug5_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug5_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug5_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug5_el3_t;

#define BDK_AP_CVM_MEMDEBUG5_EL3 BDK_AP_CVM_MEMDEBUG5_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG5_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG5_EL3_FUNC(void)
{
	return 0x000003060B050500ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG5_EL3 bdk_ap_cvm_memdebug5_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG5_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG5_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG5_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG5_EL3 "AP_CVM_MEMDEBUG5_EL3"


/**
 * SYSREG - ap_cvm_memdebug6_el3
 */
typedef union bdk_ap_cvm_memdebug6_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug6_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug6_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug6_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug6_el3_t;

#define BDK_AP_CVM_MEMDEBUG6_EL3 BDK_AP_CVM_MEMDEBUG6_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG6_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG6_EL3_FUNC(void)
{
	return 0x000003060B050600ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG6_EL3 bdk_ap_cvm_memdebug6_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG6_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG6_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG6_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG6_EL3 "AP_CVM_MEMDEBUG6_EL3"


/**
 * SYSREG - ap_cvm_memdebug7_el3
 */
typedef union bdk_ap_cvm_memdebug7_el3 {
	uint64_t u;
	struct bdk_ap_cvm_memdebug7_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t debug                       : 64; /**< RO - Undocumented debug. */
#else
		uint64_t debug                       : 64;
#endif
	} s;
	/* struct bdk_ap_cvm_memdebug7_el3_s  cn88xx; */
	/* struct bdk_ap_cvm_memdebug7_el3_s  cn88xxp1; */
} bdk_ap_cvm_memdebug7_el3_t;

#define BDK_AP_CVM_MEMDEBUG7_EL3 BDK_AP_CVM_MEMDEBUG7_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_MEMDEBUG7_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_MEMDEBUG7_EL3_FUNC(void)
{
	return 0x000003060B050700ull;
}
#define typedef_BDK_AP_CVM_MEMDEBUG7_EL3 bdk_ap_cvm_memdebug7_el3_t
#define bustype_BDK_AP_CVM_MEMDEBUG7_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_MEMDEBUG7_EL3 0
#define arguments_BDK_AP_CVM_MEMDEBUG7_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_MEMDEBUG7_EL3 "AP_CVM_MEMDEBUG7_EL3"


/**
 * SYSREG - ap_cvm_nvbar_el3
 */
typedef union bdk_ap_cvm_nvbar_el3 {
	uint64_t u;
	struct bdk_ap_cvm_nvbar_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t vector_address              : 53; /**< R/W - Cavium-specific exception vector address. */
		uint64_t reserved_0_10               : 11;
#else
		uint64_t reserved_0_10               : 11;
		uint64_t vector_address              : 53;
#endif
	} s;
	/* struct bdk_ap_cvm_nvbar_el3_s      cn88xx; */
	/* struct bdk_ap_cvm_nvbar_el3_s      cn88xxp1; */
} bdk_ap_cvm_nvbar_el3_t;

#define BDK_AP_CVM_NVBAR_EL3 BDK_AP_CVM_NVBAR_EL3_FUNC()
static inline uint64_t BDK_AP_CVM_NVBAR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_NVBAR_EL3_FUNC(void)
{
	return 0x000003060B060000ull;
}
#define typedef_BDK_AP_CVM_NVBAR_EL3 bdk_ap_cvm_nvbar_el3_t
#define bustype_BDK_AP_CVM_NVBAR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_NVBAR_EL3 0
#define arguments_BDK_AP_CVM_NVBAR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_CVM_NVBAR_EL3 "AP_CVM_NVBAR_EL3"


/**
 * SYSREG - ap_cvm_power_el1
 *
 * This register controls power management.
 * Resets to 0x2ffff00.
 */
typedef union bdk_ap_cvm_power_el1 {
	uint64_t u;
	struct bdk_ap_cvm_power_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t maxpow                      : 8;  /**< R/W - Maximum power. */
		uint64_t average_power               : 8;  /**< R/W - Average power. */
		uint64_t current_setting             : 8;  /**< R/W - Current setting. */
		uint64_t hrm_adjustment              : 8;  /**< R/W - HRM adjustment. */
		uint64_t reserved_29_31              : 3;
		uint64_t secret_override             : 1;  /**< R/W - Secret override. */
		uint64_t disable_stagger             : 1;  /**< R/W - Disable stagger. */
		uint64_t period                      : 3;  /**< R/W - Period. */
		uint64_t powlim                      : 8;  /**< R/W - Power limit. */
		uint64_t max_setting                 : 8;  /**< R/W - Maximum setting. */
		uint64_t min_setting                 : 8;  /**< R/W - Minimum setting. */
#else
		uint64_t min_setting                 : 8;
		uint64_t max_setting                 : 8;
		uint64_t powlim                      : 8;
		uint64_t period                      : 3;
		uint64_t disable_stagger             : 1;
		uint64_t secret_override             : 1;
		uint64_t reserved_29_31              : 3;
		uint64_t hrm_adjustment              : 8;
		uint64_t current_setting             : 8;
		uint64_t average_power               : 8;
		uint64_t maxpow                      : 8;
#endif
	} s;
	/* struct bdk_ap_cvm_power_el1_s      cn88xx; */
	/* struct bdk_ap_cvm_power_el1_s      cn88xxp1; */
} bdk_ap_cvm_power_el1_t;

#define BDK_AP_CVM_POWER_EL1 BDK_AP_CVM_POWER_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_POWER_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_POWER_EL1_FUNC(void)
{
	return 0x000003000B000200ull;
}
#define typedef_BDK_AP_CVM_POWER_EL1 bdk_ap_cvm_power_el1_t
#define bustype_BDK_AP_CVM_POWER_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_POWER_EL1 0
#define arguments_BDK_AP_CVM_POWER_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_POWER_EL1 "AP_CVM_POWER_EL1"


/**
 * SYSREG - ap_cvm_xlatdata0_el1
 */
typedef union bdk_ap_cvm_xlatdata0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_xlatdata0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t par                         : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_54_61              : 8;
		uint64_t walk                        : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t ng                          : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_50_50              : 1;
		uint64_t nsec                        : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_48_48              : 1;
		uint64_t ppn                         : 36; /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_10_11              : 2;
		uint64_t sh1                         : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t ap1                         : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t xn1                         : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t pxn1                        : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t attr1                       : 4;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
#else
		uint64_t attr1                       : 4;
		uint64_t pxn1                        : 1;
		uint64_t xn1                         : 1;
		uint64_t ap1                         : 2;
		uint64_t sh1                         : 2;
		uint64_t reserved_10_11              : 2;
		uint64_t ppn                         : 36;
		uint64_t reserved_48_48              : 1;
		uint64_t nsec                        : 1;
		uint64_t reserved_50_50              : 1;
		uint64_t ng                          : 1;
		uint64_t walk                        : 2;
		uint64_t reserved_54_61              : 8;
		uint64_t par                         : 2;
#endif
	} s;
	/* struct bdk_ap_cvm_xlatdata0_el1_s  cn88xx; */
	/* struct bdk_ap_cvm_xlatdata0_el1_s  cn88xxp1; */
} bdk_ap_cvm_xlatdata0_el1_t;

#define BDK_AP_CVM_XLATDATA0_EL1 BDK_AP_CVM_XLATDATA0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_XLATDATA0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_XLATDATA0_EL1_FUNC(void)
{
	return 0x000003000B050400ull;
}
#define typedef_BDK_AP_CVM_XLATDATA0_EL1 bdk_ap_cvm_xlatdata0_el1_t
#define bustype_BDK_AP_CVM_XLATDATA0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_XLATDATA0_EL1 0
#define arguments_BDK_AP_CVM_XLATDATA0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_XLATDATA0_EL1 "AP_CVM_XLATDATA0_EL1"


/**
 * SYSREG - ap_cvm_xlatdata1_el1
 */
typedef union bdk_ap_cvm_xlatdata1_el1 {
	uint64_t u;
	struct bdk_ap_cvm_xlatdata1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_63              : 1;
		uint64_t ent2                        : 9;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_45_53              : 9;
		uint64_t ent1                        : 9;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_34_35              : 2;
		uint64_t mask                        : 22; /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_10_11              : 2;
		uint64_t sh2                         : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t ap2                         : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t xn2                         : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t pxn2                        : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t attr2                       : 4;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
#else
		uint64_t attr2                       : 4;
		uint64_t pxn2                        : 1;
		uint64_t xn2                         : 1;
		uint64_t ap2                         : 2;
		uint64_t sh2                         : 2;
		uint64_t reserved_10_11              : 2;
		uint64_t mask                        : 22;
		uint64_t reserved_34_35              : 2;
		uint64_t ent1                        : 9;
		uint64_t reserved_45_53              : 9;
		uint64_t ent2                        : 9;
		uint64_t reserved_63_63              : 1;
#endif
	} s;
	/* struct bdk_ap_cvm_xlatdata1_el1_s  cn88xx; */
	/* struct bdk_ap_cvm_xlatdata1_el1_s  cn88xxp1; */
} bdk_ap_cvm_xlatdata1_el1_t;

#define BDK_AP_CVM_XLATDATA1_EL1 BDK_AP_CVM_XLATDATA1_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_XLATDATA1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_XLATDATA1_EL1_FUNC(void)
{
	return 0x000003000B050500ull;
}
#define typedef_BDK_AP_CVM_XLATDATA1_EL1 bdk_ap_cvm_xlatdata1_el1_t
#define bustype_BDK_AP_CVM_XLATDATA1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_XLATDATA1_EL1 0
#define arguments_BDK_AP_CVM_XLATDATA1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_XLATDATA1_EL1 "AP_CVM_XLATDATA1_EL1"


/**
 * SYSREG - ap_cvm_xlatvtag0_el1
 */
typedef union bdk_ap_cvm_xlatvtag0_el1 {
	uint64_t u;
	struct bdk_ap_cvm_xlatvtag0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t level                       : 2;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t eva_asid                    : 6;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t eva_vmid                    : 4;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t ng                          : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t el_1or0                     : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t nsec                        : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t r                           : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t vpn                         : 36; /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_1_11               : 11;
		uint64_t val                         : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
#else
		uint64_t val                         : 1;
		uint64_t reserved_1_11               : 11;
		uint64_t vpn                         : 36;
		uint64_t r                           : 1;
		uint64_t nsec                        : 1;
		uint64_t el_1or0                     : 1;
		uint64_t ng                          : 1;
		uint64_t eva_vmid                    : 4;
		uint64_t eva_asid                    : 6;
		uint64_t level                       : 2;
#endif
	} s;
	/* struct bdk_ap_cvm_xlatvtag0_el1_s  cn88xx; */
	/* struct bdk_ap_cvm_xlatvtag0_el1_s  cn88xxp1; */
} bdk_ap_cvm_xlatvtag0_el1_t;

#define BDK_AP_CVM_XLATVTAG0_EL1 BDK_AP_CVM_XLATVTAG0_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_XLATVTAG0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_XLATVTAG0_EL1_FUNC(void)
{
	return 0x000003000B050600ull;
}
#define typedef_BDK_AP_CVM_XLATVTAG0_EL1 bdk_ap_cvm_xlatvtag0_el1_t
#define bustype_BDK_AP_CVM_XLATVTAG0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_XLATVTAG0_EL1 0
#define arguments_BDK_AP_CVM_XLATVTAG0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_XLATVTAG0_EL1 "AP_CVM_XLATVTAG0_EL1"


/**
 * SYSREG - ap_cvm_xlatvtag1_el1
 */
typedef union bdk_ap_cvm_xlatvtag1_el1 {
	uint64_t u;
	struct bdk_ap_cvm_xlatvtag1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t ent2                        : 9;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_45_47              : 3;
		uint64_t ent1                        : 9;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_34_35              : 2;
		uint64_t mask                        : 22; /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t reserved_2_11               : 10;
		uint64_t stage2                      : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
		uint64_t stage1                      : 1;  /**< RO - SYS[CvmCACHE] debug read data from uTLB/MTLB/WCU. */
#else
		uint64_t stage1                      : 1;
		uint64_t stage2                      : 1;
		uint64_t reserved_2_11               : 10;
		uint64_t mask                        : 22;
		uint64_t reserved_34_35              : 2;
		uint64_t ent1                        : 9;
		uint64_t reserved_45_47              : 3;
		uint64_t ent2                        : 9;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_ap_cvm_xlatvtag1_el1_s  cn88xx; */
	/* struct bdk_ap_cvm_xlatvtag1_el1_s  cn88xxp1; */
} bdk_ap_cvm_xlatvtag1_el1_t;

#define BDK_AP_CVM_XLATVTAG1_EL1 BDK_AP_CVM_XLATVTAG1_EL1_FUNC()
static inline uint64_t BDK_AP_CVM_XLATVTAG1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVM_XLATVTAG1_EL1_FUNC(void)
{
	return 0x000003000B050700ull;
}
#define typedef_BDK_AP_CVM_XLATVTAG1_EL1 bdk_ap_cvm_xlatvtag1_el1_t
#define bustype_BDK_AP_CVM_XLATVTAG1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVM_XLATVTAG1_EL1 0
#define arguments_BDK_AP_CVM_XLATVTAG1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVM_XLATVTAG1_EL1 "AP_CVM_XLATVTAG1_EL1"


/**
 * SYSREG - ap_cvmctl_el1
 *
 * This register provides Cavium-specific control information.
 *
 */
typedef union bdk_ap_cvmctl_el1 {
	uint64_t u;
	struct bdk_ap_cvmctl_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t mrs_msr_hazard              : 1;  /**< R/W - Disable MRS/MSR pipelining, assume hazards. */
		uint64_t disable_eret_pred           : 1;  /**< R/W - Disable ERET prediction. */
		uint64_t disable_casp                : 1;  /**< R/W - Disable the CASP instruction. */
		uint64_t disable_cas                 : 1;  /**< R/W - Disable the CAS instruction. */
		uint64_t force_cim_ich_vtr_to1       : 1;  /**< R/W - Set CIM AP_ICH_VTR_EL2[LISTREGS] to 0x1 (i.e. two LRs) on Pass 1. */
		uint64_t disable_wfe                 : 1;  /**< R/W - Disable WFE. */
		uint64_t enable_v81                  : 1;  /**< R/W - Enable v8.1 features, modifying the ID registers to show v8.1. */
		uint64_t make_isb_unnecessarily_slow : 1;  /**< R/W - Make ISB unnecessarily slow. */
		uint64_t wfe_defer                   : 8;  /**< R/W - WFE defer timer setting.  Time in core-clocks = {| WFE_DEFER, WFE_DEFER\<3:0\>} \<\<
                                                                 WFE_DEFER\<7:4\>. */
		uint64_t disable_icache_probes       : 1;  /**< R/W - Disable Icache probes. */
		uint64_t force_icache_parity         : 1;  /**< R/W - Force icache parity error on next Icache fill. This bit clears itself after the fill operation. */
		uint64_t suppress_parity_checking    : 1;  /**< R/W - Suppress Icache parity checking. */
		uint64_t no_exc_icache_parity        : 1;  /**< R/W - Suppress exception on Icache parity error. */
		uint64_t step_rate                   : 4;  /**< R/W - Step rate. */
		uint64_t reserved_10_15              : 6;
		uint64_t disable_flex_execution      : 1;  /**< R/W - Disable flex execution; also prevents overlapped execution of DIV/SQRT and other
                                                                 instructions (to prevent a DIV load collision). */
		uint64_t disable_branch_folding      : 1;  /**< R/W - Disable branch folding. */
		uint64_t disable_wfi                 : 1;  /**< R/W - Disable WFI/WFE. */
		uint64_t disable_fetch_under_fill    : 1;  /**< R/W - Disable fetch-under-fill. */
		uint64_t force_issue_clock           : 1;  /**< R/W - Force issue-unit clock. */
		uint64_t force_exe_clock             : 1;  /**< R/W - Force execution-unit clock. */
		uint64_t force_csr_clock             : 1;  /**< R/W - Force CSR clock. */
		uint64_t disable_icache_prefetching  : 1;  /**< R/W - Disable Icache prefetching. */
		uint64_t random_icache               : 1;  /**< R/W - Random Icache replacement. */
		uint64_t disable_icache              : 1;  /**< R/W - Disable Icache. */
#else
		uint64_t disable_icache              : 1;
		uint64_t random_icache               : 1;
		uint64_t disable_icache_prefetching  : 1;
		uint64_t force_csr_clock             : 1;
		uint64_t force_exe_clock             : 1;
		uint64_t force_issue_clock           : 1;
		uint64_t disable_fetch_under_fill    : 1;
		uint64_t disable_wfi                 : 1;
		uint64_t disable_branch_folding      : 1;
		uint64_t disable_flex_execution      : 1;
		uint64_t reserved_10_15              : 6;
		uint64_t step_rate                   : 4;
		uint64_t no_exc_icache_parity        : 1;
		uint64_t suppress_parity_checking    : 1;
		uint64_t force_icache_parity         : 1;
		uint64_t disable_icache_probes       : 1;
		uint64_t wfe_defer                   : 8;
		uint64_t make_isb_unnecessarily_slow : 1;
		uint64_t enable_v81                  : 1;
		uint64_t disable_wfe                 : 1;
		uint64_t force_cim_ich_vtr_to1       : 1;
		uint64_t disable_cas                 : 1;
		uint64_t disable_casp                : 1;
		uint64_t disable_eret_pred           : 1;
		uint64_t mrs_msr_hazard              : 1;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_ap_cvmctl_el1_s         cn88xx; */
	/* struct bdk_ap_cvmctl_el1_s         cn88xxp1; */
} bdk_ap_cvmctl_el1_t;

#define BDK_AP_CVMCTL_EL1 BDK_AP_CVMCTL_EL1_FUNC()
static inline uint64_t BDK_AP_CVMCTL_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVMCTL_EL1_FUNC(void)
{
	return 0x000003000B000000ull;
}
#define typedef_BDK_AP_CVMCTL_EL1 bdk_ap_cvmctl_el1_t
#define bustype_BDK_AP_CVMCTL_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVMCTL_EL1 0
#define arguments_BDK_AP_CVMCTL_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVMCTL_EL1 "AP_CVMCTL_EL1"


/**
 * SYSREG - ap_cvmmemctl0_el1
 *
 * This register controls memory features.
 *
 */
typedef union bdk_ap_cvmmemctl0_el1 {
	uint64_t u;
	struct bdk_ap_cvmmemctl0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_63              : 1;
		uint64_t node                        : 2;  /**< RO - Local node ID. */
		uint64_t stexfailcnt                 : 3;  /**< RO - ST exclusive fail count. */
		uint64_t wfeldex1dis                 : 1;  /**< R/W - WFE release behavior for LD-exclusive.
                                                                 0 = A global monitor transition from exclusive to open (lock flag transition
                                                                 from 1 to 0) causes SEV to local core.
                                                                 1 = A global monitor transition from exclusive to open (lock flag transition
                                                                 from 1 to 0) does not cause SEV to local core.

                                                                 Added in pass 2. */
		uint64_t stlstallforce               : 1;  /**< R/W - Force ST_release to wait for flushed write-buffer entries to be ACKed (pass 2.0 only).
                                                                 0 = Store-release instructions mark prior relevant write-buffer entries for flush but do
                                                                 not wait for the ACKs to return.
                                                                 1 = Store-release instructions mark prior relevant write-buffer entries for flush and wait
                                                                 for all the ACKs to return. */
		uint64_t dmbstallforce               : 1;  /**< R/W - Force DMB to wait for flushed write-buffer entries to be ACKed (pass 2.0 only).
                                                                 0 = DMB instructions mark prior relevant write-buffer entries for flush, but do not wait
                                                                 for the ACKs to return.
                                                                 1 = DMB instructions mark prior relevant write-buffer entries for flush and wait for all
                                                                 the ACKs to return. */
		uint64_t tlbinopdis                  : 1;  /**< R/W - Disable broadcast TLBI optimization (pass 2.0 only).
                                                                 Broadcast TLBI instructions that go to remote cores are converted to from address-based
                                                                 TLBI instructions to context-based TLBI instructions. The actions on the local core
                                                                 generating the TLBI instruction are still precise.
                                                                 0 = Context-based TLBI instructions to remote cores (without intervening interruptions,
                                                                 such as a DSB) are suppressed.
                                                                 1 = Context-based TLBI instructions to remote cores are suppressed. */
		uint64_t tlbiicflush                 : 1;  /**< R/W - Some local TLBI instructions cause ICache flush (pass 2.0 only).
                                                                 0 = Icache flush operation do not happen on the TLBI instructions listed below.
                                                                 1 = Icache is flushed on the TLBI instructions listed below:
                                                                   * TLBI ALLE2{IS}.
                                                                   * TLBI ALLE3{IS}.
                                                                   * TLBI VAE1{IS}.
                                                                   * TLBI VALE1{IS}.
                                                                   * TLBI VAAE1{IS}.
                                                                   * TLBI VAALE1{IS}.
                                                                   * TLBI VAE2{IS}.
                                                                   * TLBI VALE2{IS}.
                                                                   * TLBI VAE3{IS}.
                                                                   * TLBI VALE3{IS}.
                                                                   * TLBI IPAS2E1{IS}.
                                                                   * TLBI IPAS2LE1{IS}. */
		uint64_t gsyncto                     : 5;  /**< R/W - GlobalSync timeout. (pass 2.0 only.)
                                                                 timeout = 2^[GSYNCTO].
                                                                 0x0 = disable timeout. */
		uint64_t utlbfillbypdis              : 1;  /**< R/W - Disable uTLB fill bypass (pass 2.0 only).
                                                                 0 = On a stage1-only translation, the uTLB is written along with the MTLB.
                                                                 1 = On a stage1-only translation, the uTLB is not written along with the MTLB causing a
                                                                 uTLB miss replay to complete the uTLB fill. */
		uint64_t tlbiall                     : 1;  /**< R/W - Treat all TLBIs like TLBI ALL for a specific exception level */
		uint64_t wbfdsbflushall              : 1;  /**< R/W - Any DSB instruction flushes the write buffer. */
		uint64_t wbfdmbflushnext             : 1;  /**< R/W - DMB instruction to !NSH flushes next ST to !NSH. */
		uint64_t stexl2cforce                : 1;  /**< R/W - Send all store-exclusive instructions to L2 cache. */
		uint64_t ioglobalforce               : 1;  /**< R/W - Reserved. INTERNAL: Force global order for IO references. */
		uint64_t wcumissforce                : 1;  /**< R/W - Force all walker cache lookups to miss. */
		uint64_t replayprefdis               : 1;  /**< R/W - Replay PREF disable. uTLB miss PREF instruction behavior (see chapter body).
                                                                 0 = PREF instructions do attempt a replay for MTLB to uTLB refill.
                                                                 1 = PREF instructions do not attempt a replay for MTLB to uTLB refill. */
		uint64_t zval2cdis                   : 1;  /**< R/W - ZVA bypass L2C.
                                                                 0 = DC_ZVA instructions to L2C are STFIL1 (full block store operation allocating in
                                                                 requester L2, fill 0s, self-invalidate L1 cache).
                                                                 1 = DC_ZVA instructions to L2C are STTIL1 (full block store operation through to DRAM,
                                                                 bypass home and requester L2, fill 0s, self-invalidate L1 cache). */
		uint64_t ldil2cdis                   : 1;  /**< R/W - LDI instruction L2C usage.
                                                                 0 = LDI instructions to L2C are LDI (don't allocate in L1, allocates L2 at requester).
                                                                 1 = LDI instructions to L2C are LDT (don't allocate in L2 or L1 at home or requester). */
		uint64_t dcva47                      : 1;  /**< R/W - If MMU translations are disabled,
                                                                 apply memory attributes to physical addresses where bit\<47\>
                                                                 is zero and device attributes to physical address bit\<47\> is
                                                                 one. */
		uint64_t stprefdis                   : 1;  /**< R/W - ST PREF instructions disable. */
		uint64_t ldprefdis                   : 1;  /**< R/W - LD PREF instructions disable. */
		uint64_t wfildexdis                  : 1;  /**< R/W - WFE release behavior for LD-exclusive.
                                                                 0 = L2C invalidates to global monitor cause SEV to local core.
                                                                 1 = L2C invalidates have no effect on global monitor (i.e. lock_register).

                                                                 This field should never be set to 1; setting to 1 does not
                                                                 conform to the ARMv8 specification. */
		uint64_t wfito                       : 3;  /**< R/W - Wait-for-interrupt timeout; timeout=2^(8+[WFITO]). */
		uint64_t rbfshortto                  : 5;  /**< R/W - Read buffer short timeout; timeout = 2^[RBFSHORTTO].
                                                                 Must be \>=0x6. The L2C directs the core to use either RBFSHORTTO or RBFTO. The short
                                                                 timeout is used when an CCPI link goes down to expedite error indication. */
		uint64_t rbfto                       : 5;  /**< R/W - Read buffer timeout; timeout = 2^[RBFTO]. Must be \>= 0x6. */
		uint64_t wbfallbarrier               : 1;  /**< R/W - Write-buffer apply barrier to all ST instructions. */
		uint64_t wbfnomerge                  : 1;  /**< R/W - Write-buffer merge disable. */
		uint64_t wbftonshena                 : 1;  /**< R/W - Write-buffer timeout for NSH entries enable.
                                                                 0 = Write-buffer time out for NSH entries = 218 cycles.
                                                                 1 = Write-buffer time out for NSH entries = 2^[WBFTO] (see [WBFTO]). */
		uint64_t wbftomrgclrena              : 1;  /**< R/W - Write-buffer timeout clear-on-merge enable. */
		uint64_t wbfto                       : 5;  /**< R/W - Write-buffer timeout for non-NSH entries; timeout = 2^WBFTO. */
		uint64_t wbfthresh                   : 5;  /**< R/W - Write-buffer threshold. The write-buffer starts flushing entries to the L2 cache once the
                                                                 number of valid write-buffer entries reaches this threshold value. */
		uint64_t utlbentriesm1               : 5;  /**< R/W - Number of uTLB entries - 1. */
		uint64_t cclkforce                   : 1;  /**< R/W - Force CSR clock enable. When set, force CSR conditional clocking. */
		uint64_t mclkforce                   : 1;  /**< R/W - Force memory clock enable. When set, force memory conditional clocking. */
#else
		uint64_t mclkforce                   : 1;
		uint64_t cclkforce                   : 1;
		uint64_t utlbentriesm1               : 5;
		uint64_t wbfthresh                   : 5;
		uint64_t wbfto                       : 5;
		uint64_t wbftomrgclrena              : 1;
		uint64_t wbftonshena                 : 1;
		uint64_t wbfnomerge                  : 1;
		uint64_t wbfallbarrier               : 1;
		uint64_t rbfto                       : 5;
		uint64_t rbfshortto                  : 5;
		uint64_t wfito                       : 3;
		uint64_t wfildexdis                  : 1;
		uint64_t ldprefdis                   : 1;
		uint64_t stprefdis                   : 1;
		uint64_t dcva47                      : 1;
		uint64_t ldil2cdis                   : 1;
		uint64_t zval2cdis                   : 1;
		uint64_t replayprefdis               : 1;
		uint64_t wcumissforce                : 1;
		uint64_t ioglobalforce               : 1;
		uint64_t stexl2cforce                : 1;
		uint64_t wbfdmbflushnext             : 1;
		uint64_t wbfdsbflushall              : 1;
		uint64_t tlbiall                     : 1;
		uint64_t utlbfillbypdis              : 1;
		uint64_t gsyncto                     : 5;
		uint64_t tlbiicflush                 : 1;
		uint64_t tlbinopdis                  : 1;
		uint64_t dmbstallforce               : 1;
		uint64_t stlstallforce               : 1;
		uint64_t wfeldex1dis                 : 1;
		uint64_t stexfailcnt                 : 3;
		uint64_t node                        : 2;
		uint64_t reserved_63_63              : 1;
#endif
	} s;
	/* struct bdk_ap_cvmmemctl0_el1_s     cn88xx; */
	struct bdk_ap_cvmmemctl0_el1_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_63              : 1;
		uint64_t node                        : 2;  /**< RO - Local node ID. */
		uint64_t stexfailcnt                 : 3;  /**< RO - ST exclusive fail count. */
		uint64_t reserved_57_57              : 1;
		uint64_t stlstallforce               : 1;  /**< R/W - Force ST_release to wait for flushed write-buffer entries to be ACKed (pass 2.0 only).
                                                                 0 = Store-release instructions mark prior relevant write-buffer entries for flush but do
                                                                 not wait for the ACKs to return.
                                                                 1 = Store-release instructions mark prior relevant write-buffer entries for flush and wait
                                                                 for all the ACKs to return. */
		uint64_t dmbstallforce               : 1;  /**< R/W - Force DMB to wait for flushed write-buffer entries to be ACKed (pass 2.0 only).
                                                                 0 = DMB instructions mark prior relevant write-buffer entries for flush, but do not wait
                                                                 for the ACKs to return.
                                                                 1 = DMB instructions mark prior relevant write-buffer entries for flush and wait for all
                                                                 the ACKs to return. */
		uint64_t tlbinopdis                  : 1;  /**< R/W - Disable broadcast TLBI optimization (pass 2.0 only).
                                                                 Broadcast TLBI instructions that go to remote cores are converted to from address-based
                                                                 TLBI instructions to context-based TLBI instructions. The actions on the local core
                                                                 generating the TLBI instruction are still precise.
                                                                 0 = Context-based TLBI instructions to remote cores (without intervening interruptions,
                                                                 such as a DSB) are suppressed.
                                                                 1 = Context-based TLBI instructions to remote cores are suppressed. */
		uint64_t tlbiicflush                 : 1;  /**< R/W - Some local TLBI instructions cause ICache flush (pass 2.0 only).
                                                                 0 = Icache flush operation do not happen on the TLBI instructions listed below.
                                                                 1 = Icache is flushed on the TLBI instructions listed below:
                                                                   * TLBI ALLE2{IS}.
                                                                   * TLBI ALLE3{IS}.
                                                                   * TLBI VAE1{IS}.
                                                                   * TLBI VALE1{IS}.
                                                                   * TLBI VAAE1{IS}.
                                                                   * TLBI VAALE1{IS}.
                                                                   * TLBI VAE2{IS}.
                                                                   * TLBI VALE2{IS}.
                                                                   * TLBI VAE3{IS}.
                                                                   * TLBI VALE3{IS}.
                                                                   * TLBI IPAS2E1{IS}.
                                                                   * TLBI IPAS2LE1{IS}. */
		uint64_t gsyncto                     : 5;  /**< R/W - GlobalSync timeout. (pass 2.0 only.)
                                                                 timeout = 2^[GSYNCTO].
                                                                 0x0 = disable timeout. */
		uint64_t utlbfillbypdis              : 1;  /**< R/W - Disable uTLB fill bypass (pass 2.0 only).
                                                                 0 = On a stage1-only translation, the uTLB is written along with the MTLB.
                                                                 1 = On a stage1-only translation, the uTLB is not written along with the MTLB causing a
                                                                 uTLB miss replay to complete the uTLB fill. */
		uint64_t tlbiall                     : 1;  /**< R/W - Treat all TLBIs like TLBI ALL for a specific exception level */
		uint64_t wbfdsbflushall              : 1;  /**< R/W - Any DSB instruction flushes the write buffer. */
		uint64_t wbfdmbflushnext             : 1;  /**< R/W - DMB instruction to !NSH flushes next ST to !NSH. */
		uint64_t stexl2cforce                : 1;  /**< R/W - Send all store-exclusive instructions to L2 cache. */
		uint64_t ioglobalforce               : 1;  /**< R/W - Reserved. INTERNAL: Force global order for IO references. */
		uint64_t wcumissforce                : 1;  /**< R/W - Force all walker cache lookups to miss. */
		uint64_t replayprefdis               : 1;  /**< R/W - Replay PREF disable. uTLB miss PREF instruction behavior (see chapter body).
                                                                 0 = PREF instructions do attempt a replay for MTLB to uTLB refill.
                                                                 1 = PREF instructions do not attempt a replay for MTLB to uTLB refill. */
		uint64_t zval2cdis                   : 1;  /**< R/W - ZVA bypass L2C.
                                                                 0 = DC_ZVA instructions to L2C are STFIL1 (full block store operation allocating in
                                                                 requester L2, fill 0s, self-invalidate L1 cache).
                                                                 1 = DC_ZVA instructions to L2C are STTIL1 (full block store operation through to DRAM,
                                                                 bypass home and requester L2, fill 0s, self-invalidate L1 cache). */
		uint64_t ldil2cdis                   : 1;  /**< R/W - LDI instruction L2C usage.
                                                                 0 = LDI instructions to L2C are LDI (don't allocate in L1, allocates L2 at requester).
                                                                 1 = LDI instructions to L2C are LDT (don't allocate in L2 or L1 at home or requester). */
		uint64_t dcva47                      : 1;  /**< R/W - If MMU translations are disabled,
                                                                 apply memory attributes to physical addresses where bit\<47\>
                                                                 is zero and device attributes to physical address bit\<47\> is
                                                                 one. */
		uint64_t stprefdis                   : 1;  /**< R/W - ST PREF instructions disable. */
		uint64_t ldprefdis                   : 1;  /**< R/W - LD PREF instructions disable. */
		uint64_t wfildexdis                  : 1;  /**< R/W - WFE release behavior for LD-exclusive.
                                                                 0 = L2C invalidates to global monitor cause SEV to local core.
                                                                 1 = L2C invalidates have no effect on global monitor (i.e. lock_register).

                                                                 This field should never be set to 1; setting to 1 does not
                                                                 conform to the ARMv8 specification. */
		uint64_t wfito                       : 3;  /**< R/W - Wait-for-interrupt timeout; timeout=2^(8+[WFITO]). */
		uint64_t rbfshortto                  : 5;  /**< R/W - Read buffer short timeout; timeout = 2^[RBFSHORTTO].
                                                                 Must be \>=0x6. The L2C directs the core to use either RBFSHORTTO or RBFTO. The short
                                                                 timeout is used when an CCPI link goes down to expedite error indication. */
		uint64_t rbfto                       : 5;  /**< R/W - Read buffer timeout; timeout = 2^[RBFTO]. Must be \>= 0x6. */
		uint64_t wbfallbarrier               : 1;  /**< R/W - Write-buffer apply barrier to all ST instructions. */
		uint64_t wbfnomerge                  : 1;  /**< R/W - Write-buffer merge disable. */
		uint64_t wbftonshena                 : 1;  /**< R/W - Write-buffer timeout for NSH entries enable.
                                                                 0 = Write-buffer time out for NSH entries = 218 cycles.
                                                                 1 = Write-buffer time out for NSH entries = 2^[WBFTO] (see [WBFTO]). */
		uint64_t wbftomrgclrena              : 1;  /**< R/W - Write-buffer timeout clear-on-merge enable. */
		uint64_t wbfto                       : 5;  /**< R/W - Write-buffer timeout for non-NSH entries; timeout = 2^WBFTO. */
		uint64_t wbfthresh                   : 5;  /**< R/W - Write-buffer threshold. The write-buffer starts flushing entries to the L2 cache once the
                                                                 number of valid write-buffer entries reaches this threshold value. */
		uint64_t utlbentriesm1               : 5;  /**< R/W - Number of uTLB entries - 1. */
		uint64_t cclkforce                   : 1;  /**< R/W - Force CSR clock enable. When set, force CSR conditional clocking. */
		uint64_t mclkforce                   : 1;  /**< R/W - Force memory clock enable. When set, force memory conditional clocking. */
#else
		uint64_t mclkforce                   : 1;
		uint64_t cclkforce                   : 1;
		uint64_t utlbentriesm1               : 5;
		uint64_t wbfthresh                   : 5;
		uint64_t wbfto                       : 5;
		uint64_t wbftomrgclrena              : 1;
		uint64_t wbftonshena                 : 1;
		uint64_t wbfnomerge                  : 1;
		uint64_t wbfallbarrier               : 1;
		uint64_t rbfto                       : 5;
		uint64_t rbfshortto                  : 5;
		uint64_t wfito                       : 3;
		uint64_t wfildexdis                  : 1;
		uint64_t ldprefdis                   : 1;
		uint64_t stprefdis                   : 1;
		uint64_t dcva47                      : 1;
		uint64_t ldil2cdis                   : 1;
		uint64_t zval2cdis                   : 1;
		uint64_t replayprefdis               : 1;
		uint64_t wcumissforce                : 1;
		uint64_t ioglobalforce               : 1;
		uint64_t stexl2cforce                : 1;
		uint64_t wbfdmbflushnext             : 1;
		uint64_t wbfdsbflushall              : 1;
		uint64_t tlbiall                     : 1;
		uint64_t utlbfillbypdis              : 1;
		uint64_t gsyncto                     : 5;
		uint64_t tlbiicflush                 : 1;
		uint64_t tlbinopdis                  : 1;
		uint64_t dmbstallforce               : 1;
		uint64_t stlstallforce               : 1;
		uint64_t reserved_57_57              : 1;
		uint64_t stexfailcnt                 : 3;
		uint64_t node                        : 2;
		uint64_t reserved_63_63              : 1;
#endif
	} cn88xxp1;
} bdk_ap_cvmmemctl0_el1_t;

#define BDK_AP_CVMMEMCTL0_EL1 BDK_AP_CVMMEMCTL0_EL1_FUNC()
static inline uint64_t BDK_AP_CVMMEMCTL0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVMMEMCTL0_EL1_FUNC(void)
{
	return 0x000003000B000400ull;
}
#define typedef_BDK_AP_CVMMEMCTL0_EL1 bdk_ap_cvmmemctl0_el1_t
#define bustype_BDK_AP_CVMMEMCTL0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVMMEMCTL0_EL1 0
#define arguments_BDK_AP_CVMMEMCTL0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVMMEMCTL0_EL1 "AP_CVMMEMCTL0_EL1"


/**
 * SYSREG - ap_cvmmemctl1_el1
 *
 * This register controls additional memory-unit features.
 * INTERNAL: Back-end, non-debug.
 */
typedef union bdk_ap_cvmmemctl1_el1 {
	uint64_t u;
	struct bdk_ap_cvmmemctl1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t switchtagena                : 1;  /**< R/W - Reserved.  INTERNAL: 83xx: Enable SSO switch-tag. */
		uint64_t node1trapena                : 1;  /**< R/W - Reserved.  INTERNAL: 83xx: Trap any access to non-zero node id. */
		uint64_t ioatomicena                 : 1;  /**< R/W - Enable atomics to I/O space.
                                                                 0 = Atomic instructions to I/O space (PA\<47\>=1) will trap.
                                                                 1 = Atomic instructions to SLI I/O space will succeed,
                                                                     atomic instructions to other I/O spaces will trap.
                                                                 INTERNAL: Also PKO/SSO. */
		uint64_t lmtstena                    : 1;  /**< R/W - Reserved. INTERNAL: 83xx: Enable/disable LMTST(a). */
		uint64_t lodignoresh                 : 1;  /**< R/W - LocalOrderDomain DMB/DSB_NSH{ST} ignores shareability (applies to both nsh and ish pages). */
		uint64_t lodishena                   : 1;  /**< R/W - LocalOrderDomain DMB/DSB_ISH{ST} enable. */
		uint64_t lodnshena                   : 1;  /**< R/W - LocalOrderDomain DMB/DSB_NSH{ST} enable. */
#else
		uint64_t lodnshena                   : 1;
		uint64_t lodishena                   : 1;
		uint64_t lodignoresh                 : 1;
		uint64_t lmtstena                    : 1;
		uint64_t ioatomicena                 : 1;
		uint64_t node1trapena                : 1;
		uint64_t switchtagena                : 1;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_ap_cvmmemctl1_el1_s     cn88xx; */
	/* struct bdk_ap_cvmmemctl1_el1_s     cn88xxp1; */
} bdk_ap_cvmmemctl1_el1_t;

#define BDK_AP_CVMMEMCTL1_EL1 BDK_AP_CVMMEMCTL1_EL1_FUNC()
static inline uint64_t BDK_AP_CVMMEMCTL1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_CVMMEMCTL1_EL1_FUNC(void)
{
	return 0x000003000B000500ull;
}
#define typedef_BDK_AP_CVMMEMCTL1_EL1 bdk_ap_cvmmemctl1_el1_t
#define bustype_BDK_AP_CVMMEMCTL1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_CVMMEMCTL1_EL1 0
#define arguments_BDK_AP_CVMMEMCTL1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_CVMMEMCTL1_EL1 "AP_CVMMEMCTL1_EL1"


/**
 * SYSREG - ap_dacr32_el2
 *
 * Allows access to the AArch32 DACR register from AArch64 state
 * only. Its value has no effect on execution in AArch64 state.
 */
typedef union bdk_ap_dacr32_el2 {
	uint32_t u;
	struct bdk_ap_dacr32_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_dacr32_el2_s         cn88xx; */
	/* struct bdk_ap_dacr32_el2_s         cn88xxp1; */
} bdk_ap_dacr32_el2_t;

#define BDK_AP_DACR32_EL2 BDK_AP_DACR32_EL2_FUNC()
static inline uint64_t BDK_AP_DACR32_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DACR32_EL2_FUNC(void)
{
	return 0x0000030403000000ull;
}
#define typedef_BDK_AP_DACR32_EL2 bdk_ap_dacr32_el2_t
#define bustype_BDK_AP_DACR32_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DACR32_EL2 0
#define arguments_BDK_AP_DACR32_EL2 -1,-1,-1,-1
#define basename_BDK_AP_DACR32_EL2 "AP_DACR32_EL2"


/**
 * SYSREG - ap_daif
 *
 * Allows access to the interrupt mask bits.
 *
 */
typedef union bdk_ap_daif {
	uint32_t u;
	struct bdk_ap_daif_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t dd                          : 1;  /**< R/W - Process state D mask.
                                                                 When the target Exception level of the debug exception is not
                                                                     than the current Exception level, the exception is not masked
                                                                     by this bit.
                                                                 0 = Debug exceptions from Watchpoint, Breakpoint, and Software
                                                                     step debug events targeted at the current Exception level are
                                                                     not masked.
                                                                 1 = Debug exceptions from Watchpoint, Breakpoint, and Software
                                                                     step debug events targeted at the current Exception level are
                                                                     masked. */
		uint32_t aa                          : 1;  /**< R/W - SError (System Error) mask bit.
                                                                 0 = Exception not masked.
                                                                 1 = Exception masked. */
		uint32_t i                           : 1;  /**< R/W - IRQ mask bit.
                                                                 0 = Exception not masked.
                                                                 1 = Exception masked. */
		uint32_t f                           : 1;  /**< R/W - FIQ mask bit.
                                                                 0 = Exception not masked.
                                                                 1 = Exception masked. */
		uint32_t reserved_0_5                : 6;
#else
		uint32_t reserved_0_5                : 6;
		uint32_t f                           : 1;
		uint32_t i                           : 1;
		uint32_t aa                          : 1;
		uint32_t dd                          : 1;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_ap_daif_s               cn88xx; */
	/* struct bdk_ap_daif_s               cn88xxp1; */
} bdk_ap_daif_t;

#define BDK_AP_DAIF BDK_AP_DAIF_FUNC()
static inline uint64_t BDK_AP_DAIF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DAIF_FUNC(void)
{
	return 0x0000030304020100ull;
}
#define typedef_BDK_AP_DAIF bdk_ap_daif_t
#define bustype_BDK_AP_DAIF BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DAIF 0
#define arguments_BDK_AP_DAIF -1,-1,-1,-1
#define basename_BDK_AP_DAIF "AP_DAIF"


/**
 * SYSREG - ap_dbgauthstatus_el1
 *
 * Provides information about the state of the implementation
 * defined authentication interface for debug.
 */
typedef union bdk_ap_dbgauthstatus_el1 {
	uint32_t u;
	struct bdk_ap_dbgauthstatus_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t snid                        : 2;  /**< RO - Secure non-invasive debug.
                                                                 0x0 = Not implemented. EL3 is not implemented and the processor is
                                                                     non-secure.
                                                                 0x2 = Implemented and disabled.
                                                                 0x3 = Implemented and enabled. */
		uint32_t sid                         : 2;  /**< RO - Secure invasive debug.
                                                                 0x0 = Not implemented. EL3 is not implemented and the processor is
                                                                     non-secure.
                                                                 0x2 = Implemented and disabled.
                                                                 0x3 = Implemented and enabled. */
		uint32_t nsnid                       : 2;  /**< RO - Non-secure non-invasive debug.
                                                                 0x0 = Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 0x2 = Implemented and disabled.
                                                                 0x3 = Implemented and enabled. */
		uint32_t nsid                        : 2;  /**< RO - Non-secure invasive debug.
                                                                 0x0 = Not implemented. EL3 is not implemented and the processor is
                                                                 0x2 = Implemented and disabled.
                                                                 0x3 = Implemented and enabled. */
#else
		uint32_t nsid                        : 2;
		uint32_t nsnid                       : 2;
		uint32_t sid                         : 2;
		uint32_t snid                        : 2;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ap_dbgauthstatus_el1_s  cn88xx; */
	/* struct bdk_ap_dbgauthstatus_el1_s  cn88xxp1; */
} bdk_ap_dbgauthstatus_el1_t;

#define BDK_AP_DBGAUTHSTATUS_EL1 BDK_AP_DBGAUTHSTATUS_EL1_FUNC()
static inline uint64_t BDK_AP_DBGAUTHSTATUS_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGAUTHSTATUS_EL1_FUNC(void)
{
	return 0x00000200070E0600ull;
}
#define typedef_BDK_AP_DBGAUTHSTATUS_EL1 bdk_ap_dbgauthstatus_el1_t
#define bustype_BDK_AP_DBGAUTHSTATUS_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGAUTHSTATUS_EL1 0
#define arguments_BDK_AP_DBGAUTHSTATUS_EL1 -1,-1,-1,-1
#define basename_BDK_AP_DBGAUTHSTATUS_EL1 "AP_DBGAUTHSTATUS_EL1"


/**
 * SYSREG - ap_dbgbcr#_el1
 *
 * Holds control information for a breakpoint. Forms breakpoint n
 * together with value register DBGBVR\<n\>_EL1, where n is 0 to
 * 15.
 */
typedef union bdk_ap_dbgbcrx_el1 {
	uint32_t u;
	struct bdk_ap_dbgbcrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t bt                          : 4;  /**< R/W - Breakpoint Type.
                                                                 The field breaks down as follows:
                                                                  BT[3:1]: Base type.- 0b000: Match address. DBGBVR\<n\>_EL1 is
                                                                     the address of an     instruction. - 0b010: Mismatch address.
                                                                     Behaves as type0b000 DBGBVR\<n\>_EL1     is the address of an
                                                                     instruction to be stepped. - 0b001: Match context ID.
                                                                     DBGBVR\<n\>_EL1[31:0] is a context     ID. - 0b100: Match VMID.
                                                                     DBGBVR\<n\>_EL1[39:32] is a VMID. - 0b101: Match VMID and
                                                                     context ID. DBGBVR\<n\>_EL1[31:0] is a     context ID, and
                                                                     DBGBVR\<n\>_EL1[39:32] is a VMID.
                                                                  BT[0]: Enable linking.

                                                                 If the breakpoint is not context-aware, BT[3] and BT[1] are
                                                                     RES0. If EL2 is not implemented, BT[3] is RES0. If EL1 using
                                                                     AArch32 is not implemented, BT[2] is RES0.

                                                                 0x0 = Unlinked address match.
                                                                 0x1 = Linked address match.
                                                                 0x2 = Unlinked context ID match.
                                                                 0x3 = Linked context ID match
                                                                 0x4 = Unlinked address mismatch.
                                                                 0x5 = Linked address mismatch.
                                                                 0x8 = Unlinked VMID match.
                                                                 0x9 = Linked VMID match.
                                                                 0xA = Unlinked VMID and context ID match.
                                                                 0xB = Linked VMID and context ID match. */
		uint32_t lbn                         : 4;  /**< R/W - Linked breakpoint number. For Linked address matching
                                                                 breakpoints, this specifies the index of the Context-matching
                                                                 breakpoint linked to. */
		uint32_t ssc                         : 2;  /**< R/W - Security state control. Determines the Security states under
                                                                 which a breakpoint debug event for breakpoint n is generated.
                                                                 This field must be interpreted along with the HMC and PMC
                                                                 fields. */
		uint32_t hmc                         : 1;  /**< R/W - Higher mode control. Determines the debug perspective for
                                                                 deciding when a breakpoint debug event for breakpoint n is
                                                                 generated. This field must be interpreted along with the SSC
                                                                 and PMC fields. */
		uint32_t reserved_9_12               : 4;
		uint32_t rsvd_5_8                    : 4;  /**< RO - Byte address select. Defines which half-words an address-
                                                                     matching breakpoint matches, regardless of the instruction set
                                                                     and Execution state. In an AArch64-only implementation, this
                                                                     field is reserved, RES1. Otherwise:

                                                                  BAS[2] and BAS[0] are read/write.

                                                                  BAS[3] and BAS[1] are read-only copies of BAS[2] and BAS[0]
                                                                     respectively.

                                                                 The permitted values depend on the breakpoint type.

                                                                 For Address match breakpoints in either AArch32 or AArch64
                                                                     state:
                                                                 BAS Match instruction at    Constraint for debuggers
                                                                 0b0011       DBGBVR\<n\>_EL1  Use for T32 instructions.
                                                                 0b1100       DBGBVR\<n\>_EL1+2        Use for T32 instructions.
                                                                 0b1111       DBGBVR\<n\>_EL1  Use for A64 and A32 instructions.
                                                                 0b0000

                                                                 For Address mismatch breakpoints in an AArch32 stage 1
                                                                     translation regime:
                                                                 BAS Step instruction at     Constraint for debuggers
                                                                 0b0000      -       Use for a match anywhere breakpoint.
                                                                 0b0011       DBGBVR\<n\>_EL1  Use for stepping T32 instructions.
                                                                 0b1100       DBGBVR\<n\>_EL1+2        Use for stepping T32 instructions.
                                                                 0b1111       DBGBVR\<n\>_EL1  Use for stepping A32 instructions.

                                                                 For Context matching breakpoints, this field is RES1 and
                                                                     ignored. */
		uint32_t reserved_3_4                : 2;
		uint32_t pmc                         : 2;  /**< R/W - Privilege mode control. Determines the Exception level or
                                                                 levels at which a breakpoint debug event for breakpoint n is
                                                                 generated. This field must be interpreted along with the SSC
                                                                 and HMC fields. */
		uint32_t ee                          : 1;  /**< R/W - Enable breakpoint DBGBVR\<n\>_EL1.
                                                                 0 = Breakpoint disabled.
                                                                 1 = Breakpoint enabled. */
#else
		uint32_t ee                          : 1;
		uint32_t pmc                         : 2;
		uint32_t reserved_3_4                : 2;
		uint32_t rsvd_5_8                    : 4;
		uint32_t reserved_9_12               : 4;
		uint32_t hmc                         : 1;
		uint32_t ssc                         : 2;
		uint32_t lbn                         : 4;
		uint32_t bt                          : 4;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_dbgbcrx_el1_s        cn88xx; */
	/* struct bdk_ap_dbgbcrx_el1_s        cn88xxp1; */
} bdk_ap_dbgbcrx_el1_t;

static inline uint64_t BDK_AP_DBGBCRX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGBCRX_EL1(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000020000000500ull + (param1 & 15) * 0x10000ull;
	csr_fatal("BDK_AP_DBGBCRX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_DBGBCRX_EL1(...) bdk_ap_dbgbcrx_el1_t
#define bustype_BDK_AP_DBGBCRX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGBCRX_EL1(p1) (p1)
#define arguments_BDK_AP_DBGBCRX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_DBGBCRX_EL1(...) "AP_DBGBCRX_EL1"


/**
 * SYSREG - ap_dbgbvr#_el1
 *
 * Holds a virtual address, or a VMID and/or a context ID, for
 * use in breakpoint matching. Forms breakpoint n together with
 * control register DBGBCR\<n\>_EL1, where n is 0 to 15.
 */
typedef union bdk_ap_dbgbvrx_el1 {
	uint64_t u;
	struct bdk_ap_dbgbvrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Data for breakpoint value. This doesn't match ARM docs as
                                                                 they have many encoding of the same register.
                                                                 Reserved, Sign extended. Hardwired to the value of the sign
                                                                     bit, bit [48]. Hardware and software must treat this field as
                                                                     RES0 if bit[48] is 0, and as RES1 if bit[48] is 1. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_dbgbvrx_el1_s        cn88xx; */
	/* struct bdk_ap_dbgbvrx_el1_s        cn88xxp1; */
} bdk_ap_dbgbvrx_el1_t;

static inline uint64_t BDK_AP_DBGBVRX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGBVRX_EL1(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000020000000400ull + (param1 & 15) * 0x10000ull;
	csr_fatal("BDK_AP_DBGBVRX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_DBGBVRX_EL1(...) bdk_ap_dbgbvrx_el1_t
#define bustype_BDK_AP_DBGBVRX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGBVRX_EL1(p1) (p1)
#define arguments_BDK_AP_DBGBVRX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_DBGBVRX_EL1(...) "AP_DBGBVRX_EL1"


/**
 * SYSREG - ap_dbgclaimclr_el1
 *
 * Used by software to read the values of the CLAIM bits, and to
 * clear these bits to 0.
 */
typedef union bdk_ap_dbgclaimclr_el1 {
	uint32_t u;
	struct bdk_ap_dbgclaimclr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t claim                       : 8;  /**< R/W - Claim clear bits. Reading this field returns the current value
                                                                     of the CLAIM bits.
                                                                 Writing a 1 to one of these bits clears the corresponding
                                                                     CLAIM bit to 0. This is an indirect write to the CLAIM bits.
                                                                 A single write operation can clear multiple bits to 0. Writing
                                                                     0 to one of these bits has no effect. */
#else
		uint32_t claim                       : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ap_dbgclaimclr_el1_s    cn88xx; */
	/* struct bdk_ap_dbgclaimclr_el1_s    cn88xxp1; */
} bdk_ap_dbgclaimclr_el1_t;

#define BDK_AP_DBGCLAIMCLR_EL1 BDK_AP_DBGCLAIMCLR_EL1_FUNC()
static inline uint64_t BDK_AP_DBGCLAIMCLR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGCLAIMCLR_EL1_FUNC(void)
{
	return 0x0000020007090600ull;
}
#define typedef_BDK_AP_DBGCLAIMCLR_EL1 bdk_ap_dbgclaimclr_el1_t
#define bustype_BDK_AP_DBGCLAIMCLR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGCLAIMCLR_EL1 0
#define arguments_BDK_AP_DBGCLAIMCLR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_DBGCLAIMCLR_EL1 "AP_DBGCLAIMCLR_EL1"


/**
 * SYSREG - ap_dbgclaimset_el1
 *
 * Used by software to set CLAIM bits to 1.
 *
 */
typedef union bdk_ap_dbgclaimset_el1 {
	uint32_t u;
	struct bdk_ap_dbgclaimset_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t claim                       : 8;  /**< R/W - Claim set bits. RAO.
                                                                 Writing a 1 to one of these bits sets the corresponding CLAIM
                                                                     bit to 1. This is an indirect write to the CLAIM bits.
                                                                 A single write operation can set multiple bits to 1. Writing 0
                                                                     to one of these bits has no effect. */
#else
		uint32_t claim                       : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ap_dbgclaimset_el1_s    cn88xx; */
	/* struct bdk_ap_dbgclaimset_el1_s    cn88xxp1; */
} bdk_ap_dbgclaimset_el1_t;

#define BDK_AP_DBGCLAIMSET_EL1 BDK_AP_DBGCLAIMSET_EL1_FUNC()
static inline uint64_t BDK_AP_DBGCLAIMSET_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGCLAIMSET_EL1_FUNC(void)
{
	return 0x0000020007080600ull;
}
#define typedef_BDK_AP_DBGCLAIMSET_EL1 bdk_ap_dbgclaimset_el1_t
#define bustype_BDK_AP_DBGCLAIMSET_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGCLAIMSET_EL1 0
#define arguments_BDK_AP_DBGCLAIMSET_EL1 -1,-1,-1,-1
#define basename_BDK_AP_DBGCLAIMSET_EL1 "AP_DBGCLAIMSET_EL1"


/**
 * SYSREG - ap_dbgdtr_el0
 *
 * Transfers 64 bits of data between the processor and an
 * external host. Can transfer both ways using only a single
 * register.
 */
typedef union bdk_ap_dbgdtr_el0 {
	uint64_t u;
	struct bdk_ap_dbgdtr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t highword                    : 32; /**< R/W - Writes to this register set DTRRX to the value in this field.
                                                                 Reads from this register return the value of DTRTX. */
		uint64_t lowword                     : 32; /**< R/W - Writes to this register set DTRTX to the value in this field.
                                                                 Reads from this register return the value of DTRRX. */
#else
		uint64_t lowword                     : 32;
		uint64_t highword                    : 32;
#endif
	} s;
	/* struct bdk_ap_dbgdtr_el0_s         cn88xx; */
	/* struct bdk_ap_dbgdtr_el0_s         cn88xxp1; */
} bdk_ap_dbgdtr_el0_t;

#define BDK_AP_DBGDTR_EL0 BDK_AP_DBGDTR_EL0_FUNC()
static inline uint64_t BDK_AP_DBGDTR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGDTR_EL0_FUNC(void)
{
	return 0x0000020300040000ull;
}
#define typedef_BDK_AP_DBGDTR_EL0 bdk_ap_dbgdtr_el0_t
#define bustype_BDK_AP_DBGDTR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGDTR_EL0 0
#define arguments_BDK_AP_DBGDTR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_DBGDTR_EL0 "AP_DBGDTR_EL0"


/**
 * SYSREG - ap_dbgdtrrx_el0
 *
 * Transfers 32 bits of data from an external host to the
 *     processor.
 *
 * This register is at the same select as AP_DBGDTRTX_EL0.
 */
typedef union bdk_ap_dbgdtrrx_el0 {
	uint32_t u;
	struct bdk_ap_dbgdtrrx_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< RO - Host to target data
                                                                 Host to target data. One word of data for transfer from the
                                                                     debug host to the debug target.
                                                                 For the full behavior of the Debug Communications Channel, see
                                                                     section 9 (The Debug Communications Channel and Instruction
                                                                     Transfer Register) in document PRD03-PRDC-010486. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_dbgdtrrx_el0_s       cn88xx; */
	/* struct bdk_ap_dbgdtrrx_el0_s       cn88xxp1; */
} bdk_ap_dbgdtrrx_el0_t;

#define BDK_AP_DBGDTRRX_EL0 BDK_AP_DBGDTRRX_EL0_FUNC()
static inline uint64_t BDK_AP_DBGDTRRX_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGDTRRX_EL0_FUNC(void)
{
	return 0x0000020300050000ull;
}
#define typedef_BDK_AP_DBGDTRRX_EL0 bdk_ap_dbgdtrrx_el0_t
#define bustype_BDK_AP_DBGDTRRX_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGDTRRX_EL0 0
#define arguments_BDK_AP_DBGDTRRX_EL0 -1,-1,-1,-1
#define basename_BDK_AP_DBGDTRRX_EL0 "AP_DBGDTRRX_EL0"


/**
 * SYSREG - ap_dbgdtrtx_el0
 *
 * Transfers 32 bits of data from the processor to an external
 *     host.
 *
 * This register is at the same select as AP_DBGDTRRX_EL0.
 */
typedef union bdk_ap_dbgdtrtx_el0 {
	uint32_t u;
	struct bdk_ap_dbgdtrtx_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< RO - Target to host data. One word of data for transfer from the
                                                                     debug target to the debug host.
                                                                 For the full behavior of the Debug Communications Channel, see
                                                                     section 9 (The Debug Communications Channel and Instruction
                                                                     Transfer Register) in document PRD03-PRDC-010486. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_dbgdtrtx_el0_s       cn88xx; */
	/* struct bdk_ap_dbgdtrtx_el0_s       cn88xxp1; */
} bdk_ap_dbgdtrtx_el0_t;

#define BDK_AP_DBGDTRTX_EL0 BDK_AP_DBGDTRTX_EL0_FUNC()
static inline uint64_t BDK_AP_DBGDTRTX_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGDTRTX_EL0_FUNC(void)
{
	return 0x0000020300050010ull;
}
#define typedef_BDK_AP_DBGDTRTX_EL0 bdk_ap_dbgdtrtx_el0_t
#define bustype_BDK_AP_DBGDTRTX_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGDTRTX_EL0 0
#define arguments_BDK_AP_DBGDTRTX_EL0 -1,-1,-1,-1
#define basename_BDK_AP_DBGDTRTX_EL0 "AP_DBGDTRTX_EL0"


/**
 * SYSREG - ap_dbgprcr_el1
 *
 * Controls behavior of processor on power-down request.
 *
 */
typedef union bdk_ap_dbgprcr_el1 {
	uint32_t u;
	struct bdk_ap_dbgprcr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t corenpdrq                   : 1;  /**< R/W - Core no powerdown request. Requests emulation of powerdown.

                                                                 0 = On a powerdown request, the system powers down the Core power
                                                                     domain.
                                                                 1 = On a powerdown request, the system emulates powerdown of the
                                                                     Core power domain. In this emulation mode the Core power
                                                                     domain is not actually powered down. */
#else
		uint32_t corenpdrq                   : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_dbgprcr_el1_s        cn88xx; */
	/* struct bdk_ap_dbgprcr_el1_s        cn88xxp1; */
} bdk_ap_dbgprcr_el1_t;

#define BDK_AP_DBGPRCR_EL1 BDK_AP_DBGPRCR_EL1_FUNC()
static inline uint64_t BDK_AP_DBGPRCR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGPRCR_EL1_FUNC(void)
{
	return 0x0000020001040400ull;
}
#define typedef_BDK_AP_DBGPRCR_EL1 bdk_ap_dbgprcr_el1_t
#define bustype_BDK_AP_DBGPRCR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGPRCR_EL1 0
#define arguments_BDK_AP_DBGPRCR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_DBGPRCR_EL1 "AP_DBGPRCR_EL1"


/**
 * SYSREG - ap_dbgvcr32_el2
 *
 * Allows access to the AArch32 register DBGVCR from AArch64
 * state only. Its value has no effect on execution in AArch64
 * state.
 */
typedef union bdk_ap_dbgvcr32_el2 {
	uint32_t u;
	struct bdk_ap_dbgvcr32_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nsf                         : 1;  /**< R/W - FIQ vector catch enable in non-secure state.
                                                                 The exception vector offset is 0x1C. */
		uint32_t nsi                         : 1;  /**< R/W - IRQ vector catch enable in non-secure state.
                                                                 The exception vector offset is 0x18. */
		uint32_t reserved_29_29              : 1;
		uint32_t nsd                         : 1;  /**< R/W - Data Abort vector catch enable in non-secure state.
                                                                 The exception vector offset is 0x10. */
		uint32_t nsp                         : 1;  /**< R/W - Prefetch Abort vector catch enable in non-secure state.
                                                                 The exception vector offset is 0x0C. */
		uint32_t nss                         : 1;  /**< R/W - Supervisor Call (SVC) vector catch enable in non-secure state.
                                                                 The exception vector offset is 0x08. */
		uint32_t nsu                         : 1;  /**< R/W - Undefined Instruction vector catch enable in non-secure state.
                                                                 The exception vector offset is 0x04. */
		uint32_t reserved_8_24               : 17;
		uint32_t sf                          : 1;  /**< R/W - FIQ vector catch enable in Secure state.
                                                                 The exception vector offset is 0x1C. */
		uint32_t si                          : 1;  /**< R/W - IRQ vector catch enable in Secure state.
                                                                 The exception vector offset is 0x18. */
		uint32_t reserved_5_5                : 1;
		uint32_t sd                          : 1;  /**< R/W - Data Abort vector catch enable in Secure state.
                                                                 The exception vector offset is 0x10. */
		uint32_t sp                          : 1;  /**< R/W - Prefetch Abort vector catch enable in Secure state.
                                                                 The exception vector offset is 0x0C. */
		uint32_t ss                          : 1;  /**< R/W - Supervisor Call (SVC) vector catch enable in Secure state.
                                                                 The exception vector offset is 0x08. */
		uint32_t su                          : 1;  /**< R/W - Undefined Instruction vector catch enable in Secure state.
                                                                 The exception vector offset is 0x04. */
		uint32_t reserved_0_0                : 1;
#else
		uint32_t reserved_0_0                : 1;
		uint32_t su                          : 1;
		uint32_t ss                          : 1;
		uint32_t sp                          : 1;
		uint32_t sd                          : 1;
		uint32_t reserved_5_5                : 1;
		uint32_t si                          : 1;
		uint32_t sf                          : 1;
		uint32_t reserved_8_24               : 17;
		uint32_t nsu                         : 1;
		uint32_t nss                         : 1;
		uint32_t nsp                         : 1;
		uint32_t nsd                         : 1;
		uint32_t reserved_29_29              : 1;
		uint32_t nsi                         : 1;
		uint32_t nsf                         : 1;
#endif
	} s;
	/* struct bdk_ap_dbgvcr32_el2_s       cn88xx; */
	/* struct bdk_ap_dbgvcr32_el2_s       cn88xxp1; */
} bdk_ap_dbgvcr32_el2_t;

#define BDK_AP_DBGVCR32_EL2 BDK_AP_DBGVCR32_EL2_FUNC()
static inline uint64_t BDK_AP_DBGVCR32_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGVCR32_EL2_FUNC(void)
{
	return 0x0000020400070000ull;
}
#define typedef_BDK_AP_DBGVCR32_EL2 bdk_ap_dbgvcr32_el2_t
#define bustype_BDK_AP_DBGVCR32_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGVCR32_EL2 0
#define arguments_BDK_AP_DBGVCR32_EL2 -1,-1,-1,-1
#define basename_BDK_AP_DBGVCR32_EL2 "AP_DBGVCR32_EL2"


/**
 * SYSREG - ap_dbgwcr#_el1
 *
 * Holds control information for a watchpoint. Forms watchpoint n
 * together with value register DBGWVR\<n\>_EL1, where n is 0 to
 * 15.
 */
typedef union bdk_ap_dbgwcrx_el1 {
	uint32_t u;
	struct bdk_ap_dbgwcrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_29_31              : 3;
		uint32_t mask                        : 5;  /**< R/W - Address mask. Only objects up to 2GB can be watched using a
                                                                     single mask.
                                                                 Other values mask the corresponding number of address bits.

                                                                 0x0 = No mask.
                                                                 0x1 = Reserved.
                                                                 0x2 = Reserved. */
		uint32_t reserved_21_23              : 3;
		uint32_t wt                          : 1;  /**< R/W - Watchpoint type.
                                                                 0 = Unlinked data address match.
                                                                 1 = Linked data address match. */
		uint32_t lbn                         : 4;  /**< R/W - Linked breakpoint number. For Linked data address watchpoints,
                                                                 this specifies the index of the Context-matching breakpoint
                                                                 linked to. */
		uint32_t ssc                         : 2;  /**< R/W - Security state control. Determines the Security states under
                                                                 which a watchpoint debug event for watchpoint n is generated.
                                                                 This field must be interpreted along with the HMC and PAC
                                                                 fields. */
		uint32_t hmc                         : 1;  /**< R/W - Higher mode control. Determines the debug perspective for
                                                                 deciding when a watchpoint debug event for watchpoint n is
                                                                 generated. This field must be interpreted along with the SSC
                                                                 and PAC fields. */
		uint32_t bas                         : 8;  /**< R/W - Byte address select. Each bit of this field selects whether a
                                                                     byte from within the word or double-word addressed by
                                                                     DBGWVR\<n\>_EL1 is being watched.

                                                                 xxxxxxx1    Match byte at DBGWVR\<n\>_EL1
                                                                 xxxxxx1x    Match byte at DBGWVR\<n\>_EL1+1
                                                                 xxxxx1xx    Match byte at DBGWVR\<n\>_EL1+2
                                                                 xxxx1xxx    Match byte at DBGWVR\<n\>_EL1+3

                                                                 In cases where DBGWVR\<n\>_EL1 addresses a double-word:
                                                                 BAS Description, if DBGWVR\<n\>_EL1[2] == 0

                                                                 xxx1xxxx    Match byte at DBGWVR\<n\>_EL1+4
                                                                 xx1xxxxx    Match byte at DBGWVR\<n\>_EL1+5
                                                                 x1xxxxxx    Match byte at DBGWVR\<n\>_EL1+6
                                                                 1xxxxxxx    Match byte at DBGWVR\<n\>_EL1+7

                                                                 If DBGWVR\<n\>_EL1[2] == 1, only BAS[3:0] is used. ARM
                                                                     deprecates setting DBGWVR\<n\>_EL1 == 1.
                                                                 If BAS is zero, no bytes are watched by this watchpoint.
                                                                 Ignored if E is 0. */
		uint32_t lsc                         : 2;  /**< R/W - Load/store control. This field enables watchpoint matching on
                                                                     the type of access being made.
                                                                 All other values are reserved, but must behave as if the
                                                                     watchpoint is disabled. Software must not rely on this
                                                                     property as the behavior of reserved values might change in a
                                                                     future revision of the architecture.
                                                                 Ignored if E is 0.
                                                                 0x1 = Match instructions that load from a watchpointed address.
                                                                 0x2 = Match instructions that store to a watchpointed address.
                                                                 0x3 = Match instructions that load from or store to a watchpointed
                                                                     address. */
		uint32_t pac                         : 2;  /**< R/W - Privilege of access control. Determines the Exception level or
                                                                 levels at which a watchpoint debug event for watchpoint n is
                                                                 generated. This field must be interpreted along with the SSC
                                                                 and HMC fields. */
		uint32_t ee                          : 1;  /**< R/W - Enable watchpoint n.
                                                                 0 = Watchpoint disabled.
                                                                 1 = Watchpoint enabled. */
#else
		uint32_t ee                          : 1;
		uint32_t pac                         : 2;
		uint32_t lsc                         : 2;
		uint32_t bas                         : 8;
		uint32_t hmc                         : 1;
		uint32_t ssc                         : 2;
		uint32_t lbn                         : 4;
		uint32_t wt                          : 1;
		uint32_t reserved_21_23              : 3;
		uint32_t mask                        : 5;
		uint32_t reserved_29_31              : 3;
#endif
	} s;
	/* struct bdk_ap_dbgwcrx_el1_s        cn88xx; */
	/* struct bdk_ap_dbgwcrx_el1_s        cn88xxp1; */
} bdk_ap_dbgwcrx_el1_t;

static inline uint64_t BDK_AP_DBGWCRX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGWCRX_EL1(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000020000000700ull + (param1 & 15) * 0x10000ull;
	csr_fatal("BDK_AP_DBGWCRX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_DBGWCRX_EL1(...) bdk_ap_dbgwcrx_el1_t
#define bustype_BDK_AP_DBGWCRX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGWCRX_EL1(p1) (p1)
#define arguments_BDK_AP_DBGWCRX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_DBGWCRX_EL1(...) "AP_DBGWCRX_EL1"


/**
 * SYSREG - ap_dbgwvr#_el1
 *
 * Holds a data address value for use in watchpoint matching.
 * Forms watchpoint n together with control register
 * DBGWCR\<n\>_EL1, where n is 0 to 15.
 */
typedef union bdk_ap_dbgwvrx_el1 {
	uint64_t u;
	struct bdk_ap_dbgwvrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ress                        : 15; /**< R/W - Reserved, Sign extended. Hardwired to the value of the sign
                                                                 bit, bit [48]. Hardware and software must treat this field as
                                                                 RES0 if bit[48] is 0, and as RES1 if bit[48] is 1. */
		uint64_t va                          : 47; /**< R/W - Bits[48:2] of the address value for comparison.
                                                                 ARM deprecates setting DBGWVR\<n\>_EL1[2] == 1. */
		uint64_t reserved_0_1                : 2;
#else
		uint64_t reserved_0_1                : 2;
		uint64_t va                          : 47;
		uint64_t ress                        : 15;
#endif
	} s;
	/* struct bdk_ap_dbgwvrx_el1_s        cn88xx; */
	/* struct bdk_ap_dbgwvrx_el1_s        cn88xxp1; */
} bdk_ap_dbgwvrx_el1_t;

static inline uint64_t BDK_AP_DBGWVRX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DBGWVRX_EL1(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000020000000600ull + (param1 & 15) * 0x10000ull;
	csr_fatal("BDK_AP_DBGWVRX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_DBGWVRX_EL1(...) bdk_ap_dbgwvrx_el1_t
#define bustype_BDK_AP_DBGWVRX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DBGWVRX_EL1(p1) (p1)
#define arguments_BDK_AP_DBGWVRX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_DBGWVRX_EL1(...) "AP_DBGWVRX_EL1"


/**
 * SYSREG - ap_dczid_el0
 *
 * This register indicates the block size that is written with byte values of 0 by the
 * DC ZVA (Data Cache Zero by Address) system instruction.
 */
typedef union bdk_ap_dczid_el0 {
	uint32_t u;
	struct bdk_ap_dczid_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t dzp                         : 1;  /**< RO - Data Zero prohibited.
                                                                 The value read from this field is governed by the access state
                                                                     and the values of the AP_HCR_EL2[TDZ] and AP_SCTLR_EL1[DZE] bits.
                                                                 0 =  DC ZVA instruction is permitted.
                                                                 1 =  DC ZVA instruction is prohibited. */
		uint32_t bs                          : 4;  /**< RO - Log2 of the block size in words. The maximum size supported is 2KB (value == 9).

                                                                 In CNXXXX, 128 bytes. */
#else
		uint32_t bs                          : 4;
		uint32_t dzp                         : 1;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	/* struct bdk_ap_dczid_el0_s          cn88xx; */
	/* struct bdk_ap_dczid_el0_s          cn88xxp1; */
} bdk_ap_dczid_el0_t;

#define BDK_AP_DCZID_EL0 BDK_AP_DCZID_EL0_FUNC()
static inline uint64_t BDK_AP_DCZID_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DCZID_EL0_FUNC(void)
{
	return 0x0000030300000700ull;
}
#define typedef_BDK_AP_DCZID_EL0 bdk_ap_dczid_el0_t
#define bustype_BDK_AP_DCZID_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DCZID_EL0 0
#define arguments_BDK_AP_DCZID_EL0 -1,-1,-1,-1
#define basename_BDK_AP_DCZID_EL0 "AP_DCZID_EL0"


/**
 * SYSREG - ap_dlr_el0
 *
 * In Debug state, holds the address to restart from.
 *
 */
typedef union bdk_ap_dlr_el0 {
	uint64_t u;
	struct bdk_ap_dlr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Restart address. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_dlr_el0_s            cn88xx; */
	/* struct bdk_ap_dlr_el0_s            cn88xxp1; */
} bdk_ap_dlr_el0_t;

#define BDK_AP_DLR_EL0 BDK_AP_DLR_EL0_FUNC()
static inline uint64_t BDK_AP_DLR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DLR_EL0_FUNC(void)
{
	return 0x0000030304050100ull;
}
#define typedef_BDK_AP_DLR_EL0 bdk_ap_dlr_el0_t
#define bustype_BDK_AP_DLR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DLR_EL0 0
#define arguments_BDK_AP_DLR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_DLR_EL0 "AP_DLR_EL0"


/**
 * SYSREG - ap_dspsr_el0
 *
 * Holds the saved processor state on entry to debug state.
 *
 */
typedef union bdk_ap_dspsr_el0 {
	uint32_t u;
	struct bdk_ap_dspsr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t n                           : 1;  /**< R/W - Set to the value of CPSR[N] on entering Debug state, and copied
                                                                 to CPSR[N] on exiting Debug state. */
		uint32_t z                           : 1;  /**< R/W - Set to the value of CPSR[Z] on entering Debug state, and copied
                                                                 to CPSR[Z] on exiting Debug state. */
		uint32_t cc                          : 1;  /**< R/W - Set to the value of CPSR[C] on entering Debug state, and copied
                                                                 to CPSR[C] on exiting Debug state. */
		uint32_t v                           : 1;  /**< R/W - Set to the value of CPSR[V] on entering Debug state, and copied
                                                                 to CPSR[V] on exiting Debug state. */
		uint32_t reserved_22_27              : 6;
		uint32_t ss                          : 1;  /**< R/W - Software step. Indicates whether software step was enabled when
                                                                 Debug state was entered. */
		uint32_t il                          : 1;  /**< R/W - Illegal Execution State bit. Shows the value of PSTATE[IL]
                                                                 immediately before Debug state was entered. */
		uint32_t reserved_10_19              : 10;
		uint32_t dd                          : 1;  /**< R/W - Interrupt masks - can also be accessed as PSTATE.[D,A,I,F] */
		uint32_t aa                          : 1;  /**< R/W - Asynchronous data abort mask bit.
                                                                 0 = Exception not masked.
                                                                 1 = Exception masked. */
		uint32_t i                           : 1;  /**< R/W - IRQ mask bit.
                                                                 0 = Exception not masked.
                                                                 1 = Exception masked. */
		uint32_t f                           : 1;  /**< R/W - FIQ mask bit.
                                                                 0 = Exception not masked.
                                                                 1 = Exception masked. */
		uint32_t reserved_5_5                : 1;
		uint32_t nrw                         : 1;  /**< R/W - Current register width:  0 = AArch64, 1 = AArch32. */
		uint32_t el                          : 2;  /**< R/W - Current exception level: 0x0 = EL0, 0x1 = EL1, 0x2 = EL2, 0x3 = EL3. */
		uint32_t reserved_1_1                : 1;
		uint32_t sp                          : 1;  /**< R/W - AArch64 only - Stack Pointer selection - 0 - SP0, 1 - SPx. */
#else
		uint32_t sp                          : 1;
		uint32_t reserved_1_1                : 1;
		uint32_t el                          : 2;
		uint32_t nrw                         : 1;
		uint32_t reserved_5_5                : 1;
		uint32_t f                           : 1;
		uint32_t i                           : 1;
		uint32_t aa                          : 1;
		uint32_t dd                          : 1;
		uint32_t reserved_10_19              : 10;
		uint32_t il                          : 1;
		uint32_t ss                          : 1;
		uint32_t reserved_22_27              : 6;
		uint32_t v                           : 1;
		uint32_t cc                          : 1;
		uint32_t z                           : 1;
		uint32_t n                           : 1;
#endif
	} s;
	/* struct bdk_ap_dspsr_el0_s          cn88xx; */
	/* struct bdk_ap_dspsr_el0_s          cn88xxp1; */
} bdk_ap_dspsr_el0_t;

#define BDK_AP_DSPSR_EL0 BDK_AP_DSPSR_EL0_FUNC()
static inline uint64_t BDK_AP_DSPSR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_DSPSR_EL0_FUNC(void)
{
	return 0x0000030304050000ull;
}
#define typedef_BDK_AP_DSPSR_EL0 bdk_ap_dspsr_el0_t
#define bustype_BDK_AP_DSPSR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_DSPSR_EL0 0
#define arguments_BDK_AP_DSPSR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_DSPSR_EL0 "AP_DSPSR_EL0"


/**
 * SYSREG - ap_elr_el#
 *
 * Return address for exception
 *
 */
typedef union bdk_ap_elr_elx {
	uint64_t u;
	struct bdk_ap_elr_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t address                     : 64; /**< R/W - Return address for exception. */
#else
		uint64_t address                     : 64;
#endif
	} s;
	/* struct bdk_ap_elr_elx_s            cn88xx; */
	/* struct bdk_ap_elr_elx_s            cn88xxp1; */
} bdk_ap_elr_elx_t;

static inline uint64_t BDK_AP_ELR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ELR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x0000030004000100ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_ELR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ELR_ELX(...) bdk_ap_elr_elx_t
#define bustype_BDK_AP_ELR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ELR_ELX(p1) (p1)
#define arguments_BDK_AP_ELR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ELR_ELX(...) "AP_ELR_ELX"


/**
 * SYSREG - ap_elr_el12
 *
 * Alias to allow EL2/3 access to ELR_EL1 when AP_HCR_EL2[E2H]==1.
 *
 */
typedef union bdk_ap_elr_el12 {
	uint64_t u;
	struct bdk_ap_elr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t address                     : 64; /**< R/W - Return address for exception. */
#else
		uint64_t address                     : 64;
#endif
	} s;
	/* struct bdk_ap_elr_el12_s           cn88xx; */
	/* struct bdk_ap_elr_el12_s           cn88xxp1; */
} bdk_ap_elr_el12_t;

#define BDK_AP_ELR_EL12 BDK_AP_ELR_EL12_FUNC()
static inline uint64_t BDK_AP_ELR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ELR_EL12_FUNC(void)
{
	return 0x0000030504000100ull;
}
#define typedef_BDK_AP_ELR_EL12 bdk_ap_elr_el12_t
#define bustype_BDK_AP_ELR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ELR_EL12 0
#define arguments_BDK_AP_ELR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_ELR_EL12 "AP_ELR_EL12"


/**
 * SYSREG - ap_esr_el#
 *
 * Holds syndrome information for an exception taken to EL*.
 *
 */
typedef union bdk_ap_esr_elx {
	uint32_t u;
	struct bdk_ap_esr_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ec                          : 6;  /**< R/W - Exception Class. Indicates the reason for the exception that
                                                                     this register holds information about.

                                                                 0x0 = Unknown or Uncategorized Reason - generally used for
                                                                     exceptions as a result of erroneous execution.
                                                                 0x1 = Exceptions from WFE/WFI from either AArch32 or AArch64 as a
                                                                     result of configurable traps, enables, or disables.

                                                                 Conditional WFE and WFI instructions that fail their condition
                                                                     code check do not cause an exception.

                                                                 0x3 = Exceptions from MCR/MRC to CP15 from AArch32 as a result of
                                                                     configurable traps, enables, or disables that do not use
                                                                     code 0x0.
                                                                 0x4 = Exceptions from MCRR/MRRC to CP15 from AArch32 as a result of
                                                                     configurable traps, enables, or disables that do not use
                                                                     code 0x0.
                                                                 0x5 = Exceptions from MCR/MRC to CP14 from AArch32 as a result of
                                                                     configurable traps, enables, or disables that do not use
                                                                     code 0x0.
                                                                 0x6 = Exceptions from LDC/STC to CP14 from AArch32 as a result of
                                                                     configurable traps, enables, or disables. The only architected
                                                                     uses of these instructions to access CP14 are:
                                                                  An STC to write to AP_DBGDTRRX_EL0 or DBGDTRRXint.
                                                                  An LDC to read from AP_DBGDTRTX_EL0 or DBGDTRTXint.

                                                                 0x7 = Exceptions from access to Advanced SIMD or Floating Point as a
                                                                     result of configurable traps, enables, or disables.
                                                                 0xC = Exceptions from MCRR/MRRC to CP14 from AArch32 as a result of
                                                                     configurable traps, enables, or disables.
                                                                 0xE = Exceptions that occur because the value of PSTATE[IL] is 1.
                                                                 0x13 =SMC that is not disabled executed in AArch32.
                                                                 0x15 = SVC executed in AArch64.
                                                                 0x16 = HVC that is not disabled executed in AArch64.
                                                                 0x17 = SMC that is not disabled executed in AArch64.
                                                                 0x18 = Exceptions as a result of MSR, MRS, or System AArch64
                                                                     instructions as a result of configurable traps, enables, or
                                                                     disables, except those using codes0b0000000b0000010b000111
                                                                 0x20 = Instruction Abort that caused entry from a lower Exception
                                                                     level (AArch32 or AArch64). Used for instruction access
                                                                     generated MMU faults and synchronous external aborts,
                                                                     including synchronous parity errors. Not used for debug
                                                                     related exceptions.
                                                                 0x21 = Instruction Abort that caused entry from a current Exception
                                                                     level (AArch64). Used for instruction access generated MMU
                                                                     faults and synchronous external aborts, including synchronous
                                                                     parity errors. Not used for debug related exceptions.
                                                                 0x22 = PC Alignment Exception.
                                                                 0x24 = Data Abort that caused entry from a lower Exception level
                                                                     (AArch32 or AArch64). Used for data access generated MMU
                                                                     faults, alignment faults other than those caused by the Stack
                                                                     Pointer misalignment, and synchronous external aborts,
                                                                     including synchronous parity errors. Not used for debug
                                                                     related exceptions.
                                                                 0x25 = Data Abort that caused entry from a current Exception level
                                                                     (AArch64). Used for data access generated MMU faults,
                                                                     alignment faults other than those caused by the Stack Pointer
                                                                     misalignment, and synchronous external aborts, including
                                                                     synchronous parity errors. Not used for debug related
                                                                     exceptions.
                                                                 0x26 = Stack Pointer Alignment Exception.
                                                                 0x2C = Exceptions as a result of Floating-point exception (optional
                                                                     feature) from AArch64.
                                                                 0x2F = SError Interrupt.
                                                                 0x3C = BRK instruction executed in AArch64 state. */
		uint32_t il                          : 1;  /**< R/W - Instruction Length for synchronous exceptions.
                                                                 0 = 16-bit instruction trapped.
                                                                 1 = 32-bit instruction trapped. This value is also used when the
                                                                     exception is one of the following:
                                                                  * An SError interrupt.
                                                                  * An Instruction Abort exception.
                                                                  * A Misaligned PC exception.
                                                                  * A Misaligned Stack Pointer exception.
                                                                  * A Data Abort exception for which the value of the ISV bit is 0.
                                                                  * An Illegal Execution State exception.
                                                                  * Any debug exception except for Software Breakpoint
                                                                     Instruction exceptions. For Software Breakpoint Instruction
                                                                     exceptions, this bit has its standard meaning:- 0: 16-bit T32
                                                                     BKPT instruction. - 1: 32-bit A32 BKPT instruction or A64 BRK
                                                                     instruction.
                                                                  * An exception reported using EC value 0b000000. */
		uint32_t iss                         : 25; /**< R/W - Instruction Specific Syndrome. Architecturally, this field can
                                                                     be defined independently for each defined Exception class.
                                                                     However, in practice, some ISS encodings are used for more
                                                                     than one Exception class.

                                                                 Typically, an ISS encoding has a number of subfields. When an
                                                                     ISS subfield holds a register number, the value returned in
                                                                     that field is the AArch64 view of the register number, even if
                                                                     the reported exception was taken from AArch32 state. If the
                                                                     register number is AArch32 register R15, then:

                                                                  If the instruction that generated the exception was not
                                                                     UNPREDICTABLE, the field takes the value 0b11111.

                                                                  If the instruction that generated the exception was
                                                                     UNPREDICTABLE, the field takes an UNKNOWN value that must be
                                                                     either: The AArch64 view of the register number of a register
                                                                     that     might have been used at the Exception level from
                                                                     which the     exception was taken.  The value 0b11111.

                                                                 When the EC field is0b000000 RES0. */
#else
		uint32_t iss                         : 25;
		uint32_t il                          : 1;
		uint32_t ec                          : 6;
#endif
	} s;
	/* struct bdk_ap_esr_elx_s            cn88xx; */
	/* struct bdk_ap_esr_elx_s            cn88xxp1; */
} bdk_ap_esr_elx_t;

static inline uint64_t BDK_AP_ESR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ESR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x0000030005020000ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_ESR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ESR_ELX(...) bdk_ap_esr_elx_t
#define bustype_BDK_AP_ESR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ESR_ELX(p1) (p1)
#define arguments_BDK_AP_ESR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ESR_ELX(...) "AP_ESR_ELX"


/**
 * SYSREG - ap_esr_el12
 *
 * Alias of ESR_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_esr_el12 {
	uint32_t u;
	struct bdk_ap_esr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_esr_el12_s           cn88xx; */
	/* struct bdk_ap_esr_el12_s           cn88xxp1; */
} bdk_ap_esr_el12_t;

#define BDK_AP_ESR_EL12 BDK_AP_ESR_EL12_FUNC()
static inline uint64_t BDK_AP_ESR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ESR_EL12_FUNC(void)
{
	return 0x0000030505020000ull;
}
#define typedef_BDK_AP_ESR_EL12 bdk_ap_esr_el12_t
#define bustype_BDK_AP_ESR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ESR_EL12 0
#define arguments_BDK_AP_ESR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_ESR_EL12 "AP_ESR_EL12"


/**
 * SYSREG - ap_far_el#
 *
 * Holds the faulting Virtual Address for all synchronous
 * instruction or data aborts, or exceptions from a misaligned
 * PC, taken to EL*.
 */
typedef union bdk_ap_far_elx {
	uint64_t u;
	struct bdk_ap_far_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Faulting Virtual Address for exceptions taken to EL*.
                                                                     Exceptions that set the FAR_EL* are all synchronous
                                                                     instruction aborts or data aborts, or an exception from a
                                                                     misaligned PC.
                                                                 If a memory fault that sets FAR_EL* is generated from one of
                                                                     the data cache instructions, this field holds the address
                                                                     specified in the register argument of the instruction. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_far_elx_s            cn88xx; */
	/* struct bdk_ap_far_elx_s            cn88xxp1; */
} bdk_ap_far_elx_t;

static inline uint64_t BDK_AP_FAR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_FAR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x0000030006000000ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_FAR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_FAR_ELX(...) bdk_ap_far_elx_t
#define bustype_BDK_AP_FAR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_FAR_ELX(p1) (p1)
#define arguments_BDK_AP_FAR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_FAR_ELX(...) "AP_FAR_ELX"


/**
 * SYSREG - ap_far_el12
 *
 * Alias of ESR_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_far_el12 {
	uint64_t u;
	struct bdk_ap_far_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_far_el12_s           cn88xx; */
	/* struct bdk_ap_far_el12_s           cn88xxp1; */
} bdk_ap_far_el12_t;

#define BDK_AP_FAR_EL12 BDK_AP_FAR_EL12_FUNC()
static inline uint64_t BDK_AP_FAR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_FAR_EL12_FUNC(void)
{
	return 0x0000030506000000ull;
}
#define typedef_BDK_AP_FAR_EL12 bdk_ap_far_el12_t
#define bustype_BDK_AP_FAR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_FAR_EL12 0
#define arguments_BDK_AP_FAR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_FAR_EL12 "AP_FAR_EL12"


/**
 * SYSREG - ap_fpcr
 *
 * Controls floating-point extension behavior.
 *
 */
typedef union bdk_ap_fpcr {
	uint32_t u;
	struct bdk_ap_fpcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_27_31              : 5;
		uint32_t ahp                         : 1;  /**< R/W - Alternative half-precision control bit:
                                                                 0 = IEEE half-precision format selected.
                                                                 1 = Alternative half-precision format selected. */
		uint32_t dn                          : 1;  /**< R/W - Default NaN mode control bit:
                                                                 The value of this bit controls both scalar and Advanced SIMD
                                                                     floating-point arithmetic.
                                                                 0 = NaN operands propagate through to the output of a floating-
                                                                     point operation.
                                                                 1 = Any operation involving one or more NaNs returns the Default
                                                                     NaN. */
		uint32_t fz                          : 1;  /**< R/W - Flush-to-zero mode control bit:
                                                                 The value of this bit controls both scalar and Advanced SIMD
                                                                     floating-point arithmetic.
                                                                 0 = Flush-to-zero mode disabled. Behavior of the floating-point
                                                                     system is fully compliant with the IEEE 754 standard.
                                                                 1 = Flush-to-zero mode enabled. */
		uint32_t rmode                       : 2;  /**< R/W - Rounding Mode control field. The encoding of this field is:
                                                                 The specified rounding mode is used by both scalar and
                                                                     Advanced SIMD floating-point instructions.
                                                                 0x0 = Round to Nearest (RN) mode.
                                                                 0x1 = Round towards Plus Infinity (RP) mode.
                                                                 0x2 = Round towards Minus Infinity (RM) mode.
                                                                 0x3 = Round towards Zero (RZ) mode. */
		uint32_t reserved_0_21               : 22;
#else
		uint32_t reserved_0_21               : 22;
		uint32_t rmode                       : 2;
		uint32_t fz                          : 1;
		uint32_t dn                          : 1;
		uint32_t ahp                         : 1;
		uint32_t reserved_27_31              : 5;
#endif
	} s;
	/* struct bdk_ap_fpcr_s               cn88xx; */
	/* struct bdk_ap_fpcr_s               cn88xxp1; */
} bdk_ap_fpcr_t;

#define BDK_AP_FPCR BDK_AP_FPCR_FUNC()
static inline uint64_t BDK_AP_FPCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_FPCR_FUNC(void)
{
	return 0x0000030304040000ull;
}
#define typedef_BDK_AP_FPCR bdk_ap_fpcr_t
#define bustype_BDK_AP_FPCR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_FPCR 0
#define arguments_BDK_AP_FPCR -1,-1,-1,-1
#define basename_BDK_AP_FPCR "AP_FPCR"


/**
 * SYSREG - ap_fpexc32_el2
 *
 * Allows access to the AArch32 register FPEXC from AArch64 state
 * only. Its value has no effect on execution in AArch64 state.
 */
typedef union bdk_ap_fpexc32_el2 {
	uint32_t u;
	struct bdk_ap_fpexc32_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_fpexc32_el2_s        cn88xx; */
	/* struct bdk_ap_fpexc32_el2_s        cn88xxp1; */
} bdk_ap_fpexc32_el2_t;

#define BDK_AP_FPEXC32_EL2 BDK_AP_FPEXC32_EL2_FUNC()
static inline uint64_t BDK_AP_FPEXC32_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_FPEXC32_EL2_FUNC(void)
{
	return 0x0000030405030000ull;
}
#define typedef_BDK_AP_FPEXC32_EL2 bdk_ap_fpexc32_el2_t
#define bustype_BDK_AP_FPEXC32_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_FPEXC32_EL2 0
#define arguments_BDK_AP_FPEXC32_EL2 -1,-1,-1,-1
#define basename_BDK_AP_FPEXC32_EL2 "AP_FPEXC32_EL2"


/**
 * SYSREG - ap_fpsr
 *
 * Provides floating-point system status information.
 *
 */
typedef union bdk_ap_fpsr {
	uint32_t u;
	struct bdk_ap_fpsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t qc                          : 1;  /**< R/W - Cumulative saturation bit, Advanced SIMD only. This bit is set
                                                                 to 1 to indicate that an Advanced SIMD integer operation has
                                                                 saturated since 0 was last written to this bit. */
		uint32_t reserved_8_26               : 19;
		uint32_t idc                         : 1;  /**< R/W - Input Denormal cumulative exception bit. This bit is set to 1
                                                                     to indicate that the Input Denormal exception has occurred
                                                                     since 0 was last written to this bit.

                                                                 How scalar and Advanced SIMD floating-point instructions
                                                                     update this bit depends on the value of the AP_FPCR[IDE] bit. This
                                                                     bit is only set to 1 to indicate an exception if AP_FPCR[IDE] is
                                                                     0, or if trapping software sets it. */
		uint32_t reserved_5_6                : 2;
		uint32_t ixc                         : 1;  /**< R/W - Inexact cumulative exception bit. This bit is set to 1 to
                                                                     indicate that the Inexact exception has occurred since 0 was
                                                                     last written to this bit.

                                                                 How scalar and Advanced SIMD floating-point instructions
                                                                     update this bit depends on the value of the AP_FPCR[IXE] bit. This
                                                                     bit is only set to 1 to indicate an exception if AP_FPCR[IXE] is
                                                                     0, or if trapping software sets it. */
		uint32_t ufc                         : 1;  /**< R/W - Underflow cumulative exception bit. This bit is set to 1 to
                                                                     indicate that the Underflow exception has occurred since 0 was
                                                                     last written to this bit.

                                                                 How scalar and Advanced SIMD floating-point instructions
                                                                     update this bit depends on the value of the AP_FPCR[UFE] bit. This
                                                                     bit is only set to 1 to indicate an exception if AP_FPCR[UFE] is
                                                                     0, or if trapping software sets it. */
		uint32_t ofc                         : 1;  /**< R/W - Overflow cumulative exception bit. This bit is set to 1 to
                                                                     indicate that the Overflow exception has occurred since 0 was
                                                                     last written to this bit.

                                                                 How scalar and Advanced SIMD floating-point instructions
                                                                     update this bit depends on the value of the AP_FPCR[OFE] bit. This
                                                                     bit is only set to 1 to indicate an exception if AP_FPCR[OFE] is
                                                                     0, or if trapping software sets it. */
		uint32_t dzc                         : 1;  /**< R/W - Division by Zero cumulative exception bit. This bit is set to
                                                                     1 to indicate that the Division by Zero exception has occurred
                                                                     since 0 was last written to this bit.

                                                                 How scalar and Advanced SIMD floating-point instructions
                                                                     update this bit depends on the value of the AP_FPCR[DZE] bit. This
                                                                     bit is only set to 1 to indicate an exception if AP_FPCR[DZE] is
                                                                     0, or if trapping software sets it. */
		uint32_t ioc                         : 1;  /**< R/W - Invalid Operation cumulative exception bit. This bit is set to
                                                                     1 to indicate that the Invalid Operation exception has
                                                                     occurred since 0 was last written to this bit.

                                                                 How scalar and Advanced SIMD floating-point instructions
                                                                     update this bit depends on the value of the AP_FPCR[IOE] bit. This
                                                                     bit is only set to 1 to indicate an exception if AP_FPCR[IOE] is
                                                                     0, or if trapping software sets it. */
#else
		uint32_t ioc                         : 1;
		uint32_t dzc                         : 1;
		uint32_t ofc                         : 1;
		uint32_t ufc                         : 1;
		uint32_t ixc                         : 1;
		uint32_t reserved_5_6                : 2;
		uint32_t idc                         : 1;
		uint32_t reserved_8_26               : 19;
		uint32_t qc                          : 1;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	/* struct bdk_ap_fpsr_s               cn88xx; */
	/* struct bdk_ap_fpsr_s               cn88xxp1; */
} bdk_ap_fpsr_t;

#define BDK_AP_FPSR BDK_AP_FPSR_FUNC()
static inline uint64_t BDK_AP_FPSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_FPSR_FUNC(void)
{
	return 0x0000030304040100ull;
}
#define typedef_BDK_AP_FPSR bdk_ap_fpsr_t
#define bustype_BDK_AP_FPSR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_FPSR 0
#define arguments_BDK_AP_FPSR -1,-1,-1,-1
#define basename_BDK_AP_FPSR "AP_FPSR"


/**
 * SYSREG - ap_hacr_el2
 *
 * Controls trapping to EL2 of implementation defined aspects of
 * non-secure EL1 or EL0 operation.
 */
typedef union bdk_ap_hacr_el2 {
	uint32_t u;
	struct bdk_ap_hacr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_hacr_el2_s           cn88xx; */
	/* struct bdk_ap_hacr_el2_s           cn88xxp1; */
} bdk_ap_hacr_el2_t;

#define BDK_AP_HACR_EL2 BDK_AP_HACR_EL2_FUNC()
static inline uint64_t BDK_AP_HACR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_HACR_EL2_FUNC(void)
{
	return 0x0000030401010700ull;
}
#define typedef_BDK_AP_HACR_EL2 bdk_ap_hacr_el2_t
#define bustype_BDK_AP_HACR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_HACR_EL2 0
#define arguments_BDK_AP_HACR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_HACR_EL2 "AP_HACR_EL2"


/**
 * SYSREG - ap_hcr_el2
 *
 * Provides configuration controls for virtualization, including
 * defining whether various non-secure operations are trapped to
 * EL2.
 */
typedef union bdk_ap_hcr_el2 {
	uint64_t u;
	struct bdk_ap_hcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t tlor                        : 1;  /**< R/W - v8.1: Trap access to the LOR Registers from non-secure EL1 to EL2.
                                                                 0 = Non-secure EL1 accesses to the LOR Registers are not trapped to EL2.
                                                                 1 = Non-secure EL1 accesses to the LOR Registers are trapped to EL2. */
		uint64_t e2h                         : 1;  /**< R/W - V8.1: Enable EL2 host. */
		uint64_t id                          : 1;  /**< R/W - Stage 2 Instruction cache disable. When AP_HCR_EL2[VM]==1, this
                                                                     forces all stage 2 translations for instruction accesses to
                                                                     Normal memory to be Non-cacheable for the EL1&0 translation
                                                                     regime.
                                                                 This bit has no effect on the EL2 or EL3 translation regimes.
                                                                 0 = No effect on the stage 2 of the EL1&0 translation regime for
                                                                     instruction accesses.
                                                                 1 = Forces all stage 2 translations for instruction accesses to
                                                                     Normal memory to be Non-cacheable for the EL1&0 translation
                                                                     regime. */
		uint64_t cd                          : 1;  /**< R/W - Stage 2 Data cache disable. When AP_HCR_EL2[VM]==1, this forces
                                                                     all stage 2 translations for data accesses and translation
                                                                     table walks to Normal memory to be Non-cacheable for the EL1&0
                                                                     translation regime.
                                                                 This bit has no effect on the EL2 or EL3 translation regimes.
                                                                 0 = No effect on the stage 2 of the EL1&0 translation regime for
                                                                     data accesses and translation table walks.
                                                                 1 = Forces all stage 2 translations for data accesses and
                                                                     translation table walks to Normal memory to be Non-cacheable
                                                                     for the EL1&0 translation regime. */
		uint64_t rsvd_31                     : 1;  /**< RO - rw - Register Width control for lower exception levels:
                                                                 When AP_SCR_EL3[NS]==0, this bit behaves as if it has the same
                                                                     value as the AP_SCR_EL3[RW] bit except for the value read back.
                                                                 The RW bit is permitted to be cached in a TLB.
                                                                 0 = Lower levels are all AArch32.
                                                                 1 = EL1 is AArch64. EL0 is determined by the Execution state
                                                                     described in the current process state when executing at EL0. */
		uint64_t trvm                        : 1;  /**< R/W - Trap Read of Virtual Memory controls. When this bit is set to
                                                                     1, this causes Reads to the EL1 virtual memory control
                                                                     registers from EL1 to be trapped to EL2. This covers the
                                                                     following registers:

                                                                 AArch32: SCTLR, TTBR0, TTBR1, TTBCR, DACR, DFSR, IFSR, DFAR,
                                                                     IFAR, ADFSR, AIFSR, PRRR/ MAIR0, NMRR/ MAIR1, AMAIR0, AMAIR1,
                                                                     CONTEXTIDR.

                                                                 AArch64: AP_SCTLR_EL1, AP_TTBR0_EL1, AP_TTBR1_EL1, AP_TCR_EL1, ESR_EL1,
                                                                     FAR_EL1, AFSR0_EL1, AFSR1_EL1, MAIR_EL1, AMAIR_EL1,
                                                                     AP_CONTEXTIDR_EL1. */
		uint64_t reserved_29_29              : 1;
		uint64_t tdz                         : 1;  /**< R/W - Trap DC ZVA instruction:
                                                                 This bit also has an effect on the value read from the
                                                                     AP_DCZID_EL0 register. If this bit is 1, then reading
                                                                     AP_DCZID_EL0[DZP] from non-secure EL1 or EL0 will return 1 to
                                                                     indicate that DC ZVA is prohibited.
                                                                 0 = The instruction is not trapped.
                                                                 1 = The instruction is trapped to EL2 when executed in non-secure
                                                                     EL1 or EL0. */
		uint64_t tge                         : 1;  /**< R/W - Trap General Exceptions. If this bit is set to 1, and
                                                                     AP_SCR_EL3[NS] is set to 1, then:

                                                                  All exceptions that would be routed to EL1 are routed to EL2.

                                                                  The AP_SCTLR_EL1[M] bit is treated as being 0 regardless of its
                                                                     actual state (for EL1 using AArch32 or AArch64) other than for
                                                                     the purpose of reading the bit.

                                                                  The AP_HCR_EL2[FMO], IMO and AMO bits are treated as being 1
                                                                     regardless of their actual state other than for the purpose of
                                                                     reading the bits.

                                                                  All virtual interrupts are disabled.

                                                                  Any implementation defined mechanisms for signalling virtual
                                                                     interrupts are disabled.

                                                                  An exception return to EL1 is treated as an illegal exception
                                                                     return.

                                                                 Additionally, if AP_HCR_EL2[TGE] == 1, the
                                                                     AP_MDCR_EL2.{TDRA,TDOSA,TDA} bits are ignored and the processor
                                                                     behaves as if they are set to 1, other than for the value read
                                                                     back from AP_MDCR_EL2. */
		uint64_t tvm                         : 1;  /**< R/W - Trap Virtual Memory controls. When this bit is set to 1, this
                                                                     causes Writes to the EL1 virtual memory control registers from
                                                                     EL1 to be trapped to EL2. This covers the following registers:

                                                                 AArch32: SCTLR, TTBR0, TTBR1, TTBCR, DACR, DFSR, IFSR, DFAR,
                                                                     IFAR, ADFSR, AIFSR, PRRR/ MAIR0, NMRR/ MAIR1, AMAIR0, AMAIR1,
                                                                     CONTEXTIDR.

                                                                 AArch64: AP_SCTLR_EL1, AP_TTBR0_EL1, AP_TTBR1_EL1, AP_TCR_EL1, ESR_EL1,
                                                                     FAR_EL1, AFSR0_EL1, AFSR1_EL1, MAIR_EL1, AMAIR_EL1,
                                                                     AP_CONTEXTIDR_EL1 */
		uint64_t ttlb                        : 1;  /**< R/W - Trap TLB maintenance instructions. When this bit is set to 1,
                                                                     this causes TLB maintenance instructions executed from EL1
                                                                     which are not UNdefined to be trapped to EL2. This covers the
                                                                     following instructions:

                                                                 AArch32: TLBIALLIS, TLBIMVAIS, TLBIASIDIS, TLBIMVAAIS,
                                                                     TLBIALL, TLBIMVA, TLBIASID, DTLBIALL, DTLBIMVA, DTLBIASID,
                                                                     ITLBIALL, ITLBIMVA, ITLBIASID, TLBIMVAA, TLBIMVALIS,
                                                                     TLBIMVAALIS, TLBIMVAL, TLBIMVAAL

                                                                 AArch64: TLBI VMALLE1, TLBI VAE1, TLBI ASIDE1, TLBI VAAE1,
                                                                     TLBI VALE1, TLBI VAALE1, TLBI VMALLE1IS, TLBI VAE1IS, TLBI
                                                                     ASIDE1IS, TLBI VAAE1IS, TLBI VALE1IS, TLBI VAALE1IS */
		uint64_t tpu                         : 1;  /**< R/W - Trap Cache maintenance instructions to Point of Unification.
                                                                     When this bit is set to 1, this causes Cache maintenance
                                                                     instructions to the point of unification executed from EL1 or
                                                                     EL0 which are not UNdefined to be trapped to EL2. This covers
                                                                     the following instructions:

                                                                 AArch32: ICIMVAU, ICIALLU, ICIALLUIS, DCCMVAU.

                                                                 AArch64: IC IVAU, IC IALLU, IC IALLUIS, DC CVAU. */
		uint64_t tpc                         : 1;  /**< R/W - Trap Data/Unified Cache maintenance operations to Point of
                                                                     Coherency. When this bit is set to 1, this causes Data or
                                                                     Unified Cache maintenance instructions by address to the point
                                                                     of coherency executed from EL1 or EL0 which are not UNdefined
                                                                     to be trapped to EL2. This covers the following instructions:

                                                                 AArch32: DCIMVAC, DCCIMVAC, DCCMVAC.

                                                                 AArch64: DC IVAC, DC CIVAC, DC CVAC. */
		uint64_t tsw                         : 1;  /**< R/W - Trap Data/Unified Cache maintenance operations by Set/Way.
                                                                     When this bit is set to 1, this causes Data or Unified Cache
                                                                     maintenance instructions by set/way executed from EL1 which
                                                                     are not UNdefined to be trapped to EL2. This covers the
                                                                     following instructions:

                                                                 AArch32: DCISW, DCCSW, DCCISW.

                                                                 AArch64: DC ISW, DC CSW, DC CISW. */
		uint64_t tacr                        : 1;  /**< R/W - Trap Auxiliary Control Register. When this bit is set to 1,
                                                                     this causes accesses to the following registers executed from
                                                                     EL1 to be trapped to EL2:

                                                                 AArch32: ACTLR.

                                                                 AArch64: ACTLR_EL1. */
		uint64_t tidcp                       : 1;  /**< R/W - Trap Implementation Dependent functionality. When this bit is
                                                                     set to 1, this causes accesses to the following instruction
                                                                     set space executed from EL1 to be trapped to EL2.

                                                                 AArch32: MCR and MRC instructions as follows:

                                                                  All CP15, CRn==9,  Opcode1 = {0-7}, CRm == {c0-c2, c5-c8},
                                                                     opcode2 == {0-7}.

                                                                  All CP15, CRn==10, Opcode1 =={0-7}, CRm == {c0, c1, c4, c8},
                                                                     opcode2 == {0-7}.

                                                                  All CP15, CRn==11, Opcode1=={0-7}, CRm == {c0-c8, c15},
                                                                     opcode2 == {0-7}.

                                                                 AArch64: All encoding space reserved for implementation
                                                                     defined system operations ( S1_\<op1\>_\<Cn\>_\<Cm\>_\<op2\>) and
                                                                     system registers ( S3_\<op1\>_\<Cn\>_\<Cm\>_\<op2\>).

                                                                 It is implementation defined whether any of this functionality
                                                                     accessed from EL0 is trapped to EL2 when the AP_HCR_EL2[TIDCP] bit
                                                                     is set. If it is not trapped to EL2, it results in an
                                                                     Undefined exception taken to EL1. */
		uint64_t tsc                         : 1;  /**< R/W - Trap SMC. When this bit is set to 1, this causes the following
                                                                     instructions executed from EL1 to be trapped to EL2:

                                                                 AArch32: SMC.

                                                                 AArch64: SMC.

                                                                 If EL3 is not implemented, this bit is RES0. */
		uint64_t tid3                        : 1;  /**< R/W - Trap ID Group 3. When this bit is set to 1, this causes reads
                                                                     to the following registers executed from EL1 to be trapped to
                                                                     EL2:

                                                                 AArch32: ID_PFR0, ID_PFR1, ID_DFR0, ID_AFR0, ID_MMFR0,
                                                                     ID_MMFR1, ID_MMFR2, ID_MMFR3, ID_ISAR0, ID_ISAR1, ID_ISAR2,
                                                                     ID_ISAR3, ID_ISAR4, ID_ISAR5, MVFR0, MVFR1, MVFR2. Also MRC to
                                                                     any of the following encodings:

                                                                  CP15, CRn == 0, Opc1 == 0, CRm == {3-7}, Opc2 == {0,1}.

                                                                  CP15, CRn == 0, Opc1 == 0, CRm == 3, Opc2 == 2.

                                                                  CP15, CRn == 0, Opc1 == 0, CRm == 5, Opc2 == {4,5}.

                                                                 AArch64: AP_ID_PFR0_EL1, AP_ID_PFR1_EL1, AP_ID_DFR0_EL1, AP_ID_AFR0_EL1,
                                                                     ID_MMFR0_EL1, ID_MMFR1_EL1, ID_MMFR2_EL1, ID_MMFR3_EL1,
                                                                     ID_ISAR0_EL1, ID_ISAR1_EL1, ID_ISAR2_EL1, ID_ISAR3_EL1,
                                                                     ID_ISAR4_EL1, ID_ISAR5_EL1, MVFR0_EL1, MVFR1_EL1, MVFR2_EL1,
                                                                     AP_ID_AA64PFR0_EL1, AP_ID_AA64PFR1_EL1, AP_ID_AA64DFR0_EL1,
                                                                     AP_ID_AA64DFR1_EL1, AP_ID_AA64ISAR0_EL1, AP_ID_AA64ISAR1_EL1,
                                                                     AP_ID_AA64MMFR0_EL1, AP_ID_AA64MMFR1_EL1, AP_ID_AA64AFR0_EL1,
                                                                     AP_ID_AA64AFR1_EL1. */
		uint64_t tid2                        : 1;  /**< R/W - Trap ID Group 2. When this bit is set to 1, this causes reads
                                                                     (or writes to CSSELR/ AP_CSSELR_EL1) to the following registers
                                                                     executed from EL1 or EL0 if not UNdefined to be trapped to
                                                                     EL2:

                                                                 AArch32: CTR, CCSIDR, CLIDR, CSSELR.

                                                                 AArch64: AP_CTR_EL0, AP_CCSIDR_EL1, AP_CLIDR_EL1, AP_CSSELR_EL1. */
		uint64_t tid1                        : 1;  /**< R/W - Trap ID Group 1. When this bit is set to 1, this causes reads
                                                                     to the following registers executed from EL1 to be trapped to
                                                                     EL2:

                                                                 AArch32: TCMTR, TLBTR, AIDR, REVIDR.

                                                                 AArch64: AP_AIDR_EL1, AP_REVIDR_EL1. */
		uint64_t tid0                        : 1;  /**< R/W - Trap ID Group 0. When this bit is set to 1, this causes reads
                                                                     to the following registers executed from EL1 or EL0 if not
                                                                     UNdefined to be trapped to EL2:

                                                                 AArch32: FPSID, JIDR.

                                                                 AArch64: None. */
		uint64_t twe                         : 1;  /**< R/W - Trap WFE. When this bit is set to 1, this causes the following
                                                                     instructions executed from EL1 or EL0 to be trapped to EL2 if
                                                                     the instruction would otherwise cause suspension of execution
                                                                     (i.e. if the event register is not set):

                                                                 AArch32: WFE.

                                                                 AArch64: WFE.

                                                                 Conditional WFE instructions that fail their condition are not
                                                                     trapped if this bit is set to 1. */
		uint64_t twi                         : 1;  /**< R/W - Trap WFI. When this bit is set to 1, this causes the following
                                                                     instructions executed from EL1 or EL0 to be trapped to EL2 if
                                                                     the instruction would otherwise cause suspension of execution
                                                                     (i.e. if there is not a pending WFI wakeup event):

                                                                 AArch32: WFI.

                                                                 AArch64: WFI.

                                                                 Conditional WFI instructions that fail their condition are not
                                                                     trapped if this bit is set to 1. */
		uint64_t dc                          : 1;  /**< R/W - Default Cacheable. When this bit is set to 1, this causes:

                                                                 * The AP_SCTLR_EL1[M] bit to behave as 0 when in the non-secure
                                                                     state for all purposes other than reading the value of the
                                                                     bit.

                                                                 * The AP_HCR_EL2[VM] bit to behave as 1 when in the non-secure
                                                                     state for all purposes other than reading the value of the
                                                                     bit.

                                                                 The memory type produced by the first stage of translation
                                                                     used by EL1 and EL0 is Normal Non-Shareable, Inner WriteBack
                                                                     Read-WriteAllocate, Outer WriteBack Read-WriteAllocate.

                                                                 When this bit is 0 and the stage 1 MMU is disabled, the
                                                                     default memory attribute for Data accesses is Device-nGnRnE.

                                                                 This bit is permitted to be cached in a TLB. */
		uint64_t bsu                         : 2;  /**< R/W - Barrier Shareability upgrade. The value in this field
                                                                     determines the minimum shareability domain that is applied to
                                                                     any barrier executed from EL1 or EL0.

                                                                 This value is combined with the specified level of the barrier
                                                                     held in its instruction, using the same principles as
                                                                     combining the shareability attributes from two stages of
                                                                     address translation.

                                                                 0x0 = No effect.
                                                                 0x1 = Inner Shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Full system. */
		uint64_t fb                          : 1;  /**< R/W - Force broadcast. When this bit is set to 1, this causes the
                                                                     following instructions to be broadcast within the Inner
                                                                     Shareable domain when executed from non-secure EL1:

                                                                 AArch32: BPIALL, TLBIALL, TLBIMVA, TLBIASID, DTLBIALL,
                                                                     DTLBIMVA, DTLBIASID, ITLBIALL, ITLBIMVA, ITLBIASID, TLBIMVAA,
                                                                     ICIALLU, TLBIMVAL, TLBIMVAAL.

                                                                 AArch64: TLBI VMALLE1, TLBI VAE1, TLBI ASIDE1, TLBI VAAE1,
                                                                     TLBI VALE1, TLBI VAALE1, IC IALLU. */
		uint64_t vse                         : 1;  /**< R/W - Virtual System Error/Asynchronous Abort.
                                                                 The virtual System Error/Asynchronous Abort is only enabled
                                                                     when the AP_HCR_EL2[AMO] bit is set.
                                                                 0 = Virtual System Error/Asynchronous Abort is not pending by this
                                                                     mechanism.
                                                                 1 = Virtual System Error/Asynchronous Abort is pending by this
                                                                     mechanism. */
		uint64_t vi                          : 1;  /**< R/W - Virtual IRQ Interrupt.
                                                                 The virtual IRQ is only enabled when the AP_HCR_EL2[IMO] bit is
                                                                     set.
                                                                 0 = Virtual IRQ is not pending by this mechanism.
                                                                 1 = Virtual IRQ is pending by this mechanism. */
		uint64_t vf                          : 1;  /**< R/W - Virtual FIQ Interrupt.
                                                                 The virtual FIQ is only enabled when the AP_HCR_EL2[FMO] bit is
                                                                     set.
                                                                 0 = Virtual FIQ is not pending by this mechanism.
                                                                 1 = Virtual FIQ is pending by this mechanism. */
		uint64_t amo                         : 1;  /**< R/W - Asynchronous abort and error interrupt routing.
                                                                 0 = Asynchronous External Aborts and SError Interrupts while
                                                                     executing at exception levels lower than EL2 are not taken in
                                                                     EL2. Virtual System Error/Asynchronous Abort is disabled.
                                                                 1 = Asynchronous External Aborts and SError Interrupts while
                                                                     executing at EL2 or lower are taken in EL2 unless routed by
                                                                     the AP_SCR_EL3[EA] bit to EL3. Virtual System Error/Asynchronous
                                                                     Abort is enabled. */
		uint64_t imo                         : 1;  /**< R/W - Physical IRQ Routing.
                                                                 0 = Physical IRQ while executing at exception levels lower than
                                                                     EL2 are not taken in EL2. Virtual IRQ Interrupt is disabled.
                                                                 1 = Physical IRQ while executing at EL2 or lower are taken in EL2
                                                                     unless routed by the AP_SCR_EL3[IRQ] bit to EL3. Virtual IRQ
                                                                     Interrupt is enabled. */
		uint64_t fmo                         : 1;  /**< R/W - Physical FIQ Routing.
                                                                 0 = Physical FIQ while executing at exception levels lower than
                                                                     EL2 are not taken in EL2. Virtual FIQ Interrupt is disabled.
                                                                 1 = Physical FIQ while executing at EL2 or lower are taken in EL2
                                                                     unless routed by the AP_SCR_EL3[FIQ] bit to EL3. Virtual FIQ
                                                                     Interrupt is enabled. */
		uint64_t ptw                         : 1;  /**< R/W - Protected Table Walk. When this bit is set to 1, if the stage
                                                                     2 translation of a translation table access made as part of a
                                                                     stage 1 translation table walk at EL0 or EL1 maps that
                                                                     translation table access to Strongly-ordered or Device memory,
                                                                     the access is faulted as a stage 2 Permission fault.
                                                                 This bit is permitted to be cached in a TLB. */
		uint64_t swio                        : 1;  /**< R/W - Set/Way Invalidation Override. When this bit is set to 1, this
                                                                     causes EL1 execution of the data cache invalidate by set/way
                                                                     instruction to be treated as data cache clean and invalidate
                                                                     by set/way. That is:

                                                                 AArch32: DCISW is executed as DCCISW.

                                                                 AArch64: DC ISW is executed as DC CISW.

                                                                 As a result of changes to the behavior of DCISW, this bit is
                                                                     redundant in ARMv8. It is permissible that an implementation
                                                                     makes this bit RES1. */
		uint64_t vm                          : 1;  /**< R/W - Virtualization MMU enable for EL1 and EL0 stage 2 address
                                                                     translation.
                                                                 This bit is permitted to be cached in a TLB.
                                                                 0 = EL1 and EL0 stage 2 address translation disabled.
                                                                 1 = EL1 and EL0 stage 2 address translation enabled. */
#else
		uint64_t vm                          : 1;
		uint64_t swio                        : 1;
		uint64_t ptw                         : 1;
		uint64_t fmo                         : 1;
		uint64_t imo                         : 1;
		uint64_t amo                         : 1;
		uint64_t vf                          : 1;
		uint64_t vi                          : 1;
		uint64_t vse                         : 1;
		uint64_t fb                          : 1;
		uint64_t bsu                         : 2;
		uint64_t dc                          : 1;
		uint64_t twi                         : 1;
		uint64_t twe                         : 1;
		uint64_t tid0                        : 1;
		uint64_t tid1                        : 1;
		uint64_t tid2                        : 1;
		uint64_t tid3                        : 1;
		uint64_t tsc                         : 1;
		uint64_t tidcp                       : 1;
		uint64_t tacr                        : 1;
		uint64_t tsw                         : 1;
		uint64_t tpc                         : 1;
		uint64_t tpu                         : 1;
		uint64_t ttlb                        : 1;
		uint64_t tvm                         : 1;
		uint64_t tge                         : 1;
		uint64_t tdz                         : 1;
		uint64_t reserved_29_29              : 1;
		uint64_t trvm                        : 1;
		uint64_t rsvd_31                     : 1;
		uint64_t cd                          : 1;
		uint64_t id                          : 1;
		uint64_t e2h                         : 1;
		uint64_t tlor                        : 1;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_ap_hcr_el2_s            cn88xx; */
	/* struct bdk_ap_hcr_el2_s            cn88xxp1; */
} bdk_ap_hcr_el2_t;

#define BDK_AP_HCR_EL2 BDK_AP_HCR_EL2_FUNC()
static inline uint64_t BDK_AP_HCR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_HCR_EL2_FUNC(void)
{
	return 0x0000030401010000ull;
}
#define typedef_BDK_AP_HCR_EL2 bdk_ap_hcr_el2_t
#define bustype_BDK_AP_HCR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_HCR_EL2 0
#define arguments_BDK_AP_HCR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_HCR_EL2 "AP_HCR_EL2"


/**
 * SYSREG - ap_hpfar_el2
 *
 * Holds the faulting IPA for some aborts on a stage 2
 * translation taken to EL2.
 */
typedef union bdk_ap_hpfar_el2 {
	uint64_t u;
	struct bdk_ap_hpfar_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t fipa                        : 36; /**< R/W - Bits \<47:12\> of the faulting intermediate physical address.
                                                                 For implementations with fewer than 48 physical address bits,
                                                                 the equivalent upper bits in this field are RES0. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t fipa                        : 36;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_ap_hpfar_el2_s          cn88xx; */
	/* struct bdk_ap_hpfar_el2_s          cn88xxp1; */
} bdk_ap_hpfar_el2_t;

#define BDK_AP_HPFAR_EL2 BDK_AP_HPFAR_EL2_FUNC()
static inline uint64_t BDK_AP_HPFAR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_HPFAR_EL2_FUNC(void)
{
	return 0x0000030406000400ull;
}
#define typedef_BDK_AP_HPFAR_EL2 bdk_ap_hpfar_el2_t
#define bustype_BDK_AP_HPFAR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_HPFAR_EL2 0
#define arguments_BDK_AP_HPFAR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_HPFAR_EL2 "AP_HPFAR_EL2"


/**
 * SYSREG - ap_hstr_el2
 *
 * Controls access to coprocessor registers at lower Exception
 * levels in AArch32.
 */
typedef union bdk_ap_hstr_el2 {
	uint32_t u;
	struct bdk_ap_hstr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_hstr_el2_s           cn88xx; */
	/* struct bdk_ap_hstr_el2_s           cn88xxp1; */
} bdk_ap_hstr_el2_t;

#define BDK_AP_HSTR_EL2 BDK_AP_HSTR_EL2_FUNC()
static inline uint64_t BDK_AP_HSTR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_HSTR_EL2_FUNC(void)
{
	return 0x0000030401010300ull;
}
#define typedef_BDK_AP_HSTR_EL2 bdk_ap_hstr_el2_t
#define bustype_BDK_AP_HSTR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_HSTR_EL2 0
#define arguments_BDK_AP_HSTR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_HSTR_EL2 "AP_HSTR_EL2"


/**
 * SYSREG - ap_icc_ap0r#_el1
 *
 * Provides information about the active priorities for the
 * current interrupt regime.
 */
typedef union bdk_ap_icc_ap0rx_el1 {
	uint32_t u;
	struct bdk_ap_icc_ap0rx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - Provides information about priority M, according to the
                                                                     following relationship:
                                                                 Bit P\<n\> corresponds to priority (M divided by 22^(U))
                                                                     minus 1, where U is the number of unimplemented bits of
                                                                     priority and is equal to (7 -  AP_ICC_CTLR_EL1[PRI]bits).
                                                                 For example, in a system with AP_ICC_CTLR_EL1[PRI]bits == 0b100:

                                                                  There are 5 bits of implemented priority.

                                                                  This means there are 3 bits of unimplemented priority, which
                                                                     are always at the least significant end (bits [2:0] are RES0).

                                                                  Valid priorities are 8, 16, 24, 32, and so on. Dividing these
                                                                     by 22^(3) gives 1, 2, 3, 4, and so on.

                                                                  Subtracting 1 from each gives bits 0, 1, 2, 3, and so on that
                                                                     provide information about those priorities.

                                                                 Accesses to these registers from an interrupt regime give a
                                                                     view of the active priorities that is appropriate for that
                                                                     interrupt regime, to allow save and restore of the appropriate
                                                                     state.

                                                                 Interrupt regime and the number of Security states supported
                                                                     by the Distributor affect the view as follows. Unless
                                                                     otherwise stated, when a bit is successfully set to one, this
                                                                     clears any other active priorities corresponding to that bit.

                                                                 Exception level     AP0Rn access

                                                                 (Secure) EL3        Permitted. Accesses Group 0 Secure active priorities.

                                                                 Secure EL1  Permitted. Accesses Group 0 Secure active priorities.

                                                                 Non-secure EL1 access for a Virtual interrupt       ICH_AP0Rn_EL2

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports two Security states (GICD_CTLR[DS] is
                                                                 0) Permitted. Accesses Group 0 Secure active priorities.

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports one Security state (GICD_CTLR[DS] is
                                                                 1)  Permitted. Accesses Group 0 active priorities.

                                                                 A Virtual interrupt in this case means that the interrupt
                                                                     group associated with the register has been virtualized. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_icc_ap0rx_el1_s      cn88xx; */
	/* struct bdk_ap_icc_ap0rx_el1_s      cn88xxp1; */
} bdk_ap_icc_ap0rx_el1_t;

static inline uint64_t BDK_AP_ICC_AP0RX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_AP0RX_EL1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000003000C080400ull + (param1 & 3) * 0x100ull;
	csr_fatal("BDK_AP_ICC_AP0RX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ICC_AP0RX_EL1(...) bdk_ap_icc_ap0rx_el1_t
#define bustype_BDK_AP_ICC_AP0RX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_AP0RX_EL1(p1) (p1)
#define arguments_BDK_AP_ICC_AP0RX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ICC_AP0RX_EL1(...) "AP_ICC_AP0RX_EL1"


/**
 * SYSREG - ap_icc_ap1r#_el1
 *
 * Provides information about the active priorities for the
 * current interrupt regime.
 */
typedef union bdk_ap_icc_ap1rx_el1 {
	uint32_t u;
	struct bdk_ap_icc_ap1rx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - Provides information about priority M, according to the
                                                                     following relationship:

                                                                 Bit P\<n\> corresponds to priority (M divided by 22^(U))
                                                                     minus 1, where U is the number of unimplemented bits of
                                                                     priority and is equal to (7 -  AP_ICC_CTLR_EL1[PRI]bits).

                                                                 For example, in a system with AP_ICC_CTLR_EL1[PRI]bits ==0b100

                                                                  There are 5 bits of implemented priority.

                                                                  This means there are 3 bits of unimplemented priority, which
                                                                     are always at the least significant end (bits [2:0] are RES0).

                                                                  Valid priorities are 8, 16, 24, 32, and so on. Dividing these
                                                                     by 22^(3) gives 1, 2, 3, 4, and so on.

                                                                  Subtracting 1 from each gives bits 0, 1, 2, 3, and so on that
                                                                     provide information about those priorities.

                                                                 Accesses to these registers from an interrupt regime give a
                                                                     view of the active priorities that is appropriate for that
                                                                     interrupt regime, to allow save and restore of the appropriate
                                                                     state.

                                                                 Interrupt regime and the number of Security states supported
                                                                     by the Distributor affect the view as follows. Unless
                                                                     otherwise stated, when a bit is successfully set to one, this
                                                                     clears any other active priorities corresponding to that bit.

                                                                 Current Exception level and Security state  AP1Rn access

                                                                 (Secure) EL3        Permitted. When AP_SCR_EL3[NS] is 0, accesses Group 1 Secure active
                                                                 priorities. When AP_SCR_EL3[NS] is 1, accesses Group 1 non-secure active priorities
                                                                 (unshifted). When a bit is written, the bit is only updated if the corresponding Group 0
                                                                 and Group 1 Secure active priority is zero.

                                                                 Secure EL1  Permitted. Accesses Group 1 Secure active priorities (unshifted). When a bit
                                                                 is written, the bit is only updated if the corresponding Group 0 Secure active priority is
                                                                 zero.

                                                                 Non-secure EL1 access for a Virtual interrupt       ICH_AP1Rn_EL2

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports two Security states (GICD_CTLR[DS] is
                                                                 0) Permitted. Accesses Group 1 Non-secure active priorities (shifted). When a bit is
                                                                 written, the bit is only updated if the corresponding Group 0 and Group 1 Secure active
                                                                 priority is zero.

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports one Security state (GICD_CTLR[DS] is
                                                                 1)  Permitted. Accesses Group 1 Non-secure active priorities (unshifted). When a bit is
                                                                 written, the bit is only updated if the Group 0 active priority is zero.

                                                                 A Virtual interrupt in this case means that the interrupt
                                                                     group associated with the register has been virtualized. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_icc_ap1rx_el1_s      cn88xx; */
	/* struct bdk_ap_icc_ap1rx_el1_s      cn88xxp1; */
} bdk_ap_icc_ap1rx_el1_t;

static inline uint64_t BDK_AP_ICC_AP1RX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_AP1RX_EL1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000003000C090000ull + (param1 & 3) * 0x100ull;
	csr_fatal("BDK_AP_ICC_AP1RX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ICC_AP1RX_EL1(...) bdk_ap_icc_ap1rx_el1_t
#define bustype_BDK_AP_ICC_AP1RX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_AP1RX_EL1(p1) (p1)
#define arguments_BDK_AP_ICC_AP1RX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ICC_AP1RX_EL1(...) "AP_ICC_AP1RX_EL1"


/**
 * SYSREG - ap_icc_asgi1r_el1
 *
 * Provides software the ability to generate group 1 SGIs for the
 * other Security state.
 */
typedef union bdk_ap_icc_asgi1r_el1 {
	uint64_t u;
	struct bdk_ap_icc_asgi1r_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t aff3                        : 8;  /**< R/W - The affinity 3 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t reserved_41_47              : 7;
		uint64_t irm                         : 1;  /**< R/W - Interrupt Routing Mode. Determines how the generated
                                                                     interrupts should be distributed to processors. Possible
                                                                     values are:
                                                                 0 = Interrupts routed to the processors specified by a.b.c.{target
                                                                     list}. In this routing, a, b, and c are the values of fields
                                                                     Aff3, Aff2, and Aff1 respectively.
                                                                 1 = Interrupts routed to all processors in the system, excluding
                                                                     "self". */
		uint64_t aff2                        : 8;  /**< R/W - The affinity 2 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t reserved_28_31              : 4;
		uint64_t sgiid                       : 4;  /**< R/W - SGI Interrupt ID. */
		uint64_t aff1                        : 8;  /**< R/W - The affinity 1 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t targetlist                  : 16; /**< R/W - Target List. The set of processors for which SGI interrupts
                                                                     will be generated. Each bit corresponds to the processor
                                                                     within a cluster with an Affinity 0 value equal to the bit
                                                                     number.

                                                                 If a bit is 1 and the bit does not correspond to a valid
                                                                     target processor, the bit must be ignored by the Distributor.
                                                                     In such cases, a Distributor may optionally generate an SError
                                                                     interrupt.

                                                                 This restricts distribution of SGIs to the first 16 processors
                                                                     of an affinity 1 cluster. */
#else
		uint64_t targetlist                  : 16;
		uint64_t aff1                        : 8;
		uint64_t sgiid                       : 4;
		uint64_t reserved_28_31              : 4;
		uint64_t aff2                        : 8;
		uint64_t irm                         : 1;
		uint64_t reserved_41_47              : 7;
		uint64_t aff3                        : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_asgi1r_el1_s     cn88xx; */
	/* struct bdk_ap_icc_asgi1r_el1_s     cn88xxp1; */
} bdk_ap_icc_asgi1r_el1_t;

#define BDK_AP_ICC_ASGI1R_EL1 BDK_AP_ICC_ASGI1R_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_ASGI1R_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_ASGI1R_EL1_FUNC(void)
{
	return 0x000003000C0B0600ull;
}
#define typedef_BDK_AP_ICC_ASGI1R_EL1 bdk_ap_icc_asgi1r_el1_t
#define bustype_BDK_AP_ICC_ASGI1R_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_ASGI1R_EL1 0
#define arguments_BDK_AP_ICC_ASGI1R_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_ASGI1R_EL1 "AP_ICC_ASGI1R_EL1"


/**
 * SYSREG - ap_icc_bpr0_el1
 *
 * Defines the point at which the priority value fields split
 * into two parts, the group priority field and the subpriority
 * field. The group priority field is used to determine interrupt
 * preemption.
 */
typedef union bdk_ap_icc_bpr0_el1 {
	uint32_t u;
	struct bdk_ap_icc_bpr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t binarypoint                 : 3;  /**< R/W - The value of this field controls how the 8-bit interrupt
                                                                     priority field is split into a group priority field, used to
                                                                     determine interrupt preemption, and a subpriority field. This
                                                                     is done as follows:

                                                                 \<pre\>
                                                                 Binary point value  Group priority field    Subpriority field       Field with binary
                                                                 point
                                                                 0   [7:1]   [0]     ggggggg.s
                                                                 1   [7:2]   [1:0]   gggggg.ss
                                                                 2   [7:3]   [2:0]   ggggg.sss
                                                                 3   [7:4]   [3:0]   gggg.ssss
                                                                 4   [7:5]   [4:0]   ggg.sssss
                                                                 5   [7:6]   [5:0]   gg.ssssss
                                                                 6   [7]     [6:0]   g.sssssss
                                                                 7   No preemption   [7:0]   .ssssssss
                                                                 \</pre\> */
#else
		uint32_t binarypoint                 : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_icc_bpr0_el1_s       cn88xx; */
	/* struct bdk_ap_icc_bpr0_el1_s       cn88xxp1; */
} bdk_ap_icc_bpr0_el1_t;

#define BDK_AP_ICC_BPR0_EL1 BDK_AP_ICC_BPR0_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_BPR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_BPR0_EL1_FUNC(void)
{
	return 0x000003000C080300ull;
}
#define typedef_BDK_AP_ICC_BPR0_EL1 bdk_ap_icc_bpr0_el1_t
#define bustype_BDK_AP_ICC_BPR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_BPR0_EL1 0
#define arguments_BDK_AP_ICC_BPR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_BPR0_EL1 "AP_ICC_BPR0_EL1"


/**
 * SYSREG - ap_icc_bpr1_el1
 *
 * Defines the point at which the priority value fields split
 * into two parts, the group priority field and the subpriority
 * field. The group priority field is used to determine Group 1
 * interrupt preemption.
 */
typedef union bdk_ap_icc_bpr1_el1 {
	uint32_t u;
	struct bdk_ap_icc_bpr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t binarypoint                 : 3;  /**< R/W - The value of this field controls how the 8-bit interrupt
                                                                     priority field is split into a group priority field, used to
                                                                     determine interrupt preemption, and a subpriority field. This
                                                                     is done as follows:
                                                                 \<pre\>
                                                                 Binary point value  Group priority field    Subpriority field       Field with binary
                                                                 point
                                                                 0   [7:1]   [0]     ggggggg.s
                                                                 1   [7:2]   [1:0]   gggggg.ss
                                                                 2   [7:3]   [2:0]   ggggg.sss
                                                                 3   [7:4]   [3:0]   gggg.ssss
                                                                 4   [7:5]   [4:0]   ggg.sssss
                                                                 5   [7:6]   [5:0]   gg.ssssss
                                                                 6   [7]     [6:0]   g.sssssss
                                                                 7   No preemption   [7:0]   .ssssssss
                                                                 \</pre\> */
#else
		uint32_t binarypoint                 : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_icc_bpr1_el1_s       cn88xx; */
	/* struct bdk_ap_icc_bpr1_el1_s       cn88xxp1; */
} bdk_ap_icc_bpr1_el1_t;

#define BDK_AP_ICC_BPR1_EL1 BDK_AP_ICC_BPR1_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_BPR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_BPR1_EL1_FUNC(void)
{
	return 0x000003000C0C0300ull;
}
#define typedef_BDK_AP_ICC_BPR1_EL1 bdk_ap_icc_bpr1_el1_t
#define bustype_BDK_AP_ICC_BPR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_BPR1_EL1 0
#define arguments_BDK_AP_ICC_BPR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_BPR1_EL1 "AP_ICC_BPR1_EL1"


/**
 * SYSREG - ap_icc_ctlr_el1
 *
 * Controls aspects of the behaviour of the GIC CPU interface and
 * provides information about the features implemented.
 */
typedef union bdk_ap_icc_ctlr_el1 {
	uint32_t u;
	struct bdk_ap_icc_ctlr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t a3v                         : 1;  /**< RO - Affinity 3 Valid. Read-only and writes are ignored. Possible
                                                                     values are:
                                                                 Virtual accesses return the value from AP_ICH_VTR_EL2[A3V].
                                                                 0 = The CPU interface logic only supports zero values of Affinity
                                                                     3 in SGI generation system registers.
                                                                 1 = The CPU interface logic supports non-zero values of Affinity 3
                                                                     in SGI generation system registers. */
		uint32_t seis                        : 1;  /**< RO - SEI Support. Read-only and writes are ignored. Indicates
                                                                     whether the CPU interface supports local generation of SEIs:
                                                                 Virtual accesses return the value from AP_ICH_VTR_EL2[SEIS].
                                                                 0 = The CPU interface logic does not support local generation of
                                                                     SEIs by the CPU interface.
                                                                 1 = The CPU interface logic supports local generation of SEIs by
                                                                     the CPU interface. */
		uint32_t idbits                      : 3;  /**< RO - Identifier bits. Read-only and writes are ignored. The number
                                                                     of physical interrupt identifier bits supported:
                                                                 All other values are reserved.
                                                                 Virtual accesses return the value from AP_ICH_VTR_EL2[IDBITS].
                                                                 0x0 = 16 bits.
                                                                 0x1 = 24 bits. */
		uint32_t pribits                     : 3;  /**< RO - Priority bits. Read-only and writes are ignored. The number of
                                                                     priority bits implemented, minus one.
                                                                 Virtual accesses return the value from AP_ICH_VTR_EL2[PRI] bits. */
		uint32_t reserved_7_7                : 1;
		uint32_t pmhe                        : 1;  /**< R/W - Priority Mask Hint Enable.
                                                                 If EL3 is present and GICD_CTLR[DS] == 0, this bit is a read-
                                                                     only alias of AP_ICC_CTLR_EL3[PMHE].
                                                                 If EL3 is present and GICD_CTLR[DS] == 1, this bit is writeable
                                                                     at EL1 and EL2. */
		uint32_t reserved_2_5                : 4;
		uint32_t eoimode                     : 1;  /**< R/W - Alias of AP_ICC_CTLR_EL3[EOI]mode_EL1{S,NS} as appropriate to the
                                                                     current Security state.
                                                                 Virtual accesses modify AP_ICH_VMCR_EL2[VEOIM]. */
		uint32_t cbpr                        : 1;  /**< R/W - Common Binary Point Register.
                                                                 If EL3 is present and GICD_CTLR[DS] == 0, this bit is a read-
                                                                     only alias of AP_ICC_CTLR_EL3[CBPR]_EL1{S,NS} as appropriate.
                                                                 If EL3 is not present, this field resets to zero.
                                                                 If EL3 is present and GICD_CTLR[DS] == 1, this bit is writeable
                                                                     at EL1 and EL2.
                                                                 Virtual accesses modify AP_ICH_VMCR_EL2[VCBPR]. An access is
                                                                     virtual when accessed at non-secure EL1 and either of FIQ or
                                                                     IRQ has been virtualized.  That is, when (AP_SCR_EL3[NS] == '1' &&
                                                                     (AP_HCR_EL2[FMO] == '1' || AP_HCR_EL2[IMO] == '1')). */
#else
		uint32_t cbpr                        : 1;
		uint32_t eoimode                     : 1;
		uint32_t reserved_2_5                : 4;
		uint32_t pmhe                        : 1;
		uint32_t reserved_7_7                : 1;
		uint32_t pribits                     : 3;
		uint32_t idbits                      : 3;
		uint32_t seis                        : 1;
		uint32_t a3v                         : 1;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_ap_icc_ctlr_el1_s       cn88xx; */
	/* struct bdk_ap_icc_ctlr_el1_s       cn88xxp1; */
} bdk_ap_icc_ctlr_el1_t;

#define BDK_AP_ICC_CTLR_EL1 BDK_AP_ICC_CTLR_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_CTLR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_CTLR_EL1_FUNC(void)
{
	return 0x000003000C0C0400ull;
}
#define typedef_BDK_AP_ICC_CTLR_EL1 bdk_ap_icc_ctlr_el1_t
#define bustype_BDK_AP_ICC_CTLR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_CTLR_EL1 0
#define arguments_BDK_AP_ICC_CTLR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_CTLR_EL1 "AP_ICC_CTLR_EL1"


/**
 * SYSREG - ap_icc_ctlr_el3
 *
 * Controls aspects of the behaviour of the GIC CPU interface and
 * provides information about the features implemented.
 */
typedef union bdk_ap_icc_ctlr_el3 {
	uint32_t u;
	struct bdk_ap_icc_ctlr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t a3v                         : 1;  /**< RO - Affinity 3 Valid. Read-only and writes are ignored. Possible
                                                                     values are:
                                                                 Virtual accesses return the value from AP_ICH_VTR_EL2[A3V].
                                                                 0 = The CPU interface logic only supports zero values of Affinity
                                                                     3 in SGI generation system registers.
                                                                 1 = The CPU interface logic supports non-zero values of Affinity 3
                                                                     in SGI generation system registers. */
		uint32_t seis                        : 1;  /**< RO - SEI Support. Read-only and writes are ignored. Indicates
                                                                     whether the CPU interface supports generation of SEIs:
                                                                 Virtual accesses return the value from AP_ICH_VTR_EL2[SEIS].
                                                                 0 = The CPU interface logic does not support generation of SEIs.
                                                                 1 = The CPU interface logic supports generation of SEIs. */
		uint32_t idbits                      : 3;  /**< RO - Identifier bits. Read-only and writes are ignored. The number
                                                                     of physical interrupt identifier bits supported:
                                                                 All other values are reserved.
                                                                 0x0 = 16 bits.
                                                                 0x1 = 24 bits. */
		uint32_t pribits                     : 3;  /**< RO - Priority bits. Read-only and writes are ignored. The number of
                                                                 priority bits implemented, minus one. */
		uint32_t reserved_7_7                : 1;
		uint32_t pmhe                        : 1;  /**< R/W - Priority Mask Hint Enable.
                                                                 When set, enables use of the PMR as a hint for interrupt
                                                                     distribution. */
		uint32_t rm                          : 1;  /**< RO - Routing Modifier.  Note: In systems without EL3 or where the secure
                                                                 copy of AP_ICC_SRE_EL1 is RES1, this bit is RES0.
                                                                 This bit is used to modify the behaviour of
                                                                 AP_ICC_IAR0_EL1 and AP_ICC_IAR1_EL1 such that systems with legacy
                                                                 secure software may be supported correctly.
                                                                 0 = Secure Group 0 and non-secure group 1 interrupts can be
                                                                     acknowleged and observed as the highest priority interrupt
                                                                     at EL3 in AArch64 or Monitor mode in AArch32.
                                                                 1 = Secure Group 0 and non-secure group 1 interrupts cannot be
                                                                     acknowleged and observed as the highest priority interrupt
                                                                     at EL3 in AArch64 or Monitor mode in AArch32 but return
                                                                     special values. */
		uint32_t eoimode_el1ns               : 1;  /**< R/W - EOI mode for interrupts handled at non-secure EL1 and EL2. */
		uint32_t eoimode_el1s                : 1;  /**< R/W - EOI mode for interrupts handled at secure EL1. */
		uint32_t eoimode_el3                 : 1;  /**< R/W - EOI mode for interrupts handled at EL3. */
		uint32_t cbpr_el1ns                  : 1;  /**< R/W - When set, non-secure accesses to GICC_BPR and AP_ICC_BPR1_EL1
                                                                 access the state of AP_ICC_BPR0_EL1. AP_ICC_BPR0_EL1 is used to
                                                                 determine the preemption group for non-secure group 1
                                                                 interrupts. */
		uint32_t cbpr_el1s                   : 1;  /**< R/W - When set, secure EL1 accesses to AP_ICC_BPR1_EL1 access the state
                                                                 of AP_ICC_BPR0_EL1. AP_ICC_BPR0_EL1 is used to determine the
                                                                 preemption group for Secure Group 1 interrupts. */
#else
		uint32_t cbpr_el1s                   : 1;
		uint32_t cbpr_el1ns                  : 1;
		uint32_t eoimode_el3                 : 1;
		uint32_t eoimode_el1s                : 1;
		uint32_t eoimode_el1ns               : 1;
		uint32_t rm                          : 1;
		uint32_t pmhe                        : 1;
		uint32_t reserved_7_7                : 1;
		uint32_t pribits                     : 3;
		uint32_t idbits                      : 3;
		uint32_t seis                        : 1;
		uint32_t a3v                         : 1;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_ap_icc_ctlr_el3_s       cn88xx; */
	/* struct bdk_ap_icc_ctlr_el3_s       cn88xxp1; */
} bdk_ap_icc_ctlr_el3_t;

#define BDK_AP_ICC_CTLR_EL3 BDK_AP_ICC_CTLR_EL3_FUNC()
static inline uint64_t BDK_AP_ICC_CTLR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_CTLR_EL3_FUNC(void)
{
	return 0x000003060C0C0400ull;
}
#define typedef_BDK_AP_ICC_CTLR_EL3 bdk_ap_icc_ctlr_el3_t
#define bustype_BDK_AP_ICC_CTLR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_CTLR_EL3 0
#define arguments_BDK_AP_ICC_CTLR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_ICC_CTLR_EL3 "AP_ICC_CTLR_EL3"


/**
 * SYSREG - ap_icc_dir_el1
 *
 * When interrupt priority drop is separated from interrupt
 * deactivation, a write to this register deactivates the
 * specified interrupt.
 */
typedef union bdk_ap_icc_dir_el1 {
	uint32_t u;
	struct bdk_ap_icc_dir_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t interruptid                 : 24; /**< WO - The interrupt ID.
                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t interruptid                 : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_dir_el1_s        cn88xx; */
	/* struct bdk_ap_icc_dir_el1_s        cn88xxp1; */
} bdk_ap_icc_dir_el1_t;

#define BDK_AP_ICC_DIR_EL1 BDK_AP_ICC_DIR_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_DIR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_DIR_EL1_FUNC(void)
{
	return 0x000003000C0B0100ull;
}
#define typedef_BDK_AP_ICC_DIR_EL1 bdk_ap_icc_dir_el1_t
#define bustype_BDK_AP_ICC_DIR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_DIR_EL1 0
#define arguments_BDK_AP_ICC_DIR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_DIR_EL1 "AP_ICC_DIR_EL1"


/**
 * SYSREG - ap_icc_eoir0_el1
 *
 * A processor writes to this register to inform the CPU
 * interface that it has completed the processing of the
 * specified interrupt.
 */
typedef union bdk_ap_icc_eoir0_el1 {
	uint32_t u;
	struct bdk_ap_icc_eoir0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t intvector                   : 24; /**< WO - The InterruptID value from the corresponding GICC_IAR access.
                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t intvector                   : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_eoir0_el1_s      cn88xx; */
	/* struct bdk_ap_icc_eoir0_el1_s      cn88xxp1; */
} bdk_ap_icc_eoir0_el1_t;

#define BDK_AP_ICC_EOIR0_EL1 BDK_AP_ICC_EOIR0_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_EOIR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_EOIR0_EL1_FUNC(void)
{
	return 0x000003000C080100ull;
}
#define typedef_BDK_AP_ICC_EOIR0_EL1 bdk_ap_icc_eoir0_el1_t
#define bustype_BDK_AP_ICC_EOIR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_EOIR0_EL1 0
#define arguments_BDK_AP_ICC_EOIR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_EOIR0_EL1 "AP_ICC_EOIR0_EL1"


/**
 * SYSREG - ap_icc_eoir1_el1
 *
 * A processor writes to this register to inform the CPU
 * interface that it has completed the processing of the
 * specified Group 1 interrupt.
 */
typedef union bdk_ap_icc_eoir1_el1 {
	uint32_t u;
	struct bdk_ap_icc_eoir1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t intvector                   : 24; /**< WO - The InterruptID value from the corresponding GICC_IAR access.
                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t intvector                   : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_eoir1_el1_s      cn88xx; */
	/* struct bdk_ap_icc_eoir1_el1_s      cn88xxp1; */
} bdk_ap_icc_eoir1_el1_t;

#define BDK_AP_ICC_EOIR1_EL1 BDK_AP_ICC_EOIR1_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_EOIR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_EOIR1_EL1_FUNC(void)
{
	return 0x000003000C0C0100ull;
}
#define typedef_BDK_AP_ICC_EOIR1_EL1 bdk_ap_icc_eoir1_el1_t
#define bustype_BDK_AP_ICC_EOIR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_EOIR1_EL1 0
#define arguments_BDK_AP_ICC_EOIR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_EOIR1_EL1 "AP_ICC_EOIR1_EL1"


/**
 * SYSREG - ap_icc_hppir0_el1
 *
 * Indicates the Interrupt ID, and processor ID if appropriate,
 * of the highest priority pending interrupt on the CPU
 * interface.
 */
typedef union bdk_ap_icc_hppir0_el1 {
	uint32_t u;
	struct bdk_ap_icc_hppir0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t intvector                   : 24; /**< RO - The interrupt ID of the highest priority pending interrupt.
                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t intvector                   : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_hppir0_el1_s     cn88xx; */
	/* struct bdk_ap_icc_hppir0_el1_s     cn88xxp1; */
} bdk_ap_icc_hppir0_el1_t;

#define BDK_AP_ICC_HPPIR0_EL1 BDK_AP_ICC_HPPIR0_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_HPPIR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_HPPIR0_EL1_FUNC(void)
{
	return 0x000003000C080200ull;
}
#define typedef_BDK_AP_ICC_HPPIR0_EL1 bdk_ap_icc_hppir0_el1_t
#define bustype_BDK_AP_ICC_HPPIR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_HPPIR0_EL1 0
#define arguments_BDK_AP_ICC_HPPIR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_HPPIR0_EL1 "AP_ICC_HPPIR0_EL1"


/**
 * SYSREG - ap_icc_hppir1_el1
 *
 * If the highest priority pending interrupt on the CPU interface
 * is a Group 1 interrupt, returns the interrupt ID of that
 * interrupt. Otherwise, returns a spurious interrupt ID of 1023.
 */
typedef union bdk_ap_icc_hppir1_el1 {
	uint32_t u;
	struct bdk_ap_icc_hppir1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t intvector                   : 24; /**< RO - The interrupt ID of the highest priority pending interrupt.

                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t intvector                   : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_hppir1_el1_s     cn88xx; */
	/* struct bdk_ap_icc_hppir1_el1_s     cn88xxp1; */
} bdk_ap_icc_hppir1_el1_t;

#define BDK_AP_ICC_HPPIR1_EL1 BDK_AP_ICC_HPPIR1_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_HPPIR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_HPPIR1_EL1_FUNC(void)
{
	return 0x000003000C0C0200ull;
}
#define typedef_BDK_AP_ICC_HPPIR1_EL1 bdk_ap_icc_hppir1_el1_t
#define bustype_BDK_AP_ICC_HPPIR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_HPPIR1_EL1 0
#define arguments_BDK_AP_ICC_HPPIR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_HPPIR1_EL1 "AP_ICC_HPPIR1_EL1"


/**
 * SYSREG - ap_icc_iar0_el1
 *
 * The processor reads this register to obtain the interrupt ID
 * of the signaled interrupt. This read acts as an acknowledge
 * for the interrupt.
 */
typedef union bdk_ap_icc_iar0_el1 {
	uint32_t u;
	struct bdk_ap_icc_iar0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t intvector                   : 24; /**< RO - The ID of the signaled interrupt. IDs 1020 to 1023 are
                                                                     reserved and convey additional information such as spurious
                                                                     interrupts.

                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t intvector                   : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_iar0_el1_s       cn88xx; */
	/* struct bdk_ap_icc_iar0_el1_s       cn88xxp1; */
} bdk_ap_icc_iar0_el1_t;

#define BDK_AP_ICC_IAR0_EL1 BDK_AP_ICC_IAR0_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_IAR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_IAR0_EL1_FUNC(void)
{
	return 0x000003000C080000ull;
}
#define typedef_BDK_AP_ICC_IAR0_EL1 bdk_ap_icc_iar0_el1_t
#define bustype_BDK_AP_ICC_IAR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_IAR0_EL1 0
#define arguments_BDK_AP_ICC_IAR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_IAR0_EL1 "AP_ICC_IAR0_EL1"


/**
 * SYSREG - ap_icc_iar1_el1
 *
 * The processor reads this register to obtain the interrupt ID
 * of the signaled Group 1 interrupt. This read acts as an
 * acknowledge for the interrupt.
 */
typedef union bdk_ap_icc_iar1_el1 {
	uint32_t u;
	struct bdk_ap_icc_iar1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t intvector                   : 24; /**< RO - The ID of the signaled interrupt. IDs 1020 to 1023 are
                                                                     reserved and convey additional information such as spurious
                                                                     interrupts.

                                                                 This field has either 16 or 24 bits implemented. The number of
                                                                     implemented bits can be found in AP_ICC_CTLR_EL1[IDBITS] and
                                                                     AP_ICC_CTLR_EL3[IDBITS]. If only 16 bits are implemented, bits
                                                                     [23:16] of this register are RES0. */
#else
		uint32_t intvector                   : 24;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_iar1_el1_s       cn88xx; */
	/* struct bdk_ap_icc_iar1_el1_s       cn88xxp1; */
} bdk_ap_icc_iar1_el1_t;

#define BDK_AP_ICC_IAR1_EL1 BDK_AP_ICC_IAR1_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_IAR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_IAR1_EL1_FUNC(void)
{
	return 0x000003000C0C0000ull;
}
#define typedef_BDK_AP_ICC_IAR1_EL1 bdk_ap_icc_iar1_el1_t
#define bustype_BDK_AP_ICC_IAR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_IAR1_EL1 0
#define arguments_BDK_AP_ICC_IAR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_IAR1_EL1 "AP_ICC_IAR1_EL1"


/**
 * SYSREG - ap_icc_igrpen0_el1
 *
 * Controls whether Group 0 interrupts are enabled or not.
 *
 */
typedef union bdk_ap_icc_igrpen0_el1 {
	uint32_t u;
	struct bdk_ap_icc_igrpen0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t enable                      : 1;  /**< R/W - Enables Group 0 interrupts.
                                                                 Virtual accesses to this register update AP_ICH_VMCR_EL2[VENG0].
                                                                 0 = Group 0 interrupts are disabled.
                                                                 1 = Group 0 interrupts are enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_icc_igrpen0_el1_s    cn88xx; */
	/* struct bdk_ap_icc_igrpen0_el1_s    cn88xxp1; */
} bdk_ap_icc_igrpen0_el1_t;

#define BDK_AP_ICC_IGRPEN0_EL1 BDK_AP_ICC_IGRPEN0_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_IGRPEN0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_IGRPEN0_EL1_FUNC(void)
{
	return 0x000003000C0C0600ull;
}
#define typedef_BDK_AP_ICC_IGRPEN0_EL1 bdk_ap_icc_igrpen0_el1_t
#define bustype_BDK_AP_ICC_IGRPEN0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_IGRPEN0_EL1 0
#define arguments_BDK_AP_ICC_IGRPEN0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_IGRPEN0_EL1 "AP_ICC_IGRPEN0_EL1"


/**
 * SYSREG - ap_icc_igrpen1_el1
 *
 * Controls whether Group 1 interrupts are enabled for the
 * current Security state.
 */
typedef union bdk_ap_icc_igrpen1_el1 {
	uint32_t u;
	struct bdk_ap_icc_igrpen1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t enable                      : 1;  /**< R/W - Enables Group 1 interrupts for the current Security state.
                                                                 Virtual accesses to this register update AP_ICH_VMCR_EL2[VENG1].
                                                                 When this register is accessed at EL3, the copy of this
                                                                     register appropriate to the current setting of AP_SCR_EL3[NS] is
                                                                     accessed.
                                                                 0 = Group 1 interrupts are disabled for the current Security
                                                                     state.
                                                                 1 = Group 1 interrupts are enabled for the current Security state. */
#else
		uint32_t enable                      : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_icc_igrpen1_el1_s    cn88xx; */
	/* struct bdk_ap_icc_igrpen1_el1_s    cn88xxp1; */
} bdk_ap_icc_igrpen1_el1_t;

#define BDK_AP_ICC_IGRPEN1_EL1 BDK_AP_ICC_IGRPEN1_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_IGRPEN1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_IGRPEN1_EL1_FUNC(void)
{
	return 0x000003000C0C0700ull;
}
#define typedef_BDK_AP_ICC_IGRPEN1_EL1 bdk_ap_icc_igrpen1_el1_t
#define bustype_BDK_AP_ICC_IGRPEN1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_IGRPEN1_EL1 0
#define arguments_BDK_AP_ICC_IGRPEN1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_IGRPEN1_EL1 "AP_ICC_IGRPEN1_EL1"


/**
 * SYSREG - ap_icc_igrpen1_el3
 *
 * Controls whether Group 1 interrupts are enabled or not.
 *
 */
typedef union bdk_ap_icc_igrpen1_el3 {
	uint32_t u;
	struct bdk_ap_icc_igrpen1_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t enablegrp1s                 : 1;  /**< R/W - Enables Group 1 interrupts for the Secure state.
                                                                 0 = Group 1 interrupts are disabled for the Secure state.
                                                                 1 = Group 1 interrupts are enabled for the Secure state. */
		uint32_t enablegrp1ns                : 1;  /**< R/W - Enables Group 1 interrupts for the non-secure state.
                                                                 0 = Group 1 interrupts are disabled for the non-secure state.
                                                                 1 = Group 1 interrupts are enabled for the non-secure state. */
#else
		uint32_t enablegrp1ns                : 1;
		uint32_t enablegrp1s                 : 1;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_ap_icc_igrpen1_el3_s    cn88xx; */
	/* struct bdk_ap_icc_igrpen1_el3_s    cn88xxp1; */
} bdk_ap_icc_igrpen1_el3_t;

#define BDK_AP_ICC_IGRPEN1_EL3 BDK_AP_ICC_IGRPEN1_EL3_FUNC()
static inline uint64_t BDK_AP_ICC_IGRPEN1_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_IGRPEN1_EL3_FUNC(void)
{
	return 0x000003060C0C0700ull;
}
#define typedef_BDK_AP_ICC_IGRPEN1_EL3 bdk_ap_icc_igrpen1_el3_t
#define bustype_BDK_AP_ICC_IGRPEN1_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_IGRPEN1_EL3 0
#define arguments_BDK_AP_ICC_IGRPEN1_EL3 -1,-1,-1,-1
#define basename_BDK_AP_ICC_IGRPEN1_EL3 "AP_ICC_IGRPEN1_EL3"


/**
 * SYSREG - ap_icc_pmr_el1
 *
 * Provides an interrupt priority filter. Only interrupts with
 * higher priority than the value in this register are signaled
 * to the processor.
 */
typedef union bdk_ap_icc_pmr_el1 {
	uint32_t u;
	struct bdk_ap_icc_pmr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pri                         : 8;  /**< R/W - The priority mask level for the CPU interface. If the priority
                                                                     of an interrupt is higher than the value indicated by this
                                                                     field, the interface signals the interrupt to the processor.

                                                                 If the GIC supports fewer than 256 priority levels then some
                                                                     bits are RAZ/WI, as follows:
                                                                 - 128 supported levels: Bit [0] = 0.
                                                                 - 64 supported levels: Bits [1:0] =0b00
                                                                 - 32 supported levels: Bits [2:0] =0b000
                                                                 - 16 supported levels: Bits [3:0] =0b0000

                                                                 The possible priority field values are as follows:

                                                                 \<pre\>
                                                                 Implemented priority bits
                                                                          Possible priority field values
                                                                                     Number of priority levels
                                                                 [7:0]       0x000xFF        256
                                                                 [7:1]       0x000xFE        128
                                                                 [7:2]       0x000xFC        64
                                                                 [7:3]       0x000xF8        32
                                                                 [7:4]       0x000xF0        16
                                                                 \</pre\> */
#else
		uint32_t pri                         : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ap_icc_pmr_el1_s        cn88xx; */
	/* struct bdk_ap_icc_pmr_el1_s        cn88xxp1; */
} bdk_ap_icc_pmr_el1_t;

#define BDK_AP_ICC_PMR_EL1 BDK_AP_ICC_PMR_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_PMR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_PMR_EL1_FUNC(void)
{
	return 0x0000030004060000ull;
}
#define typedef_BDK_AP_ICC_PMR_EL1 bdk_ap_icc_pmr_el1_t
#define bustype_BDK_AP_ICC_PMR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_PMR_EL1 0
#define arguments_BDK_AP_ICC_PMR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_PMR_EL1 "AP_ICC_PMR_EL1"


/**
 * SYSREG - ap_icc_rpr_el1
 *
 * Indicates the Running priority of the CPU interface.
 *
 */
typedef union bdk_ap_icc_rpr_el1 {
	uint32_t u;
	struct bdk_ap_icc_rpr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pri                         : 8;  /**< R/W - The current running priority on the CPU interface. This is the
                                                                 priority of the current active interrupt. */
#else
		uint32_t pri                         : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ap_icc_rpr_el1_s        cn88xx; */
	/* struct bdk_ap_icc_rpr_el1_s        cn88xxp1; */
} bdk_ap_icc_rpr_el1_t;

#define BDK_AP_ICC_RPR_EL1 BDK_AP_ICC_RPR_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_RPR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_RPR_EL1_FUNC(void)
{
	return 0x000003000C0B0300ull;
}
#define typedef_BDK_AP_ICC_RPR_EL1 bdk_ap_icc_rpr_el1_t
#define bustype_BDK_AP_ICC_RPR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_RPR_EL1 0
#define arguments_BDK_AP_ICC_RPR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_RPR_EL1 "AP_ICC_RPR_EL1"


/**
 * SYSREG - ap_icc_seien_el1
 *
 * Controls whether System Error Interrupts generated by bus
 * message are enabled.
 */
typedef union bdk_ap_icc_seien_el1 {
	uint32_t u;
	struct bdk_ap_icc_seien_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t enable                      : 1;  /**< R/W - Enables System Error Interrupts generated by bus message.
                                                                 Virtual accesses to this register update AP_ICH_VMCR_EL2[VENSEI].
                                                                 0 = System Error Interrupts generated by bus message are disabled.
                                                                 1 = System Error Interrupts generated by bus message are enabled. */
#else
		uint32_t enable                      : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_icc_seien_el1_s      cn88xx; */
	/* struct bdk_ap_icc_seien_el1_s      cn88xxp1; */
} bdk_ap_icc_seien_el1_t;

#define BDK_AP_ICC_SEIEN_EL1 BDK_AP_ICC_SEIEN_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_SEIEN_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_SEIEN_EL1_FUNC(void)
{
	return 0x000003000C0D0000ull;
}
#define typedef_BDK_AP_ICC_SEIEN_EL1 bdk_ap_icc_seien_el1_t
#define bustype_BDK_AP_ICC_SEIEN_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_SEIEN_EL1 0
#define arguments_BDK_AP_ICC_SEIEN_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_SEIEN_EL1 "AP_ICC_SEIEN_EL1"


/**
 * SYSREG - ap_icc_sgi0r_el1
 *
 * Provides software the ability to generate secure group 0 SGIs,
 * including from the non-secure state when permitted by
 * GICR_NSACR.
 */
typedef union bdk_ap_icc_sgi0r_el1 {
	uint64_t u;
	struct bdk_ap_icc_sgi0r_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t aff3                        : 8;  /**< R/W - The affinity 3 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t reserved_41_47              : 7;
		uint64_t irm                         : 1;  /**< R/W - Interrupt Routing Mode. Determines how the generated
                                                                     interrupts should be distributed to processors. Possible
                                                                     values are:
                                                                 0 = Interrupts routed to the processors specified by a.b.c.{target
                                                                     list}. In this routing, a, b, and c are the values of fields
                                                                     Aff3, Aff2, and Aff1 respectively.
                                                                 1 = Interrupts routed to all processors in the system, excluding
                                                                     "self". */
		uint64_t aff2                        : 8;  /**< R/W - The affinity 2 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t reserved_28_31              : 4;
		uint64_t sgiid                       : 4;  /**< R/W - SGI Interrupt ID. */
		uint64_t aff1                        : 8;  /**< R/W - The affinity 1 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t targetlist                  : 16; /**< R/W - Target List. The set of processors for which SGI interrupts
                                                                     will be generated. Each bit corresponds to the processor
                                                                     within a cluster with an Affinity 0 value equal to the bit
                                                                     number.

                                                                 If a bit is 1 and the bit does not correspond to a valid
                                                                     target processor, the bit must be ignored by the Distributor.
                                                                     In such cases, a Distributor may optionally generate an SError
                                                                     interrupt.

                                                                 This restricts distribution of SGIs to the first 16 processors
                                                                     of an affinity 1 cluster. */
#else
		uint64_t targetlist                  : 16;
		uint64_t aff1                        : 8;
		uint64_t sgiid                       : 4;
		uint64_t reserved_28_31              : 4;
		uint64_t aff2                        : 8;
		uint64_t irm                         : 1;
		uint64_t reserved_41_47              : 7;
		uint64_t aff3                        : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_sgi0r_el1_s      cn88xx; */
	/* struct bdk_ap_icc_sgi0r_el1_s      cn88xxp1; */
} bdk_ap_icc_sgi0r_el1_t;

#define BDK_AP_ICC_SGI0R_EL1 BDK_AP_ICC_SGI0R_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_SGI0R_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_SGI0R_EL1_FUNC(void)
{
	return 0x000003000C0B0700ull;
}
#define typedef_BDK_AP_ICC_SGI0R_EL1 bdk_ap_icc_sgi0r_el1_t
#define bustype_BDK_AP_ICC_SGI0R_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_SGI0R_EL1 0
#define arguments_BDK_AP_ICC_SGI0R_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_SGI0R_EL1 "AP_ICC_SGI0R_EL1"


/**
 * SYSREG - ap_icc_sgi1r_el1
 *
 * Provides software the ability to generate group 1 SGIs for the
 * current security state.
 */
typedef union bdk_ap_icc_sgi1r_el1 {
	uint64_t u;
	struct bdk_ap_icc_sgi1r_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t aff3                        : 8;  /**< R/W - The affinity 3 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t reserved_41_47              : 7;
		uint64_t irm                         : 1;  /**< R/W - Interrupt Routing Mode. Determines how the generated
                                                                     interrupts should be distributed to processors. Possible
                                                                     values are:
                                                                 0 = Interrupts routed to the processors specified by a.b.c.{target
                                                                     list}. In this routing, a, b, and c are the values of fields
                                                                     Aff3, Aff2, and Aff1 respectively.
                                                                 1 = Interrupts routed to all processors in the system, excluding
                                                                     "self". */
		uint64_t aff2                        : 8;  /**< R/W - The affinity 2 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t reserved_28_31              : 4;
		uint64_t sgiid                       : 4;  /**< R/W - SGI Interrupt ID. */
		uint64_t aff1                        : 8;  /**< R/W - The affinity 1 value of the affinity path of the cluster for
                                                                 which SGI interrupts will be generated. */
		uint64_t targetlist                  : 16; /**< R/W - Target List. The set of processors for which SGI interrupts
                                                                     will be generated. Each bit corresponds to the processor
                                                                     within a cluster with an Affinity 0 value equal to the bit
                                                                     number.
                                                                 If a bit is 1 and the bit does not correspond to a valid
                                                                     target processor, the bit must be ignored by the Distributor.
                                                                     In such cases, a Distributor may optionally generate an SError
                                                                     interrupt.
                                                                 This restricts distribution of SGIs to the first 16 processors
                                                                     of an affinity 1 cluster. */
#else
		uint64_t targetlist                  : 16;
		uint64_t aff1                        : 8;
		uint64_t sgiid                       : 4;
		uint64_t reserved_28_31              : 4;
		uint64_t aff2                        : 8;
		uint64_t irm                         : 1;
		uint64_t reserved_41_47              : 7;
		uint64_t aff3                        : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_ap_icc_sgi1r_el1_s      cn88xx; */
	/* struct bdk_ap_icc_sgi1r_el1_s      cn88xxp1; */
} bdk_ap_icc_sgi1r_el1_t;

#define BDK_AP_ICC_SGI1R_EL1 BDK_AP_ICC_SGI1R_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_SGI1R_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_SGI1R_EL1_FUNC(void)
{
	return 0x000003000C0B0500ull;
}
#define typedef_BDK_AP_ICC_SGI1R_EL1 bdk_ap_icc_sgi1r_el1_t
#define bustype_BDK_AP_ICC_SGI1R_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_SGI1R_EL1 0
#define arguments_BDK_AP_ICC_SGI1R_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_SGI1R_EL1 "AP_ICC_SGI1R_EL1"


/**
 * SYSREG - ap_icc_sre_el1
 *
 * Controls whether the system register interface or the memory
 * mapped interface to the GIC CPU interface is used for EL0 and
 * EL1.
 */
typedef union bdk_ap_icc_sre_el1 {
	uint32_t u;
	struct bdk_ap_icc_sre_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t dib                         : 1;  /**< RO - Disable IRQ bypass.
                                                                 If EL3 is present, this field is a read-only alias of
                                                                     AP_ICC_SRE_EL3[DIB].
                                                                 If EL3 is not present and EL2 is present, this field is a
                                                                     read-only alias of AP_ICC_SRE_EL2[DIB]. */
		uint32_t dfb                         : 1;  /**< RO - Disable FIQ bypass.
                                                                 If EL3 is present, this field is a read-only alias of
                                                                     AP_ICC_SRE_EL3[DFB].
                                                                 If EL3 is not present and EL2 is present, this field is a
                                                                     read-only alias of AP_ICC_SRE_EL2[DFB]. */
		uint32_t sre                         : 1;  /**< RO - System Register Enable.
                                                                 Virtual accesses modify AP_ICH_VMCR_EL2[VSRE].
                                                                 0 = The memory mapped interface must be used. Access at EL1 to any
                                                                     ICC_* system register other than AP_ICC_SRE_EL1 results in an
                                                                     Undefined exception.
                                                                 1 = The system register interface for the current Security state
                                                                     is enabled. */
#else
		uint32_t sre                         : 1;
		uint32_t dfb                         : 1;
		uint32_t dib                         : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ap_icc_sre_el1_s        cn88xx; */
	/* struct bdk_ap_icc_sre_el1_s        cn88xxp1; */
} bdk_ap_icc_sre_el1_t;

#define BDK_AP_ICC_SRE_EL1 BDK_AP_ICC_SRE_EL1_FUNC()
static inline uint64_t BDK_AP_ICC_SRE_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_SRE_EL1_FUNC(void)
{
	return 0x000003000C0C0500ull;
}
#define typedef_BDK_AP_ICC_SRE_EL1 bdk_ap_icc_sre_el1_t
#define bustype_BDK_AP_ICC_SRE_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_SRE_EL1 0
#define arguments_BDK_AP_ICC_SRE_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ICC_SRE_EL1 "AP_ICC_SRE_EL1"


/**
 * SYSREG - ap_icc_sre_el2
 *
 * Controls whether the system register interface or the memory
 * mapped interface to the GIC CPU interface is used for EL2.
 */
typedef union bdk_ap_icc_sre_el2 {
	uint32_t u;
	struct bdk_ap_icc_sre_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t enable                      : 1;  /**< R/W - Enable. Enables lower Exception level access to AP_ICC_SRE_EL1.
                                                                 0 = Non-secure EL1 accesses to AP_ICC_SRE_EL1 trap to EL2.
                                                                 1 = Non-secure EL1 accesses to AP_ICC_SRE_EL1 are permitted if EL3 is
                                                                     not present or AP_ICC_SRE_EL3[ENABLE] is 1, otherwise non-secure
                                                                     EL1 accesses to AP_ICC_SRE_EL1 trap to EL3. */
		uint32_t dib                         : 1;  /**< RO - Disable IRQ bypass.
                                                                 If EL3 is present and GICD_CTLR[DS] is 0, this field is a read-
                                                                     only alias of AP_ICC_SRE_EL3[DIB]. */
		uint32_t dfb                         : 1;  /**< RO - Disable FIQ bypass.
                                                                 If EL3 is present and GICD_CTLR[DS] is 0, this field is a read-
                                                                     only alias of AP_ICC_SRE_EL3[DFB]. */
		uint32_t sre                         : 1;  /**< RO - System Register Enable.
                                                                 0 = The memory mapped interface must be used. Access at EL2 to any
                                                                     ICH_* system register, or any EL1 or EL2 ICC_* register other
                                                                     than AP_ICC_SRE_EL1 or AP_ICC_SRE_EL2, results in an Undefined
                                                                     exception.
                                                                 1 = The system register interface to the ICH_* registers and the
                                                                     EL1 and EL2 ICC_* registers is enabled for EL2. */
#else
		uint32_t sre                         : 1;
		uint32_t dfb                         : 1;
		uint32_t dib                         : 1;
		uint32_t enable                      : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_ap_icc_sre_el2_s        cn88xx; */
	/* struct bdk_ap_icc_sre_el2_s        cn88xxp1; */
} bdk_ap_icc_sre_el2_t;

#define BDK_AP_ICC_SRE_EL2 BDK_AP_ICC_SRE_EL2_FUNC()
static inline uint64_t BDK_AP_ICC_SRE_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_SRE_EL2_FUNC(void)
{
	return 0x000003040C090500ull;
}
#define typedef_BDK_AP_ICC_SRE_EL2 bdk_ap_icc_sre_el2_t
#define bustype_BDK_AP_ICC_SRE_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_SRE_EL2 0
#define arguments_BDK_AP_ICC_SRE_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICC_SRE_EL2 "AP_ICC_SRE_EL2"


/**
 * SYSREG - ap_icc_sre_el3
 *
 * Controls whether the system register interface or the memory
 * mapped interface to the GIC CPU interface is used for EL2.
 */
typedef union bdk_ap_icc_sre_el3 {
	uint32_t u;
	struct bdk_ap_icc_sre_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t enable                      : 1;  /**< R/W - Enable. Enables lower Exception level access to AP_ICC_SRE_EL1
                                                                     and AP_ICC_SRE_EL2.
                                                                 0 = EL1 and EL2 accesses to AP_ICC_SRE_EL1 or AP_ICC_SRE_EL2 trap to
                                                                     EL3.
                                                                 1 = EL2 accesses to AP_ICC_SRE_EL2 are permitted. If the Enable bit
                                                                     of AP_ICC_SRE_EL2 is 1, then EL1 accesses to AP_ICC_SRE_EL1 are also
                                                                     permitted. */
		uint32_t dib                         : 1;  /**< RO - Disable IRQ bypass. */
		uint32_t dfb                         : 1;  /**< RO - Disable FIQ bypass. */
		uint32_t sre                         : 1;  /**< RO - System Register Enable.
                                                                 0 = The memory mapped interface must be used. Access at EL3 to any
                                                                     ICH_* system register, or any EL1, EL2, or EL3 ICC_* register
                                                                     other than AP_ICC_SRE_EL1, AP_ICC_SRE_EL2, or AP_ICC_SRE_EL3, results
                                                                     in an Undefined exception.
                                                                 1 = The system register interface to the ICH_* registers and the
                                                                     EL1, EL2, and EL3 ICC_* registers is enabled for EL3. */
#else
		uint32_t sre                         : 1;
		uint32_t dfb                         : 1;
		uint32_t dib                         : 1;
		uint32_t enable                      : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_ap_icc_sre_el3_s        cn88xx; */
	/* struct bdk_ap_icc_sre_el3_s        cn88xxp1; */
} bdk_ap_icc_sre_el3_t;

#define BDK_AP_ICC_SRE_EL3 BDK_AP_ICC_SRE_EL3_FUNC()
static inline uint64_t BDK_AP_ICC_SRE_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICC_SRE_EL3_FUNC(void)
{
	return 0x000003060C0C0500ull;
}
#define typedef_BDK_AP_ICC_SRE_EL3 bdk_ap_icc_sre_el3_t
#define bustype_BDK_AP_ICC_SRE_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICC_SRE_EL3 0
#define arguments_BDK_AP_ICC_SRE_EL3 -1,-1,-1,-1
#define basename_BDK_AP_ICC_SRE_EL3 "AP_ICC_SRE_EL3"


/**
 * SYSREG - ap_ich_ap0r0_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap0r0_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap0r0_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - Provides information about priority M, according to the
                                                                     following relationship:

                                                                 Bit P\<n\> corresponds to priority (M divided by 22^(U))
                                                                     minus 1, where U is the number of unimplemented bits of
                                                                     priority and is equal to (7 -  AP_ICC_CTLR_EL1[PRIBITS]).

                                                                 For example, in a system with AP_ICC_CTLR_EL1[PRIBITS] == 0x4:

                                                                  There are 5 bits of implemented priority.

                                                                  This means there are 3 bits of unimplemented priority, which
                                                                     are always at the least significant end (bits [2:0] are RES0).

                                                                  Valid priorities are 8, 16, 24, 32, and so on. Dividing these
                                                                     by 22^(3) gives 1, 2, 3, 4, and so on.

                                                                  Subtracting 1 from each gives bits 0, 1, 2, 3, and so on that
                                                                     provide information about those priorities.

                                                                 Accesses to these registers from an interrupt regime give a
                                                                     view of the active priorities that is appropriate for that
                                                                     interrupt regime, to allow save and restore of the appropriate
                                                                     state.

                                                                 Interrupt regime and the number of Security states supported
                                                                     by the Distributor affect the view as follows. Unless
                                                                     otherwise stated, when a bit is successfully set to one, this
                                                                     clears any other active priorities corresponding to that bit.

                                                                 Exception level     AP0Rn access

                                                                 (Secure) EL3        Permitted. Accesses Group 0 Secure active priorities.

                                                                 Secure EL1  Permitted. Accesses Group 0 Secure active priorities.

                                                                 Non-secure EL1 access for a Virtual interrupt       ICH_AP0Rn_EL2

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports two Security states (GICD_CTLR[DS] is
                                                                 0) Permitted. Accesses Group 0 Secure active priorities.

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports one Security state (GICD_CTLR[DS] is
                                                                 1)  Permitted. Accesses Group 0 active priorities.

                                                                 A Virtual interrupt in this case means that the interrupt
                                                                     group associated with the register has been virtualized. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap0r0_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap0r0_el2_s      cn88xxp1; */
} bdk_ap_ich_ap0r0_el2_t;

#define BDK_AP_ICH_AP0R0_EL2 BDK_AP_ICH_AP0R0_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP0R0_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP0R0_EL2_FUNC(void)
{
	return 0x000003040C080000ull;
}
#define typedef_BDK_AP_ICH_AP0R0_EL2 bdk_ap_ich_ap0r0_el2_t
#define bustype_BDK_AP_ICH_AP0R0_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP0R0_EL2 0
#define arguments_BDK_AP_ICH_AP0R0_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP0R0_EL2 "AP_ICH_AP0R0_EL2"


/**
 * SYSREG - ap_ich_ap0r1_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap0r1_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap0r1_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - See description of AP_ICH_AP0R0_EL2[PRIORITYBITS]. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap0r1_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap0r1_el2_s      cn88xxp1; */
} bdk_ap_ich_ap0r1_el2_t;

#define BDK_AP_ICH_AP0R1_EL2 BDK_AP_ICH_AP0R1_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP0R1_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP0R1_EL2_FUNC(void)
{
	return 0x000003040C080100ull;
}
#define typedef_BDK_AP_ICH_AP0R1_EL2 bdk_ap_ich_ap0r1_el2_t
#define bustype_BDK_AP_ICH_AP0R1_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP0R1_EL2 0
#define arguments_BDK_AP_ICH_AP0R1_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP0R1_EL2 "AP_ICH_AP0R1_EL2"


/**
 * SYSREG - ap_ich_ap0r2_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap0r2_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap0r2_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - See description of AP_ICH_AP0R0_EL2[PRIORITYBITS]. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap0r2_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap0r2_el2_s      cn88xxp1; */
} bdk_ap_ich_ap0r2_el2_t;

#define BDK_AP_ICH_AP0R2_EL2 BDK_AP_ICH_AP0R2_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP0R2_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP0R2_EL2_FUNC(void)
{
	return 0x000003040C080200ull;
}
#define typedef_BDK_AP_ICH_AP0R2_EL2 bdk_ap_ich_ap0r2_el2_t
#define bustype_BDK_AP_ICH_AP0R2_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP0R2_EL2 0
#define arguments_BDK_AP_ICH_AP0R2_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP0R2_EL2 "AP_ICH_AP0R2_EL2"


/**
 * SYSREG - ap_ich_ap0r3_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap0r3_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap0r3_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - See description of AP_ICH_AP0R0_EL2[PRIORITYBITS]. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap0r3_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap0r3_el2_s      cn88xxp1; */
} bdk_ap_ich_ap0r3_el2_t;

#define BDK_AP_ICH_AP0R3_EL2 BDK_AP_ICH_AP0R3_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP0R3_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP0R3_EL2_FUNC(void)
{
	return 0x000003040C080300ull;
}
#define typedef_BDK_AP_ICH_AP0R3_EL2 bdk_ap_ich_ap0r3_el2_t
#define bustype_BDK_AP_ICH_AP0R3_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP0R3_EL2 0
#define arguments_BDK_AP_ICH_AP0R3_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP0R3_EL2 "AP_ICH_AP0R3_EL2"


/**
 * SYSREG - ap_ich_ap1r0_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap1r0_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap1r0_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - Provides information about priority M, according to the
                                                                     following relationship:

                                                                 Bit P\<n\> corresponds to priority (M divided by 22^(U))
                                                                     minus 1, where U is the number of unimplemented bits of
                                                                     priority and is equal to (7 -  AP_ICC_CTLR_EL1[PRIBITS]).

                                                                 For example, in a system with AP_ICC_CTLR_EL1[PRIBITS] = 0x4:

                                                                  There are 5 bits of implemented priority.

                                                                  This means there are 3 bits of unimplemented priority, which
                                                                     are always at the least significant end (bits [2:0] are RES0).

                                                                  Valid priorities are 8, 16, 24, 32, and so on. Dividing these
                                                                     by 22^(3) gives 1, 2, 3, 4, and so on.

                                                                  Subtracting 1 from each gives bits 0, 1, 2, 3, and so on that
                                                                     provide information about those priorities.

                                                                 Accesses to these registers from an interrupt regime give a
                                                                     view of the active priorities that is appropriate for that
                                                                     interrupt regime, to allow save and restore of the appropriate
                                                                     state.

                                                                 Interrupt regime and the number of Security states supported
                                                                     by the Distributor affect the view as follows. Unless
                                                                     otherwise stated, when a bit is successfully set to one, this
                                                                     clears any other active priorities corresponding to that bit.

                                                                 Current Exception level and Security state  AP1Rn access

                                                                 (Secure) EL3        Permitted. When AP_SCR_EL3[NS] is 0, accesses Group 1 Secure active
                                                                 priorities. When AP_SCR_EL3[NS] is 1, accesses Group 1 non-secure active priorities
                                                                 (unshifted). When a bit is written, the bit is only updated if the corresponding Group 0
                                                                 and Group 1 Secure active priority is zero.

                                                                 Secure EL1  Permitted. Accesses Group 1 Secure active priorities (unshifted). When a bit
                                                                 is written, the bit is only updated if the corresponding Group 0 Secure active priority is
                                                                 zero.

                                                                 Non-secure EL1 access for a Virtual interrupt       ICH_AP1Rn_EL2

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports two Security states (GICD_CTLR[DS] is
                                                                 0) Permitted. Accesses Group 1 non-secure active priorities (shifted). When a bit is
                                                                 written, the bit is only updated if the corresponding Group 0 and Group 1 Secure active
                                                                 priority is zero.

                                                                 Non-secure EL1 or EL2 when GIC Distributor supports one Security state (GICD_CTLR[DS] is
                                                                 1)  Permitted. Accesses Group 1 non-secure active priorities (unshifted). When a bit is
                                                                 written, the bit is only updated if the Group 0 active priority is zero.

                                                                 A Virtual interrupt in this case means that the interrupt
                                                                     group associated with the register has been virtualized. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap1r0_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap1r0_el2_s      cn88xxp1; */
} bdk_ap_ich_ap1r0_el2_t;

#define BDK_AP_ICH_AP1R0_EL2 BDK_AP_ICH_AP1R0_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP1R0_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP1R0_EL2_FUNC(void)
{
	return 0x000003040C090000ull;
}
#define typedef_BDK_AP_ICH_AP1R0_EL2 bdk_ap_ich_ap1r0_el2_t
#define bustype_BDK_AP_ICH_AP1R0_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP1R0_EL2 0
#define arguments_BDK_AP_ICH_AP1R0_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP1R0_EL2 "AP_ICH_AP1R0_EL2"


/**
 * SYSREG - ap_ich_ap1r1_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap1r1_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap1r1_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - See description of AP_ICH_AP1R0_EL2[PRIORITYBITS]. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap1r1_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap1r1_el2_s      cn88xxp1; */
} bdk_ap_ich_ap1r1_el2_t;

#define BDK_AP_ICH_AP1R1_EL2 BDK_AP_ICH_AP1R1_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP1R1_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP1R1_EL2_FUNC(void)
{
	return 0x000003040C090100ull;
}
#define typedef_BDK_AP_ICH_AP1R1_EL2 bdk_ap_ich_ap1r1_el2_t
#define bustype_BDK_AP_ICH_AP1R1_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP1R1_EL2 0
#define arguments_BDK_AP_ICH_AP1R1_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP1R1_EL2 "AP_ICH_AP1R1_EL2"


/**
 * SYSREG - ap_ich_ap1r2_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap1r2_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap1r2_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - See description of AP_ICH_AP1R0_EL2[PRIORITYBITS]. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap1r2_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap1r2_el2_s      cn88xxp1; */
} bdk_ap_ich_ap1r2_el2_t;

#define BDK_AP_ICH_AP1R2_EL2 BDK_AP_ICH_AP1R2_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP1R2_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP1R2_EL2_FUNC(void)
{
	return 0x000003040C090200ull;
}
#define typedef_BDK_AP_ICH_AP1R2_EL2 bdk_ap_ich_ap1r2_el2_t
#define bustype_BDK_AP_ICH_AP1R2_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP1R2_EL2 0
#define arguments_BDK_AP_ICH_AP1R2_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP1R2_EL2 "AP_ICH_AP1R2_EL2"


/**
 * SYSREG - ap_ich_ap1r3_el2
 *
 * Provides information about the active priorities for the
 * current EL2 interrupt regime.
 */
typedef union bdk_ap_ich_ap1r3_el2 {
	uint32_t u;
	struct bdk_ap_ich_ap1r3_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t prioritybits                : 32; /**< R/W - See description of AP_ICH_AP1R0_EL2[PRIORITYBITS]. */
#else
		uint32_t prioritybits                : 32;
#endif
	} s;
	/* struct bdk_ap_ich_ap1r3_el2_s      cn88xx; */
	/* struct bdk_ap_ich_ap1r3_el2_s      cn88xxp1; */
} bdk_ap_ich_ap1r3_el2_t;

#define BDK_AP_ICH_AP1R3_EL2 BDK_AP_ICH_AP1R3_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_AP1R3_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_AP1R3_EL2_FUNC(void)
{
	return 0x000003040C090300ull;
}
#define typedef_BDK_AP_ICH_AP1R3_EL2 bdk_ap_ich_ap1r3_el2_t
#define bustype_BDK_AP_ICH_AP1R3_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_AP1R3_EL2 0
#define arguments_BDK_AP_ICH_AP1R3_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_AP1R3_EL2 "AP_ICH_AP1R3_EL2"


/**
 * SYSREG - ap_ich_eisr_el2
 *
 * When a maintenance interrupt is received, this register helps
 * determine which List registers have outstanding EOI interrupts
 * that require servicing.
 */
typedef union bdk_ap_ich_eisr_el2 {
	uint32_t u;
	struct bdk_ap_ich_eisr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t status_bits                 : 32; /**< RO - EOI status bit for List register \<n\>:
                                                                 For any ICH_LR\<n\>_EL2, the corresponding status bit is set to
                                                                     1 if ICH_LR\<n\>_EL2[State] is 0x0.
                                                                 0 = List register \<n\>, ICH_LR\<n\>_EL2, does not have an EOI.
                                                                 1 = List register \<n\>, ICH_LR\<n\>_EL2, has an EOI. */
#else
		uint32_t status_bits                 : 32;
#endif
	} s;
	/* struct bdk_ap_ich_eisr_el2_s       cn88xx; */
	/* struct bdk_ap_ich_eisr_el2_s       cn88xxp1; */
} bdk_ap_ich_eisr_el2_t;

#define BDK_AP_ICH_EISR_EL2 BDK_AP_ICH_EISR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_EISR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_EISR_EL2_FUNC(void)
{
	return 0x000003040C0B0300ull;
}
#define typedef_BDK_AP_ICH_EISR_EL2 bdk_ap_ich_eisr_el2_t
#define bustype_BDK_AP_ICH_EISR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_EISR_EL2 0
#define arguments_BDK_AP_ICH_EISR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_EISR_EL2 "AP_ICH_EISR_EL2"


/**
 * SYSREG - ap_ich_elsr_el2
 *
 * This register can be used to locate a usable List register
 * when the hypervisor is delivering an interrupt to a Guest OS.
 */
typedef union bdk_ap_ich_elsr_el2 {
	uint32_t u;
	struct bdk_ap_ich_elsr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t status_bits                 : 32; /**< RO - Status bit for List register \<n\>, ICH_LR\<n\>_EL2:
                                                                 For any ICH_LR\<n\>_EL2, the corresponding status bit is set to
                                                                     1 if ICH_LR\<n\>_EL2[State] is 0x0.
                                                                 0 = List register ICH_LR\<n\>_EL2, if implemented, contains a valid
                                                                    interrupt. Using this List register can result in overwriting
                                                                     a valid interrupt.
                                                                 1 = List register ICH_LR\<n\>_EL2 does not contain a valid
                                                                     interrupt. The List register is empty and can be used without
                                                                     overwriting a valid interrupt or losing an EOI maintenance
                                                                     interrupt. */
#else
		uint32_t status_bits                 : 32;
#endif
	} s;
	/* struct bdk_ap_ich_elsr_el2_s       cn88xx; */
	/* struct bdk_ap_ich_elsr_el2_s       cn88xxp1; */
} bdk_ap_ich_elsr_el2_t;

#define BDK_AP_ICH_ELSR_EL2 BDK_AP_ICH_ELSR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_ELSR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_ELSR_EL2_FUNC(void)
{
	return 0x000003040C0B0500ull;
}
#define typedef_BDK_AP_ICH_ELSR_EL2 bdk_ap_ich_elsr_el2_t
#define bustype_BDK_AP_ICH_ELSR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_ELSR_EL2 0
#define arguments_BDK_AP_ICH_ELSR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_ELSR_EL2 "AP_ICH_ELSR_EL2"


/**
 * SYSREG - ap_ich_hcr_el2
 *
 * Controls the environment for guest operating systems.
 *
 */
typedef union bdk_ap_ich_hcr_el2 {
	uint32_t u;
	struct bdk_ap_ich_hcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t eoicount                    : 5;  /**< R/W - Counts the number of EOIs received that do not have a
                                                                     corresponding entry in the List registers. The virtual CPU
                                                                     interface increments this field automatically when a matching
                                                                     EOI is received.

                                                                 EOIs that do not clear a bit in one of the Active Priorities
                                                                     registers ICH_APmRn_EL2 do not cause an increment.

                                                                 Although not possible under correct operation, if an EOI
                                                                     occurs when the value of this field is 31, this field wraps to
                                                                     0.

                                                                 The maintenance interrupt is asserted whenever this field is
                                                                     non-zero and the LRENPIE bit is set to 1. */
		uint32_t reserved_14_26              : 13;
		uint32_t tsei                        : 1;  /**< RO - A locally generated SEI will trap to EL2 if this bit is set.  This bit is RES0 when
                                                                 AP_ICH_VTR_EL2[SEIS] is not set. */
		uint32_t tall1                       : 1;  /**< R/W - Trap all non-secure EL1 accesses to ICC_* system registers for
                                                                     group 1 interrupts to EL2.
                                                                 0 = Non-Secure EL1 accesses to ICC_* registers for group 1
                                                                     interrupts proceed as normal.
                                                                 1 = Any non-secure EL1 accesses to ICC_* registers for group 1
                                                                     interrupts trap to EL2. */
		uint32_t tall0                       : 1;  /**< R/W - Trap all non-secure EL1 accesses to ICC_* system registers for
                                                                     group 0 interrupts to EL2.
                                                                 0 = Non-Secure EL1 accesses to ICC_* registers for group 0
                                                                     interrupts proceed as normal.
                                                                 1 = Any non-secure EL1 accesses to ICC_* registers for group 0
                                                                     interrupts trap to EL2. */
		uint32_t tc                          : 1;  /**< R/W - Trap all non-secure El1 accesses to system registers that are
                                                                     common to group 0 and group 1 to EL2.
                                                                 This affects AP_ICC_DIR_EL1, AP_ICC_PMR_EL1, and AP_ICC_RPR_EL1.
                                                                 0 = Non-secure EL1 accesses to common registers proceed as normal.
                                                                 1 = Any non-secure EL1 accesses to common registers trap to EL2. */
		uint32_t reserved_8_9                : 2;
		uint32_t vgrp1die                    : 1;  /**< R/W - VM Disable Group 1 Interrupt Enable. Enables the signaling of
                                                                     a maintenance interrupt while signaling of Group 1 interrupts
                                                                     from the virtual CPU interface to the connected virtual
                                                                     machine is disabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while GICV_CTLR[EnableGrp1] is
                                                                     set to 0. */
		uint32_t vgrp1eie                    : 1;  /**< R/W - VM Enable Group 1 Interrupt Enable. Enables the signaling of a
                                                                     maintenance interrupt while signaling of Group 1 interrupts
                                                                     from the virtual CPU interface to the connected virtual
                                                                     machine is enabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while GICV_CTLR[EnableGrp1] is
                                                                     set to 1. */
		uint32_t vgrp0die                    : 1;  /**< R/W - VM Disable Group 0 Interrupt Enable. Enables the signaling of
                                                                     a maintenance interrupt while signaling of Group 0 interrupts
                                                                     from the virtual CPU interface to the connected virtual
                                                                     machine is disabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while GICV_CTLR[EnableGrp0] is
                                                                     set to 0. */
		uint32_t vgrp0eie                    : 1;  /**< R/W - VM Enable Group 0 Interrupt Enable. Enables the signaling of a
                                                                     maintenance interrupt while signaling of Group 0 interrupts
                                                                     from the virtual CPU interface to the connected virtual
                                                                     machine is enabled:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interrupt signaled while GICV_CTLR[EnableGrp0] is
                                                                     set to 1. */
		uint32_t npie                        : 1;  /**< R/W - No Pending Interrupt Enable. Enables the signaling of a
                                                                     maintenance interrupt while no pending interrupts are present
                                                                     in the List registers:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = Maintenance interupt signaled while the List registers contain
                                                                     no interrupts in the pending state. */
		uint32_t lrenpie                     : 1;  /**< R/W - List Register Entry Not Present Interrupt Enable. Enables the
                                                                     signaling of a maintenance interrupt while the virtual CPU
                                                                     interface does not have a corresponding valid List register
                                                                     entry for an EOI request:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = A maintenance interrupt is asserted while the EOIcount field
                                                                     is not 0. */
		uint32_t uie                         : 1;  /**< R/W - Underflow Interrupt Enable. Enables the signaling of a
                                                                     maintenance interrupt when the List registers are empty, or
                                                                     hold only one valid entry:
                                                                 0 = Maintenance interrupt disabled.
                                                                 1 = A maintenance interrupt is asserted if none, or only one, of
                                                                     the List register entries is marked as a valid interrupt. */
		uint32_t en                          : 1;  /**< R/W - Enable. Global enable bit for the virtual CPU interface:
                                                                 When this field is set to 0:
                                                                  The virtual CPU interface does not signal any maintenance
                                                                     interrupts.
                                                                  The virtual CPU interface does not signal any virtual
                                                                     interrupts.
                                                                  A read of GICV_IAR or GICV_AIAR returns a spurious interrupt
                                                                     ID.
                                                                 0 = Virtual CPU interface operation disabled.
                                                                 1 = Virtual CPU interface operation enabled. */
#else
		uint32_t en                          : 1;
		uint32_t uie                         : 1;
		uint32_t lrenpie                     : 1;
		uint32_t npie                        : 1;
		uint32_t vgrp0eie                    : 1;
		uint32_t vgrp0die                    : 1;
		uint32_t vgrp1eie                    : 1;
		uint32_t vgrp1die                    : 1;
		uint32_t reserved_8_9                : 2;
		uint32_t tc                          : 1;
		uint32_t tall0                       : 1;
		uint32_t tall1                       : 1;
		uint32_t tsei                        : 1;
		uint32_t reserved_14_26              : 13;
		uint32_t eoicount                    : 5;
#endif
	} s;
	/* struct bdk_ap_ich_hcr_el2_s        cn88xx; */
	/* struct bdk_ap_ich_hcr_el2_s        cn88xxp1; */
} bdk_ap_ich_hcr_el2_t;

#define BDK_AP_ICH_HCR_EL2 BDK_AP_ICH_HCR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_HCR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_HCR_EL2_FUNC(void)
{
	return 0x000003040C0B0000ull;
}
#define typedef_BDK_AP_ICH_HCR_EL2 bdk_ap_ich_hcr_el2_t
#define bustype_BDK_AP_ICH_HCR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_HCR_EL2 0
#define arguments_BDK_AP_ICH_HCR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_HCR_EL2 "AP_ICH_HCR_EL2"


/**
 * SYSREG - ap_ich_lr#_el2
 *
 * Provides interrupt context information for the virtual CPU interface.
 *
 */
typedef union bdk_ap_ich_lrx_el2 {
	uint64_t u;
	struct bdk_ap_ich_lrx_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t state                       : 2;  /**< R/W - 0x0 = Invalid.
                                                                 0x1 = Pending.
                                                                 0x2 = Active.
                                                                 0x3 = Pending and Active. */
		uint64_t hw                          : 1;  /**< R/W - Virtual interrupt corresponds to physical interrupt. */
		uint64_t group                       : 1;  /**< R/W - Indicates interrupt is group 1. */
		uint64_t reserved_56_59              : 4;
		uint64_t pri                         : 8;  /**< R/W - Interrupt priority. */
		uint64_t reserved_42_47              : 6;
		uint64_t physical_id                 : 10; /**< R/W - When HW is zero, bit 41 indicates whether this interrupt triggers an EOI maintenance
                                                                 interrupt and bits 40..32 are RES0. */
		uint64_t virtual_id                  : 32; /**< R/W - Virtual interrupt ID. */
#else
		uint64_t virtual_id                  : 32;
		uint64_t physical_id                 : 10;
		uint64_t reserved_42_47              : 6;
		uint64_t pri                         : 8;
		uint64_t reserved_56_59              : 4;
		uint64_t group                       : 1;
		uint64_t hw                          : 1;
		uint64_t state                       : 2;
#endif
	} s;
	/* struct bdk_ap_ich_lrx_el2_s        cn88xx; */
	/* struct bdk_ap_ich_lrx_el2_s        cn88xxp1; */
} bdk_ap_ich_lrx_el2_t;

static inline uint64_t BDK_AP_ICH_LRX_EL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_LRX_EL2(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000003040C0C0000ull + (param1 & 15) * 0x100ull;
	csr_fatal("BDK_AP_ICH_LRX_EL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ICH_LRX_EL2(...) bdk_ap_ich_lrx_el2_t
#define bustype_BDK_AP_ICH_LRX_EL2(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_LRX_EL2(p1) (p1)
#define arguments_BDK_AP_ICH_LRX_EL2(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ICH_LRX_EL2(...) "AP_ICH_LRX_EL2"


/**
 * SYSREG - ap_ich_lrc#
 *
 * Provides interrupt context information for the virtual CPU interface. Only used for Aarch32.
 * Here for disassembly only.
 */
typedef union bdk_ap_ich_lrcx {
	uint32_t u;
	struct bdk_ap_ich_lrcx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_ich_lrcx_s           cn88xx; */
	/* struct bdk_ap_ich_lrcx_s           cn88xxp1; */
} bdk_ap_ich_lrcx_t;

static inline uint64_t BDK_AP_ICH_LRCX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_LRCX(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000003040C0E0000ull + (param1 & 15) * 0x100ull;
	csr_fatal("BDK_AP_ICH_LRCX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ICH_LRCX(...) bdk_ap_ich_lrcx_t
#define bustype_BDK_AP_ICH_LRCX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_LRCX(p1) (p1)
#define arguments_BDK_AP_ICH_LRCX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ICH_LRCX(...) "AP_ICH_LRCX"


/**
 * SYSREG - ap_ich_misr_el2
 *
 * Indicates which maintenance interrupts are asserted.
 *
 */
typedef union bdk_ap_ich_misr_el2 {
	uint32_t u;
	struct bdk_ap_ich_misr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t vsei                        : 1;  /**< RO - Virtual SEI. Set to 1 when a condition that would result in
                                                                 generation of an SEI is detected during a virtual access to an
                                                                 ICC_* system register. */
		uint32_t vgrp1d                      : 1;  /**< RO - Disabled Group 1 maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[VGrp1DIE] is 1 and
                                                                     AP_ICH_VMCR_EL2[VMGrp1En] is 0. */
		uint32_t vgrp1e                      : 1;  /**< RO - Enabled Group 1 maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[VGrp1EIE] is 1 and
                                                                     AP_ICH_VMCR_EL2[VMGrp1En] is 1. */
		uint32_t vgrp0d                      : 1;  /**< RO - Disabled Group 0 maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[VGrp0DIE] is 1 and
                                                                     AP_ICH_VMCR_EL2[VMGrp0En] is 0. */
		uint32_t vgrp0e                      : 1;  /**< RO - Enabled Group 0 maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[VGrp0EIE] is 1 and
                                                                     AP_ICH_VMCR_EL2[VMGrp0En] is 1. */
		uint32_t np                          : 1;  /**< RO - No Pending maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[NPIE] is 1 and no List register
                                                                     is in pending state. */
		uint32_t lrenp                       : 1;  /**< RO - List Register Entry Not Present maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[LRENPIE] is 1 and
                                                                     AP_ICH_HCR_EL2[EOIcount] is non-zero. */
		uint32_t u                           : 1;  /**< RO - Underflow maintenance interrupt.
                                                                 Asserted whenever AP_ICH_HCR_EL2[UIE] is 1 and if none, or only
                                                                     one, of the List register entries are marked as a valid
                                                                     interrupt, that is, if the corresponding ICH_LR\<n\>_EL2[State]
                                                                     bits do not equal0x0 */
		uint32_t eoi                         : 1;  /**< RO - EOI maintenance interrupt.
                                                                 Asserted whenever at least one List register is asserting an
                                                                     EOI interrupt. That is, when at least one bit in ICH_EISR0_EL1
                                                                     or ICH_EISR1_EL1 is 1. */
#else
		uint32_t eoi                         : 1;
		uint32_t u                           : 1;
		uint32_t lrenp                       : 1;
		uint32_t np                          : 1;
		uint32_t vgrp0e                      : 1;
		uint32_t vgrp0d                      : 1;
		uint32_t vgrp1e                      : 1;
		uint32_t vgrp1d                      : 1;
		uint32_t vsei                        : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_ap_ich_misr_el2_s       cn88xx; */
	/* struct bdk_ap_ich_misr_el2_s       cn88xxp1; */
} bdk_ap_ich_misr_el2_t;

#define BDK_AP_ICH_MISR_EL2 BDK_AP_ICH_MISR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_MISR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_MISR_EL2_FUNC(void)
{
	return 0x000003040C0B0200ull;
}
#define typedef_BDK_AP_ICH_MISR_EL2 bdk_ap_ich_misr_el2_t
#define bustype_BDK_AP_ICH_MISR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_MISR_EL2 0
#define arguments_BDK_AP_ICH_MISR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_MISR_EL2 "AP_ICH_MISR_EL2"


/**
 * SYSREG - ap_ich_vmcr_el2
 *
 * Enables the hypervisor to save and restore the virtual machine
 * view of the GIC state.
 */
typedef union bdk_ap_ich_vmcr_el2 {
	uint32_t u;
	struct bdk_ap_ich_vmcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vpmr                        : 8;  /**< R/W - Virtual Priority Mask.
                                                                 Visible to the guest OS as AP_ICC_PMR_EL1 / GICV_PMR. */
		uint32_t vbpr0                       : 3;  /**< R/W - Virtual BPR0.
                                                                 Visible to the guest OS as AP_ICC_BPR0_EL1 / GICV_BPR. */
		uint32_t vbpr1                       : 3;  /**< R/W - Virtual BPR1.
                                                                 Visible to the guest OS as AP_ICC_BPR1_EL1 / GICV_ABPR. */
		uint32_t reserved_10_17              : 8;
		uint32_t veoim                       : 1;  /**< R/W - Virtual EOImode.
                                                                 Visible to the guest OS as AP_ICC_CTLR_EL1[EOImode] /
                                                                     GICV_CTLR[EOImode]. */
		uint32_t reserved_5_8                : 4;
		uint32_t vcbpr                       : 1;  /**< R/W - Virtual CBPR.
                                                                 Visible to the guest OS as AP_ICC_CTLR_EL1[CBPR] / GICV_CTLR[CBPR]. */
		uint32_t vfiqen                      : 1;  /**< R/W - Virtual FIQ enable.
                                                                 Visible to the guest OS as GICV_CTLR[FIQEn]. */
		uint32_t vackctl                     : 1;  /**< R/W - Virtual AckCtl.
                                                                 Visible to the guest OS as GICV_CTLR[AckCtl]. */
		uint32_t veng1                       : 1;  /**< R/W - Virtual group 1 interrupt enable.
                                                                 Visible to the guest OS as AP_ICC_IGRPEN1_EL1[Enable] /
                                                                     GICV_CTLR[EnableGrp1]. */
		uint32_t veng0                       : 1;  /**< R/W - Virtual group 0 interrupt enable.
                                                                 Visible to the guest OS as AP_ICC_IGRPEN0_EL1[Enable] /
                                                                     GICV_CTLR[EnableGrp0]. */
#else
		uint32_t veng0                       : 1;
		uint32_t veng1                       : 1;
		uint32_t vackctl                     : 1;
		uint32_t vfiqen                      : 1;
		uint32_t vcbpr                       : 1;
		uint32_t reserved_5_8                : 4;
		uint32_t veoim                       : 1;
		uint32_t reserved_10_17              : 8;
		uint32_t vbpr1                       : 3;
		uint32_t vbpr0                       : 3;
		uint32_t vpmr                        : 8;
#endif
	} s;
	/* struct bdk_ap_ich_vmcr_el2_s       cn88xx; */
	/* struct bdk_ap_ich_vmcr_el2_s       cn88xxp1; */
} bdk_ap_ich_vmcr_el2_t;

#define BDK_AP_ICH_VMCR_EL2 BDK_AP_ICH_VMCR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_VMCR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_VMCR_EL2_FUNC(void)
{
	return 0x000003040C0B0700ull;
}
#define typedef_BDK_AP_ICH_VMCR_EL2 bdk_ap_ich_vmcr_el2_t
#define bustype_BDK_AP_ICH_VMCR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_VMCR_EL2 0
#define arguments_BDK_AP_ICH_VMCR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_VMCR_EL2 "AP_ICH_VMCR_EL2"


/**
 * SYSREG - ap_ich_vseir_el2
 *
 * Allows the hypervisor to inject a virtual SEI.
 *
 */
typedef union bdk_ap_ich_vseir_el2 {
	uint32_t u;
	struct bdk_ap_ich_vseir_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t valid                       : 1;  /**< R/W - System error interrupt valid.
                                                                 0 = No virtual system error exception is pending.
                                                                 1 = A virtual system error exception is pending for non-secure
                                                                     EL1. */
		uint32_t reserved_25_30              : 6;
		uint32_t syndrome                    : 25; /**< R/W - The value that will be presented in bits [24:0] of ESR_EL1 on
                                                                 entry into the SError exception handler. */
#else
		uint32_t syndrome                    : 25;
		uint32_t reserved_25_30              : 6;
		uint32_t valid                       : 1;
#endif
	} s;
	/* struct bdk_ap_ich_vseir_el2_s      cn88xx; */
	/* struct bdk_ap_ich_vseir_el2_s      cn88xxp1; */
} bdk_ap_ich_vseir_el2_t;

#define BDK_AP_ICH_VSEIR_EL2 BDK_AP_ICH_VSEIR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_VSEIR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_VSEIR_EL2_FUNC(void)
{
	return 0x000003040C090400ull;
}
#define typedef_BDK_AP_ICH_VSEIR_EL2 bdk_ap_ich_vseir_el2_t
#define bustype_BDK_AP_ICH_VSEIR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_VSEIR_EL2 0
#define arguments_BDK_AP_ICH_VSEIR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_VSEIR_EL2 "AP_ICH_VSEIR_EL2"


/**
 * SYSREG - ap_ich_vtr_el2
 *
 * Describes the number of implemented virtual priority bits and
 * List registers.
 */
typedef union bdk_ap_ich_vtr_el2 {
	uint32_t u;
	struct bdk_ap_ich_vtr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pribits                     : 3;  /**< RO - The number of virtual priority bits implemented, minus one. */
		uint32_t prebits                     : 3;  /**< RO - The number of virtual preemption bits implemented, minus one. */
		uint32_t idbits                      : 3;  /**< RO - The number of virtual interrupt identifier bits supported:
                                                                 All other values are reserved.
                                                                 0x0 = 16 bits.
                                                                 0x1 = 24 bits. */
		uint32_t seis                        : 1;  /**< RO - SEI Support. Indicates whether the virtual CPU interface
                                                                     supports generation of SEIs:
                                                                 Virtual system errors may still be generated by writing to
                                                                     AP_ICH_VSEIR_EL2 regardless of the value of this field.
                                                                 0 = The virtual CPU interface logic does not support generation of
                                                                     SEIs.
                                                                 1 = The virtual CPU interface logic supports generation of SEIs. */
		uint32_t a3v                         : 1;  /**< RO - Affinity 3 Valid.
                                                                 0 = The virtual CPU interface logic only supports zero values of
                                                                     Affinity 3 in SGI generation system registers.
                                                                 1 = The virtual CPU interface logic supports non-zero values of
                                                                     Affinity 3 in SGI generation system registers. */
		uint32_t reserved_5_20               : 16;
		uint32_t listregs                    : 5;  /**< RO - The number of implemented List registers, minus one. */
#else
		uint32_t listregs                    : 5;
		uint32_t reserved_5_20               : 16;
		uint32_t a3v                         : 1;
		uint32_t seis                        : 1;
		uint32_t idbits                      : 3;
		uint32_t prebits                     : 3;
		uint32_t pribits                     : 3;
#endif
	} s;
	/* struct bdk_ap_ich_vtr_el2_s        cn88xx; */
	/* struct bdk_ap_ich_vtr_el2_s        cn88xxp1; */
} bdk_ap_ich_vtr_el2_t;

#define BDK_AP_ICH_VTR_EL2 BDK_AP_ICH_VTR_EL2_FUNC()
static inline uint64_t BDK_AP_ICH_VTR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ICH_VTR_EL2_FUNC(void)
{
	return 0x000003040C0B0100ull;
}
#define typedef_BDK_AP_ICH_VTR_EL2 bdk_ap_ich_vtr_el2_t
#define bustype_BDK_AP_ICH_VTR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ICH_VTR_EL2 0
#define arguments_BDK_AP_ICH_VTR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_ICH_VTR_EL2 "AP_ICH_VTR_EL2"


/**
 * SYSREG - ap_id_aa64afr#_el1_res0
 *
 * Reserved for future expansion of information about the
 * implementation defined features of the processor in AArch64.
 * ARM doesn't actually assign a name to these registers, so
 * for CNXXXX a made up one.
 */
typedef union bdk_ap_id_aa64afrx_el1_res0 {
	uint64_t u;
	struct bdk_ap_id_aa64afrx_el1_res0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64afrx_el1_res0_s cn88xx; */
	/* struct bdk_ap_id_aa64afrx_el1_res0_s cn88xxp1; */
} bdk_ap_id_aa64afrx_el1_res0_t;

static inline uint64_t BDK_AP_ID_AA64AFRX_EL1_RES0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64AFRX_EL1_RES0(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 3))))
		return 0x0000030000050400ull + (param1 & 3) * 0x100ull;
	csr_fatal("BDK_AP_ID_AA64AFRX_EL1_RES0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_AA64AFRX_EL1_RES0(...) bdk_ap_id_aa64afrx_el1_res0_t
#define bustype_BDK_AP_ID_AA64AFRX_EL1_RES0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64AFRX_EL1_RES0(p1) (p1)
#define arguments_BDK_AP_ID_AA64AFRX_EL1_RES0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_AA64AFRX_EL1_RES0(...) "AP_ID_AA64AFRX_EL1_RES0"


/**
 * SYSREG - ap_id_aa64afr0_el1
 *
 * Provides information about the implementation defined features
 * of the processor in AArch64.
 */
typedef union bdk_ap_id_aa64afr0_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64afr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64afr0_el1_s    cn88xx; */
	/* struct bdk_ap_id_aa64afr0_el1_s    cn88xxp1; */
} bdk_ap_id_aa64afr0_el1_t;

#define BDK_AP_ID_AA64AFR0_EL1 BDK_AP_ID_AA64AFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64AFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64AFR0_EL1_FUNC(void)
{
	return 0x0000030000050400ull;
}
#define typedef_BDK_AP_ID_AA64AFR0_EL1 bdk_ap_id_aa64afr0_el1_t
#define bustype_BDK_AP_ID_AA64AFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64AFR0_EL1 0
#define arguments_BDK_AP_ID_AA64AFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64AFR0_EL1 "AP_ID_AA64AFR0_EL1"


/**
 * SYSREG - ap_id_aa64afr1_el1
 *
 * Reserved for future expansion of information about the
 * implementation defined features of the processor in AArch64.
 */
typedef union bdk_ap_id_aa64afr1_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64afr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64afr1_el1_s    cn88xx; */
	/* struct bdk_ap_id_aa64afr1_el1_s    cn88xxp1; */
} bdk_ap_id_aa64afr1_el1_t;

#define BDK_AP_ID_AA64AFR1_EL1 BDK_AP_ID_AA64AFR1_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64AFR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64AFR1_EL1_FUNC(void)
{
	return 0x0000030000050500ull;
}
#define typedef_BDK_AP_ID_AA64AFR1_EL1 bdk_ap_id_aa64afr1_el1_t
#define bustype_BDK_AP_ID_AA64AFR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64AFR1_EL1 0
#define arguments_BDK_AP_ID_AA64AFR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64AFR1_EL1 "AP_ID_AA64AFR1_EL1"


/**
 * SYSREG - ap_id_aa64dfr#_el1_res0
 *
 * Reserved for future expansion of top level information about
 * the debug system in AArch64. ARM doesn't actually assign
 * a name to these registers, so CNXXXX made up one.
 */
typedef union bdk_ap_id_aa64dfrx_el1_res0 {
	uint64_t u;
	struct bdk_ap_id_aa64dfrx_el1_res0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64dfrx_el1_res0_s cn88xx; */
	/* struct bdk_ap_id_aa64dfrx_el1_res0_s cn88xxp1; */
} bdk_ap_id_aa64dfrx_el1_res0_t;

static inline uint64_t BDK_AP_ID_AA64DFRX_EL1_RES0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64DFRX_EL1_RES0(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 3))))
		return 0x0000030000050000ull + (param1 & 3) * 0x100ull;
	csr_fatal("BDK_AP_ID_AA64DFRX_EL1_RES0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_AA64DFRX_EL1_RES0(...) bdk_ap_id_aa64dfrx_el1_res0_t
#define bustype_BDK_AP_ID_AA64DFRX_EL1_RES0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64DFRX_EL1_RES0(p1) (p1)
#define arguments_BDK_AP_ID_AA64DFRX_EL1_RES0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_AA64DFRX_EL1_RES0(...) "AP_ID_AA64DFRX_EL1_RES0"


/**
 * SYSREG - ap_id_aa64dfr0_el1
 *
 * This register provides top level information about the debug system in AArch64.
 *
 */
typedef union bdk_ap_id_aa64dfr0_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64dfr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ctx_cmps                    : 4;  /**< RO - Number of breakpoints that are context-aware, minus 1. These
                                                                     are the highest numbered breakpoints.

                                                                 In CNXXXX all breakpoints are context-aware. */
		uint64_t reserved_24_27              : 4;
		uint64_t wrps                        : 4;  /**< RO - Number of watchpoints, minus 1. The value of 0b0000 is reserved.

                                                                 In CNXXXX 4 watchpoints. */
		uint64_t reserved_16_19              : 4;
		uint64_t brps                        : 4;  /**< RO - Number of breakpoints, minus 1. The value of 0b0000 is reserved.

                                                                 In CNXXXX 6 breakpoints. */
		uint64_t pmuver                      : 4;  /**< RO - Performance Monitors extension version. Indicates whether
                                                                     system register interface to Performance Monitors extension is
                                                                     implemented.
                                                                 All other values are reserved.
                                                                 0x0 = Performance Monitors extension system registers not
                                                                     implemented.
                                                                 0x1 = Performance Monitors extension system registers implemented,
                                                                     PMUv3.
                                                                 0x4 = v8.1: Performance Monitors extension system registers
                                                                     implemented, PMUv3 with 16bit evtCount.
                                                                 0xF =  implementation defined form of performance monitors
                                                                     supported, PMUv3 not supported.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x4, else 0x1. */
		uint64_t tracever                    : 4;  /**< RO - Trace extension. Indicates whether system register interface to the trace
                                                                 extension is implemented.
                                                                 All other values are reserved.
                                                                 0x0 = Trace extension system registers not implemented.
                                                                 0x1 = Trace extension system registers implemented. */
		uint64_t debugver                    : 4;  /**< RO - Debug architecture version. Indicates presence of ARMv8 debug
                                                                     architecture.
                                                                 All other values are reserved.
                                                                 0x6 = ARMv8 debug architecture.
                                                                 0x7 = ARMv8.1 debug architecture.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x7, else 0x6. */
#else
		uint64_t debugver                    : 4;
		uint64_t tracever                    : 4;
		uint64_t pmuver                      : 4;
		uint64_t brps                        : 4;
		uint64_t reserved_16_19              : 4;
		uint64_t wrps                        : 4;
		uint64_t reserved_24_27              : 4;
		uint64_t ctx_cmps                    : 4;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_ap_id_aa64dfr0_el1_s    cn88xx; */
	/* struct bdk_ap_id_aa64dfr0_el1_s    cn88xxp1; */
} bdk_ap_id_aa64dfr0_el1_t;

#define BDK_AP_ID_AA64DFR0_EL1 BDK_AP_ID_AA64DFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64DFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64DFR0_EL1_FUNC(void)
{
	return 0x0000030000050000ull;
}
#define typedef_BDK_AP_ID_AA64DFR0_EL1 bdk_ap_id_aa64dfr0_el1_t
#define bustype_BDK_AP_ID_AA64DFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64DFR0_EL1 0
#define arguments_BDK_AP_ID_AA64DFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64DFR0_EL1 "AP_ID_AA64DFR0_EL1"


/**
 * SYSREG - ap_id_aa64dfr1_el1
 *
 * Reserved for future expansion of top level information about
 * the debug system in AArch64.
 */
typedef union bdk_ap_id_aa64dfr1_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64dfr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64dfr1_el1_s    cn88xx; */
	/* struct bdk_ap_id_aa64dfr1_el1_s    cn88xxp1; */
} bdk_ap_id_aa64dfr1_el1_t;

#define BDK_AP_ID_AA64DFR1_EL1 BDK_AP_ID_AA64DFR1_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64DFR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64DFR1_EL1_FUNC(void)
{
	return 0x0000030000050100ull;
}
#define typedef_BDK_AP_ID_AA64DFR1_EL1 bdk_ap_id_aa64dfr1_el1_t
#define bustype_BDK_AP_ID_AA64DFR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64DFR1_EL1 0
#define arguments_BDK_AP_ID_AA64DFR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64DFR1_EL1 "AP_ID_AA64DFR1_EL1"


/**
 * SYSREG - ap_id_aa64isar#_el1_res0
 *
 * Reserved for future expansion of the information about the
 * instruction sets implemented by the processor in AArch64.
 * ARM doesn't actually assign a name to these registers, so
 * CNXXXX made up one.
 */
typedef union bdk_ap_id_aa64isarx_el1_res0 {
	uint64_t u;
	struct bdk_ap_id_aa64isarx_el1_res0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64isarx_el1_res0_s cn88xx; */
	/* struct bdk_ap_id_aa64isarx_el1_res0_s cn88xxp1; */
} bdk_ap_id_aa64isarx_el1_res0_t;

static inline uint64_t BDK_AP_ID_AA64ISARX_EL1_RES0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64ISARX_EL1_RES0(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 7))))
		return 0x0000030000060000ull + (param1 & 7) * 0x100ull;
	csr_fatal("BDK_AP_ID_AA64ISARX_EL1_RES0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_AA64ISARX_EL1_RES0(...) bdk_ap_id_aa64isarx_el1_res0_t
#define bustype_BDK_AP_ID_AA64ISARX_EL1_RES0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64ISARX_EL1_RES0(p1) (p1)
#define arguments_BDK_AP_ID_AA64ISARX_EL1_RES0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_AA64ISARX_EL1_RES0(...) "AP_ID_AA64ISARX_EL1_RES0"


/**
 * SYSREG - ap_id_aa64isar0_el1
 *
 * This register provides information about the instructions implemented by the
 * processor in AArch64.
 */
typedef union bdk_ap_id_aa64isar0_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64isar0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t sqrdml                      : 4;  /**< RO - 0x0 = SQRDMLAH and SQRDMLSH not supported in AArch64.
                                                                 0x1 = SQRDMLAH and SQRDMLSH supported in AArch64.
                                                                 All other values reserved.

                                                                 In CNXXXX, supported. */
		uint64_t reserved_24_27              : 4;
		uint64_t atomic                      : 4;  /**< RO - Atomic instructions in AArch64
                                                                     0x0 = No Atomic instructions implemented.
                                                                     0x1 = Reserved.
                                                                     0x2 = LDADD, LDCLR, LDEOR, LDSET, LDSMAX, LDSMIN, LDUMAX, LDUMIN, CAS, CASP,
                                                                         SWP instructions implemented.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x2, else 0x0. */
		uint64_t crc32                       : 4;  /**< RO - CRC32 instructions in AArch64.
                                                                 All other values are reserved.
                                                                 This field must have the same value as ID_ISAR5[CRC32]. The
                                                                     architecture requires that if CRC32 is supported in one
                                                                     Execution state, it must be supported in both Execution
                                                                     states.
                                                                 0x0 = No CRC32 instructions implemented.
                                                                 0x1 = CRC32B, CRC32H, CRC32W, CRC32X, CRC32CB, CRC32CH, CRC32CW, and
                                                                     CRC32CX instructions implemented.

                                                                 In CNXXXX, supported unless crypto disabled by MIO_FUS_DAT2[NOCRYPTO]. */
		uint64_t sha2                        : 4;  /**< RO - SHA2 instructions in AArch64.
                                                                 All other values are reserved.
                                                                 0x0 = No SHA2 instructions implemented.
                                                                 0x1 = SHA256H, SHA256H2, SHA256SU0, and SHA256SU1 instructions
                                                                     implemented.

                                                                 In CNXXXX, supported unless crypto disabled by MIO_FUS_DAT2[NOCRYPTO]. */
		uint64_t sha1                        : 4;  /**< RO - SHA1 instructions in AArch64.
                                                                 All other values are reserved.
                                                                 0x0 = No SHA1 instructions implemented.
                                                                 0x1 = SHA1C, SHA1P, SHA1M, SHA1H, SHA1SU0, and SHA1SU1 instructions
                                                                     implemented.

                                                                 In CNXXXX, supported unless crypto disabled by MIO_FUS_DAT2[NOCRYPTO]. */
		uint64_t aes                         : 4;  /**< RO - AES instructions in AArch64.
                                                                 0x0 = No AES instructions implemented.
                                                                 0x1 = AESE, AESD, AESMC, and AESIMC instructions implemented.
                                                                 0x2 = As for 0x1, plus PMULL/PMULL2 instructions operate on
                                                                 64-bit data quantities.

                                                                 In CNXXXX, supported with PMULL/PMULL2. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t aes                         : 4;
		uint64_t sha1                        : 4;
		uint64_t sha2                        : 4;
		uint64_t crc32                       : 4;
		uint64_t atomic                      : 4;
		uint64_t reserved_24_27              : 4;
		uint64_t sqrdml                      : 4;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_ap_id_aa64isar0_el1_s   cn88xx; */
	/* struct bdk_ap_id_aa64isar0_el1_s   cn88xxp1; */
} bdk_ap_id_aa64isar0_el1_t;

#define BDK_AP_ID_AA64ISAR0_EL1 BDK_AP_ID_AA64ISAR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64ISAR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64ISAR0_EL1_FUNC(void)
{
	return 0x0000030000060000ull;
}
#define typedef_BDK_AP_ID_AA64ISAR0_EL1 bdk_ap_id_aa64isar0_el1_t
#define bustype_BDK_AP_ID_AA64ISAR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64ISAR0_EL1 0
#define arguments_BDK_AP_ID_AA64ISAR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64ISAR0_EL1 "AP_ID_AA64ISAR0_EL1"


/**
 * SYSREG - ap_id_aa64isar1_el1
 *
 * Reserved for future expansion of the information about the
 * instruction sets implemented by the processor in AArch64.
 */
typedef union bdk_ap_id_aa64isar1_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64isar1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64isar1_el1_s   cn88xx; */
	/* struct bdk_ap_id_aa64isar1_el1_s   cn88xxp1; */
} bdk_ap_id_aa64isar1_el1_t;

#define BDK_AP_ID_AA64ISAR1_EL1 BDK_AP_ID_AA64ISAR1_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64ISAR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64ISAR1_EL1_FUNC(void)
{
	return 0x0000030000060100ull;
}
#define typedef_BDK_AP_ID_AA64ISAR1_EL1 bdk_ap_id_aa64isar1_el1_t
#define bustype_BDK_AP_ID_AA64ISAR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64ISAR1_EL1 0
#define arguments_BDK_AP_ID_AA64ISAR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64ISAR1_EL1 "AP_ID_AA64ISAR1_EL1"


/**
 * SYSREG - ap_id_aa64mmfr#_el1_res0
 *
 * Reserved for future expansion of the information about the
 * implemented memory model and memory management support in
 * AArch64. ARM doesn't actually assign a name to these
 * registers, so CNXXXX made up one.
 */
typedef union bdk_ap_id_aa64mmfrx_el1_res0 {
	uint64_t u;
	struct bdk_ap_id_aa64mmfrx_el1_res0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64mmfrx_el1_res0_s cn88xx; */
	/* struct bdk_ap_id_aa64mmfrx_el1_res0_s cn88xxp1; */
} bdk_ap_id_aa64mmfrx_el1_res0_t;

static inline uint64_t BDK_AP_ID_AA64MMFRX_EL1_RES0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64MMFRX_EL1_RES0(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 7))))
		return 0x0000030000070000ull + (param1 & 7) * 0x100ull;
	csr_fatal("BDK_AP_ID_AA64MMFRX_EL1_RES0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_AA64MMFRX_EL1_RES0(...) bdk_ap_id_aa64mmfrx_el1_res0_t
#define bustype_BDK_AP_ID_AA64MMFRX_EL1_RES0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64MMFRX_EL1_RES0(p1) (p1)
#define arguments_BDK_AP_ID_AA64MMFRX_EL1_RES0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_AA64MMFRX_EL1_RES0(...) "AP_ID_AA64MMFRX_EL1_RES0"


/**
 * SYSREG - ap_id_aa64mmfr0_el1
 *
 * This register provides information about the implemented memory model and memory
 * management support in AArch64.
 */
typedef union bdk_ap_id_aa64mmfr0_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64mmfr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t tgran4                      : 4;  /**< RO - Support for 4KB memory translation granule size.
                                                                 All other values are reserved.
                                                                 0x0 = 4KB granule supported.
                                                                 0XF = 4KB granule not supported.

                                                                 In CNXXXX, supported. */
		uint64_t tgran64                     : 4;  /**< RO - Support for 64KB memory translation granule size.
                                                                 All other values are reserved.
                                                                 0x0 = 64KB granule supported.
                                                                 0xF = 64KB granule not supported.

                                                                 In CNXXXX, supported. */
		uint64_t tgran16                     : 4;  /**< RO - Support for 16KB memory translation granule size.
                                                                 All other values are reserved.
                                                                 0x0 = 16KB granule not supported.
                                                                 0x1 = 16KB granule supported.

                                                                 In CNXXXX, supported. */
		uint64_t bigendel0                   : 4;  /**< RO - Mixed-endian support at EL0 only.
                                                                 All other values are reserved.
                                                                 This field is invalid and is RES0 if the BigEnd field, bits
                                                                     [11:8], is not 0x0.
                                                                 0x0 = No mixed-endian support at EL0. The AP_SCTLR_EL1[E0E] bit has a
                                                                     fixed value.
                                                                 0x1 = Mixed-endian support at EL0. The AP_SCTLR_EL1[E0E] bit can be
                                                                     configured.

                                                                 In CNXXXX, supported. */
		uint64_t snsmem                      : 4;  /**< RO - Secure versus non-secure memory distinction.
                                                                 All other values are reserved.
                                                                 0x0 = Does not support a distinction between secure and non-secure
                                                                     memory.
                                                                 0x1 = Does support a distinction between secure and non-secure
                                                                     memory.

                                                                 In CNXXXX, supported. */
		uint64_t bigend                      : 4;  /**< RO - Mixed-endian configuration support.
                                                                 All other values are reserved.
                                                                 0x0 = No mixed-endian support. The AP_SCTLR_ELx[EE] bits have a fixed
                                                                     value. See the BigEndEL0 field, bits[19:16], for whether EL0
                                                                     supports mixed-endian.
                                                                 0x1 = Mixed-endian support. The AP_SCTLR_ELx[EE] and AP_SCTLR_EL1[E0E] bits
                                                                     can be configured.

                                                                 In CNXXXX, supported. */
		uint64_t asidbits                    : 4;  /**< RO - Number of ASID bits.
                                                                 All other values are reserved.
                                                                 0x0 = 8 bits.
                                                                 0x2 = 16 bits.

                                                                 In CNXXXX, 16 bits. */
		uint64_t parange                     : 4;  /**< RO - Physical address range supported.
                                                                 All other values are reserved.
                                                                 0x0 = 32 bits, 4GB.
                                                                 0x1 = 36 bits, 64GB.
                                                                 0x2 = 40 bits, 1TB.
                                                                 0x3 = 42 bits, 4TB.
                                                                 0x4 = 44 bits, 16TB.
                                                                 0x5 = 48 bits, 256TB.

                                                                 In CNXXXX, 48 bits. */
#else
		uint64_t parange                     : 4;
		uint64_t asidbits                    : 4;
		uint64_t bigend                      : 4;
		uint64_t snsmem                      : 4;
		uint64_t bigendel0                   : 4;
		uint64_t tgran16                     : 4;
		uint64_t tgran64                     : 4;
		uint64_t tgran4                      : 4;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_ap_id_aa64mmfr0_el1_s   cn88xx; */
	/* struct bdk_ap_id_aa64mmfr0_el1_s   cn88xxp1; */
} bdk_ap_id_aa64mmfr0_el1_t;

#define BDK_AP_ID_AA64MMFR0_EL1 BDK_AP_ID_AA64MMFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64MMFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64MMFR0_EL1_FUNC(void)
{
	return 0x0000030000070000ull;
}
#define typedef_BDK_AP_ID_AA64MMFR0_EL1 bdk_ap_id_aa64mmfr0_el1_t
#define bustype_BDK_AP_ID_AA64MMFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64MMFR0_EL1 0
#define arguments_BDK_AP_ID_AA64MMFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64MMFR0_EL1 "AP_ID_AA64MMFR0_EL1"


/**
 * SYSREG - ap_id_aa64mmfr1_el1
 *
 * This register contains additional information about the implemented memory model and
 * memory management support in AArch64.
 */
typedef union bdk_ap_id_aa64mmfr1_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64mmfr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t pan                         : 4;  /**< RO - V8.1: Privileged Access Never.
                                                                 0x0 = AP_PAN not supported.
                                                                 0x1 = AP_PAN supported.
                                                                 All other values reserved.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x1, else 0x0. */
		uint64_t lo                          : 4;  /**< RO - V8.1: Limited order regions
                                                                 All other values reserved.
                                                                 0x0 = LORRegions not supported.
                                                                 0x1 = LORRegions supported.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x1, else 0x0. */
		uint64_t hd                          : 4;  /**< RO - V8.1: Hierarchical Attribute Disables.
                                                                 All other values reserved.
                                                                 0x0 = Hierarchical Attribute Disables not supported.
                                                                 0x1 = Hierarchical Attribute Disables supported.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x1, else 0x0. */
		uint64_t vh                          : 4;  /**< RO - V8.1:  Virtualization Host Extensions.
                                                                 All other values reserved.
                                                                 0x0 = Virtualization Host Extensions are not supported.
                                                                 0x1 = Virtualization Host Extensions supported.

                                                                 For CNXXXX, if AP_CVMCTL_EL1[ENABLE_V81] is set 0x1, else 0x0. */
		uint64_t vmidbits                    : 4;  /**< RO - V8.1: Number of VMID bits.
                                                                 Other values are reserved.
                                                                 0x0 = 8 bits.
                                                                 0x1 = Reserved.
                                                                 0x2 = 16 bits.

                                                                 In CNXXXX, 16 bits. */
		uint64_t hardware_access_dirty       : 4;  /**< RO - V8.1: Hardware updates of the Access and Dirty bits
                                                                 All other fields reserved.
                                                                 0x0 = no hardware update of the access and dirty bits supported in hardware.
                                                                 0x1 = hardware update of the access bit supported in hardware.
                                                                 0x2 = hardware update of both the access and dirty bits supported in hardware.

                                                                 In CNXXXX not supported. */
#else
		uint64_t hardware_access_dirty       : 4;
		uint64_t vmidbits                    : 4;
		uint64_t vh                          : 4;
		uint64_t hd                          : 4;
		uint64_t lo                          : 4;
		uint64_t pan                         : 4;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_ap_id_aa64mmfr1_el1_s   cn88xx; */
	/* struct bdk_ap_id_aa64mmfr1_el1_s   cn88xxp1; */
} bdk_ap_id_aa64mmfr1_el1_t;

#define BDK_AP_ID_AA64MMFR1_EL1 BDK_AP_ID_AA64MMFR1_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64MMFR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64MMFR1_EL1_FUNC(void)
{
	return 0x0000030000070100ull;
}
#define typedef_BDK_AP_ID_AA64MMFR1_EL1 bdk_ap_id_aa64mmfr1_el1_t
#define bustype_BDK_AP_ID_AA64MMFR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64MMFR1_EL1 0
#define arguments_BDK_AP_ID_AA64MMFR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64MMFR1_EL1 "AP_ID_AA64MMFR1_EL1"


/**
 * SYSREG - ap_id_aa64pfr#_el1_res0
 *
 * Reserved for future expansion of information about implemented
 * processor features in AArch64. ARM doesn't actually assign
 * a name to these registers, so CNXXXX made up one.
 */
typedef union bdk_ap_id_aa64pfrx_el1_res0 {
	uint64_t u;
	struct bdk_ap_id_aa64pfrx_el1_res0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64pfrx_el1_res0_s cn88xx; */
	/* struct bdk_ap_id_aa64pfrx_el1_res0_s cn88xxp1; */
} bdk_ap_id_aa64pfrx_el1_res0_t;

static inline uint64_t BDK_AP_ID_AA64PFRX_EL1_RES0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64PFRX_EL1_RES0(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 7))))
		return 0x0000030000040000ull + (param1 & 7) * 0x100ull;
	csr_fatal("BDK_AP_ID_AA64PFRX_EL1_RES0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_AA64PFRX_EL1_RES0(...) bdk_ap_id_aa64pfrx_el1_res0_t
#define bustype_BDK_AP_ID_AA64PFRX_EL1_RES0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64PFRX_EL1_RES0(p1) (p1)
#define arguments_BDK_AP_ID_AA64PFRX_EL1_RES0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_AA64PFRX_EL1_RES0(...) "AP_ID_AA64PFRX_EL1_RES0"


/**
 * SYSREG - ap_id_aa64pfr0_el1
 *
 * This register provides additional information about implemented processor features
 * in AArch64.
 */
typedef union bdk_ap_id_aa64pfr0_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64pfr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t gic                         : 4;  /**< RO - GIC system register interface.
                                                                 All other values are reserved.
                                                                 0x0 = No GIC system registers are supported.
                                                                 0x1 = GICv3 system registers are supported.

                                                                 In CNXXXX, supported. */
		uint64_t advsimd                     : 4;  /**< RO - Advanced SIMD.
                                                                 All other values are reserved.
                                                                 0x0 = Advanced SIMD is implemented.
                                                                 0xF = Advanced SIMD is not implemented.

                                                                 In CNXXXX, supported. */
		uint64_t fp                          : 4;  /**< RO - Floating-point.
                                                                 All other values are reserved.
                                                                 0x0 = Floating-point is implemented.
                                                                 0xF = Floating-point is not implemented.

                                                                 In CNXXXX, supported. */
		uint64_t el3                         : 4;  /**< RO - EL3 Exception level handling.
                                                                 All other values are reserved.
                                                                 0x0 = EL3 is not implemented.
                                                                 0x1 = EL3 can be executed in AArch64 state only.
                                                                 0x2 = EL3 can be executed in either AArch64 or AArch32 state.

                                                                 In CNXXXX, supported in AArch64. */
		uint64_t el2                         : 4;  /**< RO - EL2 Exception level handling.
                                                                 All other values are reserved.
                                                                 0x0 = EL2 is not implemented.
                                                                 0x1 = EL2 can be executed in AArch64 state only.
                                                                 0x2 = EL2 can be executed in either AArch64 or AArch32 state.

                                                                 In CNXXXX, supported in AArch64. */
		uint64_t el1                         : 4;  /**< RO - EL1 Exception level handling.
                                                                 All other values are reserved.
                                                                 0x0 = EL1 is not implemented.
                                                                 0x1 = EL1 can be executed in AArch64 state only.
                                                                 0x2 = EL1 can be executed in either AArch64 or AArch32 state.

                                                                 In CNXXXX, supported in AArch64. */
		uint64_t el0                         : 4;  /**< RO - EL0 Exception level handling.
                                                                 All other values are reserved.
                                                                 0x0 = EL0 is not implemented.
                                                                 0x1 = EL0 can be executed in AArch64 state only.
                                                                 0x2 = EL0 can be executed in either AArch64 or AArch32 state.

                                                                 In CNXXXX, supported in AArch64. */
#else
		uint64_t el0                         : 4;
		uint64_t el1                         : 4;
		uint64_t el2                         : 4;
		uint64_t el3                         : 4;
		uint64_t fp                          : 4;
		uint64_t advsimd                     : 4;
		uint64_t gic                         : 4;
		uint64_t reserved_28_63              : 36;
#endif
	} s;
	/* struct bdk_ap_id_aa64pfr0_el1_s    cn88xx; */
	/* struct bdk_ap_id_aa64pfr0_el1_s    cn88xxp1; */
} bdk_ap_id_aa64pfr0_el1_t;

#define BDK_AP_ID_AA64PFR0_EL1 BDK_AP_ID_AA64PFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64PFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64PFR0_EL1_FUNC(void)
{
	return 0x0000030000040000ull;
}
#define typedef_BDK_AP_ID_AA64PFR0_EL1 bdk_ap_id_aa64pfr0_el1_t
#define bustype_BDK_AP_ID_AA64PFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64PFR0_EL1 0
#define arguments_BDK_AP_ID_AA64PFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64PFR0_EL1 "AP_ID_AA64PFR0_EL1"


/**
 * SYSREG - ap_id_aa64pfr1_el1
 *
 * Reserved for future expansion of information about implemented
 * processor features in AArch64.
 */
typedef union bdk_ap_id_aa64pfr1_el1 {
	uint64_t u;
	struct bdk_ap_id_aa64pfr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_id_aa64pfr1_el1_s    cn88xx; */
	/* struct bdk_ap_id_aa64pfr1_el1_s    cn88xxp1; */
} bdk_ap_id_aa64pfr1_el1_t;

#define BDK_AP_ID_AA64PFR1_EL1 BDK_AP_ID_AA64PFR1_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AA64PFR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AA64PFR1_EL1_FUNC(void)
{
	return 0x0000030000040100ull;
}
#define typedef_BDK_AP_ID_AA64PFR1_EL1 bdk_ap_id_aa64pfr1_el1_t
#define bustype_BDK_AP_ID_AA64PFR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AA64PFR1_EL1 0
#define arguments_BDK_AP_ID_AA64PFR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AA64PFR1_EL1 "AP_ID_AA64PFR1_EL1"


/**
 * SYSREG - ap_id_afr0_el1
 *
 * Provides information about the implementation defined features
 * of the PE in AArch32.
 */
typedef union bdk_ap_id_afr0_el1 {
	uint32_t u;
	struct bdk_ap_id_afr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_id_afr0_el1_s        cn88xx; */
	/* struct bdk_ap_id_afr0_el1_s        cn88xxp1; */
} bdk_ap_id_afr0_el1_t;

#define BDK_AP_ID_AFR0_EL1 BDK_AP_ID_AFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_AFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_AFR0_EL1_FUNC(void)
{
	return 0x0000030000010300ull;
}
#define typedef_BDK_AP_ID_AFR0_EL1 bdk_ap_id_afr0_el1_t
#define bustype_BDK_AP_ID_AFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_AFR0_EL1 0
#define arguments_BDK_AP_ID_AFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_AFR0_EL1 "AP_ID_AFR0_EL1"


/**
 * SYSREG - ap_id_dfr0_el1
 *
 * Provides top level information about the debug system in
 *     AArch32.
 * This register is RES0 on CNXXXX since we don't support 32bit,
 * but it still needs to exist per spec.
 */
typedef union bdk_ap_id_dfr0_el1 {
	uint32_t u;
	struct bdk_ap_id_dfr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_id_dfr0_el1_s        cn88xx; */
	/* struct bdk_ap_id_dfr0_el1_s        cn88xxp1; */
} bdk_ap_id_dfr0_el1_t;

#define BDK_AP_ID_DFR0_EL1 BDK_AP_ID_DFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_DFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_DFR0_EL1_FUNC(void)
{
	return 0x0000030000010200ull;
}
#define typedef_BDK_AP_ID_DFR0_EL1 bdk_ap_id_dfr0_el1_t
#define bustype_BDK_AP_ID_DFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_DFR0_EL1 0
#define arguments_BDK_AP_ID_DFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_DFR0_EL1 "AP_ID_DFR0_EL1"


/**
 * SYSREG - ap_id_isar#_el1
 *
 * Instruction set attribute register
 *
 */
typedef union bdk_ap_id_isarx_el1 {
	uint32_t u;
	struct bdk_ap_id_isarx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_id_isarx_el1_s       cn88xx; */
	/* struct bdk_ap_id_isarx_el1_s       cn88xxp1; */
} bdk_ap_id_isarx_el1_t;

static inline uint64_t BDK_AP_ID_ISARX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_ISARX_EL1(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x0000030000020000ull + (param1 & 7) * 0x100ull;
	csr_fatal("BDK_AP_ID_ISARX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_ISARX_EL1(...) bdk_ap_id_isarx_el1_t
#define bustype_BDK_AP_ID_ISARX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_ISARX_EL1(p1) (p1)
#define arguments_BDK_AP_ID_ISARX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_ISARX_EL1(...) "AP_ID_ISARX_EL1"


/**
 * SYSREG - ap_id_isar#_el1_res0
 *
 * Instruction set attribute register. ARM doesn't actually assign a name to these registers, so
 * CNXXXX made up one.
 */
typedef union bdk_ap_id_isarx_el1_res0 {
	uint32_t u;
	struct bdk_ap_id_isarx_el1_res0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_id_isarx_el1_res0_s  cn88xx; */
	/* struct bdk_ap_id_isarx_el1_res0_s  cn88xxp1; */
} bdk_ap_id_isarx_el1_res0_t;

static inline uint64_t BDK_AP_ID_ISARX_EL1_RES0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_ISARX_EL1_RES0(unsigned long param1)
{
	if ((((param1 >= 6) && (param1 <= 7))))
		return 0x0000030000020000ull + (param1 & 7) * 0x100ull;
	csr_fatal("BDK_AP_ID_ISARX_EL1_RES0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_ISARX_EL1_RES0(...) bdk_ap_id_isarx_el1_res0_t
#define bustype_BDK_AP_ID_ISARX_EL1_RES0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_ISARX_EL1_RES0(p1) (p1)
#define arguments_BDK_AP_ID_ISARX_EL1_RES0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_ISARX_EL1_RES0(...) "AP_ID_ISARX_EL1_RES0"


/**
 * SYSREG - ap_id_mmfr#_el1
 *
 * ARM32 Memory model feature register
 *
 */
typedef union bdk_ap_id_mmfrx_el1 {
	uint32_t u;
	struct bdk_ap_id_mmfrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_id_mmfrx_el1_s       cn88xx; */
	/* struct bdk_ap_id_mmfrx_el1_s       cn88xxp1; */
} bdk_ap_id_mmfrx_el1_t;

static inline uint64_t BDK_AP_ID_MMFRX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_MMFRX_EL1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000030000010400ull + (param1 & 3) * 0x100ull;
	csr_fatal("BDK_AP_ID_MMFRX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_ID_MMFRX_EL1(...) bdk_ap_id_mmfrx_el1_t
#define bustype_BDK_AP_ID_MMFRX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_MMFRX_EL1(p1) (p1)
#define arguments_BDK_AP_ID_MMFRX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_ID_MMFRX_EL1(...) "AP_ID_MMFRX_EL1"


/**
 * SYSREG - ap_id_pfr0_el1
 *
 * Gives top-level information about the instruction sets
 * supported by the processor in AArch32.
 */
typedef union bdk_ap_id_pfr0_el1 {
	uint32_t u;
	struct bdk_ap_id_pfr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t state3                      : 4;  /**< RO - T32EE instruction set support.
                                                                 All other values are reserved.
                                                                 0x0 = Not implemented.
                                                                 0x1 = T32EE instruction set implemented. */
		uint32_t state2                      : 4;  /**< RO - Jazelle extension support.
                                                                 All other values are reserved.
                                                                 0x0 = Not implemented.
                                                                 0x1 = Jazelle extension implemented, without clearing of JOSCR[CV] on
                                                                     exception entry.
                                                                 0x2 = Jazelle extension implemented, with clearing of JOSCR[CV] on
                                                                     exception entry. */
		uint32_t state1                      : 4;  /**< RO - T32 instruction set support.
                                                                 All other values are reserved.
                                                                 0x0 = T32 instruction set not implemented.

                                                                 0x1 = T32 encodings before the introduction of Thumb-2 technology
                                                                     implemented:
                                                                  All instructions are 16-bit.
                                                                  A BL or BLX is a pair of 16-bit instructions.
                                                                  32-bit instructions other than BL and BLX cannot be encoded.

                                                                 0x3 = T32 encodings after the introduction of Thumb-2 technology
                                                                     implemented, for all 16-bit and 32-bit T32 basic instructions. */
		uint32_t state0                      : 4;  /**< RO - A32 instruction set support.
                                                                 All other values are reserved.
                                                                 0x0 = A32 instruction set not implemented.
                                                                 0x1 = A32 instruction set implemented. */
#else
		uint32_t state0                      : 4;
		uint32_t state1                      : 4;
		uint32_t state2                      : 4;
		uint32_t state3                      : 4;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_ap_id_pfr0_el1_s        cn88xx; */
	/* struct bdk_ap_id_pfr0_el1_s        cn88xxp1; */
} bdk_ap_id_pfr0_el1_t;

#define BDK_AP_ID_PFR0_EL1 BDK_AP_ID_PFR0_EL1_FUNC()
static inline uint64_t BDK_AP_ID_PFR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_PFR0_EL1_FUNC(void)
{
	return 0x0000030000010000ull;
}
#define typedef_BDK_AP_ID_PFR0_EL1 bdk_ap_id_pfr0_el1_t
#define bustype_BDK_AP_ID_PFR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_PFR0_EL1 0
#define arguments_BDK_AP_ID_PFR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_PFR0_EL1 "AP_ID_PFR0_EL1"


/**
 * SYSREG - ap_id_pfr1_el1
 *
 * Gives information about the programmers' model and extensions
 * support in AArch32.
 */
typedef union bdk_ap_id_pfr1_el1 {
	uint32_t u;
	struct bdk_ap_id_pfr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t gic                         : 4;  /**< RO - GIC CP15 interface.
                                                                 All other values are reserved.
                                                                 0x0 = No GIC CP15 registers are supported.
                                                                 0x1 = GICv3 CP15 registers are supported. */
		uint32_t virt_frac                   : 4;  /**< RO - Virtualization fractional field. When the Virtualization field
                                                                     is0b0000
                                                                 All other values are reserved.
                                                                 This field is only valid when AP_ID_PFR1_EL1[15:12] == 0,
                                                                     otherwise it holds the value0b0000
                                                                 0x0 = No features from the ARMv7 Virtualization Extensions are
                                                                     implemented.
                                                                 0x1 = The SCR[SIF] bit is implemented. The modifications to the
                                                                     SCR[AW] and SCR[FW] bits are part of the control of whether the
                                                                     CPSR[A] and CPSR[F] bits mask the corresponding aborts. The MSR
                                                                     (Banked register) and MRS (Banked register) instructions are
                                                                     implemented.
                                                                 This value is permitted only when AP_ID_PFR1_EL1[Security] is
                                                                     not0b0000 */
		uint32_t sec_frac                    : 4;  /**< RO - Security fractional field. When the Security field is0b0000
                                                                 All other values are reserved.
                                                                 This field is only valid when AP_ID_PFR1_EL1[7:4] == 0, otherwise
                                                                     it holds the value0b0000
                                                                 0x0 = No features from the ARMv7 Security Extensions are
                                                                     implemented.
                                                                 0x1 = The implementation includes the VBAR, and the TCR[PD0] and
                                                                     TCR[PD1] bits.
                                                                 0x2 = As for 0x1. */
		uint32_t gentimer                    : 4;  /**< RO - Generic Timer Extension support.
                                                                 All other values are reserved.
                                                                 0x0 = Not implemented.
                                                                 0x1 = Generic Timer Extension implemented. */
		uint32_t virtualization              : 4;  /**< RO - Virtualization support.
                                                                 All other values are reserved.
                                                                 A value of0b0001
                                                                 0x0 = EL2 not implemented.
                                                                 0x1 = EL2 implemented. */
		uint32_t mprogmod                    : 4;  /**< RO - M profile programmers' model support.
                                                                 All other values are reserved.
                                                                 0x0 = Not supported.
                                                                 0x2 = Support for two-stack programmers' model. */
		uint32_t security                    : 4;  /**< RO - Security support.
                                                                 All other values are reserved.
                                                                 0x0 = EL3 not implemented.
                                                                 0x1 = EL3 implemented.
                                                                 This includes support for Monitor mode and the SMC
                                                                     instruction.
                                                                 0x2 = As for 0x1 NSACR[RFR] bit. Not permitted in ARMv8 as the
                                                                     NSACR[RFR] bit is RES0. */
		uint32_t progmod                     : 4;  /**< RO - Support for the standard programmers' model for ARMv4 and
                                                                     later. Model must support User, FIQ, IRQ, Supervisor, Abort,
                                                                     Undefined, and System modes.
                                                                 All other values are reserved.
                                                                 0x0 = Not supported.
                                                                 0x1 = Supported. */
#else
		uint32_t progmod                     : 4;
		uint32_t security                    : 4;
		uint32_t mprogmod                    : 4;
		uint32_t virtualization              : 4;
		uint32_t gentimer                    : 4;
		uint32_t sec_frac                    : 4;
		uint32_t virt_frac                   : 4;
		uint32_t gic                         : 4;
#endif
	} s;
	/* struct bdk_ap_id_pfr1_el1_s        cn88xx; */
	/* struct bdk_ap_id_pfr1_el1_s        cn88xxp1; */
} bdk_ap_id_pfr1_el1_t;

#define BDK_AP_ID_PFR1_EL1 BDK_AP_ID_PFR1_EL1_FUNC()
static inline uint64_t BDK_AP_ID_PFR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ID_PFR1_EL1_FUNC(void)
{
	return 0x0000030000010100ull;
}
#define typedef_BDK_AP_ID_PFR1_EL1 bdk_ap_id_pfr1_el1_t
#define bustype_BDK_AP_ID_PFR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ID_PFR1_EL1 0
#define arguments_BDK_AP_ID_PFR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ID_PFR1_EL1 "AP_ID_PFR1_EL1"


/**
 * SYSREG - ap_ifsr32_el2
 *
 * Allows access to the AArch32 IFSR register from AArch64 state
 * only. Its value has no effect on execution in AArch64 state.
 */
typedef union bdk_ap_ifsr32_el2 {
	uint32_t u;
	struct bdk_ap_ifsr32_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_ifsr32_el2_s         cn88xx; */
	/* struct bdk_ap_ifsr32_el2_s         cn88xxp1; */
} bdk_ap_ifsr32_el2_t;

#define BDK_AP_IFSR32_EL2 BDK_AP_IFSR32_EL2_FUNC()
static inline uint64_t BDK_AP_IFSR32_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_IFSR32_EL2_FUNC(void)
{
	return 0x0000030405000100ull;
}
#define typedef_BDK_AP_IFSR32_EL2 bdk_ap_ifsr32_el2_t
#define bustype_BDK_AP_IFSR32_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_IFSR32_EL2 0
#define arguments_BDK_AP_IFSR32_EL2 -1,-1,-1,-1
#define basename_BDK_AP_IFSR32_EL2 "AP_IFSR32_EL2"


/**
 * SYSREG - ap_isr_el1
 *
 * Shows whether an IRQ, FIQ, or SError interrupt is pending. If
 * EL2 is implemented, an indicated pending interrupt might be a
 * physical interrupt or a virtual interrupt.
 */
typedef union bdk_ap_isr_el1 {
	uint32_t u;
	struct bdk_ap_isr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t aa                          : 1;  /**< RO - SError pending bit:
                                                                 0 = No pending SError.
                                                                 1 = An SError interrupt is pending. */
		uint32_t i                           : 1;  /**< RO - IRQ pending bit. Indicates whether an IRQ interrupt is
                                                                     pending:
                                                                 0 = No pending IRQ.
                                                                 1 = An IRQ interrupt is pending. */
		uint32_t f                           : 1;  /**< RO - FIQ pending bit. Indicates whether an FIQ interrupt is
                                                                     pending.
                                                                 0 = No pending FIQ.
                                                                 1 = An FIQ interrupt is pending. */
		uint32_t reserved_0_5                : 6;
#else
		uint32_t reserved_0_5                : 6;
		uint32_t f                           : 1;
		uint32_t i                           : 1;
		uint32_t aa                          : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_ap_isr_el1_s            cn88xx; */
	/* struct bdk_ap_isr_el1_s            cn88xxp1; */
} bdk_ap_isr_el1_t;

#define BDK_AP_ISR_EL1 BDK_AP_ISR_EL1_FUNC()
static inline uint64_t BDK_AP_ISR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_ISR_EL1_FUNC(void)
{
	return 0x000003000C010000ull;
}
#define typedef_BDK_AP_ISR_EL1 bdk_ap_isr_el1_t
#define bustype_BDK_AP_ISR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_ISR_EL1 0
#define arguments_BDK_AP_ISR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_ISR_EL1 "AP_ISR_EL1"


/**
 * SYSREG - ap_lorc_el1
 *
 * v8.1: LORegion Control, being a 64-bit read/write register that is
 * accessible from EL1 or above.
 *
 * When the AP_LORC_EL1[EN] bit is 0, then no acceses match an LORegion
 * Note: this has the consequence that if the AP_LORID_EL1 indicates that no
 * LORegions are implemented, then the LoadLOAcquire and StoreLORelease
 * will therefore behave as LoadAcquire and StoreRelease.
 *
 * The AP_LORC_EL1[EN] bit is permitted to be cached within a TLB.
 * Note: In keeping with the other system registers in the ARMv8
 * architecture, the LORC register must be explicitly synchronised for
 * changes in the AP_LORC_EL1[DS] field to take effect.
 */
typedef union bdk_ap_lorc_el1 {
	uint64_t u;
	struct bdk_ap_lorc_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t ds                          : 3;  /**< R/W - Descriptor Select, being a number that selects the current LOR
                                                                 Descriptor accessed by the AP_LORSA_EL1, AP_LOREA_EL1, AP_LORN_EL1
                                                                 registers; If the AP_LORC_EL1[DS] points to a LOR Descriptor that is
                                                                 not supported by an implementation then the AP_LOREA_EL1, AP_LORSA_EL1
                                                                 and AP_LORN_EL1 are RES0. */
		uint64_t reserved_1_1                : 1;
		uint64_t en                          : 1;  /**< R/W - Enable.
                                                                 0 = Disabled (reset value).
                                                                 1 = Enabled. */
#else
		uint64_t en                          : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t ds                          : 3;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_ap_lorc_el1_s           cn88xx; */
	/* struct bdk_ap_lorc_el1_s           cn88xxp1; */
} bdk_ap_lorc_el1_t;

#define BDK_AP_LORC_EL1 BDK_AP_LORC_EL1_FUNC()
static inline uint64_t BDK_AP_LORC_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_LORC_EL1_FUNC(void)
{
	return 0x000003000A040300ull;
}
#define typedef_BDK_AP_LORC_EL1 bdk_ap_lorc_el1_t
#define bustype_BDK_AP_LORC_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_LORC_EL1 0
#define arguments_BDK_AP_LORC_EL1 -1,-1,-1,-1
#define basename_BDK_AP_LORC_EL1 "AP_LORC_EL1"


/**
 * SYSREG - ap_lorea_el1
 *
 * v8.1: LORegion End Address being a 64 bit read/write register that is
 * accessible from EL1 or above.
 * The AP_LOREA_EL1 is permitted to be cached in a TLB.
 * If the AP_LORN_EL1[StartAddress] \> AP_LORN_EL1[EndAddress] for a LOR
 * Descriptor, then that LOR Descriptor does not match any LORegion.
 */
typedef union bdk_ap_lorea_el1 {
	uint64_t u;
	struct bdk_ap_lorea_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t ea                          : 32; /**< R/W - End physical address bits \<47:16\>. Bits\<15:0\> of the end address
                                                                 are defined to be 0xFFFF. */
		uint64_t reserved_0_15               : 16;
#else
		uint64_t reserved_0_15               : 16;
		uint64_t ea                          : 32;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_lorea_el1_s          cn88xx; */
	/* struct bdk_ap_lorea_el1_s          cn88xxp1; */
} bdk_ap_lorea_el1_t;

#define BDK_AP_LOREA_EL1 BDK_AP_LOREA_EL1_FUNC()
static inline uint64_t BDK_AP_LOREA_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_LOREA_EL1_FUNC(void)
{
	return 0x000003000A040100ull;
}
#define typedef_BDK_AP_LOREA_EL1 bdk_ap_lorea_el1_t
#define bustype_BDK_AP_LOREA_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_LOREA_EL1 0
#define arguments_BDK_AP_LOREA_EL1 -1,-1,-1,-1
#define basename_BDK_AP_LOREA_EL1 "AP_LOREA_EL1"


/**
 * SYSREG - ap_lorid_el1
 *
 * v8.1: The LORegion ID provides an ID register as to how many LORegions
 * and LOR Descriptors are supported by the system.
 * The AP_LORID_EL1 register is a 64-bit Read-only register accessible from
 * EL1 and above.
 * If no LOR Descriptors are implemented then the AP_LORC_EL1, AP_LORN_EL1,
 * AP_LORSA_EL1 and AP_LOREA_EL1 registers are RES0.
 */
typedef union bdk_ap_lorid_el1 {
	uint64_t u;
	struct bdk_ap_lorid_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t ld                          : 8;  /**< RO - Number of LOR Descriptors supported by the implementation,
                                                                 expressed as binary 8 bit number. */
		uint64_t reserved_8_15               : 8;
		uint64_t lr                          : 8;  /**< RO - Number of LORegions supported by the implementation, expressed as
                                                                 binary 8 bit number. */
#else
		uint64_t lr                          : 8;
		uint64_t reserved_8_15               : 8;
		uint64_t ld                          : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_ap_lorid_el1_s          cn88xx; */
	/* struct bdk_ap_lorid_el1_s          cn88xxp1; */
} bdk_ap_lorid_el1_t;

#define BDK_AP_LORID_EL1 BDK_AP_LORID_EL1_FUNC()
static inline uint64_t BDK_AP_LORID_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_LORID_EL1_FUNC(void)
{
	return 0x000003000A040700ull;
}
#define typedef_BDK_AP_LORID_EL1 bdk_ap_lorid_el1_t
#define bustype_BDK_AP_LORID_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_LORID_EL1 0
#define arguments_BDK_AP_LORID_EL1 -1,-1,-1,-1
#define basename_BDK_AP_LORID_EL1 "AP_LORID_EL1"


/**
 * SYSREG - ap_lorn_el1
 *
 * v8.1: LORegion Number, being a 64-bit read/write register that is
 * accessible from EL1 or above.
 * The AP_LORN_EL1 is permitted to be cached in a TLB.
 * If the AP_LORN_EL1[Num] bit points to a LORegion that is not supported by
 * the implemented, then that LOR Descriptor does not match any LORegion.
 */
typedef union bdk_ap_lorn_el1 {
	uint64_t u;
	struct bdk_ap_lorn_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t num                         : 2;  /**< R/W - LORegion Number.

                                                                 For CNXXXX region number 0 is special and matches all physical
                                                                 addresses. */
#else
		uint64_t num                         : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ap_lorn_el1_s           cn88xx; */
	/* struct bdk_ap_lorn_el1_s           cn88xxp1; */
} bdk_ap_lorn_el1_t;

#define BDK_AP_LORN_EL1 BDK_AP_LORN_EL1_FUNC()
static inline uint64_t BDK_AP_LORN_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_LORN_EL1_FUNC(void)
{
	return 0x000003000A040200ull;
}
#define typedef_BDK_AP_LORN_EL1 bdk_ap_lorn_el1_t
#define bustype_BDK_AP_LORN_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_LORN_EL1 0
#define arguments_BDK_AP_LORN_EL1 -1,-1,-1,-1
#define basename_BDK_AP_LORN_EL1 "AP_LORN_EL1"


/**
 * SYSREG - ap_lorsa_el1
 *
 * v8.1: LORegion Start Address being a 64 bit read/write register that is
 * accessible from EL1 or above
 * The AP_LORSA_EL1 is permitted to be cached in a TLB.
 */
typedef union bdk_ap_lorsa_el1 {
	uint64_t u;
	struct bdk_ap_lorsa_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t sa                          : 32; /**< R/W - Start physical address bits \<47:16\>. Bits\<15:0\> of the start
                                                                 physical address are defined to be 0x0. */
		uint64_t reserved_1_15               : 15;
		uint64_t valid                       : 1;  /**< R/W - indicates whether the LORegion Descriptor is enabled
                                                                 0 = Not valid (reset value).
                                                                 1 = Valid. */
#else
		uint64_t valid                       : 1;
		uint64_t reserved_1_15               : 15;
		uint64_t sa                          : 32;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_lorsa_el1_s          cn88xx; */
	/* struct bdk_ap_lorsa_el1_s          cn88xxp1; */
} bdk_ap_lorsa_el1_t;

#define BDK_AP_LORSA_EL1 BDK_AP_LORSA_EL1_FUNC()
static inline uint64_t BDK_AP_LORSA_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_LORSA_EL1_FUNC(void)
{
	return 0x000003000A040000ull;
}
#define typedef_BDK_AP_LORSA_EL1 bdk_ap_lorsa_el1_t
#define bustype_BDK_AP_LORSA_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_LORSA_EL1 0
#define arguments_BDK_AP_LORSA_EL1 -1,-1,-1,-1
#define basename_BDK_AP_LORSA_EL1 "AP_LORSA_EL1"


/**
 * SYSREG - ap_mair_el#
 *
 * Provides the memory attribute encodings corresponding to the
 * possible AttrIndx values in a Long-descriptor format
 * translation table entry for stage 1 translations at EL3.
 */
typedef union bdk_ap_mair_elx {
	uint64_t u;
	struct bdk_ap_mair_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t attr_n                      : 64; /**< R/W - The memory attribute encoding for an AttrIndx[2:0] entry in a
                                                                     Long descriptor format translation table entry, where
                                                                     AttrIndx[2:0] gives the value of \<n\> in Attr\<n\>.

                                                                 Bits [7:4] are encoded as follows:

                                                                 Attr\<n\>[7:4]        Meaning
                                                                 0b0000      Device memory. See encoding of Attr\<n\>[3:0] for the type of Device memory.
                                                                 0b00RW0b00  Normal Memory, Outer Write-through transient
                                                                 0b0100      Normal Memory, Outer Non-Cacheable
                                                                 0b01RW0b00  Normal Memory, Outer Write-back transient
                                                                 0b10RW      Normal Memory, Outer Write-through non-transient
                                                                 0b11RW      Normal Memory, Outer Write-back non-transient

                                                                 R = Outer Read Allocate Policy, W = Outer Write Allocate
                                                                     Policy.

                                                                 The meaning of bits [3:0] depends on the value of bits [7:4]:

                                                                 Attr\<n\>[3:0]        Meaning when Attr\<n\>[7:4] is 0000       Meaning when Attr\<n\>[7:4] is
                                                                 not 0000
                                                                 0b0000      Device-nGnRnE memory     UNPREDICTABLE
                                                                 0b00RW0b00   UNPREDICTABLE  Normal Memory, Inner Write-through transient
                                                                 0b0100      Device-nGnRE memory     Normal memory, Inner Non-Cacheable
                                                                 0b01RW0b00   UNPREDICTABLE  Normal Memory, Inner Write-back transient
                                                                 0b1000      Device-nGRE memory      Normal Memory, Inner Write-through non-transient
                                                                 (RW=00)
                                                                 0b10RW0b00   UNPREDICTABLE  Normal Memory, Inner Write-through non-transient
                                                                 0b1100      Device-GRE memory       Normal Memory, Inner Write-back non-transient (RW=00)
                                                                 0b11RW0b00   UNPREDICTABLE  Normal Memory, Inner Write-back non-transient

                                                                 R = Inner Read Allocate Policy, W = Inner Write Allocate
                                                                     Policy.

                                                                 ARMv7's Strongly-ordered and Device memory types have been
                                                                     renamed to Device-nGnRnE and Device-nGnRE in ARMv8.

                                                                 The R and W bits in some Attr\<n\> fields have the following
                                                                     meanings:

                                                                 R or W      Meaning
                                                                 0 = Do not allocate.
                                                                 1 = Allocate. */
#else
		uint64_t attr_n                      : 64;
#endif
	} s;
	/* struct bdk_ap_mair_elx_s           cn88xx; */
	/* struct bdk_ap_mair_elx_s           cn88xxp1; */
} bdk_ap_mair_elx_t;

static inline uint64_t BDK_AP_MAIR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MAIR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x000003000A020000ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_MAIR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_MAIR_ELX(...) bdk_ap_mair_elx_t
#define bustype_BDK_AP_MAIR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MAIR_ELX(p1) (p1)
#define arguments_BDK_AP_MAIR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_MAIR_ELX(...) "AP_MAIR_ELX"


/**
 * SYSREG - ap_mair_el12
 *
 * Alias of ESR_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_mair_el12 {
	uint64_t u;
	struct bdk_ap_mair_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_mair_el12_s          cn88xx; */
	/* struct bdk_ap_mair_el12_s          cn88xxp1; */
} bdk_ap_mair_el12_t;

#define BDK_AP_MAIR_EL12 BDK_AP_MAIR_EL12_FUNC()
static inline uint64_t BDK_AP_MAIR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MAIR_EL12_FUNC(void)
{
	return 0x000003050A020000ull;
}
#define typedef_BDK_AP_MAIR_EL12 bdk_ap_mair_el12_t
#define bustype_BDK_AP_MAIR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MAIR_EL12 0
#define arguments_BDK_AP_MAIR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_MAIR_EL12 "AP_MAIR_EL12"


/**
 * SYSREG - ap_mdccint_el1
 *
 * Enables interrupt requests to be signaled based on the DCC
 * status flags.
 */
typedef union bdk_ap_mdccint_el1 {
	uint32_t u;
	struct bdk_ap_mdccint_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t rx                          : 1;  /**< R/W - DCC interrupt request enable control for DTRRX. Enables a
                                                                     common COMMIRQ interrupt request to be signaled based on the
                                                                     DCC status flags.

                                                                 If legacy COMMRX and COMMTX signals are implemented, then
                                                                     these are not affected by the value of this bit.
                                                                 0 = No interrupt request generated by DTRRX.
                                                                 1 = Interrupt request will be generated on RXfull == 1. */
		uint32_t tx                          : 1;  /**< R/W - DCC interrupt request enable control for DTRTX. Enables a
                                                                     common COMMIRQ interrupt request to be signaled based on the
                                                                     DCC status flags.

                                                                 If legacy COMMRX and COMMTX signals are implemented, then
                                                                     these are not affected by the value of this bit.
                                                                 0 = No interrupt request generated by DTRTX.
                                                                 1 = Interrupt request will be generated on TXfull == 0. */
		uint32_t reserved_0_28               : 29;
#else
		uint32_t reserved_0_28               : 29;
		uint32_t tx                          : 1;
		uint32_t rx                          : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_ap_mdccint_el1_s        cn88xx; */
	/* struct bdk_ap_mdccint_el1_s        cn88xxp1; */
} bdk_ap_mdccint_el1_t;

#define BDK_AP_MDCCINT_EL1 BDK_AP_MDCCINT_EL1_FUNC()
static inline uint64_t BDK_AP_MDCCINT_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MDCCINT_EL1_FUNC(void)
{
	return 0x0000020000020000ull;
}
#define typedef_BDK_AP_MDCCINT_EL1 bdk_ap_mdccint_el1_t
#define bustype_BDK_AP_MDCCINT_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MDCCINT_EL1 0
#define arguments_BDK_AP_MDCCINT_EL1 -1,-1,-1,-1
#define basename_BDK_AP_MDCCINT_EL1 "AP_MDCCINT_EL1"


/**
 * SYSREG - ap_mdccsr_el0
 *
 * Main control register for the debug implementation, containing
 * flow-control flags for the DCC. This is an internal, read-only
 * view.
 */
typedef union bdk_ap_mdccsr_el0 {
	uint32_t u;
	struct bdk_ap_mdccsr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t rxfull                      : 1;  /**< RO - DTRRX full. Read-only view of the equivalent bit in the EDSCR. */
		uint32_t txfull                      : 1;  /**< RO - DTRTX full. Read-only view of the equivalent bit in the EDSCR. */
		uint32_t reserved_0_28               : 29;
#else
		uint32_t reserved_0_28               : 29;
		uint32_t txfull                      : 1;
		uint32_t rxfull                      : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_ap_mdccsr_el0_s         cn88xx; */
	/* struct bdk_ap_mdccsr_el0_s         cn88xxp1; */
} bdk_ap_mdccsr_el0_t;

#define BDK_AP_MDCCSR_EL0 BDK_AP_MDCCSR_EL0_FUNC()
static inline uint64_t BDK_AP_MDCCSR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MDCCSR_EL0_FUNC(void)
{
	return 0x0000020300010000ull;
}
#define typedef_BDK_AP_MDCCSR_EL0 bdk_ap_mdccsr_el0_t
#define bustype_BDK_AP_MDCCSR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MDCCSR_EL0 0
#define arguments_BDK_AP_MDCCSR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_MDCCSR_EL0 "AP_MDCCSR_EL0"


/**
 * SYSREG - ap_mdcr_el2
 *
 * Provides configuration options for the Virtualization
 * extensions to self-hosted debug and the Performance Monitors
 * extension.
 */
typedef union bdk_ap_mdcr_el2 {
	uint32_t u;
	struct bdk_ap_mdcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_18_31              : 14;
		uint32_t hpmd                        : 1;  /**< R/W - v8.1: Hyp performance monitors disable. This prohibits event counting
                                                                 at EL2.
                                                                 0 = Event counting allowed at EL2.
                                                                 1 = Event counting prohibited at EL2, unless overridden by
                                                                         the authentication interface.

                                                                 Note: This behavior is independent of the value of the AP_HCR_EL2[E2H]
                                                                 bit.
                                                                 This control applies only to:
                                                                 The counters in the range [0.[HPMN]).
                                                                 If AP_PMCR_EL0[DP] is set to 1, AP_PMCCNTR_EL0.
                                                                 The other event counters and, if AP_PMCR_EL0[DP] is set to 0,
                                                                 AP_PMCCNTR_EL0 are unaffected.

                                                                 On Warm reset, the field resets to 0. */
		uint32_t reserved_12_16              : 5;
		uint32_t tdra                        : 1;  /**< R/W - Trap debug ROM address register access.

                                                                 When this bit is set to 1, any access to the following
                                                                     registers from EL1 or EL0 is trapped to EL2:

                                                                 AArch32: DBGDRAR, DBGDSAR.

                                                                 AArch64: AP_MDRAR_EL1.

                                                                 If AP_HCR_EL2[TGE] == 1 or AP_MDCR_EL2[TDE] == 1, then this bit is
                                                                     ignored and treated as though it is 1 other than for the value
                                                                     read back from AP_MDCR_EL2.

                                                                 0 = Has no effect on accesses to debug ROM address registers from
                                                                     EL1 and EL0.
                                                                 1 = Trap valid EL1 and EL0 access to debug ROM address registers
                                                                     to EL2. */
		uint32_t tdosa                       : 1;  /**< R/W - Trap debug OS-related register access.
                                                                 When this bit is set to 1, any access to the following
                                                                     registers from EL1 or EL0 is trapped to EL2:

                                                                 AArch32: DBGOSLAR, DBGOSLSR, DBGOSDLR, DBGPRCR.

                                                                 AArch64: AP_OSLAR_EL1, AP_OSLSR_EL1, AP_OSDLR_EL1, AP_DBGPRCR_EL1.

                                                                 If AP_HCR_EL2[TGE] == 1 or AP_MDCR_EL2[TDE] == 1, then this bit is
                                                                     ignored and treated as though it is 1 other than for the value
                                                                     read back from AP_MDCR_EL2.
                                                                 0 = Has no effect on accesses to OS-related debug registers.
                                                                 1 = Trap valid accesses to OS-related debug registers to EL2. */
		uint32_t tda                         : 1;  /**< R/W - Trap debug access.

                                                                 When this bit is set to 1, any valid non-secure access to the
                                                                     debug registers from EL1 or EL0, other than the registers
                                                                     trapped by the TDRA and TDOSA bits, is trapped to EL2.

                                                                 If AP_HCR_EL2[TGE] == 1 or AP_MDCR_EL2[TDE] == 1, then this bit is
                                                                     ignored and treated as though it is 1 other than for the value
                                                                     read back from AP_MDCR_EL2.
                                                                 0 = Has no effect on accesses to debug registers.
                                                                 1 = Trap valid non-secure accesses to debug registers to EL2. */
		uint32_t tde                         : 1;  /**< R/W - Route Software debug exceptions from non-secure EL1 and EL0 to
                                                                     EL2. Also enables traps on all debug register accesses to EL2.
                                                                 If AP_HCR_EL2[TGE] == 1, then this bit is ignored and treated as
                                                                     though it is 1 other than for the value read back from
                                                                     AP_MDCR_EL2. */
		uint32_t hpme                        : 1;  /**< R/W - Hypervisor Performance Monitors Enable.
                                                                 When this bit is set to 1, the Performance Monitors counters
                                                                     that are reserved for use from EL2 or Secure state are
                                                                     enabled. For more information see the description of the HPMN
                                                                     field.
                                                                 If the Performance Monitors extension is not implemented, this
                                                                     field is RES0.
                                                                 0 = EL2 Performance Monitors disabled.
                                                                 1 = EL2 Performance Monitors enabled. */
		uint32_t tpm                         : 1;  /**< R/W - Trap Performance Monitors accesses.
                                                                 If the Performance Monitors extension is not implemented, this
                                                                     field is RES0.
                                                                 0 = Has no effect on Performance Monitors accesses.
                                                                 1 = Trap non-secure EL0 and EL1 accesses to Performance Monitors
                                                                     registers that are not unallocated to EL2. */
		uint32_t tpmcr                       : 1;  /**< R/W - Trap AP_PMCR_EL0 accesses.
                                                                 If the Performance Monitors extension is not implemented, this
                                                                     field is RES0.
                                                                 0 = Has no effect on AP_PMCR_EL0 accesses.
                                                                 1 = Trap non-secure EL0 and EL1 accesses to AP_PMCR_EL0 to EL2. */
		uint32_t hpmn                        : 5;  /**< R/W - Defines the number of Performance Monitors counters that are
                                                                     accessible from non-secure EL0 and EL1 modes.

                                                                 If the Performance Monitors extension is not implemented, this
                                                                     field is RES0.

                                                                 In non-secure state, HPMN divides the Performance Monitors
                                                                     counters as follows. For counter n in non-secure state:

                                                                  If n is in the range 0\<=n\<HPMN, the counter is accessible
                                                                     from EL1 and EL2, and from EL0 if permitted by AP_PMUSERENR_EL0.
                                                                     AP_PMCR_EL0[E] enables the operation of counters in this range.

                                                                  If n is in the range HPMN\<=n\< AP_PMCR_EL0[N], the counter is
                                                                     accessible only from EL2. AP_MDCR_EL2[HPME] enables the operation
                                                                     of counters in this range.

                                                                 If this field is set to 0, or to a value larger than
                                                                     AP_PMCR_EL0[N], then the behavior in non-secure EL0 and EL1 is
                                                                     CONSTRAINED UNPREDICTABLE, and one of the following must
                                                                     happen:

                                                                  The number of counters accessible is an UNKNOWN non-zero
                                                                     value less than AP_PMCR_EL0[N].

                                                                  There is no access to any counters.

                                                                 For reads of AP_MDCR_EL2[HPMN] by EL2 or higher, if this field is
                                                                     set to 0 or to a value larger than AP_PMCR_EL0[N], the processor
                                                                     must return a CONSTRAINED UNPREDICTABLE value being one of:
                                                                   AP_PMCR_EL0[N].

                                                                  The value that was written to AP_MDCR_EL2[HPMN].
                                                                  (The value that was written to AP_MDCR_EL2[HPMN]) modulo
                                                                     22^(h), where h is the smallest number of bits required
                                                                     for a value in the range 0 to  AP_PMCR_EL0[N]. */
#else
		uint32_t hpmn                        : 5;
		uint32_t tpmcr                       : 1;
		uint32_t tpm                         : 1;
		uint32_t hpme                        : 1;
		uint32_t tde                         : 1;
		uint32_t tda                         : 1;
		uint32_t tdosa                       : 1;
		uint32_t tdra                        : 1;
		uint32_t reserved_12_16              : 5;
		uint32_t hpmd                        : 1;
		uint32_t reserved_18_31              : 14;
#endif
	} s;
	/* struct bdk_ap_mdcr_el2_s           cn88xx; */
	/* struct bdk_ap_mdcr_el2_s           cn88xxp1; */
} bdk_ap_mdcr_el2_t;

#define BDK_AP_MDCR_EL2 BDK_AP_MDCR_EL2_FUNC()
static inline uint64_t BDK_AP_MDCR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MDCR_EL2_FUNC(void)
{
	return 0x0000030401010100ull;
}
#define typedef_BDK_AP_MDCR_EL2 bdk_ap_mdcr_el2_t
#define bustype_BDK_AP_MDCR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MDCR_EL2 0
#define arguments_BDK_AP_MDCR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_MDCR_EL2 "AP_MDCR_EL2"


/**
 * SYSREG - ap_mdcr_el3
 *
 * Provides configuration options for the Security extensions to
 * self-hosted debug.
 */
typedef union bdk_ap_mdcr_el3 {
	uint32_t u;
	struct bdk_ap_mdcr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_22_31              : 10;
		uint32_t epmad                       : 1;  /**< R/W - External debugger access to Performance Monitors registers
                                                                     disabled. This disables access to these registers by an
                                                                     external debugger:
                                                                 0 = Access to Performance Monitors registers from external
                                                                     debugger is permitted.
                                                                 1 = Access to Performance Monitors registers from external
                                                                     debugger is disabled, unless overridden by authentication
                                                                     interface. */
		uint32_t edad                        : 1;  /**< R/W - External debugger access to breakpoint and watchpoint
                                                                     registers disabled. This disables access to these registers by
                                                                     an external debugger:
                                                                 0 = Access to breakpoint and watchpoint registers from external
                                                                     debugger is permitted.
                                                                 1 = Access to breakpoint and watchpoint registers from external
                                                                     debugger is disabled, unless overridden by authentication
                                                                     interface. */
		uint32_t reserved_18_19              : 2;
		uint32_t spme                        : 1;  /**< R/W - Secure performance monitors enable. This allows event counting
                                                                     in Secure state:
                                                                 0 = Event counting prohibited in Secure state, unless overridden
                                                                     by the authentication interface.
                                                                 1 = Event counting allowed in Secure state. */
		uint32_t sdd                         : 1;  /**< R/W - AArch64 secure self-hosted invasive debug disable. Disables
                                                                     Software debug exceptions in Secure state, other than Software
                                                                     breakpoint instruction.
                                                                 SDD only applies when both of the following are true:
                                                                  The processor is executing in Secure state.
                                                                  Secure EL1 is using AArch64.
                                                                 0 = Taking Software debug events as debug exceptions is permitted
                                                                     from Secure EL0 and EL1, if enabled by the relevant AP_MDSCR_EL1
                                                                     and PSTATE[D] flags.
                                                                 1 = Software debug events, other than software breakpoint
                                                                     instruction debug events, are disabled from all Exception
                                                                     levels in Secure state. */
		uint32_t reserved_11_15              : 5;
		uint32_t tdosa                       : 1;  /**< R/W - Trap debug OS-related register access.
                                                                 When this bit is set to 1, any access to the following
                                                                     registers from EL2 or below is trapped to EL3:

                                                                 AArch32: DBGOSLAR, DBGOSLSR, DBGOSDLR, DBGPRCR.

                                                                 AArch64: AP_OSLAR_EL1, AP_OSLSR_EL1, AP_OSDLR_EL1, AP_DBGPRCR_EL1.

                                                                 0 = Has no effect on accesses to OS-related debug registers.
                                                                 1 = Trap valid accesses to OS-related debug registers to EL3. */
		uint32_t tda                         : 1;  /**< R/W - Trap debug access.
                                                                 When this bit is set to 1, any valid non-secure access to the
                                                                     debug registers from EL2 or below, other than the registers
                                                                     trapped by the TDRA and TDOSA bits, is trapped to EL3.
                                                                 0 = Has no effect on accesses to debug registers.
                                                                 1 = Trap valid non-secure accesses to debug registers to EL3. */
		uint32_t reserved_7_8                : 2;
		uint32_t tpm                         : 1;  /**< R/W - Trap Performance Monitors accesses.
                                                                 If the Performance Monitors extension is not implemented, this
                                                                     field is RES0.
                                                                 0 = Has no effect on Performance Monitors accesses.
                                                                 1 = Trap non-secure EL0, EL1 and EL2 accesses to Performance
                                                                     Monitors registers that are not unallocated, or trapped to a
                                                                     lower Exception level, to EL3. */
		uint32_t reserved_0_5                : 6;
#else
		uint32_t reserved_0_5                : 6;
		uint32_t tpm                         : 1;
		uint32_t reserved_7_8                : 2;
		uint32_t tda                         : 1;
		uint32_t tdosa                       : 1;
		uint32_t reserved_11_15              : 5;
		uint32_t sdd                         : 1;
		uint32_t spme                        : 1;
		uint32_t reserved_18_19              : 2;
		uint32_t edad                        : 1;
		uint32_t epmad                       : 1;
		uint32_t reserved_22_31              : 10;
#endif
	} s;
	/* struct bdk_ap_mdcr_el3_s           cn88xx; */
	/* struct bdk_ap_mdcr_el3_s           cn88xxp1; */
} bdk_ap_mdcr_el3_t;

#define BDK_AP_MDCR_EL3 BDK_AP_MDCR_EL3_FUNC()
static inline uint64_t BDK_AP_MDCR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MDCR_EL3_FUNC(void)
{
	return 0x0000030601030100ull;
}
#define typedef_BDK_AP_MDCR_EL3 bdk_ap_mdcr_el3_t
#define bustype_BDK_AP_MDCR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MDCR_EL3 0
#define arguments_BDK_AP_MDCR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_MDCR_EL3 "AP_MDCR_EL3"


/**
 * SYSREG - ap_mdrar_el1
 *
 * Defines the base physical address of a 4KB-aligned memory-
 * mapped debug component, usually a ROM table that locates and
 * describes the memory-mapped debug components in the system.
 */
typedef union bdk_ap_mdrar_el1 {
	uint64_t u;
	struct bdk_ap_mdrar_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t romaddr                     : 36; /**< RO - Bits[P-1:12] of the ROM table physical address, where P is the
                                                                     physical address size in bits (up to 48 bits) as stored in
                                                                     AP_ID_AA64MMFR0_EL1. If P is less than 48, bits[47:P] of this
                                                                     register are RES0.

                                                                 Bits [11:0] of the ROM table physical address are zero.

                                                                 If EL3 is implemented, ROMADDR is an address in non-secure
                                                                     memory. Whether the ROM table is also accessible in Secure
                                                                     memory is implementation defined. */
		uint64_t reserved_2_11               : 10;
		uint64_t valid                       : 2;  /**< RO - This field indicates whether the ROM Table address is valid.

                                                                 0x0 = ROM Table address is not valid
                                                                 0x3 = ROM Table address is valid. */
#else
		uint64_t valid                       : 2;
		uint64_t reserved_2_11               : 10;
		uint64_t romaddr                     : 36;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_mdrar_el1_s          cn88xx; */
	/* struct bdk_ap_mdrar_el1_s          cn88xxp1; */
} bdk_ap_mdrar_el1_t;

#define BDK_AP_MDRAR_EL1 BDK_AP_MDRAR_EL1_FUNC()
static inline uint64_t BDK_AP_MDRAR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MDRAR_EL1_FUNC(void)
{
	return 0x0000020001000000ull;
}
#define typedef_BDK_AP_MDRAR_EL1 bdk_ap_mdrar_el1_t
#define bustype_BDK_AP_MDRAR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MDRAR_EL1 0
#define arguments_BDK_AP_MDRAR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_MDRAR_EL1 "AP_MDRAR_EL1"


/**
 * SYSREG - ap_mdscr_el1
 *
 * Main control register for the debug implementation.
 *
 */
typedef union bdk_ap_mdscr_el1 {
	uint32_t u;
	struct bdk_ap_mdscr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t rxfull                      : 1;  /**< R/W - Used for save/restore of EDSCR[RXfull].
                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO, and software must treat it as UNK/SBZP.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t txfull                      : 1;  /**< R/W - Used for save/restore of EDSCR[TXfull].
                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO, and software must treat it as UNK/SBZP.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t reserved_28_28              : 1;
		uint32_t rxo                         : 1;  /**< R/W - Used for save/restore of EDSCR[RXO].
                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO. Software must treat it as UNKNOWN and use an SBZP
                                                                     policy for writes.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t txu                         : 1;  /**< R/W - Used for save/restore of EDSCR[TXU].
                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO. Software must treat it as UNKNOWN and use an SBZP
                                                                     policy for writes.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t reserved_24_25              : 2;
		uint32_t intdis                      : 2;  /**< R/W - Used for save/restore of EDSCR[INTdis].
                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this field
                                                                     is RO. Software must treat it as UNKNOWN and use an SBZP
                                                                     policy for writes.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this field
                                                                     is RW. */
		uint32_t tda                         : 1;  /**< R/W - Used for save/restore of EDSCR[TDA].
                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO. Software must treat it as UNKNOWN and use an SBZP
                                                                     policy for writes.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t reserved_16_20              : 5;
		uint32_t mde                         : 1;  /**< R/W - Monitor debug events. Enable Breakpoint, Watchpoint, and
                                                                     Vector catch debug exceptions.
                                                                 0 = Breakpoint, Watchpoint, and Vector catch debug exceptions
                                                                     disabled.
                                                                 1 = Breakpoint, Watchpoint, and Vector catch debug exceptions
                                                                     enabled. */
		uint32_t hde                         : 1;  /**< R/W - Used for save/restore of EDSCR[HDE].

                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO. Software must treat it as UNKNOWN and use an SBZP
                                                                     policy for writes.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t kde                         : 1;  /**< R/W - Local (kernel) debug enable. If EL{d} is using
                                                                     AArch64, enable Software debug events within EL{d}.

                                                                 RES0 if EL{d} is using AArch32.
                                                                 0 = Software debug events, other than Software breakpoint
                                                                     instructions, disabled within EL{d}.
                                                                 1 = Software debug events enabled within EL{d}. */
		uint32_t tdcc                        : 1;  /**< R/W - Trap Debug Communications Channel access. When set, any EL0
                                                                     access to the following registers is trapped to EL1:

                                                                 AArch32: DBGDIDR, DBGDRAR, DBGDSAR, DBGDSCRint, DBGDTRTXint,
                                                                     DBGDTRRXint.

                                                                 AArch64: AP_MDCCSR_EL0, AP_DBGDTR_EL0, AP_DBGDTRTX_EL0, AP_DBGDTRRX_EL0. */
		uint32_t reserved_7_11               : 5;
		uint32_t err                         : 1;  /**< R/W - Used for save/restore of EDSCR[ERR].

                                                                 When AP_OSLSR_EL1[OSLK] == 0 (the OS lock is unlocked), this bit
                                                                     is RO. Software must treat it as UNKNOWN and use an SBZP
                                                                     policy for writes.

                                                                 When AP_OSLSR_EL1[OSLK] == 1 (the OS lock is locked), this bit is
                                                                     RW. */
		uint32_t reserved_1_5                : 5;
		uint32_t ss                          : 1;  /**< R/W - Software step control bit. If EL{d} is using AArch64,
                                                                     enable Software step.
                                                                 RES0 if EL{d} is using AArch32.
                                                                 0 = Software step disabled
                                                                 1 = Software step enabled. */
#else
		uint32_t ss                          : 1;
		uint32_t reserved_1_5                : 5;
		uint32_t err                         : 1;
		uint32_t reserved_7_11               : 5;
		uint32_t tdcc                        : 1;
		uint32_t kde                         : 1;
		uint32_t hde                         : 1;
		uint32_t mde                         : 1;
		uint32_t reserved_16_20              : 5;
		uint32_t tda                         : 1;
		uint32_t intdis                      : 2;
		uint32_t reserved_24_25              : 2;
		uint32_t txu                         : 1;
		uint32_t rxo                         : 1;
		uint32_t reserved_28_28              : 1;
		uint32_t txfull                      : 1;
		uint32_t rxfull                      : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_ap_mdscr_el1_s          cn88xx; */
	/* struct bdk_ap_mdscr_el1_s          cn88xxp1; */
} bdk_ap_mdscr_el1_t;

#define BDK_AP_MDSCR_EL1 BDK_AP_MDSCR_EL1_FUNC()
static inline uint64_t BDK_AP_MDSCR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MDSCR_EL1_FUNC(void)
{
	return 0x0000020000020200ull;
}
#define typedef_BDK_AP_MDSCR_EL1 bdk_ap_mdscr_el1_t
#define bustype_BDK_AP_MDSCR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MDSCR_EL1 0
#define arguments_BDK_AP_MDSCR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_MDSCR_EL1 "AP_MDSCR_EL1"


/**
 * SYSREG - ap_midr_el1
 *
 * This register provides identification information for the PE, including an
 * implementer code for the device and a device ID number.
 */
typedef union bdk_ap_midr_el1 {
	uint32_t u;
	struct bdk_ap_midr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t implementer                 : 8;  /**< RO - Implementer code that has been assigned by ARM. Assigned codes include the
                                                                 following:
                                                                 0x41 = 'A' = ARM Limited.
                                                                 0x42 = 'B' = Broadcom Corporation.
                                                                 0x43 = 'C' = Cavium Inc.
                                                                 0x44 = 'D' = Digital Equipment Corporation.
                                                                 0x49 = 'I' = Infineon Technologies AG.
                                                                 0x4D = 'M' = Motorola or Freescale Semiconductor Inc.
                                                                 0x4E = 'N' = NVIDIA Corporation.
                                                                 0x50 = 'P' = Applied Micro Circuits Corporation.
                                                                 0x51 = 'Q' = Qualcomm Inc.
                                                                 0x56 = 'V' = Marvell International Ltd.
                                                                 0x69 = 'i' = Intel Corporation.

                                                                 For CNXXXX, 'C'. */
		uint32_t variant                     : 4;  /**< RO - An implementation defined variant number. Typically, this
                                                                     field is used to distinguish between different product
                                                                     variants, or major revisions of a product.

                                                                 For CNXXXX this is the major pass, starting at zero. */
		uint32_t architecture                : 4;  /**< RO - 0x1 = ARMv4.
                                                                 0x2 = ARMv4T.
                                                                 0x3 = ARMv5 (obsolete).
                                                                 0x4 = ARMv5T.
                                                                 0x5 = ARMv5TE.
                                                                 0x6 = ARMv5TEJ.
                                                                 0x7 = ARMv6.
                                                                 0xF = Defined by CPUID scheme.

                                                                 For CNXXXX, CPUID scheme. */
		uint32_t partnum                     : 12; /**< RO - An implementation defined primary part number for the device.
                                                                 On processors implemented by ARM, if the top four bits of the
                                                                     primary part number are 0x00x7.
                                                                 Processors implemented by ARM have an Implementer code of 0x41.

                                                                 For CNXXXX, the chip ID. Enumerated by PCC_PROD_E. */
		uint32_t revision                    : 4;  /**< RO - An implementation defined revision number for the device.

                                                                 For CNXXXX, the minor pass. */
#else
		uint32_t revision                    : 4;
		uint32_t partnum                     : 12;
		uint32_t architecture                : 4;
		uint32_t variant                     : 4;
		uint32_t implementer                 : 8;
#endif
	} s;
	/* struct bdk_ap_midr_el1_s           cn88xx; */
	/* struct bdk_ap_midr_el1_s           cn88xxp1; */
} bdk_ap_midr_el1_t;

#define BDK_AP_MIDR_EL1 BDK_AP_MIDR_EL1_FUNC()
static inline uint64_t BDK_AP_MIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MIDR_EL1_FUNC(void)
{
	return 0x0000030000000000ull;
}
#define typedef_BDK_AP_MIDR_EL1 bdk_ap_midr_el1_t
#define bustype_BDK_AP_MIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MIDR_EL1 0
#define arguments_BDK_AP_MIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_MIDR_EL1 "AP_MIDR_EL1"


/**
 * SYSREG - ap_mpidr_el1
 *
 * This register in a multiprocessor system provides an additional PE identification
 * mechanism for scheduling purposes, and indicates whether the implementation includes
 * the multiprocessing extensions.
 */
typedef union bdk_ap_mpidr_el1 {
	uint64_t u;
	struct bdk_ap_mpidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t aff3                        : 8;  /**< RO - Affinity level 3. Highest level affinity field.

                                                                 Always zero on CNXXXX. */
		uint64_t rsvd_31                     : 1;  /**< RO - Reserved 1. */
		uint64_t u                           : 1;  /**< RO - Indicates a uniprocessor system, as distinct from PE 0 in a
                                                                     multiprocessor system.
                                                                 0 = Processor is part of a multiprocessor system.
                                                                 1 = Processor is part of a uniprocessor system. */
		uint64_t reserved_25_29              : 5;
		uint64_t mt                          : 1;  /**< RO - Indicates whether the lowest level of affinity consists of
                                                                     logical PEs that are implemented using a multi-threading type
                                                                     approach.
                                                                 0 = Performance of PEs at the lowest affinity level is largely
                                                                     independent.
                                                                 1 = Performance of PEs at the lowest affinity level is very
                                                                     interdependent. */
		uint64_t aff2                        : 8;  /**< RO - Affinity level 2. Second highest level affinity field.

                                                                 For CNXXXX, the socket number. */
		uint64_t aff1                        : 8;  /**< RO - Affinity level 1. Third highest level affinity field.

                                                                 For CNXXXX the processor number upper 2 bits. */
		uint64_t aff0                        : 8;  /**< RO - Affinity level 0. Lowest level affinity field.
                                                                 WARNING: The GIC register ICC_SGI{0,1}R_EL1 limits this
                                                                 to 0-15 as its a 16 bit mask.

                                                                 For CNXXXX the processor number lower 4 bits. */
#else
		uint64_t aff0                        : 8;
		uint64_t aff1                        : 8;
		uint64_t aff2                        : 8;
		uint64_t mt                          : 1;
		uint64_t reserved_25_29              : 5;
		uint64_t u                           : 1;
		uint64_t rsvd_31                     : 1;
		uint64_t aff3                        : 8;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_ap_mpidr_el1_s          cn88xx; */
	/* struct bdk_ap_mpidr_el1_s          cn88xxp1; */
} bdk_ap_mpidr_el1_t;

#define BDK_AP_MPIDR_EL1 BDK_AP_MPIDR_EL1_FUNC()
static inline uint64_t BDK_AP_MPIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MPIDR_EL1_FUNC(void)
{
	return 0x0000030000000500ull;
}
#define typedef_BDK_AP_MPIDR_EL1 bdk_ap_mpidr_el1_t
#define bustype_BDK_AP_MPIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MPIDR_EL1 0
#define arguments_BDK_AP_MPIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_MPIDR_EL1 "AP_MPIDR_EL1"


/**
 * SYSREG - ap_mvfr#_el1
 *
 * Describes the features provided by the Advanced SIMD and Floating-point Extensions.
 *
 */
typedef union bdk_ap_mvfrx_el1 {
	uint32_t u;
	struct bdk_ap_mvfrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_mvfrx_el1_s          cn88xx; */
	/* struct bdk_ap_mvfrx_el1_s          cn88xxp1; */
} bdk_ap_mvfrx_el1_t;

static inline uint64_t BDK_AP_MVFRX_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_MVFRX_EL1(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x0000030000030000ull + (param1 & 3) * 0x100ull;
	csr_fatal("BDK_AP_MVFRX_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_MVFRX_EL1(...) bdk_ap_mvfrx_el1_t
#define bustype_BDK_AP_MVFRX_EL1(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_MVFRX_EL1(p1) (p1)
#define arguments_BDK_AP_MVFRX_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_AP_MVFRX_EL1(...) "AP_MVFRX_EL1"


/**
 * SYSREG - ap_nzcv
 *
 * Allows access to the condition flags.
 *
 */
typedef union bdk_ap_nzcv {
	uint32_t u;
	struct bdk_ap_nzcv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t n                           : 1;  /**< R/W - Negative condition flag. Set to bit[31] of the result of the
                                                                 last flag-setting instruction. If the result is regarded as a
                                                                 two's complement signed integer, then the processor sets N to
                                                                 1 if the result was negative, and sets N to 0 if it was
                                                                 positive or zero. */
		uint32_t z                           : 1;  /**< R/W - Zero condition flag. Set to 1 if the result of the last flag-
                                                                 setting instruction was zero, and to 0 otherwise. A result of
                                                                 zero often indicates an equal result from a comparison. */
		uint32_t cc                          : 1;  /**< R/W - Carry condition flag. Set to 1 if the last flag-setting
                                                                 instruction resulted in a carry condition, for example an
                                                                 unsigned overflow on an addition. */
		uint32_t v                           : 1;  /**< R/W - Overflow condition flag. Set to 1 if the last flag-setting
                                                                 instruction resulted in an overflow condition, for example a
                                                                 signed overflow on an addition. */
		uint32_t reserved_0_27               : 28;
#else
		uint32_t reserved_0_27               : 28;
		uint32_t v                           : 1;
		uint32_t cc                          : 1;
		uint32_t z                           : 1;
		uint32_t n                           : 1;
#endif
	} s;
	/* struct bdk_ap_nzcv_s               cn88xx; */
	/* struct bdk_ap_nzcv_s               cn88xxp1; */
} bdk_ap_nzcv_t;

#define BDK_AP_NZCV BDK_AP_NZCV_FUNC()
static inline uint64_t BDK_AP_NZCV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_NZCV_FUNC(void)
{
	return 0x0000030304020000ull;
}
#define typedef_BDK_AP_NZCV bdk_ap_nzcv_t
#define bustype_BDK_AP_NZCV BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_NZCV 0
#define arguments_BDK_AP_NZCV -1,-1,-1,-1
#define basename_BDK_AP_NZCV "AP_NZCV"


/**
 * SYSREG - ap_osdlr_el1
 *
 * Used to control the OS Double Lock.
 *
 */
typedef union bdk_ap_osdlr_el1 {
	uint32_t u;
	struct bdk_ap_osdlr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t dlk                         : 1;  /**< R/W - OS Double Lock control bit.
                                                                 0 = OS Double Lock unlocked.
                                                                 1 = OS Double Lock locked, if AP_DBGPRCR_EL1[CORENPDRQ] (Core no
                                                                     power-down request) bit is set to 0 and the processor is in
                                                                     Non-debug state. */
#else
		uint32_t dlk                         : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_osdlr_el1_s          cn88xx; */
	/* struct bdk_ap_osdlr_el1_s          cn88xxp1; */
} bdk_ap_osdlr_el1_t;

#define BDK_AP_OSDLR_EL1 BDK_AP_OSDLR_EL1_FUNC()
static inline uint64_t BDK_AP_OSDLR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_OSDLR_EL1_FUNC(void)
{
	return 0x0000020001030400ull;
}
#define typedef_BDK_AP_OSDLR_EL1 bdk_ap_osdlr_el1_t
#define bustype_BDK_AP_OSDLR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_OSDLR_EL1 0
#define arguments_BDK_AP_OSDLR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_OSDLR_EL1 "AP_OSDLR_EL1"


/**
 * SYSREG - ap_osdtrrx_el1
 *
 * Used for save/restore of AP_DBGDTRRX_EL0. It is a component of
 * the Debug Communications Channel.
 */
typedef union bdk_ap_osdtrrx_el1 {
	uint32_t u;
	struct bdk_ap_osdtrrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Host to target data. One word of data for transfer from the
                                                                     debug host to the debug target.
                                                                 For the full behavior of the Debug Communications Channel,
                                                                     see. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_osdtrrx_el1_s        cn88xx; */
	/* struct bdk_ap_osdtrrx_el1_s        cn88xxp1; */
} bdk_ap_osdtrrx_el1_t;

#define BDK_AP_OSDTRRX_EL1 BDK_AP_OSDTRRX_EL1_FUNC()
static inline uint64_t BDK_AP_OSDTRRX_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_OSDTRRX_EL1_FUNC(void)
{
	return 0x0000020000000200ull;
}
#define typedef_BDK_AP_OSDTRRX_EL1 bdk_ap_osdtrrx_el1_t
#define bustype_BDK_AP_OSDTRRX_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_OSDTRRX_EL1 0
#define arguments_BDK_AP_OSDTRRX_EL1 -1,-1,-1,-1
#define basename_BDK_AP_OSDTRRX_EL1 "AP_OSDTRRX_EL1"


/**
 * SYSREG - ap_osdtrtx_el1
 *
 * Used for save/restore of AP_DBGDTRTX_EL0. It is a component of
 * the Debug Communications Channel.
 */
typedef union bdk_ap_osdtrtx_el1 {
	uint32_t u;
	struct bdk_ap_osdtrtx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Target to host data. One word of data for transfer from the
                                                                     debug target to the debug host.
                                                                 For the full behavior of the Debug Communications Channel,
                                                                     see. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_osdtrtx_el1_s        cn88xx; */
	/* struct bdk_ap_osdtrtx_el1_s        cn88xxp1; */
} bdk_ap_osdtrtx_el1_t;

#define BDK_AP_OSDTRTX_EL1 BDK_AP_OSDTRTX_EL1_FUNC()
static inline uint64_t BDK_AP_OSDTRTX_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_OSDTRTX_EL1_FUNC(void)
{
	return 0x0000020000030200ull;
}
#define typedef_BDK_AP_OSDTRTX_EL1 bdk_ap_osdtrtx_el1_t
#define bustype_BDK_AP_OSDTRTX_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_OSDTRTX_EL1 0
#define arguments_BDK_AP_OSDTRTX_EL1 -1,-1,-1,-1
#define basename_BDK_AP_OSDTRTX_EL1 "AP_OSDTRTX_EL1"


/**
 * SYSREG - ap_oseccr_el1
 *
 * Provides a mechanism for an operating system to access the
 * contents of EDECCR that are otherwise invisible to software,
 * so it can save/restore the contents of EDECCR over powerdown
 * on behalf of the external debugger.
 */
typedef union bdk_ap_oseccr_el1 {
	uint32_t u;
	struct bdk_ap_oseccr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t edeccr                      : 32; /**< R/W - Used for save/restore to EDECCR over powerdown. */
#else
		uint32_t edeccr                      : 32;
#endif
	} s;
	/* struct bdk_ap_oseccr_el1_s         cn88xx; */
	/* struct bdk_ap_oseccr_el1_s         cn88xxp1; */
} bdk_ap_oseccr_el1_t;

#define BDK_AP_OSECCR_EL1 BDK_AP_OSECCR_EL1_FUNC()
static inline uint64_t BDK_AP_OSECCR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_OSECCR_EL1_FUNC(void)
{
	return 0x0000020000060200ull;
}
#define typedef_BDK_AP_OSECCR_EL1 bdk_ap_oseccr_el1_t
#define bustype_BDK_AP_OSECCR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_OSECCR_EL1 0
#define arguments_BDK_AP_OSECCR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_OSECCR_EL1 "AP_OSECCR_EL1"


/**
 * SYSREG - ap_oslar_el1
 *
 * Used to lock or unlock the OS lock.
 *
 */
typedef union bdk_ap_oslar_el1 {
	uint32_t u;
	struct bdk_ap_oslar_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t oslk                        : 1;  /**< RO - On writes to AP_OSLAR_EL1, bit[0] is copied to the OS lock.
                                                                 Use AP_OSLSR_EL1[OSLK] to check the current status of the lock. */
#else
		uint32_t oslk                        : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_oslar_el1_s          cn88xx; */
	/* struct bdk_ap_oslar_el1_s          cn88xxp1; */
} bdk_ap_oslar_el1_t;

#define BDK_AP_OSLAR_EL1 BDK_AP_OSLAR_EL1_FUNC()
static inline uint64_t BDK_AP_OSLAR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_OSLAR_EL1_FUNC(void)
{
	return 0x0000020001000400ull;
}
#define typedef_BDK_AP_OSLAR_EL1 bdk_ap_oslar_el1_t
#define bustype_BDK_AP_OSLAR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_OSLAR_EL1 0
#define arguments_BDK_AP_OSLAR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_OSLAR_EL1 "AP_OSLAR_EL1"


/**
 * SYSREG - ap_oslsr_el1
 *
 * Provides the status of the OS lock.
 *
 */
typedef union bdk_ap_oslsr_el1 {
	uint32_t u;
	struct bdk_ap_oslsr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t oslm_high                   : 1;  /**< RO - See below for description of the OSLM field. */
		uint32_t ntt                         : 1;  /**< RO - Not 32-bit access. This bit is always RAZ. It indicates that a
                                                                 32-bit access is needed to write the key to the OS lock access
                                                                 register. */
		uint32_t oslk                        : 1;  /**< RO - OS Lock Status.
                                                                 The OS Lock is locked and unlocked by writing to the OS Lock
                                                                     Access Register.
                                                                 0 = OS lock unlocked.
                                                                 1 = OS lock locked. */
		uint32_t oslm_low                    : 1;  /**< RO - OS lock model implemented. Identifies the form of OS save and
                                                                     restore mechanism implemented. In ARMv8 these bits are as
                                                                     follows:
                                                                 All other values are reserved.
                                                                 OSLM0x2 = OS lock implemented. DBGOSSRR not implemented. */
#else
		uint32_t oslm_low                    : 1;
		uint32_t oslk                        : 1;
		uint32_t ntt                         : 1;
		uint32_t oslm_high                   : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_ap_oslsr_el1_s          cn88xx; */
	/* struct bdk_ap_oslsr_el1_s          cn88xxp1; */
} bdk_ap_oslsr_el1_t;

#define BDK_AP_OSLSR_EL1 BDK_AP_OSLSR_EL1_FUNC()
static inline uint64_t BDK_AP_OSLSR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_OSLSR_EL1_FUNC(void)
{
	return 0x0000020001010400ull;
}
#define typedef_BDK_AP_OSLSR_EL1 bdk_ap_oslsr_el1_t
#define bustype_BDK_AP_OSLSR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_OSLSR_EL1 0
#define arguments_BDK_AP_OSLSR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_OSLSR_EL1 "AP_OSLSR_EL1"


/**
 * SYSREG - ap_pan
 *
 * v8.1: Privileged Access Never bit.
 *
 * When 0, this bit has no effect on the translation system compared with
 * the situation in ARMv8.
 *
 * When 1, this bit disables data read or data write access from EL1 (or
 * EL2 when AP_HCR_EL2[E2H]==1) to a virtual address where access to the
 * virtual address at EL0 is permitted at stage 1 by the combination of
 * the AP[1] bit and the APTable[0] bits(if appropriate). That is, when
 * AP[1]==1 && APTable[0]==0, for all APTable bits associated with that
 * virtual address.
 *
 * The AP_PAN bit has no effect on instruction accesses.
 *
 * If access is disabled, then the access will give rise to a stage 1
 * permission fault, taken in the same way as all other stage 1
 * permission faults.
 *
 * PSTATE[AP_PAN] is copied to SPSR[AP_PAN] on an exception taken from AArch64
 * SPSR[AP_PAN] is copied to PSTATE[AP_PAN] on an exception return to AArch64
 */
typedef union bdk_ap_pan {
	uint64_t u;
	struct bdk_ap_pan_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t pan                         : 1;  /**< R/W - Privileged Access Never bit. */
		uint64_t reserved_0_21               : 22;
#else
		uint64_t reserved_0_21               : 22;
		uint64_t pan                         : 1;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_ap_pan_s                cn88xx; */
	/* struct bdk_ap_pan_s                cn88xxp1; */
} bdk_ap_pan_t;

#define BDK_AP_PAN BDK_AP_PAN_FUNC()
static inline uint64_t BDK_AP_PAN_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PAN_FUNC(void)
{
	return 0x0000030004020300ull;
}
#define typedef_BDK_AP_PAN bdk_ap_pan_t
#define bustype_BDK_AP_PAN BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PAN 0
#define arguments_BDK_AP_PAN -1,-1,-1,-1
#define basename_BDK_AP_PAN "AP_PAN"


/**
 * SYSREG - ap_par_el1
 *
 * Receives the PA from any address translation operation.
 *
 */
typedef union bdk_ap_par_el1 {
	uint64_t u;
	struct bdk_ap_par_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mair                        : 8;  /**< R/W - - On success (f=0): Memory Attributes, following the encodings for the MAIR.
                                                                 - On failure (f=1): Zero */
		uint64_t reserved_48_55              : 8;
		uint64_t pa                          : 36; /**< R/W - Physical Address. The physical address corresponding to the
                                                                 supplied virtual address. This field returns address
                                                                 bits \<47:12\>. */
		uint64_t rsvd_11                     : 1;  /**< RO - Reserved 1. */
		uint64_t reserved_10_10              : 1;
		uint64_t nsec                        : 1;  /**< R/W - Non-secure. The NS attribute for a translation table entry
                                                                     read from Secure state.
                                                                 This bit is UNKNOWN for a translation table entry read from
                                                                     non-secure state. */
		uint64_t sha                         : 2;  /**< R/W - Shareability attribute, from the translation table entry for
                                                                     the returned PA.
                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Inner Shareable. */
		uint64_t fs                          : 6;  /**< R/W - - On success (f=0): Zero.
                                                                 - On failure (f=1): Fault Status code shown in the Data Abort. */
		uint64_t f                           : 1;  /**< R/W - Indicates whether the conversion completed successfully.
                                                                 0 = VA to PA conversion completed successfully. */
#else
		uint64_t f                           : 1;
		uint64_t fs                          : 6;
		uint64_t sha                         : 2;
		uint64_t nsec                        : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rsvd_11                     : 1;
		uint64_t pa                          : 36;
		uint64_t reserved_48_55              : 8;
		uint64_t mair                        : 8;
#endif
	} s;
	/* struct bdk_ap_par_el1_s            cn88xx; */
	/* struct bdk_ap_par_el1_s            cn88xxp1; */
} bdk_ap_par_el1_t;

#define BDK_AP_PAR_EL1 BDK_AP_PAR_EL1_FUNC()
static inline uint64_t BDK_AP_PAR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PAR_EL1_FUNC(void)
{
	return 0x0000030007040000ull;
}
#define typedef_BDK_AP_PAR_EL1 bdk_ap_par_el1_t
#define bustype_BDK_AP_PAR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PAR_EL1 0
#define arguments_BDK_AP_PAR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_PAR_EL1 "AP_PAR_EL1"


/**
 * SYSREG - ap_pmccfiltr_el0
 *
 * Determines the modes in which the Cycle Counter, AP_PMCCNTR_EL0,
 * increments.
 */
typedef union bdk_ap_pmccfiltr_el0 {
	uint32_t u;
	struct bdk_ap_pmccfiltr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t p                           : 1;  /**< R/W - EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in non-secure EL1 is further
                                                                     controlled by the NSK bit.
                                                                 0 = Count cycles in EL1.
                                                                 1 = Do not count cycles in EL1. */
		uint32_t u                           : 1;  /**< R/W - EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in non-secure EL0 is further
                                                                     controlled by the NSU bit.
                                                                 0 = Count cycles in EL0.
                                                                 1 = Do not count cycles in EL0. */
		uint32_t nsk                         : 1;  /**< R/W - Non-secure kernel modes filtering bit. Controls counting in
                                                                     non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, cycles in
                                                                     non-secure EL1 are counted.
                                                                 Otherwise, cycles in non-secure EL1 are not counted. */
		uint32_t nsu                         : 1;  /**< R/W - Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, cycles in
                                                                     non-secure EL0 are counted.
                                                                 Otherwise, cycles in non-secure EL0 are not counted. */
		uint32_t nsh                         : 1;  /**< R/W - Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count cycles in EL2.
                                                                 1 = Count cycles in EL2. */
		uint32_t m                           : 1;  /**< R/W - Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.

                                                                 If the value of this bit is equal to the value of P, cycles in
                                                                     Secure EL3 are counted.

                                                                 Otherwise, cycles in Secure EL3 are not counted. */
		uint32_t reserved_0_25               : 26;
#else
		uint32_t reserved_0_25               : 26;
		uint32_t m                           : 1;
		uint32_t nsh                         : 1;
		uint32_t nsu                         : 1;
		uint32_t nsk                         : 1;
		uint32_t u                           : 1;
		uint32_t p                           : 1;
#endif
	} s;
	/* struct bdk_ap_pmccfiltr_el0_s      cn88xx; */
	/* struct bdk_ap_pmccfiltr_el0_s      cn88xxp1; */
} bdk_ap_pmccfiltr_el0_t;

#define BDK_AP_PMCCFILTR_EL0 BDK_AP_PMCCFILTR_EL0_FUNC()
static inline uint64_t BDK_AP_PMCCFILTR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCCFILTR_EL0_FUNC(void)
{
	return 0x000003030E0F0700ull;
}
#define typedef_BDK_AP_PMCCFILTR_EL0 bdk_ap_pmccfiltr_el0_t
#define bustype_BDK_AP_PMCCFILTR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCCFILTR_EL0 0
#define arguments_BDK_AP_PMCCFILTR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCCFILTR_EL0 "AP_PMCCFILTR_EL0"


/**
 * SYSREG - ap_pmccntr_el0
 *
 * Holds the value of the processor Cycle Counter, CCNT, that
 * counts processor clock cycles.
 */
typedef union bdk_ap_pmccntr_el0 {
	uint64_t u;
	struct bdk_ap_pmccntr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ccnt                        : 64; /**< R/W - Cycle count. Depending on the values of AP_PMCR_EL0.{LC,D}, this
                                                                     field increments in one of the following ways:
                                                                  Every processor clock cycle.
                                                                  Every 64th processor clock cycle.
                                                                 This field can be reset to zero by writing 1 to AP_PMCR_EL0[C]. */
#else
		uint64_t ccnt                        : 64;
#endif
	} s;
	/* struct bdk_ap_pmccntr_el0_s        cn88xx; */
	/* struct bdk_ap_pmccntr_el0_s        cn88xxp1; */
} bdk_ap_pmccntr_el0_t;

#define BDK_AP_PMCCNTR_EL0 BDK_AP_PMCCNTR_EL0_FUNC()
static inline uint64_t BDK_AP_PMCCNTR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCCNTR_EL0_FUNC(void)
{
	return 0x00000303090D0000ull;
}
#define typedef_BDK_AP_PMCCNTR_EL0 bdk_ap_pmccntr_el0_t
#define bustype_BDK_AP_PMCCNTR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCCNTR_EL0 0
#define arguments_BDK_AP_PMCCNTR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCCNTR_EL0 "AP_PMCCNTR_EL0"


/**
 * SYSREG - ap_pmceid0_el0
 *
 * Defines which common architectural and common
 * microarchitectural feature events are implemented. If a
 * particular bit is set to 1, then the event for that bit is
 * implemented.
 */
typedef union bdk_ap_pmceid0_el0 {
	uint64_t u;
	struct bdk_ap_pmceid0_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ce                          : 64; /**< RO - Common architectural and microarchitectural feature events
                                                                     that can be counted by the PMU event counters.
                                                                 For each bit described in the following table, the event is
                                                                     implemented if the bit is set to 1, or not implemented if the
                                                                     bit is set to 0.

                                                                 \<pre\>
                                                                 Bit Event number    Event mnemonic
                                                                 31  0x01F   L1D_CACHE_ALLOCATE
                                                                 30  0x01E   CHAIN
                                                                 29  0x01D   BUS_CYCLES
                                                                 28  0x01C   TTBR_WRITE_RETIRED
                                                                 27  0x01B   INST_SPEC
                                                                 26  0x01A   MEMORY_ERROR
                                                                 25  0x019   BUS_ACCESS
                                                                 24  0x018   L2D_CACHE_WB
                                                                 23  0x017   L2D_CACHE_REFILL
                                                                 22  0x016   L2D_CACHE
                                                                 21  0x015   L1D_CACHE_WB
                                                                 20  0x014   L1I_CACHE
                                                                 19  0x013   MEM_ACCESS
                                                                 18  0x012   BR_PRED
                                                                 17  0x011   CPU_CYCLES
                                                                 16  0x010   BR_MIS_PRED
                                                                 15  0x00F   UNALIGNED_LDST_RETIRED
                                                                 14  0x00E   BR_RETURN_RETIRED
                                                                 13  0x00D   BR_IMMED_RETIRED
                                                                 12  0x00C   PC_WRITE_RETIRED
                                                                 11  0x00B   CID_WRITE_RETIRED
                                                                 10  0x00A   EXC_RETURN
                                                                 9   0x009   EXC_TAKEN
                                                                 8   0x008   INST_RETIRED
                                                                 7   0x007   ST_RETIRED
                                                                 6   0x006   LD_RETIRED
                                                                 5   0x005   L1D_TLB_REFILL
                                                                 4   0x004   L1D_CACHE
                                                                 3   0x003   L1D_CACHE_REFILL
                                                                 2   0x002   L1I_TLB_REFILL
                                                                 1   0x001   L1I_CACHE_REFILL
                                                                 0   0x000   SW_INCR
                                                                 \</pre\> */
#else
		uint64_t ce                          : 64;
#endif
	} s;
	/* struct bdk_ap_pmceid0_el0_s        cn88xx; */
	/* struct bdk_ap_pmceid0_el0_s        cn88xxp1; */
} bdk_ap_pmceid0_el0_t;

#define BDK_AP_PMCEID0_EL0 BDK_AP_PMCEID0_EL0_FUNC()
static inline uint64_t BDK_AP_PMCEID0_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCEID0_EL0_FUNC(void)
{
	return 0x00000303090C0600ull;
}
#define typedef_BDK_AP_PMCEID0_EL0 bdk_ap_pmceid0_el0_t
#define bustype_BDK_AP_PMCEID0_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCEID0_EL0 0
#define arguments_BDK_AP_PMCEID0_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCEID0_EL0 "AP_PMCEID0_EL0"


/**
 * SYSREG - ap_pmceid1_el0
 *
 * Reserved for future indication of which common architectural
 * and common microarchitectural feature events are implemented.
 */
typedef union bdk_ap_pmceid1_el0 {
	uint64_t u;
	struct bdk_ap_pmceid1_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ce                          : 64; /**< RO - Common architectural and microarchitectural feature events
                                                                     that can be counted by the PMU event counters.

                                                                 For the bit described in the following table, the event is
                                                                     implemented if the bit is set to 1, or not implemented if the
                                                                     bit is set to 0.

                                                                 \<pre\>
                                                                 Bit Event number    Event mnemonic
                                                                 0   0x020   L2D_CACHE_ALLOCATE
                                                                 \</pre\> */
#else
		uint64_t ce                          : 64;
#endif
	} s;
	/* struct bdk_ap_pmceid1_el0_s        cn88xx; */
	/* struct bdk_ap_pmceid1_el0_s        cn88xxp1; */
} bdk_ap_pmceid1_el0_t;

#define BDK_AP_PMCEID1_EL0 BDK_AP_PMCEID1_EL0_FUNC()
static inline uint64_t BDK_AP_PMCEID1_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCEID1_EL0_FUNC(void)
{
	return 0x00000303090C0700ull;
}
#define typedef_BDK_AP_PMCEID1_EL0 bdk_ap_pmceid1_el0_t
#define bustype_BDK_AP_PMCEID1_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCEID1_EL0 0
#define arguments_BDK_AP_PMCEID1_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCEID1_EL0 "AP_PMCEID1_EL0"


/**
 * SYSREG - ap_pmcntenclr_el0
 *
 * Disables the Cycle Count Register, AP_PMCCNTR_EL0, and any
 * implemented event counters PMEVCNTR\<x\>. Reading this register
 * shows which counters are enabled.
 */
typedef union bdk_ap_pmcntenclr_el0 {
	uint32_t u;
	struct bdk_ap_pmcntenclr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cc                          : 1;  /**< R/W - AP_PMCCNTR_EL0 disable bit. Disables the cycle counter register.
                                                                 0 = When read, means the cycle counter is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means the cycle counter is enabled. When written,
                                                                     disables the cycle counter. */
		uint32_t p                           : 31; /**< R/W - Event counter disable bit for PMEVCNTR\<x\>.
                                                                 Bits [30:N] are RAZ/WI.
                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in
                                                                     AP_PMCR_EL0[N].

                                                                 0 = When read, means that PMEVCNTR\<x\> is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means that PMEVCNTR\<x\> is enabled. When written,
                                                                     disables PMEVCNTR\<x\>. */
#else
		uint32_t p                           : 31;
		uint32_t cc                          : 1;
#endif
	} s;
	/* struct bdk_ap_pmcntenclr_el0_s     cn88xx; */
	/* struct bdk_ap_pmcntenclr_el0_s     cn88xxp1; */
} bdk_ap_pmcntenclr_el0_t;

#define BDK_AP_PMCNTENCLR_EL0 BDK_AP_PMCNTENCLR_EL0_FUNC()
static inline uint64_t BDK_AP_PMCNTENCLR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCNTENCLR_EL0_FUNC(void)
{
	return 0x00000303090C0200ull;
}
#define typedef_BDK_AP_PMCNTENCLR_EL0 bdk_ap_pmcntenclr_el0_t
#define bustype_BDK_AP_PMCNTENCLR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCNTENCLR_EL0 0
#define arguments_BDK_AP_PMCNTENCLR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCNTENCLR_EL0 "AP_PMCNTENCLR_EL0"


/**
 * SYSREG - ap_pmcntenset_el0
 *
 * Enables the Cycle Count Register, AP_PMCCNTR_EL0, and any
 * implemented event counters PMEVCNTR\<x\>. Reading this register
 * shows which counters are enabled.
 */
typedef union bdk_ap_pmcntenset_el0 {
	uint32_t u;
	struct bdk_ap_pmcntenset_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cc                          : 1;  /**< R/W - AP_PMCCNTR_EL0 enable bit. Enables the cycle counter register.
                                                                 0 = When read, means the cycle counter is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means the cycle counter is enabled. When written,
                                                                     enables the cycle counter. */
		uint32_t p                           : 31; /**< R/W - Event counter enable bit for PMEVCNTR\<x\>.
                                                                 Bits [30:N] are RAZ/WI.
                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in
                                                                     AP_PMCR_EL0[N].

                                                                 0 = When read, means that PMEVCNTR\<x\> is disabled. When written,
                                                                     has no effect.
                                                                 1 = When read, means that PMEVCNTR\<x\> event counter is enabled.
                                                                     When written, enables PMEVCNTR\<x\>. */
#else
		uint32_t p                           : 31;
		uint32_t cc                          : 1;
#endif
	} s;
	/* struct bdk_ap_pmcntenset_el0_s     cn88xx; */
	/* struct bdk_ap_pmcntenset_el0_s     cn88xxp1; */
} bdk_ap_pmcntenset_el0_t;

#define BDK_AP_PMCNTENSET_EL0 BDK_AP_PMCNTENSET_EL0_FUNC()
static inline uint64_t BDK_AP_PMCNTENSET_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCNTENSET_EL0_FUNC(void)
{
	return 0x00000303090C0100ull;
}
#define typedef_BDK_AP_PMCNTENSET_EL0 bdk_ap_pmcntenset_el0_t
#define bustype_BDK_AP_PMCNTENSET_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCNTENSET_EL0 0
#define arguments_BDK_AP_PMCNTENSET_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCNTENSET_EL0 "AP_PMCNTENSET_EL0"


/**
 * SYSREG - ap_pmcr_el0
 *
 * Provides details of the Performance Monitors implementation,
 * including the number of counters implemented, and configures
 * and controls the counters.
 */
typedef union bdk_ap_pmcr_el0 {
	uint32_t u;
	struct bdk_ap_pmcr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t imp                         : 8;  /**< RO - Implementer code. This field is RO with an implementation
                                                                     defined value.
                                                                 The implementer codes are allocated by ARM. Values have the
                                                                     same interpretation as bits [31:24] of the MIDR. */
		uint32_t idcode                      : 8;  /**< RO - Identification code. This field is RO with an implementation
                                                                     defined value.
                                                                 Each implementer must maintain a list of identification codes
                                                                     that is specific to the implementer. A specific implementation
                                                                     is identified by the combination of the implementer code and
                                                                     the identification code. */
		uint32_t n                           : 5;  /**< RO - Number of event counters. This field is RO with an
                                                                     implementation defined value that indicates the number of
                                                                     counters implemented.
                                                                 The value of this field is the number of counters implemented.

                                                                 An implementation can implement only the Cycle Count Register,
                                                                     AP_PMCCNTR_EL0. This is indicated by a value of0b00000

                                                                 CNXXXX has 6 counters. */
		uint32_t reserved_7_10               : 4;
		uint32_t lc                          : 1;  /**< RO - Long cycle counter enable. Determines which AP_PMCCNTR_EL0 bit
                                                                     generates an overflow recorded by PMOVSR[31].
                                                                 ARM deprecates use of AP_PMCR_EL0[LC] = 0.
                                                                 0 = Cycle counter overflow on increment that changes
                                                                     AP_PMCCNTR_EL0[31] from 1 to 0.
                                                                 1 = Cycle counter overflow on increment that changes
                                                                     AP_PMCCNTR_EL0[63] from 1 to 0.

                                                                 CNXXXX doesn't support 32 bit, so this bit is RAO / WI. */
		uint32_t dp                          : 1;  /**< R/W - Disable cycle counter when event counting is prohibited.
                                                                 Event counting is prohibited when
                                                                     ProfilingProhibited(IsSecure(),PSTATE[EL]) == TRUE.
                                                                 0 =  AP_PMCCNTR_EL0, if enabled, counts when event counting is
                                                                     prohibited.
                                                                 1 =  AP_PMCCNTR_EL0 does not count when event counting is prohibited. */
		uint32_t x                           : 1;  /**< RO - Enable export of events in an implementation defined event
                                                                     stream.
                                                                 This bit is used to permit events to be exported to another
                                                                     debug device, such as an OPTIONAL trace extension, over an
                                                                     event bus. If the implementation does not include such an
                                                                     event bus, this bit is RAZ/WI.

                                                                 This bit does not affect the generation of Performance
                                                                     Monitors overflow interrupt requests or signaling to a cross-
                                                                     trigger interface (CTI) that can be implemented as signals
                                                                     exported from the processor.

                                                                 If the implementation does not include an exported event
                                                                     stream, this bit is RAZ/WI. Otherwise this bit is RW.
                                                                 0 = Do not export events.
                                                                 1 = Export events where not prohibited.

                                                                 CNXXXX doesn't support export of events. */
		uint32_t dd                          : 1;  /**< RO - Clock divider.
                                                                 If AP_PMCR_EL0[LC] == 1, this bit is ignored and the cycle counter
                                                                     counts every clock cycle.
                                                                 ARM deprecates use of PMCR[D] = 1.
                                                                 0 = When enabled, AP_PMCCNTR_EL0 counts every clock cycle.
                                                                 1 = When enabled, AP_PMCCNTR_EL0 counts once every 64 clock cycles.

                                                                 CNXXXX doesn't support 32-bit, so this bit is RAZ / WI. */
		uint32_t cc                          : 1;  /**< R/W - Cycle counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 Resetting AP_PMCCNTR_EL0 does not clear the AP_PMCCNTR_EL0 overflow
                                                                     bit to 0.
                                                                 0 = No action.
                                                                 1 = Reset AP_PMCCNTR_EL0 to zero. */
		uint32_t p                           : 1;  /**< R/W - Event counter reset. This bit is WO. The effects of writing to
                                                                     this bit are:
                                                                 This bit is always RAZ.
                                                                 In non-secure EL0 and EL1, if EL2 is implemented, a write of 1
                                                                     to this bit does not reset event counters that AP_MDCR_EL2[HPMN]
                                                                     reserves for EL2 use.
                                                                 In EL2 and EL3, a write of 1 to this bit resets all the event
                                                                     counters.
                                                                 Resetting the event counters does not clear any overflow bits
                                                                     to 0.
                                                                 0 = No action.
                                                                 1 = Reset all event counters accessible in the current EL, not
                                                                     including AP_PMCCNTR_EL0, to zero. */
		uint32_t ee                          : 1;  /**< R/W - Enable.
                                                                 This bit is RW.
                                                                 In non-secure EL0 and EL1, if EL2 is implemented, this bit
                                                                     does not affect the operation of event counters that
                                                                     AP_MDCR_EL2[HPMN] reserves for EL2 use.
                                                                 0 = All counters, including AP_PMCCNTR_EL0, are disabled.
                                                                 1 = All counters are enabled by AP_PMCNTENSET_EL0. */
#else
		uint32_t ee                          : 1;
		uint32_t p                           : 1;
		uint32_t cc                          : 1;
		uint32_t dd                          : 1;
		uint32_t x                           : 1;
		uint32_t dp                          : 1;
		uint32_t lc                          : 1;
		uint32_t reserved_7_10               : 4;
		uint32_t n                           : 5;
		uint32_t idcode                      : 8;
		uint32_t imp                         : 8;
#endif
	} s;
	/* struct bdk_ap_pmcr_el0_s           cn88xx; */
	/* struct bdk_ap_pmcr_el0_s           cn88xxp1; */
} bdk_ap_pmcr_el0_t;

#define BDK_AP_PMCR_EL0 BDK_AP_PMCR_EL0_FUNC()
static inline uint64_t BDK_AP_PMCR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMCR_EL0_FUNC(void)
{
	return 0x00000303090C0000ull;
}
#define typedef_BDK_AP_PMCR_EL0 bdk_ap_pmcr_el0_t
#define bustype_BDK_AP_PMCR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMCR_EL0 0
#define arguments_BDK_AP_PMCR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMCR_EL0 "AP_PMCR_EL0"


/**
 * SYSREG - ap_pmevcntr#_el0
 *
 * Holds event counter n, which counts events, where n is 0 to
 * 30.
 */
typedef union bdk_ap_pmevcntrx_el0 {
	uint32_t u;
	struct bdk_ap_pmevcntrx_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Event counter n. Value of event counter n, where n is the
                                                                 number of this register and is a number from 0 to 30. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_pmevcntrx_el0_s      cn88xx; */
	/* struct bdk_ap_pmevcntrx_el0_s      cn88xxp1; */
} bdk_ap_pmevcntrx_el0_t;

static inline uint64_t BDK_AP_PMEVCNTRX_EL0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMEVCNTRX_EL0(unsigned long param1)
{
	if (((param1 <= 30)))
		return 0x000003030E080000ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_AP_PMEVCNTRX_EL0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_PMEVCNTRX_EL0(...) bdk_ap_pmevcntrx_el0_t
#define bustype_BDK_AP_PMEVCNTRX_EL0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMEVCNTRX_EL0(p1) (p1)
#define arguments_BDK_AP_PMEVCNTRX_EL0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_PMEVCNTRX_EL0(...) "AP_PMEVCNTRX_EL0"


/**
 * SYSREG - ap_pmevtyper#_el0
 *
 * Configures event counter n, where n is 0 to 30.
 *
 */
typedef union bdk_ap_pmevtyperx_el0 {
	uint32_t u;
	struct bdk_ap_pmevtyperx_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t p                           : 1;  /**< R/W - EL1 modes filtering bit. Controls counting in EL1. If EL3 is
                                                                     implemented, then counting in non-secure EL1 is further
                                                                     controlled by the NSK bit.
                                                                 0 = Count events in EL1.
                                                                 1 = Do not count events in EL1. */
		uint32_t u                           : 1;  /**< R/W - EL0 filtering bit. Controls counting in EL0. If EL3 is
                                                                     implemented, then counting in non-secure EL0 is further
                                                                     controlled by the NSU bit.
                                                                 0 = Count events in EL0.
                                                                 1 = Do not count events in EL0. */
		uint32_t nsk                         : 1;  /**< R/W - Non-secure kernel modes filtering bit. Controls counting in
                                                                     non-secure EL1. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     non-secure EL1 are counted.
                                                                 Otherwise, events in non-secure EL1 are not counted. */
		uint32_t nsu                         : 1;  /**< R/W - Non-secure user modes filtering bit. Controls counting in Non-
                                                                     secure EL0. If EL3 is not implemented, this bit is RES0.
                                                                 If the value of this bit is equal to the value of U, events in
                                                                     non-secure EL0 are counted.
                                                                 Otherwise, events in non-secure EL0 are not counted. */
		uint32_t nsh                         : 1;  /**< R/W - Non-secure Hyp modes filtering bit. Controls counting in Non-
                                                                     secure EL2. If EL2 is not implemented, this bit is RES0.
                                                                 0 = Do not count events in EL2.
                                                                 1 = Count events in EL2. */
		uint32_t m                           : 1;  /**< R/W - Secure EL3 filtering bit. Most applications can ignore this
                                                                     bit and set the value to zero. If EL3 is not implemented, this
                                                                     bit is RES0.
                                                                 If the value of this bit is equal to the value of P, events in
                                                                     Secure EL3 are counted.
                                                                 Otherwise, events in Secure EL3 are not counted. */
		uint32_t reserved_16_25              : 10;
		uint32_t evtcount                    : 16; /**< R/W - Event to count. The event number of the event that is counted
                                                                     by event counter PMEVCNTR\<n\>_EL0.
                                                                 Software must program this field with an event defined by the
                                                                     processor or a common event defined by the architecture.
                                                                 If evtCount is programmed to an event that is reserved or not
                                                                     implemented, the behavior depends on the event type.

                                                                 For common architectural and microarchitectural events:
                                                                  No events are counted.
                                                                  The value read back on evtCount is the value written.

                                                                 For implementation defined events:

                                                                  It is UNPREDICTABLE what event, if any, is counted.
                                                                     UNPREDICTABLE in this case means the event must not expose
                                                                     privileged information.

                                                                  The value read back on evtCount is an UNKNOWN value with the
                                                                     same effect.

                                                                 ARM recommends that the behavior across a family of
                                                                     implementations is defined such that if a given implementation
                                                                     does not include an event from a set of common implementation
                                                                     defined events, then no event is counted and the value read
                                                                     back on evtCount is the value written.

                                                                 v8.1: Width was extended to 16 bits. */
#else
		uint32_t evtcount                    : 16;
		uint32_t reserved_16_25              : 10;
		uint32_t m                           : 1;
		uint32_t nsh                         : 1;
		uint32_t nsu                         : 1;
		uint32_t nsk                         : 1;
		uint32_t u                           : 1;
		uint32_t p                           : 1;
#endif
	} s;
	/* struct bdk_ap_pmevtyperx_el0_s     cn88xx; */
	/* struct bdk_ap_pmevtyperx_el0_s     cn88xxp1; */
} bdk_ap_pmevtyperx_el0_t;

static inline uint64_t BDK_AP_PMEVTYPERX_EL0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMEVTYPERX_EL0(unsigned long param1)
{
	if (((param1 <= 30)))
		return 0x000003030E0C0000ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_AP_PMEVTYPERX_EL0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_PMEVTYPERX_EL0(...) bdk_ap_pmevtyperx_el0_t
#define bustype_BDK_AP_PMEVTYPERX_EL0(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMEVTYPERX_EL0(p1) (p1)
#define arguments_BDK_AP_PMEVTYPERX_EL0(p1) (p1),-1,-1,-1
#define basename_BDK_AP_PMEVTYPERX_EL0(...) "AP_PMEVTYPERX_EL0"


/**
 * SYSREG - ap_pmintenclr_el1
 *
 * Disables the generation of interrupt requests on overflows
 * from the Cycle Count Register, AP_PMCCNTR_EL0, and the event
 * counters PMEVCNTR\<n\>_EL0. Reading the register shows which
 * overflow interrupt requests are enabled.
 */
typedef union bdk_ap_pmintenclr_el1 {
	uint32_t u;
	struct bdk_ap_pmintenclr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cc                          : 1;  /**< R/W - AP_PMCCNTR_EL0 overflow interrupt request disable bit. Possible
                                                                     values are:
                                                                 0 = When read, means the cycle counter overflow interrupt request
                                                                     is disabled. When written, has no effect.
                                                                 1 = When read, means the cycle counter overflow interrupt request
                                                                     is enabled. When written, disables the cycle count overflow
                                                                     interrupt request. */
		uint32_t p                           : 31; /**< R/W - Event counter overflow interrupt request disable bit for
                                                                     PMEVCNTR\<x\>_EL0.
                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in
                                                                     AP_PMCR_EL0[N].
                                                                 Bits [30:N] are RAZ/WI.
                                                                 0 = When read, means that the PMEVCNTR\<x\>_EL0 event counter
                                                                     interrupt request is disabled. When written, has no effect.
                                                                 1 = When read, means that the PMEVCNTR\<x\>_EL0 event counter
                                                                     interrupt request is enabled. When written, disables the
                                                                     PMEVCNTR\<x\>_EL0 interrupt request. */
#else
		uint32_t p                           : 31;
		uint32_t cc                          : 1;
#endif
	} s;
	/* struct bdk_ap_pmintenclr_el1_s     cn88xx; */
	/* struct bdk_ap_pmintenclr_el1_s     cn88xxp1; */
} bdk_ap_pmintenclr_el1_t;

#define BDK_AP_PMINTENCLR_EL1 BDK_AP_PMINTENCLR_EL1_FUNC()
static inline uint64_t BDK_AP_PMINTENCLR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMINTENCLR_EL1_FUNC(void)
{
	return 0x00000300090E0200ull;
}
#define typedef_BDK_AP_PMINTENCLR_EL1 bdk_ap_pmintenclr_el1_t
#define bustype_BDK_AP_PMINTENCLR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMINTENCLR_EL1 0
#define arguments_BDK_AP_PMINTENCLR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_PMINTENCLR_EL1 "AP_PMINTENCLR_EL1"


/**
 * SYSREG - ap_pmintenset_el1
 *
 * Enables the generation of interrupt requests on overflows from
 * the Cycle Count Register, AP_PMCCNTR_EL0, and the event counters
 * PMEVCNTR\<n\>_EL0. Reading the register shows which overflow
 * interrupt requests are enabled.
 */
typedef union bdk_ap_pmintenset_el1 {
	uint32_t u;
	struct bdk_ap_pmintenset_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cc                          : 1;  /**< R/W - AP_PMCCNTR_EL0 overflow interrupt request enable bit. Possible
                                                                     values are:
                                                                 0 = When read, means the cycle counter overflow interrupt request
                                                                     is disabled. When written, has no effect.
                                                                 1 = When read, means the cycle counter overflow interrupt request
                                                                     is enabled. When written, enables the cycle count overflow
                                                                     interrupt request. */
		uint32_t p                           : 31; /**< R/W - Event counter overflow interrupt request enable bit for
                                                                     PMEVCNTR\<x\>_EL0.

                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in
                                                                     AP_PMCR_EL0[N].

                                                                 Bits [30:N] are RAZ/WI.

                                                                 0 = When read, means that the PMEVCNTR\<x\>_EL0 event counter
                                                                     interrupt request is disabled. When written, has no effect.
                                                                 1 = When read, means that the PMEVCNTR\<x\>_EL0 event counter
                                                                     interrupt request is enabled. When written, enables the
                                                                     PMEVCNTR\<x\>_EL0 interrupt request. */
#else
		uint32_t p                           : 31;
		uint32_t cc                          : 1;
#endif
	} s;
	/* struct bdk_ap_pmintenset_el1_s     cn88xx; */
	/* struct bdk_ap_pmintenset_el1_s     cn88xxp1; */
} bdk_ap_pmintenset_el1_t;

#define BDK_AP_PMINTENSET_EL1 BDK_AP_PMINTENSET_EL1_FUNC()
static inline uint64_t BDK_AP_PMINTENSET_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMINTENSET_EL1_FUNC(void)
{
	return 0x00000300090E0100ull;
}
#define typedef_BDK_AP_PMINTENSET_EL1 bdk_ap_pmintenset_el1_t
#define bustype_BDK_AP_PMINTENSET_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMINTENSET_EL1 0
#define arguments_BDK_AP_PMINTENSET_EL1 -1,-1,-1,-1
#define basename_BDK_AP_PMINTENSET_EL1 "AP_PMINTENSET_EL1"


/**
 * SYSREG - ap_pmovsclr_el0
 *
 * Contains the state of the overflow bit for the Cycle Count
 * Register, AP_PMCCNTR_EL0, and each of the implemented event
 * counters PMEVCNTR\<x\>. Writing to this register clears these
 * bits.
 */
typedef union bdk_ap_pmovsclr_el0 {
	uint32_t u;
	struct bdk_ap_pmovsclr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cc                          : 1;  /**< R/W - AP_PMCCNTR_EL0 overflow bit.
                                                                 AP_PMCR_EL0[LC] is used to control from which bit of AP_PMCCNTR_EL0
                                                                     (bit 31 or bit 63) an overflow is detected.
                                                                 0 = When read, means the cycle counter has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means the cycle counter has overflowed. When
                                                                     written, clears the overflow bit to 0. */
		uint32_t p                           : 31; /**< R/W - Event counter overflow clear bit for PMEVCNTR\<x\>.
                                                                 Bits [30:N] are RAZ/WI.
                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in
                                                                     AP_PMCR_EL0[N].

                                                                 0 = When read, means that PMEVCNTR\<x\> has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means that PMEVCNTR\<x\> has overflowed. When
                                                                     written, clears the PMEVCNTR\<x\> overflow bit to 0. */
#else
		uint32_t p                           : 31;
		uint32_t cc                          : 1;
#endif
	} s;
	/* struct bdk_ap_pmovsclr_el0_s       cn88xx; */
	/* struct bdk_ap_pmovsclr_el0_s       cn88xxp1; */
} bdk_ap_pmovsclr_el0_t;

#define BDK_AP_PMOVSCLR_EL0 BDK_AP_PMOVSCLR_EL0_FUNC()
static inline uint64_t BDK_AP_PMOVSCLR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMOVSCLR_EL0_FUNC(void)
{
	return 0x00000303090C0300ull;
}
#define typedef_BDK_AP_PMOVSCLR_EL0 bdk_ap_pmovsclr_el0_t
#define bustype_BDK_AP_PMOVSCLR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMOVSCLR_EL0 0
#define arguments_BDK_AP_PMOVSCLR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMOVSCLR_EL0 "AP_PMOVSCLR_EL0"


/**
 * SYSREG - ap_pmovsset_el0
 *
 * Sets the state of the overflow bit for the Cycle Count
 * Register, AP_PMCCNTR_EL0, and each of the implemented event
 * counters PMEVCNTR\<x\>.
 */
typedef union bdk_ap_pmovsset_el0 {
	uint32_t u;
	struct bdk_ap_pmovsset_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cc                          : 1;  /**< R/W - AP_PMCCNTR_EL0 overflow bit.
                                                                 0 = When read, means the cycle counter has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means the cycle counter has overflowed. When
                                                                     written, sets the overflow bit to 1. */
		uint32_t p                           : 31; /**< R/W - Event counter overflow set bit for PMEVCNTR\<x\>.
                                                                 Bits [30:N] are RAZ/WI.
                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in
                                                                     AP_PMCR_EL0[N].
                                                                 0 = When read, means that PMEVCNTR\<x\> has not overflowed. When
                                                                     written, has no effect.
                                                                 1 = When read, means that PMEVCNTR\<x\> has overflowed. When
                                                                     written, sets the PMEVCNTR\<x\> overflow bit to 1. */
#else
		uint32_t p                           : 31;
		uint32_t cc                          : 1;
#endif
	} s;
	/* struct bdk_ap_pmovsset_el0_s       cn88xx; */
	/* struct bdk_ap_pmovsset_el0_s       cn88xxp1; */
} bdk_ap_pmovsset_el0_t;

#define BDK_AP_PMOVSSET_EL0 BDK_AP_PMOVSSET_EL0_FUNC()
static inline uint64_t BDK_AP_PMOVSSET_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMOVSSET_EL0_FUNC(void)
{
	return 0x00000303090E0300ull;
}
#define typedef_BDK_AP_PMOVSSET_EL0 bdk_ap_pmovsset_el0_t
#define bustype_BDK_AP_PMOVSSET_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMOVSSET_EL0 0
#define arguments_BDK_AP_PMOVSSET_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMOVSSET_EL0 "AP_PMOVSSET_EL0"


/**
 * SYSREG - ap_pmselr_el0
 *
 * Selects the current event counter PMEVCNTR\<x\> or the cycle
 * counter, CCNT.
 */
typedef union bdk_ap_pmselr_el0 {
	uint32_t u;
	struct bdk_ap_pmselr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t sel                         : 5;  /**< R/W - Selects event counter, PMEVCNTR\<x\>, where x is the value held
                                                                     in this field. This value identifies which event counter is
                                                                     accessed when a subsequent access to AP_PMXEVTYPER_EL0 or
                                                                     AP_PMXEVCNTR_EL0 occurs.
                                                                 When AP_PMSELR_EL0[SEL] is 0b11111:

                                                                  A read of the AP_PMXEVTYPER_EL0 returns the value of
                                                                     AP_PMCCFILTR_EL0.

                                                                  A write of the AP_PMXEVTYPER_EL0 writes to AP_PMCCFILTR_EL0.

                                                                  A read or write of AP_PMXEVCNTR_EL0 has CONSTRAINED
                                                                     UNPREDICTABLE effects, that can be one of the following:
                                                                     Access to AP_PMXEVCNTR_EL0 is UNdefined.  Access to AP_PMXEVCNTR_EL0
                                                                     behaves as a NOP.  Access to AP_PMXEVCNTR_EL0 behaves as if the
                                                                     register is RAZ/WI.  Access to AP_PMXEVCNTR_EL0 behaves as if the
                                                                     AP_PMSELR_EL0[SEL]     field contains an UNKNOWN value.

                                                                 If this field is set to a value greater than or equal to the
                                                                     number of implemented counters, but not equal to 31, the
                                                                     results of access to AP_PMXEVTYPER_EL0 or AP_PMXEVCNTR_EL0 are
                                                                     CONSTRAINED UNPREDICTABLE, and can be one of the following:

                                                                  Access to AP_PMXEVTYPER_EL0 or AP_PMXEVCNTR_EL0 is UNdefined.

                                                                  Access to AP_PMXEVTYPER_EL0 or AP_PMXEVCNTR_EL0 behaves as a NOP.

                                                                  Access to AP_PMXEVTYPER_EL0 or AP_PMXEVCNTR_EL0 behaves as if the
                                                                     register is RAZ/WI.

                                                                  Access to AP_PMXEVTYPER_EL0 or AP_PMXEVCNTR_EL0 behaves as if the
                                                                     AP_PMSELR_EL0[SEL] field contains an UNKNOWN value.

                                                                  Access to AP_PMXEVTYPER_EL0 or AP_PMXEVCNTR_EL0 behaves as if the
                                                                     AP_PMSELR_EL0[SEL] field contains0b11111 */
#else
		uint32_t sel                         : 5;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	/* struct bdk_ap_pmselr_el0_s         cn88xx; */
	/* struct bdk_ap_pmselr_el0_s         cn88xxp1; */
} bdk_ap_pmselr_el0_t;

#define BDK_AP_PMSELR_EL0 BDK_AP_PMSELR_EL0_FUNC()
static inline uint64_t BDK_AP_PMSELR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMSELR_EL0_FUNC(void)
{
	return 0x00000303090C0500ull;
}
#define typedef_BDK_AP_PMSELR_EL0 bdk_ap_pmselr_el0_t
#define bustype_BDK_AP_PMSELR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMSELR_EL0 0
#define arguments_BDK_AP_PMSELR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMSELR_EL0 "AP_PMSELR_EL0"


/**
 * SYSREG - ap_pmswinc_el0
 *
 * Increments a counter that is configured to count the Software
 * increment event, event 0x0.
 */
typedef union bdk_ap_pmswinc_el0 {
	uint32_t u;
	struct bdk_ap_pmswinc_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t p                           : 31; /**< RO - Event counter software increment bit for PMEVCNTR\<x\>.
                                                                 Bits [30:N] are RAZ/WI.
                                                                 When EL2 is implemented, in non-secure EL1 and EL0, N is the
                                                                     value in AP_MDCR_EL2[HPMN]. Otherwise, N is the value in PMCR[N].
                                                                 The effects of writing to this bit are:
                                                                 0 = No action. The write to this bit is ignored.
                                                                 1 = If PMEVCNTR\<x\> is enabled and configured to count the software
                                                                     increment event, increments PMEVCNTR\<x\> by 1. If PMEVCNTR\<x\>
                                                                     is disabled, or not configured to count the software increment
                                                                     event, the write to this bit is ignored. */
#else
		uint32_t p                           : 31;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_ap_pmswinc_el0_s        cn88xx; */
	/* struct bdk_ap_pmswinc_el0_s        cn88xxp1; */
} bdk_ap_pmswinc_el0_t;

#define BDK_AP_PMSWINC_EL0 BDK_AP_PMSWINC_EL0_FUNC()
static inline uint64_t BDK_AP_PMSWINC_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMSWINC_EL0_FUNC(void)
{
	return 0x00000303090C0400ull;
}
#define typedef_BDK_AP_PMSWINC_EL0 bdk_ap_pmswinc_el0_t
#define bustype_BDK_AP_PMSWINC_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMSWINC_EL0 0
#define arguments_BDK_AP_PMSWINC_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMSWINC_EL0 "AP_PMSWINC_EL0"


/**
 * SYSREG - ap_pmuserenr_el0
 *
 * Enables or disables EL0 access to the Performance Monitors.
 *
 */
typedef union bdk_ap_pmuserenr_el0 {
	uint32_t u;
	struct bdk_ap_pmuserenr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t er                          : 1;  /**< R/W - Event counter read enable.
                                                                 0 = EL0 read access to AP_PMXEVCNTR_EL0 / PMEVCNTR\<n\>_EL0 and
                                                                     read/write access to AP_PMSELR_EL0 disabled if AP_PMUSERENR_EL0[EN]
                                                                     is also 0.
                                                                 1 = EL0 read access to AP_PMXEVCNTR_EL0 / PMEVCNTR\<n\>_EL0 and
                                                                     read/write access to AP_PMSELR_EL0 enabled. */
		uint32_t cr                          : 1;  /**< R/W - Cycle counter read enable.
                                                                 0 = EL0 read access to AP_PMCCNTR_EL0 disabled if AP_PMUSERENR_EL0[EN] is
                                                                     also 0.
                                                                 1 = EL0 read access to AP_PMCCNTR_EL0 enabled. */
		uint32_t sw                          : 1;  /**< R/W - Software Increment write enable.
                                                                 0 = EL0 write access to AP_PMSWINC_EL0 disabled if AP_PMUSERENR_EL0[EN]
                                                                     is also 0.
                                                                 1 = EL0 write access to AP_PMSWINC_EL0 enabled. */
		uint32_t en                          : 1;  /**< R/W - EL0 access enable bit.
                                                                 0 = EL0 access to the Performance Monitors disabled.
                                                                 1 = EL0 access to the Performance Monitors enabled. Can access all
                                                                     PMU registers at EL0, except for writes to AP_PMUSERENR_EL0 and
                                                                     reads/writes of AP_PMINTENSET_EL1 and AP_PMINTENCLR_EL1. */
#else
		uint32_t en                          : 1;
		uint32_t sw                          : 1;
		uint32_t cr                          : 1;
		uint32_t er                          : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_ap_pmuserenr_el0_s      cn88xx; */
	/* struct bdk_ap_pmuserenr_el0_s      cn88xxp1; */
} bdk_ap_pmuserenr_el0_t;

#define BDK_AP_PMUSERENR_EL0 BDK_AP_PMUSERENR_EL0_FUNC()
static inline uint64_t BDK_AP_PMUSERENR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMUSERENR_EL0_FUNC(void)
{
	return 0x00000303090E0000ull;
}
#define typedef_BDK_AP_PMUSERENR_EL0 bdk_ap_pmuserenr_el0_t
#define bustype_BDK_AP_PMUSERENR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMUSERENR_EL0 0
#define arguments_BDK_AP_PMUSERENR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMUSERENR_EL0 "AP_PMUSERENR_EL0"


/**
 * SYSREG - ap_pmxevcntr_el0
 *
 * Reads or writes the value of the selected event counter,
 * PMEVCNTR\<x\>_EL0. AP_PMSELR_EL0[SEL] determines which event counter
 * is selected.
 */
typedef union bdk_ap_pmxevcntr_el0 {
	uint32_t u;
	struct bdk_ap_pmxevcntr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pmevcntr                    : 32; /**< R/W - Value of the selected event counter, PMEVCNTR\<x\>_EL0, where x
                                                                 is the value stored in AP_PMSELR_EL0[SEL]. */
#else
		uint32_t pmevcntr                    : 32;
#endif
	} s;
	/* struct bdk_ap_pmxevcntr_el0_s      cn88xx; */
	/* struct bdk_ap_pmxevcntr_el0_s      cn88xxp1; */
} bdk_ap_pmxevcntr_el0_t;

#define BDK_AP_PMXEVCNTR_EL0 BDK_AP_PMXEVCNTR_EL0_FUNC()
static inline uint64_t BDK_AP_PMXEVCNTR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMXEVCNTR_EL0_FUNC(void)
{
	return 0x00000303090D0200ull;
}
#define typedef_BDK_AP_PMXEVCNTR_EL0 bdk_ap_pmxevcntr_el0_t
#define bustype_BDK_AP_PMXEVCNTR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMXEVCNTR_EL0 0
#define arguments_BDK_AP_PMXEVCNTR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMXEVCNTR_EL0 "AP_PMXEVCNTR_EL0"


/**
 * SYSREG - ap_pmxevtyper_el0
 *
 * When AP_PMSELR_EL0[SEL] selects an event counter, this accesses a
 * PMEVTYPER\<n\>_EL0 register. When AP_PMSELR_EL0[SEL] selects the
 * cycle counter, this accesses AP_PMCCFILTR_EL0.
 */
typedef union bdk_ap_pmxevtyper_el0 {
	uint32_t u;
	struct bdk_ap_pmxevtyper_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Event type register or AP_PMCCFILTR_EL0.
                                                                 When AP_PMSELR_EL0[SEL] == 31, this register accesses
                                                                     AP_PMCCFILTR_EL0.
                                                                 Otherwise, this register accesses PMEVTYPER\<n\>_EL0 where n is
                                                                     the value in AP_PMSELR_EL0[SEL]. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ap_pmxevtyper_el0_s     cn88xx; */
	/* struct bdk_ap_pmxevtyper_el0_s     cn88xxp1; */
} bdk_ap_pmxevtyper_el0_t;

#define BDK_AP_PMXEVTYPER_EL0 BDK_AP_PMXEVTYPER_EL0_FUNC()
static inline uint64_t BDK_AP_PMXEVTYPER_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_PMXEVTYPER_EL0_FUNC(void)
{
	return 0x00000303090D0100ull;
}
#define typedef_BDK_AP_PMXEVTYPER_EL0 bdk_ap_pmxevtyper_el0_t
#define bustype_BDK_AP_PMXEVTYPER_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_PMXEVTYPER_EL0 0
#define arguments_BDK_AP_PMXEVTYPER_EL0 -1,-1,-1,-1
#define basename_BDK_AP_PMXEVTYPER_EL0 "AP_PMXEVTYPER_EL0"


/**
 * SYSREG - ap_revidr_el1
 *
 * This register provides implementation-specific minor revision information
 * that can only be interpreted in conjunction with AP_MIDR_EL1.
 */
typedef union bdk_ap_revidr_el1 {
	uint32_t u;
	struct bdk_ap_revidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_revidr_el1_s         cn88xx; */
	/* struct bdk_ap_revidr_el1_s         cn88xxp1; */
} bdk_ap_revidr_el1_t;

#define BDK_AP_REVIDR_EL1 BDK_AP_REVIDR_EL1_FUNC()
static inline uint64_t BDK_AP_REVIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_REVIDR_EL1_FUNC(void)
{
	return 0x0000030000000600ull;
}
#define typedef_BDK_AP_REVIDR_EL1 bdk_ap_revidr_el1_t
#define bustype_BDK_AP_REVIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_REVIDR_EL1 0
#define arguments_BDK_AP_REVIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_REVIDR_EL1 "AP_REVIDR_EL1"


/**
 * SYSREG - ap_rmr_el#
 *
 * Reset control for EL1 or EL2. Doesn't exists since EL3 exists.
 *
 */
typedef union bdk_ap_rmr_elx {
	uint32_t u;
	struct bdk_ap_rmr_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_rmr_elx_s            cn88xx; */
	/* struct bdk_ap_rmr_elx_s            cn88xxp1; */
} bdk_ap_rmr_elx_t;

static inline uint64_t BDK_AP_RMR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_RMR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 2))))
		return 0x000003000C000200ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_RMR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_RMR_ELX(...) bdk_ap_rmr_elx_t
#define bustype_BDK_AP_RMR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_RMR_ELX(p1) (p1)
#define arguments_BDK_AP_RMR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_RMR_ELX(...) "AP_RMR_ELX"


/**
 * SYSREG - ap_rmr_el3
 *
 * If EL3 is the highest Exception level implemented, and is
 *     capable of using both AArch32 and AArch64, controls the
 *     Execution state that the processor boots into and allows
 *     request of a Warm reset.
 *
 * Not implemented on CNXXXX - no 32 bit support.
 */
typedef union bdk_ap_rmr_el3 {
	uint32_t u;
	struct bdk_ap_rmr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t rr                          : 1;  /**< R/W - When set to 1 this bit requests a Warm reset. The bit is
                                                                 strictly a request. */
		uint32_t aa64                        : 1;  /**< R/W - Determines which Execution state the processor boots into
                                                                     after a Warm reset:
                                                                 The reset vector address on reset takes a choice between two
                                                                     IMP DEF values, depending on the value in the AA64 bit.
                                                                 0 = AArch32.
                                                                 1 = AArch64. */
#else
		uint32_t aa64                        : 1;
		uint32_t rr                          : 1;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_ap_rmr_el3_s            cn88xx; */
	/* struct bdk_ap_rmr_el3_s            cn88xxp1; */
} bdk_ap_rmr_el3_t;

#define BDK_AP_RMR_EL3 BDK_AP_RMR_EL3_FUNC()
static inline uint64_t BDK_AP_RMR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_RMR_EL3_FUNC(void)
{
	return 0x000003060C000200ull;
}
#define typedef_BDK_AP_RMR_EL3 bdk_ap_rmr_el3_t
#define bustype_BDK_AP_RMR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_RMR_EL3 0
#define arguments_BDK_AP_RMR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_RMR_EL3 "AP_RMR_EL3"


/**
 * SYSREG - ap_rvbar_el#
 *
 * Reset vector for EL1 or EL2. Doesn't exists since EL3 exists.
 *
 */
typedef union bdk_ap_rvbar_elx {
	uint64_t u;
	struct bdk_ap_rvbar_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_rvbar_elx_s          cn88xx; */
	/* struct bdk_ap_rvbar_elx_s          cn88xxp1; */
} bdk_ap_rvbar_elx_t;

static inline uint64_t BDK_AP_RVBAR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_RVBAR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 2))))
		return 0x000003000C000100ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_RVBAR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_RVBAR_ELX(...) bdk_ap_rvbar_elx_t
#define bustype_BDK_AP_RVBAR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_RVBAR_ELX(p1) (p1)
#define arguments_BDK_AP_RVBAR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_RVBAR_ELX(...) "AP_RVBAR_ELX"


/**
 * SYSREG - ap_rvbar_el3
 *
 * If EL3 is the highest exception level implemented, contains
 * the implementation defined address that execution starts from
 * after reset when executing in AArch64 state.
 */
typedef union bdk_ap_rvbar_el3 {
	uint64_t u;
	struct bdk_ap_rvbar_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO - Reset Vector Base Address. If this Exception level is the
                                                                     highest one implemented, this field contains the
                                                                     implementation defined address that execution starts from
                                                                     after reset when executing in 64-bit state. Bits[1:0] of this
                                                                     register are 00, as this address must be aligned, and the
                                                                     address must be within the physical address size supported by
                                                                     the processor.

                                                                 If this Exception level is not the highest one implemented,
                                                                     then this register is not implemented and its encoding is
                                                                     UNdefined. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_rvbar_el3_s          cn88xx; */
	/* struct bdk_ap_rvbar_el3_s          cn88xxp1; */
} bdk_ap_rvbar_el3_t;

#define BDK_AP_RVBAR_EL3 BDK_AP_RVBAR_EL3_FUNC()
static inline uint64_t BDK_AP_RVBAR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_RVBAR_EL3_FUNC(void)
{
	return 0x000003060C000100ull;
}
#define typedef_BDK_AP_RVBAR_EL3 bdk_ap_rvbar_el3_t
#define bustype_BDK_AP_RVBAR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_RVBAR_EL3 0
#define arguments_BDK_AP_RVBAR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_RVBAR_EL3 "AP_RVBAR_EL3"


/**
 * SYSREG - ap_scr_el3
 *
 * Defines the configuration of the current Security state. It
 *    specifies:
 * The Security state of EL0 and EL1, either Secure or Non-
 *    secure.
 * The Execution state at lower Exception levels.
 * Whether IRQ, FIQ, and External Abort interrupts are taken to
 *    EL3.
 */
typedef union bdk_ap_scr_el3 {
	uint32_t u;
	struct bdk_ap_scr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_15_31              : 17;
		uint32_t tlor                        : 1;  /**< R/W - v8.1: Trap access to the LOR
                                                                 Registers from EL1 and EL2 to EL3, unless the access has been
                                                                 trapped to EL2:
                                                                 0: EL1 and EL2 accesses to the LOR Registers are not trapped to EL3
                                                                 1: EL1 and EL2 accesses to the LOR Registers are trapped to EL3
                                                                     unless the access has been trapped to EL2 as a result of the
                                                                     AP_HCR_EL2[TLOR]. */
		uint32_t twe                         : 1;  /**< R/W - Trap WFE.
                                                                 0 = WFE instructions not trapped.
                                                                 1 = WFE instructions executed in AArch32 or AArch64 at EL2, EL1,
                                                                     or EL0 are trapped to EL3 if the instruction would otherwise
                                                                     cause suspension of execution, i.e. if there is not a pending
                                                                     WFI wakeup event and the instruciton does not cause another
                                                                     exception. */
		uint32_t twi                         : 1;  /**< R/W - Trap WFI.
                                                                 0 = WFI instructions not trapped.
                                                                 1 = WFI instructions executed in AArch32 or AArch64 at EL2, EL1,
                                                                     or EL0 are trapped to EL3 if the instruction would otherwise
                                                                     cause suspension of execution. */
		uint32_t st                          : 1;  /**< R/W - Enables Secure EL1 access to the AP_CNTPS_TVAL_EL1,
                                                                     AP_CNTPS_CTL_EL1, and AP_CNTPS_CVAL_EL1 registers.

                                                                 If this bit is 0 and there is a Secure EL1 access to one of
                                                                     the CNTPS registers:
                                                                  An exception is taken to EL3.
                                                                  The exception class for this exception, as returned in
                                                                     ESR_EL3[EC], is 0x18
                                                                 0 = These registers are only accessible in EL3.
                                                                 1 = These registers are accessible in EL3 and also in EL1 when
                                                                     AP_SCR_EL3[NS]==0. */
		uint32_t rsvd_10                     : 1;  /**< RO - Execution state control for lower Exception levels.
                                                                 This bit is permitted to be cached in a TLB.
                                                                 0 = Lower levels are all AArch32.
                                                                 1 = The next lower level is AArch64.

                                                                 If EL2 is present:
                                                                  EL2 is AArch64.
                                                                  EL2 controls EL1 and EL0 behaviors.

                                                                 If EL2 is not present:
                                                                  EL1 is AArch64.
                                                                  EL0 is determined by the Execution state described in the
                                                                     current process state when executing at EL0. */
		uint32_t sif                         : 1;  /**< R/W - Secure instruction fetch. When the processor is in Secure
                                                                     state, this bit disables instruction fetch from non-secure
                                                                     memory.
                                                                 This bit is permitted to be cached in a TLB.
                                                                 0 = Secure state instruction fetches from non-secure memory are
                                                                     permitted.
                                                                 1 = Secure state instruction fetches from non-secure memory are
                                                                     not permitted. */
		uint32_t hce                         : 1;  /**< R/W - Hypervisor Call enable. This bit enables use of the HVC
                                                                     instruction from non-secure EL1 modes.

                                                                 If EL3 is implemented but EL2 is not implemented, this bit is
                                                                     RES0.
                                                                 0 = HVC instruction is UNdefined in non-secure EL1 modes, and
                                                                     either UNdefined or a NOP in Hyp mode, depending on the
                                                                     implementation.
                                                                 1 = HVC instruction is enabled in non-secure EL1 modes, and
                                                                     performs a Hypervisor Call. */
		uint32_t smd                         : 1;  /**< R/W - SMC Disable.
                                                                 0 = SMC is enabled at EL1, EL2, or EL3.
                                                                 1 = SMC is UNdefined at all Exception levels. At EL1 in the Non-
                                                                     secure state, the AP_HCR_EL2[TSC] bit has priority over this
                                                                     control. */
		uint32_t reserved_6_6                : 1;
		uint32_t rsvd_4_5                    : 2;  /**< RO - Reserved 1. */
		uint32_t ea                          : 1;  /**< R/W - External Abort and SError Interrupt Routing.
                                                                 0 = External Aborts and SError Interrupts while executing at
                                                                     exception levels other than EL3 are not taken in EL3.
                                                                 1 = External Aborts and SError Interrupts while executing at all
                                                                     exception levels are taken in EL3. */
		uint32_t fiq                         : 1;  /**< R/W - Physical FIQ Routing.
                                                                 0 = Physical FIQ while executing at exception levels other than
                                                                     EL3 are not taken in EL3.
                                                                 1 = Physical FIQ while executing at all exception levels are taken
                                                                     in EL3. */
		uint32_t irq                         : 1;  /**< R/W - Physical IRQ Routing.
                                                                 0 = Physical IRQ while executing at exception levels other than
                                                                     EL3 are not taken in EL3.
                                                                 1 = Physical IRQ while executing at all exception levels are taken
                                                                     in EL3. */
		uint32_t nsec                        : 1;  /**< R/W - Non-secure bit.
                                                                 0 = Indicates that EL0 and EL1 are in Secure state, and so memory
                                                                     accesses from those Exception levels can access Secure memory.
                                                                 1 = Indicates that EL0 and EL1 are in non-secure state, and so
                                                                     memory accesses from those Exception levels cannot access
                                                                     Secure memory. */
#else
		uint32_t nsec                        : 1;
		uint32_t irq                         : 1;
		uint32_t fiq                         : 1;
		uint32_t ea                          : 1;
		uint32_t rsvd_4_5                    : 2;
		uint32_t reserved_6_6                : 1;
		uint32_t smd                         : 1;
		uint32_t hce                         : 1;
		uint32_t sif                         : 1;
		uint32_t rsvd_10                     : 1;
		uint32_t st                          : 1;
		uint32_t twi                         : 1;
		uint32_t twe                         : 1;
		uint32_t tlor                        : 1;
		uint32_t reserved_15_31              : 17;
#endif
	} s;
	/* struct bdk_ap_scr_el3_s            cn88xx; */
	/* struct bdk_ap_scr_el3_s            cn88xxp1; */
} bdk_ap_scr_el3_t;

#define BDK_AP_SCR_EL3 BDK_AP_SCR_EL3_FUNC()
static inline uint64_t BDK_AP_SCR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SCR_EL3_FUNC(void)
{
	return 0x0000030601010000ull;
}
#define typedef_BDK_AP_SCR_EL3 bdk_ap_scr_el3_t
#define bustype_BDK_AP_SCR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SCR_EL3 0
#define arguments_BDK_AP_SCR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_SCR_EL3 "AP_SCR_EL3"


/**
 * SYSREG - ap_sctlr_el1
 *
 * Provides top level control of the system, including its memory
 * system, at EL1.
 */
typedef union bdk_ap_sctlr_el1 {
	uint32_t u;
	struct bdk_ap_sctlr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t rsvd_28_29                  : 2;  /**< RO - Reserved 1. */
		uint32_t reserved_27_27              : 1;
		uint32_t uci                         : 1;  /**< R/W - When set, enables EL0 access in AArch64 for DC CVAU, DC CIVAC,
                                                                 DC CVAC, and IC IVAU instructions. */
		uint32_t ee                          : 1;  /**< R/W - Exception Endianness. This bit controls the endianness for:
                                                                  Explicit data accesses at EL1.
                                                                  Stage 1 translation table walks at EL1 and EL0.

                                                                 If an implementation does not provide Big-endian support, this
                                                                     bit is RES0. If it does not provide Little-endian support,
                                                                     this bit is RES1.
                                                                 The EE bit is permitted to be cached in a TLB.
                                                                 0 = Little-endian.
                                                                 1 = Big-endian. */
		uint32_t e0e                         : 1;  /**< R/W - Endianness of explicit data accesses at EL0.

                                                                 If an implementation only supports Little-endian accesses at
                                                                     EL0 then this bit is RES0.
                                                                 If an implementation only supports Big-endian accesses at EL0
                                                                     then this bit is RES1.
                                                                 This bit has no effect on the endianness of LDTR* and STTR*
                                                                     instructions executed at EL1.
                                                                 0 = Explicit data accesses at EL0 are little-endian.
                                                                 1 = Explicit data accesses at EL0 are big-endian. */
		uint32_t span                        : 1;  /**< R/W - v8.1: Bit[23]: SPAN set PSTATE/CPSR[AP_PAN] bit on taking an exception
                                                                 to the EL1 exception level.
                                                                 0 = PSTATE/CPSR[AP_PAN] is set on taking an exception to the EL1 exception level.
                                                                 1 = PSTATE/CPSR[AP_PAN] is left unchanged on taking an exception to the EL1 exception
                                                                 level.

                                                                 This bit has no effect on the PSTATE/CPSR[AP_PAN] when taking exceptions to any other
                                                                 exception level. */
		uint32_t rsvd_22                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_21_21              : 1;
		uint32_t rsvd_20                     : 1;  /**< RO - Reserved 1. */
		uint32_t wxn                         : 1;  /**< R/W - Write permission implies XN (Execute Never). This bit can be
                                                                     used to require all memory regions with write permission to be
                                                                     treated as XN.
                                                                 The WXN bit is permitted to be cached in a TLB.
                                                                 0 = Regions with write permission are not forced to XN.
                                                                 1 = Regions with write permission are forced to XN. */
		uint32_t ntwe                        : 1;  /**< R/W - Not trap WFE.
                                                                 Conditional WFE instructions that fail their condition do not
                                                                     cause an exception if this bit is 0.
                                                                 0 = If a WFE instruction executed at EL0 would cause execution to
                                                                     be suspended, such as if the event register is not set and
                                                                     there is not a pending WFE wakeup event, it is taken as an
                                                                     exception to EL1 using the0x1
                                                                 1 = WFE instructions are executed as normal. */
		uint32_t reserved_17_17              : 1;
		uint32_t ntwi                        : 1;  /**< R/W - Not trap WFI.
                                                                 Conditional WFI instructions that fail their condition do not
                                                                     cause an exception if this bit is 0.
                                                                 0 = If a WFI instruction executed at EL0 would cause execution to
                                                                     be suspended, such as if there is not a pending WFI wakeup
                                                                     event, it is taken as an exception to EL1 using the0x1
                                                                 1 = WFI instructions are executed as normal. */
		uint32_t uct                         : 1;  /**< R/W - When set, enables EL0 access in AArch64 to the AP_CTR_EL0
                                                                 register. */
		uint32_t dze                         : 1;  /**< R/W - Access to DC ZVA instruction at EL0.
                                                                 0 = Execution of the DC ZVA instruction is prohibited at EL0, and
                                                                     it is treated as UNdefined at EL0.
                                                                 1 = Execution of the DC ZVA instruction is allowed at EL0. */
		uint32_t reserved_13_13              : 1;
		uint32_t i                           : 1;  /**< R/W - Instruction cache enable. This is an enable bit for
                                                                     instruction caches at EL0 and EL1:
                                                                 When this bit is 0, all EL1 and EL0 Normal memory instruction
                                                                     accesses are Non-cacheable.
                                                                 If the AP_HCR_EL2[DC] bit is set to 1, then the non-secure stage 1
                                                                     EL1&0 translation regime is Cacheable regardless of the value
                                                                     of this bit.
                                                                 0 = Instruction caches disabled at EL0 and EL1. If AP_SCTLR_EL1[M] is
                                                                     set to 0, instruction accesses from stage 1 of the EL1&0
                                                                     translation regime are to Normal memory, Outer Shareable,
                                                                     Inner Non-cacheable, Outer Non-cacheable.
                                                                 1 = Instruction caches enabled at EL0 and EL1. If AP_SCTLR_EL1[M] is
                                                                     set to 0, instruction accesses from stage 1 of the EL1&0
                                                                     translation regime are to Normal memory, Outer Shareable,
                                                                     Inner Write-Through, Outer Write-Through. */
		uint32_t rsvd_11                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_10_10              : 1;
		uint32_t uma                         : 1;  /**< R/W - User Mask Access. Controls access to interrupt masks from EL0,
                                                                     when EL0 is using AArch64.
                                                                 0 = Disable access to the interrupt masks from EL0.
                                                                 1 = Enable access to the interrupt masks from EL0. */
		uint32_t rsvd_8                      : 1;  /**< RO - SETEND Disable.
                                                                 If an implementation does not support mixed endian operation,
                                                                     this bit is RES1.
                                                                 0 = The SETEND instruction is available.
                                                                 1 = The SETEND instruction is UNALLOCATED.

                                                                 SED: SETEND Disable - Only supported with 32 bit. */
		uint32_t rsvd_7                      : 1;  /**< RO - "IT Disable.
                                                                 0 = The IT instruction functionality is available.
                                                                 1 = It is implementation defined whether the IT instruction is
                                                                     treated as either:

                                                                  A 16-bit instruction, which can only be followed by another
                                                                     16-bit instruction.

                                                                  The first half of a 32-bit instruction.

                                                                 An implementation might vary dynamically as to whether IT is
                                                                     treated as a 16-bit instruction or the first half of a 32-bit
                                                                     instruction.
                                                                 All encodings of the IT instruction with hw1[3:0]!=1000 are
                                                                     UNdefined and treated as unallocated.
                                                                 All encodings of the subsequent instruction with the following
                                                                     values for hw1 are UNdefined (and treated as unallocated):

                                                                 - 0b11xxxxxxxxxxxxxx: All 32-bit instructions, and the 16-bit
                                                                     instructions B, UDF, SVC, LDM, and STM.
                                                                 - 0b1x11xxxxxxxxxxxx: All instructions in.
                                                                 - 0b1x100xxxxxxxxxxx: ADD Rd, PC, \#imm
                                                                 - 0b01001xxxxxxxxxxx: LDR Rd, [PC, \#imm]
                                                                 - 0b0100x1xxx1111xxx: ADD Rdn, PC; CMP Rn, PC; MOV Rd, PC; BX
                                                                     PC; BLX PC.
                                                                 - 0b010001xx1xxxx111: ADD PC, Rm; CMP PC, Rm; MOV PC, Rm. This
                                                                     pattern also covers UNPREDICTABLE cases with BLX Rn.

                                                                 Contrary to the standard treatment of conditional UNdefined
                                                                     instructions in the ARM architecture, in this case these
                                                                     instructions are always treated as UNdefined, regardless of
                                                                     whether the instruction would pass or fail its condition codes
                                                                     as a result of being in an IT block.

                                                                 ITD: IT Disable - Only supported with 32 bit." */
		uint32_t reserved_5_6                : 2;
		uint32_t sa0                         : 1;  /**< R/W - Stack Alignment Check Enable for EL0. When set, use of the
                                                                 stack pointer as the base address in a load/store instruction
                                                                 at EL0 must be aligned to a 16-byte boundary, or a Stack
                                                                 Alignment Fault exception will be raised. */
		uint32_t sa                          : 1;  /**< R/W - Stack Alignment Check Enable. When set, use of the stack
                                                                 pointer as the base address in a load/store instruction at
                                                                 this register's Exception level must be aligned to a 16-byte
                                                                 boundary, or a Stack Alignment Fault exception will be raised. */
		uint32_t cc                          : 1;  /**< R/W - Cache enable. This is an enable bit for data and unified
                                                                     caches at EL0 and EL1:
                                                                 When this bit is 0, all EL0 and EL1 Normal memory data
                                                                     accesses and all accesses to the EL1&0 stage 1 translation
                                                                     tables are Non-cacheable.
                                                                 If the AP_HCR_EL2[DC] bit is set to 1, then the non-secure stage 1
                                                                     EL1&0 translation regime is Cacheable regardless of the value
                                                                     of the AP_SCTLR_EL1[C] bit.
                                                                 0 = Data and unified caches disabled.
                                                                 1 = Data and unified caches enabled. */
		uint32_t aa                          : 1;  /**< R/W - Alignment check enable. This is the enable bit for Alignment
                                                                     fault checking:
                                                                 Load/store exclusive and load-acquire/store-release
                                                                     instructions have an alignment check regardless of the value
                                                                     of the A bit.
                                                                 0 = Alignment fault checking disabled.
                                                                 Instructions that load or store one or more registers, other
                                                                     than load/store exclusive and load-acquire/store-release, do
                                                                     not check that the address being accessed is aligned to the
                                                                     size of the data element(s) being accessed.
                                                                 1 = Alignment fault checking enabled.
                                                                 All instructions that load or store one or more registers have
                                                                     an alignment check that the address being accessed is aligned
                                                                     to the size of the data element(s) being accessed. If this
                                                                     check fails it causes an Alignment fault, which is taken as a
                                                                     Data Abort exception. */
		uint32_t m                           : 1;  /**< R/W - MMU enable for EL1 and EL0 stage 1 address translation.

                                                                 If AP_HCR_EL2[DC] is set to 1, then in non-secure state the
                                                                     AP_SCTLR_EL1[M] bit behaves as 0 for all purposes other than
                                                                     reading the value of the bit.
                                                                 0 = EL1 and EL0 stage 1 address translation disabled.
                                                                 1 = EL1 and EL0 stage 1 address translation enabled. */
#else
		uint32_t m                           : 1;
		uint32_t aa                          : 1;
		uint32_t cc                          : 1;
		uint32_t sa                          : 1;
		uint32_t sa0                         : 1;
		uint32_t reserved_5_6                : 2;
		uint32_t rsvd_7                      : 1;
		uint32_t rsvd_8                      : 1;
		uint32_t uma                         : 1;
		uint32_t reserved_10_10              : 1;
		uint32_t rsvd_11                     : 1;
		uint32_t i                           : 1;
		uint32_t reserved_13_13              : 1;
		uint32_t dze                         : 1;
		uint32_t uct                         : 1;
		uint32_t ntwi                        : 1;
		uint32_t reserved_17_17              : 1;
		uint32_t ntwe                        : 1;
		uint32_t wxn                         : 1;
		uint32_t rsvd_20                     : 1;
		uint32_t reserved_21_21              : 1;
		uint32_t rsvd_22                     : 1;
		uint32_t span                        : 1;
		uint32_t e0e                         : 1;
		uint32_t ee                          : 1;
		uint32_t uci                         : 1;
		uint32_t reserved_27_27              : 1;
		uint32_t rsvd_28_29                  : 2;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_ap_sctlr_el1_s          cn88xx; */
	/* struct bdk_ap_sctlr_el1_s          cn88xxp1; */
} bdk_ap_sctlr_el1_t;

#define BDK_AP_SCTLR_EL1 BDK_AP_SCTLR_EL1_FUNC()
static inline uint64_t BDK_AP_SCTLR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SCTLR_EL1_FUNC(void)
{
	return 0x0000030001000000ull;
}
#define typedef_BDK_AP_SCTLR_EL1 bdk_ap_sctlr_el1_t
#define bustype_BDK_AP_SCTLR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SCTLR_EL1 0
#define arguments_BDK_AP_SCTLR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_SCTLR_EL1 "AP_SCTLR_EL1"


/**
 * SYSREG - ap_sctlr_el12
 *
 * Alias to allow access to AP_SCTLR_EL1 from EL2 when AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_sctlr_el12 {
	uint32_t u;
	struct bdk_ap_sctlr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_sctlr_el12_s         cn88xx; */
	/* struct bdk_ap_sctlr_el12_s         cn88xxp1; */
} bdk_ap_sctlr_el12_t;

#define BDK_AP_SCTLR_EL12 BDK_AP_SCTLR_EL12_FUNC()
static inline uint64_t BDK_AP_SCTLR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SCTLR_EL12_FUNC(void)
{
	return 0x0000030501000000ull;
}
#define typedef_BDK_AP_SCTLR_EL12 bdk_ap_sctlr_el12_t
#define bustype_BDK_AP_SCTLR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SCTLR_EL12 0
#define arguments_BDK_AP_SCTLR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_SCTLR_EL12 "AP_SCTLR_EL12"


/**
 * SYSREG - ap_sctlr_el2
 *
 * Provides top level control of the system, including its memory
 *     system, at EL2.
 *
 * This register is at the same select as AP_SCTLR_EL2_E2H and is used when E2H=0.
 */
typedef union bdk_ap_sctlr_el2 {
	uint32_t u;
	struct bdk_ap_sctlr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t rsvd_28_29                  : 2;  /**< RO - Reserved 1. */
		uint32_t reserved_26_27              : 2;
		uint32_t ee                          : 1;  /**< R/W - Exception Endianness. This bit controls the endianness for:
                                                                  Explicit data accesses at EL3.
                                                                  Stage 1 translation table walks at EL3.

                                                                 If an implementation does not provide Big-endian support, this
                                                                     bit is RES0. If it does not provide Little-endian support,
                                                                     this bit is RES1.
                                                                 The EE bit is permitted to be cached in a TLB.
                                                                 0 = Little-endian.
                                                                 1 = Big-endian. */
		uint32_t reserved_24_24              : 1;
		uint32_t span                        : 1;  /**< R/W - v8.1: Bit[23]: SPAN set PSTATE/CPSR[AP_PAN] bit on taking an exception
                                                                 to the EL* exception level.
                                                                 0: PSTATE/CPSR[AP_PAN] is set on taking an exception to the EL* exception level
                                                                 1: PSTATE/CPSR[AP_PAN] is left unchanged on taking an exception to the EL* exception level

                                                                 This bit has no effect on the PSTATE/CPSR[AP_PAN] when taking exceptions to any other
                                                                 exception level. */
		uint32_t rsvd_22                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_20_21              : 2;
		uint32_t wxn                         : 1;  /**< R/W - Write permission implies XN (Execute Never). This bit can be
                                                                     used to require all memory regions with write permission to be
                                                                     treated as XN.
                                                                 The WXN bit is permitted to be cached in a TLB.
                                                                 0 = Regions with write permission are not forced to XN.
                                                                 1 = Regions with write permission are forced to XN. */
		uint32_t rsvd_18                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_17_17              : 1;
		uint32_t rsvd_16                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_13_15              : 3;
		uint32_t i                           : 1;  /**< R/W - Instruction cache enable. This is an enable bit for
                                                                     instruction caches at EL3.
                                                                 When this bit is 0, all EL3 Normal memory instruction accesses
                                                                     are Non-cacheable. This bit has no effect on the EL1&0 or EL2
                                                                     translation regimes.
                                                                 0 = Instruction caches disabled at EL3. If AP_SCTLR_EL3[M] is set to
                                                                     0, instruction accesses from stage 1 of the EL3 translation
                                                                     regime are to Normal memory, Outer Shareable, Inner Non-
                                                                     cacheable, Outer Non-cacheable.
                                                                 1 = Instruction caches enabled at EL3. If AP_SCTLR_EL3[M] is set to 0,
                                                                     instruction accesses from stage 1 of the EL3 translation
                                                                     regime are to Normal memory, Outer Shareable, Inner Write-
                                                                     Through, Outer Write-Through. */
		uint32_t rsvd_11                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_6_10               : 5;
		uint32_t rsvd_4_5                    : 2;  /**< RO - Reserved 1. */
		uint32_t sa                          : 1;  /**< R/W - Stack Alignment Check Enable. When set, use of the stack
                                                                 pointer as the base address in a load/store instruction at
                                                                 this register's Exception level must be aligned to a 16-byte
                                                                 boundary, or a Stack Alignment Fault exception will be raised. */
		uint32_t cc                          : 1;  /**< R/W - Cache enable. This is an enable bit for data and unified
                                                                     caches at EL3:

                                                                 When this bit is 0, all EL3 Normal memory data accesses and
                                                                     all accesses to the EL3 translation tables are Non-cacheable.
                                                                     This bit has no effect on the EL1&0 or EL2 translation
                                                                     regimes.
                                                                 0 = Data and unified caches disabled at EL3.
                                                                 1 = Data and unified caches enabled at EL3. */
		uint32_t aa                          : 1;  /**< R/W - Alignment check enable. This is the enable bit for Alignment
                                                                     fault checking:

                                                                 Load/store exclusive and load-acquire/store-release
                                                                     instructions have an alignment check regardless of the value
                                                                     of the A bit.

                                                                 0 = Alignment fault checking disabled.
                                                                 Instructions that load or store one or more registers, other
                                                                     than load/store exclusive and load-acquire/store-release, do
                                                                     not check that the address being accessed is aligned to the
                                                                     size of the data element(s) being accessed.

                                                                 1 = Alignment fault checking enabled.
                                                                 All instructions that load or store one or more registers have
                                                                     an alignment check that the address being accessed is aligned
                                                                     to the size of the data element(s) being accessed. If this
                                                                     check fails it causes an Alignment fault, which is taken as a
                                                                     Data Abort exception. */
		uint32_t m                           : 1;  /**< R/W - MMU enable for EL3 stage 1 address translation.
                                                                 0 = EL3 stage 1 address translation disabled.
                                                                 1 = EL3 stage 1 address translation enabled. */
#else
		uint32_t m                           : 1;
		uint32_t aa                          : 1;
		uint32_t cc                          : 1;
		uint32_t sa                          : 1;
		uint32_t rsvd_4_5                    : 2;
		uint32_t reserved_6_10               : 5;
		uint32_t rsvd_11                     : 1;
		uint32_t i                           : 1;
		uint32_t reserved_13_15              : 3;
		uint32_t rsvd_16                     : 1;
		uint32_t reserved_17_17              : 1;
		uint32_t rsvd_18                     : 1;
		uint32_t wxn                         : 1;
		uint32_t reserved_20_21              : 2;
		uint32_t rsvd_22                     : 1;
		uint32_t span                        : 1;
		uint32_t reserved_24_24              : 1;
		uint32_t ee                          : 1;
		uint32_t reserved_26_27              : 2;
		uint32_t rsvd_28_29                  : 2;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_ap_sctlr_el2_s          cn88xx; */
	/* struct bdk_ap_sctlr_el2_s          cn88xxp1; */
} bdk_ap_sctlr_el2_t;

#define BDK_AP_SCTLR_EL2 BDK_AP_SCTLR_EL2_FUNC()
static inline uint64_t BDK_AP_SCTLR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SCTLR_EL2_FUNC(void)
{
	return 0x0000030401000000ull;
}
#define typedef_BDK_AP_SCTLR_EL2 bdk_ap_sctlr_el2_t
#define bustype_BDK_AP_SCTLR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SCTLR_EL2 0
#define arguments_BDK_AP_SCTLR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_SCTLR_EL2 "AP_SCTLR_EL2"


/**
 * SYSREG - ap_sctlr_el2_e2h
 *
 * Provides top level control of the system, including its memory
 *     system, at EL2.
 *
 * This register is at the same select as AP_SCTLR_EL2 and is used when E2H=1.
 */
typedef union bdk_ap_sctlr_el2_e2h {
	uint32_t u;
	struct bdk_ap_sctlr_el2_e2h_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t rsvd_28_29                  : 2;  /**< RO - Reserved 1. */
		uint32_t reserved_27_27              : 1;
		uint32_t uci                         : 1;  /**< R/W - When set, enables EL0 access in AArch64 for DC CVAU, DC CIVAC,
                                                                 DC CVAC, and IC IVAU instructions. */
		uint32_t ee                          : 1;  /**< R/W - Exception Endianness. This bit controls the endianness for:
                                                                  Explicit data accesses at EL1.
                                                                  Stage 1 translation table walks at EL1 and EL0.

                                                                 If an implementation does not provide Big-endian support, this
                                                                     bit is RES0. If it does not provide Little-endian support,
                                                                     this bit is RES1.

                                                                 The EE bit is permitted to be cached in a TLB.

                                                                 0 = Little-endian.
                                                                 1 = Big-endian. */
		uint32_t e0e                         : 1;  /**< R/W - Endianness of explicit data accesses at EL0.

                                                                 If an implementation only supports Little-endian accesses at
                                                                     EL0 then this bit is RES0.

                                                                 If an implementation only supports Big-endian accesses at EL0
                                                                     then this bit is RES1.

                                                                 This bit has no effect on the endianness of LDTR* and STTR*
                                                                     instructions executed at EL1.

                                                                 0 = Explicit data accesses at EL0 are little-endian.
                                                                 1 = Explicit data accesses at EL0 are big-endian. */
		uint32_t span                        : 1;  /**< R/W - v8.1: Bit[23]: SPAN set PSTATE/CPSR[AP_PAN] bit on taking an exception
                                                                 to the EL1 exception level.
                                                                 0 = PSTATE/CPSR[AP_PAN] is set on taking an exception to the EL1 exception level
                                                                 1 = PSTATE/CPSR[AP_PAN] is left unchanged on taking an exception to the EL1 exception
                                                                 level

                                                                 This bit has no effect on the PSTATE/CPSR[AP_PAN] when taking exceptions to any other
                                                                 exception level. */
		uint32_t rsvd_22                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_21_21              : 1;
		uint32_t rsvd_20                     : 1;  /**< RO - Reserved 1. */
		uint32_t wxn                         : 1;  /**< R/W - Write permission implies XN (Execute Never). This bit can be
                                                                     used to require all memory regions with write permission to be
                                                                     treated as XN.

                                                                 The WXN bit is permitted to be cached in a TLB.

                                                                 0 = Regions with write permission are not forced to XN.
                                                                 1 = Regions with write permission are forced to XN. */
		uint32_t ntwe                        : 1;  /**< R/W - Not trap WFE.
                                                                 Conditional WFE instructions that fail their condition do not
                                                                     cause an exception if this bit is 0.
                                                                 0 = If a WFE instruction executed at EL0 would cause execution to
                                                                     be suspended, such as if the event register is not set and
                                                                     there is not a pending WFE wakeup event, it is taken as an
                                                                     exception to EL1 using the0x1
                                                                 1 = WFE instructions are executed as normal. */
		uint32_t reserved_17_17              : 1;
		uint32_t ntwi                        : 1;  /**< R/W - Not trap WFI.
                                                                 Conditional WFI instructions that fail their condition do not
                                                                     cause an exception if this bit is 0.
                                                                 0 = If a WFI instruction executed at EL0 would cause execution to
                                                                     be suspended, such as if there is not a pending WFI wakeup
                                                                     event, it is taken as an exception to EL1 using the0x1
                                                                 1 = WFI instructions are executed as normal. */
		uint32_t uct                         : 1;  /**< R/W - When set, enables EL0 access in AArch64 to the AP_CTR_EL0
                                                                 register. */
		uint32_t dze                         : 1;  /**< R/W - Access to DC ZVA instruction at EL0.
                                                                 0 = Execution of the DC ZVA instruction is prohibited at EL0, and
                                                                     it is treated as undefined at EL0.
                                                                 1 = Execution of the DC ZVA instruction is allowed at EL0. */
		uint32_t reserved_13_13              : 1;
		uint32_t i                           : 1;  /**< R/W - Instruction cache enable. This is an enable bit for
                                                                     instruction caches at EL0 and EL1:
                                                                 When this bit is 0, all EL1 and EL0 Normal memory instruction
                                                                     accesses are Non-cacheable.
                                                                 If the AP_HCR_EL2[DC] bit is set to 1, then the non-secure stage 1
                                                                     EL1&0 translation regime is Cacheable regardless of the value
                                                                     of this bit.
                                                                 0 = Instruction caches disabled at EL0 and EL1. If AP_SCTLR_EL1[M] is
                                                                     set to 0, instruction accesses from stage 1 of the EL1&0
                                                                     translation regime are to Normal memory, Outer Shareable,
                                                                     Inner Non-cacheable, Outer Non-cacheable.
                                                                 1 = Instruction caches enabled at EL0 and EL1. If AP_SCTLR_EL1[M] is
                                                                     set to 0, instruction accesses from stage 1 of the EL1&0
                                                                     translation regime are to Normal memory, Outer Shareable,
                                                                     Inner Write-Through, Outer Write-Through. */
		uint32_t rsvd_11                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_10_10              : 1;
		uint32_t uma                         : 1;  /**< R/W - User Mask Access. Controls access to interrupt masks from EL0,
                                                                     when EL0 is using AArch64.
                                                                 0 = Disable access to the interrupt masks from EL0.
                                                                 1 = Enable access to the interrupt masks from EL0. */
		uint32_t rsvd_8                      : 1;  /**< RO - SETEND disable.
                                                                 If an implementation does not support mixed endian operation,
                                                                     this bit is RES1.
                                                                 0 = The SETEND instruction is available.
                                                                 1 = The SETEND instruction is UNALLOCATED.

                                                                 SED: SETEND Disable - Only supported with 32 bit */
		uint32_t rsvd_7                      : 1;  /**< RO - "IT Disable.
                                                                 0 = The IT instruction functionality is available.
                                                                 1 = It is implementation defined whether the IT instruction is
                                                                     treated as either:
                                                                 * A 16-bit instruction, which can only be followed by another
                                                                     16-bit instruction.
                                                                 * The first half of a 32-bit instruction.

                                                                 An implementation might vary dynamically as to whether IT is
                                                                     treated as a 16-bit instruction or the first half of a 32-bit
                                                                     instruction.

                                                                 All encodings of the IT instruction with hw1[3:0]!=1000 are
                                                                     UNdefined and treated as unallocated.

                                                                 All encodings of the subsequent instruction with the following
                                                                     values for hw1 are UNdefined (and treated as unallocated):

                                                                 - 0b11xxxxxxxxxxxxxx: All 32-bit instructions, and the 16-bit
                                                                     instructions B, UDF, SVC, LDM, and STM.

                                                                 - 0b1x11xxxxxxxxxxxx: All instructions in.

                                                                 - 0b1x100xxxxxxxxxxx: ADD Rd, PC, \#imm

                                                                 - 0b01001xxxxxxxxxxx: LDR Rd, [PC, \#imm]

                                                                 - 0b0100x1xxx1111xxx: ADD Rdn, PC; CMP Rn, PC; MOV Rd, PC; BX
                                                                     PC; BLX PC.

                                                                 - 0b010001xx1xxxx111: ADD PC, Rm; CMP PC, Rm; MOV PC, Rm. This
                                                                     pattern also covers UNPREDICTABLE cases with BLX Rn.

                                                                 Contrary to the standard treatment of conditional UNdefined
                                                                     instructions in the ARM architecture, in this case these
                                                                     instructions are always treated as UNdefined, regardless of
                                                                     whether the instruction would pass or fail its condition codes
                                                                     as a result of being in an IT block.

                                                                 ITD: IT Disable - Only supported with 32 bit" */
		uint32_t reserved_5_6                : 2;
		uint32_t sa0                         : 1;  /**< R/W - Stack Alignment Check Enable for EL0. When set, use of the
                                                                 stack pointer as the base address in a load/store instruction
                                                                 at EL0 must be aligned to a 16-byte boundary, or a Stack
                                                                 Alignment Fault exception will be raised. */
		uint32_t sa                          : 1;  /**< R/W - Stack Alignment Check Enable. When set, use of the stack
                                                                 pointer as the base address in a load/store instruction at
                                                                 this register's Exception level must be aligned to a 16-byte
                                                                 boundary, or a Stack Alignment Fault exception will be raised. */
		uint32_t cc                          : 1;  /**< R/W - Cache enable. This is an enable bit for data and unified
                                                                     caches at EL0 and EL1:
                                                                 When this bit is 0, all EL0 and EL1 Normal memory data
                                                                     accesses and all accesses to the EL1&0 stage 1 translation
                                                                     tables are Non-cacheable.
                                                                 If the AP_HCR_EL2[DC] bit is set to 1, then the non-secure stage 1
                                                                     EL1&0 translation regime is Cacheable regardless of the value
                                                                     of the AP_SCTLR_EL1[C] bit.
                                                                 0 = Data and unified caches disabled.
                                                                 1 = Data and unified caches enabled. */
		uint32_t aa                          : 1;  /**< R/W - Alignment check enable. This is the enable bit for Alignment
                                                                     fault checking.

                                                                 Load/store exclusive and load-acquire/store-release
                                                                     instructions have an alignment check regardless of the value
                                                                     of the A bit.

                                                                 0 = Alignment fault checking disabled.
                                                                 Instructions that load or store one or more registers, other
                                                                     than load/store exclusive and load-acquire/store-release, do
                                                                     not check that the address being accessed is aligned to the
                                                                     size of the data element(s) being accessed.

                                                                 1 = Alignment fault checking enabled.
                                                                 All instructions that load or store one or more registers have
                                                                     an alignment check that the address being accessed is aligned
                                                                     to the size of the data element(s) being accessed. If this
                                                                     check fails it causes an Alignment fault, which is taken as a
                                                                     Data Abort exception. */
		uint32_t m                           : 1;  /**< R/W - MMU enable for EL1 and EL0 stage 1 address translation.

                                                                 If AP_HCR_EL2[DC] is set to 1, then in non-secure state the
                                                                     AP_SCTLR_EL1[M] bit behaves as 0 for all purposes other than
                                                                     reading the value of the bit.
                                                                 0 = EL1 and EL0 stage 1 address translation disabled.
                                                                 1 = EL1 and EL0 stage 1 address translation enabled. */
#else
		uint32_t m                           : 1;
		uint32_t aa                          : 1;
		uint32_t cc                          : 1;
		uint32_t sa                          : 1;
		uint32_t sa0                         : 1;
		uint32_t reserved_5_6                : 2;
		uint32_t rsvd_7                      : 1;
		uint32_t rsvd_8                      : 1;
		uint32_t uma                         : 1;
		uint32_t reserved_10_10              : 1;
		uint32_t rsvd_11                     : 1;
		uint32_t i                           : 1;
		uint32_t reserved_13_13              : 1;
		uint32_t dze                         : 1;
		uint32_t uct                         : 1;
		uint32_t ntwi                        : 1;
		uint32_t reserved_17_17              : 1;
		uint32_t ntwe                        : 1;
		uint32_t wxn                         : 1;
		uint32_t rsvd_20                     : 1;
		uint32_t reserved_21_21              : 1;
		uint32_t rsvd_22                     : 1;
		uint32_t span                        : 1;
		uint32_t e0e                         : 1;
		uint32_t ee                          : 1;
		uint32_t uci                         : 1;
		uint32_t reserved_27_27              : 1;
		uint32_t rsvd_28_29                  : 2;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_ap_sctlr_el2_e2h_s      cn88xx; */
	/* struct bdk_ap_sctlr_el2_e2h_s      cn88xxp1; */
} bdk_ap_sctlr_el2_e2h_t;

#define BDK_AP_SCTLR_EL2_E2H BDK_AP_SCTLR_EL2_E2H_FUNC()
static inline uint64_t BDK_AP_SCTLR_EL2_E2H_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SCTLR_EL2_E2H_FUNC(void)
{
	return 0x0000030401000010ull;
}
#define typedef_BDK_AP_SCTLR_EL2_E2H bdk_ap_sctlr_el2_e2h_t
#define bustype_BDK_AP_SCTLR_EL2_E2H BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SCTLR_EL2_E2H 0
#define arguments_BDK_AP_SCTLR_EL2_E2H -1,-1,-1,-1
#define basename_BDK_AP_SCTLR_EL2_E2H "AP_SCTLR_EL2_E2H"


/**
 * SYSREG - ap_sctlr_el3
 *
 * Provides top level control of the system, including its memory
 * system, at EL3.
 */
typedef union bdk_ap_sctlr_el3 {
	uint32_t u;
	struct bdk_ap_sctlr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t rsvd_28_29                  : 2;  /**< RO - Reserved 1. */
		uint32_t reserved_26_27              : 2;
		uint32_t ee                          : 1;  /**< R/W - Exception Endianness. This bit controls the endianness for:
                                                                  Explicit data accesses at EL3.
                                                                  Stage 1 translation table walks at EL3.

                                                                 If an implementation does not provide Big-endian support, this
                                                                     bit is RES0. If it does not provide Little-endian support,
                                                                     this bit is RES1.

                                                                 The EE bit is permitted to be cached in a TLB.
                                                                 0 = Little-endian.
                                                                 1 = Big-endian. */
		uint32_t reserved_24_24              : 1;
		uint32_t rsvd_23                     : 1;  /**< RO - Reserved 1. */
		uint32_t rsvd_22                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_20_21              : 2;
		uint32_t wxn                         : 1;  /**< R/W - Write permission implies XN (Execute Never). This bit can be
                                                                     used to require all memory regions with write permission to be
                                                                     treated as XN.
                                                                 The WXN bit is permitted to be cached in a TLB.
                                                                 0 = Regions with write permission are not forced to XN.
                                                                 1 = Regions with write permission are forced to XN. */
		uint32_t rsvd_18                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_17_17              : 1;
		uint32_t rsvd_16                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_13_15              : 3;
		uint32_t i                           : 1;  /**< R/W - Instruction cache enable. This is an enable bit for
                                                                     instruction caches at EL3:

                                                                 When this bit is 0, all EL3 Normal memory instruction accesses
                                                                     are Non-cacheable. This bit has no effect on the EL1&0 or EL2
                                                                     translation regimes.

                                                                 0 = Instruction caches disabled at EL3. If AP_SCTLR_EL3[M] is set to
                                                                     0, instruction accesses from stage 1 of the EL3 translation
                                                                     regime are to Normal memory, Outer Shareable, Inner Non-
                                                                     cacheable, Outer Non-cacheable.
                                                                 1 = Instruction caches enabled at EL3. If AP_SCTLR_EL3[M] is set to 0,
                                                                     instruction accesses from stage 1 of the EL3 translation
                                                                     regime are to Normal memory, Outer Shareable, Inner Write-
                                                                     Through, Outer Write-Through. */
		uint32_t rsvd_11                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_6_10               : 5;
		uint32_t rsvd_4_5                    : 2;  /**< RO - Reserved 1. */
		uint32_t sa                          : 1;  /**< R/W - Stack alignment check enable. When set, use of the stack
                                                                 pointer as the base address in a load/store instruction at
                                                                 this register's exception level must be aligned to a 16-byte
                                                                 boundary, or a stack alignment fault exception will be raised. */
		uint32_t cc                          : 1;  /**< R/W - Cache enable. This is an enable bit for data and unified
                                                                     caches at EL3.

                                                                 When this bit is 0, all EL3 normal memory data accesses and
                                                                     all accesses to the EL3 translation tables are Non-cacheable.
                                                                     This bit has no effect on the EL1&0 or EL2 translation
                                                                     regimes.

                                                                 0 = Data and unified caches disabled at EL3.
                                                                 1 = Data and unified caches enabled at EL3. */
		uint32_t aa                          : 1;  /**< R/W - Alignment check enable. This is the enable bit for Alignment
                                                                     fault checking:

                                                                 Load/store exclusive and load-acquire/store-release
                                                                     instructions have an alignment check regardless of the value
                                                                     of the A bit.

                                                                 0 = Alignment fault checking disabled.
                                                                 Instructions that load or store one or more registers, other
                                                                     than load/store exclusive and load-acquire/store-release, do
                                                                     not check that the address being accessed is aligned to the
                                                                     size of the data element(s) being accessed.

                                                                 1 = Alignment fault checking enabled.
                                                                 All instructions that load or store one or more registers have
                                                                     an alignment check that the address being accessed is aligned
                                                                     to the size of the data element(s) being accessed. If this
                                                                     check fails it causes an Alignment fault, which is taken as a
                                                                     Data Abort exception. */
		uint32_t m                           : 1;  /**< R/W - MMU enable for EL3 stage 1 address translation.
                                                                 0 = EL3 stage 1 address translation disabled.
                                                                 1 = EL3 stage 1 address translation enabled. */
#else
		uint32_t m                           : 1;
		uint32_t aa                          : 1;
		uint32_t cc                          : 1;
		uint32_t sa                          : 1;
		uint32_t rsvd_4_5                    : 2;
		uint32_t reserved_6_10               : 5;
		uint32_t rsvd_11                     : 1;
		uint32_t i                           : 1;
		uint32_t reserved_13_15              : 3;
		uint32_t rsvd_16                     : 1;
		uint32_t reserved_17_17              : 1;
		uint32_t rsvd_18                     : 1;
		uint32_t wxn                         : 1;
		uint32_t reserved_20_21              : 2;
		uint32_t rsvd_22                     : 1;
		uint32_t rsvd_23                     : 1;
		uint32_t reserved_24_24              : 1;
		uint32_t ee                          : 1;
		uint32_t reserved_26_27              : 2;
		uint32_t rsvd_28_29                  : 2;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_ap_sctlr_el3_s          cn88xx; */
	/* struct bdk_ap_sctlr_el3_s          cn88xxp1; */
} bdk_ap_sctlr_el3_t;

#define BDK_AP_SCTLR_EL3 BDK_AP_SCTLR_EL3_FUNC()
static inline uint64_t BDK_AP_SCTLR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SCTLR_EL3_FUNC(void)
{
	return 0x0000030601000000ull;
}
#define typedef_BDK_AP_SCTLR_EL3 bdk_ap_sctlr_el3_t
#define bustype_BDK_AP_SCTLR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SCTLR_EL3 0
#define arguments_BDK_AP_SCTLR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_SCTLR_EL3 "AP_SCTLR_EL3"


/**
 * SYSREG - ap_sder32_el3
 *
 * Allows access to the AArch32 register SDER from AArch64 state
 * only. Its value has no effect on execution in AArch64 state.
 */
typedef union bdk_ap_sder32_el3 {
	uint32_t u;
	struct bdk_ap_sder32_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t suniden                     : 1;  /**< R/W - Secure User Non-Invasive Debug Enable:
                                                                 0 = Non-invasive debug not permitted in Secure EL0 mode.
                                                                 1 = Non-invasive debug permitted in Secure EL0 mode. */
		uint32_t suiden                      : 1;  /**< R/W - Secure User Invasive Debug Enable:
                                                                 0 = Invasive debug not permitted in Secure EL0 mode.
                                                                 1 = Invasive debug permitted in Secure EL0 mode. */
#else
		uint32_t suiden                      : 1;
		uint32_t suniden                     : 1;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_ap_sder32_el3_s         cn88xx; */
	/* struct bdk_ap_sder32_el3_s         cn88xxp1; */
} bdk_ap_sder32_el3_t;

#define BDK_AP_SDER32_EL3 BDK_AP_SDER32_EL3_FUNC()
static inline uint64_t BDK_AP_SDER32_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SDER32_EL3_FUNC(void)
{
	return 0x0000030601010100ull;
}
#define typedef_BDK_AP_SDER32_EL3 bdk_ap_sder32_el3_t
#define bustype_BDK_AP_SDER32_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SDER32_EL3 0
#define arguments_BDK_AP_SDER32_EL3 -1,-1,-1,-1
#define basename_BDK_AP_SDER32_EL3 "AP_SDER32_EL3"


/**
 * SYSREG - ap_sp_el0
 *
 * Holds the stack pointer if AP_SPSel[SP] is 0, or the stack pointer
 * for EL0 if AP_SPSel[SP] is 1.
 */
typedef union bdk_ap_sp_el0 {
	uint64_t u;
	struct bdk_ap_sp_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Stack pointer. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_sp_el0_s             cn88xx; */
	/* struct bdk_ap_sp_el0_s             cn88xxp1; */
} bdk_ap_sp_el0_t;

#define BDK_AP_SP_EL0 BDK_AP_SP_EL0_FUNC()
static inline uint64_t BDK_AP_SP_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SP_EL0_FUNC(void)
{
	return 0x0000030004010000ull;
}
#define typedef_BDK_AP_SP_EL0 bdk_ap_sp_el0_t
#define bustype_BDK_AP_SP_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SP_EL0 0
#define arguments_BDK_AP_SP_EL0 -1,-1,-1,-1
#define basename_BDK_AP_SP_EL0 "AP_SP_EL0"


/**
 * SYSREG - ap_sp_el1
 *
 * Holds the stack pointer for EL1 if AP_SPSel[SP] is 1 (the stack
 * pointer selected is SP_ELx).
 */
typedef union bdk_ap_sp_el1 {
	uint64_t u;
	struct bdk_ap_sp_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Stack pointer. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_sp_el1_s             cn88xx; */
	/* struct bdk_ap_sp_el1_s             cn88xxp1; */
} bdk_ap_sp_el1_t;

#define BDK_AP_SP_EL1 BDK_AP_SP_EL1_FUNC()
static inline uint64_t BDK_AP_SP_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SP_EL1_FUNC(void)
{
	return 0x0000030404010000ull;
}
#define typedef_BDK_AP_SP_EL1 bdk_ap_sp_el1_t
#define bustype_BDK_AP_SP_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SP_EL1 0
#define arguments_BDK_AP_SP_EL1 -1,-1,-1,-1
#define basename_BDK_AP_SP_EL1 "AP_SP_EL1"


/**
 * SYSREG - ap_sp_el2
 *
 * Holds the stack pointer for EL2 if AP_SPSel[SP] is 1 (the stack
 * pointer selected is SP_ELx).
 */
typedef union bdk_ap_sp_el2 {
	uint64_t u;
	struct bdk_ap_sp_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Stack pointer. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_sp_el2_s             cn88xx; */
	/* struct bdk_ap_sp_el2_s             cn88xxp1; */
} bdk_ap_sp_el2_t;

#define BDK_AP_SP_EL2 BDK_AP_SP_EL2_FUNC()
static inline uint64_t BDK_AP_SP_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SP_EL2_FUNC(void)
{
	return 0x0000030604010000ull;
}
#define typedef_BDK_AP_SP_EL2 bdk_ap_sp_el2_t
#define bustype_BDK_AP_SP_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SP_EL2 0
#define arguments_BDK_AP_SP_EL2 -1,-1,-1,-1
#define basename_BDK_AP_SP_EL2 "AP_SP_EL2"


/**
 * SYSREG - ap_spsel
 *
 * Allows the Stack Pointer to be selected between AP_SP_EL0 and
 * SP_ELx.
 */
typedef union bdk_ap_spsel {
	uint32_t u;
	struct bdk_ap_spsel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t sp                          : 1;  /**< R/W - Stack pointer to use.
                                                                 0 = Use AP_SP_EL0 at all Exception levels.
                                                                 1 = Use SP_ELx for Exception level ELx. */
#else
		uint32_t sp                          : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_spsel_s              cn88xx; */
	/* struct bdk_ap_spsel_s              cn88xxp1; */
} bdk_ap_spsel_t;

#define BDK_AP_SPSEL BDK_AP_SPSEL_FUNC()
static inline uint64_t BDK_AP_SPSEL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSEL_FUNC(void)
{
	return 0x0000030004020000ull;
}
#define typedef_BDK_AP_SPSEL bdk_ap_spsel_t
#define bustype_BDK_AP_SPSEL BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSEL 0
#define arguments_BDK_AP_SPSEL -1,-1,-1,-1
#define basename_BDK_AP_SPSEL "AP_SPSEL"


/**
 * SYSREG - ap_spsr_abt
 *
 * Holds the saved processor state when an exception is taken to
 *     Abort mode.
 * If EL1 does not support execution in AArch32, this register is RES0.
 */
typedef union bdk_ap_spsr_abt {
	uint32_t u;
	struct bdk_ap_spsr_abt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_spsr_abt_s           cn88xx; */
	/* struct bdk_ap_spsr_abt_s           cn88xxp1; */
} bdk_ap_spsr_abt_t;

#define BDK_AP_SPSR_ABT BDK_AP_SPSR_ABT_FUNC()
static inline uint64_t BDK_AP_SPSR_ABT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSR_ABT_FUNC(void)
{
	return 0x0000030404030100ull;
}
#define typedef_BDK_AP_SPSR_ABT bdk_ap_spsr_abt_t
#define bustype_BDK_AP_SPSR_ABT BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSR_ABT 0
#define arguments_BDK_AP_SPSR_ABT -1,-1,-1,-1
#define basename_BDK_AP_SPSR_ABT "AP_SPSR_ABT"


/**
 * SYSREG - ap_spsr_el#
 *
 * Holds the saved processor state when an exception is taken to
 * EL*.
 */
typedef union bdk_ap_spsr_elx {
	uint32_t u;
	struct bdk_ap_spsr_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t n                           : 1;  /**< R/W - Set to the value of CPSR[N] on taking an exception to Monitor
                                                                 mode, and copied to CPSR[N] on executing an exception return
                                                                 operation in Monitor mode. */
		uint32_t z                           : 1;  /**< R/W - Set to the value of CPSR[Z] on taking an exception to Monitor
                                                                 mode, and copied to CPSR[Z] on executing an exception return
                                                                 operation in Monitor mode. */
		uint32_t cc                          : 1;  /**< R/W - Set to the value of CPSR[C] on taking an exception to Monitor
                                                                 mode, and copied to CPSR[C] on executing an exception return
                                                                 operation in Monitor mode. */
		uint32_t v                           : 1;  /**< R/W - Set to the value of CPSR[V] on taking an exception to Monitor
                                                                 mode, and copied to CPSR[V] on executing an exception return
                                                                 operation in Monitor mode. */
		uint32_t reserved_23_27              : 5;
		uint32_t pan                         : 1;  /**< R/W - 0 = Has no effect on the translation system.
                                                                 1 = Disables data read or data write access from EL1 (or EL2
                                                                    when AP_HCR_EL2[E2H] == 1 && AP_HCR_EL2[TGE] == 1) to a virtual
                                                                    address where access to the virtual address at EL0 is
                                                                    permitted at stage 1 by the combination of the AP[1] bit
                                                                    and the APTable[0] bits (if appropriate).  That is, when
                                                                    AP[1] == 1 && APTable[0] == 0 for all APTable bits
                                                                    associated with that virtual address.

                                                                    The AP_PAN bit has no effect on instruction accesses.

                                                                    If access is disabled, then the access will give rise to
                                                                    a stage 1 permission fault, taken in the same way as all
                                                                    other stage 1 permission faults. */
		uint32_t ss                          : 1;  /**< R/W - Software step. Indicates whether software step was
                                                                 enabled when an exception was taken. */
		uint32_t il                          : 1;  /**< R/W - The IL bit is added to process state to indicate that on
                                                                 exception return or as a result of an explicit change of the
                                                                 CPSR mode field in AArch32, an illegal state or mode was
                                                                 indicated, as described in section 3.5.6.3. Its value is
                                                                 reflected in the SPSR when it is set at a time when the
                                                                 process state IL bit was set either:

                                                                 - As a result of an UNdefined exception caused by the process
                                                                     state IL bit being set, or

                                                                 - Where execution was pre-empted between setting the process
                                                                     state IL bit and an UNdefined exception being taken.

                                                                 The IL bit is added as part of the ARMv8 architecture, but
                                                                 applies to execution in both AArch32 and AArch64. It is
                                                                 allocated into bit[20] of the SPSR. It is impossible for
                                                                 software to observe the value 1 in the CPSR in AArch32, or
                                                                 to observe the current Process State value in AArch64. */
		uint32_t reserved_10_19              : 10;
		uint32_t dd                          : 1;  /**< R/W - Interrupt masks - can also be accessed as PSTATE[D,A,I,F]. */
		uint32_t aa                          : 1;  /**< R/W - Interrupt masks - can also be accessed as PSTATE[D,A,I,F]. */
		uint32_t i                           : 1;  /**< R/W - Interrupt masks - can also be accessed as PSTATE[D,A,I,F]. */
		uint32_t f                           : 1;  /**< R/W - Interrupt masks - can also be accessed as PSTATE[D,A,I,F]. */
		uint32_t reserved_5_5                : 1;
		uint32_t from32                      : 1;  /**< R/W - 0 = Exception came from 64bit
                                                                 1 = Exception came from 32bit
                                                                 If 32bit is not implemented, then this causes an illegal state
                                                                 exception. */
		uint32_t el                          : 2;  /**< R/W - Current exception level 00 - EL0 01 -EL1, 10 - EL2, 11 - EL3. */
		uint32_t reserved_1_1                : 1;
		uint32_t sp                          : 1;  /**< R/W - AArch64 only - Stack Pointer selection - 0 - SP0, 1 - SPx. */
#else
		uint32_t sp                          : 1;
		uint32_t reserved_1_1                : 1;
		uint32_t el                          : 2;
		uint32_t from32                      : 1;
		uint32_t reserved_5_5                : 1;
		uint32_t f                           : 1;
		uint32_t i                           : 1;
		uint32_t aa                          : 1;
		uint32_t dd                          : 1;
		uint32_t reserved_10_19              : 10;
		uint32_t il                          : 1;
		uint32_t ss                          : 1;
		uint32_t pan                         : 1;
		uint32_t reserved_23_27              : 5;
		uint32_t v                           : 1;
		uint32_t cc                          : 1;
		uint32_t z                           : 1;
		uint32_t n                           : 1;
#endif
	} s;
	/* struct bdk_ap_spsr_elx_s           cn88xx; */
	/* struct bdk_ap_spsr_elx_s           cn88xxp1; */
} bdk_ap_spsr_elx_t;

static inline uint64_t BDK_AP_SPSR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x0000030004000000ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_SPSR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_SPSR_ELX(...) bdk_ap_spsr_elx_t
#define bustype_BDK_AP_SPSR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSR_ELX(p1) (p1)
#define arguments_BDK_AP_SPSR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_SPSR_ELX(...) "AP_SPSR_ELX"


/**
 * SYSREG - ap_spsr_el12
 *
 * Allows EL2 and EL3 access to SPSR_EL1 when AP_HCR_EL2[E2H]==1.
 *
 */
typedef union bdk_ap_spsr_el12 {
	uint32_t u;
	struct bdk_ap_spsr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_spsr_el12_s          cn88xx; */
	/* struct bdk_ap_spsr_el12_s          cn88xxp1; */
} bdk_ap_spsr_el12_t;

#define BDK_AP_SPSR_EL12 BDK_AP_SPSR_EL12_FUNC()
static inline uint64_t BDK_AP_SPSR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSR_EL12_FUNC(void)
{
	return 0x0000030504000000ull;
}
#define typedef_BDK_AP_SPSR_EL12 bdk_ap_spsr_el12_t
#define bustype_BDK_AP_SPSR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSR_EL12 0
#define arguments_BDK_AP_SPSR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_SPSR_EL12 "AP_SPSR_EL12"


/**
 * SYSREG - ap_spsr_fiq
 *
 * Holds the saved processor state when an exception is taken to
 *     FIQ mode.
 * If EL1 does not support execution in AArch32, this register is RES0.
 */
typedef union bdk_ap_spsr_fiq {
	uint32_t u;
	struct bdk_ap_spsr_fiq_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_spsr_fiq_s           cn88xx; */
	/* struct bdk_ap_spsr_fiq_s           cn88xxp1; */
} bdk_ap_spsr_fiq_t;

#define BDK_AP_SPSR_FIQ BDK_AP_SPSR_FIQ_FUNC()
static inline uint64_t BDK_AP_SPSR_FIQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSR_FIQ_FUNC(void)
{
	return 0x0000030404030300ull;
}
#define typedef_BDK_AP_SPSR_FIQ bdk_ap_spsr_fiq_t
#define bustype_BDK_AP_SPSR_FIQ BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSR_FIQ 0
#define arguments_BDK_AP_SPSR_FIQ -1,-1,-1,-1
#define basename_BDK_AP_SPSR_FIQ "AP_SPSR_FIQ"


/**
 * SYSREG - ap_spsr_irq
 *
 * Holds the saved processor state when an exception is taken to
 *     IRQ mode.
 * If EL1 does not support execution in AArch32, this register is RES0.
 */
typedef union bdk_ap_spsr_irq {
	uint32_t u;
	struct bdk_ap_spsr_irq_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_spsr_irq_s           cn88xx; */
	/* struct bdk_ap_spsr_irq_s           cn88xxp1; */
} bdk_ap_spsr_irq_t;

#define BDK_AP_SPSR_IRQ BDK_AP_SPSR_IRQ_FUNC()
static inline uint64_t BDK_AP_SPSR_IRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSR_IRQ_FUNC(void)
{
	return 0x0000030404030000ull;
}
#define typedef_BDK_AP_SPSR_IRQ bdk_ap_spsr_irq_t
#define bustype_BDK_AP_SPSR_IRQ BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSR_IRQ 0
#define arguments_BDK_AP_SPSR_IRQ -1,-1,-1,-1
#define basename_BDK_AP_SPSR_IRQ "AP_SPSR_IRQ"


/**
 * SYSREG - ap_spsr_und
 *
 * Holds the saved processor state when an exception is taken to
 *     Undefined mode.
 * If EL1 does not support execution in AArch32, this register is RES0.
 */
typedef union bdk_ap_spsr_und {
	uint32_t u;
	struct bdk_ap_spsr_und_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ap_spsr_und_s           cn88xx; */
	/* struct bdk_ap_spsr_und_s           cn88xxp1; */
} bdk_ap_spsr_und_t;

#define BDK_AP_SPSR_UND BDK_AP_SPSR_UND_FUNC()
static inline uint64_t BDK_AP_SPSR_UND_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_SPSR_UND_FUNC(void)
{
	return 0x0000030404030200ull;
}
#define typedef_BDK_AP_SPSR_UND bdk_ap_spsr_und_t
#define bustype_BDK_AP_SPSR_UND BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_SPSR_UND 0
#define arguments_BDK_AP_SPSR_UND -1,-1,-1,-1
#define basename_BDK_AP_SPSR_UND "AP_SPSR_UND"


/**
 * SYSREG - ap_tcr_el1
 *
 * Determines which of the Translation Table Base Registers
 * defined the base address for a translation table walk required
 * for the stage 1 translation of a memory access from EL0 or
 * EL1. Also controls the translation table format and holds
 * cacheability and shareability information.
 */
typedef union bdk_ap_tcr_el1 {
	uint64_t u;
	struct bdk_ap_tcr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t had1                        : 1;  /**< R/W - V8.1: Hierarchical Attribute Disable.
                                                                 HAD1(bit[42]): Hierarchical Attribute Disable for the TTBR1 region.
                                                                 0 = Hierarchical Attributes are enabled.
                                                                 1 = Hierarchical Attributes are disabled. */
		uint64_t had0                        : 1;  /**< R/W - V8.1: Hierarchical Attribute Disable.
                                                                 HAD0(bit[41]): Hierarchical Attribute Disable for the TTBR0 region.
                                                                 0 = Hierarchical Attributes are enabled.
                                                                 1 = Hierarchical Attributes are disabled. */
		uint64_t reserved_39_40              : 2;
		uint64_t tbi1                        : 1;  /**< R/W - Top Byte ignored - indicates whether the top byte of an
                                                                     address is used for address match for the AP_TTBR1_EL1 region, or
                                                                     ignored and used for tagged addresses.

                                                                 This affects addresses generated in EL0 and EL1 using AArch64
                                                                     where the address would be translated by tables pointed to by
                                                                     AP_TTBR1_EL1. It has an effect whether the EL1&0 translation
                                                                     regime is enabled or not.

                                                                 Additionally, this affects changes to the program counter,
                                                                     when TBI1 is 1 and bit [55] of the target address is 1, caused
                                                                     by:

                                                                  A branch or procedure return within EL0 or EL1.

                                                                  An exception taken to EL1.

                                                                  An exception return to EL0 or EL1.

                                                                 In these cases bits [63:56] of the address are also set to 1
                                                                     before it is stored in the PC.
                                                                 0 = Top Byte used in the address calculation.
                                                                 1 = Top Byte ignored in the address calculation. */
		uint64_t tbi0                        : 1;  /**< R/W - Top Byte ignored - indicates whether the top byte of an
                                                                     address is used for address match for the AP_TTBR0_EL1 region, or
                                                                     ignored and used for tagged addresses.

                                                                 This affects addresses generated in EL0 and EL1 using AArch64
                                                                     where the address would be translated by tables pointed to by
                                                                     AP_TTBR0_EL1. It has an effect whether the EL1&0 translation
                                                                     regime is enabled or not.

                                                                 Additionally, this affects changes to the program counter,
                                                                     when TBI0 is 1 and bit [55] of the target address is 0, caused
                                                                     by:

                                                                  A branch or procedure return within EL0 or EL1.

                                                                  An exception taken to EL1.

                                                                  An exception return to EL0 or EL1.

                                                                 In these cases bits [63:56] of the address are also set to 0
                                                                     before it is stored in the PC.
                                                                 0 = Top Byte used in the address calculation.
                                                                 1 = Top Byte ignored in the address calculation. */
		uint64_t as                          : 1;  /**< R/W - ASID Size.
                                                                 If the implementation has only 8 bits of ASID, this field is
                                                                     RES0.
                                                                 0 = 8 bit - the upper 8 bits of AP_TTBR0_EL1 and AP_TTBR1_EL1 are
                                                                     ignored by hardware for every purpose except reading back the
                                                                     register, and are treated as if they are all zeros for when
                                                                     used for allocation and matching entries in the TLB.
                                                                 1 = 16 bit - the upper 16 bits of AP_TTBR0_EL1 and AP_TTBR1_EL1 are used
                                                                     for allocation and matching in the TLB. */
		uint64_t reserved_35_35              : 1;
		uint64_t ips                         : 3;  /**< R/W - Intermediate Physical Address Size.
                                                                 0x0 = 32 bits, 4GB.
                                                                 0x1 = 36 bits, 64GB.
                                                                 0x2 = 40 bits, 1TB.
                                                                 0x3 = 42 bits, 4TB.
                                                                 0x4 = 44 bits, 16TB.
                                                                 0x5 = 48 bits, 256TB. */
		uint64_t tg1                         : 2;  /**< R/W - AP_TTBR1_EL1 Granule size.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.

                                                                 0x1 = 16KB
                                                                 0x2 = 4KB
                                                                 0x3 = 64KB */
		uint64_t sh1                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_TTBR1_EL1.
                                                                 0x0 = Non-shareable
                                                                 0x2 = Outer Shareable
                                                                 0x3 = Inner Shareable */
		uint64_t orgn1                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR1_EL1.
                                                                 0x0 = Normal memory, Outer Non-cacheable
                                                                 0x1 = Normal memory, Outer Write-Back Write-Allocate Cacheable
                                                                 0x2 = Normal memory, Outer Write-Through Cacheable
                                                                 0x3 = Normal memory, Outer Write-Back no Write-Allocate Cacheable */
		uint64_t irgn1                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR1_EL1.
                                                                 0x0 = Normal memory, Inner Non-cacheable
                                                                 0x1 = Normal memory, Inner Write-Back Write-Allocate Cacheable
                                                                 0x2 = Normal memory, Inner Write-Through Cacheable
                                                                 0x3 = Normal memory, Inner Write-Back no Write-Allocate Cacheable */
		uint64_t epd1                        : 1;  /**< R/W - Translation table walk disable for translations using
                                                                     AP_TTBR1_EL1. This bit controls whether a translation table walk
                                                                     is performed on a TLB miss, for an address that is translated
                                                                     using AP_TTBR1_EL1. The encoding of this bit is:
                                                                 0 = Perform translation table walks using AP_TTBR1_EL1.
                                                                 1 = A TLB miss on an address that is translated using AP_TTBR1_EL1
                                                                     generates a Translation fault. No translation table walk is
                                                                     performed. */
		uint64_t a1                          : 1;  /**< R/W - Selects whether AP_TTBR0_EL1 or AP_TTBR1_EL1 defines the ASID.
                                                                 0 =  AP_TTBR0_EL1[ASID] defines the ASID.
                                                                 1 =  AP_TTBR1_EL1[ASID] defines the ASID. */
		uint64_t t1sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_TTBR1_EL1.
                                                                     The region size is 22^(64-T1SZ) bytes.
                                                                 The maximum and minimum possible values for T1SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
		uint64_t tg0                         : 2;  /**< R/W - Granule size for the corresponding translation table base
                                                                     address register.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.

                                                                 0x0 = 4KB.
                                                                 0x1 = 64KB.
                                                                 0x2 = 16KB. */
		uint64_t sh0                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_TTBR0_EL1.
                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Inner Shareable. */
		uint64_t orgn0                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL1.
                                                                 0x0 = Normal memory, Outer Non-cacheable.
                                                                 0x1 = Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Outer Write-Through Cacheable.
                                                                 0x3 = Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
		uint64_t irgn0                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL1.
                                                                 0x0 = Normal memory, Inner Non-cacheable.
                                                                 0x1 = Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Inner Write-Through Cacheable.
                                                                 0x3 = Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
		uint64_t epd0                        : 1;  /**< R/W - Translation table walk disable for translations using TTBR0.
                                                                     This bit controls whether a translation table walk is
                                                                     performed on a TLB miss, for an address that is translated
                                                                     using TTBR0.
                                                                 0 = Perform translation table walks using TTBR0.
                                                                 1 = A TLB miss on an address that is translated using TTBR0
                                                                     generates a Translation fault. No translation table walk is
                                                                     performed. */
		uint64_t reserved_6_6                : 1;
		uint64_t t0sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_TTBR0_EL1.
                                                                     The region size is 2^(64-T0SZ) bytes.

                                                                 The maximum and minimum possible values for T0SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
#else
		uint64_t t0sz                        : 6;
		uint64_t reserved_6_6                : 1;
		uint64_t epd0                        : 1;
		uint64_t irgn0                       : 2;
		uint64_t orgn0                       : 2;
		uint64_t sh0                         : 2;
		uint64_t tg0                         : 2;
		uint64_t t1sz                        : 6;
		uint64_t a1                          : 1;
		uint64_t epd1                        : 1;
		uint64_t irgn1                       : 2;
		uint64_t orgn1                       : 2;
		uint64_t sh1                         : 2;
		uint64_t tg1                         : 2;
		uint64_t ips                         : 3;
		uint64_t reserved_35_35              : 1;
		uint64_t as                          : 1;
		uint64_t tbi0                        : 1;
		uint64_t tbi1                        : 1;
		uint64_t reserved_39_40              : 2;
		uint64_t had0                        : 1;
		uint64_t had1                        : 1;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_ap_tcr_el1_s            cn88xx; */
	/* struct bdk_ap_tcr_el1_s            cn88xxp1; */
} bdk_ap_tcr_el1_t;

#define BDK_AP_TCR_EL1 BDK_AP_TCR_EL1_FUNC()
static inline uint64_t BDK_AP_TCR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TCR_EL1_FUNC(void)
{
	return 0x0000030002000200ull;
}
#define typedef_BDK_AP_TCR_EL1 bdk_ap_tcr_el1_t
#define bustype_BDK_AP_TCR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TCR_EL1 0
#define arguments_BDK_AP_TCR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_TCR_EL1 "AP_TCR_EL1"


/**
 * SYSREG - ap_tcr_el12
 *
 * Alias of AP_TCR_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_tcr_el12 {
	uint64_t u;
	struct bdk_ap_tcr_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_tcr_el12_s           cn88xx; */
	/* struct bdk_ap_tcr_el12_s           cn88xxp1; */
} bdk_ap_tcr_el12_t;

#define BDK_AP_TCR_EL12 BDK_AP_TCR_EL12_FUNC()
static inline uint64_t BDK_AP_TCR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TCR_EL12_FUNC(void)
{
	return 0x0000030502000200ull;
}
#define typedef_BDK_AP_TCR_EL12 bdk_ap_tcr_el12_t
#define bustype_BDK_AP_TCR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TCR_EL12 0
#define arguments_BDK_AP_TCR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_TCR_EL12 "AP_TCR_EL12"


/**
 * SYSREG - ap_tcr_el2
 *
 * Controls translation table walks required for the stage 1
 *     translation of memory accesses from EL2, and holds
 *     cacheability and shareability information for the accesses.
 *
 * This register is at the same select as AP_TCR_EL2_E2H and is used when E2H=0.
 */
typedef union bdk_ap_tcr_el2 {
	uint32_t u;
	struct bdk_ap_tcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rsvd_31                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_25_30              : 6;
		uint32_t had                         : 1;  /**< R/W - V8.1: Hierarchical Attribute Disable.
                                                                 HAD (bit[24]): Hierarchical Attribute Disable.
                                                                 0 = Hierarchical Attributes are enabled.
                                                                 1 = Hierarchical Attributes are disabled. */
		uint32_t rsvd_23                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_21_22              : 2;
		uint32_t tbi                         : 1;  /**< R/W - Top Byte ignored - indicates whether the top byte of an
                                                                     address is used for address match for the AP_TTBR0_EL3 region, or
                                                                     ignored and used for tagged addresses.

                                                                 This affects addresses generated in EL3 using AArch64 where
                                                                     the address would be translated by tables pointed to by
                                                                     AP_TTBR0_EL3. It has an effect whether the EL3 translation regime
                                                                     is enabled or not.

                                                                 Additionally, this affects changes to the program counter,
                                                                     when TBI is 1, caused by:
                                                                 * A branch or procedure return within EL3.
                                                                 * A exception taken to EL3.
                                                                 * An exception return to EL3.

                                                                 In these cases bits [63:56] of the address are set to 0 before
                                                                     it is stored in the PC.
                                                                 0 = Top Byte used in the address calculation.
                                                                 1 = Top Byte ignored in the address calculation. */
		uint32_t reserved_19_19              : 1;
		uint32_t ps                          : 3;  /**< R/W - Physical Address Size.

                                                                 The reserved values behave in the same way as the0b101
                                                                 0x0 = 32 bits, 4GB.
                                                                 0x1 = 36 bits, 64GB.
                                                                 0x2 = 40 bits, 1TB.
                                                                 0x3 = 42 bits, 4TB.
                                                                 0x4 = 44 bits, 16TB.
                                                                 0x5 = 48 bits, 256TB. */
		uint32_t tg0                         : 2;  /**< R/W - Granule size for the corresponding translation table base
                                                                     address register.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.

                                                                 0x0 = 4KB.
                                                                 0x1 = 64KB.
                                                                 0x2 = 16KB. */
		uint32_t sh0                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_TTBR0_EL3.

                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Inner Shareable. */
		uint32_t orgn0                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL3.
                                                                 0x0 = Normal memory, Outer Non-cacheable.
                                                                 0x1 = Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Outer Write-Through Cacheable.
                                                                 0x3 = Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
		uint32_t irgn0                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL3.
                                                                 0x0 = Normal memory, Inner Non-cacheable.
                                                                 0x1 = Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Inner Write-Through Cacheable.
                                                                 0x3 = Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
		uint32_t reserved_6_7                : 2;
		uint32_t t0sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_TTBR0_EL3.
                                                                     The region size is 22^(64-T0SZ) bytes.

                                                                 The maximum and minimum possible values for T0SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
#else
		uint32_t t0sz                        : 6;
		uint32_t reserved_6_7                : 2;
		uint32_t irgn0                       : 2;
		uint32_t orgn0                       : 2;
		uint32_t sh0                         : 2;
		uint32_t tg0                         : 2;
		uint32_t ps                          : 3;
		uint32_t reserved_19_19              : 1;
		uint32_t tbi                         : 1;
		uint32_t reserved_21_22              : 2;
		uint32_t rsvd_23                     : 1;
		uint32_t had                         : 1;
		uint32_t reserved_25_30              : 6;
		uint32_t rsvd_31                     : 1;
#endif
	} s;
	/* struct bdk_ap_tcr_el2_s            cn88xx; */
	/* struct bdk_ap_tcr_el2_s            cn88xxp1; */
} bdk_ap_tcr_el2_t;

#define BDK_AP_TCR_EL2 BDK_AP_TCR_EL2_FUNC()
static inline uint64_t BDK_AP_TCR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TCR_EL2_FUNC(void)
{
	return 0x0000030402000200ull;
}
#define typedef_BDK_AP_TCR_EL2 bdk_ap_tcr_el2_t
#define bustype_BDK_AP_TCR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TCR_EL2 0
#define arguments_BDK_AP_TCR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_TCR_EL2 "AP_TCR_EL2"


/**
 * SYSREG - ap_tcr_el2_e2h
 *
 * [v8.1] Determines which of the Translation Table Base Registers
 *     defined the base address for a translation table walk required
 *     for the stage 1 translation of a memory access from EL2.  Also
 *     controls the translation table format and holds cacheability and
 *     shareability information.
 *
 * This register is at the same select as AP_TCR_EL2 and is used when E2H=1.
 */
typedef union bdk_ap_tcr_el2_e2h {
	uint64_t u;
	struct bdk_ap_tcr_el2_e2h_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t had1                        : 1;  /**< R/W - V8.1: Hierarchical Attribute Disable.
                                                                 HAD1(bit[42]): Hierarchical Attribute Disable for the TTBR1 region.
                                                                 0 = Hierarchical Attributes are enabled.
                                                                 1 = Hierarchical Attributes are disabled. */
		uint64_t had0                        : 1;  /**< R/W - V8.1: Hierarchical Attribute Disable.
                                                                 HAD0(bit[41]): Hierarchical Attribute Disable for the TTBR0 region.
                                                                 0 = Hierarchical Attributes are enabled.
                                                                 1 = Hierarchical Attributes are disabled. */
		uint64_t reserved_39_40              : 2;
		uint64_t tbi1                        : 1;  /**< R/W - Top Byte ignored - indicates whether the top byte of an
                                                                     address is used for address match for the AP_TTBR1_EL2 region, or
                                                                     ignored and used for tagged addresses.

                                                                 This affects addresses generated in EL2 using AArch64
                                                                     where the address would be translated by tables pointed to by
                                                                     AP_TTBR1_EL2. It has an effect whether the EL2 translation
                                                                     regime is enabled or not.

                                                                 Additionally, this affects changes to the program counter,
                                                                     when TBI1 is 1 and bit [55] of the target address is 1, caused
                                                                     by:
                                                                 * A branch or procedure return within EL2.
                                                                 * An exception taken to EL2.
                                                                 * An exception return to EL2.

                                                                 In these cases bits [63:56] of the address are also set to 1
                                                                     before it is stored in the PC.
                                                                 0 = Top Byte used in the address calculation.
                                                                 1 = Top Byte ignored in the address calculation. */
		uint64_t tbi0                        : 1;  /**< R/W - Top Byte ignored - indicates whether the top byte of an
                                                                     address is used for address match for the AP_TTBR0_EL2 region, or
                                                                     ignored and used for tagged addresses.

                                                                 This affects addresses generated in EL2 using AArch64
                                                                     where the address would be translated by tables pointed to by
                                                                     AP_TTBR0_EL2. It has an effect whether the EL2 translation
                                                                     regime is enabled or not.

                                                                 Additionally, this affects changes to the program counter,
                                                                     when TBI0 is 1 and bit [55] of the target address is 0, caused
                                                                     by:
                                                                 * A branch or procedure return within EL2.
                                                                 * An exception taken to EL2.
                                                                 * An exception return to EL2.

                                                                 In these cases bits [63:56] of the address are also set to 0
                                                                     before it is stored in the PC.
                                                                 0 = Top Byte used in the address calculation.
                                                                 1 = Top Byte ignored in the address calculation. */
		uint64_t as                          : 1;  /**< R/W - ASID Size.
                                                                 If the implementation has only 8 bits of ASID, this field is
                                                                     RES0.
                                                                 0 = 8 bit - the upper 8 bits of AP_TTBR0_EL2 and AP_TTBR1_EL2 are
                                                                     ignored by hardware for every purpose except reading back the
                                                                     register, and are treated as if they are all zeros for when
                                                                     used for allocation and matching entries in the TLB.
                                                                 1 = 16 bit - the upper 16 bits of AP_TTBR0_EL2 and AP_TTBR1_EL2 are used
                                                                     for allocation and matching in the TLB. */
		uint64_t reserved_35_35              : 1;
		uint64_t ips                         : 3;  /**< R/W - Intermediate Physical Address Size.
                                                                 0x0 = 32 bits, 4GB.
                                                                 0x1 = 36 bits, 64GB.
                                                                 0x2 = 40 bits, 1TB.
                                                                 0x3 = 42 bits, 4TB.
                                                                 0x4 = 44 bits, 16TB.
                                                                 0x5 = 48 bits, 256TB. */
		uint64_t tg1                         : 2;  /**< R/W - AP_TTBR1_EL2 Granule size.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.

                                                                 0x1 = 16KB.
                                                                 0x2 = 4KB.
                                                                 0x3 = 64KB. */
		uint64_t sh1                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_TTBR1_EL2.

                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Inner Shareable. */
		uint64_t orgn1                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR1_EL2.
                                                                 0x0 = Normal memory, Outer Non-cacheable.
                                                                 0x1 = Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Outer Write-Through Cacheable.
                                                                 0x3 = Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
		uint64_t irgn1                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR1_EL2.
                                                                 0x0 = Normal memory, Inner Non-cacheable.
                                                                 0x1 = Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Inner Write-Through Cacheable.
                                                                 0x3 = Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
		uint64_t epd1                        : 1;  /**< R/W - Translation table walk disable for translations using
                                                                     AP_TTBR1_EL2. This bit controls whether a translation table walk
                                                                     is performed on a TLB miss, for an address that is translated
                                                                     using AP_TTBR1_EL2. The encoding of this bit is:
                                                                 0 = Perform translation table walks using AP_TTBR1_EL2.
                                                                 1 = A TLB miss on an address that is translated using AP_TTBR1_EL2
                                                                     generates a Translation fault. No translation table walk is
                                                                     performed. */
		uint64_t a1                          : 1;  /**< R/W - Selects whether AP_TTBR0_EL2 or AP_TTBR1_EL2 defines the ASID. The
                                                                     encoding of this bit is:
                                                                 0 =  AP_TTBR0_EL2[ASID] defines the ASID.
                                                                 1 =  AP_TTBR1_EL2[ASID] defines the ASID. */
		uint64_t t1sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_TTBR1_EL2.
                                                                     The region size is 22^(64-T1SZ) bytes.
                                                                 The maximum and minimum possible values for T1SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
		uint64_t tg0                         : 2;  /**< R/W - Granule size for the corresponding translation table base
                                                                     address register.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.

                                                                 0x0 = 4KB.
                                                                 0x1 = 64KB.
                                                                 0x2 = 16KB. */
		uint64_t sh0                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_TTBR0_EL2.

                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Inner Shareable. */
		uint64_t orgn0                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL2.
                                                                 0x0 = Normal memory, Outer Non-cacheable.
                                                                 0x1 = Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Outer Write-Through Cacheable.
                                                                 0x3 = Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
		uint64_t irgn0                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL2.
                                                                 0x0 = Normal memory, Inner Non-cacheable.
                                                                 0x1 = Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Inner Write-Through Cacheable.
                                                                 0x3 = Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
		uint64_t epd0                        : 1;  /**< R/W - Translation table walk disable for translations using TTBR0.
                                                                     This bit controls whether a translation table walk is
                                                                     performed on a TLB miss, for an address that is translated
                                                                     using TTBR0. The encoding of this bit is:
                                                                 0 = Perform translation table walks using TTBR0.
                                                                 1 = A TLB miss on an address that is translated using TTBR0
                                                                     generates a Translation fault. No translation table walk is
                                                                     performed. */
		uint64_t reserved_6_6                : 1;
		uint64_t t0sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_TTBR0_EL2.
                                                                     The region size is 22^(64-T0SZ) bytes.
                                                                 The maximum and minimum possible values for T0SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
#else
		uint64_t t0sz                        : 6;
		uint64_t reserved_6_6                : 1;
		uint64_t epd0                        : 1;
		uint64_t irgn0                       : 2;
		uint64_t orgn0                       : 2;
		uint64_t sh0                         : 2;
		uint64_t tg0                         : 2;
		uint64_t t1sz                        : 6;
		uint64_t a1                          : 1;
		uint64_t epd1                        : 1;
		uint64_t irgn1                       : 2;
		uint64_t orgn1                       : 2;
		uint64_t sh1                         : 2;
		uint64_t tg1                         : 2;
		uint64_t ips                         : 3;
		uint64_t reserved_35_35              : 1;
		uint64_t as                          : 1;
		uint64_t tbi0                        : 1;
		uint64_t tbi1                        : 1;
		uint64_t reserved_39_40              : 2;
		uint64_t had0                        : 1;
		uint64_t had1                        : 1;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_ap_tcr_el2_e2h_s        cn88xx; */
	/* struct bdk_ap_tcr_el2_e2h_s        cn88xxp1; */
} bdk_ap_tcr_el2_e2h_t;

#define BDK_AP_TCR_EL2_E2H BDK_AP_TCR_EL2_E2H_FUNC()
static inline uint64_t BDK_AP_TCR_EL2_E2H_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TCR_EL2_E2H_FUNC(void)
{
	return 0x0000030402000210ull;
}
#define typedef_BDK_AP_TCR_EL2_E2H bdk_ap_tcr_el2_e2h_t
#define bustype_BDK_AP_TCR_EL2_E2H BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TCR_EL2_E2H 0
#define arguments_BDK_AP_TCR_EL2_E2H -1,-1,-1,-1
#define basename_BDK_AP_TCR_EL2_E2H "AP_TCR_EL2_E2H"


/**
 * SYSREG - ap_tcr_el3
 *
 * Controls translation table walks required for the stage 1
 * translation of memory accesses from EL3, and holds
 * cacheability and shareability information for the accesses.
 */
typedef union bdk_ap_tcr_el3 {
	uint32_t u;
	struct bdk_ap_tcr_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rsvd_31                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_25_30              : 6;
		uint32_t had                         : 1;  /**< R/W - V8.1: Hierarchical Attribute Disable.
                                                                 HAD (bit[24]): Hierarchical Attribute Disable.
                                                                 0 = Hierarchical Attributes are enabled.
                                                                 1 = Hierarchical Attributes are disabled. */
		uint32_t rsvd_23                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_21_22              : 2;
		uint32_t tbi                         : 1;  /**< R/W - Top Byte ignored - indicates whether the top byte of an
                                                                     address is used for address match for the AP_TTBR0_EL3 region, or
                                                                     ignored and used for tagged addresses.

                                                                 This affects addresses generated in EL3 using AArch64 where
                                                                     the address would be translated by tables pointed to by
                                                                     AP_TTBR0_EL3. It has an effect whether the EL3 translation regime
                                                                     is enabled or not.

                                                                 Additionally, this affects changes to the program counter,
                                                                     when TBI is 1, caused by:
                                                                 * A branch or procedure return within EL3.
                                                                 * A exception taken to EL3.
                                                                 * An exception return to EL3.

                                                                 In these cases bits [63:56] of the address are set to 0 before
                                                                     it is stored in the PC.
                                                                 0 = Top Byte used in the address calculation.
                                                                 1 = Top Byte ignored in the address calculation. */
		uint32_t reserved_19_19              : 1;
		uint32_t ps                          : 3;  /**< R/W - Physical Address Size.

                                                                 The reserved values behave in the same way as the0b101
                                                                 0x0 = 32 bits, 4GB.
                                                                 0x1 = 36 bits, 64GB.
                                                                 0x2 = 40 bits, 1TB.
                                                                 0x3 = 42 bits, 4TB.
                                                                 0x4 = 44 bits, 16TB.
                                                                 0x5 = 48 bits, 256TB. */
		uint32_t tg0                         : 2;  /**< R/W - Granule size for the corresponding translation table base
                                                                     address register.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.
                                                                 0x0 = 4KB.
                                                                 0x1 = 64KB.
                                                                 0x2 = 16KB. */
		uint32_t sh0                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_TTBR0_EL3.
                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer Shareable.
                                                                 0x3 = Inner Shareable. */
		uint32_t orgn0                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL3.
                                                                 0x0 = Normal memory, Outer Non-cacheable.
                                                                 0x1 = Normal memory, Outer Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Outer Write-Through Cacheable.
                                                                 0x3 = Normal memory, Outer Write-Back no Write-Allocate Cacheable. */
		uint32_t irgn0                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_TTBR0_EL3.
                                                                 0x0 = Normal memory, Inner Non-cacheable.
                                                                 0x1 = Normal memory, Inner Write-Back Write-Allocate Cacheable.
                                                                 0x2 = Normal memory, Inner Write-Through Cacheable.
                                                                 0x3 = Normal memory, Inner Write-Back no Write-Allocate Cacheable. */
		uint32_t reserved_6_7                : 2;
		uint32_t t0sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_TTBR0_EL3.
                                                                     The region size is 22^(64-T0SZ) bytes.
                                                                 The maximum and minimum possible values for T0SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
#else
		uint32_t t0sz                        : 6;
		uint32_t reserved_6_7                : 2;
		uint32_t irgn0                       : 2;
		uint32_t orgn0                       : 2;
		uint32_t sh0                         : 2;
		uint32_t tg0                         : 2;
		uint32_t ps                          : 3;
		uint32_t reserved_19_19              : 1;
		uint32_t tbi                         : 1;
		uint32_t reserved_21_22              : 2;
		uint32_t rsvd_23                     : 1;
		uint32_t had                         : 1;
		uint32_t reserved_25_30              : 6;
		uint32_t rsvd_31                     : 1;
#endif
	} s;
	/* struct bdk_ap_tcr_el3_s            cn88xx; */
	/* struct bdk_ap_tcr_el3_s            cn88xxp1; */
} bdk_ap_tcr_el3_t;

#define BDK_AP_TCR_EL3 BDK_AP_TCR_EL3_FUNC()
static inline uint64_t BDK_AP_TCR_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TCR_EL3_FUNC(void)
{
	return 0x0000030602000200ull;
}
#define typedef_BDK_AP_TCR_EL3 bdk_ap_tcr_el3_t
#define bustype_BDK_AP_TCR_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TCR_EL3 0
#define arguments_BDK_AP_TCR_EL3 -1,-1,-1,-1
#define basename_BDK_AP_TCR_EL3 "AP_TCR_EL3"


/**
 * SYSREG - ap_teecr32_el1
 *
 * Allows access to the AArch32 register TEECR from AArch64 state
 * only. Its value has no effect on execution in AArch64 state.
 */
typedef union bdk_ap_teecr32_el1 {
	uint32_t u;
	struct bdk_ap_teecr32_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t xed                         : 1;  /**< R/W - Execution Environment Disable bit. Control unprivileged access
                                                                     to TEEHBR.

                                                                 The effects of a write to this register on T32EE configuration
                                                                     are only guaranteed to be visible to subsequent instructions
                                                                     after the execution of a context synchronization operation.
                                                                     However, a read of this register always returns the value most
                                                                     recently written to the register.
                                                                 0 = Unprivileged access permitted.
                                                                 1 = Unprivileged access disabled. */
#else
		uint32_t xed                         : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ap_teecr32_el1_s        cn88xx; */
	/* struct bdk_ap_teecr32_el1_s        cn88xxp1; */
} bdk_ap_teecr32_el1_t;

#define BDK_AP_TEECR32_EL1 BDK_AP_TEECR32_EL1_FUNC()
static inline uint64_t BDK_AP_TEECR32_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TEECR32_EL1_FUNC(void)
{
	return 0x0000020200000000ull;
}
#define typedef_BDK_AP_TEECR32_EL1 bdk_ap_teecr32_el1_t
#define bustype_BDK_AP_TEECR32_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TEECR32_EL1 0
#define arguments_BDK_AP_TEECR32_EL1 -1,-1,-1,-1
#define basename_BDK_AP_TEECR32_EL1 "AP_TEECR32_EL1"


/**
 * SYSREG - ap_teehbr32_el1
 *
 * Allows access to the AArch32 register TEEHBR from AArch64
 * state only. Its value has no effect on execution in AArch64
 * state.
 */
typedef union bdk_ap_teehbr32_el1 {
	uint32_t u;
	struct bdk_ap_teehbr32_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t handlerbase                 : 30; /**< R/W - The address of the T32EE Handler_00 implementation. This is
                                                                 the address of the first of the T32EE handlers. */
		uint32_t reserved_0_1                : 2;
#else
		uint32_t reserved_0_1                : 2;
		uint32_t handlerbase                 : 30;
#endif
	} s;
	/* struct bdk_ap_teehbr32_el1_s       cn88xx; */
	/* struct bdk_ap_teehbr32_el1_s       cn88xxp1; */
} bdk_ap_teehbr32_el1_t;

#define BDK_AP_TEEHBR32_EL1 BDK_AP_TEEHBR32_EL1_FUNC()
static inline uint64_t BDK_AP_TEEHBR32_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TEEHBR32_EL1_FUNC(void)
{
	return 0x0000020201000000ull;
}
#define typedef_BDK_AP_TEEHBR32_EL1 bdk_ap_teehbr32_el1_t
#define bustype_BDK_AP_TEEHBR32_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TEEHBR32_EL1 0
#define arguments_BDK_AP_TEEHBR32_EL1 -1,-1,-1,-1
#define basename_BDK_AP_TEEHBR32_EL1 "AP_TEEHBR32_EL1"


/**
 * SYSREG - ap_tpidr_el#
 *
 * Provides a location where software executing at EL3 can store
 * thread identifying information, for OS management purposes.
 */
typedef union bdk_ap_tpidr_elx {
	uint64_t u;
	struct bdk_ap_tpidr_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Thread ID. Thread identifying information stored by software
                                                                 running at this Exception level. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_tpidr_elx_s          cn88xx; */
	/* struct bdk_ap_tpidr_elx_s          cn88xxp1; */
} bdk_ap_tpidr_elx_t;

static inline uint64_t BDK_AP_TPIDR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TPIDR_ELX(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 3))))
		return 0x000003000D000200ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_TPIDR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TPIDR_ELX(...) bdk_ap_tpidr_elx_t
#define bustype_BDK_AP_TPIDR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TPIDR_ELX(p1) (p1)
#define arguments_BDK_AP_TPIDR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TPIDR_ELX(...) "AP_TPIDR_ELX"


/**
 * SYSREG - ap_tpidr_el0
 *
 * Provides a location where software executing at EL0 can store
 * thread identifying information, for OS management purposes.
 */
typedef union bdk_ap_tpidr_el0 {
	uint64_t u;
	struct bdk_ap_tpidr_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Thread ID. Thread identifying information stored by software
                                                                 running at this Exception level. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_tpidr_el0_s          cn88xx; */
	/* struct bdk_ap_tpidr_el0_s          cn88xxp1; */
} bdk_ap_tpidr_el0_t;

#define BDK_AP_TPIDR_EL0 BDK_AP_TPIDR_EL0_FUNC()
static inline uint64_t BDK_AP_TPIDR_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TPIDR_EL0_FUNC(void)
{
	return 0x000003030D000200ull;
}
#define typedef_BDK_AP_TPIDR_EL0 bdk_ap_tpidr_el0_t
#define bustype_BDK_AP_TPIDR_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TPIDR_EL0 0
#define arguments_BDK_AP_TPIDR_EL0 -1,-1,-1,-1
#define basename_BDK_AP_TPIDR_EL0 "AP_TPIDR_EL0"


/**
 * SYSREG - ap_tpidr_el1
 *
 * Provides a location where software executing at EL1 can store
 * thread identifying information, for OS management purposes.
 */
typedef union bdk_ap_tpidr_el1 {
	uint64_t u;
	struct bdk_ap_tpidr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Thread ID. Thread identifying information stored by software
                                                                 running at this Exception level. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_tpidr_el1_s          cn88xx; */
	/* struct bdk_ap_tpidr_el1_s          cn88xxp1; */
} bdk_ap_tpidr_el1_t;

#define BDK_AP_TPIDR_EL1 BDK_AP_TPIDR_EL1_FUNC()
static inline uint64_t BDK_AP_TPIDR_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TPIDR_EL1_FUNC(void)
{
	return 0x000003000D000400ull;
}
#define typedef_BDK_AP_TPIDR_EL1 bdk_ap_tpidr_el1_t
#define bustype_BDK_AP_TPIDR_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TPIDR_EL1 0
#define arguments_BDK_AP_TPIDR_EL1 -1,-1,-1,-1
#define basename_BDK_AP_TPIDR_EL1 "AP_TPIDR_EL1"


/**
 * SYSREG - ap_tpidrro_el0
 *
 * Provides a location where software executing at EL1 or higher
 * can store thread identifying information that is visible to
 * software executing at EL0, for OS management purposes.
 */
typedef union bdk_ap_tpidrro_el0 {
	uint64_t u;
	struct bdk_ap_tpidrro_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Thread ID. Thread identifying information stored by software
                                                                 running at this Exception level. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ap_tpidrro_el0_s        cn88xx; */
	/* struct bdk_ap_tpidrro_el0_s        cn88xxp1; */
} bdk_ap_tpidrro_el0_t;

#define BDK_AP_TPIDRRO_EL0 BDK_AP_TPIDRRO_EL0_FUNC()
static inline uint64_t BDK_AP_TPIDRRO_EL0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TPIDRRO_EL0_FUNC(void)
{
	return 0x000003030D000300ull;
}
#define typedef_BDK_AP_TPIDRRO_EL0 bdk_ap_tpidrro_el0_t
#define bustype_BDK_AP_TPIDRRO_EL0 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TPIDRRO_EL0 0
#define arguments_BDK_AP_TPIDRRO_EL0 -1,-1,-1,-1
#define basename_BDK_AP_TPIDRRO_EL0 "AP_TPIDRRO_EL0"


/**
 * SYSREG - ap_trcacatr#
 */
typedef union bdk_ap_trcacatrx {
	uint64_t u;
	struct bdk_ap_trcacatrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcacatrx_s          cn88xx; */
	/* struct bdk_ap_trcacatrx_s          cn88xxp1; */
} bdk_ap_trcacatrx_t;

static inline uint64_t BDK_AP_TRCACATRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCACATRX(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000020102000200ull + (param1 & 15) * 0x20000ull;
	csr_fatal("BDK_AP_TRCACATRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCACATRX(...) bdk_ap_trcacatrx_t
#define bustype_BDK_AP_TRCACATRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCACATRX(p1) (p1)
#define arguments_BDK_AP_TRCACATRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCACATRX(...) "AP_TRCACATRX"


/**
 * SYSREG - ap_trcacvr#
 */
typedef union bdk_ap_trcacvrx {
	uint64_t u;
	struct bdk_ap_trcacvrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcacvrx_s           cn88xx; */
	/* struct bdk_ap_trcacvrx_s           cn88xxp1; */
} bdk_ap_trcacvrx_t;

static inline uint64_t BDK_AP_TRCACVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCACVRX(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000020102000000ull + (param1 & 15) * 0x20000ull;
	csr_fatal("BDK_AP_TRCACVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCACVRX(...) bdk_ap_trcacvrx_t
#define bustype_BDK_AP_TRCACVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCACVRX(p1) (p1)
#define arguments_BDK_AP_TRCACVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCACVRX(...) "AP_TRCACVRX"


/**
 * SYSREG - ap_trcauthstatus
 */
typedef union bdk_ap_trcauthstatus {
	uint64_t u;
	struct bdk_ap_trcauthstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcauthstatus_s      cn88xx; */
	/* struct bdk_ap_trcauthstatus_s      cn88xxp1; */
} bdk_ap_trcauthstatus_t;

#define BDK_AP_TRCAUTHSTATUS BDK_AP_TRCAUTHSTATUS_FUNC()
static inline uint64_t BDK_AP_TRCAUTHSTATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCAUTHSTATUS_FUNC(void)
{
	return 0x00000201070E0600ull;
}
#define typedef_BDK_AP_TRCAUTHSTATUS bdk_ap_trcauthstatus_t
#define bustype_BDK_AP_TRCAUTHSTATUS BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCAUTHSTATUS 0
#define arguments_BDK_AP_TRCAUTHSTATUS -1,-1,-1,-1
#define basename_BDK_AP_TRCAUTHSTATUS "AP_TRCAUTHSTATUS"


/**
 * SYSREG - ap_trcauxctlr
 */
typedef union bdk_ap_trcauxctlr {
	uint64_t u;
	struct bdk_ap_trcauxctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcauxctlr_s         cn88xx; */
	/* struct bdk_ap_trcauxctlr_s         cn88xxp1; */
} bdk_ap_trcauxctlr_t;

#define BDK_AP_TRCAUXCTLR BDK_AP_TRCAUXCTLR_FUNC()
static inline uint64_t BDK_AP_TRCAUXCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCAUXCTLR_FUNC(void)
{
	return 0x0000020100060000ull;
}
#define typedef_BDK_AP_TRCAUXCTLR bdk_ap_trcauxctlr_t
#define bustype_BDK_AP_TRCAUXCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCAUXCTLR 0
#define arguments_BDK_AP_TRCAUXCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCAUXCTLR "AP_TRCAUXCTLR"


/**
 * SYSREG - ap_trcbbctlr
 */
typedef union bdk_ap_trcbbctlr {
	uint64_t u;
	struct bdk_ap_trcbbctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcbbctlr_s          cn88xx; */
	/* struct bdk_ap_trcbbctlr_s          cn88xxp1; */
} bdk_ap_trcbbctlr_t;

#define BDK_AP_TRCBBCTLR BDK_AP_TRCBBCTLR_FUNC()
static inline uint64_t BDK_AP_TRCBBCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCBBCTLR_FUNC(void)
{
	return 0x00000201000F0000ull;
}
#define typedef_BDK_AP_TRCBBCTLR bdk_ap_trcbbctlr_t
#define bustype_BDK_AP_TRCBBCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCBBCTLR 0
#define arguments_BDK_AP_TRCBBCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCBBCTLR "AP_TRCBBCTLR"


/**
 * SYSREG - ap_trcccctlr
 */
typedef union bdk_ap_trcccctlr {
	uint64_t u;
	struct bdk_ap_trcccctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcccctlr_s          cn88xx; */
	/* struct bdk_ap_trcccctlr_s          cn88xxp1; */
} bdk_ap_trcccctlr_t;

#define BDK_AP_TRCCCCTLR BDK_AP_TRCCCCTLR_FUNC()
static inline uint64_t BDK_AP_TRCCCCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCCCTLR_FUNC(void)
{
	return 0x00000201000E0000ull;
}
#define typedef_BDK_AP_TRCCCCTLR bdk_ap_trcccctlr_t
#define bustype_BDK_AP_TRCCCCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCCCTLR 0
#define arguments_BDK_AP_TRCCCCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCCCCTLR "AP_TRCCCCTLR"


/**
 * SYSREG - ap_trccidcctlr#
 */
typedef union bdk_ap_trccidcctlrx {
	uint64_t u;
	struct bdk_ap_trccidcctlrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trccidcctlrx_s       cn88xx; */
	/* struct bdk_ap_trccidcctlrx_s       cn88xxp1; */
} bdk_ap_trccidcctlrx_t;

static inline uint64_t BDK_AP_TRCCIDCCTLRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCIDCCTLRX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000020103000200ull + (param1 & 1) * 0x10000ull;
	csr_fatal("BDK_AP_TRCCIDCCTLRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCCIDCCTLRX(...) bdk_ap_trccidcctlrx_t
#define bustype_BDK_AP_TRCCIDCCTLRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCIDCCTLRX(p1) (p1)
#define arguments_BDK_AP_TRCCIDCCTLRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCCIDCCTLRX(...) "AP_TRCCIDCCTLRX"


/**
 * SYSREG - ap_trccidcvr#
 */
typedef union bdk_ap_trccidcvrx {
	uint64_t u;
	struct bdk_ap_trccidcvrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trccidcvrx_s         cn88xx; */
	/* struct bdk_ap_trccidcvrx_s         cn88xxp1; */
} bdk_ap_trccidcvrx_t;

static inline uint64_t BDK_AP_TRCCIDCVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCIDCVRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020103000000ull + (param1 & 7) * 0x20000ull;
	csr_fatal("BDK_AP_TRCCIDCVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCCIDCVRX(...) bdk_ap_trccidcvrx_t
#define bustype_BDK_AP_TRCCIDCVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCIDCVRX(p1) (p1)
#define arguments_BDK_AP_TRCCIDCVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCCIDCVRX(...) "AP_TRCCIDCVRX"


/**
 * SYSREG - ap_trccidr#
 */
typedef union bdk_ap_trccidrx {
	uint64_t u;
	struct bdk_ap_trccidrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trccidrx_s           cn88xx; */
	/* struct bdk_ap_trccidrx_s           cn88xxp1; */
} bdk_ap_trccidrx_t;

static inline uint64_t BDK_AP_TRCCIDRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCIDRX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00000201070C0700ull + (param1 & 3) * 0x10000ull;
	csr_fatal("BDK_AP_TRCCIDRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCCIDRX(...) bdk_ap_trccidrx_t
#define bustype_BDK_AP_TRCCIDRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCIDRX(p1) (p1)
#define arguments_BDK_AP_TRCCIDRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCCIDRX(...) "AP_TRCCIDRX"


/**
 * SYSREG - ap_trcclaimclr
 */
typedef union bdk_ap_trcclaimclr {
	uint64_t u;
	struct bdk_ap_trcclaimclr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcclaimclr_s        cn88xx; */
	/* struct bdk_ap_trcclaimclr_s        cn88xxp1; */
} bdk_ap_trcclaimclr_t;

#define BDK_AP_TRCCLAIMCLR BDK_AP_TRCCLAIMCLR_FUNC()
static inline uint64_t BDK_AP_TRCCLAIMCLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCLAIMCLR_FUNC(void)
{
	return 0x0000020107090600ull;
}
#define typedef_BDK_AP_TRCCLAIMCLR bdk_ap_trcclaimclr_t
#define bustype_BDK_AP_TRCCLAIMCLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCLAIMCLR 0
#define arguments_BDK_AP_TRCCLAIMCLR -1,-1,-1,-1
#define basename_BDK_AP_TRCCLAIMCLR "AP_TRCCLAIMCLR"


/**
 * SYSREG - ap_trcclaimset
 */
typedef union bdk_ap_trcclaimset {
	uint64_t u;
	struct bdk_ap_trcclaimset_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcclaimset_s        cn88xx; */
	/* struct bdk_ap_trcclaimset_s        cn88xxp1; */
} bdk_ap_trcclaimset_t;

#define BDK_AP_TRCCLAIMSET BDK_AP_TRCCLAIMSET_FUNC()
static inline uint64_t BDK_AP_TRCCLAIMSET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCLAIMSET_FUNC(void)
{
	return 0x0000020107080600ull;
}
#define typedef_BDK_AP_TRCCLAIMSET bdk_ap_trcclaimset_t
#define bustype_BDK_AP_TRCCLAIMSET BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCLAIMSET 0
#define arguments_BDK_AP_TRCCLAIMSET -1,-1,-1,-1
#define basename_BDK_AP_TRCCLAIMSET "AP_TRCCLAIMSET"


/**
 * SYSREG - ap_trccntctlr#
 */
typedef union bdk_ap_trccntctlrx {
	uint64_t u;
	struct bdk_ap_trccntctlrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trccntctlrx_s        cn88xx; */
	/* struct bdk_ap_trccntctlrx_s        cn88xxp1; */
} bdk_ap_trccntctlrx_t;

static inline uint64_t BDK_AP_TRCCNTCTLRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCNTCTLRX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000020100040500ull + (param1 & 3) * 0x10000ull;
	csr_fatal("BDK_AP_TRCCNTCTLRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCCNTCTLRX(...) bdk_ap_trccntctlrx_t
#define bustype_BDK_AP_TRCCNTCTLRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCNTCTLRX(p1) (p1)
#define arguments_BDK_AP_TRCCNTCTLRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCCNTCTLRX(...) "AP_TRCCNTCTLRX"


/**
 * SYSREG - ap_trccntrldvr#
 */
typedef union bdk_ap_trccntrldvrx {
	uint64_t u;
	struct bdk_ap_trccntrldvrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trccntrldvrx_s       cn88xx; */
	/* struct bdk_ap_trccntrldvrx_s       cn88xxp1; */
} bdk_ap_trccntrldvrx_t;

static inline uint64_t BDK_AP_TRCCNTRLDVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCNTRLDVRX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000020100000500ull + (param1 & 3) * 0x10000ull;
	csr_fatal("BDK_AP_TRCCNTRLDVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCCNTRLDVRX(...) bdk_ap_trccntrldvrx_t
#define bustype_BDK_AP_TRCCNTRLDVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCNTRLDVRX(p1) (p1)
#define arguments_BDK_AP_TRCCNTRLDVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCCNTRLDVRX(...) "AP_TRCCNTRLDVRX"


/**
 * SYSREG - ap_trccntvr#
 */
typedef union bdk_ap_trccntvrx {
	uint64_t u;
	struct bdk_ap_trccntvrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trccntvrx_s          cn88xx; */
	/* struct bdk_ap_trccntvrx_s          cn88xxp1; */
} bdk_ap_trccntvrx_t;

static inline uint64_t BDK_AP_TRCCNTVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCNTVRX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000020100080500ull + (param1 & 3) * 0x10000ull;
	csr_fatal("BDK_AP_TRCCNTVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCCNTVRX(...) bdk_ap_trccntvrx_t
#define bustype_BDK_AP_TRCCNTVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCNTVRX(p1) (p1)
#define arguments_BDK_AP_TRCCNTVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCCNTVRX(...) "AP_TRCCNTVRX"


/**
 * SYSREG - ap_trcconfigr
 */
typedef union bdk_ap_trcconfigr {
	uint64_t u;
	struct bdk_ap_trcconfigr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcconfigr_s         cn88xx; */
	/* struct bdk_ap_trcconfigr_s         cn88xxp1; */
} bdk_ap_trcconfigr_t;

#define BDK_AP_TRCCONFIGR BDK_AP_TRCCONFIGR_FUNC()
static inline uint64_t BDK_AP_TRCCONFIGR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCCONFIGR_FUNC(void)
{
	return 0x0000020100040000ull;
}
#define typedef_BDK_AP_TRCCONFIGR bdk_ap_trcconfigr_t
#define bustype_BDK_AP_TRCCONFIGR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCCONFIGR 0
#define arguments_BDK_AP_TRCCONFIGR -1,-1,-1,-1
#define basename_BDK_AP_TRCCONFIGR "AP_TRCCONFIGR"


/**
 * SYSREG - ap_trcdevaff#
 */
typedef union bdk_ap_trcdevaffx {
	uint64_t u;
	struct bdk_ap_trcdevaffx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcdevaffx_s         cn88xx; */
	/* struct bdk_ap_trcdevaffx_s         cn88xxp1; */
} bdk_ap_trcdevaffx_t;

static inline uint64_t BDK_AP_TRCDEVAFFX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCDEVAFFX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00000201070A0600ull + (param1 & 1) * 0x10000ull;
	csr_fatal("BDK_AP_TRCDEVAFFX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCDEVAFFX(...) bdk_ap_trcdevaffx_t
#define bustype_BDK_AP_TRCDEVAFFX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCDEVAFFX(p1) (p1)
#define arguments_BDK_AP_TRCDEVAFFX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCDEVAFFX(...) "AP_TRCDEVAFFX"


/**
 * SYSREG - ap_trcdevarch
 */
typedef union bdk_ap_trcdevarch {
	uint64_t u;
	struct bdk_ap_trcdevarch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcdevarch_s         cn88xx; */
	/* struct bdk_ap_trcdevarch_s         cn88xxp1; */
} bdk_ap_trcdevarch_t;

#define BDK_AP_TRCDEVARCH BDK_AP_TRCDEVARCH_FUNC()
static inline uint64_t BDK_AP_TRCDEVARCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCDEVARCH_FUNC(void)
{
	return 0x00000201070F0600ull;
}
#define typedef_BDK_AP_TRCDEVARCH bdk_ap_trcdevarch_t
#define bustype_BDK_AP_TRCDEVARCH BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCDEVARCH 0
#define arguments_BDK_AP_TRCDEVARCH -1,-1,-1,-1
#define basename_BDK_AP_TRCDEVARCH "AP_TRCDEVARCH"


/**
 * SYSREG - ap_trcdevid
 */
typedef union bdk_ap_trcdevid {
	uint64_t u;
	struct bdk_ap_trcdevid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcdevid_s           cn88xx; */
	/* struct bdk_ap_trcdevid_s           cn88xxp1; */
} bdk_ap_trcdevid_t;

#define BDK_AP_TRCDEVID BDK_AP_TRCDEVID_FUNC()
static inline uint64_t BDK_AP_TRCDEVID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCDEVID_FUNC(void)
{
	return 0x0000020107020700ull;
}
#define typedef_BDK_AP_TRCDEVID bdk_ap_trcdevid_t
#define bustype_BDK_AP_TRCDEVID BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCDEVID 0
#define arguments_BDK_AP_TRCDEVID -1,-1,-1,-1
#define basename_BDK_AP_TRCDEVID "AP_TRCDEVID"


/**
 * SYSREG - ap_trcdevtype
 */
typedef union bdk_ap_trcdevtype {
	uint64_t u;
	struct bdk_ap_trcdevtype_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcdevtype_s         cn88xx; */
	/* struct bdk_ap_trcdevtype_s         cn88xxp1; */
} bdk_ap_trcdevtype_t;

#define BDK_AP_TRCDEVTYPE BDK_AP_TRCDEVTYPE_FUNC()
static inline uint64_t BDK_AP_TRCDEVTYPE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCDEVTYPE_FUNC(void)
{
	return 0x0000020107030700ull;
}
#define typedef_BDK_AP_TRCDEVTYPE bdk_ap_trcdevtype_t
#define bustype_BDK_AP_TRCDEVTYPE BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCDEVTYPE 0
#define arguments_BDK_AP_TRCDEVTYPE -1,-1,-1,-1
#define basename_BDK_AP_TRCDEVTYPE "AP_TRCDEVTYPE"


/**
 * SYSREG - ap_trcdvcmr#
 */
typedef union bdk_ap_trcdvcmrx {
	uint64_t u;
	struct bdk_ap_trcdvcmrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcdvcmrx_s          cn88xx; */
	/* struct bdk_ap_trcdvcmrx_s          cn88xxp1; */
} bdk_ap_trcdvcmrx_t;

static inline uint64_t BDK_AP_TRCDVCMRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCDVCMRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020102000600ull + (param1 & 7) * 0x40000ull;
	csr_fatal("BDK_AP_TRCDVCMRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCDVCMRX(...) bdk_ap_trcdvcmrx_t
#define bustype_BDK_AP_TRCDVCMRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCDVCMRX(p1) (p1)
#define arguments_BDK_AP_TRCDVCMRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCDVCMRX(...) "AP_TRCDVCMRX"


/**
 * SYSREG - ap_trcdvcvr#
 */
typedef union bdk_ap_trcdvcvrx {
	uint64_t u;
	struct bdk_ap_trcdvcvrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcdvcvrx_s          cn88xx; */
	/* struct bdk_ap_trcdvcvrx_s          cn88xxp1; */
} bdk_ap_trcdvcvrx_t;

static inline uint64_t BDK_AP_TRCDVCVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCDVCVRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020102000400ull + (param1 & 7) * 0x40000ull;
	csr_fatal("BDK_AP_TRCDVCVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCDVCVRX(...) bdk_ap_trcdvcvrx_t
#define bustype_BDK_AP_TRCDVCVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCDVCVRX(p1) (p1)
#define arguments_BDK_AP_TRCDVCVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCDVCVRX(...) "AP_TRCDVCVRX"


/**
 * SYSREG - ap_trceventctl#r
 */
typedef union bdk_ap_trceventctlxr {
	uint64_t u;
	struct bdk_ap_trceventctlxr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trceventctlxr_s      cn88xx; */
	/* struct bdk_ap_trceventctlxr_s      cn88xxp1; */
} bdk_ap_trceventctlxr_t;

static inline uint64_t BDK_AP_TRCEVENTCTLXR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCEVENTCTLXR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000020100080000ull + (param1 & 1) * 0x10000ull;
	csr_fatal("BDK_AP_TRCEVENTCTLXR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCEVENTCTLXR(...) bdk_ap_trceventctlxr_t
#define bustype_BDK_AP_TRCEVENTCTLXR(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCEVENTCTLXR(p1) (p1)
#define arguments_BDK_AP_TRCEVENTCTLXR(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCEVENTCTLXR(...) "AP_TRCEVENTCTLXR"


/**
 * SYSREG - ap_trcextinselr
 */
typedef union bdk_ap_trcextinselr {
	uint64_t u;
	struct bdk_ap_trcextinselr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcextinselr_s       cn88xx; */
	/* struct bdk_ap_trcextinselr_s       cn88xxp1; */
} bdk_ap_trcextinselr_t;

#define BDK_AP_TRCEXTINSELR BDK_AP_TRCEXTINSELR_FUNC()
static inline uint64_t BDK_AP_TRCEXTINSELR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCEXTINSELR_FUNC(void)
{
	return 0x0000020100080400ull;
}
#define typedef_BDK_AP_TRCEXTINSELR bdk_ap_trcextinselr_t
#define bustype_BDK_AP_TRCEXTINSELR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCEXTINSELR 0
#define arguments_BDK_AP_TRCEXTINSELR -1,-1,-1,-1
#define basename_BDK_AP_TRCEXTINSELR "AP_TRCEXTINSELR"


/**
 * SYSREG - ap_trcidr#
 */
typedef union bdk_ap_trcidrx {
	uint64_t u;
	struct bdk_ap_trcidrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcidrx_s            cn88xx; */
	/* struct bdk_ap_trcidrx_s            cn88xxp1; */
} bdk_ap_trcidrx_t;

static inline uint64_t BDK_AP_TRCIDRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCIDRX(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x0000020100080700ull + (param1 & 15) * 0x10000ull;
	csr_fatal("BDK_AP_TRCIDRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCIDRX(...) bdk_ap_trcidrx_t
#define bustype_BDK_AP_TRCIDRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCIDRX(p1) (p1)
#define arguments_BDK_AP_TRCIDRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCIDRX(...) "AP_TRCIDRX"


/**
 * SYSREG - ap_trcimspec#
 */
typedef union bdk_ap_trcimspecx {
	uint64_t u;
	struct bdk_ap_trcimspecx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcimspecx_s         cn88xx; */
	/* struct bdk_ap_trcimspecx_s         cn88xxp1; */
} bdk_ap_trcimspecx_t;

static inline uint64_t BDK_AP_TRCIMSPECX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCIMSPECX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020100000700ull + (param1 & 7) * 0x10000ull;
	csr_fatal("BDK_AP_TRCIMSPECX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCIMSPECX(...) bdk_ap_trcimspecx_t
#define bustype_BDK_AP_TRCIMSPECX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCIMSPECX(p1) (p1)
#define arguments_BDK_AP_TRCIMSPECX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCIMSPECX(...) "AP_TRCIMSPECX"


/**
 * SYSREG - ap_trcitctrl
 */
typedef union bdk_ap_trcitctrl {
	uint64_t u;
	struct bdk_ap_trcitctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcitctrl_s          cn88xx; */
	/* struct bdk_ap_trcitctrl_s          cn88xxp1; */
} bdk_ap_trcitctrl_t;

#define BDK_AP_TRCITCTRL BDK_AP_TRCITCTRL_FUNC()
static inline uint64_t BDK_AP_TRCITCTRL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCITCTRL_FUNC(void)
{
	return 0x0000020107000400ull;
}
#define typedef_BDK_AP_TRCITCTRL bdk_ap_trcitctrl_t
#define bustype_BDK_AP_TRCITCTRL BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCITCTRL 0
#define arguments_BDK_AP_TRCITCTRL -1,-1,-1,-1
#define basename_BDK_AP_TRCITCTRL "AP_TRCITCTRL"


/**
 * SYSREG - ap_trclar
 */
typedef union bdk_ap_trclar {
	uint64_t u;
	struct bdk_ap_trclar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trclar_s             cn88xx; */
	/* struct bdk_ap_trclar_s             cn88xxp1; */
} bdk_ap_trclar_t;

#define BDK_AP_TRCLAR BDK_AP_TRCLAR_FUNC()
static inline uint64_t BDK_AP_TRCLAR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCLAR_FUNC(void)
{
	return 0x00000201070C0600ull;
}
#define typedef_BDK_AP_TRCLAR bdk_ap_trclar_t
#define bustype_BDK_AP_TRCLAR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCLAR 0
#define arguments_BDK_AP_TRCLAR -1,-1,-1,-1
#define basename_BDK_AP_TRCLAR "AP_TRCLAR"


/**
 * SYSREG - ap_trclsr
 */
typedef union bdk_ap_trclsr {
	uint64_t u;
	struct bdk_ap_trclsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trclsr_s             cn88xx; */
	/* struct bdk_ap_trclsr_s             cn88xxp1; */
} bdk_ap_trclsr_t;

#define BDK_AP_TRCLSR BDK_AP_TRCLSR_FUNC()
static inline uint64_t BDK_AP_TRCLSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCLSR_FUNC(void)
{
	return 0x00000201070D0600ull;
}
#define typedef_BDK_AP_TRCLSR bdk_ap_trclsr_t
#define bustype_BDK_AP_TRCLSR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCLSR 0
#define arguments_BDK_AP_TRCLSR -1,-1,-1,-1
#define basename_BDK_AP_TRCLSR "AP_TRCLSR"


/**
 * SYSREG - ap_trcoslar
 */
typedef union bdk_ap_trcoslar {
	uint64_t u;
	struct bdk_ap_trcoslar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcoslar_s           cn88xx; */
	/* struct bdk_ap_trcoslar_s           cn88xxp1; */
} bdk_ap_trcoslar_t;

#define BDK_AP_TRCOSLAR BDK_AP_TRCOSLAR_FUNC()
static inline uint64_t BDK_AP_TRCOSLAR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCOSLAR_FUNC(void)
{
	return 0x0000020101000400ull;
}
#define typedef_BDK_AP_TRCOSLAR bdk_ap_trcoslar_t
#define bustype_BDK_AP_TRCOSLAR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCOSLAR 0
#define arguments_BDK_AP_TRCOSLAR -1,-1,-1,-1
#define basename_BDK_AP_TRCOSLAR "AP_TRCOSLAR"


/**
 * SYSREG - ap_trcoslsr
 */
typedef union bdk_ap_trcoslsr {
	uint64_t u;
	struct bdk_ap_trcoslsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcoslsr_s           cn88xx; */
	/* struct bdk_ap_trcoslsr_s           cn88xxp1; */
} bdk_ap_trcoslsr_t;

#define BDK_AP_TRCOSLSR BDK_AP_TRCOSLSR_FUNC()
static inline uint64_t BDK_AP_TRCOSLSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCOSLSR_FUNC(void)
{
	return 0x0000020101010400ull;
}
#define typedef_BDK_AP_TRCOSLSR bdk_ap_trcoslsr_t
#define bustype_BDK_AP_TRCOSLSR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCOSLSR 0
#define arguments_BDK_AP_TRCOSLSR -1,-1,-1,-1
#define basename_BDK_AP_TRCOSLSR "AP_TRCOSLSR"


/**
 * SYSREG - ap_trcpdcr
 */
typedef union bdk_ap_trcpdcr {
	uint64_t u;
	struct bdk_ap_trcpdcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcpdcr_s            cn88xx; */
	/* struct bdk_ap_trcpdcr_s            cn88xxp1; */
} bdk_ap_trcpdcr_t;

#define BDK_AP_TRCPDCR BDK_AP_TRCPDCR_FUNC()
static inline uint64_t BDK_AP_TRCPDCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCPDCR_FUNC(void)
{
	return 0x0000020101040400ull;
}
#define typedef_BDK_AP_TRCPDCR bdk_ap_trcpdcr_t
#define bustype_BDK_AP_TRCPDCR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCPDCR 0
#define arguments_BDK_AP_TRCPDCR -1,-1,-1,-1
#define basename_BDK_AP_TRCPDCR "AP_TRCPDCR"


/**
 * SYSREG - ap_trcpdsr
 */
typedef union bdk_ap_trcpdsr {
	uint64_t u;
	struct bdk_ap_trcpdsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcpdsr_s            cn88xx; */
	/* struct bdk_ap_trcpdsr_s            cn88xxp1; */
} bdk_ap_trcpdsr_t;

#define BDK_AP_TRCPDSR BDK_AP_TRCPDSR_FUNC()
static inline uint64_t BDK_AP_TRCPDSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCPDSR_FUNC(void)
{
	return 0x0000020101050400ull;
}
#define typedef_BDK_AP_TRCPDSR bdk_ap_trcpdsr_t
#define bustype_BDK_AP_TRCPDSR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCPDSR 0
#define arguments_BDK_AP_TRCPDSR -1,-1,-1,-1
#define basename_BDK_AP_TRCPDSR "AP_TRCPDSR"


/**
 * SYSREG - ap_trcpidr#
 */
typedef union bdk_ap_trcpidrx {
	uint64_t u;
	struct bdk_ap_trcpidrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcpidrx_s           cn88xx; */
	/* struct bdk_ap_trcpidrx_s           cn88xxp1; */
} bdk_ap_trcpidrx_t;

static inline uint64_t BDK_AP_TRCPIDRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCPIDRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020107080700ull + (param1 & 7) * 0x10000ull;
	csr_fatal("BDK_AP_TRCPIDRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCPIDRX(...) bdk_ap_trcpidrx_t
#define bustype_BDK_AP_TRCPIDRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCPIDRX(p1) (p1)
#define arguments_BDK_AP_TRCPIDRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCPIDRX(...) "AP_TRCPIDRX"


/**
 * SYSREG - ap_trcprgctlr
 */
typedef union bdk_ap_trcprgctlr {
	uint64_t u;
	struct bdk_ap_trcprgctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcprgctlr_s         cn88xx; */
	/* struct bdk_ap_trcprgctlr_s         cn88xxp1; */
} bdk_ap_trcprgctlr_t;

#define BDK_AP_TRCPRGCTLR BDK_AP_TRCPRGCTLR_FUNC()
static inline uint64_t BDK_AP_TRCPRGCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCPRGCTLR_FUNC(void)
{
	return 0x0000020100010000ull;
}
#define typedef_BDK_AP_TRCPRGCTLR bdk_ap_trcprgctlr_t
#define bustype_BDK_AP_TRCPRGCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCPRGCTLR 0
#define arguments_BDK_AP_TRCPRGCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCPRGCTLR "AP_TRCPRGCTLR"


/**
 * SYSREG - ap_trcprocselr
 */
typedef union bdk_ap_trcprocselr {
	uint64_t u;
	struct bdk_ap_trcprocselr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcprocselr_s        cn88xx; */
	/* struct bdk_ap_trcprocselr_s        cn88xxp1; */
} bdk_ap_trcprocselr_t;

#define BDK_AP_TRCPROCSELR BDK_AP_TRCPROCSELR_FUNC()
static inline uint64_t BDK_AP_TRCPROCSELR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCPROCSELR_FUNC(void)
{
	return 0x0000020100020000ull;
}
#define typedef_BDK_AP_TRCPROCSELR bdk_ap_trcprocselr_t
#define bustype_BDK_AP_TRCPROCSELR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCPROCSELR 0
#define arguments_BDK_AP_TRCPROCSELR -1,-1,-1,-1
#define basename_BDK_AP_TRCPROCSELR "AP_TRCPROCSELR"


/**
 * SYSREG - ap_trcqctlr
 */
typedef union bdk_ap_trcqctlr {
	uint64_t u;
	struct bdk_ap_trcqctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcqctlr_s           cn88xx; */
	/* struct bdk_ap_trcqctlr_s           cn88xxp1; */
} bdk_ap_trcqctlr_t;

#define BDK_AP_TRCQCTLR BDK_AP_TRCQCTLR_FUNC()
static inline uint64_t BDK_AP_TRCQCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCQCTLR_FUNC(void)
{
	return 0x0000020100010100ull;
}
#define typedef_BDK_AP_TRCQCTLR bdk_ap_trcqctlr_t
#define bustype_BDK_AP_TRCQCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCQCTLR 0
#define arguments_BDK_AP_TRCQCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCQCTLR "AP_TRCQCTLR"


/**
 * SYSREG - ap_trcrsctlr#
 */
typedef union bdk_ap_trcrsctlrx {
	uint64_t u;
	struct bdk_ap_trcrsctlrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcrsctlrx_s         cn88xx; */
	/* struct bdk_ap_trcrsctlrx_s         cn88xxp1; */
} bdk_ap_trcrsctlrx_t;

static inline uint64_t BDK_AP_TRCRSCTLRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCRSCTLRX(unsigned long param1)
{
	if ((((param1 >= 2) && (param1 <= 31))))
		return 0x0000020101000000ull + (param1 & 31) * 0x10000ull;
	csr_fatal("BDK_AP_TRCRSCTLRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCRSCTLRX(...) bdk_ap_trcrsctlrx_t
#define bustype_BDK_AP_TRCRSCTLRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCRSCTLRX(p1) (p1)
#define arguments_BDK_AP_TRCRSCTLRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCRSCTLRX(...) "AP_TRCRSCTLRX"


/**
 * SYSREG - ap_trcseqevr#
 */
typedef union bdk_ap_trcseqevrx {
	uint64_t u;
	struct bdk_ap_trcseqevrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcseqevrx_s         cn88xx; */
	/* struct bdk_ap_trcseqevrx_s         cn88xxp1; */
} bdk_ap_trcseqevrx_t;

static inline uint64_t BDK_AP_TRCSEQEVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSEQEVRX(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x0000020100000400ull + (param1 & 3) * 0x10000ull;
	csr_fatal("BDK_AP_TRCSEQEVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCSEQEVRX(...) bdk_ap_trcseqevrx_t
#define bustype_BDK_AP_TRCSEQEVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSEQEVRX(p1) (p1)
#define arguments_BDK_AP_TRCSEQEVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCSEQEVRX(...) "AP_TRCSEQEVRX"


/**
 * SYSREG - ap_trcseqrstevr
 */
typedef union bdk_ap_trcseqrstevr {
	uint64_t u;
	struct bdk_ap_trcseqrstevr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcseqrstevr_s       cn88xx; */
	/* struct bdk_ap_trcseqrstevr_s       cn88xxp1; */
} bdk_ap_trcseqrstevr_t;

#define BDK_AP_TRCSEQRSTEVR BDK_AP_TRCSEQRSTEVR_FUNC()
static inline uint64_t BDK_AP_TRCSEQRSTEVR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSEQRSTEVR_FUNC(void)
{
	return 0x0000020100060400ull;
}
#define typedef_BDK_AP_TRCSEQRSTEVR bdk_ap_trcseqrstevr_t
#define bustype_BDK_AP_TRCSEQRSTEVR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSEQRSTEVR 0
#define arguments_BDK_AP_TRCSEQRSTEVR -1,-1,-1,-1
#define basename_BDK_AP_TRCSEQRSTEVR "AP_TRCSEQRSTEVR"


/**
 * SYSREG - ap_trcseqstr
 */
typedef union bdk_ap_trcseqstr {
	uint64_t u;
	struct bdk_ap_trcseqstr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcseqstr_s          cn88xx; */
	/* struct bdk_ap_trcseqstr_s          cn88xxp1; */
} bdk_ap_trcseqstr_t;

#define BDK_AP_TRCSEQSTR BDK_AP_TRCSEQSTR_FUNC()
static inline uint64_t BDK_AP_TRCSEQSTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSEQSTR_FUNC(void)
{
	return 0x0000020100070400ull;
}
#define typedef_BDK_AP_TRCSEQSTR bdk_ap_trcseqstr_t
#define bustype_BDK_AP_TRCSEQSTR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSEQSTR 0
#define arguments_BDK_AP_TRCSEQSTR -1,-1,-1,-1
#define basename_BDK_AP_TRCSEQSTR "AP_TRCSEQSTR"


/**
 * SYSREG - ap_trcssccr#
 */
typedef union bdk_ap_trcssccrx {
	uint64_t u;
	struct bdk_ap_trcssccrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcssccrx_s          cn88xx; */
	/* struct bdk_ap_trcssccrx_s          cn88xxp1; */
} bdk_ap_trcssccrx_t;

static inline uint64_t BDK_AP_TRCSSCCRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSSCCRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020101000200ull + (param1 & 7) * 0x10000ull;
	csr_fatal("BDK_AP_TRCSSCCRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCSSCCRX(...) bdk_ap_trcssccrx_t
#define bustype_BDK_AP_TRCSSCCRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSSCCRX(p1) (p1)
#define arguments_BDK_AP_TRCSSCCRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCSSCCRX(...) "AP_TRCSSCCRX"


/**
 * SYSREG - ap_trcsscsr#
 */
typedef union bdk_ap_trcsscsrx {
	uint64_t u;
	struct bdk_ap_trcsscsrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcsscsrx_s          cn88xx; */
	/* struct bdk_ap_trcsscsrx_s          cn88xxp1; */
} bdk_ap_trcsscsrx_t;

static inline uint64_t BDK_AP_TRCSSCSRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSSCSRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020101080200ull + (param1 & 7) * 0x10000ull;
	csr_fatal("BDK_AP_TRCSSCSRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCSSCSRX(...) bdk_ap_trcsscsrx_t
#define bustype_BDK_AP_TRCSSCSRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSSCSRX(p1) (p1)
#define arguments_BDK_AP_TRCSSCSRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCSSCSRX(...) "AP_TRCSSCSRX"


/**
 * SYSREG - ap_trcsspcicr#
 */
typedef union bdk_ap_trcsspcicrx {
	uint64_t u;
	struct bdk_ap_trcsspcicrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcsspcicrx_s        cn88xx; */
	/* struct bdk_ap_trcsspcicrx_s        cn88xxp1; */
} bdk_ap_trcsspcicrx_t;

static inline uint64_t BDK_AP_TRCSSPCICRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSSPCICRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020101000300ull + (param1 & 7) * 0x10000ull;
	csr_fatal("BDK_AP_TRCSSPCICRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCSSPCICRX(...) bdk_ap_trcsspcicrx_t
#define bustype_BDK_AP_TRCSSPCICRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSSPCICRX(p1) (p1)
#define arguments_BDK_AP_TRCSSPCICRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCSSPCICRX(...) "AP_TRCSSPCICRX"


/**
 * SYSREG - ap_trcstallctlr
 */
typedef union bdk_ap_trcstallctlr {
	uint64_t u;
	struct bdk_ap_trcstallctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcstallctlr_s       cn88xx; */
	/* struct bdk_ap_trcstallctlr_s       cn88xxp1; */
} bdk_ap_trcstallctlr_t;

#define BDK_AP_TRCSTALLCTLR BDK_AP_TRCSTALLCTLR_FUNC()
static inline uint64_t BDK_AP_TRCSTALLCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSTALLCTLR_FUNC(void)
{
	return 0x00000201000B0000ull;
}
#define typedef_BDK_AP_TRCSTALLCTLR bdk_ap_trcstallctlr_t
#define bustype_BDK_AP_TRCSTALLCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSTALLCTLR 0
#define arguments_BDK_AP_TRCSTALLCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCSTALLCTLR "AP_TRCSTALLCTLR"


/**
 * SYSREG - ap_trcstatr
 */
typedef union bdk_ap_trcstatr {
	uint64_t u;
	struct bdk_ap_trcstatr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcstatr_s           cn88xx; */
	/* struct bdk_ap_trcstatr_s           cn88xxp1; */
} bdk_ap_trcstatr_t;

#define BDK_AP_TRCSTATR BDK_AP_TRCSTATR_FUNC()
static inline uint64_t BDK_AP_TRCSTATR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSTATR_FUNC(void)
{
	return 0x0000020100030000ull;
}
#define typedef_BDK_AP_TRCSTATR bdk_ap_trcstatr_t
#define bustype_BDK_AP_TRCSTATR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSTATR 0
#define arguments_BDK_AP_TRCSTATR -1,-1,-1,-1
#define basename_BDK_AP_TRCSTATR "AP_TRCSTATR"


/**
 * SYSREG - ap_trcsyncpr
 */
typedef union bdk_ap_trcsyncpr {
	uint64_t u;
	struct bdk_ap_trcsyncpr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcsyncpr_s          cn88xx; */
	/* struct bdk_ap_trcsyncpr_s          cn88xxp1; */
} bdk_ap_trcsyncpr_t;

#define BDK_AP_TRCSYNCPR BDK_AP_TRCSYNCPR_FUNC()
static inline uint64_t BDK_AP_TRCSYNCPR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCSYNCPR_FUNC(void)
{
	return 0x00000201000D0000ull;
}
#define typedef_BDK_AP_TRCSYNCPR bdk_ap_trcsyncpr_t
#define bustype_BDK_AP_TRCSYNCPR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCSYNCPR 0
#define arguments_BDK_AP_TRCSYNCPR -1,-1,-1,-1
#define basename_BDK_AP_TRCSYNCPR "AP_TRCSYNCPR"


/**
 * SYSREG - ap_trctraceidr
 */
typedef union bdk_ap_trctraceidr {
	uint64_t u;
	struct bdk_ap_trctraceidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trctraceidr_s        cn88xx; */
	/* struct bdk_ap_trctraceidr_s        cn88xxp1; */
} bdk_ap_trctraceidr_t;

#define BDK_AP_TRCTRACEIDR BDK_AP_TRCTRACEIDR_FUNC()
static inline uint64_t BDK_AP_TRCTRACEIDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCTRACEIDR_FUNC(void)
{
	return 0x0000020100000100ull;
}
#define typedef_BDK_AP_TRCTRACEIDR bdk_ap_trctraceidr_t
#define bustype_BDK_AP_TRCTRACEIDR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCTRACEIDR 0
#define arguments_BDK_AP_TRCTRACEIDR -1,-1,-1,-1
#define basename_BDK_AP_TRCTRACEIDR "AP_TRCTRACEIDR"


/**
 * SYSREG - ap_trctsctlr
 */
typedef union bdk_ap_trctsctlr {
	uint64_t u;
	struct bdk_ap_trctsctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trctsctlr_s          cn88xx; */
	/* struct bdk_ap_trctsctlr_s          cn88xxp1; */
} bdk_ap_trctsctlr_t;

#define BDK_AP_TRCTSCTLR BDK_AP_TRCTSCTLR_FUNC()
static inline uint64_t BDK_AP_TRCTSCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCTSCTLR_FUNC(void)
{
	return 0x00000201000C0000ull;
}
#define typedef_BDK_AP_TRCTSCTLR bdk_ap_trctsctlr_t
#define bustype_BDK_AP_TRCTSCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCTSCTLR 0
#define arguments_BDK_AP_TRCTSCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCTSCTLR "AP_TRCTSCTLR"


/**
 * SYSREG - ap_trcvdarcctlr
 */
typedef union bdk_ap_trcvdarcctlr {
	uint64_t u;
	struct bdk_ap_trcvdarcctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvdarcctlr_s       cn88xx; */
	/* struct bdk_ap_trcvdarcctlr_s       cn88xxp1; */
} bdk_ap_trcvdarcctlr_t;

#define BDK_AP_TRCVDARCCTLR BDK_AP_TRCVDARCCTLR_FUNC()
static inline uint64_t BDK_AP_TRCVDARCCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVDARCCTLR_FUNC(void)
{
	return 0x00000201000A0200ull;
}
#define typedef_BDK_AP_TRCVDARCCTLR bdk_ap_trcvdarcctlr_t
#define bustype_BDK_AP_TRCVDARCCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVDARCCTLR 0
#define arguments_BDK_AP_TRCVDARCCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVDARCCTLR "AP_TRCVDARCCTLR"


/**
 * SYSREG - ap_trcvdctlr
 */
typedef union bdk_ap_trcvdctlr {
	uint64_t u;
	struct bdk_ap_trcvdctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvdctlr_s          cn88xx; */
	/* struct bdk_ap_trcvdctlr_s          cn88xxp1; */
} bdk_ap_trcvdctlr_t;

#define BDK_AP_TRCVDCTLR BDK_AP_TRCVDCTLR_FUNC()
static inline uint64_t BDK_AP_TRCVDCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVDCTLR_FUNC(void)
{
	return 0x0000020100080200ull;
}
#define typedef_BDK_AP_TRCVDCTLR bdk_ap_trcvdctlr_t
#define bustype_BDK_AP_TRCVDCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVDCTLR 0
#define arguments_BDK_AP_TRCVDCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVDCTLR "AP_TRCVDCTLR"


/**
 * SYSREG - ap_trcvdsacctlr
 */
typedef union bdk_ap_trcvdsacctlr {
	uint64_t u;
	struct bdk_ap_trcvdsacctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvdsacctlr_s       cn88xx; */
	/* struct bdk_ap_trcvdsacctlr_s       cn88xxp1; */
} bdk_ap_trcvdsacctlr_t;

#define BDK_AP_TRCVDSACCTLR BDK_AP_TRCVDSACCTLR_FUNC()
static inline uint64_t BDK_AP_TRCVDSACCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVDSACCTLR_FUNC(void)
{
	return 0x0000020100090200ull;
}
#define typedef_BDK_AP_TRCVDSACCTLR bdk_ap_trcvdsacctlr_t
#define bustype_BDK_AP_TRCVDSACCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVDSACCTLR 0
#define arguments_BDK_AP_TRCVDSACCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVDSACCTLR "AP_TRCVDSACCTLR"


/**
 * SYSREG - ap_trcvictlr
 */
typedef union bdk_ap_trcvictlr {
	uint64_t u;
	struct bdk_ap_trcvictlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvictlr_s          cn88xx; */
	/* struct bdk_ap_trcvictlr_s          cn88xxp1; */
} bdk_ap_trcvictlr_t;

#define BDK_AP_TRCVICTLR BDK_AP_TRCVICTLR_FUNC()
static inline uint64_t BDK_AP_TRCVICTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVICTLR_FUNC(void)
{
	return 0x0000020100000200ull;
}
#define typedef_BDK_AP_TRCVICTLR bdk_ap_trcvictlr_t
#define bustype_BDK_AP_TRCVICTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVICTLR 0
#define arguments_BDK_AP_TRCVICTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVICTLR "AP_TRCVICTLR"


/**
 * SYSREG - ap_trcviiectlr
 */
typedef union bdk_ap_trcviiectlr {
	uint64_t u;
	struct bdk_ap_trcviiectlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcviiectlr_s        cn88xx; */
	/* struct bdk_ap_trcviiectlr_s        cn88xxp1; */
} bdk_ap_trcviiectlr_t;

#define BDK_AP_TRCVIIECTLR BDK_AP_TRCVIIECTLR_FUNC()
static inline uint64_t BDK_AP_TRCVIIECTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVIIECTLR_FUNC(void)
{
	return 0x0000020100010200ull;
}
#define typedef_BDK_AP_TRCVIIECTLR bdk_ap_trcviiectlr_t
#define bustype_BDK_AP_TRCVIIECTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVIIECTLR 0
#define arguments_BDK_AP_TRCVIIECTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVIIECTLR "AP_TRCVIIECTLR"


/**
 * SYSREG - ap_trcvipcssctlr
 */
typedef union bdk_ap_trcvipcssctlr {
	uint64_t u;
	struct bdk_ap_trcvipcssctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvipcssctlr_s      cn88xx; */
	/* struct bdk_ap_trcvipcssctlr_s      cn88xxp1; */
} bdk_ap_trcvipcssctlr_t;

#define BDK_AP_TRCVIPCSSCTLR BDK_AP_TRCVIPCSSCTLR_FUNC()
static inline uint64_t BDK_AP_TRCVIPCSSCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVIPCSSCTLR_FUNC(void)
{
	return 0x0000020100030200ull;
}
#define typedef_BDK_AP_TRCVIPCSSCTLR bdk_ap_trcvipcssctlr_t
#define bustype_BDK_AP_TRCVIPCSSCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVIPCSSCTLR 0
#define arguments_BDK_AP_TRCVIPCSSCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVIPCSSCTLR "AP_TRCVIPCSSCTLR"


/**
 * SYSREG - ap_trcvissctlr
 */
typedef union bdk_ap_trcvissctlr {
	uint64_t u;
	struct bdk_ap_trcvissctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvissctlr_s        cn88xx; */
	/* struct bdk_ap_trcvissctlr_s        cn88xxp1; */
} bdk_ap_trcvissctlr_t;

#define BDK_AP_TRCVISSCTLR BDK_AP_TRCVISSCTLR_FUNC()
static inline uint64_t BDK_AP_TRCVISSCTLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVISSCTLR_FUNC(void)
{
	return 0x0000020100020200ull;
}
#define typedef_BDK_AP_TRCVISSCTLR bdk_ap_trcvissctlr_t
#define bustype_BDK_AP_TRCVISSCTLR BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVISSCTLR 0
#define arguments_BDK_AP_TRCVISSCTLR -1,-1,-1,-1
#define basename_BDK_AP_TRCVISSCTLR "AP_TRCVISSCTLR"


/**
 * SYSREG - ap_trcvmidcctlr#
 */
typedef union bdk_ap_trcvmidcctlrx {
	uint64_t u;
	struct bdk_ap_trcvmidcctlrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvmidcctlrx_s      cn88xx; */
	/* struct bdk_ap_trcvmidcctlrx_s      cn88xxp1; */
} bdk_ap_trcvmidcctlrx_t;

static inline uint64_t BDK_AP_TRCVMIDCCTLRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVMIDCCTLRX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000020103020200ull + (param1 & 1) * 0x10000ull;
	csr_fatal("BDK_AP_TRCVMIDCCTLRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCVMIDCCTLRX(...) bdk_ap_trcvmidcctlrx_t
#define bustype_BDK_AP_TRCVMIDCCTLRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVMIDCCTLRX(p1) (p1)
#define arguments_BDK_AP_TRCVMIDCCTLRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCVMIDCCTLRX(...) "AP_TRCVMIDCCTLRX"


/**
 * SYSREG - ap_trcvmidcvr#
 */
typedef union bdk_ap_trcvmidcvrx {
	uint64_t u;
	struct bdk_ap_trcvmidcvrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_trcvmidcvrx_s        cn88xx; */
	/* struct bdk_ap_trcvmidcvrx_s        cn88xxp1; */
} bdk_ap_trcvmidcvrx_t;

static inline uint64_t BDK_AP_TRCVMIDCVRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TRCVMIDCVRX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000020103000100ull + (param1 & 7) * 0x20000ull;
	csr_fatal("BDK_AP_TRCVMIDCVRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_TRCVMIDCVRX(...) bdk_ap_trcvmidcvrx_t
#define bustype_BDK_AP_TRCVMIDCVRX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TRCVMIDCVRX(p1) (p1)
#define arguments_BDK_AP_TRCVMIDCVRX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_TRCVMIDCVRX(...) "AP_TRCVMIDCVRX"


/**
 * SYSREG - ap_ttbr0_el1
 *
 * Holds the base address of translation table 0, and information
 * about the memory it occupies. This is one of the translation
 * tables for the stage 1 translation of memory accesses at EL0
 * and EL1.
 */
typedef union bdk_ap_ttbr0_el1 {
	uint64_t u;
	struct bdk_ap_ttbr0_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< R/W - An ASID for the translation table base address. The AP_TCR_EL1[A1]
                                                                     field selects either AP_TTBR0_EL1[ASID] or AP_TTBR1_EL1[ASID].
                                                                 If the implementation has only 8 bits of ASID, then the upper
                                                                     8 bits of this field are RES0. */
		uint64_t baddr                       : 44; /**< R/W - Translation table base address, bits\<47:x\>. Bits \<x-1:0\> are
                                                                     RES0.

                                                                 x is based on the value of AP_TCR_EL1[T0SZ], the stage of
                                                                     translation, and the memory translation granule size.
                                                                 The AArch64 Virtual Memory System Architecture chapter
                                                                     describes how x is calculated.
                                                                 The value of x determines the required alignment of the
                                                                     translation table, which must be aligned to 22^(x)
                                                                     bytes.

                                                                 If bits [x-1:0] are not all zero, this is a misaligned
                                                                     Translation Table Base Address. Its effects are CONSTRAINED
                                                                     UNPREDICTABLE, and can be one of the following:

                                                                  Bits [x-1:0] are treated as if all the bits are zero. The
                                                                     value read back from those bits might be the value written or
                                                                     might be zero.

                                                                  The calculation of an address for a translation table walk
                                                                     using this register can be corrupted in those bits that are
                                                                     non-zero. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t baddr                       : 44;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_ap_ttbr0_el1_s          cn88xx; */
	/* struct bdk_ap_ttbr0_el1_s          cn88xxp1; */
} bdk_ap_ttbr0_el1_t;

#define BDK_AP_TTBR0_EL1 BDK_AP_TTBR0_EL1_FUNC()
static inline uint64_t BDK_AP_TTBR0_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR0_EL1_FUNC(void)
{
	return 0x0000030002000000ull;
}
#define typedef_BDK_AP_TTBR0_EL1 bdk_ap_ttbr0_el1_t
#define bustype_BDK_AP_TTBR0_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR0_EL1 0
#define arguments_BDK_AP_TTBR0_EL1 -1,-1,-1,-1
#define basename_BDK_AP_TTBR0_EL1 "AP_TTBR0_EL1"


/**
 * SYSREG - ap_ttbr0_el12
 *
 * Alias of AP_TTBR0_EL1 from EL2 when AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_ttbr0_el12 {
	uint64_t u;
	struct bdk_ap_ttbr0_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_ttbr0_el12_s         cn88xx; */
	/* struct bdk_ap_ttbr0_el12_s         cn88xxp1; */
} bdk_ap_ttbr0_el12_t;

#define BDK_AP_TTBR0_EL12 BDK_AP_TTBR0_EL12_FUNC()
static inline uint64_t BDK_AP_TTBR0_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR0_EL12_FUNC(void)
{
	return 0x0000030502000000ull;
}
#define typedef_BDK_AP_TTBR0_EL12 bdk_ap_ttbr0_el12_t
#define bustype_BDK_AP_TTBR0_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR0_EL12 0
#define arguments_BDK_AP_TTBR0_EL12 -1,-1,-1,-1
#define basename_BDK_AP_TTBR0_EL12 "AP_TTBR0_EL12"


/**
 * SYSREG - ap_ttbr0_el2
 *
 * Holds the base address of translation table 0, and information
 * about the memory it occupies. This is one of the translation
 * tables for the stage 1 translation of memory accesses at EL0
 * and EL2 when Virtual Host Extensions are enabled.
 */
typedef union bdk_ap_ttbr0_el2 {
	uint64_t u;
	struct bdk_ap_ttbr0_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< R/W - An ASID for the translation table base address. The AP_TCR_EL1[A1]
                                                                     field selects either AP_TTBR0_EL1[ASID] or AP_TTBR1_EL1[ASID].
                                                                 If the implementation has only 8 bits of ASID, then the upper
                                                                     8 bits of this field are RES0. */
		uint64_t baddr                       : 44; /**< R/W - Translation table base address, bits\<47:x\>. Bits \<x-1:0\> are
                                                                     RES0.

                                                                 x is based on the value of AP_TCR_EL1[T0SZ], the stage of
                                                                     translation, and the memory translation granule size.
                                                                 The AArch64 Virtual Memory System Architecture chapter
                                                                     describes how x is calculated.
                                                                 The value of x determines the required alignment of the
                                                                     translation table, which must be aligned to 22^(x)
                                                                     bytes.

                                                                 If bits \<x-1:0\> are not all zero, this is a misaligned
                                                                     Translation Table Base Address. Its effects are CONSTRAINED
                                                                     UNPREDICTABLE, and can be one of the following:

                                                                  Bits \<x-1:0\> are treated as if all the bits are zero. The
                                                                     value read back from those bits might be the value written or
                                                                     might be zero.

                                                                  The calculation of an address for a translation table walk
                                                                     using this register can be corrupted in those bits that are
                                                                     non-zero. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t baddr                       : 44;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_ap_ttbr0_el2_s          cn88xx; */
	/* struct bdk_ap_ttbr0_el2_s          cn88xxp1; */
} bdk_ap_ttbr0_el2_t;

#define BDK_AP_TTBR0_EL2 BDK_AP_TTBR0_EL2_FUNC()
static inline uint64_t BDK_AP_TTBR0_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR0_EL2_FUNC(void)
{
	return 0x0000030402000000ull;
}
#define typedef_BDK_AP_TTBR0_EL2 bdk_ap_ttbr0_el2_t
#define bustype_BDK_AP_TTBR0_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR0_EL2 0
#define arguments_BDK_AP_TTBR0_EL2 -1,-1,-1,-1
#define basename_BDK_AP_TTBR0_EL2 "AP_TTBR0_EL2"


/**
 * SYSREG - ap_ttbr0_el3
 *
 * Holds the base address of the translation table for the stage
 * 1 translation of memory accesses from EL3.
 */
typedef union bdk_ap_ttbr0_el3 {
	uint64_t u;
	struct bdk_ap_ttbr0_el3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t baddr                       : 44; /**< R/W - Translation table base address, bits[47:x]. Bits [x-1:0] are
                                                                     RES0.

                                                                 x is based on the value of TCR_EL*[T0SZ], the stage of
                                                                     translation, and the memory translation granule size.
                                                                 The AArch64 Virtual Memory System Architecture chapter
                                                                     describes how x is calculated.
                                                                 The value of x determines the required alignment of the
                                                                     translation table, which must be aligned to 22^(x)
                                                                     bytes.

                                                                 If bits [x-1:0] are not all zero, this is a misaligned
                                                                     Translation Table Base Address. Its effects are CONSTRAINED
                                                                     UNPREDICTABLE, and can be one of the following:

                                                                  Bits [x-1:0] are treated as if all the bits are zero. The
                                                                     value read back from those bits might be the value written or
                                                                     might be zero.

                                                                  The calculation of an address for a translation table walk
                                                                     using this register can be corrupted in those bits that are
                                                                     non-zero. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t baddr                       : 44;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ap_ttbr0_el3_s          cn88xx; */
	/* struct bdk_ap_ttbr0_el3_s          cn88xxp1; */
} bdk_ap_ttbr0_el3_t;

#define BDK_AP_TTBR0_EL3 BDK_AP_TTBR0_EL3_FUNC()
static inline uint64_t BDK_AP_TTBR0_EL3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR0_EL3_FUNC(void)
{
	return 0x0000030602000000ull;
}
#define typedef_BDK_AP_TTBR0_EL3 bdk_ap_ttbr0_el3_t
#define bustype_BDK_AP_TTBR0_EL3 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR0_EL3 0
#define arguments_BDK_AP_TTBR0_EL3 -1,-1,-1,-1
#define basename_BDK_AP_TTBR0_EL3 "AP_TTBR0_EL3"


/**
 * SYSREG - ap_ttbr1_el1
 *
 * Holds the base address of translation table 1, and information
 * about the memory it occupies. This is one of the translation
 * tables for the stage 1 translation of memory accesses at EL0
 * and EL1.
 */
typedef union bdk_ap_ttbr1_el1 {
	uint64_t u;
	struct bdk_ap_ttbr1_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< R/W - An ASID for the translation table base address. The AP_TCR_EL1[A1]
                                                                     field selects either AP_TTBR0_EL1[ASID] or AP_TTBR1_EL1[ASID].
                                                                 If the implementation has only 8 bits of ASID, then the upper
                                                                     8 bits of this field are RES0. */
		uint64_t baddr                       : 44; /**< R/W - Translation table base address, bits\<47:x\>. Bits \<x-1:0\> are
                                                                     RES0.

                                                                 x is based on the value of AP_TCR_EL1[T0SZ], the stage of
                                                                     translation, and the memory translation granule size.
                                                                 The AArch64 Virtual Memory System Architecture chapter
                                                                     describes how x is calculated.
                                                                 The value of x determines the required alignment of the
                                                                     translation table, which must be aligned to 22^(x)
                                                                     bytes.

                                                                 If bits \<x-1:0\> are not all zero, this is a misaligned
                                                                     Translation Table Base Address. Its effects are CONSTRAINED
                                                                     UNPREDICTABLE, and can be one of the following:

                                                                 Bits \<x-1:0\> are treated as if all the bits are zero. The
                                                                     value read back from those bits might be the value written or
                                                                     might be zero.

                                                                  The calculation of an address for a translation table walk
                                                                     using this register can be corrupted in those bits that are
                                                                     non-zero. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t baddr                       : 44;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_ap_ttbr1_el1_s          cn88xx; */
	/* struct bdk_ap_ttbr1_el1_s          cn88xxp1; */
} bdk_ap_ttbr1_el1_t;

#define BDK_AP_TTBR1_EL1 BDK_AP_TTBR1_EL1_FUNC()
static inline uint64_t BDK_AP_TTBR1_EL1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR1_EL1_FUNC(void)
{
	return 0x0000030002000100ull;
}
#define typedef_BDK_AP_TTBR1_EL1 bdk_ap_ttbr1_el1_t
#define bustype_BDK_AP_TTBR1_EL1 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR1_EL1 0
#define arguments_BDK_AP_TTBR1_EL1 -1,-1,-1,-1
#define basename_BDK_AP_TTBR1_EL1 "AP_TTBR1_EL1"


/**
 * SYSREG - ap_ttbr1_el12
 *
 * Alias of AP_TTBR1_EL1 from EL2 when AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_ttbr1_el12 {
	uint64_t u;
	struct bdk_ap_ttbr1_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_ttbr1_el12_s         cn88xx; */
	/* struct bdk_ap_ttbr1_el12_s         cn88xxp1; */
} bdk_ap_ttbr1_el12_t;

#define BDK_AP_TTBR1_EL12 BDK_AP_TTBR1_EL12_FUNC()
static inline uint64_t BDK_AP_TTBR1_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR1_EL12_FUNC(void)
{
	return 0x0000030502000100ull;
}
#define typedef_BDK_AP_TTBR1_EL12 bdk_ap_ttbr1_el12_t
#define bustype_BDK_AP_TTBR1_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR1_EL12 0
#define arguments_BDK_AP_TTBR1_EL12 -1,-1,-1,-1
#define basename_BDK_AP_TTBR1_EL12 "AP_TTBR1_EL12"


/**
 * SYSREG - ap_ttbr1_el2
 *
 * Holds the base address of translation table 1, and information
 * about the memory it occupies. This is one of the translation
 * tables for the stage 1 translation of memory accesses at EL2.
 */
typedef union bdk_ap_ttbr1_el2 {
	uint64_t u;
	struct bdk_ap_ttbr1_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< R/W - An ASID for the translation table base address. The AP_TCR_EL2[A1]
                                                                     field selects either AP_TTBR0_EL2[ASID] or AP_TTBR1_EL2[ASID].
                                                                 If the implementation has only 8 bits of ASID, then the upper
                                                                     8 bits of this field are RES0. */
		uint64_t baddr                       : 44; /**< R/W - Translation table base address, bits\<47:x\>. Bits \<x-1:0\> are
                                                                     RES0.

                                                                 x is based on the value of AP_TCR_EL2[T0SZ], the stage of
                                                                     translation, and the memory translation granule size.
                                                                 The AArch64 Virtual Memory System Architecture chapter
                                                                     describes how x is calculated.
                                                                 The value of x determines the required alignment of the
                                                                     translation table, which must be aligned to 22^(x)
                                                                     bytes.

                                                                 If bits \<x-1:0\> are not all zero, this is a misaligned
                                                                     Translation Table Base Address. Its effects are CONSTRAINED
                                                                     UNPREDICTABLE, and can be one of the following:

                                                                  Bits \<x-1:0\> are treated as if all the bits are zero. The
                                                                     value read back from those bits might be the value written or
                                                                     might be zero.

                                                                  The calculation of an address for a translation table walk
                                                                     using this register can be corrupted in those bits that are
                                                                     non-zero. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t baddr                       : 44;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_ap_ttbr1_el2_s          cn88xx; */
	/* struct bdk_ap_ttbr1_el2_s          cn88xxp1; */
} bdk_ap_ttbr1_el2_t;

#define BDK_AP_TTBR1_EL2 BDK_AP_TTBR1_EL2_FUNC()
static inline uint64_t BDK_AP_TTBR1_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_TTBR1_EL2_FUNC(void)
{
	return 0x0000030402000100ull;
}
#define typedef_BDK_AP_TTBR1_EL2 bdk_ap_ttbr1_el2_t
#define bustype_BDK_AP_TTBR1_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_TTBR1_EL2 0
#define arguments_BDK_AP_TTBR1_EL2 -1,-1,-1,-1
#define basename_BDK_AP_TTBR1_EL2 "AP_TTBR1_EL2"


/**
 * SYSREG - ap_vbar_el#
 *
 * Holds the exception base address for any exception that is
 * taken to EL*.
 */
typedef union bdk_ap_vbar_elx {
	uint64_t u;
	struct bdk_ap_vbar_elx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 53; /**< R/W - Vector base address. Base address of the exception vectors for
                                                                     exceptions taken in EL*.
                                                                 If tagged addresses are being used, bits \<55:48\> of VBAR_EL*
                                                                     must be 0 or else the use of the vector address will result in
                                                                     a recursive exception.

                                                                 If tagged addresses are not being used, bits \<63:48\> of
                                                                     VBAR_EL* must be 0 or else the use of the vector address will
                                                                     result in a recursive exception. */
		uint64_t reserved_0_10               : 11;
#else
		uint64_t reserved_0_10               : 11;
		uint64_t data                        : 53;
#endif
	} s;
	/* struct bdk_ap_vbar_elx_s           cn88xx; */
	/* struct bdk_ap_vbar_elx_s           cn88xxp1; */
} bdk_ap_vbar_elx_t;

static inline uint64_t BDK_AP_VBAR_ELX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_VBAR_ELX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 3))))
		return 0x000003000C000000ull + (param1 & 3) * 0x200000000ull;
	csr_fatal("BDK_AP_VBAR_ELX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_AP_VBAR_ELX(...) bdk_ap_vbar_elx_t
#define bustype_BDK_AP_VBAR_ELX(...) BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_VBAR_ELX(p1) (p1)
#define arguments_BDK_AP_VBAR_ELX(p1) (p1),-1,-1,-1
#define basename_BDK_AP_VBAR_ELX(...) "AP_VBAR_ELX"


/**
 * SYSREG - ap_vbar_el12
 *
 * Alias of VBAR_EL1 when accessed at EL2/3 and AP_HCR_EL2[E2H] is set.
 *
 */
typedef union bdk_ap_vbar_el12 {
	uint64_t u;
	struct bdk_ap_vbar_el12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_ap_vbar_el12_s          cn88xx; */
	/* struct bdk_ap_vbar_el12_s          cn88xxp1; */
} bdk_ap_vbar_el12_t;

#define BDK_AP_VBAR_EL12 BDK_AP_VBAR_EL12_FUNC()
static inline uint64_t BDK_AP_VBAR_EL12_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_VBAR_EL12_FUNC(void)
{
	return 0x000003050C000000ull;
}
#define typedef_BDK_AP_VBAR_EL12 bdk_ap_vbar_el12_t
#define bustype_BDK_AP_VBAR_EL12 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_VBAR_EL12 0
#define arguments_BDK_AP_VBAR_EL12 -1,-1,-1,-1
#define basename_BDK_AP_VBAR_EL12 "AP_VBAR_EL12"


/**
 * SYSREG - ap_vmpidr_el2
 *
 * Holds the value of the Virtualization Multiprocessor ID. This
 * is the value returned by non-secure EL1 reads of AP_MPIDR_EL1.
 */
typedef union bdk_ap_vmpidr_el2 {
	uint64_t u;
	struct bdk_ap_vmpidr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t aff3                        : 8;  /**< R/W - Affinity level 3. Highest level affinity field. */
		uint64_t rsvd_31                     : 1;  /**< RO - Reserved 1. */
		uint64_t u                           : 1;  /**< R/W - Indicates a Uniprocessor system, as distinct from PE 0 in a
                                                                     multiprocessor system.
                                                                 0 = Processor is part of a multiprocessor system.
                                                                 1 = Processor is part of a uniprocessor system. */
		uint64_t reserved_25_29              : 5;
		uint64_t mt                          : 1;  /**< R/W - Indicates whether the lowest level of affinity consists of
                                                                     logical PEs that are implemented using a multi-threading type
                                                                     approach.
                                                                 0 = Performance of PEs at the lowest affinity level is largely
                                                                     independent.
                                                                 1 = Performance of PEs at the lowest affinity level is very
                                                                     interdependent. */
		uint64_t aff2                        : 8;  /**< R/W - Affinity level 2. Second highest level affinity field. */
		uint64_t aff1                        : 8;  /**< R/W - Affinity level 1. Third highest level affinity field. */
		uint64_t aff0                        : 8;  /**< R/W - Affinity level 0. Lowest level affinity field. */
#else
		uint64_t aff0                        : 8;
		uint64_t aff1                        : 8;
		uint64_t aff2                        : 8;
		uint64_t mt                          : 1;
		uint64_t reserved_25_29              : 5;
		uint64_t u                           : 1;
		uint64_t rsvd_31                     : 1;
		uint64_t aff3                        : 8;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_ap_vmpidr_el2_s         cn88xx; */
	/* struct bdk_ap_vmpidr_el2_s         cn88xxp1; */
} bdk_ap_vmpidr_el2_t;

#define BDK_AP_VMPIDR_EL2 BDK_AP_VMPIDR_EL2_FUNC()
static inline uint64_t BDK_AP_VMPIDR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_VMPIDR_EL2_FUNC(void)
{
	return 0x0000030400000500ull;
}
#define typedef_BDK_AP_VMPIDR_EL2 bdk_ap_vmpidr_el2_t
#define bustype_BDK_AP_VMPIDR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_VMPIDR_EL2 0
#define arguments_BDK_AP_VMPIDR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_VMPIDR_EL2 "AP_VMPIDR_EL2"


/**
 * SYSREG - ap_vpidr_el2
 *
 * Holds the value of the Virtualization Processor ID. This is
 * the value returned by non-secure EL1 reads of AP_MIDR_EL1.
 */
typedef union bdk_ap_vpidr_el2 {
	uint32_t u;
	struct bdk_ap_vpidr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t implementer                 : 8;  /**< R/W - The implementer code. This field must hold an implementer code
                                                                     that has been assigned by ARM.
                                                                 Hex representation  ASCII representation.
                                                                 0x41 = 'A' = ARM Limited.
                                                                 0x42 = 'B' = Broadcom Corporation.
                                                                 0x43 = 'C' = Cavium Inc.
                                                                 0x44 = 'D' = Digital Equipment Corporation.
                                                                 0x49 = 'I' = Infineon Technologies AG.
                                                                 0x4D = 'M' = Motorola or Freescale Semiconductor Inc.
                                                                 0x4E = 'N' = NVIDIA Corporation.
                                                                 0x50 = 'P' = Applied Micro Circuits Corporation.
                                                                 0x51 = 'Q' = Qualcomm Inc.
                                                                 0x56 = 'V' = Marvell International Ltd.
                                                                 0x69 = 'i' = Intel Corporation.

                                                                 ARM can assign codes that are not published in this manual.
                                                                     All values not assigned by ARM are reserved and must not be
                                                                     used. */
		uint32_t variant                     : 4;  /**< R/W - An implementation defined variant number. Typically, this
                                                                 field is used to distinguish between different product
                                                                 variants, or major revisions of a product. */
		uint32_t architecture                : 4;  /**< R/W - Architecture:
                                                                 0x1 = ARMv4.
                                                                 0x2 = ARMv4T.
                                                                 0x3 = ARMv5 (obsolete).
                                                                 0x4 = ARMv5T.
                                                                 0x5 = ARMv5TE.
                                                                 0x6 = ARMv5TEJ.
                                                                 0x7 = ARMv6.
                                                                 0xF = Defined by CPUID scheme.
                                                                 _ All other values are reserved. */
		uint32_t partnum                     : 12; /**< R/W - An implementation defined primary part number for the device.
                                                                 On processors implemented by ARM, if the top four bits of the
                                                                     primary part number are 0x00x7. */
		uint32_t revision                    : 4;  /**< R/W - An implementation defined revision number for the device. */
#else
		uint32_t revision                    : 4;
		uint32_t partnum                     : 12;
		uint32_t architecture                : 4;
		uint32_t variant                     : 4;
		uint32_t implementer                 : 8;
#endif
	} s;
	/* struct bdk_ap_vpidr_el2_s          cn88xx; */
	/* struct bdk_ap_vpidr_el2_s          cn88xxp1; */
} bdk_ap_vpidr_el2_t;

#define BDK_AP_VPIDR_EL2 BDK_AP_VPIDR_EL2_FUNC()
static inline uint64_t BDK_AP_VPIDR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_VPIDR_EL2_FUNC(void)
{
	return 0x0000030400000000ull;
}
#define typedef_BDK_AP_VPIDR_EL2 bdk_ap_vpidr_el2_t
#define bustype_BDK_AP_VPIDR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_VPIDR_EL2 0
#define arguments_BDK_AP_VPIDR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_VPIDR_EL2 "AP_VPIDR_EL2"


/**
 * SYSREG - ap_vtcr_el2
 *
 * Controls the translation table walks required for the stage 2
 * translation of memory accesses from non-secure EL0 and EL1,
 * and holds cacheability and shareability information for the
 * accesses.
 */
typedef union bdk_ap_vtcr_el2 {
	uint32_t u;
	struct bdk_ap_vtcr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rsvd_31                     : 1;  /**< RO - Reserved 1. */
		uint32_t reserved_20_30              : 11;
		uint32_t vs                          : 1;  /**< R/W - VMID size.
                                                                 0 = 8 bits.
                                                                 1 = 16 bits. */
		uint32_t ps                          : 3;  /**< R/W - Physical Address Size.

                                                                 0x0 = 32 bits, 4GB.
                                                                 0x1 = 36 bits, 64GB.
                                                                 0x2 = 40 bits, 1TB.
                                                                 0x3 = 42 bits, 4TB.
                                                                 0x4 = 44 bits, 16TB.
                                                                 0x5 = 48 bits, 256TB. */
		uint32_t tg0                         : 2;  /**< R/W - Granule size for the corresponding translation table base
                                                                     address register.

                                                                 If the value is programmed to either a reserved value, or a
                                                                     size that has not been implemented, then the hardware will
                                                                     treat the field as if it has been programmed to an
                                                                     implementation defined choice of the sizes that has been
                                                                     implemented for all purposes other than the value read back
                                                                     from this register.

                                                                 It is implementation defined whether the value read back is
                                                                     the value programmed or the value that corresponds to the size
                                                                     chosen.

                                                                 0x0 = 4 KB.
                                                                 0x1 = 64 KB.
                                                                 0x2 = 16 KB. */
		uint32_t sh0                         : 2;  /**< R/W - Shareability attribute for memory associated with translation
                                                                     table walks using AP_VTTBR_EL2.
                                                                 0x0 = Non-shareable.
                                                                 0x2 = Outer shareable.
                                                                 0x3 = Inner shareable. */
		uint32_t orgn0                       : 2;  /**< R/W - Outer cacheability attribute for memory associated with
                                                                     translation table walks using AP_VTTBR_EL2.
                                                                 0x0 = Normal memory, outer non-cacheable.
                                                                 0x1 = Normal memory, outer write-back write-allocate cacheable.
                                                                 0x2 = Normal memory, outer write-through cacheable.
                                                                 0x3 = Normal memory, outer write-back no write-allocate cacheable. */
		uint32_t irgn0                       : 2;  /**< R/W - Inner cacheability attribute for memory associated with
                                                                     translation table walks using AP_VTTBR_EL2.
                                                                 0x0 = Normal memory, inner non-cacheable
                                                                 0x1 = Normal memory, inner write-back write-allocate cacheable
                                                                 0x2 = Normal memory, inner write-through cacheable
                                                                 0x3 = Normal memory, inner write-back no write-allocate cacheable */
		uint32_t sl0                         : 2;  /**< R/W - Starting level of the AP_VTCR_EL2 addressed region. The meaning
                                                                 of this field depends on the value of AP_VTCR_EL2[TG0] (the
                                                                 granule size). */
		uint32_t t0sz                        : 6;  /**< R/W - The size offset of the memory region addressed by AP_VTTBR_EL2.
                                                                     The region size is 22^(64-T0SZ) bytes.
                                                                 The maximum and minimum possible values for T0SZ depend on the
                                                                     level of translation table and the memory translation granule
                                                                     size, as described in the AArch64 Virtual Memory System
                                                                     Architecture chapter. */
#else
		uint32_t t0sz                        : 6;
		uint32_t sl0                         : 2;
		uint32_t irgn0                       : 2;
		uint32_t orgn0                       : 2;
		uint32_t sh0                         : 2;
		uint32_t tg0                         : 2;
		uint32_t ps                          : 3;
		uint32_t vs                          : 1;
		uint32_t reserved_20_30              : 11;
		uint32_t rsvd_31                     : 1;
#endif
	} s;
	/* struct bdk_ap_vtcr_el2_s           cn88xx; */
	/* struct bdk_ap_vtcr_el2_s           cn88xxp1; */
} bdk_ap_vtcr_el2_t;

#define BDK_AP_VTCR_EL2 BDK_AP_VTCR_EL2_FUNC()
static inline uint64_t BDK_AP_VTCR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_VTCR_EL2_FUNC(void)
{
	return 0x0000030402010200ull;
}
#define typedef_BDK_AP_VTCR_EL2 bdk_ap_vtcr_el2_t
#define bustype_BDK_AP_VTCR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_VTCR_EL2 0
#define arguments_BDK_AP_VTCR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_VTCR_EL2 "AP_VTCR_EL2"


/**
 * SYSREG - ap_vttbr_el2
 *
 * Holds the base address of the translation table for the stage
 * 2 translation of memory accesses from non-secure EL0 and EL1.
 */
typedef union bdk_ap_vttbr_el2 {
	uint64_t u;
	struct bdk_ap_vttbr_el2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t vmid                        : 16; /**< R/W - The VMID for the translation table. Expanded to 16 bits
                                                                 by the ARM Large System Extensions. */
		uint64_t baddr                       : 44; /**< R/W - Translation table base address, bits\<47:x\>. Bits \<x-1:0\> are
                                                                     RES0.

                                                                 x is based on the value of AP_VTCR_EL2[T0SZ], the stage of
                                                                     translation, and the memory translation granule size.
                                                                 The AArch64 Virtual Memory System Architecture chapter
                                                                     describes how x is calculated.
                                                                 The value of x determines the required alignment of the
                                                                     translation table, which must be aligned to 22^(x)
                                                                     bytes.

                                                                 If bits \<x-1:0\> are not all zero, this is a misaligned
                                                                     Translation Table Base Address. Its effects are CONSTRAINED
                                                                     UNPREDICTABLE, and can be one of the following:

                                                                 Bits \<x-1:0\> are treated as if all the bits are zero. The
                                                                     value read back from those bits might be the value written or
                                                                     might be zero.

                                                                 The calculation of an address for a translation table walk
                                                                     using this register can be corrupted in those bits that are
                                                                     non-zero. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t baddr                       : 44;
		uint64_t vmid                        : 16;
#endif
	} s;
	/* struct bdk_ap_vttbr_el2_s          cn88xx; */
	/* struct bdk_ap_vttbr_el2_s          cn88xxp1; */
} bdk_ap_vttbr_el2_t;

#define BDK_AP_VTTBR_EL2 BDK_AP_VTTBR_EL2_FUNC()
static inline uint64_t BDK_AP_VTTBR_EL2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_AP_VTTBR_EL2_FUNC(void)
{
	return 0x0000030402010000ull;
}
#define typedef_BDK_AP_VTTBR_EL2 bdk_ap_vttbr_el2_t
#define bustype_BDK_AP_VTTBR_EL2 BDK_CSR_TYPE_SYSREG
#define busnum_BDK_AP_VTTBR_EL2 0
#define arguments_BDK_AP_VTTBR_EL2 -1,-1,-1,-1
#define basename_BDK_AP_VTTBR_EL2 "AP_VTTBR_EL2"

#endif /* __BDK_CSRS_AP__ */
