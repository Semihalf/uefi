#ifndef __BDK_CSRS_DAB_DBG__
#define __BDK_CSRS_DAB_DBG__
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
 * Cavium DAB_DBG.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * DAB32b - dab_rom_table#
 *
 * The ROM table is for Coresight ROM
 *
 */
typedef union bdk_dab_rom_tablex {
	uint32_t u;
	struct bdk_dab_rom_tablex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_dab_rom_tablex_s        cn88xx; */
	/* struct bdk_dab_rom_tablex_s        cn88xxp1; */
} bdk_dab_rom_tablex_t;

static inline uint64_t BDK_DAB_ROM_TABLEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAB_ROM_TABLEX(unsigned long param1)
{
	if (((param1 <= 1023)))
		return 0x000087A000000000ull + (param1 & 1023) * 0x4ull;
	csr_fatal("BDK_DAB_ROM_TABLEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DAB_ROM_TABLEX(...) bdk_dab_rom_tablex_t
#define bustype_BDK_DAB_ROM_TABLEX(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DAB_ROM_TABLEX(p1) (p1)
#define arguments_BDK_DAB_ROM_TABLEX(p1) (p1),-1,-1,-1
#define basename_BDK_DAB_ROM_TABLEX(...) "DAB_ROM_TABLEX"


/**
 * DAB32b - dbg#_dbgauthstatus_el1
 *
 * Debug Authentication Status register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_dbgauthstatus_el1 {
	uint32_t u;
	struct bdk_dbgx_dbgauthstatus_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t snid                        : 2;  /**< RO/H - Secure non-invasive debug. Possible values of this field are:
                                                                 Other values are reserved.
                                                                 \<00\>        Not implemented. EL3 is not implemented and the processor is
                                                                     Non-secure.
                                                                 \<10\>        Implemented and disabled.
                                                                     ExternalSecureNoninvasiveDebugEnabled() == FALSE.
                                                                 \<11\>        Implemented and enabled.
                                                                     ExternalSecureNoninvasiveDebugEnabled() == TRUE.
                                                                 RTL: SNID[1]=1, SNID[0]=(SPIDEN || SPNIDEN) && (NIDEN || DBGEN). */
		uint32_t sid                         : 2;  /**< RO/H - Secure invasive debug. Possible values of this field are:
                                                                 Other values are reserved.
                                                                 \<00\>        Not implemented. EL3 is not implemented and the processor is
                                                                     Non-secure.
                                                                 \<10\>        Implemented and disabled. ExternalSecureInvasiveDebugEnabled()
                                                                     == FALSE.
                                                                 \<11\>        Implemented and enabled. ExternalSecureInvasiveDebugEnabled()
                                                                     == TRUE.
                                                                 RTL: SID[1]=1, SID[0]=(SPIDEN || DBGEN). */
		uint32_t nsnid                       : 2;  /**< RO/H - Non-secure non-invasive debug. Possible values of this field
                                                                     are:
                                                                 Other values are reserved.
                                                                 \<00\>        Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 \<10\>        Implemented and disabled. ExternalNoninvasiveDebugEnabled() ==
                                                                     FALSE.
                                                                 \<11\>        Implemented and enabled. ExternalNoninvasiveDebugEnabled() ==
                                                                     TRUE.
                                                                 RTL: NSNID[1]=1, NSNID[0]=(NIDEN || DBGEN). */
		uint32_t nsid                        : 2;  /**< RO/H - Non-secure invasive debug. Possible values of this field are:
                                                                 Other values are reserved.
                                                                 \<00\>        Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 \<10\>        Implemented and disabled. ExternalInvasiveDebugEnabled() ==
                                                                     FALSE.
                                                                 \<11\>        Implemented and enabled. ExternalInvasiveDebugEnabled() ==
                                                                     TRUE.
                                                                 RTL: NSID[1]=1, NSID[0]= DBGEN. */
#else
		uint32_t nsid                        : 2;
		uint32_t nsnid                       : 2;
		uint32_t sid                         : 2;
		uint32_t snid                        : 2;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_dbgauthstatus_el1_s cn88xx; */
	/* struct bdk_dbgx_dbgauthstatus_el1_s cn88xxp1; */
} bdk_dbgx_dbgauthstatus_el1_t;

static inline uint64_t BDK_DBGX_DBGAUTHSTATUS_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGAUTHSTATUS_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FB8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_DBGAUTHSTATUS_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGAUTHSTATUS_EL1(...) bdk_dbgx_dbgauthstatus_el1_t
#define bustype_BDK_DBGX_DBGAUTHSTATUS_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGAUTHSTATUS_EL1(p1) (p1)
#define arguments_BDK_DBGX_DBGAUTHSTATUS_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_DBGAUTHSTATUS_EL1(...) "DBGX_DBGAUTHSTATUS_EL1"


/**
 * DAB32b - dbg#_dbgbcr#_el1
 *
 * Holds control information for a breakpoint. Forms breakpoint n
 * together with value register DBGBVR\<n\>_EL1, where n is 0 to
 * 15.
 */
typedef union bdk_dbgx_dbgbcrx_el1 {
	uint32_t u;
	struct bdk_dbgx_dbgbcrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t bt                          : 4;  /**< R/W - Breakpoint Type. Possible values are:
                                                                 The field breaks down as follows:
                                                                  BT[3:1]: Base type.- 000: Match address. DBGBVR\<n\>_EL1 is the
                                                                     address of an     instruction. - 010: Mismatch address.
                                                                     Behaves as type0b000 DBGBVR\<n\>_EL1 is     the address of an
                                                                     instruction to be stepped. - 001: Match context ID.
                                                                     DBGBVR\<n\>_EL1[31:0] is a context ID. - 100: Match VMID.
                                                                     DBGBVR\<n\>_EL1[39:32] is a VMID. - 101: Match VMID and context
                                                                     ID. DBGBVR\<n\>_EL1[31:0] is a     context ID, and
                                                                     DBGBVR\<n\>_EL1[39:32] is a VMID.
                                                                  BT[0]: Enable linking.
                                                                 If the breakpoint is not context-aware, BT[3] and BT[1] are
                                                                     RAZ. If EL2 is not implemented, BT[3] is RAZ. If EL1 using
                                                                     AArch32 is not implemented, BT[2] is RAZ.
                                                                 The values0b011x0b11xx
                                                                 \<0000\>      Unlinked instruction address match.
                                                                 \<0001\>      Linked instruction address match.
                                                                 \<0010\>      Unlinked context ID match.
                                                                 \<0011\>      Linked context ID match
                                                                 \<0100\>      Unlinked instruction address mismatch.
                                                                 \<0101\>      Linked instruction address mismatch.
                                                                 \<1000\>      Unlinked VMID match.
                                                                 \<1001\>      Linked VMID match.
                                                                 \<1010\>      Unlinked VMID and context ID match.
                                                                 \<1011\>      Linked VMID and context ID match. */
		uint32_t lbn                         : 4;  /**< R/W - Linked breakpoint number. For Linked address matching
                                                                 breakpoints, this specifies the index of the Context-matching
                                                                 breakpoint linked to. */
		uint32_t ssc                         : 2;  /**< R/W - Security state control. Determines the security states under
                                                                 which a breakpoint debug event for breakpoint n is generated.
                                                                 This field must be interpreted along with the HMC and PMC
                                                                 fields. Possible values are summarised in the "Processor state
                                                                 matching" section of the Debug specification
                                                                 (PRD03-PRDC-010486). */
		uint32_t hmc                         : 1;  /**< R/W - Higher mode control. Determines the debug perspective for
                                                                 deciding when a breakpoint debug event for breakpoint n is
                                                                 generated. This field must be interpreted along with the SSC
                                                                 and PMC fields. Possible values are summarised in the
                                                                 "Processor state matching" section of the Debug specification
                                                                 (PRD03-PRDC-010486). */
		uint32_t reserved_9_12               : 4;
		uint32_t bas                         : 4;  /**< R/W - Byte address select. Defines which half-words an address-
                                                                     matching breakpoint matches, regardless of the instruction set
                                                                     and execution state. In an AArch64-only implementation, this
                                                                     field is reserved, RES1. Otherwise:
                                                                  BAS[2] and BAS[0] are read/write.
                                                                  BAS[3] and BAS[1] are read-only copies of BAS[2] and BAS[0]
                                                                     respectively.
                                                                 The values0b00110b1100
                                                                 For further details of how the BAS field is interpreted by
                                                                     hardware, see "Constraints on programming breakpoint and
                                                                     Watchpoint debug events", section 3.2.10, in the ARMv8 Debug
                                                                     specification (PRD03-PRDC-010486).
                                                                 The permitted values depend on the breakpoint type.
                                                                 For Address match breakpoints in either AArch32 or AArch64
                                                                     state:
                                                                 BAS Match instruction at    Constraint for debuggers
                                                                 0b0011       DBGBVR\<n\>_EL1  Use for T32 and T32EE instructions.
                                                                 0b1100       DBGBVR\<n\>_EL1+2        Use for T32 and T32EE instructions.
                                                                 0b1111       DBGBVR\<n\>_EL1  Use for A64 and A32 instructions.
                                                                 0b0000
                                                                 For Address mismatch breakpoints in an AArch32 stage 1
                                                                     translation regime:
                                                                 BAS Step instruction at     Constraint for debuggers
                                                                 0b0000      -       Use for a match anywhere breakpoint.
                                                                 0b0011       DBGBVR\<n\>_EL1  Use for stepping T32 and T32EE instructions.
                                                                 0b1100       DBGBVR\<n\>_EL1+2        Use for stepping T32 and T32EE instructions.
                                                                 0b1111       DBGBVR\<n\>_EL1  Use for stepping A64 and A32 instructions.
                                                                 For Context matching breakpoints, this field is RES1 and
                                                                     ignored. */
		uint32_t reserved_3_4                : 2;
		uint32_t pmc                         : 2;  /**< R/W - Privilege mode control. Determines the exception level or
                                                                 levels at which a breakpoint debug event for breakpoint n is
                                                                 generated. This field must be interpreted along with the SSC
                                                                 and HMC fields. Possible values are summarised in the
                                                                 "Processor state matching" section of the Debug specification
                                                                 (PRD03-PRDC-010486). */
		uint32_t en                          : 1;  /**< R/W - Enable breakpoint DBGBVR\<n\>_EL1. Possible values are:
                                                                 \<0\> Breakpoint disabled.
                                                                 \<1\> Breakpoint enabled. */
#else
		uint32_t en                          : 1;
		uint32_t pmc                         : 2;
		uint32_t reserved_3_4                : 2;
		uint32_t bas                         : 4;
		uint32_t reserved_9_12               : 4;
		uint32_t hmc                         : 1;
		uint32_t ssc                         : 2;
		uint32_t lbn                         : 4;
		uint32_t bt                          : 4;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_dbgx_dbgbcrx_el1_s      cn88xx; */
	/* struct bdk_dbgx_dbgbcrx_el1_s      cn88xxp1; */
} bdk_dbgx_dbgbcrx_el1_t;

static inline uint64_t BDK_DBGX_DBGBCRX_EL1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGBCRX_EL1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 5)))
		return 0x000087A008000408ull + (param1 & 63) * 0x80000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_DBGX_DBGBCRX_EL1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGBCRX_EL1(...) bdk_dbgx_dbgbcrx_el1_t
