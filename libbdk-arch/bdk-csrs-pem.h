#ifndef __BDK_CSRS_PEM__
#define __BDK_CSRS_PEM__
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
 * Cavium PEM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration PEM_INT_VEC_E
 *
 * PEM MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum pem_int_vec_e {
	PEM_INT_VEC_E_DBG_INFO = 0xd,
	PEM_INT_VEC_E_ERROR_AERI = 0x0,
	PEM_INT_VEC_E_ERROR_AERI_CLEAR = 0x1,
	PEM_INT_VEC_E_ERROR_PMEI = 0x2,
	PEM_INT_VEC_E_ERROR_PMEI_CLEAR = 0x3,
	PEM_INT_VEC_E_INTA = 0x4,
	PEM_INT_VEC_E_INTA_CLEAR = 0x5,
	PEM_INT_VEC_E_INTB = 0x6,
	PEM_INT_VEC_E_INTB_CLEAR = 0x7,
	PEM_INT_VEC_E_INTC = 0x8,
	PEM_INT_VEC_E_INTC_CLEAR = 0x9,
	PEM_INT_VEC_E_INTD = 0xa,
	PEM_INT_VEC_E_INTD_CLEAR = 0xb,
	PEM_INT_VEC_E_INT_SUM = 0xc,
	PEM_INT_VEC_E_ENUM_LAST = 0xe,
};



/**
 * RSL - pem#_bar1_index#
 *
 * This register contains the address index and control bits for access to memory ranges of BAR1.
 * The index is selected from the PCIe address depending on the programmed BAR-1 size.
 */
typedef union bdk_pemx_bar1_indexx {
	uint64_t u;
	struct bdk_pemx_bar1_indexx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_31_63              : 33;
		uint64_t addr_idx                    : 27; /**< R/W - Address index. Address bits [48:22] sent to L2C. */
		uint64_t ca                          : 1;  /**< R/W - Cached. Set to 1 when access is not to be cached in L2. */
		uint64_t reserved_1_2                : 2;
		uint64_t addr_v                      : 1;  /**< R/W - Address valid. Set to 1 when the selected address range is valid. */
#else
		uint64_t addr_v                      : 1;
		uint64_t reserved_1_2                : 2;
		uint64_t ca                          : 1;
		uint64_t addr_idx                    : 27;
		uint64_t reserved_31_63              : 33;
#endif
	} s;
	/* struct bdk_pemx_bar1_indexx_s      cn88xx; */
	/* struct bdk_pemx_bar1_indexx_s      cn88xxp1; */
} bdk_pemx_bar1_indexx_t;

static inline uint64_t BDK_PEMX_BAR1_INDEXX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR1_INDEXX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 <= 15)))
		return 0x000087E0C0000100ull + (param1 & 7) * 0x1000000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_PEMX_BAR1_INDEXX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_BAR1_INDEXX(...) bdk_pemx_bar1_indexx_t
#define bustype_BDK_PEMX_BAR1_INDEXX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_BAR1_INDEXX(p1,p2) (p1)
#define arguments_BDK_PEMX_BAR1_INDEXX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_PEMX_BAR1_INDEXX(...) "PEMX_BAR1_INDEXX"


/**
 * RSL - pem#_bar2_mask
 *
 * This register contains the mask pattern that is ANDed with the address from the PCIe core for
 * BAR2 hits.
 */
typedef union bdk_pemx_bar2_mask {
	uint64_t u;
	struct bdk_pemx_bar2_mask_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t mask                        : 45; /**< R/W - The value to be ANDED with the address sent to memory. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t mask                        : 45;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_pemx_bar2_mask_s        cn88xx; */
	/* struct bdk_pemx_bar2_mask_s        cn88xxp1; */
} bdk_pemx_bar2_mask_t;

static inline uint64_t BDK_PEMX_BAR2_MASK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR2_MASK(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C00000B0ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_BAR2_MASK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_BAR2_MASK(...) bdk_pemx_bar2_mask_t
#define bustype_BDK_PEMX_BAR2_MASK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_BAR2_MASK(p1) (p1)
#define arguments_BDK_PEMX_BAR2_MASK(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_BAR2_MASK(...) "PEMX_BAR2_MASK"


/**
 * RSL - pem#_bar_ctl
 *
 * This register contains control for BAR accesses.
 *
 */
typedef union bdk_pemx_bar_ctl {
	uint64_t u;
	struct bdk_pemx_bar_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t bar1_siz                    : 3;  /**< R/W - PCIe Port 0 Bar1 Size.
                                                                 0x0 = Reserved.
                                                                 0x1 = 64 MB.
                                                                 0x2 = 128 MB.
                                                                 0x3 = 256 MB.
                                                                 0x4 = 512 MB.
                                                                 0x5 = 1024 MB.
                                                                 0x6 = 2048 MB.
                                                                 0x7 = Reserved. */
		uint64_t bar2_enb                    : 1;  /**< R/W - When set to 1, BAR2 is enabled and will respond; when clear, BAR2 access will cause UR responses. */
		uint64_t reserved_1_2                : 2;
		uint64_t bar2_cax                    : 1;  /**< R/W - Value is XORed with PCIe address \<49\> to determine the L2 cache attribute. Not cached in
                                                                 L2 if XOR result is 1. */
#else
		uint64_t bar2_cax                    : 1;
		uint64_t reserved_1_2                : 2;
		uint64_t bar2_enb                    : 1;
		uint64_t bar1_siz                    : 3;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_pemx_bar_ctl_s          cn88xx; */
	/* struct bdk_pemx_bar_ctl_s          cn88xxp1; */
} bdk_pemx_bar_ctl_t;

static inline uint64_t BDK_PEMX_BAR_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BAR_CTL(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C00000A8ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_BAR_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_BAR_CTL(...) bdk_pemx_bar_ctl_t
#define bustype_BDK_PEMX_BAR_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_BAR_CTL(p1) (p1)
#define arguments_BDK_PEMX_BAR_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_BAR_CTL(...) "PEMX_BAR_CTL"


/**
 * RSL - pem#_bist_status
 *
 * This register contains results from BIST runs of PEM's memories.
 *
 */
typedef union bdk_pemx_bist_status {
	uint64_t u;
	struct bdk_pemx_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_26_63              : 38;
		uint64_t retryc                      : 1;  /**< RO - Retry buffer memory C. */
		uint64_t sot                         : 1;  /**< RO - Start of transfer memory. */
		uint64_t rqhdrb0                     : 1;  /**< RO - Rx queue header memory buffer 0. */
		uint64_t rqhdrb1                     : 1;  /**< RO - Rx queue header memory buffer 1. */
		uint64_t rqdatab0                    : 1;  /**< RO - Rx queue data buffer 0. */
		uint64_t rqdatab1                    : 1;  /**< RO - Rx queue data buffer 1. */
		uint64_t tlpan_d0                    : 1;  /**< RO - BIST Status for the tlp_n_afifo_data0. */
		uint64_t tlpan_d1                    : 1;  /**< RO - BIST Status for the tlp_n_afifo_data1. */
		uint64_t tlpan_ctl                   : 1;  /**< RO - BIST Status for the tlp_n_afifo_ctl. */
		uint64_t tlpap_d0                    : 1;  /**< RO - BIST Status for the tlp_p_afifo_data0. */
		uint64_t tlpap_d1                    : 1;  /**< RO - BIST Status for the tlp_p_afifo_data1. */
		uint64_t tlpap_ctl                   : 1;  /**< RO - BIST Status for the tlp_p_afifo_ctl. */
		uint64_t tlpac_d0                    : 1;  /**< RO - BIST Status for the tlp_c_afifo_data0. */
		uint64_t tlpac_d1                    : 1;  /**< RO - BIST Status for the tlp_c_afifo_data1. */
		uint64_t tlpac_ctl                   : 1;  /**< RO - BIST Status for the tlp_c_afifo_ctl. */
		uint64_t peai_p2e                    : 1;  /**< RO - BIST Status for the peai__pesc_fifo. */
		uint64_t tlpn_d0                     : 1;  /**< RO - BIST Status for the tlp_n_fifo_data0. */
		uint64_t tlpn_d1                     : 1;  /**< RO - BIST Status for the tlp_n_fifo_data1. */
		uint64_t tlpn_ctl                    : 1;  /**< RO - BIST Status for the tlp_n_fifo_ctl. */
		uint64_t tlpp_d0                     : 1;  /**< RO - BIST Status for the tlp_p_fifo_data0. */
		uint64_t tlpp_d1                     : 1;  /**< RO - BIST Status for the tlp_p_fifo_data1. */
		uint64_t tlpp_ctl                    : 1;  /**< RO - BIST Status for the tlp_p_fifo_ctl. */
		uint64_t tlpc_d0                     : 1;  /**< RO - BIST Status for the tlp_c_fifo_data0. */
		uint64_t tlpc_d1                     : 1;  /**< RO - BIST Status for the tlp_c_fifo_data1. */
		uint64_t tlpc_ctl                    : 1;  /**< RO - BIST Status for the tlp_c_fifo_ctl. */
		uint64_t m2s                         : 1;  /**< RO - BIST Status for the m2s_fifo. */
#else
		uint64_t m2s                         : 1;
		uint64_t tlpc_ctl                    : 1;
		uint64_t tlpc_d1                     : 1;
		uint64_t tlpc_d0                     : 1;
		uint64_t tlpp_ctl                    : 1;
		uint64_t tlpp_d1                     : 1;
		uint64_t tlpp_d0                     : 1;
		uint64_t tlpn_ctl                    : 1;
		uint64_t tlpn_d1                     : 1;
		uint64_t tlpn_d0                     : 1;
		uint64_t peai_p2e                    : 1;
		uint64_t tlpac_ctl                   : 1;
		uint64_t tlpac_d1                    : 1;
		uint64_t tlpac_d0                    : 1;
		uint64_t tlpap_ctl                   : 1;
		uint64_t tlpap_d1                    : 1;
		uint64_t tlpap_d0                    : 1;
		uint64_t tlpan_ctl                   : 1;
		uint64_t tlpan_d1                    : 1;
		uint64_t tlpan_d0                    : 1;
		uint64_t rqdatab1                    : 1;
		uint64_t rqdatab0                    : 1;
		uint64_t rqhdrb1                     : 1;
		uint64_t rqhdrb0                     : 1;
		uint64_t sot                         : 1;
		uint64_t retryc                      : 1;
		uint64_t reserved_26_63              : 38;
#endif
	} s;
	/* struct bdk_pemx_bist_status_s      cn88xx; */
	/* struct bdk_pemx_bist_status_s      cn88xxp1; */
} bdk_pemx_bist_status_t;

static inline uint64_t BDK_PEMX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000468ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_BIST_STATUS(...) bdk_pemx_bist_status_t
#define bustype_BDK_PEMX_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_BIST_STATUS(p1) (p1)
#define arguments_BDK_PEMX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_BIST_STATUS(...) "PEMX_BIST_STATUS"


/**
 * RSL - pem#_cfg
 *
 * Configuration of the PCIe Application.
 *
 */
typedef union bdk_pemx_cfg {
	uint64_t u;
	struct bdk_pemx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t laneswap                    : 1;  /**< R/W/H - Determines lane swapping. When set, lane swapping is
                                                                 performed to/from the SerDes. When clear, no lane swapping is performed. */
		uint64_t lanes8                      : 1;  /**< R/W/H - Determines the number of lanes.
                                                                 When set, the PEM is configured for a maximum of 8 lanes. When clear, the PEM is
                                                                 configured for a maximum of 4 lanes. This value is used to set the maximum link width
                                                                 field in the core's link capabilities register (CFG031) to indicate the maximum number of
                                                                 lanes supported. Note that less lanes than the specified maximum can be configured for use
                                                                 via the core's link control register (CFG032) negotiated link width field. */
		uint64_t reserved_2_2                : 1;
		uint64_t md                          : 2;  /**< R/W/H - Determines the speed.
                                                                 0x0 = Gen1 speed.
                                                                 0x1 = Gen2 speed.
                                                                 0x2 = Gen3 speed.
                                                                 0x3 = Gen3 speed. */
#else
		uint64_t md                          : 2;
		uint64_t reserved_2_2                : 1;
		uint64_t lanes8                      : 1;
		uint64_t laneswap                    : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_pemx_cfg_s              cn88xx; */
	/* struct bdk_pemx_cfg_s              cn88xxp1; */
} bdk_pemx_cfg_t;

static inline uint64_t BDK_PEMX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000410ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CFG(...) bdk_pemx_cfg_t
#define bustype_BDK_PEMX_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CFG(p1) (p1)
#define arguments_BDK_PEMX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CFG(...) "PEMX_CFG"


/**
 * RSL - pem#_cfg_rd
 *
 * This register allows read access to the configuration in the PCIe core.
 *
 */
typedef union bdk_pemx_cfg_rd {
	uint64_t u;
	struct bdk_pemx_cfg_rd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 32; /**< R/W/H - Data. */
		uint64_t addr                        : 32; /**< R/W/H - Address to read. A write to this register starts a read operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 \<11:0\> The offset of the PCIe core CFG register being accessed. */
#else
		uint64_t addr                        : 32;
		uint64_t data                        : 32;
#endif
	} s;
	/* struct bdk_pemx_cfg_rd_s           cn88xx; */
	/* struct bdk_pemx_cfg_rd_s           cn88xxp1; */
} bdk_pemx_cfg_rd_t;

