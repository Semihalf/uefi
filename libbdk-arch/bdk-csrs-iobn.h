#ifndef __BDK_CSRS_IOBN__
#define __BDK_CSRS_IOBN__
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
 * Cavium IOBN.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Bar IOBN_BAR_E
 *
 * IOBN Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#ifdef __cplusplus
namespace IOBN_BAR_E {
	const uint64_t IOBN0_PF_BAR0 = 0x87e0f0000000;
	const uint64_t IOBN0_PF_BAR0_PCC_BAR_SIZE_BITS = 23;
	const uint64_t IOBN0_PF_BAR4 = 0x87e0f0f00000;
	const uint64_t IOBN0_PF_BAR4_PCC_BAR_SIZE_BITS = 20;
	const uint64_t IOBN1_PF_BAR0 = 0x87e0f1000000;
	const uint64_t IOBN1_PF_BAR0_PCC_BAR_SIZE_BITS = 23;
	const uint64_t IOBN1_PF_BAR4 = 0x87e0f1f00000;
	const uint64_t IOBN1_PF_BAR4_PCC_BAR_SIZE_BITS = 20;
};
#endif

/**
 * Enumeration IOBN_INT_VEC_E
 *
 * IOBN MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum iobn_int_vec_e {
	IOBN_INT_VEC_E_INTS = 0x0,
	IOBN_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - iobn#_bistr_reg
 *
 * This register contains the result of the BIST run on the IOB rclk memories.
 *
 */
typedef union bdk_iobnx_bistr_reg {
	uint64_t u;
	struct bdk_iobnx_bistr_reg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t status                      : 19; /**< RO - Memory BIST status. INTERNAL:
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
#else
		uint64_t status                      : 19;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_iobnx_bistr_reg_s       cn85xx; */
	/* struct bdk_iobnx_bistr_reg_s       cn88xx; */
} bdk_iobnx_bistr_reg_t;

static inline uint64_t BDK_IOBNX_BISTR_REG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_BISTR_REG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0005008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_BISTR_REG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_BISTR_REG(...) bdk_iobnx_bistr_reg_t
#define bustype_BDK_IOBNX_BISTR_REG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_BISTR_REG(p1) (p1)
#define arguments_BDK_IOBNX_BISTR_REG(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_BISTR_REG(...) "IOBNX_BISTR_REG"


/**
 * RSL - iobn#_bists_reg
 *
 * This register contains the result of the BIST run on the IOB sclk memories.
 *
 */
typedef union bdk_iobnx_bists_reg {
	uint64_t u;
	struct bdk_iobnx_bists_reg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t status                      : 11; /**< RO - Memory BIST status: INTERNAL:
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
#else
		uint64_t status                      : 11;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_iobnx_bists_reg_s       cn85xx; */
	/* struct bdk_iobnx_bists_reg_s       cn88xx; */
} bdk_iobnx_bists_reg_t;

static inline uint64_t BDK_IOBNX_BISTS_REG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_BISTS_REG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0005000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_BISTS_REG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_BISTS_REG(...) bdk_iobnx_bists_reg_t
#define bustype_BDK_IOBNX_BISTS_REG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_BISTS_REG(p1) (p1)
#define arguments_BDK_IOBNX_BISTS_REG(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_BISTS_REG(...) "IOBNX_BISTS_REG"


/**
 * RSL - iobn#_chip_cur_pwr
 *
 * This register contains the current power setting.
 *
 */
typedef union bdk_iobnx_chip_cur_pwr {
	uint64_t u;
	struct bdk_iobnx_chip_cur_pwr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t current_power_setting       : 8;  /**< RO/H - Global throttling value currently being used. Throttling can force units (CPU cores, in
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
#else
		uint64_t current_power_setting       : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_iobnx_chip_cur_pwr_s    cn85xx; */
	/* struct bdk_iobnx_chip_cur_pwr_s    cn88xx; */
} bdk_iobnx_chip_cur_pwr_t;

static inline uint64_t BDK_IOBNX_CHIP_CUR_PWR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CHIP_CUR_PWR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F000A110ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_CHIP_CUR_PWR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_CHIP_CUR_PWR(...) bdk_iobnx_chip_cur_pwr_t
#define bustype_BDK_IOBNX_CHIP_CUR_PWR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_CHIP_CUR_PWR(p1) (p1)
#define arguments_BDK_IOBNX_CHIP_CUR_PWR(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_CHIP_CUR_PWR(...) "IOBNX_CHIP_CUR_PWR"


