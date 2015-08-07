#ifndef __BDK_CSRS_DAB_DBG_H__
#define __BDK_CSRS_DAB_DBG_H__
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
 * Cavium DAB_DBG.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Register (DAB32b) dab_rom_table#
 *
 * ROM table for DAP Register
 * The ROM table is for Coresight ROM
 */
typedef union
{
    uint32_t u;
    struct bdk_dab_rom_tablex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dab_rom_tablex_s cn; */
} bdk_dab_rom_tablex_t;

static inline uint64_t BDK_DAB_ROM_TABLEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAB_ROM_TABLEX(unsigned long a)
{
    if (a<=1023)
        return 0x87a000000000ll + 4ll * ((a) & 0x3ff);
    __bdk_csr_fatal("DAB_ROM_TABLEX", 1, a, 0, 0, 0);
}

#define typedef_BDK_DAB_ROM_TABLEX(a) bdk_dab_rom_tablex_t
#define bustype_BDK_DAB_ROM_TABLEX(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DAB_ROM_TABLEX(a) "DAB_ROM_TABLEX"
#define busnum_BDK_DAB_ROM_TABLEX(a) (a)
#define arguments_BDK_DAB_ROM_TABLEX(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_dbgauthstatus_el1
 *
 * AP DBG Authentication Status Register
 * Debug Authentication Status register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgauthstatus_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t snid                  : 2;  /**< [  7:  6](RO/H) Secure non-invasive debug. Possible values of this field are:
                                                                 Other values are reserved.  For CNXXXX allowed values of 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Non-secure.
                                                                 <10>        Implemented and disabled.
                                                                     ExternalSecureNoninvasiveDebugEnabled() == FALSE.
                                                                 <11>        Implemented and enabled.
                                                                     ExternalSecureNoninvasiveDebugEnabled() == TRUE.
                                                                 RTL: SNID[1]=1, SNID[0]=(SPIDEN || SPNIDEN) && (NIDEN || DBGEN). */
        uint32_t sid                   : 2;  /**< [  5:  4](RO/H) Secure invasive debug. Possible values of this field are:
                                                                 Other values are reserved.  For CNXXXX allowed values are 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Non-secure.
                                                                 <10>        Implemented and disabled. ExternalSecureInvasiveDebugEnabled()
                                                                     == FALSE.
                                                                 <11>        Implemented and enabled. ExternalSecureInvasiveDebugEnabled()
                                                                     == TRUE.
                                                                 RTL: SID[1]=1, SID[0]=(SPIDEN || DBGEN). */
        uint32_t nsnid                 : 2;  /**< [  3:  2](RO/H) Non-secure non-invasive debug. Possible values of this field
                                                                     are:
                                                                 Other values are reserved.  For CNXXXX allowed values are 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 <10>        Implemented and disabled. ExternalNoninvasiveDebugEnabled() ==
                                                                     FALSE.
                                                                 <11>        Implemented and enabled. ExternalNoninvasiveDebugEnabled() ==
                                                                     TRUE.
                                                                 RTL: NSNID[1]=1, NSNID[0]=(NIDEN || DBGEN). */
        uint32_t nsid                  : 2;  /**< [  1:  0](RO/H) Non-secure invasive debug. Possible values of this field are:
                                                                 Other values are reserved.  For CNXXXX allowed values are 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 <10>        Implemented and disabled. ExternalInvasiveDebugEnabled() ==
                                                                     FALSE.
                                                                 <11>        Implemented and enabled. ExternalInvasiveDebugEnabled() ==
                                                                     TRUE.
                                                                 RTL: NSID[1]=1, NSID[0]= DBGEN. */
#else /* Word 0 - Little Endian */
        uint32_t nsid                  : 2;  /**< [  1:  0](RO/H) Non-secure invasive debug. Possible values of this field are:
                                                                 Other values are reserved.  For CNXXXX allowed values are 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 <10>        Implemented and disabled. ExternalInvasiveDebugEnabled() ==
                                                                     FALSE.
                                                                 <11>        Implemented and enabled. ExternalInvasiveDebugEnabled() ==
                                                                     TRUE.
                                                                 RTL: NSID[1]=1, NSID[0]= DBGEN. */
        uint32_t nsnid                 : 2;  /**< [  3:  2](RO/H) Non-secure non-invasive debug. Possible values of this field
                                                                     are:
                                                                 Other values are reserved.  For CNXXXX allowed values are 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Secure.
                                                                 <10>        Implemented and disabled. ExternalNoninvasiveDebugEnabled() ==
                                                                     FALSE.
                                                                 <11>        Implemented and enabled. ExternalNoninvasiveDebugEnabled() ==
                                                                     TRUE.
                                                                 RTL: NSNID[1]=1, NSNID[0]=(NIDEN || DBGEN). */
        uint32_t sid                   : 2;  /**< [  5:  4](RO/H) Secure invasive debug. Possible values of this field are:
                                                                 Other values are reserved.  For CNXXXX allowed values are 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Non-secure.
                                                                 <10>        Implemented and disabled. ExternalSecureInvasiveDebugEnabled()
                                                                     == FALSE.
                                                                 <11>        Implemented and enabled. ExternalSecureInvasiveDebugEnabled()
                                                                     == TRUE.
                                                                 RTL: SID[1]=1, SID[0]=(SPIDEN || DBGEN). */
        uint32_t snid                  : 2;  /**< [  7:  6](RO/H) Secure non-invasive debug. Possible values of this field are:
                                                                 Other values are reserved.  For CNXXXX allowed values of 0x2 and 0x3.
                                                                 <00>        Not implemented. EL3 is not implemented and the processor is
                                                                     Non-secure.
                                                                 <10>        Implemented and disabled.
                                                                     ExternalSecureNoninvasiveDebugEnabled() == FALSE.
                                                                 <11>        Implemented and enabled.
                                                                     ExternalSecureNoninvasiveDebugEnabled() == TRUE.
                                                                 RTL: SNID[1]=1, SNID[0]=(SPIDEN || SPNIDEN) && (NIDEN || DBGEN). */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgauthstatus_el1_s cn; */
} bdk_dbgx_dbgauthstatus_el1_t;

static inline uint64_t BDK_DBGX_DBGAUTHSTATUS_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGAUTHSTATUS_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fb8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_DBGAUTHSTATUS_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_DBGAUTHSTATUS_EL1(a) bdk_dbgx_dbgauthstatus_el1_t
#define bustype_BDK_DBGX_DBGAUTHSTATUS_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGAUTHSTATUS_EL1(a) "DBGX_DBGAUTHSTATUS_EL1"
#define busnum_BDK_DBGX_DBGAUTHSTATUS_EL1(a) (a)
#define arguments_BDK_DBGX_DBGAUTHSTATUS_EL1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_dbgbcr#_el1
 *
 * AP DBG Debug Breakpoint Control Registers
 * Holds control information for a breakpoint. Forms breakpoint n
 *     together with value register DBGBVR<n>_EL1, where n is 0 to
 *     5.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgbcrx_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t bt                    : 4;  /**< [ 23: 20](R/W) Breakpoint Type. Possible values are:
                                                                 The field breaks down as follows:
                                                                  BT[3:1]: Base type.- 000: Match address. DBGBVR<n>_EL1 is the
                                                                     address of an     instruction. - 010: Mismatch address.
                                                                     Behaves as type0b000 DBGBVR<n>_EL1 is     the address of an
                                                                     instruction to be stepped. - 001: Match context ID.
                                                                     DBGBVR<n>_EL1[31:0] is a context ID. - 100: Match VMID.
                                                                     DBGBVR<n>_EL1[39:32] is a VMID. - 101: Match VMID and context
                                                                     ID. DBGBVR<n>_EL1[31:0] is a     context ID, and
                                                                     DBGBVR<n>_EL1[39:32] is a VMID.
                                                                  BT[0]: Enable linking.
                                                                 If the breakpoint is not context-aware, BT[3] and BT[1] are
                                                                     RAZ. If EL2 is not implemented, BT[3] is RAZ. If EL1 using
                                                                     AArch32 is not implemented, BT[2] is RAZ.
                                                                 The values0b011x0b11xx
                                                                 <0000>      Unlinked instruction address match.
                                                                 <0001>      Linked instruction address match.
                                                                 <0010>      Unlinked context ID match.
                                                                 <0011>      Linked context ID match
                                                                 <0100>      Unlinked instruction address mismatch.
                                                                 <0101>      Linked instruction address mismatch.
                                                                 <1000>      Unlinked VMID match.
                                                                 <1001>      Linked VMID match.
                                                                 <1010>      Unlinked VMID and context ID match.
                                                                 <1011>      Linked VMID and context ID match. */
        uint32_t lbn                   : 4;  /**< [ 19: 16](R/W) Linked breakpoint number. For Linked address matching
                                                                     breakpoints, this specifies the index of the Context-matching
                                                                     breakpoint linked to.  For non-linked breakpoints, this field is ignored. */
        uint32_t ssc                   : 2;  /**< [ 15: 14](R/W) Security state control. Determines the security states under
                                                                     which a breakpoint debug event for breakpoint n is generated.
                                                                     This field must be interpreted along with the HMC and PMC
                                                                     fields. Possible values are summarised in the "Processor state
                                                                     matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t hmc                   : 1;  /**< [ 13: 13](R/W) Higher mode control. Determines the debug perspective for
                                                                     deciding when a breakpoint debug event for breakpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and PMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t reserved_9_12         : 4;
        uint32_t bas                   : 4;  /**< [  8:  5](RO) Byte address select. Defines which half-words an address-
                                                                     matching breakpoint matches, regardless of the instruction set
                                                                     and execution state. In CNXXXX this field is reserved, RES1.

                                                                 For Context matching breakpoints, this field is RES1 and
                                                                     ignored. */
        uint32_t reserved_3_4          : 2;
        uint32_t pmc                   : 2;  /**< [  2:  1](R/W) Privilege mode control. Determines the exception level or
                                                                     levels at which a breakpoint debug event for breakpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and HMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable breakpoint DBGBVR<n>_EL1. Possible values are:
                                                                 <0> Breakpoint disabled.
                                                                 <1> Breakpoint enabled. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable breakpoint DBGBVR<n>_EL1. Possible values are:
                                                                 <0> Breakpoint disabled.
                                                                 <1> Breakpoint enabled. */
        uint32_t pmc                   : 2;  /**< [  2:  1](R/W) Privilege mode control. Determines the exception level or
                                                                     levels at which a breakpoint debug event for breakpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and HMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t reserved_3_4          : 2;
        uint32_t bas                   : 4;  /**< [  8:  5](RO) Byte address select. Defines which half-words an address-
                                                                     matching breakpoint matches, regardless of the instruction set
                                                                     and execution state. In CNXXXX this field is reserved, RES1.

                                                                 For Context matching breakpoints, this field is RES1 and
                                                                     ignored. */
        uint32_t reserved_9_12         : 4;
        uint32_t hmc                   : 1;  /**< [ 13: 13](R/W) Higher mode control. Determines the debug perspective for
                                                                     deciding when a breakpoint debug event for breakpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and PMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t ssc                   : 2;  /**< [ 15: 14](R/W) Security state control. Determines the security states under
                                                                     which a breakpoint debug event for breakpoint n is generated.
                                                                     This field must be interpreted along with the HMC and PMC
                                                                     fields. Possible values are summarised in the "Processor state
                                                                     matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t lbn                   : 4;  /**< [ 19: 16](R/W) Linked breakpoint number. For Linked address matching
                                                                     breakpoints, this specifies the index of the Context-matching
                                                                     breakpoint linked to.  For non-linked breakpoints, this field is ignored. */
        uint32_t bt                    : 4;  /**< [ 23: 20](R/W) Breakpoint Type. Possible values are:
                                                                 The field breaks down as follows:
                                                                  BT[3:1]: Base type.- 000: Match address. DBGBVR<n>_EL1 is the
                                                                     address of an     instruction. - 010: Mismatch address.
                                                                     Behaves as type0b000 DBGBVR<n>_EL1 is     the address of an
                                                                     instruction to be stepped. - 001: Match context ID.
                                                                     DBGBVR<n>_EL1[31:0] is a context ID. - 100: Match VMID.
                                                                     DBGBVR<n>_EL1[39:32] is a VMID. - 101: Match VMID and context
                                                                     ID. DBGBVR<n>_EL1[31:0] is a     context ID, and
                                                                     DBGBVR<n>_EL1[39:32] is a VMID.
                                                                  BT[0]: Enable linking.
                                                                 If the breakpoint is not context-aware, BT[3] and BT[1] are
                                                                     RAZ. If EL2 is not implemented, BT[3] is RAZ. If EL1 using
                                                                     AArch32 is not implemented, BT[2] is RAZ.
                                                                 The values0b011x0b11xx
                                                                 <0000>      Unlinked instruction address match.
                                                                 <0001>      Linked instruction address match.
                                                                 <0010>      Unlinked context ID match.
                                                                 <0011>      Linked context ID match
                                                                 <0100>      Unlinked instruction address mismatch.
                                                                 <0101>      Linked instruction address mismatch.
                                                                 <1000>      Unlinked VMID match.
                                                                 <1001>      Linked VMID match.
                                                                 <1010>      Unlinked VMID and context ID match.
                                                                 <1011>      Linked VMID and context ID match. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgbcrx_el1_s cn; */
} bdk_dbgx_dbgbcrx_el1_t;

static inline uint64_t BDK_DBGX_DBGBCRX_EL1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGBCRX_EL1(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008000408ll + 0x80000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x7);
    __bdk_csr_fatal("DBGX_DBGBCRX_EL1", 2, a, b, 0, 0);
}

#define typedef_BDK_DBGX_DBGBCRX_EL1(a,b) bdk_dbgx_dbgbcrx_el1_t
#define bustype_BDK_DBGX_DBGBCRX_EL1(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGBCRX_EL1(a,b) "DBGX_DBGBCRX_EL1"
#define busnum_BDK_DBGX_DBGBCRX_EL1(a,b) (a)
#define arguments_BDK_DBGX_DBGBCRX_EL1(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) dbg#_dbgbvr#_el1_hi
 *
 * AP DBG Debug Breakpoint Value High Registers
 * Accesses the high bits of the breakpoint value.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgbvrx_el1_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgbvrx_el1_hi_s cn; */
} bdk_dbgx_dbgbvrx_el1_hi_t;

static inline uint64_t BDK_DBGX_DBGBVRX_EL1_HI(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGBVRX_EL1_HI(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008000404ll + 0x80000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x7);
    __bdk_csr_fatal("DBGX_DBGBVRX_EL1_HI", 2, a, b, 0, 0);
}

#define typedef_BDK_DBGX_DBGBVRX_EL1_HI(a,b) bdk_dbgx_dbgbvrx_el1_hi_t
#define bustype_BDK_DBGX_DBGBVRX_EL1_HI(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGBVRX_EL1_HI(a,b) "DBGX_DBGBVRX_EL1_HI"
#define busnum_BDK_DBGX_DBGBVRX_EL1_HI(a,b) (a)
#define arguments_BDK_DBGX_DBGBVRX_EL1_HI(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) dbg#_dbgbvr#_el1_lo
 *
 * AP DBG Debug Breakpoint Value Low Registers
 * Accesses the low bits of the breakpoint value.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgbvrx_el1_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgbvrx_el1_lo_s cn; */
} bdk_dbgx_dbgbvrx_el1_lo_t;

static inline uint64_t BDK_DBGX_DBGBVRX_EL1_LO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGBVRX_EL1_LO(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008000400ll + 0x80000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x7);
    __bdk_csr_fatal("DBGX_DBGBVRX_EL1_LO", 2, a, b, 0, 0);
}

