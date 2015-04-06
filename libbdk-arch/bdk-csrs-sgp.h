#ifndef __BDK_CSRS_SGP__
#define __BDK_CSRS_SGP__
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
 * Cavium SGP.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration SGP_TX_ACT_E
 *
 * SGPIO Transmit Activity Enumeration
 * Enumerates the values of SGP_TX(0..3)[ACT].
 */
enum sgp_tx_act_e {
	SGP_TX_ACT_E_A_OFF_ON = 0x3,
	SGP_TX_ACT_E_A_ON_OFF = 0x2,
	SGP_TX_ACT_E_BRIEF_END = 0x4,
	SGP_TX_ACT_E_BRIEF_START = 0x5,
	SGP_TX_ACT_E_B_OFF_ON = 0x7,
	SGP_TX_ACT_E_B_ON_OFF = 0x6,
	SGP_TX_ACT_E_STATIC_OFF = 0x0,
	SGP_TX_ACT_E_STATIC_ON = 0x1,
	SGP_TX_ACT_E_ENUM_LAST = 0x8,
};

/**
 * Enumeration SGP_TX_ERR_E
 *
 * SGPIO Transmit Error Enumeration
 * Enumerates the values of SGP_TX(0..3)[ERR].
 */
enum sgp_tx_err_e {
	SGP_TX_ERR_E_A_OFF_ON = 0x3,
	SGP_TX_ERR_E_A_ON_OFF = 0x2,
	SGP_TX_ERR_E_B_OFF_ON = 0x7,
	SGP_TX_ERR_E_B_ON_OFF = 0x6,
	SGP_TX_ERR_E_STATIC_OFF = 0x0,
	SGP_TX_ERR_E_STATIC_ON = 0x1,
	SGP_TX_ERR_E_STATIC_ON4 = 0x4,
	SGP_TX_ERR_E_STATIC_ON5 = 0x5,
	SGP_TX_ERR_E_ENUM_LAST = 0x8,
};

/**
 * Enumeration SGP_TX_LOC_E
 *
 * SGPIO Transmit Locate Enumeration
 * Enumerates the values of SGP_TX(0..3)[LOC].
 */
enum sgp_tx_loc_e {
	SGP_TX_LOC_E_A_OFF_ON = 0x3,
	SGP_TX_LOC_E_A_ON_OFF = 0x2,
	SGP_TX_LOC_E_STATIC_OFF = 0x0,
	SGP_TX_LOC_E_STATIC_ON = 0x1,
	SGP_TX_LOC_E_ENUM_LAST = 0x4,
};



/**
 * RSL32b - sgp_cfg0
 */
typedef union bdk_sgp_cfg0 {
	uint32_t u;
	struct bdk_sgp_cfg0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t drive_cnt                   : 8;  /**< RO - Number of supported drives. INTERNAL: Corresponds to SATA(0..15). */
		uint32_t gp_cnt                      : 4;  /**< RO - Number of general purpose data registers. */
		uint32_t cfg_cnt                     : 3;  /**< RO - Number of configuration registers. */
		uint32_t ena                         : 1;  /**< R/W - SGPIO enable. Enables the SGPIO inputs and outputs. When zero the bus is not driven,
                                                                 inputs are zero, and shifts do not occur. A change from enabled to disabled does not take
                                                                 effect until the current bit-stream has completed. */
		uint32_t ver                         : 4;  /**< RO - Version. */
		uint32_t reserved_0_11               : 12;
#else
		uint32_t reserved_0_11               : 12;
		uint32_t ver                         : 4;
		uint32_t ena                         : 1;
		uint32_t cfg_cnt                     : 3;
		uint32_t gp_cnt                      : 4;
		uint32_t drive_cnt                   : 8;
#endif
	} s;
	/* struct bdk_sgp_cfg0_s              cn88xx; */
	/* struct bdk_sgp_cfg0_s              cn88xxp1; */
} bdk_sgp_cfg0_t;

