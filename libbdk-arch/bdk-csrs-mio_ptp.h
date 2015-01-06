#ifndef __BDK_CSRS_MIO_PTP__
#define __BDK_CSRS_MIO_PTP__
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
 * Cavium MIO_PTP.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration MIO_PTP_EXT_SEL_E
 *
 * External sources Select Enumeration
 * Enumerates the different external signal sources for PTP.
 * Note that CCPI reference clocks cannot be selected.
 */
enum mio_ptp_ext_sel_e {
	MIO_PTP_EXT_SEL_E_GPIO0 = 0x0,
	MIO_PTP_EXT_SEL_E_GPIO1 = 0x1,
	MIO_PTP_EXT_SEL_E_GPIO10 = 0xa,
	MIO_PTP_EXT_SEL_E_GPIO11 = 0xb,
	MIO_PTP_EXT_SEL_E_GPIO12 = 0xc,
	MIO_PTP_EXT_SEL_E_GPIO13 = 0xd,
	MIO_PTP_EXT_SEL_E_GPIO14 = 0xe,
	MIO_PTP_EXT_SEL_E_GPIO15 = 0xf,
	MIO_PTP_EXT_SEL_E_GPIO16 = 0x10,
	MIO_PTP_EXT_SEL_E_GPIO17 = 0x11,
	MIO_PTP_EXT_SEL_E_GPIO18 = 0x12,
	MIO_PTP_EXT_SEL_E_GPIO19 = 0x13,
	MIO_PTP_EXT_SEL_E_GPIO2 = 0x2,
	MIO_PTP_EXT_SEL_E_GPIO20 = 0x14,
	MIO_PTP_EXT_SEL_E_GPIO21 = 0x15,
	MIO_PTP_EXT_SEL_E_GPIO22 = 0x16,
	MIO_PTP_EXT_SEL_E_GPIO23 = 0x17,
	MIO_PTP_EXT_SEL_E_GPIO24 = 0x18,
	MIO_PTP_EXT_SEL_E_GPIO25 = 0x19,
	MIO_PTP_EXT_SEL_E_GPIO26 = 0x1a,
	MIO_PTP_EXT_SEL_E_GPIO27 = 0x1b,
	MIO_PTP_EXT_SEL_E_GPIO28 = 0x1c,
	MIO_PTP_EXT_SEL_E_GPIO29 = 0x1d,
	MIO_PTP_EXT_SEL_E_GPIO3 = 0x3,
	MIO_PTP_EXT_SEL_E_GPIO30 = 0x1e,
	MIO_PTP_EXT_SEL_E_GPIO31 = 0x1f,
	MIO_PTP_EXT_SEL_E_GPIO32 = 0x20,
	MIO_PTP_EXT_SEL_E_GPIO33 = 0x21,
	MIO_PTP_EXT_SEL_E_GPIO34 = 0x22,
	MIO_PTP_EXT_SEL_E_GPIO35 = 0x23,
	MIO_PTP_EXT_SEL_E_GPIO36 = 0x24,
	MIO_PTP_EXT_SEL_E_GPIO37 = 0x25,
	MIO_PTP_EXT_SEL_E_GPIO38 = 0x26,
	MIO_PTP_EXT_SEL_E_GPIO39 = 0x27,
	MIO_PTP_EXT_SEL_E_GPIO4 = 0x4,
	MIO_PTP_EXT_SEL_E_GPIO40 = 0x28,
	MIO_PTP_EXT_SEL_E_GPIO41 = 0x29,
	MIO_PTP_EXT_SEL_E_GPIO42 = 0x2a,
	MIO_PTP_EXT_SEL_E_GPIO43 = 0x2b,
	MIO_PTP_EXT_SEL_E_GPIO44 = 0x2c,
	MIO_PTP_EXT_SEL_E_GPIO45 = 0x2d,
	MIO_PTP_EXT_SEL_E_GPIO46 = 0x2e,
	MIO_PTP_EXT_SEL_E_GPIO47 = 0x2f,
	MIO_PTP_EXT_SEL_E_GPIO48 = 0x30,
	MIO_PTP_EXT_SEL_E_GPIO49 = 0x31,
	MIO_PTP_EXT_SEL_E_GPIO5 = 0x5,
	MIO_PTP_EXT_SEL_E_GPIO50 = 0x32,
	MIO_PTP_EXT_SEL_E_GPIO6 = 0x6,
	MIO_PTP_EXT_SEL_E_GPIO7 = 0x7,
	MIO_PTP_EXT_SEL_E_GPIO8 = 0x8,
	MIO_PTP_EXT_SEL_E_GPIO9 = 0x9,
	MIO_PTP_EXT_SEL_E_QLM_REF0 = 0x38,
	MIO_PTP_EXT_SEL_E_QLM_REF1 = 0x39,
	MIO_PTP_EXT_SEL_E_QLM_REF2 = 0x3a,
	MIO_PTP_EXT_SEL_E_QLM_REF3 = 0x3b,
	MIO_PTP_EXT_SEL_E_QLM_REF4 = 0x3c,
	MIO_PTP_EXT_SEL_E_QLM_REF5 = 0x3d,
	MIO_PTP_EXT_SEL_E_QLM_REF6 = 0x3e,
	MIO_PTP_EXT_SEL_E_QLM_REF7 = 0x3f,
	MIO_PTP_EXT_SEL_E_ENUM_LAST = 0x40,
};

