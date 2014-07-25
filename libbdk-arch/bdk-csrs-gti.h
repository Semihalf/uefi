#ifndef __BDK_CSRS_GTI__
#define __BDK_CSRS_GTI__
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
 * Cavium GTI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar GTI_BAR_E
 *
 * GTI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace GTI_BAR_E {
	const uint64_t GTI_PF_BAR0 = 0x844000000000;
	const uint64_t GTI_PF_BAR0_PCC_BAR_SIZE_BITS = 23;
	const uint64_t GTI_PF_BAR4 = 0x84400f000000;
	const uint64_t GTI_PF_BAR4_PCC_BAR_SIZE_BITS = 20;
};
#endif

/**
 * Enumeration GTI_INT_VEC_E
 *
 * GTI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum gti_int_vec_e {
	GTI_INT_VEC_E_CORE_WDOG0_INT = 0x3a,
	GTI_INT_VEC_E_CORE_WDOG0_NMI = 0xa,
	GTI_INT_VEC_E_CORE_WDOG10_INT = 0x44,
	GTI_INT_VEC_E_CORE_WDOG10_NMI = 0x14,
	GTI_INT_VEC_E_CORE_WDOG11_INT = 0x45,
	GTI_INT_VEC_E_CORE_WDOG11_NMI = 0x15,
	GTI_INT_VEC_E_CORE_WDOG12_INT = 0x46,
	GTI_INT_VEC_E_CORE_WDOG12_NMI = 0x16,
	GTI_INT_VEC_E_CORE_WDOG13_INT = 0x47,
	GTI_INT_VEC_E_CORE_WDOG13_NMI = 0x17,
	GTI_INT_VEC_E_CORE_WDOG14_INT = 0x48,
	GTI_INT_VEC_E_CORE_WDOG14_NMI = 0x18,
	GTI_INT_VEC_E_CORE_WDOG15_INT = 0x49,
	GTI_INT_VEC_E_CORE_WDOG15_NMI = 0x19,
	GTI_INT_VEC_E_CORE_WDOG16_INT = 0x4a,
	GTI_INT_VEC_E_CORE_WDOG16_NMI = 0x1a,
	GTI_INT_VEC_E_CORE_WDOG17_INT = 0x4b,
	GTI_INT_VEC_E_CORE_WDOG17_NMI = 0x1b,
	GTI_INT_VEC_E_CORE_WDOG18_INT = 0x4c,
	GTI_INT_VEC_E_CORE_WDOG18_NMI = 0x1c,
	GTI_INT_VEC_E_CORE_WDOG19_INT = 0x4d,
	GTI_INT_VEC_E_CORE_WDOG19_NMI = 0x1d,
	GTI_INT_VEC_E_CORE_WDOG1_INT = 0x3b,
	GTI_INT_VEC_E_CORE_WDOG1_NMI = 0xb,
	GTI_INT_VEC_E_CORE_WDOG20_INT = 0x4e,
	GTI_INT_VEC_E_CORE_WDOG20_NMI = 0x1e,
	GTI_INT_VEC_E_CORE_WDOG21_INT = 0x4f,
	GTI_INT_VEC_E_CORE_WDOG21_NMI = 0x1f,
	GTI_INT_VEC_E_CORE_WDOG22_INT = 0x50,
	GTI_INT_VEC_E_CORE_WDOG22_NMI = 0x20,
	GTI_INT_VEC_E_CORE_WDOG23_INT = 0x51,
	GTI_INT_VEC_E_CORE_WDOG23_NMI = 0x21,
	GTI_INT_VEC_E_CORE_WDOG24_INT = 0x52,
	GTI_INT_VEC_E_CORE_WDOG24_NMI = 0x22,
	GTI_INT_VEC_E_CORE_WDOG25_INT = 0x53,
	GTI_INT_VEC_E_CORE_WDOG25_NMI = 0x23,
	GTI_INT_VEC_E_CORE_WDOG26_INT = 0x54,
	GTI_INT_VEC_E_CORE_WDOG26_NMI = 0x24,
	GTI_INT_VEC_E_CORE_WDOG27_INT = 0x55,
	GTI_INT_VEC_E_CORE_WDOG27_NMI = 0x25,
	GTI_INT_VEC_E_CORE_WDOG28_INT = 0x56,
	GTI_INT_VEC_E_CORE_WDOG28_NMI = 0x26,
	GTI_INT_VEC_E_CORE_WDOG29_INT = 0x57,
	GTI_INT_VEC_E_CORE_WDOG29_NMI = 0x27,
	GTI_INT_VEC_E_CORE_WDOG2_INT = 0x3c,
	GTI_INT_VEC_E_CORE_WDOG2_NMI = 0xc,
	GTI_INT_VEC_E_CORE_WDOG30_INT = 0x58,
	GTI_INT_VEC_E_CORE_WDOG30_NMI = 0x28,
	GTI_INT_VEC_E_CORE_WDOG31_INT = 0x59,
	GTI_INT_VEC_E_CORE_WDOG31_NMI = 0x29,
	GTI_INT_VEC_E_CORE_WDOG32_INT = 0x5a,
	GTI_INT_VEC_E_CORE_WDOG32_NMI = 0x2a,
	GTI_INT_VEC_E_CORE_WDOG33_INT = 0x5b,
	GTI_INT_VEC_E_CORE_WDOG33_NMI = 0x2b,
	GTI_INT_VEC_E_CORE_WDOG34_INT = 0x5c,
	GTI_INT_VEC_E_CORE_WDOG34_NMI = 0x2c,
	GTI_INT_VEC_E_CORE_WDOG35_INT = 0x5d,
	GTI_INT_VEC_E_CORE_WDOG35_NMI = 0x2d,
	GTI_INT_VEC_E_CORE_WDOG36_INT = 0x5e,
	GTI_INT_VEC_E_CORE_WDOG36_NMI = 0x2e,
	GTI_INT_VEC_E_CORE_WDOG37_INT = 0x5f,
	GTI_INT_VEC_E_CORE_WDOG37_NMI = 0x2f,
	GTI_INT_VEC_E_CORE_WDOG38_INT = 0x60,
	GTI_INT_VEC_E_CORE_WDOG38_NMI = 0x30,
	GTI_INT_VEC_E_CORE_WDOG39_INT = 0x61,
	GTI_INT_VEC_E_CORE_WDOG39_NMI = 0x31,
	GTI_INT_VEC_E_CORE_WDOG3_INT = 0x3d,
	GTI_INT_VEC_E_CORE_WDOG3_NMI = 0xd,
	GTI_INT_VEC_E_CORE_WDOG40_INT = 0x62,
	GTI_INT_VEC_E_CORE_WDOG40_NMI = 0x32,
	GTI_INT_VEC_E_CORE_WDOG41_INT = 0x63,
	GTI_INT_VEC_E_CORE_WDOG41_NMI = 0x33,
	GTI_INT_VEC_E_CORE_WDOG42_INT = 0x64,
	GTI_INT_VEC_E_CORE_WDOG42_NMI = 0x34,
	GTI_INT_VEC_E_CORE_WDOG43_INT = 0x65,
	GTI_INT_VEC_E_CORE_WDOG43_NMI = 0x35,
	GTI_INT_VEC_E_CORE_WDOG44_INT = 0x66,
	GTI_INT_VEC_E_CORE_WDOG44_NMI = 0x36,
	GTI_INT_VEC_E_CORE_WDOG45_INT = 0x67,
	GTI_INT_VEC_E_CORE_WDOG45_NMI = 0x37,
	GTI_INT_VEC_E_CORE_WDOG46_INT = 0x68,
	GTI_INT_VEC_E_CORE_WDOG46_NMI = 0x38,
	GTI_INT_VEC_E_CORE_WDOG47_INT = 0x69,
	GTI_INT_VEC_E_CORE_WDOG47_NMI = 0x39,
	GTI_INT_VEC_E_CORE_WDOG4_INT = 0x3e,
	GTI_INT_VEC_E_CORE_WDOG4_NMI = 0xe,
	GTI_INT_VEC_E_CORE_WDOG5_INT = 0x3f,
	GTI_INT_VEC_E_CORE_WDOG5_NMI = 0xf,
	GTI_INT_VEC_E_CORE_WDOG6_INT = 0x40,
	GTI_INT_VEC_E_CORE_WDOG6_NMI = 0x10,
	GTI_INT_VEC_E_CORE_WDOG7_INT = 0x41,
	GTI_INT_VEC_E_CORE_WDOG7_NMI = 0x11,
	GTI_INT_VEC_E_CORE_WDOG8_INT = 0x42,
	GTI_INT_VEC_E_CORE_WDOG8_NMI = 0x12,
	GTI_INT_VEC_E_CORE_WDOG9_INT = 0x43,
	GTI_INT_VEC_E_CORE_WDOG9_NMI = 0x13,
	GTI_INT_VEC_E_ERROR = 0x8,
	GTI_INT_VEC_E_MAILBOX_RX = 0x7,
	GTI_INT_VEC_E_SECURE_WATCHDOG = 0x4,
	GTI_INT_VEC_E_SECURE_WATCHDOG_CLEAR = 0x5,
	GTI_INT_VEC_E_SPARE = 0x9,
	GTI_INT_VEC_E_TX_TIMESTAMP = 0x6,
	GTI_INT_VEC_E_WAKE = 0x0,
	GTI_INT_VEC_E_WAKE_CLEAR = 0x1,
	GTI_INT_VEC_E_WATCHDOG = 0x2,
	GTI_INT_VEC_E_WATCHDOG_CLEAR = 0x3,
	GTI_INT_VEC_E_ENUM_LAST = 0x6a,
};



/**
 * NCB32b - gti_bz_cidr0
 */
typedef union bdk_gti_bz_cidr0 {
	uint32_t u;
	struct bdk_gti_bz_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_cidr0_s          cn85xx; */
	/* struct bdk_gti_bz_cidr0_s          cn88xx; */
} bdk_gti_bz_cidr0_t;

#define BDK_GTI_BZ_CIDR0 BDK_GTI_BZ_CIDR0_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR0_FUNC(void)
{
	return 0x0000844000030FF0ull;
}
#define typedef_BDK_GTI_BZ_CIDR0 bdk_gti_bz_cidr0_t
#define bustype_BDK_GTI_BZ_CIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_CIDR0 0
#define arguments_BDK_GTI_BZ_CIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CIDR0 "GTI_BZ_CIDR0"


/**
 * NCB32b - gti_bz_cidr1
 */
typedef union bdk_gti_bz_cidr1 {
	uint32_t u;
	struct bdk_gti_bz_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< RO - Component class. */
		uint32_t preamble                    : 4;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_cidr1_s          cn85xx; */
	/* struct bdk_gti_bz_cidr1_s          cn88xx; */
} bdk_gti_bz_cidr1_t;

#define BDK_GTI_BZ_CIDR1 BDK_GTI_BZ_CIDR1_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR1_FUNC(void)
{
	return 0x0000844000030FF4ull;
}
#define typedef_BDK_GTI_BZ_CIDR1 bdk_gti_bz_cidr1_t
#define bustype_BDK_GTI_BZ_CIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_CIDR1 0
#define arguments_BDK_GTI_BZ_CIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CIDR1 "GTI_BZ_CIDR1"


/**
 * NCB32b - gti_bz_cidr2
 */
typedef union bdk_gti_bz_cidr2 {
	uint32_t u;
	struct bdk_gti_bz_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_cidr2_s          cn85xx; */
	/* struct bdk_gti_bz_cidr2_s          cn88xx; */
} bdk_gti_bz_cidr2_t;

#define BDK_GTI_BZ_CIDR2 BDK_GTI_BZ_CIDR2_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR2_FUNC(void)
{
	return 0x0000844000030FF8ull;
}
#define typedef_BDK_GTI_BZ_CIDR2 bdk_gti_bz_cidr2_t
#define bustype_BDK_GTI_BZ_CIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_CIDR2 0
#define arguments_BDK_GTI_BZ_CIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CIDR2 "GTI_BZ_CIDR2"


/**
 * NCB32b - gti_bz_cidr3
 */
typedef union bdk_gti_bz_cidr3 {
	uint32_t u;
	struct bdk_gti_bz_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_cidr3_s          cn85xx; */
	/* struct bdk_gti_bz_cidr3_s          cn88xx; */
} bdk_gti_bz_cidr3_t;

#define BDK_GTI_BZ_CIDR3 BDK_GTI_BZ_CIDR3_FUNC()
static inline uint64_t BDK_GTI_BZ_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CIDR3_FUNC(void)
{
	return 0x0000844000030FFCull;
}
#define typedef_BDK_GTI_BZ_CIDR3 bdk_gti_bz_cidr3_t
#define bustype_BDK_GTI_BZ_CIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_CIDR3 0
#define arguments_BDK_GTI_BZ_CIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CIDR3 "GTI_BZ_CIDR3"


/**
 * NCB32b - gti_bz_cntp_ctl
 */
typedef union bdk_gti_bz_cntp_ctl {
	uint32_t u;
	struct bdk_gti_bz_cntp_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t istatus                     : 1;  /**< RO/H - Status. */
		uint32_t imask                       : 1;  /**< R/W - Mask. */
		uint32_t enable                      : 1;  /**< R/W - Enable. */
#else
		uint32_t enable                      : 1;
		uint32_t imask                       : 1;
		uint32_t istatus                     : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_gti_bz_cntp_ctl_s       cn85xx; */
	/* struct bdk_gti_bz_cntp_ctl_s       cn88xx; */
} bdk_gti_bz_cntp_ctl_t;

#define BDK_GTI_BZ_CNTP_CTL BDK_GTI_BZ_CNTP_CTL_FUNC()
static inline uint64_t BDK_GTI_BZ_CNTP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CNTP_CTL_FUNC(void)
{
	return 0x000084400003002Cull;
}
#define typedef_BDK_GTI_BZ_CNTP_CTL bdk_gti_bz_cntp_ctl_t
#define bustype_BDK_GTI_BZ_CNTP_CTL BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_CNTP_CTL 0
#define arguments_BDK_GTI_BZ_CNTP_CTL -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CNTP_CTL "GTI_BZ_CNTP_CTL"


/**
 * NCB - gti_bz_cntp_cval
 */
typedef union bdk_gti_bz_cntp_cval {
	uint64_t u;
	struct bdk_gti_bz_cntp_cval_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W/H - Physical Timer compare value. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_gti_bz_cntp_cval_s      cn85xx; */
	/* struct bdk_gti_bz_cntp_cval_s      cn88xx; */
} bdk_gti_bz_cntp_cval_t;

#define BDK_GTI_BZ_CNTP_CVAL BDK_GTI_BZ_CNTP_CVAL_FUNC()
static inline uint64_t BDK_GTI_BZ_CNTP_CVAL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CNTP_CVAL_FUNC(void)
{
	return 0x0000844000030020ull;
}
#define typedef_BDK_GTI_BZ_CNTP_CVAL bdk_gti_bz_cntp_cval_t
#define bustype_BDK_GTI_BZ_CNTP_CVAL BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_BZ_CNTP_CVAL 0
#define arguments_BDK_GTI_BZ_CNTP_CVAL -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CNTP_CVAL "GTI_BZ_CNTP_CVAL"


