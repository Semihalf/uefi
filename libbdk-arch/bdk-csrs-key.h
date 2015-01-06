#ifndef __BDK_CSRS_KEY__
#define __BDK_CSRS_KEY__
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
 * Cavium KEY.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration KEY_INT_VEC_E
 *
 * KEY MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum key_int_vec_e {
	KEY_INT_VEC_E_INTS = 0x0,
	KEY_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - key_bist_reg
 *
 * This register provides the BIST status for KEY memory (0 = pass, 1 = fail).
 *
 */
typedef union bdk_key_bist_reg {
	uint64_t u;
	struct bdk_key_bist_reg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t rrc                         : 1;  /**< SRO/H - RRC BIST status. */
		uint64_t kmem                        : 1;  /**< SRO/H - KMEM BIST status. */
#else
		uint64_t kmem                        : 1;
		uint64_t rrc                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_key_bist_reg_s          cn88xx; */
	/* struct bdk_key_bist_reg_s          cn88xxp1; */
} bdk_key_bist_reg_t;

#define BDK_KEY_BIST_REG BDK_KEY_BIST_REG_FUNC()
static inline uint64_t BDK_KEY_BIST_REG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_BIST_REG_FUNC(void)
{
	return 0x000087E041000018ull;
}
#define typedef_BDK_KEY_BIST_REG bdk_key_bist_reg_t
#define bustype_BDK_KEY_BIST_REG BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_BIST_REG 0
#define arguments_BDK_KEY_BIST_REG -1,-1,-1,-1
#define basename_BDK_KEY_BIST_REG "KEY_BIST_REG"


/**
 * RSL - key_ctl_status
 *
 * This register provides control and status information for KEY memory.
 *
 */
typedef union bdk_key_ctl_status {
	uint64_t u;
	struct bdk_key_ctl_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t kmem_dcor                   : 1;  /**< SR/W - Disable ECC correction in KEY MEM. */
		uint64_t kmem_fs                     : 2;  /**< SR/W - Flip syndrome bits. On the next write operation, flip the syndrome bits written into KEY MEM. */
#else
		uint64_t kmem_fs                     : 2;
		uint64_t kmem_dcor                   : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_key_ctl_status_s        cn88xx; */
	/* struct bdk_key_ctl_status_s        cn88xxp1; */
} bdk_key_ctl_status_t;

#define BDK_KEY_CTL_STATUS BDK_KEY_CTL_STATUS_FUNC()
static inline uint64_t BDK_KEY_CTL_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_CTL_STATUS_FUNC(void)
{
	return 0x000087E041000010ull;
}
#define typedef_BDK_KEY_CTL_STATUS bdk_key_ctl_status_t
#define bustype_BDK_KEY_CTL_STATUS BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_CTL_STATUS 0
#define arguments_BDK_KEY_CTL_STATUS -1,-1,-1,-1
#define basename_BDK_KEY_CTL_STATUS "KEY_CTL_STATUS"


/**
 * RSL - key_int_ena_w1c
 */
typedef union bdk_key_int_ena_w1c {
	uint64_t u;
	struct bdk_key_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ked0_dbe                    : 1;  /**< SR/W1C/H - KED0 double-bit error. When set, a KED0 double-bit error has occurred. */
		uint64_t ked0_sbe                    : 1;  /**< SR/W1C/H - KED0 single-bit error. When set, a KED0 single-bit error has occurred. */
#else
		uint64_t ked0_sbe                    : 1;
		uint64_t ked0_dbe                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_key_int_ena_w1c_s       cn88xx; */
	/* struct bdk_key_int_ena_w1c_s       cn88xxp1; */
} bdk_key_int_ena_w1c_t;

#define BDK_KEY_INT_ENA_W1C BDK_KEY_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_KEY_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_INT_ENA_W1C_FUNC(void)
{
	return 0x000087E041000120ull;
}
#define typedef_BDK_KEY_INT_ENA_W1C bdk_key_int_ena_w1c_t
#define bustype_BDK_KEY_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_INT_ENA_W1C 0
#define arguments_BDK_KEY_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_KEY_INT_ENA_W1C "KEY_INT_ENA_W1C"


/**
 * RSL - key_int_ena_w1s
 */
typedef union bdk_key_int_ena_w1s {
	uint64_t u;
	struct bdk_key_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ked0_dbe                    : 1;  /**< SR/W1C/H - KED0 double-bit error. When set, a KED0 double-bit error has occurred. */
		uint64_t ked0_sbe                    : 1;  /**< SR/W1C/H - KED0 single-bit error. When set, a KED0 single-bit error has occurred. */
#else
		uint64_t ked0_sbe                    : 1;
		uint64_t ked0_dbe                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_key_int_ena_w1s_s       cn88xx; */
	/* struct bdk_key_int_ena_w1s_s       cn88xxp1; */
} bdk_key_int_ena_w1s_t;

#define BDK_KEY_INT_ENA_W1S BDK_KEY_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_KEY_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_INT_ENA_W1S_FUNC(void)
{
	return 0x000087E041000128ull;
}
#define typedef_BDK_KEY_INT_ENA_W1S bdk_key_int_ena_w1s_t
#define bustype_BDK_KEY_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_INT_ENA_W1S 0
#define arguments_BDK_KEY_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_KEY_INT_ENA_W1S "KEY_INT_ENA_W1S"


/**
 * RSL - key_int_sum
 *
 * This register contains the different interrupt-summary bits of the KEY.
 *
 */
typedef union bdk_key_int_sum {
	uint64_t u;
	struct bdk_key_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ked0_dbe                    : 1;  /**< SR/W1C/H - KED0 double-bit error. When set, a KED0 double-bit error has occurred. */
		uint64_t ked0_sbe                    : 1;  /**< SR/W1C/H - KED0 single-bit error. When set, a KED0 single-bit error has occurred. */
#else
		uint64_t ked0_sbe                    : 1;
		uint64_t ked0_dbe                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_key_int_sum_s           cn88xx; */
	/* struct bdk_key_int_sum_s           cn88xxp1; */
} bdk_key_int_sum_t;

#define BDK_KEY_INT_SUM BDK_KEY_INT_SUM_FUNC()
static inline uint64_t BDK_KEY_INT_SUM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_INT_SUM_FUNC(void)
{
	return 0x000087E041000100ull;
}
#define typedef_BDK_KEY_INT_SUM bdk_key_int_sum_t
#define bustype_BDK_KEY_INT_SUM BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_INT_SUM 0
#define arguments_BDK_KEY_INT_SUM -1,-1,-1,-1
#define basename_BDK_KEY_INT_SUM "KEY_INT_SUM"


/**
 * RSL - key_int_sum_w1s
 */
typedef union bdk_key_int_sum_w1s {
	uint64_t u;
	struct bdk_key_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ked0_dbe                    : 1;  /**< SR/W1C/H - KED0 double-bit error. When set, a KED0 double-bit error has occurred. */
		uint64_t ked0_sbe                    : 1;  /**< SR/W1C/H - KED0 single-bit error. When set, a KED0 single-bit error has occurred. */
#else
		uint64_t ked0_sbe                    : 1;
		uint64_t ked0_dbe                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_key_int_sum_w1s_s       cn88xx; */
	/* struct bdk_key_int_sum_w1s_s       cn88xxp1; */
} bdk_key_int_sum_w1s_t;

#define BDK_KEY_INT_SUM_W1S BDK_KEY_INT_SUM_W1S_FUNC()
static inline uint64_t BDK_KEY_INT_SUM_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_INT_SUM_W1S_FUNC(void)
{
	return 0x000087E041000108ull;
}
#define typedef_BDK_KEY_INT_SUM_W1S bdk_key_int_sum_w1s_t
#define bustype_BDK_KEY_INT_SUM_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_INT_SUM_W1S 0
#define arguments_BDK_KEY_INT_SUM_W1S -1,-1,-1,-1
#define basename_BDK_KEY_INT_SUM_W1S "KEY_INT_SUM_W1S"


/**
 * NCB - key_mem#
 */
typedef union bdk_key_memx {
	uint64_t u;
	struct bdk_key_memx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t kmem                        : 64; /**< SR/W - Key memory. KMEM is accessible using 8-, 16-, 32-, 64-, or 128-bit load or store
                                                                 operations.
                                                                 INTERNAL: Note this is 16 KB in pass 1. It may be increased in pass 2. */
#else
		uint64_t kmem                        : 64;
#endif
	} s;
	/* struct bdk_key_memx_s              cn88xx; */
	/* struct bdk_key_memx_s              cn88xxp1; */
} bdk_key_memx_t;

