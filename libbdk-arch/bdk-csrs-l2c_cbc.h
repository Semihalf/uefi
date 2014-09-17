#ifndef __BDK_CSRS_L2C_CBC__
#define __BDK_CSRS_L2C_CBC__
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
 * Cavium L2C_CBC.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration L2C_CBC_INT_VEC_E
 *
 * L2C_CBC MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum l2c_cbc_int_vec_e {
	L2C_CBC_INT_VEC_E_INTS = 0x0,
	L2C_CBC_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - l2c_cbc#_bist_status
 */
typedef union bdk_l2c_cbcx_bist_status {
	uint64_t u;
	struct bdk_l2c_cbcx_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_37_63              : 27;
		uint64_t mibfl                       : 5;  /**< RO/H - BIST failure status for various MIB memories. ({XMD, IPM, IRM, MXD, MXN}) */
		uint64_t rsdfl                       : 32; /**< RO/H - BIST failure status for RSDQW0-31. */
#else
		uint64_t rsdfl                       : 32;
		uint64_t mibfl                       : 5;
		uint64_t reserved_37_63              : 27;
#endif
	} s;
	/* struct bdk_l2c_cbcx_bist_status_s  cn85xx; */
	/* struct bdk_l2c_cbcx_bist_status_s  cn88xx; */
	/* struct bdk_l2c_cbcx_bist_status_s  cn88xxp1; */
} bdk_l2c_cbcx_bist_status_t;

static inline uint64_t BDK_L2C_CBCX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0580A0000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_BIST_STATUS(...) bdk_l2c_cbcx_bist_status_t
#define bustype_BDK_L2C_CBCX_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_BIST_STATUS(p1) (p1)
#define arguments_BDK_L2C_CBCX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_BIST_STATUS(...) "L2C_CBCX_BIST_STATUS"


/**
 * RSL - l2c_cbc#_dll
 *
 * Register for DLL observability.
 *
 */
typedef union bdk_l2c_cbcx_dll {
	uint64_t u;
	struct bdk_l2c_cbcx_dll_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t max_dll_setting             : 12; /**< RO/H - Max reported DLL setting. */
		uint64_t min_dll_setting             : 12; /**< RO/H - Min reported DLL setting. */
		uint64_t pd_pos_rclk_refclk          : 1;  /**< RO/H - Phase detector output. */
		uint64_t pdl_rclk_refclk             : 1;  /**< RO/H - Phase detector output. */
		uint64_t pdr_rclk_refclk             : 1;  /**< RO/H - Phase detector output. */
		uint64_t reserved_32_32              : 1;
		uint64_t dly_elem_enable             : 16; /**< RO/H - Delay element enable. */
		uint64_t dll_setting                 : 12; /**< RO/H - DLL setting. */
		uint64_t reserved_1_3                : 3;
		uint64_t dll_lock                    : 1;  /**< RO/H - DLL locked. */
#else
		uint64_t dll_lock                    : 1;
		uint64_t reserved_1_3                : 3;
		uint64_t dll_setting                 : 12;
		uint64_t dly_elem_enable             : 16;
		uint64_t reserved_32_32              : 1;
		uint64_t pdr_rclk_refclk             : 1;
		uint64_t pdl_rclk_refclk             : 1;
		uint64_t pd_pos_rclk_refclk          : 1;
		uint64_t min_dll_setting             : 12;
		uint64_t max_dll_setting             : 12;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_l2c_cbcx_dll_s          cn85xx; */
	/* struct bdk_l2c_cbcx_dll_s          cn88xx; */
	/* struct bdk_l2c_cbcx_dll_s          cn88xxp1; */
} bdk_l2c_cbcx_dll_t;

static inline uint64_t BDK_L2C_CBCX_DLL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_DLL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058040000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_DLL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_DLL(...) bdk_l2c_cbcx_dll_t
#define bustype_BDK_L2C_CBCX_DLL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_DLL(p1) (p1)
#define arguments_BDK_L2C_CBCX_DLL(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_DLL(...) "L2C_CBCX_DLL"


/**
 * RSL - l2c_cbc#_int_ena_w1c
 */
