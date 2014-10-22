#ifndef __BDK_CSRS_SMMU__
#define __BDK_CSRS_SMMU__
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
 * Cavium SMMU.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration SMMU_CTYPE_E
 *
 * SMMU Context Bank Type Enumeration
 * Enumerates the values of SMMU()_CBAR()[CTYPE].
 */
enum smmu_ctype_e {
	SMMU_CTYPE_E_STAGE1_BYP2 = 0x1,
	SMMU_CTYPE_E_STAGE1_FAULT2 = 0x2,
	SMMU_CTYPE_E_STAGE1_STAGE2 = 0x3,
	SMMU_CTYPE_E_STAGE2 = 0x0,
	SMMU_CTYPE_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration SMMU_INT_VEC_E
 *
 * SMMU MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum smmu_int_vec_e {
	SMMU_INT_VEC_E_CB0_FSR = 0x0,
	SMMU_INT_VEC_E_CB0_FSR_CLEAR = 0x1,
	SMMU_INT_VEC_E_CB100_FSR = 0xc8,
	SMMU_INT_VEC_E_CB100_FSR_CLEAR = 0xc9,
	SMMU_INT_VEC_E_CB101_FSR = 0xca,
	SMMU_INT_VEC_E_CB101_FSR_CLEAR = 0xcb,
	SMMU_INT_VEC_E_CB102_FSR = 0xcc,
	SMMU_INT_VEC_E_CB102_FSR_CLEAR = 0xcd,
	SMMU_INT_VEC_E_CB103_FSR = 0xce,
	SMMU_INT_VEC_E_CB103_FSR_CLEAR = 0xcf,
	SMMU_INT_VEC_E_CB104_FSR = 0xd0,
	SMMU_INT_VEC_E_CB104_FSR_CLEAR = 0xd1,
	SMMU_INT_VEC_E_CB105_FSR = 0xd2,
	SMMU_INT_VEC_E_CB105_FSR_CLEAR = 0xd3,
	SMMU_INT_VEC_E_CB106_FSR = 0xd4,
	SMMU_INT_VEC_E_CB106_FSR_CLEAR = 0xd5,
	SMMU_INT_VEC_E_CB107_FSR = 0xd6,
	SMMU_INT_VEC_E_CB107_FSR_CLEAR = 0xd7,
	SMMU_INT_VEC_E_CB108_FSR = 0xd8,
	SMMU_INT_VEC_E_CB108_FSR_CLEAR = 0xd9,
	SMMU_INT_VEC_E_CB109_FSR = 0xda,
	SMMU_INT_VEC_E_CB109_FSR_CLEAR = 0xdb,
	SMMU_INT_VEC_E_CB10_FSR = 0x14,
	SMMU_INT_VEC_E_CB10_FSR_CLEAR = 0x15,
	SMMU_INT_VEC_E_CB110_FSR = 0xdc,
	SMMU_INT_VEC_E_CB110_FSR_CLEAR = 0xdd,
	SMMU_INT_VEC_E_CB111_FSR = 0xde,
	SMMU_INT_VEC_E_CB111_FSR_CLEAR = 0xdf,
	SMMU_INT_VEC_E_CB112_FSR = 0xe0,
	SMMU_INT_VEC_E_CB112_FSR_CLEAR = 0xe1,
	SMMU_INT_VEC_E_CB113_FSR = 0xe2,
	SMMU_INT_VEC_E_CB113_FSR_CLEAR = 0xe3,
	SMMU_INT_VEC_E_CB114_FSR = 0xe4,
	SMMU_INT_VEC_E_CB114_FSR_CLEAR = 0xe5,
	SMMU_INT_VEC_E_CB115_FSR = 0xe6,
	SMMU_INT_VEC_E_CB115_FSR_CLEAR = 0xe7,
	SMMU_INT_VEC_E_CB116_FSR = 0xe8,
	SMMU_INT_VEC_E_CB116_FSR_CLEAR = 0xe9,
	SMMU_INT_VEC_E_CB117_FSR = 0xea,
	SMMU_INT_VEC_E_CB117_FSR_CLEAR = 0xeb,
	SMMU_INT_VEC_E_CB118_FSR = 0xec,
	SMMU_INT_VEC_E_CB118_FSR_CLEAR = 0xed,
	SMMU_INT_VEC_E_CB119_FSR = 0xee,
	SMMU_INT_VEC_E_CB119_FSR_CLEAR = 0xef,
	SMMU_INT_VEC_E_CB11_FSR = 0x16,
	SMMU_INT_VEC_E_CB11_FSR_CLEAR = 0x17,
	SMMU_INT_VEC_E_CB120_FSR = 0xf0,
	SMMU_INT_VEC_E_CB120_FSR_CLEAR = 0xf1,
	SMMU_INT_VEC_E_CB121_FSR = 0xf2,
	SMMU_INT_VEC_E_CB121_FSR_CLEAR = 0xf3,
	SMMU_INT_VEC_E_CB122_FSR = 0xf4,
	SMMU_INT_VEC_E_CB122_FSR_CLEAR = 0xf5,
	SMMU_INT_VEC_E_CB123_FSR = 0xf6,
	SMMU_INT_VEC_E_CB123_FSR_CLEAR = 0xf7,
	SMMU_INT_VEC_E_CB124_FSR = 0xf8,
	SMMU_INT_VEC_E_CB124_FSR_CLEAR = 0xf9,
	SMMU_INT_VEC_E_CB125_FSR = 0xfa,
	SMMU_INT_VEC_E_CB125_FSR_CLEAR = 0xfb,
	SMMU_INT_VEC_E_CB126_FSR = 0xfc,
	SMMU_INT_VEC_E_CB126_FSR_CLEAR = 0xfd,
	SMMU_INT_VEC_E_CB127_FSR = 0xfe,
	SMMU_INT_VEC_E_CB127_FSR_CLEAR = 0xff,
	SMMU_INT_VEC_E_CB12_FSR = 0x18,
	SMMU_INT_VEC_E_CB12_FSR_CLEAR = 0x19,
	SMMU_INT_VEC_E_CB13_FSR = 0x1a,
	SMMU_INT_VEC_E_CB13_FSR_CLEAR = 0x1b,
	SMMU_INT_VEC_E_CB14_FSR = 0x1c,
	SMMU_INT_VEC_E_CB14_FSR_CLEAR = 0x1d,
	SMMU_INT_VEC_E_CB15_FSR = 0x1e,
	SMMU_INT_VEC_E_CB15_FSR_CLEAR = 0x1f,
	SMMU_INT_VEC_E_CB16_FSR = 0x20,
	SMMU_INT_VEC_E_CB16_FSR_CLEAR = 0x21,
	SMMU_INT_VEC_E_CB17_FSR = 0x22,
	SMMU_INT_VEC_E_CB17_FSR_CLEAR = 0x23,
	SMMU_INT_VEC_E_CB18_FSR = 0x24,
	SMMU_INT_VEC_E_CB18_FSR_CLEAR = 0x25,
	SMMU_INT_VEC_E_CB19_FSR = 0x26,
	SMMU_INT_VEC_E_CB19_FSR_CLEAR = 0x27,
	SMMU_INT_VEC_E_CB1_FSR = 0x2,
	SMMU_INT_VEC_E_CB1_FSR_CLEAR = 0x3,
	SMMU_INT_VEC_E_CB20_FSR = 0x28,
	SMMU_INT_VEC_E_CB20_FSR_CLEAR = 0x29,
	SMMU_INT_VEC_E_CB21_FSR = 0x2a,
	SMMU_INT_VEC_E_CB21_FSR_CLEAR = 0x2b,
	SMMU_INT_VEC_E_CB22_FSR = 0x2c,
	SMMU_INT_VEC_E_CB22_FSR_CLEAR = 0x2d,
	SMMU_INT_VEC_E_CB23_FSR = 0x2e,
	SMMU_INT_VEC_E_CB23_FSR_CLEAR = 0x2f,
	SMMU_INT_VEC_E_CB24_FSR = 0x30,
	SMMU_INT_VEC_E_CB24_FSR_CLEAR = 0x31,
	SMMU_INT_VEC_E_CB25_FSR = 0x32,
	SMMU_INT_VEC_E_CB25_FSR_CLEAR = 0x33,
	SMMU_INT_VEC_E_CB26_FSR = 0x34,
	SMMU_INT_VEC_E_CB26_FSR_CLEAR = 0x35,
	SMMU_INT_VEC_E_CB27_FSR = 0x36,
	SMMU_INT_VEC_E_CB27_FSR_CLEAR = 0x37,
	SMMU_INT_VEC_E_CB28_FSR = 0x38,
	SMMU_INT_VEC_E_CB28_FSR_CLEAR = 0x39,
	SMMU_INT_VEC_E_CB29_FSR = 0x3a,
	SMMU_INT_VEC_E_CB29_FSR_CLEAR = 0x3b,
	SMMU_INT_VEC_E_CB2_FSR = 0x4,
	SMMU_INT_VEC_E_CB2_FSR_CLEAR = 0x5,
	SMMU_INT_VEC_E_CB30_FSR = 0x3c,
	SMMU_INT_VEC_E_CB30_FSR_CLEAR = 0x3d,
	SMMU_INT_VEC_E_CB31_FSR = 0x3e,
	SMMU_INT_VEC_E_CB31_FSR_CLEAR = 0x3f,
	SMMU_INT_VEC_E_CB32_FSR = 0x40,
	SMMU_INT_VEC_E_CB32_FSR_CLEAR = 0x41,
	SMMU_INT_VEC_E_CB33_FSR = 0x42,
	SMMU_INT_VEC_E_CB33_FSR_CLEAR = 0x43,
	SMMU_INT_VEC_E_CB34_FSR = 0x44,
	SMMU_INT_VEC_E_CB34_FSR_CLEAR = 0x45,
	SMMU_INT_VEC_E_CB35_FSR = 0x46,
	SMMU_INT_VEC_E_CB35_FSR_CLEAR = 0x47,
	SMMU_INT_VEC_E_CB36_FSR = 0x48,
	SMMU_INT_VEC_E_CB36_FSR_CLEAR = 0x49,
	SMMU_INT_VEC_E_CB37_FSR = 0x4a,
	SMMU_INT_VEC_E_CB37_FSR_CLEAR = 0x4b,
	SMMU_INT_VEC_E_CB38_FSR = 0x4c,
	SMMU_INT_VEC_E_CB38_FSR_CLEAR = 0x4d,
	SMMU_INT_VEC_E_CB39_FSR = 0x4e,
	SMMU_INT_VEC_E_CB39_FSR_CLEAR = 0x4f,
	SMMU_INT_VEC_E_CB3_FSR = 0x6,
	SMMU_INT_VEC_E_CB3_FSR_CLEAR = 0x7,
	SMMU_INT_VEC_E_CB40_FSR = 0x50,
	SMMU_INT_VEC_E_CB40_FSR_CLEAR = 0x51,
	SMMU_INT_VEC_E_CB41_FSR = 0x52,
	SMMU_INT_VEC_E_CB41_FSR_CLEAR = 0x53,
	SMMU_INT_VEC_E_CB42_FSR = 0x54,
	SMMU_INT_VEC_E_CB42_FSR_CLEAR = 0x55,
	SMMU_INT_VEC_E_CB43_FSR = 0x56,
	SMMU_INT_VEC_E_CB43_FSR_CLEAR = 0x57,
	SMMU_INT_VEC_E_CB44_FSR = 0x58,
	SMMU_INT_VEC_E_CB44_FSR_CLEAR = 0x59,
	SMMU_INT_VEC_E_CB45_FSR = 0x5a,
	SMMU_INT_VEC_E_CB45_FSR_CLEAR = 0x5b,
	SMMU_INT_VEC_E_CB46_FSR = 0x5c,
	SMMU_INT_VEC_E_CB46_FSR_CLEAR = 0x5d,
	SMMU_INT_VEC_E_CB47_FSR = 0x5e,
	SMMU_INT_VEC_E_CB47_FSR_CLEAR = 0x5f,
	SMMU_INT_VEC_E_CB48_FSR = 0x60,
	SMMU_INT_VEC_E_CB48_FSR_CLEAR = 0x61,
	SMMU_INT_VEC_E_CB49_FSR = 0x62,
	SMMU_INT_VEC_E_CB49_FSR_CLEAR = 0x63,
	SMMU_INT_VEC_E_CB4_FSR = 0x8,
	SMMU_INT_VEC_E_CB4_FSR_CLEAR = 0x9,
	SMMU_INT_VEC_E_CB50_FSR = 0x64,
	SMMU_INT_VEC_E_CB50_FSR_CLEAR = 0x65,
	SMMU_INT_VEC_E_CB51_FSR = 0x66,
	SMMU_INT_VEC_E_CB51_FSR_CLEAR = 0x67,
	SMMU_INT_VEC_E_CB52_FSR = 0x68,
	SMMU_INT_VEC_E_CB52_FSR_CLEAR = 0x69,
	SMMU_INT_VEC_E_CB53_FSR = 0x6a,
	SMMU_INT_VEC_E_CB53_FSR_CLEAR = 0x6b,
	SMMU_INT_VEC_E_CB54_FSR = 0x6c,
	SMMU_INT_VEC_E_CB54_FSR_CLEAR = 0x6d,
	SMMU_INT_VEC_E_CB55_FSR = 0x6e,
	SMMU_INT_VEC_E_CB55_FSR_CLEAR = 0x6f,
	SMMU_INT_VEC_E_CB56_FSR = 0x70,
	SMMU_INT_VEC_E_CB56_FSR_CLEAR = 0x71,
	SMMU_INT_VEC_E_CB57_FSR = 0x72,
	SMMU_INT_VEC_E_CB57_FSR_CLEAR = 0x73,
	SMMU_INT_VEC_E_CB58_FSR = 0x74,
	SMMU_INT_VEC_E_CB58_FSR_CLEAR = 0x75,
	SMMU_INT_VEC_E_CB59_FSR = 0x76,
	SMMU_INT_VEC_E_CB59_FSR_CLEAR = 0x77,
	SMMU_INT_VEC_E_CB5_FSR = 0xa,
	SMMU_INT_VEC_E_CB5_FSR_CLEAR = 0xb,
	SMMU_INT_VEC_E_CB60_FSR = 0x78,
	SMMU_INT_VEC_E_CB60_FSR_CLEAR = 0x79,
	SMMU_INT_VEC_E_CB61_FSR = 0x7a,
	SMMU_INT_VEC_E_CB61_FSR_CLEAR = 0x7b,
	SMMU_INT_VEC_E_CB62_FSR = 0x7c,
	SMMU_INT_VEC_E_CB62_FSR_CLEAR = 0x7d,
	SMMU_INT_VEC_E_CB63_FSR = 0x7e,
	SMMU_INT_VEC_E_CB63_FSR_CLEAR = 0x7f,
	SMMU_INT_VEC_E_CB64_FSR = 0x80,
	SMMU_INT_VEC_E_CB64_FSR_CLEAR = 0x81,
	SMMU_INT_VEC_E_CB65_FSR = 0x82,
	SMMU_INT_VEC_E_CB65_FSR_CLEAR = 0x83,
	SMMU_INT_VEC_E_CB66_FSR = 0x84,
	SMMU_INT_VEC_E_CB66_FSR_CLEAR = 0x85,
	SMMU_INT_VEC_E_CB67_FSR = 0x86,
	SMMU_INT_VEC_E_CB67_FSR_CLEAR = 0x87,
	SMMU_INT_VEC_E_CB68_FSR = 0x88,
	SMMU_INT_VEC_E_CB68_FSR_CLEAR = 0x89,
	SMMU_INT_VEC_E_CB69_FSR = 0x8a,
	SMMU_INT_VEC_E_CB69_FSR_CLEAR = 0x8b,
	SMMU_INT_VEC_E_CB6_FSR = 0xc,
	SMMU_INT_VEC_E_CB6_FSR_CLEAR = 0xd,
	SMMU_INT_VEC_E_CB70_FSR = 0x8c,
	SMMU_INT_VEC_E_CB70_FSR_CLEAR = 0x8d,
	SMMU_INT_VEC_E_CB71_FSR = 0x8e,
	SMMU_INT_VEC_E_CB71_FSR_CLEAR = 0x8f,
	SMMU_INT_VEC_E_CB72_FSR = 0x90,
	SMMU_INT_VEC_E_CB72_FSR_CLEAR = 0x91,
	SMMU_INT_VEC_E_CB73_FSR = 0x92,
	SMMU_INT_VEC_E_CB73_FSR_CLEAR = 0x93,
	SMMU_INT_VEC_E_CB74_FSR = 0x94,
	SMMU_INT_VEC_E_CB74_FSR_CLEAR = 0x95,
	SMMU_INT_VEC_E_CB75_FSR = 0x96,
	SMMU_INT_VEC_E_CB75_FSR_CLEAR = 0x97,
	SMMU_INT_VEC_E_CB76_FSR = 0x98,
	SMMU_INT_VEC_E_CB76_FSR_CLEAR = 0x99,
	SMMU_INT_VEC_E_CB77_FSR = 0x9a,
	SMMU_INT_VEC_E_CB77_FSR_CLEAR = 0x9b,
	SMMU_INT_VEC_E_CB78_FSR = 0x9c,
	SMMU_INT_VEC_E_CB78_FSR_CLEAR = 0x9d,
	SMMU_INT_VEC_E_CB79_FSR = 0x9e,
	SMMU_INT_VEC_E_CB79_FSR_CLEAR = 0x9f,
	SMMU_INT_VEC_E_CB7_FSR = 0xe,
	SMMU_INT_VEC_E_CB7_FSR_CLEAR = 0xf,
	SMMU_INT_VEC_E_CB80_FSR = 0xa0,
	SMMU_INT_VEC_E_CB80_FSR_CLEAR = 0xa1,
	SMMU_INT_VEC_E_CB81_FSR = 0xa2,
	SMMU_INT_VEC_E_CB81_FSR_CLEAR = 0xa3,
	SMMU_INT_VEC_E_CB82_FSR = 0xa4,
	SMMU_INT_VEC_E_CB82_FSR_CLEAR = 0xa5,
	SMMU_INT_VEC_E_CB83_FSR = 0xa6,
	SMMU_INT_VEC_E_CB83_FSR_CLEAR = 0xa7,
	SMMU_INT_VEC_E_CB84_FSR = 0xa8,
	SMMU_INT_VEC_E_CB84_FSR_CLEAR = 0xa9,
	SMMU_INT_VEC_E_CB85_FSR = 0xaa,
	SMMU_INT_VEC_E_CB85_FSR_CLEAR = 0xab,
	SMMU_INT_VEC_E_CB86_FSR = 0xac,
	SMMU_INT_VEC_E_CB86_FSR_CLEAR = 0xad,
	SMMU_INT_VEC_E_CB87_FSR = 0xae,
	SMMU_INT_VEC_E_CB87_FSR_CLEAR = 0xaf,
	SMMU_INT_VEC_E_CB88_FSR = 0xb0,
	SMMU_INT_VEC_E_CB88_FSR_CLEAR = 0xb1,
	SMMU_INT_VEC_E_CB89_FSR = 0xb2,
	SMMU_INT_VEC_E_CB89_FSR_CLEAR = 0xb3,
	SMMU_INT_VEC_E_CB8_FSR = 0x10,
	SMMU_INT_VEC_E_CB8_FSR_CLEAR = 0x11,
	SMMU_INT_VEC_E_CB90_FSR = 0xb4,
	SMMU_INT_VEC_E_CB90_FSR_CLEAR = 0xb5,
	SMMU_INT_VEC_E_CB91_FSR = 0xb6,
	SMMU_INT_VEC_E_CB91_FSR_CLEAR = 0xb7,
	SMMU_INT_VEC_E_CB92_FSR = 0xb8,
	SMMU_INT_VEC_E_CB92_FSR_CLEAR = 0xb9,
	SMMU_INT_VEC_E_CB93_FSR = 0xba,
	SMMU_INT_VEC_E_CB93_FSR_CLEAR = 0xbb,
	SMMU_INT_VEC_E_CB94_FSR = 0xbc,
	SMMU_INT_VEC_E_CB94_FSR_CLEAR = 0xbd,
	SMMU_INT_VEC_E_CB95_FSR = 0xbe,
	SMMU_INT_VEC_E_CB95_FSR_CLEAR = 0xbf,
	SMMU_INT_VEC_E_CB96_FSR = 0xc0,
	SMMU_INT_VEC_E_CB96_FSR_CLEAR = 0xc1,
	SMMU_INT_VEC_E_CB97_FSR = 0xc2,
	SMMU_INT_VEC_E_CB97_FSR_CLEAR = 0xc3,
	SMMU_INT_VEC_E_CB98_FSR = 0xc4,
	SMMU_INT_VEC_E_CB98_FSR_CLEAR = 0xc5,
	SMMU_INT_VEC_E_CB99_FSR = 0xc6,
	SMMU_INT_VEC_E_CB99_FSR_CLEAR = 0xc7,
	SMMU_INT_VEC_E_CB9_FSR = 0x12,
	SMMU_INT_VEC_E_CB9_FSR_CLEAR = 0x13,
	SMMU_INT_VEC_E_ERRFLG = 0x104,
	SMMU_INT_VEC_E_ERR_CLEAR = 0x105,
	SMMU_INT_VEC_E_NSGFSR = 0x100,
	SMMU_INT_VEC_E_NSGFSR_CLEAR = 0x101,
	SMMU_INT_VEC_E_SGFSR = 0x102,
	SMMU_INT_VEC_E_SGFSR_CLEAR = 0x103,
	SMMU_INT_VEC_E_ENUM_LAST = 0x106,
};



/**
 * NCB - smmu#_active_pc
 *
 * This register counts every core-clock cycle that the SMMU clocks are active.
 *
 */
typedef union bdk_smmux_active_pc {
	uint64_t u;
	struct bdk_smmux_active_pc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< RO/H - Counts the number of active core-clock cycles in the conditional clock domain. INTERNAL:
                                                                 Values are duplicated across each SMMU that shares an IOB. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_active_pc_s       cn88xx; */
	/* struct bdk_smmux_active_pc_s       cn88xxp1; */
} bdk_smmux_active_pc_t;

static inline uint64_t BDK_SMMUX_ACTIVE_PC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ACTIVE_PC(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021000ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ACTIVE_PC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ACTIVE_PC(...) bdk_smmux_active_pc_t
#define bustype_BDK_SMMUX_ACTIVE_PC(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ACTIVE_PC(p1) (p1)
#define arguments_BDK_SMMUX_ACTIVE_PC(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ACTIVE_PC(...) "SMMUX_ACTIVE_PC"


/**
 * NCB - smmu#_bist_status
 *
 * Contains the BIST status for the SSO memories.
 *
 */
typedef union bdk_smmux_bist_status {
	uint64_t u;
	struct bdk_smmux_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bist                        : 64; /**< RO - Memory BIST status. 0 = pass, 1 = fail. INTERNAL: Values are duplicated across each SMMU
                                                                 that shares an IOB.
                                                                 \<23\> = CSR_VMID_CAM.
                                                                 \<22\> = CSR_ASID_CAM.
                                                                 \<21\> = SIL_CAM.
                                                                 \<20\> = MSIX.
                                                                 \<19\> = WCTL.
                                                                 \<18\> = XL_MFIFO.
                                                                 \<17\> = TCTL.
                                                                 \<16\> = CONTEXT_IDR.
                                                                 \<15\> = CB_FRSYNRA.
                                                                 \<14\> = CB_IPAFAR.
                                                                 \<13\> = CB_FSYNR0.
                                                                 \<12\> = CB_FAR.
                                                                 \<11\> = S2CR.
                                                                 \<10\> = CB_ACTLR.
                                                                 \<9\> = CB_TCR2.
                                                                 \<8\> = SSDR.
                                                                 \<7\> = SCTLR.
                                                                 \<6\> = CB_TTBR0.
                                                                 \<5\> = CB_TTBR1.
                                                                 \<4\> = CB_TCR.
                                                                 \<3\> = CBA2R.
                                                                 \<2\> = CBAR.
                                                                 \<1\> = CB_MAIR0.
                                                                 \<0\> = CB_MAIR1. */
#else
		uint64_t bist                        : 64;
#endif
	} s;
	/* struct bdk_smmux_bist_status_s     cn88xx; */
	/* struct bdk_smmux_bist_status_s     cn88xxp1; */
} bdk_smmux_bist_status_t;

static inline uint64_t BDK_SMMUX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020010ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_BIST_STATUS(...) bdk_smmux_bist_status_t
#define bustype_BDK_SMMUX_BIST_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_BIST_STATUS(p1) (p1)
#define arguments_BDK_SMMUX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_BIST_STATUS(...) "SMMUX_BIST_STATUS"


/**
 * NCB32b - smmu#_cb#_actlr
 *
 * This register contains implementation specific context fields.
 *
 */
typedef union bdk_smmux_cbx_actlr {
	uint32_t u;
	struct bdk_smmux_cbx_actlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t qos                         : 4;  /**< R/W - L2C quality-of-service value to use for transactions to this context. */
		uint32_t reserved_16_27              : 12;
		uint32_t dis_bnk                     : 16; /**< R/W - Bitmask of sections of TLB to disable for fills caused by transactions to this
                                                                 context. May be used to partition the TLB to achieve QoS; note the WCU is not likewise
                                                                 partitioned. If a context is marked secure but accessed insecurely, than this register is
                                                                 RAZ/WI. For nested translations, the primary context's DIS_BNK is used. */
#else
		uint32_t dis_bnk                     : 16;
		uint32_t reserved_16_27              : 12;
		uint32_t qos                         : 4;
#endif
	} s;
	/* struct bdk_smmux_cbx_actlr_s       cn88xx; */
	/* struct bdk_smmux_cbx_actlr_s       cn88xxp1; */
} bdk_smmux_cbx_actlr_t;

static inline uint64_t BDK_SMMUX_CBX_ACTLR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_ACTLR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000004ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_ACTLR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_ACTLR(...) bdk_smmux_cbx_actlr_t
#define bustype_BDK_SMMUX_CBX_ACTLR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_ACTLR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_ACTLR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_ACTLR(...) "SMMUX_CBX_ACTLR"