/**
 * NCB32b - gti_bz_cntp_tval
 */
typedef union bdk_gti_bz_cntp_tval {
	uint32_t u;
	struct bdk_gti_bz_cntp_tval_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t timervalue                  : 32; /**< R/W/H - Physical Timer timer value. */
#else
		uint32_t timervalue                  : 32;
#endif
	} s;
	/* struct bdk_gti_bz_cntp_tval_s      cn85xx; */
	/* struct bdk_gti_bz_cntp_tval_s      cn88xx; */
} bdk_gti_bz_cntp_tval_t;

#define BDK_GTI_BZ_CNTP_TVAL BDK_GTI_BZ_CNTP_TVAL_FUNC()
static inline uint64_t BDK_GTI_BZ_CNTP_TVAL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_CNTP_TVAL_FUNC(void)
{
	return 0x0000844000030028ull;
}
#define typedef_BDK_GTI_BZ_CNTP_TVAL bdk_gti_bz_cntp_tval_t
#define bustype_BDK_GTI_BZ_CNTP_TVAL BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_CNTP_TVAL 0
#define arguments_BDK_GTI_BZ_CNTP_TVAL -1,-1,-1,-1
#define basename_BDK_GTI_BZ_CNTP_TVAL "GTI_BZ_CNTP_TVAL"


/**
 * NCB32b - gti_bz_pidr0
 */
typedef union bdk_gti_bz_pidr0 {
	uint32_t u;
	struct bdk_gti_bz_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_BZ. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_pidr0_s          cn85xx; */
	/* struct bdk_gti_bz_pidr0_s          cn88xx; */
} bdk_gti_bz_pidr0_t;

#define BDK_GTI_BZ_PIDR0 BDK_GTI_BZ_PIDR0_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR0_FUNC(void)
{
	return 0x0000844000030FE0ull;
}
#define typedef_BDK_GTI_BZ_PIDR0 bdk_gti_bz_pidr0_t
#define bustype_BDK_GTI_BZ_PIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR0 0
#define arguments_BDK_GTI_BZ_PIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR0 "GTI_BZ_PIDR0"


/**
 * NCB32b - gti_bz_pidr1
 */
typedef union bdk_gti_bz_pidr1 {
	uint32_t u;
	struct bdk_gti_bz_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_pidr1_s          cn85xx; */
	/* struct bdk_gti_bz_pidr1_s          cn88xx; */
} bdk_gti_bz_pidr1_t;

#define BDK_GTI_BZ_PIDR1 BDK_GTI_BZ_PIDR1_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR1_FUNC(void)
{
	return 0x0000844000030FE4ull;
}
#define typedef_BDK_GTI_BZ_PIDR1 bdk_gti_bz_pidr1_t
#define bustype_BDK_GTI_BZ_PIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR1 0
#define arguments_BDK_GTI_BZ_PIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR1 "GTI_BZ_PIDR1"


/**
 * NCB32b - gti_bz_pidr2
 */
typedef union bdk_gti_bz_pidr2 {
	uint32_t u;
	struct bdk_gti_bz_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_pidr2_s          cn85xx; */
	/* struct bdk_gti_bz_pidr2_s          cn88xx; */
} bdk_gti_bz_pidr2_t;

#define BDK_GTI_BZ_PIDR2 BDK_GTI_BZ_PIDR2_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR2_FUNC(void)
{
	return 0x0000844000030FE8ull;
}
#define typedef_BDK_GTI_BZ_PIDR2 bdk_gti_bz_pidr2_t
#define bustype_BDK_GTI_BZ_PIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR2 0
#define arguments_BDK_GTI_BZ_PIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR2 "GTI_BZ_PIDR2"


/**
 * NCB32b - gti_bz_pidr3
 */
typedef union bdk_gti_bz_pidr3 {
	uint32_t u;
	struct bdk_gti_bz_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_pidr3_s          cn85xx; */
	/* struct bdk_gti_bz_pidr3_s          cn88xx; */
} bdk_gti_bz_pidr3_t;

#define BDK_GTI_BZ_PIDR3 BDK_GTI_BZ_PIDR3_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR3_FUNC(void)
{
	return 0x0000844000030FECull;
}
#define typedef_BDK_GTI_BZ_PIDR3 bdk_gti_bz_pidr3_t
#define bustype_BDK_GTI_BZ_PIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR3 0
#define arguments_BDK_GTI_BZ_PIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR3 "GTI_BZ_PIDR3"


/**
 * NCB32b - gti_bz_pidr4
 */
typedef union bdk_gti_bz_pidr4 {
	uint32_t u;
	struct bdk_gti_bz_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< RO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< RO - JEP106 continuation code. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_bz_pidr4_s          cn85xx; */
	/* struct bdk_gti_bz_pidr4_s          cn88xx; */
} bdk_gti_bz_pidr4_t;

#define BDK_GTI_BZ_PIDR4 BDK_GTI_BZ_PIDR4_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR4_FUNC(void)
{
	return 0x0000844000030FD0ull;
}
#define typedef_BDK_GTI_BZ_PIDR4 bdk_gti_bz_pidr4_t
#define bustype_BDK_GTI_BZ_PIDR4 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR4 0
#define arguments_BDK_GTI_BZ_PIDR4 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR4 "GTI_BZ_PIDR4"


/**
 * NCB32b - gti_bz_pidr5
 */
typedef union bdk_gti_bz_pidr5 {
	uint32_t u;
	struct bdk_gti_bz_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_bz_pidr5_s          cn85xx; */
	/* struct bdk_gti_bz_pidr5_s          cn88xx; */
} bdk_gti_bz_pidr5_t;

#define BDK_GTI_BZ_PIDR5 BDK_GTI_BZ_PIDR5_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR5_FUNC(void)
{
	return 0x0000844000030FD4ull;
}
#define typedef_BDK_GTI_BZ_PIDR5 bdk_gti_bz_pidr5_t
#define bustype_BDK_GTI_BZ_PIDR5 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR5 0
#define arguments_BDK_GTI_BZ_PIDR5 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR5 "GTI_BZ_PIDR5"


/**
 * NCB32b - gti_bz_pidr6
 */
typedef union bdk_gti_bz_pidr6 {
	uint32_t u;
	struct bdk_gti_bz_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_bz_pidr6_s          cn85xx; */
	/* struct bdk_gti_bz_pidr6_s          cn88xx; */
} bdk_gti_bz_pidr6_t;

#define BDK_GTI_BZ_PIDR6 BDK_GTI_BZ_PIDR6_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR6_FUNC(void)
{
	return 0x0000844000030FD8ull;
}
#define typedef_BDK_GTI_BZ_PIDR6 bdk_gti_bz_pidr6_t
#define bustype_BDK_GTI_BZ_PIDR6 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR6 0
#define arguments_BDK_GTI_BZ_PIDR6 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR6 "GTI_BZ_PIDR6"


/**
 * NCB32b - gti_bz_pidr7
 */
typedef union bdk_gti_bz_pidr7 {
	uint32_t u;
	struct bdk_gti_bz_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_bz_pidr7_s          cn85xx; */
	/* struct bdk_gti_bz_pidr7_s          cn88xx; */
} bdk_gti_bz_pidr7_t;

#define BDK_GTI_BZ_PIDR7 BDK_GTI_BZ_PIDR7_FUNC()
static inline uint64_t BDK_GTI_BZ_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_BZ_PIDR7_FUNC(void)
{
	return 0x0000844000030FDCull;
}
#define typedef_BDK_GTI_BZ_PIDR7 bdk_gti_bz_pidr7_t
#define bustype_BDK_GTI_BZ_PIDR7 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_BZ_PIDR7 0
#define arguments_BDK_GTI_BZ_PIDR7 -1,-1,-1,-1
#define basename_BDK_GTI_BZ_PIDR7 "GTI_BZ_PIDR7"


/**
 * NCB32b - gti_cc_cidr0
 */
typedef union bdk_gti_cc_cidr0 {
	uint32_t u;
	struct bdk_gti_cc_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< SRO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_cidr0_s          cn85xx; */
	/* struct bdk_gti_cc_cidr0_s          cn88xx; */
} bdk_gti_cc_cidr0_t;

#define BDK_GTI_CC_CIDR0 BDK_GTI_CC_CIDR0_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR0_FUNC(void)
{
	return 0x0000844000000FF0ull;
}
#define typedef_BDK_GTI_CC_CIDR0 bdk_gti_cc_cidr0_t
#define bustype_BDK_GTI_CC_CIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CIDR0 0
#define arguments_BDK_GTI_CC_CIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_CC_CIDR0 "GTI_CC_CIDR0"


/**
 * NCB32b - gti_cc_cidr1
 */
typedef union bdk_gti_cc_cidr1 {
	uint32_t u;
	struct bdk_gti_cc_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< SRO - Component class. */
		uint32_t preamble                    : 4;  /**< SRO - Preamble identification value. */
#else
		uint32_t preamble                    : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_cidr1_s          cn85xx; */
	/* struct bdk_gti_cc_cidr1_s          cn88xx; */
} bdk_gti_cc_cidr1_t;

#define BDK_GTI_CC_CIDR1 BDK_GTI_CC_CIDR1_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR1_FUNC(void)
{
	return 0x0000844000000FF4ull;
}
#define typedef_BDK_GTI_CC_CIDR1 bdk_gti_cc_cidr1_t
#define bustype_BDK_GTI_CC_CIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CIDR1 0
#define arguments_BDK_GTI_CC_CIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_CC_CIDR1 "GTI_CC_CIDR1"


/**
 * NCB32b - gti_cc_cidr2
 */
typedef union bdk_gti_cc_cidr2 {
	uint32_t u;
	struct bdk_gti_cc_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< SRO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_cidr2_s          cn85xx; */
	/* struct bdk_gti_cc_cidr2_s          cn88xx; */
} bdk_gti_cc_cidr2_t;

#define BDK_GTI_CC_CIDR2 BDK_GTI_CC_CIDR2_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR2_FUNC(void)
{
	return 0x0000844000000FF8ull;
}
#define typedef_BDK_GTI_CC_CIDR2 bdk_gti_cc_cidr2_t
#define bustype_BDK_GTI_CC_CIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CIDR2 0
#define arguments_BDK_GTI_CC_CIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_CC_CIDR2 "GTI_CC_CIDR2"


/**
 * NCB32b - gti_cc_cidr3
 */
typedef union bdk_gti_cc_cidr3 {
	uint32_t u;
	struct bdk_gti_cc_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< SRO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_cidr3_s          cn85xx; */
	/* struct bdk_gti_cc_cidr3_s          cn88xx; */
} bdk_gti_cc_cidr3_t;

#define BDK_GTI_CC_CIDR3 BDK_GTI_CC_CIDR3_FUNC()
static inline uint64_t BDK_GTI_CC_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CIDR3_FUNC(void)
{
	return 0x0000844000000FFCull;
}
#define typedef_BDK_GTI_CC_CIDR3 bdk_gti_cc_cidr3_t
#define bustype_BDK_GTI_CC_CIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CIDR3 0
#define arguments_BDK_GTI_CC_CIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_CC_CIDR3 "GTI_CC_CIDR3"


/**
 * NCB - gti_cc_cntadd
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_cntadd {
	uint64_t u;
	struct bdk_gti_cc_cntadd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cntadd                      : 64; /**< SWO - The value written to CNTADD is atomically added to GTI_CC_CNTCV. */
#else
		uint64_t cntadd                      : 64;
#endif
	} s;
	/* struct bdk_gti_cc_cntadd_s         cn85xx; */
	/* struct bdk_gti_cc_cntadd_s         cn88xx; */
} bdk_gti_cc_cntadd_t;

#define BDK_GTI_CC_CNTADD BDK_GTI_CC_CNTADD_FUNC()
static inline uint64_t BDK_GTI_CC_CNTADD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTADD_FUNC(void)
{
	return 0x00008440000000C8ull;
}
#define typedef_BDK_GTI_CC_CNTADD bdk_gti_cc_cntadd_t
#define bustype_BDK_GTI_CC_CNTADD BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTADD 0
#define arguments_BDK_GTI_CC_CNTADD -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTADD "GTI_CC_CNTADD"


/**
 * NCB32b - gti_cc_cntcr
 */
typedef union bdk_gti_cc_cntcr {
	uint32_t u;
	struct bdk_gti_cc_cntcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t fcreq                       : 1;  /**< SR/W - Frequency change request. Indicates the number of the entry in the frequency
                                                                 table to select. Selecting an unimplemented entry, or an entry that contains
                                                                 0x0, has no effect on the counter.

                                                                 For CNXXXX, which implements a single frequency table entry, must be 0x0. */
		uint32_t reserved_2_7                : 6;
		uint32_t hdbg                        : 1;  /**< SR/W - System counter halt-on-debug enable.
                                                                 0 = System counter ignores halt-on-debug.
                                                                 1 = Asserted halt-on-debug signal halts system counter update. */
		uint32_t en                          : 1;  /**< SR/W - Enables the system counter. */
#else
		uint32_t en                          : 1;
		uint32_t hdbg                        : 1;
		uint32_t reserved_2_7                : 6;
		uint32_t fcreq                       : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_gti_cc_cntcr_s          cn85xx; */
	/* struct bdk_gti_cc_cntcr_s          cn88xx; */
} bdk_gti_cc_cntcr_t;

#define BDK_GTI_CC_CNTCR BDK_GTI_CC_CNTCR_FUNC()
static inline uint64_t BDK_GTI_CC_CNTCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTCR_FUNC(void)
{
	return 0x0000844000000000ull;
}
#define typedef_BDK_GTI_CC_CNTCR bdk_gti_cc_cntcr_t
#define bustype_BDK_GTI_CC_CNTCR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CNTCR 0
#define arguments_BDK_GTI_CC_CNTCR -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTCR "GTI_CC_CNTCR"


/**
 * NCB - gti_cc_cntcv
 */
typedef union bdk_gti_cc_cntcv {
	uint64_t u;
	struct bdk_gti_cc_cntcv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< SR/W/H - System counter count value. The counter is also read-only accessable by the
                                                                 non-secure world with GTI_RD_CNTCV. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_gti_cc_cntcv_s          cn85xx; */
	/* struct bdk_gti_cc_cntcv_s          cn88xx; */
} bdk_gti_cc_cntcv_t;

#define BDK_GTI_CC_CNTCV BDK_GTI_CC_CNTCV_FUNC()
static inline uint64_t BDK_GTI_CC_CNTCV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTCV_FUNC(void)
{
	return 0x0000844000000008ull;
}
#define typedef_BDK_GTI_CC_CNTCV bdk_gti_cc_cntcv_t
#define bustype_BDK_GTI_CC_CNTCV BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTCV 0
#define arguments_BDK_GTI_CC_CNTCV -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTCV "GTI_CC_CNTCV"


/**
 * NCB32b - gti_cc_cntfid0
 */
