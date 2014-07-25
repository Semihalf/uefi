#ifndef __BDK_CSRS_DAB_TRC__
#define __BDK_CSRS_DAB_TRC__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Networks (support@cavium.com). All rights
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

 *   * Neither the name of Cavium Networks nor the names of
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
 * Cavium DAB_TRC.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * DAB32b - trc#_trcacatr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacatr0 {
	uint32_t u;
	struct bdk_trcx_trcacatr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacatr0_s        cn85xx; */
	/* struct bdk_trcx_trcacatr0_s        cn88xx; */
} bdk_trcx_trcacatr0_t;

static inline uint64_t BDK_TRCX_TRCACATR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACATR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30480ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACATR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACATR0(...) bdk_trcx_trcacatr0_t
#define bustype_BDK_TRCX_TRCACATR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACATR0(p1) (p1)
#define arguments_BDK_TRCX_TRCACATR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACATR0(...) "TRCX_TRCACATR0"


/**
 * DAB32b - trc#_trcacatr1
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacatr1 {
	uint32_t u;
	struct bdk_trcx_trcacatr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacatr1_s        cn85xx; */
	/* struct bdk_trcx_trcacatr1_s        cn88xx; */
} bdk_trcx_trcacatr1_t;

static inline uint64_t BDK_TRCX_TRCACATR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACATR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30488ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACATR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACATR1(...) bdk_trcx_trcacatr1_t
#define bustype_BDK_TRCX_TRCACATR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACATR1(p1) (p1)
#define arguments_BDK_TRCX_TRCACATR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACATR1(...) "TRCX_TRCACATR1"


/**
 * DAB32b - trc#_trcacatr2
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacatr2 {
	uint32_t u;
	struct bdk_trcx_trcacatr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacatr2_s        cn85xx; */
	/* struct bdk_trcx_trcacatr2_s        cn88xx; */
} bdk_trcx_trcacatr2_t;

static inline uint64_t BDK_TRCX_TRCACATR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACATR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30490ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACATR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACATR2(...) bdk_trcx_trcacatr2_t
#define bustype_BDK_TRCX_TRCACATR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACATR2(p1) (p1)
#define arguments_BDK_TRCX_TRCACATR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACATR2(...) "TRCX_TRCACATR2"


/**
 * DAB32b - trc#_trcacatr3
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacatr3 {
	uint32_t u;
	struct bdk_trcx_trcacatr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacatr3_s        cn85xx; */
	/* struct bdk_trcx_trcacatr3_s        cn88xx; */
} bdk_trcx_trcacatr3_t;

static inline uint64_t BDK_TRCX_TRCACATR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACATR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30498ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACATR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACATR3(...) bdk_trcx_trcacatr3_t
#define bustype_BDK_TRCX_TRCACATR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACATR3(p1) (p1)
#define arguments_BDK_TRCX_TRCACATR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACATR3(...) "TRCX_TRCACATR3"


/**
 * DAB32b - trc#_trcacvr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacvr0 {
	uint32_t u;
	struct bdk_trcx_trcacvr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacvr0_s         cn85xx; */
	/* struct bdk_trcx_trcacvr0_s         cn88xx; */
} bdk_trcx_trcacvr0_t;

static inline uint64_t BDK_TRCX_TRCACVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30400ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACVR0(...) bdk_trcx_trcacvr0_t
#define bustype_BDK_TRCX_TRCACVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCACVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACVR0(...) "TRCX_TRCACVR0"


/**
 * DAB32b - trc#_trcacvr1
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacvr1 {
	uint32_t u;
	struct bdk_trcx_trcacvr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacvr1_s         cn85xx; */
	/* struct bdk_trcx_trcacvr1_s         cn88xx; */
} bdk_trcx_trcacvr1_t;

static inline uint64_t BDK_TRCX_TRCACVR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACVR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30408ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACVR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACVR1(...) bdk_trcx_trcacvr1_t
#define bustype_BDK_TRCX_TRCACVR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACVR1(p1) (p1)
#define arguments_BDK_TRCX_TRCACVR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACVR1(...) "TRCX_TRCACVR1"


/**
 * DAB32b - trc#_trcacvr2
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacvr2 {
	uint32_t u;
	struct bdk_trcx_trcacvr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacvr2_s         cn85xx; */
	/* struct bdk_trcx_trcacvr2_s         cn88xx; */
} bdk_trcx_trcacvr2_t;

static inline uint64_t BDK_TRCX_TRCACVR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACVR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30410ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACVR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACVR2(...) bdk_trcx_trcacvr2_t
#define bustype_BDK_TRCX_TRCACVR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACVR2(p1) (p1)
#define arguments_BDK_TRCX_TRCACVR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACVR2(...) "TRCX_TRCACVR2"


/**
 * DAB32b - trc#_trcacvr3
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcacvr3 {
	uint32_t u;
	struct bdk_trcx_trcacvr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcacvr3_s         cn85xx; */
	/* struct bdk_trcx_trcacvr3_s         cn88xx; */
} bdk_trcx_trcacvr3_t;

static inline uint64_t BDK_TRCX_TRCACVR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCACVR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30418ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCACVR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCACVR3(...) bdk_trcx_trcacvr3_t
#define bustype_BDK_TRCX_TRCACVR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCACVR3(p1) (p1)
#define arguments_BDK_TRCX_TRCACVR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCACVR3(...) "TRCX_TRCACVR3"


/**
 * DAB32b - trc#_trcauthstatus
 *
 * Provides information about the state of the implementation defined authentication
 * interface.
 */
typedef union bdk_trcx_trcauthstatus {
	uint32_t u;
	struct bdk_trcx_trcauthstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t nsnid                       : 2;  /**< RO - If EL3 is not implemented and the processor is Secure, holds
                                                                     the same value as DBGAUTHSTATUS_EL1.SNID.
                                                                 Otherwise, holds the same value as DBGAUTHSTATUS_EL1.NSNID. */
		uint32_t nsid                        : 2;  /**< RO - If EL3 is not implemented and the processor is Secure, holds
                                                                     the same value as DBGAUTHSTATUS_EL1.SID.
                                                                 Otherwise, holds the same value as DBGAUTHSTATUS_EL1.NSID. */
#else
		uint32_t nsid                        : 2;
		uint32_t nsnid                       : 2;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_trcx_trcauthstatus_s    cn85xx; */
	/* struct bdk_trcx_trcauthstatus_s    cn88xx; */
} bdk_trcx_trcauthstatus_t;

static inline uint64_t BDK_TRCX_TRCAUTHSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCAUTHSTATUS(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FB8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCAUTHSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCAUTHSTATUS(...) bdk_trcx_trcauthstatus_t
#define bustype_BDK_TRCX_TRCAUTHSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCAUTHSTATUS(p1) (p1)
#define arguments_BDK_TRCX_TRCAUTHSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCAUTHSTATUS(...) "TRCX_TRCAUTHSTATUS"


/**
 * DAB32b - trc#_trcauxctlr
 *
 * implementation defines
 *
 */
typedef union bdk_trcx_trcauxctlr {
	uint32_t u;
	struct bdk_trcx_trcauxctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcauxctlr_s       cn85xx; */
	/* struct bdk_trcx_trcauxctlr_s       cn88xx; */
} bdk_trcx_trcauxctlr_t;

static inline uint64_t BDK_TRCX_TRCAUXCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCAUXCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30018ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCAUXCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCAUXCTLR(...) bdk_trcx_trcauxctlr_t
#define bustype_BDK_TRCX_TRCAUXCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCAUXCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCAUXCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCAUXCTLR(...) "TRCX_TRCAUXCTLR"


/**
 * DAB32b - trc#_trcbbctlr
 *
 * Controls which region in the memory map is enabled to use branch broadcasting.
 *
 */
typedef union bdk_trcx_trcbbctlr {
	uint32_t u;
	struct bdk_trcx_trcbbctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t mode                        : 1;  /**< R/W - Mode bit.
                                                                 0 = Exclude mode. Branch Broadcasting is not enabled for
                                                                     branch instructions in the address range that the Range defines.
                                                                 1 = Include mode. Branch Broadcasting is enabled for
                                                                     branch instructions in the address range that the Range defines. */
		uint32_t range                       : 8;  /**< R/W - Address range fields. Select which address range comparator pairs is in use
                                                                 with branch broadcasting. Bit[n] controls address comparator pair[n]:
                                                                 0 = pair[n] is not selected.
                                                                 1 = pair[n] is selected. */
#else
		uint32_t range                       : 8;
		uint32_t mode                        : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_trcx_trcbbctlr_s        cn85xx; */
	/* struct bdk_trcx_trcbbctlr_s        cn88xx; */
} bdk_trcx_trcbbctlr_t;

static inline uint64_t BDK_TRCX_TRCBBCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCBBCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3003Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCBBCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCBBCTLR(...) bdk_trcx_trcbbctlr_t
#define bustype_BDK_TRCX_TRCBBCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCBBCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCBBCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCBBCTLR(...) "TRCX_TRCBBCTLR"


/**
 * DAB32b - trc#_trcccctlr
 *
 * Set the threshold value for cycle counting.
 *
 */
typedef union bdk_trcx_trcccctlr {
	uint32_t u;
	struct bdk_trcx_trcccctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t threshold                   : 12; /**< R/W - Set the threshold value for the instruction cycle counting. */
#else
		uint32_t threshold                   : 12;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_trcx_trcccctlr_s        cn85xx; */
	/* struct bdk_trcx_trcccctlr_s        cn88xx; */
} bdk_trcx_trcccctlr_t;

static inline uint64_t BDK_TRCX_TRCCCCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCCCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30038ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCCCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCCCTLR(...) bdk_trcx_trcccctlr_t
#define bustype_BDK_TRCX_TRCCCCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCCCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCCCCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCCCTLR(...) "TRCX_TRCCCCTLR"


/**
 * DAB32b - trc#_trccidcctlr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trccidcctlr0 {
	uint32_t u;
	struct bdk_trcx_trccidcctlr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trccidcctlr0_s     cn85xx; */
	/* struct bdk_trcx_trccidcctlr0_s     cn88xx; */
} bdk_trcx_trccidcctlr0_t;

static inline uint64_t BDK_TRCX_TRCCIDCCTLR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDCCTLR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30680ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDCCTLR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDCCTLR0(...) bdk_trcx_trccidcctlr0_t
#define bustype_BDK_TRCX_TRCCIDCCTLR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDCCTLR0(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDCCTLR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDCCTLR0(...) "TRCX_TRCCIDCCTLR0"


/**
 * DAB32b - trc#_trccidcctlr1
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trccidcctlr1 {
	uint32_t u;
	struct bdk_trcx_trccidcctlr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trccidcctlr1_s     cn85xx; */
	/* struct bdk_trcx_trccidcctlr1_s     cn88xx; */
} bdk_trcx_trccidcctlr1_t;

static inline uint64_t BDK_TRCX_TRCCIDCCTLR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDCCTLR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30684ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDCCTLR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDCCTLR1(...) bdk_trcx_trccidcctlr1_t
#define bustype_BDK_TRCX_TRCCIDCCTLR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDCCTLR1(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDCCTLR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDCCTLR1(...) "TRCX_TRCCIDCCTLR1"


/**
 * DAB32b - trc#_trccidcvr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trccidcvr0 {
	uint32_t u;
	struct bdk_trcx_trccidcvr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trccidcvr0_s       cn85xx; */
	/* struct bdk_trcx_trccidcvr0_s       cn88xx; */
} bdk_trcx_trccidcvr0_t;

static inline uint64_t BDK_TRCX_TRCCIDCVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDCVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30600ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDCVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDCVR0(...) bdk_trcx_trccidcvr0_t
#define bustype_BDK_TRCX_TRCCIDCVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDCVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDCVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDCVR0(...) "TRCX_TRCCIDCVR0"


/**
 * DAB32b - trc#_trccidr0
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trccidr0 {
	uint32_t u;
	struct bdk_trcx_trccidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_0                     : 8;  /**< RO - Preamble. Must read as 0x0D. */
#else
		uint32_t prmbl_0                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trccidr0_s         cn85xx; */
	/* struct bdk_trcx_trccidr0_s         cn88xx; */
} bdk_trcx_trccidr0_t;

static inline uint64_t BDK_TRCX_TRCCIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FF0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDR0(...) bdk_trcx_trccidr0_t
#define bustype_BDK_TRCX_TRCCIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDR0(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDR0(...) "TRCX_TRCCIDR0"


/**
 * DAB32b - trc#_trccidr1
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trccidr1 {
	uint32_t u;
	struct bdk_trcx_trccidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< RO - Component class. 0x9 = Debug component. */
		uint32_t prmbl_1                     : 4;  /**< RO - Preamble. RAZ. */
#else
		uint32_t prmbl_1                     : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trccidr1_s         cn85xx; */
	/* struct bdk_trcx_trccidr1_s         cn88xx; */
} bdk_trcx_trccidr1_t;