/**
 * Enumeration MIO_PTP_INT_VEC_E
 *
 * PTP MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum mio_ptp_int_vec_e {
	MIO_PTP_INT_VEC_E_DPLL_INT = 0x1,
	MIO_PTP_INT_VEC_E_EVT_INT = 0x0,
	MIO_PTP_INT_VEC_E_ENUM_LAST = 0x2,
};



/**
 * NCB - mio_ptp_ckout_hi_incr
 *
 * This register contains the PTP CKOUT threshold increment on pre-inverted PTP_CKOUT rising
 * edge. See MIO_PTP_CKOUT_THRESH_HI for details.
 */
typedef union bdk_mio_ptp_ckout_hi_incr {
	uint64_t u;
	struct bdk_mio_ptp_ckout_hi_incr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 32; /**< R/W - Nanoseconds. */
		uint64_t frnanosec                   : 32; /**< R/W - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t nanosec                     : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_ckout_hi_incr_s cn88xx; */
	/* struct bdk_mio_ptp_ckout_hi_incr_s cn88xxp1; */
} bdk_mio_ptp_ckout_hi_incr_t;

#define BDK_MIO_PTP_CKOUT_HI_INCR BDK_MIO_PTP_CKOUT_HI_INCR_FUNC()
static inline uint64_t BDK_MIO_PTP_CKOUT_HI_INCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CKOUT_HI_INCR_FUNC(void)
{
	return 0x0000807000000F40ull;
}
#define typedef_BDK_MIO_PTP_CKOUT_HI_INCR bdk_mio_ptp_ckout_hi_incr_t
#define bustype_BDK_MIO_PTP_CKOUT_HI_INCR BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CKOUT_HI_INCR 0
#define arguments_BDK_MIO_PTP_CKOUT_HI_INCR -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CKOUT_HI_INCR "MIO_PTP_CKOUT_HI_INCR"


/**
 * NCB - mio_ptp_ckout_lo_incr
 *
 * This register contains the PTP CKOUTthreshold increment on pre-inverted PTP_CKOUT falling
 * edge. See MIO_PTP_CKOUT_THRESH_HI for details.
 */
typedef union bdk_mio_ptp_ckout_lo_incr {
	uint64_t u;
	struct bdk_mio_ptp_ckout_lo_incr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 32; /**< R/W - Nanoseconds. */
		uint64_t frnanosec                   : 32; /**< R/W - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t nanosec                     : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_ckout_lo_incr_s cn88xx; */
	/* struct bdk_mio_ptp_ckout_lo_incr_s cn88xxp1; */
} bdk_mio_ptp_ckout_lo_incr_t;

#define BDK_MIO_PTP_CKOUT_LO_INCR BDK_MIO_PTP_CKOUT_LO_INCR_FUNC()
static inline uint64_t BDK_MIO_PTP_CKOUT_LO_INCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CKOUT_LO_INCR_FUNC(void)
{
	return 0x0000807000000F48ull;
}
#define typedef_BDK_MIO_PTP_CKOUT_LO_INCR bdk_mio_ptp_ckout_lo_incr_t
#define bustype_BDK_MIO_PTP_CKOUT_LO_INCR BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CKOUT_LO_INCR 0
#define arguments_BDK_MIO_PTP_CKOUT_LO_INCR -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CKOUT_LO_INCR "MIO_PTP_CKOUT_LO_INCR"


/**
 * NCB - mio_ptp_ckout_thresh_hi
 *
 * This register contains the high bytes of the PTP CKOUT threshold.
 * Writes to MIO_PTP_CKOUT_THRESH_HI also clear MIO_PTP_CKOUT_THRESH_LO; in order to update all
 * 96 bits, writes MIO_PTP_CKOUT_THRESH_HI followed by MIO_PTP_CKOUT_THRESH_LO.
 * This threshold {MIO_PTP_CKOUT_THRESH_HI,  MIO_PTP_CKOUT_THRESH_LO} is a rolling threshold that
 * will be updated by hardware:
 *   When current PTP_CKOUT before inversion (defined by MIO_PTP_CLOCK_CFG[CKOUT_INV]) is zero,
 *   and {MIO_PTP_CLOCK_HI/LO} \>= {MIO_PTP_CKOUT_THRESH_HI/LO}, the pre-inverted PTP_CKOUT will
 *   update to one, and {MIO_PTP_CKOUT_THRESH_HI/LO} will increment by MIO_PTP_CKOUT_HI_INCR.
 *   When current PTP_CKOUT before inversion (defined by MIO_PTP_CLOCK_CFG[CKOUT_INV]) is one,
 *   and {MIO_PTP_CLOCK_HI/LO} \>= {MIO_PTP_CKOUT_THRESH_HI/LO}, the pre-inverted PTP_CKOUT will
 *   update to zero, and {MIO_PTP_CKOUT_THRESH_HI/LO} will increment by MIO_PTP_CKOUT_LO_INCR.
 */
typedef union bdk_mio_ptp_ckout_thresh_hi {
	uint64_t u;
	struct bdk_mio_ptp_ckout_thresh_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 64; /**< R/W/H - Nanoseconds. */
#else
		uint64_t nanosec                     : 64;
#endif
	} s;
	/* struct bdk_mio_ptp_ckout_thresh_hi_s cn88xx; */
	/* struct bdk_mio_ptp_ckout_thresh_hi_s cn88xxp1; */
} bdk_mio_ptp_ckout_thresh_hi_t;

#define BDK_MIO_PTP_CKOUT_THRESH_HI BDK_MIO_PTP_CKOUT_THRESH_HI_FUNC()
static inline uint64_t BDK_MIO_PTP_CKOUT_THRESH_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CKOUT_THRESH_HI_FUNC(void)
{
	return 0x0000807000000F38ull;
}
#define typedef_BDK_MIO_PTP_CKOUT_THRESH_HI bdk_mio_ptp_ckout_thresh_hi_t
#define bustype_BDK_MIO_PTP_CKOUT_THRESH_HI BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CKOUT_THRESH_HI 0
#define arguments_BDK_MIO_PTP_CKOUT_THRESH_HI -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CKOUT_THRESH_HI "MIO_PTP_CKOUT_THRESH_HI"