typedef union bdk_gti_cc_cntfid0 {
	uint32_t u;
	struct bdk_gti_cc_cntfid0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< SR/W - Generic timer frequency mode table, index 1.
                                                                 Programmed by boot software with the system counter clock frequency in Hertz.
                                                                 See also GTI_CTL_CNTFRQ. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_gti_cc_cntfid0_s        cn85xx; */
	/* struct bdk_gti_cc_cntfid0_s        cn88xx; */
} bdk_gti_cc_cntfid0_t;

#define BDK_GTI_CC_CNTFID0 BDK_GTI_CC_CNTFID0_FUNC()
static inline uint64_t BDK_GTI_CC_CNTFID0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTFID0_FUNC(void)
{
	return 0x0000844000000020ull;
}
#define typedef_BDK_GTI_CC_CNTFID0 bdk_gti_cc_cntfid0_t
#define bustype_BDK_GTI_CC_CNTFID0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CNTFID0 0
#define arguments_BDK_GTI_CC_CNTFID0 -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTFID0 "GTI_CC_CNTFID0"


/**
 * NCB32b - gti_cc_cntfid1
 */
typedef union bdk_gti_cc_cntfid1 {
	uint32_t u;
	struct bdk_gti_cc_cntfid1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t constant                    : 32; /**< SRO - Generic timer frequency mode table, index 1. Zero to mark the end of the table. */
#else
		uint32_t constant                    : 32;
#endif
	} s;
	/* struct bdk_gti_cc_cntfid1_s        cn85xx; */
	/* struct bdk_gti_cc_cntfid1_s        cn88xx; */
} bdk_gti_cc_cntfid1_t;

#define BDK_GTI_CC_CNTFID1 BDK_GTI_CC_CNTFID1_FUNC()
static inline uint64_t BDK_GTI_CC_CNTFID1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTFID1_FUNC(void)
{
	return 0x0000844000000024ull;
}
#define typedef_BDK_GTI_CC_CNTFID1 bdk_gti_cc_cntfid1_t
#define bustype_BDK_GTI_CC_CNTFID1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CNTFID1 0
#define arguments_BDK_GTI_CC_CNTFID1 -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTFID1 "GTI_CC_CNTFID1"


/**
 * NCB - gti_cc_cntmb
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_cntmb {
	uint64_t u;
	struct bdk_gti_cc_cntmb_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mbox                        : 64; /**< SR/W - When written, GTI_CC_CNTCV is saved in GTI_CC_CNTMBTS. */
#else
		uint64_t mbox                        : 64;
#endif
	} s;
	/* struct bdk_gti_cc_cntmb_s          cn85xx; */
	/* struct bdk_gti_cc_cntmb_s          cn88xx; */
} bdk_gti_cc_cntmb_t;

#define BDK_GTI_CC_CNTMB BDK_GTI_CC_CNTMB_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_FUNC(void)
{
	return 0x00008440000000D0ull;
}
#define typedef_BDK_GTI_CC_CNTMB bdk_gti_cc_cntmb_t
#define bustype_BDK_GTI_CC_CNTMB BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTMB 0
#define arguments_BDK_GTI_CC_CNTMB -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTMB "GTI_CC_CNTMB"


/**
 * NCB - gti_cc_cntmb_int
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_cntmb_int {
	uint64_t u;
	struct bdk_gti_cc_cntmb_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mbrx                        : 1;  /**< SR/W1C/H - Mailbox receive interrupt. */
		uint64_t txts                        : 1;  /**< SR/W1C/H - Transmit timestamp interrupt. */
#else
		uint64_t txts                        : 1;
		uint64_t mbrx                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gti_cc_cntmb_int_s      cn85xx; */
	/* struct bdk_gti_cc_cntmb_int_s      cn88xx; */
} bdk_gti_cc_cntmb_int_t;

#define BDK_GTI_CC_CNTMB_INT BDK_GTI_CC_CNTMB_INT_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_FUNC(void)
{
	return 0x00008440000000E0ull;
}
#define typedef_BDK_GTI_CC_CNTMB_INT bdk_gti_cc_cntmb_int_t
#define bustype_BDK_GTI_CC_CNTMB_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTMB_INT 0
#define arguments_BDK_GTI_CC_CNTMB_INT -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTMB_INT "GTI_CC_CNTMB_INT"


/**
 * NCB - gti_cc_cntmb_int_ena_clr
 */
typedef union bdk_gti_cc_cntmb_int_ena_clr {
	uint64_t u;
	struct bdk_gti_cc_cntmb_int_ena_clr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mbrx                        : 1;  /**< SR/W1C/H - Mailbox receive interrupt. */
		uint64_t txts                        : 1;  /**< SR/W1C/H - Transmit timestamp interrupt. */
#else
		uint64_t txts                        : 1;
		uint64_t mbrx                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gti_cc_cntmb_int_ena_clr_s cn85xx; */
	/* struct bdk_gti_cc_cntmb_int_ena_clr_s cn88xx; */
} bdk_gti_cc_cntmb_int_ena_clr_t;

#define BDK_GTI_CC_CNTMB_INT_ENA_CLR BDK_GTI_CC_CNTMB_INT_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_CLR_FUNC(void)
{
	return 0x00008440000000F0ull;
}
#define typedef_BDK_GTI_CC_CNTMB_INT_ENA_CLR bdk_gti_cc_cntmb_int_ena_clr_t
#define bustype_BDK_GTI_CC_CNTMB_INT_ENA_CLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTMB_INT_ENA_CLR 0
#define arguments_BDK_GTI_CC_CNTMB_INT_ENA_CLR -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTMB_INT_ENA_CLR "GTI_CC_CNTMB_INT_ENA_CLR"


/**
 * NCB - gti_cc_cntmb_int_ena_set
 */
typedef union bdk_gti_cc_cntmb_int_ena_set {
	uint64_t u;
	struct bdk_gti_cc_cntmb_int_ena_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mbrx                        : 1;  /**< SR/W1C/H - Mailbox receive interrupt. */
		uint64_t txts                        : 1;  /**< SR/W1C/H - Transmit timestamp interrupt. */
#else
		uint64_t txts                        : 1;
		uint64_t mbrx                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gti_cc_cntmb_int_ena_set_s cn85xx; */
	/* struct bdk_gti_cc_cntmb_int_ena_set_s cn88xx; */
} bdk_gti_cc_cntmb_int_ena_set_t;

#define BDK_GTI_CC_CNTMB_INT_ENA_SET BDK_GTI_CC_CNTMB_INT_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_ENA_SET_FUNC(void)
{
	return 0x00008440000000F8ull;
}
#define typedef_BDK_GTI_CC_CNTMB_INT_ENA_SET bdk_gti_cc_cntmb_int_ena_set_t
#define bustype_BDK_GTI_CC_CNTMB_INT_ENA_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTMB_INT_ENA_SET 0
#define arguments_BDK_GTI_CC_CNTMB_INT_ENA_SET -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTMB_INT_ENA_SET "GTI_CC_CNTMB_INT_ENA_SET"


/**
 * NCB - gti_cc_cntmb_int_set
 */
typedef union bdk_gti_cc_cntmb_int_set {
	uint64_t u;
	struct bdk_gti_cc_cntmb_int_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mbrx                        : 1;  /**< SR/W1C/H - Mailbox receive interrupt. */
		uint64_t txts                        : 1;  /**< SR/W1C/H - Transmit timestamp interrupt. */
#else
		uint64_t txts                        : 1;
		uint64_t mbrx                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gti_cc_cntmb_int_set_s  cn85xx; */
	/* struct bdk_gti_cc_cntmb_int_set_s  cn88xx; */
} bdk_gti_cc_cntmb_int_set_t;

#define BDK_GTI_CC_CNTMB_INT_SET BDK_GTI_CC_CNTMB_INT_SET_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMB_INT_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMB_INT_SET_FUNC(void)
{
	return 0x00008440000000E8ull;
}
#define typedef_BDK_GTI_CC_CNTMB_INT_SET bdk_gti_cc_cntmb_int_set_t
#define bustype_BDK_GTI_CC_CNTMB_INT_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTMB_INT_SET 0
#define arguments_BDK_GTI_CC_CNTMB_INT_SET -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTMB_INT_SET "GTI_CC_CNTMB_INT_SET"


/**
 * NCB - gti_cc_cntmbts
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_cntmbts {
	uint64_t u;
	struct bdk_gti_cc_cntmbts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t timestamp                   : 64; /**< SRO/H - Mailbox time stamp. When GTI_CC_CNTMB is written, GTI_CC_CNTCV is saved in GTI_CC_CNTMBTS. */
#else
		uint64_t timestamp                   : 64;
#endif
	} s;
	/* struct bdk_gti_cc_cntmbts_s        cn85xx; */
	/* struct bdk_gti_cc_cntmbts_s        cn88xx; */
} bdk_gti_cc_cntmbts_t;

#define BDK_GTI_CC_CNTMBTS BDK_GTI_CC_CNTMBTS_FUNC()
static inline uint64_t BDK_GTI_CC_CNTMBTS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTMBTS_FUNC(void)
{
	return 0x00008440000000D8ull;
}
#define typedef_BDK_GTI_CC_CNTMBTS bdk_gti_cc_cntmbts_t
#define bustype_BDK_GTI_CC_CNTMBTS BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_CNTMBTS 0
#define arguments_BDK_GTI_CC_CNTMBTS -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTMBTS "GTI_CC_CNTMBTS"


/**
 * NCB32b - gti_cc_cntracc
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_cntracc {
	uint32_t u;
	struct bdk_gti_cc_cntracc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cntracc                     : 32; /**< SRO/H - Fractional bits of the system counter, GTI_RD_CNTCV. */
#else
		uint32_t cntracc                     : 32;
#endif
	} s;
	/* struct bdk_gti_cc_cntracc_s        cn85xx; */
	/* struct bdk_gti_cc_cntracc_s        cn88xx; */
} bdk_gti_cc_cntracc_t;

#define BDK_GTI_CC_CNTRACC BDK_GTI_CC_CNTRACC_FUNC()
static inline uint64_t BDK_GTI_CC_CNTRACC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTRACC_FUNC(void)
{
	return 0x00008440000000C4ull;
}
#define typedef_BDK_GTI_CC_CNTRACC bdk_gti_cc_cntracc_t
#define bustype_BDK_GTI_CC_CNTRACC BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CNTRACC 0
#define arguments_BDK_GTI_CC_CNTRACC -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTRACC "GTI_CC_CNTRACC"


/**
 * NCB32b - gti_cc_cntrate
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_cntrate {
	uint32_t u;
	struct bdk_gti_cc_cntrate_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cntrate                     : 32; /**< SR/W - Sets the system counter count rate.
                                                                 The contents of CNTRATE is a 32-bit fraction that is added to CTI_CC_CNTRACC every source
                                                                 clock. */
#else
		uint32_t cntrate                     : 32;
#endif
	} s;
	/* struct bdk_gti_cc_cntrate_s        cn85xx; */
	/* struct bdk_gti_cc_cntrate_s        cn88xx; */
} bdk_gti_cc_cntrate_t;

#define BDK_GTI_CC_CNTRATE BDK_GTI_CC_CNTRATE_FUNC()
static inline uint64_t BDK_GTI_CC_CNTRATE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTRATE_FUNC(void)
{
	return 0x00008440000000C0ull;
}
#define typedef_BDK_GTI_CC_CNTRATE bdk_gti_cc_cntrate_t
#define bustype_BDK_GTI_CC_CNTRATE BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CNTRATE 0
#define arguments_BDK_GTI_CC_CNTRATE -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTRATE "GTI_CC_CNTRATE"


/**
 * NCB32b - gti_cc_cntsr
 */
typedef union bdk_gti_cc_cntsr {
	uint32_t u;
	struct bdk_gti_cc_cntsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t fcack                       : 1;  /**< SRO/H - Frequency change acknowledge. Indicates the currently selected entry in the frequency
                                                                 table.

                                                                 For CNXXXX, which implements a single frequency table entry, always 0x0. */
		uint32_t reserved_2_7                : 6;
		uint32_t dbgh                        : 1;  /**< SRO/H - Indicates whether the counter is halted because the halt-on-debug signal is asserted.
                                                                 0 = Counter is not halted.
                                                                 1 = Counter is halted. */
		uint32_t reserved_0_0                : 1;
#else
		uint32_t reserved_0_0                : 1;
		uint32_t dbgh                        : 1;
		uint32_t reserved_2_7                : 6;
		uint32_t fcack                       : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_gti_cc_cntsr_s          cn85xx; */
	/* struct bdk_gti_cc_cntsr_s          cn88xx; */
} bdk_gti_cc_cntsr_t;

#define BDK_GTI_CC_CNTSR BDK_GTI_CC_CNTSR_FUNC()
static inline uint64_t BDK_GTI_CC_CNTSR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_CNTSR_FUNC(void)
{
	return 0x0000844000000004ull;
}
#define typedef_BDK_GTI_CC_CNTSR bdk_gti_cc_cntsr_t
#define bustype_BDK_GTI_CC_CNTSR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_CNTSR 0
#define arguments_BDK_GTI_CC_CNTSR -1,-1,-1,-1
#define basename_BDK_GTI_CC_CNTSR "GTI_CC_CNTSR"


/**
 * NCB - gti_cc_imp_ctl
 *
 * Implementation defined register.
 *
 */
typedef union bdk_gti_cc_imp_ctl {
	uint64_t u;
	struct bdk_gti_cc_imp_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t clk_src                     : 1;  /**< SR/W - Count source clock for GTI_CC_CNTRATE.
                                                                 0 = Coprocessor clock.
                                                                 1 = PTP PPS clock. See MIO_PTP_CLOCK_CFG[PPS]. */
#else
		uint64_t clk_src                     : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gti_cc_imp_ctl_s        cn85xx; */
	/* struct bdk_gti_cc_imp_ctl_s        cn88xx; */
} bdk_gti_cc_imp_ctl_t;

#define BDK_GTI_CC_IMP_CTL BDK_GTI_CC_IMP_CTL_FUNC()
static inline uint64_t BDK_GTI_CC_IMP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_IMP_CTL_FUNC(void)
{
	return 0x0000844000000100ull;
}
#define typedef_BDK_GTI_CC_IMP_CTL bdk_gti_cc_imp_ctl_t
#define bustype_BDK_GTI_CC_IMP_CTL BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CC_IMP_CTL 0
#define arguments_BDK_GTI_CC_IMP_CTL -1,-1,-1,-1
#define basename_BDK_GTI_CC_IMP_CTL "GTI_CC_IMP_CTL"


/**
 * NCB32b - gti_cc_pidr0
 */
typedef union bdk_gti_cc_pidr0 {
	uint32_t u;
	struct bdk_gti_cc_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< SRO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_CC. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_pidr0_s          cn85xx; */
	/* struct bdk_gti_cc_pidr0_s          cn88xx; */
} bdk_gti_cc_pidr0_t;

#define BDK_GTI_CC_PIDR0 BDK_GTI_CC_PIDR0_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR0_FUNC(void)
{
	return 0x0000844000000FE0ull;
}
#define typedef_BDK_GTI_CC_PIDR0 bdk_gti_cc_pidr0_t
#define bustype_BDK_GTI_CC_PIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR0 0
#define arguments_BDK_GTI_CC_PIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR0 "GTI_CC_PIDR0"


