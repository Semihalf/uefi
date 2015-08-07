#ifndef __BDK_CSRS_NCSI_H__
#define __BDK_CSRS_NCSI_H__
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
 * Cavium NCSI.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ncsi_bar_e
 *
 * NCSI Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_NCSI_BAR_E_NCSI_PF_BAR0 (0x87e00b000000ll) /**< Base address for standard registers. */
#define BDK_NCSI_BAR_E_NCSI_PF_BAR4 (0x87e00bf00000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration ncsi_ctl_pkt_type_e
 *
 * NCSI Control Packet Type Enumeration
 * Enumerates the control packet types. For more information see the NC-SI standard.
 */
#define BDK_NCSI_CTL_PKT_TYPE_E_AEN_EN (8) /**< AEN enable. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_CLR_INIT (0) /**< Clear initial. State used by the Management Controller to acknowledge that the Network
                                       Controller is in the initial state. */
#define BDK_NCSI_CTL_PKT_TYPE_E_DIS_BCST (0x11) /**< Disable broadcast filtering.
                                       Not implemented; software should instead use a OEM commands to modify
                                       BGX()_CMR_RX_STEERING(). */
#define BDK_NCSI_CTL_PKT_TYPE_E_DIS_CHAN (4) /**< Disable channel. Disables the NC-SI channel and to cause the forwarding of bidirectional
                                       Management Controller packets to cease. */
#define BDK_NCSI_CTL_PKT_TYPE_E_DIS_CHAN_NW (7) /**< Disable channel network TX. Disables the channel from transmitting pass-through packets
                                       onto the network. */
#define BDK_NCSI_CTL_PKT_TYPE_E_DIS_MCST (0x13) /**< Disable global multicast filtering. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_DIS_VLAN (0xd) /**< Disable VLAN.
                                       Not implemented; software should instead use a OEM commands to modify
                                       BGX()_CMR_RX_STEERING(). */
#define BDK_NCSI_CTL_PKT_TYPE_E_DSEL_PKG (2) /**< Deselect package. Instructs the controller package to stop transmitting packets through
                                       NC-SI.
                                       CNXXXX will tristate NCSI_RXD<1:0>, NCSI_RX_ER and NCSI_CRS_DV. */
#define BDK_NCSI_CTL_PKT_TYPE_E_EN_BCST (0x10) /**< Enable broadcast filtering.
                                       Not implemented; software should instead use a OEM commands to modify
                                       BGX()_CMR_RX_STEERING(). */
#define BDK_NCSI_CTL_PKT_TYPE_E_EN_CHAN (3) /**< Enable channel. Enables the NC-SI channel and to cause the forwarding of bidirectional
                                       Management Controller packets to start. */
#define BDK_NCSI_CTL_PKT_TYPE_E_EN_CHAN_NW (6) /**< Enable channel network TX. Enables the channel to transmit pass-through packets onto the network. */
#define BDK_NCSI_CTL_PKT_TYPE_E_EN_MCST (0x12) /**< Enable global multicast filtering. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_EN_VLAN (0xc) /**< Enable VLAN.
                                       Not implemented; software should instead use a OEM commands to modify
                                       BGX()_CMR_RX_STEERING(). */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_CAP (0x16) /**< Get capabilities. Get optional functions supported by the NC-SI. */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_ID (0x15) /**< Get version ID. Get controller-related version information from NCSI_RX_MFG. */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_LINK (0xa) /**< Get link. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_NCSI_STAT (0x19) /**< Get NC-SI statistics. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_PAR (0x17) /**< Get parameters. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_PASS_STAT (0x1a) /**< Get NC-SI pass-through statistics. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_GET_PKT_STAT (0x18) /**< Get controller packet statistics. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_OEM (0x50) /**< OEM command. In CNXXXX, allows access to CSRs using NCSI_CSR_OEM_CMD_S. */
#define BDK_NCSI_CTL_PKT_TYPE_E_RST_CHAN (5) /**< Reset channel. Synchronously puts the Network Controller back to the initial state. */
#define BDK_NCSI_CTL_PKT_TYPE_E_SEL_PKG (1) /**< Select package. Selects a controller package to transmit packets through NC-SI.
                                       CNXXXX will drive NCSI_RXD<1:0>, NCSI_RX_ER and NCSI_CRS_DV. */
#define BDK_NCSI_CTL_PKT_TYPE_E_SET_FLOW (0x14) /**< Set NC-SI flow control. Configure IEEE 802.3 flow control on the NC-SI. */
#define BDK_NCSI_CTL_PKT_TYPE_E_SET_LINK (9) /**< Set link. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_SET_MAC (0xe) /**< Set MAC address. Not implemented. */
#define BDK_NCSI_CTL_PKT_TYPE_E_SET_VLAN (0xb) /**< Set VLAN.
                                       Not implemented; software should instead use a OEM commands to modify
                                       BGX()_CMR_RX_STEERING(). */

/**
 * Enumeration ncsi_int_vec_e
 *
 * NCSI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_NCSI_INT_VEC_E_INTS (0) /**< See interrupt clears NCSI_INT, interrupt sets NCSI_INT_W1S, enable clears
                                       NCSI_INT_ENA_W1C, and enable sets NCSI_INT_ENA_W1S. */

/**
 * Enumeration ncsi_reason_e
 *
 * NCSI Reason Code Enumeration
 * Enumerates the NCSI standard reason codes.
 */
#define BDK_NCSI_REASON_E_CHAN (3) /**< Channel not ready. */
#define BDK_NCSI_REASON_E_INIT (1) /**< Interface initialization required. */
#define BDK_NCSI_REASON_E_NONE (0) /**< No error/no reason. */
#define BDK_NCSI_REASON_E_UNSUP (2) /**< Parameter is invalid, unsupported, or out-of-range. */

/**
 * Enumeration ncsi_resp_e
 *
 * NCSI Response Code Enumeration
 */
#define BDK_NCSI_RESP_E_COMPLETED (0) /**< Command completed. */
#define BDK_NCSI_RESP_E_CSR_READ (0x8000) /**< OEM-specific response to OEM CSR read. */
#define BDK_NCSI_RESP_E_CSR_WRITE (0x8001) /**< OEM-specific response to OEM CSR write. */
#define BDK_NCSI_RESP_E_FAILED (1) /**< Command failed. */
#define BDK_NCSI_RESP_E_UNAVAIL (2) /**< Command unavailable. */
#define BDK_NCSI_RESP_E_UNSUP (3) /**< Command unsupported. */

/**
 * Register (RSL) ncsi_bmc2cpu_msg
 *
 * NCSI BMC to CPU Message Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_bmc2cpu_msg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t msg                   : 64; /**< [ 63:  0](R/W) Data to communicate between BMC and CPU. Provides a mechanism for BMC to signal
                                                                 to the CPU. CPU SW and BMC firmware must agree on the messaging definition which
                                                                 is beyond the scope of this register definition.

                                                                 When this register is written, NCSI_INT[BMC2CPU] is set.
                                                                 INTERNAL: Interrupt is CN88XX pass 2 only, bug21942. */
#else /* Word 0 - Little Endian */
        uint64_t msg                   : 64; /**< [ 63:  0](R/W) Data to communicate between BMC and CPU. Provides a mechanism for BMC to signal
                                                                 to the CPU. CPU SW and BMC firmware must agree on the messaging definition which
                                                                 is beyond the scope of this register definition.

                                                                 When this register is written, NCSI_INT[BMC2CPU] is set.
                                                                 INTERNAL: Interrupt is CN88XX pass 2 only, bug21942. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_bmc2cpu_msg_s cn; */
} bdk_ncsi_bmc2cpu_msg_t;

#define BDK_NCSI_BMC2CPU_MSG BDK_NCSI_BMC2CPU_MSG_FUNC()
static inline uint64_t BDK_NCSI_BMC2CPU_MSG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_BMC2CPU_MSG_FUNC(void)
{
    return 0x87e00b000108ll;
}