/**
 * NCB - mio_ptp_ckout_thresh_lo
 *
 * This register contains the low bytes of the PTP CKOUT threshold,
 * See MIO_PTP_CKOUT_THRESH_HI for details.
 */
typedef union bdk_mio_ptp_ckout_thresh_lo {
	uint64_t u;
	struct bdk_mio_ptp_ckout_thresh_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t frnanosec                   : 32; /**< R/W/H - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_ckout_thresh_lo_s cn88xx; */
	/* struct bdk_mio_ptp_ckout_thresh_lo_s cn88xxp1; */
} bdk_mio_ptp_ckout_thresh_lo_t;

#define BDK_MIO_PTP_CKOUT_THRESH_LO BDK_MIO_PTP_CKOUT_THRESH_LO_FUNC()
static inline uint64_t BDK_MIO_PTP_CKOUT_THRESH_LO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CKOUT_THRESH_LO_FUNC(void)
{
	return 0x0000807000000F30ull;
}
#define typedef_BDK_MIO_PTP_CKOUT_THRESH_LO bdk_mio_ptp_ckout_thresh_lo_t
#define bustype_BDK_MIO_PTP_CKOUT_THRESH_LO BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CKOUT_THRESH_LO 0
#define arguments_BDK_MIO_PTP_CKOUT_THRESH_LO -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CKOUT_THRESH_LO "MIO_PTP_CKOUT_THRESH_LO"


/**
 * NCB - mio_ptp_clock_cfg
 *
 * This register configures the timestamp architecture. See MIO_PTP Registers for address
 *
 */
typedef union bdk_mio_ptp_clock_cfg {
	uint64_t u;
	struct bdk_mio_ptp_clock_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t ckout                       : 1;  /**< RO/H - PTP CKOUT; reflects ptp__ckout after CKOUT_INV inverter. */
		uint64_t pps                         : 1;  /**< RO/H - PTP PPS output; reflects ptp__pps after PPS_INV inverter. */
		uint64_t ext_clk_edge                : 2;  /**< R/W - External clock input edge:
                                                                 00 = Rising edge.
                                                                 01 = Falling edge.
                                                                 10 = Both rising and falling edge.
                                                                 11 = Reserved. */
		uint64_t reserved_32_37              : 6;
		uint64_t pps_inv                     : 1;  /**< R/W - Invert PTP PPS.
                                                                 0 = Don't invert.
                                                                 1 = Invert. */
		uint64_t pps_en                      : 1;  /**< R/W - Enable PTP PPS. (For output pin selection see GPIO_BIT_CFG.) */
		uint64_t reserved_26_29              : 4;
		uint64_t ckout_inv                   : 1;  /**< R/W - Invert PTP CKOUT.
                                                                 0 = Don't invert.
                                                                 1 = Invert. */
		uint64_t ckout_en                    : 1;  /**< R/W - Enable PTP CKOUT. (For output pin selection see GPIO_BIT_CFG.) */
		uint64_t evcnt_in                    : 6;  /**< R/W - Source for event counter input:
                                                                 Enumerated by MIO_PTP_EXT_SEL_E. */
		uint64_t evcnt_edge                  : 1;  /**< R/W - Event counter input edge: 0 = falling edge, 1 = rising edge */
		uint64_t evcnt_en                    : 1;  /**< R/W - Enable event counter. */
		uint64_t tstmp_in                    : 6;  /**< R/W - Source for timestamp input:
                                                                 Enumerated by MIO_PTP_EXT_SEL_E. */
		uint64_t tstmp_edge                  : 1;  /**< R/W - External timestamp input edge: 0 = falling edge, 1 = rising edge */
		uint64_t tstmp_en                    : 1;  /**< R/W - Enable external timestamp. */
		uint64_t ext_clk_in                  : 6;  /**< R/W - Source for external clock when EXT_CLK_EN is set:
                                                                 Enumerated by MIO_PTP_EXT_SEL_E. */
		uint64_t ext_clk_en                  : 1;  /**< R/W - Use external clock for PTP clock. */
		uint64_t ptp_en                      : 1;  /**< R/W - Enable PTP module. */
#else
		uint64_t ptp_en                      : 1;
		uint64_t ext_clk_en                  : 1;
		uint64_t ext_clk_in                  : 6;
		uint64_t tstmp_en                    : 1;
		uint64_t tstmp_edge                  : 1;
		uint64_t tstmp_in                    : 6;
		uint64_t evcnt_en                    : 1;
		uint64_t evcnt_edge                  : 1;
		uint64_t evcnt_in                    : 6;
		uint64_t ckout_en                    : 1;
		uint64_t ckout_inv                   : 1;
		uint64_t reserved_26_29              : 4;
		uint64_t pps_en                      : 1;
		uint64_t pps_inv                     : 1;
		uint64_t reserved_32_37              : 6;
		uint64_t ext_clk_edge                : 2;
		uint64_t pps                         : 1;
		uint64_t ckout                       : 1;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_mio_ptp_clock_cfg_s     cn88xx; */
	/* struct bdk_mio_ptp_clock_cfg_s     cn88xxp1; */
} bdk_mio_ptp_clock_cfg_t;

