#ifndef __BDK_CSRS_SATA__
#define __BDK_CSRS_SATA__
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
 * Cavium SATA.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration SATA_INT_VEC_E
 *
 * SATA MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum sata_int_vec_e {
	SATA_INT_VEC_E_UAHC_INTRQ_IP = 0x0,
	SATA_INT_VEC_E_UAHC_INTRQ_IP_CLEAR = 0x1,
	SATA_INT_VEC_E_UAHC_PME_REQ_IP = 0x2,
	SATA_INT_VEC_E_UAHC_PME_REQ_IP_CLEAR = 0x3,
	SATA_INT_VEC_E_UCTL_INTSTAT = 0x4,
	SATA_INT_VEC_E_ENUM_LAST = 0x5,
};

/**
 * Enumeration SATA_UCTL_DMA_READ_CMD_E
 *
 * SATA UCTL DMA Read Command Enumeration
 * Enumerates NCB inbound command selections for DMA read operations.
 */
enum sata_uctl_dma_read_cmd_e {
	SATA_UCTL_DMA_READ_CMD_E_LDI = 0x0,
	SATA_UCTL_DMA_READ_CMD_E_LDT = 0x1,
	SATA_UCTL_DMA_READ_CMD_E_LDY = 0x2,
	SATA_UCTL_DMA_READ_CMD_E_ENUM_LAST = 0x3,
};

/**
 * Enumeration SATA_UCTL_DMA_WRITE_CMD_E
 *
 * SATA UCTL DMA Write Command Enumeration
 * Enumerate NCB inbound command selections for DMA writes.
 */
enum sata_uctl_dma_write_cmd_e {
	SATA_UCTL_DMA_WRITE_CMD_E_RSTP = 0x1,
	SATA_UCTL_DMA_WRITE_CMD_E_STP = 0x0,
	SATA_UCTL_DMA_WRITE_CMD_E_ENUM_LAST = 0x2,
};

/**
 * Enumeration SATA_UCTL_ECC_ERR_SOURCE_E
 *
 * SATA UCTL ECC Error Source Enumeration
 * Enumerate sources of ECC error log information.
 */
enum sata_uctl_ecc_err_source_e {
	SATA_UCTL_ECC_ERR_SOURCE_E_FB_DBE = 0xf,
	SATA_UCTL_ECC_ERR_SOURCE_E_FB_SBE = 0x7,
	SATA_UCTL_ECC_ERR_SOURCE_E_NONE = 0x0,
	SATA_UCTL_ECC_ERR_SOURCE_E_RX_DBE = 0xd,
	SATA_UCTL_ECC_ERR_SOURCE_E_RX_SBE = 0x5,
	SATA_UCTL_ECC_ERR_SOURCE_E_TX_DBE = 0xe,
	SATA_UCTL_ECC_ERR_SOURCE_E_TX_SBE = 0x6,
	SATA_UCTL_ECC_ERR_SOURCE_E_XM_R_DBE = 0xa,
	SATA_UCTL_ECC_ERR_SOURCE_E_XM_R_SBE = 0x2,
	SATA_UCTL_ECC_ERR_SOURCE_E_XM_W_DBE = 0x9,
	SATA_UCTL_ECC_ERR_SOURCE_E_XM_W_SBE = 0x1,
	SATA_UCTL_ECC_ERR_SOURCE_E_ENUM_LAST = 0x10,
};

/**
 * Enumeration SATA_UCTL_XM_BAD_DMA_TYPE_E
 *
 * SATA UCTL XM Bad DMA Type Enumeration
 * Enumerates the type of DMA error seen.
 */
enum sata_uctl_xm_bad_dma_type_e {
	SATA_UCTL_XM_BAD_DMA_TYPE_E_ADDR_OOB = 0x1,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_LEN_GT_8 = 0x2,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_BYTE = 0x3,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_HALFWORD = 0x4,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_QWORD = 0x6,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_WORD = 0x5,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_NONE = 0x0,
	SATA_UCTL_XM_BAD_DMA_TYPE_E_ENUM_LAST = 0x7,
};



/**
 * NCB - sata#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the SATA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_satax_msix_pbax {
	uint64_t u;
	struct bdk_satax_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated SATA_MSIX_VEC()_CTL, enumerated by SATA_INT_VEC_E.
                                                                 Bits that have no associated SATA_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_satax_msix_pbax_s       cn88xx; */
	/* struct bdk_satax_msix_pbax_s       cn88xxp1; */
} bdk_satax_msix_pbax_t;

static inline uint64_t BDK_SATAX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 15)) && ((param2 == 0)))
		return 0x00008100002F0000ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_MSIX_PBAX(...) bdk_satax_msix_pbax_t
#define bustype_BDK_SATAX_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_SATAX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SATAX_MSIX_PBAX(...) "SATAX_MSIX_PBAX"


/**
 * NCB - sata#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the SATA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_satax_msix_vecx_addr {
	uint64_t u;
	struct bdk_satax_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SATA()_MSIX_VEC()_ADDR, SATA()_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of SATA()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SATA(0..15)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_satax_msix_vecx_addr_s  cn88xx; */
	/* struct bdk_satax_msix_vecx_addr_s  cn88xxp1; */
} bdk_satax_msix_vecx_addr_t;

static inline uint64_t BDK_SATAX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 15)) && ((param2 <= 4)))
		return 0x0000810000200000ull + (param1 & 15) * 0x1000000000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_SATAX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_MSIX_VECX_ADDR(...) bdk_satax_msix_vecx_addr_t
#define bustype_BDK_SATAX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_SATAX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SATAX_MSIX_VECX_ADDR(...) "SATAX_MSIX_VECX_ADDR"


/**
 * NCB - sata#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the SATA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_satax_msix_vecx_ctl {
	uint64_t u;
	struct bdk_satax_msix_vecx_ctl_s {
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
	/* struct bdk_satax_msix_vecx_ctl_s   cn88xx; */
	/* struct bdk_satax_msix_vecx_ctl_s   cn88xxp1; */
} bdk_satax_msix_vecx_ctl_t;

static inline uint64_t BDK_SATAX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 15)) && ((param2 <= 4)))
		return 0x0000810000200008ull + (param1 & 15) * 0x1000000000ull + (param2 & 7) * 0x10ull;
	csr_fatal("BDK_SATAX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_MSIX_VECX_CTL(...) bdk_satax_msix_vecx_ctl_t
#define bustype_BDK_SATAX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_SATAX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SATAX_MSIX_VECX_CTL(...) "SATAX_MSIX_VECX_CTL"


/**
 * NCB32b - sata#_uahc_gbl_bistafr
 *
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * This register contains the pattern definition (bits 23:16 of the
 * first DWORD) and the data pattern (bits 7:0 of the second DWORD)
 * fields of the received BIST activate FIS.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union bdk_satax_uahc_gbl_bistafr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_bistafr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t ncp                         : 8;  /**< RO - Bits 7:0 of the second DWORD of BIST activate FIS.
                                                                 0xF1 = low transition density pattern (LTDP).
                                                                 0xB5 = high transition density pattern (HTDP).
                                                                 0xAB = low frequency spectral component pattern (LFSCP).
                                                                 0x7F = simultaneous switching outputs pattern (SSOP).
                                                                 0x78 = mid frequency test pattern (MFTP).
                                                                 0x4A = high frequency test pattern (HFTP).
                                                                 0x7E = low frequency test pattern (LFTP).
                                                                 else = lone bit pattern (LBP). */
		uint32_t pd                          : 8;  /**< RO - Bits 23:16 of the first DWORD of the BIST activate FIS. Only the following values are
                                                                 supported:
                                                                 0x10 = Far-end retimed.
                                                                 0xC0 = Far-end transmit only.
                                                                 0xE0 = Far-end transmit only with scrambler bypassed. */
#else
		uint32_t pd                          : 8;
		uint32_t ncp                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_bistafr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_bistafr_s cn88xxp1; */
} bdk_satax_uahc_gbl_bistafr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTAFR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTAFR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000A0ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_BISTAFR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_BISTAFR(...) bdk_satax_uahc_gbl_bistafr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTAFR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_BISTAFR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_BISTAFR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_BISTAFR(...) "SATAX_UAHC_GBL_BISTAFR"


/**
 * NCB32b - sata#_uahc_gbl_bistcr
 *
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union bdk_satax_uahc_gbl_bistcr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_bistcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_26_31              : 6;
		uint32_t old_phy_ready               : 1;  /**< R/W - Old phy_ready. Do not change the value of this bit. */
		uint32_t late_phy_ready              : 1;  /**< R/W - Late phy_ready. */
		uint32_t reserved_21_23              : 3;
		uint32_t ferlib                      : 1;  /**< WO - Far-end retimed loopback. */
		uint32_t reserved_19_19              : 1;
		uint32_t txo                         : 1;  /**< WO - Transmit only. */
		uint32_t cntclr                      : 1;  /**< WO - Counter clear. */
		uint32_t nealb                       : 1;  /**< WO - Near-end analog loopback. */
		uint32_t llb                         : 1;  /**< R/W - Lab loopback mode. */
		uint32_t reserved_14_14              : 1;
		uint32_t errlossen                   : 1;  /**< R/W - Error loss detect enable. */
		uint32_t sdfe                        : 1;  /**< R/W - Signal detect feature enable. */
		uint32_t rsvd_1rsvd_11               : 1;  /**< R/W - Reserved. */
		uint32_t llc                         : 3;  /**< R/W - Link layer control.
                                                                 \<10\> = RPD - repeat primitive drop enable.
                                                                 \<9\> = DESCRAM - descrambler enable.
                                                                 \<8\> = SCRAM - scrambler enable. */
		uint32_t reserved_7_7                : 1;
		uint32_t erren                       : 1;  /**< R/W - Error enable. */
		uint32_t flip                        : 1;  /**< R/W - Flip disparity. */
		uint32_t pv                          : 1;  /**< R/W - Pattern version. */
		uint32_t pattern                     : 4;  /**< RO - SATA compliant pattern selection. */