static inline uint64_t BDK_TRCX_TRCCIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FF4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDR1(...) bdk_trcx_trccidr1_t
#define bustype_BDK_TRCX_TRCCIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDR1(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDR1(...) "TRCX_TRCCIDR1"


/**
 * DAB32b - trc#_trccidr2
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trccidr2 {
	uint32_t u;
	struct bdk_trcx_trccidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_2                     : 8;  /**< RO - Preamble. Must read as 0x05. */
#else
		uint32_t prmbl_2                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trccidr2_s         cn85xx; */
	/* struct bdk_trcx_trccidr2_s         cn88xx; */
} bdk_trcx_trccidr2_t;

static inline uint64_t BDK_TRCX_TRCCIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FF8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDR2(...) bdk_trcx_trccidr2_t
#define bustype_BDK_TRCX_TRCCIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDR2(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDR2(...) "TRCX_TRCCIDR2"


/**
 * DAB32b - trc#_trccidr3
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trccidr3 {
	uint32_t u;
	struct bdk_trcx_trccidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_3                     : 8;  /**< RO - Preamble. Must read as 0xB1. */
#else
		uint32_t prmbl_3                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trccidr3_s         cn85xx; */
	/* struct bdk_trcx_trccidr3_s         cn88xx; */
} bdk_trcx_trccidr3_t;

static inline uint64_t BDK_TRCX_TRCCIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCIDR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FFCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCIDR3(...) bdk_trcx_trccidr3_t
#define bustype_BDK_TRCX_TRCCIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCIDR3(p1) (p1)
#define arguments_BDK_TRCX_TRCCIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCIDR3(...) "TRCX_TRCCIDR3"


/**
 * DAB32b - trc#_trccntctlr0
 *
 * Control the operation of counter n.
 *
 */
typedef union bdk_trcx_trccntctlr0 {
	uint32_t u;
	struct bdk_trcx_trccntctlr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_18_31              : 14;
		uint32_t cntchain                    : 1;  /**< R/W - control whether counter n decrements when the reload event of counter n-1 occurs.
                                                                 0 = Counter n does not decrement when the reload event of counter n-1 occurs.
                                                                 1 = Counter n decrement when the reload event of counter n-1 occurs. */
		uint32_t rldself                     : 1;  /**< R/W - control whether counter n reload occur when counter n reaches zero.
                                                                 0 = Counter is in normal mode
                                                                 1 = Counter is in reload mode */
		uint32_t rldevent                    : 8;  /**< R/W - Select an event when it occurs, cause a reload event for counter n */
		uint32_t cntevent                    : 8;  /**< R/W - Select an event when it occurs, cause counter n to decrement. */
#else
		uint32_t cntevent                    : 8;
		uint32_t rldevent                    : 8;
		uint32_t rldself                     : 1;
		uint32_t cntchain                    : 1;
		uint32_t reserved_18_31              : 14;
#endif
	} s;
	/* struct bdk_trcx_trccntctlr0_s      cn85xx; */
	/* struct bdk_trcx_trccntctlr0_s      cn88xx; */
} bdk_trcx_trccntctlr0_t;

static inline uint64_t BDK_TRCX_TRCCNTCTLR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCNTCTLR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30150ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCNTCTLR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCNTCTLR0(...) bdk_trcx_trccntctlr0_t
#define bustype_BDK_TRCX_TRCCNTCTLR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCNTCTLR0(p1) (p1)
#define arguments_BDK_TRCX_TRCCNTCTLR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCNTCTLR0(...) "TRCX_TRCCNTCTLR0"


/**
 * DAB32b - trc#_trccntctlr1
 *
 * Control the operation of counter n.
 *
 */
typedef union bdk_trcx_trccntctlr1 {
	uint32_t u;
	struct bdk_trcx_trccntctlr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_18_31              : 14;
		uint32_t cntchain                    : 1;  /**< R/W - control whether counter n decrements when the reload event of counter n-1 occurs.
                                                                 0 = Counter n does not decrement when the reload event of counter n-1 occurs.
                                                                 1 = Counter n decrement when the reload event of counter n-1 occurs. */
		uint32_t rldself                     : 1;  /**< R/W - control whether counter n reload occur when counter n reaches zero.
                                                                 0 = Counter is in normal mode
                                                                 1 = Counter is in reload mode */
		uint32_t rldevent                    : 8;  /**< R/W - Select an event when it occurs, cause a reload event for counter n */
		uint32_t cntevent                    : 8;  /**< R/W - Select an event when it occurs, cause counter n to decrement. */
#else
		uint32_t cntevent                    : 8;
		uint32_t rldevent                    : 8;
		uint32_t rldself                     : 1;
		uint32_t cntchain                    : 1;
		uint32_t reserved_18_31              : 14;
#endif
	} s;
	/* struct bdk_trcx_trccntctlr1_s      cn85xx; */
	/* struct bdk_trcx_trccntctlr1_s      cn88xx; */
} bdk_trcx_trccntctlr1_t;

static inline uint64_t BDK_TRCX_TRCCNTCTLR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCNTCTLR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30154ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCNTCTLR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCNTCTLR1(...) bdk_trcx_trccntctlr1_t
#define bustype_BDK_TRCX_TRCCNTCTLR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCNTCTLR1(p1) (p1)
#define arguments_BDK_TRCX_TRCCNTCTLR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCNTCTLR1(...) "TRCX_TRCCNTCTLR1"


/**
 * DAB32b - trc#_trccntrldvr0
 *
 * set or read the reload counter value for counter n
 *
 */
typedef union bdk_trcx_trccntrldvr0 {
	uint32_t u;
	struct bdk_trcx_trccntrldvr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t value                       : 16; /**< R/W - Contains the reload counter value for counter n */
#else
		uint32_t value                       : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trccntrldvr0_s     cn85xx; */
	/* struct bdk_trcx_trccntrldvr0_s     cn88xx; */
} bdk_trcx_trccntrldvr0_t;

static inline uint64_t BDK_TRCX_TRCCNTRLDVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCNTRLDVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30140ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCNTRLDVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCNTRLDVR0(...) bdk_trcx_trccntrldvr0_t
#define bustype_BDK_TRCX_TRCCNTRLDVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCNTRLDVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCCNTRLDVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCNTRLDVR0(...) "TRCX_TRCCNTRLDVR0"


/**
 * DAB32b - trc#_trccntrldvr1
 *
 * set or read the reload counter value for counter n
 *
 */
typedef union bdk_trcx_trccntrldvr1 {
	uint32_t u;
	struct bdk_trcx_trccntrldvr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t value                       : 16; /**< R/W - Contains the reload counter value for counter n */
#else
		uint32_t value                       : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trccntrldvr1_s     cn85xx; */
	/* struct bdk_trcx_trccntrldvr1_s     cn88xx; */
} bdk_trcx_trccntrldvr1_t;

static inline uint64_t BDK_TRCX_TRCCNTRLDVR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCNTRLDVR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30144ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCNTRLDVR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCNTRLDVR1(...) bdk_trcx_trccntrldvr1_t
#define bustype_BDK_TRCX_TRCCNTRLDVR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCNTRLDVR1(p1) (p1)
#define arguments_BDK_TRCX_TRCCNTRLDVR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCNTRLDVR1(...) "TRCX_TRCCNTRLDVR1"


/**
 * DAB32b - trc#_trccntvr0
 *
 * return the value of counter n.
 *
 */
typedef union bdk_trcx_trccntvr0 {
	uint32_t u;
	struct bdk_trcx_trccntvr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t value                       : 16; /**< R/W - Contains the count value of counter n. */
#else
		uint32_t value                       : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trccntvr0_s        cn85xx; */
	/* struct bdk_trcx_trccntvr0_s        cn88xx; */
} bdk_trcx_trccntvr0_t;

static inline uint64_t BDK_TRCX_TRCCNTVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCNTVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30160ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCNTVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCNTVR0(...) bdk_trcx_trccntvr0_t
#define bustype_BDK_TRCX_TRCCNTVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCNTVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCCNTVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCNTVR0(...) "TRCX_TRCCNTVR0"


/**
 * DAB32b - trc#_trccntvr1
 *
 * return the value of counter n.
 *
 */
typedef union bdk_trcx_trccntvr1 {
	uint32_t u;
	struct bdk_trcx_trccntvr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t value                       : 16; /**< R/W - Contains the count value of counter n. */
#else
		uint32_t value                       : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trccntvr1_s        cn85xx; */
	/* struct bdk_trcx_trccntvr1_s        cn88xx; */
} bdk_trcx_trccntvr1_t;

static inline uint64_t BDK_TRCX_TRCCNTVR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCNTVR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30164ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCNTVR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCNTVR1(...) bdk_trcx_trccntvr1_t
#define bustype_BDK_TRCX_TRCCNTVR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCNTVR1(p1) (p1)
#define arguments_BDK_TRCX_TRCCNTVR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCNTVR1(...) "TRCX_TRCCNTVR1"


/**
 * DAB32b - trc#_trcconfigr
 *
 * Control the trace unit options.
 *
 */
typedef union bdk_trcx_trcconfigr {
	uint32_t u;
	struct bdk_trcx_trcconfigr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_18_31              : 14;
		uint32_t dv                          : 1;  /**< R/W - Data Value tracing bit.
                                                                 0 = The data value tracing is disabled.
                                                                 1 = The data value tracing is enabled when INSTP0 is not 0x0. */
		uint32_t da                          : 1;  /**< R/W - Data Address tracing bit.
                                                                 0 = The data address tracing is disabled.
                                                                 1 = The data address tracing is enabled when INSTP0 is not 0x0. */
		uint32_t reserved_15_15              : 1;
		uint32_t qe                          : 2;  /**< R/W - Q Element enable field.
                                                                 0x0 = Q elements are disabled.
                                                                 0x1 = Q elements with instruction counts are enabled.
                                                                      Q elements without instruction counts are disabled.
                                                                 0x2 = Reserved.
                                                                 0x3 Q elements with and without instruction counts are enabled.

                                                                 These fields must be set to 0x0 if any of the following are true:
                                                                      1. TRCCONFIGR.INSTP0 is not 0x0.
                                                                      2. TRCCONFIGR.COND is not 0x0.
                                                                      3. TRCCONFIGR.BB is not 0. */
		uint32_t rs                          : 1;  /**< R/W - Return stack enable bit.
                                                                 0 = Return stack is not enabled.
                                                                 1 = Return stack is enabled. */
		uint32_t ts                          : 1;  /**< R/W - Global timestamp tracing bit.
                                                                 0 = Global timestamp tracing is not enabled.
                                                                 1 = Global timestamp tracing is enabled. */
		uint32_t cond                        : 3;  /**< R/W - Conditional instruction tracing bit. The permitted values are:
                                                                 0x0 = Conditional instruction tracing is disabled.
                                                                 0x1 = Conditional load instructions are traced.
                                                                 0x2 = Conditional store instructions are traced.
                                                                 0x3 = Conditional load and store instructions are traced.
                                                                 0x7 = All conditional instructions are traced.
                                                                 all other values are reserved. */
		uint32_t vmid                        : 1;  /**< R/W - VMID tracing bit.
                                                                 0 = VMID tracing is disabled.
                                                                 1 = VMID tracing is enabled. */
		uint32_t cid                         : 1;  /**< R/W - Context ID tracing bit.
                                                                 0 = Context ID tracing is disabled.
                                                                 1 = Context ID tracing is enabled. */
		uint32_t reserved_5_5                : 1;
		uint32_t cci                         : 1;  /**< R/W - Cycle counting instruction trace bit.
                                                                 0 = Cycle counting in instruction trace is disabled.
                                                                 1 = Cycle counting in instruction trace is enabled. */
		uint32_t bb                          : 1;  /**< R/W - Branch broadcast mode bit.
                                                                 0 = Branch broadcast mode is disabled.
                                                                 1 = Branch broadcast mode is enabled. */
		uint32_t instp0                      : 2;  /**< R/W - Instruction P0 fields. This field control whether load and store instructions
                                                                   trace are traced as P0 instructions:
                                                                 0x0 = Do not trace load and store instructions as P0 instructions.
                                                                 0x1 = Trace load instructions as P0 instructions.
                                                                 0x2 = Trace store instructions as P0 instructions.
                                                                 0x3 = Trace load and store instructions as P0 instructions. */
		uint32_t b0                          : 1;
#else
		uint32_t b0                          : 1;
		uint32_t instp0                      : 2;
		uint32_t bb                          : 1;
		uint32_t cci                         : 1;
		uint32_t reserved_5_5                : 1;
		uint32_t cid                         : 1;
		uint32_t vmid                        : 1;
		uint32_t cond                        : 3;
		uint32_t ts                          : 1;
		uint32_t rs                          : 1;
		uint32_t qe                          : 2;
		uint32_t reserved_15_15              : 1;
		uint32_t da                          : 1;
		uint32_t dv                          : 1;
		uint32_t reserved_18_31              : 14;
#endif
	} s;
	/* struct bdk_trcx_trcconfigr_s       cn85xx; */
	/* struct bdk_trcx_trcconfigr_s       cn88xx; */
} bdk_trcx_trcconfigr_t;

