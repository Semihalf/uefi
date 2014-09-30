#ifndef __BDK_CSRS_ECAM__
#define __BDK_CSRS_ECAM__
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
 * Cavium ECAM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));



/**
 * Structure ECAM_CFG_ADDR_S
 *
 * ECAM Configuration Address Structure
 * ECAM load and store operations form an address with this structure: 8-bit, 16-bit, 32-bit and
 * 64-bit read and write operations are supported to this region.
 */
union ecam_cfg_addr_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16; /**< [ 63: 48] Reserved */
		uint64_t io                          : 1;  /**< [ 47: 47] Indicates I/O space. */
		uint64_t reserved_46_46              : 1;  /**< [ 46: 46] Reserved. */
		uint64_t node                        : 2;  /**< [ 45: 44] CCPI node number. */
		uint64_t did                         : 8;  /**< [ 43: 36] ECAM(0..3) DID. 0x48 + ECAM number. */
		uint64_t setup                       : 1;  /**< [ 35: 35] Reserved, MBZ. INTERNAL: Reserved for future use - Setup. Allow certain PCC
                                                                 configuration registers to be written for boot-time initialization. Treated as 0
                                                                 unless in secure mode. */
		uint64_t bcst                        : 1;  /**< [ 34: 34] Reserved, MBZ. INTERNAL: Reserved for future use - Broadcast. Write to all PCC
                                                                 blocks for fast configuration. Treated as 0 unless in secure mode and SETUP is
                                                                 set. */
		uint64_t reserved_28_33              : 6;  /**< [ 33: 28] Reserved. */
		uint64_t bus                         : 8;  /**< [ 27: 20] Bus number. */
		uint64_t func                        : 8;  /**< [ 19: 12] Function number. Note this assumes an ARI device; for external PCI devices that do not
                                                                 support ARI this contains both the device and function number. */
		uint64_t addr                        : 12; /**< [ 11:  0] Register address within the device. */
#else
		uint64_t addr                        : 12;
		uint64_t func                        : 8;
		uint64_t bus                         : 8;
		uint64_t reserved_28_33              : 6;
		uint64_t bcst                        : 1;
		uint64_t setup                       : 1;
		uint64_t did                         : 8;
		uint64_t node                        : 2;
		uint64_t reserved_46_46              : 1;
		uint64_t io                          : 1;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
};


/**
 * RSL - ecam#_bus#_nsdis
 */
typedef union bdk_ecamx_busx_nsdis {
	uint64_t u;
	struct bdk_ecamx_busx_nsdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t dis                         : 1;  /**< R/W - Disable ECAM bus in non-secure mode. If set, the indexed ECAM bus number is RAO/WI
                                                                 when accessed via the ECAM space with non-secure transactions. Note this affects only ECAM
                                                                 configuration access, not normal I/O mapped memory accesses to the device. ECAM 0, bus 0
                                                                 (corresponding to RSL devices) is not generally disabled, instead  may be used to disable
                                                                 RSL discovery. */
#else
		uint64_t dis                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_ecamx_busx_nsdis_s      cn85xx; */
	/* struct bdk_ecamx_busx_nsdis_s      cn88xx; */
	/* struct bdk_ecamx_busx_nsdis_s      cn88xxp1; */
} bdk_ecamx_busx_nsdis_t;

