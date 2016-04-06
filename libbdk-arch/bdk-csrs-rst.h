#ifndef __BDK_CSRS_RST_H__
#define __BDK_CSRS_RST_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
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
 * Cavium RST.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration rst_bar_e
 *
 * RST Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_RST_BAR_E_RST_PF_BAR0 (0x87e006000000ll)
#define BDK_RST_BAR_E_RST_PF_BAR4 (0x87e006f00000ll)

/**
 * Enumeration rst_boot_fail_e
 *
 * RST Boot Failure Code Enumeration
 * Enumerates the reasons for boot failure, returned to post-boot code
 * in argument register 0 and blinked on GPIO<11>.
 */
#define BDK_RST_BOOT_FAIL_E_AUTH (6)
#define BDK_RST_BOOT_FAIL_E_DEVICE (3)
#define BDK_RST_BOOT_FAIL_E_GOOD (0)
#define BDK_RST_BOOT_FAIL_E_MAGIC (4)
#define BDK_RST_BOOT_FAIL_E_MCORE (5)
#define BDK_RST_BOOT_FAIL_E_METH (2)

/**
 * Enumeration rst_boot_method_e
 *
 * RST Boot-strap Method Enumeration
 * Enumerates GPIO_STRAP<3:0>, which determines the method used to boot the cores.
 */
#define BDK_RST_BOOT_METHOD_E_CCPI0 (9)
#define BDK_RST_BOOT_METHOD_E_CCPI1 (0xa)
#define BDK_RST_BOOT_METHOD_E_CCPI2 (0xb)
#define BDK_RST_BOOT_METHOD_E_EMMC_LS (3)
#define BDK_RST_BOOT_METHOD_E_EMMC_SS (2)
#define BDK_RST_BOOT_METHOD_E_PCIE0 (0xc)
#define BDK_RST_BOOT_METHOD_E_PCIE2 (0xd)
#define BDK_RST_BOOT_METHOD_E_REMOTE (8)
#define BDK_RST_BOOT_METHOD_E_SPI24 (5)
#define BDK_RST_BOOT_METHOD_E_SPI32 (6)

/**
 * Enumeration rst_int_vec_e
 *
 * RST MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_RST_INT_VEC_E_INTS (0)

/**
 * Structure rst_pp_pwr_s
 *
 * INTERNAL: Core Reset Power Delivery Structure
 *
 * This structure specifies the layout of RTL reset and power delivery. It is not visible to software.
 */
union bdk_rst_pp_pwr_s
{
    uint32_t u;
    struct bdk_rst_pp_pwr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_10_31        : 22;
        uint32_t valid                 : 1;  /**< [  9:  9] Data transmitted on interface is valid.. */
        uint32_t ppvid                 : 6;  /**< [  8:  3] Virtual core number. */
        uint32_t dbg_rst               : 1;  /**< [  2:  2] Reset control for the core specified by PPVID. */
        uint32_t pwrdwn                : 1;  /**< [  1:  1] Core does not require power. */
        uint32_t rst                   : 1;  /**< [  0:  0] Reset control for the core specified by PPVID. */
#else /* Word 0 - Little Endian */
        uint32_t rst                   : 1;  /**< [  0:  0] Reset control for the core specified by PPVID. */
        uint32_t pwrdwn                : 1;  /**< [  1:  1] Core does not require power. */
        uint32_t dbg_rst               : 1;  /**< [  2:  2] Reset control for the core specified by PPVID. */
        uint32_t ppvid                 : 6;  /**< [  8:  3] Virtual core number. */
        uint32_t valid                 : 1;  /**< [  9:  9] Data transmitted on interface is valid.. */
        uint32_t reserved_10_31        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_pp_pwr_s_s cn; */
};

/**
 * Register (RSL) rst_bist_timer
 *
 * INTERNAL: RST BIST Timer Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_bist_timer_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t count                 : 29; /**< [ 28:  0](RO) Number of 50 MHz reference clocks that have elapsed during BIST and repair during the last
                                                                 reset.
                                                                 If MSB is set the BIST chain did not complete as expected. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 29; /**< [ 28:  0](RO) Number of 50 MHz reference clocks that have elapsed during BIST and repair during the last
                                                                 reset.
                                                                 If MSB is set the BIST chain did not complete as expected. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_bist_timer_s cn; */
} bdk_rst_bist_timer_t;

#define BDK_RST_BIST_TIMER BDK_RST_BIST_TIMER_FUNC()
static inline uint64_t BDK_RST_BIST_TIMER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_BIST_TIMER_FUNC(void)
{
    return 0x87e006001760ll;
}

#define typedef_BDK_RST_BIST_TIMER bdk_rst_bist_timer_t
#define bustype_BDK_RST_BIST_TIMER BDK_CSR_TYPE_RSL
#define basename_BDK_RST_BIST_TIMER "RST_BIST_TIMER"
#define device_bar_BDK_RST_BIST_TIMER 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_BIST_TIMER 0
#define arguments_BDK_RST_BIST_TIMER -1,-1,-1,-1