#define BDK_MIO_PTP_CLOCK_CFG BDK_MIO_PTP_CLOCK_CFG_FUNC()
static inline uint64_t BDK_MIO_PTP_CLOCK_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CLOCK_CFG_FUNC(void)
{
	return 0x0000807000000F00ull;
}
#define typedef_BDK_MIO_PTP_CLOCK_CFG bdk_mio_ptp_clock_cfg_t
#define bustype_BDK_MIO_PTP_CLOCK_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CLOCK_CFG 0
#define arguments_BDK_MIO_PTP_CLOCK_CFG -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CLOCK_CFG "MIO_PTP_CLOCK_CFG"


/**
 * NCB - mio_ptp_clock_comp
 *
 * This register provides the amount to increment the PTP clock {MIO_PTP_CLOCK_HI,
 * MIO_PTP_CLOCK_LO}
 * on PTP events defined by MIO_PTP_CLOCK_CFG[EXT_CLK_EN/EXT_CLK_IN/EXT_CLK_EDGE].
 * MIO_PTP_CLOCK_CFG[PTP_EN] needs to be enabled before writing this register.
 */
typedef union bdk_mio_ptp_clock_comp {
	uint64_t u;
	struct bdk_mio_ptp_clock_comp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 32; /**< R/W - Compensation value in nanoseconds. */
		uint64_t frnanosec                   : 32; /**< R/W - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t nanosec                     : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_clock_comp_s    cn88xx; */
	/* struct bdk_mio_ptp_clock_comp_s    cn88xxp1; */
} bdk_mio_ptp_clock_comp_t;

#define BDK_MIO_PTP_CLOCK_COMP BDK_MIO_PTP_CLOCK_COMP_FUNC()
static inline uint64_t BDK_MIO_PTP_CLOCK_COMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CLOCK_COMP_FUNC(void)
{
	return 0x0000807000000F18ull;
}
#define typedef_BDK_MIO_PTP_CLOCK_COMP bdk_mio_ptp_clock_comp_t
#define bustype_BDK_MIO_PTP_CLOCK_COMP BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CLOCK_COMP 0
#define arguments_BDK_MIO_PTP_CLOCK_COMP -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CLOCK_COMP "MIO_PTP_CLOCK_COMP"


/**
 * NCB - mio_ptp_clock_hi
 *
 * This register provides bits\<95:32\> of the PTP clock. Writes to MIO_PTP_CLOCK_HI also clear
 * MIO_PTP_CLOCK_LO. To update all 96 bits, write MIO_PTP_CLOCK_HI followed by MIO_PTP_CLOCK_LO.
 * MIO_PTP_CLOCK_CFG[PTP_EN] needs to be enabled before writing this register.
 */
typedef union bdk_mio_ptp_clock_hi {
	uint64_t u;
	struct bdk_mio_ptp_clock_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 64; /**< R/W/H - Clock value in nanoseconds. Bits\<95:32\> of the PTP clock. */
#else
		uint64_t nanosec                     : 64;
#endif
	} s;
	/* struct bdk_mio_ptp_clock_hi_s      cn88xx; */
	/* struct bdk_mio_ptp_clock_hi_s      cn88xxp1; */
} bdk_mio_ptp_clock_hi_t;

#define BDK_MIO_PTP_CLOCK_HI BDK_MIO_PTP_CLOCK_HI_FUNC()
static inline uint64_t BDK_MIO_PTP_CLOCK_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CLOCK_HI_FUNC(void)
{
	return 0x0000807000000F10ull;
}
#define typedef_BDK_MIO_PTP_CLOCK_HI bdk_mio_ptp_clock_hi_t
#define bustype_BDK_MIO_PTP_CLOCK_HI BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CLOCK_HI 0
#define arguments_BDK_MIO_PTP_CLOCK_HI -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CLOCK_HI "MIO_PTP_CLOCK_HI"


/**
 * NCB - mio_ptp_clock_lo
 *
 * This register provides bits\<31:0\> of the PTP clock.  MIO_PTP_CLOCK_CFG[PTP_EN] needs to be
 * enabled before writing this register.
 */
typedef union bdk_mio_ptp_clock_lo {
	uint64_t u;
	struct bdk_mio_ptp_clock_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t frnanosec                   : 32; /**< R/W/H - Fractions of nanoseconds. Bits\<31:0\> of the PTP clock. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_clock_lo_s      cn88xx; */
	/* struct bdk_mio_ptp_clock_lo_s      cn88xxp1; */
} bdk_mio_ptp_clock_lo_t;

#define BDK_MIO_PTP_CLOCK_LO BDK_MIO_PTP_CLOCK_LO_FUNC()
static inline uint64_t BDK_MIO_PTP_CLOCK_LO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_CLOCK_LO_FUNC(void)
{
	return 0x0000807000000F08ull;
}
#define typedef_BDK_MIO_PTP_CLOCK_LO bdk_mio_ptp_clock_lo_t
#define bustype_BDK_MIO_PTP_CLOCK_LO BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_CLOCK_LO 0
#define arguments_BDK_MIO_PTP_CLOCK_LO -1,-1,-1,-1
#define basename_BDK_MIO_PTP_CLOCK_LO "MIO_PTP_CLOCK_LO"


/**
 * NCB - mio_ptp_dpll_err_int
 *
 * This register contains the Digital PLL error event.
 *
 */
typedef union bdk_mio_ptp_dpll_err_int {
	uint64_t u;
	struct bdk_mio_ptp_dpll_err_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t n_sclk                      : 32; /**< RO/H - Latest number of coprocessor clocks in one external reference signal compensation period
                                                                 (MIO_PTP_CLOCK_COMP). */
		uint64_t reserved_0_31               : 32;
#else
		uint64_t reserved_0_31               : 32;
		uint64_t n_sclk                      : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_dpll_err_int_s  cn88xx; */
	/* struct bdk_mio_ptp_dpll_err_int_s  cn88xxp1; */
} bdk_mio_ptp_dpll_err_int_t;

