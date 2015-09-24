#ifndef __BDK_CSRS_XCV_H__
#define __BDK_CSRS_XCV_H__
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
 * Cavium XCV.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration xcv_bar_e
 *
 * XCV Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_XCV_BAR_E_XCV_PF_BAR0 (0x87e0db000000ll) /**< Base address for standard registers. */
#define BDK_XCV_BAR_E_XCV_PF_BAR4 (0x87e0dbf00000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration xcv_int_vec_e
 *
 * XCV MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_XCV_INT_VEC_E_ERR (0) /**< See interrupt clears XCV()_ERR_INT, interrupt sets XCV()_ERR_INT_W1S, enable clears
                                       XCV()_ERR_INT_ENA_W1C, and enable sets XCV()_ERR_INT_ENA_W1S. */

/**
 * Register (RSL) xcv_batch_crd_ret
 *
 * XCV Batch Credit Return Register
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_batch_crd_ret_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t crd_ret               : 1;  /**< [  0:  0](WO) In case of the reset event, when this register is written XCV sends out the
                                                                 initial credit batch to BGX. Initial credit value of 16. The write will only
                                                                 take effect when XCV_RESET[ENABLE] is set. */
#else /* Word 0 - Little Endian */
        uint64_t crd_ret               : 1;  /**< [  0:  0](WO) In case of the reset event, when this register is written XCV sends out the
                                                                 initial credit batch to BGX. Initial credit value of 16. The write will only
                                                                 take effect when XCV_RESET[ENABLE] is set. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_batch_crd_ret_s cn; */
} bdk_xcv_batch_crd_ret_t;

#define BDK_XCV_BATCH_CRD_RET BDK_XCV_BATCH_CRD_RET_FUNC()
static inline uint64_t BDK_XCV_BATCH_CRD_RET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_BATCH_CRD_RET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000100ll;
    __bdk_csr_fatal("XCV_BATCH_CRD_RET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_BATCH_CRD_RET bdk_xcv_batch_crd_ret_t
#define bustype_BDK_XCV_BATCH_CRD_RET BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_BATCH_CRD_RET "XCV_BATCH_CRD_RET"
#define device_bar_BDK_XCV_BATCH_CRD_RET 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_BATCH_CRD_RET 0
#define arguments_BDK_XCV_BATCH_CRD_RET -1,-1,-1,-1

/**
 * Register (RSL) xcv_comp_ctl
 *
 * XCV Compensation Controller Register
 * This register controls programmable compensation.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_comp_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t drv_byp               : 1;  /**< [ 63: 63](R/W) When set, bypass the compensation controller and use
                                                                 DRV_NCTL and DRV_PCTL. */
        uint64_t reserved_61_62        : 2;
        uint64_t cmp_pctl              : 5;  /**< [ 60: 56](RO/H) PCTL drive strength from the HW compensation controller. */
        uint64_t reserved_53_55        : 3;
        uint64_t cmp_nctl              : 5;  /**< [ 52: 48](RO/H) NCTL drive strength from the HW compensation controller. */
        uint64_t reserved_45_47        : 3;
        uint64_t drv_pctl              : 5;  /**< [ 44: 40](R/W) PCTL drive strength to use in bypass mode.
                                                                 Reset value of 13 is for 50 ohm termination. */
        uint64_t reserved_37_39        : 3;
        uint64_t drv_nctl              : 5;  /**< [ 36: 32](R/W) NCTL drive strength to use in bypass mode.
                                                                 Reset value of 12 is for 50 ohm termination. */
        uint64_t reserved_31           : 1;
        uint64_t pctl_lock             : 1;  /**< [ 30: 30](RO/H) PCTL Lock. */
        uint64_t pctl_sat              : 1;  /**< [ 29: 29](RO/H) PCTL Saturate. */
        uint64_t reserved_28           : 1;
        uint64_t nctl_lock             : 1;  /**< [ 27: 27](RO/H) NCTL Lock. */
        uint64_t reserved_1_26         : 26;
        uint64_t nctl_sat              : 1;  /**< [  0:  0](RO/H) NCTL Saturate. */
#else /* Word 0 - Little Endian */
        uint64_t nctl_sat              : 1;  /**< [  0:  0](RO/H) NCTL Saturate. */
        uint64_t reserved_1_26         : 26;
        uint64_t nctl_lock             : 1;  /**< [ 27: 27](RO/H) NCTL Lock. */
        uint64_t reserved_28           : 1;
        uint64_t pctl_sat              : 1;  /**< [ 29: 29](RO/H) PCTL Saturate. */
        uint64_t pctl_lock             : 1;  /**< [ 30: 30](RO/H) PCTL Lock. */
        uint64_t reserved_31           : 1;
        uint64_t drv_nctl              : 5;  /**< [ 36: 32](R/W) NCTL drive strength to use in bypass mode.
                                                                 Reset value of 12 is for 50 ohm termination. */
        uint64_t reserved_37_39        : 3;
        uint64_t drv_pctl              : 5;  /**< [ 44: 40](R/W) PCTL drive strength to use in bypass mode.
                                                                 Reset value of 13 is for 50 ohm termination. */
        uint64_t reserved_45_47        : 3;
        uint64_t cmp_nctl              : 5;  /**< [ 52: 48](RO/H) NCTL drive strength from the HW compensation controller. */
        uint64_t reserved_53_55        : 3;
        uint64_t cmp_pctl              : 5;  /**< [ 60: 56](RO/H) PCTL drive strength from the HW compensation controller. */
        uint64_t reserved_61_62        : 2;
        uint64_t drv_byp               : 1;  /**< [ 63: 63](R/W) When set, bypass the compensation controller and use
                                                                 DRV_NCTL and DRV_PCTL. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_comp_ctl_s cn; */
} bdk_xcv_comp_ctl_t;

