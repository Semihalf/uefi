#ifndef __BDK_CSRS_IOBN_H__
#define __BDK_CSRS_IOBN_H__
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
 * Cavium IOBN.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration iobn_int_vec_e
 *
 * IOBN MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_IOBN_INT_VEC_E_INTS (0) /**< See interrupt clears IOBN(0..1)_INT_SUM,
                                       interrupt sets IOBN(0..1)_INT_SUM_W1S,
                                       enable clears IOBN(0..1)_INT_ENA_W1C,
                                       and enable sets IOBN(0..1)_INT_ENA_W1S. */

/**
 * Enumeration iobn_bar_e
 *
 * IOBN Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_IOBN_BAR_E_IOBNX_PF_BAR0(a) (0x87e0f0000000ll + 0x1000000ll * (a)) /**< (0..1)Base address for standard registers. */
#define BDK_IOBN_BAR_E_IOBNX_PF_BAR4(a) (0x87e0f0f00000ll + 0x1000000ll * (a)) /**< (0..1)Base address for MSI-X registers. */

/**
 * Register (RSL) iobn#_gbl_dll
 *
 * INTERNAL: IOBN Global Core-Clock DLL Status Register
 *
 * Status of the global core-clock DLL.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_gbl_dll_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_20_63        : 44;
        uint64_t pdr_rclk_refclk       : 1;  /**< [ 19: 19](RO/H) Synchronized pdr_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
        uint64_t pdl_rclk_refclk       : 1;  /**< [ 18: 18](RO/H) Synchronized pdl_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
        uint64_t pd_pos_rclk_refclk    : 1;  /**< [ 17: 17](RO/H) Synchronized pd_pos_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
        uint64_t dll_fsm_state_a       : 3;  /**< [ 16: 14](RO/H) State for the global core-clock DLL, from the positive edge of refclk.
                                                                 0x0 = TMD_IDLE.
                                                                 0x1 = TMD_STATE1.
                                                                 0x2 = TMD_STATE2.
                                                                 0x3 = TMD_STATE3.
                                                                 0x4 = TMD_STATE4.
                                                                 0x5 = TMD_LOCKED. */
        uint64_t dll_lock              : 1;  /**< [ 13: 13](RO/H) The dll_lock signal from global core-clock DLL, from the positive edge of refclk. */
        uint64_t dll_clk_invert_out    : 1;  /**< [ 12: 12](RO/H) The clk_invert setting from the global core-clock DLL, from the negative edge of refclk. */
        uint64_t dll_setting           : 12; /**< [ 11:  0](RO/H) The global core-clock DLL setting, from the negative edge of refclk. */
#else /* Word 0 - Little Endian */
        uint64_t dll_setting           : 12; /**< [ 11:  0](RO/H) The global core-clock DLL setting, from the negative edge of refclk. */
        uint64_t dll_clk_invert_out    : 1;  /**< [ 12: 12](RO/H) The clk_invert setting from the global core-clock DLL, from the negative edge of refclk. */
        uint64_t dll_lock              : 1;  /**< [ 13: 13](RO/H) The dll_lock signal from global core-clock DLL, from the positive edge of refclk. */
        uint64_t dll_fsm_state_a       : 3;  /**< [ 16: 14](RO/H) State for the global core-clock DLL, from the positive edge of refclk.
                                                                 0x0 = TMD_IDLE.
                                                                 0x1 = TMD_STATE1.
                                                                 0x2 = TMD_STATE2.
                                                                 0x3 = TMD_STATE3.
                                                                 0x4 = TMD_STATE4.
                                                                 0x5 = TMD_LOCKED. */
        uint64_t pd_pos_rclk_refclk    : 1;  /**< [ 17: 17](RO/H) Synchronized pd_pos_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
        uint64_t pdl_rclk_refclk       : 1;  /**< [ 18: 18](RO/H) Synchronized pdl_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
        uint64_t pdr_rclk_refclk       : 1;  /**< [ 19: 19](RO/H) Synchronized pdr_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
        uint64_t reserved_20_63        : 44;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_gbl_dll_s cn; */
} bdk_iobnx_gbl_dll_t;

static inline uint64_t BDK_IOBNX_GBL_DLL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_GBL_DLL(unsigned long a)
{
    return 0x87e0f000a000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_GBL_DLL(a) bdk_iobnx_gbl_dll_t
#define bustype_BDK_IOBNX_GBL_DLL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_GBL_DLL(a) "IOBNX_GBL_DLL"
#define busnum_BDK_IOBNX_GBL_DLL(a) (a)
#define arguments_BDK_IOBNX_GBL_DLL(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_int_sum_w1s
 *
 * IOBN Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_int_sum_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct bdk_iobnx_int_sum_w1s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1S/H) Added in pass 2.0. Reads or sets IOBN(0..1)_INT_SUM[PEM_SIE]. */
        uint64_t reserved_61_62        : 2;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1S/H) Added in pass 2.0. Reads or sets IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1S/H) Added in pass 2.0. Reads or sets IOBN(0..1)_INT_SUM[IED0_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1S/H) Added in pass 2.0. Reads or sets IOBN(0..1)_INT_SUM[IED0_SBE]. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1S/H) Added in pass 2.0. Reads or sets IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_61_62        : 2;
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1S/H) Added in pass 2.0. Reads or sets IOBN(0..1)_INT_SUM[PEM_SIE]. */
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_iobnx_int_sum_w1s_cn83xx cn88xxp2; */
    struct bdk_iobnx_int_sum_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1S/H) Reads or sets IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1S/H) Reads or sets IOBN(0..1)_INT_SUM[IED0_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1S/H) Reads or sets IOBN(0..1)_INT_SUM[IED0_SBE]. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1S/H) Reads or sets IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_iobnx_int_sum_w1s_t;

static inline uint64_t BDK_IOBNX_INT_SUM_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_SUM_W1S(unsigned long a)
{
    return 0x87e0f0007000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_INT_SUM_W1S(a) bdk_iobnx_int_sum_w1s_t
#define bustype_BDK_IOBNX_INT_SUM_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_INT_SUM_W1S(a) "IOBNX_INT_SUM_W1S"
#define busnum_BDK_IOBNX_INT_SUM_W1S(a) (a)
#define arguments_BDK_IOBNX_INT_SUM_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_int_ena_w1s
 *
 * IOBN Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct bdk_iobnx_int_ena_w1s_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1S/H) Added in pass 2.0. Reads or sets enable for IOBN(0..1)_INT_SUM[PEM_SIE]. */
        uint64_t reserved_61_62        : 2;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1S/H) Added in pass 2.0. Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1S/H) Added in pass 2.0. Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1S/H) Added in pass 2.0. Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1S/H) Added in pass 2.0. Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_61_62        : 2;
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1S/H) Added in pass 2.0. Reads or sets enable for IOBN(0..1)_INT_SUM[PEM_SIE]. */
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_iobnx_int_ena_w1s_cn83xx cn88xxp2; */
    struct bdk_iobnx_int_ena_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1S/H) Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1S/H) Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1S/H) Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1S/H) Reads or sets enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_iobnx_int_ena_w1s_t;

static inline uint64_t BDK_IOBNX_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_ENA_W1S(unsigned long a)
{
    return 0x87e0f0009000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_INT_ENA_W1S(a) bdk_iobnx_int_ena_w1s_t
#define bustype_BDK_IOBNX_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_INT_ENA_W1S(a) "IOBNX_INT_ENA_W1S"
#define busnum_BDK_IOBNX_INT_ENA_W1S(a) (a)
#define arguments_BDK_IOBNX_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_int_ena_w1c
 *
 * IOBN Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct bdk_iobnx_int_ena_w1c_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1C/H) Added in pass 2.0. Reads or clears enable for IOBN(0..1)_INT_SUM[PEM_SIE]. */
        uint64_t reserved_61_62        : 2;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1C/H) Added in pass 2.0. Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1C/H) Added in pass 2.0. Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1C/H) Added in pass 2.0. Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1C/H) Added in pass 2.0. Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_61_62        : 2;
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1C/H) Added in pass 2.0. Reads or clears enable for IOBN(0..1)_INT_SUM[PEM_SIE]. */
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_iobnx_int_ena_w1c_cn83xx cn88xxp2; */
    struct bdk_iobnx_int_ena_w1c_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1C/H) Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1C/H) Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1C/H) Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_SBE]. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1C/H) Reads or clears enable for IOBN(0..1)_INT_SUM[IED0_DBE]. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_iobnx_int_ena_w1c_t;

