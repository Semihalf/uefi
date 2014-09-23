#ifndef __BDK_CSRS_MIO_FUS__
#define __BDK_CSRS_MIO_FUS__
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
 * Cavium MIO_FUS.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * RSL - mio_fus_bnk_dat#
 *
 * The initial state of MIO_FUS_BNK_DAT(0..1) is as if bank6 were just read,
 * i.e. DAT* = fus[895:768].
 */
typedef union bdk_mio_fus_bnk_datx {
	uint64_t u;
	struct bdk_mio_fus_bnk_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< R/W/H - Efuse bank store. For read operations, the DAT gets the fus bank last read. For write
                                                                 operations, the DAT determines which fuses to blow. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_mio_fus_bnk_datx_s      cn85xx; */
	/* struct bdk_mio_fus_bnk_datx_s      cn88xx; */
	/* struct bdk_mio_fus_bnk_datx_s      cn88xxp1; */
} bdk_mio_fus_bnk_datx_t;

static inline uint64_t BDK_MIO_FUS_BNK_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_BNK_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E003001520ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_MIO_FUS_BNK_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_FUS_BNK_DATX(...) bdk_mio_fus_bnk_datx_t
#define bustype_BDK_MIO_FUS_BNK_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_BNK_DATX(p1) (p1)
#define arguments_BDK_MIO_FUS_BNK_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_FUS_BNK_DATX(...) "MIO_FUS_BNK_DATX"


/**
 * RSL - mio_fus_dat0
 */
typedef union bdk_mio_fus_dat0 {
	uint64_t u;
	struct bdk_mio_fus_dat0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t man_info                    : 32; /**< RO - Fuse information - manufacturing info [31:0]. */
#else
		uint64_t man_info                    : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_mio_fus_dat0_s          cn85xx; */
	/* struct bdk_mio_fus_dat0_s          cn88xx; */
	/* struct bdk_mio_fus_dat0_s          cn88xxp1; */
} bdk_mio_fus_dat0_t;

#define BDK_MIO_FUS_DAT0 BDK_MIO_FUS_DAT0_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT0_FUNC(void)
{
	return 0x000087E003001400ull;
}
#define typedef_BDK_MIO_FUS_DAT0 bdk_mio_fus_dat0_t
#define bustype_BDK_MIO_FUS_DAT0 BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_DAT0 0
#define arguments_BDK_MIO_FUS_DAT0 -1,-1,-1,-1
#define basename_BDK_MIO_FUS_DAT0 "MIO_FUS_DAT0"


/**
 * RSL - mio_fus_dat1
 */
typedef union bdk_mio_fus_dat1 {
	uint64_t u;
	struct bdk_mio_fus_dat1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t man_info                    : 32; /**< RO - Fuse information - manufacturing info [63:32]. */
#else
		uint64_t man_info                    : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_mio_fus_dat1_s          cn85xx; */
	/* struct bdk_mio_fus_dat1_s          cn88xx; */
	/* struct bdk_mio_fus_dat1_s          cn88xxp1; */
} bdk_mio_fus_dat1_t;

#define BDK_MIO_FUS_DAT1 BDK_MIO_FUS_DAT1_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT1_FUNC(void)
{
	return 0x000087E003001408ull;
}
#define typedef_BDK_MIO_FUS_DAT1 bdk_mio_fus_dat1_t
#define bustype_BDK_MIO_FUS_DAT1 BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_DAT1 0
#define arguments_BDK_MIO_FUS_DAT1 -1,-1,-1,-1
#define basename_BDK_MIO_FUS_DAT1 "MIO_FUS_DAT1"


/**
 * RSL - mio_fus_dat2
 */