static inline uint64_t BDK_TRCX_TRCCONFIGR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCCONFIGR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30010ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCCONFIGR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCCONFIGR(...) bdk_trcx_trcconfigr_t
#define bustype_BDK_TRCX_TRCCONFIGR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCCONFIGR(p1) (p1)
#define arguments_BDK_TRCX_TRCCONFIGR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCCONFIGR(...) "TRCX_TRCCONFIGR"


/**
 * DAB32b - trc#_trcdevaff0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcdevaff0 {
	uint32_t u;
	struct bdk_trcx_trcdevaff0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcdevaff0_s       cn85xx; */
	/* struct bdk_trcx_trcdevaff0_s       cn88xx; */
} bdk_trcx_trcdevaff0_t;

static inline uint64_t BDK_TRCX_TRCDEVAFF0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDEVAFF0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FA8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDEVAFF0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDEVAFF0(...) bdk_trcx_trcdevaff0_t
#define bustype_BDK_TRCX_TRCDEVAFF0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDEVAFF0(p1) (p1)
#define arguments_BDK_TRCX_TRCDEVAFF0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDEVAFF0(...) "TRCX_TRCDEVAFF0"


/**
 * DAB32b - trc#_trcdevaff1
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcdevaff1 {
	uint32_t u;
	struct bdk_trcx_trcdevaff1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcdevaff1_s       cn85xx; */
	/* struct bdk_trcx_trcdevaff1_s       cn88xx; */
} bdk_trcx_trcdevaff1_t;

static inline uint64_t BDK_TRCX_TRCDEVAFF1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDEVAFF1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FACull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDEVAFF1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDEVAFF1(...) bdk_trcx_trcdevaff1_t
#define bustype_BDK_TRCX_TRCDEVAFF1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDEVAFF1(p1) (p1)
#define arguments_BDK_TRCX_TRCDEVAFF1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDEVAFF1(...) "TRCX_TRCDEVAFF1"


/**
 * DAB32b - trc#_trcdevarch
 *
 * Identifies the programmers' model architecture.
 *
 */
typedef union bdk_trcx_trcdevarch {
	uint32_t u;
	struct bdk_trcx_trcdevarch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t architect                   : 11; /**< RO - Defines the architecture of the component. This is ARM Limited.

                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.

                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
		uint32_t present                     : 1;  /**< RO - When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
		uint32_t revision                    : 4;  /**< RO - Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For TRC, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
		uint32_t archid                      : 16; /**< RO - Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For TRC:
                                                                  Bits [15:12] are the architecture version, 0x1.
                                                                  Bits [11:0] are the architecture part number, 0xA14.
                                                                 This corresponds to TRC architecture version TRCv2. */
#else
		uint32_t archid                      : 16;
		uint32_t revision                    : 4;
		uint32_t present                     : 1;
		uint32_t architect                   : 11;
#endif
	} s;
	/* struct bdk_trcx_trcdevarch_s       cn85xx; */
	/* struct bdk_trcx_trcdevarch_s       cn88xx; */
} bdk_trcx_trcdevarch_t;

static inline uint64_t BDK_TRCX_TRCDEVARCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDEVARCH(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FBCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDEVARCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDEVARCH(...) bdk_trcx_trcdevarch_t
#define bustype_BDK_TRCX_TRCDEVARCH(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDEVARCH(p1) (p1)
#define arguments_BDK_TRCX_TRCDEVARCH(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDEVARCH(...) "TRCX_TRCDEVARCH"


/**
 * DAB32b - trc#_trcdevid
 *
 * Describes the component to the debugger.
 *
 */
typedef union bdk_trcx_trcdevid {
	uint32_t u;
	struct bdk_trcx_trcdevid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t inout_gate                  : 2;  /**< RO - Input/output options. Indicates presence of the input gate. If
                                                                     the CTM is not implemented, this field is RAZ.
                                                                 All other values are reserved.
                                                                 0x0 = TRCGATE does not mask propagation of input events from
                                                                     external channels.
                                                                 0x1 = TRCGATE masks propagation of input events from external
                                                                     channels. */
		uint32_t reserved_22_23              : 2;
		uint32_t numchan                     : 6;  /**< RO - Number of ECT channels implemented. Implementation defined.
                                                                 For v8-A, valid values are:
                                                                 0x3 = 3 channels (0..2) implemented.
                                                                 0x4 = 4 channels (0..3) implemented.
                                                                 0x5 = 5 channels (0..4) implemented.
                                                                 0x6 = 6 channels (0..5) implemented.
                                                                 and so on up to 0x20.
                                                                 All other values are reserved. */
		uint32_t reserved_14_15              : 2;
		uint32_t numtrig                     : 6;  /**< RO - Number of triggers implemented. implementation defined. This
                                                                     is one more than the index of the largest trigger, rather than
                                                                     the actual number of triggers.
                                                                 For v8-A, valid values are:
                                                                 0x3 = Up to 3 triggers (0..2) implemented.
                                                                 0x8 = Up to 8 triggers (0..7) implemented.
                                                                 0x9 = Up to 9 triggers (0..8) implemented.
                                                                 0xa = Up to 10 triggers (0..9) implemented.
                                                                 and so on up to 0x20.

                                                                 All other values are reserved. If the Trace Extension is implemented, this field
                                                                 must be at least 0x8. There is no guarantee that any of the implemented
                                                                 triggers, including the highest numbered, are connected to any components. */
		uint32_t reserved_5_7                : 3;
		uint32_t extmuxnum                   : 5;  /**< RO - Maximum number of external triggers available for multiplexing
                                                                 into the TRC. This relates only to additional external
                                                                 triggers outside those defined for v8-A. */
#else
		uint32_t extmuxnum                   : 5;
		uint32_t reserved_5_7                : 3;
		uint32_t numtrig                     : 6;
		uint32_t reserved_14_15              : 2;
		uint32_t numchan                     : 6;
		uint32_t reserved_22_23              : 2;
		uint32_t inout_gate                  : 2;
		uint32_t reserved_26_31              : 6;
#endif
	} s;
	/* struct bdk_trcx_trcdevid_s         cn85xx; */
	/* struct bdk_trcx_trcdevid_s         cn88xx; */
} bdk_trcx_trcdevid_t;

static inline uint64_t BDK_TRCX_TRCDEVID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDEVID(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FC8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDEVID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDEVID(...) bdk_trcx_trcdevid_t
#define bustype_BDK_TRCX_TRCDEVID(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDEVID(p1) (p1)
#define arguments_BDK_TRCX_TRCDEVID(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDEVID(...) "TRCX_TRCDEVID"


/**
 * DAB32b - trc#_trcdevtype
 *
 * Indicates to a debugger that this component is part of a processor's cross-trigger
 * interface.
 */
typedef union bdk_trcx_trcdevtype {
	uint32_t u;
	struct bdk_trcx_trcdevtype_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t sub                         : 4;  /**< RO - Subtype. Must read as 0x1. */
		uint32_t major                       : 4;  /**< RO - Major type. Must read as 0x4. */
#else
		uint32_t major                       : 4;
		uint32_t sub                         : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcdevtype_s       cn85xx; */
	/* struct bdk_trcx_trcdevtype_s       cn88xx; */
} bdk_trcx_trcdevtype_t;

static inline uint64_t BDK_TRCX_TRCDEVTYPE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDEVTYPE(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FCCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDEVTYPE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDEVTYPE(...) bdk_trcx_trcdevtype_t
#define bustype_BDK_TRCX_TRCDEVTYPE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDEVTYPE(p1) (p1)
#define arguments_BDK_TRCX_TRCDEVTYPE(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDEVTYPE(...) "TRCX_TRCDEVTYPE"


/**
 * DAB32b - trc#_trcdvcmr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcdvcmr0 {
	uint32_t u;
	struct bdk_trcx_trcdvcmr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcdvcmr0_s        cn85xx; */
	/* struct bdk_trcx_trcdvcmr0_s        cn88xx; */
} bdk_trcx_trcdvcmr0_t;

static inline uint64_t BDK_TRCX_TRCDVCMR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDVCMR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30580ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDVCMR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDVCMR0(...) bdk_trcx_trcdvcmr0_t
#define bustype_BDK_TRCX_TRCDVCMR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDVCMR0(p1) (p1)
#define arguments_BDK_TRCX_TRCDVCMR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDVCMR0(...) "TRCX_TRCDVCMR0"


/**
 * DAB32b - trc#_trcdvcvr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcdvcvr0 {
	uint32_t u;
	struct bdk_trcx_trcdvcvr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcdvcvr0_s        cn85xx; */
	/* struct bdk_trcx_trcdvcvr0_s        cn88xx; */
} bdk_trcx_trcdvcvr0_t;

static inline uint64_t BDK_TRCX_TRCDVCVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCDVCVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30500ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCDVCVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCDVCVR0(...) bdk_trcx_trcdvcvr0_t
#define bustype_BDK_TRCX_TRCDVCVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCDVCVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCDVCVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCDVCVR0(...) "TRCX_TRCDVCVR0"


/**
 * DAB32b - trc#_trceventctl0r
 *
 * Control the tracing of arbitrary event.
 *
 */
typedef union bdk_trcx_trceventctl0r {
	uint32_t u;
	struct bdk_trcx_trceventctl0r_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t event3                      : 8;  /**< R/W - Only supported if TRCIDR0.NUMEVENT = 0x3. */
		uint32_t event2                      : 8;  /**< R/W - Only supported if TRCIDR0.NUMEVENT = 0x3, 0x2. */
		uint32_t event1                      : 8;  /**< R/W - Only supported if TRCIDR0.NUMEVENT = 0x3, 0x2, 0x1. */
		uint32_t event0                      : 8;  /**< R/W - always supported. */
#else
		uint32_t event0                      : 8;
		uint32_t event1                      : 8;
		uint32_t event2                      : 8;
		uint32_t event3                      : 8;
#endif
	} s;
	/* struct bdk_trcx_trceventctl0r_s    cn85xx; */
	/* struct bdk_trcx_trceventctl0r_s    cn88xx; */
} bdk_trcx_trceventctl0r_t;