typedef union bdk_l2c_cbcx_int_ena_w1c {
	uint64_t u;
	struct bdk_l2c_cbcx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t iowrdisoci                  : 1;  /**< R/W1C/H - Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
		uint64_t iorddisoci                  : 1;  /**< R/W1C/H - Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
		uint64_t mibdbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t mibsbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t reserved_2_3                : 2;
		uint64_t rsddbe                      : 1;  /**< R/W1C/H - RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
		uint64_t rsdsbe                      : 1;  /**< R/W1C/H - RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else
		uint64_t rsdsbe                      : 1;
		uint64_t rsddbe                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t mibsbe                      : 1;
		uint64_t mibdbe                      : 1;
		uint64_t iorddisoci                  : 1;
		uint64_t iowrdisoci                  : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_l2c_cbcx_int_ena_w1c_s  cn85xx; */
	/* struct bdk_l2c_cbcx_int_ena_w1c_s  cn88xx; */
	/* struct bdk_l2c_cbcx_int_ena_w1c_s  cn88xxp1; */
} bdk_l2c_cbcx_int_ena_w1c_t;

static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058060020ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_INT_ENA_W1C(...) bdk_l2c_cbcx_int_ena_w1c_t
#define bustype_BDK_L2C_CBCX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_L2C_CBCX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_INT_ENA_W1C(...) "L2C_CBCX_INT_ENA_W1C"


/**
 * RSL - l2c_cbc#_int_ena_w1s
 */
typedef union bdk_l2c_cbcx_int_ena_w1s {
	uint64_t u;
	struct bdk_l2c_cbcx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t iowrdisoci                  : 1;  /**< R/W1C/H - Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
		uint64_t iorddisoci                  : 1;  /**< R/W1C/H - Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
		uint64_t mibdbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t mibsbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t reserved_2_3                : 2;
		uint64_t rsddbe                      : 1;  /**< R/W1C/H - RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
		uint64_t rsdsbe                      : 1;  /**< R/W1C/H - RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else
		uint64_t rsdsbe                      : 1;
		uint64_t rsddbe                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t mibsbe                      : 1;
		uint64_t mibdbe                      : 1;
		uint64_t iorddisoci                  : 1;
		uint64_t iowrdisoci                  : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_l2c_cbcx_int_ena_w1s_s  cn85xx; */
	/* struct bdk_l2c_cbcx_int_ena_w1s_s  cn88xx; */
	/* struct bdk_l2c_cbcx_int_ena_w1s_s  cn88xxp1; */
} bdk_l2c_cbcx_int_ena_w1s_t;

static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058060028ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_INT_ENA_W1S(...) bdk_l2c_cbcx_int_ena_w1s_t
#define bustype_BDK_L2C_CBCX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_L2C_CBCX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_INT_ENA_W1S(...) "L2C_CBCX_INT_ENA_W1S"


/**
 * RSL - l2c_cbc#_int_w1c
 *
 * This register is for CBC-based interrupts.
 *
 */
typedef union bdk_l2c_cbcx_int_w1c {
	uint64_t u;
	struct bdk_l2c_cbcx_int_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t iowrdisoci                  : 1;  /**< R/W1C/H - Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
		uint64_t iorddisoci                  : 1;  /**< R/W1C/H - Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
		uint64_t mibdbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t mibsbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t reserved_2_3                : 2;
		uint64_t rsddbe                      : 1;  /**< R/W1C/H - RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
		uint64_t rsdsbe                      : 1;  /**< R/W1C/H - RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else
		uint64_t rsdsbe                      : 1;
		uint64_t rsddbe                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t mibsbe                      : 1;
		uint64_t mibdbe                      : 1;
		uint64_t iorddisoci                  : 1;
		uint64_t iowrdisoci                  : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_l2c_cbcx_int_w1c_s      cn85xx; */
	/* struct bdk_l2c_cbcx_int_w1c_s      cn88xx; */
	/* struct bdk_l2c_cbcx_int_w1c_s      cn88xxp1; */
} bdk_l2c_cbcx_int_w1c_t;

