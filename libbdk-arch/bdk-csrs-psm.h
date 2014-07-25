#ifndef __BDK_CSRS_PSM__
#define __BDK_CSRS_PSM__
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
 * Cavium PSM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * NCB - phys_dbg_break_cfg
 *
 * This register configures the debug "break" mechanism.
 *
 */
typedef union bdk_phys_dbg_break_cfg {
	uint64_t u;
	struct bdk_phys_dbg_break_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t start_brk_ena               : 1;  /**< R/W - Break on Job Start which matches JOB_PTR and generate debug
                                                                 interrupt. */
		uint64_t done_brk_ena                : 1;  /**< R/W - Break on Job Done which matches JOB_PTR and generate debug
                                                                 interrupt. */
		uint64_t stop_on_brk                 : 1;  /**< R/W - Halt the PHY Scheduler from issuing new commadns upon break event.
                                                                 On a break, the HALTED bit will be set which will stop all queues
                                                                 from advancing. */
		uint64_t halted                      : 1;  /**< R/W - Set to 1 if STOP_ON_BRK is set and a break is encountered. When set,
                                                                 all queues will be halted from advancing. Job completion and job
                                                                 queue additions are still enabled. Set to 0 to resume queue
                                                                 dispatch. */
		uint64_t reserved_16_59              : 44;
		uint64_t job_tag                     : 16; /**< R/W - JOB TAG to be matched for the break mechanism. */
#else
		uint64_t job_tag                     : 16;
		uint64_t reserved_16_59              : 44;
		uint64_t halted                      : 1;
		uint64_t stop_on_brk                 : 1;
		uint64_t done_brk_ena                : 1;
		uint64_t start_brk_ena               : 1;
#endif
	} s;
	/* struct bdk_phys_dbg_break_cfg_s    cn85xx; */
} bdk_phys_dbg_break_cfg_t;

#define BDK_PHYS_DBG_BREAK_CFG BDK_PHYS_DBG_BREAK_CFG_FUNC()
static inline uint64_t BDK_PHYS_DBG_BREAK_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_DBG_BREAK_CFG_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000800ull;
	else 		csr_fatal("BDK_PHYS_DBG_BREAK_CFG", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_DBG_BREAK_CFG bdk_phys_dbg_break_cfg_t
#define bustype_BDK_PHYS_DBG_BREAK_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_DBG_BREAK_CFG 0
#define arguments_BDK_PHYS_DBG_BREAK_CFG -1,-1,-1,-1
#define basename_BDK_PHYS_DBG_BREAK_CFG "PHYS_DBG_BREAK_CFG"


/**
 * NCB - phys_djcnt_cfg#
 *
 * This register allows reading and setting of dependent job counters.
 *
 */
typedef union bdk_phys_djcnt_cfgx {
	uint64_t u;
	struct bdk_phys_djcnt_cfgx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_58_63              : 6;
		uint64_t djcnt_sosf3                 : 1;  /**< R/W - If 1, the selected DJCNT will be configured to decrement upon each start-of-subframe signal. */
		uint64_t djcnt_update3               : 1;  /**< R/W - If 1, the selected DJCNT will be updated with DJCNT_VAL. */
		uint64_t djcnt_val3                  : 8;  /**< R/W - On read, returns the current value of the DJCNT. On write, the selected DJCNT will be
                                                                 updated with this value if DJCNT_UPDATE is set. */
		uint64_t reserved_42_47              : 6;
		uint64_t djcnt_sosf2                 : 1;  /**< R/W - If 1, the selected DJCNT will be configured to decrement upon each start-of-subframe signal. */
		uint64_t djcnt_update2               : 1;  /**< R/W - If 1, the selected DJCNT will be updated with DJCNT_VAL. */
		uint64_t djcnt_val2                  : 8;  /**< R/W - On read, returns the current value of the DJCNT. On write, the selected DJCNT will be
                                                                 updated with this value if DJCNT_UPDATE is set. */
		uint64_t reserved_26_31              : 6;
		uint64_t djcnt_sosf1                 : 1;  /**< R/W - If 1, the selected DJCNT will be configured to decrement upon each start-of-subframe signal. */
		uint64_t djcnt_update1               : 1;  /**< R/W - If 1, the selected DJCNT will be updated with DJCNT_VAL. */
		uint64_t djcnt_val1                  : 8;  /**< R/W - On read, returns the current value of the DJCNT. On write, the selected DJCNT will be
                                                                 updated with this value if DJCNT_UPDATE is set. */
		uint64_t reserved_10_15              : 6;
		uint64_t djcnt_sosf0                 : 1;  /**< R/W - If 1, the selected DJCNT will be configured to decrement upon each start-of-subframe signal. */
		uint64_t djcnt_update0               : 1;  /**< R/W - If 1, the selected DJCNT will be updated with DJCNT_VAL. */
		uint64_t djcnt_val0                  : 8;  /**< R/W - On read, returns the current value of the DJCNT. On write, the selected DJCNT will be
                                                                 updated with this value if DJCNT_UPDATE is set. */
#else
		uint64_t djcnt_val0                  : 8;
		uint64_t djcnt_update0               : 1;
		uint64_t djcnt_sosf0                 : 1;
		uint64_t reserved_10_15              : 6;
		uint64_t djcnt_val1                  : 8;
		uint64_t djcnt_update1               : 1;
		uint64_t djcnt_sosf1                 : 1;
		uint64_t reserved_26_31              : 6;
		uint64_t djcnt_val2                  : 8;
		uint64_t djcnt_update2               : 1;
		uint64_t djcnt_sosf2                 : 1;
		uint64_t reserved_42_47              : 6;
		uint64_t djcnt_val3                  : 8;
		uint64_t djcnt_update3               : 1;
		uint64_t djcnt_sosf3                 : 1;
		uint64_t reserved_58_63              : 6;
#endif
	} s;
	/* struct bdk_phys_djcnt_cfgx_s       cn85xx; */
} bdk_phys_djcnt_cfgx_t;