static inline uint64_t BDK_TRCX_TRCEVENTCTL0R(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCEVENTCTL0R(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30020ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCEVENTCTL0R", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCEVENTCTL0R(...) bdk_trcx_trceventctl0r_t
#define bustype_BDK_TRCX_TRCEVENTCTL0R(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCEVENTCTL0R(p1) (p1)
#define arguments_BDK_TRCX_TRCEVENTCTL0R(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCEVENTCTL0R(...) "TRCX_TRCEVENTCTL0R"


/**
 * DAB32b - trc#_trceventctl1r
 *
 * Control the behavior of events that TRCEVENTCTL0R selects.
 *
 */
typedef union bdk_trcx_trceventctl1r {
	uint32_t u;
	struct bdk_trcx_trceventctl1r_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_13_31              : 19;
		uint32_t lpoverride                  : 1;  /**< R/W - Low power state over ride bit.
                                                                 0 = Trace unit low power state is not affected.
                                                                      The trace unit is enabled to enter low power state.
                                                                 1 = Trace unit low power behavior is overridden. */
		uint32_t atb                         : 1;  /**< R/W - AMBA trace bus trigger enable bit.
                                                                 0 = ATB trigger is disabled.
                                                                 1 = ATB trigger is enabled. */
		uint32_t reserved_5_10               : 6;
		uint32_t dataen                      : 1;  /**< R/W - Data event enable bit.
                                                                 0 = The trace unit does not generate an event element.
                                                                 1 = The trace unit generates an event element in the data trace stream. */
		uint32_t insten                      : 4;  /**< R/W - Instruction event[n] enable fields.
                                                                 0 = The trace unit does not generate an event[n] element.
                                                                 1 = The trace unit generates an event[n] element in the instruction trace stream. */
#else
		uint32_t insten                      : 4;
		uint32_t dataen                      : 1;
		uint32_t reserved_5_10               : 6;
		uint32_t atb                         : 1;
		uint32_t lpoverride                  : 1;
		uint32_t reserved_13_31              : 19;
#endif
	} s;
	/* struct bdk_trcx_trceventctl1r_s    cn85xx; */
	/* struct bdk_trcx_trceventctl1r_s    cn88xx; */
} bdk_trcx_trceventctl1r_t;

static inline uint64_t BDK_TRCX_TRCEVENTCTL1R(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCEVENTCTL1R(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30024ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCEVENTCTL1R", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCEVENTCTL1R(...) bdk_trcx_trceventctl1r_t
#define bustype_BDK_TRCX_TRCEVENTCTL1R(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCEVENTCTL1R(p1) (p1)
#define arguments_BDK_TRCX_TRCEVENTCTL1R(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCEVENTCTL1R(...) "TRCX_TRCEVENTCTL1R"


/**
 * DAB32b - trc#_trcextinselr
 *
 * set or read which external inputs are resources to trace unit.
 *
 */
typedef union bdk_trcx_trcextinselr {
	uint32_t u;
	struct bdk_trcx_trcextinselr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t sel3                        : 8;  /**< R/W - Select which external input is a resources to the trace unit. */
		uint32_t sel2                        : 8;  /**< R/W - Select which external input is a resources to the trace unit. */
		uint32_t sel1                        : 8;  /**< R/W - Select which external input is a resources to the trace unit. */
		uint32_t sel0                        : 8;  /**< R/W - Select which external input is a resources to the trace unit. */
#else
		uint32_t sel0                        : 8;
		uint32_t sel1                        : 8;
		uint32_t sel2                        : 8;
		uint32_t sel3                        : 8;
#endif
	} s;
	/* struct bdk_trcx_trcextinselr_s     cn85xx; */
	/* struct bdk_trcx_trcextinselr_s     cn88xx; */
} bdk_trcx_trcextinselr_t;

static inline uint64_t BDK_TRCX_TRCEXTINSELR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCEXTINSELR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30120ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCEXTINSELR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCEXTINSELR(...) bdk_trcx_trcextinselr_t
#define bustype_BDK_TRCX_TRCEXTINSELR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCEXTINSELR(p1) (p1)
#define arguments_BDK_TRCX_TRCEXTINSELR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCEXTINSELR(...) "TRCX_TRCEXTINSELR"


/**
 * DAB32b - trc#_trcidr0
 *
 * Returns the trace capability of the trace unit.
 *
 */
typedef union bdk_trcx_trcidr0 {
	uint32_t u;
	struct bdk_trcx_trcidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t commopt                     : 1;  /**< R/W - Common mode field:
                                                                 0 = common mode 0.
                                                                 1 = common mode 1. */
		uint32_t tssize                      : 5;  /**< R/W - Global timestamp size field. The permitted values are:
                                                                 0x0 = Global timestamping is not implemented.
                                                                 0x6 = Implementation supports a maximum Global timestamp of 48 bits.
                                                                 0x8 = Implementation supports a maximum Global timestamp of 64 bits.
                                                                 _ all other values are reserved. */
		uint32_t reserved_18_23              : 6;
		uint32_t trcexdata                   : 1;  /**< R/W - Indicate support for tracing of data transfer for exceptions and exception returns.
                                                                 0 = Implemented.
                                                                 1 = Not Implemented. */
		uint32_t qsupp                       : 2;  /**< R/W - Q Elements support field. The permitted values:
                                                                 0x0 = Q Elements support is not implemented.
                                                                 0x1 = Q Elements support is implemented and only support Q Elements
                                                                            with instruction count.
                                                                 0x2 = Q Elements support is implemented and only support Q Elements
                                                                            without instruction count.
                                                                 0x3 = Q Elements support is implemented and support Q Elements
                                                                            with and without instruction count. */
		uint32_t qfilt                       : 1;  /**< R/W - When QSUPP > 0x0, this is Q element filtering support field.
                                                                 0 = Q element filtering is not implemented.
                                                                 1 = Q element filtering is implemented. */
		uint32_t condtype                    : 2;  /**< R/W - Conditional tracing field.  The permitted values are:
                                                                 0x0 = The trace unit indicates only if the conditional instruction
                                                                       pass or fail its condition code check.
                                                                 0x1 = The trace unit provides the value of APSR condition flags, for
                                                                       a conditional instruction.
                                                                 all other values are reserved. */
		uint32_t numevent                    : 2;  /**< R/W - Number of event field. Indicates how many event a trace unit support.
                                                                 0x0 = The trace unit supports 1 event.
                                                                 0x1 = The trace unit supports 2 events.
                                                                 0x2 = The trace unit supports 3 events.
                                                                 0x3 = The trace unit supports 4 events. */
		uint32_t retstack                    : 1;  /**< R/W - Return stack bit.
                                                                 0 = The return stack is not implemented.
                                                                 1 = The return stack is implemented. */
		uint32_t reserved_8_8                : 1;
		uint32_t trccci                      : 1;  /**< R/W - Cycle count instruction bit.
                                                                 0 = Cycle count in instruction trace is not implemented.
                                                                 1 = Cycle count in instruction trace is implemented. */
		uint32_t trccond                     : 1;  /**< R/W - Conditional instruction tracing support bit.
                                                                 0 = Conditional instruction tracing is not supported.
                                                                 1 = Conditional instruction tracing is supported. */
		uint32_t trcbb                       : 1;  /**< R/W - Branch broadcast tracing support bit.
                                                                 0 = Branch broadcast tracing is not supported.
                                                                 1 = Branch broadcast tracing is supported. */
		uint32_t trcdata                     : 2;  /**< R/W - Conditional tracing field. The permitted values are:
                                                                 0x0 = Data tracing is not supported.
                                                                 0x3 = Data tracing is supported. */
		uint32_t intp0                       : 2;  /**< R/W - P0 traing support field. The permitted values are:
                                                                 0x0 = Tracing of load and store instruction as P0 element is not supported.
                                                                 0x3 = Tracing of load and store instruction as P0 element is supported. */
		uint32_t bit0                        : 1;
#else
		uint32_t bit0                        : 1;
		uint32_t intp0                       : 2;
		uint32_t trcdata                     : 2;
		uint32_t trcbb                       : 1;
		uint32_t trccond                     : 1;
		uint32_t trccci                      : 1;
		uint32_t reserved_8_8                : 1;
		uint32_t retstack                    : 1;
		uint32_t numevent                    : 2;
		uint32_t condtype                    : 2;
		uint32_t qfilt                       : 1;
		uint32_t qsupp                       : 2;
		uint32_t trcexdata                   : 1;
		uint32_t reserved_18_23              : 6;
		uint32_t tssize                      : 5;
		uint32_t commopt                     : 1;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_trcx_trcidr0_s          cn85xx; */
	/* struct bdk_trcx_trcidr0_s          cn88xx; */
} bdk_trcx_trcidr0_t;

static inline uint64_t BDK_TRCX_TRCIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCIDR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC301E0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCIDR0(...) bdk_trcx_trcidr0_t
#define bustype_BDK_TRCX_TRCIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCIDR0(p1) (p1)
#define arguments_BDK_TRCX_TRCIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCIDR0(...) "TRCX_TRCIDR0"


/**
 * DAB32b - trc#_trcidr1
 *
 * Returns the basic architecture of the trace unit.
 *
 */
typedef union bdk_trcx_trcidr1 {
	uint32_t u;
	struct bdk_trcx_trcidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t designer                    : 8;
		uint32_t reserved_16_23              : 8;
		uint32_t val1                        : 4;
		uint32_t archmaj                     : 4;
		uint32_t archmin                     : 4;
		uint32_t revision                    : 4;
#else
		uint32_t revision                    : 4;
		uint32_t archmin                     : 4;
		uint32_t archmaj                     : 4;
		uint32_t val1                        : 4;
		uint32_t reserved_16_23              : 8;
		uint32_t designer                    : 8;
#endif
	} s;
	/* struct bdk_trcx_trcidr1_s          cn85xx; */
	/* struct bdk_trcx_trcidr1_s          cn88xx; */
} bdk_trcx_trcidr1_t;

static inline uint64_t BDK_TRCX_TRCIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCIDR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC301E4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCIDR1(...) bdk_trcx_trcidr1_t
#define bustype_BDK_TRCX_TRCIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCIDR1(p1) (p1)
#define arguments_BDK_TRCX_TRCIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCIDR1(...) "TRCX_TRCIDR1"


/**
 * DAB32b - trc#_trcidr2
 *
 * return the maximum size of data address and data value.
 *
 */
typedef union bdk_trcx_trcidr2 {
	uint32_t u;
	struct bdk_trcx_trcidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_29_31              : 3;
		uint32_t ccsize                      : 4;
		uint32_t dvsize                      : 5;
		uint32_t dasize                      : 5;
		uint32_t vmidsize                    : 5;
		uint32_t cidsize                     : 5;
		uint32_t iasize                      : 5;
#else
		uint32_t iasize                      : 5;
		uint32_t cidsize                     : 5;
		uint32_t vmidsize                    : 5;
		uint32_t dasize                      : 5;
		uint32_t dvsize                      : 5;
		uint32_t ccsize                      : 4;
		uint32_t reserved_29_31              : 3;
#endif
	} s;
	/* struct bdk_trcx_trcidr2_s          cn85xx; */
	/* struct bdk_trcx_trcidr2_s          cn88xx; */
} bdk_trcx_trcidr2_t;

static inline uint64_t BDK_TRCX_TRCIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCIDR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC301E8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCIDR2(...) bdk_trcx_trcidr2_t
#define bustype_BDK_TRCX_TRCIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCIDR2(p1) (p1)
#define arguments_BDK_TRCX_TRCIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCIDR2(...) "TRCX_TRCIDR2"


/**
 * DAB32b - trc#_trcidr3
 *
 * return charactristics of the trace unit.
 *
 */
typedef union bdk_trcx_trcidr3 {
	uint32_t u;
	struct bdk_trcx_trcidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t noovflw                     : 1;
		uint32_t numproc                     : 3;
		uint32_t sysstall                    : 1;
		uint32_t stallctl                    : 1;
		uint32_t syncpr                      : 1;
		uint32_t trcerr                      : 1;
		uint32_t elns                        : 4;
		uint32_t els                         : 4;
		uint32_t reserved_12_15              : 4;
		uint32_t ccitmin                     : 12;
#else
		uint32_t ccitmin                     : 12;
		uint32_t reserved_12_15              : 4;
		uint32_t els                         : 4;
		uint32_t elns                        : 4;
		uint32_t trcerr                      : 1;
		uint32_t syncpr                      : 1;
		uint32_t stallctl                    : 1;
		uint32_t sysstall                    : 1;
		uint32_t numproc                     : 3;
		uint32_t noovflw                     : 1;
#endif
	} s;
	/* struct bdk_trcx_trcidr3_s          cn85xx; */
	/* struct bdk_trcx_trcidr3_s          cn88xx; */
} bdk_trcx_trcidr3_t;

static inline uint64_t BDK_TRCX_TRCIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCIDR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC301ECull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCIDR3(...) bdk_trcx_trcidr3_t
#define bustype_BDK_TRCX_TRCIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCIDR3(p1) (p1)
#define arguments_BDK_TRCX_TRCIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCIDR3(...) "TRCX_TRCIDR3"


/**
 * DAB32b - trc#_trcidr4
 *
 * return how many resources the trace unit supports.
 *
 */
typedef union bdk_trcx_trcidr4 {
	uint32_t u;
	struct bdk_trcx_trcidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t numvmidc                    : 4;
		uint32_t numcidc                     : 4;
		uint32_t numsscc                     : 4;
		uint32_t numrspair                   : 4;
		uint32_t numpc                       : 4;
		uint32_t reserved_9_11               : 3;
		uint32_t suppdac                     : 1;
		uint32_t numdvc                      : 4;
		uint32_t numacpairs                  : 4;
#else
		uint32_t numacpairs                  : 4;
		uint32_t numdvc                      : 4;
		uint32_t suppdac                     : 1;
		uint32_t reserved_9_11               : 3;
		uint32_t numpc                       : 4;
		uint32_t numrspair                   : 4;
		uint32_t numsscc                     : 4;
		uint32_t numcidc                     : 4;
		uint32_t numvmidc                    : 4;
#endif
	} s;
	/* struct bdk_trcx_trcidr4_s          cn85xx; */
	/* struct bdk_trcx_trcidr4_s          cn88xx; */
} bdk_trcx_trcidr4_t;

static inline uint64_t BDK_TRCX_TRCIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCIDR4(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC301F0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCIDR4(...) bdk_trcx_trcidr4_t
#define bustype_BDK_TRCX_TRCIDR4(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCIDR4(p1) (p1)
#define arguments_BDK_TRCX_TRCIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCIDR4(...) "TRCX_TRCIDR4"


/**
 * DAB32b - trc#_trcidr5
 *
 * return how many resources the trace unit supports.
 *
 */
typedef union bdk_trcx_trcidr5 {
	uint32_t u;
	struct bdk_trcx_trcidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t redfuncntr                  : 1;
		uint32_t numcntr                     : 3;
		uint32_t numseqstate                 : 3;
		uint32_t reserved_24_24              : 1;
		uint32_t lpoverride                  : 1;
		uint32_t atbtrig                     : 1;
		uint32_t traceidsize                 : 6;
		uint32_t reserved_12_15              : 4;
		uint32_t numextinsel                 : 3;
		uint32_t numextin                    : 9;
#else
		uint32_t numextin                    : 9;
		uint32_t numextinsel                 : 3;
		uint32_t reserved_12_15              : 4;
		uint32_t traceidsize                 : 6;
		uint32_t atbtrig                     : 1;
		uint32_t lpoverride                  : 1;
		uint32_t reserved_24_24              : 1;
		uint32_t numseqstate                 : 3;
		uint32_t numcntr                     : 3;
		uint32_t redfuncntr                  : 1;
#endif
	} s;
	/* struct bdk_trcx_trcidr5_s          cn85xx; */
	/* struct bdk_trcx_trcidr5_s          cn88xx; */
} bdk_trcx_trcidr5_t;

