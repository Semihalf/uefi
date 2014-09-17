#ifndef __BDK_CSRS_LMC__
#define __BDK_CSRS_LMC__
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
 * Cavium LMC.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration LMC_INT_VEC_E
 *
 * LMC MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum lmc_int_vec_e {
	LMC_INT_VEC_E_INTS = 0x0,
	LMC_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - lmc#_bist_ctl
 *
 * This register has fields to control BIST operation.
 *
 */
typedef union bdk_lmcx_bist_ctl {
	uint64_t u;
	struct bdk_lmcx_bist_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t macram_bist_status          : 1;  /**< RO/H - Maximum Activate Counts RAM BIST status.
                                                                 1 means fail. */
		uint64_t dlcram_bist_status          : 1;  /**< RO/H - DLC RAM BIST status; 1 means fail. */
		uint64_t dlcram_bist_done            : 1;  /**< RO/H - DLC and MAC RAM BIST complete indication;
                                                                 1 means both RAMs have completed. */
		uint64_t start_bist                  : 1;  /**< R/W - Start BIST on DLC and MAC memory. */
		uint64_t clear_bist                  : 1;  /**< R/W - Start clear BIST on DLC and MAC memory. */
#else
		uint64_t clear_bist                  : 1;
		uint64_t start_bist                  : 1;
		uint64_t dlcram_bist_done            : 1;
		uint64_t dlcram_bist_status          : 1;
		uint64_t macram_bist_status          : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_lmcx_bist_ctl_s         cn85xx; */
	/* struct bdk_lmcx_bist_ctl_s         cn88xx; */
	/* struct bdk_lmcx_bist_ctl_s         cn88xxp1; */
} bdk_lmcx_bist_ctl_t;

static inline uint64_t BDK_LMCX_BIST_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_BIST_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000100ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_BIST_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_BIST_CTL(...) bdk_lmcx_bist_ctl_t
#define bustype_BDK_LMCX_BIST_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_BIST_CTL(p1) (p1)
#define arguments_BDK_LMCX_BIST_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_BIST_CTL(...) "LMCX_BIST_CTL"


/**
 * RSL - lmc#_char_ctl
 *
 * This register provides an assortment of various control fields needed to characterize the DDR3
 * interface.
 */
typedef union bdk_lmcx_char_ctl {
	uint64_t u;
	struct bdk_lmcx_char_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t dq_char_check_lock          : 1;  /**< RO/H - Indicates if a lock has been achieved. Is set to 1 only if a lock is achieved during the
                                                                 LFSR priming period after DQ_CHAR_CHECK_ENABLE is set to 1, and is forced back to 0 when
                                                                 DQ_CHAR_CHECK_ENABLE is set to 0. */
		uint64_t dq_char_check_enable        : 1;  /**< R/W - Enable DQ pattern check. The transition from disabled to enabled clears
                                                                 LMC()_CHAR_DQ_ERR_COUNT. */
		uint64_t dq_char_bit_sel             : 3;  /**< R/W - Select a bit within the byte for DQ characterization pattern check. */
		uint64_t dq_char_byte_sel            : 4;  /**< R/W - Select a byte of data for DQ characterization pattern check. */
		uint64_t dr                          : 1;  /**< R/W - Pattern at data rate (not clock rate). */
		uint64_t skew_on                     : 1;  /**< R/W - Skew adjacent bits. */
		uint64_t en                          : 1;  /**< R/W - Enable characterization. */
		uint64_t sel                         : 1;  /**< R/W - Pattern select: 0 = PRBS, 1 = programmable pattern. */
		uint64_t prog                        : 8;  /**< R/W - Programmable pattern. */
		uint64_t prbs                        : 32; /**< R/W - PRBS polynomial. */
#else
		uint64_t prbs                        : 32;
		uint64_t prog                        : 8;
		uint64_t sel                         : 1;
		uint64_t en                          : 1;
		uint64_t skew_on                     : 1;
		uint64_t dr                          : 1;
		uint64_t dq_char_byte_sel            : 4;
		uint64_t dq_char_bit_sel             : 3;
		uint64_t dq_char_check_enable        : 1;
		uint64_t dq_char_check_lock          : 1;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_lmcx_char_ctl_s         cn85xx; */
	/* struct bdk_lmcx_char_ctl_s         cn88xx; */
	/* struct bdk_lmcx_char_ctl_s         cn88xxp1; */
} bdk_lmcx_char_ctl_t;

static inline uint64_t BDK_LMCX_CHAR_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000220ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_CTL(...) bdk_lmcx_char_ctl_t
#define bustype_BDK_LMCX_CHAR_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_CTL(p1) (p1)
#define arguments_BDK_LMCX_CHAR_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_CTL(...) "LMCX_CHAR_CTL"


/**
 * RSL - lmc#_char_dq_err_count
 *
 * This register is used to initiate the various control sequences in the LMC.
 *
 */
typedef union bdk_lmcx_char_dq_err_count {
	uint64_t u;
	struct bdk_lmcx_char_dq_err_count_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t dq_err_count                : 40; /**< RO - DQ error count. */
#else
		uint64_t dq_err_count                : 40;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_lmcx_char_dq_err_count_s cn85xx; */
	/* struct bdk_lmcx_char_dq_err_count_s cn88xx; */
	/* struct bdk_lmcx_char_dq_err_count_s cn88xxp1; */
} bdk_lmcx_char_dq_err_count_t;

static inline uint64_t BDK_LMCX_CHAR_DQ_ERR_COUNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_DQ_ERR_COUNT(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000040ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_DQ_ERR_COUNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_DQ_ERR_COUNT(...) bdk_lmcx_char_dq_err_count_t
#define bustype_BDK_LMCX_CHAR_DQ_ERR_COUNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_DQ_ERR_COUNT(p1) (p1)
#define arguments_BDK_LMCX_CHAR_DQ_ERR_COUNT(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_DQ_ERR_COUNT(...) "LMCX_CHAR_DQ_ERR_COUNT"


/**
 * RSL - lmc#_char_mask0
 *
 * This register provides an assortment of various control fields needed to characterize the DDR3
 * interface.
 */
typedef union bdk_lmcx_char_mask0 {
	uint64_t u;
	struct bdk_lmcx_char_mask0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mask                        : 64; /**< R/W - Mask for DQ0\<63:0\>. */
#else
		uint64_t mask                        : 64;
#endif
	} s;
	/* struct bdk_lmcx_char_mask0_s       cn85xx; */
	/* struct bdk_lmcx_char_mask0_s       cn88xx; */
	/* struct bdk_lmcx_char_mask0_s       cn88xxp1; */
} bdk_lmcx_char_mask0_t;

static inline uint64_t BDK_LMCX_CHAR_MASK0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_MASK0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000228ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_MASK0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_MASK0(...) bdk_lmcx_char_mask0_t
#define bustype_BDK_LMCX_CHAR_MASK0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_MASK0(p1) (p1)
#define arguments_BDK_LMCX_CHAR_MASK0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_MASK0(...) "LMCX_CHAR_MASK0"


/**
 * RSL - lmc#_char_mask1
 *
 * This register provides an assortment of various control fields needed to characterize the DDR3
 * interface.
 */
typedef union bdk_lmcx_char_mask1 {
	uint64_t u;
	struct bdk_lmcx_char_mask1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t mask                        : 8;  /**< R/W - Mask for DQ0\<71:64\>. */
#else
		uint64_t mask                        : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_lmcx_char_mask1_s       cn85xx; */
	/* struct bdk_lmcx_char_mask1_s       cn88xx; */
	/* struct bdk_lmcx_char_mask1_s       cn88xxp1; */
} bdk_lmcx_char_mask1_t;

static inline uint64_t BDK_LMCX_CHAR_MASK1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_MASK1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000230ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_MASK1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_MASK1(...) bdk_lmcx_char_mask1_t
#define bustype_BDK_LMCX_CHAR_MASK1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_MASK1(p1) (p1)
#define arguments_BDK_LMCX_CHAR_MASK1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_MASK1(...) "LMCX_CHAR_MASK1"


/**
 * RSL - lmc#_char_mask2
 *
 * This register provides an assortment of various control fields needed to characterize the DDR3
 * interface.
 */
typedef union bdk_lmcx_char_mask2 {
	uint64_t u;
	struct bdk_lmcx_char_mask2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mask                        : 64; /**< R/W - Mask for DQ1\<63:0\>. */
#else
		uint64_t mask                        : 64;
#endif
	} s;
	/* struct bdk_lmcx_char_mask2_s       cn85xx; */
	/* struct bdk_lmcx_char_mask2_s       cn88xx; */
	/* struct bdk_lmcx_char_mask2_s       cn88xxp1; */
} bdk_lmcx_char_mask2_t;

static inline uint64_t BDK_LMCX_CHAR_MASK2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_MASK2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000238ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_MASK2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_MASK2(...) bdk_lmcx_char_mask2_t
#define bustype_BDK_LMCX_CHAR_MASK2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_MASK2(p1) (p1)
#define arguments_BDK_LMCX_CHAR_MASK2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_MASK2(...) "LMCX_CHAR_MASK2"


/**
 * RSL - lmc#_char_mask3
 *
 * This register provides an assortment of various control fields needed to characterize the DDR3
 * interface.
 */
typedef union bdk_lmcx_char_mask3 {
	uint64_t u;
	struct bdk_lmcx_char_mask3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t mask                        : 8;  /**< R/W - Mask for DQ1\<71:64\>. */
#else
		uint64_t mask                        : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_lmcx_char_mask3_s       cn85xx; */
	/* struct bdk_lmcx_char_mask3_s       cn88xx; */
	/* struct bdk_lmcx_char_mask3_s       cn88xxp1; */
} bdk_lmcx_char_mask3_t;

static inline uint64_t BDK_LMCX_CHAR_MASK3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_MASK3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000240ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_MASK3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_MASK3(...) bdk_lmcx_char_mask3_t
#define bustype_BDK_LMCX_CHAR_MASK3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_MASK3(p1) (p1)
#define arguments_BDK_LMCX_CHAR_MASK3(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_MASK3(...) "LMCX_CHAR_MASK3"


/**
 * RSL - lmc#_char_mask4
 *
 * This register is an assortment of various control fields needed to characterize the DDR3 interface.
 *
 */
typedef union bdk_lmcx_char_mask4 {
	uint64_t u;
	struct bdk_lmcx_char_mask4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ref_pin_on_mask             : 9;  /**< R/W - This mask is applied to the REF_PIN_ON signals that go to the PHY, so that each byte lane
                                                                 can selectively turn off or on the signals once the master signals are enabled. Using the
                                                                 symbol R, the mask looks like this:
                                                                 RRRRRRRRR
                                                                 876543210 */
		uint64_t dac_on_mask                 : 9;  /**< R/W - This mask is applied to the DAC_ON signals that go to the PHY, so that each byte lane can
                                                                 selectively turn off or on the signals once the master signals are enabled. Using the
                                                                 symbol D for DAC_ON, the mask looks like this:
                                                                 DDDDDDDDD
                                                                 876543210 */
		uint64_t reserved_45_45              : 1;
		uint64_t dbi_mask                    : 9;  /**< R/W - Mask for DBI/DQS\<1\>. */
		uint64_t par_mask                    : 1;  /**< R/W - Mask for PAR. */
		uint64_t act_n_mask                  : 1;  /**< R/W - Mask for ACT_N. */
		uint64_t a17_mask                    : 1;  /**< R/W - Mask for A17. */
		uint64_t reset_n_mask                : 1;  /**< R/W - Mask for RESET_L. */
		uint64_t a_mask                      : 16; /**< R/W - Mask for A\<15:0\>. */
		uint64_t ba_mask                     : 3;  /**< R/W - Mask for BA\<2:0\>. */
		uint64_t we_n_mask                   : 1;  /**< R/W - Mask for WE_N. */
		uint64_t cas_n_mask                  : 1;  /**< R/W - Mask for CAS_N. */
		uint64_t ras_n_mask                  : 1;  /**< R/W - Mask for RAS_N. */
		uint64_t odt1_mask                   : 2;  /**< R/W - Mask for ODT1. */
		uint64_t odt0_mask                   : 2;  /**< R/W - Mask for ODT0. */
		uint64_t cs1_n_mask                  : 2;  /**< R/W - Mask for CS1_N. */
		uint64_t cs0_n_mask                  : 2;  /**< R/W - Mask for CS0_N. */
		uint64_t cke_mask                    : 2;  /**< R/W - Mask for CKE*. */
#else
		uint64_t cke_mask                    : 2;
		uint64_t cs0_n_mask                  : 2;
		uint64_t cs1_n_mask                  : 2;
		uint64_t odt0_mask                   : 2;
		uint64_t odt1_mask                   : 2;
		uint64_t ras_n_mask                  : 1;
		uint64_t cas_n_mask                  : 1;
		uint64_t we_n_mask                   : 1;
		uint64_t ba_mask                     : 3;
		uint64_t a_mask                      : 16;
		uint64_t reset_n_mask                : 1;
		uint64_t a17_mask                    : 1;
		uint64_t act_n_mask                  : 1;
		uint64_t par_mask                    : 1;
		uint64_t dbi_mask                    : 9;
		uint64_t reserved_45_45              : 1;
		uint64_t dac_on_mask                 : 9;
		uint64_t ref_pin_on_mask             : 9;
#endif
	} s;
	/* struct bdk_lmcx_char_mask4_s       cn85xx; */
	/* struct bdk_lmcx_char_mask4_s       cn88xx; */
	/* struct bdk_lmcx_char_mask4_s       cn88xxp1; */
} bdk_lmcx_char_mask4_t;

static inline uint64_t BDK_LMCX_CHAR_MASK4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CHAR_MASK4(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000318ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CHAR_MASK4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CHAR_MASK4(...) bdk_lmcx_char_mask4_t
#define bustype_BDK_LMCX_CHAR_MASK4(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CHAR_MASK4(p1) (p1)
#define arguments_BDK_LMCX_CHAR_MASK4(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CHAR_MASK4(...) "LMCX_CHAR_MASK4"


/**
 * RSL - lmc#_comp_ctl2
 */
typedef union bdk_lmcx_comp_ctl2 {
	uint64_t u;
	struct bdk_lmcx_comp_ctl2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t rclk_char_mode              : 1;  /**< R/W - Reserved. INTERNAL: Select RCLK characterization mode. */
		uint64_t ddr__ptune                  : 5;  /**< RO/H - DDR PCTL from compensation circuit. The encoded value provides debug information for the
                                                                 compensation impedance on P-pullup. */
		uint64_t ddr__ntune                  : 5;  /**< RO/H - DDR NCTL from compensation circuit. The encoded value provides debug information for the
                                                                 compensation impedance on N-pulldown. */
		uint64_t ptune_offset                : 4;  /**< R/W - Ptune offset value. This is a signed value where the MSB is a sign bit, with zero
                                                                 indicating addition and one indicating subtraction. */
		uint64_t ntune_offset                : 4;  /**< R/W - Ntune offset value. This is a signed value where the MSB is a sign bit, with zero
                                                                 indicating addition and one indicating subtraction. */
		uint64_t m180                        : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Cap impedance at 180 ohm, instead of 240 ohm. */
		uint64_t byp                         : 1;  /**< R/W - Bypass mode. When set, PTUNE,NTUNE are the compensation setting. When clear,
                                                                 DDR__PTUNE,DDR__NTUNE are the compensation setting. */
		uint64_t ptune                       : 5;  /**< R/W - PCTL impedance control in bypass mode. */
		uint64_t ntune                       : 5;  /**< R/W - NCTL impedance control in bypass mode. */
		uint64_t rodt_ctl                    : 4;  /**< R/W - RODT NCTL impedance control bits. This field controls ODT values during a memory read.
                                                                   0x0 = No ODT.
                                                                   0x1 = 20 ohm.
                                                                   0x2 = 30 ohm.
                                                                   0x3 = 40 ohm.
                                                                   0x4 = 60 ohm.
                                                                   0x5 = 120 ohm.
                                                                   _ else = Reserved.

                                                                 In DDR4 mode:
                                                                   0x0 = No ODT.
                                                                   0x1 = 40 ohm.
                                                                   0x2 = 60 ohm.
                                                                   0x3 = 80 ohm.
                                                                   0x4 = 120 ohm.
                                                                   0x5 = 240 ohm.
                                                                   0x6 = 34 ohm.
                                                                   0x7 = 48 ohm.
                                                                   _ else = Reserved. */
		uint64_t control_ctl                 : 4;  /**< R/W - Drive strength control for ODT, etc. drivers.

                                                                 In DDR3 mode:
                                                                   0x1 = 24 ohm.
                                                                   0x2 = 26.67 ohm.
                                                                   0x3 = 30 ohm.
                                                                   0x4 = 34.3 ohm.
                                                                   0x5 = 40 ohm.
                                                                   0x6 = 48 ohm.
                                                                   0x7 = 60 ohm.
                                                                   _ else = Reserved.

                                                                 In DDR4 mode:
                                                                   0x0 = Reserved.
                                                                   0x1 = Reserved.
                                                                   0x2 = 26 ohm.
                                                                   0x3 = 30 ohm.
                                                                   0x4 = 34 ohm.
                                                                   0x5 = 40 ohm.
                                                                   0x6 = 48 ohm.
                                                                   _ else = Reserved. */
		uint64_t cmd_ctl                     : 4;  /**< R/W - Drive strength control for CMD/A/RESET_L drivers.

                                                                 In DDR3 mode:
                                                                   0x1 = 24 ohm.
                                                                   0x2 = 26.67 ohm.
                                                                   0x3 = 30 ohm.
                                                                   0x4 = 34.3 ohm.
                                                                   0x5 = 40 ohm.
                                                                   0x6 = 48 ohm.
                                                                   0x7 = 60 ohm.
                                                                   _ else = Reserved.

                                                                 In DDR4 mode:
                                                                   0x0 = Reserved.
                                                                   0x1 = Reserved.
                                                                   0x2 = 26 ohm.
                                                                   0x3 = 30 ohm.
                                                                   0x4 = 34 ohm.
                                                                   0x5 = 40 ohm.
                                                                   0x6 = 48 ohm.
                                                                   _ else = Reserved. */
		uint64_t ck_ctl                      : 4;  /**< R/W - "Drive strength control for DDR_CK_*_P/DDR_DIMM*_CS*_L/DDR_DIMM*_ODT_* /DDR\#_DIMM*_CKE*
                                                                 drivers.

                                                                 In DDR3 mode:
                                                                   0x1 = 24 ohm.
                                                                   0x2 = 26.67 ohm.
                                                                   0x3 = 30 ohm.
                                                                   0x4 = 34.3 ohm.
                                                                   0x5 = 40 ohm.
                                                                   0x6 = 48 ohm.
                                                                   0x7 = 60 ohm.
                                                                   _ else = Reserved.

                                                                 In DDR4 mode:
                                                                   0x0 = Reserved.
                                                                   0x1 = Reserved.
                                                                   0x2 = 26 ohm.
                                                                 0x3 = 30 ohm.
                                                                   0x4 = 34 ohm.
                                                                   0x5 = 40 ohm.
                                                                   0x6 = 48 ohm.
                                                                   _ else = Reserved." */
		uint64_t dqx_ctl                     : 4;  /**< R/W - Drive strength control for DDR_DQ* /DDR_DQS_*_P/N drivers.
                                                                 0x1 = 24 ohm.
                                                                 0x2 = 26.67 ohm.
                                                                 0x3 = 30 ohm.
                                                                 0x4 = 34.3 ohm.
                                                                 0x5 = 40 ohm.
                                                                 0x6 = 48 ohm.
                                                                 0x7 = 60 ohm.
                                                                 _ else = Reserved. */
#else
		uint64_t dqx_ctl                     : 4;
		uint64_t ck_ctl                      : 4;
		uint64_t cmd_ctl                     : 4;
		uint64_t control_ctl                 : 4;
		uint64_t rodt_ctl                    : 4;
		uint64_t ntune                       : 5;
		uint64_t ptune                       : 5;
		uint64_t byp                         : 1;
		uint64_t m180                        : 1;
		uint64_t ntune_offset                : 4;
		uint64_t ptune_offset                : 4;
		uint64_t ddr__ntune                  : 5;
		uint64_t ddr__ptune                  : 5;
		uint64_t rclk_char_mode              : 1;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_lmcx_comp_ctl2_s        cn85xx; */
	/* struct bdk_lmcx_comp_ctl2_s        cn88xx; */
	/* struct bdk_lmcx_comp_ctl2_s        cn88xxp1; */
} bdk_lmcx_comp_ctl2_t;

static inline uint64_t BDK_LMCX_COMP_CTL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_COMP_CTL2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001B8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_COMP_CTL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_COMP_CTL2(...) bdk_lmcx_comp_ctl2_t
#define bustype_BDK_LMCX_COMP_CTL2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_COMP_CTL2(p1) (p1)
#define arguments_BDK_LMCX_COMP_CTL2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_COMP_CTL2(...) "LMCX_COMP_CTL2"


/**
 * RSL - lmc#_config
 *
 * This register controls certain parameters required for memory configuration. Note the
 * following:
 * * Priority order for hardware write operations to
 * LMC()_CONFIG/LMC()_FADR/LMC()_ECC_SYND: DED error \> SEC error.
 * * The self-refresh entry sequence(s) power the DLL up/down (depending on
 * LMC()_MODEREG_PARAMS0[DLL]) when LMC()_CONFIG[SREF_WITH_DLL] is set.
 * * Prior to the self-refresh exit sequence, LMC()_MODEREG_PARAMS0 should be reprogrammed
 * (if needed) to the appropriate values.
 *
 * See LMC Initialization Sequence for the LMC bring-up sequence.
 */
typedef union bdk_lmcx_config {
	uint64_t u;
	struct bdk_lmcx_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t lrdimm_ena                  : 1;  /**< R/W - Load Reduced DIMM Enable. When set allows the use of JEDEC DDR4 LRDIMMs. */
		uint64_t bg2_enable                  : 1;  /**< R/W - BG2 pin is active for DDR4 mode. Only has an effect when LMC()_CONFIG[MODEDDR4] = 1.
                                                                 Typically only cleared for DDR4 *16 devices, where there is no BG2 pin on the device. */
		uint64_t mode_x4dev                  : 1;  /**< R/W - DDR *4 device mode. */
		uint64_t mode32b                     : 1;  /**< R/W - 32-bit datapath mode. When set, only 32 DQ pins are used. */
		uint64_t scrz                        : 1;  /**< R/W1S/H - Hide LMC()_SCRAMBLE_CFG0 and LMC()_SCRAMBLE_CFG1 when set. */
		uint64_t early_unload_d1_r1          : 1;  /**< R/W - Reserved, MBZ.  INTERNAL:  When set, unload the PHY silo one cycle early for Rank 3 reads.
                                                                 The recommended EARLY_UNLOAD_D1_R1 value can be calculated after the final
                                                                 LMC()_RLEVEL_RANK3[BYTE*] values are selected (as part of read-leveling initialization).
                                                                 Then, determine the largest read-leveling setting for rank 3 (i.e. calculate
                                                                 maxset=MAX(LMC()_RLEVEL_RANK3[BYTEi]) across all i), then set EARLY_UNLOAD_D1_R1 when the
                                                                 low two bits of this largest setting is not 3 (i.e. EARLY_UNLOAD_D1_R1 = (maxset\<1:0\>
                                                                 !=3)). */
		uint64_t early_unload_d1_r0          : 1;  /**< R/W - Reserved, MBZ.  INTERNAL:  When set, unload the PHY silo one cycle early for Rank 2 reads.
                                                                 The recommended EARLY_UNLOAD_D1_RO value can be calculated after the final
                                                                 LMC()_RLEVEL_RANK2[BYTE*] values are selected (as part of read-leveling initialization).
                                                                 Then, determine the largest read-leveling setting for rank 2 (i.e. calculate
                                                                 maxset=MAX(LMC()_RLEVEL_RANK2[BYTEi]) across all i), then set EARLY_UNLOAD_D1_RO when the
                                                                 low two bits of this largest setting is not 3 (i.e. EARLY_UNLOAD_D1_RO = (maxset\<1:0\>
                                                                 !=3)). */
		uint64_t early_unload_d0_r1          : 1;  /**< R/W - Reserved, MBZ.  INTERNAL:  When set, unload the PHY silo one cycle early for Rank 1 reads.
                                                                 The recommended EARLY_UNLOAD_D0_R1 value can be calculated after the final
                                                                 LMC()_RLEVEL_RANK1[BYTE*] values are selected (as part of read-leveling initialization).
                                                                 Then, determine the largest read-leveling setting for rank 1 (i.e. calculate
                                                                 maxset=MAX(LMC()_RLEVEL_RANK1[BYTEi]) across all i), then set EARLY_UNLOAD_D0_R1 when the
                                                                 low two bits of this largest setting is not 3 (i.e. EARLY_UNLOAD_D0_R1 = (maxset\<1:0\>
                                                                 !=3)). */
		uint64_t early_unload_d0_r0          : 1;  /**< R/W - Reserved, MBZ.  INTERNAL:  When set, unload the PHY silo one cycle early for Rank 0 reads.
                                                                 The recommended EARLY_UNLOAD_D0_R0 value can be calculated after the final
                                                                 LMC()_RLEVEL_RANK0[BYTE*] values are selected (as part of read-leveling initialization).
                                                                 Then, determine the largest read-leveling setting for rank 0 (i.e. calculate
                                                                 maxset=MAX(LMC()_RLEVEL_RANK0[BYTEi]) across all i), then set EARLY_UNLOAD_D0_R0 when the
                                                                 low two bits of this largest setting is not 3 (i.e. EARLY_UNLOAD_D0_R0 = (maxset\<1:0\>
                                                                 !=3)). */
		uint64_t init_status                 : 4;  /**< RO/H - Indicates status of initialization. INIT_STATUS[n] = 1 implies rank n has been
                                                                 initialized.
                                                                 Software must set necessary RANKMASK bits before executing the initialization sequence
                                                                 using LMC()_SEQ_CTL. If the rank has been selected for init with the RANKMASK bits,
                                                                 the INIT_STATUS bits will be set after successful initialization and after self-refresh
                                                                 exit. INIT_STATUS determines the chip-selects that assert during refresh, ZQCS, precharge
                                                                 power-down entry/exit, and self-refresh entry SEQ_SELs. */
		uint64_t mirrmask                    : 4;  /**< R/W - "Mask determining which ranks are address-mirrored.
                                                                 MIRRMASK\<n\> = 1 means Rank n addresses are mirrored for
                                                                 0 \<= n \<= 3.
                                                                 In DDR3, a mirrored read/write operation has the following differences:
                                                                 * DDR\#_BA\<1\> is swapped with DDR\#_BA\<0\>.
                                                                 * DDR\#_A\<8\> is swapped with DDR\#_A\<7\>.
                                                                 * DDR\#_A\<6\> is swapped with DDR\#_A\<5\>.
                                                                 * DDR\#_A\<4\> is swapped with DDR\#_A\<3\>.

                                                                 When RANK_ENA = 0, MIRRMASK\<1\> MBZ.

                                                                 In DDR4, a mirrored read/write operation has the following differences:
                                                                 * DDR\#_BG\<1\> is swapped with DDR\#_BG\<0\>.
                                                                 * DDR\#_BA\<1\> is swapped with DDR\#_BA\<0\>.
                                                                 * DDR\#_A\<13\> is swapped with DDR\#_A\<11\>.
                                                                 * DDR\#_A\<8\> is swapped with DDR\#_A\<7\>.
                                                                 * DDR\#_A\<6\> is swapped with DDR\#_A\<5\>.
                                                                 * DDR\#_A\<4\> is swapped with DDR\#_A\<3\>.

                                                                 For CN70XX, MIRRMASK\<3:2\> MBZ.
                                                                 * When RANK_ENA = 0, MIRRMASK\<1\> MBZ." */
		uint64_t rankmask                    : 4;  /**< R/W - Mask to select rank to be leveled/initialized. To write-level/read-level/initialize rank
                                                                 i, set RANKMASK\<i\>:

                                                                 \<pre\>
                                                                               RANK_ENA = 1   RANK_ENA = 0
                                                                 RANKMASK\<0\> = DIMM0_CS0      DIMM0_CS0
                                                                 RANKMASK\<1\> = DIMM0_CS1      MBZ
                                                                 RANKMASK\<2\> = DIMM1_CS0      DIMM1_CS0
                                                                 RANKMASK\<3\> = DIMM1_CS1      MBZ
                                                                 \</pre\>

                                                                 For read/write leveling, each rank has to be leveled separately, so RANKMASK should only
                                                                 have one bit set. RANKMASK is not used during self-refresh entry/exit and precharge power-
                                                                 down entry/exit instruction sequences. When RANK_ENA = 0, RANKMASK\<1\> and RANKMASK\<3\> MBZ. */
		uint64_t rank_ena                    : 1;  /**< R/W - "RANK enable (for use with dual-rank DIMMs).
                                                                 * For dual-rank DIMMs, the RANK_ENA bit will enable the drive of the DDR\#_DIMM*_CS*_L and
                                                                 ODT_\<1:0\> pins differently based on the (PBANK_LSB - 1) address bit.
                                                                 * Write 0 for SINGLE ranked DIMMs." */
		uint64_t sref_with_dll               : 1;  /**< R/W - Self-refresh entry/exit write mode registers. When set, self-refresh entry sequence writes
                                                                 MR2 and MR1 (in this order, in all ranks), and self-refresh exit sequence writes MR1, MR0,
                                                                 MR2, and MR3 (in this order, for all ranks). The write operations occur before self-
                                                                 refresh entry, and after self-refresh exit. When clear, self-refresh entry and exit
                                                                 instruction sequences do not write any mode registers in the DDR3/4 parts. */
		uint64_t early_dqx                   : 1;  /**< R/W - Set this bit to send DQx signals one CK cycle earlier for the case when the shortest DQx
                                                                 lines have a larger delay than the CK line. */
		uint64_t ref_zqcs_int                : 22; /**< R/W - Refresh interval is represented in number of 512 CK cycle increments. ZQCS interval is
                                                                 represented in a number of refresh intervals. A refresh sequence is triggered when bits
                                                                 \<24:18\> are equal to 0x0, and a ZQCS sequence is triggered when \<39:18\> are equal to 0x0.

                                                                 The ZQCS timer only decrements when the refresh timer is 0.

                                                                 Program \<24:18\> to RND-DN(TREFI/clkPeriod/512).

                                                                 A value of 0 in bits \<24:18\> will effectively turn off refresh.

                                                                 Program \<36:25\> to (RND-DN(ZQCS_Period / Refresh_Period) - 1), where Refresh_Period is the
                                                                 effective period programmed in bits \<24:18\>. Note that this value should always be greater
                                                                 than 32, to account for resistor calibration delays.

                                                                 000_00000000_0000000: Reserved

                                                                 Max Refresh interval = 127 * 512= 65024 CK cycles.

                                                                 Max ZQCS interval = 32768 * 127 * 512 = 2130706432 CK cycles.

                                                                 If refresh interval is programmed to ~8us, max ZQCS interval is ~262ms, or ~4 ZQCS
                                                                 operations per second.
                                                                 LMC()_CONFIG[INIT_STATUS] determines which ranks receive the REF / ZQCS. LMC does not
                                                                 send any refreshes / ZQCS's when LMC()_CONFIG[INIT_STATUS]=0. */
		uint64_t reset                       : 1;  /**< R/W - Reset one-shot pulse for LMC()_OPS_CNT, LMC()_IFB_CNT, and LMC()_DCLK_CNT
                                                                 CSRs.
                                                                 To cause the reset, software writes this to a 1, then rewrites it to a 0. */
		uint64_t ecc_adr                     : 1;  /**< R/W - Include memory reference address in the ECC calculation.
                                                                 0 = disabled, 1 = enabled. */
		uint64_t forcewrite                  : 4;  /**< R/W - Force the oldest outstanding write to complete after having waited for 2^FORCEWRITE CK
                                                                 cycles. 0 = disabled. */
		uint64_t idlepower                   : 3;  /**< R/W - Enter precharge power-down mode after the memory controller has been idle for
                                                                 2^(2+IDLEPOWER) CK cycles. 0 = disabled.

                                                                 This field should only be programmed after initialization.
                                                                 LMC()_MODEREG_PARAMS0[PPD] determines whether the DRAM DLL is disabled during the
                                                                 precharge power-down. */
		uint64_t pbank_lsb                   : 4;  /**< R/W - DIMM address bit select. Reverting to the explanation for ROW_LSB, PBANK_LSB would be:
                                                                 ROW_LSB bit + num_rowbits + num_rankbits

                                                                 Decoding for PBANK_LSB:

                                                                 0x0: DIMM = mem_adr\<28\>; if RANK_ENA=1, rank = mem_adr\<27\>.
                                                                 0x1: DIMM = mem_adr\<29\>; if RANK_ENA=1, rank = mem_adr\<28\>.
                                                                 0x2: DIMM = mem_adr\<30\>; if RANK_ENA=1, rank = mem_adr\<29\>.
                                                                 0x3: DIMM = mem_adr\<31\>; if RANK_ENA=1, rank = mem_adr\<30\>.
                                                                 0x4: DIMM = mem_adr\<32\>; if RANK_ENA=1, rank = mem_adr\<31\>.
                                                                 0x5: DIMM = mem_adr\<33\>; if RANK_ENA=1, rank = mem_adr\<32\>.
                                                                 0x6: DIMM = mem_adr\<34\>; if RANK_ENA=1, rank = mem_adr\<33\>.
                                                                 0x7: DIMM = mem_adr\<35\>; if RANK_ENA=1, rank = mem_adr\<34\>.
                                                                 0x8: DIMM = mem_adr\<36\>; if RANK_ENA=1, rank = mem_adr\<35\>.
                                                                 0x9: DIMM = mem_adr\<37\>; if RANK_ENA=1, rank = mem_adr\<36\>.
                                                                 0xA: DIMM = 0;           if RANK_ENA=1, rank = mem_adr\<37\>.
                                                                 0xB-0xF: Reserved.

                                                                 For example, for a DIMM made of Samsung's K4B1G0846C-F7 1Gb (16M * 8 bit * 8 bank)
                                                                 parts, the column address width = 10, so with 10b of col, 3b of bus, 3b of bank, ROW_LSB =
                                                                 16. So, row = mem_adr\<29:16\>.

                                                                 With RANK_ENA = 0, PBANK_LSB = 2.
                                                                 With RANK_ENA = 1, PBANK_LSB = 3.

                                                                 TBD for interfacing with 8H 3DS, regardless of RANK_ENA value, set this 0xA. */
		uint64_t row_lsb                     : 3;  /**< R/W - "Row address bit select.
                                                                 0x0 = Address bit 14 is LSB.
                                                                 0x1 = Address bit 15 is LSB.
                                                                 0x2 = Address bit 16 is LSB.
                                                                 0x3 = Address bit 17 is LSB.
                                                                 0x4 = Address bit 18 is LSB.
                                                                 0x5 = Address bit 19 is LSB.
                                                                 0x6 = Address bit 20 is LSB.
                                                                 0x6 = Reserved.

                                                                 Encoding used to determine which memory address bit position represents the low order DDR
                                                                 ROW address. The processor's memory address\<34:7\> needs to be translated to DRAM addresses
                                                                 (bnk,row,col,rank and DIMM) and that is a function of the following:
                                                                 * Datapath width (64).
                                                                 * Number of banks (8).
                                                                 * Number of column bits of the memory part--specified indirectly by this register.
                                                                 * Number of row bits of the memory part--specified indirectly by PBANK_LSB.
                                                                 * Number of ranks in a DIMM--specified by RANK_ENA.
                                                                 * Number of DIMMs in the system by the register below (PBANK_LSB).

                                                                 Col address starts from mem_addr[3] for 64b (8Bytes) DQ width. ROW_LSB is mem_adr[15] for
                                                                 64b mode. Therefore, the ROW_LSB parameter should be set to 001 (64b).

                                                                 For example, for a DIMM made of Samsung's K4B1G0846C-F7 1GB (16M * 8 bit * 8 bank)
                                                                 parts, the column address width = 10, so with 10b of col, 3b of bus, 3b of bank, ROW_LSB =
                                                                 16. So, row = mem_adr\<29:16\>.

                                                                 Refer to Cache-block Read Transaction Example, Cache-block Read Transaction Example." */
		uint64_t ecc_ena                     : 1;  /**< R/W - ECC enable. When set, enables the 8b ECC check/correct logic. Should be 1 when used with
                                                                 DIMMs with ECC; 0, otherwise.

                                                                 * When this mode is turned on, DQ\<71:64\> on write operations contains the ECC code
                                                                 generated for the 64 bits of data which will be written in the memory. Later on read
                                                                 operations, will be used to check for single-bit error (which will be auto-corrected) and
                                                                 double-bit error (which will be reported).

                                                                 * When not turned on, DQ\<71:64\> are driven to 0. Please refer to SEC_ERR, DED_ERR,
                                                                 LMC()_FADR, and LMC()_ECC_SYND registers for diagnostics information when there is
                                                                 an error. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t ecc_ena                     : 1;
		uint64_t row_lsb                     : 3;
		uint64_t pbank_lsb                   : 4;
		uint64_t idlepower                   : 3;
		uint64_t forcewrite                  : 4;
		uint64_t ecc_adr                     : 1;
		uint64_t reset                       : 1;
		uint64_t ref_zqcs_int                : 22;
		uint64_t early_dqx                   : 1;
		uint64_t sref_with_dll               : 1;
		uint64_t rank_ena                    : 1;
		uint64_t rankmask                    : 4;
		uint64_t mirrmask                    : 4;
		uint64_t init_status                 : 4;
		uint64_t early_unload_d0_r0          : 1;
		uint64_t early_unload_d0_r1          : 1;
		uint64_t early_unload_d1_r0          : 1;
		uint64_t early_unload_d1_r1          : 1;
		uint64_t scrz                        : 1;
		uint64_t mode32b                     : 1;
		uint64_t mode_x4dev                  : 1;
		uint64_t bg2_enable                  : 1;
		uint64_t lrdimm_ena                  : 1;
#endif
	} s;
	/* struct bdk_lmcx_config_s           cn85xx; */
	/* struct bdk_lmcx_config_s           cn88xx; */
	/* struct bdk_lmcx_config_s           cn88xxp1; */
} bdk_lmcx_config_t;

static inline uint64_t BDK_LMCX_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CONFIG(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000188ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CONFIG(...) bdk_lmcx_config_t
#define bustype_BDK_LMCX_CONFIG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CONFIG(p1) (p1)
#define arguments_BDK_LMCX_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CONFIG(...) "LMCX_CONFIG"


/**
 * RSL - lmc#_control
 */
typedef union bdk_lmcx_control {
	uint64_t u;
	struct bdk_lmcx_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t scramble_ena                : 1;  /**< R/W - When set, will enable the scramble/descramble logic. */
		uint64_t thrcnt                      : 12; /**< RO/H - Fine count. */
		uint64_t persub                      : 8;  /**< R/W - Offset for DFA rate-matching. */
		uint64_t thrmax                      : 4;  /**< R/W - Fine rate matching max bucket size. In conjunction with the coarse rate matching logic,
                                                                 the fine rate matching logic gives software the ability to prioritize DFA reads over L2C
                                                                 writes. Higher PERSUB values result in a lower DFA read bandwidth.

                                                                 0x0 = Reserved. */
		uint64_t crm_cnt                     : 5;  /**< RO/H - Coarse count. */
		uint64_t crm_thr                     : 5;  /**< R/W - Coarse rate matching threshold. */
		uint64_t crm_max                     : 5;  /**< R/W - Coarse rate matching max bucket size. The coarse rate matching logic is used to control
                                                                 the bandwidth allocated to DFA reads. CRM_MAX is subdivided into two regions with DFA
                                                                 reads being preferred over LMC reads/writes when CRM_CNT \< CRM_THR. CRM_CNT increments by
                                                                 1 when a DFA read is slotted and by 2 when a LMC read/write is slotted, and rolls over
                                                                 when CRM_MAX is reached.

                                                                 0x0 = Reserved. */
		uint64_t rodt_bprch                  : 1;  /**< R/W - When set, the turn-off time for the ODT pin during a RD command is delayed an additional CK cycle. */
		uint64_t wodt_bprch                  : 1;  /**< R/W - When set, the turn-off time for the ODT pin during a WR command is delayed an additional CK cycle. */
		uint64_t bprch                       : 2;  /**< R/W - "Back porch enable. When set, the turn-on time for the default DDR\#_DQ* /DDR\#_DQS_*_P/N
                                                                 drivers is delayed an additional BPRCH CK cycles.
                                                                 0x0 = 0 CK cycles.
                                                                 0x1 = 1 CK cycles.
                                                                 0x2 = 2 CK cycles.
                                                                 0x3 = 3 CK cycles." */
		uint64_t ext_zqcs_dis                : 1;  /**< R/W - Disable (external) auto-ZQCS calibration. When clear, LMC runs external ZQ calibration
                                                                 every LMC()_CONFIG [REF_ZQCS_INT] CK cycles. */
		uint64_t int_zqcs_dis                : 1;  /**< R/W - Disable (internal) auto-ZQCS calibration. When clear, LMC runs internal ZQ calibration
                                                                 every LMC()_CONFIG [REF_ZQCS_INT] CK cycles. */
		uint64_t auto_dclkdis                : 1;  /**< R/W - When 1, LMC automatically shuts off its internal clock to conserve power when there is no
                                                                 traffic. Note that this has no effect on the DDR3/DDR4 PHY and pads clocks. */
		uint64_t xor_bank                    : 1;  /**< R/W - XOR the bank bits.
                                                                 0: bank\<2:0\> = address\<9:7\>.
                                                                 1: bank\<2:0\> = address\<9:7\> ^ address\<14:12\>. */
		uint64_t max_write_batch             : 4;  /**< R/W - Maximum number of consecutive write operations to service before forcing read operations
                                                                 to interrupt. */
		uint64_t nxm_write_en                : 1;  /**< R/W - NXM write mode. When clear, LMC discards write operations to addresses that don't exist in
                                                                 the DRAM (as defined by LMC()_NXM configuration). When set, LMC completes write
                                                                 operations to addresses that don't exist in the DRAM at an aliased address. */
		uint64_t elev_prio_dis               : 1;  /**< R/W - Disable elevate priority logic. When set, write operations are sent in regardless of
                                                                 priority information from L2C. */
		uint64_t inorder_wr                  : 1;  /**< R/W - Send write operations in order (regardless of priority). */
		uint64_t inorder_rd                  : 1;  /**< R/W - Send read operations in order (regardless of priority). */
		uint64_t throttle_wr                 : 1;  /**< R/W - When set, use at most one IFB for write operations. */
		uint64_t throttle_rd                 : 1;  /**< R/W - When set, use at most one IFB for read operations. */
		uint64_t fprch2                      : 2;  /**< R/W - "Front porch enable. When set, the turn-off time for the default DDR\#_DQ* /DDR\#_DQS_*_P/N
                                                                 drivers is FPRCH2 CKs earlier.
                                                                 0x0 = 0 CK cycles.
                                                                 0x1 = 1 CK cycles.
                                                                 0x2 = 2 CK cycles.
                                                                 0x3 = Reserved." */
		uint64_t pocas                       : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Enable the posted CAS feature of DDR3. This bit must be
                                                                 set whenever LMC()_MODEREG_PARAMS0[AL]!=0. */
		uint64_t ddr2t                       : 1;  /**< R/W - Turn on the DDR 2T mode. 2 CK-cycle window for CMD and address. This mode helps relieve
                                                                 setup time pressure on the address and command bus which nominally have a very large
                                                                 fanout. Please refer to Micron's tech note tn_47_01 titled DDR2-533 Memory Design Guide
                                                                 for Two Dimm Unbuffered Systems for physical details. */
		uint64_t bwcnt                       : 1;  /**< R/W - Bus utilization counter clear. Clears the LMC()_OPS_CNT, LMC()_IFB_CNT, and
                                                                 LMC()_DCLK_CNT registers. To clear the CSRs, software should first write this field to
                                                                 a one, then write this field to a zero. */
		uint64_t rdimm_ena                   : 1;  /**< R/W - Registered DIMM Enable. When set allows the use of JEDEC Registered DIMMs which require
                                                                 address and control bits to be registered in the controller. */
#else
		uint64_t rdimm_ena                   : 1;
		uint64_t bwcnt                       : 1;
		uint64_t ddr2t                       : 1;
		uint64_t pocas                       : 1;
		uint64_t fprch2                      : 2;
		uint64_t throttle_rd                 : 1;
		uint64_t throttle_wr                 : 1;
		uint64_t inorder_rd                  : 1;
		uint64_t inorder_wr                  : 1;
		uint64_t elev_prio_dis               : 1;
		uint64_t nxm_write_en                : 1;
		uint64_t max_write_batch             : 4;
		uint64_t xor_bank                    : 1;
		uint64_t auto_dclkdis                : 1;
		uint64_t int_zqcs_dis                : 1;
		uint64_t ext_zqcs_dis                : 1;
		uint64_t bprch                       : 2;
		uint64_t wodt_bprch                  : 1;
		uint64_t rodt_bprch                  : 1;
		uint64_t crm_max                     : 5;
		uint64_t crm_thr                     : 5;
		uint64_t crm_cnt                     : 5;
		uint64_t thrmax                      : 4;
		uint64_t persub                      : 8;
		uint64_t thrcnt                      : 12;
		uint64_t scramble_ena                : 1;
#endif
	} s;
	/* struct bdk_lmcx_control_s          cn85xx; */
	/* struct bdk_lmcx_control_s          cn88xx; */
	/* struct bdk_lmcx_control_s          cn88xxp1; */
} bdk_lmcx_control_t;

static inline uint64_t BDK_LMCX_CONTROL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_CONTROL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000190ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_CONTROL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_CONTROL(...) bdk_lmcx_control_t
#define bustype_BDK_LMCX_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_CONTROL(p1) (p1)
#define arguments_BDK_LMCX_CONTROL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_CONTROL(...) "LMCX_CONTROL"


/**
 * RSL - lmc#_dbtrain_ctl
 *
 * This register contains control bits that are used during the Data Buffer
 * training sequence in DDR4 LRDIMM mode. When one of the data buffer training
 * sequence is initiated, it uses the contents of this register to control
 * its operation.
 */
typedef union bdk_lmcx_dbtrain_ctl {
	uint64_t u;
	struct bdk_lmcx_dbtrain_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t db_output_impedance         : 3;  /**< R/W - Host Interface DQ/DQS Output Driver Impedance control.
                                                                 This is the default value used during Host Interface Write Leveling in LRDIMM
                                                                 environment, i.e., CONFIG[LRDIMM_ENA] = 1, SEQ_CTL[SEQ_SEL] = 0x6.
                                                                 0x0 = RZQ/6 (40 ohm).
                                                                 0x1 = RZQ/7 (34 ohm).
                                                                 0x2 = RZQ/5 (48 ohm).
                                                                 0x3-0x7 = Reserved. */
		uint64_t db_sel                      : 1;  /**< R/W - Used when running Host Interface Write Leveling.
                                                                 0 = selects DIMM0's Data Buffer.
                                                                 1 = selects DIMM1's Data Buffer. */
		uint64_t tccd_sel                    : 1;  /**< R/W - When set, the sequence uses MODEREG_PARAMS3[TCCD_L] to space out
                                                                 back-to-back read commands. Otherwise it will space out back-to-back
                                                                 reads with a default value of 4 cycles.

                                                                 While in DRAM MPR mode, reads from Page 0 may use tCCD_S or tCCD_L.
                                                                 Reads from Pages 1, 2 or 3 however must use tCCD_L, thereby requring
                                                                 this bit to be set. */
		uint64_t rw_train                    : 1;  /**< R/W - When set, the DBTRAIN sequence will perform a Write to the DRAM
                                                                 memory array using burst patern that are set in the CSRs
                                                                 LMC()_GENERAL_PURPOSE0[DATA]\<61:0\>, LMC()_GENERAL_PURPOSE1[DATA]\<61:0\> and
                                                                 LMC()_GENERAL_PURPOSE2[DATA]\<15:0\>.

                                                                 This burst pattern gets shifted by one byte at every cycle.
                                                                 The sequence will then do the reads to the same location and compare
                                                                 the data coming back with this pattern.
                                                                 The bit-wise comparison result gets stored in
                                                                 LMC()_MPR_DATA0[MPR_DATA]\<63:0\> and LMC()_MPR_DATA1[MPR_DATA]\<7:0\>. */
		uint64_t read_dq_count               : 7;  /**< R/W - The amount of cycles until a pulse is issued to sample the DQ into the
                                                                 MPR register. This bits control the timing of when to sample the data
                                                                 buffer training result. */
		uint64_t read_cmd_count              : 5;  /**< R/W - The amount of Read Commands to be sent during the data buffer training.
                                                                 This can be set to zero in which case the sequence does not send any
                                                                 Read commands to accommodate for the DWL training mode. */
		uint64_t write_ena                   : 1;  /**< R/W - Enables the write operation. This is mainly used to accomplish the MWD
                                                                 training sequence of the data buffer.
                                                                 DBTRAIN_CTL[ACTIVATE] must be set to 1 for this to take effect. */
		uint64_t activate                    : 1;  /**< R/W - Enables the activate command during the data buffer training sequence. */
		uint64_t prank                       : 2;  /**< R/W - Physical Rank bits for Read/Write/Activate operation during the data buffer
                                                                 training. INTERNAL: FIXME, needs to be 4 bits for the case of DDP DIMM. */
		uint64_t lrank                       : 3;  /**< R/W - Logical Rank bits for Read/Write/Activate operation during the data buffer
                                                                 training. */
		uint64_t row_a                       : 18; /**< R/W - The row address for the Activate command during dbtrain. */
		uint64_t bg                          : 2;  /**< R/W - The Bank Group that the commands are directed to while in data buffer
                                                                 training sequence. */
		uint64_t ba                          : 2;  /**< R/W - The bank address for the commands while in data buffer training sequence. */
		uint64_t column_a                    : 13; /**< R/W - Column address for the Read/Write operation during the data buffer
                                                                 training. */
#else
		uint64_t column_a                    : 13;
		uint64_t ba                          : 2;
		uint64_t bg                          : 2;
		uint64_t row_a                       : 18;
		uint64_t lrank                       : 3;
		uint64_t prank                       : 2;
		uint64_t activate                    : 1;
		uint64_t write_ena                   : 1;
		uint64_t read_cmd_count              : 5;
		uint64_t read_dq_count               : 7;
		uint64_t rw_train                    : 1;
		uint64_t tccd_sel                    : 1;
		uint64_t db_sel                      : 1;
		uint64_t db_output_impedance         : 3;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_lmcx_dbtrain_ctl_s      cn85xx; */
	/* struct bdk_lmcx_dbtrain_ctl_s      cn88xx; */
	/* struct bdk_lmcx_dbtrain_ctl_s      cn88xxp1; */
} bdk_lmcx_dbtrain_ctl_t;

static inline uint64_t BDK_LMCX_DBTRAIN_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DBTRAIN_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880003F8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DBTRAIN_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DBTRAIN_CTL(...) bdk_lmcx_dbtrain_ctl_t
#define bustype_BDK_LMCX_DBTRAIN_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DBTRAIN_CTL(p1) (p1)
#define arguments_BDK_LMCX_DBTRAIN_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DBTRAIN_CTL(...) "LMCX_DBTRAIN_CTL"


/**
 * RSL - lmc#_dclk_cnt
 */
typedef union bdk_lmcx_dclk_cnt {
	uint64_t u;
	struct bdk_lmcx_dclk_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dclkcnt                     : 64; /**< RO/H - Performance counter. A 64-bit counter that increments every CK cycle. */
#else
		uint64_t dclkcnt                     : 64;
#endif
	} s;
	/* struct bdk_lmcx_dclk_cnt_s         cn85xx; */
	/* struct bdk_lmcx_dclk_cnt_s         cn88xx; */
	/* struct bdk_lmcx_dclk_cnt_s         cn88xxp1; */
} bdk_lmcx_dclk_cnt_t;

