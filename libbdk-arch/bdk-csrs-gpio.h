#ifndef __BDK_CSRS_GPIO__
#define __BDK_CSRS_GPIO__
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
 * Cavium GPIO.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration GPIO_INT_VEC_E
 *
 * GPIO MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum gpio_int_vec_e {
	GPIO_INT_VEC_E_INTR_PIN0 = 0x30,
	GPIO_INT_VEC_E_INTR_PIN0_CLEAR = 0x31,
	GPIO_INT_VEC_E_INTR_PIN1 = 0x32,
	GPIO_INT_VEC_E_INTR_PIN10 = 0x44,
	GPIO_INT_VEC_E_INTR_PIN10_CLEAR = 0x45,
	GPIO_INT_VEC_E_INTR_PIN11 = 0x46,
	GPIO_INT_VEC_E_INTR_PIN11_CLEAR = 0x47,
	GPIO_INT_VEC_E_INTR_PIN12 = 0x48,
	GPIO_INT_VEC_E_INTR_PIN12_CLEAR = 0x49,
	GPIO_INT_VEC_E_INTR_PIN13 = 0x4a,
	GPIO_INT_VEC_E_INTR_PIN13_CLEAR = 0x4b,
	GPIO_INT_VEC_E_INTR_PIN14 = 0x4c,
	GPIO_INT_VEC_E_INTR_PIN14_CLEAR = 0x4d,
	GPIO_INT_VEC_E_INTR_PIN15 = 0x4e,
	GPIO_INT_VEC_E_INTR_PIN15_CLEAR = 0x4f,
	GPIO_INT_VEC_E_INTR_PIN16 = 0x50,
	GPIO_INT_VEC_E_INTR_PIN16_CLEAR = 0x51,
	GPIO_INT_VEC_E_INTR_PIN17 = 0x52,
	GPIO_INT_VEC_E_INTR_PIN17_CLEAR = 0x53,
	GPIO_INT_VEC_E_INTR_PIN18 = 0x54,
	GPIO_INT_VEC_E_INTR_PIN18_CLEAR = 0x55,
	GPIO_INT_VEC_E_INTR_PIN19 = 0x56,
	GPIO_INT_VEC_E_INTR_PIN19_CLEAR = 0x57,
	GPIO_INT_VEC_E_INTR_PIN1_CLEAR = 0x33,
	GPIO_INT_VEC_E_INTR_PIN2 = 0x34,
	GPIO_INT_VEC_E_INTR_PIN20 = 0x58,
	GPIO_INT_VEC_E_INTR_PIN20_CLEAR = 0x59,
	GPIO_INT_VEC_E_INTR_PIN21 = 0x5a,
	GPIO_INT_VEC_E_INTR_PIN21_CLEAR = 0x5b,
	GPIO_INT_VEC_E_INTR_PIN22 = 0x5c,
	GPIO_INT_VEC_E_INTR_PIN22_CLEAR = 0x5d,
	GPIO_INT_VEC_E_INTR_PIN23 = 0x5e,
	GPIO_INT_VEC_E_INTR_PIN23_CLEAR = 0x5f,
	GPIO_INT_VEC_E_INTR_PIN24 = 0x60,
	GPIO_INT_VEC_E_INTR_PIN24_CLEAR = 0x61,
	GPIO_INT_VEC_E_INTR_PIN25 = 0x62,
	GPIO_INT_VEC_E_INTR_PIN25_CLEAR = 0x63,
	GPIO_INT_VEC_E_INTR_PIN26 = 0x64,
	GPIO_INT_VEC_E_INTR_PIN26_CLEAR = 0x65,
	GPIO_INT_VEC_E_INTR_PIN27 = 0x66,
	GPIO_INT_VEC_E_INTR_PIN27_CLEAR = 0x67,
	GPIO_INT_VEC_E_INTR_PIN28 = 0x68,
	GPIO_INT_VEC_E_INTR_PIN28_CLEAR = 0x69,
	GPIO_INT_VEC_E_INTR_PIN29 = 0x6a,
	GPIO_INT_VEC_E_INTR_PIN29_CLEAR = 0x6b,
	GPIO_INT_VEC_E_INTR_PIN2_CLEAR = 0x35,
	GPIO_INT_VEC_E_INTR_PIN3 = 0x36,
	GPIO_INT_VEC_E_INTR_PIN30 = 0x6c,
	GPIO_INT_VEC_E_INTR_PIN30_CLEAR = 0x6d,
	GPIO_INT_VEC_E_INTR_PIN31 = 0x6e,
	GPIO_INT_VEC_E_INTR_PIN31_CLEAR = 0x6f,
	GPIO_INT_VEC_E_INTR_PIN32 = 0x70,
	GPIO_INT_VEC_E_INTR_PIN32_CLEAR = 0x71,
	GPIO_INT_VEC_E_INTR_PIN33 = 0x72,
	GPIO_INT_VEC_E_INTR_PIN33_CLEAR = 0x73,
	GPIO_INT_VEC_E_INTR_PIN34 = 0x74,
	GPIO_INT_VEC_E_INTR_PIN34_CLEAR = 0x75,
	GPIO_INT_VEC_E_INTR_PIN35 = 0x76,
	GPIO_INT_VEC_E_INTR_PIN35_CLEAR = 0x77,
	GPIO_INT_VEC_E_INTR_PIN36 = 0x78,
	GPIO_INT_VEC_E_INTR_PIN36_CLEAR = 0x79,
	GPIO_INT_VEC_E_INTR_PIN37 = 0x7a,
	GPIO_INT_VEC_E_INTR_PIN37_CLEAR = 0x7b,
	GPIO_INT_VEC_E_INTR_PIN38 = 0x7c,
	GPIO_INT_VEC_E_INTR_PIN38_CLEAR = 0x7d,
	GPIO_INT_VEC_E_INTR_PIN39 = 0x7e,
	GPIO_INT_VEC_E_INTR_PIN39_CLEAR = 0x7f,
	GPIO_INT_VEC_E_INTR_PIN3_CLEAR = 0x37,
	GPIO_INT_VEC_E_INTR_PIN4 = 0x38,
	GPIO_INT_VEC_E_INTR_PIN40 = 0x80,
	GPIO_INT_VEC_E_INTR_PIN40_CLEAR = 0x81,
	GPIO_INT_VEC_E_INTR_PIN41 = 0x82,
	GPIO_INT_VEC_E_INTR_PIN41_CLEAR = 0x83,
	GPIO_INT_VEC_E_INTR_PIN42 = 0x84,
	GPIO_INT_VEC_E_INTR_PIN42_CLEAR = 0x85,
	GPIO_INT_VEC_E_INTR_PIN43 = 0x86,
	GPIO_INT_VEC_E_INTR_PIN43_CLEAR = 0x87,
	GPIO_INT_VEC_E_INTR_PIN44 = 0x88,
	GPIO_INT_VEC_E_INTR_PIN44_CLEAR = 0x89,
	GPIO_INT_VEC_E_INTR_PIN45 = 0x8a,
	GPIO_INT_VEC_E_INTR_PIN45_CLEAR = 0x8b,
	GPIO_INT_VEC_E_INTR_PIN46 = 0x8c,
	GPIO_INT_VEC_E_INTR_PIN46_CLEAR = 0x8d,
	GPIO_INT_VEC_E_INTR_PIN47 = 0x8e,
	GPIO_INT_VEC_E_INTR_PIN47_CLEAR = 0x8f,
	GPIO_INT_VEC_E_INTR_PIN48 = 0x90,
	GPIO_INT_VEC_E_INTR_PIN48_CLEAR = 0x91,
	GPIO_INT_VEC_E_INTR_PIN49 = 0x92,
	GPIO_INT_VEC_E_INTR_PIN49_CLEAR = 0x93,
	GPIO_INT_VEC_E_INTR_PIN4_CLEAR = 0x39,
	GPIO_INT_VEC_E_INTR_PIN5 = 0x3a,
	GPIO_INT_VEC_E_INTR_PIN50 = 0x94,
	GPIO_INT_VEC_E_INTR_PIN50_CLEAR = 0x95,
	GPIO_INT_VEC_E_INTR_PIN5_CLEAR = 0x3b,
	GPIO_INT_VEC_E_INTR_PIN6 = 0x3c,
	GPIO_INT_VEC_E_INTR_PIN6_CLEAR = 0x3d,
	GPIO_INT_VEC_E_INTR_PIN7 = 0x3e,
	GPIO_INT_VEC_E_INTR_PIN7_CLEAR = 0x3f,
	GPIO_INT_VEC_E_INTR_PIN8 = 0x40,
	GPIO_INT_VEC_E_INTR_PIN8_CLEAR = 0x41,
	GPIO_INT_VEC_E_INTR_PIN9 = 0x42,
	GPIO_INT_VEC_E_INTR_PIN9_CLEAR = 0x43,
	GPIO_INT_VEC_E_MC_INTR_PP0 = 0x0,
	GPIO_INT_VEC_E_MC_INTR_PP1 = 0x1,
	GPIO_INT_VEC_E_MC_INTR_PP10 = 0xa,
	GPIO_INT_VEC_E_MC_INTR_PP11 = 0xb,
	GPIO_INT_VEC_E_MC_INTR_PP12 = 0xc,
	GPIO_INT_VEC_E_MC_INTR_PP13 = 0xd,
	GPIO_INT_VEC_E_MC_INTR_PP14 = 0xe,
	GPIO_INT_VEC_E_MC_INTR_PP15 = 0xf,
	GPIO_INT_VEC_E_MC_INTR_PP16 = 0x10,
	GPIO_INT_VEC_E_MC_INTR_PP17 = 0x11,
	GPIO_INT_VEC_E_MC_INTR_PP18 = 0x12,
	GPIO_INT_VEC_E_MC_INTR_PP19 = 0x13,
	GPIO_INT_VEC_E_MC_INTR_PP2 = 0x2,
	GPIO_INT_VEC_E_MC_INTR_PP20 = 0x14,
	GPIO_INT_VEC_E_MC_INTR_PP21 = 0x15,
	GPIO_INT_VEC_E_MC_INTR_PP22 = 0x16,
	GPIO_INT_VEC_E_MC_INTR_PP23 = 0x17,
	GPIO_INT_VEC_E_MC_INTR_PP24 = 0x18,
	GPIO_INT_VEC_E_MC_INTR_PP25 = 0x19,
	GPIO_INT_VEC_E_MC_INTR_PP26 = 0x1a,
	GPIO_INT_VEC_E_MC_INTR_PP27 = 0x1b,
	GPIO_INT_VEC_E_MC_INTR_PP28 = 0x1c,
	GPIO_INT_VEC_E_MC_INTR_PP29 = 0x1d,
	GPIO_INT_VEC_E_MC_INTR_PP3 = 0x3,
	GPIO_INT_VEC_E_MC_INTR_PP30 = 0x1e,
	GPIO_INT_VEC_E_MC_INTR_PP31 = 0x1f,
	GPIO_INT_VEC_E_MC_INTR_PP32 = 0x20,
	GPIO_INT_VEC_E_MC_INTR_PP33 = 0x21,
	GPIO_INT_VEC_E_MC_INTR_PP34 = 0x22,
	GPIO_INT_VEC_E_MC_INTR_PP35 = 0x23,
	GPIO_INT_VEC_E_MC_INTR_PP36 = 0x24,
	GPIO_INT_VEC_E_MC_INTR_PP37 = 0x25,
	GPIO_INT_VEC_E_MC_INTR_PP38 = 0x26,
	GPIO_INT_VEC_E_MC_INTR_PP39 = 0x27,
	GPIO_INT_VEC_E_MC_INTR_PP4 = 0x4,
	GPIO_INT_VEC_E_MC_INTR_PP40 = 0x28,
	GPIO_INT_VEC_E_MC_INTR_PP41 = 0x29,
	GPIO_INT_VEC_E_MC_INTR_PP42 = 0x2a,
	GPIO_INT_VEC_E_MC_INTR_PP43 = 0x2b,
	GPIO_INT_VEC_E_MC_INTR_PP44 = 0x2c,
	GPIO_INT_VEC_E_MC_INTR_PP45 = 0x2d,
	GPIO_INT_VEC_E_MC_INTR_PP46 = 0x2e,
	GPIO_INT_VEC_E_MC_INTR_PP47 = 0x2f,
	GPIO_INT_VEC_E_MC_INTR_PP5 = 0x5,
	GPIO_INT_VEC_E_MC_INTR_PP6 = 0x6,
	GPIO_INT_VEC_E_MC_INTR_PP7 = 0x7,
	GPIO_INT_VEC_E_MC_INTR_PP8 = 0x8,
	GPIO_INT_VEC_E_MC_INTR_PP9 = 0x9,
	GPIO_INT_VEC_E_ENUM_LAST = 0x96,
};