static inline uint64_t BDK_IOBNX_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_ENA_W1C(unsigned long a)
{
    return 0x87e0f0008000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_INT_ENA_W1C(a) bdk_iobnx_int_ena_w1c_t
#define bustype_BDK_IOBNX_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_INT_ENA_W1C(a) "IOBNX_INT_ENA_W1C"
#define busnum_BDK_IOBNX_INT_ENA_W1C(a) (a)
#define arguments_BDK_IOBNX_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_chip_glb_pwr_throttle
 *
 * IOBN Chip Global Power Throttle Register
 * This register controls the min/max power settings.
 * Only index zero (IOB(0)) is used.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_chip_glb_pwr_throttle_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_34_63        : 30;
        uint64_t pwr_bw                : 2;  /**< [ 33: 32](R/W) Configures the reaction time of the closed-loop feedback control system for the
                                                                 AVG_CHIP_POWER power approximation. Higher numbers decrease bandwidth, reducing response
                                                                 time, which could lead to greater tracking error, but reduce ringing. */
        uint64_t pwr_max               : 8;  /**< [ 31: 24](R/W) Maximum allowed CURRENT_POWER_SETTING value. PWR_MAX must be >= PWR_MIN. */
        uint64_t pwr_min               : 8;  /**< [ 23: 16](R/W) Minimum allowed CURRENT_POWER_SETTING value. PWR_MIN must be <= PWR_MAX. We recommend a
                                                                 PWR_MIN value larger than zero to set a minimum performance level in case PWR_SETTING is
                                                                 set to an unreachable goal. See the CPU CP0 PowThrottle description. PWR_MIN = 50% of
                                                                 PowThrottle[MAXPOW] could be a good choice, for example. */
        uint64_t pwr_setting           : 16; /**< [ 15:  0](R/W) A power limiter for the chip. A limiter of the power consumption of the chip. This power
                                                                 limiting is implemented by a closed-loop feedback control system for the AVG_CHIP_POWER
                                                                 power approximation. The direct output of the PWR_SETTING feedback control system is the
                                                                 CURRENT_POWER_SETTING value. The power consumed by the chip (estimated currently by the
                                                                 AVG_CHIP_POWER value) is an indirect output of the PWR_SETTING feedback control system.
                                                                 PWR_SETTING is not used by the hardware when PWR_MIN equals PWR_MAX. PWR_MIN and PWR_MAX
                                                                 threshold requirements always supersede PWR_SETTING limits. (For maximum PWR_SETTING
                                                                 feedback control freedom, set PWR_MIN=0 and PWR_MAX=0xff.)

                                                                 PWR_SETTING equal to 0 forces the chip to consume near minimum power. Increasing
                                                                 PWR_SETTING value from 0 to 0xFFFF increases the power that the chip is allowed to consume
                                                                 linearly (roughly) from minimum to maximum. */
#else /* Word 0 - Little Endian */
        uint64_t pwr_setting           : 16; /**< [ 15:  0](R/W) A power limiter for the chip. A limiter of the power consumption of the chip. This power
                                                                 limiting is implemented by a closed-loop feedback control system for the AVG_CHIP_POWER
                                                                 power approximation. The direct output of the PWR_SETTING feedback control system is the
                                                                 CURRENT_POWER_SETTING value. The power consumed by the chip (estimated currently by the
                                                                 AVG_CHIP_POWER value) is an indirect output of the PWR_SETTING feedback control system.
                                                                 PWR_SETTING is not used by the hardware when PWR_MIN equals PWR_MAX. PWR_MIN and PWR_MAX
                                                                 threshold requirements always supersede PWR_SETTING limits. (For maximum PWR_SETTING
                                                                 feedback control freedom, set PWR_MIN=0 and PWR_MAX=0xff.)

                                                                 PWR_SETTING equal to 0 forces the chip to consume near minimum power. Increasing
                                                                 PWR_SETTING value from 0 to 0xFFFF increases the power that the chip is allowed to consume
                                                                 linearly (roughly) from minimum to maximum. */
        uint64_t pwr_min               : 8;  /**< [ 23: 16](R/W) Minimum allowed CURRENT_POWER_SETTING value. PWR_MIN must be <= PWR_MAX. We recommend a
                                                                 PWR_MIN value larger than zero to set a minimum performance level in case PWR_SETTING is
                                                                 set to an unreachable goal. See the CPU CP0 PowThrottle description. PWR_MIN = 50% of
                                                                 PowThrottle[MAXPOW] could be a good choice, for example. */
        uint64_t pwr_max               : 8;  /**< [ 31: 24](R/W) Maximum allowed CURRENT_POWER_SETTING value. PWR_MAX must be >= PWR_MIN. */
        uint64_t pwr_bw                : 2;  /**< [ 33: 32](R/W) Configures the reaction time of the closed-loop feedback control system for the
                                                                 AVG_CHIP_POWER power approximation. Higher numbers decrease bandwidth, reducing response
                                                                 time, which could lead to greater tracking error, but reduce ringing. */
        uint64_t reserved_34_63        : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_chip_glb_pwr_throttle_s cn; */
} bdk_iobnx_chip_glb_pwr_throttle_t;

static inline uint64_t BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(unsigned long a)
{
    return 0x87e0f000a100ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(a) bdk_iobnx_chip_glb_pwr_throttle_t
#define bustype_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(a) "IOBNX_CHIP_GLB_PWR_THROTTLE"
#define busnum_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(a) (a)
#define arguments_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_scratch
 *
 * INTERNAL: IOBN Scratch Register
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_scratch_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Test register for CSR access. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Test register for CSR access. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_scratch_s cn; */
} bdk_iobnx_scratch_t;

static inline uint64_t BDK_IOBNX_SCRATCH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_SCRATCH(unsigned long a)
{
    return 0x87e0f0003020ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_SCRATCH(a) bdk_iobnx_scratch_t
#define bustype_BDK_IOBNX_SCRATCH(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_SCRATCH(a) "IOBNX_SCRATCH"
#define busnum_BDK_IOBNX_SCRATCH(a) (a)
#define arguments_BDK_IOBNX_SCRATCH(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_int_sum
 *
 * IOBN Interrupt Summary Register
 * This register contains the different interrupt-summary bits of the IOBN.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_int_sum_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_0_63         : 64;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_63         : 64;
#endif /* Word 0 - End */
    } s;
    struct bdk_iobnx_int_sum_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1C/H) PEM sent in an invalid stream ID. Added in pass 2. */
        uint64_t reserved_61_62        : 2;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1C/H) Changed in pass 2.
                                                                 IED0 double-bit error. When set, an IED0 double-bit error has occurred.
                                                                 INTERNAL:
                                                                      iob_mem_data_xmd_sbe_sclk,
                                                                      gmr_ixofifo_dbe_sclk,
                                                                      icc0_xmc_fif_dbe,
                                                                      icc1_xmc_fif_dbe,
                                                                      icc_xmc_fifo_ecc_dbe,
                                                                      sli_preq_0_dbe_sclk,
                                                                      sli_req_0_dbe_sclk,
                                                                      sli_preq_1_dbe_sclk,
                                                                      sli_req_1_dbe_sclk,
                                                                      sli_preq_2_dbe_sclk,
                                                                      sli_req_2_dbe_sclk,
                                                                      ixo_smmu_mem0_dbe_sclk,
                                                                      iop_breq_fifo0_dbe,
                                                                      iop_breq_fifo1_dbe ,
                                                                      iop_breq_fifo2_dbe,
                                                                      iop_breq_fifo3_dbe ,
                                                                      iop_ffifo_dbe_sclk,
                                                                      rsd_mem0_dbe,
                                                                      rsd_mem1_dbe,
                                                                      ics_cmd_fifo_dbe_sclk,
                                                                      ixo_xmd_mem1_dbe_sclk,
                                                                      ixo_xmd_mem0_dbe_sclk,
                                                                      iobn_iorn_ffifo0__dbe_sclk,
                                                                      iobn_iorn_ffifo1__dbe_sclk,
                                                                      irp1_flid_mem_dbe,
                                                                      irp0_flid_mem_dbe,
                                                                      ixo_icc_fifo0_dbe_in_sclk,
                                                                      ixo_icc_fifo1_dbe_in_sclk,
                                                                      ixo_ics_mem_dbe_in_sclk. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1C/H) Changed in pass 2.
                                                                 IED0 single-bit error. When set, an IED0 single-bit error has occurred.
                                                                 INTERNAL:
                                                                       iob_mem_data_xmd_sbe_sclk,
                                                                       gmr_ixofifo_sbe_sclk,
                                                                       icc0_xmc_fif_sbe,
                                                                       icc1_xmc_fif_sbe,
                                                                       icc_xmc_fifo_ecc_sbe,
                                                                       sli_preq_0_sbe_sclk,
                                                                       sli_req_0_sbe_sclk,
                                                                       sli_preq_1_sbe_sclk,
                                                                       sli_req_1_sbe_sclk,
                                                                       sli_preq_2_sbe_sclk,
                                                                       sli_req_2_sbe_sclk,
                                                                       ixo_smmu_mem0_sbe_sclk,
                                                                       iop_breq_fifo0_sbe,
                                                                       iop_breq_fifo1_sbe ,
                                                                       iop_breq_fifo2_sbe,
                                                                       iop_breq_fifo3_sbe ,
                                                                       iop_ffifo_sbe_sclk,
                                                                       rsd_mem0_sbe,
                                                                       rsd_mem1_sbe,
                                                                       ics_cmd_fifo_sbe_sclk,
                                                                       ixo_xmd_mem1_sbe_sclk,
                                                                       ixo_xmd_mem0_sbe_sclk,
                                                                       iobn_iorn_ffifo0__sbe_sclk,
                                                                       iobn_iorn_ffifo1__sbe_sclk,
                                                                       irp1_flid_mem_sbe,
                                                                       irp0_flid_mem_sbe,
                                                                       ixo_icc_fifo0_sbe_in_sclk,
                                                                       ixo_icc_fifo1_sbe_in_sclk,
                                                                       ixo_ics_mem_sbe_in_sclk. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 29; /**< [ 28:  0](R/W1C/H) Changed in pass 2.
                                                                 IED0 single-bit error. When set, an IED0 single-bit error has occurred.
                                                                 INTERNAL:
                                                                       iob_mem_data_xmd_sbe_sclk,
                                                                       gmr_ixofifo_sbe_sclk,
                                                                       icc0_xmc_fif_sbe,
                                                                       icc1_xmc_fif_sbe,
                                                                       icc_xmc_fifo_ecc_sbe,
                                                                       sli_preq_0_sbe_sclk,
                                                                       sli_req_0_sbe_sclk,
                                                                       sli_preq_1_sbe_sclk,
                                                                       sli_req_1_sbe_sclk,
                                                                       sli_preq_2_sbe_sclk,
                                                                       sli_req_2_sbe_sclk,
                                                                       ixo_smmu_mem0_sbe_sclk,
                                                                       iop_breq_fifo0_sbe,
                                                                       iop_breq_fifo1_sbe ,
                                                                       iop_breq_fifo2_sbe,
                                                                       iop_breq_fifo3_sbe ,
                                                                       iop_ffifo_sbe_sclk,
                                                                       rsd_mem0_sbe,
                                                                       rsd_mem1_sbe,
                                                                       ics_cmd_fifo_sbe_sclk,
                                                                       ixo_xmd_mem1_sbe_sclk,
                                                                       ixo_xmd_mem0_sbe_sclk,
                                                                       iobn_iorn_ffifo0__sbe_sclk,
                                                                       iobn_iorn_ffifo1__sbe_sclk,
                                                                       irp1_flid_mem_sbe,
                                                                       irp0_flid_mem_sbe,
                                                                       ixo_icc_fifo0_sbe_in_sclk,
                                                                       ixo_icc_fifo1_sbe_in_sclk,
                                                                       ixo_ics_mem_sbe_in_sclk. */
        uint64_t reserved_29_31        : 3;
        uint64_t ied0_dbe              : 29; /**< [ 60: 32](R/W1C/H) Changed in pass 2.
                                                                 IED0 double-bit error. When set, an IED0 double-bit error has occurred.
                                                                 INTERNAL:
                                                                      iob_mem_data_xmd_sbe_sclk,
                                                                      gmr_ixofifo_dbe_sclk,
                                                                      icc0_xmc_fif_dbe,
                                                                      icc1_xmc_fif_dbe,
                                                                      icc_xmc_fifo_ecc_dbe,
                                                                      sli_preq_0_dbe_sclk,
                                                                      sli_req_0_dbe_sclk,
                                                                      sli_preq_1_dbe_sclk,
                                                                      sli_req_1_dbe_sclk,
                                                                      sli_preq_2_dbe_sclk,
                                                                      sli_req_2_dbe_sclk,
                                                                      ixo_smmu_mem0_dbe_sclk,
                                                                      iop_breq_fifo0_dbe,
                                                                      iop_breq_fifo1_dbe ,
                                                                      iop_breq_fifo2_dbe,
                                                                      iop_breq_fifo3_dbe ,
                                                                      iop_ffifo_dbe_sclk,
                                                                      rsd_mem0_dbe,
                                                                      rsd_mem1_dbe,
                                                                      ics_cmd_fifo_dbe_sclk,
                                                                      ixo_xmd_mem1_dbe_sclk,
                                                                      ixo_xmd_mem0_dbe_sclk,
                                                                      iobn_iorn_ffifo0__dbe_sclk,
                                                                      iobn_iorn_ffifo1__dbe_sclk,
                                                                      irp1_flid_mem_dbe,
                                                                      irp0_flid_mem_dbe,
                                                                      ixo_icc_fifo0_dbe_in_sclk,
                                                                      ixo_icc_fifo1_dbe_in_sclk,
                                                                      ixo_ics_mem_dbe_in_sclk. */
        uint64_t reserved_61_62        : 2;
        uint64_t pem_sie               : 1;  /**< [ 63: 63](R/W1C/H) PEM sent in an invalid stream ID. Added in pass 2. */
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_iobnx_int_sum_cn83xx cn88xxp2; */
    struct bdk_iobnx_int_sum_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1C/H) IED0 double-bit error. When set, an IED0 double-bit error has occurred.
                                                                 INTERNAL:
                                                                      gmr_ixofifo_dbe_sclk,
                                                                      icc0_xmc_fif_dbe,
                                                                      icc1_xmc_fif_dbe,
                                                                      icc_xmc_fifo_ecc_dbe,
                                                                      sli_preq_0_dbe_sclk,
                                                                      sli_req_0_dbe_sclk,
                                                                      sli_preq_1_dbe_sclk,
                                                                      sli_req_1_dbe_sclk,
                                                                      sli_preq_2_dbe_sclk,
                                                                      sli_req_2_dbe_sclk,
                                                                      ixo_smmu_mem0_dbe_sclk,
                                                                      iop_breq_fifo0_dbe,
                                                                      iop_breq_fifo1_dbe ,
                                                                      iop_breq_fifo2_dbe,
                                                                      iop_breq_fifo3_dbe ,
                                                                      iop_ffifo_dbe_sclk,
                                                                      rsd_mem0_dbe,
                                                                      rsd_mem1_dbe,
                                                                      ics_cmd_fifo_dbe_sclk,
                                                                      ixo_xmd_mem1_dbe_sclk,
                                                                      ixo_xmd_mem0_dbe_sclk,
                                                                      iobn_iorn_ffifo0__dbe_sclk,
                                                                      iobn_iorn_ffifo1__dbe_sclk,
                                                                      irp1_flid_mem_dbe,
                                                                      irp0_flid_mem_dbe,
                                                                      ixo_icc_fifo0_dbe_in_sclk,
                                                                      ixo_icc_fifo1_dbe_in_sclk,
                                                                      ixo_ics_mem_dbe_in_sclk. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1C/H) IED0 single-bit error. When set, an IED0 single-bit error has occurred.
                                                                 INTERNAL:
                                                                       gmr_ixofifo_sbe_sclk,
                                                                       icc0_xmc_fif_sbe,
                                                                       icc1_xmc_fif_sbe,
                                                                       icc_xmc_fifo_ecc_sbe,
                                                                       sli_preq_0_sbe_sclk,
                                                                       sli_req_0_sbe_sclk,
                                                                       sli_preq_1_sbe_sclk,
                                                                       sli_req_1_sbe_sclk,
                                                                       sli_preq_2_sbe_sclk,
                                                                       sli_req_2_sbe_sclk,
                                                                       ixo_smmu_mem0_sbe_sclk,
                                                                       iop_breq_fifo0_sbe,
                                                                       iop_breq_fifo1_sbe ,
                                                                       iop_breq_fifo2_sbe,
                                                                       iop_breq_fifo3_sbe ,
                                                                       iop_ffifo_sbe_sclk,
                                                                       rsd_mem0_sbe,
                                                                       rsd_mem1_sbe,
                                                                       ics_cmd_fifo_sbe_sclk,
                                                                       ixo_xmd_mem1_sbe_sclk,
                                                                       ixo_xmd_mem0_sbe_sclk,
                                                                       iobn_iorn_ffifo0__sbe_sclk,
                                                                       iobn_iorn_ffifo1__sbe_sclk,
                                                                       irp1_flid_mem_sbe,
                                                                       irp0_flid_mem_sbe,
                                                                       ixo_icc_fifo0_sbe_in_sclk,
                                                                       ixo_icc_fifo1_sbe_in_sclk,
                                                                       ixo_ics_mem_sbe_in_sclk. */