/**
 * RSL - iobn#_chip_glb_pwr_throttle
 *
 * This register controls the min/max power settings.
 *
 */
typedef union bdk_iobnx_chip_glb_pwr_throttle {
	uint64_t u;
	struct bdk_iobnx_chip_glb_pwr_throttle_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t pwr_bw                      : 2;  /**< R/W - Configures the reaction time of the closed-loop feedback control system for the
                                                                 AVG_CHIP_POWER power approximation. Higher numbers decrease bandwidth, reducing response
                                                                 time, which could lead to greater tracking error, but reduce ringing. */
		uint64_t pwr_max                     : 8;  /**< R/W - Maximum allowed CURRENT_POWER_SETTING value. PWR_MAX must be >= PWR_MIN. */
		uint64_t pwr_min                     : 8;  /**< R/W - Minimum allowed CURRENT_POWER_SETTING value. PWR_MIN must be <= PWR_MAX. We recommend a
                                                                 PWR_MIN value larger than zero to set a minimum performance level in case PWR_SETTING is
                                                                 set to an unreachable goal. See the CPU CP0 PowThrottle description. PWR_MIN = 50% of
                                                                 PowThrottle[MAXPOW] could be a good choice, for example. */
		uint64_t pwr_setting                 : 16; /**< R/W - A power limiter for the chip. A limiter of the power consumption of the chip. This power
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
#else
		uint64_t pwr_setting                 : 16;
		uint64_t pwr_min                     : 8;
		uint64_t pwr_max                     : 8;
		uint64_t pwr_bw                      : 2;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_iobnx_chip_glb_pwr_throttle_s cn85xx; */
	/* struct bdk_iobnx_chip_glb_pwr_throttle_s cn88xx; */
} bdk_iobnx_chip_glb_pwr_throttle_t;

static inline uint64_t BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F000A100ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_CHIP_GLB_PWR_THROTTLE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(...) bdk_iobnx_chip_glb_pwr_throttle_t
#define bustype_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(p1) (p1)
#define arguments_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_CHIP_GLB_PWR_THROTTLE(...) "IOBNX_CHIP_GLB_PWR_THROTTLE"


/**
 * RSL - iobn#_chip_pwr_out
 *
 * This register contains power numbers from the various partitions on the chip.
 *
 */
typedef union bdk_iobnx_chip_pwr_out {
	uint64_t u;
	struct bdk_iobnx_chip_pwr_out_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cpu_pwr                     : 16; /**< RO/H - An estimate of the current CPU core complex power consumption. The CPU core complex
                                                                 includes the caches and DRAM controller(s), as well as all CPU cores. Linearly larger
                                                                 values indicate linearly higher power consumption. This power consumption estimate is
                                                                 energy per core clock. */
		uint64_t chip_power                  : 16; /**< RO/H - An estimate of the current total power consumption by the chip. Linearly larger values
                                                                 indicate linearly higher power consumption. CHIP_POWER is the sum of CPU_POWER and
                                                                 COPROC_POWER. */
		uint64_t coproc_power                : 16; /**< RO/H - An estimate of the current coprocessor power consumption. Linearly larger values indicate
                                                                 linearly higher power consumption. This estimate is energy per core clock, and will
                                                                 generally decrease as the ratio of core to coprocessor clock speed increases. */
		uint64_t avg_chip_power              : 16; /**< RO/H - An average of CHIP_POWER, calculated using an IIR filter with an average weight of 16K core clocks. */
#else
		uint64_t avg_chip_power              : 16;
		uint64_t coproc_power                : 16;
		uint64_t chip_power                  : 16;
		uint64_t cpu_pwr                     : 16;
#endif
	} s;
	/* struct bdk_iobnx_chip_pwr_out_s    cn85xx; */
	/* struct bdk_iobnx_chip_pwr_out_s    cn88xx; */
} bdk_iobnx_chip_pwr_out_t;

static inline uint64_t BDK_IOBNX_CHIP_PWR_OUT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_CHIP_PWR_OUT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F000A108ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_CHIP_PWR_OUT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_CHIP_PWR_OUT(...) bdk_iobnx_chip_pwr_out_t
#define bustype_BDK_IOBNX_CHIP_PWR_OUT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_CHIP_PWR_OUT(p1) (p1)
#define arguments_BDK_IOBNX_CHIP_PWR_OUT(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_CHIP_PWR_OUT(...) "IOBNX_CHIP_PWR_OUT"


