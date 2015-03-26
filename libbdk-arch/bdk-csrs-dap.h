#ifndef __BDK_CSRS_DAP__
#define __BDK_CSRS_DAP__
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
 * Cavium DAP.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * RSL - dap_eco
 *
 * Added in pass 2.
 *
 */
typedef union bdk_dap_eco {
	uint64_t u;
	struct bdk_dap_eco_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_ro                      : 16; /**< RO - Reserved for ECO usage. */
		uint64_t eco_rw                      : 16; /**< R/W - Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 16;
		uint64_t eco_ro                      : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_dap_eco_s               cn88xx; */
} bdk_dap_eco_t;

#define BDK_DAP_ECO BDK_DAP_ECO_FUNC()
static inline uint64_t BDK_DAP_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_ECO_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x000087E002000120ull;
	else 		csr_fatal("BDK_DAP_ECO", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_DAP_ECO bdk_dap_eco_t
#define bustype_BDK_DAP_ECO BDK_CSR_TYPE_RSL
#define busnum_BDK_DAP_ECO 0
#define arguments_BDK_DAP_ECO -1,-1,-1,-1
#define basename_BDK_DAP_ECO "DAP_ECO"


/**
 * RSL32b - dap_hwpoll_cnt
 */
typedef union bdk_dap_hwpoll_cnt {
	uint32_t u;
	struct bdk_dap_hwpoll_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t poll_dis                    : 1;  /**< R/W - Disable hardware polling. For diagnostic use only. Added in pass 2. */
		uint32_t reserved_16_30              : 15;
		uint32_t count                       : 16; /**< R/W - Number of coprocessor-clocks between DAP bus poll intervals.
                                                                 With the approximate transaction delay of 256 cycles, the default
                                                                 results in a poll approximately every 2048 cycles.
                                                                 Must not be zero. For diagnostic use only. */
#else
		uint32_t count                       : 16;
		uint32_t reserved_16_30              : 15;
		uint32_t poll_dis                    : 1;
#endif
	} s;
	/* struct bdk_dap_hwpoll_cnt_s        cn88xx; */
	struct bdk_dap_hwpoll_cnt_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t count                       : 16; /**< R/W - Number of coprocessor-clocks between DAP bus poll intervals.
                                                                 With the approximate transaction delay of 256 cycles, the default
                                                                 results in a poll approximately every 2048 cycles.
                                                                 Must not be zero. For diagnostic use only. */
#else
		uint32_t count                       : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} cn88xxp1;
} bdk_dap_hwpoll_cnt_t;

#define BDK_DAP_HWPOLL_CNT BDK_DAP_HWPOLL_CNT_FUNC()
static inline uint64_t BDK_DAP_HWPOLL_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_HWPOLL_CNT_FUNC(void)
{
	return 0x000087E002000114ull;
}
#define typedef_BDK_DAP_HWPOLL_CNT bdk_dap_hwpoll_cnt_t
#define bustype_BDK_DAP_HWPOLL_CNT BDK_CSR_TYPE_RSL32b
#define busnum_BDK_DAP_HWPOLL_CNT 0
#define arguments_BDK_DAP_HWPOLL_CNT -1,-1,-1,-1
#define basename_BDK_DAP_HWPOLL_CNT "DAP_HWPOLL_CNT"


/**
 * RSL32b - dap_imp_dar
 *
 * This register controls the device enables and secure/non-secure access permissions.
 *
 */