#define typedef_BDK_DBGX_DBGBVRX_EL1_LO(a,b) bdk_dbgx_dbgbvrx_el1_lo_t
#define bustype_BDK_DBGX_DBGBVRX_EL1_LO(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGBVRX_EL1_LO(a,b) "DBGX_DBGBVRX_EL1_LO"
#define busnum_BDK_DBGX_DBGBVRX_EL1_LO(a,b) (a)
#define arguments_BDK_DBGX_DBGBVRX_EL1_LO(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) dbg#_dbgclaimclr_el1
 *
 * AP DBG Debug Claim Tag Clear Register
 * Used by software to read the values of the CLAIM bits, and to
 *     clear these bits to 0.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgclaimclr_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t claim                 : 8;  /**< [  7:  0](R/W) Claim clear bits. Reading this field returns the current value
                                                                     of the CLAIM bits.
                                                                 Writing a 1 to one of these bits clears the corresponding
                                                                     CLAIM bit to 0. This is an indirect write to the CLAIM bits.
                                                                 A single write operation can clear multiple bits to 0. Writing
                                                                     0 to one of these bits has no effect. */
#else /* Word 0 - Little Endian */
        uint32_t claim                 : 8;  /**< [  7:  0](R/W) Claim clear bits. Reading this field returns the current value
                                                                     of the CLAIM bits.
                                                                 Writing a 1 to one of these bits clears the corresponding
                                                                     CLAIM bit to 0. This is an indirect write to the CLAIM bits.
                                                                 A single write operation can clear multiple bits to 0. Writing
                                                                     0 to one of these bits has no effect. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgclaimclr_el1_s cn; */
} bdk_dbgx_dbgclaimclr_el1_t;

static inline uint64_t BDK_DBGX_DBGCLAIMCLR_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGCLAIMCLR_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fa4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_DBGCLAIMCLR_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_DBGCLAIMCLR_EL1(a) bdk_dbgx_dbgclaimclr_el1_t
#define bustype_BDK_DBGX_DBGCLAIMCLR_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGCLAIMCLR_EL1(a) "DBGX_DBGCLAIMCLR_EL1"
#define busnum_BDK_DBGX_DBGCLAIMCLR_EL1(a) (a)
#define arguments_BDK_DBGX_DBGCLAIMCLR_EL1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_dbgclaimset_el1
 *
 * AP DBG Debug Claim Tag Set Register
 * Used by software to set CLAIM bits to 1.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgclaimset_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t claim                 : 8;  /**< [  7:  0](R/W) Claim set bits. RAO.
                                                                 Writing a 1 to one of these bits sets the corresponding CLAIM
                                                                     bit to 1. This is an indirect write to the CLAIM bits.
                                                                 A single write operation can set multiple bits to 1. Writing 0
                                                                     to one of these bits has no effect. */
#else /* Word 0 - Little Endian */
        uint32_t claim                 : 8;  /**< [  7:  0](R/W) Claim set bits. RAO.
                                                                 Writing a 1 to one of these bits sets the corresponding CLAIM
                                                                     bit to 1. This is an indirect write to the CLAIM bits.
                                                                 A single write operation can set multiple bits to 1. Writing 0
                                                                     to one of these bits has no effect. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgclaimset_el1_s cn; */
} bdk_dbgx_dbgclaimset_el1_t;

static inline uint64_t BDK_DBGX_DBGCLAIMSET_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGCLAIMSET_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fa0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_DBGCLAIMSET_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_DBGCLAIMSET_EL1(a) bdk_dbgx_dbgclaimset_el1_t
#define bustype_BDK_DBGX_DBGCLAIMSET_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGCLAIMSET_EL1(a) "DBGX_DBGCLAIMSET_EL1"
#define busnum_BDK_DBGX_DBGCLAIMSET_EL1(a) (a)
#define arguments_BDK_DBGX_DBGCLAIMSET_EL1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_dbgdtrrx_el0
 *
 * AP DBG Debug Data Transfer Receive Register
 * This register transfers 32 bits of data from an external host to the
 *     processor.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgdtrrx_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](R/W) Update DTRRX. Writing to this register updates the value in
                                                                     DTRRX and set RXfull to 1.
                                                                 Reading this register returns the last value written to DTRRX
                                                                     and does not change RXfull. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](R/W) Update DTRRX. Writing to this register updates the value in
                                                                     DTRRX and set RXfull to 1.
                                                                 Reading this register returns the last value written to DTRRX
                                                                     and does not change RXfull. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgdtrrx_el0_s cn; */
} bdk_dbgx_dbgdtrrx_el0_t;

static inline uint64_t BDK_DBGX_DBGDTRRX_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGDTRRX_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a008000080ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_DBGDTRRX_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_DBGDTRRX_EL0(a) bdk_dbgx_dbgdtrrx_el0_t
#define bustype_BDK_DBGX_DBGDTRRX_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGDTRRX_EL0(a) "DBGX_DBGDTRRX_EL0"
#define busnum_BDK_DBGX_DBGDTRRX_EL0(a) (a)
#define arguments_BDK_DBGX_DBGDTRRX_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_dbgdtrtx_el0
 *
 * AP DBG Debug Data Transfer Transmit Register
 * This register transfers 32 bits of data from the processor to an external
 *     host.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgdtrtx_el0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](R/W) Return DTRTX
                                                                 Return DTRTX. Reads of this register return the value in DTRTX
                                                                     and clear TXfull to 0.
                                                                 Writes of this register update the value in DTRTX and do not
                                                                     change TXfull.
                                                                 See ARMv8 debug architecture for more details. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](R/W) Return DTRTX
                                                                 Return DTRTX. Reads of this register return the value in DTRTX
                                                                     and clear TXfull to 0.
                                                                 Writes of this register update the value in DTRTX and do not
                                                                     change TXfull.
                                                                 See ARMv8 debug architecture for more details. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgdtrtx_el0_s cn; */
} bdk_dbgx_dbgdtrtx_el0_t;

static inline uint64_t BDK_DBGX_DBGDTRTX_EL0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGDTRTX_EL0(unsigned long a)
{
    if (a<=47)
        return 0x87a00800008cll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_DBGDTRTX_EL0", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_DBGDTRTX_EL0(a) bdk_dbgx_dbgdtrtx_el0_t
#define bustype_BDK_DBGX_DBGDTRTX_EL0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGDTRTX_EL0(a) "DBGX_DBGDTRTX_EL0"
#define busnum_BDK_DBGX_DBGDTRTX_EL0(a) (a)
#define arguments_BDK_DBGX_DBGDTRTX_EL0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_dbgwcr#_el1
 *
 * AP DBG Debug Watchpoint Control Registers
 * Watchpoint control register.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgwcrx_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_29_31        : 3;
        uint32_t mask                  : 5;  /**< [ 28: 24](R/W) Address mask.   Ignored if E is zero.  Only objects up to 2GB
                                                                 can be watched by a signle mask.
                                                                 00000  No Mask.
                                                                 00011  3 address bits masked (0x00000007).
                                                                 00100  4 address bits masked (0x0000000f).
                                                                 00101  5 address bits masked (0x0000001f).
                                                                  ...
                                                                 11111  31 address bits masked (0x7ffffffff).
                                                                 All other values are reserved and behaviour is unpredictable. */
        uint32_t reserved_21_23        : 3;
        uint32_t wt                    : 1;  /**< [ 20: 20](R/W) Watchpoint Type.  Ignored if E is 0.
                                                                 0 - unlinked data address match.
                                                                 1 - linked data address match. */
        uint32_t lbn                   : 4;  /**< [ 19: 16](R/W) Linked breakpoint number.  If the watchpoint is linked,
                                                                 specifies the linked context breakpoint to which this watchpoint is linked.
                                                                 For unlinked watchpoints, this field is ignored. */
        uint32_t ssc                   : 2;  /**< [ 15: 14](R/W) Security state control. Determines the security states under
                                                                     which a watchpoint debug event for watchpoint n is generated.
                                                                     This field must be interpreted along with the HMC and PMC
                                                                     fields. Possible values are summarised in the "Processor state
                                                                     matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t hmc                   : 1;  /**< [ 13: 13](R/W) Higher mode control. Determines the debug perspective for
                                                                     deciding when a watchpoint debug event for watchpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and PMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t bas                   : 8;  /**< [ 12:  5](R/W) Byte address select.
                                                                 A 1 in a bit selects whether the corresponding byte in a word or double-word
                                                                 specified byte DBGVRn_EL1 is being watched.  The lsb corresponds to
                                                                 DBGVRn_EL1+0 and the msb corresponds to DBGVRn_EL1+7.  Only contiguous bits
                                                                 may be set. See PRD03-PRDC-010486 for more details.. */
        uint32_t lsc                   : 2;  /**< [  4:  3](R/W) Load store control. Ignored if E is 0.   Otherwise
                                                                     00  Reserved, acts as if E is 0.
                                                                     01  Match load instructions
                                                                     10  Match store instructions
                                                                     11  Match both load and store instructions. */
        uint32_t pac                   : 2;  /**< [  2:  1](R/W) Privilege access control. Determines the exception level or
                                                                     levels at which a watchpoint debug event for watchpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and HMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Watchpoint Enable.  0 - disabled, 1 enabled. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Watchpoint Enable.  0 - disabled, 1 enabled. */
        uint32_t pac                   : 2;  /**< [  2:  1](R/W) Privilege access control. Determines the exception level or
                                                                     levels at which a watchpoint debug event for watchpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and HMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t lsc                   : 2;  /**< [  4:  3](R/W) Load store control. Ignored if E is 0.   Otherwise
                                                                     00  Reserved, acts as if E is 0.
                                                                     01  Match load instructions
                                                                     10  Match store instructions
                                                                     11  Match both load and store instructions. */
        uint32_t bas                   : 8;  /**< [ 12:  5](R/W) Byte address select.
                                                                 A 1 in a bit selects whether the corresponding byte in a word or double-word
                                                                 specified byte DBGVRn_EL1 is being watched.  The lsb corresponds to
                                                                 DBGVRn_EL1+0 and the msb corresponds to DBGVRn_EL1+7.  Only contiguous bits
                                                                 may be set. See PRD03-PRDC-010486 for more details.. */
        uint32_t hmc                   : 1;  /**< [ 13: 13](R/W) Higher mode control. Determines the debug perspective for
                                                                     deciding when a watchpoint debug event for watchpoint n is
                                                                     generated. This field must be interpreted along with the SSC
                                                                     and PMC fields. Possible values are summarised in the
                                                                     "Processor state matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t ssc                   : 2;  /**< [ 15: 14](R/W) Security state control. Determines the security states under
                                                                     which a watchpoint debug event for watchpoint n is generated.
                                                                     This field must be interpreted along with the HMC and PMC
                                                                     fields. Possible values are summarised in the "Processor state
                                                                     matching" section of the Debug specification
                                                                     (PRD03-PRDC-010486). */
        uint32_t lbn                   : 4;  /**< [ 19: 16](R/W) Linked breakpoint number.  If the watchpoint is linked,
                                                                 specifies the linked context breakpoint to which this watchpoint is linked.
                                                                 For unlinked watchpoints, this field is ignored. */
        uint32_t wt                    : 1;  /**< [ 20: 20](R/W) Watchpoint Type.  Ignored if E is 0.
                                                                 0 - unlinked data address match.
                                                                 1 - linked data address match. */
        uint32_t reserved_21_23        : 3;
        uint32_t mask                  : 5;  /**< [ 28: 24](R/W) Address mask.   Ignored if E is zero.  Only objects up to 2GB
                                                                 can be watched by a signle mask.
                                                                 00000  No Mask.
                                                                 00011  3 address bits masked (0x00000007).
                                                                 00100  4 address bits masked (0x0000000f).
                                                                 00101  5 address bits masked (0x0000001f).
                                                                  ...
                                                                 11111  31 address bits masked (0x7ffffffff).
                                                                 All other values are reserved and behaviour is unpredictable. */
        uint32_t reserved_29_31        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgwcrx_el1_s cn; */
} bdk_dbgx_dbgwcrx_el1_t;

static inline uint64_t BDK_DBGX_DBGWCRX_EL1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGWCRX_EL1(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008000808ll + 0x80000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x7);
    __bdk_csr_fatal("DBGX_DBGWCRX_EL1", 2, a, b, 0, 0);
}

#define typedef_BDK_DBGX_DBGWCRX_EL1(a,b) bdk_dbgx_dbgwcrx_el1_t
#define bustype_BDK_DBGX_DBGWCRX_EL1(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGWCRX_EL1(a,b) "DBGX_DBGWCRX_EL1"
#define busnum_BDK_DBGX_DBGWCRX_EL1(a,b) (a)
#define arguments_BDK_DBGX_DBGWCRX_EL1(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) dbg#_dbgwvr#_el1_hi
 *
 * AP DBG Debug Watchpoint Value High Registers
 * Watchpoint value register - high order 32 bits.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgwvrx_el1_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgwvrx_el1_hi_s cn; */
} bdk_dbgx_dbgwvrx_el1_hi_t;

static inline uint64_t BDK_DBGX_DBGWVRX_EL1_HI(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGWVRX_EL1_HI(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008000804ll + 0x80000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x7);
    __bdk_csr_fatal("DBGX_DBGWVRX_EL1_HI", 2, a, b, 0, 0);
}

#define typedef_BDK_DBGX_DBGWVRX_EL1_HI(a,b) bdk_dbgx_dbgwvrx_el1_hi_t
#define bustype_BDK_DBGX_DBGWVRX_EL1_HI(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGWVRX_EL1_HI(a,b) "DBGX_DBGWVRX_EL1_HI"
#define busnum_BDK_DBGX_DBGWVRX_EL1_HI(a,b) (a)
#define arguments_BDK_DBGX_DBGWVRX_EL1_HI(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) dbg#_dbgwvr#_el1_lo
 *
 * AP DBG Debug Watchpoint Value Low Registers
 * Watchpoint value register (low order 32 bits)
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_dbgwvrx_el1_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](R/W/H) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_dbgwvrx_el1_lo_s cn; */
} bdk_dbgx_dbgwvrx_el1_lo_t;

static inline uint64_t BDK_DBGX_DBGWVRX_EL1_LO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_DBGWVRX_EL1_LO(unsigned long a, unsigned long b)
{
    if ((a<=47) && (b<=5))
        return 0x87a008000800ll + 0x80000ll * ((a) & 0x3f) + 0x10ll * ((b) & 0x7);
    __bdk_csr_fatal("DBGX_DBGWVRX_EL1_LO", 2, a, b, 0, 0);
}

#define typedef_BDK_DBGX_DBGWVRX_EL1_LO(a,b) bdk_dbgx_dbgwvrx_el1_lo_t
#define bustype_BDK_DBGX_DBGWVRX_EL1_LO(a,b) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_DBGWVRX_EL1_LO(a,b) "DBGX_DBGWVRX_EL1_LO"
#define busnum_BDK_DBGX_DBGWVRX_EL1_LO(a,b) (a)
#define arguments_BDK_DBGX_DBGWVRX_EL1_LO(a,b) (a),(b),-1,-1

/**
 * Register (DAB32b) dbg#_edcidr0
 *
 * AP DBG External Debug Component Identification Register 0
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edcidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prmbl_0               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x0D. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_0               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x0D. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edcidr0_s cn; */
} bdk_dbgx_edcidr0_t;

static inline uint64_t BDK_DBGX_EDCIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR0(unsigned long a)
{
    if (a<=47)
        return 0x87a008000ff0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDCIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDCIDR0(a) bdk_dbgx_edcidr0_t
#define bustype_BDK_DBGX_EDCIDR0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDCIDR0(a) "DBGX_EDCIDR0"
#define busnum_BDK_DBGX_EDCIDR0(a) (a)
#define arguments_BDK_DBGX_EDCIDR0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edcidr1
 *
 * AP DBG External Debug Component Identification Register 1
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edcidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. 0x9 = Debug component. */
        uint32_t prmbl_1               : 4;  /**< [  3:  0](RO) Preamble. RAZ. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_1               : 4;  /**< [  3:  0](RO) Preamble. RAZ. */
        uint32_t cclass                : 4;  /**< [  7:  4](RO) Component class. 0x9 = Debug component. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edcidr1_s cn; */
} bdk_dbgx_edcidr1_t;