/**
 * NCB32b - smmu#_cb#_contextidr
 *
 * Identifies the current process identifier. Used only by software.
 * This register is used by stage 1 context banks.
 */
typedef union bdk_smmux_cbx_contextidr {
	uint32_t u;
	struct bdk_smmux_cbx_contextidr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t procid                      : 32; /**< R/W - Process identifier. Used only by software. */
#else
		uint32_t procid                      : 32;
#endif
	} s;
	/* struct bdk_smmux_cbx_contextidr_s  cn88xx; */
	/* struct bdk_smmux_cbx_contextidr_s  cn88xxp1; */
} bdk_smmux_cbx_contextidr_t;

static inline uint64_t BDK_SMMUX_CBX_CONTEXTIDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_CONTEXTIDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000034ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_CONTEXTIDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_CONTEXTIDR(...) bdk_smmux_cbx_contextidr_t
#define bustype_BDK_SMMUX_CBX_CONTEXTIDR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_CONTEXTIDR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_CONTEXTIDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_CONTEXTIDR(...) "SMMUX_CBX_CONTEXTIDR"


/**
 * NCB - smmu#_cb#_far
 *
 * This register is used by both stage 1 and stage 2 context banks. This register might be
 * updated as the result of
 * 1. A stage 2 only context fault for an upstream client device. The IPA supplied by the
 * upstream client device is recorded.
 * 2. A nested stage 1 + stage 2 fault. The VA supplied by the upstream client device to the
 * stage 1 context is recorded. Note: the IPA is not recorded but the fault is tagged as nested
 * and the index of the stage 1 context is recorded in SMMU_FSYNR0.
 * 3. An ATOS operation at stage 1 in a nested context that faults at stage 2. The VA supplied by
 * to the global or stage 1 address translation operation is recorded. The IPA is recorded in
 * SMMU()_CB()_IPAFAR below and the fault is tagged as nested. The index of the stage 1
 * context is recorded in SMMU()_CB()_FSYNR0.
 */
typedef union bdk_smmux_cbx_far {
	uint64_t u;
	struct bdk_smmux_cbx_far_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t faddr                       : 37; /**< R/W/H - Fault address, the input address of the faulting access. This register might be updated as
                                                                 the result of a translation fault for an upstream client device. For CNXXXX \<11:0\> are
                                                                 always zero. */
		uint64_t reserved_0_11               : 12;
#else
		uint64_t reserved_0_11               : 12;
		uint64_t faddr                       : 37;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_smmux_cbx_far_s         cn88xx; */
	/* struct bdk_smmux_cbx_far_s         cn88xxp1; */
} bdk_smmux_cbx_far_t;

static inline uint64_t BDK_SMMUX_CBX_FAR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FAR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000060ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_FAR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_FAR(...) bdk_smmux_cbx_far_t
#define bustype_BDK_SMMUX_CBX_FAR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_FAR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_FAR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_FAR(...) "SMMUX_CBX_FAR"


/**
 * NCB32b - smmu#_cb#_fsr
 *
 * Provides memory system fault status information. This register is used by both stage 1 and
 * stage 2 context banks.
 */
typedef union bdk_smmux_cbx_fsr {
	uint32_t u;
	struct bdk_smmux_cbx_fsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t multi                       : 1;  /**< R/W1C/H - Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in SMMU(0..3)_(S)GFSR was nonzero. */
		uint32_t ss                          : 1;  /**< RO - Stalled status.
                                                                 0 = SMMU not stalled due to a fault in this bank.
                                                                 1 = SMMU stalled due to a fault in this bank.

                                                                 For CNXXXX always zero, no stalls. */
		uint32_t reserved_11_29              : 19;
		uint32_t fmt                         : 2;  /**< RO - Translation scheme.
                                                                 0x0 = AArch32 short-descriptor translation scheme.
                                                                 0x1 = AArch32 long-descriptor translation scheme.
                                                                 0x2 = AArch64 translation scheme.
                                                                 0x3 = Reserved.

                                                                 For CNXXXX always AArch64. */
		uint32_t uut                         : 1;  /**< RAZ - Unsupported upstream transaction fault. */
		uint32_t asf                         : 1;  /**< R/W1C/H - Incorrect address size fault. */
		uint32_t tlblkf                      : 1;  /**< RAZ - TLB lock fault. For CNXXXX always zero, no TLB locks. */
		uint32_t tlbmcf                      : 1;  /**< R/W1C/H - TLB match conflict fault. */
		uint32_t ef                          : 1;  /**< R/W1C/H - External fault. */
		uint32_t pf                          : 1;  /**< R/W1C/H - Permission fault.
                                                                 0 = No permission fault.
                                                                 1 = Fault caused by insufficient permission to complete a memory access has occurred. */
		uint32_t aff                         : 1;  /**< R/W1C/H - Access flag fault.
                                                                 0 = No access flag fault.
                                                                 1 = Fault caused by the access flag being set for the address being accessed has occurred. */
		uint32_t tf                          : 1;  /**< R/W1C/H - Translation fault.
                                                                 0 = No translation fault.
                                                                 1 = Translation fault has occurred. The mapping for the address being accessed is invalid. */
		uint32_t reserved_0_0                : 1;
#else
		uint32_t reserved_0_0                : 1;
		uint32_t tf                          : 1;
		uint32_t aff                         : 1;
		uint32_t pf                          : 1;
		uint32_t ef                          : 1;
		uint32_t tlbmcf                      : 1;
		uint32_t tlblkf                      : 1;
		uint32_t asf                         : 1;
		uint32_t uut                         : 1;
		uint32_t fmt                         : 2;
		uint32_t reserved_11_29              : 19;
		uint32_t ss                          : 1;
		uint32_t multi                       : 1;
#endif
	} s;
	/* struct bdk_smmux_cbx_fsr_s         cn88xx; */
	/* struct bdk_smmux_cbx_fsr_s         cn88xxp1; */
} bdk_smmux_cbx_fsr_t;

static inline uint64_t BDK_SMMUX_CBX_FSR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000058ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_FSR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_FSR(...) bdk_smmux_cbx_fsr_t
#define bustype_BDK_SMMUX_CBX_FSR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_FSR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_FSR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_FSR(...) "SMMUX_CBX_FSR"


/**
 * NCB32b - smmu#_cb#_fsrrestore
 *
 * Restores the SMMU()_CB()_FSR register after reset. This register is used by both
 * stage 1 and stage 2 context banks.
 */
typedef union bdk_smmux_cbx_fsrrestore {
	uint32_t u;
	struct bdk_smmux_cbx_fsrrestore_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t restore                     : 32; /**< WO - Writes bits in corresponding SMMU()_CB()_FSR. */
#else
		uint32_t restore                     : 32;
#endif
	} s;
	/* struct bdk_smmux_cbx_fsrrestore_s  cn88xx; */
	/* struct bdk_smmux_cbx_fsrrestore_s  cn88xxp1; */
} bdk_smmux_cbx_fsrrestore_t;

static inline uint64_t BDK_SMMUX_CBX_FSRRESTORE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSRRESTORE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x000083000100005Cull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_FSRRESTORE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_FSRRESTORE(...) bdk_smmux_cbx_fsrrestore_t
#define bustype_BDK_SMMUX_CBX_FSRRESTORE(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_FSRRESTORE(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_FSRRESTORE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_FSRRESTORE(...) "SMMUX_CBX_FSRRESTORE"


/**
 * NCB32b - smmu#_cb#_fsynr0
 */
typedef union bdk_smmux_cbx_fsynr0 {
	uint32_t u;
	struct bdk_smmux_cbx_fsynr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t s1cbndx                     : 8;  /**< R/W/H - Stage 1 context bank index associated with the transaction that caused the fault. For
                                                                 nested translation, this field contains the stage 1 translation context bank index for
                                                                 processing the transaction. For stage 2 only translation, this field is UNKNOWN.
                                                                 This field is only present in a stage 2 format translation context bank. In a stage 1
                                                                 format translation context bank, it is UNKNOWN. */
		uint32_t reserved_12_15              : 4;
		uint32_t afr                         : 1;  /**< R/W/H - Asynchronous fault recorded.
                                                                 0 = A fault was recorded synchronously.
                                                                 1 = A fault was recorded asynchronously. */
		uint32_t ptwf                        : 1;  /**< R/W/H - A walk fault on a translation table access.
                                                                 0 = A walk fault did not occur.
                                                                 1 = A walk fault occurred during processing of a translation table walk. */
		uint32_t atof                        : 1;  /**< RO - Stage 2 address translation operation fault. ATOs not supported. */
		uint32_t nsattr                      : 1;  /**< R/W/H - Non-secure attribute.
                                                                 0 = The input transaction after SMMU()_S2CR()[NSCFG] had secure attribute.
                                                                 1 = The input transaction after SMMU()_S2CR()[NSCFG] had non-secure attribute. */
		uint32_t nsstate                     : 1;  /**< RO - Stage 2 non-secure state:
                                                                 0 = The transaction is associated with a secure client.
                                                                 1 = The transaction is associated with a non-secure client. */
		uint32_t ind                         : 1;  /**< R/W/H - Instruction, not data.
                                                                 0 = Data.
                                                                 1 = Instruction. */
		uint32_t pnu                         : 1;  /**< R/W/H - Privileged, not unprivileged.
                                                                 0 = Unprivileged.
                                                                 1 = Privileged. */
		uint32_t wnr                         : 1;  /**< R/W/H - Write, not read. */
		uint32_t s1ptwf                      : 1;  /**< R/W/H - Stage 2 walk fault during stage 2 translation of a stage 1 translation table walk. */
		uint32_t nested                      : 1;  /**< R/W/H - Indicates whether the fault is due to a nested stage 1 translation.
                                                                 0 = The fault is related to a stage 2 only translation.
                                                                 1 = The fault is related to a nested stage1 and stage 2 translation.

                                                                 When NESTED is set to zero:
                                                                 * SMMU()_CB()_FAR records the IPA that faulted at stage 2
                                                                 * SMMU()_CB()_FSYNR0[S1CBNDX] is UNKNOWN.
                                                                 * SMMU()_CB()_IPAFAR also records the IPA that faulted at stage 2

                                                                 When NESTED is set to one:
                                                                 * SMMU()_CB()_FAR records the virtual address of the requested translation.
                                                                 * SMMU()_CB()_FSYNR0[S1CBNDX] indicates the stage 1 context bank that caused the
                                                                 translation.
                                                                 * SMMU()_CB()_IPAFAR records the IPA that faulted at stage 2.
                                                                 This bit is RAZ/WI if SMMU()_IDR0[NTS] == 0. */
		uint32_t plvl                        : 2;  /**< R/W/H - Translation table level for fault.
                                                                 0 = Reserved.
                                                                 1 = level 1.
                                                                 2 = level 2.
                                                                 3 = level 3. */
#else
		uint32_t plvl                        : 2;
		uint32_t nested                      : 1;
		uint32_t s1ptwf                      : 1;
		uint32_t wnr                         : 1;
		uint32_t pnu                         : 1;
		uint32_t ind                         : 1;
		uint32_t nsstate                     : 1;
		uint32_t nsattr                      : 1;
		uint32_t atof                        : 1;
		uint32_t ptwf                        : 1;
		uint32_t afr                         : 1;
		uint32_t reserved_12_15              : 4;
		uint32_t s1cbndx                     : 8;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_smmux_cbx_fsynr0_s      cn88xx; */
	/* struct bdk_smmux_cbx_fsynr0_s      cn88xxp1; */
} bdk_smmux_cbx_fsynr0_t;

static inline uint64_t BDK_SMMUX_CBX_FSYNR0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSYNR0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000068ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_FSYNR0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_FSYNR0(...) bdk_smmux_cbx_fsynr0_t
#define bustype_BDK_SMMUX_CBX_FSYNR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_FSYNR0(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_FSYNR0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_FSYNR0(...) "SMMUX_CBX_FSYNR0"


/**
 * NCB32b - smmu#_cb#_fsynr1
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_cbx_fsynr1 {
	uint32_t u;
	struct bdk_smmux_cbx_fsynr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_cbx_fsynr1_s      cn88xx; */
	/* struct bdk_smmux_cbx_fsynr1_s      cn88xxp1; */
} bdk_smmux_cbx_fsynr1_t;

static inline uint64_t BDK_SMMUX_CBX_FSYNR1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_FSYNR1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x000083000100006Cull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_FSYNR1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_FSYNR1(...) bdk_smmux_cbx_fsynr1_t
#define bustype_BDK_SMMUX_CBX_FSYNR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_FSYNR1(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_FSYNR1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_FSYNR1(...) "SMMUX_CBX_FSYNR1"


/**
 * NCB - smmu#_cb#_ipafar
 *
 * IPA for a nested translation that faults in stage 2 (analogous to HPFAR in the processor).
 *
 */
typedef union bdk_smmux_cbx_ipafar {
	uint64_t u;
	struct bdk_smmux_cbx_ipafar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t faddr                       : 37; /**< RO/H - Fault address, the input address of the faulting access. This register might be updated as
                                                                 the result of a translation fault for an upstream client device. The least significant 12
                                                                 bits of this register are shared with SMMU()_CB()_FAR. */
		uint64_t reserved_0_11               : 12;
#else
		uint64_t reserved_0_11               : 12;
		uint64_t faddr                       : 37;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_smmux_cbx_ipafar_s      cn88xx; */
	/* struct bdk_smmux_cbx_ipafar_s      cn88xxp1; */
} bdk_smmux_cbx_ipafar_t;

static inline uint64_t BDK_SMMUX_CBX_IPAFAR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_IPAFAR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000070ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_IPAFAR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_IPAFAR(...) bdk_smmux_cbx_ipafar_t
#define bustype_BDK_SMMUX_CBX_IPAFAR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_IPAFAR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_IPAFAR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_IPAFAR(...) "SMMUX_CBX_IPAFAR"


/**
 * NCB32b - smmu#_cb#_mair0
 *
 * Provides a revised version of the TEX-Remap system to redirect the selection of memory
 * attributes from the translation table entries.
 * This register is used by stage 1 context banks.
 */
typedef union bdk_smmux_cbx_mair0 {
	uint32_t u;
	struct bdk_smmux_cbx_mair0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t attr3                       : 8;  /**< R/W - Memory attributes. */
		uint32_t attr2                       : 8;  /**< R/W - Memory attributes. */
		uint32_t attr1                       : 8;  /**< R/W - Memory attributes. */
		uint32_t attr0                       : 8;  /**< R/W - Memory attributes. */
#else
		uint32_t attr0                       : 8;
		uint32_t attr1                       : 8;
		uint32_t attr2                       : 8;
		uint32_t attr3                       : 8;
#endif
	} s;
	/* struct bdk_smmux_cbx_mair0_s       cn88xx; */
	/* struct bdk_smmux_cbx_mair0_s       cn88xxp1; */
} bdk_smmux_cbx_mair0_t;

static inline uint64_t BDK_SMMUX_CBX_MAIR0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_MAIR0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000038ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_MAIR0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_MAIR0(...) bdk_smmux_cbx_mair0_t
#define bustype_BDK_SMMUX_CBX_MAIR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_MAIR0(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_MAIR0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_MAIR0(...) "SMMUX_CBX_MAIR0"


/**
 * NCB32b - smmu#_cb#_mair1
 *
 * Provides a revised version of the TEX-Remap system to redirect the selection of memory
 * attributes from the translation table entries.
 * This register is used by stage 1 context banks.
 */
typedef union bdk_smmux_cbx_mair1 {
	uint32_t u;
	struct bdk_smmux_cbx_mair1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t attr7                       : 8;  /**< R/W - Memory attributes. */
		uint32_t attr6                       : 8;  /**< R/W - Memory attributes. */
		uint32_t attr5                       : 8;  /**< R/W - Memory attributes. */
		uint32_t attr4                       : 8;  /**< R/W - Memory attributes. */
#else
		uint32_t attr4                       : 8;
		uint32_t attr5                       : 8;
		uint32_t attr6                       : 8;
		uint32_t attr7                       : 8;
#endif
	} s;
	/* struct bdk_smmux_cbx_mair1_s       cn88xx; */
	/* struct bdk_smmux_cbx_mair1_s       cn88xxp1; */
} bdk_smmux_cbx_mair1_t;

static inline uint64_t BDK_SMMUX_CBX_MAIR1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_MAIR1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x000083000100003Cull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_MAIR1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_MAIR1(...) bdk_smmux_cbx_mair1_t
#define bustype_BDK_SMMUX_CBX_MAIR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_MAIR1(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_MAIR1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_MAIR1(...) "SMMUX_CBX_MAIR1"


/**
 * NCB32b - smmu#_cb#_resume
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_cbx_resume {
	uint32_t u;
	struct bdk_smmux_cbx_resume_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_cbx_resume_s      cn88xx; */
	/* struct bdk_smmux_cbx_resume_s      cn88xxp1; */
} bdk_smmux_cbx_resume_t;