#define BDK_MIO_PTP_DPLL_ERR_INT BDK_MIO_PTP_DPLL_ERR_INT_FUNC()
static inline uint64_t BDK_MIO_PTP_DPLL_ERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_DPLL_ERR_INT_FUNC(void)
{
	return 0x0000807000000F90ull;
}
#define typedef_BDK_MIO_PTP_DPLL_ERR_INT bdk_mio_ptp_dpll_err_int_t
#define bustype_BDK_MIO_PTP_DPLL_ERR_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_DPLL_ERR_INT 0
#define arguments_BDK_MIO_PTP_DPLL_ERR_INT -1,-1,-1,-1
#define basename_BDK_MIO_PTP_DPLL_ERR_INT "MIO_PTP_DPLL_ERR_INT"


/**
 * NCB - mio_ptp_dpll_err_thresh
 *
 * This register configures the Digital PLL error interrupt.
 *
 */
typedef union bdk_mio_ptp_dpll_err_thresh {
	uint64_t u;
	struct bdk_mio_ptp_dpll_err_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t max                         : 32; /**< R/W - Highest acceptable value of MIO_PTP_DPLL_ERR_INT[N_SCLK] without asserting DPLL_INT interrupt. */
		uint64_t min                         : 32; /**< R/W - Lowest acceptable value of MIO_PTP_DPLL_ERR_INT[N_SCLK] without asserting DPLL_INT interrupt. */
#else
		uint64_t min                         : 32;
		uint64_t max                         : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_dpll_err_thresh_s cn88xx; */
	/* struct bdk_mio_ptp_dpll_err_thresh_s cn88xxp1; */
} bdk_mio_ptp_dpll_err_thresh_t;

#define BDK_MIO_PTP_DPLL_ERR_THRESH BDK_MIO_PTP_DPLL_ERR_THRESH_FUNC()
static inline uint64_t BDK_MIO_PTP_DPLL_ERR_THRESH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_DPLL_ERR_THRESH_FUNC(void)
{
	return 0x0000807000000F88ull;
}
#define typedef_BDK_MIO_PTP_DPLL_ERR_THRESH bdk_mio_ptp_dpll_err_thresh_t
#define bustype_BDK_MIO_PTP_DPLL_ERR_THRESH BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_DPLL_ERR_THRESH 0
#define arguments_BDK_MIO_PTP_DPLL_ERR_THRESH -1,-1,-1,-1
#define basename_BDK_MIO_PTP_DPLL_ERR_THRESH "MIO_PTP_DPLL_ERR_THRESH"


/**
 * NCB - mio_ptp_dpll_incr
 *
 * This register contains the Digital PLL increment on each coprocessor clock rising edge.
 * Zero disables the digital PLL.
 */
typedef union bdk_mio_ptp_dpll_incr {
	uint64_t u;
	struct bdk_mio_ptp_dpll_incr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 32; /**< R/W - Nanoseconds. */
		uint64_t frnanosec                   : 32; /**< R/W - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t nanosec                     : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_dpll_incr_s     cn88xx; */
	/* struct bdk_mio_ptp_dpll_incr_s     cn88xxp1; */
} bdk_mio_ptp_dpll_incr_t;

#define BDK_MIO_PTP_DPLL_INCR BDK_MIO_PTP_DPLL_INCR_FUNC()
static inline uint64_t BDK_MIO_PTP_DPLL_INCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_DPLL_INCR_FUNC(void)
{
	return 0x0000807000000F80ull;
}
#define typedef_BDK_MIO_PTP_DPLL_INCR bdk_mio_ptp_dpll_incr_t
#define bustype_BDK_MIO_PTP_DPLL_INCR BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_DPLL_INCR 0
#define arguments_BDK_MIO_PTP_DPLL_INCR -1,-1,-1,-1
#define basename_BDK_MIO_PTP_DPLL_INCR "MIO_PTP_DPLL_INCR"


/**
 * NCB - mio_ptp_evt_cnt
 *
 * This register contains the PTP event counter.
 *
 */
typedef union bdk_mio_ptp_evt_cnt {
	uint64_t u;
	struct bdk_mio_ptp_evt_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cntr                        : 64; /**< R/W/H - PTP event counter. Writing to this register increments this register by the value of the
                                                                 write data. The register counts down by 1 for every MIO_PTP_CLOCK_CFG[EVCNT_EDGE] edge of
                                                                 MIO_PTP_CLOCK_CFG[EVCNT_IN]. When this register equals 0, an interrupt is generated.
                                                                 When this register equals 0 and PTP Event still enabled (MIO_PTP_CLOCK_CFG[EVCNT_EN]),
                                                                 the counter will rollover to negative to continue counting down whenever new event comes. */
#else
		uint64_t cntr                        : 64;
#endif
	} s;
	/* struct bdk_mio_ptp_evt_cnt_s       cn88xx; */
	/* struct bdk_mio_ptp_evt_cnt_s       cn88xxp1; */
} bdk_mio_ptp_evt_cnt_t;

#define BDK_MIO_PTP_EVT_CNT BDK_MIO_PTP_EVT_CNT_FUNC()
static inline uint64_t BDK_MIO_PTP_EVT_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_EVT_CNT_FUNC(void)
{
	return 0x0000807000000F28ull;
}
#define typedef_BDK_MIO_PTP_EVT_CNT bdk_mio_ptp_evt_cnt_t
#define bustype_BDK_MIO_PTP_EVT_CNT BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_EVT_CNT 0
#define arguments_BDK_MIO_PTP_EVT_CNT -1,-1,-1,-1
#define basename_BDK_MIO_PTP_EVT_CNT "MIO_PTP_EVT_CNT"