#define typedef_BDK_NCSI_BMC2CPU_MSG bdk_ncsi_bmc2cpu_msg_t
#define bustype_BDK_NCSI_BMC2CPU_MSG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_BMC2CPU_MSG "NCSI_BMC2CPU_MSG"
#define busnum_BDK_NCSI_BMC2CPU_MSG 0
#define arguments_BDK_NCSI_BMC2CPU_MSG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_config
 *
 * NCSI Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t pkg_id                : 3;  /**< [  4:  2](R/W/H) Override the NCSI package id
                                                                 which defaults to the global node ID.  MSB must be set to 0
                                                                 for NCSI V1.0 compliance.
                                                                 Added in pass 2. */
        uint64_t pkg_desel_tx_ch_dis   : 1;  /**< [  1:  1](R/W) This bit controls whether the NCSI will disable the TX_CH upon pkg deselect command.
                                                                 0 = On pkg deselect command, keep TX channel enabled, enabling pass through traffic to
                                                                 BGX.
                                                                 1 = On pkg deselect command, disable TX channel preventing pass through traffic to BGX. */
        uint64_t cam_accept            : 1;  /**< [  0:  0](R/W) Allow or deny SMAC address filter.  Applies to both SMAC filters in the CAM.
                                                                 See NCSI_TX_FRM_SMAC()_CAM for additional details.
                                                                 0 = Reject the packet on SMAC CAM address match.
                                                                 1 = Accept the packet on SMAC CAM address match. */
#else /* Word 0 - Little Endian */
        uint64_t cam_accept            : 1;  /**< [  0:  0](R/W) Allow or deny SMAC address filter.  Applies to both SMAC filters in the CAM.
                                                                 See NCSI_TX_FRM_SMAC()_CAM for additional details.
                                                                 0 = Reject the packet on SMAC CAM address match.
                                                                 1 = Accept the packet on SMAC CAM address match. */
        uint64_t pkg_desel_tx_ch_dis   : 1;  /**< [  1:  1](R/W) This bit controls whether the NCSI will disable the TX_CH upon pkg deselect command.
                                                                 0 = On pkg deselect command, keep TX channel enabled, enabling pass through traffic to
                                                                 BGX.
                                                                 1 = On pkg deselect command, disable TX channel preventing pass through traffic to BGX. */
        uint64_t pkg_id                : 3;  /**< [  4:  2](R/W/H) Override the NCSI package id
                                                                 which defaults to the global node ID.  MSB must be set to 0
                                                                 for NCSI V1.0 compliance.
                                                                 Added in pass 2. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_config_s cn83xx; */
    /* struct bdk_ncsi_config_s cn88xxp2; */
    struct bdk_ncsi_config_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t pkg_id                : 3;  /**< [  4:  2](RAZ) Reserved. */
        uint64_t pkg_desel_tx_ch_dis   : 1;  /**< [  1:  1](R/W) This bit controls whether the NCSI will disable the TX_CH upon pkg deselect command.
                                                                 0 = On pkg deselect command, keep TX channel enabled, enabling pass through traffic to
                                                                 BGX.
                                                                 1 = On pkg deselect command, disable TX channel preventing pass through traffic to BGX. */
        uint64_t cam_accept            : 1;  /**< [  0:  0](R/W) Allow or deny SMAC address filter.  Applies to both SMAC filters in the CAM.
                                                                 See NCSI_TX_FRM_SMAC()_CAM for additional details.
                                                                 0 = Reject the packet on SMAC CAM address match.
                                                                 1 = Accept the packet on SMAC CAM address match. */
#else /* Word 0 - Little Endian */
        uint64_t cam_accept            : 1;  /**< [  0:  0](R/W) Allow or deny SMAC address filter.  Applies to both SMAC filters in the CAM.
                                                                 See NCSI_TX_FRM_SMAC()_CAM for additional details.
                                                                 0 = Reject the packet on SMAC CAM address match.
                                                                 1 = Accept the packet on SMAC CAM address match. */
        uint64_t pkg_desel_tx_ch_dis   : 1;  /**< [  1:  1](R/W) This bit controls whether the NCSI will disable the TX_CH upon pkg deselect command.
                                                                 0 = On pkg deselect command, keep TX channel enabled, enabling pass through traffic to
                                                                 BGX.
                                                                 1 = On pkg deselect command, disable TX channel preventing pass through traffic to BGX. */
        uint64_t pkg_id                : 3;  /**< [  4:  2](RAZ) Reserved. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_ncsi_config_t;

#define BDK_NCSI_CONFIG BDK_NCSI_CONFIG_FUNC()
static inline uint64_t BDK_NCSI_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_CONFIG_FUNC(void)
{
    return 0x87e00b000110ll;
}

#define typedef_BDK_NCSI_CONFIG bdk_ncsi_config_t
#define bustype_BDK_NCSI_CONFIG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_CONFIG "NCSI_CONFIG"
#define busnum_BDK_NCSI_CONFIG 0
#define arguments_BDK_NCSI_CONFIG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_cpu2bmc_msg
 *
 * NCSI CPU to BMC Message Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_cpu2bmc_msg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t msg                   : 64; /**< [ 63:  0](R/W) Data to communicate between CPU and BMC. Provides a mechanism for CPU to signal
                                                                 to the BMC. CPU SW and BMC firmware must agree on the messaging definition which
                                                                 is beyond the scope of this register definition. */
#else /* Word 0 - Little Endian */
        uint64_t msg                   : 64; /**< [ 63:  0](R/W) Data to communicate between CPU and BMC. Provides a mechanism for CPU to signal
                                                                 to the BMC. CPU SW and BMC firmware must agree on the messaging definition which
                                                                 is beyond the scope of this register definition. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_cpu2bmc_msg_s cn; */
} bdk_ncsi_cpu2bmc_msg_t;

#define BDK_NCSI_CPU2BMC_MSG BDK_NCSI_CPU2BMC_MSG_FUNC()
static inline uint64_t BDK_NCSI_CPU2BMC_MSG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_CPU2BMC_MSG_FUNC(void)
{
    return 0x87e00b000100ll;
}

#define typedef_BDK_NCSI_CPU2BMC_MSG bdk_ncsi_cpu2bmc_msg_t
#define bustype_BDK_NCSI_CPU2BMC_MSG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_CPU2BMC_MSG "NCSI_CPU2BMC_MSG"
#define busnum_BDK_NCSI_CPU2BMC_MSG 0
#define arguments_BDK_NCSI_CPU2BMC_MSG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_int
 *
 * NCSI Memory Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Messaging interrupt set whenever NCSI_BMC2CPU_MSG is written by the BMC. Added in pass 2. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) RX RSP FIFO overflow. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) RX RSP FIFO single-bit error. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) RX RSP FIFO double-bit error. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) RX PMAC FIFO single-bit error. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) RX PMAC FIFO double-bit error. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) TX MIX FIFO overflow. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) TX MIX FIFO single-bit error. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) TX MIX FIFO double-bit error. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Frame received without a proper L2 header needed for NCSI command detection. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Interframe gap violation. Does not necessarily indicate a failure. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) System-length error. Frame was received with length > sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) System-length error. Frame was received with length > sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Interframe gap violation. Does not necessarily indicate a failure. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Frame received without a proper L2 header needed for NCSI command detection. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) TX MIX FIFO double-bit error. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) TX MIX FIFO single-bit error. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) TX MIX FIFO overflow. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) RX PMAC FIFO double-bit error. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) RX PMAC FIFO single-bit error. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) RX RSP FIFO double-bit error. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) RX RSP FIFO single-bit error. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) RX RSP FIFO overflow. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Messaging interrupt set whenever NCSI_BMC2CPU_MSG is written by the BMC. Added in pass 2. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_int_s cn83xx; */
    /* struct bdk_ncsi_int_s cn88xxp2; */
    struct bdk_ncsi_int_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Reserved. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) RX RSP FIFO overflow. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) RX RSP FIFO single-bit error. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) RX RSP FIFO double-bit error. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) RX PMAC FIFO single-bit error. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) RX PMAC FIFO double-bit error. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) TX MIX FIFO overflow. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) TX MIX FIFO single-bit error. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) TX MIX FIFO double-bit error. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Frame received without a proper L2 header needed for NCSI command detection. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Interframe gap violation. Does not necessarily indicate a failure. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) System-length error. Frame was received with length > sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) System-length error. Frame was received with length > sys_length. A jabber error
                                                                 indicates that a packet was received from RMII interface which is longer than the maximum
                                                                 allowed packet as defined by the system. NCSI truncates the packet at the JABBER count+1
                                                                 bytes. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Pass through received FCS/CRC error. Frame was received with FCS/CRC error.
                                                                 FCSERR indication takes precedence over JABBER error. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) NCSI command received with FCS/CRC error. Frame was received with FCS/CRC error. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Interframe gap violation. Does not necessarily indicate a failure. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Frame received without a proper L2 header needed for NCSI command detection. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) TX MIX FIFO double-bit error. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) TX MIX FIFO single-bit error. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) TX MIX FIFO overflow. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) RX PMAC FIFO double-bit error. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) RX PMAC FIFO single-bit error. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Underflow through RX PMAC path.  Fifo drained on a non-packet boundary */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) RX RSP FIFO double-bit error. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) RX RSP FIFO single-bit error. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) RX RSP FIFO overflow. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Reserved. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_ncsi_int_t;