typedef union bdk_mio_fus_dat2 {
	uint64_t u;
	struct bdk_mio_fus_dat2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t fus118                      : 1;  /**< RO - Fuse information - Ignore trusted-mode disable. Is actually fus99. */
		uint64_t rom_info                    : 10; /**< RO - Fuse information - ROM info. */
		uint64_t power_limit                 : 2;  /**< RO - Fuse information - Power limit. */
		uint64_t dorm_crypto                 : 1;  /**< RO - Fuse information - Dormant encryption enable. See NOCRYPTO. */
		uint64_t fus318                      : 1;  /**< RO - Reserved. */
		uint64_t raid_en                     : 1;  /**< RO - Fuse information - RAID enabled. */
		uint64_t reserved_29_31              : 3;
		uint64_t nodfa_cp2                   : 1;  /**< RO - Fuse information - HFA disable (CP2). */
		uint64_t nomul                       : 1;  /**< RO - Fuse information - VMUL disable. */
		uint64_t nocrypto                    : 1;  /**< RO - Fuse information - DORM_CRYPTO and NOCRYPTO together select the crypto mode:

                                                                 _ DORM_CRYPTO = 0, NOCRYPTO = 0: AES/SHA/PMULL enabled.

                                                                 _ DORM_CRYPTO = 0, NOCRYPTO = 1: The AES, SHA, and PMULL 1D/2D instructions will
                                                                 cause undefined exceptions, and ID_AA64ISAR0_EL1[AES, SHA1, SHA2] are zero
                                                                 indicating this behavior.

                                                                 _ DORM_CRYPTO = 1, NOCRYPTO = 0: Dormant encryption enable.  AES/SHA/PMULL are
                                                                 disabled (as if NOCRYPTO = 1) until the appropriate key is written to
                                                                 RNM_EER_KEY, then they are enabled (as if NOCRYPTO = 1).

                                                                 _ DORM_CRYPTO = 1, NOCRYPTO = 1: Reserved. */
		uint64_t trustzone_en                : 1;  /**< RO - Fuse information - TrustZone enable. */
		uint64_t reserved_24_24              : 1;
		uint64_t chip_id                     : 8;  /**< RO - Fuse information - chip ID. */
		uint64_t ocx_dis                     : 1;  /**< RO - Fuse information - OCX disable. */
		uint64_t bgx_dis                     : 2;  /**< RO - Fuse information - BGX(1..0) disable, BGX0 is bit\<13\> and BGX1 is bit\<14\>. */
		uint64_t sata_dis                    : 4;  /**< RO - Fuse information - SATA(3..0) disable, SATA0 is bit\<9\> ... SATA3 is bit\<12\>. */
		uint64_t pem_dis                     : 3;  /**< RO - Fuse information - PEM(2..0) disable, PEM0 is bit\<6\> ... PEM2 is bit\<8\>. */
		uint64_t lmc_half                    : 1;  /**< RO - Fuse information - LMC uses two channels rather than four. */
		uint64_t reserved_0_4                : 5;
#else
		uint64_t reserved_0_4                : 5;
		uint64_t lmc_half                    : 1;
		uint64_t pem_dis                     : 3;
		uint64_t sata_dis                    : 4;
		uint64_t bgx_dis                     : 2;
		uint64_t ocx_dis                     : 1;
		uint64_t chip_id                     : 8;
		uint64_t reserved_24_24              : 1;
		uint64_t trustzone_en                : 1;
		uint64_t nocrypto                    : 1;
		uint64_t nomul                       : 1;
		uint64_t nodfa_cp2                   : 1;
		uint64_t reserved_29_31              : 3;
		uint64_t raid_en                     : 1;
		uint64_t fus318                      : 1;
		uint64_t dorm_crypto                 : 1;
		uint64_t power_limit                 : 2;
		uint64_t rom_info                    : 10;
		uint64_t fus118                      : 1;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_mio_fus_dat2_s          cn85xx; */
	/* struct bdk_mio_fus_dat2_s          cn88xx; */
	/* struct bdk_mio_fus_dat2_s          cn88xxp1; */
} bdk_mio_fus_dat2_t;

#define BDK_MIO_FUS_DAT2 BDK_MIO_FUS_DAT2_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT2_FUNC(void)
{
	return 0x000087E003001410ull;
}
#define typedef_BDK_MIO_FUS_DAT2 bdk_mio_fus_dat2_t
#define bustype_BDK_MIO_FUS_DAT2 BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_DAT2 0
#define arguments_BDK_MIO_FUS_DAT2 -1,-1,-1,-1
#define basename_BDK_MIO_FUS_DAT2 "MIO_FUS_DAT2"


/**
 * RSL - mio_fus_dat3
 */
