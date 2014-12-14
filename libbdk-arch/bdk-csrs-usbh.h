#ifndef __BDK_CSRS_USBH__
#define __BDK_CSRS_USBH__
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
 * Cavium USBH.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration UCTL_DMA_READ_CMD_E
 *
 * UCTL DMA Read Command Enumeration
 * Enumerate NCB inbound command selections for DMA read operations.
 */
enum uctl_dma_read_cmd_e {
	UCTL_DMA_READ_CMD_E_LDI = 0x0,
	UCTL_DMA_READ_CMD_E_LDT = 0x1,
	UCTL_DMA_READ_CMD_E_LDY = 0x2,
	UCTL_DMA_READ_CMD_E_ENUM_LAST = 0x3,
};

/**
 * Enumeration UCTL_DMA_WRITE_CMD_E
 *
 * UCTL DMA Write Command Enumeration
 * Enumerate NCB inbound command selections for DMA write operations.
 */
enum uctl_dma_write_cmd_e {
	UCTL_DMA_WRITE_CMD_E_RSTP = 0x1,
	UCTL_DMA_WRITE_CMD_E_STP = 0x0,
	UCTL_DMA_WRITE_CMD_E_ENUM_LAST = 0x2,
};

/**
 * Enumeration UCTL_ECC_ERR_SOURCE_E
 *
 * UCTL ECC Error Source Enumeration
 * Enumerate sources of ECC error log information.
 */
enum uctl_ecc_err_source_e {
	UCTL_ECC_ERR_SOURCE_E_NONE = 0x0,
	UCTL_ECC_ERR_SOURCE_E_RAM0_DBE = 0xf,
	UCTL_ECC_ERR_SOURCE_E_RAM0_SBE = 0x7,
	UCTL_ECC_ERR_SOURCE_E_RAM1_DBE = 0xe,
	UCTL_ECC_ERR_SOURCE_E_RAM1_SBE = 0x6,
	UCTL_ECC_ERR_SOURCE_E_RAM2_DBE = 0xd,
	UCTL_ECC_ERR_SOURCE_E_RAM2_SBE = 0x5,
	UCTL_ECC_ERR_SOURCE_E_XM_R_DBE = 0xa,
	UCTL_ECC_ERR_SOURCE_E_XM_R_SBE = 0x2,
	UCTL_ECC_ERR_SOURCE_E_XM_W_DBE = 0x9,
	UCTL_ECC_ERR_SOURCE_E_XM_W_SBE = 0x1,
	UCTL_ECC_ERR_SOURCE_E_ENUM_LAST = 0x10,
};

/**
 * Enumeration UCTL_ENDIAN_MODE_E
 *
 * UCTL Endian-Mode Enumeration
 * Enumerate endian mode selections.
 */
enum uctl_endian_mode_e {
	UCTL_ENDIAN_MODE_E_BIG = 0x1,
	UCTL_ENDIAN_MODE_E_LITTLE = 0x0,
	UCTL_ENDIAN_MODE_E_RSVD2 = 0x2,
	UCTL_ENDIAN_MODE_E_RSVD3 = 0x3,
	UCTL_ENDIAN_MODE_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration UCTL_XM_BAD_DMA_TYPE_E
 *
 * UCTL XM Bad DMA Type Enumeration
 * Enumerate type of DMA error seen.
 */
enum uctl_xm_bad_dma_type_e {
	UCTL_XM_BAD_DMA_TYPE_E_ADDR_OOB = 0x1,
	UCTL_XM_BAD_DMA_TYPE_E_LEN_GT_16 = 0x2,
	UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_BYTE = 0x3,
	UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_HALFWORD = 0x4,
	UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_WORD = 0x5,
	UCTL_XM_BAD_DMA_TYPE_E_NONE = 0x0,
	UCTL_XM_BAD_DMA_TYPE_E_ENUM_LAST = 0x6,
};

/**
 * Enumeration USBH_INT_VEC_E
 *
 * USBH MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum usbh_int_vec_e {
	USBH_INT_VEC_E_UAHC_IMAN_IP = 0x2,
	USBH_INT_VEC_E_UAHC_USBSTS_HSE = 0x0,
	USBH_INT_VEC_E_UAHC_USBSTS_HSE_CLEAR = 0x1,
	USBH_INT_VEC_E_UCTL_INTSTAT = 0x3,
	USBH_INT_VEC_E_ENUM_LAST = 0x4,
};



/**
 * NCB - usbh#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the USBH_INT_VEC_E enumeration.
 *
 */
typedef union bdk_usbhx_msix_pbax {
	uint64_t u;
	struct bdk_usbhx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated USBH_MSIX_VEC()_CTL, enumerated by USBH_INT_VEC_E.
                                                                 Bits that have no associated USBH_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_usbhx_msix_pbax_s       cn88xx; */
	/* struct bdk_usbhx_msix_pbax_s       cn88xxp1; */
} bdk_usbhx_msix_pbax_t;

static inline uint64_t BDK_USBHX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x00008680002F0000ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_MSIX_PBAX(...) bdk_usbhx_msix_pbax_t
#define bustype_BDK_USBHX_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_USBHX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_MSIX_PBAX(...) "USBHX_MSIX_PBAX"


/**
 * NCB - usbh#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the USBH_INT_VEC_E enumeration.
 *
 */
typedef union bdk_usbhx_msix_vecx_addr {
	uint64_t u;
	struct bdk_usbhx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's USBH()_MSIX_VEC()_ADDR, USBH()_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of USBH()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_USBH()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_usbhx_msix_vecx_addr_s  cn88xx; */
	/* struct bdk_usbhx_msix_vecx_addr_s  cn88xxp1; */
} bdk_usbhx_msix_vecx_addr_t;

static inline uint64_t BDK_USBHX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x0000868000200000ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_USBHX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_MSIX_VECX_ADDR(...) bdk_usbhx_msix_vecx_addr_t
#define bustype_BDK_USBHX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_USBHX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_MSIX_VECX_ADDR(...) "USBHX_MSIX_VECX_ADDR"


/**
 * NCB - usbh#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the USBH_INT_VEC_E enumeration.
 *
 */
typedef union bdk_usbhx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_usbhx_msix_vecx_ctl_s {
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
	/* struct bdk_usbhx_msix_vecx_ctl_s   cn88xx; */
	/* struct bdk_usbhx_msix_vecx_ctl_s   cn88xxp1; */
} bdk_usbhx_msix_vecx_ctl_t;

static inline uint64_t BDK_USBHX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x0000868000200008ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_USBHX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_MSIX_VECX_CTL(...) bdk_usbhx_msix_vecx_ctl_t
#define bustype_BDK_USBHX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_USBHX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_MSIX_VECX_CTL(...) "USBHX_MSIX_VECX_CTL"


/**
 * NCB32b - usbh#_uahc_caplength
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.1.
 *
 */
typedef union bdk_usbhx_uahc_caplength {
	uint32_t u;
	struct bdk_usbhx_uahc_caplength_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t hciversion                  : 16; /**< RO - Host controller interface version number. */
		uint32_t reserved_8_15               : 8;
		uint32_t caplength                   : 8;  /**< RO - Capability registers length. */
#else
		uint32_t caplength                   : 8;
		uint32_t reserved_8_15               : 8;
		uint32_t hciversion                  : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_caplength_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t hciversion                  : 16; /**< RO - Host controller interface version number. */
		uint32_t reserved_15_8               : 8;
		uint32_t caplength                   : 8;  /**< RO - Capability registers length. */
#else
		uint32_t caplength                   : 8;
		uint32_t reserved_15_8               : 8;
		uint32_t hciversion                  : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_caplength_cn88xx cn88xxp1;
} bdk_usbhx_uahc_caplength_t;

static inline uint64_t BDK_USBHX_UAHC_CAPLENGTH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_CAPLENGTH(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000000ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_CAPLENGTH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_CAPLENGTH(...) bdk_usbhx_uahc_caplength_t
#define bustype_BDK_USBHX_UAHC_CAPLENGTH(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_CAPLENGTH(p1) (p1)
#define arguments_BDK_USBHX_UAHC_CAPLENGTH(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_CAPLENGTH(...) "USBHX_UAHC_CAPLENGTH"


/**
 * NCB32b - usbh#_uahc_config
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.7.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_config {
	uint32_t u;
	struct bdk_usbhx_uahc_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t maxslotsen                  : 8;  /**< R/W - Maximum device slots enabled. */
#else
		uint32_t maxslotsen                  : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	struct bdk_usbhx_uahc_config_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_8               : 24;
		uint32_t maxslotsen                  : 8;  /**< R/W - Maximum device slots enabled. */
#else
		uint32_t maxslotsen                  : 8;
		uint32_t reserved_31_8               : 24;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_config_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_config_t;

static inline uint64_t BDK_USBHX_UAHC_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_CONFIG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000058ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_CONFIG(...) bdk_usbhx_uahc_config_t
#define bustype_BDK_USBHX_UAHC_CONFIG(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_CONFIG(p1) (p1)
#define arguments_BDK_USBHX_UAHC_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_CONFIG(...) "USBHX_UAHC_CONFIG"


/**
 * NCB - usbh#_uahc_crcr
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.5.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_crcr {
	uint64_t u;
	struct bdk_usbhx_uahc_crcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cmd_ring_ptr                : 58; /**< WO - Command ring pointer. */
		uint64_t reserved_4_5                : 2;
		uint64_t crr                         : 1;  /**< RO/H - Command ring running. */
		uint64_t ca                          : 1;  /**< WO - Command abort. */
		uint64_t cs                          : 1;  /**< WO - Command stop. */
		uint64_t rcs                         : 1;  /**< WO - Ring cycle state. */
#else
		uint64_t rcs                         : 1;
		uint64_t cs                          : 1;
		uint64_t ca                          : 1;
		uint64_t crr                         : 1;
		uint64_t reserved_4_5                : 2;
		uint64_t cmd_ring_ptr                : 58;
#endif
	} s;
	struct bdk_usbhx_uahc_crcr_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cmd_ring_ptr                : 58; /**< WO - Command ring pointer. */
		uint64_t reserved_5_4                : 2;
		uint64_t crr                         : 1;  /**< RO/H - Command ring running. */
		uint64_t ca                          : 1;  /**< WO - Command abort. */
		uint64_t cs                          : 1;  /**< WO - Command stop. */
		uint64_t rcs                         : 1;  /**< WO - Ring cycle state. */
#else
		uint64_t rcs                         : 1;
		uint64_t cs                          : 1;
		uint64_t ca                          : 1;
		uint64_t crr                         : 1;
		uint64_t reserved_5_4                : 2;
		uint64_t cmd_ring_ptr                : 58;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_crcr_cn88xx     cn88xxp1;
} bdk_usbhx_uahc_crcr_t;

static inline uint64_t BDK_USBHX_UAHC_CRCR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_CRCR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000038ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_CRCR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_CRCR(...) bdk_usbhx_uahc_crcr_t
#define bustype_BDK_USBHX_UAHC_CRCR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_CRCR(p1) (p1)
#define arguments_BDK_USBHX_UAHC_CRCR(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_CRCR(...) "USBHX_UAHC_CRCR"


/**
 * NCB32b - usbh#_uahc_db#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.6.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 *
 * INTERNAL: xHCI spec, page 32: there are USBH()_UAHC_HCSPARAMS1[MAXSLOTS]+1 doorbell registers.
 */
typedef union bdk_usbhx_uahc_dbx {
	uint32_t u;
	struct bdk_usbhx_uahc_dbx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dbstreamid                  : 16; /**< WO - Doorbell stream ID. */
		uint32_t reserved_8_15               : 8;
		uint32_t dbtarget                    : 8;  /**< WO - Doorbell target. */
#else
		uint32_t dbtarget                    : 8;
		uint32_t reserved_8_15               : 8;
		uint32_t dbstreamid                  : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_dbx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dbstreamid                  : 16; /**< WO - Doorbell stream ID. */
		uint32_t reserved_15_8               : 8;
		uint32_t dbtarget                    : 8;  /**< WO - Doorbell target. */
#else
		uint32_t dbtarget                    : 8;
		uint32_t reserved_15_8               : 8;
		uint32_t dbstreamid                  : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_dbx_cn88xx      cn88xxp1;
} bdk_usbhx_uahc_dbx_t;

static inline uint64_t BDK_USBHX_UAHC_DBX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_DBX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 64)))
		return 0x0000868000000480ull + (param1 & 1) * 0x1000000000ull + (param2 & 127) * 0x4ull;
	csr_fatal("BDK_USBHX_UAHC_DBX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_DBX(...) bdk_usbhx_uahc_dbx_t
#define bustype_BDK_USBHX_UAHC_DBX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_DBX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_DBX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_DBX(...) "USBHX_UAHC_DBX"


/**
 * NCB32b - usbh#_uahc_dboff
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.7.
 *
 */
typedef union bdk_usbhx_uahc_dboff {
	uint32_t u;
	struct bdk_usbhx_uahc_dboff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dboff                       : 30; /**< RO - Doorbell array offset. */
		uint32_t reserved_0_1                : 2;
#else
		uint32_t reserved_0_1                : 2;
		uint32_t dboff                       : 30;
#endif
	} s;
	struct bdk_usbhx_uahc_dboff_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dboff                       : 30; /**< RO - Doorbell array offset. */
		uint32_t reserved_1_0                : 2;
#else
		uint32_t reserved_1_0                : 2;
		uint32_t dboff                       : 30;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_dboff_cn88xx    cn88xxp1;
} bdk_usbhx_uahc_dboff_t;

static inline uint64_t BDK_USBHX_UAHC_DBOFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_DBOFF(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000014ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_DBOFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_DBOFF(...) bdk_usbhx_uahc_dboff_t
#define bustype_BDK_USBHX_UAHC_DBOFF(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_DBOFF(p1) (p1)
#define arguments_BDK_USBHX_UAHC_DBOFF(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_DBOFF(...) "USBHX_UAHC_DBOFF"


/**
 * NCB - usbh#_uahc_dcbaap
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.6.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_dcbaap {
	uint64_t u;
	struct bdk_usbhx_uahc_dcbaap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dcbaap                      : 58; /**< R/W - Device context base address array pointer. */
		uint64_t reserved_0_5                : 6;
#else
		uint64_t reserved_0_5                : 6;
		uint64_t dcbaap                      : 58;
#endif
	} s;
	struct bdk_usbhx_uahc_dcbaap_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dcbaap                      : 58; /**< R/W - Device context base address array pointer. */
		uint64_t reserved_5_0                : 6;
#else
		uint64_t reserved_5_0                : 6;
		uint64_t dcbaap                      : 58;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_dcbaap_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_dcbaap_t;

static inline uint64_t BDK_USBHX_UAHC_DCBAAP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_DCBAAP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000050ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_DCBAAP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_DCBAAP(...) bdk_usbhx_uahc_dcbaap_t
#define bustype_BDK_USBHX_UAHC_DCBAAP(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_DCBAAP(p1) (p1)
#define arguments_BDK_USBHX_UAHC_DCBAAP(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_DCBAAP(...) "USBHX_UAHC_DCBAAP"


/**
 * NCB32b - usbh#_uahc_dnctrl
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.4.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_dnctrl {
	uint32_t u;
	struct bdk_usbhx_uahc_dnctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t n                           : 16; /**< R/W - Notification enable. */
#else
		uint32_t n                           : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_dnctrl_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_16              : 16;
		uint32_t n                           : 16; /**< R/W - Notification enable. */
#else
		uint32_t n                           : 16;
		uint32_t reserved_31_16              : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_dnctrl_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_dnctrl_t;

static inline uint64_t BDK_USBHX_UAHC_DNCTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_DNCTRL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000034ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_DNCTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_DNCTRL(...) bdk_usbhx_uahc_dnctrl_t
#define bustype_BDK_USBHX_UAHC_DNCTRL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_DNCTRL(p1) (p1)
#define arguments_BDK_USBHX_UAHC_DNCTRL(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_DNCTRL(...) "USBHX_UAHC_DNCTRL"


/**
 * NCB - usbh#_uahc_erdp#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.3.3.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_erdpx {
	uint64_t u;
	struct bdk_usbhx_uahc_erdpx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t erdp                        : 60; /**< R/W - Event ring dequeue pointer bits \<63:4\>. */
		uint64_t ehb                         : 1;  /**< R/W1C/H - Event handler busy */
		uint64_t desi                        : 3;  /**< R/W - Dequeue ERST segment index. */
#else
		uint64_t desi                        : 3;
		uint64_t ehb                         : 1;
		uint64_t erdp                        : 60;
#endif
	} s;
	/* struct bdk_usbhx_uahc_erdpx_s      cn88xx; */
	/* struct bdk_usbhx_uahc_erdpx_s      cn88xxp1; */
} bdk_usbhx_uahc_erdpx_t;

static inline uint64_t BDK_USBHX_UAHC_ERDPX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_ERDPX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000478ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_ERDPX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_ERDPX(...) bdk_usbhx_uahc_erdpx_t
#define bustype_BDK_USBHX_UAHC_ERDPX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_ERDPX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_ERDPX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_ERDPX(...) "USBHX_UAHC_ERDPX"


/**
 * NCB - usbh#_uahc_erstba#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.3.2.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_erstbax {
	uint64_t u;
	struct bdk_usbhx_uahc_erstbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t erstba                      : 58; /**< R/W - Event-ring segment-table base-address bits\<63:6\>. */
		uint64_t reserved_0_5                : 6;
#else
		uint64_t reserved_0_5                : 6;
		uint64_t erstba                      : 58;
#endif
	} s;
	struct bdk_usbhx_uahc_erstbax_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t erstba                      : 58; /**< R/W - Event-ring segment-table base-address bits\<63:6\>. */
		uint64_t reserved_5_0                : 6;
#else
		uint64_t reserved_5_0                : 6;
		uint64_t erstba                      : 58;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_erstbax_cn88xx  cn88xxp1;
} bdk_usbhx_uahc_erstbax_t;

static inline uint64_t BDK_USBHX_UAHC_ERSTBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_ERSTBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000470ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_ERSTBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_ERSTBAX(...) bdk_usbhx_uahc_erstbax_t
#define bustype_BDK_USBHX_UAHC_ERSTBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_ERSTBAX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_ERSTBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_ERSTBAX(...) "USBHX_UAHC_ERSTBAX"


/**
 * NCB32b - usbh#_uahc_erstsz#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.3.1.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_erstszx {
	uint32_t u;
	struct bdk_usbhx_uahc_erstszx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t erstsz                      : 16; /**< R/W - Event-ring segment-table size. */
#else
		uint32_t erstsz                      : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_erstszx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_16              : 16;
		uint32_t erstsz                      : 16; /**< R/W - Event-ring segment-table size. */
#else
		uint32_t erstsz                      : 16;
		uint32_t reserved_31_16              : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_erstszx_cn88xx  cn88xxp1;
} bdk_usbhx_uahc_erstszx_t;

static inline uint64_t BDK_USBHX_UAHC_ERSTSZX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_ERSTSZX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000468ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_ERSTSZX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_ERSTSZX(...) bdk_usbhx_uahc_erstszx_t
#define bustype_BDK_USBHX_UAHC_ERSTSZX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_ERSTSZX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_ERSTSZX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_ERSTSZX(...) "USBHX_UAHC_ERSTSZX"


/**
 * NCB - usbh#_uahc_gbuserraddr
 *
 * When the AXI Master Bus returns Error response, the SoC Bus Error is generated. In the host
 * mode, the host_system_err port indicates this condition. In addition, it is also indicated in
 * USBH()_UAHC_USBSTS[HSE]. Due to the nature of AXI, it is possible that multiple AXI
 * transactions
 * are active at a time. The host controller does not keep track of the start address of all
 * outstanding transactions. Instead, it keeps track of the start address of the DMA transfer
 * associated with all active transactions. It is this address that is reported in
 * USBH()_UAHC_GBUSERRADDR when a bus error occurs. For example, if the host controller initiates
 * a DMA
 * transfer to write 1k of packet data starting at buffer address 0xABCD0000, and this DMA is
 * broken up into multiple 256B bursts on the AXI, then if a bus error occurs on any of these
 * associated AXI transfers, USBH()_UAHC_GBUSERRADDR reflects the DMA start address of 0xABCD0000
 * regardless of which AXI transaction received the error.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.12.
 */
typedef union bdk_usbhx_uahc_gbuserraddr {
	uint64_t u;
	struct bdk_usbhx_uahc_gbuserraddr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t busaddr                     : 64; /**< RO/H - Bus address. Contains the first bus address that encountered an SoC bus error. It is valid
                                                                 when the USBH()_UAHC_GSTS[BUSERRADDRVLD] = 1. It can only be cleared by resetting the
                                                                 core. */
#else
		uint64_t busaddr                     : 64;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gbuserraddr_s cn88xx; */
	/* struct bdk_usbhx_uahc_gbuserraddr_s cn88xxp1; */
} bdk_usbhx_uahc_gbuserraddr_t;

static inline uint64_t BDK_USBHX_UAHC_GBUSERRADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GBUSERRADDR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C130ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GBUSERRADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GBUSERRADDR(...) bdk_usbhx_uahc_gbuserraddr_t
#define bustype_BDK_USBHX_UAHC_GBUSERRADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_GBUSERRADDR(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GBUSERRADDR(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GBUSERRADDR(...) "USBHX_UAHC_GBUSERRADDR"


/**
 * NCB32b - usbh#_uahc_gctl
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.5.
 */
typedef union bdk_usbhx_uahc_gctl {
	uint32_t u;
	struct bdk_usbhx_uahc_gctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pwrdnscale                  : 13; /**< R/W - Power down scale. The USB3 suspend-clock input replaces pipe3_rx_pclk as a clock source to
                                                                 a small part of the USB3 core that operates when the SuperSpeed PHY is in its lowest power
                                                                 (P3) state, and therefore does not provide a clock. This field specifies how many suspend-
                                                                 clock periods fit into a 16 kHz clock period. When performing the division, round up the
                                                                 remainder.

                                                                 For example, when using an 32-bit PHY and 25-MHz suspend clock, PWRDNSCALE = 25000 kHz/16
                                                                 kHz = 1563 (rounded up).

                                                                 The minimum suspend-clock frequency is 32 KHz, and maximum suspend-clock frequency is 125
                                                                 MHz.

                                                                 The LTSSM uses Suspend clock for 12-ms and 100-ms timers during suspend mode. According to
                                                                 the USB 3.0 specification, the accuracy on these timers is 0% to +50%. 12 ms + 0~+50%
                                                                 accuracy = 18 ms (Range is 12 ms - 18 ms)
                                                                 100 ms + 0~+50% accuracy = 150 ms (Range is 100 ms - 150 ms).

                                                                 The suspend clock accuracy requirement is:
                                                                 _ (12,000/62.5) * (GCTL[31:19]) * actual suspend_clk_period should be between 12,000 and
                                                                 18,000
                                                                 _ (100,000/62.5) * (GCTL[31:19]) * actual suspend_clk_period should be between 100,000 and
                                                                 150,000

                                                                 For example, if your suspend_clk frequency varies from 7.5 MHz to 10.5MHz, then the value
                                                                 needs to programmed is: Power Down Scale = 10500/16 = 657 (rounded up; and fastest
                                                                 frequency used). */
		uint32_t masterfiltbypass            : 1;  /**< R/W - Master filter bypass. Not relevant for Cavium's configuration. */
		uint32_t reserved_16_17              : 2;
		uint32_t frmscldwn                   : 2;  /**< R/W - Frame scale down. Scales down device view of a SOF/USOF/ITP duration.
                                                                 For SuperSpeed/high-speed mode:
                                                                 0x0 = Interval is 125 us.
                                                                 0x1 = Interval is 62.5 us.
                                                                 0x2 = Interval is 31.25 us.
                                                                 0x3 = Interval is 15.625 us.

                                                                 For full-speed mode, the scale-down value is multiplied by 8. */
		uint32_t prtcapdir                   : 2;  /**< R/W - Port capability direction. Always keep set to 0x1. */
		uint32_t coresoftreset               : 1;  /**< R/W - Core soft reset: 1 = soft reset to core, 0 = no soft reset.
                                                                 Clears the interrupts and all the USBH()_UAHC_* CSRs except the
                                                                 following registers: USBH()_UAHC_GCTL, USBH()_UAHC_GUCTL, USBH()_UAHC_GSTS,
                                                                 USBH()_UAHC_GRLSID, USBH()_UAHC_GGPIO, USBH()_UAHC_GUID, USBH()_UAHC_GUSB2PHYCFG(),
                                                                 USBH()_UAHC_GUSB3PIPECTL().

                                                                 When you reset PHYs (using USBH()_UAHC_GUSB2PHYCFG() or USBH()_UAHC_GUSB3PIPECTL()), you
                                                                 must keep the
                                                                 core in reset state until PHY clocks are stable. This controls the bus, RAM, and MAC
                                                                 domain resets.

                                                                 INTERNAL: Refer to Reset Generation on Synopsys Databook page 250.
                                                                 Under soft reset, accesses to USBH()_UAHC_* CSRs other than USBH()_UAHC_GCTL may fail
                                                                 (timeout).
                                                                 This bit is for debug purposes only. Use USBH()_UAHC_USBCMD[HCRST] for soft reset. */
		uint32_t sofitpsync                  : 1;  /**< R/W - Synchronize ITP to reference clock. In host mode, if this bit is set to:
                                                                 0 = The core keeps the UTMI/ULPI PHY on the first port in non-suspended state whenever
                                                                 there is a SuperSpeed port that is not in Rx.Detect, SS.Disable, and U3 state.
                                                                 1 = The core keeps the UTMI/ULPI PHY on the first port in non-suspended state whenever the
                                                                 other non-SuperSpeed ports are not in suspended state.

                                                                 This feature is useful because it saves power by suspending UTMI/ULPI when SuperSpeed only
                                                                 is active and it helps resolve when the PHY does not transmit a host resume unless it is
                                                                 placed in suspend state.
                                                                 USBH()_UAHC_GUSB2PHYCFG()[SUSPHY] eventually decides to put the UTMI/ULPI PHY in to
                                                                 suspend
                                                                 state. In addition, when this bit is set to 1, the core generates ITP off of the REF_CLK-
                                                                 based counter. Otherwise, ITP and SOF are generated off of UTMI/ULPI_CLK[0] based counter.

                                                                 To program the reference clock period inside the core, refer to
                                                                 USBH()_UAHC_GUCTL[REFCLKPER].

                                                                 If you do not plan to ever use this feature or the
                                                                 USBH()_UAHC_GFLADJ[GFLADJ_REFCLK_LPM_SEL]
                                                                 feature, the minimum frequency for the ref_clk can be as low as 32KHz. You can connect the
                                                                 SUSPEND_CLK (as low as 32 KHz) to REF_CLK.

                                                                 If you plan to enable hardware-based LPM (PORTPMSC[HLE] = 1), this feature cannot be used.
                                                                 Turn off this feature by setting this bit to zero and use the
                                                                 USBH()_UAHC_GFLADJ[GFLADJ_REFCLK_LPM_SEL] feature.

                                                                 If you set this bit to 1, the USBH()_UAHC_GUSB2PHYCFG() [U2_FREECLK_EXISTS] bit must be
                                                                 set to
                                                                 0. */
		uint32_t u1u2timerscale              : 1;  /**< R/W - Disable U1/U2 timer scaledown. If set to 1, along with SCALEDOWN = 0x1, disables the scale
                                                                 down of U1/U2 inactive timer values.
                                                                 This is for simulation mode only. */
		uint32_t debugattach                 : 1;  /**< R/W - Debug attach. When this bit is set:
                                                                 * SuperSpeed link proceeds directly to the polling-link state (USBH()_UAHC_DCTL[RS] = 1)
                                                                 without checking remote termination.
                                                                 * Link LFPS polling timeout is infinite
                                                                 * Polling timeout during TS1 is infinite (in case link is waiting for TXEQ to finish). */
		uint32_t ramclksel                   : 2;  /**< R/W - RAM clock select. Always keep set to 0x0. */
		uint32_t scaledown                   : 2;  /**< R/W - Scale-down mode. When scale-down mode is enabled for simulation, the core uses scaled-down
                                                                 timing values, resulting in faster simulations. When scale-down mode is disabled, actual
                                                                 timing values are used. This is required for hardware operation.

                                                                 High-speed/full-speed/low-speed modes:
                                                                 0x0 = Disables all scale-downs. Actual timing values are used.
                                                                 0x1 = Enables scale-down of all timing values. These include:
                                                                 * Speed enumeration
                                                                 * HNP/SRP
                                                                 * Suspend and resume

                                                                 0x2 = N/A
                                                                 0x3 = Enables bits \<0\> and \<1\> scale-down timing values.

                                                                 SuperSpeed mode:
                                                                 0x0 = Disables all scale-downs. Actual timing values are used.
                                                                 0x1 = Enables scaled down SuperSpeed timing and repeat values including:
                                                                 * Number of TxEq training sequences reduce to eight
                                                                 * LFPS polling burst time reduce to 100 ns
                                                                 * LFPS warm reset receive reduce to 30 us.

                                                                 INTERNAL: Refer to the rtl_vip_scaledown_mapping.xls file under \<workspace\>/sim/SoC_sim
                                                                 directory for the complete list.
                                                                 0x2 = No TxEq training sequences are sent. Overrides bit\<4\>.
                                                                 0x3 = Enables bits\<0\> and \<1\> scale-down timing values. */
		uint32_t disscramble                 : 1;  /**< R/W - Disable scrambling. Transmit request to link partner on next transition to recovery or polling. */
		uint32_t u2exit_lfps                 : 1;  /**< R/W - LFPS U2 exit.
                                                                 0 = The link treats 248ns LFPS as a valid U2 exit.
                                                                 1 = The link waits for 8us of LFPS before it detects a valid U2 exit.

                                                                 This bit is added to improve interoperability with a third party host controller. This
                                                                 host controller in U2 state while performing receiver detection generates an LFPS glitch
                                                                 of about 4s duration. This causes the device to exit from U2 state because the LFPS filter
                                                                 value is 248ns. With the new functionality enabled, the device can stay in U2 while
                                                                 ignoring this glitch from the host controller. */
		uint32_t reserved_1_1                : 1;
		uint32_t dsblclkgtng                 : 1;  /**< R/W - Disable clock gating. When set to 1 and the core is in low-power mode, internal clock
                                                                 gating is disabled, which means the clocks are always running. This bit can be set to 1
                                                                 after power-up reset. */
#else
		uint32_t dsblclkgtng                 : 1;
		uint32_t reserved_1_1                : 1;
		uint32_t u2exit_lfps                 : 1;
		uint32_t disscramble                 : 1;
		uint32_t scaledown                   : 2;
		uint32_t ramclksel                   : 2;
		uint32_t debugattach                 : 1;
		uint32_t u1u2timerscale              : 1;
		uint32_t sofitpsync                  : 1;
		uint32_t coresoftreset               : 1;
		uint32_t prtcapdir                   : 2;
		uint32_t frmscldwn                   : 2;
		uint32_t reserved_16_17              : 2;
		uint32_t masterfiltbypass            : 1;
		uint32_t pwrdnscale                  : 13;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gctl_s       cn88xx; */
	/* struct bdk_usbhx_uahc_gctl_s       cn88xxp1; */
} bdk_usbhx_uahc_gctl_t;

static inline uint64_t BDK_USBHX_UAHC_GCTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GCTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C110ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GCTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GCTL(...) bdk_usbhx_uahc_gctl_t
#define bustype_BDK_USBHX_UAHC_GCTL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GCTL(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GCTL(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GCTL(...) "USBHX_UAHC_GCTL"


/**
 * NCB32b - usbh#_uahc_gdbgbmu
 *
 * See description in USBH()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.5.
 */