#define BDK_NCSI_INT BDK_NCSI_INT_FUNC()
static inline uint64_t BDK_NCSI_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_FUNC(void)
{
    return 0x87e00b000000ll;
}

#define typedef_BDK_NCSI_INT bdk_ncsi_int_t
#define bustype_BDK_NCSI_INT BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_INT "NCSI_INT"
#define busnum_BDK_NCSI_INT 0
#define arguments_BDK_NCSI_INT -1,-1,-1,-1

/**
 * Register (RSL) ncsi_int_ena_w1c
 *
 * NCSI Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Added in pass 2.0. Reads or clears enable for NCSI_INT[BMC2CPU]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for NCSI_INT[RUNTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for NCSI_INT[IFGERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for NCSI_INT[PCTERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for NCSI_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for NCSI_INT[JABBER]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for NCSI_INT[PCTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for NCSI_INT[IFGERR]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for NCSI_INT[RUNTERR]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Added in pass 2.0. Reads or clears enable for NCSI_INT[BMC2CPU]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_int_ena_w1c_s cn83xx; */
    /* struct bdk_ncsi_int_ena_w1c_s cn88xxp2; */
    struct bdk_ncsi_int_ena_w1c_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for NCSI_INT[BMC2CPU]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for NCSI_INT[RUNTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for NCSI_INT[IFGERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for NCSI_INT[PCTERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for NCSI_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for NCSI_INT[JABBER]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for NCSI_INT[PCTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for NCSI_INT[IFGERR]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for NCSI_INT[RUNTERR]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for NCSI_INT[BMC2CPU]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_ncsi_int_ena_w1c_t;

#define BDK_NCSI_INT_ENA_W1C BDK_NCSI_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_NCSI_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_ENA_W1C_FUNC(void)
{
    return 0x87e00b000018ll;
}

#define typedef_BDK_NCSI_INT_ENA_W1C bdk_ncsi_int_ena_w1c_t
#define bustype_BDK_NCSI_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_INT_ENA_W1C "NCSI_INT_ENA_W1C"
#define busnum_BDK_NCSI_INT_ENA_W1C 0
#define arguments_BDK_NCSI_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) ncsi_int_ena_w1s
 *
 * NCSI Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Added in pass 2.0. Reads or sets enable for NCSI_INT[BMC2CPU]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for NCSI_INT[RUNTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for NCSI_INT[IFGERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for NCSI_INT[PCTERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for NCSI_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for NCSI_INT[JABBER]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for NCSI_INT[PCTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for NCSI_INT[IFGERR]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for NCSI_INT[RUNTERR]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Added in pass 2.0. Reads or sets enable for NCSI_INT[BMC2CPU]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_int_ena_w1s_s cn83xx; */
    /* struct bdk_ncsi_int_ena_w1s_s cn88xxp2; */
    struct bdk_ncsi_int_ena_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for NCSI_INT[BMC2CPU]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for NCSI_INT[RUNTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for NCSI_INT[IFGERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for NCSI_INT[PCTERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for NCSI_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for NCSI_INT[JABBER]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for NCSI_INT[PMAC_FCSERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for NCSI_INT[NCP_FCSERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for NCSI_INT[PCTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for NCSI_INT[IFGERR]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for NCSI_INT[RUNTERR]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_DBE]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_DBE]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for NCSI_INT[BMC2CPU]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_ncsi_int_ena_w1s_t;

#define BDK_NCSI_INT_ENA_W1S BDK_NCSI_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_NCSI_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_ENA_W1S_FUNC(void)
{
    return 0x87e00b000010ll;
}

#define typedef_BDK_NCSI_INT_ENA_W1S bdk_ncsi_int_ena_w1s_t
#define bustype_BDK_NCSI_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_INT_ENA_W1S "NCSI_INT_ENA_W1S"
#define busnum_BDK_NCSI_INT_ENA_W1S 0
#define arguments_BDK_NCSI_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) ncsi_int_w1s
 *
 * NCSI Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Added in pass 2.0. Reads or sets NCSI_INT[BMC2CPU]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_DBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_DBE]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets NCSI_INT[RUNTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets NCSI_INT[IFGERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets NCSI_INT[PCTERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets NCSI_INT[NCP_FCSERR]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets NCSI_INT[PMAC_FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets NCSI_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets NCSI_INT[JABBER]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets NCSI_INT[PMAC_FCSERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets NCSI_INT[NCP_FCSERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets NCSI_INT[PCTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets NCSI_INT[IFGERR]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets NCSI_INT[RUNTERR]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_DBE]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_DBE]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Added in pass 2.0. Reads or sets NCSI_INT[BMC2CPU]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_int_w1s_s cn83xx; */
    /* struct bdk_ncsi_int_w1s_s cn88xxp2; */
    struct bdk_ncsi_int_w1s_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets NCSI_INT[BMC2CPU]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_DBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_DBE]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets NCSI_INT[RUNTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets NCSI_INT[IFGERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets NCSI_INT[PCTERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets NCSI_INT[NCP_FCSERR]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets NCSI_INT[PMAC_FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets NCSI_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets NCSI_INT[JABBER]. */
        uint64_t pmac_fcserr           : 1;  /**< [  1:  1](R/W1S/H) Reads or sets NCSI_INT[PMAC_FCSERR]. */
        uint64_t ncp_fcserr            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets NCSI_INT[NCP_FCSERR]. */
        uint64_t pcterr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets NCSI_INT[PCTERR]. */
        uint64_t ifgerr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets NCSI_INT[IFGERR]. */
        uint64_t runterr               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets NCSI_INT[RUNTERR]. */
        uint64_t tx_mix_dbe            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_DBE]. */
        uint64_t tx_mix_sbe            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_SBE]. */
        uint64_t tx_mix_overfl         : 1;  /**< [  8:  8](R/W1S/H) Reads or sets NCSI_INT[TX_MIX_OVERFL]. */
        uint64_t rx_pmac_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_DBE]. */
        uint64_t rx_pmac_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_SBE]. */
        uint64_t rx_pmac_underfl       : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets NCSI_INT[RX_PMAC_UNDERFL]. */
        uint64_t rx_rsp_dbe            : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_DBE]. */
        uint64_t rx_rsp_sbe            : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_SBE]. */
        uint64_t rx_rsp_overfl         : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets NCSI_INT[RX_RSP_OVERFL]. */
        uint64_t bmc2cpu               : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets NCSI_INT[BMC2CPU]. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_ncsi_int_w1s_t;

#define BDK_NCSI_INT_W1S BDK_NCSI_INT_W1S_FUNC()
static inline uint64_t BDK_NCSI_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_INT_W1S_FUNC(void)
{
    return 0x87e00b000008ll;
}

#define typedef_BDK_NCSI_INT_W1S bdk_ncsi_int_w1s_t
#define bustype_BDK_NCSI_INT_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_INT_W1S "NCSI_INT_W1S"
#define busnum_BDK_NCSI_INT_W1S 0
#define arguments_BDK_NCSI_INT_W1S -1,-1,-1,-1

/**
 * Register (RSL) ncsi_mem_ctrl
 *
 * NCSI Memory Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_mem_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t rx_rsp_synd           : 2;  /**< [  8:  7](R/W) Syndrome to flip and generate single-bit/double-bit for RX RSP FIFO. */
        uint64_t rx_rsp_cor_dis        : 1;  /**< [  6:  6](R/W) ECC-correction disable for the RX RSP FIFO. */
        uint64_t rx_pmac_synd          : 2;  /**< [  5:  4](R/W) Syndrome to flip and generate single-bit/double-bit for RX PMAC FIFO. */
        uint64_t rx_pmac_cor_dis       : 1;  /**< [  3:  3](R/W) ECC-correction disable for the RX PMAC FIFO. */
        uint64_t tx_mix_synd           : 2;  /**< [  2:  1](R/W) Syndrome to flip and generate single-bit/double-bit for TX MIX_FIFO. */
        uint64_t tx_mix_cor_dis        : 1;  /**< [  0:  0](R/W) ECC-correction disable for the TX MIX FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t tx_mix_cor_dis        : 1;  /**< [  0:  0](R/W) ECC-correction disable for the TX MIX FIFO. */
        uint64_t tx_mix_synd           : 2;  /**< [  2:  1](R/W) Syndrome to flip and generate single-bit/double-bit for TX MIX_FIFO. */
        uint64_t rx_pmac_cor_dis       : 1;  /**< [  3:  3](R/W) ECC-correction disable for the RX PMAC FIFO. */
        uint64_t rx_pmac_synd          : 2;  /**< [  5:  4](R/W) Syndrome to flip and generate single-bit/double-bit for RX PMAC FIFO. */
        uint64_t rx_rsp_cor_dis        : 1;  /**< [  6:  6](R/W) ECC-correction disable for the RX RSP FIFO. */
        uint64_t rx_rsp_synd           : 2;  /**< [  8:  7](R/W) Syndrome to flip and generate single-bit/double-bit for RX RSP FIFO. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_mem_ctrl_s cn; */
} bdk_ncsi_mem_ctrl_t;

#define BDK_NCSI_MEM_CTRL BDK_NCSI_MEM_CTRL_FUNC()
static inline uint64_t BDK_NCSI_MEM_CTRL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MEM_CTRL_FUNC(void)
{
    return 0x87e00b000118ll;
}

#define typedef_BDK_NCSI_MEM_CTRL bdk_ncsi_mem_ctrl_t
#define bustype_BDK_NCSI_MEM_CTRL BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_MEM_CTRL "NCSI_MEM_CTRL"
#define busnum_BDK_NCSI_MEM_CTRL 0
#define arguments_BDK_NCSI_MEM_CTRL -1,-1,-1,-1

/**
 * Register (RSL) ncsi_msix_pba#
 *
 * NCSI MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the NCSI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated NCSI_MSIX_VEC()_CTL, enumerated by NCSI_INT_VEC_E.
                                                                 Bits that have no associated NCSI_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated NCSI_MSIX_VEC()_CTL, enumerated by NCSI_INT_VEC_E.
                                                                 Bits that have no associated NCSI_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_msix_pbax_s cn; */
} bdk_ncsi_msix_pbax_t;

static inline uint64_t BDK_NCSI_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MSIX_PBAX(unsigned long a)
{
    if (a==0)
        return 0x87e00bff0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("NCSI_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_NCSI_MSIX_PBAX(a) bdk_ncsi_msix_pbax_t
#define bustype_BDK_NCSI_MSIX_PBAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_MSIX_PBAX(a) "NCSI_MSIX_PBAX"
#define busnum_BDK_NCSI_MSIX_PBAX(a) (a)
#define arguments_BDK_NCSI_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) ncsi_msix_vec#_addr
 *
 * NCSI MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the NCSI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's NCSI_MSIX_VEC()_ADDR, NCSI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of NCSI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_NCSI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's NCSI_MSIX_VEC()_ADDR, NCSI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of NCSI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_NCSI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_msix_vecx_addr_s cn; */
} bdk_ncsi_msix_vecx_addr_t;

static inline uint64_t BDK_NCSI_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MSIX_VECX_ADDR(unsigned long a)
{
    if (a==0)
        return 0x87e00bf00000ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("NCSI_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_NCSI_MSIX_VECX_ADDR(a) bdk_ncsi_msix_vecx_addr_t
#define bustype_BDK_NCSI_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_MSIX_VECX_ADDR(a) "NCSI_MSIX_VECX_ADDR"
#define busnum_BDK_NCSI_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_NCSI_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) ncsi_msix_vec#_ctl
 *
 * NCSI MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the NCSI_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_msix_vecx_ctl_s
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
    /* struct bdk_ncsi_msix_vecx_ctl_s cn; */
} bdk_ncsi_msix_vecx_ctl_t;

static inline uint64_t BDK_NCSI_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_MSIX_VECX_CTL(unsigned long a)
{
    if (a==0)
        return 0x87e00bf00008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("NCSI_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_NCSI_MSIX_VECX_CTL(a) bdk_ncsi_msix_vecx_ctl_t
#define bustype_BDK_NCSI_MSIX_VECX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_MSIX_VECX_CTL(a) "NCSI_MSIX_VECX_CTL"
#define busnum_BDK_NCSI_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_NCSI_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) ncsi_rx_frm_ctl
 *
 * NCSI RX Frame Control Registers
 * This register should be set in coordination with BGX registers that control similar
 * parameters.
 * If NCSI should is configured to prepend preamble and postpend FCS, then these should be
 * stripped
 * by BGX.  If NCSI is configured not to prepend preamble and postpend FCS, then BGX should not
 * be stripping these values.
 * Practically speaking, preamble and FCS should be set together.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_frm_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t fcs                   : 1;  /**< [  2:  2](R/W) Append the Ethernet FCS on each pass through packet going to RMII. */
        uint64_t pad                   : 1;  /**< [  1:  1](R/W) Append PAD bytes such that minimum-sized pass through packet is sent over RMII. FCS will
                                                                 be appended in this case by default. */
        uint64_t preamble              : 1;  /**< [  0:  0](R/W) Prepend the Ethernet preamble on each pass through transfer over RMII */
#else /* Word 0 - Little Endian */
        uint64_t preamble              : 1;  /**< [  0:  0](R/W) Prepend the Ethernet preamble on each pass through transfer over RMII */
        uint64_t pad                   : 1;  /**< [  1:  1](R/W) Append PAD bytes such that minimum-sized pass through packet is sent over RMII. FCS will
                                                                 be appended in this case by default. */
        uint64_t fcs                   : 1;  /**< [  2:  2](R/W) Append the Ethernet FCS on each pass through packet going to RMII. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_frm_ctl_s cn; */
} bdk_ncsi_rx_frm_ctl_t;

#define BDK_NCSI_RX_FRM_CTL BDK_NCSI_RX_FRM_CTL_FUNC()
static inline uint64_t BDK_NCSI_RX_FRM_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_FRM_CTL_FUNC(void)
{
    return 0x87e00b000508ll;
}

#define typedef_BDK_NCSI_RX_FRM_CTL bdk_ncsi_rx_frm_ctl_t
#define bustype_BDK_NCSI_RX_FRM_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_FRM_CTL "NCSI_RX_FRM_CTL"
#define busnum_BDK_NCSI_RX_FRM_CTL 0
#define arguments_BDK_NCSI_RX_FRM_CTL -1,-1,-1,-1

/**
 * Register (RSL) ncsi_rx_ifg
 *
 * NCSI RX Interframe-Gap Cycles Registers
 * Interframe gap between packets going out on the RMII interface.
 * For IEEE 802.3 compatibility, IFG1 must be in the range of 1-11, IFG2 must be in the range
 * of 1-11, and the IFG1 + IFG2 sum must be 12 resulting in 96 bit times.
 * For all other systems, IFG1 and IFG2 can be any value in the range of 1-15, allowing for a
 * total possible IFG sum of 2 minimum and 30 maximum.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_ifg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ifg2                  : 4;  /**< [  7:  4](R/W) Remainder of interFrameGap timing, equal to interFrameGap - IFG1 (in IFG2 * 8 bits). A
                                                                 value of 4 sets an IFG2 of 32 bit times appropriate for 802.3 compliance. */
        uint64_t ifg1                  : 4;  /**< [  3:  0](R/W) First portion of interFrameGap timing, (in IFG1 * 8 bits). A value of 8 sets an IFG1 of 64
                                                                 bit times appropriate for 802.3 compliance. */
#else /* Word 0 - Little Endian */
        uint64_t ifg1                  : 4;  /**< [  3:  0](R/W) First portion of interFrameGap timing, (in IFG1 * 8 bits). A value of 8 sets an IFG1 of 64
                                                                 bit times appropriate for 802.3 compliance. */
        uint64_t ifg2                  : 4;  /**< [  7:  4](R/W) Remainder of interFrameGap timing, equal to interFrameGap - IFG1 (in IFG2 * 8 bits). A
                                                                 value of 4 sets an IFG2 of 32 bit times appropriate for 802.3 compliance. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_ifg_s cn; */
} bdk_ncsi_rx_ifg_t;

#define BDK_NCSI_RX_IFG BDK_NCSI_RX_IFG_FUNC()
static inline uint64_t BDK_NCSI_RX_IFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_IFG_FUNC(void)
{
    return 0x87e00b000518ll;
}

#define typedef_BDK_NCSI_RX_IFG bdk_ncsi_rx_ifg_t
#define bustype_BDK_NCSI_RX_IFG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_IFG "NCSI_RX_IFG"
#define busnum_BDK_NCSI_RX_IFG 0
#define arguments_BDK_NCSI_RX_IFG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_rx_mfg
 *
 * NCSI RX Manufacturer ID Register
 * This register sets the manufacturer ID.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_mfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t id                    : 32; /**< [ 31:  0](R/W) Manufacturer ID to place in the NCSI OEM and GET_ID response packets.
                                                                 The value should not conflict with the existing vendor enterprise numbers in the
                                                                 IANA database. For commands on the TX side, the incoming OEM command mfg id entry
                                                                 will go unchecked since the package and channel fields of the NCSI header are
                                                                 sufficient to address the network controller. */
#else /* Word 0 - Little Endian */
        uint64_t id                    : 32; /**< [ 31:  0](R/W) Manufacturer ID to place in the NCSI OEM and GET_ID response packets.
                                                                 The value should not conflict with the existing vendor enterprise numbers in the
                                                                 IANA database. For commands on the TX side, the incoming OEM command mfg id entry
                                                                 will go unchecked since the package and channel fields of the NCSI header are
                                                                 sufficient to address the network controller. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_mfg_s cn; */
} bdk_ncsi_rx_mfg_t;

#define BDK_NCSI_RX_MFG BDK_NCSI_RX_MFG_FUNC()
static inline uint64_t BDK_NCSI_RX_MFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_MFG_FUNC(void)
{
    return 0x87e00b000520ll;
}

#define typedef_BDK_NCSI_RX_MFG bdk_ncsi_rx_mfg_t
#define bustype_BDK_NCSI_RX_MFG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_MFG "NCSI_RX_MFG"
#define busnum_BDK_NCSI_RX_MFG 0
#define arguments_BDK_NCSI_RX_MFG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_rx_min_pkt
 *
 * NCSI RX Minimum-Size-Packet Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_min_pkt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t min_size              : 6;  /**< [  5:  0](R/W) Minimum frame size in bytes before the FCS is applied for packets going to the RMII
                                                                 interface and does not include Preamble/SFD. Padding is only appended when
                                                                 NCSI_RX_FRM_CTL[PAD] set.
                                                                 The reset value pads to 60 bytes. */
#else /* Word 0 - Little Endian */
        uint64_t min_size              : 6;  /**< [  5:  0](R/W) Minimum frame size in bytes before the FCS is applied for packets going to the RMII
                                                                 interface and does not include Preamble/SFD. Padding is only appended when
                                                                 NCSI_RX_FRM_CTL[PAD] set.
                                                                 The reset value pads to 60 bytes. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_min_pkt_s cn; */
} bdk_ncsi_rx_min_pkt_t;

#define BDK_NCSI_RX_MIN_PKT BDK_NCSI_RX_MIN_PKT_FUNC()
static inline uint64_t BDK_NCSI_RX_MIN_PKT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_MIN_PKT_FUNC(void)
{
    return 0x87e00b000510ll;
}

#define typedef_BDK_NCSI_RX_MIN_PKT bdk_ncsi_rx_min_pkt_t
#define bustype_BDK_NCSI_RX_MIN_PKT BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_MIN_PKT "NCSI_RX_MIN_PKT"
#define busnum_BDK_NCSI_RX_MIN_PKT 0
#define arguments_BDK_NCSI_RX_MIN_PKT -1,-1,-1,-1

/**
 * Register (RSL) ncsi_rx_stat0
 *
 * NCSI RX Statistics Register 0
 * This register provides a count of valid packets through the recieve side NCSI at the output of
 * the recieve side buffers.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of packets through the rx-side NCSI. This includes both pass through and response
                                                                 packets and does not include those
                                                                 stored in the fifo waiting to be dequeued. CNT will wrap and is cleared if NCSI is
                                                                 disabled with NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of packets through the rx-side NCSI. This includes both pass through and response
                                                                 packets and does not include those
                                                                 stored in the fifo waiting to be dequeued. CNT will wrap and is cleared if NCSI is
                                                                 disabled with NCSI_SECURE_CONFIG[NCSIEN]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_stat0_s cn; */
} bdk_ncsi_rx_stat0_t;

#define BDK_NCSI_RX_STAT0 BDK_NCSI_RX_STAT0_FUNC()
static inline uint64_t BDK_NCSI_RX_STAT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_STAT0_FUNC(void)
{
    return 0x87e00b000600ll;
}

#define typedef_BDK_NCSI_RX_STAT0 bdk_ncsi_rx_stat0_t
#define bustype_BDK_NCSI_RX_STAT0 BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_STAT0 "NCSI_RX_STAT0"
#define busnum_BDK_NCSI_RX_STAT0 0
#define arguments_BDK_NCSI_RX_STAT0 -1,-1,-1,-1

/**
 * Register (RSL) ncsi_rx_stat1
 *
 * NCSI RX Statistics Register 1
 * This register provides a count of valid bytes through the recieve side NCSI at the output of
 * the recieve side buffers. During underflow situations the count may deviate from the
 * the number of bytes that appear on the RMII interface.  This is due to the fact the design
 * does not deassert CRS_DV during underflow situations until the packet boundary is detected.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of valid bytes through the RX-side NCSI.  This includes both pass through and
                                                                 response packet bytes and does not include those stored in the FIFO waiting to be
                                                                 dequeued. CNT will wrap and is cleared if NCSI is disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of valid bytes through the RX-side NCSI.  This includes both pass through and
                                                                 response packet bytes and does not include those stored in the FIFO waiting to be
                                                                 dequeued. CNT will wrap and is cleared if NCSI is disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_stat1_s cn; */
} bdk_ncsi_rx_stat1_t;

#define BDK_NCSI_RX_STAT1 BDK_NCSI_RX_STAT1_FUNC()
static inline uint64_t BDK_NCSI_RX_STAT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_STAT1_FUNC(void)
{
    return 0x87e00b000608ll;
}

#define typedef_BDK_NCSI_RX_STAT1 bdk_ncsi_rx_stat1_t
#define bustype_BDK_NCSI_RX_STAT1 BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_STAT1 "NCSI_RX_STAT1"
#define busnum_BDK_NCSI_RX_STAT1 0
#define arguments_BDK_NCSI_RX_STAT1 -1,-1,-1,-1

/**
 * Register (RSL) ncsi_rx_thresh
 *
 * NCSI RX Threshold Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_rx_thresh_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t cnt                   : 11; /**< [ 10:  0](R/W) Number of bytes to accumulate in the RX FIFO before sending on the RMII
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 11; /**< [ 10:  0](R/W) Number of bytes to accumulate in the RX FIFO before sending on the RMII
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_rx_thresh_s cn; */
} bdk_ncsi_rx_thresh_t;

#define BDK_NCSI_RX_THRESH BDK_NCSI_RX_THRESH_FUNC()
static inline uint64_t BDK_NCSI_RX_THRESH_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_RX_THRESH_FUNC(void)
{
    return 0x87e00b000500ll;
}

#define typedef_BDK_NCSI_RX_THRESH bdk_ncsi_rx_thresh_t
#define bustype_BDK_NCSI_RX_THRESH BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_RX_THRESH "NCSI_RX_THRESH"
#define busnum_BDK_NCSI_RX_THRESH 0
#define arguments_BDK_NCSI_RX_THRESH -1,-1,-1,-1

/**
 * Register (RSL) ncsi_secure_config
 *
 * NCSI Secure Configuration Register
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_secure_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ncsien                : 1;  /**< [  1:  1](SR/W) Master enable for the NCSI block. */
        uint64_t ncsisecen             : 1;  /**< [  0:  0](SR/W) For BMC access using the OEM command, allow or deny secure access into CNXXXX.
                                                                 Also see NCSI_TX_NCP_PERM()_TABLE.
                                                                 0 = OEM command address must pass the permision table filter before being forwarded to the
                                                                 MRML. Access to NCSI_CPU2BMC_MSG and NCSI_BMC2CPU_MSG are always allowed.
                                                                 1 = Bypass the permissions table and allow any secure or non-secure register access
                                                                 in the RSL address space. */
#else /* Word 0 - Little Endian */
        uint64_t ncsisecen             : 1;  /**< [  0:  0](SR/W) For BMC access using the OEM command, allow or deny secure access into CNXXXX.
                                                                 Also see NCSI_TX_NCP_PERM()_TABLE.
                                                                 0 = OEM command address must pass the permision table filter before being forwarded to the
                                                                 MRML. Access to NCSI_CPU2BMC_MSG and NCSI_BMC2CPU_MSG are always allowed.
                                                                 1 = Bypass the permissions table and allow any secure or non-secure register access
                                                                 in the RSL address space. */
        uint64_t ncsien                : 1;  /**< [  1:  1](SR/W) Master enable for the NCSI block. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_secure_config_s cn; */
} bdk_ncsi_secure_config_t;

#define BDK_NCSI_SECURE_CONFIG BDK_NCSI_SECURE_CONFIG_FUNC()
static inline uint64_t BDK_NCSI_SECURE_CONFIG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_SECURE_CONFIG_FUNC(void)
{
    return 0x87e00b000800ll;
}

#define typedef_BDK_NCSI_SECURE_CONFIG bdk_ncsi_secure_config_t
#define bustype_BDK_NCSI_SECURE_CONFIG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_SECURE_CONFIG "NCSI_SECURE_CONFIG"
#define busnum_BDK_NCSI_SECURE_CONFIG 0
#define arguments_BDK_NCSI_SECURE_CONFIG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_frm_ctl
 *
 * NCSI TX Frame Control Registers
 * Frame control register for packets coming in from the RMII interface.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_frm_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t fcs_strp              : 1;  /**< [  4:  4](R/W) Strip off the FCS for pass through packets.
                                                                 0 = FCS is not removed from the pass through packets.
                                                                 1 = FCS is removed from the pass through packets.

                                                                 Added in pass 2. */
        uint64_t pre_strp              : 1;  /**< [  3:  3](R/W) Strip off the PREAMBLE and SFD:
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.

                                                                 PRE_STRP determines if the PREAMBLE+SFD bytes are thrown away or sent to the core as part
                                                                 of the packet. With either setting, the PREAMBLE+SFD bytes are not counted toward the
                                                                 packet size when checking against the MIN and MAX bounds. Furthermore, the bytes are
                                                                 skipped when locating the start of the L2 header for DMAC recognition. */
        uint64_t pre_chk_len           : 3;  /**< [  2:  0](R/W) Check that a correct preamble of a given length is present.

                                                                 With a setting of > 0, NCSI checks that a valid PREAMBLE is received and of the
                                                                 corresponding length in bytes.
                                                                 If a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The NCSI_INT[PCTERR] interrupt is also raised.

                                                                 With a setting of 0, NCSI checks the first byte is an valid SFD symbol and not a PREAMBLE
                                                                 symbol. */
#else /* Word 0 - Little Endian */
        uint64_t pre_chk_len           : 3;  /**< [  2:  0](R/W) Check that a correct preamble of a given length is present.

                                                                 With a setting of > 0, NCSI checks that a valid PREAMBLE is received and of the
                                                                 corresponding length in bytes.
                                                                 If a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The NCSI_INT[PCTERR] interrupt is also raised.

                                                                 With a setting of 0, NCSI checks the first byte is an valid SFD symbol and not a PREAMBLE
                                                                 symbol. */
        uint64_t pre_strp              : 1;  /**< [  3:  3](R/W) Strip off the PREAMBLE and SFD:
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.

                                                                 PRE_STRP determines if the PREAMBLE+SFD bytes are thrown away or sent to the core as part
                                                                 of the packet. With either setting, the PREAMBLE+SFD bytes are not counted toward the
                                                                 packet size when checking against the MIN and MAX bounds. Furthermore, the bytes are
                                                                 skipped when locating the start of the L2 header for DMAC recognition. */
        uint64_t fcs_strp              : 1;  /**< [  4:  4](R/W) Strip off the FCS for pass through packets.
                                                                 0 = FCS is not removed from the pass through packets.
                                                                 1 = FCS is removed from the pass through packets.

                                                                 Added in pass 2. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_frm_ctl_s cn83xx; */
    /* struct bdk_ncsi_tx_frm_ctl_s cn88xxp2; */
    struct bdk_ncsi_tx_frm_ctl_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t fcs_strp              : 1;  /**< [  4:  4](RAZ) Reserved. */
        uint64_t pre_strp              : 1;  /**< [  3:  3](R/W) Strip off the PREAMBLE and SFD:
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.

                                                                 PRE_STRP determines if the PREAMBLE+SFD bytes are thrown away or sent to the core as part
                                                                 of the packet. With either setting, the PREAMBLE+SFD bytes are not counted toward the
                                                                 packet size when checking against the MIN and MAX bounds. Furthermore, the bytes are
                                                                 skipped when locating the start of the L2 header for DMAC recognition. */
        uint64_t pre_chk_len           : 3;  /**< [  2:  0](R/W) Check that a correct preamble of a given length is present.

                                                                 With a setting of > 0, NCSI checks that a valid PREAMBLE is received and of the
                                                                 corresponding length in bytes.
                                                                 If a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The NCSI_INT[PCTERR] interrupt is also raised.

                                                                 With a setting of 0, NCSI checks the first byte is an valid SFD symbol and not a PREAMBLE
                                                                 symbol. */
#else /* Word 0 - Little Endian */
        uint64_t pre_chk_len           : 3;  /**< [  2:  0](R/W) Check that a correct preamble of a given length is present.

                                                                 With a setting of > 0, NCSI checks that a valid PREAMBLE is received and of the
                                                                 corresponding length in bytes.
                                                                 If a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The NCSI_INT[PCTERR] interrupt is also raised.

                                                                 With a setting of 0, NCSI checks the first byte is an valid SFD symbol and not a PREAMBLE
                                                                 symbol. */
        uint64_t pre_strp              : 1;  /**< [  3:  3](R/W) Strip off the PREAMBLE and SFD:
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.

                                                                 PRE_STRP determines if the PREAMBLE+SFD bytes are thrown away or sent to the core as part
                                                                 of the packet. With either setting, the PREAMBLE+SFD bytes are not counted toward the
                                                                 packet size when checking against the MIN and MAX bounds. Furthermore, the bytes are
                                                                 skipped when locating the start of the L2 header for DMAC recognition. */
        uint64_t fcs_strp              : 1;  /**< [  4:  4](RAZ) Reserved. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_ncsi_tx_frm_ctl_t;

#define BDK_NCSI_TX_FRM_CTL BDK_NCSI_TX_FRM_CTL_FUNC()
static inline uint64_t BDK_NCSI_TX_FRM_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_FRM_CTL_FUNC(void)
{
    return 0x87e00b000120ll;
}

#define typedef_BDK_NCSI_TX_FRM_CTL bdk_ncsi_tx_frm_ctl_t
#define bustype_BDK_NCSI_TX_FRM_CTL BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_FRM_CTL "NCSI_TX_FRM_CTL"
#define busnum_BDK_NCSI_TX_FRM_CTL 0
#define arguments_BDK_NCSI_TX_FRM_CTL -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_frm_smac#_cam
 *
 * NCSI TX SMAC CAM Registers
 * These registers set TX framer Source MAC address CAM.  See NCSI_CONFIG for addition CAM config
 * options.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_frm_smacx_cam_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t en                    : 1;  /**< [ 48: 48](R/W) CAM entry enable for this SMAC address.
                                                                 1 = Include this address in the matching algorithm.
                                                                 0 = Don't include this address in the matching algorithm. */
        uint64_t adr                   : 48; /**< [ 47:  0](R/W) SMAC address in the CAM used for matching. */
#else /* Word 0 - Little Endian */
        uint64_t adr                   : 48; /**< [ 47:  0](R/W) SMAC address in the CAM used for matching. */
        uint64_t en                    : 1;  /**< [ 48: 48](R/W) CAM entry enable for this SMAC address.
                                                                 1 = Include this address in the matching algorithm.
                                                                 0 = Don't include this address in the matching algorithm. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_frm_smacx_cam_s cn; */
} bdk_ncsi_tx_frm_smacx_cam_t;

static inline uint64_t BDK_NCSI_TX_FRM_SMACX_CAM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_FRM_SMACX_CAM(unsigned long a)
{
    if (a<=1)
        return 0x87e00b000200ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("NCSI_TX_FRM_SMACX_CAM", 1, a, 0, 0, 0);
}

#define typedef_BDK_NCSI_TX_FRM_SMACX_CAM(a) bdk_ncsi_tx_frm_smacx_cam_t
#define bustype_BDK_NCSI_TX_FRM_SMACX_CAM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_FRM_SMACX_CAM(a) "NCSI_TX_FRM_SMACX_CAM"
#define busnum_BDK_NCSI_TX_FRM_SMACX_CAM(a) (a)
#define arguments_BDK_NCSI_TX_FRM_SMACX_CAM(a) (a),-1,-1,-1

/**
 * Register (RSL) ncsi_tx_ifg
 *
 * NCSI TX Minimum Interframe-Gap Cycles Registers
 * This register specifies the minimum number of interframe-gap (IFG) cycles between packets
 * recieved from the RMII input interface.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_ifg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_6_63         : 58;
        uint64_t ifg                   : 6;  /**< [  5:  0](R/W) Min IFG (in refclk cycles) between packets used to determine IFGERR.
                                                                 Normally IFG is 96 bits, and with 2 bits per cycle, equates to 48.
                                                                 The CNXXXX NCSI datapath can tolerate an IFG as small as 32 bit times or 16 refclk
                                                                 cycles. Incoming IFG values less than this may cause data corruption particularly if
                                                                 FCS stripping is turned on. */
#else /* Word 0 - Little Endian */
        uint64_t ifg                   : 6;  /**< [  5:  0](R/W) Min IFG (in refclk cycles) between packets used to determine IFGERR.
                                                                 Normally IFG is 96 bits, and with 2 bits per cycle, equates to 48.
                                                                 The CNXXXX NCSI datapath can tolerate an IFG as small as 32 bit times or 16 refclk
                                                                 cycles. Incoming IFG values less than this may cause data corruption particularly if
                                                                 FCS stripping is turned on. */
        uint64_t reserved_6_63         : 58;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_ifg_s cn; */
} bdk_ncsi_tx_ifg_t;

#define BDK_NCSI_TX_IFG BDK_NCSI_TX_IFG_FUNC()
static inline uint64_t BDK_NCSI_TX_IFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_IFG_FUNC(void)
{
    return 0x87e00b000130ll;
}

#define typedef_BDK_NCSI_TX_IFG bdk_ncsi_tx_ifg_t
#define bustype_BDK_NCSI_TX_IFG BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_IFG "NCSI_TX_IFG"
#define busnum_BDK_NCSI_TX_IFG 0
#define arguments_BDK_NCSI_TX_IFG -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_jabber
 *
 * NCSI TX Maximum Packet-Size Registers
 * The max size of a packet in bytes, including preamble, SFD and FCS, that the NCSI will allow.
 * Any packet recieved by the NCSI TX RMII interface larger than NCSI_TX_JABBER[CNT] will be
 * marked with error and become eligible for packet truncation.  Transmission will resume at
 * the detection of the next packet.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_jabber_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W) Byte count for jabber check. Failing packets set the JABBER interrupt and are
                                                                 sent with opcode = JABBER. NCSI truncates the packet to CNT+1 bytes. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W) Byte count for jabber check. Failing packets set the JABBER interrupt and are
                                                                 sent with opcode = JABBER. NCSI truncates the packet to CNT+1 bytes. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_jabber_s cn; */
} bdk_ncsi_tx_jabber_t;

#define BDK_NCSI_TX_JABBER BDK_NCSI_TX_JABBER_FUNC()
static inline uint64_t BDK_NCSI_TX_JABBER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_JABBER_FUNC(void)
{
    return 0x87e00b000128ll;
}

#define typedef_BDK_NCSI_TX_JABBER bdk_ncsi_tx_jabber_t
#define bustype_BDK_NCSI_TX_JABBER BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_JABBER "NCSI_TX_JABBER"
#define busnum_BDK_NCSI_TX_JABBER 0
#define arguments_BDK_NCSI_TX_JABBER -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_mix
 *
 * NCSI TX MIX Configuration Register
 * This register specifies configuration parameters for the MIX interface of BGX.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_mix_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t port                  : 4;  /**< [  3:  0](R/W) Port value inserted into MIX frames headed to the BGX where it is used as the channel number. */
#else /* Word 0 - Little Endian */
        uint64_t port                  : 4;  /**< [  3:  0](R/W) Port value inserted into MIX frames headed to the BGX where it is used as the channel number. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_mix_s cn; */
} bdk_ncsi_tx_mix_t;

#define BDK_NCSI_TX_MIX BDK_NCSI_TX_MIX_FUNC()
static inline uint64_t BDK_NCSI_TX_MIX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_MIX_FUNC(void)
{
    return 0x87e00b000138ll;
}

#define typedef_BDK_NCSI_TX_MIX bdk_ncsi_tx_mix_t
#define bustype_BDK_NCSI_TX_MIX BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_MIX "NCSI_TX_MIX"
#define busnum_BDK_NCSI_TX_MIX 0
#define arguments_BDK_NCSI_TX_MIX -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_ncp_ch_st
 *
 * NCSI TX NCP State Register
 * This register provides the NCSI command processor channel state status.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_ncp_ch_st_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t ald                   : 1;  /**< [  1:  1](RO/H) Current state of ALD (allow link disable) in the last received disable channel command. */
        uint64_t state                 : 1;  /**< [  0:  0](RO/H) Current state of the NCSI command processor channel state. */
#else /* Word 0 - Little Endian */
        uint64_t state                 : 1;  /**< [  0:  0](RO/H) Current state of the NCSI command processor channel state. */
        uint64_t ald                   : 1;  /**< [  1:  1](RO/H) Current state of ALD (allow link disable) in the last received disable channel command. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_ncp_ch_st_s cn; */
} bdk_ncsi_tx_ncp_ch_st_t;

