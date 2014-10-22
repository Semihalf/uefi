#ifndef __BDK_CSRS_NCSI__
#define __BDK_CSRS_NCSI__
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
 * Cavium NCSI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration NCSI_CTL_PKT_TYPE_E
 *
 * NCSI Control Packet Type Enumeration
 * Enumerates the control packet types. For more information see the NC-SI standard.
 */
enum ncsi_ctl_pkt_type_e {
	NCSI_CTL_PKT_TYPE_E_AEN_EN = 0x8,
	NCSI_CTL_PKT_TYPE_E_CLR_INIT = 0x0,
	NCSI_CTL_PKT_TYPE_E_DIS_BCST = 0x11,
	NCSI_CTL_PKT_TYPE_E_DIS_CHAN = 0x4,
	NCSI_CTL_PKT_TYPE_E_DIS_CHAN_NW = 0x7,
	NCSI_CTL_PKT_TYPE_E_DIS_MCST = 0x13,
	NCSI_CTL_PKT_TYPE_E_DIS_VLAN = 0xd,
	NCSI_CTL_PKT_TYPE_E_DSEL_PKG = 0x2,
	NCSI_CTL_PKT_TYPE_E_EN_BCST = 0x10,
	NCSI_CTL_PKT_TYPE_E_EN_CHAN = 0x3,
	NCSI_CTL_PKT_TYPE_E_EN_CHAN_NW = 0x6,
	NCSI_CTL_PKT_TYPE_E_EN_MCST = 0x12,
	NCSI_CTL_PKT_TYPE_E_EN_VLAN = 0xc,
	NCSI_CTL_PKT_TYPE_E_GET_CAP = 0x16,
	NCSI_CTL_PKT_TYPE_E_GET_ID = 0x15,
	NCSI_CTL_PKT_TYPE_E_GET_LINK = 0xa,
	NCSI_CTL_PKT_TYPE_E_GET_NCSI_STAT = 0x19,
	NCSI_CTL_PKT_TYPE_E_GET_PAR = 0x17,
	NCSI_CTL_PKT_TYPE_E_GET_PASS_STAT = 0x1a,
	NCSI_CTL_PKT_TYPE_E_GET_PKT_STAT = 0x18,
	NCSI_CTL_PKT_TYPE_E_OEM = 0x50,
	NCSI_CTL_PKT_TYPE_E_RST_CHAN = 0x5,
	NCSI_CTL_PKT_TYPE_E_SEL_PKG = 0x1,
	NCSI_CTL_PKT_TYPE_E_SET_FLOW = 0x14,
	NCSI_CTL_PKT_TYPE_E_SET_LINK = 0x9,
	NCSI_CTL_PKT_TYPE_E_SET_MAC = 0xe,
	NCSI_CTL_PKT_TYPE_E_SET_VLAN = 0xb,
	NCSI_CTL_PKT_TYPE_E_ENUM_LAST = 0x51,
};

/**
 * Enumeration NCSI_INT_VEC_E
 *
 * NCSI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum ncsi_int_vec_e {
	NCSI_INT_VEC_E_INTS = 0x0,
	NCSI_INT_VEC_E_ENUM_LAST = 0x1,
};

/**
 * Enumeration NCSI_REASON_E
 *
 * NCSI Reason Code Enumeration
 * Enumerates the NCSI standard reason codes.
 */
enum ncsi_reason_e {
	NCSI_REASON_E_CHAN = 0x3,
	NCSI_REASON_E_INIT = 0x1,
	NCSI_REASON_E_NONE = 0x0,
	NCSI_REASON_E_UNSUP = 0x2,
	NCSI_REASON_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration NCSI_RESP_E
 *
 * NCSI Response Code Enumeration
 *
 */
enum ncsi_resp_e {
	NCSI_RESP_E_COMPLETED = 0x0,
	NCSI_RESP_E_CSR_READ = 0x8000,
	NCSI_RESP_E_CSR_WRITE = 0x8001,
	NCSI_RESP_E_FAILED = 0x1,
	NCSI_RESP_E_UNAVAIL = 0x2,
	NCSI_RESP_E_UNSUP = 0x3,
	NCSI_RESP_E_ENUM_LAST = 0x8002,
};



/**
 * RSL - ncsi_bmc2cpu_msg
 */
typedef union bdk_ncsi_bmc2cpu_msg {
	uint64_t u;
	struct bdk_ncsi_bmc2cpu_msg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t msg                         : 64; /**< R/W - Data to communicate between BMC and CPU. Provides a mechanism for BMC to signal
                                                                 to the CPU. CPU SW and BMC firmware must agree on the messaging definition which
                                                                 is beyond the scope of this register definition.

                                                                 When this register is written, NCSI_INT[BMC2CPU] is set.
                                                                 INTERNAL: Interrupt is CN88XX pass 2 only, bug21942. */
#else
		uint64_t msg                         : 64;
#endif
	} s;
	/* struct bdk_ncsi_bmc2cpu_msg_s      cn88xx; */
	/* struct bdk_ncsi_bmc2cpu_msg_s      cn88xxp1; */
} bdk_ncsi_bmc2cpu_msg_t;

#define BDK_NCSI_BMC2CPU_MSG BDK_NCSI_BMC2CPU_MSG_FUNC()
static inline uint64_t BDK_NCSI_BMC2CPU_MSG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_BMC2CPU_MSG_FUNC(void)
{
	return 0x000087E00B000108ull;
}
#define typedef_BDK_NCSI_BMC2CPU_MSG bdk_ncsi_bmc2cpu_msg_t
#define bustype_BDK_NCSI_BMC2CPU_MSG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_BMC2CPU_MSG 0
#define arguments_BDK_NCSI_BMC2CPU_MSG -1,-1,-1,-1
#define basename_BDK_NCSI_BMC2CPU_MSG "NCSI_BMC2CPU_MSG"


/**
 * RSL - ncsi_config
 */
typedef union bdk_ncsi_config {
	uint64_t u;
	struct bdk_ncsi_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t pkg_desel_tx_ch_dis         : 1;  /**< R/W - This bit controls whether the NCSI will disable the TX_CH upon pkg deselect command.
                                                                 0 = On pkg deselect command, keep TX channel enabled, enabling pass through traffic to
                                                                 BGX.
                                                                 1 = On pkg deselect command, disable TX channel preventing pass through traffic to BGX. */
		uint64_t cam_accept                  : 1;  /**< R/W - Allow or deny SMAC address filter.  Applies to both SMAC filters in the CAM.
                                                                 See NCSI_TX_FRM_SMAC()_CAM for additional details.
                                                                 0 = Reject the packet on SMAC CAM address match.
                                                                 1 = Accept the packet on SMAC CAM address match. */
#else
		uint64_t cam_accept                  : 1;
		uint64_t pkg_desel_tx_ch_dis         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ncsi_config_s           cn88xx; */
	/* struct bdk_ncsi_config_s           cn88xxp1; */
} bdk_ncsi_config_t;