/**
 * Enumeration GPIO_PIN_SEL_E
 *
 * GPIO Output Select Enumeration
 * Enumerates the GPIO pin function selections for GPIO_BIT_CFG()[PIN_SEL].
 * The GPIO pins can be configured as either input or output depending on selected function's
 * definition.
 * When GPIO pin is used as input pin, GPIO input is reported to selected function as well as
 * GPIO_RX_DAT.
 */
enum gpio_pin_sel_e {
	GPIO_PIN_SEL_E_GPIO_CLK0 = 0x5,
	GPIO_PIN_SEL_E_GPIO_CLK1 = 0x6,
	GPIO_PIN_SEL_E_GPIO_CLK2 = 0x7,
	GPIO_PIN_SEL_E_GPIO_CLK3 = 0x8,
	GPIO_PIN_SEL_E_GPIO_CLK_SYNCE0 = 0x3,
	GPIO_PIN_SEL_E_GPIO_CLK_SYNCE1 = 0x4,
	GPIO_PIN_SEL_E_GPIO_PTP_CKOUT = 0x1,
	GPIO_PIN_SEL_E_GPIO_PTP_PPS = 0x2,
	GPIO_PIN_SEL_E_GPIO_SW = 0x0,
	GPIO_PIN_SEL_E_LMC0_ECC = 0x70,
	GPIO_PIN_SEL_E_LMC1_ECC = 0x71,
	GPIO_PIN_SEL_E_LMC2_ECC = 0x72,
	GPIO_PIN_SEL_E_LMC3_ECC = 0x73,
	GPIO_PIN_SEL_E_MCD0_IN = 0xb0,
	GPIO_PIN_SEL_E_MCD0_OUT = 0x14,
	GPIO_PIN_SEL_E_MCD1_IN = 0xb1,
	GPIO_PIN_SEL_E_MCD1_OUT = 0x15,
	GPIO_PIN_SEL_E_MCD2_IN = 0xb2,
	GPIO_PIN_SEL_E_MCD2_OUT = 0x16,
	GPIO_PIN_SEL_E_OCLA_EXT_TRIGGER = 0x8a,
	GPIO_PIN_SEL_E_SATA0_ACT_LED = 0x60,
	GPIO_PIN_SEL_E_SATA0_CP_DET = 0x90,
	GPIO_PIN_SEL_E_SATA0_CP_POD = 0x50,
	GPIO_PIN_SEL_E_SATA0_MP_SWITCH = 0xa0,
	GPIO_PIN_SEL_E_SATA10_ACT_LED = 0x6a,
	GPIO_PIN_SEL_E_SATA10_CP_DET = 0x9a,
	GPIO_PIN_SEL_E_SATA10_CP_POD = 0x5a,
	GPIO_PIN_SEL_E_SATA10_MP_SWITCH = 0xaa,
	GPIO_PIN_SEL_E_SATA11_ACT_LED = 0x6b,
	GPIO_PIN_SEL_E_SATA11_CP_DET = 0x9b,
	GPIO_PIN_SEL_E_SATA11_CP_POD = 0x5b,
	GPIO_PIN_SEL_E_SATA11_MP_SWITCH = 0xab,
	GPIO_PIN_SEL_E_SATA12_ACT_LED = 0x6c,
	GPIO_PIN_SEL_E_SATA12_CP_DET = 0x9c,
	GPIO_PIN_SEL_E_SATA12_CP_POD = 0x5c,
	GPIO_PIN_SEL_E_SATA12_MP_SWITCH = 0xac,
	GPIO_PIN_SEL_E_SATA13_ACT_LED = 0x6d,
	GPIO_PIN_SEL_E_SATA13_CP_DET = 0x9d,
	GPIO_PIN_SEL_E_SATA13_CP_POD = 0x5d,
	GPIO_PIN_SEL_E_SATA13_MP_SWITCH = 0xad,
	GPIO_PIN_SEL_E_SATA14_ACT_LED = 0x6e,
	GPIO_PIN_SEL_E_SATA14_CP_DET = 0x9e,
	GPIO_PIN_SEL_E_SATA14_CP_POD = 0x5e,
	GPIO_PIN_SEL_E_SATA14_MP_SWITCH = 0xae,
	GPIO_PIN_SEL_E_SATA15_ACT_LED = 0x6f,
	GPIO_PIN_SEL_E_SATA15_CP_DET = 0x9f,
	GPIO_PIN_SEL_E_SATA15_CP_POD = 0x5f,
	GPIO_PIN_SEL_E_SATA15_MP_SWITCH = 0xaf,
	GPIO_PIN_SEL_E_SATA1_ACT_LED = 0x61,
	GPIO_PIN_SEL_E_SATA1_CP_DET = 0x91,
	GPIO_PIN_SEL_E_SATA1_CP_POD = 0x51,
	GPIO_PIN_SEL_E_SATA1_MP_SWITCH = 0xa1,
	GPIO_PIN_SEL_E_SATA2_ACT_LED = 0x62,
	GPIO_PIN_SEL_E_SATA2_CP_DET = 0x92,
	GPIO_PIN_SEL_E_SATA2_CP_POD = 0x52,
	GPIO_PIN_SEL_E_SATA2_MP_SWITCH = 0xa2,
	GPIO_PIN_SEL_E_SATA3_ACT_LED = 0x63,
	GPIO_PIN_SEL_E_SATA3_CP_DET = 0x93,
	GPIO_PIN_SEL_E_SATA3_CP_POD = 0x53,
	GPIO_PIN_SEL_E_SATA3_MP_SWITCH = 0xa3,
	GPIO_PIN_SEL_E_SATA4_ACT_LED = 0x64,
	GPIO_PIN_SEL_E_SATA4_CP_DET = 0x94,
	GPIO_PIN_SEL_E_SATA4_CP_POD = 0x54,
	GPIO_PIN_SEL_E_SATA4_MP_SWITCH = 0xa4,
	GPIO_PIN_SEL_E_SATA5_ACT_LED = 0x65,
	GPIO_PIN_SEL_E_SATA5_CP_DET = 0x95,
	GPIO_PIN_SEL_E_SATA5_CP_POD = 0x55,
	GPIO_PIN_SEL_E_SATA5_MP_SWITCH = 0xa5,
	GPIO_PIN_SEL_E_SATA6_ACT_LED = 0x66,
	GPIO_PIN_SEL_E_SATA6_CP_DET = 0x96,
	GPIO_PIN_SEL_E_SATA6_CP_POD = 0x56,
	GPIO_PIN_SEL_E_SATA6_MP_SWITCH = 0xa6,
	GPIO_PIN_SEL_E_SATA7_ACT_LED = 0x67,
	GPIO_PIN_SEL_E_SATA7_CP_DET = 0x97,
	GPIO_PIN_SEL_E_SATA7_CP_POD = 0x57,
	GPIO_PIN_SEL_E_SATA7_MP_SWITCH = 0xa7,
	GPIO_PIN_SEL_E_SATA8_ACT_LED = 0x68,
	GPIO_PIN_SEL_E_SATA8_CP_DET = 0x98,
	GPIO_PIN_SEL_E_SATA8_CP_POD = 0x58,
	GPIO_PIN_SEL_E_SATA8_MP_SWITCH = 0xa8,
	GPIO_PIN_SEL_E_SATA9_ACT_LED = 0x69,
	GPIO_PIN_SEL_E_SATA9_CP_DET = 0x99,
	GPIO_PIN_SEL_E_SATA9_CP_POD = 0x59,
	GPIO_PIN_SEL_E_SATA9_MP_SWITCH = 0xa9,
	GPIO_PIN_SEL_E_SATA_LAB_LB = 0x8e,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED0 = 0x20,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED1 = 0x21,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED10 = 0x2a,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED11 = 0x2b,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED12 = 0x2c,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED13 = 0x2d,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED14 = 0x2e,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED15 = 0x2f,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED2 = 0x22,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED3 = 0x23,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED4 = 0x24,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED5 = 0x25,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED6 = 0x26,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED7 = 0x27,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED8 = 0x28,
	GPIO_PIN_SEL_E_SGPIO_ACT_LED9 = 0x29,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED0 = 0x30,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED1 = 0x31,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED10 = 0x3a,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED11 = 0x3b,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED12 = 0x3c,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED13 = 0x3d,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED14 = 0x3e,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED15 = 0x3f,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED2 = 0x32,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED3 = 0x33,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED4 = 0x34,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED5 = 0x35,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED6 = 0x36,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED7 = 0x37,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED8 = 0x38,
	GPIO_PIN_SEL_E_SGPIO_ERR_LED9 = 0x39,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED0 = 0x40,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED1 = 0x41,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED10 = 0x4a,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED11 = 0x4b,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED12 = 0x4c,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED13 = 0x4d,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED14 = 0x4e,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED15 = 0x4f,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED2 = 0x42,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED3 = 0x43,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED4 = 0x44,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED5 = 0x45,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED6 = 0x46,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED7 = 0x47,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED8 = 0x48,
	GPIO_PIN_SEL_E_SGPIO_LOC_LED9 = 0x49,
	GPIO_PIN_SEL_E_SGPIO_SCLOCK = 0xb,
	GPIO_PIN_SEL_E_SGPIO_SDATAIN0 = 0x80,
	GPIO_PIN_SEL_E_SGPIO_SDATAIN1 = 0x81,
	GPIO_PIN_SEL_E_SGPIO_SDATAIN2 = 0x82,
	GPIO_PIN_SEL_E_SGPIO_SDATAIN3 = 0x83,
	GPIO_PIN_SEL_E_SGPIO_SDATAOUT0 = 0x10,
	GPIO_PIN_SEL_E_SGPIO_SDATAOUT1 = 0x11,
	GPIO_PIN_SEL_E_SGPIO_SDATAOUT2 = 0x12,
	GPIO_PIN_SEL_E_SGPIO_SDATAOUT3 = 0x13,
	GPIO_PIN_SEL_E_SGPIO_SLOAD = 0xc,
	GPIO_PIN_SEL_E_SPI_CS2 = 0x1a,
	GPIO_PIN_SEL_E_SPI_CS3 = 0x1b,
	GPIO_PIN_SEL_E_TIMER = 0x8b,
	GPIO_PIN_SEL_E_UART0_DCD_N = 0x84,
	GPIO_PIN_SEL_E_UART0_DSR = 0x88,
	GPIO_PIN_SEL_E_UART0_DTR_N = 0x9,
	GPIO_PIN_SEL_E_UART0_RI = 0x86,
	GPIO_PIN_SEL_E_UART1_DCD_N = 0x85,
	GPIO_PIN_SEL_E_UART1_DSR = 0x89,
	GPIO_PIN_SEL_E_UART1_DTR_N = 0xa,
	GPIO_PIN_SEL_E_UART1_RI = 0x87,
	GPIO_PIN_SEL_E_USB0_OVR_CRNT = 0x8c,
	GPIO_PIN_SEL_E_USB0_VBUS_CTRL = 0x74,
	GPIO_PIN_SEL_E_USB1_OVR_CRNT = 0x8d,
	GPIO_PIN_SEL_E_USB1_VBUS_CTRL = 0x75,
	GPIO_PIN_SEL_E_ENUM_LAST = 0xb3,
};