static inline uint64_t BDK_DBGX_EDCIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000ff4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDCIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDCIDR1(a) bdk_dbgx_edcidr1_t
#define bustype_BDK_DBGX_EDCIDR1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDCIDR1(a) "DBGX_EDCIDR1"
#define busnum_BDK_DBGX_EDCIDR1(a) (a)
#define arguments_BDK_DBGX_EDCIDR1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edcidr2
 *
 * AP DBG External Debug Component Identification Register 2
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edcidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prmbl_2               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x05. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_2               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0x05. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edcidr2_s cn; */
} bdk_dbgx_edcidr2_t;

static inline uint64_t BDK_DBGX_EDCIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR2(unsigned long a)
{
    if (a<=47)
        return 0x87a008000ff8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDCIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDCIDR2(a) bdk_dbgx_edcidr2_t
#define bustype_BDK_DBGX_EDCIDR2(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDCIDR2(a) "DBGX_EDCIDR2"
#define busnum_BDK_DBGX_EDCIDR2(a) (a)
#define arguments_BDK_DBGX_EDCIDR2(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edcidr3
 *
 * AP DBG External Debug Component Identification Register 3
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edcidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t prmbl_3               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0xB1. */
#else /* Word 0 - Little Endian */
        uint32_t prmbl_3               : 8;  /**< [  7:  0](RO) Preamble. Must read as 0xB1. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edcidr3_s cn; */
} bdk_dbgx_edcidr3_t;

static inline uint64_t BDK_DBGX_EDCIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDR3(unsigned long a)
{
    if (a<=47)
        return 0x87a008000ffcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDCIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDCIDR3(a) bdk_dbgx_edcidr3_t
#define bustype_BDK_DBGX_EDCIDR3(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDCIDR3(a) "DBGX_EDCIDR3"
#define busnum_BDK_DBGX_EDCIDR3(a) (a)
#define arguments_BDK_DBGX_EDCIDR3(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edcidsr
 *
 * AP DBG External Debug Context ID Sample Register
 * Contains the sampled value of CONTEXTIDR_EL1, captured on
 *     reading the low half of EDPCSR.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edcidsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t contextidr            : 32; /**< [ 31:  0](RO) The sampled value of CONTEXTIDR_EL1, captured on reading the
                                                                     low half of EDPCSR.
                                                                 If EL3 is implemented and using AArch32 then CONTEXTIDR is a
                                                                     Banked register, and EDCIDSR samples the current Banked copy
                                                                     of CONTEXTIDR. */
#else /* Word 0 - Little Endian */
        uint32_t contextidr            : 32; /**< [ 31:  0](RO) The sampled value of CONTEXTIDR_EL1, captured on reading the
                                                                     low half of EDPCSR.
                                                                 If EL3 is implemented and using AArch32 then CONTEXTIDR is a
                                                                     Banked register, and EDCIDSR samples the current Banked copy
                                                                     of CONTEXTIDR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edcidsr_s cn; */
} bdk_dbgx_edcidsr_t;

static inline uint64_t BDK_DBGX_EDCIDSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDCIDSR(unsigned long a)
{
    if (a<=47)
        return 0x87a0080000a4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDCIDSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDCIDSR(a) bdk_dbgx_edcidsr_t
#define bustype_BDK_DBGX_EDCIDSR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDCIDSR(a) "DBGX_EDCIDSR"
#define busnum_BDK_DBGX_EDCIDSR(a) (a)
#define arguments_BDK_DBGX_EDCIDSR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevaff0
 *
 * AP DBG External Debug Device Affinity register 0 DAP EDDEVAFF0 Register
 * copy of the MPIDR_EL1[31:0] register in the process core.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevaff0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t b31                   : 1;  /**< [ 31: 31](RO) Bit 31. */
        uint32_t u                     : 1;  /**< [ 30: 30](RO) U  - 1 indidcates processor is part of a multiprocessor system. */
        uint32_t reserved_24_29        : 6;
        uint32_t aff2                  : 8;  /**< [ 23: 16](RO/H) AFF2, this is node id. */
        uint32_t aff1                  : 8;  /**< [ 15:  8](RO/H) AFF1, this is the group of 16 cores within a node */
        uint32_t aff0                  : 8;  /**< [  7:  0](RO/H) AFF0, this is the core within a group of 16 */
#else /* Word 0 - Little Endian */
        uint32_t aff0                  : 8;  /**< [  7:  0](RO/H) AFF0, this is the core within a group of 16 */
        uint32_t aff1                  : 8;  /**< [ 15:  8](RO/H) AFF1, this is the group of 16 cores within a node */
        uint32_t aff2                  : 8;  /**< [ 23: 16](RO/H) AFF2, this is node id. */
        uint32_t reserved_24_29        : 6;
        uint32_t u                     : 1;  /**< [ 30: 30](RO) U  - 1 indidcates processor is part of a multiprocessor system. */
        uint32_t b31                   : 1;  /**< [ 31: 31](RO) Bit 31. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevaff0_s cn; */
} bdk_dbgx_eddevaff0_t;

static inline uint64_t BDK_DBGX_EDDEVAFF0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVAFF0(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fa8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVAFF0", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVAFF0(a) bdk_dbgx_eddevaff0_t
#define bustype_BDK_DBGX_EDDEVAFF0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVAFF0(a) "DBGX_EDDEVAFF0"
#define busnum_BDK_DBGX_EDDEVAFF0(a) (a)
#define arguments_BDK_DBGX_EDDEVAFF0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevaff1
 *
 * AP DBG External Debug Device Affinity Register 1
 * MPIDR_EL1[63:32] register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevaff1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevaff1_s cn; */
} bdk_dbgx_eddevaff1_t;

static inline uint64_t BDK_DBGX_EDDEVAFF1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVAFF1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000facll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVAFF1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVAFF1(a) bdk_dbgx_eddevaff1_t
#define bustype_BDK_DBGX_EDDEVAFF1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVAFF1(a) "DBGX_EDDEVAFF1"
#define busnum_BDK_DBGX_EDDEVAFF1(a) (a)
#define arguments_BDK_DBGX_EDDEVAFF1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevarch
 *
 * AP DBG External Debug Device Architecture Register
 * Identifies the programmers' model architecture of the external
 *     debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevarch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t architect             : 11; /**< [ 31: 21](RO) Defines the architecture of the component. For debug, this is
                                                                     ARM Limited.
                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.
                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
        uint32_t present               : 1;  /**< [ 20: 20](RO) When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
        uint32_t revision              : 4;  /**< [ 19: 16](RO) Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For debug, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
        uint32_t archid                : 16; /**< [ 15:  0](RO) Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For debug:
                                                                  Bits [15:12] are the architecture version, 0x6.
                                                                  Bits [11:0] are the architecture part number, 0xA15.
                                                                 This corresponds to debug architecture version v8-A. */
#else /* Word 0 - Little Endian */
        uint32_t archid                : 16; /**< [ 15:  0](RO) Defines this part to be a v8-A debug component. For
                                                                     architectures defined by ARM this is further subdivided.
                                                                 For debug:
                                                                  Bits [15:12] are the architecture version, 0x6.
                                                                  Bits [11:0] are the architecture part number, 0xA15.
                                                                 This corresponds to debug architecture version v8-A. */
        uint32_t revision              : 4;  /**< [ 19: 16](RO) Defines the architecture revision. For architectures defined
                                                                     by ARM this is the minor revision.
                                                                 For debug, the revision defined by v8-A is 0x0.
                                                                 All other values are reserved. */
        uint32_t present               : 1;  /**< [ 20: 20](RO) When set to 1, indicates that the DEVARCH is present.
                                                                 This field is 1 in v8-A. */
        uint32_t architect             : 11; /**< [ 31: 21](RO) Defines the architecture of the component. For debug, this is
                                                                     ARM Limited.
                                                                 Bits [31:28] are the JEP 106 continuation code, 0x4.
                                                                 Bits [27:21] are the JEP 106 ID code, 0x3B. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevarch_s cn; */
} bdk_dbgx_eddevarch_t;

static inline uint64_t BDK_DBGX_EDDEVARCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVARCH(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fbcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVARCH", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVARCH(a) bdk_dbgx_eddevarch_t
#define bustype_BDK_DBGX_EDDEVARCH(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVARCH(a) "DBGX_EDDEVARCH"
#define busnum_BDK_DBGX_EDDEVARCH(a) (a)
#define arguments_BDK_DBGX_EDDEVARCH(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevid
 *
 * AP DBG Main Id Register
 * Device id register for ap core.
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t auxregs               : 4;  /**< [ 27: 24](RO) Indicates support for Auxiliary registers. Permitted values
                                                                     for this field are:
                                                                 All other values are reserved.
                                                                 <0000>      None supported.
                                                                 <0001>      Support for External Debug Auxiliary Control Register, EDACR. */
        uint32_t reserved_4_23         : 20;
        uint32_t pcsample              : 4;  /**< [  3:  0](RO) PCsample field.
                                                                 Indicates the level of Sample-based profiling support using
                                                                     external debug registers 40 through 43. Permitted values of
                                                                     this field in v8-A are:
                                                                 All other values are reserved.
                                                                 <0000>      Architecture-defined form of Sample-based profiling not
                                                                     implemented.
                                                                 <0010>       EDPCSR and EDCIDSR are implemented (only permitted if EL3 and
                                                                     EL2 are not implemented).
                                                                 <0011>       EDPCSR, EDCIDSR, and EDVIDSR are implemented. */
#else /* Word 0 - Little Endian */
        uint32_t pcsample              : 4;  /**< [  3:  0](RO) PCsample field.
                                                                 Indicates the level of Sample-based profiling support using
                                                                     external debug registers 40 through 43. Permitted values of
                                                                     this field in v8-A are:
                                                                 All other values are reserved.
                                                                 <0000>      Architecture-defined form of Sample-based profiling not
                                                                     implemented.
                                                                 <0010>       EDPCSR and EDCIDSR are implemented (only permitted if EL3 and
                                                                     EL2 are not implemented).
                                                                 <0011>       EDPCSR, EDCIDSR, and EDVIDSR are implemented. */
        uint32_t reserved_4_23         : 20;
        uint32_t auxregs               : 4;  /**< [ 27: 24](RO) Indicates support for Auxiliary registers. Permitted values
                                                                     for this field are:
                                                                 All other values are reserved.
                                                                 <0000>      None supported.
                                                                 <0001>      Support for External Debug Auxiliary Control Register, EDACR. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevid_s cn; */
} bdk_dbgx_eddevid_t;

static inline uint64_t BDK_DBGX_EDDEVID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVID(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fc8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVID", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVID(a) bdk_dbgx_eddevid_t
#define bustype_BDK_DBGX_EDDEVID(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVID(a) "DBGX_EDDEVID"
#define busnum_BDK_DBGX_EDDEVID(a) (a)
#define arguments_BDK_DBGX_EDDEVID(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevid1
 *
 * AP DBG Device Id Register 1
 * Device id1 register for ap core.
 * INTERNAL: RTL:
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevid1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_4_31         : 28;
        uint32_t pcsroffset            : 4;  /**< [  3:  0](RO) PCSROffset field.
                                                                 This field indicates the offset applied to PC samples returned
                                                                     by reads of EDPCSR. Permitted values of this field in v8-A
                                                                     are:
                                                                 <0000>       EDPCSR not implemented.
                                                                 <0010>       EDPCSR implemented, and samples have no offset applied and do
                                                                     not sample the instruction set state in AArch32 state.

                                                                 Note: CNXXXX does not implement AArch32 state. */
#else /* Word 0 - Little Endian */
        uint32_t pcsroffset            : 4;  /**< [  3:  0](RO) PCSROffset field.
                                                                 This field indicates the offset applied to PC samples returned
                                                                     by reads of EDPCSR. Permitted values of this field in v8-A
                                                                     are:
                                                                 <0000>       EDPCSR not implemented.
                                                                 <0010>       EDPCSR implemented, and samples have no offset applied and do
                                                                     not sample the instruction set state in AArch32 state.

                                                                 Note: CNXXXX does not implement AArch32 state. */
        uint32_t reserved_4_31         : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevid1_s cn; */
} bdk_dbgx_eddevid1_t;

static inline uint64_t BDK_DBGX_EDDEVID1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVID1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fc4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVID1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVID1(a) bdk_dbgx_eddevid1_t
#define bustype_BDK_DBGX_EDDEVID1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVID1(a) "DBGX_EDDEVID1"
#define busnum_BDK_DBGX_EDDEVID1(a) (a)
#define arguments_BDK_DBGX_EDDEVID1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevid2
 *
 * AP DBG Device Id Register 2
 * Device id2 register for ap core.
 * INTERNAL: RTL:
 * Read only register, Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevid2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevid2_s cn; */
} bdk_dbgx_eddevid2_t;

static inline uint64_t BDK_DBGX_EDDEVID2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVID2(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fc0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVID2", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVID2(a) bdk_dbgx_eddevid2_t
#define bustype_BDK_DBGX_EDDEVID2(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVID2(a) "DBGX_EDDEVID2"
#define busnum_BDK_DBGX_EDDEVID2(a) (a)
#define arguments_BDK_DBGX_EDDEVID2(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_eddevtype
 *
 * AP DBG External Debug Device Type Register
 * Indicates to a debugger that this component is part of a
 *     processor's debug logic.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_eddevtype_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t sub                   : 4;  /**< [  7:  4](RO) Subtype. */
        uint32_t major                 : 4;  /**< [  3:  0](RO) Major type. */
#else /* Word 0 - Little Endian */
        uint32_t major                 : 4;  /**< [  3:  0](RO) Major type. */
        uint32_t sub                   : 4;  /**< [  7:  4](RO) Subtype. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddevtype_s cn; */
} bdk_dbgx_eddevtype_t;

