#ifndef __BDK_CSRS_RST__
#define __BDK_CSRS_RST__
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
 * Cavium RST.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration RST_BOOT_FAIL_E
 *
 * RST Boot Failure Code Enumeration
 * Enumerates the reasons for boot failure, returned to post-boot code
 * in argument register 0 and blinked on GPIO\<11\>.
 */
enum rst_boot_fail_e {
	RST_BOOT_FAIL_E_AUTH = 0x6,
	RST_BOOT_FAIL_E_DEVICE = 0x3,
	RST_BOOT_FAIL_E_GOOD = 0x0,
	RST_BOOT_FAIL_E_MAGIC = 0x4,
	RST_BOOT_FAIL_E_MCORE = 0x5,
	RST_BOOT_FAIL_E_METH = 0x2,
	RST_BOOT_FAIL_E_ENUM_LAST = 0x7,
};

/**
 * Enumeration RST_BOOT_METHOD_E
 *
 * RST Boot-strap Method Enumeration
 * Enumerates GPIO_STRAP\<3:0\>, which determines the method used to boot the cores.
 */
enum rst_boot_method_e {
	RST_BOOT_METHOD_E_CCPI0 = 0x9,
	RST_BOOT_METHOD_E_CCPI1 = 0xa,
	RST_BOOT_METHOD_E_CCPI2 = 0xb,
	RST_BOOT_METHOD_E_EMMC_LS = 0x3,
	RST_BOOT_METHOD_E_EMMC_SS = 0x2,
	RST_BOOT_METHOD_E_PCIE0 = 0xc,
	RST_BOOT_METHOD_E_REMOTE = 0x8,
	RST_BOOT_METHOD_E_SPI16 = 0x4,
	RST_BOOT_METHOD_E_SPI24 = 0x5,
	RST_BOOT_METHOD_E_SPI32 = 0x6,
	RST_BOOT_METHOD_E_ENUM_LAST = 0xd,
};

/**
 * Enumeration RST_INT_VEC_E
 *
 * RST MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum rst_int_vec_e {
	RST_INT_VEC_E_INTS = 0x0,
	RST_INT_VEC_E_ENUM_LAST = 0x1,
};


/**
 * Structure RST_PP_PWR_S
 *
 * INTERNAL: Core Reset Power Delivery Structure
 *
 * This structure specifies the layout of RTL reset and power delivery. It is not visible to software.
 */
union rst_pp_pwr_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54; /**< [ 63: 10] Reserved */
		uint64_t valid                       : 1;  /**< [  9:  9] Data transmitted on interface is valid */
		uint64_t ppvid                       : 6;  /**< [  8:  3] Virtual core number. */
		uint64_t dbg_rst                     : 1;  /**< [  2:  2] Reset control for the core specified by PPVID. */
		uint64_t pwrdwn                      : 1;  /**< [  1:  1] Core does not require power. */
		uint64_t rst                         : 1;  /**< [  0:  0] Reset control for the core specified by PPVID. */
#else
		uint64_t rst                         : 1;
		uint64_t pwrdwn                      : 1;
		uint64_t dbg_rst                     : 1;
		uint64_t ppvid                       : 6;
		uint64_t valid                       : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
};


/**
 * RSL - rst_bist_timer
 */
typedef union bdk_rst_bist_timer {
	uint64_t u;
	struct bdk_rst_bist_timer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_29_63              : 35;
		uint64_t count                       : 29; /**< RO - Number of 50 Mhz reference clocks that have elapsed during BIST and repair during the last
                                                                 reset.
                                                                 If MSB is set the BIST chain did not complete as expected. */
#else
		uint64_t count                       : 29;
		uint64_t reserved_29_63              : 35;
#endif
	} s;
	/* struct bdk_rst_bist_timer_s        cn85xx; */
	/* struct bdk_rst_bist_timer_s        cn88xx; */
	/* struct bdk_rst_bist_timer_s        cn88xxp1; */
} bdk_rst_bist_timer_t;

#define BDK_RST_BIST_TIMER BDK_RST_BIST_TIMER_FUNC()
static inline uint64_t BDK_RST_BIST_TIMER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_BIST_TIMER_FUNC(void)
{
	return 0x000087E006001760ull;
}
#define typedef_BDK_RST_BIST_TIMER bdk_rst_bist_timer_t
#define bustype_BDK_RST_BIST_TIMER BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_BIST_TIMER 0
#define arguments_BDK_RST_BIST_TIMER -1,-1,-1,-1
#define basename_BDK_RST_BIST_TIMER "RST_BIST_TIMER"


/**
 * RSL - rst_boot
 */