#else
		uint32_t pattern                     : 4;
		uint32_t pv                          : 1;
		uint32_t flip                        : 1;
		uint32_t erren                       : 1;
		uint32_t reserved_7_7                : 1;
		uint32_t llc                         : 3;
		uint32_t rsvd_1rsvd_11               : 1;
		uint32_t sdfe                        : 1;
		uint32_t errlossen                   : 1;
		uint32_t reserved_14_14              : 1;
		uint32_t llb                         : 1;
		uint32_t nealb                       : 1;
		uint32_t cntclr                      : 1;
		uint32_t txo                         : 1;
		uint32_t reserved_19_19              : 1;
		uint32_t ferlib                      : 1;
		uint32_t reserved_21_23              : 3;
		uint32_t late_phy_ready              : 1;
		uint32_t old_phy_ready               : 1;
		uint32_t reserved_26_31              : 6;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_bistcr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_bistcr_s cn88xxp1; */
} bdk_satax_uahc_gbl_bistcr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTCR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000A4ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_BISTCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_BISTCR(...) bdk_satax_uahc_gbl_bistcr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTCR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_BISTCR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_BISTCR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_BISTCR(...) "SATAX_UAHC_GBL_BISTCR"


/**
 * NCB32b - sata#_uahc_gbl_bistdecr
 *
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union bdk_satax_uahc_gbl_bistdecr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_bistdecr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dwerr                       : 32; /**< RO - DWORD error count. */
#else
		uint32_t dwerr                       : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_bistdecr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_bistdecr_s cn88xxp1; */
} bdk_satax_uahc_gbl_bistdecr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTDECR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTDECR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000B0ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_BISTDECR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_BISTDECR(...) bdk_satax_uahc_gbl_bistdecr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTDECR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_BISTDECR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_BISTDECR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_BISTDECR(...) "SATAX_UAHC_GBL_BISTDECR"


/**
 * NCB32b - sata#_uahc_gbl_bistfctr
 *
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union bdk_satax_uahc_gbl_bistfctr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_bistfctr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t count                       : 32; /**< RO - Received BIST FIS count. */
#else
		uint32_t count                       : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_bistfctr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_bistfctr_s cn88xxp1; */
} bdk_satax_uahc_gbl_bistfctr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTFCTR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTFCTR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000A8ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_BISTFCTR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_BISTFCTR(...) bdk_satax_uahc_gbl_bistfctr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTFCTR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_BISTFCTR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_BISTFCTR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_BISTFCTR(...) "SATAX_UAHC_GBL_BISTFCTR"


/**
 * NCB32b - sata#_uahc_gbl_bistsr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_bistsr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_bistsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t brsterr                     : 8;  /**< RO - Burst error. */
		uint32_t framerr                     : 16; /**< RO - Frame error. */
#else
		uint32_t framerr                     : 16;
		uint32_t brsterr                     : 8;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_bistsr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_bistsr_s cn88xxp1; */
} bdk_satax_uahc_gbl_bistsr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTSR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000ACull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_BISTSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_BISTSR(...) bdk_satax_uahc_gbl_bistsr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTSR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_BISTSR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_BISTSR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_BISTSR(...) "SATAX_UAHC_GBL_BISTSR"


/**
 * NCB32b - sata#_uahc_gbl_cap
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_cap {
	uint32_t u;
	struct bdk_satax_uahc_gbl_cap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t s64a                        : 1;  /**< RO - Supports 64-bit addressing. */
		uint32_t sncq                        : 1;  /**< RO - Supports native command queuing. */
		uint32_t ssntf                       : 1;  /**< RO - Supports SNotification register. */
		uint32_t smps                        : 1;  /**< R/W - Supports mechanical presence switch. */
		uint32_t sss                         : 1;  /**< R/W - Supports staggered spin-up. */
		uint32_t salp                        : 1;  /**< RO - Supports agressive link power management. */
		uint32_t sal                         : 1;  /**< RO - Supports activity LED. */
		uint32_t sclo                        : 1;  /**< RO - Supports command list override. */
		uint32_t iss                         : 4;  /**< RO - Interface speed support. */
		uint32_t snzo                        : 1;  /**< RO - Supports non-zero DMA offsets. */
		uint32_t sam                         : 1;  /**< RO - Supports AHCI mode only. */
		uint32_t spm                         : 1;  /**< RO - Supports port multiplier. */
		uint32_t fbss                        : 1;  /**< RO - Supports FIS-based switching. */
		uint32_t pmd                         : 1;  /**< RO - PIO multiple DRQ block. */
		uint32_t ssc                         : 1;  /**< RO - Slumber state capable. */
		uint32_t psc                         : 1;  /**< RO - Partial state capable. */
		uint32_t ncs                         : 5;  /**< RO - Number of command slots. */
		uint32_t cccs                        : 1;  /**< RO - Command completion coalescing support. */
		uint32_t ems                         : 1;  /**< RO - Enclosure management support. */
		uint32_t sxs                         : 1;  /**< RO - Supports external SATA. */
		uint32_t np                          : 5;  /**< RO - Number of ports. 0x0 = 1 port. */
#else
		uint32_t np                          : 5;
		uint32_t sxs                         : 1;
		uint32_t ems                         : 1;
		uint32_t cccs                        : 1;
		uint32_t ncs                         : 5;
		uint32_t psc                         : 1;
		uint32_t ssc                         : 1;
		uint32_t pmd                         : 1;
		uint32_t fbss                        : 1;
		uint32_t spm                         : 1;
		uint32_t sam                         : 1;
		uint32_t snzo                        : 1;
		uint32_t iss                         : 4;
		uint32_t sclo                        : 1;
		uint32_t sal                         : 1;
		uint32_t salp                        : 1;
		uint32_t sss                         : 1;
		uint32_t smps                        : 1;
		uint32_t ssntf                       : 1;
		uint32_t sncq                        : 1;
		uint32_t s64a                        : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_cap_s    cn88xx; */
	/* struct bdk_satax_uahc_gbl_cap_s    cn88xxp1; */
} bdk_satax_uahc_gbl_cap_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CAP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CAP(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000000ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_CAP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_CAP(...) bdk_satax_uahc_gbl_cap_t
#define bustype_BDK_SATAX_UAHC_GBL_CAP(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_CAP(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_CAP(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_CAP(...) "SATAX_UAHC_GBL_CAP"


/**
 * NCB32b - sata#_uahc_gbl_cap2
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_cap2 {
	uint32_t u;
	struct bdk_satax_uahc_gbl_cap2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_6_31               : 26;
		uint32_t deso                        : 1;  /**< RO - Device sleep entrance from slumber only. */
		uint32_t sadm                        : 1;  /**< RO - Supports aggressive device sleep management. */
		uint32_t sds                         : 1;  /**< RO - Supports device sleep. */
		uint32_t apst                        : 1;  /**< RO - Automatic partial to slumber transitions. */
		uint32_t nvmp                        : 1;  /**< RO - NVMHCI present. */
		uint32_t boh                         : 1;  /**< RO - Supports BIOS/OS handoff. */
#else
		uint32_t boh                         : 1;
		uint32_t nvmp                        : 1;
		uint32_t apst                        : 1;
		uint32_t sds                         : 1;
		uint32_t sadm                        : 1;
		uint32_t deso                        : 1;
		uint32_t reserved_6_31               : 26;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_cap2_s   cn88xx; */
	/* struct bdk_satax_uahc_gbl_cap2_s   cn88xxp1; */
} bdk_satax_uahc_gbl_cap2_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CAP2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CAP2(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000024ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_CAP2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_CAP2(...) bdk_satax_uahc_gbl_cap2_t
#define bustype_BDK_SATAX_UAHC_GBL_CAP2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_CAP2(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_CAP2(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_CAP2(...) "SATAX_UAHC_GBL_CAP2"


/**
 * NCB32b - sata#_uahc_gbl_ccc_ctl
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_ccc_ctl {
	uint32_t u;
	struct bdk_satax_uahc_gbl_ccc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tv                          : 16; /**< R/W - Time-out value. Writable only when EN = 0. */
		uint32_t cc                          : 8;  /**< R/W - Command completions. Writable only when EN = 0. */
		uint32_t intr                        : 5;  /**< RO - Specifies the port interrupt used by the CCC feature. */
		uint32_t reserved_1_2                : 2;
		uint32_t en                          : 1;  /**< R/W - CCC enable. */
#else
		uint32_t en                          : 1;
		uint32_t reserved_1_2                : 2;
		uint32_t intr                        : 5;
		uint32_t cc                          : 8;
		uint32_t tv                          : 16;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_ccc_ctl_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_ccc_ctl_s cn88xxp1; */
} bdk_satax_uahc_gbl_ccc_ctl_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_CTL(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000014ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_CCC_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_CCC_CTL(...) bdk_satax_uahc_gbl_ccc_ctl_t
#define bustype_BDK_SATAX_UAHC_GBL_CCC_CTL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_CCC_CTL(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_CCC_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_CCC_CTL(...) "SATAX_UAHC_GBL_CCC_CTL"


/**
 * NCB32b - sata#_uahc_gbl_ccc_ports
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_ccc_ports {
	uint32_t u;
	struct bdk_satax_uahc_gbl_ccc_ports_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t prt                         : 1;  /**< R/W - Per port CCC enable. */
#else
		uint32_t prt                         : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_ccc_ports_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_ccc_ports_s cn88xxp1; */
} bdk_satax_uahc_gbl_ccc_ports_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_PORTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_PORTS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000018ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_CCC_PORTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_CCC_PORTS(...) bdk_satax_uahc_gbl_ccc_ports_t
#define bustype_BDK_SATAX_UAHC_GBL_CCC_PORTS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_CCC_PORTS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_CCC_PORTS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_CCC_PORTS(...) "SATAX_UAHC_GBL_CCC_PORTS"


/**
 * NCB32b - sata#_uahc_gbl_ghc
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_ghc {
	uint32_t u;
	struct bdk_satax_uahc_gbl_ghc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ae                          : 1;  /**< RO - AHCI enable. */
		uint32_t reserved_2_30               : 29;
		uint32_t ie                          : 1;  /**< R/W - Interrupt enable. */
		uint32_t hr                          : 1;  /**< R/W1/H - HBA reset. Writing a 1 resets the UAHC. Hardware clears this bit once reset is complete. */