#define BDK_NCSI_CONFIG BDK_NCSI_CONFIG_FUNC()
static inline uint64_t BDK_NCSI_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_CONFIG_FUNC(void)
{
	return 0x000087E00B000110ull;
}
#define typedef_BDK_NCSI_CONFIG bdk_ncsi_config_t
#define bustype_BDK_NCSI_CONFIG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_CONFIG 0
#define arguments_BDK_NCSI_CONFIG -1,-1,-1,-1
#define basename_BDK_NCSI_CONFIG "NCSI_CONFIG"


/**
 * RSL - ncsi_cpu2bmc_msg
 */
typedef union bdk_ncsi_cpu2bmc_msg {
	uint64_t u;
	struct bdk_ncsi_cpu2bmc_msg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t msg                         : 64; /**< R/W - Data to communicate between CPU and BMC. Provides a mechanism for CPU to signal
                                                                 to the BMC. CPU SW and BMC firmware must agree on the messaging definition which
                                                                 is beyond the scope of this register definition. */
#else
		uint64_t msg                         : 64;
#endif
	} s;
	/* struct bdk_ncsi_cpu2bmc_msg_s      cn88xx; */
	/* struct bdk_ncsi_cpu2bmc_msg_s      cn88xxp1; */
} bdk_ncsi_cpu2bmc_msg_t;

#define BDK_NCSI_CPU2BMC_MSG BDK_NCSI_CPU2BMC_MSG_FUNC()
static inline uint64_t BDK_NCSI_CPU2BMC_MSG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_CPU2BMC_MSG_FUNC(void)
{
	return 0x000087E00B000100ull;
}
#define typedef_BDK_NCSI_CPU2BMC_MSG bdk_ncsi_cpu2bmc_msg_t
#define bustype_BDK_NCSI_CPU2BMC_MSG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_CPU2BMC_MSG 0
#define arguments_BDK_NCSI_CPU2BMC_MSG -1,-1,-1,-1
#define basename_BDK_NCSI_CPU2BMC_MSG "NCSI_CPU2BMC_MSG"


/**
 * RSL - ncsi_int
 */
typedef union bdk_ncsi_int {
	uint64_t u;
	struct bdk_ncsi_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t rx_rsp_overfl               : 1;  /**< R/W1C/H - RX RSP FIFO overflow. */
		uint64_t rx_rsp_sbe                  : 1;  /**< R/W1C/H - RX RSP FIFO single-bit error. */
		uint64_t rx_rsp_dbe                  : 1;  /**< R/W1C/H - RX RSP FIFO double-bit error. */
		uint64_t rx_pmac_underfl             : 1;  /**< R/W1C/H - Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
		uint64_t rx_pmac_sbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO single-bit error. */
		uint64_t rx_pmac_dbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO double-bit error. */
		uint64_t tx_mix_overfl               : 1;  /**< R/W1C/H - TX MIX FIFO overflow. */
		uint64_t tx_mix_sbe                  : 1;  /**< R/W1C/H - TX MIX FIFO single-bit error. */
		uint64_t tx_mix_dbe                  : 1;  /**< R/W1C/H - TX MIX FIFO double-bit error. */
		uint64_t runterr                     : 1;  /**< R/W1C/H - Frame received without a proper L2 header needed for NCSI command detection. */
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
		uint64_t ncp_fcserr                  : 1;  /**< R/W1C/H - NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t pmac_fcserr                 : 1;  /**< R/W1C/H - Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error. Frame was received with length \> sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
#else
		uint64_t jabber                      : 1;
		uint64_t pmac_fcserr                 : 1;
		uint64_t ncp_fcserr                  : 1;
		uint64_t pcterr                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t runterr                     : 1;
		uint64_t tx_mix_dbe                  : 1;
		uint64_t tx_mix_sbe                  : 1;
		uint64_t tx_mix_overfl               : 1;
		uint64_t rx_pmac_dbe                 : 1;
		uint64_t rx_pmac_sbe                 : 1;
		uint64_t rx_pmac_underfl             : 1;
		uint64_t rx_rsp_dbe                  : 1;
		uint64_t rx_rsp_sbe                  : 1;
		uint64_t rx_rsp_overfl               : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_ncsi_int_s              cn88xx; */
	/* struct bdk_ncsi_int_s              cn88xxp1; */
} bdk_ncsi_int_t;

#define BDK_NCSI_INT BDK_NCSI_INT_FUNC()
static inline uint64_t BDK_NCSI_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_FUNC(void)
{
	return 0x000087E00B000000ull;
}
#define typedef_BDK_NCSI_INT bdk_ncsi_int_t
#define bustype_BDK_NCSI_INT BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_INT 0
#define arguments_BDK_NCSI_INT -1,-1,-1,-1
#define basename_BDK_NCSI_INT "NCSI_INT"


/**
 * RSL - ncsi_int_ena_w1c
 */
typedef union bdk_ncsi_int_ena_w1c {
	uint64_t u;
	struct bdk_ncsi_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t rx_rsp_overfl               : 1;  /**< R/W1C/H - RX RSP FIFO overflow. */
		uint64_t rx_rsp_sbe                  : 1;  /**< R/W1C/H - RX RSP FIFO single-bit error. */
		uint64_t rx_rsp_dbe                  : 1;  /**< R/W1C/H - RX RSP FIFO double-bit error. */
		uint64_t rx_pmac_underfl             : 1;  /**< R/W1C/H - Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
		uint64_t rx_pmac_sbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO single-bit error. */
		uint64_t rx_pmac_dbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO double-bit error. */
		uint64_t tx_mix_overfl               : 1;  /**< R/W1C/H - TX MIX FIFO overflow. */
		uint64_t tx_mix_sbe                  : 1;  /**< R/W1C/H - TX MIX FIFO single-bit error. */
		uint64_t tx_mix_dbe                  : 1;  /**< R/W1C/H - TX MIX FIFO double-bit error. */
		uint64_t runterr                     : 1;  /**< R/W1C/H - Frame received without a proper L2 header needed for NCSI command detection. */
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
		uint64_t ncp_fcserr                  : 1;  /**< R/W1C/H - NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t pmac_fcserr                 : 1;  /**< R/W1C/H - Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error. Frame was received with length \> sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
#else
		uint64_t jabber                      : 1;
		uint64_t pmac_fcserr                 : 1;
		uint64_t ncp_fcserr                  : 1;
		uint64_t pcterr                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t runterr                     : 1;
		uint64_t tx_mix_dbe                  : 1;
		uint64_t tx_mix_sbe                  : 1;
		uint64_t tx_mix_overfl               : 1;
		uint64_t rx_pmac_dbe                 : 1;
		uint64_t rx_pmac_sbe                 : 1;
		uint64_t rx_pmac_underfl             : 1;
		uint64_t rx_rsp_dbe                  : 1;
		uint64_t rx_rsp_sbe                  : 1;
		uint64_t rx_rsp_overfl               : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_ncsi_int_ena_w1c_s      cn88xx; */
	/* struct bdk_ncsi_int_ena_w1c_s      cn88xxp1; */
} bdk_ncsi_int_ena_w1c_t;