static inline uint64_t BDK_PHYS_DJCNT_CFGX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_DJCNT_CFGX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 15)))
		return 0x000085C000000700ull + (param1 & 15) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_DJCNT_CFGX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_DJCNT_CFGX(...) bdk_phys_djcnt_cfgx_t
#define bustype_BDK_PHYS_DJCNT_CFGX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_DJCNT_CFGX(p1) (p1)
#define arguments_BDK_PHYS_DJCNT_CFGX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_DJCNT_CFGX(...) "PHYS_DJCNT_CFGX"


/**
 * NCB - phys_gpint_ena_w1c
 *
 * This register disables the general purpose interrupts. Writing a 1 will
 * disable the selected interrupt. Writes of 0 are ignored. Interrupts are
 * enabled via the PHYS_GPINT_ENA_W1S register.
 */
typedef union bdk_phys_gpint_ena_w1c {
	uint64_t u;
	struct bdk_phys_gpint_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t gpint                       : 64; /**< R/W1C - Disable for each general purpose interrupt. */
#else
		uint64_t gpint                       : 64;
#endif
	} s;
	/* struct bdk_phys_gpint_ena_w1c_s    cn85xx; */
} bdk_phys_gpint_ena_w1c_t;

#define BDK_PHYS_GPINT_ENA_W1C BDK_PHYS_GPINT_ENA_W1C_FUNC()
static inline uint64_t BDK_PHYS_GPINT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_GPINT_ENA_W1C_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000680ull;
	else 		csr_fatal("BDK_PHYS_GPINT_ENA_W1C", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_GPINT_ENA_W1C bdk_phys_gpint_ena_w1c_t
#define bustype_BDK_PHYS_GPINT_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_GPINT_ENA_W1C 0
#define arguments_BDK_PHYS_GPINT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_PHYS_GPINT_ENA_W1C "PHYS_GPINT_ENA_W1C"


/**
 * NCB - phys_gpint_ena_w1s
 *
 * This register enables the general purpose interrupts. Writing a 1 will
 * enable the selected interrupt. Writes of 0 are ignored. Interrupts are
 * disabled via the PHYS_GPINT_ENA_W1S register.
 */
typedef union bdk_phys_gpint_ena_w1s {
	uint64_t u;
	struct bdk_phys_gpint_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t gpint                       : 64; /**< R/W1S - Enable for each general purpose interrupt. */
#else
		uint64_t gpint                       : 64;
#endif
	} s;
	/* struct bdk_phys_gpint_ena_w1s_s    cn85xx; */
} bdk_phys_gpint_ena_w1s_t;

#define BDK_PHYS_GPINT_ENA_W1S BDK_PHYS_GPINT_ENA_W1S_FUNC()
static inline uint64_t BDK_PHYS_GPINT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_GPINT_ENA_W1S_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000670ull;
	else 		csr_fatal("BDK_PHYS_GPINT_ENA_W1S", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_GPINT_ENA_W1S bdk_phys_gpint_ena_w1s_t
#define bustype_BDK_PHYS_GPINT_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_GPINT_ENA_W1S 0
#define arguments_BDK_PHYS_GPINT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_PHYS_GPINT_ENA_W1S "PHYS_GPINT_ENA_W1S"


/**
 * NCB - phys_gpint_sum
 *
 * This register reports the status of the general purpose interrupts. Writing
 * a 1 will clear the selected interupt. Writes of 0 are ignored.
 */
typedef union bdk_phys_gpint_sum {
	uint64_t u;
	struct bdk_phys_gpint_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t gpint                       : 64; /**< R/W1C - Status bit for each general purpose interrupt. */
#else
		uint64_t gpint                       : 64;
#endif
	} s;
	/* struct bdk_phys_gpint_sum_s        cn85xx; */
} bdk_phys_gpint_sum_t;

#define BDK_PHYS_GPINT_SUM BDK_PHYS_GPINT_SUM_FUNC()
static inline uint64_t BDK_PHYS_GPINT_SUM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_GPINT_SUM_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000650ull;
	else 		csr_fatal("BDK_PHYS_GPINT_SUM", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_GPINT_SUM bdk_phys_gpint_sum_t
#define bustype_BDK_PHYS_GPINT_SUM BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_GPINT_SUM 0
#define arguments_BDK_PHYS_GPINT_SUM -1,-1,-1,-1
#define basename_BDK_PHYS_GPINT_SUM "PHYS_GPINT_SUM"


/**
 * NCB - phys_gpint_sum_w1s
 *
 * This register allows software to set the general purpose interrupts. Writing
 * a 1 will set the selected interupt. Writes of 0 are ignored.
 */
typedef union bdk_phys_gpint_sum_w1s {
	uint64_t u;
	struct bdk_phys_gpint_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t gpint                       : 64; /**< R/W1S - Set bit for each general purpose interrupt. */
#else
		uint64_t gpint                       : 64;
#endif
	} s;
	/* struct bdk_phys_gpint_sum_w1s_s    cn85xx; */
} bdk_phys_gpint_sum_w1s_t;