#define BDK_SGP_CFG0 BDK_SGP_CFG0_FUNC()
static inline uint64_t BDK_SGP_CFG0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_CFG0_FUNC(void)
{
	return 0x000087E027000000ull;
}
#define typedef_BDK_SGP_CFG0 bdk_sgp_cfg0_t
#define bustype_BDK_SGP_CFG0 BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_CFG0 0
#define arguments_BDK_SGP_CFG0 -1,-1,-1,-1
#define basename_BDK_SGP_CFG0 "SGP_CFG0"


/**
 * RSL32b - sgp_cfg1
 */
typedef union bdk_sgp_cfg1 {
	uint32_t u;
	struct bdk_sgp_cfg1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t blink_b                     : 4;  /**< R/W - Blink generator rate B. */
		uint32_t blink_a                     : 4;  /**< R/W - Blink generator rate A:
                                                                 0x0 = 1/8 second.
                                                                 0x1 = 2/8 second.
                                                                 ...
                                                                 0xF = 16/8 seconds. */
		uint32_t force_off                   : 4;  /**< R/W - Force activity off time. The minimum amount of time to disable the activity indicator if
                                                                 it has been continually enabled for the [MAX_ON] time, and the SGP_TX(0..3)[*_ACT] is
                                                                 0x4 or 0x5.
                                                                 0x0 = No minimum.
                                                                 0x1 = 1/8 second.
                                                                 ...
                                                                 0xF = 15/8 seconds. */
		uint32_t max_on                      : 4;  /**< R/W - Maximum activity on time. The maximum amount of time to enable the activity indicator if
                                                                 SGP_TX(0..3)[*_ACT] is 0x4 or 0x5. Note all drives will not reach the MAX_ON time
                                                                 simultaneously, the pattern will appear somewhat random.
                                                                 0x0 = No maximum.
                                                                 0x1 = 1/8 second.
                                                                 ...
                                                                 0xF = 15/8 seconds. */
		uint32_t stretch_off                 : 4;  /**< R/W - Stretch activity off. The minimum amount of time to disable the activity indicator if
                                                                 SGP_TX(0..3)[*_ACT] is 0x4 or 0x5.
                                                                 0x0 = No minimum.
                                                                 0x1 = 1/8 second.
                                                                 ...
                                                                 0xF = 15/8 seconds. */
		uint32_t stretch_on                  : 4;  /**< R/W - Stretch activity on. The minimum amount of time to enable the activity indicator if
                                                                 SGP_TX(0..3)[*_ACT] is 0x4 or 0x5.
                                                                 0x0 = 1/64 second.
                                                                 0x1 = 2/64 second.
                                                                 ...
                                                                 0xF = 16/64 seconds. */
#else
		uint32_t stretch_on                  : 4;
		uint32_t stretch_off                 : 4;
		uint32_t max_on                      : 4;
		uint32_t force_off                   : 4;
		uint32_t blink_a                     : 4;
		uint32_t blink_b                     : 4;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_sgp_cfg1_s              cn88xx; */
	/* struct bdk_sgp_cfg1_s              cn88xxp1; */
} bdk_sgp_cfg1_t;

#define BDK_SGP_CFG1 BDK_SGP_CFG1_FUNC()
static inline uint64_t BDK_SGP_CFG1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_CFG1_FUNC(void)
{
	return 0x000087E027000004ull;
}
#define typedef_BDK_SGP_CFG1 bdk_sgp_cfg1_t
#define bustype_BDK_SGP_CFG1 BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_CFG1 0
#define arguments_BDK_SGP_CFG1 -1,-1,-1,-1
#define basename_BDK_SGP_CFG1 "SGP_CFG1"


/**
 * RSL32b - sgp_imp_clk
 */
