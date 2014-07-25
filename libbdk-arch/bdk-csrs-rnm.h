#ifndef __BDK_CSRS_RNM__
#define __BDK_CSRS_RNM__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Networks (support@cavium.com). All rights
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

 *   * Neither the name of Cavium Networks nor the names of
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
 * Cavium RNM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar RNM_BAR_E
 *
 * RNM Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace RNM_BAR_E {
	const uint64_t RNM_PF_BAR0 = 0x87e040000000;
	const uint64_t RNM_PF_BAR0_PCC_BAR_SIZE_BITS = 20;
	const uint64_t RNM_VF_BAR0 = 0x840000800000;
	const uint64_t RNM_VF_BAR0_PCC_BAR_SIZE_BITS = 20;
};
#endif



/**
 * RSL - rnm_bist_status
 *
 * This register is the RNM memory BIST status register, indicating status of built-in self-tests.
 *
 */
typedef union bdk_rnm_bist_status {
	uint64_t u;
	struct bdk_rnm_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t rrc                         : 1;  /**< RO/H - Status of the RRC memory block BIST: 1 = failed BIST, 0 = passed BIST. */
		uint64_t mem                         : 1;  /**< RO/H - Status of MEM block BIST: 1 = failed BIST, 0 = passed BIST. */
#else
		uint64_t mem                         : 1;
		uint64_t rrc                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_rnm_bist_status_s       cn85xx; */
	/* struct bdk_rnm_bist_status_s       cn88xx; */
} bdk_rnm_bist_status_t;

#define BDK_RNM_BIST_STATUS BDK_RNM_BIST_STATUS_FUNC()
static inline uint64_t BDK_RNM_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RNM_BIST_STATUS_FUNC(void)
{
	return 0x000087E040000008ull;
}
#define typedef_BDK_RNM_BIST_STATUS bdk_rnm_bist_status_t
#define bustype_BDK_RNM_BIST_STATUS BDK_CSR_TYPE_RSL
#define busnum_BDK_RNM_BIST_STATUS 0
#define arguments_BDK_RNM_BIST_STATUS -1,-1,-1,-1
#define basename_BDK_RNM_BIST_STATUS "RNM_BIST_STATUS"


/**
 * RSL - rnm_ctl_status
 *
 * This register is the RNM control register.
 * This register is secure only to prevent non-secure world from affecting secure-world clients
 * using true random numbers.
 */
typedef union bdk_rnm_ctl_status {
	uint64_t u;
	struct bdk_rnm_ctl_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t dis_mak                     : 1;  /**< SR/W1S/H - Disable use of master AES KEY. */
		uint64_t eer_lck                     : 1;  /**< SRO/H - Encryption enable register locked. */
		uint64_t eer_val                     : 1;  /**< SRO/H - Dormant encryption key match. */
		uint64_t ent_sel                     : 4;  /**< SR/W - Select input to RNM FIFO.
                                                                 0x0 = 0-7.
                                                                 0x1 = 8-15.
                                                                 0x2 = 16-23.
                                                                 0x3 = 24-31.
                                                                 0x4 = 32-39.
                                                                 0x5 = 40-47.
                                                                 0x6 = 48-55.
                                                                 0x7 = 56-63.
                                                                 0x8 = 64-71.
                                                                 0x9 = 72-79.
                                                                 0xA = 80-87.
                                                                 0xB = 88-95.
                                                                 0xC = 96-103.
                                                                 0xD = 104-111.
                                                                 0xE = 112-119.
                                                                 0xF = 120-127. */
		uint64_t exp_ent                     : 1;  /**< SR/W - Exported entropy enable for random-number generator. */
		uint64_t rng_rst                     : 1;  /**< SR/W - Reset RNG as core reset. */
		uint64_t rnm_rst                     : 1;  /**< SR/W - Reset the RNM as core reset except for register logic. */
		uint64_t rng_en                      : 1;  /**< SR/W - Enables the output of the RNG. */
		uint64_t ent_en                      : 1;  /**< SR/W - Entropy enable for random number generator. */
#else
		uint64_t ent_en                      : 1;
		uint64_t rng_en                      : 1;
		uint64_t rnm_rst                     : 1;
		uint64_t rng_rst                     : 1;
		uint64_t exp_ent                     : 1;
		uint64_t ent_sel                     : 4;
		uint64_t eer_val                     : 1;
		uint64_t eer_lck                     : 1;
		uint64_t dis_mak                     : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_rnm_ctl_status_s        cn85xx; */
	/* struct bdk_rnm_ctl_status_s        cn88xx; */
} bdk_rnm_ctl_status_t;

#define BDK_RNM_CTL_STATUS BDK_RNM_CTL_STATUS_FUNC()
static inline uint64_t BDK_RNM_CTL_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RNM_CTL_STATUS_FUNC(void)
{
	return 0x000087E040000000ull;
}
#define typedef_BDK_RNM_CTL_STATUS bdk_rnm_ctl_status_t
#define bustype_BDK_RNM_CTL_STATUS BDK_CSR_TYPE_RSL
#define busnum_BDK_RNM_CTL_STATUS 0
#define arguments_BDK_RNM_CTL_STATUS -1,-1,-1,-1
#define basename_BDK_RNM_CTL_STATUS "RNM_CTL_STATUS"