#define BDK_NCSI_TX_NCP_CH_ST BDK_NCSI_TX_NCP_CH_ST_FUNC()
static inline uint64_t BDK_NCSI_TX_NCP_CH_ST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_CH_ST_FUNC(void)
{
    return 0x87e00b000140ll;
}

#define typedef_BDK_NCSI_TX_NCP_CH_ST bdk_ncsi_tx_ncp_ch_st_t
#define bustype_BDK_NCSI_TX_NCP_CH_ST BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_NCP_CH_ST "NCSI_TX_NCP_CH_ST"
#define busnum_BDK_NCSI_TX_NCP_CH_ST 0
#define arguments_BDK_NCSI_TX_NCP_CH_ST -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_ncp_perm#_table_hi
 *
 * NCSI TX NCP Permissions Table Hi Registers
 * These registers set the TX NCP Permission table high address range filter for the OEM command.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_ncp_permx_table_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 64; /**< [ 63:  0](SR/W) Specifies the high physical address in formulating a permissions filter for OEM command
                                                                 access.
                                                                 Together with the respective NCSI_TX_NCP_PERM()_TABLE_LOW entry, specifies
                                                                 a range, from NCSI_TX_NCP_PERM_TABLE()_LOW[n] to NCSI_TX_NCP_PERM()_TABLE_HI[n] of
                                                                 physical addresses, contained in the OEM command, that have permissions to execute
                                                                 read or writes to CNXXXX general registers through MRML.

                                                                 Values per entry should be set such that LOW[n]<=HI[n]. To specify a single address the hi
                                                                 and low are programmed with the same value.
                                                                 If a range in one set of HI/LOW entries overlaps with another, the
                                                                 overlap is harmlessly redundant.

                                                                 Address bit <63> is used as the secure bit, and thus to allow secure and
                                                                 non-secure access to a given register, both the register's address with <63>=0,
                                                                 and register's address with <63>=1 must be within the range(s).

                                                                 Default values allow default access to:

                                                                   * All NCSI addresses except secure registers.
                                                                   * All BGX0 and BGX1 addresses except secure registers.
                                                                   * All SERDES addresses serving BGX0 and BGX1, namely QLM0 and QLM1.

                                                                 Access to NCSI_CPU2BMC_MSG and NCSI_BMC2CPU_MSG are always allowed. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 64; /**< [ 63:  0](SR/W) Specifies the high physical address in formulating a permissions filter for OEM command
                                                                 access.
                                                                 Together with the respective NCSI_TX_NCP_PERM()_TABLE_LOW entry, specifies
                                                                 a range, from NCSI_TX_NCP_PERM_TABLE()_LOW[n] to NCSI_TX_NCP_PERM()_TABLE_HI[n] of
                                                                 physical addresses, contained in the OEM command, that have permissions to execute
                                                                 read or writes to CNXXXX general registers through MRML.

                                                                 Values per entry should be set such that LOW[n]<=HI[n]. To specify a single address the hi
                                                                 and low are programmed with the same value.
                                                                 If a range in one set of HI/LOW entries overlaps with another, the
                                                                 overlap is harmlessly redundant.

                                                                 Address bit <63> is used as the secure bit, and thus to allow secure and
                                                                 non-secure access to a given register, both the register's address with <63>=0,
                                                                 and register's address with <63>=1 must be within the range(s).

                                                                 Default values allow default access to:

                                                                   * All NCSI addresses except secure registers.
                                                                   * All BGX0 and BGX1 addresses except secure registers.
                                                                   * All SERDES addresses serving BGX0 and BGX1, namely QLM0 and QLM1.

                                                                 Access to NCSI_CPU2BMC_MSG and NCSI_BMC2CPU_MSG are always allowed. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_ncp_permx_table_hi_s cn; */
} bdk_ncsi_tx_ncp_permx_table_hi_t;