typedef union bdk_rst_boot {
	uint64_t u;
	struct bdk_rst_boot_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t chipkill                    : 1;  /**< R/W1S - A 0-to-1 transition of CHIPKILL starts the CHIPKILL timer. When CHIPKILL = 1 and the timer
                                                                 expires, internal chip reset is asserted forever until the next chip reset. The CHIPKILL
                                                                 timer can be stopped only by a chip (cold, warm, soft) reset. The length of the CHIPKILL
                                                                 timer is specified by RST_CKILL[TIMER]. */
		uint64_t jtcsrdis                    : 1;  /**< R/W - JTAG CSR disable. When set to 1, internal CSR access via the JTAG TAP controller
                                                                 is disabled This field resets to 1 in trusted-mode, else 0. */
		uint64_t ejtagdis                    : 1;  /**< R/W - EJTAG CSR disable. When set, external EJTAG access is disabled. This field resets to 1 in
                                                                 trusted-mode, else 0. */
		uint64_t trusted_mode                : 1;  /**< RO - When set, chip is operating as a trusted device. This bit is asserted when
                                                                 either MIO_FUS_DAT2[TRUSTZONE_EN], FUSF_CTL[TZ_FORCE2], or the trusted-mode
                                                                 strap GPIO_STRAP\<10\> are set. */
		uint64_t ckill_ppdis                 : 1;  /**< R/W - Chipkill core disable. When set to 1, cores other than 0 are disabled during a CHIPKILL.
                                                                 Write operations have no effect when RST_BOOT[CHIPKILL] = 1. */
		uint64_t jt_tstmode                  : 1;  /**< RO - JTAG test mode. */
		uint64_t vrm_err                     : 1;  /**< RO - VRM error. VRM did not complete operations within 5.25mS of PLL_DC_OK being
                                                                 asserted. PLLs were released automatically. */
		uint64_t dis_huk                     : 1;  /**< R/W1S - Disable HUK. Secure only and W1S set-only. When set to 1, FUSF_SSK(), FUSF_ROTPK(),
                                                                 FUSF_HUK(), FUSF_EK(), and FUSF_SW()
                                                                 cannot be read. Resets to (!trusted_mode && FUSF_CTL[FJ_DIS_HUK]). */
		uint64_t dis_scan                    : 1;  /**< R/W1S - Disable scan. When written to 1, and FUSF_CTL[ROT_LCK] = 1, reads as 1 and scan is not
                                                                 allowed in the part.
                                                                 This state persists across soft and warm resets.
                                                                 INTERNAL:  This state will presist across a simulations */
		uint64_t reserved_47_54              : 8;
		uint64_t c_mul                       : 7;  /**< RO/H - Core-clock multiplier. C_MUL = (core-clock speed) / (ref-clock speed). The value
                                                                 ref-clock speed should always be 50 MHz.
                                                                 INTERNAL:  C_MUL is set from the pi_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[127:123].  If the fuse value is \> 0, it is compared with the pi_pll_mul[5:1]
                                                                 pins and the smaller value is used. */
		uint64_t reserved_39_39              : 1;
		uint64_t pnr_mul                     : 6;  /**< RO/H - Coprocessor-clock multiplier. PNR_MUL = (coprocessor-clock speed) /(ref-clock speed).
                                                                 The value ref-clock speed should always be 50 MHz.
                                                                 INTERNAL:  PNR_MUL is set from the pi_pnr_pll_mul pins plus 6 and is limited by a set of
                                                                 fuses[122:119].  If the fuse value is \> 0, it is compared with the pi_pnr_pll_mul[4:1]
                                                                 pins and the smaller value is used. */
		uint64_t lboot_oci                   : 3;  /**< R/W1C - Last boot cause mask for CCPI; resets only with PLL_DC_OK.
                                                                 \<32\> = Warm reset due to CCPI link 2 going down.
                                                                 \<31\> = Warm reset due to CCPI link 1 going down.
                                                                 \<30\> = Warm reset due to CCPI link 0 going down. */
		uint64_t reserved_24_29              : 6;
		uint64_t lboot_ext45                 : 6;  /**< R/W1C - Last boot cause mask for PEM5 and PEM4; resets only with PLL_DC_OK.
                                                                 \<23\> = Warm reset due to Cntl5 link-down or hot-reset.
                                                                 \<22\> = Warm reset due to Cntl4 link-down or hot-reset.
                                                                 \<21\> = Cntl5 reset due to PERST5_L pin.
                                                                 \<20\> = Cntl4 reset due to PERST4_L pin.
                                                                 \<19\> = Warm reset due to PERST5_L pin.
                                                                 \<18\> = Warm reset due to PERST4_L pin. */
		uint64_t lboot_ext23                 : 6;  /**< R/W1C - Last boot cause mask for PEM3 and PEM2; resets only with PLL_DC_OK.
                                                                 \<17\> = Warm reset due to Cntl3 link-down or hot-reset.
                                                                 \<16\> = Warm reset due to Cntl2 link-down or hot-reset.
                                                                 \<15\> = Cntl3 reset due to PERST3_L pin.
                                                                 \<14\> = Cntl2 reset due to PERST2_L pin.
                                                                 \<13\> = Warm reset due to PERST3_L pin.
                                                                 \<12\> = Warm reset due to PERST2_L pin. */
		uint64_t lboot                       : 10; /**< R/W1C/H - Last boot cause mask for PEM1 and PEM0; resets only with PLL_DC_OK.
                                                                 \<11\> = Soft reset due to watchdog.
                                                                 \<10\> = Soft reset due to RST_SOFT_RST write.
                                                                 \<9\> = Warm reset due to Cntl1 link-down or hot-reset.
                                                                 \<8\> = Warm reset due to Cntl0 link-down or hot-reset.
                                                                 \<7\> = Cntl1 reset due to PERST1_L pin.
                                                                 \<6\> = Cntl0 reset due to PERST0_L pin.
                                                                 \<5\> = Warm reset due to PERST1_L pin.
                                                                 \<4\> = Warm reset due to PERST0_L pin.
                                                                 \<3\> = Warm reset due to CHIP_RESET_L pin.
                                                                 \<2\> = Cold reset due to PLL_DC_OK pin. */
		uint64_t rboot                       : 1;  /**< R/W - Remote Boot. If set, indicates that core 0 will remain in reset after a
                                                                 chip warm/soft reset.  The initial value mimics the setting of the RBOOT_PIN. */
		uint64_t rboot_pin                   : 1;  /**< RO/H - Remote Boot Strap. Indicates the state of remote boot as initially determined by
                                                                 GPIO_STRAP\<2:0\> = RST_BOOT_METHOD_E::REMOTE. If set core 0 will remain in reset
                                                                 for the cold reset. */
#else
		uint64_t rboot_pin                   : 1;
		uint64_t rboot                       : 1;
		uint64_t lboot                       : 10;
		uint64_t lboot_ext23                 : 6;
		uint64_t lboot_ext45                 : 6;
		uint64_t reserved_24_29              : 6;
		uint64_t lboot_oci                   : 3;
		uint64_t pnr_mul                     : 6;
		uint64_t reserved_39_39              : 1;
		uint64_t c_mul                       : 7;
		uint64_t reserved_47_54              : 8;
		uint64_t dis_scan                    : 1;
		uint64_t dis_huk                     : 1;
		uint64_t vrm_err                     : 1;
		uint64_t jt_tstmode                  : 1;
		uint64_t ckill_ppdis                 : 1;
		uint64_t trusted_mode                : 1;
		uint64_t ejtagdis                    : 1;
		uint64_t jtcsrdis                    : 1;
		uint64_t chipkill                    : 1;
#endif
	} s;
	/* struct bdk_rst_boot_s              cn85xx; */
	/* struct bdk_rst_boot_s              cn88xx; */
	/* struct bdk_rst_boot_s              cn88xxp1; */
} bdk_rst_boot_t;

#define BDK_RST_BOOT BDK_RST_BOOT_FUNC()
static inline uint64_t BDK_RST_BOOT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_BOOT_FUNC(void)
{
	return 0x000087E006001600ull;
}
#define typedef_BDK_RST_BOOT bdk_rst_boot_t
#define bustype_BDK_RST_BOOT BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_BOOT 0
#define arguments_BDK_RST_BOOT -1,-1,-1,-1
#define basename_BDK_RST_BOOT "RST_BOOT"


/**
 * RSL - rst_cfg
 */