#else /* Word 0 - Little Endian */
        uint64_t ied0_sbe              : 28; /**< [ 27:  0](R/W1C/H) IED0 single-bit error. When set, an IED0 single-bit error has occurred.
                                                                 INTERNAL:
                                                                       gmr_ixofifo_sbe_sclk,
                                                                       icc0_xmc_fif_sbe,
                                                                       icc1_xmc_fif_sbe,
                                                                       icc_xmc_fifo_ecc_sbe,
                                                                       sli_preq_0_sbe_sclk,
                                                                       sli_req_0_sbe_sclk,
                                                                       sli_preq_1_sbe_sclk,
                                                                       sli_req_1_sbe_sclk,
                                                                       sli_preq_2_sbe_sclk,
                                                                       sli_req_2_sbe_sclk,
                                                                       ixo_smmu_mem0_sbe_sclk,
                                                                       iop_breq_fifo0_sbe,
                                                                       iop_breq_fifo1_sbe ,
                                                                       iop_breq_fifo2_sbe,
                                                                       iop_breq_fifo3_sbe ,
                                                                       iop_ffifo_sbe_sclk,
                                                                       rsd_mem0_sbe,
                                                                       rsd_mem1_sbe,
                                                                       ics_cmd_fifo_sbe_sclk,
                                                                       ixo_xmd_mem1_sbe_sclk,
                                                                       ixo_xmd_mem0_sbe_sclk,
                                                                       iobn_iorn_ffifo0__sbe_sclk,
                                                                       iobn_iorn_ffifo1__sbe_sclk,
                                                                       irp1_flid_mem_sbe,
                                                                       irp0_flid_mem_sbe,
                                                                       ixo_icc_fifo0_sbe_in_sclk,
                                                                       ixo_icc_fifo1_sbe_in_sclk,
                                                                       ixo_ics_mem_sbe_in_sclk. */
        uint64_t reserved_28_31        : 4;
        uint64_t ied0_dbe              : 28; /**< [ 59: 32](R/W1C/H) IED0 double-bit error. When set, an IED0 double-bit error has occurred.
                                                                 INTERNAL:
                                                                      gmr_ixofifo_dbe_sclk,
                                                                      icc0_xmc_fif_dbe,
                                                                      icc1_xmc_fif_dbe,
                                                                      icc_xmc_fifo_ecc_dbe,
                                                                      sli_preq_0_dbe_sclk,
                                                                      sli_req_0_dbe_sclk,
                                                                      sli_preq_1_dbe_sclk,
                                                                      sli_req_1_dbe_sclk,
                                                                      sli_preq_2_dbe_sclk,
                                                                      sli_req_2_dbe_sclk,
                                                                      ixo_smmu_mem0_dbe_sclk,
                                                                      iop_breq_fifo0_dbe,
                                                                      iop_breq_fifo1_dbe ,
                                                                      iop_breq_fifo2_dbe,
                                                                      iop_breq_fifo3_dbe ,
                                                                      iop_ffifo_dbe_sclk,
                                                                      rsd_mem0_dbe,
                                                                      rsd_mem1_dbe,
                                                                      ics_cmd_fifo_dbe_sclk,
                                                                      ixo_xmd_mem1_dbe_sclk,
                                                                      ixo_xmd_mem0_dbe_sclk,
                                                                      iobn_iorn_ffifo0__dbe_sclk,
                                                                      iobn_iorn_ffifo1__dbe_sclk,
                                                                      irp1_flid_mem_dbe,
                                                                      irp0_flid_mem_dbe,
                                                                      ixo_icc_fifo0_dbe_in_sclk,
                                                                      ixo_icc_fifo1_dbe_in_sclk,
                                                                      ixo_ics_mem_dbe_in_sclk. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_iobnx_int_sum_t;

static inline uint64_t BDK_IOBNX_INT_SUM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_SUM(unsigned long a)
{
    return 0x87e0f0006000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_INT_SUM(a) bdk_iobnx_int_sum_t
#define bustype_BDK_IOBNX_INT_SUM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_INT_SUM(a) "IOBNX_INT_SUM"
#define busnum_BDK_IOBNX_INT_SUM(a) (a)
#define arguments_BDK_IOBNX_INT_SUM(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_chip_cur_pwr
 *
 * IOBN Chip Current Power Register
 * This register contains the current power setting.
 * Only index zero (IOB(0)) is used.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_chip_cur_pwr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t current_power_setting : 8;  /**< [  7:  0](RO/H) Global throttling value currently being used. Throttling can force units (CPU cores, in
                                                                 particular) idle for a portion of time, which will reduce power consumption. When
                                                                 CURRENT_POWER_SETTING is equal to zero, the unit is idle most of the time and consumes
                                                                 minimum power. When CURRENT_POWER_SETTING is equal to 0xFF, units are never idled to
                                                                 reduce power. The hardware generally uses a CURRENT_POWER_SETTING value that is as large
                                                                 as possible (in order to maximize performance) subject to the following constraints (in
                                                                 priority order):
                                                                 * PWR_MIN <= CURRENT_POWER_SETTING <= PWR_MAX.
                                                                 * Power limits from the PWR_SETTING feedback control system.

                                                                 In the case of the CPU cores, CURRENT_POWER_SETTING effectively limits the CP0
                                                                 PowThrottle[POWLIM] value: effective POWLIM = MINIMUM(CURRENT_POWER_SETTING,
                                                                 PowThrottle[POWLIM]) */