static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_HI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_HI(unsigned long a)
{
    if (a<=15)
        return 0x87e00b000900ll + 8ll * ((a) & 0xf);
    __bdk_csr_fatal("NCSI_TX_NCP_PERMX_TABLE_HI", 1, a, 0, 0, 0);
}

#define typedef_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(a) bdk_ncsi_tx_ncp_permx_table_hi_t
#define bustype_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(a) BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(a) "NCSI_TX_NCP_PERMX_TABLE_HI"
#define busnum_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(a) (a)
#define arguments_BDK_NCSI_TX_NCP_PERMX_TABLE_HI(a) (a),-1,-1,-1

/**
 * Register (RSL) ncsi_tx_ncp_perm#_table_low
 *
 * NCSI TX NCP Permissions Table Low Registers
 * These registers set the TX NCP Permission table low address range filter for the OEM command.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_ncp_permx_table_low_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t addr                  : 64; /**< [ 63:  0](SR/W) Specifies the low physical address in formulating a permissions filter for OEM command
                                                                 access.  See NCSI_TX_NCP_PERM()_TABLE_HI. */
#else /* Word 0 - Little Endian */
        uint64_t addr                  : 64; /**< [ 63:  0](SR/W) Specifies the low physical address in formulating a permissions filter for OEM command
                                                                 access.  See NCSI_TX_NCP_PERM()_TABLE_HI. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_ncp_permx_table_low_s cn; */
} bdk_ncsi_tx_ncp_permx_table_low_t;