#define bustype_BDK_DBGX_DBGBCRX_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGBCRX_EL1(p1,p2) (p1)
#define arguments_BDK_DBGX_DBGBCRX_EL1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DBGX_DBGBCRX_EL1(...) "DBGX_DBGBCRX_EL1"


/**
 * DAB32b - dbg#_dbgbvr#_el1_hi
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_dbgbvrx_el1_hi {
	uint32_t u;
	struct bdk_dbgx_dbgbvrx_el1_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgbvrx_el1_hi_s   cn88xx; */
	/* struct bdk_dbgx_dbgbvrx_el1_hi_s   cn88xxp1; */
} bdk_dbgx_dbgbvrx_el1_hi_t;

static inline uint64_t BDK_DBGX_DBGBVRX_EL1_HI(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGBVRX_EL1_HI(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 5)))
		return 0x000087A008000404ull + (param1 & 63) * 0x80000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_DBGX_DBGBVRX_EL1_HI", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGBVRX_EL1_HI(...) bdk_dbgx_dbgbvrx_el1_hi_t
#define bustype_BDK_DBGX_DBGBVRX_EL1_HI(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGBVRX_EL1_HI(p1,p2) (p1)
#define arguments_BDK_DBGX_DBGBVRX_EL1_HI(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DBGX_DBGBVRX_EL1_HI(...) "DBGX_DBGBVRX_EL1_HI"


/**
 * DAB32b - dbg#_dbgbvr#_el1_lo
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_dbgbvrx_el1_lo {
	uint32_t u;
	struct bdk_dbgx_dbgbvrx_el1_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgbvrx_el1_lo_s   cn88xx; */
	/* struct bdk_dbgx_dbgbvrx_el1_lo_s   cn88xxp1; */
} bdk_dbgx_dbgbvrx_el1_lo_t;

static inline uint64_t BDK_DBGX_DBGBVRX_EL1_LO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGBVRX_EL1_LO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 5)))
		return 0x000087A008000400ull + (param1 & 63) * 0x80000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_DBGX_DBGBVRX_EL1_LO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGBVRX_EL1_LO(...) bdk_dbgx_dbgbvrx_el1_lo_t
#define bustype_BDK_DBGX_DBGBVRX_EL1_LO(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGBVRX_EL1_LO(p1,p2) (p1)
#define arguments_BDK_DBGX_DBGBVRX_EL1_LO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DBGX_DBGBVRX_EL1_LO(...) "DBGX_DBGBVRX_EL1_LO"


/**
 * DAB32b - dbg#_dbgclaimclr_el1
 *
 * Used by software to read the values of the CLAIM bits, and to
 * clear these bits to 0.
 */
typedef union bdk_dbgx_dbgclaimclr_el1 {
	uint32_t u;
	struct bdk_dbgx_dbgclaimclr_el1_s {
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
	/* struct bdk_dbgx_dbgclaimclr_el1_s  cn88xx; */
	/* struct bdk_dbgx_dbgclaimclr_el1_s  cn88xxp1; */
} bdk_dbgx_dbgclaimclr_el1_t;

static inline uint64_t BDK_DBGX_DBGCLAIMCLR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGCLAIMCLR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FA4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_DBGCLAIMCLR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGCLAIMCLR_EL1(...) bdk_dbgx_dbgclaimclr_el1_t
#define bustype_BDK_DBGX_DBGCLAIMCLR_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGCLAIMCLR_EL1(p1) (p1)
#define arguments_BDK_DBGX_DBGCLAIMCLR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_DBGCLAIMCLR_EL1(...) "DBGX_DBGCLAIMCLR_EL1"


/**
 * DAB32b - dbg#_dbgclaimset_el1
 *
 * Used by software to set CLAIM bits to 1.
 *
 */
typedef union bdk_dbgx_dbgclaimset_el1 {
	uint32_t u;
	struct bdk_dbgx_dbgclaimset_el1_s {
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
	/* struct bdk_dbgx_dbgclaimset_el1_s  cn88xx; */
	/* struct bdk_dbgx_dbgclaimset_el1_s  cn88xxp1; */
} bdk_dbgx_dbgclaimset_el1_t;

static inline uint64_t BDK_DBGX_DBGCLAIMSET_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGCLAIMSET_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FA0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_DBGCLAIMSET_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGCLAIMSET_EL1(...) bdk_dbgx_dbgclaimset_el1_t
#define bustype_BDK_DBGX_DBGCLAIMSET_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGCLAIMSET_EL1(p1) (p1)
#define arguments_BDK_DBGX_DBGCLAIMSET_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_DBGCLAIMSET_EL1(...) "DBGX_DBGCLAIMSET_EL1"


/**
 * DAB32b - dbg#_dbgdtrrx_el0
 *
 * Transfers 32 bits of data from an external host to the
 * processor.
 */
typedef union bdk_dbgx_dbgdtrrx_el0 {
	uint32_t u;
	struct bdk_dbgx_dbgdtrrx_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Update DTRRX
                                                                 Update DTRRX. Writes to this register update the value in
                                                                     DTRRX and set RXfull to 1.
                                                                 Reads of this register return the last value written to DTRRX
                                                                     and do not change RXfull. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgdtrrx_el0_s     cn88xx; */
	/* struct bdk_dbgx_dbgdtrrx_el0_s     cn88xxp1; */
} bdk_dbgx_dbgdtrrx_el0_t;

static inline uint64_t BDK_DBGX_DBGDTRRX_EL0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGDTRRX_EL0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000080ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_DBGDTRRX_EL0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGDTRRX_EL0(...) bdk_dbgx_dbgdtrrx_el0_t
#define bustype_BDK_DBGX_DBGDTRRX_EL0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGDTRRX_EL0(p1) (p1)
#define arguments_BDK_DBGX_DBGDTRRX_EL0(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_DBGDTRRX_EL0(...) "DBGX_DBGDTRRX_EL0"


/**
 * DAB32b - dbg#_dbgdtrtx_el0
 *
 * Transfers 32 bits of data from the processor to an external
 * host.
 */
typedef union bdk_dbgx_dbgdtrtx_el0 {
	uint32_t u;
	struct bdk_dbgx_dbgdtrtx_el0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< R/W - Return DTRTX
                                                                 Return DTRTX. Reads of this register return the value in DTRTX
                                                                     and clear TXfull to 0.
                                                                 Writes of this register update the value in DTRTX and do not
                                                                     change TXfull. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgdtrtx_el0_s     cn88xx; */
	/* struct bdk_dbgx_dbgdtrtx_el0_s     cn88xxp1; */
} bdk_dbgx_dbgdtrtx_el0_t;

static inline uint64_t BDK_DBGX_DBGDTRTX_EL0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGDTRTX_EL0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A00800008Cull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_DBGDTRTX_EL0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGDTRTX_EL0(...) bdk_dbgx_dbgdtrtx_el0_t
#define bustype_BDK_DBGX_DBGDTRTX_EL0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGDTRTX_EL0(p1) (p1)
#define arguments_BDK_DBGX_DBGDTRTX_EL0(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_DBGDTRTX_EL0(...) "DBGX_DBGDTRTX_EL0"


/**
 * DAB32b - dbg#_dbgwcr#_el1
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_dbgwcrx_el1 {
	uint32_t u;
	struct bdk_dbgx_dbgwcrx_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgwcrx_el1_s      cn88xx; */
	/* struct bdk_dbgx_dbgwcrx_el1_s      cn88xxp1; */
} bdk_dbgx_dbgwcrx_el1_t;

static inline uint64_t BDK_DBGX_DBGWCRX_EL1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGWCRX_EL1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 5)))
		return 0x000087A008000808ull + (param1 & 63) * 0x80000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_DBGX_DBGWCRX_EL1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGWCRX_EL1(...) bdk_dbgx_dbgwcrx_el1_t
#define bustype_BDK_DBGX_DBGWCRX_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGWCRX_EL1(p1,p2) (p1)
#define arguments_BDK_DBGX_DBGWCRX_EL1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DBGX_DBGWCRX_EL1(...) "DBGX_DBGWCRX_EL1"


/**
 * DAB32b - dbg#_dbgwvr#_el1_hi
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_dbgwvrx_el1_hi {
	uint32_t u;
	struct bdk_dbgx_dbgwvrx_el1_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgwvrx_el1_hi_s   cn88xx; */
	/* struct bdk_dbgx_dbgwvrx_el1_hi_s   cn88xxp1; */
} bdk_dbgx_dbgwvrx_el1_hi_t;

static inline uint64_t BDK_DBGX_DBGWVRX_EL1_HI(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGWVRX_EL1_HI(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 5)))
		return 0x000087A008000804ull + (param1 & 63) * 0x80000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_DBGX_DBGWVRX_EL1_HI", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGWVRX_EL1_HI(...) bdk_dbgx_dbgwvrx_el1_hi_t
#define bustype_BDK_DBGX_DBGWVRX_EL1_HI(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGWVRX_EL1_HI(p1,p2) (p1)
#define arguments_BDK_DBGX_DBGWVRX_EL1_HI(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DBGX_DBGWVRX_EL1_HI(...) "DBGX_DBGWVRX_EL1_HI"


/**
 * DAB32b - dbg#_dbgwvr#_el1_lo
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_dbgwvrx_el1_lo {
	uint32_t u;
	struct bdk_dbgx_dbgwvrx_el1_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_dbgwvrx_el1_lo_s   cn88xx; */
	/* struct bdk_dbgx_dbgwvrx_el1_lo_s   cn88xxp1; */
} bdk_dbgx_dbgwvrx_el1_lo_t;

static inline uint64_t BDK_DBGX_DBGWVRX_EL1_LO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGWVRX_EL1_LO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 47)) && ((param2 <= 5)))
		return 0x000087A008000800ull + (param1 & 63) * 0x80000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_DBGX_DBGWVRX_EL1_LO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_DBGWVRX_EL1_LO(...) bdk_dbgx_dbgwvrx_el1_lo_t
#define bustype_BDK_DBGX_DBGWVRX_EL1_LO(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_DBGWVRX_EL1_LO(p1,p2) (p1)
#define arguments_BDK_DBGX_DBGWVRX_EL1_LO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_DBGX_DBGWVRX_EL1_LO(...) "DBGX_DBGWVRX_EL1_LO"


/**
 * DAB32b - dbg#_edacr
 *
 * Allows implementations to support IMPLEMENTATION DEFINED
 * controls.
 */
typedef union bdk_dbgx_edacr {
	uint32_t u;
	struct bdk_dbgx_edacr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t impl_defined                : 32;
#else
		uint32_t impl_defined                : 32;
#endif
	} s;
	/* struct bdk_dbgx_edacr_s            cn88xx; */
	/* struct bdk_dbgx_edacr_s            cn88xxp1; */
} bdk_dbgx_edacr_t;

static inline uint64_t BDK_DBGX_EDACR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDACR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000094ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDACR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDACR(...) bdk_dbgx_edacr_t
#define bustype_BDK_DBGX_EDACR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDACR(p1) (p1)
#define arguments_BDK_DBGX_EDACR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDACR(...) "DBGX_EDACR"