static inline uint64_t BDK_L2C_CBCX_INT_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_W1C(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058060000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_INT_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_INT_W1C(...) bdk_l2c_cbcx_int_w1c_t
#define bustype_BDK_L2C_CBCX_INT_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_INT_W1C(p1) (p1)
#define arguments_BDK_L2C_CBCX_INT_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_INT_W1C(...) "L2C_CBCX_INT_W1C"


/**
 * RSL - l2c_cbc#_int_w1s
 */
typedef union bdk_l2c_cbcx_int_w1s {
	uint64_t u;
	struct bdk_l2c_cbcx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t iowrdisoci                  : 1;  /**< R/W1C/H - Illegal I/O write operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBST, IOBSTP, IOBADDR, IASET, IACLR, IAADD, IASWP, IACAS, and LMTST XMC
                                                                 commands. */
		uint64_t iorddisoci                  : 1;  /**< R/W1C/H - Illegal I/O read operation to a remote node with L2C_OCI_CTL[ENAOCI][node]
                                                                 clear. See L2C_CBC()_IODISOCIERR for logged information. This interrupt applies
                                                                 to IOBLD, IASET, IACLR, IAADD, IASWP, and IACAS XMC commands. */
		uint64_t mibdbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t mibsbe                      : 1;  /**< R/W1C/H - MIB double-bit error occurred. See L2C_CBC()_MIBERR for logged information. */
		uint64_t reserved_2_3                : 2;
		uint64_t rsddbe                      : 1;  /**< R/W1C/H - RSD double-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
		uint64_t rsdsbe                      : 1;  /**< R/W1C/H - RSD single-bit error occurred. See L2C_CBC()_RSDERR for logged information. */
#else
		uint64_t rsdsbe                      : 1;
		uint64_t rsddbe                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t mibsbe                      : 1;
		uint64_t mibdbe                      : 1;
		uint64_t iorddisoci                  : 1;
		uint64_t iowrdisoci                  : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_l2c_cbcx_int_w1s_s      cn85xx; */
	/* struct bdk_l2c_cbcx_int_w1s_s      cn88xx; */
	/* struct bdk_l2c_cbcx_int_w1s_s      cn88xxp1; */
} bdk_l2c_cbcx_int_w1s_t;

static inline uint64_t BDK_L2C_CBCX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058060008ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_INT_W1S(...) bdk_l2c_cbcx_int_w1s_t
#define bustype_BDK_L2C_CBCX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_INT_W1S(p1) (p1)
#define arguments_BDK_L2C_CBCX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_INT_W1S(...) "L2C_CBCX_INT_W1S"


/**
 * RSL - l2c_cbc#_inv#_pfc
 */
typedef union bdk_l2c_cbcx_invx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_invx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_invx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_invx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_invx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_invx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_INVX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_INVX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E058000020ull + (param1 & 3) * 0x1000000ull + (param2 & 1) * 0x40ull;
	csr_fatal("BDK_L2C_CBCX_INVX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_INVX_PFC(...) bdk_l2c_cbcx_invx_pfc_t
#define bustype_BDK_L2C_CBCX_INVX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_INVX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_INVX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_INVX_PFC(...) "L2C_CBCX_INVX_PFC"


/**
 * RSL - l2c_cbc#_ioc#_pfc
 */
typedef union bdk_l2c_cbcx_iocx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_iocx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_iocx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_iocx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_iocx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_iocx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_IOCX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_IOCX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E058000028ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_IOCX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_IOCX_PFC(...) bdk_l2c_cbcx_iocx_pfc_t
#define bustype_BDK_L2C_CBCX_IOCX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_IOCX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_IOCX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_IOCX_PFC(...) "L2C_CBCX_IOCX_PFC"


/**
 * RSL - l2c_cbc#_iocerr
 *
 * Reserved.
 *
 */
typedef union bdk_l2c_cbcx_iocerr {
	uint64_t u;
	struct bdk_l2c_cbcx_iocerr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_iocerr_s       cn85xx; */
	/* struct bdk_l2c_cbcx_iocerr_s       cn88xx; */
	/* struct bdk_l2c_cbcx_iocerr_s       cn88xxp1; */
} bdk_l2c_cbcx_iocerr_t;

static inline uint64_t BDK_L2C_CBCX_IOCERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_IOCERR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058080010ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_IOCERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_IOCERR(...) bdk_l2c_cbcx_iocerr_t
#define bustype_BDK_L2C_CBCX_IOCERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_IOCERR(p1) (p1)
#define arguments_BDK_L2C_CBCX_IOCERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_IOCERR(...) "L2C_CBCX_IOCERR"


/**
 * RSL - l2c_cbc#_iodisocierr
 *
 * This register records error information associated with IORDDISOCI/IOWRDISOCI interrupts.
 * IOWRDISOCI events take priority over previously captured IORDDISOCI events. Of the available
 * I/O transactions, some commands will either set IORDDISOCI, set IOWRDISOCI, or set both
 * IORDDISOCI and IOWRDISOCI. See L2C_CBC()_INT_W1C for information about which I/O
 * transactions
 * may result in IORDDISOCI/IOWRDISOCI interrupts.
 */
typedef union bdk_l2c_cbcx_iodisocierr {
	uint64_t u;
	struct bdk_l2c_cbcx_iodisocierr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t iorddisoci                  : 1;  /**< RO/H - Logged information is for a IORDDISOCI error. */
		uint64_t iowrdisoci                  : 1;  /**< RO/H - Logged information is for a IOWRDISOCI error. */
		uint64_t reserved_59_61              : 3;
		uint64_t cmd                         : 7;  /**< RO/H - Encoding of XMC command.  INTERNAL: Enumerated by XMC_CMD_E. */
		uint64_t ppvid                       : 6;  /**< RO/H - CMB source PPVID. */
		uint64_t node                        : 2;  /**< RO/H - Destination node ID. */
		uint64_t did                         : 8;  /**< RO/H - Destination device ID. */
		uint64_t addr                        : 36; /**< RO/H - I/O address. */
#else
		uint64_t addr                        : 36;
		uint64_t did                         : 8;
		uint64_t node                        : 2;
		uint64_t ppvid                       : 6;
		uint64_t cmd                         : 7;
		uint64_t reserved_59_61              : 3;
		uint64_t iowrdisoci                  : 1;
		uint64_t iorddisoci                  : 1;
#endif
	} s;
	/* struct bdk_l2c_cbcx_iodisocierr_s  cn85xx; */
	/* struct bdk_l2c_cbcx_iodisocierr_s  cn88xx; */
	/* struct bdk_l2c_cbcx_iodisocierr_s  cn88xxp1; */
} bdk_l2c_cbcx_iodisocierr_t;

static inline uint64_t BDK_L2C_CBCX_IODISOCIERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_IODISOCIERR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058080008ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_IODISOCIERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_IODISOCIERR(...) bdk_l2c_cbcx_iodisocierr_t
#define bustype_BDK_L2C_CBCX_IODISOCIERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_IODISOCIERR(p1) (p1)
#define arguments_BDK_L2C_CBCX_IODISOCIERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_IODISOCIERR(...) "L2C_CBCX_IODISOCIERR"


/**
 * RSL - l2c_cbc#_ior#_pfc
 */
typedef union bdk_l2c_cbcx_iorx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_iorx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_iorx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_iorx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_iorx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_iorx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_IORX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_IORX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E058000030ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_IORX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_IORX_PFC(...) bdk_l2c_cbcx_iorx_pfc_t
#define bustype_BDK_L2C_CBCX_IORX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_IORX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_IORX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_IORX_PFC(...) "L2C_CBCX_IORX_PFC"


/**
 * RSL - l2c_cbc#_miberr
 *
 * This register records error information for all CBC MIB errors. An error locks the INDEX, and
 * SYN fields and set the bit corresponding to the error received. MIBDBE errors take priority
 * and overwrite an earlier logged MIBSBE error. Only one of MIBSBE/MIBDBE is set at any given
 * time and serves to document which error the INDEX/SYN is associated with. The syndrome is
 * recorded for DBE errors, though the utility of the value is not clear.
 */
typedef union bdk_l2c_cbcx_miberr {
	uint64_t u;
	struct bdk_l2c_cbcx_miberr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mibdbe                      : 1;  /**< RO/H - INDEX/SYN corresponds to a double-bit MIB ECC error. */
		uint64_t mibsbe                      : 1;  /**< RO/H - INDEX/SYN corresponds to a single-bit MIB ECC error. */
		uint64_t reserved_40_61              : 22;
		uint64_t syn                         : 8;  /**< RO/H - Error syndrome. */
		uint64_t reserved_3_31               : 29;
		uint64_t memid                       : 2;  /**< RO/H - Indicates the memory that had the error.
                                                                 0x0 = Error from MXB_VC_MRN, MXB_VC_MFN, MXB_VC_MPN VCs.
                                                                 0x1 = Error from MXB_VC_MRD, MXB_VC_MPD VCs.
                                                                 0x2 = Error from MXB_VC_IRM VC.
                                                                 0x3 = Error from MXB_VC_IPM VC. */
		uint64_t mibnum                      : 1;  /**< RO/H - Indicates the MIB bus that had the error. */
#else
		uint64_t mibnum                      : 1;
		uint64_t memid                       : 2;
		uint64_t reserved_3_31               : 29;
		uint64_t syn                         : 8;
		uint64_t reserved_40_61              : 22;
		uint64_t mibsbe                      : 1;
		uint64_t mibdbe                      : 1;
#endif
	} s;
	/* struct bdk_l2c_cbcx_miberr_s       cn85xx; */
	/* struct bdk_l2c_cbcx_miberr_s       cn88xx; */
	/* struct bdk_l2c_cbcx_miberr_s       cn88xxp1; */
} bdk_l2c_cbcx_miberr_t;