static inline uint64_t BDK_DBGX_EDDEVTYPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDEVTYPE(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fccll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDEVTYPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDEVTYPE(a) bdk_dbgx_eddevtype_t
#define bustype_BDK_DBGX_EDDEVTYPE(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDDEVTYPE(a) "DBGX_EDDEVTYPE"
#define busnum_BDK_DBGX_EDDEVTYPE(a) (a)
#define arguments_BDK_DBGX_EDDEVTYPE(a) (a),-1,-1,-1

/**
 * Register (DAB) dbg#_eddfr
 *
 * AP DBG External Debug Feature Register
 * Provide information for external debuggers. CTX_CMDS, WRPS, BRPS, PMUVER, TRACEVER has same
 * value in the corresponding fields of ID_AA64DFR0_EL1.
 */
typedef union
{
    uint64_t u;
    struct bdk_dbgx_eddfr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t ctx_cmds              : 4;  /**< [ 31: 28](RO) Number of breakpoints that are context-aware, minus 1.
                                                                 These are the highest numbeed breakpoints. */
        uint64_t reserved_24_27        : 4;
        uint64_t wrps                  : 4;  /**< [ 23: 20](RO) Number of watch points, minus 1. The value of 0x0 is reserved. */
        uint64_t reserved_16_19        : 4;
        uint64_t brps                  : 4;  /**< [ 15: 12](RO) Number of break points, minus 1. The value of 0x0 is reserved. */
        uint64_t pmuver                : 4;  /**< [ 11:  8](RO) Support for performance monitors extension system registers.
                                                                   0x0 = Performance monitors extension system registers not implemented.
                                                                   0x1 =Support for performance monitors extension system registers, version 3, as
                                                                 defined in Part C, performance monitors extension.
                                                                   0x4 =Support for 16 bit even field.
                                                                   0xF = Implementation defined form of performance monitors supported, PMUv3 not
                                                                 supported.
                                                                   _ All other values are reserved. */
        uint64_t tracever              : 4;  /**< [  7:  4](RO) Support for trace extension system registers.
                                                                   0x0 = Trace extension system registers not implemented.
                                                                   0x1 = Support for ARM-defined trace extension system registers. The trace ID register
                                                                          gives more information about implementation.
                                                                   _ All other values are reserved. */
        uint64_t debugver              : 4;  /**< [  3:  0](RO) Support for debug architecture.
                                                                   0x6 = Support for ARMv8 architecture.
                                                                   _ All other values are reserved. */
#else /* Word 0 - Little Endian */
        uint64_t debugver              : 4;  /**< [  3:  0](RO) Support for debug architecture.
                                                                   0x6 = Support for ARMv8 architecture.
                                                                   _ All other values are reserved. */
        uint64_t tracever              : 4;  /**< [  7:  4](RO) Support for trace extension system registers.
                                                                   0x0 = Trace extension system registers not implemented.
                                                                   0x1 = Support for ARM-defined trace extension system registers. The trace ID register
                                                                          gives more information about implementation.
                                                                   _ All other values are reserved. */
        uint64_t pmuver                : 4;  /**< [ 11:  8](RO) Support for performance monitors extension system registers.
                                                                   0x0 = Performance monitors extension system registers not implemented.
                                                                   0x1 =Support for performance monitors extension system registers, version 3, as
                                                                 defined in Part C, performance monitors extension.
                                                                   0x4 =Support for 16 bit even field.
                                                                   0xF = Implementation defined form of performance monitors supported, PMUv3 not
                                                                 supported.
                                                                   _ All other values are reserved. */
        uint64_t brps                  : 4;  /**< [ 15: 12](RO) Number of break points, minus 1. The value of 0x0 is reserved. */
        uint64_t reserved_16_19        : 4;
        uint64_t wrps                  : 4;  /**< [ 23: 20](RO) Number of watch points, minus 1. The value of 0x0 is reserved. */
        uint64_t reserved_24_27        : 4;
        uint64_t ctx_cmds              : 4;  /**< [ 31: 28](RO) Number of breakpoints that are context-aware, minus 1.
                                                                 These are the highest numbeed breakpoints. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_eddfr_s cn; */
} bdk_dbgx_eddfr_t;

static inline uint64_t BDK_DBGX_EDDFR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDDFR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000d28ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDDFR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDDFR(a) bdk_dbgx_eddfr_t
#define bustype_BDK_DBGX_EDDFR(a) BDK_CSR_TYPE_DAB
#define basename_BDK_DBGX_EDDFR(a) "DBGX_EDDFR"
#define busnum_BDK_DBGX_EDDFR(a) (a)
#define arguments_BDK_DBGX_EDDFR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edeccr
 *
 * AP DBG External Debug Exception Catch Control Register
 * Controls exception catch debug events.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edeccr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t nse                   : 4;  /**< [  7:  4](R/W) Coarse-grained Non-secure exception catch. Possible values of
                                                                     this field are:
                                                                 All other values are reserved. Bits [7,4] are reserved, RAZ.
                                                                 <0000>      Exception catch debug event disabled for Non-secure exception
                                                                     levels.
                                                                 <0010>      Exception catch debug event enabled for Non-secure EL1.
                                                                 <0100>      Exception catch debug event enabled for Non-secure EL2.
                                                                 <0110>      Exception catch debug event enabled for Non-secure EL1 and
                                                                     EL2. */
        uint32_t se                    : 4;  /**< [  3:  0](R/W) Coarse-grained Secure exception catch. Possible values of this
                                                                     field are:
                                                                 All other values are reserved. Bits [2,0] are reserved. RAZ.
                                                                     Ignored if ExternalSecureInvasiveDebugEnabled() == FALSE.
                                                                 <0000>      Exception catch debug event disabled for Secure exception
                                                                     levels.
                                                                 <0010>      Exception catch debug event enabled for Secure EL1.
                                                                 <1000>      Exception catch debug event enabled for Secure EL3.
                                                                 <1010>      Exception catch debug event enabled for Secure EL1 and EL3. */
#else /* Word 0 - Little Endian */
        uint32_t se                    : 4;  /**< [  3:  0](R/W) Coarse-grained Secure exception catch. Possible values of this
                                                                     field are:
                                                                 All other values are reserved. Bits [2,0] are reserved. RAZ.
                                                                     Ignored if ExternalSecureInvasiveDebugEnabled() == FALSE.
                                                                 <0000>      Exception catch debug event disabled for Secure exception
                                                                     levels.
                                                                 <0010>      Exception catch debug event enabled for Secure EL1.
                                                                 <1000>      Exception catch debug event enabled for Secure EL3.
                                                                 <1010>      Exception catch debug event enabled for Secure EL1 and EL3. */
        uint32_t nse                   : 4;  /**< [  7:  4](R/W) Coarse-grained Non-secure exception catch. Possible values of
                                                                     this field are:
                                                                 All other values are reserved. Bits [7,4] are reserved, RAZ.
                                                                 <0000>      Exception catch debug event disabled for Non-secure exception
                                                                     levels.
                                                                 <0010>      Exception catch debug event enabled for Non-secure EL1.
                                                                 <0100>      Exception catch debug event enabled for Non-secure EL2.
                                                                 <0110>      Exception catch debug event enabled for Non-secure EL1 and
                                                                     EL2. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edeccr_s cn; */
} bdk_dbgx_edeccr_t;

static inline uint64_t BDK_DBGX_EDECCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDECCR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000098ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDECCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDECCR(a) bdk_dbgx_edeccr_t
#define bustype_BDK_DBGX_EDECCR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDECCR(a) "DBGX_EDECCR"
#define busnum_BDK_DBGX_EDECCR(a) (a)
#define arguments_BDK_DBGX_EDECCR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edecr
 *
 * AP DBG External Debug Execution Control Register
 * This register controls halting debug events.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edecr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t ss                    : 1;  /**< [  2:  2](R/W) Halting step enable.
                                                                 If this value is changed when the processor is in
                                                                     nondebug state, the resulting value is UNKNOWN.
                                                                 0 = Halting step debug event disabled.
                                                                 1 = Halting step debug event enabled. */
        uint32_t rce                   : 1;  /**< [  1:  1](R/W) Reset catch enable. Possible values of this field are:
                                                                 0 = Reset catch debug event disabled.
                                                                 1 = Reset catch debug event enabled. */
        uint32_t osuce                 : 1;  /**< [  0:  0](R/W) OS unlock catch enabled. Possible values of this field are:
                                                                 0 = OS unlock catch debug event disabled.
                                                                 1 = OS unlock catch debug event enabled. */
#else /* Word 0 - Little Endian */
        uint32_t osuce                 : 1;  /**< [  0:  0](R/W) OS unlock catch enabled. Possible values of this field are:
                                                                 0 = OS unlock catch debug event disabled.
                                                                 1 = OS unlock catch debug event enabled. */
        uint32_t rce                   : 1;  /**< [  1:  1](R/W) Reset catch enable. Possible values of this field are:
                                                                 0 = Reset catch debug event disabled.
                                                                 1 = Reset catch debug event enabled. */
        uint32_t ss                    : 1;  /**< [  2:  2](R/W) Halting step enable.
                                                                 If this value is changed when the processor is in
                                                                     nondebug state, the resulting value is UNKNOWN.
                                                                 0 = Halting step debug event disabled.
                                                                 1 = Halting step debug event enabled. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edecr_s cn; */
} bdk_dbgx_edecr_t;

static inline uint64_t BDK_DBGX_EDECR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDECR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000024ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDECR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDECR(a) bdk_dbgx_edecr_t
#define bustype_BDK_DBGX_EDECR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDECR(a) "DBGX_EDECR"
#define busnum_BDK_DBGX_EDECR(a) (a)
#define arguments_BDK_DBGX_EDECR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edesr
 *
 * AP DBG External Debug Event Status Register
 * This register indicates the status of internally pending halting debug
 *     events.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edesr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t ss                    : 1;  /**< [  2:  2](R/W) Halting step debug event pending.
                                                                 0 = A halting step debug event is not
                                                                     pending. Writing a 0 means no action.
                                                                 1 = A halting step debug event is pending.
                                                                     Writing a 1 clears the pending halting step debug event. */
        uint32_t rc                    : 1;  /**< [  1:  1](R/W) Reset catch debug event pending.
                                                                 0 = a reset catch debug event is not
                                                                     pending. Writing a 0 means no action.
                                                                 1 = a reset catch debug event is pending.
                                                                     Writing a 1 clears the pending reset catch debug event. */
        uint32_t osuc                  : 1;  /**< [  0:  0](R/W) OS unlock debug event pending.
                                                                 0 = An OS unlock catch debug event is not
                                                                     pending. Writing a 0 means no action.
                                                                 1 = An OS unlock catch debug event is
                                                                     pending. Writing a 1 clears the pending OS unlock catch debug
                                                                     event. */
#else /* Word 0 - Little Endian */
        uint32_t osuc                  : 1;  /**< [  0:  0](R/W) OS unlock debug event pending.
                                                                 0 = An OS unlock catch debug event is not
                                                                     pending. Writing a 0 means no action.
                                                                 1 = An OS unlock catch debug event is
                                                                     pending. Writing a 1 clears the pending OS unlock catch debug
                                                                     event. */
        uint32_t rc                    : 1;  /**< [  1:  1](R/W) Reset catch debug event pending.
                                                                 0 = a reset catch debug event is not
                                                                     pending. Writing a 0 means no action.
                                                                 1 = a reset catch debug event is pending.
                                                                     Writing a 1 clears the pending reset catch debug event. */
        uint32_t ss                    : 1;  /**< [  2:  2](R/W) Halting step debug event pending.
                                                                 0 = A halting step debug event is not
                                                                     pending. Writing a 0 means no action.
                                                                 1 = A halting step debug event is pending.
                                                                     Writing a 1 clears the pending halting step debug event. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edesr_s cn; */
} bdk_dbgx_edesr_t;

static inline uint64_t BDK_DBGX_EDESR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDESR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000020ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDESR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDESR(a) bdk_dbgx_edesr_t
#define bustype_BDK_DBGX_EDESR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDESR(a) "DBGX_EDESR"
#define busnum_BDK_DBGX_EDESR(a) (a)
#define arguments_BDK_DBGX_EDESR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_editctrl
 *
 * AP DBG External Debug Integration Mode Control Register
 * Enables the external debug to switch from its default mode
 *     into integration mode, where test software can control
 *     directly the inputs and outputs of the processor, for
 *     integration testing or topology detection.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_editctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t ime                   : 1;  /**< [  0:  0](RO) Integration mode enable.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled.

                                                                 Integration mode is not supported by CNXXXX. */
#else /* Word 0 - Little Endian */
        uint32_t ime                   : 1;  /**< [  0:  0](RO) Integration mode enable.
                                                                 0 = Normal operation.
                                                                 1 = Integration mode enabled.

                                                                 Integration mode is not supported by CNXXXX. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_editctrl_s cn; */
} bdk_dbgx_editctrl_t;

static inline uint64_t BDK_DBGX_EDITCTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDITCTRL(unsigned long a)
{
    if (a<=47)
        return 0x87a008000f00ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDITCTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDITCTRL(a) bdk_dbgx_editctrl_t
#define bustype_BDK_DBGX_EDITCTRL(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDITCTRL(a) "DBGX_EDITCTRL"
#define busnum_BDK_DBGX_EDITCTRL(a) (a)
#define arguments_BDK_DBGX_EDITCTRL(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_editr
 *
 * AP DBG External Debug Instruction Transfer Register
 * This register is used in Debug state for passing instructions to the processor
 *     for execution.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_editr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t t32second             : 16; /**< [ 31: 16](WO) Second halfword of the T32 instruction to be executed on the
                                                                     processor. */
        uint32_t t32first              : 16; /**< [ 15:  0](WO) First halfword of the T32 instruction to be executed on the
                                                                     processor. */
#else /* Word 0 - Little Endian */
        uint32_t t32first              : 16; /**< [ 15:  0](WO) First halfword of the T32 instruction to be executed on the
                                                                     processor. */
        uint32_t t32second             : 16; /**< [ 31: 16](WO) Second halfword of the T32 instruction to be executed on the
                                                                     processor. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_editr_s cn; */
} bdk_dbgx_editr_t;

static inline uint64_t BDK_DBGX_EDITR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDITR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000084ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDITR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDITR(a) bdk_dbgx_editr_t
#define bustype_BDK_DBGX_EDITR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDITR(a) "DBGX_EDITR"
#define busnum_BDK_DBGX_EDITR(a) (a)
#define arguments_BDK_DBGX_EDITR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edlar
 *
 * AP DBG External Debug Lock Access Register
 * Allows or disallows access to the external debug registers
 *     through a memory-mapped interface.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edlar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t key                   : 32; /**< [ 31:  0](WO) Lock Access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface from internal
                                                                 software.  From external access (via DAP), this reister is write ignored. */
#else /* Word 0 - Little Endian */
        uint32_t key                   : 32; /**< [ 31:  0](WO) Lock Access control. Writing the key value 0xC5ACCE55 unlocks the lock.
                                                                 Writing any other value to this register locks the lock, disabling write
                                                                 accesses to this component's registers through a memory mapped interface from internal
                                                                 software.  From external access (via DAP), this reister is write ignored. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edlar_s cn; */
} bdk_dbgx_edlar_t;

static inline uint64_t BDK_DBGX_EDLAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDLAR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fb0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDLAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDLAR(a) bdk_dbgx_edlar_t
#define bustype_BDK_DBGX_EDLAR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDLAR(a) "DBGX_EDLAR"
#define busnum_BDK_DBGX_EDLAR(a) (a)
#define arguments_BDK_DBGX_EDLAR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edlsr
 *
 * AP DBG External Debug Lock Status Register
 * Indicates the current status of the software lock for memory mapped external
 *     debug registers.  This register when accessed from an external debugger (via DAP)
 *     is RAZ.   However, when accessed from internal software indicates the value of hte
 * software lock.
 *     The software lock is intended to prevent accidental corruption of the external debug
 *     registers.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edlsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t ntt                   : 1;  /**< [  2:  2](RO) Not thirty-two bit access required. RAZ. */
        uint32_t slk                   : 1;  /**< [  1:  1](RO/H) Software lock status for this component. For an access to LSR
                                                                     that is not a memory-mapped access (i.e. from inside the device)
                                                                     this field is RAZ.
                                                                 For memory-mapped accesses when the software lock is
                                                                     implemented, possible values of this field are:
                                                                 <0> Lock clear. Writes are permitted to this component's
                                                                     registers.
                                                                 <1> Lock set. Writes to this component's registers are ignored,
                                                                     and reads have no side effects. */
        uint32_t sli                   : 1;  /**< [  0:  0](RO) Software lock implemented for CNXXXX. For an access to LSR that is not a
                                                                     memory-mapped access, this field is RAZ. For memory-mapped
                                                                     accesses, the value of this field is 1
                                                                     Permitted values are:
                                                                 <0> Software lock not implemented or not memory-mapped access.
                                                                 <1> Software lock implemented and memory-mapped access. */
#else /* Word 0 - Little Endian */
        uint32_t sli                   : 1;  /**< [  0:  0](RO) Software lock implemented for CNXXXX. For an access to LSR that is not a
                                                                     memory-mapped access, this field is RAZ. For memory-mapped
                                                                     accesses, the value of this field is 1
                                                                     Permitted values are:
                                                                 <0> Software lock not implemented or not memory-mapped access.
                                                                 <1> Software lock implemented and memory-mapped access. */
        uint32_t slk                   : 1;  /**< [  1:  1](RO/H) Software lock status for this component. For an access to LSR
                                                                     that is not a memory-mapped access (i.e. from inside the device)
                                                                     this field is RAZ.
                                                                 For memory-mapped accesses when the software lock is
                                                                     implemented, possible values of this field are:
                                                                 <0> Lock clear. Writes are permitted to this component's
                                                                     registers.
                                                                 <1> Lock set. Writes to this component's registers are ignored,
                                                                     and reads have no side effects. */
        uint32_t ntt                   : 1;  /**< [  2:  2](RO) Not thirty-two bit access required. RAZ. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edlsr_s cn; */
} bdk_dbgx_edlsr_t;