typedef union bdk_sgp_imp_clk {
	uint32_t u;
	struct bdk_sgp_imp_clk_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_27_31              : 5;
		uint32_t div                         : 27; /**< R/W - SClock divisor. Number of coprocessor clock cycles per GPIO_SCLOCK. May only be changed
                                                                 when SGP_CFG0[ENA] and SGP_IMP_CTL[BUSY] are clear. Should be
                                                                 programmed to yield a frequency between 32 Hz and 100 kHz; reset value assumes a
                                                                 coprocessor clock of 800 MHz and a SGPIO_SCLOCK of 100 KHz. */
#else
		uint32_t div                         : 27;
		uint32_t reserved_27_31              : 5;
#endif
	} s;
	/* struct bdk_sgp_imp_clk_s           cn88xx; */
	/* struct bdk_sgp_imp_clk_s           cn88xxp1; */
} bdk_sgp_imp_clk_t;

#define BDK_SGP_IMP_CLK BDK_SGP_IMP_CLK_FUNC()
static inline uint64_t BDK_SGP_IMP_CLK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_IMP_CLK_FUNC(void)
{
	return 0x000087E027030010ull;
}
#define typedef_BDK_SGP_IMP_CLK bdk_sgp_imp_clk_t
#define bustype_BDK_SGP_IMP_CLK BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_IMP_CLK 0
#define arguments_BDK_SGP_IMP_CLK -1,-1,-1,-1
#define basename_BDK_SGP_IMP_CLK "SGP_IMP_CLK"


/**
 * RSL32b - sgp_imp_ctl
 */
typedef union bdk_sgp_imp_ctl {
	uint32_t u;
	struct bdk_sgp_imp_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_5_31               : 27;
		uint32_t datains                     : 3;  /**< R/W - Number of SGP_SDATAIN connections:
                                                                 0x0 = No SGP_SDATAIN, all input shift data will be zero.
                                                                 0x1 = SGP_SDATAIN(0) for drives 0-15.
                                                                 0x2 = SGP_SDATAIN(0) for drives 0-7, (1) for drives 8-15.
                                                                 0x3 = SGP_SDATAIN(0) for drives 0-3, (1) for drives 4-7, (2) for drives 8-11, (3) for
                                                                 drives 12-15.
                                                                 0x4-0x7 = Reserved */
		uint32_t hold                        : 1;  /**< R/W - Hold shift. When set, automatic shifts will not occur, and the SGP_TX_GP_CFG[COUNT] must
                                                                 be used to initiate a shift operation. */
		uint32_t busy                        : 1;  /**< RO/H - Shift in progress. */
#else
		uint32_t busy                        : 1;
		uint32_t hold                        : 1;
		uint32_t datains                     : 3;
		uint32_t reserved_5_31               : 27;
#endif
	} s;
	/* struct bdk_sgp_imp_ctl_s           cn88xx; */
	/* struct bdk_sgp_imp_ctl_s           cn88xxp1; */
} bdk_sgp_imp_ctl_t;

#define BDK_SGP_IMP_CTL BDK_SGP_IMP_CTL_FUNC()
static inline uint64_t BDK_SGP_IMP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_IMP_CTL_FUNC(void)
{
	return 0x000087E027030000ull;
}
#define typedef_BDK_SGP_IMP_CTL bdk_sgp_imp_ctl_t
#define bustype_BDK_SGP_IMP_CTL BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_IMP_CTL 0
#define arguments_BDK_SGP_IMP_CTL -1,-1,-1,-1
#define basename_BDK_SGP_IMP_CTL "SGP_IMP_CTL"


/**
 * RSL32b - sgp_imp_drive#
 */