static inline uint64_t BDK_TRCX_TRCIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCIDR5(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC301F4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCIDR5(...) bdk_trcx_trcidr5_t
#define bustype_BDK_TRCX_TRCIDR5(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCIDR5(p1) (p1)
#define arguments_BDK_TRCX_TRCIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCIDR5(...) "TRCX_TRCIDR5"


/**
 * DAB32b - trc#_trcitctrl
 *
 * Enables the TRC to switch from its default mode into
 * integration mode, where test software can control directly the
 * inputs and outputs of the processor, for integration testing
 * or topology detection.
 */
typedef union bdk_trcx_trcitctrl {
	uint32_t u;
	struct bdk_trcx_trcitctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t ime                         : 1;  /**< RO - Integration mode enable. When IME == 1, the device reverts to
                                                                     an integration mode to enable integration testing or topology
                                                                     detection. The integration mode behavior is implementation
                                                                     defined.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled. */
#else
		uint32_t ime                         : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_trcx_trcitctrl_s        cn85xx; */
	/* struct bdk_trcx_trcitctrl_s        cn88xx; */
} bdk_trcx_trcitctrl_t;

static inline uint64_t BDK_TRCX_TRCITCTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCITCTRL(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30F00ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCITCTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCITCTRL(...) bdk_trcx_trcitctrl_t
#define bustype_BDK_TRCX_TRCITCTRL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCITCTRL(p1) (p1)
#define arguments_BDK_TRCX_TRCITCTRL(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCITCTRL(...) "TRCX_TRCITCTRL"


/**
 * DAB32b - trc#_trclar
 *
 * Allows or disallows access to the TRC registers through a
 * memory-mapped interface.
 */
typedef union bdk_trcx_trclar {
	uint32_t u;
	struct bdk_trcx_trclar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t key                         : 32; /**< WO - Lock access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface. */
#else
		uint32_t key                         : 32;
#endif
	} s;
	/* struct bdk_trcx_trclar_s           cn85xx; */
	/* struct bdk_trcx_trclar_s           cn88xx; */
} bdk_trcx_trclar_t;

static inline uint64_t BDK_TRCX_TRCLAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCLAR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FB0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCLAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCLAR(...) bdk_trcx_trclar_t
#define bustype_BDK_TRCX_TRCLAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCLAR(p1) (p1)
#define arguments_BDK_TRCX_TRCLAR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCLAR(...) "TRCX_TRCLAR"


/**
 * DAB32b - trc#_trclsr
 *
 * Indicates the current status of the software lock for TRC
 * registers.
 */
typedef union bdk_trcx_trclsr {
	uint32_t u;
	struct bdk_trcx_trclsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ntt                         : 1;  /**< RO - Not thirty-two bit access required. RAZ. */
		uint32_t slk                         : 1;  /**< RO/H - Software lock status for this component. For an access to LSR
                                                                     that is not a memory-mapped access, or when the software lock
                                                                     is not implemented, this field is RAZ.
                                                                 For memory-mapped accesses when the software lock is
                                                                     implemented, possible values of this field are:
                                                                 0 = Lock clear. Writes are permitted to this component's
                                                                     registers.
                                                                 1 = Lock set. Writes to this component's registers are ignored,
                                                                     and reads have no side effects. */
		uint32_t sli                         : 1;  /**< RO - Software lock implemented. For an access to LSR that is not a
                                                                     memory-mapped access, this field is RAZ. For memory-mapped
                                                                     accesses, the value of this field is implementation defined.
                                                                     Permitted values are:
                                                                 0 = Software lock not implemented or not memory-mapped access.
                                                                 1 = Software lock implemented and memory-mapped access. */
#else
		uint32_t sli                         : 1;
		uint32_t slk                         : 1;
		uint32_t ntt                         : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_trcx_trclsr_s           cn85xx; */
	/* struct bdk_trcx_trclsr_s           cn88xx; */
} bdk_trcx_trclsr_t;

static inline uint64_t BDK_TRCX_TRCLSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCLSR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FB4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCLSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCLSR(...) bdk_trcx_trclsr_t
#define bustype_BDK_TRCX_TRCLSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCLSR(p1) (p1)
#define arguments_BDK_TRCX_TRCLSR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCLSR(...) "TRCX_TRCLSR"


/**
 * DAB32b - trc#_trcoslar
 *
 * Clears bits of the Application Trigger register.
 *
 */
typedef union bdk_trcx_trcoslar {
	uint32_t u;
	struct bdk_trcx_trcoslar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcoslar_s         cn85xx; */
	/* struct bdk_trcx_trcoslar_s         cn88xx; */
} bdk_trcx_trcoslar_t;

static inline uint64_t BDK_TRCX_TRCOSLAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCOSLAR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30300ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCOSLAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCOSLAR(...) bdk_trcx_trcoslar_t
#define bustype_BDK_TRCX_TRCOSLAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCOSLAR(p1) (p1)
#define arguments_BDK_TRCX_TRCOSLAR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCOSLAR(...) "TRCX_TRCOSLAR"


/**
 * DAB32b - trc#_trcoslsr
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcoslsr {
	uint32_t u;
	struct bdk_trcx_trcoslsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t apppulse                    : 3;  /**< RO - Generate event pulse on ECT channel <x>.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     TRCDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 Writing to this bit has the following effect:
                                                                 0 = No effect.
                                                                 1 = Channel <x> event pulse generated for one clock period. */
#else
		uint32_t apppulse                    : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_trcx_trcoslsr_s         cn85xx; */
	/* struct bdk_trcx_trcoslsr_s         cn88xx; */
} bdk_trcx_trcoslsr_t;

static inline uint64_t BDK_TRCX_TRCOSLSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCOSLSR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30304ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCOSLSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCOSLSR(...) bdk_trcx_trcoslsr_t
#define bustype_BDK_TRCX_TRCOSLSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCOSLSR(p1) (p1)
#define arguments_BDK_TRCX_TRCOSLSR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCOSLSR(...) "TRCX_TRCOSLSR"


/**
 * DAB32b - trc#_trcpdcr
 *
 * Enables the signaling of an event on output channels when
 * input trigger event n is received by the TRC.
 */
typedef union bdk_trcx_trcpdcr {
	uint32_t u;
	struct bdk_trcx_trcpdcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t inen                        : 3;  /**< R/W - Input trigger <n> to output channel <x> enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     TRCDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = Input trigger <n> will not generate an event on output channel
                                                                     <x>.
                                                                 1 = Input trigger <n> will generate an event on output channel
                                                                     <x>.

                                                                 In CNXXXX TRCINEN(3..31) are ignored as there are only 3 channels. */
#else
		uint32_t inen                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_trcx_trcpdcr_s          cn85xx; */
	/* struct bdk_trcx_trcpdcr_s          cn88xx; */
} bdk_trcx_trcpdcr_t;

static inline uint64_t BDK_TRCX_TRCPDCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPDCR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30310ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPDCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPDCR(...) bdk_trcx_trcpdcr_t
#define bustype_BDK_TRCX_TRCPDCR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPDCR(p1) (p1)
#define arguments_BDK_TRCX_TRCPDCR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPDCR(...) "TRCX_TRCPDCR"


/**
 * DAB32b - trc#_trcpdsr
 *
 * Defines which input channels generate output trigger n.
 *
 */
typedef union bdk_trcx_trcpdsr {
	uint32_t u;
	struct bdk_trcx_trcpdsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t outen                       : 3;  /**< R/W - Input channel <x> to output trigger <n> enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     TRCDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = An event on input channel <x> will not cause output trigger
                                                                     <n> to be asserted.
                                                                 1 = An event on input channel <x> will cause output trigger <n> to
                                                                     be asserted.

                                                                 In CNXXXX TRCOUTEN(3..31) are ignored as there are only 3 channels. */
#else
		uint32_t outen                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_trcx_trcpdsr_s          cn85xx; */
	/* struct bdk_trcx_trcpdsr_s          cn88xx; */
} bdk_trcx_trcpdsr_t;

static inline uint64_t BDK_TRCX_TRCPDSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPDSR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30314ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPDSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPDSR(...) bdk_trcx_trcpdsr_t
#define bustype_BDK_TRCX_TRCPDSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPDSR(p1) (p1)
#define arguments_BDK_TRCX_TRCPDSR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPDSR(...) "TRCX_TRCPDSR"


/**
 * DAB32b - trc#_trcpidr0
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trcpidr0 {
	uint32_t u;
	struct bdk_trcx_trcpidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t part_0                      : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::TRC. */
#else
		uint32_t part_0                      : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcpidr0_s         cn85xx; */
	/* struct bdk_trcx_trcpidr0_s         cn88xx; */
} bdk_trcx_trcpidr0_t;

static inline uint64_t BDK_TRCX_TRCPIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FE0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR0(...) bdk_trcx_trcpidr0_t
#define bustype_BDK_TRCX_TRCPIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR0(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR0(...) "TRCX_TRCPIDR0"


/**
 * DAB32b - trc#_trcpidr1
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trcpidr1 {
	uint32_t u;
	struct bdk_trcx_trcpidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t des_0                       : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t part_1                      : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t part_1                      : 4;
		uint32_t des_0                       : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcpidr1_s         cn85xx; */
	/* struct bdk_trcx_trcpidr1_s         cn88xx; */
} bdk_trcx_trcpidr1_t;

static inline uint64_t BDK_TRCX_TRCPIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FE4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR1(...) bdk_trcx_trcpidr1_t
#define bustype_BDK_TRCX_TRCPIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR1(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR1(...) "TRCX_TRCPIDR1"


/**
 * DAB32b - trc#_trcpidr2
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trcpidr2 {
	uint32_t u;
	struct bdk_trcx_trcpidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t des_1                       : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t des_1                       : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcpidr2_s         cn85xx; */
	/* struct bdk_trcx_trcpidr2_s         cn88xx; */
} bdk_trcx_trcpidr2_t;

static inline uint64_t BDK_TRCX_TRCPIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FE8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR2(...) bdk_trcx_trcpidr2_t
#define bustype_BDK_TRCX_TRCPIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR2(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR2(...) "TRCX_TRCPIDR2"


/**
 * DAB32b - trc#_trcpidr3
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trcpidr3 {
	uint32_t u;
	struct bdk_trcx_trcpidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cmod                        : 4;  /**< RO - Customer modified. Indicates someone other than the Designer
                                                                 has modified the component. */
#else
		uint32_t cmod                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcpidr3_s         cn85xx; */
	/* struct bdk_trcx_trcpidr3_s         cn88xx; */
} bdk_trcx_trcpidr3_t;

static inline uint64_t BDK_TRCX_TRCPIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FECull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR3(...) bdk_trcx_trcpidr3_t
#define bustype_BDK_TRCX_TRCPIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR3(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR3(...) "TRCX_TRCPIDR3"


/**
 * DAB32b - trc#_trcpidr4
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_trcx_trcpidr4 {
	uint32_t u;
	struct bdk_trcx_trcpidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t size                        : 4;  /**< RO - Size of the component. RAZ. Log<sub>2</sub> of the number of 4KB pages from the
                                                                 start of the component to the end of the component ID registers. */
		uint32_t des_2                       : 4;  /**< RO - JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else
		uint32_t des_2                       : 4;
		uint32_t size                        : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcpidr4_s         cn85xx; */
	/* struct bdk_trcx_trcpidr4_s         cn88xx; */
} bdk_trcx_trcpidr4_t;

static inline uint64_t BDK_TRCX_TRCPIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR4(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FD0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR4(...) bdk_trcx_trcpidr4_t
#define bustype_BDK_TRCX_TRCPIDR4(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR4(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR4(...) "TRCX_TRCPIDR4"


/**
 * DAB32b - trc#_trcpidr5
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_trcx_trcpidr5 {
	uint32_t u;
	struct bdk_trcx_trcpidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcpidr5_s         cn85xx; */
	/* struct bdk_trcx_trcpidr5_s         cn88xx; */
} bdk_trcx_trcpidr5_t;

static inline uint64_t BDK_TRCX_TRCPIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR5(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FD4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR5(...) bdk_trcx_trcpidr5_t
#define bustype_BDK_TRCX_TRCPIDR5(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR5(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR5(...) "TRCX_TRCPIDR5"


/**
 * DAB32b - trc#_trcpidr6
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_trcx_trcpidr6 {
	uint32_t u;
	struct bdk_trcx_trcpidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcpidr6_s         cn85xx; */
	/* struct bdk_trcx_trcpidr6_s         cn88xx; */
} bdk_trcx_trcpidr6_t;

static inline uint64_t BDK_TRCX_TRCPIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR6(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FD8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR6(...) bdk_trcx_trcpidr6_t
#define bustype_BDK_TRCX_TRCPIDR6(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR6(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR6(...) "TRCX_TRCPIDR6"


/**
 * DAB32b - trc#_trcpidr7
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_trcx_trcpidr7 {
	uint32_t u;
	struct bdk_trcx_trcpidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcpidr7_s         cn85xx; */
	/* struct bdk_trcx_trcpidr7_s         cn88xx; */
} bdk_trcx_trcpidr7_t;