static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(unsigned long a)
{
    if (a<=15)
        return 0x87e00b000a00ll + 8ll * ((a) & 0xf);
    __bdk_csr_fatal("NCSI_TX_NCP_PERMX_TABLE_LOW", 1, a, 0, 0, 0);
}

#define typedef_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(a) bdk_ncsi_tx_ncp_permx_table_low_t
#define bustype_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(a) BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(a) "NCSI_TX_NCP_PERMX_TABLE_LOW"
#define busnum_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(a) (a)
#define arguments_BDK_NCSI_TX_NCP_PERMX_TABLE_LOW(a) (a),-1,-1,-1

/**
 * Register (RSL) ncsi_tx_ncp_pkg_st
 *
 * NCSI TX NCP State Register
 * This register provides the NCSI command processor package state status.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_ncp_pkg_st_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t state                 : 1;  /**< [  0:  0](RO/H) Currect state of the NCSI command processor package state. */
#else /* Word 0 - Little Endian */
        uint64_t state                 : 1;  /**< [  0:  0](RO/H) Currect state of the NCSI command processor package state. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_ncp_pkg_st_s cn; */
} bdk_ncsi_tx_ncp_pkg_st_t;

#define BDK_NCSI_TX_NCP_PKG_ST BDK_NCSI_TX_NCP_PKG_ST_FUNC()
static inline uint64_t BDK_NCSI_TX_NCP_PKG_ST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_NCP_PKG_ST_FUNC(void)
{
    return 0x87e00b000148ll;
}