static inline uint64_t BDK_SMMUX_CBX_RESUME(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_RESUME(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000008ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_RESUME", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_RESUME(...) bdk_smmux_cbx_resume_t
#define bustype_BDK_SMMUX_CBX_RESUME(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_RESUME(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_RESUME(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_RESUME(...) "SMMUX_CBX_RESUME"


/**
 * NCB32b - smmu#_cb#_sctlr
 *
 * Provides top-level control of the translation system for the related translation context bank.
 * This register is used by both stage 1 and stage 2 context banks.
 */
typedef union bdk_smmux_cbx_sctlr {
	uint32_t u;
	struct bdk_smmux_cbx_sctlr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t uci                         : 1;  /**< R/W - For stage 1, user cache maintenance operation enable.
                                                                 0 = User level cache maintenance operations are disabled.
                                                                 1 = User level cache maintenance operations are enabled.

                                                                 This field is ignored when SMMU()_CBA2R()[VA64] is zero.
                                                                 In CNXXXX TBD if needed.

                                                                 For stage 2, reserved. */
		uint32_t nscfg                       : 2;  /**< R/W - For stage 1, non-secure configuration. Controls the non-secure attribute for any
                                                                 transaction where the translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0. [NSCFG] only exists in a translation context bank
                                                                 reserved by secure software. In a non-secure translation context bank, this field is
                                                                 UNK/SBZP.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure.

                                                                 For stage 2, reserved. */
		uint32_t wacfg                       : 2;  /**< RO - Write-allocate configuration. Controls the allocation hint for write accesses where the
                                                                 translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
		uint32_t racfg                       : 2;  /**< RO - Read-allocate configuration. Controls the allocation hint for read accesses where the
                                                                 translation context bank translation is disabled. That is, where
                                                                 SMMU()_CB()_SCTLR[M]==0.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
		uint32_t shcfg                       : 2;  /**< RO - Shared configuration. Controls the sharable attribute of a transaction where the
                                                                 translation context bank is disabled.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
		uint32_t fb                          : 1;  /**< RAZ - For stage 1, force broadcast. Forces the broadcast of TLB maintenance operations. Ignored
                                                                 in CNXXXX, as NCB clients do not initiate invalidates.

                                                                 For stage 2, reserved. */
		uint32_t mtcfg                       : 1;  /**< R/W - For stage 1, memory type configuration. Applies to transactions when the translation
                                                                 context bank is disabled.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes.

                                                                 For stage 2, reserved. */
		uint32_t memattr                     : 4;  /**< R/W - Memory attributes for bypass transactions if MTCFG == 1. */
		uint32_t transcfg_bsu                : 2;  /**< RO - For stage 1, transient allocate configuration. Not implemented in CNXXXX.

                                                                 For stage 2, barrier sharability upgrade. Not implemented in CNXXXX. */
		uint32_t ptw                         : 1;  /**< R/W - For stage 1, reserved.

                                                                 For stage 2, protected translation walk for stage 1 followed by stage 2 translations:
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 2 permission fault if a stage 1 translation walk is to an area of memory
                                                                 that has the device or strongly-ordered memory attribute in the stage 2 translation
                                                                 tables. */
		uint32_t asidpne                     : 1;  /**< RO - For stage 1, address space identifier private namespace enable hint.
                                                                 0 = SMMU ASID values for this translation context bank are coordinated with wider
                                                                 system.
                                                                 1 = SMMU ASID values for this translation context bank are a private namespace not
                                                                 coordinated with the wider system.

                                                                 Hint ignored in CNXXXX, always system wide.

                                                                 For stage 2, reserved. */
		uint32_t reserved_11_11              : 1;
		uint32_t uwxn                        : 1;  /**< RO - For stage 1, unprivileged writable execute never.
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 1 permission fault if an instruction fetch occurs from a memory location
                                                                 that permits writes for unprivileged access.

                                                                 For stage 2, reserved.

                                                                 CNXXXX not implemented, no instruction stream. */
		uint32_t wxn                         : 1;  /**< RO - For stage 1, writable execute never.
                                                                 0 = This behavior is not enabled.
                                                                 1 = Raise a stage 1 permission fault if an instruction fetch occurs from a memory location
                                                                 that permits writes.

                                                                 For stage 2, reserved.

                                                                 CNXXXX not implemented, no instruction stream. */
		uint32_t hupcf                       : 1;  /**< RO - Hit under previous context fault.
                                                                 0 = Stall or terminate subsequent transactions in the presence of an outstanding context
                                                                 fault.
                                                                 1 = Process all subsequent transactions independently of any outstanding context fault.

                                                                 CNXXXX ignores, always processes. */
		uint32_t cfcfg                       : 1;  /**< RO - Context fault configuration.
                                                                 0 = Terminate.
                                                                 1 = Stall.

                                                                 CNXXXX ignores, always terminates. */
		uint32_t cfie                        : 1;  /**< R/W - Context fault interrupt enable.
                                                                 0 = Do not raise an interrupt when a context fault occurs.
                                                                 1 = Raise an interrupt when a context fault occurs. */
		uint32_t cfre                        : 1;  /**< R/W - Context fault report enable.
                                                                 0 = Do not return an abort when a context fault occurs.
                                                                 1 = Return an abort when a context fault occurs. */
		uint32_t ebig                        : 1;  /**< R/W - Endianness, indicates the endian format of translation tables.
                                                                 0 = Little endian.
                                                                 1 = Big endian. */
		uint32_t affd                        : 1;  /**< R/W - Access flag fault disable.
                                                                 0 = Access flag faults are enabled.
                                                                 1 = Access flag faults are disabled.

                                                                 In CNXXXX, TBD if this bit is cacheable in the TLB.

                                                                 It is expected that software will issue TLB maintenance operations if this bit is
                                                                 modified. If page tables are shared with the processor, then any descriptor with AF zero
                                                                 will not be held in a processor TLB entry. However, such descriptors might be held in SMMU
                                                                 TLBs. This means that page table maintenance software that changes descriptors must be
                                                                 aware that the old descriptor might be cached in the SMMU. */
		uint32_t afe                         : 1;  /**< RO - Access flag enable. In ARMv8 this bit has no effect and the SMMU behaves as if the
                                                                 bit were set. Software should treat this bit as UNK/SBOP. */
		uint32_t tre                         : 1;  /**< RO - TEX remap enable. In ARMv8 this bit has no effect. */
		uint32_t m                           : 1;  /**< R/W - MMU enable.
                                                                 0 = MMU behavior for this translation context bank is disabled.
                                                                 1 = MMU behavior for this translation context bank is enabled. */
#else
		uint32_t m                           : 1;
		uint32_t tre                         : 1;
		uint32_t afe                         : 1;
		uint32_t affd                        : 1;
		uint32_t ebig                        : 1;
		uint32_t cfre                        : 1;
		uint32_t cfie                        : 1;
		uint32_t cfcfg                       : 1;
		uint32_t hupcf                       : 1;
		uint32_t wxn                         : 1;
		uint32_t uwxn                        : 1;
		uint32_t reserved_11_11              : 1;
		uint32_t asidpne                     : 1;
		uint32_t ptw                         : 1;
		uint32_t transcfg_bsu                : 2;
		uint32_t memattr                     : 4;
		uint32_t mtcfg                       : 1;
		uint32_t fb                          : 1;
		uint32_t shcfg                       : 2;
		uint32_t racfg                       : 2;
		uint32_t wacfg                       : 2;
		uint32_t nscfg                       : 2;
		uint32_t uci                         : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_smmux_cbx_sctlr_s       cn88xx; */
	/* struct bdk_smmux_cbx_sctlr_s       cn88xxp1; */
} bdk_smmux_cbx_sctlr_t;

static inline uint64_t BDK_SMMUX_CBX_SCTLR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_SCTLR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000000ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_SCTLR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_SCTLR(...) bdk_smmux_cbx_sctlr_t
#define bustype_BDK_SMMUX_CBX_SCTLR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_SCTLR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_SCTLR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_SCTLR(...) "SMMUX_CBX_SCTLR"


/**
 * NCB32b - smmu#_cb#_tcr
 */
typedef union bdk_smmux_cbx_tcr {
	uint32_t u;
	struct bdk_smmux_cbx_tcr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tg1                         : 2;  /**< R/W - For stage 1, page size granule for TTBR1.
                                                                 0x0 = Reserved
                                                                 0x1 = 16 KB page granule.
                                                                 0x2 = 4 KB page granule.
                                                                 0x3 = 64 KB page granule.

                                                                 Note the encoding is different from the [TG0] encoding.
                                                                 For stage 2, reserved. */
		uint32_t sh1                         : 2;  /**< R/W - For stage 1, sharability attributes for the memory associated with the translation table
                                                                 walks using TTBR1.

                                                                 For stage 2, reserved. */
		uint32_t orgn1                       : 2;  /**< R/W - For stage 1, outer cachability attributes for TTBR1 table walks.

                                                                 For stage 2, reserved. */
		uint32_t irgn1                       : 2;  /**< R/W - For stage 1, inner cachability attributes for TTBR1 table walks.

                                                                 For stage 2, reserved. */
		uint32_t epd1                        : 1;  /**< R/W - For stage 1, Translation walk disable for TTBR1 region. This bit controls whether a
                                                                 translation table walk is performed on a TLB miss when SMMU()_CB()_TTBR1 is
                                                                 used:
                                                                 0 = If a TLB miss occurs when TTBR1 is used a translation table walk is performed.
                                                                 1 = If a TLB miss occurs when TTBR1 is used no translation table walk is performed and a
                                                                 L1 Translation fault is returned.

                                                                 For stage 2, reserved. */
		uint32_t a1                          : 1;  /**< R/W - For stage 1, select ASID from TTBRn register.
                                                                 0 = Select ASID from SMMU()_CB()_TTBR0.
                                                                 1 = Select ASID from SMMU()_CB()_TTBR1.

                                                                 For stage 2, reserved. */
		uint32_t t1sz_pasize                 : 6;  /**< R/W - For stage 1, \<21:16\> is size offset of the SMMU()_CB()_TCR addressed region,
                                                                 encoded as a six-bit unsigned number, giving the size of the region as 2^(64-T1SZ).

                                                                 For stage 2, \<21:19\> is reserved, \<18:16\> is PASize, the size of the physical address
                                                                 (i.e. the output address):
                                                                 0x0 = 32 bits (4 GBytes).
                                                                 0x1 = 36 bits (64 GBytes).
                                                                 0x2 = 40 bits (1 TByte).
                                                                 0x3 = 42 bits (4 TByte).
                                                                 0x4 = 44 bits (16 TByte).
                                                                 0x5 = 48 bits (256 TByte).
                                                                 0x6-0x7 = Reserved. Treat as 48 bits. */
		uint32_t tg0                         : 2;  /**< R/W - Page size granule for TTBR0.
                                                                 0x0 = 4 KB page granule.
                                                                 0x1 = 64 KB page granule.
                                                                 0x2 = 16 KB page granule.
                                                                 0x3 = Reserved.

                                                                 Note the encoding is different from the [TG1] encoding. */
		uint32_t sh0                         : 2;  /**< R/W - Sharability attributes for the memory associated with the translation table walks using TTBR0. */
		uint32_t orgn0                       : 2;  /**< RO - Outer cachability attributes for TTBR0 table walks.
                                                                 Ignored in CNXXXX. */
		uint32_t irgn0                       : 2;  /**< RO - Inner cachability attributes for TTBR0 table walks.
                                                                 Ignored in CNXXXX. */
		uint32_t epd0_sl0                    : 2;  /**< R/W - For stage 1, \<6\> is reserved. \<7\> is EPD0, translation walk disable for TTBR0 region. This
                                                                 bit is RES0 for hypervisor and monitor contexts. This bit controls whether a translation
                                                                 table walk is performed on a TLB miss when TTBR0 is used:
                                                                 0 = If aTLB miss occurs when TTBR0 is used a translation table walk is performed.
                                                                 1 = If a TLB miss occurs when TTBR0 is used no translation table walk is performed and a
                                                                 L1 Translation fault is returned.

                                                                 For stage 2, \<7:6\> is SL0, starting level of the addressed regions. For 4kB page granule
                                                                 size (TG0 == 0):
                                                                 0 = Level 2.
                                                                 1 = Level 1.
                                                                 2 = Level 0.
                                                                 3 = Reserved.

                                                                 For 64kB page granule size (TG0 == 1):
                                                                 0 = Level 3.
                                                                 1 = Level 2.
                                                                 2 = Level 1.
                                                                 3 = Reserved. */
		uint32_t t0sz                        : 6;  /**< R/W - Size offset of the TTBR0 addressed region, encoded as a six-bit unsigned number giving the
                                                                 size of the region as 2^(64-T0SZ). */
#else
		uint32_t t0sz                        : 6;
		uint32_t epd0_sl0                    : 2;
		uint32_t irgn0                       : 2;
		uint32_t orgn0                       : 2;
		uint32_t sh0                         : 2;
		uint32_t tg0                         : 2;
		uint32_t t1sz_pasize                 : 6;
		uint32_t a1                          : 1;
		uint32_t epd1                        : 1;
		uint32_t irgn1                       : 2;
		uint32_t orgn1                       : 2;
		uint32_t sh1                         : 2;
		uint32_t tg1                         : 2;
#endif
	} s;
	/* struct bdk_smmux_cbx_tcr_s         cn88xx; */
	/* struct bdk_smmux_cbx_tcr_s         cn88xxp1; */
} bdk_smmux_cbx_tcr_t;

static inline uint64_t BDK_SMMUX_CBX_TCR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TCR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000030ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TCR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TCR(...) bdk_smmux_cbx_tcr_t
#define bustype_BDK_SMMUX_CBX_TCR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_TCR(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TCR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TCR(...) "SMMUX_CBX_TCR"


/**
 * NCB32b - smmu#_cb#_tcr2
 */
typedef union bdk_smmux_cbx_tcr2 {
	uint32_t u;
	struct bdk_smmux_cbx_tcr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t nscfg1                      : 1;  /**< R/W - Non-secure attribute for the memory associated with translation table walks using
                                                                 SMMU()_CB()_TTBR1. This field only applies for secure owned context banks,
                                                                 otherwise this field is ignored. */
		uint32_t reserved_18_29              : 12;
		uint32_t sep                         : 3;  /**< R/W - Sign extension position. The bit position from which to sign-extend the stage 1 input
                                                                 address when required.
                                                                 0x0 = Bit [31].
                                                                 0x1 = Bit [35].
                                                                 0x2 = Bit [39].
                                                                 0x3 = Bit [41].
                                                                 0x4 = Bit [43].
                                                                 0x5 = Bit [47].
                                                                 0x6 = Reserved. This must be treated as 0x7.
                                                                 0x7 = Explicit sign bit provided by device (as bit [48]). If bit[48] is not provided it is
                                                                 treated as zero.

                                                                 If SEP specifies a bit above that implemented on the upstream input address bus, addresses
                                                                 will be zero-extended. Sign-extension does not apply to address translation operations.
                                                                 For hypervisor and monitor contexts this field is ignored.

                                                                 If the value of SEP is changed, then software must invalidate any affected TLB entries. */
		uint32_t nscfg0                      : 1;  /**< R/W - Non-secure attribute for the memory associated with translation table walks using
                                                                 SMMU()_CB()_TTBR0. This field only applies for secure owned context banks,
                                                                 otherwise this field is ignored. */
		uint32_t reserved_10_13              : 4;
		uint32_t had1                        : 1;  /**< R/W - Hierarchical attribute disable 1 for the TTBR1 region. Similar to [HAD0]. */
		uint32_t had0                        : 1;  /**< R/W - For stage 1, hierarchical attribute disable 0 for the TTBR0 region.
                                                                 This field is ignored as not supported when SMMU()_IDR2[HADS] is zero.
                                                                 This field is ignored when SMMU()_CBA2R()[VA64] is zero.
                                                                 0 = Hierarchical attributes are enabled.
                                                                 1 = Hierarchical attributes are disabled.

                                                                 For stage 2, reserved. */
		uint32_t reserved_7_7                : 1;
		uint32_t tbi1                        : 1;  /**< R/W - Top byte ignored. Indicates whether the top byte of the input address should be used for
                                                                 address match for the TTBR1 region. */
		uint32_t tbi0                        : 1;  /**< R/W - Top byte ignored. Indicates whether the top byte of the input address should be used for
                                                                 address match for the TTBR0 region. */
		uint32_t as                          : 1;  /**< R/W - ASID Size.
                                                                 0 = 8 bit. Note: 8 bit ASIDs are zero extended to 16 bits for all TLB matching purposes.
                                                                 1 = 16 bit. */
		uint32_t reserved_3_3                : 1;
		uint32_t pasize                      : 3;  /**< R/W - The size of the physical address:
                                                                 0x0 = 32 bits (4 GBytes).
                                                                 0x1 = 36 bits (64 GBytes).
                                                                 0x2 = 40 bits (1 TByte).
                                                                 0x3 = 42 bits (4 TByte).
                                                                 0x4 = 44 bits (16 TByte).
                                                                 0x5 = 48 bits (256 TByte).
                                                                 0x6-0x7. Reserved. Treat as 48 bits. */
#else
		uint32_t pasize                      : 3;
		uint32_t reserved_3_3                : 1;
		uint32_t as                          : 1;
		uint32_t tbi0                        : 1;
		uint32_t tbi1                        : 1;
		uint32_t reserved_7_7                : 1;
		uint32_t had0                        : 1;
		uint32_t had1                        : 1;
		uint32_t reserved_10_13              : 4;
		uint32_t nscfg0                      : 1;
		uint32_t sep                         : 3;
		uint32_t reserved_18_29              : 12;
		uint32_t nscfg1                      : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_smmux_cbx_tcr2_s        cn88xx; */
	/* struct bdk_smmux_cbx_tcr2_s        cn88xxp1; */
} bdk_smmux_cbx_tcr2_t;

static inline uint64_t BDK_SMMUX_CBX_TCR2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TCR2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000010ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TCR2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TCR2(...) bdk_smmux_cbx_tcr2_t
#define bustype_BDK_SMMUX_CBX_TCR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_TCR2(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TCR2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TCR2(...) "SMMUX_CBX_TCR2"


/**
 * NCB32b - smmu#_cb#_tlbiall
 *
 * Invalidates all of the TLB entries, and only has to apply to TLB entries associated with the
 * VMID used for the stage 1 translation context bank. If SMMU()_CBAR()[HYPC] has the
 * value 1, this operation only has to apply to TLB entries associated with hypervisor contexts.
 * if SMMU()_CBAR()[MONC] has the value 1, this operation only has to apply to TLB
 * entries associated with monitor contexts. The VMID is therefore irrelevant to the operation.
 * This operation only has to apply to TLB entries associated with the security domain that the
 * Stage 1 translation context bank is a member of.
 * Register fields are identical to those in SMMU()_TLBIALLH.
 */
typedef union bdk_smmux_cbx_tlbiall {
	uint32_t u;
	struct bdk_smmux_cbx_tlbiall_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< WO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbiall_s     cn88xx; */
	/* struct bdk_smmux_cbx_tlbiall_s     cn88xxp1; */
} bdk_smmux_cbx_tlbiall_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIALL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIALL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000618ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIALL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIALL(...) bdk_smmux_cbx_tlbiall_t
#define bustype_BDK_SMMUX_CBX_TLBIALL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_TLBIALL(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIALL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIALL(...) "SMMUX_CBX_TLBIALL"


/**
 * NCB32b - smmu#_cb#_tlbiasid
 *
 * Invalidates all of the TLB entries that match the ASID provided as an argument. This operation
 * only has to apply to non-global TLB entries that match the VMID used for the stage 1
 * translation context bank.For MONC and HYPC contexts, this operation has no effect and ignored.
 * This operation only has to apply to TLBentries associated with the security domain that the
 * Stage 1 translation context bank is a member of.
 */
typedef union bdk_smmux_cbx_tlbiasid {
	uint32_t u;
	struct bdk_smmux_cbx_tlbiasid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t asid                        : 16; /**< WO - ASID to invalidate. */
#else
		uint32_t asid                        : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbiasid_s    cn88xx; */
	/* struct bdk_smmux_cbx_tlbiasid_s    cn88xxp1; */
} bdk_smmux_cbx_tlbiasid_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIASID(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIASID(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000610ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIASID", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIASID(...) bdk_smmux_cbx_tlbiasid_t
#define bustype_BDK_SMMUX_CBX_TLBIASID(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_TLBIASID(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIASID(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIASID(...) "SMMUX_CBX_TLBIASID"


/**
 * NCB - smmu#_cb#_tlbiipas2
 *
 * Invalidates all TLB entries that  match the specified IPA. this operation does not need to
 * apply to caching structures that combines both stage 1 and stage 2 translation table entries,
 * but must apply to caching structures that contain information only from stage 2 translation
 * table entries. For those implementations that choose to store the IPA in a combined stage 1
 * and stage 2 TLB entry, this operation is only required to match those entries that have the
 * same VMID as specified by the stage 2 bank.
 * An incoming transaction directed at an S2 context might result in S2-only TLB entries which
 * will be affected by this operation.
 * However, an incoming transaction directed to a S1 + S2 nested context might result in S1+S2
 * TLB entries. Such entries might not be affected by this operation. Thus in order to change a
 * Stage 2 page table entry then software must invalidate all stage 1 contexts (using an
 * SMMU()_TLBIVMIDS1 operation).
 */
typedef union bdk_smmux_cbx_tlbiipas2 {
	uint64_t u;
	struct bdk_smmux_cbx_tlbiipas2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t address                     : 36; /**< WO - IPA\<47:12\> to be invalidated. Note this matches the format of the address supplied to
                                                                 ARMv8 processor TLB invalidation instructions. If the page size for stage 2 is 64kB then
                                                                 bits corresponding to address\<15:12\> are ignored. */
#else
		uint64_t address                     : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbiipas2_s   cn88xx; */
	/* struct bdk_smmux_cbx_tlbiipas2_s   cn88xxp1; */
} bdk_smmux_cbx_tlbiipas2_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000630ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIIPAS2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIIPAS2(...) bdk_smmux_cbx_tlbiipas2_t
#define bustype_BDK_SMMUX_CBX_TLBIIPAS2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TLBIIPAS2(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIIPAS2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIIPAS2(...) "SMMUX_CBX_TLBIIPAS2"


/**
 * NCB - smmu#_cb#_tlbiipas2l
 *
 * Operates exactly as SMMU()_CB()_TLBIIPAS2, but only invalidating those that
 * correspond to the last level of the translation table walk.
 */
typedef union bdk_smmux_cbx_tlbiipas2l {
	uint64_t u;
	struct bdk_smmux_cbx_tlbiipas2l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t address                     : 36; /**< WO - IPA\<47:12\> to be invalidated. Note this matches the format of the address supplied to
                                                                 ARMv8 processor TLB invalidation instructions. If the page size for stage 2 is 64kB then
                                                                 bits corresponding to address\<15:12\> are ignored. */
#else
		uint64_t address                     : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbiipas2l_s  cn88xx; */
	/* struct bdk_smmux_cbx_tlbiipas2l_s  cn88xxp1; */
} bdk_smmux_cbx_tlbiipas2l_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2L(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIIPAS2L(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000638ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIIPAS2L", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIIPAS2L(...) bdk_smmux_cbx_tlbiipas2l_t
#define bustype_BDK_SMMUX_CBX_TLBIIPAS2L(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TLBIIPAS2L(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIIPAS2L(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIIPAS2L(...) "SMMUX_CBX_TLBIIPAS2L"


/**
 * NCB - smmu#_cb#_tlbiva
 *
 * Invalidates all of the TLB entries that match the VA and ASID provided as arguments. This
 * operation only applies to TLB entries associated with the VMID used for a stage 1 translation
 * context bank. The ASID is not checked for global entries in the TLB. If
 * SMMU()_CBAR()[HYPC] is set, this operation only applies to TLB entries associated
 * with hypervisor contexts. The VMID and ASID are therefore irrelevant to the operation. This
 * operation only applies to TLB entries associated with the security domain that the stage 1
 * translation context bank is a member of.
 */
typedef union bdk_smmux_cbx_tlbiva {
	uint64_t u;
	struct bdk_smmux_cbx_tlbiva_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< WO - ASID for which the TLB invalidation should be performed. */
		uint64_t reserved_44_47              : 4;
		uint64_t address                     : 44; /**< WO - Address\<55:12\> to be invalidated. Note this matches the format of the address supplied to
                                                                 the ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then the bits
                                                                 corresponding to address\<15:12\> are ignored. The address will be extended to bit \<63\> by
                                                                 copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_47              : 4;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbiva_s      cn88xx; */
	/* struct bdk_smmux_cbx_tlbiva_s      cn88xxp1; */
} bdk_smmux_cbx_tlbiva_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVA(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVA(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000600ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIVA", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIVA(...) bdk_smmux_cbx_tlbiva_t
#define bustype_BDK_SMMUX_CBX_TLBIVA(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TLBIVA(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIVA(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIVA(...) "SMMUX_CBX_TLBIVA"


/**
 * NCB - smmu#_cb#_tlbivaa
 *
 * Invalidates all of the TLB entries that match the VA provided as an argument, regardless of
 * the ASID. This operation only has to apply to TLB entries associated with the VMID used for a
 * Stage 1 translation context bank. If SMMU()_CBAR()[HYPC] is set, this operation is
 * unpredictable. This operation only has to apply to TLB entries associated with the security
 * domain that the stage 1 translation context bank is a member of.
 * Register fields are identical to those in SMMU()_TLBIVAH64.
 */
typedef union bdk_smmux_cbx_tlbivaa {
	uint64_t u;
	struct bdk_smmux_cbx_tlbivaa_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t address                     : 44; /**< WO - Virtual address \<55:12\> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS\<15:12\> are ignored. The address will be extended to bit \<63\>
                                                                 by copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbivaa_s     cn88xx; */
	/* struct bdk_smmux_cbx_tlbivaa_s     cn88xxp1; */
} bdk_smmux_cbx_tlbivaa_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVAA(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVAA(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000608ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIVAA", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIVAA(...) bdk_smmux_cbx_tlbivaa_t
#define bustype_BDK_SMMUX_CBX_TLBIVAA(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TLBIVAA(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIVAA(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIVAA(...) "SMMUX_CBX_TLBIVAA"


/**
 * NCB - smmu#_cb#_tlbivaal
 *
 * Operates exactly as SMMU()_CB()_TLBIVAA, but only invalidating those that correspond
 * to the last level of the translation table walk.
 */
typedef union bdk_smmux_cbx_tlbivaal {
	uint64_t u;
	struct bdk_smmux_cbx_tlbivaal_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t address                     : 44; /**< WO - Virtual address \<55:12\> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS\<15:12\> are ignored. The address will be extended to bit \<63\>
                                                                 by copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbivaal_s    cn88xx; */
	/* struct bdk_smmux_cbx_tlbivaal_s    cn88xxp1; */
} bdk_smmux_cbx_tlbivaal_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVAAL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVAAL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000628ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIVAAL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIVAAL(...) bdk_smmux_cbx_tlbivaal_t
#define bustype_BDK_SMMUX_CBX_TLBIVAAL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TLBIVAAL(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIVAAL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIVAAL(...) "SMMUX_CBX_TLBIVAAL"


/**
 * NCB - smmu#_cb#_tlbival
 *
 * Operates exactly as SMMU()_CB()_TLBIVA, but only invalidating those that correspond
 * to the last level of the translation table walk.
 */
typedef union bdk_smmux_cbx_tlbival {
	uint64_t u;
	struct bdk_smmux_cbx_tlbival_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< WO - ASID for which the TLB invalidation should be performed. */
		uint64_t reserved_44_47              : 4;
		uint64_t address                     : 44; /**< WO - Address\<55:12\> to be invalidated. Note this matches the format of the address supplied to
                                                                 the ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then the bits
                                                                 corresponding to address\<15:12\> are ignored. The address will be extended to bit \<63\> by
                                                                 copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_47              : 4;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbival_s     cn88xx; */
	/* struct bdk_smmux_cbx_tlbival_s     cn88xxp1; */
} bdk_smmux_cbx_tlbival_t;

static inline uint64_t BDK_SMMUX_CBX_TLBIVAL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBIVAL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000620ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBIVAL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBIVAL(...) bdk_smmux_cbx_tlbival_t
#define bustype_BDK_SMMUX_CBX_TLBIVAL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TLBIVAL(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBIVAL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBIVAL(...) "SMMUX_CBX_TLBIVAL"


/**
 * NCB32b - smmu#_cb#_tlbstatus
 *
 * Gives the status of a TLB maintenance operation. Register fields are identical to those in
 * SMMU(0..3)_(S)TLBGSTATUS.
 */
typedef union bdk_smmux_cbx_tlbstatus {
	uint32_t u;
	struct bdk_smmux_cbx_tlbstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t gsactive                    : 1;  /**< RO/H - Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
#else
		uint32_t gsactive                    : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbstatus_s   cn88xx; */
	/* struct bdk_smmux_cbx_tlbstatus_s   cn88xxp1; */
} bdk_smmux_cbx_tlbstatus_t;

static inline uint64_t BDK_SMMUX_CBX_TLBSTATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBSTATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x00008300010007F4ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBSTATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBSTATUS(...) bdk_smmux_cbx_tlbstatus_t
#define bustype_BDK_SMMUX_CBX_TLBSTATUS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_TLBSTATUS(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBSTATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBSTATUS(...) "SMMUX_CBX_TLBSTATUS"


/**
 * NCB32b - smmu#_cb#_tlbsync
 *
 * Starts a context synchronization operation that ensures the completion of any previously
 * accepted TLB Invalidate operation. Register fields are identical to those in
 * SMMU(0..3)_(S)TLBGSYNC.
 */
typedef union bdk_smmux_cbx_tlbsync {
	uint32_t u;
	struct bdk_smmux_cbx_tlbsync_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< WO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_cbx_tlbsync_s     cn88xx; */
	/* struct bdk_smmux_cbx_tlbsync_s     cn88xxp1; */
} bdk_smmux_cbx_tlbsync_t;

static inline uint64_t BDK_SMMUX_CBX_TLBSYNC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TLBSYNC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x00008300010007F0ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TLBSYNC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TLBSYNC(...) bdk_smmux_cbx_tlbsync_t
#define bustype_BDK_SMMUX_CBX_TLBSYNC(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBX_TLBSYNC(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TLBSYNC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TLBSYNC(...) "SMMUX_CBX_TLBSYNC"


/**
 * NCB - smmu#_cb#_ttbr0
 *
 * Holds the base address of translation tables. This register is used by both stage 1 and stage
 * 2 context banks.
 */
typedef union bdk_smmux_cbx_ttbr0 {
	uint64_t u;
	struct bdk_smmux_cbx_ttbr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< R/W - Address space ID associated with this base address. The selection between
                                                                 SMMU()_CB()_TTBR0[ASID] and SMMU()_CB()_TTBR1[ASID] is determined by
                                                                 SMMU()_CB()_TCR[A1]. Bits [15:8] are only valid if
                                                                 SMMU()_CB()_TCR2[AS] ==1 and RES0 otherwise. */
		uint64_t addr                        : 44; /**< R/W - Translation table base address. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t addr                        : 44;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_smmux_cbx_ttbr0_s       cn88xx; */
	/* struct bdk_smmux_cbx_ttbr0_s       cn88xxp1; */
} bdk_smmux_cbx_ttbr0_t;

static inline uint64_t BDK_SMMUX_CBX_TTBR0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TTBR0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000020ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TTBR0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TTBR0(...) bdk_smmux_cbx_ttbr0_t
#define bustype_BDK_SMMUX_CBX_TTBR0(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TTBR0(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TTBR0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TTBR0(...) "SMMUX_CBX_TTBR0"


/**
 * NCB - smmu#_cb#_ttbr1
 *
 * Holds the base address of translation tables. This register is used by stage 1 context banks.
 * Register fields are identical to those in SMMU()_CB()_TTBR0.
 */
typedef union bdk_smmux_cbx_ttbr1 {
	uint64_t u;
	struct bdk_smmux_cbx_ttbr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t asid                        : 16; /**< R/W - Address space ID associated with this base address. The selection between
                                                                 SMMU()_CB()_TTBR0[ASID] and SMMU()_CB()_TTBR1[ASID] is determined by
                                                                 SMMU()_CB()_TCR[A1]. Bits [15:8] are only valid if
                                                                 SMMU()_CB()_TCR2[AS] ==1 and RES0 otherwise. */
		uint64_t addr                        : 44; /**< R/W - Translation table base address. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t addr                        : 44;
		uint64_t asid                        : 16;
#endif
	} s;
	/* struct bdk_smmux_cbx_ttbr1_s       cn88xx; */
	/* struct bdk_smmux_cbx_ttbr1_s       cn88xxp1; */
} bdk_smmux_cbx_ttbr1_t;

static inline uint64_t BDK_SMMUX_CBX_TTBR1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBX_TTBR1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830001000028ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x10000ull;
	csr_fatal("BDK_SMMUX_CBX_TTBR1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBX_TTBR1(...) bdk_smmux_cbx_ttbr1_t
#define bustype_BDK_SMMUX_CBX_TTBR1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_CBX_TTBR1(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBX_TTBR1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBX_TTBR1(...) "SMMUX_CBX_TTBR1"


/**
 * NCB32b - smmu#_cba2r#
 *
 * Extended attributes for context bank n.
 *
 */
typedef union bdk_smmux_cba2rx {
	uint32_t u;
	struct bdk_smmux_cba2rx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vmid                        : 16; /**< R/W/H - Virtual machine identifier. Writes to SMMU()_CBAR()[VMID] also update this field
                                                                 by zeroing the upper 8 bits. */
		uint32_t reserved_3_15               : 13;
		uint32_t e2hc                        : 1;  /**< R/W - Virtualization host support enable.
                                                                 Must be clear if SMMU()_IDR2[E2HCS] is clear.
                                                                 The value of this bit is ignored unless the context bank is configured as AArch64,
                                                                 non-HYPC, non-MONC and stage 1 + stage 2 bypass.

                                                                 If set, then SMMU()_S2CR()[VMID] is ignored for all purposes except reading back
                                                                 of the value written.  The context bank must be tagged by ASID + E2H rather than ASID +
                                                                 VMID.

                                                                 If set, broadcast TLBI operations targeting hypervisor contexts that do not include an
                                                                 ASID target all E2H entries independent of ASID (for example, this is equivalent to
                                                                 TLBIVAA if the message also matches a VA).

                                                                 If set, the context bank is not considered to be a HYPC context except for the purposes of
                                                                 broadcast TLBI operations and writes to the TLB invalidate hypervisor registers in global
                                                                 register space 0.  In addition, because TLB entries are not tagged by VMID, then TLBI
                                                                 operations that include a VMID do not affect any TLB entries tagged with ASID + E2H.  Thus
                                                                 the ASID space tagged with E2H is unrelated to any other ASID space; for example there is
                                                                 no relationship between ASID0 in an E2HC bank and ASID0 in a VMID0 context.

                                                                 This feature can be used for secure hypervisor contexts, but the TLB entries are not
                                                                 required to be tagged by secure or non-secure and the warnings about allowing non-secure
                                                                 SW to configure hypervisor contexts still apply.

                                                                 If a context bank changes its security state, it is recommended that this bit is reset by
                                                                 software. */
		uint32_t monc                        : 1;  /**< R/W - Designates a secure monitor context bank (EL3). Ignored if the bank is non-secure. */
		uint32_t va64                        : 1;  /**< RO - Descriptor format. If set, only AArch64 translations are permitted.
                                                                 For CNXXXX always set; ARM defines this as R/W to allow for 32-bit V7 format. */
#else
		uint32_t va64                        : 1;
		uint32_t monc                        : 1;
		uint32_t e2hc                        : 1;
		uint32_t reserved_3_15               : 13;
		uint32_t vmid                        : 16;
#endif
	} s;
	/* struct bdk_smmux_cba2rx_s          cn88xx; */
	/* struct bdk_smmux_cba2rx_s          cn88xxp1; */
} bdk_smmux_cba2rx_t;

static inline uint64_t BDK_SMMUX_CBA2RX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBA2RX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830000010800ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x4ull;
	csr_fatal("BDK_SMMUX_CBA2RX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBA2RX(...) bdk_smmux_cba2rx_t
#define bustype_BDK_SMMUX_CBA2RX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBA2RX(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBA2RX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBA2RX(...) "SMMUX_CBA2RX"


/**
 * NCB32b - smmu#_cbar#
 *
 * Specifies configuration attributes for translation context bank n. This field has different
 * layouts based on the CTYPE field value.
 */
typedef union bdk_smmux_cbarx {
	uint32_t u;
	struct bdk_smmux_cbarx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t wacfg                       : 2;  /**< RO - If CTYPE=1 or 3, write allocate configuration hint.

                                                                 If CTYPE=0/2, reserved.

                                                                 CNXXXX ignores the hint. INTERNAL: Requested filed with ARM to make RO. */
		uint32_t racfg                       : 2;  /**< RO - If CTYPE=1 or 3, read allocate configuration hint.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 CNXXXX ignores the hint. INTERNAL: Requested filed with ARM to make RO. */
		uint32_t bsu                         : 2;  /**< RO - Barrier sharability upgrade. Not implemented in CNXXXX. */
		uint32_t ctype                       : 2;  /**< R/W - Register type.   Indicates the context format. Enumerated by SMMU_CTYPE_E. */
		uint32_t memattr_cbndx4              : 4;  /**< R/W - Memory attributes, or context bank index \<7:4\>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, combined with the shared attributes of the previous translation stage.

                                                                 If CTYPE=3, context bank index \<7:4\>, see [BPSHCFG_CNBDX0]. */
		uint32_t fb_cbndx3                   : 1;  /**< R/W - Force broadcast of TLB and cache maintenance operations or context bank index\<3\>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, force broadcast mode. Ignored in CNXXXX, as NCB clients do not initiate
                                                                 invalidates.

                                                                 If CTYPE=3, context bank index \<3\>, see [BPSHCFG_CNBDX0]. */
		uint32_t hypc_cbndx2                 : 1;  /**< R/W - Hypervisor context or context bank index \<2\>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, hypervisor context.
                                                                 0 = Non-hypervisor context. Use VMID and ASID for TLB tagging.
                                                                 1 = Hypervisor context. Do not use VMID and ASID for TLB tagging.

                                                                 In an interaction with the security extensions, the following restrictions apply to secure
                                                                 software: If SMMU()_SCR1[GASRAE]=0, Secure software must not set HYPC to 1 for any
                                                                 secure translation context bank. If SMMU()_SCR1[GASRAE]=1, Secure software must not
                                                                 set HYPC to 1 for any non-secure translation context bank. Otherwise, UNPREDICTABLE
                                                                 behavior might occur.

                                                                 If CTYPE=3, context bank index \<2\>, see [BPSHCFG_CNBDX0]. */
		uint32_t bpshcfg_cbndx0              : 2;  /**< R/W - Bypass shared configuration or context bank index \<1:0\>.

                                                                 If CTYPE=0 or 2, reserved.

                                                                 If CTYPE=1, bypass shared configuration mode. CNXXXX ignores the value, R/W for software
                                                                 only.

                                                                 If CTYPE=3, context bank index \<1:0\>. The translation context bank index used for the
                                                                 stage 2 translation context bank in a nested translation. The full 8-bit context bank
                                                                 index is shared between the [MEMATTR_CBNDX4], [FB_CBNDX3], [HYPC_CBNDX2] and
                                                                 [BPSHCFG_CBNDX0] fields. Behavior is UNPREDICTABLE if the SMMU()_CBAR() register
                                                                 associated with the translation context specified by SMMU()_CBAR()[CBNDX] has
                                                                 any value other than 0x0 to specify a stage 2 translation context bank.) */
		uint32_t vmid                        : 8;  /**< R/W/H - Virtual machine identifier associated with context bank. Contains the low 8 bits of
                                                                 SMMU()_CBA2R()[VMID]. Writes to this field are zero extended into
                                                                 SMMU()_CBA2R()[VMID]. */
#else
		uint32_t vmid                        : 8;
		uint32_t bpshcfg_cbndx0              : 2;
		uint32_t hypc_cbndx2                 : 1;
		uint32_t fb_cbndx3                   : 1;
		uint32_t memattr_cbndx4              : 4;
		uint32_t ctype                       : 2;
		uint32_t bsu                         : 2;
		uint32_t racfg                       : 2;
		uint32_t wacfg                       : 2;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_smmux_cbarx_s           cn88xx; */
	/* struct bdk_smmux_cbarx_s           cn88xxp1; */
} bdk_smmux_cbarx_t;

static inline uint64_t BDK_SMMUX_CBARX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBARX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830000010000ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x4ull;
	csr_fatal("BDK_SMMUX_CBARX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBARX(...) bdk_smmux_cbarx_t
#define bustype_BDK_SMMUX_CBARX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBARX(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBARX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBARX(...) "SMMUX_CBARX"


/**
 * NCB32b - smmu#_cbfrsynra#
 *
 * Gives fault syndrome information about the access that caused an exception in the associated
 * translation.
 */
typedef union bdk_smmux_cbfrsynrax {
	uint32_t u;
	struct bdk_smmux_cbfrsynrax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ssd_index                   : 16; /**< SRO/H - SSD index of the transaction that caused the fault. Only accessible to configuration
                                                                 accesses by secure software, else RAZ/WI. For CNXXXX, set on a fault to always match
                                                                 STREAMID. INTERNAL: Requested ARM extend this into \<31\>. */
		uint32_t streamid                    : 16; /**< R/W/H - Stream ID of the transaction that caused the fault. */
#else
		uint32_t streamid                    : 16;
		uint32_t ssd_index                   : 16;
#endif
	} s;
	/* struct bdk_smmux_cbfrsynrax_s      cn88xx; */
	/* struct bdk_smmux_cbfrsynrax_s      cn88xxp1; */
} bdk_smmux_cbfrsynrax_t;

static inline uint64_t BDK_SMMUX_CBFRSYNRAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CBFRSYNRAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830000010400ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x4ull;
	csr_fatal("BDK_SMMUX_CBFRSYNRAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CBFRSYNRAX(...) bdk_smmux_cbfrsynrax_t
#define bustype_BDK_SMMUX_CBFRSYNRAX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CBFRSYNRAX(p1,p2) (p1)
#define arguments_BDK_SMMUX_CBFRSYNRAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_CBFRSYNRAX(...) "SMMUX_CBFRSYNRAX"


/**
 * NCB32b - smmu#_cidr0
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_cidr0 {
	uint32_t u;
	struct bdk_smmux_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_cidr0_s           cn88xx; */
	/* struct bdk_smmux_cidr0_s           cn88xxp1; */
} bdk_smmux_cidr0_t;

static inline uint64_t BDK_SMMUX_CIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FF0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_CIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CIDR0(...) bdk_smmux_cidr0_t
#define bustype_BDK_SMMUX_CIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CIDR0(p1) (p1)
#define arguments_BDK_SMMUX_CIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_CIDR0(...) "SMMUX_CIDR0"


/**
 * NCB32b - smmu#_cidr1
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_cidr1 {
	uint32_t u;
	struct bdk_smmux_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_cidr1_s           cn88xx; */
	/* struct bdk_smmux_cidr1_s           cn88xxp1; */
} bdk_smmux_cidr1_t;

static inline uint64_t BDK_SMMUX_CIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FF4ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_CIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CIDR1(...) bdk_smmux_cidr1_t
#define bustype_BDK_SMMUX_CIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CIDR1(p1) (p1)
#define arguments_BDK_SMMUX_CIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_CIDR1(...) "SMMUX_CIDR1"


/**
 * NCB32b - smmu#_cidr2
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_cidr2 {
	uint32_t u;
	struct bdk_smmux_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_cidr2_s           cn88xx; */
	/* struct bdk_smmux_cidr2_s           cn88xxp1; */
} bdk_smmux_cidr2_t;

static inline uint64_t BDK_SMMUX_CIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FF8ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_CIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CIDR2(...) bdk_smmux_cidr2_t
#define bustype_BDK_SMMUX_CIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CIDR2(p1) (p1)
#define arguments_BDK_SMMUX_CIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_CIDR2(...) "SMMUX_CIDR2"


/**
 * NCB32b - smmu#_cidr3
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_cidr3 {
	uint32_t u;
	struct bdk_smmux_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_cidr3_s           cn88xx; */
	/* struct bdk_smmux_cidr3_s           cn88xxp1; */
} bdk_smmux_cidr3_t;

static inline uint64_t BDK_SMMUX_CIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_CIDR3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FFCull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_CIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_CIDR3(...) bdk_smmux_cidr3_t
#define bustype_BDK_SMMUX_CIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_CIDR3(p1) (p1)
#define arguments_BDK_SMMUX_CIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_CIDR3(...) "SMMUX_CIDR3"


/**
 * NCB - smmu#_diag_ctl
 */
typedef union bdk_smmux_diag_ctl {
	uint64_t u;
	struct bdk_smmux_diag_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t force_clks_active           : 1;  /**< SR/W - Forces the conditional clocks to be always on. For diagnostic use only. */
		uint64_t walkers                     : 6;  /**< SR/W - Number of walkers. The number of page table walkers that may
                                                                 simultaneously be executing, minus one.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's.
                                                                 For diagnostic use only. */
		uint64_t reserved_7_7                : 1;
		uint64_t throttle                    : 1;  /**< SR/W - Throttle throughput. For diagnostic use only. If set, limit translations to one every four
                                                                 cycles, to insure OCLA debug FIFOs will not overrun.
                                                                 SMMU1 uses SMMU0's register value; SMMU3 uses SMMU2's. */
		uint64_t dis_bcstr                   : 1;  /**< SR/W - Disable broadcast response. For diagnostic use only. If set, a broadcast invalidate will
                                                                 be acknowledged immediately and the standard acknowledgement at completion of invalidation
                                                                 will be suppressed. */
		uint64_t dis_wcs1                    : 2;  /**< SR/W - Disables hitting in the walk cache for stage 1 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
		uint64_t dis_wcs2                    : 2;  /**< SR/W - Disables hitting in the walk cache for stage 2 translations. For diagnostic use only.
                                                                 0x0 = Normal operation. Allow hits at all levels.
                                                                 0x1 = Never hit.
                                                                 0x2 = Allow hits on table levels 0 and 1.
                                                                 0x3 = Reserved. */
		uint64_t dis_tlb                     : 1;  /**< SR/W - Disables hitting in the TLB. For diagnostic use only. */
#else
		uint64_t dis_tlb                     : 1;
		uint64_t dis_wcs2                    : 2;
		uint64_t dis_wcs1                    : 2;
		uint64_t dis_bcstr                   : 1;
		uint64_t throttle                    : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t walkers                     : 6;
		uint64_t force_clks_active           : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_smmux_diag_ctl_s        cn88xx; */
	/* struct bdk_smmux_diag_ctl_s        cn88xxp1; */
} bdk_smmux_diag_ctl_t;

static inline uint64_t BDK_SMMUX_DIAG_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_DIAG_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020030ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_DIAG_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_DIAG_CTL(...) bdk_smmux_diag_ctl_t
#define bustype_BDK_SMMUX_DIAG_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_DIAG_CTL(p1) (p1)
#define arguments_BDK_SMMUX_DIAG_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_DIAG_CTL(...) "SMMUX_DIAG_CTL"


/**
 * NCB - smmu#_ecc_ctl_0
 */
typedef union bdk_smmux_ecc_ctl_0 {
	uint64_t u;
	struct bdk_smmux_ecc_ctl_0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t ram_cdis                    : 21; /**< SR/W - RAM ECC correction disable. Each bit corresponds to a different RAM. INTERNAL: Bits
                                                                 do not match SMMU()_ERR_INT[RAM_SBE].
                                                                 \<20\> = WCTL.
                                                                 \<19\> = TCTL.
                                                                 \<18\> = XL_MFIFO.
                                                                 \<17\> = MSIX.
                                                                 \<16\> = CONTEXT_IDR.
                                                                 \<15\> = CB_FRSYNRA.
                                                                 \<14\> = CB_IPAFAR.
                                                                 \<13\> = CB_FSYNR0.
                                                                 \<12\> = CB_FAR.
                                                                 \<11\> = S2CR.
                                                                 \<10\> = CB_ACTLR.
                                                                 \<9\>  = CB_TCR2.
                                                                 \<8\>  = SSDR.
                                                                 \<7\>  = SCTLR.
                                                                 \<6\>  = CB_MAIR0.
                                                                 \<5\>  = CB_MAIR1.
                                                                 \<4\>  = CBAR.
                                                                 \<3\>  = CBA2R.
                                                                 \<2\>  = CB_TTBR0.
                                                                 \<1\>  = CB_TTBR1.
                                                                 \<0\>  = CB_TCR. */
#else
		uint64_t ram_cdis                    : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_smmux_ecc_ctl_0_s       cn88xx; */
	/* struct bdk_smmux_ecc_ctl_0_s       cn88xxp1; */
} bdk_smmux_ecc_ctl_0_t;

static inline uint64_t BDK_SMMUX_ECC_CTL_0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ECC_CTL_0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000200F0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ECC_CTL_0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ECC_CTL_0(...) bdk_smmux_ecc_ctl_0_t
#define bustype_BDK_SMMUX_ECC_CTL_0(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ECC_CTL_0(p1) (p1)
#define arguments_BDK_SMMUX_ECC_CTL_0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ECC_CTL_0(...) "SMMUX_ECC_CTL_0"


/**
 * NCB - smmu#_ecc_ctl_1
 */
typedef union bdk_smmux_ecc_ctl_1 {
	uint64_t u;
	struct bdk_smmux_ecc_ctl_1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t ram_flip1                   : 21; /**< SR/W - Flip syndrome bits on write. Flip syndrome bit \<1\> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. INTERNAL: Bits enumerated by
                                                                 SMMU()_ECC_CTL0[RAM_CDIS]. */
		uint64_t reserved_21_31              : 11;
		uint64_t ram_flip0                   : 21; /**< SR/W - Flip syndrome bits on write. Flip syndrome bit \<0\> on writes to the corresponding ram to
                                                                 test single-bit or double-bit error handling. INTERNAL: Bits enumerated by
                                                                 SMMU()_ECC_CTL0[RAM_CDIS]. */
#else
		uint64_t ram_flip0                   : 21;
		uint64_t reserved_21_31              : 11;
		uint64_t ram_flip1                   : 21;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_smmux_ecc_ctl_1_s       cn88xx; */
	/* struct bdk_smmux_ecc_ctl_1_s       cn88xxp1; */
} bdk_smmux_ecc_ctl_1_t;

static inline uint64_t BDK_SMMUX_ECC_CTL_1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ECC_CTL_1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000200F8ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ECC_CTL_1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ECC_CTL_1(...) bdk_smmux_ecc_ctl_1_t
#define bustype_BDK_SMMUX_ECC_CTL_1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ECC_CTL_1(p1) (p1)
#define arguments_BDK_SMMUX_ECC_CTL_1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ECC_CTL_1(...) "SMMUX_ECC_CTL_1"


/**
 * NCB - smmu#_err_ena_w1c
 */
typedef union bdk_smmux_err_ena_w1c {
	uint64_t u;
	struct bdk_smmux_err_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t ram_dbe                     : 21; /**< R/W1C/H - Double-bit error detected in internal RAM. INTERNAL: Bits enumerated by [RAM_SBE]. */
		uint64_t reserved_21_31              : 11;
		uint64_t ram_sbe                     : 21; /**< R/W1C/H - Single-bit error detected in internal RAM.
                                                                 \<20\> = TCTL.
                                                                 \<19\> = WCTL.
                                                                 \<18\> = XL_MFIFO.
                                                                 \<17\> = MSIX.
                                                                 \<16\> = CONTEXT_IDR.
                                                                 \<15\> = CB_FRSYNRA.
                                                                 \<14\> = CB_IPAFAR.
                                                                 \<13\> = CB_FSYNR0.
                                                                 \<12\> = CB_FAR.
                                                                 \<11\> = S2CR.
                                                                 \<10\> = CB_ACTLR.
                                                                 \<9\>  = CB_TCR2.
                                                                 \<8\>  = SSDR.
                                                                 \<7\>  = SCTLR.
                                                                 \<6\>  = CB_MAIR0.
                                                                 \<5\>  = CB_MAIR1.
                                                                 \<4\>  = CBAR.
                                                                 \<3\>  = CBA2R.
                                                                 \<2\>  = CB_TTBR0.
                                                                 \<1\>  = CB_TTBR1.
                                                                 \<0\>  = CB_TCR. */
#else
		uint64_t ram_sbe                     : 21;
		uint64_t reserved_21_31              : 11;
		uint64_t ram_dbe                     : 21;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_smmux_err_ena_w1c_s     cn88xx; */
	/* struct bdk_smmux_err_ena_w1c_s     cn88xxp1; */
} bdk_smmux_err_ena_w1c_t;

static inline uint64_t BDK_SMMUX_ERR_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000200A0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ERR_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ERR_ENA_W1C(...) bdk_smmux_err_ena_w1c_t
#define bustype_BDK_SMMUX_ERR_ENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ERR_ENA_W1C(p1) (p1)
#define arguments_BDK_SMMUX_ERR_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ERR_ENA_W1C(...) "SMMUX_ERR_ENA_W1C"


/**
 * NCB - smmu#_err_ena_w1s
 */
typedef union bdk_smmux_err_ena_w1s {
	uint64_t u;
	struct bdk_smmux_err_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t ram_dbe                     : 21; /**< R/W1C/H - Double-bit error detected in internal RAM. INTERNAL: Bits enumerated by [RAM_SBE]. */
		uint64_t reserved_21_31              : 11;
		uint64_t ram_sbe                     : 21; /**< R/W1C/H - Single-bit error detected in internal RAM.
                                                                 \<20\> = TCTL.
                                                                 \<19\> = WCTL.
                                                                 \<18\> = XL_MFIFO.
                                                                 \<17\> = MSIX.
                                                                 \<16\> = CONTEXT_IDR.
                                                                 \<15\> = CB_FRSYNRA.
                                                                 \<14\> = CB_IPAFAR.
                                                                 \<13\> = CB_FSYNR0.
                                                                 \<12\> = CB_FAR.
                                                                 \<11\> = S2CR.
                                                                 \<10\> = CB_ACTLR.
                                                                 \<9\>  = CB_TCR2.
                                                                 \<8\>  = SSDR.
                                                                 \<7\>  = SCTLR.
                                                                 \<6\>  = CB_MAIR0.
                                                                 \<5\>  = CB_MAIR1.
                                                                 \<4\>  = CBAR.
                                                                 \<3\>  = CBA2R.
                                                                 \<2\>  = CB_TTBR0.
                                                                 \<1\>  = CB_TTBR1.
                                                                 \<0\>  = CB_TCR. */
#else
		uint64_t ram_sbe                     : 21;
		uint64_t reserved_21_31              : 11;
		uint64_t ram_dbe                     : 21;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_smmux_err_ena_w1s_s     cn88xx; */
	/* struct bdk_smmux_err_ena_w1s_s     cn88xxp1; */
} bdk_smmux_err_ena_w1s_t;

static inline uint64_t BDK_SMMUX_ERR_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000200B0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ERR_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ERR_ENA_W1S(...) bdk_smmux_err_ena_w1s_t
#define bustype_BDK_SMMUX_ERR_ENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ERR_ENA_W1S(p1) (p1)
#define arguments_BDK_SMMUX_ERR_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ERR_ENA_W1S(...) "SMMUX_ERR_ENA_W1S"


/**
 * NCB - smmu#_err_int
 */
typedef union bdk_smmux_err_int {
	uint64_t u;
	struct bdk_smmux_err_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t ram_dbe                     : 21; /**< R/W1C/H - Double-bit error detected in internal RAM. INTERNAL: Bits enumerated by [RAM_SBE]. */
		uint64_t reserved_21_31              : 11;
		uint64_t ram_sbe                     : 21; /**< R/W1C/H - Single-bit error detected in internal RAM.
                                                                 \<20\> = TCTL.
                                                                 \<19\> = WCTL.
                                                                 \<18\> = XL_MFIFO.
                                                                 \<17\> = MSIX.
                                                                 \<16\> = CONTEXT_IDR.
                                                                 \<15\> = CB_FRSYNRA.
                                                                 \<14\> = CB_IPAFAR.
                                                                 \<13\> = CB_FSYNR0.
                                                                 \<12\> = CB_FAR.
                                                                 \<11\> = S2CR.
                                                                 \<10\> = CB_ACTLR.
                                                                 \<9\>  = CB_TCR2.
                                                                 \<8\>  = SSDR.
                                                                 \<7\>  = SCTLR.
                                                                 \<6\>  = CB_MAIR0.
                                                                 \<5\>  = CB_MAIR1.
                                                                 \<4\>  = CBAR.
                                                                 \<3\>  = CBA2R.
                                                                 \<2\>  = CB_TTBR0.
                                                                 \<1\>  = CB_TTBR1.
                                                                 \<0\>  = CB_TCR. */
#else
		uint64_t ram_sbe                     : 21;
		uint64_t reserved_21_31              : 11;
		uint64_t ram_dbe                     : 21;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_smmux_err_int_s         cn88xx; */
	/* struct bdk_smmux_err_int_s         cn88xxp1; */
} bdk_smmux_err_int_t;

static inline uint64_t BDK_SMMUX_ERR_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_INT(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020080ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ERR_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ERR_INT(...) bdk_smmux_err_int_t
#define bustype_BDK_SMMUX_ERR_INT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ERR_INT(p1) (p1)
#define arguments_BDK_SMMUX_ERR_INT(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ERR_INT(...) "SMMUX_ERR_INT"


/**
 * NCB - smmu#_err_int_w1s
 */
typedef union bdk_smmux_err_int_w1s {
	uint64_t u;
	struct bdk_smmux_err_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_53_63              : 11;
		uint64_t ram_dbe                     : 21; /**< R/W1C/H - Double-bit error detected in internal RAM. INTERNAL: Bits enumerated by [RAM_SBE]. */
		uint64_t reserved_21_31              : 11;
		uint64_t ram_sbe                     : 21; /**< R/W1C/H - Single-bit error detected in internal RAM.
                                                                 \<20\> = TCTL.
                                                                 \<19\> = WCTL.
                                                                 \<18\> = XL_MFIFO.
                                                                 \<17\> = MSIX.
                                                                 \<16\> = CONTEXT_IDR.
                                                                 \<15\> = CB_FRSYNRA.
                                                                 \<14\> = CB_IPAFAR.
                                                                 \<13\> = CB_FSYNR0.
                                                                 \<12\> = CB_FAR.
                                                                 \<11\> = S2CR.
                                                                 \<10\> = CB_ACTLR.
                                                                 \<9\>  = CB_TCR2.
                                                                 \<8\>  = SSDR.
                                                                 \<7\>  = SCTLR.
                                                                 \<6\>  = CB_MAIR0.
                                                                 \<5\>  = CB_MAIR1.
                                                                 \<4\>  = CBAR.
                                                                 \<3\>  = CBA2R.
                                                                 \<2\>  = CB_TTBR0.
                                                                 \<1\>  = CB_TTBR1.
                                                                 \<0\>  = CB_TCR. */
#else
		uint64_t ram_sbe                     : 21;
		uint64_t reserved_21_31              : 11;
		uint64_t ram_dbe                     : 21;
		uint64_t reserved_53_63              : 11;
#endif
	} s;
	/* struct bdk_smmux_err_int_w1s_s     cn88xx; */
	/* struct bdk_smmux_err_int_w1s_s     cn88xxp1; */
} bdk_smmux_err_int_w1s_t;

static inline uint64_t BDK_SMMUX_ERR_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_ERR_INT_W1S(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020090ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_ERR_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_ERR_INT_W1S(...) bdk_smmux_err_int_w1s_t
#define bustype_BDK_SMMUX_ERR_INT_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_ERR_INT_W1S(p1) (p1)
#define arguments_BDK_SMMUX_ERR_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_ERR_INT_W1S(...) "SMMUX_ERR_INT_W1S"


/**
 * NCB32b - smmu#_idr0
 *
 * Provides SMMU capability information.
 *
 */
typedef union bdk_smmux_idr0 {
	uint32_t u;
	struct bdk_smmux_idr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t se                          : 1;  /**< SRO - Security extensions support. */
		uint32_t s1ts                        : 1;  /**< RO - Stage 1 translation support. */
		uint32_t s2ts                        : 1;  /**< RO - Stage 2 translation support.
                                                                 0 = Stage 2 translations are not supported.
                                                                 1 = Stage 2 translations are supported.

                                                                 As stage 2 translation is not supported for secure client accesses, the value returned in
                                                                 this field relates to SMMU capabilities for non-secure client accesses. */
		uint32_t nts                         : 1;  /**< RO - Nested translation support.
                                                                 As stage 2 (and therefore nested) translation is not supported for secure client accesses,
                                                                 the value returned in this field relates to SMMU capabilities for non-secure client
                                                                 accesses. */
		uint32_t sms                         : 1;  /**< RO - Stream match support. */
		uint32_t atosns                      : 1;  /**< RO - Address translations operation not supported.

                                                                 In CNXXXX, deprecated and not supported. */
		uint32_t ptfs                        : 2;  /**< RO - Page table format supported.
                                                                 0x0 = V7L and V7S supported.
                                                                 0x1 = V7L format supported.
                                                                 0x2 = Only the V8 format is supported.
                                                                 0x3 = Reserved.

                                                                 In CNXXXX V8 only. */
		uint32_t numirpt                     : 8;  /**< RO - Number of implemented context fault interrupts. Always 0x1 in ARMv8. */
		uint32_t reserved_15_15              : 1;
		uint32_t cttw                        : 1;  /**< RO - Coherent translation table walk supported. */
		uint32_t btm                         : 1;  /**< RO - Broadcast TLB maintenance supported. */
		uint32_t numsidb                     : 4;  /**< RO - Number of supported stream ID bits. */
		uint32_t exids                       : 1;  /**< RO - Extended stream IDs are supported. */
		uint32_t numsmrg                     : 8;  /**< RO/H - Number of supported stream mapping registers groups. Access to this field by non-secure
                                                                 software gives the value configured in SMMU()_SCR1[NSNUMSMRGO]. */
#else
		uint32_t numsmrg                     : 8;
		uint32_t exids                       : 1;
		uint32_t numsidb                     : 4;
		uint32_t btm                         : 1;
		uint32_t cttw                        : 1;
		uint32_t reserved_15_15              : 1;
		uint32_t numirpt                     : 8;
		uint32_t ptfs                        : 2;
		uint32_t atosns                      : 1;
		uint32_t sms                         : 1;
		uint32_t nts                         : 1;
		uint32_t s2ts                        : 1;
		uint32_t s1ts                        : 1;
		uint32_t se                          : 1;
#endif
	} s;
	/* struct bdk_smmux_idr0_s            cn88xx; */
	/* struct bdk_smmux_idr0_s            cn88xxp1; */
} bdk_smmux_idr0_t;

static inline uint64_t BDK_SMMUX_IDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000020ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR0(...) bdk_smmux_idr0_t
#define bustype_BDK_SMMUX_IDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR0(p1) (p1)
#define arguments_BDK_SMMUX_IDR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR0(...) "SMMUX_IDR0"


/**
 * NCB32b - smmu#_idr1
 *
 * Provides SMMU capability information.
 *
 */
typedef union bdk_smmux_idr1 {
	uint32_t u;
	struct bdk_smmux_idr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t pagesize                    : 1;  /**< RO - Indicates the size of each page in the SMMU register map.
                                                                 0 = Each page consumes 4 Kbytes.
                                                                 1 = Each page consumes 64 Kbytes. */
		uint32_t numpagendxb                 : 3;  /**< RO - Indicates how many pagesize pages occupy the global address space or the translation
                                                                 context address space where the number of pages is equal to 2^(NUMPAGENDXB + 1). */
		uint32_t reserved_24_27              : 4;
		uint32_t nums2cb                     : 8;  /**< RO - Number of stage 2 context banks. Indicates the number of translation context banks that
                                                                 only support the stage 2 translation format. */
		uint32_t smcd                        : 1;  /**< RO - Stream match conflict detection.
                                                                 0 = The detection of all stream match conflicts is not guaranteed.
                                                                 1 = The detection of all stream match conflicts is guaranteed.

                                                                 CNXXXX detects stream match conflicts. */
		uint32_t reserved_14_14              : 1;
		uint32_t ssdtp                       : 2;  /**< SRO - Security state determination table present.
                                                                 0x0 = The security state determination address space is UNK/WI.
                                                                 0x1 = The security state determination address space is populated for up to 15-bit
                                                                 streams.
                                                                 0x2 = Reserved.
                                                                 0x3 = The security state determination address space is populated for up to 16-bit
                                                                 streams.

                                                                 CNXXXX implements a 16-bit security state determination table. */
		uint32_t numssdndxb                  : 4;  /**< SRO - Indicates the number of SSD_Index bits for indexing the security state determination table. */
		uint32_t numcb                       : 8;  /**< RO/H - Indicates the total number of implemented translation context banks in the range 0-128.
                                                                 The value reported in NUMCB includes translation context banks that only support stage 2
                                                                 format. The number of translation context banks that support the stage 1 format is given
                                                                 by [NUMCB] - [NUMS2CB]. A read of this field by non-secure software gives the value
                                                                 configured in [NSNUMCBO]. */
#else
		uint32_t numcb                       : 8;
		uint32_t numssdndxb                  : 4;
		uint32_t ssdtp                       : 2;
		uint32_t reserved_14_14              : 1;
		uint32_t smcd                        : 1;
		uint32_t nums2cb                     : 8;
		uint32_t reserved_24_27              : 4;
		uint32_t numpagendxb                 : 3;
		uint32_t pagesize                    : 1;
#endif
	} s;
	/* struct bdk_smmux_idr1_s            cn88xx; */
	/* struct bdk_smmux_idr1_s            cn88xxp1; */
} bdk_smmux_idr1_t;

static inline uint64_t BDK_SMMUX_IDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000024ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR1(...) bdk_smmux_idr1_t
#define bustype_BDK_SMMUX_IDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR1(p1) (p1)
#define arguments_BDK_SMMUX_IDR1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR1(...) "SMMUX_IDR1"


/**
 * NCB32b - smmu#_idr2
 */
typedef union bdk_smmux_idr2 {
	uint32_t u;
	struct bdk_smmux_idr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t dipans                      : 1;  /**< RO - Privileged access never support.
                                                                 When set, indicates supports ARM v8.1 privileged access never.
                                                                 See SMMU()_S2CR()[PRIVCFG].

                                                                 Note unlike the processor architecture, DIPAN applies to both instruction and data
                                                                 transactions; thus to distinguish the two features then the SMMU feature is called DIPAN
                                                                 whilst the processor architecture version is called PAN. */
		uint32_t reserved_29_29              : 1;
		uint32_t hads                        : 1;  /**< RO - Hierarchical attribute disable support.
                                                                 When set, indicates supports ARM v8.1 hierarchical attribute disables.
                                                                 See SMMU()_CB()_TCR2[HAD0]. */
		uint32_t e2hs                        : 1;  /**< RO - Virtual host extension contexts.
                                                                 When set, indicates supports ARM v8.1 virtual host extension contexts.
                                                                 See SMMU()_CBA2R()[E2HC]. */
		uint32_t reserved_16_26              : 11;
		uint32_t vmid16s                     : 1;  /**< RO - When set, indicates that 16-bit VMIDs are supported (ARMv8 large system extensions). */
		uint32_t ptfsv8_64kb                 : 1;  /**< RO - When set, indicates that ARMv8 page tables using 64kb page granule are supported. */
		uint32_t ptfsv8_16kb                 : 1;  /**< RO - When set, indicates that ARMv8 page tables using 16kb page granule are supported. */
		uint32_t ptfsv8_4kb                  : 1;  /**< RO - When set, indicates that ARMv8 page tables using 4kb page granule are supported. */
		uint32_t ubs                         : 4;  /**< RO - Upstream bus size.  This field specifies the maximum width of any upstream address port
                                                                 used by client devices to perform address translations.
                                                                 0x5 = 48-bit + 1 sign bit. */
		uint32_t oas                         : 4;  /**< RO - Output address size. The maximum PA size supported.
                                                                 0x5 = 48-bit. */
		uint32_t ias                         : 4;  /**< RO - Intermediate address size. The maximum IPA size supported.
                                                                 0x5 = 48-bit. */
#else
		uint32_t ias                         : 4;
		uint32_t oas                         : 4;
		uint32_t ubs                         : 4;
		uint32_t ptfsv8_4kb                  : 1;
		uint32_t ptfsv8_16kb                 : 1;
		uint32_t ptfsv8_64kb                 : 1;
		uint32_t vmid16s                     : 1;
		uint32_t reserved_16_26              : 11;
		uint32_t e2hs                        : 1;
		uint32_t hads                        : 1;
		uint32_t reserved_29_29              : 1;
		uint32_t dipans                      : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_smmux_idr2_s            cn88xx; */
	/* struct bdk_smmux_idr2_s            cn88xxp1; */
} bdk_smmux_idr2_t;

static inline uint64_t BDK_SMMUX_IDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000028ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR2(...) bdk_smmux_idr2_t
#define bustype_BDK_SMMUX_IDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR2(p1) (p1)
#define arguments_BDK_SMMUX_IDR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR2(...) "SMMUX_IDR2"


/**
 * NCB32b - smmu#_idr3
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_idr3 {
	uint32_t u;
	struct bdk_smmux_idr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_idr3_s            cn88xx; */
	/* struct bdk_smmux_idr3_s            cn88xxp1; */
} bdk_smmux_idr3_t;

static inline uint64_t BDK_SMMUX_IDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000083000000002Cull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR3(...) bdk_smmux_idr3_t
#define bustype_BDK_SMMUX_IDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR3(p1) (p1)
#define arguments_BDK_SMMUX_IDR3(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR3(...) "SMMUX_IDR3"


/**
 * NCB32b - smmu#_idr4
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_idr4 {
	uint32_t u;
	struct bdk_smmux_idr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_idr4_s            cn88xx; */
	/* struct bdk_smmux_idr4_s            cn88xxp1; */
} bdk_smmux_idr4_t;

static inline uint64_t BDK_SMMUX_IDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR4(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000030ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR4(...) bdk_smmux_idr4_t
#define bustype_BDK_SMMUX_IDR4(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR4(p1) (p1)
#define arguments_BDK_SMMUX_IDR4(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR4(...) "SMMUX_IDR4"


/**
 * NCB32b - smmu#_idr5
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_idr5 {
	uint32_t u;
	struct bdk_smmux_idr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_idr5_s            cn88xx; */
	/* struct bdk_smmux_idr5_s            cn88xxp1; */
} bdk_smmux_idr5_t;

static inline uint64_t BDK_SMMUX_IDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR5(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000034ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR5(...) bdk_smmux_idr5_t
#define bustype_BDK_SMMUX_IDR5(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR5(p1) (p1)
#define arguments_BDK_SMMUX_IDR5(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR5(...) "SMMUX_IDR5"


/**
 * NCB32b - smmu#_idr6
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_idr6 {
	uint32_t u;
	struct bdk_smmux_idr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_idr6_s            cn88xx; */
	/* struct bdk_smmux_idr6_s            cn88xxp1; */
} bdk_smmux_idr6_t;

static inline uint64_t BDK_SMMUX_IDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR6(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000038ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR6(...) bdk_smmux_idr6_t
#define bustype_BDK_SMMUX_IDR6(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR6(p1) (p1)
#define arguments_BDK_SMMUX_IDR6(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR6(...) "SMMUX_IDR6"


/**
 * NCB32b - smmu#_idr7
 */
typedef union bdk_smmux_idr7 {
	uint32_t u;
	struct bdk_smmux_idr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t major                       : 4;  /**< RO - The major part of the implementation version number.
                                                                 For CNXXXX from PCCPF_SMMU()_REV[RID]\<7:4\>. */
		uint32_t minor                       : 4;  /**< RO - The minor part of the implementation version number.
                                                                 For CNXXXX from PCCPF_SMMU()_REV[RID]\<3:0\>. */
#else
		uint32_t minor                       : 4;
		uint32_t major                       : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_idr7_s            cn88xx; */
	/* struct bdk_smmux_idr7_s            cn88xxp1; */
} bdk_smmux_idr7_t;

static inline uint64_t BDK_SMMUX_IDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_IDR7(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000083000000003Cull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_IDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_IDR7(...) bdk_smmux_idr7_t
#define bustype_BDK_SMMUX_IDR7(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_IDR7(p1) (p1)
#define arguments_BDK_SMMUX_IDR7(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_IDR7(...) "SMMUX_IDR7"


/**
 * NCB - smmu#_look_par
 *
 * Receives the physical address from a SMMU()_LOOK_REQ operation. For diagnostic use only.
 *
 */
typedef union bdk_smmux_look_par {
	uint64_t u;
	struct bdk_smmux_look_par_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t pa                          : 36; /**< SRO/H - If [FAULT]=0, physical address of the completed lookup. */
		uint64_t reserved_3_11               : 9;
		uint64_t nsec                        : 1;  /**< SRO/H - If [FAULT]=0, non-secure. The final resolved secure state for the translation, matching
                                                                 the non-secure bit passed to the L2 cache. */
		uint64_t active                      : 1;  /**< SRO/H - Translation in progress. Set on write to SMMU()_LOOK_REQ[GO], cleared when translation
                                                                 has completed. */
		uint64_t fault                       : 1;  /**< SRO/H - Fault. If 0 indicates completed successfully. If 1, the fault will not be recorded in the
                                                                 error registers. */
#else
		uint64_t fault                       : 1;
		uint64_t active                      : 1;
		uint64_t nsec                        : 1;
		uint64_t reserved_3_11               : 9;
		uint64_t pa                          : 36;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_smmux_look_par_s        cn88xx; */
	/* struct bdk_smmux_look_par_s        cn88xxp1; */
} bdk_smmux_look_par_t;

static inline uint64_t BDK_SMMUX_LOOK_PAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_LOOK_PAR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020120ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_LOOK_PAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_LOOK_PAR(...) bdk_smmux_look_par_t
#define bustype_BDK_SMMUX_LOOK_PAR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_LOOK_PAR(p1) (p1)
#define arguments_BDK_SMMUX_LOOK_PAR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_LOOK_PAR(...) "SMMUX_LOOK_PAR"


/**
 * NCB - smmu#_look_req
 *
 * For diagnostic use only.
 *
 */
typedef union bdk_smmux_look_req {
	uint64_t u;
	struct bdk_smmux_look_req_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t va                          : 37; /**< SR/W - Virtual address to lookup. */
		uint64_t reserved_3_11               : 9;
		uint64_t rd                          : 1;  /**< SR/W - Read operation lookup; page must allow reads. Either a read or write operation must be asserted. */
		uint64_t wr                          : 1;  /**< SR/W - Write operation lookup; page must allow writes. Either a read or write operation must be asserted. */
		uint64_t go                          : 1;  /**< SWO - Write a one to request translation begin. Read SMMU()_LOOK_PAR[ACTIVE] to determine
                                                                 when the translation completes. */
#else
		uint64_t go                          : 1;
		uint64_t wr                          : 1;
		uint64_t rd                          : 1;
		uint64_t reserved_3_11               : 9;
		uint64_t va                          : 37;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_smmux_look_req_s        cn88xx; */
	/* struct bdk_smmux_look_req_s        cn88xxp1; */
} bdk_smmux_look_req_t;

static inline uint64_t BDK_SMMUX_LOOK_REQ(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_LOOK_REQ(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020100ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_LOOK_REQ", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_LOOK_REQ(...) bdk_smmux_look_req_t
#define bustype_BDK_SMMUX_LOOK_REQ(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_LOOK_REQ(p1) (p1)
#define arguments_BDK_SMMUX_LOOK_REQ(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_LOOK_REQ(...) "SMMUX_LOOK_REQ"


/**
 * NCB - smmu#_look_strm
 *
 * Specifies additional lookup values for the next SMMU()_LOOK_REQ
 * operation. For diagnostic use only.
 */
typedef union bdk_smmux_look_strm {
	uint64_t u;
	struct bdk_smmux_look_strm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t stream                      : 16; /**< SR/W - Stream ID. */
#else
		uint64_t stream                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_smmux_look_strm_s       cn88xx; */
	/* struct bdk_smmux_look_strm_s       cn88xxp1; */
} bdk_smmux_look_strm_t;

static inline uint64_t BDK_SMMUX_LOOK_STRM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_LOOK_STRM(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000020110ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_LOOK_STRM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_LOOK_STRM(...) bdk_smmux_look_strm_t
#define bustype_BDK_SMMUX_LOOK_STRM(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_LOOK_STRM(p1) (p1)
#define arguments_BDK_SMMUX_LOOK_STRM(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_LOOK_STRM(...) "SMMUX_LOOK_STRM"


/**
 * NCB - smmu#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the SMMU_INT_VEC_E enumeration.
 *
 */
typedef union bdk_smmux_msix_pbax {
	uint64_t u;
	struct bdk_smmux_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for each interrupt, enumerated by SMMU_INT_VEC_E. Bits that have no
                                                                 associated SMMU_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_smmux_msix_pbax_s       cn88xx; */
	/* struct bdk_smmux_msix_pbax_s       cn88xxp1; */
} bdk_smmux_msix_pbax_t;

static inline uint64_t BDK_SMMUX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 4)))
		return 0x000083000F0F0000ull + (param1 & 3) * 0x1000000000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_SMMUX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_MSIX_PBAX(...) bdk_smmux_msix_pbax_t
#define bustype_BDK_SMMUX_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_SMMUX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_MSIX_PBAX(...) "SMMUX_MSIX_PBAX"


/**
 * NCB - smmu#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the SMMU_INT_VEC_E enumeration.
 *
 */
typedef union bdk_smmux_msix_vecx_addr {
	uint64_t u;
	struct bdk_smmux_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SMMU()_MSIX_VEC()_ADDR, SMMU()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of SMMU()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SMMU(0..3)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_smmux_msix_vecx_addr_s  cn88xx; */
	/* struct bdk_smmux_msix_vecx_addr_s  cn88xxp1; */
} bdk_smmux_msix_vecx_addr_t;

static inline uint64_t BDK_SMMUX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 261)))
		return 0x000083000F000000ull + (param1 & 3) * 0x1000000000ull + (param2 & 511) * 0x10ull;
	csr_fatal("BDK_SMMUX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_MSIX_VECX_ADDR(...) bdk_smmux_msix_vecx_addr_t
#define bustype_BDK_SMMUX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_SMMUX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_MSIX_VECX_ADDR(...) "SMMUX_MSIX_VECX_ADDR"


/**
 * NCB - smmu#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the SMMU_INT_VEC_E enumeration.
 *
 */
typedef union bdk_smmux_msix_vecx_ctl {
	uint64_t u;
	struct bdk_smmux_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< R/W - When set, no MSI-X interrupts will be sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< R/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_smmux_msix_vecx_ctl_s   cn88xx; */
	/* struct bdk_smmux_msix_vecx_ctl_s   cn88xxp1; */
} bdk_smmux_msix_vecx_ctl_t;

static inline uint64_t BDK_SMMUX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 261)))
		return 0x000083000F000008ull + (param1 & 3) * 0x1000000000ull + (param2 & 511) * 0x10ull;
	csr_fatal("BDK_SMMUX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_MSIX_VECX_CTL(...) bdk_smmux_msix_vecx_ctl_t
#define bustype_BDK_SMMUX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_SMMUX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_MSIX_VECX_CTL(...) "SMMUX_MSIX_VECX_CTL"


/**
 * NCB - smmu#_ns_hit_perf
 */
typedef union bdk_smmux_ns_hit_perf {
	uint64_t u;
	struct bdk_smmux_ns_hit_perf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< R/W/H - Counts the number of hits in non-secure mode. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_ns_hit_perf_s     cn88xx; */
	/* struct bdk_smmux_ns_hit_perf_s     cn88xxp1; */
} bdk_smmux_ns_hit_perf_t;

static inline uint64_t BDK_SMMUX_NS_HIT_PERF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NS_HIT_PERF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021010ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NS_HIT_PERF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NS_HIT_PERF(...) bdk_smmux_ns_hit_perf_t
#define bustype_BDK_SMMUX_NS_HIT_PERF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_NS_HIT_PERF(p1) (p1)
#define arguments_BDK_SMMUX_NS_HIT_PERF(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NS_HIT_PERF(...) "SMMUX_NS_HIT_PERF"


/**
 * NCB32b - smmu#_nsacr
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)ACR.
 *
 */
typedef union bdk_smmux_nsacr {
	uint32_t u;
	struct bdk_smmux_nsacr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t qos                         : 4;  /**< R/W - L2C quality-of-service value to use for standard transactions that are not by a specific
                                                                 context, and so SMMU()_CB()_ACTLR[QOS] is not applicable. */
		uint32_t qos_walk                    : 4;  /**< R/W - L2C quality-of-service value to use for page table walks. For optimal performance, this
                                                                 typically would be set to the most preferential QoS value of zero. */
		uint32_t reserved_0_23               : 24;
#else
		uint32_t reserved_0_23               : 24;
		uint32_t qos_walk                    : 4;
		uint32_t qos                         : 4;
#endif
	} s;
	/* struct bdk_smmux_nsacr_s           cn88xx; */
	/* struct bdk_smmux_nsacr_s           cn88xxp1; */
} bdk_smmux_nsacr_t;

static inline uint64_t BDK_SMMUX_NSACR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSACR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000410ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSACR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSACR(...) bdk_smmux_nsacr_t
#define bustype_BDK_SMMUX_NSACR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSACR(p1) (p1)
#define arguments_BDK_SMMUX_NSACR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSACR(...) "SMMUX_NSACR"


/**
 * NCB32b - smmu#_nscr0
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)CR0.
 *
 */
typedef union bdk_smmux_nscr0 {
	uint32_t u;
	struct bdk_smmux_nscr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t shypmode1                   : 1;  /**< SR/W - Only exists in the secure copy of this register. */
		uint32_t shypmode0                   : 1;
		uint32_t nscfg                       : 2;  /**< SR/W - Non-secure configuration. Only exist in secure copy of register, RES0 in non-secure copy.
                                                                 This field only applies to secure transactions bypassing the SMMU stream mapping
                                                                 process.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure. */
		uint32_t wacfg                       : 2;  /**< RO - Write-allocate configuration, controls the allocation hint for write accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
		uint32_t racfg                       : 2;  /**< RO - Read-allocate configuration, controls the allocation hint for read accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
		uint32_t shcfg                       : 2;  /**< RO - Shared configuration. Applies to transactions that bypass the stream mapping table.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
		uint32_t smcfcfg                     : 1;  /**< RO - Stream match conflict fault configuration. Controls transactions with multiple matches in
                                                                 the stream mapping table.
                                                                 0 = Permit the transaction to bypass the SMMU.
                                                                 1 = Raise a stream match conflict fault.

                                                                 CNXXXX detects all stream match conflicts and always faults. */
		uint32_t mtcfg                       : 1;  /**< R/W - Memory type configuration, applies to transactions that bypass the stream mapping table.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes. */
		uint32_t memattr                     : 4;  /**< R/W - Memory attributes for bypass transactions if MTCFG == 1. */
		uint32_t bsu                         : 2;  /**< RO - Barrier sharability upgrade. Upgrades the sharability of barriers issued by client devices
                                                                 that are not mapped to a translation context bank by setting the minimum sharability
                                                                 domain applied to any barrier.  Applies to transactions bypassing the stream mapping
                                                                 table.
                                                                 00 = No effect.
                                                                 01 = Inner sharable.
                                                                 10 = Outer sharable.
                                                                 11 = Full system.

                                                                 Ignored in CNXXXX. */
		uint32_t fb                          : 1;  /**< R/W - Force broadcast of TLB and instruction cache maintenance operations. Applies to
                                                                 transactions bypassing the stream mapping table. Affects client TLB maintenance, BPIALL
                                                                 and ICIALLU operations. If FB=1, any affected operation is modified to the equivalent
                                                                 broadcast variant in the inner shareable domain.
                                                                 0 = Process affected operations as presented.
                                                                 1 = Upgrade affected operations to be broadcast within the inner sharable domain.

                                                                 Ignored in CNXXXX, as NCB clients do not initiate invalidates. */
		uint32_t ptm                         : 1;  /**< R/W - Private TLB maintenance hint.
                                                                 0 = Process affected operations as presented.
                                                                 1 = SMMU TLBs are privately managed and are not require to respond to broadcast TLB
                                                                 maintenance operations from the wider system.

                                                                 CNXXXX honors this hint, but both the secure and non-secure version must be set for
                                                                 private management. INTERNAL: Note when set SMMU always still sends a response for the
                                                                 invalidates, it just does not perform the invalidation action against the TLB/WCU. */
		uint32_t vmidpne                     : 1;  /**< RO - VMID private namespace enable hint.
                                                                 0 = SMMU values are coordinated with the wider system.
                                                                 1 = SMMU VMID values are a private namespace, not coordinated with the wider system.

                                                                 CNXXXX ignores this hint. */
		uint32_t usfcfg                      : 1;  /**< R/W - Unidentified stream fault configuration.
                                                                 0 = Permit any transaction that does not match any entries in the stream matching table to
                                                                 pass through.
                                                                 1 = Raise an unidentified stream fault on any transaction that does not match any stream
                                                                 matching table entry. */
		uint32_t gse                         : 1;  /**< RO - Global stall enable.
                                                                 0 = Do not enforce global stalling across contexts.
                                                                 1 = Enforce global stalling across contexts.

                                                                 In CNXXXX always 0, no stalling. */
		uint32_t stalld                      : 1;  /**< RO - Stall disable.
                                                                 0 = Permit per-context stalling on context faults.
                                                                 1 = Disable per-context stalling on context faults, or not programmable.

                                                                 In CNXXXX always 1, no stalling. */
		uint32_t transientcfg                : 2;  /**< RO - Transient configuration controls the transient allocation hint.
                                                                 00 = Default transient allocation attributes.
                                                                 01 = Reserved.
                                                                 10 = Non-transient.
                                                                 11 = Transient.

                                                                 Not implemented in CNXXXX. */
		uint32_t gcfgfie                     : 1;  /**< RO - Global configuration fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global configuration fault
                                                                 1 = Raise an interrupt on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
		uint32_t gcfgfre                     : 1;  /**< RO - Global configuration fault report enable.
                                                                 0 = Do not return an abort on a global configuration fault
                                                                 1 = Return an abort on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
		uint32_t exidenable                  : 1;  /**< R/W - Extended stream ID enable.
                                                                 0 = For this SSD, SMMU()_SMR() has the format with the VALID bit in the
                                                                 SMMU()_SMR(). The SMMU()_S2CR()[EXIDVALID] is ignored.
                                                                 1 = For this SSD, SMMU()_SMR() has the extended id format and the valid bit is
                                                                 held in the corresponding SMMU()_S2CR()[EXIDVALID].

                                                                 Software should only change [EXIDENABLE] when all SMMU()_S2CR().[EXIDVALID] == 0
                                                                 and SMMU()_SMR().[EXMASK[15]/VALID] == 0 for the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use. */
		uint32_t gfie                        : 1;  /**< R/W - Global fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global fault.
                                                                 1 = Raise an interrupt on a global fault. */
		uint32_t gfre                        : 1;  /**< R/W - Global fault report enable.
                                                                 0 = Do not return an abort on a global fault.
                                                                 1 = Return an abort on a global fault. */
		uint32_t clientpd                    : 1;  /**< R/W - Client port disable.
                                                                 0 = Each SMMU client access is subject to translation, access control and attribute
                                                                 generation.
                                                                 1 = Each SMMU client access bypasses translation, access control and attribute generation. */
#else
		uint32_t clientpd                    : 1;
		uint32_t gfre                        : 1;
		uint32_t gfie                        : 1;
		uint32_t exidenable                  : 1;
		uint32_t gcfgfre                     : 1;
		uint32_t gcfgfie                     : 1;
		uint32_t transientcfg                : 2;
		uint32_t stalld                      : 1;
		uint32_t gse                         : 1;
		uint32_t usfcfg                      : 1;
		uint32_t vmidpne                     : 1;
		uint32_t ptm                         : 1;
		uint32_t fb                          : 1;
		uint32_t bsu                         : 2;
		uint32_t memattr                     : 4;
		uint32_t mtcfg                       : 1;
		uint32_t smcfcfg                     : 1;
		uint32_t shcfg                       : 2;
		uint32_t racfg                       : 2;
		uint32_t wacfg                       : 2;
		uint32_t nscfg                       : 2;
		uint32_t shypmode0                   : 1;
		uint32_t shypmode1                   : 1;
#endif
	} s;
	/* struct bdk_smmux_nscr0_s           cn88xx; */
	/* struct bdk_smmux_nscr0_s           cn88xxp1; */
} bdk_smmux_nscr0_t;