static inline uint64_t BDK_ECAMX_BUSX_NSDIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_BUSX_NSDIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 255)))
		return 0x000087E048030000ull + (param1 & 3) * 0x1000000ull + (param2 & 255) * 0x8ull;
	csr_fatal("BDK_ECAMX_BUSX_NSDIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_BUSX_NSDIS(...) bdk_ecamx_busx_nsdis_t
#define bustype_BDK_ECAMX_BUSX_NSDIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_BUSX_NSDIS(p1,p2) (p1)
#define arguments_BDK_ECAMX_BUSX_NSDIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_ECAMX_BUSX_NSDIS(...) "ECAMX_BUSX_NSDIS"


/**
 * RSL - ecam#_bus#_sdis
 */
typedef union bdk_ecamx_busx_sdis {
	uint64_t u;
	struct bdk_ecamx_busx_sdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t sec                         : 1;  /**< SR/W - Secure ECAM bus. If set, the indexed ECAM bus number is secured and RAO/WI when
                                                                 accessed via the ECAM space with non-secure transactions. This bit overrides
                                                                 ECAM()_BUS()_NSDIS[DIS]. */
		uint64_t dis                         : 1;  /**< SR/W - Disable ECAM bus in secure mode. If set, the indexed ECAM bus number is RAO/WI when
                                                                 accessed via the ECAM space with secure transactions. This bit is similar to the non-
                                                                 secure ECAM()_BUS()_NSDIS[DIS]. */
#else
		uint64_t dis                         : 1;
		uint64_t sec                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ecamx_busx_sdis_s       cn85xx; */
	/* struct bdk_ecamx_busx_sdis_s       cn88xx; */
	/* struct bdk_ecamx_busx_sdis_s       cn88xxp1; */
} bdk_ecamx_busx_sdis_t;

static inline uint64_t BDK_ECAMX_BUSX_SDIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_BUSX_SDIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 255)))
		return 0x000087E048020000ull + (param1 & 3) * 0x1000000ull + (param2 & 255) * 0x8ull;
	csr_fatal("BDK_ECAMX_BUSX_SDIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_BUSX_SDIS(...) bdk_ecamx_busx_sdis_t
#define bustype_BDK_ECAMX_BUSX_SDIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_BUSX_SDIS(p1,p2) (p1)
#define arguments_BDK_ECAMX_BUSX_SDIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_ECAMX_BUSX_SDIS(...) "ECAMX_BUSX_SDIS"


/**
 * RSL - ecam#_dev#_nsdis
 */
typedef union bdk_ecamx_devx_nsdis {
	uint64_t u;
	struct bdk_ecamx_devx_nsdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t dis                         : 1;  /**< R/W - Disable ECAM device in non-secure mode. If set, the specified device
                                                                 number on bus 0 are RAO/WI when accessed via the ECAM space with
                                                                 non-secure transactions. Note this affects only ECAM configuration
                                                                 access, not normal I/O mapped memory accesses to the device. */
#else
		uint64_t dis                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_ecamx_devx_nsdis_s      cn85xx; */
	/* struct bdk_ecamx_devx_nsdis_s      cn88xx; */
	/* struct bdk_ecamx_devx_nsdis_s      cn88xxp1; */
} bdk_ecamx_devx_nsdis_t;

static inline uint64_t BDK_ECAMX_DEVX_NSDIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_DEVX_NSDIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 31)))
		return 0x000087E048070000ull + (param1 & 3) * 0x1000000ull + (param2 & 31) * 0x8ull;
	csr_fatal("BDK_ECAMX_DEVX_NSDIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_DEVX_NSDIS(...) bdk_ecamx_devx_nsdis_t
#define bustype_BDK_ECAMX_DEVX_NSDIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_DEVX_NSDIS(p1,p2) (p1)
#define arguments_BDK_ECAMX_DEVX_NSDIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_ECAMX_DEVX_NSDIS(...) "ECAMX_DEVX_NSDIS"


/**
 * RSL - ecam#_dev#_sdis
 */
typedef union bdk_ecamx_devx_sdis {
	uint64_t u;
	struct bdk_ecamx_devx_sdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t sec                         : 1;  /**< SR/W - Secure ECAM device. If set, the indexed device number on bus 0 are
                                                                 secured and RAO/WI when accessed via the ECAM space with non-secure
                                                                 transactions. This bit overrides ECAM()_DEV()_NSDIS[DIS]. */
		uint64_t dis                         : 1;  /**< SR/W - Disable ECAM device in secure mode. If set, ECAM secure
                                                                 read/write operations to the indexed device number on bus 0
                                                                 are RAO/WI when accessed via the ECAM space. This bit is
                                                                 similar to the non-secure ECAM()_DEV()_NSDIS[DIS]. */
#else
		uint64_t dis                         : 1;
		uint64_t sec                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ecamx_devx_sdis_s       cn85xx; */
	/* struct bdk_ecamx_devx_sdis_s       cn88xx; */
	/* struct bdk_ecamx_devx_sdis_s       cn88xxp1; */
} bdk_ecamx_devx_sdis_t;

static inline uint64_t BDK_ECAMX_DEVX_SDIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_DEVX_SDIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 31)))
		return 0x000087E048060000ull + (param1 & 3) * 0x1000000ull + (param2 & 31) * 0x8ull;
	csr_fatal("BDK_ECAMX_DEVX_SDIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_DEVX_SDIS(...) bdk_ecamx_devx_sdis_t
#define bustype_BDK_ECAMX_DEVX_SDIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_DEVX_SDIS(p1,p2) (p1)
#define arguments_BDK_ECAMX_DEVX_SDIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_ECAMX_DEVX_SDIS(...) "ECAMX_DEVX_SDIS"


/**
 * RSL - ecam#_nop_of
 */
typedef union bdk_ecamx_nop_of {
	uint64_t u;
	struct bdk_ecamx_nop_of_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ones                        : 64; /**< RO - Used internally to handle disabled read/write transactions. */
#else
		uint64_t ones                        : 64;
#endif
	} s;
	/* struct bdk_ecamx_nop_of_s          cn85xx; */
	/* struct bdk_ecamx_nop_of_s          cn88xx; */
	/* struct bdk_ecamx_nop_of_s          cn88xxp1; */
} bdk_ecamx_nop_of_t;

