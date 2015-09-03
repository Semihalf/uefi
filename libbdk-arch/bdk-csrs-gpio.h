#ifndef __BDK_CSRS_GPIO_H__
#define __BDK_CSRS_GPIO_H__
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
 * Cavium GPIO.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration gpio_bar_e
 *
 * GPIO Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_GPIO_BAR_E_GPIO_PF_BAR0 (0x803000000000ll) /**< Base address for standard registers. */
#define BDK_GPIO_BAR_E_GPIO_PF_BAR4 (0x803000f00000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration gpio_int_vec_e
 *
 * GPIO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_GPIO_INT_VEC_E_INTR_PINX(a) (0x30 + 2 * (a)) /**< GPIO general interrupts.
                                       See interrupt clears GPIO_INTR(0..50)[INTR],
                                       interrupt sets GPIO_INTR(0..50)[INTR_W1S],
                                       enable clears GPIO_INTR(0..50)[INTR_ENA_W1C],
                                       and enable sets GPIO_INTR(0..50)[INTR_ENA_W1S]. */
#define BDK_GPIO_INT_VEC_E_INTR_PINX_CLEAR(a) (0x31 + 2 * (a)) /**< Level sensitive interrupt clear vector. */
#define BDK_GPIO_INT_VEC_E_MC_INTR_PPX(a) (0 + (a)) /**< GPIO multicast interrupts.
                                       All four pins 4..7 are collapsed onto the same vector.
                                       See interrupt clears GPIO_MC_INTR(4..7)[INTR<{a}>],
                                       interrupt sets GPIO_MC_INTR(4..7)_W1S[INTR<{a}>],
                                       enable clears GPIO_MC_INTR(4..7)_ENA_W1C[INTR<{a}>],
                                       and enable sets GPIO_MC_INTR(4..7)_ENA_W1S[INTR<{a}>]. */

/**
 * Enumeration gpio_pin_sel_e
 *
 * GPIO Output Select Enumeration
 * Enumerates the GPIO pin function selections for GPIO_BIT_CFG()[PIN_SEL].
 * The GPIO pins can be configured as either input or output depending on selected function's
 * definition.
 * When GPIO pin is used as input pin, GPIO input is reported to selected function as well as
 * GPIO_RX_DAT.
 */
#define BDK_GPIO_PIN_SEL_E_BOOT_ADH (0xba) /**< Boot-bus high address and data inputs and outputs.
                                       
                                       This encoding must be used on 16 contiguous GPIO pins, either GPIO<32..47>, or
                                       GPIO<48..63>.
                                       
                                       <pre>
                                       BOOT_AD<16>  = GPIO<32> or <48>
                                       BOOT_AD<17>  = GPIO<33> or <49>
                                       BOOT_AD ...
                                       BOOT_AD<31>  = GPIO<47> or <63>
                                       </pre> */
#define BDK_GPIO_PIN_SEL_E_BOOT_ADL (0xb9) /**< Boot-bus low address and data inputs and outputs.
                                       
                                       This encoding must be used on 16 contiguous GPIO pins, either GPIO<16..31>, or
                                       GPIO<32..47>.
                                       
                                       <pre>
                                       BOOT_AD<0>   = GPIO<16> or <32>
                                       BOOT_AD<1>   = GPIO<17> or <33>
                                       BOOT_AD ...
                                       BOOT_AD<15>  = GPIO<31> or <47>
                                       </pre> */