static inline uint64_t BDK_L2C_CBCX_MIBERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MIBERR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058080020ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_MIBERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_MIBERR(...) bdk_l2c_cbcx_miberr_t
#define bustype_BDK_L2C_CBCX_MIBERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_MIBERR(p1) (p1)
#define arguments_BDK_L2C_CBCX_MIBERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_MIBERR(...) "L2C_CBCX_MIBERR"


/**
 * RSL - l2c_cbc#_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the L2C_CBC_INT_VEC_E
 * enumeration.
 */
typedef union bdk_l2c_cbcx_msix_pbax {
	uint64_t u;
	struct bdk_l2c_cbcx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO - Pending message for the associated L2C_CBC()_MSIX_VEC()_CTL, enumerated by
                                                                 L2C_CBC_INT_VEC_E. Bits
                                                                 that have no associated L2C_CBC_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_msix_pbax_s    cn85xx; */
	/* struct bdk_l2c_cbcx_msix_pbax_s    cn88xx; */
	/* struct bdk_l2c_cbcx_msix_pbax_s    cn88xxp1; */
} bdk_l2c_cbcx_msix_pbax_t;

static inline uint64_t BDK_L2C_CBCX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E058FF0000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_MSIX_PBAX(...) bdk_l2c_cbcx_msix_pbax_t
#define bustype_BDK_L2C_CBCX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_MSIX_PBAX(...) "L2C_CBCX_MSIX_PBAX"