static inline uint64_t BDK_ECAMX_NOP_OF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_OF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E048000000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_ECAMX_NOP_OF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_NOP_OF(...) bdk_ecamx_nop_of_t
#define bustype_BDK_ECAMX_NOP_OF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_NOP_OF(p1) (p1)
#define arguments_BDK_ECAMX_NOP_OF(p1) (p1),-1,-1,-1
#define basename_BDK_ECAMX_NOP_OF(...) "ECAMX_NOP_OF"


/**
 * RSL - ecam#_nop_onf
 */
typedef union bdk_ecamx_nop_onf {
	uint64_t u;
	struct bdk_ecamx_nop_onf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ones                        : 64; /**< RO - Used internally to handle disabled read/write transactions. */
#else
		uint64_t ones                        : 64;
#endif
	} s;
	/* struct bdk_ecamx_nop_onf_s         cn85xx; */
	/* struct bdk_ecamx_nop_onf_s         cn88xx; */
	/* struct bdk_ecamx_nop_onf_s         cn88xxp1; */
} bdk_ecamx_nop_onf_t;

static inline uint64_t BDK_ECAMX_NOP_ONF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_ONF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E048000080ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_ECAMX_NOP_ONF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_NOP_ONF(...) bdk_ecamx_nop_onf_t
#define bustype_BDK_ECAMX_NOP_ONF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_NOP_ONF(p1) (p1)
#define arguments_BDK_ECAMX_NOP_ONF(p1) (p1),-1,-1,-1
#define basename_BDK_ECAMX_NOP_ONF(...) "ECAMX_NOP_ONF"


/**
 * RSL - ecam#_nop_zf
 */
typedef union bdk_ecamx_nop_zf {
	uint64_t u;
	struct bdk_ecamx_nop_zf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t zeros                       : 64; /**< RO - Used internally to handle disabled read/write transactions. */
#else
		uint64_t zeros                       : 64;
#endif
	} s;
	/* struct bdk_ecamx_nop_zf_s          cn85xx; */
	/* struct bdk_ecamx_nop_zf_s          cn88xx; */
	/* struct bdk_ecamx_nop_zf_s          cn88xxp1; */
} bdk_ecamx_nop_zf_t;

static inline uint64_t BDK_ECAMX_NOP_ZF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_ZF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E048000100ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_ECAMX_NOP_ZF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_NOP_ZF(...) bdk_ecamx_nop_zf_t
#define bustype_BDK_ECAMX_NOP_ZF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_NOP_ZF(p1) (p1)
#define arguments_BDK_ECAMX_NOP_ZF(p1) (p1),-1,-1,-1
#define basename_BDK_ECAMX_NOP_ZF(...) "ECAMX_NOP_ZF"


/**
 * RSL - ecam#_nop_znf
 */
typedef union bdk_ecamx_nop_znf {
	uint64_t u;
	struct bdk_ecamx_nop_znf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t zeros                       : 64; /**< RO - Used internally to handle disabled read/write transactions. */
#else
		uint64_t zeros                       : 64;
#endif
	} s;
	/* struct bdk_ecamx_nop_znf_s         cn85xx; */
	/* struct bdk_ecamx_nop_znf_s         cn88xx; */
	/* struct bdk_ecamx_nop_znf_s         cn88xxp1; */
} bdk_ecamx_nop_znf_t;