typedef union bdk_mio_fus_dat3 {
	uint64_t u;
	struct bdk_mio_fus_dat3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ema0                        : 6;  /**< RO - Fuse information - EMA0. INTERNAL: dflt value is 0x02. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
		uint64_t pll_ctl                     : 10; /**< RO - Reserved. */
		uint64_t dfa_info_dte                : 3;  /**< RO - Fuse information - HFA information (HTE). */
		uint64_t dfa_info_clm                : 4;  /**< RO - Fuse information - HFA information (cluster mask). */
		uint64_t pll_alt_matrix              : 1;  /**< RO - Select alternate PLL matrix. */
		uint64_t pll_bwadj_denom             : 2;  /**< RO - Select CLKF denominator for BWADJ value.
                                                                 0x0 = Selects CLKF/4.
                                                                 0x1 = Selects CLKF/2.
                                                                 0x2 = Selects CLKF/8. */
		uint64_t efus_lck_rsv                : 1;  /**< RO - Fuse information - efuse lockdown. */
		uint64_t efus_lck_man                : 1;  /**< RO - Fuse information - efuse lockdown. */
		uint64_t pll_half_dis                : 1;  /**< RO/H - Fuse information - Coprocessor-clock PLL control. */
		uint64_t l2c_crip                    : 3;  /**< RO - Fuse information - L2C cripple:
                                                                 0x0 = Full cache (16-way, 16 MB).
                                                                 0x1 = 3/4 ways (12-way, 12 MB).
                                                                 0x2 = 1/2 ways (8-way, 8 MB).
                                                                 0x3 = 1/4 ways (4-way, 4MB).
                                                                 0x4-0x7 = Reserved. */
		uint64_t use_int_refclk              : 1;  /**< RO - If set use the PLL output as the low-jitter reference clock to the rclk DLLs. Default is
                                                                 to use the external input reference clock. */
		uint64_t zip_info                    : 2;  /**< RO - Fuse information - Zip information. */
		uint64_t bar2_sz_conf                : 1;  /**< RO - Fuse information - When 0, BAR2 size conforms to PCIe specification. */
		uint64_t efus_lck                    : 1;  /**< RO - Fuse information - efuse lockdown. */
		uint64_t efus_ign                    : 1;  /**< RO - Fuse information - efuse ignore. */
		uint64_t nozip                       : 1;  /**< RO - Fuse information - ZIP disable. */
		uint64_t nodfa_dte                   : 1;  /**< RO - Fuse information - HFA disable (HTE). */
		uint64_t ema1                        : 6;  /**< RO - Fuse information - EMA1. INTERNAL: Default value is 0x11. Soft or hard blow of these fuses
                                                                 will XOR with this value. */
		uint64_t nohna_dte                   : 1;  /**< RO - Fuse information - HNA disable (DTE). */
		uint64_t hna_info_dte                : 3;  /**< RO - Fuse information - HNA information (DTE). */
		uint64_t hna_info_clm                : 4;  /**< RO - Fuse information - HNA information (cluster mask). */
		uint64_t tns_cripple                 : 1;  /**< RO - When set to 1, TNS switching functionality is permanently disabled. */
		uint64_t core_pll_mul                : 5;  /**< RO - Core-clock PLL multiplier. */
		uint64_t pnr_pll_mul                 : 4;  /**< RO - Coprocessor-clock PLL multiplier. */
#else
		uint64_t pnr_pll_mul                 : 4;
		uint64_t core_pll_mul                : 5;
		uint64_t tns_cripple                 : 1;
		uint64_t hna_info_clm                : 4;
		uint64_t hna_info_dte                : 3;
		uint64_t nohna_dte                   : 1;
		uint64_t ema1                        : 6;
		uint64_t nodfa_dte                   : 1;
		uint64_t nozip                       : 1;
		uint64_t efus_ign                    : 1;
		uint64_t efus_lck                    : 1;
		uint64_t bar2_sz_conf                : 1;
		uint64_t zip_info                    : 2;
		uint64_t use_int_refclk              : 1;
		uint64_t l2c_crip                    : 3;
		uint64_t pll_half_dis                : 1;
		uint64_t efus_lck_man                : 1;
		uint64_t efus_lck_rsv                : 1;
		uint64_t pll_bwadj_denom             : 2;
		uint64_t pll_alt_matrix              : 1;
		uint64_t dfa_info_clm                : 4;
		uint64_t dfa_info_dte                : 3;
		uint64_t pll_ctl                     : 10;
		uint64_t ema0                        : 6;
#endif
	} s;
	/* struct bdk_mio_fus_dat3_s          cn85xx; */
	/* struct bdk_mio_fus_dat3_s          cn88xx; */
	/* struct bdk_mio_fus_dat3_s          cn88xxp1; */
} bdk_mio_fus_dat3_t;

#define BDK_MIO_FUS_DAT3 BDK_MIO_FUS_DAT3_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT3_FUNC(void)
{
	return 0x000087E003001418ull;
}
#define typedef_BDK_MIO_FUS_DAT3 bdk_mio_fus_dat3_t
#define bustype_BDK_MIO_FUS_DAT3 BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_DAT3 0
#define arguments_BDK_MIO_FUS_DAT3 -1,-1,-1,-1
#define basename_BDK_MIO_FUS_DAT3 "MIO_FUS_DAT3"


/**
 * RSL - mio_fus_dat4
 */