typedef union bdk_sgp_imp_drivex {
	uint32_t u;
	struct bdk_sgp_imp_drivex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t pres_det                    : 1;  /**< R/W - "Presence detect. If set, logically OR GPIO_SDATAIN's ID\#.0 bit with any GPIO related
                                                                 present detect and send to the relevant SATA controller's mechanical presence detect." */
		uint32_t reserved_4_7                : 4;
		uint32_t ctrlr                       : 4;  /**< R/W - SATA controller attached to this index's SGPIO drive. Indicates which SATA(0..15) connects
                                                                 to the corresponding indexed SGPIO drive 0..15. Resets to the index number; controller 0
                                                                 for drive 0, controller 1 for drive 1, etc.

                                                                 If SGP_TX()[D0_ACT]..[D3_ACT] = BRIEF_START or BRIEF_END, the activity input will come
                                                                 from SATA controller number [CTRLR].  Else, the activity indication is controlled by
                                                                 software alone.

                                                                 If [PRES_DET] is set, SATA controller number [CTRL] will receive the index'ed drive's
                                                                 presence detect. */
#else
		uint32_t ctrlr                       : 4;
		uint32_t reserved_4_7                : 4;
		uint32_t pres_det                    : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_sgp_imp_drivex_s        cn88xx; */
	/* struct bdk_sgp_imp_drivex_s        cn88xxp1; */
} bdk_sgp_imp_drivex_t;