#define BDK_PHYS_GPINT_SUM_W1S BDK_PHYS_GPINT_SUM_W1S_FUNC()
static inline uint64_t BDK_PHYS_GPINT_SUM_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_GPINT_SUM_W1S_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000660ull;
	else 		csr_fatal("BDK_PHYS_GPINT_SUM_W1S", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_GPINT_SUM_W1S bdk_phys_gpint_sum_w1s_t
#define bustype_BDK_PHYS_GPINT_SUM_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_GPINT_SUM_W1S 0
#define arguments_BDK_PHYS_GPINT_SUM_W1S -1,-1,-1,-1
#define basename_BDK_PHYS_GPINT_SUM_W1S "PHYS_GPINT_SUM_W1S"


/**
 * NCB - phys_int_ena_w1c
 *
 * This register disables the special purpose interrupts. Writing a 1 will
 * disable the selected interrupt. Writes of 0 are ignored. Interrupts are
 * enabled via the PHYS_INT_ENA_W1S register.
 */
typedef union bdk_phys_int_ena_w1c {
	uint64_t u;
	struct bdk_phys_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t queueram_ecc_error          : 1;  /**< R/W1C - An uncorrectable ECC error was detected in the queue RAM. */
		uint64_t trace_dbg                   : 1;  /**< R/W1C - Trace interrupt from either a job completion or a job dispatch according
                                                                 to the settings in PHYS_DBG_BREAK_CFG. */
		uint64_t to_error                    : 1;  /**< R/W1C - Job timeout error - a job runtime exceeded the job MAXTIME tiemout value. */
		uint64_t job_error                   : 1;  /**< R/W1C - Job error from PHY Accelerator - a job completed with an error. */
		uint64_t queue_ovf                   : 1;  /**< R/W1C - Queue overflow when adding new commadn to an already full queue. */
		uint64_t tick_ctr_error              : 1;  /**< R/W1C - The tick counter rolled over without a SOSF being received. */
#else
		uint64_t tick_ctr_error              : 1;
		uint64_t queue_ovf                   : 1;
		uint64_t job_error                   : 1;
		uint64_t to_error                    : 1;
		uint64_t trace_dbg                   : 1;
		uint64_t queueram_ecc_error          : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_phys_int_ena_w1c_s      cn85xx; */
} bdk_phys_int_ena_w1c_t;

#define BDK_PHYS_INT_ENA_W1C BDK_PHYS_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_PHYS_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_INT_ENA_W1C_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000630ull;
	else 		csr_fatal("BDK_PHYS_INT_ENA_W1C", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_INT_ENA_W1C bdk_phys_int_ena_w1c_t
#define bustype_BDK_PHYS_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_INT_ENA_W1C 0
#define arguments_BDK_PHYS_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_PHYS_INT_ENA_W1C "PHYS_INT_ENA_W1C"


/**
 * NCB - phys_int_ena_w1s
 *
 * This register enables the special purpose interrupts. Writing a 1 will
 * enable the selected interrupt. Writes of 0 are ignored. Interrupts are
 * disabled via the PHYS_INT_ENA_W1C register.
 */
typedef union bdk_phys_int_ena_w1s {
	uint64_t u;
	struct bdk_phys_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t queueram_ecc_error          : 1;  /**< R/W1S - An uncorrectable ECC error was detected in the queue RAM. */
		uint64_t trace_dbg                   : 1;  /**< R/W1S - Trace interrupt from either a job completion or a job dispatch according
                                                                 to the settings in PHYS_DBG_BREAK_CFG. */
		uint64_t to_error                    : 1;  /**< R/W1S - Job timeout error - a job runtime exceeded the job MAXTIME tiemout value. */
		uint64_t job_error                   : 1;  /**< R/W1S - Job error from PHY Accelerator - a job completed with an error. */
		uint64_t queue_ovf                   : 1;  /**< R/W1S - Queue overflow when adding new commadn to an already full queue. */
		uint64_t tick_ctr_error              : 1;  /**< R/W1S - The tick counter rolled over without a SOSF being received. */
#else
		uint64_t tick_ctr_error              : 1;
		uint64_t queue_ovf                   : 1;
		uint64_t job_error                   : 1;
		uint64_t to_error                    : 1;
		uint64_t trace_dbg                   : 1;
		uint64_t queueram_ecc_error          : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_phys_int_ena_w1s_s      cn85xx; */
} bdk_phys_int_ena_w1s_t;

#define BDK_PHYS_INT_ENA_W1S BDK_PHYS_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_PHYS_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_INT_ENA_W1S_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000620ull;
	else 		csr_fatal("BDK_PHYS_INT_ENA_W1S", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_INT_ENA_W1S bdk_phys_int_ena_w1s_t
#define bustype_BDK_PHYS_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_INT_ENA_W1S 0
#define arguments_BDK_PHYS_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_PHYS_INT_ENA_W1S "PHYS_INT_ENA_W1S"


/**
 * NCB - phys_int_sum
 *
 * This register returns the interrupt status - either an interrupt was
 * triggered, or a debug/error interrupt was triggered. Writing a 1 to the
 * selected bit will clear the interrupt. Writes of 0 are ignored
 */
typedef union bdk_phys_int_sum {
	uint64_t u;
	struct bdk_phys_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t queueram_ecc_error          : 1;  /**< R/W1C - An uncorrectable ECC error was detected in the queue RAM. */
		uint64_t trace_dbg                   : 1;  /**< R/W1C - Trace interrupt from either a job completion or a job dispatch according
                                                                 to the settings in PHYS_DBG_BREAK_CFG. */
		uint64_t to_error                    : 1;  /**< R/W1C - Job timeout error - a job runtime exceeded the job MAXTIME tiemout value. */
		uint64_t job_error                   : 1;  /**< R/W1C - Job error from PHY Accelerator - a job completed with an error. */
		uint64_t queue_ovf                   : 1;  /**< R/W1C - Queue overflow when adding new commadn to an already full queue. */
		uint64_t tick_ctr_error              : 1;  /**< R/W1C - The tick counter rolled over without a SOSF being received. */
#else
		uint64_t tick_ctr_error              : 1;
		uint64_t queue_ovf                   : 1;
		uint64_t job_error                   : 1;
		uint64_t to_error                    : 1;
		uint64_t trace_dbg                   : 1;
		uint64_t queueram_ecc_error          : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_phys_int_sum_s          cn85xx; */
} bdk_phys_int_sum_t;

#define BDK_PHYS_INT_SUM BDK_PHYS_INT_SUM_FUNC()
static inline uint64_t BDK_PHYS_INT_SUM_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_INT_SUM_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000600ull;
	else 		csr_fatal("BDK_PHYS_INT_SUM", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_INT_SUM bdk_phys_int_sum_t
#define bustype_BDK_PHYS_INT_SUM BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_INT_SUM 0
#define arguments_BDK_PHYS_INT_SUM -1,-1,-1,-1
#define basename_BDK_PHYS_INT_SUM "PHYS_INT_SUM"


/**
 * NCB - phys_int_sum_w1s
 *
 * This register allows the interrupts to be set by software for testing
 * purposes. Writing a 1 will set the selected interrupt. Writes of 0 are ignored.
 */
typedef union bdk_phys_int_sum_w1s {
	uint64_t u;
	struct bdk_phys_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t queueram_ecc_error          : 1;  /**< R/W1S - An uncorrectable ECC error was detected in the queue RAM. */
		uint64_t trace_dbg                   : 1;  /**< R/W1S - Trace interrupt from either a job completion or a job dispatch according
                                                                 to the settings in PHYS_DBG_BREAK_CFG. */
		uint64_t to_error                    : 1;  /**< R/W1S - Job timeout error - a job runtime exceeded the job MAXTIME tiemout value. */
		uint64_t job_error                   : 1;  /**< R/W1S - Job error from PHY Accelerator - a job completed with an error. */
		uint64_t queue_ovf                   : 1;  /**< R/W1S - Queue overflow when adding new commadn to an already full queue. */
		uint64_t tick_ctr_error              : 1;  /**< R/W1S - The tick counter rolled over without a SOSF being received. */
#else
		uint64_t tick_ctr_error              : 1;
		uint64_t queue_ovf                   : 1;
		uint64_t job_error                   : 1;
		uint64_t to_error                    : 1;
		uint64_t trace_dbg                   : 1;
		uint64_t queueram_ecc_error          : 1;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_phys_int_sum_w1s_s      cn85xx; */
} bdk_phys_int_sum_w1s_t;

#define BDK_PHYS_INT_SUM_W1S BDK_PHYS_INT_SUM_W1S_FUNC()
static inline uint64_t BDK_PHYS_INT_SUM_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_INT_SUM_W1S_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000610ull;
	else 		csr_fatal("BDK_PHYS_INT_SUM_W1S", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_INT_SUM_W1S bdk_phys_int_sum_w1s_t
#define bustype_BDK_PHYS_INT_SUM_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_INT_SUM_W1S 0
#define arguments_BDK_PHYS_INT_SUM_W1S -1,-1,-1,-1
#define basename_BDK_PHYS_INT_SUM_W1S "PHYS_INT_SUM_W1S"


/**
 * NCB - phys_log_base
 *
 * This register configures the log circular output buffer location in
 * memory and enables the job trace feature.
 */
typedef union bdk_phys_log_base {
	uint64_t u;
	struct bdk_phys_log_base_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t base_ptr                    : 50; /**< R/W - Base address for the job trace log. Must be alligned to a cache line
                                                                 boundary (i.e., 128 byte boundary). */
#else
		uint64_t base_ptr                    : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_phys_log_base_s         cn85xx; */
} bdk_phys_log_base_t;

#define BDK_PHYS_LOG_BASE BDK_PHYS_LOG_BASE_FUNC()
static inline uint64_t BDK_PHYS_LOG_BASE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_LOG_BASE_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C0000007E0ull;
	else 		csr_fatal("BDK_PHYS_LOG_BASE", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_LOG_BASE bdk_phys_log_base_t
#define bustype_BDK_PHYS_LOG_BASE BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_LOG_BASE 0
#define arguments_BDK_PHYS_LOG_BASE -1,-1,-1,-1
#define basename_BDK_PHYS_LOG_BASE "PHYS_LOG_BASE"


/**
 * NCB - phys_log_cfg
 *
 * This register configures the log circular output buffer location in
 * memory and enables the job trace feature.
 */
typedef union bdk_phys_log_cfg {
	uint64_t u;
	struct bdk_phys_log_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_41_63              : 23;
		uint64_t flush                       : 1;  /**< WO - When written 1, flushes any pending log writes remaining
                                                                 in the internal buffer. */
		uint64_t reserved_34_39              : 6;
		uint64_t log_done_en                 : 1;  /**< R/W - Enable output log of all job completions. */
		uint64_t log_start_en                : 1;  /**< R/W - Enable output log of all job starts. */
		uint64_t reserved_16_31              : 16;
		uint64_t log_size                    : 16; /**< R/W - Size in cache lines (128 byte units) of the circular buffer log. */
#else
		uint64_t log_size                    : 16;
		uint64_t reserved_16_31              : 16;
		uint64_t log_start_en                : 1;
		uint64_t log_done_en                 : 1;
		uint64_t reserved_34_39              : 6;
		uint64_t flush                       : 1;
		uint64_t reserved_41_63              : 23;
#endif
	} s;
	/* struct bdk_phys_log_cfg_s          cn85xx; */
} bdk_phys_log_cfg_t;

#define BDK_PHYS_LOG_CFG BDK_PHYS_LOG_CFG_FUNC()
static inline uint64_t BDK_PHYS_LOG_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_LOG_CFG_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C0000007D0ull;
	else 		csr_fatal("BDK_PHYS_LOG_CFG", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_LOG_CFG bdk_phys_log_cfg_t
#define bustype_BDK_PHYS_LOG_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_LOG_CFG 0
#define arguments_BDK_PHYS_LOG_CFG -1,-1,-1,-1
#define basename_BDK_PHYS_LOG_CFG "PHYS_LOG_CFG"


/**
 * NCB - phys_log_ptr
 *
 * This register configures the log circular output buffer location in
 * memory and enables the job trace feature.
 */
typedef union bdk_phys_log_ptr {
	uint64_t u;
	struct bdk_phys_log_ptr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t log_ptr                     : 50; /**< R/W - Address of the current output pointer for the job trace log. As new
                                                                 blocks are output, log_ptr will be updated. Must be doubleword aligned. */
#else
		uint64_t log_ptr                     : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_phys_log_ptr_s          cn85xx; */
} bdk_phys_log_ptr_t;

#define BDK_PHYS_LOG_PTR BDK_PHYS_LOG_PTR_FUNC()
static inline uint64_t BDK_PHYS_LOG_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_LOG_PTR_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C0000007F0ull;
	else 		csr_fatal("BDK_PHYS_LOG_PTR", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_LOG_PTR bdk_phys_log_ptr_t
#define bustype_BDK_PHYS_LOG_PTR BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_LOG_PTR 0
#define arguments_BDK_PHYS_LOG_PTR -1,-1,-1,-1
#define basename_BDK_PHYS_LOG_PTR "PHYS_LOG_PTR"


/**
 * NCB - phys_max_credit#
 *
 * This register defines the maximum number of jobs that each Accelerator
 * can accept at one time.
 */
typedef union bdk_phys_max_creditx {
	uint64_t u;
	struct bdk_phys_max_creditx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t max15                       : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 15. */
		uint64_t max14                       : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 14. */
		uint64_t max13                       : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 13. */
		uint64_t max12                       : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 12. */
		uint64_t max11                       : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 11. */
		uint64_t max10                       : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 10. */
		uint64_t max9                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 9. */
		uint64_t max8                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 8. */
		uint64_t max7                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 7. */
		uint64_t max6                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 6. */
		uint64_t max5                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 5. */
		uint64_t max4                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 4. */
		uint64_t max3                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 3. */
		uint64_t max2                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 2. */
		uint64_t max1                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 1. */
		uint64_t max0                        : 4;  /**< R/W - Maximum number of jobs for PHY Accelerator 0. */
#else
		uint64_t max0                        : 4;
		uint64_t max1                        : 4;
		uint64_t max2                        : 4;
		uint64_t max3                        : 4;
		uint64_t max4                        : 4;
		uint64_t max5                        : 4;
		uint64_t max6                        : 4;
		uint64_t max7                        : 4;
		uint64_t max8                        : 4;
		uint64_t max9                        : 4;
		uint64_t max10                       : 4;
		uint64_t max11                       : 4;
		uint64_t max12                       : 4;
		uint64_t max13                       : 4;
		uint64_t max14                       : 4;
		uint64_t max15                       : 4;
#endif
	} s;
	/* struct bdk_phys_max_creditx_s      cn85xx; */
} bdk_phys_max_creditx_t;

static inline uint64_t BDK_PHYS_MAX_CREDITX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_MAX_CREDITX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 3)))
		return 0x000085C000000C00ull + (param1 & 3) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_MAX_CREDITX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_MAX_CREDITX(...) bdk_phys_max_creditx_t
#define bustype_BDK_PHYS_MAX_CREDITX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_MAX_CREDITX(p1) (p1)
#define arguments_BDK_PHYS_MAX_CREDITX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_MAX_CREDITX(...) "PHYS_MAX_CREDITX"


/**
 * NCB - phys_queue_busy_sts
 *
 * This register contains busy status bits for each queue from
 * 0 through 31.
 */
typedef union bdk_phys_queue_busy_sts {
	uint64_t u;
	struct bdk_phys_queue_busy_sts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t busy                        : 32; /**< RO - 1 = Queue Busy, at least one command queued or in-flight.
                                                                 0 = No cmds queued or in-flight. */
#else
		uint64_t busy                        : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_phys_queue_busy_sts_s   cn85xx; */
} bdk_phys_queue_busy_sts_t;

#define BDK_PHYS_QUEUE_BUSY_STS BDK_PHYS_QUEUE_BUSY_STS_FUNC()
static inline uint64_t BDK_PHYS_QUEUE_BUSY_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_BUSY_STS_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000018ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_BUSY_STS", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_BUSY_STS bdk_phys_queue_busy_sts_t
#define bustype_BDK_PHYS_QUEUE_BUSY_STS BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_BUSY_STS 0
#define arguments_BDK_PHYS_QUEUE_BUSY_STS -1,-1,-1,-1
#define basename_BDK_PHYS_QUEUE_BUSY_STS "PHYS_QUEUE_BUSY_STS"


/**
 * NCB - phys_queue_cfg#
 *
 * This register configures the high and low value of each circular command
 * queue within the Queue RAM. The Queue RAM contains 2048 entries, and
 * software must carefully determine the high and low entries for each queue to
 * avoid overflow and make sure the queues do not overlap.
 */
typedef union bdk_phys_queue_cfgx {
	uint64_t u;
	struct bdk_phys_queue_cfgx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t prio                        : 2;  /**< R/W - Queue priority. 0 = highest priority, 3 = lowest priority. */
		uint64_t reserved_29_31              : 3;
		uint64_t top                         : 13; /**< R/W - HIGH address pointer for the queue. Must be greater than the LO
                                                                 address pointer. */
		uint64_t reserved_13_15              : 3;
		uint64_t base                        : 13; /**< R/W - LO address pointer for the queue. */
#else
		uint64_t base                        : 13;
		uint64_t reserved_13_15              : 3;
		uint64_t top                         : 13;
		uint64_t reserved_29_31              : 3;
		uint64_t prio                        : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_phys_queue_cfgx_s       cn85xx; */
} bdk_phys_queue_cfgx_t;

static inline uint64_t BDK_PHYS_QUEUE_CFGX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_CFGX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 31)))
		return 0x000085C000000100ull + (param1 & 31) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_CFGX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_CFGX(...) bdk_phys_queue_cfgx_t