static inline uint64_t BDK_LMCX_DCLK_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DCLK_CNT(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001E0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DCLK_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DCLK_CNT(...) bdk_lmcx_dclk_cnt_t
#define bustype_BDK_LMCX_DCLK_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DCLK_CNT(p1) (p1)
#define arguments_BDK_LMCX_DCLK_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DCLK_CNT(...) "LMCX_DCLK_CNT"


/**
 * RSL - lmc#_ddr4_dimm_ctl
 *
 * Bits 0-21 of this register is used only when LMC()_CONTROL[RDIMM_ENA] = 1.
 *
 * Bits 22-27 is used only when LMC()_CONFIG[LRDIMM_ENA] = 1 AND
 * LMC()_MR_MPR_CTL[MR_WR_PBA_ENABLE] = 1.
 *
 * During an RCW initialization sequence, bits 0-21 controls LMC's write
 * operations to the extended DDR4 control words in the JEDEC standard
 * registering clock driver on an RDIMM.
 *
 * During PBA mode of an MRW sequence, bits 22-27 controls the Buffer Configuration
 * Control Word F0BC1x settings during the BCW write.
 */
typedef union bdk_lmcx_ddr4_dimm_ctl {
	uint64_t u;
	struct bdk_lmcx_ddr4_dimm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t rank_timing_enable          : 1;  /**< R/W - Package Rank Timing Alignment Enable bit for the DDR4 LRDIMM Buffer Configuration Control
                                                                 Word F0BC1x DA[7]. Used during PBA BCW Write through the MRW sequence. */
		uint64_t bodt_trans_mode             : 1;  /**< R/W - BODT input handling in Transparent Mode for the DDR4 LRDIMM Buffer Conifguration Control
                                                                 Word F0BC1x. Used during PBA BCW Write through the MRW sequence. */
		uint64_t trans_mode_ena              : 1;  /**< R/W - Transparent Mode Enable bit for DDR4 LRDIMM Buffer Configuration Control Word
                                                                 F0BC1x DA[5]. Used during PBA BCW Write through the MRW sequence. */
		uint64_t read_preamble_mode          : 1;  /**< R/W - Read Preamble Training Mode Enable bit for DDR4 LRDIMM Buffer Configuration Control Word
                                                                 F0BC1x DA[4]. Used during PBA BCW Write through the MRW sequence. */
		uint64_t buff_config_da3             : 1;  /**< R/W - Reserved setting value in F0BC1x DA3. Used during PBA BCW Write through the MRW sequence. */
		uint64_t mpr_over_ena                : 1;  /**< R/W - MPR Override Mode Enable bit for the DDR4 LRDIMM Buffer Configuration Control Word
                                                                 F0BC1x DA[1]. Used during PBA BCW Write through the MRW sequence. */
		uint64_t ddr4_dimm1_wmask            : 11; /**< R/W - DIMM1 write mask. If (DIMM1_WMASK[n] = 1), write DIMM1.RCn. */
		uint64_t ddr4_dimm0_wmask            : 11; /**< R/W - DIMM0 write mask. If (DIMM0_WMASK[n] = 1), write DIMM0.RCn. */
#else
		uint64_t ddr4_dimm0_wmask            : 11;
		uint64_t ddr4_dimm1_wmask            : 11;
		uint64_t mpr_over_ena                : 1;
		uint64_t buff_config_da3             : 1;
		uint64_t read_preamble_mode          : 1;
		uint64_t trans_mode_ena              : 1;
		uint64_t bodt_trans_mode             : 1;
		uint64_t rank_timing_enable          : 1;
		uint64_t reserved_28_63              : 36;
#endif
	} s;
	/* struct bdk_lmcx_ddr4_dimm_ctl_s    cn85xx; */
	/* struct bdk_lmcx_ddr4_dimm_ctl_s    cn88xx; */
	/* struct bdk_lmcx_ddr4_dimm_ctl_s    cn88xxp1; */
} bdk_lmcx_ddr4_dimm_ctl_t;

static inline uint64_t BDK_LMCX_DDR4_DIMM_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DDR4_DIMM_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880003F0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DDR4_DIMM_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DDR4_DIMM_CTL(...) bdk_lmcx_ddr4_dimm_ctl_t
#define bustype_BDK_LMCX_DDR4_DIMM_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DDR4_DIMM_CTL(p1) (p1)
#define arguments_BDK_LMCX_DDR4_DIMM_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DDR4_DIMM_CTL(...) "LMCX_DDR4_DIMM_CTL"


/**
 * RSL - lmc#_ddr_pll_ctl
 *
 * This register controls the DDR_CK frequency. For details, refer to CK Speed Programming. See
 * LMC Initialization Sequence for the initialization sequence.
 * DDR PLL Bringup sequence:
 *
 * 1. Write CLKF, DDR_PS_EN, DFM_PS_EN, DIFFAMP, CPS, CPB. If test mode is going to be activated,
 * then also write jtg__ddr_pll_tm_en1, jtg__ddr_pll_tm_en2, jtg__ddr_pll_tm_en3,
 * jtg__ddr_pll_tm_en4, jtg__dfa_pll_tm_en1, jtg__dfa_pll_tm_en2, jtg__dfa_pll_tm_en3,
 * jtg__dfa_pll_tm_en4, JTAG_TEST_MODE.
 *
 * 2. Wait 128 ref clock cycles (7680 rclk cycles).
 *
 * 3. Write 1 to RESET_N.
 *
 * 4. Wait 1152 ref clocks (1152*16 rclk cycles).
 *
 * 5. Write 0 to DDR_DIV_RESET and DFM_DIV_RESET.
 *
 * 6. Wait 10 ref clock cycles (160 rclk cycles) before bringing up the DDR interface
 * If test mode is going to be activated, wait an additional 8191 ref clocks (8191*16 rclk+
 * cycles) to allow PLL clock alignment.
 */
typedef union bdk_lmcx_ddr_pll_ctl {
	uint64_t u;
	struct bdk_lmcx_ddr_pll_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_45_63              : 19;
		uint64_t dclk_alt_refclk_sel         : 1;  /**< R/W - Select alternate reference clock for DCLK PLL. */
		uint64_t bwadj                       : 12; /**< R/W - Bandwidth control for DCLK PLLs. */
		uint64_t dclk_invert                 : 1;  /**< R/W - Invert dclk that feeds LMC/DDR at the south side of the chip. */
		uint64_t phy_dcok                    : 1;  /**< R/W - Set to power up PHY logic after setting LMC()_DDR_PLL_CTL[DDR4_MODE]. */
		uint64_t ddr4_mode                   : 1;  /**< R/W - DDR4 mode select: 1 = DDR4, 0 = DDR3. */
		uint64_t pll_fbslip                  : 1;  /**< RO/H - PLL FBSLIP indication. */
		uint64_t pll_lock                    : 1;  /**< RO/H - PLL LOCK indication. */
		uint64_t pll_rfslip                  : 1;  /**< RO/H - PLL RFSLIP indication. */
		uint64_t clkr                        : 2;  /**< R/W - PLL post-divider control. */
		uint64_t jtg_test_mode               : 1;  /**< R/W - Reserved; must be zero. INTERNAL: JTAG test mode. Clock alignment between DCLK & REFCLK as
                                                                 well as FCLK & REFCLK can only be performed after the ddr_pll_divider_reset is deasserted.
                                                                 SW need to wait at least 10 reference clock cycles after deasserting pll_divider_reset
                                                                 before asserting LMC()_DDR_PLL_CTL[JTG_TEST_MODE]. During alignment (which can take up
                                                                 to 160 microseconds) DCLK and FCLK can exhibit some high-frequency pulses. Therefore, all
                                                                 bring up activities in that clock domain need to be delayed (when the chip operates in
                                                                 jtg_test_mode) by about 160 microseconds to ensure that lock is achieved. */
		uint64_t ddr_div_reset               : 1;  /**< R/W - DDR postscalar divider reset. */
		uint64_t ddr_ps_en                   : 4;  /**< R/W - DDR postscalar divide ratio. Determines the LMC CK speed.
                                                                 0x0 = divide LMC PLL by 1.
                                                                 0x1 = divide LMC PLL by 2.
                                                                 0x2 = divide LMC PLL by 3.
                                                                 0x3 = divide LMC PLL by 4.
                                                                 0x4 = divide LMC PLL by 5.
                                                                 0x5 = divide LMC PLL by 6.
                                                                 0x6 = divide LMC PLL by 7.
                                                                 0x7 = divide LMC PLL by 8.
                                                                 0x8 = divide LMC PLL by 10.
                                                                 0x9 = divide LMC PLL by 12.
                                                                 0xA = Reserved.
                                                                 0xB = Reserved.
                                                                 0xC = Reserved.
                                                                 0xD = Reserved.
                                                                 0xE = Reserved.
                                                                 0xF = Reserved.

                                                                 DDR_PS_EN is not used when DDR_DIV_RESET = 1. */
		uint64_t reserved_9_17               : 9;
		uint64_t clkf_ext                    : 1;  /**< R/W - A 1-bit extension to the CLKF register to support for DDR4-2666. */
		uint64_t reset_n                     : 1;  /**< R/W - PLL reset */
		uint64_t clkf                        : 7;  /**< R/W - Multiply reference by CLKF. 32 \<= CLKF \<= 64. LMC PLL frequency = 50 * CLKF. min = 1.6
                                                                 GHz, max = 3.2 GHz. */
#else
		uint64_t clkf                        : 7;
		uint64_t reset_n                     : 1;
		uint64_t clkf_ext                    : 1;
		uint64_t reserved_9_17               : 9;
		uint64_t ddr_ps_en                   : 4;
		uint64_t ddr_div_reset               : 1;
		uint64_t jtg_test_mode               : 1;
		uint64_t clkr                        : 2;
		uint64_t pll_rfslip                  : 1;
		uint64_t pll_lock                    : 1;
		uint64_t pll_fbslip                  : 1;
		uint64_t ddr4_mode                   : 1;
		uint64_t phy_dcok                    : 1;
		uint64_t dclk_invert                 : 1;
		uint64_t bwadj                       : 12;
		uint64_t dclk_alt_refclk_sel         : 1;
		uint64_t reserved_45_63              : 19;
#endif
	} s;
	/* struct bdk_lmcx_ddr_pll_ctl_s      cn85xx; */
	/* struct bdk_lmcx_ddr_pll_ctl_s      cn88xx; */
	/* struct bdk_lmcx_ddr_pll_ctl_s      cn88xxp1; */
} bdk_lmcx_ddr_pll_ctl_t;

static inline uint64_t BDK_LMCX_DDR_PLL_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DDR_PLL_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000258ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DDR_PLL_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DDR_PLL_CTL(...) bdk_lmcx_ddr_pll_ctl_t
#define bustype_BDK_LMCX_DDR_PLL_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DDR_PLL_CTL(p1) (p1)
#define arguments_BDK_LMCX_DDR_PLL_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DDR_PLL_CTL(...) "LMCX_DDR_PLL_CTL"


/**
 * RSL - lmc#_dimm#_ddr4_params0
 *
 * This register contains values to be programmed into the extra DDR4 control words in the
 * corresponding (registered) DIMM. These are control words RC1x through RC8x.
 */
typedef union bdk_lmcx_dimmx_ddr4_params0 {
	uint64_t u;
	struct bdk_lmcx_dimmx_ddr4_params0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rc8x                        : 8;  /**< R/W - RC8x. */
		uint64_t rc7x                        : 8;  /**< R/W - RC7x. */
		uint64_t rc6x                        : 8;  /**< R/W - RC6x. */
		uint64_t rc5x                        : 8;  /**< R/W - RC5x. */
		uint64_t rc4x                        : 8;  /**< R/W - RC4x. */
		uint64_t rc3x                        : 8;  /**< R/W - RC3x. */
		uint64_t rc2x                        : 8;  /**< R/W - RC2x. */
		uint64_t rc1x                        : 8;  /**< R/W - RC1x. */
#else
		uint64_t rc1x                        : 8;
		uint64_t rc2x                        : 8;
		uint64_t rc3x                        : 8;
		uint64_t rc4x                        : 8;
		uint64_t rc5x                        : 8;
		uint64_t rc6x                        : 8;
		uint64_t rc7x                        : 8;
		uint64_t rc8x                        : 8;
#endif
	} s;
	/* struct bdk_lmcx_dimmx_ddr4_params0_s cn85xx; */
	/* struct bdk_lmcx_dimmx_ddr4_params0_s cn88xx; */
	/* struct bdk_lmcx_dimmx_ddr4_params0_s cn88xxp1; */
} bdk_lmcx_dimmx_ddr4_params0_t;

static inline uint64_t BDK_LMCX_DIMMX_DDR4_PARAMS0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DIMMX_DDR4_PARAMS0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E0880000D0ull + (param1 & 3) * 0x1000000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_LMCX_DIMMX_DDR4_PARAMS0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DIMMX_DDR4_PARAMS0(...) bdk_lmcx_dimmx_ddr4_params0_t
#define bustype_BDK_LMCX_DIMMX_DDR4_PARAMS0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DIMMX_DDR4_PARAMS0(p1,p2) (p1)
#define arguments_BDK_LMCX_DIMMX_DDR4_PARAMS0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_DIMMX_DDR4_PARAMS0(...) "LMCX_DIMMX_DDR4_PARAMS0"


/**
 * RSL - lmc#_dimm#_ddr4_params1
 *
 * This register contains values to be programmed into the extra DDR4 control words in the
 * corresponding (registered) DIMM. These are control words RC9x through RCBx.
 */
typedef union bdk_lmcx_dimmx_ddr4_params1 {
	uint64_t u;
	struct bdk_lmcx_dimmx_ddr4_params1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t rcbx                        : 8;  /**< R/W - RCBx. */
		uint64_t rcax                        : 8;  /**< R/W - RCAx. */
		uint64_t rc9x                        : 8;  /**< R/W - RC9x. */
#else
		uint64_t rc9x                        : 8;
		uint64_t rcax                        : 8;
		uint64_t rcbx                        : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_lmcx_dimmx_ddr4_params1_s cn85xx; */
	/* struct bdk_lmcx_dimmx_ddr4_params1_s cn88xx; */
	/* struct bdk_lmcx_dimmx_ddr4_params1_s cn88xxp1; */
} bdk_lmcx_dimmx_ddr4_params1_t;

static inline uint64_t BDK_LMCX_DIMMX_DDR4_PARAMS1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DIMMX_DDR4_PARAMS1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E088000140ull + (param1 & 3) * 0x1000000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_LMCX_DIMMX_DDR4_PARAMS1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DIMMX_DDR4_PARAMS1(...) bdk_lmcx_dimmx_ddr4_params1_t
#define bustype_BDK_LMCX_DIMMX_DDR4_PARAMS1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DIMMX_DDR4_PARAMS1(p1,p2) (p1)
#define arguments_BDK_LMCX_DIMMX_DDR4_PARAMS1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_DIMMX_DDR4_PARAMS1(...) "LMCX_DIMMX_DDR4_PARAMS1"