typedef union bdk_rst_cfg {
	uint64_t u;
	struct bdk_rst_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bist_delay                  : 58; /**< RO/H - Reserved. */
		uint64_t reserved_3_5                : 3;
		uint64_t cntl_clr_bist               : 1;  /**< R/W - Perform clear BIST during control-only reset, instead of a full BIST. A warm/soft reset
                                                                 does not change this field. */
		uint64_t warm_clr_bist               : 1;  /**< R/W - Perform clear BIST during warm reset, instead of a full BIST. A warm/soft reset does not
                                                                 change this field. Note that a cold reset always performs a full BIST. */
		uint64_t soft_clr_bist               : 1;  /**< R/W - Perform clear BIST during soft reset, instead of a full BIST. A warm/soft reset does not
                                                                 change this field. Note that a cold reset always performs a full BIST. */
#else
		uint64_t soft_clr_bist               : 1;
		uint64_t warm_clr_bist               : 1;
		uint64_t cntl_clr_bist               : 1;
		uint64_t reserved_3_5                : 3;
		uint64_t bist_delay                  : 58;
#endif
	} s;
	/* struct bdk_rst_cfg_s               cn85xx; */
	/* struct bdk_rst_cfg_s               cn88xx; */
	/* struct bdk_rst_cfg_s               cn88xxp1; */
} bdk_rst_cfg_t;

#define BDK_RST_CFG BDK_RST_CFG_FUNC()
static inline uint64_t BDK_RST_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_CFG_FUNC(void)
{
	return 0x000087E006001610ull;
}
#define typedef_BDK_RST_CFG bdk_rst_cfg_t
#define bustype_BDK_RST_CFG BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_CFG 0
#define arguments_BDK_RST_CFG -1,-1,-1,-1
#define basename_BDK_RST_CFG "RST_CFG"


/**
 * RSL - rst_ckill
 */
typedef union bdk_rst_ckill {
	uint64_t u;
	struct bdk_rst_ckill_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_47_63              : 17;
		uint64_t timer                       : 47; /**< R/W - Chipkill timer measured in coprocessor-clock cycles. Read requests return
                                                                 current chipkill timer. Write operations have no effect when RST_BOOT[CHIPKILL]
                                                                 = 1. */
#else
		uint64_t timer                       : 47;
		uint64_t reserved_47_63              : 17;
#endif
	} s;
	/* struct bdk_rst_ckill_s             cn85xx; */
	/* struct bdk_rst_ckill_s             cn88xx; */
	/* struct bdk_rst_ckill_s             cn88xxp1; */
} bdk_rst_ckill_t;

#define BDK_RST_CKILL BDK_RST_CKILL_FUNC()
static inline uint64_t BDK_RST_CKILL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_CKILL_FUNC(void)
{
	return 0x000087E006001638ull;
}
#define typedef_BDK_RST_CKILL bdk_rst_ckill_t
#define bustype_BDK_RST_CKILL BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_CKILL 0
#define arguments_BDK_RST_CKILL -1,-1,-1,-1
#define basename_BDK_RST_CKILL "RST_CKILL"


/**
 * RSL - rst_cold_data#
 */
typedef union bdk_rst_cold_datax {
	uint64_t u;
	struct bdk_rst_cold_datax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Scratch data registers preserved through warm reset. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_rst_cold_datax_s        cn85xx; */
	/* struct bdk_rst_cold_datax_s        cn88xx; */
	/* struct bdk_rst_cold_datax_s        cn88xxp1; */
} bdk_rst_cold_datax_t;

