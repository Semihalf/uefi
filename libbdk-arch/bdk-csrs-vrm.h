#ifndef __BDK_CSRS_VRM__
#define __BDK_CSRS_VRM__
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
 * Cavium VRM.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration VRM_TYPE_E
 *
 * VRM Types Register Enumeration
 * Indicates type of device connected to this controller, as loaded into
 * VRM()_MISC_INFO[VRM_TYPE] and VRM()_MISC_INFO[VRM_TYPE2].
 */
enum vrm_type_e {
	VRM_TYPE_E_ISL6367 = 0x1,
	VRM_TYPE_E_PMB_LIN = 0x0,
	VRM_TYPE_E_PMB_VID = 0x2,
	VRM_TYPE_E_PMB_VID_TPS53641 = 0x4,
	VRM_TYPE_E_ENUM_LAST = 0x5,
};


/**
 * Structure VRM_TWS_TWSI_SW_S
 *
 * VRM TWSI Software Write Structure
 * Format for software to write data to external regulator.
 */
union vrm_tws_twsi_sw_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12; /**< [ 63: 52] Reserved */
		uint64_t v                           : 1;  /**< [ 51: 51] Valid. */
		uint64_t r                           : 1;  /**< [ 50: 50] Read. */
		uint64_t size                        : 2;  /**< [ 49: 48] Size of payload. */
		uint64_t addr                        : 8;  /**< [ 47: 40] Slave address. External regulator ID. */
		uint64_t ia                          : 8;  /**< [ 39: 32] Internal CSR address of registers within external regulator. */
		uint64_t data                        : 32; /**< [ 31:  0] Data to/from external regulator, includes PEC. */
#else
		uint64_t data                        : 32; /**< [ 31:  0] Data to/from external regulator, includes PEC. */
		uint64_t ia                          : 8;  /**< [ 39: 32] Internal CSR address of registers within external regulator. */
		uint64_t addr                        : 8;  /**< [ 47: 40] Slave address. External regulator ID. */
		uint64_t size                        : 2;  /**< [ 49: 48] Size of payload. */
		uint64_t r                           : 1;  /**< [ 50: 50] Read. */
		uint64_t v                           : 1;  /**< [ 51: 51] Valid. */
		uint64_t reserved_52_63              : 12; /**< [ 63: 52] Reserved */
#endif
	} s;
};


/**
 * RSL - vrm#_alt_fuse
 */
typedef union bdk_vrmx_alt_fuse {
	uint64_t u;
	struct bdk_vrmx_alt_fuse_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t tran_temp                   : 8;  /**< R/W - Transition temperature for V calculation. */
		uint64_t max_step                    : 8;  /**< R/W - V step. */
		uint64_t slope                       : 8;  /**< R/W - Slope. */
		uint64_t v_base                      : 8;  /**< R/W - Base voltage. Minimum voltage that gets written to voltage regulator. */
		uint64_t v_max                       : 8;  /**< R/W - Max voltage. Maximum voltage that gets written to voltage regulator. */
#else
		uint64_t v_max                       : 8;
		uint64_t v_base                      : 8;
		uint64_t slope                       : 8;
		uint64_t max_step                    : 8;
		uint64_t tran_temp                   : 8;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_vrmx_alt_fuse_s         cn88xx; */
	/* struct bdk_vrmx_alt_fuse_s         cn88xxp1; */
} bdk_vrmx_alt_fuse_t;