/**
 * Register (RSL) rst_boot
 *
 * RST Boot Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_boot_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t chipkill              : 1;  /**< [ 63: 63](R/W1S) A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL=1 and the timer
                                                                 expires, chip reset is asserted internally. The CHIPKILL timer can be stopped only by
                                                                 a reset (cold, warm, soft). The length of the CHIPKILL timer is specified by
                                                                 RST_CKILL[TIMER]. This feature is effectively a delayed warm reset. */
        uint64_t jtcsrdis              : 1;  /**< [ 62: 62](R/W) JTAG CSR disable. When set to 1, during the next warm or soft reset the JTAG TAP
                                                                 controller will be disabled, i.e. DAP_IMP_DAR will be 0. This field resets to 1
                                                                 in trusted-mode, else 0. */
        uint64_t ejtagdis              : 1;  /**< [ 61: 61](R/W) Reserved. */
        uint64_t trusted_mode          : 1;  /**< [ 60: 60](RO) When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP<10> are set. */
        uint64_t ckill_ppdis           : 1;  /**< [ 59: 59](R/W) Chipkill core disable. When set to 1, cores other than core 0 will immediately
                                                                 be disabled when RST_BOOT[CHIPKILL] is set. Writes have no effect when
                                                                 RST_BOOT[CHIPKILL]=1. */
        uint64_t jt_tstmode            : 1;  /**< [ 58: 58](RO) JTAG test mode. */
        uint64_t vrm_err               : 1;  /**< [ 57: 57](RO) VRM error. VRM did not complete operations within 5.25ms of PLL_DC_OK being
                                                                 asserted. PLLs were released automatically. */
        uint64_t dis_huk               : 1;  /**< [ 56: 56](R/W1S) Disable HUK. Secure only and W1S set-only. When set FUSF_SSK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW() cannot be read.
                                                                 Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
        uint64_t dis_scan              : 1;  /**< [ 55: 55](R/W1S) Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.

                                                                 Internal:
                                                                 This state will persist across a simulation */
        uint64_t reserved_47_54        : 8;
        uint64_t c_mul                 : 7;  /**< [ 46: 40](RO/H) Core-clock multiplier. [C_MUL] = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [C_MUL] is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123]. If the fuse value is > 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_39           : 1;
        uint64_t pnr_mul               : 6;  /**< [ 38: 33](RO/H) Coprocessor-clock multiplier. [PNR_MUL] = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [PNR_MUL] is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119]. If the fuse value is > 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
        uint64_t lboot_oci             : 3;  /**< [ 32: 30](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 <32> = Warm reset due to CCPI link 2 going down.
                                                                 <31> = Warm reset due to CCPI link 1 going down.
                                                                 <30> = Warm reset due to CCPI link 0 going down. */
        uint64_t lboot_pf_flr          : 4;  /**< [ 29: 26](R/W1C/H) Last boot cause was caused by a PF Function Level Reset event.
                                                                 <29> = Warm reset due to PF FLR on PEM3.
                                                                 <28> = Warm reset due to PF FLR on PEM2.
                                                                 <27> = Warm reset due to PF FLR on PEM1.
                                                                 <26> = Warm reset due to PF FLR on PEM0. */
        uint64_t lboot_ckill           : 1;  /**< [ 25: 25](R/W1C/H) Last boot cause was chip kill timer expiring.  See RST_BOOT[CHIPKILL]. */
        uint64_t lboot_jtg             : 1;  /**< [ 24: 24](R/W1C/H) Last boot cause was write to JTG reset. */
        uint64_t lboot_ext45           : 6;  /**< [ 23: 18](R/W1C/H) Reserved. */
        uint64_t lboot_ext23           : 6;  /**< [ 17: 12](R/W1C/H) Last boot cause mask for PEM3 and PEM2; resets only with PLL_DC_OK.
                                                                 <17> = Warm reset due to Cntl3 link-down or hot-reset.
                                                                 <16> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 <15> = Cntl3 reset due to PERST3_L pin.
                                                                 <14> = Cntl2 reset due to PERST2_L pin.
                                                                 <13> = Warm reset due to PERST3_L pin.
                                                                 <12> = Warm reset due to PERST2_L pin. */
        uint64_t lboot                 : 10; /**< [ 11:  2](R/W1C/H) Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 <11> = Soft reset due to watchdog.
                                                                 <10> = Soft reset due to RST_SOFT_RST write.
                                                                 <9> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 <8> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 <7> = Cntl1 reset due to PERST1_L pin.
                                                                 <6> = Cntl0 reset due to PERST0_L pin.
                                                                 <5> = Warm reset due to PERST1_L pin.
                                                                 <4> = Warm reset due to PERST0_L pin.
                                                                 <3> = Warm reset due to CHIP_RESET_L pin.
                                                                 <2> = Cold reset due to PLL_DC_OK pin. */
        uint64_t rboot                 : 1;  /**< [  1:  1](R/W) Remote boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset. The initial value mimics the setting of the [RBOOT_PIN]. */
        uint64_t rboot_pin             : 1;  /**< [  0:  0](RO/H) Remote Boot strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
#else /* Word 0 - Little Endian */
        uint64_t rboot_pin             : 1;  /**< [  0:  0](RO/H) Remote Boot strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
        uint64_t rboot                 : 1;  /**< [  1:  1](R/W) Remote boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset. The initial value mimics the setting of the [RBOOT_PIN]. */
        uint64_t lboot                 : 10; /**< [ 11:  2](R/W1C/H) Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 <11> = Soft reset due to watchdog.
                                                                 <10> = Soft reset due to RST_SOFT_RST write.
                                                                 <9> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 <8> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 <7> = Cntl1 reset due to PERST1_L pin.
                                                                 <6> = Cntl0 reset due to PERST0_L pin.
                                                                 <5> = Warm reset due to PERST1_L pin.
                                                                 <4> = Warm reset due to PERST0_L pin.
                                                                 <3> = Warm reset due to CHIP_RESET_L pin.
                                                                 <2> = Cold reset due to PLL_DC_OK pin. */
        uint64_t lboot_ext23           : 6;  /**< [ 17: 12](R/W1C/H) Last boot cause mask for PEM3 and PEM2; resets only with PLL_DC_OK.
                                                                 <17> = Warm reset due to Cntl3 link-down or hot-reset.
                                                                 <16> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 <15> = Cntl3 reset due to PERST3_L pin.
                                                                 <14> = Cntl2 reset due to PERST2_L pin.
                                                                 <13> = Warm reset due to PERST3_L pin.
                                                                 <12> = Warm reset due to PERST2_L pin. */
        uint64_t lboot_ext45           : 6;  /**< [ 23: 18](R/W1C/H) Reserved. */
        uint64_t lboot_jtg             : 1;  /**< [ 24: 24](R/W1C/H) Last boot cause was write to JTG reset. */
        uint64_t lboot_ckill           : 1;  /**< [ 25: 25](R/W1C/H) Last boot cause was chip kill timer expiring.  See RST_BOOT[CHIPKILL]. */
        uint64_t lboot_pf_flr          : 4;  /**< [ 29: 26](R/W1C/H) Last boot cause was caused by a PF Function Level Reset event.
                                                                 <29> = Warm reset due to PF FLR on PEM3.
                                                                 <28> = Warm reset due to PF FLR on PEM2.
                                                                 <27> = Warm reset due to PF FLR on PEM1.
                                                                 <26> = Warm reset due to PF FLR on PEM0. */
        uint64_t lboot_oci             : 3;  /**< [ 32: 30](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 <32> = Warm reset due to CCPI link 2 going down.
                                                                 <31> = Warm reset due to CCPI link 1 going down.
                                                                 <30> = Warm reset due to CCPI link 0 going down. */
        uint64_t pnr_mul               : 6;  /**< [ 38: 33](RO/H) Coprocessor-clock multiplier. [PNR_MUL] = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [PNR_MUL] is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119]. If the fuse value is > 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_39           : 1;
        uint64_t c_mul                 : 7;  /**< [ 46: 40](RO/H) Core-clock multiplier. [C_MUL] = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [C_MUL] is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123]. If the fuse value is > 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_47_54        : 8;
        uint64_t dis_scan              : 1;  /**< [ 55: 55](R/W1S) Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.

                                                                 Internal:
                                                                 This state will persist across a simulation */
        uint64_t dis_huk               : 1;  /**< [ 56: 56](R/W1S) Disable HUK. Secure only and W1S set-only. When set FUSF_SSK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW() cannot be read.
                                                                 Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
        uint64_t vrm_err               : 1;  /**< [ 57: 57](RO) VRM error. VRM did not complete operations within 5.25ms of PLL_DC_OK being
                                                                 asserted. PLLs were released automatically. */
        uint64_t jt_tstmode            : 1;  /**< [ 58: 58](RO) JTAG test mode. */
        uint64_t ckill_ppdis           : 1;  /**< [ 59: 59](R/W) Chipkill core disable. When set to 1, cores other than core 0 will immediately
                                                                 be disabled when RST_BOOT[CHIPKILL] is set. Writes have no effect when
                                                                 RST_BOOT[CHIPKILL]=1. */
        uint64_t trusted_mode          : 1;  /**< [ 60: 60](RO) When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP<10> are set. */
        uint64_t ejtagdis              : 1;  /**< [ 61: 61](R/W) Reserved. */
        uint64_t jtcsrdis              : 1;  /**< [ 62: 62](R/W) JTAG CSR disable. When set to 1, during the next warm or soft reset the JTAG TAP
                                                                 controller will be disabled, i.e. DAP_IMP_DAR will be 0. This field resets to 1
                                                                 in trusted-mode, else 0. */
        uint64_t chipkill              : 1;  /**< [ 63: 63](R/W1S) A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL=1 and the timer
                                                                 expires, chip reset is asserted internally. The CHIPKILL timer can be stopped only by
                                                                 a reset (cold, warm, soft). The length of the CHIPKILL timer is specified by
                                                                 RST_CKILL[TIMER]. This feature is effectively a delayed warm reset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_boot_s cn9; */
    struct bdk_rst_boot_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t chipkill              : 1;  /**< [ 63: 63](R/W1S) A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL=1 and the timer
                                                                 expires, chip reset is asserted internally. The CHIPKILL timer can be stopped only by
                                                                 a reset (cold, warm, soft). The length of the CHIPKILL timer is specified by
                                                                 RST_CKILL[TIMER]. This feature is effectively a delayed warm reset. */
        uint64_t jtcsrdis              : 1;  /**< [ 62: 62](R/W) JTAG CSR disable. When set to 1, during the next warm or soft reset the JTAG TAP
                                                                 controller will be disabled, i.e. DAP_IMP_DAR will be 0. This field resets to 1
                                                                 in trusted-mode, else 0. */
        uint64_t ejtagdis              : 1;  /**< [ 61: 61](R/W) Reserved. */
        uint64_t trusted_mode          : 1;  /**< [ 60: 60](RO) When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP<10> are set. */
        uint64_t ckill_ppdis           : 1;  /**< [ 59: 59](R/W) Chipkill core disable. When set to 1, cores other than core 0 will immediately
                                                                 be disabled when RST_BOOT[CHIPKILL] is set. Writes have no effect when
                                                                 RST_BOOT[CHIPKILL]=1. */
        uint64_t jt_tstmode            : 1;  /**< [ 58: 58](RO) JTAG test mode. */
        uint64_t vrm_err               : 1;  /**< [ 57: 57](RO) Reserved. */
        uint64_t dis_huk               : 1;  /**< [ 56: 56](R/W1S) Disable HUK. Secure only and W1S set-only. When set FUSF_SSK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW() cannot be read.
                                                                 Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
        uint64_t dis_scan              : 1;  /**< [ 55: 55](R/W1S) Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.

                                                                 Internal:
                                                                 This state will persist across a simulation */
        uint64_t reserved_47_54        : 8;
        uint64_t c_mul                 : 7;  /**< [ 46: 40](RO/H) Core-clock multiplier. [C_MUL] = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [C_MUL] is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123]. If the fuse value is > 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_39           : 1;
        uint64_t pnr_mul               : 6;  /**< [ 38: 33](RO/H) Coprocessor-clock multiplier. [PNR_MUL] = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [PNR_MUL] is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119]. If the fuse value is > 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
        uint64_t lboot_oci             : 3;  /**< [ 32: 30](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 <32> = Warm reset due to CCPI link 2 going down.
                                                                 <31> = Warm reset due to CCPI link 1 going down.
                                                                 <30> = Warm reset due to CCPI link 0 going down. */
        uint64_t reserved_26_29        : 4;
        uint64_t lboot_ckill           : 1;  /**< [ 25: 25](R/W1C/H) Last boot cause was chip kill timer expiring.  See RST_BOOT[CHIPKILL]. */
        uint64_t lboot_jtg             : 1;  /**< [ 24: 24](R/W1C/H) Last boot cause was write to JTG reset. */
        uint64_t lboot_ext45           : 6;  /**< [ 23: 18](R/W1C/H) Reserved. */
        uint64_t lboot_ext23           : 6;  /**< [ 17: 12](R/W1C/H) Last boot cause mask for PEM2; resets only with PLL_DC_OK.
                                                                 <17> = Reserved
                                                                 <16> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 <15> = Reserved
                                                                 <14> = Cntl2 reset due to PERST2_L pin.
                                                                 <13> = Reserved
                                                                 <12> = Warm reset due to PERST2_L pin. */
        uint64_t lboot                 : 10; /**< [ 11:  2](R/W1C/H) Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 <11> = Soft reset due to watchdog.
                                                                 <10> = Soft reset due to RST_SOFT_RST write.
                                                                 <9> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 <8> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 <7> = Cntl1 reset due to PERST1_L pin.
                                                                 <6> = Cntl0 reset due to PERST0_L pin.
                                                                 <5> = Warm reset due to PERST1_L pin.
                                                                 <4> = Warm reset due to PERST0_L pin.
                                                                 <3> = Warm reset due to CHIP_RESET_L pin.
                                                                 <2> = Cold reset due to PLL_DC_OK pin. */
        uint64_t rboot                 : 1;  /**< [  1:  1](R/W) Remote boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset. The initial value mimics the setting of the [RBOOT_PIN]. */
        uint64_t rboot_pin             : 1;  /**< [  0:  0](RO/H) Remote Boot strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
#else /* Word 0 - Little Endian */
        uint64_t rboot_pin             : 1;  /**< [  0:  0](RO/H) Remote Boot strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
        uint64_t rboot                 : 1;  /**< [  1:  1](R/W) Remote boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset. The initial value mimics the setting of the [RBOOT_PIN]. */
        uint64_t lboot                 : 10; /**< [ 11:  2](R/W1C/H) Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 <11> = Soft reset due to watchdog.
                                                                 <10> = Soft reset due to RST_SOFT_RST write.
                                                                 <9> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 <8> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 <7> = Cntl1 reset due to PERST1_L pin.
                                                                 <6> = Cntl0 reset due to PERST0_L pin.
                                                                 <5> = Warm reset due to PERST1_L pin.
                                                                 <4> = Warm reset due to PERST0_L pin.
                                                                 <3> = Warm reset due to CHIP_RESET_L pin.
                                                                 <2> = Cold reset due to PLL_DC_OK pin. */
        uint64_t lboot_ext23           : 6;  /**< [ 17: 12](R/W1C/H) Last boot cause mask for PEM2; resets only with PLL_DC_OK.
                                                                 <17> = Reserved
                                                                 <16> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 <15> = Reserved
                                                                 <14> = Cntl2 reset due to PERST2_L pin.
                                                                 <13> = Reserved
                                                                 <12> = Warm reset due to PERST2_L pin. */
        uint64_t lboot_ext45           : 6;  /**< [ 23: 18](R/W1C/H) Reserved. */
        uint64_t lboot_jtg             : 1;  /**< [ 24: 24](R/W1C/H) Last boot cause was write to JTG reset. */
        uint64_t lboot_ckill           : 1;  /**< [ 25: 25](R/W1C/H) Last boot cause was chip kill timer expiring.  See RST_BOOT[CHIPKILL]. */
        uint64_t reserved_26_29        : 4;
        uint64_t lboot_oci             : 3;  /**< [ 32: 30](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 <32> = Warm reset due to CCPI link 2 going down.
                                                                 <31> = Warm reset due to CCPI link 1 going down.
                                                                 <30> = Warm reset due to CCPI link 0 going down. */
        uint64_t pnr_mul               : 6;  /**< [ 38: 33](RO/H) Coprocessor-clock multiplier. [PNR_MUL] = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [PNR_MUL] is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119]. If the fuse value is > 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_39           : 1;
        uint64_t c_mul                 : 7;  /**< [ 46: 40](RO/H) Core-clock multiplier. [C_MUL] = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [C_MUL] is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123]. If the fuse value is > 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_47_54        : 8;
        uint64_t dis_scan              : 1;  /**< [ 55: 55](R/W1S) Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.

                                                                 Internal:
                                                                 This state will persist across a simulation */
        uint64_t dis_huk               : 1;  /**< [ 56: 56](R/W1S) Disable HUK. Secure only and W1S set-only. When set FUSF_SSK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW() cannot be read.
                                                                 Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
        uint64_t vrm_err               : 1;  /**< [ 57: 57](RO) Reserved. */
        uint64_t jt_tstmode            : 1;  /**< [ 58: 58](RO) JTAG test mode. */
        uint64_t ckill_ppdis           : 1;  /**< [ 59: 59](R/W) Chipkill core disable. When set to 1, cores other than core 0 will immediately
                                                                 be disabled when RST_BOOT[CHIPKILL] is set. Writes have no effect when
                                                                 RST_BOOT[CHIPKILL]=1. */
        uint64_t trusted_mode          : 1;  /**< [ 60: 60](RO) When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP<10> are set. */
        uint64_t ejtagdis              : 1;  /**< [ 61: 61](R/W) Reserved. */
        uint64_t jtcsrdis              : 1;  /**< [ 62: 62](R/W) JTAG CSR disable. When set to 1, during the next warm or soft reset the JTAG TAP
                                                                 controller will be disabled, i.e. DAP_IMP_DAR will be 0. This field resets to 1
                                                                 in trusted-mode, else 0. */
        uint64_t chipkill              : 1;  /**< [ 63: 63](R/W1S) A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL=1 and the timer
                                                                 expires, chip reset is asserted internally. The CHIPKILL timer can be stopped only by
                                                                 a reset (cold, warm, soft). The length of the CHIPKILL timer is specified by
                                                                 RST_CKILL[TIMER]. This feature is effectively a delayed warm reset. */