static inline uint64_t BDK_SMMUX_NSCR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSCR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000400ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSCR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSCR0(...) bdk_smmux_nscr0_t
#define bustype_BDK_SMMUX_NSCR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSCR0(p1) (p1)
#define arguments_BDK_SMMUX_NSCR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSCR0(...) "SMMUX_NSCR0"


/**
 * NCB32b - smmu#_nscr2
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)CR2.
 *
 */
typedef union bdk_smmux_nscr2 {
	uint32_t u;
	struct bdk_smmux_nscr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t bpvmid                      : 16; /**< RAZ - Bypass VMID. VMID field applied to client transactions that bypass the SMMU. In CNXXXX,
                                                                 not supported. INTERNAL: If L2C adds support for QoS on a per VMID basis the L2C will also
                                                                 have a `secure' QoS setting, so this field should sremain not required. */
#else
		uint32_t bpvmid                      : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_nscr2_s           cn88xx; */
	/* struct bdk_smmux_nscr2_s           cn88xxp1; */
} bdk_smmux_nscr2_t;

static inline uint64_t BDK_SMMUX_NSCR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSCR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000408ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSCR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSCR2(...) bdk_smmux_nscr2_t
#define bustype_BDK_SMMUX_NSCR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSCR2(p1) (p1)
#define arguments_BDK_SMMUX_NSCR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSCR2(...) "SMMUX_NSCR2"