#else /* Word 0 - Little Endian */
        uint64_t current_power_setting : 8;  /**< [  7:  0](RO/H) Global throttling value currently being used. Throttling can force units (CPU cores, in
                                                                 particular) idle for a portion of time, which will reduce power consumption. When
                                                                 CURRENT_POWER_SETTING is equal to zero, the unit is idle most of the time and consumes
                                                                 minimum power. When CURRENT_POWER_SETTING is equal to 0xFF, units are never idled to
                                                                 reduce power. The hardware generally uses a CURRENT_POWER_SETTING value that is as large
                                                                 as possible (in order to maximize performance) subject to the following constraints (in
                                                                 priority order):
                                                                 * PWR_MIN <= CURRENT_POWER_SETTING <= PWR_MAX.
                                                                 * Power limits from the PWR_SETTING feedback control system.

                                                                 In the case of the CPU cores, CURRENT_POWER_SETTING effectively limits the CP0
                                                                 PowThrottle[POWLIM] value: effective POWLIM = MINIMUM(CURRENT_POWER_SETTING,
                                                                 PowThrottle[POWLIM]) */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_chip_cur_pwr_s cn; */
} bdk_iobnx_chip_cur_pwr_t;

static inline uint64_t BDK_IOBNX_CHIP_CUR_PWR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CHIP_CUR_PWR(unsigned long a)
{
    return 0x87e0f000a110ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_CHIP_CUR_PWR(a) bdk_iobnx_chip_cur_pwr_t
#define bustype_BDK_IOBNX_CHIP_CUR_PWR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_CHIP_CUR_PWR(a) "IOBNX_CHIP_CUR_PWR"
#define busnum_BDK_IOBNX_CHIP_CUR_PWR(a) (a)
#define arguments_BDK_IOBNX_CHIP_CUR_PWR(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_slitag#_control
 *
 * IOBN Control Register
 * This register contains various control bits for IOBN functionality.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_slitagx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t bits_dis              : 1;  /**< [  8:  8](R/W) When set, disables stream validity checking. For diagnostic use only.
                                                                 Changed in pass 2. */
        uint64_t reserved_4_7          : 4;
        uint64_t ld_ld_ord             : 1;  /**< [  3:  3](R/W) Enforce load-following-load ordering for SLI operations. A load operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t ld_st_ord             : 1;  /**< [  2:  2](R/W) Enforce load-following-store ordering for SLI operations. A load operation must
                                                                 wait for all previous store operations' STDNs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t st_ld_ord             : 1;  /**< [  1:  1](R/W) Enforce store-following-load ordering for SLI operations. A store operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t st_st_ord             : 1;  /**< [  0:  0](R/W) Enforce store-following-store ordering for SLI operations. A store operation must
                                                                 wait for all previous store operations' STDNs before issuing. */
#else /* Word 0 - Little Endian */
        uint64_t st_st_ord             : 1;  /**< [  0:  0](R/W) Enforce store-following-store ordering for SLI operations. A store operation must
                                                                 wait for all previous store operations' STDNs before issuing. */
        uint64_t st_ld_ord             : 1;  /**< [  1:  1](R/W) Enforce store-following-load ordering for SLI operations. A store operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t ld_st_ord             : 1;  /**< [  2:  2](R/W) Enforce load-following-store ordering for SLI operations. A load operation must
                                                                 wait for all previous store operations' STDNs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t ld_ld_ord             : 1;  /**< [  3:  3](R/W) Enforce load-following-load ordering for SLI operations. A load operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t reserved_4_7          : 4;
        uint64_t bits_dis              : 1;  /**< [  8:  8](R/W) When set, disables stream validity checking. For diagnostic use only.
                                                                 Changed in pass 2. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_slitagx_control_s cn83xx; */
    /* struct bdk_iobnx_slitagx_control_s cn88xxp2; */
    struct bdk_iobnx_slitagx_control_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t bits_dis              : 1;  /**< [  8:  8](RAZ) Reserved. */
        uint64_t reserved_4_7          : 4;
        uint64_t ld_ld_ord             : 1;  /**< [  3:  3](R/W) Enforce load-following-load ordering for SLI operations. A load operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t ld_st_ord             : 1;  /**< [  2:  2](R/W) Enforce load-following-store ordering for SLI operations. A load operation must
                                                                 wait for all previous store operations' STDNs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t st_ld_ord             : 1;  /**< [  1:  1](R/W) Enforce store-following-load ordering for SLI operations. A store operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t st_st_ord             : 1;  /**< [  0:  0](R/W) Enforce store-following-store ordering for SLI operations. A store operation must
                                                                 wait for all previous store operations' STDNs before issuing. */
#else /* Word 0 - Little Endian */
        uint64_t st_st_ord             : 1;  /**< [  0:  0](R/W) Enforce store-following-store ordering for SLI operations. A store operation must
                                                                 wait for all previous store operations' STDNs before issuing. */
        uint64_t st_ld_ord             : 1;  /**< [  1:  1](R/W) Enforce store-following-load ordering for SLI operations. A store operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t ld_st_ord             : 1;  /**< [  2:  2](R/W) Enforce load-following-store ordering for SLI operations. A load operation must
                                                                 wait for all previous store operations' STDNs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t ld_ld_ord             : 1;  /**< [  3:  3](R/W) Enforce load-following-load ordering for SLI operations. A load operation must
                                                                 wait for all previous load operations' FILLs before issuing.

                                                                 Atomic transactions (which for PCI are non-posted so not part of normal store
                                                                 ordering) are also considered loads for the purpose of this bit. */
        uint64_t reserved_4_7          : 4;
        uint64_t bits_dis              : 1;  /**< [  8:  8](RAZ) Reserved. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_iobnx_slitagx_control_t;

static inline uint64_t BDK_IOBNX_SLITAGX_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_SLITAGX_CONTROL(unsigned long a, unsigned long b)
{
    return 0x87e0f0000000ll + 0x1000000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3);
}

#define typedef_BDK_IOBNX_SLITAGX_CONTROL(a,b) bdk_iobnx_slitagx_control_t
#define bustype_BDK_IOBNX_SLITAGX_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_SLITAGX_CONTROL(a,b) "IOBNX_SLITAGX_CONTROL"
#define busnum_BDK_IOBNX_SLITAGX_CONTROL(a,b) (a)
#define arguments_BDK_IOBNX_SLITAGX_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_ncb#_credits
 *
 * IOBN NCB Credits Register
 * This register controls the number of loads and stores each NCB can have to the L2.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_ncbx_credits_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_23_63        : 41;
        uint64_t ncb_wr_buf_crd        : 7;  /**< [ 22: 16](R/W) NCB write buffer credit. Each NCB can have 64 write buffers in flight to the L2; this is
                                                                 the number to decrease the 64 by. */
        uint64_t reserved_15           : 1;
        uint64_t ncb0_wr_crd           : 7;  /**< [ 14:  8](R/W) NCB write credit. Each NCB can have 64 writes in flight to the L2; this is the number to
                                                                 decrease the 64 by. */
        uint64_t reserved_7            : 1;
        uint64_t ncb0_rd_crd           : 7;  /**< [  6:  0](R/W) NCB read credit. Each NCB can have 64 reads in flight to the L2; this is the number to
                                                                 decrease the 64 by. */
#else /* Word 0 - Little Endian */
        uint64_t ncb0_rd_crd           : 7;  /**< [  6:  0](R/W) NCB read credit. Each NCB can have 64 reads in flight to the L2; this is the number to
                                                                 decrease the 64 by. */
        uint64_t reserved_7            : 1;
        uint64_t ncb0_wr_crd           : 7;  /**< [ 14:  8](R/W) NCB write credit. Each NCB can have 64 writes in flight to the L2; this is the number to
                                                                 decrease the 64 by. */
        uint64_t reserved_15           : 1;
        uint64_t ncb_wr_buf_crd        : 7;  /**< [ 22: 16](R/W) NCB write buffer credit. Each NCB can have 64 write buffers in flight to the L2; this is
                                                                 the number to decrease the 64 by. */
        uint64_t reserved_23_63        : 41;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_ncbx_credits_s cn; */
} bdk_iobnx_ncbx_credits_t;

static inline uint64_t BDK_IOBNX_NCBX_CREDITS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCBX_CREDITS(unsigned long a, unsigned long b)
{
    return 0x87e0f0001000ll + 0x1000000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x1);
}

#define typedef_BDK_IOBNX_NCBX_CREDITS(a,b) bdk_iobnx_ncbx_credits_t
#define bustype_BDK_IOBNX_NCBX_CREDITS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_NCBX_CREDITS(a,b) "IOBNX_NCBX_CREDITS"
#define busnum_BDK_IOBNX_NCBX_CREDITS(a,b) (a)
#define arguments_BDK_IOBNX_NCBX_CREDITS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_ncb0_sdis#
 *
 * IOBN NCB Secure Disable Register
 * SDIS(3) = DIDs 255:192, SDIS(2) = DIDs 191:128, SDIS(1) = DIDs 127:64, SDIS(0) = DIDs 63:0.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_ncb0_sdisx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t did                   : 64; /**< [ 63:  0](SR/W) When set a secure operation is required to access the NCBDID. If a non-secure operation
                                                                 occurs it will result in a R/W to ECAM0_NOP_ZF. */
#else /* Word 0 - Little Endian */
        uint64_t did                   : 64; /**< [ 63:  0](SR/W) When set a secure operation is required to access the NCBDID. If a non-secure operation
                                                                 occurs it will result in a R/W to ECAM0_NOP_ZF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_ncb0_sdisx_s cn; */
} bdk_iobnx_ncb0_sdisx_t;

static inline uint64_t BDK_IOBNX_NCB0_SDISX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCB0_SDISX(unsigned long a, unsigned long b)
{
    return 0x87e0f0002000ll + 0x1000000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x3);
}