static inline uint64_t BDK_KEY_MEMX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_MEMX(unsigned long param1)
{
	if (((param1 <= 2047)))
		return 0x0000841000400000ull + (param1 & 2047) * 0x8ull;
	csr_fatal("BDK_KEY_MEMX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_KEY_MEMX(...) bdk_key_memx_t
#define bustype_BDK_KEY_MEMX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_KEY_MEMX(p1) (p1)
#define arguments_BDK_KEY_MEMX(p1) (p1),-1,-1,-1
#define basename_BDK_KEY_MEMX(...) "KEY_MEMX"


/**
 * RSL - key_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the KEY_INT_VEC_E enumeration.
 *
 */
typedef union bdk_key_msix_pbax {
	uint64_t u;
	struct bdk_key_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< SRO/H - Pending message for the associated KEY_MSIX_VEC()_CTL, enumerated by KEY_INT_VEC_E. Bits
                                                                 that have no associated KEY_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_key_msix_pbax_s         cn88xx; */
	/* struct bdk_key_msix_pbax_s         cn88xxp1; */
} bdk_key_msix_pbax_t;

static inline uint64_t BDK_KEY_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E041FF0000ull;
	csr_fatal("BDK_KEY_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_KEY_MSIX_PBAX(...) bdk_key_msix_pbax_t
#define bustype_BDK_KEY_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_MSIX_PBAX(p1) (p1)
#define arguments_BDK_KEY_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_KEY_MSIX_PBAX(...) "KEY_MSIX_PBAX"


/**
 * RSL - key_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the KEY_INT_VEC_E enumeration.
 *
 */
typedef union bdk_key_msix_vecx_addr {
	uint64_t u;
	struct bdk_key_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< SR/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's KEY_MSIX_VEC()_ADDR, KEY_MSIX_VEC()_CTL, and corresponding
                                                                 bit of KEY_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_KEY_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_key_msix_vecx_addr_s    cn88xx; */
	/* struct bdk_key_msix_vecx_addr_s    cn88xxp1; */
} bdk_key_msix_vecx_addr_t;

static inline uint64_t BDK_KEY_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E041F00000ull;
	csr_fatal("BDK_KEY_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_KEY_MSIX_VECX_ADDR(...) bdk_key_msix_vecx_addr_t
#define bustype_BDK_KEY_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_KEY_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_KEY_MSIX_VECX_ADDR(...) "KEY_MSIX_VECX_ADDR"


/**
 * RSL - key_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the KEY_INT_VEC_E enumeration.
 *
 */
typedef union bdk_key_msix_vecx_ctl {
	uint64_t u;
	struct bdk_key_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< SR/W - When set, no MSI-X interrupts are sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< SR/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_key_msix_vecx_ctl_s     cn88xx; */
	/* struct bdk_key_msix_vecx_ctl_s     cn88xxp1; */
} bdk_key_msix_vecx_ctl_t;

static inline uint64_t BDK_KEY_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_KEY_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E041F00008ull;
	csr_fatal("BDK_KEY_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_KEY_MSIX_VECX_CTL(...) bdk_key_msix_vecx_ctl_t
#define bustype_BDK_KEY_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_KEY_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_KEY_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_KEY_MSIX_VECX_CTL(...) "KEY_MSIX_VECX_CTL"

#endif /* __BDK_CSRS_KEY__ */
