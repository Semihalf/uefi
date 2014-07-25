#ifndef __BDK_CSRS_MRML__
#define __BDK_CSRS_MRML__
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
 * Cavium MRML.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar MRML_BAR_E
 *
 * MRML Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace MRML_BAR_E {
	const uint64_t MRML_PF_BAR0 = 0x87e0fc000000;
	const uint64_t MRML_PF_BAR0_PCC_BAR_SIZE_BITS = 20;
	const uint64_t MRML_PF_BAR4 = 0x87e0fcf00000;
	const uint64_t MRML_PF_BAR4_PCC_BAR_SIZE_BITS = 20;
};
#endif

/**
 * Enumeration MRML_INT_VEC_E
 *
 * MRML MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum mrml_int_vec_e {
	MRML_INT_VEC_E_INTS = 0x0,
	MRML_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - mrml_int_ena_w1c
 */
typedef union bdk_mrml_int_ena_w1c {
	uint64_t u;
	struct bdk_mrml_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t local_toe                   : 1;  /**< SR/W1C/H - Local timeout error. When set, a local timeout error has occurred. */
		uint64_t ocx_toe                     : 1;  /**< SR/W1C/H - OCX timeout error. When set, an OCX timeout error has occurred. */
#else
		uint64_t ocx_toe                     : 1;
		uint64_t local_toe                   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mrml_int_ena_w1c_s      cn85xx; */
	/* struct bdk_mrml_int_ena_w1c_s      cn88xx; */
} bdk_mrml_int_ena_w1c_t;

#define BDK_MRML_INT_ENA_W1C BDK_MRML_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_MRML_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_INT_ENA_W1C_FUNC(void)
{
	return 0x000087E0FC000880ull;
}
#define typedef_BDK_MRML_INT_ENA_W1C bdk_mrml_int_ena_w1c_t
#define bustype_BDK_MRML_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_INT_ENA_W1C 0
#define arguments_BDK_MRML_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_MRML_INT_ENA_W1C "MRML_INT_ENA_W1C"


/**
 * RSL - mrml_int_ena_w1s
 */
typedef union bdk_mrml_int_ena_w1s {
	uint64_t u;
	struct bdk_mrml_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t local_toe                   : 1;  /**< SR/W1C/H - Local timeout error. When set, a local timeout error has occurred. */
		uint64_t ocx_toe                     : 1;  /**< SR/W1C/H - OCX timeout error. When set, an OCX timeout error has occurred. */
#else
		uint64_t ocx_toe                     : 1;
		uint64_t local_toe                   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mrml_int_ena_w1s_s      cn85xx; */
	/* struct bdk_mrml_int_ena_w1s_s      cn88xx; */
} bdk_mrml_int_ena_w1s_t;

#define BDK_MRML_INT_ENA_W1S BDK_MRML_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_MRML_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_INT_ENA_W1S_FUNC(void)
{
	return 0x000087E0FC001000ull;
}
#define typedef_BDK_MRML_INT_ENA_W1S bdk_mrml_int_ena_w1s_t
#define bustype_BDK_MRML_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_INT_ENA_W1S 0
#define arguments_BDK_MRML_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_MRML_INT_ENA_W1S "MRML_INT_ENA_W1S"


/**
 * RSL32b - mrml_int_local_to
 *
 * Configures local-node timeouts.
 *
 */
typedef union bdk_mrml_int_local_to {
	uint32_t u;
	struct bdk_mrml_int_local_to_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tovalue                     : 32; /**< SR/W - Local timeout value, in coprocessor-clocks. */
#else
		uint32_t tovalue                     : 32;
#endif
	} s;
	/* struct bdk_mrml_int_local_to_s     cn85xx; */
	/* struct bdk_mrml_int_local_to_s     cn88xx; */
} bdk_mrml_int_local_to_t;

#define BDK_MRML_INT_LOCAL_TO BDK_MRML_INT_LOCAL_TO_FUNC()
static inline uint64_t BDK_MRML_INT_LOCAL_TO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_INT_LOCAL_TO_FUNC(void)
{
	return 0x000087E0FC000800ull;
}
#define typedef_BDK_MRML_INT_LOCAL_TO bdk_mrml_int_local_to_t
#define bustype_BDK_MRML_INT_LOCAL_TO BDK_CSR_TYPE_RSL32b
#define busnum_BDK_MRML_INT_LOCAL_TO 0
#define arguments_BDK_MRML_INT_LOCAL_TO -1,-1,-1,-1
#define basename_BDK_MRML_INT_LOCAL_TO "MRML_INT_LOCAL_TO"


/**
 * RSL32b - mrml_int_ocx_to
 *
 * Configures remote-node timeouts.
 *
 */