/**
 * NCB - mio_ptp_int
 *
 * This register contains the PTP interrupts.
 *
 */
typedef union bdk_mio_ptp_int {
	uint64_t u;
	struct bdk_mio_ptp_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t dpll_int                    : 1;  /**< R/W1C/H - Digital PLL error. */
		uint64_t evt_int                     : 1;  /**< R/W1C/H - PTP event observed. See MIO_PTP_EVT_CNT for details. */
#else
		uint64_t evt_int                     : 1;
		uint64_t dpll_int                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_ptp_int_s           cn88xx; */
	/* struct bdk_mio_ptp_int_s           cn88xxp1; */
} bdk_mio_ptp_int_t;

#define BDK_MIO_PTP_INT BDK_MIO_PTP_INT_FUNC()
static inline uint64_t BDK_MIO_PTP_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_INT_FUNC(void)
{
	return 0x0000807000000F70ull;
}
#define typedef_BDK_MIO_PTP_INT bdk_mio_ptp_int_t
#define bustype_BDK_MIO_PTP_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_INT 0
#define arguments_BDK_MIO_PTP_INT -1,-1,-1,-1
#define basename_BDK_MIO_PTP_INT "MIO_PTP_INT"


/**
 * NCB - mio_ptp_int_ena_w1c
 */
typedef union bdk_mio_ptp_int_ena_w1c {
	uint64_t u;
	struct bdk_mio_ptp_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t dpll_int                    : 1;  /**< R/W1C/H - Digital PLL error. */
		uint64_t evt_int                     : 1;  /**< R/W1C/H - PTP event observed. See MIO_PTP_EVT_CNT for details. */
#else
		uint64_t evt_int                     : 1;
		uint64_t dpll_int                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_ptp_int_ena_w1c_s   cn88xx; */
	/* struct bdk_mio_ptp_int_ena_w1c_s   cn88xxp1; */
} bdk_mio_ptp_int_ena_w1c_t;

#define BDK_MIO_PTP_INT_ENA_W1C BDK_MIO_PTP_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_MIO_PTP_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_INT_ENA_W1C_FUNC(void)
{
	return 0x0000807000000FA0ull;
}
#define typedef_BDK_MIO_PTP_INT_ENA_W1C bdk_mio_ptp_int_ena_w1c_t
#define bustype_BDK_MIO_PTP_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_INT_ENA_W1C 0
#define arguments_BDK_MIO_PTP_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_MIO_PTP_INT_ENA_W1C "MIO_PTP_INT_ENA_W1C"


/**
 * NCB - mio_ptp_int_ena_w1s
 */
typedef union bdk_mio_ptp_int_ena_w1s {
	uint64_t u;
	struct bdk_mio_ptp_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t dpll_int                    : 1;  /**< R/W1C/H - Digital PLL error. */
		uint64_t evt_int                     : 1;  /**< R/W1C/H - PTP event observed. See MIO_PTP_EVT_CNT for details. */
#else
		uint64_t evt_int                     : 1;
		uint64_t dpll_int                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_ptp_int_ena_w1s_s   cn88xx; */
	/* struct bdk_mio_ptp_int_ena_w1s_s   cn88xxp1; */
} bdk_mio_ptp_int_ena_w1s_t;

#define BDK_MIO_PTP_INT_ENA_W1S BDK_MIO_PTP_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_MIO_PTP_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_INT_ENA_W1S_FUNC(void)
{
	return 0x0000807000000FA8ull;
}
#define typedef_BDK_MIO_PTP_INT_ENA_W1S bdk_mio_ptp_int_ena_w1s_t
#define bustype_BDK_MIO_PTP_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_INT_ENA_W1S 0
#define arguments_BDK_MIO_PTP_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_MIO_PTP_INT_ENA_W1S "MIO_PTP_INT_ENA_W1S"


/**
 * NCB - mio_ptp_int_w1s
 */
typedef union bdk_mio_ptp_int_w1s {
	uint64_t u;
	struct bdk_mio_ptp_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t dpll_int                    : 1;  /**< R/W1C/H - Digital PLL error. */
		uint64_t evt_int                     : 1;  /**< R/W1C/H - PTP event observed. See MIO_PTP_EVT_CNT for details. */
#else
		uint64_t evt_int                     : 1;
		uint64_t dpll_int                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_ptp_int_w1s_s       cn88xx; */
	/* struct bdk_mio_ptp_int_w1s_s       cn88xxp1; */
} bdk_mio_ptp_int_w1s_t;

#define BDK_MIO_PTP_INT_W1S BDK_MIO_PTP_INT_W1S_FUNC()
static inline uint64_t BDK_MIO_PTP_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_INT_W1S_FUNC(void)
{
	return 0x0000807000000F78ull;
}
#define typedef_BDK_MIO_PTP_INT_W1S bdk_mio_ptp_int_w1s_t
#define bustype_BDK_MIO_PTP_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_INT_W1S 0
#define arguments_BDK_MIO_PTP_INT_W1S -1,-1,-1,-1
#define basename_BDK_MIO_PTP_INT_W1S "MIO_PTP_INT_W1S"


/**
 * NCB - mio_ptp_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the MIO_PTP_INT_VEC_E
 * enumeration.
 */
typedef union bdk_mio_ptp_msix_pbax {
	uint64_t u;
	struct bdk_mio_ptp_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO - Pending message for the associated MIO_PTP_MSIX_VEC()_CTL, enumerated by
                                                                 MIO_PTP_INT_VEC_E. Bits
                                                                 that have no associated MIO_PTP_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_mio_ptp_msix_pbax_s     cn88xx; */
	/* struct bdk_mio_ptp_msix_pbax_s     cn88xxp1; */
} bdk_mio_ptp_msix_pbax_t;