static inline uint64_t BDK_VRMX_ALT_FUSE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_ALT_FUSE(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000018ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_ALT_FUSE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_ALT_FUSE(...) bdk_vrmx_alt_fuse_t
#define bustype_BDK_VRMX_ALT_FUSE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_ALT_FUSE(p1) (p1)
#define arguments_BDK_VRMX_ALT_FUSE(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_ALT_FUSE(...) "VRMX_ALT_FUSE"


/**
 * RSL - vrm#_device_status
 */
typedef union bdk_vrmx_device_status {
	uint64_t u;
	struct bdk_vrmx_device_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t remove_idle                 : 1;  /**< R/W - When set, will remove IDLE as described below.
                                                                 Software should not set this bit, unless the reason for PEC mismatch is known. */
		uint64_t status_idle                 : 1;  /**< RO/H - If set, faulty external controller operation was detected, for example in the ISL636*.
                                                                 Sixteen attempts were made to communicate with device that came back with PEC faults.
                                                                 See STATUS_CML in the PMbus documentation. */
		uint64_t status_byte                 : 8;  /**< RO/H - Reads STATUS_BYTE register. See PMBus documentation. */
		uint64_t status_cml                  : 8;  /**< RO/H - Reads STATUS_CML register. See PMBus documentation. */
#else
		uint64_t status_cml                  : 8;
		uint64_t status_byte                 : 8;
		uint64_t status_idle                 : 1;
		uint64_t remove_idle                 : 1;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_vrmx_device_status_s    cn88xx; */
	/* struct bdk_vrmx_device_status_s    cn88xxp1; */
} bdk_vrmx_device_status_t;

static inline uint64_t BDK_VRMX_DEVICE_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_DEVICE_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0210000A8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_DEVICE_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_DEVICE_STATUS(...) bdk_vrmx_device_status_t
#define bustype_BDK_VRMX_DEVICE_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_DEVICE_STATUS(p1) (p1)
#define arguments_BDK_VRMX_DEVICE_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_DEVICE_STATUS(...) "VRMX_DEVICE_STATUS"


/**
 * RSL - vrm#_fuse_bypass
 */
typedef union bdk_vrmx_fuse_bypass {
	uint64_t u;
	struct bdk_vrmx_fuse_bypass_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t ctl_hw_bypass               : 1;  /**< R/W - If set, bypass VRM control hardware responsible for controlling external voltage
                                                                 regulator so software can send commands to the regulator. */
		uint64_t ctl_fuse_bypass             : 1;  /**< R/W - If set, bypass V_MAX, V_BASE, MAX_STEP, SLOPE, TRAN_TEMP fuses which feed the PMBus VRM controller. */
		uint64_t ts_fuse_bypass              : 1;  /**< R/W - If set, bypass MC and NOFF fuses which feed the temperature sensor. */
#else
		uint64_t ts_fuse_bypass              : 1;
		uint64_t ctl_fuse_bypass             : 1;
		uint64_t ctl_hw_bypass               : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_vrmx_fuse_bypass_s      cn88xx; */
	/* struct bdk_vrmx_fuse_bypass_s      cn88xxp1; */
} bdk_vrmx_fuse_bypass_t;

static inline uint64_t BDK_VRMX_FUSE_BYPASS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_FUSE_BYPASS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000098ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_FUSE_BYPASS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_FUSE_BYPASS(...) bdk_vrmx_fuse_bypass_t
#define bustype_BDK_VRMX_FUSE_BYPASS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_FUSE_BYPASS(p1) (p1)
#define arguments_BDK_VRMX_FUSE_BYPASS(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_FUSE_BYPASS(...) "VRMX_FUSE_BYPASS"


/**
 * RSL - vrm#_misc_info
 */
typedef union bdk_vrmx_misc_info {
	uint64_t u;
	struct bdk_vrmx_misc_info_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t vrm_type2                   : 3;  /**< RO/H - Bits \<4..2\> of VRM type, enumerated by VRM_TYPE_E. */
		uint64_t vrm_ctl_rcv_status_error    : 24; /**< RO/H - Holds the received status read from the external controller only for failing status. */
		uint64_t vrm_ctl_cur_state           : 3;  /**< RO/H - Current state of the VRM_CTL. */
		uint64_t vrm_type                    : 2;  /**< RO/H - Bits \<1:0\> of VRM type indicating the type of device connected to this controller.
                                                                 Enumerated by VRM_TYPE_E. */
		uint64_t boot_seq                    : 1;  /**< RO/H - Boot sequence was completed. */
		uint64_t ts_fuse_sts                 : 1;  /**< RO/H - Set if VRM fuses were loaded. */
		uint64_t vrm_fuse_sts                : 1;  /**< RO/H - Set if VRM fuses were loaded. */
		uint64_t cmnd                        : 8;  /**< RO/H - Last command send to the external voltage regulator. */
#else
		uint64_t cmnd                        : 8;
		uint64_t vrm_fuse_sts                : 1;
		uint64_t ts_fuse_sts                 : 1;
		uint64_t boot_seq                    : 1;
		uint64_t vrm_type                    : 2;
		uint64_t vrm_ctl_cur_state           : 3;
		uint64_t vrm_ctl_rcv_status_error    : 24;
		uint64_t vrm_type2                   : 3;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_vrmx_misc_info_s        cn88xx; */
	/* struct bdk_vrmx_misc_info_s        cn88xxp1; */
} bdk_vrmx_misc_info_t;

static inline uint64_t BDK_VRMX_MISC_INFO(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_MISC_INFO(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000048ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_MISC_INFO", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_MISC_INFO(...) bdk_vrmx_misc_info_t
#define bustype_BDK_VRMX_MISC_INFO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_MISC_INFO(p1) (p1)
#define arguments_BDK_VRMX_MISC_INFO(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_MISC_INFO(...) "VRMX_MISC_INFO"


/**
 * RSL - vrm#_telemetry_cmnd
 */
typedef union bdk_vrmx_telemetry_cmnd {
	uint64_t u;
	struct bdk_vrmx_telemetry_cmnd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t cmnd                        : 2;  /**< R/W/H - This command will initiate a read instruction to the external voltage regulator
                                                                 into VRM_TELEMETRY_READ.
                                                                 0x0 = Do nothing.
                                                                 0x1 = Read V.
                                                                 0x2 = Read I.
                                                                 0x3 = Read V.

                                                                 Hardware clears CMND to indicate operation completed. */
#else
		uint64_t cmnd                        : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_vrmx_telemetry_cmnd_s   cn88xx; */
	/* struct bdk_vrmx_telemetry_cmnd_s   cn88xxp1; */
} bdk_vrmx_telemetry_cmnd_t;

static inline uint64_t BDK_VRMX_TELEMETRY_CMND(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TELEMETRY_CMND(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000038ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TELEMETRY_CMND", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TELEMETRY_CMND(...) bdk_vrmx_telemetry_cmnd_t
#define bustype_BDK_VRMX_TELEMETRY_CMND(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TELEMETRY_CMND(p1) (p1)
#define arguments_BDK_VRMX_TELEMETRY_CMND(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TELEMETRY_CMND(...) "VRMX_TELEMETRY_CMND"


/**
 * RSL - vrm#_telemetry_read
 */
typedef union bdk_vrmx_telemetry_read {
	uint64_t u;
	struct bdk_vrmx_telemetry_read_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t iout                        : 16; /**< RO - Current reading from external regulator. */
		uint64_t vout                        : 16; /**< RO - Voltage reading from external regulator. */
#else
		uint64_t vout                        : 16;
		uint64_t iout                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_vrmx_telemetry_read_s   cn88xx; */
	/* struct bdk_vrmx_telemetry_read_s   cn88xxp1; */
} bdk_vrmx_telemetry_read_t;

static inline uint64_t BDK_VRMX_TELEMETRY_READ(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TELEMETRY_READ(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000028ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TELEMETRY_READ", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TELEMETRY_READ(...) bdk_vrmx_telemetry_read_t
#define bustype_BDK_VRMX_TELEMETRY_READ(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TELEMETRY_READ(p1) (p1)
#define arguments_BDK_VRMX_TELEMETRY_READ(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TELEMETRY_READ(...) "VRMX_TELEMETRY_READ"


/**
 * RSL - vrm#_trip
 */
typedef union bdk_vrmx_trip {
	uint64_t u;
	struct bdk_vrmx_trip_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t trip_level                  : 8;  /**< R/W - If temperature sensed is greater than this value RST_THERMAL_ALERT[TRIP] is set,
                                                                 and the THERMAL_TRIP_L pin asserts. */
#else
		uint64_t trip_level                  : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_vrmx_trip_s             cn88xx; */
	/* struct bdk_vrmx_trip_s             cn88xxp1; */
} bdk_vrmx_trip_t;

static inline uint64_t BDK_VRMX_TRIP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TRIP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0210000B8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TRIP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TRIP(...) bdk_vrmx_trip_t
#define bustype_BDK_VRMX_TRIP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TRIP(p1) (p1)
#define arguments_BDK_VRMX_TRIP(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TRIP(...) "VRMX_TRIP"


/**
 * RSL - vrm#_ts_temp_conv_coeff_fsm
 */
typedef union bdk_vrmx_ts_temp_conv_coeff_fsm {
	uint64_t u;
	struct bdk_vrmx_ts_temp_conv_coeff_fsm_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_58_63              : 6;
		uint64_t t_fsm                       : 10; /**< R/W - Sets time interval for FSM update. */
		uint64_t reserved_38_47              : 10;
		uint64_t coeff_a                     : 6;  /**< R/W - Coefficient A value for polynomial fit.
                                                                 _ \<37\> is a sign bit to flip the shifted results.
                                                                 _ \<36:32\> dictates the amount of right shift. */
		uint64_t reserved_25_31              : 7;
		uint64_t coeff_b                     : 9;  /**< R/W - Coefficient B value for polynomial fit. It should be a positive number and between 1 and
                                                                 2.
                                                                 _ \<24\> is the integer part should always be 1.
                                                                 _ \<23:16\> form the fractional part. */
		uint64_t reserved_12_15              : 4;
		uint64_t coeff_c                     : 12; /**< R/W - Coefficient C value for polynomial fit.
                                                                 A 2's complement number. */
#else
		uint64_t coeff_c                     : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t coeff_b                     : 9;
		uint64_t reserved_25_31              : 7;
		uint64_t coeff_a                     : 6;
		uint64_t reserved_38_47              : 10;
		uint64_t t_fsm                       : 10;
		uint64_t reserved_58_63              : 6;
#endif
	} s;
	/* struct bdk_vrmx_ts_temp_conv_coeff_fsm_s cn88xx; */
	/* struct bdk_vrmx_ts_temp_conv_coeff_fsm_s cn88xxp1; */
} bdk_vrmx_ts_temp_conv_coeff_fsm_t;

static inline uint64_t BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000078ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TS_TEMP_CONV_COEFF_FSM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(...) bdk_vrmx_ts_temp_conv_coeff_fsm_t
#define bustype_BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(p1) (p1)
#define arguments_BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TS_TEMP_CONV_COEFF_FSM(...) "VRMX_TS_TEMP_CONV_COEFF_FSM"


/**
 * RSL - vrm#_ts_temp_conv_ctl
 */
typedef union bdk_vrmx_ts_temp_conv_ctl {
	uint64_t u;
	struct bdk_vrmx_ts_temp_conv_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t reset_sm                    : 1;  /**< R/W - This will force the temperature conversion state machine into the reset state until
                                                                 RESET_SM is cleared. */
		uint64_t sw_access                   : 1;  /**< R/W - If set, software controls inputs of analog temperature sensor. */
		uint64_t ts_switch                   : 9;  /**< R/W - Alternate software access to control temperature sensor switches. */
		uint64_t ts_curr2en                  : 1;  /**< R/W - Controls curr2_en pin on analog temperature sensor block. */
		uint64_t strobe                      : 1;  /**< R/W - Controls strobe pin on analog temperature sensor block. */
#else
		uint64_t strobe                      : 1;
		uint64_t ts_curr2en                  : 1;
		uint64_t ts_switch                   : 9;
		uint64_t sw_access                   : 1;
		uint64_t reset_sm                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_vrmx_ts_temp_conv_ctl_s cn88xx; */
	/* struct bdk_vrmx_ts_temp_conv_ctl_s cn88xxp1; */
} bdk_vrmx_ts_temp_conv_ctl_t;

static inline uint64_t BDK_VRMX_TS_TEMP_CONV_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TS_TEMP_CONV_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000058ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TS_TEMP_CONV_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TS_TEMP_CONV_CTL(...) bdk_vrmx_ts_temp_conv_ctl_t
#define bustype_BDK_VRMX_TS_TEMP_CONV_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TS_TEMP_CONV_CTL(p1) (p1)
#define arguments_BDK_VRMX_TS_TEMP_CONV_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TS_TEMP_CONV_CTL(...) "VRMX_TS_TEMP_CONV_CTL"


/**
 * RSL - vrm#_ts_temp_conv_result
 */
typedef union bdk_vrmx_ts_temp_conv_result {
	uint64_t u;
	struct bdk_vrmx_ts_temp_conv_result_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t n_valid                     : 1;  /**< RO/H - When set N_VALUE is valid. */
		uint64_t n_value                     : 11; /**< RO/H - N cycle count values after calibration initiated. Qualified by N_VALID. */
		uint64_t temp_valid                  : 1;  /**< RO/H - When set TEMP_CORRECTED is valid.
                                                                 This bit is pulsed on each conversion, and as such software may not be able to observe the
                                                                 cycle in which TEMP_VALID is set. */
		uint64_t temp_corrected              : 11; /**< RO/H - Corrected temperature read out from the temp sensor module, in degrees C with
                                                                 two bits of fraction. Unpredictable unless TEMP_VALID is set. */
#else
		uint64_t temp_corrected              : 11;
		uint64_t temp_valid                  : 1;
		uint64_t n_value                     : 11;
		uint64_t n_valid                     : 1;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_vrmx_ts_temp_conv_result_s cn88xx; */
	/* struct bdk_vrmx_ts_temp_conv_result_s cn88xxp1; */
} bdk_vrmx_ts_temp_conv_result_t;

static inline uint64_t BDK_VRMX_TS_TEMP_CONV_RESULT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TS_TEMP_CONV_RESULT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000068ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TS_TEMP_CONV_RESULT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TS_TEMP_CONV_RESULT(...) bdk_vrmx_ts_temp_conv_result_t
#define bustype_BDK_VRMX_TS_TEMP_CONV_RESULT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TS_TEMP_CONV_RESULT(p1) (p1)
#define arguments_BDK_VRMX_TS_TEMP_CONV_RESULT(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TS_TEMP_CONV_RESULT(...) "VRMX_TS_TEMP_CONV_RESULT"


/**
 * RSL - vrm#_ts_temp_noff_mc
 */
typedef union bdk_vrmx_ts_temp_noff_mc {
	uint64_t u;
	struct bdk_vrmx_ts_temp_noff_mc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_28_63              : 36;
		uint64_t mc                          : 12; /**< R/W - MC value, default is 3000 decimal. */
		uint64_t reserved_11_15              : 5;
		uint64_t noff                        : 11; /**< R/W - N cycle count offset, used to subtract the appropriate count from N cycle.
                                                                 It should be such that at 0 degrees C, the difference between NOFF and NCYCLE is 0. */
#else
		uint64_t noff                        : 11;
		uint64_t reserved_11_15              : 5;
		uint64_t mc                          : 12;
		uint64_t reserved_28_63              : 36;
#endif
	} s;
	/* struct bdk_vrmx_ts_temp_noff_mc_s  cn88xx; */
	/* struct bdk_vrmx_ts_temp_noff_mc_s  cn88xxp1; */
} bdk_vrmx_ts_temp_noff_mc_t;

static inline uint64_t BDK_VRMX_TS_TEMP_NOFF_MC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TS_TEMP_NOFF_MC(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000088ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TS_TEMP_NOFF_MC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TS_TEMP_NOFF_MC(...) bdk_vrmx_ts_temp_noff_mc_t
#define bustype_BDK_VRMX_TS_TEMP_NOFF_MC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TS_TEMP_NOFF_MC(p1) (p1)
#define arguments_BDK_VRMX_TS_TEMP_NOFF_MC(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TS_TEMP_NOFF_MC(...) "VRMX_TS_TEMP_NOFF_MC"


/**
 * RSL - vrm#_tws_twsi_sw
 *
 * This register allows software to write data into I2C controller directly.
 * This register is for diagnostic use only.
 */
typedef union bdk_vrmx_tws_twsi_sw {
	uint64_t u;
	struct bdk_vrmx_tws_twsi_sw_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t v                           : 1;  /**< RC/W/H - Valid bit.
                                                                 Set on a write operation (should always be written with a 1).
                                                                 Cleared when a TWSI master-mode operation completes.
                                                                 Cleared when a TWSI configuration register access completes.
                                                                 Cleared when the TWSI device reads the register if SLONLY = 1. */
		uint64_t sl_only                     : 1;  /**< RO - Reserved. */
		uint64_t eia                         : 1;  /**< RO - Reserved. */
		uint64_t op                          : 4;  /**< RO - Reserved. */
		uint64_t r                           : 1;  /**< R/W/H - Read bit or result. If this bit is set on a CSR write when SLONLY = 0, the operation is a
                                                                 read operation (if clear, it is a write operation).
                                                                 On a CSR read, this bit returns the result indication for the most recent master-mode
                                                                 operation, 1 = success, 0 = failure. */
		uint64_t sovr                        : 1;  /**< RO - Reserved. */
		uint64_t size_b3                     : 1;  /**< RO - Reserved. */
		uint64_t size                        : 2;  /**< R/W/H - Size minus one. Specifies the size in bytes of the master-mode operation.
                                                                 (0 = 1 byte, 1 = 2 bytes, 3 = 4 bytes). */
		uint64_t scr                         : 2;  /**< RO - Reserved. */
		uint64_t un_addr                     : 3;  /**< RO - Reserved. */
		uint64_t addr                        : 7;  /**< R/W/H - Address field. The address of the remote device for a master-mode operation.
                                                                 Note that when mastering a 7-bit OP, ADDR\<6:0\> should not take any of the values 0x78,
                                                                 0x79, 0x7A nor 0x7B, as these 7-bit addresses are reserved to extend to 10-bit addressing. */
		uint64_t ia                          : 8;  /**< R/W/H - Internal address. Used when launching a combined master-mode operation. */
		uint64_t data                        : 32; /**< R/W/H - Data field.
                                                                 Used on a write operation when initiating a master-mode write operation (SLONLY = 0),
                                                                 or writing a TWSI configuration register (SLONLY = 0).
                                                                 The read value is updated by:

                                                                 * A write operation to this register.

                                                                 * Master-mode completion (contains error code).

                                                                 * TWSI configuration-register read (contains result). */
#else
		uint64_t data                        : 32;
		uint64_t ia                          : 8;
		uint64_t addr                        : 7;
		uint64_t un_addr                     : 3;
		uint64_t scr                         : 2;
		uint64_t size                        : 2;
		uint64_t size_b3                     : 1;
		uint64_t sovr                        : 1;
		uint64_t r                           : 1;
		uint64_t op                          : 4;
		uint64_t eia                         : 1;
		uint64_t sl_only                     : 1;
		uint64_t v                           : 1;
#endif
	} s;
	/* struct bdk_vrmx_tws_twsi_sw_s      cn88xx; */
	/* struct bdk_vrmx_tws_twsi_sw_s      cn88xxp1; */
} bdk_vrmx_tws_twsi_sw_t;

static inline uint64_t BDK_VRMX_TWS_TWSI_SW(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_VRMX_TWS_TWSI_SW(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E021000008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_VRMX_TWS_TWSI_SW", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_VRMX_TWS_TWSI_SW(...) bdk_vrmx_tws_twsi_sw_t
#define bustype_BDK_VRMX_TWS_TWSI_SW(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_VRMX_TWS_TWSI_SW(p1) (p1)
#define arguments_BDK_VRMX_TWS_TWSI_SW(p1) (p1),-1,-1,-1
#define basename_BDK_VRMX_TWS_TWSI_SW(...) "VRMX_TWS_TWSI_SW"

#endif /* __BDK_CSRS_VRM__ */