/**
 * RSL - l2c_cbc#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the L2C_CBC_INT_VEC_E enumeration.
 *
 */
typedef union bdk_l2c_cbcx_msix_vecx_addr {
	uint64_t u;
	struct bdk_l2c_cbcx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's L2C_CBC()_MSIX_VEC()_ADDR, L2C_CBC()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of L2C_CBC()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_L2C_CBC_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_l2c_cbcx_msix_vecx_addr_s cn85xx; */
	/* struct bdk_l2c_cbcx_msix_vecx_addr_s cn88xx; */
	/* struct bdk_l2c_cbcx_msix_vecx_addr_s cn88xxp1; */
} bdk_l2c_cbcx_msix_vecx_addr_t;

static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E058F00000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_MSIX_VECX_ADDR(...) bdk_l2c_cbcx_msix_vecx_addr_t
#define bustype_BDK_L2C_CBCX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_MSIX_VECX_ADDR(...) "L2C_CBCX_MSIX_VECX_ADDR"


/**
 * RSL - l2c_cbc#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the L2C_CBC_INT_VEC_E enumeration.
 *
 */
typedef union bdk_l2c_cbcx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_l2c_cbcx_msix_vecx_ctl_s {
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
	/* struct bdk_l2c_cbcx_msix_vecx_ctl_s cn85xx; */
	/* struct bdk_l2c_cbcx_msix_vecx_ctl_s cn88xx; */
	/* struct bdk_l2c_cbcx_msix_vecx_ctl_s cn88xxp1; */
} bdk_l2c_cbcx_msix_vecx_ctl_t;