typedef union bdk_mio_fus_dat4 {
	uint64_t u;
	struct bdk_mio_fus_dat4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t global_rclk_byp_select      : 1;  /**< RO - Reserved. */
		uint64_t global_rclk_byp_setting     : 11; /**< RO - Bits\<11:1\>. Reserved. */
		uint64_t east_rclk_byp_select        : 1;  /**< RO - Reserved. */
		uint64_t east_rclk_byp_setting       : 12; /**< RO - Reserved. */
		uint64_t cmb_rclk_byp_select         : 1;  /**< RO - Reserved. */
		uint64_t cmb_rclk_byp_setting        : 12; /**< RO - Reserved. */
		uint64_t pp_rclk_byp_select          : 1;  /**< RO - Reserved. */
		uint64_t pp_rclk_byp_setting         : 12; /**< RO - Reserved. */
		uint64_t tad_rclk_byp_select         : 1;  /**< RO - Reserved. */
		uint64_t tad_rclk_byp_setting        : 12; /**< RO - Reserved. */
#else
		uint64_t tad_rclk_byp_setting        : 12;
		uint64_t tad_rclk_byp_select         : 1;
		uint64_t pp_rclk_byp_setting         : 12;
		uint64_t pp_rclk_byp_select          : 1;
		uint64_t cmb_rclk_byp_setting        : 12;
		uint64_t cmb_rclk_byp_select         : 1;
		uint64_t east_rclk_byp_setting       : 12;
		uint64_t east_rclk_byp_select        : 1;
		uint64_t global_rclk_byp_setting     : 11;
		uint64_t global_rclk_byp_select      : 1;
#endif
	} s;
	/* struct bdk_mio_fus_dat4_s          cn85xx; */
	/* struct bdk_mio_fus_dat4_s          cn88xx; */
	/* struct bdk_mio_fus_dat4_s          cn88xxp1; */
} bdk_mio_fus_dat4_t;

#define BDK_MIO_FUS_DAT4 BDK_MIO_FUS_DAT4_FUNC()
static inline uint64_t BDK_MIO_FUS_DAT4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_DAT4_FUNC(void)
{
	return 0x000087E003001420ull;
}
#define typedef_BDK_MIO_FUS_DAT4 bdk_mio_fus_dat4_t
#define bustype_BDK_MIO_FUS_DAT4 BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_DAT4 0
#define arguments_BDK_MIO_FUS_DAT4 -1,-1,-1,-1
#define basename_BDK_MIO_FUS_DAT4 "MIO_FUS_DAT4"


/**
 * RSL - mio_fus_int
 */
typedef union bdk_mio_fus_int {
	uint64_t u;
	struct bdk_mio_fus_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t rpr_dbe                     : 1;  /**< R/W1C/H - INTERNAL: Indicates an uncorrectable double-bit-error occurred to RPR_MEM. */
		uint64_t rpr_sbe                     : 1;  /**< R/W1C/H - INTERNAL: Indicates a corrected single-bit-error occurred to RPR_MEM. */
#else
		uint64_t rpr_sbe                     : 1;
		uint64_t rpr_dbe                     : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_fus_int_s           cn85xx; */
	/* struct bdk_mio_fus_int_s           cn88xx; */
	/* struct bdk_mio_fus_int_s           cn88xxp1; */
} bdk_mio_fus_int_t;

#define BDK_MIO_FUS_INT BDK_MIO_FUS_INT_FUNC()
static inline uint64_t BDK_MIO_FUS_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_INT_FUNC(void)
{
	return 0x000087E003001548ull;
}
#define typedef_BDK_MIO_FUS_INT bdk_mio_fus_int_t
#define bustype_BDK_MIO_FUS_INT BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_INT 0
#define arguments_BDK_MIO_FUS_INT -1,-1,-1,-1
#define basename_BDK_MIO_FUS_INT "MIO_FUS_INT"


/**
 * RSL - mio_fus_pdf
 */
typedef union bdk_mio_fus_pdf {
	uint64_t u;
	struct bdk_mio_fus_pdf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pdf                         : 64; /**< RO - Fuse information--product definition field. */
#else
		uint64_t pdf                         : 64;
#endif
	} s;
	/* struct bdk_mio_fus_pdf_s           cn85xx; */
	/* struct bdk_mio_fus_pdf_s           cn88xx; */
	/* struct bdk_mio_fus_pdf_s           cn88xxp1; */
} bdk_mio_fus_pdf_t;

#define BDK_MIO_FUS_PDF BDK_MIO_FUS_PDF_FUNC()
static inline uint64_t BDK_MIO_FUS_PDF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PDF_FUNC(void)
{
	return 0x000087E003001428ull;
}
#define typedef_BDK_MIO_FUS_PDF bdk_mio_fus_pdf_t
#define bustype_BDK_MIO_FUS_PDF BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_PDF 0
#define arguments_BDK_MIO_FUS_PDF -1,-1,-1,-1
#define basename_BDK_MIO_FUS_PDF "MIO_FUS_PDF"


/**
 * RSL - mio_fus_pll
 */