/**
 * NCB32b - gti_cc_pidr1
 */
typedef union bdk_gti_cc_pidr1 {
	uint32_t u;
	struct bdk_gti_cc_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< SRO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< SRO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_pidr1_s          cn85xx; */
	/* struct bdk_gti_cc_pidr1_s          cn88xx; */
} bdk_gti_cc_pidr1_t;

#define BDK_GTI_CC_PIDR1 BDK_GTI_CC_PIDR1_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR1_FUNC(void)
{
	return 0x0000844000000FE4ull;
}
#define typedef_BDK_GTI_CC_PIDR1 bdk_gti_cc_pidr1_t
#define bustype_BDK_GTI_CC_PIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR1 0
#define arguments_BDK_GTI_CC_PIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR1 "GTI_CC_PIDR1"


/**
 * NCB32b - gti_cc_pidr2
 */
typedef union bdk_gti_cc_pidr2 {
	uint32_t u;
	struct bdk_gti_cc_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< SRO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< SRO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< SRO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_pidr2_s          cn85xx; */
	/* struct bdk_gti_cc_pidr2_s          cn88xx; */
} bdk_gti_cc_pidr2_t;

#define BDK_GTI_CC_PIDR2 BDK_GTI_CC_PIDR2_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR2_FUNC(void)
{
	return 0x0000844000000FE8ull;
}
#define typedef_BDK_GTI_CC_PIDR2 bdk_gti_cc_pidr2_t
#define bustype_BDK_GTI_CC_PIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR2 0
#define arguments_BDK_GTI_CC_PIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR2 "GTI_CC_PIDR2"


/**
 * NCB32b - gti_cc_pidr3
 */
typedef union bdk_gti_cc_pidr3 {
	uint32_t u;
	struct bdk_gti_cc_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< SRO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< SRO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_pidr3_s          cn85xx; */
	/* struct bdk_gti_cc_pidr3_s          cn88xx; */
} bdk_gti_cc_pidr3_t;

#define BDK_GTI_CC_PIDR3 BDK_GTI_CC_PIDR3_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR3_FUNC(void)
{
	return 0x0000844000000FECull;
}
#define typedef_BDK_GTI_CC_PIDR3 bdk_gti_cc_pidr3_t
#define bustype_BDK_GTI_CC_PIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR3 0
#define arguments_BDK_GTI_CC_PIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR3 "GTI_CC_PIDR3"


/**
 * NCB32b - gti_cc_pidr4
 */
typedef union bdk_gti_cc_pidr4 {
	uint32_t u;
	struct bdk_gti_cc_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< SRO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< SRO - JEP106 continuation code. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_cc_pidr4_s          cn85xx; */
	/* struct bdk_gti_cc_pidr4_s          cn88xx; */
} bdk_gti_cc_pidr4_t;

#define BDK_GTI_CC_PIDR4 BDK_GTI_CC_PIDR4_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR4_FUNC(void)
{
	return 0x0000844000000FD0ull;
}
#define typedef_BDK_GTI_CC_PIDR4 bdk_gti_cc_pidr4_t
#define bustype_BDK_GTI_CC_PIDR4 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR4 0
#define arguments_BDK_GTI_CC_PIDR4 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR4 "GTI_CC_PIDR4"


/**
 * NCB32b - gti_cc_pidr5
 */
typedef union bdk_gti_cc_pidr5 {
	uint32_t u;
	struct bdk_gti_cc_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_cc_pidr5_s          cn85xx; */
	/* struct bdk_gti_cc_pidr5_s          cn88xx; */
} bdk_gti_cc_pidr5_t;

#define BDK_GTI_CC_PIDR5 BDK_GTI_CC_PIDR5_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR5_FUNC(void)
{
	return 0x0000844000000FD4ull;
}
#define typedef_BDK_GTI_CC_PIDR5 bdk_gti_cc_pidr5_t
#define bustype_BDK_GTI_CC_PIDR5 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR5 0
#define arguments_BDK_GTI_CC_PIDR5 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR5 "GTI_CC_PIDR5"


/**
 * NCB32b - gti_cc_pidr6
 */
typedef union bdk_gti_cc_pidr6 {
	uint32_t u;
	struct bdk_gti_cc_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_cc_pidr6_s          cn85xx; */
	/* struct bdk_gti_cc_pidr6_s          cn88xx; */
} bdk_gti_cc_pidr6_t;

#define BDK_GTI_CC_PIDR6 BDK_GTI_CC_PIDR6_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR6_FUNC(void)
{
	return 0x0000844000000FD8ull;
}
#define typedef_BDK_GTI_CC_PIDR6 bdk_gti_cc_pidr6_t
#define bustype_BDK_GTI_CC_PIDR6 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR6 0
#define arguments_BDK_GTI_CC_PIDR6 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR6 "GTI_CC_PIDR6"


/**
 * NCB32b - gti_cc_pidr7
 */
typedef union bdk_gti_cc_pidr7 {
	uint32_t u;
	struct bdk_gti_cc_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_cc_pidr7_s          cn85xx; */
	/* struct bdk_gti_cc_pidr7_s          cn88xx; */
} bdk_gti_cc_pidr7_t;

#define BDK_GTI_CC_PIDR7 BDK_GTI_CC_PIDR7_FUNC()
static inline uint64_t BDK_GTI_CC_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CC_PIDR7_FUNC(void)
{
	return 0x0000844000000FDCull;
}
#define typedef_BDK_GTI_CC_PIDR7 bdk_gti_cc_pidr7_t
#define bustype_BDK_GTI_CC_PIDR7 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CC_PIDR7 0
#define arguments_BDK_GTI_CC_PIDR7 -1,-1,-1,-1
#define basename_BDK_GTI_CC_PIDR7 "GTI_CC_PIDR7"


/**
 * NCB32b - gti_ctl_cidr0
 */
typedef union bdk_gti_ctl_cidr0 {
	uint32_t u;
	struct bdk_gti_ctl_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_cidr0_s         cn85xx; */
	/* struct bdk_gti_ctl_cidr0_s         cn88xx; */
} bdk_gti_ctl_cidr0_t;

#define BDK_GTI_CTL_CIDR0 BDK_GTI_CTL_CIDR0_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR0_FUNC(void)
{
	return 0x0000844000020FF0ull;
}
#define typedef_BDK_GTI_CTL_CIDR0 bdk_gti_ctl_cidr0_t
#define bustype_BDK_GTI_CTL_CIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CIDR0 0
#define arguments_BDK_GTI_CTL_CIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CIDR0 "GTI_CTL_CIDR0"


/**
 * NCB32b - gti_ctl_cidr1
 */
typedef union bdk_gti_ctl_cidr1 {
	uint32_t u;
	struct bdk_gti_ctl_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< RO - Component class. */
		uint32_t preamble                    : 4;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_cidr1_s         cn85xx; */
	/* struct bdk_gti_ctl_cidr1_s         cn88xx; */
} bdk_gti_ctl_cidr1_t;

#define BDK_GTI_CTL_CIDR1 BDK_GTI_CTL_CIDR1_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR1_FUNC(void)
{
	return 0x0000844000020FF4ull;
}
#define typedef_BDK_GTI_CTL_CIDR1 bdk_gti_ctl_cidr1_t
#define bustype_BDK_GTI_CTL_CIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CIDR1 0
#define arguments_BDK_GTI_CTL_CIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CIDR1 "GTI_CTL_CIDR1"


/**
 * NCB32b - gti_ctl_cidr2
 */
typedef union bdk_gti_ctl_cidr2 {
	uint32_t u;
	struct bdk_gti_ctl_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_cidr2_s         cn85xx; */
	/* struct bdk_gti_ctl_cidr2_s         cn88xx; */
} bdk_gti_ctl_cidr2_t;

#define BDK_GTI_CTL_CIDR2 BDK_GTI_CTL_CIDR2_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR2_FUNC(void)
{
	return 0x0000844000020FF8ull;
}
#define typedef_BDK_GTI_CTL_CIDR2 bdk_gti_ctl_cidr2_t
#define bustype_BDK_GTI_CTL_CIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CIDR2 0
#define arguments_BDK_GTI_CTL_CIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CIDR2 "GTI_CTL_CIDR2"


/**
 * NCB32b - gti_ctl_cidr3
 */
typedef union bdk_gti_ctl_cidr3 {
	uint32_t u;
	struct bdk_gti_ctl_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_cidr3_s         cn85xx; */
	/* struct bdk_gti_ctl_cidr3_s         cn88xx; */
} bdk_gti_ctl_cidr3_t;

#define BDK_GTI_CTL_CIDR3 BDK_GTI_CTL_CIDR3_FUNC()
static inline uint64_t BDK_GTI_CTL_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CIDR3_FUNC(void)
{
	return 0x0000844000020FFCull;
}
#define typedef_BDK_GTI_CTL_CIDR3 bdk_gti_ctl_cidr3_t
#define bustype_BDK_GTI_CTL_CIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CIDR3 0
#define arguments_BDK_GTI_CTL_CIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CIDR3 "GTI_CTL_CIDR3"


/**
 * NCB32b - gti_ctl_cntacr0
 */
typedef union bdk_gti_ctl_cntacr0 {
	uint32_t u;
	struct bdk_gti_ctl_cntacr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t constant                    : 32; /**< RO - Access Control 0. */
#else
		uint32_t constant                    : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_cntacr0_s       cn85xx; */
	/* struct bdk_gti_ctl_cntacr0_s       cn88xx; */
} bdk_gti_ctl_cntacr0_t;

#define BDK_GTI_CTL_CNTACR0 BDK_GTI_CTL_CNTACR0_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTACR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTACR0_FUNC(void)
{
	return 0x0000844000020040ull;
}
#define typedef_BDK_GTI_CTL_CNTACR0 bdk_gti_ctl_cntacr0_t
#define bustype_BDK_GTI_CTL_CNTACR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CNTACR0 0
#define arguments_BDK_GTI_CTL_CNTACR0 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CNTACR0 "GTI_CTL_CNTACR0"


/**
 * NCB32b - gti_ctl_cntfrq
 */
typedef union bdk_gti_ctl_cntfrq {
	uint32_t u;
	struct bdk_gti_ctl_cntfrq_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t data                        : 32; /**< SR/W - Programmed by boot software with the system counter clock frequency in Hertz.
                                                                 See also GTI_CC_CNTFID0. */
#else
		uint32_t data                        : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_cntfrq_s        cn85xx; */
	/* struct bdk_gti_ctl_cntfrq_s        cn88xx; */
} bdk_gti_ctl_cntfrq_t;

#define BDK_GTI_CTL_CNTFRQ BDK_GTI_CTL_CNTFRQ_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTFRQ_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTFRQ_FUNC(void)
{
	return 0x0000844000020000ull;
}
#define typedef_BDK_GTI_CTL_CNTFRQ bdk_gti_ctl_cntfrq_t
#define bustype_BDK_GTI_CTL_CNTFRQ BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CNTFRQ 0
#define arguments_BDK_GTI_CTL_CNTFRQ -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CNTFRQ "GTI_CTL_CNTFRQ"


/**
 * NCB32b - gti_ctl_cntnsar
 */
typedef union bdk_gti_ctl_cntnsar {
	uint32_t u;
	struct bdk_gti_ctl_cntnsar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t constant                    : 32; /**< SRO - Counter non-secure access. */
#else
		uint32_t constant                    : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_cntnsar_s       cn85xx; */
	/* struct bdk_gti_ctl_cntnsar_s       cn88xx; */
} bdk_gti_ctl_cntnsar_t;

#define BDK_GTI_CTL_CNTNSAR BDK_GTI_CTL_CNTNSAR_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTNSAR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTNSAR_FUNC(void)
{
	return 0x0000844000020004ull;
}
#define typedef_BDK_GTI_CTL_CNTNSAR bdk_gti_ctl_cntnsar_t
#define bustype_BDK_GTI_CTL_CNTNSAR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CNTNSAR 0
#define arguments_BDK_GTI_CTL_CNTNSAR -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CNTNSAR "GTI_CTL_CNTNSAR"


/**
 * NCB32b - gti_ctl_cnttidr
 */
typedef union bdk_gti_ctl_cnttidr {
	uint32_t u;
	struct bdk_gti_ctl_cnttidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t constant                    : 32; /**< RO - Counter Timer ID. */
#else
		uint32_t constant                    : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_cnttidr_s       cn85xx; */
	/* struct bdk_gti_ctl_cnttidr_s       cn88xx; */
} bdk_gti_ctl_cnttidr_t;

#define BDK_GTI_CTL_CNTTIDR BDK_GTI_CTL_CNTTIDR_FUNC()
static inline uint64_t BDK_GTI_CTL_CNTTIDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_CNTTIDR_FUNC(void)
{
	return 0x0000844000020008ull;
}
#define typedef_BDK_GTI_CTL_CNTTIDR bdk_gti_ctl_cnttidr_t
#define bustype_BDK_GTI_CTL_CNTTIDR BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_CNTTIDR 0
#define arguments_BDK_GTI_CTL_CNTTIDR -1,-1,-1,-1
#define basename_BDK_GTI_CTL_CNTTIDR "GTI_CTL_CNTTIDR"


/**
 * NCB32b - gti_ctl_pidr0
 */
typedef union bdk_gti_ctl_pidr0 {
	uint32_t u;
	struct bdk_gti_ctl_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_CTL. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr0_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr0_s         cn88xx; */
} bdk_gti_ctl_pidr0_t;

#define BDK_GTI_CTL_PIDR0 BDK_GTI_CTL_PIDR0_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR0_FUNC(void)
{
	return 0x0000844000020FE0ull;
}
#define typedef_BDK_GTI_CTL_PIDR0 bdk_gti_ctl_pidr0_t
#define bustype_BDK_GTI_CTL_PIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR0 0
#define arguments_BDK_GTI_CTL_PIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR0 "GTI_CTL_PIDR0"


/**
 * NCB32b - gti_ctl_pidr1
 */
typedef union bdk_gti_ctl_pidr1 {
	uint32_t u;
	struct bdk_gti_ctl_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr1_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr1_s         cn88xx; */
} bdk_gti_ctl_pidr1_t;

#define BDK_GTI_CTL_PIDR1 BDK_GTI_CTL_PIDR1_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR1_FUNC(void)
{
	return 0x0000844000020FE4ull;
}
#define typedef_BDK_GTI_CTL_PIDR1 bdk_gti_ctl_pidr1_t
#define bustype_BDK_GTI_CTL_PIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR1 0
#define arguments_BDK_GTI_CTL_PIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR1 "GTI_CTL_PIDR1"


/**
 * NCB32b - gti_ctl_pidr2
 */
typedef union bdk_gti_ctl_pidr2 {
	uint32_t u;
	struct bdk_gti_ctl_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr2_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr2_s         cn88xx; */
} bdk_gti_ctl_pidr2_t;