/**
 * RSL - iobn#_dis_ncbi_io
 *
 * IOBN control.
 *
 */
typedef union bdk_iobnx_dis_ncbi_io {
	uint64_t u;
	struct bdk_iobnx_dis_ncbi_io_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t oci_key_only                : 1;  /**< R/W - When set, allows CCPI-sourced I/O write requests to KEY_MEM(0..2047) (e.g. 16KB, not
                                                                 all of KEY_MEM).
                                                                 CCPI-sourced writes to __any__ other address (non-KEY), or any CCPI source read will be
                                                                 redirected to ECAM0_NOP_ZF. This does not affect local-node originated traffic. */
		uint64_t all_gic                     : 1;  /**< R/W - All-to-GIC. For diagnostic use only. INTERNAL:
                                                                   0 = Normal operation. NCBI traffic to GIC interrupt delivery registers will be ordered
                                                                 with other interrupt delivery traffic and over the RIB bus.  NCBI traffic to normal non-
                                                                 interrupt-delivery GIC registers will go via RSL.
                                                                   1 = All NCBI traffic to the GIC DID will be assumed to be interrupt delivery traffic.
                                                                 This will break NCBI write transactions to non-interrupt-delivery GIC registers, but may
                                                                 work around bugs whereby interrupt-delivery CSRs are mis-catagorized inside IOB. */
		uint64_t ncbi_off                    : 1;  /**< R/W - When set NCBI translation to I/O space (with exception of GIC traffic) will be disabled.
                                                                 Disabled traffic will turn into access to ECAM0_NOP_ZF. */
#else
		uint64_t ncbi_off                    : 1;
		uint64_t all_gic                     : 1;
		uint64_t oci_key_only                : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_iobnx_dis_ncbi_io_s     cn85xx; */
	/* struct bdk_iobnx_dis_ncbi_io_s     cn88xx; */
} bdk_iobnx_dis_ncbi_io_t;