/**
 * RSL - lmc#_dimm#_params
 *
 * This register contains values to be programmed into each control word in the corresponding
 * (registered) DIMM. The control words allow optimization of the device properties for different
 * raw card designs. Note that LMC only uses this CSR when LMC()_CONTROL[RDIMM_ENA]=1. During
 * a power-up/init sequence, LMC writes these fields into the control words in the JEDEC standard
 * SSTE32882 registering clock driver on an RDIMM when corresponding
 * LMC()_DIMM_CTL[DIMM*_WMASK] bits are set.
 */
typedef union bdk_lmcx_dimmx_params {
	uint64_t u;
	struct bdk_lmcx_dimmx_params_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rc15                        : 4;  /**< R/W - RC15, Reserved. */
		uint64_t rc14                        : 4;  /**< R/W - RC14, Reserved. */
		uint64_t rc13                        : 4;  /**< R/W - RC13, Reserved. */
		uint64_t rc12                        : 4;  /**< R/W - RC12, Reserved. */
		uint64_t rc11                        : 4;  /**< R/W - RC11, Encoding for RDIMM operating VDD. */
		uint64_t rc10                        : 4;  /**< R/W - RC10, Encoding for RDIMM operating speed. */
		uint64_t rc9                         : 4;  /**< R/W - RC9, Power savings settings control word. */
		uint64_t rc8                         : 4;  /**< R/W - RC8, Additional IBT settings control word. */
		uint64_t rc7                         : 4;  /**< R/W - RC7, Reserved. */
		uint64_t rc6                         : 4;  /**< R/W - RC6, Reserved. */
		uint64_t rc5                         : 4;  /**< R/W - RC5, CK driver characteristics control word. */
		uint64_t rc4                         : 4;  /**< R/W - RC4, Control signals driver characteristics control word. */
		uint64_t rc3                         : 4;  /**< R/W - RC3, CA signals driver characteristics control word. */
		uint64_t rc2                         : 4;  /**< R/W - RC2, Timing control word. */
		uint64_t rc1                         : 4;  /**< R/W - RC1, Clock driver enable control word. */
		uint64_t rc0                         : 4;  /**< R/W - RC0, Global features control word. */
#else
		uint64_t rc0                         : 4;
		uint64_t rc1                         : 4;
		uint64_t rc2                         : 4;
		uint64_t rc3                         : 4;
		uint64_t rc4                         : 4;
		uint64_t rc5                         : 4;
		uint64_t rc6                         : 4;
		uint64_t rc7                         : 4;
		uint64_t rc8                         : 4;
		uint64_t rc9                         : 4;
		uint64_t rc10                        : 4;
		uint64_t rc11                        : 4;
		uint64_t rc12                        : 4;
		uint64_t rc13                        : 4;
		uint64_t rc14                        : 4;
		uint64_t rc15                        : 4;
#endif
	} s;
	/* struct bdk_lmcx_dimmx_params_s     cn85xx; */
	/* struct bdk_lmcx_dimmx_params_s     cn88xx; */
	/* struct bdk_lmcx_dimmx_params_s     cn88xxp1; */
} bdk_lmcx_dimmx_params_t;

static inline uint64_t BDK_LMCX_DIMMX_PARAMS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DIMMX_PARAMS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 1)))
		return 0x000087E088000270ull + (param1 & 3) * 0x1000000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_LMCX_DIMMX_PARAMS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DIMMX_PARAMS(...) bdk_lmcx_dimmx_params_t
#define bustype_BDK_LMCX_DIMMX_PARAMS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DIMMX_PARAMS(p1,p2) (p1)
#define arguments_BDK_LMCX_DIMMX_PARAMS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_DIMMX_PARAMS(...) "LMCX_DIMMX_PARAMS"


/**
 * RSL - lmc#_dimm_ctl
 *
 * Note that this CSR is only used when LMC()_CONTROL[RDIMM_ENA] = 1. During a power-up/init
 * sequence, this CSR controls LMC's write operations to the control words in the JEDEC standard
 * SSTE32882 registering clock driver on an RDIMM.
 */
typedef union bdk_lmcx_dimm_ctl {
	uint64_t u;
	struct bdk_lmcx_dimm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_46_63              : 18;
		uint64_t parity                      : 1;  /**< R/W - "Parity. The Par_In input of a registered DIMM should be tied off. LMC adjusts the value
                                                                 of the DDR_WE_L (DWE\#) pin during DDR3 register part control word writes to ensure the
                                                                 parity is observed correctly by the receiving SSTE32882 register part.
                                                                 When Par_In is grounded, PARITY should be cleared to 0." */
		uint64_t tcws                        : 13; /**< R/W - LMC waits for this time period before and after a RDIMM control word access during a
                                                                 power-up/init SEQUENCE. TCWS is in multiples of 8 CK cycles.
                                                                 Set TCWS (CSR field) = RNDUP[TCWS(ns)/(8 * TCYC(ns))], where TCWS is the desired time
                                                                 (ns), and TCYC(ns) is the DDR clock frequency (not data rate).
                                                                 TYP = 0x4E0 (equivalent to 15 us) when changing clock timing (RC2.DBA1, RC6.DA4, RC10.DA3,
                                                                 RC10.DA4, RC11.DA3, and RC11.DA4)
                                                                 TYP = 0x8, otherwise
                                                                 0x0 = Reserved */
		uint64_t dimm1_wmask                 : 16; /**< R/W - DIMM1 write mask. If (DIMM1_WMASK[n] = 1), write DIMM1.RCn. */
		uint64_t dimm0_wmask                 : 16; /**< R/W - DIMM0 write mask. If (DIMM0_WMASK[n] = 1), write DIMM0.RCn. */
#else
		uint64_t dimm0_wmask                 : 16;
		uint64_t dimm1_wmask                 : 16;
		uint64_t tcws                        : 13;
		uint64_t parity                      : 1;
		uint64_t reserved_46_63              : 18;
#endif
	} s;
	/* struct bdk_lmcx_dimm_ctl_s         cn85xx; */
	/* struct bdk_lmcx_dimm_ctl_s         cn88xx; */
	/* struct bdk_lmcx_dimm_ctl_s         cn88xxp1; */
} bdk_lmcx_dimm_ctl_t;

static inline uint64_t BDK_LMCX_DIMM_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DIMM_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000310ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DIMM_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DIMM_CTL(...) bdk_lmcx_dimm_ctl_t
#define bustype_BDK_LMCX_DIMM_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DIMM_CTL(p1) (p1)
#define arguments_BDK_LMCX_DIMM_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DIMM_CTL(...) "LMCX_DIMM_CTL"


/**
 * RSL - lmc#_dll_ctl2
 *
 * See LMC Initialization Sequence for the initialization sequence.
 *
 */
typedef union bdk_lmcx_dll_ctl2 {
	uint64_t u;
	struct bdk_lmcx_dll_ctl2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t intf_en                     : 1;  /**< R/W - Interface enable. */
		uint64_t dll_bringup                 : 1;  /**< R/W - DLL bring up. */
		uint64_t dreset                      : 1;  /**< R/W - System-memory-clock domain reset. The reset signal that is used by the system-memory-clock
                                                                 domain is
                                                                 (DRESET -OR- core-clock reset). */
		uint64_t quad_dll_ena                : 1;  /**< R/W - DLL enable. */
		uint64_t byp_sel                     : 4;  /**< R/W - Reserved; must be zero. INTERNAL: Bypass select.
                                                                 0x0 = no byte.
                                                                 0x1 = byte 0.
                                                                 ...
                                                                 0x9 = byte 8.
                                                                 0xA = all bytes.
                                                                 0xB-0xF = Reserved. */
		uint64_t byp_setting                 : 9;  /**< R/W - Reserved; must be zero. INTERNAL: Bypass setting.
                                                                 DDR3-1600: 0x22.
                                                                 DDR3-1333: 0x32.
                                                                 DDR3-1066: 0x4B.
                                                                 DDR3-800: 0x75.
                                                                 DDR3-667: 0x96.
                                                                 DDR3-600: 0xAC. */
#else
		uint64_t byp_setting                 : 9;
		uint64_t byp_sel                     : 4;
		uint64_t quad_dll_ena                : 1;
		uint64_t dreset                      : 1;
		uint64_t dll_bringup                 : 1;
		uint64_t intf_en                     : 1;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_lmcx_dll_ctl2_s         cn85xx; */
	/* struct bdk_lmcx_dll_ctl2_s         cn88xx; */
	/* struct bdk_lmcx_dll_ctl2_s         cn88xxp1; */
} bdk_lmcx_dll_ctl2_t;

static inline uint64_t BDK_LMCX_DLL_CTL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DLL_CTL2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001C8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DLL_CTL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DLL_CTL2(...) bdk_lmcx_dll_ctl2_t
#define bustype_BDK_LMCX_DLL_CTL2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DLL_CTL2(p1) (p1)
#define arguments_BDK_LMCX_DLL_CTL2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DLL_CTL2(...) "LMCX_DLL_CTL2"


/**
 * RSL - lmc#_dll_ctl3
 */
typedef union bdk_lmcx_dll_ctl3 {
	uint64_t u;
	struct bdk_lmcx_dll_ctl3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t wr_deskew_ena               : 1;  /**< R/W - When set, it enables the write bit deskew feature. */
		uint64_t wr_deskew_ld                : 1;  /**< WO - When set, the bit deskew settings in DLL_CTL3[OFFSET] gets loaded to
                                                                 the designated byte DLL_CTL3[BYTE_SEL] and bit DLL_CTL3[BIT_SELECT]
                                                                 for write bit deskew. This is a oneshot and clears itself each time
                                                                 it is set. */
		uint64_t bit_select                  : 4;  /**< R/W - Selects specific DQ bit in byte DLL_CTL3[BYTE_SEL] for write bit deskew. */
		uint64_t dclk90_fwd                  : 1;  /**< WO - Reserved; must be zero. INTERNAL: Generate a one cycle pulse to forward setting. This is a
                                                                 oneshot and clears itself each time it is set. */
		uint64_t ddr_90_dly_byp              : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Bypass DDR90_DLY in clock tree. */
		uint64_t dclk90_recal_dis            : 1;  /**< R/W - Disable periodic recalibration of DDR90 delay line in. */
		uint64_t dclk90_byp_sel              : 1;  /**< R/W - Bypass setting select for DDR90 delay line. */
		uint64_t dclk90_byp_setting          : 9;  /**< R/W - Bypass setting for DDR90 delay line. */
		uint64_t dll_fast                    : 1;  /**< RO/H - Reserved; must be zero. INTERNAL: DLL lock, 0=DLL locked. */
		uint64_t dll90_setting               : 9;  /**< RO/H - Reserved; must be zero. INTERNAL: Encoded DLL settings. Works in conjunction with
                                                                 DLL90_BYTE_SEL. */
		uint64_t fine_tune_mode              : 1;  /**< R/W - DLL fine tune mode. 0 = disabled; 1 = enable. When enabled, calibrate internal PHY DLL
                                                                 every LMC()_CONFIG[REF_ZQCS_INT] CK cycles. */
		uint64_t dll_mode                    : 1;  /**< R/W - Reserved; must be zero. INTERNAL: DLL mode. */
		uint64_t dll90_byte_sel              : 4;  /**< R/W - Observe DLL settings for selected byte.
                                                                 0x0 = byte 0.
                                                                 0x1 = byte 1.
                                                                 ...
                                                                 0x8: byte 8.
                                                                 0x9-0xF: reserved. */
		uint64_t offset_ena                  : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Offset enable. 1=enable. */
		uint64_t load_offset                 : 1;  /**< WO - Reserved; must be zero. INTERNAL: Load offset. 0=disable, 1=generate a one cycle pulse to
                                                                 the PHY. This field is a oneshot and clears itself each time it is set. */
		uint64_t mode_sel                    : 2;  /**< R/W - Reserved; must be zero. INTERNAL: Mode select. 0x0 = reset, 0x1 = write, 0x2 = read, 0x3 =
                                                                 write and read. */
		uint64_t byte_sel                    : 4;  /**< R/W - Reserved; must be zero. INTERNAL: Byte select. 0x0 = no byte, 0x1 = byte 0, ..., 0x9 =
                                                                 byte 8, 0xA = all bytes, 0xB-0xF = Reserved. */
		uint64_t offset                      : 7;  /**< R/W - Reserved; must be zero. INTERNAL: Write/read offset setting. \<5:0\>: offset (not
                                                                 two's-complement), \<5\>: 0 = increment, 1 = decrement. */
#else
		uint64_t offset                      : 7;
		uint64_t byte_sel                    : 4;
		uint64_t mode_sel                    : 2;
		uint64_t load_offset                 : 1;
		uint64_t offset_ena                  : 1;
		uint64_t dll90_byte_sel              : 4;
		uint64_t dll_mode                    : 1;
		uint64_t fine_tune_mode              : 1;
		uint64_t dll90_setting               : 9;
		uint64_t dll_fast                    : 1;
		uint64_t dclk90_byp_setting          : 9;
		uint64_t dclk90_byp_sel              : 1;
		uint64_t dclk90_recal_dis            : 1;
		uint64_t ddr_90_dly_byp              : 1;
		uint64_t dclk90_fwd                  : 1;
		uint64_t bit_select                  : 4;
		uint64_t wr_deskew_ld                : 1;
		uint64_t wr_deskew_ena               : 1;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_lmcx_dll_ctl3_s         cn85xx; */
	/* struct bdk_lmcx_dll_ctl3_s         cn88xx; */
	/* struct bdk_lmcx_dll_ctl3_s         cn88xxp1; */
} bdk_lmcx_dll_ctl3_t;

static inline uint64_t BDK_LMCX_DLL_CTL3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DLL_CTL3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000218ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DLL_CTL3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DLL_CTL3(...) bdk_lmcx_dll_ctl3_t
#define bustype_BDK_LMCX_DLL_CTL3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DLL_CTL3(p1) (p1)
#define arguments_BDK_LMCX_DLL_CTL3(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DLL_CTL3(...) "LMCX_DLL_CTL3"


/**
 * RSL - lmc#_dual_memcfg
 *
 * This register controls certain parameters of dual-memory configuration.
 *
 * This register enables the design to have two separate memory configurations, selected
 * dynamically by the reference address. Note however, that both configurations share
 * LMC()_CONTROL[XOR_BANK], LMC()_CONFIG [PBANK_LSB], LMC()_CONFIG[RANK_ENA], and all
 * timing parameters.
 *
 * In this description:
 * * config0 refers to the normal memory configuration that is defined by the
 * LMC()_CONFIG[ROW_LSB] parameter
 * * config1 refers to the dual (or second) memory configuration that is defined by this
 * register.
 */
typedef union bdk_lmcx_dual_memcfg {
	uint64_t u;
	struct bdk_lmcx_dual_memcfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t row_lsb                     : 3;  /**< R/W - Encoding used to determine which memory address bit position represents the low order DDR
                                                                 ROW address. Refer to
                                                                 LMC()_CONFIG[ROW_LSB].
                                                                 Refer to Cache-block Read Transaction Example. */
		uint64_t reserved_4_15               : 12;
		uint64_t cs_mask                     : 4;  /**< R/W - Chip-select mask. This mask corresponds to the four chip-select signals for a memory
                                                                 configuration. Each reference address asserts one of the chip-select signals. If that
                                                                 chip-select signal has its corresponding CS_MASK bit set, then the config1 parameters are
                                                                 used, otherwise the config0 parameters are used. */
#else
		uint64_t cs_mask                     : 4;
		uint64_t reserved_4_15               : 12;
		uint64_t row_lsb                     : 3;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_lmcx_dual_memcfg_s      cn85xx; */
	/* struct bdk_lmcx_dual_memcfg_s      cn88xx; */
	/* struct bdk_lmcx_dual_memcfg_s      cn88xxp1; */
} bdk_lmcx_dual_memcfg_t;