static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E058F00008ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_MSIX_VECX_CTL(...) bdk_l2c_cbcx_msix_vecx_ctl_t
#define bustype_BDK_L2C_CBCX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_MSIX_VECX_CTL(...) "L2C_CBCX_MSIX_VECX_CTL"


/**
 * RSL - l2c_cbc#_rsc#_pfc
 */
typedef union bdk_l2c_cbcx_rscx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_rscx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_rscx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_rscx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_rscx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_rscx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_RSCX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_RSCX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 2)))
		return 0x000087E058000010ull + (param1 & 3) * 0x1000000ull + (param2 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_CBCX_RSCX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_RSCX_PFC(...) bdk_l2c_cbcx_rscx_pfc_t
#define bustype_BDK_L2C_CBCX_RSCX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_RSCX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_RSCX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_RSCX_PFC(...) "L2C_CBCX_RSCX_PFC"


/**
 * RSL - l2c_cbc#_rsd#_pfc
 */
typedef union bdk_l2c_cbcx_rsdx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_rsdx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_rsdx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_rsdx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_rsdx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_rsdx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_RSDX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_RSDX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 2)))
		return 0x000087E058000018ull + (param1 & 3) * 0x1000000ull + (param2 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_CBCX_RSDX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_RSDX_PFC(...) bdk_l2c_cbcx_rsdx_pfc_t
#define bustype_BDK_L2C_CBCX_RSDX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_RSDX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_RSDX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_RSDX_PFC(...) "L2C_CBCX_RSDX_PFC"


/**
 * RSL - l2c_cbc#_rsderr
 *
 * This register records error information for all CBC RSD errors.
 * An error locks the INDEX, and SYN fields and set the bit corresponding to the error received.
 * RSDDBE errors take priority and overwrite an earlier logged RSDSBE error. Only one of
 * RSDSBE/RSDDBE is set at any given time and serves to document which error the INDEX/SYN is
 * associated with.
 * The syndrome is recorded for DBE errors, though the utility of the value is not clear.
 */
typedef union bdk_l2c_cbcx_rsderr {
	uint64_t u;
	struct bdk_l2c_cbcx_rsderr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rsddbe                      : 1;  /**< RO/H - INDEX/SYN corresponds to a double-bit RSD ECC error */
		uint64_t rsdsbe                      : 1;  /**< RO/H - INDEX/SYN corresponds to a single-bit RSD ECC error */
		uint64_t reserved_40_61              : 22;
		uint64_t syn                         : 8;  /**< RO/H - Error syndrome. */
		uint64_t reserved_9_31               : 23;
		uint64_t tadnum                      : 3;  /**< RO/H - Indicates the TAD FIFO containing the error. */
		uint64_t qwnum                       : 2;  /**< RO/H - Indicates the QW containing the error. */
		uint64_t rsdnum                      : 4;  /**< RO/H - Indicates the RSD that had the error. */
#else
		uint64_t rsdnum                      : 4;
		uint64_t qwnum                       : 2;
		uint64_t tadnum                      : 3;
		uint64_t reserved_9_31               : 23;
		uint64_t syn                         : 8;
		uint64_t reserved_40_61              : 22;
		uint64_t rsdsbe                      : 1;
		uint64_t rsddbe                      : 1;
#endif
	} s;
	/* struct bdk_l2c_cbcx_rsderr_s       cn85xx; */
	/* struct bdk_l2c_cbcx_rsderr_s       cn88xx; */
	/* struct bdk_l2c_cbcx_rsderr_s       cn88xxp1; */
} bdk_l2c_cbcx_rsderr_t;