#define typedef_BDK_IOBNX_NCB0_SDISX(a,b) bdk_iobnx_ncb0_sdisx_t
#define bustype_BDK_IOBNX_NCB0_SDISX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_NCB0_SDISX(a,b) "IOBNX_NCB0_SDISX"
#define busnum_BDK_IOBNX_NCB0_SDISX(a,b) (a)
#define arguments_BDK_IOBNX_NCB0_SDISX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_bists_reg
 *
 * IOBN BIST Status Register
 * This register contains the result of the BIST run on the IOB sclk memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_bists_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t status                : 11; /**< [ 10:  0](RO/H) Memory BIST status: INTERNAL:
                                                                   <10> = irp0_flid_mem_status.
                                                                   <9>  = irp1_flid_mem_status.
                                                                   <8>  = icc0_xmc_fifo_ecc_bstatus.
                                                                   <7>  = icc1_xmc_fifo_ecc_bstatus.
                                                                   <6>  = icc_xmc_fifo_ecc_bstatus.
                                                                   <5>  = rsd_mem0_bstatus.
                                                                   <4>  = rsd_mem1_bstatus.
                                                                   <3>  = iop_breq_fifo0_bstatus.
                                                                   <2>  = iop_breq_fifo1_bstatus.
                                                                   <1>  = iop_breq_fifo2_bstatus.
                                                                   <0>  = iop_breq_fifo3_bstatus. */
#else /* Word 0 - Little Endian */
        uint64_t status                : 11; /**< [ 10:  0](RO/H) Memory BIST status: INTERNAL:
                                                                   <10> = irp0_flid_mem_status.
                                                                   <9>  = irp1_flid_mem_status.
                                                                   <8>  = icc0_xmc_fifo_ecc_bstatus.
                                                                   <7>  = icc1_xmc_fifo_ecc_bstatus.
                                                                   <6>  = icc_xmc_fifo_ecc_bstatus.
                                                                   <5>  = rsd_mem0_bstatus.
                                                                   <4>  = rsd_mem1_bstatus.
                                                                   <3>  = iop_breq_fifo0_bstatus.
                                                                   <2>  = iop_breq_fifo1_bstatus.
                                                                   <1>  = iop_breq_fifo2_bstatus.
                                                                   <0>  = iop_breq_fifo3_bstatus. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_bists_reg_s cn; */
} bdk_iobnx_bists_reg_t;

static inline uint64_t BDK_IOBNX_BISTS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_BISTS_REG(unsigned long a)
{
    return 0x87e0f0005000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_BISTS_REG(a) bdk_iobnx_bists_reg_t
#define bustype_BDK_IOBNX_BISTS_REG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_BISTS_REG(a) "IOBNX_BISTS_REG"
#define busnum_BDK_IOBNX_BISTS_REG(a) (a)
#define arguments_BDK_IOBNX_BISTS_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_roc_dll
 *
 * INTERNAL: IOBN Global Core-Clock DLL Status Register
 *
 * Status of the ROC core-clock DLL.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_roc_dll_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t pdr_rclk_refclk       : 1;  /**< [ 31: 31](RO/H) Synchronized pdr_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pdl_rclk_refclk       : 1;  /**< [ 30: 30](RO/H) Synchronized pdl_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pd_pos_rclk_refclk    : 1;  /**< [ 29: 29](RO/H) Synchronized pd_pos_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t dll_lock              : 1;  /**< [ 28: 28](RO/H) The dll_lock signal from ROC core-clock DLL, from the positive edge of refclk. */
        uint64_t dll_dly_elem_en       : 16; /**< [ 27: 12](RO/H) The ROC core-clock delay element enable setting, from the negative edge of refclk. */
        uint64_t dll_setting           : 12; /**< [ 11:  0](RO/H) The ROC core-clock DLL setting, from the negative edge of refclk. */
#else /* Word 0 - Little Endian */
        uint64_t dll_setting           : 12; /**< [ 11:  0](RO/H) The ROC core-clock DLL setting, from the negative edge of refclk. */
        uint64_t dll_dly_elem_en       : 16; /**< [ 27: 12](RO/H) The ROC core-clock delay element enable setting, from the negative edge of refclk. */
        uint64_t dll_lock              : 1;  /**< [ 28: 28](RO/H) The dll_lock signal from ROC core-clock DLL, from the positive edge of refclk. */
        uint64_t pd_pos_rclk_refclk    : 1;  /**< [ 29: 29](RO/H) Synchronized pd_pos_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pdl_rclk_refclk       : 1;  /**< [ 30: 30](RO/H) Synchronized pdl_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pdr_rclk_refclk       : 1;  /**< [ 31: 31](RO/H) Synchronized pdr_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    struct bdk_iobnx_roc_dll_cn83xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t max_dll_setting       : 12; /**< [ 59: 48](RO/H) Changed in pass 2. Max reported DLL setting. */
        uint64_t min_dll_setting       : 12; /**< [ 47: 36](RO/H) Changed in pass 2. Min reported DLL setting. */
        uint64_t reserved_32_35        : 4;
        uint64_t pdr_rclk_refclk       : 1;  /**< [ 31: 31](RO/H) Synchronized pdr_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pdl_rclk_refclk       : 1;  /**< [ 30: 30](RO/H) Synchronized pdl_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pd_pos_rclk_refclk    : 1;  /**< [ 29: 29](RO/H) Synchronized pd_pos_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t dll_lock              : 1;  /**< [ 28: 28](RO/H) The dll_lock signal from ROC core-clock DLL, from the positive edge of refclk. */
        uint64_t dll_dly_elem_en       : 16; /**< [ 27: 12](RO/H) The ROC core-clock delay element enable setting, from the negative edge of refclk. */
        uint64_t dll_setting           : 12; /**< [ 11:  0](RO/H) The ROC core-clock DLL setting, from the negative edge of refclk. */
#else /* Word 0 - Little Endian */
        uint64_t dll_setting           : 12; /**< [ 11:  0](RO/H) The ROC core-clock DLL setting, from the negative edge of refclk. */
        uint64_t dll_dly_elem_en       : 16; /**< [ 27: 12](RO/H) The ROC core-clock delay element enable setting, from the negative edge of refclk. */
        uint64_t dll_lock              : 1;  /**< [ 28: 28](RO/H) The dll_lock signal from ROC core-clock DLL, from the positive edge of refclk. */
        uint64_t pd_pos_rclk_refclk    : 1;  /**< [ 29: 29](RO/H) Synchronized pd_pos_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pdl_rclk_refclk       : 1;  /**< [ 30: 30](RO/H) Synchronized pdl_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t pdr_rclk_refclk       : 1;  /**< [ 31: 31](RO/H) Synchronized pdr_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
        uint64_t reserved_32_35        : 4;
        uint64_t min_dll_setting       : 12; /**< [ 47: 36](RO/H) Changed in pass 2. Min reported DLL setting. */
        uint64_t max_dll_setting       : 12; /**< [ 59: 48](RO/H) Changed in pass 2. Max reported DLL setting. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } cn83xx;
    /* struct bdk_iobnx_roc_dll_cn83xx cn88xxp2; */
    /* struct bdk_iobnx_roc_dll_s cn88xxp1; */
} bdk_iobnx_roc_dll_t;

static inline uint64_t BDK_IOBNX_ROC_DLL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_ROC_DLL(unsigned long a)
{
    return 0x87e0f000a008ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_ROC_DLL(a) bdk_iobnx_roc_dll_t
#define bustype_BDK_IOBNX_ROC_DLL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_ROC_DLL(a) "IOBNX_ROC_DLL"
#define busnum_BDK_IOBNX_ROC_DLL(a) (a)
#define arguments_BDK_IOBNX_ROC_DLL(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_mctlr_reg
 *
 * IOBN Memory SControl Register
 * Contains the sclk memory control for memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_mctlr_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t dis                   : 16; /**< [ 47: 32](R/W) Memory ECC disable. INTERNAL:
                                                                   <47:32>  = iobn_gmr_ixofifo_csr_cor_dis,
                                                                              sli_req_2_cor_dis and sli_preq_2_cor_dis,
                                                                              sli_req_1_cor_dis and sli_preq_1_cor_dis,
                                                                              sli_req_0_cor_dis and sli_preq_0_cor_dis,
                                                                              iob__iob_xmd_csr_cor_dis_rclk,
                                                                              ixo_smmu_mem0_csr_cor_dis,
                                                                              ixo_smmu_mem1_csr_cor_dis,
                                                                              ixo_ics_mem_csr_cor_dis,
                                                                              ixo_icc_fifo0_csr_cor_dis,
                                                                              ixo_icc_fifo1_csr_cor_dis,
                                                                              ixo_xmd_mem0_csr_cor_dis,
                                                                              ixo_xmd_mem1_csr_cor_dis,
                                                                              iobn_iorn_ffifo0__csr_cor_dis,
                                                                              iobn_iorn_ffifo1__csr_cor_dis,
                                                                              iop_ffifo_csr_cor_dis,
                                                                              ics_cmd_fifo_csr_cor_dis */
        uint64_t reserved_28_31        : 4;
        uint64_t flip                  : 28; /**< [ 27:  0](R/W) Memory ECC flip. INTERNAL:
                                                                   <27:0>  = iobn_gmr_ixofifo_csr_flip_synd,
                                                                             sli_req_2_flip_synd and sli_preq_2_flip_synd,
                                                                             sli_req_1_flip_synd and sli_preq_1_flip_synd,
                                                                             sli_req_0_flip_synd and sli_preq_0_flip_synd,
                                                                             iobn_rsd_mem0_csr_flip_synd_rclk,
                                                                             iobn_rsd_mem1_csr_flip_synd_rclk,
                                                                             ixo_smmu_mem0_csr_flip_synd,
                                                                             ixo_smmu_mem1_csr_flip_synd,
                                                                             ixo_ics_mem_csr_flip_synd,
                                                                             iop_ffifo_csr_flip_synd,
                                                                             iop_breq_fifo0_csr_flip_synd,
                                                                             iop_breq_fifo1_csr_flip_synd,
                                                                             iop_breq_fifo2_csr_flip_synd,
                                                                             iop_breq_fifo3_csr_flip_synd */
#else /* Word 0 - Little Endian */
        uint64_t flip                  : 28; /**< [ 27:  0](R/W) Memory ECC flip. INTERNAL:
                                                                   <27:0>  = iobn_gmr_ixofifo_csr_flip_synd,
                                                                             sli_req_2_flip_synd and sli_preq_2_flip_synd,
                                                                             sli_req_1_flip_synd and sli_preq_1_flip_synd,
                                                                             sli_req_0_flip_synd and sli_preq_0_flip_synd,
                                                                             iobn_rsd_mem0_csr_flip_synd_rclk,
                                                                             iobn_rsd_mem1_csr_flip_synd_rclk,
                                                                             ixo_smmu_mem0_csr_flip_synd,
                                                                             ixo_smmu_mem1_csr_flip_synd,
                                                                             ixo_ics_mem_csr_flip_synd,
                                                                             iop_ffifo_csr_flip_synd,
                                                                             iop_breq_fifo0_csr_flip_synd,
                                                                             iop_breq_fifo1_csr_flip_synd,
                                                                             iop_breq_fifo2_csr_flip_synd,
                                                                             iop_breq_fifo3_csr_flip_synd */
        uint64_t reserved_28_31        : 4;
        uint64_t dis                   : 16; /**< [ 47: 32](R/W) Memory ECC disable. INTERNAL:
                                                                   <47:32>  = iobn_gmr_ixofifo_csr_cor_dis,
                                                                              sli_req_2_cor_dis and sli_preq_2_cor_dis,
                                                                              sli_req_1_cor_dis and sli_preq_1_cor_dis,
                                                                              sli_req_0_cor_dis and sli_preq_0_cor_dis,
                                                                              iob__iob_xmd_csr_cor_dis_rclk,
                                                                              ixo_smmu_mem0_csr_cor_dis,
                                                                              ixo_smmu_mem1_csr_cor_dis,
                                                                              ixo_ics_mem_csr_cor_dis,
                                                                              ixo_icc_fifo0_csr_cor_dis,
                                                                              ixo_icc_fifo1_csr_cor_dis,
                                                                              ixo_xmd_mem0_csr_cor_dis,
                                                                              ixo_xmd_mem1_csr_cor_dis,
                                                                              iobn_iorn_ffifo0__csr_cor_dis,
                                                                              iobn_iorn_ffifo1__csr_cor_dis,
                                                                              iop_ffifo_csr_cor_dis,
                                                                              ics_cmd_fifo_csr_cor_dis */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_mctlr_reg_s cn; */
} bdk_iobnx_mctlr_reg_t;