#endif /* Word 0 - End */
    } cn81xx;
    struct bdk_rst_boot_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t chipkill              : 1;  /**< [ 63: 63](R/W1S) A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL=1 and the timer
                                                                 expires, chip reset is asserted internally. The CHIPKILL timer can be stopped only by
                                                                 a reset (cold, warm, soft). The length of the CHIPKILL timer is specified by
                                                                 RST_CKILL[TIMER]. This feature is effectively a delayed warm reset. */
        uint64_t jtcsrdis              : 1;  /**< [ 62: 62](R/W) JTAG CSR disable. When set to 1, during the next warm or soft reset the JTAG TAP
                                                                 controller will be disabled, i.e. DAP_IMP_DAR will be 0. This field resets to 1
                                                                 in trusted-mode, else 0. */
        uint64_t ejtagdis              : 1;  /**< [ 61: 61](R/W) Reserved. */
        uint64_t trusted_mode          : 1;  /**< [ 60: 60](RO) When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP<10> are set. */
        uint64_t ckill_ppdis           : 1;  /**< [ 59: 59](R/W) Chipkill core disable. When set to 1, cores other than core 0 will immediately
                                                                 be disabled when RST_BOOT[CHIPKILL] is set. Writes have no effect when
                                                                 RST_BOOT[CHIPKILL]=1. */
        uint64_t jt_tstmode            : 1;  /**< [ 58: 58](RO) JTAG test mode. */
        uint64_t vrm_err               : 1;  /**< [ 57: 57](RO) VRM error. VRM did not complete operations within 5.25ms of PLL_DC_OK being
                                                                 asserted. PLLs were released automatically. */
        uint64_t dis_huk               : 1;  /**< [ 56: 56](R/W1S) Disable HUK. Secure only and W1S set-only. When set FUSF_SSK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW() cannot be read.
                                                                 Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
        uint64_t dis_scan              : 1;  /**< [ 55: 55](R/W1S) Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.

                                                                 Internal:
                                                                 This state will persist across a simulation */
        uint64_t reserved_47_54        : 8;
        uint64_t c_mul                 : 7;  /**< [ 46: 40](RO/H) Core-clock multiplier. [C_MUL] = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [C_MUL] is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123]. If the fuse value is > 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_39           : 1;
        uint64_t pnr_mul               : 6;  /**< [ 38: 33](RO/H) Coprocessor-clock multiplier. [PNR_MUL] = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [PNR_MUL] is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119]. If the fuse value is > 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
        uint64_t lboot_oci             : 3;  /**< [ 32: 30](R/W1C/H) Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 <32> = Warm reset due to CCPI link 2 going down.
                                                                 <31> = Warm reset due to CCPI link 1 going down.
                                                                 <30> = Warm reset due to CCPI link 0 going down. */
        uint64_t reserved_26_29        : 4;
        uint64_t reserved_24_25        : 2;
        uint64_t lboot_ext45           : 6;  /**< [ 23: 18](R/W1C/H) Last boot cause mask for PEM5 and PEM4; resets only with PLL_DC_OK.
                                                                 <23> = Warm reset due to Cntl5 link-down or hot-reset.
                                                                 <22> = Warm reset due to Cntl4 link-down or hot-reset.
                                                                 <21> = Cntl5 reset due to PERST5_L pin.
                                                                 <20> = Cntl4 reset due to PERST4_L pin.
                                                                 <19> = Warm reset due to PERST5_L pin.
                                                                 <18> = Warm reset due to PERST4_L pin. */
        uint64_t lboot_ext23           : 6;  /**< [ 17: 12](R/W1C/H) Last boot cause mask for PEM3 and PEM2; resets only with PLL_DC_OK.
                                                                 <17> = Warm reset due to Cntl3 link-down or hot-reset.
                                                                 <16> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 <15> = Cntl3 reset due to PERST3_L pin.
                                                                 <14> = Cntl2 reset due to PERST2_L pin.
                                                                 <13> = Warm reset due to PERST3_L pin.
                                                                 <12> = Warm reset due to PERST2_L pin. */
        uint64_t lboot                 : 10; /**< [ 11:  2](R/W1C/H) Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 <11> = Soft reset due to watchdog.
                                                                 <10> = Soft reset due to RST_SOFT_RST write.
                                                                 <9> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 <8> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 <7> = Cntl1 reset due to PERST1_L pin.
                                                                 <6> = Cntl0 reset due to PERST0_L pin.
                                                                 <5> = Warm reset due to PERST1_L pin.
                                                                 <4> = Warm reset due to PERST0_L pin.
                                                                 <3> = Warm reset due to CHIP_RESET_L pin.
                                                                 <2> = Cold reset due to PLL_DC_OK pin. */
        uint64_t rboot                 : 1;  /**< [  1:  1](R/W) Remote boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset. The initial value mimics the setting of the [RBOOT_PIN]. */
        uint64_t rboot_pin             : 1;  /**< [  0:  0](RO/H) Remote Boot strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
#else /* Word 0 - Little Endian */
        uint64_t rboot_pin             : 1;  /**< [  0:  0](RO/H) Remote Boot strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
        uint64_t rboot                 : 1;  /**< [  1:  1](R/W) Remote boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset. The initial value mimics the setting of the [RBOOT_PIN]. */
        uint64_t lboot                 : 10; /**< [ 11:  2](R/W1C/H) Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 <11> = Soft reset due to watchdog.
                                                                 <10> = Soft reset due to RST_SOFT_RST write.
                                                                 <9> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 <8> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 <7> = Cntl1 reset due to PERST1_L pin.
                                                                 <6> = Cntl0 reset due to PERST0_L pin.
                                                                 <5> = Warm reset due to PERST1_L pin.
                                                                 <4> = Warm reset due to PERST0_L pin.
                                                                 <3> = Warm reset due to CHIP_RESET_L pin.
                                                                 <2> = Cold reset due to PLL_DC_OK pin. */
        uint64_t lboot_ext23           : 6;  /**< [ 17: 12](R/W1C/H) Last boot cause mask for PEM3 and PEM2; resets only with PLL_DC_OK.
                                                                 <17> = Warm reset due to Cntl3 link-down or hot-reset.
                                                                 <16> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 <15> = Cntl3 reset due to PERST3_L pin.
                                                                 <14> = Cntl2 reset due to PERST2_L pin.
                                                                 <13> = Warm reset due to PERST3_L pin.
                                                                 <12> = Warm reset due to PERST2_L pin. */
        uint64_t lboot_ext45           : 6;  /**< [ 23: 18](R/W1C/H) Last boot cause mask for PEM5 and PEM4; resets only with PLL_DC_OK.
                                                                 <23> = Warm reset due to Cntl5 link-down or hot-reset.
                                                                 <22> = Warm reset due to Cntl4 link-down or hot-reset.
                                                                 <21> = Cntl5 reset due to PERST5_L pin.
                                                                 <20> = Cntl4 reset due to PERST4_L pin.
                                                                 <19> = Warm reset due to PERST5_L pin.
                                                                 <18> = Warm reset due to PERST4_L pin. */
        uint64_t reserved_24_25        : 2;
        uint64_t reserved_26_29        : 4;
        uint64_t lboot_oci             : 3;  /**< [ 32: 30](R/W1C/H) Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 <32> = Warm reset due to CCPI link 2 going down.
                                                                 <31> = Warm reset due to CCPI link 1 going down.
                                                                 <30> = Warm reset due to CCPI link 0 going down. */
        uint64_t pnr_mul               : 6;  /**< [ 38: 33](RO/H) Coprocessor-clock multiplier. [PNR_MUL] = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [PNR_MUL] is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119]. If the fuse value is > 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_39           : 1;
        uint64_t c_mul                 : 7;  /**< [ 46: 40](RO/H) Core-clock multiplier. [C_MUL] = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.

                                                                 Internal:
                                                                 [C_MUL] is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123]. If the fuse value is > 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
        uint64_t reserved_47_54        : 8;
        uint64_t dis_scan              : 1;  /**< [ 55: 55](R/W1S) Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.

                                                                 Internal:
                                                                 This state will persist across a simulation */
        uint64_t dis_huk               : 1;  /**< [ 56: 56](R/W1S) Disable HUK. Secure only and W1S set-only. When set FUSF_SSK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW() cannot be read.
                                                                 Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
        uint64_t vrm_err               : 1;  /**< [ 57: 57](RO) VRM error. VRM did not complete operations within 5.25ms of PLL_DC_OK being
                                                                 asserted. PLLs were released automatically. */
        uint64_t jt_tstmode            : 1;  /**< [ 58: 58](RO) JTAG test mode. */
        uint64_t ckill_ppdis           : 1;  /**< [ 59: 59](R/W) Chipkill core disable. When set to 1, cores other than core 0 will immediately
                                                                 be disabled when RST_BOOT[CHIPKILL] is set. Writes have no effect when
                                                                 RST_BOOT[CHIPKILL]=1. */
        uint64_t trusted_mode          : 1;  /**< [ 60: 60](RO) When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP<10> are set. */
        uint64_t ejtagdis              : 1;  /**< [ 61: 61](R/W) Reserved. */
        uint64_t jtcsrdis              : 1;  /**< [ 62: 62](R/W) JTAG CSR disable. When set to 1, during the next warm or soft reset the JTAG TAP
                                                                 controller will be disabled, i.e. DAP_IMP_DAR will be 0. This field resets to 1
                                                                 in trusted-mode, else 0. */
        uint64_t chipkill              : 1;  /**< [ 63: 63](R/W1S) A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL=1 and the timer
                                                                 expires, chip reset is asserted internally. The CHIPKILL timer can be stopped only by
                                                                 a reset (cold, warm, soft). The length of the CHIPKILL timer is specified by
                                                                 RST_CKILL[TIMER]. This feature is effectively a delayed warm reset. */
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_rst_boot_s cn83xx; */
} bdk_rst_boot_t;

#define BDK_RST_BOOT BDK_RST_BOOT_FUNC()
static inline uint64_t BDK_RST_BOOT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_BOOT_FUNC(void)
{
    return 0x87e006001600ll;
}

#define typedef_BDK_RST_BOOT bdk_rst_boot_t
#define bustype_BDK_RST_BOOT BDK_CSR_TYPE_RSL
#define basename_BDK_RST_BOOT "RST_BOOT"
#define device_bar_BDK_RST_BOOT 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_BOOT 0
#define arguments_BDK_RST_BOOT -1,-1,-1,-1

/**
 * Register (RSL) rst_cfg
 *
 * RST Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bist_delay            : 58; /**< [ 63:  6](RO/H) Reserved. */
        uint64_t reserved_3_5          : 3;
        uint64_t cntl_clr_bist         : 1;  /**< [  2:  2](R/W) Perform clear BIST during control-only reset, instead of a full BIST. A warm/soft reset
                                                                 does not change this field. */
        uint64_t warm_clr_bist         : 1;  /**< [  1:  1](R/W) Perform clear BIST during warm reset, instead of a full BIST. A warm/soft reset does not
                                                                 change this field. Note that a cold reset always performs a full BIST. */
        uint64_t soft_clr_bist         : 1;  /**< [  0:  0](R/W) Perform clear BIST during soft reset, instead of a full BIST. A warm/soft reset does not
                                                                 change this field. Note that a cold reset always performs a full BIST. */
#else /* Word 0 - Little Endian */
        uint64_t soft_clr_bist         : 1;  /**< [  0:  0](R/W) Perform clear BIST during soft reset, instead of a full BIST. A warm/soft reset does not
                                                                 change this field. Note that a cold reset always performs a full BIST. */
        uint64_t warm_clr_bist         : 1;  /**< [  1:  1](R/W) Perform clear BIST during warm reset, instead of a full BIST. A warm/soft reset does not
                                                                 change this field. Note that a cold reset always performs a full BIST. */
        uint64_t cntl_clr_bist         : 1;  /**< [  2:  2](R/W) Perform clear BIST during control-only reset, instead of a full BIST. A warm/soft reset
                                                                 does not change this field. */
        uint64_t reserved_3_5          : 3;
        uint64_t bist_delay            : 58; /**< [ 63:  6](RO/H) Reserved. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_cfg_s cn; */
} bdk_rst_cfg_t;

#define BDK_RST_CFG BDK_RST_CFG_FUNC()
static inline uint64_t BDK_RST_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_CFG_FUNC(void)
{
    return 0x87e006001610ll;
}

#define typedef_BDK_RST_CFG bdk_rst_cfg_t
#define bustype_BDK_RST_CFG BDK_CSR_TYPE_RSL
#define basename_BDK_RST_CFG "RST_CFG"
#define device_bar_BDK_RST_CFG 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_CFG 0
#define arguments_BDK_RST_CFG -1,-1,-1,-1

/**
 * Register (RSL) rst_ckill
 *
 * RST Chipkill Timer Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_ckill_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_47_63        : 17;
        uint64_t timer                 : 47; /**< [ 46:  0](R/W/H) Chipkill timer measured in coprocessor-clock cycles. Read requests return
                                                                 current chipkill timer. Write operations have no effect when RST_BOOT[CHIPKILL]
                                                                 = 1. */
#else /* Word 0 - Little Endian */
        uint64_t timer                 : 47; /**< [ 46:  0](R/W/H) Chipkill timer measured in coprocessor-clock cycles. Read requests return
                                                                 current chipkill timer. Write operations have no effect when RST_BOOT[CHIPKILL]
                                                                 = 1. */
        uint64_t reserved_47_63        : 17;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_ckill_s cn; */
} bdk_rst_ckill_t;

#define BDK_RST_CKILL BDK_RST_CKILL_FUNC()
static inline uint64_t BDK_RST_CKILL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_CKILL_FUNC(void)
{
    return 0x87e006001638ll;
}

#define typedef_BDK_RST_CKILL bdk_rst_ckill_t
#define bustype_BDK_RST_CKILL BDK_CSR_TYPE_RSL
#define basename_BDK_RST_CKILL "RST_CKILL"
#define device_bar_BDK_RST_CKILL 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_CKILL 0
#define arguments_BDK_RST_CKILL -1,-1,-1,-1

/**
 * Register (RSL) rst_cold_data#
 *
 * RST Cold Reset Data Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_cold_datax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data registers preserved through warm reset. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 64; /**< [ 63:  0](R/W) Scratch data registers preserved through warm reset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_cold_datax_s cn; */
} bdk_rst_cold_datax_t;