#define bustype_BDK_PHYS_QUEUE_CFGX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_CFGX(p1) (p1)
#define arguments_BDK_PHYS_QUEUE_CFGX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_QUEUE_CFGX(...) "PHYS_QUEUE_CFGX"


/**
 * NCB - phys_queue_cmd_hi#
 *
 * These registers are aliased to the 32 command queues. If the corresponding PHYS_QUEUE_CMD_LOn
 * register holds the low order bits of a Job command or a continued Job command, then a write
 * to this register results in adding the command to the tail of the
 * specified queue, with bits <127:64> taken from this register and bits <63:0> taken from the
 * corresponding PHYS_QUEUE_CMD_LOn register.  The tail and
 * notempty registers are updated accordingly. If the queue is full, a Queue Overflow
 * interrupt is triggered.
 */
typedef union bdk_phys_queue_cmd_hix {
	uint64_t u;
	struct bdk_phys_queue_cmd_hix_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t command                     : 64; /**< WO - The host processor writes a valid PHY scheduler command to this
                                                                 register. If the queue is already full, then a Queue Overflow
                                                                 interrupt will be triggered, and the command will be dropped. */
#else
		uint64_t command                     : 64;
#endif
	} s;
	/* struct bdk_phys_queue_cmd_hix_s    cn85xx; */
} bdk_phys_queue_cmd_hix_t;