static inline uint64_t BDK_DBGX_EDLSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDLSR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fb4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDLSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDLSR(a) bdk_dbgx_edlsr_t
#define bustype_BDK_DBGX_EDLSR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDLSR(a) "DBGX_EDLSR"
#define busnum_BDK_DBGX_EDLSR(a) (a)
#define arguments_BDK_DBGX_EDLSR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpcsr_hi
 *
 * AP DBG External Debug Program Counter Sample High Register
 * PC bits 63:32 sampled when EDPCSR_LO is read.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpcsr_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](RO) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](RO) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpcsr_hi_s cn; */
} bdk_dbgx_edpcsr_hi_t;

static inline uint64_t BDK_DBGX_EDPCSR_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPCSR_HI(unsigned long a)
{
    if (a<=47)
        return 0x87a0080000acll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPCSR_HI", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPCSR_HI(a) bdk_dbgx_edpcsr_hi_t
#define bustype_BDK_DBGX_EDPCSR_HI(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPCSR_HI(a) "DBGX_EDPCSR_HI"
#define busnum_BDK_DBGX_EDPCSR_HI(a) (a)
#define arguments_BDK_DBGX_EDPCSR_HI(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpcsr_lo
 *
 * AP DBG External Debug Program Counter Sample Low Register
 * low order 32 bits of the sampled PC.  Maybe used to capture PC values when sampling is
 * enabled.
 * When read, causes the capture of the low PC bits, EDCIDSR (Context), EDVIDSR (VMID) and
 * EDPCSR_hi.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpcsr_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t value                 : 32; /**< [ 31:  0](RO) Reserved. */
#else /* Word 0 - Little Endian */
        uint32_t value                 : 32; /**< [ 31:  0](RO) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpcsr_lo_s cn; */
} bdk_dbgx_edpcsr_lo_t;

static inline uint64_t BDK_DBGX_EDPCSR_LO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPCSR_LO(unsigned long a)
{
    if (a<=47)
        return 0x87a0080000a0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPCSR_LO", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPCSR_LO(a) bdk_dbgx_edpcsr_lo_t
#define bustype_BDK_DBGX_EDPCSR_LO(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPCSR_LO(a) "DBGX_EDPCSR_LO"
#define busnum_BDK_DBGX_EDPCSR_LO(a) (a)
#define arguments_BDK_DBGX_EDPCSR_LO(a) (a),-1,-1,-1

/**
 * Register (DAB) dbg#_edpfr
 *
 * AP DBG External Debug Processor Feature Register
 * Provide information for external debuggers. GIC, ADVSIMD, FP, EL3, EL2, EL1, EL0 has same
 * value in the corresponding fields of ID_AA64PFR0_EL1.
 */
typedef union
{
    uint64_t u;
    struct bdk_dbgx_edpfr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t gic                   : 4;  /**< [ 27: 24](RO) GIC system register interface.
                                                                   0x0 = No GIC system registers are supported.
                                                                   0x1 = GICv3 system registers are supported.
                                                                   _ All other values are reserved. */
        uint64_t advsimd               : 4;  /**< [ 23: 20](RO) Advanced SIMD.
                                                                   0x0 = Advanced SIMD is implemented.
                                                                   0xF = Advanced SIMD is not implemented.
                                                                   _ All other values are reserved. */
        uint64_t fp                    : 4;  /**< [ 19: 16](RO) Floating-point.
                                                                   0x0 = Floating-point is implemented.
                                                                   0xF = Floating-point is not implemented.
                                                                   _ All other values are reserved. */
        uint64_t el3                   : 4;  /**< [ 15: 12](RO) EL3 exception level handling.
                                                                   0x0 = EL3 is not implemented.
                                                                   0x1 = EL3 can be executed in AArch64 state only.
                                                                   0x2 = EL3 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t el2                   : 4;  /**< [ 11:  8](RO) EL2 exception level handling.
                                                                   0x0 = EL2 is not implemented.
                                                                   0x1 = EL2 can be executed in AArch64 state only.
                                                                   0x2 = EL2 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t el1                   : 4;  /**< [  7:  4](RO) EL1 exception level handling.
                                                                   0x0 = EL1 is not implemented.
                                                                   0x1 = EL1 can be executed in AArch64 state only.
                                                                   0x2 = EL1 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t el0                   : 4;  /**< [  3:  0](RO) EL0 exception level handling.
                                                                   0x0 = EL0 is not implemented.
                                                                   0x1 = EL0 can be executed in AArch64 state only.
                                                                   0x2 = EL0 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
#else /* Word 0 - Little Endian */
        uint64_t el0                   : 4;  /**< [  3:  0](RO) EL0 exception level handling.
                                                                   0x0 = EL0 is not implemented.
                                                                   0x1 = EL0 can be executed in AArch64 state only.
                                                                   0x2 = EL0 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t el1                   : 4;  /**< [  7:  4](RO) EL1 exception level handling.
                                                                   0x0 = EL1 is not implemented.
                                                                   0x1 = EL1 can be executed in AArch64 state only.
                                                                   0x2 = EL1 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t el2                   : 4;  /**< [ 11:  8](RO) EL2 exception level handling.
                                                                   0x0 = EL2 is not implemented.
                                                                   0x1 = EL2 can be executed in AArch64 state only.
                                                                   0x2 = EL2 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t el3                   : 4;  /**< [ 15: 12](RO) EL3 exception level handling.
                                                                   0x0 = EL3 is not implemented.
                                                                   0x1 = EL3 can be executed in AArch64 state only.
                                                                   0x2 = EL3 can be executed in either AArch64 or AArch32 state.
                                                                   _ All other values are reserved. */
        uint64_t fp                    : 4;  /**< [ 19: 16](RO) Floating-point.
                                                                   0x0 = Floating-point is implemented.
                                                                   0xF = Floating-point is not implemented.
                                                                   _ All other values are reserved. */
        uint64_t advsimd               : 4;  /**< [ 23: 20](RO) Advanced SIMD.
                                                                   0x0 = Advanced SIMD is implemented.
                                                                   0xF = Advanced SIMD is not implemented.
                                                                   _ All other values are reserved. */
        uint64_t gic                   : 4;  /**< [ 27: 24](RO) GIC system register interface.
                                                                   0x0 = No GIC system registers are supported.
                                                                   0x1 = GICv3 system registers are supported.
                                                                   _ All other values are reserved. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpfr_s cn; */
} bdk_dbgx_edpfr_t;

static inline uint64_t BDK_DBGX_EDPFR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPFR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000d20ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPFR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPFR(a) bdk_dbgx_edpfr_t
#define bustype_BDK_DBGX_EDPFR(a) BDK_CSR_TYPE_DAB
#define basename_BDK_DBGX_EDPFR(a) "DBGX_EDPFR"
#define busnum_BDK_DBGX_EDPFR(a) (a)
#define arguments_BDK_DBGX_EDPFR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr0
 *
 * AP DBG External Debug Peripheral Identification Register 0
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t part_0                : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::DBG. */
#else /* Word 0 - Little Endian */
        uint32_t part_0                : 8;  /**< [  7:  0](RO) Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::DBG. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr0_s cn; */
} bdk_dbgx_edpidr0_t;

static inline uint64_t BDK_DBGX_EDPIDR0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR0(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fe0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR0", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR0(a) bdk_dbgx_edpidr0_t
#define bustype_BDK_DBGX_EDPIDR0(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR0(a) "DBGX_EDPIDR0"
#define busnum_BDK_DBGX_EDPIDR0(a) (a)
#define arguments_BDK_DBGX_EDPIDR0(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr1
 *
 * AP DBG External Debug Peripheral Identification Register 1
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t des_0                 : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium JEP106 code is 0x4C. */
        uint32_t part_1                : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else /* Word 0 - Little Endian */
        uint32_t part_1                : 4;  /**< [  3:  0](RO) Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
        uint32_t des_0                 : 4;  /**< [  7:  4](RO) JEP106 identification code <3:0>. Cavium JEP106 code is 0x4C. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr1_s cn; */
} bdk_dbgx_edpidr1_t;

static inline uint64_t BDK_DBGX_EDPIDR1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fe4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR1(a) bdk_dbgx_edpidr1_t
#define bustype_BDK_DBGX_EDPIDR1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR1(a) "DBGX_EDPIDR1"
#define busnum_BDK_DBGX_EDPIDR1(a) (a)
#define arguments_BDK_DBGX_EDPIDR1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr2
 *
 * AP DBG External Debug Peripheral Identification Register 2
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t des_1                 : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium JEP106 code is 0x4C. */
#else /* Word 0 - Little Endian */
        uint32_t des_1                 : 3;  /**< [  2:  0](RO) JEP106 identification code <6:4>. Cavium JEP106 code is 0x4C. */
        uint32_t jedec                 : 1;  /**< [  3:  3](RO) JEDEC assigned. */
        uint32_t revision              : 4;  /**< [  7:  4](RO) Architectural revision. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr2_s cn; */
} bdk_dbgx_edpidr2_t;

static inline uint64_t BDK_DBGX_EDPIDR2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR2(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fe8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR2", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR2(a) bdk_dbgx_edpidr2_t
#define bustype_BDK_DBGX_EDPIDR2(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR2(a) "DBGX_EDPIDR2"
#define busnum_BDK_DBGX_EDPIDR2(a) (a)
#define arguments_BDK_DBGX_EDPIDR2(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr3
 *
 * AP DBG External Debug Peripheral Identification Register 3
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t cmod                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else /* Word 0 - Little Endian */
        uint32_t cmod                  : 4;  /**< [  3:  0](RO) Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
        uint32_t revand                : 4;  /**< [  7:  4](RO) Manufacturer revision number. For CNXXXX always 0x0. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr3_s cn; */
} bdk_dbgx_edpidr3_t;

static inline uint64_t BDK_DBGX_EDPIDR3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR3(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fecll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR3", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR3(a) bdk_dbgx_edpidr3_t
#define bustype_BDK_DBGX_EDPIDR3(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR3(a) "DBGX_EDPIDR3"
#define busnum_BDK_DBGX_EDPIDR3(a) (a)
#define arguments_BDK_DBGX_EDPIDR3(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr4
 *
 * AP DBG External Debug Peripheral Identification Register 4
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t size                  : 4;  /**< [  7:  4](RO) Size of the component. RAZ. Log<sub>2</sub> of the number of
                                                                     4KB pages from the start of the component to the end of the
                                                                     component ID registers. */
        uint32_t des_2                 : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. 0x3 = Cavium. */
#else /* Word 0 - Little Endian */
        uint32_t des_2                 : 4;  /**< [  3:  0](RO) JEP106 continuation code, least significant nibble. 0x3 = Cavium. */
        uint32_t size                  : 4;  /**< [  7:  4](RO) Size of the component. RAZ. Log<sub>2</sub> of the number of
                                                                     4KB pages from the start of the component to the end of the
                                                                     component ID registers. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr4_s cn; */
} bdk_dbgx_edpidr4_t;

static inline uint64_t BDK_DBGX_EDPIDR4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR4(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fd0ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR4", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR4(a) bdk_dbgx_edpidr4_t
#define bustype_BDK_DBGX_EDPIDR4(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR4(a) "DBGX_EDPIDR4"
#define busnum_BDK_DBGX_EDPIDR4(a) (a)
#define arguments_BDK_DBGX_EDPIDR4(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr5
 *
 * AP DBG External Debug Peripheral Identification Register 5
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr5_s cn; */
} bdk_dbgx_edpidr5_t;

static inline uint64_t BDK_DBGX_EDPIDR5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR5(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fd4ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR5", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR5(a) bdk_dbgx_edpidr5_t
#define bustype_BDK_DBGX_EDPIDR5(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR5(a) "DBGX_EDPIDR5"
#define busnum_BDK_DBGX_EDPIDR5(a) (a)
#define arguments_BDK_DBGX_EDPIDR5(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr6
 *
 * AP DBG External Debug Peripheral Identification Register 6
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr6_s cn; */
} bdk_dbgx_edpidr6_t;

static inline uint64_t BDK_DBGX_EDPIDR6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR6(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fd8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR6", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR6(a) bdk_dbgx_edpidr6_t
#define bustype_BDK_DBGX_EDPIDR6(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR6(a) "DBGX_EDPIDR6"
#define busnum_BDK_DBGX_EDPIDR6(a) (a)
#define arguments_BDK_DBGX_EDPIDR6(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edpidr7
 *
 * AP DBG External Debug Peripheral Identification Register 7
 * Provides information to identify an external debug component.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edpidr7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edpidr7_s cn; */
} bdk_dbgx_edpidr7_t;

static inline uint64_t BDK_DBGX_EDPIDR7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPIDR7(unsigned long a)
{
    if (a<=47)
        return 0x87a008000fdcll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPIDR7", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPIDR7(a) bdk_dbgx_edpidr7_t
#define bustype_BDK_DBGX_EDPIDR7(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPIDR7(a) "DBGX_EDPIDR7"
#define busnum_BDK_DBGX_EDPIDR7(a) (a)
#define arguments_BDK_DBGX_EDPIDR7(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edprcr
 *
 * AP DBG External Debug Power/Reset Control Register
 * Controls processor functionality related to powerup, reset,
 * and powerdown.
 * INTERNAL: RTL: Powerup request for ap core. This is write only register.
 * write 1 to bit[3] to request powerup.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edprcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_4_31         : 28;
        uint32_t corepurq              : 1;  /**< [  3:  3](R/W) Software write "1" to set the powerup reuqest.
                                                                 Core powerup request. Allows a debugger to request that the
                                                                     power controller power up the core, enabling access to the
                                                                     debug register in the Core power domain. The actions on
                                                                     writing to this bit are:
                                                                 This bit can be read and written when the Core power domain is
                                                                     powered off.
                                                                 The power controller must not allow the Core power domain to
                                                                     switch off while this bit is one.
                                                                 <0> No effect.
                                                                 <1> Request the power controller to powerup the core. */
        uint32_t reserved_2            : 1;
        uint32_t cwrr                  : 1;  /**< [  1:  1](WO) Warm reset request. Write only bit that reads as zero. The
                                                                    actions on writing to this bit are:
                                                                 The processor ignores writes to this bit if any of the
                                                                    following are the case:
                                                                 ExternalSecureInvasiveDebugEnabled() == FALSE and
                                                                    he processor is Secure.
                                                                 The Core power domain is either completely off or in a low-
                                                                    power state where the Core power domain registers cannot be
                                                                    accessed.
                                                                 DoubleLockStatus() == TRUE (OS double-lock is set).
                                                                 OSLSR.OSLK == 1 (OS lock is locked).
                                                                 <0> No action.
                                                                 <1> Request Warm reset. */
        uint32_t corenpdrq             : 1;  /**< [  0:  0](RO) Core no powerdown request. Requests emulation of powerdown.
                                                                 CNXXXX does not implment core power down emulation. */
#else /* Word 0 - Little Endian */
        uint32_t corenpdrq             : 1;  /**< [  0:  0](RO) Core no powerdown request. Requests emulation of powerdown.
                                                                 CNXXXX does not implment core power down emulation. */
        uint32_t cwrr                  : 1;  /**< [  1:  1](WO) Warm reset request. Write only bit that reads as zero. The
                                                                    actions on writing to this bit are:
                                                                 The processor ignores writes to this bit if any of the
                                                                    following are the case:
                                                                 ExternalSecureInvasiveDebugEnabled() == FALSE and
                                                                    he processor is Secure.
                                                                 The Core power domain is either completely off or in a low-
                                                                    power state where the Core power domain registers cannot be
                                                                    accessed.
                                                                 DoubleLockStatus() == TRUE (OS double-lock is set).
                                                                 OSLSR.OSLK == 1 (OS lock is locked).
                                                                 <0> No action.
                                                                 <1> Request Warm reset. */
        uint32_t reserved_2            : 1;
        uint32_t corepurq              : 1;  /**< [  3:  3](R/W) Software write "1" to set the powerup reuqest.
                                                                 Core powerup request. Allows a debugger to request that the
                                                                     power controller power up the core, enabling access to the
                                                                     debug register in the Core power domain. The actions on
                                                                     writing to this bit are:
                                                                 This bit can be read and written when the Core power domain is
                                                                     powered off.
                                                                 The power controller must not allow the Core power domain to
                                                                     switch off while this bit is one.
                                                                 <0> No effect.
                                                                 <1> Request the power controller to powerup the core. */
        uint32_t reserved_4_31         : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edprcr_s cn; */
} bdk_dbgx_edprcr_t;