static inline uint64_t BDK_LMCX_DUAL_MEMCFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_DUAL_MEMCFG(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000098ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_DUAL_MEMCFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_DUAL_MEMCFG(...) bdk_lmcx_dual_memcfg_t
#define bustype_BDK_LMCX_DUAL_MEMCFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_DUAL_MEMCFG(p1) (p1)
#define arguments_BDK_LMCX_DUAL_MEMCFG(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_DUAL_MEMCFG(...) "LMCX_DUAL_MEMCFG"


/**
 * RSL - lmc#_ecc_parity_test
 *
 * This register has bits to control the ECC and CA parity errors creation during test modes. ECC
 * error is generated by enabling the CA_PARITY_CORRUPT_ENA bit of this register and selecting
 * any ECC_CORRUPT_IDX index of the dataword from the cacheline to be corrupted. User can select
 * which bit of the 128-bits dataword to corrupt by asserting any of the CHAR_MASK0 and
 * CHAR_MASK2 bits. (CHAR_MASK0 and CHAR_MASK2 corresponds to the lower and upper 64-bit signal
 * that can corrupt any individual bit of the data).
 *
 * CA parity error is generated by enabling CA_PARITY_CORRUPT_ENA bit of this register and
 * selecting the DDR command that the parity is to be corrupted with through CA_PARITY_SEL.
 */
typedef union bdk_lmcx_ecc_parity_test {
	uint64_t u;
	struct bdk_lmcx_ecc_parity_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t ecc_corrupt_ena             : 1;  /**< R/W/H - Enables the ECC data corruption. */
		uint64_t ecc_corrupt_idx             : 3;  /**< R/W - Selects the cacheline index that the dataword is to be corrupted with. */
		uint64_t reserved_6_7                : 2;
		uint64_t ca_parity_corrupt_ena       : 1;  /**< R/W/H - Enables the CA parity bit corruption. */
		uint64_t ca_parity_sel               : 5;  /**< R/W - Selects the type of DDR command to corrupt the parity bit. */
#else
		uint64_t ca_parity_sel               : 5;
		uint64_t ca_parity_corrupt_ena       : 1;
		uint64_t reserved_6_7                : 2;
		uint64_t ecc_corrupt_idx             : 3;
		uint64_t ecc_corrupt_ena             : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_lmcx_ecc_parity_test_s  cn85xx; */
	/* struct bdk_lmcx_ecc_parity_test_s  cn88xx; */
	/* struct bdk_lmcx_ecc_parity_test_s  cn88xxp1; */
} bdk_lmcx_ecc_parity_test_t;

static inline uint64_t BDK_LMCX_ECC_PARITY_TEST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_ECC_PARITY_TEST(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000108ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_ECC_PARITY_TEST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_ECC_PARITY_TEST(...) bdk_lmcx_ecc_parity_test_t
#define bustype_BDK_LMCX_ECC_PARITY_TEST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_ECC_PARITY_TEST(p1) (p1)
#define arguments_BDK_LMCX_ECC_PARITY_TEST(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_ECC_PARITY_TEST(...) "LMCX_ECC_PARITY_TEST"


/**
 * RSL - lmc#_ecc_synd
 */
typedef union bdk_lmcx_ecc_synd {
	uint64_t u;
	struct bdk_lmcx_ecc_synd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t mrdsyn3                     : 8;  /**< RO/H - MRD ECC syndrome quad 3. MRDSYN3 corresponds to DQ[63:0]_c1_p1, or in 32-bit mode
                                                                 DQ[31:0]_c3_p1/0, where _cC_pP denotes cycle C and phase P. */
		uint64_t mrdsyn2                     : 8;  /**< RO/H - MRD ECC syndrome quad 2. MRDSYN2 corresponds to DQ[63:0]_c1_p0, or in 32-bit mode
                                                                 DQ[31:0]_c2_p1/0, where _cC_pP denotes cycle C and phase P. */
		uint64_t mrdsyn1                     : 8;  /**< RO/H - MRD ECC syndrome quad 1. MRDSYN1 corresponds to DQ[63:0]_c0_p1, or in 32-bit mode
                                                                 DQ[31:0]_c1_p1/0, where _cC_pP denotes cycle C and phase P. */
		uint64_t mrdsyn0                     : 8;  /**< RO/H - MRD ECC syndrome quad 0. MRDSYN0 corresponds to DQ[63:0]_c0_p0, or in 32-bit mode
                                                                 DQ[31:0]_c0_p1/0, where _cC_pP denotes cycle C and phase P. */
#else
		uint64_t mrdsyn0                     : 8;
		uint64_t mrdsyn1                     : 8;
		uint64_t mrdsyn2                     : 8;
		uint64_t mrdsyn3                     : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_lmcx_ecc_synd_s         cn85xx; */
	/* struct bdk_lmcx_ecc_synd_s         cn88xx; */
	/* struct bdk_lmcx_ecc_synd_s         cn88xxp1; */
} bdk_lmcx_ecc_synd_t;

static inline uint64_t BDK_LMCX_ECC_SYND(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_ECC_SYND(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000038ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_ECC_SYND", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_ECC_SYND(...) bdk_lmcx_ecc_synd_t
#define bustype_BDK_LMCX_ECC_SYND(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_ECC_SYND(p1) (p1)
#define arguments_BDK_LMCX_ECC_SYND(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_ECC_SYND(...) "LMCX_ECC_SYND"


/**
 * RSL - lmc#_ext_config
 *
 * This register has additional configuration and control bits for the LMC.
 *
 */
typedef union bdk_lmcx_ext_config {
	uint64_t u;
	struct bdk_lmcx_ext_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t ref_block                   : 1;  /**< R/W - When set, LMC is blocked to initiate any refresh sequence. LMC then will only
                                                                 allow refresh sequence to start when LMC()_REF_STATUS[REF_COUNT] has
                                                                 reached the maximum value of 0x7. */
		uint64_t mrs_side                    : 1;  /**< R/W - Only applies when EXT_CONFIG[MRS_ONE_SIDE] is set.
                                                                 0 = MRS command is sent to the A side of an RDIMM/LRDIMM.
                                                                 1 = MRS command is sent to the B side of an RDIMM/LRDIMM. */
		uint64_t mrs_one_side                : 1;  /**< R/W - Only applies to DDR4 RDIMM/LRDIMM.
                                                                 When set, MRS commands are directed to either the A or B
                                                                 side of the RCD.

                                                                 PDA operation is NOT allowed when this bit is set. In
                                                                 other words, MR_MPR_CTL[MR_WR_PDA_ENABLE]
                                                                 must be cleared before running MRW sequence with this
                                                                 bit turned on. */
		uint64_t mrs_bside_invert_disable    : 1;  /**< R/W - When set, the command decoder cancels the auto inversion of
                                                                 A3-A9, A11, A13, A17, BA0, BA1 and BG0 during MRS/MRS_PDA
                                                                 command to the B side of the RDIMM/LRDIMM.
                                                                 When set, make sure that the RCD's control word
                                                                 RC00 DA[0] = 1 so that the output inversion is disabled in
                                                                 the DDR4 RCD. */
		uint64_t dimm_sel_invert_off         : 1;  /**< R/W - During coalesce_address_mode, the default logic would be to invert
                                                                 the pbank bit whenever NXM[MEM_MSB_D1_R0] \> NXM[MEM_MSB_D0_R0].
                                                                 When this bit is set to 1, it disables this default behaviour.
                                                                 This configuration has lower priority compared to
                                                                 DIMM_SEL_FORCE_INVERT. */
		uint64_t dimm_sel_force_invert       : 1;  /**< R/W - When set to 1, this bit forces the pbank bit to be inverted
                                                                 when in coalesce_address_mode. That is, pbank value of 0 selects
                                                                 DIMM1 instead of DIMM0.
                                                                 Intended to be use for the case of DIMM1 having bigger rank/s
                                                                 than DIMM0. This bit has priority over DIMM_SEL_INVERT_OFF. */
		uint64_t coalesce_address_mode       : 1;  /**< R/W - When set to 1, this bit enables LMC to coalesce the cache-line
                                                                 address space into the DRAMs' address.
                                                                 INTERNAL: FIXME - more explanation */
		uint64_t dimm1_cid                   : 2;  /**< R/W - DIMM1 configuration bits that represent the number of Chip
                                                                 ID of the DRAM. This value is use for decoding address
                                                                 as well as routing Chip IDs to the appropriate output
                                                                 pins.
                                                                 0x0 = 0 Chip ID  (Mono-Die stack).
                                                                 0x1 = 1 Chip ID  (2H 3DS).
                                                                 0x2 = 2 Chip IDs (4H 3DS).
                                                                 0x3 = 3 Chip IDs (8H 3DS). */
		uint64_t dimm0_cid                   : 2;  /**< R/W - DIMM0 configuration bits that represent the number of Chip
                                                                 ID of the DRAM. This value is use for decoding address
                                                                 as well as routing Chip IDs to the appropriate output
                                                                 pins.
                                                                 0x0 = 0 Chip ID  (Mono-Die stack).
                                                                 0x1 = 1 Chip ID  (2H 3DS).
                                                                 0x2 = 2 Chip IDs (4H 3DS).
                                                                 0x3 = 3 Chip IDs (8H 3DS). */
		uint64_t rcd_parity_check            : 1;  /**< R/W - Enables the one cycle delay of the CA parity output. This MUST be set to 1 when using DDR4
                                                                 RDIMM AND parity checking in RCD is enabled (RC0E DA0 = 1). Set this to 0 otherwise.
                                                                 To enable the parity checking in RCD, set this bit first BEFORE issuing the RCW write RC0E
                                                                 DA0 = 1. */
		uint64_t reserved_46_47              : 2;
		uint64_t error_alert_n_sample        : 1;  /**< RO - Read to get a sample of the DDR*_ERROR_ALERT_L signal. */
		uint64_t ea_int_polarity             : 1;  /**< R/W - Set to invert DDR*_ERROR_ALERT_L interrupt polarity. When clear, interrupt is signaled on
                                                                 the rising edge of DDR*_ERROR_ALERT_L. When set, interrupt is signalled on the falling
                                                                 edge of DDR*_ERROR_ALERT_L. */
		uint64_t reserved_43_43              : 1;
		uint64_t par_addr_mask               : 3;  /**< R/W - Mask applied to parity for address bits 14, 13, and 12. Clear to exclude these address
                                                                 bits from the parity calculation, necessary if the DRAM device does not have these pins. */
		uint64_t reserved_38_39              : 2;
		uint64_t mrs_cmd_override            : 1;  /**< R/W - Set to override behavior of MRS and RCS DRAM operations. */
		uint64_t mrs_cmd_select              : 1;  /**< R/W - When MRS_CMD_OVERRIDE is set, use this bit to select which style of operation for MRS and
                                                                 RCW commands.

                                                                 If this bit is clear, select operation where signals other than CS are active before and
                                                                 after the CS_N active cycle.

                                                                 When this bit is set, select the operation where the other command signals (DDR*_RAS_L,
                                                                 DDR*_CAS_L, DDR*_WE_L, DDR*_A\<15:0\>, etc) all are active only during the cycle where the
                                                                 CS_N is also active. */
		uint64_t reserved_33_35              : 3;
		uint64_t invert_data                 : 1;  /**< R/W - Set this bit to cause all data to be inverted before writing or reading to/from DRAM. This
                                                                 effectively uses the scramble logic to instead invert all the data, so this bit must not
                                                                 be set if data scrambling is enabled. May be useful if data inversion will result in lower
                                                                 power. */
		uint64_t reserved_30_31              : 2;
		uint64_t cmd_rti                     : 1;  /**< R/W - Set this bit to change the behavior of the LMC to return to a completely idle command (no
                                                                 CS active, no command pins active, and address/bank address/bank group all low) on the
                                                                 interface after an active command, rather than only forcing the CS inactive between
                                                                 commands. */
		uint64_t cal_ena                     : 1;  /**< R/W - Set to cause LMC to operate in CAL mode. First set LMC()_MODEREG_PARAMS3[CAL], then
                                                                 set CAL_ENA. */
		uint64_t reserved_27_27              : 1;
		uint64_t par_include_a17             : 1;  /**< R/W - If set, include A17 in parity calculations in DDR4 mode. */
		uint64_t par_include_bg1             : 1;  /**< R/W - If set, include BG1 in parity calculations in DDR4 mode. */
		uint64_t gen_par                     : 1;  /**< R/W - Enable parity generation in the DRAM commands; must be set prior to enabling parity in
                                                                 register or DRAM devices. */
		uint64_t reserved_21_23              : 3;
		uint64_t vrefint_seq_deskew          : 1;  /**< R/W - Personality bit to change the operation of what is normally the internal Vref training
                                                                 sequence into the deskew training sequence. */
		uint64_t read_ena_bprch              : 1;  /**< R/W - Enable pad receiver one cycle longer than normal during read operations. */
		uint64_t read_ena_fprch              : 1;  /**< R/W - Enable pad receiver starting one cycle earlier than normal during read operations. */
		uint64_t slot_ctl_reset_force        : 1;  /**< WO - Write 1 to reset the slot-control override for all slot-control registers. After writing a
                                                                 1 to this bit, slot-control registers will update with changes made to other timing-
                                                                 control registers. This is a one-shot operation; it automatically returns to 0 after a
                                                                 write to 1. */
		uint64_t ref_int_lsbs                : 9;  /**< R/W - Refresh-interval value least-significant bits. The default is 0x0; but it can be set to a
                                                                 non-zero value to get a more precise refresh interval. */
		uint64_t drive_ena_bprch             : 1;  /**< R/W - Drive DQx for one cycle longer than normal during write operations. */
		uint64_t drive_ena_fprch             : 1;  /**< R/W - Drive DQX starting one cycle earlier than normal during write operations. */
		uint64_t dlcram_flip_synd            : 2;  /**< R/W - Reserved. INTERNAL: DLC RAM flip syndrome control bits. */
		uint64_t dlcram_cor_dis              : 1;  /**< R/W - Reserved. INTERNAL: DLC RAM correction disable control. */
		uint64_t dlc_nxm_rd                  : 1;  /**< R/W - When set, enable NXM events for HFA read operations. INTERNAL: Default is disabled, but
                                                                 could be useful for debug of DLC/DFA accesses. */
		uint64_t l2c_nxm_rd                  : 1;  /**< R/W - When set, enable NXM events for L2C read operations. INTERNAL: Default is disabled as L2C
                                                                 NXM read operations are possible and expected during normal operation. */
		uint64_t l2c_nxm_wr                  : 1;  /**< R/W - When set, enable NXM events for L2C write operations. */
#else
		uint64_t l2c_nxm_wr                  : 1;
		uint64_t l2c_nxm_rd                  : 1;
		uint64_t dlc_nxm_rd                  : 1;
		uint64_t dlcram_cor_dis              : 1;
		uint64_t dlcram_flip_synd            : 2;
		uint64_t drive_ena_fprch             : 1;
		uint64_t drive_ena_bprch             : 1;
		uint64_t ref_int_lsbs                : 9;
		uint64_t slot_ctl_reset_force        : 1;
		uint64_t read_ena_fprch              : 1;
		uint64_t read_ena_bprch              : 1;
		uint64_t vrefint_seq_deskew          : 1;
		uint64_t reserved_21_23              : 3;
		uint64_t gen_par                     : 1;
		uint64_t par_include_bg1             : 1;
		uint64_t par_include_a17             : 1;
		uint64_t reserved_27_27              : 1;
		uint64_t cal_ena                     : 1;
		uint64_t cmd_rti                     : 1;
		uint64_t reserved_30_31              : 2;
		uint64_t invert_data                 : 1;
		uint64_t reserved_33_35              : 3;
		uint64_t mrs_cmd_select              : 1;
		uint64_t mrs_cmd_override            : 1;
		uint64_t reserved_38_39              : 2;
		uint64_t par_addr_mask               : 3;
		uint64_t reserved_43_43              : 1;
		uint64_t ea_int_polarity             : 1;
		uint64_t error_alert_n_sample        : 1;
		uint64_t reserved_46_47              : 2;
		uint64_t rcd_parity_check            : 1;
		uint64_t dimm0_cid                   : 2;
		uint64_t dimm1_cid                   : 2;
		uint64_t coalesce_address_mode       : 1;
		uint64_t dimm_sel_force_invert       : 1;
		uint64_t dimm_sel_invert_off         : 1;
		uint64_t mrs_bside_invert_disable    : 1;
		uint64_t mrs_one_side                : 1;
		uint64_t mrs_side                    : 1;
		uint64_t ref_block                   : 1;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_lmcx_ext_config_s       cn85xx; */
	/* struct bdk_lmcx_ext_config_s       cn88xx; */
	/* struct bdk_lmcx_ext_config_s       cn88xxp1; */
} bdk_lmcx_ext_config_t;

static inline uint64_t BDK_LMCX_EXT_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_EXT_CONFIG(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000030ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_EXT_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_EXT_CONFIG(...) bdk_lmcx_ext_config_t
#define bustype_BDK_LMCX_EXT_CONFIG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_EXT_CONFIG(p1) (p1)
#define arguments_BDK_LMCX_EXT_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_EXT_CONFIG(...) "LMCX_EXT_CONFIG"


/**
 * RSL - lmc#_ext_config2
 *
 * This register has additional configuration and control bits for the LMC.
 *
 */
typedef union bdk_lmcx_ext_config2 {
	uint64_t u;
	struct bdk_lmcx_ext_config2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t row_col_switch              : 1;  /**< R/W - When set, the memory address bit position that represents bit 4 of the COLUMN
                                                                 address (bit 5 in 32-bit mode) becomes the low order DDR ROW address bit.
                                                                 The upper DDR COLUMN address portion is selected using LMC()_CONFIG[ROW_LSB]
                                                                 (and LMC()_DUAL_MEMCFG[ROW_LSB] for dual-memory configuration).
                                                                 It is recommended to set this bit to 1 when TRR_ON is set. */
		uint64_t trr_on                      : 1;  /**< R/W - When set, this enables row activates counts of the
                                                                 DRAM used in Target Row Refresh mode. This bit can
                                                                 be safely set after the LMC()_EXT_CONFIG2[MACRAM_SCRUB_DONE]
                                                                 has a value of 1. */
		uint64_t mac                         : 3;  /**< R/W - Sets the maximum number of activates allowed within a tMAW interval.
                                                                 0x0 = 100K.
                                                                 0x1 = 400K/2.
                                                                 0x2 = 500K/2.
                                                                 0x3 = 600K/2.
                                                                 0x4 = 700K/2.
                                                                 0x5 = 800K/2.
                                                                 0x6 = 900K/2.
                                                                 0x7 = 1000K/2. */
		uint64_t macram_scrub_done           : 1;  /**< RO/H - Maximum Activate Count memory scrub complete indication;
                                                                 1 means the memory has been scrubbed to all zero. */
		uint64_t macram_scrub                : 1;  /**< WO - When set, the Maximum Activate Count memory will be scrubbed to all zero values. This
                                                                 should be done before enabling TRR mode by setting LMC()_EXT_CONFIG2[TRR_ON].
                                                                 This is a one-shot operation; it automatically returns to 0 after a write to 1. */
		uint64_t macram_flip_synd            : 2;  /**< R/W - Reserved. INTERNAL: MAC RAM flip syndrome control bits. */
		uint64_t macram_cor_dis              : 1;  /**< R/W - Reserved. INTERNAL: MAC RAM correction disable control. */
#else
		uint64_t macram_cor_dis              : 1;
		uint64_t macram_flip_synd            : 2;
		uint64_t macram_scrub                : 1;
		uint64_t macram_scrub_done           : 1;
		uint64_t mac                         : 3;
		uint64_t trr_on                      : 1;
		uint64_t row_col_switch              : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_lmcx_ext_config2_s      cn85xx; */
	/* struct bdk_lmcx_ext_config2_s      cn88xx; */
	/* struct bdk_lmcx_ext_config2_s      cn88xxp1; */
} bdk_lmcx_ext_config2_t;

static inline uint64_t BDK_LMCX_EXT_CONFIG2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_EXT_CONFIG2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000090ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_EXT_CONFIG2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_EXT_CONFIG2(...) bdk_lmcx_ext_config2_t
#define bustype_BDK_LMCX_EXT_CONFIG2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_EXT_CONFIG2(p1) (p1)
#define arguments_BDK_LMCX_EXT_CONFIG2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_EXT_CONFIG2(...) "LMCX_EXT_CONFIG2"


/**
 * RSL - lmc#_fadr
 *
 * This register only captures the first transaction with ECC errors. A DED error can over-write
 * this register with its failing addresses if the first error was a SEC. If you write
 * LMC()_INT -\> SEC_ERR/DED_ERR, it clears the error bits and captures the next failing
 * address. If FDIMM is 1, that means the error is in the high DIMM.
 * LMC()_FADR captures the failing pre-scrambled address location (split into DIMM, bunk,
 * bank, etc). If scrambling is off, then LMC()_FADR will also capture the failing physical
 * location in the DRAM parts. LMC()_SCRAMBLED_FADR captures the actual failing address
 * location in the physical DRAM parts, i.e.,
 * * If scrambling is on, LMC()_SCRAMBLED_FADR contains the failing physical location in the
 * DRAM parts (split into DIMM, bunk, bank, etc.)
 * If scrambling is off, the pre-scramble and post-scramble addresses are the same; and so the
 * contents of LMC()_SCRAMBLED_FADR match the contents of LMC()_FADR.
 */
typedef union bdk_lmcx_fadr {
	uint64_t u;
	struct bdk_lmcx_fadr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t fcid                        : 3;  /**< RO/H - Failing CID number. */
		uint64_t fill_order                  : 2;  /**< RO/H - Fill order for failing transaction. */
		uint64_t fdimm                       : 1;  /**< RO/H - Failing DIMM number. */
		uint64_t fbunk                       : 1;  /**< RO/H - Failing rank number. */
		uint64_t fbank                       : 4;  /**< RO/H - Failing bank number. Bits \<3:0\>. */
		uint64_t frow                        : 18; /**< RO/H - Failing row address. Bits \<17:0\>. */
		uint64_t fcol                        : 14; /**< RO/H - Failing column address \<13:0\>. Technically, represents the address of the 64b data that
                                                                 had an ECC error, i.e., FCOL[0] is always 0. Can be used in conjunction with
                                                                 LMC()_INT[DED_ERR] to isolate the 64b chunk of data in error. */
#else
		uint64_t fcol                        : 14;
		uint64_t frow                        : 18;
		uint64_t fbank                       : 4;
		uint64_t fbunk                       : 1;
		uint64_t fdimm                       : 1;
		uint64_t fill_order                  : 2;
		uint64_t fcid                        : 3;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_lmcx_fadr_s             cn85xx; */
	/* struct bdk_lmcx_fadr_s             cn88xx; */
	/* struct bdk_lmcx_fadr_s             cn88xxp1; */
} bdk_lmcx_fadr_t;

static inline uint64_t BDK_LMCX_FADR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_FADR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000020ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_FADR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_FADR(...) bdk_lmcx_fadr_t
#define bustype_BDK_LMCX_FADR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_FADR(p1) (p1)
#define arguments_BDK_LMCX_FADR(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_FADR(...) "LMCX_FADR"


/**
 * RSL - lmc#_general_purpose0
 */
typedef union bdk_lmcx_general_purpose0 {
	uint64_t u;
	struct bdk_lmcx_general_purpose0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - General purpose data register.  See LMC()_PPR_CTL and LMC()_DBTRAIN_CTL[RW_TRAIN]. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_lmcx_general_purpose0_s cn85xx; */
	/* struct bdk_lmcx_general_purpose0_s cn88xx; */
	/* struct bdk_lmcx_general_purpose0_s cn88xxp1; */
} bdk_lmcx_general_purpose0_t;

static inline uint64_t BDK_LMCX_GENERAL_PURPOSE0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_GENERAL_PURPOSE0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000340ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_GENERAL_PURPOSE0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_GENERAL_PURPOSE0(...) bdk_lmcx_general_purpose0_t
#define bustype_BDK_LMCX_GENERAL_PURPOSE0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_GENERAL_PURPOSE0(p1) (p1)
#define arguments_BDK_LMCX_GENERAL_PURPOSE0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_GENERAL_PURPOSE0(...) "LMCX_GENERAL_PURPOSE0"


/**
 * RSL - lmc#_general_purpose1
 */
typedef union bdk_lmcx_general_purpose1 {
	uint64_t u;
	struct bdk_lmcx_general_purpose1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - General purpose data register.  See LMC()_PPR_CTL and LMC()_DBTRAIN_CTL[RW_TRAIN]. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_lmcx_general_purpose1_s cn85xx; */
	/* struct bdk_lmcx_general_purpose1_s cn88xx; */
	/* struct bdk_lmcx_general_purpose1_s cn88xxp1; */
} bdk_lmcx_general_purpose1_t;

static inline uint64_t BDK_LMCX_GENERAL_PURPOSE1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_GENERAL_PURPOSE1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000348ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_GENERAL_PURPOSE1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_GENERAL_PURPOSE1(...) bdk_lmcx_general_purpose1_t
#define bustype_BDK_LMCX_GENERAL_PURPOSE1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_GENERAL_PURPOSE1(p1) (p1)
#define arguments_BDK_LMCX_GENERAL_PURPOSE1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_GENERAL_PURPOSE1(...) "LMCX_GENERAL_PURPOSE1"


/**
 * RSL - lmc#_general_purpose2
 */
typedef union bdk_lmcx_general_purpose2 {
	uint64_t u;
	struct bdk_lmcx_general_purpose2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t data                        : 16; /**< R/W - General purpose data register.  See LMC()_PPR_CTL and LMC()_DBTRAIN_CTL[RW_TRAIN]. */
#else
		uint64_t data                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_lmcx_general_purpose2_s cn85xx; */
	/* struct bdk_lmcx_general_purpose2_s cn88xx; */
	/* struct bdk_lmcx_general_purpose2_s cn88xxp1; */
} bdk_lmcx_general_purpose2_t;

static inline uint64_t BDK_LMCX_GENERAL_PURPOSE2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_GENERAL_PURPOSE2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000350ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_GENERAL_PURPOSE2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_GENERAL_PURPOSE2(...) bdk_lmcx_general_purpose2_t
#define bustype_BDK_LMCX_GENERAL_PURPOSE2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_GENERAL_PURPOSE2(p1) (p1)
#define arguments_BDK_LMCX_GENERAL_PURPOSE2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_GENERAL_PURPOSE2(...) "LMCX_GENERAL_PURPOSE2"


/**
 * RSL - lmc#_ifb_cnt
 */
typedef union bdk_lmcx_ifb_cnt {
	uint64_t u;
	struct bdk_lmcx_ifb_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ifbcnt                      : 64; /**< RO/H - Performance counter. 64-bit counter that increments every CK cycle that there is something
                                                                 in the in-flight buffer. */
#else
		uint64_t ifbcnt                      : 64;
#endif
	} s;
	/* struct bdk_lmcx_ifb_cnt_s          cn85xx; */
	/* struct bdk_lmcx_ifb_cnt_s          cn88xx; */
	/* struct bdk_lmcx_ifb_cnt_s          cn88xxp1; */
} bdk_lmcx_ifb_cnt_t;

static inline uint64_t BDK_LMCX_IFB_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_IFB_CNT(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001D0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_IFB_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_IFB_CNT(...) bdk_lmcx_ifb_cnt_t
#define bustype_BDK_LMCX_IFB_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_IFB_CNT(p1) (p1)
#define arguments_BDK_LMCX_IFB_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_IFB_CNT(...) "LMCX_IFB_CNT"


/**
 * RSL - lmc#_int
 *
 * This register contains the different interrupt-summary bits of the LMC.
 *
 */
typedef union bdk_lmcx_int {
	uint64_t u;
	struct bdk_lmcx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t macram_ded_err              : 1;  /**< R/W1C/H - MAC RAM ECC double error detect (DED). */
		uint64_t macram_sec_err              : 1;  /**< R/W1C/H - MAC RAM ECC single error correct (SEC). */
		uint64_t ddr_err                     : 1;  /**< R/W1C/H - DDR RAM error alert interrupt. */
		uint64_t dlcram_ded_err              : 1;  /**< R/W1C/H - DLC RAM ECC double error detect (DED). */
		uint64_t dlcram_sec_err              : 1;  /**< R/W1C/H - DLC RAM ECC single error correct (SEC). */
		uint64_t ded_err                     : 4;  /**< R/W1C/H - Double error detected (DED) of Rd Data.
                                                                 In 64b mode:

                                                                 _ \<5\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<6\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<7\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<8\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 _ \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 _ \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 _ \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 _ \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t sec_err                     : 4;  /**< R/W1C/H - Single error (corrected) of Rd Data.
                                                                 _ \<1\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<2\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<3\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<4\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t nxm_wr_err                  : 1;  /**< R/W1C/H - Write to nonexistent memory. */
#else
		uint64_t nxm_wr_err                  : 1;
		uint64_t sec_err                     : 4;
		uint64_t ded_err                     : 4;
		uint64_t dlcram_sec_err              : 1;
		uint64_t dlcram_ded_err              : 1;
		uint64_t ddr_err                     : 1;
		uint64_t macram_sec_err              : 1;
		uint64_t macram_ded_err              : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_lmcx_int_s              cn85xx; */
	/* struct bdk_lmcx_int_s              cn88xx; */
	/* struct bdk_lmcx_int_s              cn88xxp1; */
} bdk_lmcx_int_t;

static inline uint64_t BDK_LMCX_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_INT(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001F0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_INT(...) bdk_lmcx_int_t
#define bustype_BDK_LMCX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_INT(p1) (p1)
#define arguments_BDK_LMCX_INT(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_INT(...) "LMCX_INT"


/**
 * RSL - lmc#_int_en
 */
typedef union bdk_lmcx_int_en {
	uint64_t u;
	struct bdk_lmcx_int_en_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t ddr_error_alert_ena         : 1;  /**< R/W - DDR4 error alert interrupt enable bit. */
		uint64_t dlcram_ded_ena              : 1;  /**< R/W - DLC RAM ECC double error detect (DED) interrupt enable bit. */
		uint64_t dlcram_sec_ena              : 1;  /**< R/W - DLC RAM ECC single error correct (SEC) interrupt enable bit. */
		uint64_t intr_ded_ena                : 1;  /**< R/W - ECC double error detect (DED) interrupt enable bit. When set, the memory controller raises
                                                                 a processor interrupt on detecting an uncorrectable double-bit ECC error. */
		uint64_t intr_sec_ena                : 1;  /**< R/W - ECC single error correct (SEC) interrupt enable bit. When set, the memory controller
                                                                 raises a processor interrupt on detecting a correctable single-bit ECC error. */
		uint64_t intr_nxm_wr_ena             : 1;  /**< R/W - Nonwrite error interrupt enable bit. When set, the memory controller raises a processor
                                                                 interrupt on detecting an nonexistent memory write. */
#else
		uint64_t intr_nxm_wr_ena             : 1;
		uint64_t intr_sec_ena                : 1;
		uint64_t intr_ded_ena                : 1;
		uint64_t dlcram_sec_ena              : 1;
		uint64_t dlcram_ded_ena              : 1;
		uint64_t ddr_error_alert_ena         : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_lmcx_int_en_s           cn85xx; */
	/* struct bdk_lmcx_int_en_s           cn88xx; */
	/* struct bdk_lmcx_int_en_s           cn88xxp1; */
} bdk_lmcx_int_en_t;

static inline uint64_t BDK_LMCX_INT_EN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_INT_EN(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001E8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_INT_EN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_INT_EN(...) bdk_lmcx_int_en_t
#define bustype_BDK_LMCX_INT_EN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_INT_EN(p1) (p1)
#define arguments_BDK_LMCX_INT_EN(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_INT_EN(...) "LMCX_INT_EN"


/**
 * RSL - lmc#_int_ena_w1c
 */
typedef union bdk_lmcx_int_ena_w1c {
	uint64_t u;
	struct bdk_lmcx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t macram_ded_err              : 1;  /**< R/W1C/H - MAC RAM ECC double error detect (DED). */
		uint64_t macram_sec_err              : 1;  /**< R/W1C/H - MAC RAM ECC single error correct (SEC). */
		uint64_t ddr_err                     : 1;  /**< R/W1C/H - DDR RAM error alert interrupt. */
		uint64_t dlcram_ded_err              : 1;  /**< R/W1C/H - DLC RAM ECC double error detect (DED). */
		uint64_t dlcram_sec_err              : 1;  /**< R/W1C/H - DLC RAM ECC single error correct (SEC). */
		uint64_t ded_err                     : 4;  /**< R/W1C/H - Double error detected (DED) of Rd Data.
                                                                 In 64b mode:

                                                                 _ \<5\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<6\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<7\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<8\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 _ \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 _ \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 _ \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 _ \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t sec_err                     : 4;  /**< R/W1C/H - Single error (corrected) of Rd Data.
                                                                 _ \<1\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<2\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<3\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<4\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t nxm_wr_err                  : 1;  /**< R/W1C/H - Write to nonexistent memory. */
#else
		uint64_t nxm_wr_err                  : 1;
		uint64_t sec_err                     : 4;
		uint64_t ded_err                     : 4;
		uint64_t dlcram_sec_err              : 1;
		uint64_t dlcram_ded_err              : 1;
		uint64_t ddr_err                     : 1;
		uint64_t macram_sec_err              : 1;
		uint64_t macram_ded_err              : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_lmcx_int_ena_w1c_s      cn85xx; */
	/* struct bdk_lmcx_int_ena_w1c_s      cn88xx; */
	/* struct bdk_lmcx_int_ena_w1c_s      cn88xxp1; */
} bdk_lmcx_int_ena_w1c_t;

static inline uint64_t BDK_LMCX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000158ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_INT_ENA_W1C(...) bdk_lmcx_int_ena_w1c_t
#define bustype_BDK_LMCX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_LMCX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_INT_ENA_W1C(...) "LMCX_INT_ENA_W1C"


/**
 * RSL - lmc#_int_ena_w1s
 */
typedef union bdk_lmcx_int_ena_w1s {
	uint64_t u;
	struct bdk_lmcx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t macram_ded_err              : 1;  /**< R/W1C/H - MAC RAM ECC double error detect (DED). */
		uint64_t macram_sec_err              : 1;  /**< R/W1C/H - MAC RAM ECC single error correct (SEC). */
		uint64_t ddr_err                     : 1;  /**< R/W1C/H - DDR RAM error alert interrupt. */
		uint64_t dlcram_ded_err              : 1;  /**< R/W1C/H - DLC RAM ECC double error detect (DED). */
		uint64_t dlcram_sec_err              : 1;  /**< R/W1C/H - DLC RAM ECC single error correct (SEC). */
		uint64_t ded_err                     : 4;  /**< R/W1C/H - Double error detected (DED) of Rd Data.
                                                                 In 64b mode:

                                                                 _ \<5\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<6\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<7\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<8\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 _ \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 _ \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 _ \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 _ \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t sec_err                     : 4;  /**< R/W1C/H - Single error (corrected) of Rd Data.
                                                                 _ \<1\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<2\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<3\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<4\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t nxm_wr_err                  : 1;  /**< R/W1C/H - Write to nonexistent memory. */
#else
		uint64_t nxm_wr_err                  : 1;
		uint64_t sec_err                     : 4;
		uint64_t ded_err                     : 4;
		uint64_t dlcram_sec_err              : 1;
		uint64_t dlcram_ded_err              : 1;
		uint64_t ddr_err                     : 1;
		uint64_t macram_sec_err              : 1;
		uint64_t macram_ded_err              : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_lmcx_int_ena_w1s_s      cn85xx; */
	/* struct bdk_lmcx_int_ena_w1s_s      cn88xx; */
	/* struct bdk_lmcx_int_ena_w1s_s      cn88xxp1; */
} bdk_lmcx_int_ena_w1s_t;

static inline uint64_t BDK_LMCX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000160ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_INT_ENA_W1S(...) bdk_lmcx_int_ena_w1s_t
#define bustype_BDK_LMCX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_LMCX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_INT_ENA_W1S(...) "LMCX_INT_ENA_W1S"


/**
 * RSL - lmc#_int_w1s
 */
typedef union bdk_lmcx_int_w1s {
	uint64_t u;
	struct bdk_lmcx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t macram_ded_err              : 1;  /**< R/W1C/H - MAC RAM ECC double error detect (DED). */
		uint64_t macram_sec_err              : 1;  /**< R/W1C/H - MAC RAM ECC single error correct (SEC). */
		uint64_t ddr_err                     : 1;  /**< R/W1C/H - DDR RAM error alert interrupt. */
		uint64_t dlcram_ded_err              : 1;  /**< R/W1C/H - DLC RAM ECC double error detect (DED). */
		uint64_t dlcram_sec_err              : 1;  /**< R/W1C/H - DLC RAM ECC single error correct (SEC). */
		uint64_t ded_err                     : 4;  /**< R/W1C/H - Double error detected (DED) of Rd Data.
                                                                 In 64b mode:

                                                                 _ \<5\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<6\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<7\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<8\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 _ \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 _ \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 _ \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 _ \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t sec_err                     : 4;  /**< R/W1C/H - Single error (corrected) of Rd Data.
                                                                 _ \<1\> corresponds to DQ[63:0]_c0_p0
                                                                 _ \<2\> corresponds to DQ[63:0]_c0_p1
                                                                 _ \<3\> corresponds to DQ[63:0]_c1_p0
                                                                 _ \<4\> corresponds to DQ[63:0]_c1_p1
                                                                 _ where _cC_pP denotes cycle C and phase P.

                                                                 In 32b mode, each bit corresponds to 2 phases:
                                                                 \<5\> corresponds to DQ[31:0]_c0_p1/0
                                                                 \<6\> corresponds to DQ[31:0]_c1_p1/0
                                                                 \<7\> corresponds to DQ[31:0]_c2_p1/0
                                                                 \<8\> corresponds to DQ[31:0]_c3_p1/0 */
		uint64_t nxm_wr_err                  : 1;  /**< R/W1C/H - Write to nonexistent memory. */
#else
		uint64_t nxm_wr_err                  : 1;
		uint64_t sec_err                     : 4;
		uint64_t ded_err                     : 4;
		uint64_t dlcram_sec_err              : 1;
		uint64_t dlcram_ded_err              : 1;
		uint64_t ddr_err                     : 1;
		uint64_t macram_sec_err              : 1;
		uint64_t macram_ded_err              : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_lmcx_int_w1s_s          cn85xx; */
	/* struct bdk_lmcx_int_w1s_s          cn88xx; */
	/* struct bdk_lmcx_int_w1s_s          cn88xxp1; */
} bdk_lmcx_int_w1s_t;

static inline uint64_t BDK_LMCX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000150ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_INT_W1S(...) bdk_lmcx_int_w1s_t
#define bustype_BDK_LMCX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_INT_W1S(p1) (p1)
#define arguments_BDK_LMCX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_INT_W1S(...) "LMCX_INT_W1S"


/**
 * RSL - lmc#_lane#_crc_swiz
 *
 * This register contains the CRC bit swizzle for even and odd ranks.
 *
 */
typedef union bdk_lmcx_lanex_crc_swiz {
	uint64_t u;
	struct bdk_lmcx_lanex_crc_swiz_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t r1_swiz7                    : 3;  /**< R/W - Bit select for odd rank, bit 7. */
		uint64_t r1_swiz6                    : 3;  /**< R/W - Bit select for odd rank, bit 6. */
		uint64_t r1_swiz5                    : 3;  /**< R/W - Bit select for odd rank, bit 5. */
		uint64_t r1_swiz4                    : 3;  /**< R/W - Bit select for odd rank, bit 4. */
		uint64_t r1_swiz3                    : 3;  /**< R/W - Bit select for odd rank, bit 3. */
		uint64_t r1_swiz2                    : 3;  /**< R/W - Bit select for odd rank, bit 2. */
		uint64_t r1_swiz1                    : 3;  /**< R/W - Bit select for odd rank, bit 1. */
		uint64_t r1_swiz0                    : 3;  /**< R/W - Bit select for odd rank, bit 0. */
		uint64_t reserved_24_31              : 8;
		uint64_t r0_swiz7                    : 3;  /**< R/W - Bit select for even rank, bit 7. */
		uint64_t r0_swiz6                    : 3;  /**< R/W - Bit select for even rank, bit 6. */
		uint64_t r0_swiz5                    : 3;  /**< R/W - Bit select for even rank, bit 5. */
		uint64_t r0_swiz4                    : 3;  /**< R/W - Bit select for even rank, bit 4. */
		uint64_t r0_swiz3                    : 3;  /**< R/W - Bit select for even rank, bit 3. */
		uint64_t r0_swiz2                    : 3;  /**< R/W - Bit select for even rank, bit 2. */
		uint64_t r0_swiz1                    : 3;  /**< R/W - Bit select for even rank, bit 1. */
		uint64_t r0_swiz0                    : 3;  /**< R/W - Bit select for even rank, bit 0. */
#else
		uint64_t r0_swiz0                    : 3;
		uint64_t r0_swiz1                    : 3;
		uint64_t r0_swiz2                    : 3;
		uint64_t r0_swiz3                    : 3;
		uint64_t r0_swiz4                    : 3;
		uint64_t r0_swiz5                    : 3;
		uint64_t r0_swiz6                    : 3;
		uint64_t r0_swiz7                    : 3;
		uint64_t reserved_24_31              : 8;
		uint64_t r1_swiz0                    : 3;
		uint64_t r1_swiz1                    : 3;
		uint64_t r1_swiz2                    : 3;
		uint64_t r1_swiz3                    : 3;
		uint64_t r1_swiz4                    : 3;
		uint64_t r1_swiz5                    : 3;
		uint64_t r1_swiz6                    : 3;
		uint64_t r1_swiz7                    : 3;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_lmcx_lanex_crc_swiz_s   cn85xx; */
	/* struct bdk_lmcx_lanex_crc_swiz_s   cn88xx; */
	/* struct bdk_lmcx_lanex_crc_swiz_s   cn88xxp1; */
} bdk_lmcx_lanex_crc_swiz_t;

static inline uint64_t BDK_LMCX_LANEX_CRC_SWIZ(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_LANEX_CRC_SWIZ(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 8)))
		return 0x000087E088000380ull + (param1 & 3) * 0x1000000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_LMCX_LANEX_CRC_SWIZ", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_LANEX_CRC_SWIZ(...) bdk_lmcx_lanex_crc_swiz_t
#define bustype_BDK_LMCX_LANEX_CRC_SWIZ(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_LANEX_CRC_SWIZ(p1,p2) (p1)
#define arguments_BDK_LMCX_LANEX_CRC_SWIZ(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_LANEX_CRC_SWIZ(...) "LMCX_LANEX_CRC_SWIZ"


/**
 * RSL - lmc#_modereg_params0
 *
 * These parameters are written into the DDR3/DDR4 MR0, MR1, MR2 and MR3 registers.
 *
 */
typedef union bdk_lmcx_modereg_params0 {
	uint64_t u;
	struct bdk_lmcx_modereg_params0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t cl_ext                      : 1;  /**< R/W - Reserved; must be zero.
                                                                 INTERNAL: The extended bit for the proposed CAS Latency spec change. The new
                                                                 CAS Latency in DDR4 DRAM is defined in MR0(A12,A6,A5,A4,A2). This bit sets
                                                                 the A12 bit.

                                                                 See LMC()_MODEREG_PARAMS0[CL]. */
		uint64_t al_ext                      : 1;  /**< R/W - Reserved; must be zero.
                                                                 INTERNAL: The extended bit for the new Additive latency settings for DDR4 3DS.
                                                                 Together with LMC()_MODEREG_PARAMS0[AL], this covers additive latency settings
                                                                 of up to CL-6.

                                                                 0: CL - (LMC()_MODEREG_PARAMS0[AL])
                                                                 1: CL - (LMC()_MODEREG_PARAMS0[AL] + 4)

                                                                 See LMC()_MODEREG_PARAMS0[AL]. */
		uint64_t ppd                         : 1;  /**< R/W - DLL control for precharge powerdown.
                                                                 0 = Slow exit (DLL off).
                                                                 1 = Fast exit (DLL on).

                                                                 LMC writes this value to MR0[PPD] in the selected DDR3/DDR4 parts during power-up/init
                                                                 and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK]. This value must
                                                                 equal
                                                                 the MR0[PPD] value in all the DDR3/DDR4 parts attached to all ranks during normal
                                                                 operation. */
		uint64_t wrp                         : 3;  /**< R/W - Write recovery for auto precharge. Should be programmed to be equal to or greater than
                                                                 RNDUP[TWR(ns) / Tcyc(ns)].

                                                                 0x0 = 5.
                                                                 0x1 = 5.
                                                                 0x2 = 6.
                                                                 0x3 = 7.
                                                                 0x4 = 8.
                                                                 0x5 = 10.
                                                                 0x6 = 12.
                                                                 0x7 = 14.

                                                                 LMC writes this value to MR0[WR] in the selected DDR3/DDR4 parts during power-up/init and,
                                                                 if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK]. This value must
                                                                 equal
                                                                 the MR0[WR] value in all the DDR3/DDR4 parts attached to all ranks during normal
                                                                 operation. */
		uint64_t dllr                        : 1;  /**< R/W - DLL reset. LMC writes this value to MR0[DLL] in the selected DDR3/DDR4 parts during power-
                                                                 up/init and, if LMC()_CONFIG [SREF_WITH_DLL] is set, self-refresh exit instruction
                                                                 sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK].
                                                                 The MR0[DLL] value must be 0 in all the DDR3/DDR4 parts attached to all ranks during
                                                                 normal operation. */
		uint64_t tm                          : 1;  /**< R/W - Test mode. LMC writes this value to MR0[TM] in the selected DDR3/DDR4 parts during power-
                                                                 up/init and, if LMC()_CONFIG [SREF_WITH_DLL] is set, self-refresh exit instruction
                                                                 sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK].
                                                                 The MR0[TM] value must be 0 in all the DDR3/DDR4 parts attached to all ranks during normal
                                                                 operation. */
		uint64_t rbt                         : 1;  /**< RO - Read burst. Type 1 = interleaved (fixed). LMC writes this value to MR0[RBT] in the
                                                                 selected DDR3/DDR4 parts during power-up/init and, if LMC()_CONFIG[SREF_WITH_DLL] is set,
                                                                 self-refresh exit instruction sequences. See LMC()_CONFIG[SEQ_SEL,INIT_START,
                                                                 RANKMASK]. The MR0[RBT] value must be 1 in all the DDR3/DDR4 parts attached to all ranks
                                                                 during normal operation. */
		uint64_t cl                          : 4;  /**< R/W - CAS latency.

                                                                 In DDR3 mode:

                                                                 0x2 = 5. 0x1 = 12.
                                                                 0x4 = 6. 0x3 = 13.
                                                                 0x6 = 7. 0x5 = 14.
                                                                 0x8 = 8. 0x7 = 15.
                                                                 0xA = 9. 0x9 = 16.
                                                                 0xC = 10.
                                                                 0xE = 11.
                                                                 0x0, 0xB, 0xD, 0xF = Reserved.

                                                                 In DDR4 mode:

                                                                 0x0 =  9. 0x1 = 10.
                                                                 0x2 = 11. 0x3 = 12.
                                                                 0x4 = 13. 0x5 = 14.
                                                                 0x6 = 15. 0x7 = 16.
                                                                 0x8 = 18. 0x9 = 20.
                                                                 0xA = 22. 0xB = 24.
                                                                 0xD = 17, 0xE = 19.
                                                                 0xF = 21, 0xC = Reserved.

                                                                 LMC writes this value to MR0[CAS Latency / CL] in the selected DDR3 parts during power-
                                                                 up/init and, if LMC()_CONFIG [SREF_WITH_DLL] is set, self-refresh exit instruction
                                                                 sequences. See LMC()_CONFIG[SEQ_SEL,INIT_START,RANKMASK]. This value must equal the
                                                                 MR0[CAS Latency / CL] value in all the DDR3/4 parts attached to all ranks during normal
                                                                 operation.

                                                                 tCL must be programmed to greater than or equal to tCWL for proper LMC operation. */
		uint64_t bl                          : 2;  /**< R/W - Burst length.
                                                                 0x0 = 8 (fixed).
                                                                 0x1 = 4 or 8 (on-the-fly).

                                                                 LMC writes this value to MR0[BL] in the selected DDR3 parts during power-up/init and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK]. The MR0[BL] value
                                                                 must be 1 in all the DDR3/4 parts attached to all ranks during normal operation. */
		uint64_t qoff                        : 1;  /**< R/W - Qoff enable. 0: enable; 1: disable.
                                                                 LMC writes this value to MR1[Qoff] in the DDR3 parts in the selected ranks during power-
                                                                 up/init, write-leveling, and if LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry
                                                                 and exit instruction sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and
                                                                 LMC()_CONFIG[RANKMASK,INIT_STATUS] and LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. The
                                                                 MR1[Qoff] value must be 0 in all the DDR3 parts attached to all ranks during normal
                                                                 operation. */
		uint64_t tdqs                        : 1;  /**< R/W - TDQS enable. 0: disable. LMC writes this value to MR1[TDQS] in the DDR3 parts in the
                                                                 selected ranks during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_CONFIG[SEQ_SEL, INIT_START,RANKMASK,INIT_STATUS] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t wlev                        : 1;  /**< RO - Write leveling enable. 0: disable. LMC writes MR1[Level]=0 in the DDR3 parts in the
                                                                 selected ranks during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit sequences. (Write-
                                                                 leveling can only be initiated via the write-leveling instruction sequence.) See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK,INIT_STATUS] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t al                          : 2;  /**< R/W - Reserved; must be zero.
                                                                 INTERNAL: Additive latency:
                                                                 0x0: 0.
                                                                 0x1: CL-1.
                                                                 0x2: CL - 2.
                                                                 0x3: Reserved.
                                                                 LMC writes this value to MR1[AL] in the selected DDR3 parts during power-up/init, write-
                                                                 leveling, and, if LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit
                                                                 instruction sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and
                                                                 LMC()_CONFIG[RANKMASK]
                                                                 and LMC()_RESET_CTL [DDR3PWARM,DDR3PSOFT]. This value must equal the MR1[AL] value in
                                                                 all
                                                                 the DDR3 parts attached to all ranks during normal operation. See also
                                                                 LMC()_CONTROL[POCAS]. */
		uint64_t dll                         : 1;  /**< R/W - DLL Enable. 0: enable; 1: disable. LMC writes this value to MR1[DLL] in the selected DDR3
                                                                 parts during power-up/init, write-leveling, and, if LMC()_CONFIG[SREF_WITH_DLL] is
                                                                 set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START]
                                                                 and LMC()_CONFIG[RANKMASK] and LMC()_RESET_CTL [DDR3PWARM,DDR3PSOFT]. This value
                                                                 must equal the MR1[DLL] value in all the DDR3 parts attached to all ranks during normal
                                                                 operation. In DLL-off mode, CL/CWL must be programmed equal to 6/6, respectively, as per
                                                                 the JEDEC DDR3 specifications. */
		uint64_t mpr                         : 1;  /**< R/W - MPR. LMC writes this value to MR3[MPR] in the selected DDR3 parts during power-up/init,
                                                                 read-leveling, and, if LMC()_CONFIG [SREF_WITH_DLL] is set, self-refresh exit
                                                                 instruction sequences. (LMC also writes MR3[MPR] = 1 at the beginning of the read-leveling
                                                                 instruction sequence. Read-leveling should only be initiated via the read-leveling
                                                                 instruction sequence.) See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and
                                                                 LMC()_CONFIG[RANKMASK].
                                                                 The MR3[MPR] value must be 0 in all the DDR3 parts attached to all ranks during normal
                                                                 operation. */
		uint64_t mprloc                      : 2;  /**< R/W - MPR location. LMC writes this value to MR3[MPRLoc] in the selected DDR3 parts during
                                                                 power-up/init, read-leveling, and, if LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh
                                                                 exit instruction sequences. (LMC also writes MR3[MPRLoc] = 0 at the beginning of the read-
                                                                 leveling instruction sequence.) See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and
                                                                 LMC()_CONFIG[RANKMASK]. The MR3[MPRLoc] value must be 0 in all the DDR3 parts attached
                                                                 to all ranks during normal operation. */
		uint64_t cwl                         : 3;  /**< R/W - CAS write latency.

                                                                 In DDR3 mode:
                                                                 0x0 = 5.
                                                                 0x1 = 6.
                                                                 0x2 = 7.
                                                                 0x3 = 8.
                                                                 0x4 = 9.
                                                                 0x5 = 10.
                                                                 0x6 = 11.
                                                                 0x7 = 12.

                                                                 In DDR4 mode:
                                                                 0x0 = 9.
                                                                 0x1 = 10.
                                                                 0x2 = 11.
                                                                 0x3 = 12.
                                                                 0x4 = 13.
                                                                 0x5 = 16.
                                                                 0x6 = 18.
                                                                 0x7 = Reserved.

                                                                 LMC writes this value to MR2[CWL] in the selected DDR3 parts during power-up/init, write-
                                                                 leveling, and, if LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit
                                                                 instruction sequences. See LMC()_CONFIG[SEQ_SEL, INIT_START,RANKMASK] and
                                                                 LMC()_RESET_CTL [DDR3PWARM, DDR3PSOFT]. This value must equal the MR2[CWL] value in
                                                                 all the DDR3 parts attached to all ranks during normal operation.
                                                                 tCWL must be programmed to less than or equal to tCL for proper LMC operation. */
#else
		uint64_t cwl                         : 3;
		uint64_t mprloc                      : 2;
		uint64_t mpr                         : 1;
		uint64_t dll                         : 1;
		uint64_t al                          : 2;
		uint64_t wlev                        : 1;
		uint64_t tdqs                        : 1;
		uint64_t qoff                        : 1;
		uint64_t bl                          : 2;
		uint64_t cl                          : 4;
		uint64_t rbt                         : 1;
		uint64_t tm                          : 1;
		uint64_t dllr                        : 1;
		uint64_t wrp                         : 3;
		uint64_t ppd                         : 1;
		uint64_t al_ext                      : 1;
		uint64_t cl_ext                      : 1;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_lmcx_modereg_params0_s  cn85xx; */
	/* struct bdk_lmcx_modereg_params0_s  cn88xx; */
	/* struct bdk_lmcx_modereg_params0_s  cn88xxp1; */
} bdk_lmcx_modereg_params0_t;

static inline uint64_t BDK_LMCX_MODEREG_PARAMS0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MODEREG_PARAMS0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001A8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MODEREG_PARAMS0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MODEREG_PARAMS0(...) bdk_lmcx_modereg_params0_t
#define bustype_BDK_LMCX_MODEREG_PARAMS0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MODEREG_PARAMS0(p1) (p1)
#define arguments_BDK_LMCX_MODEREG_PARAMS0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MODEREG_PARAMS0(...) "LMCX_MODEREG_PARAMS0"


/**
 * RSL - lmc#_modereg_params1
 *
 * These parameters are written into the DDR3 MR0, MR1, MR2 and MR3 registers.
 *
 */
typedef union bdk_lmcx_modereg_params1 {
	uint64_t u;
	struct bdk_lmcx_modereg_params1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t db_output_impedance         : 3;  /**< R/W - Host Interface DQ/DQS Output Driver Impedance control for DIMM0's Data Buffer.
                                                                 This is the default value used during Host Interface Write Leveling in LRDIMM
                                                                 environment, i.e., CONFIG[LRDIMM_ENA] = 1, SEQ_CTL[SEQ_SEL] = 0x6.
                                                                 0x0 = RZQ/6 (40 ohm).
                                                                 0x1 = RZQ/7 (34 ohm).
                                                                 0x2 = RZQ/5 (48 ohm).
                                                                 0x3-0x7 = Reserved. */
		uint64_t rtt_nom_11                  : 3;  /**< R/W - RTT_NOM rank 3. LMC writes this value to MR1[RTT_NOM] in the rank 3 (i.e. DIMM1_CS1) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. Per JEDEC DDR3 specifications, if RTT_NOM is
                                                                 used during write operations, only values MR1[RTT_NOM] = 1 (RZQ/4), 2 (RZQ/2), or 3
                                                                 (RZQ/6) are allowed. Otherwise, values MR1[RTT_NOM] = 4 (RZQ/12) and 5 (RZQ/8) are also
                                                                 allowed. */
		uint64_t dic_11                      : 2;  /**< R/W - Output driver impedance control rank 3. LMC writes this value to MR1[D.I.C.] in the rank 3
                                                                 (i.e. DIMM1_CS1) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t rtt_wr_11                   : 2;  /**< R/W - RTT_WR rank 3. LMC writes this value to MR2[Rtt_WR] in the rank 3 (i.e. DIMM1_CS1) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL [DDR3PWARM,DDR3PSOFT]. */
		uint64_t srt_11                      : 1;  /**< R/W - Self-refresh temperature range rank 3. LMC writes this value to MR2[SRT] in the rank 3
                                                                 (i.e. DIMM1_CS1) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START], LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t asr_11                      : 1;  /**< R/W - Auto self-refresh rank 3. LMC writes this value to MR2[ASR] in the rank 3 (i.e. DIMM1_CS1)
                                                                 DDR3 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START], LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t pasr_11                     : 3;  /**< R/W - Partial array self-refresh rank 3. LMC writes this value to MR2[PASR] in the rank 3 (i.e.
                                                                 DIMM1_CS1) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t rtt_nom_10                  : 3;  /**< R/W - RTT_NOM rank 2. LMC writes this value to MR1[Rtt_Nom] in the rank 2 (i.e. DIMM1_CS0) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL [DDR3PWARM, DDR3PSOFT]. Per JEDEC DDR3 specifications, if RTT_NOM
                                                                 is used during write operations, only values MR1[RTT_NOM] = 1 (RZQ/4), 2 (RZQ/2), or
                                                                 3 (RZQ/6) are allowed. Otherwise, values MR1[RTT_NOM] = 4 (RZQ/12) and 5 (RZQ/8) are
                                                                 also allowed. */
		uint64_t dic_10                      : 2;  /**< R/W - Output driver impedance control rank 2. LMC writes this value to MR1[D.I.C.] in the rank 2
                                                                 (i.e. DIMM1_CS0) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t rtt_wr_10                   : 2;  /**< R/W - RTT_WR rank 2. LMC writes this value to MR2[Rtt_WR] in the rank 2 (i.e. DIMM1_CS0) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t srt_10                      : 1;  /**< R/W - Self-refresh temperature range rank 2. LMC writes this value to MR2[SRT] in the rank 2
                                                                 (i.e. DIMM1_CS0) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t asr_10                      : 1;  /**< R/W - Auto self-refresh rank 2. LMC writes this value to MR2[ASR] in the rank 2 (i.e. DIMM1_CS0)
                                                                 DDR3 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t pasr_10                     : 3;  /**< R/W - Partial array self-refresh rank 2. LMC writes this value to MR2[PASR] in the rank 2 (i.e.
                                                                 DIMM1_CS0) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t rtt_nom_01                  : 3;  /**< R/W - RTT_NOM rank 1. LMC writes this value to MR1[RTT_NOM] in the rank 1 (i.e. DIMM0_CS1) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. Per JEDEC DDR3 specifications, if RTT_NOM is
                                                                 used during write operations, only values MR1[RTT_NOM] = 1 (RZQ/4), 2 (RZQ/2), or 3
                                                                 (RZQ/6) are allowed. Otherwise, values MR1[RTT_NOM] = 4 (RZQ/12) and 5 (RZQ/8) are also
                                                                 allowed. */
		uint64_t dic_01                      : 2;  /**< R/W - Output driver impedance control rank 1. LMC writes this value to MR1[D.I.C.] in the rank 1
                                                                 (i.e. DIMM0_CS1) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t rtt_wr_01                   : 2;  /**< R/W - RTT_WR rank 1. LMC writes this value to MR2[RTT_WR] in the rank 1 (i.e. DIMM0_CS1) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t srt_01                      : 1;  /**< R/W - Self-refresh temperature range rank 1. LMC writes this value to MR2[SRT] in the rank 1
                                                                 (i.e. DIMM0_CS1) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t asr_01                      : 1;  /**< R/W - Auto self-refresh rank 1. LMC writes this value to MR2[ASR] in the rank 1 (i.e. DIMM0_CS1)
                                                                 DDR3 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t pasr_01                     : 3;  /**< R/W - Partial array self-refresh rank 1. LMC writes this value to MR2[PASR] in the rank 1 (i.e.
                                                                 DIMM0_CS1) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t rtt_nom_00                  : 3;  /**< R/W - RTT_NOM rank 0. LMC writes this value to MR1[RTT_NOM] in the rank 0 (i.e. DIMM0_CS0) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. Per JEDEC DDR3 specifications, if RTT_NOM is
                                                                 used during write operations, only values MR1[RTT_NOM] = 1 (RZQ/4), 2 (RZQ/2),
                                                                 or 3 (RZQ/6) are allowed. Otherwise, values MR1[RTT_NOM] = 4 (RZQ/12) and 5 (RZQ/8)
                                                                 are also allowed. */
		uint64_t dic_00                      : 2;  /**< R/W - Output driver impedance control rank 0. LMC writes this value to MR1[D.I.C.] in the rank 0
                                                                 (i.e. DIMM0_CS0) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t rtt_wr_00                   : 2;  /**< R/W - RTT_WR rank 0. LMC writes this value to MR2[RTT_WR] in the rank 0 (i.e. DIMM0_CS0) DDR3
                                                                 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. */
		uint64_t srt_00                      : 1;  /**< R/W - Self-refresh temperature range rank 0. LMC writes this value to MR2[SRT] in the rank 0
                                                                 (i.e. DIMM0_CS0) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
		uint64_t asr_00                      : 1;  /**< R/W - Auto self-refresh rank 0. LMC writes this value to MR2[ASR] in the rank 0 (i.e. DIMM0_CS0)
                                                                 DDR3 parts when selected during power-up/init, write-leveling, and, if LMC()_CONFIG
                                                                 [SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences. See
                                                                 LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL [DDR3PWARM,DDR3PSOFT]. */
		uint64_t pasr_00                     : 3;  /**< R/W - Partial array self-refresh rank 0. LMC writes this value to MR2[PASR] in the rank 0 (i.e.
                                                                 DIMM0_CS0) DDR3 parts when selected during power-up/init, write-leveling, and, if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit instruction sequences.
                                                                 See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and
                                                                 LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT]. */
#else
		uint64_t pasr_00                     : 3;
		uint64_t asr_00                      : 1;
		uint64_t srt_00                      : 1;
		uint64_t rtt_wr_00                   : 2;
		uint64_t dic_00                      : 2;
		uint64_t rtt_nom_00                  : 3;
		uint64_t pasr_01                     : 3;
		uint64_t asr_01                      : 1;
		uint64_t srt_01                      : 1;
		uint64_t rtt_wr_01                   : 2;
		uint64_t dic_01                      : 2;
		uint64_t rtt_nom_01                  : 3;
		uint64_t pasr_10                     : 3;
		uint64_t asr_10                      : 1;
		uint64_t srt_10                      : 1;
		uint64_t rtt_wr_10                   : 2;
		uint64_t dic_10                      : 2;
		uint64_t rtt_nom_10                  : 3;
		uint64_t pasr_11                     : 3;
		uint64_t asr_11                      : 1;
		uint64_t srt_11                      : 1;
		uint64_t rtt_wr_11                   : 2;
		uint64_t dic_11                      : 2;
		uint64_t rtt_nom_11                  : 3;
		uint64_t db_output_impedance         : 3;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_lmcx_modereg_params1_s  cn85xx; */
	/* struct bdk_lmcx_modereg_params1_s  cn88xx; */
	/* struct bdk_lmcx_modereg_params1_s  cn88xxp1; */
} bdk_lmcx_modereg_params1_t;

static inline uint64_t BDK_LMCX_MODEREG_PARAMS1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MODEREG_PARAMS1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000260ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MODEREG_PARAMS1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MODEREG_PARAMS1(...) bdk_lmcx_modereg_params1_t
#define bustype_BDK_LMCX_MODEREG_PARAMS1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MODEREG_PARAMS1(p1) (p1)
#define arguments_BDK_LMCX_MODEREG_PARAMS1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MODEREG_PARAMS1(...) "LMCX_MODEREG_PARAMS1"


/**
 * RSL - lmc#_modereg_params2
 *
 * These parameters are written into the DDR4 mode registers.
 *
 */
typedef union bdk_lmcx_modereg_params2 {
	uint64_t u;
	struct bdk_lmcx_modereg_params2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_41_63              : 23;
		uint64_t vrefdq_train_en             : 1;  /**< R/W - Vref training mode enable, used for all ranks. */
		uint64_t vref_range_11               : 1;  /**< R/W - VREF range for rank 3. */
		uint64_t vref_value_11               : 6;  /**< R/W - VREF value for rank 3. */
		uint64_t rtt_park_11                 : 3;  /**< R/W - RTT park value for rank 3. */
		uint64_t vref_range_10               : 1;  /**< R/W - VREF range for rank 2. */
		uint64_t vref_value_10               : 6;  /**< R/W - VREF value for rank 2. */
		uint64_t rtt_park_10                 : 3;  /**< R/W - RTT park value for rank 2. */
		uint64_t vref_range_01               : 1;  /**< R/W - VREF range for rank 1. */
		uint64_t vref_value_01               : 6;  /**< R/W - VREF value for rank 1. */
		uint64_t rtt_park_01                 : 3;  /**< R/W - RTT park value for rank 1. */
		uint64_t vref_range_00               : 1;  /**< R/W - VREF range for rank 0. */
		uint64_t vref_value_00               : 6;  /**< R/W - VREF value for rank 0. */
		uint64_t rtt_park_00                 : 3;  /**< R/W - RTT park value for rank 0. */
#else
		uint64_t rtt_park_00                 : 3;
		uint64_t vref_value_00               : 6;
		uint64_t vref_range_00               : 1;
		uint64_t rtt_park_01                 : 3;
		uint64_t vref_value_01               : 6;
		uint64_t vref_range_01               : 1;
		uint64_t rtt_park_10                 : 3;
		uint64_t vref_value_10               : 6;
		uint64_t vref_range_10               : 1;
		uint64_t rtt_park_11                 : 3;
		uint64_t vref_value_11               : 6;
		uint64_t vref_range_11               : 1;
		uint64_t vrefdq_train_en             : 1;
		uint64_t reserved_41_63              : 23;
#endif
	} s;
	/* struct bdk_lmcx_modereg_params2_s  cn85xx; */
	/* struct bdk_lmcx_modereg_params2_s  cn88xx; */
	/* struct bdk_lmcx_modereg_params2_s  cn88xxp1; */
} bdk_lmcx_modereg_params2_t;

static inline uint64_t BDK_LMCX_MODEREG_PARAMS2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MODEREG_PARAMS2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000050ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MODEREG_PARAMS2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MODEREG_PARAMS2(...) bdk_lmcx_modereg_params2_t
#define bustype_BDK_LMCX_MODEREG_PARAMS2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MODEREG_PARAMS2(p1) (p1)
#define arguments_BDK_LMCX_MODEREG_PARAMS2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MODEREG_PARAMS2(...) "LMCX_MODEREG_PARAMS2"


/**
 * RSL - lmc#_modereg_params3
 *
 * These parameters are written into the DDR4 mode registers.
 *
 */
typedef union bdk_lmcx_modereg_params3 {
	uint64_t u;
	struct bdk_lmcx_modereg_params3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_39_63              : 25;
		uint64_t xrank_add_tccd_l            : 3;  /**< R/W - Add additional cycles on top of the 4 cycles applied to tCCD_L
                                                                 when crossing logical rank (to the same bank group) of a 3DS DRAM. */
		uint64_t xrank_add_tccd_s            : 3;  /**< R/W - Add additional cycles on top of the 4 cycles applied to tCCD_S
                                                                 when crossing logical rank (to a different bank group) of a 3DS DRAM. */
		uint64_t mpr_fmt                     : 2;  /**< R/W - MPR format. */
		uint64_t wr_cmd_lat                  : 2;  /**< R/W - Write command latency when CRC and DM are both enabled. */
		uint64_t fgrm                        : 3;  /**< R/W - Fine granularity refresh mode. */
		uint64_t temp_sense                  : 1;  /**< R/W - Temperature sensor readout enable. */
		uint64_t pda                         : 1;  /**< R/W - Per DRAM addressability. */
		uint64_t gd                          : 1;  /**< R/W - Gear-down mode. */
		uint64_t crc                         : 1;  /**< R/W - CRC mode. */
		uint64_t lpasr                       : 2;  /**< R/W - LP auto self refresh. */
		uint64_t tccd_l                      : 3;  /**< R/W - TCCD_L timing parameter:
                                                                 0x0 = 4.
                                                                 0x1 = 5.
                                                                 0x2 = 6.
                                                                 0x3 = 7.
                                                                 0x4 = 8.
                                                                 0x5-0x7 = reserved. */
		uint64_t rd_dbi                      : 1;  /**< R/W - Read DBI. */
		uint64_t wr_dbi                      : 1;  /**< R/W - Write DBI. */
		uint64_t dm                          : 1;  /**< R/W - Data mask enable. */
		uint64_t ca_par_pers                 : 1;  /**< R/W - Command/address persistent parity error mode. */
		uint64_t odt_pd                      : 1;  /**< R/W - ODT in PD mode. */
		uint64_t par_lat_mode                : 3;  /**< R/W - Parity latency mode. */
		uint64_t wr_preamble                 : 1;  /**< R/W - Write preamble, 0 = one nCK, 1 = two nCK. */
		uint64_t rd_preamble                 : 1;  /**< R/W - Write preamble, 0 = one nCK, 1 = two nCK. */
		uint64_t sre_abort                   : 1;  /**< R/W - Self refresh abort. */
		uint64_t cal                         : 3;  /**< R/W - CS-to-CMD/ADDR latency mode (cycles). */
		uint64_t vref_mon                    : 1;  /**< R/W - Internal VREF monitor: 0 = disable, 1 = enable. */
		uint64_t tc_ref                      : 1;  /**< R/W - Temperature controlled refresh range: 0 = normal, 1 = extended. */
		uint64_t max_pd                      : 1;  /**< R/W - Maximum power-down mode: 0 = disable, 1 = enable. */
#else
		uint64_t max_pd                      : 1;
		uint64_t tc_ref                      : 1;
		uint64_t vref_mon                    : 1;
		uint64_t cal                         : 3;
		uint64_t sre_abort                   : 1;
		uint64_t rd_preamble                 : 1;
		uint64_t wr_preamble                 : 1;
		uint64_t par_lat_mode                : 3;
		uint64_t odt_pd                      : 1;
		uint64_t ca_par_pers                 : 1;
		uint64_t dm                          : 1;
		uint64_t wr_dbi                      : 1;
		uint64_t rd_dbi                      : 1;
		uint64_t tccd_l                      : 3;
		uint64_t lpasr                       : 2;
		uint64_t crc                         : 1;
		uint64_t gd                          : 1;
		uint64_t pda                         : 1;
		uint64_t temp_sense                  : 1;
		uint64_t fgrm                        : 3;
		uint64_t wr_cmd_lat                  : 2;
		uint64_t mpr_fmt                     : 2;
		uint64_t xrank_add_tccd_s            : 3;
		uint64_t xrank_add_tccd_l            : 3;
		uint64_t reserved_39_63              : 25;
#endif
	} s;
	/* struct bdk_lmcx_modereg_params3_s  cn85xx; */
	/* struct bdk_lmcx_modereg_params3_s  cn88xx; */
	/* struct bdk_lmcx_modereg_params3_s  cn88xxp1; */
} bdk_lmcx_modereg_params3_t;

static inline uint64_t BDK_LMCX_MODEREG_PARAMS3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MODEREG_PARAMS3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000058ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MODEREG_PARAMS3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MODEREG_PARAMS3(...) bdk_lmcx_modereg_params3_t
#define bustype_BDK_LMCX_MODEREG_PARAMS3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MODEREG_PARAMS3(p1) (p1)
#define arguments_BDK_LMCX_MODEREG_PARAMS3(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MODEREG_PARAMS3(...) "LMCX_MODEREG_PARAMS3"


/**
 * RSL - lmc#_mpr_data0
 *
 * This register provides bits \<63:0\> of MPR data register.
 *
 */
typedef union bdk_lmcx_mpr_data0 {
	uint64_t u;
	struct bdk_lmcx_mpr_data0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mpr_data                    : 64; /**< RO/H - MPR data bits\<63:0\>. Bits\<7:0\> represent the MPR data for the lowest-order *4 device (*4
                                                                 device 0); bits\<15:8\> represent *4 device 1; ..., bits\<63:56\> are for *4 device 7. */
#else
		uint64_t mpr_data                    : 64;
#endif
	} s;
	/* struct bdk_lmcx_mpr_data0_s        cn85xx; */
	/* struct bdk_lmcx_mpr_data0_s        cn88xx; */
	/* struct bdk_lmcx_mpr_data0_s        cn88xxp1; */
} bdk_lmcx_mpr_data0_t;

static inline uint64_t BDK_LMCX_MPR_DATA0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MPR_DATA0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000070ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MPR_DATA0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MPR_DATA0(...) bdk_lmcx_mpr_data0_t
#define bustype_BDK_LMCX_MPR_DATA0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MPR_DATA0(p1) (p1)
#define arguments_BDK_LMCX_MPR_DATA0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MPR_DATA0(...) "LMCX_MPR_DATA0"


/**
 * RSL - lmc#_mpr_data1
 *
 * This register provides bits \<127:64\> of MPR data register.
 *
 */
typedef union bdk_lmcx_mpr_data1 {
	uint64_t u;
	struct bdk_lmcx_mpr_data1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mpr_data                    : 64; /**< RO/H - MPR data bits\<127:64\>. Bits\<7:0\> represent the MPR data for *4 device 8; bits\<15:8\>
                                                                 represent *4 device 9; ...; bits\<63:56\> are for *4 device 15. */
#else
		uint64_t mpr_data                    : 64;
#endif
	} s;
	/* struct bdk_lmcx_mpr_data1_s        cn85xx; */
	/* struct bdk_lmcx_mpr_data1_s        cn88xx; */
	/* struct bdk_lmcx_mpr_data1_s        cn88xxp1; */
} bdk_lmcx_mpr_data1_t;

static inline uint64_t BDK_LMCX_MPR_DATA1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MPR_DATA1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000078ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MPR_DATA1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MPR_DATA1(...) bdk_lmcx_mpr_data1_t
#define bustype_BDK_LMCX_MPR_DATA1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MPR_DATA1(p1) (p1)
#define arguments_BDK_LMCX_MPR_DATA1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MPR_DATA1(...) "LMCX_MPR_DATA1"


/**
 * RSL - lmc#_mpr_data2
 *
 * This register provides bits \<143:128\> of MPR data register.
 *
 */
typedef union bdk_lmcx_mpr_data2 {
	uint64_t u;
	struct bdk_lmcx_mpr_data2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t mpr_data                    : 16; /**< RO/H - MPR data bits\<143:128\>. Bits\<7:0\> represent the MPR data for *4 device 16; bits\<15:8\>
                                                                 represent *4 device 17. */
#else
		uint64_t mpr_data                    : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_lmcx_mpr_data2_s        cn85xx; */
	/* struct bdk_lmcx_mpr_data2_s        cn88xx; */
	/* struct bdk_lmcx_mpr_data2_s        cn88xxp1; */
} bdk_lmcx_mpr_data2_t;

static inline uint64_t BDK_LMCX_MPR_DATA2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MPR_DATA2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000080ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MPR_DATA2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MPR_DATA2(...) bdk_lmcx_mpr_data2_t
#define bustype_BDK_LMCX_MPR_DATA2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MPR_DATA2(p1) (p1)
#define arguments_BDK_LMCX_MPR_DATA2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MPR_DATA2(...) "LMCX_MPR_DATA2"


/**
 * RSL - lmc#_mr_mpr_ctl
 *
 * This register sets timing parameters for DDR4.
 *
 */
typedef union bdk_lmcx_mr_mpr_ctl {
	uint64_t u;
	struct bdk_lmcx_mr_mpr_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_61_63              : 3;
		uint64_t mr_wr_secure_key_ena        : 1;  /**< R/W - When set, this enables the issuing of security key with the
                                                                 unique address field A[17:0] set by LMC()_MR_MPR_CTL[MR_WR_ADDR]
                                                                 during the MRW sequence.
                                                                 Set this to 1 when executing DRAM Post Package Repair manually
                                                                 by using MRW operation. */
		uint64_t pba_func_space              : 3;  /**< R/W - Set the Function Space Selector during PBA mode of the MRW
                                                                 sequence. */
		uint64_t mr_wr_bg1                   : 1;  /**< R/W - BG1 part of the address select for MRS in DDR4 mode. */
		uint64_t mpr_sample_dq_enable        : 1;  /**< R/W - Reserved. INTERNAL: Sample the whole r128dat1_2a and r128dat0_2a
                                                                 in one cycle. This has priority over the whole-byte mode. i.e., when
                                                                 this bit is set to 1, the MPR register ignores the value of the
                                                                 MPR_WHOLE_BYTE_ENABLE bit. */
		uint64_t pda_early_dqx               : 1;  /**< R/W - When set, it enables lmc_dqx early for PDA/PBA operation. */
		uint64_t mr_wr_pba_enable            : 1;  /**< R/W - Per Buffer Addressability write enable. When set, MRW operations use PBA, enabled by
                                                                 MR_WR_PDA_MASK per buffer.
                                                                 Only available for DDR4 LRDIMM. */
		uint64_t mr_wr_use_default_value     : 1;  /**< R/W - When set, write the value to the MR that is computed from the value set in various CSR
                                                                 fields that would be used during initialization, rather that using the value in the
                                                                 LMC()_MR_MPR_CTL[MR_WR_ADDR]. Useful to rewrite the same value or to change single
                                                                 bits without having to compute a whole new value for the MR. */
		uint64_t mpr_whole_byte_enable       : 1;  /**< R/W - Reserved. INTERNAL: Select a whole byte of DRAM data to read when whole-byte mode enabled. */
		uint64_t mpr_byte_select             : 4;  /**< R/W - Reserved. INTERNAL: Select a whole byte of DRAM data to read when whole-byte mode enabled. */
		uint64_t mpr_bit_select              : 2;  /**< R/W - Select which of four bits to read for each nibble of DRAM data. Typically all four bits
                                                                 from a *4 device, or all eight bits from a *8 device, or all 16 bits from a *16 device
                                                                 carry the same data, but this field allows selection of which device bit will be used to
                                                                 read the MPR data. */
		uint64_t mpr_wr                      : 1;  /**< R/W - MPR sequence will perform a write operation when set. */
		uint64_t mpr_loc                     : 2;  /**< R/W - MPR location select for MPR sequence. Only makes a difference for DDR4. */
		uint64_t mr_wr_pda_enable            : 1;  /**< R/W - PDA write enable. When set, MRW operations use PDA, enabled by MR_WR_PDA_MASK per device.
                                                                 Only available for DDR4 devices. */
		uint64_t mr_wr_pda_mask              : 18; /**< R/W - PDA mask. If MR_WR_PDA_ENABLE = 1 and there is a 1 in the bit for this mask value, then
                                                                 the corresponding DRAM device is enabled for the PDA MR write operation.
                                                                 Bit\<23\> corresponds to the lowest order, *4 device, and bit\<40\> corresponds to the highest
                                                                 order *4 device, for a total of up to 18 devices. */
		uint64_t mr_wr_rank                  : 2;  /**< R/W - Selects the DRAM rank for either MRW or MPR sequences. */
		uint64_t mr_wr_sel                   : 3;  /**< R/W - Selects which MR to write with the MR write sequence.
                                                                 Which pins to drive and how to drive them is automatically controlled through the DDR3/4
                                                                 mode setting. Bits\<19:18\> are also used to select the MPR page for an MPR sequence.
                                                                 A value of 0x7 selects an RCW write for both DDR4 and DDR3 MRW operations. */
		uint64_t mr_wr_addr                  : 18; /**< R/W - Sets a value for A\<17:0\> for MR write operations. Note that many of these bits must be 0
                                                                 for various MRs. Bits\<7:0\> are also used for write data on an MPR sequence write
                                                                 operation. */
#else
		uint64_t mr_wr_addr                  : 18;
		uint64_t mr_wr_sel                   : 3;
		uint64_t mr_wr_rank                  : 2;
		uint64_t mr_wr_pda_mask              : 18;
		uint64_t mr_wr_pda_enable            : 1;
		uint64_t mpr_loc                     : 2;
		uint64_t mpr_wr                      : 1;
		uint64_t mpr_bit_select              : 2;
		uint64_t mpr_byte_select             : 4;
		uint64_t mpr_whole_byte_enable       : 1;
		uint64_t mr_wr_use_default_value     : 1;
		uint64_t mr_wr_pba_enable            : 1;
		uint64_t pda_early_dqx               : 1;
		uint64_t mpr_sample_dq_enable        : 1;
		uint64_t mr_wr_bg1                   : 1;
		uint64_t pba_func_space              : 3;
		uint64_t mr_wr_secure_key_ena        : 1;
		uint64_t reserved_61_63              : 3;
#endif
	} s;
	/* struct bdk_lmcx_mr_mpr_ctl_s       cn85xx; */
	/* struct bdk_lmcx_mr_mpr_ctl_s       cn88xx; */
	/* struct bdk_lmcx_mr_mpr_ctl_s       cn88xxp1; */
} bdk_lmcx_mr_mpr_ctl_t;

static inline uint64_t BDK_LMCX_MR_MPR_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MR_MPR_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000068ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MR_MPR_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MR_MPR_CTL(...) bdk_lmcx_mr_mpr_ctl_t
#define bustype_BDK_LMCX_MR_MPR_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MR_MPR_CTL(p1) (p1)
#define arguments_BDK_LMCX_MR_MPR_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_MR_MPR_CTL(...) "LMCX_MR_MPR_CTL"


/**
 * RSL - lmc#_msix_pba#
 *
 * This register is the LMC-X PBA table; the bit number is indexed by the LMC_INT_VEC_E enumeration.
 *
 */
typedef union bdk_lmcx_msix_pbax {
	uint64_t u;
	struct bdk_lmcx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated LMC()_MSIX_VEC()_CTL, enumerated by LMC_INT_VEC_E. Bits
                                                                 that have no associated LMC_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_lmcx_msix_pbax_s        cn85xx; */
	/* struct bdk_lmcx_msix_pbax_s        cn88xx; */
	/* struct bdk_lmcx_msix_pbax_s        cn88xxp1; */
} bdk_lmcx_msix_pbax_t;

static inline uint64_t BDK_LMCX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E088FF0000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MSIX_PBAX(...) bdk_lmcx_msix_pbax_t
#define bustype_BDK_LMCX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_LMCX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_MSIX_PBAX(...) "LMCX_MSIX_PBAX"


/**
 * RSL - lmc#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the LMC_INT_VEC_E enumeration.
 *
 */
typedef union bdk_lmcx_msix_vecx_addr {
	uint64_t u;
	struct bdk_lmcx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's LMC()_MSIX_VEC()_ADDR, LMC()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of LMC()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_lmcx_msix_vecx_addr_s   cn85xx; */
	/* struct bdk_lmcx_msix_vecx_addr_s   cn88xx; */
	/* struct bdk_lmcx_msix_vecx_addr_s   cn88xxp1; */
} bdk_lmcx_msix_vecx_addr_t;

static inline uint64_t BDK_LMCX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E088F00000ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MSIX_VECX_ADDR(...) bdk_lmcx_msix_vecx_addr_t
#define bustype_BDK_LMCX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_LMCX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_MSIX_VECX_ADDR(...) "LMCX_MSIX_VECX_ADDR"


/**
 * RSL - lmc#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the LMC_INT_VEC_E enumeration.
 *
 */
typedef union bdk_lmcx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_lmcx_msix_vecx_ctl_s {
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
	/* struct bdk_lmcx_msix_vecx_ctl_s    cn85xx; */
	/* struct bdk_lmcx_msix_vecx_ctl_s    cn88xx; */
	/* struct bdk_lmcx_msix_vecx_ctl_s    cn88xxp1; */
} bdk_lmcx_msix_vecx_ctl_t;

static inline uint64_t BDK_LMCX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 == 0)))
		return 0x000087E088F00008ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_MSIX_VECX_CTL(...) bdk_lmcx_msix_vecx_ctl_t