typedef union bdk_usbhx_uahc_gdbgbmu {
	uint32_t u;
	struct bdk_usbhx_uahc_gdbgbmu_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bmu_bcu_dbg                 : 24; /**< RO/H - BMU_BCU debug information. */
		uint32_t bmu_dcu_dbg                 : 4;  /**< RO/H - BMU_DCU debug information. */
		uint32_t bmu_ccu_dbg                 : 4;  /**< RO/H - BMU_CCU debug information. */
#else
		uint32_t bmu_ccu_dbg                 : 4;
		uint32_t bmu_dcu_dbg                 : 4;
		uint32_t bmu_bcu_dbg                 : 24;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gdbgbmu_s    cn88xx; */
	/* struct bdk_usbhx_uahc_gdbgbmu_s    cn88xxp1; */
} bdk_usbhx_uahc_gdbgbmu_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGBMU(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGBMU(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C16Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGBMU", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGBMU(...) bdk_usbhx_uahc_gdbgbmu_t
#define bustype_BDK_USBHX_UAHC_GDBGBMU(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDBGBMU(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGBMU(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGBMU(...) "USBHX_UAHC_GDBGBMU"


/**
 * NCB - usbh#_uahc_gdbgepinfo
 *
 * See description in USBH()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 */
typedef union bdk_usbhx_uahc_gdbgepinfo {
	uint64_t u;
	struct bdk_usbhx_uahc_gdbgepinfo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t endpt_dbg                   : 64; /**< RO/H - Endpoint debug information. */
#else
		uint64_t endpt_dbg                   : 64;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gdbgepinfo_s cn88xx; */
	/* struct bdk_usbhx_uahc_gdbgepinfo_s cn88xxp1; */
} bdk_usbhx_uahc_gdbgepinfo_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGEPINFO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGEPINFO(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C178ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGEPINFO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGEPINFO(...) bdk_usbhx_uahc_gdbgepinfo_t
#define bustype_BDK_USBHX_UAHC_GDBGEPINFO(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_GDBGEPINFO(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGEPINFO(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGEPINFO(...) "USBHX_UAHC_GDBGEPINFO"


/**
 * NCB32b - usbh#_uahc_gdbgfifospace
 *
 * This register is for debug purposes. It provides debug information on the internal status and
 * state machines. Global debug registers have design-specific information, and are used by state
 * machines. Global debug registers have design-specific information, and are used for debugging
 * purposes. These registers are not intended to be used by the customer. If any debug assistance
 * is needed for the silicon, contact customer support with a dump of these registers.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.2.
 * INTERNAL: Contact Synopsys directly.
 */
typedef union bdk_usbhx_uahc_gdbgfifospace {
	uint32_t u;
	struct bdk_usbhx_uahc_gdbgfifospace_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t spaceavailable              : 16; /**< RO/H - Space available in the selected FIFO. */
		uint32_t reserved_9_15               : 7;
		uint32_t select                      : 9;  /**< R/W - FIFO/queue select/port-select.
                                                                 FIFO/queue select: \<7:5\> indicates the FIFO/queue type; \<4:0\> indicates the FIFO/queue
                                                                 number.
                                                                 For example, 0x21 refers to RxFIFO_1, and 0x5E refers to TxReqQ_30.
                                                                 0x1F-0x0: TxFIFO_31 to TxFIFO_0.
                                                                 0x3F-0x20: RxFIFO_31 to RxFIFO_0.
                                                                 0x5F-0x40: TxReqQ_31 to TxReqQ_0.
                                                                 0x7F-0x60: RxReqQ_31 to RxReqQ_0.
                                                                 0x9F-0x80: RxInfoQ_31 to RxInfoQ_0.
                                                                 0xA0: DescFetchQ.
                                                                 0xA1: EventQ.
                                                                 0xA2: ProtocolStatusQ.

                                                                 Port-select: \<3:0\> selects the port-number when accessing USBH()_UAHC_GDBGLTSSM. */
#else
		uint32_t select                      : 9;
		uint32_t reserved_9_15               : 7;
		uint32_t spaceavailable              : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_gdbgfifospace_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t spaceavailable              : 16; /**< RO/H - Space available in the selected FIFO. */
		uint32_t reserved_15_9               : 7;
		uint32_t select                      : 9;  /**< R/W - FIFO/queue select/port-select.
                                                                 FIFO/queue select: \<7:5\> indicates the FIFO/queue type; \<4:0\> indicates the FIFO/queue
                                                                 number.
                                                                 For example, 0x21 refers to RxFIFO_1, and 0x5E refers to TxReqQ_30.
                                                                 0x1F-0x0: TxFIFO_31 to TxFIFO_0.
                                                                 0x3F-0x20: RxFIFO_31 to RxFIFO_0.
                                                                 0x5F-0x40: TxReqQ_31 to TxReqQ_0.
                                                                 0x7F-0x60: RxReqQ_31 to RxReqQ_0.
                                                                 0x9F-0x80: RxInfoQ_31 to RxInfoQ_0.
                                                                 0xA0: DescFetchQ.
                                                                 0xA1: EventQ.
                                                                 0xA2: ProtocolStatusQ.

                                                                 Port-select: \<3:0\> selects the port-number when accessing USBH()_UAHC_GDBGLTSSM. */
#else
		uint32_t select                      : 9;
		uint32_t reserved_15_9               : 7;
		uint32_t spaceavailable              : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gdbgfifospace_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gdbgfifospace_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGFIFOSPACE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGFIFOSPACE(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C160ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGFIFOSPACE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGFIFOSPACE(...) bdk_usbhx_uahc_gdbgfifospace_t
#define bustype_BDK_USBHX_UAHC_GDBGFIFOSPACE(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDBGFIFOSPACE(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGFIFOSPACE(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGFIFOSPACE(...) "USBHX_UAHC_GDBGFIFOSPACE"


/**
 * NCB32b - usbh#_uahc_gdbglnmcc
 *
 * See description in USBH()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.4.
 */
typedef union bdk_usbhx_uahc_gdbglnmcc {
	uint32_t u;
	struct bdk_usbhx_uahc_gdbglnmcc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t lnmcc_berc                  : 9;  /**< RO/H - This field indicates the bit-error-rate information for the port selected in
                                                                 USBH()_UAHC_GDBGFIFOSPACE[SELECT] (port-select).
                                                                 This field is for debug purposes only. */
#else
		uint32_t lnmcc_berc                  : 9;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	struct bdk_usbhx_uahc_gdbglnmcc_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_9               : 23;
		uint32_t lnmcc_berc                  : 9;  /**< RO/H - This field indicates the bit-error-rate information for the port selected in
                                                                 USBH()_UAHC_GDBGFIFOSPACE[SELECT] (port-select).
                                                                 This field is for debug purposes only. */
#else
		uint32_t lnmcc_berc                  : 9;
		uint32_t reserved_31_9               : 23;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gdbglnmcc_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gdbglnmcc_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGLNMCC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGLNMCC(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C168ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGLNMCC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGLNMCC(...) bdk_usbhx_uahc_gdbglnmcc_t
#define bustype_BDK_USBHX_UAHC_GDBGLNMCC(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDBGLNMCC(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGLNMCC(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGLNMCC(...) "USBHX_UAHC_GDBGLNMCC"


/**
 * NCB32b - usbh#_uahc_gdbglsp
 *
 * See description in USBH()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 */
typedef union bdk_usbhx_uahc_gdbglsp {
	uint32_t u;
	struct bdk_usbhx_uahc_gdbglsp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lsp_dbg                     : 32; /**< RO/H - LSP debug information. */
#else
		uint32_t lsp_dbg                     : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gdbglsp_s    cn88xx; */
	/* struct bdk_usbhx_uahc_gdbglsp_s    cn88xxp1; */
} bdk_usbhx_uahc_gdbglsp_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGLSP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGLSP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C174ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGLSP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGLSP(...) bdk_usbhx_uahc_gdbglsp_t
#define bustype_BDK_USBHX_UAHC_GDBGLSP(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDBGLSP(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGLSP(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGLSP(...) "USBHX_UAHC_GDBGLSP"


/**
 * NCB32b - usbh#_uahc_gdbglspmux
 *
 * See description in USBH()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.6.
 * INTERNAL: This register is for Synopsys internal use only.
 */
typedef union bdk_usbhx_uahc_gdbglspmux {
	uint32_t u;
	struct bdk_usbhx_uahc_gdbglspmux_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t latraceportmuxselect        : 8;  /**< R/W - logic_analyzer_trace port multiplexer select. Only bits\<21:16\> are used. For details on
                                                                 how the mux controls the debug traces, refer to the Verilog file.
                                                                 A value of 0x3F drives 0s on the logic_analyzer_trace signal. If you plan to OR (instead
                                                                 using a mux) this signal with other trace signals in your system to generate a common
                                                                 trace signal, you can use this feature. */
		uint32_t endbc                       : 1;  /**< R/W - Enable debugging of the debug capability LSP. Use HOSTSELECT to select the DbC LSP debug
                                                                 information presented in the GDBGLSP register.
                                                                 INTERNAL: Note this can only be used if DebugCapabaility was enabled at compile. */
		uint32_t reserved_14_14              : 1;
		uint32_t hostselect                  : 14; /**< R/W - Host select. Selects the LSP debug information presented in USBH()_UAHC_GDBGLSP. */
#else
		uint32_t hostselect                  : 14;
		uint32_t reserved_14_14              : 1;
		uint32_t endbc                       : 1;
		uint32_t latraceportmuxselect        : 8;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gdbglspmux_s cn88xx; */
	/* struct bdk_usbhx_uahc_gdbglspmux_s cn88xxp1; */
} bdk_usbhx_uahc_gdbglspmux_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGLSPMUX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGLSPMUX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C170ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGLSPMUX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGLSPMUX(...) bdk_usbhx_uahc_gdbglspmux_t
#define bustype_BDK_USBHX_UAHC_GDBGLSPMUX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDBGLSPMUX(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGLSPMUX(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGLSPMUX(...) "USBHX_UAHC_GDBGLSPMUX"


/**
 * NCB32b - usbh#_uahc_gdbgltssm
 *
 * In multiport host configuration, the port number is defined by
 * USBH()_UAHC_GDBGFIFOSPACE[SELECT]\<3:0\>. Value of this register may change immediately after
 * reset.
 * See description in USBH()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.3.
 */
typedef union bdk_usbhx_uahc_gdbgltssm {
	uint32_t u;
	struct bdk_usbhx_uahc_gdbgltssm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_27_31              : 5;
		uint32_t ltdbtimeout                 : 1;  /**< RO/H - LTDB timeout. */
		uint32_t ltdblinkstate               : 4;  /**< RO/H - LTDB link state. */
		uint32_t ltdbsubstate                : 4;  /**< RO/H - LTDB substate. */
		uint32_t debugpipestatus             : 18; /**< RO/H - Debug PIPE status.
                                                                 _ \<17\> Elastic buffer mode.
                                                                 _ \<16\> TX elec idle.
                                                                 _ \<15\> RX polarity.
                                                                 _ \<14\> TX Detect RX/loopback.
                                                                 _ \<13:11\> LTSSM PHY command state.
                                                                 _ 0x0 = PHY_IDLE (PHY command state is in IDLE. No PHY request is pending.)
                                                                 _ 0x1 = PHY_DET (Request to start receiver detection).
                                                                 _ 0x2 = PHY_DET_3 (Wait for Phy_Status (receiver detection)).
                                                                 _ 0x3 = PHY_PWR_DLY (delay Pipe3_PowerDown P0 -\> P1/P2/P3 request).
                                                                 _ 0x4 = PHY_PWR_A (delay for internal logic).
                                                                 _ 0x5 = PHY_PWR_B (wait for Phy_Status(Power-state change request)).

                                                                 _ \<10:9\> Power down.
                                                                 _ \<8\> RxEq train.
                                                                 _ \<7:6\> TX de-emphasis.
                                                                 _ \<5:3\> LTSSM clock state.
                                                                 _ 0x0 = CLK_NORM (PHY is in non-P3 state and PCLK is running).
                                                                 _ 0x1 = CLK_TO_P3 (P3 entry request to PHY).
                                                                 _ 0x2 = CLK_WAIT1 (wait for Phy_Status (P3 request)).
                                                                 _ 0x3 = CLK_P3 (PHY is in P3 and PCLK is not running).
                                                                 _ 0x4 = CLK_TO_P0 (P3 exit request to PHY).
                                                                 _ 0x5 = CLK_WAIT2 (Wait for Phy_Status (P3 exit request)).

                                                                 _ \<2\> TX swing.
                                                                 _ \<1\> RX termination.
                                                                 _ \<0\> TX 1s/0s. */
#else
		uint32_t debugpipestatus             : 18;
		uint32_t ltdbsubstate                : 4;
		uint32_t ltdblinkstate               : 4;
		uint32_t ltdbtimeout                 : 1;
		uint32_t reserved_27_31              : 5;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gdbgltssm_s  cn88xx; */
	/* struct bdk_usbhx_uahc_gdbgltssm_s  cn88xxp1; */
} bdk_usbhx_uahc_gdbgltssm_t;

static inline uint64_t BDK_USBHX_UAHC_GDBGLTSSM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDBGLTSSM(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C164ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDBGLTSSM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDBGLTSSM(...) bdk_usbhx_uahc_gdbgltssm_t
#define bustype_BDK_USBHX_UAHC_GDBGLTSSM(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDBGLTSSM(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDBGLTSSM(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDBGLTSSM(...) "USBHX_UAHC_GDBGLTSSM"


/**
 * NCB32b - usbh#_uahc_gdmahlratio
 *
 * This register specifies the relative priority of the SuperSpeed FIFOs with respect to the
 * high-speed/full-speed/low-speed FIFOs. The DMA arbiter prioritizes the high-speed/full-speed
 * /low-speed round-robin arbiter group every DMA high-low priority ratio grants as indicated in
 * the register separately for TX and RX.
 *
 * To illustrate, consider that all FIFOs are requesting access simultaneously, and the ratio is
 * 4. SuperSpeed gets priority for four packets, high-speed/full-speed/low-speed gets priority
 * for one packet, SuperSpeed gets priority for four packets, high-speed/full-speed/low-speed
 * gets priority for one packet, and so on.
 *
 * If FIFOs from both speed groups are not requesting access simultaneously then:
 * * If SuperSpeed got grants four out of the last four times, then high-speed/full-speed/
 * low-speed get the priority on any future request.
 * * If high-speed/full-speed/low-speed got the grant last time, SuperSpeed gets the priority on
 * the next request.
 *
 * If there is a valid request on either SuperSpeed or high-speed/full-speed/low-speed, a grant
 * is always awarded; there is no idle.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.5.
 */
typedef union bdk_usbhx_uahc_gdmahlratio {
	uint32_t u;
	struct bdk_usbhx_uahc_gdmahlratio_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_13_31              : 19;
		uint32_t rx_ratio                    : 5;  /**< R/W - Speed ratio for RX arbitration. */
		uint32_t reserved_5_7                : 3;
		uint32_t tx_ratio                    : 5;  /**< R/W - Speed ratio for TX arbitration. */
#else
		uint32_t tx_ratio                    : 5;
		uint32_t reserved_5_7                : 3;
		uint32_t rx_ratio                    : 5;
		uint32_t reserved_13_31              : 19;
#endif
	} s;
	struct bdk_usbhx_uahc_gdmahlratio_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_13              : 19;
		uint32_t rx_ratio                    : 5;  /**< R/W - Speed ratio for RX arbitration. */
		uint32_t reserved_7_5                : 3;
		uint32_t tx_ratio                    : 5;  /**< R/W - Speed ratio for TX arbitration. */
#else
		uint32_t tx_ratio                    : 5;
		uint32_t reserved_7_5                : 3;
		uint32_t rx_ratio                    : 5;
		uint32_t reserved_31_13              : 19;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gdmahlratio_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gdmahlratio_t;

static inline uint64_t BDK_USBHX_UAHC_GDMAHLRATIO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GDMAHLRATIO(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C624ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GDMAHLRATIO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GDMAHLRATIO(...) bdk_usbhx_uahc_gdmahlratio_t
#define bustype_BDK_USBHX_UAHC_GDMAHLRATIO(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GDMAHLRATIO(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GDMAHLRATIO(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GDMAHLRATIO(...) "USBHX_UAHC_GDMAHLRATIO"


/**
 * NCB32b - usbh#_uahc_gfladj
 *
 * This register provides options for the software to control the core behavior with respect to
 * SOF (start of frame) and ITP (isochronous timestamp packet) timers and frame timer
 * functionality. It provides the option to override the sideband signal fladj_30mhz_reg. In
 * addition, it enables running SOF or ITP frame timer counters completely off of the REF_CLK.
 * This facilitates hardware LPM in host mode with the SOF or ITP counters being run off of the
 * REF_CLK signal.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.6.
 */
typedef union bdk_usbhx_uahc_gfladj {
	uint32_t u;
	struct bdk_usbhx_uahc_gfladj_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t gfladj_refclk_240mhzdecr_pls1 : 1;/**< R/W - This field indicates that the decrement value that the controller applies for each REF_CLK
                                                                 must be GFLADJ_REFCLK_240MHZ_DECR and GFLADJ_REFCLK_240MHZ_DECR +1 alternatively on each
                                                                 REF_CLK. Set this bit to 1 only if GFLADJ_REFCLK_LPM_SEL is set to 1 and the fractional
                                                                 component of 240/ref_frequency is greater than or equal to 0.5.

                                                                 Example:

                                                                 If the REF_CLK is 19.2 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 52.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = (240/19.2) = 12.5.
                                                                 * GFLADJ_REFCLK_240MHZDECR_PLS1 = 1.

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = (240/24) = 10.
                                                                 * GFLADJ_REFCLK_240MHZDECR_PLS1 = 0. */
		uint32_t gfladj_refclk_240mhz_decr   : 7;  /**< R/W - This field indicates the decrement value that the controller applies for each REF_CLK in
                                                                 order to derive a frame timer in terms of a 240-MHz clock. This field must be programmed
                                                                 to a non-zero value only if GFLADJ_REFCLK_LPM_SEL is set to 1.

                                                                 The value is derived as follows:
                                                                 _ GFLADJ_REFCLK_240MHZ_DECR = 240/ref_clk_frequency

                                                                 Examples:

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/24 = 10.

                                                                 If the REF_CLK is 48 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 20.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/48 = 5.

                                                                 If the REF_CLK is 17 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 58.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/17 = 14. */
		uint32_t gfladj_refclk_lpm_sel       : 1;  /**< R/W - This bit enables the functionality of running SOF/ITP counters on the REF_CLK.
                                                                 This bit must not be set to 1 if USBH()_UAHC_GCTL[SOFITPSYNC] = 1. Similarly, if
                                                                 GFLADJ_REFCLK_LPM_SEL = 1, USBH()_UAHC_GCTL[SOFITPSYNC] must not be set to 1.
                                                                 When GFLADJ_REFCLK_LPM_SEL = 1 the overloading of the suspend control of the USB 2.0 first
                                                                 port PHY (UTMI) with USB 3.0 port states is removed. Note that the REF_CLK frequencies
                                                                 supported in this mode are 16/17/19.2/20/24/39.7/40 MHz.
                                                                 INTERNAL: The utmi_clk[0] signal of the core must be connected to the FREECLK of the PHY.
                                                                 If you set this bit to 1, USBH()_UAHC_GUSB2PHYCFG()[U2_FREECLK_EXISTS] must be set to 0. */
		uint32_t reserved_22_22              : 1;
		uint32_t gfladj_refclk_fladj         : 14; /**< R/W - This field indicates the frame length adjustment to be applied when SOF/ITP counter is
                                                                 running off of the REF_CLK. This register value is used to adjust:.
                                                                 * ITP interval when USBH()_UAHC_GCTL[SOFITPSYNC] = 1
                                                                 * both SOF and ITP interval when GFLADJ_REFCLK_LPM_SEL = 1.

                                                                 This field must be programmed to a non-zero value only if GFLADJ_REFCLK_LPM_SEL = 1 or
                                                                 USBH()_UAHC_GCTL[SOFITPSYNC] = 1.

                                                                 The value is derived as below:

                                                                 _ FLADJ_REF_CLK_FLADJ = ((125000/ref_clk_period_integer) - (125000/ref_clk_period)) *
                                                                 ref_clk_period

                                                                 where,
                                                                 * the ref_clk_period_integer is the integer value of the REF_CLK period got by truncating
                                                                 the decimal (fractional) value that is programmed in USBH()_UAHC_GUCTL[REFCLKPER].
                                                                 * the ref_clk_period is the REF_CLK period including the fractional value.

                                                                 Examples:

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GLADJ_REFCLK_FLADJ = ((125000/41) -
                                                                 (125000/41.6666)) * 41.6666 = 2032 (ignoring the fractional value).

                                                                 If the REF_CLK is 48 MHz then,
                                                                 * USBH()_UAHC_GUCTL[REFCLKPER] = 20.
                                                                 * GLADJ_REFCLK_FLADJ = ((125000/20) -
                                                                 (125000/20.8333)) * 20.8333 = 5208 (ignoring the fractional value). */
		uint32_t gfladj_30mhz_reg_sel        : 1;  /**< R/W - This field selects whether to use the input signal fladj_30mhz_reg or the GFLADJ_30MHZ to
                                                                 adjust the frame length for the SOF/ITP. When this bit is set to, 1, the controller uses
                                                                 GFLADJ_30MHZ value 0x0, the controller uses the input signal fladj_30mhz_reg value. */
		uint32_t reserved_6_6                : 1;
		uint32_t gfladj_30mhz                : 6;  /**< R/W - This field indicates the value that is used for frame length adjustment instead of
                                                                 considering from the sideband input signal fladj_30mhz_reg. This enables post-silicon
                                                                 frame length adjustment in case the input signal fladj_30mhz_reg is connected to a wrong
                                                                 value or is not valid. The controller uses this value if GFLADJ_30MHZ_REG_SEL = 1 and the
                                                                 SOF/ITP counters are running off of UTMI(ULPI) clock (GFLADJ_REFCLK_LPM_SEL = 0 and
                                                                 USBH()_UAHC_GCTL[SOFITPSYNC] is 1 or 0). For details on how to set this value, refer to
                                                                 section 5.2.4 Frame Length Adjustment Register (FLADJ) of the xHCI Specification. */
#else
		uint32_t gfladj_30mhz                : 6;
		uint32_t reserved_6_6                : 1;
		uint32_t gfladj_30mhz_reg_sel        : 1;
		uint32_t gfladj_refclk_fladj         : 14;
		uint32_t reserved_22_22              : 1;
		uint32_t gfladj_refclk_lpm_sel       : 1;
		uint32_t gfladj_refclk_240mhz_decr   : 7;
		uint32_t gfladj_refclk_240mhzdecr_pls1 : 1;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gfladj_s     cn88xx; */
	/* struct bdk_usbhx_uahc_gfladj_s     cn88xxp1; */
} bdk_usbhx_uahc_gfladj_t;

static inline uint64_t BDK_USBHX_UAHC_GFLADJ(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GFLADJ(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C630ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GFLADJ", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GFLADJ(...) bdk_usbhx_uahc_gfladj_t
#define bustype_BDK_USBHX_UAHC_GFLADJ(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GFLADJ(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GFLADJ(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GFLADJ(...) "USBHX_UAHC_GFLADJ"


/**
 * NCB32b - usbh#_uahc_ggpio
 *
 * The application can use this register for general purpose input and output ports or for
 * debugging.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.9.
 */
typedef union bdk_usbhx_uahc_ggpio {
	uint32_t u;
	struct bdk_usbhx_uahc_ggpio_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t gpo                         : 16; /**< R/W - General purpose output. These outputs are not connected to anything. Can be used as scratch. */
		uint32_t gpi                         : 16; /**< RO - General purpose input. These inputs are tied 0x0. */
#else
		uint32_t gpi                         : 16;
		uint32_t gpo                         : 16;
#endif
	} s;
	/* struct bdk_usbhx_uahc_ggpio_s      cn88xx; */
	/* struct bdk_usbhx_uahc_ggpio_s      cn88xxp1; */
} bdk_usbhx_uahc_ggpio_t;

static inline uint64_t BDK_USBHX_UAHC_GGPIO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GGPIO(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C124ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GGPIO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GGPIO(...) bdk_usbhx_uahc_ggpio_t
#define bustype_BDK_USBHX_UAHC_GGPIO(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GGPIO(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GGPIO(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GGPIO(...) "USBHX_UAHC_GGPIO"


/**
 * NCB32b - usbh#_uahc_ghwparams0
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.1.
 */
typedef union bdk_usbhx_uahc_ghwparams0 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t awidth                      : 8;  /**< RO - USB core bus-address width. */
		uint32_t sdwidth                     : 8;  /**< RO - USB core bus slave-data width. */
		uint32_t mdwidth                     : 8;  /**< RO - USB core bus master-data width. */
		uint32_t sbus_type                   : 2;  /**< RO - USB core bus slave type: AXI. */
		uint32_t mbus_type                   : 3;  /**< RO - USB core bus master type: AXI. */
		uint32_t mode                        : 3;  /**< RO - Operation mode: 0x1: host-only. */
#else
		uint32_t mode                        : 3;
		uint32_t mbus_type                   : 3;
		uint32_t sbus_type                   : 2;
		uint32_t mdwidth                     : 8;
		uint32_t sdwidth                     : 8;
		uint32_t awidth                      : 8;
#endif
	} s;
	/* struct bdk_usbhx_uahc_ghwparams0_s cn88xx; */
	/* struct bdk_usbhx_uahc_ghwparams0_s cn88xxp1; */
} bdk_usbhx_uahc_ghwparams0_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C140ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS0(...) bdk_usbhx_uahc_ghwparams0_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS0(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS0(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS0(...) "USBHX_UAHC_GHWPARAMS0"


/**
 * NCB32b - usbh#_uahc_ghwparams1
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.2.
 */
typedef union bdk_usbhx_uahc_ghwparams1 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t en_dbc                      : 1;  /**< RO - Enable debug capability. */
		uint32_t rm_opt_features             : 1;  /**< RO - Remove optional features. */
		uint32_t sync_rst                    : 1;  /**< RO - Synchronous reset coding. */
		uint32_t ram_bus_clks_sync           : 1;  /**< RO - RAM_CLK and BUS_CLK are synchronous. INTERNAL: (appears to be orthogonal from the
                                                                 RAM_CLK_TO_BUS_CLK parameter) */
		uint32_t mac_ram_clks_sync           : 1;  /**< RO - MAC3_CLK and RAM_CLK are synchronous. */
		uint32_t mac_phy_clks_sync           : 1;  /**< RO - MAC3_CLK and PHY_CLK are synchronous. */
		uint32_t en_pwropt                   : 2;  /**< RO - Power optimization mode:
                                                                 bit\<0\> = Clock-gating feature available.
                                                                 bit\<1\> = Hibernation feature available. */
		uint32_t spram_typ                   : 1;  /**< RO - SRAM type: one-port RAMs. */
		uint32_t num_rams                    : 2;  /**< RO - Number of RAMs. */
		uint32_t device_num_int              : 6;  /**< RO - Number of event buffers (and interrupts) in device-mode (unsupported). */
		uint32_t aspacewidth                 : 3;  /**< RO - Native interface address-space port width. */
		uint32_t reqinfowidth                : 3;  /**< RO - Native interface request/response-info port width. */
		uint32_t datainfowidth               : 3;  /**< RO - Native interface data-info port width. */
		uint32_t burstwidth_m1               : 3;  /**< RO - Width minus one of AXI length field. */
		uint32_t idwidth_m1                  : 3;  /**< RO - Width minus one of AXI ID field. */
#else
		uint32_t idwidth_m1                  : 3;
		uint32_t burstwidth_m1               : 3;
		uint32_t datainfowidth               : 3;
		uint32_t reqinfowidth                : 3;
		uint32_t aspacewidth                 : 3;
		uint32_t device_num_int              : 6;
		uint32_t num_rams                    : 2;
		uint32_t spram_typ                   : 1;
		uint32_t en_pwropt                   : 2;
		uint32_t mac_phy_clks_sync           : 1;
		uint32_t mac_ram_clks_sync           : 1;
		uint32_t ram_bus_clks_sync           : 1;
		uint32_t sync_rst                    : 1;
		uint32_t rm_opt_features             : 1;
		uint32_t en_dbc                      : 1;
#endif
	} s;
	/* struct bdk_usbhx_uahc_ghwparams1_s cn88xx; */
	/* struct bdk_usbhx_uahc_ghwparams1_s cn88xxp1; */
} bdk_usbhx_uahc_ghwparams1_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C144ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS1(...) bdk_usbhx_uahc_ghwparams1_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS1(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS1(...) "USBHX_UAHC_GHWPARAMS1"


/**
 * NCB32b - usbh#_uahc_ghwparams2
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.3.
 */
typedef union bdk_usbhx_uahc_ghwparams2 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t userid                      : 32; /**< RO - User ID. */
#else
		uint32_t userid                      : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_ghwparams2_s cn88xx; */
	/* struct bdk_usbhx_uahc_ghwparams2_s cn88xxp1; */
} bdk_usbhx_uahc_ghwparams2_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C148ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS2(...) bdk_usbhx_uahc_ghwparams2_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS2(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS2(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS2(...) "USBHX_UAHC_GHWPARAMS2"


/**
 * NCB32b - usbh#_uahc_ghwparams3
 *
 * This register contains the hardware configuration options selected at compile-time.
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.4.
 */
typedef union bdk_usbhx_uahc_ghwparams3 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t cache_total_xfer_resources  : 8;  /**< RO - Maximum number of transfer resources in the core. */
		uint32_t num_in_eps                  : 5;  /**< RO - Maximum number of device-mode (unsupported) IN endpoints active. */
		uint32_t num_eps                     : 6;  /**< RO - Number of device-mode (unsupported) single-directional endpoints. */
		uint32_t ulpi_carkit                 : 1;  /**< RO - ULPI Carkit is not supported. */
		uint32_t vendor_ctl_interface        : 1;  /**< RO - UTMI+ PHY vendor control interface enabled. */
		uint32_t reserved_8_9                : 2;
		uint32_t hsphy_dwidth                : 2;  /**< RO - Data width of the UTMI+ PHY interface: 0x2 = 8-or-16 bits. */
		uint32_t fsphy_interface             : 2;  /**< RO - USB 1.1 full-speed serial transceiver interface. */
		uint32_t hsphy_interface             : 2;  /**< RO - High-speed PHY interface: 0x1 = UTMI+. */
		uint32_t ssphy_interface             : 2;  /**< RO - SuperSpeed PHY interface: 0x1 = PIPE3. */
#else
		uint32_t ssphy_interface             : 2;
		uint32_t hsphy_interface             : 2;
		uint32_t fsphy_interface             : 2;
		uint32_t hsphy_dwidth                : 2;
		uint32_t reserved_8_9                : 2;
		uint32_t vendor_ctl_interface        : 1;
		uint32_t ulpi_carkit                 : 1;
		uint32_t num_eps                     : 6;
		uint32_t num_in_eps                  : 5;
		uint32_t cache_total_xfer_resources  : 8;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	struct bdk_usbhx_uahc_ghwparams3_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t cache_total_xfer_resources  : 8;  /**< RO - Maximum number of transfer resources in the core. */
		uint32_t num_in_eps                  : 5;  /**< RO - Maximum number of device-mode (unsupported) IN endpoints active. */
		uint32_t num_eps                     : 6;  /**< RO - Number of device-mode (unsupported) single-directional endpoints. */
		uint32_t ulpi_carkit                 : 1;  /**< RO - ULPI Carkit is not supported. */
		uint32_t vendor_ctl_interface        : 1;  /**< RO - UTMI+ PHY vendor control interface enabled. */
		uint32_t reserved_9_8                : 2;
		uint32_t hsphy_dwidth                : 2;  /**< RO - Data width of the UTMI+ PHY interface: 0x2 = 8-or-16 bits. */
		uint32_t fsphy_interface             : 2;  /**< RO - USB 1.1 full-speed serial transceiver interface. */
		uint32_t hsphy_interface             : 2;  /**< RO - High-speed PHY interface: 0x1 = UTMI+. */
		uint32_t ssphy_interface             : 2;  /**< RO - SuperSpeed PHY interface: 0x1 = PIPE3. */
#else
		uint32_t ssphy_interface             : 2;
		uint32_t hsphy_interface             : 2;
		uint32_t fsphy_interface             : 2;
		uint32_t hsphy_dwidth                : 2;
		uint32_t reserved_9_8                : 2;
		uint32_t vendor_ctl_interface        : 1;
		uint32_t ulpi_carkit                 : 1;
		uint32_t num_eps                     : 6;
		uint32_t num_in_eps                  : 5;
		uint32_t cache_total_xfer_resources  : 8;
		uint32_t reserved_31_31              : 1;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_ghwparams3_cn88xx cn88xxp1;
} bdk_usbhx_uahc_ghwparams3_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C14Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS3(...) bdk_usbhx_uahc_ghwparams3_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS3(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS3(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS3(...) "USBHX_UAHC_GHWPARAMS3"


/**
 * NCB32b - usbh#_uahc_ghwparams4
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.5.
 */
typedef union bdk_usbhx_uahc_ghwparams4 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bmu_lsp_depth               : 4;  /**< RO - Depth of the BMU-LSP status buffer. */
		uint32_t bmu_ptl_depth_m1            : 4;  /**< RO - Depth of the BMU-PTL source/sink buffers minus 1. */
		uint32_t en_isoc_supt                : 1;  /**< RO - Isochronous support enabled. */
		uint32_t reserved_22_22              : 1;
		uint32_t ext_buff_control            : 1;  /**< RO - Enables device external buffer control sideband controls. */
		uint32_t num_ss_usb_instances        : 4;  /**< RO - Number of SuperSpeed bus instances. */
		uint32_t hiber_scratchbufs           : 4;  /**< RO - Number of hibernation scratchpad buffers. */
		uint32_t reserved_6_12               : 7;
		uint32_t cache_trbs_per_transfer     : 6;  /**< RO - Number of TRBs per transfer that can be cached. */
#else
		uint32_t cache_trbs_per_transfer     : 6;
		uint32_t reserved_6_12               : 7;
		uint32_t hiber_scratchbufs           : 4;
		uint32_t num_ss_usb_instances        : 4;
		uint32_t ext_buff_control            : 1;
		uint32_t reserved_22_22              : 1;
		uint32_t en_isoc_supt                : 1;
		uint32_t bmu_ptl_depth_m1            : 4;
		uint32_t bmu_lsp_depth               : 4;
#endif
	} s;
	struct bdk_usbhx_uahc_ghwparams4_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bmu_lsp_depth               : 4;  /**< RO - Depth of the BMU-LSP status buffer. */
		uint32_t bmu_ptl_depth_m1            : 4;  /**< RO - Depth of the BMU-PTL source/sink buffers minus 1. */
		uint32_t en_isoc_supt                : 1;  /**< RO - Isochronous support enabled. */
		uint32_t reserved_22_22              : 1;
		uint32_t ext_buff_control            : 1;  /**< RO - Enables device external buffer control sideband controls. */
		uint32_t num_ss_usb_instances        : 4;  /**< RO - Number of SuperSpeed bus instances. */
		uint32_t hiber_scratchbufs           : 4;  /**< RO - Number of hibernation scratchpad buffers. */
		uint32_t reserved_12_6               : 7;
		uint32_t cache_trbs_per_transfer     : 6;  /**< RO - Number of TRBs per transfer that can be cached. */
#else
		uint32_t cache_trbs_per_transfer     : 6;
		uint32_t reserved_12_6               : 7;
		uint32_t hiber_scratchbufs           : 4;
		uint32_t num_ss_usb_instances        : 4;
		uint32_t ext_buff_control            : 1;
		uint32_t reserved_22_22              : 1;
		uint32_t en_isoc_supt                : 1;
		uint32_t bmu_ptl_depth_m1            : 4;
		uint32_t bmu_lsp_depth               : 4;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_ghwparams4_cn88xx cn88xxp1;
} bdk_usbhx_uahc_ghwparams4_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS4(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C150ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS4(...) bdk_usbhx_uahc_ghwparams4_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS4(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS4(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS4(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS4(...) "USBHX_UAHC_GHWPARAMS4"


/**
 * NCB32b - usbh#_uahc_ghwparams5
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.6.
 */
typedef union bdk_usbhx_uahc_ghwparams5 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t dfq_fifo_depth              : 6;  /**< RO - Size of the BMU descriptor fetch-request queue. */
		uint32_t dwq_fifo_depth              : 6;  /**< RO - Size of the BMU descriptor write queue. */
		uint32_t txq_fifo_depth              : 6;  /**< RO - Size of the BMU TX request queue. */
		uint32_t rxq_fifo_depth              : 6;  /**< RO - Size of the BMU RX request queue. */
		uint32_t bmu_busgm_depth             : 4;  /**< RO - Depth of the BMU-BUSGM source/sink buffers. */
#else
		uint32_t bmu_busgm_depth             : 4;
		uint32_t rxq_fifo_depth              : 6;
		uint32_t txq_fifo_depth              : 6;
		uint32_t dwq_fifo_depth              : 6;
		uint32_t dfq_fifo_depth              : 6;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	struct bdk_usbhx_uahc_ghwparams5_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_28              : 4;
		uint32_t dfq_fifo_depth              : 6;  /**< RO - Size of the BMU descriptor fetch-request queue. */
		uint32_t dwq_fifo_depth              : 6;  /**< RO - Size of the BMU descriptor write queue. */
		uint32_t txq_fifo_depth              : 6;  /**< RO - Size of the BMU TX request queue. */
		uint32_t rxq_fifo_depth              : 6;  /**< RO - Size of the BMU RX request queue. */
		uint32_t bmu_busgm_depth             : 4;  /**< RO - Depth of the BMU-BUSGM source/sink buffers. */
#else
		uint32_t bmu_busgm_depth             : 4;
		uint32_t rxq_fifo_depth              : 6;
		uint32_t txq_fifo_depth              : 6;
		uint32_t dwq_fifo_depth              : 6;
		uint32_t dfq_fifo_depth              : 6;
		uint32_t reserved_31_28              : 4;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_ghwparams5_cn88xx cn88xxp1;
} bdk_usbhx_uahc_ghwparams5_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS5(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C154ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS5(...) bdk_usbhx_uahc_ghwparams5_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS5(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS5(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS5(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS5(...) "USBHX_UAHC_GHWPARAMS5"


/**
 * NCB32b - usbh#_uahc_ghwparams6
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.7.
 */
typedef union bdk_usbhx_uahc_ghwparams6 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ram0_depth                  : 16; /**< RO - RAM0 Depth. */
		uint32_t en_bus_filters              : 1;  /**< RO - Enable VBus filters support. */
		uint32_t en_bc                       : 1;  /**< RO - Enable battery-charging support. */
		uint32_t en_otg_ss                   : 1;  /**< RO - Enable OTG SuperSpeed support. */
		uint32_t en_adp                      : 1;  /**< RO - Enable ADP support. */
		uint32_t hnp_support                 : 1;  /**< RO - HNP support. */
		uint32_t srp_support                 : 1;  /**< RO - SRP support. */
		uint32_t reserved_8_9                : 2;
		uint32_t en_fpga                     : 1;  /**< RO - Enable FPGA implementation. */
		uint32_t en_dbg_ports                : 1;  /**< RO - Enable Debug ports for FGPA. */
		uint32_t psq_fifo_depth              : 6;  /**< RO - Size of the BMU-protocol status queue. */
#else
		uint32_t psq_fifo_depth              : 6;
		uint32_t en_dbg_ports                : 1;
		uint32_t en_fpga                     : 1;
		uint32_t reserved_8_9                : 2;
		uint32_t srp_support                 : 1;
		uint32_t hnp_support                 : 1;
		uint32_t en_adp                      : 1;
		uint32_t en_otg_ss                   : 1;
		uint32_t en_bc                       : 1;
		uint32_t en_bus_filters              : 1;
		uint32_t ram0_depth                  : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_ghwparams6_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ram0_depth                  : 16; /**< RO - RAM0 Depth. */
		uint32_t en_bus_filters              : 1;  /**< RO - Enable VBus filters support. */
		uint32_t en_bc                       : 1;  /**< RO - Enable battery-charging support. */
		uint32_t en_otg_ss                   : 1;  /**< RO - Enable OTG SuperSpeed support. */
		uint32_t en_adp                      : 1;  /**< RO - Enable ADP support. */
		uint32_t hnp_support                 : 1;  /**< RO - HNP support. */
		uint32_t srp_support                 : 1;  /**< RO - SRP support. */
		uint32_t reserved_9_8                : 2;
		uint32_t en_fpga                     : 1;  /**< RO - Enable FPGA implementation. */
		uint32_t en_dbg_ports                : 1;  /**< RO - Enable Debug ports for FGPA. */
		uint32_t psq_fifo_depth              : 6;  /**< RO - Size of the BMU-protocol status queue. */
#else
		uint32_t psq_fifo_depth              : 6;
		uint32_t en_dbg_ports                : 1;
		uint32_t en_fpga                     : 1;
		uint32_t reserved_9_8                : 2;
		uint32_t srp_support                 : 1;
		uint32_t hnp_support                 : 1;
		uint32_t en_adp                      : 1;
		uint32_t en_otg_ss                   : 1;
		uint32_t en_bc                       : 1;
		uint32_t en_bus_filters              : 1;
		uint32_t ram0_depth                  : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_ghwparams6_cn88xx cn88xxp1;
} bdk_usbhx_uahc_ghwparams6_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS6(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C158ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS6(...) bdk_usbhx_uahc_ghwparams6_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS6(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS6(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS6(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS6(...) "USBHX_UAHC_GHWPARAMS6"


/**
 * NCB32b - usbh#_uahc_ghwparams7
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.8.
 */
typedef union bdk_usbhx_uahc_ghwparams7 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ram2_depth                  : 16; /**< RO - RAM2 depth. */
		uint32_t ram1_depth                  : 16; /**< RO - RAM1 depth. */
#else
		uint32_t ram1_depth                  : 16;
		uint32_t ram2_depth                  : 16;
#endif
	} s;
	/* struct bdk_usbhx_uahc_ghwparams7_s cn88xx; */
	/* struct bdk_usbhx_uahc_ghwparams7_s cn88xxp1; */
} bdk_usbhx_uahc_ghwparams7_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS7(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C15Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS7(...) bdk_usbhx_uahc_ghwparams7_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS7(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS7(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS7(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS7(...) "USBHX_UAHC_GHWPARAMS7"


/**
 * NCB32b - usbh#_uahc_ghwparams8
 *
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.3.9.
 */
typedef union bdk_usbhx_uahc_ghwparams8 {
	uint32_t u;
	struct bdk_usbhx_uahc_ghwparams8_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t dcache_depth_info           : 32; /**< RO - Dcache depth. */
#else
		uint32_t dcache_depth_info           : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_ghwparams8_s cn88xx; */
	/* struct bdk_usbhx_uahc_ghwparams8_s cn88xxp1; */
} bdk_usbhx_uahc_ghwparams8_t;

static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS8(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GHWPARAMS8(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C600ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GHWPARAMS8", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GHWPARAMS8(...) bdk_usbhx_uahc_ghwparams8_t
#define bustype_BDK_USBHX_UAHC_GHWPARAMS8(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GHWPARAMS8(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GHWPARAMS8(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GHWPARAMS8(...) "USBHX_UAHC_GHWPARAMS8"


/**
 * NCB32b - usbh#_uahc_gpmsts
 *
 * This debug register gives information on which event caused the hibernation exit. These
 * registers are for debug purposes. They provide debug information on the internal status and
 * state machines. Global debug registers have design-specific information, and are used by for
 * debugging purposes. These registers are not intended to be used by the customer. If any debug
 * assistance is needed for the silicon, contact Customer Support with a dump of these registers.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.1.
 * INTERNAL: Contact Synopsys directly.
 */
typedef union bdk_usbhx_uahc_gpmsts {
	uint32_t u;
	struct bdk_usbhx_uahc_gpmsts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t portsel                     : 4;  /**< WO - This field selects the port number. Always 0x0. */
		uint32_t reserved_17_27              : 11;
		uint32_t u3wakeup                    : 5;  /**< RO/H - This field gives the USB 3.0 port wakeup conditions.
                                                                 bit\<12\> = Overcurrent detected.
                                                                 bit\<13\> = Resume detected.
                                                                 bit\<14\> = Connect detected.
                                                                 bit\<15\> = Disconnect detected.
                                                                 bit\<16\> = Last connection state. */
		uint32_t reserved_10_11              : 2;
		uint32_t u2wakeup                    : 10; /**< RO/H - This field indicates the USB 2.0 port wakeup conditions.
                                                                 bit\<0\> = Overcurrent detected.
                                                                 bit\<1\> = Resume detected.
                                                                 bit\<2\> = Connect detected.
                                                                 bit\<3\> = Disconnect detected.
                                                                 bit\<4\> = Last connection state.
                                                                 bit\<5\> = ID change detected.
                                                                 bit\<6\> = SRP request detected.
                                                                 bit\<7\> = ULPI interrupt detected.
                                                                 bit\<8\> = USB reset detected.
                                                                 bit\<9\> = Resume detected changed. */
#else
		uint32_t u2wakeup                    : 10;
		uint32_t reserved_10_11              : 2;
		uint32_t u3wakeup                    : 5;
		uint32_t reserved_17_27              : 11;
		uint32_t portsel                     : 4;
#endif
	} s;
	struct bdk_usbhx_uahc_gpmsts_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t portsel                     : 4;  /**< WO - This field selects the port number. Always 0x0. */
		uint32_t reserved_27_17              : 11;
		uint32_t u3wakeup                    : 5;  /**< RO/H - This field gives the USB 3.0 port wakeup conditions.
                                                                 bit\<12\> = Overcurrent detected.
                                                                 bit\<13\> = Resume detected.
                                                                 bit\<14\> = Connect detected.
                                                                 bit\<15\> = Disconnect detected.
                                                                 bit\<16\> = Last connection state. */
		uint32_t reserved_11_10              : 2;
		uint32_t u2wakeup                    : 10; /**< RO/H - This field indicates the USB 2.0 port wakeup conditions.
                                                                 bit\<0\> = Overcurrent detected.
                                                                 bit\<1\> = Resume detected.
                                                                 bit\<2\> = Connect detected.
                                                                 bit\<3\> = Disconnect detected.
                                                                 bit\<4\> = Last connection state.
                                                                 bit\<5\> = ID change detected.
                                                                 bit\<6\> = SRP request detected.
                                                                 bit\<7\> = ULPI interrupt detected.
                                                                 bit\<8\> = USB reset detected.
                                                                 bit\<9\> = Resume detected changed. */
#else
		uint32_t u2wakeup                    : 10;
		uint32_t reserved_11_10              : 2;
		uint32_t u3wakeup                    : 5;
		uint32_t reserved_27_17              : 11;
		uint32_t portsel                     : 4;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gpmsts_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_gpmsts_t;

static inline uint64_t BDK_USBHX_UAHC_GPMSTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GPMSTS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C114ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GPMSTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GPMSTS(...) bdk_usbhx_uahc_gpmsts_t
#define bustype_BDK_USBHX_UAHC_GPMSTS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GPMSTS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GPMSTS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GPMSTS(...) "USBHX_UAHC_GPMSTS"


/**
 * NCB - usbh#_uahc_gprtbimap
 *
 * This register specifies the SuperSpeed USB instance number to which each USB 3.0 port is
 * connected. By default, USB 3.0 ports are evenly distributed among all SuperSpeed USB
 * instances. Software can program this register to specify how USB 3.0 ports are connected to
 * SuperSpeed USB instances. The UAHC only implements one SuperSpeed bus-instance, so this
 * register should always be 0.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.2.1.
 */
typedef union bdk_usbhx_uahc_gprtbimap {
	uint64_t u;
	struct bdk_usbhx_uahc_gprtbimap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t binum1                      : 4;  /**< R/W - SuperSpeed USB instance number for port 1. */
#else
		uint64_t binum1                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	struct bdk_usbhx_uahc_gprtbimap_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_4               : 60;
		uint64_t binum1                      : 4;  /**< R/W - SuperSpeed USB instance number for port 1. */
#else
		uint64_t binum1                      : 4;
		uint64_t reserved_63_4               : 60;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gprtbimap_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gprtbimap_t;

static inline uint64_t BDK_USBHX_UAHC_GPRTBIMAP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GPRTBIMAP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C138ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GPRTBIMAP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GPRTBIMAP(...) bdk_usbhx_uahc_gprtbimap_t
#define bustype_BDK_USBHX_UAHC_GPRTBIMAP(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_GPRTBIMAP(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GPRTBIMAP(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GPRTBIMAP(...) "USBHX_UAHC_GPRTBIMAP"


/**
 * NCB - usbh#_uahc_gprtbimap_fs
 *
 * This register specifies the full-speed/low-speed USB instance number to which each USB 1.1
 * port is connected. By default, USB 1.1 ports are evenly distributed among all full-speed/
 * low-speed USB instances. Software can program this register to specify how USB 1.1 ports are
 * connected to full-speed/low-speed USB instances. The UAHC only implements one full-speed/
 * low-speed bus-instance, so this register should always be 0x0.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.2.3.
 */
typedef union bdk_usbhx_uahc_gprtbimap_fs {
	uint64_t u;
	struct bdk_usbhx_uahc_gprtbimap_fs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t binum1                      : 4;  /**< R/W - Full-speed USB instance number for port 1. */
#else
		uint64_t binum1                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	struct bdk_usbhx_uahc_gprtbimap_fs_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_4               : 60;
		uint64_t binum1                      : 4;  /**< R/W - Full-speed USB instance number for port 1. */
#else
		uint64_t binum1                      : 4;
		uint64_t reserved_63_4               : 60;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gprtbimap_fs_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gprtbimap_fs_t;

static inline uint64_t BDK_USBHX_UAHC_GPRTBIMAP_FS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GPRTBIMAP_FS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C188ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GPRTBIMAP_FS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GPRTBIMAP_FS(...) bdk_usbhx_uahc_gprtbimap_fs_t
#define bustype_BDK_USBHX_UAHC_GPRTBIMAP_FS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_GPRTBIMAP_FS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GPRTBIMAP_FS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GPRTBIMAP_FS(...) "USBHX_UAHC_GPRTBIMAP_FS"


/**
 * NCB - usbh#_uahc_gprtbimap_hs
 *
 * This register specifies the high-speed USB instance number to which each USB 2.0 port is
 * connected. By default, USB 2.0 ports are evenly distributed among all high-speed USB
 * instances. Software can program this register to specify how USB 2.0 ports are connected to
 * high-speed USB instances. The UAHC only implements one high-speed bus-instance, so this
 * register should always be 0.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.2.2.
 */
typedef union bdk_usbhx_uahc_gprtbimap_hs {
	uint64_t u;
	struct bdk_usbhx_uahc_gprtbimap_hs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t binum1                      : 4;  /**< R/W - High-speed USB instance number for port 1. */
#else
		uint64_t binum1                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	struct bdk_usbhx_uahc_gprtbimap_hs_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_4               : 60;
		uint64_t binum1                      : 4;  /**< R/W - High-speed USB instance number for port 1. */
#else
		uint64_t binum1                      : 4;
		uint64_t reserved_63_4               : 60;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gprtbimap_hs_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gprtbimap_hs_t;

static inline uint64_t BDK_USBHX_UAHC_GPRTBIMAP_HS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GPRTBIMAP_HS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C180ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GPRTBIMAP_HS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GPRTBIMAP_HS(...) bdk_usbhx_uahc_gprtbimap_hs_t
#define bustype_BDK_USBHX_UAHC_GPRTBIMAP_HS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UAHC_GPRTBIMAP_HS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GPRTBIMAP_HS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GPRTBIMAP_HS(...) "USBHX_UAHC_GPRTBIMAP_HS"


/**
 * NCB32b - usbh#_uahc_grlsid
 *
 * This is a read-only register that contains the release number of the core.
 * INTERNAL: Original name: GSNPSID = Synopsys ID.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.8.
 */
typedef union bdk_usbhx_uahc_grlsid {
	uint32_t u;
	struct bdk_usbhx_uahc_grlsid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t releaseid                   : 32; /**< RO - Software can use this register to configure release-specific features in the driver.
                                                                 INTERNAL: Synopsys ID
                                                                  * SynopsysID[31:16] indicates Core Identification Number. 0x5533 is ASCII for
                                                                 U3 (DWC_usb3).
                                                                  * SynopsysID[15:0] indicates the release number. Current Release is 2.50a. */
#else
		uint32_t releaseid                   : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_grlsid_s     cn88xx; */
	/* struct bdk_usbhx_uahc_grlsid_s     cn88xxp1; */
} bdk_usbhx_uahc_grlsid_t;

static inline uint64_t BDK_USBHX_UAHC_GRLSID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GRLSID(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C120ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GRLSID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GRLSID(...) bdk_usbhx_uahc_grlsid_t
#define bustype_BDK_USBHX_UAHC_GRLSID(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GRLSID(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GRLSID(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GRLSID(...) "USBHX_UAHC_GRLSID"


/**
 * NCB32b - usbh#_uahc_grxfifoprihst
 *
 * This register specifies the relative DMA priority level among the host RXFIFOs (one per USB
 * bus instance) within the associated speed group (SuperSpeed or high-speed/full-speed/
 * low-speed). When multiple RXFIFOs compete for DMA service at a given time, the RXDMA arbiter
 * grants access on a packet-basis in the following manner:
 *
 * Among the FIFOs in the same speed group (SuperSpeed or high-speed/full-speed/low-speed):
 * * High-priority RXFIFOs are granted access using round-robin arbitration.
 * * Low-priority RXFIFOs are granted access using round-robin arbitration only after high-
 * priority
 * RXFIFOs have no further processing to do (i.e., either the RXQs are empty or the corresponding
 * RXFIFOs do not have the required data).
 *
 * The RX DMA arbiter prioritizes the SuperSpeed group or high-speed/full-speed/low-speed group
 * according to the ratio programmed in
 * USBH()_UAHC_GDMAHLRATIO.
 *
 * For scatter-gather packets, the arbiter grants successive DMA requests to the same FIFO until
 * the entire packet is completed. The register size corresponds to the number of configured USB
 * bus instances; for example, in the default configuration, there are 3 USB bus instances (1
 * SuperSpeed, 1 high-speed, and 1 full-speed/low-speed).
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.3.
 */
typedef union bdk_usbhx_uahc_grxfifoprihst {
	uint32_t u;
	struct bdk_usbhx_uahc_grxfifoprihst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t rx_priority                 : 3;  /**< R/W - Each register bit[n] controls the priority (1 = high, 0 = low) of RXFIFO[n] within a speed group. */
#else
		uint32_t rx_priority                 : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	struct bdk_usbhx_uahc_grxfifoprihst_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_3               : 29;
		uint32_t rx_priority                 : 3;  /**< R/W - Each register bit[n] controls the priority (1 = high, 0 = low) of RXFIFO[n] within a speed group. */
#else
		uint32_t rx_priority                 : 3;
		uint32_t reserved_31_3               : 29;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_grxfifoprihst_cn88xx cn88xxp1;
} bdk_usbhx_uahc_grxfifoprihst_t;

static inline uint64_t BDK_USBHX_UAHC_GRXFIFOPRIHST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GRXFIFOPRIHST(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C61Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GRXFIFOPRIHST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GRXFIFOPRIHST(...) bdk_usbhx_uahc_grxfifoprihst_t
#define bustype_BDK_USBHX_UAHC_GRXFIFOPRIHST(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GRXFIFOPRIHST(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GRXFIFOPRIHST(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GRXFIFOPRIHST(...) "USBHX_UAHC_GRXFIFOPRIHST"


/**
 * NCB32b - usbh#_uahc_grxfifosiz#
 *
 * The application can program the internal RAM start address/depth of the each RxFIFO as shown
 * below. It is recommended that software use the default value. In Host mode, per-port registers
 * are implemented. One register per FIFO.
 *
 * Reset values = 0:{0x0000_0084} 1:{0x0084_0104} 2:{0x0188_0180}.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.6.2.
 * INTERNAL: For more information, see the BMU section in Block Descriptions on Synopsys Databook
 * page 238.
 */
typedef union bdk_usbhx_uahc_grxfifosizx {
	uint32_t u;
	struct bdk_usbhx_uahc_grxfifosizx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rxfstaddr                   : 16; /**< R/W - RxFIFOn RAM start address. This field contains the memory start address for RxFIFOn. The
                                                                 reset value is derived from configuration parameters. */
		uint32_t rxfdep                      : 16; /**< R/W - RxFIFOn depth. This value is in terms of RX RAM Data width.
                                                                 minimum value = 0x20, maximum value = 0x4000.
                                                                 INTERNAL: For more information, see the Hardware Integration chapter of the Synopsys
                                                                 Databook.
                                                                 The reset value is derived from configuration parameters. */
#else
		uint32_t rxfdep                      : 16;
		uint32_t rxfstaddr                   : 16;
#endif
	} s;
	/* struct bdk_usbhx_uahc_grxfifosizx_s cn88xx; */
	/* struct bdk_usbhx_uahc_grxfifosizx_s cn88xxp1; */
} bdk_usbhx_uahc_grxfifosizx_t;

static inline uint64_t BDK_USBHX_UAHC_GRXFIFOSIZX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GRXFIFOSIZX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x000086800000C380ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x4ull;
	csr_fatal("BDK_USBHX_UAHC_GRXFIFOSIZX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GRXFIFOSIZX(...) bdk_usbhx_uahc_grxfifosizx_t
#define bustype_BDK_USBHX_UAHC_GRXFIFOSIZX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GRXFIFOSIZX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_GRXFIFOSIZX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_GRXFIFOSIZX(...) "USBHX_UAHC_GRXFIFOSIZX"


/**
 * NCB32b - usbh#_uahc_grxthrcfg
 *
 * In a normal case, an RX burst starts as soon as 1-packet space is available. This works well
 * as long as the system bus is faster than the USB3.0 bus (a 1024-bytes packet takes ~2.2 us on
 * the USB bus in SuperSpeed mode). If the system bus latency is larger than 2.2 us to access a
 * 1024-byte packet, then starting a burst on 1-packet condition leads to an early abort of the
 * burst causing unnecessary performance reduction. This register allows the configuration of
 * threshold and burst size control. This feature is enabled by USBRXPKTCNTSEL.
 *
 * Receive Path:
 * * The RX threshold is controlled by USBRXPKTCNT and the RX burst size is controlled by
 * USBMAXRXBURSTSIZE.
 * * Selecting optimal RX FIFO size, RX Threshold, and RX burst size avoids RX burst aborts due
 * to overrun if the system bus is slower than USB. Once in a while overrun is OK, and there is
 * no functional issue.
 * * Some devices do not support terminating ACK retry. With these devices, host cannot set ACK=0
 * and Retry=0 and do retry later and you have to retry immediately. For such devices, minimize
 * retry due to underrun. Setting threshold and burst size guarantees this.
 * A larger RX threshold affects the performance since the scheduler is idle during this time.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.4.
 */
typedef union bdk_usbhx_uahc_grxthrcfg {
	uint32_t u;
	struct bdk_usbhx_uahc_grxthrcfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t usbrxpktcntsel              : 1;  /**< R/W - USB receive-packet-count enable. Enables/disables the USB reception multipacket
                                                                 thresholding:
                                                                 0 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 one packet.
                                                                 1 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 USBRXPKTCNT amount of packets.
                                                                 This mode is only used for SuperSpeed. */
		uint32_t reserved_28_28              : 1;
		uint32_t usbrxpktcnt                 : 4;  /**< R/W - USB receive-packet count. In host-mode, specifies space (in number of packets) that must
                                                                 be available in the RX FIFO before the core can start the corresponding USB RX transaction
                                                                 (burst).

                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0xF.
                                                                 This field must be \<= USBMAXRXBURSTSIZE. */
		uint32_t usbmaxrxburstsize           : 5;  /**< R/W - USB maximum receive-burst size. Specifies the maximum bulk IN burst the core
                                                                 should do. When the system bus is slower than the USB, RX FIFO can overrun during a long
                                                                 burst.

                                                                 Program a smaller value to this field to limit the RX burst size that the core can do. It
                                                                 only applies to SuperSpeed Bulk, Isochronous, and Interrupt IN endpoints.
                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0x10. */
		uint32_t reserved_0_18               : 19;
#else
		uint32_t reserved_0_18               : 19;
		uint32_t usbmaxrxburstsize           : 5;
		uint32_t usbrxpktcnt                 : 4;
		uint32_t reserved_28_28              : 1;
		uint32_t usbrxpktcntsel              : 1;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_usbhx_uahc_grxthrcfg_s  cn88xx; */
	/* struct bdk_usbhx_uahc_grxthrcfg_s  cn88xxp1; */
} bdk_usbhx_uahc_grxthrcfg_t;

static inline uint64_t BDK_USBHX_UAHC_GRXTHRCFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GRXTHRCFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C10Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GRXTHRCFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GRXTHRCFG(...) bdk_usbhx_uahc_grxthrcfg_t
#define bustype_BDK_USBHX_UAHC_GRXTHRCFG(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GRXTHRCFG(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GRXTHRCFG(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GRXTHRCFG(...) "USBHX_UAHC_GRXTHRCFG"


/**
 * NCB32b - usbh#_uahc_gsbuscfg0
 *
 * This register can be used to configure the core after power-on or a change in mode of
 * operation. This register mainly contains AXI system-related configuration parameters. Do not
 * change this register after the initial programming. The application must program this register
 * before starting any transactions on AXI. When INCRBRSTENA is enabled, it has the highest
 * priority over other burst lengths. The core always performs the largest burst when enabled.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: The AXI cache signals are not connected in Cavium's hookup, so the *REQINFO fields
 * can be ignored.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.1.
 */
typedef union bdk_usbhx_uahc_gsbuscfg0 {
	uint32_t u;
	struct bdk_usbhx_uahc_gsbuscfg0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t datrdreqinfo                : 4;  /**< R/W - AXI-cache for data-read operations. Always set to 0x0. */
		uint32_t desrdreqinfo                : 4;  /**< R/W - AXI-cache for descriptor-read operations. Always set to 0x0. */
		uint32_t datwrreqinfo                : 4;  /**< R/W - AXI-cache for data-write operations. Always set to 0x0. */
		uint32_t deswrreqinfo                : 4;  /**< R/W - AXI-cache for descriptor-write operations. Always set to 0x0. */
		uint32_t reserved_12_15              : 4;
		uint32_t datbigend                   : 1;  /**< R/W - Data access is big-endian. Keep this set to 0 (little-endian) and use the
                                                                 USBH()_UCTL_SHIM_CFG[DMA_ENDIAN_MODE] setting instead. */
		uint32_t descbigend                  : 1;  /**< R/W - Descriptor access is big-endian. Keep this set to 0 (little-endian) and use the
                                                                 USBH()_UCTL_SHIM_CFG[DMA_ENDIAN_MODE] setting instead. */
		uint32_t reserved_8_9                : 2;
		uint32_t incr256brstena              : 1;  /**< R/W - INCR256 burst-type enable. Always set to 0. */
		uint32_t incr128brstena              : 1;  /**< R/W - INCR128 burst-type enable. Always set to 0. */
		uint32_t incr64brstena               : 1;  /**< R/W - INCR64 burst-type enable. Always set to 0. */
		uint32_t incr32brstena               : 1;  /**< R/W - INCR32 burst-type enable. Always set to 0. */
		uint32_t incr16brstena               : 1;  /**< R/W - INCR16 burst-type enable. Allows the AXI master to generate INCR 16-beat bursts. */
		uint32_t incr8brstena                : 1;  /**< R/W - INCR8 burst-type enable. Allows the AXI master to generate INCR eight-beat bursts. */
		uint32_t incr4brstena                : 1;  /**< R/W - INCR4 burst-type enable. Allows the AXI master to generate INCR four-beat bursts. */
		uint32_t incrbrstena                 : 1;  /**< R/W - Undefined-length INCR burst-type enable.
                                                                 This bit determines the set of burst lengths to be utilized by the master interface. It
                                                                 works in conjunction with the GSBUSCFG0[7:1] enables (INCR*BRSTENA).

                                                                 If disabled, the AXI master will use only the burst lengths
                                                                 1, 4, 8, 16 (assuming the INCR*BRSTENA are set to their reset values).

                                                                 If enabled, the AXI master uses any length less than or equal to the largest-enabled burst
                                                                 length based on the INCR*BRSTENA fields. */
#else
		uint32_t incrbrstena                 : 1;
		uint32_t incr4brstena                : 1;
		uint32_t incr8brstena                : 1;
		uint32_t incr16brstena               : 1;
		uint32_t incr32brstena               : 1;
		uint32_t incr64brstena               : 1;
		uint32_t incr128brstena              : 1;
		uint32_t incr256brstena              : 1;
		uint32_t reserved_8_9                : 2;
		uint32_t descbigend                  : 1;
		uint32_t datbigend                   : 1;
		uint32_t reserved_12_15              : 4;
		uint32_t deswrreqinfo                : 4;
		uint32_t datwrreqinfo                : 4;
		uint32_t desrdreqinfo                : 4;
		uint32_t datrdreqinfo                : 4;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gsbuscfg0_s  cn88xx; */
	/* struct bdk_usbhx_uahc_gsbuscfg0_s  cn88xxp1; */
} bdk_usbhx_uahc_gsbuscfg0_t;

static inline uint64_t BDK_USBHX_UAHC_GSBUSCFG0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GSBUSCFG0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C100ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GSBUSCFG0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GSBUSCFG0(...) bdk_usbhx_uahc_gsbuscfg0_t
#define bustype_BDK_USBHX_UAHC_GSBUSCFG0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GSBUSCFG0(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GSBUSCFG0(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GSBUSCFG0(...) "USBHX_UAHC_GSBUSCFG0"


/**
 * NCB32b - usbh#_uahc_gsbuscfg1
 *
 * This register can be used to configure the core after power-on or a change in mode of
 * operation. This register mainly contains AXI system-related configuration parameters. Do not
 * change this register after the initial programming. The application must program this register
 * before starting any transactions on AXI.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.2.
 */
typedef union bdk_usbhx_uahc_gsbuscfg1 {
	uint32_t u;
	struct bdk_usbhx_uahc_gsbuscfg1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_13_31              : 19;
		uint32_t en1kpage                    : 1;  /**< R/W - 1K page-boundary enable.
                                                                 0 = Break transfers at the 4K page boundary (default).
                                                                 1 = Break transfers at the 1K page boundary. */
		uint32_t pipetranslimit              : 4;  /**< R/W - AXI pipelined transfers burst-request limit. Controls the number of outstanding pipelined
                                                                 transfers requests the AXI master will push to the AXI slave. Once the AXI master reaches
                                                                 this limit, it does not make more requests on the AXI ARADDR and AWADDR buses until the
                                                                 associated data phases complete. This field is encoded as follows:
                                                                 0x0 = 1 request. 0x8 = 9 requests.
                                                                 0x1 = 2 requests. 0x9 = 10 requests.
                                                                 0x2 = 3 requests. 0xA = 11 requests.
                                                                 0x3 = 4 requests. 0xB = 12 requests.
                                                                 0x4 = 5 requests. 0xC = 13 requests.
                                                                 0x5 = 6 requests. 0xD = 14 requests.
                                                                 0x6 = 7 requests. 0xE = 15 requests.
                                                                 0x7 = 8 requests. 0xF = 16 requests. */
		uint32_t reserved_0_7                : 8;
#else
		uint32_t reserved_0_7                : 8;
		uint32_t pipetranslimit              : 4;
		uint32_t en1kpage                    : 1;
		uint32_t reserved_13_31              : 19;
#endif
	} s;
	struct bdk_usbhx_uahc_gsbuscfg1_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_13              : 19;
		uint32_t en1kpage                    : 1;  /**< R/W - 1K page-boundary enable.
                                                                 0 = Break transfers at the 4K page boundary (default).
                                                                 1 = Break transfers at the 1K page boundary. */
		uint32_t pipetranslimit              : 4;  /**< R/W - AXI pipelined transfers burst-request limit. Controls the number of outstanding pipelined
                                                                 transfers requests the AXI master will push to the AXI slave. Once the AXI master reaches
                                                                 this limit, it does not make more requests on the AXI ARADDR and AWADDR buses until the
                                                                 associated data phases complete. This field is encoded as follows:
                                                                 0x0 = 1 request. 0x8 = 9 requests.
                                                                 0x1 = 2 requests. 0x9 = 10 requests.
                                                                 0x2 = 3 requests. 0xA = 11 requests.
                                                                 0x3 = 4 requests. 0xB = 12 requests.
                                                                 0x4 = 5 requests. 0xC = 13 requests.
                                                                 0x5 = 6 requests. 0xD = 14 requests.
                                                                 0x6 = 7 requests. 0xE = 15 requests.
                                                                 0x7 = 8 requests. 0xF = 16 requests. */
		uint32_t reserved_0_7                : 8;
#else
		uint32_t reserved_0_7                : 8;
		uint32_t pipetranslimit              : 4;
		uint32_t en1kpage                    : 1;
		uint32_t reserved_31_13              : 19;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gsbuscfg1_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gsbuscfg1_t;

static inline uint64_t BDK_USBHX_UAHC_GSBUSCFG1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GSBUSCFG1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C104ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GSBUSCFG1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GSBUSCFG1(...) bdk_usbhx_uahc_gsbuscfg1_t
#define bustype_BDK_USBHX_UAHC_GSBUSCFG1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GSBUSCFG1(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GSBUSCFG1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GSBUSCFG1(...) "USBHX_UAHC_GSBUSCFG1"


/**
 * NCB32b - usbh#_uahc_gsts
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.6.
 */
typedef union bdk_usbhx_uahc_gsts {
	uint32_t u;
	struct bdk_usbhx_uahc_gsts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cbelt                       : 12; /**< RO/H - Current BELT value. In host mode, indicates the minimum value of all received device BELT
                                                                 values and the BELT value that is set by the set latency tolerance value command. */
		uint32_t reserved_8_19               : 12;
		uint32_t host_ip                     : 1;  /**< RO/H - Host interrupt pending. Indicates that there is a pending interrupt pertaining to xHC in
                                                                 the host-event queue. */
		uint32_t reserved_6_6                : 1;
		uint32_t csrtimeout                  : 1;  /**< R/W1C/H - CSR timeout. When set to 1, indicates that software performed a write or read operation to
                                                                 a core register that could not be completed within 0xFFFF controller-clock cycles. */
		uint32_t buserraddrvld               : 1;  /**< R/W1C/H - Bus-error address valid. Indicates that USBH()_UAHC_GBUSERRADDR is valid and reports the
                                                                 first bus address that encounters a bus error. */
		uint32_t reserved_2_3                : 2;
		uint32_t curmod                      : 2;  /**< RO - Current mode of operation. Always 0x1. INTERNAL: May vary from 0x1 if you write
                                                                 USBH()_UAHC_GCTL[PRTCAPDIR]!=0x1. */
#else
		uint32_t curmod                      : 2;
		uint32_t reserved_2_3                : 2;
		uint32_t buserraddrvld               : 1;
		uint32_t csrtimeout                  : 1;
		uint32_t reserved_6_6                : 1;
		uint32_t host_ip                     : 1;
		uint32_t reserved_8_19               : 12;
		uint32_t cbelt                       : 12;
#endif
	} s;
	struct bdk_usbhx_uahc_gsts_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t cbelt                       : 12; /**< RO/H - Current BELT value. In host mode, indicates the minimum value of all received device BELT
                                                                 values and the BELT value that is set by the set latency tolerance value command. */
		uint32_t reserved_19_8               : 12;
		uint32_t host_ip                     : 1;  /**< RO/H - Host interrupt pending. Indicates that there is a pending interrupt pertaining to xHC in
                                                                 the host-event queue. */
		uint32_t reserved_6_6                : 1;
		uint32_t csrtimeout                  : 1;  /**< R/W1C/H - CSR timeout. When set to 1, indicates that software performed a write or read operation to
                                                                 a core register that could not be completed within 0xFFFF controller-clock cycles. */
		uint32_t buserraddrvld               : 1;  /**< R/W1C/H - Bus-error address valid. Indicates that USBH()_UAHC_GBUSERRADDR is valid and reports the
                                                                 first bus address that encounters a bus error. */
		uint32_t reserved_3_2                : 2;
		uint32_t curmod                      : 2;  /**< RO - Current mode of operation. Always 0x1. INTERNAL: May vary from 0x1 if you write
                                                                 USBH()_UAHC_GCTL[PRTCAPDIR]!=0x1. */
#else
		uint32_t curmod                      : 2;
		uint32_t reserved_3_2                : 2;
		uint32_t buserraddrvld               : 1;
		uint32_t csrtimeout                  : 1;
		uint32_t reserved_6_6                : 1;
		uint32_t host_ip                     : 1;
		uint32_t reserved_19_8               : 12;
		uint32_t cbelt                       : 12;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gsts_cn88xx     cn88xxp1;
} bdk_usbhx_uahc_gsts_t;

static inline uint64_t BDK_USBHX_UAHC_GSTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GSTS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C118ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GSTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GSTS(...) bdk_usbhx_uahc_gsts_t
#define bustype_BDK_USBHX_UAHC_GSTS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GSTS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GSTS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GSTS(...) "USBHX_UAHC_GSTS"


/**
 * NCB32b - usbh#_uahc_gtxfifoprihst
 *
 * This register specifies the relative DMA priority level among the host TXFIFOs (one per USB
 * bus instance) within the associated speed group (SuperSpeed or high-speed/full-speed/
 * low-speed). When multiple TXFIFOs compete for DMA service at a given time, the TXDMA arbiter
 * grants access on a packet-basis in the following manner:
 *
 * Among the FIFOs in the same speed group (SuperSpeed or high-speed/full-speed/low-speed):
 *
 * * High-priority TXFIFOs are granted access using round-robin arbitration.
 * * Low-priority TXFIFOs are granted access using round-robin arbitration only after high-
 * priority
 * TXFIFOs have no further processing to do (i.e., either the TXQs are empty or the corresponding
 * TXFIFOs do not have the required data).
 *
 * The TX DMA arbiter prioritizes the SuperSpeed group or high-speed/full-speed/low-speed group
 * according to the ratio programmed in
 * USBH()_UAHC_GDMAHLRATIO.
 *
 * For scatter-gather packets, the arbiter grants successive DMA requests to the same FIFO until
 * the entire packet is completed. The register size corresponds to the number of configured USB
 * bus instances; for example, in the default configuration, there are 3 USB bus instances (1
 * SuperSpeed, 1 high-speed, and 1 full-speed/low-speed).
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.2.
 */
typedef union bdk_usbhx_uahc_gtxfifoprihst {
	uint32_t u;
	struct bdk_usbhx_uahc_gtxfifoprihst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_3_31               : 29;
		uint32_t tx_priority                 : 3;  /**< R/W - Each register bit n controls the priority (1: high, 0: low) of TX FIFO\<n\> within a speed
                                                                 group. */
#else
		uint32_t tx_priority                 : 3;
		uint32_t reserved_3_31               : 29;
#endif
	} s;
	struct bdk_usbhx_uahc_gtxfifoprihst_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_3               : 29;
		uint32_t tx_priority                 : 3;  /**< R/W - Each register bit n controls the priority (1: high, 0: low) of TX FIFO\<n\> within a speed
                                                                 group. */
#else
		uint32_t tx_priority                 : 3;
		uint32_t reserved_31_3               : 29;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gtxfifoprihst_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gtxfifoprihst_t;

static inline uint64_t BDK_USBHX_UAHC_GTXFIFOPRIHST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GTXFIFOPRIHST(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C618ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GTXFIFOPRIHST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GTXFIFOPRIHST(...) bdk_usbhx_uahc_gtxfifoprihst_t
#define bustype_BDK_USBHX_UAHC_GTXFIFOPRIHST(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GTXFIFOPRIHST(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GTXFIFOPRIHST(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GTXFIFOPRIHST(...) "USBHX_UAHC_GTXFIFOPRIHST"


/**
 * NCB32b - usbh#_uahc_gtxfifosiz#
 *
 * This register holds the internal RAM start address/depth of each TxFIFO implemented. Unless
 * packet size/buffer size for each endpoint is different and application-specific, it is
 * recommended that the software use the default value. One register per FIFO. One register per
 * FIFO.
 *
 * Reset values = 0:{0x0000_0082} 1:{0x0082_0103} 2:{0x0185_0205}.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.6.1.
 * INTERNAL: For more information, refer to the BMU section in Block Descriptions on Synopsys
 * Databook page 238.
 */
typedef union bdk_usbhx_uahc_gtxfifosizx {
	uint32_t u;
	struct bdk_usbhx_uahc_gtxfifosizx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t txfstaddr                   : 16; /**< R/W - Transmit FIFOn RAM start address. Contains the memory start address for TxFIFOn. The reset
                                                                 is value derived from configuration parameters. */
		uint32_t txfdep                      : 16; /**< R/W - TxFIFOn depth. This value is in terms of TX RAM data width.
                                                                 minimum value = 0x20, maximum value = 0x8000.
                                                                 INTERNAL: For more information, see the Hardware Integration chapter of the Synopsys
                                                                 Databook.
                                                                 The reset value derived from configuration parameters. */
#else
		uint32_t txfdep                      : 16;
		uint32_t txfstaddr                   : 16;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gtxfifosizx_s cn88xx; */
	/* struct bdk_usbhx_uahc_gtxfifosizx_s cn88xxp1; */
} bdk_usbhx_uahc_gtxfifosizx_t;

static inline uint64_t BDK_USBHX_UAHC_GTXFIFOSIZX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GTXFIFOSIZX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x000086800000C300ull + (param1 & 1) * 0x1000000000ull + (param2 & 3) * 0x4ull;
	csr_fatal("BDK_USBHX_UAHC_GTXFIFOSIZX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GTXFIFOSIZX(...) bdk_usbhx_uahc_gtxfifosizx_t
#define bustype_BDK_USBHX_UAHC_GTXFIFOSIZX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GTXFIFOSIZX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_GTXFIFOSIZX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_GTXFIFOSIZX(...) "USBHX_UAHC_GTXFIFOSIZX"


/**
 * NCB32b - usbh#_uahc_gtxthrcfg
 *
 * In a normal case, a TX burst starts as soon as one packet is prefetched. This works well as
 * long as the system bus is faster than the USB3.0 bus (a 1024-bytes packet takes ~2.2 us on the
 * USB bus in SuperSpeed mode). If the system bus latency is larger than 2.2 us to access a
 * 1024-byte packet, then starting a burst on 1-packet condition leads to an early abort of the
 * burst causing unnecessary performance reduction. This register allows the configuration of
 * threshold and burst size control. This feature is enabled by [USBTXPKTCNTSEL].
 *
 * Transmit Path:
 * * The TX Threshold is controlled by [USBTXPKTCNT], and the TX burst size is controlled by
 * [USBMAXTXBURSTSIZE].
 * * Selecting optimal TX FIFO size, TX Threshold, and TX burst size avoids TX burst aborts due
 * to an underrun if the system bus is slower than USB. Once in a while an underrun is OK, and
 * there is no functional issue.
 * * A larger threshold affects the performance, since the scheduler is idle during this time.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.3.
 */
typedef union bdk_usbhx_uahc_gtxthrcfg {
	uint32_t u;
	struct bdk_usbhx_uahc_gtxthrcfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_30_31              : 2;
		uint32_t usbtxpktcntsel              : 1;  /**< R/W - USB transmit packet-count enable. Enables/disables the USB transmission multipacket
                                                                 thresholding:
                                                                 0 = USB transmission multipacket thresholding is disabled, the core can only start
                                                                 transmission on the USB after the entire packet has been fetched into the corresponding
                                                                 TXFIFO.
                                                                 1 = USB transmission multipacket thresholding is enabled. The core can only start
                                                                 transmission on the USB after USBTXPKTCNT amount of packets for the USB transaction
                                                                 (burst) are already in the corresponding TXFIFO.
                                                                 This mode is only used for SuperSpeed. */
		uint32_t reserved_28_28              : 1;
		uint32_t usbtxpktcnt                 : 4;  /**< R/W - USB transmit-packet count. Specifies the number of packets that must be in the TXFIFO
                                                                 before the core can start transmission for the corresponding USB transaction (burst). This
                                                                 field is only valid when USBTXPKTCNTSEL = 1. Valid values are from 0x1 to 0xF.
                                                                 This field must be \<= USBMAXTXBURSTSIZE. */
		uint32_t usbmaxtxburstsize           : 8;  /**< R/W - USB maximum TX burst size. When USBTXPKTCNTSEL = 1, this field specifies the maximum bulk
                                                                 OUT burst the core should do. When the system bus is slower than the USB, TX FIFO can
                                                                 underrun during a long burst. Program a smaller value to this field to limit the TX burst
                                                                 size that the core can do. It only applies to SuperSpeed Bulk, Isochronous, and Interrupt
                                                                 OUT endpoints in the host mode. Valid values are from 0x1 to 0x10. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t usbmaxtxburstsize           : 8;
		uint32_t usbtxpktcnt                 : 4;
		uint32_t reserved_28_28              : 1;
		uint32_t usbtxpktcntsel              : 1;
		uint32_t reserved_30_31              : 2;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gtxthrcfg_s  cn88xx; */
	/* struct bdk_usbhx_uahc_gtxthrcfg_s  cn88xxp1; */
} bdk_usbhx_uahc_gtxthrcfg_t;

static inline uint64_t BDK_USBHX_UAHC_GTXTHRCFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GTXTHRCFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C108ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GTXTHRCFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GTXTHRCFG(...) bdk_usbhx_uahc_gtxthrcfg_t
#define bustype_BDK_USBHX_UAHC_GTXTHRCFG(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GTXTHRCFG(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GTXTHRCFG(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GTXTHRCFG(...) "USBHX_UAHC_GTXTHRCFG"


/**
 * NCB32b - usbh#_uahc_guctl
 *
 * This register provides a few options for the software to control the core behavior in the host
 * mode. Most of the options are used to improve host inter-operability with different devices.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.11.
 */
typedef union bdk_usbhx_uahc_guctl {
	uint32_t u;
	struct bdk_usbhx_uahc_guctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t refclkper                   : 10; /**< R/W - Reference-clock period. Indicates (in terms of ns) the period of REF_CLK. The default
                                                                 value is set to 0x8
                                                                 (8 ns/125 MHz). This field must be updated during power on initialization if
                                                                 USBH()_UAHC_GCTL[SOFITPSYNC] = 1 or USBH()_UAHC_GFLADJ [GFLADJ_REFCLK_LPM_SEL] = 1. The
                                                                 programmable maximum value 62 ns, and the minimum value is 8 ns. You use a reference clock
                                                                 with a period that is a integer multiple, so that ITP can meet the jitter margin of 32 ns.
                                                                 The allowable REF_CLK frequencies whose period is not integer multiples are
                                                                 16/17/19.2/24/39.7 MHz.

                                                                 This field should not be set to 0x0 at any time. If you do not plan to use this feature,
                                                                 then you need to set this field to 0x8, the default value. */
		uint32_t noextrdl                    : 1;  /**< R/W - No extra delay between SOF and the first packet.
                                                                 Some high-speed devices misbehave when the host sends a packet immediately after an SOF.
                                                                 However, adding an extra delay between an SOF and the first packet can reduce the USB data
                                                                 rate and performance.

                                                                 This bit is used to control whether the host should wait for 2 us before it sends the
                                                                 first packet after a SOF, or not. You can set this bit to 1 to improve the performance if
                                                                 those problematic devices are not a concern in your host environment.
                                                                 0 = host waits for 2 us after an SOF before it sends the first USB packet.
                                                                 1 = host does not wait after an SOF before it sends the first USB packet. */
		uint32_t psqextrressp                : 3;  /**< R/W - PSQ extra reserved space. This is a debug feature, and is not intended for normal usage.
                                                                 This parameter specifies how much additional space in the PSQ (protocol-status queue) must
                                                                 be reserved before the U3PTL initiates a new USB transaction and burst beats. */
		uint32_t sprsctrltransen             : 1;  /**< R/W - Sparse control transaction enable. Some devices are slow in responding to control
                                                                 transfers. Scheduling multiple transactions in one microframe/frame can cause these
                                                                 devices to misbehave. If this bit is set to 1, the host controller schedules transactions
                                                                 for a control transfer in different microframes/frames. */
		uint32_t resbwhseps                  : 1;  /**< R/W - Reserving 85% bandwidth for high-speed periodic EPs. By default, host controller reserves
                                                                 80% of the bandwidth for periodic EPs. If this bit is set, the bandwidth is relaxed to 85%
                                                                 to accommodate two high-speed, high-bandwidth ISOC EPs.

                                                                 USB 2.0 required 80% bandwidth allocated for ISOC traffic. If two high bandwidth ISOC
                                                                 devices (HD webcams) are connected, and if each requires 1024-bytes * 3 packets per
                                                                 microframe, then the bandwidth required is around 82%. If this bit is set to 1, it is
                                                                 possible to connect two webcams of 1024 bytes * 3 payload per microframe each. Otherwise,
                                                                 you may have to reduce the resolution of the webcams. */
		uint32_t cmdevaddr                   : 1;  /**< R/W - Compliance mode for device address. When set to 1, slot ID can have different value than
                                                                 device address if max_slot_enabled \< 128.
                                                                 0 = Device address is equal to slot ID.
                                                                 1 = Increment device address on each address device command.

                                                                 The xHCI compliance requires this bit to be set to 1. The 0 mode is for debug purpose
                                                                 only. This allows you to easily identify a device connected to a port in the Lecroy or
                                                                 Eliisys trace during hardware debug. */
		uint32_t usbhstinautoretryen         : 1;  /**< R/W - Host IN auto-retry enable. When set, this field enables the auto-retry feature. For IN
                                                                 transfers (non-isochronous) that encounter data packets with CRC errors or internal
                                                                 overrun scenarios, the auto-retry feature causes the host core to reply to the device with
                                                                 a non-terminating retry ACK (i.e. an ACK transaction packet with Retry = 1 and NumP != 0).
                                                                 If the auto-retry feature is disabled (default), the core responds with a terminating
                                                                 retry ACK (i.e. an ACK transaction packet with Retry = 1 and NumP = 0). */
		uint32_t enoverlapchk                : 1;  /**< R/W - Enable check for LFPS overlap during remote Ux Exit. If this bit is set to:
                                                                 0 = When the link exists U1/U2/U3 because of a remote exit, it does not look for an LFPS
                                                                 overlap.
                                                                 1 = The SuperSpeed link, when exiting U1/U2/U3, waits for either the remote link LFPS or
                                                                 TS1/TS2 training symbols before it confirms that the LFPS handshake is complete. This is
                                                                 done to handle the case where the LFPS glitch causes the link to start exiting from the
                                                                 low power state. Looking for the LFPS overlap makes sure that the link partner also sees
                                                                 the LFPS. */
		uint32_t extcapsupten                : 1;  /**< R/W - External extended capability support enable. If disabled, a read USBH()_UAHC_SUPTPRT3_DW0
                                                                 [NEXTCAPPTR] returns 0 in the next capability pointer field. This indicates there are no
                                                                 more capabilities. If enabled, a read to USBH()_UAHC_SUPTPRT3_DW0[NEXTCAPPTR] returns 4 in
                                                                 the
                                                                 next capability pointer field.
                                                                 Always set to 0x0. */
		uint32_t insrtextrfsbodi             : 1;  /**< R/W - Insert extra delay between full-speed bulk OUT transactions. Some full-speed devices are
                                                                 slow to receive bulk OUT data and can get stuck when there are consecutive bulk OUT
                                                                 transactions with short inter-transaction delays. This bit is used to control whether the
                                                                 host inserts extra delay between consecutive bulk OUT transactions to a full-speed
                                                                 endpoint.
                                                                 0 = Host does not insert extra delay.
                                                                 Setting this bit to 1 reduces the bulk OUT transfer performance for most of the full-speed
                                                                 devices.
                                                                 1 = Host inserts about 12 us extra delay between consecutive bulk OUT transactions to an
                                                                 full-speed endpoint to work around the device issue. */
		uint32_t dtct                        : 2;  /**< R/W - Device timeout coarse tuning. This field determines how long the host waits for a response
                                                                 from device before considering a timeout.
                                                                 The core first checks the DTCT value. If it is 0, then the timeout value is defined by the
                                                                 DTFT. If it is non-zero, then it uses the following timeout values:
                                                                 0x0 = 0 us; use DTFT value instead.
                                                                 0x1 = 500 us.
                                                                 0x2 = 1.5 ms.
                                                                 0x3 = 6.5 ms. */
		uint32_t dtft                        : 9;  /**< R/W - Device timeout fine tuning. This field determines how long the host waits for a response
                                                                 from a device before considering a timeout. For DTFT to take effect, DTCT must be set to
                                                                 0x0.
                                                                 The DTFT value specifies the number of 125MHz clock cycles * 256 to count before
                                                                 considering a device timeout. For the 125 MHz clock cycles (8 ns period), this is
                                                                 calculated as follows:
                                                                 _ [DTFT value] * 256 * 8 (ns)
                                                                 0x2 = 2 * 256 * 8 -\> 4 us.
                                                                 0x5 = 5 * 256 * 8 -\> 10 us.
                                                                 0xA = 10 * 256 * 8 -\> 20 us.
                                                                 0x10 = 16 * 256 * 8 -\> 32 us.
                                                                 0x19 = 25 * 256 * 8 -\> 51 us.
                                                                 0x31 = 49 * 256 * 8 -\> 100 us.
                                                                 0x62 = 98 * 256 * 8 -\> 200 us. */
#else
		uint32_t dtft                        : 9;
		uint32_t dtct                        : 2;
		uint32_t insrtextrfsbodi             : 1;
		uint32_t extcapsupten                : 1;
		uint32_t enoverlapchk                : 1;
		uint32_t usbhstinautoretryen         : 1;
		uint32_t cmdevaddr                   : 1;
		uint32_t resbwhseps                  : 1;
		uint32_t sprsctrltransen             : 1;
		uint32_t psqextrressp                : 3;
		uint32_t noextrdl                    : 1;
		uint32_t refclkper                   : 10;
#endif
	} s;
	/* struct bdk_usbhx_uahc_guctl_s      cn88xx; */
	/* struct bdk_usbhx_uahc_guctl_s      cn88xxp1; */
} bdk_usbhx_uahc_guctl_t;

static inline uint64_t BDK_USBHX_UAHC_GUCTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GUCTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C12Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GUCTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GUCTL(...) bdk_usbhx_uahc_guctl_t
#define bustype_BDK_USBHX_UAHC_GUCTL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GUCTL(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GUCTL(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GUCTL(...) "USBHX_UAHC_GUCTL"


/**
 * NCB32b - usbh#_uahc_guctl1
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.7.
 */
typedef union bdk_usbhx_uahc_guctl1 {
	uint32_t u;
	struct bdk_usbhx_uahc_guctl1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_18_31              : 14;
		uint32_t parkmode_disable_ss         : 1;  /**< R/W - This bit is for debug purpose only.
                                                                 When this bit is set to 1 all SS bus instances in park mode are
                                                                 disabled. */
		uint32_t parkmode_disable_hs         : 1;  /**< R/W - When this bit is set to 1 all HS bus instances park mode are
                                                                 disabled. */
		uint32_t parkmode_disable_fsls       : 1;  /**< R/W - When this bit is set to 1 all FS/LS bus instances park mode are
                                                                 disabled. */
		uint32_t reserved_9_14               : 6;
		uint32_t l1_susp_thrld_en_for_host   : 1;  /**< R/W - The controller puts the PHY into deep low-power mode in L1 when both of the
                                                                 following are true:
                                                                 - The HIRD/BESL value used is greater than or equal to the
                                                                   value in L1_SUSP_THRLD_FOR_HOST field.
                                                                 - The L1_SUSP_THRLD_EN_FOR_HOST bit is set to 1'b1.
                                                                 The controller the UTMI PHY transitions to shallow low-power
                                                                 mode in L1 by powering down necessary blocks when one of the
                                                                 following is true:
                                                                 - The HIRD/BESL value used is less than the value in
                                                                   L1_SUSP_THRLD_FOR_HOST field.
                                                                 - The L1_SUSP_THRLD_EN_FOR_HOST bit is set to 1'b0. */
		uint32_t l1_susp_thrld_for_host      : 4;  /**< R/W - This field is effective only when the L1_SUSP_THRLD_EN_FOR_HOST is set t0 1. */
		uint32_t helden                      : 1;  /**< R/W - When this bit is set to 1, it enables the Exit Latency Delta (ELD)
                                                                 support defined in the xHCI 1.0 Errata. */
		uint32_t hparchkdisable              : 1;  /**< R/W - When this bit is set to 0 (by default), the xHC checks that the input
                                                                 slot/EP context fields comply to the xHCI Specification. Upon
                                                                 detection of a parameter error during command execution, the
                                                                 xHC generates an event TRB with completion code indicating
                                                                 'PARAMETER ERROR'.
                                                                 When the bit is set to 1, the xHC does not perform parameter
                                                                 checks and does not generate 'PARAMETER ERROR' completion
                                                                 code. */
		uint32_t ovrld_l1_susp_com           : 1;  /**< R/W - Always set to 0. */
		uint32_t loa_filter_en               : 1;  /**< R/W - If this bit is set, the USB 2.0 port babble is checked at least three consecutive times
                                                                 before the port is disabled. This prevents false triggering of the babble condition when
                                                                 using low quality cables. */
#else
		uint32_t loa_filter_en               : 1;
		uint32_t ovrld_l1_susp_com           : 1;
		uint32_t hparchkdisable              : 1;
		uint32_t helden                      : 1;
		uint32_t l1_susp_thrld_for_host      : 4;
		uint32_t l1_susp_thrld_en_for_host   : 1;
		uint32_t reserved_9_14               : 6;
		uint32_t parkmode_disable_fsls       : 1;
		uint32_t parkmode_disable_hs         : 1;
		uint32_t parkmode_disable_ss         : 1;
		uint32_t reserved_18_31              : 14;
#endif
	} s;
	/* struct bdk_usbhx_uahc_guctl1_s     cn88xx; */
	/* struct bdk_usbhx_uahc_guctl1_s     cn88xxp1; */
} bdk_usbhx_uahc_guctl1_t;

static inline uint64_t BDK_USBHX_UAHC_GUCTL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GUCTL1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C11Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GUCTL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GUCTL1(...) bdk_usbhx_uahc_guctl1_t
#define bustype_BDK_USBHX_UAHC_GUCTL1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GUCTL1(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GUCTL1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GUCTL1(...) "USBHX_UAHC_GUCTL1"


/**
 * NCB32b - usbh#_uahc_guid
 *
 * This is a read/write register containing the User ID. The power-on value for this register is
 * specified as the User Identification Register. This register can be used in the following
 * ways:
 * * To store the version or revision of your system.
 * * To store hardware configurations that are outside of the core.
 * * As a scratch register.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.10.
 */
typedef union bdk_usbhx_uahc_guid {
	uint32_t u;
	struct bdk_usbhx_uahc_guid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t userid                      : 32; /**< R/W - User ID. Application-programmable ID field. */
#else
		uint32_t userid                      : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_guid_s       cn88xx; */
	/* struct bdk_usbhx_uahc_guid_s       cn88xxp1; */
} bdk_usbhx_uahc_guid_t;

static inline uint64_t BDK_USBHX_UAHC_GUID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GUID(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000C128ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GUID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GUID(...) bdk_usbhx_uahc_guid_t
#define bustype_BDK_USBHX_UAHC_GUID(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GUID(p1) (p1)
#define arguments_BDK_USBHX_UAHC_GUID(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_GUID(...) "USBHX_UAHC_GUID"


/**
 * NCB32b - usbh#_uahc_gusb2i2cctl#
 *
 * This register is reserved for future use.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.5.2.
 */
typedef union bdk_usbhx_uahc_gusb2i2cctlx {
	uint32_t u;
	struct bdk_usbhx_uahc_gusb2i2cctlx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	struct bdk_usbhx_uahc_gusb2i2cctlx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_0               : 32;
#else
		uint32_t reserved_31_0               : 32;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_gusb2i2cctlx_cn88xx cn88xxp1;
} bdk_usbhx_uahc_gusb2i2cctlx_t;

static inline uint64_t BDK_USBHX_UAHC_GUSB2I2CCTLX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GUSB2I2CCTLX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000086800000C240ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GUSB2I2CCTLX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GUSB2I2CCTLX(...) bdk_usbhx_uahc_gusb2i2cctlx_t
#define bustype_BDK_USBHX_UAHC_GUSB2I2CCTLX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GUSB2I2CCTLX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_GUSB2I2CCTLX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_GUSB2I2CCTLX(...) "USBHX_UAHC_GUSB2I2CCTLX"


/**
 * NCB32b - usbh#_uahc_gusb2phycfg#
 *
 * This register is used to configure the core after power-on. It contains USB 2.0 and USB 2.0
 * PHY-related configuration parameters. The application must program this register before
 * starting any transactions on either the SoC bus or the USB. Per-port registers are
 * implemented.
 *
 * Do not make changes to this register after the initial programming.
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.5.1.
 * Reset by: NCB reset or USBH()_UCTL_CTL[UAHC_RST].
 */
typedef union bdk_usbhx_uahc_gusb2phycfgx {
	uint32_t u;
	struct bdk_usbhx_uahc_gusb2phycfgx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t physoftrst                  : 1;  /**< R/W - PHY soft reset. Causes the usb2phy_reset signal to be asserted to reset a UTMI PHY. */
		uint32_t u2_freeclk_exists           : 1;  /**< R/W - Specifies whether your USB 2.0 PHY provides a free-running PHY clock, which is active when
                                                                 the clock control input is active. If your USB 2.0 PHY provides a free-running PHY clock,
                                                                 it must be connected to the utmi_clk[0] input. The remaining utmi_clk[n] must be connected
                                                                 to the respective port clocks. The core uses the Port-0 clock for generating the internal
                                                                 mac2 clock.
                                                                 0 = USB 2.0 free clock does not exist.
                                                                 1 = USB 2.0 free clock exists.

                                                                 This field must be set to zero if you enable ITP generation based on the REF_CLK
                                                                 counter, USBH()_UAHC_GCTL[SOFITPSYNC] = 1, or USBH()_UAHC_GFLADJ [GFLADJ_REFCLK_LPM_SEL] =
                                                                 1. */
		uint32_t ulpi_lpm_with_opmode_chk    : 1;  /**< R/W - Support the LPM over ULPI without NOPID token to the ULPI PHY. Always 0x0. */
		uint32_t hsic_con_width_adj          : 2;  /**< RO - This bit is used in the HSIC device mode of operation. Always 0x0 */
		uint32_t inv_sel_hsic                : 1;  /**< RO - The application driver uses this bit to control the HSIC enable/disable function. */
		uint32_t reserved_19_25              : 7;
		uint32_t ulpiextvbusindicator        : 1;  /**< R/W - Reserved (unused in this configuration). */
		uint32_t ulpiextvbusdrv              : 1;  /**< R/W - Reserved (unused in this configuration). */
		uint32_t ulpiclksusm                 : 1;  /**< R/W - Reserved (unused in this configuration). */
		uint32_t ulpiautores                 : 1;  /**< R/W - Reserved (unused in this configuration). */
		uint32_t reserved_14_14              : 1;
		uint32_t usbtrdtim                   : 4;  /**< R/W - USB 2.0 turnaround time. Sets the turnaround time in PHY clock cycles. Specifies the
                                                                 response time for a MAC request to the packet FIFO controller (PFC) to fetch data from the
                                                                 DFIFO (SPRAM).
                                                                 USB turnaround time is a critical certification criteria when using long cables and five
                                                                 hub levels.
                                                                 When the MAC interface is 8-bit UTMI+/ULPI, the required values for this field is 0x9. */
		uint32_t reserved_9_9                : 1;
		uint32_t enblslpm                    : 1;  /**< R/W - Enable utmi_sleep_n and utmi_l1_suspend_n. The application uses this field to control
                                                                 utmi_sleep_n and utmi_l1_suspend_n assertion to the PHY in the L1 state.
                                                                 0 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is not transferred to the
                                                                 external PHY.
                                                                 1 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is transferred to the
                                                                 external PHY.

                                                                 When hardware LPM is enabled, this bit should be set high for Port0. */
		uint32_t physel                      : 1;  /**< WO - USB 2.0 high-speed PHY or USB 1.1 full-speed serial transceiver select. */
		uint32_t susphy                      : 1;  /**< R/W - Suspend USB2.0 high-speed/full-speed/low-speed PHY. When set, USB2.0 PHY enters suspend
                                                                 mode if suspend conditions are valid. */
		uint32_t fsintf                      : 1;  /**< RO - Full-speed serial-interface select. Always reads as 0x0. */
		uint32_t ulpi_utmi_sel               : 1;  /**< RO - ULPI or UTMI+ select. Always reads as 0x0, indicating UTMI+. */
		uint32_t phyif                       : 1;  /**< R/W - PHY interface width: 1 = 16-bit, 0 = 8-bit.
                                                                 All the enabled 2.0 ports should have the same clock frequency as Port0 clock frequency
                                                                 (utmi_clk[0]).
                                                                 The UTMI 8-bit and 16-bit modes cannot be used together for different ports at the same
                                                                 time (i.e., all the ports should be in 8-bit mode, or all of them should be in 16-bit
                                                                 mode). */
		uint32_t toutcal                     : 3;  /**< R/W - High-speed/full-speed timeout calibration.
                                                                 The number of PHY clock cycles, as indicated by the application in this field, is
                                                                 multiplied by a bit-time factor; this factor is added to the high-speed/full-speed
                                                                 interpacket timeout duration in the core to account for additional delays introduced by
                                                                 the PHY. This might be required, since the delay introduced by the PHY in generating the
                                                                 linestate condition can vary among PHYs.

                                                                 The USB standard timeout value for high-speed operation is 736 to 816 (inclusive) bit
                                                                 times. The USB standard timeout value for full-speed operation is 16 to 18 (inclusive) bit
                                                                 times. The application must program this field based on the speed of connection.

                                                                 The number of bit times added per PHY clock are:
                                                                 * High-speed operation:
                                                                 - one 30-MHz PHY clock = 16 bit times.
                                                                 - one 60-MHz PHY clock = 8 bit times.

                                                                 * Full-speed operation:
                                                                 - one 30-MHz PHY clock = 0.4 bit times.
                                                                 - one 60-MHz PHY clock = 0.2 bit times.
                                                                 - one 48-MHz PHY clock = 0.25 bit times. */
#else
		uint32_t toutcal                     : 3;
		uint32_t phyif                       : 1;
		uint32_t ulpi_utmi_sel               : 1;
		uint32_t fsintf                      : 1;
		uint32_t susphy                      : 1;
		uint32_t physel                      : 1;
		uint32_t enblslpm                    : 1;
		uint32_t reserved_9_9                : 1;
		uint32_t usbtrdtim                   : 4;
		uint32_t reserved_14_14              : 1;
		uint32_t ulpiautores                 : 1;
		uint32_t ulpiclksusm                 : 1;
		uint32_t ulpiextvbusdrv              : 1;
		uint32_t ulpiextvbusindicator        : 1;
		uint32_t reserved_19_25              : 7;
		uint32_t inv_sel_hsic                : 1;
		uint32_t hsic_con_width_adj          : 2;
		uint32_t ulpi_lpm_with_opmode_chk    : 1;
		uint32_t u2_freeclk_exists           : 1;
		uint32_t physoftrst                  : 1;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gusb2phycfgx_s cn88xx; */
	/* struct bdk_usbhx_uahc_gusb2phycfgx_s cn88xxp1; */
} bdk_usbhx_uahc_gusb2phycfgx_t;

static inline uint64_t BDK_USBHX_UAHC_GUSB2PHYCFGX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GUSB2PHYCFGX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000086800000C200ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GUSB2PHYCFGX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GUSB2PHYCFGX(...) bdk_usbhx_uahc_gusb2phycfgx_t
#define bustype_BDK_USBHX_UAHC_GUSB2PHYCFGX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GUSB2PHYCFGX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_GUSB2PHYCFGX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_GUSB2PHYCFGX(...) "USBHX_UAHC_GUSB2PHYCFGX"


/**
 * NCB32b - usbh#_uahc_gusb3pipectl#
 *
 * This register is used to configure the core after power-on. It contains USB 3.0 and USB 3.0
 * PHY-related configuration parameters. The application must program this register before
 * starting any transactions on either the SoC bus or the USB. Per-port registers are
 * implemented.
 *
 * Do not make changes to this register after the initial programming.
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.5.4.
 * Reset by: NCB reset or USBH()_UCTL_CTL[UAHC_RST].
 */
typedef union bdk_usbhx_uahc_gusb3pipectlx {
	uint32_t u;
	struct bdk_usbhx_uahc_gusb3pipectlx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t physoftrst                  : 1;  /**< R/W - USB3 PHY soft reset (PHYSoftRst). When set to 1, initiates a PHY soft reset. After setting
                                                                 this bit to 1, the software needs to clear this bit. */
		uint32_t hstprtcmpl                  : 1;  /**< R/W - Host port compliance. Setting this bit to 1 enables placing the SuperSpeed port link into
                                                                 a compliance state, which allows testing of the PIPE PHY compliance patterns without
                                                                 having to have a test fixture on the USB 3.0 cable. By default, this bit should be set to
                                                                 0.

                                                                 In compliance-lab testing, the SuperSpeed port link enters compliance after failing the
                                                                 first polling sequence after power on. Set this bit to 0 when you run compliance tests.

                                                                 The sequence for using this functionality is as follows:
                                                                 * Disconnect any plugged-in devices.
                                                                 * Set USBH()_UAHC_USBCMD[HCRST] = 1 or power-on-chip reset.
                                                                 * Set USBH()_UAHC_PORTSC()[PP] = 0.
                                                                 * Set HSTPRTCMPL = 1. This places the link into compliance state.

                                                                 To advance the compliance pattern, follow this sequence (toggle HSTPRTCMPL):
                                                                 * Set HSTPRTCMPL = 0.
                                                                 * Set HSTPRTCMPL = 1. This advances the link to the next compliance pattern.

                                                                 To exit from the compliance state, set USBH()_UAHC_USBCMD[HCRST] = 1 or power-on-chip
                                                                 reset. */
		uint32_t u2ssinactp3ok               : 1;  /**< R/W - P3 OK for U2/SS.Inactive:
                                                                 0 = During link state U2/SS.Inactive, put PHY in P2 (default).
                                                                 1 = During link state U2/SS.Inactive, put PHY in P3. */
		uint32_t disrxdetp3                  : 1;  /**< R/W - Disables receiver detection in P3. If PHY is in P3 and the core needs to perform receiver
                                                                 detection:
                                                                 0 = Core performs receiver detection in P3 (default).
                                                                 1 = Core changes the PHY power state to P2 and then performs receiver detection. After
                                                                 receiver detection, core changes PHY power state to P3. */
		uint32_t ux_exit_in_px               : 1;  /**< R/W - UX exit in Px:
                                                                 0 = Core does U1/U2/U3 exit in PHY power state P0 (default behavior).
                                                                 1 = Core does U1/U2/U3 exit in PHY power state P1/P2/P3 respectively.

                                                                 This bit is added for SuperSpeed PHY workaround where SuperSpeed PHY injects a glitch on
                                                                 pipe3_RxElecIdle while receiving Ux exit LFPS, and pipe3_PowerDown change is in progress.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
		uint32_t ping_enchance_en            : 1;  /**< R/W - Ping enhancement enable. When set to 1, the downstream-port U1-ping-receive timeout
                                                                 becomes 500 ms instead of 300 ms. Minimum Ping.LFPS receive duration is 8 ns (one mac3_clk
                                                                 cycle). This field is valid for the downstream port only.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
		uint32_t u1u2exitfail_to_recov       : 1;  /**< R/W - U1U2exit fail to recovery. When set to 1, and U1/U2 LFPS handshake fails, the LTSSM
                                                                 transitions from U1/U2 to recovery instead of SS.inactive.
                                                                 If recovery fails, then the LTSSM can enter SS.Inactive. This is an enhancement only. It
                                                                 prevents interoperability issue if the remote link does not do the proper handshake. */
		uint32_t request_p1p2p3              : 1;  /**< R/W - Always request P1/P2/P3 for U1/U2/U3.
                                                                 0 = if immediate Ux exit (remotely initiated, or locally initiated) happens, the core does
                                                                 not request P1/P2/P3 power state change.
                                                                 1 = the core always requests PHY power change from P0 to P1/P2/P3 during U0 to U1/U2/U3
                                                                 transition.

                                                                 INTERNAL: Note: This bit should be set to 1 for Synopsys PHY. For third-party SuperSpeed
                                                                 PHY, check with your PHY vendor. */
		uint32_t startrxdetu3rxdet           : 1;  /**< WO - Start receiver detection in U3/Rx.Detect.
                                                                 If DISRXDETU3RXDET is set to 1 during reset, and the link is in U3 or Rx.Detect state, the
                                                                 core starts receiver detection on rising edge of this bit.
                                                                 This bit is valid for downstream ports only, and this feature must not be enabled for
                                                                 normal operation.
                                                                 INTERNAL: If have to use this feature, contact Synopsys. */
		uint32_t disrxdetu3rxdet             : 1;  /**< R/W - Disable receiver detection in U3/Rx.Detect. When set to 1, the core does not do receiver
                                                                 detection in U3 or Rx.Detect state. If STARTRXDETU3RXDET is set to 1 during reset,
                                                                 receiver detection starts manually.
                                                                 This bit is valid for downstream ports only, and this feature must not be enabled for
                                                                 normal operation.
                                                                 INTERNAL: If have to use this feature, contact Synopsys. */
		uint32_t delaypx                     : 3;  /**< R/W - Delay P1P2P3. Delay P0 to P1/P2/P3 request when entering U1/U2/U3 until (DELAYPX * 8)
                                                                 8B10B error occurs, or Pipe3_RxValid drops to 0.
                                                                 DELAYPXTRANSENTERUX must reset to 1 to enable this functionality.
                                                                 INTERNAL: Should always be 0x1 for a Synopsys PHY. */
		uint32_t delaypxtransenterux         : 1;  /**< R/W - Delay PHY power change from P0 to P1/P2/P3 when link state changing from U0 to U1/U2/U3
                                                                 respectively.
                                                                 0 = when entering U1/U2/U3, transition to P1/P2/P3 without checking for Pipe3_RxElecIlde
                                                                 and pipe3_RxValid.
                                                                 1 = when entering U1/U2/U3, delay the transition to P1/P2/P3 until the pipe3 signals,
                                                                 Pipe3_RxElecIlde is 1 and pipe3_RxValid is 0.

                                                                 INTERNAL: Note: This bit should be set to '1' for Synopsys PHY. It is also used by third-
                                                                 party SuperSpeed PHY. */
		uint32_t suspend_en                  : 1;  /**< R/W - Suspend USB3.0 SuperSpeed PHY (Suspend_en). When set to 1, and if suspend conditions are
                                                                 valid, the USB 3.0 PHY enters suspend mode. */
		uint32_t datwidth                    : 2;  /**< RO - PIPE data width.
                                                                 0x0 = 32 bits.
                                                                 0x1 = 16 bits.
                                                                 0x2 = 8 bits.
                                                                 0x3 = reserved.

                                                                 One clock cycle after reset, these bits receive the value seen on the pipe3_DataBusWidth.
                                                                 This will always be 0x0.
                                                                 INTERNAL: The simulation testbench uses the coreConsultant parameter to configure the VIP.
                                                                 INTERNAL: These bits in the coreConsultant parameter should match your PHY data width and
                                                                 the pipe3_DataBusWidth port. */
		uint32_t abortrxdetinu2              : 1;  /**< R/W - Abort RX Detect in U2. When set to 1, and the link state is U2, the core aborts receiver
                                                                 detection if it receives U2 exit LFPS from the remote link partner.

                                                                 This bit is for downstream port only.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
		uint32_t skiprxdet                   : 1;  /**< R/W - Skip RX detect. When set to 1, the core skips RX detection if pipe3_RxElecIdle is low.
                                                                 Skip is defined as waiting for the appropriate timeout, then repeating the operation. */
		uint32_t lfpsp0algn                  : 1;  /**< R/W - LFPS P0 align. When set to 1:
                                                                 * the core deasserts LFPS transmission on the clock edge that it requests Phy power state
                                                                 0 when exiting U1, U2, or U3 low power states. Otherwise, LFPS transmission is asserted
                                                                 one clock earlier.
                                                                 * the core requests symbol transmission two pipe3_rx_pclks periods after the PHY asserts
                                                                 PhyStatus as a result of the PHY switching from P1 or P2 state to P0 state.
                                                                 For USB 3.0 host, this is not required. */
		uint32_t p3p2tranok                  : 1;  /**< R/W - P3 P2 transitions OK.
                                                                 0 = P0 is always entered as an intermediate state during transitions between P2 and P3, as
                                                                 defined in the PIPE3 specification.
                                                                 1 = the core transitions directly from Phy power state P2 to P3 or from state P3 to P2.

                                                                 According to PIPE3 specification, any direct transition between P3 and P2 is illegal.
                                                                 INTERNAL: This bit is used only for some non-Synopsys PHYs that cannot do LFPS in P3.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
		uint32_t p3exsigp2                   : 1;  /**< R/W - P3 exit signal in P2. When set to 1, the core always changes the PHY power state to P2,
                                                                 before attempting a U3 exit handshake.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
		uint32_t lfpsfilt                    : 1;  /**< R/W - LFPS filter. When set to 1, filter LFPS reception with pipe3_RxValid in PHY power state
                                                                 P0, ignore LFPS reception from the PHY unless both pipe3_Rxelecidle and pipe3_RxValid are
                                                                 deasserted. */
		uint32_t rxdet2polllfpsctrl          : 1;  /**< R/W - RX_DETECT to Polling.
                                                                 0 = Enables a 400 us delay to start polling LFPS after RX_DETECT. This allows VCM offset
                                                                 to settle to a proper level.
                                                                 1 = Disables the 400 us delay to start polling LFPS after RX_DETECT. */
		uint32_t ssicen                      : 1;  /**< R/W - SSIC is not supported. This bit must be set to 0. */
		uint32_t txswing                     : 1;  /**< R/W - TX swing. Refer to the PIPE3 specification. */
		uint32_t txmargin                    : 3;  /**< R/W - TX margin. Refer to the PIPE3 specification, table 5-3. */
		uint32_t txdeemphasis                : 2;  /**< R/W - TX de-emphasis. The value driven to the PHY is controlled by the LTSSM during USB3
                                                                 compliance mode. Refer to the PIPE3 specification, table 5-3. */
		uint32_t elasticbuffermode           : 1;  /**< R/W - Elastic buffer mode. Refer to the PIPE3 specification, table 5-3. */
#else
		uint32_t elasticbuffermode           : 1;
		uint32_t txdeemphasis                : 2;
		uint32_t txmargin                    : 3;
		uint32_t txswing                     : 1;
		uint32_t ssicen                      : 1;
		uint32_t rxdet2polllfpsctrl          : 1;
		uint32_t lfpsfilt                    : 1;
		uint32_t p3exsigp2                   : 1;
		uint32_t p3p2tranok                  : 1;
		uint32_t lfpsp0algn                  : 1;
		uint32_t skiprxdet                   : 1;
		uint32_t abortrxdetinu2              : 1;
		uint32_t datwidth                    : 2;
		uint32_t suspend_en                  : 1;
		uint32_t delaypxtransenterux         : 1;
		uint32_t delaypx                     : 3;
		uint32_t disrxdetu3rxdet             : 1;
		uint32_t startrxdetu3rxdet           : 1;
		uint32_t request_p1p2p3              : 1;
		uint32_t u1u2exitfail_to_recov       : 1;
		uint32_t ping_enchance_en            : 1;
		uint32_t ux_exit_in_px               : 1;
		uint32_t disrxdetp3                  : 1;
		uint32_t u2ssinactp3ok               : 1;
		uint32_t hstprtcmpl                  : 1;
		uint32_t physoftrst                  : 1;
#endif
	} s;
	/* struct bdk_usbhx_uahc_gusb3pipectlx_s cn88xx; */
	/* struct bdk_usbhx_uahc_gusb3pipectlx_s cn88xxp1; */
} bdk_usbhx_uahc_gusb3pipectlx_t;

static inline uint64_t BDK_USBHX_UAHC_GUSB3PIPECTLX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_GUSB3PIPECTLX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000086800000C2C0ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_GUSB3PIPECTLX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_GUSB3PIPECTLX(...) bdk_usbhx_uahc_gusb3pipectlx_t
#define bustype_BDK_USBHX_UAHC_GUSB3PIPECTLX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_GUSB3PIPECTLX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_GUSB3PIPECTLX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_GUSB3PIPECTLX(...) "USBHX_UAHC_GUSB3PIPECTLX"


/**
 * NCB32b - usbh#_uahc_hccparams
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.6.
 *
 */
typedef union bdk_usbhx_uahc_hccparams {
	uint32_t u;
	struct bdk_usbhx_uahc_hccparams_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t xecp                        : 16; /**< RO - xHCI extended capabilities pointer. */
		uint32_t maxpsasize                  : 4;  /**< RO - Maximum primary-stream-array size. */
		uint32_t reserved_11_11              : 1;
		uint32_t sec                         : 1;  /**< RO/H - Stopped EDLTA Capability */
		uint32_t spc                         : 1;  /**< RO/H - Stopped - Short packet Capability */
		uint32_t pae                         : 1;  /**< RO - Parse all event data. */
		uint32_t nss                         : 1;  /**< RO - No secondary SID support. */
		uint32_t ltc                         : 1;  /**< RO - Latency tolerance messaging capability. */
		uint32_t lhrc                        : 1;  /**< RO - Light HC reset capability. */
		uint32_t pind                        : 1;  /**< RO - Port indicators. */
		uint32_t ppc                         : 1;  /**< RO - Port power control. Value is based on USBH()_UCTL_HOST_CFG[PPC_EN]. */
		uint32_t csz                         : 1;  /**< RO - Context size. */
		uint32_t bnc                         : 1;  /**< RO - BW negotiation capability. */
		uint32_t ac64                        : 1;  /**< RO - 64-bit addressing capability. */
#else
		uint32_t ac64                        : 1;
		uint32_t bnc                         : 1;
		uint32_t csz                         : 1;
		uint32_t ppc                         : 1;
		uint32_t pind                        : 1;
		uint32_t lhrc                        : 1;
		uint32_t ltc                         : 1;
		uint32_t nss                         : 1;
		uint32_t pae                         : 1;
		uint32_t spc                         : 1;
		uint32_t sec                         : 1;
		uint32_t reserved_11_11              : 1;
		uint32_t maxpsasize                  : 4;
		uint32_t xecp                        : 16;
#endif
	} s;
	/* struct bdk_usbhx_uahc_hccparams_s  cn88xx; */
	/* struct bdk_usbhx_uahc_hccparams_s  cn88xxp1; */
} bdk_usbhx_uahc_hccparams_t;

static inline uint64_t BDK_USBHX_UAHC_HCCPARAMS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_HCCPARAMS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000010ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_HCCPARAMS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_HCCPARAMS(...) bdk_usbhx_uahc_hccparams_t
#define bustype_BDK_USBHX_UAHC_HCCPARAMS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_HCCPARAMS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_HCCPARAMS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_HCCPARAMS(...) "USBHX_UAHC_HCCPARAMS"


/**
 * NCB32b - usbh#_uahc_hcsparams1
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.3.
 *
 */
typedef union bdk_usbhx_uahc_hcsparams1 {
	uint32_t u;
	struct bdk_usbhx_uahc_hcsparams1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t maxports                    : 8;  /**< RO - Maximum number of ports. */
		uint32_t reserved_19_23              : 5;
		uint32_t maxintrs                    : 11; /**< RO - Maximum number of interrupters. */
		uint32_t maxslots                    : 8;  /**< RO - Maximum number of device slots. */
#else
		uint32_t maxslots                    : 8;
		uint32_t maxintrs                    : 11;
		uint32_t reserved_19_23              : 5;
		uint32_t maxports                    : 8;
#endif
	} s;
	struct bdk_usbhx_uahc_hcsparams1_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t maxports                    : 8;  /**< RO - Maximum number of ports. */
		uint32_t reserved_23_19              : 5;
		uint32_t maxintrs                    : 11; /**< RO - Maximum number of interrupters. */
		uint32_t maxslots                    : 8;  /**< RO - Maximum number of device slots. */
#else
		uint32_t maxslots                    : 8;
		uint32_t maxintrs                    : 11;
		uint32_t reserved_23_19              : 5;
		uint32_t maxports                    : 8;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_hcsparams1_cn88xx cn88xxp1;
} bdk_usbhx_uahc_hcsparams1_t;

static inline uint64_t BDK_USBHX_UAHC_HCSPARAMS1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_HCSPARAMS1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000004ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_HCSPARAMS1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_HCSPARAMS1(...) bdk_usbhx_uahc_hcsparams1_t
#define bustype_BDK_USBHX_UAHC_HCSPARAMS1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_HCSPARAMS1(p1) (p1)
#define arguments_BDK_USBHX_UAHC_HCSPARAMS1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_HCSPARAMS1(...) "USBHX_UAHC_HCSPARAMS1"


/**
 * NCB32b - usbh#_uahc_hcsparams2
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.4.
 *
 */
typedef union bdk_usbhx_uahc_hcsparams2 {
	uint32_t u;
	struct bdk_usbhx_uahc_hcsparams2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t maxscratchpadbufs_l         : 5;  /**< RO - Maximum number of scratchpad buffers[4:0]. */
		uint32_t reserved_26_26              : 1;
		uint32_t maxscratchpadbufs_h         : 5;  /**< RO - Maximum number of scratchpad buffers[9:5]. */
		uint32_t reserved_8_20               : 13;
		uint32_t erst_max                    : 4;  /**< RO - Event ring segment table maximum. */
		uint32_t ist                         : 4;  /**< RO - Isochronous scheduling threshold. */
#else
		uint32_t ist                         : 4;
		uint32_t erst_max                    : 4;
		uint32_t reserved_8_20               : 13;
		uint32_t maxscratchpadbufs_h         : 5;
		uint32_t reserved_26_26              : 1;
		uint32_t maxscratchpadbufs_l         : 5;
#endif
	} s;
	struct bdk_usbhx_uahc_hcsparams2_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t maxscratchpadbufs_l         : 5;  /**< RO - Maximum number of scratchpad buffers[4:0]. */
		uint32_t reserved_26_26              : 1;
		uint32_t maxscratchpadbufs_h         : 5;  /**< RO - Maximum number of scratchpad buffers[9:5]. */
		uint32_t reserved_20_8               : 13;
		uint32_t erst_max                    : 4;  /**< RO - Event ring segment table maximum. */
		uint32_t ist                         : 4;  /**< RO - Isochronous scheduling threshold. */
#else
		uint32_t ist                         : 4;
		uint32_t erst_max                    : 4;
		uint32_t reserved_20_8               : 13;
		uint32_t maxscratchpadbufs_h         : 5;
		uint32_t reserved_26_26              : 1;
		uint32_t maxscratchpadbufs_l         : 5;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_hcsparams2_cn88xx cn88xxp1;
} bdk_usbhx_uahc_hcsparams2_t;

static inline uint64_t BDK_USBHX_UAHC_HCSPARAMS2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_HCSPARAMS2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000008ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_HCSPARAMS2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_HCSPARAMS2(...) bdk_usbhx_uahc_hcsparams2_t
#define bustype_BDK_USBHX_UAHC_HCSPARAMS2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_HCSPARAMS2(p1) (p1)
#define arguments_BDK_USBHX_UAHC_HCSPARAMS2(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_HCSPARAMS2(...) "USBHX_UAHC_HCSPARAMS2"


/**
 * NCB32b - usbh#_uahc_hcsparams3
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.5.
 *
 */
typedef union bdk_usbhx_uahc_hcsparams3 {
	uint32_t u;
	struct bdk_usbhx_uahc_hcsparams3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t u2_device_exit_latency      : 16; /**< RO - U2 device exit latency. */
		uint32_t reserved_8_15               : 8;
		uint32_t u1_device_exit_latency      : 8;  /**< RO - U1 device exit latency. */
#else
		uint32_t u1_device_exit_latency      : 8;
		uint32_t reserved_8_15               : 8;
		uint32_t u2_device_exit_latency      : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_hcsparams3_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t u2_device_exit_latency      : 16; /**< RO - U2 device exit latency. */
		uint32_t reserved_15_8               : 8;
		uint32_t u1_device_exit_latency      : 8;  /**< RO - U1 device exit latency. */
#else
		uint32_t u1_device_exit_latency      : 8;
		uint32_t reserved_15_8               : 8;
		uint32_t u2_device_exit_latency      : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_hcsparams3_cn88xx cn88xxp1;
} bdk_usbhx_uahc_hcsparams3_t;

static inline uint64_t BDK_USBHX_UAHC_HCSPARAMS3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_HCSPARAMS3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000000Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_HCSPARAMS3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_HCSPARAMS3(...) bdk_usbhx_uahc_hcsparams3_t
#define bustype_BDK_USBHX_UAHC_HCSPARAMS3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_HCSPARAMS3(p1) (p1)
#define arguments_BDK_USBHX_UAHC_HCSPARAMS3(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_HCSPARAMS3(...) "USBHX_UAHC_HCSPARAMS3"


/**
 * NCB32b - usbh#_uahc_iman#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.1.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_imanx {
	uint32_t u;
	struct bdk_usbhx_uahc_imanx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_2_31               : 30;
		uint32_t ie                          : 1;  /**< R/W - Interrupt enable. */
		uint32_t ip                          : 1;  /**< R/W1C/H - Interrupt pending. */
#else
		uint32_t ip                          : 1;
		uint32_t ie                          : 1;
		uint32_t reserved_2_31               : 30;
#endif
	} s;
	struct bdk_usbhx_uahc_imanx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_2               : 30;
		uint32_t ie                          : 1;  /**< R/W - Interrupt enable. */
		uint32_t ip                          : 1;  /**< R/W1C/H - Interrupt pending. */
#else
		uint32_t ip                          : 1;
		uint32_t ie                          : 1;
		uint32_t reserved_31_2               : 30;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_imanx_cn88xx    cn88xxp1;
} bdk_usbhx_uahc_imanx_t;

static inline uint64_t BDK_USBHX_UAHC_IMANX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_IMANX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000460ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_IMANX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_IMANX(...) bdk_usbhx_uahc_imanx_t
#define bustype_BDK_USBHX_UAHC_IMANX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_IMANX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_IMANX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_IMANX(...) "USBHX_UAHC_IMANX"


/**
 * NCB32b - usbh#_uahc_imod#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.2.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_imodx {
	uint32_t u;
	struct bdk_usbhx_uahc_imodx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t imodc                       : 16; /**< R/W - Interrupt moderation counter. */
		uint32_t imodi                       : 16; /**< R/W - Interrupt moderation interval. */
#else
		uint32_t imodi                       : 16;
		uint32_t imodc                       : 16;
#endif
	} s;
	/* struct bdk_usbhx_uahc_imodx_s      cn88xx; */
	/* struct bdk_usbhx_uahc_imodx_s      cn88xxp1; */
} bdk_usbhx_uahc_imodx_t;

static inline uint64_t BDK_USBHX_UAHC_IMODX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_IMODX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000464ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_IMODX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_IMODX(...) bdk_usbhx_uahc_imodx_t
#define bustype_BDK_USBHX_UAHC_IMODX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_IMODX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_IMODX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_IMODX(...) "USBHX_UAHC_IMODX"


/**
 * NCB32b - usbh#_uahc_mfindex
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.1.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_mfindex {
	uint32_t u;
	struct bdk_usbhx_uahc_mfindex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_14_31              : 18;
		uint32_t mfindex                     : 14; /**< RO/H - Microframe index. */
#else
		uint32_t mfindex                     : 14;
		uint32_t reserved_14_31              : 18;
#endif
	} s;
	struct bdk_usbhx_uahc_mfindex_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_14              : 18;
		uint32_t mfindex                     : 14; /**< RO/H - Microframe index. */
#else
		uint32_t mfindex                     : 14;
		uint32_t reserved_31_14              : 18;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_mfindex_cn88xx  cn88xxp1;
} bdk_usbhx_uahc_mfindex_t;

static inline uint64_t BDK_USBHX_UAHC_MFINDEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_MFINDEX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000440ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_MFINDEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_MFINDEX(...) bdk_usbhx_uahc_mfindex_t
#define bustype_BDK_USBHX_UAHC_MFINDEX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_MFINDEX(p1) (p1)
#define arguments_BDK_USBHX_UAHC_MFINDEX(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_MFINDEX(...) "USBHX_UAHC_MFINDEX"


/**
 * NCB32b - usbh#_uahc_pagesize
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.3.
 *
 */
typedef union bdk_usbhx_uahc_pagesize {
	uint32_t u;
	struct bdk_usbhx_uahc_pagesize_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t pagesize                    : 16; /**< RO - Page size. */
#else
		uint32_t pagesize                    : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_pagesize_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_16              : 16;
		uint32_t pagesize                    : 16; /**< RO - Page size. */
#else
		uint32_t pagesize                    : 16;
		uint32_t reserved_31_16              : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_pagesize_cn88xx cn88xxp1;
} bdk_usbhx_uahc_pagesize_t;

static inline uint64_t BDK_USBHX_UAHC_PAGESIZE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PAGESIZE(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000028ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_PAGESIZE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PAGESIZE(...) bdk_usbhx_uahc_pagesize_t
#define bustype_BDK_USBHX_UAHC_PAGESIZE(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PAGESIZE(p1) (p1)
#define arguments_BDK_USBHX_UAHC_PAGESIZE(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_PAGESIZE(...) "USBHX_UAHC_PAGESIZE"


/**
 * NCB32b - usbh#_uahc_porthlpmc_20#
 *
 * For information on this register, refer to the xHCI Specification, v1.1, section 5.4.11.2.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_porthlpmc_20x {
	uint32_t u;
	struct bdk_usbhx_uahc_porthlpmc_20x_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_14_31              : 18;
		uint32_t hirdd                       : 4;  /**< R/W - See section 5.4.11.2 of the XHCI Spec 1.1.
                                                                 If USBH()_UAHC_SUPTPRT2_DW2[BLC] = 0, then HIRD timing is applied to this field.
                                                                 If USBH()_UAHC_SUPTPRT2_DW2[BLC] = 1, then BESL timing is applied to this field. */
		uint32_t l1_timeout                  : 8;  /**< R/W - Timeout value for the L1 inactivity timer (LPM Timer). This field is set to 0x0 by the
                                                                 assertion of PR to 1. Refer to section 4.23.5.1.1.1 (in XHCI spec 1.1) for more
                                                                 information on L1 Timeout operation.
                                                                 The following are permissible values:
                                                                 0x0 =  128 us. (default).
                                                                 0x1 =  256 us.
                                                                 0x2 =  512 us.
                                                                 0x3 =  768 us.
                                                                 _ ...
                                                                 0xFF =  65280 us. */
		uint32_t hirdm                       : 2;  /**< R/W - Host-initiated resume-duration mode. */
#else
		uint32_t hirdm                       : 2;
		uint32_t l1_timeout                  : 8;
		uint32_t hirdd                       : 4;
		uint32_t reserved_14_31              : 18;
#endif
	} s;
	struct bdk_usbhx_uahc_porthlpmc_20x_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_14              : 18;
		uint32_t hirdd                       : 4;  /**< R/W - See section 5.4.11.2 of the XHCI Spec 1.1.
                                                                 If USBH()_UAHC_SUPTPRT2_DW2[BLC] = 0, then HIRD timing is applied to this field.
                                                                 If USBH()_UAHC_SUPTPRT2_DW2[BLC] = 1, then BESL timing is applied to this field. */
		uint32_t l1_timeout                  : 8;  /**< R/W - Timeout value for the L1 inactivity timer (LPM Timer). This field is set to 0x0 by the
                                                                 assertion of PR to 1. Refer to section 4.23.5.1.1.1 (in XHCI spec 1.1) for more
                                                                 information on L1 Timeout operation.
                                                                 The following are permissible values:
                                                                 0x0 =  128 us. (default).
                                                                 0x1 =  256 us.
                                                                 0x2 =  512 us.
                                                                 0x3 =  768 us.
                                                                 _ ...
                                                                 0xFF =  65280 us. */
		uint32_t hirdm                       : 2;  /**< R/W - Host-initiated resume-duration mode. */
#else
		uint32_t hirdm                       : 2;
		uint32_t l1_timeout                  : 8;
		uint32_t hirdd                       : 4;
		uint32_t reserved_31_14              : 18;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_porthlpmc_20x_cn88xx cn88xxp1;
} bdk_usbhx_uahc_porthlpmc_20x_t;

static inline uint64_t BDK_USBHX_UAHC_PORTHLPMC_20X(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTHLPMC_20X(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000086800000042Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_PORTHLPMC_20X", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTHLPMC_20X(...) bdk_usbhx_uahc_porthlpmc_20x_t
#define bustype_BDK_USBHX_UAHC_PORTHLPMC_20X(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTHLPMC_20X(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTHLPMC_20X(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTHLPMC_20X(...) "USBHX_UAHC_PORTHLPMC_20X"


/**
 * NCB32b - usbh#_uahc_porthlpmc_ss#
 *
 * The USB3 Port Hardware LPM Control register is reserved and shall be treated as RsvdP by
 * software. See xHCI specification v1.1 section 5.4.11.1.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST].
 */
typedef union bdk_usbhx_uahc_porthlpmc_ssx {
	uint32_t u;
	struct bdk_usbhx_uahc_porthlpmc_ssx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	struct bdk_usbhx_uahc_porthlpmc_ssx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_0               : 32;
#else
		uint32_t reserved_31_0               : 32;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_porthlpmc_ssx_cn88xx cn88xxp1;
} bdk_usbhx_uahc_porthlpmc_ssx_t;

static inline uint64_t BDK_USBHX_UAHC_PORTHLPMC_SSX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTHLPMC_SSX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 1)))
		return 0x000086800000042Cull + (param1 & 1) * 0x1000000000ull + (param2 & 1) * 0x10ull;
	csr_fatal("BDK_USBHX_UAHC_PORTHLPMC_SSX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTHLPMC_SSX(...) bdk_usbhx_uahc_porthlpmc_ssx_t
#define bustype_BDK_USBHX_UAHC_PORTHLPMC_SSX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTHLPMC_SSX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTHLPMC_SSX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTHLPMC_SSX(...) "USBHX_UAHC_PORTHLPMC_SSX"


/**
 * NCB32b - usbh#_uahc_portli_20#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.10.
 *
 */
typedef union bdk_usbhx_uahc_portli_20x {
	uint32_t u;
	struct bdk_usbhx_uahc_portli_20x_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	struct bdk_usbhx_uahc_portli_20x_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_0               : 32;
#else
		uint32_t reserved_31_0               : 32;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_portli_20x_cn88xx cn88xxp1;
} bdk_usbhx_uahc_portli_20x_t;

static inline uint64_t BDK_USBHX_UAHC_PORTLI_20X(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTLI_20X(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000428ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_PORTLI_20X", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTLI_20X(...) bdk_usbhx_uahc_portli_20x_t
#define bustype_BDK_USBHX_UAHC_PORTLI_20X(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTLI_20X(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTLI_20X(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTLI_20X(...) "USBHX_UAHC_PORTLI_20X"


/**
 * NCB32b - usbh#_uahc_portli_ss#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.10.
 *
 */
typedef union bdk_usbhx_uahc_portli_ssx {
	uint32_t u;
	struct bdk_usbhx_uahc_portli_ssx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t linkerrorcount              : 16; /**< RO/H - Link error count. */
#else
		uint32_t linkerrorcount              : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	struct bdk_usbhx_uahc_portli_ssx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_16              : 16;
		uint32_t linkerrorcount              : 16; /**< RO/H - Link error count. */
#else
		uint32_t linkerrorcount              : 16;
		uint32_t reserved_31_16              : 16;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_portli_ssx_cn88xx cn88xxp1;
} bdk_usbhx_uahc_portli_ssx_t;

static inline uint64_t BDK_USBHX_UAHC_PORTLI_SSX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTLI_SSX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 1)))
		return 0x0000868000000428ull + (param1 & 1) * 0x1000000000ull + (param2 & 1) * 0x10ull;
	csr_fatal("BDK_USBHX_UAHC_PORTLI_SSX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTLI_SSX(...) bdk_usbhx_uahc_portli_ssx_t
#define bustype_BDK_USBHX_UAHC_PORTLI_SSX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTLI_SSX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTLI_SSX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTLI_SSX(...) "USBHX_UAHC_PORTLI_SSX"


/**
 * NCB32b - usbh#_uahc_portpmsc_20#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.9.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST].
 */
typedef union bdk_usbhx_uahc_portpmsc_20x {
	uint32_t u;
	struct bdk_usbhx_uahc_portpmsc_20x_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t port_test_control           : 4;  /**< R/W - Port test control. */
		uint32_t reserved_17_27              : 11;
		uint32_t hle                         : 1;  /**< R/W - Hardware LPM enable. */
		uint32_t l1_device_slot              : 8;  /**< R/W - L1 device slot. */
		uint32_t hird                        : 4;  /**< R/W - Host-initiated resume duration. */
		uint32_t rwe                         : 1;  /**< R/W - Remove wake enable. */
		uint32_t l1s                         : 3;  /**< RO/H - L1 status. */
#else
		uint32_t l1s                         : 3;
		uint32_t rwe                         : 1;
		uint32_t hird                        : 4;
		uint32_t l1_device_slot              : 8;
		uint32_t hle                         : 1;
		uint32_t reserved_17_27              : 11;
		uint32_t port_test_control           : 4;
#endif
	} s;
	struct bdk_usbhx_uahc_portpmsc_20x_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t port_test_control           : 4;  /**< R/W - Port test control. */
		uint32_t reserved_27_17              : 11;
		uint32_t hle                         : 1;  /**< R/W - Hardware LPM enable. */
		uint32_t l1_device_slot              : 8;  /**< R/W - L1 device slot. */
		uint32_t hird                        : 4;  /**< R/W - Host-initiated resume duration. */
		uint32_t rwe                         : 1;  /**< R/W - Remove wake enable. */
		uint32_t l1s                         : 3;  /**< RO/H - L1 status. */
#else
		uint32_t l1s                         : 3;
		uint32_t rwe                         : 1;
		uint32_t hird                        : 4;
		uint32_t l1_device_slot              : 8;
		uint32_t hle                         : 1;
		uint32_t reserved_27_17              : 11;
		uint32_t port_test_control           : 4;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_portpmsc_20x_cn88xx cn88xxp1;
} bdk_usbhx_uahc_portpmsc_20x_t;

static inline uint64_t BDK_USBHX_UAHC_PORTPMSC_20X(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTPMSC_20X(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000000424ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_PORTPMSC_20X", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTPMSC_20X(...) bdk_usbhx_uahc_portpmsc_20x_t
#define bustype_BDK_USBHX_UAHC_PORTPMSC_20X(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTPMSC_20X(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTPMSC_20X(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTPMSC_20X(...) "USBHX_UAHC_PORTPMSC_20X"


/**
 * NCB32b - usbh#_uahc_portpmsc_ss#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.9.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST].
 */
typedef union bdk_usbhx_uahc_portpmsc_ssx {
	uint32_t u;
	struct bdk_usbhx_uahc_portpmsc_ssx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_17_31              : 15;
		uint32_t fla                         : 1;  /**< R/W - Force link PM accept. */
		uint32_t u2_timeout                  : 8;  /**< R/W - U2 timeout. */
		uint32_t u1_timeout                  : 8;  /**< R/W - U1 timeout. */
#else
		uint32_t u1_timeout                  : 8;
		uint32_t u2_timeout                  : 8;
		uint32_t fla                         : 1;
		uint32_t reserved_17_31              : 15;
#endif
	} s;
	struct bdk_usbhx_uahc_portpmsc_ssx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_17              : 15;
		uint32_t fla                         : 1;  /**< R/W - Force link PM accept. */
		uint32_t u2_timeout                  : 8;  /**< R/W - U2 timeout. */
		uint32_t u1_timeout                  : 8;  /**< R/W - U1 timeout. */
#else
		uint32_t u1_timeout                  : 8;
		uint32_t u2_timeout                  : 8;
		uint32_t fla                         : 1;
		uint32_t reserved_31_17              : 15;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_portpmsc_ssx_cn88xx cn88xxp1;
} bdk_usbhx_uahc_portpmsc_ssx_t;

static inline uint64_t BDK_USBHX_UAHC_PORTPMSC_SSX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTPMSC_SSX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 1)))
		return 0x0000868000000424ull + (param1 & 1) * 0x1000000000ull + (param2 & 1) * 0x10ull;
	csr_fatal("BDK_USBHX_UAHC_PORTPMSC_SSX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTPMSC_SSX(...) bdk_usbhx_uahc_portpmsc_ssx_t
#define bustype_BDK_USBHX_UAHC_PORTPMSC_SSX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTPMSC_SSX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTPMSC_SSX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTPMSC_SSX(...) "USBHX_UAHC_PORTPMSC_SSX"


/**
 * NCB32b - usbh#_uahc_portsc#
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.8. Port 1
 * is USB3.0 SuperSpeed link, Port 0 is USB2.0 high-speed/full-speed/low-speed link.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST].
 */
typedef union bdk_usbhx_uahc_portscx {
	uint32_t u;
	struct bdk_usbhx_uahc_portscx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t wpr                         : 1;  /**< WO - Warm port reset. */
		uint32_t dr                          : 1;  /**< RO/H - Device removable. */
		uint32_t reserved_28_29              : 2;
		uint32_t woe                         : 1;  /**< R/W - Wake-on-overcurrent enable. */
		uint32_t wde                         : 1;  /**< R/W - Wake-on-disconnect enable. */
		uint32_t wce                         : 1;  /**< R/W - Wake-on-connect enable. */
		uint32_t cas                         : 1;  /**< RO/H - Cold-attach status. */
		uint32_t cec                         : 1;  /**< R/W1C/H - Port-configuration-error change. */
		uint32_t plc                         : 1;  /**< R/W1C/H - Port-link-state change. */
		uint32_t prc                         : 1;  /**< R/W1C/H - Port-reset change. */
		uint32_t occ                         : 1;  /**< R/W1C/H - Overcurrent change. */
		uint32_t wrc                         : 1;  /**< R/W1C/H - Warm-port-reset change. */
		uint32_t pec                         : 1;  /**< R/W1C/H - Port enabled/disabled change. */
		uint32_t csc                         : 1;  /**< R/W1C/H - Connect-status change. */
		uint32_t lws                         : 1;  /**< WO - Port-link-state write strobe. */
		uint32_t pic                         : 2;  /**< R/W/H - Port indicator control. */
		uint32_t portspeed                   : 4;  /**< RO/H - Port speed. */
		uint32_t pp                          : 1;  /**< R/W/H - Port power. */
		uint32_t pls                         : 4;  /**< R/W/H - Port-link state. */
		uint32_t pr                          : 1;  /**< R/W1S/H - Port reset. */
		uint32_t oca                         : 1;  /**< RO/H - Overcurrent active. */
		uint32_t reserved_2_2                : 1;
		uint32_t ped                         : 1;  /**< R/W1C/H - Port enabled/disabled. */
		uint32_t ccs                         : 1;  /**< RO/H - Current connect status. */
#else
		uint32_t ccs                         : 1;
		uint32_t ped                         : 1;
		uint32_t reserved_2_2                : 1;
		uint32_t oca                         : 1;
		uint32_t pr                          : 1;
		uint32_t pls                         : 4;
		uint32_t pp                          : 1;
		uint32_t portspeed                   : 4;
		uint32_t pic                         : 2;
		uint32_t lws                         : 1;
		uint32_t csc                         : 1;
		uint32_t pec                         : 1;
		uint32_t wrc                         : 1;
		uint32_t occ                         : 1;
		uint32_t prc                         : 1;
		uint32_t plc                         : 1;
		uint32_t cec                         : 1;
		uint32_t cas                         : 1;
		uint32_t wce                         : 1;
		uint32_t wde                         : 1;
		uint32_t woe                         : 1;
		uint32_t reserved_28_29              : 2;
		uint32_t dr                          : 1;
		uint32_t wpr                         : 1;
#endif
	} s;
	struct bdk_usbhx_uahc_portscx_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t wpr                         : 1;  /**< WO - Warm port reset. */
		uint32_t dr                          : 1;  /**< RO/H - Device removable. */
		uint32_t reserved_29_28              : 2;
		uint32_t woe                         : 1;  /**< R/W - Wake-on-overcurrent enable. */
		uint32_t wde                         : 1;  /**< R/W - Wake-on-disconnect enable. */
		uint32_t wce                         : 1;  /**< R/W - Wake-on-connect enable. */
		uint32_t cas                         : 1;  /**< RO/H - Cold-attach status. */
		uint32_t cec                         : 1;  /**< R/W1C/H - Port-configuration-error change. */
		uint32_t plc                         : 1;  /**< R/W1C/H - Port-link-state change. */
		uint32_t prc                         : 1;  /**< R/W1C/H - Port-reset change. */
		uint32_t occ                         : 1;  /**< R/W1C/H - Overcurrent change. */
		uint32_t wrc                         : 1;  /**< R/W1C/H - Warm-port-reset change. */
		uint32_t pec                         : 1;  /**< R/W1C/H - Port enabled/disabled change. */
		uint32_t csc                         : 1;  /**< R/W1C/H - Connect-status change. */
		uint32_t lws                         : 1;  /**< WO - Port-link-state write strobe. */
		uint32_t pic                         : 2;  /**< R/W/H - Port indicator control. */
		uint32_t portspeed                   : 4;  /**< RO/H - Port speed. */
		uint32_t pp                          : 1;  /**< R/W/H - Port power. */
		uint32_t pls                         : 4;  /**< R/W/H - Port-link state. */
		uint32_t pr                          : 1;  /**< R/W1S/H - Port reset. */
		uint32_t oca                         : 1;  /**< RO/H - Overcurrent active. */
		uint32_t reserved_2_2                : 1;
		uint32_t ped                         : 1;  /**< R/W1C/H - Port enabled/disabled. */
		uint32_t ccs                         : 1;  /**< RO/H - Current connect status. */
#else
		uint32_t ccs                         : 1;
		uint32_t ped                         : 1;
		uint32_t reserved_2_2                : 1;
		uint32_t oca                         : 1;
		uint32_t pr                          : 1;
		uint32_t pls                         : 4;
		uint32_t pp                          : 1;
		uint32_t portspeed                   : 4;
		uint32_t pic                         : 2;
		uint32_t lws                         : 1;
		uint32_t csc                         : 1;
		uint32_t pec                         : 1;
		uint32_t wrc                         : 1;
		uint32_t occ                         : 1;
		uint32_t prc                         : 1;
		uint32_t plc                         : 1;
		uint32_t cec                         : 1;
		uint32_t cas                         : 1;
		uint32_t wce                         : 1;
		uint32_t wde                         : 1;
		uint32_t woe                         : 1;
		uint32_t reserved_29_28              : 2;
		uint32_t dr                          : 1;
		uint32_t wpr                         : 1;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_portscx_cn88xx  cn88xxp1;
} bdk_usbhx_uahc_portscx_t;

static inline uint64_t BDK_USBHX_UAHC_PORTSCX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_PORTSCX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x0000868000000420ull + (param1 & 1) * 0x1000000000ull + (param2 & 1) * 0x10ull;
	csr_fatal("BDK_USBHX_UAHC_PORTSCX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_PORTSCX(...) bdk_usbhx_uahc_portscx_t
#define bustype_BDK_USBHX_UAHC_PORTSCX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_PORTSCX(p1,p2) (p1)
#define arguments_BDK_USBHX_UAHC_PORTSCX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UAHC_PORTSCX(...) "USBHX_UAHC_PORTSCX"


/**
 * NCB32b - usbh#_uahc_rtsoff
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.8.
 *
 */
typedef union bdk_usbhx_uahc_rtsoff {
	uint32_t u;
	struct bdk_usbhx_uahc_rtsoff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rtsoff                      : 27; /**< RO - Runtime register-space offset. */
		uint32_t reserved_0_4                : 5;
#else
		uint32_t reserved_0_4                : 5;
		uint32_t rtsoff                      : 27;
#endif
	} s;
	struct bdk_usbhx_uahc_rtsoff_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t rtsoff                      : 27; /**< RO - Runtime register-space offset. */
		uint32_t reserved_4_0                : 5;
#else
		uint32_t reserved_4_0                : 5;
		uint32_t rtsoff                      : 27;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_rtsoff_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_rtsoff_t;

static inline uint64_t BDK_USBHX_UAHC_RTSOFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_RTSOFF(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000018ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_RTSOFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_RTSOFF(...) bdk_usbhx_uahc_rtsoff_t
#define bustype_BDK_USBHX_UAHC_RTSOFF(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_RTSOFF(p1) (p1)
#define arguments_BDK_USBHX_UAHC_RTSOFF(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_RTSOFF(...) "USBHX_UAHC_RTSOFF"


/**
 * NCB32b - usbh#_uahc_suptprt2_dw0
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt2_dw0 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt2_dw0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t majorrev                    : 8;  /**< RO - Major revision. */
		uint32_t minorrev                    : 8;  /**< RO - Minor revision. */
		uint32_t nextcapptr                  : 8;  /**< RO - Next capability pointer. */
		uint32_t capid                       : 8;  /**< RO - Capability ID = supported protocol. */
#else
		uint32_t capid                       : 8;
		uint32_t nextcapptr                  : 8;
		uint32_t minorrev                    : 8;
		uint32_t majorrev                    : 8;
#endif
	} s;
	/* struct bdk_usbhx_uahc_suptprt2_dw0_s cn88xx; */
	/* struct bdk_usbhx_uahc_suptprt2_dw0_s cn88xxp1; */
} bdk_usbhx_uahc_suptprt2_dw0_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000890ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT2_DW0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT2_DW0(...) bdk_usbhx_uahc_suptprt2_dw0_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT2_DW0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT2_DW0(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT2_DW0(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT2_DW0(...) "USBHX_UAHC_SUPTPRT2_DW0"


/**
 * NCB32b - usbh#_uahc_suptprt2_dw1
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt2_dw1 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt2_dw1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t name                        : 32; /**< RO - Name string: 'USB'. */
#else
		uint32_t name                        : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_suptprt2_dw1_s cn88xx; */
	/* struct bdk_usbhx_uahc_suptprt2_dw1_s cn88xxp1; */
} bdk_usbhx_uahc_suptprt2_dw1_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000894ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT2_DW1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT2_DW1(...) bdk_usbhx_uahc_suptprt2_dw1_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT2_DW1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT2_DW1(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT2_DW1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT2_DW1(...) "USBHX_UAHC_SUPTPRT2_DW1"


/**
 * NCB32b - usbh#_uahc_suptprt2_dw2
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt2_dw2 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt2_dw2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t psic                        : 4;  /**< RO - Protocol speed ID count. */
		uint32_t reserved_21_27              : 7;
		uint32_t blc                         : 1;  /**< RO - BESL LPM capability. */
		uint32_t hlc                         : 1;  /**< RO - Hardware LMP capability. */
		uint32_t ihi                         : 1;  /**< RO - Integrated hub implemented. */
		uint32_t hso                         : 1;  /**< RO - High-speed only. */
		uint32_t reserved_16_16              : 1;
		uint32_t compatprtcnt                : 8;  /**< RO - Compatible port count. */
		uint32_t compatprtoff                : 8;  /**< RO - Compatible port offset. */
#else
		uint32_t compatprtoff                : 8;
		uint32_t compatprtcnt                : 8;
		uint32_t reserved_16_16              : 1;
		uint32_t hso                         : 1;
		uint32_t ihi                         : 1;
		uint32_t hlc                         : 1;
		uint32_t blc                         : 1;
		uint32_t reserved_21_27              : 7;
		uint32_t psic                        : 4;
#endif
	} s;
	struct bdk_usbhx_uahc_suptprt2_dw2_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t psic                        : 4;  /**< RO - Protocol speed ID count. */
		uint32_t reserved_27_21              : 7;
		uint32_t blc                         : 1;  /**< RO - BESL LPM capability. */
		uint32_t hlc                         : 1;  /**< RO - Hardware LMP capability. */
		uint32_t ihi                         : 1;  /**< RO - Integrated hub implemented. */
		uint32_t hso                         : 1;  /**< RO - High-speed only. */
		uint32_t reserved_16_16              : 1;
		uint32_t compatprtcnt                : 8;  /**< RO - Compatible port count. */
		uint32_t compatprtoff                : 8;  /**< RO - Compatible port offset. */
#else
		uint32_t compatprtoff                : 8;
		uint32_t compatprtcnt                : 8;
		uint32_t reserved_16_16              : 1;
		uint32_t hso                         : 1;
		uint32_t ihi                         : 1;
		uint32_t hlc                         : 1;
		uint32_t blc                         : 1;
		uint32_t reserved_27_21              : 7;
		uint32_t psic                        : 4;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_suptprt2_dw2_cn88xx cn88xxp1;
} bdk_usbhx_uahc_suptprt2_dw2_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000898ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT2_DW2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT2_DW2(...) bdk_usbhx_uahc_suptprt2_dw2_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT2_DW2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT2_DW2(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT2_DW2(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT2_DW2(...) "USBHX_UAHC_SUPTPRT2_DW2"


/**
 * NCB32b - usbh#_uahc_suptprt2_dw3
 *
 * For information on this register, refer to the xHCI Specification, v1.1, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt2_dw3 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt2_dw3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t protslottype                : 5;  /**< RO - Protocol slot type. */
#else
		uint32_t protslottype                : 5;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	struct bdk_usbhx_uahc_suptprt2_dw3_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_5               : 27;
		uint32_t protslottype                : 5;  /**< RO - Protocol slot type. */
#else
		uint32_t protslottype                : 5;
		uint32_t reserved_31_5               : 27;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_suptprt2_dw3_cn88xx cn88xxp1;
} bdk_usbhx_uahc_suptprt2_dw3_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT2_DW3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000086800000089Cull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT2_DW3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT2_DW3(...) bdk_usbhx_uahc_suptprt2_dw3_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT2_DW3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT2_DW3(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT2_DW3(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT2_DW3(...) "USBHX_UAHC_SUPTPRT2_DW3"


/**
 * NCB32b - usbh#_uahc_suptprt3_dw0
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt3_dw0 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt3_dw0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t majorrev                    : 8;  /**< RO - Major revision. */
		uint32_t minorrev                    : 8;  /**< RO - Minor revision. */
		uint32_t nextcapptr                  : 8;  /**< RO/H - Next capability pointer. Value depends on USBH()_UAHC_GUCTL[EXTCAPSUPTEN]. If EXTCAPSUPTEN
                                                                 =
                                                                 0, value is 0x0. If EXTCAPSUPTEN = 1, value is 0x4. */
		uint32_t capid                       : 8;  /**< RO - Capability ID = supported protocol. */
#else
		uint32_t capid                       : 8;
		uint32_t nextcapptr                  : 8;
		uint32_t minorrev                    : 8;
		uint32_t majorrev                    : 8;
#endif
	} s;
	/* struct bdk_usbhx_uahc_suptprt3_dw0_s cn88xx; */
	/* struct bdk_usbhx_uahc_suptprt3_dw0_s cn88xxp1; */
} bdk_usbhx_uahc_suptprt3_dw0_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680000008A0ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT3_DW0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT3_DW0(...) bdk_usbhx_uahc_suptprt3_dw0_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT3_DW0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT3_DW0(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT3_DW0(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT3_DW0(...) "USBHX_UAHC_SUPTPRT3_DW0"


/**
 * NCB32b - usbh#_uahc_suptprt3_dw1
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt3_dw1 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt3_dw1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t name                        : 32; /**< RO - Name string: 'USB'. */
#else
		uint32_t name                        : 32;
#endif
	} s;
	/* struct bdk_usbhx_uahc_suptprt3_dw1_s cn88xx; */
	/* struct bdk_usbhx_uahc_suptprt3_dw1_s cn88xxp1; */
} bdk_usbhx_uahc_suptprt3_dw1_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680000008A4ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT3_DW1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT3_DW1(...) bdk_usbhx_uahc_suptprt3_dw1_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT3_DW1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT3_DW1(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT3_DW1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT3_DW1(...) "USBHX_UAHC_SUPTPRT3_DW1"


/**
 * NCB32b - usbh#_uahc_suptprt3_dw2
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt3_dw2 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt3_dw2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t psic                        : 4;  /**< RO - Protocol speed ID count. */
		uint32_t reserved_16_27              : 12;
		uint32_t compatprtcnt                : 8;  /**< RO - Compatible port count. */
		uint32_t compatprtoff                : 8;  /**< RO - Compatible port offset. */
#else
		uint32_t compatprtoff                : 8;
		uint32_t compatprtcnt                : 8;
		uint32_t reserved_16_27              : 12;
		uint32_t psic                        : 4;
#endif
	} s;
	struct bdk_usbhx_uahc_suptprt3_dw2_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t psic                        : 4;  /**< RO - Protocol speed ID count. */
		uint32_t reserved_27_16              : 12;
		uint32_t compatprtcnt                : 8;  /**< RO - Compatible port count. */
		uint32_t compatprtoff                : 8;  /**< RO - Compatible port offset. */
#else
		uint32_t compatprtoff                : 8;
		uint32_t compatprtcnt                : 8;
		uint32_t reserved_27_16              : 12;
		uint32_t psic                        : 4;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_suptprt3_dw2_cn88xx cn88xxp1;
} bdk_usbhx_uahc_suptprt3_dw2_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680000008A8ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT3_DW2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT3_DW2(...) bdk_usbhx_uahc_suptprt3_dw2_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT3_DW2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT3_DW2(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT3_DW2(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT3_DW2(...) "USBHX_UAHC_SUPTPRT3_DW2"


/**
 * NCB32b - usbh#_uahc_suptprt3_dw3
 *
 * For information on this register, refer to the xHCI Specification, v1.1, section 7.2.
 *
 */
typedef union bdk_usbhx_uahc_suptprt3_dw3 {
	uint32_t u;
	struct bdk_usbhx_uahc_suptprt3_dw3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t protslottype                : 5;  /**< RO - Protocol slot type. */
#else
		uint32_t protslottype                : 5;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	struct bdk_usbhx_uahc_suptprt3_dw3_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_5               : 27;
		uint32_t protslottype                : 5;  /**< RO - Protocol slot type. */
#else
		uint32_t protslottype                : 5;
		uint32_t reserved_31_5               : 27;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_suptprt3_dw3_cn88xx cn88xxp1;
} bdk_usbhx_uahc_suptprt3_dw3_t;

static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_SUPTPRT3_DW3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680000008ACull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_SUPTPRT3_DW3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_SUPTPRT3_DW3(...) bdk_usbhx_uahc_suptprt3_dw3_t
#define bustype_BDK_USBHX_UAHC_SUPTPRT3_DW3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_SUPTPRT3_DW3(p1) (p1)
#define arguments_BDK_USBHX_UAHC_SUPTPRT3_DW3(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_SUPTPRT3_DW3(...) "USBHX_UAHC_SUPTPRT3_DW3"


/**
 * NCB32b - usbh#_uahc_usbcmd
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.1.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_usbcmd {
	uint32_t u;
	struct bdk_usbhx_uahc_usbcmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t eu3s                        : 1;  /**< R/W - Enable U3 MFINDEX stop. */
		uint32_t ewe                         : 1;  /**< R/W - Enable wrap event. */
		uint32_t crs                         : 1;  /**< WO - Controller restore state. */
		uint32_t css                         : 1;  /**< WO - Controller save state. */
		uint32_t lhcrst                      : 1;  /**< R/W1S/H - Light-host-controller reset. */
		uint32_t reserved_4_6                : 3;
		uint32_t hsee                        : 1;  /**< R/W - Host-system-error enable. */
		uint32_t inte                        : 1;  /**< R/W - Interrupter enable. */
		uint32_t hcrst                       : 1;  /**< R/W1S/H - Host-controller reset. */
		uint32_t r_s                         : 1;  /**< R/W - Run/stop. */
#else
		uint32_t r_s                         : 1;
		uint32_t hcrst                       : 1;
		uint32_t inte                        : 1;
		uint32_t hsee                        : 1;
		uint32_t reserved_4_6                : 3;
		uint32_t lhcrst                      : 1;
		uint32_t css                         : 1;
		uint32_t crs                         : 1;
		uint32_t ewe                         : 1;
		uint32_t eu3s                        : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	struct bdk_usbhx_uahc_usbcmd_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t eu3s                        : 1;  /**< R/W - Enable U3 MFINDEX stop. */
		uint32_t ewe                         : 1;  /**< R/W - Enable wrap event. */
		uint32_t crs                         : 1;  /**< WO - Controller restore state. */
		uint32_t css                         : 1;  /**< WO - Controller save state. */
		uint32_t lhcrst                      : 1;  /**< R/W1S/H - Light-host-controller reset. */
		uint32_t reserved_6_4                : 3;
		uint32_t hsee                        : 1;  /**< R/W - Host-system-error enable. */
		uint32_t inte                        : 1;  /**< R/W - Interrupter enable. */
		uint32_t hcrst                       : 1;  /**< R/W1S/H - Host-controller reset. */
		uint32_t r_s                         : 1;  /**< R/W - Run/stop. */
#else
		uint32_t r_s                         : 1;
		uint32_t hcrst                       : 1;
		uint32_t inte                        : 1;
		uint32_t hsee                        : 1;
		uint32_t reserved_6_4                : 3;
		uint32_t lhcrst                      : 1;
		uint32_t css                         : 1;
		uint32_t crs                         : 1;
		uint32_t ewe                         : 1;
		uint32_t eu3s                        : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_usbcmd_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_usbcmd_t;

static inline uint64_t BDK_USBHX_UAHC_USBCMD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_USBCMD(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000020ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_USBCMD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_USBCMD(...) bdk_usbhx_uahc_usbcmd_t
#define bustype_BDK_USBHX_UAHC_USBCMD(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_USBCMD(p1) (p1)
#define arguments_BDK_USBHX_UAHC_USBCMD(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_USBCMD(...) "USBHX_UAHC_USBCMD"


/**
 * NCB32b - usbh#_uahc_usblegctlsts
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.1.2. Note
 * that the SMI interrupts are not connected to anything in a CNXXXX configuration.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_usblegctlsts {
	uint32_t u;
	struct bdk_usbhx_uahc_usblegctlsts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t smi_on_bar                  : 1;  /**< R/W1C/H - System management interrupt on BAR. Never generated. */
		uint32_t smi_on_pci_command          : 1;  /**< R/W1C/H - System management interrupt on PCI command. Never generated. */
		uint32_t smi_on_os_ownership         : 1;  /**< R/W1C/H - System management interrupt on OS ownership change. This bit is set to 1 whenever
                                                                 USBH()_UAHC_USBLEGSUP[HC_OS_OWNED_SEMAPHORES] transitions. */
		uint32_t reserved_21_28              : 8;
		uint32_t smi_on_hostsystemerr        : 1;  /**< RO/H - System-management interrupt on host-system error. Shadow bit of USBH()_UAHC_USBSTS[HSE].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition and effects of the events associated with this bit being
                                                                 set to 1.

                                                                 To clear this bit to a 0, system software must write a 1 to USBH()_UAHC_USBSTS[HSE]. */
		uint32_t reserved_17_19              : 3;
		uint32_t smi_on_event_interrupt      : 1;  /**< RO/H - System-management interrupt on event interrupt. Shadow bit of USBH()_UAHC_USBSTS[EINT].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition. This bit automatically clears when [EINT] clears and
                                                                 sets when [EINT] sets. */
		uint32_t smi_on_bar_en               : 1;  /**< R/W - System-management interrupt on BAR enable. */
		uint32_t smi_on_pci_command_en       : 1;  /**< R/W - System-management interrupt on PCI command enable. */
		uint32_t smi_on_os_ownership_en      : 1;  /**< R/W - System-management interrupt on OS ownership enable. */
		uint32_t reserved_5_12               : 8;
		uint32_t smi_on_hostsystemerr_en     : 1;  /**< R/W - System-management interrupt on host-system error enable */
		uint32_t reserved_1_3                : 3;
		uint32_t usb_smi_en                  : 1;  /**< R/W - USB system-management interrupt enable. */
#else
		uint32_t usb_smi_en                  : 1;
		uint32_t reserved_1_3                : 3;
		uint32_t smi_on_hostsystemerr_en     : 1;
		uint32_t reserved_5_12               : 8;
		uint32_t smi_on_os_ownership_en      : 1;
		uint32_t smi_on_pci_command_en       : 1;
		uint32_t smi_on_bar_en               : 1;
		uint32_t smi_on_event_interrupt      : 1;
		uint32_t reserved_17_19              : 3;
		uint32_t smi_on_hostsystemerr        : 1;
		uint32_t reserved_21_28              : 8;
		uint32_t smi_on_os_ownership         : 1;
		uint32_t smi_on_pci_command          : 1;
		uint32_t smi_on_bar                  : 1;
#endif
	} s;
	struct bdk_usbhx_uahc_usblegctlsts_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t smi_on_bar                  : 1;  /**< R/W1C/H - System management interrupt on BAR. Never generated. */
		uint32_t smi_on_pci_command          : 1;  /**< R/W1C/H - System management interrupt on PCI command. Never generated. */
		uint32_t smi_on_os_ownership         : 1;  /**< R/W1C/H - System management interrupt on OS ownership change. This bit is set to 1 whenever
                                                                 USBH()_UAHC_USBLEGSUP[HC_OS_OWNED_SEMAPHORES] transitions. */
		uint32_t reserved_28_21              : 8;
		uint32_t smi_on_hostsystemerr        : 1;  /**< RO/H - System-management interrupt on host-system error. Shadow bit of USBH()_UAHC_USBSTS[HSE].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition and effects of the events associated with this bit being
                                                                 set to 1.

                                                                 To clear this bit to a 0, system software must write a 1 to USBH()_UAHC_USBSTS[HSE]. */
		uint32_t reserved_19_17              : 3;
		uint32_t smi_on_event_interrupt      : 1;  /**< RO/H - System-management interrupt on event interrupt. Shadow bit of USBH()_UAHC_USBSTS[EINT].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition. This bit automatically clears when [EINT] clears and
                                                                 sets when [EINT] sets. */
		uint32_t smi_on_bar_en               : 1;  /**< R/W - System-management interrupt on BAR enable. */
		uint32_t smi_on_pci_command_en       : 1;  /**< R/W - System-management interrupt on PCI command enable. */
		uint32_t smi_on_os_ownership_en      : 1;  /**< R/W - System-management interrupt on OS ownership enable. */
		uint32_t reserved_12_5               : 8;
		uint32_t smi_on_hostsystemerr_en     : 1;  /**< R/W - System-management interrupt on host-system error enable */
		uint32_t reserved_3_1                : 3;
		uint32_t usb_smi_en                  : 1;  /**< R/W - USB system-management interrupt enable. */
#else
		uint32_t usb_smi_en                  : 1;
		uint32_t reserved_3_1                : 3;
		uint32_t smi_on_hostsystemerr_en     : 1;
		uint32_t reserved_12_5               : 8;
		uint32_t smi_on_os_ownership_en      : 1;
		uint32_t smi_on_pci_command_en       : 1;
		uint32_t smi_on_bar_en               : 1;
		uint32_t smi_on_event_interrupt      : 1;
		uint32_t reserved_19_17              : 3;
		uint32_t smi_on_hostsystemerr        : 1;
		uint32_t reserved_28_21              : 8;
		uint32_t smi_on_os_ownership         : 1;
		uint32_t smi_on_pci_command          : 1;
		uint32_t smi_on_bar                  : 1;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_usblegctlsts_cn88xx cn88xxp1;
} bdk_usbhx_uahc_usblegctlsts_t;

static inline uint64_t BDK_USBHX_UAHC_USBLEGCTLSTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_USBLEGCTLSTS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000884ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_USBLEGCTLSTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_USBLEGCTLSTS(...) bdk_usbhx_uahc_usblegctlsts_t
#define bustype_BDK_USBHX_UAHC_USBLEGCTLSTS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_USBLEGCTLSTS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_USBLEGCTLSTS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_USBLEGCTLSTS(...) "USBHX_UAHC_USBLEGCTLSTS"


/**
 * NCB32b - usbh#_uahc_usblegsup
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.1.1.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_usblegsup {
	uint32_t u;
	struct bdk_usbhx_uahc_usblegsup_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_25_31              : 7;
		uint32_t hc_os_owned_semaphores      : 1;  /**< R/W - HC OS-owned semaphore. */
		uint32_t reserved_17_23              : 7;
		uint32_t hc_bios_owned_semaphores    : 1;  /**< R/W - HC BIOS-owned semaphore. */
		uint32_t nextcapptr                  : 8;  /**< RO - Next xHCI extended-capability pointer. */
		uint32_t capid                       : 8;  /**< RO - Capability ID = USB legacy support. */
#else
		uint32_t capid                       : 8;
		uint32_t nextcapptr                  : 8;
		uint32_t hc_bios_owned_semaphores    : 1;
		uint32_t reserved_17_23              : 7;
		uint32_t hc_os_owned_semaphores      : 1;
		uint32_t reserved_25_31              : 7;
#endif
	} s;
	struct bdk_usbhx_uahc_usblegsup_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_25              : 7;
		uint32_t hc_os_owned_semaphores      : 1;  /**< R/W - HC OS-owned semaphore. */
		uint32_t reserved_23_17              : 7;
		uint32_t hc_bios_owned_semaphores    : 1;  /**< R/W - HC BIOS-owned semaphore. */
		uint32_t nextcapptr                  : 8;  /**< RO - Next xHCI extended-capability pointer. */
		uint32_t capid                       : 8;  /**< RO - Capability ID = USB legacy support. */
#else
		uint32_t capid                       : 8;
		uint32_t nextcapptr                  : 8;
		uint32_t hc_bios_owned_semaphores    : 1;
		uint32_t reserved_23_17              : 7;
		uint32_t hc_os_owned_semaphores      : 1;
		uint32_t reserved_31_25              : 7;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_usblegsup_cn88xx cn88xxp1;
} bdk_usbhx_uahc_usblegsup_t;

static inline uint64_t BDK_USBHX_UAHC_USBLEGSUP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_USBLEGSUP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000880ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_USBLEGSUP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_USBLEGSUP(...) bdk_usbhx_uahc_usblegsup_t
#define bustype_BDK_USBHX_UAHC_USBLEGSUP(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_USBLEGSUP(p1) (p1)
#define arguments_BDK_USBHX_UAHC_USBLEGSUP(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_USBLEGSUP(...) "USBHX_UAHC_USBLEGSUP"


/**
 * NCB32b - usbh#_uahc_usbsts
 *
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.2.
 *
 * This register can be reset by NCB reset,
 * or USBH()_UCTL_CTL[UAHC_RST],
 * or USBH()_UAHC_GCTL[CORESOFTRESET],
 * or USBH()_UAHC_USBCMD[HCRST], or USBH()_UAHC_USBCMD[LHCRST].
 */
typedef union bdk_usbhx_uahc_usbsts {
	uint32_t u;
	struct bdk_usbhx_uahc_usbsts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_13_31              : 19;
		uint32_t hce                         : 1;  /**< RO/H - Host-controller error. */
		uint32_t cnr                         : 1;  /**< RO/H - Controller not ready. */
		uint32_t sre                         : 1;  /**< R/W1C/H - Save/restore error. */
		uint32_t rss                         : 1;  /**< RO/H - Restore state status. */
		uint32_t sss                         : 1;  /**< RO/H - Save state status. */
		uint32_t reserved_5_7                : 3;
		uint32_t pcd                         : 1;  /**< R/W1C/H - Port-change detect. */
		uint32_t eint                        : 1;  /**< R/W1C/H - Event interrupt. */
		uint32_t hse                         : 1;  /**< R/W1C/H - Host-system error. The typical software response to an HSE is to reset the core. */
		uint32_t reserved_1_1                : 1;
		uint32_t hch                         : 1;  /**< RO/H - HC halted. */
#else
		uint32_t hch                         : 1;
		uint32_t reserved_1_1                : 1;
		uint32_t hse                         : 1;
		uint32_t eint                        : 1;
		uint32_t pcd                         : 1;
		uint32_t reserved_5_7                : 3;
		uint32_t sss                         : 1;
		uint32_t rss                         : 1;
		uint32_t sre                         : 1;
		uint32_t cnr                         : 1;
		uint32_t hce                         : 1;
		uint32_t reserved_13_31              : 19;
#endif
	} s;
	struct bdk_usbhx_uahc_usbsts_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_13              : 19;
		uint32_t hce                         : 1;  /**< RO/H - Host-controller error. */
		uint32_t cnr                         : 1;  /**< RO/H - Controller not ready. */
		uint32_t sre                         : 1;  /**< R/W1C/H - Save/restore error. */
		uint32_t rss                         : 1;  /**< RO/H - Restore state status. */
		uint32_t sss                         : 1;  /**< RO/H - Save state status. */
		uint32_t reserved_7_5                : 3;
		uint32_t pcd                         : 1;  /**< R/W1C/H - Port-change detect. */
		uint32_t eint                        : 1;  /**< R/W1C/H - Event interrupt. */
		uint32_t hse                         : 1;  /**< R/W1C/H - Host-system error. The typical software response to an HSE is to reset the core. */
		uint32_t reserved_1_1                : 1;
		uint32_t hch                         : 1;  /**< RO/H - HC halted. */
#else
		uint32_t hch                         : 1;
		uint32_t reserved_1_1                : 1;
		uint32_t hse                         : 1;
		uint32_t eint                        : 1;
		uint32_t pcd                         : 1;
		uint32_t reserved_7_5                : 3;
		uint32_t sss                         : 1;
		uint32_t rss                         : 1;
		uint32_t sre                         : 1;
		uint32_t cnr                         : 1;
		uint32_t hce                         : 1;
		uint32_t reserved_31_13              : 19;
#endif
	} cn88xx;
	struct bdk_usbhx_uahc_usbsts_cn88xx   cn88xxp1;
} bdk_usbhx_uahc_usbsts_t;

static inline uint64_t BDK_USBHX_UAHC_USBSTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UAHC_USBSTS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000000024ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UAHC_USBSTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UAHC_USBSTS(...) bdk_usbhx_uahc_usbsts_t
#define bustype_BDK_USBHX_UAHC_USBSTS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_USBHX_UAHC_USBSTS(p1) (p1)
#define arguments_BDK_USBHX_UAHC_USBSTS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UAHC_USBSTS(...) "USBHX_UAHC_USBSTS"


/**
 * NCB - usbh#_uctl_bist_status
 *
 * This register indicates the results from the built-in self-test (BIST) runs of USBH memories.
 * A 0 indicates pass or never run, a 1 indicates fail. This register can be reset by NCB reset.
 */
typedef union bdk_usbhx_uctl_bist_status {
	uint64_t u;
	struct bdk_usbhx_uctl_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t uctl_xm_r_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UCTL AxiMaster read-data FIFO. */
		uint64_t uctl_xm_w_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_35_39              : 5;
		uint64_t uahc_ram2_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UAHC RxFIFO RAM (RAM2). */
		uint64_t uahc_ram1_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UAHC TxFIFO RAM (RAM1). */
		uint64_t uahc_ram0_bist_ndone        : 1;  /**< RO/H - BIST is not complete for the UAHC descriptor/register cache (RAM0). */
		uint64_t reserved_10_31              : 22;
		uint64_t uctl_xm_r_bist_status       : 1;  /**< RO/H - BIST status of the UCTL AxiMaster read-data FIFO. */
		uint64_t uctl_xm_w_bist_status       : 1;  /**< RO/H - BIST status of the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_3_7                : 5;
		uint64_t uahc_ram2_bist_status       : 1;  /**< RO/H - BIST status of the UAHC RxFIFO RAM (RAM2). */
		uint64_t uahc_ram1_bist_status       : 1;  /**< RO/H - BIST status of the UAHC TxFIFO RAM (RAM1). */
		uint64_t uahc_ram0_bist_status       : 1;  /**< RO/H - BIST status of the UAHC descriptor/register cache (RAM0). */
#else
		uint64_t uahc_ram0_bist_status       : 1;
		uint64_t uahc_ram1_bist_status       : 1;
		uint64_t uahc_ram2_bist_status       : 1;
		uint64_t reserved_3_7                : 5;
		uint64_t uctl_xm_w_bist_status       : 1;
		uint64_t uctl_xm_r_bist_status       : 1;
		uint64_t reserved_10_31              : 22;
		uint64_t uahc_ram0_bist_ndone        : 1;
		uint64_t uahc_ram1_bist_ndone        : 1;
		uint64_t uahc_ram2_bist_ndone        : 1;
		uint64_t reserved_35_39              : 5;
		uint64_t uctl_xm_w_bist_ndone        : 1;
		uint64_t uctl_xm_r_bist_ndone        : 1;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_usbhx_uctl_bist_status_s cn88xx; */
	/* struct bdk_usbhx_uctl_bist_status_s cn88xxp1; */
} bdk_usbhx_uctl_bist_status_t;

static inline uint64_t BDK_USBHX_UCTL_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100008ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_BIST_STATUS(...) bdk_usbhx_uctl_bist_status_t
#define bustype_BDK_USBHX_UCTL_BIST_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_BIST_STATUS(p1) (p1)
#define arguments_BDK_USBHX_UCTL_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_BIST_STATUS(...) "USBHX_UCTL_BIST_STATUS"


/**
 * NCB - usbh#_uctl_ctl
 *
 * This register controls clocks, resets, power, and BIST.
 *
 * This register can be reset by NCB reset.
 */
typedef union bdk_usbhx_uctl_ctl {
	uint64_t u;
	struct bdk_usbhx_uctl_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t clear_bist                  : 1;  /**< R/W - BIST fast-clear mode select. A BIST run with this bit set clears all entries in USBH RAMs
                                                                 to 0x0.

                                                                 There are two major modes of BIST: full and clear. Full BIST is run by the BIST state
                                                                 machine when CLEAR_BIST is deasserted during BIST. Clear BIST is run if CLEAR_BIST is
                                                                 asserted during BIST.

                                                                 To avoid race conditions, software must first perform a CSR write operation that puts the
                                                                 CLEAR_BIST setting into the correct state and then perform another CSR write operation to
                                                                 set the BIST trigger (keeping the CLEAR_BIST state constant).
                                                                 CLEAR BIST completion is indicated by USBH()_UCTL_BIST_STATUS. A BIST clear operation
                                                                 takes almost 2,000 controller-clock cycles for the largest RAM. */
		uint64_t start_bist                  : 1;  /**< R/W - Rising edge starts BIST on the memories in USBH.
                                                                 To run BIST, the controller clock must be both configured and enabled, and should be
                                                                 configured to the maximum available frequency given the available coprocessor clock and
                                                                 dividers.
                                                                 Also, the UCTL, UAHC, and UPHY should be held in software- initiated reset (using
                                                                 UPHY_RST, UAHC_RST, UCTL_RST) until BIST is complete.
                                                                 BIST defect status can be checked after FULL BIST completion, both of which are indicated
                                                                 in USBH()_UCTL_BIST_STATUS. The full BIST run takes almost 80,000 controller-clock cycles
                                                                 for
                                                                 the largest RAM. */
		uint64_t ref_clk_sel                 : 2;  /**< R/W - Reference clock select. Choose reference-clock source for the SuperSpeed and high-speed
                                                                 PLL blocks.
                                                                 0x0 = Reference clock source for both PLLs come from the USB pads.
                                                                 0x1 = Reserved.
                                                                 0x2 = Reserved.
                                                                 0x3 = Reserved.

                                                                 This value can be changed only during UPHY_RST.

                                                                 If REF_CLK_SEL = 0x0, then the reference clock input cannot be spread-spectrum.

                                                                 INTERNAL: For the 0x1 selection, reference clock source for SuperSpeed PLL is from the USB
                                                                 pads, reference clock source for HighSpeed PLL is PLL_REF_CLK. But in 78xx, PLL_REF_CLK
                                                                 cannot be routed to USB without violating jitter requirements */
		uint64_t ssc_en                      : 1;  /**< R/W - Spread-spectrum clock enable. Enables spread-spectrum clock production in the SuperSpeed
                                                                 function. If the input reference clock for the SuperSpeed PLL is already spread-spectrum,
                                                                 then do not enable this feature. The clocks sourced to the SuperSpeed function must have
                                                                 spread-spectrum to be compliant with the USB specification.
                                                                 The high-speed PLL cannot support a spread-spectrum input, so REF_CLK_SEL = 0x0 must
                                                                 enable this feature.
                                                                 This value may only be changed during UPHY_RST. */
		uint64_t ssc_range                   : 3;  /**< R/W - Spread-spectrum clock range. Selects the range of spread-spectrum modulation when SSC_EN
                                                                 is asserted and the PHY is spreading the SuperSpeed transmit clocks.
                                                                 Applies a fixed offset to the phase accumulator.
                                                                 0x0 = -4980 ppm downspread of clock.
                                                                 0x1 = -4492 ppm.
                                                                 0x2 = -4003 ppm.
                                                                 0x3-0x7 = reserved.

                                                                 All of these settings are within the USB 3.0 specification. The amount of EMI emission
                                                                 reduction might decrease as the SSC_RANGE increases; therefore, the SSC_RANGE settings can
                                                                 be registered to enable the amount of spreading to be adjusted on a per-application basis.
                                                                 This value can be changed only during UPHY_RST. */
		uint64_t ssc_ref_clk_sel             : 9;  /**< R/W - Enables non-standard oscillator frequencies to generate targeted MPLL output rates. Input
                                                                 corresponds to the frequency-synthesis coefficient.

                                                                 [55:53]: modulus - 1,
                                                                 [52:47]: 2's complement push amount

                                                                 Must leave at reset value of 0x0.
                                                                 This value may only be changed during UPHY_RST. */
		uint64_t mpll_multiplier             : 7;  /**< R/W - Multiplies the reference clock to a frequency suitable for intended operating speed. Must
                                                                 leave at reset value of 0x0. This value may only be changed during UPHY_RST.
                                                                 This value is superseded by the REF_CLK_FSEL\<5:3\> selection. */
		uint64_t ref_ssp_en                  : 1;  /**< R/W - Enables reference clock to the prescaler for SuperSpeed function. This should always be
                                                                 enabled since this output clock is used to drive the UAHC suspend-mode clock during
                                                                 low-power states.

                                                                 This value can be changed only during UPHY_RST or during low-power states.
                                                                 The reference clock must be running and stable before UPHY_RST is deasserted and before
                                                                 REF_SSP_EN is asserted. */
		uint64_t ref_clk_div2                : 1;  /**< R/W - Divides the reference clock by 2 before feeding it into the REF_CLK_FSEL divider. Must
                                                                 leave at reset value of 0x0.

                                                                 This value can be changed only during UPHY_RST. */
		uint64_t ref_clk_fsel                : 6;  /**< R/W - Selects the reference clock frequency for the SuperSpeed and high-speed PLL blocks. The
                                                                 legal values are as follows:
                                                                 0x27 = External reference clock 100 MHz.

                                                                 All other values are reserved.
                                                                 This value may only be changed during UPHY_RST.
                                                                 INTERNAL: 0x2A = External reference clock 24 MHz.
                                                                 0x31 = External reference clock 20 MHz.
                                                                 0x38 = External reference clock 19.2 MHz. */
		uint64_t reserved_31_31              : 1;
		uint64_t h_clk_en                    : 1;  /**< R/W - Controller-clock enable. When set to 1, the controller clock is generated. This also
                                                                 enables access to UCTL registers 0x30-0xF8. */
		uint64_t h_clk_byp_sel               : 1;  /**< R/W - Select the bypass input to the controller-clock divider.
                                                                 0 = Use the divided coprocessor clock from the H_CLKDIV divider.
                                                                 1 = Use the bypass clock from the GPIO pins.

                                                                 This signal is just a multiplexer-select signal; it does not enable the controller clock.
                                                                 You must still set H_CLKDIV_EN separately. H_CLK_BYP_SEL select should not be changed
                                                                 unless H_CLKDIV_EN is disabled.

                                                                 The bypass clock can be selected and running even if the controller-clock dividers are not
                                                                 running.
                                                                 INTERNAL: Generally bypass is only used for scan purposes. */
		uint64_t h_clkdiv_rst                : 1;  /**< R/W - Controller-clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
		uint64_t reserved_27_27              : 1;
		uint64_t h_clkdiv_sel                : 3;  /**< R/W - Controller clock-frequency-divider select. The controller-clock frequency is the
                                                                 coprocessor-clock frequency divided by H_CLKDIV_SEL and must be at or below 300 MHz.
                                                                 The divider values are the following:
                                                                 0x0 = divide by 1.
                                                                 0x1 = divide by 2.
                                                                 0x2 = divide by 4.
                                                                 0x3 = divide by 6.
                                                                 0x4 = divide by 8.
                                                                 0x5 = divide by 16.
                                                                 0x6 = divide by 24.
                                                                 0x7 = divide by 32.

                                                                 For USB3:
                                                                 * The controller-clock frequency must be at or above 125 MHz for any USB3 operation.
                                                                 * The controller-clock frequency must be at or above
                                                                 150 MHz for full-rate USB3 operation.

                                                                 For USB2:
                                                                 * The controller-clock frequency must be at or above 62.5 MHz for any USB2 operation.
                                                                 * The controller-clock frequency must be at or above
                                                                 90 MHz for full-rate USB2 operation.

                                                                 This field can be changed only when H_CLKDIV_RST = 1.
                                                                 INTERNAL: 150MHz is from the maximum of Synopsys DWC_usb3 Databook v2.50a, table A-16, row
                                                                 1, col 12. Synopsys DWC_usb3 Databook v2.50a, table A-17, row 7, col 9. Synopsys DWC_usb3
                                                                 Databook v2.50a, table A-16, row 7, col 9. HOST2\>62.5MHz in HOST mode is from Synopsys
                                                                 DWC_usb3 Databook v2.50a, section A.12.5, 3rd bullet in Note on page 894. HOST2\>90MHz was
                                                                 arrived at from some math: 62.5MHz + (diff between row 1 and 2, col 12 of table A-16). */
		uint64_t reserved_22_23              : 2;
		uint64_t usb3_port_perm_attach       : 1;  /**< R/W - Indicates this port is permanently attached. This is a strap signal; it should be modified
                                                                 only when UPHY_RST is asserted. */
		uint64_t usb2_port_perm_attach       : 1;  /**< R/W - Indicates this port is permanently attached. This is a strap signal; it should be modified
                                                                 only when UPHY_RST is asserted. */
		uint64_t reserved_19_19              : 1;
		uint64_t usb3_port_disable           : 1;  /**< R/W - Disables the USB3 (SuperSpeed) portion of this PHY. When set to 1, this signal stops
                                                                 reporting connect/disconnect events on the port and keeps the port in disabled state. This
                                                                 could be used for security reasons where hardware can disable a port regardless of whether
                                                                 xHCI driver enables a port or not.
                                                                 USBH()_UAHC_HCSPARAMS1[MAXPORTS] is not affected by this signal.

                                                                 This is a strap signal; it should be modified only when UPHY_RST is asserted. */
		uint64_t reserved_17_17              : 1;
		uint64_t usb2_port_disable           : 1;  /**< R/W - Disables USB2 (high-speed/full-speed/low-speed) portion of this PHY. When set to 1, this
                                                                 signal stops reporting connect/disconnect events on the port and keeps the port in
                                                                 disabled state. This could be used for security reasons where hardware can disable a port
                                                                 regardless of whether xHCI driver enables a port or not.
                                                                 USBH()_UAHC_HCSPARAMS1[MAXPORTS] is not affected by this signal.

                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted.
                                                                 If Port0 is required to be disabled, ensure that the utmi_clk[0] is running at the normal
                                                                 speed. Also, all the enabled USB2.0 ports should have the same clock frequency as Port0. */
		uint64_t reserved_15_15              : 1;
		uint64_t ss_power_en                 : 1;  /**< R/W - PHY SuperSpeed block power enable.
                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted. */
		uint64_t reserved_13_13              : 1;
		uint64_t hs_power_en                 : 1;  /**< R/W - PHY high-speed block power enable.
                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted. */
		uint64_t reserved_5_11               : 7;
		uint64_t csclk_en                    : 1;  /**< R/W - Turns on the USB UCTL interface clock (coprocessor clock). This enables access to UAHC
                                                                 registers via the NCB, as well as UCTL registers starting from 0x30 via the RSL bus. */
		uint64_t reserved_3_3                : 1;
		uint64_t uphy_rst                    : 1;  /**< R/W - PHY reset; resets UPHY; active-high. */
		uint64_t uahc_rst                    : 1;  /**< R/W - Software reset; resets UAHC; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 or NCB protocols. */
		uint64_t uctl_rst                    : 1;  /**< R/W - Software reset; resets UCTL; active-high.
                                                                 Resets UAHC DMA and register shims. Resets UCTL RSL registers 0x30-0xF8.
                                                                 Does not reset UCTL RSL registers 0x0-0x28.
                                                                 UCTL RSL registers starting from 0x30 can be accessed only after the controller clock is
                                                                 active and UCTL_RST is deasserted.
                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL, NCB, and CIB protocols. */
#else
		uint64_t uctl_rst                    : 1;
		uint64_t uahc_rst                    : 1;
		uint64_t uphy_rst                    : 1;
		uint64_t reserved_3_3                : 1;
		uint64_t csclk_en                    : 1;
		uint64_t reserved_5_11               : 7;
		uint64_t hs_power_en                 : 1;
		uint64_t reserved_13_13              : 1;
		uint64_t ss_power_en                 : 1;
		uint64_t reserved_15_15              : 1;
		uint64_t usb2_port_disable           : 1;
		uint64_t reserved_17_17              : 1;
		uint64_t usb3_port_disable           : 1;
		uint64_t reserved_19_19              : 1;
		uint64_t usb2_port_perm_attach       : 1;
		uint64_t usb3_port_perm_attach       : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t h_clkdiv_sel                : 3;
		uint64_t reserved_27_27              : 1;
		uint64_t h_clkdiv_rst                : 1;
		uint64_t h_clk_byp_sel               : 1;
		uint64_t h_clk_en                    : 1;
		uint64_t reserved_31_31              : 1;
		uint64_t ref_clk_fsel                : 6;
		uint64_t ref_clk_div2                : 1;
		uint64_t ref_ssp_en                  : 1;
		uint64_t mpll_multiplier             : 7;
		uint64_t ssc_ref_clk_sel             : 9;
		uint64_t ssc_range                   : 3;
		uint64_t ssc_en                      : 1;
		uint64_t ref_clk_sel                 : 2;
		uint64_t start_bist                  : 1;
		uint64_t clear_bist                  : 1;
#endif
	} s;
	/* struct bdk_usbhx_uctl_ctl_s        cn88xx; */
	/* struct bdk_usbhx_uctl_ctl_s        cn88xxp1; */
} bdk_usbhx_uctl_ctl_t;

static inline uint64_t BDK_USBHX_UCTL_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100000ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_CTL(...) bdk_usbhx_uctl_ctl_t
#define bustype_BDK_USBHX_UCTL_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_CTL(p1) (p1)
#define arguments_BDK_USBHX_UCTL_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_CTL(...) "USBHX_UCTL_CTL"


/**
 * NCB - usbh#_uctl_ecc
 *
 * This register can be used to disable ECC correction, insert ECC errors, and debug ECC
 * failures.
 * * The ECC_ERR* fields are captured when there are no outstanding ECC errors indicated in
 * INTSTAT and a new ECC error arrives. Prioritization for multiple events occurring on the same
 * cycle is indicated by the ECC_ERR_SOURCE enumeration: highest encoded value has highest
 * priority.
 * * The *ECC_*_DIS fields disable ECC correction; SBE and DBE errors are still reported. If
 * *ECC_*_DIS = 0x1, then no data-correction occurs.
 * * The *ECC_FLIP_SYND fields flip the syndrome\<1:0\> bits to generate single-bit/double-bit
 * error for testing.
 *
 * 0x0 = normal operation.
 * 0x1 = SBE on bit[0].
 * 0x2 = SBE on bit[1].
 * 0x3 = DBE on bit[1:0].
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 */
typedef union bdk_usbhx_uctl_ecc {
	uint64_t u;
	struct bdk_usbhx_uctl_ecc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t ecc_err_source              : 4;  /**< RO/H - Source of ECC error, see UCTL_ECC_ERR_SOURCE_E. */
		uint64_t ecc_err_syndrome            : 8;  /**< RO/H - Syndrome bits of the ECC error. */
		uint64_t ecc_err_address             : 16; /**< RO/H - RAM address of the ECC error. */
		uint64_t reserved_21_31              : 11;
		uint64_t uctl_xm_r_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uctl_xm_r_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UCTL AxiMaster read-data FIFO. */
		uint64_t uctl_xm_w_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uctl_xm_w_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_9_14               : 6;
		uint64_t uahc_ram2_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uahc_ram2_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UAHC RxFIFO RAMs (RAM2). */
		uint64_t uahc_ram1_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uahc_ram1_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UAHC TxFIFO RAMs (RAM1). */
		uint64_t uahc_ram0_ecc_flip_synd     : 2;  /**< R/W - Insert ECC error for testing purposes. */
		uint64_t uahc_ram0_ecc_cor_dis       : 1;  /**< R/W - Enables ECC correction on UAHC Desc/Reg cache (RAM0). */
#else
		uint64_t uahc_ram0_ecc_cor_dis       : 1;
		uint64_t uahc_ram0_ecc_flip_synd     : 2;
		uint64_t uahc_ram1_ecc_cor_dis       : 1;
		uint64_t uahc_ram1_ecc_flip_synd     : 2;
		uint64_t uahc_ram2_ecc_cor_dis       : 1;
		uint64_t uahc_ram2_ecc_flip_synd     : 2;
		uint64_t reserved_9_14               : 6;
		uint64_t uctl_xm_w_ecc_cor_dis       : 1;
		uint64_t uctl_xm_w_ecc_flip_synd     : 2;
		uint64_t uctl_xm_r_ecc_cor_dis       : 1;
		uint64_t uctl_xm_r_ecc_flip_synd     : 2;
		uint64_t reserved_21_31              : 11;
		uint64_t ecc_err_address             : 16;
		uint64_t ecc_err_syndrome            : 8;
		uint64_t ecc_err_source              : 4;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_usbhx_uctl_ecc_s        cn88xx; */
	/* struct bdk_usbhx_uctl_ecc_s        cn88xxp1; */
} bdk_usbhx_uctl_ecc_t;

static inline uint64_t BDK_USBHX_UCTL_ECC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_ECC(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680001000F0ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_ECC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_ECC(...) bdk_usbhx_uctl_ecc_t
#define bustype_BDK_USBHX_UCTL_ECC(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_ECC(p1) (p1)
#define arguments_BDK_USBHX_UCTL_ECC(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_ECC(...) "USBHX_UCTL_ECC"


/**
 * NCB - usbh#_uctl_host_cfg
 *
 * This register allows configuration of various host controller (UAHC) features. Most of these
 * are strap signals and should be modified only while the controller is not running.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 */
typedef union bdk_usbhx_uctl_host_cfg {
	uint64_t u;
	struct bdk_usbhx_uctl_host_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t host_current_belt           : 12; /**< RO - This signal indicates the minimum value of all received BELT values and the BELT that is
                                                                 set by the Set LTV command. */
		uint64_t reserved_38_47              : 10;
		uint64_t fla                         : 6;  /**< R/W - High-speed jitter adjustment. Indicates the correction required to accommodate mac3 clock
                                                                 and utmi clock jitter to measure 125us duration. With FLA tied to 0x0, the high-speed
                                                                 125us micro-frame is counted for 123933ns. The value needs to be programmed in terms of
                                                                 high-speed bit times in a 30 MHz cycle. Default value that needs to be driven is 0x20
                                                                 (assuming 30 MHz perfect clock).

                                                                 FLA connects to the FLADJ register defined in the xHCI spec in the PCI configuration
                                                                 space. Each count is equal to 16 high-speed bit times. By default when this register is
                                                                 set to 0x20, it gives 125us interval. Now, based on the clock accuracy, you can decrement
                                                                 the count or increment the count to get the 125 us uSOF window.
                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
		uint64_t reserved_29_31              : 3;
		uint64_t bme                         : 1;  /**< R/W - Bus-master enable. This signal is used to disable the bus-mastering capability of the
                                                                 host. Disabling this capability stalls DMA accesses. */
		uint64_t oci_en                      : 1;  /**< R/W - Overcurrent-indication enable. When enabled, OCI input to UAHC is taken from the GPIO
                                                                 signals and sense-converted based on OCI_ACTIVE_HIGH_EN. The MIO GPIO multiplexer must be
                                                                 programmed accordingly.

                                                                 When disabled, OCI input to UAHC is forced to the correct inactive state based on
                                                                 OCI_ACTIVE_HIGH_EN.

                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
		uint64_t oci_active_high_en          : 1;  /**< R/W - Overcurrent sense selection. The off-chip sense (high/low) is converted to match the
                                                                 controller's active-high sense.
                                                                 0 = Overcurrent indication from off-chip source is active-low.
                                                                 1 = Overcurrent indication from off-chip source is active-high.

                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
		uint64_t ppc_en                      : 1;  /**< R/W - Port-power-control enable.
                                                                 0 = USBH()_UAHC_HCCPARAMS[PPC] report port-power-control feature is unavailable.
                                                                 1 = USBH()_UAHC_HCCPARAMS[PPC] reports port-power-control feature is available. PPC output
                                                                 from UAHC is taken to the GPIO signals and sense-converted based on PPC_ACTIVE_HIGH_EN.

                                                                 The MIO GPIO multiplexer must be programmed accordingly.

                                                                 This is a strap signal; it should only be modified when either the UCTL_CTL[UAHC] or
                                                                 UAHC_GCTL[CoreSoftReset] is asserted. */
		uint64_t ppc_active_high_en          : 1;  /**< R/W - Port power control sense selection. The active-high port-power-control output to off-chip
                                                                 source is converted to match the off-chip sense.
                                                                 0 = Port-power control to off-chip source is active-low.
                                                                 1 = Port-power control to off-chip source is active-high.

                                                                 This is a strap signal; it should only be modified when either the UCTL_CTL[UAHC] or
                                                                 UAHC_GCTL[CoreSoftReset] is asserted. */
		uint64_t reserved_0_23               : 24;
#else
		uint64_t reserved_0_23               : 24;
		uint64_t ppc_active_high_en          : 1;
		uint64_t ppc_en                      : 1;
		uint64_t oci_active_high_en          : 1;
		uint64_t oci_en                      : 1;
		uint64_t bme                         : 1;
		uint64_t reserved_29_31              : 3;
		uint64_t fla                         : 6;
		uint64_t reserved_38_47              : 10;
		uint64_t host_current_belt           : 12;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_usbhx_uctl_host_cfg_s   cn88xx; */
	/* struct bdk_usbhx_uctl_host_cfg_s   cn88xxp1; */
} bdk_usbhx_uctl_host_cfg_t;

static inline uint64_t BDK_USBHX_UCTL_HOST_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_HOST_CFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680001000E0ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_HOST_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_HOST_CFG(...) bdk_usbhx_uctl_host_cfg_t
#define bustype_BDK_USBHX_UCTL_HOST_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_HOST_CFG(p1) (p1)
#define arguments_BDK_USBHX_UCTL_HOST_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_HOST_CFG(...) "USBHX_UCTL_HOST_CFG"


/**
 * NCB - usbh#_uctl_intena_w1c
 */
typedef union bdk_usbhx_uctl_intena_w1c {
	uint64_t u;
	struct bdk_usbhx_uctl_intena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_22_25              : 4;
		uint64_t ram2_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram2_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram1_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram1_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram0_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t ram0_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t reserved_8_15               : 8;
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO */
		uint64_t reserved_3_5                : 3;
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. Error information is logged in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates the
                                                                 assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see the description in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE]. The hardware does not translate the request
                                                                 correctly
                                                                 and results may violate NCB protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. Error information is logged in USBH()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t reserved_3_5                : 3;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t reserved_8_15               : 8;
		uint64_t ram0_sbe                    : 1;
		uint64_t ram0_dbe                    : 1;
		uint64_t ram1_sbe                    : 1;
		uint64_t ram1_dbe                    : 1;
		uint64_t ram2_sbe                    : 1;
		uint64_t ram2_dbe                    : 1;
		uint64_t reserved_22_25              : 4;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_usbhx_uctl_intena_w1c_s cn88xx; */
	/* struct bdk_usbhx_uctl_intena_w1c_s cn88xxp1; */
} bdk_usbhx_uctl_intena_w1c_t;

static inline uint64_t BDK_USBHX_UCTL_INTENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_INTENA_W1C(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100040ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_INTENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_INTENA_W1C(...) bdk_usbhx_uctl_intena_w1c_t
#define bustype_BDK_USBHX_UCTL_INTENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_INTENA_W1C(p1) (p1)
#define arguments_BDK_USBHX_UCTL_INTENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_INTENA_W1C(...) "USBHX_UCTL_INTENA_W1C"


/**
 * NCB - usbh#_uctl_intena_w1s
 */
typedef union bdk_usbhx_uctl_intena_w1s {
	uint64_t u;
	struct bdk_usbhx_uctl_intena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_22_25              : 4;
		uint64_t ram2_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram2_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram1_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram1_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram0_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t ram0_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t reserved_8_15               : 8;
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO */
		uint64_t reserved_3_5                : 3;
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. Error information is logged in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates the
                                                                 assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see the description in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE]. The hardware does not translate the request
                                                                 correctly
                                                                 and results may violate NCB protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. Error information is logged in USBH()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t reserved_3_5                : 3;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t reserved_8_15               : 8;
		uint64_t ram0_sbe                    : 1;
		uint64_t ram0_dbe                    : 1;
		uint64_t ram1_sbe                    : 1;
		uint64_t ram1_dbe                    : 1;
		uint64_t ram2_sbe                    : 1;
		uint64_t ram2_dbe                    : 1;
		uint64_t reserved_22_25              : 4;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_usbhx_uctl_intena_w1s_s cn88xx; */
	/* struct bdk_usbhx_uctl_intena_w1s_s cn88xxp1; */
} bdk_usbhx_uctl_intena_w1s_t;

static inline uint64_t BDK_USBHX_UCTL_INTENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_INTENA_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100048ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_INTENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_INTENA_W1S(...) bdk_usbhx_uctl_intena_w1s_t
#define bustype_BDK_USBHX_UCTL_INTENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_INTENA_W1S(p1) (p1)
#define arguments_BDK_USBHX_UCTL_INTENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_INTENA_W1S(...) "USBHX_UCTL_INTENA_W1S"


/**
 * NCB - usbh#_uctl_intstat
 *
 * This register provides a summary of different bits of RSL interrupts. DBEs are detected and
 * SBE are corrected. For debugging output for ECC DBEs/SBEs, see USBH()_UCTL_ECC. This register
 * can
 * be reset by NCB reset.
 */
typedef union bdk_usbhx_uctl_intstat {
	uint64_t u;
	struct bdk_usbhx_uctl_intstat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_22_25              : 4;
		uint64_t ram2_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram2_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram1_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram1_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram0_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t ram0_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t reserved_8_15               : 8;
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO */
		uint64_t reserved_3_5                : 3;
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. Error information is logged in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates the
                                                                 assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see the description in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE]. The hardware does not translate the request
                                                                 correctly
                                                                 and results may violate NCB protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. Error information is logged in USBH()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t reserved_3_5                : 3;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t reserved_8_15               : 8;
		uint64_t ram0_sbe                    : 1;
		uint64_t ram0_dbe                    : 1;
		uint64_t ram1_sbe                    : 1;
		uint64_t ram1_dbe                    : 1;
		uint64_t ram2_sbe                    : 1;
		uint64_t ram2_dbe                    : 1;
		uint64_t reserved_22_25              : 4;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_usbhx_uctl_intstat_s    cn88xx; */
	/* struct bdk_usbhx_uctl_intstat_s    cn88xxp1; */
} bdk_usbhx_uctl_intstat_t;

static inline uint64_t BDK_USBHX_UCTL_INTSTAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_INTSTAT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100030ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_INTSTAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_INTSTAT(...) bdk_usbhx_uctl_intstat_t
#define bustype_BDK_USBHX_UCTL_INTSTAT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_INTSTAT(p1) (p1)
#define arguments_BDK_USBHX_UCTL_INTSTAT(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_INTSTAT(...) "USBHX_UCTL_INTSTAT"


/**
 * NCB - usbh#_uctl_intstat_w1s
 */
typedef union bdk_usbhx_uctl_intstat_w1s {
	uint64_t u;
	struct bdk_usbhx_uctl_intstat_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t xm_r_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_r_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
		uint64_t xm_w_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t xm_w_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
		uint64_t reserved_22_25              : 4;
		uint64_t ram2_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram2_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC RxFIFO RAMs (RAM2). */
		uint64_t ram1_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram1_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC TxFIFO RAMs (RAM1). */
		uint64_t ram0_dbe                    : 1;  /**< R/W1C/H - Detected double-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t ram0_sbe                    : 1;  /**< R/W1C/H - Detected single-bit error on the UAHC Desc/Reg Cache (RAM0). */
		uint64_t reserved_8_15               : 8;
		uint64_t dma_rd_err                  : 1;  /**< R/W1C/H - Received DMA read response error from NCBO */
		uint64_t dma_wr_err                  : 1;  /**< R/W1C/H - Received DMA write response error from NCBO */
		uint64_t reserved_3_5                : 3;
		uint64_t xm_bad_dma                  : 1;  /**< R/W1C/H - Detected bad DMA access from UAHC to NCB. Error information is logged in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates the
                                                                 assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see the description in
                                                                 USBH()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE]. The hardware does not translate the request
                                                                 correctly
                                                                 and results may violate NCB protocols. */
		uint64_t xs_ncb_oob                  : 1;  /**< R/W1C/H - Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. Error information is logged in USBH()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t xs_ncb_oob                  : 1;
		uint64_t xm_bad_dma                  : 1;
		uint64_t reserved_3_5                : 3;
		uint64_t dma_wr_err                  : 1;
		uint64_t dma_rd_err                  : 1;
		uint64_t reserved_8_15               : 8;
		uint64_t ram0_sbe                    : 1;
		uint64_t ram0_dbe                    : 1;
		uint64_t ram1_sbe                    : 1;
		uint64_t ram1_dbe                    : 1;
		uint64_t ram2_sbe                    : 1;
		uint64_t ram2_dbe                    : 1;
		uint64_t reserved_22_25              : 4;
		uint64_t xm_w_sbe                    : 1;
		uint64_t xm_w_dbe                    : 1;
		uint64_t xm_r_sbe                    : 1;
		uint64_t xm_r_dbe                    : 1;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_usbhx_uctl_intstat_w1s_s cn88xx; */
	/* struct bdk_usbhx_uctl_intstat_w1s_s cn88xxp1; */
} bdk_usbhx_uctl_intstat_w1s_t;

static inline uint64_t BDK_USBHX_UCTL_INTSTAT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_INTSTAT_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100038ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_INTSTAT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_INTSTAT_W1S(...) bdk_usbhx_uctl_intstat_w1s_t
#define bustype_BDK_USBHX_UCTL_INTSTAT_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_INTSTAT_W1S(p1) (p1)
#define arguments_BDK_USBHX_UCTL_INTSTAT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_INTSTAT_W1S(...) "USBHX_UCTL_INTSTAT_W1S"


/**
 * NCB - usbh#_uctl_port#_cfg_hs
 *
 * This register controls configuration and test controls for the HS port 0 PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset.
 */
typedef union bdk_usbhx_uctl_portx_cfg_hs {
	uint64_t u;
	struct bdk_usbhx_uctl_portx_cfg_hs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_58_63              : 6;
		uint64_t comp_dis_tune               : 3;  /**< R/W - Disconnect threshold voltage. Adjusts the voltage level for the threshold used to detect a
                                                                 disconnect event at the host.
                                                                 A positive binary bit setting change results in a +1.5% incremental change in the
                                                                 threshold voltage level, while a negative binary bit setting change results in a -1.5%
                                                                 incremental change in the threshold voltage level. */
		uint64_t sq_rx_tune                  : 3;  /**< R/W - Squelch threshold adjustment. Adjusts the voltage level for the threshold used to detect
                                                                 valid high-speed data.
                                                                 A positive binary bit setting change results in a -5% incremental change in threshold
                                                                 voltage level, while a negative binary bit setting change results in a +5% incremental
                                                                 change in threshold voltage level. */
		uint64_t tx_fsls_tune                : 4;  /**< R/W - Low-speed/full-speed source impedance adjustment. Adjusts the low- and full-speed single-
                                                                 ended source impedance while driving high. This parameter control is encoded in
                                                                 thermometer code.
                                                                 A positive thermometer code change results in a -2.5% incremental change in source
                                                                 impedance. A negative thermometer code change results in +2.5% incremental change in
                                                                 source impedance. Any non-thermometer code setting (that is, 0x9) is not supported and
                                                                 reserved. */
		uint64_t reserved_46_47              : 2;
		uint64_t tx_hs_xv_tune               : 2;  /**< R/W - Transmitter high-speed crossover adjustment. This bus adjusts the voltage at which the DP0
                                                                 and DM0 signals cross while transmitting in high-speed mode.
                                                                 0x3 = default setting.
                                                                 0x2 = +15 mV.
                                                                 0x1 = -15 mV.
                                                                 0x0 = reserved. */
		uint64_t tx_preemp_amp_tune          : 2;  /**< R/W - High-speed transmitter pre-emphasis current control. Controls the amount of current
                                                                 sourced to DP0 and DM0 after a J-to-K or K-to-J transition. The high-speed transmitter
                                                                 preemphasis current is defined in terms of unit amounts. One unit amount is approximately
                                                                 600 A and is defined as 1* preemphasis current.
                                                                 0x0 = High-speed TX preemphasis is disabled.
                                                                 0x1 = High-speed TX preemphasis circuit sources 1* preemphasis current.
                                                                 0x2 = High-speed TX preemphasis circuit sources 2* preemphasis current.
                                                                 0x3 = High-speed TX preemphasis circuit sources 3* preemphasis current.

                                                                 If these signals are not used, set them to 0x0. */
		uint64_t reserved_41_41              : 1;
		uint64_t tx_preemp_pulse_tune        : 1;  /**< R/W - High-speed transmitter preemphasis duration control. Controls the duration for which the
                                                                 high-speed preemphasis current is sourced onto DP0 or DM0. The high-speed transmitter
                                                                 preemphasis duration is defined in terms of unit amounts. One unit of preemphasis duration
                                                                 is approximately 580 ps and is defined as 1* preemphasis duration. This signal is valid
                                                                 only if either TX_PREEMP_AMP_TUNE0[1] or TX_PREEMP_AMP_TUNE0[0] is set to 1.
                                                                 0 = 2*, long preemphasis current duration (design default)
                                                                 1 = 1*, short preemphasis current duration

                                                                 If this signal is not used, set it to 0. */
		uint64_t tx_res_tune                 : 2;  /**< R/W - USB source-impedance adjustment. Some applications require additional devices to be added
                                                                 on the USB, such as a series switch, which can add significant series resistance. This bus
                                                                 adjusts the driver source impedance to compensate for added series resistance on the USB.
                                                                 0x0 = source impedance is decreased by approximately 1.5 ohm.
                                                                 0x1 = design default.
                                                                 0x2 = source impedance is decreased by approximately 2 ohm.
                                                                 0x3 = source impedance is decreased by approximately 4 ohm.

                                                                 Any setting other than the default can result in source-impedance variation across
                                                                 process, voltage, and temperature conditions that does not meet USB 2.0 specification
                                                                 limits. If this bus is not used, leave it at the default setting. */
		uint64_t tx_rise_tune                : 2;  /**< R/W - High-speed transmitter rise-/fall-time adjustment. Adjusts the rise/fall times of the
                                                                 high-speed waveform. A positive binary bit setting change results in a -4% incremental
                                                                 change in the high-speed rise/fall time. A negative binary bit setting change results in a
                                                                 +4% incremental change in the high-speed rise/fall time. */
		uint64_t tx_vref_tune                : 4;  /**< R/W - High-speed DC voltage-level adjustment. Adjusts the high-speed DC level voltage.
                                                                 A positive binary-bit-setting change results in a +1.25% incremental change in high-speed
                                                                 DC voltage level, while a negative binary-bit-setting change results in a -1.25%
                                                                 incremental change in high-speed DC voltage level.

                                                                 The default bit setting is intended to create a HighSpeed transmit
                                                                 DC level of approximately 400mV. */
		uint64_t reserved_4_31               : 28;
		uint64_t vatest_enable               : 2;  /**< R/W - Analog test-pin select. Enables analog test voltages to be placed on the ID0 pin.
                                                                 0x0 = test functionality disabled.
                                                                 0x1 = test functionality enabled.
                                                                 0x2, 0x3 = reserved, invalid settings.

                                                                 See also the PHY databook for details on how to select which analog test voltage. */
		uint64_t loopback_enable             : 1;  /**< R/W - Places the high-speed PHY in loopback mode, which concurrently enables high-speed receive
                                                                 and transmit logic. */
		uint64_t atereset                    : 1;  /**< R/W - Per-PHY ATE reset. When the USB core is powered up (not in suspend mode), an automatic
                                                                 tester can use this to disable PHYCLOCK and FREECLK, then re-enable them with an aligned
                                                                 phase.
                                                                 0 = PHYCLOCK and FREECLK are available within a specific period after ATERESET is
                                                                 deasserted.
                                                                 1 = PHYCLOCK and FREECLK outputs are disabled. */
#else
		uint64_t atereset                    : 1;
		uint64_t loopback_enable             : 1;
		uint64_t vatest_enable               : 2;
		uint64_t reserved_4_31               : 28;
		uint64_t tx_vref_tune                : 4;
		uint64_t tx_rise_tune                : 2;
		uint64_t tx_res_tune                 : 2;
		uint64_t tx_preemp_pulse_tune        : 1;
		uint64_t reserved_41_41              : 1;
		uint64_t tx_preemp_amp_tune          : 2;
		uint64_t tx_hs_xv_tune               : 2;
		uint64_t reserved_46_47              : 2;
		uint64_t tx_fsls_tune                : 4;
		uint64_t sq_rx_tune                  : 3;
		uint64_t comp_dis_tune               : 3;
		uint64_t reserved_58_63              : 6;
#endif
	} s;
	/* struct bdk_usbhx_uctl_portx_cfg_hs_s cn88xx; */
	/* struct bdk_usbhx_uctl_portx_cfg_hs_s cn88xxp1; */
} bdk_usbhx_uctl_portx_cfg_hs_t;

static inline uint64_t BDK_USBHX_UCTL_PORTX_CFG_HS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_PORTX_CFG_HS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000100050ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_PORTX_CFG_HS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_PORTX_CFG_HS(...) bdk_usbhx_uctl_portx_cfg_hs_t
#define bustype_BDK_USBHX_UCTL_PORTX_CFG_HS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_PORTX_CFG_HS(p1,p2) (p1)
#define arguments_BDK_USBHX_UCTL_PORTX_CFG_HS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UCTL_PORTX_CFG_HS(...) "USBHX_UCTL_PORTX_CFG_HS"


/**
 * NCB - usbh#_uctl_port#_cfg_ss
 *
 * This register controls configuration and test controls for the SS port 0 PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 *
 * INTERNAL: All these settings are for high-speed functionality, connect on DVDD power domain.
 */
typedef union bdk_usbhx_uctl_portx_cfg_ss {
	uint64_t u;
	struct bdk_usbhx_uctl_portx_cfg_ss_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t tx_vboost_lvl               : 3;  /**< R/W - TX voltage-boost level. Sets the boosted transmit launch amplitude (mVppd). The default
                                                                 bit setting is intended to set the launch amplitude to approximately 1,008 mVppd. A
                                                                 single, positive binary bit setting change results in a +156 mVppd change in the TX launch
                                                                 amplitude.
                                                                 A single, negative binary bit setting change results in a -156 mVppd change in the TX
                                                                 launch amplitude. All settings more than one binary bit change should not be used.
                                                                 0x3 = 0.844 V launch amplitude.
                                                                 0x4 = 1.008 V launch amplitude.
                                                                 0x5 = 1.156 V launch amplitude.
                                                                 All others values are invalid. */
		uint64_t los_bias                    : 3;  /**< R/W - Loss-of-signal detector threshold-level control. A positive, binary bit setting change
                                                                 results in a +15 mVp incremental change in the LOS threshold.
                                                                 A negative binary bit setting change results in a -15 mVp incremental change in the LOS
                                                                 threshold. The 0x0 setting is reserved and must not be used. The default 0x5 setting
                                                                 corresponds to approximately 105 mVp.
                                                                 0x0 = invalid.
                                                                 0x1 = 45 mV.
                                                                 0x2 = 60 mV.
                                                                 0x3 = 75 mV.
                                                                 0x4 = 90 mV.
                                                                 0x5 = 105 mV (default).
                                                                 0x6 = 120 mV.
                                                                 0x7 = 135 mV. */
		uint64_t lane0_ext_pclk_req          : 1;  /**< R/W - When asserted, this signal enables the pipe0_pclk output regardless of power state (along
                                                                 with the associated increase in power consumption). You can use this input to enable
                                                                 pipe0_pclk in the P3 state without going through a complete boot sequence. */
		uint64_t lane0_tx2rx_loopbk          : 1;  /**< R/W - When asserted, data from TX predriver is looped back to RX slicers. LOS is bypassed and
                                                                 based on the tx0_en input so that rx0_los = !tx_data_en. */
		uint64_t reserved_42_55              : 14;
		uint64_t pcs_rx_los_mask_val         : 10; /**< R/W - Configurable loss-of-signal mask width. Sets the number of reference clock cycles to mask
                                                                 the incoming LFPS in U3 and U2 states. Masks the incoming LFPS for the number of reference
                                                                 clock cycles equal to the value of pcs_rx_los_mask_val\<9:0\>. This control filters out
                                                                 short, non-compliant LFPS glitches sent by a noncompliant host.

                                                                 For normal operation, set to a targeted mask interval of 10us (value = 10us / Tref_clk).
                                                                 If the USBH()_UCTL_CTL[REF_CLK_DIV2] is used, then
                                                                 (value = 10us / (2 * Tref_clk)). These equations are based on the SuperSpeed reference
                                                                 clock frequency. The value of PCS_RX_LOS_MASK_VAL should be as follows:

                                                                 \<pre\>
                                                                      Frequency   DIV2  LOS_MASK
                                                                      ---------    ---  --------
                                                                      200   MHz      1     0x3E8
                                                                      125   MHz      0     0x4E2
                                                                      104   MHz      0     0x410
                                                                      100   MHz      0     0x3E8
                                                                       96   MHz      0     0x3C0
                                                                       76.8 MHz      1     0x180
                                                                       52   MHz      0     0x208
                                                                       50   MHz      0     0x1F4
                                                                       48   MHz      0     0x1E0
                                                                       40   MHz      1     0x0C8
                                                                       38.4 MHz      0     0x180
                                                                       26   MHz      0     0x104
                                                                       25   MHz      0     0x0FA
                                                                       24   MHz      0     0x0F0
                                                                       20   MHz      0     0x0C8
                                                                       19.2 MHz      0     0x0C0
                                                                 \</pre\>

                                                                 Setting this bus to 0x0 disables masking. The value should be defined when the PHY is in
                                                                 reset. Changing this value during operation might disrupt normal operation of the link. */
		uint64_t pcs_tx_deemph_3p5db         : 6;  /**< R/W - Fine-tune transmitter driver deemphasis when set to 3.5db.
                                                                 This static value sets the TX driver deemphasis value when pipeP_tx_deemph[1:0] is set to
                                                                 0x1 (according to the PIPE3 specification). The values for transmit deemphasis are derived
                                                                 from the following equation:

                                                                 _ TX de-emphasis (db) = 20 * log_base_10((128 - 2 * pcs_tx_deemph)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
		uint64_t pcs_tx_deemph_6db           : 6;  /**< R/W - Fine-tune transmitter driver deemphasis when set to 6db.
                                                                 This static value sets the TX driver deemphasis value when pipeP_tx_deemph[1:0] is set to
                                                                 0x2 (according to the PIPE3 specification). This bus is provided for completeness and as a
                                                                 second potential launch amplitude. The values for transmit deemphasis are derived from the
                                                                 following equation:

                                                                 _ TX de-emphasis (db) = 20 * log_base_10((128 - 2 * pcs_tx_deemph)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
		uint64_t pcs_tx_swing_full           : 7;  /**< R/W - Launch amplitude of the transmitter. Sets the launch amplitude of the transmitter. The
                                                                 values for transmit amplitude are derived from the following equation:
                                                                 TX amplitude (V) = vptx * ((pcs_tx_swing_full + 1)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
		uint64_t lane0_tx_term_offset        : 5;  /**< R/W - Transmitter termination offset. Reserved, set to 0x0. */
		uint64_t reserved_6_7                : 2;
		uint64_t res_tune_ack                : 1;  /**< RO/H - Resistor tune acknowledge. While asserted, indicates a resistor tune is in progress. */
		uint64_t res_tune_req                : 1;  /**< R/W - Resistor tune request. The rising edge triggers a resistor tune request (if one is not
                                                                 already in progress). When asserted, RES_TUNE_ACK is asserted high until calibration of
                                                                 the termination impedance is complete.
                                                                 Tuning disrupts the normal flow of data; therefore, assert RES_TUNE_REQ only when the PHY
                                                                 is inactive. The PHY automatically performs a tune when coming out of PRST. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t res_tune_req                : 1;
		uint64_t res_tune_ack                : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t lane0_tx_term_offset        : 5;
		uint64_t pcs_tx_swing_full           : 7;
		uint64_t pcs_tx_deemph_6db           : 6;
		uint64_t pcs_tx_deemph_3p5db         : 6;
		uint64_t pcs_rx_los_mask_val         : 10;
		uint64_t reserved_42_55              : 14;
		uint64_t lane0_tx2rx_loopbk          : 1;
		uint64_t lane0_ext_pclk_req          : 1;
		uint64_t los_bias                    : 3;
		uint64_t tx_vboost_lvl               : 3;
#endif
	} s;
	/* struct bdk_usbhx_uctl_portx_cfg_ss_s cn88xx; */
	/* struct bdk_usbhx_uctl_portx_cfg_ss_s cn88xxp1; */
} bdk_usbhx_uctl_portx_cfg_ss_t;

static inline uint64_t BDK_USBHX_UCTL_PORTX_CFG_SS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_PORTX_CFG_SS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000100058ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_PORTX_CFG_SS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_PORTX_CFG_SS(...) bdk_usbhx_uctl_portx_cfg_ss_t
#define bustype_BDK_USBHX_UCTL_PORTX_CFG_SS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_PORTX_CFG_SS(p1,p2) (p1)
#define arguments_BDK_USBHX_UCTL_PORTX_CFG_SS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UCTL_PORTX_CFG_SS(...) "USBHX_UCTL_PORTX_CFG_SS"


/**
 * NCB - usbh#_uctl_port#_cr_dbg_cfg
 *
 * This register allows indirect access to the configuration and test controls for the port 0
 * PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 *
 * INTERNAL: (In body of HRM)
 * To access the PHY registers indirectly through the CR interface, the HCLK must be running,
 * UCTL_RST must be deasserted, and UPHY_RST must be deasserted. Software is responsible for
 * ensuring that only one indirect access is ongoing at a time.
 *
 * To read a PHY register via indirect CR interface:
 *   1. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the \<\<address\>\> of the register,
 *     * [CAP_ADDR], [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   2. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the \<\<address\>\> of the register,
 *     * [CAP_ADDR] field 0x1,
 *     * [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   3. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   4. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   5. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *   6. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [READ] field 0x1,
 *     * [DATA_IN], [CAP_ADDR], [CAP_DATA], and [WRITE] fields 0x0.
 *   7. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   8. Read UCTL_PORTn_CR_DBG_STATUS[DATA_OUT]. This is the \<\<read data\>\>.
 *   9. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   10. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *
 * To write a PHY register via indirect CR interface:
 *   1. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the \<\<address\>\> of the register,
 *     * [CAP_ADDR], [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   2. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the \<\<address\>\> of the register,
 *     * [CAP_ADDR] field 0x1,
 *     * [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   3. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   4. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   5. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *   6. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the \<\<write data\>\>,
 *     * [CAP_ADDR], [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   7. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the write data,
 *     * [CAP_DATA] field 0x1,
 *     * [CAP_ADDR], [READ], and [WRITE] fields 0x0.
 *   8. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   9. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   10. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *   11. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [WRITE] field 0x1,
 *     * [DATA_IN], [CAP_ADDR], and [READ] fields 0x0.
 *   12. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   13. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   14. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *
 * For partial writes, a read-modify write is required. Note that the CAP_ADDR steps (1-5)
 * do not have to be repeated until the address needs changed.
 */
typedef union bdk_usbhx_uctl_portx_cr_dbg_cfg {
	uint64_t u;
	struct bdk_usbhx_uctl_portx_cr_dbg_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t data_in                     : 16; /**< R/W - Address or data to be written to the CR interface. */
		uint64_t reserved_4_31               : 28;
		uint64_t cap_addr                    : 1;  /**< R/W - Rising edge triggers the DATA_IN field to be captured as the address. */
		uint64_t cap_data                    : 1;  /**< R/W - Rising edge triggers the DATA_IN field to be captured as the write data. */
		uint64_t read                        : 1;  /**< R/W - Rising edge triggers a register read operation of the captured address. */
		uint64_t write                       : 1;  /**< R/W - Rising edge triggers a register write operation of the captured address with the captured data. */
#else
		uint64_t write                       : 1;
		uint64_t read                        : 1;
		uint64_t cap_data                    : 1;
		uint64_t cap_addr                    : 1;
		uint64_t reserved_4_31               : 28;
		uint64_t data_in                     : 16;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_usbhx_uctl_portx_cr_dbg_cfg_s cn88xx; */
	/* struct bdk_usbhx_uctl_portx_cr_dbg_cfg_s cn88xxp1; */
} bdk_usbhx_uctl_portx_cr_dbg_cfg_t;

static inline uint64_t BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000100060ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_PORTX_CR_DBG_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(...) bdk_usbhx_uctl_portx_cr_dbg_cfg_t
#define bustype_BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(p1,p2) (p1)
#define arguments_BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UCTL_PORTX_CR_DBG_CFG(...) "USBHX_UCTL_PORTX_CR_DBG_CFG"


/**
 * NCB - usbh#_uctl_port#_cr_dbg_status
 *
 * This register allows indirect access to the configuration and test controls for the port 0
 * PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 */
typedef union bdk_usbhx_uctl_portx_cr_dbg_status {
	uint64_t u;
	struct bdk_usbhx_uctl_portx_cr_dbg_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t data_out                    : 16; /**< RO/H - Last data read from the CR interface. */
		uint64_t reserved_1_31               : 31;
		uint64_t ack                         : 1;  /**< RO/H - Acknowledge that the CAP_ADDR, CAP_DATA, READ, WRITE commands have completed. */
#else
		uint64_t ack                         : 1;
		uint64_t reserved_1_31               : 31;
		uint64_t data_out                    : 16;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_usbhx_uctl_portx_cr_dbg_status_s cn88xx; */
	/* struct bdk_usbhx_uctl_portx_cr_dbg_status_s cn88xxp1; */
} bdk_usbhx_uctl_portx_cr_dbg_status_t;

static inline uint64_t BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x0000868000100068ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(...) bdk_usbhx_uctl_portx_cr_dbg_status_t
#define bustype_BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(p1,p2) (p1)
#define arguments_BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_USBHX_UCTL_PORTX_CR_DBG_STATUS(...) "USBHX_UCTL_PORTX_CR_DBG_STATUS"


/**
 * NCB - usbh#_uctl_shim_cfg
 *
 * This register allows configuration of various shim (UCTL) features. The fields XS_NCB_OOB_*
 * are captured when there are no outstanding OOB errors indicated in INTSTAT and a new OOB error
 * arrives. The fields XS_BAD_DMA_* are captured when there are no outstanding DMA errors
 * indicated in INTSTAT and a new DMA error arrives.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 */
typedef union bdk_usbhx_uctl_shim_cfg {
	uint64_t u;
	struct bdk_usbhx_uctl_shim_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t xs_ncb_oob_wrn              : 1;  /**< RO/H - Read/write error log for out-of-bound UAHC register access.
                                                                 0 = read, 1 = write. */
		uint64_t reserved_60_62              : 3;
		uint64_t xs_ncb_oob_osrc             : 12; /**< RO/H - SRCID error log for out-of-bound UAHC register access. The NCB outbound SRCID for the OOB
                                                                 error.
                                                                 \<59:58\> = chipID.
                                                                 \<57\> = Request source: 0 = core, 1 = NCB-device.
                                                                 \<56:51\> = Core/NCB-device number. Note that for NCB devices, \<56\> is always 0.
                                                                 \<50:48\> = SubID. */
		uint64_t xm_bad_dma_wrn              : 1;  /**< RO/H - Read/write error log for bad DMA access from UAHC.
                                                                 0 = read error log, 1 = write error log */
		uint64_t reserved_44_46              : 3;
		uint64_t xm_bad_dma_type             : 4;  /**< RO/H - ErrType error log for bad DMA access from UAHC. Encodes the type of error encountered
                                                                 (error largest encoded value has priority). See UCTL_XM_BAD_DMA_TYPE_E. */
		uint64_t reserved_14_39              : 26;
		uint64_t dma_read_cmd                : 2;  /**< R/W - Selects the NCB read command used by DMA accesses. See UCTL_DMA_READ_CMD_E. */
		uint64_t reserved_11_11              : 1;
		uint64_t dma_write_cmd               : 1;  /**< R/W - Selects the NCB write command used by DMA accesses. See UCTL_DMA_WRITE_CMD_E. */
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
	/* struct bdk_usbhx_uctl_shim_cfg_s   cn88xx; */
	/* struct bdk_usbhx_uctl_shim_cfg_s   cn88xxp1; */
} bdk_usbhx_uctl_shim_cfg_t;

static inline uint64_t BDK_USBHX_UCTL_SHIM_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_SHIM_CFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680001000E8ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_SHIM_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_SHIM_CFG(...) bdk_usbhx_uctl_shim_cfg_t
#define bustype_BDK_USBHX_UCTL_SHIM_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_SHIM_CFG(p1) (p1)
#define arguments_BDK_USBHX_UCTL_SHIM_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_SHIM_CFG(...) "USBHX_UCTL_SHIM_CFG"


/**
 * NCB - usbh#_uctl_spare0
 *
 * This register is a spare register. This register can be reset by NCB reset.
 *
 */
typedef union bdk_usbhx_uctl_spare0 {
	uint64_t u;
	struct bdk_usbhx_uctl_spare0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_usbhx_uctl_spare0_s     cn88xx; */
	/* struct bdk_usbhx_uctl_spare0_s     cn88xxp1; */
} bdk_usbhx_uctl_spare0_t;

static inline uint64_t BDK_USBHX_UCTL_SPARE0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_SPARE0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000868000100010ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_SPARE0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_SPARE0(...) bdk_usbhx_uctl_spare0_t
#define bustype_BDK_USBHX_UCTL_SPARE0(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_SPARE0(p1) (p1)
#define arguments_BDK_USBHX_UCTL_SPARE0(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_SPARE0(...) "USBHX_UCTL_SPARE0"


/**
 * NCB - usbh#_uctl_spare1
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBH()_UCTL_CTL[UCTL_RST].
 */
typedef union bdk_usbhx_uctl_spare1 {
	uint64_t u;
	struct bdk_usbhx_uctl_spare1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_usbhx_uctl_spare1_s     cn88xx; */
	/* struct bdk_usbhx_uctl_spare1_s     cn88xxp1; */
} bdk_usbhx_uctl_spare1_t;

static inline uint64_t BDK_USBHX_UCTL_SPARE1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBHX_UCTL_SPARE1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x00008680001000F8ull + (param1 & 1) * 0x1000000000ull;
	csr_fatal("BDK_USBHX_UCTL_SPARE1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_USBHX_UCTL_SPARE1(...) bdk_usbhx_uctl_spare1_t
#define bustype_BDK_USBHX_UCTL_SPARE1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_USBHX_UCTL_SPARE1(p1) (p1)
#define arguments_BDK_USBHX_UCTL_SPARE1(p1) (p1),-1,-1,-1
#define basename_BDK_USBHX_UCTL_SPARE1(...) "USBHX_UCTL_SPARE1"

#endif /* __BDK_CSRS_USBH__ */