#else
		uint32_t hr                          : 1;
		uint32_t ie                          : 1;
		uint32_t reserved_2_30               : 29;
		uint32_t ae                          : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_ghc_s    cn88xx; */
	/* struct bdk_satax_uahc_gbl_ghc_s    cn88xxp1; */
} bdk_satax_uahc_gbl_ghc_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_GHC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_GHC(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000004ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_GHC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_GHC(...) bdk_satax_uahc_gbl_ghc_t
#define bustype_BDK_SATAX_UAHC_GBL_GHC(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_GHC(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_GHC(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_GHC(...) "SATAX_UAHC_GBL_GHC"


/**
 * NCB32b - sata#_uahc_gbl_gparam1r
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_gparam1r {
	uint32_t u;
	struct bdk_satax_uahc_gbl_gparam1r_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t align_m                     : 1;  /**< RO - RX data alignment mode (ALIGN_MODE). */
		uint32_t rx_buffer                   : 1;  /**< RO - RX data buffer mode (RX_BUFFER_MODE). */
		uint32_t phy_data                    : 2;  /**< RO - PHY data width (PHY_DATA_WIDTH). */
		uint32_t phy_rst                     : 1;  /**< RO - PHY reset mode (PHY_RST_MODE). */
		uint32_t phy_ctrl                    : 6;  /**< RO - PHY control width (PHY_CTRL_W). */
		uint32_t phy_stat                    : 6;  /**< RO - PHY status width (PHY_STAT_W). */
		uint32_t latch_m                     : 1;  /**< RO - Latch mode (LATCH_MODE). */
		uint32_t phy_type                    : 3;  /**< RO - PHY interface type (PHY_INTERFACE_TYPE). */
		uint32_t return_err                  : 1;  /**< RO - AMBA error response (RETURN_ERR_RESP). */
		uint32_t ahb_endian                  : 2;  /**< RO - AHB bus endianness (AHB_ENDIANNESS). */
		uint32_t s_haddr                     : 1;  /**< RO - AMBA slave address bus width (S_HADDR_WIDTH). */
		uint32_t m_haddr                     : 1;  /**< RO - AMBA master address bus width (M_HADDR_WIDTH). */
		uint32_t s_hdata                     : 3;  /**< RO - AMBA slave data width (S_HDATA_WIDTH). */
		uint32_t m_hdata                     : 3;  /**< RO - AMBA master data width (M_HDATA_WIDTH). */
#else
		uint32_t m_hdata                     : 3;
		uint32_t s_hdata                     : 3;
		uint32_t m_haddr                     : 1;
		uint32_t s_haddr                     : 1;
		uint32_t ahb_endian                  : 2;
		uint32_t return_err                  : 1;
		uint32_t phy_type                    : 3;
		uint32_t latch_m                     : 1;
		uint32_t phy_stat                    : 6;
		uint32_t phy_ctrl                    : 6;
		uint32_t phy_rst                     : 1;
		uint32_t phy_data                    : 2;
		uint32_t rx_buffer                   : 1;
		uint32_t align_m                     : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_gparam1r_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_gparam1r_s cn88xxp1; */
} bdk_satax_uahc_gbl_gparam1r_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM1R(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM1R(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000E8ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_GPARAM1R", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_GPARAM1R(...) bdk_satax_uahc_gbl_gparam1r_t
#define bustype_BDK_SATAX_UAHC_GBL_GPARAM1R(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_GPARAM1R(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_GPARAM1R(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_GPARAM1R(...) "SATAX_UAHC_GBL_GPARAM1R"


/**
 * NCB32b - sata#_uahc_gbl_gparam2r
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_gparam2r {
	uint32_t u;
	struct bdk_satax_uahc_gbl_gparam2r_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t rxoob_clk_units             : 1;  /**< RO - RX OOB clock frequency units. */
		uint32_t rxoob_clk_upper             : 10; /**< RO - Upper bits of RX OOB clock frequency. */
		uint32_t bist_m                      : 1;  /**< RO - BIST loopback checking depth (BIST_MODE). */
		uint32_t fbs_mem_s                   : 1;  /**< RO - Context RAM memory location (FBS_MEM_S). */
		uint32_t fbs_pmpn                    : 2;  /**< RO - Maximum number of port multiplier ports (FBS_PMPN_MAX). */
		uint32_t fbs_support                 : 1;  /**< RO - FIS-based switching support (FBS_SUPPORT). */
		uint32_t dev_cp                      : 1;  /**< RO - Cold presence detect (DEV_CP_DET). */
		uint32_t dev_mp                      : 1;  /**< RO - Mechanical presence switch (DEV_MP_SWITCH). */
		uint32_t encode_m                    : 1;  /**< RO - 8b/10b encoding/decoding (ENCODE_MODE). */
		uint32_t rxoob_clk_m                 : 1;  /**< RO - RX OOB clock mode (RXOOB_CLK_MODE). */
		uint32_t rx_oob_m                    : 1;  /**< RO - RX OOB mode (RX_OOB_MODE). */
		uint32_t tx_oob_m                    : 1;  /**< RO - TX OOB mode (TX_OOB_MODE). */
		uint32_t rxoob_clk                   : 9;  /**< RO - RX OOB clock frequency (RXOOB_CLK). */
#else
		uint32_t rxoob_clk                   : 9;
		uint32_t tx_oob_m                    : 1;
		uint32_t rx_oob_m                    : 1;
		uint32_t rxoob_clk_m                 : 1;
		uint32_t encode_m                    : 1;
		uint32_t dev_mp                      : 1;
		uint32_t dev_cp                      : 1;
		uint32_t fbs_support                 : 1;
		uint32_t fbs_pmpn                    : 2;
		uint32_t fbs_mem_s                   : 1;
		uint32_t bist_m                      : 1;
		uint32_t rxoob_clk_upper             : 10;
		uint32_t rxoob_clk_units             : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_gparam2r_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_gparam2r_s cn88xxp1; */
} bdk_satax_uahc_gbl_gparam2r_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM2R(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM2R(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000ECull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_GPARAM2R", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_GPARAM2R(...) bdk_satax_uahc_gbl_gparam2r_t
#define bustype_BDK_SATAX_UAHC_GBL_GPARAM2R(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_GPARAM2R(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_GPARAM2R(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_GPARAM2R(...) "SATAX_UAHC_GBL_GPARAM2R"


/**
 * NCB32b - sata#_uahc_gbl_idr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_idr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_idr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t id                          : 32; /**< RO - Core ID. */
#else
		uint32_t id                          : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_idr_s    cn88xx; */
	/* struct bdk_satax_uahc_gbl_idr_s    cn88xxp1; */
} bdk_satax_uahc_gbl_idr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_IDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_IDR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000FCull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_IDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_IDR(...) bdk_satax_uahc_gbl_idr_t
#define bustype_BDK_SATAX_UAHC_GBL_IDR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_IDR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_IDR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_IDR(...) "SATAX_UAHC_GBL_IDR"


/**
 * NCB32b - sata#_uahc_gbl_is
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_is {
	uint32_t u;
	struct bdk_satax_uahc_gbl_is_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t ips                         : 2;  /**< R/W1C/H - Interrupt pending status. */
#else
		uint32_t ips                         : 2;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_is_s     cn88xx; */
	/* struct bdk_satax_uahc_gbl_is_s     cn88xxp1; */
} bdk_satax_uahc_gbl_is_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_IS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_IS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000008ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_IS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_IS(...) bdk_satax_uahc_gbl_is_t
#define bustype_BDK_SATAX_UAHC_GBL_IS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_IS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_IS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_IS(...) "SATAX_UAHC_GBL_IS"


/**
 * NCB32b - sata#_uahc_gbl_oobr
 *
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union bdk_satax_uahc_gbl_oobr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_oobr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t we                          : 1;  /**< R/W/H - Write enable. */
		uint32_t cwmin                       : 7;  /**< R/W/H - COMWAKE minimum value. Writable only if WE is set. */
		uint32_t cwmax                       : 8;  /**< R/W/H - COMWAKE maximum value. Writable only if WE is set. */
		uint32_t cimin                       : 8;  /**< R/W/H - COMINIT minimum value. Writable only if WE is set. */
		uint32_t cimax                       : 8;  /**< R/W/H - COMINIT maximum value. Writable only if WE is set. */
#else
		uint32_t cimax                       : 8;
		uint32_t cimin                       : 8;
		uint32_t cwmax                       : 8;
		uint32_t cwmin                       : 7;
		uint32_t we                          : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_oobr_s   cn88xx; */
	/* struct bdk_satax_uahc_gbl_oobr_s   cn88xxp1; */
} bdk_satax_uahc_gbl_oobr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_OOBR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_OOBR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000BCull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_OOBR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_OOBR(...) bdk_satax_uahc_gbl_oobr_t
#define bustype_BDK_SATAX_UAHC_GBL_OOBR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_OOBR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_OOBR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_OOBR(...) "SATAX_UAHC_GBL_OOBR"


/**
 * NCB32b - sata#_uahc_gbl_pi
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_pi {
	uint32_t u;
	struct bdk_satax_uahc_gbl_pi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t pi                          : 1;  /**< R/W - Number of ports implemented. This field is one-time writable, then becomes read-only. */
#else
		uint32_t pi                          : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_pi_s     cn88xx; */
	/* struct bdk_satax_uahc_gbl_pi_s     cn88xxp1; */
} bdk_satax_uahc_gbl_pi_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_PI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_PI(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000081000000000Cull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_PI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_PI(...) bdk_satax_uahc_gbl_pi_t
#define bustype_BDK_SATAX_UAHC_GBL_PI(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_PI(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_PI(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_PI(...) "SATAX_UAHC_GBL_PI"


/**
 * NCB32b - sata#_uahc_gbl_pparamr
 *
 * Port is selected by the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union bdk_satax_uahc_gbl_pparamr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_pparamr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t tx_mem_m                    : 1;  /**< RO - TX FIFO memory read port type (Pn_TX_MEM_MODE). */
		uint32_t tx_mem_s                    : 1;  /**< RO - TX FIFO memory type (Pn_TX_MEM_SELECT). */
		uint32_t rx_mem_m                    : 1;  /**< RO - RX FIFO memory read port type (Pn_RX_MEM_MODE). */
		uint32_t rx_mem_s                    : 1;  /**< RO - RX FIFO memory type (Pn_RX_MEM_SELECT). */
		uint32_t txfifo_depth                : 4;  /**< RO - TX FIFO depth in FIFO words. */
		uint32_t rxfifo_depth                : 4;  /**< RO - RX FIFO depth in FIFO words. */
#else
		uint32_t rxfifo_depth                : 4;
		uint32_t txfifo_depth                : 4;
		uint32_t rx_mem_s                    : 1;
		uint32_t rx_mem_m                    : 1;
		uint32_t tx_mem_s                    : 1;
		uint32_t tx_mem_m                    : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_pparamr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_pparamr_s cn88xxp1; */
} bdk_satax_uahc_gbl_pparamr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_PPARAMR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_PPARAMR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000F0ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_PPARAMR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_PPARAMR(...) bdk_satax_uahc_gbl_pparamr_t
#define bustype_BDK_SATAX_UAHC_GBL_PPARAMR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_PPARAMR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_PPARAMR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_PPARAMR(...) "SATAX_UAHC_GBL_PPARAMR"