static inline uint64_t BDK_PHYS_QUEUE_CMD_HIX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_CMD_HIX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 31)))
		return 0x000085C000000408ull + (param1 & 31) * 0x10ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_CMD_HIX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_CMD_HIX(...) bdk_phys_queue_cmd_hix_t
#define bustype_BDK_PHYS_QUEUE_CMD_HIX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_CMD_HIX(p1) (p1)
#define arguments_BDK_PHYS_QUEUE_CMD_HIX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_QUEUE_CMD_HIX(...) "PHYS_QUEUE_CMD_HIX"


/**
 * NCB - phys_queue_cmd_lo#
 *
 * These registers are aliased to the 32 command queues. Writing a Wait, Int, or DJCNT
 * command to one of these registers results in adding the command to the tail of the
 * specified queue, with bits <127:64> of the command set to zero. The tail and
 * notempty registers are updated accordingly. If the queue is full, a Queue Overflow
 * interrupt is triggered. Writing the least significant 64 bits of a Job command or a
 * Continued Job command results in holding the bits in this register.
 */
typedef union bdk_phys_queue_cmd_lox {
	uint64_t u;
	struct bdk_phys_queue_cmd_lox_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t command                     : 64; /**< R/W/H - The host processor writes a valid PHY scheduler command to this
                                                                 register. If the queue is already full, then a Queue Overflow
                                                                 interrupt will be triggered, and the command will be dropped. */
#else
		uint64_t command                     : 64;
#endif
	} s;
	/* struct bdk_phys_queue_cmd_lox_s    cn85xx; */
} bdk_phys_queue_cmd_lox_t;