#define BDK_XCV_COMP_CTL BDK_XCV_COMP_CTL_FUNC()
static inline uint64_t BDK_XCV_COMP_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_COMP_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000020ll;
    __bdk_csr_fatal("XCV_COMP_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_COMP_CTL bdk_xcv_comp_ctl_t
#define bustype_BDK_XCV_COMP_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_COMP_CTL "XCV_COMP_CTL"
#define device_bar_BDK_XCV_COMP_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_COMP_CTL 0
#define arguments_BDK_XCV_COMP_CTL -1,-1,-1,-1

/**
 * Register (RSL) xcv_ctl
 *
 * XCV Control Register
 * This register contains the status control bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t lpbk_ext              : 1;  /**< [  3:  3](R/W) Enable external loopback mode. External loopback loops the RX datapath to the TX
                                                                 datapath. For correct operation, the following CSRs must be configured:
                                                                 * XCV_CTL[SPEED]          = 0x2.
                                                                 * XCV_DLL_CTL[REFCLK_SEL] = 1.
                                                                 * XCV_RESET[CLKRST]       = 1. */
        uint64_t lpbk_int              : 1;  /**< [  2:  2](R/W) Enable internal loopback mode. Internal loopback loops the TX datapath to the RX
                                                                 datapath. For correct operation, the following CSRs must be configured:
                                                                 * XCV_CTL[SPEED]          = 0x2.
                                                                 * XCV_DLL_CTL[REFCLK_SEL] = 0.
                                                                 * XCV_RESET[CLKRST]       = 0. */
        uint64_t speed                 : 2;  /**< [  1:  0](R/W) XCV operational speed:
                                                                   0x0 = 10 Mbps.
                                                                   0x1 = 100 Mbps.
                                                                   0x2 = 1Gbps.
                                                                   0x3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t speed                 : 2;  /**< [  1:  0](R/W) XCV operational speed:
                                                                   0x0 = 10 Mbps.
                                                                   0x1 = 100 Mbps.
                                                                   0x2 = 1Gbps.
                                                                   0x3 = Reserved. */
        uint64_t lpbk_int              : 1;  /**< [  2:  2](R/W) Enable internal loopback mode. Internal loopback loops the TX datapath to the RX
                                                                 datapath. For correct operation, the following CSRs must be configured:
                                                                 * XCV_CTL[SPEED]          = 0x2.
                                                                 * XCV_DLL_CTL[REFCLK_SEL] = 0.
                                                                 * XCV_RESET[CLKRST]       = 0. */
        uint64_t lpbk_ext              : 1;  /**< [  3:  3](R/W) Enable external loopback mode. External loopback loops the RX datapath to the TX
                                                                 datapath. For correct operation, the following CSRs must be configured:
                                                                 * XCV_CTL[SPEED]          = 0x2.
                                                                 * XCV_DLL_CTL[REFCLK_SEL] = 1.
                                                                 * XCV_RESET[CLKRST]       = 1. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_ctl_s cn; */
} bdk_xcv_ctl_t;