/**
 * NCB32b - sata#_uahc_gbl_testr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_testr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_testr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_19_31              : 13;
		uint32_t psel                        : 3;  /**< R/W - Port select. */
		uint32_t reserved_1_15               : 15;
		uint32_t test_if                     : 1;  /**< R/W - Test interface. */
#else
		uint32_t test_if                     : 1;
		uint32_t reserved_1_15               : 15;
		uint32_t psel                        : 3;
		uint32_t reserved_19_31              : 13;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_testr_s  cn88xx; */
	/* struct bdk_satax_uahc_gbl_testr_s  cn88xxp1; */
} bdk_satax_uahc_gbl_testr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_TESTR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_TESTR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000F4ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_TESTR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_TESTR(...) bdk_satax_uahc_gbl_testr_t
#define bustype_BDK_SATAX_UAHC_GBL_TESTR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_TESTR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_TESTR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_TESTR(...) "SATAX_UAHC_GBL_TESTR"


/**
 * NCB32b - sata#_uahc_gbl_timer1ms
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_timer1ms {
	uint32_t u;
	struct bdk_satax_uahc_gbl_timer1ms_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t timv                        : 20; /**< R/W - 1ms timer value. Writable only when SATA()_UAHC_GBL_CCC_CTL[EN] = 0. */
#else
		uint32_t timv                        : 20;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_timer1ms_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_timer1ms_s cn88xxp1; */
} bdk_satax_uahc_gbl_timer1ms_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_TIMER1MS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_TIMER1MS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000E0ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_TIMER1MS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_TIMER1MS(...) bdk_satax_uahc_gbl_timer1ms_t
#define bustype_BDK_SATAX_UAHC_GBL_TIMER1MS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_TIMER1MS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_TIMER1MS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_TIMER1MS(...) "SATAX_UAHC_GBL_TIMER1MS"


/**
 * NCB32b - sata#_uahc_gbl_versionr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_gbl_versionr {
	uint32_t u;
	struct bdk_satax_uahc_gbl_versionr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ver                         : 32; /**< RO - SATA IP version number. */
#else
		uint32_t ver                         : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_versionr_s cn88xx; */
	/* struct bdk_satax_uahc_gbl_versionr_s cn88xxp1; */
} bdk_satax_uahc_gbl_versionr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_VERSIONR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_VERSIONR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100000000F8ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_VERSIONR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_VERSIONR(...) bdk_satax_uahc_gbl_versionr_t
#define bustype_BDK_SATAX_UAHC_GBL_VERSIONR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_VERSIONR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_VERSIONR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_VERSIONR(...) "SATAX_UAHC_GBL_VERSIONR"


/**
 * NCB32b - sata#_uahc_gbl_vs
 *
 * See AHCI specification v1.3 section 3.1.
 *
 */
typedef union bdk_satax_uahc_gbl_vs {
	uint32_t u;
	struct bdk_satax_uahc_gbl_vs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t mjr                         : 16; /**< RO - Major version number. */
		uint32_t mnr                         : 16; /**< RO - Minor version number. No DEVSLP support. */
#else
		uint32_t mnr                         : 16;
		uint32_t mjr                         : 16;
#endif
	} s;
	/* struct bdk_satax_uahc_gbl_vs_s     cn88xx; */
	/* struct bdk_satax_uahc_gbl_vs_s     cn88xxp1; */
} bdk_satax_uahc_gbl_vs_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_VS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_VS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000010ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_GBL_VS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_GBL_VS(...) bdk_satax_uahc_gbl_vs_t
#define bustype_BDK_SATAX_UAHC_GBL_VS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_GBL_VS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_GBL_VS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_GBL_VS(...) "SATAX_UAHC_GBL_VS"


/**
 * NCB32b - sata#_uahc_p0_ci
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_ci {
	uint32_t u;
	struct bdk_satax_uahc_p0_ci_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ci                          : 32; /**< R/W1S/H - Command issued. */
#else
		uint32_t ci                          : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_ci_s      cn88xx; */
	/* struct bdk_satax_uahc_p0_ci_s      cn88xxp1; */
} bdk_satax_uahc_p0_ci_t;

static inline uint64_t BDK_SATAX_UAHC_P0_CI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_CI(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000138ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_CI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_CI(...) bdk_satax_uahc_p0_ci_t
#define bustype_BDK_SATAX_UAHC_P0_CI(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_CI(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_CI(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_CI(...) "SATAX_UAHC_P0_CI"


/**
 * NCB - sata#_uahc_p0_clb
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_clb {
	uint64_t u;
	struct bdk_satax_uahc_p0_clb_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t clb                         : 54; /**< R/W - Command-list base address. */
		uint64_t reserved_0_9                : 10;
#else
		uint64_t reserved_0_9                : 10;
		uint64_t clb                         : 54;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_clb_s     cn88xx; */
	/* struct bdk_satax_uahc_p0_clb_s     cn88xxp1; */
} bdk_satax_uahc_p0_clb_t;

static inline uint64_t BDK_SATAX_UAHC_P0_CLB(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_CLB(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000100ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_CLB", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_CLB(...) bdk_satax_uahc_p0_clb_t
#define bustype_BDK_SATAX_UAHC_P0_CLB(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UAHC_P0_CLB(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_CLB(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_CLB(...) "SATAX_UAHC_P0_CLB"


/**
 * NCB32b - sata#_uahc_p0_cmd
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_cmd {
	uint32_t u;
	struct bdk_satax_uahc_p0_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t icc                         : 4;  /**< R/W - Interface communication control. */
		uint32_t asp                         : 1;  /**< R/W - Aggressive slumber/partial. */
		uint32_t alpe                        : 1;  /**< R/W - Aggressive link-power-management enable. */
		uint32_t dlae                        : 1;  /**< R/W - Drive LED on ATAPI enable. */
		uint32_t atapi                       : 1;  /**< R/W - Device is ATAPI. */
		uint32_t apste                       : 1;  /**< R/W - Automatic partial to slumber transitions enable. */
		uint32_t fbscp                       : 1;  /**< R/W - FIS-based switching capable port. Write-once. */
		uint32_t esp                         : 1;  /**< R/W - External SATA port. Write-once. */
		uint32_t cpd                         : 1;  /**< R/W - Cold-presence detection. Write-once. */
		uint32_t mpsp                        : 1;  /**< R/W - Mechanical presence switch attached to port. Write-once. */
		uint32_t hpcp                        : 1;  /**< R/W - Hot-plug-capable support. Write-once. */
		uint32_t pma                         : 1;  /**< R/W - Port multiplier attached. */
		uint32_t cps                         : 1;  /**< RO - Cold presence state. */
		uint32_t cr                          : 1;  /**< RO - Command list running. */
		uint32_t fr                          : 1;  /**< RO/H - FIS receive running. */
		uint32_t mpss                        : 1;  /**< RO - Mechanical presence switch state. */
		uint32_t ccs                         : 5;  /**< RO - Current-command slot. */
		uint32_t reserved_5_7                : 3;
		uint32_t fre                         : 1;  /**< R/W - FIS-receive enable. */
		uint32_t clo                         : 1;  /**< WO - Command-list override. */
		uint32_t pod                         : 1;  /**< R/W - Power-on device. R/W only if CPD = 1, else read only. */
		uint32_t sud                         : 1;  /**< R/W - Spin-up device. R/W only if SATA()_UAHC_GBL_CAP[SSS]=1, else read only.
                                                                 Setting this bit triggers a COMRESET initialization sequence. */
		uint32_t st                          : 1;  /**< R/W - Start. */
#else
		uint32_t st                          : 1;
		uint32_t sud                         : 1;
		uint32_t pod                         : 1;
		uint32_t clo                         : 1;
		uint32_t fre                         : 1;
		uint32_t reserved_5_7                : 3;
		uint32_t ccs                         : 5;
		uint32_t mpss                        : 1;
		uint32_t fr                          : 1;
		uint32_t cr                          : 1;
		uint32_t cps                         : 1;
		uint32_t pma                         : 1;
		uint32_t hpcp                        : 1;
		uint32_t mpsp                        : 1;
		uint32_t cpd                         : 1;
		uint32_t esp                         : 1;
		uint32_t fbscp                       : 1;
		uint32_t apste                       : 1;
		uint32_t atapi                       : 1;
		uint32_t dlae                        : 1;
		uint32_t alpe                        : 1;
		uint32_t asp                         : 1;
		uint32_t icc                         : 4;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_cmd_s     cn88xx; */
	/* struct bdk_satax_uahc_p0_cmd_s     cn88xxp1; */
} bdk_satax_uahc_p0_cmd_t;

static inline uint64_t BDK_SATAX_UAHC_P0_CMD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_CMD(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000118ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_CMD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_CMD(...) bdk_satax_uahc_p0_cmd_t
#define bustype_BDK_SATAX_UAHC_P0_CMD(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_CMD(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_CMD(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_CMD(...) "SATAX_UAHC_P0_CMD"


/**
 * NCB32b - sata#_uahc_p0_dmacr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_dmacr {
	uint32_t u;
	struct bdk_satax_uahc_p0_dmacr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t rxts                        : 4;  /**< R/W - Receive transaction size. This field is R/W when SATA()_UAHC_P0_CMD[ST] = 0
                                                                 and read only when SATA()_UAHC_P0_CMD[ST] = 1. */
		uint32_t txts                        : 4;  /**< R/W - Transmit transaction size. This field is R/W when SATA()_UAHC_P0_CMD[ST] = 0
                                                                 and read only when SATA()_UAHC_P0_CMD[ST] = 1. */
#else
		uint32_t txts                        : 4;
		uint32_t rxts                        : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_dmacr_s   cn88xx; */
	/* struct bdk_satax_uahc_p0_dmacr_s   cn88xxp1; */
} bdk_satax_uahc_p0_dmacr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_DMACR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_DMACR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000170ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_DMACR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_DMACR(...) bdk_satax_uahc_p0_dmacr_t
#define bustype_BDK_SATAX_UAHC_P0_DMACR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_DMACR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_DMACR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_DMACR(...) "SATAX_UAHC_P0_DMACR"


/**
 * NCB - sata#_uahc_p0_fb
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_fb {
	uint64_t u;
	struct bdk_satax_uahc_p0_fb_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t fb                          : 56; /**< R/W - FIS base address. */
		uint64_t reserved_0_7                : 8;
#else
		uint64_t reserved_0_7                : 8;
		uint64_t fb                          : 56;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_fb_s      cn88xx; */
	/* struct bdk_satax_uahc_p0_fb_s      cn88xxp1; */
} bdk_satax_uahc_p0_fb_t;