static inline uint64_t BDK_PHYS_QUEUE_CMD_LOX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_CMD_LOX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 31)))
		return 0x000085C000000400ull + (param1 & 31) * 0x10ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_CMD_LOX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_CMD_LOX(...) bdk_phys_queue_cmd_lox_t
#define bustype_BDK_PHYS_QUEUE_CMD_LOX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_CMD_LOX(p1) (p1)
#define arguments_BDK_PHYS_QUEUE_CMD_LOX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_QUEUE_CMD_LOX(...) "PHYS_QUEUE_CMD_LOX"


/**
 * NCB - phys_queue_ena
 *
 * This register contains enable bits for each queue from
 * 0 through 31.
 */
typedef union bdk_phys_queue_ena {
	uint64_t u;
	struct bdk_phys_queue_ena_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ena                         : 32; /**< R/W - Enable bit for each queue. If 0, the queue is disabled.
                                                                 Jobs may be added to the queue, but the queue wil not execute. */
#else
		uint64_t ena                         : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_phys_queue_ena_s        cn85xx; */
} bdk_phys_queue_ena_t;

#define BDK_PHYS_QUEUE_ENA BDK_PHYS_QUEUE_ENA_FUNC()
static inline uint64_t BDK_PHYS_QUEUE_ENA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_ENA_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000000ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_ENA", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_ENA bdk_phys_queue_ena_t
#define bustype_BDK_PHYS_QUEUE_ENA BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_ENA 0
#define arguments_BDK_PHYS_QUEUE_ENA -1,-1,-1,-1
#define basename_BDK_PHYS_QUEUE_ENA "PHYS_QUEUE_ENA"


/**
 * NCB - phys_queue_full_sts
 *
 * This register contains full indicators for each queue from
 * 0 through 31.
 */
typedef union bdk_phys_queue_full_sts {
	uint64_t u;
	struct bdk_phys_queue_full_sts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t full                        : 32; /**< RO - For each queue, a 1 bit indicates the queue is full, a 0 indicates
                                                                 the queue is not full and a cnARM core can enqueue a job. */
#else
		uint64_t full                        : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_phys_queue_full_sts_s   cn85xx; */
} bdk_phys_queue_full_sts_t;

#define BDK_PHYS_QUEUE_FULL_STS BDK_PHYS_QUEUE_FULL_STS_FUNC()
static inline uint64_t BDK_PHYS_QUEUE_FULL_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_FULL_STS_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000010ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_FULL_STS", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_FULL_STS bdk_phys_queue_full_sts_t
#define bustype_BDK_PHYS_QUEUE_FULL_STS BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_FULL_STS 0
#define arguments_BDK_PHYS_QUEUE_FULL_STS -1,-1,-1,-1
#define basename_BDK_PHYS_QUEUE_FULL_STS "PHYS_QUEUE_FULL_STS"


/**
 * NCB - phys_queue_ptr#
 *
 * This register returns the status of each queues head and tail pointers.
 *
 */
typedef union bdk_phys_queue_ptrx {
	uint64_t u;
	struct bdk_phys_queue_ptrx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t full                        : 1;  /**< RO - Indicates the queue is full. */
		uint64_t notempty                    : 1;  /**< RO - Indicates there are commands in the queue. */
		uint64_t reserved_29_31              : 3;
		uint64_t tail                        : 13; /**< RO - Tail pointer in the queue. Points to the next entry for adding an
                                                                 item to the queue. */
		uint64_t reserved_13_15              : 3;
		uint64_t head                        : 13; /**< RO - The head pointer in the queue. Points to the top of the queue which
                                                                 holds the item currently arbitrating for execution. */
#else
		uint64_t head                        : 13;
		uint64_t reserved_13_15              : 3;
		uint64_t tail                        : 13;
		uint64_t reserved_29_31              : 3;
		uint64_t notempty                    : 1;
		uint64_t full                        : 1;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_phys_queue_ptrx_s       cn85xx; */
} bdk_phys_queue_ptrx_t;