static inline uint64_t BDK_IOBNX_MCTLR_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MCTLR_REG(unsigned long a)
{
    return 0x87e0f0005108ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_MCTLR_REG(a) bdk_iobnx_mctlr_reg_t
#define bustype_BDK_IOBNX_MCTLR_REG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_MCTLR_REG(a) "IOBNX_MCTLR_REG"
#define busnum_BDK_IOBNX_MCTLR_REG(a) (a)
#define arguments_BDK_IOBNX_MCTLR_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_ncb#_ctl
 *
 * IOBN NCB Credits Register
 * This register controls the number of loads and stores each NCB can have to the L2.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_ncbx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t stp                   : 2;  /**< [  9:  8](R/W) When a complete cache block is written a STP will be converted to:
                                                                    0 = STF.
                                                                    1 = STY.
                                                                    2 = STT.
                                                                    3 = Reserved. */
        uint64_t reserved_2_7          : 6;
        uint64_t rstp                  : 2;  /**< [  1:  0](R/W) When a complete cache block is written a RSTP will be converted to:
                                                                    0 = STY.
                                                                    1 = STT.
                                                                    2 = STF.
                                                                    3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t rstp                  : 2;  /**< [  1:  0](R/W) When a complete cache block is written a RSTP will be converted to:
                                                                    0 = STY.
                                                                    1 = STT.
                                                                    2 = STF.
                                                                    3 = Reserved. */
        uint64_t reserved_2_7          : 6;
        uint64_t stp                   : 2;  /**< [  9:  8](R/W) When a complete cache block is written a STP will be converted to:
                                                                    0 = STF.
                                                                    1 = STY.
                                                                    2 = STT.
                                                                    3 = Reserved. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_ncbx_ctl_s cn; */
} bdk_iobnx_ncbx_ctl_t;

static inline uint64_t BDK_IOBNX_NCBX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCBX_CTL(unsigned long a, unsigned long b)
{
    return 0x87e0f0004000ll + 0x1000000ll * ((a) & 0x1) + 0x100ll * ((b) & 0x1);
}

#define typedef_BDK_IOBNX_NCBX_CTL(a,b) bdk_iobnx_ncbx_ctl_t
#define bustype_BDK_IOBNX_NCBX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_NCBX_CTL(a,b) "IOBNX_NCBX_CTL"
#define busnum_BDK_IOBNX_NCBX_CTL(a,b) (a)
#define arguments_BDK_IOBNX_NCBX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_dis_ncbi_io
 *
 * IOBN Disable NCBI IO Register
 * IOBN control.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_dis_ncbi_io_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t tlb_sync_dis          : 1;  /**< [  3:  3](R/W) When set the IOBN will return SYNC-RDY to the SMMU without waiting for
                                                                 outstanding request to receive responses. */
        uint64_t oci_key_only          : 1;  /**< [  2:  2](R/W) Restrict CCPI-sourced I/O write requests.

                                                                 0 = CCPI-sourced I/O read and write requests are allowed to any device through
                                                                 IOB, including allowing read/writes to all of KEY_MEM().

                                                                 1 = CCPI-sourced I/O write requests allowed to KEY_MEM(0..2047) (e.g. 16KB, not
                                                                 all of KEY_MEM) only. CCPI-sourced writes to __any__ other address
                                                                 (non-KEY_MEM(0..2047)), or any CCPI-source read will be redirected to
                                                                 ECAM0_NOP_ZF (for non-ECAM) or ECAM0_NOP_ONNF (for-ECAM).

                                                                 This setting does not affect local-node originated traffic.

                                                                 In pass 1, read-only.
                                                                 Changed in pass 2. */
        uint64_t all_gic               : 1;  /**< [  1:  1](R/W) All-to-GIC. For diagnostic use only. INTERNAL:
                                                                   0 = Normal operation. NCBI traffic to GIC interrupt delivery registers will be ordered
                                                                 with other interrupt delivery traffic and over the RIB bus.  NCBI traffic to normal non-
                                                                 interrupt-delivery GIC registers will go via RSL.
                                                                   1 = All NCBI traffic to the GIC DID will be assumed to be interrupt delivery traffic.
                                                                 This will break NCBI write transactions to non-interrupt-delivery GIC registers, but may
                                                                 work around bugs whereby interrupt-delivery CSRs are mis-catagorized inside IOB. */
        uint64_t ncbi_off              : 1;  /**< [  0:  0](R/W) When set NCBI translation to I/O space (with exception of GIC traffic) will be disabled.
                                                                 Disabled traffic will turn into access to ECAM0_NOP_ZF. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_off              : 1;  /**< [  0:  0](R/W) When set NCBI translation to I/O space (with exception of GIC traffic) will be disabled.
                                                                 Disabled traffic will turn into access to ECAM0_NOP_ZF. */
        uint64_t all_gic               : 1;  /**< [  1:  1](R/W) All-to-GIC. For diagnostic use only. INTERNAL:
                                                                   0 = Normal operation. NCBI traffic to GIC interrupt delivery registers will be ordered
                                                                 with other interrupt delivery traffic and over the RIB bus.  NCBI traffic to normal non-
                                                                 interrupt-delivery GIC registers will go via RSL.
                                                                   1 = All NCBI traffic to the GIC DID will be assumed to be interrupt delivery traffic.
                                                                 This will break NCBI write transactions to non-interrupt-delivery GIC registers, but may
                                                                 work around bugs whereby interrupt-delivery CSRs are mis-catagorized inside IOB. */
        uint64_t oci_key_only          : 1;  /**< [  2:  2](R/W) Restrict CCPI-sourced I/O write requests.

                                                                 0 = CCPI-sourced I/O read and write requests are allowed to any device through
                                                                 IOB, including allowing read/writes to all of KEY_MEM().

                                                                 1 = CCPI-sourced I/O write requests allowed to KEY_MEM(0..2047) (e.g. 16KB, not
                                                                 all of KEY_MEM) only. CCPI-sourced writes to __any__ other address
                                                                 (non-KEY_MEM(0..2047)), or any CCPI-source read will be redirected to
                                                                 ECAM0_NOP_ZF (for non-ECAM) or ECAM0_NOP_ONNF (for-ECAM).

                                                                 This setting does not affect local-node originated traffic.

                                                                 In pass 1, read-only.
                                                                 Changed in pass 2. */
        uint64_t tlb_sync_dis          : 1;  /**< [  3:  3](R/W) When set the IOBN will return SYNC-RDY to the SMMU without waiting for
                                                                 outstanding request to receive responses. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_dis_ncbi_io_s cn83xx; */
    /* struct bdk_iobnx_dis_ncbi_io_s cn88xxp2; */
    struct bdk_iobnx_dis_ncbi_io_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t tlb_sync_dis          : 1;  /**< [  3:  3](R/W) When set the IOBN will return SYNC-RDY to the SMMU without waiting for
                                                                 outstanding request to receive responses. */
        uint64_t oci_key_only          : 1;  /**< [  2:  2](RO) Restrict CCPI-sourced I/O write requests.

                                                                 0 = CCPI-sourced I/O read and write requests are allowed to any device through
                                                                 IOB, including allowing read/writes to all of KEY_MEM().

                                                                 1 = CCPI-sourced I/O write requests allowed to KEY_MEM(0..2047) (e.g. 16KB, not
                                                                 all of KEY_MEM) only. CCPI-sourced writes to __any__ other address
                                                                 (non-KEY_MEM(0..2047)), or any CCPI-source read will be redirected to
                                                                 ECAM0_NOP_ZF (for non-ECAM) or ECAM0_NOP_ONNF (for-ECAM).

                                                                 This setting does not affect local-node originated traffic.

                                                                 In pass 1, read-only. */
        uint64_t all_gic               : 1;  /**< [  1:  1](R/W) All-to-GIC. For diagnostic use only. INTERNAL:
                                                                   0 = Normal operation. NCBI traffic to GIC interrupt delivery registers will be ordered
                                                                 with other interrupt delivery traffic and over the RIB bus.  NCBI traffic to normal non-
                                                                 interrupt-delivery GIC registers will go via RSL.
                                                                   1 = All NCBI traffic to the GIC DID will be assumed to be interrupt delivery traffic.
                                                                 This will break NCBI write transactions to non-interrupt-delivery GIC registers, but may
                                                                 work around bugs whereby interrupt-delivery CSRs are mis-catagorized inside IOB. */
        uint64_t ncbi_off              : 1;  /**< [  0:  0](R/W) When set NCBI translation to I/O space (with exception of GIC traffic) will be disabled.
                                                                 Disabled traffic will turn into access to ECAM0_NOP_ZF. */