static inline uint64_t BDK_TRCX_TRCPIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPIDR7(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30FDCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPIDR7(...) bdk_trcx_trcpidr7_t
#define bustype_BDK_TRCX_TRCPIDR7(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPIDR7(p1) (p1)
#define arguments_BDK_TRCX_TRCPIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPIDR7(...) "TRCX_TRCPIDR7"


/**
 * DAB32b - trc#_trcprgctlr
 *
 * Controls whether the TRC is enabled.
 *
 */
typedef union bdk_trcx_trcprgctlr {
	uint32_t u;
	struct bdk_trcx_trcprgctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t en                          : 1;  /**< R/W - Enables or disables the Tace Unit:
                                                                 0 = Trace Unit is disabled.
                                                                     All tace resources are inactive and no Trace is generated.
                                                                 1 = Trace Unit is enabled. */
#else
		uint32_t en                          : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_trcx_trcprgctlr_s       cn85xx; */
	/* struct bdk_trcx_trcprgctlr_s       cn88xx; */
} bdk_trcx_trcprgctlr_t;

static inline uint64_t BDK_TRCX_TRCPRGCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPRGCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30004ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPRGCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPRGCTLR(...) bdk_trcx_trcprgctlr_t
#define bustype_BDK_TRCX_TRCPRGCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPRGCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCPRGCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPRGCTLR(...) "TRCX_TRCPRGCTLR"


/**
 * DAB32b - trc#_trcprocselr
 *
 * Programmed to select which PE to trace.
 *
 */
typedef union bdk_trcx_trcprocselr {
	uint32_t u;
	struct bdk_trcx_trcprocselr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_6_31               : 26;
		uint32_t procsel                     : 6;  /**< R/W - Only accepts writes when the trace unit is disabled. Before writing to this
                                                                 register, ensure that TRCSTATR.IDLE = 1 so that the trace unit can synchronize
                                                                 with the chosed PE. */
#else
		uint32_t procsel                     : 6;
		uint32_t reserved_6_31               : 26;
#endif
	} s;
	/* struct bdk_trcx_trcprocselr_s      cn85xx; */
	/* struct bdk_trcx_trcprocselr_s      cn88xx; */
} bdk_trcx_trcprocselr_t;

static inline uint64_t BDK_TRCX_TRCPROCSELR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCPROCSELR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30008ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCPROCSELR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCPROCSELR(...) bdk_trcx_trcprocselr_t
#define bustype_BDK_TRCX_TRCPROCSELR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCPROCSELR(p1) (p1)
#define arguments_BDK_TRCX_TRCPROCSELR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCPROCSELR(...) "TRCX_TRCPROCSELR"


/**
 * DAB32b - trc#_trcqctlr
 *
 * Controls when Q elements are enabled.
 *
 */
typedef union bdk_trcx_trcqctlr {
	uint32_t u;
	struct bdk_trcx_trcqctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t mode                        : 1;  /**< R/W - Select whether address range comparator is permitted to generate Q element.
                                                                 0 = Exclude mode. The address range comparator which is slected by Range
                                                                     is not permitted to generate Q element.
                                                                 1 = Include mode. The address range comparator which is slected by Range
                                                                     is permitted to generate Q element. */
		uint32_t range                       : 8;  /**< R/W - specify the address range comparator to be used for controlling Q elements.
                                                                 0 = address range comparator[n] is not selected.
                                                                 1 = address range comparator[n] is selected. */
#else
		uint32_t range                       : 8;
		uint32_t mode                        : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_trcx_trcqctlr_s         cn85xx; */
	/* struct bdk_trcx_trcqctlr_s         cn88xx; */
} bdk_trcx_trcqctlr_t;

static inline uint64_t BDK_TRCX_TRCQCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCQCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30044ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCQCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCQCTLR(...) bdk_trcx_trcqctlr_t
#define bustype_BDK_TRCX_TRCQCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCQCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCQCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCQCTLR(...) "TRCX_TRCQCTLR"


/**
 * DAB32b - trc#_trcrsctlr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr0 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr0_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr0_s       cn88xx; */
} bdk_trcx_trcrsctlr0_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30200ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR0(...) bdk_trcx_trcrsctlr0_t
#define bustype_BDK_TRCX_TRCRSCTLR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR0(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR0(...) "TRCX_TRCRSCTLR0"


/**
 * DAB32b - trc#_trcrsctlr1
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr1 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr1_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr1_s       cn88xx; */
} bdk_trcx_trcrsctlr1_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30204ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR1(...) bdk_trcx_trcrsctlr1_t
#define bustype_BDK_TRCX_TRCRSCTLR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR1(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR1(...) "TRCX_TRCRSCTLR1"


/**
 * DAB32b - trc#_trcrsctlr2
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr2 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr2_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr2_s       cn88xx; */
} bdk_trcx_trcrsctlr2_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30208ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR2(...) bdk_trcx_trcrsctlr2_t
#define bustype_BDK_TRCX_TRCRSCTLR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR2(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR2(...) "TRCX_TRCRSCTLR2"


/**
 * DAB32b - trc#_trcrsctlr3
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr3 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr3_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr3_s       cn88xx; */
} bdk_trcx_trcrsctlr3_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3020Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR3(...) bdk_trcx_trcrsctlr3_t
#define bustype_BDK_TRCX_TRCRSCTLR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR3(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR3(...) "TRCX_TRCRSCTLR3"


/**
 * DAB32b - trc#_trcrsctlr4
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr4 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr4_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr4_s       cn88xx; */
} bdk_trcx_trcrsctlr4_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR4(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30210ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR4(...) bdk_trcx_trcrsctlr4_t
#define bustype_BDK_TRCX_TRCRSCTLR4(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR4(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR4(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR4(...) "TRCX_TRCRSCTLR4"


/**
 * DAB32b - trc#_trcrsctlr5
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr5 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr5_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr5_s       cn88xx; */
} bdk_trcx_trcrsctlr5_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR5(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30214ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR5(...) bdk_trcx_trcrsctlr5_t
#define bustype_BDK_TRCX_TRCRSCTLR5(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR5(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR5(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR5(...) "TRCX_TRCRSCTLR5"


/**
 * DAB32b - trc#_trcrsctlr6
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr6 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr6_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr6_s       cn88xx; */
} bdk_trcx_trcrsctlr6_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR6(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30218ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR6(...) bdk_trcx_trcrsctlr6_t
#define bustype_BDK_TRCX_TRCRSCTLR6(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR6(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR6(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR6(...) "TRCX_TRCRSCTLR6"


/**
 * DAB32b - trc#_trcrsctlr7
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcrsctlr7 {
	uint32_t u;
	struct bdk_trcx_trcrsctlr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcrsctlr7_s       cn85xx; */
	/* struct bdk_trcx_trcrsctlr7_s       cn88xx; */
} bdk_trcx_trcrsctlr7_t;

static inline uint64_t BDK_TRCX_TRCRSCTLR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCRSCTLR7(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3021Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCRSCTLR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCRSCTLR7(...) bdk_trcx_trcrsctlr7_t
#define bustype_BDK_TRCX_TRCRSCTLR7(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCRSCTLR7(p1) (p1)
#define arguments_BDK_TRCX_TRCRSCTLR7(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCRSCTLR7(...) "TRCX_TRCRSCTLR7"


/**
 * DAB32b - trc#_trcseqevr0
 *
 * move Sequencer State forwards or backwards.
 *
 */
typedef union bdk_trcx_trcseqevr0 {
	uint32_t u;
	struct bdk_trcx_trcseqevr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t bak                         : 8;  /**< R/W - Backwards field: an event selector */
		uint32_t f                           : 8;  /**< R/W - Forwards field: an event selector */
#else
		uint32_t f                           : 8;
		uint32_t bak                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trcseqevr0_s       cn85xx; */
	/* struct bdk_trcx_trcseqevr0_s       cn88xx; */
} bdk_trcx_trcseqevr0_t;

static inline uint64_t BDK_TRCX_TRCSEQEVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSEQEVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30100ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSEQEVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSEQEVR0(...) bdk_trcx_trcseqevr0_t
#define bustype_BDK_TRCX_TRCSEQEVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSEQEVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCSEQEVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSEQEVR0(...) "TRCX_TRCSEQEVR0"


/**
 * DAB32b - trc#_trcseqevr1
 *
 * move Sequencer State forwards or backwards.
 *
 */
typedef union bdk_trcx_trcseqevr1 {
	uint32_t u;
	struct bdk_trcx_trcseqevr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t bak                         : 8;  /**< R/W - Backwards field: an event selector */
		uint32_t f                           : 8;  /**< R/W - Forwards field: an event selector */
#else
		uint32_t f                           : 8;
		uint32_t bak                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trcseqevr1_s       cn85xx; */
	/* struct bdk_trcx_trcseqevr1_s       cn88xx; */
} bdk_trcx_trcseqevr1_t;

static inline uint64_t BDK_TRCX_TRCSEQEVR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSEQEVR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30104ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSEQEVR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSEQEVR1(...) bdk_trcx_trcseqevr1_t
#define bustype_BDK_TRCX_TRCSEQEVR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSEQEVR1(p1) (p1)
#define arguments_BDK_TRCX_TRCSEQEVR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSEQEVR1(...) "TRCX_TRCSEQEVR1"


/**
 * DAB32b - trc#_trcseqevr2
 *
 * move Sequencer State forwards or backwards.
 *
 */
typedef union bdk_trcx_trcseqevr2 {
	uint32_t u;
	struct bdk_trcx_trcseqevr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t bak                         : 8;  /**< R/W - Backwards field: an event selector */
		uint32_t f                           : 8;  /**< R/W - Forwards field: an event selector */
#else
		uint32_t f                           : 8;
		uint32_t bak                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trcseqevr2_s       cn85xx; */
	/* struct bdk_trcx_trcseqevr2_s       cn88xx; */
} bdk_trcx_trcseqevr2_t;

static inline uint64_t BDK_TRCX_TRCSEQEVR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSEQEVR2(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30108ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSEQEVR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSEQEVR2(...) bdk_trcx_trcseqevr2_t
#define bustype_BDK_TRCX_TRCSEQEVR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSEQEVR2(p1) (p1)
#define arguments_BDK_TRCX_TRCSEQEVR2(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSEQEVR2(...) "TRCX_TRCSEQEVR2"


/**
 * DAB32b - trc#_trcseqevr3
 *
 * move Sequencer State forwards or backwards.
 *
 */
typedef union bdk_trcx_trcseqevr3 {
	uint32_t u;
	struct bdk_trcx_trcseqevr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t bak                         : 8;  /**< R/W - Backwards field: an event selector */
		uint32_t f                           : 8;  /**< R/W - Forwards field: an event selector */
#else
		uint32_t f                           : 8;
		uint32_t bak                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_trcx_trcseqevr3_s       cn85xx; */
	/* struct bdk_trcx_trcseqevr3_s       cn88xx; */
} bdk_trcx_trcseqevr3_t;

static inline uint64_t BDK_TRCX_TRCSEQEVR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSEQEVR3(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3010Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSEQEVR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSEQEVR3(...) bdk_trcx_trcseqevr3_t
#define bustype_BDK_TRCX_TRCSEQEVR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSEQEVR3(p1) (p1)
#define arguments_BDK_TRCX_TRCSEQEVR3(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSEQEVR3(...) "TRCX_TRCSEQEVR3"


/**
 * DAB32b - trc#_trcseqrstevr
 *
 * move the sequencer to state 0 when a programmed event occurs.
 *
 */
typedef union bdk_trcx_trcseqrstevr {
	uint32_t u;
	struct bdk_trcx_trcseqrstevr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t rst                         : 8;  /**< R/W - An event selector: when event occus, move sequencer state to state 0. */
#else
		uint32_t rst                         : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_trcx_trcseqrstevr_s     cn85xx; */
	/* struct bdk_trcx_trcseqrstevr_s     cn88xx; */
} bdk_trcx_trcseqrstevr_t;

static inline uint64_t BDK_TRCX_TRCSEQRSTEVR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSEQRSTEVR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30118ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSEQRSTEVR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSEQRSTEVR(...) bdk_trcx_trcseqrstevr_t
#define bustype_BDK_TRCX_TRCSEQRSTEVR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSEQRSTEVR(p1) (p1)
#define arguments_BDK_TRCX_TRCSEQRSTEVR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSEQRSTEVR(...) "TRCX_TRCSEQRSTEVR"


/**
 * DAB32b - trc#_trcseqstr
 *
 * set or read the sequencer state.
 *
 */
typedef union bdk_trcx_trcseqstr {
	uint32_t u;
	struct bdk_trcx_trcseqstr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t state                       : 2;  /**< R/W - Set or return the state of sequencer.
                                                                 0x0 = state0.
                                                                 0x1 = state1.
                                                                 0x2 = state2.
                                                                 0x3 = state3. */
#else
		uint32_t state                       : 2;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_trcx_trcseqstr_s        cn85xx; */
	/* struct bdk_trcx_trcseqstr_s        cn88xx; */
} bdk_trcx_trcseqstr_t;

static inline uint64_t BDK_TRCX_TRCSEQSTR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSEQSTR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3011Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSEQSTR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSEQSTR(...) bdk_trcx_trcseqstr_t
#define bustype_BDK_TRCX_TRCSEQSTR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSEQSTR(p1) (p1)
#define arguments_BDK_TRCX_TRCSEQSTR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSEQSTR(...) "TRCX_TRCSEQSTR"


/**
 * DAB32b - trc#_trcssccr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcssccr0 {
	uint32_t u;
	struct bdk_trcx_trcssccr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcssccr0_s        cn85xx; */
	/* struct bdk_trcx_trcssccr0_s        cn88xx; */
} bdk_trcx_trcssccr0_t;

static inline uint64_t BDK_TRCX_TRCSSCCR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSSCCR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30280ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSSCCR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSSCCR0(...) bdk_trcx_trcssccr0_t
#define bustype_BDK_TRCX_TRCSSCCR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSSCCR0(p1) (p1)
#define arguments_BDK_TRCX_TRCSSCCR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSSCCR0(...) "TRCX_TRCSSCCR0"


/**
 * DAB32b - trc#_trcsscsr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcsscsr0 {
	uint32_t u;
	struct bdk_trcx_trcsscsr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcsscsr0_s        cn85xx; */
	/* struct bdk_trcx_trcsscsr0_s        cn88xx; */
} bdk_trcx_trcsscsr0_t;

static inline uint64_t BDK_TRCX_TRCSSCSR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSSCSR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC302A0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSSCSR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSSCSR0(...) bdk_trcx_trcsscsr0_t
#define bustype_BDK_TRCX_TRCSSCSR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSSCSR0(p1) (p1)
#define arguments_BDK_TRCX_TRCSSCSR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSSCSR0(...) "TRCX_TRCSSCSR0"


/**
 * DAB32b - trc#_trcsspcicr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcsspcicr0 {
	uint32_t u;
	struct bdk_trcx_trcsspcicr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcsspcicr0_s      cn85xx; */
	/* struct bdk_trcx_trcsspcicr0_s      cn88xx; */
} bdk_trcx_trcsspcicr0_t;