#define BDK_GTI_CTL_PIDR2 BDK_GTI_CTL_PIDR2_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR2_FUNC(void)
{
	return 0x0000844000020FE8ull;
}
#define typedef_BDK_GTI_CTL_PIDR2 bdk_gti_ctl_pidr2_t
#define bustype_BDK_GTI_CTL_PIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR2 0
#define arguments_BDK_GTI_CTL_PIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR2 "GTI_CTL_PIDR2"


/**
 * NCB32b - gti_ctl_pidr3
 */
typedef union bdk_gti_ctl_pidr3 {
	uint32_t u;
	struct bdk_gti_ctl_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr3_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr3_s         cn88xx; */
} bdk_gti_ctl_pidr3_t;

#define BDK_GTI_CTL_PIDR3 BDK_GTI_CTL_PIDR3_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR3_FUNC(void)
{
	return 0x0000844000020FECull;
}
#define typedef_BDK_GTI_CTL_PIDR3 bdk_gti_ctl_pidr3_t
#define bustype_BDK_GTI_CTL_PIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR3 0
#define arguments_BDK_GTI_CTL_PIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR3 "GTI_CTL_PIDR3"


/**
 * NCB32b - gti_ctl_pidr4
 */
typedef union bdk_gti_ctl_pidr4 {
	uint32_t u;
	struct bdk_gti_ctl_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< RO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< RO - JEP106 continuation code. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr4_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr4_s         cn88xx; */
} bdk_gti_ctl_pidr4_t;

#define BDK_GTI_CTL_PIDR4 BDK_GTI_CTL_PIDR4_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR4_FUNC(void)
{
	return 0x0000844000020FD0ull;
}
#define typedef_BDK_GTI_CTL_PIDR4 bdk_gti_ctl_pidr4_t
#define bustype_BDK_GTI_CTL_PIDR4 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR4 0
#define arguments_BDK_GTI_CTL_PIDR4 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR4 "GTI_CTL_PIDR4"


/**
 * NCB32b - gti_ctl_pidr5
 */
typedef union bdk_gti_ctl_pidr5 {
	uint32_t u;
	struct bdk_gti_ctl_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr5_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr5_s         cn88xx; */
} bdk_gti_ctl_pidr5_t;

#define BDK_GTI_CTL_PIDR5 BDK_GTI_CTL_PIDR5_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR5_FUNC(void)
{
	return 0x0000844000020FD4ull;
}
#define typedef_BDK_GTI_CTL_PIDR5 bdk_gti_ctl_pidr5_t
#define bustype_BDK_GTI_CTL_PIDR5 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR5 0
#define arguments_BDK_GTI_CTL_PIDR5 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR5 "GTI_CTL_PIDR5"


/**
 * NCB32b - gti_ctl_pidr6
 */
typedef union bdk_gti_ctl_pidr6 {
	uint32_t u;
	struct bdk_gti_ctl_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr6_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr6_s         cn88xx; */
} bdk_gti_ctl_pidr6_t;

#define BDK_GTI_CTL_PIDR6 BDK_GTI_CTL_PIDR6_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR6_FUNC(void)
{
	return 0x0000844000020FD8ull;
}
#define typedef_BDK_GTI_CTL_PIDR6 bdk_gti_ctl_pidr6_t
#define bustype_BDK_GTI_CTL_PIDR6 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR6 0
#define arguments_BDK_GTI_CTL_PIDR6 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR6 "GTI_CTL_PIDR6"


/**
 * NCB32b - gti_ctl_pidr7
 */
typedef union bdk_gti_ctl_pidr7 {
	uint32_t u;
	struct bdk_gti_ctl_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_ctl_pidr7_s         cn85xx; */
	/* struct bdk_gti_ctl_pidr7_s         cn88xx; */
} bdk_gti_ctl_pidr7_t;

#define BDK_GTI_CTL_PIDR7 BDK_GTI_CTL_PIDR7_FUNC()
static inline uint64_t BDK_GTI_CTL_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CTL_PIDR7_FUNC(void)
{
	return 0x0000844000020FDCull;
}
#define typedef_BDK_GTI_CTL_PIDR7 bdk_gti_ctl_pidr7_t
#define bustype_BDK_GTI_CTL_PIDR7 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_CTL_PIDR7 0
#define arguments_BDK_GTI_CTL_PIDR7 -1,-1,-1,-1
#define basename_BDK_GTI_CTL_PIDR7 "GTI_CTL_PIDR7"


/**
 * NCB - gti_cwd_int
 *
 * Generic Timer Per-core Watchdog Interrupts
 *
 */
typedef union bdk_gti_cwd_int {
	uint64_t u;
	struct bdk_gti_cwd_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core Watchdog Interrupt (Write one to clear) */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_int_s           cn85xx; */
	/* struct bdk_gti_cwd_int_s           cn88xx; */
} bdk_gti_cwd_int_t;

#define BDK_GTI_CWD_INT BDK_GTI_CWD_INT_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_FUNC(void)
{
	return 0x0000844000040200ull;
}
#define typedef_BDK_GTI_CWD_INT bdk_gti_cwd_int_t
#define bustype_BDK_GTI_CWD_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_INT 0
#define arguments_BDK_GTI_CWD_INT -1,-1,-1,-1
#define basename_BDK_GTI_CWD_INT "GTI_CWD_INT"


/**
 * NCB - gti_cwd_int_ena_clr
 */
typedef union bdk_gti_cwd_int_ena_clr {
	uint64_t u;
	struct bdk_gti_cwd_int_ena_clr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core Watchdog Interrupt (Write one to clear) */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_int_ena_clr_s   cn85xx; */
	/* struct bdk_gti_cwd_int_ena_clr_s   cn88xx; */
} bdk_gti_cwd_int_ena_clr_t;

#define BDK_GTI_CWD_INT_ENA_CLR BDK_GTI_CWD_INT_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_ENA_CLR_FUNC(void)
{
	return 0x0000844000040210ull;
}
#define typedef_BDK_GTI_CWD_INT_ENA_CLR bdk_gti_cwd_int_ena_clr_t
#define bustype_BDK_GTI_CWD_INT_ENA_CLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_INT_ENA_CLR 0
#define arguments_BDK_GTI_CWD_INT_ENA_CLR -1,-1,-1,-1
#define basename_BDK_GTI_CWD_INT_ENA_CLR "GTI_CWD_INT_ENA_CLR"


/**
 * NCB - gti_cwd_int_ena_set
 */
typedef union bdk_gti_cwd_int_ena_set {
	uint64_t u;
	struct bdk_gti_cwd_int_ena_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core Watchdog Interrupt (Write one to clear) */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_int_ena_set_s   cn85xx; */
	/* struct bdk_gti_cwd_int_ena_set_s   cn88xx; */
} bdk_gti_cwd_int_ena_set_t;

#define BDK_GTI_CWD_INT_ENA_SET BDK_GTI_CWD_INT_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_ENA_SET_FUNC(void)
{
	return 0x0000844000040218ull;
}
#define typedef_BDK_GTI_CWD_INT_ENA_SET bdk_gti_cwd_int_ena_set_t
#define bustype_BDK_GTI_CWD_INT_ENA_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_INT_ENA_SET 0
#define arguments_BDK_GTI_CWD_INT_ENA_SET -1,-1,-1,-1
#define basename_BDK_GTI_CWD_INT_ENA_SET "GTI_CWD_INT_ENA_SET"


/**
 * NCB - gti_cwd_int_set
 */
typedef union bdk_gti_cwd_int_set {
	uint64_t u;
	struct bdk_gti_cwd_int_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core Watchdog Interrupt (Write one to clear) */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_int_set_s       cn85xx; */
	/* struct bdk_gti_cwd_int_set_s       cn88xx; */
} bdk_gti_cwd_int_set_t;

#define BDK_GTI_CWD_INT_SET BDK_GTI_CWD_INT_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_INT_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_INT_SET_FUNC(void)
{
	return 0x0000844000040208ull;
}
#define typedef_BDK_GTI_CWD_INT_SET bdk_gti_cwd_int_set_t
#define bustype_BDK_GTI_CWD_INT_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_INT_SET 0
#define arguments_BDK_GTI_CWD_INT_SET -1,-1,-1,-1
#define basename_BDK_GTI_CWD_INT_SET "GTI_CWD_INT_SET"


/**
 * NCB - gti_cwd_nmi
 *
 * Generic Timer Per-core Watchdog Non-Maskable Interrupts
 *
 */
typedef union bdk_gti_cwd_nmi {
	uint64_t u;
	struct bdk_gti_cwd_nmi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core watchdog non-maskable interrupt. */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_nmi_s           cn85xx; */
	/* struct bdk_gti_cwd_nmi_s           cn88xx; */
} bdk_gti_cwd_nmi_t;

#define BDK_GTI_CWD_NMI BDK_GTI_CWD_NMI_FUNC()
static inline uint64_t BDK_GTI_CWD_NMI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_NMI_FUNC(void)
{
	return 0x0000844000040220ull;
}
#define typedef_BDK_GTI_CWD_NMI bdk_gti_cwd_nmi_t
#define bustype_BDK_GTI_CWD_NMI BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_NMI 0
#define arguments_BDK_GTI_CWD_NMI -1,-1,-1,-1
#define basename_BDK_GTI_CWD_NMI "GTI_CWD_NMI"


/**
 * NCB - gti_cwd_nmi_ena_clr
 */
typedef union bdk_gti_cwd_nmi_ena_clr {
	uint64_t u;
	struct bdk_gti_cwd_nmi_ena_clr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core watchdog non-maskable interrupt. */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_nmi_ena_clr_s   cn85xx; */
	/* struct bdk_gti_cwd_nmi_ena_clr_s   cn88xx; */
} bdk_gti_cwd_nmi_ena_clr_t;

#define BDK_GTI_CWD_NMI_ENA_CLR BDK_GTI_CWD_NMI_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_CWD_NMI_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_NMI_ENA_CLR_FUNC(void)
{
	return 0x0000844000040230ull;
}
#define typedef_BDK_GTI_CWD_NMI_ENA_CLR bdk_gti_cwd_nmi_ena_clr_t
#define bustype_BDK_GTI_CWD_NMI_ENA_CLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_NMI_ENA_CLR 0
#define arguments_BDK_GTI_CWD_NMI_ENA_CLR -1,-1,-1,-1
#define basename_BDK_GTI_CWD_NMI_ENA_CLR "GTI_CWD_NMI_ENA_CLR"


/**
 * NCB - gti_cwd_nmi_ena_set
 */
typedef union bdk_gti_cwd_nmi_ena_set {
	uint64_t u;
	struct bdk_gti_cwd_nmi_ena_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core watchdog non-maskable interrupt. */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_nmi_ena_set_s   cn85xx; */
	/* struct bdk_gti_cwd_nmi_ena_set_s   cn88xx; */
} bdk_gti_cwd_nmi_ena_set_t;

#define BDK_GTI_CWD_NMI_ENA_SET BDK_GTI_CWD_NMI_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_NMI_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_NMI_ENA_SET_FUNC(void)
{
	return 0x0000844000040238ull;
}
#define typedef_BDK_GTI_CWD_NMI_ENA_SET bdk_gti_cwd_nmi_ena_set_t
#define bustype_BDK_GTI_CWD_NMI_ENA_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_NMI_ENA_SET 0
#define arguments_BDK_GTI_CWD_NMI_ENA_SET -1,-1,-1,-1
#define basename_BDK_GTI_CWD_NMI_ENA_SET "GTI_CWD_NMI_ENA_SET"


/**
 * NCB - gti_cwd_nmi_set
 */
typedef union bdk_gti_cwd_nmi_set {
	uint64_t u;
	struct bdk_gti_cwd_nmi_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t core                        : 48; /**< R/W1C/H - Per-core watchdog non-maskable interrupt. */
#else
		uint64_t core                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gti_cwd_nmi_set_s       cn85xx; */
	/* struct bdk_gti_cwd_nmi_set_s       cn88xx; */
} bdk_gti_cwd_nmi_set_t;

#define BDK_GTI_CWD_NMI_SET BDK_GTI_CWD_NMI_SET_FUNC()
static inline uint64_t BDK_GTI_CWD_NMI_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_NMI_SET_FUNC(void)
{
	return 0x0000844000040228ull;
}
#define typedef_BDK_GTI_CWD_NMI_SET bdk_gti_cwd_nmi_set_t
#define bustype_BDK_GTI_CWD_NMI_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_NMI_SET 0
#define arguments_BDK_GTI_CWD_NMI_SET -1,-1,-1,-1
#define basename_BDK_GTI_CWD_NMI_SET "GTI_CWD_NMI_SET"


/**
 * NCB - gti_cwd_poke#
 *
 * Per-core Watchdog poke. Writing any value to this register does the following:
 * * Clears any pending interrupt generated by the associated watchdog.
 * * Resets GTI_CWD_WDOG()[STATE] to 0x0.
 * * Sets GTI_CWD_WDOG()[CNT] to (GTI_CWD_WDOG()[LEN] << 8)
 *
 * Reading this register returns the associated GTI_CWD_WDOG() register.
 */
typedef union bdk_gti_cwd_pokex {
	uint64_t u;
	struct bdk_gti_cwd_pokex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t zero                        : 18; /**< WO - Reserved. */
		uint64_t gstop                       : 1;  /**< RO/H - Global-stop enable. */
		uint64_t dstop                       : 1;  /**< RO/H - Debug-stop enable. */
		uint64_t cnt                         : 24; /**< RO/H - Number of 1024-cycle intervals until next watchdog expiration. Set on write to
                                                                 associated GTI_CWD_WDOG_POKE(). */
		uint64_t len                         : 16; /**< RO/H - Watchdog time-expiration length. The most-significant 16 bits of a 24-bit value to be
                                                                 decremented every 1024 cycles. */
		uint64_t state                       : 2;  /**< RO/H - Watchdog state. The number of watchdog time expirations since last core poke. Cleared on
                                                                 write to associated GTI_CWD_WDOG_POKE(). */
		uint64_t mode                        : 2;  /**< RO/H - Watchdog mode:
                                                                 0x0 = Off.
                                                                 0x1 = Interrupt only.
                                                                 0x2 = Interrupt + NMI.
                                                                 0x3 = Interrupt + NMI + soft reset. */
#else
		uint64_t mode                        : 2;
		uint64_t state                       : 2;
		uint64_t len                         : 16;
		uint64_t cnt                         : 24;
		uint64_t dstop                       : 1;
		uint64_t gstop                       : 1;
		uint64_t zero                        : 18;
#endif
	} s;
	/* struct bdk_gti_cwd_pokex_s         cn85xx; */
	/* struct bdk_gti_cwd_pokex_s         cn88xx; */
} bdk_gti_cwd_pokex_t;

