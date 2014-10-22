#ifndef __BDK_CSRS_DAB_SYSCTI__
#define __BDK_CSRS_DAB_SYSCTI__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Inc. (support@cavium.com). All rights
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
 * Cavium DAB_SYSCTI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * DAB32b - syscti#_asicctl
 *
 * Provides a control for external multiplexing of additional triggers.
 *
 */
typedef union bdk_sysctix_asicctl {
	uint32_t u;
	struct bdk_sysctix_asicctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t asicctl                     : 3;  /**< R/W - Implementation defined ASIC control. Provides a control for
                                                                 external multiplexing of additional triggers.
                                                                 If external multiplexing of trigger signals is implemented
                                                                     then the number of multiplexed signals on each trigger must be
                                                                     reflected in SYSCTIDEVID.EXTMUXNUM.
                                                                 If SYSCTIDEVID.EXTMUXNUM is zero, this field is RAZ. */
#else
		uint32_t asicctl                     : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_asicctl_s       cn88xx; */
	/* struct bdk_sysctix_asicctl_s       cn88xxp1; */
} bdk_sysctix_asicctl_t;

static inline uint64_t BDK_SYSCTIX_ASICCTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_ASICCTL(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810144ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_ASICCTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_ASICCTL(...) bdk_sysctix_asicctl_t
#define bustype_BDK_SYSCTIX_ASICCTL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_ASICCTL(p1) (p1)
#define arguments_BDK_SYSCTIX_ASICCTL(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_ASICCTL(...) "SYSCTIX_ASICCTL"


/**
 * DAB32b - syscti#_claimclr_el1
 *
 * Used by software to read the values of the CLAIM bits, and to
 * clear these bits to 0.
 */
typedef union bdk_sysctix_claimclr_el1 {
	uint32_t u;
	struct bdk_sysctix_claimclr_el1_s {
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
	/* struct bdk_sysctix_claimclr_el1_s  cn88xx; */
	/* struct bdk_sysctix_claimclr_el1_s  cn88xxp1; */
} bdk_sysctix_claimclr_el1_t;

static inline uint64_t BDK_SYSCTIX_CLAIMCLR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CLAIMCLR_EL1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FA4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CLAIMCLR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CLAIMCLR_EL1(...) bdk_sysctix_claimclr_el1_t
#define bustype_BDK_SYSCTIX_CLAIMCLR_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CLAIMCLR_EL1(p1) (p1)
#define arguments_BDK_SYSCTIX_CLAIMCLR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CLAIMCLR_EL1(...) "SYSCTIX_CLAIMCLR_EL1"


/**
 * DAB32b - syscti#_claimset_el1
 *
 * Used by software to set CLAIM bits to 1.
 *
 */
typedef union bdk_sysctix_claimset_el1 {
	uint32_t u;
	struct bdk_sysctix_claimset_el1_s {
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
	/* struct bdk_sysctix_claimset_el1_s  cn88xx; */
	/* struct bdk_sysctix_claimset_el1_s  cn88xxp1; */
} bdk_sysctix_claimset_el1_t;

static inline uint64_t BDK_SYSCTIX_CLAIMSET_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CLAIMSET_EL1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FA0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CLAIMSET_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CLAIMSET_EL1(...) bdk_sysctix_claimset_el1_t
#define bustype_BDK_SYSCTIX_CLAIMSET_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CLAIMSET_EL1(p1) (p1)
#define arguments_BDK_SYSCTIX_CLAIMSET_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CLAIMSET_EL1(...) "SYSCTIX_CLAIMSET_EL1"


/**
 * DAB32b - syscti#_ctiappclear
 *
 * Clears bits of the Application Trigger register.
 *
 */
typedef union bdk_sysctix_ctiappclear {
	uint32_t u;
	struct bdk_sysctix_ctiappclear_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctiappclear_s   cn88xx; */
	/* struct bdk_sysctix_ctiappclear_s   cn88xxp1; */
} bdk_sysctix_ctiappclear_t;

static inline uint64_t BDK_SYSCTIX_CTIAPPCLEAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIAPPCLEAR(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810018ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIAPPCLEAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIAPPCLEAR(...) bdk_sysctix_ctiappclear_t
#define bustype_BDK_SYSCTIX_CTIAPPCLEAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIAPPCLEAR(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIAPPCLEAR(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIAPPCLEAR(...) "SYSCTIX_CTIAPPCLEAR"


/**
 * DAB32b - syscti#_ctiapppulse
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_sysctix_ctiapppulse {
	uint32_t u;
	struct bdk_sysctix_ctiapppulse_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t apppulse                    : 3;  /**< WO - Generate event pulse on ECT channel \<x\>.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     SYSCTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 Writing to this bit has the following effect:
                                                                 0 = No effect.
                                                                 1 = Channel \<x\> event pulse generated for one clock period. */
#else
		uint32_t apppulse                    : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctiapppulse_s   cn88xx; */
	/* struct bdk_sysctix_ctiapppulse_s   cn88xxp1; */
} bdk_sysctix_ctiapppulse_t;

static inline uint64_t BDK_SYSCTIX_CTIAPPPULSE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIAPPPULSE(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F81001Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIAPPPULSE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIAPPPULSE(...) bdk_sysctix_ctiapppulse_t
#define bustype_BDK_SYSCTIX_CTIAPPPULSE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIAPPPULSE(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIAPPPULSE(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIAPPPULSE(...) "SYSCTIX_CTIAPPPULSE"


/**
 * DAB32b - syscti#_ctiappset
 *
 * Sets bits of the Application Trigger register.
 *
 */
typedef union bdk_sysctix_ctiappset {
	uint32_t u;
	struct bdk_sysctix_ctiappset_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctiappset_s     cn88xx; */
	/* struct bdk_sysctix_ctiappset_s     cn88xxp1; */
} bdk_sysctix_ctiappset_t;

static inline uint64_t BDK_SYSCTIX_CTIAPPSET(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIAPPSET(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810014ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIAPPSET", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIAPPSET(...) bdk_sysctix_ctiappset_t
#define bustype_BDK_SYSCTIX_CTIAPPSET(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIAPPSET(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIAPPSET(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIAPPSET(...) "SYSCTIX_CTIAPPSET"


/**
 * DAB32b - syscti#_ctiauthstatus_el1
 *
 * Provides information about the state of the implementation defined authentication
 * interface.
 */
typedef union bdk_sysctix_ctiauthstatus_el1 {
	uint32_t u;
	struct bdk_sysctix_ctiauthstatus_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t nsnid1                      : 1;  /**< RO - If EL3 is not implemented and the processor is Secure, holds
                                                                     the same value as DBGAUTHSTATUS_EL1.SNID.
                                                                 Otherwise, holds the same value as DBGAUTHSTATUS_EL1.NSNID. */
		uint32_t nsnid0                      : 1;
		uint32_t nsid1                       : 1;  /**< RO - If EL3 is not implemented and the processor is Secure, holds
                                                                     the same value as DBGAUTHSTATUS_EL1.SID.
                                                                 Otherwise, holds the same value as DBGAUTHSTATUS_EL1.NSID. */
		uint32_t nsid0                       : 1;
#else
		uint32_t nsid0                       : 1;
		uint32_t nsid1                       : 1;
		uint32_t nsnid0                      : 1;
		uint32_t nsnid1                      : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_sysctix_ctiauthstatus_el1_s cn88xx; */
	/* struct bdk_sysctix_ctiauthstatus_el1_s cn88xxp1; */
} bdk_sysctix_ctiauthstatus_el1_t;

static inline uint64_t BDK_SYSCTIX_CTIAUTHSTATUS_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIAUTHSTATUS_EL1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FB8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIAUTHSTATUS_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIAUTHSTATUS_EL1(...) bdk_sysctix_ctiauthstatus_el1_t
#define bustype_BDK_SYSCTIX_CTIAUTHSTATUS_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIAUTHSTATUS_EL1(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIAUTHSTATUS_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIAUTHSTATUS_EL1(...) "SYSCTIX_CTIAUTHSTATUS_EL1"


/**
 * DAB32b - syscti#_ctichinstatus
 *
 * Provides the raw status of the ECT channel inputs.
 *
 */
typedef union bdk_sysctix_ctichinstatus {
	uint32_t u;
	struct bdk_sysctix_ctichinstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t chin                        : 3;  /**< RO - Input channel \<n\> status.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     SYSCTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ.

                                                                 0 = Input channel \<n\> is inactive.
                                                                 1 = Input channel \<n\> is active. */
#else
		uint32_t chin                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctichinstatus_s cn88xx; */
	/* struct bdk_sysctix_ctichinstatus_s cn88xxp1; */
} bdk_sysctix_ctichinstatus_t;

static inline uint64_t BDK_SYSCTIX_CTICHINSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICHINSTATUS(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810138ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICHINSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICHINSTATUS(...) bdk_sysctix_ctichinstatus_t
#define bustype_BDK_SYSCTIX_CTICHINSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICHINSTATUS(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICHINSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICHINSTATUS(...) "SYSCTIX_CTICHINSTATUS"


/**
 * DAB32b - syscti#_ctichoutstatus
 *
 * Provides the status of the ECT channel outputs.
 *
 */
typedef union bdk_sysctix_ctichoutstatus {
	uint32_t u;
	struct bdk_sysctix_ctichoutstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t chout                       : 3;  /**< RO - Output channel \<n\> status.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     SYSCTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ.

                                                                 0 = Output channel \<n\> is inactive.
                                                                 1 = Output channel \<n\> is active. */
#else
		uint32_t chout                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctichoutstatus_s cn88xx; */
	/* struct bdk_sysctix_ctichoutstatus_s cn88xxp1; */
} bdk_sysctix_ctichoutstatus_t;

static inline uint64_t BDK_SYSCTIX_CTICHOUTSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICHOUTSTATUS(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F81013Cull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICHOUTSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICHOUTSTATUS(...) bdk_sysctix_ctichoutstatus_t
#define bustype_BDK_SYSCTIX_CTICHOUTSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICHOUTSTATUS(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICHOUTSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICHOUTSTATUS(...) "SYSCTIX_CTICHOUTSTATUS"


/**
 * DAB32b - syscti#_cticidr0
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_cticidr0 {
	uint32_t u;
	struct bdk_sysctix_cticidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_0                     : 8;  /**< RO - Preamble. Must read as 0x0D. */
#else
		uint32_t prmbl_0                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_cticidr0_s      cn88xx; */
	/* struct bdk_sysctix_cticidr0_s      cn88xxp1; */
} bdk_sysctix_cticidr0_t;

static inline uint64_t BDK_SYSCTIX_CTICIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICIDR0(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FF0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICIDR0(...) bdk_sysctix_cticidr0_t
#define bustype_BDK_SYSCTIX_CTICIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICIDR0(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICIDR0(...) "SYSCTIX_CTICIDR0"


/**
 * DAB32b - syscti#_cticidr1
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_cticidr1 {
	uint32_t u;
	struct bdk_sysctix_cticidr1_s {
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
	/* struct bdk_sysctix_cticidr1_s      cn88xx; */
	/* struct bdk_sysctix_cticidr1_s      cn88xxp1; */
} bdk_sysctix_cticidr1_t;

static inline uint64_t BDK_SYSCTIX_CTICIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICIDR1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FF4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICIDR1(...) bdk_sysctix_cticidr1_t
#define bustype_BDK_SYSCTIX_CTICIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICIDR1(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICIDR1(...) "SYSCTIX_CTICIDR1"


/**
 * DAB32b - syscti#_cticidr2
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_cticidr2 {
	uint32_t u;
	struct bdk_sysctix_cticidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_2                     : 8;  /**< RO - Preamble. Must read as 0x05. */
#else
		uint32_t prmbl_2                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_cticidr2_s      cn88xx; */
	/* struct bdk_sysctix_cticidr2_s      cn88xxp1; */
} bdk_sysctix_cticidr2_t;

static inline uint64_t BDK_SYSCTIX_CTICIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICIDR2(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FF8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICIDR2(...) bdk_sysctix_cticidr2_t
#define bustype_BDK_SYSCTIX_CTICIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICIDR2(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICIDR2(...) "SYSCTIX_CTICIDR2"


/**
 * DAB32b - syscti#_cticidr3
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_cticidr3 {
	uint32_t u;
	struct bdk_sysctix_cticidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_3                     : 8;  /**< RO - Preamble. Must read as 0xB1. */
#else
		uint32_t prmbl_3                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_cticidr3_s      cn88xx; */
	/* struct bdk_sysctix_cticidr3_s      cn88xxp1; */
} bdk_sysctix_cticidr3_t;

static inline uint64_t BDK_SYSCTIX_CTICIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICIDR3(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FFCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICIDR3(...) bdk_sysctix_cticidr3_t
#define bustype_BDK_SYSCTIX_CTICIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICIDR3(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICIDR3(...) "SYSCTIX_CTICIDR3"


/**
 * DAB32b - syscti#_cticontrol
 *
 * Controls whether the SYSCTI is enabled.
 *
 */
typedef union bdk_sysctix_cticontrol {
	uint32_t u;
	struct bdk_sysctix_cticontrol_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t glben                       : 1;  /**< R/W - Enables or disables the SYSCTI mapping functions.
                                                                 When the mapping functions are disabled, no new events are
                                                                     signaled on either output triggers or output channels. If a
                                                                     previously asserted output trigger has not been acknowledged,
                                                                     it remains asserted after the mapping functions are disabled.
                                                                     All output triggers are disabled by SYSCTI reset.

                                                                 0 = SYSCTI mapping functions disabled.
                                                                 1 = SYSCTI mapping functions enabled. */
#else
		uint32_t glben                       : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_sysctix_cticontrol_s    cn88xx; */
	/* struct bdk_sysctix_cticontrol_s    cn88xxp1; */
} bdk_sysctix_cticontrol_t;

static inline uint64_t BDK_SYSCTIX_CTICONTROL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTICONTROL(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810000ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTICONTROL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTICONTROL(...) bdk_sysctix_cticontrol_t
#define bustype_BDK_SYSCTIX_CTICONTROL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTICONTROL(p1) (p1)
#define arguments_BDK_SYSCTIX_CTICONTROL(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTICONTROL(...) "SYSCTIX_CTICONTROL"


/**
 * DAB32b - syscti#_ctidevaff0
 *
 * Copy of the low half of the processor MPIDR_EL1 register that allows a debugger to
 * determine which processor in a multiprocessor system the SYSCTI component relates
 * to.
 */
typedef union bdk_sysctix_ctidevaff0 {
	uint32_t u;
	struct bdk_sysctix_ctidevaff0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< RO - MPIDR_EL1 low half. Read-only copy of the low half of MPIDR_EL1, as seen from
                                                                 the highest implemented exception level. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctidevaff0_s    cn88xx; */
	/* struct bdk_sysctix_ctidevaff0_s    cn88xxp1; */
} bdk_sysctix_ctidevaff0_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVAFF0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVAFF0(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FA8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVAFF0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVAFF0(...) bdk_sysctix_ctidevaff0_t
#define bustype_BDK_SYSCTIX_CTIDEVAFF0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVAFF0(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVAFF0(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVAFF0(...) "SYSCTIX_CTIDEVAFF0"


/**
 * DAB32b - syscti#_ctidevaff1
 *
 * Copy of the high half of the processor MPIDR_EL1 register that allows a debugger to
 * determine which processor in a multiprocessor system the SYSCTI component relates
 * to.
 */
typedef union bdk_sysctix_ctidevaff1 {
	uint32_t u;
	struct bdk_sysctix_ctidevaff1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< RO - MPIDR_EL1 high half. Read-only copy of the high half of MPIDR_EL1, as seen from
                                                                 the highest implemented exception level. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctidevaff1_s    cn88xx; */
	/* struct bdk_sysctix_ctidevaff1_s    cn88xxp1; */
} bdk_sysctix_ctidevaff1_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVAFF1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVAFF1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FACull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVAFF1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVAFF1(...) bdk_sysctix_ctidevaff1_t
#define bustype_BDK_SYSCTIX_CTIDEVAFF1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVAFF1(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVAFF1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVAFF1(...) "SYSCTIX_CTIDEVAFF1"


/**
 * DAB32b - syscti#_ctidevarch
 *
 * Identifies the programmers' model architecture.
 *
 */
typedef union bdk_sysctix_ctidevarch {
	uint32_t u;
	struct bdk_sysctix_ctidevarch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t architect                   : 11; /**< RO - Defines the architecture of the component. This is ARM Limited.

                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.

                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
		uint32_t present                     : 1;  /**< RO - When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
		uint32_t revision                    : 4;  /**< RO - Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For SYSCTI, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
		uint32_t archid                      : 16; /**< RO - Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For SYSCTI:
                                                                  Bits [15:12] are the architecture version, 0x1.
                                                                  Bits [11:0] are the architecture part number, 0xA14.

                                                                 This corresponds to SYSCTI architecture version SYSCTIv2. */
#else
		uint32_t archid                      : 16;
		uint32_t revision                    : 4;
		uint32_t present                     : 1;
		uint32_t architect                   : 11;
#endif
	} s;
	/* struct bdk_sysctix_ctidevarch_s    cn88xx; */
	/* struct bdk_sysctix_ctidevarch_s    cn88xxp1; */
} bdk_sysctix_ctidevarch_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVARCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVARCH(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FBCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVARCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVARCH(...) bdk_sysctix_ctidevarch_t
#define bustype_BDK_SYSCTIX_CTIDEVARCH(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVARCH(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVARCH(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVARCH(...) "SYSCTIX_CTIDEVARCH"


/**
 * DAB32b - syscti#_ctidevid
 *
 * Describes the component to the debugger.
 *
 */
typedef union bdk_sysctix_ctidevid {
	uint32_t u;
	struct bdk_sysctix_ctidevid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t inout_gate                  : 2;  /**< RO - Input/output options. Indicates presence of the input gate. If
                                                                     the CTM is not implemented, this field is RAZ.
                                                                 All other values are reserved.
                                                                 0x0 = SYSCTIGATE does not mask propagation of input events from
                                                                     external channels.
                                                                 0x1 = SYSCTIGATE masks propagation of input events from external
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
		uint32_t extmuxnum                   : 5;  /**< RO - Maximum number of external triggers available for multiplexing.
                                                                 This relates only to additional external triggers outside those defined
                                                                 for v8-A. */
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
	/* struct bdk_sysctix_ctidevid_s      cn88xx; */
	/* struct bdk_sysctix_ctidevid_s      cn88xxp1; */
} bdk_sysctix_ctidevid_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVID(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FC8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVID(...) bdk_sysctix_ctidevid_t
#define bustype_BDK_SYSCTIX_CTIDEVID(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVID(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVID(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVID(...) "SYSCTIX_CTIDEVID"


/**
 * DAB32b - syscti#_ctidevid1
 *
 * Reserved for future information about the component to the debugger.
 *
 */
typedef union bdk_sysctix_ctidevid1 {
	uint32_t u;
	struct bdk_sysctix_ctidevid1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctidevid1_s     cn88xx; */
	/* struct bdk_sysctix_ctidevid1_s     cn88xxp1; */
} bdk_sysctix_ctidevid1_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVID1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVID1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FC4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVID1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVID1(...) bdk_sysctix_ctidevid1_t
#define bustype_BDK_SYSCTIX_CTIDEVID1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVID1(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVID1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVID1(...) "SYSCTIX_CTIDEVID1"


/**
 * DAB32b - syscti#_ctidevid2
 *
 * Reserved for future information about the SYSCTI component to the debugger.
 *
 */
typedef union bdk_sysctix_ctidevid2 {
	uint32_t u;
	struct bdk_sysctix_ctidevid2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctidevid2_s     cn88xx; */
	/* struct bdk_sysctix_ctidevid2_s     cn88xxp1; */
} bdk_sysctix_ctidevid2_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVID2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVID2(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FC0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVID2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVID2(...) bdk_sysctix_ctidevid2_t
#define bustype_BDK_SYSCTIX_CTIDEVID2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVID2(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVID2(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVID2(...) "SYSCTIX_CTIDEVID2"


/**
 * DAB32b - syscti#_ctidevtype
 *
 * Indicates to a debugger that this component is part of a processor's cross-trigger
 * interface.
 */
typedef union bdk_sysctix_ctidevtype {
	uint32_t u;
	struct bdk_sysctix_ctidevtype_s {
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
	/* struct bdk_sysctix_ctidevtype_s    cn88xx; */
	/* struct bdk_sysctix_ctidevtype_s    cn88xxp1; */
} bdk_sysctix_ctidevtype_t;

static inline uint64_t BDK_SYSCTIX_CTIDEVTYPE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIDEVTYPE(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FCCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIDEVTYPE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIDEVTYPE(...) bdk_sysctix_ctidevtype_t
#define bustype_BDK_SYSCTIX_CTIDEVTYPE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIDEVTYPE(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIDEVTYPE(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIDEVTYPE(...) "SYSCTIX_CTIDEVTYPE"


/**
 * DAB32b - syscti#_ctigate
 *
 * Determines whether events on channels propagate through the
 * CTM to other ECT components, or from the CTM into the SYSCTI.
 */
typedef union bdk_sysctix_ctigate {
	uint32_t u;
	struct bdk_sysctix_ctigate_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t gate                        : 3;  /**< R/W - Channel \<x\> gate enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     SYSCTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = Disable output and, if SYSCTIDEVID.INOUT = 0x1.
                                                                 1 = Enable output and, if SYSCTIDEVID.INOUT = 0x1. */
#else
		uint32_t gate                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctigate_s       cn88xx; */
	/* struct bdk_sysctix_ctigate_s       cn88xxp1; */
} bdk_sysctix_ctigate_t;

static inline uint64_t BDK_SYSCTIX_CTIGATE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIGATE(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810140ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIGATE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIGATE(...) bdk_sysctix_ctigate_t
#define bustype_BDK_SYSCTIX_CTIGATE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIGATE(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIGATE(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIGATE(...) "SYSCTIX_CTIGATE"


/**
 * DAB32b - syscti#_ctiinen#
 *
 * Enables the signaling of an event on output channels when
 * input trigger event n is received by the SYSCTI.
 */
typedef union bdk_sysctix_ctiinenx {
	uint32_t u;
	struct bdk_sysctix_ctiinenx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t inen                        : 3;  /**< R/W - Input trigger \<n\> to output channel \<x\> enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     SYSCTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = Input trigger \<n\> will not generate an event on output channel
                                                                     \<x\>.
                                                                 1 = Input trigger \<n\> will generate an event on output channel
                                                                     \<x\>.

                                                                 In CNXXXX SYSCTIINEN(3..31) are ignored as there are only 3 channels. */
#else
		uint32_t inen                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctiinenx_s      cn88xx; */
	/* struct bdk_sysctix_ctiinenx_s      cn88xxp1; */
} bdk_sysctix_ctiinenx_t;

static inline uint64_t BDK_SYSCTIX_CTIINENX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIINENX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 6)) && ((param2 <= 2)))
		return 0x000087A00F810020ull + (param1 & 7) * 0x80000ull + (param2 & 3) * 0x4ull;
	csr_fatal("BDK_SYSCTIX_CTIINENX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIINENX(...) bdk_sysctix_ctiinenx_t
#define bustype_BDK_SYSCTIX_CTIINENX(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIINENX(p1,p2) (p1)
#define arguments_BDK_SYSCTIX_CTIINENX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SYSCTIX_CTIINENX(...) "SYSCTIX_CTIINENX"


/**
 * DAB32b - syscti#_ctiintack
 *
 * Creates soft acknowledges for output triggers.
 *
 */
typedef union bdk_sysctix_ctiintack {
	uint32_t u;
	struct bdk_sysctix_ctiintack_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ack                         : 3;  /**< RO - Acknowledge for output trigger \<n\>.
                                                                 N is the number of SYSCTI triggers implemented as defined by the
                                                                     SYSCTIDEVID.NUMTRIG field. Bits [31:N] are RAZ/WI.

                                                                 If any of the following is true, writes to ACK\<n\> are ignored:
                                                                 * n \>= SYSCTIDEVID.NUMTRIG, the number of implemented triggers.
                                                                 * Output trigger n is not active
                                                                 * The channel mapping function output, as controlled by
                                                                     SYSCTIOUTEN\<n\>, is still active.

                                                                 Otherwise, if any of the following are true, it is
                                                                     implementation defined whether writes to ACK\<n\> are ignored:
                                                                 * Output trigger n is not implemented.
                                                                 * Output trigger n is not connected.
                                                                 * Output trigger n is self-acknowledging and does not require
                                                                     software acknowledge.

                                                                 Otherwise, the behavior on writes to ACK\<n\> is as follows:
                                                                 0 = No effect.
                                                                 1 = Deactivate the trigger. */
#else
		uint32_t ack                         : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctiintack_s     cn88xx; */
	/* struct bdk_sysctix_ctiintack_s     cn88xxp1; */
} bdk_sysctix_ctiintack_t;

static inline uint64_t BDK_SYSCTIX_CTIINTACK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIINTACK(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810010ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIINTACK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIINTACK(...) bdk_sysctix_ctiintack_t
#define bustype_BDK_SYSCTIX_CTIINTACK(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIINTACK(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIINTACK(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIINTACK(...) "SYSCTIX_CTIINTACK"


/**
 * DAB32b - syscti#_ctiitctrl
 *
 * Enables the SYSCTI to switch from its default mode into
 * integration mode, where test software can control directly the
 * inputs and outputs of the processor, for integration testing
 * or topology detection.
 */
typedef union bdk_sysctix_ctiitctrl {
	uint32_t u;
	struct bdk_sysctix_ctiitctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t ime                         : 1;  /**< RO - Integration mode enable.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled. When IME == 1, the device reverts to
                                                                     an integration mode to enable integration testing or topology
                                                                     detection. The integration mode behavior is implementation
                                                                     defined. */
#else
		uint32_t ime                         : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_sysctix_ctiitctrl_s     cn88xx; */
	/* struct bdk_sysctix_ctiitctrl_s     cn88xxp1; */
} bdk_sysctix_ctiitctrl_t;

static inline uint64_t BDK_SYSCTIX_CTIITCTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIITCTRL(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810F00ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIITCTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIITCTRL(...) bdk_sysctix_ctiitctrl_t
#define bustype_BDK_SYSCTIX_CTIITCTRL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIITCTRL(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIITCTRL(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIITCTRL(...) "SYSCTIX_CTIITCTRL"


/**
 * DAB32b - syscti#_ctilar
 *
 * Allows or disallows access to the SYSCTI registers through a memory-mapped
 * interface.
 */
typedef union bdk_sysctix_ctilar {
	uint32_t u;
	struct bdk_sysctix_ctilar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t key                         : 32; /**< WO - Lock access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface. */
#else
		uint32_t key                         : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctilar_s        cn88xx; */
	/* struct bdk_sysctix_ctilar_s        cn88xxp1; */
} bdk_sysctix_ctilar_t;

static inline uint64_t BDK_SYSCTIX_CTILAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTILAR(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FB0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTILAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTILAR(...) bdk_sysctix_ctilar_t
#define bustype_BDK_SYSCTIX_CTILAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTILAR(p1) (p1)
#define arguments_BDK_SYSCTIX_CTILAR(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTILAR(...) "SYSCTIX_CTILAR"


/**
 * DAB32b - syscti#_ctilsr
 *
 * Indicates the current status of the software lock for registers.
 *
 */
typedef union bdk_sysctix_ctilsr {
	uint32_t u;
	struct bdk_sysctix_ctilsr_s {
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
                                                                     accesses, the value of this field is IMPLEMENTATION DEFINED.
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
	/* struct bdk_sysctix_ctilsr_s        cn88xx; */
	/* struct bdk_sysctix_ctilsr_s        cn88xxp1; */
} bdk_sysctix_ctilsr_t;

static inline uint64_t BDK_SYSCTIX_CTILSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTILSR(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FB4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTILSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTILSR(...) bdk_sysctix_ctilsr_t
#define bustype_BDK_SYSCTIX_CTILSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTILSR(p1) (p1)
#define arguments_BDK_SYSCTIX_CTILSR(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTILSR(...) "SYSCTIX_CTILSR"


/**
 * DAB32b - syscti#_ctiouten#
 *
 * Defines which input channels generate output trigger n.
 *
 */
typedef union bdk_sysctix_ctioutenx {
	uint32_t u;
	struct bdk_sysctix_ctioutenx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t outen                       : 3;  /**< R/W - Input channel \<x\> to output trigger \<n\> enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     SYSCTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = An event on input channel \<x\> will not cause output trigger
                                                                     \<n\> to be asserted.
                                                                 1 = An event on input channel \<x\> will cause output trigger \<n\> to
                                                                     be asserted.

                                                                 In CNXXXX SYSCTIOUTEN(3..31) are ignored as there are only 3 channels. */
#else
		uint32_t outen                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctioutenx_s     cn88xx; */
	/* struct bdk_sysctix_ctioutenx_s     cn88xxp1; */
} bdk_sysctix_ctioutenx_t;

static inline uint64_t BDK_SYSCTIX_CTIOUTENX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIOUTENX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 6)) && ((param2 <= 2)))
		return 0x000087A00F8100A0ull + (param1 & 7) * 0x80000ull + (param2 & 3) * 0x4ull;
	csr_fatal("BDK_SYSCTIX_CTIOUTENX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIOUTENX(...) bdk_sysctix_ctioutenx_t
#define bustype_BDK_SYSCTIX_CTIOUTENX(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIOUTENX(p1,p2) (p1)
#define arguments_BDK_SYSCTIX_CTIOUTENX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SYSCTIX_CTIOUTENX(...) "SYSCTIX_CTIOUTENX"


/**
 * DAB32b - syscti#_ctipidr0
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_ctipidr0 {
	uint32_t u;
	struct bdk_sysctix_ctipidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t part_0                      : 8;  /**< RO - Part number \<7:0\>.  Indicates PCC_PIDR_PARTNUM0_E::SYSCTI. */
#else
		uint32_t part_0                      : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr0_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr0_s      cn88xxp1; */
} bdk_sysctix_ctipidr0_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR0(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FE0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR0(...) bdk_sysctix_ctipidr0_t
#define bustype_BDK_SYSCTIX_CTIPIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR0(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR0(...) "SYSCTIX_CTIPIDR0"


/**
 * DAB32b - syscti#_ctipidr1
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_ctipidr1 {
	uint32_t u;
	struct bdk_sysctix_ctipidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t des_0                       : 4;  /**< RO - JEP106 identification code \<3:0\>. Cavium code is 0x4C. */
		uint32_t part_1                      : 4;  /**< RO - Part number \<11:8\>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t part_1                      : 4;
		uint32_t des_0                       : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr1_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr1_s      cn88xxp1; */
} bdk_sysctix_ctipidr1_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR1(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FE4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR1(...) bdk_sysctix_ctipidr1_t
#define bustype_BDK_SYSCTIX_CTIPIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR1(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR1(...) "SYSCTIX_CTIPIDR1"


/**
 * DAB32b - syscti#_ctipidr2
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_ctipidr2 {
	uint32_t u;
	struct bdk_sysctix_ctipidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t des_1                       : 3;  /**< RO - JEP106 identification code \<6:4\>. Cavium code is 0x4C. */
#else
		uint32_t des_1                       : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr2_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr2_s      cn88xxp1; */
} bdk_sysctix_ctipidr2_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR2(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FE8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR2(...) bdk_sysctix_ctipidr2_t
#define bustype_BDK_SYSCTIX_CTIPIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR2(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR2(...) "SYSCTIX_CTIPIDR2"


/**
 * DAB32b - syscti#_ctipidr3
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_ctipidr3 {
	uint32_t u;
	struct bdk_sysctix_ctipidr3_s {
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
	/* struct bdk_sysctix_ctipidr3_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr3_s      cn88xxp1; */
} bdk_sysctix_ctipidr3_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR3(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FECull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR3(...) bdk_sysctix_ctipidr3_t
#define bustype_BDK_SYSCTIX_CTIPIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR3(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR3(...) "SYSCTIX_CTIPIDR3"


/**
 * DAB32b - syscti#_ctipidr4
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_sysctix_ctipidr4 {
	uint32_t u;
	struct bdk_sysctix_ctipidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t size                        : 4;  /**< RO - Size of the component. RAZ. Log\<sub\>2\</sub\> of the number of 4KB pages from the
                                                                 start of the component to the end of the component ID registers. */
		uint32_t des_2                       : 4;  /**< RO - JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else
		uint32_t des_2                       : 4;
		uint32_t size                        : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr4_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr4_s      cn88xxp1; */
} bdk_sysctix_ctipidr4_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR4(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FD0ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR4(...) bdk_sysctix_ctipidr4_t
#define bustype_BDK_SYSCTIX_CTIPIDR4(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR4(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR4(...) "SYSCTIX_CTIPIDR4"


/**
 * DAB32b - syscti#_ctipidr5
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_sysctix_ctipidr5 {
	uint32_t u;
	struct bdk_sysctix_ctipidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr5_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr5_s      cn88xxp1; */
} bdk_sysctix_ctipidr5_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR5(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FD4ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR5(...) bdk_sysctix_ctipidr5_t
#define bustype_BDK_SYSCTIX_CTIPIDR5(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR5(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR5(...) "SYSCTIX_CTIPIDR5"


/**
 * DAB32b - syscti#_ctipidr6
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_sysctix_ctipidr6 {
	uint32_t u;
	struct bdk_sysctix_ctipidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr6_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr6_s      cn88xxp1; */
} bdk_sysctix_ctipidr6_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR6(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FD8ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR6(...) bdk_sysctix_ctipidr6_t
#define bustype_BDK_SYSCTIX_CTIPIDR6(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR6(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR6(...) "SYSCTIX_CTIPIDR6"


/**
 * DAB32b - syscti#_ctipidr7
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_sysctix_ctipidr7 {
	uint32_t u;
	struct bdk_sysctix_ctipidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_sysctix_ctipidr7_s      cn88xx; */
	/* struct bdk_sysctix_ctipidr7_s      cn88xxp1; */
} bdk_sysctix_ctipidr7_t;

static inline uint64_t BDK_SYSCTIX_CTIPIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTIPIDR7(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810FDCull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTIPIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTIPIDR7(...) bdk_sysctix_ctipidr7_t
#define bustype_BDK_SYSCTIX_CTIPIDR7(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTIPIDR7(p1) (p1)
#define arguments_BDK_SYSCTIX_CTIPIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTIPIDR7(...) "SYSCTIX_CTIPIDR7"


/**
 * DAB32b - syscti#_ctitriginstatus
 *
 * Provides the status of the trigger inputs.
 *
 */
typedef union bdk_sysctix_ctitriginstatus {
	uint32_t u;
	struct bdk_sysctix_ctitriginstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t trin                        : 3;  /**< RO - Trigger input \<n\> status.
                                                                 N is the number of triggers implemented as defined by the
                                                                     SYSCTIDEVID.NUMTRIG field.
                                                                 Bits [31:N] are RAZ.

                                                                 Not implemented and not-connected input triggers are always inactive.
                                                                 0 = Input trigger n is inactive.
                                                                 1 = Input trigger n is active. */
#else
		uint32_t trin                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctitriginstatus_s cn88xx; */
	/* struct bdk_sysctix_ctitriginstatus_s cn88xxp1; */
} bdk_sysctix_ctitriginstatus_t;

static inline uint64_t BDK_SYSCTIX_CTITRIGINSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTITRIGINSTATUS(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810130ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTITRIGINSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTITRIGINSTATUS(...) bdk_sysctix_ctitriginstatus_t
#define bustype_BDK_SYSCTIX_CTITRIGINSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTITRIGINSTATUS(p1) (p1)
#define arguments_BDK_SYSCTIX_CTITRIGINSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTITRIGINSTATUS(...) "SYSCTIX_CTITRIGINSTATUS"


/**
 * DAB32b - syscti#_ctitrigoutstatus
 *
 * Provides the status of the trigger outputs.
 *
 */
typedef union bdk_sysctix_ctitrigoutstatus {
	uint32_t u;
	struct bdk_sysctix_ctitrigoutstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t trout                       : 3;  /**< RO - Trigger output \<n\> status.
                                                                 N is the number of triggers implemented as defined by the
                                                                     SYSCTIDEVID.NUMTRIG field.
                                                                 Bits [31:N] are RAZ.

                                                                 If output trigger \<n\> is implemented and connected, possible
                                                                     values of this bit are:
                                                                 Otherwise it is IMPLEMENTATION DEFINED whether TROUT\<n\> is RAZ
                                                                     or behaves as above.
                                                                 0 = Output trigger n is inactive.
                                                                 1 = Output trigger n is active. */
#else
		uint32_t trout                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_sysctix_ctitrigoutstatus_s cn88xx; */
	/* struct bdk_sysctix_ctitrigoutstatus_s cn88xxp1; */
} bdk_sysctix_ctitrigoutstatus_t;

static inline uint64_t BDK_SYSCTIX_CTITRIGOUTSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SYSCTIX_CTITRIGOUTSTATUS(unsigned long param1)
{
	if (((param1 <= 6)))
		return 0x000087A00F810134ull + (param1 & 7) * 0x80000ull;
	csr_fatal("BDK_SYSCTIX_CTITRIGOUTSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SYSCTIX_CTITRIGOUTSTATUS(...) bdk_sysctix_ctitrigoutstatus_t
#define bustype_BDK_SYSCTIX_CTITRIGOUTSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_SYSCTIX_CTITRIGOUTSTATUS(p1) (p1)
#define arguments_BDK_SYSCTIX_CTITRIGOUTSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SYSCTIX_CTITRIGOUTSTATUS(...) "SYSCTIX_CTITRIGOUTSTATUS"

#endif /* __BDK_CSRS_DAB_SYSCTI__ */