static inline uint64_t BDK_RST_COLD_DATAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_COLD_DATAX(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0060017C0ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_RST_COLD_DATAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RST_COLD_DATAX(...) bdk_rst_cold_datax_t
#define bustype_BDK_RST_COLD_DATAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_COLD_DATAX(p1) (p1)
#define arguments_BDK_RST_COLD_DATAX(p1) (p1),-1,-1,-1
#define basename_BDK_RST_COLD_DATAX(...) "RST_COLD_DATAX"


/**
 * RSL - rst_ctl#
 */
typedef union bdk_rst_ctlx {
	uint64_t u;
	struct bdk_rst_ctlx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t prst_link                   : 1;  /**< R/W - Controls whether corresponding controller link-down or hot-reset causes the assertion of
                                                                 RST_SOFT_PRST()[SOFT_PRST].
                                                                 A warm/soft reset does not change this field. On cold reset, this field is initialized to
                                                                 0. */
		uint64_t rst_done                    : 1;  /**< RO/H - Reset done. Indicates the controller reset status. RST_DONE is always 0
                                                                 (i.e. the controller is held in reset) when
                                                                 * RST_SOFT_PRST()[SOFT_PRST] = 1, or
                                                                 * RST_RCV = 1 and PERST*_L pin is asserted. */
		uint64_t rst_link                    : 1;  /**< R/W - Reset link. Controls whether corresponding controller link-down reset or hot reset causes
                                                                 a warm chip reset. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 Note that a link-down or hot-reset event can never cause a warm chip reset when the
                                                                 controller is in reset (i.e. can never cause a warm reset when [RST_DONE] = 0). */
		uint64_t host_mode                   : 1;  /**< RO - For all controllers this field is set as host. */
		uint64_t reserved_4_5                : 2;
		uint64_t rst_drv                     : 1;  /**< R/W - Controls whether PERST*_L is driven. A warm/soft reset does not change this field. On cold
                                                                 reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 0.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 1.

                                                                 When set, CNXXXX drives the corresponding PERST*_L pin. Otherwise, CNXXXX does not drive
                                                                 the corresponding PERST*_L pin. */
		uint64_t rst_rcv                     : 1;  /**< R/W - Reset received. Controls whether PERST*_L is received. A warm/soft reset does
                                                                 not change this field. On cold reset, this field is initialized as follows:

                                                                 _ 0 when RST_CTL()[HOST_MODE] = 1.

                                                                 _ 1 when RST_CTL()[HOST_MODE] = 0.

                                                                 When RST_RCV = 1, the PERST*_L value is received and can be used to reset the
                                                                 controller and (optionally, based on RST_CHIP) warm reset the chip.

                                                                 When RST_RCV = 1 (and RST_CHIP = 0), RST_INT[PERST*] gets set when the PERST*_L
                                                                 pin asserts. (This interrupt can alert software whenever the external reset pin initiates
                                                                 a controller reset sequence.)

                                                                 RST_VAL gives the PERST*_L pin value when RST_RCV = 1.

                                                                 When RST_RCV = 0, the PERST*_L pin value is ignored. */
		uint64_t rst_chip                    : 1;  /**< R/W - Controls whether PERST*_L causes a chip warm reset like CHIP_RESET_L. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0.

                                                                 When RST_RCV = 0, RST_CHIP is ignored.

                                                                 When RST_RCV = 1, RST_CHIP = 1, and PERST*_L asserts, a chip warm reset is generated. */
		uint64_t rst_val                     : 1;  /**< RO/H - Read-only access to PERST*_L. Unpredictable when RST_RCV = 0.

                                                                 Reads as 1 when RST_RCV = 1 and the PERST*_L pin is asserted.

                                                                 Reads as 0 when RST_RCV = 1 and the PERST*_L pin is not asserted. */
#else
		uint64_t rst_val                     : 1;
		uint64_t rst_chip                    : 1;
		uint64_t rst_rcv                     : 1;
		uint64_t rst_drv                     : 1;
		uint64_t reserved_4_5                : 2;
		uint64_t host_mode                   : 1;
		uint64_t rst_link                    : 1;
		uint64_t rst_done                    : 1;
		uint64_t prst_link                   : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_rst_ctlx_s              cn85xx; */
	/* struct bdk_rst_ctlx_s              cn88xx; */
	/* struct bdk_rst_ctlx_s              cn88xxp1; */
} bdk_rst_ctlx_t;

static inline uint64_t BDK_RST_CTLX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_CTLX(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E006001640ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_RST_CTLX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RST_CTLX(...) bdk_rst_ctlx_t
#define bustype_BDK_RST_CTLX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_CTLX(p1) (p1)
#define arguments_BDK_RST_CTLX(p1) (p1),-1,-1,-1
#define basename_BDK_RST_CTLX(...) "RST_CTLX"


/**
 * RSL - rst_dbg_reset
 *
 * This register contains the reset control for each core's debug logic.
 *
 */
typedef union bdk_rst_dbg_reset {
	uint64_t u;
	struct bdk_rst_dbg_reset_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t rst                         : 48; /**< R/W - Debug logic reset for each core:
                                                                   0 = Debug logic operates normally.
                                                                   1 = Holds the debug logic in its reset state.

                                                                 The register is reset to 0 only during cold reset, the value is unaffected by
                                                                 warm and soft reset. */
#else
		uint64_t rst                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rst_dbg_reset_s         cn85xx; */
	/* struct bdk_rst_dbg_reset_s         cn88xx; */
	/* struct bdk_rst_dbg_reset_s         cn88xxp1; */
} bdk_rst_dbg_reset_t;

#define BDK_RST_DBG_RESET BDK_RST_DBG_RESET_FUNC()
static inline uint64_t BDK_RST_DBG_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_DBG_RESET_FUNC(void)
{
	return 0x000087E006001750ull;
}
#define typedef_BDK_RST_DBG_RESET bdk_rst_dbg_reset_t
#define bustype_BDK_RST_DBG_RESET BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_DBG_RESET 0
#define arguments_BDK_RST_DBG_RESET -1,-1,-1,-1
#define basename_BDK_RST_DBG_RESET "RST_DBG_RESET"


/**
 * RSL - rst_delay
 */
typedef union bdk_rst_delay {
	uint64_t u;
	struct bdk_rst_delay_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t warm_rst_dly                : 16; /**< R/W - Warm reset delay. A warm reset immediately causes an early warm-reset notification, but
                                                                 the assertion of warm reset is delayed this many coprocessor-clock cycles. A warm/soft
                                                                 reset does not change this field.
                                                                 This must be at least 0x200 coprocessor-clock cycles. */
		uint64_t soft_rst_dly                : 16; /**< R/W - Soft reset delay. A soft reset immediately causes an early soft-reset notification, but
                                                                 the assertion of soft reset is delayed this many coprocessor-clock cycles. A warm/soft
                                                                 reset does not change this field.
                                                                 This must be at least 0x200 coprocessor-clock cycles. */
#else
		uint64_t soft_rst_dly                : 16;
		uint64_t warm_rst_dly                : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_rst_delay_s             cn85xx; */
	/* struct bdk_rst_delay_s             cn88xx; */
	/* struct bdk_rst_delay_s             cn88xxp1; */
} bdk_rst_delay_t;

#define BDK_RST_DELAY BDK_RST_DELAY_FUNC()
static inline uint64_t BDK_RST_DELAY_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_DELAY_FUNC(void)
{
	return 0x000087E006001608ull;
}
#define typedef_BDK_RST_DELAY bdk_rst_delay_t
#define bustype_BDK_RST_DELAY BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_DELAY 0
#define arguments_BDK_RST_DELAY -1,-1,-1,-1
#define basename_BDK_RST_DELAY "RST_DELAY"


/**
 * RSL - rst_int
 */
typedef union bdk_rst_int {
	uint64_t u;
	struct bdk_rst_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t perst                       : 6;  /**< R/W1C/H - PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
		uint64_t reserved_6_7                : 2;
		uint64_t rst_link                    : 6;  /**< R/W1C/H - A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else
		uint64_t rst_link                    : 6;
		uint64_t reserved_6_7                : 2;
		uint64_t perst                       : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_rst_int_s               cn85xx; */
	/* struct bdk_rst_int_s               cn88xx; */
	/* struct bdk_rst_int_s               cn88xxp1; */
} bdk_rst_int_t;

#define BDK_RST_INT BDK_RST_INT_FUNC()
static inline uint64_t BDK_RST_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_FUNC(void)
{
	return 0x000087E006001628ull;
}
#define typedef_BDK_RST_INT bdk_rst_int_t
#define bustype_BDK_RST_INT BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_INT 0
#define arguments_BDK_RST_INT -1,-1,-1,-1
#define basename_BDK_RST_INT "RST_INT"


/**
 * RSL - rst_int_ena_w1c
 */
typedef union bdk_rst_int_ena_w1c {
	uint64_t u;
	struct bdk_rst_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t perst                       : 6;  /**< R/W1C/H - PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
		uint64_t reserved_6_7                : 2;
		uint64_t rst_link                    : 6;  /**< R/W1C/H - A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else
		uint64_t rst_link                    : 6;
		uint64_t reserved_6_7                : 2;
		uint64_t perst                       : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_rst_int_ena_w1c_s       cn85xx; */
	/* struct bdk_rst_int_ena_w1c_s       cn88xx; */
	/* struct bdk_rst_int_ena_w1c_s       cn88xxp1; */
} bdk_rst_int_ena_w1c_t;

#define BDK_RST_INT_ENA_W1C BDK_RST_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_RST_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_ENA_W1C_FUNC(void)
{
	return 0x000087E0060016A8ull;
}
#define typedef_BDK_RST_INT_ENA_W1C bdk_rst_int_ena_w1c_t
#define bustype_BDK_RST_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_INT_ENA_W1C 0
#define arguments_BDK_RST_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_RST_INT_ENA_W1C "RST_INT_ENA_W1C"


/**
 * RSL - rst_int_ena_w1s
 */
typedef union bdk_rst_int_ena_w1s {
	uint64_t u;
	struct bdk_rst_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t perst                       : 6;  /**< R/W1C/H - PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
		uint64_t reserved_6_7                : 2;
		uint64_t rst_link                    : 6;  /**< R/W1C/H - A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else
		uint64_t rst_link                    : 6;
		uint64_t reserved_6_7                : 2;
		uint64_t perst                       : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_rst_int_ena_w1s_s       cn85xx; */
	/* struct bdk_rst_int_ena_w1s_s       cn88xx; */
	/* struct bdk_rst_int_ena_w1s_s       cn88xxp1; */
} bdk_rst_int_ena_w1s_t;

#define BDK_RST_INT_ENA_W1S BDK_RST_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_RST_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_ENA_W1S_FUNC(void)
{
	return 0x000087E0060016A0ull;
}
#define typedef_BDK_RST_INT_ENA_W1S bdk_rst_int_ena_w1s_t
#define bustype_BDK_RST_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_INT_ENA_W1S 0
#define arguments_BDK_RST_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_RST_INT_ENA_W1S "RST_INT_ENA_W1S"


/**
 * RSL - rst_int_w1s
 */
typedef union bdk_rst_int_w1s {
	uint64_t u;
	struct bdk_rst_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t perst                       : 6;  /**< R/W1C/H - PERST*_L asserted while RST_CTL()[RST_RCV] = 1 and RST_CTL()[RST_CHIP] = 0. One bit
                                                                 corresponds to each controller. */
		uint64_t reserved_6_7                : 2;
		uint64_t rst_link                    : 6;  /**< R/W1C/H - A controller link-down/hot-reset occurred while RST_CTL()[RST_LINK] = 0. Software must
                                                                 assert then deassert RST_SOFT_PRST()[SOFT_PRST]. One bit corresponds to each controller. */
#else
		uint64_t rst_link                    : 6;
		uint64_t reserved_6_7                : 2;
		uint64_t perst                       : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_rst_int_w1s_s           cn85xx; */
	/* struct bdk_rst_int_w1s_s           cn88xx; */
	/* struct bdk_rst_int_w1s_s           cn88xxp1; */
} bdk_rst_int_w1s_t;

#define BDK_RST_INT_W1S BDK_RST_INT_W1S_FUNC()
static inline uint64_t BDK_RST_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_INT_W1S_FUNC(void)
{
	return 0x000087E006001630ull;
}
#define typedef_BDK_RST_INT_W1S bdk_rst_int_w1s_t
#define bustype_BDK_RST_INT_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_INT_W1S 0
#define arguments_BDK_RST_INT_W1S -1,-1,-1,-1
#define basename_BDK_RST_INT_W1S "RST_INT_W1S"


/**
 * RSL - rst_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the RST_INT_VEC_E
 * enumeration.
 */
typedef union bdk_rst_msix_pbax {
	uint64_t u;
	struct bdk_rst_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated RST_MSIX_VEC()_CTL, enumerated by
                                                                 RST_INT_VEC_E. Bits that have no associated RST_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_rst_msix_pbax_s         cn85xx; */
	/* struct bdk_rst_msix_pbax_s         cn88xx; */
	/* struct bdk_rst_msix_pbax_s         cn88xxp1; */
} bdk_rst_msix_pbax_t;

static inline uint64_t BDK_RST_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E006FF0000ull;
	csr_fatal("BDK_RST_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RST_MSIX_PBAX(...) bdk_rst_msix_pbax_t
#define bustype_BDK_RST_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_MSIX_PBAX(p1) (p1)
#define arguments_BDK_RST_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_RST_MSIX_PBAX(...) "RST_MSIX_PBAX"


/**
 * RSL - rst_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the RST_INT_VEC_E enumeration.
 *
 */
typedef union bdk_rst_msix_vecx_addr {
	uint64_t u;
	struct bdk_rst_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector can be read or written by either secure or non-secure states.
                                                                 1 = This vector's RST_MSIX_VEC()_ADDR, RST_MSIX_VEC()_CTL, and
                                                                 corresponding bit of RST_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_RST_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_rst_msix_vecx_addr_s    cn85xx; */
	/* struct bdk_rst_msix_vecx_addr_s    cn88xx; */
	/* struct bdk_rst_msix_vecx_addr_s    cn88xxp1; */
} bdk_rst_msix_vecx_addr_t;

static inline uint64_t BDK_RST_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E006F00000ull;
	csr_fatal("BDK_RST_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RST_MSIX_VECX_ADDR(...) bdk_rst_msix_vecx_addr_t
#define bustype_BDK_RST_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_RST_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_RST_MSIX_VECX_ADDR(...) "RST_MSIX_VECX_ADDR"


/**
 * RSL - rst_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the RST_INT_VEC_E enumeration.
 *
 */
typedef union bdk_rst_msix_vecx_ctl {
	uint64_t u;
	struct bdk_rst_msix_vecx_ctl_s {
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
	/* struct bdk_rst_msix_vecx_ctl_s     cn85xx; */
	/* struct bdk_rst_msix_vecx_ctl_s     cn88xx; */
	/* struct bdk_rst_msix_vecx_ctl_s     cn88xxp1; */
} bdk_rst_msix_vecx_ctl_t;

static inline uint64_t BDK_RST_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E006F00008ull;
	csr_fatal("BDK_RST_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RST_MSIX_VECX_CTL(...) bdk_rst_msix_vecx_ctl_t
#define bustype_BDK_RST_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_RST_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_RST_MSIX_VECX_CTL(...) "RST_MSIX_VECX_CTL"


/**
 * RSL - rst_ocx
 */
typedef union bdk_rst_ocx {
	uint64_t u;
	struct bdk_rst_ocx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t rst_link                    : 3;  /**< R/W - Controls whether corresponding OCX link going down causes a chip reset. A warm/soft reset
                                                                 does not change this field. On cold reset, this field is initialized to 0. See
                                                                 OCX_COM_LINK()_CTL for a description of what events can contribute to the link_down
                                                                 condition. */
#else
		uint64_t rst_link                    : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_rst_ocx_s               cn85xx; */
	/* struct bdk_rst_ocx_s               cn88xx; */
	/* struct bdk_rst_ocx_s               cn88xxp1; */
} bdk_rst_ocx_t;

#define BDK_RST_OCX BDK_RST_OCX_FUNC()
static inline uint64_t BDK_RST_OCX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_OCX_FUNC(void)
{
	return 0x000087E006001618ull;
}
#define typedef_BDK_RST_OCX bdk_rst_ocx_t
#define bustype_BDK_RST_OCX BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_OCX 0
#define arguments_BDK_RST_OCX -1,-1,-1,-1
#define basename_BDK_RST_OCX "RST_OCX"


/**
 * RSL - rst_out_ctl
 */
typedef union bdk_rst_out_ctl {
	uint64_t u;
	struct bdk_rst_out_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t soft_rst                    : 1;  /**< R/W - Soft reset. When set to 1 by software, this field drives the RST_OUT_N pin
                                                                 active low. In this case the field must also be cleared by software to deassert
                                                                 the pin. The pin is also automatically asserted and deasserted by hardware
                                                                 during a cold/warm/soft reset. */
#else
		uint64_t soft_rst                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_rst_out_ctl_s           cn85xx; */
	/* struct bdk_rst_out_ctl_s           cn88xx; */
	/* struct bdk_rst_out_ctl_s           cn88xxp1; */
} bdk_rst_out_ctl_t;

#define BDK_RST_OUT_CTL BDK_RST_OUT_CTL_FUNC()
static inline uint64_t BDK_RST_OUT_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_OUT_CTL_FUNC(void)
{
	return 0x000087E006001688ull;
}
#define typedef_BDK_RST_OUT_CTL bdk_rst_out_ctl_t
#define bustype_BDK_RST_OUT_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_OUT_CTL 0
#define arguments_BDK_RST_OUT_CTL -1,-1,-1,-1
#define basename_BDK_RST_OUT_CTL "RST_OUT_CTL"


/**
 * RSL - rst_power_dbg
 */
typedef union bdk_rst_power_dbg {
	uint64_t u;
	struct bdk_rst_power_dbg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t str                         : 3;  /**< R/W - Reserved. INTERNAL: Internal power driver strength. Resets only on cold reset. */
#else
		uint64_t str                         : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_rst_power_dbg_s         cn85xx; */
	/* struct bdk_rst_power_dbg_s         cn88xx; */
	/* struct bdk_rst_power_dbg_s         cn88xxp1; */
} bdk_rst_power_dbg_t;

#define BDK_RST_POWER_DBG BDK_RST_POWER_DBG_FUNC()
static inline uint64_t BDK_RST_POWER_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_POWER_DBG_FUNC(void)
{
	return 0x000087E006001708ull;
}
#define typedef_BDK_RST_POWER_DBG bdk_rst_power_dbg_t
#define bustype_BDK_RST_POWER_DBG BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_POWER_DBG 0
#define arguments_BDK_RST_POWER_DBG -1,-1,-1,-1
#define basename_BDK_RST_POWER_DBG "RST_POWER_DBG"


/**
 * RSL - rst_pp_available
 */
typedef union bdk_rst_pp_available {
	uint64_t u;
	struct bdk_rst_pp_available_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t present                     : 48; /**< RO - Each bit set indicates a physical core is present. */
#else
		uint64_t present                     : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rst_pp_available_s      cn85xx; */
	/* struct bdk_rst_pp_available_s      cn88xx; */
	/* struct bdk_rst_pp_available_s      cn88xxp1; */
} bdk_rst_pp_available_t;

#define BDK_RST_PP_AVAILABLE BDK_RST_PP_AVAILABLE_FUNC()
static inline uint64_t BDK_RST_PP_AVAILABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_AVAILABLE_FUNC(void)
{
	return 0x000087E006001738ull;
}
#define typedef_BDK_RST_PP_AVAILABLE bdk_rst_pp_available_t
#define bustype_BDK_RST_PP_AVAILABLE BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_PP_AVAILABLE 0
#define arguments_BDK_RST_PP_AVAILABLE -1,-1,-1,-1
#define basename_BDK_RST_PP_AVAILABLE "RST_PP_AVAILABLE"


/**
 * RSL - rst_pp_pending
 *
 * This register contains the reset status for each core.
 *
 */
typedef union bdk_rst_pp_pending {
	uint64_t u;
	struct bdk_rst_pp_pending_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t pend                        : 48; /**< RO/H - Set if corresponding core is waiting to change its reset state. Normally a reset change
                                                                 occurs immediately but if RST_PP_POWER[GATE] = 1 and the core is released from
                                                                 reset a delay of 64K core-clock cycles between each core reset applies to satisfy power
                                                                 management. */
#else
		uint64_t pend                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rst_pp_pending_s        cn85xx; */
	/* struct bdk_rst_pp_pending_s        cn88xx; */
	/* struct bdk_rst_pp_pending_s        cn88xxp1; */
} bdk_rst_pp_pending_t;

#define BDK_RST_PP_PENDING BDK_RST_PP_PENDING_FUNC()
static inline uint64_t BDK_RST_PP_PENDING_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_PENDING_FUNC(void)
{
	return 0x000087E006001748ull;
}
#define typedef_BDK_RST_PP_PENDING bdk_rst_pp_pending_t
#define bustype_BDK_RST_PP_PENDING BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_PP_PENDING 0
#define arguments_BDK_RST_PP_PENDING -1,-1,-1,-1
#define basename_BDK_RST_PP_PENDING "RST_PP_PENDING"


/**
 * RSL - rst_pp_power
 */
typedef union bdk_rst_pp_power {
	uint64_t u;
	struct bdk_rst_pp_power_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t gate                        : 48; /**< R/W - Powerdown enable. When a bit in this field and the corresponding RST_PP_RESET bit are set,
                                                                 the core
                                                                 has voltage removed to save power. In typical operation these bits are set up during
                                                                 initialization and core resets are controlled through RST_PP_RESET. These bits can only be
                                                                 changed when the corresponding core is in reset. */
#else
		uint64_t gate                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rst_pp_power_s          cn85xx; */
	/* struct bdk_rst_pp_power_s          cn88xx; */
	/* struct bdk_rst_pp_power_s          cn88xxp1; */
} bdk_rst_pp_power_t;

#define BDK_RST_PP_POWER BDK_RST_PP_POWER_FUNC()
static inline uint64_t BDK_RST_PP_POWER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_POWER_FUNC(void)
{
	return 0x000087E006001700ull;
}
#define typedef_BDK_RST_PP_POWER bdk_rst_pp_power_t
#define bustype_BDK_RST_PP_POWER BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_PP_POWER 0
#define arguments_BDK_RST_PP_POWER -1,-1,-1,-1
#define basename_BDK_RST_PP_POWER "RST_PP_POWER"


/**
 * RSL - rst_pp_power_stat
 */
typedef union bdk_rst_pp_power_stat {
	uint64_t u;
	struct bdk_rst_pp_power_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t down                        : 48; /**< RO/H - Reserved.
                                                                 INTERNAL: Core Powerdown.  When set each bit indicates the core is currently powered down.
                                                                 Typically this occurs when the corresponding RST_PP_RESET and RST_PP_POWER bits are set.
                                                                 If the core is powered down when RST_PP_PENDING and RST_PP_RESET are both clear then the
                                                                 core should be reset again by setting the RST_PP_RESET and then clearing it. */
#else
		uint64_t down                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rst_pp_power_stat_s     cn85xx; */
	/* struct bdk_rst_pp_power_stat_s     cn88xx; */
	/* struct bdk_rst_pp_power_stat_s     cn88xxp1; */
} bdk_rst_pp_power_stat_t;

#define BDK_RST_PP_POWER_STAT BDK_RST_PP_POWER_STAT_FUNC()
static inline uint64_t BDK_RST_PP_POWER_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_POWER_STAT_FUNC(void)
{
	return 0x000087E006001710ull;
}
#define typedef_BDK_RST_PP_POWER_STAT bdk_rst_pp_power_stat_t
#define bustype_BDK_RST_PP_POWER_STAT BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_PP_POWER_STAT 0
#define arguments_BDK_RST_PP_POWER_STAT -1,-1,-1,-1
#define basename_BDK_RST_PP_POWER_STAT "RST_PP_POWER_STAT"


/**
 * RSL - rst_pp_reset
 *
 * This register contains the reset control for each core: 1 = hold core in reset, 0 = release
 * core
 * from reset. It resets to all 1s when GPIO_STRAP\<2:0\> = RST_BOOT_METHOD_E::REMOTE
 * or all 1s excluding bit 0 otherwise.
 * Write operations to this register should occur only if RST_PP_PENDING is cleared.
 */
typedef union bdk_rst_pp_reset {
	uint64_t u;
	struct bdk_rst_pp_reset_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t rst                         : 47; /**< R/W/H - Core reset for cores 1 and above. Writing a 1 holds the corresponding core in reset,
                                                                 writing a 0 releases from reset.  These bits may also be cleared by either DAP or CIC
                                                                 activity. */
		uint64_t rst0                        : 1;  /**< R/W/H - Core reset for core 0, depends on if GPIO_STRAP\<2:0\> = RST_BOOT_METHOD_E::REMOTE.
                                                                 This bit may also be cleared by either DAP or CIC activity. */
#else
		uint64_t rst0                        : 1;
		uint64_t rst                         : 47;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_rst_pp_reset_s          cn85xx; */
	/* struct bdk_rst_pp_reset_s          cn88xx; */
	/* struct bdk_rst_pp_reset_s          cn88xxp1; */
} bdk_rst_pp_reset_t;

#define BDK_RST_PP_RESET BDK_RST_PP_RESET_FUNC()
static inline uint64_t BDK_RST_PP_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_PP_RESET_FUNC(void)
{
	return 0x000087E006001740ull;
}
#define typedef_BDK_RST_PP_RESET bdk_rst_pp_reset_t
#define bustype_BDK_RST_PP_RESET BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_PP_RESET 0
#define arguments_BDK_RST_PP_RESET -1,-1,-1,-1
#define basename_BDK_RST_PP_RESET "RST_PP_RESET"


/**
 * RSL - rst_ref_cntr
 */
typedef union bdk_rst_ref_cntr {
	uint64_t u;
	struct bdk_rst_ref_cntr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< R/W - Count. The counter is initialized to 0x0 during a cold reset and is otherwise continuously
                                                                 running.
                                                                 CNT is incremented every reference-clock cycle (i.e. at 50 MHz). */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_rst_ref_cntr_s          cn85xx; */
	/* struct bdk_rst_ref_cntr_s          cn88xx; */
	/* struct bdk_rst_ref_cntr_s          cn88xxp1; */
} bdk_rst_ref_cntr_t;

#define BDK_RST_REF_CNTR BDK_RST_REF_CNTR_FUNC()
static inline uint64_t BDK_RST_REF_CNTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_REF_CNTR_FUNC(void)
{
	return 0x000087E006001758ull;
}
#define typedef_BDK_RST_REF_CNTR bdk_rst_ref_cntr_t
#define bustype_BDK_RST_REF_CNTR BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_REF_CNTR 0
#define arguments_BDK_RST_REF_CNTR -1,-1,-1,-1
#define basename_BDK_RST_REF_CNTR "RST_REF_CNTR"


/**
 * RSL - rst_soft_prst#
 */
typedef union bdk_rst_soft_prstx {
	uint64_t u;
	struct bdk_rst_soft_prstx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t soft_prst                   : 1;  /**< R/W - Soft PCIe reset. Resets the PCIe logic and corresponding common logic associated with the
                                                                 SLI controller in
                                                                 all modes, not just RC mode.
                                                                 * If RST_CTL()[HOST_MODE] = 0, SOFT_PRST resets to 0.
                                                                 * If RST_CTL()[HOST_MODE] = 1, SOFT_PRST resets to 1.

                                                                 When CNXXXX is configured to drive PERST*_L (i.e.
                                                                 RST_CTL()[RST_DRV] = 1), this controls the output value on PERST*_L.
                                                                 INTERNAL:  This bit is also forced high if the corresponding PEM Cripple Fuse is set. */
#else
		uint64_t soft_prst                   : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_rst_soft_prstx_s        cn85xx; */
	/* struct bdk_rst_soft_prstx_s        cn88xx; */
	/* struct bdk_rst_soft_prstx_s        cn88xxp1; */
} bdk_rst_soft_prstx_t;

static inline uint64_t BDK_RST_SOFT_PRSTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_SOFT_PRSTX(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0060016C0ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_RST_SOFT_PRSTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_RST_SOFT_PRSTX(...) bdk_rst_soft_prstx_t
#define bustype_BDK_RST_SOFT_PRSTX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_SOFT_PRSTX(p1) (p1)
#define arguments_BDK_RST_SOFT_PRSTX(p1) (p1),-1,-1,-1
#define basename_BDK_RST_SOFT_PRSTX(...) "RST_SOFT_PRSTX"


/**
 * RSL - rst_soft_rst
 */
typedef union bdk_rst_soft_rst {
	uint64_t u;
	struct bdk_rst_soft_rst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t soft_rst                    : 1;  /**< WO - Soft reset. When set to 1, resets the CNXXXX core. When performing a soft reset from a
                                                                 remote PCIe host,
                                                                 always read this register and wait for the results before setting SOFT_RST to 1. */
#else
		uint64_t soft_rst                    : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_rst_soft_rst_s          cn85xx; */
	/* struct bdk_rst_soft_rst_s          cn88xx; */
	/* struct bdk_rst_soft_rst_s          cn88xxp1; */
} bdk_rst_soft_rst_t;

#define BDK_RST_SOFT_RST BDK_RST_SOFT_RST_FUNC()
static inline uint64_t BDK_RST_SOFT_RST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_SOFT_RST_FUNC(void)
{
	return 0x000087E006001680ull;
}
#define typedef_BDK_RST_SOFT_RST bdk_rst_soft_rst_t
#define bustype_BDK_RST_SOFT_RST BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_SOFT_RST 0
#define arguments_BDK_RST_SOFT_RST -1,-1,-1,-1
#define basename_BDK_RST_SOFT_RST "RST_SOFT_RST"


/**
 * RSL - rst_thermal_alert
 */
typedef union bdk_rst_thermal_alert {
	uint64_t u;
	struct bdk_rst_thermal_alert_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t trip                        : 1;  /**< R/W1S/H - Thermal trip pin. When set to 1, drives the THERMAL_TRIP_N pin active low. This field is
                                                                 set by either of the
                                                                 onboard temperature sensors reaching a failure threshold or writing this bit.
                                                                 The bit can only be cleared by a deassertion of the PLL_DC_OK pin which completely resets
                                                                 the chip. */
		uint64_t reserved_2_7                : 6;
		uint64_t alert                       : 2;  /**< RO/H - Thermal alert status. When set to 1, indicates the temperature sensor is currently at the
                                                                 failure threshold. */
#else
		uint64_t alert                       : 2;
		uint64_t reserved_2_7                : 6;
		uint64_t trip                        : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_rst_thermal_alert_s     cn85xx; */
	/* struct bdk_rst_thermal_alert_s     cn88xx; */
	/* struct bdk_rst_thermal_alert_s     cn88xxp1; */
} bdk_rst_thermal_alert_t;

#define BDK_RST_THERMAL_ALERT BDK_RST_THERMAL_ALERT_FUNC()
static inline uint64_t BDK_RST_THERMAL_ALERT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_THERMAL_ALERT_FUNC(void)
{
	return 0x000087E006001690ull;
}
#define typedef_BDK_RST_THERMAL_ALERT bdk_rst_thermal_alert_t
#define bustype_BDK_RST_THERMAL_ALERT BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_THERMAL_ALERT 0
#define arguments_BDK_RST_THERMAL_ALERT -1,-1,-1,-1
#define basename_BDK_RST_THERMAL_ALERT "RST_THERMAL_ALERT"


/**
 * RSL - rst_tns_pll_ctl
 *
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
typedef union bdk_rst_tns_pll_ctl {
	uint64_t u;
	struct bdk_rst_tns_pll_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_29_63              : 35;
		uint64_t pll_fbslip                  : 1;  /**< RO/H - PLL FBSLIP indication. */
		uint64_t pll_lock                    : 1;  /**< RO/H - PLL LOCK indication. */
		uint64_t pll_rfslip                  : 1;  /**< RO/H - PLL RFSLIP indication. */
		uint64_t reserved_23_25              : 3;
		uint64_t div_reset                   : 1;  /**< R/W - Postscalar divider reset. */
		uint64_t ps_en                       : 4;  /**< R/W - PLL postscalar divide ratio. Determines the network clock speed.
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

                                                                 PS_EN is not used when DIV_RESET = 1 */
		uint64_t reserved_15_17              : 3;
		uint64_t cout_rst                    : 1;  /**< R/W - Clockout postscaler reset. This clockout postscaler should be placed in reset at
                                                                 least 10 reference-clock cycles prior to changing COUT_SEL. The clockout postscaler
                                                                 should remain under reset for at least 10 reference-clock cycles after COUT_SEL changes. */
		uint64_t cout_sel                    : 2;  /**< R/W - PNR clockout select:
                                                                 0x0 = Network clock.
                                                                 0x1 = PS output.
                                                                 0x2 = PLL output.
                                                                 0x3 = UNDIVIDED core clock. */
		uint64_t reserved_8_11               : 4;
		uint64_t reset_n                     : 1;  /**< R/W - PLL reset. */
		uint64_t clkf                        : 7;  /**< R/W - Multiply reference by CLKF. */
#else
		uint64_t clkf                        : 7;
		uint64_t reset_n                     : 1;
		uint64_t reserved_8_11               : 4;
		uint64_t cout_sel                    : 2;
		uint64_t cout_rst                    : 1;
		uint64_t reserved_15_17              : 3;
		uint64_t ps_en                       : 4;
		uint64_t div_reset                   : 1;
		uint64_t reserved_23_25              : 3;
		uint64_t pll_rfslip                  : 1;
		uint64_t pll_lock                    : 1;
		uint64_t pll_fbslip                  : 1;
		uint64_t reserved_29_63              : 35;
#endif
	} s;
	/* struct bdk_rst_tns_pll_ctl_s       cn85xx; */
	/* struct bdk_rst_tns_pll_ctl_s       cn88xx; */
	/* struct bdk_rst_tns_pll_ctl_s       cn88xxp1; */
} bdk_rst_tns_pll_ctl_t;

#define BDK_RST_TNS_PLL_CTL BDK_RST_TNS_PLL_CTL_FUNC()
static inline uint64_t BDK_RST_TNS_PLL_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RST_TNS_PLL_CTL_FUNC(void)
{
	return 0x000087E006001780ull;
}
#define typedef_BDK_RST_TNS_PLL_CTL bdk_rst_tns_pll_ctl_t
#define bustype_BDK_RST_TNS_PLL_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_RST_TNS_PLL_CTL 0
#define arguments_BDK_RST_TNS_PLL_CTL -1,-1,-1,-1
#define basename_BDK_RST_TNS_PLL_CTL "RST_TNS_PLL_CTL"

#endif /* __BDK_CSRS_RST__ */
