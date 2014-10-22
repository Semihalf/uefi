#ifndef __BDK_CSRS_GSER__
#define __BDK_CSRS_GSER__
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
 * Cavium GSER.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration GSER_LMODE_E
 *
 * GSER Lane Mode Enumeration
 * Enumerates the SerDes lane modes. See GSER()_LANE_MODE[LMODE].
 */
enum gser_lmode_e {
	GSER_LMODE_E_R_103125G_REFCLK15625_KR = 0x5,
	GSER_LMODE_E_R_125G_REFCLK15625_KX = 0x3,
	GSER_LMODE_E_R_125G_REFCLK15625_SGMII = 0x6,
	GSER_LMODE_E_R_25G_REFCLK100 = 0x0,
	GSER_LMODE_E_R_25G_REFCLK125 = 0x9,
	GSER_LMODE_E_R_3125G_REFCLK15625_XAUI = 0x4,
	GSER_LMODE_E_R_5G_REFCLK100 = 0x1,
	GSER_LMODE_E_R_5G_REFCLK125 = 0xa,
	GSER_LMODE_E_R_5G_REFCLK15625_QSGMII = 0x7,
	GSER_LMODE_E_R_625G_REFCLK15625_RXAUI = 0x8,
	GSER_LMODE_E_R_8G_REFCLK100 = 0x2,
	GSER_LMODE_E_R_8G_REFCLK125 = 0xb,
	GSER_LMODE_E_ENUM_LAST = 0xc,
};

/**
 * Enumeration GSER_QLM_E
 *
 * GSER QLM/CCPI Enumeration
 * Enumerates the GSER to QLM.
 */
enum gser_qlm_e {
	GSER_QLM_E_GSER0 = 0x0,
	GSER_QLM_E_GSER1 = 0x1,
	GSER_QLM_E_GSER10 = 0xa,
	GSER_QLM_E_GSER11 = 0xb,
	GSER_QLM_E_GSER12 = 0xc,
	GSER_QLM_E_GSER13 = 0xd,
	GSER_QLM_E_GSER2 = 0x2,
	GSER_QLM_E_GSER3 = 0x3,
	GSER_QLM_E_GSER4 = 0x4,
	GSER_QLM_E_GSER5 = 0x5,
	GSER_QLM_E_GSER6 = 0x6,
	GSER_QLM_E_GSER7 = 0x7,
	GSER_QLM_E_GSER8 = 0x8,
	GSER_QLM_E_GSER9 = 0x9,
	GSER_QLM_E_ENUM_LAST = 0xe,
};



/**
 * RSL - gser#_ana_atest
 */
typedef union bdk_gserx_ana_atest {
	uint64_t u;
	struct bdk_gserx_ana_atest_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t ana_dac_b                   : 7;  /**< R/W - Used to control the B-side DAC input to the analog test block. Note that the QLM4 register
                                                                 is tied to the analog test block, for non-CCPI links. Note that the CCPI4 register is tied
                                                                 to the analog test block, for CCPI links. The other GSER()_ANA_ATEST registers are
                                                                 unused. For diagnostic use only. */
		uint64_t ana_dac_a                   : 5;  /**< R/W - Used to control A-side DAC input to the analog test block. Note that the QLM4 register is
                                                                 tied to the analog test block, for non-CCPI links. Note that the CCPI4 register is tied to
                                                                 the analog test block, for CCPI links. The other GSER()_ANA_ATEST registers are unused.
                                                                 For diagnostic use only. */
#else
		uint64_t ana_dac_a                   : 5;
		uint64_t ana_dac_b                   : 7;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_gserx_ana_atest_s       cn88xx; */
	/* struct bdk_gserx_ana_atest_s       cn88xxp1; */
} bdk_gserx_ana_atest_t;