static inline uint64_t BDK_TRCX_TRCSSPCICR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSSPCICR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC302C0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSSPCICR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSSPCICR0(...) bdk_trcx_trcsspcicr0_t
#define bustype_BDK_TRCX_TRCSSPCICR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSSPCICR0(p1) (p1)
#define arguments_BDK_TRCX_TRCSSPCICR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSSPCICR0(...) "TRCX_TRCSSPCICR0"


/**
 * DAB32b - trc#_trcstallctlr
 *
 * Enable trace unit functionality that prevents trace unit buffer overflow.
 *
 */
typedef union bdk_trcx_trcstallctlr {
	uint32_t u;
	struct bdk_trcx_trcstallctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_14_31              : 18;
		uint32_t nooverflow                  : 1;  /**< R/W - Trace overflow prevention bit.
                                                                 0 = Trace overflow prevention is disabled.
                                                                 1 = Trace overflow prevention is enabled. This might
                                                                      cause significant performance impact. */
		uint32_t datadiscard                 : 2;  /**< R/W - Data discard field. Control if a trace unit can discard data trace elements when
                                                                 data trace buffer space is less than LEVEL:
                                                                 0x0 = The trace unit must not discard any data trace elements.
                                                                 0x1 = The trace unit can discard P1 and P2 elements associated with data loads.
                                                                 0x2 = The trace unit can discard P1 and P2 elements associated with data stores.
                                                                 0x3 = The trace unit can discard P1 and P2 elements associated with
                                                                       data loads and stores. */
		uint32_t instpriority                : 1;  /**< R/W - Prioritize instruction trace bit. Control if a trace unit can prioritize the
                                                                 instruction trace when the instruction trace buffer space is less than LEVEL:
                                                                 0 = The trace unit must not prioritize the instruction trace.
                                                                 1 = The trace unit can prioritize the instruction trace. */
		uint32_t dstall                      : 1;  /**< R/W - Data stall bit. Control if a trace unit can stall the PE
                                                                 when the data trace buffer space is less than LEVEL:
                                                                 0 = The trace unit must not stall the PE.
                                                                 1 = The trace unit can stall the PE. */
		uint32_t istall                      : 1;  /**< R/W - Instruction stall bit. Control if a trace unit can stall the PE
                                                                 when the instruction trace buffer space is less than LEVEL:
                                                                 0 = The trace unit must not stall the PE.
                                                                 1 = The trace unit can stall the PE. */
		uint32_t reserved_4_7                : 4;
		uint32_t level                       : 4;  /**< R/W - Threshold level field. The field can support 16 monotonic lvel from 0x0 to 0xF.
                                                                 where
                                                                 0x0 = Zero invasion. The setting has greater risk of FIFO overflow.
                                                                 0xF = Maximum invasion. But the FIFO has less risk of overflow. */
#else
		uint32_t level                       : 4;
		uint32_t reserved_4_7                : 4;
		uint32_t istall                      : 1;
		uint32_t dstall                      : 1;
		uint32_t instpriority                : 1;
		uint32_t datadiscard                 : 2;
		uint32_t nooverflow                  : 1;
		uint32_t reserved_14_31              : 18;
#endif
	} s;
	/* struct bdk_trcx_trcstallctlr_s     cn85xx; */
	/* struct bdk_trcx_trcstallctlr_s     cn88xx; */
} bdk_trcx_trcstallctlr_t;

static inline uint64_t BDK_TRCX_TRCSTALLCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSTALLCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3002Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSTALLCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSTALLCTLR(...) bdk_trcx_trcstallctlr_t
#define bustype_BDK_TRCX_TRCSTALLCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSTALLCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCSTALLCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSTALLCTLR(...) "TRCX_TRCSTALLCTLR"


/**
 * DAB32b - trc#_trcstatr
 *
 * trace unit status
 *
 */
typedef union bdk_trcx_trcstatr {
	uint32_t u;
	struct bdk_trcx_trcstatr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t pmstable                    : 1;  /**< RO - This bit is valid only when either TRCPRGCTRL.EN = 0 or the OS Lock is locked.
                                                                 0 = Programmer's model is not stable.
                                                                 1 = Programmer's model is stable. */
		uint32_t idle                        : 1;  /**< RO - Idle status bit.
                                                                 0 = The trace unit is not idle.
                                                                 1 = The trace unit is idle. */
#else
		uint32_t idle                        : 1;
		uint32_t pmstable                    : 1;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_trcx_trcstatr_s         cn85xx; */
	/* struct bdk_trcx_trcstatr_s         cn88xx; */
} bdk_trcx_trcstatr_t;

static inline uint64_t BDK_TRCX_TRCSTATR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSTATR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3000Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSTATR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSTATR(...) bdk_trcx_trcstatr_t
#define bustype_BDK_TRCX_TRCSTATR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSTATR(p1) (p1)
#define arguments_BDK_TRCX_TRCSTATR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSTATR(...) "TRCX_TRCSTATR"


/**
 * DAB32b - trc#_trcsyncpr
 *
 * Controls how often trace synchronization request occurs.
 *
 */
typedef union bdk_trcx_trcsyncpr {
	uint32_t u;
	struct bdk_trcx_trcsyncpr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t period                      : 5;  /**< R/W - Control how many bytes of trace that a trace unit can generate
                                                                 before the trace synchronization request occurs.
                                                                 0x00 = Trace synchronization requests are disabled.
                                                                 0x10 = Trace synchronization requests occur after 256 bytes of trace.
                                                                 0x11 = Trace synchronization requests occur after 512 bytes of trace.
                                                                 0x14 = Trace synchronization requests occur after 20 power of 2 bytes of trace. */
#else
		uint32_t period                      : 5;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	/* struct bdk_trcx_trcsyncpr_s        cn85xx; */
	/* struct bdk_trcx_trcsyncpr_s        cn88xx; */
} bdk_trcx_trcsyncpr_t;

static inline uint64_t BDK_TRCX_TRCSYNCPR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCSYNCPR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30034ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCSYNCPR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCSYNCPR(...) bdk_trcx_trcsyncpr_t
#define bustype_BDK_TRCX_TRCSYNCPR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCSYNCPR(p1) (p1)
#define arguments_BDK_TRCX_TRCSYNCPR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCSYNCPR(...) "TRCX_TRCSYNCPR"


/**
 * DAB32b - trc#_trctraceidr
 *
 * set the Trace ID value for instruction trace.
 *
 */
typedef union bdk_trcx_trctraceidr {
	uint32_t u;
	struct bdk_trcx_trctraceidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_7_31               : 25;
		uint32_t traceid                     : 7;  /**< R/W - Trace ID value for instruction trace. */
#else
		uint32_t traceid                     : 7;
		uint32_t reserved_7_31               : 25;
#endif
	} s;
	/* struct bdk_trcx_trctraceidr_s      cn85xx; */
	/* struct bdk_trcx_trctraceidr_s      cn88xx; */
} bdk_trcx_trctraceidr_t;

static inline uint64_t BDK_TRCX_TRCTRACEIDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCTRACEIDR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30040ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCTRACEIDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCTRACEIDR(...) bdk_trcx_trctraceidr_t
#define bustype_BDK_TRCX_TRCTRACEIDR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCTRACEIDR(p1) (p1)
#define arguments_BDK_TRCX_TRCTRACEIDR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCTRACEIDR(...) "TRCX_TRCTRACEIDR"


/**
 * DAB32b - trc#_trctsctlr
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trctsctlr {
	uint32_t u;
	struct bdk_trcx_trctsctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trctsctlr_s        cn85xx; */
	/* struct bdk_trcx_trctsctlr_s        cn88xx; */
} bdk_trcx_trctsctlr_t;

static inline uint64_t BDK_TRCX_TRCTSCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCTSCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30030ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCTSCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCTSCTLR(...) bdk_trcx_trctsctlr_t
#define bustype_BDK_TRCX_TRCTSCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCTSCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCTSCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCTSCTLR(...) "TRCX_TRCTSCTLR"


/**
 * DAB32b - trc#_trcvdarcctlr
 *
 * set or read the address range comparator for ViewData Include/Exclude control
 *
 */
typedef union bdk_trcx_trcvdarcctlr {
	uint32_t u;
	struct bdk_trcx_trcvdarcctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t exclude                     : 4;  /**< R/W - Select which address range comparators are in use with ViewData exclude control.
                                                                 0 = The address range that the address comparator pair[m-16] defines is not
                                                                      selected for the ViewData exclude control.
                                                                 1 = The address range that the address comparator pair[m-16] defines is
                                                                      selected for the ViewData exclude control. */
		uint32_t reserved_4_15               : 12;
		uint32_t incld                       : 4;  /**< R/W - Select which address range comparators are in use with ViewData include control.
                                                                 0 = The address range that the address comparator pair[m] defines is not
                                                                      selected for the ViewData include control.
                                                                 1 = The address range that the address comparator pair[m] defines is
                                                                      selected for the ViewData include control. */
#else
		uint32_t incld                       : 4;
		uint32_t reserved_4_15               : 12;
		uint32_t exclude                     : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_trcx_trcvdarcctlr_s     cn85xx; */
	/* struct bdk_trcx_trcvdarcctlr_s     cn88xx; */
} bdk_trcx_trcvdarcctlr_t;

static inline uint64_t BDK_TRCX_TRCVDARCCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVDARCCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC300A8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVDARCCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVDARCCTLR(...) bdk_trcx_trcvdarcctlr_t
#define bustype_BDK_TRCX_TRCVDARCCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVDARCCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVDARCCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVDARCCTLR(...) "TRCX_TRCVDARCCTLR"


/**
 * DAB32b - trc#_trcvdctlr
 *
 * Control data trace filtering.
 *
 */
typedef union bdk_trcx_trcvdctlr {
	uint32_t u;
	struct bdk_trcx_trcvdctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_13_31              : 19;
		uint32_t trcexdata                   : 1;  /**< R/W - Control the tracing of data transfer for exception and exception return.
                                                                 0 = Exception and exception return data transfers are not traced.
                                                                 1 = Exception and exception return data transfers are traced. */
		uint32_t tbi                         : 1;  /**< R/W - Control which information a trace unit populates in bit[63:56] of the data address.
                                                                 0 = The trace unit assgin bit[63:56] have the value of bit[55] of the data address,
                                                                     which is sign extension.
                                                                 1 = The trace unit assgin bit[63:56] have the value of bit[63:56] of the data address. */
		uint32_t pcrel                       : 1;  /**< R/W - Control whether a trace unit trace data for transfers that are
                                                                   relative to PC(program counter).
                                                                 0 = The trace unit does not affect tracing of PC relative transfers.
                                                                 1 = The trace unit does not trace the address or value portions of PC relative transfers. */
		uint32_t sprel                       : 2;  /**< R/W - Control whether a trace unit trace data for transfers that are
                                                                   relative to SP(Stack Pointer).
                                                                 0x0 = The trace unit does not affect tracing of SP relative transfers.
                                                                 0x1 = Reserved
                                                                 0x2 = The trace unit does not trace the address portions of SP relative transfers.
                                                                 0x3 = The trace unit does not trace the address or value portions of SP relative
                                                                 transfers. */
		uint32_t evnt                        : 8;  /**< R/W - An event selector. */
#else
		uint32_t evnt                        : 8;
		uint32_t sprel                       : 2;
		uint32_t pcrel                       : 1;
		uint32_t tbi                         : 1;
		uint32_t trcexdata                   : 1;
		uint32_t reserved_13_31              : 19;
#endif
	} s;
	/* struct bdk_trcx_trcvdctlr_s        cn85xx; */
	/* struct bdk_trcx_trcvdctlr_s        cn88xx; */
} bdk_trcx_trcvdctlr_t;