static inline uint64_t BDK_DBGX_EDPRCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPRCR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000310ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPRCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPRCR(a) bdk_dbgx_edprcr_t
#define bustype_BDK_DBGX_EDPRCR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPRCR(a) "DBGX_EDPRCR"
#define busnum_BDK_DBGX_EDPRCR(a) (a)
#define arguments_BDK_DBGX_EDPRCR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edprsr
 *
 * AP DBG External Debug Processor Status Register
 * Changed in pass 2, removed from DAP.
 * Holds information about the reset and powerdown state of the
 *     processor.
 * RTL: Powerup status for ap core and only bit[1:0] used
 * If AP CORE power down, read to register will not generate OWB access.
 * If AP CORE power up, read to register will generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edprsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t sdr                   : 1;  /**< [ 11: 11](RO) Sticky debug restart. Set to 1 when the processor exits Debug
                                                                     state and cleared to 0 following reads of EDPRSR.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 0 = The processor has not restarted since EDPRSR was last read.
                                                                 1 = The processor has restarted since EDPRSR was last read. */
        uint32_t spmad                 : 1;  /**< [ 10: 10](RO) Sticky EPMAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalPMUAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 0 = No accesses to the external performance monitors registers
                                                                     have failed since EDPRSR was last read.
                                                                 1 = At least one access to the external performance monitors
                                                                     registers has failed since EDPRSR was last read. */
        uint32_t epmad                 : 1;  /**< [  9:  9](RO) External performance monitors access disable status.
                                                                 If external performance monitors access is not implemented,
                                                                     EPMAD is RAO. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1, or EDPRSR.PU is zero.
                                                                 0 = External performance monitors access enabled.
                                                                 1 = External performance monitors access disabled. */
        uint32_t sdad                  : 1;  /**< [  8:  8](RO) Sticky EDAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalDebugAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 following a read of EDPRSR.
                                                                 0 = No accesses to the external debug registers have failed since
                                                                     EDPRSR was last read.
                                                                 1 = At least one access to the external debug registers has failed
                                                                     since EDPRSR was last read. */
        uint32_t edad                  : 1;  /**< [  7:  7](RO) External debug access disable status.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 0 = External debug access enabled.
                                                                 1 = External debug access disabled. */
        uint32_t dlk                   : 1;  /**< [  6:  6](RO) OS double-lock status bit.
                                                                 This bit is UNKNOWN on reads if EDPRSR.PU is zero.
                                                                 0 = OSDLR_EL1.DLK = 0 or EDPRCR.CORENPDRQ = 1 or the processor
                                                                     is in debug state.
                                                                 1 = OSDLR_EL1.DLK = 1 and EDPRCR.CORENPDRQ = 0 and the processor
                                                                     is in non-debug state. */
        uint32_t oslk                  : 1;  /**< [  5:  5](RO) OS lock status bit. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1 or EDPRSR.PU is zero. Otherwise, a read
                                                                     returns the value of OSLSR_EL1.OSLK. */
        uint32_t halted                : 1;  /**< [  4:  4](RO) Halted status bit. This bit is UNKNOWN on reads if EDPRSR.PU
                                                                     is zero, 0 if EDSCR.STATUS == 0x2, 1 if EDSCR.STATUS != 0x2. */
        uint32_t sr                    : 1;  /**< [  3:  3](RO) Sticky core reset status bit. This bit is UNKNOWN on reads if
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 This bit clears to 0 following a read of EDPRSR if the non-
                                                                     debug logic of the processor is not in reset state.
                                                                 0 = The non-debug logic of the processor is not in reset state and
                                                                     has not been reset since the last time EDPRSR was read.
                                                                 1 = The non-debug logic of the processor is in reset state or has
                                                                     been reset since the last time EDPRSR was read. */
        uint32_t r                     : 1;  /**< [  2:  2](RO) Core reset status bit. This bit is UNKNOWN on reads if either
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 0 = The non-debug logic of the processor is not in reset state.
                                                                 1 = The non-debug logic of the processor is in reset state. */
        uint32_t spd                   : 1;  /**< [  1:  1](RO) Sticky core power-down status bit. This bit is UNKNOWN on
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
                                                                 * Retention: The states of the debug registers, including
                                                                     EDPRSR.SPD, in the Core power domain is preserved, and
                                                                     restored on leaving retention state.
                                                                 * Power-down: The states of the debug registers in the Core
                                                                     power domain is lost, and a Cold reset is asserted on leaving
                                                                     power-down state.

                                                                  If EDPRSR.PU is zero,
                                                                  0 = It is now known whether the state of the degug regsiters in the Core power domain is
                                                                 lost.
                                                                  1 = The state fo the debug registers int he Core power domain is lost

                                                                  If EDPRSR.PU is one,
                                                                  0 = The state of the debug registers in the Core power domain has not been lost.
                                                                  1 = The state of the debug registers in the Core power domain has been lost. */
        uint32_t pu                    : 1;  /**< [  0:  0](RO) Core power-up status bit. Indicates whether the Core power
                                                                     domain debug registers can be accessed:
                                                                 0 = Core is in a low-power or power-down state where the debug
                                                                     registers cannot be accessed.
                                                                 1 = Core is in a power-up state where the debug registers can be
                                                                     accessed. */
#else /* Word 0 - Little Endian */
        uint32_t pu                    : 1;  /**< [  0:  0](RO) Core power-up status bit. Indicates whether the Core power
                                                                     domain debug registers can be accessed:
                                                                 0 = Core is in a low-power or power-down state where the debug
                                                                     registers cannot be accessed.
                                                                 1 = Core is in a power-up state where the debug registers can be
                                                                     accessed. */
        uint32_t spd                   : 1;  /**< [  1:  1](RO) Sticky core power-down status bit. This bit is UNKNOWN on
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
                                                                 * Retention: The states of the debug registers, including
                                                                     EDPRSR.SPD, in the Core power domain is preserved, and
                                                                     restored on leaving retention state.
                                                                 * Power-down: The states of the debug registers in the Core
                                                                     power domain is lost, and a Cold reset is asserted on leaving
                                                                     power-down state.

                                                                  If EDPRSR.PU is zero,
                                                                  0 = It is now known whether the state of the degug regsiters in the Core power domain is
                                                                 lost.
                                                                  1 = The state fo the debug registers int he Core power domain is lost

                                                                  If EDPRSR.PU is one,
                                                                  0 = The state of the debug registers in the Core power domain has not been lost.
                                                                  1 = The state of the debug registers in the Core power domain has been lost. */
        uint32_t r                     : 1;  /**< [  2:  2](RO) Core reset status bit. This bit is UNKNOWN on reads if either
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 0 = The non-debug logic of the processor is not in reset state.
                                                                 1 = The non-debug logic of the processor is in reset state. */
        uint32_t sr                    : 1;  /**< [  3:  3](RO) Sticky core reset status bit. This bit is UNKNOWN on reads if
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 This bit clears to 0 following a read of EDPRSR if the non-
                                                                     debug logic of the processor is not in reset state.
                                                                 0 = The non-debug logic of the processor is not in reset state and
                                                                     has not been reset since the last time EDPRSR was read.
                                                                 1 = The non-debug logic of the processor is in reset state or has
                                                                     been reset since the last time EDPRSR was read. */
        uint32_t halted                : 1;  /**< [  4:  4](RO) Halted status bit. This bit is UNKNOWN on reads if EDPRSR.PU
                                                                     is zero, 0 if EDSCR.STATUS == 0x2, 1 if EDSCR.STATUS != 0x2. */
        uint32_t oslk                  : 1;  /**< [  5:  5](RO) OS lock status bit. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1 or EDPRSR.PU is zero. Otherwise, a read
                                                                     returns the value of OSLSR_EL1.OSLK. */
        uint32_t dlk                   : 1;  /**< [  6:  6](RO) OS double-lock status bit.
                                                                 This bit is UNKNOWN on reads if EDPRSR.PU is zero.
                                                                 0 = OSDLR_EL1.DLK = 0 or EDPRCR.CORENPDRQ = 1 or the processor
                                                                     is in debug state.
                                                                 1 = OSDLR_EL1.DLK = 1 and EDPRCR.CORENPDRQ = 0 and the processor
                                                                     is in non-debug state. */
        uint32_t edad                  : 1;  /**< [  7:  7](RO) External debug access disable status.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 0 = External debug access enabled.
                                                                 1 = External debug access disabled. */
        uint32_t sdad                  : 1;  /**< [  8:  8](RO) Sticky EDAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalDebugAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 following a read of EDPRSR.
                                                                 0 = No accesses to the external debug registers have failed since
                                                                     EDPRSR was last read.
                                                                 1 = At least one access to the external debug registers has failed
                                                                     since EDPRSR was last read. */
        uint32_t epmad                 : 1;  /**< [  9:  9](RO) External performance monitors access disable status.
                                                                 If external performance monitors access is not implemented,
                                                                     EPMAD is RAO. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1, or EDPRSR.PU is zero.
                                                                 0 = External performance monitors access enabled.
                                                                 1 = External performance monitors access disabled. */
        uint32_t spmad                 : 1;  /**< [ 10: 10](RO) Sticky EPMAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalPMUAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 0 = No accesses to the external performance monitors registers
                                                                     have failed since EDPRSR was last read.
                                                                 1 = At least one access to the external performance monitors
                                                                     registers has failed since EDPRSR was last read. */
        uint32_t sdr                   : 1;  /**< [ 11: 11](RO) Sticky debug restart. Set to 1 when the processor exits Debug
                                                                     state and cleared to 0 following reads of EDPRSR.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 0 = The processor has not restarted since EDPRSR was last read.
                                                                 1 = The processor has restarted since EDPRSR was last read. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edprsr_s cn83xx; */
    /* struct bdk_dbgx_edprsr_s cn88xxp2; */
    struct bdk_dbgx_edprsr_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t sdr                   : 1;  /**< [ 11: 11](RO) Sticky debug restart. Set to 1 when the processor exits Debug
                                                                     state and cleared to 0 following reads of EDPRSR.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 <0> The processor has not restarted since EDPRSR was last read.
                                                                 <1> The processor has restarted since EDPRSR was last read. */
        uint32_t spmad                 : 1;  /**< [ 10: 10](RO) Sticky EPMAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalPMUAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 <0> No accesses to the external performance monitors registers
                                                                     have failed since EDPRSR was last read.
                                                                 <1> At least one access to the external performance monitors
                                                                     registers has failed since EDPRSR was last read. */
        uint32_t epmad                 : 1;  /**< [  9:  9](RO) External performance monitors access disable status.
                                                                 If external performance monitors access is not implemented,
                                                                     EPMAD is RAO. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1, or EDPRSR.PU is zero.
                                                                 <0> External performance monitors access enabled.
                                                                 <1> External performance monitors access disabled. */
        uint32_t sdad                  : 1;  /**< [  8:  8](RO) Sticky EDAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalDebugAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 following a read of EDPRSR.
                                                                 <0> No accesses to the external debug registers have failed since
                                                                     EDPRSR was last read.
                                                                 <1> At least one access to the external debug registers has failed
                                                                     since EDPRSR was last read. */
        uint32_t edad                  : 1;  /**< [  7:  7](RO) External debug access disable status.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 <0> External debug access enabled.
                                                                 <1> External debug access disabled. */
        uint32_t dlk                   : 1;  /**< [  6:  6](RO) OS double-lock status bit.
                                                                 This bit is UNKNOWN on reads if EDPRSR.PU is zero.
                                                                 <0> OSDLR_EL1.DLK == 0 or EDPRCR.CORENPDRQ == 1 or the processor
                                                                     is in Debug state.
                                                                 <1> OSDLR_EL1.DLK == 1 and EDPRCR.CORENPDRQ == 0 and the processor
                                                                     is in Non-debug state. */
        uint32_t oslk                  : 1;  /**< [  5:  5](RO) OS lock status bit. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1 or EDPRSR.PU is zero. Otherwise, a read
                                                                     returns the value of OSLSR_EL1.OSLK. */
        uint32_t halted                : 1;  /**< [  4:  4](RO) Halted status bit. This bit is UNKNOWN on reads if EDPRSR.PU
                                                                     is zero, 0 if EDSCR.STATUS == 0x2, 1 if EDSCR.STATUS != 0x2. */
        uint32_t sr                    : 1;  /**< [  3:  3](RO) Sticky core reset status bit. This bit is UNKNOWN on reads if
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 This bit clears to 0 following a read of EDPRSR if the non-
                                                                     debug logic of the processor is not in reset state.
                                                                 <0> The non-debug logic of the processor is not in reset state and
                                                                     has not been reset since the last time EDPRSR was read.
                                                                 <1> The non-debug logic of the processor is in reset state or has
                                                                     been reset since the last time EDPRSR was read. */
        uint32_t r                     : 1;  /**< [  2:  2](RO) Core reset status bit. This bit is UNKNOWN on reads if either
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 <0> The non-debug logic of the processor is not in reset state.
                                                                 <1> The non-debug logic of the processor is in reset state. */
        uint32_t spd                   : 1;  /**< [  1:  1](RO) Sticky core power-down status bit. This bit is UNKNOWN on
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
                                                                  If EDPRSR.PU is zero,
                                                                  <0> It is now known whether the state of the degug regsiters in the Core power domain is
                                                                 lost.
                                                                  <1> The state fo the debug registers int he Core power domain is lost
                                                                  If EDPRSR.PU is one,
                                                                  <0> The state of the debug registers in the Core power domain has not been lost.
                                                                  <1> The state of the debug registers in the Core power domain has been lost. */
        uint32_t pu                    : 1;  /**< [  0:  0](RO) Core power-up status bit. Indicates whether the Core power
                                                                     domain debug registers can be accessed:
                                                                 <0> Core is in a low-power or power-down state where the debug
                                                                     registers cannot be accessed.
                                                                 <1> Core is in a power-up state where the debug registers can be
                                                                     accessed. */