static inline uint64_t BDK_GSERX_ANA_ATEST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_ANA_ATEST(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000800ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_ANA_ATEST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_ANA_ATEST(...) bdk_gserx_ana_atest_t
#define bustype_BDK_GSERX_ANA_ATEST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_ANA_ATEST(p1) (p1)
#define arguments_BDK_GSERX_ANA_ATEST(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_ANA_ATEST(...) "GSERX_ANA_ATEST"


/**
 * RSL - gser#_ana_sel
 */
typedef union bdk_gserx_ana_sel {
	uint64_t u;
	struct bdk_gserx_ana_sel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t ana_sel                     : 9;  /**< R/W - Used to control the adr_global input to the analog test block. Note that the QLM0 register
                                                                 is tied to the analog test block, for non-CCPI links. Note that the QLM8 register is tied
                                                                 to the analog test block, for CCPI links. The other GSER()_ANA_SEL registers are unused.
                                                                 For diagnostic use only. */
#else
		uint64_t ana_sel                     : 9;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_gserx_ana_sel_s         cn88xx; */
	/* struct bdk_gserx_ana_sel_s         cn88xxp1; */
} bdk_gserx_ana_sel_t;

static inline uint64_t BDK_GSERX_ANA_SEL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_ANA_SEL(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000808ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_ANA_SEL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_ANA_SEL(...) bdk_gserx_ana_sel_t
#define bustype_BDK_GSERX_ANA_SEL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_ANA_SEL(p1) (p1)
#define arguments_BDK_GSERX_ANA_SEL(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_ANA_SEL(...) "GSERX_ANA_SEL"


/**
 * RSL - gser#_br_rx#_ctl
 */
typedef union bdk_gserx_br_rxx_ctl {
	uint64_t u;
	struct bdk_gserx_br_rxx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t rxt_swm                     : 1;  /**< R/W - Set when RX Base-R Link Training is to be performed under software control. For diagnostic
                                                                 use only. */
		uint64_t rxt_preset                  : 1;  /**< R/W - For all link training, this bit determines how to configure the preset bit in the
                                                                 coefficient update message that is sent to the far end transmitter. When set, a one time
                                                                 request is made that the coefficients be set to a state where equalization is turned off.

                                                                 To perform a preset, set this bit prior to link training. Link training needs to be
                                                                 disabled to complete the request and get the rxtrain state machine back to idle. Note that
                                                                 it is illegal to set both the preset and initialize bits at the same time. For diagnostic
                                                                 use only. */
		uint64_t rxt_initialize              : 1;  /**< R/W - For all link training, this bit determines how to configure the initialize bit in the
                                                                 coefficient update message that is sent to the far end transmitter of RX training. When
                                                                 set, a request is made that the coefficients be set to its INITIALIZE state. To perform an
                                                                 initialize prior to link training, set this bit prior to performing link training. Note
                                                                 that it is illegal to set both the preset and initialize bits at the same time. Since the
                                                                 far end transmitter is required to be initialized prior to starting link training, it is
                                                                 not expected that software will need to set this bit. For diagnostic use only. */
#else
		uint64_t rxt_initialize              : 1;
		uint64_t rxt_preset                  : 1;
		uint64_t rxt_swm                     : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_gserx_br_rxx_ctl_s      cn88xx; */
	/* struct bdk_gserx_br_rxx_ctl_s      cn88xxp1; */
} bdk_gserx_br_rxx_ctl_t;

static inline uint64_t BDK_GSERX_BR_RXX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_BR_RXX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090000400ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x80ull;
	csr_fatal("BDK_GSERX_BR_RXX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_BR_RXX_CTL(...) bdk_gserx_br_rxx_ctl_t
#define bustype_BDK_GSERX_BR_RXX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_BR_RXX_CTL(p1,p2) (p1)
#define arguments_BDK_GSERX_BR_RXX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_BR_RXX_CTL(...) "GSERX_BR_RXX_CTL"


/**
 * RSL - gser#_br_rx#_eer
 *
 * GSER software Base-R RX Link Training equalization evaluation request (EER). A write to
 * RXT_EER initiates a equalization request to the RAW PCS. A read of this register returns the
 * equalization status message and a valid bit indicating it was updated. These registers are for
 * diagnostic use only.
 */
typedef union bdk_gserx_br_rxx_eer {
	uint64_t u;
	struct bdk_gserx_br_rxx_eer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rxt_eer                     : 1;  /**< WO - When RX Base-R Link Training is being performed under software control,
                                                                 (GSER()_BR_RX()_CTL[RXT_SWM] is set), writing this bit initiates an equalization
                                                                 request to the RAW PCS. Reading this bit always returns a zero. */
		uint64_t rxt_esv                     : 1;  /**< R/W - When performing an equalization request (RXT_EER), this bit, when set, indicates that the
                                                                 Equalization Status (RXT_ESM) is valid. When issuing a RXT_EER request, it is expected
                                                                 that RXT_ESV will get written to zero so that a valid RXT_ESM can be determined. */
		uint64_t rxt_esm                     : 14; /**< RO - When performing an equalization request (RXT_EER), this is the equalization status message
                                                                 from the RAW PCS. It is valid when RXT_ESV is set.

                                                                 _ \<13:6\>: Figure of merit. An 8-bit output from the PHY indicating the quality of the
                                                                 received data eye. A higher value indicates better link equalization, with 8'd0 indicating
                                                                 worst equalization setting and 8'd255 indicating the best equalization setting.

                                                                 _ \<5:4\>: RX recommended TXPOST direction change.

                                                                 _ \<3:2\>: RX recommended TXMAIN direction change.

                                                                 _ \<1:0\>: RX recommended TXPRE direction change.

                                                                 Recommended direction change outputs from the PHY for the link partner transmitter
                                                                 coefficients.
                                                                 0x0 = Hold.
                                                                 0x1 = Increment.
                                                                 0x2 = Decrement.
                                                                 0x3 = Hold. */
#else
		uint64_t rxt_esm                     : 14;
		uint64_t rxt_esv                     : 1;
		uint64_t rxt_eer                     : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_br_rxx_eer_s      cn88xx; */
	/* struct bdk_gserx_br_rxx_eer_s      cn88xxp1; */
} bdk_gserx_br_rxx_eer_t;

static inline uint64_t BDK_GSERX_BR_RXX_EER(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_BR_RXX_EER(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090000418ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x80ull;
	csr_fatal("BDK_GSERX_BR_RXX_EER", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_BR_RXX_EER(...) bdk_gserx_br_rxx_eer_t
#define bustype_BDK_GSERX_BR_RXX_EER(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_BR_RXX_EER(p1,p2) (p1)
#define arguments_BDK_GSERX_BR_RXX_EER(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_BR_RXX_EER(...) "GSERX_BR_RXX_EER"


/**
 * RSL - gser#_br_tx#_ctl
 */
typedef union bdk_gserx_br_txx_ctl {
	uint64_t u;
	struct bdk_gserx_br_txx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t txt_swm                     : 1;  /**< R/W - Set when TX Base-R Link Training is to be performed under software control. For diagnostic
                                                                 use only. */
#else
		uint64_t txt_swm                     : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_br_txx_ctl_s      cn88xx; */
	/* struct bdk_gserx_br_txx_ctl_s      cn88xxp1; */
} bdk_gserx_br_txx_ctl_t;

static inline uint64_t BDK_GSERX_BR_TXX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_BR_TXX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090000420ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x80ull;
	csr_fatal("BDK_GSERX_BR_TXX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_BR_TXX_CTL(...) bdk_gserx_br_txx_ctl_t
#define bustype_BDK_GSERX_BR_TXX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_BR_TXX_CTL(p1,p2) (p1)
#define arguments_BDK_GSERX_BR_TXX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_BR_TXX_CTL(...) "GSERX_BR_TXX_CTL"


/**
 * RSL - gser#_br_tx#_cur
 */
typedef union bdk_gserx_br_txx_cur {
	uint64_t u;
	struct bdk_gserx_br_txx_cur_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t txt_cur                     : 14; /**< R/W - When TX Base-R Link Training is being performed under software control,
                                                                 (GSER()_BR_TX()_CTL.TXT_SWM is set), this is the Coefficient Update to be written to the
                                                                 PHY.
                                                                 For diagnostic use only.
                                                                 \<13:9\> = TX_POST\<4:0\>.
                                                                 \<8:4\> = TX_SWING\<4:0\>.
                                                                 \<3:0\> = TX_PRE\<4:0\>. */
#else
		uint64_t txt_cur                     : 14;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_br_txx_cur_s      cn88xx; */
	/* struct bdk_gserx_br_txx_cur_s      cn88xxp1; */
} bdk_gserx_br_txx_cur_t;

static inline uint64_t BDK_GSERX_BR_TXX_CUR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_BR_TXX_CUR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090000438ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x80ull;
	csr_fatal("BDK_GSERX_BR_TXX_CUR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_BR_TXX_CUR(...) bdk_gserx_br_txx_cur_t
#define bustype_BDK_GSERX_BR_TXX_CUR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_BR_TXX_CUR(p1,p2) (p1)
#define arguments_BDK_GSERX_BR_TXX_CUR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_BR_TXX_CUR(...) "GSERX_BR_TXX_CUR"


/**
 * RSL - gser#_br_tx#_tap
 */
typedef union bdk_gserx_br_txx_tap {
	uint64_t u;
	struct bdk_gserx_br_txx_tap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t txt_pre                     : 4;  /**< RO/H - After TX Base-R Link Training, this is the resultant POST Tap value that was
                                                                 written to the PHY.  This field has no meaning if TX Base-R Link Traning was
                                                                 not performed.
                                                                 For diagnostic use only. */
		uint64_t txt_swing                   : 5;  /**< RO/H - After TX Base-R Link Training, this is the resultant SWING Tap value that was
                                                                 written to the PHY.  This field has no meaning if TX Base-R Link Traning was
                                                                 not performed.
                                                                 For diagnostic use only. */
		uint64_t txt_post                    : 5;  /**< RO/H - After TX Base-R Link Training, this is the resultant POST Tap value that was
                                                                 written to the PHY.  This field has no meaning if TX Base-R Link Traning was
                                                                 not performed.
                                                                 For diagnostic use only. */
#else
		uint64_t txt_post                    : 5;
		uint64_t txt_swing                   : 5;
		uint64_t txt_pre                     : 4;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_br_txx_tap_s      cn88xx; */
	/* struct bdk_gserx_br_txx_tap_s      cn88xxp1; */
} bdk_gserx_br_txx_tap_t;

static inline uint64_t BDK_GSERX_BR_TXX_TAP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_BR_TXX_TAP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090000440ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x80ull;
	csr_fatal("BDK_GSERX_BR_TXX_TAP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_BR_TXX_TAP(...) bdk_gserx_br_txx_tap_t
#define bustype_BDK_GSERX_BR_TXX_TAP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_BR_TXX_TAP(p1,p2) (p1)
#define arguments_BDK_GSERX_BR_TXX_TAP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_BR_TXX_TAP(...) "GSERX_BR_TXX_TAP"


/**
 * RSL - gser#_cfg
 */
typedef union bdk_gserx_cfg {
	uint64_t u;
	struct bdk_gserx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t sata                        : 1;  /**< R/W - Indicates the GSER is configured for SATA mode. Only one of the BGX, SATA, or PCIE
                                                                 modes can be set at any one time. */
		uint64_t bgx_quad                    : 1;  /**< R/W - For non-CCPI links, indicates the BGX is in quad aggregation mode when GSER()_CFG[BGX]
                                                                 is also set. A single controller is used for all four lanes. For CCPI links, this bit has
                                                                 no meaning. */
		uint64_t bgx_dual                    : 1;  /**< R/W - For non-CCPI links, indicates the BGX is in dual aggregation mode when GSER()_CFG[BGX]
                                                                 is also set. A single controller is used for lanes 0 and 1 and another controller is used
                                                                 for lanes 2 and 3. For CCPI links, this bit has no meaning. */
		uint64_t bgx                         : 1;  /**< R/W - For non-CCPI links, indicates the GSER is configured for BGX mode. Only one of the BGX,
                                                                 SATA, or PCIE modes can be set at any one time. For CCPI links, this bit has no meaning. */
		uint64_t ila                         : 1;  /**< R/W - Reserved. */
		uint64_t pcie                        : 1;  /**< R/W/H - For non-CCPI links, indicates the GSER is configured for PCIE mode. Only one of the BGX,
                                                                 ILA, or PCIE modes can be set at any one time. For CCPI links, this bit has no meaning. */
#else
		uint64_t pcie                        : 1;
		uint64_t ila                         : 1;
		uint64_t bgx                         : 1;
		uint64_t bgx_dual                    : 1;
		uint64_t bgx_quad                    : 1;
		uint64_t sata                        : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_gserx_cfg_s             cn88xx; */
	/* struct bdk_gserx_cfg_s             cn88xxp1; */
} bdk_gserx_cfg_t;

static inline uint64_t BDK_GSERX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_CFG(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000080ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_CFG(...) bdk_gserx_cfg_t
#define bustype_BDK_GSERX_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_CFG(p1) (p1)
#define arguments_BDK_GSERX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_CFG(...) "GSERX_CFG"


/**
 * RSL - gser#_dbg
 */
typedef union bdk_gserx_dbg {
	uint64_t u;
	struct bdk_gserx_dbg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t rxqtm_on                    : 1;  /**< R/W - For non-BGX configurations, setting this bit enables the RX FIFOs. This allows
                                                                 received data to become visible to the RSL debug port. For diagnostic use only. */
#else
		uint64_t rxqtm_on                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_dbg_s             cn88xx; */
	/* struct bdk_gserx_dbg_s             cn88xxp1; */
} bdk_gserx_dbg_t;

static inline uint64_t BDK_GSERX_DBG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_DBG(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000098ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_DBG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_DBG(...) bdk_gserx_dbg_t
#define bustype_BDK_GSERX_DBG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_DBG(p1) (p1)
#define arguments_BDK_GSERX_DBG(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_DBG(...) "GSERX_DBG"


/**
 * RSL - gser#_eq_wait_time
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_eq_wait_time {
	uint64_t u;
	struct bdk_gserx_eq_wait_time_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t rxeq_wait_cnt               : 4;  /**< R/W - Determines the wait time after VMA RX-EQ completes and before sampling
                                                                 tap1 and starting the precorrelation check. */
		uint64_t txeq_wait_cnt               : 4;  /**< R/W - Determines the wait time from applying the TX-EQ controls (swing/pre/post)
                                                                 to the sampling of the sds_pcs_tx_comp_out. */
#else
		uint64_t txeq_wait_cnt               : 4;
		uint64_t rxeq_wait_cnt               : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_gserx_eq_wait_time_s    cn88xx; */
	/* struct bdk_gserx_eq_wait_time_s    cn88xxp1; */
} bdk_gserx_eq_wait_time_t;

static inline uint64_t BDK_GSERX_EQ_WAIT_TIME(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_EQ_WAIT_TIME(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E0000ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_EQ_WAIT_TIME", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_EQ_WAIT_TIME(...) bdk_gserx_eq_wait_time_t
#define bustype_BDK_GSERX_EQ_WAIT_TIME(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_EQ_WAIT_TIME(p1) (p1)
#define arguments_BDK_GSERX_EQ_WAIT_TIME(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_EQ_WAIT_TIME(...) "GSERX_EQ_WAIT_TIME"


/**
 * RSL - gser#_glbl_pll_monitor
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_glbl_pll_monitor {
	uint64_t u;
	struct bdk_gserx_glbl_pll_monitor_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t sds_pcs_glbl_status         : 6;  /**< RO/H - Spare reserved for future use. Read data should be ignored. */
		uint64_t sds_pcs_pll_lock            : 1;  /**< RO/H - Status signal from Global indicates that PLL is locked. Not a true "lock" signal.
                                                                 Used to debug/test the PLL. */
		uint64_t sds_pcs_clock_ready         : 1;  /**< RO/H - Clock status signal, can be overriden with (I_PLL_CTRL_EN == 1).
                                                                 0 = Clock not ready.
                                                                 1 = Clock ready. */
		uint64_t sds_pcs_pll_calstates       : 5;  /**< RO/H - PLL calibration code. */
		uint64_t sds_pcs_pll_caldone         : 1;  /**< RO/H - PLL calibration done signal. */
#else
		uint64_t sds_pcs_pll_caldone         : 1;
		uint64_t sds_pcs_pll_calstates       : 5;
		uint64_t sds_pcs_clock_ready         : 1;
		uint64_t sds_pcs_pll_lock            : 1;
		uint64_t sds_pcs_glbl_status         : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_glbl_pll_monitor_s cn88xx; */
	/* struct bdk_gserx_glbl_pll_monitor_s cn88xxp1; */
} bdk_gserx_glbl_pll_monitor_t;

static inline uint64_t BDK_GSERX_GLBL_PLL_MONITOR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_GLBL_PLL_MONITOR(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090460100ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_GLBL_PLL_MONITOR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_GLBL_PLL_MONITOR(...) bdk_gserx_glbl_pll_monitor_t
#define bustype_BDK_GSERX_GLBL_PLL_MONITOR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_GLBL_PLL_MONITOR(p1) (p1)
#define arguments_BDK_GSERX_GLBL_PLL_MONITOR(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_GLBL_PLL_MONITOR(...) "GSERX_GLBL_PLL_MONITOR"


/**
 * RSL - gser#_glbl_tad
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_glbl_tad {
	uint64_t u;
	struct bdk_gserx_glbl_tad_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t pcs_sds_tad_8_5             : 4;  /**< R/W - AMON Specific mode selection.
                                                                 Set GSER()_GLBL_TM_ADMON[AMON_ON].
                                                                 Decodes 0x0 - 0x4 require GSER()_GLBL_TM_ADMON[LSEL] set.
                                                                 Decodes 0x5 - 0x5 do not require GSER()_GLBL_TM_ADMON[LSEL] set.
                                                                 In both cases, the resulting signals can be observed on the AMON pin.

                                                                 0x0 = TX txdrv DAC 100ua sink current monitor.
                                                                 0x1 = TX vcnt precision dcc.
                                                                 0x2 = RX sdll topregout.
                                                                 0x3 = RX ldll vctrl_i.
                                                                 0x4 = RX RX term VCM voltage.
                                                                 0x5 = Global bandgap voltage.
                                                                 0x6 = Global CTAT voltage.
                                                                 0x7 = Global internal 100ua reference current.
                                                                 0x8 = Global external 100ua reference current.
                                                                 0x9 = Global Rterm calibration reference voltage.
                                                                 0xA = Global Rterm calibration comparator voltage.
                                                                 0xB = Global Force VCNT thru DAC.
                                                                 0xC = Global VDD voltage.
                                                                 0xD = Global VDDCLK voltage.
                                                                 0xE = Global PLL regulate VCO supply.
                                                                 0xF = Global VCTRL for VCO varactor control. */
		uint64_t pcs_sds_tad_4_0             : 5;  /**< R/W - DMON Specific mode selection.
                                                                 Set GSER()_GLBL_TM_ADMON[DMON_ON].
                                                                 Decodes 0x0 - 0xe require GSER()_GLBL_TM_ADMON[LSEL] set.
                                                                 Decodes 0xf - 0x1f do not require GSER()_GLBL_TM_ADMON[LSEL] set.
                                                                 In both cases, the resulting signals can be observed on the DMON pin.

                                                                 0x00 = DFE Data Q.
                                                                 0x01 = DFE Edge I.
                                                                 0x02 = DFE CK Q.
                                                                 0x03 = DFE CK I.
                                                                 0x04 = TBD.
                                                                 0x05-0x7 = Reserved.
                                                                 0x08 = RX ld_rx[0].
                                                                 0x09 = RX rx_clk.
                                                                 0x0A = RX q_error_stg.
                                                                 0x0B = RX q_data_stg.
                                                                 0x0C-0x0E = Reserved.
                                                                 0x0F = Special case to observe supply in global. Sds_vdda and a internal regulated supply
                                                                 can be observed on DMON and DMONB
                                                                 respectively.  sds_vss can be observed on AMON. GSER()_GLBL_TM_ADMON[AMON_ON]
                                                                 must not be set.
                                                                 0x10: PLL_CLK 0 degree.
                                                                 0x11: Sds_tst_fb_clk.
                                                                 0x12: Buffered refclk.
                                                                 0x13: Div 8 of core clock (core_clk_out).
                                                                 0x14-0x1F: Reserved. */
#else
		uint64_t pcs_sds_tad_4_0             : 5;
		uint64_t pcs_sds_tad_8_5             : 4;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_gserx_glbl_tad_s        cn88xx; */
	/* struct bdk_gserx_glbl_tad_s        cn88xxp1; */
} bdk_gserx_glbl_tad_t;

static inline uint64_t BDK_GSERX_GLBL_TAD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_GLBL_TAD(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090460400ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_GLBL_TAD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_GLBL_TAD(...) bdk_gserx_glbl_tad_t
#define bustype_BDK_GSERX_GLBL_TAD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_GLBL_TAD(p1) (p1)
#define arguments_BDK_GSERX_GLBL_TAD(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_GLBL_TAD(...) "GSERX_GLBL_TAD"


/**
 * RSL - gser#_glbl_tm_admon
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_glbl_tm_admon {
	uint64_t u;
	struct bdk_gserx_glbl_tm_admon_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t amon_on                     : 1;  /**< R/W - When set, AMON test mode is enabled; see GSER()_GLBL_TAD. */
		uint64_t dmon_on                     : 1;  /**< R/W - When set, DMON test mode is enabled; see GSER()_GLBL_TAD. */
		uint64_t reserved_3_5                : 3;
		uint64_t lsel                        : 3;  /**< R/W - Three bits to select 1 out of 4 lanes for AMON/DMON test.
                                                                 0x0 = Selects lane 0.
                                                                 0x1 = Selects lane 1.
                                                                 0x2 = Selects lane 2.
                                                                 0x3 = Selects lane 3.
                                                                 0x4-0x7 = Reserved. */
#else
		uint64_t lsel                        : 3;
		uint64_t reserved_3_5                : 3;
		uint64_t dmon_on                     : 1;
		uint64_t amon_on                     : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_gserx_glbl_tm_admon_s   cn88xx; */
	/* struct bdk_gserx_glbl_tm_admon_s   cn88xxp1; */
} bdk_gserx_glbl_tm_admon_t;

static inline uint64_t BDK_GSERX_GLBL_TM_ADMON(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_GLBL_TM_ADMON(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090460408ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_GLBL_TM_ADMON", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_GLBL_TM_ADMON(...) bdk_gserx_glbl_tm_admon_t
#define bustype_BDK_GSERX_GLBL_TM_ADMON(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_GLBL_TM_ADMON(p1) (p1)
#define arguments_BDK_GSERX_GLBL_TM_ADMON(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_GLBL_TM_ADMON(...) "GSERX_GLBL_TM_ADMON"


/**
 * RSL - gser#_iddq_mode
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_iddq_mode {
	uint64_t u;
	struct bdk_gserx_iddq_mode_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t phy_iddq_mode               : 1;  /**< R/W - When set, power downs all circuitry in PHY for IDDQ testing */
#else
		uint64_t phy_iddq_mode               : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_iddq_mode_s       cn88xx; */
	/* struct bdk_gserx_iddq_mode_s       cn88xxp1; */
} bdk_gserx_iddq_mode_t;

static inline uint64_t BDK_GSERX_IDDQ_MODE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_IDDQ_MODE(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000018ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_IDDQ_MODE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_IDDQ_MODE(...) bdk_gserx_iddq_mode_t
#define bustype_BDK_GSERX_IDDQ_MODE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_IDDQ_MODE(p1) (p1)
#define arguments_BDK_GSERX_IDDQ_MODE(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_IDDQ_MODE(...) "GSERX_IDDQ_MODE"


/**
 * RSL - gser#_lane#_lbert_cfg
 *
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_lbert_cfg {
	uint64_t u;
	struct bdk_gserx_lanex_lbert_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t lbert_pg_err_insert         : 1;  /**< WO/H - Insert one bit error into the LSB of the LBERT generated
                                                                 stream.  A single write to this bit inserts a single bit
                                                                 error. */
		uint64_t lbert_pm_sync_start         : 1;  /**< WO/H - Synchronize the pattern matcher LFSR with the incoming
                                                                 data.  Writing this bit resets the error counter and
                                                                 starts a synchronization of the PM.  There is no need
                                                                 to write this bit back to a zero to run normally. */
		uint64_t lbert_pg_en                 : 1;  /**< R/W - Enable the LBERT pattern generator. */
		uint64_t lbert_pg_width              : 2;  /**< R/W - LBERT pattern generator data width:
                                                                 0x0 = 8-bit data.
                                                                 0x1 = 10-bit data.
                                                                 0x2 = 16-bit data.
                                                                 0x3 = 20-bit data. */
		uint64_t lbert_pg_mode               : 4;  /**< R/W - LBERT pattern generator mode; when changing modes,
                                                                 must be disabled first:
                                                                 0x0 = Disabled.
                                                                 0x1 = lfsr31 = X^31 + X^28 + 1.
                                                                 0x2 = lfsr23 = X^23 + X^18 + 1.
                                                                 0x3 = lfsr23 = X^23 + X^21 + X^16 + X^8 + X^5 + X^2 + 1.
                                                                 0x4 = lfsr16 = X^16 + X^5 + X^4 + X^3 + 1.
                                                                 0x5 = lfsr15 = X^15 + X^14 + 1.
                                                                 0x6 = lfsr11 = X^11 + X^9 + 1.
                                                                 0x7 = lfsr7  = X^7 + X^6 + 1.
                                                                 0x8 = Fixed word (PAT0).
                                                                 0x9 = DC-balanced word (PAT0, ~PAT0)
                                                                 0xA = Fixed Pattern (000, PAT0, 3ff, ~PAT0).
                                                                 0xB-F = Reserved. */
		uint64_t lbert_pm_en                 : 1;  /**< R/W - Enable LBERT pattern matcher. */
		uint64_t lbert_pm_width              : 2;  /**< R/W - LBERT pattern matcher data width.
                                                                 0x0 = 8-bit data.
                                                                 0x1 = 10-bit data.
                                                                 0x2 = 16-bit data.
                                                                 0x3 = 20-bit data. */
		uint64_t lbert_pm_mode               : 4;  /**< R/W - LBERT pattern matcher mode; when changing modes,
                                                                 must be disabled first:
                                                                 0x0 = Disabled.
                                                                 0x1 = lfsr31 = X^31 + X^28 + 1.
                                                                 0x2 = lfsr23 = X^23 + X^18 + 1.
                                                                 0x3 = lfsr23 = X^23 + X^21 + X^16 + X^8 + X^5 + X^2 + 1.
                                                                 0x4 = lfsr16 = X^16 + X^5 + X^4 + X^3 + 1.
                                                                 0x5 = lfsr15 = X^15 + X^14 + 1.
                                                                 0x6 = lfsr11 = X^11 + X^9 + 1.
                                                                 0x7 = lfsr7  = X^7 + X^6 + 1.
                                                                 0x8 = Fixed word (PAT0).
                                                                 0x9 = DC-balanced word (PAT0, ~PAT0).
                                                                 0xA = Fixed Pattern: (000, PAT0, 3ff, ~PAT0).
                                                                 0xB-F = Reserved. */
#else
		uint64_t lbert_pm_mode               : 4;
		uint64_t lbert_pm_width              : 2;
		uint64_t lbert_pm_en                 : 1;
		uint64_t lbert_pg_mode               : 4;
		uint64_t lbert_pg_width              : 2;
		uint64_t lbert_pg_en                 : 1;
		uint64_t lbert_pm_sync_start         : 1;
		uint64_t lbert_pg_err_insert         : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_lbert_cfg_s cn88xx; */
	/* struct bdk_gserx_lanex_lbert_cfg_s cn88xxp1; */
} bdk_gserx_lanex_lbert_cfg_t;

static inline uint64_t BDK_GSERX_LANEX_LBERT_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_LBERT_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0020ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_LBERT_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_LBERT_CFG(...) bdk_gserx_lanex_lbert_cfg_t
#define bustype_BDK_GSERX_LANEX_LBERT_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_LBERT_CFG(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_LBERT_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_LBERT_CFG(...) "GSERX_LANEX_LBERT_CFG"


/**
 * RSL - gser#_lane#_lbert_ecnt
 *
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 * The error registers are reset on a read-only when the pattern matcher is enabled.
 * If the pattern matcher is disabled, the registers return the error count that was
 * indicated when the pattern matcher was disabled and never reset.
 */
typedef union bdk_gserx_lanex_lbert_ecnt {
	uint64_t u;
	struct bdk_gserx_lanex_lbert_ecnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t lbert_err_ovbit14           : 1;  /**< RO/H - If this bit is set, multiply LBERT_ERR_CNT by 128.
                                                                 If this bit is set and LBERT_ERR_CNT = 2^15-1, signals
                                                                 overflow of the counter. */
		uint64_t lbert_err_cnt               : 15; /**< RO/H - Current error count.
                                                                 If LBERT_ERR_OVBIT14 field is active, then multiply
                                                                 count by 128. */
#else
		uint64_t lbert_err_cnt               : 15;
		uint64_t lbert_err_ovbit14           : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_lbert_ecnt_s cn88xx; */
	/* struct bdk_gserx_lanex_lbert_ecnt_s cn88xxp1; */
} bdk_gserx_lanex_lbert_ecnt_t;

static inline uint64_t BDK_GSERX_LANEX_LBERT_ECNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_LBERT_ECNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0028ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_LBERT_ECNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_LBERT_ECNT(...) bdk_gserx_lanex_lbert_ecnt_t
#define bustype_BDK_GSERX_LANEX_LBERT_ECNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_LBERT_ECNT(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_LBERT_ECNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_LBERT_ECNT(...) "GSERX_LANEX_LBERT_ECNT"


/**
 * RSL - gser#_lane#_lbert_pat_cfg
 *
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_lbert_pat_cfg {
	uint64_t u;
	struct bdk_gserx_lanex_lbert_pat_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t lbert_pg_pat                : 10; /**< R/W - Programmable 10-bit pattern to be used in the LBERT pattern mode;
                                                                 applies when GSER()_LANE()_LBERT_CFG[LBERT_PG_MODE]
                                                                 is equal to 8, 9, or 10. */
#else
		uint64_t lbert_pg_pat                : 10;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lanex_lbert_pat_cfg_s cn88xx; */
	/* struct bdk_gserx_lanex_lbert_pat_cfg_s cn88xxp1; */
} bdk_gserx_lanex_lbert_pat_cfg_t;

static inline uint64_t BDK_GSERX_LANEX_LBERT_PAT_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_LBERT_PAT_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0018ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_LBERT_PAT_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_LBERT_PAT_CFG(...) bdk_gserx_lanex_lbert_pat_cfg_t
#define bustype_BDK_GSERX_LANEX_LBERT_PAT_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_LBERT_PAT_CFG(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_LBERT_PAT_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_LBERT_PAT_CFG(...) "GSERX_LANEX_LBERT_PAT_CFG"


/**
 * RSL - gser#_lane#_misc_cfg_0
 *
 * These registers are for diagnostic use only.
 * They are reset by hardware only during chip cold reset.
 * The values of the fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_misc_cfg_0 {
	uint64_t u;
	struct bdk_gserx_lanex_misc_cfg_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t use_pma_polarity            : 1;  /**< R/W - If set, the PMA control is used to define the polarity.
                                                                 If not set, GSER()_LANE()_RX_CFG_0[CFG_RX_POL_INVERT]
                                                                 is used. */
		uint64_t cfg_pcs_loopback            : 1;  /**< R/W - Assert for Parallel Loopback Raw PCS TX to Raw PCS RX. */
		uint64_t pcs_tx_mode_ovrrd_en        : 1;  /**< R/W - Override enable for Raw PCS TX data width. */
		uint64_t pcs_rx_mode_ovrrd_en        : 1;  /**< R/W - Override enable for Raw PCS RX data width. */
		uint64_t cfg_eie_det_cnt             : 4;  /**< R/W - EIE detect state machine required number of consecutive
                                                                 PHY EIE status assertions to determine EIE and assert Raw
                                                                 PCS output pcs_mac_rx_eie_det_sts. */
		uint64_t eie_det_stl_on_time         : 3;  /**< R/W - EIE detect state machine "on" delay prior to sampling
                                                                 PHY EIE status.  Software needs to set this field to 0x4 if
                                                                 in SATA mode (GSER()_CFG[SATA] is set). */
		uint64_t eie_det_stl_off_time        : 3;  /**< R/W - EIE detect state machine "off" delay prior to sampling
                                                                 PHY EIE status. */
		uint64_t tx_bit_order                : 1;  /**< R/W - Specify transmit bit order.
                                                                 1 = reverse bit order of parallel data to SerDes TX.
                                                                 0 = maintain bit order of parallel data to SerDes TX. */
		uint64_t rx_bit_order                : 1;  /**< R/W - Specify receive bit order:
                                                                 1 = reverse bit order of parallel data to SerDes RX.
                                                                 0 = maintain bit order of parallel data to SerDes RX. */
#else
		uint64_t rx_bit_order                : 1;
		uint64_t tx_bit_order                : 1;
		uint64_t eie_det_stl_off_time        : 3;
		uint64_t eie_det_stl_on_time         : 3;
		uint64_t cfg_eie_det_cnt             : 4;
		uint64_t pcs_rx_mode_ovrrd_en        : 1;
		uint64_t pcs_tx_mode_ovrrd_en        : 1;
		uint64_t cfg_pcs_loopback            : 1;
		uint64_t use_pma_polarity            : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_misc_cfg_0_s cn88xx; */
	/* struct bdk_gserx_lanex_misc_cfg_0_s cn88xxp1; */
} bdk_gserx_lanex_misc_cfg_0_t;

static inline uint64_t BDK_GSERX_LANEX_MISC_CFG_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_MISC_CFG_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0000ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_MISC_CFG_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_MISC_CFG_0(...) bdk_gserx_lanex_misc_cfg_0_t
#define bustype_BDK_GSERX_LANEX_MISC_CFG_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_MISC_CFG_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_MISC_CFG_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_MISC_CFG_0(...) "GSERX_LANEX_MISC_CFG_0"


/**
 * RSL - gser#_lane#_misc_cfg_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_misc_cfg_1 {
	uint64_t u;
	struct bdk_gserx_lanex_misc_cfg_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t par_tx_init                 : 1;  /**< R/W - Performs parallel initialization of SerDes interface TX
                                                                 fifo pointers. */
		uint64_t tx_polarity                 : 1;  /**< R/W - Invert polarity of trasmitted bit stream.  Inversion is
                                                                 performed in the SerDes interface transmit datapth. */
		uint64_t rx_polarity_ovrrd_en        : 1;  /**< R/W - Override mac_pcs_rxX_polarity control pin values
                                                                 When set, RX polarity inversion is specified from
                                                                 RX_POLARITY_OVRRD_VAL, and mac_pcs_rxX_polarity is ignored. */
		uint64_t rx_polarity_ovrrd_val       : 1;  /**< R/W - Controls RX polarity inversion when RX_POLARITY_OVRRD_EN
                                                                 is set. Inversion is performed in the SerDes interface receive
                                                                 datapath. */
		uint64_t reserved_2_8                : 7;
		uint64_t mac_tx_fifo_rd_ptr_ival     : 2;  /**< R/W/H - Initial value for MAC to PCS TX FIFO read pointer. */
#else
		uint64_t mac_tx_fifo_rd_ptr_ival     : 2;
		uint64_t reserved_2_8                : 7;
		uint64_t rx_polarity_ovrrd_val       : 1;
		uint64_t rx_polarity_ovrrd_en        : 1;
		uint64_t tx_polarity                 : 1;
		uint64_t par_tx_init                 : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_gserx_lanex_misc_cfg_1_s cn88xx; */
	/* struct bdk_gserx_lanex_misc_cfg_1_s cn88xxp1; */
} bdk_gserx_lanex_misc_cfg_1_t;

static inline uint64_t BDK_GSERX_LANEX_MISC_CFG_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_MISC_CFG_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0008ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_MISC_CFG_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_MISC_CFG_1(...) bdk_gserx_lanex_misc_cfg_1_t
#define bustype_BDK_GSERX_LANEX_MISC_CFG_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_MISC_CFG_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_MISC_CFG_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_MISC_CFG_1(...) "GSERX_LANEX_MISC_CFG_1"


/**
 * RSL - gser#_lane#_pcs_ctlifc_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_pcs_ctlifc_0 {
	uint64_t u;
	struct bdk_gserx_lanex_pcs_ctlifc_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t cfg_tx_vboost_en_ovrrd_val  : 1;  /**< R/W - Specifies TX VBOOST Enable request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_VBOOST_EN_OVRRD_EN]. */
		uint64_t cfg_tx_coeff_req_ovrrd_val  : 1;  /**< R/W - Specifies TX Coefficient request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_COEFF_REQ_OVRRD_EN]. */
		uint64_t cfg_rx_cdr_coast_req_ovrrd_val : 1;/**< R/W - Specifies RX CDR Coast request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_RX_COAST_REQ_OVRRD_EN]. */
		uint64_t cfg_tx_detrx_en_req_ovrrd_val : 1;/**< R/W - Specifies TX Detect RX request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_DETRX_EN_REQ_OVRRD_EN]. */
		uint64_t cfg_soft_reset_req_ovrrd_val : 1; /**< R/W - Specifies Soft Reset request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_SOFT_RESET_REQ_OVRRD_EN]. */
		uint64_t cfg_lane_pwr_off_ovrrd_val  : 1;  /**< R/W - Specifies Lane Power Off Reset request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_LANE_PWR_OFF_OVRRD_EN]. */
		uint64_t cfg_tx_mode_ovrrd_val       : 2;  /**< R/W - Override PCS TX mode (data width) when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_MODE_OVRRD_EN].
                                                                 0x0 = 8-bit raw data (not supported).
                                                                 0x1 = 10-bit raw data (not supported).
                                                                 0x2 = 16-bit raw data (not supported).
                                                                 0x3 = 20-bit raw data. */
		uint64_t cfg_tx_pstate_req_ovrrd_val : 2;  /**< R/W - Override TX pstate request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_PSTATE_REQ_OVRRD_EN]. */
		uint64_t cfg_lane_mode_req_ovrrd_val : 4;  /**< R/W - Override Lane Mode request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_LANE_MODE_REQ_OVRRD_EN]. */
#else
		uint64_t cfg_lane_mode_req_ovrrd_val : 4;
		uint64_t cfg_tx_pstate_req_ovrrd_val : 2;
		uint64_t cfg_tx_mode_ovrrd_val       : 2;
		uint64_t cfg_lane_pwr_off_ovrrd_val  : 1;
		uint64_t cfg_soft_reset_req_ovrrd_val : 1;
		uint64_t cfg_tx_detrx_en_req_ovrrd_val : 1;
		uint64_t cfg_rx_cdr_coast_req_ovrrd_val : 1;
		uint64_t cfg_tx_coeff_req_ovrrd_val  : 1;
		uint64_t cfg_tx_vboost_en_ovrrd_val  : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_lanex_pcs_ctlifc_0_s cn88xx; */
	/* struct bdk_gserx_lanex_pcs_ctlifc_0_s cn88xxp1; */
} bdk_gserx_lanex_pcs_ctlifc_0_t;

static inline uint64_t BDK_GSERX_LANEX_PCS_CTLIFC_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_PCS_CTLIFC_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0060ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_PCS_CTLIFC_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_PCS_CTLIFC_0(...) bdk_gserx_lanex_pcs_ctlifc_0_t
#define bustype_BDK_GSERX_LANEX_PCS_CTLIFC_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_PCS_CTLIFC_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_PCS_CTLIFC_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_PCS_CTLIFC_0(...) "GSERX_LANEX_PCS_CTLIFC_0"


/**
 * RSL - gser#_lane#_pcs_ctlifc_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_pcs_ctlifc_1 {
	uint64_t u;
	struct bdk_gserx_lanex_pcs_ctlifc_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t cfg_rx_pstate_req_ovrrd_val : 2;  /**< R/W - Override RX pstate request when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_PSTATE_REQ_OVRRD_EN]. */
		uint64_t reserved_2_6                : 5;
		uint64_t cfg_rx_mode_ovrrd_val       : 2;  /**< R/W - Override PCS RX mode (data width) when its override bit
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_RX_MODE_OVRRD_EN].
                                                                 0x0 = 8-bit raw data (not supported).
                                                                 0x1 = 10-bit raw data (not supported).
                                                                 0x2 = 16-bit raw data (not supported).
                                                                 0x3 = 20-bit raw data. */
#else
		uint64_t cfg_rx_mode_ovrrd_val       : 2;
		uint64_t reserved_2_6                : 5;
		uint64_t cfg_rx_pstate_req_ovrrd_val : 2;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_gserx_lanex_pcs_ctlifc_1_s cn88xx; */
	/* struct bdk_gserx_lanex_pcs_ctlifc_1_s cn88xxp1; */
} bdk_gserx_lanex_pcs_ctlifc_1_t;

static inline uint64_t BDK_GSERX_LANEX_PCS_CTLIFC_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_PCS_CTLIFC_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0068ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_PCS_CTLIFC_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_PCS_CTLIFC_1(...) bdk_gserx_lanex_pcs_ctlifc_1_t
#define bustype_BDK_GSERX_LANEX_PCS_CTLIFC_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_PCS_CTLIFC_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_PCS_CTLIFC_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_PCS_CTLIFC_1(...) "GSERX_LANEX_PCS_CTLIFC_1"


/**
 * RSL - gser#_lane#_pcs_ctlifc_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_pcs_ctlifc_2 {
	uint64_t u;
	struct bdk_gserx_lanex_pcs_ctlifc_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t ctlifc_ovrrd_req            : 1;  /**< WO - Writing to set this bit initiates a state machine interface request
                                                                 for GSER()_LANE()_PCS_CTLIFC_0 and GSER()_LANE()_PCS_CTLIFC_1
                                                                 override values. */
		uint64_t reserved_9_14               : 6;
		uint64_t cfg_tx_vboost_en_ovrrd_en   : 1;  /**< R/W - Override mac_pcs_txX vboost_en signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_VBOOST_EN_OVRRD_VAL]. */
		uint64_t cfg_tx_coeff_req_ovrrd_en   : 1;  /**< R/W - Override mac_pcs_txX_coeff_req signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_0[CFG_TX_COEFF_REQ_OVRRD_VAL]. */
		uint64_t cfg_rx_cdr_coast_req_ovrrd_en : 1;/**< R/W - Override mac_pcs_rxX_cdr_coast signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_RX_COAST_REQ_OVRRD_VAL]. */
		uint64_t cfg_tx_detrx_en_req_ovrrd_en : 1; /**< R/W - Override mac_pcs_txX_detrx_en signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_DETRX_EN_REQ_OVRRD_VAL]. */
		uint64_t cfg_soft_reset_req_ovrrd_en : 1;  /**< R/W - Override mac_pcs_laneX_soft_rst signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_SOFT_RESET_REQ_OVRRD_VAL]. */
		uint64_t cfg_lane_pwr_off_ovrrd_en   : 1;  /**< R/W - Override mac_pcs_laneX_pwr_off signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_LANE_PWR_OFF_OVRRD_VAL]. */
		uint64_t cfg_tx_pstate_req_ovrrd_en  : 1;  /**< R/W - Override mac_pcs_txX_pstate[1:0] signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_TX_PSTATE_REQ_OVRRD_VAL].
                                                                 When using this field to change the TX Power State, you must also set
                                                                 the override enable bits for the lane_mode, soft_reset and lane_pwr_off
                                                                 fields.  The corresponding orrd_val fields should be programmed so as
                                                                 not to cause undesired changes. */
		uint64_t cfg_rx_pstate_req_ovrrd_en  : 1;  /**< R/W - Override mac_pcs_rxX_pstate[1:0] signal with the value specified in
                                                                 GSER()_LANE()_PCS_CTLIFC_2[CFG_RX_PSTATE_REQ_OVRRD_VAL].
                                                                 When using this field to change the RX Power State, you must also set
                                                                 the override enable bits for the lane_mode, soft_reset and lane_pwr_off
                                                                 fields.  The corresponding orrd_val fields should be programmed so as
                                                                 not to cause undesired changes. */
		uint64_t cfg_lane_mode_req_ovrrd_en  : 1;  /**< R/W - Override mac_pcs_laneX_mode[3:0] signal with the value specified in
                                                                 is asserted GSER()_LANE()_PCS_CTLIFC_2[CFG_LANE_MODE_REQ_OVRRD_VAL]. */
#else
		uint64_t cfg_lane_mode_req_ovrrd_en  : 1;
		uint64_t cfg_rx_pstate_req_ovrrd_en  : 1;
		uint64_t cfg_tx_pstate_req_ovrrd_en  : 1;
		uint64_t cfg_lane_pwr_off_ovrrd_en   : 1;
		uint64_t cfg_soft_reset_req_ovrrd_en : 1;
		uint64_t cfg_tx_detrx_en_req_ovrrd_en : 1;
		uint64_t cfg_rx_cdr_coast_req_ovrrd_en : 1;
		uint64_t cfg_tx_coeff_req_ovrrd_en   : 1;
		uint64_t cfg_tx_vboost_en_ovrrd_en   : 1;
		uint64_t reserved_9_14               : 6;
		uint64_t ctlifc_ovrrd_req            : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_pcs_ctlifc_2_s cn88xx; */
	/* struct bdk_gserx_lanex_pcs_ctlifc_2_s cn88xxp1; */
} bdk_gserx_lanex_pcs_ctlifc_2_t;

static inline uint64_t BDK_GSERX_LANEX_PCS_CTLIFC_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_PCS_CTLIFC_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904C0070ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_PCS_CTLIFC_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_PCS_CTLIFC_2(...) bdk_gserx_lanex_pcs_ctlifc_2_t
#define bustype_BDK_GSERX_LANEX_PCS_CTLIFC_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_PCS_CTLIFC_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_PCS_CTLIFC_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_PCS_CTLIFC_2(...) "GSERX_LANEX_PCS_CTLIFC_2"


/**
 * RSL - gser#_lane#_pma_loopback_ctrl
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_pma_loopback_ctrl {
	uint64_t u;
	struct bdk_gserx_lanex_pma_loopback_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t cfg_ln_lpbk_mode_ovrrd_en   : 1;  /**< R/W - Enable override mac_pcs_loopbk_mode[3:0] with value of FG_LN_LPBK_MODE. */
		uint64_t cfg_ln_lpbk_mode            : 1;  /**< R/W - Override value when CFG_LN_LPBK_MODE_OVRRD_EN is set. */
#else
		uint64_t cfg_ln_lpbk_mode            : 1;
		uint64_t cfg_ln_lpbk_mode_ovrrd_en   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gserx_lanex_pma_loopback_ctrl_s cn88xx; */
	/* struct bdk_gserx_lanex_pma_loopback_ctrl_s cn88xxp1; */
} bdk_gserx_lanex_pma_loopback_ctrl_t;

static inline uint64_t BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400D0ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(...) bdk_gserx_lanex_pma_loopback_ctrl_t
#define bustype_BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_PMA_LOOPBACK_CTRL(...) "GSERX_LANEX_PMA_LOOPBACK_CTRL"


/**
 * RSL - gser#_lane#_pwr_ctrl
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_pwr_ctrl {
	uint64_t u;
	struct bdk_gserx_lanex_pwr_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t tx_sds_fifo_reset_ovrrd_en  : 1;  /**< R/W - When asserted, TX_SDS_FIFO_RESET_OVVRD_VAL is used to specify the value of the reset
                                                                 signal for the TX FIFO supplying data to the SerDes p2s interface. */
		uint64_t tx_sds_fifo_reset_ovrrd_val : 1;  /**< R/W - When asserted, TX_SDS_FIFO_RESET_OVVRD_EN is asserted, this field is
                                                                 used to specify the value of the reset
                                                                 signal for the TX FIFO supplying data to the SerDes p2s interface. */
		uint64_t tx_pcs_reset_ovrrd_val      : 1;  /**< R/W - When TX_PCS_RESET_OVRRD_EN is
                                                                 asserted, this field is used to specify the value of
                                                                 the reset signal for PCS TX logic. */
		uint64_t rx_pcs_reset_ovrrd_val      : 1;  /**< R/W - When RX_PCS_RESET_OVRRD_EN is
                                                                 asserted, this field is used to specify the value of
                                                                 the reset signal for PCS RX logic. */
		uint64_t reserved_9_10               : 2;
		uint64_t rx_resetn_ovrrd_en          : 1;  /**< R/W - Override RX Power State machine rx_resetn
                                                                 control signal.  When set, the rx_resetn control signal is taken
                                                                 from the GSER()_LANE()_RX_CFG_0[RX_RESETN_OVRRD_VAL]
                                                                 control bit. */
		uint64_t rx_resetn_ovrrd_val         : 1;  /**< R/W - Override RX Power State machine reset control
                                                                 signal. When set, reset control signals are specified in
                                                                 [RX_PCS_RESET_OVRRD_VAL]. */
		uint64_t rx_lctrl_ovrrd_en           : 1;  /**< R/W - Override RX Power State machine loop control
                                                                 signals.  When set, the loop control settings are
                                                                 specified in the GSER()_LANE()_RX_LOOP_CTRL[CFG_RX_LCTRL] field. */
		uint64_t rx_lctrl_ovrrd_val          : 1;  /**< R/W - Override RX Power State machine power down
                                                                 control signal. When set, the power down control signal is
                                                                 specified by GSER()_LANE()_RX_CFG_1[RX_CHPD_OVRRD_VAL]. */
		uint64_t tx_tristate_en_ovrrd_en     : 1;  /**< R/W - Override TX Power State machine TX tristate
                                                                 control signal.  When set, TX tristate control signal is specified
                                                                 in GSER()_LANE()_TX_CFG_0[TX_TRISTATE_EN_OVRRD_VAL]. */
		uint64_t tx_pcs_reset_ovrrd_en       : 1;  /**< R/W - Override TX Power State machine reset control
                                                                 signal.  When set, reset control signals is specified in
                                                                 [TX_PCS_RESET_OVRRD_VAL]. */
		uint64_t tx_elec_idle_ovrrd_en       : 1;  /**< R/W - Override mac_pcs_txX_elec_idle signal
                                                                 When set, TX electrical idle is controlled from
                                                                 GSER()_LANE()_TX_CFG_1[TX_ELEC_IDLE_OVRRD_VAL]
                                                                 mac_pcs_txX_elec_idle signal is ignored. */
		uint64_t tx_pd_ovrrd_en              : 1;  /**< R/W - Override TX Power State machine TX lane
                                                                 power-down control signal
                                                                 When set, TX lane power down is controlled by
                                                                 GSER()_LANE()_TX_CFG_0[TX_CHPD_OVRRD_VAL]. */
		uint64_t tx_p2s_resetn_ovrrd_en      : 1;  /**< R/W - Override TX Power State machine TX reset
                                                                 control signal
                                                                 When set, TX reset is controlled by
                                                                 GSER()_LANE()_TX_CFG_0[TX_RESETN_OVRRD_VAL]. */
#else
		uint64_t tx_p2s_resetn_ovrrd_en      : 1;
		uint64_t tx_pd_ovrrd_en              : 1;
		uint64_t tx_elec_idle_ovrrd_en       : 1;
		uint64_t tx_pcs_reset_ovrrd_en       : 1;
		uint64_t tx_tristate_en_ovrrd_en     : 1;
		uint64_t rx_lctrl_ovrrd_val          : 1;
		uint64_t rx_lctrl_ovrrd_en           : 1;
		uint64_t rx_resetn_ovrrd_val         : 1;
		uint64_t rx_resetn_ovrrd_en          : 1;
		uint64_t reserved_9_10               : 2;
		uint64_t rx_pcs_reset_ovrrd_val      : 1;
		uint64_t tx_pcs_reset_ovrrd_val      : 1;
		uint64_t tx_sds_fifo_reset_ovrrd_val : 1;
		uint64_t tx_sds_fifo_reset_ovrrd_en  : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_pwr_ctrl_s  cn88xx; */
	/* struct bdk_gserx_lanex_pwr_ctrl_s  cn88xxp1; */
} bdk_gserx_lanex_pwr_ctrl_t;

static inline uint64_t BDK_GSERX_LANEX_PWR_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_PWR_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400D8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_PWR_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_PWR_CTRL(...) bdk_gserx_lanex_pwr_ctrl_t
#define bustype_BDK_GSERX_LANEX_PWR_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_PWR_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_PWR_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_PWR_CTRL(...) "GSERX_LANEX_PWR_CTRL"


/**
 * RSL - gser#_lane#_pwr_ctrl_p2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_pwr_ctrl_p2 {
	uint64_t u;
	struct bdk_gserx_lanex_pwr_ctrl_p2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t p2_rx_resetn                : 1;  /**< R/W - Place the reciever in reset (active low). */
		uint64_t p2_rx_allow_pll_pd          : 1;  /**< R/W - When asserted, it permits PLL powerdown (PLL is
                                                                 powered down if all other factors permit). */
		uint64_t p2_rx_pcs_reset             : 1;  /**< R/W - When asserted, the RX Power state machine puts the Raw PCS
                                                                 RX logic in reset state to save power. */
		uint64_t p2_rx_agc_en                : 1;  /**< R/W - AGC enable. */
		uint64_t p2_rx_dfe_en                : 1;  /**< R/W - DFE enable. */
		uint64_t p2_rx_cdr_en                : 1;  /**< R/W - CDR enable. */
		uint64_t p2_rx_cdr_coast             : 1;  /**< R/W - CDR coast; freezes the frequency of the CDR. */
		uint64_t p2_rx_cdr_clr               : 1;  /**< R/W - CDR clear; clears the frequency register in the CDR. */
		uint64_t p2_rx_subblk_pd             : 5;  /**< R/W - RX sub-block powerdown to RX:
                                                                 \<4\> = CTLE.
                                                                 \<3\> = Reserved.
                                                                 \<2\> = Lane DLL.
                                                                 \<1\> = DFE/Samplers.
                                                                 \<0\> = Termination.

                                                                 Software needs to clear the Termination bit in SATA mode
                                                                 (when GSER()_CFG[SATA] is set). */
		uint64_t p2_rx_chpd                  : 1;  /**< R/W - RX lane power down. */
#else
		uint64_t p2_rx_chpd                  : 1;
		uint64_t p2_rx_subblk_pd             : 5;
		uint64_t p2_rx_cdr_clr               : 1;
		uint64_t p2_rx_cdr_coast             : 1;
		uint64_t p2_rx_cdr_en                : 1;
		uint64_t p2_rx_dfe_en                : 1;
		uint64_t p2_rx_agc_en                : 1;
		uint64_t p2_rx_pcs_reset             : 1;
		uint64_t p2_rx_allow_pll_pd          : 1;
		uint64_t p2_rx_resetn                : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_lanex_pwr_ctrl_p2_s cn88xx; */
	/* struct bdk_gserx_lanex_pwr_ctrl_p2_s cn88xxp1; */
} bdk_gserx_lanex_pwr_ctrl_p2_t;

static inline uint64_t BDK_GSERX_LANEX_PWR_CTRL_P2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_PWR_CTRL_P2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904600B8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_PWR_CTRL_P2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_PWR_CTRL_P2(...) bdk_gserx_lanex_pwr_ctrl_p2_t
#define bustype_BDK_GSERX_LANEX_PWR_CTRL_P2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_PWR_CTRL_P2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_PWR_CTRL_P2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_PWR_CTRL_P2(...) "GSERX_LANEX_PWR_CTRL_P2"


/**
 * RSL - gser#_lane#_rx_aeq_out_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_aeq_out_0 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_aeq_out_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t sds_pcs_rx_aeq_out          : 10; /**< RO/H - \<9:5\>: DFE TAP5
                                                                 \<4:0\>: DFE TAP4 */
#else
		uint64_t sds_pcs_rx_aeq_out          : 10;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_aeq_out_0_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_aeq_out_0_s cn88xxp1; */
} bdk_gserx_lanex_rx_aeq_out_0_t;

static inline uint64_t BDK_GSERX_LANEX_RX_AEQ_OUT_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_AEQ_OUT_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440280ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_AEQ_OUT_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_AEQ_OUT_0(...) bdk_gserx_lanex_rx_aeq_out_0_t
#define bustype_BDK_GSERX_LANEX_RX_AEQ_OUT_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_AEQ_OUT_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_AEQ_OUT_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_AEQ_OUT_0(...) "GSERX_LANEX_RX_AEQ_OUT_0"


/**
 * RSL - gser#_lane#_rx_aeq_out_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_aeq_out_1 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_aeq_out_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t sds_pcs_rx_aeq_out          : 15; /**< RO/H - \<14:10\> = DFE TAP3.
                                                                 \<9:5\> = DFE TAP2.
                                                                 \<4:0\> = DFE TAP1. */
#else
		uint64_t sds_pcs_rx_aeq_out          : 15;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_aeq_out_1_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_aeq_out_1_s cn88xxp1; */
} bdk_gserx_lanex_rx_aeq_out_1_t;

static inline uint64_t BDK_GSERX_LANEX_RX_AEQ_OUT_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_AEQ_OUT_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440288ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_AEQ_OUT_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_AEQ_OUT_1(...) bdk_gserx_lanex_rx_aeq_out_1_t
#define bustype_BDK_GSERX_LANEX_RX_AEQ_OUT_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_AEQ_OUT_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_AEQ_OUT_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_AEQ_OUT_1(...) "GSERX_LANEX_RX_AEQ_OUT_1"


/**
 * RSL - gser#_lane#_rx_aeq_out_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_aeq_out_2 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_aeq_out_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t sds_pcs_rx_aeq_out          : 15; /**< RO/H - \<9:8\> = Reserved.
                                                                 \<7:4\> = Pre-CTLE gain.
                                                                 \<3:0\> = Post-CTLE gain. */
#else
		uint64_t sds_pcs_rx_aeq_out          : 15;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_aeq_out_2_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_aeq_out_2_s cn88xxp1; */
} bdk_gserx_lanex_rx_aeq_out_2_t;