static inline uint64_t BDK_PEMX_CFG_RD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG_RD(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000030ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CFG_RD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CFG_RD(...) bdk_pemx_cfg_rd_t
#define bustype_BDK_PEMX_CFG_RD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CFG_RD(p1) (p1)
#define arguments_BDK_PEMX_CFG_RD(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CFG_RD(...) "PEMX_CFG_RD"


/**
 * RSL - pem#_cfg_wr
 *
 * This register allows write access to the configuration in the PCIe core.
 *
 */
typedef union bdk_pemx_cfg_wr {
	uint64_t u;
	struct bdk_pemx_cfg_wr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 32; /**< R/W/H - Data to write. A write to this register starts a write operation. */
		uint64_t addr                        : 32; /**< R/W/H - Address to write. A write to this register starts a write operation.
                                                                 Following are the sub-fields of the ADDR field.

                                                                 \<31\>   When set, asserts dbi_cs2 at PCIe core.
                                                                 \<11:0\> The offset of the PCIe core CFG register being accessed. */
#else
		uint64_t addr                        : 32;
		uint64_t data                        : 32;
#endif
	} s;
	/* struct bdk_pemx_cfg_wr_s           cn88xx; */
	/* struct bdk_pemx_cfg_wr_s           cn88xxp1; */
} bdk_pemx_cfg_wr_t;