/**
 * DAB32b - dbg#_edcidr0
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edcidr0 {
	uint32_t u;
	struct bdk_dbgx_edcidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_0                     : 8;  /**< RO - Preamble. Must read as 0x0D. */
#else
		uint32_t prmbl_0                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edcidr0_s          cn88xx; */
	/* struct bdk_dbgx_edcidr0_s          cn88xxp1; */
} bdk_dbgx_edcidr0_t;

static inline uint64_t BDK_DBGX_EDCIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FF0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDCIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDCIDR0(...) bdk_dbgx_edcidr0_t
#define bustype_BDK_DBGX_EDCIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDCIDR0(p1) (p1)
#define arguments_BDK_DBGX_EDCIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDCIDR0(...) "DBGX_EDCIDR0"


/**
 * DAB32b - dbg#_edcidr1
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edcidr1 {
	uint32_t u;
	struct bdk_dbgx_edcidr1_s {
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
	/* struct bdk_dbgx_edcidr1_s          cn88xx; */
	/* struct bdk_dbgx_edcidr1_s          cn88xxp1; */
} bdk_dbgx_edcidr1_t;

static inline uint64_t BDK_DBGX_EDCIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FF4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDCIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDCIDR1(...) bdk_dbgx_edcidr1_t
#define bustype_BDK_DBGX_EDCIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDCIDR1(p1) (p1)
#define arguments_BDK_DBGX_EDCIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDCIDR1(...) "DBGX_EDCIDR1"


/**
 * DAB32b - dbg#_edcidr2
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edcidr2 {
	uint32_t u;
	struct bdk_dbgx_edcidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_2                     : 8;  /**< RO - Preamble. Must read as 0x05. */
#else
		uint32_t prmbl_2                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edcidr2_s          cn88xx; */
	/* struct bdk_dbgx_edcidr2_s          cn88xxp1; */
} bdk_dbgx_edcidr2_t;

static inline uint64_t BDK_DBGX_EDCIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FF8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDCIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDCIDR2(...) bdk_dbgx_edcidr2_t
#define bustype_BDK_DBGX_EDCIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDCIDR2(p1) (p1)
#define arguments_BDK_DBGX_EDCIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDCIDR2(...) "DBGX_EDCIDR2"


/**
 * DAB32b - dbg#_edcidr3
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edcidr3 {
	uint32_t u;
	struct bdk_dbgx_edcidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t prmbl_3                     : 8;  /**< RO - Preamble. Must read as 0xB1. */
#else
		uint32_t prmbl_3                     : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edcidr3_s          cn88xx; */
	/* struct bdk_dbgx_edcidr3_s          cn88xxp1; */
} bdk_dbgx_edcidr3_t;

static inline uint64_t BDK_DBGX_EDCIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FFCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDCIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDCIDR3(...) bdk_dbgx_edcidr3_t
#define bustype_BDK_DBGX_EDCIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDCIDR3(p1) (p1)
#define arguments_BDK_DBGX_EDCIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDCIDR3(...) "DBGX_EDCIDR3"


/**
 * DAB32b - dbg#_edcidsr
 *
 * Contains the sampled value of CONTEXTIDR_EL1, captured on
 * reading the low half of EDPCSR.
 */
typedef union bdk_dbgx_edcidsr {
	uint32_t u;
	struct bdk_dbgx_edcidsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t contextidr                  : 32; /**< RO - The sampled value of CONTEXTIDR_EL1, captured on reading the
                                                                     low half of EDPCSR.
                                                                 If EL3 is implemented and using AArch32 then CONTEXTIDR is a
                                                                     Banked register, and EDCIDSR samples the current Banked copy
                                                                     of CONTEXTIDR. */
#else
		uint32_t contextidr                  : 32;
#endif
	} s;
	/* struct bdk_dbgx_edcidsr_s          cn88xx; */
	/* struct bdk_dbgx_edcidsr_s          cn88xxp1; */
} bdk_dbgx_edcidsr_t;

static inline uint64_t BDK_DBGX_EDCIDSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDSR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A0080000A4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDCIDSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDCIDSR(...) bdk_dbgx_edcidsr_t
#define bustype_BDK_DBGX_EDCIDSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDCIDSR(p1) (p1)
#define arguments_BDK_DBGX_EDCIDSR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDCIDSR(...) "DBGX_EDCIDSR"


/**
 * DAB32b - dbg#_eddevaff0
 *
 * MPIDR_EL1[31:0] register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_eddevaff0 {
	uint32_t u;
	struct bdk_dbgx_eddevaff0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t b31                         : 1;  /**< RO - Bit 31. */
		uint32_t u                           : 1;  /**< RO - U name. */
		uint32_t reserved_24_29              : 6;
		uint32_t aff2                        : 8;  /**< RO/H - AFF2, this is node id from CIC. */
		uint32_t aff1                        : 8;  /**< RO/H - AFF1. */
		uint32_t aff0                        : 8;  /**< RO/H - AFF0. */
#else
		uint32_t aff0                        : 8;
		uint32_t aff1                        : 8;
		uint32_t aff2                        : 8;
		uint32_t reserved_24_29              : 6;
		uint32_t u                           : 1;
		uint32_t b31                         : 1;
#endif
	} s;
	/* struct bdk_dbgx_eddevaff0_s        cn88xx; */
	/* struct bdk_dbgx_eddevaff0_s        cn88xxp1; */
} bdk_dbgx_eddevaff0_t;

static inline uint64_t BDK_DBGX_EDDEVAFF0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVAFF0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FA8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVAFF0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVAFF0(...) bdk_dbgx_eddevaff0_t
#define bustype_BDK_DBGX_EDDEVAFF0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVAFF0(p1) (p1)
#define arguments_BDK_DBGX_EDDEVAFF0(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVAFF0(...) "DBGX_EDDEVAFF0"


/**
 * DAB32b - dbg#_eddevaff1
 *
 * MPIDR_EL1[63:32] register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_eddevaff1 {
	uint32_t u;
	struct bdk_dbgx_eddevaff1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_dbgx_eddevaff1_s        cn88xx; */
	/* struct bdk_dbgx_eddevaff1_s        cn88xxp1; */
} bdk_dbgx_eddevaff1_t;

static inline uint64_t BDK_DBGX_EDDEVAFF1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVAFF1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FACull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVAFF1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVAFF1(...) bdk_dbgx_eddevaff1_t
#define bustype_BDK_DBGX_EDDEVAFF1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVAFF1(p1) (p1)
#define arguments_BDK_DBGX_EDDEVAFF1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVAFF1(...) "DBGX_EDDEVAFF1"


/**
 * DAB32b - dbg#_eddevarch
 *
 * Identifies the programmers' model architecture of the external
 * debug component.
 */
typedef union bdk_dbgx_eddevarch {
	uint32_t u;
	struct bdk_dbgx_eddevarch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t architect                   : 11; /**< RO - Defines the architecture of the component. For debug, this is
                                                                     ARM Limited.
                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.
                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
		uint32_t present                     : 1;  /**< RO - When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
		uint32_t revision                    : 4;  /**< RO - Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For debug, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
		uint32_t archid                      : 16; /**< RO - Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For debug:
                                                                  Bits [15:12] are the architecture version, 0x6.
                                                                  Bits [11:0] are the architecture part number, 0xA15.
                                                                 This corresponds to debug architecture version v8-A. */
#else
		uint32_t archid                      : 16;
		uint32_t revision                    : 4;
		uint32_t present                     : 1;
		uint32_t architect                   : 11;
#endif
	} s;
	/* struct bdk_dbgx_eddevarch_s        cn88xx; */
	/* struct bdk_dbgx_eddevarch_s        cn88xxp1; */
} bdk_dbgx_eddevarch_t;

static inline uint64_t BDK_DBGX_EDDEVARCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVARCH(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FBCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVARCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVARCH(...) bdk_dbgx_eddevarch_t
#define bustype_BDK_DBGX_EDDEVARCH(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVARCH(p1) (p1)
#define arguments_BDK_DBGX_EDDEVARCH(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVARCH(...) "DBGX_EDDEVARCH"


/**
 * DAB32b - dbg#_eddevid
 *
 * Device id register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_eddevid {
	uint32_t u;
	struct bdk_dbgx_eddevid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t auxregs                     : 4;  /**< RO - Indicates support for Auxiliary registers. Permitted values
                                                                     for this field are:
                                                                 All other values are reserved.
                                                                 \<0000\>      None supported.
                                                                 \<0001\>      Support for External Debug Auxiliary Control Register, EDACR. */
		uint32_t reserved_4_23               : 20;
		uint32_t pcsample                    : 4;  /**< RO - PCsample field.
                                                                 Indicates the level of Sample-based profiling support using
                                                                     external debug registers 40 through 43. Permitted values of
                                                                     this field in v8-A are:
                                                                 All other values are reserved.
                                                                 \<0000\>      Architecture-defined form of Sample-based profiling not
                                                                     implemented.
                                                                 \<0010\>       EDPCSR and EDCIDSR are implemented (only permitted if EL3 and
                                                                     EL2 are not implemented).
                                                                 \<0011\>       EDPCSR, EDCIDSR, and EDVIDSR are implemented. */
#else
		uint32_t pcsample                    : 4;
		uint32_t reserved_4_23               : 20;
		uint32_t auxregs                     : 4;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	/* struct bdk_dbgx_eddevid_s          cn88xx; */
	/* struct bdk_dbgx_eddevid_s          cn88xxp1; */
} bdk_dbgx_eddevid_t;

static inline uint64_t BDK_DBGX_EDDEVID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVID(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FC8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVID(...) bdk_dbgx_eddevid_t
#define bustype_BDK_DBGX_EDDEVID(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVID(p1) (p1)
#define arguments_BDK_DBGX_EDDEVID(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVID(...) "DBGX_EDDEVID"


/**
 * DAB32b - dbg#_eddevid1
 *
 * Revice id1 register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_eddevid1 {
	uint32_t u;
	struct bdk_dbgx_eddevid1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t pcsroffset                  : 4;  /**< RO - PCSROffset field.
                                                                 This field indicates the offset applied to PC samples returned
                                                                     by reads of EDPCSR. Permitted values of this field in v8-A
                                                                     are:
                                                                 \<0000\>       EDPCSR not implemented.
                                                                 \<0010\>       EDPCSR implemented, and samples have no offset applied and do
                                                                     not sample the instruction set state in AArch32 state. */
#else
		uint32_t pcsroffset                  : 4;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_dbgx_eddevid1_s         cn88xx; */
	/* struct bdk_dbgx_eddevid1_s         cn88xxp1; */
} bdk_dbgx_eddevid1_t;

static inline uint64_t BDK_DBGX_EDDEVID1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVID1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FC4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVID1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVID1(...) bdk_dbgx_eddevid1_t
#define bustype_BDK_DBGX_EDDEVID1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVID1(p1) (p1)
#define arguments_BDK_DBGX_EDDEVID1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVID1(...) "DBGX_EDDEVID1"


/**
 * DAB32b - dbg#_eddevid2
 *
 * Device id2 register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_eddevid2 {
	uint32_t u;
	struct bdk_dbgx_eddevid2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_dbgx_eddevid2_s         cn88xx; */
	/* struct bdk_dbgx_eddevid2_s         cn88xxp1; */
} bdk_dbgx_eddevid2_t;