static inline uint64_t BDK_PHYS_QUEUE_PTRX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_PTRX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 31)))
		return 0x000085C000000200ull + (param1 & 31) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_PTRX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_PTRX(...) bdk_phys_queue_ptrx_t
#define bustype_BDK_PHYS_QUEUE_PTRX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_PTRX(p1) (p1)
#define arguments_BDK_PHYS_QUEUE_PTRX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_QUEUE_PTRX(...) "PHYS_QUEUE_PTRX"


/**
 * NCB - phys_queue_ram#
 *
 * These addresses provide a debug mechanism into the Queue RAM. Both read
 * and write accesses are allowed into individual Queue RAM entries.
 */
typedef union bdk_phys_queue_ramx {
	uint64_t u;
	struct bdk_phys_queue_ramx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t entry                       : 64; /**< R/W - The Queue RAM entry data. */
#else
		uint64_t entry                       : 64;
#endif
	} s;
	/* struct bdk_phys_queue_ramx_s       cn85xx; */
} bdk_phys_queue_ramx_t;

static inline uint64_t BDK_PHYS_QUEUE_RAMX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_RAMX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 16383)))
		return 0x000085C000020000ull + (param1 & 16383) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_RAMX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_RAMX(...) bdk_phys_queue_ramx_t
#define bustype_BDK_PHYS_QUEUE_RAMX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_RAMX(p1) (p1)
#define arguments_BDK_PHYS_QUEUE_RAMX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_QUEUE_RAMX(...) "PHYS_QUEUE_RAMX"


/**
 * NCB - phys_queue_space#
 *
 * This register reports the number of free entries in each queue.
 *
 */
typedef union bdk_phys_queue_spacex {
	uint64_t u;
	struct bdk_phys_queue_spacex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t space                       : 13; /**< RO - The number of commands that can be added to the queue. */
#else
		uint64_t space                       : 13;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_phys_queue_spacex_s     cn85xx; */
} bdk_phys_queue_spacex_t;

static inline uint64_t BDK_PHYS_QUEUE_SPACEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_QUEUE_SPACEX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 31)))
		return 0x000085C000000300ull + (param1 & 31) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_QUEUE_SPACEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_QUEUE_SPACEX(...) bdk_phys_queue_spacex_t
#define bustype_BDK_PHYS_QUEUE_SPACEX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_QUEUE_SPACEX(p1) (p1)
#define arguments_BDK_PHYS_QUEUE_SPACEX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_QUEUE_SPACEX(...) "PHYS_QUEUE_SPACEX"


/**
 * NCB - phys_rsrc_tbl#
 *
 * This register defines a mapping table of Job Types to PHY MegaHAB Accelerators.
 * Multiple PHY Accelerators maybe assigned to service jobs of each type.
 */
typedef union bdk_phys_rsrc_tblx {
	uint64_t u;
	struct bdk_phys_rsrc_tblx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ab_map                      : 64; /**< R/W - Bit mask indicating which PHY Accelerators can accept jobs of type
                                                                 N. E.g., if bits 2, 4, and 5 are set in register PHYS_RSRC_TBL7,
                                                                 then PHY Accelerators 2, 4, and 5 can service jobs of type 7. */
#else
		uint64_t ab_map                      : 64;
#endif
	} s;
	/* struct bdk_phys_rsrc_tblx_s        cn85xx; */
} bdk_phys_rsrc_tblx_t;

static inline uint64_t BDK_PHYS_RSRC_TBLX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_RSRC_TBLX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 63)))
		return 0x000085C000000A00ull + (param1 & 63) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_RSRC_TBLX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_RSRC_TBLX(...) bdk_phys_rsrc_tblx_t
#define bustype_BDK_PHYS_RSRC_TBLX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_RSRC_TBLX(p1) (p1)
#define arguments_BDK_PHYS_RSRC_TBLX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_RSRC_TBLX(...) "PHYS_RSRC_TBLX"


/**
 * NCB - phys_rst
 *
 * This register provides a mechanism to reset the PHY Scheduler,
 * and individual scheduler queues.
 */
typedef union bdk_phys_rst {
	uint64_t u;
	struct bdk_phys_rst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t queue_reset                 : 32; /**< WO - Each set bit will reset an individual queue (any of the 32). Reset will empty the queue
                                                                 and reset any in-flight jobs dispatched from the given queue. */
		uint64_t reserved_1_31               : 31;
		uint64_t reset                       : 1;  /**< WO - When set, will reset entire PHY Scheduler to hardware reset state. */
#else
		uint64_t reset                       : 1;
		uint64_t reserved_1_31               : 31;
		uint64_t queue_reset                 : 32;
#endif
	} s;
	/* struct bdk_phys_rst_s              cn85xx; */
} bdk_phys_rst_t;