#else /* Word 0 - Little Endian */
        uint32_t pu                    : 1;  /**< [  0:  0](RO) Core power-up status bit. Indicates whether the Core power
                                                                     domain debug registers can be accessed:
                                                                 <0> Core is in a low-power or power-down state where the debug
                                                                     registers cannot be accessed.
                                                                 <1> Core is in a power-up state where the debug registers can be
                                                                     accessed. */
        uint32_t spd                   : 1;  /**< [  1:  1](RO) Sticky core power-down status bit. This bit is UNKNOWN on
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
                                                                  If EDPRSR.PU is zero,
                                                                  <0> It is now known whether the state of the degug regsiters in the Core power domain is
                                                                 lost.
                                                                  <1> The state fo the debug registers int he Core power domain is lost
                                                                  If EDPRSR.PU is one,
                                                                  <0> The state of the debug registers in the Core power domain has not been lost.
                                                                  <1> The state of the debug registers in the Core power domain has been lost. */
        uint32_t r                     : 1;  /**< [  2:  2](RO) Core reset status bit. This bit is UNKNOWN on reads if either
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 <0> The non-debug logic of the processor is not in reset state.
                                                                 <1> The non-debug logic of the processor is in reset state. */
        uint32_t sr                    : 1;  /**< [  3:  3](RO) Sticky core reset status bit. This bit is UNKNOWN on reads if
                                                                     EDPRSR.DLK is 1 or EDPRSR.PU is zero. Otherwise its possible
                                                                     values are:
                                                                 This bit clears to 0 following a read of EDPRSR if the non-
                                                                     debug logic of the processor is not in reset state.
                                                                 <0> The non-debug logic of the processor is not in reset state and
                                                                     has not been reset since the last time EDPRSR was read.
                                                                 <1> The non-debug logic of the processor is in reset state or has
                                                                     been reset since the last time EDPRSR was read. */
        uint32_t halted                : 1;  /**< [  4:  4](RO) Halted status bit. This bit is UNKNOWN on reads if EDPRSR.PU
                                                                     is zero, 0 if EDSCR.STATUS == 0x2, 1 if EDSCR.STATUS != 0x2. */
        uint32_t oslk                  : 1;  /**< [  5:  5](RO) OS lock status bit. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1 or EDPRSR.PU is zero. Otherwise, a read
                                                                     returns the value of OSLSR_EL1.OSLK. */
        uint32_t dlk                   : 1;  /**< [  6:  6](RO) OS double-lock status bit.
                                                                 This bit is UNKNOWN on reads if EDPRSR.PU is zero.
                                                                 <0> OSDLR_EL1.DLK == 0 or EDPRCR.CORENPDRQ == 1 or the processor
                                                                     is in Debug state.
                                                                 <1> OSDLR_EL1.DLK == 1 and EDPRCR.CORENPDRQ == 0 and the processor
                                                                     is in Non-debug state. */
        uint32_t edad                  : 1;  /**< [  7:  7](RO) External debug access disable status.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 <0> External debug access enabled.
                                                                 <1> External debug access disabled. */
        uint32_t sdad                  : 1;  /**< [  8:  8](RO) Sticky EDAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalDebugAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 following a read of EDPRSR.
                                                                 <0> No accesses to the external debug registers have failed since
                                                                     EDPRSR was last read.
                                                                 <1> At least one access to the external debug registers has failed
                                                                     since EDPRSR was last read. */
        uint32_t epmad                 : 1;  /**< [  9:  9](RO) External performance monitors access disable status.
                                                                 If external performance monitors access is not implemented,
                                                                     EPMAD is RAO. This bit is UNKNOWN on reads if either of
                                                                     EDPRSR.{DLK, R} is 1, or EDPRSR.PU is zero.
                                                                 <0> External performance monitors access enabled.
                                                                 <1> External performance monitors access disabled. */
        uint32_t spmad                 : 1;  /**< [ 10: 10](RO) Sticky EPMAD error. Set to 1 if an access returns an error
                                                                     because AllowExternalPMUAccess() == FALSE.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 <0> No accesses to the external performance monitors registers
                                                                     have failed since EDPRSR was last read.
                                                                 <1> At least one access to the external performance monitors
                                                                     registers has failed since EDPRSR was last read. */
        uint32_t sdr                   : 1;  /**< [ 11: 11](RO) Sticky debug restart. Set to 1 when the processor exits Debug
                                                                     state and cleared to 0 following reads of EDPRSR.
                                                                 This bit is UNKNOWN on reads if either of EDPRSR.{DLK, R} is
                                                                     1, or EDPRSR.PU is zero.
                                                                 This bit clears to 0 when following a read of EDPRSR.
                                                                 <0> The processor has not restarted since EDPRSR was last read.
                                                                 <1> The processor has restarted since EDPRSR was last read. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_dbgx_edprsr_t;

static inline uint64_t BDK_DBGX_EDPRSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDPRSR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000314ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDPRSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDPRSR(a) bdk_dbgx_edprsr_t
#define bustype_BDK_DBGX_EDPRSR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDPRSR(a) "DBGX_EDPRSR"
#define busnum_BDK_DBGX_EDPRSR(a) (a)
#define arguments_BDK_DBGX_EDPRSR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edrcr
 *
 * AP DBG External Debug Reserve Control Register
 * This register is used to allow imprecise entry to Debug state
 *     and clear sticky bits in EDSCR.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edrcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_5_31         : 27;
        uint32_t cbrrq                 : 1;  /**< [  4:  4](RO) Imprecise entry to debug state not suppported.  This bit is write ignore. */
        uint32_t cspa                  : 1;  /**< [  3:  3](WO) Clear Sticky Pipeline Advance. This bit is used to clear the
                                                                     EDSCR.PipeAdv bit to 0. The actions on writing to this bit
                                                                     are:
                                                                 <0> No action.
                                                                 <1> Clear the EDSCR.PipeAdv bit to 0. */
        uint32_t cse                   : 1;  /**< [  2:  2](WO) Clear Sticky Error. Used to clear the EDSCR cumulative error
                                                                     bits to 0. The actions on writing to this bit are:
                                                                 <0> No action.
                                                                 <1> Clear the EDSCR.{TXU, RXO, ERR} bits, and, if the processor is
                                                                     in Debug state, the EDSCR.ITO bit, to 0. */
        uint32_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_1          : 2;
        uint32_t cse                   : 1;  /**< [  2:  2](WO) Clear Sticky Error. Used to clear the EDSCR cumulative error
                                                                     bits to 0. The actions on writing to this bit are:
                                                                 <0> No action.
                                                                 <1> Clear the EDSCR.{TXU, RXO, ERR} bits, and, if the processor is
                                                                     in Debug state, the EDSCR.ITO bit, to 0. */
        uint32_t cspa                  : 1;  /**< [  3:  3](WO) Clear Sticky Pipeline Advance. This bit is used to clear the
                                                                     EDSCR.PipeAdv bit to 0. The actions on writing to this bit
                                                                     are:
                                                                 <0> No action.
                                                                 <1> Clear the EDSCR.PipeAdv bit to 0. */
        uint32_t cbrrq                 : 1;  /**< [  4:  4](RO) Imprecise entry to debug state not suppported.  This bit is write ignore. */
        uint32_t reserved_5_31         : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edrcr_s cn; */
} bdk_dbgx_edrcr_t;

static inline uint64_t BDK_DBGX_EDRCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDRCR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000090ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDRCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDRCR(a) bdk_dbgx_edrcr_t
#define bustype_BDK_DBGX_EDRCR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDRCR(a) "DBGX_EDRCR"
#define busnum_BDK_DBGX_EDRCR(a) (a)
#define arguments_BDK_DBGX_EDRCR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edscr
 *
 * AP DBG External Debug Status and Control Register
 * This is the main control register for the debug implementation.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edscr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t rxfull                : 1;  /**< [ 30: 30](RO) DTRRX is full. */
        uint32_t txfull                : 1;  /**< [ 29: 29](RO) DTRTX is full. */
        uint32_t ito                   : 1;  /**< [ 28: 28](RO) EDITR overrun.
                                                                 If the processor is not in the Debug state, this bit is UNKNOWN.
                                                                     ITO is set to 0 on entry to Debug state. */
        uint32_t rxo                   : 1;  /**< [ 27: 27](RO) Indicates DTRRX overrun. */
        uint32_t txu                   : 1;  /**< [ 26: 26](RO) Indicates DTRTX underrun. */
        uint32_t pipeadv               : 1;  /**< [ 25: 25](RO) Pipeline advance. This bit is set to 1 every time the processor
                                                                     pipeline retires one or more instructions. Cleared to 0 by a
                                                                     write to DBG()_EDRCR[CSPA].

                                                                 The architecture does not define precisely when this bit is
                                                                     set to 1. It requires only that this happen periodically in
                                                                     nondebug state to indicate that software execution is
                                                                     progressing. */
        uint32_t ite                   : 1;  /**< [ 24: 24](RO) ITR empty.
                                                                 If the processor is not in the debug state, this bit is UNKNOWN.
                                                                     It is always valid in the debug state.  When set to 1, the ITR is empty. */
        uint32_t intdis                : 2;  /**< [ 23: 22](R/W) Interrupt disable. Disables taking interrupts (including
                                                                     virtual interrupts and System Error interrupts) in nondebug
                                                                     state.

                                                                 The value of this field does not affect whether an interrupt is a
                                                                     WFI wake-up event, but can mask an interrupt as a WFE wake-up
                                                                     event.
                                                                 If EL3 and EL2 are not implemented, INTDIS<0> is RO and reads
                                                                     the same value as INTDIS<1>, meaning only the values0b000b11.
                                                                 If external-invasive debug is disabled, the value of this
                                                                     field is ignored.
                                                                 If external-invasive debug is enabled, the possible values of
                                                                     this field are:
                                                                 0x0 = Do not disable interrupts.
                                                                 0x1 = Disable interrupts targeting Non-secure EL1.
                                                                 0x2 = Disable interrupts targeting only nonsecure EL1 and nonsecure EL2. If external
                                                                 secure invasive debug is enabled, also
                                                                     disable interrupts targeting Secure EL1.
                                                                 0x3 = Disable interrupts targeting only nonsecure EL1 and non
                                                                     secure EL2. If external secure invasive debug is enabled, also
                                                                     disable all other interrupts. */
        uint32_t tda                   : 1;  /**< [ 21: 21](R/W) Trap debug registers accesses unless OSLSR_EL1.OSLCK = 1 or halting is prohibited.
                                                                 Affected registeres are the DBG()_DBGBVR()_EL1_LO, DBG()_DBGBVR()_EL1_HI,
                                                                 DBG()_DBGBCR()_EL1, DBG()_DBGWVR()_EL1_LO, DBG()_DBGWVR()_EL1_HI, and DBG()_DBGWCR()_EL1. */
        uint32_t ma                    : 1;  /**< [ 20: 20](R/W) Memory-access mode. Controls use of memory-access mode for
                                                                     accessing EDITR and the DCC. This bit is ignored if in non
                                                                     debug state and set to 0 on entry to debug state.
                                                                 Possible values of this field are:

                                                                 0 = Normal access mode.
                                                                 1 = Memory access mode. */
        uint32_t reserved_19           : 1;
        uint32_t nsec                  : 1;  /**< [ 18: 18](RO) Nonsecure status (NS). When in debug state, gives the
                                                                     current security state.
                                                                 In nondebug state, this bit is UNKNOWN.

                                                                 0 = Secure state, IsSecure() == TRUE.
                                                                 1 = Nonsecure state, IsSecure() == FALSE. */
        uint32_t reserved_17           : 1;
        uint32_t sdd                   : 1;  /**< [ 16: 16](RO) Secure debug disabled.

                                                                 On entry to Debug state:
                                                                    If entering in secure state, SDD is set to 0.
                                                                    If entering in nonsecure state, SDD is set to the inverse of
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

                                                                 If EL3 is not implemented and the implementation is non
                                                                     secure, this bit is reserved. */
        uint32_t reserved_15           : 1;
        uint32_t hde                   : 1;  /**< [ 14: 14](R/W) Halting debug mode enable.

                                                                 0 = Halting debug mode disabled.
                                                                 1 = Halting debug mode enabled. */
        uint32_t rw                    : 4;  /**< [ 13: 10](RO) Exception level register-width status. Read-only. In debug
                                                                     state, each bit gives the current register width status of
                                                                     each EL:
                                                                 However:
                                                                  If not at EL0: RW[0] == RW[1].
                                                                  If EL2 is not implemented in the current security state:
                                                                     RW[2] == RW[1].
                                                                  If EL3 is not implemented: RW[3] == RW[2].
                                                                 In Non-debug state, this field is RAO.
                                                                 <1111>      All exception levels are AArch64 state.
                                                                 <1110>      EL0 is AArch32 state. All other exception levels are AArch64
                                                                     state.
                                                                 <1100>      EL0 and EL1 are AArch32 state. All other exception levels are
                                                                     AArch64 state. Never seen if EL2 is not implemented in the
                                                                     current security state.
                                                                 <1000>      EL0, EL1, and, if implemented in the current security state,
                                                                     EL2 are AArch32 state. All other exception levels are AArch64
                                                                     state.
                                                                 <0000>      All exception levels are set to AArch32 state (32-bit
                                                                     configuration).

                                                                 In CNXXXX, this field is always <1111>..  All other values will be ignored. */
        uint32_t el                    : 2;  /**< [  9:  8](RO) Exception level.  In Debug state, this gives the
                                                                     current EL of the processor.
                                                                 In Non-debug state, this field is RAZ. */
        uint32_t aa                    : 1;  /**< [  7:  7](RO) System Error interrupt (asynchronous abort) pending.
                                                                     In Debug state, indicates whether a SError interrupt is
                                                                     pending:
                                                                  If HCR_EL2.{AMO, TGE} = {1, 0} and in Non-secure EL0 or EL1,
                                                                     a virtual SError interrupt.
                                                                  Otherwise, a physical SError interrupt.
                                                                 A debugger can read EDSCR to check whether a SError interrupt
                                                                     is pending without having to execute further instructions. A
                                                                     pending SError might indicate data from target memory is
                                                                     corrupted.
                                                                  UNKNOWN in Non-debug state.
                                                                 <0> No SError interrupt pending.
                                                                 <1> SError interrupt pending. */
        uint32_t errflg                : 1;  /**< [  6:  6](RO) Cumulative error flag. It is set to 1
                                                                     following exceptions in Debug state and on any signaled
                                                                     overrun or underrun on the DTR or EDITR. */
        uint32_t status                : 6;  /**< [  5:  0](RO) Debug status flags.
                                                                 The possible values of this field are:
                                                                 All other values of STATUS are reserved.
                                                                 <000010>    Processor is in Non-debug state.
                                                                 <000001>    Processor is restarting (exiting Debug state).
                                                                 <000111>    Breakpoint.
                                                                 <010011>    External debug request.
                                                                 <011011>    Halting step, normal.
                                                                 <011111>    Halting step, exclusive.
                                                                 <100011>    OS unlock catch.
                                                                 <100111>    Reset catch.
                                                                 <101011>    Watchpoint.
                                                                 <101111>    HLT instruction.
                                                                 <110011>    Software access to debug register.
                                                                 <110111>    Exception catch.
                                                                 <111011>    Halting step, no syndrome. */