static inline uint64_t BDK_GTI_CWD_POKEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_POKEX(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000844000050000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_GTI_CWD_POKEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_CWD_POKEX(...) bdk_gti_cwd_pokex_t
#define bustype_BDK_GTI_CWD_POKEX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_POKEX(p1) (p1)
#define arguments_BDK_GTI_CWD_POKEX(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_CWD_POKEX(...) "GTI_CWD_POKEX"


/**
 * NCB - gti_cwd_wdog#
 */
typedef union bdk_gti_cwd_wdogx {
	uint64_t u;
	struct bdk_gti_cwd_wdogx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_46_63              : 18;
		uint64_t gstop                       : 1;  /**< R/W - Global-stop enable. */
		uint64_t dstop                       : 1;  /**< R/W - Debug-stop enable. */
		uint64_t cnt                         : 24; /**< R/W/H - Number of 1024-cycle intervals until next watchdog expiration. Set on write to
                                                                 associated GTI_CWD_WDOG_POKE(). */
		uint64_t len                         : 16; /**< R/W - Watchdog time-expiration length. The most-significant 16 bits of a 24-bit value to be
                                                                 decremented every 1024 cycles. */
		uint64_t state                       : 2;  /**< R/W/H - Watchdog state. The number of watchdog time expirations since last core poke. Cleared on
                                                                 write to associated GTI_CWD_WDOG_POKE(). */
		uint64_t mode                        : 2;  /**< R/W - Watchdog mode:
                                                                 0x0 = Off.
                                                                 0x1 = Interrupt only.
                                                                 0x2 = Interrupt + NMI.
                                                                 0x3 = Interrupt + NMI + soft reset. */
#else
		uint64_t mode                        : 2;
		uint64_t state                       : 2;
		uint64_t len                         : 16;
		uint64_t cnt                         : 24;
		uint64_t dstop                       : 1;
		uint64_t gstop                       : 1;
		uint64_t reserved_46_63              : 18;
#endif
	} s;
	/* struct bdk_gti_cwd_wdogx_s         cn85xx; */
	/* struct bdk_gti_cwd_wdogx_s         cn88xx; */
} bdk_gti_cwd_wdogx_t;

static inline uint64_t BDK_GTI_CWD_WDOGX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_CWD_WDOGX(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x0000844000040000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_GTI_CWD_WDOGX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_CWD_WDOGX(...) bdk_gti_cwd_wdogx_t
#define bustype_BDK_GTI_CWD_WDOGX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_CWD_WDOGX(p1) (p1)
#define arguments_BDK_GTI_CWD_WDOGX(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_CWD_WDOGX(...) "GTI_CWD_WDOGX"


/**
 * NCB - gti_err_bist_status
 */
typedef union bdk_gti_err_bist_status {
	uint64_t u;
	struct bdk_gti_err_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ram                         : 2;  /**< RO/H - BIST status. */
#else
		uint64_t ram                         : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gti_err_bist_status_s   cn85xx; */
	/* struct bdk_gti_err_bist_status_s   cn88xx; */
} bdk_gti_err_bist_status_t;

#define BDK_GTI_ERR_BIST_STATUS BDK_GTI_ERR_BIST_STATUS_FUNC()
static inline uint64_t BDK_GTI_ERR_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_BIST_STATUS_FUNC(void)
{
	return 0x00008440000F0030ull;
}
#define typedef_BDK_GTI_ERR_BIST_STATUS bdk_gti_err_bist_status_t
#define bustype_BDK_GTI_ERR_BIST_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_BIST_STATUS 0
#define arguments_BDK_GTI_ERR_BIST_STATUS -1,-1,-1,-1
#define basename_BDK_GTI_ERR_BIST_STATUS "GTI_ERR_BIST_STATUS"


/**
 * NCB - gti_err_ecc_disable
 */
typedef union bdk_gti_err_ecc_disable {
	uint64_t u;
	struct bdk_gti_err_ecc_disable_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ram                         : 2;  /**< R/W - Each bit disables correction of respective RAM. */
#else
		uint64_t ram                         : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gti_err_ecc_disable_s   cn85xx; */
	/* struct bdk_gti_err_ecc_disable_s   cn88xx; */
} bdk_gti_err_ecc_disable_t;

#define BDK_GTI_ERR_ECC_DISABLE BDK_GTI_ERR_ECC_DISABLE_FUNC()
static inline uint64_t BDK_GTI_ERR_ECC_DISABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_ECC_DISABLE_FUNC(void)
{
	return 0x00008440000F0020ull;
}
#define typedef_BDK_GTI_ERR_ECC_DISABLE bdk_gti_err_ecc_disable_t
#define bustype_BDK_GTI_ERR_ECC_DISABLE BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_ECC_DISABLE 0
#define arguments_BDK_GTI_ERR_ECC_DISABLE -1,-1,-1,-1
#define basename_BDK_GTI_ERR_ECC_DISABLE "GTI_ERR_ECC_DISABLE"


/**
 * NCB - gti_err_ecc_flip
 */
typedef union bdk_gti_err_ecc_flip {
	uint64_t u;
	struct bdk_gti_err_ecc_flip_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t ramx                        : 2;  /**< R/W - Each bit flips a second bit of syndrome in the respective RAM. */
		uint64_t reserved_2_31               : 30;
		uint64_t ram                         : 2;  /**< R/W - Each bit flips the first bit of syndrome in the respective RAM. */
#else
		uint64_t ram                         : 2;
		uint64_t reserved_2_31               : 30;
		uint64_t ramx                        : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_gti_err_ecc_flip_s      cn85xx; */
	/* struct bdk_gti_err_ecc_flip_s      cn88xx; */
} bdk_gti_err_ecc_flip_t;

#define BDK_GTI_ERR_ECC_FLIP BDK_GTI_ERR_ECC_FLIP_FUNC()
static inline uint64_t BDK_GTI_ERR_ECC_FLIP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_ECC_FLIP_FUNC(void)
{
	return 0x00008440000F0028ull;
}
#define typedef_BDK_GTI_ERR_ECC_FLIP bdk_gti_err_ecc_flip_t
#define bustype_BDK_GTI_ERR_ECC_FLIP BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_ECC_FLIP 0
#define arguments_BDK_GTI_ERR_ECC_FLIP -1,-1,-1,-1
#define basename_BDK_GTI_ERR_ECC_FLIP "GTI_ERR_ECC_FLIP"


/**
 * NCB - gti_err_int
 */
typedef union bdk_gti_err_int {
	uint64_t u;
	struct bdk_gti_err_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t dbe                         : 2;  /**< R/W1C/H - Double bit error. */
		uint64_t reserved_2_31               : 30;
		uint64_t sbe                         : 2;  /**< R/W1C/H - Single bit error. */
#else
		uint64_t sbe                         : 2;
		uint64_t reserved_2_31               : 30;
		uint64_t dbe                         : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_gti_err_int_s           cn85xx; */
	/* struct bdk_gti_err_int_s           cn88xx; */
} bdk_gti_err_int_t;

#define BDK_GTI_ERR_INT BDK_GTI_ERR_INT_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_FUNC(void)
{
	return 0x00008440000F0000ull;
}
#define typedef_BDK_GTI_ERR_INT bdk_gti_err_int_t
#define bustype_BDK_GTI_ERR_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_INT 0
#define arguments_BDK_GTI_ERR_INT -1,-1,-1,-1
#define basename_BDK_GTI_ERR_INT "GTI_ERR_INT"


/**
 * NCB - gti_err_int_ena_clr
 */
typedef union bdk_gti_err_int_ena_clr {
	uint64_t u;
	struct bdk_gti_err_int_ena_clr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t dbe                         : 2;  /**< R/W1C/H - Double bit error. */
		uint64_t reserved_2_31               : 30;
		uint64_t sbe                         : 2;  /**< R/W1C/H - Single bit error. */
#else
		uint64_t sbe                         : 2;
		uint64_t reserved_2_31               : 30;
		uint64_t dbe                         : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_gti_err_int_ena_clr_s   cn85xx; */
	/* struct bdk_gti_err_int_ena_clr_s   cn88xx; */
} bdk_gti_err_int_ena_clr_t;

#define BDK_GTI_ERR_INT_ENA_CLR BDK_GTI_ERR_INT_ENA_CLR_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_ENA_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_ENA_CLR_FUNC(void)
{
	return 0x00008440000F0010ull;
}
#define typedef_BDK_GTI_ERR_INT_ENA_CLR bdk_gti_err_int_ena_clr_t
#define bustype_BDK_GTI_ERR_INT_ENA_CLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_INT_ENA_CLR 0
#define arguments_BDK_GTI_ERR_INT_ENA_CLR -1,-1,-1,-1
#define basename_BDK_GTI_ERR_INT_ENA_CLR "GTI_ERR_INT_ENA_CLR"


/**
 * NCB - gti_err_int_ena_set
 */
typedef union bdk_gti_err_int_ena_set {
	uint64_t u;
	struct bdk_gti_err_int_ena_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t dbe                         : 2;  /**< R/W1C/H - Double bit error. */
		uint64_t reserved_2_31               : 30;
		uint64_t sbe                         : 2;  /**< R/W1C/H - Single bit error. */
#else
		uint64_t sbe                         : 2;
		uint64_t reserved_2_31               : 30;
		uint64_t dbe                         : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_gti_err_int_ena_set_s   cn85xx; */
	/* struct bdk_gti_err_int_ena_set_s   cn88xx; */
} bdk_gti_err_int_ena_set_t;

#define BDK_GTI_ERR_INT_ENA_SET BDK_GTI_ERR_INT_ENA_SET_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_ENA_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_ENA_SET_FUNC(void)
{
	return 0x00008440000F0018ull;
}
#define typedef_BDK_GTI_ERR_INT_ENA_SET bdk_gti_err_int_ena_set_t
#define bustype_BDK_GTI_ERR_INT_ENA_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_INT_ENA_SET 0
#define arguments_BDK_GTI_ERR_INT_ENA_SET -1,-1,-1,-1
#define basename_BDK_GTI_ERR_INT_ENA_SET "GTI_ERR_INT_ENA_SET"


/**
 * NCB - gti_err_int_set
 */
typedef union bdk_gti_err_int_set {
	uint64_t u;
	struct bdk_gti_err_int_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t dbe                         : 2;  /**< R/W1C/H - Double bit error. */
		uint64_t reserved_2_31               : 30;
		uint64_t sbe                         : 2;  /**< R/W1C/H - Single bit error. */
#else
		uint64_t sbe                         : 2;
		uint64_t reserved_2_31               : 30;
		uint64_t dbe                         : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_gti_err_int_set_s       cn85xx; */
	/* struct bdk_gti_err_int_set_s       cn88xx; */
} bdk_gti_err_int_set_t;

#define BDK_GTI_ERR_INT_SET BDK_GTI_ERR_INT_SET_FUNC()
static inline uint64_t BDK_GTI_ERR_INT_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_ERR_INT_SET_FUNC(void)
{
	return 0x00008440000F0008ull;
}
#define typedef_BDK_GTI_ERR_INT_SET bdk_gti_err_int_set_t
#define bustype_BDK_GTI_ERR_INT_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_ERR_INT_SET 0
#define arguments_BDK_GTI_ERR_INT_SET -1,-1,-1,-1
#define basename_BDK_GTI_ERR_INT_SET "GTI_ERR_INT_SET"


/**
 * NCB - gti_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the GTI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_gti_msix_pbax {
	uint64_t u;
	struct bdk_gti_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for each interrupt, enumerated by GTI_INT_VEC_E.
                                                                 Bits that have no associated GTI_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_gti_msix_pbax_s         cn85xx; */
	/* struct bdk_gti_msix_pbax_s         cn88xx; */
} bdk_gti_msix_pbax_t;

static inline uint64_t BDK_GTI_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_MSIX_PBAX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000084400F0F0000ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_GTI_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_MSIX_PBAX(...) bdk_gti_msix_pbax_t
#define bustype_BDK_GTI_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_MSIX_PBAX(p1) (p1)
#define arguments_BDK_GTI_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_MSIX_PBAX(...) "GTI_MSIX_PBAX"


/**
 * NCB - gti_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the GTI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_gti_msix_vecx_addr {
	uint64_t u;
	struct bdk_gti_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's GTI_MSIX_VEC()_ADDR, GTI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GTI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_GTI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_gti_msix_vecx_addr_s    cn85xx; */
	/* struct bdk_gti_msix_vecx_addr_s    cn88xx; */
} bdk_gti_msix_vecx_addr_t;

static inline uint64_t BDK_GTI_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 105)))
		return 0x000084400F000000ull + (param1 & 127) * 0x10ull;
	csr_fatal("BDK_GTI_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_MSIX_VECX_ADDR(...) bdk_gti_msix_vecx_addr_t
#define bustype_BDK_GTI_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_GTI_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_MSIX_VECX_ADDR(...) "GTI_MSIX_VECX_ADDR"


/**
 * NCB - gti_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the GTI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_gti_msix_vecx_ctl {
	uint64_t u;
	struct bdk_gti_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< R/W - When set, no MSI-X interrupts will be sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< R/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_gti_msix_vecx_ctl_s     cn85xx; */
	/* struct bdk_gti_msix_vecx_ctl_s     cn88xx; */
} bdk_gti_msix_vecx_ctl_t;