static inline uint64_t BDK_RST_COLD_DATAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_COLD_DATAX(unsigned long a)
{
    if (a<=5)
        return 0x87e0060017c0ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("RST_COLD_DATAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_RST_COLD_DATAX(a) bdk_rst_cold_datax_t
#define bustype_BDK_RST_COLD_DATAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_RST_COLD_DATAX(a) "RST_COLD_DATAX"
#define device_bar_BDK_RST_COLD_DATAX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_COLD_DATAX(a) (a)
#define arguments_BDK_RST_COLD_DATAX(a) (a),-1,-1,-1

/**
 * Register (RSL) rst_ctl#
 *
 * RST Controllers Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_ctlx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t pf_flr_chip           : 1;  /**< [ 10: 10](R/W) Controls whether corresponding controller PF Function Level Reset causes a chip warm
                                                                 reset like CHIP_RESET_L. A warm/soft reset does not change this field.
                                                                 On cold reset, this field is initialized to 0. */
        uint64_t prst_link             : 1;  /**< [  9:  9](R/W) Controls whether corresponding controller link-down or hot-reset causes the assertion of
                                                                 RST_SOFT_PRST()[SOFT_PRST].
                                                                 A warm/soft reset does not change this field. On cold reset, this field is initialized to
                                                                 0. */
        uint64_t rst_done              : 1;  /**< [  8:  8](RO/H) Reset done. Indicates the controller reset status. [RST_DONE] is always 0
                                                                 (i.e. the controller is held in reset) when
                                                                 * RST_SOFT_PRST()[SOFT_PRST] = 1, or
                                                                 * [RST_RCV] = 1 and PERST*_L pin is asserted. */
        uint64_t rst_link              : 1;  /**< [  7:  7](R/W) Reset link. Controls whether corresponding controller link-down reset or hot reset causes
                                                                 a warm chip reset. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 Note that a link-down or hot-reset event can never cause a warm chip reset when the
                                                                 controller is in reset (i.e. can never cause a warm reset when [RST_DONE] = 0). */
        uint64_t host_mode             : 1;  /**< [  6:  6](RO) Read-only access to the corresponding PEM()_CFG[HOSTMD] field indicating PEMn is root
                                                                 complex (host). For controllers 0 and 2  the initial value is determined by straps. For
                                                                 controllers 1 and 3 this field is initially set as host. */
        uint64_t reserved_4_5          : 2;
        uint64_t rst_drv               : 1;  /**< [  3:  3](R/W) Controls whether PERST*_L is driven. A warm/soft reset does not change this field. On cold
                                                                 reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 0.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 1.

                                                                 When set, CNXXXX drives the corresponding PERST*_L pin. Otherwise, CNXXXX does not drive
                                                                 the corresponding PERST*_L pin. */
        uint64_t rst_rcv               : 1;  /**< [  2:  2](R/W) Reset received. Controls whether PERST*_L is received. A warm/soft reset does
                                                                 not change this field. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 When [RST_RCV] = 1, the PERST*_L value is received and can be used to reset the
                                                                 controller and (optionally, based on [RST_CHIP]) warm reset the chip.

                                                                 When [RST_RCV] = 1 (and [RST_CHIP] = 0), RST_INT[PERST*] gets set when the PERST*_L
                                                                 pin asserts. (This interrupt can alert software whenever the external reset pin initiates
                                                                 a controller reset sequence.)

                                                                 [RST_VAL] gives the PERST*_L pin value when [RST_RCV] = 1.

                                                                 When [RST_RCV] = 0, the PERST*_L pin value is ignored. */
        uint64_t rst_chip              : 1;  /**< [  1:  1](R/W) Controls whether PERST*_L causes a chip warm reset like CHIP_RESET_L. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0.

                                                                 When [RST_RCV] = 0, [RST_CHIP] is ignored.

                                                                 When [RST_RCV] = 1, [RST_CHIP] = 1, and PERST*_L asserts, a chip warm reset is generated. */
        uint64_t rst_val               : 1;  /**< [  0:  0](RO/H) Read-only access to PERST*_L. Unpredictable when [RST_RCV] = 0.

                                                                 Reads as 1 when [RST_RCV] = 1 and the PERST*_L pin is asserted.

                                                                 Reads as 0 when [RST_RCV] = 1 and the PERST*_L pin is not asserted. */
#else /* Word 0 - Little Endian */
        uint64_t rst_val               : 1;  /**< [  0:  0](RO/H) Read-only access to PERST*_L. Unpredictable when [RST_RCV] = 0.

                                                                 Reads as 1 when [RST_RCV] = 1 and the PERST*_L pin is asserted.

                                                                 Reads as 0 when [RST_RCV] = 1 and the PERST*_L pin is not asserted. */
        uint64_t rst_chip              : 1;  /**< [  1:  1](R/W) Controls whether PERST*_L causes a chip warm reset like CHIP_RESET_L. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0.

                                                                 When [RST_RCV] = 0, [RST_CHIP] is ignored.

                                                                 When [RST_RCV] = 1, [RST_CHIP] = 1, and PERST*_L asserts, a chip warm reset is generated. */
        uint64_t rst_rcv               : 1;  /**< [  2:  2](R/W) Reset received. Controls whether PERST*_L is received. A warm/soft reset does
                                                                 not change this field. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 When [RST_RCV] = 1, the PERST*_L value is received and can be used to reset the
                                                                 controller and (optionally, based on [RST_CHIP]) warm reset the chip.

                                                                 When [RST_RCV] = 1 (and [RST_CHIP] = 0), RST_INT[PERST*] gets set when the PERST*_L
                                                                 pin asserts. (This interrupt can alert software whenever the external reset pin initiates
                                                                 a controller reset sequence.)

                                                                 [RST_VAL] gives the PERST*_L pin value when [RST_RCV] = 1.

                                                                 When [RST_RCV] = 0, the PERST*_L pin value is ignored. */
        uint64_t rst_drv               : 1;  /**< [  3:  3](R/W) Controls whether PERST*_L is driven. A warm/soft reset does not change this field. On cold
                                                                 reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 0.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 1.

                                                                 When set, CNXXXX drives the corresponding PERST*_L pin. Otherwise, CNXXXX does not drive
                                                                 the corresponding PERST*_L pin. */
        uint64_t reserved_4_5          : 2;
        uint64_t host_mode             : 1;  /**< [  6:  6](RO) Read-only access to the corresponding PEM()_CFG[HOSTMD] field indicating PEMn is root
                                                                 complex (host). For controllers 0 and 2  the initial value is determined by straps. For
                                                                 controllers 1 and 3 this field is initially set as host. */
        uint64_t rst_link              : 1;  /**< [  7:  7](R/W) Reset link. Controls whether corresponding controller link-down reset or hot reset causes
                                                                 a warm chip reset. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 Note that a link-down or hot-reset event can never cause a warm chip reset when the
                                                                 controller is in reset (i.e. can never cause a warm reset when [RST_DONE] = 0). */
        uint64_t rst_done              : 1;  /**< [  8:  8](RO/H) Reset done. Indicates the controller reset status. [RST_DONE] is always 0
                                                                 (i.e. the controller is held in reset) when
                                                                 * RST_SOFT_PRST()[SOFT_PRST] = 1, or
                                                                 * [RST_RCV] = 1 and PERST*_L pin is asserted. */
        uint64_t prst_link             : 1;  /**< [  9:  9](R/W) Controls whether corresponding controller link-down or hot-reset causes the assertion of
                                                                 RST_SOFT_PRST()[SOFT_PRST].
                                                                 A warm/soft reset does not change this field. On cold reset, this field is initialized to
                                                                 0. */
        uint64_t pf_flr_chip           : 1;  /**< [ 10: 10](R/W) Controls whether corresponding controller PF Function Level Reset causes a chip warm
                                                                 reset like CHIP_RESET_L. A warm/soft reset does not change this field.
                                                                 On cold reset, this field is initialized to 0. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_ctlx_s cn9; */
    struct bdk_rst_ctlx_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t prst_link             : 1;  /**< [  9:  9](R/W) Controls whether corresponding controller link-down or hot-reset causes the assertion of
                                                                 RST_SOFT_PRST()[SOFT_PRST].
                                                                 A warm/soft reset does not change this field. On cold reset, this field is initialized to
                                                                 0. */
        uint64_t rst_done              : 1;  /**< [  8:  8](RO/H) Reset done. Indicates the controller reset status. [RST_DONE] is always 0
                                                                 (i.e. the controller is held in reset) when
                                                                 * RST_SOFT_PRST()[SOFT_PRST] = 1, or
                                                                 * [RST_RCV] = 1 and PERST*_L pin is asserted. */
        uint64_t rst_link              : 1;  /**< [  7:  7](R/W) Reset link. Controls whether corresponding controller link-down reset or hot reset causes
                                                                 a warm chip reset. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 Note that a link-down or hot-reset event can never cause a warm chip reset when the
                                                                 controller is in reset (i.e. can never cause a warm reset when [RST_DONE] = 0). */
        uint64_t host_mode             : 1;  /**< [  6:  6](RO) For all controllers this field is set as host. */
        uint64_t reserved_4_5          : 2;
        uint64_t rst_drv               : 1;  /**< [  3:  3](R/W) Controls whether PERST*_L is driven. A warm/soft reset does not change this field. On cold
                                                                 reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 0.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 1.

                                                                 When set, CNXXXX drives the corresponding PERST*_L pin. Otherwise, CNXXXX does not drive
                                                                 the corresponding PERST*_L pin. */
        uint64_t rst_rcv               : 1;  /**< [  2:  2](R/W) Reset received. Controls whether PERST*_L is received. A warm/soft reset does
                                                                 not change this field. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 When [RST_RCV] = 1, the PERST*_L value is received and can be used to reset the
                                                                 controller and (optionally, based on [RST_CHIP]) warm reset the chip.

                                                                 When [RST_RCV] = 1 (and [RST_CHIP] = 0), RST_INT[PERST*] gets set when the PERST*_L
                                                                 pin asserts. (This interrupt can alert software whenever the external reset pin initiates
                                                                 a controller reset sequence.)

                                                                 [RST_VAL] gives the PERST*_L pin value when [RST_RCV] = 1.

                                                                 When [RST_RCV] = 0, the PERST*_L pin value is ignored. */
        uint64_t rst_chip              : 1;  /**< [  1:  1](R/W) Controls whether PERST*_L causes a chip warm reset like CHIP_RESET_L. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0.

                                                                 When [RST_RCV] = 0, [RST_CHIP] is ignored.

                                                                 When [RST_RCV] = 1, [RST_CHIP] = 1, and PERST*_L asserts, a chip warm reset is generated. */
        uint64_t rst_val               : 1;  /**< [  0:  0](RO/H) Read-only access to PERST*_L. Unpredictable when [RST_RCV] = 0.

                                                                 Reads as 1 when [RST_RCV] = 1 and the PERST*_L pin is asserted.

                                                                 Reads as 0 when [RST_RCV] = 1 and the PERST*_L pin is not asserted. */
#else /* Word 0 - Little Endian */
        uint64_t rst_val               : 1;  /**< [  0:  0](RO/H) Read-only access to PERST*_L. Unpredictable when [RST_RCV] = 0.

                                                                 Reads as 1 when [RST_RCV] = 1 and the PERST*_L pin is asserted.

                                                                 Reads as 0 when [RST_RCV] = 1 and the PERST*_L pin is not asserted. */
        uint64_t rst_chip              : 1;  /**< [  1:  1](R/W) Controls whether PERST*_L causes a chip warm reset like CHIP_RESET_L. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0.

                                                                 When [RST_RCV] = 0, [RST_CHIP] is ignored.

                                                                 When [RST_RCV] = 1, [RST_CHIP] = 1, and PERST*_L asserts, a chip warm reset is generated. */
        uint64_t rst_rcv               : 1;  /**< [  2:  2](R/W) Reset received. Controls whether PERST*_L is received. A warm/soft reset does
                                                                 not change this field. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 When [RST_RCV] = 1, the PERST*_L value is received and can be used to reset the
                                                                 controller and (optionally, based on [RST_CHIP]) warm reset the chip.

                                                                 When [RST_RCV] = 1 (and [RST_CHIP] = 0), RST_INT[PERST*] gets set when the PERST*_L
                                                                 pin asserts. (This interrupt can alert software whenever the external reset pin initiates
                                                                 a controller reset sequence.)

                                                                 [RST_VAL] gives the PERST*_L pin value when [RST_RCV] = 1.

                                                                 When [RST_RCV] = 0, the PERST*_L pin value is ignored. */
        uint64_t rst_drv               : 1;  /**< [  3:  3](R/W) Controls whether PERST*_L is driven. A warm/soft reset does not change this field. On cold
                                                                 reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 0.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 1.

                                                                 When set, CNXXXX drives the corresponding PERST*_L pin. Otherwise, CNXXXX does not drive
                                                                 the corresponding PERST*_L pin. */
        uint64_t reserved_4_5          : 2;
        uint64_t host_mode             : 1;  /**< [  6:  6](RO) For all controllers this field is set as host. */
        uint64_t rst_link              : 1;  /**< [  7:  7](R/W) Reset link. Controls whether corresponding controller link-down reset or hot reset causes
                                                                 a warm chip reset. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 Note that a link-down or hot-reset event can never cause a warm chip reset when the
                                                                 controller is in reset (i.e. can never cause a warm reset when [RST_DONE] = 0). */
        uint64_t rst_done              : 1;  /**< [  8:  8](RO/H) Reset done. Indicates the controller reset status. [RST_DONE] is always 0
                                                                 (i.e. the controller is held in reset) when
                                                                 * RST_SOFT_PRST()[SOFT_PRST] = 1, or
                                                                 * [RST_RCV] = 1 and PERST*_L pin is asserted. */
        uint64_t prst_link             : 1;  /**< [  9:  9](R/W) Controls whether corresponding controller link-down or hot-reset causes the assertion of
                                                                 RST_SOFT_PRST()[SOFT_PRST].
                                                                 A warm/soft reset does not change this field. On cold reset, this field is initialized to
                                                                 0. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_ctlx_cn81xx cn88xx; */
    /* struct bdk_rst_ctlx_s cn83xx; */
} bdk_rst_ctlx_t;

static inline uint64_t BDK_RST_CTLX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_CTLX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e006001640ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e006001640ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e006001640ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e006001640ll + 8ll * ((a) & 0x3);
    __bdk_csr_fatal("RST_CTLX", 1, a, 0, 0, 0);
}