#define BDK_GPIO_PIN_SEL_E_GPIO_CLKX(a) (5 + (a)) /**< GPIO clock generator output; see GPIO_CLK_GEN(). */
#define BDK_GPIO_PIN_SEL_E_GPIO_CLK_SYNCEX(a) (3 + (a)) /**< CLK_SYNCE({a}) output; see GPIO_CLK_SYNCE(). */
#define BDK_GPIO_PIN_SEL_E_GPIO_PTP_CKOUT (1) /**< PTP CKOUT output; see MIO_PTP_CLOCK_CFG. */
#define BDK_GPIO_PIN_SEL_E_GPIO_PTP_PPS (2) /**< PTP PPS output; see MIO_PTP_CLOCK_CFG. */
#define BDK_GPIO_PIN_SEL_E_GPIO_SW (0) /**< Normal software controlled GPIO output, controlled by GPIO_TX_SET, GPIO_TX_CLR. */
#define BDK_GPIO_PIN_SEL_E_LMCX_ECC(a) (0x70 + (a)) /**< LMC ECC error detected output; see LMC chapter. */
#define BDK_GPIO_PIN_SEL_E_MCDX_IN(a) (0xb0 + (a)) /**< Multichip debug input; see OCLA chapter.
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_MCDX_OUT(a) (0x14 + (a)) /**< Multichip debug output; see OCLA chapter. */
#define BDK_GPIO_PIN_SEL_E_NCSI (0xb8) /**< NCSI inputs and outputs.
                                       
                                       This encoding must be used on 8 contiguous GPIO pins, either GPIO<16..31>,
                                       GPIO<24..31>, GPIO<32..39>, GPIO<40..47>, GPIO<48..55> or GPIO<56..63>.
                                       
                                       <pre>
                                       NCSI_REF_CLK input = GPIO<16> or <24> or <32> or <40> or <48> or <56>
                                       NCSI_TX_EN output  = GPIO<17> or <25> or <33> or <41> or <49> or <57>
                                       NCSI_TXD<0> output = GPIO<18> or <26> or <34> or <42> or <50> or <58>
                                       NCSI_TXD<1> output = GPIO<19> or <27> or <35> or <43> or <51> or <59>
                                       NCSI_CRS_DV input  = GPIO<20> or <28> or <36> or <44> or <52> or <60>
                                       NCSI_RXD<0> input  = GPIO<21> or <29> or <37> or <45> or <53> or <61>
                                       NCSI_RXD<1> input  = GPIO<22> or <30> or <38> or <46> or <54> or <62>
                                       NCSI_RX_ER input   = GPIO<23> or <31> or <39> or <47> or <55> or <63>
                                       </pre> */
#define BDK_GPIO_PIN_SEL_E_OCLA_EXT_TRIGGER (0x8a) /**< OCLA external trigger input; see OCLA()_GEN_CTL[EXTEN].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_SATAX_ACT_LED(a) (0x60 + (a)) /**< SATA activity LED output; see SATA chapter. */
#define BDK_GPIO_PIN_SEL_E_SATAX_CP_DET(a) (0x90 + (a)) /**< SATA cold presence detect input; detects addition (1) or removal (0) of the
                                       powered-down device; see SATA()_UAHC_P0_CMD[CPS].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_SATAX_CP_POD(a) (0x50 + (a)) /**< SATA cold-presence power-on device output; see SATA()_UAHC_P0_CMD[POD]. */
#define BDK_GPIO_PIN_SEL_E_SATAX_MP_SWITCH(a) (0xa0 + (a)) /**< SATA mechanical presence switch input; indicated the state of external device
                                       presence switch (0) switch open, (1) switch closed. See SATA()_UAHC_P0_CMD[MPSS].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_SATA_LAB_LB (0x8e) /**< SATA BIST lab-loopback pin. See SATA chapter.
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_SGPIO_ACT_LEDX(a) (0x20 + (a)) /**< SGPIO automatic mode active LED output; see SGP_TX().
                                       Note this output is only valid when SGP is in automatic shift mode
                                       (SGP_IMP_CTL[HOLD]=0). */
#define BDK_GPIO_PIN_SEL_E_SGPIO_ERR_LEDX(a) (0x30 + (a)) /**< SGPIO automatic mode error LED output; see SGP_TX().
                                       Note this output is only valid when SGP is in automatic shift mode
                                       (SGP_IMP_CTL[HOLD]=0). */
#define BDK_GPIO_PIN_SEL_E_SGPIO_LOC_LEDX(a) (0x40 + (a)) /**< SGPIO automatic mode locate LED output; see SGP_TX().
                                       Note this output is only valid when SGP is in automatic shift mode
                                       (SGP_IMP_CTL[HOLD]=0). */