#define BDK_XCV_CTL BDK_XCV_CTL_FUNC()
static inline uint64_t BDK_XCV_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000030ll;
    __bdk_csr_fatal("XCV_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_CTL bdk_xcv_ctl_t
#define bustype_BDK_XCV_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_CTL "XCV_CTL"
#define device_bar_BDK_XCV_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_CTL 0
#define arguments_BDK_XCV_CTL -1,-1,-1,-1

/**
 * Register (RSL) xcv_dll_ctl
 *
 * XCV DLL Controller Register
 * The RGMII timing specification requires that devices transmit clock and
 * data synchronously. The specification requires external sources (namely
 * the PC board trace routes) to introduce the appropriate 1.5 to 2.0 ns of
 * delay.
 *
 * To eliminate the need for the PC board delays, the RGMII interface has optional
 * onboard DLL's for both transmit and receive. For correct operation, at most one
 * of the transmitter, board, or receiver involved in an RGMII link should
 * introduce delay. By default/reset, the RGMII receivers delay the received clock,
 * and the RGMII transmitters do not delay the transmitted clock. Whether this
 * default works as-is with a given link partner depends on the behavior of the
 * link partner and the PC board.
 *
 * These are the possible modes of RGMII receive operation:
 *
 * * XCV_PRTx_CTL[CLKRX_BYP] = 0 (reset value) - The RGMII
 * receive interface introduces clock delay using its internal DLL.
 * This mode is appropriate if neither the remote
 * transmitter nor the PC board delays the clock.
 *
 * * XCV_PRTx_CTL[CLKRX_BYP] = 1, [CLKRX_SET] = 0x0 - The
 * RGMII receive interface introduces no clock delay. This mode
 * is appropriate if either the remote transmitter or the PC board
 * delays the clock.
 *
 * These are the possible modes of RGMII transmit operation:
 *
 * * XCV_PRTx_CTL[CLKTX_BYP] = 1, [CLKTX_SET] = 0x0 (reset value) -
 * The RGMII transmit interface introduces no clock
 * delay. This mode is appropriate is either the remote receiver
 * or the PC board delays the clock.
 *
 * * XCV_PRTx_CTL[CLKTX_BYP] = 0 - The RGMII transmit
 * interface introduces clock delay using its internal DLL.
 * This mode is appropriate if neither the remote receiver
 * nor the PC board delays the clock
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_dll_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t lock                  : 1;  /**< [ 31: 31](RO/H) DLL is locked. */
        uint64_t clk_set               : 7;  /**< [ 30: 24](RO/H) The clock delay as determined by the on board HW DLL. */
        uint64_t clkrx_byp             : 1;  /**< [ 23: 23](R/W) Bypass the RX clock delay setting.
                                                                 Skews RXC from RXD, RXCTL.
                                                                 By default, HW internally shifts the RXC clock
                                                                 to sample RXD,RXCTL assuming clock and data and
                                                                 sourced synchronously from the link partner. */
        uint64_t clkrx_set             : 7;  /**< [ 22: 16](R/W) RX clock delay setting to use in bypass mode.
                                                                 Skews RXC from RXD. */
        uint64_t clktx_byp             : 1;  /**< [ 15: 15](R/W) Bypass the TX clock delay setting.
                                                                 Skews TXC from TXD, TXCTL.
                                                                 By default, clock and data and sourced
                                                                 synchronously. */
        uint64_t clktx_set             : 7;  /**< [ 14:  8](R/W) TX clock delay setting to use in bypass mode.
                                                                 Skews TXC from TXD. */
        uint64_t reserved_2_7          : 6;
        uint64_t refclk_sel            : 2;  /**< [  1:  0](R/W) Select the refclk to use.  Normal RGMII specification requires a 125MHz oscillator.  In
                                                                 order to reduce system cost, a 500MHz coprocessor clock can be divided down and remove the
                                                                 requirements for the external oscillator.  Additionally, in some well defined systems, the
                                                                 link partner may be able to source the RXC.  The RGMII would operate correctly in 1000Mbs
                                                                 mode only.
                                                                 0x0 = RGMII REFCLK.
                                                                 0x1 = RGMII RXC (1000Mbs only).
                                                                 0x2 = Divided coprocessor clk.
                                                                 0x3 = Reserved.

                                                                 INTERNAL: Some programming magic could allow for 10/100 operation if
                                                                 critical, use encoding 0x1 but some programming restrictions would apply. */
#else /* Word 0 - Little Endian */
        uint64_t refclk_sel            : 2;  /**< [  1:  0](R/W) Select the refclk to use.  Normal RGMII specification requires a 125MHz oscillator.  In
                                                                 order to reduce system cost, a 500MHz coprocessor clock can be divided down and remove the
                                                                 requirements for the external oscillator.  Additionally, in some well defined systems, the
                                                                 link partner may be able to source the RXC.  The RGMII would operate correctly in 1000Mbs
                                                                 mode only.
                                                                 0x0 = RGMII REFCLK.
                                                                 0x1 = RGMII RXC (1000Mbs only).
                                                                 0x2 = Divided coprocessor clk.
                                                                 0x3 = Reserved.

                                                                 INTERNAL: Some programming magic could allow for 10/100 operation if
                                                                 critical, use encoding 0x1 but some programming restrictions would apply. */
        uint64_t reserved_2_7          : 6;
        uint64_t clktx_set             : 7;  /**< [ 14:  8](R/W) TX clock delay setting to use in bypass mode.
                                                                 Skews TXC from TXD. */
        uint64_t clktx_byp             : 1;  /**< [ 15: 15](R/W) Bypass the TX clock delay setting.
                                                                 Skews TXC from TXD, TXCTL.
                                                                 By default, clock and data and sourced
                                                                 synchronously. */
        uint64_t clkrx_set             : 7;  /**< [ 22: 16](R/W) RX clock delay setting to use in bypass mode.
                                                                 Skews RXC from RXD. */
        uint64_t clkrx_byp             : 1;  /**< [ 23: 23](R/W) Bypass the RX clock delay setting.
                                                                 Skews RXC from RXD, RXCTL.
                                                                 By default, HW internally shifts the RXC clock
                                                                 to sample RXD,RXCTL assuming clock and data and
                                                                 sourced synchronously from the link partner. */
        uint64_t clk_set               : 7;  /**< [ 30: 24](RO/H) The clock delay as determined by the on board HW DLL. */
        uint64_t lock                  : 1;  /**< [ 31: 31](RO/H) DLL is locked. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_dll_ctl_s cn; */
} bdk_xcv_dll_ctl_t;