#define typedef_BDK_RST_CTLX(a) bdk_rst_ctlx_t
#define bustype_BDK_RST_CTLX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_RST_CTLX(a) "RST_CTLX"
#define device_bar_BDK_RST_CTLX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_CTLX(a) (a)
#define arguments_BDK_RST_CTLX(a) (a),-1,-1,-1

/**
 * Register (RSL) rst_dbg_reset
 *
 * INTERNAL: RST Debug Logic Reset Register
 *
 * This register contains the reset control for each core's debug logic.
 * Debug reset is not supported.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_dbg_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t rst                   : 48; /**< [ 47:  0](R/W) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t rst                   : 48; /**< [ 47:  0](R/W) Reserved. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_dbg_reset_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t rst                   : 48; /**< [ 47:  0](R/W) Debug logic reset for each core:
                                                                   0 = Debug logic operates normally.
                                                                   1 = Holds the debug logic in its reset state.

                                                                 The register is reset to 0 only during cold reset, the value is unaffected by
                                                                 warm and soft reset. */
#else /* Word 0 - Little Endian */
        uint64_t rst                   : 48; /**< [ 47:  0](R/W) Debug logic reset for each core:
                                                                   0 = Debug logic operates normally.
                                                                   1 = Holds the debug logic in its reset state.

                                                                 The register is reset to 0 only during cold reset, the value is unaffected by
                                                                 warm and soft reset. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_rst_dbg_reset_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t rst                   : 24; /**< [ 23:  0](R/W) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t rst                   : 24; /**< [ 23:  0](R/W) Reserved. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_dbg_reset_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t rst                   : 4;  /**< [  3:  0](R/W) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t rst                   : 4;  /**< [  3:  0](R/W) Reserved. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_dbg_reset_cn9 cn83xx; */
    /* struct bdk_rst_dbg_reset_s cn88xxp2; */
} bdk_rst_dbg_reset_t;

#define BDK_RST_DBG_RESET BDK_RST_DBG_RESET_FUNC()
static inline uint64_t BDK_RST_DBG_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_DBG_RESET_FUNC(void)
{
    return 0x87e006001750ll;
}

#define typedef_BDK_RST_DBG_RESET bdk_rst_dbg_reset_t
#define bustype_BDK_RST_DBG_RESET BDK_CSR_TYPE_RSL
#define basename_BDK_RST_DBG_RESET "RST_DBG_RESET"
#define device_bar_BDK_RST_DBG_RESET 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_DBG_RESET 0
#define arguments_BDK_RST_DBG_RESET -1,-1,-1,-1

/**
 * Register (RSL) rst_debug
 *
 * RST Debug Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_debug_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t clk_on                : 1;  /**< [  0:  0](R/W) Force conditional clock used for interrupt logic to always be on. For diagnostic use only. */
#else /* Word 0 - Little Endian */
        uint64_t clk_on                : 1;  /**< [  0:  0](R/W) Force conditional clock used for interrupt logic to always be on. For diagnostic use only. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_debug_s cn; */
} bdk_rst_debug_t;

#define BDK_RST_DEBUG BDK_RST_DEBUG_FUNC()
static inline uint64_t BDK_RST_DEBUG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_DEBUG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0060017b0ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0060017b0ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x87e0060017b0ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e0060017b0ll;
    __bdk_csr_fatal("RST_DEBUG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_RST_DEBUG bdk_rst_debug_t
#define bustype_BDK_RST_DEBUG BDK_CSR_TYPE_RSL
#define basename_BDK_RST_DEBUG "RST_DEBUG"
#define device_bar_BDK_RST_DEBUG 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_DEBUG 0
#define arguments_BDK_RST_DEBUG -1,-1,-1,-1

/**
 * Register (RSL) rst_delay
 *
 * RST Delay Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_delay_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t warm_rst_dly          : 16; /**< [ 31: 16](R/W) Warm reset delay. A warm reset immediately causes an early warm-reset notification, but
                                                                 the assertion of warm reset is delayed this many coprocessor-clock cycles. A warm/soft
                                                                 reset does not change this field.
                                                                 This must be at least 0x200 coprocessor-clock cycles. */
        uint64_t soft_rst_dly          : 16; /**< [ 15:  0](R/W) Soft reset delay. A soft reset immediately causes an early soft-reset notification, but
                                                                 the assertion of soft reset is delayed this many coprocessor-clock cycles. A warm/soft
                                                                 reset does not change this field.
                                                                 This must be at least 0x200 coprocessor-clock cycles. */
#else /* Word 0 - Little Endian */
        uint64_t soft_rst_dly          : 16; /**< [ 15:  0](R/W) Soft reset delay. A soft reset immediately causes an early soft-reset notification, but
                                                                 the assertion of soft reset is delayed this many coprocessor-clock cycles. A warm/soft
                                                                 reset does not change this field.
                                                                 This must be at least 0x200 coprocessor-clock cycles. */
        uint64_t warm_rst_dly          : 16; /**< [ 31: 16](R/W) Warm reset delay. A warm reset immediately causes an early warm-reset notification, but
                                                                 the assertion of warm reset is delayed this many coprocessor-clock cycles. A warm/soft
                                                                 reset does not change this field.
                                                                 This must be at least 0x200 coprocessor-clock cycles. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_delay_s cn; */
} bdk_rst_delay_t;

#define BDK_RST_DELAY BDK_RST_DELAY_FUNC()
static inline uint64_t BDK_RST_DELAY_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_DELAY_FUNC(void)
{
    return 0x87e006001608ll;
}

#define typedef_BDK_RST_DELAY bdk_rst_delay_t
#define bustype_BDK_RST_DELAY BDK_CSR_TYPE_RSL
#define basename_BDK_RST_DELAY "RST_DELAY"
#define device_bar_BDK_RST_DELAY 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_DELAY 0
#define arguments_BDK_RST_DELAY -1,-1,-1,-1

/**
 * Register (RSL) rst_eco
 *
 * INTERNAL: RST ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) ECO flops. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) ECO flops. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_eco_s cn; */
} bdk_rst_eco_t;

#define BDK_RST_ECO BDK_RST_ECO_FUNC()
static inline uint64_t BDK_RST_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0060017b8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0060017b8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x87e0060017b8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e0060017b8ll;
    __bdk_csr_fatal("RST_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_RST_ECO bdk_rst_eco_t
#define bustype_BDK_RST_ECO BDK_CSR_TYPE_RSL
#define basename_BDK_RST_ECO "RST_ECO"
#define device_bar_BDK_RST_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_ECO 0
#define arguments_BDK_RST_ECO -1,-1,-1,-1

/**
 * Register (RSL) rst_int
 *
 * RST Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1C/H) PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
        uint64_t reserved_6_7          : 2;
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1C/H) A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1C/H) A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
        uint64_t reserved_6_7          : 2;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1C/H) PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_int_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1C/H) PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
        uint64_t reserved_4_7          : 4;
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1C/H) A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1C/H) A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
        uint64_t reserved_4_7          : 4;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1C/H) PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_int_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1C/H) PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
        uint64_t reserved_3_7          : 5;
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1C/H) A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1C/H) A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
        uint64_t reserved_3_7          : 5;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1C/H) PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_int_s cn88xx; */
    /* struct bdk_rst_int_cn9 cn83xx; */
} bdk_rst_int_t;

#define BDK_RST_INT BDK_RST_INT_FUNC()
static inline uint64_t BDK_RST_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_FUNC(void)
{
    return 0x87e006001628ll;
}

#define typedef_BDK_RST_INT bdk_rst_int_t
#define bustype_BDK_RST_INT BDK_CSR_TYPE_RSL
#define basename_BDK_RST_INT "RST_INT"
#define device_bar_BDK_RST_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_INT 0
#define arguments_BDK_RST_INT -1,-1,-1,-1

/**
 * Register (RSL) rst_int_ena_w1c
 *
 * RST Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1C/H) Reads or clears enable for RST_INT[PERST]. */
        uint64_t reserved_6_7          : 2;
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1C/H) Reads or clears enable for RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1C/H) Reads or clears enable for RST_INT[RST_LINK]. */
        uint64_t reserved_6_7          : 2;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1C/H) Reads or clears enable for RST_INT[PERST]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_int_ena_w1c_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1C/H) Reads or clears enable for RST_INT[PERST]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1C/H) Reads or clears enable for RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1C/H) Reads or clears enable for RST_INT[RST_LINK]. */
        uint64_t reserved_4_7          : 4;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1C/H) Reads or clears enable for RST_INT[PERST]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_int_ena_w1c_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1C/H) Reads or clears enable for RST_INT[PERST]. */
        uint64_t reserved_3_7          : 5;
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1C/H) Reads or clears enable for RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1C/H) Reads or clears enable for RST_INT[RST_LINK]. */
        uint64_t reserved_3_7          : 5;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1C/H) Reads or clears enable for RST_INT[PERST]. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_int_ena_w1c_s cn88xx; */
    /* struct bdk_rst_int_ena_w1c_cn9 cn83xx; */
} bdk_rst_int_ena_w1c_t;

#define BDK_RST_INT_ENA_W1C BDK_RST_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_RST_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_ENA_W1C_FUNC(void)
{
    return 0x87e0060016a8ll;
}

#define typedef_BDK_RST_INT_ENA_W1C bdk_rst_int_ena_w1c_t
#define bustype_BDK_RST_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define basename_BDK_RST_INT_ENA_W1C "RST_INT_ENA_W1C"
#define device_bar_BDK_RST_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_INT_ENA_W1C 0
#define arguments_BDK_RST_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) rst_int_ena_w1s
 *
 * RST Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1S/H) Reads or sets enable for RST_INT[PERST]. */
        uint64_t reserved_6_7          : 2;
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1S/H) Reads or sets enable for RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1S/H) Reads or sets enable for RST_INT[RST_LINK]. */
        uint64_t reserved_6_7          : 2;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1S/H) Reads or sets enable for RST_INT[PERST]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_int_ena_w1s_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1S/H) Reads or sets enable for RST_INT[PERST]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1S/H) Reads or sets enable for RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1S/H) Reads or sets enable for RST_INT[RST_LINK]. */
        uint64_t reserved_4_7          : 4;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1S/H) Reads or sets enable for RST_INT[PERST]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_int_ena_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1S/H) Reads or sets enable for RST_INT[PERST]. */
        uint64_t reserved_3_7          : 5;
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1S/H) Reads or sets enable for RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1S/H) Reads or sets enable for RST_INT[RST_LINK]. */
        uint64_t reserved_3_7          : 5;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1S/H) Reads or sets enable for RST_INT[PERST]. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_int_ena_w1s_s cn88xx; */
    /* struct bdk_rst_int_ena_w1s_cn9 cn83xx; */
} bdk_rst_int_ena_w1s_t;