static inline uint64_t BDK_SATAX_UAHC_P0_FB(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_FB(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000108ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_FB", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_FB(...) bdk_satax_uahc_p0_fb_t
#define bustype_BDK_SATAX_UAHC_P0_FB(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UAHC_P0_FB(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_FB(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_FB(...) "SATAX_UAHC_P0_FB"


/**
 * NCB32b - sata#_uahc_p0_fbs
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_fbs {
	uint32_t u;
	struct bdk_satax_uahc_p0_fbs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t dwe                         : 4;  /**< RO - Device with error. */
		uint32_t ado                         : 4;  /**< RO - Active device optimization. */
		uint32_t dev                         : 4;  /**< R/W - Device to issue. */
		uint32_t reserved_3_7                : 5;
		uint32_t sde                         : 1;  /**< RO - Single device error. */
		uint32_t dec                         : 1;  /**< R/W1C/H - Device error clear. */
		uint32_t en                          : 1;  /**< R/W - Enable. */
#else
		uint32_t en                          : 1;
		uint32_t dec                         : 1;
		uint32_t sde                         : 1;
		uint32_t reserved_3_7                : 5;
		uint32_t dev                         : 4;
		uint32_t ado                         : 4;
		uint32_t dwe                         : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_fbs_s     cn88xx; */
	/* struct bdk_satax_uahc_p0_fbs_s     cn88xxp1; */
} bdk_satax_uahc_p0_fbs_t;

static inline uint64_t BDK_SATAX_UAHC_P0_FBS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_FBS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000140ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_FBS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_FBS(...) bdk_satax_uahc_p0_fbs_t
#define bustype_BDK_SATAX_UAHC_P0_FBS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_FBS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_FBS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_FBS(...) "SATAX_UAHC_P0_FBS"


/**
 * NCB32b - sata#_uahc_p0_ie
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_ie {
	uint32_t u;
	struct bdk_satax_uahc_p0_ie_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cpde                        : 1;  /**< R/W - Cold-port-detect enable. */
		uint32_t tfee                        : 1;  /**< R/W - Task-file-error enable. */
		uint32_t hbfe                        : 1;  /**< R/W - Host-bus fatal-error enable. */
		uint32_t hbde                        : 1;  /**< R/W - Host-bus data-error enable. */
		uint32_t ife                         : 1;  /**< R/W - Interface fatal-error enable. */
		uint32_t infe                        : 1;  /**< R/W - Interface non-fatal-error enable. */
		uint32_t reserved_25_25              : 1;
		uint32_t ofe                         : 1;  /**< R/W - Overflow enable. */
		uint32_t impe                        : 1;  /**< R/W - Incorrect port-multiplier enable. */
		uint32_t prce                        : 1;  /**< R/W - PHY-ready-change enable. */
		uint32_t reserved_8_21               : 14;
		uint32_t dmpe                        : 1;  /**< R/W - Device mechanical-presence enable. */
		uint32_t pce                         : 1;  /**< R/W - Port-connect-change enable. */
		uint32_t dpe                         : 1;  /**< R/W - Descriptor-processed enable. */
		uint32_t ufe                         : 1;  /**< R/W - Unknown-FIS-interrupt enable. */
		uint32_t sdbe                        : 1;  /**< R/W - Set device-bits-interrupt enable. */
		uint32_t dse                         : 1;  /**< R/W - DMA-setup FIS interrupt enable. */
		uint32_t pse                         : 1;  /**< R/W - PIO-setup FIS interrupt enable. */
		uint32_t dhre                        : 1;  /**< R/W - Device-to-host register FIS interrupt enable. */
#else
		uint32_t dhre                        : 1;
		uint32_t pse                         : 1;
		uint32_t dse                         : 1;
		uint32_t sdbe                        : 1;
		uint32_t ufe                         : 1;
		uint32_t dpe                         : 1;
		uint32_t pce                         : 1;
		uint32_t dmpe                        : 1;
		uint32_t reserved_8_21               : 14;
		uint32_t prce                        : 1;
		uint32_t impe                        : 1;
		uint32_t ofe                         : 1;
		uint32_t reserved_25_25              : 1;
		uint32_t infe                        : 1;
		uint32_t ife                         : 1;
		uint32_t hbde                        : 1;
		uint32_t hbfe                        : 1;
		uint32_t tfee                        : 1;
		uint32_t cpde                        : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_ie_s      cn88xx; */
	/* struct bdk_satax_uahc_p0_ie_s      cn88xxp1; */
} bdk_satax_uahc_p0_ie_t;

static inline uint64_t BDK_SATAX_UAHC_P0_IE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_IE(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000114ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_IE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_IE(...) bdk_satax_uahc_p0_ie_t
#define bustype_BDK_SATAX_UAHC_P0_IE(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_IE(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_IE(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_IE(...) "SATAX_UAHC_P0_IE"


/**
 * NCB32b - sata#_uahc_p0_is
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_is {
	uint32_t u;
	struct bdk_satax_uahc_p0_is_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cpds                        : 1;  /**< R/W1C/H - Cold-port detect status. */
		uint32_t tfes                        : 1;  /**< R/W1C/H - Task-file error status. */
		uint32_t hbfs                        : 1;  /**< R/W1C/H - Host-bus fatal-error status. */
		uint32_t hbds                        : 1;  /**< R/W1C/H - Host-bus data-error status. */
		uint32_t ifs                         : 1;  /**< R/W1C/H - Interface fatal-error status. */
		uint32_t infs                        : 1;  /**< R/W1C/H - Interface non-fatal-error status. */
		uint32_t reserved_25_25              : 1;
		uint32_t ofs                         : 1;  /**< R/W1C/H - Overflow status. */
		uint32_t imps                        : 1;  /**< R/W1C/H - Incorrect port-multiplier status. */
		uint32_t prcs                        : 1;  /**< RO/H - PHY-ready change status. */
		uint32_t reserved_8_21               : 14;
		uint32_t dmps                        : 1;  /**< R/W1C/H - Device mechanical-presence status. */
		uint32_t pcs                         : 1;  /**< RO/H - Port-connect-change status. */
		uint32_t dps                         : 1;  /**< R/W1C/H - Descriptor processed. */
		uint32_t ufs                         : 1;  /**< RO - Unknown FIS interrupt. */
		uint32_t sdbs                        : 1;  /**< R/W1C/H - Set device bits interrupt. */
		uint32_t dss                         : 1;  /**< R/W1C/H - DMA setup FIS interrupt. */
		uint32_t pss                         : 1;  /**< R/W1C/H - PIO setup FIS interrupt. */
		uint32_t dhrs                        : 1;  /**< R/W1C/H - Device-to-host register FIS interrupt. */
#else
		uint32_t dhrs                        : 1;
		uint32_t pss                         : 1;
		uint32_t dss                         : 1;
		uint32_t sdbs                        : 1;
		uint32_t ufs                         : 1;
		uint32_t dps                         : 1;
		uint32_t pcs                         : 1;
		uint32_t dmps                        : 1;
		uint32_t reserved_8_21               : 14;
		uint32_t prcs                        : 1;
		uint32_t imps                        : 1;
		uint32_t ofs                         : 1;
		uint32_t reserved_25_25              : 1;
		uint32_t infs                        : 1;
		uint32_t ifs                         : 1;
		uint32_t hbds                        : 1;
		uint32_t hbfs                        : 1;
		uint32_t tfes                        : 1;
		uint32_t cpds                        : 1;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_is_s      cn88xx; */
	/* struct bdk_satax_uahc_p0_is_s      cn88xxp1; */
} bdk_satax_uahc_p0_is_t;

static inline uint64_t BDK_SATAX_UAHC_P0_IS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_IS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000110ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_IS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_IS(...) bdk_satax_uahc_p0_is_t
#define bustype_BDK_SATAX_UAHC_P0_IS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_IS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_IS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_IS(...) "SATAX_UAHC_P0_IS"


/**
 * NCB32b - sata#_uahc_p0_phycr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_phycr {
	uint32_t u;
	struct bdk_satax_uahc_p0_phycr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ctrl                        : 32; /**< R/W - Port PHY control. */
#else
		uint32_t ctrl                        : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_phycr_s   cn88xx; */
	/* struct bdk_satax_uahc_p0_phycr_s   cn88xxp1; */
} bdk_satax_uahc_p0_phycr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_PHYCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_PHYCR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000178ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_PHYCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_PHYCR(...) bdk_satax_uahc_p0_phycr_t
#define bustype_BDK_SATAX_UAHC_P0_PHYCR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_PHYCR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_PHYCR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_PHYCR(...) "SATAX_UAHC_P0_PHYCR"


/**
 * NCB32b - sata#_uahc_p0_physr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_physr {
	uint32_t u;
	struct bdk_satax_uahc_p0_physr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t stat                        : 32; /**< RO - Port PHY status. */
#else
		uint32_t stat                        : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_physr_s   cn88xx; */
	/* struct bdk_satax_uahc_p0_physr_s   cn88xxp1; */
} bdk_satax_uahc_p0_physr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_PHYSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_PHYSR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000081000000017Cull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_PHYSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_PHYSR(...) bdk_satax_uahc_p0_physr_t
#define bustype_BDK_SATAX_UAHC_P0_PHYSR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_PHYSR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_PHYSR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_PHYSR(...) "SATAX_UAHC_P0_PHYSR"


/**
 * NCB32b - sata#_uahc_p0_sact
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_sact {
	uint32_t u;
	struct bdk_satax_uahc_p0_sact_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ds                          : 32; /**< R/W1S/H - Device status. */