static inline uint64_t BDK_L2C_CBCX_RSDERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_RSDERR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E058080018ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_RSDERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_RSDERR(...) bdk_l2c_cbcx_rsderr_t
#define bustype_BDK_L2C_CBCX_RSDERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_RSDERR(p1) (p1)
#define arguments_BDK_L2C_CBCX_RSDERR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_RSDERR(...) "L2C_CBCX_RSDERR"


/**
 * RSL - l2c_cbc#_scratch
 *
 * These registers are only reset by hardware during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_l2c_cbcx_scratch {
	uint64_t u;
	struct bdk_l2c_cbcx_scratch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t scratch                     : 7;  /**< R/W - General purpose scratch register. */
		uint64_t invdly                      : 1;  /**< R/W - Delays all invalidates for 9 cycles after a broadcast invalidate. */
#else
		uint64_t invdly                      : 1;
		uint64_t scratch                     : 7;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_l2c_cbcx_scratch_s      cn85xx; */
	/* struct bdk_l2c_cbcx_scratch_s      cn88xx; */
	/* struct bdk_l2c_cbcx_scratch_s      cn88xxp1; */
} bdk_l2c_cbcx_scratch_t;

static inline uint64_t BDK_L2C_CBCX_SCRATCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_SCRATCH(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0580D0000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_SCRATCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_SCRATCH(...) bdk_l2c_cbcx_scratch_t
#define bustype_BDK_L2C_CBCX_SCRATCH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_SCRATCH(p1) (p1)
#define arguments_BDK_L2C_CBCX_SCRATCH(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_SCRATCH(...) "L2C_CBCX_SCRATCH"


/**
 * RSL - l2c_cbc#_xmc#_pfc
 */
typedef union bdk_l2c_cbcx_xmcx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_xmcx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_xmcx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_xmcx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_xmcx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_xmcx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_XMCX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_XMCX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 2)))
		return 0x000087E058000000ull + (param1 & 3) * 0x1000000ull + (param2 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_CBCX_XMCX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_XMCX_PFC(...) bdk_l2c_cbcx_xmcx_pfc_t
#define bustype_BDK_L2C_CBCX_XMCX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_XMCX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_XMCX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_XMCX_PFC(...) "L2C_CBCX_XMCX_PFC"


/**
 * RSL - l2c_cbc#_xmc_cmd
 *
 * Note the following:
 *
 * The ADD bus command chosen must not be a IOB-destined command or operation is UNDEFINED.
 *
 * The ADD bus command will have SID forced to IOB, DID forced to L2C, no virtualization checks
 * performed (always pass), and xmdmsk forced to 0. Note that this implies that commands that
 * REQUIRE a STORE cycle (STP, STC, SAA, FAA, FAS) should not be used or the results are
 * unpredictable. The sid = IOB means that the way partitioning used for the command is
 * L2C_WPAR_IOB(). L2C_QOS_PP() are not used for these commands.
 *
 * Any FILL responses generated by the ADD bus command are ignored. Generated STINs, however,
 * will correctly invalidate the required cores.
 *
 * Any L2D read generated by the ADD bus command records the syndrome information in
 * L2C_TAD(0..3)_ECC0/1. If ECC is disabled prior to the CSR write, this provides the ability to
 * read the ECC bits directly. If ECC is not disabled, this should log zeros (assuming no ECC
 * errors were found in the block).
 *
 * A write that arrives while the INUSE bit is set will block until the INUSE bit clears. This
 * gives software two options when needing to issue a stream of write operations to L2C_XMC_CMD:
 * polling on the INUSE bit, or allowing hardware to handle the interlock -- at the expense of
 * locking up the RSL bus for potentially tens of cycles at a time while waiting for an available
 * LFB/VAB entry. Note that when the INUSE bit clears, the only ordering it implies is that
 * software can send another ADD bus command. Subsequent commands may complete out of order
 * relative to earlier commands.
 *
 * The address written to L2C_XMC_CMD is a physical address. L2C performs index
 * aliasing (if enabled) on the written address and uses that for the command. This
 * index-aliased address is what is returned on a read of the L2C_XMC_CMD register.
 */
typedef union bdk_l2c_cbcx_xmc_cmd {
	uint64_t u;
	struct bdk_l2c_cbcx_xmc_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t inuse                       : 1;  /**< RO/H - Set to 1 by hardware upon receiving a write; cleared when command has issued (not
                                                                 necessarily completed, but ordered relative to other traffic) and hardware can accept
                                                                 another command. */
		uint64_t cmd                         : 7;  /**< R/W - Command to use for simulated ADD bus request. A new request can be accepted. */
		uint64_t reserved_49_55              : 7;
		uint64_t nonsec                      : 1;  /**< R/W - Nonsecure bit to use for simulated ADD bus request. */
		uint64_t reserved_47_47              : 1;
		uint64_t qos                         : 3;  /**< R/W - QOS level to use for simulated ADD bus request. */
		uint64_t reserved_42_43              : 2;
		uint64_t node                        : 2;  /**< R/W - CCPI node to use for simulated ADD bus request. */
		uint64_t addr                        : 40; /**< R/W - Address to use for simulated ADD bus request. (The address written to L2C_XMC_CMD is a
                                                                 physical address. L2C performs index aliasing (if enabled) on the written
                                                                 address and uses that for the command. This index-aliased address is what is
                                                                 returned on a read of L2C_XMC_CMD.) */
#else
		uint64_t addr                        : 40;
		uint64_t node                        : 2;
		uint64_t reserved_42_43              : 2;
		uint64_t qos                         : 3;
		uint64_t reserved_47_47              : 1;
		uint64_t nonsec                      : 1;
		uint64_t reserved_49_55              : 7;
		uint64_t cmd                         : 7;
		uint64_t inuse                       : 1;
#endif
	} s;
	/* struct bdk_l2c_cbcx_xmc_cmd_s      cn85xx; */
	/* struct bdk_l2c_cbcx_xmc_cmd_s      cn88xx; */
	/* struct bdk_l2c_cbcx_xmc_cmd_s      cn88xxp1; */
} bdk_l2c_cbcx_xmc_cmd_t;