#define BDK_XCV_DLL_CTL BDK_XCV_DLL_CTL_FUNC()
static inline uint64_t BDK_XCV_DLL_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_DLL_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000010ll;
    __bdk_csr_fatal("XCV_DLL_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_DLL_CTL bdk_xcv_dll_ctl_t
#define bustype_BDK_XCV_DLL_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_DLL_CTL "XCV_DLL_CTL"
#define device_bar_BDK_XCV_DLL_CTL 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_DLL_CTL 0
#define arguments_BDK_XCV_DLL_CTL -1,-1,-1,-1

/**
 * Register (RSL) xcv_eco
 *
 * INTERNAL: XCV ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t eco_rw                : 16; /**< [ 15:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 16; /**< [ 15:  0](R/W) INTERNAL: Reserved for ECO usage. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_eco_s cn; */
} bdk_xcv_eco_t;

#define BDK_XCV_ECO BDK_XCV_ECO_FUNC()
static inline uint64_t BDK_XCV_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000200ll;
    __bdk_csr_fatal("XCV_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_ECO bdk_xcv_eco_t
#define bustype_BDK_XCV_ECO BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_ECO "XCV_ECO"
#define device_bar_BDK_XCV_ECO 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_ECO 0
#define arguments_BDK_XCV_ECO -1,-1,-1,-1

/**
 * Register (RSL) xcv_err_int
 *
 * XCV Error Interupt Register
 * This register controls interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_err_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1C/H) TX FIFO overflow. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1C/H) TX FIFO underflow. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1C/H) Flags the incomplete byte cases for 10/100 mode. */
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1C/H) Flags the inband status change on link duplex. */
        uint64_t reserved_2            : 1;
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1C/H) Flags the inband status change on link speed. */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1C/H) Flags the inband status change on link up/down status. */
#else /* Word 0 - Little Endian */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1C/H) Flags the inband status change on link up/down status. */
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1C/H) Flags the inband status change on link speed. */
        uint64_t reserved_2            : 1;
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1C/H) Flags the inband status change on link duplex. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1C/H) Flags the incomplete byte cases for 10/100 mode. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1C/H) TX FIFO underflow. */
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1C/H) TX FIFO overflow. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_err_int_s cn; */
} bdk_xcv_err_int_t;