typedef union bdk_mio_fus_pll {
	uint64_t u;
	struct bdk_mio_fus_pll_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t core_status                 : 3;  /**< RO - Core-clock PLL status information. */
		uint64_t reserved_11_11              : 1;
		uint64_t pnr_status                  : 3;  /**< RO - Coprocessor-clock PLL status information. */
		uint64_t c_cout_rst                  : 1;  /**< R/W - Core clockout postscaler reset. The core clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing C_COUT_SEL. The core clockout postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after C_COUT_SEL changes. */
		uint64_t c_cout_sel                  : 2;  /**< R/W - Core-clock output select:
                                                                 0x0 = Core clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = Undivided core clock. */
		uint64_t pnr_cout_rst                : 1;  /**< R/W - SYS clockout postscaler reset. The PNR clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing PNR_COUT_SEL. The SYS clockout
                                                                 postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after PNR_COUT_SEL
                                                                 changes. */
		uint64_t pnr_cout_sel                : 2;  /**< R/W - Coprocessor-clock output select:
                                                                 0x0 = Coprocessor clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = Undivided core clock. */
		uint64_t reserved_0_1                : 2;
#else
		uint64_t reserved_0_1                : 2;
		uint64_t pnr_cout_sel                : 2;
		uint64_t pnr_cout_rst                : 1;
		uint64_t c_cout_sel                  : 2;
		uint64_t c_cout_rst                  : 1;
		uint64_t pnr_status                  : 3;
		uint64_t reserved_11_11              : 1;
		uint64_t core_status                 : 3;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_mio_fus_pll_s           cn85xx; */
	/* struct bdk_mio_fus_pll_s           cn88xx; */
	/* struct bdk_mio_fus_pll_s           cn88xxp1; */
} bdk_mio_fus_pll_t;

#define BDK_MIO_FUS_PLL BDK_MIO_FUS_PLL_FUNC()
static inline uint64_t BDK_MIO_FUS_PLL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PLL_FUNC(void)
{
	return 0x000087E003001580ull;
}
#define typedef_BDK_MIO_FUS_PLL bdk_mio_fus_pll_t
#define bustype_BDK_MIO_FUS_PLL BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_PLL 0
#define arguments_BDK_MIO_FUS_PLL -1,-1,-1,-1
#define basename_BDK_MIO_FUS_PLL "MIO_FUS_PLL"


/**
 * RSL - mio_fus_prog
 */
typedef union bdk_mio_fus_prog {
	uint64_t u;
	struct bdk_mio_fus_prog_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t sft                         : 1;  /**< R/W/H - INTERNAL: When set with PROG, causes only the local storage to change and will not blow
                                                                 any fuses. Hardware will clear when the program operation is complete. */
		uint64_t prog                        : 1;  /**< R/W/H - INTERNAL: When written to one by software, blow the fuse bank. Hardware will clear when
                                                                 the program operation is complete.
                                                                 To write a bank of fuses, software must set MIO_FUS_WADR[ADDR] to the bank to be
                                                                 programmed and then set each bit within MIO_FUS_BNK_DATX to indicate which fuses to blow.
                                                                 Once ADDR, and DAT are setup, SW can write to MIO_FUS_PROG[PROG] to start the bank write
                                                                 and poll on PROG. Once PROG is clear, the bank write is complete. A soft blow is still
                                                                 subject to lockdown fuses. After a soft/warm reset, the chip will behave as though the
                                                                 fuses were actually blown. A cold reset restores the actual fuse values. */
#else
		uint64_t prog                        : 1;
		uint64_t sft                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_fus_prog_s          cn85xx; */
	/* struct bdk_mio_fus_prog_s          cn88xx; */
	/* struct bdk_mio_fus_prog_s          cn88xxp1; */
} bdk_mio_fus_prog_t;

#define BDK_MIO_FUS_PROG BDK_MIO_FUS_PROG_FUNC()
static inline uint64_t BDK_MIO_FUS_PROG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PROG_FUNC(void)
{
	return 0x000087E003001510ull;
}
#define typedef_BDK_MIO_FUS_PROG bdk_mio_fus_prog_t
#define bustype_BDK_MIO_FUS_PROG BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_PROG 0
#define arguments_BDK_MIO_FUS_PROG -1,-1,-1,-1
#define basename_BDK_MIO_FUS_PROG "MIO_FUS_PROG"


/**
 * RSL - mio_fus_prog_times
 */
typedef union bdk_mio_fus_prog_times {
	uint64_t u;
	struct bdk_mio_fus_prog_times_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_35_63              : 29;
		uint64_t vgate_pin                   : 1;  /**< RO - INTERNAL: Efuse vgate pin (L6G). */
		uint64_t fsrc_pin                    : 1;  /**< RO - INTERNAL: Efuse fsource pin (L6G). */
		uint64_t prog_pin                    : 1;  /**< RO - INTERNAL: Efuse program pin (IFB). */
		uint64_t reserved_0_31               : 32;
#else
		uint64_t reserved_0_31               : 32;
		uint64_t prog_pin                    : 1;
		uint64_t fsrc_pin                    : 1;
		uint64_t vgate_pin                   : 1;
		uint64_t reserved_35_63              : 29;
#endif
	} s;
	/* struct bdk_mio_fus_prog_times_s    cn85xx; */
	/* struct bdk_mio_fus_prog_times_s    cn88xx; */
	/* struct bdk_mio_fus_prog_times_s    cn88xxp1; */
} bdk_mio_fus_prog_times_t;

