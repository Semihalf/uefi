#ifndef __BDK_CSRS_L2C_MCI__
#define __BDK_CSRS_L2C_MCI__
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
 * Cavium L2C_MCI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration L2C_MCI_INT_VEC_E
 *
 * L2C_MCI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum l2c_mci_int_vec_e {
	L2C_MCI_INT_VEC_E_INTS = 0x0,
	L2C_MCI_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - l2c_mci#_bist_status
 *
 * If clear BIST is desired, CLEAR_BIST must be written to 1 before START_BIST is written to 1
 * using a separate CSR write operation.
 * CLEAR_BIST must not be changed after writing START_BIST to 1 until the BIST operation
 * completes (indicated by START_BIST returning to 0) or operation is undefined.
 */
typedef union bdk_l2c_mcix_bist_status {
	uint64_t u;
	struct bdk_l2c_mcix_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t start_bist                  : 1;  /**< R/W/H - When written to 1, starts BIST. Remains 1 until BIST is complete. */
		uint64_t clear_bist                  : 1;  /**< R/W - When BIST is triggered, run clear BIST. */
		uint64_t reserved_2_61               : 60;
		uint64_t vbffl                       : 2;  /**< RO/H - BIST failure status for VBF0-1. */
#else
		uint64_t vbffl                       : 2;
		uint64_t reserved_2_61               : 60;
		uint64_t clear_bist                  : 1;
		uint64_t start_bist                  : 1;
#endif
	} s;
	/* struct bdk_l2c_mcix_bist_status_s  cn85xx; */
	/* struct bdk_l2c_mcix_bist_status_s  cn88xx; */
} bdk_l2c_mcix_bist_status_t;

static inline uint64_t BDK_L2C_MCIX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C020000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_BIST_STATUS(...) bdk_l2c_mcix_bist_status_t
#define bustype_BDK_L2C_MCIX_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_BIST_STATUS(p1) (p1)
#define arguments_BDK_L2C_MCIX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_BIST_STATUS(...) "L2C_MCIX_BIST_STATUS"


/**
 * RSL - l2c_mci#_err
 *
 * This register records error information for all MCI errors.
 * An error locks the VBF4, INDEX, and SYN0/1 fields and set the bit corresponding to the error
 * received. VBFDBE errors take priority and will overwrite an earlier logged VBFSBE error. The
 * information from exactly one VBF read is present at any given time and serves to document
 * which error(s) were present in the read with the highest priority error.
 * The syndrome is recorded for DBE errors.
 */
typedef union bdk_l2c_mcix_err {
	uint64_t u;
	struct bdk_l2c_mcix_err_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t vbfdbe1                     : 1;  /**< RO/H - INDEX/SYN1 corresponds to a double-bit VBF ECC error. */
		uint64_t vbfdbe0                     : 1;  /**< RO/H - INDEX/SYN0 corresponds to a double-bit VBF ECC error. */
		uint64_t vbfsbe1                     : 1;  /**< RO/H - INDEX/SYN1 corresponds to a single-bit VBF ECC error. */
		uint64_t vbfsbe0                     : 1;  /**< RO/H - INDEX/SYN0 corresponds to a single-bit VBF ECC error. */
		uint64_t reserved_48_59              : 12;
		uint64_t syn1                        : 8;  /**< RO/H - Error syndrome for QW1 ([127:64]). */
		uint64_t syn0                        : 8;  /**< RO/H - Error syndrome for QW0 ([63:0]). */
		uint64_t reserved_12_31              : 20;
		uint64_t vbf4                        : 1;  /**< RO/H - When 1, errors were from VBF (4+a), when 0, from VBF (0+a). */
		uint64_t index                       : 7;  /**< RO/H - VBF index which was read and had the error(s). */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t index                       : 7;
		uint64_t vbf4                        : 1;
		uint64_t reserved_12_31              : 20;
		uint64_t syn0                        : 8;
		uint64_t syn1                        : 8;
		uint64_t reserved_48_59              : 12;
		uint64_t vbfsbe0                     : 1;
		uint64_t vbfsbe1                     : 1;
		uint64_t vbfdbe0                     : 1;
		uint64_t vbfdbe1                     : 1;
#endif
	} s;
	/* struct bdk_l2c_mcix_err_s          cn85xx; */
	/* struct bdk_l2c_mcix_err_s          cn88xx; */
} bdk_l2c_mcix_err_t;