#define BDK_NCSI_INT_ENA_W1C BDK_NCSI_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_NCSI_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_ENA_W1C_FUNC(void)
{
	return 0x000087E00B000018ull;
}
#define typedef_BDK_NCSI_INT_ENA_W1C bdk_ncsi_int_ena_w1c_t
#define bustype_BDK_NCSI_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_INT_ENA_W1C 0
#define arguments_BDK_NCSI_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NCSI_INT_ENA_W1C "NCSI_INT_ENA_W1C"


/**
 * RSL - ncsi_int_ena_w1s
 */
typedef union bdk_ncsi_int_ena_w1s {
	uint64_t u;
	struct bdk_ncsi_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t rx_rsp_overfl               : 1;  /**< R/W1C/H - RX RSP FIFO overflow. */
		uint64_t rx_rsp_sbe                  : 1;  /**< R/W1C/H - RX RSP FIFO single-bit error. */
		uint64_t rx_rsp_dbe                  : 1;  /**< R/W1C/H - RX RSP FIFO double-bit error. */
		uint64_t rx_pmac_underfl             : 1;  /**< R/W1C/H - Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
		uint64_t rx_pmac_sbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO single-bit error. */
		uint64_t rx_pmac_dbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO double-bit error. */
		uint64_t tx_mix_overfl               : 1;  /**< R/W1C/H - TX MIX FIFO overflow. */
		uint64_t tx_mix_sbe                  : 1;  /**< R/W1C/H - TX MIX FIFO single-bit error. */
		uint64_t tx_mix_dbe                  : 1;  /**< R/W1C/H - TX MIX FIFO double-bit error. */
		uint64_t runterr                     : 1;  /**< R/W1C/H - Frame received without a proper L2 header needed for NCSI command detection. */
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
		uint64_t ncp_fcserr                  : 1;  /**< R/W1C/H - NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t pmac_fcserr                 : 1;  /**< R/W1C/H - Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error. Frame was received with length \> sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
#else
		uint64_t jabber                      : 1;
		uint64_t pmac_fcserr                 : 1;
		uint64_t ncp_fcserr                  : 1;
		uint64_t pcterr                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t runterr                     : 1;
		uint64_t tx_mix_dbe                  : 1;
		uint64_t tx_mix_sbe                  : 1;
		uint64_t tx_mix_overfl               : 1;
		uint64_t rx_pmac_dbe                 : 1;
		uint64_t rx_pmac_sbe                 : 1;
		uint64_t rx_pmac_underfl             : 1;
		uint64_t rx_rsp_dbe                  : 1;
		uint64_t rx_rsp_sbe                  : 1;
		uint64_t rx_rsp_overfl               : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_ncsi_int_ena_w1s_s      cn88xx; */
	/* struct bdk_ncsi_int_ena_w1s_s      cn88xxp1; */
} bdk_ncsi_int_ena_w1s_t;

#define BDK_NCSI_INT_ENA_W1S BDK_NCSI_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_NCSI_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_ENA_W1S_FUNC(void)
{
	return 0x000087E00B000010ull;
}
#define typedef_BDK_NCSI_INT_ENA_W1S bdk_ncsi_int_ena_w1s_t
#define bustype_BDK_NCSI_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_INT_ENA_W1S 0
#define arguments_BDK_NCSI_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NCSI_INT_ENA_W1S "NCSI_INT_ENA_W1S"


/**
 * RSL - ncsi_int_w1s
 */
typedef union bdk_ncsi_int_w1s {
	uint64_t u;
	struct bdk_ncsi_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t rx_rsp_overfl               : 1;  /**< R/W1C/H - RX RSP FIFO overflow. */
		uint64_t rx_rsp_sbe                  : 1;  /**< R/W1C/H - RX RSP FIFO single-bit error. */
		uint64_t rx_rsp_dbe                  : 1;  /**< R/W1C/H - RX RSP FIFO double-bit error. */
		uint64_t rx_pmac_underfl             : 1;  /**< R/W1C/H - Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
		uint64_t rx_pmac_sbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO single-bit error. */
		uint64_t rx_pmac_dbe                 : 1;  /**< R/W1C/H - RX PMAC FIFO double-bit error. */
		uint64_t tx_mix_overfl               : 1;  /**< R/W1C/H - TX MIX FIFO overflow. */
		uint64_t tx_mix_sbe                  : 1;  /**< R/W1C/H - TX MIX FIFO single-bit error. */
		uint64_t tx_mix_dbe                  : 1;  /**< R/W1C/H - TX MIX FIFO double-bit error. */
		uint64_t runterr                     : 1;  /**< R/W1C/H - Frame received without a proper L2 header needed for NCSI command detection. */
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
		uint64_t ncp_fcserr                  : 1;  /**< R/W1C/H - NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t pmac_fcserr                 : 1;  /**< R/W1C/H - Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error. Frame was received with length \> sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
#else
		uint64_t jabber                      : 1;
		uint64_t pmac_fcserr                 : 1;
		uint64_t ncp_fcserr                  : 1;
		uint64_t pcterr                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t runterr                     : 1;
		uint64_t tx_mix_dbe                  : 1;
		uint64_t tx_mix_sbe                  : 1;
		uint64_t tx_mix_overfl               : 1;
		uint64_t rx_pmac_dbe                 : 1;
		uint64_t rx_pmac_sbe                 : 1;
		uint64_t rx_pmac_underfl             : 1;
		uint64_t rx_rsp_dbe                  : 1;
		uint64_t rx_rsp_sbe                  : 1;
		uint64_t rx_rsp_overfl               : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_ncsi_int_w1s_s          cn88xx; */
	/* struct bdk_ncsi_int_w1s_s          cn88xxp1; */
} bdk_ncsi_int_w1s_t;

#define BDK_NCSI_INT_W1S BDK_NCSI_INT_W1S_FUNC()
static inline uint64_t BDK_NCSI_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_W1S_FUNC(void)
{
	return 0x000087E00B000008ull;
}
#define typedef_BDK_NCSI_INT_W1S bdk_ncsi_int_w1s_t
#define bustype_BDK_NCSI_INT_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_INT_W1S 0
#define arguments_BDK_NCSI_INT_W1S -1,-1,-1,-1
#define basename_BDK_NCSI_INT_W1S "NCSI_INT_W1S"