#define BDK_XCV_ERR_INT BDK_XCV_ERR_INT_FUNC()
static inline uint64_t BDK_XCV_ERR_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_ERR_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000040ll;
    __bdk_csr_fatal("XCV_ERR_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_ERR_INT bdk_xcv_err_int_t
#define bustype_BDK_XCV_ERR_INT BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_ERR_INT "XCV_ERR_INT"
#define device_bar_BDK_XCV_ERR_INT 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_ERR_INT 0
#define arguments_BDK_XCV_ERR_INT -1,-1,-1,-1

/**
 * Register (RSL) xcv_err_int_ena_w1c
 *
 * Loopback Error Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_err_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for XCV_ERR_INT[TX_OVRFLW]. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for XCV_ERR_INT[TX_UNDFLW]. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for XCV_ERR_INT[INCOMP_BYTE]. */
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for XCV_ERR_INT[DUPLEX]. */
        uint64_t reserved_2            : 1;
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for XCV_ERR_INT[SPEED]. */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for XCV_ERR_INT[LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for XCV_ERR_INT[LINK]. */
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for XCV_ERR_INT[SPEED]. */
        uint64_t reserved_2            : 1;
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for XCV_ERR_INT[DUPLEX]. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for XCV_ERR_INT[INCOMP_BYTE]. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for XCV_ERR_INT[TX_UNDFLW]. */
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for XCV_ERR_INT[TX_OVRFLW]. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_err_int_ena_w1c_s cn; */
} bdk_xcv_err_int_ena_w1c_t;

#define BDK_XCV_ERR_INT_ENA_W1C BDK_XCV_ERR_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_XCV_ERR_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_ERR_INT_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000050ll;
    __bdk_csr_fatal("XCV_ERR_INT_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_ERR_INT_ENA_W1C bdk_xcv_err_int_ena_w1c_t
#define bustype_BDK_XCV_ERR_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_ERR_INT_ENA_W1C "XCV_ERR_INT_ENA_W1C"
#define device_bar_BDK_XCV_ERR_INT_ENA_W1C 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_ERR_INT_ENA_W1C 0
#define arguments_BDK_XCV_ERR_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) xcv_err_int_ena_w1s
 *
 * Loopback Error Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_err_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for XCV_ERR_INT[TX_OVRFLW]. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for XCV_ERR_INT[TX_UNDFLW]. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for XCV_ERR_INT[INCOMP_BYTE]. */
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for XCV_ERR_INT[DUPLEX]. */
        uint64_t reserved_2            : 1;
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for XCV_ERR_INT[SPEED]. */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for XCV_ERR_INT[LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for XCV_ERR_INT[LINK]. */
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for XCV_ERR_INT[SPEED]. */
        uint64_t reserved_2            : 1;
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for XCV_ERR_INT[DUPLEX]. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for XCV_ERR_INT[INCOMP_BYTE]. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for XCV_ERR_INT[TX_UNDFLW]. */
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for XCV_ERR_INT[TX_OVRFLW]. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_err_int_ena_w1s_s cn; */
} bdk_xcv_err_int_ena_w1s_t;

#define BDK_XCV_ERR_INT_ENA_W1S BDK_XCV_ERR_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_XCV_ERR_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_ERR_INT_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000058ll;
    __bdk_csr_fatal("XCV_ERR_INT_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_ERR_INT_ENA_W1S bdk_xcv_err_int_ena_w1s_t
#define bustype_BDK_XCV_ERR_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_ERR_INT_ENA_W1S "XCV_ERR_INT_ENA_W1S"
#define device_bar_BDK_XCV_ERR_INT_ENA_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_ERR_INT_ENA_W1S 0
#define arguments_BDK_XCV_ERR_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) xcv_err_int_w1s
 *
 * Loopback Error Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_err_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets XCV_ERR_INT[TX_OVRFLW]. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets XCV_ERR_INT[TX_UNDFLW]. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1S/H) Reads or sets XCV_ERR_INT[INCOMP_BYTE]. */
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets XCV_ERR_INT[DUPLEX]. */
        uint64_t reserved_2            : 1;
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets XCV_ERR_INT[SPEED]. */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets XCV_ERR_INT[LINK]. */
#else /* Word 0 - Little Endian */
        uint64_t link                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets XCV_ERR_INT[LINK]. */
        uint64_t speed                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets XCV_ERR_INT[SPEED]. */
        uint64_t reserved_2            : 1;
        uint64_t duplex                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets XCV_ERR_INT[DUPLEX]. */
        uint64_t incomp_byte           : 1;  /**< [  4:  4](R/W1S/H) Reads or sets XCV_ERR_INT[INCOMP_BYTE]. */
        uint64_t tx_undflw             : 1;  /**< [  5:  5](R/W1S/H) Reads or sets XCV_ERR_INT[TX_UNDFLW]. */
        uint64_t tx_ovrflw             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets XCV_ERR_INT[TX_OVRFLW]. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_err_int_w1s_s cn; */
} bdk_xcv_err_int_w1s_t;

#define BDK_XCV_ERR_INT_W1S BDK_XCV_ERR_INT_W1S_FUNC()
static inline uint64_t BDK_XCV_ERR_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_ERR_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000048ll;
    __bdk_csr_fatal("XCV_ERR_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_ERR_INT_W1S bdk_xcv_err_int_w1s_t
#define bustype_BDK_XCV_ERR_INT_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_ERR_INT_W1S "XCV_ERR_INT_W1S"
#define device_bar_BDK_XCV_ERR_INT_W1S 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_ERR_INT_W1S 0
#define arguments_BDK_XCV_ERR_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) xcv_inbnd_status
 *
 * XCV Interupt Register
 * This register contains RGMII inband status.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_inbnd_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t duplex                : 1;  /**< [  3:  3](RO/H) RGMII inband status - link duplex:
                                                                 0 = Half-duplex.
                                                                 1 = Full-duplex. */
        uint64_t speed                 : 2;  /**< [  2:  1](RO/H) RGMII inband status - link speed:
                                                                 0x0 = 10 Mbps.
                                                                 0x1 = 100 Mbps.
                                                                 0x2 = 1000 Mbps.
                                                                 0x3 = Reserved. */
        uint64_t link                  : 1;  /**< [  0:  0](RO/H) RGMII inband status - link enable/up:
                                                                 0 = Link down.
                                                                 1 = Link up. */
#else /* Word 0 - Little Endian */
        uint64_t link                  : 1;  /**< [  0:  0](RO/H) RGMII inband status - link enable/up:
                                                                 0 = Link down.
                                                                 1 = Link up. */
        uint64_t speed                 : 2;  /**< [  2:  1](RO/H) RGMII inband status - link speed:
                                                                 0x0 = 10 Mbps.
                                                                 0x1 = 100 Mbps.
                                                                 0x2 = 1000 Mbps.
                                                                 0x3 = Reserved. */
        uint64_t duplex                : 1;  /**< [  3:  3](RO/H) RGMII inband status - link duplex:
                                                                 0 = Half-duplex.
                                                                 1 = Full-duplex. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_inbnd_status_s cn; */
} bdk_xcv_inbnd_status_t;

#define BDK_XCV_INBND_STATUS BDK_XCV_INBND_STATUS_FUNC()
static inline uint64_t BDK_XCV_INBND_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_INBND_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000080ll;
    __bdk_csr_fatal("XCV_INBND_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_INBND_STATUS bdk_xcv_inbnd_status_t
#define bustype_BDK_XCV_INBND_STATUS BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_INBND_STATUS "XCV_INBND_STATUS"
#define device_bar_BDK_XCV_INBND_STATUS 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_INBND_STATUS 0
#define arguments_BDK_XCV_INBND_STATUS -1,-1,-1,-1

/**
 * Register (RSL) xcv_msix_pba#
 *
 * XCV MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the XCV_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated XCV_MSIX_VEC()_CTL, enumerated by
                                                                 XCV_INT_VEC_E. Bits that have no associated XCV_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated XCV_MSIX_VEC()_CTL, enumerated by
                                                                 XCV_INT_VEC_E. Bits that have no associated XCV_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_msix_pbax_s cn; */
} bdk_xcv_msix_pbax_t;

static inline uint64_t BDK_XCV_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e0dbff0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("XCV_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_XCV_MSIX_PBAX(a) bdk_xcv_msix_pbax_t
#define bustype_BDK_XCV_MSIX_PBAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_MSIX_PBAX(a) "XCV_MSIX_PBAX"
#define device_bar_BDK_XCV_MSIX_PBAX(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_XCV_MSIX_PBAX(a) (a)
#define arguments_BDK_XCV_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) xcv_msix_vec#_addr
 *
 * XCV MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the XCV_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's XCV_MSIX_VEC()_ADDR, XCV_MSIX_VEC()_CTL, and corresponding
                                                                 bit of XCV_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_XCV_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's XCV_MSIX_VEC()_ADDR, XCV_MSIX_VEC()_CTL, and corresponding
                                                                 bit of XCV_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_XCV_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_msix_vecx_addr_s cn; */
} bdk_xcv_msix_vecx_addr_t;

static inline uint64_t BDK_XCV_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e0dbf00000ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("XCV_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_XCV_MSIX_VECX_ADDR(a) bdk_xcv_msix_vecx_addr_t
#define bustype_BDK_XCV_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_MSIX_VECX_ADDR(a) "XCV_MSIX_VECX_ADDR"
#define device_bar_BDK_XCV_MSIX_VECX_ADDR(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_XCV_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_XCV_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) xcv_msix_vec#_ctl
 *
 * XCV MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the XCV_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_msix_vecx_ctl_s
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
    /* struct bdk_xcv_msix_vecx_ctl_s cn; */
} bdk_xcv_msix_vecx_ctl_t;

static inline uint64_t BDK_XCV_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e0dbf00008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("XCV_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_XCV_MSIX_VECX_CTL(a) bdk_xcv_msix_vecx_ctl_t
#define bustype_BDK_XCV_MSIX_VECX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_MSIX_VECX_CTL(a) "XCV_MSIX_VECX_CTL"
#define device_bar_BDK_XCV_MSIX_VECX_CTL(a) 0x4 /* PF_BAR4 */
#define busnum_BDK_XCV_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_XCV_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) xcv_reset
 *
 * XCV Reset Registers
 * This register controls reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_xcv_reset_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t enable                : 1;  /**< [ 63: 63](R/W) Port enable. */
        uint64_t reserved_16_62        : 47;
        uint64_t clkrst                : 1;  /**< [ 15: 15](R/W) DLL CLK reset.  CLKRST must be set if DLL bypass mode
                                                                 XCV_DLL_CTL[CLKRX_BYP,CLKTX_BYP] is used. */
        uint64_t reserved_12_14        : 3;
        uint64_t dllrst                : 1;  /**< [ 11: 11](R/W) DLL reset. */
        uint64_t reserved_8_10         : 3;
        uint64_t comp                  : 1;  /**< [  7:  7](R/W) Compensation enable. */
        uint64_t reserved_4_6          : 3;
        uint64_t tx_pkt_rst_n          : 1;  /**< [  3:  3](R/W) Packet reset for TX. */
        uint64_t tx_dat_rst_n          : 1;  /**< [  2:  2](R/W) Datapath reset for TX. */
        uint64_t rx_pkt_rst_n          : 1;  /**< [  1:  1](R/W) Packet reset for RX. */
        uint64_t rx_dat_rst_n          : 1;  /**< [  0:  0](R/W) Datapath reset for RX. */
#else /* Word 0 - Little Endian */
        uint64_t rx_dat_rst_n          : 1;  /**< [  0:  0](R/W) Datapath reset for RX. */
        uint64_t rx_pkt_rst_n          : 1;  /**< [  1:  1](R/W) Packet reset for RX. */
        uint64_t tx_dat_rst_n          : 1;  /**< [  2:  2](R/W) Datapath reset for TX. */
        uint64_t tx_pkt_rst_n          : 1;  /**< [  3:  3](R/W) Packet reset for TX. */
        uint64_t reserved_4_6          : 3;
        uint64_t comp                  : 1;  /**< [  7:  7](R/W) Compensation enable. */
        uint64_t reserved_8_10         : 3;
        uint64_t dllrst                : 1;  /**< [ 11: 11](R/W) DLL reset. */
        uint64_t reserved_12_14        : 3;
        uint64_t clkrst                : 1;  /**< [ 15: 15](R/W) DLL CLK reset.  CLKRST must be set if DLL bypass mode
                                                                 XCV_DLL_CTL[CLKRX_BYP,CLKTX_BYP] is used. */
        uint64_t reserved_16_62        : 47;
        uint64_t enable                : 1;  /**< [ 63: 63](R/W) Port enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_xcv_reset_s cn; */
} bdk_xcv_reset_t;

#define BDK_XCV_RESET BDK_XCV_RESET_FUNC()
static inline uint64_t BDK_XCV_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_XCV_RESET_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0db000000ll;
    __bdk_csr_fatal("XCV_RESET", 0, 0, 0, 0, 0);
}

#define typedef_BDK_XCV_RESET bdk_xcv_reset_t
#define bustype_BDK_XCV_RESET BDK_CSR_TYPE_RSL
#define basename_BDK_XCV_RESET "XCV_RESET"
#define device_bar_BDK_XCV_RESET 0x0 /* PF_BAR0 */
#define busnum_BDK_XCV_RESET 0
#define arguments_BDK_XCV_RESET -1,-1,-1,-1

#endif /* __BDK_CSRS_XCV_H__ */