#define BDK_RST_INT_ENA_W1S BDK_RST_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_RST_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_ENA_W1S_FUNC(void)
{
    return 0x87e0060016a0ll;
}

#define typedef_BDK_RST_INT_ENA_W1S bdk_rst_int_ena_w1s_t
#define bustype_BDK_RST_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_RST_INT_ENA_W1S "RST_INT_ENA_W1S"
#define device_bar_BDK_RST_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_INT_ENA_W1S 0
#define arguments_BDK_RST_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) rst_int_w1s
 *
 * RST Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1S/H) Reads or sets RST_INT[PERST]. */
        uint64_t reserved_6_7          : 2;
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1S/H) Reads or sets RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 6;  /**< [  5:  0](R/W1S/H) Reads or sets RST_INT[RST_LINK]. */
        uint64_t reserved_6_7          : 2;
        uint64_t perst                 : 6;  /**< [ 13:  8](R/W1S/H) Reads or sets RST_INT[PERST]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_int_w1s_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1S/H) Reads or sets RST_INT[PERST]. */
        uint64_t reserved_4_7          : 4;
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1S/H) Reads or sets RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 4;  /**< [  3:  0](R/W1S/H) Reads or sets RST_INT[RST_LINK]. */
        uint64_t reserved_4_7          : 4;
        uint64_t perst                 : 4;  /**< [ 11:  8](R/W1S/H) Reads or sets RST_INT[PERST]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_int_w1s_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1S/H) Reads or sets RST_INT[PERST]. */
        uint64_t reserved_3_7          : 5;
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1S/H) Reads or sets RST_INT[RST_LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W1S/H) Reads or sets RST_INT[RST_LINK]. */
        uint64_t reserved_3_7          : 5;
        uint64_t perst                 : 3;  /**< [ 10:  8](R/W1S/H) Reads or sets RST_INT[PERST]. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_int_w1s_s cn88xx; */
    /* struct bdk_rst_int_w1s_cn9 cn83xx; */
} bdk_rst_int_w1s_t;

#define BDK_RST_INT_W1S BDK_RST_INT_W1S_FUNC()
static inline uint64_t BDK_RST_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_W1S_FUNC(void)
{
    return 0x87e006001630ll;
}

#define typedef_BDK_RST_INT_W1S bdk_rst_int_w1s_t
#define bustype_BDK_RST_INT_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_RST_INT_W1S "RST_INT_W1S"
#define device_bar_BDK_RST_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_INT_W1S 0
#define arguments_BDK_RST_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) rst_msix_pba#
 *
 * RST MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the RST_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated RST_MSIX_VEC()_CTL, enumerated by
                                                                 RST_INT_VEC_E. Bits that have no associated RST_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated RST_MSIX_VEC()_CTL, enumerated by
                                                                 RST_INT_VEC_E. Bits that have no associated RST_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_msix_pbax_s cn; */
} bdk_rst_msix_pbax_t;

static inline uint64_t BDK_RST_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_MSIX_PBAX(unsigned long a)
{
    if (a==0)
        return 0x87e006ff0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("RST_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_RST_MSIX_PBAX(a) bdk_rst_msix_pbax_t
#define bustype_BDK_RST_MSIX_PBAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_RST_MSIX_PBAX(a) "RST_MSIX_PBAX"
#define device_bar_BDK_RST_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_RST_MSIX_PBAX(a) (a)
#define arguments_BDK_RST_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) rst_msix_vec#_addr
 *
 * RST MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the RST_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector can be read or written by either secure or nonsecure states.
                                                                 1 = This vector's RST_MSIX_VEC()_ADDR, RST_MSIX_VEC()_CTL, and
                                                                 corresponding bit of RST_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_RST_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector can be read or written by either secure or nonsecure states.
                                                                 1 = This vector's RST_MSIX_VEC()_ADDR, RST_MSIX_VEC()_CTL, and
                                                                 corresponding bit of RST_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_RST_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_msix_vecx_addr_s cn; */
} bdk_rst_msix_vecx_addr_t;

static inline uint64_t BDK_RST_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_MSIX_VECX_ADDR(unsigned long a)
{
    if (a==0)
        return 0x87e006f00000ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("RST_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_RST_MSIX_VECX_ADDR(a) bdk_rst_msix_vecx_addr_t
#define bustype_BDK_RST_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_RST_MSIX_VECX_ADDR(a) "RST_MSIX_VECX_ADDR"
#define device_bar_BDK_RST_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_RST_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_RST_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) rst_msix_vec#_ctl
 *
 * RST MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the RST_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_msix_vecx_ctl_s
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
    /* struct bdk_rst_msix_vecx_ctl_s cn; */
} bdk_rst_msix_vecx_ctl_t;

static inline uint64_t BDK_RST_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_MSIX_VECX_CTL(unsigned long a)
{
    if (a==0)
        return 0x87e006f00008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("RST_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_RST_MSIX_VECX_CTL(a) bdk_rst_msix_vecx_ctl_t
#define bustype_BDK_RST_MSIX_VECX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_RST_MSIX_VECX_CTL(a) "RST_MSIX_VECX_CTL"
#define device_bar_BDK_RST_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_RST_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_RST_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) rst_ocx
 *
 * RST OCX Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_ocx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W) Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W) Reserved. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_ocx_s cn9; */
    /* struct bdk_rst_ocx_s cn81xx; */
    struct bdk_rst_ocx_cn88xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W) Controls whether corresponding OCX link going down causes a chip reset. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0. See
                                                                 OCX_COM_LINK()_CTL for a description of what events can contribute to the link_down
                                                                 condition. */
#else /* Word 0 - Little Endian */
        uint64_t rst_link              : 3;  /**< [  2:  0](R/W) Controls whether corresponding OCX link going down causes a chip reset. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0. See
                                                                 OCX_COM_LINK()_CTL for a description of what events can contribute to the link_down
                                                                 condition. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } cn88xx;
    /* struct bdk_rst_ocx_s cn83xx; */
} bdk_rst_ocx_t;

#define BDK_RST_OCX BDK_RST_OCX_FUNC()
static inline uint64_t BDK_RST_OCX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_OCX_FUNC(void)
{
    return 0x87e006001618ll;
}

#define typedef_BDK_RST_OCX bdk_rst_ocx_t
#define bustype_BDK_RST_OCX BDK_CSR_TYPE_RSL
#define basename_BDK_RST_OCX "RST_OCX"
#define device_bar_BDK_RST_OCX 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_OCX 0
#define arguments_BDK_RST_OCX -1,-1,-1,-1

/**
 * Register (RSL) rst_osc_cntr
 *
 * INTERNAL: RST Internal Ring-Oscillator Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_osc_cntr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](RO/H) Internal ring-oscillator clock count.  Updated every 16 reference clocks. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](RO/H) Internal ring-oscillator clock count.  Updated every 16 reference clocks. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_osc_cntr_s cn; */
} bdk_rst_osc_cntr_t;

#define BDK_RST_OSC_CNTR BDK_RST_OSC_CNTR_FUNC()
static inline uint64_t BDK_RST_OSC_CNTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_OSC_CNTR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e006001778ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e006001778ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x87e006001778ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e006001778ll;
    __bdk_csr_fatal("RST_OSC_CNTR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_RST_OSC_CNTR bdk_rst_osc_cntr_t
#define bustype_BDK_RST_OSC_CNTR BDK_CSR_TYPE_RSL
#define basename_BDK_RST_OSC_CNTR "RST_OSC_CNTR"
#define device_bar_BDK_RST_OSC_CNTR 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_OSC_CNTR 0
#define arguments_BDK_RST_OSC_CNTR -1,-1,-1,-1

/**
 * Register (RSL) rst_out_ctl
 *
 * RST External Reset Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_out_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_rst              : 1;  /**< [  0:  0](R/W) Soft reset. When set to 1 by software, this field drives the RST_OUT_N pin
                                                                 active low. In this case the field must also be cleared by software to deassert
                                                                 the pin. The pin is also automatically asserted and deasserted by hardware
                                                                 during a cold/warm/soft reset. */
#else /* Word 0 - Little Endian */
        uint64_t soft_rst              : 1;  /**< [  0:  0](R/W) Soft reset. When set to 1 by software, this field drives the RST_OUT_N pin
                                                                 active low. In this case the field must also be cleared by software to deassert
                                                                 the pin. The pin is also automatically asserted and deasserted by hardware
                                                                 during a cold/warm/soft reset. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_out_ctl_s cn; */
} bdk_rst_out_ctl_t;

#define BDK_RST_OUT_CTL BDK_RST_OUT_CTL_FUNC()
static inline uint64_t BDK_RST_OUT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_OUT_CTL_FUNC(void)
{
    return 0x87e006001688ll;
}

#define typedef_BDK_RST_OUT_CTL bdk_rst_out_ctl_t
#define bustype_BDK_RST_OUT_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_RST_OUT_CTL "RST_OUT_CTL"
#define device_bar_BDK_RST_OUT_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_OUT_CTL 0
#define arguments_BDK_RST_OUT_CTL -1,-1,-1,-1

/**
 * Register (RSL) rst_power_dbg
 *
 * RST Core-Power Debug-Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_power_dbg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t str                   : 3;  /**< [  2:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Internal power driver strength. Resets only on cold reset. */
#else /* Word 0 - Little Endian */
        uint64_t str                   : 3;  /**< [  2:  0](R/W) Reserved.
                                                                 Internal:
                                                                 Internal power driver strength. Resets only on cold reset. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_power_dbg_s cn; */
} bdk_rst_power_dbg_t;

#define BDK_RST_POWER_DBG BDK_RST_POWER_DBG_FUNC()
static inline uint64_t BDK_RST_POWER_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_POWER_DBG_FUNC(void)
{
    return 0x87e006001708ll;
}

#define typedef_BDK_RST_POWER_DBG bdk_rst_power_dbg_t
#define bustype_BDK_RST_POWER_DBG BDK_CSR_TYPE_RSL
#define basename_BDK_RST_POWER_DBG "RST_POWER_DBG"
#define device_bar_BDK_RST_POWER_DBG 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_POWER_DBG 0
#define arguments_BDK_RST_POWER_DBG -1,-1,-1,-1

/**
 * Register (RSL) rst_pp_available
 *
 * RST Core Availablity Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_pp_available_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t present               : 48; /**< [ 47:  0](RO) Each bit set indicates a physical core is present. */
#else /* Word 0 - Little Endian */
        uint64_t present               : 48; /**< [ 47:  0](RO) Each bit set indicates a physical core is present. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_pp_available_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t present               : 24; /**< [ 23:  0](RO) Each bit set indicates a physical core is present. */
#else /* Word 0 - Little Endian */
        uint64_t present               : 24; /**< [ 23:  0](RO) Each bit set indicates a physical core is present. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_pp_available_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t present               : 4;  /**< [  3:  0](RO) Each bit set indicates a physical core is present. */
#else /* Word 0 - Little Endian */
        uint64_t present               : 4;  /**< [  3:  0](RO) Each bit set indicates a physical core is present. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_pp_available_s cn88xx; */
    /* struct bdk_rst_pp_available_cn9 cn83xx; */
} bdk_rst_pp_available_t;

#define BDK_RST_PP_AVAILABLE BDK_RST_PP_AVAILABLE_FUNC()
static inline uint64_t BDK_RST_PP_AVAILABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_AVAILABLE_FUNC(void)
{
    return 0x87e006001738ll;
}

#define typedef_BDK_RST_PP_AVAILABLE bdk_rst_pp_available_t
#define bustype_BDK_RST_PP_AVAILABLE BDK_CSR_TYPE_RSL
#define basename_BDK_RST_PP_AVAILABLE "RST_PP_AVAILABLE"
#define device_bar_BDK_RST_PP_AVAILABLE 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_PP_AVAILABLE 0
#define arguments_BDK_RST_PP_AVAILABLE -1,-1,-1,-1

/**
 * Register (RSL) rst_pp_pending
 *
 * RST Cores Reset Pending Register
 * This register contains the reset status for each core.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_pp_pending_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pend                  : 48; /**< [ 47:  0](RO/H) Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 48; /**< [ 47:  0](RO/H) Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_pp_pending_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t pend                  : 24; /**< [ 23:  0](RO/H) Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 24; /**< [ 23:  0](RO/H) Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_pp_pending_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t pend                  : 4;  /**< [  3:  0](RO/H) Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 4;  /**< [  3:  0](RO/H) Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_pp_pending_s cn88xx; */
    /* struct bdk_rst_pp_pending_cn9 cn83xx; */
} bdk_rst_pp_pending_t;