static inline uint64_t BDK_GTI_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 105)))
		return 0x000084400F000008ull + (param1 & 127) * 0x10ull;
	csr_fatal("BDK_GTI_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_MSIX_VECX_CTL(...) bdk_gti_msix_vecx_ctl_t
#define bustype_BDK_GTI_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_GTI_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_MSIX_VECX_CTL(...) "GTI_MSIX_VECX_CTL"


/**
 * NCB32b - gti_rd_cidr0
 */
typedef union bdk_gti_rd_cidr0 {
	uint32_t u;
	struct bdk_gti_rd_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_cidr0_s          cn85xx; */
	/* struct bdk_gti_rd_cidr0_s          cn88xx; */
} bdk_gti_rd_cidr0_t;

#define BDK_GTI_RD_CIDR0 BDK_GTI_RD_CIDR0_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR0_FUNC(void)
{
	return 0x0000844000010FF0ull;
}
#define typedef_BDK_GTI_RD_CIDR0 bdk_gti_rd_cidr0_t
#define bustype_BDK_GTI_RD_CIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_CIDR0 0
#define arguments_BDK_GTI_RD_CIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_RD_CIDR0 "GTI_RD_CIDR0"


/**
 * NCB32b - gti_rd_cidr1
 */
typedef union bdk_gti_rd_cidr1 {
	uint32_t u;
	struct bdk_gti_rd_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< RO - Component class. */
		uint32_t preamble                    : 4;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_cidr1_s          cn85xx; */
	/* struct bdk_gti_rd_cidr1_s          cn88xx; */
} bdk_gti_rd_cidr1_t;

#define BDK_GTI_RD_CIDR1 BDK_GTI_RD_CIDR1_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR1_FUNC(void)
{
	return 0x0000844000010FF4ull;
}
#define typedef_BDK_GTI_RD_CIDR1 bdk_gti_rd_cidr1_t
#define bustype_BDK_GTI_RD_CIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_CIDR1 0
#define arguments_BDK_GTI_RD_CIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_RD_CIDR1 "GTI_RD_CIDR1"


/**
 * NCB32b - gti_rd_cidr2
 */
typedef union bdk_gti_rd_cidr2 {
	uint32_t u;
	struct bdk_gti_rd_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_cidr2_s          cn85xx; */
	/* struct bdk_gti_rd_cidr2_s          cn88xx; */
} bdk_gti_rd_cidr2_t;

#define BDK_GTI_RD_CIDR2 BDK_GTI_RD_CIDR2_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR2_FUNC(void)
{
	return 0x0000844000010FF8ull;
}
#define typedef_BDK_GTI_RD_CIDR2 bdk_gti_rd_cidr2_t
#define bustype_BDK_GTI_RD_CIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_CIDR2 0
#define arguments_BDK_GTI_RD_CIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_RD_CIDR2 "GTI_RD_CIDR2"


/**
 * NCB32b - gti_rd_cidr3
 */
typedef union bdk_gti_rd_cidr3 {
	uint32_t u;
	struct bdk_gti_rd_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_cidr3_s          cn85xx; */
	/* struct bdk_gti_rd_cidr3_s          cn88xx; */
} bdk_gti_rd_cidr3_t;

#define BDK_GTI_RD_CIDR3 BDK_GTI_RD_CIDR3_FUNC()
static inline uint64_t BDK_GTI_RD_CIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CIDR3_FUNC(void)
{
	return 0x0000844000010FFCull;
}
#define typedef_BDK_GTI_RD_CIDR3 bdk_gti_rd_cidr3_t
#define bustype_BDK_GTI_RD_CIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_CIDR3 0
#define arguments_BDK_GTI_RD_CIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_RD_CIDR3 "GTI_RD_CIDR3"


/**
 * NCB - gti_rd_cntcv
 */
typedef union bdk_gti_rd_cntcv {
	uint64_t u;
	struct bdk_gti_rd_cntcv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< RO/H - System counter count value.  The counter is writable with GTI_CC_CNTCV. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_gti_rd_cntcv_s          cn85xx; */
	/* struct bdk_gti_rd_cntcv_s          cn88xx; */
} bdk_gti_rd_cntcv_t;

#define BDK_GTI_RD_CNTCV BDK_GTI_RD_CNTCV_FUNC()
static inline uint64_t BDK_GTI_RD_CNTCV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_CNTCV_FUNC(void)
{
	return 0x0000844000010000ull;
}
#define typedef_BDK_GTI_RD_CNTCV bdk_gti_rd_cntcv_t
#define bustype_BDK_GTI_RD_CNTCV BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_RD_CNTCV 0
#define arguments_BDK_GTI_RD_CNTCV -1,-1,-1,-1
#define basename_BDK_GTI_RD_CNTCV "GTI_RD_CNTCV"


/**
 * NCB32b - gti_rd_pidr0
 */
typedef union bdk_gti_rd_pidr0 {
	uint32_t u;
	struct bdk_gti_rd_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_RD. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_pidr0_s          cn85xx; */
	/* struct bdk_gti_rd_pidr0_s          cn88xx; */
} bdk_gti_rd_pidr0_t;

#define BDK_GTI_RD_PIDR0 BDK_GTI_RD_PIDR0_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR0_FUNC(void)
{
	return 0x0000844000010FE0ull;
}
#define typedef_BDK_GTI_RD_PIDR0 bdk_gti_rd_pidr0_t
#define bustype_BDK_GTI_RD_PIDR0 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR0 0
#define arguments_BDK_GTI_RD_PIDR0 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR0 "GTI_RD_PIDR0"


/**
 * NCB32b - gti_rd_pidr1
 */
typedef union bdk_gti_rd_pidr1 {
	uint32_t u;
	struct bdk_gti_rd_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_pidr1_s          cn85xx; */
	/* struct bdk_gti_rd_pidr1_s          cn88xx; */
} bdk_gti_rd_pidr1_t;

#define BDK_GTI_RD_PIDR1 BDK_GTI_RD_PIDR1_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR1_FUNC(void)
{
	return 0x0000844000010FE4ull;
}
#define typedef_BDK_GTI_RD_PIDR1 bdk_gti_rd_pidr1_t
#define bustype_BDK_GTI_RD_PIDR1 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR1 0
#define arguments_BDK_GTI_RD_PIDR1 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR1 "GTI_RD_PIDR1"


/**
 * NCB32b - gti_rd_pidr2
 */
typedef union bdk_gti_rd_pidr2 {
	uint32_t u;
	struct bdk_gti_rd_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_pidr2_s          cn85xx; */
	/* struct bdk_gti_rd_pidr2_s          cn88xx; */
} bdk_gti_rd_pidr2_t;

#define BDK_GTI_RD_PIDR2 BDK_GTI_RD_PIDR2_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR2_FUNC(void)
{
	return 0x0000844000010FE8ull;
}
#define typedef_BDK_GTI_RD_PIDR2 bdk_gti_rd_pidr2_t
#define bustype_BDK_GTI_RD_PIDR2 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR2 0
#define arguments_BDK_GTI_RD_PIDR2 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR2 "GTI_RD_PIDR2"


/**
 * NCB32b - gti_rd_pidr3
 */
typedef union bdk_gti_rd_pidr3 {
	uint32_t u;
	struct bdk_gti_rd_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_pidr3_s          cn85xx; */
	/* struct bdk_gti_rd_pidr3_s          cn88xx; */
} bdk_gti_rd_pidr3_t;

#define BDK_GTI_RD_PIDR3 BDK_GTI_RD_PIDR3_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR3_FUNC(void)
{
	return 0x0000844000010FECull;
}
#define typedef_BDK_GTI_RD_PIDR3 bdk_gti_rd_pidr3_t
#define bustype_BDK_GTI_RD_PIDR3 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR3 0
#define arguments_BDK_GTI_RD_PIDR3 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR3 "GTI_RD_PIDR3"


/**
 * NCB32b - gti_rd_pidr4
 */
typedef union bdk_gti_rd_pidr4 {
	uint32_t u;
	struct bdk_gti_rd_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< RO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< RO - JEP106 continuation code. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_rd_pidr4_s          cn85xx; */
	/* struct bdk_gti_rd_pidr4_s          cn88xx; */
} bdk_gti_rd_pidr4_t;

#define BDK_GTI_RD_PIDR4 BDK_GTI_RD_PIDR4_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR4_FUNC(void)
{
	return 0x0000844000010FD0ull;
}
#define typedef_BDK_GTI_RD_PIDR4 bdk_gti_rd_pidr4_t
#define bustype_BDK_GTI_RD_PIDR4 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR4 0
#define arguments_BDK_GTI_RD_PIDR4 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR4 "GTI_RD_PIDR4"


/**
 * NCB32b - gti_rd_pidr5
 */
typedef union bdk_gti_rd_pidr5 {
	uint32_t u;
	struct bdk_gti_rd_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_rd_pidr5_s          cn85xx; */
	/* struct bdk_gti_rd_pidr5_s          cn88xx; */
} bdk_gti_rd_pidr5_t;

#define BDK_GTI_RD_PIDR5 BDK_GTI_RD_PIDR5_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR5_FUNC(void)
{
	return 0x0000844000010FD4ull;
}
#define typedef_BDK_GTI_RD_PIDR5 bdk_gti_rd_pidr5_t
#define bustype_BDK_GTI_RD_PIDR5 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR5 0
#define arguments_BDK_GTI_RD_PIDR5 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR5 "GTI_RD_PIDR5"


/**
 * NCB32b - gti_rd_pidr6
 */
typedef union bdk_gti_rd_pidr6 {
	uint32_t u;
	struct bdk_gti_rd_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_rd_pidr6_s          cn85xx; */
	/* struct bdk_gti_rd_pidr6_s          cn88xx; */
} bdk_gti_rd_pidr6_t;

#define BDK_GTI_RD_PIDR6 BDK_GTI_RD_PIDR6_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR6_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR6_FUNC(void)
{
	return 0x0000844000010FD8ull;
}
#define typedef_BDK_GTI_RD_PIDR6 bdk_gti_rd_pidr6_t
#define bustype_BDK_GTI_RD_PIDR6 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR6 0
#define arguments_BDK_GTI_RD_PIDR6 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR6 "GTI_RD_PIDR6"


/**
 * NCB32b - gti_rd_pidr7
 */
typedef union bdk_gti_rd_pidr7 {
	uint32_t u;
	struct bdk_gti_rd_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_rd_pidr7_s          cn85xx; */
	/* struct bdk_gti_rd_pidr7_s          cn88xx; */
} bdk_gti_rd_pidr7_t;

#define BDK_GTI_RD_PIDR7 BDK_GTI_RD_PIDR7_FUNC()
static inline uint64_t BDK_GTI_RD_PIDR7_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_RD_PIDR7_FUNC(void)
{
	return 0x0000844000010FDCull;
}
#define typedef_BDK_GTI_RD_PIDR7 bdk_gti_rd_pidr7_t
#define bustype_BDK_GTI_RD_PIDR7 BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_RD_PIDR7 0
#define arguments_BDK_GTI_RD_PIDR7 -1,-1,-1,-1
#define basename_BDK_GTI_RD_PIDR7 "GTI_RD_PIDR7"


/**
 * NCB32b - gti_wc#_cidr0
 */
typedef union bdk_gti_wcx_cidr0 {
	uint32_t u;
	struct bdk_gti_wcx_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_cidr0_s         cn85xx; */
	/* struct bdk_gti_wcx_cidr0_s         cn88xx; */
} bdk_gti_wcx_cidr0_t;

static inline uint64_t BDK_GTI_WCX_CIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FF0ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_CIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_CIDR0(...) bdk_gti_wcx_cidr0_t
#define bustype_BDK_GTI_WCX_CIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_CIDR0(p1) (p1)
#define arguments_BDK_GTI_WCX_CIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_CIDR0(...) "GTI_WCX_CIDR0"


/**
 * NCB32b - gti_wc#_cidr1
 */
typedef union bdk_gti_wcx_cidr1 {
	uint32_t u;
	struct bdk_gti_wcx_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< RO - Component class. */
		uint32_t preamble                    : 4;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_cidr1_s         cn85xx; */
	/* struct bdk_gti_wcx_cidr1_s         cn88xx; */
} bdk_gti_wcx_cidr1_t;

static inline uint64_t BDK_GTI_WCX_CIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FF4ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_CIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_CIDR1(...) bdk_gti_wcx_cidr1_t
#define bustype_BDK_GTI_WCX_CIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_CIDR1(p1) (p1)
#define arguments_BDK_GTI_WCX_CIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_CIDR1(...) "GTI_WCX_CIDR1"


/**
 * NCB32b - gti_wc#_cidr2
 */
typedef union bdk_gti_wcx_cidr2 {
	uint32_t u;
	struct bdk_gti_wcx_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_cidr2_s         cn85xx; */
	/* struct bdk_gti_wcx_cidr2_s         cn88xx; */
} bdk_gti_wcx_cidr2_t;

static inline uint64_t BDK_GTI_WCX_CIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FF8ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_CIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_CIDR2(...) bdk_gti_wcx_cidr2_t
#define bustype_BDK_GTI_WCX_CIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_CIDR2(p1) (p1)
#define arguments_BDK_GTI_WCX_CIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_CIDR2(...) "GTI_WCX_CIDR2"


/**
 * NCB32b - gti_wc#_cidr3
 */
typedef union bdk_gti_wcx_cidr3 {
	uint32_t u;
	struct bdk_gti_wcx_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_cidr3_s         cn85xx; */
	/* struct bdk_gti_wcx_cidr3_s         cn88xx; */
} bdk_gti_wcx_cidr3_t;

static inline uint64_t BDK_GTI_WCX_CIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_CIDR3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FFCull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_CIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_CIDR3(...) bdk_gti_wcx_cidr3_t
#define bustype_BDK_GTI_WCX_CIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_CIDR3(p1) (p1)
#define arguments_BDK_GTI_WCX_CIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_CIDR3(...) "GTI_WCX_CIDR3"


/**
 * NCB32b - gti_wc#_pidr0
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_pidr0 {
	uint32_t u;
	struct bdk_gti_wcx_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_WC. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr0_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr0_s         cn88xx; */
} bdk_gti_wcx_pidr0_t;

static inline uint64_t BDK_GTI_WCX_PIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FE0ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR0(...) bdk_gti_wcx_pidr0_t
#define bustype_BDK_GTI_WCX_PIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR0(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR0(...) "GTI_WCX_PIDR0"


/**
 * NCB32b - gti_wc#_pidr1
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_pidr1 {
	uint32_t u;
	struct bdk_gti_wcx_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr1_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr1_s         cn88xx; */
} bdk_gti_wcx_pidr1_t;

static inline uint64_t BDK_GTI_WCX_PIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FE4ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR1(...) bdk_gti_wcx_pidr1_t
#define bustype_BDK_GTI_WCX_PIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR1(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR1(...) "GTI_WCX_PIDR1"


/**
 * NCB32b - gti_wc#_pidr2
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_pidr2 {
	uint32_t u;
	struct bdk_gti_wcx_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr2_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr2_s         cn88xx; */
} bdk_gti_wcx_pidr2_t;

static inline uint64_t BDK_GTI_WCX_PIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FE8ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR2(...) bdk_gti_wcx_pidr2_t
#define bustype_BDK_GTI_WCX_PIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR2(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR2(...) "GTI_WCX_PIDR2"


/**
 * NCB32b - gti_wc#_pidr3
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_pidr3 {
	uint32_t u;
	struct bdk_gti_wcx_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr3_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr3_s         cn88xx; */
} bdk_gti_wcx_pidr3_t;

static inline uint64_t BDK_GTI_WCX_PIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FECull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR3(...) bdk_gti_wcx_pidr3_t
#define bustype_BDK_GTI_WCX_PIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR3(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR3(...) "GTI_WCX_PIDR3"


/**
 * NCB32b - gti_wc#_pidr4
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_pidr4 {
	uint32_t u;
	struct bdk_gti_wcx_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< RO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< RO - JEP106 continuation code. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr4_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr4_s         cn88xx; */
} bdk_gti_wcx_pidr4_t;