typedef union bdk_mrml_int_ocx_to {
	uint32_t u;
	struct bdk_mrml_int_ocx_to_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tovalue                     : 32; /**< SR/W - OCX timeout value, in coprocessor-clocks. */
#else
		uint32_t tovalue                     : 32;
#endif
	} s;
	/* struct bdk_mrml_int_ocx_to_s       cn85xx; */
	/* struct bdk_mrml_int_ocx_to_s       cn88xx; */
} bdk_mrml_int_ocx_to_t;

#define BDK_MRML_INT_OCX_TO BDK_MRML_INT_OCX_TO_FUNC()
static inline uint64_t BDK_MRML_INT_OCX_TO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_INT_OCX_TO_FUNC(void)
{
	return 0x000087E0FC000808ull;
}
#define typedef_BDK_MRML_INT_OCX_TO bdk_mrml_int_ocx_to_t
#define bustype_BDK_MRML_INT_OCX_TO BDK_CSR_TYPE_RSL32b
#define busnum_BDK_MRML_INT_OCX_TO 0
#define arguments_BDK_MRML_INT_OCX_TO -1,-1,-1,-1
#define basename_BDK_MRML_INT_OCX_TO "MRML_INT_OCX_TO"


/**
 * RSL - mrml_int_sum
 *
 * This register contains the different interrupt-summary bits of the MRML.
 *
 */
typedef union bdk_mrml_int_sum {
	uint64_t u;
	struct bdk_mrml_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t local_toe                   : 1;  /**< SR/W1C/H - Local timeout error. When set, a local timeout error has occurred. */
		uint64_t ocx_toe                     : 1;  /**< SR/W1C/H - OCX timeout error. When set, an OCX timeout error has occurred. */
#else
		uint64_t ocx_toe                     : 1;
		uint64_t local_toe                   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mrml_int_sum_s          cn85xx; */
	/* struct bdk_mrml_int_sum_s          cn88xx; */
} bdk_mrml_int_sum_t;

#define BDK_MRML_INT_SUM BDK_MRML_INT_SUM_FUNC()
static inline uint64_t BDK_MRML_INT_SUM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_INT_SUM_FUNC(void)
{
	return 0x000087E0FC000810ull;
}
#define typedef_BDK_MRML_INT_SUM bdk_mrml_int_sum_t
#define bustype_BDK_MRML_INT_SUM BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_INT_SUM 0
#define arguments_BDK_MRML_INT_SUM -1,-1,-1,-1
#define basename_BDK_MRML_INT_SUM "MRML_INT_SUM"


/**
 * RSL - mrml_int_sum_w1s
 */
typedef union bdk_mrml_int_sum_w1s {
	uint64_t u;
	struct bdk_mrml_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t local_toe                   : 1;  /**< SR/W1C/H - Local timeout error. When set, a local timeout error has occurred. */
		uint64_t ocx_toe                     : 1;  /**< SR/W1C/H - OCX timeout error. When set, an OCX timeout error has occurred. */
#else
		uint64_t ocx_toe                     : 1;
		uint64_t local_toe                   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mrml_int_sum_w1s_s      cn85xx; */
	/* struct bdk_mrml_int_sum_w1s_s      cn88xx; */
} bdk_mrml_int_sum_w1s_t;

#define BDK_MRML_INT_SUM_W1S BDK_MRML_INT_SUM_W1S_FUNC()
static inline uint64_t BDK_MRML_INT_SUM_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_INT_SUM_W1S_FUNC(void)
{
	return 0x000087E0FC000818ull;
}
#define typedef_BDK_MRML_INT_SUM_W1S bdk_mrml_int_sum_w1s_t
#define bustype_BDK_MRML_INT_SUM_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_INT_SUM_W1S 0
#define arguments_BDK_MRML_INT_SUM_W1S -1,-1,-1,-1
#define basename_BDK_MRML_INT_SUM_W1S "MRML_INT_SUM_W1S"


/**
 * RSL - mrml_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the MRML_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mrml_msix_pbax {
	uint64_t u;
	struct bdk_mrml_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated MRML_MSIX_VEC()_CTL, enumerated by MRML_INT_VEC_E.
                                                                 Bits that have no associated MRML_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_mrml_msix_pbax_s        cn85xx; */
	/* struct bdk_mrml_msix_pbax_s        cn88xx; */
} bdk_mrml_msix_pbax_t;

static inline uint64_t BDK_MRML_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E0FCFF0000ull;
	csr_fatal("BDK_MRML_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MRML_MSIX_PBAX(...) bdk_mrml_msix_pbax_t
#define bustype_BDK_MRML_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_MSIX_PBAX(p1) (p1)
#define arguments_BDK_MRML_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_MRML_MSIX_PBAX(...) "MRML_MSIX_PBAX"


/**
 * RSL - mrml_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the MRML_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mrml_msix_vecx_addr {
	uint64_t u;
	struct bdk_mrml_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's MRML_MSIX_VEC()_ADDR, MRML_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MRML_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_MRML_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_mrml_msix_vecx_addr_s   cn85xx; */
	/* struct bdk_mrml_msix_vecx_addr_s   cn88xx; */
} bdk_mrml_msix_vecx_addr_t;