static inline uint64_t BDK_GSERX_LANEX_RX_AEQ_OUT_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_AEQ_OUT_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440290ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_AEQ_OUT_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_AEQ_OUT_2(...) bdk_gserx_lanex_rx_aeq_out_2_t
#define bustype_BDK_GSERX_LANEX_RX_AEQ_OUT_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_AEQ_OUT_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_AEQ_OUT_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_AEQ_OUT_2(...) "GSERX_LANEX_RX_AEQ_OUT_2"


/**
 * RSL - gser#_lane#_rx_cdr_ctrl_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cdr_ctrl_1 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cdr_ctrl_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cfg_rx_cdr_ctrl_ovrrd_val   : 16; /**< R/W - Set CFG_RX_CDR_CTRL_OVRRD_EN in register
                                                                 GSER()_LANE()_RX_MISC_OVRRD to override pcs_sds_rx_cdr_ctrl.
                                                                 \<15:13\> = CDR frequency gain.
                                                                 \<12\>    = Frequency accumulator manual enable.
                                                                 \<11:5\>  = Frequency accumulator manual value.
                                                                 \<4\>     = CDR phase offset override enable.
                                                                 \<3:0\>   = CDR phase offset override, DLL IQ. */
#else
		uint64_t cfg_rx_cdr_ctrl_ovrrd_val   : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cdr_ctrl_1_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_cdr_ctrl_1_s cn88xxp1; */
} bdk_gserx_lanex_rx_cdr_ctrl_1_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CDR_CTRL_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CDR_CTRL_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440038ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CDR_CTRL_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CDR_CTRL_1(...) bdk_gserx_lanex_rx_cdr_ctrl_1_t
#define bustype_BDK_GSERX_LANEX_RX_CDR_CTRL_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CDR_CTRL_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CDR_CTRL_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CDR_CTRL_1(...) "GSERX_LANEX_RX_CDR_CTRL_1"


/**
 * RSL - gser#_lane#_rx_cdr_ctrl_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cdr_ctrl_2 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cdr_ctrl_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cfg_rx_cdr_ctrl_ovrrd_val   : 16; /**< R/W - Set CFG_RX_CDR_CTRL_OVRRD_EN in register
                                                                 GSER()_LANE()_RX_MISC_OVRRD to override pcs_sds_rx_cdr_ctrl.
                                                                 \<15\>   = Shadow PI phase enable.
                                                                 \<14:8\> = Shadow PI phase value.
                                                                 \<7\>    = CDR manual phase enable.
                                                                 \<6:0\>  = CDR manual phase value. */
#else
		uint64_t cfg_rx_cdr_ctrl_ovrrd_val   : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cdr_ctrl_2_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_cdr_ctrl_2_s cn88xxp1; */
} bdk_gserx_lanex_rx_cdr_ctrl_2_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CDR_CTRL_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CDR_CTRL_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440040ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CDR_CTRL_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CDR_CTRL_2(...) bdk_gserx_lanex_rx_cdr_ctrl_2_t
#define bustype_BDK_GSERX_LANEX_RX_CDR_CTRL_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CDR_CTRL_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CDR_CTRL_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CDR_CTRL_2(...) "GSERX_LANEX_RX_CDR_CTRL_2"


/**
 * RSL - gser#_lane#_rx_cdr_misc_ctrl_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cdr_misc_ctrl_0 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cdr_misc_ctrl_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t pcs_sds_rx_cdr_misc_ctrl    : 8;  /**< R/W - Per lane RX miscellaneous CDR control:
                                                                 \<7\> = RT-Eyemon counter enable, will start counting 5.4e9 bits.
                                                                 \<6\> = RT-Eyemon shadow PI control enable.
                                                                 \<5:4\> = RT-Eyemon error counter byte selection observable on
                                                                         SDS_OCS_RX_CDR_STATUS[14:7] in register GSER_LANE_RX_CDR_STATUS_1.
                                                                 \<3:0\> = LBW adjustment thresholds. */
#else
		uint64_t pcs_sds_rx_cdr_misc_ctrl    : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cdr_misc_ctrl_0_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_cdr_misc_ctrl_0_s cn88xxp1; */
} bdk_gserx_lanex_rx_cdr_misc_ctrl_0_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440208ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(...) bdk_gserx_lanex_rx_cdr_misc_ctrl_0_t
#define bustype_BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CDR_MISC_CTRL_0(...) "GSERX_LANEX_RX_CDR_MISC_CTRL_0"


/**
 * RSL - gser#_lane#_rx_cdr_status_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cdr_status_1 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cdr_status_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t sds_pcs_rx_cdr_status       : 15; /**< RO/H - Per lane RX CDR status:
                                                                 \<14:7\> = RT-Eyemon error counter.
                                                                 \<6:4\>  = LBW adjustment value.
                                                                 \<3:0\>  = LBW adjustment state. */
#else
		uint64_t sds_pcs_rx_cdr_status       : 15;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cdr_status_1_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_cdr_status_1_s cn88xxp1; */
} bdk_gserx_lanex_rx_cdr_status_1_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CDR_STATUS_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CDR_STATUS_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904402D0ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CDR_STATUS_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CDR_STATUS_1(...) bdk_gserx_lanex_rx_cdr_status_1_t
#define bustype_BDK_GSERX_LANEX_RX_CDR_STATUS_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CDR_STATUS_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CDR_STATUS_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CDR_STATUS_1(...) "GSERX_LANEX_RX_CDR_STATUS_1"


/**
 * RSL - gser#_lane#_rx_cdr_status_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cdr_status_2 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cdr_status_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t sds_pcs_rx_cdr_status       : 14; /**< RO/H - CDR status.
                                                                 \<13:7\> = CDR phase control output.
                                                                 \<6:0\> = CDR frequency accumulator output. */
#else
		uint64_t sds_pcs_rx_cdr_status       : 14;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cdr_status_2_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_cdr_status_2_s cn88xxp1; */
} bdk_gserx_lanex_rx_cdr_status_2_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CDR_STATUS_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CDR_STATUS_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904402D8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CDR_STATUS_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CDR_STATUS_2(...) bdk_gserx_lanex_rx_cdr_status_2_t
#define bustype_BDK_GSERX_LANEX_RX_CDR_STATUS_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CDR_STATUS_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CDR_STATUS_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CDR_STATUS_2(...) "GSERX_LANEX_RX_CDR_STATUS_2"


/**
 * RSL - gser#_lane#_rx_cfg_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cfg_0 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cfg_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rx_datarate_ovrrd_en        : 1;  /**< R/W - Override enable for RX Power State Machine data rate signal. */
		uint64_t pcs_sds_rx_tristate_enable  : 1;  /**< R/W - RX termination high-Z enable. */
		uint64_t rx_resetn_ovvrd_val         : 1;  /**< R/W - This value overrides the RX Power State machine rx_resetn control
                                                                 signal when GSER()_LANE()_PWR_CTRL[RX_RESETN_OVRRD_EN] is set. */
		uint64_t pcs_sds_rx_eyemon_en        : 1;  /**< R/W - RX eyemon test enable. */
		uint64_t pcs_sds_rx_pcm_ctrl         : 4;  /**< R/W - \<11\>: Reserved
                                                                 \<10-8\>:
                                                                   0x0 = 540mV.
                                                                   0x1 = 540mV + 20mV.
                                                                   0x2-0x3 = Reserved.
                                                                   0x4 = 100-620mV (default).
                                                                   0x5-0x7 = Reserved. */
		uint64_t rx_datarate_ovrrd_val       : 2;  /**< R/W - Specifies the data rate when RX_DATARATE_OVRRD_EN is asserted:
                                                                 0x0 = Full rate.
                                                                 0x1 = 1/2 data rate.
                                                                 0x2 = 1/4 data rate.
                                                                 0x3 = 1/8 data rate. */
		uint64_t cfg_rx_pol_invert           : 1;  /**< R/W - Invert the receive data.  Allies with GSER()_LANE()_MISC_CFG_0[USE_PMA_POLARITY]
                                                                 is deasserted. */
		uint64_t rx_subblk_pd_ovrrd_val      : 5;  /**< R/W - Not supported. */
#else
		uint64_t rx_subblk_pd_ovrrd_val      : 5;
		uint64_t cfg_rx_pol_invert           : 1;
		uint64_t rx_datarate_ovrrd_val       : 2;
		uint64_t pcs_sds_rx_pcm_ctrl         : 4;
		uint64_t pcs_sds_rx_eyemon_en        : 1;
		uint64_t rx_resetn_ovvrd_val         : 1;
		uint64_t pcs_sds_rx_tristate_enable  : 1;
		uint64_t rx_datarate_ovrrd_en        : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cfg_0_s  cn88xx; */
	/* struct bdk_gserx_lanex_rx_cfg_0_s  cn88xxp1; */
} bdk_gserx_lanex_rx_cfg_0_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CFG_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CFG_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440000ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CFG_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CFG_0(...) bdk_gserx_lanex_rx_cfg_0_t
#define bustype_BDK_GSERX_LANEX_RX_CFG_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CFG_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CFG_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CFG_0(...) "GSERX_LANEX_RX_CFG_0"


/**
 * RSL - gser#_lane#_rx_cfg_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cfg_1 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cfg_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rx_chpd_ovrrd_val           : 1;  /**< R/W - Not supported. */
		uint64_t pcs_sds_rx_os_men           : 1;  /**< R/W - RX Offset manual enable. */
		uint64_t eie_en_ovvrd_en             : 1;  /**< R/W - Override enable for Electrical-Idle-Exit circuit. */
		uint64_t eie_en_ovvrd_val            : 1;  /**< R/W - Override value for Electrical-Idle-Exit circuit. */
		uint64_t reserved_11_11              : 1;
		uint64_t rx_pcie_mode_ovvrd_en       : 1;  /**< R/W - Override enable for RX_PCIE_MODE_OVVRD_VAL. */
		uint64_t rx_pcie_mode_ovvrd_val      : 1;  /**< R/W - Override value for RX_PCIE_MODE_OVVRD_VAL;
                                                                 selects between RX terminations.
                                                                 0x0 = pcs_sds_rx_terminate_to_vdda.
                                                                 0x1 = VDDA. */
		uint64_t cfg_rx_dll_locken           : 1;  /**< R/W - Enable DLL lock when GSER()_LANE()_RX_MISC_OVRRD[CFG_RX_DLL_LOCKEN_OVRRD_EN] is asserted. */
		uint64_t pcs_sds_rx_cdr_ssc_mode     : 8;  /**< R/W - Per lane RX CDR SSC control:
                                                                 \<7:4\> = Resrted.
                                                                 \<3\> = Clean SSC error flag.
                                                                 \<2\> = Diable SSC filter.
                                                                 \<1\> = Enable SSC value usage.
                                                                 \<0\> = Reserved. */
#else
		uint64_t pcs_sds_rx_cdr_ssc_mode     : 8;
		uint64_t cfg_rx_dll_locken           : 1;
		uint64_t rx_pcie_mode_ovvrd_val      : 1;
		uint64_t rx_pcie_mode_ovvrd_en       : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t eie_en_ovvrd_val            : 1;
		uint64_t eie_en_ovvrd_en             : 1;
		uint64_t pcs_sds_rx_os_men           : 1;
		uint64_t rx_chpd_ovrrd_val           : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cfg_1_s  cn88xx; */
	/* struct bdk_gserx_lanex_rx_cfg_1_s  cn88xxp1; */
} bdk_gserx_lanex_rx_cfg_1_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CFG_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CFG_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440008ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CFG_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CFG_1(...) bdk_gserx_lanex_rx_cfg_1_t
#define bustype_BDK_GSERX_LANEX_RX_CFG_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CFG_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CFG_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CFG_1(...) "GSERX_LANEX_RX_CFG_1"


/**
 * RSL - gser#_lane#_rx_cfg_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cfg_2 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cfg_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t pcs_sds_rx_terminate_to_vdda : 1; /**< R/W - RX Termination control:
                                                                 0 = Floating.
                                                                 1 = Terminate to sds_vdda. */
		uint64_t pcs_sds_rx_sampler_boost    : 2;  /**< R/W - Controls amount of boost.
                                                                 Note that this control can negatively impact reliability. */
		uint64_t pcs_sds_rx_sampler_boost_en : 1;  /**< R/W - Faster sampler c2q.
                                                                 For diagnostic use only. */
		uint64_t reserved_10_10              : 1;
		uint64_t rx_sds_rx_agc_mval          : 10; /**< R/W - AGC manual value only used when GSERX_LANE()_RX_CFG_5[RX_AGC_MEN_OVVRD_VAL] is set.

                                                                 \<9:8\>: Reserved.

                                                                 \<7:4\>: Pre-CTL gain
                                                                 - 0 = -6dB
                                                                 - 1 = -5dB
                                                                 - 3 = +5dB.

                                                                 \<3:0\>: Post-CTL gain (steps of 0.0875)
                                                                 - 0x0 = lowest
                                                                 - 0xf = lowest * 2.3125. */
#else
		uint64_t rx_sds_rx_agc_mval          : 10;
		uint64_t reserved_10_10              : 1;
		uint64_t pcs_sds_rx_sampler_boost_en : 1;
		uint64_t pcs_sds_rx_sampler_boost    : 2;
		uint64_t pcs_sds_rx_terminate_to_vdda : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cfg_2_s  cn88xx; */
	/* struct bdk_gserx_lanex_rx_cfg_2_s  cn88xxp1; */
} bdk_gserx_lanex_rx_cfg_2_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CFG_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CFG_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440010ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CFG_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CFG_2(...) bdk_gserx_lanex_rx_cfg_2_t
#define bustype_BDK_GSERX_LANEX_RX_CFG_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CFG_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CFG_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CFG_2(...) "GSERX_LANEX_RX_CFG_2"


/**
 * RSL - gser#_lane#_rx_cfg_3
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cfg_3 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cfg_3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cfg_rx_errdet_ctrl          : 16; /**< R/W - RX Adaptive Equalizer Control.
                                                                 Value of pcs_sds_rx_err_det_ctrl when
                                                                 GSER()_LANE()_RX_MISC_OVRRD[CFG_RS_ERRDET_CTRL_OVRRD_EN}
                                                                 is set.

                                                                 \<15:13\>: Starting delta (6.7mV/step, 13.4mV + 6.7mV*N).

                                                                 \<12:10\>: Minimum delta to adapt to (6.7mV/step, 13.4mV + 6.7mV*N).

                                                                 \<9:7\>: Window mode (PM) delta (6.7mV/step, 13.4mV + 6.7mV*N).

                                                                 \<6\>: Enable DFE for edge samplers.

                                                                 \<5:4\>: Edge sampler DEF alpha:
                                                                 0x0 = 1/4.
                                                                 0x1 = 1/2.
                                                                 0x2 = 3/4.
                                                                 0x3 = 1.

                                                                 \<3:0\>: Q/QB error sampler 1 threshold, 6.7mV/step. */