#define BDK_GPIO_PIN_SEL_E_SGPIO_SCLOCK (0xb) /**< SGPIO SCLOCK output; see SGPIO_IMP_CLK. */
#define BDK_GPIO_PIN_SEL_E_SGPIO_SDATAINX(a) (0x80 + (a)) /**< SGPIO SDATAIN input; see SGPIO_RX_GP.
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_SGPIO_SDATAOUTX(a) (0x10 + (a)) /**< SGPIO SDATAOUT output; see SGPIO_TX_GP. */
#define BDK_GPIO_PIN_SEL_E_SGPIO_SLOAD (0xc) /**< SGPIO SLOAD output; see SGPIO_TX_GP_CFG. */
#define BDK_GPIO_PIN_SEL_E_SPI_CSX(a) (0x18 + (a)) /**< SPI/MPI_CS(2..3) output; see MPI_TX[CS_ID]. */
#define BDK_GPIO_PIN_SEL_E_TIMER (0x8b) /**< Reserved.
                                       INTERNAL: For CN83XX,
                                       Timer coprocessor control input; see TIM chapter.
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_UARTX_DCD_N(a) (0x84 + (a)) /**< UART_DCD_N input; see UAA(0..1)_FR[DCD].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_UARTX_DSR(a) (0x88 + (a)) /**< UART_DSR input; see UAA(0..1)_FR[DSR].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_UARTX_DTR_N(a) (9 + (a)) /**< UART_DTR_N output; see UAA()_CR[DTR]. */
#define BDK_GPIO_PIN_SEL_E_UARTX_RI(a) (0x86 + (a)) /**< UART_RI input; see UAA(0..1)_FR[RI].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_USBX_OVR_CRNT(a) (0x8c + (a)) /**< USB over-current input; see USBH(0..1)_UCTL_HOST_CFG[OCI_EN].
                                       
                                       Multiple GPIO pins may not be configured to point to the same input encoding, or
                                       the input result is unpredictable.  (e.g. GPIO_BIT_CFG(1)[PIN_SEL] and
                                       GPIO_BIT_CFG(2)[PIN_SEL] cannot both be 0x80.) */
#define BDK_GPIO_PIN_SEL_E_USBX_VBUS_CTRL(a) (0x74 + (a)) /**< USBH Vbus control output; see USB chapter. */

/**
 * Register (NCB) gpio_bit_cfg#
 *
 * GPIO Bit Configuration Registers
 * Each register provides configuration information for the corresponding GPIO pin.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_bit_cfgx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_24_63        : 40;
        uint64_t pin_sel               : 8;  /**< [ 23: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_13_15        : 3;
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after  PIN_SEL mux
                                                                 and [PIN_XOR] invertor.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output.  With both TX_OD and PIN_XOR set, a transmit
                                                                 of 1 will tristate the pin output driver to archive open-drain function. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter are XOR inverter are also appliable to GPIO input muxing signals and interrupts. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples (FIL_CNT+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter are XOR inverter are also appliable to GPIO input muxing signals and interrupts. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter as well XOR inverter. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controlls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA]. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiveing or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO PIN_SEL muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO PIN_SEL muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output pin
                                                                 if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_SW. TX_OE is only used along with GPIO_TX_SET
                                                                 or GPIO_TX_CLR, and TX_OE function is before GPIO_BIT_CFG()[PIN_SEL] mux. */