static inline uint64_t BDK_L2C_MCIX_ERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_ERR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C010000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_ERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_ERR(...) bdk_l2c_mcix_err_t
#define bustype_BDK_L2C_MCIX_ERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_ERR(p1) (p1)
#define arguments_BDK_L2C_MCIX_ERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_ERR(...) "L2C_MCIX_ERR"


/**
 * RSL - l2c_mci#_int_ena_w1c
 */
typedef union bdk_l2c_mcix_int_ena_w1c {
	uint64_t u;
	struct bdk_l2c_mcix_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t vbfdbe                      : 1;  /**< R/W1C/H - VBF double-bit error occurred. See L2C_MCI()_ERR for logged information. */
		uint64_t vbfsbe                      : 1;  /**< R/W1C/H - VBF single-bit error occurred. See L2C_MCI()_ERR for logged information. */
#else
		uint64_t vbfsbe                      : 1;
		uint64_t vbfdbe                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_l2c_mcix_int_ena_w1c_s  cn85xx; */
	/* struct bdk_l2c_mcix_int_ena_w1c_s  cn88xx; */
} bdk_l2c_mcix_int_ena_w1c_t;

static inline uint64_t BDK_L2C_MCIX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C000020ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_INT_ENA_W1C(...) bdk_l2c_mcix_int_ena_w1c_t
#define bustype_BDK_L2C_MCIX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_L2C_MCIX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_INT_ENA_W1C(...) "L2C_MCIX_INT_ENA_W1C"


/**
 * RSL - l2c_mci#_int_ena_w1s
 */
typedef union bdk_l2c_mcix_int_ena_w1s {
	uint64_t u;
	struct bdk_l2c_mcix_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t vbfdbe                      : 1;  /**< R/W1C/H - VBF double-bit error occurred. See L2C_MCI()_ERR for logged information. */
		uint64_t vbfsbe                      : 1;  /**< R/W1C/H - VBF single-bit error occurred. See L2C_MCI()_ERR for logged information. */
#else
		uint64_t vbfsbe                      : 1;
		uint64_t vbfdbe                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_l2c_mcix_int_ena_w1s_s  cn85xx; */
	/* struct bdk_l2c_mcix_int_ena_w1s_s  cn88xx; */
} bdk_l2c_mcix_int_ena_w1s_t;

static inline uint64_t BDK_L2C_MCIX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C000028ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_INT_ENA_W1S(...) bdk_l2c_mcix_int_ena_w1s_t
#define bustype_BDK_L2C_MCIX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_L2C_MCIX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_INT_ENA_W1S(...) "L2C_MCIX_INT_ENA_W1S"


/**
 * RSL - l2c_mci#_int_w1c
 *
 * This register is for MCI-based interrupts.
 *
 */
typedef union bdk_l2c_mcix_int_w1c {
	uint64_t u;
	struct bdk_l2c_mcix_int_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t vbfdbe                      : 1;  /**< R/W1C/H - VBF double-bit error occurred. See L2C_MCI()_ERR for logged information. */
		uint64_t vbfsbe                      : 1;  /**< R/W1C/H - VBF single-bit error occurred. See L2C_MCI()_ERR for logged information. */
#else
		uint64_t vbfsbe                      : 1;
		uint64_t vbfdbe                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_l2c_mcix_int_w1c_s      cn85xx; */
	/* struct bdk_l2c_mcix_int_w1c_s      cn88xx; */
} bdk_l2c_mcix_int_w1c_t;