#else
		uint32_t ds                          : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_sact_s    cn88xx; */
	/* struct bdk_satax_uahc_p0_sact_s    cn88xxp1; */
} bdk_satax_uahc_p0_sact_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SACT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SACT(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000134ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_SACT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_SACT(...) bdk_satax_uahc_p0_sact_t
#define bustype_BDK_SATAX_UAHC_P0_SACT(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_SACT(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_SACT(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_SACT(...) "SATAX_UAHC_P0_SACT"


/**
 * NCB32b - sata#_uahc_p0_sctl
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_sctl {
	uint32_t u;
	struct bdk_satax_uahc_p0_sctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_10_31              : 22;
		uint32_t ipm                         : 2;  /**< R/W - Interface power-management transitions allowed. */
		uint32_t reserved_6_7                : 2;
		uint32_t spd                         : 2;  /**< R/W - Speed allowed. */
		uint32_t reserved_3_3                : 1;
		uint32_t det                         : 3;  /**< R/W - Device-detection initialization. */
#else
		uint32_t det                         : 3;
		uint32_t reserved_3_3                : 1;
		uint32_t spd                         : 2;
		uint32_t reserved_6_7                : 2;
		uint32_t ipm                         : 2;
		uint32_t reserved_10_31              : 22;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_sctl_s    cn88xx; */
	/* struct bdk_satax_uahc_p0_sctl_s    cn88xxp1; */
} bdk_satax_uahc_p0_sctl_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SCTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SCTL(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000081000000012Cull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_SCTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_SCTL(...) bdk_satax_uahc_p0_sctl_t
#define bustype_BDK_SATAX_UAHC_P0_SCTL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_SCTL(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_SCTL(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_SCTL(...) "SATAX_UAHC_P0_SCTL"


/**
 * NCB32b - sata#_uahc_p0_serr
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_serr {
	uint32_t u;
	struct bdk_satax_uahc_p0_serr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_27_31              : 5;
		uint32_t diag_x                      : 1;  /**< R/W1C/H - Exchanged. */
		uint32_t diag_f                      : 1;  /**< R/W1C/H - Unknown FIS type. */
		uint32_t diag_t                      : 1;  /**< R/W1C/H - Transport state transition error. */
		uint32_t diag_s                      : 1;  /**< R/W1C/H - Link sequence error. */
		uint32_t diag_h                      : 1;  /**< R/W1C/H - Handshake error. */
		uint32_t diag_c                      : 1;  /**< R/W1C/H - CRC error. */
		uint32_t diag_d                      : 1;  /**< R/W1C/H - Disparity error. */
		uint32_t diag_b                      : 1;  /**< R/W1C/H - 10B to 8B decode error. */
		uint32_t diag_w                      : 1;  /**< R/W1C/H - COMWAKE detected. */
		uint32_t diag_i                      : 1;  /**< R/W1C/H - PHY internal error. */
		uint32_t diag_n                      : 1;  /**< R/W1C/H - PHY ready change. */
		uint32_t reserved_12_15              : 4;
		uint32_t err_e                       : 1;  /**< R/W1C/H - Internal error. */
		uint32_t err_p                       : 1;  /**< R/W1C/H - Protocol error. */
		uint32_t err_c                       : 1;  /**< R/W1C/H - Non-recovered persistent communication error. */
		uint32_t err_t                       : 1;  /**< R/W1C/H - Non-recovered transient data integrity error. */
		uint32_t reserved_2_7                : 6;
		uint32_t err_m                       : 1;  /**< R/W1C/H - Recovered communication error. */
		uint32_t err_i                       : 1;  /**< R/W1C/H - Recovered data integrity. */
#else
		uint32_t err_i                       : 1;
		uint32_t err_m                       : 1;
		uint32_t reserved_2_7                : 6;
		uint32_t err_t                       : 1;
		uint32_t err_c                       : 1;
		uint32_t err_p                       : 1;
		uint32_t err_e                       : 1;
		uint32_t reserved_12_15              : 4;
		uint32_t diag_n                      : 1;
		uint32_t diag_i                      : 1;
		uint32_t diag_w                      : 1;
		uint32_t diag_b                      : 1;
		uint32_t diag_d                      : 1;
		uint32_t diag_c                      : 1;
		uint32_t diag_h                      : 1;
		uint32_t diag_s                      : 1;
		uint32_t diag_t                      : 1;
		uint32_t diag_f                      : 1;
		uint32_t diag_x                      : 1;
		uint32_t reserved_27_31              : 5;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_serr_s    cn88xx; */
	/* struct bdk_satax_uahc_p0_serr_s    cn88xxp1; */
} bdk_satax_uahc_p0_serr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SERR(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000130ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_SERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_SERR(...) bdk_satax_uahc_p0_serr_t
#define bustype_BDK_SATAX_UAHC_P0_SERR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_SERR(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_SERR(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_SERR(...) "SATAX_UAHC_P0_SERR"


/**
 * NCB32b - sata#_uahc_p0_sig
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_sig {
	uint32_t u;
	struct bdk_satax_uahc_p0_sig_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t sig                         : 32; /**< RO/H - Signature. */
#else
		uint32_t sig                         : 32;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_sig_s     cn88xx; */
	/* struct bdk_satax_uahc_p0_sig_s     cn88xxp1; */
} bdk_satax_uahc_p0_sig_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SIG(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000124ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_SIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_SIG(...) bdk_satax_uahc_p0_sig_t
#define bustype_BDK_SATAX_UAHC_P0_SIG(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_SIG(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_SIG(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_SIG(...) "SATAX_UAHC_P0_SIG"


/**
 * NCB32b - sata#_uahc_p0_sntf
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_sntf {
	uint32_t u;
	struct bdk_satax_uahc_p0_sntf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t pmn                         : 16; /**< R/W1C/H - PM notify. */
#else
		uint32_t pmn                         : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_sntf_s    cn88xx; */
	/* struct bdk_satax_uahc_p0_sntf_s    cn88xxp1; */
} bdk_satax_uahc_p0_sntf_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SNTF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SNTF(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000081000000013Cull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_SNTF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_SNTF(...) bdk_satax_uahc_p0_sntf_t
#define bustype_BDK_SATAX_UAHC_P0_SNTF(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_SNTF(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_SNTF(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_SNTF(...) "SATAX_UAHC_P0_SNTF"


/**
 * NCB32b - sata#_uahc_p0_ssts
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_ssts {
	uint32_t u;
	struct bdk_satax_uahc_p0_ssts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t ipm                         : 4;  /**< RO/H - Interface power management. */
		uint32_t spd                         : 4;  /**< RO/H - Current interface speed. */
		uint32_t det                         : 4;  /**< RO/H - Device detection. */
#else
		uint32_t det                         : 4;
		uint32_t spd                         : 4;
		uint32_t ipm                         : 4;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_ssts_s    cn88xx; */
	/* struct bdk_satax_uahc_p0_ssts_s    cn88xxp1; */
} bdk_satax_uahc_p0_ssts_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SSTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SSTS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000128ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_SSTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_SSTS(...) bdk_satax_uahc_p0_ssts_t
#define bustype_BDK_SATAX_UAHC_P0_SSTS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_SSTS(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_SSTS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_SSTS(...) "SATAX_UAHC_P0_SSTS"


/**
 * NCB32b - sata#_uahc_p0_tfd
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 *
 */
typedef union bdk_satax_uahc_p0_tfd {
	uint32_t u;
	struct bdk_satax_uahc_p0_tfd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t tferr                       : 8;  /**< RO - Copy of task-file error register. */
		uint32_t sts                         : 8;  /**< RO/H - Copy of task-file status register. */
#else
		uint32_t sts                         : 8;
		uint32_t tferr                       : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_satax_uahc_p0_tfd_s     cn88xx; */
	/* struct bdk_satax_uahc_p0_tfd_s     cn88xxp1; */
} bdk_satax_uahc_p0_tfd_t;