#define bustype_BDK_LMCX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_LMCX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_MSIX_VECX_CTL(...) "LMCX_MSIX_VECX_CTL"


/**
 * RSL - lmc#_ns_ctl
 *
 * This register contains control parameters for handling non-secure accesses.
 *
 */
typedef union bdk_lmcx_ns_ctl {
	uint64_t u;
	struct bdk_lmcx_ns_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_26_63              : 38;
		uint64_t ns_scramble_dis             : 1;  /**< R/W - When set, this field disables data scrambling on non-secure accesses only.
                                                                 When data scrambling is enabled by setting CONTROL[SCRAMBLE_ENA] to 1, this
                                                                 field needs to be cleared to 0 in order to enable data scrambling on
                                                                 non-secure mode. */
		uint64_t reserved_18_24              : 7;
		uint64_t adr_offset                  : 18; /**< R/W - Sets the offset to the non-secure region of the DRAM/L2 address space.

                                                                 In 4 LMC mode, this specifies the address offset \<39:22\> for non-secure transaction.

                                                                 In 2 LMC mode, this specifies the address offset \<38:21\> for non-secure transaction. */
#else
		uint64_t adr_offset                  : 18;
		uint64_t reserved_18_24              : 7;
		uint64_t ns_scramble_dis             : 1;
		uint64_t reserved_26_63              : 38;
#endif
	} s;
	/* struct bdk_lmcx_ns_ctl_s           cn85xx; */
	/* struct bdk_lmcx_ns_ctl_s           cn88xx; */
	/* struct bdk_lmcx_ns_ctl_s           cn88xxp1; */
} bdk_lmcx_ns_ctl_t;