static inline uint64_t BDK_DBGX_EDDEVID2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVID2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FC0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVID2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVID2(...) bdk_dbgx_eddevid2_t
#define bustype_BDK_DBGX_EDDEVID2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVID2(p1) (p1)
#define arguments_BDK_DBGX_EDDEVID2(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVID2(...) "DBGX_EDDEVID2"


/**
 * DAB32b - dbg#_eddevtype
 *
 * Indicates to a debugger that this component is part of a
 * processor's debug logic.
 */
typedef union bdk_dbgx_eddevtype {
	uint32_t u;
	struct bdk_dbgx_eddevtype_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t sub                         : 4;  /**< RO - Subtype. Must read as 0x1. */
		uint32_t major                       : 4;  /**< RO - Major type. Must read as 0x5. */
#else
		uint32_t major                       : 4;
		uint32_t sub                         : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_eddevtype_s        cn88xx; */
	/* struct bdk_dbgx_eddevtype_s        cn88xxp1; */
} bdk_dbgx_eddevtype_t;

static inline uint64_t BDK_DBGX_EDDEVTYPE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVTYPE(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FCCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDEVTYPE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDEVTYPE(...) bdk_dbgx_eddevtype_t
#define bustype_BDK_DBGX_EDDEVTYPE(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDDEVTYPE(p1) (p1)
#define arguments_BDK_DBGX_EDDEVTYPE(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDEVTYPE(...) "DBGX_EDDEVTYPE"


/**
 * DAB - dbg#_eddfr
 *
 * Provide information for external debuggers. CTX_CMDS, WRPS, BRPS, PMUVER, TRACEVER has same
 * value in the corresponding fields of ID_AA64DFR0_EL1.
 */
typedef union bdk_dbgx_eddfr {
	uint64_t u;
	struct bdk_dbgx_eddfr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ctx_cmds                    : 4;  /**< RO - Number of breakpoints that are context-aware, minus 1.
                                                                 These are the highest numbeed breakpoints. */
		uint64_t reserved_24_27              : 4;
		uint64_t wrps                        : 4;  /**< RO - Number of watch points, minus 1. The value of 0x0 is reserved. */
		uint64_t reserved_16_19              : 4;
		uint64_t brps                        : 4;  /**< RO - Number of break points, minus 1. The value of 0x0 is reserved. */
		uint64_t pmuver                      : 4;  /**< RO - Support for performance monitors extension system registers. Permitted values are:
                                                                   0x0 = Performance monitors extension system registers not implemented.
                                                                   0x1 =Support for performance monitors extension system registers, version 3, as
                                                                 defined in Part C, performance monitors extension.
                                                                   0xF = Implementation defined form of performance monitors supported, PMUv3 not
                                                                 supported.
                                                                   _ All other values are reserved. */
		uint64_t tracever                    : 4;  /**< RO - Support for trace extension system registers. Permitted values are:
                                                                 0x0 = Trace extension system registers not implemented.
                                                                 0x1 = Support for ARM-defined trace extension system registers. The trace ID register
                                                                        gives more information about implementation.
                                                                 _ All other values are reserved. */
		uint64_t debugver                    : 4;  /**< RO - Support for debug architecture. Permitted values are:
                                                                 0x6 = Support for ARMv8 architecture.
                                                                 _ All other values are reserved. */
#else
		uint64_t debugver                    : 4;
		uint64_t tracever                    : 4;
		uint64_t pmuver                      : 4;
		uint64_t brps                        : 4;
		uint64_t reserved_16_19              : 4;
		uint64_t wrps                        : 4;
		uint64_t reserved_24_27              : 4;
		uint64_t ctx_cmds                    : 4;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_dbgx_eddfr_s            cn88xx; */
	/* struct bdk_dbgx_eddfr_s            cn88xxp1; */
} bdk_dbgx_eddfr_t;

static inline uint64_t BDK_DBGX_EDDFR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDFR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000D28ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDDFR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDDFR(...) bdk_dbgx_eddfr_t
#define bustype_BDK_DBGX_EDDFR(...) BDK_CSR_TYPE_DAB
#define busnum_BDK_DBGX_EDDFR(p1) (p1)
#define arguments_BDK_DBGX_EDDFR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDDFR(...) "DBGX_EDDFR"


/**
 * DAB32b - dbg#_edeccr
 *
 * Controls exception catch debug events.
 *
 */
typedef union bdk_dbgx_edeccr {
	uint32_t u;
	struct bdk_dbgx_edeccr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t nse                         : 4;  /**< R/W - Coarse-grained Non-secure exception catch. Possible values of
                                                                     this field are:
                                                                 All other values are reserved. Bits [7,4] are reserved, RAZ.
                                                                 \<0000\>      Exception catch debug event disabled for Non-secure exception
                                                                     levels.
                                                                 \<0010\>      Exception catch debug event enabled for Non-secure EL1.
                                                                 \<0100\>      Exception catch debug event enabled for Non-secure EL2.
                                                                 \<0110\>      Exception catch debug event enabled for Non-secure EL1 and
                                                                     EL2. */
		uint32_t se                          : 4;  /**< R/W - Coarse-grained Secure exception catch. Possible values of this
                                                                     field are:
                                                                 All other values are reserved. Bits [2,0] are reserved. RAZ.
                                                                     Ignored if ExternalSecureInvasiveDebugEnabled() == FALSE.
                                                                 \<0000\>      Exception catch debug event disabled for Secure exception
                                                                     levels.
                                                                 \<0010\>      Exception catch debug event enabled for Secure EL1.
                                                                 \<1000\>      Exception catch debug event enabled for Secure EL3.
                                                                 \<1010\>      Exception catch debug event enabled for Secure EL1 and EL3. */
#else
		uint32_t se                          : 4;
		uint32_t nse                         : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edeccr_s           cn88xx; */
	/* struct bdk_dbgx_edeccr_s           cn88xxp1; */
} bdk_dbgx_edeccr_t;

static inline uint64_t BDK_DBGX_EDECCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDECCR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000098ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDECCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDECCR(...) bdk_dbgx_edeccr_t
#define bustype_BDK_DBGX_EDECCR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDECCR(p1) (p1)
#define arguments_BDK_DBGX_EDECCR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDECCR(...) "DBGX_EDECCR"


/**
 * DAB32b - dbg#_edecr
 *
 * Controls Halting debug events.
 *
 */
typedef union bdk_dbgx_edecr {
	uint32_t u;
	struct bdk_dbgx_edecr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ss                          : 1;  /**< R/W - Halting step enable. Possible values of this field are:
                                                                 If the value of EDECR.SS is changed when the processor is in
                                                                     Non-debug state, the resulting value of EDECR.SS is UNKNOWN.
                                                                 \<0\> Halting step debug event disabled.
                                                                 \<1\> Halting step debug event enabled. */
		uint32_t rce                         : 1;  /**< R/W - Reset catch enable. Possible values of this field are:
                                                                 \<0\> Reset catch debug event disabled.
                                                                 \<1\> Reset catch debug event enabled. */
		uint32_t osuce                       : 1;  /**< R/W - OS unlock catch enabled. Possible values of this field are:
                                                                 \<0\> OS unlock catch debug event disabled.
                                                                 \<1\> OS unlock catch debug event enabled. */
#else
		uint32_t osuce                       : 1;
		uint32_t rce                         : 1;
		uint32_t ss                          : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_dbgx_edecr_s            cn88xx; */
	/* struct bdk_dbgx_edecr_s            cn88xxp1; */
} bdk_dbgx_edecr_t;

static inline uint64_t BDK_DBGX_EDECR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDECR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000024ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDECR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDECR(...) bdk_dbgx_edecr_t
#define bustype_BDK_DBGX_EDECR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDECR(p1) (p1)
#define arguments_BDK_DBGX_EDECR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDECR(...) "DBGX_EDECR"


/**
 * DAB32b - dbg#_edesr
 *
 * Indicates the status of internally pending Halting debug
 * events.
 */
typedef union bdk_dbgx_edesr {
	uint32_t u;
	struct bdk_dbgx_edesr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ss                          : 1;  /**< R/W - Halting step debug event pending. Possible values of this
                                                                     field are:
                                                                 \<0\> Reading this means that a Halting step debug event is not
                                                                     pending. Writing this means no action.
                                                                 \<1\> Reading this means that a Halting step debug event is pending.
                                                                     Writing this clears the pending Halting step debug event. */
		uint32_t rc                          : 1;  /**< R/W - Reset catch debug event pending. Possible values of this field
                                                                     are:
                                                                 \<0\> Reading this means that a Reset catch debug event is not
                                                                     pending. Writing this means no action.
                                                                 \<1\> Reading this means that a Reset catch debug event is pending.
                                                                     Writing this clears the pending Reset catch debug event. */
		uint32_t osuc                        : 1;  /**< R/W - OS unlock debug event pending. Possible values of this field
                                                                     are:
                                                                 \<0\> Reading this means that an OS unlock catch debug event is not
                                                                     pending. Writing this means no action.
                                                                 \<1\> Reading this means that an OS unlock catch debug event is
                                                                     pending. Writing this clears the pending OS unlock catch debug
                                                                     event. */
#else
		uint32_t osuc                        : 1;
		uint32_t rc                          : 1;
		uint32_t ss                          : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_dbgx_edesr_s            cn88xx; */
	/* struct bdk_dbgx_edesr_s            cn88xxp1; */
} bdk_dbgx_edesr_t;

static inline uint64_t BDK_DBGX_EDESR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDESR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000020ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDESR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDESR(...) bdk_dbgx_edesr_t
#define bustype_BDK_DBGX_EDESR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDESR(p1) (p1)
#define arguments_BDK_DBGX_EDESR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDESR(...) "DBGX_EDESR"


/**
 * DAB32b - dbg#_editctrl
 *
 * Enables the external debug to switch from its default mode
 * into integration mode, where test software can control
 * directly the inputs and outputs of the processor, for
 * integration testing or topology detection.
 */
typedef union bdk_dbgx_editctrl {
	uint32_t u;
	struct bdk_dbgx_editctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t ime                         : 1;  /**< RO - Integration mode enable. When IME == 1, the device reverts to
                                                                     an integration mode to enable integration testing or topology
                                                                     detection. The integration mode behavior is IMPLEMENTATION
                                                                     DEFINED.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled. */
#else
		uint32_t ime                         : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_dbgx_editctrl_s         cn88xx; */
	/* struct bdk_dbgx_editctrl_s         cn88xxp1; */
} bdk_dbgx_editctrl_t;

static inline uint64_t BDK_DBGX_EDITCTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDITCTRL(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000F00ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDITCTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDITCTRL(...) bdk_dbgx_editctrl_t
#define bustype_BDK_DBGX_EDITCTRL(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDITCTRL(p1) (p1)
#define arguments_BDK_DBGX_EDITCTRL(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDITCTRL(...) "DBGX_EDITCTRL"


/**
 * DAB32b - dbg#_editr
 *
 * Used in Debug state for passing instructions to the processor
 * for execution.
 */
typedef union bdk_dbgx_editr {
	uint32_t u;
	struct bdk_dbgx_editr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t t32second                   : 16; /**< WO - Second halfword of the T32 instruction to be executed on the
                                                                 processor. */
		uint32_t t32first                    : 16; /**< WO - First halfword of the T32 instruction to be executed on the
                                                                 processor. */
#else
		uint32_t t32first                    : 16;
		uint32_t t32second                   : 16;
#endif
	} s;
	/* struct bdk_dbgx_editr_s            cn88xx; */
	/* struct bdk_dbgx_editr_s            cn88xxp1; */
} bdk_dbgx_editr_t;

static inline uint64_t BDK_DBGX_EDITR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDITR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000084ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDITR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDITR(...) bdk_dbgx_editr_t
#define bustype_BDK_DBGX_EDITR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDITR(p1) (p1)
#define arguments_BDK_DBGX_EDITR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDITR(...) "DBGX_EDITR"


/**
 * DAB32b - dbg#_edlar
 *
 * Allows or disallows access to the external debug registers
 * through a memory-mapped interface.
 */
typedef union bdk_dbgx_edlar {
	uint32_t u;
	struct bdk_dbgx_edlar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t key                         : 32; /**< WO - Lock Access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface. */
#else
		uint32_t key                         : 32;
#endif
	} s;
	/* struct bdk_dbgx_edlar_s            cn88xx; */
	/* struct bdk_dbgx_edlar_s            cn88xxp1; */
} bdk_dbgx_edlar_t;