#else
		uint64_t cfg_rx_errdet_ctrl          : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cfg_3_s  cn88xx; */
	/* struct bdk_gserx_lanex_rx_cfg_3_s  cn88xxp1; */
} bdk_gserx_lanex_rx_cfg_3_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CFG_3(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CFG_3(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440018ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CFG_3", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CFG_3(...) bdk_gserx_lanex_rx_cfg_3_t
#define bustype_BDK_GSERX_LANEX_RX_CFG_3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CFG_3(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CFG_3(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CFG_3(...) "GSERX_LANEX_RX_CFG_3"


/**
 * RSL - gser#_lane#_rx_cfg_4
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cfg_4 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cfg_4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cfg_rx_errdet_ctrl          : 16; /**< R/W - RX adaptive equalizer control.
                                                                 Value of pcs_sds_rx_err_det_ctrl when
                                                                 GSER()_LANE()_RX_MISC_OVRRD[CFG_RS_ERRDET_CTRL_OVRRD_EN] is set.

                                                                 \<15:14\>: Reserved

                                                                 \<13:8\>: Q/QB error sampler 0 threshold, 6.7mV/step, used for training/LMS.

                                                                 \<7\>: Enable Window mode, after training has finished.

                                                                 \<6:5\>: Control sds_pcs_rx_vma_status[15:8].

                                                                 0x0 = window counter[19:12] (FOM).
                                                                 0x1 = window ouunter[11:4].
                                                                 0x2 = CTLE pole, SDLL_IQ.
                                                                 0x3 = pre-CTLE gain, CTLE peak.

                                                                 \<4\>: Offset cancellation enable.

                                                                 \<3:0\>: Max CTLE peak setting during training when pcs_sds_rx_vma_ctl[7] is set in
                                                                 GSER()_LANE()_RX_VMA_CTRL. */
#else
		uint64_t cfg_rx_errdet_ctrl          : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cfg_4_s  cn88xx; */
	/* struct bdk_gserx_lanex_rx_cfg_4_s  cn88xxp1; */
} bdk_gserx_lanex_rx_cfg_4_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CFG_4(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CFG_4(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440020ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CFG_4", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CFG_4(...) bdk_gserx_lanex_rx_cfg_4_t
#define bustype_BDK_GSERX_LANEX_RX_CFG_4(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CFG_4(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CFG_4(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CFG_4(...) "GSERX_LANEX_RX_CFG_4"


/**
 * RSL - gser#_lane#_rx_cfg_5
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_cfg_5 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_cfg_5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t rx_agc_men_ovvrd_en         : 1;  /**< R/W - Override enable for AGC manual mode. */
		uint64_t rx_agc_men_ovvrd_val        : 1;  /**< R/W - Override value for AGC manual mode. */
		uint64_t rx_widthsel_ovvrd_en        : 1;  /**< R/W - Override enable for RX width select to the SerDes pcs_sds_rx_widthsel. */
		uint64_t rx_widthsel_ovvrd_val       : 2;  /**< R/W - Override value for RX width select to the SerDes pcs_sds_rx_widthsel.
                                                                 0x0 = 8-bit raw data.
                                                                 0x1 = 10-bit raw data.
                                                                 0x2 = 16-bit raw data.
                                                                 0x3 = 20-bit raw data. */
#else
		uint64_t rx_widthsel_ovvrd_val       : 2;
		uint64_t rx_widthsel_ovvrd_en        : 1;
		uint64_t rx_agc_men_ovvrd_val        : 1;
		uint64_t rx_agc_men_ovvrd_en         : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_cfg_5_s  cn88xx; */
	/* struct bdk_gserx_lanex_rx_cfg_5_s  cn88xxp1; */
} bdk_gserx_lanex_rx_cfg_5_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CFG_5(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CFG_5(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440028ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CFG_5", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CFG_5(...) bdk_gserx_lanex_rx_cfg_5_t
#define bustype_BDK_GSERX_LANEX_RX_CFG_5(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CFG_5(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CFG_5(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CFG_5(...) "GSERX_LANEX_RX_CFG_5"


/**
 * RSL - gser#_lane#_rx_ctle_ctrl
 *
 * These are the RAW PCS per-lane RX CTLE control registers.
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_ctle_ctrl {
	uint64_t u;
	struct bdk_gserx_lanex_rx_ctle_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t pcs_sds_rx_ctle_bias_ctrl   : 2;  /**< R/W - CTLE bias trim bits.
                                                                 0x0 = -10%.
                                                                 0x1 =  0%.
                                                                 0x2 = +5%.
                                                                 0x3 = +10%. */
		uint64_t pcs_sds_rx_ctle_zero        : 4;  /**< R/W - Equalizer peaking control. */
		uint64_t rx_ctle_pole_ovrrd_en       : 1;  /**< R/W - Equalizer pole adjustment override enable. */
		uint64_t rx_ctle_pole_ovrrd_val      : 4;  /**< R/W - Equalizer pole adjustment override value.
                                                                 RX pre-correlation sample counter control
                                                                 bit 3: Optimize CTLE during training.
                                                                 bit 2: Turn off DFE1 for edge samplers.
                                                                 bits 1:0:
                                                                 0x0 = ~ 5dB of peaking at 4.0 GHz.
                                                                 0x1 = ~10dB of peaking at 5.0 GHz.
                                                                 0x2 = ~15dB of peaking at 5.5 GHz.
                                                                 0x3 = ~20dB of peaking at 6.0 GHz. */
		uint64_t pcs_sds_rx_ctle_pole_max    : 2;  /**< R/W - Maximum pole value (for VMA adaption, not applicable in manual mode). */
		uint64_t pcs_sds_rx_ctle_pole_min    : 2;  /**< R/W - Minimum pole value (for VMA adaption, not applicable in manual mode). */
		uint64_t pcs_sds_rx_ctle_pole_step   : 1;  /**< R/W - Step pole value (for VMA adaption, not applicable in manual mode). */
#else
		uint64_t pcs_sds_rx_ctle_pole_step   : 1;
		uint64_t pcs_sds_rx_ctle_pole_min    : 2;
		uint64_t pcs_sds_rx_ctle_pole_max    : 2;
		uint64_t rx_ctle_pole_ovrrd_val      : 4;
		uint64_t rx_ctle_pole_ovrrd_en       : 1;
		uint64_t pcs_sds_rx_ctle_zero        : 4;
		uint64_t pcs_sds_rx_ctle_bias_ctrl   : 2;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_ctle_ctrl_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_ctle_ctrl_s cn88xxp1; */
} bdk_gserx_lanex_rx_ctle_ctrl_t;

static inline uint64_t BDK_GSERX_LANEX_RX_CTLE_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_CTLE_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440058ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_CTLE_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_CTLE_CTRL(...) bdk_gserx_lanex_rx_ctle_ctrl_t
#define bustype_BDK_GSERX_LANEX_RX_CTLE_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_CTLE_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_CTLE_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_CTLE_CTRL(...) "GSERX_LANEX_RX_CTLE_CTRL"


/**
 * RSL - gser#_lane#_rx_loop_ctrl
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_loop_ctrl {
	uint64_t u;
	struct bdk_gserx_lanex_rx_loop_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t fast_dll_lock               : 1;  /**< R/W/H - Assert to enable fast DLL lock (for simulation purposes only). */
		uint64_t fast_ofst_cncl              : 1;  /**< R/W/H - Assert to enable fast Offset cancellation (for simulation purposes only). */
		uint64_t cfg_rx_lctrl                : 10; /**< R/W - When GSER()_LANE()_PWR_CTRL[RX_LCTRL_OVRRD_EN] is set, loop control settings.
                                                                 0x0 = cdr_en_byp.
                                                                 0x1 = dfe_en_byp.
                                                                 0x2 = agc_en_byp.
                                                                 0x3 = ofst_cncl_en_byp.
                                                                 0x4 = CDR resetn.
                                                                 0x5 = CTLE resetn.
                                                                 0x6 = VMA resetn.
                                                                 0x7 = ofst_cncl_rstn_byp.
                                                                 0x8 = lctrl_men.
                                                                 0x9 - 0x3ff = Reserved. */
#else
		uint64_t cfg_rx_lctrl                : 10;
		uint64_t fast_ofst_cncl              : 1;
		uint64_t fast_dll_lock               : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_loop_ctrl_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_loop_ctrl_s cn88xxp1; */
} bdk_gserx_lanex_rx_loop_ctrl_t;

static inline uint64_t BDK_GSERX_LANEX_RX_LOOP_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_LOOP_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440048ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_LOOP_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_LOOP_CTRL(...) bdk_gserx_lanex_rx_loop_ctrl_t
#define bustype_BDK_GSERX_LANEX_RX_LOOP_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_LOOP_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_LOOP_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_LOOP_CTRL(...) "GSERX_LANEX_RX_LOOP_CTRL"


/**
 * RSL - gser#_lane#_rx_misc_ovrrd
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_misc_ovrrd {
	uint64_t u;
	struct bdk_gserx_lanex_rx_misc_ovrrd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t cfg_rx_oob_clk_en_ovrrd_val : 1;  /**< R/W - Override value for RX OOB Clock Enable. */
		uint64_t cfg_rx_oob_clk_en_ovrrd_en  : 1;  /**< R/W - Override enable for RX OOB Clock Enable. */
		uint64_t cfg_rx_eie_det_ovrrd_val    : 1;  /**< R/W - Override value for RX Electrical-Idle-Exit
                                                                 Detect Enable. */
		uint64_t cfg_rx_eie_det_ovrrd_en     : 1;  /**< R/W - Override enable for RX Electrical-Idle-Exit
                                                                 Detect Enable. */
		uint64_t cfg_rx_cdr_ctrl_ovvrd_en    : 1;  /**< R/W - Not supported. */
		uint64_t cfg_rx_eq_eval_ovrrd_val    : 1;  /**< R/W - Training mode control in override mode. */
		uint64_t cfg_rx_eq_eval_ovrrd_en     : 1;  /**< R/W - Override enable for RX-EQ Eval
                                                                 When asserted, training mode is controlled by
                                                                 CFG_RX_EQ_EVAL_OVRRD_VAL. */
		uint64_t reserved_6_6                : 1;
		uint64_t cfg_rx_dll_locken_ovvrd_en  : 1;  /**< R/W - When asserted, override DLL lock enable
                                                                 signal from the RX Power State machine with
                                                                 CFG_RX_DLL_LOCKEN in register
                                                                 GSER()_LANE()_RX_CFG_1. */
		uint64_t cfg_rx_errdet_ctrl_ovvrd_en : 1;  /**< R/W - When asserted, pcs_sds_rx_err_det_ctrl is set
                                                                 to cfg_rx_errdet_ctrl in registers
                                                                 GSER()_LANE()_RX_CFG_3 and GSER()_LANE()_RX_CFG_4. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t cfg_rx_errdet_ctrl_ovvrd_en : 1;
		uint64_t cfg_rx_dll_locken_ovvrd_en  : 1;
		uint64_t reserved_6_6                : 1;
		uint64_t cfg_rx_eq_eval_ovrrd_en     : 1;
		uint64_t cfg_rx_eq_eval_ovrrd_val    : 1;
		uint64_t cfg_rx_cdr_ctrl_ovvrd_en    : 1;
		uint64_t cfg_rx_eie_det_ovrrd_en     : 1;
		uint64_t cfg_rx_eie_det_ovrrd_val    : 1;
		uint64_t cfg_rx_oob_clk_en_ovrrd_en  : 1;
		uint64_t cfg_rx_oob_clk_en_ovrrd_val : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_misc_ovrrd_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_misc_ovrrd_s cn88xxp1; */
} bdk_gserx_lanex_rx_misc_ovrrd_t;

static inline uint64_t BDK_GSERX_LANEX_RX_MISC_OVRRD(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_MISC_OVRRD(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440258ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_MISC_OVRRD", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_MISC_OVRRD(...) bdk_gserx_lanex_rx_misc_ovrrd_t
#define bustype_BDK_GSERX_LANEX_RX_MISC_OVRRD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_MISC_OVRRD(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_MISC_OVRRD(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_MISC_OVRRD(...) "GSERX_LANEX_RX_MISC_OVRRD"


/**
 * RSL - gser#_lane#_rx_precorr_ctrl
 *
 * These are the RAW PCS per-lane RX precorrelation control registers. These registers are for
 * diagnostic use only.
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_precorr_ctrl {
	uint64_t u;
	struct bdk_gserx_lanex_rx_precorr_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t rx_precorr_disable          : 1;  /**< R/W - Disable RX precorrelation calculation. */
		uint64_t rx_precorr_en_ovrrd_en      : 1;  /**< R/W - Override enable for RX precorrelation calculation enable. */
		uint64_t rx_precorr_en_ovrrd_val     : 1;  /**< R/W - Override value for RX precorrelation calculation enable. */
		uint64_t pcs_sds_rx_precorr_scnt_ctrl : 2; /**< R/W - RX precorrelation sample counter control.
                                                                 0x0 = Load max sample counter with 0x1FF.
                                                                 0x1 = Load max sample counter with 0x3FF.
                                                                 0x2 = Load max sample counter with 0x7FF.
                                                                 0x3 = Load max sample counter with 0xFFF. */
#else
		uint64_t pcs_sds_rx_precorr_scnt_ctrl : 2;
		uint64_t rx_precorr_en_ovrrd_val     : 1;
		uint64_t rx_precorr_en_ovrrd_en      : 1;
		uint64_t rx_precorr_disable          : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_precorr_ctrl_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_precorr_ctrl_s cn88xxp1; */
} bdk_gserx_lanex_rx_precorr_ctrl_t;

static inline uint64_t BDK_GSERX_LANEX_RX_PRECORR_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_PRECORR_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440060ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_PRECORR_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_PRECORR_CTRL(...) bdk_gserx_lanex_rx_precorr_ctrl_t
#define bustype_BDK_GSERX_LANEX_RX_PRECORR_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_PRECORR_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_PRECORR_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_PRECORR_CTRL(...) "GSERX_LANEX_RX_PRECORR_CTRL"


/**
 * RSL - gser#_lane#_rx_precorr_val
 *
 * These are the RAW PCS per-lane RX precorrelation control registers. These registers are for
 * diagnostic use only.
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_precorr_val {
	uint64_t u;
	struct bdk_gserx_lanex_rx_precorr_val_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t sds_pcs_rx_precorr_vld      : 1;  /**< RO/H - RX pre-correlation count is valid. */
		uint64_t sds_pcs_rx_precorr_cnt      : 12; /**< RO/H - RX pre-correlation count. */
#else
		uint64_t sds_pcs_rx_precorr_cnt      : 12;
		uint64_t sds_pcs_rx_precorr_vld      : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_precorr_val_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_precorr_val_s cn88xxp1; */
} bdk_gserx_lanex_rx_precorr_val_t;

static inline uint64_t BDK_GSERX_LANEX_RX_PRECORR_VAL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_PRECORR_VAL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440078ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_PRECORR_VAL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_PRECORR_VAL(...) bdk_gserx_lanex_rx_precorr_val_t
#define bustype_BDK_GSERX_LANEX_RX_PRECORR_VAL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_PRECORR_VAL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_PRECORR_VAL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_PRECORR_VAL(...) "GSERX_LANEX_RX_PRECORR_VAL"


/**
 * RSL - gser#_lane#_rx_valbbd_ctrl_0
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_valbbd_ctrl_0 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_valbbd_ctrl_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t agc_gain                    : 2;  /**< R/W - AGC gain. */
		uint64_t dfe_gain                    : 2;  /**< R/W - DFE gain. */
		uint64_t dfe_c5_mval                 : 4;  /**< R/W - DFE Tap5 manual value when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c5_msgn                 : 1;  /**< R/W - DFE Tap5 manual sign when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c4_mval                 : 4;  /**< R/W - DFE Tap4 manual value when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c4_msgn                 : 1;  /**< R/W - DFE Tap4 manual sign when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
#else
		uint64_t dfe_c4_msgn                 : 1;
		uint64_t dfe_c4_mval                 : 4;
		uint64_t dfe_c5_msgn                 : 1;
		uint64_t dfe_c5_mval                 : 4;
		uint64_t dfe_gain                    : 2;
		uint64_t agc_gain                    : 2;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_valbbd_ctrl_0_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_valbbd_ctrl_0_s cn88xxp1; */
} bdk_gserx_lanex_rx_valbbd_ctrl_0_t;

static inline uint64_t BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440240ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_VALBBD_CTRL_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(...) bdk_gserx_lanex_rx_valbbd_ctrl_0_t
#define bustype_BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(...) "GSERX_LANEX_RX_VALBBD_CTRL_0"


/**
 * RSL - gser#_lane#_rx_valbbd_ctrl_1
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_valbbd_ctrl_1 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_valbbd_ctrl_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t dfe_c3_mval                 : 4;  /**< R/W - DFE Tap3 manual value when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c3_msgn                 : 1;  /**< R/W - DFE Tap3 manual sign when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c2_mval                 : 4;  /**< R/W - DFE Tap2 manual value when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c2_msgn                 : 1;  /**< R/W - DFE Tap2 manual sign when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
		uint64_t dfe_c1_mval                 : 4;  /**< R/W - DFE Tap1 manual value when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set.

                                                                 Recommended settings: For the following modes:
                                                                 5G_REFCLK100, 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that DFE_C1_MVAL
                                                                 be set to zero after setting GSER()_LANE_P()_MODE_1[VMA_MM] and also after
                                                                 updating the GSER()_LANE()_RX_VALBBD_CTRL_2 register. In all other modes this
                                                                 register can be ignored. */
		uint64_t dfe_c1_msgn                 : 1;  /**< R/W - DFE Tap1 manual sign when GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_OVRD_EN] and
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_2[DFE_C5_OVRD_VAL] are both set. */
#else
		uint64_t dfe_c1_msgn                 : 1;
		uint64_t dfe_c1_mval                 : 4;
		uint64_t dfe_c2_msgn                 : 1;
		uint64_t dfe_c2_mval                 : 4;
		uint64_t dfe_c3_msgn                 : 1;
		uint64_t dfe_c3_mval                 : 4;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_valbbd_ctrl_1_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_valbbd_ctrl_1_s cn88xxp1; */
} bdk_gserx_lanex_rx_valbbd_ctrl_1_t;

static inline uint64_t BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440248ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_VALBBD_CTRL_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(...) bdk_gserx_lanex_rx_valbbd_ctrl_1_t
#define bustype_BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_VALBBD_CTRL_1(...) "GSERX_LANEX_RX_VALBBD_CTRL_1"


/**
 * RSL - gser#_lane#_rx_valbbd_ctrl_2
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_valbbd_ctrl_2 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_valbbd_ctrl_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t dfe_ovrd_en                 : 1;  /**< R/W - Override enable for DFE tap controls. When asserted, the register bits in
                                                                 GSER()_LANE()_RX_VALBBD_CTRL_0 and GSER()_LANE()_RX_VALBBD_CTRL_1 are
                                                                 used for controlling the DFE tap manual mode, instead the manual mode signal indexed by
                                                                 GSER()_LANE_MODE[LMODE]. Recommended settings: For the following modes: 5G_REFCLK100,
                                                                 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that DFE tap controls be put in
                                                                 manual mode by setting this bit. In all other modes this register can be ignored. */
		uint64_t dfe_c5_ovrd_val             : 1;  /**< R/W - Override value for DFE Tap5 manual enable. Recommended settings: For the following modes;
                                                                 5G_REFCLK100, 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that the DFE Tap5
                                                                 manual enable be set after setting GSER()_LANE_P()_MODE_1[VMA_MM]. In all
                                                                 other modes this register can be ignored. */
		uint64_t dfe_c4_ovrd_val             : 1;  /**< R/W - Override value for DFE Tap4 manual enable. Recommended settings: For the following modes:
                                                                 5G_REFCLK100, 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that the DFE Tap4
                                                                 manual enable be set after setting GSER()_LANE_P()_MODE_1[VMA_MM]. In all
                                                                 other modes this register can be ignored. */
		uint64_t dfe_c3_ovrd_val             : 1;  /**< R/W - Override value for DFE Tap3 manual enable. Recommended settings: For the following modes;
                                                                 5G_REFCLK100, 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that the DFE Tap3
                                                                 manual enable be set after setting GSER()_LANE_P()_MODE_1[VMA_MM]. In all
                                                                 other modes this register can be ignored. */
		uint64_t dfe_c2_ovrd_val             : 1;  /**< R/W - Override value for DFE Tap2 manual enable. Recommended settings: For the following modes;
                                                                 5G_REFCLK100, 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that the DFE Tap2
                                                                 manual enable be set after setting GSER()_LANE_P()_MODE_1[VMA_MM]. In all
                                                                 other modes this register can be ignored. */
		uint64_t dfe_c1_ovrd_val             : 1;  /**< R/W - Override value for DFE Tap1 manual enable. Recommended settings: For the following modes;
                                                                 5G_REFCLK100, 5G_REFCLK15625_QSGMII, and 5G_REFCLK125, it is recommended that the DFE Tap1
                                                                 manual enable be set after setting GSER()_LANE_P()_MODE_1[VMA_MM]. In all
                                                                 other modes this register can be ignored. */
#else
		uint64_t dfe_c1_ovrd_val             : 1;
		uint64_t dfe_c2_ovrd_val             : 1;
		uint64_t dfe_c3_ovrd_val             : 1;
		uint64_t dfe_c4_ovrd_val             : 1;
		uint64_t dfe_c5_ovrd_val             : 1;
		uint64_t dfe_ovrd_en                 : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_valbbd_ctrl_2_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_valbbd_ctrl_2_s cn88xxp1; */
} bdk_gserx_lanex_rx_valbbd_ctrl_2_t;

static inline uint64_t BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440250ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_VALBBD_CTRL_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(...) bdk_gserx_lanex_rx_valbbd_ctrl_2_t
#define bustype_BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_VALBBD_CTRL_2(...) "GSERX_LANEX_RX_VALBBD_CTRL_2"


/**
 * RSL - gser#_lane#_rx_vma_ctrl
 *
 * These are the RAW PCS per-lane RX VMA control registers. These registers are for diagnostic
 * use only.
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_vma_ctrl {
	uint64_t u;
	struct bdk_gserx_lanex_rx_vma_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t vma_fine_cfg_sel_ovrrd_en   : 1;  /**< R/W - Enable override of VMA fine configuration selection. */
		uint64_t vma_fine_cfg_sel_ovrrd_val  : 1;  /**< R/W - Override value of VMA fine configuration selection.
                                                                 0: Coarse mode.
                                                                 1: Fine mode. */
		uint64_t rx_fom_div_delta            : 1;  /**< R/W - TX figure of merit delta division-mode enable. */
		uint64_t rx_vna_ctrl_18_16           : 3;  /**< R/W - RX VMA loop control. */
		uint64_t rx_vna_ctrl_9_0             : 10; /**< R/W - RX VMA loop control.
                                                                 \<9:8\> = Parameter settling wait time.
                                                                 \<7\> = Limit CTLE peak to max value.
                                                                 \<6\> = Long reach enabled.
                                                                 \<5\> = Short reach enabled.
                                                                 \<4\> = Training done override enable.
                                                                 \<3\> = Training done override value.
                                                                 \<2:0\> = VMA clock modulation. */
#else
		uint64_t rx_vna_ctrl_9_0             : 10;
		uint64_t rx_vna_ctrl_18_16           : 3;
		uint64_t rx_fom_div_delta            : 1;
		uint64_t vma_fine_cfg_sel_ovrrd_val  : 1;
		uint64_t vma_fine_cfg_sel_ovrrd_en   : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_vma_ctrl_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_vma_ctrl_s cn88xxp1; */
} bdk_gserx_lanex_rx_vma_ctrl_t;

static inline uint64_t BDK_GSERX_LANEX_RX_VMA_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_VMA_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440200ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_VMA_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_VMA_CTRL(...) bdk_gserx_lanex_rx_vma_ctrl_t
#define bustype_BDK_GSERX_LANEX_RX_VMA_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_VMA_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_VMA_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_VMA_CTRL(...) "GSERX_LANEX_RX_VMA_CTRL"


/**
 * RSL - gser#_lane#_rx_vma_status_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_vma_status_0 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_vma_status_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t sds_pcs_rx_vma_status       : 8;  /**< RO/H - \<8\> = DFE Powerdown.
                                                                 \<7\> = Reserved.
                                                                 \<6:2\> = CTLE Peak.
                                                                 \<1:0\> = CTLE Pole. */
#else
		uint64_t sds_pcs_rx_vma_status       : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_vma_status_0_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_vma_status_0_s cn88xxp1; */
} bdk_gserx_lanex_rx_vma_status_0_t;

static inline uint64_t BDK_GSERX_LANEX_RX_VMA_STATUS_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_VMA_STATUS_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904402B8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_VMA_STATUS_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_VMA_STATUS_0(...) bdk_gserx_lanex_rx_vma_status_0_t
#define bustype_BDK_GSERX_LANEX_RX_VMA_STATUS_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_VMA_STATUS_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_VMA_STATUS_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_VMA_STATUS_0(...) "GSERX_LANEX_RX_VMA_STATUS_0"