#else /* Word 0 - Little Endian */
        uint64_t tx_oe                 : 1;  /**< [  0:  0](R/W) Transmit output enable. When set to 1, the GPIO pin can be driven as an output pin
                                                                 if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_SW. TX_OE is only used along with GPIO_TX_SET
                                                                 or GPIO_TX_CLR, and TX_OE function is before GPIO_BIT_CFG()[PIN_SEL] mux. */
        uint64_t pin_xor               : 1;  /**< [  1:  1](R/W) GPIO data inversion. When set, inverts the receiveing or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO PIN_SEL muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO PIN_SEL muxes, as used to control
                                                                 GPIO interrupts. */
        uint64_t int_en                : 1;  /**< [  2:  2](R/W) Pin controlls interrupt.

                                                                 If set, assertions of this pin after [PIN_XOR] will set GPIO_INTR()[INTR].

                                                                 If set and [INT_TYPE] is clear (level-sensitive), deassertions of this pin
                                                                 after [PIN_XOR] will clear GPIO_INTR()[INTR].

                                                                 This does NOT control if interrupts are enabled towards the MSI-X vector,
                                                                 for that see GPIO_INTR()[INTR_ENA]. */
        uint64_t int_type              : 1;  /**< [  3:  3](R/W) Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter as well XOR inverter. */
        uint64_t fil_cnt               : 4;  /**< [  7:  4](R/W) Filter count. Specifies the number of consecutive samples (FIL_CNT+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter are XOR inverter are also appliable to GPIO input muxing signals and interrupts. */
        uint64_t fil_sel               : 4;  /**< [ 11:  8](R/W) Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter are XOR inverter are also appliable to GPIO input muxing signals and interrupts. */
        uint64_t tx_od                 : 1;  /**< [ 12: 12](R/W) GPIO output open-drain conversion. This function is after  PIN_SEL mux
                                                                 and [PIN_XOR] invertor.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output.  With both TX_OD and PIN_XOR set, a transmit
                                                                 of 1 will tristate the pin output driver to archive open-drain function. */
        uint64_t reserved_13_15        : 3;
        uint64_t pin_sel               : 8;  /**< [ 23: 16](R/W) Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
        uint64_t reserved_24_63        : 40;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_bit_cfgx_s cn; */
} bdk_gpio_bit_cfgx_t;

static inline uint64_t BDK_GPIO_BIT_CFGX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_BIT_CFGX(unsigned long a)
{
    if (a<=50)
        return 0x803000000400ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("GPIO_BIT_CFGX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_BIT_CFGX(a) bdk_gpio_bit_cfgx_t
#define bustype_BDK_GPIO_BIT_CFGX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_BIT_CFGX(a) "GPIO_BIT_CFGX"
#define busnum_BDK_GPIO_BIT_CFGX(a) (a)
#define arguments_BDK_GPIO_BIT_CFGX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_clk_gen#
 *
 * GPIO Clock Generator Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_clk_genx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
#else /* Word 0 - Little Endian */
        uint64_t n                     : 32; /**< [ 31:  0](R/W) Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_clk_genx_s cn; */
} bdk_gpio_clk_genx_t;

static inline uint64_t BDK_GPIO_CLK_GENX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_CLK_GENX(unsigned long a)
{
    if (a<=3)
        return 0x803000000040ll + 8ll * ((a) & 0x3);
    __bdk_csr_fatal("GPIO_CLK_GENX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_CLK_GENX(a) bdk_gpio_clk_genx_t
#define bustype_BDK_GPIO_CLK_GENX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_CLK_GENX(a) "GPIO_CLK_GENX"
#define busnum_BDK_GPIO_CLK_GENX(a) (a)
#define arguments_BDK_GPIO_CLK_GENX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_clk_synce#
 *
 * GPIO Clock SyncE Registers
 * A QLM can be configured as a clock source. The GPIO block can support up to two unique clocks
 * to send out any GPIO pin as configured by GPIO_BIT_CFG()[SYNCE_SEL]. The clock can be
 * divided by 20, 40, 80 or 160 of the selected RX lane clock.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_clk_syncex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which QLM(0..7) to select from. */
        uint64_t reserved_4_7          : 4;
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock divider setting relative to QLM SerDes CLOCK_SYNCE. The maximum
                                                                 supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Selects which RX lane clock from QLMx to use as the GPIO internal QLMx clock. */
#else /* Word 0 - Little Endian */
        uint64_t lane_sel              : 2;  /**< [  1:  0](R/W) Selects which RX lane clock from QLMx to use as the GPIO internal QLMx clock. */
        uint64_t div                   : 2;  /**< [  3:  2](R/W) GPIO internal clock divider setting relative to QLM SerDes CLOCK_SYNCE. The maximum
                                                                 supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
        uint64_t reserved_4_7          : 4;
        uint64_t qlm_sel               : 4;  /**< [ 11:  8](R/W) Selects which QLM(0..7) to select from. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_clk_syncex_s cn; */
} bdk_gpio_clk_syncex_t;

static inline uint64_t BDK_GPIO_CLK_SYNCEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_CLK_SYNCEX(unsigned long a)
{
    if (a<=1)
        return 0x803000000060ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("GPIO_CLK_SYNCEX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_CLK_SYNCEX(a) bdk_gpio_clk_syncex_t
#define bustype_BDK_GPIO_CLK_SYNCEX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_CLK_SYNCEX(a) "GPIO_CLK_SYNCEX"
#define busnum_BDK_GPIO_CLK_SYNCEX(a) (a)
#define arguments_BDK_GPIO_CLK_SYNCEX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_comp
 *
 * GPIO Compensation Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_comp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) GPIO bus driver PCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_3_7          : 5;
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) GPIO bus driver NCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
#else /* Word 0 - Little Endian */
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) GPIO bus driver NCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_3_7          : 5;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) GPIO bus driver PCTL. Suggested values:
                                                                 0x4 = 60 ohm.
                                                                 0x6 = 40 ohm.
                                                                 0x7 = 30 ohm. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_comp_s cn; */
} bdk_gpio_comp_t;