static inline uint64_t BDK_MIO_PTP_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000807000FF0000ull;
	csr_fatal("BDK_MIO_PTP_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_PTP_MSIX_PBAX(...) bdk_mio_ptp_msix_pbax_t
#define bustype_BDK_MIO_PTP_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_MSIX_PBAX(p1) (p1)
#define arguments_BDK_MIO_PTP_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_PTP_MSIX_PBAX(...) "MIO_PTP_MSIX_PBAX"


/**
 * NCB - mio_ptp_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the MIO_PTP_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mio_ptp_msix_vecx_addr {
	uint64_t u;
	struct bdk_mio_ptp_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's MIO_PTP_MSIX_VEC()_ADDR, MIO_PTP_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of MIO_PTP_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.
                                                                 If PCCPF_MIO_PTP_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_mio_ptp_msix_vecx_addr_s cn88xx; */
	/* struct bdk_mio_ptp_msix_vecx_addr_s cn88xxp1; */
} bdk_mio_ptp_msix_vecx_addr_t;

static inline uint64_t BDK_MIO_PTP_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000807000F00000ull + (param1 & 1) * 0x10ull;
	csr_fatal("BDK_MIO_PTP_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_PTP_MSIX_VECX_ADDR(...) bdk_mio_ptp_msix_vecx_addr_t
#define bustype_BDK_MIO_PTP_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_MIO_PTP_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_PTP_MSIX_VECX_ADDR(...) "MIO_PTP_MSIX_VECX_ADDR"


/**
 * NCB - mio_ptp_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the MIO_PTP_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mio_ptp_msix_vecx_ctl {
	uint64_t u;
	struct bdk_mio_ptp_msix_vecx_ctl_s {
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
	/* struct bdk_mio_ptp_msix_vecx_ctl_s cn88xx; */
	/* struct bdk_mio_ptp_msix_vecx_ctl_s cn88xxp1; */
} bdk_mio_ptp_msix_vecx_ctl_t;

static inline uint64_t BDK_MIO_PTP_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000807000F00008ull + (param1 & 1) * 0x10ull;
	csr_fatal("BDK_MIO_PTP_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_PTP_MSIX_VECX_CTL(...) bdk_mio_ptp_msix_vecx_ctl_t
#define bustype_BDK_MIO_PTP_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_MIO_PTP_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_PTP_MSIX_VECX_CTL(...) "MIO_PTP_MSIX_VECX_CTL"


/**
 * NCB - mio_ptp_pps_hi_incr
 *
 * This register contains the PTP PPS threshold increment on pre-inverted PTP_PPS rising edge.
 * See MIO_PTP_PPS_THRESH_HI for details.
 */
typedef union bdk_mio_ptp_pps_hi_incr {
	uint64_t u;
	struct bdk_mio_ptp_pps_hi_incr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 32; /**< R/W - Nanoseconds. */
		uint64_t frnanosec                   : 32; /**< R/W - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t nanosec                     : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_pps_hi_incr_s   cn88xx; */
	/* struct bdk_mio_ptp_pps_hi_incr_s   cn88xxp1; */
} bdk_mio_ptp_pps_hi_incr_t;

#define BDK_MIO_PTP_PPS_HI_INCR BDK_MIO_PTP_PPS_HI_INCR_FUNC()
static inline uint64_t BDK_MIO_PTP_PPS_HI_INCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_PPS_HI_INCR_FUNC(void)
{
	return 0x0000807000000F60ull;
}
#define typedef_BDK_MIO_PTP_PPS_HI_INCR bdk_mio_ptp_pps_hi_incr_t
#define bustype_BDK_MIO_PTP_PPS_HI_INCR BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_PPS_HI_INCR 0
#define arguments_BDK_MIO_PTP_PPS_HI_INCR -1,-1,-1,-1
#define basename_BDK_MIO_PTP_PPS_HI_INCR "MIO_PTP_PPS_HI_INCR"


/**
 * NCB - mio_ptp_pps_lo_incr
 *
 * This register contains the PTP PPS threshold increment on pre-inverted PTP_PPS falling edge.
 * See MIO_PTP_PPS_THRESH_HI for details.
 */
typedef union bdk_mio_ptp_pps_lo_incr {
	uint64_t u;
	struct bdk_mio_ptp_pps_lo_incr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 32; /**< R/W - Nanoseconds. */
		uint64_t frnanosec                   : 32; /**< R/W - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t nanosec                     : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_pps_lo_incr_s   cn88xx; */
	/* struct bdk_mio_ptp_pps_lo_incr_s   cn88xxp1; */
} bdk_mio_ptp_pps_lo_incr_t;

#define BDK_MIO_PTP_PPS_LO_INCR BDK_MIO_PTP_PPS_LO_INCR_FUNC()
static inline uint64_t BDK_MIO_PTP_PPS_LO_INCR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_PPS_LO_INCR_FUNC(void)
{
	return 0x0000807000000F68ull;
}
#define typedef_BDK_MIO_PTP_PPS_LO_INCR bdk_mio_ptp_pps_lo_incr_t
#define bustype_BDK_MIO_PTP_PPS_LO_INCR BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_PPS_LO_INCR 0
#define arguments_BDK_MIO_PTP_PPS_LO_INCR -1,-1,-1,-1
#define basename_BDK_MIO_PTP_PPS_LO_INCR "MIO_PTP_PPS_LO_INCR"


/**
 * NCB - mio_ptp_pps_thresh_hi
 *
 * This register contains the high bytes of the PTP PPS threshold.
 * Writes to MIO_PTP_PPS_THRESH_HI also clear MIO_PTP_PPS_THRESH_LO; in order to update all 96
 * bits, writes MIO_PTP_PPS_THRESH_HI followed by MIO_PTP_PPS_THRESH_LO.
 * This threshold {MIO_PTP_PPS_THRESH_HI, MIO_PTP_PPS_THRESH_LO}  is a rolling threshold that
 * will be updated by hardware:
 *   When current PTP_PPS before inversion (defined by MIO_PTP_CLOCK_CFG[PPS_INV]) is zero,
 *   and {MIO_PTP_CLOCK_HI/LO} \>=  {MIO_PTP_PPS_THRESH_HI/LO}, the pre-inverted PTP_PPS will
 *   update to one, and {MIO_PTP_PPS_THRESH_HI/LO} will increment by MIO_PTP_PPS_HI_INCR.
 *   When current PTP_PPS before inversion (defined by MIO_PTP_CLOCK_CFG[PPS_INV]) is one,
 *   and {MIO_PTP_CLOCK_HI/LO} \>=  {MIO_PTP_PPS_THRESH_HI/LO}, the pre-inverted PTP_PPS will
 *   update to zero, and {MIO_PTP_PPS_THRESH_HI/LO} will increment by MIO_PTP_PPS_LO_INCR.
 */
typedef union bdk_mio_ptp_pps_thresh_hi {
	uint64_t u;
	struct bdk_mio_ptp_pps_thresh_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 64; /**< R/W/H - Nanoseconds. */
#else
		uint64_t nanosec                     : 64;
#endif
	} s;
	/* struct bdk_mio_ptp_pps_thresh_hi_s cn88xx; */
	/* struct bdk_mio_ptp_pps_thresh_hi_s cn88xxp1; */
} bdk_mio_ptp_pps_thresh_hi_t;