/**
 * RSL - gser#_lane#_rx_vma_status_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_rx_vma_status_1 {
	uint64_t u;
	struct bdk_gserx_lanex_rx_vma_status_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t sds_pcs_rx_vma_status       : 16; /**< RO/H - \<15:8\>: Output is controlled by GSER()_LANE()_RX_CFG_3[CFG_RX_ERRDET_CTRL[6:5]
                                                                 0x0 = Pre-CTL gain, CTLE Peak.
                                                                 0x1 = CTL pole, SDLL_IQ.
                                                                 0x2 = Window counter[11:3].
                                                                 0x3 = Window counter[19:12] (VMA RAW FOM).

                                                                 \<7\>: Training done

                                                                 \<6\>: Internal state machine training done

                                                                 \<5:3\>: Internal state machine Delta

                                                                 \<2:0\>: CDR Phase Offset, DLL IQ Training value. */
#else
		uint64_t sds_pcs_rx_vma_status       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_rx_vma_status_1_s cn88xx; */
	/* struct bdk_gserx_lanex_rx_vma_status_1_s cn88xxp1; */
} bdk_gserx_lanex_rx_vma_status_1_t;

static inline uint64_t BDK_GSERX_LANEX_RX_VMA_STATUS_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_RX_VMA_STATUS_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904402C0ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_RX_VMA_STATUS_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_RX_VMA_STATUS_1(...) bdk_gserx_lanex_rx_vma_status_1_t
#define bustype_BDK_GSERX_LANEX_RX_VMA_STATUS_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_RX_VMA_STATUS_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_RX_VMA_STATUS_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_RX_VMA_STATUS_1(...) "GSERX_LANEX_RX_VMA_STATUS_1"


/**
 * RSL - gser#_lane#_sds_pin_mon_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_sds_pin_mon_0 {
	uint64_t u;
	struct bdk_gserx_lanex_sds_pin_mon_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t pcs_sds_tx_widthsel         : 2;  /**< RO/H - TX parallel interface width settings (RAW PCS to
                                                                 SerDes TX).
                                                                 0x0 = 8-bit raw data (not supported).
                                                                 0x1 = 10-bit raw data (not supported).
                                                                 0x2 = 16-bit raw data (not supported).
                                                                 0x3 = 20-bit raw data. */
		uint64_t pcs_sds_rx_pcie_mode        : 1;  /**< RO/H - Selects between RX terminations:
                                                                 0x0 = pcs_sds_rx_terminate_to_vdda.
                                                                 0x1 = VSS. */
		uint64_t reserved_5_6                : 2;
		uint64_t pcs_sds_rx_misc_ctrl_5      : 1;  /**< RO/H - Not Used. */
		uint64_t tx_detrx_state              : 2;  /**< RO/H - RX detection state:
                                                                 0x0 = IDLE.
                                                                 0x1 = Charge Up.
                                                                 0x2 = Detection.
                                                                 0x3 = Restore common mode. */
		uint64_t pcs_sds_tx_rx_detect_dis    : 1;  /**< RO/H - TX detect RX, mode disable. */
		uint64_t pcs_sds_tx_detect_pulsen    : 1;  /**< RO/H - TX detect RX, pulse enable. */
#else
		uint64_t pcs_sds_tx_detect_pulsen    : 1;
		uint64_t pcs_sds_tx_rx_detect_dis    : 1;
		uint64_t tx_detrx_state              : 2;
		uint64_t pcs_sds_rx_misc_ctrl_5      : 1;
		uint64_t reserved_5_6                : 2;
		uint64_t pcs_sds_rx_pcie_mode        : 1;
		uint64_t pcs_sds_tx_widthsel         : 2;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lanex_sds_pin_mon_0_s cn88xx; */
	/* struct bdk_gserx_lanex_sds_pin_mon_0_s cn88xxp1; */
} bdk_gserx_lanex_sds_pin_mon_0_t;

static inline uint64_t BDK_GSERX_LANEX_SDS_PIN_MON_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_SDS_PIN_MON_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440130ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_SDS_PIN_MON_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_SDS_PIN_MON_0(...) bdk_gserx_lanex_sds_pin_mon_0_t
#define bustype_BDK_GSERX_LANEX_SDS_PIN_MON_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_SDS_PIN_MON_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_SDS_PIN_MON_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_SDS_PIN_MON_0(...) "GSERX_LANEX_SDS_PIN_MON_0"


/**
 * RSL - gser#_lane#_sds_pin_mon_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_sds_pin_mon_1 {
	uint64_t u;
	struct bdk_gserx_lanex_sds_pin_mon_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t pcs_sds_rx_chpd             : 1;  /**< RO/H - RX channel powerdown signal. */
		uint64_t pcs_sds_rx_eie_en           : 1;  /**< RO/H - Enable for electrical idle detection circuit
                                                                 in SerDes RX. */
		uint64_t reserved_13_13              : 1;
		uint64_t pcs_sds_ln_loopback_mode    : 1;  /**< RO/H - TX to RX on chip loopback control signal. */
		uint64_t pcs_sds_tx_chpd             : 1;  /**< RO/H - TX channel powerdown signal. */
		uint64_t pcs_sds_rx_widthsel         : 2;  /**< RO/H - Width select.
                                                                 0x0 = 8-bit raw data.
                                                                 0x1 = 10-bit raw data.
                                                                 0x2 = 16-bit raw data.
                                                                 0x3 = 20-bit raw data. */
		uint64_t reserved_8_8                : 1;
		uint64_t pcs_sds_tx_resetn           : 1;  /**< RO/H - TX reset, active low (RAW PCS output to lane TX). */
		uint64_t pcs_sds_tx_tristate_en      : 1;  /**< RO/H - TX driver tristate enable (RAW PCS output to lane TX). */
		uint64_t pcs_sds_tx_swing            : 5;  /**< RO/H - TX swing (RAW PCS output to lane TX). */
		uint64_t pcs_sds_tx_elec_idle        : 1;  /**< RO/H - TX electrical idle control (RAW PCS output to lane TX). */
#else
		uint64_t pcs_sds_tx_elec_idle        : 1;
		uint64_t pcs_sds_tx_swing            : 5;
		uint64_t pcs_sds_tx_tristate_en      : 1;
		uint64_t pcs_sds_tx_resetn           : 1;
		uint64_t reserved_8_8                : 1;
		uint64_t pcs_sds_rx_widthsel         : 2;
		uint64_t pcs_sds_tx_chpd             : 1;
		uint64_t pcs_sds_ln_loopback_mode    : 1;
		uint64_t reserved_13_13              : 1;
		uint64_t pcs_sds_rx_eie_en           : 1;
		uint64_t pcs_sds_rx_chpd             : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_sds_pin_mon_1_s cn88xx; */
	/* struct bdk_gserx_lanex_sds_pin_mon_1_s cn88xxp1; */
} bdk_gserx_lanex_sds_pin_mon_1_t;

static inline uint64_t BDK_GSERX_LANEX_SDS_PIN_MON_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_SDS_PIN_MON_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440138ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_SDS_PIN_MON_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_SDS_PIN_MON_1(...) bdk_gserx_lanex_sds_pin_mon_1_t
#define bustype_BDK_GSERX_LANEX_SDS_PIN_MON_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_SDS_PIN_MON_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_SDS_PIN_MON_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_SDS_PIN_MON_1(...) "GSERX_LANEX_SDS_PIN_MON_1"


/**
 * RSL - gser#_lane#_sds_pin_mon_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lanex_sds_pin_mon_2 {
	uint64_t u;
	struct bdk_gserx_lanex_sds_pin_mon_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t pcs_sds_tx_vboost_en        : 1;  /**< RO/H - TX boost enable. */
		uint64_t pcs_sds_tx_turbos_en        : 1;  /**< RO/H - TX turbo mode enable signal, increases swing of TX
                                                                 through current mode. */
		uint64_t pcs_sds_premptap            : 9;  /**< RO/H - Pre-emphasis control.
                                                                 \<8:4\> = Post-cursor.
                                                                 \<3:0\> = Pre-cursor. */
#else
		uint64_t pcs_sds_premptap            : 9;
		uint64_t pcs_sds_tx_turbos_en        : 1;
		uint64_t pcs_sds_tx_vboost_en        : 1;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_gserx_lanex_sds_pin_mon_2_s cn88xx; */
	/* struct bdk_gserx_lanex_sds_pin_mon_2_s cn88xxp1; */
} bdk_gserx_lanex_sds_pin_mon_2_t;

static inline uint64_t BDK_GSERX_LANEX_SDS_PIN_MON_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_SDS_PIN_MON_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E090440140ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_SDS_PIN_MON_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_SDS_PIN_MON_2(...) bdk_gserx_lanex_sds_pin_mon_2_t
#define bustype_BDK_GSERX_LANEX_SDS_PIN_MON_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_SDS_PIN_MON_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_SDS_PIN_MON_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_SDS_PIN_MON_2(...) "GSERX_LANEX_SDS_PIN_MON_2"


/**
 * RSL - gser#_lane#_tx_cfg_0
 *
 * These registers are for diagnostic use only. These registers are reset by hardware only during
 * chip cold reset. The values of the CSR fields in these registers do not change during chip
 * warm or soft resets.
 */
typedef union bdk_gserx_lanex_tx_cfg_0 {
	uint64_t u;
	struct bdk_gserx_lanex_tx_cfg_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t tx_tristate_en_ovrd_val     : 1;  /**< R/W - TX termination high-Z enable. */
		uint64_t tx_chpd_ovrd_val            : 1;  /**< R/W - TX lane power down. */
		uint64_t reserved_10_13              : 4;
		uint64_t tx_resetn_ovrd_val          : 1;  /**< R/W - TX P2S rest. */
		uint64_t tx_cm_mode                  : 1;  /**< R/W/H - Assert to enable fast Common-Mode charge up. For simulation purposes only. */
		uint64_t cfg_tx_swing                : 5;  /**< R/W - TX output swing control.
                                                                 Default swing encoding when GSER()_LANE()_TX_CFG_1[TX_SWING_OVRRD_EN] is
                                                                 asserted. */
		uint64_t fast_rdet_mode              : 1;  /**< R/W/H - Assert to enable fast RX Detection. For simulation purposes only. */
		uint64_t fast_tristate_mode          : 1;  /**< R/W/H - Assert to enable fast Tristate power up. For simulation purposes only. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t fast_tristate_mode          : 1;
		uint64_t fast_rdet_mode              : 1;
		uint64_t cfg_tx_swing                : 5;
		uint64_t tx_cm_mode                  : 1;
		uint64_t tx_resetn_ovrd_val          : 1;
		uint64_t reserved_10_13              : 4;
		uint64_t tx_chpd_ovrd_val            : 1;
		uint64_t tx_tristate_en_ovrd_val     : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_tx_cfg_0_s  cn88xx; */
	/* struct bdk_gserx_lanex_tx_cfg_0_s  cn88xxp1; */
} bdk_gserx_lanex_tx_cfg_0_t;

static inline uint64_t BDK_GSERX_LANEX_TX_CFG_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_TX_CFG_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400A8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_TX_CFG_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_TX_CFG_0(...) bdk_gserx_lanex_tx_cfg_0_t
#define bustype_BDK_GSERX_LANEX_TX_CFG_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_TX_CFG_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_TX_CFG_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_TX_CFG_0(...) "GSERX_LANEX_TX_CFG_0"


/**
 * RSL - gser#_lane#_tx_cfg_1
 *
 * These registers are for diagnostic use only. These registers are reset by hardware only during
 * chip cold reset. The values of the CSR fields in these registers do not change during chip
 * warm or soft resets.
 */
typedef union bdk_gserx_lanex_tx_cfg_1 {
	uint64_t u;
	struct bdk_gserx_lanex_tx_cfg_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t tx_widthsel_ovrd_en         : 1;  /**< R/W - Override enable for pcs_sds_txX_widthsel, TX parallel interface width setting. */
		uint64_t tx_widthsel_ovrd_val        : 2;  /**< R/W - Override value for pcs_sds_widthsel, TX parallel interface width setting.
                                                                 0x0 = 8-bit (not supported).
                                                                 0x1 = 10-bit (not supported).
                                                                 0x2 = 16-bit (not supported).
                                                                 0x3 = 20-bit (not supported). */
		uint64_t tx_vboost_en_ovrrd_en       : 1;  /**< R/W - Override enable for pcs_sds_txX_vboost_en, TX  vboost mode enable. */
		uint64_t tx_turbo_en_ovrrd_en        : 1;  /**< R/W - Override enable for pcs_sds_txX_turbo_en, Turbo mode enable. */
		uint64_t tx_swing_ovrd_en            : 1;  /**< R/W - Override enable for pcs_sds_txX_swing, TX swing. */
		uint64_t tx_premptap_ovrd_val        : 1;  /**< R/W - Override enable for pcs_sds_txX_preemptap, preemphasis control. */
		uint64_t tx_elec_idle_ovrrd_en       : 1;  /**< R/W - Override enable for pcs_sds_txX_elec_idle, TX electrical idle. */
		uint64_t smpl_rate_ovrd_en           : 1;  /**< R/W - Override enable for TX Power state machine sample rate. When asserted, the TX sample is
                                                                 specified from SMPL_RATE_OVRD_VAL and the TX Power state machine control signal is
                                                                 ignored. */
		uint64_t smpl_rate_ovrd_val          : 3;  /**< R/W - Specifies the sample rate (strobe assertion) relative to mac_pcs_txX_clk when
                                                                 SMPL_RATE_OVRD_EN is asserted.
                                                                 0x0 = full rate.
                                                                 0x1 = 1/2 data rate.
                                                                 0x2 = 1/4 data rate.
                                                                 0x3 = 1/8 data rate.
                                                                 0x4 = 1/18 data rate.
                                                                 0x5-7 = Reserved. */
		uint64_t tx_datarate_ovrd_en         : 1;  /**< R/W - Override enable for RX Power state machine data rate signal. When set, rx_datarate is
                                                                 specified from TX_DATA_RATE_OVRD_VAL and the RX Power State Machine control signal is
                                                                 ignored. */
		uint64_t tx_datarate_ovrd_val        : 2;  /**< R/W - Specifies the TX data rate when TX_DATARATE_OVRD_EN is asserted.
                                                                 0x0 = full rate.
                                                                 0x1 = 1/2 data rate.
                                                                 0x2 = 1/4 data rate.
                                                                 0x3 = 1/8 data rate. */
#else
		uint64_t tx_datarate_ovrd_val        : 2;
		uint64_t tx_datarate_ovrd_en         : 1;
		uint64_t smpl_rate_ovrd_val          : 3;
		uint64_t smpl_rate_ovrd_en           : 1;
		uint64_t tx_elec_idle_ovrrd_en       : 1;
		uint64_t tx_premptap_ovrd_val        : 1;
		uint64_t tx_swing_ovrd_en            : 1;
		uint64_t tx_turbo_en_ovrrd_en        : 1;
		uint64_t tx_vboost_en_ovrrd_en       : 1;
		uint64_t tx_widthsel_ovrd_val        : 2;
		uint64_t tx_widthsel_ovrd_en         : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_tx_cfg_1_s  cn88xx; */
	/* struct bdk_gserx_lanex_tx_cfg_1_s  cn88xxp1; */
} bdk_gserx_lanex_tx_cfg_1_t;

static inline uint64_t BDK_GSERX_LANEX_TX_CFG_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_TX_CFG_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400B0ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_TX_CFG_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_TX_CFG_1(...) bdk_gserx_lanex_tx_cfg_1_t
#define bustype_BDK_GSERX_LANEX_TX_CFG_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_TX_CFG_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_TX_CFG_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_TX_CFG_1(...) "GSERX_LANEX_TX_CFG_1"


/**
 * RSL - gser#_lane#_tx_cfg_2
 *
 * These registers are for diagnostic use only. These registers are reset by hardware only during
 * chip cold reset. The values of the CSR fields in these registers do not change during chip
 * warm or soft resets.
 */
typedef union bdk_gserx_lanex_tx_cfg_2 {
	uint64_t u;
	struct bdk_gserx_lanex_tx_cfg_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t pcs_sds_tx_dcc_en           : 1;  /**< R/W - DCC Enable. */
		uint64_t reserved_3_14               : 12;
		uint64_t rcvr_test_ovrd_en           : 1;  /**< R/W - Override RX detect disable and test pulse. */
		uint64_t rcvr_test_ovrd_val          : 1;  /**< R/W - Override value for RX detect test pulse; used to create a pulse during which the receiver
                                                                 detect test operation is performed. */
		uint64_t tx_rx_detect_dis_ovrd_val   : 1;  /**< R/W - Override value of RX detect disable. */
#else
		uint64_t tx_rx_detect_dis_ovrd_val   : 1;
		uint64_t rcvr_test_ovrd_val          : 1;
		uint64_t rcvr_test_ovrd_en           : 1;
		uint64_t reserved_3_14               : 12;
		uint64_t pcs_sds_tx_dcc_en           : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lanex_tx_cfg_2_s  cn88xx; */
	/* struct bdk_gserx_lanex_tx_cfg_2_s  cn88xxp1; */
} bdk_gserx_lanex_tx_cfg_2_t;

static inline uint64_t BDK_GSERX_LANEX_TX_CFG_2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_TX_CFG_2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400B8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_TX_CFG_2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_TX_CFG_2(...) bdk_gserx_lanex_tx_cfg_2_t
#define bustype_BDK_GSERX_LANEX_TX_CFG_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_TX_CFG_2(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_TX_CFG_2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_TX_CFG_2(...) "GSERX_LANEX_TX_CFG_2"


/**
 * RSL - gser#_lane#_tx_cfg_3
 *
 * These registers are for diagnostic use only. These registers are reset by hardware only during
 * chip cold reset. The values of the CSR fields in these registers do not change during chip
 * warm or soft resets.
 */
typedef union bdk_gserx_lanex_tx_cfg_3 {
	uint64_t u;
	struct bdk_gserx_lanex_tx_cfg_3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t cfg_tx_vboost_en            : 1;  /**< R/W - Specifies the value of TX VBoost enable when
                                                                 GSER()_LANE()_TX_CFG_1[TX_VBOOST_EN_OVRRD_EN] is asserted. */
		uint64_t reserved_7_13               : 7;
		uint64_t pcs_sds_tx_gain             : 3;  /**< R/W/H - TX Gain. For debug use only. */
		uint64_t pcs_sds_tx_srate_sel        : 3;  /**< R/W/H - Reserved. */
		uint64_t cfg_tx_turbo_en             : 1;  /**< R/W - Specifies value ot TX turbo enable when GSER()_LANE()_TX_CFG_1[TX_TURBO_EN] is set. */
#else
		uint64_t cfg_tx_turbo_en             : 1;
		uint64_t pcs_sds_tx_srate_sel        : 3;
		uint64_t pcs_sds_tx_gain             : 3;
		uint64_t reserved_7_13               : 7;
		uint64_t cfg_tx_vboost_en            : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lanex_tx_cfg_3_s  cn88xx; */
	/* struct bdk_gserx_lanex_tx_cfg_3_s  cn88xxp1; */
} bdk_gserx_lanex_tx_cfg_3_t;

static inline uint64_t BDK_GSERX_LANEX_TX_CFG_3(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_TX_CFG_3(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400C0ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_TX_CFG_3", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_TX_CFG_3(...) bdk_gserx_lanex_tx_cfg_3_t
#define bustype_BDK_GSERX_LANEX_TX_CFG_3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_TX_CFG_3(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_TX_CFG_3(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_TX_CFG_3(...) "GSERX_LANEX_TX_CFG_3"


/**
 * RSL - gser#_lane#_tx_pre_emphasis
 *
 * These registers are for diagnostic use only. These registers are reset by hardware only during
 * chip cold reset. The values of the CSR fields in these registers do not change during chip
 * warm or soft resets.
 */
typedef union bdk_gserx_lanex_tx_pre_emphasis {
	uint64_t u;
	struct bdk_gserx_lanex_tx_pre_emphasis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t cfg_tx_premptap             : 9;  /**< R/W - Override preemphasis control. Applies when
                                                                 GSER()_LANE()_TX_CFG_3[TX_PREMPTAP_OVRD_EN] is asserted.
                                                                 \<8:4\> = Post-cursor.
                                                                 \<3:0\> = Pre-cursor. */
#else
		uint64_t cfg_tx_premptap             : 9;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_gserx_lanex_tx_pre_emphasis_s cn88xx; */
	/* struct bdk_gserx_lanex_tx_pre_emphasis_s cn88xxp1; */
} bdk_gserx_lanex_tx_pre_emphasis_t;

static inline uint64_t BDK_GSERX_LANEX_TX_PRE_EMPHASIS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANEX_TX_PRE_EMPHASIS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 3)))
		return 0x000087E0904400C8ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_GSERX_LANEX_TX_PRE_EMPHASIS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANEX_TX_PRE_EMPHASIS(...) bdk_gserx_lanex_tx_pre_emphasis_t
#define bustype_BDK_GSERX_LANEX_TX_PRE_EMPHASIS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANEX_TX_PRE_EMPHASIS(p1,p2) (p1)
#define arguments_BDK_GSERX_LANEX_TX_PRE_EMPHASIS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANEX_TX_PRE_EMPHASIS(...) "GSERX_LANEX_TX_PRE_EMPHASIS"


/**
 * RSL - gser#_lane_lpbken
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_lpbken {
	uint64_t u;
	struct bdk_gserx_lane_lpbken_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t lpbken                      : 4;  /**< R/W - For links that are not in PCIE or SATA mode (including all CCPI links). When asserted in
                                                                 P0
                                                                 state,
                                                                 allows per lane TX-to-RX serial loopback activation.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t lpbken                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_lane_lpbken_s     cn88xx; */
	/* struct bdk_gserx_lane_lpbken_s     cn88xxp1; */
} bdk_gserx_lane_lpbken_t;

static inline uint64_t BDK_GSERX_LANE_LPBKEN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_LPBKEN(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000110ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_LPBKEN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_LPBKEN(...) bdk_gserx_lane_lpbken_t
#define bustype_BDK_GSERX_LANE_LPBKEN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_LPBKEN(p1) (p1)
#define arguments_BDK_GSERX_LANE_LPBKEN(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_LPBKEN(...) "GSERX_LANE_LPBKEN"


/**
 * RSL - gser#_lane_mode
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_mode {
	uint64_t u;
	struct bdk_gserx_lane_mode_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t lmode                       : 4;  /**< R/W/H - For links that are not in PCIE or SATA mode (including all CCPI links), used to index into
                                                                 the PHY
                                                                 table to select electrical specs and link rate. Note that the PHY table can be modified
                                                                 such that any supported link rate can be derived regardless of the configured LMODE.

                                                                 0x0: R_25G_REFCLK100.
                                                                 0x1: R_5G_REFCLK100.
                                                                 0x2: R_8G_REFCLK100.
                                                                 0x3: R_125G_REFCLK15625_KX (not supported).
                                                                 0x4: R_3125G_REFCLK15625_XAUI.

                                                                 For XAUI applications:
                                                                 0x5: R_103125G_REFCLK15625_KR.

                                                                 For XFI, XLAUI, KR applications:
                                                                 0x6: R_125G_REFCLK15625_SGMII.

                                                                 For SGMII applications:
                                                                 0x7: R_5G_REFCLK15625_QSGMII (not supported).
                                                                 0x8: R_625G_REFCLK15625_RXAUI.

                                                                 For RXAUI, DXAUI applications:
                                                                 0x9: R_25G_REFCLK125.
                                                                 0xA: R_5G_REFCLK125.
                                                                 0xB: R_8G_REFCLK125.
                                                                 0xC - 0xF: Reserved.

                                                                 This register is not used for PCIE configurations. For non-CCPI links, this register
                                                                 defaults to R_625G_REFCLK15625_RXAUI. For CCPI links, the value is mapped at reset from
                                                                 the
                                                                 GSER()_SPD and the appropriate table updates are performed so the rate is obtained for the
                                                                 particular reference clock.

                                                                 It is recommended that the PHY be in reset when reconfiguring the LMODE
                                                                 (GSER()_PHY_CTL[PHY_RESET] is set).

                                                                 Once the LMODE has been configured, and the PHY is out of reset, the table entries for the
                                                                 selected LMODE must be updated to reflect the reference clock speed. Refer to the register
                                                                 description and index into the table using the rate and reference speed to obtain the
                                                                 recommended values.

                                                                 _ Write GSER()_PLL_P()_MODE_0.
                                                                 _ Write GSER()_PLL_P()_MODE_1.
                                                                 _ Write GSER()_LANE_P()_MODE_0.
                                                                 _ Write GSER()_LANE_P()_MODE_1.

                                                                 where in "P(z)", z equals LMODE. */
#else
		uint64_t lmode                       : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_lane_mode_s       cn88xx; */
	/* struct bdk_gserx_lane_mode_s       cn88xxp1; */
} bdk_gserx_lane_mode_t;