#define BDK_GPIO_COMP BDK_GPIO_COMP_FUNC()
static inline uint64_t BDK_GPIO_COMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_COMP_FUNC(void)
{
    return 0x803000000080ll;
}

#define typedef_BDK_GPIO_COMP bdk_gpio_comp_t
#define bustype_BDK_GPIO_COMP BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_COMP "GPIO_COMP"
#define busnum_BDK_GPIO_COMP 0
#define arguments_BDK_GPIO_COMP -1,-1,-1,-1

/**
 * Register (NCB) gpio_intr#
 *
 * GPIO Bit Interrupt Registers
 * Each register provides interrupt information for the corresponding GPIO pin.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_intrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t intr_ena_w1s          : 1;  /**< [  3:  3](R/W1S) GPIO signalled interrupt enable. Write one to set interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t intr_ena_w1c          : 1;  /**< [  2:  2](R/W1C) GPIO signalled interrupt enable. Write one to clear interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t intr_w1s              : 1;  /**< [  1:  1](R/W1S/H) GPIO signalled interrupt. If interrupts are edge sensitive, write one to set, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state. */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) GPIO signalled interrupt. If interrupts are edge sensitive, write one to clear, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state.
                                                                 An interrupt set event is sent when [INTR_ENA_W1S] reads as set. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 1;  /**< [  0:  0](R/W1C/H) GPIO signalled interrupt. If interrupts are edge sensitive, write one to clear, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state.
                                                                 An interrupt set event is sent when [INTR_ENA_W1S] reads as set. */
        uint64_t intr_w1s              : 1;  /**< [  1:  1](R/W1S/H) GPIO signalled interrupt. If interrupts are edge sensitive, write one to set, otherwise
                                                                 will clear automatically when GPIO pin de-asserts.
                                                                 [INTR_W1S] and [INTR] both read the interrupt state. */
        uint64_t intr_ena_w1c          : 1;  /**< [  2:  2](R/W1C) GPIO signalled interrupt enable. Write one to clear interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t intr_ena_w1s          : 1;  /**< [  3:  3](R/W1S) GPIO signalled interrupt enable. Write one to set interrupt enable.
                                                                 [INTR_ENA_W1S] and [INTR_ENA_W1C] both read the interrupt enable state. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_intrx_s cn; */
} bdk_gpio_intrx_t;

static inline uint64_t BDK_GPIO_INTRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_INTRX(unsigned long a)
{
    if (a<=50)
        return 0x803000000800ll + 8ll * ((a) & 0x3f);
    __bdk_csr_fatal("GPIO_INTRX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_INTRX(a) bdk_gpio_intrx_t
#define bustype_BDK_GPIO_INTRX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_INTRX(a) "GPIO_INTRX"
#define busnum_BDK_GPIO_INTRX(a) (a)
#define arguments_BDK_GPIO_INTRX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#
 *
 * GPIO Bit Multicast Interrupt Registers
 * Each register provides interrupt multicasting for GPIO(4..7).
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_mc_intrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_mc_intrx_s cn; */
} bdk_gpio_mc_intrx_t;

static inline uint64_t BDK_GPIO_MC_INTRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("GPIO_MC_INTRX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MC_INTRX(a) bdk_gpio_mc_intrx_t
#define bustype_BDK_GPIO_MC_INTRX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MC_INTRX(a) "GPIO_MC_INTRX"
#define busnum_BDK_GPIO_MC_INTRX(a) (a)
#define arguments_BDK_GPIO_MC_INTRX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#_ena_w1c
 *
 * GPIO Bit Multicast Interrupt Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_mc_intrx_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1C/H) Reads or clears enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_mc_intrx_ena_w1c_s cn; */
} bdk_gpio_mc_intrx_ena_w1c_t;