#else /* Word 0 - Little Endian */
        uint64_t ncbi_off              : 1;  /**< [  0:  0](R/W) When set NCBI translation to I/O space (with exception of GIC traffic) will be disabled.
                                                                 Disabled traffic will turn into access to ECAM0_NOP_ZF. */
        uint64_t all_gic               : 1;  /**< [  1:  1](R/W) All-to-GIC. For diagnostic use only. INTERNAL:
                                                                   0 = Normal operation. NCBI traffic to GIC interrupt delivery registers will be ordered
                                                                 with other interrupt delivery traffic and over the RIB bus.  NCBI traffic to normal non-
                                                                 interrupt-delivery GIC registers will go via RSL.
                                                                   1 = All NCBI traffic to the GIC DID will be assumed to be interrupt delivery traffic.
                                                                 This will break NCBI write transactions to non-interrupt-delivery GIC registers, but may
                                                                 work around bugs whereby interrupt-delivery CSRs are mis-catagorized inside IOB. */
        uint64_t oci_key_only          : 1;  /**< [  2:  2](RO) Restrict CCPI-sourced I/O write requests.

                                                                 0 = CCPI-sourced I/O read and write requests are allowed to any device through
                                                                 IOB, including allowing read/writes to all of KEY_MEM().

                                                                 1 = CCPI-sourced I/O write requests allowed to KEY_MEM(0..2047) (e.g. 16KB, not
                                                                 all of KEY_MEM) only. CCPI-sourced writes to __any__ other address
                                                                 (non-KEY_MEM(0..2047)), or any CCPI-source read will be redirected to
                                                                 ECAM0_NOP_ZF (for non-ECAM) or ECAM0_NOP_ONNF (for-ECAM).

                                                                 This setting does not affect local-node originated traffic.

                                                                 In pass 1, read-only. */
        uint64_t tlb_sync_dis          : 1;  /**< [  3:  3](R/W) When set the IOBN will return SYNC-RDY to the SMMU without waiting for
                                                                 outstanding request to receive responses. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_iobnx_dis_ncbi_io_t;

static inline uint64_t BDK_IOBNX_DIS_NCBI_IO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_DIS_NCBI_IO(unsigned long a)
{
    return 0x87e0f0003000ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_DIS_NCBI_IO(a) bdk_iobnx_dis_ncbi_io_t
#define bustype_BDK_IOBNX_DIS_NCBI_IO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_DIS_NCBI_IO(a) "IOBNX_DIS_NCBI_IO"
#define busnum_BDK_IOBNX_DIS_NCBI_IO(a) (a)
#define arguments_BDK_IOBNX_DIS_NCBI_IO(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_msix_pba#
 *
 * IOBN MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the IOBN_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated IOBN_MSIX_VEC()_CTL, enumerated by IOBN_INT_VEC_E.
                                                                 Bits that have no associated IOBN_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated IOBN_MSIX_VEC()_CTL, enumerated by IOBN_INT_VEC_E.
                                                                 Bits that have no associated IOBN_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_msix_pbax_s cn; */
} bdk_iobnx_msix_pbax_t;

static inline uint64_t BDK_IOBNX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    return 0x87e0f0ff0000ll + 0x1000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
}

#define typedef_BDK_IOBNX_MSIX_PBAX(a,b) bdk_iobnx_msix_pbax_t
#define bustype_BDK_IOBNX_MSIX_PBAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_MSIX_PBAX(a,b) "IOBNX_MSIX_PBAX"
#define busnum_BDK_IOBNX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_IOBNX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_msix_vec#_ctl
 *
 * IOBN MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the IOBN_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_msix_vecx_ctl_s cn; */
} bdk_iobnx_msix_vecx_ctl_t;

static inline uint64_t BDK_IOBNX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    return 0x87e0f0f00008ll + 0x1000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
}

#define typedef_BDK_IOBNX_MSIX_VECX_CTL(a,b) bdk_iobnx_msix_vecx_ctl_t
#define bustype_BDK_IOBNX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_MSIX_VECX_CTL(a,b) "IOBNX_MSIX_VECX_CTL"
#define busnum_BDK_IOBNX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_IOBNX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_mctls_reg
 *
 * IOBN Memory SControl Register
 * Contains the sclk memory control for memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_mctls_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_43_63        : 21;
        uint64_t dis                   : 11; /**< [ 42: 32](R/W) Memory ECC disable. INTERNAL:
                                                                   <42:32>  = iobn_rsd_mem0_csr_cor_dis,
                                                                              iobn_rsd_mem1_csr_cor_dis,
                                                                              irp0_flid_mem_csr_cor_dis,
                                                                              irp1_flid_mem_csr_cor_dis,
                                                                              iop_breq_fifo0_csr_cor_dis,
                                                                              iop_breq_fifo1_csr_cor_dis,
                                                                              iop_breq_fifo2_csr_cor_dis,
                                                                              iop_breq_fifo3_csr_cor_dis,
                                                                              icc_xmc_fifo_ecc_csr_cor_dis,
                                                                              icc0_xmc_fifo_csr_cor_dis,
                                                                              icc1_xmc_fifo_csr_cor_dis */
        uint64_t reserved_26_31        : 6;
        uint64_t flip                  : 26; /**< [ 25:  0](R/W) Memory ECC flip. INTERNAL:
                                                                   <25:0>  = iob__iob_xmd_csr_flip_synd_sclk,
                                                                             ixo_icc_fifo0_csr_flip_synd,
                                                                             ixo_icc_fifo1_csr_flip_synd,
                                                                             ixo_xmd_mem0_csr_flip_synd,
                                                                             ixo_xmd_mem1_csr_flip_synd,
                                                                             irp0_flid_mem_csr_flip_synd,
                                                                             irp1_flid_mem_csr_flip_synd,
                                                                             iobn_iorn_ffifo0__csr_flip_synd,
                                                                             iobn_iorn_ffifo1__csr_flip_synd,
                                                                             icc_xmc_fifo_ecc_csr_flip_synd,
                                                                             ics_cmd_fifo_csr_flip_synd,
                                                                             icc0_xmc_fifo_csr_flip_synd,
                                                                             icc1_xmc_fifo_csr_flip_synd */
#else /* Word 0 - Little Endian */
        uint64_t flip                  : 26; /**< [ 25:  0](R/W) Memory ECC flip. INTERNAL:
                                                                   <25:0>  = iob__iob_xmd_csr_flip_synd_sclk,
                                                                             ixo_icc_fifo0_csr_flip_synd,
                                                                             ixo_icc_fifo1_csr_flip_synd,
                                                                             ixo_xmd_mem0_csr_flip_synd,
                                                                             ixo_xmd_mem1_csr_flip_synd,
                                                                             irp0_flid_mem_csr_flip_synd,
                                                                             irp1_flid_mem_csr_flip_synd,
                                                                             iobn_iorn_ffifo0__csr_flip_synd,
                                                                             iobn_iorn_ffifo1__csr_flip_synd,
                                                                             icc_xmc_fifo_ecc_csr_flip_synd,
                                                                             ics_cmd_fifo_csr_flip_synd,
                                                                             icc0_xmc_fifo_csr_flip_synd,
                                                                             icc1_xmc_fifo_csr_flip_synd */
        uint64_t reserved_26_31        : 6;
        uint64_t dis                   : 11; /**< [ 42: 32](R/W) Memory ECC disable. INTERNAL:
                                                                   <42:32>  = iobn_rsd_mem0_csr_cor_dis,
                                                                              iobn_rsd_mem1_csr_cor_dis,
                                                                              irp0_flid_mem_csr_cor_dis,
                                                                              irp1_flid_mem_csr_cor_dis,
                                                                              iop_breq_fifo0_csr_cor_dis,
                                                                              iop_breq_fifo1_csr_cor_dis,
                                                                              iop_breq_fifo2_csr_cor_dis,
                                                                              iop_breq_fifo3_csr_cor_dis,
                                                                              icc_xmc_fifo_ecc_csr_cor_dis,
                                                                              icc0_xmc_fifo_csr_cor_dis,
                                                                              icc1_xmc_fifo_csr_cor_dis */
        uint64_t reserved_43_63        : 21;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_mctls_reg_s cn; */
} bdk_iobnx_mctls_reg_t;

static inline uint64_t BDK_IOBNX_MCTLS_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MCTLS_REG(unsigned long a)
{
    return 0x87e0f0005100ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_MCTLS_REG(a) bdk_iobnx_mctls_reg_t
#define bustype_BDK_IOBNX_MCTLS_REG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_MCTLS_REG(a) "IOBNX_MCTLS_REG"
#define busnum_BDK_IOBNX_MCTLS_REG(a) (a)
#define arguments_BDK_IOBNX_MCTLS_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_core_bist_status
 *
 * IOBN Cores BIST Status Register
 * This register contains the result of the BIST run on the cores.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_core_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t core_bstat            : 24; /**< [ 23:  0](RO/H) BIST status of the cores. IOBN0 contains the BIST status for the even numbered cores and
                                                                 IOBN1 contains the BIST status for the odd numbered cores.

                                                                 <pre>
                                                                    BIT    IOBN0     IOBN1
                                                                    [0]    Core 0    Core 1
                                                                    [1]    Core 2    Core 3
                                                                    ...
                                                                    [23]   Core 46   Core 47
                                                                 </pre> */
#else /* Word 0 - Little Endian */
        uint64_t core_bstat            : 24; /**< [ 23:  0](RO/H) BIST status of the cores. IOBN0 contains the BIST status for the even numbered cores and
                                                                 IOBN1 contains the BIST status for the odd numbered cores.

                                                                 <pre>
                                                                    BIT    IOBN0     IOBN1
                                                                    [0]    Core 0    Core 1
                                                                    [1]    Core 2    Core 3
                                                                    ...
                                                                    [23]   Core 46   Core 47
                                                                 </pre> */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_core_bist_status_s cn; */
} bdk_iobnx_core_bist_status_t;