static inline uint64_t BDK_SATAX_UAHC_P0_TFD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_TFD(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000000120ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UAHC_P0_TFD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UAHC_P0_TFD(...) bdk_satax_uahc_p0_tfd_t
#define bustype_BDK_SATAX_UAHC_P0_TFD(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SATAX_UAHC_P0_TFD(p1) (p1)
#define arguments_BDK_SATAX_UAHC_P0_TFD(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UAHC_P0_TFD(...) "SATAX_UAHC_P0_TFD"


/**
 * NCB - sata#_uctl_bist_status
 *
 * Results from BIST runs of SATA's memories.
 * Wait for NDONE==0, then look at defect indication.
 *
 * Accessible always.
 *
 * Reset by NCB reset.
 */
typedef union bdk_satax_uctl_bist_status {
	uint64_t u;
	struct bdk_satax_uctl_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t uctl_xm_r_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UCTL AxiMaster read-data FIFO. */
		uint64_t uctl_xm_w_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_36_39              : 4;
		uint64_t uahc_p0_rxram_bist_ndone    : 1;  /**< RO/H - BIST is not complete for the UAHC Port 0 RxFIFO RAM. */
		uint64_t reserved_34_34              : 1;
		uint64_t uahc_p0_txram_bist_ndone    : 1;  /**< RO/H - BIST is not complete for the UAHC Port 0 TxFIFO RAM. */
		uint64_t reserved_10_32              : 23;
		uint64_t uctl_xm_r_bist_status       : 1;  /**< RO/H - BIST status of the UCTL AxiMaster read-data FIFO. */
		uint64_t uctl_xm_w_bist_status       : 1;  /**< RO/H - BIST status of the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_4_7                : 4;
		uint64_t uahc_p0_rxram_bist_status   : 1;  /**< RO/H - BIST status of the UAHC Port0 RxFIFO RAM. */
		uint64_t reserved_2_2                : 1;
		uint64_t uahc_p0_txram_bist_status   : 1;  /**< RO/H - BIST status of the UAHC Port0 TxFIFO RAM. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t uahc_p0_txram_bist_status   : 1;
		uint64_t reserved_2_2                : 1;
		uint64_t uahc_p0_rxram_bist_status   : 1;
		uint64_t reserved_4_7                : 4;
		uint64_t uctl_xm_w_bist_status       : 1;
		uint64_t uctl_xm_r_bist_status       : 1;
		uint64_t reserved_10_32              : 23;
		uint64_t uahc_p0_txram_bist_ndone    : 1;
		uint64_t reserved_34_34              : 1;
		uint64_t uahc_p0_rxram_bist_ndone    : 1;
		uint64_t reserved_36_39              : 4;
		uint64_t uctl_xm_w_bist_ndone        : 1;
		uint64_t uctl_xm_r_bist_ndone        : 1;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_satax_uctl_bist_status_s cn88xx; */
	/* struct bdk_satax_uctl_bist_status_s cn88xxp1; */
} bdk_satax_uctl_bist_status_t;

static inline uint64_t BDK_SATAX_UCTL_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100008ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_BIST_STATUS(...) bdk_satax_uctl_bist_status_t
#define bustype_BDK_SATAX_UCTL_BIST_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_BIST_STATUS(p1) (p1)
#define arguments_BDK_SATAX_UCTL_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_BIST_STATUS(...) "SATAX_UCTL_BIST_STATUS"


/**
 * NCB - sata#_uctl_ctl
 *
 * This register controls clocks, resets, power, and BIST for the SATA.
 *
 * Accessible always.
 *
 * Reset by NCB reset.
 */
typedef union bdk_satax_uctl_ctl {
	uint64_t u;
	struct bdk_satax_uctl_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t clear_bist                  : 1;  /**< R/W - BIST fast-clear mode select. There are two major modes of BIST: FULL and CLEAR.
                                                                 0 = FULL BIST is run by the BIST state machine.
                                                                 1 = CLEAR BIST is run by the BIST state machine. A clear-BIST run clears all entries in
                                                                 SATA RAMs to 0x0.

                                                                 To avoid race conditions, software must first perform a CSR write operation that puts
                                                                 CLEAR_BIST into the correct state and then perform another CSR write operation to set
                                                                 START_BIST (keeping CLEAR_BIST constant). CLEAR BIST completion is indicated by
                                                                 SATA()_UCTL_BIST_STATUS[NDONE].

                                                                 A BIST clear operation takes almost 2,000 host-controller clock cycles for the largest
                                                                 RAM. */
		uint64_t start_bist                  : 1;  /**< R/W - Start BIST. The rising edge starts BIST on the memories in SATA. To run BIST, the host-
                                                                 controller clock must be both configured and enabled, and should be configured to the
                                                                 maximum available frequency given the available coprocessor clock and dividers.

                                                                 Refer to Cold Reset for clock initialization procedures. BIST defect status can be checked
                                                                 after FULL BIST completion, both of which are indicated in SATA_UCTL_BIST_STATUS. The FULL
                                                                 BIST run takes almost 80,000 host-controller clock cycles for the largest RAM. */
		uint64_t reserved_31_61              : 31;
		uint64_t a_clk_en                    : 1;  /**< R/W - Host-controller clock enable. When set to 1, the host-controller clock is generated. This
                                                                 also enables access to UCTL registers 0x30-0xF8. */
		uint64_t a_clk_byp_sel               : 1;  /**< R/W - Select the bypass input to the host-controller clock divider.
                                                                 0 = Use the divided coprocessor clock from the A_CLKDIV divider.
                                                                 1 = use the bypass clock from the GPIO pins (generally bypass is only used for scan
                                                                 purposes).

                                                                 This signal is a multiplexer-select signal; it does not enable the host-controller clock.
                                                                 You must set A_CLK_EN separately. A_CLK_BYP_SEL select should not be changed unless
                                                                 A_CLK_EN is disabled. The bypass clock can be selected and running even if the host-
                                                                 controller clock dividers are not running. */
		uint64_t a_clkdiv_rst                : 1;  /**< R/W - Host-controller-clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
		uint64_t reserved_27_27              : 1;
		uint64_t a_clkdiv_sel                : 3;  /**< R/W - The host-controller clock frequency is the coprocessor-clock frequency divided by
                                                                 A_CLKDIV_SEL. The host-controller clock frequency must be at or below 333MHz.
                                                                 This field can be changed only when A_CLKDIV_RST = 1. The divider values are the
                                                                 following:
                                                                 0x0 = divide by 1.
                                                                 0x1 = divide by 2.
                                                                 0x2 = divide by 3.
                                                                 0x3 = divide by 4.
                                                                 0x4 = divide by 6.
                                                                 0x5 = divide by 8.
                                                                 0x6 = divide by 16.
                                                                 0x7 = divide by 24. */
		uint64_t reserved_5_23               : 19;
		uint64_t csclk_en                    : 1;  /**< R/W - Turns on the SATA UCTL interface clock (coprocessor clock). This enables access to UAHC
                                                                 registers via the NCB, as well as UCTL registers starting from 0x10_0030. */
		uint64_t reserved_2_3                : 2;
		uint64_t sata_uahc_rst               : 1;  /**< R/W - Software reset; resets UAHC; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 or NCB protocols. */
		uint64_t sata_uctl_rst               : 1;  /**< R/W - Software reset; resets UCTL; active-high. Resets UAHC DMA and register shims and the UCTL
                                                                 registers 0x10_0030-0x10_00F8.

                                                                 It does not reset UCTL registers 0x10_0000-0x10_0028.

                                                                 The UCTL registers starting from 0x10_0030 can be accessed only after the host-controller
                                                                 clock is active and UCTL_RST is deasserted.

                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL, NCB, and GIB protocols. */
#else
		uint64_t sata_uctl_rst               : 1;
		uint64_t sata_uahc_rst               : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t csclk_en                    : 1;
		uint64_t reserved_5_23               : 19;
		uint64_t a_clkdiv_sel                : 3;
		uint64_t reserved_27_27              : 1;
		uint64_t a_clkdiv_rst                : 1;
		uint64_t a_clk_byp_sel               : 1;
		uint64_t a_clk_en                    : 1;
		uint64_t reserved_31_61              : 31;
		uint64_t start_bist                  : 1;
		uint64_t clear_bist                  : 1;
#endif
	} s;
	/* struct bdk_satax_uctl_ctl_s        cn88xx; */
	/* struct bdk_satax_uctl_ctl_s        cn88xxp1; */
} bdk_satax_uctl_ctl_t;

static inline uint64_t BDK_SATAX_UCTL_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_CTL(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100000ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_CTL(...) bdk_satax_uctl_ctl_t
#define bustype_BDK_SATAX_UCTL_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_CTL(p1) (p1)
#define arguments_BDK_SATAX_UCTL_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_CTL(...) "SATAX_UCTL_CTL"


/**
 * NCB - sata#_uctl_ecc
 *
 * This register can be used to disable ECC correction, insert ECC errors, and debug ECC
 * failures.
 *
 * Fields ECC_ERR* are captured when there are no outstanding ECC errors indicated in INTSTAT
 * and a new ECC error arrives. Prioritization for multiple events occurring on the same cycle is
 * indicated by the ECC_ERR_SOURCE enumeration: highest encoded value has highest priority.
 *
 * Fields *ECC_DIS: Disables ECC correction, SBE and DBE errors are still reported.
 * If ECC_DIS is 0x1, then no data-correction occurs.
 *
 * Fields *ECC_FLIP_SYND:  Flip the syndrom[1:0] bits to generate 1-bit/2-bits error for testing.
 *
 * Accessible only when SATA()_UCTL_CTL[A_CLK_EN].
 *
 * Reset by NCB reset or SATA()_UCTL_CTL[SATA_UCTL_RST].
 */
typedef union bdk_satax_uctl_ecc {
	uint64_t u;
	struct bdk_satax_uctl_ecc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_62_63              : 2;
		uint64_t ecc_err_source              : 4;  /**< RO/H - Source of ECC error, see UCTL_ECC_ERR_SOURCE_E. */
		uint64_t ecc_err_syndrome            : 18; /**< RO/H - Syndrome bits of the ECC error. */
		uint64_t ecc_err_address             : 8;  /**< RO/H - RAM address of the ECC error. */
		uint64_t reserved_21_31              : 11;
		uint64_t uctl_xm_r_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uctl_xm_r_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UCTL AxiMaster read-data FIFO. */
		uint64_t uctl_xm_w_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uctl_xm_w_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_9_14               : 6;
		uint64_t uahc_rx_ecc_flip_synd       : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uahc_rx_ecc_cor_dis         : 1;  /**< R/W - Enables ECC correction on UAHC RxFIFO RAMs. */
		uint64_t uahc_tx_ecc_flip_synd       : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uahc_tx_ecc_cor_dis         : 1;  /**< R/W - Enables ECC correction on UAHC TxFIFO RAMs. */
		uint64_t uahc_fb_ecc_flip_synd       : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uahc_fb_ecc_cor_dis         : 1;  /**< R/W - Enables ECC correction on UAHC FBS RAM. */
#else
		uint64_t uahc_fb_ecc_cor_dis         : 1;
		uint64_t uahc_fb_ecc_flip_synd       : 2;
		uint64_t uahc_tx_ecc_cor_dis         : 1;
		uint64_t uahc_tx_ecc_flip_synd       : 2;
		uint64_t uahc_rx_ecc_cor_dis         : 1;
		uint64_t uahc_rx_ecc_flip_synd       : 2;
		uint64_t reserved_9_14               : 6;
		uint64_t uctl_xm_w_ecc_cor_dis       : 1;
		uint64_t uctl_xm_w_ecc_flip_synd     : 2;
		uint64_t uctl_xm_r_ecc_cor_dis       : 1;
		uint64_t uctl_xm_r_ecc_flip_synd     : 2;
		uint64_t reserved_21_31              : 11;
		uint64_t ecc_err_address             : 8;
		uint64_t ecc_err_syndrome            : 18;
		uint64_t ecc_err_source              : 4;
		uint64_t reserved_62_63              : 2;
#endif
	} s;
	/* struct bdk_satax_uctl_ecc_s        cn88xx; */
	/* struct bdk_satax_uctl_ecc_s        cn88xxp1; */
} bdk_satax_uctl_ecc_t;

static inline uint64_t BDK_SATAX_UCTL_ECC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_ECC(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100001000F0ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_ECC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_ECC(...) bdk_satax_uctl_ecc_t
#define bustype_BDK_SATAX_UCTL_ECC(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_ECC(p1) (p1)
#define arguments_BDK_SATAX_UCTL_ECC(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_ECC(...) "SATAX_UCTL_ECC"


/**
 * NCB - sata#_uctl_intena_w1c
 */
typedef union bdk_satax_uctl_intena_w1c {
	uint64_t u;
	struct bdk_satax_uctl_intena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t uahc_rx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_rx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_tx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_tx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_fb_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC FBS memory. */
		uint64_t uahc_fb_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC FBS memory. */
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO. */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO. */
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates
                                                                 the assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see description in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE].

                                                                 The hardware does not translate the request correctly and results may violate NCB
                                                                 protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
#else
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t uahc_fb_sbe                 : 1;
		uint64_t uahc_fb_dbe                 : 1;
		uint64_t uahc_tx_sbe                 : 1;
		uint64_t uahc_tx_dbe                 : 1;
		uint64_t uahc_rx_sbe                 : 1;
		uint64_t uahc_rx_dbe                 : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_satax_uctl_intena_w1c_s cn88xx; */
	/* struct bdk_satax_uctl_intena_w1c_s cn88xxp1; */
} bdk_satax_uctl_intena_w1c_t;