/**
 * RSL - ncsi_mem_ctrl
 */
typedef union bdk_ncsi_mem_ctrl {
	uint64_t u;
	struct bdk_ncsi_mem_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t rx_rsp_synd                 : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for RX RSP FIFO. */
		uint64_t rx_rsp_cor_dis              : 1;  /**< R/W - ECC-correction disable for the RX RSP FIFO. */
		uint64_t rx_pmac_synd                : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for RX PMAC FIFO. */
		uint64_t rx_pmac_cor_dis             : 1;  /**< R/W - ECC-correction disable for the RX PMAC FIFO. */
		uint64_t tx_mix_synd                 : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for TX MIX_FIFO. */
		uint64_t tx_mix_cor_dis              : 1;  /**< R/W - ECC-correction disable for the TX MIX FIFO. */
#else
		uint64_t tx_mix_cor_dis              : 1;
		uint64_t tx_mix_synd                 : 2;
		uint64_t rx_pmac_cor_dis             : 1;
		uint64_t rx_pmac_synd                : 2;
		uint64_t rx_rsp_cor_dis              : 1;
		uint64_t rx_rsp_synd                 : 2;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ncsi_mem_ctrl_s         cn88xx; */
	/* struct bdk_ncsi_mem_ctrl_s         cn88xxp1; */
} bdk_ncsi_mem_ctrl_t;

#define BDK_NCSI_MEM_CTRL BDK_NCSI_MEM_CTRL_FUNC()
static inline uint64_t BDK_NCSI_MEM_CTRL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MEM_CTRL_FUNC(void)
{
	return 0x000087E00B000118ull;
}
#define typedef_BDK_NCSI_MEM_CTRL bdk_ncsi_mem_ctrl_t
#define bustype_BDK_NCSI_MEM_CTRL BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_MEM_CTRL 0
#define arguments_BDK_NCSI_MEM_CTRL -1,-1,-1,-1
#define basename_BDK_NCSI_MEM_CTRL "NCSI_MEM_CTRL"


/**
 * RSL - ncsi_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the NCSI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_ncsi_msix_pbax {
	uint64_t u;
	struct bdk_ncsi_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated NCSI_MSIX_VEC()_CTL, enumerated by NCSI_INT_VEC_E.
                                                                 Bits that have no associated NCSI_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_ncsi_msix_pbax_s        cn88xx; */
	/* struct bdk_ncsi_msix_pbax_s        cn88xxp1; */
} bdk_ncsi_msix_pbax_t;

static inline uint64_t BDK_NCSI_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E00BFF0000ull;
	csr_fatal("BDK_NCSI_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NCSI_MSIX_PBAX(...) bdk_ncsi_msix_pbax_t
#define bustype_BDK_NCSI_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_MSIX_PBAX(p1) (p1)
#define arguments_BDK_NCSI_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_NCSI_MSIX_PBAX(...) "NCSI_MSIX_PBAX"


/**
 * RSL - ncsi_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the NCSI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_ncsi_msix_vecx_addr {
	uint64_t u;
	struct bdk_ncsi_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's NCSI_MSIX_VEC()_ADDR, NCSI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of NCSI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_NCSI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_ncsi_msix_vecx_addr_s   cn88xx; */
	/* struct bdk_ncsi_msix_vecx_addr_s   cn88xxp1; */
} bdk_ncsi_msix_vecx_addr_t;

static inline uint64_t BDK_NCSI_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E00BF00000ull;
	csr_fatal("BDK_NCSI_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NCSI_MSIX_VECX_ADDR(...) bdk_ncsi_msix_vecx_addr_t
#define bustype_BDK_NCSI_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_NCSI_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_NCSI_MSIX_VECX_ADDR(...) "NCSI_MSIX_VECX_ADDR"


/**
 * RSL - ncsi_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the NCSI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_ncsi_msix_vecx_ctl {
	uint64_t u;
	struct bdk_ncsi_msix_vecx_ctl_s {
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
	/* struct bdk_ncsi_msix_vecx_ctl_s    cn88xx; */
	/* struct bdk_ncsi_msix_vecx_ctl_s    cn88xxp1; */
} bdk_ncsi_msix_vecx_ctl_t;