#define BDK_RST_PP_PENDING BDK_RST_PP_PENDING_FUNC()
static inline uint64_t BDK_RST_PP_PENDING_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_PENDING_FUNC(void)
{
    return 0x87e006001748ll;
}

#define typedef_BDK_RST_PP_PENDING bdk_rst_pp_pending_t
#define bustype_BDK_RST_PP_PENDING BDK_CSR_TYPE_RSL
#define basename_BDK_RST_PP_PENDING "RST_PP_PENDING"
#define device_bar_BDK_RST_PP_PENDING 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_PP_PENDING 0
#define arguments_BDK_RST_PP_PENDING -1,-1,-1,-1

/**
 * Register (RSL) rst_pp_power
 *
 * RST Core-Power Gating-Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_pp_power_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t gate                  : 48; /**< [ 47:  0](R/W) Power down enable. When a bit in this field and the corresponding RST_PP_RESET bit are
                                                                 set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
#else /* Word 0 - Little Endian */
        uint64_t gate                  : 48; /**< [ 47:  0](R/W) Power down enable. When a bit in this field and the corresponding RST_PP_RESET bit are
                                                                 set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_pp_power_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t gate                  : 24; /**< [ 23:  0](R/W) Power down enable. When a bit in this field and the corresponding RST_PP_RESET bit are
                                                                 set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
#else /* Word 0 - Little Endian */
        uint64_t gate                  : 24; /**< [ 23:  0](R/W) Power down enable. When a bit in this field and the corresponding RST_PP_RESET bit are
                                                                 set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_pp_power_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t gate                  : 4;  /**< [  3:  0](R/W) Power down enable. When a bit in this field and the corresponding RST_PP_RESET bit are
                                                                 set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
#else /* Word 0 - Little Endian */
        uint64_t gate                  : 4;  /**< [  3:  0](R/W) Power down enable. When a bit in this field and the corresponding RST_PP_RESET bit are
                                                                 set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_pp_power_s cn88xx; */
    /* struct bdk_rst_pp_power_cn9 cn83xx; */
} bdk_rst_pp_power_t;

#define BDK_RST_PP_POWER BDK_RST_PP_POWER_FUNC()
static inline uint64_t BDK_RST_PP_POWER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_POWER_FUNC(void)
{
    return 0x87e006001700ll;
}

#define typedef_BDK_RST_PP_POWER bdk_rst_pp_power_t
#define bustype_BDK_RST_PP_POWER BDK_CSR_TYPE_RSL
#define basename_BDK_RST_PP_POWER "RST_PP_POWER"
#define device_bar_BDK_RST_PP_POWER 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_PP_POWER 0
#define arguments_BDK_RST_PP_POWER -1,-1,-1,-1

/**
 * Register (RSL) rst_pp_power_stat
 *
 * RST Core-Power Status Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_pp_power_stat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t down                  : 48; /**< [ 47:  0](RO/H) Reserved.
                                                                 Internal:
                                                                 Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
#else /* Word 0 - Little Endian */
        uint64_t down                  : 48; /**< [ 47:  0](RO/H) Reserved.
                                                                 Internal:
                                                                 Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_pp_power_stat_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t down                  : 24; /**< [ 23:  0](RO/H) Reserved.
                                                                 Internal:
                                                                 Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
#else /* Word 0 - Little Endian */
        uint64_t down                  : 24; /**< [ 23:  0](RO/H) Reserved.
                                                                 Internal:
                                                                 Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_pp_power_stat_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t down                  : 4;  /**< [  3:  0](RO/H) Reserved.
                                                                 Internal:
                                                                 Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
#else /* Word 0 - Little Endian */
        uint64_t down                  : 4;  /**< [  3:  0](RO/H) Reserved.
                                                                 Internal:
                                                                 Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_pp_power_stat_s cn88xx; */
    /* struct bdk_rst_pp_power_stat_cn9 cn83xx; */
} bdk_rst_pp_power_stat_t;

#define BDK_RST_PP_POWER_STAT BDK_RST_PP_POWER_STAT_FUNC()
static inline uint64_t BDK_RST_PP_POWER_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_POWER_STAT_FUNC(void)
{
    return 0x87e006001710ll;
}

#define typedef_BDK_RST_PP_POWER_STAT bdk_rst_pp_power_stat_t
#define bustype_BDK_RST_PP_POWER_STAT BDK_CSR_TYPE_RSL
#define basename_BDK_RST_PP_POWER_STAT "RST_PP_POWER_STAT"
#define device_bar_BDK_RST_PP_POWER_STAT 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_PP_POWER_STAT 0
#define arguments_BDK_RST_PP_POWER_STAT -1,-1,-1,-1

/**
 * Register (RSL) rst_pp_reset
 *
 * RST Core Reset Register
 * This register contains the reset control for each core: 1 = hold core in reset, 0 = release
 * core
 * from reset. It resets to all 1s when GPIO_STRAP<3:0> = RST_BOOT_METHOD_E::REMOTE
 * or all 1s excluding bit 0 otherwise.
 * Write operations to this register should occur only if RST_PP_PENDING is cleared.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_pp_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t rst                   : 47; /**< [ 47:  1](R/W/H) Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
        uint64_t rst0                  : 1;  /**< [  0:  0](R/W/H) Core reset for core 0, depends on if GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
#else /* Word 0 - Little Endian */
        uint64_t rst0                  : 1;  /**< [  0:  0](R/W/H) Core reset for core 0, depends on if GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
        uint64_t rst                   : 47; /**< [ 47:  1](R/W/H) Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_pp_reset_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t rst                   : 23; /**< [ 23:  1](R/W/H) Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
        uint64_t rst0                  : 1;  /**< [  0:  0](R/W/H) Core reset for core 0, depends on if GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
#else /* Word 0 - Little Endian */
        uint64_t rst0                  : 1;  /**< [  0:  0](R/W/H) Core reset for core 0, depends on if GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
        uint64_t rst                   : 23; /**< [ 23:  1](R/W/H) Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } cn9;
    struct bdk_rst_pp_reset_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t rst                   : 3;  /**< [  3:  1](R/W/H) Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
        uint64_t rst0                  : 1;  /**< [  0:  0](R/W/H) Core reset for core 0, depends on if GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
#else /* Word 0 - Little Endian */
        uint64_t rst0                  : 1;  /**< [  0:  0](R/W/H) Core reset for core 0, depends on if GPIO_STRAP<2:0> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
        uint64_t rst                   : 3;  /**< [  3:  1](R/W/H) Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_rst_pp_reset_s cn88xx; */
    /* struct bdk_rst_pp_reset_cn9 cn83xx; */
} bdk_rst_pp_reset_t;

#define BDK_RST_PP_RESET BDK_RST_PP_RESET_FUNC()
static inline uint64_t BDK_RST_PP_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_RESET_FUNC(void)
{
    return 0x87e006001740ll;
}

#define typedef_BDK_RST_PP_RESET bdk_rst_pp_reset_t
#define bustype_BDK_RST_PP_RESET BDK_CSR_TYPE_RSL
#define basename_BDK_RST_PP_RESET "RST_PP_RESET"
#define device_bar_BDK_RST_PP_RESET 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_PP_RESET 0
#define arguments_BDK_RST_PP_RESET -1,-1,-1,-1

/**
 * Register (RSL) rst_ref_check
 *
 * INTERNAL: RST Reference Clock Checker Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_ref_check_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t range                 : 1;  /**< [ 63: 63](RO/H) Reference ever out of range. Set when either:
                                                                 * Reference clock was outside operating range of 25 to 100 MHz.
                                                                 * Reference clock duty cycle outside 50% +/- 20%.
                                                                 * Reference increased or decreased in frequency. */
        uint64_t reserved_32_62        : 31;
        uint64_t cnt1                  : 16; /**< [ 31: 16](RO/H) Number of internal ring-oscillator clock pulses counted over 16 reference clocks
                                                                 while reference clock was high.
                                                                 When used with [CNT0] the internal ring-oscillator frequency can be determined. */
        uint64_t cnt0                  : 16; /**< [ 15:  0](RO/H) Number of internal ring-oscillator clock pulses counted over 16 reference clocks
                                                                 while reference clock was low.
                                                                 When used with [CNT1] the internal ring-oscillator frequency can be determined. */
#else /* Word 0 - Little Endian */
        uint64_t cnt0                  : 16; /**< [ 15:  0](RO/H) Number of internal ring-oscillator clock pulses counted over 16 reference clocks
                                                                 while reference clock was low.
                                                                 When used with [CNT1] the internal ring-oscillator frequency can be determined. */
        uint64_t cnt1                  : 16; /**< [ 31: 16](RO/H) Number of internal ring-oscillator clock pulses counted over 16 reference clocks
                                                                 while reference clock was high.
                                                                 When used with [CNT0] the internal ring-oscillator frequency can be determined. */
        uint64_t reserved_32_62        : 31;
        uint64_t range                 : 1;  /**< [ 63: 63](RO/H) Reference ever out of range. Set when either:
                                                                 * Reference clock was outside operating range of 25 to 100 MHz.
                                                                 * Reference clock duty cycle outside 50% +/- 20%.
                                                                 * Reference increased or decreased in frequency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_ref_check_s cn; */
} bdk_rst_ref_check_t;

#define BDK_RST_REF_CHECK BDK_RST_REF_CHECK_FUNC()
static inline uint64_t BDK_RST_REF_CHECK_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_REF_CHECK_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e006001770ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e006001770ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x87e006001770ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX))
        return 0x87e006001770ll;
    __bdk_csr_fatal("RST_REF_CHECK", 0, 0, 0, 0, 0);
}

#define typedef_BDK_RST_REF_CHECK bdk_rst_ref_check_t
#define bustype_BDK_RST_REF_CHECK BDK_CSR_TYPE_RSL
#define basename_BDK_RST_REF_CHECK "RST_REF_CHECK"
#define device_bar_BDK_RST_REF_CHECK 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_REF_CHECK 0
#define arguments_BDK_RST_REF_CHECK -1,-1,-1,-1

/**
 * Register (RSL) rst_ref_cntr
 *
 * RST Reference-Counter Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_ref_cntr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Count. The counter is initialized to 0x0 during a cold reset and is otherwise continuously
                                                                 running.
                                                                 CNT is incremented every reference-clock cycle (i.e. at 50 MHz). */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 64; /**< [ 63:  0](R/W/H) Count. The counter is initialized to 0x0 during a cold reset and is otherwise continuously
                                                                 running.
                                                                 CNT is incremented every reference-clock cycle (i.e. at 50 MHz). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_ref_cntr_s cn; */
} bdk_rst_ref_cntr_t;

#define BDK_RST_REF_CNTR BDK_RST_REF_CNTR_FUNC()
static inline uint64_t BDK_RST_REF_CNTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_REF_CNTR_FUNC(void)
{
    return 0x87e006001758ll;
}

#define typedef_BDK_RST_REF_CNTR bdk_rst_ref_cntr_t
#define bustype_BDK_RST_REF_CNTR BDK_CSR_TYPE_RSL
#define basename_BDK_RST_REF_CNTR "RST_REF_CNTR"
#define device_bar_BDK_RST_REF_CNTR 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_REF_CNTR 0
#define arguments_BDK_RST_REF_CNTR -1,-1,-1,-1

/**
 * Register (RSL) rst_soft_prst#
 *
 * RST PCIe Soft Reset Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_soft_prstx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_prst             : 1;  /**< [  0:  0](R/W) Soft PCIe reset. Resets the PCIe logic and corresponding common logic associated with the
                                                                 SLI controller in
                                                                 all modes, not just RC mode.
                                                                 * If RST_CTL()[HOST_MODE] = 0, [SOFT_PRST] resets to 0.
                                                                 * If RST_CTL()[HOST_MODE] = 1, [SOFT_PRST] resets to 1.

                                                                 When CNXXXX is configured to drive PERST*_L (i.e.
                                                                 RST_CTL()[RST_DRV] = 1), this controls the output value on PERST*_L.

                                                                 Internal:
                                                                 This bit is also forced high if the corresponding PEM Cripple Fuse is set. */
#else /* Word 0 - Little Endian */
        uint64_t soft_prst             : 1;  /**< [  0:  0](R/W) Soft PCIe reset. Resets the PCIe logic and corresponding common logic associated with the
                                                                 SLI controller in
                                                                 all modes, not just RC mode.
                                                                 * If RST_CTL()[HOST_MODE] = 0, [SOFT_PRST] resets to 0.
                                                                 * If RST_CTL()[HOST_MODE] = 1, [SOFT_PRST] resets to 1.

                                                                 When CNXXXX is configured to drive PERST*_L (i.e.
                                                                 RST_CTL()[RST_DRV] = 1), this controls the output value on PERST*_L.

                                                                 Internal:
                                                                 This bit is also forced high if the corresponding PEM Cripple Fuse is set. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_soft_prstx_s cn; */
} bdk_rst_soft_prstx_t;