static inline uint64_t BDK_GSERX_LANE_MODE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_MODE(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000118ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_MODE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_MODE(...) bdk_gserx_lane_mode_t
#define bustype_BDK_GSERX_LANE_MODE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_MODE(p1) (p1)
#define arguments_BDK_GSERX_LANE_MODE(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_MODE(...) "GSERX_LANE_MODE"


/**
 * RSL - gser#_lane_p#_mode_0
 *
 * These are the RAW PCS lane settings mode 0 registers. There is one register per
 * 4 lanes per GSER per GSER_LMODE_E value (0..11). Only one entry is used at any given time in a
 * given GSER lane - the one selected by the corresponding GSER()_LANE_MODE[LMODE].
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_px_mode_0 {
	uint64_t u;
	struct bdk_gserx_lane_px_mode_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t ctle                        : 2;  /**< R/W/H - Continuous time linear equalizer pole configuration.
                                                                 0x0 = ~5dB of peaking at 4 GHz (Minimum bandwidth).
                                                                 0x1 =~10dB of peaking at 5 GHz
                                                                 0x2 = ~15dB of peaking at 5.5 GHz
                                                                 0x3 = ~20dB of peaking at 6 GHz (Maximum bandwidth).

                                                                 Recommended settings:
                                                                 _ R_25G_REFCLK100:          0x0
                                                                 _ R_5G_REFCLK100:           0x0
                                                                 _ R_8G_REFCLK100:           0x3
                                                                 _ R_125G_REFCLK15625_KX:    0x0
                                                                 _ R_3125G_REFCLK15625_XAUI: 0x0
                                                                 _ R_103125G_REFCLK15625_KR: 0x3
                                                                 _ R_125G_REFCLK15625_SGMII: 0x0
                                                                 _ R_5G_REFCLK15625_QSGMII:  0x0
                                                                 _ R_625G_REFCLK15625_RXAUI: 0x0
                                                                 _ R_25G_REFCLK125:          0x0
                                                                 _ R_5G_REFCLK125:           0x0
                                                                 _ R_8G_REFCLK125:           0x3 */
		uint64_t pcie                        : 1;  /**< R/W/H - Selects between RX terminations.
                                                                 0: Differential termination
                                                                 1: Termination between pad and SDS_VDDS.

                                                                 Recommended settings:
                                                                 _ R_25G_REFCLK100:          0x1
                                                                 _ R_5G_REFCLK100:           0x1
                                                                 _ R_8G_REFCLK100:           0x0
                                                                 _ R_125G_REFCLK15625_KX:    0x0
                                                                 _ R_3125G_REFCLK15625_XAUI: 0x0
                                                                 _ R_103125G_REFCLK15625_KR: 0x0
                                                                 _ R_125G_REFCLK15625_SGMII: 0x0
                                                                 _ R_5G_REFCLK15625_QSGMII:  0x0
                                                                 _ R_625G_REFCLK15625_RXAUI: 0x0
                                                                 _ R_25G_REFCLK125:          0x1
                                                                 _ R_5G_REFCLK125:           0x1
                                                                 _ R_8G_REFCLK125:           0x0 */
		uint64_t tx_ldiv                     : 2;  /**< R/W/H - Configures clock divider used to determine the receive rate.
                                                                 0x0 = full data rate.
                                                                 0x1 = 1/2 data rate.
                                                                 0x2 = 1/4 data rate.
                                                                 0x3 = 1/8 data rate.

                                                                 Recommended settings:
                                                                 \<pre\>
                                                                                             SATA   non-SATA
                                                                 _ R_25G_REFCLK100:           0x0    0x1
                                                                 _ R_5G_REFCLK100:            0x0    0x0
                                                                 _ R_8G_REFCLK100:            0x0    0x0
                                                                 _ R_125G_REFCLK15625_KX:     NS     0x2
                                                                 _ R_3125G_REFCLK15625_XAUI:  NS     0x1
                                                                 _ R_103125G_REFCLK15625_KR:  NS     0x0
                                                                 _ R_125G_REFCLK15625_SGMII:  NS     0x2
                                                                 _ R_5G_REFCLK15625_QSGMII:   NS     0x0
                                                                 _ R_625G_REFCLK15625_RXAUI:  NS     0x0
                                                                 _ R_25G_REFCLK125:           NS     0x1
                                                                 _ R_5G_REFCLK125:            NS     0x0
                                                                 _ R_8G_REFCLK125:            NS     0x0
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
		uint64_t rx_ldiv                     : 2;  /**< R/W/H - Configures clock divider used to determine the receive rate.
                                                                 0x0 = full data rate
                                                                 0x1 = 1/2 data rate
                                                                 0x2 = 1/4 data rate
                                                                 0x3 = 1/8 data rate

                                                                 Recommended settings:
                                                                 \<pre\>
                                                                                             SATA   non-SATA
                                                                 _ R_25G_REFCLK100:           0x2    0x1
                                                                 _ R_5G_REFCLK100:            0x1    0x0
                                                                 _ R_8G_REFCLK100:            0x1    0x0
                                                                 _ R_125G_REFCLK15625_KX:     NS     0x2
                                                                 _ R_3125G_REFCLK15625_XAUI:  NS     0x1
                                                                 _ R_103125G_REFCLK15625_KR:  NS     0x0
                                                                 _ R_125G_REFCLK15625_SGMII:  NS     0x2
                                                                 _ R_5G_REFCLK15625_QSGMII:   NS     0x0
                                                                 _ R_625G_REFCLK15625_RXAUI:  NS     0x0
                                                                 _ R_25G_REFCLK125:           NS     0x1
                                                                 _ R_5G_REFCLK125:            NS     0x0
                                                                 _ R_8G_REFCLK125:            NS     0x0
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
		uint64_t srate                       : 3;  /**< R/W - Sample rate, used to generate strobe to effectively divide the clock down to a slower
                                                                 rate.
                                                                 0x0 = Full rate
                                                                 0x1 = 1/2 data rate
                                                                 0x2 = 1/4 data rate
                                                                 0x3 = 1/8 data rate
                                                                 0x4 = 1/16 data rate
                                                                 else = Reserved.
                                                                 This field should always be cleared to zero (full rate). */
		uint64_t reserved_4_4                : 1;
		uint64_t tx_mode                     : 2;  /**< R/W/H - TX data width:
                                                                 0x0 = 8-bit raw data (not supported).
                                                                 0x1 = 10-bit raw data (not supported).
                                                                 0x2 = 16-bit raw data (not supported).
                                                                 0x3 = 20-bit raw data. */
		uint64_t rx_mode                     : 2;  /**< R/W/H - RX data width:
                                                                 0x0 = 8-bit raw data (not supported).
                                                                 0x1 = 10-bit raw data (not supported).
                                                                 0x2 = 16-bit raw data (not supported).
                                                                 0x3 = 20-bit raw data. */
#else
		uint64_t rx_mode                     : 2;
		uint64_t tx_mode                     : 2;
		uint64_t reserved_4_4                : 1;
		uint64_t srate                       : 3;
		uint64_t rx_ldiv                     : 2;
		uint64_t tx_ldiv                     : 2;
		uint64_t pcie                        : 1;
		uint64_t ctle                        : 2;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_gserx_lane_px_mode_0_s  cn88xx; */
	/* struct bdk_gserx_lane_px_mode_0_s  cn88xxp1; */
} bdk_gserx_lane_px_mode_0_t;

static inline uint64_t BDK_GSERX_LANE_PX_MODE_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_PX_MODE_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 11)))
		return 0x000087E0904E0040ull + (param1 & 15) * 0x1000000ull + (param2 & 15) * 0x20ull;
	csr_fatal("BDK_GSERX_LANE_PX_MODE_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_PX_MODE_0(...) bdk_gserx_lane_px_mode_0_t
#define bustype_BDK_GSERX_LANE_PX_MODE_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_PX_MODE_0(p1,p2) (p1)
#define arguments_BDK_GSERX_LANE_PX_MODE_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANE_PX_MODE_0(...) "GSERX_LANE_PX_MODE_0"


/**
 * RSL - gser#_lane_p#_mode_1
 *
 * These are the RAW PCS lane settings mode 1 registers. There is one register per 4 lanes,
 * (0..3) per GSER per GSER_LMODE_E value (0..11). Only one entry is used at any given time in a
 * given
 * GSER lane - the one selected by the corresponding GSER()_LANE_MODE[LMODE].
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_px_mode_1 {
	uint64_t u;
	struct bdk_gserx_lane_px_mode_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t vma_fine_cfg_sel            : 1;  /**< R/W/H - Recommended settings:
                                                                 1 = Enabled. Fine step adaptation selected (10.3125 Gbaud rate).
                                                                 0 = Disabled. Coarse step adaptation selected (rates lower than 10.3125 Gbaud). */
		uint64_t vma_mm                      : 1;  /**< R/W/H - Manual DFE verses adaptive DFE mode. Recommended settings:
                                                                 0 = Adaptive DFE (5 Gbaud and higher)
                                                                 1 = Manual DFE, fixed tap (3.125 Gbaud and lower). */
		uint64_t cdr_fgain                   : 4;  /**< R/W/H - CDR frequency gain.
                                                                 Recommended settings:
                                                                 _ R_25G_REFCLK100:          0xA
                                                                 _ R_5G_REFCLK100:           0xA
                                                                 _ R_8G_REFCLK100:           0xB
                                                                 _ R_125G_REFCLK15625_KX:    0xC
                                                                 _ R_3125G_REFCLK15625_XAUI: 0xC
                                                                 _ R_103125G_REFCLK15625_KR: 0xA
                                                                 _ R_125G_REFCLK15625_SGMII: 0xC
                                                                 _ R_5G_REFCLK15625_QSGMII:  0xC
                                                                 _ R_625G_REFCLK15625_RXAUI: 0xA
                                                                 _ R_25G_REFCLK125:          0xA
                                                                 _ R_5G_REFCLK125:           0xA
                                                                 _ R_8G_REFCLK125:           0xB */
		uint64_t ph_acc_adj                  : 10; /**< R/W/H - Phase accumulator adjust.
                                                                 Recommended settings:
                                                                 _ R_25G_REFCLK100:          0x14
                                                                 _ R_5G_REFCLK100:           0x14
                                                                 _ R_8G_REFCLK100:           0x23
                                                                 _ R_125G_REFCLK15625_KX:    0x1E
                                                                 _ R_3125G_REFCLK15625_XAUI: 0x1E
                                                                 _ R_103125G_REFCLK15625_KR: 0xF
                                                                 _ R_125G_REFCLK15625_SGMII: 0x1E
                                                                 _ R_5G_REFCLK15625_QSGMII:  0x1E
                                                                 _ R_625G_REFCLK15625_RXAUI: 0x14
                                                                 _ R_25G_REFCLK125:          0x14
                                                                 _ R_5G_REFCLK125:           0x14
                                                                 _ R_8G_REFCLK125:           0x23 */
#else
		uint64_t ph_acc_adj                  : 10;
		uint64_t cdr_fgain                   : 4;
		uint64_t vma_mm                      : 1;
		uint64_t vma_fine_cfg_sel            : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lane_px_mode_1_s  cn88xx; */
	/* struct bdk_gserx_lane_px_mode_1_s  cn88xxp1; */
} bdk_gserx_lane_px_mode_1_t;

static inline uint64_t BDK_GSERX_LANE_PX_MODE_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_PX_MODE_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 11)))
		return 0x000087E0904E0048ull + (param1 & 15) * 0x1000000ull + (param2 & 15) * 0x20ull;
	csr_fatal("BDK_GSERX_LANE_PX_MODE_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_PX_MODE_1(...) bdk_gserx_lane_px_mode_1_t
#define bustype_BDK_GSERX_LANE_PX_MODE_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_PX_MODE_1(p1,p2) (p1)
#define arguments_BDK_GSERX_LANE_PX_MODE_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_LANE_PX_MODE_1(...) "GSERX_LANE_PX_MODE_1"


/**
 * RSL - gser#_lane_poff
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_poff {
	uint64_t u;
	struct bdk_gserx_lane_poff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t lpoff                       : 4;  /**< R/W - For links that are not in PCIE mode (including all CCPI links), allows for per lane power
                                                                 down.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t lpoff                       : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_lane_poff_s       cn88xx; */
	/* struct bdk_gserx_lane_poff_s       cn88xxp1; */
} bdk_gserx_lane_poff_t;

static inline uint64_t BDK_GSERX_LANE_POFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_POFF(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000108ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_POFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_POFF(...) bdk_gserx_lane_poff_t
#define bustype_BDK_GSERX_LANE_POFF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_POFF(p1) (p1)
#define arguments_BDK_GSERX_LANE_POFF(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_POFF(...) "GSERX_LANE_POFF"


/**
 * RSL - gser#_lane_srst
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_srst {
	uint64_t u;
	struct bdk_gserx_lane_srst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t lsrst                       : 1;  /**< R/W - For links that are not in PCIE or SATA mode (including all CCPI links), resets all 4 lanes
                                                                 (equivalent to the P2 power state) after any pending requests (power state change, rate
                                                                 change) are complete. The lanes remain in reset state while this signal is asserted. When
                                                                 the signal deasserts, the lanes exit the reset state and the PHY returns to the power
                                                                 state the PHY was in prior. For diagnostic use only. */
#else
		uint64_t lsrst                       : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_lane_srst_s       cn88xx; */
	/* struct bdk_gserx_lane_srst_s       cn88xxp1; */
} bdk_gserx_lane_srst_t;

static inline uint64_t BDK_GSERX_LANE_SRST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_SRST(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000100ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_SRST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_SRST(...) bdk_gserx_lane_srst_t
#define bustype_BDK_GSERX_LANE_SRST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_SRST(p1) (p1)
#define arguments_BDK_GSERX_LANE_SRST(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_SRST(...) "GSERX_LANE_SRST"


/**
 * RSL - gser#_lane_vma_coarse_ctrl_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_vma_coarse_ctrl_0 {
	uint64_t u;
	struct bdk_gserx_lane_vma_coarse_ctrl_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t iq_max                      : 4;  /**< R/W - Slice DLL IQ maximum value in VMA coarse mode. */
		uint64_t iq_min                      : 4;  /**< R/W - Slice DLL IQ minimum value in VMA coarse mode. */
		uint64_t iq_step                     : 2;  /**< R/W - Slice DLL IQ step size in VMA coarse mode. */
		uint64_t window_wait                 : 3;  /**< R/W - Adaptation window wait setting in VMA coarse mode. */
		uint64_t lms_wait                    : 3;  /**< R/W/H - LMS wait time setting used to control the number of samples taken during the collection of
                                                                 statistics in VMA coarse mode. */
#else
		uint64_t lms_wait                    : 3;
		uint64_t window_wait                 : 3;
		uint64_t iq_step                     : 2;
		uint64_t iq_min                      : 4;
		uint64_t iq_max                      : 4;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lane_vma_coarse_ctrl_0_s cn88xx; */
	/* struct bdk_gserx_lane_vma_coarse_ctrl_0_s cn88xxp1; */
} bdk_gserx_lane_vma_coarse_ctrl_0_t;

static inline uint64_t BDK_GSERX_LANE_VMA_COARSE_CTRL_0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_VMA_COARSE_CTRL_0(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E01B0ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_VMA_COARSE_CTRL_0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_VMA_COARSE_CTRL_0(...) bdk_gserx_lane_vma_coarse_ctrl_0_t
#define bustype_BDK_GSERX_LANE_VMA_COARSE_CTRL_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_VMA_COARSE_CTRL_0(p1) (p1)
#define arguments_BDK_GSERX_LANE_VMA_COARSE_CTRL_0(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_VMA_COARSE_CTRL_0(...) "GSERX_LANE_VMA_COARSE_CTRL_0"


/**
 * RSL - gser#_lane_vma_coarse_ctrl_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_vma_coarse_ctrl_1 {
	uint64_t u;
	struct bdk_gserx_lane_vma_coarse_ctrl_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t ctle_pmax                   : 4;  /**< R/W - RX CTLE peak maximum value in VMA coarse mode. */
		uint64_t ctle_pmin                   : 4;  /**< R/W - RX CTLE peak minimum value in VMA coarse mode. */
		uint64_t ctle_pstep                  : 2;  /**< R/W - CTLE peak step size in VMA coarse mode. */
#else
		uint64_t ctle_pstep                  : 2;
		uint64_t ctle_pmin                   : 4;
		uint64_t ctle_pmax                   : 4;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lane_vma_coarse_ctrl_1_s cn88xx; */
	/* struct bdk_gserx_lane_vma_coarse_ctrl_1_s cn88xxp1; */
} bdk_gserx_lane_vma_coarse_ctrl_1_t;

static inline uint64_t BDK_GSERX_LANE_VMA_COARSE_CTRL_1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_VMA_COARSE_CTRL_1(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E01B8ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_VMA_COARSE_CTRL_1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_VMA_COARSE_CTRL_1(...) bdk_gserx_lane_vma_coarse_ctrl_1_t
#define bustype_BDK_GSERX_LANE_VMA_COARSE_CTRL_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_VMA_COARSE_CTRL_1(p1) (p1)
#define arguments_BDK_GSERX_LANE_VMA_COARSE_CTRL_1(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_VMA_COARSE_CTRL_1(...) "GSERX_LANE_VMA_COARSE_CTRL_1"


/**
 * RSL - gser#_lane_vma_coarse_ctrl_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_vma_coarse_ctrl_2 {
	uint64_t u;
	struct bdk_gserx_lane_vma_coarse_ctrl_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t pctle_gmax                  : 4;  /**< R/W - RX PRE-CTLE gain maximum value in VMA coarse mode. */
		uint64_t pctle_gmin                  : 4;  /**< R/W - RX PRE-CTLE gain minimum value in VMA coarse mode. */
		uint64_t pctle_gstep                 : 2;  /**< R/W - CTLE PRE-peak gain step size in VMA coarse mode. */
#else
		uint64_t pctle_gstep                 : 2;
		uint64_t pctle_gmin                  : 4;
		uint64_t pctle_gmax                  : 4;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lane_vma_coarse_ctrl_2_s cn88xx; */
	/* struct bdk_gserx_lane_vma_coarse_ctrl_2_s cn88xxp1; */
} bdk_gserx_lane_vma_coarse_ctrl_2_t;

static inline uint64_t BDK_GSERX_LANE_VMA_COARSE_CTRL_2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_VMA_COARSE_CTRL_2(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E01C0ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_VMA_COARSE_CTRL_2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_VMA_COARSE_CTRL_2(...) bdk_gserx_lane_vma_coarse_ctrl_2_t
#define bustype_BDK_GSERX_LANE_VMA_COARSE_CTRL_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_VMA_COARSE_CTRL_2(p1) (p1)
#define arguments_BDK_GSERX_LANE_VMA_COARSE_CTRL_2(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_VMA_COARSE_CTRL_2(...) "GSERX_LANE_VMA_COARSE_CTRL_2"


/**
 * RSL - gser#_lane_vma_fine_ctrl_0
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_vma_fine_ctrl_0 {
	uint64_t u;
	struct bdk_gserx_lane_vma_fine_ctrl_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rx_sdll_iq_max_fine         : 4;  /**< R/W - RX Slice DLL IQ maximum value in VMA Fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and
                                                                 GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t rx_sdll_iq_min_fine         : 4;  /**< R/W - RX slice DLL IQ minimum value in VMA fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and
                                                                 GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t rx_sdll_iq_step_fine        : 2;  /**< R/W - RX Slice DLL IQ step size in VMA Fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and
                                                                 GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t vma_window_wait_fine        : 3;  /**< R/W - Adaptation window wait setting (in VMA fine mode); used to control the number of samples
                                                                 taken during the collection of statistics (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t lms_wait_time_fine          : 3;  /**< R/W - LMS wait time setting (in VMA fine mode); used to control the number of samples taken
                                                                 during the collection of statistics (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
#else
		uint64_t lms_wait_time_fine          : 3;
		uint64_t vma_window_wait_fine        : 3;
		uint64_t rx_sdll_iq_step_fine        : 2;
		uint64_t rx_sdll_iq_min_fine         : 4;
		uint64_t rx_sdll_iq_max_fine         : 4;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_lane_vma_fine_ctrl_0_s cn88xx; */
	/* struct bdk_gserx_lane_vma_fine_ctrl_0_s cn88xxp1; */
} bdk_gserx_lane_vma_fine_ctrl_0_t;

static inline uint64_t BDK_GSERX_LANE_VMA_FINE_CTRL_0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_VMA_FINE_CTRL_0(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E01C8ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_VMA_FINE_CTRL_0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_VMA_FINE_CTRL_0(...) bdk_gserx_lane_vma_fine_ctrl_0_t
#define bustype_BDK_GSERX_LANE_VMA_FINE_CTRL_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_VMA_FINE_CTRL_0(p1) (p1)
#define arguments_BDK_GSERX_LANE_VMA_FINE_CTRL_0(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_VMA_FINE_CTRL_0(...) "GSERX_LANE_VMA_FINE_CTRL_0"


/**
 * RSL - gser#_lane_vma_fine_ctrl_1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_vma_fine_ctrl_1 {
	uint64_t u;
	struct bdk_gserx_lane_vma_fine_ctrl_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t rx_ctle_peak_max_fine       : 4;  /**< R/W - RX CTLE peak maximum value in VMA fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t rx_ctle_peak_min_fine       : 4;  /**< R/W - RX CTLE peak minimum value in VMA fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t rx_ctle_peak_step_fine      : 2;  /**< R/W - RX CTLE Peak step size in VMA Fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
#else
		uint64_t rx_ctle_peak_step_fine      : 2;
		uint64_t rx_ctle_peak_min_fine       : 4;
		uint64_t rx_ctle_peak_max_fine       : 4;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lane_vma_fine_ctrl_1_s cn88xx; */
	/* struct bdk_gserx_lane_vma_fine_ctrl_1_s cn88xxp1; */
} bdk_gserx_lane_vma_fine_ctrl_1_t;

static inline uint64_t BDK_GSERX_LANE_VMA_FINE_CTRL_1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_VMA_FINE_CTRL_1(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E01D0ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_VMA_FINE_CTRL_1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_VMA_FINE_CTRL_1(...) bdk_gserx_lane_vma_fine_ctrl_1_t
#define bustype_BDK_GSERX_LANE_VMA_FINE_CTRL_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_VMA_FINE_CTRL_1(p1) (p1)
#define arguments_BDK_GSERX_LANE_VMA_FINE_CTRL_1(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_VMA_FINE_CTRL_1(...) "GSERX_LANE_VMA_FINE_CTRL_1"


/**
 * RSL - gser#_lane_vma_fine_ctrl_2
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_lane_vma_fine_ctrl_2 {
	uint64_t u;
	struct bdk_gserx_lane_vma_fine_ctrl_2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t rx_prectle_peak_max_fine    : 4;  /**< R/W - RX PRE-CTLE peak maximum value in VMA fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t rx_prectle_peak_min_fine    : 4;  /**< R/W - RX PRE-CTLE peak minimum value in VMA fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
		uint64_t rx_prectle_peak_step_fine   : 2;  /**< R/W - RX PRE-CTLE peak step size in VMA fine mode (valid when
                                                                 GSER()_LANE_P()_MODE_1[VMA_FINE_CFG_SEL]=1 and GSER()_LANE_P()_MODE_1[VMA_MM]=0). */
#else
		uint64_t rx_prectle_peak_step_fine   : 2;
		uint64_t rx_prectle_peak_min_fine    : 4;
		uint64_t rx_prectle_peak_max_fine    : 4;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_gserx_lane_vma_fine_ctrl_2_s cn88xx; */
	/* struct bdk_gserx_lane_vma_fine_ctrl_2_s cn88xxp1; */
} bdk_gserx_lane_vma_fine_ctrl_2_t;

static inline uint64_t BDK_GSERX_LANE_VMA_FINE_CTRL_2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_LANE_VMA_FINE_CTRL_2(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E01D8ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_LANE_VMA_FINE_CTRL_2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_LANE_VMA_FINE_CTRL_2(...) bdk_gserx_lane_vma_fine_ctrl_2_t
#define bustype_BDK_GSERX_LANE_VMA_FINE_CTRL_2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_LANE_VMA_FINE_CTRL_2(p1) (p1)
#define arguments_BDK_GSERX_LANE_VMA_FINE_CTRL_2(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_LANE_VMA_FINE_CTRL_2(...) "GSERX_LANE_VMA_FINE_CTRL_2"


/**
 * RSL - gser#_phy_ctl
 *
 * This register contains general PHY/PLL control of the RAW PCS.
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_phy_ctl {
	uint64_t u;
	struct bdk_gserx_phy_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t phy_reset                   : 1;  /**< R/W/H - When asserted, the PHY is held in reset. This bit is initialized as follows:
                                                                 0 = (not reset) = Bootable PCIe, or CCPI when GSER(8..13)_SPD[SPD] comes up in a bootable
                                                                 mode.
                                                                 1 = (reset) = Non-bootable PCIe, BGX, SATA or CCPI when GSER(8..13)_SPD[SPD] comes up in
                                                                 SW_MODE. */
		uint64_t phy_pd                      : 1;  /**< R/W - When asserted, the PHY is powered down. */
#else
		uint64_t phy_pd                      : 1;
		uint64_t phy_reset                   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gserx_phy_ctl_s         cn88xx; */
	/* struct bdk_gserx_phy_ctl_s         cn88xxp1; */
} bdk_gserx_phy_ctl_t;