#define BDK_MIO_FUS_PROG_TIMES BDK_MIO_FUS_PROG_TIMES_FUNC()
static inline uint64_t BDK_MIO_FUS_PROG_TIMES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_PROG_TIMES_FUNC(void)
{
	return 0x000087E003001518ull;
}
#define typedef_BDK_MIO_FUS_PROG_TIMES bdk_mio_fus_prog_times_t
#define bustype_BDK_MIO_FUS_PROG_TIMES BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_PROG_TIMES 0
#define arguments_BDK_MIO_FUS_PROG_TIMES -1,-1,-1,-1
#define basename_BDK_MIO_FUS_PROG_TIMES "MIO_FUS_PROG_TIMES"


/**
 * RSL - mio_fus_rcmd
 *
 * To read an efuse, software writes MIO_FUS_RCMD[ADDR,PEND] with the byte address of the fuse in
 * question, then software can poll MIO_FUS_RCMD[PEND]. When [PEND] = 0, then
 * MIO_FUS_RCMD[DAT] is valid. In addition, if the efuse read went to the efuse banks (e.g.
 * (ADDR/16) not {0,1,7}) || EFUSE), software can read MIO_FUS_BNK_DATx which contains all 128
 * fuses in the bank associated in ADDR.
 */
typedef union bdk_mio_fus_rcmd {
	uint64_t u;
	struct bdk_mio_fus_rcmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t dat                         : 8;  /**< RO/H - Eight bits of fuse data. */
		uint64_t reserved_13_15              : 3;
		uint64_t pend                        : 1;  /**< R/W/H - Software sets this bit to 1 on a write operation that starts FUSE read operation. Hardware
                                                                 clears this bit when the read operation
                                                                 is complete and the DAT is valid. */
		uint64_t reserved_11_11              : 1;
		uint64_t addr_hi                     : 2;  /**< R/W - Upper fuse address bits to extend space beyond 2k fuses. Valid range is 0x0-0x3. */
		uint64_t efuse                       : 1;  /**< R/W - Efuse storage. When set to 1, the return data is from the efuse storage rather than the
                                                                 local storage. */
		uint64_t addr                        : 8;  /**< R/W - Address. Specifies the byte address of the fuse to read. */
#else
		uint64_t addr                        : 8;
		uint64_t efuse                       : 1;
		uint64_t addr_hi                     : 2;
		uint64_t reserved_11_11              : 1;
		uint64_t pend                        : 1;
		uint64_t reserved_13_15              : 3;
		uint64_t dat                         : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_mio_fus_rcmd_s          cn85xx; */
	/* struct bdk_mio_fus_rcmd_s          cn88xx; */
	/* struct bdk_mio_fus_rcmd_s          cn88xxp1; */
} bdk_mio_fus_rcmd_t;

#define BDK_MIO_FUS_RCMD BDK_MIO_FUS_RCMD_FUNC()
static inline uint64_t BDK_MIO_FUS_RCMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_RCMD_FUNC(void)
{
	return 0x000087E003001500ull;
}
#define typedef_BDK_MIO_FUS_RCMD bdk_mio_fus_rcmd_t
#define bustype_BDK_MIO_FUS_RCMD BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_RCMD 0
#define arguments_BDK_MIO_FUS_RCMD -1,-1,-1,-1
#define basename_BDK_MIO_FUS_RCMD "MIO_FUS_RCMD"


/**
 * RSL - mio_fus_read_times
 *
 * IFB fuses are 0 to 1791. The reset values are for IFB fuses for PLL_REF_CLK up to 100MHz when
 * the core PLL is engaged. If any of the formulas below result in a value less than 0x0, the
 * corresponding timing parameter should be set to 0.
 *
 * Prior to issuing a read operation to the fuse banks (via MIO_FUS_RCMD), this register should
 * be written with the timing parameters that will be read.
 * This register should not be written while MIO_FUS_RCMD[PEND] = 1.
 */
