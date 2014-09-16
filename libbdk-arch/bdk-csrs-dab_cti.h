#ifndef __BDK_CSRS_DAB_CTI__
#define __BDK_CSRS_DAB_CTI__
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
 * Cavium DAB_CTI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * DAB32b - cti#_asicctl
 *
 * Provides a control for external multiplexing of additional triggers.
 *
 */
typedef union bdk_ctix_asicctl {
	uint32_t u;
	struct bdk_ctix_asicctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t asicctl                     : 3;  /**< R/W - Implementation defined ASIC control. Provides a control for
                                                                 external multiplexing of additional triggers.
                                                                 If external multiplexing of trigger signals is implemented
                                                                     then the number of multiplexed signals on each trigger must be
                                                                     reflected in CTIDEVID.EXTMUXNUM.
                                                                 If CTIDEVID.EXTMUXNUM is zero, this field is RAZ. */
#else
		uint32_t asicctl                     : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_asicctl_s          cn85xx; */
	/* struct bdk_ctix_asicctl_s          cn88xx; */
	/* struct bdk_ctix_asicctl_s          cn88xxp1; */
} bdk_ctix_asicctl_t;

static inline uint64_t BDK_CTIX_ASICCTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_ASICCTL(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010144ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_ASICCTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_ASICCTL(...) bdk_ctix_asicctl_t
#define bustype_BDK_CTIX_ASICCTL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_ASICCTL(p1) (p1)
#define arguments_BDK_CTIX_ASICCTL(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_ASICCTL(...) "CTIX_ASICCTL"


/**
 * DAB32b - cti#_claimclr_el1
 *
 * Used by software to read the values of the CLAIM bits, and to
 * clear these bits to 0.
 */
typedef union bdk_ctix_claimclr_el1 {
	uint32_t u;
	struct bdk_ctix_claimclr_el1_s {
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
	/* struct bdk_ctix_claimclr_el1_s     cn85xx; */
	/* struct bdk_ctix_claimclr_el1_s     cn88xx; */
	/* struct bdk_ctix_claimclr_el1_s     cn88xxp1; */
} bdk_ctix_claimclr_el1_t;

static inline uint64_t BDK_CTIX_CLAIMCLR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CLAIMCLR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FA4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CLAIMCLR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CLAIMCLR_EL1(...) bdk_ctix_claimclr_el1_t
#define bustype_BDK_CTIX_CLAIMCLR_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CLAIMCLR_EL1(p1) (p1)
#define arguments_BDK_CTIX_CLAIMCLR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CLAIMCLR_EL1(...) "CTIX_CLAIMCLR_EL1"


/**
 * DAB32b - cti#_claimset_el1
 *
 * Used by software to set CLAIM bits to 1.
 *
 */
typedef union bdk_ctix_claimset_el1 {
	uint32_t u;
	struct bdk_ctix_claimset_el1_s {
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
	/* struct bdk_ctix_claimset_el1_s     cn85xx; */
	/* struct bdk_ctix_claimset_el1_s     cn88xx; */
	/* struct bdk_ctix_claimset_el1_s     cn88xxp1; */
} bdk_ctix_claimset_el1_t;

static inline uint64_t BDK_CTIX_CLAIMSET_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CLAIMSET_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FA0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CLAIMSET_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CLAIMSET_EL1(...) bdk_ctix_claimset_el1_t
#define bustype_BDK_CTIX_CLAIMSET_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CLAIMSET_EL1(p1) (p1)
#define arguments_BDK_CTIX_CLAIMSET_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CLAIMSET_EL1(...) "CTIX_CLAIMSET_EL1"


/**
 * DAB32b - cti#_ctiappclear
 *
 * Clears bits of the Application Trigger register.
 *
 */
typedef union bdk_ctix_ctiappclear {
	uint32_t u;
	struct bdk_ctix_ctiappclear_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctiappclear_s      cn85xx; */
	/* struct bdk_ctix_ctiappclear_s      cn88xx; */
	/* struct bdk_ctix_ctiappclear_s      cn88xxp1; */
} bdk_ctix_ctiappclear_t;

static inline uint64_t BDK_CTIX_CTIAPPCLEAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIAPPCLEAR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010018ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIAPPCLEAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIAPPCLEAR(...) bdk_ctix_ctiappclear_t
#define bustype_BDK_CTIX_CTIAPPCLEAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIAPPCLEAR(p1) (p1)
#define arguments_BDK_CTIX_CTIAPPCLEAR(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIAPPCLEAR(...) "CTIX_CTIAPPCLEAR"


/**
 * DAB32b - cti#_ctiapppulse
 *
 * Causes event pulses to be generated on ECT channels.
 *
 */
typedef union bdk_ctix_ctiapppulse {
	uint32_t u;
	struct bdk_ctix_ctiapppulse_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t apppulse                    : 3;  /**< WO - Generate event pulse on ECT channel \<x\>.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     CTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 Writing to this bit has the following effect:
                                                                 0 = No effect.
                                                                 1 = Channel \<x\> event pulse generated for one clock period. */
#else
		uint32_t apppulse                    : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctiapppulse_s      cn85xx; */
	/* struct bdk_ctix_ctiapppulse_s      cn88xx; */
	/* struct bdk_ctix_ctiapppulse_s      cn88xxp1; */
} bdk_ctix_ctiapppulse_t;

static inline uint64_t BDK_CTIX_CTIAPPPULSE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIAPPPULSE(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A00801001Cull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIAPPPULSE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIAPPPULSE(...) bdk_ctix_ctiapppulse_t
#define bustype_BDK_CTIX_CTIAPPPULSE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIAPPPULSE(p1) (p1)
#define arguments_BDK_CTIX_CTIAPPPULSE(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIAPPPULSE(...) "CTIX_CTIAPPPULSE"


/**
 * DAB32b - cti#_ctiappset
 *
 * Sets bits of the Application Trigger register.
 *
 */
typedef union bdk_ctix_ctiappset {
	uint32_t u;
	struct bdk_ctix_ctiappset_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctiappset_s        cn85xx; */
	/* struct bdk_ctix_ctiappset_s        cn88xx; */
	/* struct bdk_ctix_ctiappset_s        cn88xxp1; */
} bdk_ctix_ctiappset_t;

static inline uint64_t BDK_CTIX_CTIAPPSET(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIAPPSET(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010014ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIAPPSET", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIAPPSET(...) bdk_ctix_ctiappset_t
#define bustype_BDK_CTIX_CTIAPPSET(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIAPPSET(p1) (p1)
#define arguments_BDK_CTIX_CTIAPPSET(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIAPPSET(...) "CTIX_CTIAPPSET"


/**
 * DAB32b - cti#_ctiauthstatus
 *
 * Provides information about the state of the implementation defined authentication
 * interface.
 */
typedef union bdk_ctix_ctiauthstatus {
	uint32_t u;
	struct bdk_ctix_ctiauthstatus_s {
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
	/* struct bdk_ctix_ctiauthstatus_s    cn85xx; */
	/* struct bdk_ctix_ctiauthstatus_s    cn88xx; */
	/* struct bdk_ctix_ctiauthstatus_s    cn88xxp1; */
} bdk_ctix_ctiauthstatus_t;

static inline uint64_t BDK_CTIX_CTIAUTHSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIAUTHSTATUS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FB8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIAUTHSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIAUTHSTATUS(...) bdk_ctix_ctiauthstatus_t
#define bustype_BDK_CTIX_CTIAUTHSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIAUTHSTATUS(p1) (p1)
#define arguments_BDK_CTIX_CTIAUTHSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIAUTHSTATUS(...) "CTIX_CTIAUTHSTATUS"


/**
 * DAB32b - cti#_ctichinstatus
 *
 * Provides the raw status of the ECT channel inputs.
 *
 */
typedef union bdk_ctix_ctichinstatus {
	uint32_t u;
	struct bdk_ctix_ctichinstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t chin                        : 3;  /**< RO - Input channel \<n\> status.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     CTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ.

                                                                 0 = Input channel \<n\> is inactive.
                                                                 1 = Input channel \<n\> is active. */
#else
		uint32_t chin                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctichinstatus_s    cn85xx; */
	/* struct bdk_ctix_ctichinstatus_s    cn88xx; */
	/* struct bdk_ctix_ctichinstatus_s    cn88xxp1; */
} bdk_ctix_ctichinstatus_t;

static inline uint64_t BDK_CTIX_CTICHINSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICHINSTATUS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010138ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICHINSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICHINSTATUS(...) bdk_ctix_ctichinstatus_t
#define bustype_BDK_CTIX_CTICHINSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICHINSTATUS(p1) (p1)
#define arguments_BDK_CTIX_CTICHINSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICHINSTATUS(...) "CTIX_CTICHINSTATUS"


/**
 * DAB32b - cti#_ctichoutstatus
 *
 * Provides the status of the ECT channel outputs.
 *
 */
typedef union bdk_ctix_ctichoutstatus {
	uint32_t u;
	struct bdk_ctix_ctichoutstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t chout                       : 3;  /**< RO - Output channel \<n\> status.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     CTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ.

                                                                 0 = Output channel \<n\> is inactive.
                                                                 1 = Output channel \<n\> is active. */
#else
		uint32_t chout                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctichoutstatus_s   cn85xx; */
	/* struct bdk_ctix_ctichoutstatus_s   cn88xx; */
	/* struct bdk_ctix_ctichoutstatus_s   cn88xxp1; */
} bdk_ctix_ctichoutstatus_t;

static inline uint64_t BDK_CTIX_CTICHOUTSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICHOUTSTATUS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A00801013Cull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICHOUTSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICHOUTSTATUS(...) bdk_ctix_ctichoutstatus_t
#define bustype_BDK_CTIX_CTICHOUTSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICHOUTSTATUS(p1) (p1)
#define arguments_BDK_CTIX_CTICHOUTSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICHOUTSTATUS(...) "CTIX_CTICHOUTSTATUS"


/**
 * DAB32b - cti#_cticidr0
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_cticidr0 {
	uint32_t u;
	struct bdk_ctix_cticidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_0                     : 8;  /**< RO - Preamble. Must read as 0x0D. */
#else
		uint32_t prmbl_0                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ctix_cticidr0_s         cn85xx; */
	/* struct bdk_ctix_cticidr0_s         cn88xx; */
	/* struct bdk_ctix_cticidr0_s         cn88xxp1; */
} bdk_ctix_cticidr0_t;

static inline uint64_t BDK_CTIX_CTICIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICIDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FF0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICIDR0(...) bdk_ctix_cticidr0_t
#define bustype_BDK_CTIX_CTICIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICIDR0(p1) (p1)
#define arguments_BDK_CTIX_CTICIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICIDR0(...) "CTIX_CTICIDR0"


/**
 * DAB32b - cti#_cticidr1
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_cticidr1 {
	uint32_t u;
	struct bdk_ctix_cticidr1_s {
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
	/* struct bdk_ctix_cticidr1_s         cn85xx; */
	/* struct bdk_ctix_cticidr1_s         cn88xx; */
	/* struct bdk_ctix_cticidr1_s         cn88xxp1; */
} bdk_ctix_cticidr1_t;

static inline uint64_t BDK_CTIX_CTICIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICIDR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FF4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICIDR1(...) bdk_ctix_cticidr1_t
#define bustype_BDK_CTIX_CTICIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICIDR1(p1) (p1)
#define arguments_BDK_CTIX_CTICIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICIDR1(...) "CTIX_CTICIDR1"


/**
 * DAB32b - cti#_cticidr2
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_cticidr2 {
	uint32_t u;
	struct bdk_ctix_cticidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_2                     : 8;  /**< RO - Preamble. Must read as 0x05. */
#else
		uint32_t prmbl_2                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ctix_cticidr2_s         cn85xx; */
	/* struct bdk_ctix_cticidr2_s         cn88xx; */
	/* struct bdk_ctix_cticidr2_s         cn88xxp1; */
} bdk_ctix_cticidr2_t;

static inline uint64_t BDK_CTIX_CTICIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICIDR2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FF8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICIDR2(...) bdk_ctix_cticidr2_t
#define bustype_BDK_CTIX_CTICIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICIDR2(p1) (p1)
#define arguments_BDK_CTIX_CTICIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICIDR2(...) "CTIX_CTICIDR2"


/**
 * DAB32b - cti#_cticidr3
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_cticidr3 {
	uint32_t u;
	struct bdk_ctix_cticidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_3                     : 8;  /**< RO - Preamble. Must read as 0xB1. */
#else
		uint32_t prmbl_3                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ctix_cticidr3_s         cn85xx; */
	/* struct bdk_ctix_cticidr3_s         cn88xx; */
	/* struct bdk_ctix_cticidr3_s         cn88xxp1; */
} bdk_ctix_cticidr3_t;

static inline uint64_t BDK_CTIX_CTICIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICIDR3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FFCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICIDR3(...) bdk_ctix_cticidr3_t
#define bustype_BDK_CTIX_CTICIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICIDR3(p1) (p1)
#define arguments_BDK_CTIX_CTICIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICIDR3(...) "CTIX_CTICIDR3"


/**
 * DAB32b - cti#_cticontrol
 *
 * Controls whether the CTI is enabled.
 *
 */
typedef union bdk_ctix_cticontrol {
	uint32_t u;
	struct bdk_ctix_cticontrol_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t glben                       : 1;  /**< R/W - Enables or disables the CTI mapping functions.
                                                                 When the mapping functions are disabled, no new events are
                                                                     signaled on either output triggers or output channels. If a
                                                                     previously asserted output trigger has not been acknowledged,
                                                                     it remains asserted after the mapping functions are disabled.
                                                                     All output triggers are disabled by CTI reset.

                                                                 0 = CTI mapping functions disabled.
                                                                 1 = CTI mapping functions enabled. */
#else
		uint32_t glben                       : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_ctix_cticontrol_s       cn85xx; */
	/* struct bdk_ctix_cticontrol_s       cn88xx; */
	/* struct bdk_ctix_cticontrol_s       cn88xxp1; */
} bdk_ctix_cticontrol_t;

static inline uint64_t BDK_CTIX_CTICONTROL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTICONTROL(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010000ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTICONTROL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTICONTROL(...) bdk_ctix_cticontrol_t
#define bustype_BDK_CTIX_CTICONTROL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTICONTROL(p1) (p1)
#define arguments_BDK_CTIX_CTICONTROL(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTICONTROL(...) "CTIX_CTICONTROL"


/**
 * DAB32b - cti#_ctidevaff0
 *
 * Copy of the low half of the processor MPIDR_EL1 register that
 * allows a debugger to determine which processor in a
 * multiprocessor system the CTI component relates to.
 */
typedef union bdk_ctix_ctidevaff0 {
	uint32_t u;
	struct bdk_ctix_ctidevaff0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< RO - MPIDR_EL1 low half. Read-only copy of the low half of MPIDR_EL1, as seen from
                                                                 the highest implemented exception level. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ctix_ctidevaff0_s       cn85xx; */
	/* struct bdk_ctix_ctidevaff0_s       cn88xx; */
	/* struct bdk_ctix_ctidevaff0_s       cn88xxp1; */
} bdk_ctix_ctidevaff0_t;

static inline uint64_t BDK_CTIX_CTIDEVAFF0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVAFF0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FA8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVAFF0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVAFF0(...) bdk_ctix_ctidevaff0_t
#define bustype_BDK_CTIX_CTIDEVAFF0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVAFF0(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVAFF0(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVAFF0(...) "CTIX_CTIDEVAFF0"


/**
 * DAB32b - cti#_ctidevaff1
 *
 * Copy of the high half of the processor MPIDR_EL1 register that
 * allows a debugger to determine which processor in a
 * multiprocessor system the CTI component relates to.
 */
typedef union bdk_ctix_ctidevaff1 {
	uint32_t u;
	struct bdk_ctix_ctidevaff1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< RO - MPIDR_EL1 high half. Read-only copy of the high half of MPIDR_EL1, as seen from
                                                                 the highest implemented exception level. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_ctix_ctidevaff1_s       cn85xx; */
	/* struct bdk_ctix_ctidevaff1_s       cn88xx; */
	/* struct bdk_ctix_ctidevaff1_s       cn88xxp1; */
} bdk_ctix_ctidevaff1_t;

static inline uint64_t BDK_CTIX_CTIDEVAFF1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVAFF1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FACull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVAFF1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVAFF1(...) bdk_ctix_ctidevaff1_t
#define bustype_BDK_CTIX_CTIDEVAFF1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVAFF1(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVAFF1(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVAFF1(...) "CTIX_CTIDEVAFF1"


/**
 * DAB32b - cti#_ctidevarch
 *
 * Identifies the programmers' model architecture.
 *
 */
typedef union bdk_ctix_ctidevarch {
	uint32_t u;
	struct bdk_ctix_ctidevarch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t architect                   : 11; /**< RO - Defines the architecture of the component. This is ARM Limited.

                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.

                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
		uint32_t present                     : 1;  /**< RO - When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
		uint32_t revision                    : 4;  /**< RO - Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For CTI, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
		uint32_t archid                      : 16; /**< RO - Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For CTI:
                                                                  Bits [15:12] are the architecture version, 0x1.
                                                                  Bits [11:0] are the architecture part number, 0xA14.
                                                                 This corresponds to CTI architecture version CTIv2. */
#else
		uint32_t archid                      : 16;
		uint32_t revision                    : 4;
		uint32_t present                     : 1;
		uint32_t architect                   : 11;
#endif
	} s;
	/* struct bdk_ctix_ctidevarch_s       cn85xx; */
	/* struct bdk_ctix_ctidevarch_s       cn88xx; */
	/* struct bdk_ctix_ctidevarch_s       cn88xxp1; */
} bdk_ctix_ctidevarch_t;

static inline uint64_t BDK_CTIX_CTIDEVARCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVARCH(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FBCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVARCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVARCH(...) bdk_ctix_ctidevarch_t
#define bustype_BDK_CTIX_CTIDEVARCH(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVARCH(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVARCH(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVARCH(...) "CTIX_CTIDEVARCH"


/**
 * DAB32b - cti#_ctidevid
 *
 * Describes the component to the debugger.
 *
 */
typedef union bdk_ctix_ctidevid {
	uint32_t u;
	struct bdk_ctix_ctidevid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t inout_gate                  : 2;  /**< RO - Input/output options. Indicates presence of the input gate. If
                                                                     the CTM is not implemented, this field is RAZ.
                                                                 All other values are reserved.
                                                                 0x0 = CTIGATE does not mask propagation of input events from
                                                                     external channels.
                                                                 0x1 = CTIGATE masks propagation of input events from external
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
                                                                 into the CTI. This relates only to additional external
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
	/* struct bdk_ctix_ctidevid_s         cn85xx; */
	/* struct bdk_ctix_ctidevid_s         cn88xx; */
	/* struct bdk_ctix_ctidevid_s         cn88xxp1; */
} bdk_ctix_ctidevid_t;

static inline uint64_t BDK_CTIX_CTIDEVID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVID(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FC8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVID(...) bdk_ctix_ctidevid_t
#define bustype_BDK_CTIX_CTIDEVID(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVID(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVID(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVID(...) "CTIX_CTIDEVID"


/**
 * DAB32b - cti#_ctidevid1
 *
 * Reserved for future information about the component to the debugger.
 *
 */
typedef union bdk_ctix_ctidevid1 {
	uint32_t u;
	struct bdk_ctix_ctidevid1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctidevid1_s        cn85xx; */
	/* struct bdk_ctix_ctidevid1_s        cn88xx; */
	/* struct bdk_ctix_ctidevid1_s        cn88xxp1; */
} bdk_ctix_ctidevid1_t;

static inline uint64_t BDK_CTIX_CTIDEVID1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVID1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FC4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVID1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVID1(...) bdk_ctix_ctidevid1_t
#define bustype_BDK_CTIX_CTIDEVID1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVID1(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVID1(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVID1(...) "CTIX_CTIDEVID1"


/**
 * DAB32b - cti#_ctidevid2
 *
 * Reserved for future information about the CTI component to the
 * debugger.
 */
typedef union bdk_ctix_ctidevid2 {
	uint32_t u;
	struct bdk_ctix_ctidevid2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctidevid2_s        cn85xx; */
	/* struct bdk_ctix_ctidevid2_s        cn88xx; */
	/* struct bdk_ctix_ctidevid2_s        cn88xxp1; */
} bdk_ctix_ctidevid2_t;

static inline uint64_t BDK_CTIX_CTIDEVID2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVID2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FC0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVID2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVID2(...) bdk_ctix_ctidevid2_t
#define bustype_BDK_CTIX_CTIDEVID2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVID2(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVID2(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVID2(...) "CTIX_CTIDEVID2"


/**
 * DAB32b - cti#_ctidevtype
 *
 * Indicates to a debugger that this component is part of a processor's cross-trigger
 * interface.
 */
typedef union bdk_ctix_ctidevtype {
	uint32_t u;
	struct bdk_ctix_ctidevtype_s {
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
	/* struct bdk_ctix_ctidevtype_s       cn85xx; */
	/* struct bdk_ctix_ctidevtype_s       cn88xx; */
	/* struct bdk_ctix_ctidevtype_s       cn88xxp1; */
} bdk_ctix_ctidevtype_t;

static inline uint64_t BDK_CTIX_CTIDEVTYPE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIDEVTYPE(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FCCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIDEVTYPE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIDEVTYPE(...) bdk_ctix_ctidevtype_t
#define bustype_BDK_CTIX_CTIDEVTYPE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIDEVTYPE(p1) (p1)
#define arguments_BDK_CTIX_CTIDEVTYPE(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIDEVTYPE(...) "CTIX_CTIDEVTYPE"


/**
 * DAB32b - cti#_ctigate
 *
 * Determines whether events on channels propagate through the
 * CTM to other ECT components, or from the CTM into the CTI.
 */
typedef union bdk_ctix_ctigate {
	uint32_t u;
	struct bdk_ctix_ctigate_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t gate                        : 3;  /**< R/W - Channel \<x\> gate enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     CTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = Disable output and, if CTIDEVID[INOUT] = 0x1.
                                                                 1 = Enable output and, if CTIDEVID[INOUT] = 0x1. */
#else
		uint32_t gate                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctigate_s          cn85xx; */
	/* struct bdk_ctix_ctigate_s          cn88xx; */
	/* struct bdk_ctix_ctigate_s          cn88xxp1; */
} bdk_ctix_ctigate_t;

static inline uint64_t BDK_CTIX_CTIGATE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIGATE(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010140ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIGATE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIGATE(...) bdk_ctix_ctigate_t
#define bustype_BDK_CTIX_CTIGATE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIGATE(p1) (p1)
#define arguments_BDK_CTIX_CTIGATE(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIGATE(...) "CTIX_CTIGATE"


/**
 * DAB32b - cti#_ctiinen#
 *
 * Enables the signaling of an event on output channels when
 * input trigger event n is received by the CTI.
 */
typedef union bdk_ctix_ctiinenx {
	uint32_t u;
	struct bdk_ctix_ctiinenx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t inen                        : 3;  /**< R/W - Input trigger \<n\> to output channel \<x\> enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     CTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = Input trigger \<n\> will not generate an event on output channel
                                                                     \<x\>.
                                                                 1 = Input trigger \<n\> will generate an event on output channel
                                                                     \<x\>.

                                                                 In CNXXXX CTIINEN(3..31) are ignored as there are only 3 channels. */
#else
		uint32_t inen                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctiinenx_s         cn85xx; */
	/* struct bdk_ctix_ctiinenx_s         cn88xx; */
	/* struct bdk_ctix_ctiinenx_s         cn88xxp1; */
} bdk_ctix_ctiinenx_t;

static inline uint64_t BDK_CTIX_CTIINENX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIINENX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 2)))
		return 0x000087A008010020ull + (param1 & 63) * 0x80000ull + (param2 & 3) * 0x4ull;
	csr_fatal("BDK_CTIX_CTIINENX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIINENX(...) bdk_ctix_ctiinenx_t
#define bustype_BDK_CTIX_CTIINENX(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIINENX(p1,p2) (p1)
#define arguments_BDK_CTIX_CTIINENX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_CTIX_CTIINENX(...) "CTIX_CTIINENX"


/**
 * DAB32b - cti#_ctiintack
 *
 * Creates soft acknowledges for output triggers.
 *
 */
typedef union bdk_ctix_ctiintack {
	uint32_t u;
	struct bdk_ctix_ctiintack_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ack                         : 3;  /**< RO - Acknowledge for output trigger \<n\>.
                                                                 N is the number of CTI triggers implemented as defined by the
                                                                     CTIDEVID.NUMTRIG field. Bits [31:N] are RAZ/WI.

                                                                 If any of the following is true, writes to ACK\<n\> are ignored:
                                                                 * n \>= CTIDEVID.NUMTRIG, the number of implemented triggers.
                                                                 * Output trigger n is not active
                                                                 * The channel mapping function output, as controlled by
                                                                     CTIOUTEN\<n\>, is still active.

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
	/* struct bdk_ctix_ctiintack_s        cn85xx; */
	/* struct bdk_ctix_ctiintack_s        cn88xx; */
	/* struct bdk_ctix_ctiintack_s        cn88xxp1; */
} bdk_ctix_ctiintack_t;

static inline uint64_t BDK_CTIX_CTIINTACK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIINTACK(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010010ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIINTACK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIINTACK(...) bdk_ctix_ctiintack_t
#define bustype_BDK_CTIX_CTIINTACK(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIINTACK(p1) (p1)
#define arguments_BDK_CTIX_CTIINTACK(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIINTACK(...) "CTIX_CTIINTACK"


/**
 * DAB32b - cti#_ctiitctrl
 *
 * Enables the CTI to switch from its default mode into
 * integration mode, where test software can control directly the
 * inputs and outputs of the processor, for integration testing
 * or topology detection.
 */
typedef union bdk_ctix_ctiitctrl {
	uint32_t u;
	struct bdk_ctix_ctiitctrl_s {
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
	/* struct bdk_ctix_ctiitctrl_s        cn85xx; */
	/* struct bdk_ctix_ctiitctrl_s        cn88xx; */
	/* struct bdk_ctix_ctiitctrl_s        cn88xxp1; */
} bdk_ctix_ctiitctrl_t;

static inline uint64_t BDK_CTIX_CTIITCTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIITCTRL(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010F00ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIITCTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIITCTRL(...) bdk_ctix_ctiitctrl_t
#define bustype_BDK_CTIX_CTIITCTRL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIITCTRL(p1) (p1)
#define arguments_BDK_CTIX_CTIITCTRL(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIITCTRL(...) "CTIX_CTIITCTRL"


/**
 * DAB32b - cti#_ctilar
 *
 * Allows or disallows access to the CTI registers through a
 * memory-mapped interface.
 */
typedef union bdk_ctix_ctilar {
	uint32_t u;
	struct bdk_ctix_ctilar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t key                         : 32; /**< WO - Lock access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface. */
#else
		uint32_t key                         : 32;
#endif
	} s;
	/* struct bdk_ctix_ctilar_s           cn85xx; */
	/* struct bdk_ctix_ctilar_s           cn88xx; */
	/* struct bdk_ctix_ctilar_s           cn88xxp1; */
} bdk_ctix_ctilar_t;

static inline uint64_t BDK_CTIX_CTILAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTILAR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FB0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTILAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTILAR(...) bdk_ctix_ctilar_t
#define bustype_BDK_CTIX_CTILAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTILAR(p1) (p1)
#define arguments_BDK_CTIX_CTILAR(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTILAR(...) "CTIX_CTILAR"


/**
 * DAB32b - cti#_ctilsr
 *
 * Indicates the current status of the software lock for CTI
 * registers.
 */
typedef union bdk_ctix_ctilsr {
	uint32_t u;
	struct bdk_ctix_ctilsr_s {
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
	/* struct bdk_ctix_ctilsr_s           cn85xx; */
	/* struct bdk_ctix_ctilsr_s           cn88xx; */
	/* struct bdk_ctix_ctilsr_s           cn88xxp1; */
} bdk_ctix_ctilsr_t;

static inline uint64_t BDK_CTIX_CTILSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTILSR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FB4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTILSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTILSR(...) bdk_ctix_ctilsr_t
#define bustype_BDK_CTIX_CTILSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTILSR(p1) (p1)
#define arguments_BDK_CTIX_CTILSR(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTILSR(...) "CTIX_CTILSR"


/**
 * DAB32b - cti#_ctiouten#
 *
 * Defines which input channels generate output trigger n.
 *
 */
typedef union bdk_ctix_ctioutenx {
	uint32_t u;
	struct bdk_ctix_ctioutenx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t outen                       : 3;  /**< R/W - Input channel \<x\> to output trigger \<n\> enable.
                                                                 N is the number of ECT channels implemented as defined by the
                                                                     CTIDEVID.NUMCHAN field.
                                                                 Bits [31:N] are RAZ/WI.

                                                                 0 = An event on input channel \<x\> will not cause output trigger
                                                                     \<n\> to be asserted.
                                                                 1 = An event on input channel \<x\> will cause output trigger \<n\> to
                                                                     be asserted.

                                                                 In CNXXXX CTIOUTEN(3..31) are ignored as there are only 3 channels. */
#else
		uint32_t outen                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctioutenx_s        cn85xx; */
	/* struct bdk_ctix_ctioutenx_s        cn88xx; */
	/* struct bdk_ctix_ctioutenx_s        cn88xxp1; */
} bdk_ctix_ctioutenx_t;

static inline uint64_t BDK_CTIX_CTIOUTENX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIOUTENX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 2)))
		return 0x000087A0080100A0ull + (param1 & 63) * 0x80000ull + (param2 & 3) * 0x4ull;
	csr_fatal("BDK_CTIX_CTIOUTENX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIOUTENX(...) bdk_ctix_ctioutenx_t
#define bustype_BDK_CTIX_CTIOUTENX(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIOUTENX(p1,p2) (p1)
#define arguments_BDK_CTIX_CTIOUTENX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_CTIX_CTIOUTENX(...) "CTIX_CTIOUTENX"


/**
 * DAB32b - cti#_ctipidr0
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_ctipidr0 {
	uint32_t u;
	struct bdk_ctix_ctipidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t part_0                      : 8;  /**< RO - Part number \<7:0\>.  Indicates PCC_PIDR_PARTNUM0_E::CTI. */
#else
		uint32_t part_0                      : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ctix_ctipidr0_s         cn85xx; */
	/* struct bdk_ctix_ctipidr0_s         cn88xx; */
	/* struct bdk_ctix_ctipidr0_s         cn88xxp1; */
} bdk_ctix_ctipidr0_t;

static inline uint64_t BDK_CTIX_CTIPIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FE0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR0(...) bdk_ctix_ctipidr0_t
#define bustype_BDK_CTIX_CTIPIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR0(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR0(...) "CTIX_CTIPIDR0"


/**
 * DAB32b - cti#_ctipidr1
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_ctipidr1 {
	uint32_t u;
	struct bdk_ctix_ctipidr1_s {
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
	/* struct bdk_ctix_ctipidr1_s         cn85xx; */
	/* struct bdk_ctix_ctipidr1_s         cn88xx; */
	/* struct bdk_ctix_ctipidr1_s         cn88xxp1; */
} bdk_ctix_ctipidr1_t;

static inline uint64_t BDK_CTIX_CTIPIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FE4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR1(...) bdk_ctix_ctipidr1_t
#define bustype_BDK_CTIX_CTIPIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR1(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR1(...) "CTIX_CTIPIDR1"


/**
 * DAB32b - cti#_ctipidr2
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_ctipidr2 {
	uint32_t u;
	struct bdk_ctix_ctipidr2_s {
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
	/* struct bdk_ctix_ctipidr2_s         cn85xx; */
	/* struct bdk_ctix_ctipidr2_s         cn88xx; */
	/* struct bdk_ctix_ctipidr2_s         cn88xxp1; */
} bdk_ctix_ctipidr2_t;

static inline uint64_t BDK_CTIX_CTIPIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FE8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR2(...) bdk_ctix_ctipidr2_t
#define bustype_BDK_CTIX_CTIPIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR2(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR2(...) "CTIX_CTIPIDR2"


/**
 * DAB32b - cti#_ctipidr3
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_ctipidr3 {
	uint32_t u;
	struct bdk_ctix_ctipidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cmod                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cmod                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_ctix_ctipidr3_s         cn85xx; */
	/* struct bdk_ctix_ctipidr3_s         cn88xx; */
	/* struct bdk_ctix_ctipidr3_s         cn88xxp1; */
} bdk_ctix_ctipidr3_t;

static inline uint64_t BDK_CTIX_CTIPIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FECull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR3(...) bdk_ctix_ctipidr3_t
#define bustype_BDK_CTIX_CTIPIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR3(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR3(...) "CTIX_CTIPIDR3"


/**
 * DAB32b - cti#_ctipidr4
 *
 * Provides information to identify a component.
 *
 */
typedef union bdk_ctix_ctipidr4 {
	uint32_t u;
	struct bdk_ctix_ctipidr4_s {
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
	/* struct bdk_ctix_ctipidr4_s         cn85xx; */
	/* struct bdk_ctix_ctipidr4_s         cn88xx; */
	/* struct bdk_ctix_ctipidr4_s         cn88xxp1; */
} bdk_ctix_ctipidr4_t;

static inline uint64_t BDK_CTIX_CTIPIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR4(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FD0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR4(...) bdk_ctix_ctipidr4_t
#define bustype_BDK_CTIX_CTIPIDR4(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR4(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR4(...) "CTIX_CTIPIDR4"


/**
 * DAB32b - cti#_ctipidr5
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_ctix_ctipidr5 {
	uint32_t u;
	struct bdk_ctix_ctipidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctipidr5_s         cn85xx; */
	/* struct bdk_ctix_ctipidr5_s         cn88xx; */
	/* struct bdk_ctix_ctipidr5_s         cn88xxp1; */
} bdk_ctix_ctipidr5_t;

static inline uint64_t BDK_CTIX_CTIPIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR5(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FD4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR5(...) bdk_ctix_ctipidr5_t
#define bustype_BDK_CTIX_CTIPIDR5(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR5(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR5(...) "CTIX_CTIPIDR5"


/**
 * DAB32b - cti#_ctipidr6
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_ctix_ctipidr6 {
	uint32_t u;
	struct bdk_ctix_ctipidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctipidr6_s         cn85xx; */
	/* struct bdk_ctix_ctipidr6_s         cn88xx; */
	/* struct bdk_ctix_ctipidr6_s         cn88xxp1; */
} bdk_ctix_ctipidr6_t;

static inline uint64_t BDK_CTIX_CTIPIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR6(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FD8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR6(...) bdk_ctix_ctipidr6_t
#define bustype_BDK_CTIX_CTIPIDR6(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR6(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR6(...) "CTIX_CTIPIDR6"


/**
 * DAB32b - cti#_ctipidr7
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_ctix_ctipidr7 {
	uint32_t u;
	struct bdk_ctix_ctipidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_ctix_ctipidr7_s         cn85xx; */
	/* struct bdk_ctix_ctipidr7_s         cn88xx; */
	/* struct bdk_ctix_ctipidr7_s         cn88xxp1; */
} bdk_ctix_ctipidr7_t;

static inline uint64_t BDK_CTIX_CTIPIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTIPIDR7(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010FDCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTIPIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTIPIDR7(...) bdk_ctix_ctipidr7_t
#define bustype_BDK_CTIX_CTIPIDR7(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTIPIDR7(p1) (p1)
#define arguments_BDK_CTIX_CTIPIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTIPIDR7(...) "CTIX_CTIPIDR7"


/**
 * DAB32b - cti#_ctitriginstatus
 *
 * Provides the status of the trigger inputs.
 *
 */
typedef union bdk_ctix_ctitriginstatus {
	uint32_t u;
	struct bdk_ctix_ctitriginstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t trin                        : 3;  /**< RO - Trigger input \<n\> status.
                                                                 N is the number of CTI triggers implemented as defined by the
                                                                     CTIDEVID.NUMTRIG field.
                                                                 Bits [31:N] are RAZ.

                                                                 Not implemented and not-connected input triggers are always inactive.
                                                                 0 = Input trigger n is inactive.
                                                                 1 = Input trigger n is active. */
#else
		uint32_t trin                        : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctitriginstatus_s  cn85xx; */
	/* struct bdk_ctix_ctitriginstatus_s  cn88xx; */
	/* struct bdk_ctix_ctitriginstatus_s  cn88xxp1; */
} bdk_ctix_ctitriginstatus_t;

static inline uint64_t BDK_CTIX_CTITRIGINSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTITRIGINSTATUS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010130ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTITRIGINSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTITRIGINSTATUS(...) bdk_ctix_ctitriginstatus_t
#define bustype_BDK_CTIX_CTITRIGINSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTITRIGINSTATUS(p1) (p1)
#define arguments_BDK_CTIX_CTITRIGINSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTITRIGINSTATUS(...) "CTIX_CTITRIGINSTATUS"


/**
 * DAB32b - cti#_ctitrigoutstatus
 *
 * Provides the status of the trigger outputs.
 *
 */
typedef union bdk_ctix_ctitrigoutstatus {
	uint32_t u;
	struct bdk_ctix_ctitrigoutstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t trout                       : 3;  /**< RO - Trigger output \<n\> status.
                                                                 N is the number of CTI triggers implemented as defined by the
                                                                     CTIDEVID.NUMTRIG field.
                                                                 Bits [31:N] are RAZ.

                                                                 If output trigger \<n\> is implemented and connected, possible
                                                                     values of this bit are:
                                                                 Otherwise it is implementation defined whether TROUT\<n\> is RAZ
                                                                     or behaves as above.
                                                                 0 = Output trigger n is inactive.
                                                                 1 = Output trigger n is active. */
#else
		uint32_t trout                       : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_ctix_ctitrigoutstatus_s cn85xx; */
	/* struct bdk_ctix_ctitrigoutstatus_s cn88xx; */
	/* struct bdk_ctix_ctitrigoutstatus_s cn88xxp1; */
} bdk_ctix_ctitrigoutstatus_t;

static inline uint64_t BDK_CTIX_CTITRIGOUTSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CTIX_CTITRIGOUTSTATUS(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008010134ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_CTIX_CTITRIGOUTSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_CTIX_CTITRIGOUTSTATUS(...) bdk_ctix_ctitrigoutstatus_t
#define bustype_BDK_CTIX_CTITRIGOUTSTATUS(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_CTIX_CTITRIGOUTSTATUS(p1) (p1)
#define arguments_BDK_CTIX_CTITRIGOUTSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_CTIX_CTITRIGOUTSTATUS(...) "CTIX_CTITRIGOUTSTATUS"

#endif /* __BDK_CSRS_DAB_CTI__ */