#define BDK_MIO_PTP_PPS_THRESH_HI BDK_MIO_PTP_PPS_THRESH_HI_FUNC()
static inline uint64_t BDK_MIO_PTP_PPS_THRESH_HI_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_PPS_THRESH_HI_FUNC(void)
{
	return 0x0000807000000F58ull;
}
#define typedef_BDK_MIO_PTP_PPS_THRESH_HI bdk_mio_ptp_pps_thresh_hi_t
#define bustype_BDK_MIO_PTP_PPS_THRESH_HI BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_PPS_THRESH_HI 0
#define arguments_BDK_MIO_PTP_PPS_THRESH_HI -1,-1,-1,-1
#define basename_BDK_MIO_PTP_PPS_THRESH_HI "MIO_PTP_PPS_THRESH_HI"


/**
 * NCB - mio_ptp_pps_thresh_lo
 *
 * This register contains the low bytes of the PTP PPS threshold.
 * See MIO_PTP_PPS_THRESH_HI for details.
 */
typedef union bdk_mio_ptp_pps_thresh_lo {
	uint64_t u;
	struct bdk_mio_ptp_pps_thresh_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t frnanosec                   : 32; /**< R/W/H - Fractions of nanoseconds. */
#else
		uint64_t frnanosec                   : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_mio_ptp_pps_thresh_lo_s cn88xx; */
	/* struct bdk_mio_ptp_pps_thresh_lo_s cn88xxp1; */
} bdk_mio_ptp_pps_thresh_lo_t;

#define BDK_MIO_PTP_PPS_THRESH_LO BDK_MIO_PTP_PPS_THRESH_LO_FUNC()
static inline uint64_t BDK_MIO_PTP_PPS_THRESH_LO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_PPS_THRESH_LO_FUNC(void)
{
	return 0x0000807000000F50ull;
}
#define typedef_BDK_MIO_PTP_PPS_THRESH_LO bdk_mio_ptp_pps_thresh_lo_t
#define bustype_BDK_MIO_PTP_PPS_THRESH_LO BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_PPS_THRESH_LO 0
#define arguments_BDK_MIO_PTP_PPS_THRESH_LO -1,-1,-1,-1
#define basename_BDK_MIO_PTP_PPS_THRESH_LO "MIO_PTP_PPS_THRESH_LO"


/**
 * NCB - mio_ptp_timestamp
 *
 * This register contains the timestamp latched on MIO_PTP_CLOCK_CFG[TSTMP_EDGE] edge of
 * MIO_PTP_CLOCK_CFG[TSTMP_IN].
 */
typedef union bdk_mio_ptp_timestamp {
	uint64_t u;
	struct bdk_mio_ptp_timestamp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t nanosec                     : 64; /**< R/W/H - Timestamp in nanoseconds. */
#else
		uint64_t nanosec                     : 64;
#endif
	} s;
	/* struct bdk_mio_ptp_timestamp_s     cn88xx; */
	/* struct bdk_mio_ptp_timestamp_s     cn88xxp1; */
} bdk_mio_ptp_timestamp_t;

#define BDK_MIO_PTP_TIMESTAMP BDK_MIO_PTP_TIMESTAMP_FUNC()
static inline uint64_t BDK_MIO_PTP_TIMESTAMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_PTP_TIMESTAMP_FUNC(void)
{
	return 0x0000807000000F20ull;
}
#define typedef_BDK_MIO_PTP_TIMESTAMP bdk_mio_ptp_timestamp_t
#define bustype_BDK_MIO_PTP_TIMESTAMP BDK_CSR_TYPE_NCB
#define busnum_BDK_MIO_PTP_TIMESTAMP 0
#define arguments_BDK_MIO_PTP_TIMESTAMP -1,-1,-1,-1
#define basename_BDK_MIO_PTP_TIMESTAMP "MIO_PTP_TIMESTAMP"

#endif /* __BDK_CSRS_MIO_PTP__ */