/**
 * NCB - smmu#_nsgfar
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)GFAR.
 *
 */
typedef union bdk_smmux_nsgfar {
	uint64_t u;
	struct bdk_smmux_nsgfar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t faddr                       : 49; /**< R/W/H - Fault address, the input address of the faulty access. For configuration access faults,
                                                                 this is the physical address resulting in the fault. For other fault classes it is the
                                                                 input address of the faulting access, which the system can interpret in a number of ways.
                                                                 This register is updated before a valid context has been determined. Hence, no sign
                                                                 extension can have been performed.

                                                                 For CNXXXX \<11:0\> are always zero. */
#else
		uint64_t faddr                       : 49;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_smmux_nsgfar_s          cn88xx; */
	/* struct bdk_smmux_nsgfar_s          cn88xxp1; */
} bdk_smmux_nsgfar_t;

static inline uint64_t BDK_SMMUX_NSGFAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFAR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000440ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSGFAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSGFAR(...) bdk_smmux_nsgfar_t
#define bustype_BDK_SMMUX_NSGFAR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_NSGFAR(p1) (p1)
#define arguments_BDK_SMMUX_NSGFAR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSGFAR(...) "SMMUX_NSGFAR"


/**
 * NCB32b - smmu#_nsgfsr
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)GFSR.
 *
 */