static inline uint64_t BDK_DBGX_EDLAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDLAR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FB0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDLAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDLAR(...) bdk_dbgx_edlar_t
#define bustype_BDK_DBGX_EDLAR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDLAR(p1) (p1)
#define arguments_BDK_DBGX_EDLAR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDLAR(...) "DBGX_EDLAR"


/**
 * DAB32b - dbg#_edlsr
 *
 * Indicates the current status of the software lock for external
 * debug registers.
 */
typedef union bdk_dbgx_edlsr {
	uint32_t u;
	struct bdk_dbgx_edlsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ntt                         : 1;  /**< RO - Not thirty-two bit access required. RAZ. */
		uint32_t slk                         : 1;  /**< RO/H - Software lock status for this component. For an access to LSR
                                                                     that is not a memory-mapped access, or when the software lock
                                                                     is not implemented, this field is RAZ.
                                                                 For memory-mapped accesses when the software lock is
                                                                     implemented, possible values of this field are:
                                                                 \<0\> Lock clear. Writes are permitted to this component's
                                                                     registers.
                                                                 \<1\> Lock set. Writes to this component's registers are ignored,
                                                                     and reads have no side effects. */
		uint32_t sli                         : 1;  /**< RO - Software lock implemented for CNXXXX. For an access to LSR that is not a
                                                                     memory-mapped access, this field is RAZ. For memory-mapped
                                                                     accesses, the value of this field is IMPLEMENTATION DEFINED.
                                                                     Permitted values are:
                                                                 \<0\> Software lock not implemented or not memory-mapped access.
                                                                 \<1\> Software lock implemented and memory-mapped access. */
#else
		uint32_t sli                         : 1;
		uint32_t slk                         : 1;
		uint32_t ntt                         : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_dbgx_edlsr_s            cn88xx; */
	/* struct bdk_dbgx_edlsr_s            cn88xxp1; */
} bdk_dbgx_edlsr_t;

static inline uint64_t BDK_DBGX_EDLSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDLSR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FB4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDLSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDLSR(...) bdk_dbgx_edlsr_t
#define bustype_BDK_DBGX_EDLSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDLSR(p1) (p1)
#define arguments_BDK_DBGX_EDLSR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDLSR(...) "DBGX_EDLSR"


/**
 * DAB32b - dbg#_edpcsr_hi
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_edpcsr_hi {
	uint32_t u;
	struct bdk_dbgx_edpcsr_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_edpcsr_hi_s        cn88xx; */
	/* struct bdk_dbgx_edpcsr_hi_s        cn88xxp1; */
} bdk_dbgx_edpcsr_hi_t;

static inline uint64_t BDK_DBGX_EDPCSR_HI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPCSR_HI(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A0080000ACull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPCSR_HI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPCSR_HI(...) bdk_dbgx_edpcsr_hi_t
#define bustype_BDK_DBGX_EDPCSR_HI(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPCSR_HI(p1) (p1)
#define arguments_BDK_DBGX_EDPCSR_HI(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPCSR_HI(...) "DBGX_EDPCSR_HI"


/**
 * DAB32b - dbg#_edpcsr_lo
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_edpcsr_lo {
	uint32_t u;
	struct bdk_dbgx_edpcsr_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t value                       : 32;
#else
		uint32_t value                       : 32;
#endif
	} s;
	/* struct bdk_dbgx_edpcsr_lo_s        cn88xx; */
	/* struct bdk_dbgx_edpcsr_lo_s        cn88xxp1; */
} bdk_dbgx_edpcsr_lo_t;

static inline uint64_t BDK_DBGX_EDPCSR_LO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPCSR_LO(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A0080000A0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPCSR_LO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPCSR_LO(...) bdk_dbgx_edpcsr_lo_t
#define bustype_BDK_DBGX_EDPCSR_LO(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPCSR_LO(p1) (p1)
#define arguments_BDK_DBGX_EDPCSR_LO(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPCSR_LO(...) "DBGX_EDPCSR_LO"


/**
 * DAB - dbg#_edpfr
 *
 * Provide information for external debuggers. GIC, ADVSIMD, FP, EL3, EL2, EL1, EL0 has same
 * value in the corresponding fields of ID_AA64PFR0_EL1.
 */
typedef union bdk_dbgx_edpfr {
	uint64_t u;
	struct bdk_dbgx_edpfr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t gic                         : 4;  /**< RO - GIC system register interface. Permitted values are:
                                                                 0x0 = No GIC system registers are supported.
                                                                 0x1 = GICv3 system registers are supported.
                                                                 _ All other values are reserved. */
		uint64_t advsimd                     : 4;  /**< RO - Advanced SIMD. Permitted values are:
                                                                 0x0 = Advanced SIMD is implemented.
                                                                 0xF = Advanced SIMD is not implemented.
                                                                 _ All other values are reserved. */
		uint64_t fp                          : 4;  /**< RO - Floating-point. Permitted values are:
                                                                 0x0 = Floating-point is implemented.
                                                                 0xF = Floating-point is not implemented.
                                                                 _ All other values are reserved. */
		uint64_t el3                         : 4;  /**< RO - EL3 exception level handling. Permitted values are:
                                                                 0x0 = EL3 is not implemented.
                                                                 0x1 = EL3 can be executed in AArch64 state only.
                                                                 0x2 = EL3 can be executed in either AArch64 or AArch32 state.
                                                                 _ All other values are reserved. */
		uint64_t el2                         : 4;  /**< RO - EL2 exception level handling. Permitted values are:
                                                                 0x0 = EL2 is not implemented.
                                                                 0x1 = EL2 can be executed in AArch64 state only.
                                                                 0x2 = EL2 can be executed in either AArch64 or AArch32 state.
                                                                 _ All other values are reserved. */
		uint64_t el1                         : 4;  /**< RO - EL1 exception level handling. Permitted values are:
                                                                 0x0 = EL1 is not implemented.
                                                                 0x1 = EL1 can be executed in AArch64 state only.
                                                                 0x2 = EL1 can be executed in either AArch64 or AArch32 state.
                                                                 _ All other values are reserved. */
		uint64_t el0                         : 4;  /**< RO - EL0 exception level handling. Permitted values are:
                                                                 0x0 = EL0 is not implemented.
                                                                 0x1 = EL0 can be executed in AArch64 state only.
                                                                 0x2 = EL0 can be executed in either AArch64 or AArch32 state.
                                                                 _ All other values are reserved. */
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
	/* struct bdk_dbgx_edpfr_s            cn88xx; */
	/* struct bdk_dbgx_edpfr_s            cn88xxp1; */
} bdk_dbgx_edpfr_t;

static inline uint64_t BDK_DBGX_EDPFR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPFR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000D20ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPFR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPFR(...) bdk_dbgx_edpfr_t
#define bustype_BDK_DBGX_EDPFR(...) BDK_CSR_TYPE_DAB
#define busnum_BDK_DBGX_EDPFR(p1) (p1)
#define arguments_BDK_DBGX_EDPFR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPFR(...) "DBGX_EDPFR"


/**
 * DAB32b - dbg#_edpidr0
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr0 {
	uint32_t u;
	struct bdk_dbgx_edpidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t part_0                      : 8;  /**< RO - Part number \<7:0\>.  Indicates PCC_PIDR_PARTNUM0_E::DBG. */
#else
		uint32_t part_0                      : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edpidr0_s          cn88xx; */
	/* struct bdk_dbgx_edpidr0_s          cn88xxp1; */
} bdk_dbgx_edpidr0_t;

static inline uint64_t BDK_DBGX_EDPIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR0(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FE0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR0(...) bdk_dbgx_edpidr0_t
#define bustype_BDK_DBGX_EDPIDR0(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR0(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR0(...) "DBGX_EDPIDR0"


/**
 * DAB32b - dbg#_edpidr1
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr1 {
	uint32_t u;
	struct bdk_dbgx_edpidr1_s {
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
	/* struct bdk_dbgx_edpidr1_s          cn88xx; */
	/* struct bdk_dbgx_edpidr1_s          cn88xxp1; */
} bdk_dbgx_edpidr1_t;

static inline uint64_t BDK_DBGX_EDPIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FE4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR1(...) bdk_dbgx_edpidr1_t
#define bustype_BDK_DBGX_EDPIDR1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR1(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR1(...) "DBGX_EDPIDR1"


/**
 * DAB32b - dbg#_edpidr2
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr2 {
	uint32_t u;
	struct bdk_dbgx_edpidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t des_1                       : 3;  /**< RO - JEP106 identification code \<6:4\>. Cavium code is 0x4C. */
#else
		uint32_t des_1                       : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edpidr2_s          cn88xx; */
	/* struct bdk_dbgx_edpidr2_s          cn88xxp1; */
} bdk_dbgx_edpidr2_t;

static inline uint64_t BDK_DBGX_EDPIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR2(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FE8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR2(...) bdk_dbgx_edpidr2_t
#define bustype_BDK_DBGX_EDPIDR2(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR2(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR2(...) "DBGX_EDPIDR2"


/**
 * DAB32b - dbg#_edpidr3
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr3 {
	uint32_t u;
	struct bdk_dbgx_edpidr3_s {
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
	/* struct bdk_dbgx_edpidr3_s          cn88xx; */
	/* struct bdk_dbgx_edpidr3_s          cn88xxp1; */
} bdk_dbgx_edpidr3_t;

static inline uint64_t BDK_DBGX_EDPIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR3(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FECull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR3(...) bdk_dbgx_edpidr3_t
#define bustype_BDK_DBGX_EDPIDR3(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR3(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR3(...) "DBGX_EDPIDR3"


/**
 * DAB32b - dbg#_edpidr4
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr4 {
	uint32_t u;
	struct bdk_dbgx_edpidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t size                        : 4;  /**< RO - Size of the component. RAZ. Log\<sub\>2\</sub\> of the number of
                                                                 4KB pages from the start of the component to the end of the
                                                                 component ID registers. */
		uint32_t des_2                       : 4;  /**< RO - JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else
		uint32_t des_2                       : 4;
		uint32_t size                        : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_dbgx_edpidr4_s          cn88xx; */
	/* struct bdk_dbgx_edpidr4_s          cn88xxp1; */
} bdk_dbgx_edpidr4_t;