static inline uint64_t BDK_LMCX_NS_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_NS_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000178ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_NS_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_NS_CTL(...) bdk_lmcx_ns_ctl_t
#define bustype_BDK_LMCX_NS_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_NS_CTL(p1) (p1)
#define arguments_BDK_LMCX_NS_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_NS_CTL(...) "LMCX_NS_CTL"


/**
 * RSL - lmc#_nxm
 *
 * Following is the decoding for mem_msb/rank:
 * 0x0: mem_msb = mem_adr[25].
 * 0x1: mem_msb = mem_adr[26].
 * 0x2: mem_msb = mem_adr[27].
 * 0x3: mem_msb = mem_adr[28].
 * 0x4: mem_msb = mem_adr[29].
 * 0x5: mem_msb = mem_adr[30].
 * 0x6: mem_msb = mem_adr[31].
 * 0x7: mem_msb = mem_adr[32].
 * 0x8: mem_msb = mem_adr[33].
 * 0x9: mem_msb = mem_adr[34].
 * 0xA: mem_msb = mem_adr[35].
 * 0xB: mem_msb = mem_adr[36].
 * 0xC-0xF = Reserved.
 *
 * For example, for a DIMM made of Samsung's K4B1G0846C-ZCF7 1Gb (16M * 8 bit * 8 bank)
 * parts, the column address width = 10; so with 10b of col, 3b of bus, 3b of bank, row_lsb = 16.
 * Therefore, row = mem_adr[29:16] and mem_msb = 4.
 *
 * Note also that addresses greater than the max defined space (pbank_msb) are also treated as
 * NXM accesses.
 */
typedef union bdk_lmcx_nxm {
	uint64_t u;
	struct bdk_lmcx_nxm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t mem_msb_d1_r1               : 4;  /**< R/W - Maximum row MSB for DIMM1, RANK1/DIMM1 in single ranked.
                                                                 If DIMM1 is dual-sided, this should be set to
                                                                 NXM[MEM_MSB_D1_R0]. If CONFIG[RANK_ENA] is cleared, this field is ignored. */
		uint64_t mem_msb_d1_r0               : 4;  /**< R/W - Maximum row MSB for DIMM1, RANK0.
                                                                 if DIMM1 contains 3DS DRAMs, this would point to
                                                                 the logical rank's most significant bit. */
		uint64_t mem_msb_d0_r1               : 4;  /**< R/W - Maximum row MSB for DIMM0, RANK1/DIMM0 in single ranked.
                                                                 If DIMM0 is dual-sided, this should be set to
                                                                 NXM[MEM_MSB_D0_R0]. If CONFIG[RANK_ENA] is cleared, this field is ignored. */
		uint64_t mem_msb_d0_r0               : 4;  /**< R/W - Maximum row MSB for DIMM0, RANK0.
                                                                 If DIMM0 contains 3DS DRAMs, this would point to
                                                                 the logical rank's most significant bit. */
		uint64_t reserved_4_7                : 4;
		uint64_t cs_mask                     : 4;  /**< R/W - Chip select mask. This mask corresponds to the four chip selects for a memory
                                                                 configuration. If LMC()_CONFIG[RANK_ENA]=0 then this mask must be set in pairs because
                                                                 each reference address will assert a pair of chip selects. If the chip select(s) have a
                                                                 corresponding CS_MASK bit set, then the reference is to nonexistent memory (NXM). LMC will
                                                                 alias a NXM read reference to use the lowest, legal chip select(s) and return zeros. LMC
                                                                 normally discards NXM write operations, but will also alias them when LMC()_CONTROL
                                                                 [NXM_WRITE_EN]=1. */
#else
		uint64_t cs_mask                     : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t mem_msb_d0_r0               : 4;
		uint64_t mem_msb_d0_r1               : 4;
		uint64_t mem_msb_d1_r0               : 4;
		uint64_t mem_msb_d1_r1               : 4;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_lmcx_nxm_s              cn85xx; */
	/* struct bdk_lmcx_nxm_s              cn88xx; */
	/* struct bdk_lmcx_nxm_s              cn88xxp1; */
} bdk_lmcx_nxm_t;

static inline uint64_t BDK_LMCX_NXM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_NXM(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880000C8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_NXM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_NXM(...) bdk_lmcx_nxm_t
#define bustype_BDK_LMCX_NXM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_NXM(p1) (p1)
#define arguments_BDK_LMCX_NXM(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_NXM(...) "LMCX_NXM"


/**
 * RSL - lmc#_nxm_fadr
 *
 * This register captures only the first transaction with a NXM error while an interrupt is
 * pending, and only captures a subsequent event once the interrupt is cleared by writing a 1 to
 * LMC()_INT[NXM_ERR]. It captures the actual L2C-LMC address provided to the LMC that caused
 * the NXM error. A read or write NXM error is captured only if enabled using the NXM event
 * enables.
 */
typedef union bdk_lmcx_nxm_fadr {
	uint64_t u;
	struct bdk_lmcx_nxm_fadr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t nxm_faddr_ext               : 1;  /**< RO/H - Extended bit for the Failing L2C-LMC address (bit 37). */
		uint64_t nxm_src                     : 1;  /**< RO/H - Indicates the source of the operation that caused a NXM error:
                                                                 0 = L2C, 1 = HFA */
		uint64_t nxm_type                    : 1;  /**< RO/H - Indicates the type of operation that caused NXM error:
                                                                 0 = Read, 1 = Write */
		uint64_t nxm_faddr                   : 37; /**< RO/H - Failing L2C-LMC address. Bits\<3:0\> are always 0s for an HFA access, and bits\<4:0\> are
                                                                 always 0s for an L2C access. Bits\<5:4\> represent the fill order for an L2C read operation,
                                                                 and the start point within a cache line for a write operation. */
#else
		uint64_t nxm_faddr                   : 37;
		uint64_t nxm_type                    : 1;
		uint64_t nxm_src                     : 1;
		uint64_t nxm_faddr_ext               : 1;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_lmcx_nxm_fadr_s         cn85xx; */
	/* struct bdk_lmcx_nxm_fadr_s         cn88xx; */
	/* struct bdk_lmcx_nxm_fadr_s         cn88xxp1; */
} bdk_lmcx_nxm_fadr_t;

static inline uint64_t BDK_LMCX_NXM_FADR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_NXM_FADR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000028ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_NXM_FADR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_NXM_FADR(...) bdk_lmcx_nxm_fadr_t
#define bustype_BDK_LMCX_NXM_FADR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_NXM_FADR(p1) (p1)
#define arguments_BDK_LMCX_NXM_FADR(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_NXM_FADR(...) "LMCX_NXM_FADR"


/**
 * RSL - lmc#_ops_cnt
 */
typedef union bdk_lmcx_ops_cnt {
	uint64_t u;
	struct bdk_lmcx_ops_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t opscnt                      : 64; /**< RO/H - Performance counter. A 64-bit counter that increments when the DDR3 data bus is being
                                                                 used.
                                                                 DDR bus utilization = OPSCNT / LMC()_DCLK_CNT. */
#else
		uint64_t opscnt                      : 64;
#endif
	} s;
	/* struct bdk_lmcx_ops_cnt_s          cn85xx; */
	/* struct bdk_lmcx_ops_cnt_s          cn88xx; */
	/* struct bdk_lmcx_ops_cnt_s          cn88xxp1; */
} bdk_lmcx_ops_cnt_t;

static inline uint64_t BDK_LMCX_OPS_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_OPS_CNT(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001D8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_OPS_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_OPS_CNT(...) bdk_lmcx_ops_cnt_t
#define bustype_BDK_LMCX_OPS_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_OPS_CNT(p1) (p1)
#define arguments_BDK_LMCX_OPS_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_OPS_CNT(...) "LMCX_OPS_CNT"


/**
 * RSL - lmc#_phy_ctl
 */
typedef union bdk_lmcx_phy_ctl {
	uint64_t u;
	struct bdk_lmcx_phy_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_55_63              : 9;
		uint64_t c1_sel                      : 2;  /**< R/W - 0x0 = C1 is not routed to any output pin.
                                                                 0x1 = C1 is routed to CS3.
                                                                 0x2 = C1 is routed to A17 address pin.
                                                                 0x3 = C1 is not routed to any output pin. */
		uint64_t c0_sel                      : 2;  /**< R/W - 0x0 = C0 is not routed to any output pin.
                                                                 0x1 = C0 is routed to CS2.
                                                                 0x2 = C0 is routed to TEN output pin.
                                                                 0x3 = C0 is not routed to any output pin. */
		uint64_t phy_reset                   : 1;  /**< WO - Reserved. INTERNAL: Write to 1 to reset the PHY, one-shot operation, will automatically
                                                                 clear to value of 0. */
		uint64_t dsk_dbg_rd_complete         : 1;  /**< RO/H - Reserved. INTERNAL: Indicates completion of a read operation, will clear to 0 when a read
                                                                 operation is started, then set to 1 when operation is complete. */
		uint64_t dsk_dbg_rd_data             : 10; /**< RO/H - Reserved. INTERNAL: Data from a deskew read operation. Only valid when the
                                                                 LMC()_PHY_CTL[DSK_DBG_RD_COMPLETE] bit is set. */
		uint64_t dsk_dbg_rd_start            : 1;  /**< WO/H - Reserved. INTERNAL: Write 1 to start deskew data read operation, will automatically clear
                                                                 to 0. Write to 1 will also clear the complete bit. */
		uint64_t dsk_dbg_clk_scaler          : 2;  /**< R/W - Reserved. INTERNAL: Adjust clock toggle rate for reading deskew debug information:
                                                                 0x0 = Deskew read clock toggles every 4 DCLKs.
                                                                 0x1 = Deskew read clock toggles every 8 DCLKs.
                                                                 0x2 = Deskew read clock toggles every 12 DCLKs.
                                                                 0x3 = Deskew read clock toggles every 16 DCLKs. */
		uint64_t dsk_dbg_offset              : 2;  /**< R/W - Reserved. INTERNAL: Offset to change delay of deskew debug data return time to LMC from
                                                                 DDR PHY. */
		uint64_t dsk_dbg_num_bits_sel        : 1;  /**< R/W - Reserved. INTERNAL: Deskew debug, select number of bits per byte lane.
                                                                 0 = 8 bits per byte lane, no DBI.
                                                                 1 = 9 bits per byte lane, including DBI. */
		uint64_t dsk_dbg_byte_sel            : 4;  /**< R/W - Reserved. INTERNAL: Deskew debug byte select for read operation. Values 0-3 correspond to
                                                                 byte lanes 0-3, 4 is for ECC, 5-8 are byte lanes 4-7. */
		uint64_t dsk_dbg_bit_sel             : 4;  /**< R/W - Reserved. INTERNAL: Deskew debug bit select for dsk read operation. */
		uint64_t dbi_mode_ena                : 1;  /**< R/W - Enable DBI mode for PHY. */
		uint64_t ddr_error_n_ena             : 1;  /**< R/W - Enable error_alert_n signal for PHY. */
		uint64_t ref_pin_on                  : 1;  /**< R/W - Reserved. INTERNAL: Voltage reference pin enabled. */
		uint64_t dac_on                      : 1;  /**< R/W - Reserved. INTERNAL: PHY DAC on. */
		uint64_t int_pad_loopback_ena        : 1;  /**< R/W - Reserved. INTERNAL: DDR pad loopback enable.  Also must set LMCX_PHY_CTL[PHY_DSK_BYP]
                                                                 when loopback is enabled. */
		uint64_t int_phy_loopback_ena        : 1;  /**< R/W - Reserved. INTERNAL: PHY loopback enable. */
		uint64_t phy_dsk_reset               : 1;  /**< R/W - PHY deskew reset. When set, the deskew reset signal goes active if the Vrefint/deskew
                                                                 training sequence is in the idle state. */
		uint64_t phy_dsk_byp                 : 1;  /**< R/W - PHY deskew bypass. */
		uint64_t phy_pwr_save_disable        : 1;  /**< R/W - DDR PHY power save disable. */
		uint64_t ten                         : 1;  /**< R/W - DDR PHY test enable pin. */
		uint64_t rx_always_on                : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Set to force read_enable to PHY active all the time. */
		uint64_t lv_mode                     : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Low Voltage Mode (1.35V.) */
		uint64_t ck_tune1                    : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Clock tune. */
		uint64_t ck_dlyout1                  : 4;  /**< R/W - Reserved; must be zero. INTERNAL: Clock delay out. */
		uint64_t ck_tune0                    : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Clock tune. */
		uint64_t ck_dlyout0                  : 4;  /**< R/W - Reserved; must be zero. INTERNAL: Clock delay out. */
		uint64_t loopback                    : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Loopback enable. */
		uint64_t loopback_pos                : 1;  /**< R/W - Reserved; must be zero. INTERNAL: Loopback pos mode. */
		uint64_t ts_stagger                  : 1;  /**< R/W - TS stagger mode. This mode configures output drivers with two-stage drive strength to
                                                                 avoid undershoot issues on the bus when strong drivers are suddenly turned on. When this
                                                                 mode is asserted, CNXXXX will configure output drivers to be weak drivers (60ohm output
                                                                 impedance) at the first CK cycle, and change drivers to the designated drive strengths
                                                                 specified in LMC()_COMP_CTL2[CMD_CTL/CK_CTL/DQX_CTL] starting at the following cycle. */
#else
		uint64_t ts_stagger                  : 1;
		uint64_t loopback_pos                : 1;
		uint64_t loopback                    : 1;
		uint64_t ck_dlyout0                  : 4;
		uint64_t ck_tune0                    : 1;
		uint64_t ck_dlyout1                  : 4;
		uint64_t ck_tune1                    : 1;
		uint64_t lv_mode                     : 1;
		uint64_t rx_always_on                : 1;
		uint64_t ten                         : 1;
		uint64_t phy_pwr_save_disable        : 1;
		uint64_t phy_dsk_byp                 : 1;
		uint64_t phy_dsk_reset               : 1;
		uint64_t int_phy_loopback_ena        : 1;
		uint64_t int_pad_loopback_ena        : 1;
		uint64_t dac_on                      : 1;
		uint64_t ref_pin_on                  : 1;
		uint64_t ddr_error_n_ena             : 1;
		uint64_t dbi_mode_ena                : 1;
		uint64_t dsk_dbg_bit_sel             : 4;
		uint64_t dsk_dbg_byte_sel            : 4;
		uint64_t dsk_dbg_num_bits_sel        : 1;
		uint64_t dsk_dbg_offset              : 2;
		uint64_t dsk_dbg_clk_scaler          : 2;
		uint64_t dsk_dbg_rd_start            : 1;
		uint64_t dsk_dbg_rd_data             : 10;
		uint64_t dsk_dbg_rd_complete         : 1;
		uint64_t phy_reset                   : 1;
		uint64_t c0_sel                      : 2;
		uint64_t c1_sel                      : 2;
		uint64_t reserved_55_63              : 9;
#endif
	} s;
	/* struct bdk_lmcx_phy_ctl_s          cn85xx; */
	/* struct bdk_lmcx_phy_ctl_s          cn88xx; */
	/* struct bdk_lmcx_phy_ctl_s          cn88xxp1; */
} bdk_lmcx_phy_ctl_t;

static inline uint64_t BDK_LMCX_PHY_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_PHY_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000210ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_PHY_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_PHY_CTL(...) bdk_lmcx_phy_ctl_t
#define bustype_BDK_LMCX_PHY_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_PHY_CTL(p1) (p1)
#define arguments_BDK_LMCX_PHY_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_PHY_CTL(...) "LMCX_PHY_CTL"


/**
 * RSL - lmc#_ppr_ctl
 *
 * This register contains programmable timing and control parameters used
 * when running the post package repair sequence. The timing fields
 * PPR_CTL[TPGMPST], PPR_CTL[TPGM_EXIT] and PPR_CTL[TPGM] need to be set as
 * to satisfy the minimum values mentioned in the JEDEC DDR4 spec before
 * running the PPR sequence. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] to run
 * the PPR sequence.
 *
 * Running Hard PPR may require LMC to issue Security Key as four consecutive
 * MR0 commands, each with a unique address field A[17:0]. Set the Security
 * Key in the general purpose CSRs as follows:
 *
 * _ Security Key 0 = LMC()_GENERAL_PURPOSE0[DATA]\<17:0\>.
 * _ Security Key 1 = LMC()_GENERAL_PURPOSE0[DATA]\<35:18\>.
 * _ Security Key 2 = LMC()_GENERAL_PURPOSE1[DATA]\<17:0\>.
 * _ Security Key 3 = LMC()_GENERAL_PURPOSE1[DATA]\<35:18\>.
 */
typedef union bdk_lmcx_ppr_ctl {
	uint64_t u;
	struct bdk_lmcx_ppr_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t skip_issue_security         : 1;  /**< R/W - Personality bit for the PPR sequence. When set, this field forces the sequence to skip
                                                                 issuing four consecutive MR0 commands that suppliy the Security Key. */
		uint64_t sppr                        : 1;  /**< R/W - Personality bit for the PPR sequence. When set, this field forces the sequence to run
                                                                 the Soft PPR mode. */
		uint64_t tpgm                        : 10; /**< R/W - Indicates the programming time (tPGM) constraint used when running PPR sequence.

                                                                 For hard PPR (PPR_CTL[SPPR] = 0), set this field as follows:
                                                                 RNDUP[TPGM(ns) / (1048576 * TCYC(ns))].

                                                                 For soft PPR (PPR_CTL[SPPR] = 1), set this field as follows:
                                                                 RNDUP[TPGM(ns) / TCYC(ns))].

                                                                 TPGM is from the JEDEC DDR4 spec, and TCYC(ns) is the DDR clock frequency (not data
                                                                 rate). */
		uint64_t tpgm_exit                   : 5;  /**< R/W - Indicates PPR Exit time (tPGM_Exit) contrainst used when running PPR sequence.
                                                                 Set this field as follows:
                                                                 _ RNDUP[TPGM_EXIT(ns) / TCYC(ns)]

                                                                 where TPGM_EXIT is from the JEDEC DDR4 spec, and TCYC(ns) is the DDR clock frequency (not
                                                                 data rate). */
		uint64_t tpgmpst                     : 7;  /**< R/W - Indicates New Address Setting time (tPGMPST) constraint used when running PPR sequence.
                                                                 Set this field as follows:

                                                                 _ RNDUP[TPGMPST(ns) / (1024 * TCYC(ns))]

                                                                 where TPGMPST is from the JEDEC DDR4 spec, and TCYC(ns) is the DDR clock frequency (not
                                                                 data rate). */
#else
		uint64_t tpgmpst                     : 7;
		uint64_t tpgm_exit                   : 5;
		uint64_t tpgm                        : 10;
		uint64_t sppr                        : 1;
		uint64_t skip_issue_security         : 1;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_lmcx_ppr_ctl_s          cn85xx; */
	/* struct bdk_lmcx_ppr_ctl_s          cn88xx; */
	/* struct bdk_lmcx_ppr_ctl_s          cn88xxp1; */
} bdk_lmcx_ppr_ctl_t;

static inline uint64_t BDK_LMCX_PPR_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_PPR_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880003E0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_PPR_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_PPR_CTL(...) bdk_lmcx_ppr_ctl_t
#define bustype_BDK_LMCX_PPR_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_PPR_CTL(p1) (p1)
#define arguments_BDK_LMCX_PPR_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_PPR_CTL(...) "LMCX_PPR_CTL"


/**
 * RSL - lmc#_ref_status
 *
 * This register contains the status of the refresh pending counter.
 *
 */
typedef union bdk_lmcx_ref_status {
	uint64_t u;
	struct bdk_lmcx_ref_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t ref_pend_max_clr            : 1;  /**< R/W1C/H - Indicates that the number of pending refreshes has reached 7. Requiring
                                                                 software to clear the flag by setting this field to 1. */
		uint64_t ref_count                   : 3;  /**< RO/H - Reads back the number of pending refreshes that LMC has yet to execute. */
#else
		uint64_t ref_count                   : 3;
		uint64_t ref_pend_max_clr            : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_lmcx_ref_status_s       cn85xx; */
	/* struct bdk_lmcx_ref_status_s       cn88xx; */
	/* struct bdk_lmcx_ref_status_s       cn88xxp1; */
} bdk_lmcx_ref_status_t;

static inline uint64_t BDK_LMCX_REF_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_REF_STATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880000A0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_REF_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_REF_STATUS(...) bdk_lmcx_ref_status_t
#define bustype_BDK_LMCX_REF_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_REF_STATUS(p1) (p1)
#define arguments_BDK_LMCX_REF_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_REF_STATUS(...) "LMCX_REF_STATUS"


/**
 * RSL - lmc#_reset_ctl
 *
 * Specify the RSL base addresses for the block.
 *
 */
typedef union bdk_lmcx_reset_ctl {
	uint64_t u;
	struct bdk_lmcx_reset_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t ddr3psv                     : 1;  /**< R/W/H - Memory reset. 1 = DDR contents preserved.

                                                                 May be useful for system software to determine when the DDR3/DDR4 contents have been
                                                                 preserved.
                                                                 Cleared by hardware during a cold reset. Never cleared by hardware during a warm/soft
                                                                 reset. Set by hardware during a warm/soft reset if the hardware automatically put the
                                                                 DDR3/DDR4
                                                                 DRAM into self-refresh during the reset sequence.
                                                                 Can also be written by software (to any value). */
		uint64_t ddr3psoft                   : 1;  /**< R/W/H - Memory reset. 1 = Enable preserve mode during soft reset.

                                                                 Enables preserve mode during a soft reset. When set, the DDR3/DDR4 controller hardware
                                                                 automatically puts the attached DDR3/DDR4 DRAM parts into self-refresh at the beginning of
                                                                 a
                                                                 soft reset sequence (see LMC()_SEQ_CTL[SEQ_SEL]), provided that the DDR3/DDR4 controller
                                                                 is up. When clear, the DDR3/DDR4 controller hardware does not put the attached DDR3/DDR4
                                                                 DRAM
                                                                 parts into self-refresh during a soft reset sequence.
                                                                 DDR3PSOFT is cleared on a cold reset. Warm and soft chip resets do not affect the
                                                                 DDR3PSOFT value. Outside of cold reset, only software CSR write operations change the
                                                                 DDR3PSOFT value. */
		uint64_t ddr3pwarm                   : 1;  /**< R/W/H - Memory reset. 1 = Enable preserve mode during warm reset.

                                                                 Enables preserve mode during a warm reset. When set, the DDR3/DDR4 controller hardware
                                                                 automatically puts the attached DDR3/DDR4 DRAM parts into self-refresh at the beginning of
                                                                 a
                                                                 warm reset sequence (see LMC()_SEQ_CTL[SEQ_SEL]), provided that the DDR3/DDR4 controller
                                                                 is up. When clear, the DDR3/DDR4 controller hardware does not put the attached DDR3/DDR4
                                                                 DRAM
                                                                 parts into self-refresh during a warm reset sequence.
                                                                 DDR3PWARM is cleared on a cold reset. Warm and soft chip resets do not affect the
                                                                 DDR3PWARM value. Outside of cold reset, only software CSR write operations change the
                                                                 DDR3PWARM value.

                                                                 Note that if a warm reset follows a soft reset, DDR3PWARM has no effect, as the DDR3/DDR4
                                                                 controller is no longer up after any cold/warm/soft reset sequence. */
		uint64_t ddr3rst                     : 1;  /**< R/W/H - "Memory reset. 0 = Reset asserted; 1 = Reset deasserted.

                                                                 DDR3/DDR4 DRAM parts have a RESET\# pin that was not present in DDR2 parts. The DDR3RST CSR
                                                                 field controls the assertion of the new CNXXXX pin that attaches to RESET\#. When DDR3RST
                                                                 is set, CNXXXX deasserts RESET\#. When DDR3RST is clear, CNXXXX asserts RESET\#.
                                                                 DDR3RST is cleared on a cold reset. Warm and soft chip resets do not affect the DDR3RST
                                                                 value.
                                                                 Outside of cold reset, only software CSR write operations change the DDR3RST value." */
#else
		uint64_t ddr3rst                     : 1;
		uint64_t ddr3pwarm                   : 1;
		uint64_t ddr3psoft                   : 1;
		uint64_t ddr3psv                     : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_lmcx_reset_ctl_s        cn85xx; */
	/* struct bdk_lmcx_reset_ctl_s        cn88xx; */
	/* struct bdk_lmcx_reset_ctl_s        cn88xxp1; */
} bdk_lmcx_reset_ctl_t;

static inline uint64_t BDK_LMCX_RESET_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RESET_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000180ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_RESET_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RESET_CTL(...) bdk_lmcx_reset_ctl_t
#define bustype_BDK_LMCX_RESET_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RESET_CTL(p1) (p1)
#define arguments_BDK_LMCX_RESET_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_RESET_CTL(...) "LMCX_RESET_CTL"


/**
 * RSL - lmc#_retry_config
 *
 * This register configures automatic retry operation.
 *
 */
typedef union bdk_lmcx_retry_config {
	uint64_t u;
	struct bdk_lmcx_retry_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t max_errors                  : 24; /**< R/W - Maximum number of errors before errors are ignored. */
		uint64_t reserved_13_31              : 19;
		uint64_t error_continue              : 1;  /**< WO - If LMC()_RETRY_CONFIG[AUTO_ERROR_CONTINUE] is cleared, LMC will wait
                                                                 for a 1 to be written to LMC()_RETRY_CONFIG[ERROR_CONTINUE] before
                                                                 continuing operations after an error. */
		uint64_t reserved_9_11               : 3;
		uint64_t auto_error_continue         : 1;  /**< R/W - When set, LMC will automatically proceed with error handling and normal
                                                                 operation after an error occurs.  If clear, LMC will cease all operations
                                                                 except for refresh as soon as possible, and will not continue with error
                                                                 handling or normal operation until LMC()_RETRY_CONFIG[ERROR_CONTINUE]
                                                                 is written with a 1. */
		uint64_t reserved_5_7                : 3;
		uint64_t pulse_count_auto_clr        : 1;  /**< R/W - When set, LMC()_RETRY_STATUS[ERROR_PULSE_COUNT_VALID] will clear
                                                                 whenever the error interrupt is cleared. */
		uint64_t reserved_1_3                : 3;
		uint64_t retry_enable                : 1;  /**< R/W - Enable retry on errors. */
#else
		uint64_t retry_enable                : 1;
		uint64_t reserved_1_3                : 3;
		uint64_t pulse_count_auto_clr        : 1;
		uint64_t reserved_5_7                : 3;
		uint64_t auto_error_continue         : 1;
		uint64_t reserved_9_11               : 3;
		uint64_t error_continue              : 1;
		uint64_t reserved_13_31              : 19;
		uint64_t max_errors                  : 24;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_lmcx_retry_config_s     cn85xx; */
	/* struct bdk_lmcx_retry_config_s     cn88xx; */
	/* struct bdk_lmcx_retry_config_s     cn88xxp1; */
} bdk_lmcx_retry_config_t;

static inline uint64_t BDK_LMCX_RETRY_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RETRY_CONFIG(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000110ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_RETRY_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RETRY_CONFIG(...) bdk_lmcx_retry_config_t
#define bustype_BDK_LMCX_RETRY_CONFIG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RETRY_CONFIG(p1) (p1)
#define arguments_BDK_LMCX_RETRY_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_RETRY_CONFIG(...) "LMCX_RETRY_CONFIG"


/**
 * RSL - lmc#_retry_status
 *
 * This register provides status on automatic retry operation.
 *
 */
typedef union bdk_lmcx_retry_status {
	uint64_t u;
	struct bdk_lmcx_retry_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t clear_error_count           : 1;  /**< WO - Clear the error count, one shot operation. */
		uint64_t clear_error_pulse_count     : 1;  /**< WO - Clear the error count, one shot operation. */
		uint64_t reserved_57_61              : 5;
		uint64_t error_pulse_count_valid     : 1;  /**< RO/H - When set and the count is valid, indicates that the counter has saturated,
                                                                 which effectively indicates that a command error has occured and not a CRC
                                                                 error. */
		uint64_t error_pulse_count_sat       : 1;  /**< RO/H - When set and the count is valid, indicates that the counter has saturated,
                                                                 which effectively indicates that a command error has occured and not a CRC
                                                                 error. */
		uint64_t reserved_52_54              : 3;
		uint64_t error_pulse_count           : 4;  /**< RO/H - Count of cycles in last error pulse since clear.  This count will be cleared
                                                                 either by clearing the interrupt or writing a 1 to the pulse count clear bit. */
		uint64_t reserved_45_47              : 3;
		uint64_t error_sequence              : 5;  /**< RO/H - Sequence number for sequence that was running when error occurred. */
		uint64_t reserved_33_39              : 7;
		uint64_t error_type                  : 1;  /**< RO/H - 0 = Error during a sequence run.
                                                                 1 = Error during normal operation, which means a read or write operation. Effectively this
                                                                 means a command error for a read or write operation, or a CRC error for a write data
                                                                 operation. */
		uint64_t reserved_24_31              : 8;
		uint64_t error_count                 : 24; /**< RO/H - Number of errors encountered since last cleared. */
#else
		uint64_t error_count                 : 24;
		uint64_t reserved_24_31              : 8;
		uint64_t error_type                  : 1;
		uint64_t reserved_33_39              : 7;
		uint64_t error_sequence              : 5;
		uint64_t reserved_45_47              : 3;
		uint64_t error_pulse_count           : 4;
		uint64_t reserved_52_54              : 3;
		uint64_t error_pulse_count_sat       : 1;
		uint64_t error_pulse_count_valid     : 1;
		uint64_t reserved_57_61              : 5;
		uint64_t clear_error_pulse_count     : 1;
		uint64_t clear_error_count           : 1;
#endif
	} s;
	/* struct bdk_lmcx_retry_status_s     cn85xx; */
	/* struct bdk_lmcx_retry_status_s     cn88xx; */
	/* struct bdk_lmcx_retry_status_s     cn88xxp1; */
} bdk_lmcx_retry_status_t;

static inline uint64_t BDK_LMCX_RETRY_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RETRY_STATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000118ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_RETRY_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RETRY_STATUS(...) bdk_lmcx_retry_status_t
#define bustype_BDK_LMCX_RETRY_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RETRY_STATUS(p1) (p1)
#define arguments_BDK_LMCX_RETRY_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_RETRY_STATUS(...) "LMCX_RETRY_STATUS"


/**
 * RSL - lmc#_rlevel_ctl
 */
typedef union bdk_lmcx_rlevel_ctl {
	uint64_t u;
	struct bdk_lmcx_rlevel_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pattern                     : 8;  /**< R/W - Sets the data pattern used to match in read-leveling operations. */
		uint64_t reserved_22_23              : 2;
		uint64_t delay_unload_3              : 1;  /**< R/W - Reserved, must be set.  INTERNAL: When set, unload the PHY silo one cycle later during
                                                                 read-leveling if LMC()_RLEVEL_RANK()[BYTE*\<1:0\>] = 3. DELAY_UNLOAD_3 should
                                                                 normally be set, particularly at higher speeds. */
		uint64_t delay_unload_2              : 1;  /**< R/W - Reserved, must be set.  INTERNAL: When set, unload the PHY silo one cycle later during
                                                                 read-leveling if LMC()_RLEVEL_RANK()[BYTE*\<1:0\>] = 2. DELAY_UNLOAD_2 should
                                                                 normally be set. */
		uint64_t delay_unload_1              : 1;  /**< R/W - Reserved, must be set.  INTERNAL: When set, unload the PHY silo one cycle later during
                                                                 read-leveling if LMC()_RLEVEL_RANK()[BYTE*\<1:0\>] = 1. DELAY_UNLOAD_1 should
                                                                 normally be set. */
		uint64_t delay_unload_0              : 1;  /**< R/W - Reserved, must be set.  INTERNAL: When set, unload the PHY silo one cycle later during
                                                                 read-leveling if LMC()_RLEVEL_RANK()[BYTE*\<1:0\>] = 0. DELAY_UNLOAD_0 should
                                                                 normally be set. */
		uint64_t bitmask                     : 8;  /**< R/W - Mask to select bit lanes on which read-leveling feedback is returned when OR_DIS is set to 1. */
		uint64_t or_dis                      : 1;  /**< R/W - Disable ORing of bits in a byte lane when computing the read-leveling bitmask. OR_DIS
                                                                 should normally not be set. */
		uint64_t offset_en                   : 1;  /**< R/W - When set, LMC attempts to select the read-leveling setting that is
                                                                 LMC()_RLEVEL_CTL[OFFSET] settings earlier than the last passing read-leveling setting
                                                                 in the largest contiguous sequence of passing settings. When clear, or if the setting
                                                                 selected by LMC()_RLEVEL_CTL[OFFSET] did not pass, LMC selects the middle setting in
                                                                 the largest contiguous sequence of passing settings, rounding earlier when necessary. */
		uint64_t offset                      : 4;  /**< R/W - The offset used when LMC()_RLEVEL_CTL[OFFSET] is set. */
		uint64_t byte                        : 4;  /**< R/W - 0 \<= BYTE \<= 8. Byte index for which bitmask results are saved in LMC()_RLEVEL_DBG. */
#else
		uint64_t byte                        : 4;
		uint64_t offset                      : 4;
		uint64_t offset_en                   : 1;
		uint64_t or_dis                      : 1;
		uint64_t bitmask                     : 8;
		uint64_t delay_unload_0              : 1;
		uint64_t delay_unload_1              : 1;
		uint64_t delay_unload_2              : 1;
		uint64_t delay_unload_3              : 1;
		uint64_t reserved_22_23              : 2;
		uint64_t pattern                     : 8;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_lmcx_rlevel_ctl_s       cn85xx; */
	/* struct bdk_lmcx_rlevel_ctl_s       cn88xx; */
	/* struct bdk_lmcx_rlevel_ctl_s       cn88xxp1; */
} bdk_lmcx_rlevel_ctl_t;