static inline uint64_t BDK_SGP_IMP_DRIVEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_IMP_DRIVEX(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000087E027040000ull + (param1 & 15) * 0x8ull;
	csr_fatal("BDK_SGP_IMP_DRIVEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SGP_IMP_DRIVEX(...) bdk_sgp_imp_drivex_t
#define bustype_BDK_SGP_IMP_DRIVEX(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_IMP_DRIVEX(p1) (p1)
#define arguments_BDK_SGP_IMP_DRIVEX(p1) (p1),-1,-1,-1
#define basename_BDK_SGP_IMP_DRIVEX(...) "SGP_IMP_DRIVEX"


/**
 * RSL32b - sgp_imp_sec_clk
 */
typedef union bdk_sgp_imp_sec_clk {
	uint32_t u;
	struct bdk_sgp_imp_sec_clk_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t div                         : 16; /**< R/W - SClock seconds divisor. Number of GPIO_SCLOCKs per 1/64th second. May only be changed when
                                                                 SGP_CFG0[ENA] and SGP_IMP_CTL[BUSY] are clear. Should be
                                                                 programmed to yield a frequency of 64 Hz; reset value assumes GPIO_SCLOCK of 100 kHz. */
#else
		uint32_t div                         : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_sgp_imp_sec_clk_s       cn88xx; */
	/* struct bdk_sgp_imp_sec_clk_s       cn88xxp1; */
} bdk_sgp_imp_sec_clk_t;

#define BDK_SGP_IMP_SEC_CLK BDK_SGP_IMP_SEC_CLK_FUNC()
static inline uint64_t BDK_SGP_IMP_SEC_CLK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_IMP_SEC_CLK_FUNC(void)
{
	return 0x000087E027030020ull;
}
#define typedef_BDK_SGP_IMP_SEC_CLK bdk_sgp_imp_sec_clk_t
#define bustype_BDK_SGP_IMP_SEC_CLK BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_IMP_SEC_CLK 0
#define arguments_BDK_SGP_IMP_SEC_CLK -1,-1,-1,-1
#define basename_BDK_SGP_IMP_SEC_CLK "SGP_IMP_SEC_CLK"


/**
 * RSL32b - sgp_rx#
 */
typedef union bdk_sgp_rxx {
	uint32_t u;
	struct bdk_sgp_rxx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_27_31              : 5;
		uint32_t rx3                         : 3;  /**< RO/H - Three bits received on SGP_SDATAIN corresponding to drive 3+4*index. */
		uint32_t reserved_19_23              : 5;
		uint32_t rx2                         : 3;  /**< RO/H - Three bits received on SGP_SDATAIN corresponding to drive 2+4*index. */
		uint32_t reserved_11_15              : 5;
		uint32_t rx1                         : 3;  /**< RO/H - Three bits received on SGP_SDATAIN corresponding to drive 1+4*index. */
		uint32_t reserved_3_7                : 5;
		uint32_t rx0                         : 3;  /**< RO/H - Three bits received on SGP_SDATAIN corresponding to drive 0+4*index. */
#else
		uint32_t rx0                         : 3;
		uint32_t reserved_3_7                : 5;
		uint32_t rx1                         : 3;
		uint32_t reserved_11_15              : 5;
		uint32_t rx2                         : 3;
		uint32_t reserved_19_23              : 5;
		uint32_t rx3                         : 3;
		uint32_t reserved_27_31              : 5;
#endif
	} s;
	/* struct bdk_sgp_rxx_s               cn88xx; */
	/* struct bdk_sgp_rxx_s               cn88xxp1; */
} bdk_sgp_rxx_t;

static inline uint64_t BDK_SGP_RXX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_RXX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E027000400ull + (param1 & 3) * 0x4ull;
	csr_fatal("BDK_SGP_RXX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SGP_RXX(...) bdk_sgp_rxx_t
#define bustype_BDK_SGP_RXX(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_RXX(p1) (p1)
#define arguments_BDK_SGP_RXX(p1) (p1),-1,-1,-1
#define basename_BDK_SGP_RXX(...) "SGP_RXX"


/**
 * RSL32b - sgp_rx_gp#
 */
typedef union bdk_sgp_rx_gpx {
	uint32_t u;
	struct bdk_sgp_rx_gpx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t sdatain3                    : 8;  /**< RO/H - See [SDATAIN0]. */
		uint32_t sdatain2                    : 8;  /**< RO/H - See [SDATAIN0]. */
		uint32_t sdatain1                    : 8;  /**< RO/H - See [SDATAIN0]. */
		uint32_t sdatain0                    : 8;  /**< RO/H - Raw data shifted from SGP_SDATAIN. The bits are not in natural 32-bit form; they are
                                                                 assigned to registers as follows:
                                                                 Bit 0 (ID0.0): SGP_RX_GP(1)[SDATAIN3]\<0\>.
                                                                 Bit 8 (ID2.2): SGP_RX_GP(1)[SDATAIN2]\<0\>.
                                                                 Bit 16 (ID5.1): SGP_RX_GP(1)[SDATAIN1]\<0\>.
                                                                 Bit 24 (ID8.0): SGP_RX_GP(1)[SDATAIN0]\<0\>.
                                                                 Bit 32 (ID10.2): SGP_RX_GP(2)[SDATAIN3]\<0\>.
                                                                 Bit 40 (ID13.1): SGP_RX_GP(2)[SDATAIN2]\<0\>.
                                                                 Bit 47 (ID15.2): SGP_RX_GP(2)[SDATAIN2]\<7\>.
                                                                 SGP_RX_GP(2)[SDATAIN1/SDATAIN0] are always zero. */
#else
		uint32_t sdatain0                    : 8;
		uint32_t sdatain1                    : 8;
		uint32_t sdatain2                    : 8;
		uint32_t sdatain3                    : 8;
#endif
	} s;
	/* struct bdk_sgp_rx_gpx_s            cn88xx; */
	/* struct bdk_sgp_rx_gpx_s            cn88xxp1; */
} bdk_sgp_rx_gpx_t;

static inline uint64_t BDK_SGP_RX_GPX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_RX_GPX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 2))))
		return 0x000087E027000800ull + (param1 & 3) * 0x4ull;
	csr_fatal("BDK_SGP_RX_GPX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SGP_RX_GPX(...) bdk_sgp_rx_gpx_t
#define bustype_BDK_SGP_RX_GPX(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_RX_GPX(p1) (p1)
#define arguments_BDK_SGP_RX_GPX(p1) (p1),-1,-1,-1
#define basename_BDK_SGP_RX_GPX(...) "SGP_RX_GPX"


/**
 * RSL32b - sgp_rx_gp_cfg
 */
typedef union bdk_sgp_rx_gp_cfg {
	uint32_t u;
	struct bdk_sgp_rx_gp_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t count                       : 8;  /**< RO/H - Number of repetitions remaining. A [COUNT] of 0xFF indicates infinite repetitions are remaining. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t count                       : 8;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_sgp_rx_gp_cfg_s         cn88xx; */
	/* struct bdk_sgp_rx_gp_cfg_s         cn88xxp1; */
} bdk_sgp_rx_gp_cfg_t;

#define BDK_SGP_RX_GP_CFG BDK_SGP_RX_GP_CFG_FUNC()
static inline uint64_t BDK_SGP_RX_GP_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_RX_GP_CFG_FUNC(void)
{
	return 0x000087E027000800ull;
}
#define typedef_BDK_SGP_RX_GP_CFG bdk_sgp_rx_gp_cfg_t
#define bustype_BDK_SGP_RX_GP_CFG BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_RX_GP_CFG 0
#define arguments_BDK_SGP_RX_GP_CFG -1,-1,-1,-1
#define basename_BDK_SGP_RX_GP_CFG "SGP_RX_GP_CFG"


/**
 * RSL32b - sgp_tx#
 */
typedef union bdk_sgp_txx {
	uint32_t u;
	struct bdk_sgp_txx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t d3_act                      : 3;  /**< R/W - Drive 3+4*index's activity state. */
		uint32_t d3_loc                      : 2;  /**< R/W - Drive 3+4*index's locate state. */
		uint32_t d3_err                      : 3;  /**< R/W - Drive 3+4*index's error state. */
		uint32_t d2_act                      : 3;  /**< R/W - Drive 2+4*index's activity state. */
		uint32_t d2_loc                      : 2;  /**< R/W - Drive 2+4*index's locate state. */
		uint32_t d2_err                      : 3;  /**< R/W - Drive 2+4*index's error state. */
		uint32_t d1_act                      : 3;  /**< R/W - Drive 1+4*index's activity state. */
		uint32_t d1_loc                      : 2;  /**< R/W - Drive 1+4*index's locate state. */
		uint32_t d1_err                      : 3;  /**< R/W - Drive 1+4*index's error state. */
		uint32_t d0_act                      : 3;  /**< R/W - Drive 0+4*index's activity state, enumerated by SGP_TX_ACT_E. */
		uint32_t d0_loc                      : 2;  /**< R/W - Drive 0+4*index's locate state, enumerated by SGP_TX_LOC_E. */
		uint32_t d0_err                      : 3;  /**< R/W - Drive 0+4*index's error state, enumerated by SGP_TX_ERR_E. */
#else
		uint32_t d0_err                      : 3;
		uint32_t d0_loc                      : 2;
		uint32_t d0_act                      : 3;
		uint32_t d1_err                      : 3;
		uint32_t d1_loc                      : 2;
		uint32_t d1_act                      : 3;
		uint32_t d2_err                      : 3;
		uint32_t d2_loc                      : 2;
		uint32_t d2_act                      : 3;
		uint32_t d3_err                      : 3;
		uint32_t d3_loc                      : 2;
		uint32_t d3_act                      : 3;
#endif
	} s;
	/* struct bdk_sgp_txx_s               cn88xx; */
	/* struct bdk_sgp_txx_s               cn88xxp1; */
} bdk_sgp_txx_t;