static inline uint64_t BDK_DBGX_EDPIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR4(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FD0ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR4(...) bdk_dbgx_edpidr4_t
#define bustype_BDK_DBGX_EDPIDR4(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR4(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR4(...) "DBGX_EDPIDR4"


/**
 * DAB32b - dbg#_edpidr5
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr5 {
	uint32_t u;
	struct bdk_dbgx_edpidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_dbgx_edpidr5_s          cn88xx; */
	/* struct bdk_dbgx_edpidr5_s          cn88xxp1; */
} bdk_dbgx_edpidr5_t;

static inline uint64_t BDK_DBGX_EDPIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR5(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FD4ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR5(...) bdk_dbgx_edpidr5_t
#define bustype_BDK_DBGX_EDPIDR5(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR5(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR5(...) "DBGX_EDPIDR5"


/**
 * DAB32b - dbg#_edpidr6
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr6 {
	uint32_t u;
	struct bdk_dbgx_edpidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_dbgx_edpidr6_s          cn88xx; */
	/* struct bdk_dbgx_edpidr6_s          cn88xxp1; */
} bdk_dbgx_edpidr6_t;

static inline uint64_t BDK_DBGX_EDPIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR6(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FD8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR6(...) bdk_dbgx_edpidr6_t
#define bustype_BDK_DBGX_EDPIDR6(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR6(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR6(...) "DBGX_EDPIDR6"


/**
 * DAB32b - dbg#_edpidr7
 *
 * Provides information to identify an external debug component.
 *
 */
typedef union bdk_dbgx_edpidr7 {
	uint32_t u;
	struct bdk_dbgx_edpidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_dbgx_edpidr7_s          cn88xx; */
	/* struct bdk_dbgx_edpidr7_s          cn88xxp1; */
} bdk_dbgx_edpidr7_t;

static inline uint64_t BDK_DBGX_EDPIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR7(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000FDCull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPIDR7(...) bdk_dbgx_edpidr7_t
#define bustype_BDK_DBGX_EDPIDR7(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPIDR7(p1) (p1)
#define arguments_BDK_DBGX_EDPIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPIDR7(...) "DBGX_EDPIDR7"


/**
 * DAB32b - dbg#_edprcr
 *
 * Controls processor functionality related to powerup, reset,
 * and powerdown.
 * INTERNAL: RTL: Powerup request for ap core. This is write only register.
 * write 1 to bit[3] to request powerup.
 */
typedef union bdk_dbgx_edprcr {
	uint32_t u;
	struct bdk_dbgx_edprcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t corepurq                    : 1;  /**< R/W/H - Software write "1" to set the powerup reuqest.
                                                                 Core powerup request. Allows a debugger to request that the
                                                                     power controller power up the core, enabling access to the
                                                                     debug register in the Core power domain. The actions on
                                                                     writing to this bit are:
                                                                 In an implementation that includes the recommended external
                                                                     debug interface, this bit drives the DBGPWRUPREQ signal.
                                                                 This bit can be read and written when the Core power domain is
                                                                     powered off.
                                                                 The power controller must not allow the Core power domain to
                                                                     switch off while this bit is one.
                                                                 \<0\> No effect.
                                                                 \<1\> Request the power controller to powerup the core. */
		uint32_t reserved_2_2                : 1;
		uint32_t cwrr                        : 1;  /**< RO - Warm reset request. Write only bit that reads as zero. The
                                                                    actions on writing to this bit are:
                                                                 The processor ignores writes to this bit if any of the
                                                                    following are the case:
                                                                 ExternalInvasiveDebugEnabled() == FALSE, EL3 is not
                                                                    implemented, and the processor is Non-secure.
                                                                 ExternalSecureInvasiveDebugEnabled() == FALSE and one of the
                                                                    following is true: EL3 is implemented.  The processor is
                                                                    Secure.
                                                                 The Core power domain is either completely off or in a low-
                                                                    power state where the Core power domain registers cannot be
                                                                    accessed.
                                                                 DoubleLockStatus() == TRUE (OS double-lock is set).
                                                                 OSLSR.OSLK == 1 (OS lock is locked).
                                                                 In an implementation that includes the recommended external
                                                                    debug interface, this bit drives the DBGRSTREQ signal.
                                                                 \<0\> No action.
                                                                 \<1\> Request Warm reset. */
		uint32_t corenpdrq                   : 1;  /**< RO - Core no powerdown request. Requests emulation of powerdown.
                                                                     Possible values of this bit are:
                                                                 For more information about emulation of powerdown, see section
                                                                     10.2 ("Emulating low-power states") of the ARMv8 Debug
                                                                     Specification, PRD03-PRDC-010486.
                                                                 \<0\> On a powerdown request, the system powers down the Core power
                                                                     domain.
                                                                 \<1\> On a powerdown request, the system emulates powerdown of the
                                                                     Core power domain. In this emulation mode the Core power
                                                                     domain is not actually powered down. */
#else
		uint32_t corenpdrq                   : 1;
		uint32_t cwrr                        : 1;
		uint32_t reserved_2_2                : 1;
		uint32_t corepurq                    : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_dbgx_edprcr_s           cn88xx; */
	/* struct bdk_dbgx_edprcr_s           cn88xxp1; */
} bdk_dbgx_edprcr_t;

static inline uint64_t BDK_DBGX_EDPRCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPRCR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000310ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPRCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPRCR(...) bdk_dbgx_edprcr_t
#define bustype_BDK_DBGX_EDPRCR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPRCR(p1) (p1)
#define arguments_BDK_DBGX_EDPRCR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPRCR(...) "DBGX_EDPRCR"


/**
 * DAB32b - dbg#_edprsr
 *
 * Holds information about the reset and powerdown state of the
 *     processor.
 * RTL: Powerup status for ap core and only bit[1:0] used
 * If AP CORE power down, read to register will not generate OWB access.
 * If AP CORE power up, read to register will generate OWB access.
 */
typedef union bdk_dbgx_edprsr {
	uint32_t u;
	struct bdk_dbgx_edprsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t sdr                         : 1;  /**< RO - Sticky debug restart. Set to 1 when the processor exits Debug
                                                                     state and cleared to 0 following reads of EDPRSR.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 \<0\> The processor has not restarted since EDPRSR was last read.
                                                                 \<1\> The processor has restarted since EDPRSR was last read. */
		uint32_t spmad                       : 1;  /**< RO - Sticky EPMAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalPMUAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 \<0\> No accesses to the external performance monitors registers
                                                                     have failed since EDPRSR was last read.
                                                                 \<1\> At least one access to the external performance monitors
                                                                     registers has failed since EDPRSR was last read. */
		uint32_t epmad                       : 1;  /**< RO - External performance monitors access disable status.
                                                                 If external performance monitors access is not implemented,
                                                                     EPMAD is RAO. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1, or EDPRSR.PU is zero.
                                                                 \<0\> External performance monitors access enabled.
                                                                 \<1\> External performance monitors access disabled. */
		uint32_t sdad                        : 1;  /**< RO - Sticky EDAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalDebugAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 following a read of EDPRSR.
                                                                 \<0\> No accesses to the external debug registers have failed since
                                                                     EDPRSR was last read.
                                                                 \<1\> At least one access to the external debug registers has failed
                                                                     since EDPRSR was last read. */
		uint32_t edad                        : 1;  /**< RO - External debug access disable status.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 \<0\> External debug access enabled.
                                                                 \<1\> External debug access disabled. */
		uint32_t dlk                         : 1;  /**< RO - OS double-lock status bit.
                                                                 This bit is UNKNOWN on reads if EDPRSR.PU is zero.
                                                                 \<0\> OSDLR_EL1.DLK == 0 or EDPRCR.CORENPDRQ == 1 or the processor
                                                                     is in Debug state.
                                                                 \<1\> OSDLR_EL1.DLK == 1 and EDPRCR.CORENPDRQ == 0 and the processor
                                                                     is in Non-debug state. */
		uint32_t oslk                        : 1;  /**< RO - OS lock status bit. This bit is UNKNOWN on reads if either of
                                                                 EDPRSR.{DLK, R} is 1 or EDPRSR.PU is zero. Otherwise, a read
                                                                 returns the value of OSLSR_EL1.OSLK. */
		uint32_t halted                      : 1;  /**< RO - Halted status bit. This bit is UNKNOWN on reads if EDPRSR.PU
                                                                 is zero, 1 if EDSCR.STATUS != 0x2. */
		uint32_t sr                          : 1;  /**< RO - Sticky core reset status bit. This bit is UNKNOWN on reads if
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 This bit clears to 0 following a read of EDPRSR if the non-
                                                                     debug logic of the processor is not in reset state.
                                                                 \<0\> The non-debug logic of the processor is not in reset state and
                                                                     has not been reset since the last time EDPRSR was read.
                                                                 \<1\> The non-debug logic of the processor is in reset state or has
                                                                     been reset since the last time EDPRSR was read. */
		uint32_t r                           : 1;  /**< RO - Core reset status bit. This bit is UNKNOWN on reads if either
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 \<0\> The non-debug logic of the processor is not in reset state.
                                                                 \<1\> The non-debug logic of the processor is in reset state. */
		uint32_t spd                         : 1;  /**< RO - Sticky core power-down status bit. This bit is UNKNOWN on
                                                                     reads if both EDPRSR.DLK and EDPRSR.PU are 1.
                                                                 This bit is set to 1 on Cold reset to indicate the state of
                                                                     the debug registers has been lost. Since a Cold reset is
                                                                     required on powering up the processor, this usually indicates
                                                                     the Core power domain has been completely powered off.
                                                                 Possible values are:
                                                                 This bit clears to 0 following a read of EDPRSR if the
                                                                     processor is not in the powered down state.
                                                                 There are two logical power off states for the Core power
                                                                     domain:
                                                                 - Retention: The states of the debug registers, including
                                                                     EDPRSR.SPD, in the Core power domain is preserved, and
                                                                     restored on leaving retention state.
                                                                 - Power-down: The states of the debug registers in the Core
                                                                     power domain is lost, and a Cold reset is asserted on leaving
                                                                     power-down state.
                                                                  In these states, it is IMPLEMENTATION DEFINED whether:
                                                                  EDPRSR.SPD shows whether the state of the debug registers in
                                                                     the Core power domain has been lost since the last time EDPRSR
                                                                     was read when the Core power domain was on.
                                                                  EDPRSR.SPD reads-as-zero.
                                                                  EDPRSR.SPD is not cleared following a read of EDPRSR in these
                                                                     states.
                                                                  This means it is IMPLEMENTATION DEFINED whether a processor
                                                                     implements EDPRSR.SPD as:
                                                                  Fixed RAZ when in one or both of the retention and power-down
                                                                     states.
                                                                  Retaining its previous value when in the retention state.
                                                                  Fixed RAO in the power-down state.
                                                                  Note that this definition does not allow EDPRSR.SPD to be
                                                                     fixed RAO in the low-power retention state, as the state of
                                                                     the debug registers in the Core power domain is not lost by
                                                                     entering this state. However, the bit can be read as 1 in this
                                                                     state if the state of the registers was lost before entering
                                                                     this state (i.e. EDPRSR has not been read since the last Cold
                                                                     reset).
                                                                  ARM recommends that an implementation make EDPRSR.SPD fixed
                                                                     RAO when in the power-down state, particularly if it does not
                                                                     support a low-power retention state.
                                                                  \<0\> If the Core power domain is off (EDPRSR.PU is zero), it is not
                                                                     known whether the state of the debug registers in the Core
                                                                     power domain is lost. Otherwise, the Core power domain is on,
                                                                     and the state of the debug registers in the Core power domain
                                                                     has not been lost.
                                                                  \<1\> The state of the debug registers in the Core power domain is
                                                                     lost. */
		uint32_t pu                          : 1;  /**< RO - Core power-up status bit. Indicates whether the Core power
                                                                     domain debug registers can be accessed:
                                                                 \<0\> Core is in a low-power or power-down state where the debug
                                                                     registers cannot be accessed.
                                                                 \<1\> Core is in a power-up state where the debug registers can be
                                                                     accessed. */
#else
		uint32_t pu                          : 1;
		uint32_t spd                         : 1;
		uint32_t r                           : 1;
		uint32_t sr                          : 1;
		uint32_t halted                      : 1;
		uint32_t oslk                        : 1;
		uint32_t dlk                         : 1;
		uint32_t edad                        : 1;
		uint32_t sdad                        : 1;
		uint32_t epmad                       : 1;
		uint32_t spmad                       : 1;
		uint32_t sdr                         : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_dbgx_edprsr_s           cn88xx; */
	/* struct bdk_dbgx_edprsr_s           cn88xxp1; */
} bdk_dbgx_edprsr_t;

static inline uint64_t BDK_DBGX_EDPRSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPRSR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000314ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDPRSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDPRSR(...) bdk_dbgx_edprsr_t
#define bustype_BDK_DBGX_EDPRSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDPRSR(p1) (p1)
#define arguments_BDK_DBGX_EDPRSR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDPRSR(...) "DBGX_EDPRSR"


/**
 * DAB32b - dbg#_edrcr
 *
 * This register is used to allow imprecise entry to Debug state
 * and clear sticky bits in EDSCR.
 */
typedef union bdk_dbgx_edrcr {
	uint32_t u;
	struct bdk_dbgx_edrcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t cbrrq                       : 1;  /**< RO - Allow imprecise entry to Debug state. The actions on writing
                                                                     to this bit are:
                                                                 Setting this bit to 1 allows a debugger to request imprecise
                                                                     entry to Debug state. An External Debug Request debug event
                                                                     must be pending before the debugger sets this bit to 1.
                                                                 This feature is optional. If this feature is not implemented,
                                                                     writes to this bit are ignored.
                                                                 \<0\> No action.
                                                                 \<1\> Allow imprecise entry to Debug state, for example by canceling
                                                                     pending bus accesses. */
		uint32_t cspa                        : 1;  /**< RO - Clear Sticky Pipeline Advance. This bit is used to clear the
                                                                     EDSCR.PipeAdv bit to 0. The actions on writing to this bit
                                                                     are:
                                                                 \<0\> No action.
                                                                 \<1\> Clear the EDSCR.PipeAdv bit to 0. */
		uint32_t cse                         : 1;  /**< RO - Clear Sticky Error. Used to clear the EDSCR cumulative error
                                                                     bits to 0. The actions on writing to this bit are:
                                                                 \<0\> No action.
                                                                 \<1\> Clear the EDSCR.{TXU, RXO, ERR} bits, and, if the processor is
                                                                     in Debug state, the EDSCR.ITO bit, to 0. */
		uint32_t reserved_0_1                : 2;
#else
		uint32_t reserved_0_1                : 2;
		uint32_t cse                         : 1;
		uint32_t cspa                        : 1;
		uint32_t cbrrq                       : 1;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	/* struct bdk_dbgx_edrcr_s            cn88xx; */
	/* struct bdk_dbgx_edrcr_s            cn88xxp1; */
} bdk_dbgx_edrcr_t;

static inline uint64_t BDK_DBGX_EDRCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDRCR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000090ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDRCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDRCR(...) bdk_dbgx_edrcr_t
#define bustype_BDK_DBGX_EDRCR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDRCR(p1) (p1)
#define arguments_BDK_DBGX_EDRCR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDRCR(...) "DBGX_EDRCR"


/**
 * DAB32b - dbg#_edscr
 *
 * Main control register for the debug implementation.
 *
 */
typedef union bdk_dbgx_edscr {
	uint32_t u;
	struct bdk_dbgx_edscr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t rxfull                      : 1;  /**< R/W - DTRRX full. This bit is RO. */
		uint32_t txfull                      : 1;  /**< R/W - DTRTX full. This bit is RO. */
		uint32_t ito                         : 1;  /**< R/W - EDITR overrun. This bit is RO.
                                                                 If the processor is not in Debug state, this bit is UNKNOWN.
                                                                     ITO is set to 0 on entry to Debug state. */
		uint32_t rxo                         : 1;  /**< R/W - DTRRX overrun. This bit is RO. */
		uint32_t txu                         : 1;  /**< R/W - DTRTX underrun. This bit is RO. */
		uint32_t pipeadv                     : 1;  /**< R/W - Pipeline advance. Read-only. Set to 1 every time the processor
                                                                     pipeline retires one or more instructions. Cleared to 0 by a
                                                                     write to EDRCR.CSPA.
                                                                 The architecture does not define precisely when this bit is
                                                                     set to 1. It requires only that this happen periodically in
                                                                     Non-debug state to indicate that software execution is
                                                                     progressing. */
		uint32_t ite                         : 1;  /**< R/W - ITR empty. This bit is RO.
                                                                 If the processor is not in Debug state, this bit is UNKNOWN.
                                                                     It is always valid in Debug state. */
		uint32_t intdis                      : 2;  /**< R/W - Interrupt disable. Disables taking interrupts (including
                                                                     virtual interrupts and System Error interrupts) in Non-Debug
                                                                     state.
                                                                 If external invasive debug is disabled, the value of this
                                                                     field is ignored.
                                                                 If external invasive debug is enabled, the possible values of
                                                                     this field are:
                                                                 The value of INTdis does not affect whether an interrupt is a
                                                                     WFI wake-up event, but can mask an interrupt as a WFE wake-up
                                                                     event.
                                                                 If EL3 and EL2 are not implemented, INTdis[0] is RO and reads
                                                                     the same value as INTdis[1], meaning only the values0b000b11
                                                                 \<00\>        Do not disable interrupts
                                                                 \<01\>        Disable interrupts targeting Non-secure EL1.
                                                                 \<10\>        Disable interrupts targeting only Non-secure EL1 and Non-
                                                                     secure EL2. If external secure invasive debug is enabled, also
                                                                     disable interrupts targeting Secure EL1.
                                                                 \<11\>        Disable interrupts targeting only Non-secure EL1 and Non-
                                                                     secure EL2. If external secure invasive debug is enabled, also
                                                                     disable all other interrupts. */
		uint32_t tda                         : 1;  /**< R/W - Trap debug registers accesses. */
		uint32_t ma                          : 1;  /**< R/W - Memory access mode. Controls use of memory-access mode for
                                                                     accessing EDITR and the DCC. This bit is ignored if in Non-
                                                                     debug state and set to zero on entry to Debug state.
                                                                 Possible values of this field are:
                                                                 \<0\> Normal access mode
                                                                 \<1\> Memory access mode. */
		uint32_t reserved_19_19              : 1;
		uint32_t non_secure                  : 1;  /**< R/W - Non-secure status. Read-only. When in Debug state, gives the
                                                                     current security state:
                                                                 In Non-debug state, this bit is UNKNOWN.
                                                                 \<0\> Secure state, IsSecure() == TRUE
                                                                 \<1\> Non-secure state, IsSecure() == FALSE. */
		uint32_t reserved_17_17              : 1;
		uint32_t sdd                         : 1;  /**< R/W - Secure debug disabled. This bit is RO.
                                                                 On entry to Debug state:
                                                                  If entering in Secure state, SDD is set to 0.
                                                                  If entering in Non-secure state, SDD is set to the inverse of
                                                                     ExternalSecureInvasiveDebugEnabled().
                                                                 In Debug state, the value of the SDD bit does not change, even
                                                                     if ExternalSecureInvasiveDebugEnabled() changes.
                                                                 In Non-debug state:
                                                                  SDD returns the inverse of
                                                                     ExternalSecureInvasiveDebugEnabled(). If the authentication
                                                                     signals that control ExternalSecureInvasiveDebugEnabled()
                                                                     change, a context synchronization operation is required to
                                                                     guarantee their effect.
                                                                  This bit is unaffected by the Security state of the
                                                                     processor.
                                                                 If EL3 is not implemented and the implementation is Non-
                                                                     secure, this bit is RES1. */
		uint32_t reserved_15_15              : 1;
		uint32_t hde                         : 1;  /**< R/W - Halting debug mode enable. Possible values of this bit are:
                                                                 \<0\> Halting debug mode disabled.
                                                                 \<1\> Halting debug mode enabled. */
		uint32_t rw                          : 4;  /**< R/W - Exception level register-width status. Read-only. In Debug
                                                                     state, each bit gives the current register width status of
                                                                     each EL:
                                                                 However:
                                                                  If not at EL0: RW[0] == RW[1].
                                                                  If EL2 is not implemented in the current security state:
                                                                     RW[2] == RW[1].
                                                                  If EL3 is not implemented: RW[3] == RW[2].
                                                                 In Non-debug state, this field is RAO.
                                                                 \<1111\>      All exception levels are AArch64 state.
                                                                 \<1110\>      EL0 is AArch32 state. All other exception levels are AArch64
                                                                     state.
                                                                 \<1100\>      EL0 and EL1 are AArch32 state. All other exception levels are
                                                                     AArch64 state. Never seen if EL2 is not implemented in the
                                                                     current security state.
                                                                 \<1000\>      EL0, EL1, and, if implemented in the current security state,
                                                                     EL2 are AArch32 state. All other exception levels are AArch64
                                                                     state.
                                                                 \<0000\>      All exception levels are set to AArch32 state (32-bit
                                                                     configuration). */
		uint32_t el                          : 2;  /**< R/W - Exception level. Read-only. In Debug state, this gives the
                                                                     current EL of the processor.
                                                                 In Non-debug state, this field is RAZ. */
		uint32_t aa                          : 1;  /**< R/W - System Error interrupt (asynchronous abort) pending. Read-
                                                                     only. In Debug state, indicates whether a SError interrupt is
                                                                     pending:
                                                                  If HCR_EL2.{AMO, TGE} = {1, 0} and in Non-secure EL0 or EL1,
                                                                     a virtual SError interrupt.
                                                                  Otherwise, a physical SError interrupt.
                                                                 A debugger can read EDSCR to check whether a SError interrupt
                                                                     is pending without having to execute further instructions. A
                                                                     pending SError might indicate data from target memory is
                                                                     corrupted.
                                                                  UNKNOWN in Non-debug state.
                                                                 \<0\> No SError interrupt pending.
                                                                 \<1\> SError interrupt pending. */
		uint32_t errflg                      : 1;  /**< R/W - Cumulative error flag. This field is RO. It is set to 1
                                                                 following exceptions in Debug state and on any signaled
                                                                 overrun or underrun on the DTR or EDITR. */
		uint32_t status                      : 6;  /**< R/W - Debug status flags. This field is RO.
                                                                 The possible values of this field are:
                                                                 All other values of STATUS are reserved.
                                                                 \<000010\>    Processor is in Non-debug state.
                                                                 \<000001\>    Processor is restarting (exiting Debug state).
                                                                 \<000111\>    Breakpoint.
                                                                 \<010011\>    External debug request.
                                                                 \<011011\>    Halting step, normal.
                                                                 \<011111\>    Halting step, exclusive.
                                                                 \<100011\>    OS unlock catch.
                                                                 \<100111\>    Reset catch.
                                                                 \<101011\>    Watchpoint.
                                                                 \<101111\>    HLT instruction.
                                                                 \<110011\>    Software access to debug register.
                                                                 \<110111\>    Exception catch.
                                                                 \<111011\>    Halting step, no syndrome. */
#else
		uint32_t status                      : 6;
		uint32_t errflg                      : 1;
		uint32_t aa                          : 1;
		uint32_t el                          : 2;
		uint32_t rw                          : 4;
		uint32_t hde                         : 1;
		uint32_t reserved_15_15              : 1;
		uint32_t sdd                         : 1;
		uint32_t reserved_17_17              : 1;
		uint32_t non_secure                  : 1;
		uint32_t reserved_19_19              : 1;
		uint32_t ma                          : 1;
		uint32_t tda                         : 1;
		uint32_t intdis                      : 2;
		uint32_t ite                         : 1;
		uint32_t pipeadv                     : 1;
		uint32_t txu                         : 1;
		uint32_t rxo                         : 1;
		uint32_t ito                         : 1;
		uint32_t txfull                      : 1;
		uint32_t rxfull                      : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_dbgx_edscr_s            cn88xx; */
	/* struct bdk_dbgx_edscr_s            cn88xxp1; */
} bdk_dbgx_edscr_t;

static inline uint64_t BDK_DBGX_EDSCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDSCR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000088ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDSCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDSCR(...) bdk_dbgx_edscr_t
#define bustype_BDK_DBGX_EDSCR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDSCR(p1) (p1)
#define arguments_BDK_DBGX_EDSCR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDSCR(...) "DBGX_EDSCR"


/**
 * DAB32b - dbg#_edvidsr
 *
 * Contains sampled values captured on reading EDPCSR.
 *
 */
typedef union bdk_dbgx_edvidsr {
	uint32_t u;
	struct bdk_dbgx_edvidsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t non_secure                  : 1;  /**< RO - Non-secure state sample. Indicates the security state
                                                                 associated with the most recent EDPCSR sample. */
		uint32_t e2                          : 1;  /**< RO - Exception level 2 status sample. Indicates whether the most
                                                                 recent EDPCSR sample was associated with EL2. If EDVIDSR.NS ==
                                                                 0, this bit is 0. */
		uint32_t e3                          : 1;  /**< RO - Exception level 3 status sample. Indicates whether the most
                                                                 recent EDPCSR sample was associated with AArch64 EL3. If
                                                                 EDVIDSR.NS == 1 or the processor was in AArch32 state when
                                                                 EDPCSR was read, this bit is 0. */
		uint32_t hv                          : 1;  /**< RO - EDPCSR high half valid. Indicates whether bits [63:32] of the
                                                                 most recent EDPCSR sample are valid. If EDVIDSR.HV == 0, the
                                                                 value of EDPCSR[63:32] is RAZ. */
		uint32_t reserved_8_27               : 20;
		uint32_t vmid                        : 8;  /**< RO - VMID sample. The value of VTTBR_EL2.VMID associated with the
                                                                 most recent EDPCSR sample. If EDVIDSR.NS == 0 or EDVIDSR.E2 ==
                                                                 1, this field is RAZ. */
#else
		uint32_t vmid                        : 8;
		uint32_t reserved_8_27               : 20;
		uint32_t hv                          : 1;
		uint32_t e3                          : 1;
		uint32_t e2                          : 1;
		uint32_t non_secure                  : 1;
#endif
	} s;
	/* struct bdk_dbgx_edvidsr_s          cn88xx; */
	/* struct bdk_dbgx_edvidsr_s          cn88xxp1; */
} bdk_dbgx_edvidsr_t;

static inline uint64_t BDK_DBGX_EDVIDSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDVIDSR(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A0080000A8ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDVIDSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDVIDSR(...) bdk_dbgx_edvidsr_t
#define bustype_BDK_DBGX_EDVIDSR(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDVIDSR(p1) (p1)
#define arguments_BDK_DBGX_EDVIDSR(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDVIDSR(...) "DBGX_EDVIDSR"


/**
 * DAB32b - dbg#_edwar_hi
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_edwar_hi {
	uint32_t u;
	struct bdk_dbgx_edwar_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t address                     : 32; /**< RO - FIXME */
#else
		uint32_t address                     : 32;
#endif
	} s;
	/* struct bdk_dbgx_edwar_hi_s         cn88xx; */
	/* struct bdk_dbgx_edwar_hi_s         cn88xxp1; */
} bdk_dbgx_edwar_hi_t;