static inline uint64_t BDK_LMCX_RLEVEL_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RLEVEL_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880002A0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_RLEVEL_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RLEVEL_CTL(...) bdk_lmcx_rlevel_ctl_t
#define bustype_BDK_LMCX_RLEVEL_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RLEVEL_CTL(p1) (p1)
#define arguments_BDK_LMCX_RLEVEL_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_RLEVEL_CTL(...) "LMCX_RLEVEL_CTL"


/**
 * RSL - lmc#_rlevel_dbg
 *
 * A given read of LMC()_RLEVEL_DBG returns the read-leveling pass/fail results for all
 * possible delay settings (i.e. the BITMASK) for only one byte in the last rank that the
 * hardware ran read-leveling on. LMC()_RLEVEL_CTL[BYTE] selects the particular byte. To get
 * these pass/fail results for a different rank, you must run the hardware read-leveling again.
 * For example, it is possible to get the BITMASK results for every byte of every rank if you run
 * read-leveling separately for each rank, probing LMC()_RLEVEL_DBG between each read-
 * leveling.
 */
typedef union bdk_lmcx_rlevel_dbg {
	uint64_t u;
	struct bdk_lmcx_rlevel_dbg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bitmask                     : 64; /**< RO/H - Bitmask generated during read level settings sweep. BITMASK[n] = 0 means read level
                                                                 setting n failed; BITMASK[n] = 1 means read level setting n passed for 0 \<= n \<= 63. */
#else
		uint64_t bitmask                     : 64;
#endif
	} s;
	/* struct bdk_lmcx_rlevel_dbg_s       cn85xx; */
	/* struct bdk_lmcx_rlevel_dbg_s       cn88xx; */
	/* struct bdk_lmcx_rlevel_dbg_s       cn88xxp1; */
} bdk_lmcx_rlevel_dbg_t;

static inline uint64_t BDK_LMCX_RLEVEL_DBG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RLEVEL_DBG(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880002A8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_RLEVEL_DBG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RLEVEL_DBG(...) bdk_lmcx_rlevel_dbg_t
#define bustype_BDK_LMCX_RLEVEL_DBG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RLEVEL_DBG(p1) (p1)
#define arguments_BDK_LMCX_RLEVEL_DBG(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_RLEVEL_DBG(...) "LMCX_RLEVEL_DBG"


/**
 * RSL - lmc#_rlevel_rank#
 *
 * Four of these CSRs exist per LMC, one for each rank. Read level setting is measured in units
 * of 1/4 CK, so the BYTEn values can range over 16 CK cycles. Each CSR is written by hardware
 * during a read-leveling sequence for the rank. (Hardware sets STATUS to 3 after hardware read-
 * leveling completes for the rank.)
 * If hardware is unable to find a match per LMC()_RLEVEL_CTL[OFFSET_EN] and
 * LMC()_RLEVEL_CTL[OFFSET], then hardware sets LMC()_RLEVEL_RANK()[BYTEn\<5:0\>] to
 * 0x0.
 *
 * Each CSR may also be written by software, but not while a read-leveling sequence is in
 * progress. (Hardware sets STATUS to 1 after a CSR write.) Software initiates a hardware read-
 * leveling sequence by programming LMC()_RLEVEL_CTL and writing INIT_START = 1 with
 * SEQ_SEL=1. See LMC()_RLEVEL_CTL.
 *
 * LMC()_RLEVEL_RANKi values for ranks i without attached DRAM should be set such that they do
 * not
 * increase the range of possible BYTE values for any byte lane. The easiest way to do this is to
 * set LMC()_RLEVEL_RANKi = LMC()_RLEVEL_RANKj, where j is some rank with attached DRAM whose
 * LMC()_RLEVEL_RANKj is already fully initialized.
 */
typedef union bdk_lmcx_rlevel_rankx {
	uint64_t u;
	struct bdk_lmcx_rlevel_rankx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t status                      : 2;  /**< RO/H - Indicates status of the read-leveling and where the BYTEn programmings in \<53:0\> came
                                                                 from:
                                                                 0x0 = BYTEn values are their reset value.
                                                                 0x1 = BYTEn values were set via a CSR write to this register.
                                                                 0x2 = read-leveling sequence currently in progress (BYTEn values are unpredictable).
                                                                 0x3 = BYTEn values came from a complete read-leveling sequence. */
		uint64_t byte8                       : 6;  /**< R/W/H - "Read level setting.
                                                                 When ECC DRAM is not present in 64-bit mode (i.e. when DRAM is not attached to chip
                                                                 signals DDR\#_CBS_0_* and DDR\#_CB\<7:0\>), software should write BYTE8 to a value that does
                                                                 not increase the range of possible BYTE* values. The easiest way to do this is to set
                                                                 LMC()_RLEVEL_RANK()[BYTE8] = LMC()_RLEVEL_RANK()[BYTE0] when there is no
                                                                 ECC DRAM, using the final BYTE0 value." */
		uint64_t byte7                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte6                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte5                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte4                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte3                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte2                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte1                       : 6;  /**< R/W/H - Read level setting. */
		uint64_t byte0                       : 6;  /**< R/W/H - Read level setting. */
#else
		uint64_t byte0                       : 6;
		uint64_t byte1                       : 6;
		uint64_t byte2                       : 6;
		uint64_t byte3                       : 6;
		uint64_t byte4                       : 6;
		uint64_t byte5                       : 6;
		uint64_t byte6                       : 6;
		uint64_t byte7                       : 6;
		uint64_t byte8                       : 6;
		uint64_t status                      : 2;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_lmcx_rlevel_rankx_s     cn85xx; */
	/* struct bdk_lmcx_rlevel_rankx_s     cn88xx; */
	/* struct bdk_lmcx_rlevel_rankx_s     cn88xxp1; */
} bdk_lmcx_rlevel_rankx_t;

static inline uint64_t BDK_LMCX_RLEVEL_RANKX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RLEVEL_RANKX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 3)))
		return 0x000087E088000280ull + (param1 & 3) * 0x1000000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_LMCX_RLEVEL_RANKX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RLEVEL_RANKX(...) bdk_lmcx_rlevel_rankx_t
#define bustype_BDK_LMCX_RLEVEL_RANKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RLEVEL_RANKX(p1,p2) (p1)
#define arguments_BDK_LMCX_RLEVEL_RANKX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_RLEVEL_RANKX(...) "LMCX_RLEVEL_RANKX"


/**
 * RSL - lmc#_rodt_mask
 *
 * System designers may desire to terminate DQ/DQS lines for higher frequency DDR operations,
 * especially on a multirank system. DDR3 DQ/DQS I/Os have built-in termination resistors that
 * can be turned on or off by the controller, after meeting TAOND and TAOF timing requirements.
 *
 * Each rank has its own ODT pin that fans out to all the memory parts in that DIMM. System
 * designers may prefer different combinations of ODT ONs for read operations into different
 * ranks. CNXXXX supports full programmability by way of the mask register below. Each rank
 * position has its own 4-bit programmable field. When the controller does a read to that rank,
 * it sets the 4 ODT pins to the MASK pins below. For example, when doing a read from Rank0, a
 * system designer may desire to terminate the lines with the resistor on DIMM0/Rank1. The mask
 * RODT_D0_R0 would then be {0010}.
 *
 * CNXXXX drives the appropriate mask values on the ODT pins by default. If this feature is not
 * required, write 0x0 in this register. Note that, as per the JEDEC DDR3 specifications, the ODT
 * pin for the rank that is being read should always be 0x0.
 * When a given RANK is selected, the RODT mask for that rank is used. The resulting RODT mask is
 * driven to the DIMMs in the following manner:
 */
typedef union bdk_lmcx_rodt_mask {
	uint64_t u;
	struct bdk_lmcx_rodt_mask_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t rodt_d1_r1                  : 4;  /**< R/W - Read ODT mask DIMM1, RANK1/DIMM1 in SingleRanked. If RANK_ENA=1, RODT_D1_R1\<3\> must be
                                                                 zero. Otherwise RODT_D1_R1\<3:0\> is not used and must be zero. */
		uint64_t reserved_20_23              : 4;
		uint64_t rodt_d1_r0                  : 4;  /**< R/W - Read ODT mask DIMM1, RANK0. If RANK_ENA=1, RODT_D1_RO\<2\> must be zero. Otherwise,
                                                                 RODT_D1_RO\<3:2,1\> must be zero. */
		uint64_t reserved_12_15              : 4;
		uint64_t rodt_d0_r1                  : 4;  /**< R/W - Read ODT mask DIMM0, RANK1/DIMM0 in SingleRanked. If RANK_ENA=1, RODT_D0_R1\<1\> must be
                                                                 zero. Otherwise, RODT_D0_R1\<3:0\> is not used and must be zero. */
		uint64_t reserved_4_7                : 4;
		uint64_t rodt_d0_r0                  : 4;  /**< R/W - Read ODT mask DIMM0, RANK0. If RANK_ENA=1, RODT_D0_RO\<0\> must be zero. Otherwise,
                                                                 RODT_D0_RO\<1:0,3\> must be zero. */
#else
		uint64_t rodt_d0_r0                  : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t rodt_d0_r1                  : 4;
		uint64_t reserved_12_15              : 4;
		uint64_t rodt_d1_r0                  : 4;
		uint64_t reserved_20_23              : 4;
		uint64_t rodt_d1_r1                  : 4;
		uint64_t reserved_28_63              : 36;
#endif
	} s;
	/* struct bdk_lmcx_rodt_mask_s        cn85xx; */
	/* struct bdk_lmcx_rodt_mask_s        cn88xx; */
	/* struct bdk_lmcx_rodt_mask_s        cn88xxp1; */
} bdk_lmcx_rodt_mask_t;

static inline uint64_t BDK_LMCX_RODT_MASK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_RODT_MASK(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000268ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_RODT_MASK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_RODT_MASK(...) bdk_lmcx_rodt_mask_t
#define bustype_BDK_LMCX_RODT_MASK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_RODT_MASK(p1) (p1)
#define arguments_BDK_LMCX_RODT_MASK(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_RODT_MASK(...) "LMCX_RODT_MASK"


/**
 * RSL - lmc#_scramble_cfg0
 */
typedef union bdk_lmcx_scramble_cfg0 {
	uint64_t u;
	struct bdk_lmcx_scramble_cfg0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t key                         : 64; /**< R/W/H - Scramble key for data. Prior to enabling scrambling this key should be generated from a
                                                                 cryptographically-secure random number generator such as RNM_RANDOM. */
#else
		uint64_t key                         : 64;
#endif
	} s;
	/* struct bdk_lmcx_scramble_cfg0_s    cn85xx; */
	/* struct bdk_lmcx_scramble_cfg0_s    cn88xx; */
	/* struct bdk_lmcx_scramble_cfg0_s    cn88xxp1; */
} bdk_lmcx_scramble_cfg0_t;

static inline uint64_t BDK_LMCX_SCRAMBLE_CFG0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SCRAMBLE_CFG0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000320ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SCRAMBLE_CFG0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SCRAMBLE_CFG0(...) bdk_lmcx_scramble_cfg0_t
#define bustype_BDK_LMCX_SCRAMBLE_CFG0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SCRAMBLE_CFG0(p1) (p1)
#define arguments_BDK_LMCX_SCRAMBLE_CFG0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SCRAMBLE_CFG0(...) "LMCX_SCRAMBLE_CFG0"


/**
 * RSL - lmc#_scramble_cfg1
 *
 * These registers set the aliasing that uses the lowest, legal chip select(s).
 *
 */
typedef union bdk_lmcx_scramble_cfg1 {
	uint64_t u;
	struct bdk_lmcx_scramble_cfg1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t key                         : 64; /**< R/W/H - Scramble key for addresses. Prior to enabling scrambling this key should be generated from
                                                                 a cryptographically-secure random number generator such as RNM_RANDOM. */
#else
		uint64_t key                         : 64;
#endif
	} s;
	/* struct bdk_lmcx_scramble_cfg1_s    cn85xx; */
	/* struct bdk_lmcx_scramble_cfg1_s    cn88xx; */
	/* struct bdk_lmcx_scramble_cfg1_s    cn88xxp1; */
} bdk_lmcx_scramble_cfg1_t;

static inline uint64_t BDK_LMCX_SCRAMBLE_CFG1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SCRAMBLE_CFG1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000328ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SCRAMBLE_CFG1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SCRAMBLE_CFG1(...) bdk_lmcx_scramble_cfg1_t
#define bustype_BDK_LMCX_SCRAMBLE_CFG1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SCRAMBLE_CFG1(p1) (p1)
#define arguments_BDK_LMCX_SCRAMBLE_CFG1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SCRAMBLE_CFG1(...) "LMCX_SCRAMBLE_CFG1"


/**
 * RSL - lmc#_scramble_cfg2
 */
typedef union bdk_lmcx_scramble_cfg2 {
	uint64_t u;
	struct bdk_lmcx_scramble_cfg2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t key                         : 64; /**< R/W/H - Scramble key for data. */
#else
		uint64_t key                         : 64;
#endif
	} s;
	/* struct bdk_lmcx_scramble_cfg2_s    cn85xx; */
	/* struct bdk_lmcx_scramble_cfg2_s    cn88xx; */
	/* struct bdk_lmcx_scramble_cfg2_s    cn88xxp1; */
} bdk_lmcx_scramble_cfg2_t;

static inline uint64_t BDK_LMCX_SCRAMBLE_CFG2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SCRAMBLE_CFG2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000338ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SCRAMBLE_CFG2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SCRAMBLE_CFG2(...) bdk_lmcx_scramble_cfg2_t
#define bustype_BDK_LMCX_SCRAMBLE_CFG2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SCRAMBLE_CFG2(p1) (p1)
#define arguments_BDK_LMCX_SCRAMBLE_CFG2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SCRAMBLE_CFG2(...) "LMCX_SCRAMBLE_CFG2"


/**
 * RSL - lmc#_scrambled_fadr
 *
 * LMC()_FADR captures the failing pre-scrambled address location (split into DIMM, bunk,
 * bank, etc). If scrambling is off, LMC()_FADR also captures the failing physical location
 * in the DRAM parts. LMC()_SCRAMBLED_FADR captures the actual failing address location in
 * the physical DRAM parts, i.e.:
 *
 * * If scrambling is on, LMC()_SCRAMBLED_FADR contains the failing physical location in the
 * DRAM parts (split into DIMM, bunk, bank, etc);
 *
 * * If scrambling is off, the pre-scramble and post-scramble addresses are the same, and so the
 * contents of LMC()_SCRAMBLED_FADR match the contents of LMC()_FADR.
 *
 * This register only captures the first transaction with ECC errors. A DED error can over-write
 * this register with its failing addresses if the first error was a SEC. If you write
 * LMC()_CONFIG -\> SEC_ERR/DED_ERR, it clears the error bits and captures the next failing
 * address. If FDIMM is 1, that means the error is in the higher DIMM.
 */
typedef union bdk_lmcx_scrambled_fadr {
	uint64_t u;
	struct bdk_lmcx_scrambled_fadr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t fcid                        : 3;  /**< RO/H - Failing CID number. */
		uint64_t fill_order                  : 2;  /**< RO/H - Fill order for failing transaction. */
		uint64_t fdimm                       : 1;  /**< RO/H - Failing DIMM number. */
		uint64_t fbunk                       : 1;  /**< RO/H - Failing rank number. */
		uint64_t fbank                       : 4;  /**< RO/H - Failing bank number. Bits \<3:0\>. */
		uint64_t frow                        : 18; /**< RO/H - Failing row address. Bits \<17:0\>. */
		uint64_t fcol                        : 14; /**< RO/H - Failing column address \<13:0\>. Technically, represents the address of the 128b data that
                                                                 had an ECC error, i.e., FCOL\<0\> is always 0. Can be used in conjunction with
                                                                 LMC()_CONFIG[DED_ERR] to isolate the 64b chunk of data in error. */
#else
		uint64_t fcol                        : 14;
		uint64_t frow                        : 18;
		uint64_t fbank                       : 4;
		uint64_t fbunk                       : 1;
		uint64_t fdimm                       : 1;
		uint64_t fill_order                  : 2;
		uint64_t fcid                        : 3;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_lmcx_scrambled_fadr_s   cn85xx; */
	/* struct bdk_lmcx_scrambled_fadr_s   cn88xx; */
	/* struct bdk_lmcx_scrambled_fadr_s   cn88xxp1; */
} bdk_lmcx_scrambled_fadr_t;

static inline uint64_t BDK_LMCX_SCRAMBLED_FADR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SCRAMBLED_FADR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000330ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SCRAMBLED_FADR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SCRAMBLED_FADR(...) bdk_lmcx_scrambled_fadr_t
#define bustype_BDK_LMCX_SCRAMBLED_FADR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SCRAMBLED_FADR(p1) (p1)
#define arguments_BDK_LMCX_SCRAMBLED_FADR(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SCRAMBLED_FADR(...) "LMCX_SCRAMBLED_FADR"


/**
 * RSL - lmc#_seq_ctl
 *
 * This register is used to initiate the various control sequences in the LMC.
 *
 */
typedef union bdk_lmcx_seq_ctl {
	uint64_t u;
	struct bdk_lmcx_seq_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t seq_complete                : 1;  /**< RO/H - Sequence complete. This bit is cleared when INIT_START is set to a 1 and then is set to 1
                                                                 when the sequence is completed. */
		uint64_t seq_sel                     : 4;  /**< R/W - Selects the sequence that LMC runs after a 0-\>1 transition on INIT_START.
                                                                 0x0 = Power-up/initialization:

                                                                 LMC()_CONFIG[RANKMASK] selects participating ranks (should be all ranks with attached
                                                                 DRAM). DDR*_DIMM*_CKE* signals are activated (if not already active). RDIMM register
                                                                 control words 0-15 are written to LMC()_CONFIG[RANKMASK]-selected RDIMMs when

                                                                 LMC()_CONTROL[RDIMM_ENA] = 1 and corresponding LMC()_DIMM_CTL[DIMM*_WMASK] bits
                                                                 are set. (Refer to LMC()_DIMM(0..1)_PARAMS and LMC()_DIMM_CTL descriptions for
                                                                 more details.)

                                                                 The DRAM registers MR0, MR1, MR2, and MR3 are written in the selected ranks.

                                                                 0x1 = Read-leveling:
                                                                 LMC()_CONFIG[RANKMASK] selects the rank to be read-leveled. MR3 written in the
                                                                 selected rank.

                                                                 0x2 = Self-refresh entry:
                                                                 LMC()_CONFIG[INIT_STATUS] selects the participating ranks (should be all ranks with
                                                                 attached DRAM). MR1 and MR2 are written in the selected ranks if
                                                                 LMC()_CONFIG[SREF_WITH_DLL] = 1. DDR*_DIMM*_CKE* signals de-activated.

                                                                 0x3 = Self-refresh exit:
                                                                 LMC()_CONFIG[RANKMASK] must be set to indicate participating ranks (should be all
                                                                 ranks with attached DRAM). DDR*_DIMM*_CKE* signals activated. MR0, MR1, MR2, and MR3 are
                                                                 written in the participating ranks if LMC()_CONFIG[SREF_WITH_DLL] = 1.
                                                                 LMC()_CONFIG[INIT_STATUS] is updated for ranks that are selected.

                                                                 0x6 = Write-leveling:
                                                                 LMC()_CONFIG[RANKMASK] selects the rank to be write-leveled.
                                                                 LMC()_CONFIG[INIT_STATUS] must indicate all ranks with attached DRAM. MR1 and MR2
                                                                 written in the LMC()_CONFIG[INIT_STATUS]-selected ranks.

                                                                 0x7 = Initialize RCW:
                                                                 LMC()_CONFIG[RANKMASK] selects participating ranks (should be all ranks with attached
                                                                 DRAM). In DDR3 mode, RDIMM register control words 0-15 are written to
                                                                 LMC()_CONFIG[RANKMASK]-selected RDIMMs when LMC()_CONTROL[RDIMM_ENA] = 1 and
                                                                 corresponding LMC()_DIMM_CTL[DIMM*_WMASK] bits are set. (Refer to
                                                                 LMC()_DIMM(0..1)_PARAMS and LMC()_DIMM_CTL descriptions for more details.) */
		uint64_t init_start                  : 1;  /**< WO - A 0-\>1 transition starts the DDR memory sequence that is selected by
                                                                 LMC()_SEQ_CTL[SEQ_SEL].
                                                                 This register is a one-shot and clears itself each time it is set. */
#else
		uint64_t init_start                  : 1;
		uint64_t seq_sel                     : 4;
		uint64_t seq_complete                : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_lmcx_seq_ctl_s          cn85xx; */
	/* struct bdk_lmcx_seq_ctl_s          cn88xx; */
	/* struct bdk_lmcx_seq_ctl_s          cn88xxp1; */
} bdk_lmcx_seq_ctl_t;

static inline uint64_t BDK_LMCX_SEQ_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SEQ_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000048ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SEQ_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SEQ_CTL(...) bdk_lmcx_seq_ctl_t
#define bustype_BDK_LMCX_SEQ_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SEQ_CTL(p1) (p1)
#define arguments_BDK_LMCX_SEQ_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SEQ_CTL(...) "LMCX_SEQ_CTL"


/**
 * RSL - lmc#_slot_ctl0
 *
 * This register is an assortment of control fields needed by the memory controller. If software
 * has not previously written to this register (since the last DRESET), hardware updates the
 * fields in this register to the minimum allowed value when any of LMC()_RLEVEL_RANK(),
 * LMC()_WLEVEL_RANK(), LMC()_CONTROL, and LMC()_MODEREG_PARAMS0 registers
 * change. Ideally, only read this register after LMC has been initialized and
 * LMC()_RLEVEL_RANK(), LMC()_WLEVEL_RANK() have valid data.
 *
 * The interpretation of the fields in this register depends on LMC(0)_CONFIG[DDR2T]:
 *
 * * If LMC()_CONFIG[DDR2T]=1, (FieldValue + 4) is the minimum CK cycles between when
 * the DRAM part registers CAS commands of the first and second types from different cache
 * blocks.
 *
 * If LMC()_CONFIG[DDR2T]=0, (FieldValue + 3) is the minimum CK cycles between when the DRAM
 * part registers CAS commands of the first and second types from different cache blocks.
 * FieldValue = 0 is always illegal in this case.
 * The hardware-calculated minimums for these fields are shown in LMC(0)_SLOT_CTL0 Hardware-
 * Calculated Minimums.
 */
typedef union bdk_lmcx_slot_ctl0 {
	uint64_t u;
	struct bdk_lmcx_slot_ctl0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t w2w_l_init                  : 6;  /**< R/W/H - Write-to-write spacing control for back-to-back write followed by write cache block
                                                                 accesses to the same rank and DIMM, and same BG for DDR4. */
		uint64_t w2r_l_init                  : 6;  /**< R/W/H - Write-to-read spacing control for back-to-back write followed by read cache block accesses
                                                                 to the same rank and DIMM, and same BG for DDR4. */
		uint64_t r2w_l_init                  : 6;  /**< R/W/H - Read-to-write spacing control for back-to-back read followed by write cache block accesses
                                                                 to the same rank and DIMM, and same BG for DDR4. */
		uint64_t r2r_l_init                  : 6;  /**< R/W/H - Read-to-read spacing control for back-to-back read followed by read cache block accesses
                                                                 to the same rank and DIMM, and same BG for DDR4. */
		uint64_t w2w_init                    : 6;  /**< R/W/H - Write-to-write spacing control for back-to-back write followed by write cache block
                                                                 accesses to the same rank and DIMM. */
		uint64_t w2r_init                    : 6;  /**< R/W/H - Write-to-read spacing control for back-to-back write followed by read cache block accesses
                                                                 to the same rank and DIMM. */
		uint64_t r2w_init                    : 6;  /**< R/W/H - Read-to-write spacing control for back-to-back read followed by write cache block accesses
                                                                 to the same rank and DIMM. */
		uint64_t r2r_init                    : 6;  /**< R/W/H - Read-to-read spacing control for back-to-back read followed by read cache block accesses
                                                                 to the same rank and DIMM. */
#else
		uint64_t r2r_init                    : 6;
		uint64_t r2w_init                    : 6;
		uint64_t w2r_init                    : 6;
		uint64_t w2w_init                    : 6;
		uint64_t r2r_l_init                  : 6;
		uint64_t r2w_l_init                  : 6;
		uint64_t w2r_l_init                  : 6;
		uint64_t w2w_l_init                  : 6;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_lmcx_slot_ctl0_s        cn85xx; */
	/* struct bdk_lmcx_slot_ctl0_s        cn88xx; */
	/* struct bdk_lmcx_slot_ctl0_s        cn88xxp1; */
} bdk_lmcx_slot_ctl0_t;

static inline uint64_t BDK_LMCX_SLOT_CTL0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SLOT_CTL0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001F8ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SLOT_CTL0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SLOT_CTL0(...) bdk_lmcx_slot_ctl0_t
#define bustype_BDK_LMCX_SLOT_CTL0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SLOT_CTL0(p1) (p1)
#define arguments_BDK_LMCX_SLOT_CTL0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SLOT_CTL0(...) "LMCX_SLOT_CTL0"


/**
 * RSL - lmc#_slot_ctl1
 *
 * This register is an assortment of control fields needed by the memory controller. If software
 * has not previously written to this register (since the last DRESET), hardware updates the
 * fields in this register to the minimum allowed value when any of LMC()_RLEVEL_RANK(),
 * LMC()_WLEVEL_RANK(), LMC()_CONTROL and LMC()_MODEREG_PARAMS0 CSRs change.
 * Ideally, only read this register after LMC has been initialized and
 * LMC()_RLEVEL_RANK(), LMC()_WLEVEL_RANK() have valid data.
 *
 * The interpretation of the fields in this CSR depends on LMC(0)_CONFIG[DDR2T]:
 *
 * * If LMC()_CONFIG[DDR2T]=1, (FieldValue + 4) is the minimum CK cycles between when the
 * DRAM part registers CAS commands of the first and second types from different cache blocks.
 *
 * * If LMC()_CONFIG[DDR2T]=0, (FieldValue + 3) is the minimum CK cycles between when the DRAM
 * part registers CAS commands of the first and second types from different cache blocks.
 * FieldValue = 0 is always illegal in this case.
 *
 * The hardware-calculated minimums for these fields are shown in LMC(0)_SLOT_CTL1 Hardware-
 * Calculated Minimums.
 */
typedef union bdk_lmcx_slot_ctl1 {
	uint64_t u;
	struct bdk_lmcx_slot_ctl1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t w2w_xrank_init              : 6;  /**< R/W/H - Write-to-write spacing control for back-to-back write followed by write cache block
                                                                 accesses across ranks of the same DIMM. */
		uint64_t w2r_xrank_init              : 6;  /**< R/W/H - Write-to-read spacing control for back-to-back write followed by read cache block accesses
                                                                 across ranks of the same DIMM. */
		uint64_t r2w_xrank_init              : 6;  /**< R/W/H - Read-to-write spacing control for back-to-back read followed by write cache block accesses
                                                                 across ranks of the same DIMM. */
		uint64_t r2r_xrank_init              : 6;  /**< R/W/H - Read-to-read spacing control for back-to-back read followed by read cache block accesses
                                                                 across ranks of the same DIMM. */
#else
		uint64_t r2r_xrank_init              : 6;
		uint64_t r2w_xrank_init              : 6;
		uint64_t w2r_xrank_init              : 6;
		uint64_t w2w_xrank_init              : 6;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_lmcx_slot_ctl1_s        cn85xx; */
	/* struct bdk_lmcx_slot_ctl1_s        cn88xx; */
	/* struct bdk_lmcx_slot_ctl1_s        cn88xxp1; */
} bdk_lmcx_slot_ctl1_t;

static inline uint64_t BDK_LMCX_SLOT_CTL1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SLOT_CTL1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000200ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SLOT_CTL1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SLOT_CTL1(...) bdk_lmcx_slot_ctl1_t
#define bustype_BDK_LMCX_SLOT_CTL1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SLOT_CTL1(p1) (p1)
#define arguments_BDK_LMCX_SLOT_CTL1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SLOT_CTL1(...) "LMCX_SLOT_CTL1"


/**
 * RSL - lmc#_slot_ctl2
 *
 * This register is an assortment of control fields needed by the memory controller. If software
 * has not previously written to this register (since the last DRESET), hardware updates the
 * fields in this register to the minimum allowed value when any of LMC()_RLEVEL_RANK(),
 * LMC()_WLEVEL_RANK(), LMC()_CONTROL and LMC()_MODEREG_PARAMS0 CSRs change.
 * Ideally, only read this register after LMC has been initialized and
 * LMC()_RLEVEL_RANK(), LMC()_WLEVEL_RANK() have valid data.
 *
 * The interpretation of the fields in this CSR depends on LMC(0)_CONFIG[DDR2T]:
 *
 * * If LMC()_CONFIG[DDR2T] = 1, (FieldValue + 4) is the minimum CK cycles between when the
 * DRAM part registers CAS commands of the first and second types from different cache blocks.
 *
 * * If LMC()_CONFIG[DDR2T] = 0, (FieldValue + 3) is the minimum CK cycles between when the
 * DRAM part registers CAS commands of the first and second types from different cache blocks.
 * FieldValue = 0 is always illegal in this case.
 *
 * The hardware-calculated minimums for these fields are shown in LMC Registers.
 */
typedef union bdk_lmcx_slot_ctl2 {
	uint64_t u;
	struct bdk_lmcx_slot_ctl2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t w2w_xdimm_init              : 6;  /**< R/W/H - Write-to-write spacing control for back-to-back write followed by write cache block
                                                                 accesses across DIMMs. */
		uint64_t w2r_xdimm_init              : 6;  /**< R/W/H - Write-to-read spacing control for back-to-back write followed by read cache block accesses
                                                                 across DIMMs. */
		uint64_t r2w_xdimm_init              : 6;  /**< R/W/H - Read-to-write spacing control for back-to-back read followed by write cache block accesses
                                                                 across DIMMs. */
		uint64_t r2r_xdimm_init              : 6;  /**< R/W/H - Read-to-read spacing control for back-to-back read followed by read cache block accesses
                                                                 across DIMMs. */
#else
		uint64_t r2r_xdimm_init              : 6;
		uint64_t r2w_xdimm_init              : 6;
		uint64_t w2r_xdimm_init              : 6;
		uint64_t w2w_xdimm_init              : 6;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_lmcx_slot_ctl2_s        cn85xx; */
	/* struct bdk_lmcx_slot_ctl2_s        cn88xx; */
	/* struct bdk_lmcx_slot_ctl2_s        cn88xxp1; */
} bdk_lmcx_slot_ctl2_t;

static inline uint64_t BDK_LMCX_SLOT_CTL2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SLOT_CTL2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000208ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SLOT_CTL2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SLOT_CTL2(...) bdk_lmcx_slot_ctl2_t
#define bustype_BDK_LMCX_SLOT_CTL2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SLOT_CTL2(p1) (p1)
#define arguments_BDK_LMCX_SLOT_CTL2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SLOT_CTL2(...) "LMCX_SLOT_CTL2"


/**
 * RSL - lmc#_slot_ctl3
 *
 * This register is an assortment of control fields needed by the memory controller. If software
 * has not previously written to this register (since the last DRESET), hardware updates the
 * fields in this register to the minimum allowed value when any of LMC()_RLEVEL_RANK(),
 * LMC()_WLEVEL_RANK(), LMC()_CONTROL and LMC()_MODEREG_PARAMS0 CSRs change.
 * Ideally, only read this register after LMC has been initialized and
 * LMC()_RLEVEL_RANK(), LMC()_WLEVEL_RANK() have valid data.
 *
 * The interpretation of the fields in this CSR depends on LMC(0)_CONFIG[DDR2T]:
 *
 * * If LMC()_CONFIG[DDR2T] = 1, (FieldValue + 4) is the minimum CK cycles between when the
 * DRAM part registers CAS commands of the first and second types from different cache blocks.
 *
 * * If LMC()_CONFIG[DDR2T] = 0, (FieldValue + 3) is the minimum CK cycles between when the
 * DRAM part registers CAS commands of the first and second types from different cache blocks.
 * FieldValue = 0 is always illegal in this case.
 *
 * The hardware-calculated minimums for these fields are shown in LMC Registers.
 */