static inline uint64_t BDK_IOBNX_CORE_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CORE_BIST_STATUS(unsigned long a)
{
    return 0x87e0f0005008ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_CORE_BIST_STATUS(a) bdk_iobnx_core_bist_status_t
#define bustype_BDK_IOBNX_CORE_BIST_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_CORE_BIST_STATUS(a) "IOBNX_CORE_BIST_STATUS"
#define busnum_BDK_IOBNX_CORE_BIST_STATUS(a) (a)
#define arguments_BDK_IOBNX_CORE_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_msix_vec#_addr
 *
 * IOBN MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the IOBN_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's IOBN_MSIX_VEC()_ADDR, IOBN_MSIX_VEC()_CTL, and corresponding
                                                                 bit of IOBN_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_IOBN_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's IOBN_MSIX_VEC()_ADDR, IOBN_MSIX_VEC()_CTL, and corresponding
                                                                 bit of IOBN_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_IOBN_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_msix_vecx_addr_s cn; */
} bdk_iobnx_msix_vecx_addr_t;

static inline uint64_t BDK_IOBNX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    return 0x87e0f0f00000ll + 0x1000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
}

#define typedef_BDK_IOBNX_MSIX_VECX_ADDR(a,b) bdk_iobnx_msix_vecx_addr_t
#define bustype_BDK_IOBNX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_MSIX_VECX_ADDR(a,b) "IOBNX_MSIX_VECX_ADDR"
#define busnum_BDK_IOBNX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_IOBNX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) iobn#_bistr_reg
 *
 * IOBN BIST Status Register
 * This register contains the result of the BIST run on the IOB rclk memories.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_bistr_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t status                : 19; /**< [ 18:  0](RO/H) Memory BIST status. INTERNAL:
                                                                   <18> = gmr_ixofifo_bstatus_rclk.
                                                                   <17> = sli_preq_2_ffifo_bstatus_rclk.
                                                                   <16> = sli_req_2_ffifo_bstatus_rclk.
                                                                   <15> = sli_preq_1_ffifo_bstatus_rclk.
                                                                   <14> = sli_req_1_ffifo_bstatus_rclk.
                                                                   <13> = sli_preq_0_ffifo_bstatus_rclk.
                                                                   <12> = sli_req_0_ffifo_bstatus_rclk.
                                                                   <11> = iop_ffifo_bstatus_rclk.
                                                                   <10> = ixo_icc_fifo0_bstatus_rclk.
                                                                   <9> = ixo_icc_fifo1_bstatus_rclk.
                                                                   <8>  = ixo_ics_mem_bstatus_rclk.
                                                                   <7>  = iob_mem_data_xmd0_bstatus_rclk.
                                                                   <6>  = iob_mem_data_xmd1_bstatus_rclk.
                                                                   <5>  = ics_cmd_fifo_bstatus_rclk.
                                                                   <4>  = ixo_xmd_mem0_bstatus_rclk.
                                                                   <3>  = ixo_xmd_mem1_bstatus_rclk.
                                                                   <2>  = iobn_iorn_ffifo0_bstatus_rclk.
                                                                   <1>  = iobn_iorn_ffifo1_bstatus_rclk.
                                                                   <0>  = ixo_smmu_mem0_bstatus_rclk. */
#else /* Word 0 - Little Endian */
        uint64_t status                : 19; /**< [ 18:  0](RO/H) Memory BIST status. INTERNAL:
                                                                   <18> = gmr_ixofifo_bstatus_rclk.
                                                                   <17> = sli_preq_2_ffifo_bstatus_rclk.
                                                                   <16> = sli_req_2_ffifo_bstatus_rclk.
                                                                   <15> = sli_preq_1_ffifo_bstatus_rclk.
                                                                   <14> = sli_req_1_ffifo_bstatus_rclk.
                                                                   <13> = sli_preq_0_ffifo_bstatus_rclk.
                                                                   <12> = sli_req_0_ffifo_bstatus_rclk.
                                                                   <11> = iop_ffifo_bstatus_rclk.
                                                                   <10> = ixo_icc_fifo0_bstatus_rclk.
                                                                   <9> = ixo_icc_fifo1_bstatus_rclk.
                                                                   <8>  = ixo_ics_mem_bstatus_rclk.
                                                                   <7>  = iob_mem_data_xmd0_bstatus_rclk.
                                                                   <6>  = iob_mem_data_xmd1_bstatus_rclk.
                                                                   <5>  = ics_cmd_fifo_bstatus_rclk.
                                                                   <4>  = ixo_xmd_mem0_bstatus_rclk.
                                                                   <3>  = ixo_xmd_mem1_bstatus_rclk.
                                                                   <2>  = iobn_iorn_ffifo0_bstatus_rclk.
                                                                   <1>  = iobn_iorn_ffifo1_bstatus_rclk.
                                                                   <0>  = ixo_smmu_mem0_bstatus_rclk. */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_bistr_reg_s cn; */
} bdk_iobnx_bistr_reg_t;

static inline uint64_t BDK_IOBNX_BISTR_REG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_BISTR_REG(unsigned long a)
{
    return 0x87e0f0005080ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_BISTR_REG(a) bdk_iobnx_bistr_reg_t
#define bustype_BDK_IOBNX_BISTR_REG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_BISTR_REG(a) "IOBNX_BISTR_REG"
#define busnum_BDK_IOBNX_BISTR_REG(a) (a)
#define arguments_BDK_IOBNX_BISTR_REG(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_chip_pwr_out
 *
 * IOBN Chip Power Out Register
 * This register contains power numbers from the various partitions on the chip.
 * Only index zero (IOB(0)) is used.
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_chip_pwr_out_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cpu_pwr               : 16; /**< [ 63: 48](RO/H) An estimate of the current CPU core complex power consumption. The CPU core complex
                                                                 includes the caches and DRAM controller(s), as well as all CPU cores. Linearly larger
                                                                 values indicate linearly higher power consumption. This power consumption estimate is
                                                                 energy per core clock. */
        uint64_t chip_power            : 16; /**< [ 47: 32](RO/H) An estimate of the current total power consumption by the chip. Linearly larger values
                                                                 indicate linearly higher power consumption. CHIP_POWER is the sum of CPU_POWER and
                                                                 COPROC_POWER. */
        uint64_t coproc_power          : 16; /**< [ 31: 16](RO/H) An estimate of the current coprocessor power consumption. Linearly larger values indicate
                                                                 linearly higher power consumption. This estimate is energy per core clock, and will
                                                                 generally decrease as the ratio of core to coprocessor clock speed increases. */
        uint64_t avg_chip_power        : 16; /**< [ 15:  0](RO/H) An average of CHIP_POWER, calculated using an IIR filter with an average weight of 16K core clocks. */
#else /* Word 0 - Little Endian */
        uint64_t avg_chip_power        : 16; /**< [ 15:  0](RO/H) An average of CHIP_POWER, calculated using an IIR filter with an average weight of 16K core clocks. */
        uint64_t coproc_power          : 16; /**< [ 31: 16](RO/H) An estimate of the current coprocessor power consumption. Linearly larger values indicate
                                                                 linearly higher power consumption. This estimate is energy per core clock, and will
                                                                 generally decrease as the ratio of core to coprocessor clock speed increases. */
        uint64_t chip_power            : 16; /**< [ 47: 32](RO/H) An estimate of the current total power consumption by the chip. Linearly larger values
                                                                 indicate linearly higher power consumption. CHIP_POWER is the sum of CPU_POWER and
                                                                 COPROC_POWER. */
        uint64_t cpu_pwr               : 16; /**< [ 63: 48](RO/H) An estimate of the current CPU core complex power consumption. The CPU core complex
                                                                 includes the caches and DRAM controller(s), as well as all CPU cores. Linearly larger
                                                                 values indicate linearly higher power consumption. This power consumption estimate is
                                                                 energy per core clock. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_chip_pwr_out_s cn; */
} bdk_iobnx_chip_pwr_out_t;

static inline uint64_t BDK_IOBNX_CHIP_PWR_OUT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CHIP_PWR_OUT(unsigned long a)
{
    return 0x87e0f000a108ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_CHIP_PWR_OUT(a) bdk_iobnx_chip_pwr_out_t
#define bustype_BDK_IOBNX_CHIP_PWR_OUT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_CHIP_PWR_OUT(a) "IOBNX_CHIP_PWR_OUT"
#define busnum_BDK_IOBNX_CHIP_PWR_OUT(a) (a)
#define arguments_BDK_IOBNX_CHIP_PWR_OUT(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_test
 *
 * INTERNAL: IOBN Test Register
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_test_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t gibarb_testmode       : 1;  /**< [  0:  0](R/W) When set, the IOBN GIB arbiters will only grant one requestor at a time. */
#else /* Word 0 - Little Endian */
        uint64_t gibarb_testmode       : 1;  /**< [  0:  0](R/W) When set, the IOBN GIB arbiters will only grant one requestor at a time. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_test_s cn; */
} bdk_iobnx_test_t;

static inline uint64_t BDK_IOBNX_TEST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_TEST(unsigned long a)
{
    return 0x87e0f0003010ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_TEST(a) bdk_iobnx_test_t
#define bustype_BDK_IOBNX_TEST(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_TEST(a) "IOBNX_TEST"
#define busnum_BDK_IOBNX_TEST(a) (a)
#define arguments_BDK_IOBNX_TEST(a) (a),-1,-1,-1

/**
 * Register (RSL) iobn#_ncb0_hp
 *
 * IOBN NCBI0 High Performance Register
 */
typedef union
{
    uint64_t u;
    struct bdk_iobnx_ncb0_hp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t hp                    : 1;  /**< [  0:  0](R/W) When set, NCBI 0 ARB 0 will use the high performance path through the IOBN. */
#else /* Word 0 - Little Endian */
        uint64_t hp                    : 1;  /**< [  0:  0](R/W) When set, NCBI 0 ARB 0 will use the high performance path through the IOBN. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_iobnx_ncb0_hp_s cn; */
} bdk_iobnx_ncb0_hp_t;

static inline uint64_t BDK_IOBNX_NCB0_HP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCB0_HP(unsigned long a)
{
    return 0x87e0f0003008ll + 0x1000000ll * ((a) & 0x1);
}

#define typedef_BDK_IOBNX_NCB0_HP(a) bdk_iobnx_ncb0_hp_t
#define bustype_BDK_IOBNX_NCB0_HP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_IOBNX_NCB0_HP(a) "IOBNX_NCB0_HP"
#define busnum_BDK_IOBNX_NCB0_HP(a) (a)
#define arguments_BDK_IOBNX_NCB0_HP(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_IOBN_H__ */