static inline uint64_t BDK_DBGX_EDWAR_HI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDWAR_HI(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000034ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDWAR_HI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDWAR_HI(...) bdk_dbgx_edwar_hi_t
#define bustype_BDK_DBGX_EDWAR_HI(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDWAR_HI(p1) (p1)
#define arguments_BDK_DBGX_EDWAR_HI(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDWAR_HI(...) "DBGX_EDWAR_HI"


/**
 * DAB32b - dbg#_edwar_lo
 *
 * FIXME
 *
 */
typedef union bdk_dbgx_edwar_lo {
	uint32_t u;
	struct bdk_dbgx_edwar_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t address                     : 32; /**< RO - FIXME */
#else
		uint32_t address                     : 32;
#endif
	} s;
	/* struct bdk_dbgx_edwar_lo_s         cn88xx; */
	/* struct bdk_dbgx_edwar_lo_s         cn88xxp1; */
} bdk_dbgx_edwar_lo_t;

static inline uint64_t BDK_DBGX_EDWAR_LO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDWAR_LO(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000030ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_EDWAR_LO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_EDWAR_LO(...) bdk_dbgx_edwar_lo_t
#define bustype_BDK_DBGX_EDWAR_LO(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_EDWAR_LO(p1) (p1)
#define arguments_BDK_DBGX_EDWAR_LO(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_EDWAR_LO(...) "DBGX_EDWAR_LO"


/**
 * DAB32b - dbg#_midr_el1
 *
 * Main id register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union bdk_dbgx_midr_el1 {
	uint32_t u;
	struct bdk_dbgx_midr_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t implementer                 : 8;  /**< RO - Implementor field.
                                                                 The Implementer code. This field must hold an implementer code
                                                                     that has been assigned by ARM. Assigned codes include the
                                                                     following:

                                                                 \<pre\>
                                                                 Hex    ASCII  Implementer
                                                                 0x41    A     ARM Limited
                                                                 0x42    B     Broadcom Corporation
                                                                 0x43    C     Cavium Inc.
                                                                 0x44    D     Digital Equipment Corporation
                                                                 0x49    I     Infineon Technologies AG
                                                                 0x4D    M     Motorola or Freescale Semiconductor Inc.
                                                                 0x4E    N     NVIDIA Corporation
                                                                 0x50    P     Applied Micro Circuits Corporation
                                                                 0x51    Q     Qualcomm Inc.
                                                                 0x56    V     Marvell International Ltd.
                                                                 0x69    i     Intel Corporation
                                                                 \</pre\>

                                                                 ARM can assign codes that are not published in this manual.
                                                                     All values not assigned by ARM are reserved and must not be
                                                                     used. */
		uint32_t variant                     : 4;  /**< RO - Variant field.
                                                                 An implementation defined variant number. Typically, this
                                                                     field is used to distinguish between different product
                                                                     variants, or major revisions of a product.
                                                                 In CNXXXX, the major pass number. */
		uint32_t architecture                : 4;  /**< RO - Architecure field.
                                                                 The permitted values of this field are:
                                                                 All other values are reserved.
                                                                 \<0001\>      ARMv4
                                                                 \<0010\>      ARMv4T
                                                                 \<0011\>      ARMv5 (obsolete)
                                                                 \<0100\>      ARMv5T
                                                                 \<0101\>      ARMv5TE
                                                                 \<0110\>      ARMv5TEJ
                                                                 \<0111\>      ARMv6
                                                                 \<1111\>      Defined by CPUID scheme */
		uint32_t partnum                     : 12; /**< RO - Part number field.
                                                                 An implementation defined primary part number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
		uint32_t revision                    : 4;  /**< RO - Revision field.
                                                                 An implementation defined revision number for the device.
                                                                 In CNXXXX, the minor pass number. */
#else
		uint32_t revision                    : 4;
		uint32_t partnum                     : 12;
		uint32_t architecture                : 4;
		uint32_t variant                     : 4;
		uint32_t implementer                 : 8;
#endif
	} s;
	/* struct bdk_dbgx_midr_el1_s         cn88xx; */
	/* struct bdk_dbgx_midr_el1_s         cn88xxp1; */
} bdk_dbgx_midr_el1_t;