static inline uint64_t BDK_MRML_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E0FCF00000ull;
	csr_fatal("BDK_MRML_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MRML_MSIX_VECX_ADDR(...) bdk_mrml_msix_vecx_addr_t
#define bustype_BDK_MRML_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_MRML_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_MRML_MSIX_VECX_ADDR(...) "MRML_MSIX_VECX_ADDR"


/**
 * RSL - mrml_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the MRML_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mrml_msix_vecx_ctl {
	uint64_t u;
	struct bdk_mrml_msix_vecx_ctl_s {
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
	/* struct bdk_mrml_msix_vecx_ctl_s    cn85xx; */
	/* struct bdk_mrml_msix_vecx_ctl_s    cn88xx; */
} bdk_mrml_msix_vecx_ctl_t;

static inline uint64_t BDK_MRML_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E0FCF00008ull;
	csr_fatal("BDK_MRML_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MRML_MSIX_VECX_CTL(...) bdk_mrml_msix_vecx_ctl_t
#define bustype_BDK_MRML_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_MRML_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_MRML_MSIX_VECX_CTL(...) "MRML_MSIX_VECX_CTL"


/**
 * RSL - mrml_ncb#_sdev
 */
typedef union bdk_mrml_ncbx_sdev {
	uint64_t u;
	struct bdk_mrml_ncbx_sdev_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t sec                         : 64; /**< SR/W - NCB function secure.  Similar to MRML_RSL()_SDEV except applies to NCB devices. */
#else
		uint64_t sec                         : 64;
#endif
	} s;
	/* struct bdk_mrml_ncbx_sdev_s        cn85xx; */
	/* struct bdk_mrml_ncbx_sdev_s        cn88xx; */
} bdk_mrml_ncbx_sdev_t;

static inline uint64_t BDK_MRML_NCBX_SDEV(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_NCBX_SDEV(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FC000400ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_MRML_NCBX_SDEV", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MRML_NCBX_SDEV(...) bdk_mrml_ncbx_sdev_t
#define bustype_BDK_MRML_NCBX_SDEV(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_NCBX_SDEV(p1) (p1)
#define arguments_BDK_MRML_NCBX_SDEV(p1) (p1),-1,-1,-1
#define basename_BDK_MRML_NCBX_SDEV(...) "MRML_NCBX_SDEV"


/**
 * RSL - mrml_rsl#_sdev
 */
typedef union bdk_mrml_rslx_sdev {
	uint64_t u;
	struct bdk_mrml_rslx_sdev_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t sec                         : 64; /**< SR/W - RSL function secure. If set, the corresponding RSL device ID will be secure access
                                                                 only. Read/writes from non-secure agents will be RAZ/WI.
                                                                 The register index 0..3 indicates which group of 64 functions, and bit index indicates
                                                                 which mod-64 function, for 256 function bits total.
                                                                 For compatiblity with ARM secure boot the following RSL devices
                                                                 should be marked secure: TBD (DTX, KEY, MIO_FUS, OCLA, RST, SPI). */
#else
		uint64_t sec                         : 64;
#endif
	} s;
	/* struct bdk_mrml_rslx_sdev_s        cn85xx; */
	/* struct bdk_mrml_rslx_sdev_s        cn88xx; */
} bdk_mrml_rslx_sdev_t;

static inline uint64_t BDK_MRML_RSLX_SDEV(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_RSLX_SDEV(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0FC000200ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_MRML_RSLX_SDEV", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MRML_RSLX_SDEV(...) bdk_mrml_rslx_sdev_t
#define bustype_BDK_MRML_RSLX_SDEV(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_RSLX_SDEV(p1) (p1)
#define arguments_BDK_MRML_RSLX_SDEV(p1) (p1),-1,-1,-1
#define basename_BDK_MRML_RSLX_SDEV(...) "MRML_RSLX_SDEV"


/**
 * RSL - mrml_scfg
 */
typedef union bdk_mrml_scfg {
	uint64_t u;
	struct bdk_mrml_scfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_mrml_scfg_s             cn85xx; */
	/* struct bdk_mrml_scfg_s             cn88xx; */
} bdk_mrml_scfg_t;

#define BDK_MRML_SCFG BDK_MRML_SCFG_FUNC()
static inline uint64_t BDK_MRML_SCFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MRML_SCFG_FUNC(void)
{
	return 0x000087E0FC000000ull;
}
#define typedef_BDK_MRML_SCFG bdk_mrml_scfg_t
#define bustype_BDK_MRML_SCFG BDK_CSR_TYPE_RSL
#define busnum_BDK_MRML_SCFG 0
#define arguments_BDK_MRML_SCFG -1,-1,-1,-1
#define basename_BDK_MRML_SCFG "MRML_SCFG"

#endif /* __BDK_CSRS_MRML__ */