#define typedef_BDK_NCSI_TX_NCP_PKG_ST bdk_ncsi_tx_ncp_pkg_st_t
#define bustype_BDK_NCSI_TX_NCP_PKG_ST BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_NCP_PKG_ST "NCSI_TX_NCP_PKG_ST"
#define busnum_BDK_NCSI_TX_NCP_PKG_ST 0
#define arguments_BDK_NCSI_TX_NCP_PKG_ST -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_stat0
 *
 * NCSI TX Statistics Register 0
 * This register provides a count of valid packets detected at the output of the transmit side
 * NCSI framer.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of valid packets through the tx side framers. CNT will wrap and is cleared if NCSI
                                                                 is disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of valid packets through the tx side framers. CNT will wrap and is cleared if NCSI
                                                                 is disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_stat0_s cn; */
} bdk_ncsi_tx_stat0_t;

#define BDK_NCSI_TX_STAT0 BDK_NCSI_TX_STAT0_FUNC()
static inline uint64_t BDK_NCSI_TX_STAT0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_STAT0_FUNC(void)
{
    return 0x87e00b000300ll;
}

#define typedef_BDK_NCSI_TX_STAT0 bdk_ncsi_tx_stat0_t
#define bustype_BDK_NCSI_TX_STAT0 BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_STAT0 "NCSI_TX_STAT0"
#define busnum_BDK_NCSI_TX_STAT0 0
#define arguments_BDK_NCSI_TX_STAT0 -1,-1,-1,-1