/**
 * NCB - gpio_bit_cfg#
 *
 * Each register provides configuration information for the corresponding GPIO pin.
 *
 */
typedef union bdk_gpio_bit_cfgx {
	uint64_t u;
	struct bdk_gpio_bit_cfgx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t pin_sel                     : 8;  /**< R/W - Selects which signal is reported to GPIO output, or which signal GPIO input need to
                                                                 connect. Each GPIO pin can be configured either input-only or output-only depending
                                                                 function selected, as enumerated by GPIO_PIN_SEL_E. For GPIO input selects,
                                                                 the GPIO signal used is after glitch filter and XOR inverter (GPIO_BIT_CFG()[PIN_XOR]). */
		uint64_t reserved_13_15              : 3;
		uint64_t tx_od                       : 1;  /**< R/W - GPIO output open-drain conversion. This function is after  PIN_SEL mux
                                                                 and [PIN_XOR] invertor.
                                                                 When set, the pin output will connect to zero, and pin enable
                                                                 will connect to original pin output.  With both TX_OD and PIN_XOR set, a transmit
                                                                 of 1 will tristate the pin output driver to archive open-drain function. */
		uint64_t fil_sel                     : 4;  /**< R/W - Filter select. Global counter bit-select (controls sample rate).
                                                                 Filter are XOR inverter are also appliable to GPIO input muxing signals and interrupts. */
		uint64_t fil_cnt                     : 4;  /**< R/W - Filter count. Specifies the number of consecutive samples (FIL_CNT+1) to change state.
                                                                 Zero to disable the filter.
                                                                 Filter are XOR inverter are also appliable to GPIO input muxing signals and interrupts. */
		uint64_t int_type                    : 1;  /**< R/W - Type of interrupt when pin is an input and [INT_EN] set. When set, rising edge
                                                                 interrupt, else level interrupt. The GPIO signal used to generate interrupt is after
                                                                 the filter as well XOR inverter. */
		uint64_t int_en                      : 1;  /**< R/W - Enable interrupt generated by this pin. */
		uint64_t pin_xor                     : 1;  /**< R/W - GPIO data inversion. When set, inverts the receiveing or transmitting GPIO signal.
                                                                 For GPIO output, this inversion is after all GPIO PIN_SEL muxes. This inversion function
                                                                 is applicable to any GPIO output mux signals, also used to control GPIO_RX_DAT.
                                                                 For GPIO input, this inversion is before the GPIO PIN_SEL muxes, as used to control
                                                                 GPIO interrupts. */
		uint64_t tx_oe                       : 1;  /**< R/W - Transmit output enable. When set to 1, the GPIO pin can be driven as an output pin
                                                                 if GPIO_BIT_CFG()[PIN_SEL] selects GPIO_SW. TX_OE is only used along with GPIO_TX_SET
                                                                 or GPIO_TX_CLR, and TX_OE function is before GPIO_BIT_CFG()[PIN_SEL] mux. */
#else
		uint64_t tx_oe                       : 1;
		uint64_t pin_xor                     : 1;
		uint64_t int_en                      : 1;
		uint64_t int_type                    : 1;
		uint64_t fil_cnt                     : 4;
		uint64_t fil_sel                     : 4;
		uint64_t tx_od                       : 1;
		uint64_t reserved_13_15              : 3;
		uint64_t pin_sel                     : 8;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_gpio_bit_cfgx_s         cn88xx; */
	/* struct bdk_gpio_bit_cfgx_s         cn88xxp1; */
} bdk_gpio_bit_cfgx_t;