static inline uint64_t BDK_IOBNX_DIS_NCBI_IO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_DIS_NCBI_IO(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0003000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_DIS_NCBI_IO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_DIS_NCBI_IO(...) bdk_iobnx_dis_ncbi_io_t
#define bustype_BDK_IOBNX_DIS_NCBI_IO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_DIS_NCBI_IO(p1) (p1)
#define arguments_BDK_IOBNX_DIS_NCBI_IO(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_DIS_NCBI_IO(...) "IOBNX_DIS_NCBI_IO"


/**
 * RSL - iobn#_gbl_dll
 *
 * Status of the global core-clock DLL.
 *
 */
typedef union bdk_iobnx_gbl_dll {
	uint64_t u;
	struct bdk_iobnx_gbl_dll_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t pdr_rclk_refclk             : 1;  /**< RO/H - Synchronized pdr_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
		uint64_t pdl_rclk_refclk             : 1;  /**< RO/H - Synchronized pdl_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
		uint64_t pd_pos_rclk_refclk          : 1;  /**< RO/H - Synchronized pd_pos_rclk_refclk from global core-clock DLL cmb0 phase detectors. */
		uint64_t dll_fsm_state_a             : 3;  /**< RO/H - State for the global core-clock DLL, from the positive edge of refclk.
                                                                 0x0 = TMD_IDLE.
                                                                 0x1 = TMD_STATE1.
                                                                 0x2 = TMD_STATE2.
                                                                 0x3 = TMD_STATE3.
                                                                 0x4 = TMD_STATE4.
                                                                 0x5 = TMD_LOCKED. */
		uint64_t dll_lock                    : 1;  /**< RO/H - The dll_lock signal from global core-clock DLL, from the positive edge of refclk. */
		uint64_t dll_clk_invert_out          : 1;  /**< RO/H - The clk_invert setting from the global core-clock DLL, from the negative edge of refclk. */
		uint64_t dll_setting                 : 12; /**< RO/H - The global core-clock DLL setting, from the negative edge of refclk. */
#else
		uint64_t dll_setting                 : 12;
		uint64_t dll_clk_invert_out          : 1;
		uint64_t dll_lock                    : 1;
		uint64_t dll_fsm_state_a             : 3;
		uint64_t pd_pos_rclk_refclk          : 1;
		uint64_t pdl_rclk_refclk             : 1;
		uint64_t pdr_rclk_refclk             : 1;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_iobnx_gbl_dll_s         cn85xx; */
	/* struct bdk_iobnx_gbl_dll_s         cn88xx; */
} bdk_iobnx_gbl_dll_t;

static inline uint64_t BDK_IOBNX_GBL_DLL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_GBL_DLL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F000A000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_GBL_DLL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_GBL_DLL(...) bdk_iobnx_gbl_dll_t
#define bustype_BDK_IOBNX_GBL_DLL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_GBL_DLL(p1) (p1)
#define arguments_BDK_IOBNX_GBL_DLL(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_GBL_DLL(...) "IOBNX_GBL_DLL"


/**
 * RSL - iobn#_int_ena_w1c
 */
typedef union bdk_iobnx_int_ena_w1c {
	uint64_t u;
	struct bdk_iobnx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t ied0_dbe                    : 28; /**< R/W1C/H - IED0 double-bit error. When set, an IED0 double-bit error has occurred.
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
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_sbe                    : 28; /**< R/W1C/H - IED0 single-bit error. When set, an IED0 single-bit error has occurred.
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
#else
		uint64_t ied0_sbe                    : 28;
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_dbe                    : 28;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_iobnx_int_ena_w1c_s     cn85xx; */
	/* struct bdk_iobnx_int_ena_w1c_s     cn88xx; */
} bdk_iobnx_int_ena_w1c_t;

static inline uint64_t BDK_IOBNX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0008000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_INT_ENA_W1C(...) bdk_iobnx_int_ena_w1c_t
#define bustype_BDK_IOBNX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_IOBNX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_INT_ENA_W1C(...) "IOBNX_INT_ENA_W1C"


/**
 * RSL - iobn#_int_ena_w1s
 */
typedef union bdk_iobnx_int_ena_w1s {
	uint64_t u;
	struct bdk_iobnx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t ied0_dbe                    : 28; /**< R/W1C/H - IED0 double-bit error. When set, an IED0 double-bit error has occurred.
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
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_sbe                    : 28; /**< R/W1C/H - IED0 single-bit error. When set, an IED0 single-bit error has occurred.
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
#else
		uint64_t ied0_sbe                    : 28;
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_dbe                    : 28;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_iobnx_int_ena_w1s_s     cn85xx; */
	/* struct bdk_iobnx_int_ena_w1s_s     cn88xx; */
} bdk_iobnx_int_ena_w1s_t;

static inline uint64_t BDK_IOBNX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0009000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_INT_ENA_W1S(...) bdk_iobnx_int_ena_w1s_t
#define bustype_BDK_IOBNX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_IOBNX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_INT_ENA_W1S(...) "IOBNX_INT_ENA_W1S"


/**
 * RSL - iobn#_int_sum
 *
 * This register contains the different interrupt-summary bits of the IOBN.
 *
 */
typedef union bdk_iobnx_int_sum {
	uint64_t u;
	struct bdk_iobnx_int_sum_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t ied0_dbe                    : 28; /**< R/W1C/H - IED0 double-bit error. When set, an IED0 double-bit error has occurred.
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
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_sbe                    : 28; /**< R/W1C/H - IED0 single-bit error. When set, an IED0 single-bit error has occurred.
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
#else
		uint64_t ied0_sbe                    : 28;
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_dbe                    : 28;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_iobnx_int_sum_s         cn85xx; */
	/* struct bdk_iobnx_int_sum_s         cn88xx; */
} bdk_iobnx_int_sum_t;

static inline uint64_t BDK_IOBNX_INT_SUM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_SUM(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0006000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_INT_SUM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_INT_SUM(...) bdk_iobnx_int_sum_t
#define bustype_BDK_IOBNX_INT_SUM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_INT_SUM(p1) (p1)
#define arguments_BDK_IOBNX_INT_SUM(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_INT_SUM(...) "IOBNX_INT_SUM"


/**
 * RSL - iobn#_int_sum_w1s
 */
typedef union bdk_iobnx_int_sum_w1s {
	uint64_t u;
	struct bdk_iobnx_int_sum_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t ied0_dbe                    : 28; /**< R/W1C/H - IED0 double-bit error. When set, an IED0 double-bit error has occurred.
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
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_sbe                    : 28; /**< R/W1C/H - IED0 single-bit error. When set, an IED0 single-bit error has occurred.
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
#else
		uint64_t ied0_sbe                    : 28;
		uint64_t reserved_28_31              : 4;
		uint64_t ied0_dbe                    : 28;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_iobnx_int_sum_w1s_s     cn85xx; */
	/* struct bdk_iobnx_int_sum_w1s_s     cn88xx; */
} bdk_iobnx_int_sum_w1s_t;

static inline uint64_t BDK_IOBNX_INT_SUM_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_INT_SUM_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0007000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_INT_SUM_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_INT_SUM_W1S(...) bdk_iobnx_int_sum_w1s_t
#define bustype_BDK_IOBNX_INT_SUM_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_INT_SUM_W1S(p1) (p1)
#define arguments_BDK_IOBNX_INT_SUM_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_INT_SUM_W1S(...) "IOBNX_INT_SUM_W1S"


/**
 * RSL - iobn#_mctlr_reg
 *
 * Contains the sclk memory control for memories.
 *
 */
typedef union bdk_iobnx_mctlr_reg {
	uint64_t u;
	struct bdk_iobnx_mctlr_reg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t dis                         : 16; /**< R/W - Memory ECC disable. INTERNAL:
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
		uint64_t reserved_28_31              : 4;
		uint64_t flip                        : 28; /**< R/W - Memory ECC flip. INTERNAL:
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
#else
		uint64_t flip                        : 28;
		uint64_t reserved_28_31              : 4;
		uint64_t dis                         : 16;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_iobnx_mctlr_reg_s       cn85xx; */
	/* struct bdk_iobnx_mctlr_reg_s       cn88xx; */
} bdk_iobnx_mctlr_reg_t;

static inline uint64_t BDK_IOBNX_MCTLR_REG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MCTLR_REG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0005108ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_MCTLR_REG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_MCTLR_REG(...) bdk_iobnx_mctlr_reg_t
#define bustype_BDK_IOBNX_MCTLR_REG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_MCTLR_REG(p1) (p1)
#define arguments_BDK_IOBNX_MCTLR_REG(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_MCTLR_REG(...) "IOBNX_MCTLR_REG"


/**
 * RSL - iobn#_mctls_reg
 *
 * Contains the sclk memory control for memories.
 *
 */
typedef union bdk_iobnx_mctls_reg {
	uint64_t u;
	struct bdk_iobnx_mctls_reg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t dis                         : 11; /**< R/W - Memory ECC disable. INTERNAL:
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
		uint64_t reserved_26_31              : 6;
		uint64_t flip                        : 26; /**< R/W - Memory ECC flip. INTERNAL:
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
#else
		uint64_t flip                        : 26;
		uint64_t reserved_26_31              : 6;
		uint64_t dis                         : 11;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_iobnx_mctls_reg_s       cn85xx; */
	/* struct bdk_iobnx_mctls_reg_s       cn88xx; */
} bdk_iobnx_mctls_reg_t;

static inline uint64_t BDK_IOBNX_MCTLS_REG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MCTLS_REG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0005100ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_MCTLS_REG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_MCTLS_REG(...) bdk_iobnx_mctls_reg_t
#define bustype_BDK_IOBNX_MCTLS_REG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_MCTLS_REG(p1) (p1)
#define arguments_BDK_IOBNX_MCTLS_REG(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_MCTLS_REG(...) "IOBNX_MCTLS_REG"


/**
 * RSL - iobn#_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the IOBN_INT_VEC_E enumeration.
 *
 */
typedef union bdk_iobnx_msix_pbax {
	uint64_t u;
	struct bdk_iobnx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO - Pending message for the associated IOBN_MSIX_VEC()_CTL, enumerated by IOBN_INT_VEC_E.
                                                                 Bits that have no associated IOBN_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_iobnx_msix_pbax_s       cn85xx; */
	/* struct bdk_iobnx_msix_pbax_s       cn88xx; */
} bdk_iobnx_msix_pbax_t;

static inline uint64_t BDK_IOBNX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000087E0F0FF0000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_MSIX_PBAX(...) bdk_iobnx_msix_pbax_t
#define bustype_BDK_IOBNX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_IOBNX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_MSIX_PBAX(...) "IOBNX_MSIX_PBAX"


/**
 * RSL - iobn#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the IOBN_INT_VEC_E enumeration.
 *
 */
typedef union bdk_iobnx_msix_vecx_addr {
	uint64_t u;
	struct bdk_iobnx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's IOBN_MSIX_VEC()_ADDR, IOBN_MSIX_VEC()_CTL, and corresponding
                                                                 bit of IOBN_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_IOBN_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_iobnx_msix_vecx_addr_s  cn85xx; */
	/* struct bdk_iobnx_msix_vecx_addr_s  cn88xx; */
} bdk_iobnx_msix_vecx_addr_t;

static inline uint64_t BDK_IOBNX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000087E0F0F00000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_MSIX_VECX_ADDR(...) bdk_iobnx_msix_vecx_addr_t
#define bustype_BDK_IOBNX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_IOBNX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_MSIX_VECX_ADDR(...) "IOBNX_MSIX_VECX_ADDR"


/**
 * RSL - iobn#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the IOBN_INT_VEC_E enumeration.
 *
 */
typedef union bdk_iobnx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_iobnx_msix_vecx_ctl_s {
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
	/* struct bdk_iobnx_msix_vecx_ctl_s   cn85xx; */
	/* struct bdk_iobnx_msix_vecx_ctl_s   cn88xx; */
} bdk_iobnx_msix_vecx_ctl_t;

static inline uint64_t BDK_IOBNX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000087E0F0F00008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_MSIX_VECX_CTL(...) bdk_iobnx_msix_vecx_ctl_t
#define bustype_BDK_IOBNX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_IOBNX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_MSIX_VECX_CTL(...) "IOBNX_MSIX_VECX_CTL"


/**
 * RSL - iobn#_ncb#_credits
 *
 * This register controls the number of loads and stores each NCB can have to the L2.
 *
 */
typedef union bdk_iobnx_ncbx_credits {
	uint64_t u;
	struct bdk_iobnx_ncbx_credits_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_23_63              : 41;
		uint64_t ncb_wr_buf_crd              : 7;  /**< R/W - NCB write buffer credit. Each NCB can have 64 write buffers in flight to the L2; this is
                                                                 the number to decrease the 64 by. */
		uint64_t reserved_15_15              : 1;
		uint64_t ncb0_wr_crd                 : 7;  /**< R/W - NCB write credit. Each NCB can have 64 writes in flight to the L2; this is the number to
                                                                 decrease the 64 by. */
		uint64_t reserved_7_7                : 1;
		uint64_t ncb0_rd_crd                 : 7;  /**< R/W - NCB read credit. Each NCB can have 64 reads in flight to the L2; this is the number to
                                                                 decrease the 64 by. */
#else
		uint64_t ncb0_rd_crd                 : 7;
		uint64_t reserved_7_7                : 1;
		uint64_t ncb0_wr_crd                 : 7;
		uint64_t reserved_15_15              : 1;
		uint64_t ncb_wr_buf_crd              : 7;
		uint64_t reserved_23_63              : 41;
#endif
	} s;
	/* struct bdk_iobnx_ncbx_credits_s    cn85xx; */
	/* struct bdk_iobnx_ncbx_credits_s    cn88xx; */
} bdk_iobnx_ncbx_credits_t;

static inline uint64_t BDK_IOBNX_NCBX_CREDITS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCBX_CREDITS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0F0001000ull + (param1 & 1) * 0x1000000ull + (param2 & 1) * 0x100ull;
	csr_fatal("BDK_IOBNX_NCBX_CREDITS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_NCBX_CREDITS(...) bdk_iobnx_ncbx_credits_t
#define bustype_BDK_IOBNX_NCBX_CREDITS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_NCBX_CREDITS(p1,p2) (p1)
#define arguments_BDK_IOBNX_NCBX_CREDITS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_NCBX_CREDITS(...) "IOBNX_NCBX_CREDITS"


/**
 * RSL - iobn#_ncb#_ctl
 *
 * This register controls the number of loads and stores each NCB can have to the L2.
 *
 */
typedef union bdk_iobnx_ncbx_ctl {
	uint64_t u;
	struct bdk_iobnx_ncbx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t stp                         : 2;  /**< R/W - When a complete cache block is written a STP will be converted to:
                                                                 0 = STF.
                                                                 1 = STY.
                                                                 2 = STT.
                                                                 3 = Reserved. */
		uint64_t reserved_2_7                : 6;
		uint64_t rstp                        : 2;  /**< R/W - When a complete cache block is written a RSTP will be converted to:
                                                                 0 = STY.
                                                                 1 = STT.
                                                                 2 = STF.
                                                                 3 = Reserved. */
#else
		uint64_t rstp                        : 2;
		uint64_t reserved_2_7                : 6;
		uint64_t stp                         : 2;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_iobnx_ncbx_ctl_s        cn85xx; */
	/* struct bdk_iobnx_ncbx_ctl_s        cn88xx; */
} bdk_iobnx_ncbx_ctl_t;

static inline uint64_t BDK_IOBNX_NCBX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCBX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E0F0004000ull + (param1 & 1) * 0x1000000ull + (param2 & 1) * 0x100ull;
	csr_fatal("BDK_IOBNX_NCBX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_NCBX_CTL(...) bdk_iobnx_ncbx_ctl_t
#define bustype_BDK_IOBNX_NCBX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_NCBX_CTL(p1,p2) (p1)
#define arguments_BDK_IOBNX_NCBX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_NCBX_CTL(...) "IOBNX_NCBX_CTL"


/**
 * RSL - iobn#_ncb0_hp
 */
typedef union bdk_iobnx_ncb0_hp {
	uint64_t u;
	struct bdk_iobnx_ncb0_hp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t hp                          : 1;  /**< R/W - When set, NCBI 0 ARB 0 will use the high performance path through the IOBN. */
#else
		uint64_t hp                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_iobnx_ncb0_hp_s         cn85xx; */
	/* struct bdk_iobnx_ncb0_hp_s         cn88xx; */
} bdk_iobnx_ncb0_hp_t;

static inline uint64_t BDK_IOBNX_NCB0_HP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCB0_HP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0003008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_NCB0_HP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_NCB0_HP(...) bdk_iobnx_ncb0_hp_t
#define bustype_BDK_IOBNX_NCB0_HP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_NCB0_HP(p1) (p1)
#define arguments_BDK_IOBNX_NCB0_HP(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_NCB0_HP(...) "IOBNX_NCB0_HP"


/**
 * RSL - iobn#_ncb0_sdis#
 *
 * SDIS(3) = DIDs 255:192, SDIS(2) = DIDs 191:128, SDIS(1) = DIDs 127:64, SDIS(0) = DIDs 63:0.
 *
 */
typedef union bdk_iobnx_ncb0_sdisx {
	uint64_t u;
	struct bdk_iobnx_ncb0_sdisx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t did                         : 64; /**< SR/W - When set a secure operation is required to access the NCBDID. If a non-secure operation
                                                                 occurs it will result in a R/W to ECAM0_NOP_ZF. */
#else
		uint64_t did                         : 64;
#endif
	} s;
	/* struct bdk_iobnx_ncb0_sdisx_s      cn85xx; */
	/* struct bdk_iobnx_ncb0_sdisx_s      cn88xx; */
} bdk_iobnx_ncb0_sdisx_t;

static inline uint64_t BDK_IOBNX_NCB0_SDISX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_NCB0_SDISX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0F0002000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100ull;
	csr_fatal("BDK_IOBNX_NCB0_SDISX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_NCB0_SDISX(...) bdk_iobnx_ncb0_sdisx_t
#define bustype_BDK_IOBNX_NCB0_SDISX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_NCB0_SDISX(p1,p2) (p1)
#define arguments_BDK_IOBNX_NCB0_SDISX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_NCB0_SDISX(...) "IOBNX_NCB0_SDISX"


/**
 * RSL - iobn#_roc_dll
 *
 * Status of the ROC core-clock DLL.
 *
 */
typedef union bdk_iobnx_roc_dll {
	uint64_t u;
	struct bdk_iobnx_roc_dll_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t pdr_rclk_refclk             : 1;  /**< RO/H - Synchronized pdr_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
		uint64_t pdl_rclk_refclk             : 1;  /**< RO/H - Synchronized pdl_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
		uint64_t pd_pos_rclk_refclk          : 1;  /**< RO/H - Synchronized pd_pos_rclk_refclk from ROC core-clock DLL cmb0 phase detectors. */
		uint64_t dll_lock                    : 1;  /**< RO/H - The dll_lock signal from ROC core-clock DLL, from the positive edge of refclk. */
		uint64_t dll_dly_elem_en             : 16; /**< RO/H - The ROC core-clock delay element enable setting, from the negative edge of refclk. */
		uint64_t dll_setting                 : 12; /**< RO/H - The ROC core-clock DLL setting, from the negative edge of refclk. */
#else
		uint64_t dll_setting                 : 12;
		uint64_t dll_dly_elem_en             : 16;
		uint64_t dll_lock                    : 1;
		uint64_t pd_pos_rclk_refclk          : 1;
		uint64_t pdl_rclk_refclk             : 1;
		uint64_t pdr_rclk_refclk             : 1;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_iobnx_roc_dll_s         cn85xx; */
	/* struct bdk_iobnx_roc_dll_s         cn88xx; */
} bdk_iobnx_roc_dll_t;

static inline uint64_t BDK_IOBNX_ROC_DLL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_ROC_DLL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F000A008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_ROC_DLL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_ROC_DLL(...) bdk_iobnx_roc_dll_t
#define bustype_BDK_IOBNX_ROC_DLL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_ROC_DLL(p1) (p1)
#define arguments_BDK_IOBNX_ROC_DLL(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_ROC_DLL(...) "IOBNX_ROC_DLL"


/**
 * RSL - iobn#_scratch
 */
typedef union bdk_iobnx_scratch {
	uint64_t u;
	struct bdk_iobnx_scratch_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W - Test register for CSR access. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_iobnx_scratch_s         cn85xx; */
	/* struct bdk_iobnx_scratch_s         cn88xx; */
} bdk_iobnx_scratch_t;

static inline uint64_t BDK_IOBNX_SCRATCH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_SCRATCH(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0003020ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_SCRATCH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_SCRATCH(...) bdk_iobnx_scratch_t
#define bustype_BDK_IOBNX_SCRATCH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_SCRATCH(p1) (p1)
#define arguments_BDK_IOBNX_SCRATCH(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_SCRATCH(...) "IOBNX_SCRATCH"


/**
 * RSL - iobn#_slitag#_control
 *
 * This register contains various control bits for IOBN functionality.
 *
 */
typedef union bdk_iobnx_slitagx_control {
	uint64_t u;
	struct bdk_iobnx_slitagx_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t ld_ld_ord                   : 1;  /**< R/W - Enforce load-following-load ordering for SLI operations. A load operation must
                                                                 wait for all previous load operations' FILLs before issuing. */
		uint64_t ld_st_ord                   : 1;  /**< R/W - Enforce load-following-store ordering for SLI operations. A load operation must
                                                                 wait for all previous store operations' STDNs before issuing. */
		uint64_t st_ld_ord                   : 1;  /**< R/W - Enforce store-following-load ordering for SLI operations. A store operation must
                                                                 wait for all previous load operations' FILLs before issuing. */
		uint64_t st_st_ord                   : 1;  /**< R/W - Enforce store-following-store ordering for SLI operations. A store operation must
                                                                 wait for all previous store operations' STDNs before issuing. */
#else
		uint64_t st_st_ord                   : 1;
		uint64_t st_ld_ord                   : 1;
		uint64_t ld_st_ord                   : 1;
		uint64_t ld_ld_ord                   : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_iobnx_slitagx_control_s cn85xx; */
	/* struct bdk_iobnx_slitagx_control_s cn88xx; */
} bdk_iobnx_slitagx_control_t;

static inline uint64_t BDK_IOBNX_SLITAGX_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_SLITAGX_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 2)))
		return 0x000087E0F0000000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100ull;
	csr_fatal("BDK_IOBNX_SLITAGX_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_SLITAGX_CONTROL(...) bdk_iobnx_slitagx_control_t
#define bustype_BDK_IOBNX_SLITAGX_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_SLITAGX_CONTROL(p1,p2) (p1)
#define arguments_BDK_IOBNX_SLITAGX_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_IOBNX_SLITAGX_CONTROL(...) "IOBNX_SLITAGX_CONTROL"


/**
 * RSL - iobn#_test
 */
typedef union bdk_iobnx_test {
	uint64_t u;
	struct bdk_iobnx_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t gibarb_testmode             : 1;  /**< R/W - When set, the IOBN GIB arbiters will only grant one requestor at a time. */
#else
		uint64_t gibarb_testmode             : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_iobnx_test_s            cn85xx; */
	/* struct bdk_iobnx_test_s            cn88xx; */
} bdk_iobnx_test_t;

static inline uint64_t BDK_IOBNX_TEST(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_IOBNX_TEST(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0F0003010ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_IOBNX_TEST", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_IOBNX_TEST(...) bdk_iobnx_test_t
#define bustype_BDK_IOBNX_TEST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_IOBNX_TEST(p1) (p1)
#define arguments_BDK_IOBNX_TEST(p1) (p1),-1,-1,-1
#define basename_BDK_IOBNX_TEST(...) "IOBNX_TEST"

#endif /* __BDK_CSRS_IOBN__ */