static inline uint64_t BDK_NCSI_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E00BF00008ull;
	csr_fatal("BDK_NCSI_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NCSI_MSIX_VECX_CTL(...) bdk_ncsi_msix_vecx_ctl_t
#define bustype_BDK_NCSI_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_NCSI_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_NCSI_MSIX_VECX_CTL(...) "NCSI_MSIX_VECX_CTL"


/**
 * RSL - ncsi_rx_frm_ctl
 *
 * This register should be set in coordination with BGX registers that control similar
 * parameters.
 * If NCSI should is configured to prepend preamble and postpend FCS, then these should be
 * stripped
 * by BGX.  If NCSI is configured not to prepend preamble and postpend FCS, then BGX should not
 * be stripping these values.
 * Practically speaking, preamble and FCS should be set together.
 */
typedef union bdk_ncsi_rx_frm_ctl {
	uint64_t u;
	struct bdk_ncsi_rx_frm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t fcs                         : 1;  /**< R/W - Append the Ethernet FCS on each pass through packet going to RMII. */
		uint64_t pad                         : 1;  /**< R/W - Append PAD bytes such that minimum-sized pass through packet is sent over RMII. FCS will
                                                                 be appended in this case by default. */
		uint64_t preamble                    : 1;  /**< R/W - Prepend the Ethernet preamble on each pass through transfer over RMII */
#else
		uint64_t preamble                    : 1;
		uint64_t pad                         : 1;
		uint64_t fcs                         : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_ncsi_rx_frm_ctl_s       cn88xx; */
	/* struct bdk_ncsi_rx_frm_ctl_s       cn88xxp1; */
} bdk_ncsi_rx_frm_ctl_t;

#define BDK_NCSI_RX_FRM_CTL BDK_NCSI_RX_FRM_CTL_FUNC()
static inline uint64_t BDK_NCSI_RX_FRM_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_FRM_CTL_FUNC(void)
{
	return 0x000087E00B000508ull;
}
#define typedef_BDK_NCSI_RX_FRM_CTL bdk_ncsi_rx_frm_ctl_t
#define bustype_BDK_NCSI_RX_FRM_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_FRM_CTL 0
#define arguments_BDK_NCSI_RX_FRM_CTL -1,-1,-1,-1
#define basename_BDK_NCSI_RX_FRM_CTL "NCSI_RX_FRM_CTL"


/**
 * RSL - ncsi_rx_ifg
 *
 * Interframe gap between packets going out on the RMII interface.
 * For IEEE 802.3 compatibility, IFG1 must be in the range of 1-11, IFG2 must be in the range
 * of 1-11, and the IFG1 + IFG2 sum must be 12 resulting in 96 bit times.
 * For all other systems, IFG1 and IFG2 can be any value in the range of 1-15, allowing for a
 * total possible IFG sum of 2 minimum and 30 maximum.
 */
typedef union bdk_ncsi_rx_ifg {
	uint64_t u;
	struct bdk_ncsi_rx_ifg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t ifg2                        : 4;  /**< R/W - Remainder of interFrameGap timing, equal to interFrameGap - IFG1 (in IFG2 * 8 bits). A
                                                                 value of 4 sets an IFG2 of 32 bit times appropriate for 802.3 compliance. */
		uint64_t ifg1                        : 4;  /**< R/W - First portion of interFrameGap timing, (in IFG1 * 8 bits). A value of 8 sets an IFG1 of 64
                                                                 bit times appropriate for 802.3 compliance. */
#else
		uint64_t ifg1                        : 4;
		uint64_t ifg2                        : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_ncsi_rx_ifg_s           cn88xx; */
	/* struct bdk_ncsi_rx_ifg_s           cn88xxp1; */
} bdk_ncsi_rx_ifg_t;

#define BDK_NCSI_RX_IFG BDK_NCSI_RX_IFG_FUNC()
static inline uint64_t BDK_NCSI_RX_IFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_IFG_FUNC(void)
{
	return 0x000087E00B000518ull;
}
#define typedef_BDK_NCSI_RX_IFG bdk_ncsi_rx_ifg_t
#define bustype_BDK_NCSI_RX_IFG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_IFG 0
#define arguments_BDK_NCSI_RX_IFG -1,-1,-1,-1
#define basename_BDK_NCSI_RX_IFG "NCSI_RX_IFG"


/**
 * RSL - ncsi_rx_mfg
 *
 * This register sets the manufacturer ID.
 *
 */
typedef union bdk_ncsi_rx_mfg {
	uint64_t u;
	struct bdk_ncsi_rx_mfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t id                          : 32; /**< R/W - Manufacturer ID to place in the NCSI OEM and GET_ID response packets.
                                                                 The value should not conflict with the existing vendor enterprise numbers in the
                                                                 IANA database. For commands on the TX side, the incoming OEM command mfg id entry
                                                                 will go unchecked since the package and channel fields of the NCSI header are
                                                                 sufficient to address the network controller. */
#else
		uint64_t id                          : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_ncsi_rx_mfg_s           cn88xx; */
	/* struct bdk_ncsi_rx_mfg_s           cn88xxp1; */
} bdk_ncsi_rx_mfg_t;

#define BDK_NCSI_RX_MFG BDK_NCSI_RX_MFG_FUNC()
static inline uint64_t BDK_NCSI_RX_MFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_MFG_FUNC(void)
{
	return 0x000087E00B000520ull;
}
#define typedef_BDK_NCSI_RX_MFG bdk_ncsi_rx_mfg_t
#define bustype_BDK_NCSI_RX_MFG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_MFG 0
#define arguments_BDK_NCSI_RX_MFG -1,-1,-1,-1
#define basename_BDK_NCSI_RX_MFG "NCSI_RX_MFG"


/**
 * RSL - ncsi_rx_min_pkt
 */
typedef union bdk_ncsi_rx_min_pkt {
	uint64_t u;
	struct bdk_ncsi_rx_min_pkt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t min_size                    : 6;  /**< R/W - Minimum frame size in bytes before the FCS is applied for packets going to the RMII
                                                                 interface and does not include Preamble/SFD. Padding is only appended when
                                                                 NCSI_RX_FRM_CTL[PAD] set.
                                                                 The reset value pads to 60 bytes. */
#else
		uint64_t min_size                    : 6;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_ncsi_rx_min_pkt_s       cn88xx; */
	/* struct bdk_ncsi_rx_min_pkt_s       cn88xxp1; */
} bdk_ncsi_rx_min_pkt_t;

#define BDK_NCSI_RX_MIN_PKT BDK_NCSI_RX_MIN_PKT_FUNC()
static inline uint64_t BDK_NCSI_RX_MIN_PKT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_MIN_PKT_FUNC(void)
{
	return 0x000087E00B000510ull;
}
#define typedef_BDK_NCSI_RX_MIN_PKT bdk_ncsi_rx_min_pkt_t
#define bustype_BDK_NCSI_RX_MIN_PKT BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_MIN_PKT 0
#define arguments_BDK_NCSI_RX_MIN_PKT -1,-1,-1,-1
#define basename_BDK_NCSI_RX_MIN_PKT "NCSI_RX_MIN_PKT"


/**
 * RSL - ncsi_rx_stat0
 *
 * This register provides a count of valid packets through the recieve side NCSI at the output of
 * the recieve side buffers.
 */
typedef union bdk_ncsi_rx_stat0 {
	uint64_t u;
	struct bdk_ncsi_rx_stat0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of packets through the rx-side NCSI. This includes both pass through and response
                                                                 packets and does not include those
                                                                 stored in the fifo waiting to be dequeued. CNT will wrap and is cleared if NCSI is
                                                                 disabled with NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ncsi_rx_stat0_s         cn88xx; */
	/* struct bdk_ncsi_rx_stat0_s         cn88xxp1; */
} bdk_ncsi_rx_stat0_t;

#define BDK_NCSI_RX_STAT0 BDK_NCSI_RX_STAT0_FUNC()
static inline uint64_t BDK_NCSI_RX_STAT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_STAT0_FUNC(void)
{
	return 0x000087E00B000600ull;
}
#define typedef_BDK_NCSI_RX_STAT0 bdk_ncsi_rx_stat0_t
#define bustype_BDK_NCSI_RX_STAT0 BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_STAT0 0
#define arguments_BDK_NCSI_RX_STAT0 -1,-1,-1,-1
#define basename_BDK_NCSI_RX_STAT0 "NCSI_RX_STAT0"


/**
 * RSL - ncsi_rx_stat1
 *
 * This register provides a count of valid bytes through the recieve side NCSI at the output of
 * the recieve side buffers. During underflow situations the count may deviate from the
 * the number of bytes that appear on the RMII interface.  This is due to the fact the design
 * does not deassert CRS_DV during underflow situations until the packet boundary is detected.
 */
typedef union bdk_ncsi_rx_stat1 {
	uint64_t u;
	struct bdk_ncsi_rx_stat1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of valid bytes through the RX-side NCSI.  This includes both pass through and
                                                                 response packet bytes and does not include those stored in the FIFO waiting to be
                                                                 dequeued. CNT will wrap and is cleared if NCSI is disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ncsi_rx_stat1_s         cn88xx; */
	/* struct bdk_ncsi_rx_stat1_s         cn88xxp1; */
} bdk_ncsi_rx_stat1_t;

#define BDK_NCSI_RX_STAT1 BDK_NCSI_RX_STAT1_FUNC()
static inline uint64_t BDK_NCSI_RX_STAT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_STAT1_FUNC(void)
{
	return 0x000087E00B000608ull;
}
#define typedef_BDK_NCSI_RX_STAT1 bdk_ncsi_rx_stat1_t
#define bustype_BDK_NCSI_RX_STAT1 BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_STAT1 0
#define arguments_BDK_NCSI_RX_STAT1 -1,-1,-1,-1
#define basename_BDK_NCSI_RX_STAT1 "NCSI_RX_STAT1"


/**
 * RSL - ncsi_rx_thresh
 */
typedef union bdk_ncsi_rx_thresh {
	uint64_t u;
	struct bdk_ncsi_rx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t cnt                         : 11; /**< R/W - Number of bytes to accumulate in the RX FIFO before sending on the RMII
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0. */
#else
		uint64_t cnt                         : 11;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_ncsi_rx_thresh_s        cn88xx; */
	/* struct bdk_ncsi_rx_thresh_s        cn88xxp1; */
} bdk_ncsi_rx_thresh_t;

#define BDK_NCSI_RX_THRESH BDK_NCSI_RX_THRESH_FUNC()
static inline uint64_t BDK_NCSI_RX_THRESH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_THRESH_FUNC(void)
{
	return 0x000087E00B000500ull;
}
#define typedef_BDK_NCSI_RX_THRESH bdk_ncsi_rx_thresh_t
#define bustype_BDK_NCSI_RX_THRESH BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_RX_THRESH 0
#define arguments_BDK_NCSI_RX_THRESH -1,-1,-1,-1
#define basename_BDK_NCSI_RX_THRESH "NCSI_RX_THRESH"


/**
 * RSL - ncsi_secure_config
 */
typedef union bdk_ncsi_secure_config {
	uint64_t u;
	struct bdk_ncsi_secure_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ncsien                      : 1;  /**< SR/W - Master enable for the NCSI block. */
		uint64_t ncsisecen                   : 1;  /**< SR/W - For BMC access using the OEM command, allow or deny secure access into CNXXXX.
                                                                 Also see NCSI_TX_NCP_PERM()_TABLE.
                                                                 0 = OEM command address must pass the permision table filter before being forwarded to the
                                                                 MRML. Access to NCSI_CPU2BMC_MSG and NCSI_BMC2CPU_MSG are always allowed.
                                                                 1 = Bypass the permissions table and allow any register access in the RSL address space. */
#else
		uint64_t ncsisecen                   : 1;
		uint64_t ncsien                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ncsi_secure_config_s    cn88xx; */
	/* struct bdk_ncsi_secure_config_s    cn88xxp1; */
} bdk_ncsi_secure_config_t;

#define BDK_NCSI_SECURE_CONFIG BDK_NCSI_SECURE_CONFIG_FUNC()
static inline uint64_t BDK_NCSI_SECURE_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_SECURE_CONFIG_FUNC(void)
{
	return 0x000087E00B000800ull;
}
#define typedef_BDK_NCSI_SECURE_CONFIG bdk_ncsi_secure_config_t
#define bustype_BDK_NCSI_SECURE_CONFIG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_SECURE_CONFIG 0
#define arguments_BDK_NCSI_SECURE_CONFIG -1,-1,-1,-1
#define basename_BDK_NCSI_SECURE_CONFIG "NCSI_SECURE_CONFIG"


/**
 * RSL - ncsi_tx_frm_ctl
 *
 * Frame control register for packets coming in from the RMII interface.
 *
 */
typedef union bdk_ncsi_tx_frm_ctl {
	uint64_t u;
	struct bdk_ncsi_tx_frm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t pre_strp                    : 1;  /**< R/W - Strip off the PREAMBLE and SFD:
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.

                                                                 PRE_STRP determines if the PREAMBLE+SFD bytes are thrown away or sent to the core as part
                                                                 of the packet. With either setting, the PREAMBLE+SFD bytes are not counted toward the
                                                                 packet size when checking against the MIN and MAX bounds. Furthermore, the bytes are
                                                                 skipped when locating the start of the L2 header for DMAC recognition. */
		uint64_t pre_chk_len                 : 3;  /**< R/W - Check that a correct preamble of a given length is present.

                                                                 With a setting of \> 0, NCSI checks that a valid PREAMBLE is received and of the
                                                                 corresponding length in bytes.
                                                                 If a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The NCSI_INT[PCTERR] interrupt is also raised.

                                                                 With a setting of 0, NCSI checks the first byte is an valid SFD symbol and not a PREAMBLE
                                                                 symbol. */
#else
		uint64_t pre_chk_len                 : 3;
		uint64_t pre_strp                    : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_ncsi_tx_frm_ctl_s       cn88xx; */
	/* struct bdk_ncsi_tx_frm_ctl_s       cn88xxp1; */
} bdk_ncsi_tx_frm_ctl_t;

#define BDK_NCSI_TX_FRM_CTL BDK_NCSI_TX_FRM_CTL_FUNC()
static inline uint64_t BDK_NCSI_TX_FRM_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_FRM_CTL_FUNC(void)
{
	return 0x000087E00B000120ull;
}
#define typedef_BDK_NCSI_TX_FRM_CTL bdk_ncsi_tx_frm_ctl_t
#define bustype_BDK_NCSI_TX_FRM_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_FRM_CTL 0
#define arguments_BDK_NCSI_TX_FRM_CTL -1,-1,-1,-1
#define basename_BDK_NCSI_TX_FRM_CTL "NCSI_TX_FRM_CTL"


/**
 * RSL - ncsi_tx_frm_smac#_cam
 *
 * These registers set TX framer Source MAC address CAM.  See NCSI_CONFIG for addition CAM config
 * options.
 */
typedef union bdk_ncsi_tx_frm_smacx_cam {
	uint64_t u;
	struct bdk_ncsi_tx_frm_smacx_cam_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t en                          : 1;  /**< R/W - CAM entry enable for this SMAC address.
                                                                 1 = Include this address in the matching algorithm.
                                                                 0 = Don't include this address in the matching algorithm. */
		uint64_t adr                         : 48; /**< R/W - SMAC address in the CAM used for matching. */
#else
		uint64_t adr                         : 48;
		uint64_t en                          : 1;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_ncsi_tx_frm_smacx_cam_s cn88xx; */
	/* struct bdk_ncsi_tx_frm_smacx_cam_s cn88xxp1; */
} bdk_ncsi_tx_frm_smacx_cam_t;

static inline uint64_t BDK_NCSI_TX_FRM_SMACX_CAM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_FRM_SMACX_CAM(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E00B000200ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_NCSI_TX_FRM_SMACX_CAM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NCSI_TX_FRM_SMACX_CAM(...) bdk_ncsi_tx_frm_smacx_cam_t
#define bustype_BDK_NCSI_TX_FRM_SMACX_CAM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_FRM_SMACX_CAM(p1) (p1)
#define arguments_BDK_NCSI_TX_FRM_SMACX_CAM(p1) (p1),-1,-1,-1
#define basename_BDK_NCSI_TX_FRM_SMACX_CAM(...) "NCSI_TX_FRM_SMACX_CAM"


/**
 * RSL - ncsi_tx_ifg
 *
 * This register specifies the minimum number of interframe-gap (IFG) cycles between packets
 * recieved from the RMII input interface.
 */
typedef union bdk_ncsi_tx_ifg {
	uint64_t u;
	struct bdk_ncsi_tx_ifg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t ifg                         : 6;  /**< R/W - Min IFG (in refclk cycles) between packets used to determine IFGERR.
                                                                 Normally IFG is 96 bits, and with 2 bits per cycle, equates to 48. */
#else
		uint64_t ifg                         : 6;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_ncsi_tx_ifg_s           cn88xx; */
	/* struct bdk_ncsi_tx_ifg_s           cn88xxp1; */
} bdk_ncsi_tx_ifg_t;

#define BDK_NCSI_TX_IFG BDK_NCSI_TX_IFG_FUNC()
static inline uint64_t BDK_NCSI_TX_IFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_IFG_FUNC(void)
{
	return 0x000087E00B000130ull;
}
#define typedef_BDK_NCSI_TX_IFG bdk_ncsi_tx_ifg_t
#define bustype_BDK_NCSI_TX_IFG BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_IFG 0
#define arguments_BDK_NCSI_TX_IFG -1,-1,-1,-1
#define basename_BDK_NCSI_TX_IFG "NCSI_TX_IFG"


/**
 * RSL - ncsi_tx_jabber
 *
 * The max size of a packet in bytes, including preamble, SFD and FCS, that the NCSI will allow.
 * Any packet recieved by the NCSI TX RMII interface larger than NCSI_TX_JABBER[CNT] will be
 * marked with error and become eligible for packet truncation.  Transmission will resume at
 * the detection of the next packet.
 */
typedef union bdk_ncsi_tx_jabber {
	uint64_t u;
	struct bdk_ncsi_tx_jabber_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cnt                         : 16; /**< R/W - Byte count for jabber check. Failing packets set the JABBER interrupt and are
                                                                 sent with opcode = JABBER. NCSI truncates the packet to CNT+1 bytes. */
#else
		uint64_t cnt                         : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ncsi_tx_jabber_s        cn88xx; */
	/* struct bdk_ncsi_tx_jabber_s        cn88xxp1; */
} bdk_ncsi_tx_jabber_t;

#define BDK_NCSI_TX_JABBER BDK_NCSI_TX_JABBER_FUNC()
static inline uint64_t BDK_NCSI_TX_JABBER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_JABBER_FUNC(void)
{
	return 0x000087E00B000128ull;
}
#define typedef_BDK_NCSI_TX_JABBER bdk_ncsi_tx_jabber_t
#define bustype_BDK_NCSI_TX_JABBER BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_JABBER 0
#define arguments_BDK_NCSI_TX_JABBER -1,-1,-1,-1
#define basename_BDK_NCSI_TX_JABBER "NCSI_TX_JABBER"


/**
 * RSL - ncsi_tx_mix
 *
 * This register specifies configuration parameters for the MIX interface of BGX.
 *
 */
typedef union bdk_ncsi_tx_mix {
	uint64_t u;
	struct bdk_ncsi_tx_mix_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t port                        : 4;  /**< R/W - Port value inserted into MIX frames headed to the BGX where it is used as the channel number. */
#else
		uint64_t port                        : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_ncsi_tx_mix_s           cn88xx; */
	/* struct bdk_ncsi_tx_mix_s           cn88xxp1; */
} bdk_ncsi_tx_mix_t;

#define BDK_NCSI_TX_MIX BDK_NCSI_TX_MIX_FUNC()
static inline uint64_t BDK_NCSI_TX_MIX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_MIX_FUNC(void)
{
	return 0x000087E00B000138ull;
}
#define typedef_BDK_NCSI_TX_MIX bdk_ncsi_tx_mix_t
#define bustype_BDK_NCSI_TX_MIX BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_MIX 0
#define arguments_BDK_NCSI_TX_MIX -1,-1,-1,-1
#define basename_BDK_NCSI_TX_MIX "NCSI_TX_MIX"


/**
 * RSL - ncsi_tx_ncp_ch_st
 *
 * This register provides the NCSI command processor channel state status.
 *
 */
typedef union bdk_ncsi_tx_ncp_ch_st {
	uint64_t u;
	struct bdk_ncsi_tx_ncp_ch_st_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ald                         : 1;  /**< RO/H - Current state of ALD (allow link disable) in the last received disable channel command. */
		uint64_t state                       : 1;  /**< RO/H - Current state of the NCSI command processor channel state. */
#else
		uint64_t state                       : 1;
		uint64_t ald                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ncsi_tx_ncp_ch_st_s     cn88xx; */
	/* struct bdk_ncsi_tx_ncp_ch_st_s     cn88xxp1; */
} bdk_ncsi_tx_ncp_ch_st_t;

#define BDK_NCSI_TX_NCP_CH_ST BDK_NCSI_TX_NCP_CH_ST_FUNC()
static inline uint64_t BDK_NCSI_TX_NCP_CH_ST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_CH_ST_FUNC(void)
{
	return 0x000087E00B000140ull;
}
#define typedef_BDK_NCSI_TX_NCP_CH_ST bdk_ncsi_tx_ncp_ch_st_t
#define bustype_BDK_NCSI_TX_NCP_CH_ST BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_NCP_CH_ST 0
#define arguments_BDK_NCSI_TX_NCP_CH_ST -1,-1,-1,-1
#define basename_BDK_NCSI_TX_NCP_CH_ST "NCSI_TX_NCP_CH_ST"


/**
 * RSL - ncsi_tx_ncp_perm#_table_hi
 *
 * These registers set the TX NCP Permission table high address range filter for the OEM command.
 *
 */
typedef union bdk_ncsi_tx_ncp_permx_table_hi {
	uint64_t u;
	struct bdk_ncsi_tx_ncp_permx_table_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t addr                        : 64; /**< SR/W - Specifies the high physical address in formulating a permissions filter for OEM command
                                                                 access.
                                                                 Together with the respective NCSI_TX_NCP_PERM()_TABLE_LOW entry, specifies
                                                                 a range, from NCSI_TX_NCP_PERM_TABLE()_LOW[n] to NCSI_TX_NCP_PERM()_TABLE_HI[n] of
                                                                 physical addresses, contained in the OEM command, that have permissions to execute
                                                                 read or writes to CNXXXX general registers through MRML.

                                                                 Values per entry should be set such that LOW[n]\<=HI[n]. To specify a single address the hi
                                                                 and low are programmed with the same value.
                                                                 If a range in one set of HI/LOW entries overlaps with another, the
                                                                 overlap is harmlessly redundant.

                                                                 Default values allow default access to:

                                                                   * All NCSI addresses except secure registers.
                                                                   * All BGX0 and BGX1 addresses except secure registers.
                                                                   * All SERDES addresses serving BGX0 and BGX1, namely QLM0 and QLM1.

                                                                 Access to NCSI_CPU2BMC_MSG and NCSI_BMC2CPU_MSG are always allowed. */
#else
		uint64_t addr                        : 64;
#endif
	} s;
	/* struct bdk_ncsi_tx_ncp_permx_table_hi_s cn88xx; */
	/* struct bdk_ncsi_tx_ncp_permx_table_hi_s cn88xxp1; */
} bdk_ncsi_tx_ncp_permx_table_hi_t;

static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_HI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_HI(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000087E00B000900ull + (param1 & 15) * 0x8ull;
	csr_fatal("BDK_NCSI_TX_NCP_PERMX_TABLE_HI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(...) bdk_ncsi_tx_ncp_permx_table_hi_t
#define bustype_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(p1) (p1)
#define arguments_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(p1) (p1),-1,-1,-1
#define basename_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(...) "NCSI_TX_NCP_PERMX_TABLE_HI"


/**
 * RSL - ncsi_tx_ncp_perm#_table_low
 *
 * These registers set the TX NCP Permission table low address range filter for the OEM command.
 *
 */
typedef union bdk_ncsi_tx_ncp_permx_table_low {
	uint64_t u;
	struct bdk_ncsi_tx_ncp_permx_table_low_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t addr                        : 64; /**< SR/W - Specifies the low physical address in formulating a permissions filter for OEM command
                                                                 access.  See NCSI_TX_NCP_PERM()_TABLE_HI. */
#else
		uint64_t addr                        : 64;
#endif
	} s;
	/* struct bdk_ncsi_tx_ncp_permx_table_low_s cn88xx; */
	/* struct bdk_ncsi_tx_ncp_permx_table_low_s cn88xxp1; */
} bdk_ncsi_tx_ncp_permx_table_low_t;

static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000087E00B000A00ull + (param1 & 15) * 0x8ull;
	csr_fatal("BDK_NCSI_TX_NCP_PERMX_TABLE_LOW", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(...) bdk_ncsi_tx_ncp_permx_table_low_t
#define bustype_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(p1) (p1)
#define arguments_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(p1) (p1),-1,-1,-1
#define basename_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(...) "NCSI_TX_NCP_PERMX_TABLE_LOW"


/**
 * RSL - ncsi_tx_ncp_pkg_st
 *
 * This register provides the NCSI command processor package state status.
 *
 */
typedef union bdk_ncsi_tx_ncp_pkg_st {
	uint64_t u;
	struct bdk_ncsi_tx_ncp_pkg_st_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t state                       : 1;  /**< RO/H - Currect state of the NCSI command processor package state. */
#else
		uint64_t state                       : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_ncsi_tx_ncp_pkg_st_s    cn88xx; */
	/* struct bdk_ncsi_tx_ncp_pkg_st_s    cn88xxp1; */
} bdk_ncsi_tx_ncp_pkg_st_t;

#define BDK_NCSI_TX_NCP_PKG_ST BDK_NCSI_TX_NCP_PKG_ST_FUNC()
static inline uint64_t BDK_NCSI_TX_NCP_PKG_ST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_PKG_ST_FUNC(void)
{
	return 0x000087E00B000148ull;
}
#define typedef_BDK_NCSI_TX_NCP_PKG_ST bdk_ncsi_tx_ncp_pkg_st_t
#define bustype_BDK_NCSI_TX_NCP_PKG_ST BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_NCP_PKG_ST 0
#define arguments_BDK_NCSI_TX_NCP_PKG_ST -1,-1,-1,-1
#define basename_BDK_NCSI_TX_NCP_PKG_ST "NCSI_TX_NCP_PKG_ST"


/**
 * RSL - ncsi_tx_stat0
 *
 * This register provides a count of valid packets detected at the output of the transmit side
 * NCSI framer.
 */
typedef union bdk_ncsi_tx_stat0 {
	uint64_t u;
	struct bdk_ncsi_tx_stat0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of valid packets through the tx side framers. CNT will wrap and is cleared if NCSI
                                                                 is disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ncsi_tx_stat0_s         cn88xx; */
	/* struct bdk_ncsi_tx_stat0_s         cn88xxp1; */
} bdk_ncsi_tx_stat0_t;

#define BDK_NCSI_TX_STAT0 BDK_NCSI_TX_STAT0_FUNC()
static inline uint64_t BDK_NCSI_TX_STAT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_STAT0_FUNC(void)
{
	return 0x000087E00B000300ull;
}
#define typedef_BDK_NCSI_TX_STAT0 bdk_ncsi_tx_stat0_t
#define bustype_BDK_NCSI_TX_STAT0 BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_STAT0 0
#define arguments_BDK_NCSI_TX_STAT0 -1,-1,-1,-1
#define basename_BDK_NCSI_TX_STAT0 "NCSI_TX_STAT0"


/**
 * RSL - ncsi_tx_stat1
 *
 * This register provides a count of valid bytes detected at the output of the transmit side
 * NCSI framer.  These bytes are detected as being part of a valid frame.
 */
typedef union bdk_ncsi_tx_stat1 {
	uint64_t u;
	struct bdk_ncsi_tx_stat1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of valid bytes through the tx side framer. CNT will wrap and is cleared if NCSI is
                                                                 disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_ncsi_tx_stat1_s         cn88xx; */
	/* struct bdk_ncsi_tx_stat1_s         cn88xxp1; */
} bdk_ncsi_tx_stat1_t;

#define BDK_NCSI_TX_STAT1 BDK_NCSI_TX_STAT1_FUNC()
static inline uint64_t BDK_NCSI_TX_STAT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_STAT1_FUNC(void)
{
	return 0x000087E00B000308ull;
}
#define typedef_BDK_NCSI_TX_STAT1 bdk_ncsi_tx_stat1_t
#define bustype_BDK_NCSI_TX_STAT1 BDK_CSR_TYPE_RSL
#define busnum_BDK_NCSI_TX_STAT1 0
#define arguments_BDK_NCSI_TX_STAT1 -1,-1,-1,-1
#define basename_BDK_NCSI_TX_STAT1 "NCSI_TX_STAT1"

#endif /* __BDK_CSRS_NCSI__ */