/**
 * Register (RSL) ncsi_tx_stat1
 *
 * NCSI TX Statistics Register 1
 * This register provides a count of valid bytes detected at the output of the transmit side
 * NCSI framer.  These bytes are detected as being part of a valid frame.
 */
typedef union
{
    uint64_t u;
    struct bdk_ncsi_tx_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of valid bytes through the tx side framer. CNT will wrap and is cleared if NCSI is
                                                                 disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of valid bytes through the tx side framer. CNT will wrap and is cleared if NCSI is
                                                                 disabled with
                                                                 NCSI_SECURE_CONFIG[NCSIEN]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ncsi_tx_stat1_s cn; */
} bdk_ncsi_tx_stat1_t;

#define BDK_NCSI_TX_STAT1 BDK_NCSI_TX_STAT1_FUNC()
static inline uint64_t BDK_NCSI_TX_STAT1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NCSI_TX_STAT1_FUNC(void)
{
    return 0x87e00b000308ll;
}

#define typedef_BDK_NCSI_TX_STAT1 bdk_ncsi_tx_stat1_t
#define bustype_BDK_NCSI_TX_STAT1 BDK_CSR_TYPE_RSL
#define basename_BDK_NCSI_TX_STAT1 "NCSI_TX_STAT1"
#define busnum_BDK_NCSI_TX_STAT1 0
#define arguments_BDK_NCSI_TX_STAT1 -1,-1,-1,-1

#endif /* __BDK_CSRS_NCSI_H__ */