#define BDK_PHYS_RST BDK_PHYS_RST_FUNC()
static inline uint64_t BDK_PHYS_RST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_RST_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000820ull;
	else 		csr_fatal("BDK_PHYS_RST", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_RST bdk_phys_rst_t
#define bustype_BDK_PHYS_RST BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_RST 0
#define arguments_BDK_PHYS_RST -1,-1,-1,-1
#define basename_BDK_PHYS_RST "PHYS_RST"


/**
 * NCB - phys_svmid
 *
 * This is a hypervisor only CSR.
 *
 */
typedef union bdk_phys_svmid {
	uint64_t u;
	struct bdk_phys_svmid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t svmid                       : 16; /**< R/W - The SVMID the PHY Scheduler uses when enqueueing work in the SSO, or with the FPA. */
#else
		uint64_t svmid                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_phys_svmid_s            cn85xx; */
} bdk_phys_svmid_t;

#define BDK_PHYS_SVMID BDK_PHYS_SVMID_FUNC()
static inline uint64_t BDK_PHYS_SVMID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_SVMID_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000010000ull;
	else 		csr_fatal("BDK_PHYS_SVMID", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_SVMID bdk_phys_svmid_t
#define bustype_BDK_PHYS_SVMID BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_SVMID 0
#define arguments_BDK_PHYS_SVMID -1,-1,-1,-1
#define basename_BDK_PHYS_SVMID "PHYS_SVMID"


/**
 * NCB - phys_tim_trig_cfg#
 *
 * This register configures the timestampt tirggers. At a certain timer value,
 * a dependent job counter can be decremented.
 */
typedef union bdk_phys_tim_trig_cfgx {
	uint64_t u;
	struct bdk_phys_tim_trig_cfgx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t djcnt                       : 8;  /**< R/W - Dependent Job Counter (1-63) to decrement when timer value matches trigger.
                                                                 If 0, then trigger is disabled. */
		uint64_t reserved_46_47              : 2;
		uint64_t trig_subframe               : 30; /**< R/W - SUBFRAME value for triggering a decrement of a dependent job counter. */
		uint64_t trig_tick                   : 16; /**< R/W - TICK value for triggering a decrement of a dependent job counter. */
#else
		uint64_t trig_tick                   : 16;
		uint64_t trig_subframe               : 30;
		uint64_t reserved_46_47              : 2;
		uint64_t djcnt                       : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_phys_tim_trig_cfgx_s    cn85xx; */
} bdk_phys_tim_trig_cfgx_t;

static inline uint64_t BDK_PHYS_TIM_TRIG_CFGX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_TIM_TRIG_CFGX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX) && ((param1 <= 7)))
		return 0x000085C000000780ull + (param1 & 7) * 0x8ull;
	else 		csr_fatal("BDK_PHYS_TIM_TRIG_CFGX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_TIM_TRIG_CFGX(...) bdk_phys_tim_trig_cfgx_t
#define bustype_BDK_PHYS_TIM_TRIG_CFGX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_TIM_TRIG_CFGX(p1) (p1)
#define arguments_BDK_PHYS_TIM_TRIG_CFGX(p1) (p1),-1,-1,-1
#define basename_BDK_PHYS_TIM_TRIG_CFGX(...) "PHYS_TIM_TRIG_CFGX"


/**
 * NCB - phys_tim_val
 *
 * This register holds the subframe count and timer tick within the subframe. The
 * Tick value is incremented every cycle and cleared every SOsF. The Subframe
 * value is incremented every SOsF. This timer is used for job trace log
 * timestamps, and for timestamp triggers.
 */
typedef union bdk_phys_tim_val {
	uint64_t u;
	struct bdk_phys_tim_val_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ena                         : 1;  /**< R/W - Timer enable. */
		uint64_t reserved_58_62              : 5;
		uint64_t sf_update                   : 1;  /**< R/W - If written 1, update SUBFRAME count. */
		uint64_t tick_update                 : 1;  /**< R/W - If written 1, update TICK count. */
		uint64_t reserved_46_55              : 10;
		uint64_t subframe                    : 30; /**< R/W - Subframe count. Increments every SOsF */
		uint64_t tick                        : 16; /**< R/W - Current timer count. When enabled, a SOsF signal from RFIF will reset
                                                                 the timer to 0 and increment every cycle. */
#else
		uint64_t tick                        : 16;
		uint64_t subframe                    : 30;
		uint64_t reserved_46_55              : 10;
		uint64_t tick_update                 : 1;
		uint64_t sf_update                   : 1;
		uint64_t reserved_58_62              : 5;
		uint64_t ena                         : 1;
#endif
	} s;
	/* struct bdk_phys_tim_val_s          cn85xx; */
} bdk_phys_tim_val_t;

#define BDK_PHYS_TIM_VAL BDK_PHYS_TIM_VAL_FUNC()
static inline uint64_t BDK_PHYS_TIM_VAL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_TIM_VAL_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C0000007C0ull;
	else 		csr_fatal("BDK_PHYS_TIM_VAL", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_TIM_VAL bdk_phys_tim_val_t
#define bustype_BDK_PHYS_TIM_VAL BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_TIM_VAL 0
#define arguments_BDK_PHYS_TIM_VAL -1,-1,-1,-1
#define basename_BDK_PHYS_TIM_VAL "PHYS_TIM_VAL"


/**
 * NCB - phys_timeout_cfg
 *
 * This register configures the Job Timeout mechanism.
 *
 */
typedef union bdk_phys_timeout_cfg {
	uint64_t u;
	struct bdk_phys_timeout_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ena                         : 1;  /**< R/W - Enable PHYS to generate timeout error interrupt if any job is
                                                                 outstanding for longer than MAXTIME cycles. */
		uint64_t reserved_32_62              : 31;
		uint64_t maxtime                     : 32; /**< R/W - Maximum cycles before a job timeout. */
#else
		uint64_t maxtime                     : 32;
		uint64_t reserved_32_62              : 31;
		uint64_t ena                         : 1;
#endif
	} s;
	/* struct bdk_phys_timeout_cfg_s      cn85xx; */
} bdk_phys_timeout_cfg_t;

#define BDK_PHYS_TIMEOUT_CFG BDK_PHYS_TIMEOUT_CFG_FUNC()
static inline uint64_t BDK_PHYS_TIMEOUT_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PHYS_TIMEOUT_CFG_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN85XX))
		return 0x000085C000000810ull;
	else 		csr_fatal("BDK_PHYS_TIMEOUT_CFG", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_PHYS_TIMEOUT_CFG bdk_phys_timeout_cfg_t
#define bustype_BDK_PHYS_TIMEOUT_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_PHYS_TIMEOUT_CFG 0
#define arguments_BDK_PHYS_TIMEOUT_CFG -1,-1,-1,-1
#define basename_BDK_PHYS_TIMEOUT_CFG "PHYS_TIMEOUT_CFG"

#endif /* __BDK_CSRS_PSM__ */