static inline uint64_t BDK_SGP_TXX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_TXX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E027000C00ull + (param1 & 3) * 0x4ull;
	csr_fatal("BDK_SGP_TXX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SGP_TXX(...) bdk_sgp_txx_t
#define bustype_BDK_SGP_TXX(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_TXX(p1) (p1)
#define arguments_BDK_SGP_TXX(p1) (p1),-1,-1,-1
#define basename_BDK_SGP_TXX(...) "SGP_TXX"


/**
 * RSL32b - sgp_tx_gp#
 */
typedef union bdk_sgp_tx_gpx {
	uint32_t u;
	struct bdk_sgp_tx_gpx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t sdataout3                   : 8;  /**< R/W - See [SDATAOUT0]. */
		uint32_t sdataout2                   : 8;  /**< R/W - See [SDATAOUT0]. */
		uint32_t sdataout1                   : 8;  /**< R/W - See [SDATAOUT0]. */
		uint32_t sdataout0                   : 8;  /**< R/W - Raw data to shift onto SGP_SDATAOUT. The bits are not in natural 32-bit form; they are
                                                                 assigned to registers as follows:
                                                                 Bit 0 (ID0.0): SGP_TX_GP(1)[SDATAOUT3]\<0\>.
                                                                 Bit 8 (ID2.2): SGP_TX_GP(1)[SDATAOUT2]\<0\>.
                                                                 Bit 16 (ID5.1): SGP_TX_GP(1)[SDATAOUT1]\<0\>.
                                                                 Bit 24 (ID8.0): SGP_TX_GP(1)[SDATAOUT0]\<0\>.
                                                                 Bit 32 (ID10.2): SGP_TX_GP(2)[SDATAOUT3]\<0\>.
                                                                 Bit 40 (ID13.1): SGP_TX_GP(2)[SDATAOUT2]\<0\>.
                                                                 Bit 47 (ID15.2): SGP_TX_GP(2)[SDATAOUT2]\<7\>.
                                                                 SGP_TX_GP(2)[SDATAOUT1/SDATAOUT0] are ignored. */
#else
		uint32_t sdataout0                   : 8;
		uint32_t sdataout1                   : 8;
		uint32_t sdataout2                   : 8;
		uint32_t sdataout3                   : 8;
#endif
	} s;
	/* struct bdk_sgp_tx_gpx_s            cn88xx; */
	/* struct bdk_sgp_tx_gpx_s            cn88xxp1; */
} bdk_sgp_tx_gpx_t;