typedef union bdk_dap_imp_dar {
	uint32_t u;
	struct bdk_dap_imp_dar_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_11_31              : 21;
		uint32_t cabnsen                     : 1;  /**< R/W - Enable non-secure CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault on non-secure CAB accesses.
                                                                 1 = Enable non-secure CAB accesses.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t caben                       : 1;  /**< R/W - Enable CAB accesses from NCB and RSL devices.
                                                                 0 = Return fault for all CAB accesses.
                                                                 1 = Enable all CAB accesses.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t reserved_6_8                : 3;
		uint32_t deviceen                    : 1;  /**< R/W - Set this bit to use CVM-AP inside DAP for CNXXXX addressing accesses.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t dabdeviceen                 : 1;  /**< R/W - Set this bit to use ARM-AP inside DAP for DAB serial bus accesses.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t spniden                     : 1;  /**< R/W - Set this bit to enable secure non invasive debug enable.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t spiden                      : 1;  /**< R/W - Set this bit to enable secure invasive debug enable.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t niden                       : 1;  /**< R/W - Set this bit to enable non secure invasive debug enable.

                                                                 When in trusted-mode resets to 0, else 1. */
		uint32_t dbgen                       : 1;  /**< R/W - Set this bit to enable debug enable.

                                                                 When in trusted-mode resets to 0, else 1. */
#else
		uint32_t dbgen                       : 1;
		uint32_t niden                       : 1;
		uint32_t spiden                      : 1;
		uint32_t spniden                     : 1;
		uint32_t dabdeviceen                 : 1;
		uint32_t deviceen                    : 1;
		uint32_t reserved_6_8                : 3;
		uint32_t caben                       : 1;
		uint32_t cabnsen                     : 1;
		uint32_t reserved_11_31              : 21;
#endif
	} s;
	/* struct bdk_dap_imp_dar_s           cn88xx; */
	/* struct bdk_dap_imp_dar_s           cn88xxp1; */
} bdk_dap_imp_dar_t;

#define BDK_DAP_IMP_DAR BDK_DAP_IMP_DAR_FUNC()
static inline uint64_t BDK_DAP_IMP_DAR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_IMP_DAR_FUNC(void)
{
	return 0x000087E002000100ull;
}
#define typedef_BDK_DAP_IMP_DAR bdk_dap_imp_dar_t
#define bustype_BDK_DAP_IMP_DAR BDK_CSR_TYPE_RSL32b
#define busnum_BDK_DAP_IMP_DAR 0
#define arguments_BDK_DAP_IMP_DAR -1,-1,-1,-1
#define basename_BDK_DAP_IMP_DAR "DAP_IMP_DAR"


/**
 * RSL32b - dap_owb_to
 *
 * This register configures the one-wire bus.
 *
 */
typedef union bdk_dap_owb_to {
	uint32_t u;
	struct bdk_dap_owb_to_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t to_dis                      : 1;  /**< R/W - Disable timeout mechanism. Added in pass 2. */
		uint32_t reserved_16_30              : 15;
		uint32_t tovalue                     : 16; /**< R/W - Timeout value. If an OWB transaction is longer than this number
                                                                 of coprocessor-clock cycles, it will timeout. */
#else
		uint32_t tovalue                     : 16;
		uint32_t reserved_16_30              : 15;
		uint32_t to_dis                      : 1;
#endif
	} s;
	/* struct bdk_dap_owb_to_s            cn88xx; */
	struct bdk_dap_owb_to_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t tovalue                     : 16; /**< R/W - Timeout value. If an OWB transaction is longer than this number
                                                                 of coprocessor-clock cycles, it will timeout. */
#else
		uint32_t tovalue                     : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} cn88xxp1;
} bdk_dap_owb_to_t;

#define BDK_DAP_OWB_TO BDK_DAP_OWB_TO_FUNC()
static inline uint64_t BDK_DAP_OWB_TO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_OWB_TO_FUNC(void)
{
	return 0x000087E002000110ull;
}
#define typedef_BDK_DAP_OWB_TO bdk_dap_owb_to_t
#define bustype_BDK_DAP_OWB_TO BDK_CSR_TYPE_RSL32b
#define busnum_BDK_DAP_OWB_TO 0
#define arguments_BDK_DAP_OWB_TO -1,-1,-1,-1
#define basename_BDK_DAP_OWB_TO "DAP_OWB_TO"


/**
 * RSL - dap_scratch
 *
 * This register is a scratch register for software use. Added in pass 2.
 *
 */
typedef union bdk_dap_scratch {
	uint64_t u;
	struct bdk_dap_scratch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Scratch data, not used by hardware. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_dap_scratch_s           cn88xx; */
} bdk_dap_scratch_t;