static inline uint64_t BDK_ECAMX_NOP_ZNF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_NOP_ZNF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E048000180ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_ECAMX_NOP_ZNF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_NOP_ZNF(...) bdk_ecamx_nop_znf_t
#define bustype_BDK_ECAMX_NOP_ZNF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_NOP_ZNF(p1) (p1)
#define arguments_BDK_ECAMX_NOP_ZNF(p1) (p1),-1,-1,-1
#define basename_BDK_ECAMX_NOP_ZNF(...) "ECAMX_NOP_ZNF"


/**
 * RSL - ecam#_rsl#_nsdis
 *
 * This register is only implemented for ECAM0 which sources RSL.
 *
 */
typedef union bdk_ecamx_rslx_nsdis {
	uint64_t u;
	struct bdk_ecamx_rslx_nsdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t dis                         : 1;  /**< R/W - Disable ECAM RSL function in non-secure mode. If set, the specified RSL function number
                                                                 (under ECAM 0 bus 1) is RAO/WI when accessed via the ECAM space with non-secure
                                                                 transactions. Note this affects only ECAM configuration access, not normal I/O mapped
                                                                 memory accesses to the device. */
#else
		uint64_t dis                         : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_ecamx_rslx_nsdis_s      cn85xx; */
	/* struct bdk_ecamx_rslx_nsdis_s      cn88xx; */
	/* struct bdk_ecamx_rslx_nsdis_s      cn88xxp1; */
} bdk_ecamx_rslx_nsdis_t;

static inline uint64_t BDK_ECAMX_RSLX_NSDIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_RSLX_NSDIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 255)))
		return 0x000087E048050000ull + (param1 & 3) * 0x1000000ull + (param2 & 255) * 0x8ull;
	csr_fatal("BDK_ECAMX_RSLX_NSDIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_RSLX_NSDIS(...) bdk_ecamx_rslx_nsdis_t
#define bustype_BDK_ECAMX_RSLX_NSDIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_RSLX_NSDIS(p1,p2) (p1)
#define arguments_BDK_ECAMX_RSLX_NSDIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_ECAMX_RSLX_NSDIS(...) "ECAMX_RSLX_NSDIS"


/**
 * RSL - ecam#_rsl#_sdis
 *
 * This register is only implemented for ECAM0 which sources RSL.
 *
 */
typedef union bdk_ecamx_rslx_sdis {
	uint64_t u;
	struct bdk_ecamx_rslx_sdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t sec                         : 1;  /**< SR/W - Secure ECAM RSL function. If set, the indexed RSL function number (under ECAM 0
                                                                 bus 1) is secured and RAO/WI when accessed via the ECAM space with non-secure
                                                                 transactions. This bit overrides ECAM()_RSL()_NSDIS[DIS]. */
		uint64_t dis                         : 1;  /**< SR/W - Disable ECAM RSL function in secure mode. If set, ECAM secure read/write operations to the
                                                                 indexed
                                                                 RSL function number (under ECAM 0 bus 1) are RAO/WI when accessed via the ECAM
                                                                 space. This bit is similar to the non-secure ECAM()_RSL()_NSDIS[DIS]. */
#else
		uint64_t dis                         : 1;
		uint64_t sec                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ecamx_rslx_sdis_s       cn85xx; */
	/* struct bdk_ecamx_rslx_sdis_s       cn88xx; */
	/* struct bdk_ecamx_rslx_sdis_s       cn88xxp1; */
} bdk_ecamx_rslx_sdis_t;

static inline uint64_t BDK_ECAMX_RSLX_SDIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_ECAMX_RSLX_SDIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 255)))
		return 0x000087E048040000ull + (param1 & 3) * 0x1000000ull + (param2 & 255) * 0x8ull;
	csr_fatal("BDK_ECAMX_RSLX_SDIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_ECAMX_RSLX_SDIS(...) bdk_ecamx_rslx_sdis_t
#define bustype_BDK_ECAMX_RSLX_SDIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_ECAMX_RSLX_SDIS(p1,p2) (p1)
#define arguments_BDK_ECAMX_RSLX_SDIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_ECAMX_RSLX_SDIS(...) "ECAMX_RSLX_SDIS"

#endif /* __BDK_CSRS_ECAM__ */