/**
 * RSL - rnm_eer_dbg
 *
 * This register is the encryption enable debug register.
 *
 */
typedef union bdk_rnm_eer_dbg {
	uint64_t u;
	struct bdk_rnm_eer_dbg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< SRO/H - Dormant encryption debug info. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_rnm_eer_dbg_s           cn85xx; */
	/* struct bdk_rnm_eer_dbg_s           cn88xx; */
} bdk_rnm_eer_dbg_t;

#define BDK_RNM_EER_DBG BDK_RNM_EER_DBG_FUNC()
static inline uint64_t BDK_RNM_EER_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RNM_EER_DBG_FUNC(void)
{
	return 0x000087E040000018ull;
}
#define typedef_BDK_RNM_EER_DBG bdk_rnm_eer_dbg_t
#define bustype_BDK_RNM_EER_DBG BDK_CSR_TYPE_RSL
#define busnum_BDK_RNM_EER_DBG 0
#define arguments_BDK_RNM_EER_DBG -1,-1,-1,-1
#define basename_BDK_RNM_EER_DBG "RNM_EER_DBG"


/**
 * RSL - rnm_eer_key
 *
 * This register is the encryption enable register.
 *
 */
typedef union bdk_rnm_eer_key {
	uint64_t u;
	struct bdk_rnm_eer_key_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t key                         : 64; /**< SWO - Dormant encryption key. If dormant crypto is fuse-enabled, crypto can be enabled by
                                                                 writing this register with the correct key. */
#else
		uint64_t key                         : 64;
#endif
	} s;
	/* struct bdk_rnm_eer_key_s           cn85xx; */
	/* struct bdk_rnm_eer_key_s           cn88xx; */
} bdk_rnm_eer_key_t;

#define BDK_RNM_EER_KEY BDK_RNM_EER_KEY_FUNC()
static inline uint64_t BDK_RNM_EER_KEY_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RNM_EER_KEY_FUNC(void)
{
	return 0x000087E040000010ull;
}
#define typedef_BDK_RNM_EER_KEY bdk_rnm_eer_key_t
#define bustype_BDK_RNM_EER_KEY BDK_CSR_TYPE_RSL
#define busnum_BDK_RNM_EER_KEY 0
#define arguments_BDK_RNM_EER_KEY -1,-1,-1,-1
#define basename_BDK_RNM_EER_KEY "RNM_EER_KEY"


/**
 * NCB - rnm_random
 */
typedef union bdk_rnm_random {
	uint64_t u;
	struct bdk_rnm_random_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< RO/H - Generated random number. This register may be accessed with a 8, 16, 32 or 64-bit
                                                                 operation. This register is on a independent page, and may be mapped into guest operating
                                                                 systems. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_rnm_random_s            cn85xx; */
	/* struct bdk_rnm_random_s            cn88xx; */
} bdk_rnm_random_t;

#define BDK_RNM_RANDOM BDK_RNM_RANDOM_FUNC()
static inline uint64_t BDK_RNM_RANDOM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RNM_RANDOM_FUNC(void)
{
	return 0x0000840000800000ull;
}
#define typedef_BDK_RNM_RANDOM bdk_rnm_random_t
#define bustype_BDK_RNM_RANDOM BDK_CSR_TYPE_NCB
#define busnum_BDK_RNM_RANDOM 0
#define arguments_BDK_RNM_RANDOM -1,-1,-1,-1
#define basename_BDK_RNM_RANDOM "RNM_RANDOM"


/**
 * RSL - rnm_serial_num
 */
typedef union bdk_rnm_serial_num {
	uint64_t u;
	struct bdk_rnm_serial_num_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t dat                         : 64; /**< RO/H - Dormant encryption serial number. */
#else
		uint64_t dat                         : 64;
#endif
	} s;
	/* struct bdk_rnm_serial_num_s        cn85xx; */
	/* struct bdk_rnm_serial_num_s        cn88xx; */
} bdk_rnm_serial_num_t;

#define BDK_RNM_SERIAL_NUM BDK_RNM_SERIAL_NUM_FUNC()
static inline uint64_t BDK_RNM_SERIAL_NUM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_RNM_SERIAL_NUM_FUNC(void)
{
	return 0x000087E040000020ull;
}
#define typedef_BDK_RNM_SERIAL_NUM bdk_rnm_serial_num_t
#define bustype_BDK_RNM_SERIAL_NUM BDK_CSR_TYPE_RSL
#define busnum_BDK_RNM_SERIAL_NUM 0
#define arguments_BDK_RNM_SERIAL_NUM -1,-1,-1,-1
#define basename_BDK_RNM_SERIAL_NUM "RNM_SERIAL_NUM"

#endif /* __BDK_CSRS_RNM__ */