typedef union bdk_smmux_nsgfsr {
	uint32_t u;
	struct bdk_smmux_nsgfsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t multi                       : 1;  /**< R/W1C/H - Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in this register was nonzero. */
		uint32_t reserved_9_30               : 22;
		uint32_t uut                         : 1;  /**< R/W1C/H - Unsupported upstream transaction.
                                                                 0 = No unsupported upstream transaction fault.
                                                                 1 = Unsupported upstream transaction fault caused by receipt of an unsupported client
                                                                 transaction from an upstream device. */
		uint32_t pf                          : 1;  /**< R/W1C/H - Permission fault. In SMMU_GFSR, this field is reserved. In SMMU_SGFSR, this field records
                                                                 global SMMU()_SCR1[SIF] faults.
                                                                 Note if a transaction is associated with a particular translation context bank, faults are
                                                                 recorded in SMMU()_CB()_FSR instead of SMMU_SGFSR. */
		uint32_t ef                          : 1;  /**< R/W1C/H - External fault. */
		uint32_t caf                         : 1;  /**< RO - Configuration access fault.
                                                                 For CNXXXX always zero, no configuration faults. */
		uint32_t ucif                        : 1;  /**< R/W1C/H - Unimplemented context interrupt fault. */
		uint32_t ucbf                        : 1;  /**< R/W1C/H - Unimplemented context bank fault. */
		uint32_t smcf                        : 1;  /**< R/W1C/H - Stream match conflict fault. */
		uint32_t usf                         : 1;  /**< R/W1C/H - Unidentified stream fault. */
		uint32_t icf                         : 1;  /**< R/W1C/H - Invalid context fault. */
#else
		uint32_t icf                         : 1;
		uint32_t usf                         : 1;
		uint32_t smcf                        : 1;
		uint32_t ucbf                        : 1;
		uint32_t ucif                        : 1;
		uint32_t caf                         : 1;
		uint32_t ef                          : 1;
		uint32_t pf                          : 1;
		uint32_t uut                         : 1;
		uint32_t reserved_9_30               : 22;
		uint32_t multi                       : 1;
#endif
	} s;
	/* struct bdk_smmux_nsgfsr_s          cn88xx; */
	/* struct bdk_smmux_nsgfsr_s          cn88xxp1; */
} bdk_smmux_nsgfsr_t;

static inline uint64_t BDK_SMMUX_NSGFSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000448ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSGFSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSGFSR(...) bdk_smmux_nsgfsr_t
#define bustype_BDK_SMMUX_NSGFSR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSGFSR(p1) (p1)
#define arguments_BDK_SMMUX_NSGFSR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSGFSR(...) "SMMUX_NSGFSR"


/**
 * NCB32b - smmu#_nsgfsrrestore
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)GFSRRESTORE.
 *
 */
typedef union bdk_smmux_nsgfsrrestore {
	uint32_t u;
	struct bdk_smmux_nsgfsrrestore_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t restore                     : 32; /**< WO - Writes bits in corresponding SMMU()_(S)GFSR. */
#else
		uint32_t restore                     : 32;
#endif
	} s;
	/* struct bdk_smmux_nsgfsrrestore_s   cn88xx; */
	/* struct bdk_smmux_nsgfsrrestore_s   cn88xxp1; */
} bdk_smmux_nsgfsrrestore_t;

static inline uint64_t BDK_SMMUX_NSGFSRRESTORE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSRRESTORE(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000083000000044Cull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSGFSRRESTORE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSGFSRRESTORE(...) bdk_smmux_nsgfsrrestore_t
#define bustype_BDK_SMMUX_NSGFSRRESTORE(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSGFSRRESTORE(p1) (p1)
#define arguments_BDK_SMMUX_NSGFSRRESTORE(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSGFSRRESTORE(...) "SMMUX_NSGFSRRESTORE"


/**
 * NCB32b - smmu#_nsgfsynr0
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)GFSYNR0.
 *
 */
typedef union bdk_smmux_nsgfsynr0 {
	uint32_t u;
	struct bdk_smmux_nsgfsynr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t imp                         : 8;  /**< RO - Reserved for implementation. */
		uint32_t reserved_7_7                : 1;
		uint32_t ats                         : 1;  /**< RO - Address translation operation fault. For CNXXXX zero, SMMU()_IDR0[ATOSNS] not supported. */
		uint32_t nsattr                      : 1;  /**< R/W/H - Non-secure attribute.
                                                                 0 = The faulty transaction has the secure attribute.
                                                                 1 = The faulty transaction has the non-secure attribute. */
		uint32_t nsstate                     : 1;  /**< SR/W/H - Non-secure state.
                                                                 0 = The faulty transaction is associated with a secure device.
                                                                 1 = The faulty transaction is associated with a non-secure device.

                                                                 This field is only valid for the secure state.

                                                                 This field may read '1' in the event that a fault is encountered in relation to a
                                                                 non-secure client device and where SMMU()_SCR1[GEFRO]='1'. */
		uint32_t ind                         : 1;  /**< R/W/H - Instruction not data.
                                                                 0 = The faulty transaction has the data access attribute.
                                                                 1 = The faulty transaction has the instruction access attribute. */
		uint32_t pnu                         : 1;  /**< R/W/H - Privileged not unprivileged.
                                                                 0 = The faulty transaction has the unprivileged attribute.
                                                                 1 = The faulty transaction has the privileged attribute. */
		uint32_t wnr                         : 1;  /**< R/W/H - Write not read.
                                                                 0 = The faulty transaction is a read.
                                                                 1 = The faulty transaction is a write. */
		uint32_t nested                      : 1;  /**< R/W/H - Nested fault.
                                                                 0 = The fault occurred in the initial stream context.
                                                                 1 = The fault occurred in a nested context.

                                                                 This bit is reserved in SMMU_SGFSYNR0. */
#else
		uint32_t nested                      : 1;
		uint32_t wnr                         : 1;
		uint32_t pnu                         : 1;
		uint32_t ind                         : 1;
		uint32_t nsstate                     : 1;
		uint32_t nsattr                      : 1;
		uint32_t ats                         : 1;
		uint32_t reserved_7_7                : 1;
		uint32_t imp                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_nsgfsynr0_s       cn88xx; */
	/* struct bdk_smmux_nsgfsynr0_s       cn88xxp1; */
} bdk_smmux_nsgfsynr0_t;

static inline uint64_t BDK_SMMUX_NSGFSYNR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSYNR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000450ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSGFSYNR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSGFSYNR0(...) bdk_smmux_nsgfsynr0_t
#define bustype_BDK_SMMUX_NSGFSYNR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSGFSYNR0(p1) (p1)
#define arguments_BDK_SMMUX_NSGFSYNR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSGFSYNR0(...) "SMMUX_NSGFSYNR0"


/**
 * NCB32b - smmu#_nsgfsynr1
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)GFSYNR1.
 *
 */
typedef union bdk_smmux_nsgfsynr1 {
	uint32_t u;
	struct bdk_smmux_nsgfsynr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ssd_index                   : 16; /**< SRO/H - The SSD_Index of the transaction that caused the fault. The SSD_Index field is only
                                                                 accessible to configuration accesses by secure software. Non-secure configuration accesses
                                                                 treat this field as RAZ/WI.

                                                                 For CNXXXX, the SSD_INDEX is always the same as [STREAMID]. */
		uint32_t streamid                    : 16; /**< R/W/H - The stream ID of the transaction that caused the fault. */
#else
		uint32_t streamid                    : 16;
		uint32_t ssd_index                   : 16;
#endif
	} s;
	/* struct bdk_smmux_nsgfsynr1_s       cn88xx; */
	/* struct bdk_smmux_nsgfsynr1_s       cn88xxp1; */
} bdk_smmux_nsgfsynr1_t;

static inline uint64_t BDK_SMMUX_NSGFSYNR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSYNR1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000454ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSGFSYNR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSGFSYNR1(...) bdk_smmux_nsgfsynr1_t
#define bustype_BDK_SMMUX_NSGFSYNR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSGFSYNR1(p1) (p1)
#define arguments_BDK_SMMUX_NSGFSYNR1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSGFSYNR1(...) "SMMUX_NSGFSYNR1"


/**
 * NCB32b - smmu#_nsgfsynr2
 *
 * Provides secure alias for non-secure register SMMU(0..3)_(S)GFSYNR2.
 *
 */
typedef union bdk_smmux_nsgfsynr2 {
	uint32_t u;
	struct bdk_smmux_nsgfsynr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_nsgfsynr2_s       cn88xx; */
	/* struct bdk_smmux_nsgfsynr2_s       cn88xxp1; */
} bdk_smmux_nsgfsynr2_t;

static inline uint64_t BDK_SMMUX_NSGFSYNR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSGFSYNR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000458ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSGFSYNR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSGFSYNR2(...) bdk_smmux_nsgfsynr2_t
#define bustype_BDK_SMMUX_NSGFSYNR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSGFSYNR2(p1) (p1)
#define arguments_BDK_SMMUX_NSGFSYNR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSGFSYNR2(...) "SMMUX_NSGFSYNR2"


/**
 * NCB - smmu#_nsmiss_perf
 */
typedef union bdk_smmux_nsmiss_perf {
	uint64_t u;
	struct bdk_smmux_nsmiss_perf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< R/W/H - Counts the number of lookup requests in non-secure mode which missed the IOTLB. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_nsmiss_perf_s     cn88xx; */
	/* struct bdk_smmux_nsmiss_perf_s     cn88xxp1; */
} bdk_smmux_nsmiss_perf_t;

static inline uint64_t BDK_SMMUX_NSMISS_PERF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSMISS_PERF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021030ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSMISS_PERF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSMISS_PERF(...) bdk_smmux_nsmiss_perf_t
#define bustype_BDK_SMMUX_NSMISS_PERF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_NSMISS_PERF(p1) (p1)
#define arguments_BDK_SMMUX_NSMISS_PERF(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSMISS_PERF(...) "SMMUX_NSMISS_PERF"


/**
 * NCB - smmu#_nsptread_perf
 */
typedef union bdk_smmux_nsptread_perf {
	uint64_t u;
	struct bdk_smmux_nsptread_perf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< R/W/H - Counts the number of page table reads issued to non-secure memory. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_nsptread_perf_s   cn88xx; */
	/* struct bdk_smmux_nsptread_perf_s   cn88xxp1; */
} bdk_smmux_nsptread_perf_t;

static inline uint64_t BDK_SMMUX_NSPTREAD_PERF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSPTREAD_PERF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021050ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSPTREAD_PERF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSPTREAD_PERF(...) bdk_smmux_nsptread_perf_t
#define bustype_BDK_SMMUX_NSPTREAD_PERF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_NSPTREAD_PERF(p1) (p1)
#define arguments_BDK_SMMUX_NSPTREAD_PERF(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSPTREAD_PERF(...) "SMMUX_NSPTREAD_PERF"


/**
 * NCB32b - smmu#_nstlbgstatus
 *
 * Gives the status of a TLB maintenance operation.
 *
 */
typedef union bdk_smmux_nstlbgstatus {
	uint32_t u;
	struct bdk_smmux_nstlbgstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t gsactive                    : 1;  /**< RO/H - Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
#else
		uint32_t gsactive                    : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_smmux_nstlbgstatus_s    cn88xx; */
	/* struct bdk_smmux_nstlbgstatus_s    cn88xxp1; */
} bdk_smmux_nstlbgstatus_t;

static inline uint64_t BDK_SMMUX_NSTLBGSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSTLBGSTATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000474ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSTLBGSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSTLBGSTATUS(...) bdk_smmux_nstlbgstatus_t
#define bustype_BDK_SMMUX_NSTLBGSTATUS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSTLBGSTATUS(p1) (p1)
#define arguments_BDK_SMMUX_NSTLBGSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSTLBGSTATUS(...) "SMMUX_NSTLBGSTATUS"


/**
 * NCB32b - smmu#_nstlbgsync
 *
 * Starts a global synchronization operation that ensures the completion of any previously
 * accepted TLB invalidate operation.
 */
typedef union bdk_smmux_nstlbgsync {
	uint32_t u;
	struct bdk_smmux_nstlbgsync_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< WO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_nstlbgsync_s      cn88xx; */
	/* struct bdk_smmux_nstlbgsync_s      cn88xxp1; */
} bdk_smmux_nstlbgsync_t;

static inline uint64_t BDK_SMMUX_NSTLBGSYNC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_NSTLBGSYNC(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000470ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_NSTLBGSYNC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_NSTLBGSYNC(...) bdk_smmux_nstlbgsync_t
#define bustype_BDK_SMMUX_NSTLBGSYNC(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_NSTLBGSYNC(p1) (p1)
#define arguments_BDK_SMMUX_NSTLBGSYNC(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_NSTLBGSYNC(...) "SMMUX_NSTLBGSYNC"


/**
 * NCB32b - smmu#_pidr0
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr0 {
	uint32_t u;
	struct bdk_smmux_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number \<7:0\>.  Indicates PCC_PIDR_PARTNUM0_E::SMMU. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_pidr0_s           cn88xx; */
	/* struct bdk_smmux_pidr0_s           cn88xxp1; */
} bdk_smmux_pidr0_t;

static inline uint64_t BDK_SMMUX_PIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FE0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR0(...) bdk_smmux_pidr0_t
#define bustype_BDK_SMMUX_PIDR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR0(p1) (p1)
#define arguments_BDK_SMMUX_PIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR0(...) "SMMUX_PIDR0"


/**
 * NCB32b - smmu#_pidr1
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr1 {
	uint32_t u;
	struct bdk_smmux_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - JEP106 identification code \<3:0\>. Cavium code is 0x4C. */
		uint32_t partnum1                    : 4;  /**< RO - Part number \<11:8\>.  Indicates PCC_PIDR_PARTNUM1_E::COMP. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_pidr1_s           cn88xx; */
	/* struct bdk_smmux_pidr1_s           cn88xxp1; */
} bdk_smmux_pidr1_t;

static inline uint64_t BDK_SMMUX_PIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FE4ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR1(...) bdk_smmux_pidr1_t
#define bustype_BDK_SMMUX_PIDR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR1(p1) (p1)
#define arguments_BDK_SMMUX_PIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR1(...) "SMMUX_PIDR1"


/**
 * NCB32b - smmu#_pidr2
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr2 {
	uint32_t u;
	struct bdk_smmux_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - SMMU Revision.
                                                                 0x0 = SMMUv1.
                                                                 0x1 = SMMUv2. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. */
		uint32_t idcode                      : 3;  /**< RO - JEP106 identification code \<6:4\>. Cavium code is 0x4C. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_pidr2_s           cn88xx; */
	/* struct bdk_smmux_pidr2_s           cn88xxp1; */
} bdk_smmux_pidr2_t;

static inline uint64_t BDK_SMMUX_PIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FE8ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR2(...) bdk_smmux_pidr2_t
#define bustype_BDK_SMMUX_PIDR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR2(p1) (p1)
#define arguments_BDK_SMMUX_PIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR2(...) "SMMUX_PIDR2"


/**
 * NCB32b - smmu#_pidr3
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr3 {
	uint32_t u;
	struct bdk_smmux_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_pidr3_s           cn88xx; */
	/* struct bdk_smmux_pidr3_s           cn88xxp1; */
} bdk_smmux_pidr3_t;

static inline uint64_t BDK_SMMUX_PIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR3(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FECull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR3(...) bdk_smmux_pidr3_t
#define bustype_BDK_SMMUX_PIDR3(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR3(p1) (p1)
#define arguments_BDK_SMMUX_PIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR3(...) "SMMUX_PIDR3"


/**
 * NCB32b - smmu#_pidr4
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr4 {
	uint32_t u;
	struct bdk_smmux_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t pagecnt                     : 4;  /**< RO - Number of log-2 4 KB blocks occupied. */
		uint32_t jepcont                     : 4;  /**< RO - JEP106 continuation code, least significant nibble. Indicates Cavium. */
#else
		uint32_t jepcont                     : 4;
		uint32_t pagecnt                     : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_smmux_pidr4_s           cn88xx; */
	/* struct bdk_smmux_pidr4_s           cn88xxp1; */
} bdk_smmux_pidr4_t;

static inline uint64_t BDK_SMMUX_PIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR4(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FD0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR4(...) bdk_smmux_pidr4_t
#define bustype_BDK_SMMUX_PIDR4(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR4(p1) (p1)
#define arguments_BDK_SMMUX_PIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR4(...) "SMMUX_PIDR4"


/**
 * NCB32b - smmu#_pidr5
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr5 {
	uint32_t u;
	struct bdk_smmux_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_pidr5_s           cn88xx; */
	/* struct bdk_smmux_pidr5_s           cn88xxp1; */
} bdk_smmux_pidr5_t;

static inline uint64_t BDK_SMMUX_PIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR5(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FD4ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR5(...) bdk_smmux_pidr5_t
#define bustype_BDK_SMMUX_PIDR5(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR5(p1) (p1)
#define arguments_BDK_SMMUX_PIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR5(...) "SMMUX_PIDR5"


/**
 * NCB32b - smmu#_pidr6
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr6 {
	uint32_t u;
	struct bdk_smmux_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_pidr6_s           cn88xx; */
	/* struct bdk_smmux_pidr6_s           cn88xxp1; */
} bdk_smmux_pidr6_t;