static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1C(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001200ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("GPIO_MC_INTRX_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MC_INTRX_ENA_W1C(a) bdk_gpio_mc_intrx_ena_w1c_t
#define bustype_BDK_GPIO_MC_INTRX_ENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MC_INTRX_ENA_W1C(a) "GPIO_MC_INTRX_ENA_W1C"
#define busnum_BDK_GPIO_MC_INTRX_ENA_W1C(a) (a)
#define arguments_BDK_GPIO_MC_INTRX_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#_ena_w1s
 *
 * GPIO Bit Multicast Interrupt Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_mc_intrx_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets enable for GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_mc_intrx_ena_w1s_s cn; */
} bdk_gpio_mc_intrx_ena_w1s_t;

static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1S(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001300ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("GPIO_MC_INTRX_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MC_INTRX_ENA_W1S(a) bdk_gpio_mc_intrx_ena_w1s_t
#define bustype_BDK_GPIO_MC_INTRX_ENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MC_INTRX_ENA_W1S(a) "GPIO_MC_INTRX_ENA_W1S"
#define busnum_BDK_GPIO_MC_INTRX_ENA_W1S(a) (a)
#define arguments_BDK_GPIO_MC_INTRX_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_mc_intr#_w1s
 *
 * GPIO Bit Multicast Interrupt W1S Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_mc_intrx_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
#else /* Word 0 - Little Endian */
        uint64_t intr                  : 48; /**< [ 47:  0](R/W1S/H) Reads or sets GPIO_MC_INTR(4..7)[INTR]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_mc_intrx_w1s_s cn; */
} bdk_gpio_mc_intrx_w1s_t;

static inline uint64_t BDK_GPIO_MC_INTRX_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX_W1S(unsigned long a)
{
    if ((a>=4)&&(a<=7))
        return 0x803000001100ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("GPIO_MC_INTRX_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MC_INTRX_W1S(a) bdk_gpio_mc_intrx_w1s_t
#define bustype_BDK_GPIO_MC_INTRX_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MC_INTRX_W1S(a) "GPIO_MC_INTRX_W1S"
#define busnum_BDK_GPIO_MC_INTRX_W1S(a) (a)
#define arguments_BDK_GPIO_MC_INTRX_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_msix_pba#
 *
 * GPIO MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the GPIO_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated GPIO_MSIX_VEC()_CTL, enumerated by
                                                                 GPIO_INT_VEC_E. Bits
                                                                 that have no associated GPIO_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated GPIO_MSIX_VEC()_CTL, enumerated by
                                                                 GPIO_INT_VEC_E. Bits
                                                                 that have no associated GPIO_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_msix_pbax_s cn; */
} bdk_gpio_msix_pbax_t;

static inline uint64_t BDK_GPIO_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MSIX_PBAX(unsigned long a)
{
    if (a<=2)
        return 0x803000ff0000ll + 8ll * ((a) & 0x3);
    __bdk_csr_fatal("GPIO_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MSIX_PBAX(a) bdk_gpio_msix_pbax_t
#define bustype_BDK_GPIO_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MSIX_PBAX(a) "GPIO_MSIX_PBAX"
#define busnum_BDK_GPIO_MSIX_PBAX(a) (a)
#define arguments_BDK_GPIO_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_msix_vec#_addr
 *
 * GPIO MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the GPIO_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_msix_vecx_addr_s cn; */
} bdk_gpio_msix_vecx_addr_t;

static inline uint64_t BDK_GPIO_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MSIX_VECX_ADDR(unsigned long a)
{
    if (a<=149)
        return 0x803000f00000ll + 0x10ll * ((a) & 0xff);
    __bdk_csr_fatal("GPIO_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MSIX_VECX_ADDR(a) bdk_gpio_msix_vecx_addr_t
#define bustype_BDK_GPIO_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MSIX_VECX_ADDR(a) "GPIO_MSIX_VECX_ADDR"
#define busnum_BDK_GPIO_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_GPIO_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_msix_vec#_ctl
 *
 * GPIO MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the GPIO_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_msix_vecx_ctl_s
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
    /* struct bdk_gpio_msix_vecx_ctl_s cn; */
} bdk_gpio_msix_vecx_ctl_t;

static inline uint64_t BDK_GPIO_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MSIX_VECX_CTL(unsigned long a)
{
    if (a<=149)
        return 0x803000f00008ll + 0x10ll * ((a) & 0xff);
    __bdk_csr_fatal("GPIO_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_GPIO_MSIX_VECX_CTL(a) bdk_gpio_msix_vecx_ctl_t
#define bustype_BDK_GPIO_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MSIX_VECX_CTL(a) "GPIO_MSIX_VECX_CTL"
#define busnum_BDK_GPIO_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_GPIO_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) gpio_multi_cast
 *
 * GPIO Multicast Register
 * This register enables multicast GPIO interrupts.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_multi_cast_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t en                    : 1;  /**< [  0:  0](R/W) Enable GPIO interrupt multicast mode. When EN is set, GPIO<7:4> functions in multicast
                                                                 mode allowing these four GPIOs to interrupt multiple cores. Multicast functionality allows
                                                                 the GPIO to exist as per-core interrupts as opposed to a global interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t en                    : 1;  /**< [  0:  0](R/W) Enable GPIO interrupt multicast mode. When EN is set, GPIO<7:4> functions in multicast
                                                                 mode allowing these four GPIOs to interrupt multiple cores. Multicast functionality allows
                                                                 the GPIO to exist as per-core interrupts as opposed to a global interrupt. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_multi_cast_s cn; */
} bdk_gpio_multi_cast_t;

#define BDK_GPIO_MULTI_CAST BDK_GPIO_MULTI_CAST_FUNC()
static inline uint64_t BDK_GPIO_MULTI_CAST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MULTI_CAST_FUNC(void)
{
    return 0x803000000018ll;
}

#define typedef_BDK_GPIO_MULTI_CAST bdk_gpio_multi_cast_t
#define bustype_BDK_GPIO_MULTI_CAST BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_MULTI_CAST "GPIO_MULTI_CAST"
#define busnum_BDK_GPIO_MULTI_CAST 0
#define arguments_BDK_GPIO_MULTI_CAST -1,-1,-1,-1

/**
 * Register (NCB) gpio_ocla_exten_trig
 *
 * GPIO OCLA External Trigger Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_ocla_exten_trig_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t m_trig                : 1;  /**< [  0:  0](R/W) Manual Trigger.  This external trigger can also use the GPIO(0..50) input pin, when
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER.
                                                                 This signal report to the OCLA coprocessor for GPIO-based triggering. When external
                                                                 trigger and manual trigger
                                                                 active at the same time, an ORed version of trigger is used. */
#else /* Word 0 - Little Endian */
        uint64_t m_trig                : 1;  /**< [  0:  0](R/W) Manual Trigger.  This external trigger can also use the GPIO(0..50) input pin, when
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER.
                                                                 This signal report to the OCLA coprocessor for GPIO-based triggering. When external
                                                                 trigger and manual trigger
                                                                 active at the same time, an ORed version of trigger is used. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_ocla_exten_trig_s cn; */
} bdk_gpio_ocla_exten_trig_t;

#define BDK_GPIO_OCLA_EXTEN_TRIG BDK_GPIO_OCLA_EXTEN_TRIG_FUNC()
static inline uint64_t BDK_GPIO_OCLA_EXTEN_TRIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_OCLA_EXTEN_TRIG_FUNC(void)
{
    return 0x803000000020ll;
}

#define typedef_BDK_GPIO_OCLA_EXTEN_TRIG bdk_gpio_ocla_exten_trig_t
#define bustype_BDK_GPIO_OCLA_EXTEN_TRIG BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_OCLA_EXTEN_TRIG "GPIO_OCLA_EXTEN_TRIG"
#define busnum_BDK_GPIO_OCLA_EXTEN_TRIG 0
#define arguments_BDK_GPIO_OCLA_EXTEN_TRIG -1,-1,-1,-1

/**
 * Register (NCB) gpio_rx_dat
 *
 * GPIO Receive Data Register
 * This register contains the state of the GPIO pins.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_rx_dat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t dat                   : 51; /**< [ 50:  0](RO/H) GPIO read data. */
#else /* Word 0 - Little Endian */
        uint64_t dat                   : 51; /**< [ 50:  0](RO/H) GPIO read data. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_rx_dat_s cn; */
} bdk_gpio_rx_dat_t;

#define BDK_GPIO_RX_DAT BDK_GPIO_RX_DAT_FUNC()
static inline uint64_t BDK_GPIO_RX_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_RX_DAT_FUNC(void)
{
    return 0x803000000000ll;
}

#define typedef_BDK_GPIO_RX_DAT bdk_gpio_rx_dat_t
#define bustype_BDK_GPIO_RX_DAT BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_RX_DAT "GPIO_RX_DAT"
#define busnum_BDK_GPIO_RX_DAT 0
#define arguments_BDK_GPIO_RX_DAT -1,-1,-1,-1

/**
 * Register (NCB) gpio_strap
 *
 * GPIO Strap Value Register
 * This register contains GPIO strap data captured at the rising edge of DC_OK.
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_strap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t strap                 : 51; /**< [ 50:  0](RO/H) GPIO strap data. */
#else /* Word 0 - Little Endian */
        uint64_t strap                 : 51; /**< [ 50:  0](RO/H) GPIO strap data. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_strap_s cn; */
} bdk_gpio_strap_t;

#define BDK_GPIO_STRAP BDK_GPIO_STRAP_FUNC()
static inline uint64_t BDK_GPIO_STRAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_STRAP_FUNC(void)
{
    return 0x803000000028ll;
}

#define typedef_BDK_GPIO_STRAP bdk_gpio_strap_t
#define bustype_BDK_GPIO_STRAP BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_STRAP "GPIO_STRAP"
#define busnum_BDK_GPIO_STRAP 0
#define arguments_BDK_GPIO_STRAP -1,-1,-1,-1

/**
 * Register (NCB) gpio_tx_clr
 *
 * GPIO Transmit Clear Mask Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_tx_clr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t clr                   : 51; /**< [ 50:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t clr                   : 51; /**< [ 50:  0](R/W1C/H) Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX_DAT storage. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_tx_clr_s cn; */
} bdk_gpio_tx_clr_t;

#define BDK_GPIO_TX_CLR BDK_GPIO_TX_CLR_FUNC()
static inline uint64_t BDK_GPIO_TX_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_TX_CLR_FUNC(void)
{
    return 0x803000000010ll;
}

#define typedef_BDK_GPIO_TX_CLR bdk_gpio_tx_clr_t
#define bustype_BDK_GPIO_TX_CLR BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_TX_CLR "GPIO_TX_CLR"
#define busnum_BDK_GPIO_TX_CLR 0
#define arguments_BDK_GPIO_TX_CLR -1,-1,-1,-1

/**
 * Register (NCB) gpio_tx_set
 *
 * GPIO Transmit Set Mask Register
 */
typedef union
{
    uint64_t u;
    struct bdk_gpio_tx_set_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t set                   : 51; /**< [ 50:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX_DAT storage. */
#else /* Word 0 - Little Endian */
        uint64_t set                   : 51; /**< [ 50:  0](R/W1S/H) Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX_DAT storage. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_gpio_tx_set_s cn; */
} bdk_gpio_tx_set_t;

#define BDK_GPIO_TX_SET BDK_GPIO_TX_SET_FUNC()
static inline uint64_t BDK_GPIO_TX_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_TX_SET_FUNC(void)
{
    return 0x803000000008ll;
}

#define typedef_BDK_GPIO_TX_SET bdk_gpio_tx_set_t
#define bustype_BDK_GPIO_TX_SET BDK_CSR_TYPE_NCB
#define basename_BDK_GPIO_TX_SET "GPIO_TX_SET"
#define busnum_BDK_GPIO_TX_SET 0
#define arguments_BDK_GPIO_TX_SET -1,-1,-1,-1

#endif /* __BDK_CSRS_GPIO_H__ */