static inline uint64_t BDK_GTI_WCX_PIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR4(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FD0ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR4(...) bdk_gti_wcx_pidr4_t
#define bustype_BDK_GTI_WCX_PIDR4(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR4(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR4(...) "GTI_WCX_PIDR4"


/**
 * NCB32b - gti_wc#_pidr5
 */
typedef union bdk_gti_wcx_pidr5 {
	uint32_t u;
	struct bdk_gti_wcx_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr5_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr5_s         cn88xx; */
} bdk_gti_wcx_pidr5_t;

static inline uint64_t BDK_GTI_WCX_PIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR5(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FD4ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR5(...) bdk_gti_wcx_pidr5_t
#define bustype_BDK_GTI_WCX_PIDR5(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR5(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR5(...) "GTI_WCX_PIDR5"


/**
 * NCB32b - gti_wc#_pidr6
 */
typedef union bdk_gti_wcx_pidr6 {
	uint32_t u;
	struct bdk_gti_wcx_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr6_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr6_s         cn88xx; */
} bdk_gti_wcx_pidr6_t;

static inline uint64_t BDK_GTI_WCX_PIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR6(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FD8ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR6(...) bdk_gti_wcx_pidr6_t
#define bustype_BDK_GTI_WCX_PIDR6(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR6(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR6(...) "GTI_WCX_PIDR6"


/**
 * NCB32b - gti_wc#_pidr7
 */
typedef union bdk_gti_wcx_pidr7 {
	uint32_t u;
	struct bdk_gti_wcx_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_wcx_pidr7_s         cn85xx; */
	/* struct bdk_gti_wcx_pidr7_s         cn88xx; */
} bdk_gti_wcx_pidr7_t;

static inline uint64_t BDK_GTI_WCX_PIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_PIDR7(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FDCull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_PIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_PIDR7(...) bdk_gti_wcx_pidr7_t
#define bustype_BDK_GTI_WCX_PIDR7(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_PIDR7(p1) (p1)
#define arguments_BDK_GTI_WCX_PIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_PIDR7(...) "GTI_WCX_PIDR7"


/**
 * NCB32b - gti_wc#_w_iidr
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_w_iidr {
	uint32_t u;
	struct bdk_gti_wcx_w_iidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t productid                   : 8;  /**< RO - An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
		uint32_t variant                     : 4;  /**< RO - Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
		uint32_t arch                        : 4;  /**< RO - Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
		uint32_t revision                    : 4;  /**< RO - Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
		uint32_t implementer                 : 12; /**< RO - Indicates the implementer: 0x34C = Cavium. */
#else
		uint32_t implementer                 : 12;
		uint32_t revision                    : 4;
		uint32_t arch                        : 4;
		uint32_t variant                     : 4;
		uint32_t productid                   : 8;
#endif
	} s;
	/* struct bdk_gti_wcx_w_iidr_s        cn85xx; */
	/* struct bdk_gti_wcx_w_iidr_s        cn88xx; */
} bdk_gti_wcx_w_iidr_t;

static inline uint64_t BDK_GTI_WCX_W_IIDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_W_IIDR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080FCCull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_W_IIDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_W_IIDR(...) bdk_gti_wcx_w_iidr_t
#define bustype_BDK_GTI_WCX_W_IIDR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_W_IIDR(p1) (p1)
#define arguments_BDK_GTI_WCX_W_IIDR(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_W_IIDR(...) "GTI_WCX_W_IIDR"


/**
 * NCB32b - gti_wc#_wcs
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_wcs {
	uint32_t u;
	struct bdk_gti_wcx_wcs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t ws1                         : 1;  /**< RO/H - WS1 */
		uint32_t ws0                         : 1;  /**< RO/H - WS0 */
		uint32_t en                          : 1;  /**< R/W - Enable. */
#else
		uint32_t en                          : 1;
		uint32_t ws0                         : 1;
		uint32_t ws1                         : 1;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	/* struct bdk_gti_wcx_wcs_s           cn85xx; */
	/* struct bdk_gti_wcx_wcs_s           cn88xx; */
} bdk_gti_wcx_wcs_t;

static inline uint64_t BDK_GTI_WCX_WCS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_WCS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080000ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_WCS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_WCS(...) bdk_gti_wcx_wcs_t
#define bustype_BDK_GTI_WCX_WCS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_WCS(p1) (p1)
#define arguments_BDK_GTI_WCX_WCS(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_WCS(...) "GTI_WCX_WCS"


/**
 * NCB - gti_wc#_wcv
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_wcv {
	uint64_t u;
	struct bdk_gti_wcx_wcv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wdcv                        : 64; /**< R/W/H - Watchdog compare value. */
#else
		uint64_t wdcv                        : 64;
#endif
	} s;
	/* struct bdk_gti_wcx_wcv_s           cn85xx; */
	/* struct bdk_gti_wcx_wcv_s           cn88xx; */
} bdk_gti_wcx_wcv_t;

static inline uint64_t BDK_GTI_WCX_WCV(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_WCV(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080010ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_WCV", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_WCV(...) bdk_gti_wcx_wcv_t
#define bustype_BDK_GTI_WCX_WCV(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GTI_WCX_WCV(p1) (p1)
#define arguments_BDK_GTI_WCX_WCV(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_WCV(...) "GTI_WCX_WCV"


/**
 * NCB32b - gti_wc#_wor
 *
 * GTI_WC(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WC(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wcx_wor {
	uint32_t u;
	struct bdk_gti_wcx_wor_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t offset                      : 32; /**< R/W/H - Watchdog offset. */
#else
		uint32_t offset                      : 32;
#endif
	} s;
	/* struct bdk_gti_wcx_wor_s           cn85xx; */
	/* struct bdk_gti_wcx_wor_s           cn88xx; */
} bdk_gti_wcx_wor_t;

static inline uint64_t BDK_GTI_WCX_WOR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WCX_WOR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000080008ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WCX_WOR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WCX_WOR(...) bdk_gti_wcx_wor_t
#define bustype_BDK_GTI_WCX_WOR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WCX_WOR(p1) (p1)
#define arguments_BDK_GTI_WCX_WOR(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WCX_WOR(...) "GTI_WCX_WOR"


/**
 * NCB32b - gti_wr#_cidr0
 */
typedef union bdk_gti_wrx_cidr0 {
	uint32_t u;
	struct bdk_gti_wrx_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_cidr0_s         cn85xx; */
	/* struct bdk_gti_wrx_cidr0_s         cn88xx; */
} bdk_gti_wrx_cidr0_t;

static inline uint64_t BDK_GTI_WRX_CIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FF0ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_CIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_CIDR0(...) bdk_gti_wrx_cidr0_t
#define bustype_BDK_GTI_WRX_CIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_CIDR0(p1) (p1)
#define arguments_BDK_GTI_WRX_CIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_CIDR0(...) "GTI_WRX_CIDR0"


/**
 * NCB32b - gti_wr#_cidr1
 */
typedef union bdk_gti_wrx_cidr1 {
	uint32_t u;
	struct bdk_gti_wrx_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cclass                      : 4;  /**< RO - Component class. */
		uint32_t preamble                    : 4;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 4;
		uint32_t cclass                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_cidr1_s         cn85xx; */
	/* struct bdk_gti_wrx_cidr1_s         cn88xx; */
} bdk_gti_wrx_cidr1_t;

static inline uint64_t BDK_GTI_WRX_CIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FF4ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_CIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_CIDR1(...) bdk_gti_wrx_cidr1_t
#define bustype_BDK_GTI_WRX_CIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_CIDR1(p1) (p1)
#define arguments_BDK_GTI_WRX_CIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_CIDR1(...) "GTI_WRX_CIDR1"


/**
 * NCB32b - gti_wr#_cidr2
 */
typedef union bdk_gti_wrx_cidr2 {
	uint32_t u;
	struct bdk_gti_wrx_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_cidr2_s         cn85xx; */
	/* struct bdk_gti_wrx_cidr2_s         cn88xx; */
} bdk_gti_wrx_cidr2_t;

static inline uint64_t BDK_GTI_WRX_CIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FF8ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_CIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_CIDR2(...) bdk_gti_wrx_cidr2_t
#define bustype_BDK_GTI_WRX_CIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_CIDR2(p1) (p1)
#define arguments_BDK_GTI_WRX_CIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_CIDR2(...) "GTI_WRX_CIDR2"


/**
 * NCB32b - gti_wr#_cidr3
 */
typedef union bdk_gti_wrx_cidr3 {
	uint32_t u;
	struct bdk_gti_wrx_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_cidr3_s         cn85xx; */
	/* struct bdk_gti_wrx_cidr3_s         cn88xx; */
} bdk_gti_wrx_cidr3_t;

static inline uint64_t BDK_GTI_WRX_CIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_CIDR3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FFCull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_CIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_CIDR3(...) bdk_gti_wrx_cidr3_t
#define bustype_BDK_GTI_WRX_CIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_CIDR3(p1) (p1)
#define arguments_BDK_GTI_WRX_CIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_CIDR3(...) "GTI_WRX_CIDR3"


/**
 * NCB32b - gti_wr#_pidr0
 */
typedef union bdk_gti_wrx_pidr0 {
	uint32_t u;
	struct bdk_gti_wrx_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  Indicates PCC_PIDR_PARTNUM0_E::GTI_WR. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr0_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr0_s         cn88xx; */
} bdk_gti_wrx_pidr0_t;

static inline uint64_t BDK_GTI_WRX_PIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FE0ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR0(...) bdk_gti_wrx_pidr0_t
#define bustype_BDK_GTI_WRX_PIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR0(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR0(...) "GTI_WRX_PIDR0"


/**
 * NCB32b - gti_wr#_pidr1
 */
typedef union bdk_gti_wrx_pidr1 {
	uint32_t u;
	struct bdk_gti_wrx_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code <3:0>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr1_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr1_s         cn88xx; */
} bdk_gti_wrx_pidr1_t;

static inline uint64_t BDK_GTI_WRX_PIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FE4ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR1(...) bdk_gti_wrx_pidr1_t
#define bustype_BDK_GTI_WRX_PIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR1(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR1(...) "GTI_WRX_PIDR1"


/**
 * NCB32b - gti_wr#_pidr2
 */
typedef union bdk_gti_wrx_pidr2 {
	uint32_t u;
	struct bdk_gti_wrx_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - Architectural revision, as assigned by ARM. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< RO - JEP106 identification code <6:4>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr2_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr2_s         cn88xx; */
} bdk_gti_wrx_pidr2_t;

static inline uint64_t BDK_GTI_WRX_PIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FE8ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR2(...) bdk_gti_wrx_pidr2_t
#define bustype_BDK_GTI_WRX_PIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR2(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR2(...) "GTI_WRX_PIDR2"


/**
 * NCB32b - gti_wr#_pidr3
 */
typedef union bdk_gti_wrx_pidr3 {
	uint32_t u;
	struct bdk_gti_wrx_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr3_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr3_s         cn88xx; */
} bdk_gti_wrx_pidr3_t;

static inline uint64_t BDK_GTI_WRX_PIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FECull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR3(...) bdk_gti_wrx_pidr3_t
#define bustype_BDK_GTI_WRX_PIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR3(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR3(...) "GTI_WRX_PIDR3"


/**
 * NCB32b - gti_wr#_pidr4
 */
typedef union bdk_gti_wrx_pidr4 {
	uint32_t u;
	struct bdk_gti_wrx_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< RO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< RO - JEP106 continuation code. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr4_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr4_s         cn88xx; */
} bdk_gti_wrx_pidr4_t;

static inline uint64_t BDK_GTI_WRX_PIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR4(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FD0ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR4(...) bdk_gti_wrx_pidr4_t
#define bustype_BDK_GTI_WRX_PIDR4(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR4(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR4(...) "GTI_WRX_PIDR4"


/**
 * NCB32b - gti_wr#_pidr5
 */
typedef union bdk_gti_wrx_pidr5 {
	uint32_t u;
	struct bdk_gti_wrx_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr5_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr5_s         cn88xx; */
} bdk_gti_wrx_pidr5_t;

static inline uint64_t BDK_GTI_WRX_PIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR5(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FD4ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR5(...) bdk_gti_wrx_pidr5_t
#define bustype_BDK_GTI_WRX_PIDR5(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR5(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR5(...) "GTI_WRX_PIDR5"


/**
 * NCB32b - gti_wr#_pidr6
 */
typedef union bdk_gti_wrx_pidr6 {
	uint32_t u;
	struct bdk_gti_wrx_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr6_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr6_s         cn88xx; */
} bdk_gti_wrx_pidr6_t;

static inline uint64_t BDK_GTI_WRX_PIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR6(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FD8ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR6(...) bdk_gti_wrx_pidr6_t
#define bustype_BDK_GTI_WRX_PIDR6(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR6(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR6(...) "GTI_WRX_PIDR6"


/**
 * NCB32b - gti_wr#_pidr7
 */
typedef union bdk_gti_wrx_pidr7 {
	uint32_t u;
	struct bdk_gti_wrx_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_gti_wrx_pidr7_s         cn85xx; */
	/* struct bdk_gti_wrx_pidr7_s         cn88xx; */
} bdk_gti_wrx_pidr7_t;

static inline uint64_t BDK_GTI_WRX_PIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_PIDR7(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FDCull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_PIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_PIDR7(...) bdk_gti_wrx_pidr7_t
#define bustype_BDK_GTI_WRX_PIDR7(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_PIDR7(p1) (p1)
#define arguments_BDK_GTI_WRX_PIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_PIDR7(...) "GTI_WRX_PIDR7"


/**
 * NCB32b - gti_wr#_w_iidr
 *
 * GTI_WR(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WR(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wrx_w_iidr {
	uint32_t u;
	struct bdk_gti_wrx_w_iidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t productid                   : 8;  /**< RO - An implementation defined product number for the device.
                                                                 In CNXXXX, enumerated by PCC_PROD_E::CN88XX. */
		uint32_t variant                     : 4;  /**< RO - Variant field.
                                                                 Note in the SBSA this is defined as part of the product identification.
                                                                 In CNXXXX, the major pass number. */
		uint32_t arch                        : 4;  /**< RO - Architecture revision. 0x0 = SBSA 1.0 watchdogs. */
		uint32_t revision                    : 4;  /**< RO - Indicates the minor revision of the product.
                                                                 In CNXXXX, the minor pass number. */
		uint32_t implementer                 : 12; /**< RO - Indicates the implementer: 0x34C = Cavium. */
#else
		uint32_t implementer                 : 12;
		uint32_t revision                    : 4;
		uint32_t arch                        : 4;
		uint32_t variant                     : 4;
		uint32_t productid                   : 8;
#endif
	} s;
	/* struct bdk_gti_wrx_w_iidr_s        cn85xx; */
	/* struct bdk_gti_wrx_w_iidr_s        cn88xx; */
} bdk_gti_wrx_w_iidr_t;

static inline uint64_t BDK_GTI_WRX_W_IIDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_W_IIDR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090FCCull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_W_IIDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_W_IIDR(...) bdk_gti_wrx_w_iidr_t
#define bustype_BDK_GTI_WRX_W_IIDR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_W_IIDR(p1) (p1)
#define arguments_BDK_GTI_WRX_W_IIDR(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_W_IIDR(...) "GTI_WRX_W_IIDR"


/**
 * NCB32b - gti_wr#_wrr
 *
 * GTI_WR(0) accesses the secure watchdog and is accessable only by the
 * secure-world. GTI_WR(1) accesses the non-secure watchdog.
 */
typedef union bdk_gti_wrx_wrr {
	uint32_t u;
	struct bdk_gti_wrx_wrr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t zero                        : 32; /**< WO - Watchdog refresh. */
#else
		uint32_t zero                        : 32;
#endif
	} s;
	/* struct bdk_gti_wrx_wrr_s           cn85xx; */
	/* struct bdk_gti_wrx_wrr_s           cn88xx; */
} bdk_gti_wrx_wrr_t;

static inline uint64_t BDK_GTI_WRX_WRR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GTI_WRX_WRR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000844000090000ull + (param1 & 1) * 0x20000ull;
	csr_fatal("BDK_GTI_WRX_WRR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GTI_WRX_WRR(...) bdk_gti_wrx_wrr_t
#define bustype_BDK_GTI_WRX_WRR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_GTI_WRX_WRR(p1) (p1)
#define arguments_BDK_GTI_WRX_WRR(p1) (p1),-1,-1,-1
#define basename_BDK_GTI_WRX_WRR(...) "GTI_WRX_WRR"

#endif /* __BDK_CSRS_GTI__ */