static inline uint64_t BDK_SMMUX_PIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR6(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FD8ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR6(...) bdk_smmux_pidr6_t
#define bustype_BDK_SMMUX_PIDR6(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR6(p1) (p1)
#define arguments_BDK_SMMUX_PIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR6(...) "SMMUX_PIDR6"


/**
 * NCB32b - smmu#_pidr7
 *
 * This register is visible regardless of the setting of SMMU()_SCR1[GASRAE].
 *
 */
typedef union bdk_smmux_pidr7 {
	uint32_t u;
	struct bdk_smmux_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_pidr7_s           cn88xx; */
	/* struct bdk_smmux_pidr7_s           cn88xxp1; */
} bdk_smmux_pidr7_t;

static inline uint64_t BDK_SMMUX_PIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_PIDR7(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000FDCull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_PIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_PIDR7(...) bdk_smmux_pidr7_t
#define bustype_BDK_SMMUX_PIDR7(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_PIDR7(p1) (p1)
#define arguments_BDK_SMMUX_PIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_PIDR7(...) "SMMUX_PIDR7"


/**
 * NCB32b - smmu#_s2cr#
 *
 * Specifies the translation context for processing a transaction where the transaction matches
 * the stream mapping group to which this register belongs.
 * An SMMU()_S2CR() register reserved by secure software using
 * SMMU()_SCR1[NSNUMSMRGO] must only specify a translation context bank that is reserved by
 * secure software. An SMMU()_S2CR() register that is accessible from the non-secure
 * state must only specify a translation context bank that is not reserved by secure software
 */
typedef union bdk_smmux_s2crx {
	uint32_t u;
	struct bdk_smmux_s2crx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t imp                         : 2;  /**< RAZ - Reserved. */
		uint32_t transientcfg                : 2;  /**< RO - For CTYPE=0 or 1, transient allocate configuration.

                                                                 0 = Use the default transient allocation attributes.
                                                                 1 = Reserved.
                                                                 2 = Non-transient.
                                                                 3 = Transient.

                                                                 For CTYPE=2, reserved.

                                                                 In CNXXXX this field is not implemented. */
		uint32_t instcfg_fb                  : 2;  /**< R/W - For CTYPE=0, \<27:26\> is INSTCFG, instruction fetch attribute configuration. Ignored in
                                                                 CNXXXX.

                                                                 For CTYPE=1, \<27\> reserved, \<26\> is FB, force broadcast. Force broadcast of TLB and
                                                                 instruction cache maintenance operations. Ignored in CNXXXX, as NCB clients do not
                                                                 initiate invalidates.

                                                                 For CTYPE=2, reserved. */
		uint32_t privcfg_bsu                 : 2;  /**< R/W - For CTYPE=0, PRIVCFG, privileged attribute configuration.

                                                                 0 = Default privilege attribute.

                                                                 1 = Privledged access never.  This encoding is reserved if SMMU()_IDR2[DIPANS] is
                                                                     clear.
                                                                     When a context bank is configured to use this encoding, then any transaction from
                                                                     the upstream device is considered to be marked as privileged and any attempt to access
                                                                     a user-accessible page will result in a permission fault.  Thus a device that is
                                                                     expected to operate only on privileged data will fault if it is misprogrammed and
                                                                     tries to access user data accessible through the corresponding context bank.
                                                                     For SMMU()_S2CR() that are configured as bypass, then there is no associated
                                                                     context bank and no permission checks.
                                                                     Thus the only effect of this bit is to mark the downstream transaction as privileged;
                                                                     it behaves identically to encoding 0x3, "Privileged".
                                                                     For E2HC banks then there are two levels of privilege and this encoding behaves as
                                                                     normal.

                                                                 2 = Unprivileged.

                                                                 3 = Privileged.

                                                                 For CTYPE=1, BSU, barrier shareability upgrade. Ignored in CNXXXX.

                                                                 For CTYPE=2, reserved. */
		uint32_t wacfg                       : 2;  /**< RO - For CTYPE=0 or 1, write allocate configuration.

                                                                 0 = Default allocation attribute.
                                                                 1 = Reserved.
                                                                 2 = Write-allocate.
                                                                 3 = No write-allocate.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
		uint32_t racfg                       : 2;  /**< RO - For CTYPE=0 or 1, read allocate configuration.

                                                                 0 = Default allocation attribute.
                                                                 1 = Reserved.
                                                                 2 = Read-allocate.
                                                                 3 = No read-allocate.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
		uint32_t nscfg                       : 2;  /**< SR/W - For CTYPE=0 or 1, Non-secure configuration.

                                                                 0 = Default security attribute.
                                                                 1 = Reserved.
                                                                 2 = Secure configuration.
                                                                 3 = Non secure configuration.

                                                                 For CTYPE=2, reserved.

                                                                 This field exists only for secure stream mapping register groups. */
		uint32_t ctype                       : 2;  /**< R/W - Context register type. Indicates the meaning of the remaining fields in this register:
                                                                 0 = Translation context bank index.
                                                                 1 = Bypass mode.
                                                                 2 = Fault, no index.
                                                                 3 = Reserved. */
		uint32_t memattr                     : 4;  /**< R/W - For CTYPE=0 or 1, memory attributes.

                                                                 For CTYPE=2, reserved. */
		uint32_t mtcfg                       : 1;  /**< R/W - For CTYPE=0 or 1, memory type configuration.

                                                                 0 = Default memory attributes.
                                                                 1 = [MEMATTR] field attributes.

                                                                 For CTYPE=2, reserved. */
		uint32_t exidvalid                   : 1;  /**< R/W - Extended ID valid.
                                                                 0 = The stream match register group is valid if SMMU()_SMR()[VALID] is set and
                                                                 SMMU(0..3)_(S)CR0[EXIDENABLE] is clear, for backward compatibility.
                                                                 1 = The stream match register group is valid and SMMU()_SMR()[VALID] is used as
                                                                 an extra mask bit. CNXXXX recommends this setting. */
		uint32_t shcfg                       : 2;  /**< RO - For CTYPE=0 or 1, Sharability configuration.
                                                                 0 = Default sharability attribute.
                                                                 1 = Outer sharable.
                                                                 2 = Inner sharable.
                                                                 3 = Non-sharable.

                                                                 For CTYPE=2, reserved.

                                                                 For CNXXXX not implemented. */
		uint32_t cbndx                       : 8;  /**< R/W - For CTYPE=0, Context bank index.

                                                                 For CTYPE=1, VMID, not implemented in CNXXXX.

                                                                 For CTYPE=2, reserved.

                                                                 A secure SMMU()_S2CR() register configured to specify a translation context bank
                                                                 is only permitted to specify a CBNDX corresponding to a translation context bank that is
                                                                 also reserved by secure software, or specify a translation context bank configured for the
                                                                 Stage 1 context with stage 2 bypass format. */
#else
		uint32_t cbndx                       : 8;
		uint32_t shcfg                       : 2;
		uint32_t exidvalid                   : 1;
		uint32_t mtcfg                       : 1;
		uint32_t memattr                     : 4;
		uint32_t ctype                       : 2;
		uint32_t nscfg                       : 2;
		uint32_t racfg                       : 2;
		uint32_t wacfg                       : 2;
		uint32_t privcfg_bsu                 : 2;
		uint32_t instcfg_fb                  : 2;
		uint32_t transientcfg                : 2;
		uint32_t imp                         : 2;
#endif
	} s;
	/* struct bdk_smmux_s2crx_s           cn88xx; */
	/* struct bdk_smmux_s2crx_s           cn88xxp1; */
} bdk_smmux_s2crx_t;

static inline uint64_t BDK_SMMUX_S2CRX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_S2CRX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830000000C00ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x4ull;
	csr_fatal("BDK_SMMUX_S2CRX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_S2CRX(...) bdk_smmux_s2crx_t
#define bustype_BDK_SMMUX_S2CRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_S2CRX(p1,p2) (p1)
#define arguments_BDK_SMMUX_S2CRX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_S2CRX(...) "SMMUX_S2CRX"


/**
 * NCB - smmu#_s_hit_perf
 */
typedef union bdk_smmux_s_hit_perf {
	uint64_t u;
	struct bdk_smmux_s_hit_perf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< SR/W/H - Counts the number of hits in secure mode. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_s_hit_perf_s      cn88xx; */
	/* struct bdk_smmux_s_hit_perf_s      cn88xxp1; */
} bdk_smmux_s_hit_perf_t;

static inline uint64_t BDK_SMMUX_S_HIT_PERF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_S_HIT_PERF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021020ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_S_HIT_PERF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_S_HIT_PERF(...) bdk_smmux_s_hit_perf_t
#define bustype_BDK_SMMUX_S_HIT_PERF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_S_HIT_PERF(p1) (p1)
#define arguments_BDK_SMMUX_S_HIT_PERF(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_S_HIT_PERF(...) "SMMUX_S_HIT_PERF"


/**
 * NCB32b - smmu#_sacr
 *
 * This register contains implementation specific context fields.
 *
 */
typedef union bdk_smmux_sacr {
	uint32_t u;
	struct bdk_smmux_sacr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t qos                         : 4;  /**< R/W - L2C quality-of-service value to use for standard transactions that are not by a specific
                                                                 context, and so SMMU()_CB()_ACTLR[QOS] is not applicable. */
		uint32_t qos_walk                    : 4;  /**< R/W - L2C quality-of-service value to use for page table walks. For optimal performance, this
                                                                 typically would be set to the most preferential QoS value of zero. */
		uint32_t reserved_0_23               : 24;
#else
		uint32_t reserved_0_23               : 24;
		uint32_t qos_walk                    : 4;
		uint32_t qos                         : 4;
#endif
	} s;
	/* struct bdk_smmux_sacr_s            cn88xx; */
	/* struct bdk_smmux_sacr_s            cn88xxp1; */
} bdk_smmux_sacr_t;

static inline uint64_t BDK_SMMUX_SACR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SACR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000010ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SACR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SACR(...) bdk_smmux_sacr_t
#define bustype_BDK_SMMUX_SACR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SACR(p1) (p1)
#define arguments_BDK_SMMUX_SACR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SACR(...) "SMMUX_SACR"


/**
 * NCB32b - smmu#_scr0
 *
 * The non-secure version of this register does not provide full top-level control of the SMMU
 * for secure transactions. Some fields only apply to non-secure transactions.
 */
typedef union bdk_smmux_scr0 {
	uint32_t u;
	struct bdk_smmux_scr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t shypmode1                   : 1;  /**< SR/W - Only exists in the secure copy of this register. */
		uint32_t shypmode0                   : 1;
		uint32_t nscfg                       : 2;  /**< SR/W - Non-secure configuration. Only exist in secure copy of register, RES0 in non-secure copy.
                                                                 This field only applies to secure transactions bypassing the SMMU stream mapping
                                                                 process.
                                                                 00 = Use default NS attribute.
                                                                 01 = Reserved.
                                                                 10 = Secure.
                                                                 11 = Non-secure. */
		uint32_t wacfg                       : 2;  /**< RO - Write-allocate configuration, controls the allocation hint for write accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Write-allocate.
                                                                 11 = No write-allocate.

                                                                 Ignored in CNXXXX. */
		uint32_t racfg                       : 2;  /**< RO - Read-allocate configuration, controls the allocation hint for read accesses. This field
                                                                 applies to transactions that bypass the stream mapping table.
                                                                 00 = Default attributes.
                                                                 01 = Reserved.
                                                                 10 = Read-allocate.
                                                                 11 = No read-allocate.

                                                                 Ignored in CNXXXX. */
		uint32_t shcfg                       : 2;  /**< RO - Shared configuration. Applies to transactions that bypass the stream mapping table.
                                                                 00 = Default shareable attributes.
                                                                 01 = Outer sharable.
                                                                 10 = Inner sharable.
                                                                 11 = Non-sharable.

                                                                 Ignored in CNXXXX. */
		uint32_t smcfcfg                     : 1;  /**< RO - Stream match conflict fault configuration. Controls transactions with multiple matches in
                                                                 the stream mapping table.
                                                                 0 = Permit the transaction to bypass the SMMU.
                                                                 1 = Raise a stream match conflict fault.

                                                                 CNXXXX detects all stream match conflicts and always faults. */
		uint32_t mtcfg                       : 1;  /**< R/W - Memory type configuration, applies to transactions that bypass the stream mapping table.
                                                                 0 = Use the default memory attributes.
                                                                 1 = Use the MEMATTR field for memory attributes. */
		uint32_t memattr                     : 4;  /**< R/W - Memory attributes for bypass transactions if MTCFG == 1. */
		uint32_t bsu                         : 2;  /**< RO - Barrier sharability upgrade. Upgrades the sharability of barriers issued by client devices
                                                                 that are not mapped to a translation context bank by setting the minimum sharability
                                                                 domain applied to any barrier.  Applies to transactions bypassing the stream mapping
                                                                 table.
                                                                 00 = No effect.
                                                                 01 = Inner sharable.
                                                                 10 = Outer sharable.
                                                                 11 = Full system.

                                                                 Ignored in CNXXXX. */
		uint32_t fb                          : 1;  /**< R/W - Force broadcast of TLB and instruction cache maintenance operations. Applies to
                                                                 transactions bypassing the stream mapping table. Affects client TLB maintenance, BPIALL
                                                                 and ICIALLU operations. If FB=1, any affected operation is modified to the equivalent
                                                                 broadcast variant in the inner shareable domain.
                                                                 0 = Process affected operations as presented.
                                                                 1 = Upgrade affected operations to be broadcast within the inner sharable domain.

                                                                 Ignored in CNXXXX, as NCB clients do not initiate invalidates. */
		uint32_t ptm                         : 1;  /**< R/W - Private TLB maintenance hint.
                                                                 0 = Process affected operations as presented.
                                                                 1 = SMMU TLBs are privately managed and are not require to respond to broadcast TLB
                                                                 maintenance operations from the wider system.

                                                                 CNXXXX honors this hint, but both the secure and non-secure version must be set for
                                                                 private management. INTERNAL: Note when set SMMU always still sends a response for the
                                                                 invalidates, it just does not perform the invalidation action against the TLB/WCU. */
		uint32_t vmidpne                     : 1;  /**< RO - VMID private namespace enable hint.
                                                                 0 = SMMU values are coordinated with the wider system.
                                                                 1 = SMMU VMID values are a private namespace, not coordinated with the wider system.

                                                                 CNXXXX ignores this hint. */
		uint32_t usfcfg                      : 1;  /**< R/W - Unidentified stream fault configuration.
                                                                 0 = Permit any transaction that does not match any entries in the stream matching table to
                                                                 pass through.
                                                                 1 = Raise an unidentified stream fault on any transaction that does not match any stream
                                                                 matching table entry. */
		uint32_t gse                         : 1;  /**< RO - Global stall enable.
                                                                 0 = Do not enforce global stalling across contexts.
                                                                 1 = Enforce global stalling across contexts.

                                                                 In CNXXXX always 0, no stalling. */
		uint32_t stalld                      : 1;  /**< RO - Stall disable.
                                                                 0 = Permit per-context stalling on context faults.
                                                                 1 = Disable per-context stalling on context faults, or not programmable.

                                                                 In CNXXXX always 1, no stalling. */
		uint32_t transientcfg                : 2;  /**< RO - Transient configuration controls the transient allocation hint.
                                                                 00 = Default transient allocation attributes.
                                                                 01 = Reserved.
                                                                 10 = Non-transient.
                                                                 11 = Transient.

                                                                 Not implemented in CNXXXX. */
		uint32_t gcfgfie                     : 1;  /**< RO - Global configuration fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global configuration fault
                                                                 1 = Raise an interrupt on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
		uint32_t gcfgfre                     : 1;  /**< RO - Global configuration fault report enable.
                                                                 0 = Do not return an abort on a global configuration fault
                                                                 1 = Return an abort on a global configuration fault.

                                                                 In CNXXXX always zero, as does not support configuration faults. */
		uint32_t exidenable                  : 1;  /**< R/W - Extended stream ID enable.
                                                                 0 = For this SSD, SMMU()_SMR() has the format with the VALID bit in the
                                                                 SMMU()_SMR(). The SMMU()_S2CR()[EXIDVALID] is ignored.
                                                                 1 = For this SSD, SMMU()_SMR() has the extended id format and the valid bit is
                                                                 held in the corresponding SMMU()_S2CR()[EXIDVALID].

                                                                 Software should only change [EXIDENABLE] when all SMMU()_S2CR().[EXIDVALID] == 0
                                                                 and SMMU()_SMR().[EXMASK[15]/VALID] == 0 for the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use. */
		uint32_t gfie                        : 1;  /**< R/W - Global fault interrupt enable.
                                                                 0 = Do not raise an interrupt on a global fault.
                                                                 1 = Raise an interrupt on a global fault. */
		uint32_t gfre                        : 1;  /**< R/W - Global fault report enable.
                                                                 0 = Do not return an abort on a global fault.
                                                                 1 = Return an abort on a global fault. */
		uint32_t clientpd                    : 1;  /**< R/W - Client port disable.
                                                                 0 = Each SMMU client access is subject to translation, access control and attribute
                                                                 generation.
                                                                 1 = Each SMMU client access bypasses translation, access control and attribute generation. */
#else
		uint32_t clientpd                    : 1;
		uint32_t gfre                        : 1;
		uint32_t gfie                        : 1;
		uint32_t exidenable                  : 1;
		uint32_t gcfgfre                     : 1;
		uint32_t gcfgfie                     : 1;
		uint32_t transientcfg                : 2;
		uint32_t stalld                      : 1;
		uint32_t gse                         : 1;
		uint32_t usfcfg                      : 1;
		uint32_t vmidpne                     : 1;
		uint32_t ptm                         : 1;
		uint32_t fb                          : 1;
		uint32_t bsu                         : 2;
		uint32_t memattr                     : 4;
		uint32_t mtcfg                       : 1;
		uint32_t smcfcfg                     : 1;
		uint32_t shcfg                       : 2;
		uint32_t racfg                       : 2;
		uint32_t wacfg                       : 2;
		uint32_t nscfg                       : 2;
		uint32_t shypmode0                   : 1;
		uint32_t shypmode1                   : 1;
#endif
	} s;
	/* struct bdk_smmux_scr0_s            cn88xx; */
	/* struct bdk_smmux_scr0_s            cn88xxp1; */
} bdk_smmux_scr0_t;

static inline uint64_t BDK_SMMUX_SCR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SCR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000000ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SCR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SCR0(...) bdk_smmux_scr0_t
#define bustype_BDK_SMMUX_SCR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SCR0(p1) (p1)
#define arguments_BDK_SMMUX_SCR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SCR0(...) "SMMUX_SCR0"


/**
 * NCB32b - smmu#_scr1
 *
 * Provides top-level secure control of the SMMU.
 *
 */
typedef union bdk_smmux_scr1 {
	uint32_t u;
	struct bdk_smmux_scr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_31_31              : 1;
		uint32_t nshypmodedisable            : 1;  /**< SR/W - Disables HYPC mode. */
		uint32_t reserved_29_29              : 1;
		uint32_t nscafro                     : 1;  /**< SRO - Non-secure configuration access fault report override.
                                                                 0 = Permit SMMU_SGFSR to report configuration access faults caused by non-secure accesses
                                                                 to secure-only registers.
                                                                 1 = SMMU_GFSR reports all such faults.

                                                                 In CNXXXX always zero, as does not support generation of configuration faults. */
		uint32_t spmen                       : 1;  /**< SR/W - Secure performance monitor enable.
                                                                 0 = Any event caused by secure transaction processing does not contribute towards
                                                                 performance monitor counting.
                                                                 1 = Any event caused by secure transaction processing is permitted to contribute towards
                                                                 performance monitor counting.

                                                                 Ignored in CNXXXX, no ARM architected performance monitoring, counters are separate
                                                                 between secure and non-secure. */
		uint32_t sif                         : 1;  /**< SR/W - Secure instruction fetch.
                                                                 0 = Secure instruction fetches are permitted to non-secure memory locations.
                                                                 1 = Raise a permission fault if a secure domain instruction fetch accesses a non-secure
                                                                 memory location.

                                                                 Ignored in CNXXXX, no instruction fetches from IO devices. */
		uint32_t gefro                       : 1;  /**< SR/W - Global external fault report override.

                                                                 0 = Permit SMMU_GFSR to report external faults.
                                                                 1 = SMMU_SGFSR reports all external faults.

                                                                 If SMMU()_SCR1[GEFRO]==1, all external aborts that would have been recorded in
                                                                 SMMU_GFSR are instead recorded in SMMU_SGFSR. */
		uint32_t gasrae                      : 1;  /**< SR/W - Global address space restricted access enable.
                                                                 0 = Global address space is accessible using either secure or non-secure configuration
                                                                 memory accesses.
                                                                 1 = Global address space is only accessible by secure configuration memory accesses. Stage
                                                                 2 format context banks (as determined by SMMU()_CBAR()[CTYPE]) are only
                                                                 accessible by secure configuration accesses.

                                                                 The following additional constraints apply:

                                                                 If 0, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a secure stage 1 translation context bank.

                                                                 If 1, secure software must avoid setting SMMU()_CBAR()[HYPC] to 1 when
                                                                 configuring a non-secure stage 1 translation context bank.

                                                                 In CNXXXX, implementation defined register accesses are also controlled by this bit. */
		uint32_t nsnumirpto                  : 8;  /**< SRO - Non-secure number of interrupts override. Always 1 in ARMv8. */
		uint32_t nsnumsmrgo                  : 8;  /**< SR/W - Adjusts the number of stream mapping register groups visible to non-secure accesses. The
                                                                 number of stream mapping register groups reported in SMMU()_IDR0 is reduced to the
                                                                 number indicated by NSNUMSMRGO.

                                                                 In CNXXXX if the value in NSNUMSMRGO exceeds the number of implemented stream match
                                                                 register groups then non-secure software might attempt to access an unimplemented stream
                                                                 match register group and such access are ignored.

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized before use.

                                                                 These bits reset to the implemented number of stream mapping register groups. */
		uint32_t nsnumcbo                    : 8;  /**< SR/W - Non-secure number of context banks override. adjusts the number of translation context
                                                                 banks visible to non-secure accesses. The number of translation context banks reported in
                                                                 SMMU()_IDR1[NUMCB] is reduced to the number indicated by SMMU()_SCR1[NSNUMCBO].

                                                                 In CNXXXX, software should only change [NSNUMSMRGO]/[NSNUMCBO] when
                                                                 SMMU()_S2CR()[EXIDVALID] == 0 and SMMU()_SMR()[EXMASK[15]/VALID] == 0
                                                                 for at minimum any contexts being moved into/out of the appropriate security world,
                                                                 otherwise the effect is unpredictable. In particular, note that the reset values of
                                                                 SMMU()_S2CR() and SMMU()_SMR() are unknown and so need to be
                                                                 initialized first. */
#else
		uint32_t nsnumcbo                    : 8;
		uint32_t nsnumsmrgo                  : 8;
		uint32_t nsnumirpto                  : 8;
		uint32_t gasrae                      : 1;
		uint32_t gefro                       : 1;
		uint32_t sif                         : 1;
		uint32_t spmen                       : 1;
		uint32_t nscafro                     : 1;
		uint32_t reserved_29_29              : 1;
		uint32_t nshypmodedisable            : 1;
		uint32_t reserved_31_31              : 1;
#endif
	} s;
	/* struct bdk_smmux_scr1_s            cn88xx; */
	/* struct bdk_smmux_scr1_s            cn88xxp1; */
} bdk_smmux_scr1_t;

static inline uint64_t BDK_SMMUX_SCR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SCR1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000004ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SCR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SCR1(...) bdk_smmux_scr1_t
#define bustype_BDK_SMMUX_SCR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SCR1(p1) (p1)
#define arguments_BDK_SMMUX_SCR1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SCR1(...) "SMMUX_SCR1"


/**
 * NCB32b - smmu#_scr2
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_scr2 {
	uint32_t u;
	struct bdk_smmux_scr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t bpvmid                      : 16; /**< RAZ - Bypass VMID. VMID field applied to client transactions that bypass the SMMU. In CNXXXX,
                                                                 not supported. INTERNAL: If L2C adds support for QoS on a per VMID basis the L2C will also
                                                                 have a `secure' QoS setting, so this field should sremain not required. */
#else
		uint32_t bpvmid                      : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_scr2_s            cn88xx; */
	/* struct bdk_smmux_scr2_s            cn88xxp1; */
} bdk_smmux_scr2_t;

static inline uint64_t BDK_SMMUX_SCR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SCR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000008ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SCR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SCR2(...) bdk_smmux_scr2_t
#define bustype_BDK_SMMUX_SCR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SCR2(p1) (p1)
#define arguments_BDK_SMMUX_SCR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SCR2(...) "SMMUX_SCR2"


/**
 * NCB - smmu#_sgfar
 *
 * Contains the input address of an erroneous request reported by SMMU()_(S)GFSR.
 *
 */
typedef union bdk_smmux_sgfar {
	uint64_t u;
	struct bdk_smmux_sgfar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t faddr                       : 49; /**< R/W/H - Fault address, the input address of the faulty access. For configuration access faults,
                                                                 this is the physical address resulting in the fault. For other fault classes it is the
                                                                 input address of the faulting access, which the system can interpret in a number of ways.
                                                                 This register is updated before a valid context has been determined. Hence, no sign
                                                                 extension can have been performed.

                                                                 For CNXXXX \<11:0\> are always zero. */
#else
		uint64_t faddr                       : 49;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_smmux_sgfar_s           cn88xx; */
	/* struct bdk_smmux_sgfar_s           cn88xxp1; */
} bdk_smmux_sgfar_t;

static inline uint64_t BDK_SMMUX_SGFAR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFAR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000040ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SGFAR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SGFAR(...) bdk_smmux_sgfar_t
#define bustype_BDK_SMMUX_SGFAR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_SGFAR(p1) (p1)
#define arguments_BDK_SMMUX_SGFAR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SGFAR(...) "SMMUX_SGFAR"


/**
 * NCB32b - smmu#_sgfsr
 */
typedef union bdk_smmux_sgfsr {
	uint32_t u;
	struct bdk_smmux_sgfsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t multi                       : 1;  /**< R/W1C/H - Multiple error conditions.
                                                                 0 = No multiple error condition was encountered.
                                                                 1 = An error occurred while the value in this register was nonzero. */
		uint32_t reserved_9_30               : 22;
		uint32_t uut                         : 1;  /**< R/W1C/H - Unsupported upstream transaction.
                                                                 0 = No unsupported upstream transaction fault.
                                                                 1 = Unsupported upstream transaction fault caused by receipt of an unsupported client
                                                                 transaction from an upstream device. */
		uint32_t pf                          : 1;  /**< R/W1C/H - Permission fault. In SMMU_GFSR, this field is reserved. In SMMU_SGFSR, this field records
                                                                 global SMMU()_SCR1[SIF] faults.
                                                                 Note if a transaction is associated with a particular translation context bank, faults are
                                                                 recorded in SMMU()_CB()_FSR instead of SMMU_SGFSR. */
		uint32_t ef                          : 1;  /**< R/W1C/H - External fault. */
		uint32_t caf                         : 1;  /**< RO - Configuration access fault.
                                                                 For CNXXXX always zero, no configuration faults. */
		uint32_t ucif                        : 1;  /**< R/W1C/H - Unimplemented context interrupt fault. */
		uint32_t ucbf                        : 1;  /**< R/W1C/H - Unimplemented context bank fault. */
		uint32_t smcf                        : 1;  /**< R/W1C/H - Stream match conflict fault. */
		uint32_t usf                         : 1;  /**< R/W1C/H - Unidentified stream fault. */
		uint32_t icf                         : 1;  /**< R/W1C/H - Invalid context fault. */
#else
		uint32_t icf                         : 1;
		uint32_t usf                         : 1;
		uint32_t smcf                        : 1;
		uint32_t ucbf                        : 1;
		uint32_t ucif                        : 1;
		uint32_t caf                         : 1;
		uint32_t ef                          : 1;
		uint32_t pf                          : 1;
		uint32_t uut                         : 1;
		uint32_t reserved_9_30               : 22;
		uint32_t multi                       : 1;
#endif
	} s;
	/* struct bdk_smmux_sgfsr_s           cn88xx; */
	/* struct bdk_smmux_sgfsr_s           cn88xxp1; */
} bdk_smmux_sgfsr_t;

static inline uint64_t BDK_SMMUX_SGFSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000048ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SGFSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SGFSR(...) bdk_smmux_sgfsr_t
#define bustype_BDK_SMMUX_SGFSR(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SGFSR(p1) (p1)
#define arguments_BDK_SMMUX_SGFSR(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SGFSR(...) "SMMUX_SGFSR"


/**
 * NCB32b - smmu#_sgfsrrestore
 *
 * Restores the SMMU()_(S)GFSR register after reset.
 *
 */
typedef union bdk_smmux_sgfsrrestore {
	uint32_t u;
	struct bdk_smmux_sgfsrrestore_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t restore                     : 32; /**< WO - Writes bits in corresponding SMMU()_(S)GFSR. */
#else
		uint32_t restore                     : 32;
#endif
	} s;
	/* struct bdk_smmux_sgfsrrestore_s    cn88xx; */
	/* struct bdk_smmux_sgfsrrestore_s    cn88xxp1; */
} bdk_smmux_sgfsrrestore_t;