static inline uint64_t BDK_L2C_CBCX_XMC_CMD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_XMC_CMD(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0580C0000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_L2C_CBCX_XMC_CMD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_XMC_CMD(...) bdk_l2c_cbcx_xmc_cmd_t
#define bustype_BDK_L2C_CBCX_XMC_CMD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_XMC_CMD(p1) (p1)
#define arguments_BDK_L2C_CBCX_XMC_CMD(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_CBCX_XMC_CMD(...) "L2C_CBCX_XMC_CMD"


/**
 * RSL - l2c_cbc#_xmd#_pfc
 */
typedef union bdk_l2c_cbcx_xmdx_pfc {
	uint64_t u;
	struct bdk_l2c_cbcx_xmdx_pfc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W/H - Current counter value. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_l2c_cbcx_xmdx_pfc_s     cn85xx; */
	/* struct bdk_l2c_cbcx_xmdx_pfc_s     cn88xx; */
	/* struct bdk_l2c_cbcx_xmdx_pfc_s     cn88xxp1; */
} bdk_l2c_cbcx_xmdx_pfc_t;

static inline uint64_t BDK_L2C_CBCX_XMDX_PFC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CBCX_XMDX_PFC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 2)))
		return 0x000087E058000008ull + (param1 & 3) * 0x1000000ull + (param2 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_CBCX_XMDX_PFC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_L2C_CBCX_XMDX_PFC(...) bdk_l2c_cbcx_xmdx_pfc_t
#define bustype_BDK_L2C_CBCX_XMDX_PFC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CBCX_XMDX_PFC(p1,p2) (p1)
#define arguments_BDK_L2C_CBCX_XMDX_PFC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_L2C_CBCX_XMDX_PFC(...) "L2C_CBCX_XMDX_PFC"

#endif /* __BDK_CSRS_L2C_CBC__ */