typedef union bdk_mio_fus_read_times {
	uint64_t u;
	struct bdk_mio_fus_read_times_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t done                        : 4;  /**< R/W - Hold time of CSB, PGENB, and LOAD with respect to falling edge of STROBE for read and
                                                                 write mode in PLL_REF_CLK + 1 cycles. Timing specs are th_CS = 6ns, th_PG = 10ns, th_LD_p
                                                                 = 7ns. Default of 0x0 yields 20ns for a PLL_REF_CLK of 50 MHz, 10ns at 100MHz. */
		uint64_t ahd                         : 4;  /**< R/W - Hold time of A with respect to falling edge of STROBE for read and write modes in
                                                                 PLL_REF_CLK + 2 cycles. Timing spec of tsu_A_r and tsu_A_p is 3ns min. Default of 0x0
                                                                 yields 40ns for a PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
		uint64_t wrstb_wh                    : 12; /**< R/W - Pulse width high of STROBE in write mode in PLL_REF_CLK + 1 cycles. Timing spec of
                                                                 twh_SB_p is 9.8us max. Default of 0x1F3 yields 10 us at PLL_REF_CLK of 50 MHz. */
		uint64_t rdstb_wh                    : 4;  /**< R/W - Pulse width high of STROBE in read mode in PLL_REF_CLK + 1 cycles. Timing spec of twh_SB_p
                                                                 is 20ns min. Default of 0x1 yields 40 ns at PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
		uint64_t asu                         : 4;  /**< R/W - Setup time of A to rising edge of STROBE for read and write modes in PLL_REF_CLK cycles.
                                                                 Timing spec of tsu_A_r and tsu_A_p is 12 ns min. Default of 0x1 yields 40 ns at
                                                                 PLL_REF_CLK of 50 MHz, 20ns at 100MHz. */
		uint64_t setup                       : 4;  /**< R/W - Setup time of CSB, PGENB, LOAD to rising edge of STROBE in read and write modes in
                                                                 PLL_REF_CLK + 1 cycles. tsu_CS = 16ns, tsu_PG = 14ns, tsu_LD_r = 10ns. Default of 0x0
                                                                 yields 20 ns plus ASU cycles at PLL_REF_CLK of 50 MHz, 10ns + ASU at 100MHz. */
#else
		uint64_t setup                       : 4;
		uint64_t asu                         : 4;
		uint64_t rdstb_wh                    : 4;
		uint64_t wrstb_wh                    : 12;
		uint64_t ahd                         : 4;
		uint64_t done                        : 4;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_mio_fus_read_times_s    cn85xx; */
	/* struct bdk_mio_fus_read_times_s    cn88xx; */
	/* struct bdk_mio_fus_read_times_s    cn88xxp1; */
} bdk_mio_fus_read_times_t;

#define BDK_MIO_FUS_READ_TIMES BDK_MIO_FUS_READ_TIMES_FUNC()
static inline uint64_t BDK_MIO_FUS_READ_TIMES_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_READ_TIMES_FUNC(void)
{
	return 0x000087E003001570ull;
}
#define typedef_BDK_MIO_FUS_READ_TIMES bdk_mio_fus_read_times_t
#define bustype_BDK_MIO_FUS_READ_TIMES BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_READ_TIMES 0
#define arguments_BDK_MIO_FUS_READ_TIMES -1,-1,-1,-1
#define basename_BDK_MIO_FUS_READ_TIMES "MIO_FUS_READ_TIMES"


/**
 * RSL - mio_fus_rpr_dat#
 */
typedef union bdk_mio_fus_rpr_datx {
	uint64_t u;
	struct bdk_mio_fus_rpr_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< R/W - INTERNAL: Repair memory store (RPR_MEM). Data for read and write. A write to
                                                                 MIO_FUS_RPR_DAT(1) writes all 128 bits from both registers to RPR_MEM. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_mio_fus_rpr_datx_s      cn85xx; */
	/* struct bdk_mio_fus_rpr_datx_s      cn88xx; */
	/* struct bdk_mio_fus_rpr_datx_s      cn88xxp1; */
} bdk_mio_fus_rpr_datx_t;

static inline uint64_t BDK_MIO_FUS_RPR_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_RPR_DATX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E003001530ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_MIO_FUS_RPR_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_FUS_RPR_DATX(...) bdk_mio_fus_rpr_datx_t
#define bustype_BDK_MIO_FUS_RPR_DATX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_RPR_DATX(p1) (p1)
#define arguments_BDK_MIO_FUS_RPR_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_FUS_RPR_DATX(...) "MIO_FUS_RPR_DATX"


/**
 * RSL - mio_fus_soft_repair
 */