static inline uint64_t BDK_L2C_MCIX_INT_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_INT_W1C(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C000000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_INT_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_INT_W1C(...) bdk_l2c_mcix_int_w1c_t
#define bustype_BDK_L2C_MCIX_INT_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_INT_W1C(p1) (p1)
#define arguments_BDK_L2C_MCIX_INT_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_INT_W1C(...) "L2C_MCIX_INT_W1C"


/**
 * RSL - l2c_mci#_int_w1s
 */
typedef union bdk_l2c_mcix_int_w1s {
	uint64_t u;
	struct bdk_l2c_mcix_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t vbfdbe                      : 1;  /**< R/W1C/H - VBF double-bit error occurred. See L2C_MCI()_ERR for logged information. */
		uint64_t vbfsbe                      : 1;  /**< R/W1C/H - VBF single-bit error occurred. See L2C_MCI()_ERR for logged information. */
#else
		uint64_t vbfsbe                      : 1;
		uint64_t vbfdbe                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_l2c_mcix_int_w1s_s      cn85xx; */
	/* struct bdk_l2c_mcix_int_w1s_s      cn88xx; */
} bdk_l2c_mcix_int_w1s_t;

static inline uint64_t BDK_L2C_MCIX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C000008ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_INT_W1S(...) bdk_l2c_mcix_int_w1s_t
#define bustype_BDK_L2C_MCIX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_INT_W1S(p1) (p1)
#define arguments_BDK_L2C_MCIX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_INT_W1S(...) "L2C_MCIX_INT_W1S"


/**
 * RSL - l2c_mci#_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the L2C_MCI_INT_VEC_E
 * enumeration.
 */
typedef union bdk_l2c_mcix_msix_pbax {
	uint64_t u;
	struct bdk_l2c_mcix_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO - Pending message for the associated L2C_MCI()_MSIX_VEC()_CTL, enumerated by
                                                                 L2C_MCI_INT_VEC_E. Bits that have no associated L2C_MCI_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_l2c_mcix_msix_pbax_s    cn85xx; */
	/* struct bdk_l2c_mcix_msix_pbax_s    cn88xx; */
} bdk_l2c_mcix_msix_pbax_t;

static inline uint64_t BDK_L2C_MCIX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E05CFF0000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_MSIX_PBAX(...) bdk_l2c_mcix_msix_pbax_t
#define bustype_BDK_L2C_MCIX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_L2C_MCIX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_MCIX_MSIX_PBAX(...) "L2C_MCIX_MSIX_PBAX"


/**
 * RSL - l2c_mci#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the L2C_MCI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_l2c_mcix_msix_vecx_addr {
	uint64_t u;
	struct bdk_l2c_mcix_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's L2C_MCI()_MSIX_VEC()_ADDR, L2C_MCI()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of L2C_MCI()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_L2C_MCI_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_l2c_mcix_msix_vecx_addr_s cn85xx; */
	/* struct bdk_l2c_mcix_msix_vecx_addr_s cn88xx; */
} bdk_l2c_mcix_msix_vecx_addr_t;

static inline uint64_t BDK_L2C_MCIX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E05CF00000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_MSIX_VECX_ADDR(...) bdk_l2c_mcix_msix_vecx_addr_t
#define bustype_BDK_L2C_MCIX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_L2C_MCIX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_MCIX_MSIX_VECX_ADDR(...) "L2C_MCIX_MSIX_VECX_ADDR"


/**
 * RSL - l2c_mci#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the L2C_MCI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_l2c_mcix_msix_vecx_ctl {
	uint64_t u;
	struct bdk_l2c_mcix_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< R/W - When set, no MSI-X interrupts are sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< R/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_l2c_mcix_msix_vecx_ctl_s cn85xx; */
	/* struct bdk_l2c_mcix_msix_vecx_ctl_s cn88xx; */
} bdk_l2c_mcix_msix_vecx_ctl_t;

static inline uint64_t BDK_L2C_MCIX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E05CF00008ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_MSIX_VECX_CTL(...) bdk_l2c_mcix_msix_vecx_ctl_t
#define bustype_BDK_L2C_MCIX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_L2C_MCIX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_MCIX_MSIX_VECX_CTL(...) "L2C_MCIX_MSIX_VECX_CTL"


/**
 * RSL - l2c_mci#_scratch
 *
 * These registers are only reset by hardware during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_l2c_mcix_scratch {
	uint64_t u;
	struct bdk_l2c_mcix_scratch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t scratch                     : 8;  /**< R/W - General purpose scratch register. */
#else
		uint64_t scratch                     : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_l2c_mcix_scratch_s      cn85xx; */
	/* struct bdk_l2c_mcix_scratch_s      cn88xx; */
} bdk_l2c_mcix_scratch_t;

static inline uint64_t BDK_L2C_MCIX_SCRATCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_MCIX_SCRATCH(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E05C030000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_MCIX_SCRATCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_MCIX_SCRATCH(...) bdk_l2c_mcix_scratch_t
#define bustype_BDK_L2C_MCIX_SCRATCH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_MCIX_SCRATCH(p1) (p1)
#define arguments_BDK_L2C_MCIX_SCRATCH(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_MCIX_SCRATCH(...) "L2C_MCIX_SCRATCH"

#endif /* __BDK_CSRS_L2C_MCI__ */