static inline uint64_t BDK_RST_SOFT_PRSTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_SOFT_PRSTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=2))
        return 0x87e0060016c0ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=3))
        return 0x87e0060016c0ll + 8ll * ((a) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && (a<=5))
        return 0x87e0060016c0ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0060016c0ll + 8ll * ((a) & 0x3);
    __bdk_csr_fatal("RST_SOFT_PRSTX", 1, a, 0, 0, 0);
}

#define typedef_BDK_RST_SOFT_PRSTX(a) bdk_rst_soft_prstx_t
#define bustype_BDK_RST_SOFT_PRSTX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_RST_SOFT_PRSTX(a) "RST_SOFT_PRSTX"
#define device_bar_BDK_RST_SOFT_PRSTX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_SOFT_PRSTX(a) (a)
#define arguments_BDK_RST_SOFT_PRSTX(a) (a),-1,-1,-1

/**
 * Register (RSL) rst_soft_rst
 *
 * RST Soft Reset Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_soft_rst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t soft_rst              : 1;  /**< [  0:  0](WO) Soft reset. When set to 1, resets the CNXXXX core. When performing a soft reset from a
                                                                 remote PCIe host,
                                                                 always read this register and wait for the results before setting [SOFT_RST] to 1. */
#else /* Word 0 - Little Endian */
        uint64_t soft_rst              : 1;  /**< [  0:  0](WO) Soft reset. When set to 1, resets the CNXXXX core. When performing a soft reset from a
                                                                 remote PCIe host,
                                                                 always read this register and wait for the results before setting [SOFT_RST] to 1. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_soft_rst_s cn; */
} bdk_rst_soft_rst_t;

#define BDK_RST_SOFT_RST BDK_RST_SOFT_RST_FUNC()
static inline uint64_t BDK_RST_SOFT_RST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_SOFT_RST_FUNC(void)
{
    return 0x87e006001680ll;
}

#define typedef_BDK_RST_SOFT_RST bdk_rst_soft_rst_t
#define bustype_BDK_RST_SOFT_RST BDK_CSR_TYPE_RSL
#define basename_BDK_RST_SOFT_RST "RST_SOFT_RST"
#define device_bar_BDK_RST_SOFT_RST 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_SOFT_RST 0
#define arguments_BDK_RST_SOFT_RST -1,-1,-1,-1

/**
 * Register (RSL) rst_thermal_alert
 *
 * RST Thermal Alert Register
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_thermal_alert_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t trip                  : 1;  /**< [  8:  8](R/W1S/H) Thermal trip pin. When set to 1, drives the THERMAL_TRIP_N pin active low. This field is
                                                                 set by either of the
                                                                 on-board temperature sensors reaching a failure threshold or writing this bit.
                                                                 The bit can only be cleared by a deassertion of the PLL_DC_OK pin which completely resets
                                                                 the chip. */
        uint64_t reserved_2_7          : 6;
        uint64_t alert                 : 2;  /**< [  1:  0](RO/H) Thermal alert status. When set to 1, indicates the temperature sensor is currently at the
                                                                 failure threshold. */
#else /* Word 0 - Little Endian */
        uint64_t alert                 : 2;  /**< [  1:  0](RO/H) Thermal alert status. When set to 1, indicates the temperature sensor is currently at the
                                                                 failure threshold. */
        uint64_t reserved_2_7          : 6;
        uint64_t trip                  : 1;  /**< [  8:  8](R/W1S/H) Thermal trip pin. When set to 1, drives the THERMAL_TRIP_N pin active low. This field is
                                                                 set by either of the
                                                                 on-board temperature sensors reaching a failure threshold or writing this bit.
                                                                 The bit can only be cleared by a deassertion of the PLL_DC_OK pin which completely resets
                                                                 the chip. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    struct bdk_rst_thermal_alert_cn9
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t trip                  : 1;  /**< [  8:  8](R/W1S/H) Thermal trip pin. When set to 1, drives the THERMAL_TRIP_N pin active low. This field is
                                                                 set by either of the
                                                                 on-board temperature sensors reaching a failure threshold or writing this bit.
                                                                 The bit can only be cleared by a deassertion of the PLL_DC_OK pin which completely resets
                                                                 the chip. */
        uint64_t reserved_1_7          : 7;
        uint64_t alert                 : 1;  /**< [  0:  0](RO/H) Thermal alert status. When set to 1, indicates the temperature sensor is currently at the
                                                                 failure threshold. */
#else /* Word 0 - Little Endian */
        uint64_t alert                 : 1;  /**< [  0:  0](RO/H) Thermal alert status. When set to 1, indicates the temperature sensor is currently at the
                                                                 failure threshold. */
        uint64_t reserved_1_7          : 7;
        uint64_t trip                  : 1;  /**< [  8:  8](R/W1S/H) Thermal trip pin. When set to 1, drives the THERMAL_TRIP_N pin active low. This field is
                                                                 set by either of the
                                                                 on-board temperature sensors reaching a failure threshold or writing this bit.
                                                                 The bit can only be cleared by a deassertion of the PLL_DC_OK pin which completely resets
                                                                 the chip. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } cn9;
    /* struct bdk_rst_thermal_alert_cn9 cn81xx; */
    /* struct bdk_rst_thermal_alert_s cn88xx; */
    /* struct bdk_rst_thermal_alert_cn9 cn83xx; */
} bdk_rst_thermal_alert_t;

#define BDK_RST_THERMAL_ALERT BDK_RST_THERMAL_ALERT_FUNC()
static inline uint64_t BDK_RST_THERMAL_ALERT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_THERMAL_ALERT_FUNC(void)
{
    return 0x87e006001690ll;
}

#define typedef_BDK_RST_THERMAL_ALERT bdk_rst_thermal_alert_t
#define bustype_BDK_RST_THERMAL_ALERT BDK_CSR_TYPE_RSL
#define basename_BDK_RST_THERMAL_ALERT "RST_THERMAL_ALERT"
#define device_bar_BDK_RST_THERMAL_ALERT 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_THERMAL_ALERT 0
#define arguments_BDK_RST_THERMAL_ALERT -1,-1,-1,-1

/**
 * Register (RSL) rst_tns_pll_ctl
 *
 * RST Network-Switch PLL-Control Register
 * This register controls the network-switch clock frequency.
 * The following sequence is the TNS PLL-bringup sequence:
 *
 * 1. Write a 0 to [RESET_N] and a 1 to [DIV_RESET].
 *
 * 2. Set [CLKF] and [PS_EN]. If jtg_test_mode.
 * then also write jtg__tns_pll_tm_en2, jtg__tns_pll_tm_en4, jtg__tns_pll_tm_en12 and
 * jtg__tns_pll_tm_en24.
 *
 * 3. Wait 128 reference-clock cycles.
 *
 * 4. Write 1 to [RESET_N].
 *
 * 5. Wait 1152 reference-clock cycles.
 *
 * 6. Write 0 to [DIV_RESET].
 *
 * 7. Wait 10 reference-clock cycles before bringing up the network interface.
 *
 * If test mode is going to be activated, wait an additional 8191 reference-clock cycles to allow
 * PLL clock
 * alignment.
 */
typedef union
{
    uint64_t u;
    struct bdk_rst_tns_pll_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_29_63        : 35;
        uint64_t pll_fbslip            : 1;  /**< [ 28: 28](RO/H) PLL FBSLIP indication. */
        uint64_t pll_lock              : 1;  /**< [ 27: 27](RO/H) PLL LOCK indication. */
        uint64_t pll_rfslip            : 1;  /**< [ 26: 26](RO/H) PLL RFSLIP indication. */
        uint64_t reserved_23_25        : 3;
        uint64_t div_reset             : 1;  /**< [ 22: 22](R/W) Postscalar divider reset. */
        uint64_t ps_en                 : 4;  /**< [ 21: 18](R/W) PLL postscalar divide ratio. Determines the network clock speed.
                                                                 0x0 = divide TNS PLL by 1.
                                                                 0x1 = divide TNS PLL by 2.
                                                                 0x2 = divide TNS PLL by 3.
                                                                 0x3 = divide TNS PLL by 4.
                                                                 0x4 = divide TNS PLL by 5.
                                                                 0x5 = divide TNS PLL by 6.
                                                                 0x6 = divide TNS PLL by 7.
                                                                 0x7 = divide TNS PLL by 8.
                                                                 0x8 = divide TNS PLL by 10.
                                                                 0x9 = divide TNS PLL by 12.
                                                                 0xA-0xF = Reserved.

                                                                 [PS_EN] is not used when [DIV_RESET] = 1 */
        uint64_t reserved_15_17        : 3;
        uint64_t cout_rst              : 1;  /**< [ 14: 14](R/W) Clockout postscaler reset. This clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing [COUT_SEL]. The clockout
                                                                 postscaler should remain under reset for at least 10 reference-clock cycles
                                                                 after [COUT_SEL] changes. */
        uint64_t cout_sel              : 2;  /**< [ 13: 12](R/W) PNR clockout select:
                                                                 0x0 = Network clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = UNDIVIDED core clock. */
        uint64_t reserved_8_11         : 4;
        uint64_t reset_n               : 1;  /**< [  7:  7](R/W) PLL reset. */
        uint64_t clkf                  : 7;  /**< [  6:  0](R/W) PLL multiplier.  Sets TNS clock frequency to 50 MHz * ([CLKF]+1) / ([PS_EN]+1). */
#else /* Word 0 - Little Endian */
        uint64_t clkf                  : 7;  /**< [  6:  0](R/W) PLL multiplier.  Sets TNS clock frequency to 50 MHz * ([CLKF]+1) / ([PS_EN]+1). */
        uint64_t reset_n               : 1;  /**< [  7:  7](R/W) PLL reset. */
        uint64_t reserved_8_11         : 4;
        uint64_t cout_sel              : 2;  /**< [ 13: 12](R/W) PNR clockout select:
                                                                 0x0 = Network clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = UNDIVIDED core clock. */
        uint64_t cout_rst              : 1;  /**< [ 14: 14](R/W) Clockout postscaler reset. This clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing [COUT_SEL]. The clockout
                                                                 postscaler should remain under reset for at least 10 reference-clock cycles
                                                                 after [COUT_SEL] changes. */
        uint64_t reserved_15_17        : 3;
        uint64_t ps_en                 : 4;  /**< [ 21: 18](R/W) PLL postscalar divide ratio. Determines the network clock speed.
                                                                 0x0 = divide TNS PLL by 1.
                                                                 0x1 = divide TNS PLL by 2.
                                                                 0x2 = divide TNS PLL by 3.
                                                                 0x3 = divide TNS PLL by 4.
                                                                 0x4 = divide TNS PLL by 5.
                                                                 0x5 = divide TNS PLL by 6.
                                                                 0x6 = divide TNS PLL by 7.
                                                                 0x7 = divide TNS PLL by 8.
                                                                 0x8 = divide TNS PLL by 10.
                                                                 0x9 = divide TNS PLL by 12.
                                                                 0xA-0xF = Reserved.

                                                                 [PS_EN] is not used when [DIV_RESET] = 1 */
        uint64_t div_reset             : 1;  /**< [ 22: 22](R/W) Postscalar divider reset. */
        uint64_t reserved_23_25        : 3;
        uint64_t pll_rfslip            : 1;  /**< [ 26: 26](RO/H) PLL RFSLIP indication. */
        uint64_t pll_lock              : 1;  /**< [ 27: 27](RO/H) PLL LOCK indication. */
        uint64_t pll_fbslip            : 1;  /**< [ 28: 28](RO/H) PLL FBSLIP indication. */
        uint64_t reserved_29_63        : 35;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_rst_tns_pll_ctl_s cn; */
} bdk_rst_tns_pll_ctl_t;

#define BDK_RST_TNS_PLL_CTL BDK_RST_TNS_PLL_CTL_FUNC()
static inline uint64_t BDK_RST_TNS_PLL_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_TNS_PLL_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x87e006001780ll;
    __bdk_csr_fatal("RST_TNS_PLL_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_RST_TNS_PLL_CTL bdk_rst_tns_pll_ctl_t
#define bustype_BDK_RST_TNS_PLL_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_RST_TNS_PLL_CTL "RST_TNS_PLL_CTL"
#define device_bar_BDK_RST_TNS_PLL_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_RST_TNS_PLL_CTL 0
#define arguments_BDK_RST_TNS_PLL_CTL -1,-1,-1,-1

#endif /* __BDK_CSRS_RST_H__ */