static inline uint64_t BDK_GSERX_PHY_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_PHY_CTL(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000000ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_PHY_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_PHY_CTL(...) bdk_gserx_phy_ctl_t
#define bustype_BDK_GSERX_PHY_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_PHY_CTL(p1) (p1)
#define arguments_BDK_GSERX_PHY_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_PHY_CTL(...) "GSERX_PHY_CTL"


/**
 * RSL - gser#_pipe_lpbk
 */
typedef union bdk_gserx_pipe_lpbk {
	uint64_t u;
	struct bdk_gserx_pipe_lpbk_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t pcie_lpbk                   : 1;  /**< R/W - For links that are in PCIE mode, places the PHY in serial loopback mode, where the
                                                                 QLMn_TXN/QLMn_TXP data are looped back to the QLMn_RXN/QLMn_RXP.

                                                                 This register has no meaning for links that don't support PCIe i.e. GSER(5..13). */
#else
		uint64_t pcie_lpbk                   : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_pipe_lpbk_s       cn88xx; */
	/* struct bdk_gserx_pipe_lpbk_s       cn88xxp1; */
} bdk_gserx_pipe_lpbk_t;

static inline uint64_t BDK_GSERX_PIPE_LPBK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_PIPE_LPBK(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000200ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_PIPE_LPBK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_PIPE_LPBK(...) bdk_gserx_pipe_lpbk_t
#define bustype_BDK_GSERX_PIPE_LPBK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_PIPE_LPBK(p1) (p1)
#define arguments_BDK_GSERX_PIPE_LPBK(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_PIPE_LPBK(...) "GSERX_PIPE_LPBK"


/**
 * RSL - gser#_pll_p#_mode_0
 *
 * These are the RAW PCS PLL global settings mode 0 registers. There is one register per GSER per
 * GSER_LMODE_E value (0..11). Only one entry is used at any given time in a given GSER - the one
 * selected by the corresponding GSER()_LANE_MODE[LMODE].
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during subsequent chip warm or
 * soft resets.
 */
typedef union bdk_gserx_pll_px_mode_0 {
	uint64_t u;
	struct bdk_gserx_pll_px_mode_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t pll_icp                     : 4;  /**< R/W/H - PLL charge pump enable.
                                                                 Recommended settings, which are based on the reference clock speed:

                                                                 \<pre\>
                                                                          100Mhz  100MHz   125MHz   156.25MHz
                                                                          SATA    non-SATA non-SATA non-SATA
                                                                 1.25G:    NS     0x1      0x1      0x1
                                                                 2.5G:     0x1    0x4      0x3      0x3
                                                                 3.125G:   NS     NS       0x1      0x1
                                                                 5.0G:     0x1    0x4      0x3      0x3
                                                                 6.25G:    NS     NS       0x1      0x1
                                                                 8.0G:     0x1    0x3      0x2      NS
                                                                 10.3125G: NS     NS       NS       0x1
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
		uint64_t pll_rloop                   : 3;  /**< R/W/H - Loop resistor tuning.
                                                                 Recommended settings:
                                                                 \<pre\>
                                                                             SATA    non-SATA
                                                                 _ 1.25G:     NS      0x3
                                                                 _ 2.5G:      0x3     0x3
                                                                 _ 3.125G:    NS      0x3
                                                                 _ 5.0G:      0x3     0x3
                                                                 _ 6.25G:     NS      0x3
                                                                 _ 8.0G:      0x5     0x5
                                                                 _ 10.3125G:  NS      0x5
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
		uint64_t pll_pcs_div                 : 9;  /**< R/W/H - The divider that generates PCS_MAC_TX_CLK. The frequency of the clock is (pll_frequency /
                                                                 PLL_PCS_DIV).
                                                                 Recommended settings:
                                                                 \<pre\>
                                                                             SATA    PCIE   Other
                                                                 _ 1.25G:     NS      NS     0x28
                                                                 _ 2.5G:      0x5     0x5    0x5
                                                                 _ 3.125G:    NS      NS     0x14
                                                                 _ 5.0G:      0x5     0x5    0xA
                                                                 _ 6.25G:     NS      NS     0xA
                                                                 _ 8.0G:      0x5     0x8    0xA
                                                                 _ 10.3125G:  NS      NS     0xA
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
#else
		uint64_t pll_pcs_div                 : 9;
		uint64_t pll_rloop                   : 3;
		uint64_t pll_icp                     : 4;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_pll_px_mode_0_s   cn88xx; */
	/* struct bdk_gserx_pll_px_mode_0_s   cn88xxp1; */
} bdk_gserx_pll_px_mode_0_t;

static inline uint64_t BDK_GSERX_PLL_PX_MODE_0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_PLL_PX_MODE_0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 11)))
		return 0x000087E0904E0030ull + (param1 & 15) * 0x1000000ull + (param2 & 15) * 0x20ull;
	csr_fatal("BDK_GSERX_PLL_PX_MODE_0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_PLL_PX_MODE_0(...) bdk_gserx_pll_px_mode_0_t
#define bustype_BDK_GSERX_PLL_PX_MODE_0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_PLL_PX_MODE_0(p1,p2) (p1)
#define arguments_BDK_GSERX_PLL_PX_MODE_0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_PLL_PX_MODE_0(...) "GSERX_PLL_PX_MODE_0"


/**
 * RSL - gser#_pll_p#_mode_1
 *
 * These are the RAW PCS PLL global settings mode 1 registers. There is one register per GSER per
 * GSER_LMODE_E value (0..11). Only one entry is used at any given time in a given GSER - the one
 * selected by the corresponding GSER()_LANE_MODE[LMODE].
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in this register do not change during subsequent chip warm or
 * soft resets.
 */
typedef union bdk_gserx_pll_px_mode_1 {
	uint64_t u;
	struct bdk_gserx_pll_px_mode_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t pll_16p5en                  : 1;  /**< R/W/H - Enable for the DIV 16.5 divided down clock.
                                                                 Recommended settings, based on the reference clock speed:

                                                                 \<pre\>
                                                                          100MHz 125MHz 156.25MHz
                                                                 1.25G:    0x1    0x1     0x1
                                                                 2.5G:     0x0    0x0     0x0
                                                                 3.125G:   NS     0x1     0x1
                                                                 5.0G:     0x0    0x0     0x0
                                                                 6.25G:    NS     0x0     0x0
                                                                 8.0G:     0x0    0x0     NS
                                                                 10.3125G: NS     NS      0x1
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
		uint64_t pll_cpadj                   : 2;  /**< R/W/H - PLL charge adjust.
                                                                 Recommended settings, based on the reference clock speed:

                                                                 \<pre\>
                                                                           100MHz 125MHz 156.25MHz
                                                                 1.25G:     0x2     0x2    0x3
                                                                 2.5G:      0x2     0x1    0x2
                                                                 3.125G:    NS      0x2    0x2
                                                                 5.0G:      0x2     0x1    0x2
                                                                 6.25G:     NS      0x2    0x2
                                                                 8.0G:      0x2     0x1    NS
                                                                 10.3125G:  NS      NS     0x2
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
		uint64_t pll_pcie3en                 : 1;  /**< R/W/H - Enable PCIE3 mode. Recommended settings:
                                                                 0 = Any rate other than 8 Gbaud.
                                                                 1 = Rate is equal to 8 Gbaud. */
		uint64_t pll_opr                     : 1;  /**< R/W/H - PLL op range:
                                                                 0 = Use Ring Oscillator VCO.
                                                                 Recommended for rates 6.25 Gbaud and lower and for SATA.
                                                                 1 = Use LC-tank VCO.
                                                                 Recommended for non-SATA rates 8 Gbaud and higher. */
		uint64_t pll_div                     : 9;  /**< R/W/H - PLL divider in feedback path which sets the PLL frequency.
                                                                 Recommended settings:

                                                                 \<pre\>
                                                                          100Mhz  100MHz   125MHz   156.25MHz
                                                                          SATA    non-SATA non-SATA non-SATA
                                                                 1.25G:    NS      0x19   0x14    0x10
                                                                 2.5G:     0x18    0x19   0x14    0x10
                                                                 3.125G:   NS      NS     0x19    0x14
                                                                 5.0G:     0x18    0x19   0x14    0x10
                                                                 6.25G:    NS      NS     0x19    0x14
                                                                 8.0G:     0x18    0x28   0x20    NS
                                                                 10.3125G: NS      NS     NS      0x21
                                                                 \</pre\>

                                                                 A 'NS' indicates that the rate is not supported at the specified reference clock. */
#else
		uint64_t pll_div                     : 9;
		uint64_t pll_opr                     : 1;
		uint64_t pll_pcie3en                 : 1;
		uint64_t pll_cpadj                   : 2;
		uint64_t pll_16p5en                  : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_pll_px_mode_1_s   cn88xx; */
	/* struct bdk_gserx_pll_px_mode_1_s   cn88xxp1; */
} bdk_gserx_pll_px_mode_1_t;

static inline uint64_t BDK_GSERX_PLL_PX_MODE_1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_PLL_PX_MODE_1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 11)))
		return 0x000087E0904E0038ull + (param1 & 15) * 0x1000000ull + (param2 & 15) * 0x20ull;
	csr_fatal("BDK_GSERX_PLL_PX_MODE_1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_PLL_PX_MODE_1(...) bdk_gserx_pll_px_mode_1_t
#define bustype_BDK_GSERX_PLL_PX_MODE_1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_PLL_PX_MODE_1(p1,p2) (p1)
#define arguments_BDK_GSERX_PLL_PX_MODE_1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_PLL_PX_MODE_1(...) "GSERX_PLL_PX_MODE_1"


/**
 * RSL - gser#_pll_stat
 */
typedef union bdk_gserx_pll_stat {
	uint64_t u;
	struct bdk_gserx_pll_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t pll_lock                    : 1;  /**< RO/H - When set, indicates that the PHY PLL is locked. */
#else
		uint64_t pll_lock                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_pll_stat_s        cn88xx; */
	/* struct bdk_gserx_pll_stat_s        cn88xxp1; */
} bdk_gserx_pll_stat_t;

static inline uint64_t BDK_GSERX_PLL_STAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_PLL_STAT(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000010ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_PLL_STAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_PLL_STAT(...) bdk_gserx_pll_stat_t
#define bustype_BDK_GSERX_PLL_STAT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_PLL_STAT(p1) (p1)
#define arguments_BDK_GSERX_PLL_STAT(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_PLL_STAT(...) "GSERX_PLL_STAT"


/**
 * RSL - gser#_qlm_stat
 */
typedef union bdk_gserx_qlm_stat {
	uint64_t u;
	struct bdk_gserx_qlm_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t rst_rdy                     : 1;  /**< RO/H - When asserted, the QLM is configured and the PLLs are stable. The GSER
                                                                 is ready to accept TX traffic from the MAC. */
		uint64_t dcok                        : 1;  /**< RO - When asserted, there is a PLL reference clock indicating there is power to the QLM. */
#else
		uint64_t dcok                        : 1;
		uint64_t rst_rdy                     : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gserx_qlm_stat_s        cn88xx; */
	/* struct bdk_gserx_qlm_stat_s        cn88xxp1; */
} bdk_gserx_qlm_stat_t;

static inline uint64_t BDK_GSERX_QLM_STAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_QLM_STAT(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0900000A0ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_QLM_STAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_QLM_STAT(...) bdk_gserx_qlm_stat_t
#define bustype_BDK_GSERX_QLM_STAT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_QLM_STAT(p1) (p1)
#define arguments_BDK_GSERX_QLM_STAT(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_QLM_STAT(...) "GSERX_QLM_STAT"


/**
 * RSL - gser#_rdet_time
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_rdet_time {
	uint64_t u;
	struct bdk_gserx_rdet_time_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rdet_time_3                 : 4;  /**< R/W - Determines the time allocated for disabling the RX detect
                                                                 circuit, and returning to common mode. */
		uint64_t rdet_time_2                 : 4;  /**< R/W - Determines the time allocated for the RX detect circuit to
                                                                 detect a receiver. */
		uint64_t rdet_time_1                 : 8;  /**< R/W - Determines the time allocated for enabling the RX detect circuit. */
#else
		uint64_t rdet_time_1                 : 8;
		uint64_t rdet_time_2                 : 4;
		uint64_t rdet_time_3                 : 4;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_rdet_time_s       cn88xx; */
	/* struct bdk_gserx_rdet_time_s       cn88xxp1; */
} bdk_gserx_rdet_time_t;

static inline uint64_t BDK_GSERX_RDET_TIME(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RDET_TIME(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904E0008ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RDET_TIME", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RDET_TIME(...) bdk_gserx_rdet_time_t
#define bustype_BDK_GSERX_RDET_TIME(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RDET_TIME(p1) (p1)
#define arguments_BDK_GSERX_RDET_TIME(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RDET_TIME(...) "GSERX_RDET_TIME"


/**
 * RSL - gser#_refclk_evt_cntr
 */
typedef union bdk_gserx_refclk_evt_cntr {
	uint64_t u;
	struct bdk_gserx_refclk_evt_cntr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t count                       : 32; /**< RO - This register can only be reliably read when GSER()_REFCLK_EVT_CTRL[ENB]
                                                                 is clear.

                                                                 When GSER()_REFCLK_EVT_CTRL[CLR] is set, [COUNT] goes to zero.

                                                                 When GSER()_REFCLK_EVT_CTRL[ENB] is set, [COUNT] is incremented
                                                                 in positve edges of the QLM reference clock.

                                                                 When GSER()_REFCLK_EVT_CTRL[ENB] is not set, [COUNT] is held; this must
                                                                 be used when [COUNT] is being read for reliable results. */
#else
		uint64_t count                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_gserx_refclk_evt_cntr_s cn88xx; */
	/* struct bdk_gserx_refclk_evt_cntr_s cn88xxp1; */
} bdk_gserx_refclk_evt_cntr_t;

static inline uint64_t BDK_GSERX_REFCLK_EVT_CNTR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_REFCLK_EVT_CNTR(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000178ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_REFCLK_EVT_CNTR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_REFCLK_EVT_CNTR(...) bdk_gserx_refclk_evt_cntr_t
#define bustype_BDK_GSERX_REFCLK_EVT_CNTR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_REFCLK_EVT_CNTR(p1) (p1)
#define arguments_BDK_GSERX_REFCLK_EVT_CNTR(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_REFCLK_EVT_CNTR(...) "GSERX_REFCLK_EVT_CNTR"


/**
 * RSL - gser#_refclk_evt_ctrl
 */
typedef union bdk_gserx_refclk_evt_ctrl {
	uint64_t u;
	struct bdk_gserx_refclk_evt_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t clr                         : 1;  /**< R/W - When set, clears GSER()_REFCLK_EVT_CNTR[COUNT]. */
		uint64_t enb                         : 1;  /**< R/W - When set, enables the GSER()_REFCLK_EVT_CNTR[COUNT] to increment
                                                                 on positive edges of the QLM reference clock. */
#else
		uint64_t enb                         : 1;
		uint64_t clr                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gserx_refclk_evt_ctrl_s cn88xx; */
	/* struct bdk_gserx_refclk_evt_ctrl_s cn88xxp1; */
} bdk_gserx_refclk_evt_ctrl_t;

static inline uint64_t BDK_GSERX_REFCLK_EVT_CTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_REFCLK_EVT_CTRL(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000170ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_REFCLK_EVT_CTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_REFCLK_EVT_CTRL(...) bdk_gserx_refclk_evt_ctrl_t
#define bustype_BDK_GSERX_REFCLK_EVT_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_REFCLK_EVT_CTRL(p1) (p1)
#define arguments_BDK_GSERX_REFCLK_EVT_CTRL(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_REFCLK_EVT_CTRL(...) "GSERX_REFCLK_EVT_CTRL"


/**
 * RSL - gser#_refclk_sel
 *
 * This register selects the reference clock.
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_refclk_sel {
	uint64_t u;
	struct bdk_gserx_refclk_sel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t pcie_refclk125              : 1;  /**< R/W/H - For bootable PCIe links, this is loaded with
                                                                 PCIE0/2_REFCLK_125 at cold reset and indicates a 125 MHz reference clock when set. For
                                                                 non-bootable PCIe links, this bit is set to zero at cold reset and indicates a 100 MHz
                                                                 reference clock. It is not used for non-PCIe links. */
		uint64_t com_clk_sel                 : 1;  /**< R/W/H - When set, the reference clock is sourced from the external clock mux. For bootable PCIe
                                                                 links, this bit is loaded with the PCIEn_COM0_CLK_EN pin at cold reset. */
		uint64_t use_com1                    : 1;  /**< R/W - For non-CCPI links, this bit controls the external mux select. When set, QLMC_REF_CLK1_N/P
                                                                 are selected as the reference clock. When clear, QLMC_REF_CLK0_N/P are selected as the
                                                                 reference clock. */
#else
		uint64_t use_com1                    : 1;
		uint64_t com_clk_sel                 : 1;
		uint64_t pcie_refclk125              : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_gserx_refclk_sel_s      cn88xx; */
	/* struct bdk_gserx_refclk_sel_s      cn88xxp1; */
} bdk_gserx_refclk_sel_t;

static inline uint64_t BDK_GSERX_REFCLK_SEL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_REFCLK_SEL(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000008ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_REFCLK_SEL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_REFCLK_SEL(...) bdk_gserx_refclk_sel_t
#define bustype_BDK_GSERX_REFCLK_SEL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_REFCLK_SEL(p1) (p1)
#define arguments_BDK_GSERX_REFCLK_SEL(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_REFCLK_SEL(...) "GSERX_REFCLK_SEL"


/**
 * RSL - gser#_rx_coast
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_rx_coast {
	uint64_t u;
	struct bdk_gserx_rx_coast_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t coast                       : 4;  /**< R/W/H - For links that are not in PCIE or SATA mode (including all CCPI links), control signals to
                                                                 freeze
                                                                 the frequency of the per lane CDR in the PHY. The COAST signals are only valid in P0
                                                                 state, come up asserted and are deasserted in hardware after detecting the electrical idle
                                                                 exit (GSER()_RX_EIE_DETSTS[EIESTS]). Once the COAST signal deasserts, the CDR is
                                                                 allowed to lock. In BGX mode, the BGX MAC can also control the COAST inputs to the PHY to
                                                                 allow Auto-Negotiation for backplane Ethernet. For diagnostic use only.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t coast                       : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_rx_coast_s        cn88xx; */
	/* struct bdk_gserx_rx_coast_s        cn88xxp1; */
} bdk_gserx_rx_coast_t;

static inline uint64_t BDK_GSERX_RX_COAST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RX_COAST(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000138ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RX_COAST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RX_COAST(...) bdk_gserx_rx_coast_t
#define bustype_BDK_GSERX_RX_COAST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RX_COAST(p1) (p1)
#define arguments_BDK_GSERX_RX_COAST(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RX_COAST(...) "GSERX_RX_COAST"


/**
 * RSL - gser#_rx_eie_deten
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_rx_eie_deten {
	uint64_t u;
	struct bdk_gserx_rx_eie_deten_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t eiede                       : 4;  /**< R/W - For links that are not in PCIE or SATA mode (including all CCPI links), these bits enable
                                                                 per lane
                                                                 electrical idle exit (EIE) detection. When EIE is detected,
                                                                 GSER()_RX_EIE_DETSTS[EIELTCH] is asserted. EIEDE defaults to the enabled state. Once
                                                                 EIE has been detected, EIEDE must be disabled, and then enabled again to perform another
                                                                 EIE detection.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t eiede                       : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_rx_eie_deten_s    cn88xx; */
	/* struct bdk_gserx_rx_eie_deten_s    cn88xxp1; */
} bdk_gserx_rx_eie_deten_t;

static inline uint64_t BDK_GSERX_RX_EIE_DETEN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RX_EIE_DETEN(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000148ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RX_EIE_DETEN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RX_EIE_DETEN(...) bdk_gserx_rx_eie_deten_t
#define bustype_BDK_GSERX_RX_EIE_DETEN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RX_EIE_DETEN(p1) (p1)
#define arguments_BDK_GSERX_RX_EIE_DETEN(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RX_EIE_DETEN(...) "GSERX_RX_EIE_DETEN"


/**
 * RSL - gser#_rx_eie_detsts
 */
typedef union bdk_gserx_rx_eie_detsts {
	uint64_t u;
	struct bdk_gserx_rx_eie_detsts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t cdrlock                     : 4;  /**< RO/H - After an electrical idle exit condition (EIE) has been detected, the CDR needs 10000 UI to
                                                                 lock. During this time, there may be RX bit errors. These bits will set when the CDR is
                                                                 guaranteed to be locked. Note that link training can't start until the lane CDRLOCK is
                                                                 set. Software can use CDRLOCK to determine when to expect error free RX data.
                                                                 \<11\>: Lane 3.
                                                                 \<10\>: Lane 2.
                                                                 \<9\>: Lane 1.
                                                                 \<8\>: Lane 0. */
		uint64_t eiests                      : 4;  /**< RO/H - When electrical idle exit detection is enabled (GSER()_RX_EIE_DETEN[EIEDE] is
                                                                 asserted), indicates that an electrical idle exit condition (EIE) was detected. For higher
                                                                 data rates, the received data needs to have sufficient low frequency content (for example,
                                                                 idle symbols) for data transitions to be detected and for EIESTS to stay set accordingly.
                                                                 Under most conditions, EIESTS
                                                                 will stay asserted until GSER()_RX_EIE_DETEN[EIEDE] is deasserted.
                                                                 \<7\>: Lane 3.
                                                                 \<6\>: Lane 2.
                                                                 \<5\>: Lane 1.
                                                                 \<4\>: Lane 0. */
		uint64_t eieltch                     : 4;  /**< RO/H - When electrical idle exit detection is enabled (GSER()_RX_EIE_DETEN[EIEDE] is
                                                                 asserted), indicates that an electrical idle exit condition (EIE) was detected. Once an
                                                                 EIE condition has been detected, the per-lane EIELTCH will stay set until
                                                                 GSER()_RX_EIE_DETEN[EIEDE] is deasserted. Note that there may be RX bit errors until
                                                                 CDRLOCK
                                                                 is set.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t eieltch                     : 4;
		uint64_t eiests                      : 4;
		uint64_t cdrlock                     : 4;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_gserx_rx_eie_detsts_s   cn88xx; */
	/* struct bdk_gserx_rx_eie_detsts_s   cn88xxp1; */
} bdk_gserx_rx_eie_detsts_t;

static inline uint64_t BDK_GSERX_RX_EIE_DETSTS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RX_EIE_DETSTS(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000150ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RX_EIE_DETSTS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RX_EIE_DETSTS(...) bdk_gserx_rx_eie_detsts_t
#define bustype_BDK_GSERX_RX_EIE_DETSTS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RX_EIE_DETSTS(p1) (p1)
#define arguments_BDK_GSERX_RX_EIE_DETSTS(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RX_EIE_DETSTS(...) "GSERX_RX_EIE_DETSTS"


/**
 * RSL - gser#_rx_eie_filter
 */
typedef union bdk_gserx_rx_eie_filter {
	uint64_t u;
	struct bdk_gserx_rx_eie_filter_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t eii_filt                    : 16; /**< R/W - The GSER uses electrical idle inference to determine when a RX lane has reentered
                                                                 electrical idle (EI). The PHY electrical idle exit detection supports a minimum pulse
                                                                 width of 400ps, therefore configurations that run faster than 2.5G can indicate EI when
                                                                 the serial lines are still driven. For rates faster than 2.5G, it takes 16K * 8 UI of
                                                                 consecutive deasserted GSER()_RX_EIE_DETSTS[EIESTS] for the GSER to infer EI. In the
                                                                 event of electrical idle inference, the following happens:
                                                                 * GSER()_RX_EIE_DETSTS[CDRLOCK]\<lane\> is zeroed.
                                                                 * GSER()_RX_EIE_DETSTS[EIELTCH]\<lane\> is zeroed.
                                                                 * GSER()_RX_EIE_DETSTS[EIESTS]\<lane\> is zeroed.
                                                                 * GSER()_RX_COAST[COAST]\<lane\> is asserted to prevent the CDR from trying to lock on
                                                                 the incoming data stream.
                                                                 * GSER()_RX_EIE_DETEN[EIEDE]\<lane\> deasserts for a short period of time, and then is
                                                                 asserted to begin looking for the Electrical idle Exit condition.

                                                                 Writing this register to a non-zero value causes the electrical idle inference to use the
                                                                 EII_FILT count instead of the default settings. Each EII_FILT count represents 20 ns of
                                                                 incremental EI inference time.

                                                                 It is not expected that software will need to use the Electrical Idle Inference logic. */
#else
		uint64_t eii_filt                    : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_rx_eie_filter_s   cn88xx; */
	/* struct bdk_gserx_rx_eie_filter_s   cn88xxp1; */
} bdk_gserx_rx_eie_filter_t;

static inline uint64_t BDK_GSERX_RX_EIE_FILTER(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RX_EIE_FILTER(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000158ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RX_EIE_FILTER", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RX_EIE_FILTER(...) bdk_gserx_rx_eie_filter_t
#define bustype_BDK_GSERX_RX_EIE_FILTER(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RX_EIE_FILTER(p1) (p1)
#define arguments_BDK_GSERX_RX_EIE_FILTER(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RX_EIE_FILTER(...) "GSERX_RX_EIE_FILTER"


/**
 * RSL - gser#_rx_polarity
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_rx_polarity {
	uint64_t u;
	struct bdk_gserx_rx_polarity_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t rx_inv                      : 4;  /**< R/W - For links that are not in PCIE mode (including all CCPI links), control signal to invert
                                                                 the polarity of received data. When asserted, the polarity of the received data is
                                                                 inverted.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t rx_inv                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_rx_polarity_s     cn88xx; */
	/* struct bdk_gserx_rx_polarity_s     cn88xxp1; */
} bdk_gserx_rx_polarity_t;

static inline uint64_t BDK_GSERX_RX_POLARITY(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RX_POLARITY(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000160ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RX_POLARITY", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RX_POLARITY(...) bdk_gserx_rx_polarity_t
#define bustype_BDK_GSERX_RX_POLARITY(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RX_POLARITY(p1) (p1)
#define arguments_BDK_GSERX_RX_POLARITY(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RX_POLARITY(...) "GSERX_RX_POLARITY"


/**
 * RSL - gser#_rx_pwr_ctrl_p1
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_rx_pwr_ctrl_p1 {
	uint64_t u;
	struct bdk_gserx_rx_pwr_ctrl_p1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t p1_rx_resetn                : 1;  /**< R/W - Place the receiver in reset (active low). */
		uint64_t pq_rx_allow_pll_pd          : 1;  /**< R/W - When asserted, permit PLL powerdown (PLL is powered
                                                                 down if all other factors permit). */
		uint64_t pq_rx_pcs_reset             : 1;  /**< R/W - When asserted, the RX power state machine puts the raw PCS RX logic
                                                                 in reset state to save power. */
		uint64_t p1_rx_agc_en                : 1;  /**< R/W - AGC enable. */
		uint64_t p1_rx_dfe_en                : 1;  /**< R/W - DFE enable. */
		uint64_t p1_rx_cdr_en                : 1;  /**< R/W - CDR enable. */
		uint64_t p1_rx_cdr_coast             : 1;  /**< R/W - CDR coast; freezes the frequency of the CDR. */
		uint64_t p1_rx_cdr_clr               : 1;  /**< R/W - CDR clear; clears the frequency of the CDR. */
		uint64_t p1_rx_subblk_pd             : 5;  /**< R/W - RX sub-block powerdown controls to RX:
                                                                 \<4\> = CTLE.
                                                                 \<3\> = Reserved.
                                                                 \<2\> = Lane DLL.
                                                                 \<1\> = DFE/samplers.
                                                                 \<0\> = Termination. */
		uint64_t p1_rx_chpd                  : 1;  /**< R/W - RX lane powerdown. */
#else
		uint64_t p1_rx_chpd                  : 1;
		uint64_t p1_rx_subblk_pd             : 5;
		uint64_t p1_rx_cdr_clr               : 1;
		uint64_t p1_rx_cdr_coast             : 1;
		uint64_t p1_rx_cdr_en                : 1;
		uint64_t p1_rx_dfe_en                : 1;
		uint64_t p1_rx_agc_en                : 1;
		uint64_t pq_rx_pcs_reset             : 1;
		uint64_t pq_rx_allow_pll_pd          : 1;
		uint64_t p1_rx_resetn                : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_gserx_rx_pwr_ctrl_p1_s  cn88xx; */
	/* struct bdk_gserx_rx_pwr_ctrl_p1_s  cn88xxp1; */
} bdk_gserx_rx_pwr_ctrl_p1_t;

static inline uint64_t BDK_GSERX_RX_PWR_CTRL_P1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_RX_PWR_CTRL_P1(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E0904600B0ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_RX_PWR_CTRL_P1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_RX_PWR_CTRL_P1(...) bdk_gserx_rx_pwr_ctrl_p1_t
#define bustype_BDK_GSERX_RX_PWR_CTRL_P1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_RX_PWR_CTRL_P1(p1) (p1)
#define arguments_BDK_GSERX_RX_PWR_CTRL_P1(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_RX_PWR_CTRL_P1(...) "GSERX_RX_PWR_CTRL_P1"


/**
 * RSL - gser#_sata_lane#_tx_amp#
 *
 * SATA lane TX launch amplitude at Gen 1, 2 and 3 speeds.
 * * AMP(0) is for Gen1.
 * * AMP(1) is for Gen2.
 * * AMP(2) is for Gen3.
 */
typedef union bdk_gserx_sata_lanex_tx_ampx {
	uint64_t u;
	struct bdk_gserx_sata_lanex_tx_ampx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t tx_amp                      : 7;  /**< R/W - This status value sets the Tx driver launch amplitude in the
                                                                 case where the PHY is running at the Gen1, Gen2, and Gen3
                                                                 rates. Used for tuning at the board level for Rx eye compliance. */
#else
		uint64_t tx_amp                      : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_gserx_sata_lanex_tx_ampx_s cn88xx; */
	/* struct bdk_gserx_sata_lanex_tx_ampx_s cn88xxp1; */
} bdk_gserx_sata_lanex_tx_ampx_t;

static inline uint64_t BDK_GSERX_SATA_LANEX_TX_AMPX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SATA_LANEX_TX_AMPX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 13)) && ((param2 <= 3)) && ((param3 <= 2)))
		return 0x000087E090000B00ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x20ull + (param3 & 3) * 0x8ull;
	csr_fatal("BDK_GSERX_SATA_LANEX_TX_AMPX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_GSERX_SATA_LANEX_TX_AMPX(...) bdk_gserx_sata_lanex_tx_ampx_t
#define bustype_BDK_GSERX_SATA_LANEX_TX_AMPX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SATA_LANEX_TX_AMPX(p1,p2,p3) (p1)
#define arguments_BDK_GSERX_SATA_LANEX_TX_AMPX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_GSERX_SATA_LANEX_TX_AMPX(...) "GSERX_SATA_LANEX_TX_AMPX"


/**
 * RSL - gser#_sata_lane#_tx_preemph#
 *
 * SATA TX pre-emphasis at Gen 1, 2 and 3 speeds. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 * * PREEMPH(0) is for Gen1.
 * * PREEMPH(1) is for Gen2.
 * * PREEMPH(2) is for Gen3.
 */
typedef union bdk_gserx_sata_lanex_tx_preemphx {
	uint64_t u;
	struct bdk_gserx_sata_lanex_tx_preemphx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t tx_preemph                  : 7;  /**< R/W/H - This static value sets the Tx driver de-emphasis value in the
                                                                 case where the PHY is running at the Gen1, Gen2, and Gen3
                                                                 rates. Used for tuning at the board level for Rx eye compliance. */
#else
		uint64_t tx_preemph                  : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_gserx_sata_lanex_tx_preemphx_s cn88xx; */
	/* struct bdk_gserx_sata_lanex_tx_preemphx_s cn88xxp1; */
} bdk_gserx_sata_lanex_tx_preemphx_t;

static inline uint64_t BDK_GSERX_SATA_LANEX_TX_PREEMPHX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SATA_LANEX_TX_PREEMPHX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 13)) && ((param2 <= 3)) && ((param3 <= 2)))
		return 0x000087E090000A00ull + (param1 & 15) * 0x1000000ull + (param2 & 3) * 0x20ull + (param3 & 3) * 0x8ull;
	csr_fatal("BDK_GSERX_SATA_LANEX_TX_PREEMPHX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_GSERX_SATA_LANEX_TX_PREEMPHX(...) bdk_gserx_sata_lanex_tx_preemphx_t
#define bustype_BDK_GSERX_SATA_LANEX_TX_PREEMPHX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SATA_LANEX_TX_PREEMPHX(p1,p2,p3) (p1)
#define arguments_BDK_GSERX_SATA_LANEX_TX_PREEMPHX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_GSERX_SATA_LANEX_TX_PREEMPHX(...) "GSERX_SATA_LANEX_TX_PREEMPHX"


/**
 * RSL - gser#_sata_lane_rst
 *
 * Lane Reset Control.
 *
 */
typedef union bdk_gserx_sata_lane_rst {
	uint64_t u;
	struct bdk_gserx_sata_lane_rst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t l3_rst                      : 1;  /**< R/W - Independent reset for Lane 3. */
		uint64_t l2_rst                      : 1;  /**< R/W - Independent reset for Lane 2. */
		uint64_t l1_rst                      : 1;  /**< R/W - Independent reset for Lane 1. */
		uint64_t l0_rst                      : 1;  /**< R/W - Independent reset for Lane 0. */
#else
		uint64_t l0_rst                      : 1;
		uint64_t l1_rst                      : 1;
		uint64_t l2_rst                      : 1;
		uint64_t l3_rst                      : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_sata_lane_rst_s   cn88xx; */
	/* struct bdk_gserx_sata_lane_rst_s   cn88xxp1; */
} bdk_gserx_sata_lane_rst_t;

static inline uint64_t BDK_GSERX_SATA_LANE_RST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SATA_LANE_RST(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000908ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SATA_LANE_RST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SATA_LANE_RST(...) bdk_gserx_sata_lane_rst_t
#define bustype_BDK_GSERX_SATA_LANE_RST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SATA_LANE_RST(p1) (p1)
#define arguments_BDK_GSERX_SATA_LANE_RST(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SATA_LANE_RST(...) "GSERX_SATA_LANE_RST"


/**
 * RSL - gser#_sata_status
 *
 * SATA PHY Ready Status.
 *
 */
typedef union bdk_gserx_sata_status {
	uint64_t u;
	struct bdk_gserx_sata_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t p3_rdy                      : 1;  /**< RO/H - PHY Lane 3 is ready to send and receive data. */
		uint64_t p2_rdy                      : 1;  /**< RO/H - PHY Lane 2 is ready to send and receive data. */
		uint64_t p1_rdy                      : 1;  /**< RO/H - PHY Lane 1 is ready to send and receive data. */
		uint64_t p0_rdy                      : 1;  /**< RO/H - PHY Lane 0 is ready to send and receive data. */
#else
		uint64_t p0_rdy                      : 1;
		uint64_t p1_rdy                      : 1;
		uint64_t p2_rdy                      : 1;
		uint64_t p3_rdy                      : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_sata_status_s     cn88xx; */
	/* struct bdk_gserx_sata_status_s     cn88xxp1; */
} bdk_gserx_sata_status_t;

static inline uint64_t BDK_GSERX_SATA_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SATA_STATUS(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090100900ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SATA_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SATA_STATUS(...) bdk_gserx_sata_status_t
#define bustype_BDK_GSERX_SATA_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SATA_STATUS(p1) (p1)
#define arguments_BDK_GSERX_SATA_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SATA_STATUS(...) "GSERX_SATA_STATUS"


/**
 * RSL - gser#_sata_tx_invert
 *
 * Lane Reset Control.
 *
 */
typedef union bdk_gserx_sata_tx_invert {
	uint64_t u;
	struct bdk_gserx_sata_tx_invert_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t l3_inv                      : 1;  /**< R/W - Instructs the SATA PCS to perform a polarity inversion on the
                                                                 lane 3 transmitted data. */
		uint64_t l2_inv                      : 1;  /**< R/W - Instructs the SATA PCS to perform a polarity inversion on the
                                                                 lane 2 transmitted data. */
		uint64_t l1_inv                      : 1;  /**< R/W - Instructs the SATA PCS to perform a polarity inversion on the
                                                                 lane 1 transmitted data. */
		uint64_t l0_inv                      : 1;  /**< R/W - Instructs the SATA PCS to perform a polarity inversion on the
                                                                 lane 0 transmitted data. */
#else
		uint64_t l0_inv                      : 1;
		uint64_t l1_inv                      : 1;
		uint64_t l2_inv                      : 1;
		uint64_t l3_inv                      : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_sata_tx_invert_s  cn88xx; */
	/* struct bdk_gserx_sata_tx_invert_s  cn88xxp1; */
} bdk_gserx_sata_tx_invert_t;

static inline uint64_t BDK_GSERX_SATA_TX_INVERT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SATA_TX_INVERT(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000910ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SATA_TX_INVERT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SATA_TX_INVERT(...) bdk_gserx_sata_tx_invert_t
#define bustype_BDK_GSERX_SATA_TX_INVERT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SATA_TX_INVERT(p1) (p1)
#define arguments_BDK_GSERX_SATA_TX_INVERT(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SATA_TX_INVERT(...) "GSERX_SATA_TX_INVERT"


/**
 * RSL - gser#_scratch
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_scratch {
	uint64_t u;
	struct bdk_gserx_scratch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t scratch                     : 16; /**< R/W - General purpose scratch register. */
#else
		uint64_t scratch                     : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_scratch_s         cn88xx; */
	/* struct bdk_gserx_scratch_s         cn88xxp1; */
} bdk_gserx_scratch_t;

static inline uint64_t BDK_GSERX_SCRATCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SCRATCH(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000020ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SCRATCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SCRATCH(...) bdk_gserx_scratch_t
#define bustype_BDK_GSERX_SCRATCH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SCRATCH(p1) (p1)
#define arguments_BDK_GSERX_SCRATCH(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SCRATCH(...) "GSERX_SCRATCH"


/**
 * RSL - gser#_slice#_rx_sdll_ctrl
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_slicex_rx_sdll_ctrl {
	uint64_t u;
	struct bdk_gserx_slicex_rx_sdll_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t pcs_sds_oob_clk_ctrl        : 2;  /**< R/W/H - OOB clock oscillator output frequency selection:
                                                                 0x0 = 506 Mhz (min) 682 Mhz (typ) 782 Mhz (max).
                                                                 0x1 = 439 Mhz (min) 554 Mhz (typ) 595 Mhz (max).
                                                                 0x2 = 379 Mhz (min) 453 Mhz (typ) 482 Mhz (max).
                                                                 0x3 = 303 Mhz (min) 378 Mhz (typ) 414 Mhz (max).

                                                                 This parameter is for debugging purposes and should not
                                                                 be written in normal operation. */
		uint64_t reserved_7_13               : 7;
		uint64_t pcs_sds_rx_sdll_tune        : 3;  /**< R/W - Tuning bits for the regulator and the loop filter. */
		uint64_t pcs_sds_rx_sdll_swsel       : 4;  /**< R/W - DMON control; selects which signal is passed to the output
                                                                 of DMON.
                                                                 0x1 = dllout[0] (first output clock phase, out of 8 phases,
                                                                 of the Slice DLL).
                                                                 0x2 = dllout[1] (second output clock phase, out of 8 phases,
                                                                 of the Slice DLL).
                                                                 0x4 = piclk (output clock of the PI).
                                                                 0x8 = vdda_int.

                                                                 All other values in this field are reserved. */
#else
		uint64_t pcs_sds_rx_sdll_swsel       : 4;
		uint64_t pcs_sds_rx_sdll_tune        : 3;
		uint64_t reserved_7_13               : 7;
		uint64_t pcs_sds_oob_clk_ctrl        : 2;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_gserx_slicex_rx_sdll_ctrl_s cn88xx; */
	/* struct bdk_gserx_slicex_rx_sdll_ctrl_s cn88xxp1; */
} bdk_gserx_slicex_rx_sdll_ctrl_t;

static inline uint64_t BDK_GSERX_SLICEX_RX_SDLL_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SLICEX_RX_SDLL_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 13)) && ((param2 <= 1)))
		return 0x000087E090460220ull + (param1 & 15) * 0x1000000ull + (param2 & 1) * 0x200000ull;
	csr_fatal("BDK_GSERX_SLICEX_RX_SDLL_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SLICEX_RX_SDLL_CTRL(...) bdk_gserx_slicex_rx_sdll_ctrl_t
#define bustype_BDK_GSERX_SLICEX_RX_SDLL_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SLICEX_RX_SDLL_CTRL(p1,p2) (p1)
#define arguments_BDK_GSERX_SLICEX_RX_SDLL_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_GSERX_SLICEX_RX_SDLL_CTRL(...) "GSERX_SLICEX_RX_SDLL_CTRL"


/**
 * RSL - gser#_slice_cfg
 *
 * These registers are for diagnostic use only.
 * These registers are reset by hardware only during chip cold reset.
 * The values of the CSR fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_slice_cfg {
	uint64_t u;
	struct bdk_gserx_slice_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t tx_rx_detect_lvl_enc        : 4;  /**< R/W - Determines the RX Detect level, pcs_sds_tx_rx_detect_lvl[9:0],
                                                                 (which is a 1-hot signal), where the level is equal to to
                                                                 2^TX_RX_DETECT_LVL_ENC. */
		uint64_t reserved_6_7                : 2;
		uint64_t pcs_sds_rx_pcie_pterm       : 2;  /**< R/W - Reserved. */
		uint64_t pcs_sds_rx_pcie_nterm       : 2;  /**< R/W - Reserved. */
		uint64_t pcs_sds_tx_stress_eye       : 2;  /**< R/W - Controls TX stress eye. */
#else
		uint64_t pcs_sds_tx_stress_eye       : 2;
		uint64_t pcs_sds_rx_pcie_nterm       : 2;
		uint64_t pcs_sds_rx_pcie_pterm       : 2;
		uint64_t reserved_6_7                : 2;
		uint64_t tx_rx_detect_lvl_enc        : 4;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_gserx_slice_cfg_s       cn88xx; */
	/* struct bdk_gserx_slice_cfg_s       cn88xxp1; */
} bdk_gserx_slice_cfg_t;

static inline uint64_t BDK_GSERX_SLICE_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SLICE_CFG(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090460060ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SLICE_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SLICE_CFG(...) bdk_gserx_slice_cfg_t
#define bustype_BDK_GSERX_SLICE_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SLICE_CFG(p1) (p1)
#define arguments_BDK_GSERX_SLICE_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SLICE_CFG(...) "GSERX_SLICE_CFG"


/**
 * RSL - gser#_spd
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_spd {
	uint64_t u;
	struct bdk_gserx_spd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t spd                         : 4;  /**< R/W/H - For CCPI links (i.e. GSER8..13), the hardware loads this CSR field from the OCI_SPD\<3:0\>
                                                                 pins during chip cold reset. For non-CCPI links, this field is not used.
                                                                 For SPD settings that configure a non-default reference clock, hardware updates the PLL
                                                                 settings of the specific lane mode (LMODE) table entry to derive the correct link rate.

                                                                 \<pre\>
                                                                 SPD   REFCLK      Link rate   LMODE
                                                                 0x0:  100 MHz     1.25 Gb     R_125G_REFCLK15625_KX
                                                                 0x1:  100 MHz     2.5 Gb      R_25G_REFCLK100
                                                                 0x2:  100 MHz     5 Gb        R_5G_REFCLK100
                                                                 0x3:  100 MHz     8 Gb        R_8G_REFCLK100
                                                                 0x4:  125 MHz     1.25 Gb     R_125G_REFCLK15625_KX
                                                                 0x5:  125 MHz     2.5 Gb      R_25G_REFCLK125
                                                                 0x6:  125 MHz     3.125 Gb    R_3125G_REFCLK15625_XAUI
                                                                 0x7:  125 MHz     5 Gb        R_5G_REFCLK125
                                                                 0x8:  125 MHz     6.25 Gb     R_625G_REFCLK15625_RXAUI
                                                                 0x9:  125 MHz     8 Gb        R_8G_REFCLK125
                                                                 0xA:  156.25 MHz  2.5 Gb      R_25G_REFCLK100
                                                                 0xB:  156.25 MHz  3.125 Gb    R_3125G_REFCLK15625_XAUI
                                                                 0xC:  156.25 MHz  5 Gb        R_5G_REFCLK125
                                                                 0xD:  156.25 MHz  6.25 Gb     R_625G_REFCLK15625_RXAUI
                                                                 0xE:  156.25 MHz  10.3125 Gb  R_103125G_REFCLK15625_KR
                                                                 0xF:                          SW_MODE
                                                                 \</pre\>

                                                                 Note that a value of 0xF is called SW_MODE. The CCPI link does not come up configured in
                                                                 SW_MODE.
                                                                 (Software must do all the CCPI GSER configuration to use CCPI in the case of SW_MODE.)
                                                                 When SPD!=SW_MODE after a chip cold reset, the hardware has initialized the following
                                                                 registers (based on the OCI_SPD selection):

                                                                  * GSER()_LANE_MODE[LMODE]=Z.
                                                                  * GSER()_PLL_P()_MODE_0.
                                                                  * GSER()_PLL_P()_MODE_1.
                                                                  * GSER()_LANE_P()_MODE_0.
                                                                  * GSER()_LANE_P()_MODE_1.
                                                                  * GSER()_LANE()_RX_VALBBD_CTRL_0.
                                                                  * GSER()_LANE()_RX_VALBBD_CTRL_1.
                                                                  * GSER()_LANE()_RX_VALBBD_CTRL_2.

                                                                  where in "GSER(x)", x is 8..13, and in "P(z)", z equals LMODE. */
#else
		uint64_t spd                         : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_spd_s             cn88xx; */
	/* struct bdk_gserx_spd_s             cn88xxp1; */
} bdk_gserx_spd_t;

static inline uint64_t BDK_GSERX_SPD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SPD(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000088ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SPD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SPD(...) bdk_gserx_spd_t
#define bustype_BDK_GSERX_SPD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SPD(p1) (p1)
#define arguments_BDK_GSERX_SPD(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SPD(...) "GSERX_SPD"


/**
 * RSL - gser#_srst
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_srst {
	uint64_t u;
	struct bdk_gserx_srst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t srst                        : 1;  /**< R/W - When asserted, resets all per-lane state in the GSER with the exception of the PHY and the
                                                                 GSER()_CFG. For diagnostic use only. */
#else
		uint64_t srst                        : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gserx_srst_s            cn88xx; */
	/* struct bdk_gserx_srst_s            cn88xxp1; */
} bdk_gserx_srst_t;

static inline uint64_t BDK_GSERX_SRST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_SRST(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000090ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_SRST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_SRST(...) bdk_gserx_srst_t
#define bustype_BDK_GSERX_SRST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_SRST(p1) (p1)
#define arguments_BDK_GSERX_SRST(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_SRST(...) "GSERX_SRST"


/**
 * RSL - gser#_tx_vboost
 *
 * These registers are reset by hardware only during chip cold reset. The values of the CSR
 * fields in these registers do not change during chip warm or soft resets.
 */
typedef union bdk_gserx_tx_vboost {
	uint64_t u;
	struct bdk_gserx_tx_vboost_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t vboost                      : 4;  /**< R/W - For links that are not in PCIE mode (including all CCPI links), boosts the TX Vswing from
                                                                 VDD to 1.0 VPPD.
                                                                 \<3\>: Lane 3.
                                                                 \<2\>: Lane 2.
                                                                 \<1\>: Lane 1.
                                                                 \<0\>: Lane 0. */
#else
		uint64_t vboost                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gserx_tx_vboost_s       cn88xx; */
	/* struct bdk_gserx_tx_vboost_s       cn88xxp1; */
} bdk_gserx_tx_vboost_t;

static inline uint64_t BDK_GSERX_TX_VBOOST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_TX_VBOOST(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000130ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_TX_VBOOST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_TX_VBOOST(...) bdk_gserx_tx_vboost_t
#define bustype_BDK_GSERX_TX_VBOOST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_TX_VBOOST(p1) (p1)
#define arguments_BDK_GSERX_TX_VBOOST(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_TX_VBOOST(...) "GSERX_TX_VBOOST"


/**
 * RSL - gser#_txclk_evt_cntr
 */
typedef union bdk_gserx_txclk_evt_cntr {
	uint64_t u;
	struct bdk_gserx_txclk_evt_cntr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t count                       : 32; /**< RO - This register can only be reliably read when GSER()_TXCLK_EVT_CTRL[ENB]
                                                                 is clear.

                                                                 When GSER()_TXCLK_EVT_CTRL[CLR] is set, [COUNT] goes to zero.

                                                                 When GSER()_TXCLK_EVT_CTRL[ENB] is set, [COUNT] is incremented
                                                                 in positve edges of the QLM reference clock.

                                                                 When GSER()_TXCLK_EVT_CTRL[ENB] is not set, [COUNT] value is held;
                                                                 this must be used when [COUNT] is being read for reliable results. */
#else
		uint64_t count                       : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_gserx_txclk_evt_cntr_s  cn88xx; */
	/* struct bdk_gserx_txclk_evt_cntr_s  cn88xxp1; */
} bdk_gserx_txclk_evt_cntr_t;

static inline uint64_t BDK_GSERX_TXCLK_EVT_CNTR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_TXCLK_EVT_CNTR(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000188ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_TXCLK_EVT_CNTR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_TXCLK_EVT_CNTR(...) bdk_gserx_txclk_evt_cntr_t
#define bustype_BDK_GSERX_TXCLK_EVT_CNTR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_TXCLK_EVT_CNTR(p1) (p1)
#define arguments_BDK_GSERX_TXCLK_EVT_CNTR(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_TXCLK_EVT_CNTR(...) "GSERX_TXCLK_EVT_CNTR"


/**
 * RSL - gser#_txclk_evt_ctrl
 */
typedef union bdk_gserx_txclk_evt_ctrl {
	uint64_t u;
	struct bdk_gserx_txclk_evt_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t clr                         : 1;  /**< R/W - When set, clears GSER()_TXCLK_EVT_CNTR[COUNT]. */
		uint64_t enb                         : 1;  /**< R/W - When set, enables the GSER()_TXCLK_EVT_CNTR[COUNT] to increment
                                                                 on positive edges of the QLM reference clock. */
#else
		uint64_t enb                         : 1;
		uint64_t clr                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_gserx_txclk_evt_ctrl_s  cn88xx; */
	/* struct bdk_gserx_txclk_evt_ctrl_s  cn88xxp1; */
} bdk_gserx_txclk_evt_ctrl_t;

static inline uint64_t BDK_GSERX_TXCLK_EVT_CTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GSERX_TXCLK_EVT_CTRL(unsigned long param1)
{
	if (((param1 <= 13)))
		return 0x000087E090000180ull + (param1 & 15) * 0x1000000ull;
	csr_fatal("BDK_GSERX_TXCLK_EVT_CTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GSERX_TXCLK_EVT_CTRL(...) bdk_gserx_txclk_evt_ctrl_t
#define bustype_BDK_GSERX_TXCLK_EVT_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_GSERX_TXCLK_EVT_CTRL(p1) (p1)
#define arguments_BDK_GSERX_TXCLK_EVT_CTRL(p1) (p1),-1,-1,-1
#define basename_BDK_GSERX_TXCLK_EVT_CTRL(...) "GSERX_TXCLK_EVT_CTRL"

#endif /* __BDK_CSRS_GSER__ */