static inline uint64_t BDK_SATAX_UCTL_INTENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTENA_W1C(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100040ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_INTENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_INTENA_W1C(...) bdk_satax_uctl_intena_w1c_t
#define bustype_BDK_SATAX_UCTL_INTENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_INTENA_W1C(p1) (p1)
#define arguments_BDK_SATAX_UCTL_INTENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_INTENA_W1C(...) "SATAX_UCTL_INTENA_W1C"


/**
 * NCB - sata#_uctl_intena_w1s
 */
typedef union bdk_satax_uctl_intena_w1s {
	uint64_t u;
	struct bdk_satax_uctl_intena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t uahc_rx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_rx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_tx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_tx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_fb_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC FBS memory. */
		uint64_t uahc_fb_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC FBS memory. */
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO. */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO. */
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates
                                                                 the assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see description in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE].

                                                                 The hardware does not translate the request correctly and results may violate NCB
                                                                 protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
#else
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t uahc_fb_sbe                 : 1;
		uint64_t uahc_fb_dbe                 : 1;
		uint64_t uahc_tx_sbe                 : 1;
		uint64_t uahc_tx_dbe                 : 1;
		uint64_t uahc_rx_sbe                 : 1;
		uint64_t uahc_rx_dbe                 : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_satax_uctl_intena_w1s_s cn88xx; */
	/* struct bdk_satax_uctl_intena_w1s_s cn88xxp1; */
} bdk_satax_uctl_intena_w1s_t;

static inline uint64_t BDK_SATAX_UCTL_INTENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTENA_W1S(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100048ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_INTENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_INTENA_W1S(...) bdk_satax_uctl_intena_w1s_t
#define bustype_BDK_SATAX_UCTL_INTENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_INTENA_W1S(p1) (p1)
#define arguments_BDK_SATAX_UCTL_INTENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_INTENA_W1S(...) "SATAX_UCTL_INTENA_W1S"


/**
 * NCB - sata#_uctl_intstat
 *
 * Summary of different bits of interrupts.
 *
 * Accessible always.
 *
 * Reset NCB reset.
 */
typedef union bdk_satax_uctl_intstat {
	uint64_t u;
	struct bdk_satax_uctl_intstat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t uahc_rx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_rx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_tx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_tx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_fb_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC FBS memory. */
		uint64_t uahc_fb_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC FBS memory. */
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO. */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO. */
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates
                                                                 the assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see description in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE].

                                                                 The hardware does not translate the request correctly and results may violate NCB
                                                                 protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
#else
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t uahc_fb_sbe                 : 1;
		uint64_t uahc_fb_dbe                 : 1;
		uint64_t uahc_tx_sbe                 : 1;
		uint64_t uahc_tx_dbe                 : 1;
		uint64_t uahc_rx_sbe                 : 1;
		uint64_t uahc_rx_dbe                 : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_satax_uctl_intstat_s    cn88xx; */
	/* struct bdk_satax_uctl_intstat_s    cn88xxp1; */
} bdk_satax_uctl_intstat_t;

static inline uint64_t BDK_SATAX_UCTL_INTSTAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTSTAT(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100030ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_INTSTAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_INTSTAT(...) bdk_satax_uctl_intstat_t
#define bustype_BDK_SATAX_UCTL_INTSTAT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_INTSTAT(p1) (p1)
#define arguments_BDK_SATAX_UCTL_INTSTAT(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_INTSTAT(...) "SATAX_UCTL_INTSTAT"


/**
 * NCB - sata#_uctl_intstat_w1s
 */
typedef union bdk_satax_uctl_intstat_w1s {
	uint64_t u;
	struct bdk_satax_uctl_intstat_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t uahc_rx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_rx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Rx FIFO. */
		uint64_t uahc_tx_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_tx_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Tx FIFO. */
		uint64_t uahc_fb_dbe                 : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC FBS memory. */
		uint64_t uahc_fb_sbe                 : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC FBS memory. */
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO. */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO. */
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates
                                                                 the assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see description in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE].

                                                                 The hardware does not translate the request correctly and results may violate NCB
                                                                 protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
#else
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t uahc_fb_sbe                 : 1;
		uint64_t uahc_fb_dbe                 : 1;
		uint64_t uahc_tx_sbe                 : 1;
		uint64_t uahc_tx_dbe                 : 1;
		uint64_t uahc_rx_sbe                 : 1;
		uint64_t uahc_rx_dbe                 : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_satax_uctl_intstat_w1s_s cn88xx; */
	/* struct bdk_satax_uctl_intstat_w1s_s cn88xxp1; */
} bdk_satax_uctl_intstat_w1s_t;

static inline uint64_t BDK_SATAX_UCTL_INTSTAT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTSTAT_W1S(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100038ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_INTSTAT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_INTSTAT_W1S(...) bdk_satax_uctl_intstat_w1s_t
#define bustype_BDK_SATAX_UCTL_INTSTAT_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_INTSTAT_W1S(p1) (p1)
#define arguments_BDK_SATAX_UCTL_INTSTAT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_INTSTAT_W1S(...) "SATAX_UCTL_INTSTAT_W1S"


/**
 * NCB - sata#_uctl_shim_cfg
 *
 * This register allows configuration of various shim (UCTL) features.
 *
 * Fields XS_NCB_OOB_* are captured when there are no outstanding OOB errors indicated in INTSTAT
 * and a new OOB error arrives.
 *
 * Fields XS_BAD_DMA_* are captured when there are no outstanding DMA errors indicated in INTSTAT
 * and a new DMA error arrives.
 *
 * Accessible only when SATA()_UCTL_CTL[A_CLK_EN].
 *
 * Reset by NCB reset or SATA()_UCTL_CTL[SATA_UCTL_RST].
 */
typedef union bdk_satax_uctl_shim_cfg {
	uint64_t u;
	struct bdk_satax_uctl_shim_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t xs_ncb_oob_wrn              : 1;  /**< RO/H - Read/write error log for out-of-bound UAHC register access.
                                                                 0 = read, 1 = write. */
		uint64_t reserved_60_62              : 3;
		uint64_t xs_ncb_oob_osrc             : 12; /**< RO/H - SRCID error log for out-of-bound UAHC register access. The NCB outbound SRCID for the OOB
                                                                 error.
                                                                 \<59:58\> = chipID.
                                                                 \<57\> = Request source: 0 = core, 1 = NCB-device.
                                                                 \<56:51\> = core/NCB-device number. Note that for NCB devices, \<56\> is always 0.
                                                                 \<50:48\> = SubID. */
		uint64_t xm_bad_dma_wrn              : 1;  /**< RO/H - Read/write error log for bad DMA access from UAHC.
                                                                 0 = read error log, 1 = write error log. */
		uint64_t reserved_44_46              : 3;
		uint64_t xm_bad_dma_type             : 4;  /**< RO/H - ErrType error log for bad DMA access from UAHC. Encodes the type of error encountered
                                                                 (error largest encoded value has priority). See SATA_UCTL_XM_BAD_DMA_TYPE_E. */
		uint64_t reserved_14_39              : 26;
		uint64_t dma_read_cmd                : 2;  /**< R/W - Selects the NCB read command used by DMA accesses. See SATA_UCTL_DMA_READ_CMD_E. */
		uint64_t reserved_11_11              : 1;
		uint64_t dma_write_cmd               : 1;  /**< R/W - Selects the NCB write command used by DMA accesses. See enum SATA_UCTL_DMA_WRITE_CMD_E. */
		uint64_t reserved_0_9                : 10;
#else
		uint64_t reserved_0_9                : 10;
		uint64_t dma_write_cmd               : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t dma_read_cmd                : 2;
		uint64_t reserved_14_39              : 26;
		uint64_t xm_bad_dma_type             : 4;
		uint64_t reserved_44_46              : 3;
		uint64_t xm_bad_dma_wrn              : 1;
		uint64_t xs_ncb_oob_osrc             : 12;
		uint64_t reserved_60_62              : 3;
		uint64_t xs_ncb_oob_wrn              : 1;
#endif
	} s;
	/* struct bdk_satax_uctl_shim_cfg_s   cn88xx; */
	/* struct bdk_satax_uctl_shim_cfg_s   cn88xxp1; */
} bdk_satax_uctl_shim_cfg_t;

static inline uint64_t BDK_SATAX_UCTL_SHIM_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_SHIM_CFG(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100001000E8ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_SHIM_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_SHIM_CFG(...) bdk_satax_uctl_shim_cfg_t
#define bustype_BDK_SATAX_UCTL_SHIM_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_SHIM_CFG(p1) (p1)
#define arguments_BDK_SATAX_UCTL_SHIM_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_SHIM_CFG(...) "SATAX_UCTL_SHIM_CFG"


/**
 * NCB - sata#_uctl_spare0
 *
 * This register is spare.
 *
 * Accessible always.
 *
 * Reset NCB reset.
 */
typedef union bdk_satax_uctl_spare0 {
	uint64_t u;
	struct bdk_satax_uctl_spare0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_satax_uctl_spare0_s     cn88xx; */
	/* struct bdk_satax_uctl_spare0_s     cn88xxp1; */
} bdk_satax_uctl_spare0_t;

static inline uint64_t BDK_SATAX_UCTL_SPARE0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_SPARE0(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000810000100010ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_SPARE0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_SPARE0(...) bdk_satax_uctl_spare0_t
#define bustype_BDK_SATAX_UCTL_SPARE0(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_SPARE0(p1) (p1)
#define arguments_BDK_SATAX_UCTL_SPARE0(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_SPARE0(...) "SATAX_UCTL_SPARE0"


/**
 * NCB - sata#_uctl_spare1
 *
 * This register is spare.
 *
 * Accessible only when SATA()_UCTL_CTL[A_CLK_EN].
 *
 * Reset by NCB reset or SATA()_UCTL_CTL[SATA_UCTL_RST].
 */
typedef union bdk_satax_uctl_spare1 {
	uint64_t u;
	struct bdk_satax_uctl_spare1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_satax_uctl_spare1_s     cn88xx; */
	/* struct bdk_satax_uctl_spare1_s     cn88xxp1; */
} bdk_satax_uctl_spare1_t;

static inline uint64_t BDK_SATAX_UCTL_SPARE1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_SPARE1(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x00008100001000F8ull + (param1 & 15) * 0x1000000000ull;
	csr_fatal("BDK_SATAX_UCTL_SPARE1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SATAX_UCTL_SPARE1(...) bdk_satax_uctl_spare1_t
#define bustype_BDK_SATAX_UCTL_SPARE1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SATAX_UCTL_SPARE1(p1) (p1)
#define arguments_BDK_SATAX_UCTL_SPARE1(p1) (p1),-1,-1,-1
#define basename_BDK_SATAX_UCTL_SPARE1(...) "SATAX_UCTL_SPARE1"

#endif /* __BDK_CSRS_SATA__ */