static inline uint64_t BDK_GPIO_BIT_CFGX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_BIT_CFGX(unsigned long param1)
{
	if (((param1 <= 50)))
		return 0x0000803000000400ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_GPIO_BIT_CFGX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_BIT_CFGX(...) bdk_gpio_bit_cfgx_t
#define bustype_BDK_GPIO_BIT_CFGX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_BIT_CFGX(p1) (p1)
#define arguments_BDK_GPIO_BIT_CFGX(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_BIT_CFGX(...) "GPIO_BIT_CFGX"


/**
 * NCB - gpio_clk_gen#
 */
typedef union bdk_gpio_clk_genx {
	uint64_t u;
	struct bdk_gpio_clk_genx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t n                           : 32; /**< R/W - Determines the frequency of the GPIO clock generator. N should be less than or equal to
                                                                 2^31-1.
                                                                 The frequency of the GPIO clock generator equals the coprocessor-clock frequency times N
                                                                 divided by 2^32.
                                                                 Writing N = 0x0 stops the clock generator. */
#else
		uint64_t n                           : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_gpio_clk_genx_s         cn88xx; */
	/* struct bdk_gpio_clk_genx_s         cn88xxp1; */
} bdk_gpio_clk_genx_t;

static inline uint64_t BDK_GPIO_CLK_GENX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_CLK_GENX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000803000000040ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_GPIO_CLK_GENX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_CLK_GENX(...) bdk_gpio_clk_genx_t
#define bustype_BDK_GPIO_CLK_GENX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_CLK_GENX(p1) (p1)
#define arguments_BDK_GPIO_CLK_GENX(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_CLK_GENX(...) "GPIO_CLK_GENX"


/**
 * NCB - gpio_clk_synce#
 *
 * A QLM can be configured as a clock source. The GPIO block can support up to two
 * unique clocks to send out any GPIO pin as configured when GPIO_BIT_CFG()[PIN_SEL] =
 * GPIO_PIN_SEL_E::GPIO_CLK_SYNCE(0..1). The clock can be divided by 20, 40, 80 or 160
 * of the selected QLM SerDes clock.
 */
typedef union bdk_gpio_clk_syncex {
	uint64_t u;
	struct bdk_gpio_clk_syncex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t qlm_sel                     : 4;  /**< R/W - Selects which QLM(0..7) to select from. */
		uint64_t reserved_4_7                : 4;
		uint64_t div                         : 2;  /**< R/W - GPIO internal clock divider setting relative to QLM SerDes CLOCK_SYNCE. The maximum
                                                                 supported GPIO output frequency is 125 MHz.
                                                                 0x0 = Divide by 20.
                                                                 0x1 = Divide by 40.
                                                                 0x2 = Divide by 80.
                                                                 0x3 = Divide by 160. */
		uint64_t lane_sel                    : 2;  /**< R/W - Selects which RX lane clock from QLMx to use as the GPIO internal QLMx clock. */
#else
		uint64_t lane_sel                    : 2;
		uint64_t div                         : 2;
		uint64_t reserved_4_7                : 4;
		uint64_t qlm_sel                     : 4;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_gpio_clk_syncex_s       cn88xx; */
	/* struct bdk_gpio_clk_syncex_s       cn88xxp1; */
} bdk_gpio_clk_syncex_t;

static inline uint64_t BDK_GPIO_CLK_SYNCEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_CLK_SYNCEX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000803000000060ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_GPIO_CLK_SYNCEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_CLK_SYNCEX(...) bdk_gpio_clk_syncex_t
#define bustype_BDK_GPIO_CLK_SYNCEX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_CLK_SYNCEX(p1) (p1)
#define arguments_BDK_GPIO_CLK_SYNCEX(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_CLK_SYNCEX(...) "GPIO_CLK_SYNCEX"


/**
 * NCB - gpio_comp
 */
typedef union bdk_gpio_comp {
	uint64_t u;
	struct bdk_gpio_comp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t pctl                        : 3;  /**< R/W - GPIO bus driver PCTL. Suggested values:
                                                                 0x4 = 75 ohm.
                                                                 0x6 = 50 ohm.
                                                                 0x7 = 40 ohm. */
		uint64_t reserved_3_7                : 5;
		uint64_t nctl                        : 3;  /**< R/W - GPIO bus driver NCTL. Suggested values:
                                                                 0x4 = 75 ohm.
                                                                 0x6 = 50 ohm.
                                                                 0x7 = 40 ohm. */
#else
		uint64_t nctl                        : 3;
		uint64_t reserved_3_7                : 5;
		uint64_t pctl                        : 3;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_gpio_comp_s             cn88xx; */
	/* struct bdk_gpio_comp_s             cn88xxp1; */
} bdk_gpio_comp_t;

#define BDK_GPIO_COMP BDK_GPIO_COMP_FUNC()
static inline uint64_t BDK_GPIO_COMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_COMP_FUNC(void)
{
	return 0x0000803000000080ull;
}
#define typedef_BDK_GPIO_COMP bdk_gpio_comp_t
#define bustype_BDK_GPIO_COMP BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_COMP 0
#define arguments_BDK_GPIO_COMP -1,-1,-1,-1
#define basename_BDK_GPIO_COMP "GPIO_COMP"


/**
 * NCB - gpio_intr#
 *
 * Each register provides interrupt information for the corresponding GPIO pin.
 * GPIO_INTR interrupts can be level or edge interrupts depending on GPIO_BIT_CFG()[INT_TYPE].
 */
typedef union bdk_gpio_intrx {
	uint64_t u;
	struct bdk_gpio_intrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t intr_ena_w1s                : 1;  /**< R/W1S - GPIO signalled interrupt enable. Write one to set. Read out value is INTR_ENA. */
		uint64_t intr_ena_w1c                : 1;  /**< R/W1C - GPIO signalled interrupt enable. Write one to clear. Read out value is INTR_ENA. */
		uint64_t intr_w1s                    : 1;  /**< R/W1S/H - GPIO signalled interrupt. If interrupts are edge sensitive, write one to set, otherwise
                                                                 will clear automatically when GPIO pin de-asserts. Read out value is INTR. */
		uint64_t intr                        : 1;  /**< R/W1C/H - GPIO signalled interrupt. If interrupts are edge sensitive, write one to clear, otherwise
                                                                 will clear automatically when GPIO pin de-asserts. Read out value is INTR. */
#else
		uint64_t intr                        : 1;
		uint64_t intr_w1s                    : 1;
		uint64_t intr_ena_w1c                : 1;
		uint64_t intr_ena_w1s                : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_gpio_intrx_s            cn88xx; */
	/* struct bdk_gpio_intrx_s            cn88xxp1; */
} bdk_gpio_intrx_t;

static inline uint64_t BDK_GPIO_INTRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_INTRX(unsigned long param1)
{
	if (((param1 <= 50)))
		return 0x0000803000000800ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_GPIO_INTRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_INTRX(...) bdk_gpio_intrx_t
#define bustype_BDK_GPIO_INTRX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_INTRX(p1) (p1)
#define arguments_BDK_GPIO_INTRX(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_INTRX(...) "GPIO_INTRX"


/**
 * NCB - gpio_mc_intr#
 *
 * Each register provides interrupt multicasting for GPIO(4..7),
 * and all GPIO_MC_INTR interrupts are edge interrupts.
 */
typedef union bdk_gpio_mc_intrx {
	uint64_t u;
	struct bdk_gpio_mc_intrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t intr                        : 48; /**< R/W1C/H - GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else
		uint64_t intr                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gpio_mc_intrx_s         cn88xx; */
	/* struct bdk_gpio_mc_intrx_s         cn88xxp1; */
} bdk_gpio_mc_intrx_t;

static inline uint64_t BDK_GPIO_MC_INTRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX(unsigned long param1)
{
	if ((((param1 >= 4) && (param1 <= 7))))
		return 0x0000803000001000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_GPIO_MC_INTRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MC_INTRX(...) bdk_gpio_mc_intrx_t
#define bustype_BDK_GPIO_MC_INTRX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MC_INTRX(p1) (p1)
#define arguments_BDK_GPIO_MC_INTRX(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MC_INTRX(...) "GPIO_MC_INTRX"


/**
 * NCB - gpio_mc_intr#_ena_w1c
 */
typedef union bdk_gpio_mc_intrx_ena_w1c {
	uint64_t u;
	struct bdk_gpio_mc_intrx_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t intr                        : 48; /**< R/W1C/H - GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else
		uint64_t intr                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gpio_mc_intrx_ena_w1c_s cn88xx; */
	/* struct bdk_gpio_mc_intrx_ena_w1c_s cn88xxp1; */
} bdk_gpio_mc_intrx_ena_w1c_t;

static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1C(unsigned long param1)
{
	if ((((param1 >= 4) && (param1 <= 7))))
		return 0x0000803000001200ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_GPIO_MC_INTRX_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MC_INTRX_ENA_W1C(...) bdk_gpio_mc_intrx_ena_w1c_t
#define bustype_BDK_GPIO_MC_INTRX_ENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MC_INTRX_ENA_W1C(p1) (p1)
#define arguments_BDK_GPIO_MC_INTRX_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MC_INTRX_ENA_W1C(...) "GPIO_MC_INTRX_ENA_W1C"


/**
 * NCB - gpio_mc_intr#_ena_w1s
 */
typedef union bdk_gpio_mc_intrx_ena_w1s {
	uint64_t u;
	struct bdk_gpio_mc_intrx_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t intr                        : 48; /**< R/W1C/H - GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else
		uint64_t intr                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gpio_mc_intrx_ena_w1s_s cn88xx; */
	/* struct bdk_gpio_mc_intrx_ena_w1s_s cn88xxp1; */
} bdk_gpio_mc_intrx_ena_w1s_t;

static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX_ENA_W1S(unsigned long param1)
{
	if ((((param1 >= 4) && (param1 <= 7))))
		return 0x0000803000001300ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_GPIO_MC_INTRX_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MC_INTRX_ENA_W1S(...) bdk_gpio_mc_intrx_ena_w1s_t
#define bustype_BDK_GPIO_MC_INTRX_ENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MC_INTRX_ENA_W1S(p1) (p1)
#define arguments_BDK_GPIO_MC_INTRX_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MC_INTRX_ENA_W1S(...) "GPIO_MC_INTRX_ENA_W1S"


/**
 * NCB - gpio_mc_intr#_w1s
 */
typedef union bdk_gpio_mc_intrx_w1s {
	uint64_t u;
	struct bdk_gpio_mc_intrx_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t intr                        : 48; /**< R/W1C/H - GPIO interrupt for each core. When corresponding GPIO4-7 is edge-triggered and MULTI_CAST
                                                                 is enabled, a GPIO assertion will set all 48 bits. Each bit is expected to be routed to
                                                                 interrupt a different core using the CIU, and each core will then write one to clear its
                                                                 corresponding bit in this register. */
#else
		uint64_t intr                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_gpio_mc_intrx_w1s_s     cn88xx; */
	/* struct bdk_gpio_mc_intrx_w1s_s     cn88xxp1; */
} bdk_gpio_mc_intrx_w1s_t;

static inline uint64_t BDK_GPIO_MC_INTRX_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MC_INTRX_W1S(unsigned long param1)
{
	if ((((param1 >= 4) && (param1 <= 7))))
		return 0x0000803000001100ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_GPIO_MC_INTRX_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MC_INTRX_W1S(...) bdk_gpio_mc_intrx_w1s_t
#define bustype_BDK_GPIO_MC_INTRX_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MC_INTRX_W1S(p1) (p1)
#define arguments_BDK_GPIO_MC_INTRX_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MC_INTRX_W1S(...) "GPIO_MC_INTRX_W1S"


/**
 * NCB - gpio_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the GPIO_INT_VEC_E enumeration.
 *
 */
typedef union bdk_gpio_msix_pbax {
	uint64_t u;
	struct bdk_gpio_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO - Pending message for the associated GPIO_MSIX_VEC()_CTL, enumerated by
                                                                 GPIO_INT_VEC_E. Bits
                                                                 that have no associated GPIO_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_gpio_msix_pbax_s        cn88xx; */
	/* struct bdk_gpio_msix_pbax_s        cn88xxp1; */
} bdk_gpio_msix_pbax_t;

static inline uint64_t BDK_GPIO_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MSIX_PBAX(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x0000803000FF0000ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_GPIO_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MSIX_PBAX(...) bdk_gpio_msix_pbax_t
#define bustype_BDK_GPIO_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MSIX_PBAX(p1) (p1)
#define arguments_BDK_GPIO_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MSIX_PBAX(...) "GPIO_MSIX_PBAX"


/**
 * NCB - gpio_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the GPIO_INT_VEC_E enumeration.
 *
 */
typedef union bdk_gpio_msix_vecx_addr {
	uint64_t u;
	struct bdk_gpio_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's GPIO_MSIX_VEC()_ADDR, GPIO_MSIX_VEC()_CTL, and corresponding
                                                                 bit of GPIO_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_GPIO_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_gpio_msix_vecx_addr_s   cn88xx; */
	/* struct bdk_gpio_msix_vecx_addr_s   cn88xxp1; */
} bdk_gpio_msix_vecx_addr_t;

static inline uint64_t BDK_GPIO_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 149)))
		return 0x0000803000F00000ull + (param1 & 255) * 0x10ull;
	csr_fatal("BDK_GPIO_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MSIX_VECX_ADDR(...) bdk_gpio_msix_vecx_addr_t
#define bustype_BDK_GPIO_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_GPIO_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MSIX_VECX_ADDR(...) "GPIO_MSIX_VECX_ADDR"


/**
 * NCB - gpio_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the GPIO_INT_VEC_E enumeration.
 *
 */
typedef union bdk_gpio_msix_vecx_ctl {
	uint64_t u;
	struct bdk_gpio_msix_vecx_ctl_s {
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
	/* struct bdk_gpio_msix_vecx_ctl_s    cn88xx; */
	/* struct bdk_gpio_msix_vecx_ctl_s    cn88xxp1; */
} bdk_gpio_msix_vecx_ctl_t;

static inline uint64_t BDK_GPIO_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 149)))
		return 0x0000803000F00008ull + (param1 & 255) * 0x10ull;
	csr_fatal("BDK_GPIO_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_GPIO_MSIX_VECX_CTL(...) bdk_gpio_msix_vecx_ctl_t
#define bustype_BDK_GPIO_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_GPIO_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_GPIO_MSIX_VECX_CTL(...) "GPIO_MSIX_VECX_CTL"


/**
 * NCB - gpio_multi_cast
 *
 * This register enables multicast GPIO interrupts.
 *
 */
typedef union bdk_gpio_multi_cast {
	uint64_t u;
	struct bdk_gpio_multi_cast_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t en                          : 1;  /**< R/W - Enable GPIO interrupt multicast mode. When EN is set, GPIO\<7:4\> functions in multicast
                                                                 mode allowing these four GPIOs to interrupt multiple cores. Multicast functionality allows
                                                                 the GPIO to exist as per-core interrupts as opposed to a global interrupt. */
#else
		uint64_t en                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gpio_multi_cast_s       cn88xx; */
	/* struct bdk_gpio_multi_cast_s       cn88xxp1; */
} bdk_gpio_multi_cast_t;

#define BDK_GPIO_MULTI_CAST BDK_GPIO_MULTI_CAST_FUNC()
static inline uint64_t BDK_GPIO_MULTI_CAST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_MULTI_CAST_FUNC(void)
{
	return 0x0000803000000018ull;
}
#define typedef_BDK_GPIO_MULTI_CAST bdk_gpio_multi_cast_t
#define bustype_BDK_GPIO_MULTI_CAST BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_MULTI_CAST 0
#define arguments_BDK_GPIO_MULTI_CAST -1,-1,-1,-1
#define basename_BDK_GPIO_MULTI_CAST "GPIO_MULTI_CAST"


/**
 * NCB - gpio_ocla_exten_trig
 */
typedef union bdk_gpio_ocla_exten_trig {
	uint64_t u;
	struct bdk_gpio_ocla_exten_trig_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t m_trig                      : 1;  /**< R/W - Manual Trigger.  This external trigger can also use the GPIO(0..50) input pin, when
                                                                 GPIO_BIT_CFG()[PIN_SEL] = GPIO_PIN_SEL_E::OCLA_EXT_TRIGGER.
                                                                 This signal report to the OCLA coprocessor for GPIO-based triggering. When external
                                                                 trigger and manual trigger
                                                                 active at the same time, an ORed version of trigger is used. */
#else
		uint64_t m_trig                      : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_gpio_ocla_exten_trig_s  cn88xx; */
	/* struct bdk_gpio_ocla_exten_trig_s  cn88xxp1; */
} bdk_gpio_ocla_exten_trig_t;

#define BDK_GPIO_OCLA_EXTEN_TRIG BDK_GPIO_OCLA_EXTEN_TRIG_FUNC()
static inline uint64_t BDK_GPIO_OCLA_EXTEN_TRIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_OCLA_EXTEN_TRIG_FUNC(void)
{
	return 0x0000803000000020ull;
}
#define typedef_BDK_GPIO_OCLA_EXTEN_TRIG bdk_gpio_ocla_exten_trig_t
#define bustype_BDK_GPIO_OCLA_EXTEN_TRIG BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_OCLA_EXTEN_TRIG 0
#define arguments_BDK_GPIO_OCLA_EXTEN_TRIG -1,-1,-1,-1
#define basename_BDK_GPIO_OCLA_EXTEN_TRIG "GPIO_OCLA_EXTEN_TRIG"


/**
 * NCB - gpio_rx_dat
 *
 * This register contains the state of the GPIO pins, which is after glitch filter and XOR
 * inverter (GPIO_BIT_CFG()[PIN_XOR]). GPIO inputs always report to GPIO_RX_DAT despite of
 * the value of GPIO_BIT_CFG()[PIN_SEL].
 */
typedef union bdk_gpio_rx_dat {
	uint64_t u;
	struct bdk_gpio_rx_dat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t dat                         : 51; /**< RO/H - GPIO read data. */
#else
		uint64_t dat                         : 51;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_gpio_rx_dat_s           cn88xx; */
	/* struct bdk_gpio_rx_dat_s           cn88xxp1; */
} bdk_gpio_rx_dat_t;

#define BDK_GPIO_RX_DAT BDK_GPIO_RX_DAT_FUNC()
static inline uint64_t BDK_GPIO_RX_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_RX_DAT_FUNC(void)
{
	return 0x0000803000000000ull;
}
#define typedef_BDK_GPIO_RX_DAT bdk_gpio_rx_dat_t
#define bustype_BDK_GPIO_RX_DAT BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_RX_DAT 0
#define arguments_BDK_GPIO_RX_DAT -1,-1,-1,-1
#define basename_BDK_GPIO_RX_DAT "GPIO_RX_DAT"


/**
 * NCB - gpio_strap
 *
 * This register contains GPIO strap data captured at the rising edge of DC_OK.
 *
 */
typedef union bdk_gpio_strap {
	uint64_t u;
	struct bdk_gpio_strap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t strap                       : 51; /**< RO/H - GPIO strap data. */
#else
		uint64_t strap                       : 51;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_gpio_strap_s            cn88xx; */
	/* struct bdk_gpio_strap_s            cn88xxp1; */
} bdk_gpio_strap_t;

#define BDK_GPIO_STRAP BDK_GPIO_STRAP_FUNC()
static inline uint64_t BDK_GPIO_STRAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_STRAP_FUNC(void)
{
	return 0x0000803000000028ull;
}
#define typedef_BDK_GPIO_STRAP bdk_gpio_strap_t
#define bustype_BDK_GPIO_STRAP BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_STRAP 0
#define arguments_BDK_GPIO_STRAP -1,-1,-1,-1
#define basename_BDK_GPIO_STRAP "GPIO_STRAP"


/**
 * NCB - gpio_tx_clr
 */
typedef union bdk_gpio_tx_clr {
	uint64_t u;
	struct bdk_gpio_tx_clr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t clr                         : 51; /**< R/W1C/H - Clear mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 0. When read, CLR
                                                                 returns the GPIO_TX_DAT storage. */
#else
		uint64_t clr                         : 51;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_gpio_tx_clr_s           cn88xx; */
	/* struct bdk_gpio_tx_clr_s           cn88xxp1; */
} bdk_gpio_tx_clr_t;

#define BDK_GPIO_TX_CLR BDK_GPIO_TX_CLR_FUNC()
static inline uint64_t BDK_GPIO_TX_CLR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_TX_CLR_FUNC(void)
{
	return 0x0000803000000010ull;
}
#define typedef_BDK_GPIO_TX_CLR bdk_gpio_tx_clr_t
#define bustype_BDK_GPIO_TX_CLR BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_TX_CLR 0
#define arguments_BDK_GPIO_TX_CLR -1,-1,-1,-1
#define basename_BDK_GPIO_TX_CLR "GPIO_TX_CLR"


/**
 * NCB - gpio_tx_set
 */
typedef union bdk_gpio_tx_set {
	uint64_t u;
	struct bdk_gpio_tx_set_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t set                         : 51; /**< R/W1S/H - Set mask. Bit mask to indicate which GPIO_TX_DAT bits to set to 1. When read, SET
                                                                 returns the GPIO_TX_DAT storage. */
#else
		uint64_t set                         : 51;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_gpio_tx_set_s           cn88xx; */
	/* struct bdk_gpio_tx_set_s           cn88xxp1; */
} bdk_gpio_tx_set_t;

#define BDK_GPIO_TX_SET BDK_GPIO_TX_SET_FUNC()
static inline uint64_t BDK_GPIO_TX_SET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_GPIO_TX_SET_FUNC(void)
{
	return 0x0000803000000008ull;
}
#define typedef_BDK_GPIO_TX_SET bdk_gpio_tx_set_t
#define bustype_BDK_GPIO_TX_SET BDK_CSR_TYPE_NCB
#define busnum_BDK_GPIO_TX_SET 0
#define arguments_BDK_GPIO_TX_SET -1,-1,-1,-1
#define basename_BDK_GPIO_TX_SET "GPIO_TX_SET"

#endif /* __BDK_CSRS_GPIO__ */