#else /* Word 0 - Little Endian */
        uint32_t status                : 6;  /**< [  5:  0](RO) Debug status flags.
                                                                 The possible values of this field are:
                                                                 All other values of STATUS are reserved.
                                                                 <000010>    Processor is in Non-debug state.
                                                                 <000001>    Processor is restarting (exiting Debug state).
                                                                 <000111>    Breakpoint.
                                                                 <010011>    External debug request.
                                                                 <011011>    Halting step, normal.
                                                                 <011111>    Halting step, exclusive.
                                                                 <100011>    OS unlock catch.
                                                                 <100111>    Reset catch.
                                                                 <101011>    Watchpoint.
                                                                 <101111>    HLT instruction.
                                                                 <110011>    Software access to debug register.
                                                                 <110111>    Exception catch.
                                                                 <111011>    Halting step, no syndrome. */
        uint32_t errflg                : 1;  /**< [  6:  6](RO) Cumulative error flag. It is set to 1
                                                                     following exceptions in Debug state and on any signaled
                                                                     overrun or underrun on the DTR or EDITR. */
        uint32_t aa                    : 1;  /**< [  7:  7](RO) System Error interrupt (asynchronous abort) pending.
                                                                     In Debug state, indicates whether a SError interrupt is
                                                                     pending:
                                                                  If HCR_EL2.{AMO, TGE} = {1, 0} and in Non-secure EL0 or EL1,
                                                                     a virtual SError interrupt.
                                                                  Otherwise, a physical SError interrupt.
                                                                 A debugger can read EDSCR to check whether a SError interrupt
                                                                     is pending without having to execute further instructions. A
                                                                     pending SError might indicate data from target memory is
                                                                     corrupted.
                                                                  UNKNOWN in Non-debug state.
                                                                 <0> No SError interrupt pending.
                                                                 <1> SError interrupt pending. */
        uint32_t el                    : 2;  /**< [  9:  8](RO) Exception level.  In Debug state, this gives the
                                                                     current EL of the processor.
                                                                 In Non-debug state, this field is RAZ. */
        uint32_t rw                    : 4;  /**< [ 13: 10](RO) Exception level register-width status. Read-only. In debug
                                                                     state, each bit gives the current register width status of
                                                                     each EL:
                                                                 However:
                                                                  If not at EL0: RW[0] == RW[1].
                                                                  If EL2 is not implemented in the current security state:
                                                                     RW[2] == RW[1].
                                                                  If EL3 is not implemented: RW[3] == RW[2].
                                                                 In Non-debug state, this field is RAO.
                                                                 <1111>      All exception levels are AArch64 state.
                                                                 <1110>      EL0 is AArch32 state. All other exception levels are AArch64
                                                                     state.
                                                                 <1100>      EL0 and EL1 are AArch32 state. All other exception levels are
                                                                     AArch64 state. Never seen if EL2 is not implemented in the
                                                                     current security state.
                                                                 <1000>      EL0, EL1, and, if implemented in the current security state,
                                                                     EL2 are AArch32 state. All other exception levels are AArch64
                                                                     state.
                                                                 <0000>      All exception levels are set to AArch32 state (32-bit
                                                                     configuration).

                                                                 In CNXXXX, this field is always <1111>..  All other values will be ignored. */
        uint32_t hde                   : 1;  /**< [ 14: 14](R/W) Halting debug mode enable.

                                                                 0 = Halting debug mode disabled.
                                                                 1 = Halting debug mode enabled. */
        uint32_t reserved_15           : 1;
        uint32_t sdd                   : 1;  /**< [ 16: 16](RO) Secure debug disabled.

                                                                 On entry to Debug state:
                                                                    If entering in secure state, SDD is set to 0.
                                                                    If entering in nonsecure state, SDD is set to the inverse of
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

                                                                 If EL3 is not implemented and the implementation is non
                                                                     secure, this bit is reserved. */
        uint32_t reserved_17           : 1;
        uint32_t nsec                  : 1;  /**< [ 18: 18](RO) Nonsecure status (NS). When in debug state, gives the
                                                                     current security state.
                                                                 In nondebug state, this bit is UNKNOWN.

                                                                 0 = Secure state, IsSecure() == TRUE.
                                                                 1 = Nonsecure state, IsSecure() == FALSE. */
        uint32_t reserved_19           : 1;
        uint32_t ma                    : 1;  /**< [ 20: 20](R/W) Memory-access mode. Controls use of memory-access mode for
                                                                     accessing EDITR and the DCC. This bit is ignored if in non
                                                                     debug state and set to 0 on entry to debug state.
                                                                 Possible values of this field are:

                                                                 0 = Normal access mode.
                                                                 1 = Memory access mode. */
        uint32_t tda                   : 1;  /**< [ 21: 21](R/W) Trap debug registers accesses unless OSLSR_EL1.OSLCK = 1 or halting is prohibited.
                                                                 Affected registeres are the DBG()_DBGBVR()_EL1_LO, DBG()_DBGBVR()_EL1_HI,
                                                                 DBG()_DBGBCR()_EL1, DBG()_DBGWVR()_EL1_LO, DBG()_DBGWVR()_EL1_HI, and DBG()_DBGWCR()_EL1. */
        uint32_t intdis                : 2;  /**< [ 23: 22](R/W) Interrupt disable. Disables taking interrupts (including
                                                                     virtual interrupts and System Error interrupts) in nondebug
                                                                     state.

                                                                 The value of this field does not affect whether an interrupt is a
                                                                     WFI wake-up event, but can mask an interrupt as a WFE wake-up
                                                                     event.
                                                                 If EL3 and EL2 are not implemented, INTDIS<0> is RO and reads
                                                                     the same value as INTDIS<1>, meaning only the values0b000b11.
                                                                 If external-invasive debug is disabled, the value of this
                                                                     field is ignored.
                                                                 If external-invasive debug is enabled, the possible values of
                                                                     this field are:
                                                                 0x0 = Do not disable interrupts.
                                                                 0x1 = Disable interrupts targeting Non-secure EL1.
                                                                 0x2 = Disable interrupts targeting only nonsecure EL1 and nonsecure EL2. If external
                                                                 secure invasive debug is enabled, also
                                                                     disable interrupts targeting Secure EL1.
                                                                 0x3 = Disable interrupts targeting only nonsecure EL1 and non
                                                                     secure EL2. If external secure invasive debug is enabled, also
                                                                     disable all other interrupts. */
        uint32_t ite                   : 1;  /**< [ 24: 24](RO) ITR empty.
                                                                 If the processor is not in the debug state, this bit is UNKNOWN.
                                                                     It is always valid in the debug state.  When set to 1, the ITR is empty. */
        uint32_t pipeadv               : 1;  /**< [ 25: 25](RO) Pipeline advance. This bit is set to 1 every time the processor
                                                                     pipeline retires one or more instructions. Cleared to 0 by a
                                                                     write to DBG()_EDRCR[CSPA].

                                                                 The architecture does not define precisely when this bit is
                                                                     set to 1. It requires only that this happen periodically in
                                                                     nondebug state to indicate that software execution is
                                                                     progressing. */
        uint32_t txu                   : 1;  /**< [ 26: 26](RO) Indicates DTRTX underrun. */
        uint32_t rxo                   : 1;  /**< [ 27: 27](RO) Indicates DTRRX overrun. */
        uint32_t ito                   : 1;  /**< [ 28: 28](RO) EDITR overrun.
                                                                 If the processor is not in the Debug state, this bit is UNKNOWN.
                                                                     ITO is set to 0 on entry to Debug state. */
        uint32_t txfull                : 1;  /**< [ 29: 29](RO) DTRTX is full. */
        uint32_t rxfull                : 1;  /**< [ 30: 30](RO) DTRRX is full. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edscr_s cn; */
} bdk_dbgx_edscr_t;

static inline uint64_t BDK_DBGX_EDSCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDSCR(unsigned long a)
{
    if (a<=47)
        return 0x87a008000088ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDSCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDSCR(a) bdk_dbgx_edscr_t
#define bustype_BDK_DBGX_EDSCR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDSCR(a) "DBGX_EDSCR"
#define busnum_BDK_DBGX_EDSCR(a) (a)
#define arguments_BDK_DBGX_EDSCR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edvidsr
 *
 * AP DBG External Debug Virtual Context Sample Register
 * Contains sampled values captured on reading EDPCSR.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edvidsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t non_secure            : 1;  /**< [ 31: 31](RO) Non-secure state sample. Indicates the security state
                                                                     associated with the most recent EDPCSR sample. */
        uint32_t e2                    : 1;  /**< [ 30: 30](RO) Exception level 2 status sample. Indicates whether the most
                                                                     recent EDPCSR sample was associated with EL2. If EDVIDSR.NS ==
                                                                     0, this bit is 0. */
        uint32_t e3                    : 1;  /**< [ 29: 29](RO) Exception level 3 status sample. Indicates whether the most
                                                                     recent EDPCSR sample was associated with AArch64 EL3. If
                                                                     EDVIDSR.NS == 1 or the processor was in AArch32 state when
                                                                     EDPCSR was read, this bit is 0. */
        uint32_t hv                    : 1;  /**< [ 28: 28](RO) EDPCSR high half valid. Indicates whether bits [63:32] of the
                                                                    most recent EDPCSR sample are valid. If EDVIDSR.HV == 0, the
                                                                    value of EDPCSR[63:32] is RAZ. */
        uint32_t reserved_8_27         : 20;
        uint32_t vmid                  : 8;  /**< [  7:  0](RO) VMID sample. The value of VTTBR_EL2.VMID associated with the
                                                                     most recent EDPCSR sample. If EDVIDSR.NS == 0 or EDVIDSR.E2 ==
                                                                     1, this field is RAZ. */
#else /* Word 0 - Little Endian */
        uint32_t vmid                  : 8;  /**< [  7:  0](RO) VMID sample. The value of VTTBR_EL2.VMID associated with the
                                                                     most recent EDPCSR sample. If EDVIDSR.NS == 0 or EDVIDSR.E2 ==
                                                                     1, this field is RAZ. */
        uint32_t reserved_8_27         : 20;
        uint32_t hv                    : 1;  /**< [ 28: 28](RO) EDPCSR high half valid. Indicates whether bits [63:32] of the
                                                                    most recent EDPCSR sample are valid. If EDVIDSR.HV == 0, the
                                                                    value of EDPCSR[63:32] is RAZ. */
        uint32_t e3                    : 1;  /**< [ 29: 29](RO) Exception level 3 status sample. Indicates whether the most
                                                                     recent EDPCSR sample was associated with AArch64 EL3. If
                                                                     EDVIDSR.NS == 1 or the processor was in AArch32 state when
                                                                     EDPCSR was read, this bit is 0. */
        uint32_t e2                    : 1;  /**< [ 30: 30](RO) Exception level 2 status sample. Indicates whether the most
                                                                     recent EDPCSR sample was associated with EL2. If EDVIDSR.NS ==
                                                                     0, this bit is 0. */
        uint32_t non_secure            : 1;  /**< [ 31: 31](RO) Non-secure state sample. Indicates the security state
                                                                     associated with the most recent EDPCSR sample. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edvidsr_s cn; */
} bdk_dbgx_edvidsr_t;

static inline uint64_t BDK_DBGX_EDVIDSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDVIDSR(unsigned long a)
{
    if (a<=47)
        return 0x87a0080000a8ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDVIDSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDVIDSR(a) bdk_dbgx_edvidsr_t
#define bustype_BDK_DBGX_EDVIDSR(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDVIDSR(a) "DBGX_EDVIDSR"
#define busnum_BDK_DBGX_EDVIDSR(a) (a)
#define arguments_BDK_DBGX_EDVIDSR(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edwar_hi
 *
 * AP DBG External Debug Watchpoint Address High Register
 * Watchpoint register high half.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edwar_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 32; /**< [ 31:  0](RO) Records bits <63:32> of the data virtual address being accessed when a Watchpoint debug
                                                                 event occurs. */
#else /* Word 0 - Little Endian */
        uint32_t address               : 32; /**< [ 31:  0](RO) Records bits <63:32> of the data virtual address being accessed when a Watchpoint debug
                                                                 event occurs. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edwar_hi_s cn; */
} bdk_dbgx_edwar_hi_t;

static inline uint64_t BDK_DBGX_EDWAR_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDWAR_HI(unsigned long a)
{
    if (a<=47)
        return 0x87a008000034ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDWAR_HI", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDWAR_HI(a) bdk_dbgx_edwar_hi_t
#define bustype_BDK_DBGX_EDWAR_HI(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDWAR_HI(a) "DBGX_EDWAR_HI"
#define busnum_BDK_DBGX_EDWAR_HI(a) (a)
#define arguments_BDK_DBGX_EDWAR_HI(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_edwar_lo
 *
 * AP DBG External Debug Watchpoint Address Low Register
 * Watchpoint register low half.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_edwar_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t address               : 32; /**< [ 31:  0](RO) Records bits <31:0> of the data virtual address being accessed when a Watchpoint debug
                                                                 event
                                                                 occurs. */
#else /* Word 0 - Little Endian */
        uint32_t address               : 32; /**< [ 31:  0](RO) Records bits <31:0> of the data virtual address being accessed when a Watchpoint debug
                                                                 event
                                                                 occurs. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_edwar_lo_s cn; */
} bdk_dbgx_edwar_lo_t;

static inline uint64_t BDK_DBGX_EDWAR_LO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_EDWAR_LO(unsigned long a)
{
    if (a<=47)
        return 0x87a008000030ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_EDWAR_LO", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_EDWAR_LO(a) bdk_dbgx_edwar_lo_t
#define bustype_BDK_DBGX_EDWAR_LO(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_EDWAR_LO(a) "DBGX_EDWAR_LO"
#define busnum_BDK_DBGX_EDWAR_LO(a) (a)
#define arguments_BDK_DBGX_EDWAR_LO(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_midr_el1
 *
 * AP DBG Main Id Register
 * Main id register for ap core.
 * Read only register
 * INTERNAL: RTL: Read to this register will be provided by DAP and
 * DAP will not generate OWB access.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_midr_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t implementer           : 8;  /**< [ 31: 24](RO) Implementor field - Cavium - 0x43.
                                                                 The Implementer code. This field must hold an implementer code
                                                                     that has been assigned by ARM. Assigned codes include the
                                                                     following:

                                                                 <pre>
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
                                                                 </pre> */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field - used by CNXXXX to indicate major pass number. */
        uint32_t architecture          : 4;  /**< [ 19: 16](RO) Architecure field.
                                                                 The permitted values of this field are:
                                                                 All other values are reserved.
                                                                 <0001>      ARMv4
                                                                 <0010>      ARMv4T
                                                                 <0011>      ARMv5 (obsolete)
                                                                 <0100>      ARMv5T
                                                                 <0101>      ARMv5TE
                                                                 <0110>      ARMv5TEJ
                                                                 <0111>      ARMv6
                                                                 <1111>      Defined by CPUID scheme */
        uint32_t partnum               : 12; /**< [ 15:  4](RO) Part number field.
                                                                 An implementation defined primary part number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
        uint32_t revision              : 4;  /**< [  3:  0](RO) Revision field.
                                                                 An implementation defined revision number for the device.
                                                                 In CNXXXX, the minor pass number. */
#else /* Word 0 - Little Endian */
        uint32_t revision              : 4;  /**< [  3:  0](RO) Revision field.
                                                                 An implementation defined revision number for the device.
                                                                 In CNXXXX, the minor pass number. */
        uint32_t partnum               : 12; /**< [ 15:  4](RO) Part number field.
                                                                 An implementation defined primary part number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
        uint32_t architecture          : 4;  /**< [ 19: 16](RO) Architecure field.
                                                                 The permitted values of this field are:
                                                                 All other values are reserved.
                                                                 <0001>      ARMv4
                                                                 <0010>      ARMv4T
                                                                 <0011>      ARMv5 (obsolete)
                                                                 <0100>      ARMv5T
                                                                 <0101>      ARMv5TE
                                                                 <0110>      ARMv5TEJ
                                                                 <0111>      ARMv6
                                                                 <1111>      Defined by CPUID scheme */
        uint32_t variant               : 4;  /**< [ 23: 20](RO) Variant field - used by CNXXXX to indicate major pass number. */
        uint32_t implementer           : 8;  /**< [ 31: 24](RO) Implementor field - Cavium - 0x43.
                                                                 The Implementer code. This field must hold an implementer code
                                                                     that has been assigned by ARM. Assigned codes include the
                                                                     following:

                                                                 <pre>
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
                                                                 </pre> */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_midr_el1_s cn; */
} bdk_dbgx_midr_el1_t;

static inline uint64_t BDK_DBGX_MIDR_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_MIDR_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000d00ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_MIDR_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_MIDR_EL1(a) bdk_dbgx_midr_el1_t
#define bustype_BDK_DBGX_MIDR_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_MIDR_EL1(a) "DBGX_MIDR_EL1"
#define busnum_BDK_DBGX_MIDR_EL1(a) (a)
#define arguments_BDK_DBGX_MIDR_EL1(a) (a),-1,-1,-1

/**
 * Register (DAB32b) dbg#_oslar_el1
 *
 * AP DBG OS Lock Access Register
 * Used to lock or unlock the OS lock.
 */
typedef union
{
    uint32_t u;
    struct bdk_dbgx_oslar_el1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t oslk                  : 1;  /**< [  0:  0](WO) On writes to OSLAR_EL1, bit[0] is copied to the OS lock (see OSLSR_EL1).
                                                                 Use EDPRSR.OSLK to check the current status of the lock. */
#else /* Word 0 - Little Endian */
        uint32_t oslk                  : 1;  /**< [  0:  0](WO) On writes to OSLAR_EL1, bit[0] is copied to the OS lock (see OSLSR_EL1).
                                                                 Use EDPRSR.OSLK to check the current status of the lock. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_dbgx_oslar_el1_s cn; */
} bdk_dbgx_oslar_el1_t;

static inline uint64_t BDK_DBGX_OSLAR_EL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DBGX_OSLAR_EL1(unsigned long a)
{
    if (a<=47)
        return 0x87a008000300ll + 0x80000ll * ((a) & 0x3f);
    __bdk_csr_fatal("DBGX_OSLAR_EL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_DBGX_OSLAR_EL1(a) bdk_dbgx_oslar_el1_t
#define bustype_BDK_DBGX_OSLAR_EL1(a) BDK_CSR_TYPE_DAB32b
#define basename_BDK_DBGX_OSLAR_EL1(a) "DBGX_OSLAR_EL1"
#define busnum_BDK_DBGX_OSLAR_EL1(a) (a)
#define arguments_BDK_DBGX_OSLAR_EL1(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_DAB_DBG_H__ */