static inline uint64_t BDK_TRCX_TRCVDCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVDCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC300A0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVDCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVDCTLR(...) bdk_trcx_trcvdctlr_t
#define bustype_BDK_TRCX_TRCVDCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVDCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVDCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVDCTLR(...) "TRCX_TRCVDCTLR"


/**
 * DAB32b - trc#_trcvdsacctlr
 *
 * set or read the single address comparator for ViewData Include/Exclude control
 *
 */
typedef union bdk_trcx_trcvdsacctlr {
	uint32_t u;
	struct bdk_trcx_trcvdsacctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t exclude                     : 4;  /**< R/W - Select which single address comparators are in use with ViewData exclude control.
                                                                 0 = The single address comparator[m-16] is not
                                                                      selected for the ViewData exclude control.
                                                                 1 = The single address comparator[m-16] is
                                                                      selected for the ViewData exclude control. */
		uint32_t reserved_4_15               : 12;
		uint32_t incld                       : 4;  /**< R/W - Select which single address comparators are in use with ViewData include control.
                                                                 0 = The single address comparator[m] is not
                                                                      selected for the ViewData include control.
                                                                 1 = The single address comparator[m] is
                                                                      selected for the ViewData include control. */
#else
		uint32_t incld                       : 4;
		uint32_t reserved_4_15               : 12;
		uint32_t exclude                     : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_trcx_trcvdsacctlr_s     cn85xx; */
	/* struct bdk_trcx_trcvdsacctlr_s     cn88xx; */
} bdk_trcx_trcvdsacctlr_t;

static inline uint64_t BDK_TRCX_TRCVDSACCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVDSACCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC300A4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVDSACCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVDSACCTLR(...) bdk_trcx_trcvdsacctlr_t
#define bustype_BDK_TRCX_TRCVDSACCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVDSACCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVDSACCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVDSACCTLR(...) "TRCX_TRCVDSACCTLR"


/**
 * DAB32b - trc#_trcvictlr
 *
 * Control instruction trace filtering.
 *
 */
typedef union bdk_trcx_trcvictlr {
	uint32_t u;
	struct bdk_trcx_trcvictlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t level_ns                    : 4;  /**< R/W - In nonsecure state, each bit control whether instruction tracing is enabled for
                                                                   the corresponding exception level.
                                                                 0 = the trace unit generates the instruction trace for exception level n.
                                                                 1 = the trace unit dos not generate the instruction trace for exception level n.
                                                                    <20>  exception level 0.
                                                                    <21>  exception level 1.
                                                                    <22>  exception level 2.
                                                                    <23>  RAZ/WI. */
		uint32_t level_s                     : 4;  /**< R/W - In secure state, each bit control whether instruction tracing is enabled for
                                                                   the corresponding exception level.
                                                                 0 = the trace unit generates the instruction trace for exception level n.
                                                                 1 = the trace unit dos not generate the instruction trace for exception level n.
                                                                    <16> = exception level 0.
                                                                    <17> = exception level 1.
                                                                    <18> = RAZ/WI.
                                                                    <19> = exception level 3. */
		uint32_t reserved_12_15              : 4;
		uint32_t trcerr                      : 1;  /**< R/W - Control whether a trace unit must trace a system error exception.
                                                                 0 = The trace unit does not trace a system error exception.
                                                                 1 = The trace unit always traces a system error exception. */
		uint32_t trcreset                    : 1;  /**< R/W - Control whether a trace unit must trace a reset exception.
                                                                 0 = The trace unit does not trace a reset exception.
                                                                 1 = The trace unit always traces a reset exception. */
		uint32_t ssstatus                    : 1;  /**< R/W - This bit return the status of start-stop logic.
                                                                 0 = The start-stop logic is in stop state.
                                                                 1 = The start-stop logic is in start state. */
		uint32_t reserved_8_8                : 1;
		uint32_t evnt                        : 8;  /**< R/W - An event selector. */
#else
		uint32_t evnt                        : 8;
		uint32_t reserved_8_8                : 1;
		uint32_t ssstatus                    : 1;
		uint32_t trcreset                    : 1;
		uint32_t trcerr                      : 1;
		uint32_t reserved_12_15              : 4;
		uint32_t level_s                     : 4;
		uint32_t level_ns                    : 4;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_trcx_trcvictlr_s        cn85xx; */
	/* struct bdk_trcx_trcvictlr_s        cn88xx; */
} bdk_trcx_trcvictlr_t;

static inline uint64_t BDK_TRCX_TRCVICTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVICTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30080ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVICTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVICTLR(...) bdk_trcx_trcvictlr_t
#define bustype_BDK_TRCX_TRCVICTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVICTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVICTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVICTLR(...) "TRCX_TRCVICTLR"


/**
 * DAB32b - trc#_trcviiectlr
 *
 * Set or read ViewInst Include/Exclude address comparator.
 *
 */
typedef union bdk_trcx_trcviiectlr {
	uint32_t u;
	struct bdk_trcx_trcviiectlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t exclude                     : 4;  /**< R/W - Exclude range field. Bit[m]
                                                                 0 = The address range that the address comparator pair[m-16] defines is not
                                                                      selected for the ViewInst exclude control.
                                                                 1 = The address range that the address comparator pair[m-16] defines is
                                                                      selected for the ViewInst exclude control. */
		uint32_t reserved_4_15               : 12;
		uint32_t incld                       : 4;  /**< R/W - Include range field.
                                                                 0 = The address range that the address comparator pair[m] defines is not
                                                                      selected for the ViewInst include control.
                                                                 1 = The address range that the address comparator pair[m] defines is
                                                                      selected for the ViewInst include control. */
#else
		uint32_t incld                       : 4;
		uint32_t reserved_4_15               : 12;
		uint32_t exclude                     : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_trcx_trcviiectlr_s      cn85xx; */
	/* struct bdk_trcx_trcviiectlr_s      cn88xx; */
} bdk_trcx_trcviiectlr_t;

static inline uint64_t BDK_TRCX_TRCVIIECTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVIIECTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30084ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVIIECTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVIIECTLR(...) bdk_trcx_trcviiectlr_t
#define bustype_BDK_TRCX_TRCVIIECTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVIIECTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVIIECTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVIIECTLR(...) "TRCX_TRCVIIECTLR"


/**
 * DAB32b - trc#_trcvipcssctlr
 *
 * read which PE comparator can control ViewInst start-stop logic
 *
 */
typedef union bdk_trcx_trcvipcssctlr {
	uint32_t u;
	struct bdk_trcx_trcvipcssctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t stop                        : 4;  /**< R/W - Select which PE comparator inputs are in use with ViewInst start-stop control,
                                                                   for the purpose of stopping trace.
                                                                 0 = The single PE comparator[m-16] is not
                                                                      selected as a stop resource.
                                                                 1 = The single PE comparator[m-16] is
                                                                      selected as a stop resource. */
		uint32_t reserved_4_15               : 12;
		uint32_t start                       : 4;  /**< R/W - Select which PE comparator inputs are in use with ViewInst start-stop control,
                                                                   for the purpose of starting trace.
                                                                 0 = The single PE comparator[m] is not
                                                                      selected as a start resource.
                                                                 1 = The single PE comparator[m] is
                                                                      selected as a start resource. */
#else
		uint32_t start                       : 4;
		uint32_t reserved_4_15               : 12;
		uint32_t stop                        : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_trcx_trcvipcssctlr_s    cn85xx; */
	/* struct bdk_trcx_trcvipcssctlr_s    cn88xx; */
} bdk_trcx_trcvipcssctlr_t;

static inline uint64_t BDK_TRCX_TRCVIPCSSCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVIPCSSCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3008Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVIPCSSCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVIPCSSCTLR(...) bdk_trcx_trcvipcssctlr_t
#define bustype_BDK_TRCX_TRCVIPCSSCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVIPCSSCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVIPCSSCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVIPCSSCTLR(...) "TRCX_TRCVIPCSSCTLR"


/**
 * DAB32b - trc#_trcvissctlr
 *
 * set or read the single address comparator that controls start-stop logic
 *
 */
typedef union bdk_trcx_trcvissctlr {
	uint32_t u;
	struct bdk_trcx_trcvissctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t stop                        : 4;  /**< R/W - Select which address comparators are in use with ViewInst start-stop control,
                                                                   for the purpose of stopping trace.
                                                                 0 = The single address comparator[m-16] is not
                                                                      selected as a stop resource.
                                                                 1 = The single address comparator[m-16] is
                                                                      selected as a stop resource. */
		uint32_t reserved_4_15               : 12;
		uint32_t start                       : 4;  /**< R/W - Select which address comparators are in use with ViewInst start-stop control,
                                                                   for the purpose of starting trace.
                                                                 0 = The single address comparator[m] is not
                                                                      selected as a start resource.
                                                                 1 = The single address comparator[m] is
                                                                      selected as a start resource. */
#else
		uint32_t start                       : 4;
		uint32_t reserved_4_15               : 12;
		uint32_t stop                        : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_trcx_trcvissctlr_s      cn85xx; */
	/* struct bdk_trcx_trcvissctlr_s      cn88xx; */
} bdk_trcx_trcvissctlr_t;

static inline uint64_t BDK_TRCX_TRCVISSCTLR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVISSCTLR(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30088ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVISSCTLR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVISSCTLR(...) bdk_trcx_trcvissctlr_t
#define bustype_BDK_TRCX_TRCVISSCTLR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVISSCTLR(p1) (p1)
#define arguments_BDK_TRCX_TRCVISSCTLR(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVISSCTLR(...) "TRCX_TRCVISSCTLR"


/**
 * DAB32b - trc#_trcvmidcctlr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcvmidcctlr0 {
	uint32_t u;
	struct bdk_trcx_trcvmidcctlr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcvmidcctlr0_s    cn85xx; */
	/* struct bdk_trcx_trcvmidcctlr0_s    cn88xx; */
} bdk_trcx_trcvmidcctlr0_t;

static inline uint64_t BDK_TRCX_TRCVMIDCCTLR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVMIDCCTLR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30688ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVMIDCCTLR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVMIDCCTLR0(...) bdk_trcx_trcvmidcctlr0_t
#define bustype_BDK_TRCX_TRCVMIDCCTLR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVMIDCCTLR0(p1) (p1)
#define arguments_BDK_TRCX_TRCVMIDCCTLR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVMIDCCTLR0(...) "TRCX_TRCVMIDCCTLR0"


/**
 * DAB32b - trc#_trcvmidcctlr1
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcvmidcctlr1 {
	uint32_t u;
	struct bdk_trcx_trcvmidcctlr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcvmidcctlr1_s    cn85xx; */
	/* struct bdk_trcx_trcvmidcctlr1_s    cn88xx; */
} bdk_trcx_trcvmidcctlr1_t;

static inline uint64_t BDK_TRCX_TRCVMIDCCTLR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVMIDCCTLR1(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC3068Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVMIDCCTLR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVMIDCCTLR1(...) bdk_trcx_trcvmidcctlr1_t
#define bustype_BDK_TRCX_TRCVMIDCCTLR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVMIDCCTLR1(p1) (p1)
#define arguments_BDK_TRCX_TRCVMIDCCTLR1(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVMIDCCTLR1(...) "TRCX_TRCVMIDCCTLR1"


/**
 * DAB32b - trc#_trcvmidcvr0
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_trcx_trcvmidcvr0 {
	uint32_t u;
	struct bdk_trcx_trcvmidcvr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_trcx_trcvmidcvr0_s      cn85xx; */
	/* struct bdk_trcx_trcvmidcvr0_s      cn88xx; */
} bdk_trcx_trcvmidcvr0_t;

static inline uint64_t BDK_TRCX_TRCVMIDCVR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_TRCX_TRCVMIDCVR0(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x000087A00FC30640ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_TRCX_TRCVMIDCVR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_TRCX_TRCVMIDCVR0(...) bdk_trcx_trcvmidcvr0_t
#define bustype_BDK_TRCX_TRCVMIDCVR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_TRCX_TRCVMIDCVR0(p1) (p1)
#define arguments_BDK_TRCX_TRCVMIDCVR0(p1) (p1),-1,-1,-1
#define basename_BDK_TRCX_TRCVMIDCVR0(...) "TRCX_TRCVMIDCVR0"

#endif /* __BDK_CSRS_DAB_TRC__ */