static inline uint64_t BDK_SMMUX_SGFSRRESTORE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSRRESTORE(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000083000000004Cull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SGFSRRESTORE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SGFSRRESTORE(...) bdk_smmux_sgfsrrestore_t
#define bustype_BDK_SMMUX_SGFSRRESTORE(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SGFSRRESTORE(p1) (p1)
#define arguments_BDK_SMMUX_SGFSRRESTORE(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SGFSRRESTORE(...) "SMMUX_SGFSRRESTORE"


/**
 * NCB32b - smmu#_sgfsynr0
 *
 * Contains fault syndrome information relating to SMMU()_(S)GFSR.
 *
 */
typedef union bdk_smmux_sgfsynr0 {
	uint32_t u;
	struct bdk_smmux_sgfsynr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t imp                         : 8;  /**< RO - Reserved for implementation. */
		uint32_t reserved_7_7                : 1;
		uint32_t ats                         : 1;  /**< RO - Address translation operation fault. For CNXXXX zero, SMMU()_IDR0[ATOSNS] not supported. */
		uint32_t nsattr                      : 1;  /**< R/W/H - Non-secure attribute.
                                                                 0 = The faulty transaction has the secure attribute.
                                                                 1 = The faulty transaction has the non-secure attribute. */
		uint32_t nsstate                     : 1;  /**< SR/W/H - Non-secure state.
                                                                 0 = The faulty transaction is associated with a secure device.
                                                                 1 = The faulty transaction is associated with a non-secure device.

                                                                 This field is only valid for the secure state.

                                                                 This field may read '1' in the event that a fault is encountered in relation to a
                                                                 non-secure client device and where SMMU()_SCR1[GEFRO]='1'. */
		uint32_t ind                         : 1;  /**< R/W/H - Instruction not data.
                                                                 0 = The faulty transaction has the data access attribute.
                                                                 1 = The faulty transaction has the instruction access attribute. */
		uint32_t pnu                         : 1;  /**< R/W/H - Privileged not unprivileged.
                                                                 0 = The faulty transaction has the unprivileged attribute.
                                                                 1 = The faulty transaction has the privileged attribute. */
		uint32_t wnr                         : 1;  /**< R/W/H - Write not read.
                                                                 0 = The faulty transaction is a read.
                                                                 1 = The faulty transaction is a write. */
		uint32_t nested                      : 1;  /**< R/W/H - Nested fault.
                                                                 0 = The fault occurred in the initial stream context.
                                                                 1 = The fault occurred in a nested context.

                                                                 This bit is reserved in SMMU_SGFSYNR0. */
#else
		uint32_t nested                      : 1;
		uint32_t wnr                         : 1;
		uint32_t pnu                         : 1;
		uint32_t ind                         : 1;
		uint32_t nsstate                     : 1;
		uint32_t nsattr                      : 1;
		uint32_t ats                         : 1;
		uint32_t reserved_7_7                : 1;
		uint32_t imp                         : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_sgfsynr0_s        cn88xx; */
	/* struct bdk_smmux_sgfsynr0_s        cn88xxp1; */
} bdk_smmux_sgfsynr0_t;

static inline uint64_t BDK_SMMUX_SGFSYNR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSYNR0(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000050ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SGFSYNR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SGFSYNR0(...) bdk_smmux_sgfsynr0_t
#define bustype_BDK_SMMUX_SGFSYNR0(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SGFSYNR0(p1) (p1)
#define arguments_BDK_SMMUX_SGFSYNR0(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SGFSYNR0(...) "SMMUX_SGFSYNR0"


/**
 * NCB32b - smmu#_sgfsynr1
 *
 * Contains fault syndrome information relating to SMMU()_(S)GFSR.
 *
 */
typedef union bdk_smmux_sgfsynr1 {
	uint32_t u;
	struct bdk_smmux_sgfsynr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ssd_index                   : 16; /**< SRO/H - The SSD_Index of the transaction that caused the fault. The SSD_Index field is only
                                                                 accessible to configuration accesses by secure software. Non-secure configuration accesses
                                                                 treat this field as RAZ/WI.

                                                                 For CNXXXX, the SSD_INDEX is always the same as [STREAMID]. */
		uint32_t streamid                    : 16; /**< R/W/H - The stream ID of the transaction that caused the fault. */
#else
		uint32_t streamid                    : 16;
		uint32_t ssd_index                   : 16;
#endif
	} s;
	/* struct bdk_smmux_sgfsynr1_s        cn88xx; */
	/* struct bdk_smmux_sgfsynr1_s        cn88xxp1; */
} bdk_smmux_sgfsynr1_t;

static inline uint64_t BDK_SMMUX_SGFSYNR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSYNR1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000054ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SGFSYNR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SGFSYNR1(...) bdk_smmux_sgfsynr1_t
#define bustype_BDK_SMMUX_SGFSYNR1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SGFSYNR1(p1) (p1)
#define arguments_BDK_SMMUX_SGFSYNR1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SGFSYNR1(...) "SMMUX_SGFSYNR1"


/**
 * NCB32b - smmu#_sgfsynr2
 *
 * Not implemented in CNXXXX.
 *
 */
typedef union bdk_smmux_sgfsynr2 {
	uint32_t u;
	struct bdk_smmux_sgfsynr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_sgfsynr2_s        cn88xx; */
	/* struct bdk_smmux_sgfsynr2_s        cn88xxp1; */
} bdk_smmux_sgfsynr2_t;

static inline uint64_t BDK_SMMUX_SGFSYNR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SGFSYNR2(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000058ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SGFSYNR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SGFSYNR2(...) bdk_smmux_sgfsynr2_t
#define bustype_BDK_SMMUX_SGFSYNR2(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SGFSYNR2(p1) (p1)
#define arguments_BDK_SMMUX_SGFSYNR2(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SGFSYNR2(...) "SMMUX_SGFSYNR2"


/**
 * NCB - smmu#_smiss_perf
 */
typedef union bdk_smmux_smiss_perf {
	uint64_t u;
	struct bdk_smmux_smiss_perf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< SR/W/H - Counts the number of lookup requests in secure mode which missed the IOTLB. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_smiss_perf_s      cn88xx; */
	/* struct bdk_smmux_smiss_perf_s      cn88xxp1; */
} bdk_smmux_smiss_perf_t;

static inline uint64_t BDK_SMMUX_SMISS_PERF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SMISS_PERF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021040ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SMISS_PERF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SMISS_PERF(...) bdk_smmux_smiss_perf_t
#define bustype_BDK_SMMUX_SMISS_PERF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_SMISS_PERF(p1) (p1)
#define arguments_BDK_SMMUX_SMISS_PERF(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SMISS_PERF(...) "SMMUX_SMISS_PERF"


/**
 * NCB32b - smmu#_smr#
 *
 * Match a transaction with a particular stream mapping register group. The stream match register
 * table can have multiple entries matching the same stream id value during configuration,
 * providing software has the necessary precautions before configuration takes effect. For
 * example: 1. disable the stream source and ensure that no outstanding transactions from that
 * source are in progress disable one or more of the SMMU()_SMR() table entries using
 * the corresponding SMMU()_SMR()[VALID] bit, 2. disable the SMMU completely with
 * SMMU()_CB()_SCTLR[M].
 */
typedef union bdk_smmux_smrx {
	uint32_t u;
	struct bdk_smmux_smrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t exmask_valid                : 16; /**< R/W - Masking of stream id bits irrelevent to the matching process.

                                                                 If MASK\<i\>==1, ID\<i\> is ignored.

                                                                 If MASK\<i\>==0, ID\<i\> is relevant for matching.

                                                                 Note \<31\> indicates VALID if SMMU(0..3)_(S)CR0[EXIDENABLE] is zero. */
		uint32_t exid                        : 16; /**< R/W/H - Stream identifier to match after masking. In CNXXXX, if a bit is ignored (MASK\<i\>==1), the
                                                                 respective EXID\<i\> bit will be cleared by hardware. */
#else
		uint32_t exid                        : 16;
		uint32_t exmask_valid                : 16;
#endif
	} s;
	/* struct bdk_smmux_smrx_s            cn88xx; */
	/* struct bdk_smmux_smrx_s            cn88xxp1; */
} bdk_smmux_smrx_t;

static inline uint64_t BDK_SMMUX_SMRX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SMRX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 127)))
		return 0x0000830000000800ull + (param1 & 3) * 0x1000000000ull + (param2 & 127) * 0x4ull;
	csr_fatal("BDK_SMMUX_SMRX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SMRX(...) bdk_smmux_smrx_t
#define bustype_BDK_SMMUX_SMRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SMRX(p1,p2) (p1)
#define arguments_BDK_SMMUX_SMRX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_SMRX(...) "SMMUX_SMRX"


/**
 * NCB - smmu#_sptread_perf
 */
typedef union bdk_smmux_sptread_perf {
	uint64_t u;
	struct bdk_smmux_sptread_perf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cnt                         : 64; /**< SR/W/H - Counts the number of page table reads issued to secure memory. */
#else
		uint64_t cnt                         : 64;
#endif
	} s;
	/* struct bdk_smmux_sptread_perf_s    cn88xx; */
	/* struct bdk_smmux_sptread_perf_s    cn88xxp1; */
} bdk_smmux_sptread_perf_t;

static inline uint64_t BDK_SMMUX_SPTREAD_PERF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SPTREAD_PERF(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000021060ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_SPTREAD_PERF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SPTREAD_PERF(...) bdk_smmux_sptread_perf_t
#define bustype_BDK_SMMUX_SPTREAD_PERF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_SPTREAD_PERF(p1) (p1)
#define arguments_BDK_SMMUX_SPTREAD_PERF(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_SPTREAD_PERF(...) "SMMUX_SPTREAD_PERF"


/**
 * NCB32b - smmu#_ssdr#
 */
typedef union bdk_smmux_ssdrx {
	uint32_t u;
	struct bdk_smmux_ssdrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ssd                         : 32; /**< SR/W - Security state definition, where each bit corresponds to a SSD_Index:
                                                                 0 = Corresponding SSD_Index is acting for the secure domain.
                                                                 1 = Non-secure domain.

                                                                 Only accessible to secure software, else RAZ/WI. CNXXXX indexes this table by stream
                                                                 identifier, and uses the result of this table to also promote interrupts to secure
                                                                 interrupts. */
#else
		uint32_t ssd                         : 32;
#endif
	} s;
	/* struct bdk_smmux_ssdrx_s           cn88xx; */
	/* struct bdk_smmux_ssdrx_s           cn88xxp1; */
} bdk_smmux_ssdrx_t;

static inline uint64_t BDK_SMMUX_SSDRX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_SSDRX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 2047)))
		return 0x0000830000040000ull + (param1 & 3) * 0x1000000000ull + (param2 & 2047) * 0x4ull;
	csr_fatal("BDK_SMMUX_SSDRX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_SSDRX(...) bdk_smmux_ssdrx_t
#define bustype_BDK_SMMUX_SSDRX(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_SSDRX(p1,p2) (p1)
#define arguments_BDK_SMMUX_SSDRX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_SSDRX(...) "SMMUX_SSDRX"


/**
 * NCB32b - smmu#_stlbgstatus
 *
 * Gives the status of a TLB maintenance operation. Register fields are identical to those in
 * SMMU(0..3)_(S)TLBGSTATUS.
 */
typedef union bdk_smmux_stlbgstatus {
	uint32_t u;
	struct bdk_smmux_stlbgstatus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_1_31               : 31;
		uint32_t gsactive                    : 1;  /**< RO/H - Global synchronize TLB invalidate active:
                                                                 0 = No global TLB synchronization operation is active.
                                                                 1 = A global TLB synchronization operation is active. */
#else
		uint32_t gsactive                    : 1;
		uint32_t reserved_1_31               : 31;
#endif
	} s;
	/* struct bdk_smmux_stlbgstatus_s     cn88xx; */
	/* struct bdk_smmux_stlbgstatus_s     cn88xxp1; */
} bdk_smmux_stlbgstatus_t;

static inline uint64_t BDK_SMMUX_STLBGSTATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBGSTATUS(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000074ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_STLBGSTATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_STLBGSTATUS(...) bdk_smmux_stlbgstatus_t
#define bustype_BDK_SMMUX_STLBGSTATUS(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_STLBGSTATUS(p1) (p1)
#define arguments_BDK_SMMUX_STLBGSTATUS(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_STLBGSTATUS(...) "SMMUX_STLBGSTATUS"


/**
 * NCB32b - smmu#_stlbgsync
 *
 * Starts a global synchronization operation that ensures the completion of any previously
 * accepted TLB invalidate operation. Register fields are identical to those in
 * SMMU(0..3)_(S)TLBGSYNC.
 */
typedef union bdk_smmux_stlbgsync {
	uint32_t u;
	struct bdk_smmux_stlbgsync_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< WO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_stlbgsync_s       cn88xx; */
	/* struct bdk_smmux_stlbgsync_s       cn88xxp1; */
} bdk_smmux_stlbgsync_t;

static inline uint64_t BDK_SMMUX_STLBGSYNC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBGSYNC(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000070ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_STLBGSYNC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_STLBGSYNC(...) bdk_smmux_stlbgsync_t
#define bustype_BDK_SMMUX_STLBGSYNC(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_STLBGSYNC(p1) (p1)
#define arguments_BDK_SMMUX_STLBGSYNC(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_STLBGSYNC(...) "SMMUX_STLBGSYNC"


/**
 * NCB32b - smmu#_stlbiall
 *
 * Invalidates all unlocked secure entries in the TLB. Register fields are identical to those in
 * SMMU()_TLBIALLH.
 */
typedef union bdk_smmux_stlbiall {
	uint32_t u;
	struct bdk_smmux_stlbiall_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< SWO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_stlbiall_s        cn88xx; */
	/* struct bdk_smmux_stlbiall_s        cn88xxp1; */
} bdk_smmux_stlbiall_t;

static inline uint64_t BDK_SMMUX_STLBIALL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIALL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000060ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_STLBIALL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_STLBIALL(...) bdk_smmux_stlbiall_t
#define bustype_BDK_SMMUX_STLBIALL(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_STLBIALL(p1) (p1)
#define arguments_BDK_SMMUX_STLBIALL(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_STLBIALL(...) "SMMUX_STLBIALL"


/**
 * NCB32b - smmu#_stlbiallm
 *
 * Invalidate all unlocked secure monitor entries in the TLB. Register fields are identical to
 * those in SMMU()_TLBIALLH.
 */
typedef union bdk_smmux_stlbiallm {
	uint32_t u;
	struct bdk_smmux_stlbiallm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< SWO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_stlbiallm_s       cn88xx; */
	/* struct bdk_smmux_stlbiallm_s       cn88xxp1; */
} bdk_smmux_stlbiallm_t;

static inline uint64_t BDK_SMMUX_STLBIALLM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIALLM(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000000BCull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_STLBIALLM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_STLBIALLM(...) bdk_smmux_stlbiallm_t
#define bustype_BDK_SMMUX_STLBIALLM(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_STLBIALLM(p1) (p1)
#define arguments_BDK_SMMUX_STLBIALLM(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_STLBIALLM(...) "SMMUX_STLBIALLM"


/**
 * NCB - smmu#_stlbivalm
 *
 * This secure 64-bit register operates exactly as SMMU()_STLBIVAM, except the invalidation
 * need only apply to the caching of entries returned from the last level of translation table
 * walk. This 64-bit register supports the ARMv8 TLB invalidation operation address format.
 */
typedef union bdk_smmux_stlbivalm {
	uint64_t u;
	struct bdk_smmux_stlbivalm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t address                     : 44; /**< SWO - Virtual address \<55:12\> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS\<15:12\> are ignored. The address will be extended to bit \<63\>
                                                                 by copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_smmux_stlbivalm_s       cn88xx; */
	/* struct bdk_smmux_stlbivalm_s       cn88xxp1; */
} bdk_smmux_stlbivalm_t;

static inline uint64_t BDK_SMMUX_STLBIVALM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIVALM(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000000A0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_STLBIVALM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_STLBIVALM(...) bdk_smmux_stlbivalm_t
#define bustype_BDK_SMMUX_STLBIVALM(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_STLBIVALM(p1) (p1)
#define arguments_BDK_SMMUX_STLBIVALM(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_STLBIVALM(...) "SMMUX_STLBIVALM"


/**
 * NCB - smmu#_stlbivam
 *
 * This secure 64-bit register invalidates all monitor TLB entries that associated with the
 * specified virtual address and applies to all unlocked entries within the TLB. This 64-bit
 * register supports the ARMv8 TLB invalidation operation address format. Register fields are
 * identical to those in SMMU()_TLBIVAH64.
 */
typedef union bdk_smmux_stlbivam {
	uint64_t u;
	struct bdk_smmux_stlbivam_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t address                     : 44; /**< SWO - Virtual address \<55:12\> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS\<15:12\> are ignored. The address will be extended to bit \<63\>
                                                                 by copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_smmux_stlbivam_s        cn88xx; */
	/* struct bdk_smmux_stlbivam_s        cn88xxp1; */
} bdk_smmux_stlbivam_t;

static inline uint64_t BDK_SMMUX_STLBIVAM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_STLBIVAM(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000000A8ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_STLBIVAM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_STLBIVAM(...) bdk_smmux_stlbivam_t
#define bustype_BDK_SMMUX_STLBIVAM(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_STLBIVAM(p1) (p1)
#define arguments_BDK_SMMUX_STLBIVAM(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_STLBIVAM(...) "SMMUX_STLBIVAM"


/**
 * NCB - smmu#_tlb#_dat
 */
typedef union bdk_smmux_tlbx_dat {
	uint64_t u;
	struct bdk_smmux_tlbx_dat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO/H - Internal TLB state, for diagnostic use only. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_smmux_tlbx_dat_s        cn88xx; */
	/* struct bdk_smmux_tlbx_dat_s        cn88xxp1; */
} bdk_smmux_tlbx_dat_t;

static inline uint64_t BDK_SMMUX_TLBX_DAT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBX_DAT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 4095)))
		return 0x0000830000028000ull + (param1 & 3) * 0x1000000000ull + (param2 & 4095) * 0x8ull;
	csr_fatal("BDK_SMMUX_TLBX_DAT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBX_DAT(...) bdk_smmux_tlbx_dat_t
#define bustype_BDK_SMMUX_TLBX_DAT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_TLBX_DAT(p1,p2) (p1)
#define arguments_BDK_SMMUX_TLBX_DAT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_TLBX_DAT(...) "SMMUX_TLBX_DAT"


/**
 * NCB32b - smmu#_tlbiallh
 *
 * Invalidate all hypervisor tagged entries in the TLB, regardless of the security state of each
 * entry. It can optionally apply to all unlocked entries.
 */
typedef union bdk_smmux_tlbiallh {
	uint32_t u;
	struct bdk_smmux_tlbiallh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< WO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_tlbiallh_s        cn88xx; */
	/* struct bdk_smmux_tlbiallh_s        cn88xxp1; */
} bdk_smmux_tlbiallh_t;

static inline uint64_t BDK_SMMUX_TLBIALLH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIALLH(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000083000000006Cull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIALLH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIALLH(...) bdk_smmux_tlbiallh_t
#define bustype_BDK_SMMUX_TLBIALLH(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_TLBIALLH(p1) (p1)
#define arguments_BDK_SMMUX_TLBIALLH(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIALLH(...) "SMMUX_TLBIALLH"


/**
 * NCB32b - smmu#_tlbiallnsnh
 *
 * Invalidate all non-secure, non-hypervisor tagged entries in the TLB. Register fields are
 * identical to those in SMMU()_TLBIALLH. It can optionally apply to all unlocked entries.
 */
typedef union bdk_smmux_tlbiallnsnh {
	uint32_t u;
	struct bdk_smmux_tlbiallnsnh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t command                     : 32; /**< WO - Any write to this register will perform the synchronization. */
#else
		uint32_t command                     : 32;
#endif
	} s;
	/* struct bdk_smmux_tlbiallnsnh_s     cn88xx; */
	/* struct bdk_smmux_tlbiallnsnh_s     cn88xxp1; */
} bdk_smmux_tlbiallnsnh_t;

static inline uint64_t BDK_SMMUX_TLBIALLNSNH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIALLNSNH(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000068ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIALLNSNH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIALLNSNH(...) bdk_smmux_tlbiallnsnh_t
#define bustype_BDK_SMMUX_TLBIALLNSNH(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_TLBIALLNSNH(p1) (p1)
#define arguments_BDK_SMMUX_TLBIALLNSNH(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIALLNSNH(...) "SMMUX_TLBIALLNSNH"


/**
 * NCB32b - smmu#_tlbivah
 *
 * Backward compatible version of SMMU()_TLBIVAH64.
 *
 */
typedef union bdk_smmux_tlbivah {
	uint32_t u;
	struct bdk_smmux_tlbivah_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_smmux_tlbivah_s         cn88xx; */
	/* struct bdk_smmux_tlbivah_s         cn88xxp1; */
} bdk_smmux_tlbivah_t;

static inline uint64_t BDK_SMMUX_TLBIVAH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVAH(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000078ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIVAH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIVAH(...) bdk_smmux_tlbivah_t
#define bustype_BDK_SMMUX_TLBIVAH(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_TLBIVAH(p1) (p1)
#define arguments_BDK_SMMUX_TLBIVAH(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIVAH(...) "SMMUX_TLBIVAH"


/**
 * NCB - smmu#_tlbivah64
 *
 * Invalidate all hypervisor tagged entries in the TLB, regardless of the security tagging
 * associated with the entry. It can optionally apply to all unlocked entries.
 */
typedef union bdk_smmux_tlbivah64 {
	uint64_t u;
	struct bdk_smmux_tlbivah64_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t address                     : 44; /**< WO - Virtual address \<55:12\> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS\<15:12\> are ignored. The address will be extended to bit \<63\>
                                                                 by copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_smmux_tlbivah64_s       cn88xx; */
	/* struct bdk_smmux_tlbivah64_s       cn88xxp1; */
} bdk_smmux_tlbivah64_t;

static inline uint64_t BDK_SMMUX_TLBIVAH64(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVAH64(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000000C0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIVAH64", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIVAH64(...) bdk_smmux_tlbivah64_t
#define bustype_BDK_SMMUX_TLBIVAH64(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_TLBIVAH64(p1) (p1)
#define arguments_BDK_SMMUX_TLBIVAH64(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIVAH64(...) "SMMUX_TLBIVAH64"


/**
 * NCB - smmu#_tlbivalh64
 *
 * This 64-bit register operates exactly as SMMU()_TLBIVAH64, except the
 * invalidation need only apply to the caching of entries returned from the last level of
 * translation table walk. This 64-bit register supports the ARMv8 TLB invalidation operation
 * address format.
 */
typedef union bdk_smmux_tlbivalh64 {
	uint64_t u;
	struct bdk_smmux_tlbivalh64_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t address                     : 44; /**< WO - Virtual address \<55:12\> to be invalidated. Note: this matches the format of the addresses
                                                                 supplied to ARMv8 processor TLBI invalidation instructions. If the page size is 64kB then
                                                                 bits corresponding to ADDRESS\<15:12\> are ignored. The address will be extended to bit \<63\>
                                                                 by copying bit \<55\>. */
#else
		uint64_t address                     : 44;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_smmux_tlbivalh64_s      cn88xx; */
	/* struct bdk_smmux_tlbivalh64_s      cn88xxp1; */
} bdk_smmux_tlbivalh64_t;

static inline uint64_t BDK_SMMUX_TLBIVALH64(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVALH64(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000000B0ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIVALH64", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIVALH64(...) bdk_smmux_tlbivalh64_t
#define bustype_BDK_SMMUX_TLBIVALH64(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_TLBIVALH64(p1) (p1)
#define arguments_BDK_SMMUX_TLBIVALH64(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIVALH64(...) "SMMUX_TLBIVALH64"


/**
 * NCB32b - smmu#_tlbivmid
 *
 * Invalidate all non-secure, non-hypervisor TLB entries having the specified VMID. It can
 * optionally apply to all entries.
 */
typedef union bdk_smmux_tlbivmid {
	uint32_t u;
	struct bdk_smmux_tlbivmid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t vmid                        : 16; /**< WO - The virtual machine identifier to use in the invalidate operation. INTERNAL: Bits 15:8
                                                                 defined by the large system extensions. */
#else
		uint32_t vmid                        : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_tlbivmid_s        cn88xx; */
	/* struct bdk_smmux_tlbivmid_s        cn88xxp1; */
} bdk_smmux_tlbivmid_t;

static inline uint64_t BDK_SMMUX_TLBIVMID(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVMID(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000830000000064ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIVMID", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIVMID(...) bdk_smmux_tlbivmid_t
#define bustype_BDK_SMMUX_TLBIVMID(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_TLBIVMID(p1) (p1)
#define arguments_BDK_SMMUX_TLBIVMID(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIVMID(...) "SMMUX_TLBIVMID"


/**
 * NCB32b - smmu#_tlbivmids1
 *
 * Invalidate all non-secure, non-hypervisor TLB entries having the specified VMID. In an
 * implementation using combined S1 + S2 TLB entries, this operation must invalidate any entries
 * tagged with a valid matching VMID. It operates exactly as SMMU()_TLBIVMID, except it only
 * applies to caching of entries containing information from the first stage of translation.
 */
typedef union bdk_smmux_tlbivmids1 {
	uint32_t u;
	struct bdk_smmux_tlbivmids1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t vmid                        : 16; /**< WO - The virtual machine identifier to use in the invalidate operation. INTERNAL: Bits 15:8
                                                                 defined by the large system extensions. */
#else
		uint32_t vmid                        : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_smmux_tlbivmids1_s      cn88xx; */
	/* struct bdk_smmux_tlbivmids1_s      cn88xxp1; */
} bdk_smmux_tlbivmids1_t;

static inline uint64_t BDK_SMMUX_TLBIVMIDS1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_TLBIVMIDS1(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x00008300000000B8ull + (param1 & 3) * 0x1000000000ull;
	csr_fatal("BDK_SMMUX_TLBIVMIDS1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_TLBIVMIDS1(...) bdk_smmux_tlbivmids1_t
#define bustype_BDK_SMMUX_TLBIVMIDS1(...) BDK_CSR_TYPE_NCB32b
#define busnum_BDK_SMMUX_TLBIVMIDS1(p1) (p1)
#define arguments_BDK_SMMUX_TLBIVMIDS1(p1) (p1),-1,-1,-1
#define basename_BDK_SMMUX_TLBIVMIDS1(...) "SMMUX_TLBIVMIDS1"


/**
 * NCB - smmu#_wcu#_dat
 */
typedef union bdk_smmux_wcux_dat {
	uint64_t u;
	struct bdk_smmux_wcux_dat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO/H - Internal WCU state, for diagnostic use only. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_smmux_wcux_dat_s        cn88xx; */
	/* struct bdk_smmux_wcux_dat_s        cn88xxp1; */
} bdk_smmux_wcux_dat_t;

static inline uint64_t BDK_SMMUX_WCUX_DAT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMMUX_WCUX_DAT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 3)) && ((param2 <= 2047)))
		return 0x0000830000024000ull + (param1 & 3) * 0x1000000000ull + (param2 & 2047) * 0x8ull;
	csr_fatal("BDK_SMMUX_WCUX_DAT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_SMMUX_WCUX_DAT(...) bdk_smmux_wcux_dat_t
#define bustype_BDK_SMMUX_WCUX_DAT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_SMMUX_WCUX_DAT(p1,p2) (p1)
#define arguments_BDK_SMMUX_WCUX_DAT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_SMMUX_WCUX_DAT(...) "SMMUX_WCUX_DAT"

#endif /* __BDK_CSRS_SMMU__ */