static inline uint64_t BDK_PEMX_CFG_WR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CFG_WR(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000028ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CFG_WR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CFG_WR(...) bdk_pemx_cfg_wr_t
#define bustype_BDK_PEMX_CFG_WR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CFG_WR(p1) (p1)
#define arguments_BDK_PEMX_CFG_WR(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CFG_WR(...) "PEMX_CFG_WR"


/**
 * RSL - pem#_clk_en
 *
 * This register contains the clock enable for CSCLK and PCE_CLK.
 *
 */
typedef union bdk_pemx_clk_en {
	uint64_t u;
	struct bdk_pemx_clk_en_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t pceclk_gate                 : 1;  /**< R/W/H - When set, PCE_CLK is gated off. When clear, PCE_CLK is enabled. */
		uint64_t csclk_gate                  : 1;  /**< R/W/H - When set, CSCLK is gated off. When clear, CSCLK is enabled. */
#else
		uint64_t csclk_gate                  : 1;
		uint64_t pceclk_gate                 : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_pemx_clk_en_s           cn88xx; */
	/* struct bdk_pemx_clk_en_s           cn88xxp1; */
} bdk_pemx_clk_en_t;

static inline uint64_t BDK_PEMX_CLK_EN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CLK_EN(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000400ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CLK_EN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CLK_EN(...) bdk_pemx_clk_en_t
#define bustype_BDK_PEMX_CLK_EN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CLK_EN(p1) (p1)
#define arguments_BDK_PEMX_CLK_EN(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CLK_EN(...) "PEMX_CLK_EN"


/**
 * RSL - pem#_cpl_lut_valid
 *
 * This register specifies the bit set for an outstanding tag read.
 *
 */
typedef union bdk_pemx_cpl_lut_valid {
	uint64_t u;
	struct bdk_pemx_cpl_lut_valid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t tag                         : 64; /**< RO/H - Bit vector set corresponds to an outstanding tag. */
#else
		uint64_t tag                         : 64;
#endif
	} s;
	/* struct bdk_pemx_cpl_lut_valid_s    cn88xx; */
	/* struct bdk_pemx_cpl_lut_valid_s    cn88xxp1; */
} bdk_pemx_cpl_lut_valid_t;

static inline uint64_t BDK_PEMX_CPL_LUT_VALID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CPL_LUT_VALID(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000098ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CPL_LUT_VALID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CPL_LUT_VALID(...) bdk_pemx_cpl_lut_valid_t
#define bustype_BDK_PEMX_CPL_LUT_VALID(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CPL_LUT_VALID(p1) (p1)
#define arguments_BDK_PEMX_CPL_LUT_VALID(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CPL_LUT_VALID(...) "PEMX_CPL_LUT_VALID"


/**
 * RSL - pem#_ctl_status
 *
 * This is a general control and status register of the PEM.
 *
 */
typedef union bdk_pemx_ctl_status {
	uint64_t u;
	struct bdk_pemx_ctl_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t rd_flt                      : 1;  /**< RO - Read fault.

                                                                   0 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and non-fault.
                                                                       This is compatible with CN88XX pass 1.0.
                                                                   1 = A PCIe non-config read which is terminated by PCIe with an error (UR, etc) will
                                                                       return to the NCB/cores all-ones and fault. In the case of a read by a core,
                                                                       this fault will cause a synchronous external abort in the core.

                                                                 Config reads which are terminated by PCIe with an error (UR, etc), or config reads
                                                                 when the PEM is disabled or link is down, will return to the NCB/cores all-ones and
                                                                 non-fault regardless of this bit. */
		uint64_t inv_dpar                    : 1;  /**< R/W - Invert the generated parity to be written into the most significant data queue buffer RAM
                                                                 block to force a parity error when it is later read. */
		uint64_t reserved_48_49              : 2;
		uint64_t auto_sd                     : 1;  /**< RO/H - Link hardware autonomous speed disable. */
		uint64_t dnum                        : 5;  /**< RO/H - Primary bus device number. */
		uint64_t pbus                        : 8;  /**< RO/H - Primary bus number. */
		uint64_t reserved_32_33              : 2;
		uint64_t cfg_rtry                    : 16; /**< R/W - The time in units of 0x10000 coprocessor-clocks, during which retry completions to
                                                                 configuration
                                                                 reads will result in PCIE retries, but after which they shall result in a response error
                                                                 to the SLI and no retries. A value of 0 disables retries and treats a CPL Retry as a CPL
                                                                 UR.
                                                                 When non-zero, only one CFG RD may be issued until either successful completion or CPL UR. */
		uint64_t reserved_12_15              : 4;
		uint64_t pm_xtoff                    : 1;  /**< R/W/H - When written with one, a single cycle pulse is sent to the PCIe core pm_xmt_turnoff port. RC mode. */
		uint64_t reserved_6_10               : 5;
		uint64_t dly_one                     : 1;  /**< R/W/H - When set the output client state machines will wait one cycle before starting a new TLP out. */
		uint64_t lnk_enb                     : 1;  /**< R/W - When set, the link is enabled; when clear (0) the link is disabled. This bit only is
                                                                 active when in RC mode. */
		uint64_t ro_ctlp                     : 1;  /**< R/W - When set, C-TLPs that have the RO bit set will not wait for P-TLPs that are normally sent first. */
		uint64_t fast_lm                     : 1;  /**< R/W - When set, forces fast link mode. */
		uint64_t inv_ecrc                    : 1;  /**< R/W - When set, causes the LSB of the ECRC to be inverted. */
		uint64_t inv_lcrc                    : 1;  /**< R/W - When set, causes the LSB of the LCRC to be inverted. */
#else
		uint64_t inv_lcrc                    : 1;
		uint64_t inv_ecrc                    : 1;
		uint64_t fast_lm                     : 1;
		uint64_t ro_ctlp                     : 1;
		uint64_t lnk_enb                     : 1;
		uint64_t dly_one                     : 1;
		uint64_t reserved_6_10               : 5;
		uint64_t pm_xtoff                    : 1;
		uint64_t reserved_12_15              : 4;
		uint64_t cfg_rtry                    : 16;
		uint64_t reserved_32_33              : 2;
		uint64_t pbus                        : 8;
		uint64_t dnum                        : 5;
		uint64_t auto_sd                     : 1;
		uint64_t reserved_48_49              : 2;
		uint64_t inv_dpar                    : 1;
		uint64_t rd_flt                      : 1;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_pemx_ctl_status_s       cn88xx; */
	/* struct bdk_pemx_ctl_status_s       cn88xxp1; */
} bdk_pemx_ctl_status_t;

static inline uint64_t BDK_PEMX_CTL_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CTL_STATUS(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CTL_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CTL_STATUS(...) bdk_pemx_ctl_status_t
#define bustype_BDK_PEMX_CTL_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CTL_STATUS(p1) (p1)
#define arguments_BDK_PEMX_CTL_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CTL_STATUS(...) "PEMX_CTL_STATUS"


/**
 * RSL - pem#_ctl_status2
 *
 * This register contains additional general control and status of the PEM.
 *
 */
typedef union bdk_pemx_ctl_status2 {
	uint64_t u;
	struct bdk_pemx_ctl_status2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t no_fwd_prg                  : 16; /**< R/W - The time * 0x10000 in core clocks to wait for the TLP FIFOs to be able to unload an entry.
                                                                 If there is no forward progress, such that the timeout occurs, credits are returned to the
                                                                 SLI and an interrupt (if enabled) is asserted. Any more TLPs received are dropped on the
                                                                 floor and the credits associated with those TLPs are returned as well. Note that 0xFFFF is
                                                                 a reserved value that will put the PEM in the 'forward progress stopped' state
                                                                 immediately. This state holds until a MAC reset is received. */
#else
		uint64_t no_fwd_prg                  : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_pemx_ctl_status2_s      cn88xx; */
	/* struct bdk_pemx_ctl_status2_s      cn88xxp1; */
} bdk_pemx_ctl_status2_t;

static inline uint64_t BDK_PEMX_CTL_STATUS2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_CTL_STATUS2(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_CTL_STATUS2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_CTL_STATUS2(...) bdk_pemx_ctl_status2_t
#define bustype_BDK_PEMX_CTL_STATUS2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_CTL_STATUS2(p1) (p1)
#define arguments_BDK_PEMX_CTL_STATUS2(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_CTL_STATUS2(...) "PEMX_CTL_STATUS2"


/**
 * RSL - pem#_dbg_ena_w1c
 */
typedef union bdk_pemx_dbg_ena_w1c {
	uint64_t u;
	struct bdk_pemx_dbg_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t qhdr_b1_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 double bit error. */
		uint64_t qhdr_b1_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 single bit error. */
		uint64_t qhdr_b0_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 double bit error. */
		uint64_t qhdr_b0_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 single bit error. */
		uint64_t rtry_dbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM double bit error. */
		uint64_t rtry_sbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM single bit error. */
		uint64_t c_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control double bit error. */
		uint64_t c_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control single bit error. */
		uint64_t c_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 double bit error. */
		uint64_t c_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 single bit error. */
		uint64_t c_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 double bit error. */
		uint64_t c_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 single bit error. */
		uint64_t n_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control double bit error. */
		uint64_t n_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control single bit error. */
		uint64_t n_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 double bit error. */
		uint64_t n_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 single bit error. */
		uint64_t n_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 double bit error. */
		uint64_t n_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 single bit error. */
		uint64_t p_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control double bit error. */
		uint64_t p_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control single bit error. */
		uint64_t p_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 double bit error. */
		uint64_t p_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 single bit error. */
		uint64_t p_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 double bit error. */
		uint64_t p_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 single bit error. */
		uint64_t datq_pe                     : 1;  /**< R/W1C/H - Detected a data queue RAM parity error. */
		uint64_t lofp                        : 1;  /**< R/W1C/H - Lack of forward progress at TLP FIFOs timeout occurred. */
		uint64_t ecrc_e                      : 1;  /**< R/W1C/H - Received an ECRC error. */
		uint64_t rawwpp                      : 1;  /**< R/W1C/H - Received a write with poisoned payload. radm_rcvd_wreq_poisoned */
		uint64_t racpp                       : 1;  /**< R/W1C/H - Received a completion with poisoned payload. radm_rcvd_cpl_poisoned */
		uint64_t ramtlp                      : 1;  /**< R/W1C/H - Received a malformed TLP. radm_mlf_tlp_err */
		uint64_t rarwdns                     : 1;  /**< R/W1C/H - Received a request which device does not support. radm_rcvd_ur_req */
		uint64_t caar                        : 1;  /**< R/W1C/H - Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
		uint64_t racca                       : 1;  /**< R/W1C/H - Received a completion with CA status. radm_rcvd_cpl_ca */
		uint64_t racur                       : 1;  /**< R/W1C/H - Received a completion with UR status. radm_rcvd_cpl_ur */
		uint64_t rauc                        : 1;  /**< R/W1C/H - Received an unexpected completion. radm_unexp_cpl_err */
		uint64_t rqo                         : 1;  /**< R/W1C/H - Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. radm_qoverflow */
		uint64_t fcuv                        : 1;  /**< R/W1C/H - Flow control update violation. (opt. checks) int_xadm_fc_prot_err */
		uint64_t rpe                         : 1;  /**< R/W1C/H - PHY reported an 8B/10B decode error (RxStatus = 3b100) or disparity error (RxStatus =
                                                                 3b111), the signal rmlh_rcvd_err will be asserted. rmlh_rcvd_err */
		uint64_t fcpvwt                      : 1;  /**< R/W1C/H - Flow control protocol violation (watchdog timer). rtlh_fc_prot_err */
		uint64_t dpeoosd                     : 1;  /**< R/W1C/H - DLLP protocol error (out of sequence DLLP). rdlh_prot_err */
		uint64_t rtwdle                      : 1;  /**< R/W1C/H - Received TLP with datalink layer error. rdlh_bad_tlp_err */
		uint64_t rdwdle                      : 1;  /**< R/W1C/H - Received DLLP with datalink layer error. rdlh_bad_dllp_err */
		uint64_t mre                         : 1;  /**< R/W1C/H - Maximum number of retries exceeded. xdlh_replay_num_rlover_err */
		uint64_t rte                         : 1;  /**< R/W1C/H - Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load. xdlh_replay_timeout_err */
		uint64_t acto                        : 1;  /**< R/W1C/H - A completion timeout occurred. pedc_radm_cpl_timeout */
		uint64_t rvdm                        : 1;  /**< R/W1C/H - Received vendor-defined message. pedc_radm_vendor_msg */
		uint64_t reserved_10_10              : 1;
		uint64_t rptamrc                     : 1;  /**< R/W1C/H - Received PME turnoff acknowledge message (RC mode only). pedc_radm_pm_to_ack */
		uint64_t rpmerc                      : 1;  /**< R/W1C/H - Received PME message (RC mode only). pedc_radm_pm_pme */
		uint64_t rfemrc                      : 1;  /**< R/W1C/H - Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. pedc_radm_fatal_err */
		uint64_t rnfemrc                     : 1;  /**< R/W1C/H - Received nonfatal error message (RC mode only). pedc_radm_nonfatal_err */
		uint64_t rcemrc                      : 1;  /**< R/W1C/H - Received correctable error message (RC mode only). pedc_radm_correctable_err */
		uint64_t rpoison                     : 1;  /**< R/W1C/H - Received poisoned TLP. pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv */
		uint64_t recrce                      : 1;  /**< R/W1C/H - Received ECRC error. pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot */
		uint64_t rtlplle                     : 1;  /**< R/W1C/H - Received TLP has link layer error. pedc_radm_trgt1_dllp_abort & pedc__radm_trgt1_eot */
		uint64_t rtlpmal                     : 1;  /**< R/W1C/H - Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot */
		uint64_t spoison                     : 1;  /**< R/W1C/H - Poisoned TLP sent. peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else
		uint64_t spoison                     : 1;
		uint64_t rtlpmal                     : 1;
		uint64_t rtlplle                     : 1;
		uint64_t recrce                      : 1;
		uint64_t rpoison                     : 1;
		uint64_t rcemrc                      : 1;
		uint64_t rnfemrc                     : 1;
		uint64_t rfemrc                      : 1;
		uint64_t rpmerc                      : 1;
		uint64_t rptamrc                     : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rvdm                        : 1;
		uint64_t acto                        : 1;
		uint64_t rte                         : 1;
		uint64_t mre                         : 1;
		uint64_t rdwdle                      : 1;
		uint64_t rtwdle                      : 1;
		uint64_t dpeoosd                     : 1;
		uint64_t fcpvwt                      : 1;
		uint64_t rpe                         : 1;
		uint64_t fcuv                        : 1;
		uint64_t rqo                         : 1;
		uint64_t rauc                        : 1;
		uint64_t racur                       : 1;
		uint64_t racca                       : 1;
		uint64_t caar                        : 1;
		uint64_t rarwdns                     : 1;
		uint64_t ramtlp                      : 1;
		uint64_t racpp                       : 1;
		uint64_t rawwpp                      : 1;
		uint64_t ecrc_e                      : 1;
		uint64_t lofp                        : 1;
		uint64_t datq_pe                     : 1;
		uint64_t p_d0_sbe                    : 1;
		uint64_t p_d0_dbe                    : 1;
		uint64_t p_d1_sbe                    : 1;
		uint64_t p_d1_dbe                    : 1;
		uint64_t p_c_sbe                     : 1;
		uint64_t p_c_dbe                     : 1;
		uint64_t n_d0_sbe                    : 1;
		uint64_t n_d0_dbe                    : 1;
		uint64_t n_d1_sbe                    : 1;
		uint64_t n_d1_dbe                    : 1;
		uint64_t n_c_sbe                     : 1;
		uint64_t n_c_dbe                     : 1;
		uint64_t c_d0_sbe                    : 1;
		uint64_t c_d0_dbe                    : 1;
		uint64_t c_d1_sbe                    : 1;
		uint64_t c_d1_dbe                    : 1;
		uint64_t c_c_sbe                     : 1;
		uint64_t c_c_dbe                     : 1;
		uint64_t rtry_sbe                    : 1;
		uint64_t rtry_dbe                    : 1;
		uint64_t qhdr_b0_sbe                 : 1;
		uint64_t qhdr_b0_dbe                 : 1;
		uint64_t qhdr_b1_sbe                 : 1;
		uint64_t qhdr_b1_dbe                 : 1;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_pemx_dbg_ena_w1c_s      cn88xx; */
	/* struct bdk_pemx_dbg_ena_w1c_s      cn88xxp1; */
} bdk_pemx_dbg_ena_w1c_t;

static inline uint64_t BDK_PEMX_DBG_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000458ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_DBG_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_DBG_ENA_W1C(...) bdk_pemx_dbg_ena_w1c_t
#define bustype_BDK_PEMX_DBG_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_DBG_ENA_W1C(p1) (p1)
#define arguments_BDK_PEMX_DBG_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_DBG_ENA_W1C(...) "PEMX_DBG_ENA_W1C"


/**
 * RSL - pem#_dbg_ena_w1s
 */
typedef union bdk_pemx_dbg_ena_w1s {
	uint64_t u;
	struct bdk_pemx_dbg_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t qhdr_b1_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 double bit error. */
		uint64_t qhdr_b1_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 single bit error. */
		uint64_t qhdr_b0_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 double bit error. */
		uint64_t qhdr_b0_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 single bit error. */
		uint64_t rtry_dbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM double bit error. */
		uint64_t rtry_sbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM single bit error. */
		uint64_t c_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control double bit error. */
		uint64_t c_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control single bit error. */
		uint64_t c_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 double bit error. */
		uint64_t c_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 single bit error. */
		uint64_t c_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 double bit error. */
		uint64_t c_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 single bit error. */
		uint64_t n_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control double bit error. */
		uint64_t n_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control single bit error. */
		uint64_t n_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 double bit error. */
		uint64_t n_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 single bit error. */
		uint64_t n_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 double bit error. */
		uint64_t n_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 single bit error. */
		uint64_t p_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control double bit error. */
		uint64_t p_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control single bit error. */
		uint64_t p_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 double bit error. */
		uint64_t p_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 single bit error. */
		uint64_t p_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 double bit error. */
		uint64_t p_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 single bit error. */
		uint64_t datq_pe                     : 1;  /**< R/W1C/H - Detected a data queue RAM parity error. */
		uint64_t lofp                        : 1;  /**< R/W1C/H - Lack of forward progress at TLP FIFOs timeout occurred. */
		uint64_t ecrc_e                      : 1;  /**< R/W1C/H - Received an ECRC error. */
		uint64_t rawwpp                      : 1;  /**< R/W1C/H - Received a write with poisoned payload. radm_rcvd_wreq_poisoned */
		uint64_t racpp                       : 1;  /**< R/W1C/H - Received a completion with poisoned payload. radm_rcvd_cpl_poisoned */
		uint64_t ramtlp                      : 1;  /**< R/W1C/H - Received a malformed TLP. radm_mlf_tlp_err */
		uint64_t rarwdns                     : 1;  /**< R/W1C/H - Received a request which device does not support. radm_rcvd_ur_req */
		uint64_t caar                        : 1;  /**< R/W1C/H - Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
		uint64_t racca                       : 1;  /**< R/W1C/H - Received a completion with CA status. radm_rcvd_cpl_ca */
		uint64_t racur                       : 1;  /**< R/W1C/H - Received a completion with UR status. radm_rcvd_cpl_ur */
		uint64_t rauc                        : 1;  /**< R/W1C/H - Received an unexpected completion. radm_unexp_cpl_err */
		uint64_t rqo                         : 1;  /**< R/W1C/H - Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. radm_qoverflow */
		uint64_t fcuv                        : 1;  /**< R/W1C/H - Flow control update violation. (opt. checks) int_xadm_fc_prot_err */
		uint64_t rpe                         : 1;  /**< R/W1C/H - PHY reported an 8B/10B decode error (RxStatus = 3b100) or disparity error (RxStatus =
                                                                 3b111), the signal rmlh_rcvd_err will be asserted. rmlh_rcvd_err */
		uint64_t fcpvwt                      : 1;  /**< R/W1C/H - Flow control protocol violation (watchdog timer). rtlh_fc_prot_err */
		uint64_t dpeoosd                     : 1;  /**< R/W1C/H - DLLP protocol error (out of sequence DLLP). rdlh_prot_err */
		uint64_t rtwdle                      : 1;  /**< R/W1C/H - Received TLP with datalink layer error. rdlh_bad_tlp_err */
		uint64_t rdwdle                      : 1;  /**< R/W1C/H - Received DLLP with datalink layer error. rdlh_bad_dllp_err */
		uint64_t mre                         : 1;  /**< R/W1C/H - Maximum number of retries exceeded. xdlh_replay_num_rlover_err */
		uint64_t rte                         : 1;  /**< R/W1C/H - Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load. xdlh_replay_timeout_err */
		uint64_t acto                        : 1;  /**< R/W1C/H - A completion timeout occurred. pedc_radm_cpl_timeout */
		uint64_t rvdm                        : 1;  /**< R/W1C/H - Received vendor-defined message. pedc_radm_vendor_msg */
		uint64_t reserved_10_10              : 1;
		uint64_t rptamrc                     : 1;  /**< R/W1C/H - Received PME turnoff acknowledge message (RC mode only). pedc_radm_pm_to_ack */
		uint64_t rpmerc                      : 1;  /**< R/W1C/H - Received PME message (RC mode only). pedc_radm_pm_pme */
		uint64_t rfemrc                      : 1;  /**< R/W1C/H - Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. pedc_radm_fatal_err */
		uint64_t rnfemrc                     : 1;  /**< R/W1C/H - Received nonfatal error message (RC mode only). pedc_radm_nonfatal_err */
		uint64_t rcemrc                      : 1;  /**< R/W1C/H - Received correctable error message (RC mode only). pedc_radm_correctable_err */
		uint64_t rpoison                     : 1;  /**< R/W1C/H - Received poisoned TLP. pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv */
		uint64_t recrce                      : 1;  /**< R/W1C/H - Received ECRC error. pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot */
		uint64_t rtlplle                     : 1;  /**< R/W1C/H - Received TLP has link layer error. pedc_radm_trgt1_dllp_abort & pedc__radm_trgt1_eot */
		uint64_t rtlpmal                     : 1;  /**< R/W1C/H - Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot */
		uint64_t spoison                     : 1;  /**< R/W1C/H - Poisoned TLP sent. peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else
		uint64_t spoison                     : 1;
		uint64_t rtlpmal                     : 1;
		uint64_t rtlplle                     : 1;
		uint64_t recrce                      : 1;
		uint64_t rpoison                     : 1;
		uint64_t rcemrc                      : 1;
		uint64_t rnfemrc                     : 1;
		uint64_t rfemrc                      : 1;
		uint64_t rpmerc                      : 1;
		uint64_t rptamrc                     : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rvdm                        : 1;
		uint64_t acto                        : 1;
		uint64_t rte                         : 1;
		uint64_t mre                         : 1;
		uint64_t rdwdle                      : 1;
		uint64_t rtwdle                      : 1;
		uint64_t dpeoosd                     : 1;
		uint64_t fcpvwt                      : 1;
		uint64_t rpe                         : 1;
		uint64_t fcuv                        : 1;
		uint64_t rqo                         : 1;
		uint64_t rauc                        : 1;
		uint64_t racur                       : 1;
		uint64_t racca                       : 1;
		uint64_t caar                        : 1;
		uint64_t rarwdns                     : 1;
		uint64_t ramtlp                      : 1;
		uint64_t racpp                       : 1;
		uint64_t rawwpp                      : 1;
		uint64_t ecrc_e                      : 1;
		uint64_t lofp                        : 1;
		uint64_t datq_pe                     : 1;
		uint64_t p_d0_sbe                    : 1;
		uint64_t p_d0_dbe                    : 1;
		uint64_t p_d1_sbe                    : 1;
		uint64_t p_d1_dbe                    : 1;
		uint64_t p_c_sbe                     : 1;
		uint64_t p_c_dbe                     : 1;
		uint64_t n_d0_sbe                    : 1;
		uint64_t n_d0_dbe                    : 1;
		uint64_t n_d1_sbe                    : 1;
		uint64_t n_d1_dbe                    : 1;
		uint64_t n_c_sbe                     : 1;
		uint64_t n_c_dbe                     : 1;
		uint64_t c_d0_sbe                    : 1;
		uint64_t c_d0_dbe                    : 1;
		uint64_t c_d1_sbe                    : 1;
		uint64_t c_d1_dbe                    : 1;
		uint64_t c_c_sbe                     : 1;
		uint64_t c_c_dbe                     : 1;
		uint64_t rtry_sbe                    : 1;
		uint64_t rtry_dbe                    : 1;
		uint64_t qhdr_b0_sbe                 : 1;
		uint64_t qhdr_b0_dbe                 : 1;
		uint64_t qhdr_b1_sbe                 : 1;
		uint64_t qhdr_b1_dbe                 : 1;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_pemx_dbg_ena_w1s_s      cn88xx; */
	/* struct bdk_pemx_dbg_ena_w1s_s      cn88xxp1; */
} bdk_pemx_dbg_ena_w1s_t;

static inline uint64_t BDK_PEMX_DBG_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000460ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_DBG_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_DBG_ENA_W1S(...) bdk_pemx_dbg_ena_w1s_t
#define bustype_BDK_PEMX_DBG_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_DBG_ENA_W1S(p1) (p1)
#define arguments_BDK_PEMX_DBG_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_DBG_ENA_W1S(...) "PEMX_DBG_ENA_W1S"


/**
 * RSL - pem#_dbg_info
 *
 * This is a debug information register of the PEM.
 *
 */
typedef union bdk_pemx_dbg_info {
	uint64_t u;
	struct bdk_pemx_dbg_info_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t qhdr_b1_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 double bit error. */
		uint64_t qhdr_b1_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 single bit error. */
		uint64_t qhdr_b0_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 double bit error. */
		uint64_t qhdr_b0_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 single bit error. */
		uint64_t rtry_dbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM double bit error. */
		uint64_t rtry_sbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM single bit error. */
		uint64_t c_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control double bit error. */
		uint64_t c_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control single bit error. */
		uint64_t c_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 double bit error. */
		uint64_t c_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 single bit error. */
		uint64_t c_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 double bit error. */
		uint64_t c_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 single bit error. */
		uint64_t n_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control double bit error. */
		uint64_t n_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control single bit error. */
		uint64_t n_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 double bit error. */
		uint64_t n_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 single bit error. */
		uint64_t n_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 double bit error. */
		uint64_t n_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 single bit error. */
		uint64_t p_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control double bit error. */
		uint64_t p_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control single bit error. */
		uint64_t p_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 double bit error. */
		uint64_t p_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 single bit error. */
		uint64_t p_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 double bit error. */
		uint64_t p_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 single bit error. */
		uint64_t datq_pe                     : 1;  /**< R/W1C/H - Detected a data queue RAM parity error. */
		uint64_t lofp                        : 1;  /**< R/W1C/H - Lack of forward progress at TLP FIFOs timeout occurred. */
		uint64_t ecrc_e                      : 1;  /**< R/W1C/H - Received an ECRC error. */
		uint64_t rawwpp                      : 1;  /**< R/W1C/H - Received a write with poisoned payload. radm_rcvd_wreq_poisoned */
		uint64_t racpp                       : 1;  /**< R/W1C/H - Received a completion with poisoned payload. radm_rcvd_cpl_poisoned */
		uint64_t ramtlp                      : 1;  /**< R/W1C/H - Received a malformed TLP. radm_mlf_tlp_err */
		uint64_t rarwdns                     : 1;  /**< R/W1C/H - Received a request which device does not support. radm_rcvd_ur_req */
		uint64_t caar                        : 1;  /**< R/W1C/H - Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
		uint64_t racca                       : 1;  /**< R/W1C/H - Received a completion with CA status. radm_rcvd_cpl_ca */
		uint64_t racur                       : 1;  /**< R/W1C/H - Received a completion with UR status. radm_rcvd_cpl_ur */
		uint64_t rauc                        : 1;  /**< R/W1C/H - Received an unexpected completion. radm_unexp_cpl_err */
		uint64_t rqo                         : 1;  /**< R/W1C/H - Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. radm_qoverflow */
		uint64_t fcuv                        : 1;  /**< R/W1C/H - Flow control update violation. (opt. checks) int_xadm_fc_prot_err */
		uint64_t rpe                         : 1;  /**< R/W1C/H - PHY reported an 8B/10B decode error (RxStatus = 3b100) or disparity error (RxStatus =
                                                                 3b111), the signal rmlh_rcvd_err will be asserted. rmlh_rcvd_err */
		uint64_t fcpvwt                      : 1;  /**< R/W1C/H - Flow control protocol violation (watchdog timer). rtlh_fc_prot_err */
		uint64_t dpeoosd                     : 1;  /**< R/W1C/H - DLLP protocol error (out of sequence DLLP). rdlh_prot_err */
		uint64_t rtwdle                      : 1;  /**< R/W1C/H - Received TLP with datalink layer error. rdlh_bad_tlp_err */
		uint64_t rdwdle                      : 1;  /**< R/W1C/H - Received DLLP with datalink layer error. rdlh_bad_dllp_err */
		uint64_t mre                         : 1;  /**< R/W1C/H - Maximum number of retries exceeded. xdlh_replay_num_rlover_err */
		uint64_t rte                         : 1;  /**< R/W1C/H - Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load. xdlh_replay_timeout_err */
		uint64_t acto                        : 1;  /**< R/W1C/H - A completion timeout occurred. pedc_radm_cpl_timeout */
		uint64_t rvdm                        : 1;  /**< R/W1C/H - Received vendor-defined message. pedc_radm_vendor_msg */
		uint64_t reserved_10_10              : 1;
		uint64_t rptamrc                     : 1;  /**< R/W1C/H - Received PME turnoff acknowledge message (RC mode only). pedc_radm_pm_to_ack */
		uint64_t rpmerc                      : 1;  /**< R/W1C/H - Received PME message (RC mode only). pedc_radm_pm_pme */
		uint64_t rfemrc                      : 1;  /**< R/W1C/H - Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. pedc_radm_fatal_err */
		uint64_t rnfemrc                     : 1;  /**< R/W1C/H - Received nonfatal error message (RC mode only). pedc_radm_nonfatal_err */
		uint64_t rcemrc                      : 1;  /**< R/W1C/H - Received correctable error message (RC mode only). pedc_radm_correctable_err */
		uint64_t rpoison                     : 1;  /**< R/W1C/H - Received poisoned TLP. pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv */
		uint64_t recrce                      : 1;  /**< R/W1C/H - Received ECRC error. pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot */
		uint64_t rtlplle                     : 1;  /**< R/W1C/H - Received TLP has link layer error. pedc_radm_trgt1_dllp_abort & pedc__radm_trgt1_eot */
		uint64_t rtlpmal                     : 1;  /**< R/W1C/H - Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot */
		uint64_t spoison                     : 1;  /**< R/W1C/H - Poisoned TLP sent. peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else
		uint64_t spoison                     : 1;
		uint64_t rtlpmal                     : 1;
		uint64_t rtlplle                     : 1;
		uint64_t recrce                      : 1;
		uint64_t rpoison                     : 1;
		uint64_t rcemrc                      : 1;
		uint64_t rnfemrc                     : 1;
		uint64_t rfemrc                      : 1;
		uint64_t rpmerc                      : 1;
		uint64_t rptamrc                     : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rvdm                        : 1;
		uint64_t acto                        : 1;
		uint64_t rte                         : 1;
		uint64_t mre                         : 1;
		uint64_t rdwdle                      : 1;
		uint64_t rtwdle                      : 1;
		uint64_t dpeoosd                     : 1;
		uint64_t fcpvwt                      : 1;
		uint64_t rpe                         : 1;
		uint64_t fcuv                        : 1;
		uint64_t rqo                         : 1;
		uint64_t rauc                        : 1;
		uint64_t racur                       : 1;
		uint64_t racca                       : 1;
		uint64_t caar                        : 1;
		uint64_t rarwdns                     : 1;
		uint64_t ramtlp                      : 1;
		uint64_t racpp                       : 1;
		uint64_t rawwpp                      : 1;
		uint64_t ecrc_e                      : 1;
		uint64_t lofp                        : 1;
		uint64_t datq_pe                     : 1;
		uint64_t p_d0_sbe                    : 1;
		uint64_t p_d0_dbe                    : 1;
		uint64_t p_d1_sbe                    : 1;
		uint64_t p_d1_dbe                    : 1;
		uint64_t p_c_sbe                     : 1;
		uint64_t p_c_dbe                     : 1;
		uint64_t n_d0_sbe                    : 1;
		uint64_t n_d0_dbe                    : 1;
		uint64_t n_d1_sbe                    : 1;
		uint64_t n_d1_dbe                    : 1;
		uint64_t n_c_sbe                     : 1;
		uint64_t n_c_dbe                     : 1;
		uint64_t c_d0_sbe                    : 1;
		uint64_t c_d0_dbe                    : 1;
		uint64_t c_d1_sbe                    : 1;
		uint64_t c_d1_dbe                    : 1;
		uint64_t c_c_sbe                     : 1;
		uint64_t c_c_dbe                     : 1;
		uint64_t rtry_sbe                    : 1;
		uint64_t rtry_dbe                    : 1;
		uint64_t qhdr_b0_sbe                 : 1;
		uint64_t qhdr_b0_dbe                 : 1;
		uint64_t qhdr_b1_sbe                 : 1;
		uint64_t qhdr_b1_dbe                 : 1;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_pemx_dbg_info_s         cn88xx; */
	/* struct bdk_pemx_dbg_info_s         cn88xxp1; */
} bdk_pemx_dbg_info_t;

static inline uint64_t BDK_PEMX_DBG_INFO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_INFO(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000448ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_DBG_INFO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_DBG_INFO(...) bdk_pemx_dbg_info_t
#define bustype_BDK_PEMX_DBG_INFO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_DBG_INFO(p1) (p1)
#define arguments_BDK_PEMX_DBG_INFO(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_DBG_INFO(...) "PEMX_DBG_INFO"


/**
 * RSL - pem#_dbg_info_w1s
 */
typedef union bdk_pemx_dbg_info_w1s {
	uint64_t u;
	struct bdk_pemx_dbg_info_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t qhdr_b1_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 double bit error. */
		uint64_t qhdr_b1_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank1 single bit error. */
		uint64_t qhdr_b0_dbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 double bit error. */
		uint64_t qhdr_b0_sbe                 : 1;  /**< R/W1C/H - Detected a core header queue bank0 single bit error. */
		uint64_t rtry_dbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM double bit error. */
		uint64_t rtry_sbe                    : 1;  /**< R/W1C/H - Detected a core retry RAM single bit error. */
		uint64_t c_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control double bit error. */
		uint64_t c_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO control single bit error. */
		uint64_t c_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 double bit error. */
		uint64_t c_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data1 single bit error. */
		uint64_t c_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 double bit error. */
		uint64_t c_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP CPL FIFO data0 single bit error. */
		uint64_t n_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control double bit error. */
		uint64_t n_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP NP FIFO control single bit error. */
		uint64_t n_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 double bit error. */
		uint64_t n_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data1 single bit error. */
		uint64_t n_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 double bit error. */
		uint64_t n_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP NP FIFO data0 single bit error. */
		uint64_t p_c_dbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control double bit error. */
		uint64_t p_c_sbe                     : 1;  /**< R/W1C/H - Detected a TLP posted FIFO control single bit error. */
		uint64_t p_d1_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 double bit error. */
		uint64_t p_d1_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data1 single bit error. */
		uint64_t p_d0_dbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 double bit error. */
		uint64_t p_d0_sbe                    : 1;  /**< R/W1C/H - Detected a TLP posted FIFO data0 single bit error. */
		uint64_t datq_pe                     : 1;  /**< R/W1C/H - Detected a data queue RAM parity error. */
		uint64_t lofp                        : 1;  /**< R/W1C/H - Lack of forward progress at TLP FIFOs timeout occurred. */
		uint64_t ecrc_e                      : 1;  /**< R/W1C/H - Received an ECRC error. */
		uint64_t rawwpp                      : 1;  /**< R/W1C/H - Received a write with poisoned payload. radm_rcvd_wreq_poisoned */
		uint64_t racpp                       : 1;  /**< R/W1C/H - Received a completion with poisoned payload. radm_rcvd_cpl_poisoned */
		uint64_t ramtlp                      : 1;  /**< R/W1C/H - Received a malformed TLP. radm_mlf_tlp_err */
		uint64_t rarwdns                     : 1;  /**< R/W1C/H - Received a request which device does not support. radm_rcvd_ur_req */
		uint64_t caar                        : 1;  /**< R/W1C/H - Completer aborted a request. This bit is never set because CNXXXX does not generate
                                                                 completer aborts. */
		uint64_t racca                       : 1;  /**< R/W1C/H - Received a completion with CA status. radm_rcvd_cpl_ca */
		uint64_t racur                       : 1;  /**< R/W1C/H - Received a completion with UR status. radm_rcvd_cpl_ur */
		uint64_t rauc                        : 1;  /**< R/W1C/H - Received an unexpected completion. radm_unexp_cpl_err */
		uint64_t rqo                         : 1;  /**< R/W1C/H - Receive queue overflow. Normally happens only when flow control advertisements are
                                                                 ignored. radm_qoverflow */
		uint64_t fcuv                        : 1;  /**< R/W1C/H - Flow control update violation. (opt. checks) int_xadm_fc_prot_err */
		uint64_t rpe                         : 1;  /**< R/W1C/H - PHY reported an 8B/10B decode error (RxStatus = 3b100) or disparity error (RxStatus =
                                                                 3b111), the signal rmlh_rcvd_err will be asserted. rmlh_rcvd_err */
		uint64_t fcpvwt                      : 1;  /**< R/W1C/H - Flow control protocol violation (watchdog timer). rtlh_fc_prot_err */
		uint64_t dpeoosd                     : 1;  /**< R/W1C/H - DLLP protocol error (out of sequence DLLP). rdlh_prot_err */
		uint64_t rtwdle                      : 1;  /**< R/W1C/H - Received TLP with datalink layer error. rdlh_bad_tlp_err */
		uint64_t rdwdle                      : 1;  /**< R/W1C/H - Received DLLP with datalink layer error. rdlh_bad_dllp_err */
		uint64_t mre                         : 1;  /**< R/W1C/H - Maximum number of retries exceeded. xdlh_replay_num_rlover_err */
		uint64_t rte                         : 1;  /**< R/W1C/H - Replay timer expired. This bit is set when the REPLAY_TIMER expires in the PCIe core. The
                                                                 probability of this bit being set increases with the traffic load. xdlh_replay_timeout_err */
		uint64_t acto                        : 1;  /**< R/W1C/H - A completion timeout occurred. pedc_radm_cpl_timeout */
		uint64_t rvdm                        : 1;  /**< R/W1C/H - Received vendor-defined message. pedc_radm_vendor_msg */
		uint64_t reserved_10_10              : 1;
		uint64_t rptamrc                     : 1;  /**< R/W1C/H - Received PME turnoff acknowledge message (RC mode only). pedc_radm_pm_to_ack */
		uint64_t rpmerc                      : 1;  /**< R/W1C/H - Received PME message (RC mode only). pedc_radm_pm_pme */
		uint64_t rfemrc                      : 1;  /**< R/W1C/H - Received fatal-error message (RC mode only). This bit is set when a message with ERR_FATAL
                                                                 is set. pedc_radm_fatal_err */
		uint64_t rnfemrc                     : 1;  /**< R/W1C/H - Received nonfatal error message (RC mode only). pedc_radm_nonfatal_err */
		uint64_t rcemrc                      : 1;  /**< R/W1C/H - Received correctable error message (RC mode only). pedc_radm_correctable_err */
		uint64_t rpoison                     : 1;  /**< R/W1C/H - Received poisoned TLP. pedc__radm_trgt1_poisoned & pedc__radm_trgt1_hv */
		uint64_t recrce                      : 1;  /**< R/W1C/H - Received ECRC error. pedc_radm_trgt1_ecrc_err & pedc__radm_trgt1_eot */
		uint64_t rtlplle                     : 1;  /**< R/W1C/H - Received TLP has link layer error. pedc_radm_trgt1_dllp_abort & pedc__radm_trgt1_eot */
		uint64_t rtlpmal                     : 1;  /**< R/W1C/H - Received TLP is malformed or a message. If the core receives a MSG (or Vendor Message) or
                                                                 if a received AtomicOp viloates address/length rules, this bit is set as well.
                                                                 pedc_radm_trgt1_tlp_abort & pedc__radm_trgt1_eot */
		uint64_t spoison                     : 1;  /**< R/W1C/H - Poisoned TLP sent. peai__client0_tlp_ep & peai__client0_tlp_hv or
                                                                 peai__client1_tlp_ep & peai__client1_tlp_hv (atomic_op). */
#else
		uint64_t spoison                     : 1;
		uint64_t rtlpmal                     : 1;
		uint64_t rtlplle                     : 1;
		uint64_t recrce                      : 1;
		uint64_t rpoison                     : 1;
		uint64_t rcemrc                      : 1;
		uint64_t rnfemrc                     : 1;
		uint64_t rfemrc                      : 1;
		uint64_t rpmerc                      : 1;
		uint64_t rptamrc                     : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rvdm                        : 1;
		uint64_t acto                        : 1;
		uint64_t rte                         : 1;
		uint64_t mre                         : 1;
		uint64_t rdwdle                      : 1;
		uint64_t rtwdle                      : 1;
		uint64_t dpeoosd                     : 1;
		uint64_t fcpvwt                      : 1;
		uint64_t rpe                         : 1;
		uint64_t fcuv                        : 1;
		uint64_t rqo                         : 1;
		uint64_t rauc                        : 1;
		uint64_t racur                       : 1;
		uint64_t racca                       : 1;
		uint64_t caar                        : 1;
		uint64_t rarwdns                     : 1;
		uint64_t ramtlp                      : 1;
		uint64_t racpp                       : 1;
		uint64_t rawwpp                      : 1;
		uint64_t ecrc_e                      : 1;
		uint64_t lofp                        : 1;
		uint64_t datq_pe                     : 1;
		uint64_t p_d0_sbe                    : 1;
		uint64_t p_d0_dbe                    : 1;
		uint64_t p_d1_sbe                    : 1;
		uint64_t p_d1_dbe                    : 1;
		uint64_t p_c_sbe                     : 1;
		uint64_t p_c_dbe                     : 1;
		uint64_t n_d0_sbe                    : 1;
		uint64_t n_d0_dbe                    : 1;
		uint64_t n_d1_sbe                    : 1;
		uint64_t n_d1_dbe                    : 1;
		uint64_t n_c_sbe                     : 1;
		uint64_t n_c_dbe                     : 1;
		uint64_t c_d0_sbe                    : 1;
		uint64_t c_d0_dbe                    : 1;
		uint64_t c_d1_sbe                    : 1;
		uint64_t c_d1_dbe                    : 1;
		uint64_t c_c_sbe                     : 1;
		uint64_t c_c_dbe                     : 1;
		uint64_t rtry_sbe                    : 1;
		uint64_t rtry_dbe                    : 1;
		uint64_t qhdr_b0_sbe                 : 1;
		uint64_t qhdr_b0_dbe                 : 1;
		uint64_t qhdr_b1_sbe                 : 1;
		uint64_t qhdr_b1_dbe                 : 1;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_pemx_dbg_info_w1s_s     cn88xx; */
	/* struct bdk_pemx_dbg_info_w1s_s     cn88xxp1; */
} bdk_pemx_dbg_info_w1s_t;

static inline uint64_t BDK_PEMX_DBG_INFO_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DBG_INFO_W1S(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000450ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_DBG_INFO_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_DBG_INFO_W1S(...) bdk_pemx_dbg_info_w1s_t
#define bustype_BDK_PEMX_DBG_INFO_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_DBG_INFO_W1S(p1) (p1)
#define arguments_BDK_PEMX_DBG_INFO_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_DBG_INFO_W1S(...) "PEMX_DBG_INFO_W1S"


/**
 * RSL - pem#_debug
 *
 * This register contains status of level interrupts for debugging purposes.
 *
 */
typedef union bdk_pemx_debug {
	uint64_t u;
	struct bdk_pemx_debug_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t intval                      : 7;  /**< RO/H - Status of INTX, PMEI, and AERI interrupts. */
#else
		uint64_t intval                      : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_pemx_debug_s            cn88xx; */
	/* struct bdk_pemx_debug_s            cn88xxp1; */
} bdk_pemx_debug_t;

static inline uint64_t BDK_PEMX_DEBUG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DEBUG(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000480ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_DEBUG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_DEBUG(...) bdk_pemx_debug_t
#define bustype_BDK_PEMX_DEBUG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_DEBUG(p1) (p1)
#define arguments_BDK_PEMX_DEBUG(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_DEBUG(...) "PEMX_DEBUG"


/**
 * RSL - pem#_diag_status
 *
 * This register contains selection control for the core diagnostic bus.
 *
 */
typedef union bdk_pemx_diag_status {
	uint64_t u;
	struct bdk_pemx_diag_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t pwrdwn                      : 3;  /**< RO/H - Current mac_phy_powerdown state. */
		uint64_t pm_dst                      : 3;  /**< RO/H - Current power management DSTATE. */
		uint64_t pm_stat                     : 1;  /**< RO - Power management status. */
		uint64_t pm_en                       : 1;  /**< RO - Power management event enable. */
		uint64_t aux_en                      : 1;  /**< RO - Auxiliary power enable. Always read as zero as auxiliary power is not supported. */
#else
		uint64_t aux_en                      : 1;
		uint64_t pm_en                       : 1;
		uint64_t pm_stat                     : 1;
		uint64_t pm_dst                      : 3;
		uint64_t pwrdwn                      : 3;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	struct bdk_pemx_diag_status_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_9               : 55;
		uint64_t pwrdwn                      : 3;  /**< RO/H - Current mac_phy_powerdown state. */
		uint64_t pm_dst                      : 3;  /**< RO/H - Current power management DSTATE. */
		uint64_t pm_stat                     : 1;  /**< RO - Power management status. */
		uint64_t pm_en                       : 1;  /**< RO - Power management event enable. */
		uint64_t aux_en                      : 1;  /**< RO - Auxiliary power enable. Always read as zero as auxiliary power is not supported. */
#else
		uint64_t aux_en                      : 1;
		uint64_t pm_en                       : 1;
		uint64_t pm_stat                     : 1;
		uint64_t pm_dst                      : 3;
		uint64_t pwrdwn                      : 3;
		uint64_t reserved_63_9               : 55;
#endif
	} cn88xx;
	struct bdk_pemx_diag_status_cn88xx    cn88xxp1;
} bdk_pemx_diag_status_t;

static inline uint64_t BDK_PEMX_DIAG_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_DIAG_STATUS(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000020ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_DIAG_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_DIAG_STATUS(...) bdk_pemx_diag_status_t
#define bustype_BDK_PEMX_DIAG_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_DIAG_STATUS(p1) (p1)
#define arguments_BDK_PEMX_DIAG_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_DIAG_STATUS(...) "PEMX_DIAG_STATUS"


/**
 * RSL - pem#_ecc_ena
 *
 * Contains enables for TLP FIFO ECC RAMs.
 *
 */
typedef union bdk_pemx_ecc_ena {
	uint64_t u;
	struct bdk_pemx_ecc_ena_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_35_63              : 29;
		uint64_t qhdr_b1_ena                 : 1;  /**< R/W - ECC enable for Core's Q HDR Bank1 RAM. */
		uint64_t qhdr_b0_ena                 : 1;  /**< R/W - ECC enable for Core's Q HDR Bank0 RAM. */
		uint64_t rtry_ena                    : 1;  /**< R/W - ECC enable for Core's RETRY RA. */
		uint64_t reserved_9_31               : 23;
		uint64_t c_c_ena                     : 1;  /**< R/W - ECC enable for TLP CPL control FIFO. */
		uint64_t c_d1_ena                    : 1;  /**< R/W - ECC enable for TLP CPL data1 FIFO. */
		uint64_t c_d0_ena                    : 1;  /**< R/W - ECC enable for TLP CPL data0 FIFO. */
		uint64_t n_c_ena                     : 1;  /**< R/W - ECC enable for TLP NP control FIFO. */
		uint64_t n_d1_ena                    : 1;  /**< R/W - ECC enable for TLP NP data1 FIFO. */
		uint64_t n_d0_ena                    : 1;  /**< R/W - ECC enable for TLP NP data0 FIFO. */
		uint64_t p_c_ena                     : 1;  /**< R/W - ECC enable for TLP posted control FIFO. */
		uint64_t p_d1_ena                    : 1;  /**< R/W - ECC enable for TLP posted data1 FIFO. */
		uint64_t p_d0_ena                    : 1;  /**< R/W - ECC enable for TLP posted data0 FIFO. */
#else
		uint64_t p_d0_ena                    : 1;
		uint64_t p_d1_ena                    : 1;
		uint64_t p_c_ena                     : 1;
		uint64_t n_d0_ena                    : 1;
		uint64_t n_d1_ena                    : 1;
		uint64_t n_c_ena                     : 1;
		uint64_t c_d0_ena                    : 1;
		uint64_t c_d1_ena                    : 1;
		uint64_t c_c_ena                     : 1;
		uint64_t reserved_9_31               : 23;
		uint64_t rtry_ena                    : 1;
		uint64_t qhdr_b0_ena                 : 1;
		uint64_t qhdr_b1_ena                 : 1;
		uint64_t reserved_35_63              : 29;
#endif
	} s;
	/* struct bdk_pemx_ecc_ena_s          cn88xx; */
	/* struct bdk_pemx_ecc_ena_s          cn88xxp1; */
} bdk_pemx_ecc_ena_t;

static inline uint64_t BDK_PEMX_ECC_ENA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECC_ENA(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000470ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_ECC_ENA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_ECC_ENA(...) bdk_pemx_ecc_ena_t
#define bustype_BDK_PEMX_ECC_ENA(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_ECC_ENA(p1) (p1)
#define arguments_BDK_PEMX_ECC_ENA(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_ECC_ENA(...) "PEMX_ECC_ENA"


/**
 * RSL - pem#_ecc_synd_ctrl
 *
 * This register contains syndrome control for TLP FIFO ECC RAMs.
 *
 */
typedef union bdk_pemx_ecc_synd_ctrl {
	uint64_t u;
	struct bdk_pemx_ecc_synd_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26;
		uint64_t qhdr_b1_syn                 : 2;  /**< R/W - Syndrome flip bits for Core's Q HDR Bank1 RAM. */
		uint64_t qhdr_b0_syn                 : 2;  /**< R/W - Syndrome flip bits for Core's Q HDR Bank0 RAM. */
		uint64_t rtry_syn                    : 2;  /**< R/W - Syndrome flip bits for Core's RETRY RAM. */
		uint64_t reserved_18_31              : 14;
		uint64_t c_c_syn                     : 2;  /**< R/W - Syndrome flip bits for TLP CPL control FIFO. */
		uint64_t c_d1_syn                    : 2;  /**< R/W - Syndrome flip bits for TLP CPL data1 FIFO. */
		uint64_t c_d0_syn                    : 2;  /**< R/W - Syndrome flip bits for TLP CPL data0 FIFO. */
		uint64_t n_c_syn                     : 2;  /**< R/W - Syndrome flip bits for TLP NP control FIFO. */
		uint64_t n_d1_syn                    : 2;  /**< R/W - Syndrome flip bits for TLP NP data1 FIFO. */
		uint64_t n_d0_syn                    : 2;  /**< R/W - Syndrome flip bits for TLP NP data0 FIFO. */
		uint64_t p_c_syn                     : 2;  /**< R/W - Syndrome flip bits for TLP posted control FIFO. */
		uint64_t p_d1_syn                    : 2;  /**< R/W - Syndrome flip bits for TLP posted data1 FIFO. */
		uint64_t p_d0_syn                    : 2;  /**< R/W - Syndrome flip bits for TLP posted data0 FIFO. */
#else
		uint64_t p_d0_syn                    : 2;
		uint64_t p_d1_syn                    : 2;
		uint64_t p_c_syn                     : 2;
		uint64_t n_d0_syn                    : 2;
		uint64_t n_d1_syn                    : 2;
		uint64_t n_c_syn                     : 2;
		uint64_t c_d0_syn                    : 2;
		uint64_t c_d1_syn                    : 2;
		uint64_t c_c_syn                     : 2;
		uint64_t reserved_18_31              : 14;
		uint64_t rtry_syn                    : 2;
		uint64_t qhdr_b0_syn                 : 2;
		uint64_t qhdr_b1_syn                 : 2;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
	/* struct bdk_pemx_ecc_synd_ctrl_s    cn88xx; */
	/* struct bdk_pemx_ecc_synd_ctrl_s    cn88xxp1; */
} bdk_pemx_ecc_synd_ctrl_t;

static inline uint64_t BDK_PEMX_ECC_SYND_CTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ECC_SYND_CTRL(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000478ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_ECC_SYND_CTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_ECC_SYND_CTRL(...) bdk_pemx_ecc_synd_ctrl_t
#define bustype_BDK_PEMX_ECC_SYND_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_ECC_SYND_CTRL(p1) (p1)
#define arguments_BDK_PEMX_ECC_SYND_CTRL(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_ECC_SYND_CTRL(...) "PEMX_ECC_SYND_CTRL"


/**
 * RSL - pem#_inb_read_credits
 *
 * This register contains the number of in-flight read operations from PCIe core to SLI.
 *
 */
typedef union bdk_pemx_inb_read_credits {
	uint64_t u;
	struct bdk_pemx_inb_read_credits_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t num                         : 7;  /**< R/W - The number of reads that may be in flight from the PCIe core to the SLI. Minimum number is
                                                                 2; maximum number is 64. */
#else
		uint64_t num                         : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_pemx_inb_read_credits_s cn88xx; */
	/* struct bdk_pemx_inb_read_credits_s cn88xxp1; */
} bdk_pemx_inb_read_credits_t;

static inline uint64_t BDK_PEMX_INB_READ_CREDITS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INB_READ_CREDITS(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C00000B8ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_INB_READ_CREDITS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_INB_READ_CREDITS(...) bdk_pemx_inb_read_credits_t
#define bustype_BDK_PEMX_INB_READ_CREDITS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_INB_READ_CREDITS(p1) (p1)
#define arguments_BDK_PEMX_INB_READ_CREDITS(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_INB_READ_CREDITS(...) "PEMX_INB_READ_CREDITS"


/**
 * RSL - pem#_int_ena_w1c
 */
typedef union bdk_pemx_int_ena_w1c {
	uint64_t u;
	struct bdk_pemx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t crs_dr                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were disabled. */
		uint64_t crs_er                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were enabled. */
		uint64_t rdlk                        : 1;  /**< R/W1C/H - Received read lock TLP. */
		uint64_t reserved_10_10              : 1;
		uint64_t un_bx                       : 1;  /**< R/W1C/H - Received N-TLP for unknown BAR. */
		uint64_t un_b2                       : 1;  /**< R/W1C/H - Received N-TLP for BAR2 when BAR2 is disabled. */
		uint64_t un_b1                       : 1;  /**< R/W1C/H - Received N-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t up_bx                       : 1;  /**< R/W1C/H - Received P-TLP for an unknown BAR. */
		uint64_t up_b2                       : 1;  /**< R/W1C/H - Received P-TLP for BAR2 when BAR2 is disabled. */
		uint64_t up_b1                       : 1;  /**< R/W1C/H - Received P-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t reserved_2_3                : 2;
		uint64_t se                          : 1;  /**< R/W1C/H - System error, RC mode only.  (cfg_sys_err_rc) */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t se                          : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t up_b1                       : 1;
		uint64_t up_b2                       : 1;
		uint64_t up_bx                       : 1;
		uint64_t un_b1                       : 1;
		uint64_t un_b2                       : 1;
		uint64_t un_bx                       : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rdlk                        : 1;
		uint64_t crs_er                      : 1;
		uint64_t crs_dr                      : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_pemx_int_ena_w1c_s      cn88xx; */
	/* struct bdk_pemx_int_ena_w1c_s      cn88xxp1; */
} bdk_pemx_int_ena_w1c_t;

static inline uint64_t BDK_PEMX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000438ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_INT_ENA_W1C(...) bdk_pemx_int_ena_w1c_t
#define bustype_BDK_PEMX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_PEMX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_INT_ENA_W1C(...) "PEMX_INT_ENA_W1C"


/**
 * RSL - pem#_int_ena_w1s
 */
typedef union bdk_pemx_int_ena_w1s {
	uint64_t u;
	struct bdk_pemx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t crs_dr                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were disabled. */
		uint64_t crs_er                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were enabled. */
		uint64_t rdlk                        : 1;  /**< R/W1C/H - Received read lock TLP. */
		uint64_t reserved_10_10              : 1;
		uint64_t un_bx                       : 1;  /**< R/W1C/H - Received N-TLP for unknown BAR. */
		uint64_t un_b2                       : 1;  /**< R/W1C/H - Received N-TLP for BAR2 when BAR2 is disabled. */
		uint64_t un_b1                       : 1;  /**< R/W1C/H - Received N-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t up_bx                       : 1;  /**< R/W1C/H - Received P-TLP for an unknown BAR. */
		uint64_t up_b2                       : 1;  /**< R/W1C/H - Received P-TLP for BAR2 when BAR2 is disabled. */
		uint64_t up_b1                       : 1;  /**< R/W1C/H - Received P-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t reserved_2_3                : 2;
		uint64_t se                          : 1;  /**< R/W1C/H - System error, RC mode only.  (cfg_sys_err_rc) */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t se                          : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t up_b1                       : 1;
		uint64_t up_b2                       : 1;
		uint64_t up_bx                       : 1;
		uint64_t un_b1                       : 1;
		uint64_t un_b2                       : 1;
		uint64_t un_bx                       : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rdlk                        : 1;
		uint64_t crs_er                      : 1;
		uint64_t crs_dr                      : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_pemx_int_ena_w1s_s      cn88xx; */
	/* struct bdk_pemx_int_ena_w1s_s      cn88xxp1; */
} bdk_pemx_int_ena_w1s_t;

static inline uint64_t BDK_PEMX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000440ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_INT_ENA_W1S(...) bdk_pemx_int_ena_w1s_t
#define bustype_BDK_PEMX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_PEMX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_INT_ENA_W1S(...) "PEMX_INT_ENA_W1S"


/**
 * RSL - pem#_int_sum
 *
 * This register contains the different interrupt summary bits of the PEM.
 *
 */
typedef union bdk_pemx_int_sum {
	uint64_t u;
	struct bdk_pemx_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t crs_dr                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were disabled. */
		uint64_t crs_er                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were enabled. */
		uint64_t rdlk                        : 1;  /**< R/W1C/H - Received read lock TLP. */
		uint64_t reserved_10_10              : 1;
		uint64_t un_bx                       : 1;  /**< R/W1C/H - Received N-TLP for unknown BAR. */
		uint64_t un_b2                       : 1;  /**< R/W1C/H - Received N-TLP for BAR2 when BAR2 is disabled. */
		uint64_t un_b1                       : 1;  /**< R/W1C/H - Received N-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t up_bx                       : 1;  /**< R/W1C/H - Received P-TLP for an unknown BAR. */
		uint64_t up_b2                       : 1;  /**< R/W1C/H - Received P-TLP for BAR2 when BAR2 is disabled. */
		uint64_t up_b1                       : 1;  /**< R/W1C/H - Received P-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t reserved_2_3                : 2;
		uint64_t se                          : 1;  /**< R/W1C/H - System error, RC mode only.  (cfg_sys_err_rc) */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t se                          : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t up_b1                       : 1;
		uint64_t up_b2                       : 1;
		uint64_t up_bx                       : 1;
		uint64_t un_b1                       : 1;
		uint64_t un_b2                       : 1;
		uint64_t un_bx                       : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rdlk                        : 1;
		uint64_t crs_er                      : 1;
		uint64_t crs_dr                      : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_pemx_int_sum_s          cn88xx; */
	/* struct bdk_pemx_int_sum_s          cn88xxp1; */
} bdk_pemx_int_sum_t;

static inline uint64_t BDK_PEMX_INT_SUM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_SUM(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000428ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_INT_SUM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_INT_SUM(...) bdk_pemx_int_sum_t
#define bustype_BDK_PEMX_INT_SUM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_INT_SUM(p1) (p1)
#define arguments_BDK_PEMX_INT_SUM(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_INT_SUM(...) "PEMX_INT_SUM"


/**
 * RSL - pem#_int_sum_w1s
 */
typedef union bdk_pemx_int_sum_w1s {
	uint64_t u;
	struct bdk_pemx_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t crs_dr                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were disabled. */
		uint64_t crs_er                      : 1;  /**< R/W1C/H - Had a CRS timeout when retries were enabled. */
		uint64_t rdlk                        : 1;  /**< R/W1C/H - Received read lock TLP. */
		uint64_t reserved_10_10              : 1;
		uint64_t un_bx                       : 1;  /**< R/W1C/H - Received N-TLP for unknown BAR. */
		uint64_t un_b2                       : 1;  /**< R/W1C/H - Received N-TLP for BAR2 when BAR2 is disabled. */
		uint64_t un_b1                       : 1;  /**< R/W1C/H - Received N-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t up_bx                       : 1;  /**< R/W1C/H - Received P-TLP for an unknown BAR. */
		uint64_t up_b2                       : 1;  /**< R/W1C/H - Received P-TLP for BAR2 when BAR2 is disabled. */
		uint64_t up_b1                       : 1;  /**< R/W1C/H - Received P-TLP for BAR1 when BAR1 index valid is not set. */
		uint64_t reserved_2_3                : 2;
		uint64_t se                          : 1;  /**< R/W1C/H - System error, RC mode only.  (cfg_sys_err_rc) */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t se                          : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t up_b1                       : 1;
		uint64_t up_b2                       : 1;
		uint64_t up_bx                       : 1;
		uint64_t un_b1                       : 1;
		uint64_t un_b2                       : 1;
		uint64_t un_bx                       : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t rdlk                        : 1;
		uint64_t crs_er                      : 1;
		uint64_t crs_dr                      : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_pemx_int_sum_w1s_s      cn88xx; */
	/* struct bdk_pemx_int_sum_w1s_s      cn88xxp1; */
} bdk_pemx_int_sum_w1s_t;

static inline uint64_t BDK_PEMX_INT_SUM_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_INT_SUM_W1S(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000430ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_INT_SUM_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_INT_SUM_W1S(...) bdk_pemx_int_sum_w1s_t
#define bustype_BDK_PEMX_INT_SUM_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_INT_SUM_W1S(p1) (p1)
#define arguments_BDK_PEMX_INT_SUM_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_INT_SUM_W1S(...) "PEMX_INT_SUM_W1S"


/**
 * RSL - pem#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the PEM_INT_VEC_E enumeration.
 *
 */
typedef union bdk_pemx_msix_pbax {
	uint64_t u;
	struct bdk_pemx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated PEM_MSIX_VEC()_CTL, enumerated by PEM_INT_VEC_E. Bits
                                                                 that have no associated PEM_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_pemx_msix_pbax_s        cn88xx; */
	/* struct bdk_pemx_msix_pbax_s        cn88xxp1; */
} bdk_pemx_msix_pbax_t;

static inline uint64_t BDK_PEMX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 == 0)))
		return 0x000087E0C0FF0000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_MSIX_PBAX(...) bdk_pemx_msix_pbax_t
#define bustype_BDK_PEMX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_PEMX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_PEMX_MSIX_PBAX(...) "PEMX_MSIX_PBAX"


/**
 * RSL - pem#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the PEM_INT_VEC_E enumeration.
 *
 */
typedef union bdk_pemx_msix_vecx_addr {
	uint64_t u;
	struct bdk_pemx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PEM()_MSIX_VEC()_ADDR, PEM()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of PEM()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_PEM(0..5)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_pemx_msix_vecx_addr_s   cn88xx; */
	/* struct bdk_pemx_msix_vecx_addr_s   cn88xxp1; */
} bdk_pemx_msix_vecx_addr_t;

static inline uint64_t BDK_PEMX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 <= 13)))
		return 0x000087E0C0F00000ull + (param1 & 7) * 0x1000000ull + (param2 & 15) * 0x10ull;
	csr_fatal("BDK_PEMX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_MSIX_VECX_ADDR(...) bdk_pemx_msix_vecx_addr_t
#define bustype_BDK_PEMX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_PEMX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_PEMX_MSIX_VECX_ADDR(...) "PEMX_MSIX_VECX_ADDR"


/**
 * RSL - pem#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the PEM_INT_VEC_E enumeration.
 *
 */
typedef union bdk_pemx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_pemx_msix_vecx_ctl_s {
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
	/* struct bdk_pemx_msix_vecx_ctl_s    cn88xx; */
	/* struct bdk_pemx_msix_vecx_ctl_s    cn88xxp1; */
} bdk_pemx_msix_vecx_ctl_t;

static inline uint64_t BDK_PEMX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 <= 13)))
		return 0x000087E0C0F00008ull + (param1 & 7) * 0x1000000ull + (param2 & 15) * 0x10ull;
	csr_fatal("BDK_PEMX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_MSIX_VECX_CTL(...) bdk_pemx_msix_vecx_ctl_t
#define bustype_BDK_PEMX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_PEMX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_PEMX_MSIX_VECX_CTL(...) "PEMX_MSIX_VECX_CTL"


/**
 * RSL - pem#_on
 *
 * This register indicates that PEM is configured and ready.
 *
 */
typedef union bdk_pemx_on {
	uint64_t u;
	struct bdk_pemx_on_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t pemoor                      : 1;  /**< RO/H - Indication to software that the PEM has been taken out of reset (i.e. BIST is done) and it
                                                                 is safe to configure core CSRs. */
		uint64_t pemon                       : 1;  /**< R/W/H - Indication to the QLM that the PEM is out of reset, configured, and ready to send/receive
                                                                 traffic. Setting this bit takes the configured PIPE out of reset. */
#else
		uint64_t pemon                       : 1;
		uint64_t pemoor                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_pemx_on_s               cn88xx; */
	/* struct bdk_pemx_on_s               cn88xxp1; */
} bdk_pemx_on_t;

static inline uint64_t BDK_PEMX_ON(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_ON(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000420ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_ON", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_ON(...) bdk_pemx_on_t
#define bustype_BDK_PEMX_ON(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_ON(p1) (p1)
#define arguments_BDK_PEMX_ON(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_ON(...) "PEMX_ON"


/**
 * RSL - pem#_p2n_bar0_start
 *
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the SLI in RC mode.
 */
typedef union bdk_pemx_p2n_bar0_start {
	uint64_t u;
	struct bdk_pemx_p2n_bar0_start_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t addr                        : 50; /**< R/W - The starting address of the 16KB BAR0 address space. */
		uint64_t reserved_0_13               : 14;
#else
		uint64_t reserved_0_13               : 14;
		uint64_t addr                        : 50;
#endif
	} s;
	/* struct bdk_pemx_p2n_bar0_start_s   cn88xx; */
	/* struct bdk_pemx_p2n_bar0_start_s   cn88xxp1; */
} bdk_pemx_p2n_bar0_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR0_START(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR0_START(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000080ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_P2N_BAR0_START", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_P2N_BAR0_START(...) bdk_pemx_p2n_bar0_start_t
#define bustype_BDK_PEMX_P2N_BAR0_START(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_P2N_BAR0_START(p1) (p1)
#define arguments_BDK_PEMX_P2N_BAR0_START(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_P2N_BAR0_START(...) "PEMX_P2N_BAR0_START"


/**
 * RSL - pem#_p2n_bar1_start
 *
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the SLI in RC mode.
 */
typedef union bdk_pemx_p2n_bar1_start {
	uint64_t u;
	struct bdk_pemx_p2n_bar1_start_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t addr                        : 38; /**< R/W - The starting address of the 64MB BAR1 address space. */
		uint64_t reserved_0_25               : 26;
#else
		uint64_t reserved_0_25               : 26;
		uint64_t addr                        : 38;
#endif
	} s;
	/* struct bdk_pemx_p2n_bar1_start_s   cn88xx; */
	/* struct bdk_pemx_p2n_bar1_start_s   cn88xxp1; */
} bdk_pemx_p2n_bar1_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR1_START(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR1_START(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000088ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_P2N_BAR1_START", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_P2N_BAR1_START(...) bdk_pemx_p2n_bar1_start_t
#define bustype_BDK_PEMX_P2N_BAR1_START(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_P2N_BAR1_START(p1) (p1)
#define arguments_BDK_PEMX_P2N_BAR1_START(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_P2N_BAR1_START(...) "PEMX_P2N_BAR1_START"


/**
 * RSL - pem#_p2n_bar2_start
 *
 * This register specifies the starting address for memory requests that are to be forwarded to
 * the SLI in RC mode.
 */
typedef union bdk_pemx_p2n_bar2_start {
	uint64_t u;
	struct bdk_pemx_p2n_bar2_start_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t addr                        : 14; /**< R/W - The starting address of the 2^50 address space
                                                                 that is the BAR2 address space. */
		uint64_t reserved_0_49               : 50;
#else
		uint64_t reserved_0_49               : 50;
		uint64_t addr                        : 14;
#endif
	} s;
	/* struct bdk_pemx_p2n_bar2_start_s   cn88xx; */
	/* struct bdk_pemx_p2n_bar2_start_s   cn88xxp1; */
} bdk_pemx_p2n_bar2_start_t;

static inline uint64_t BDK_PEMX_P2N_BAR2_START(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_P2N_BAR2_START(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000090ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_P2N_BAR2_START", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_P2N_BAR2_START(...) bdk_pemx_p2n_bar2_start_t
#define bustype_BDK_PEMX_P2N_BAR2_START(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_P2N_BAR2_START(p1) (p1)
#define arguments_BDK_PEMX_P2N_BAR2_START(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_P2N_BAR2_START(...) "PEMX_P2N_BAR2_START"


/**
 * RSL - pem#_tlp_credits
 *
 * This register specifies the number of credits for use in moving TLPs. When this register is
 * written, the credit values are reset to the register value. A write to this register should
 * take place before traffic flow starts.
 */
typedef union bdk_pemx_tlp_credits {
	uint64_t u;
	struct bdk_pemx_tlp_credits_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t sli_cpl                     : 8;  /**< R/W - TLP 16B credits for Completion TLPs in the SLI. Legal values are 0x24 to 0x80 and this
                                                                 value is not dependent of the number of PEMS wire-OR'd together. Software should
                                                                 reprogram this register for performance reasons. */
		uint64_t sli_np                      : 8;  /**< R/W - TLP 16B credits for Non-Posted TLPs in the SLI. Legal values are 0x4 to 0x10 and this
                                                                 value is not dependent of the number of PEMS wire-OR'd together. Software should
                                                                 reprogram this register for performance reasons. */
		uint64_t sli_p                       : 8;  /**< R/W - TLP 16B credits for Posted TLPs in the SLI. Legal values are 0x24 to 0x80 and this value
                                                                 is not dependent of the number of PEMS wire-OR'd together. Software should reprogram this
                                                                 register for performance reasons. */
#else
		uint64_t sli_p                       : 8;
		uint64_t sli_np                      : 8;
		uint64_t sli_cpl                     : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_pemx_tlp_credits_s      cn88xx; */
	/* struct bdk_pemx_tlp_credits_s      cn88xxp1; */
} bdk_pemx_tlp_credits_t;

static inline uint64_t BDK_PEMX_TLP_CREDITS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PEMX_TLP_CREDITS(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0C0000038ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_PEMX_TLP_CREDITS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PEMX_TLP_CREDITS(...) bdk_pemx_tlp_credits_t
#define bustype_BDK_PEMX_TLP_CREDITS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_PEMX_TLP_CREDITS(p1) (p1)
#define arguments_BDK_PEMX_TLP_CREDITS(p1) (p1),-1,-1,-1
#define basename_BDK_PEMX_TLP_CREDITS(...) "PEMX_TLP_CREDITS"

#endif /* __BDK_CSRS_PEM__ */