static inline uint64_t BDK_DBGX_MIDR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_MIDR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000D00ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_MIDR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_MIDR_EL1(...) bdk_dbgx_midr_el1_t
#define bustype_BDK_DBGX_MIDR_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_MIDR_EL1(p1) (p1)
#define arguments_BDK_DBGX_MIDR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_MIDR_EL1(...) "DBGX_MIDR_EL1"


/**
 * DAB32b - dbg#_oslar_el1
 *
 * Used to lock or unlock the OS lock.
 *
 */
typedef union bdk_dbgx_oslar_el1 {
	uint32_t u;
	struct bdk_dbgx_oslar_el1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t oslk                        : 1;  /**< RO - On writes to OSLAR_EL1, bit[0] is copied to the OS lock.
                                                                 Use EDPRSR.OSLK to check the current status of the lock. */
#else
		uint32_t oslk                        : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_dbgx_oslar_el1_s        cn88xx; */
	/* struct bdk_dbgx_oslar_el1_s        cn88xxp1; */
} bdk_dbgx_oslar_el1_t;

static inline uint64_t BDK_DBGX_OSLAR_EL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_OSLAR_EL1(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087A008000300ull + (param1 & 63) * 0x80000ull;
	csr_fatal("BDK_DBGX_OSLAR_EL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_DBGX_OSLAR_EL1(...) bdk_dbgx_oslar_el1_t
#define bustype_BDK_DBGX_OSLAR_EL1(...) BDK_CSR_TYPE_DAB32b
#define busnum_BDK_DBGX_OSLAR_EL1(p1) (p1)
#define arguments_BDK_DBGX_OSLAR_EL1(p1) (p1),-1,-1,-1
#define basename_BDK_DBGX_OSLAR_EL1(...) "DBGX_OSLAR_EL1"

#endif /* __BDK_CSRS_DAB_DBG__ */