static inline uint64_t BDK_SGP_TX_GPX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_TX_GPX(unsigned long param1)
{
	if ((((param1 >= 1) && (param1 <= 2))))
		return 0x000087E027001000ull + (param1 & 3) * 0x4ull;
	csr_fatal("BDK_SGP_TX_GPX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SGP_TX_GPX(...) bdk_sgp_tx_gpx_t
#define bustype_BDK_SGP_TX_GPX(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_TX_GPX(p1) (p1)
#define arguments_BDK_SGP_TX_GPX(p1) (p1),-1,-1,-1
#define basename_BDK_SGP_TX_GPX(...) "SGP_TX_GPX"


/**
 * RSL32b - sgp_tx_gp_cfg
 */
typedef union bdk_sgp_tx_gp_cfg {
	uint32_t u;
	struct bdk_sgp_tx_gp_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_28_31              : 4;
		uint32_t sload                       : 4;  /**< R/W - Pattern to transmit on SGP_SLOAD at the start of each general purpose bit stream.
                                                                 [SLOAD]\<0\> is the first bit (L0), \<3\> is the last bit (L3). */
		uint32_t count                       : 8;  /**< R/W - Number of times to transmit the SGP_TX_GP(1..2) pattern and receive
                                                                 into SGP_RX_GP(1..2). A [COUNT] of 0xFF transmits continuously until [COUNT] is set to
                                                                 non-0xFF. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t count                       : 8;
		uint32_t sload                       : 4;
		uint32_t reserved_28_31              : 4;
#endif
	} s;
	/* struct bdk_sgp_tx_gp_cfg_s         cn88xx; */
	/* struct bdk_sgp_tx_gp_cfg_s         cn88xxp1; */
} bdk_sgp_tx_gp_cfg_t;

#define BDK_SGP_TX_GP_CFG BDK_SGP_TX_GP_CFG_FUNC()
static inline uint64_t BDK_SGP_TX_GP_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SGP_TX_GP_CFG_FUNC(void)
{
	return 0x000087E027001000ull;
}
#define typedef_BDK_SGP_TX_GP_CFG bdk_sgp_tx_gp_cfg_t
#define bustype_BDK_SGP_TX_GP_CFG BDK_CSR_TYPE_RSL32b
#define busnum_BDK_SGP_TX_GP_CFG 0
#define arguments_BDK_SGP_TX_GP_CFG -1,-1,-1,-1
#define basename_BDK_SGP_TX_GP_CFG "SGP_TX_GP_CFG"

#endif /* __BDK_CSRS_SGP__ */