typedef union bdk_lmcx_slot_ctl3 {
	uint64_t u;
	struct bdk_lmcx_slot_ctl3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t w2w_l_xrank_init            : 6;  /**< R/W/H - Write-to-write spacing control for back-to-back write followed by write cache block
                                                                 accesses to a different logical rank, and same BG for DDR4. */
		uint64_t w2r_l_xrank_init            : 6;  /**< R/W/H - Write-to-read spacing control for back-to-back write followed by read cache block accesses
                                                                 to a different logical rank, and same BG for DDR4. */
		uint64_t r2w_l_xrank_init            : 6;  /**< R/W/H - Read-to-write spacing control for back-to-back read followed by write cache block accesses
                                                                 to a different logical rank, and same BG for DDR4. */
		uint64_t r2r_l_xrank_init            : 6;  /**< R/W/H - Read-to-read spacing control for back-to-back read followed by read cache block accesses
                                                                 to a different logical rank, and same BG for DDR4. */
		uint64_t w2w_xrank_init              : 6;  /**< R/W/H - Write-to-write spacing control for back-to-back write followed by write cache block
                                                                 accesses to a different logical rank. */
		uint64_t w2r_xrank_init              : 6;  /**< R/W/H - Write-to-read spacing control for back-to-back write followed by read cache block accesses
                                                                 to a different logical rank. */
		uint64_t r2w_xrank_init              : 6;  /**< R/W/H - Read-to-write spacing control for back-to-back read followed by write cache block accesses
                                                                 to a different logical rank. */
		uint64_t r2r_xrank_init              : 6;  /**< R/W/H - Read-to-read spacing control for back-to-back read followed by read cache block accesses
                                                                 to a different logical rank. */
#else
		uint64_t r2r_xrank_init              : 6;
		uint64_t r2w_xrank_init              : 6;
		uint64_t w2r_xrank_init              : 6;
		uint64_t w2w_xrank_init              : 6;
		uint64_t r2r_l_xrank_init            : 6;
		uint64_t r2w_l_xrank_init            : 6;
		uint64_t w2r_l_xrank_init            : 6;
		uint64_t w2w_l_xrank_init            : 6;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_lmcx_slot_ctl3_s        cn85xx; */
	/* struct bdk_lmcx_slot_ctl3_s        cn88xx; */
	/* struct bdk_lmcx_slot_ctl3_s        cn88xxp1; */
} bdk_lmcx_slot_ctl3_t;

static inline uint64_t BDK_LMCX_SLOT_CTL3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_SLOT_CTL3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000248ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_SLOT_CTL3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_SLOT_CTL3(...) bdk_lmcx_slot_ctl3_t
#define bustype_BDK_LMCX_SLOT_CTL3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_SLOT_CTL3(p1) (p1)
#define arguments_BDK_LMCX_SLOT_CTL3(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_SLOT_CTL3(...) "LMCX_SLOT_CTL3"


/**
 * RSL - lmc#_timing_params0
 */
typedef union bdk_lmcx_timing_params0 {
	uint64_t u;
	struct bdk_lmcx_timing_params0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t tbcw                        : 5;  /**< R/W - Indicates tBCW constraints. Set this field as follows:
                                                                 _ RNDUP[TBCW(ns) / TCYC(ns)] - 1

                                                                 where TBCW is from the JEDEC DDR4DB spec, and TCYC(ns) is the DDR clock frequency (not
                                                                 data rate).

                                                                 TYP = 16. */
		uint64_t tcksre                      : 4;  /**< R/W - Indicates TCKSRE constraints. Set this field as follows:
                                                                 _ RNDUP[TCKSRE(ns) / TCYC(ns)] - 1

                                                                 where TCKSRE is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(5nCK, 10 ns). */
		uint64_t trp                         : 5;  /**< R/W - Indicates TRP constraints. Set TRP as follows:

                                                                 _ RNDUP[TRP(ns) / TCYC(ns)] - 1

                                                                 where TRP and TRTP are from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency
                                                                 (not data rate).

                                                                 TYP TRP = 10-15ns.

                                                                 TYP TRTP = max(4nCK, 7.5 ns). */
		uint64_t tzqinit                     : 4;  /**< R/W - Indicates TZQINIT constraints. Set this field as follows:

                                                                 _ RNDUP[TZQINIT(ns) / (256 * TCYC(ns))]

                                                                 where TZQINIT is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 2 (equivalent to 512). */
		uint64_t tdllk                       : 4;  /**< R/W - Indicates TDLLK constraints. Set this field as follows:

                                                                 _ RNDUP[TDLLK(ns) / (256 * TCYC(ns))]

                                                                 where TDLLK is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 2 (equivalent to 512).

                                                                 This parameter is used in self-refresh exit and assumed to be greater than TRFC. */
		uint64_t tmod                        : 5;  /**< R/W - Indicates tMOD constraints. Set this field as follows:

                                                                 _ RNDUP[TMOD(ns) / TCYC(ns)] - 1

                                                                 where TMOD is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(12nCK, 15 ns). */
		uint64_t tmrd                        : 4;  /**< R/W - Indicates TMRD constraints. Set this field as follows:

                                                                 _ RNDUP[TMRD(ns) / TCYC(ns)] - 1

                                                                 where TMRD is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 4nCK. */
		uint64_t txpr                        : 6;  /**< R/W - Indicates TXPR constraints. Set this field as follows:

                                                                 _ RNDUP[TXPR(ns) / (16 * TCYC(ns))]

                                                                 where TXPR is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(5nCK, TRFC+10 ns). */
		uint64_t tcke                        : 4;  /**< R/W - Indicates TCKE constraints. Set this field as follows:

                                                                 _ RNDUP[TCKE(ns) / TCYC(ns)] - 1

                                                                 where TCKE is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(3nCK, 7.5/5.625/5.625/5 ns).

                                                                 Because a DDR4 register can shorten the pulse width of CKE (it delays the falling edge
                                                                 but does not delay the rising edge), care must be taken to set this parameter larger
                                                                 to account for this effective reduction in the pulse width. */
		uint64_t tzqcs                       : 4;  /**< R/W - Indicates TZQCS constraints. This field is set as follows:

                                                                 _ RNDUP[(2 * TZQCS(ns)) / (16 * TCYC(ns))]

                                                                 where TZQCS is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP \>= 8 (greater-than-or-equal-to 128), to allow for dclk90 calibration. */
		uint64_t reserved_0_7                : 8;
#else
		uint64_t reserved_0_7                : 8;
		uint64_t tzqcs                       : 4;
		uint64_t tcke                        : 4;
		uint64_t txpr                        : 6;
		uint64_t tmrd                        : 4;
		uint64_t tmod                        : 5;
		uint64_t tdllk                       : 4;
		uint64_t tzqinit                     : 4;
		uint64_t trp                         : 5;
		uint64_t tcksre                      : 4;
		uint64_t tbcw                        : 5;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_lmcx_timing_params0_s   cn85xx; */
	/* struct bdk_lmcx_timing_params0_s   cn88xx; */
	/* struct bdk_lmcx_timing_params0_s   cn88xxp1; */
} bdk_lmcx_timing_params0_t;

static inline uint64_t BDK_LMCX_TIMING_PARAMS0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_TIMING_PARAMS0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000198ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_TIMING_PARAMS0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_TIMING_PARAMS0(...) bdk_lmcx_timing_params0_t
#define bustype_BDK_LMCX_TIMING_PARAMS0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_TIMING_PARAMS0(p1) (p1)
#define arguments_BDK_LMCX_TIMING_PARAMS0(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_TIMING_PARAMS0(...) "LMCX_TIMING_PARAMS0"


/**
 * RSL - lmc#_timing_params1
 */
typedef union bdk_lmcx_timing_params1 {
	uint64_t u;
	struct bdk_lmcx_timing_params1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_57_63              : 7;
		uint64_t tpdm_full_cycle_ena         : 1;  /**< R/W - When set, this field enables the addition of one-cycle delay to the
                                                                 Write/Read latency calculation. This is to compensate the case when
                                                                 tPDM delay in the RCD of an RDIMM/LRDIMM is greater than one-cycle.
                                                                 Only valid in RDIMM  (LMC()_CTL[RDIMM_ENA]=1) or LRDIMM
                                                                 (LMC()_CONFIG[LRDIMM_ENA=1) mode. */
		uint64_t trfc_dlr                    : 7;  /**< R/W - Indicates TRFC_DLR constraints. Set this field as follows:

                                                                 _ RNDUP[TRFC_DLR(ns) / (8 * TCYC(ns))]

                                                                 where TRFC_DLR is from the JEDEC 3D Stacked SDRAM spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 90-120 ns.

                                                                 0x0 = reserved.
                                                                 0x1 = 8 TCYC.
                                                                 0x2 = 16 TCYC.
                                                                 0x3 = 24 TCYC.
                                                                 0x4 = 32 TCYC.
                                                                 ...
                                                                 0x7E = 1008 TCYC.
                                                                 0x7F = 1016 TCYC. */
		uint64_t txpdll                      : 5;  /**< R/W - Indicates TXPDLL constraints. Set this field as follows:

                                                                 _ RNDUP[TXPDLL(ns) / TCYC(ns)] - 1

                                                                 where TXPDLL is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP=max(10nCK, 24 ns) */
		uint64_t tfaw                        : 5;  /**< R/W - Indicates TFAW constraints. Set this field as follows:

                                                                 _ RNDUP[TFAW(ns) / (4 * TCYC(ns))]

                                                                 where TFAW is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 30-40 ns

                                                                 When interfacing with DIMMs that contain 3DS DRAMs, set this field as follows:

                                                                 _ RNDUP[TFAW_SLR(ns) / (4 * TCYC(ns))]

                                                                 where TFAW_SLR is the Four activate window to the same logical rank from the
                                                                 JEDEC DDR4 3D Stacked spec. */
		uint64_t twldqsen                    : 4;  /**< R/W - Indicates TWLDQSEN constraints. Set this field as follows:

                                                                 _ RNDUP[TWLDQSEN(ns) / (4 * TCYC(ns))]

                                                                 where TWLDQSEN is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(25nCK) */
		uint64_t twlmrd                      : 4;  /**< R/W - Indicates TWLMRD constraints. Set this field as follows:

                                                                 _ RNDUP[TWLMRD(ns) / (4 * TCYC(ns))]

                                                                 where TWLMRD is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(40nCK) */
		uint64_t txp                         : 3;  /**< R/W - Indicates TXP constraints. Set this field as follows:

                                                                 _ RNDUP[TXP(ns) / TCYC(ns)] - 1

                                                                 where TXP is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP=max(3nCK, 7.5 ns) */
		uint64_t trrd                        : 3;  /**< R/W - Indicates TRRD constraints. Set this field as follows:

                                                                 _ RNDUP[TRRD(ns) / TCYC(ns)] - 1,

                                                                 where TRRD is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(4nCK, 10 ns)

                                                                 0x0 = Reserved.
                                                                 0x1 = 2 TCYC.
                                                                 ...
                                                                 0x6 = 7 TCYC.
                                                                 0x7 = 8 TCYC.

                                                                 For DDR4, this is the TRRD_S parameter. */
		uint64_t trfc                        : 7;  /**< R/W - Indicates TRFC constraints. Set this field as follows:

                                                                 _ RNDUP[TRFC(ns) / (8 * TCYC(ns))]

                                                                 where TRFC is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 90-350 ns

                                                                 0x0 = reserved.
                                                                 0x1 = 8 TCYC.
                                                                 0x2 = 16 TCYC.
                                                                 0x3 = 24 TCYC.
                                                                 0x4 = 32 TCYC.
                                                                 ...
                                                                 0x7E = 1008 TCYC.
                                                                 0x7F = 1016 TCYC. */
		uint64_t twtr                        : 4;  /**< R/W - Indicates TWTR constraints. Set this field as follows:

                                                                 _ RNDUP[TWTR(ns) / TCYC(ns)] - 1

                                                                 where TWTR is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = max(4nCK, 7.5 ns)

                                                                 For DDR4, this CSR field represents TWTR_S.

                                                                 0x0 = reserved.
                                                                 0x1 = 2.
                                                                 ...
                                                                 0x7 = 8.
                                                                 0x8-0xF = reserved. */
		uint64_t trcd                        : 4;  /**< R/W - Indicates TRCD constraints. Set this field as follows:

                                                                 _ RNDUP[TRCD(ns) / TCYC(ns)]

                                                                 where TRCD is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 10-15 ns

                                                                 0x0 = reserved.
                                                                 0x1 = 2 (2 is the smallest value allowed).
                                                                 0x2 = 2.
                                                                 ...
                                                                 0xE = 14.
                                                                 0xA-0xF = reserved.

                                                                 In 2T mode, make this register TRCD - 1, not going below 2. */
		uint64_t tras                        : 6;  /**< R/W - Indicates TRAS constraints. Set TRAS (CSR field) as follows:

                                                                 _ RNDUP[TRAS(ns)/TCYC(ns)] - 1,

                                                                 where TRAS is from the DDR3/DDR4 spec, and TCYC(ns) is the DDR clock frequency (not data
                                                                 rate).

                                                                 TYP = 35ns - 9 * TREFI

                                                                 0x0 = reserved.
                                                                 0x1 = 2 TCYC.
                                                                 0010:  3 TCYC.
                                                                 ...
                                                                 0x3F: 64 TCYC. */
		uint64_t tmprr                       : 4;  /**< R/W - Indicates TMPRR constraints. Set this field as follows:

                                                                 _ RNDUP[TMPRR(ns) / TCYC(ns)] - 1

                                                                 where TMPRR is from the JEDEC DDR3/DDR4 spec, and TCYC(ns) is the DDR clock
                                                                 frequency (not data rate).

                                                                 TYP = 1 nCK */
#else
		uint64_t tmprr                       : 4;
		uint64_t tras                        : 6;
		uint64_t trcd                        : 4;
		uint64_t twtr                        : 4;
		uint64_t trfc                        : 7;
		uint64_t trrd                        : 3;
		uint64_t txp                         : 3;
		uint64_t twlmrd                      : 4;
		uint64_t twldqsen                    : 4;
		uint64_t tfaw                        : 5;
		uint64_t txpdll                      : 5;
		uint64_t trfc_dlr                    : 7;
		uint64_t tpdm_full_cycle_ena         : 1;
		uint64_t reserved_57_63              : 7;
#endif
	} s;
	/* struct bdk_lmcx_timing_params1_s   cn85xx; */
	/* struct bdk_lmcx_timing_params1_s   cn88xx; */
	/* struct bdk_lmcx_timing_params1_s   cn88xxp1; */
} bdk_lmcx_timing_params1_t;

static inline uint64_t BDK_LMCX_TIMING_PARAMS1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_TIMING_PARAMS1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001A0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_TIMING_PARAMS1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_TIMING_PARAMS1(...) bdk_lmcx_timing_params1_t
#define bustype_BDK_LMCX_TIMING_PARAMS1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_TIMING_PARAMS1(p1) (p1)
#define arguments_BDK_LMCX_TIMING_PARAMS1(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_TIMING_PARAMS1(...) "LMCX_TIMING_PARAMS1"


/**
 * RSL - lmc#_timing_params2
 *
 * This register sets timing parameters for DDR4.
 *
 */
typedef union bdk_lmcx_timing_params2 {
	uint64_t u;
	struct bdk_lmcx_timing_params2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t trrd_l_ext                  : 1;  /**< R/W - MSB of TWTR_L constraints. Set this field
                                                                 when requiring tRRD_L of more than 8 nCK. Otherwise
                                                                 this bit must be 0. */
		uint64_t trtp                        : 4;  /**< R/W - Specifies the TRTP parameter, in cycles. Set this field as follows:
                                                                 _ RNDUP[TRTP(ns) / TCYC(ns)] - 1,

                                                                 For DDR3, typical = max(4 nCK, 7.5ns).

                                                                 For DDR4 the TRTP parameter is dictated by the TWR MR bits. */
		uint64_t t_rw_op_max                 : 4;  /**< R/W - Specifies the maximum delay for a read or write operation to complete, used to set the
                                                                 timing of MRW and MPR operations. Set this field as follows:

                                                                 _ RNDUP[Maximum operation delay (cycles) / 8]

                                                                 Typical = 0x7. */
		uint64_t twtr_l                      : 4;  /**< R/W - Specifies TWTR_L constraints. Set this field as follows:

                                                                 _ RNDUP[TWTR_L(ns) / TCYC(ns)] - 1

                                                                 where TWTR_L is from the JEDEC DDR4 spec, and TCYC(ns) is the DDR clock frequency (not the
                                                                 data rate).

                                                                 Typical = MAX(4 nCK, 7.5 ns)

                                                                 INTERNAL: Seems the '- 1' is because we add 1 back into slot timing equation */
		uint64_t trrd_l                      : 3;  /**< R/W - Specifies TRRD_L constraints. Set this field as follows:

                                                                 _ RNDUP[TRRD_L(ns) / TCYC(ns)] - 1,

                                                                 where TRRD_L is from the JEDEC DDR4 spec, and TCYC(ns) is the DDR clock frequency (not the
                                                                 data rate).

                                                                 Typical = MAX(4 nCK, 7.5 ns).
                                                                 0x0 = reserved.
                                                                 0x1 = two TCYC.
                                                                 0x2 = three TCYC.
                                                                 0x3 = four TCYC.
                                                                 0x4 = five TCYC.
                                                                 0x5 = six TCYC.
                                                                 0x6 = seven TCYC.
                                                                 0x7 = eight TCYC. */
#else
		uint64_t trrd_l                      : 3;
		uint64_t twtr_l                      : 4;
		uint64_t t_rw_op_max                 : 4;
		uint64_t trtp                        : 4;
		uint64_t trrd_l_ext                  : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_lmcx_timing_params2_s   cn85xx; */
	/* struct bdk_lmcx_timing_params2_s   cn88xx; */
	/* struct bdk_lmcx_timing_params2_s   cn88xxp1; */
} bdk_lmcx_timing_params2_t;

static inline uint64_t BDK_LMCX_TIMING_PARAMS2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_TIMING_PARAMS2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000060ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_TIMING_PARAMS2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_TIMING_PARAMS2(...) bdk_lmcx_timing_params2_t
#define bustype_BDK_LMCX_TIMING_PARAMS2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_TIMING_PARAMS2(p1) (p1)
#define arguments_BDK_LMCX_TIMING_PARAMS2(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_TIMING_PARAMS2(...) "LMCX_TIMING_PARAMS2"


/**
 * RSL - lmc#_wlevel_ctl
 */
typedef union bdk_lmcx_wlevel_ctl {
	uint64_t u;
	struct bdk_lmcx_wlevel_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t rtt_nom                     : 3;  /**< R/W - LMC writes a decoded value to MR1[Rtt_Nom] of the rank during write leveling. Per JEDEC
                                                                 DDR3 specifications, only values MR1[Rtt_Nom] = 1 (RZQ/4), 2 (RZQ/2), or 3 (RZQ/6) are
                                                                 allowed during write leveling with output buffer enabled.
                                                                 DDR3 Spec:
                                                                 0x0 = LMC writes 0x1 (RZQ/4) to MR1[Rtt_Nom].
                                                                 0x1 = LMC writes 0x2 (RZQ/2) to MR1[Rtt_Nom].
                                                                 0x2 = LMC writes 0x3 (RZQ/6) to MR1[Rtt_Nom].
                                                                 0x3 = LMC writes 0x4 (RZQ/12) to MR1[Rtt_Nom].
                                                                 0x4 = LMC writes 0x5 (RZQ/8) to MR1[Rtt_Nom].
                                                                 0x5 = LMC writes 0x6 (Rsvd) to MR1[Rtt_Nom].
                                                                 0x6 = LMC writes 0x7 (Rsvd) to MR1[Rtt_Nom].
                                                                 0x7 = LMC writes 0x0 (Disabled) to MR1[Rtt_Nom].

                                                                 In DDR4 LRDIMM application, this is used to program the Data Buffer Control Word BC00
                                                                 during the Host Interface Write Leveling Mode:
                                                                 0x0 = LMC writes 0x1 (RZQ/4).
                                                                 0x1 = LMC writes 0x2 (RZQ/2).
                                                                 0x2 = LMC writes 0x3 (RZQ/6).
                                                                 0x3 = LMC writes 0x4 (RZQ/1).
                                                                 0x4 = LMC writes 0x5 (RZQ/5).
                                                                 0x5 = LMC writes 0x6 (RZQ/3).
                                                                 0x6 = LMC writes 0x7 (RZQ/7).
                                                                 0x7 = LMC writes 0x0 (Disabled). */
		uint64_t bitmask                     : 8;  /**< R/W - Mask to select bit lanes on which write-leveling feedback is returned when OR_DIS is set to 1. */
		uint64_t or_dis                      : 1;  /**< R/W - Disable ORing of bits in a byte lane when computing the write-leveling bitmask. */
		uint64_t sset                        : 1;  /**< R/W - Run write-leveling on the current setting only. */
		uint64_t lanemask                    : 9;  /**< R/W - One-shot mask to select byte lane to be leveled by the write-leveling sequence. Used with
                                                                 *16 parts where the upper and lower byte lanes need to be leveled independently. */
#else
		uint64_t lanemask                    : 9;
		uint64_t sset                        : 1;
		uint64_t or_dis                      : 1;
		uint64_t bitmask                     : 8;
		uint64_t rtt_nom                     : 3;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_lmcx_wlevel_ctl_s       cn85xx; */
	/* struct bdk_lmcx_wlevel_ctl_s       cn88xx; */
	/* struct bdk_lmcx_wlevel_ctl_s       cn88xxp1; */
} bdk_lmcx_wlevel_ctl_t;

static inline uint64_t BDK_LMCX_WLEVEL_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_WLEVEL_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000300ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_WLEVEL_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_WLEVEL_CTL(...) bdk_lmcx_wlevel_ctl_t
#define bustype_BDK_LMCX_WLEVEL_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_WLEVEL_CTL(p1) (p1)
#define arguments_BDK_LMCX_WLEVEL_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_WLEVEL_CTL(...) "LMCX_WLEVEL_CTL"


/**
 * RSL - lmc#_wlevel_dbg
 *
 * A given write of LMC()_WLEVEL_DBG returns the write-leveling pass/fail results for all
 * possible delay settings (i.e. the BITMASK) for only one byte in the last rank that the
 * hardware write-leveled. LMC()_WLEVEL_DBG[BYTE] selects the particular byte. To get these
 * pass/fail results for a different rank, you must run the hardware write-leveling again. For
 * example, it is possible to get the BITMASK results for every byte of every rank if you run
 * write-leveling separately for each rank, probing LMC()_WLEVEL_DBG between each write-
 * leveling.
 */
typedef union bdk_lmcx_wlevel_dbg {
	uint64_t u;
	struct bdk_lmcx_wlevel_dbg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t bitmask                     : 8;  /**< RO/H - Bitmask generated during write level settings sweep. If LMC()_WLEVEL_CTL[SSET]=0,
                                                                 BITMASK\<n\>=0 means write level setting n failed; BITMASK\<n\>=1 means write level setting n
                                                                 passed for
                                                                 0 \<= n \<= 7. BITMASK contains the first 8 results of the total 16 collected by LMC during
                                                                 the write-leveling sequence.

                                                                 If LMC()_WLEVEL_CTL[SSET]=1, BITMASK\<0\>=0 means curr write level setting failed;
                                                                 BITMASK\<0\>=1 means curr write level setting passed. */
		uint64_t byte                        : 4;  /**< R/W - 0 \<= BYTE \<= 8. */
#else
		uint64_t byte                        : 4;
		uint64_t bitmask                     : 8;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_lmcx_wlevel_dbg_s       cn85xx; */
	/* struct bdk_lmcx_wlevel_dbg_s       cn88xx; */
	/* struct bdk_lmcx_wlevel_dbg_s       cn88xxp1; */
} bdk_lmcx_wlevel_dbg_t;

static inline uint64_t BDK_LMCX_WLEVEL_DBG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_WLEVEL_DBG(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E088000308ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_WLEVEL_DBG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_WLEVEL_DBG(...) bdk_lmcx_wlevel_dbg_t
#define bustype_BDK_LMCX_WLEVEL_DBG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_WLEVEL_DBG(p1) (p1)
#define arguments_BDK_LMCX_WLEVEL_DBG(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_WLEVEL_DBG(...) "LMCX_WLEVEL_DBG"


/**
 * RSL - lmc#_wlevel_rank#
 *
 * Four of these CSRs exist per LMC, one for each rank. Write level setting is measured in units
 * of 1/8 CK, so the below BYTEn values can range over 4 CK cycles. Assuming
 * LMC()_WLEVEL_CTL[SSET]=0, the BYTEn\<2:0\> values are not used during write-leveling, and
 * they are overwritten by the hardware as part of the write-leveling sequence. (Hardware sets
 * STATUS to 3 after hardware write-leveling completes for the rank). Software needs to set
 * BYTEn\<4:3\> bits.
 *
 * Each CSR may also be written by software, but not while a write-leveling sequence is in
 * progress. (Hardware sets STATUS to 1 after a CSR write.) Software initiates a hardware write-
 * leveling sequence by programming LMC()_WLEVEL_CTL and writing RANKMASK and INIT_START=1 with
 * SEQ_SEL=6 in LMC*0_CONFIG.
 *
 * LMC will then step through and accumulate write leveling results for 8 unique delay settings
 * (twice), starting at a delay of LMC()_WLEVEL_RANK() [BYTEn\<4:3\>]* 8 CK increasing by
 * 1/8 CK each setting. Hardware will then set LMC()_WLEVEL_RANK()[BYTEn\<2:0\>] to
 * indicate the first write leveling result of '1' that followed a result of '0' during the
 * sequence by searching for a '1100' pattern in the generated bitmask, except that LMC will
 * always write LMC()_WLEVEL_RANK()[BYTEn\<0\>]=0. If hardware is unable to find a match
 * for a '1100' pattern, then hardware sets LMC()_WLEVEL_RANK() [BYTEn\<2:0\>] to 0x4. See
 * LMC()_WLEVEL_CTL.
 *
 * LMC()_WLEVEL_RANKi values for ranks i without attached DRAM should be set such that they do
 * not
 * increase the range of possible BYTE values for any byte lane. The easiest way to do this is to
 * set LMC()_WLEVEL_RANKi = LMC()_WLEVEL_RANKj, where j is some rank with attached DRAM whose
 * LMC()_WLEVEL_RANKj is already fully initialized.
 */
typedef union bdk_lmcx_wlevel_rankx {
	uint64_t u;
	struct bdk_lmcx_wlevel_rankx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_47_63              : 17;
		uint64_t status                      : 2;  /**< RO/H - Indicates status of the write-leveling and where the BYTE* programmings in \<44:0\> came
                                                                 from:
                                                                 0x0 = BYTE* values are their reset value.
                                                                 0x1 = BYTE* values were set via a CSR write to this register.
                                                                 0x2 = write-leveling sequence currently in progress (BYTE* values are unpredictable).
                                                                 0x3 = BYTE* values came from a complete write-leveling sequence, irrespective of which
                                                                 lanes are masked via LMC()_WLEVEL_CTL[LANEMASK]. */
		uint64_t byte8                       : 5;  /**< R/W/H - "Write level setting. Bit 0 of BYTE8 must be zero during normal operation. When ECC DRAM
                                                                 is not present in 64-bit mode (i.e. when DRAM is not attached to chip signals DDR\#_CBS_0_*
                                                                 and DDR\#_CB\<7:0\>), software should write BYTE8 with a value that does not increase the
                                                                 range of possible BYTE* values. The easiest way to do this is to set
                                                                 LMC()_WLEVEL_RANK()[BYTE8] = LMC()_WLEVEL_RANK()[BYTE0] when there is no
                                                                 ECC DRAM, using the final BYTE0 value." */
		uint64_t byte7                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE7 must be zero during normal operation. */
		uint64_t byte6                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE6 must be zero during normal operation. */
		uint64_t byte5                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE5 must be zero during normal operation. */
		uint64_t byte4                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE4 must be zero during normal operation. */
		uint64_t byte3                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE3 must be zero during normal operation. */
		uint64_t byte2                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE2 must be zero during normal operation. */
		uint64_t byte1                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE1 must be zero during normal operation. */
		uint64_t byte0                       : 5;  /**< R/W/H - Write level setting. Bit 0 of BYTE0 must be zero during normal operation. */
#else
		uint64_t byte0                       : 5;
		uint64_t byte1                       : 5;
		uint64_t byte2                       : 5;
		uint64_t byte3                       : 5;
		uint64_t byte4                       : 5;
		uint64_t byte5                       : 5;
		uint64_t byte6                       : 5;
		uint64_t byte7                       : 5;
		uint64_t byte8                       : 5;
		uint64_t status                      : 2;
		uint64_t reserved_47_63              : 17;
#endif
	} s;
	/* struct bdk_lmcx_wlevel_rankx_s     cn85xx; */
	/* struct bdk_lmcx_wlevel_rankx_s     cn88xx; */
	/* struct bdk_lmcx_wlevel_rankx_s     cn88xxp1; */
} bdk_lmcx_wlevel_rankx_t;

static inline uint64_t BDK_LMCX_WLEVEL_RANKX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_WLEVEL_RANKX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 3)))
		return 0x000087E0880002C0ull + (param1 & 3) * 0x1000000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_LMCX_WLEVEL_RANKX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_WLEVEL_RANKX(...) bdk_lmcx_wlevel_rankx_t
#define bustype_BDK_LMCX_WLEVEL_RANKX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_WLEVEL_RANKX(p1,p2) (p1)
#define arguments_BDK_LMCX_WLEVEL_RANKX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_LMCX_WLEVEL_RANKX(...) "LMCX_WLEVEL_RANKX"


/**
 * RSL - lmc#_wodt_mask
 *
 * System designers may desire to terminate DQ/DQS lines for higher-frequency DDR operations,
 * especially on a multirank system. DDR3 DQ/DQS I/Os have built-in termination resistors that
 * can be turned on or off by the controller, after meeting TAOND and TAOF timing requirements.
 * Each rank has its own ODT pin that fans out to all of the memory parts in that DIMM. System
 * designers may prefer different combinations of ODT ONs for write operations into different
 * ranks. CNXXXX supports full programmability by way of the mask register below. Each rank
 * position has its own 8-bit programmable field. When the controller does a write to that rank,
 * it sets the 4 ODT pins to the mask pins below. For example, when doing a write into Rank0, a
 * system designer may desire to terminate the lines with the resistor on DIMM0/Rank1. The mask
 * WODT_D0_R0 would then be {00000010}.
 *
 * CNXXXX drives the appropriate mask values on the ODT pins by default. If this feature is not
 * required, write 0x0 in this register. When a given RANK is selected, the WODT mask for that
 * RANK is used. The resulting WODT mask is driven to the DIMMs in the following manner:
 */
typedef union bdk_lmcx_wodt_mask {
	uint64_t u;
	struct bdk_lmcx_wodt_mask_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t wodt_d1_r1                  : 4;  /**< R/W - Write ODT mask DIMM1, RANK1/DIMM1 in SingleRanked.
                                                                 If RANK_ENA=0, WODT_D1_R1\<3:0\> must be zero. */
		uint64_t reserved_20_23              : 4;
		uint64_t wodt_d1_r0                  : 4;  /**< R/W - Write ODT mask DIMM1, RANK0. If RANK_ENA=0, WODT_D1_R0\<3,1\> must be zero. */
		uint64_t reserved_12_15              : 4;
		uint64_t wodt_d0_r1                  : 4;  /**< R/W - Write ODT mask DIMM0, RANK1/DIMM0 in SingleRanked. If RANK_ENA=0, WODT_D0_R1\<3:0\> must be
                                                                 zero. */
		uint64_t reserved_4_7                : 4;
		uint64_t wodt_d0_r0                  : 4;  /**< R/W - Write ODT mask DIMM0, RANK0. If RANK_ENA=0, WODT_D0_R0\<3,1\> must be zero. */
#else
		uint64_t wodt_d0_r0                  : 4;
		uint64_t reserved_4_7                : 4;
		uint64_t wodt_d0_r1                  : 4;
		uint64_t reserved_12_15              : 4;
		uint64_t wodt_d1_r0                  : 4;
		uint64_t reserved_20_23              : 4;
		uint64_t wodt_d1_r1                  : 4;
		uint64_t reserved_28_63              : 36;
#endif
	} s;
	/* struct bdk_lmcx_wodt_mask_s        cn85xx; */
	/* struct bdk_lmcx_wodt_mask_s        cn88xx; */
	/* struct bdk_lmcx_wodt_mask_s        cn88xxp1; */
} bdk_lmcx_wodt_mask_t;

static inline uint64_t BDK_LMCX_WODT_MASK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_LMCX_WODT_MASK(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E0880001B0ull + (param1 & 3) * 0x1000000ull;
	csr_fatal("BDK_LMCX_WODT_MASK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_LMCX_WODT_MASK(...) bdk_lmcx_wodt_mask_t
#define bustype_BDK_LMCX_WODT_MASK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_LMCX_WODT_MASK(p1) (p1)
#define arguments_BDK_LMCX_WODT_MASK(p1) (p1),-1,-1,-1
#define basename_BDK_LMCX_WODT_MASK(...) "LMCX_WODT_MASK"

#endif /* __BDK_CSRS_LMC__ */