typedef union bdk_mio_fus_soft_repair {
	uint64_t u;
	struct bdk_mio_fus_soft_repair_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t rpr_flip_synd               : 2;  /**< R/W/H - INTERNAL: Flip syndrome bits on RPR_MEM writes. For diagnostic use only. */
		uint64_t autoblow                    : 1;  /**< R/W/H - INTERNAL: Set to initiate burning of defect fuses to fuse macro. Clears when fuses are
                                                                 blown. */
		uint64_t too_many                    : 1;  /**< RO/H - INTERNAL: Set if the sum of fuse repairs and memory defects exceeds 195. */
		uint64_t numdefects                  : 8;  /**< RO/H - INTERNAL: After reset/BIST indicates the number of memory defects reported. Defects are
                                                                 stored in REPAIR_MEM from bit address NUMREPAIRS*21 to (NUMREPAIRS*21 + NUMDEFECTS*21 -
                                                                 1). */
		uint64_t numrepairs                  : 8;  /**< R/W - INTERNAL: Indicates the number of soft repairs to load from repair mem to the memories on
                                                                 a soft/warm reset. Indicates the number of repairs loaded from efuses to repair mem on a
                                                                 cold reset. */
#else
		uint64_t numrepairs                  : 8;
		uint64_t numdefects                  : 8;
		uint64_t too_many                    : 1;
		uint64_t autoblow                    : 1;
		uint64_t rpr_flip_synd               : 2;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_mio_fus_soft_repair_s   cn85xx; */
	/* struct bdk_mio_fus_soft_repair_s   cn88xx; */
	/* struct bdk_mio_fus_soft_repair_s   cn88xxp1; */
} bdk_mio_fus_soft_repair_t;

#define BDK_MIO_FUS_SOFT_REPAIR BDK_MIO_FUS_SOFT_REPAIR_FUNC()
static inline uint64_t BDK_MIO_FUS_SOFT_REPAIR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_SOFT_REPAIR_FUNC(void)
{
	return 0x000087E003001540ull;
}
#define typedef_BDK_MIO_FUS_SOFT_REPAIR bdk_mio_fus_soft_repair_t
#define bustype_BDK_MIO_FUS_SOFT_REPAIR BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_SOFT_REPAIR 0
#define arguments_BDK_MIO_FUS_SOFT_REPAIR -1,-1,-1,-1
#define basename_BDK_MIO_FUS_SOFT_REPAIR "MIO_FUS_SOFT_REPAIR"


/**
 * RSL - mio_fus_tgg
 *
 * This register exists to support Authentik. Authentik code should read this register, then
 * clear VAL to prevent other software from observing the value of the TGG fuses.
 */
typedef union bdk_mio_fus_tgg {
	uint64_t u;
	struct bdk_mio_fus_tgg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t val                         : 1;  /**< R/W/H - Software can write VAL to 0, but cannot write VAL to a 1. When VAL = 1, DAT reads
                                                                 the corresponding TGG fuses. When VAL = 0, DAT reads as 0s. The reset value of
                                                                 this VAL bit is normally its fuse setting (i.e. TGG\<63\>). */
		uint64_t dat                         : 63; /**< RO/H - When VAL = 0, DAT always reads as 0x0, regardless of the value of the TGG\<62:0\>
                                                                 fuses. When VAL = 1, DAT returns the value of the TGG\<62:0\> fuses. */
#else
		uint64_t dat                         : 63;
		uint64_t val                         : 1;
#endif
	} s;
	/* struct bdk_mio_fus_tgg_s           cn85xx; */
	/* struct bdk_mio_fus_tgg_s           cn88xx; */
	/* struct bdk_mio_fus_tgg_s           cn88xxp1; */
} bdk_mio_fus_tgg_t;

#define BDK_MIO_FUS_TGG BDK_MIO_FUS_TGG_FUNC()
static inline uint64_t BDK_MIO_FUS_TGG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_TGG_FUNC(void)
{
	return 0x000087E003001430ull;
}
#define typedef_BDK_MIO_FUS_TGG bdk_mio_fus_tgg_t
#define bustype_BDK_MIO_FUS_TGG BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_TGG 0
#define arguments_BDK_MIO_FUS_TGG -1,-1,-1,-1
#define basename_BDK_MIO_FUS_TGG "MIO_FUS_TGG"


/**
 * RSL - mio_fus_wadr
 */
typedef union bdk_mio_fus_wadr {
	uint64_t u;
	struct bdk_mio_fus_wadr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t addr                        : 6;  /**< R/W - Indicates which of the banks of 128 fuses to blow. */
#else
		uint64_t addr                        : 6;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_mio_fus_wadr_s          cn85xx; */
	/* struct bdk_mio_fus_wadr_s          cn88xx; */
	/* struct bdk_mio_fus_wadr_s          cn88xxp1; */
} bdk_mio_fus_wadr_t;

#define BDK_MIO_FUS_WADR BDK_MIO_FUS_WADR_FUNC()
static inline uint64_t BDK_MIO_FUS_WADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_FUS_WADR_FUNC(void)
{
	return 0x000087E003001508ull;
}
#define typedef_BDK_MIO_FUS_WADR bdk_mio_fus_wadr_t
#define bustype_BDK_MIO_FUS_WADR BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_FUS_WADR 0
#define arguments_BDK_MIO_FUS_WADR -1,-1,-1,-1
#define basename_BDK_MIO_FUS_WADR "MIO_FUS_WADR"

#endif /* __BDK_CSRS_MIO_FUS__ */