#define BDK_DAP_SCRATCH BDK_DAP_SCRATCH_FUNC()
static inline uint64_t BDK_DAP_SCRATCH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_SCRATCH_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x000087E002000118ull;
	else 		csr_fatal("BDK_DAP_SCRATCH", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_DAP_SCRATCH bdk_dap_scratch_t
#define bustype_BDK_DAP_SCRATCH BDK_CSR_TYPE_RSL
#define busnum_BDK_DAP_SCRATCH 0
#define arguments_BDK_DAP_SCRATCH -1,-1,-1,-1
#define basename_BDK_DAP_SCRATCH "DAP_SCRATCH"


/**
 * RSL32b - dap_sraaddr
 *
 * This register controls broadcast write or polling to the cores.
 *
 */
typedef union bdk_dap_sraaddr {
	uint32_t u;
	struct bdk_dap_sraaddr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_29_31              : 3;
		uint32_t cabdabsel                   : 1;  /**< R/W - CAB or DAB bus access selection for polling/broadcast write.
                                                                 0 = Polling/broadcast write is for DAB bus, bits \<20:5\> is the address offset.
                                                                 1 = Polling/broadcast write is for CAB bus, bits \<19:5\> is the register number. */
		uint32_t reserved_21_27              : 7;
		uint32_t regnum                      : 16; /**< R/W - If [CABDABSEL]=1, then \<19:5\> is the register number with these bit definitions:
                                                                 \<19\>: Op0[0].
                                                                 \<18:16\>: Op1
                                                                 \<15:12\>: CRn.
                                                                 \<11:8\>: CRm.
                                                                 \<7:5\>: Op.

                                                                 If [CABDABSEL]=0, then [REGNUM] is the register offset. */
		uint32_t reserved_2_4                : 3;
		uint32_t errstatus                   : 1;  /**< RAZ - Rurrently reserved. */
		uint32_t busy                        : 1;  /**< RO/H - Busy indicator if the broadcast write or polling still in progress.
                                                                 0 = Idle.
                                                                 1 = Broadcast write or polling still in progress. */
#else
		uint32_t busy                        : 1;
		uint32_t errstatus                   : 1;
		uint32_t reserved_2_4                : 3;
		uint32_t regnum                      : 16;
		uint32_t reserved_21_27              : 7;
		uint32_t cabdabsel                   : 1;
		uint32_t reserved_29_31              : 3;
#endif
	} s;
	/* struct bdk_dap_sraaddr_s           cn88xx; */
	/* struct bdk_dap_sraaddr_s           cn88xxp1; */
} bdk_dap_sraaddr_t;

#define BDK_DAP_SRAADDR BDK_DAP_SRAADDR_FUNC()
static inline uint64_t BDK_DAP_SRAADDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_SRAADDR_FUNC(void)
{
	return 0x000087E002000104ull;
}
#define typedef_BDK_DAP_SRAADDR bdk_dap_sraaddr_t
#define bustype_BDK_DAP_SRAADDR BDK_CSR_TYPE_RSL32b
#define busnum_BDK_DAP_SRAADDR 0
#define arguments_BDK_DAP_SRAADDR -1,-1,-1,-1
#define basename_BDK_DAP_SRAADDR "DAP_SRAADDR"


/**
 * RSL - dap_sradata
 *
 * Data register for broadcast writes and polling from the cores.
 *
 */
typedef union bdk_dap_sradata {
	uint64_t u;
	struct bdk_dap_sradata_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	struct bdk_dap_sradata_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_0               : 64;
#else
		uint64_t reserved_63_0               : 64;
#endif
	} cn88xx;
	struct bdk_dap_sradata_cn88xx         cn88xxp1;
} bdk_dap_sradata_t;

#define BDK_DAP_SRADATA BDK_DAP_SRADATA_FUNC()
static inline uint64_t BDK_DAP_SRADATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_DAP_SRADATA_FUNC(void)
{
	return 0x000087E002000108ull;
}
#define typedef_BDK_DAP_SRADATA bdk_dap_sradata_t
#define bustype_BDK_DAP_SRADATA BDK_CSR_TYPE_RSL
#define busnum_BDK_DAP_SRADATA 0
#define arguments_BDK_DAP_SRADATA -1,-1,-1,-1
#define basename_BDK_DAP_SRADATA "DAP_SRADATA"

#endif /* __BDK_CSRS_DAP__ */
