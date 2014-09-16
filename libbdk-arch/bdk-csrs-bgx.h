#ifndef __BDK_CSRS_BGX__
#define __BDK_CSRS_BGX__
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
 * Cavium BGX.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration BGX_INT_VEC_E
 *
 * BGX MSI-X Vector Enumeration
 * Enumeration the MSI-X interrupt vectors.
 */
enum bgx_int_vec_e {
	BGX_INT_VEC_E_CMR0_INT = 0x0,
	BGX_INT_VEC_E_CMR1_INT = 0x7,
	BGX_INT_VEC_E_CMR2_INT = 0xe,
	BGX_INT_VEC_E_CMR3_INT = 0x15,
	BGX_INT_VEC_E_CMR_MEM_INT = 0x1c,
	BGX_INT_VEC_E_GMP0_GMI_RX_INT = 0x5,
	BGX_INT_VEC_E_GMP0_GMI_TX_INT = 0x6,
	BGX_INT_VEC_E_GMP0_PCS_INT = 0x4,
	BGX_INT_VEC_E_GMP1_GMI_RX_INT = 0xc,
	BGX_INT_VEC_E_GMP1_GMI_TX_INT = 0xd,
	BGX_INT_VEC_E_GMP1_PCS_INT = 0xb,
	BGX_INT_VEC_E_GMP2_GMI_RX_INT = 0x13,
	BGX_INT_VEC_E_GMP2_GMI_TX_INT = 0x14,
	BGX_INT_VEC_E_GMP2_PCS_INT = 0x12,
	BGX_INT_VEC_E_GMP3_GMI_RX_INT = 0x1a,
	BGX_INT_VEC_E_GMP3_GMI_TX_INT = 0x1b,
	BGX_INT_VEC_E_GMP3_PCS_INT = 0x19,
	BGX_INT_VEC_E_SMU0_RX_INT = 0x2,
	BGX_INT_VEC_E_SMU0_TX_INT = 0x3,
	BGX_INT_VEC_E_SMU1_RX_INT = 0x9,
	BGX_INT_VEC_E_SMU1_TX_INT = 0xa,
	BGX_INT_VEC_E_SMU2_RX_INT = 0x10,
	BGX_INT_VEC_E_SMU2_TX_INT = 0x11,
	BGX_INT_VEC_E_SMU3_RX_INT = 0x17,
	BGX_INT_VEC_E_SMU3_TX_INT = 0x18,
	BGX_INT_VEC_E_SPU0_INT = 0x1,
	BGX_INT_VEC_E_SPU1_INT = 0x8,
	BGX_INT_VEC_E_SPU2_INT = 0xf,
	BGX_INT_VEC_E_SPU3_INT = 0x16,
	BGX_INT_VEC_E_SPU_MEM_INT = 0x1d,
	BGX_INT_VEC_E_ENUM_LAST = 0x1e,
};

/**
 * Enumeration BGX_OPCODE_E
 *
 * BGX Error Opcode Enumeration
 * Enumerates the error opcodes created by BGX and presented into NCSI frames.
 */
enum bgx_opcode_e {
	BGX_OPCODE_E_BAD_TERM = 0x9,
	BGX_OPCODE_E_FCSERR_RCVERR = 0x8,
	BGX_OPCODE_E_FCS_ERR = 0x3,
	BGX_OPCODE_E_JABBER_ERR = 0x2,
	BGX_OPCODE_E_NONE = 0x0,
	BGX_OPCODE_E_PARTIAL_ERR = 0x1,
	BGX_OPCODE_E_RCV_ERR = 0xb,
	BGX_OPCODE_E_SKP_ERR = 0xc,
	BGX_OPCODE_E_ENUM_LAST = 0xd,
};

/**
 * Enumeration BGX_SPU_BR_TRAIN_CST_E
 *
 * BGX Training Coefficient Status Enumeration
 * 2-bit status for each coefficient as defined in 802.3-2008, Table 72-5.
 */
enum bgx_spu_br_train_cst_e {
	BGX_SPU_BR_TRAIN_CST_E_MAXIMUM = 0x3,
	BGX_SPU_BR_TRAIN_CST_E_MINIMUM = 0x2,
	BGX_SPU_BR_TRAIN_CST_E_NOT_UPDATED = 0x0,
	BGX_SPU_BR_TRAIN_CST_E_UPDATED = 0x1,
	BGX_SPU_BR_TRAIN_CST_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration BGX_SPU_BR_TRAIN_CUP_E
 *
 * BGX Training Coefficient Enumeration
 * 2-bit command for each coefficient as defined in 802.3-2008, Table 72-4.
 */
enum bgx_spu_br_train_cup_e {
	BGX_SPU_BR_TRAIN_CUP_E_DECREMENT = 0x1,
	BGX_SPU_BR_TRAIN_CUP_E_HOLD = 0x0,
	BGX_SPU_BR_TRAIN_CUP_E_INCREMENT = 0x2,
	BGX_SPU_BR_TRAIN_CUP_E_RSV_CMD = 0x3,
	BGX_SPU_BR_TRAIN_CUP_E_ENUM_LAST = 0x4,
};


/**
 * Structure BGX_SPU_BR_LANE_TRAIN_STATUS_S
 *
 * BGX Lane Training Status Structure
 * This is the group of lane status bits for a single lane in the BASE-R PMD status register
 * (MDIO address 1.151) as defined in 802.3ba-2010, Table 45-55.
 */
union bgx_spu_br_lane_train_status_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60; /**< [ 63:  4] Reserved */
		uint64_t training_failure            : 1;  /**< [  3:  3] Link training failure. */
		uint64_t training                    : 1;  /**< [  2:  2] Link training state.
                                                                 0 = Training in progress.
                                                                 1 = Training has completed. */
		uint64_t frame_lock                  : 1;  /**< [  1:  1] Frame lock status. Set when training frame delineation has been detected. */
		uint64_t rx_trained                  : 1;  /**< [  0:  0] Receiver trained status.
                                                                 0 = Receiver training.
                                                                 1 = Receiver trained and ready to receive data for the lane. */
#else
		uint64_t rx_trained                  : 1;
		uint64_t frame_lock                  : 1;
		uint64_t training                    : 1;
		uint64_t training_failure            : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
};

/**
 * Structure BGX_SPU_BR_TRAIN_CUP_S
 *
 * BGX Lane Training Coeffiecient Structure
 * This is the coefficient update field of the BASE-R link training packet as defined in
 * 802.3-2008, Table 72-4.
 */
union bgx_spu_br_train_cup_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48; /**< [ 63: 16] Reserved */
		uint64_t reserved_14_15              : 2;  /**< [ 15: 14] Reserved. */
		uint64_t preset                      : 1;  /**< [ 13: 13] Preset. Set to indicate that all TX coefficients be set to a state where equalization is
                                                                 turned off, i.e. the precursor (k = -1) and postcursor (k = +1) coefficients should be set
                                                                 to 0 and the main
                                                                 (k = 0) coefficient should be set to its maximum value. */
		uint64_t init                        : 1;  /**< [ 12: 12] Initialize. Set to indicate that the TX coefficients should be set to meet the conditions
                                                                 defined in 802.3-2008 sub-clause 72.6.10.4.2. */
		uint64_t reserved_6_11               : 6;  /**< [ 11:  6] Reserved. */
		uint64_t post_cup                    : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 BGX_SPU_BR_TRAIN_CUP_E. */
		uint64_t main_cup                    : 2;  /**< [  3:  2] Main (k = 0) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 BGX_SPU_BR_TRAIN_CUP_E. */
		uint64_t pre_cup                     : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 BGX_SPU_BR_TRAIN_CUP_E. */
#else
		uint64_t pre_cup                     : 2;
		uint64_t main_cup                    : 2;
		uint64_t post_cup                    : 2;
		uint64_t reserved_6_11               : 6;
		uint64_t init                        : 1;
		uint64_t preset                      : 1;
		uint64_t reserved_14_15              : 2;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
};

/**
 * Structure BGX_SPU_BR_TRAIN_REP_S
 *
 * BGX Training Report Structure
 * This is the status report field of the BASE-R link training packet as defined in 802.3-2008,
 * Table 72-5.
 */
union bgx_spu_br_train_rep_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48; /**< [ 63: 16] Reserved */
		uint64_t rx_ready                    : 1;  /**< [ 15: 15] Receiver ready. Set to indicate that the local receiver has determined that training is
                                                                 complete and is prepared to receive data. */
		uint64_t reserved_6_14               : 9;  /**< [ 14:  6] Reserved. */
		uint64_t post_cst                    : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 BGX_SPU_BR_TRAIN_CST_E. */
		uint64_t main_cst                    : 2;  /**< [  3:  2] Main (k = 0) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 BGX_SPU_BR_TRAIN_CST_E. */
		uint64_t pre_cst                     : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 BGX_SPU_BR_TRAIN_CST_E. */
#else
		uint64_t pre_cst                     : 2;
		uint64_t main_cst                    : 2;
		uint64_t post_cst                    : 2;
		uint64_t reserved_6_14               : 9;
		uint64_t rx_ready                    : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
};

/**
 * Structure BGX_SPU_SDS_CU_S
 *
 * BGX Training Coeffiecient Structure
 * This structure is similar to BGX_SPU_BR_TRAIN_CUP_S format, but with reserved fields removed
 * and RX_READY field added.
 */
union bgx_spu_sds_cu_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55; /**< [ 63:  9] Reserved */
		uint64_t rcvr_ready                  : 1;  /**< [  8:  8] See BGX_SPU_BR_TRAIN_REP_S[RX_READY]. */
		uint64_t preset                      : 1;  /**< [  7:  7] See BGX_SPU_BR_TRAIN_CUP_S[PRESET]. */
		uint64_t initialize                  : 1;  /**< [  6:  6] See BGX_SPU_BR_TRAIN_CUP_S[INIT]. */
		uint64_t post_cu                     : 2;  /**< [  5:  4] See BGX_SPU_BR_TRAIN_CUP_S[POST_CUP]. */
		uint64_t main_cu                     : 2;  /**< [  3:  2] See BGX_SPU_BR_TRAIN_CUP_S[MAIN_CUP]. */
		uint64_t pre_cu                      : 2;  /**< [  1:  0] See BGX_SPU_BR_TRAIN_CUP_S[PRE_CUP]. */
#else
		uint64_t pre_cu                      : 2;
		uint64_t main_cu                     : 2;
		uint64_t post_cu                     : 2;
		uint64_t initialize                  : 1;
		uint64_t preset                      : 1;
		uint64_t rcvr_ready                  : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
};

/**
 * Structure BGX_SPU_SDS_SKEW_STATUS_S
 *
 * BGX Skew Status Structure
 * Provides receive skew information detected for a physical SerDes lane when it is assigned to a
 * multilane LMAC/LPCS. Contents are valid when RX deskew is done for the associated LMAC/LPCS.
 */
union bgx_spu_sds_skew_status_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32; /**< [ 63: 32] Reserved */
		uint64_t reserved_25_31              : 7;  /**< [ 31: 25] Reserved. */
		uint64_t lane_skew                   : 5;  /**< [ 24: 20] Lane Skew. The SerDes lane's receive skew/delay in number of code-groups (BASE-X) or
                                                                 blocks (40GBASE-R) relative to the earliest (least delayed) lane of the LMAC/LPCS. */
		uint64_t reserved_18_19              : 2;  /**< [ 19: 18] Reserved. */
		uint64_t am_lane_id                  : 2;  /**< [ 17: 16] Alignment Marker ID. Valid for 40GBASE-R only. This is the PCS lane number of the
                                                                 alignment marker received on the SerDes lane. */
		uint64_t reserved_12_15              : 4;  /**< [ 15: 12] Reserved. */
		uint64_t am_timestamp                : 12; /**< [ 11:  0] Alignment marker PTP timestamp. Valid for 40GBASE-R only. Contains the lower 12 bits of
                                                                 the PTP timestamp of the alignment marker received on the SerDes lane during align/skew
                                                                 detection. */
#else
		uint64_t am_timestamp                : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t am_lane_id                  : 2;
		uint64_t reserved_18_19              : 2;
		uint64_t lane_skew                   : 5;
		uint64_t reserved_25_31              : 7;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
};

/**
 * Structure BGX_SPU_SDS_SR_S
 *
 * BGX Lane Training Coeffiecient Structure
 * Similar to BGX_SPU_BR_TRAIN_REP_S format, but with reserved fields and RX_READY fields removed.
 */
union bgx_spu_sds_sr_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58; /**< [ 63:  6] Reserved */
		uint64_t post_status                 : 2;  /**< [  5:  4] See BGX_SPU_BR_TRAIN_REP_S[POST_CST]. */
		uint64_t main_status                 : 2;  /**< [  3:  2] See BGX_SPU_BR_TRAIN_REP_S[MAIN_CST]. */
		uint64_t pre_status                  : 2;  /**< [  1:  0] See BGX_SPU_BR_TRAIN_REP_S[PRE_CST]. */
#else
		uint64_t pre_status                  : 2;
		uint64_t main_status                 : 2;
		uint64_t post_status                 : 2;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
};


/**
 * RSL - bgx#_cmr#_config
 *
 * Logical MAC/PCS configuration registers; one per LMAC. The maximum number of LMACs (and
 * maximum LMAC ID) that can be enabled by these registers is limited by
 * BGX()_CMR_RX_LMACS[LMACS] and BGX()_CMR_TX_LMACS[LMACS]. When multiple LMACs are
 * enabled, they must be configured with the same [LMAC_TYPE] value.
 *
 * INTERNAL:
 * \<pre\>
 * Typical configurations:
 *   ---------------------------------------------------------------------------
 *   Configuration           LMACS  Register             [ENABLE]    [LMAC_TYPE]
 *   ---------------------------------------------------------------------------
 *   1x40GBASE-R4            1      BGXn_CMR0_CONFIG     1           4
 *                                  BGXn_CMR1_CONFIG     0           --
 *                                  BGXn_CMR2_CONFIG     0           --
 *                                  BGXn_CMR3_CONFIG     0           --
 *   ---------------------------------------------------------------------------
 *   4x10GBASE-R             4      BGXn_CMR0_CONFIG     1           3
 *                                  BGXn_CMR1_CONFIG     1           3
 *                                  BGXn_CMR2_CONFIG     1           3
 *                                  BGXn_CMR3_CONFIG     1           3
 *   ---------------------------------------------------------------------------
 *   2xRXAUI                 2      BGXn_CMR0_CONFIG     1           2
 *                                  BGXn_CMR1_CONFIG     1           2
 *                                  BGXn_CMR2_CONFIG     0           --
 *                                  BGXn_CMR3_CONFIG     0           --
 *   ---------------------------------------------------------------------------
 *   1x10GBASE-X/XAUI/DXAUI  1      BGXn_CMR0_CONFIG     1           1
 *                                  BGXn_CMR1_CONFIG     0           --
 *                                  BGXn_CMR2_CONFIG     0           --
 *                                  BGXn_CMR3_CONFIG     0           --
 *   ---------------------------------------------------------------------------
 *   4xSGMII/1000BASE-X      4      BGXn_CMR0_CONFIG     1           0
 *                                  BGXn_CMR1_CONFIG     1           0
 *                                  BGXn_CMR2_CONFIG     1           0
 *                                  BGXn_CMR3_CONFIG     1           0
 *   ---------------------------------------------------------------------------
 * \</pre\>
 */
typedef union bdk_bgxx_cmrx_config {
	uint64_t u;
	struct bdk_bgxx_cmrx_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t enable                      : 1;  /**< R/W - Logical MAC/PCS enable. This is the master enable for the LMAC. When clear, all the
                                                                 dedicated BGX context state for the LMAC (state machines, FIFOs, counters, etc.) is reset,
                                                                 and LMAC access to shared BGX resources (SMU/SPU data path, SerDes lanes) is disabled.

                                                                 When set, LMAC operation is enabled, including link bring-up, synchronization, and
                                                                 transmit/receive of idles and fault sequences. Note that configuration registers for an
                                                                 LMAC are not reset when this bit is clear, allowing software to program them before
                                                                 setting this bit to enable the LMAC. This bit together with LMAC_TYPE is also used to
                                                                 enable the clocking to the GMP and/or blocks of the Super path (SMU and SPU). CMR clocking
                                                                 is enabled when any of the paths are enabled. */
		uint64_t data_pkt_rx_en              : 1;  /**< R/W - Data packet receive enable. When ENABLE = 1 and DATA_PKT_RX_EN = 1, the reception of data
                                                                 packets is enabled in the MAC layer. When ENABLE = 1 and DATA_PKT_RX_EN = 0, the MAC layer
                                                                 drops received data and flow-control packets. */
		uint64_t data_pkt_tx_en              : 1;  /**< R/W - Data packet transmit enable. When ENABLE = 1 and DATA_PKT_TX_EN = 1, the transmission of
                                                                 data
                                                                 packets is enabled in the MAC layer. When ENABLE = 1 and DATA_PKT_TX_EN = 0, the MAC layer
                                                                 suppresses the transmission of new data and packets for the LMAC. */
		uint64_t int_beat_gen                : 1;  /**< R/W - Internal beat generation. This bit is used for debug/test purposes and should be clear
                                                                 during normal operation. When set, the LMAC's PCS layer ignores RXVALID and
                                                                 TXREADY/TXCREDIT from the associated SerDes lanes, internally generates fake (idle)
                                                                 RXVALID and TXCREDIT pulses, and suppresses transmission to the SerDes. */
		uint64_t mix_en                      : 1;  /**< R/W - Must be 0. */
		uint64_t lmac_type                   : 3;  /**< R/W - Logical MAC/PCS/prt type:

                                                                 \<pre\>
                                                                   LMAC_TYPE  Name       Description            NUM_PCS_LANES
                                                                   ----------------------------------------------------------
                                                                   0x0        SGMII      SGMII/1000BASE-X             1
                                                                   0x1        XAUI       10GBASE-X/XAUI or DXAUI      4
                                                                   0x3        10G_R      10GBASE-R                    1
                                                                   0x4        40G_R      40GBASE-R                    4
                                                                   Other      --         Reserved                     -
                                                                 \</pre\>

                                                                 NUM_PCS_LANES specifies the number of PCS lanes that are valid for
                                                                 each type. Each valid PCS lane is mapped to a physical SerDes lane
                                                                 based on the programming of [LANE_TO_SDS].

                                                                 This field must be programmed to its final value before [ENABLE] is set, and must not
                                                                 be changed when [ENABLE] = 1. */
		uint64_t lane_to_sds                 : 8;  /**< R/W - PCS lane-to-SerDes Mapping.
                                                                 This is an array of 2-bit values that map each logical PCS Lane to a
                                                                 physical SerDes lane, as follows:

                                                                 \<pre\>
                                                                   Bits    Description            Reset value
                                                                   ------------------------------------------
                                                                   \<7:6\>   PCS Lane 3 SerDes ID       0x3
                                                                   \<5:4\>   PCS Lane 2 SerDes ID       0x2
                                                                   \<3:2\>   PCS Lane 1 SerDes ID       0x1
                                                                   \<1:0\>   PCS Lane 0 SerDes ID       0x0
                                                                 \</pre\>

                                                                 PCS lanes 0 through NUM_PCS_LANES-1 are valid, where NUM_PCS_LANES is a function of the
                                                                 logical MAC/PCS type. (See definition of LMAC_TYPE.) For example, when LMAC_TYPE = SGMII,
                                                                 then NUM_PCS_LANES = 1, PCS lane 0 is valid and the associated physical SerDes lanes
                                                                 are selected by bits \<1:0\>.

                                                                 For 40GBASE-R (LMAC_TYPE = 40G_R), all four PCS lanes are valid, and the PCS lane IDs
                                                                 determine the block distribution order and associated alignment markers on the transmit
                                                                 side. This is not necessarily the order in which PCS lanes receive data because 802.3
                                                                 allows multilane BASE-R receive lanes to be reordered. When a lane (called service
                                                                 interface in 802.3ba-2010) has achieved alignment marker lock on the receive side (i.e.
                                                                 the associated BGX()_SPU()_BR_ALGN_STATUS[MARKER_LOCK] = 1), then the actual
                                                                 detected RX PCS lane number is recorded in the corresponding
                                                                 BGX()_SPU()_BR_LANE_MAP[LNx_MAPPING].

                                                                 This field must be programmed to its final value before [ENABLE] is set, and must not
                                                                 be changed when [ENABLE] = 1. */
#else
		uint64_t lane_to_sds                 : 8;
		uint64_t lmac_type                   : 3;
		uint64_t mix_en                      : 1;
		uint64_t int_beat_gen                : 1;
		uint64_t data_pkt_tx_en              : 1;
		uint64_t data_pkt_rx_en              : 1;
		uint64_t enable                      : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_config_s      cn85xx; */
	/* struct bdk_bgxx_cmrx_config_s      cn88xx; */
	/* struct bdk_bgxx_cmrx_config_s      cn88xxp1; */
} bdk_bgxx_cmrx_config_t;

static inline uint64_t BDK_BGXX_CMRX_CONFIG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_CONFIG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_CONFIG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_CONFIG(...) bdk_bgxx_cmrx_config_t
#define bustype_BDK_BGXX_CMRX_CONFIG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_CONFIG(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_CONFIG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_CONFIG(...) "BGXX_CMRX_CONFIG"


/**
 * RSL - bgx#_cmr#_int
 */
typedef union bdk_bgxx_cmrx_int {
	uint64_t u;
	struct bdk_bgxx_cmrx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t pko_nxc                     : 1;  /**< R/W1C/H - TX channel out-of-range from PKO interface. Assigned to the LMAC ID based on the lower 2
                                                                 bits of the offending channel. */
		uint64_t overflw                     : 1;  /**< R/W1C/H - RX overflow. */
		uint64_t pause_drp                   : 1;  /**< R/W1C/H - RX PAUSE packet was dropped due to full RXB FIFO or during partner reset. */
#else
		uint64_t pause_drp                   : 1;
		uint64_t overflw                     : 1;
		uint64_t pko_nxc                     : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_int_s         cn85xx; */
	/* struct bdk_bgxx_cmrx_int_s         cn88xx; */
	/* struct bdk_bgxx_cmrx_int_s         cn88xxp1; */
} bdk_bgxx_cmrx_int_t;

static inline uint64_t BDK_BGXX_CMRX_INT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_INT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000040ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_INT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_INT(...) bdk_bgxx_cmrx_int_t
#define bustype_BDK_BGXX_CMRX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_INT(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_INT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_INT(...) "BGXX_CMRX_INT"


/**
 * RSL - bgx#_cmr#_int_ena_w1c
 */
typedef union bdk_bgxx_cmrx_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_cmrx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t pko_nxc                     : 1;  /**< R/W1C/H - TX channel out-of-range from PKO interface. Assigned to the LMAC ID based on the lower 2
                                                                 bits of the offending channel. */
		uint64_t overflw                     : 1;  /**< R/W1C/H - RX overflow. */
		uint64_t pause_drp                   : 1;  /**< R/W1C/H - RX PAUSE packet was dropped due to full RXB FIFO or during partner reset. */
#else
		uint64_t pause_drp                   : 1;
		uint64_t overflw                     : 1;
		uint64_t pko_nxc                     : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_cmrx_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_cmrx_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_cmrx_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_CMRX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000050ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_INT_ENA_W1C(...) bdk_bgxx_cmrx_int_ena_w1c_t
#define bustype_BDK_BGXX_CMRX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_INT_ENA_W1C(...) "BGXX_CMRX_INT_ENA_W1C"


/**
 * RSL - bgx#_cmr#_int_ena_w1s
 */
typedef union bdk_bgxx_cmrx_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_cmrx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t pko_nxc                     : 1;  /**< R/W1C/H - TX channel out-of-range from PKO interface. Assigned to the LMAC ID based on the lower 2
                                                                 bits of the offending channel. */
		uint64_t overflw                     : 1;  /**< R/W1C/H - RX overflow. */
		uint64_t pause_drp                   : 1;  /**< R/W1C/H - RX PAUSE packet was dropped due to full RXB FIFO or during partner reset. */
#else
		uint64_t pause_drp                   : 1;
		uint64_t overflw                     : 1;
		uint64_t pko_nxc                     : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_cmrx_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_cmrx_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_cmrx_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_CMRX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000058ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_INT_ENA_W1S(...) bdk_bgxx_cmrx_int_ena_w1s_t
#define bustype_BDK_BGXX_CMRX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_INT_ENA_W1S(...) "BGXX_CMRX_INT_ENA_W1S"


/**
 * RSL - bgx#_cmr#_int_w1s
 */
typedef union bdk_bgxx_cmrx_int_w1s {
	uint64_t u;
	struct bdk_bgxx_cmrx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t pko_nxc                     : 1;  /**< R/W1C/H - TX channel out-of-range from PKO interface. Assigned to the LMAC ID based on the lower 2
                                                                 bits of the offending channel. */
		uint64_t overflw                     : 1;  /**< R/W1C/H - RX overflow. */
		uint64_t pause_drp                   : 1;  /**< R/W1C/H - RX PAUSE packet was dropped due to full RXB FIFO or during partner reset. */
#else
		uint64_t pause_drp                   : 1;
		uint64_t overflw                     : 1;
		uint64_t pko_nxc                     : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_int_w1s_s     cn85xx; */
	/* struct bdk_bgxx_cmrx_int_w1s_s     cn88xx; */
	/* struct bdk_bgxx_cmrx_int_w1s_s     cn88xxp1; */
} bdk_bgxx_cmrx_int_w1s_t;

static inline uint64_t BDK_BGXX_CMRX_INT_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_INT_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000048ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_INT_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_INT_W1S(...) bdk_bgxx_cmrx_int_w1s_t
#define bustype_BDK_BGXX_CMRX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_INT_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_INT_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_INT_W1S(...) "BGXX_CMRX_INT_W1S"


/**
 * RSL - bgx#_cmr#_prt_cbfc_ctl
 *
 * See XOFF definition listed under BGX()_SMU()_CBFC_CTL.
 *
 */
typedef union bdk_bgxx_cmrx_prt_cbfc_ctl {
	uint64_t u;
	struct bdk_bgxx_cmrx_prt_cbfc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t phys_bp                     : 16; /**< R/W - When BGX()_SMU()_CBFC_CTL[RX_EN] is set and the hardware is backpressuring any
                                                                 LMACs (from either PFC/CBFC PAUSE packets or BGX()_CMR()_TX_OVR_BP[TX_CHAN_BP])
                                                                 and all LMACs indicated by PHYS_BP are backpressured, simulate physical backpressure by
                                                                 deferring all packets on the transmitter. */
		uint64_t reserved_0_15               : 16;
#else
		uint64_t reserved_0_15               : 16;
		uint64_t phys_bp                     : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_prt_cbfc_ctl_s cn85xx; */
	/* struct bdk_bgxx_cmrx_prt_cbfc_ctl_s cn88xx; */
	/* struct bdk_bgxx_cmrx_prt_cbfc_ctl_s cn88xxp1; */
} bdk_bgxx_cmrx_prt_cbfc_ctl_t;

static inline uint64_t BDK_BGXX_CMRX_PRT_CBFC_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_PRT_CBFC_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000508ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_PRT_CBFC_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_PRT_CBFC_CTL(...) bdk_bgxx_cmrx_prt_cbfc_ctl_t
#define bustype_BDK_BGXX_CMRX_PRT_CBFC_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_PRT_CBFC_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_PRT_CBFC_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_PRT_CBFC_CTL(...) "BGXX_CMRX_PRT_CBFC_CTL"


/**
 * RSL - bgx#_cmr#_rx_bp_drop
 */
typedef union bdk_bgxx_cmrx_rx_bp_drop {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_bp_drop_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t mark                        : 7;  /**< R/W - Number of eight-byte cycles to reserve in the RX FIFO. When the number of free
                                                                 entries in the RX FIFO is less than or equal to MARK, incoming packet data is
                                                                 dropped. Mark additionally indicates the number of entries to reserve in the RX FIFO for
                                                                 closing partially received packets. MARK should typically be programmed to its reset
                                                                 value; failure to program correctly can lead to system instability. */
#else
		uint64_t mark                        : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_bp_drop_s  cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_drop_s  cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_drop_s  cn88xxp1; */
} bdk_bgxx_cmrx_rx_bp_drop_t;

static inline uint64_t BDK_BGXX_CMRX_RX_BP_DROP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_BP_DROP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000C8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_BP_DROP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_BP_DROP(...) bdk_bgxx_cmrx_rx_bp_drop_t
#define bustype_BDK_BGXX_CMRX_RX_BP_DROP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_BP_DROP(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_BP_DROP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_BP_DROP(...) "BGXX_CMRX_RX_BP_DROP"


/**
 * RSL - bgx#_cmr#_rx_bp_off
 */
typedef union bdk_bgxx_cmrx_rx_bp_off {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_bp_off_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t mark                        : 7;  /**< R/W - Low watermark (number of eight-byte cycles to deassert backpressure). Level is also used
                                                                 to exit the overflow dropping state. */
#else
		uint64_t mark                        : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_bp_off_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_off_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_off_s   cn88xxp1; */
} bdk_bgxx_cmrx_rx_bp_off_t;

static inline uint64_t BDK_BGXX_CMRX_RX_BP_OFF(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_BP_OFF(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000D8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_BP_OFF", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_BP_OFF(...) bdk_bgxx_cmrx_rx_bp_off_t
#define bustype_BDK_BGXX_CMRX_RX_BP_OFF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_BP_OFF(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_BP_OFF(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_BP_OFF(...) "BGXX_CMRX_RX_BP_OFF"


/**
 * RSL - bgx#_cmr#_rx_bp_on
 */
typedef union bdk_bgxx_cmrx_rx_bp_on {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_bp_on_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t mark                        : 12; /**< R/W - High watermark. Buffer depth in multiple of 16-bytes, at which BGX will
                                                                 assert backpressure for each individual LMAC.  MARK must satisfy:

                                                                   BGX()_CMR()_RX_BP_OFF[MARK] \<= MARK \<
                                                                   (FIFO_SIZE - BGX()_CMR()_RX_BP_DROP[MARK]).

                                                                 A value of 0x0 immediately asserts backpressure.

                                                                 The recommended value is 1/4th the size of the per-LMAC RX FIFO_SIZE as
                                                                 determined by BGX()_CMR_RX_LMACS[LMACS]. For example in SGMII mode with
                                                                 four LMACs of type SGMII, where BGX()_CMR_RX_LMACS[LMACS]=0x4, there is
                                                                 16 KB of buffering. The recommended 1/4th size of that 16 KB is 4 KB, which
                                                                 in units of 16 bytes gives MARK = 0x100 (the reset value). */
#else
		uint64_t mark                        : 12;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_bp_on_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_on_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_on_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_bp_on_t;

static inline uint64_t BDK_BGXX_CMRX_RX_BP_ON(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_BP_ON(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000D0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_BP_ON", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_BP_ON(...) bdk_bgxx_cmrx_rx_bp_on_t
#define bustype_BDK_BGXX_CMRX_RX_BP_ON(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_BP_ON(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_BP_ON(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_BP_ON(...) "BGXX_CMRX_RX_BP_ON"


/**
 * RSL - bgx#_cmr#_rx_bp_status
 */
typedef union bdk_bgxx_cmrx_rx_bp_status {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_bp_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t bp                          : 1;  /**< RO/H - Per-LMAC backpressure status.
                                                                 0 = LMAC is not backpressured.
                                                                 1 = LMAC is backpressured. */
#else
		uint64_t bp                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_bp_status_s cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_status_s cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_bp_status_s cn88xxp1; */
} bdk_bgxx_cmrx_rx_bp_status_t;

static inline uint64_t BDK_BGXX_CMRX_RX_BP_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_BP_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000F0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_BP_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_BP_STATUS(...) bdk_bgxx_cmrx_rx_bp_status_t
#define bustype_BDK_BGXX_CMRX_RX_BP_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_BP_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_BP_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_BP_STATUS(...) "BGXX_CMRX_RX_BP_STATUS"


/**
 * RSL - bgx#_cmr#_rx_dmac_ctl
 */
typedef union bdk_bgxx_cmrx_rx_dmac_ctl {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_dmac_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t cam_accept                  : 1;  /**< R/W - Allow or deny DMAC address filter.
                                                                 0 = Reject the packet on DMAC CAM address match.
                                                                 1 = Accept the packet on DMAC CAM address match. */
		uint64_t mcst_mode                   : 2;  /**< R/W - Multicast mode.
                                                                 0x0 = Force reject all multicast packets.
                                                                 0x1 = Force accept all multicast packets.
                                                                 0x2 = Use the address filter CAM.
                                                                 0x3 = Reserved. */
		uint64_t bcst_accept                 : 1;  /**< R/W - Allow or deny broadcast packets.
                                                                 0 = Reject all broadcast packets.
                                                                 1 = Accept all broadcast Packets. */
#else
		uint64_t bcst_accept                 : 1;
		uint64_t mcst_mode                   : 2;
		uint64_t cam_accept                  : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_dmac_ctl_s cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_dmac_ctl_s cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_dmac_ctl_s cn88xxp1; */
} bdk_bgxx_cmrx_rx_dmac_ctl_t;

static inline uint64_t BDK_BGXX_CMRX_RX_DMAC_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_DMAC_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000E8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_DMAC_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_DMAC_CTL(...) bdk_bgxx_cmrx_rx_dmac_ctl_t
#define bustype_BDK_BGXX_CMRX_RX_DMAC_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_DMAC_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_DMAC_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_DMAC_CTL(...) "BGXX_CMRX_RX_DMAC_CTL"


/**
 * RSL - bgx#_cmr#_rx_fifo_len
 */
typedef union bdk_bgxx_cmrx_rx_fifo_len {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_fifo_len_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t fifo_len                    : 13; /**< RO/H - Per-LMAC FIFO length. Useful for determining if FIFO is empty when bringing an LMAC down. */
#else
		uint64_t fifo_len                    : 13;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_fifo_len_s cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_fifo_len_s cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_fifo_len_s cn88xxp1; */
} bdk_bgxx_cmrx_rx_fifo_len_t;

static inline uint64_t BDK_BGXX_CMRX_RX_FIFO_LEN(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_FIFO_LEN(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000108ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_FIFO_LEN", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_FIFO_LEN(...) bdk_bgxx_cmrx_rx_fifo_len_t
#define bustype_BDK_BGXX_CMRX_RX_FIFO_LEN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_FIFO_LEN(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_FIFO_LEN(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_FIFO_LEN(...) "BGXX_CMRX_RX_FIFO_LEN"


/**
 * RSL - bgx#_cmr#_rx_id_map
 *
 * These registers set the RX LMAC ID mapping for X2P/NIC.
 *
 */
typedef union bdk_bgxx_cmrx_rx_id_map {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_id_map_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t rid                         : 7;  /**< R/W - Reassembly ID map for this LMAC. A shared pool of 96 reassembly IDs (RIDs) exists for all
                                                                 MACs.

                                                                 The RID for this LMAC must be constrained such that it does not overlap with any other MAC
                                                                 in the system. Its reset value has been chosen such that this condition is satisfied:

                                                                 _ RID reset value = 4*(BGX_ID + 1) + LMAC_ID

                                                                 Changes to RID must only occur when the LMAC is quiescent (i.e. the LMAC receive interface
                                                                 is down and the RX FIFO is empty). */
		uint64_t pknd                        : 8;  /**< R/W - Port kind for this LMAC.  Only bits [5:0] are used.  Bits [7:6] are not used and should
                                                                 not be changed from the reset value of 0. */
#else
		uint64_t pknd                        : 8;
		uint64_t rid                         : 7;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_id_map_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_id_map_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_id_map_s   cn88xxp1; */
} bdk_bgxx_cmrx_rx_id_map_t;

static inline uint64_t BDK_BGXX_CMRX_RX_ID_MAP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_ID_MAP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000060ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_ID_MAP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_ID_MAP(...) bdk_bgxx_cmrx_rx_id_map_t
#define bustype_BDK_BGXX_CMRX_RX_ID_MAP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_ID_MAP(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_ID_MAP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_ID_MAP(...) "BGXX_CMRX_RX_ID_MAP"


/**
 * RSL - bgx#_cmr#_rx_logl_xoff
 */
typedef union bdk_bgxx_cmrx_rx_logl_xoff {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_logl_xoff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t xoff                        : 16; /**< R/W1S/H - Together with BGX()_CMR()_RX_LOGL_XON, defines type of channel backpressure to
                                                                 apply to the SMU. Do not write when HiGig2 is enabled. Writing 1 sets the same physical
                                                                 register as that which is cleared by BGX()_CMR()_RX_LOGL_XON[XON]. An XOFF value
                                                                 of 1 will cause a backpressure on SMU. */
#else
		uint64_t xoff                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_logl_xoff_s cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_logl_xoff_s cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_logl_xoff_s cn88xxp1; */
} bdk_bgxx_cmrx_rx_logl_xoff_t;

static inline uint64_t BDK_BGXX_CMRX_RX_LOGL_XOFF(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_LOGL_XOFF(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000F8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_LOGL_XOFF", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_LOGL_XOFF(...) bdk_bgxx_cmrx_rx_logl_xoff_t
#define bustype_BDK_BGXX_CMRX_RX_LOGL_XOFF(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_LOGL_XOFF(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_LOGL_XOFF(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_LOGL_XOFF(...) "BGXX_CMRX_RX_LOGL_XOFF"


/**
 * RSL - bgx#_cmr#_rx_logl_xon
 */
typedef union bdk_bgxx_cmrx_rx_logl_xon {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_logl_xon_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t xon                         : 16; /**< R/W1C/H - Together with BGX()_CMR()_RX_LOGL_XOFF, defines type of channel backpressure to
                                                                 apply. Do not write when HiGig2 is enabled. Writing 1 clears the same physical register as
                                                                 that which is set by XOFF. An XON value of 1 means only NIC channel BP can cause a
                                                                 backpressure on SMU. */
#else
		uint64_t xon                         : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_logl_xon_s cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_logl_xon_s cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_logl_xon_s cn88xxp1; */
} bdk_bgxx_cmrx_rx_logl_xon_t;

static inline uint64_t BDK_BGXX_CMRX_RX_LOGL_XON(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_LOGL_XON(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000100ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_LOGL_XON", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_LOGL_XON(...) bdk_bgxx_cmrx_rx_logl_xon_t
#define bustype_BDK_BGXX_CMRX_RX_LOGL_XON(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_LOGL_XON(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_LOGL_XON(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_LOGL_XON(...) "BGXX_CMRX_RX_LOGL_XON"


/**
 * RSL - bgx#_cmr#_rx_pause_drop_time
 */
typedef union bdk_bgxx_cmrx_rx_pause_drop_time {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_pause_drop_time_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t pause_time                  : 16; /**< R/W1C/H - Time extracted from the dropped PAUSE packet dropped due to RXB FIFO full or during partner reset. */
#else
		uint64_t pause_time                  : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_pause_drop_time_s cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_pause_drop_time_s cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_pause_drop_time_s cn88xxp1; */
} bdk_bgxx_cmrx_rx_pause_drop_time_t;

static inline uint64_t BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000068ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(...) bdk_bgxx_cmrx_rx_pause_drop_time_t
#define bustype_BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_PAUSE_DROP_TIME(...) "BGXX_CMRX_RX_PAUSE_DROP_TIME"


/**
 * RSL - bgx#_cmr#_rx_stat0
 *
 * These registers provide a count of received packets that meet the following conditions:
 * * are not recognized as PAUSE packets.
 * * are not dropped due DMAC filtering.
 * * are not dropped due FIFO full status.
 * * do not have any other OPCODE (FCS, Length, etc).
 */
typedef union bdk_bgxx_cmrx_rx_stat0 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of received packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat0_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat0_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat0_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat0_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000070ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT0(...) bdk_bgxx_cmrx_rx_stat0_t
#define bustype_BDK_BGXX_CMRX_RX_STAT0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT0(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT0(...) "BGXX_CMRX_RX_STAT0"


/**
 * RSL - bgx#_cmr#_rx_stat1
 *
 * These registers provide a count of octets of received packets.
 *
 */
typedef union bdk_bgxx_cmrx_rx_stat1 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Octet count of received packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat1_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat1_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat1_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat1_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000078ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT1(...) bdk_bgxx_cmrx_rx_stat1_t
#define bustype_BDK_BGXX_CMRX_RX_STAT1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT1(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT1(...) "BGXX_CMRX_RX_STAT1"


/**
 * RSL - bgx#_cmr#_rx_stat2
 *
 * These registers provide a count of all packets received that were recognized as flow-control
 * or PAUSE packets. PAUSE packets with any kind of error are counted in
 * BGX()_CMR()_RX_STAT8 (error stats register). Pause packets can be optionally dropped
 * or forwarded based on BGX()_SMU()_RX_FRM_CTL[CTL_DRP]. This count increments
 * regardless of whether the packet is dropped. PAUSE packets are never counted in
 * BGX()_CMR()_RX_STAT0.
 */
typedef union bdk_bgxx_cmrx_rx_stat2 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of received PAUSE packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat2_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat2_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat2_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat2_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000080ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT2(...) bdk_bgxx_cmrx_rx_stat2_t
#define bustype_BDK_BGXX_CMRX_RX_STAT2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT2(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT2(...) "BGXX_CMRX_RX_STAT2"


/**
 * RSL - bgx#_cmr#_rx_stat3
 *
 * These registers provide a count of octets of received PAUSE and control packets.
 *
 */
typedef union bdk_bgxx_cmrx_rx_stat3 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Octet count of received PAUSE packets. CNT will wrap and is cleared if LMAC is disabled
                                                                 with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat3_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat3_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat3_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat3_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT3(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT3(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000088ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT3", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT3(...) bdk_bgxx_cmrx_rx_stat3_t
#define bustype_BDK_BGXX_CMRX_RX_STAT3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT3(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT3(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT3(...) "BGXX_CMRX_RX_STAT3"


/**
 * RSL - bgx#_cmr#_rx_stat4
 *
 * These registers provide a count of all packets received that were dropped by the DMAC filter.
 * Packets that match the DMAC are dropped and counted here regardless of whether they were ERR
 * packets, but does not include those reported in BGX()_CMR()_RX_STAT6. These packets
 * are never counted in BGX()_CMR()_RX_STAT0. Eight-byte packets as the result of
 * truncation or other means are not dropped by CNXXXX and will never appear in this count.
 */
typedef union bdk_bgxx_cmrx_rx_stat4 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of filtered DMAC packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat4_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat4_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat4_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat4_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT4(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT4(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000090ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT4", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT4(...) bdk_bgxx_cmrx_rx_stat4_t
#define bustype_BDK_BGXX_CMRX_RX_STAT4(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT4(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT4(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT4(...) "BGXX_CMRX_RX_STAT4"


/**
 * RSL - bgx#_cmr#_rx_stat5
 *
 * These registers provide a count of octets of filtered DMAC packets.
 *
 */
typedef union bdk_bgxx_cmrx_rx_stat5 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Octet count of filtered DMAC packets. CNT will wrap and is cleared if LMAC is disabled
                                                                 with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat5_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat5_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat5_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat5_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT5(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT5(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000098ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT5", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT5(...) bdk_bgxx_cmrx_rx_stat5_t
#define bustype_BDK_BGXX_CMRX_RX_STAT5(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT5(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT5(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT5(...) "BGXX_CMRX_RX_STAT5"


/**
 * RSL - bgx#_cmr#_rx_stat6
 *
 * These registers provide a count of all packets received that were dropped due to a full
 * receive FIFO. They do not count any packet that is truncated at the point of overflow and sent
 * on to the NIC. These registers count all entire packets dropped by the FIFO for a given LMAC
 * regardless of DMAC or PAUSE type.
 */
typedef union bdk_bgxx_cmrx_rx_stat6 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of dropped packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat6_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat6_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat6_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat6_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT6(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT6(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000A0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT6", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT6(...) bdk_bgxx_cmrx_rx_stat6_t
#define bustype_BDK_BGXX_CMRX_RX_STAT6(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT6(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT6(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT6(...) "BGXX_CMRX_RX_STAT6"


/**
 * RSL - bgx#_cmr#_rx_stat7
 *
 * These registers provide a count of octets of received packets that were dropped due to a full
 * receive FIFO.
 */
typedef union bdk_bgxx_cmrx_rx_stat7 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Octet count of dropped packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat7_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat7_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat7_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat7_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT7(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT7(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000A8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT7", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT7(...) bdk_bgxx_cmrx_rx_stat7_t
#define bustype_BDK_BGXX_CMRX_RX_STAT7(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT7(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT7(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT7(...) "BGXX_CMRX_RX_STAT7"


/**
 * RSL - bgx#_cmr#_rx_stat8
 *
 * These registers provide a count of all packets received with some error that were not dropped
 * either due to the DMAC filter or lack of room in the receive FIFO.
 * This does not include packets which were counted in
 * BGX()_CMR()_RX_STAT2, BGX()_CMR()_RX_STAT4 nor
 * BGX()_CMR()_RX_STAT6.
 *
 * Which statistics are updated on control packet errors and drops are shown below:
 *
 * \<pre\>
 * if dropped {
 *   if !errored STAT8
 *   if overflow STAT6
 *   else if dmac drop STAT4
 *   else if filter drop STAT2
 * } else {
 *   if errored STAT2
 *   else STAT8
 * }
 * \</pre\>
 */
typedef union bdk_bgxx_cmrx_rx_stat8 {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_stat8_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of error packets. CNT will wrap and is cleared if LMAC is disabled with
                                                                 BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_stat8_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_stat8_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_stat8_s    cn88xxp1; */
} bdk_bgxx_cmrx_rx_stat8_t;

static inline uint64_t BDK_BGXX_CMRX_RX_STAT8(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_STAT8(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000B0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_STAT8", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_STAT8(...) bdk_bgxx_cmrx_rx_stat8_t
#define bustype_BDK_BGXX_CMRX_RX_STAT8(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_STAT8(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_STAT8(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_STAT8(...) "BGXX_CMRX_RX_STAT8"


/**
 * RSL - bgx#_cmr#_rx_weight
 */
typedef union bdk_bgxx_cmrx_rx_weight {
	uint64_t u;
	struct bdk_bgxx_cmrx_rx_weight_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t weight                      : 4;  /**< R/W - For the weighted round robin algorithm in CMR RXB, weight to assign for this LMAC relative
                                                                 to other LMAC weights. Defaults to round-robin (non-weighted minimum setting of 0x1). A
                                                                 setting of 0x0 effectively takes the LMAC out of eligibility. */
#else
		uint64_t weight                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_rx_weight_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_rx_weight_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_rx_weight_s   cn88xxp1; */
} bdk_bgxx_cmrx_rx_weight_t;

static inline uint64_t BDK_BGXX_CMRX_RX_WEIGHT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_RX_WEIGHT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00000E0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_RX_WEIGHT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_RX_WEIGHT(...) bdk_bgxx_cmrx_rx_weight_t
#define bustype_BDK_BGXX_CMRX_RX_WEIGHT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_RX_WEIGHT(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_RX_WEIGHT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_RX_WEIGHT(...) "BGXX_CMRX_RX_WEIGHT"


/**
 * RSL - bgx#_cmr#_tx_channel
 */
typedef union bdk_bgxx_cmrx_tx_channel {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_channel_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t msk                         : 16; /**< R/W - Backpressure channel mask. BGX can completely ignore the channel backpressure for channel
                                                                 specified by this field. Any channel in which MSK\<n\> is set never sends backpressure
                                                                 information to PKO. */
		uint64_t dis                         : 16; /**< R/W - Credit return backpressure disable. BGX stops returning channel credits for any channel
                                                                 that is backpressured. These bits can be used to override that. If DIS\<n\> is set, channel
                                                                 credits may flow back regardless of the backpressure for that channel. */
#else
		uint64_t dis                         : 16;
		uint64_t msk                         : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_channel_s  cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_channel_s  cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_channel_s  cn88xxp1; */
} bdk_bgxx_cmrx_tx_channel_t;

static inline uint64_t BDK_BGXX_CMRX_TX_CHANNEL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_CHANNEL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000500ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_CHANNEL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_CHANNEL(...) bdk_bgxx_cmrx_tx_channel_t
#define bustype_BDK_BGXX_CMRX_TX_CHANNEL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_CHANNEL(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_CHANNEL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_CHANNEL(...) "BGXX_CMRX_TX_CHANNEL"


/**
 * RSL - bgx#_cmr#_tx_fifo_len
 */
typedef union bdk_bgxx_cmrx_tx_fifo_len {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_fifo_len_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t lmac_idle                   : 1;  /**< RO/H - Idle signal to identify when all credits and other pipeline buffers are also cleared out
                                                                 and LMAC can be considered IDLE in the BGX CMR TX. */
		uint64_t fifo_len                    : 14; /**< RO/H - Per-LMAC TXB main FIFO length. Useful for determining if main FIFO is empty when bringing
                                                                 an LMAC down. */
#else
		uint64_t fifo_len                    : 14;
		uint64_t lmac_idle                   : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_fifo_len_s cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_fifo_len_s cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_fifo_len_s cn88xxp1; */
} bdk_bgxx_cmrx_tx_fifo_len_t;

static inline uint64_t BDK_BGXX_CMRX_TX_FIFO_LEN(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_FIFO_LEN(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000518ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_FIFO_LEN", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_FIFO_LEN(...) bdk_bgxx_cmrx_tx_fifo_len_t
#define bustype_BDK_BGXX_CMRX_TX_FIFO_LEN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_FIFO_LEN(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_FIFO_LEN(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_FIFO_LEN(...) "BGXX_CMRX_TX_FIFO_LEN"


/**
 * RSL - bgx#_cmr#_tx_hg2_status
 */
typedef union bdk_bgxx_cmrx_tx_hg2_status {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_hg2_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t xof                         : 16; /**< RO/H - 16-bit XOF back pressure vector from HiGig2 message packet or from PFC/CBFC packets. Non-
                                                                 zero only when logical back pressure is active. All bits are 0 when LGTIM2GO=0x0. */
		uint64_t lgtim2go                    : 16; /**< RO/H - Logical packet flow back pressure time remaining. Initial value set from XOF time field of
                                                                 HiGig2 message packet received or a function of the enabled and current timers for
                                                                 PFC/CBFC packets. Non-zero only when logical back pressure is active. */
#else
		uint64_t lgtim2go                    : 16;
		uint64_t xof                         : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_hg2_status_s cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_hg2_status_s cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_hg2_status_s cn88xxp1; */
} bdk_bgxx_cmrx_tx_hg2_status_t;

static inline uint64_t BDK_BGXX_CMRX_TX_HG2_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_HG2_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000510ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_HG2_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_HG2_STATUS(...) bdk_bgxx_cmrx_tx_hg2_status_t
#define bustype_BDK_BGXX_CMRX_TX_HG2_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_HG2_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_HG2_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_HG2_STATUS(...) "BGXX_CMRX_TX_HG2_STATUS"


/**
 * RSL - bgx#_cmr#_tx_ovr_bp
 */
typedef union bdk_bgxx_cmrx_tx_ovr_bp {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_ovr_bp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t tx_chan_bp                  : 16; /**< R/W - Per-channel backpressure status sent to PKO.
                                                                 0 = channel is available.
                                                                 1 = channel should be backpressured. */
#else
		uint64_t tx_chan_bp                  : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_ovr_bp_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_ovr_bp_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_ovr_bp_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_ovr_bp_t;

static inline uint64_t BDK_BGXX_CMRX_TX_OVR_BP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_OVR_BP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000520ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_OVR_BP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_OVR_BP(...) bdk_bgxx_cmrx_tx_ovr_bp_t
#define bustype_BDK_BGXX_CMRX_TX_OVR_BP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_OVR_BP(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_OVR_BP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_OVR_BP(...) "BGXX_CMRX_TX_OVR_BP"


/**
 * RSL - bgx#_cmr#_tx_stat0
 */
typedef union bdk_bgxx_cmrx_tx_stat0 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t xscol                       : 48; /**< R/W/H - Number of packets dropped (never successfully sent) due to excessive collision. Defined by
                                                                 BGX()_GMP_GMI_TX_COL_ATTEMPT[LIMIT]. SGMII/1000Base-X half-duplex only.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t xscol                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat0_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat0_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat0_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat0_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000600ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT0(...) bdk_bgxx_cmrx_tx_stat0_t
#define bustype_BDK_BGXX_CMRX_TX_STAT0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT0(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT0(...) "BGXX_CMRX_TX_STAT0"


/**
 * RSL - bgx#_cmr#_tx_stat1
 */
typedef union bdk_bgxx_cmrx_tx_stat1 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t xsdef                       : 48; /**< R/W/H - Number of packets dropped (never successfully sent) due to excessive deferral.
                                                                 SGMII/1000BASE-X half-duplex only.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t xsdef                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat1_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat1_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat1_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat1_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000608ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT1(...) bdk_bgxx_cmrx_tx_stat1_t
#define bustype_BDK_BGXX_CMRX_TX_STAT1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT1(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT1(...) "BGXX_CMRX_TX_STAT1"


/**
 * RSL - bgx#_cmr#_tx_stat10
 */
typedef union bdk_bgxx_cmrx_tx_stat10 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat10_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist4                       : 48; /**< R/W/H - Number of packets sent with an octet count between 256-511. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or
                                                                 EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist4                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat10_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat10_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat10_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat10_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT10(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT10(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000650ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT10", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT10(...) bdk_bgxx_cmrx_tx_stat10_t
#define bustype_BDK_BGXX_CMRX_TX_STAT10(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT10(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT10(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT10(...) "BGXX_CMRX_TX_STAT10"


/**
 * RSL - bgx#_cmr#_tx_stat11
 */
typedef union bdk_bgxx_cmrx_tx_stat11 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat11_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist5                       : 48; /**< R/W/H - Number of packets sent with an octet count between 512-1023. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or
                                                                 EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist5                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat11_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat11_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat11_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat11_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT11(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT11(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000658ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT11", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT11(...) bdk_bgxx_cmrx_tx_stat11_t
#define bustype_BDK_BGXX_CMRX_TX_STAT11(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT11(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT11(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT11(...) "BGXX_CMRX_TX_STAT11"


/**
 * RSL - bgx#_cmr#_tx_stat12
 */
typedef union bdk_bgxx_cmrx_tx_stat12 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist6                       : 48; /**< R/W/H - Number of packets sent with an octet count between 1024-1518. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or
                                                                 EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist6                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat12_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat12_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat12_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat12_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT12(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT12(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000660ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT12", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT12(...) bdk_bgxx_cmrx_tx_stat12_t
#define bustype_BDK_BGXX_CMRX_TX_STAT12(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT12(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT12(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT12(...) "BGXX_CMRX_TX_STAT12"


/**
 * RSL - bgx#_cmr#_tx_stat13
 */
typedef union bdk_bgxx_cmrx_tx_stat13 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat13_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist7                       : 48; /**< R/W/H - Number of packets sent with an octet count \> 1518. Packet length is the sum of all data
                                                                 transmitted on the wire for the given packet including packet data, pad bytes, FCS bytes,
                                                                 PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND
                                                                 cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist7                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat13_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat13_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat13_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat13_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT13(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT13(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000668ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT13", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT13(...) bdk_bgxx_cmrx_tx_stat13_t
#define bustype_BDK_BGXX_CMRX_TX_STAT13(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT13(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT13(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT13(...) "BGXX_CMRX_TX_STAT13"


/**
 * RSL - bgx#_cmr#_tx_stat14
 */
typedef union bdk_bgxx_cmrx_tx_stat14 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat14_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t bcst                        : 48; /**< R/W/H - Number of packets sent to broadcast DMAC. Does not include MCST packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap.

                                                                 Note that BGX determines if the packet is MCST or BCST from the DMAC of the packet. BGX
                                                                 assumes that the DMAC lies in the first six bytes of the packet as per the 802.3 frame
                                                                 definition. If the system requires additional data before the L2 header, the MCST and BCST
                                                                 counters may not reflect reality and should be ignored by software. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t bcst                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat14_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat14_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat14_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat14_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT14(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT14(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000670ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT14", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT14(...) bdk_bgxx_cmrx_tx_stat14_t
#define bustype_BDK_BGXX_CMRX_TX_STAT14(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT14(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT14(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT14(...) "BGXX_CMRX_TX_STAT14"


/**
 * RSL - bgx#_cmr#_tx_stat15
 */
typedef union bdk_bgxx_cmrx_tx_stat15 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat15_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t mcst                        : 48; /**< R/W/H - Number of packets sent to multicast DMAC. Does not include BCST packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap.

                                                                 Note that BGX determines if the packet is MCST or BCST from the DMAC of the packet. BGX
                                                                 assumes that the DMAC lies in the first six bytes of the packet as per the 802.3 frame
                                                                 definition. If the system requires additional data before the L2 header, then the MCST and
                                                                 BCST counters may not reflect reality and should be ignored by software. Cleared if LMAC
                                                                 is disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t mcst                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat15_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat15_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat15_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat15_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT15(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT15(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000678ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT15", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT15(...) bdk_bgxx_cmrx_tx_stat15_t
#define bustype_BDK_BGXX_CMRX_TX_STAT15(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT15(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT15(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT15(...) "BGXX_CMRX_TX_STAT15"


/**
 * RSL - bgx#_cmr#_tx_stat16
 */
typedef union bdk_bgxx_cmrx_tx_stat16 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat16_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t undflw                      : 48; /**< R/W/H - Number of underflow packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t undflw                      : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat16_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat16_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat16_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat16_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT16(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT16(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000680ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT16", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT16(...) bdk_bgxx_cmrx_tx_stat16_t
#define bustype_BDK_BGXX_CMRX_TX_STAT16(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT16(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT16(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT16(...) "BGXX_CMRX_TX_STAT16"


/**
 * RSL - bgx#_cmr#_tx_stat17
 */
typedef union bdk_bgxx_cmrx_tx_stat17 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat17_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t ctl                         : 48; /**< R/W/H - Number of control packets (PAUSE flow control) generated by BGX. It does not include
                                                                 control packets forwarded or generated by the cores.
                                                                 CTL counts the number of generated PFC frames and does not track the number of generated
                                                                 HG2 messages.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t ctl                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat17_s   cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat17_s   cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat17_s   cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat17_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT17(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT17(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000688ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT17", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT17(...) bdk_bgxx_cmrx_tx_stat17_t
#define bustype_BDK_BGXX_CMRX_TX_STAT17(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT17(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT17(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT17(...) "BGXX_CMRX_TX_STAT17"


/**
 * RSL - bgx#_cmr#_tx_stat2
 */
typedef union bdk_bgxx_cmrx_tx_stat2 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t mcol                        : 48; /**< R/W/H - Number of packets sent with multiple collisions. Must be less than
                                                                 BGX()_GMP_GMI_TX_COL_ATTEMPT[LIMIT]. SGMII/1000BASE-X half-duplex only.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t mcol                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat2_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat2_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat2_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat2_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000610ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT2(...) bdk_bgxx_cmrx_tx_stat2_t
#define bustype_BDK_BGXX_CMRX_TX_STAT2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT2(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT2(...) "BGXX_CMRX_TX_STAT2"


/**
 * RSL - bgx#_cmr#_tx_stat3
 */
typedef union bdk_bgxx_cmrx_tx_stat3 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t scol                        : 48; /**< R/W/H - Number of packets sent with a single collision. SGMII/1000BASE-X half-duplex only.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t scol                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat3_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat3_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat3_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat3_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT3(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT3(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000618ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT3", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT3(...) bdk_bgxx_cmrx_tx_stat3_t
#define bustype_BDK_BGXX_CMRX_TX_STAT3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT3(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT3(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT3(...) "BGXX_CMRX_TX_STAT3"


/**
 * RSL - bgx#_cmr#_tx_stat4
 */
typedef union bdk_bgxx_cmrx_tx_stat4 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t octs                        : 48; /**< R/W/H - Number of total octets sent on the interface. Does not count octets from frames that were
                                                                 truncated due to collisions in half-duplex mode.
                                                                 Octet counts are the sum of all data transmitted on the wire including packet data, pad
                                                                 bytes, FCS bytes, PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE
                                                                 byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t octs                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat4_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat4_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat4_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat4_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT4(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT4(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000620ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT4", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT4(...) bdk_bgxx_cmrx_tx_stat4_t
#define bustype_BDK_BGXX_CMRX_TX_STAT4(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT4(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT4(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT4(...) "BGXX_CMRX_TX_STAT4"


/**
 * RSL - bgx#_cmr#_tx_stat5
 */
typedef union bdk_bgxx_cmrx_tx_stat5 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t pkts                        : 48; /**< R/W/H - Number of total frames sent on the interface. Does not count octets from frames that were
                                                                 truncated due to collisions in half-duplex mode.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t pkts                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat5_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat5_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat5_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat5_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT5(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT5(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000628ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT5", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT5(...) bdk_bgxx_cmrx_tx_stat5_t
#define bustype_BDK_BGXX_CMRX_TX_STAT5(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT5(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT5(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT5(...) "BGXX_CMRX_TX_STAT5"


/**
 * RSL - bgx#_cmr#_tx_stat6
 */
typedef union bdk_bgxx_cmrx_tx_stat6 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist0                       : 48; /**< R/W/H - Number of packets sent with an octet count \< 64. Packet length is the sum of all data
                                                                 transmitted on the wire for the given packet including packet data, pad bytes, FCS bytes,
                                                                 PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND
                                                                 cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist0                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat6_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat6_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat6_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat6_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT6(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT6(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000630ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT6", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT6(...) bdk_bgxx_cmrx_tx_stat6_t
#define bustype_BDK_BGXX_CMRX_TX_STAT6(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT6(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT6(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT6(...) "BGXX_CMRX_TX_STAT6"


/**
 * RSL - bgx#_cmr#_tx_stat7
 */
typedef union bdk_bgxx_cmrx_tx_stat7 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist1                       : 48; /**< R/W/H - Number of packets sent with an octet count of 64. Packet length is the sum of all data
                                                                 transmitted on the wire for the given packet including packet data, pad bytes, FCS bytes,
                                                                 PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND
                                                                 cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist1                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat7_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat7_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat7_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat7_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT7(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT7(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000638ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT7", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT7(...) bdk_bgxx_cmrx_tx_stat7_t
#define bustype_BDK_BGXX_CMRX_TX_STAT7(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT7(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT7(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT7(...) "BGXX_CMRX_TX_STAT7"


/**
 * RSL - bgx#_cmr#_tx_stat8
 */
typedef union bdk_bgxx_cmrx_tx_stat8 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat8_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist2                       : 48; /**< R/W/H - Number of packets sent with an octet count between 65-127. Packet length is the sum of all
                                                                 data transmitted on the wire for the given packet including packet data, pad bytes, FCS
                                                                 bytes, PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND
                                                                 cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist2                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat8_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat8_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat8_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat8_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT8(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT8(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000640ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT8", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT8(...) bdk_bgxx_cmrx_tx_stat8_t
#define bustype_BDK_BGXX_CMRX_TX_STAT8(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT8(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT8(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT8(...) "BGXX_CMRX_TX_STAT8"


/**
 * RSL - bgx#_cmr#_tx_stat9
 */
typedef union bdk_bgxx_cmrx_tx_stat9 {
	uint64_t u;
	struct bdk_bgxx_cmrx_tx_stat9_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t hist3                       : 48; /**< R/W/H - Number of packets sent with an octet count between 128-255. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, PAUSE bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or
                                                                 EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with BGX()_CMR()_CONFIG[ENABLE]=0. */
#else
		uint64_t hist3                       : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmrx_tx_stat9_s    cn85xx; */
	/* struct bdk_bgxx_cmrx_tx_stat9_s    cn88xx; */
	/* struct bdk_bgxx_cmrx_tx_stat9_s    cn88xxp1; */
} bdk_bgxx_cmrx_tx_stat9_t;

static inline uint64_t BDK_BGXX_CMRX_TX_STAT9(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMRX_TX_STAT9(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0000648ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_CMRX_TX_STAT9", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMRX_TX_STAT9(...) bdk_bgxx_cmrx_tx_stat9_t
#define bustype_BDK_BGXX_CMRX_TX_STAT9(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMRX_TX_STAT9(p1,p2) (p1)
#define arguments_BDK_BGXX_CMRX_TX_STAT9(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMRX_TX_STAT9(...) "BGXX_CMRX_TX_STAT9"


/**
 * RSL - bgx#_cmr_bad
 */
typedef union bdk_bgxx_cmr_bad {
	uint64_t u;
	struct bdk_bgxx_cmr_bad_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t rxb_nxl                     : 1;  /**< R/W1C/H - Receive side LMAC ID \> BGX()_CMR_RX_LMACS. */
#else
		uint64_t rxb_nxl                     : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_bgxx_cmr_bad_s          cn85xx; */
	/* struct bdk_bgxx_cmr_bad_s          cn88xx; */
	/* struct bdk_bgxx_cmr_bad_s          cn88xxp1; */
} bdk_bgxx_cmr_bad_t;

static inline uint64_t BDK_BGXX_CMR_BAD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_BAD(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0001020ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_BAD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_BAD(...) bdk_bgxx_cmr_bad_t
#define bustype_BDK_BGXX_CMR_BAD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_BAD(p1) (p1)
#define arguments_BDK_BGXX_CMR_BAD(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_BAD(...) "BGXX_CMR_BAD"


/**
 * RSL - bgx#_cmr_bist_status
 */
typedef union bdk_bgxx_cmr_bist_status {
	uint64_t u;
	struct bdk_bgxx_cmr_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t status                      : 25; /**< RO/H - "BIST results. Hardware sets a bit to 1 for memory that fails; 0 indicates pass or never
                                                                 run. INTERNAL:
                                                                 \<0\> = bgx\#.rxb.infif_gmp
                                                                 \<1\> = bgx\#.rxb.infif_smu
                                                                 \<2\> = bgx\#.rxb.fif_bnk00
                                                                 \<3\> = bgx\#.rxb.fif_bnk01
                                                                 \<4\> = bgx\#.rxb.fif_bnk10
                                                                 \<5\> = bgx\#.rxb.fif_bnk11
                                                                 \<6\> = bgx\#.rxb.skd_fif
                                                                 \<7\> = bgx\#.rxb_mix0_fif
                                                                 \<8\> = bgx\#.rxb_mix1_fif
                                                                 \<9\> = RAZ
                                                                 \<10\> = bgx\#.txb_fif_bnk0
                                                                 \<11\> = bgx\#.txb_fif_bnk1
                                                                 \<12\> = bgx\#.txb_skd_m0_fif
                                                                 \<13\> = bgx\#.txb_skd_m1_fif
                                                                 \<14\> = bgx\#.txb_skd_m2_fif
                                                                 \<15\> = bgx\#.txb_skd_m3_fif
                                                                 \<16\> = bgx\#.txb_mix0_fif
                                                                 \<17\> = bgx\#.txb_mix1_fif
                                                                 \<18\> = bgx\#.txb_ncsi_fif
                                                                 \<24:19\> = RAZ" */
#else
		uint64_t status                      : 25;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_bgxx_cmr_bist_status_s  cn85xx; */
	/* struct bdk_bgxx_cmr_bist_status_s  cn88xx; */
	/* struct bdk_bgxx_cmr_bist_status_s  cn88xxp1; */
} bdk_bgxx_cmr_bist_status_t;

static inline uint64_t BDK_BGXX_CMR_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000460ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_BIST_STATUS(...) bdk_bgxx_cmr_bist_status_t
#define bustype_BDK_BGXX_CMR_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_BIST_STATUS(p1) (p1)
#define arguments_BDK_BGXX_CMR_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_BIST_STATUS(...) "BGXX_CMR_BIST_STATUS"


/**
 * RSL - bgx#_cmr_chan_msk_and
 */
typedef union bdk_bgxx_cmr_chan_msk_and {
	uint64_t u;
	struct bdk_bgxx_cmr_chan_msk_and_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t msk_and                     : 64; /**< R/W - Assert physical backpressure when the backpressure channel vector combined with MSK_AND
                                                                 indicates backpressure as follows:
                                                                 _ phys_bp_msk_and = (CHAN_VECTOR\<x:y\> & MSK_AND\<x:y\>) == MSK_AND\<x:y\>
                                                                 _ phys_bp = phys_bp_msk_or || phys_bp_msk_and

                                                                 In single LMAC configurations, x = 63, y = 0.

                                                                 In multi-LMAC configurations, x/y are set as follows:
                                                                 _ LMAC interface 0, x = 15, y = 0.
                                                                 _ LMAC interface 1, x = 31, y = 16.
                                                                 _ LMAC interface 2, x = 47, y = 32.
                                                                 _ LMAC interface 3, x = 63, y = 48. */
#else
		uint64_t msk_and                     : 64;
#endif
	} s;
	/* struct bdk_bgxx_cmr_chan_msk_and_s cn85xx; */
	/* struct bdk_bgxx_cmr_chan_msk_and_s cn88xx; */
	/* struct bdk_bgxx_cmr_chan_msk_and_s cn88xxp1; */
} bdk_bgxx_cmr_chan_msk_and_t;

static inline uint64_t BDK_BGXX_CMR_CHAN_MSK_AND(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_CHAN_MSK_AND(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000450ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_CHAN_MSK_AND", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_CHAN_MSK_AND(...) bdk_bgxx_cmr_chan_msk_and_t
#define bustype_BDK_BGXX_CMR_CHAN_MSK_AND(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_CHAN_MSK_AND(p1) (p1)
#define arguments_BDK_BGXX_CMR_CHAN_MSK_AND(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_CHAN_MSK_AND(...) "BGXX_CMR_CHAN_MSK_AND"


/**
 * RSL - bgx#_cmr_chan_msk_or
 */
typedef union bdk_bgxx_cmr_chan_msk_or {
	uint64_t u;
	struct bdk_bgxx_cmr_chan_msk_or_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t msk_or                      : 64; /**< R/W - Assert physical backpressure when the backpressure channel vector combined with MSK_OR
                                                                 indicates backpressure as follows:

                                                                 _ phys_bp_msk_or = (CHAN_VECTOR\<x:y\> & MSK_AND\<x:y\>) & MSK_OR\<x:y\>
                                                                 _ phys_bp = phys_bp_msk_or || phys_bp_msk_and

                                                                 In single LMAC configurations, x = 63, y = 0.

                                                                 In multi-LMAC configurations, x/y are set as follows:
                                                                 _ LMAC interface 0, x = 15, y = 0.
                                                                 _ LMAC interface 1, x = 31, y = 16.
                                                                 _ LMAC interface 2, x = 47, y = 32.
                                                                 _ LMAC interface 3, x = 63, y = 48. */
#else
		uint64_t msk_or                      : 64;
#endif
	} s;
	/* struct bdk_bgxx_cmr_chan_msk_or_s  cn85xx; */
	/* struct bdk_bgxx_cmr_chan_msk_or_s  cn88xx; */
	/* struct bdk_bgxx_cmr_chan_msk_or_s  cn88xxp1; */
} bdk_bgxx_cmr_chan_msk_or_t;

static inline uint64_t BDK_BGXX_CMR_CHAN_MSK_OR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_CHAN_MSK_OR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000458ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_CHAN_MSK_OR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_CHAN_MSK_OR(...) bdk_bgxx_cmr_chan_msk_or_t
#define bustype_BDK_BGXX_CMR_CHAN_MSK_OR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_CHAN_MSK_OR(p1) (p1)
#define arguments_BDK_BGXX_CMR_CHAN_MSK_OR(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_CHAN_MSK_OR(...) "BGXX_CMR_CHAN_MSK_OR"


/**
 * RSL - bgx#_cmr_global_config
 *
 * These registers configure the global CMR, PCS, and MAC.
 *
 */
typedef union bdk_bgxx_cmr_global_config {
	uint64_t u;
	struct bdk_bgxx_cmr_global_config_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t cmr_ncsi_reset              : 1;  /**< R/W - Interface reset for the CMR NCSI block.
                                                                 Upon power up the CMR NCSI is in reset and the companion CNXXXX NCSI block will be
                                                                 commanded by the
                                                                 external BMC to enable one of the CNXXXX BGX NCSI interfaces for passing network traffic.
                                                                 Only one NCSI interface can be enabled in CNXXXX.  The BMC/NCSI will then proceed to
                                                                 configure
                                                                 the rest of the BGX csr for pass through traffic.

                                                                 When set, will reset the CMR NCSI interface effectively disabling it at a traffic boundary
                                                                 should traffic be flowing.  This bit will not reset the main RXB fifos. */
		uint64_t cmr_ncsi_drop               : 1;  /**< R/W - NCSI drop.
                                                                 1 = Cleanly drop traffic going into the NCSI block of BGX.  Must set asserted
                                                                 with with CMR_X2P_RESET=1 (in the same write operation) to avoid partial packets
                                                                 to the NCSI interface while performing a X2P partner reset.
                                                                 0 = Allow traffic to flow through the NCSI block. */
		uint64_t ncsi_lmac_id                : 2;  /**< R/W - Logical MAC ID that carries NCSI traffic for both RX and TX side of CMR.  On the RX side
                                                                 is
                                                                 also the LMAC_ID that is eligible for steering. */
		uint64_t fcs_strip                   : 1;  /**< R/W - A setting of 1 means the BGX strip the FCS bytes of every packet.  For packets less than 4
                                                                 bytes, the packet will be removed.
                                                                 A setting of 0 means the BGX will not modify or remove the FCS bytes. */
		uint64_t interleave_mode             : 1;  /**< R/W - A setting of 0 means the BGX will operate in non-interleaved mode where there is 1 packet
                                                                 from a given lmac in flight on the X2P interface.  A setting of 1 means the BGX will
                                                                 operate
                                                                 in interleaved mode where each valid consecutive cycle on the X2P interface may contain
                                                                 words
                                                                 from different lmacs.  In other words there will be multiple packets in flight from
                                                                 different
                                                                 lmacs at the same time. */
		uint64_t cmr_mix1_reset              : 1;  /**< R/W - Must be 0. */
		uint64_t cmr_mix0_reset              : 1;  /**< R/W - Must be 0. */
		uint64_t cmr_x2p_reset               : 1;  /**< R/W - If the NIC block is reset, software also needs to reset the X2P interface in the BGX by
                                                                 setting this bit to 1. It resets the X2P interface state in the BGX (skid FIFO and pending
                                                                 requests to NIC) and prevents the RXB FIFOs for all LMACs from pushing data to the
                                                                 interface. Because the X2P and NCSI interfaces share the main RXB fifos it will also
                                                                 impact the NCSI interface therefore it is required to set CMR_NCSI_DROP bit first before
                                                                 setting this bit.

                                                                 Setting this bit to 0 does not reset the X2P interface nor NCSI interface.
                                                                 After NIC comes out of reset, software should clear CMR_X2P_RESET. */
		uint64_t bgx_clk_enable              : 1;  /**< R/W - The global clock enable for BGX. Setting this bit overrides clock enables set by
                                                                 BGX()_CMR()_CONFIG[ENABLE] and BGX()_CMR()_CONFIG[LMAC_TYPE], essentially
                                                                 turning on clocks for the entire BGX. Setting this bit to 0 results in not overriding
                                                                 clock enables set by BGX()_CMR()_CONFIG[ENABLE] and
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]. */
		uint64_t pmux_sds_sel                : 1;  /**< R/W - SerDes/QLM output select. Specifies which QLM output is selected as the BGX input, as
                                                                 follows:

                                                                 \<pre\>
                                                                   Block   PMUX_SDS_SEL=0  PMUX_SDS_SEL=1
                                                                   --------------------------------------
                                                                   BGX0:   QLM0            QLM2
                                                                   BGX1:   QLM1            QLM3
                                                                   BGX2:   QLM4            N/A
                                                                   BGX3:   QLM5            N/A
                                                                   BGX4:   QLM6            N/A
                                                                   BGX5:   QLM7            N/A
                                                                 \</pre\> */
#else
		uint64_t pmux_sds_sel                : 1;
		uint64_t bgx_clk_enable              : 1;
		uint64_t cmr_x2p_reset               : 1;
		uint64_t cmr_mix0_reset              : 1;
		uint64_t cmr_mix1_reset              : 1;
		uint64_t interleave_mode             : 1;
		uint64_t fcs_strip                   : 1;
		uint64_t ncsi_lmac_id                : 2;
		uint64_t cmr_ncsi_drop               : 1;
		uint64_t cmr_ncsi_reset              : 1;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_bgxx_cmr_global_config_s cn85xx; */
	/* struct bdk_bgxx_cmr_global_config_s cn88xx; */
	/* struct bdk_bgxx_cmr_global_config_s cn88xxp1; */
} bdk_bgxx_cmr_global_config_t;

static inline uint64_t BDK_BGXX_CMR_GLOBAL_CONFIG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_GLOBAL_CONFIG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_GLOBAL_CONFIG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_GLOBAL_CONFIG(...) bdk_bgxx_cmr_global_config_t
#define bustype_BDK_BGXX_CMR_GLOBAL_CONFIG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_GLOBAL_CONFIG(p1) (p1)
#define arguments_BDK_BGXX_CMR_GLOBAL_CONFIG(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_GLOBAL_CONFIG(...) "BGXX_CMR_GLOBAL_CONFIG"


/**
 * RSL - bgx#_cmr_mem_ctrl
 */
typedef union bdk_bgxx_cmr_mem_ctrl {
	uint64_t u;
	struct bdk_bgxx_cmr_mem_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t txb_ncsi_synd               : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
		uint64_t txb_ncsi_cor_dis            : 1;  /**< R/W - ECC-correction disable for the TXB SKID FIFO */
		uint64_t txb_skid_m3_synd            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
		uint64_t txb_skid_m3_cor_dis         : 1;  /**< R/W - ECC-correction disable for the TXB SKID FIFO */
		uint64_t txb_skid_m2_synd            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
		uint64_t txb_skid_m2_cor_dis         : 1;  /**< R/W - ECC-correction disable for the TXB SKID FIFO */
		uint64_t txb_skid_m1_synd            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
		uint64_t txb_skid_m1_cor_dis         : 1;  /**< R/W - ECC-correction disable for the TXB SKID FIFO */
		uint64_t txb_skid_m0_synd            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO. */
		uint64_t txb_skid_m0_cor_dis         : 1;  /**< R/W - ECC-correction disable for the TXB SKID FIFO. */
		uint64_t txb_fif_bk1_syn             : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for TXB main bank1. */
		uint64_t txb_fif_bk1_cdis            : 1;  /**< R/W - ECC-correction disable for the TXB main bank1. */
		uint64_t txb_fif_bk0_syn             : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for TXB main bank0. */
		uint64_t txb_fif_bk0_cdis            : 1;  /**< R/W - ECC-correction disable for the TXB main bank0. */
		uint64_t rxb_skid_synd               : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for RXB SKID FIFO. */
		uint64_t rxb_skid_cor_dis            : 1;  /**< R/W - ECC-correction disable for the RXB SKID FIFO. */
		uint64_t rxb_fif_bk1_syn1            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for RXB main bank1 srf1. */
		uint64_t rxb_fif_bk1_cdis1           : 1;  /**< R/W - ECC-correction disable for the RXB main bank1 srf1. */
		uint64_t rxb_fif_bk1_syn0            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for RXB main bank1 srf0. */
		uint64_t rxb_fif_bk1_cdis0           : 1;  /**< R/W - ECC-correction disable for the RXB main bank1 srf0. */
		uint64_t rxb_fif_bk0_syn1            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for RXB main bank0 srf1. */
		uint64_t rxb_fif_bk0_cdis1           : 1;  /**< R/W - ECC-correction disable for the RXB main bank0 srf1. */
		uint64_t rxb_fif_bk0_syn0            : 2;  /**< R/W - Syndrome to flip and generate single-bit/double-bit error for RXB main bank0 srf0. */
		uint64_t rxb_fif_bk0_cdis0           : 1;  /**< R/W - ECC-correction disable for the RXB main bank0 srf0. */
#else
		uint64_t rxb_fif_bk0_cdis0           : 1;
		uint64_t rxb_fif_bk0_syn0            : 2;
		uint64_t rxb_fif_bk0_cdis1           : 1;
		uint64_t rxb_fif_bk0_syn1            : 2;
		uint64_t rxb_fif_bk1_cdis0           : 1;
		uint64_t rxb_fif_bk1_syn0            : 2;
		uint64_t rxb_fif_bk1_cdis1           : 1;
		uint64_t rxb_fif_bk1_syn1            : 2;
		uint64_t rxb_skid_cor_dis            : 1;
		uint64_t rxb_skid_synd               : 2;
		uint64_t txb_fif_bk0_cdis            : 1;
		uint64_t txb_fif_bk0_syn             : 2;
		uint64_t txb_fif_bk1_cdis            : 1;
		uint64_t txb_fif_bk1_syn             : 2;
		uint64_t txb_skid_m0_cor_dis         : 1;
		uint64_t txb_skid_m0_synd            : 2;
		uint64_t txb_skid_m1_cor_dis         : 1;
		uint64_t txb_skid_m1_synd            : 2;
		uint64_t txb_skid_m2_cor_dis         : 1;
		uint64_t txb_skid_m2_synd            : 2;
		uint64_t txb_skid_m3_cor_dis         : 1;
		uint64_t txb_skid_m3_synd            : 2;
		uint64_t txb_ncsi_cor_dis            : 1;
		uint64_t txb_ncsi_synd               : 2;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_bgxx_cmr_mem_ctrl_s     cn85xx; */
	/* struct bdk_bgxx_cmr_mem_ctrl_s     cn88xx; */
	/* struct bdk_bgxx_cmr_mem_ctrl_s     cn88xxp1; */
} bdk_bgxx_cmr_mem_ctrl_t;

static inline uint64_t BDK_BGXX_CMR_MEM_CTRL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_MEM_CTRL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000030ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_MEM_CTRL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_MEM_CTRL(...) bdk_bgxx_cmr_mem_ctrl_t
#define bustype_BDK_BGXX_CMR_MEM_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_MEM_CTRL(p1) (p1)
#define arguments_BDK_BGXX_CMR_MEM_CTRL(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_MEM_CTRL(...) "BGXX_CMR_MEM_CTRL"


/**
 * RSL - bgx#_cmr_mem_int
 */
typedef union bdk_bgxx_cmr_mem_int {
	uint64_t u;
	struct bdk_bgxx_cmr_mem_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_26_63              : 38;
		uint64_t txb_ncsi_sbe                : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_ncsi_dbe                : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m3_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m3_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m2_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m2_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m1_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m1_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t smu_in_overfl               : 1;  /**< R/W1C/H - RX SMU INFIFO overflow. */
		uint64_t gmp_in_overfl               : 1;  /**< R/W1C/H - RX GMP INFIFO overflow. */
		uint64_t txb_skid_m0_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error. */
		uint64_t txb_skid_m0_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error. */
		uint64_t txb_fif_bk1_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 single-bit error. */
		uint64_t txb_fif_bk1_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 double-bit error. */
		uint64_t txb_fif_bk0_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 single-bit error. */
		uint64_t txb_fif_bk0_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 double-bit error. */
		uint64_t rxb_skid_sbe                : 1;  /**< R/W1C/H - RXB SKID FIFO single-bit error. */
		uint64_t rxb_skid_dbe                : 1;  /**< R/W1C/H - RXB SKID FIFO double-bit error. */
		uint64_t rxb_fif_bk1_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 single-bit error. */
		uint64_t rxb_fif_bk1_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 double-bit error. */
		uint64_t rxb_fif_bk1_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 single-bit error. */
		uint64_t rxb_fif_bk1_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 double-bit error. */
		uint64_t rxb_fif_bk0_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 single-bit error. */
		uint64_t rxb_fif_bk0_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 double-bit error. */
		uint64_t rxb_fif_bk0_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 single-bit error. */
		uint64_t rxb_fif_bk0_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 double-bit error. */
#else
		uint64_t rxb_fif_bk0_dbe0            : 1;
		uint64_t rxb_fif_bk0_sbe0            : 1;
		uint64_t rxb_fif_bk0_dbe1            : 1;
		uint64_t rxb_fif_bk0_sbe1            : 1;
		uint64_t rxb_fif_bk1_dbe0            : 1;
		uint64_t rxb_fif_bk1_sbe0            : 1;
		uint64_t rxb_fif_bk1_dbe1            : 1;
		uint64_t rxb_fif_bk1_sbe1            : 1;
		uint64_t rxb_skid_dbe                : 1;
		uint64_t rxb_skid_sbe                : 1;
		uint64_t txb_fif_bk0_dbe             : 1;
		uint64_t txb_fif_bk0_sbe             : 1;
		uint64_t txb_fif_bk1_dbe             : 1;
		uint64_t txb_fif_bk1_sbe             : 1;
		uint64_t txb_skid_m0_dbe             : 1;
		uint64_t txb_skid_m0_sbe             : 1;
		uint64_t gmp_in_overfl               : 1;
		uint64_t smu_in_overfl               : 1;
		uint64_t txb_skid_m1_dbe             : 1;
		uint64_t txb_skid_m1_sbe             : 1;
		uint64_t txb_skid_m2_dbe             : 1;
		uint64_t txb_skid_m2_sbe             : 1;
		uint64_t txb_skid_m3_dbe             : 1;
		uint64_t txb_skid_m3_sbe             : 1;
		uint64_t txb_ncsi_dbe                : 1;
		uint64_t txb_ncsi_sbe                : 1;
		uint64_t reserved_26_63              : 38;
#endif
	} s;
	/* struct bdk_bgxx_cmr_mem_int_s      cn85xx; */
	/* struct bdk_bgxx_cmr_mem_int_s      cn88xx; */
	/* struct bdk_bgxx_cmr_mem_int_s      cn88xxp1; */
} bdk_bgxx_cmr_mem_int_t;

static inline uint64_t BDK_BGXX_CMR_MEM_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_MEM_INT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000010ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_MEM_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_MEM_INT(...) bdk_bgxx_cmr_mem_int_t
#define bustype_BDK_BGXX_CMR_MEM_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_MEM_INT(p1) (p1)
#define arguments_BDK_BGXX_CMR_MEM_INT(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_MEM_INT(...) "BGXX_CMR_MEM_INT"


/**
 * RSL - bgx#_cmr_mem_int_ena_w1c
 */
typedef union bdk_bgxx_cmr_mem_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_cmr_mem_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_26_63              : 38;
		uint64_t txb_ncsi_sbe                : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_ncsi_dbe                : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m3_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m3_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m2_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m2_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m1_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m1_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t smu_in_overfl               : 1;  /**< R/W1C/H - RX SMU INFIFO overflow. */
		uint64_t gmp_in_overfl               : 1;  /**< R/W1C/H - RX GMP INFIFO overflow. */
		uint64_t txb_skid_m0_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error. */
		uint64_t txb_skid_m0_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error. */
		uint64_t txb_fif_bk1_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 single-bit error. */
		uint64_t txb_fif_bk1_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 double-bit error. */
		uint64_t txb_fif_bk0_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 single-bit error. */
		uint64_t txb_fif_bk0_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 double-bit error. */
		uint64_t rxb_skid_sbe                : 1;  /**< R/W1C/H - RXB SKID FIFO single-bit error. */
		uint64_t rxb_skid_dbe                : 1;  /**< R/W1C/H - RXB SKID FIFO double-bit error. */
		uint64_t rxb_fif_bk1_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 single-bit error. */
		uint64_t rxb_fif_bk1_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 double-bit error. */
		uint64_t rxb_fif_bk1_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 single-bit error. */
		uint64_t rxb_fif_bk1_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 double-bit error. */
		uint64_t rxb_fif_bk0_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 single-bit error. */
		uint64_t rxb_fif_bk0_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 double-bit error. */
		uint64_t rxb_fif_bk0_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 single-bit error. */
		uint64_t rxb_fif_bk0_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 double-bit error. */
#else
		uint64_t rxb_fif_bk0_dbe0            : 1;
		uint64_t rxb_fif_bk0_sbe0            : 1;
		uint64_t rxb_fif_bk0_dbe1            : 1;
		uint64_t rxb_fif_bk0_sbe1            : 1;
		uint64_t rxb_fif_bk1_dbe0            : 1;
		uint64_t rxb_fif_bk1_sbe0            : 1;
		uint64_t rxb_fif_bk1_dbe1            : 1;
		uint64_t rxb_fif_bk1_sbe1            : 1;
		uint64_t rxb_skid_dbe                : 1;
		uint64_t rxb_skid_sbe                : 1;
		uint64_t txb_fif_bk0_dbe             : 1;
		uint64_t txb_fif_bk0_sbe             : 1;
		uint64_t txb_fif_bk1_dbe             : 1;
		uint64_t txb_fif_bk1_sbe             : 1;
		uint64_t txb_skid_m0_dbe             : 1;
		uint64_t txb_skid_m0_sbe             : 1;
		uint64_t gmp_in_overfl               : 1;
		uint64_t smu_in_overfl               : 1;
		uint64_t txb_skid_m1_dbe             : 1;
		uint64_t txb_skid_m1_sbe             : 1;
		uint64_t txb_skid_m2_dbe             : 1;
		uint64_t txb_skid_m2_sbe             : 1;
		uint64_t txb_skid_m3_dbe             : 1;
		uint64_t txb_skid_m3_sbe             : 1;
		uint64_t txb_ncsi_dbe                : 1;
		uint64_t txb_ncsi_sbe                : 1;
		uint64_t reserved_26_63              : 38;
#endif
	} s;
	/* struct bdk_bgxx_cmr_mem_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_cmr_mem_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_cmr_mem_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_cmr_mem_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_CMR_MEM_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_MEM_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000020ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_MEM_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_MEM_INT_ENA_W1C(...) bdk_bgxx_cmr_mem_int_ena_w1c_t
#define bustype_BDK_BGXX_CMR_MEM_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_MEM_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_BGXX_CMR_MEM_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_MEM_INT_ENA_W1C(...) "BGXX_CMR_MEM_INT_ENA_W1C"


/**
 * RSL - bgx#_cmr_mem_int_ena_w1s
 */
typedef union bdk_bgxx_cmr_mem_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_cmr_mem_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_26_63              : 38;
		uint64_t txb_ncsi_sbe                : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_ncsi_dbe                : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m3_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m3_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m2_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m2_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m1_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m1_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t smu_in_overfl               : 1;  /**< R/W1C/H - RX SMU INFIFO overflow. */
		uint64_t gmp_in_overfl               : 1;  /**< R/W1C/H - RX GMP INFIFO overflow. */
		uint64_t txb_skid_m0_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error. */
		uint64_t txb_skid_m0_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error. */
		uint64_t txb_fif_bk1_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 single-bit error. */
		uint64_t txb_fif_bk1_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 double-bit error. */
		uint64_t txb_fif_bk0_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 single-bit error. */
		uint64_t txb_fif_bk0_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 double-bit error. */
		uint64_t rxb_skid_sbe                : 1;  /**< R/W1C/H - RXB SKID FIFO single-bit error. */
		uint64_t rxb_skid_dbe                : 1;  /**< R/W1C/H - RXB SKID FIFO double-bit error. */
		uint64_t rxb_fif_bk1_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 single-bit error. */
		uint64_t rxb_fif_bk1_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 double-bit error. */
		uint64_t rxb_fif_bk1_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 single-bit error. */
		uint64_t rxb_fif_bk1_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 double-bit error. */
		uint64_t rxb_fif_bk0_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 single-bit error. */
		uint64_t rxb_fif_bk0_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 double-bit error. */
		uint64_t rxb_fif_bk0_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 single-bit error. */
		uint64_t rxb_fif_bk0_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 double-bit error. */
#else
		uint64_t rxb_fif_bk0_dbe0            : 1;
		uint64_t rxb_fif_bk0_sbe0            : 1;
		uint64_t rxb_fif_bk0_dbe1            : 1;
		uint64_t rxb_fif_bk0_sbe1            : 1;
		uint64_t rxb_fif_bk1_dbe0            : 1;
		uint64_t rxb_fif_bk1_sbe0            : 1;
		uint64_t rxb_fif_bk1_dbe1            : 1;
		uint64_t rxb_fif_bk1_sbe1            : 1;
		uint64_t rxb_skid_dbe                : 1;
		uint64_t rxb_skid_sbe                : 1;
		uint64_t txb_fif_bk0_dbe             : 1;
		uint64_t txb_fif_bk0_sbe             : 1;
		uint64_t txb_fif_bk1_dbe             : 1;
		uint64_t txb_fif_bk1_sbe             : 1;
		uint64_t txb_skid_m0_dbe             : 1;
		uint64_t txb_skid_m0_sbe             : 1;
		uint64_t gmp_in_overfl               : 1;
		uint64_t smu_in_overfl               : 1;
		uint64_t txb_skid_m1_dbe             : 1;
		uint64_t txb_skid_m1_sbe             : 1;
		uint64_t txb_skid_m2_dbe             : 1;
		uint64_t txb_skid_m2_sbe             : 1;
		uint64_t txb_skid_m3_dbe             : 1;
		uint64_t txb_skid_m3_sbe             : 1;
		uint64_t txb_ncsi_dbe                : 1;
		uint64_t txb_ncsi_sbe                : 1;
		uint64_t reserved_26_63              : 38;
#endif
	} s;
	/* struct bdk_bgxx_cmr_mem_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_cmr_mem_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_cmr_mem_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_cmr_mem_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_CMR_MEM_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_MEM_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000028ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_MEM_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_MEM_INT_ENA_W1S(...) bdk_bgxx_cmr_mem_int_ena_w1s_t
#define bustype_BDK_BGXX_CMR_MEM_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_MEM_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_BGXX_CMR_MEM_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_MEM_INT_ENA_W1S(...) "BGXX_CMR_MEM_INT_ENA_W1S"


/**
 * RSL - bgx#_cmr_mem_int_w1s
 */
typedef union bdk_bgxx_cmr_mem_int_w1s {
	uint64_t u;
	struct bdk_bgxx_cmr_mem_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_26_63              : 38;
		uint64_t txb_ncsi_sbe                : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_ncsi_dbe                : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m3_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m3_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m2_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m2_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t txb_skid_m1_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error */
		uint64_t txb_skid_m1_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error */
		uint64_t smu_in_overfl               : 1;  /**< R/W1C/H - RX SMU INFIFO overflow. */
		uint64_t gmp_in_overfl               : 1;  /**< R/W1C/H - RX GMP INFIFO overflow. */
		uint64_t txb_skid_m0_sbe             : 1;  /**< R/W1C/H - TXB SKID FIFO single-bit error. */
		uint64_t txb_skid_m0_dbe             : 1;  /**< R/W1C/H - TXB SKID FIFO double-bit error. */
		uint64_t txb_fif_bk1_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 single-bit error. */
		uint64_t txb_fif_bk1_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank1 double-bit error. */
		uint64_t txb_fif_bk0_sbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 single-bit error. */
		uint64_t txb_fif_bk0_dbe             : 1;  /**< R/W1C/H - TXB Main FIFO Bank0 double-bit error. */
		uint64_t rxb_skid_sbe                : 1;  /**< R/W1C/H - RXB SKID FIFO single-bit error. */
		uint64_t rxb_skid_dbe                : 1;  /**< R/W1C/H - RXB SKID FIFO double-bit error. */
		uint64_t rxb_fif_bk1_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 single-bit error. */
		uint64_t rxb_fif_bk1_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf1 double-bit error. */
		uint64_t rxb_fif_bk1_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 single-bit error. */
		uint64_t rxb_fif_bk1_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank1 srf0 double-bit error. */
		uint64_t rxb_fif_bk0_sbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 single-bit error. */
		uint64_t rxb_fif_bk0_dbe1            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf1 double-bit error. */
		uint64_t rxb_fif_bk0_sbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 single-bit error. */
		uint64_t rxb_fif_bk0_dbe0            : 1;  /**< R/W1C/H - RXB main FIFO bank0 srf0 double-bit error. */
#else
		uint64_t rxb_fif_bk0_dbe0            : 1;
		uint64_t rxb_fif_bk0_sbe0            : 1;
		uint64_t rxb_fif_bk0_dbe1            : 1;
		uint64_t rxb_fif_bk0_sbe1            : 1;
		uint64_t rxb_fif_bk1_dbe0            : 1;
		uint64_t rxb_fif_bk1_sbe0            : 1;
		uint64_t rxb_fif_bk1_dbe1            : 1;
		uint64_t rxb_fif_bk1_sbe1            : 1;
		uint64_t rxb_skid_dbe                : 1;
		uint64_t rxb_skid_sbe                : 1;
		uint64_t txb_fif_bk0_dbe             : 1;
		uint64_t txb_fif_bk0_sbe             : 1;
		uint64_t txb_fif_bk1_dbe             : 1;
		uint64_t txb_fif_bk1_sbe             : 1;
		uint64_t txb_skid_m0_dbe             : 1;
		uint64_t txb_skid_m0_sbe             : 1;
		uint64_t gmp_in_overfl               : 1;
		uint64_t smu_in_overfl               : 1;
		uint64_t txb_skid_m1_dbe             : 1;
		uint64_t txb_skid_m1_sbe             : 1;
		uint64_t txb_skid_m2_dbe             : 1;
		uint64_t txb_skid_m2_sbe             : 1;
		uint64_t txb_skid_m3_dbe             : 1;
		uint64_t txb_skid_m3_sbe             : 1;
		uint64_t txb_ncsi_dbe                : 1;
		uint64_t txb_ncsi_sbe                : 1;
		uint64_t reserved_26_63              : 38;
#endif
	} s;
	/* struct bdk_bgxx_cmr_mem_int_w1s_s  cn85xx; */
	/* struct bdk_bgxx_cmr_mem_int_w1s_s  cn88xx; */
	/* struct bdk_bgxx_cmr_mem_int_w1s_s  cn88xxp1; */
} bdk_bgxx_cmr_mem_int_w1s_t;

static inline uint64_t BDK_BGXX_CMR_MEM_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_MEM_INT_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000018ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_MEM_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_MEM_INT_W1S(...) bdk_bgxx_cmr_mem_int_w1s_t
#define bustype_BDK_BGXX_CMR_MEM_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_MEM_INT_W1S(p1) (p1)
#define arguments_BDK_BGXX_CMR_MEM_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_MEM_INT_W1S(...) "BGXX_CMR_MEM_INT_W1S"


/**
 * RSL - bgx#_cmr_nxc_adr
 */
typedef union bdk_bgxx_cmr_nxc_adr {
	uint64_t u;
	struct bdk_bgxx_cmr_nxc_adr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t lmac_id                     : 4;  /**< RO/H - Logged LMAC ID associated with NXC exceptions. */
		uint64_t channel                     : 12; /**< RO/H - Logged channel for NXC exceptions. */
#else
		uint64_t channel                     : 12;
		uint64_t lmac_id                     : 4;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_cmr_nxc_adr_s      cn85xx; */
	/* struct bdk_bgxx_cmr_nxc_adr_s      cn88xx; */
	/* struct bdk_bgxx_cmr_nxc_adr_s      cn88xxp1; */
} bdk_bgxx_cmr_nxc_adr_t;

static inline uint64_t BDK_BGXX_CMR_NXC_ADR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_NXC_ADR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0001018ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_NXC_ADR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_NXC_ADR(...) bdk_bgxx_cmr_nxc_adr_t
#define bustype_BDK_BGXX_CMR_NXC_ADR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_NXC_ADR(p1) (p1)
#define arguments_BDK_BGXX_CMR_NXC_ADR(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_NXC_ADR(...) "BGXX_CMR_NXC_ADR"


/**
 * RSL - bgx#_cmr_rx_dmac#_cam
 *
 * These registers provide access to the 32 DMAC CAM entries in BGX.
 *
 */
typedef union bdk_bgxx_cmr_rx_dmacx_cam {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_dmacx_cam_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_51_63              : 13;
		uint64_t id                          : 2;  /**< R/W - Logical MAC ID that this DMAC CAM address applies to. BGX has 32 DMAC CAM entries that can
                                                                 be accessed with the BGX*_CMR_RX_ADR_CAM() CSRs. These 32 DMAC entries can be used by
                                                                 any of the four SGMII MACs or the 10G/40G MACs using these register bits.

                                                                 A typical configuration is to provide eight CAM entries per LMAC ID, which is configured
                                                                 using the following settings:
                                                                 * LMAC interface 0: BGX(0..1)_CMR_RX_ADR(0..7)_CAM[ID] = 0x0.
                                                                 * LMAC interface 1: BGX(0..1)_CMR_RX_ADR(8..15)_CAM[ID] = 0x1.
                                                                 * LMAC interface 2: BGX(0..1)_CMR_RX_ADR(16..23)_CAM[ID] = 0x2.
                                                                 * LMAC interface 3: BGX(0..1)_CMR_RX_ADR(24..31)_CAM[ID] = 0x3. */
		uint64_t en                          : 1;  /**< R/W - CAM entry enable for this DMAC address.
                                                                 1 = Include this address in the matching algorithm.
                                                                 0 = Don't include this address in the matching algorithm. */
		uint64_t adr                         : 48; /**< R/W - DMAC address in the CAM used for matching. Specified in network byte order, i.e.
                                                                 ADR[47:40] is for the first DMAC byte on the wire. The CAM matches against unicast or
                                                                 multicast DMAC addresses. All BGX()_CMR_RX_ADR()_CAM CSRs can be used in any of the LMAC
                                                                 combinations such that any BGX MAC can use any of the 32 common DMAC entries. */
#else
		uint64_t adr                         : 48;
		uint64_t en                          : 1;
		uint64_t id                          : 2;
		uint64_t reserved_51_63              : 13;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_dmacx_cam_s cn85xx; */
	/* struct bdk_bgxx_cmr_rx_dmacx_cam_s cn88xx; */
	/* struct bdk_bgxx_cmr_rx_dmacx_cam_s cn88xxp1; */
} bdk_bgxx_cmr_rx_dmacx_cam_t;

static inline uint64_t BDK_BGXX_CMR_RX_DMACX_CAM(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_DMACX_CAM(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 31)))
		return 0x000087E0E0000200ull + (param1 & 1) * 0x1000000ull + (param2 & 31) * 0x8ull;
	csr_fatal("BDK_BGXX_CMR_RX_DMACX_CAM", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_DMACX_CAM(...) bdk_bgxx_cmr_rx_dmacx_cam_t
#define bustype_BDK_BGXX_CMR_RX_DMACX_CAM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_DMACX_CAM(p1,p2) (p1)
#define arguments_BDK_BGXX_CMR_RX_DMACX_CAM(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMR_RX_DMACX_CAM(...) "BGXX_CMR_RX_DMACX_CAM"


/**
 * RSL - bgx#_cmr_rx_lmacs
 */
typedef union bdk_bgxx_cmr_rx_lmacs {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_lmacs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t lmacs                       : 3;  /**< R/W - Number of LMACS. Specifies the number of LMACs that can be enabled.
                                                                 This determines the logical RX buffer size per LMAC and the maximum
                                                                 LMAC ID that can be used:

                                                                 0x0 = Reserved.
                                                                 0x1 = 64 KB per LMAC, maximum LMAC ID is 0.
                                                                 0x2 = 32 KB per LMAC, maximum LMAC ID is 1.
                                                                 0x3 = 16 KB per LMAC, maximum LMAC ID is 2.
                                                                 0x4 = 16 KB per LMAC, maximum LMAC ID is 3.
                                                                 0x5-0x7 = Reserved.

                                                                 Note the maximum LMAC ID is determined by the smaller of
                                                                 BGX()_CMR_RX_LMACS[LMACS] and BGX()_CMR_TX_LMACS[LMACS]. The two fields
                                                                 should be set to the same value for normal operation. */
#else
		uint64_t lmacs                       : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_lmacs_s     cn85xx; */
	/* struct bdk_bgxx_cmr_rx_lmacs_s     cn88xx; */
	/* struct bdk_bgxx_cmr_rx_lmacs_s     cn88xxp1; */
} bdk_bgxx_cmr_rx_lmacs_t;

static inline uint64_t BDK_BGXX_CMR_RX_LMACS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_LMACS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000468ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_RX_LMACS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_LMACS(...) bdk_bgxx_cmr_rx_lmacs_t
#define bustype_BDK_BGXX_CMR_RX_LMACS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_LMACS(p1) (p1)
#define arguments_BDK_BGXX_CMR_RX_LMACS(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_RX_LMACS(...) "BGXX_CMR_RX_LMACS"


/**
 * RSL - bgx#_cmr_rx_ovr_bp
 *
 * BGX()_CMR_RX_OVR_BP[EN\<0\>] must be set to one and BGX()_CMR_RX_OVR_BP[BP\<0\>] must be
 * cleared to zero (to forcibly disable hardware-automatic 802.3 PAUSE packet generation) with
 * the HiGig2 Protocol when BGX()_SMU()_HG2_CONTROL[HG2TX_EN]=0. (The HiGig2 protocol is
 * indicated by BGX()_SMU()_TX_CTL[HG_EN]=1 and BGX()_SMU()_RX_UDD_SKP[LEN]=16).
 * Hardware can only auto-generate backpressure through HiGig2 messages (optionally, when
 * BGX()_SMU()_HG2_CONTROL[HG2TX_EN]=1) with the HiGig2 protocol.
 */
typedef union bdk_bgxx_cmr_rx_ovr_bp {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_ovr_bp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t en                          : 4;  /**< R/W - Per-LMAC enable backpressure override.
                                                                 0 = Don't enable.
                                                                 1 = Enable override.

                                                                 Bit\<8\> represents LMAC 0, ..., bit\<11\> represents LMAC 3. */
		uint64_t bp                          : 4;  /**< R/W - Per-LMAC backpressure status to use:
                                                                 0 = LMAC is available.
                                                                 1 = LMAC should be backpressured.

                                                                 Bit\<4\> represents LMAC 0, ..., bit\<7\> represents LMAC 3. */
		uint64_t ign_fifo_bp                 : 4;  /**< R/W - Ignore the RX FIFO BP_ON signal when computing backpressure. CMR does not backpressure the
                                                                 MAC due to the FIFO length passing BP_ON mark. */
#else
		uint64_t ign_fifo_bp                 : 4;
		uint64_t bp                          : 4;
		uint64_t en                          : 4;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_ovr_bp_s    cn85xx; */
	/* struct bdk_bgxx_cmr_rx_ovr_bp_s    cn88xx; */
	/* struct bdk_bgxx_cmr_rx_ovr_bp_s    cn88xxp1; */
} bdk_bgxx_cmr_rx_ovr_bp_t;

static inline uint64_t BDK_BGXX_CMR_RX_OVR_BP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_OVR_BP(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000470ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_RX_OVR_BP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_OVR_BP(...) bdk_bgxx_cmr_rx_ovr_bp_t
#define bustype_BDK_BGXX_CMR_RX_OVR_BP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_OVR_BP(p1) (p1)
#define arguments_BDK_BGXX_CMR_RX_OVR_BP(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_RX_OVR_BP(...) "BGXX_CMR_RX_OVR_BP"


/**
 * RSL - bgx#_cmr_rx_stat10
 *
 * This register provide a count of octets of dropped at the NCSI interface.
 *
 */
typedef union bdk_bgxx_cmr_rx_stat10 {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_stat10_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Octet count of dropped NCSI packets. CNT will wrap and is cleared if NCSI is reset with
                                                                 BGX()_CMR()_GLOBAL_CONFIG[NCSI_RESET]=1. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_stat10_s    cn85xx; */
	/* struct bdk_bgxx_cmr_rx_stat10_s    cn88xx; */
	/* struct bdk_bgxx_cmr_rx_stat10_s    cn88xxp1; */
} bdk_bgxx_cmr_rx_stat10_t;

static inline uint64_t BDK_BGXX_CMR_RX_STAT10(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_STAT10(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E00000C0ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_RX_STAT10", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_STAT10(...) bdk_bgxx_cmr_rx_stat10_t
#define bustype_BDK_BGXX_CMR_RX_STAT10(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_STAT10(p1) (p1)
#define arguments_BDK_BGXX_CMR_RX_STAT10(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_RX_STAT10(...) "BGXX_CMR_RX_STAT10"


/**
 * RSL - bgx#_cmr_rx_stat9
 *
 * This registers provides a count of packets dropped at the NCSI interface.
 * The count of dropped NCSI packets is not accounted for in any other stats
 * registers.
 */
typedef union bdk_bgxx_cmr_rx_stat9 {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_stat9_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t cnt                         : 48; /**< R/W/H - Count of dropped packets. CNT will wrap and is cleared if NCSI is reset with
                                                                 BGX()_CMR()_GLOBAL_CONFIG[NCSI_RESET]=1. */
#else
		uint64_t cnt                         : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_stat9_s     cn85xx; */
	/* struct bdk_bgxx_cmr_rx_stat9_s     cn88xx; */
	/* struct bdk_bgxx_cmr_rx_stat9_s     cn88xxp1; */
} bdk_bgxx_cmr_rx_stat9_t;

static inline uint64_t BDK_BGXX_CMR_RX_STAT9(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_STAT9(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E00000B8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_RX_STAT9", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_STAT9(...) bdk_bgxx_cmr_rx_stat9_t
#define bustype_BDK_BGXX_CMR_RX_STAT9(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_STAT9(p1) (p1)
#define arguments_BDK_BGXX_CMR_RX_STAT9(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_RX_STAT9(...) "BGXX_CMR_RX_STAT9"


/**
 * RSL - bgx#_cmr_rx_steering#
 *
 * These registers provide VLAN ID and DMAC ADR for identifying NCSI traffic. BGX has 2 VLAN
 * ID/DMAC address entries that can be accessed with the BGX()_CMR_RX_NCSI_CAM(0..1) CSRs.
 * Traffic
 * matching either of these cam entries, together the ethernet type (see
 * BGX_CMR_RX_NCSI_VLAN_ETYPE)
 * will be steered to the the RX NCSI interface of BGX.
 * These 2 entries can be used by any of the four SGMII MACs or the 10G/40G MACs using these
 * register
 * bits. See BGX()_CMR_GLOBAL_CONFIG for the LMAC_ID associated with NCSI traffic.
 */
typedef union bdk_bgxx_cmr_rx_steeringx {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_steeringx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t dest                        : 2;  /**< R/W - Destination for traffic that meets all criteria of the matching algorithm:
                                                                 0x0 = Steer this traffic exclusively to NCSI.
                                                                 0x1 = Steer this traffic exclusively to X2P.
                                                                 0x2 = Steer this traffic to BOTH X2P and NCSI.
                                                                 0x3 = Steer this traffic to the bit bucket (drop). */
		uint64_t mcst_en                     : 1;  /**< R/W - Enable for identifying MCST traffic
                                                                 1 = Include this MCST in the matching algorithm for traffic that is steered to the DEST
                                                                 interface.
                                                                 0 = Don't include MCST in the matching algorithm.
                                                                 traffic. */
		uint64_t dmac_en                     : 1;  /**< R/W - CAM entry enable for this DMAC address.
                                                                 1 = Include this address in the matching algorithm for traffic that is steered to the DEST
                                                                 interface.
                                                                 0 = Don't include this address in the matching algorithm. */
		uint64_t dmac                        : 48; /**< R/W - DMAC address used for matching and identifying traffic that will be steered to the DEST
                                                                 interface.
                                                                 Can be used alone to identify a DMAC ADR within the incoming traffic NCSI block or
                                                                 together with VLAN ID,
                                                                 BGX()_CMR_RX_NCSI_VETYPE[VLAN_ETYPE] to identify traffic to send to the NCSI block for
                                                                 example.
                                                                 This entry is independent but should be set in a coordinated manner with any of the
                                                                 BGX()_CMR_RX_DMAC()_CAM entries used for filtering traffic.  Broadcast can be specified
                                                                 with value 0xFFFF_FFFFFF. */
#else
		uint64_t dmac                        : 48;
		uint64_t dmac_en                     : 1;
		uint64_t mcst_en                     : 1;
		uint64_t dest                        : 2;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_steeringx_s cn85xx; */
	/* struct bdk_bgxx_cmr_rx_steeringx_s cn88xx; */
	/* struct bdk_bgxx_cmr_rx_steeringx_s cn88xxp1; */
} bdk_bgxx_cmr_rx_steeringx_t;

static inline uint64_t BDK_BGXX_CMR_RX_STEERINGX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_STEERINGX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 7)))
		return 0x000087E0E0000300ull + (param1 & 1) * 0x1000000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_BGXX_CMR_RX_STEERINGX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_STEERINGX(...) bdk_bgxx_cmr_rx_steeringx_t
#define bustype_BDK_BGXX_CMR_RX_STEERINGX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_STEERINGX(p1,p2) (p1)
#define arguments_BDK_BGXX_CMR_RX_STEERINGX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMR_RX_STEERINGX(...) "BGXX_CMR_RX_STEERINGX"


/**
 * RSL - bgx#_cmr_rx_steering_default
 *
 * Traffic not matching any of steering entries (BGX()_CMR_RX_STEERING(),
 * and BGX()_CMR_RX_STEERING_VETYPE)
 * will be sent to the DEFAULT_DEST interface of BGX_CMR for LMAC ID matching NCSI_LMAC_ID.
 */
typedef union bdk_bgxx_cmr_rx_steering_default {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_steering_default_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t dest                        : 2;  /**< R/W - If traffic does not meet all criteria of the matching algorithm:
                                                                 0x0 = Steer traffic exclusively to NCSI.
                                                                 0x1 = Steer traffic exclusively to X2P.
                                                                 0x2 = Steer traffic to BOTH X2P and NCSI.
                                                                 0x3 = Steer traffic to the bit bucket (drop). */
#else
		uint64_t dest                        : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_steering_default_s cn85xx; */
	/* struct bdk_bgxx_cmr_rx_steering_default_s cn88xx; */
	/* struct bdk_bgxx_cmr_rx_steering_default_s cn88xxp1; */
} bdk_bgxx_cmr_rx_steering_default_t;

static inline uint64_t BDK_BGXX_CMR_RX_STEERING_DEFAULT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_STEERING_DEFAULT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0000448ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_RX_STEERING_DEFAULT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_STEERING_DEFAULT(...) bdk_bgxx_cmr_rx_steering_default_t
#define bustype_BDK_BGXX_CMR_RX_STEERING_DEFAULT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_STEERING_DEFAULT(p1) (p1)
#define arguments_BDK_BGXX_CMR_RX_STEERING_DEFAULT(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_RX_STEERING_DEFAULT(...) "BGXX_CMR_RX_STEERING_DEFAULT"


/**
 * RSL - bgx#_cmr_rx_steering_vetype#
 *
 * This register specifies the ETYPES and VLAN IDs necessary to identify VLAN tagged traffic.
 * Together with BGX()_CMR_RX_STEERING(), BGX has 8 VLAN TAG/VLAN ID/DMAC address entries or
 * rules that can be assigned
 * for the purpose of steering.
 * 802.1Q and 802.1ad specify several different ETYPEs used to identify VLAN tagged and VLAN
 * double tagged packets. BGX CMR will always match against the tag that immediately following
 * the SMAC address of the L2 header. Traffic with ETYPE matching VLAN_ETYPE0 or VLAN_ETYPE1
 * are sent to the NCSI (subject to additional matches involving BGX()_CMR_RX_NCSI_CAM).
 * Matching combinations specified in the NCSI Ver1.0 spec are typically as follows:
 * 1. VLAN_Tag + VLAN_Match + DMAC_Match
 * 2. VLAN_Tag + DMAC_Match
 * 3. DMAC_Match only
 *
 * These combinations can be achieved using VLAN_TAG_EN contained in this register,
 * along with BGX()_CMR_RX_NCSI_CAM[VLAN_EN] and BGX()_CMR_RX_NCSI_CAM[DMAC_EN].
 */
typedef union bdk_bgxx_cmr_rx_steering_vetypex {
	uint64_t u;
	struct bdk_bgxx_cmr_rx_steering_vetypex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t vlan_en                     : 1;  /**< R/W - Enable for this VLAN ID
                                                                 1 = Include this VLAN_ID in the matching algorithm for traffic that is steered to the DEST
                                                                 interface.
                                                                 0 = Don't include this address in the matching algorithm. */
		uint64_t vlan_id                     : 12; /**< R/W - VLAN ID useful for identifying NCSI traffic. Can be used alone to identify a VLAN ID
                                                                 within the incoming traffic to send to the DEST interface or together with VLAN_ETYPE,
                                                                 VLAN_TAG_EN and entries in BGX()_CMR_RX_STEERING(). */
		uint64_t vlan_tag_en                 : 1;  /**< R/W - Enable for requiring VLAN Tagging presence.  Applies to both ETYPEs shown below.
                                                                 1 = VLAG Tag required to be present for the matching algorithm to identify NCSI traffic.
                                                                 0 = VLAN Tag is not requried to be present for matching algorithm identifying NCSI
                                                                 traffic. */
		uint64_t vlan_etype                  : 16; /**< R/W - VLAN Ethertype for identifying traffic that is steered to the DEST interface. */
#else
		uint64_t vlan_etype                  : 16;
		uint64_t vlan_tag_en                 : 1;
		uint64_t vlan_id                     : 12;
		uint64_t vlan_en                     : 1;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_bgxx_cmr_rx_steering_vetypex_s cn85xx; */
	/* struct bdk_bgxx_cmr_rx_steering_vetypex_s cn88xx; */
	/* struct bdk_bgxx_cmr_rx_steering_vetypex_s cn88xxp1; */
} bdk_bgxx_cmr_rx_steering_vetypex_t;

static inline uint64_t BDK_BGXX_CMR_RX_STEERING_VETYPEX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_RX_STEERING_VETYPEX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 7)))
		return 0x000087E0E0000400ull + (param1 & 1) * 0x1000000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_BGXX_CMR_RX_STEERING_VETYPEX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_RX_STEERING_VETYPEX(...) bdk_bgxx_cmr_rx_steering_vetypex_t
#define bustype_BDK_BGXX_CMR_RX_STEERING_VETYPEX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_RX_STEERING_VETYPEX(p1,p2) (p1)
#define arguments_BDK_BGXX_CMR_RX_STEERING_VETYPEX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_CMR_RX_STEERING_VETYPEX(...) "BGXX_CMR_RX_STEERING_VETYPEX"


/**
 * RSL - bgx#_cmr_tx_lmacs
 *
 * This register sets the number of LMACs allowed on the TX interface. The value is important for
 * defining the partitioning of the transmit FIFO.
 */
typedef union bdk_bgxx_cmr_tx_lmacs {
	uint64_t u;
	struct bdk_bgxx_cmr_tx_lmacs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t lmacs                       : 3;  /**< R/W - Number of LMACS: Specifies the number of LMACs that can be enabled.
                                                                 This determines the logical TX buffer size per LMAC and the maximum
                                                                 LMAC ID that can be used:

                                                                 0x0 = Reserved.
                                                                 0x1 = 48 KB per LMAC, maximum LMAC ID is 0.
                                                                 0x2 = 24 KB per LMAC, maximum LMAC ID is 1.
                                                                 0x3 = 12 KB per LMAC, maximum LMAC ID is 2.
                                                                 0x4 = 12 KB per LMAC, maximum LMAC ID is 3.
                                                                 0x5-0x7 = Reserved.

                                                                 The maximum LMAC ID is determined by the smaller of BGX()_CMR_RX_LMACS[LMACS]
                                                                 and BGX()_CMR_TX_LMACS[LMACS]. The two fields should be set to the same value for
                                                                 normal operation.' */
#else
		uint64_t lmacs                       : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_cmr_tx_lmacs_s     cn85xx; */
	/* struct bdk_bgxx_cmr_tx_lmacs_s     cn88xx; */
	/* struct bdk_bgxx_cmr_tx_lmacs_s     cn88xxp1; */
} bdk_bgxx_cmr_tx_lmacs_t;

static inline uint64_t BDK_BGXX_CMR_TX_LMACS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_CMR_TX_LMACS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0001000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_CMR_TX_LMACS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_CMR_TX_LMACS(...) bdk_bgxx_cmr_tx_lmacs_t
#define bustype_BDK_BGXX_CMR_TX_LMACS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_CMR_TX_LMACS(p1) (p1)
#define arguments_BDK_BGXX_CMR_TX_LMACS(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_CMR_TX_LMACS(...) "BGXX_CMR_TX_LMACS"


/**
 * RSL - bgx#_gmp_gmi_prt#_cfg
 *
 * This register controls the configuration of the LMAC.
 *
 */
typedef union bdk_bgxx_gmp_gmi_prtx_cfg {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_prtx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t tx_idle                     : 1;  /**< RO/H - TX machine is idle. */
		uint64_t rx_idle                     : 1;  /**< RO/H - RX machine is idle. */
		uint64_t reserved_9_11               : 3;
		uint64_t speed_msb                   : 1;  /**< R/W - Link speed MSB (SGMII/1000Base-X only). See [SPEED]. */
		uint64_t reserved_4_7                : 4;
		uint64_t slottime                    : 1;  /**< R/W - Slot time for half-duplex operation
                                                                 (SGMII/1000Base-X only):
                                                                 0 = 512 bit times (10/100 Mb/s operation)
                                                                 1 = 4096 bit times (1000 Mb/s operation) */
		uint64_t duplex                      : 1;  /**< R/W - Duplex mode
                                                                 (SGMII/1000Base-X only):
                                                                 0 = half-duplex (collisions/extensions/bursts):
                                                                 1 = full-duplex. */
		uint64_t speed                       : 1;  /**< R/W - Link Speed LSB (SGMII/1000Base-X only):
                                                                 _ [SPEED_MSB:SPEED] = 0x0: 100 Mb/s operation.
                                                                 _ [SPEED_MSB:SPEED] = 0x1: 1000 Mb/s operation.
                                                                 _ [SPEED_MSB:SPEED] = 0x2: 10 Mb/s operation.
                                                                 _ [SPEED_MSB:SPEED] = 0x3: Reserved. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t speed                       : 1;
		uint64_t duplex                      : 1;
		uint64_t slottime                    : 1;
		uint64_t reserved_4_7                : 4;
		uint64_t speed_msb                   : 1;
		uint64_t reserved_9_11               : 3;
		uint64_t rx_idle                     : 1;
		uint64_t tx_idle                     : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_prtx_cfg_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_prtx_cfg_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_prtx_cfg_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_prtx_cfg_t;

static inline uint64_t BDK_BGXX_GMP_GMI_PRTX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_PRTX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038020ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_PRTX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_PRTX_CFG(...) bdk_bgxx_gmp_gmi_prtx_cfg_t
#define bustype_BDK_BGXX_GMP_GMI_PRTX_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_PRTX_CFG(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_PRTX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_PRTX_CFG(...) "BGXX_GMP_GMI_PRTX_CFG"


/**
 * RSL - bgx#_gmp_gmi_rx#_decision
 *
 * This register specifies the byte count used to determine when to accept or to filter a packet.
 * As each byte in a packet is received by GMI, the L2 byte count is compared against the
 * BGX()_GMP_GMI_RX()_DECISION[CNT]. In normal operation, the L2 header begins after the
 * PREAMBLE + SFD (BGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] = 1) and any optional UDD skip
 * data (BGX()_GMP_GMI_RX()_UDD_SKP[LEN]).
 *
 * INTERNAL: Notes:
 * As each byte in a packet is received by GMI, the L2 byte count is compared
 * against the BGX()_GMP_GMI_RX()_DECISION[CNT].  The L2 byte count is the number of bytes
 * from the beginning of the L2 header (DMAC).  In normal operation, the L2
 * header begins after the PREAMBLE+SFD (BGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK]=1) and any
 * optional UDD skip data (BGX()_GMP_GMI_RX()_UDD_SKP[LEN]).
 * When BGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] is clear, PREAMBLE+SFD are prepended to the
 * packet and would require UDD skip length to account for them.
 * Port Mode
 * - Full Duplex
 *     L2 Size \<  BGX_RX_DECISION - Accept packet. No filtering is applied
 *     L2 Size \>= BGX_RX_DECISION - Apply filter. Accept packet based on PAUSE packet filter
 * - Half Duplex
 *     L2 Size \<  BGX_RX_DECISION - Drop packet. Packet is unconditionally dropped.
 *     L2 Size \>= BGX_RX_DECISION - Accept packet.
 *
 * where L2_size = MAX(0, total_packet_size - BGX()_GMP_GMI_RX()_UDD_SKP[LEN] -
 *                        ((BGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK]==1)*8))
 *
 * BGX()_GMP_GMI_RX()_DECISION = The byte count to decide when to accept or filter a packet
 */
typedef union bdk_bgxx_gmp_gmi_rxx_decision {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_decision_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t cnt                         : 5;  /**< R/W - The byte count used to decide when to accept or filter a packet. Refer to GMI Decisions. */
#else
		uint64_t cnt                         : 5;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_decision_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_decision_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_decision_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_decision_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_DECISION(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_DECISION(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038040ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_DECISION", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_DECISION(...) bdk_bgxx_gmp_gmi_rxx_decision_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_DECISION(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_DECISION(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_DECISION(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_DECISION(...) "BGXX_GMP_GMI_RXX_DECISION"


/**
 * RSL - bgx#_gmp_gmi_rx#_frm_chk
 */
typedef union bdk_bgxx_gmp_gmi_rxx_frm_chk {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_frm_chk_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t skperr                      : 1;  /**< R/W - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W - Frame was received with data-reception error. */
		uint64_t reserved_5_6                : 2;
		uint64_t fcserr                      : 1;  /**< R/W - Frame was received with FCS/CRC error. */
		uint64_t jabber                      : 1;  /**< R/W - Frame was received with length \> sys_length. */
		uint64_t reserved_2_2                : 1;
		uint64_t carext                      : 1;  /**< R/W - Carrier extend error. SGMII/1000Base-X only. */
		uint64_t minerr                      : 1;  /**< R/W - PAUSE frame was received with length \< minFrameSize. */
#else
		uint64_t minerr                      : 1;
		uint64_t carext                      : 1;
		uint64_t reserved_2_2                : 1;
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t reserved_5_6                : 2;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_frm_chk_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_frm_chk_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_frm_chk_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_frm_chk_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_FRM_CHK(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_FRM_CHK(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038030ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_FRM_CHK", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_FRM_CHK(...) bdk_bgxx_gmp_gmi_rxx_frm_chk_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_FRM_CHK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_FRM_CHK(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_FRM_CHK(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_FRM_CHK(...) "BGXX_GMP_GMI_RXX_FRM_CHK"


/**
 * RSL - bgx#_gmp_gmi_rx#_frm_ctl
 *
 * This register controls the handling of the frames.
 * The CTL_BCK/CTL_DRP bits control how the hardware handles incoming PAUSE packets. The most
 * common modes of operation:
 * _ CTL_BCK = 1, CTL_DRP = 1: hardware handles everything.
 * _ CTL_BCK = 0, CTL_DRP = 0: software sees all PAUSE frames.
 * _ CTL_BCK = 0, CTL_DRP = 1: all PAUSE frames are completely ignored.
 *
 * These control bits should be set to CTL_BCK = 0,CTL_DRP = 0 in half-duplex mode. Since PAUSE
 * packets only apply to full duplex operation, any PAUSE packet would constitute an exception
 * which should be handled by the processing cores. PAUSE packets should not be forwarded.
 *
 * INTERNAL: Notes:
 * PRE_STRP
 * When PRE_CHK is set (indicating that the PREAMBLE will be sent), PRE_STRP
 * determines if the PREAMBLE+SFD bytes are thrown away or sent to the Octane
 * core as part of the packet.
 * In either mode, the PREAMBLE+SFD bytes are not counted toward the packet
 * size when checking against the MIN and MAX bounds.  Furthermore, the bytes
 * are skipped when locating the start of the L2 header for DMAC and Control
 * frame recognition.
 */
typedef union bdk_bgxx_gmp_gmi_rxx_frm_ctl {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_frm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t ptp_mode                    : 1;  /**< R/W - Timestamp mode. When PTP_MODE is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the BGX()_GMP_GMI_RX()_JABBER,
                                                                 BGX()_GMP_GMI_RX()_DECISION, BGX()_GMP_GMI_RX()_UDD_SKP, and
                                                                 BGX()_CMR()_RX_STAT0..BGX()_CMR()_RX_STAT8
                                                                 do not require any adjustment as they operate on the received
                                                                 packet size. When the packet reaches NIC, its size reflects the additional bytes. */
		uint64_t reserved_11_11              : 1;
		uint64_t null_dis                    : 1;  /**< R/W - When set, do not modify the MOD bits on NULL ticks due to partial packets. */
		uint64_t pre_align                   : 1;  /**< R/W - When set, PREAMBLE parser aligns the SFD byte regardless of the number of previous
                                                                 PREAMBLE nibbles. In this mode, PRE_STRP should be set to account for the variable nature
                                                                 of the PREAMBLE. PRE_CHK must be set to enable this and all PREAMBLE features.
                                                                 SGMII at 10/100Mbs only. */
		uint64_t reserved_7_8                : 2;
		uint64_t pre_free                    : 1;  /**< RO/H - When set, PREAMBLE checking is less strict. GMI will begin the frame at the first SFD.
                                                                 PRE_CHK must be set to enable this and all PREAMBLE features. SGMII/1000Base-X only. */
		uint64_t ctl_smac                    : 1;  /**< R/W - Control PAUSE frames can match station SMAC. */
		uint64_t ctl_mcst                    : 1;  /**< R/W - Control PAUSE frames can match globally assigned multicast address. */
		uint64_t ctl_bck                     : 1;  /**< R/W - Forward PAUSE information to TX block. */
		uint64_t ctl_drp                     : 1;  /**< R/W - Drop control-PAUSE frames. */
		uint64_t pre_strp                    : 1;  /**< R/W - Strip off the preamble (when present).
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If PTP_MODE=1 and PRE_CHK=1, PRE_STRP must be 1.

                                                                 When PRE_CHK is set (indicating that the PREAMBLE will be sent), PRE_STRP determines if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and Control frame recognition. */
		uint64_t pre_chk                     : 1;  /**< R/W - Check the preamble for correctness. This port is configured to send a valid 802.3 PREAMBLE
                                                                 to begin every frame. GMI checks that a valid PREAMBLE is received (based on PRE_FREE).
                                                                 When a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The BGX()_SMU()_RX_INT[PCTERR] interrupt is also raised.

                                                                 When BGX()_SMU()_TX_CTL[HG_EN] is set, PRE_CHK must be 0. If PTP_MODE = 1 and
                                                                 PRE_CHK = 1, PRE_STRP must be 1. */
#else
		uint64_t pre_chk                     : 1;
		uint64_t pre_strp                    : 1;
		uint64_t ctl_drp                     : 1;
		uint64_t ctl_bck                     : 1;
		uint64_t ctl_mcst                    : 1;
		uint64_t ctl_smac                    : 1;
		uint64_t pre_free                    : 1;
		uint64_t reserved_7_8                : 2;
		uint64_t pre_align                   : 1;
		uint64_t null_dis                    : 1;
		uint64_t reserved_11_11              : 1;
		uint64_t ptp_mode                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_frm_ctl_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_frm_ctl_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_frm_ctl_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_frm_ctl_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_FRM_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_FRM_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038028ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_FRM_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_FRM_CTL(...) bdk_bgxx_gmp_gmi_rxx_frm_ctl_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_FRM_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_FRM_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_FRM_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_FRM_CTL(...) "BGXX_GMP_GMI_RXX_FRM_CTL"


/**
 * RSL - bgx#_gmp_gmi_rx#_ifg
 *
 * This register specifies the minimum number of interframe-gap (IFG) cycles between packets.
 *
 */
typedef union bdk_bgxx_gmp_gmi_rxx_ifg {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_ifg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t ifg                         : 4;  /**< R/W - Min IFG (in IFG * 8 bits) between packets used to determine IFGERR. Normally IFG is 96
                                                                 bits.

                                                                 Note that in some operating modes, IFG cycles can be inserted or removed in order to
                                                                 achieve clock rate adaptation. For these reasons, the default value is slightly
                                                                 conservative and does not check up to the full 96 bits of IFG.
                                                                 (SGMII/1000Base-X only) */
#else
		uint64_t ifg                         : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_ifg_s  cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_ifg_s  cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_ifg_s  cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_ifg_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_IFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_IFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038058ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_IFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_IFG(...) bdk_bgxx_gmp_gmi_rxx_ifg_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_IFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_IFG(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_IFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_IFG(...) "BGXX_GMP_GMI_RXX_IFG"


/**
 * RSL - bgx#_gmp_gmi_rx#_int
 *
 * "These registers allow interrupts to be sent to the control processor.
 * * Exception conditions \<10:0\> can also set the rcv/opcode in the received packet's work-queue
 * entry. BGX()_GMP_GMI_RX()_FRM_CHK provides a bit mask for configuring which conditions
 * set the error.
 * In half duplex operation, the expectation is that collisions will appear as either MINERR or
 * CAREXT errors.
 *
 * INTERNAL: Notes:
 * (2) exception conditions 10:0 can also set the rcv/opcode in the received
 * packet's workQ entry.  The BGX()_GMP_GMI_RX()_FRM_CHK register provides a bit mask
 * for configuring which conditions set the error.
 *
 * (3) in half duplex operation, the expectation is that collisions will appear
 * as either MINERR o r CAREXT errors.
 *
 * (4) JABBER An RX Jabber error indicates that a packet was received which
 * is longer than the maximum allowed packet as defined by the
 * system.  GMI will truncate the packet at the JABBER count.
 * Failure to do so could lead to system instabilty.
 *
 * (5) NIBERR This error is illegal at 1000Mbs speeds
 * (BGX()_GMP_GMI_RX()_PRT_CFG[SPEED]==0) and will never assert.
 *
 * (6) MAXERR for untagged frames, the total frame DA+SA+TL+DATA+PAD+FCS \>
 * BGX()_GMP_GMI_RX()_FRM_MAX.  For tagged frames, DA+SA+VLAN+TL+DATA+PAD+FCS
 * > BGX()_GMP_GMI_RX()_FRM_MAX + 4*VLAN_VAL + 4*VLAN_STACKED.
 *
 * (7) MINERR total frame DA+SA+TL+DATA+PAD+FCS \< 64
 *
 * (8) ALNERR Indicates that the packet received was not an integer number of
 * bytes.  If FCS checking is enabled, ALNERR will only assert if
 * the FCS is bad.  If FCS checking is disabled, ALNERR will
 * assert in all non-integer frame cases.
 *
 * (9) Collisions Collisions can only occur in half-duplex mode.  A collision
 * is assumed by the receiver when the slottime
 * (BGX()_GMP_GMI_PRT_CFG[SLOTTIME]) is not satisfied.  In 10/100 mode,
 * this will result in a frame \< SLOTTIME.  In 1000 mode, it
 * could result either in frame \< SLOTTIME or a carrier extend
 * error with the SLOTTIME.  These conditions are visible by...
 * . transfer ended before slottime COLDET
 * . carrier extend error           CAREXT
 *
 * (A) LENERR Length errors occur when the received packet does not match the
 * length field.  LENERR is only checked for packets between 64
 * and 1500 bytes.  For untagged frames, the length must exact
 * match.  For tagged frames the length or length+4 must match.
 *
 * (B) PCTERR checks that the frame begins with a valid PREAMBLE sequence.
 * Does not check the number of PREAMBLE cycles.
 *
 * (C) OVRERR *DON'T PUT IN HRM*
 * OVRERR is an architectural assertion check internal to GMI to
 * make sure no assumption was violated.  In a correctly operating
 * system, this interrupt can never fire.
 * GMI has an internal arbiter which selects which of 4 ports to
 * buffer in the main RX FIFO.  If we normally buffer 8 bytes,
 * then each port will typically push a tick every 8 cycles if
 * the packet interface is going as fast as possible.  If there
 * are four ports, they push every two cycles.  So that's the
 * assumption.  That the inbound module will always be able to
 * consume the tick before another is produced.  If that doesn't
 * happen that's when OVRERR will assert."
 */
typedef union bdk_bgxx_gmp_gmi_rxx_int {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. SGMII/1000Base-X only. */
		uint64_t coldet                      : 1;  /**< R/W1C/H - Collision detection. Collisions can only occur in half-duplex mode. A collision is assumed
                                                                 by the receiver when the slottime (BGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not
                                                                 satisfied. In 10/100 mode, this will result in a frame \< SLOTTIME. In 1000 mode, it could
                                                                 result either in frame \< SLOTTIME or a carrier extend error with the SLOTTIME. These
                                                                 conditions are visible by 1) transfer ended before slottime - COLDET or 2) carrier extend
                                                                 error - CAREXT. */
		uint64_t falerr                      : 1;  /**< R/W1C/H - False-carrier error, or carrier-extend error after slottime is satisfied. SGMII/1000Base-X only. */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcode. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence.
                                                                 Does not check the number of PREAMBLE cycles. */
		uint64_t ovrerr                      : 1;  /**< R/W1C/H - Internal data aggregation overflow. This interrupt should never assert. SGMII/1000Base-X only. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Data-reception error. Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error: frame was received with length \> sys_length.
                                                                 An RX Jabber error indicates that a packet was received which is longer than the maximum
                                                                 allowed packet as defined by the system. GMI truncates the packet at the JABBER count.
                                                                 Failure to do so could lead to system instability. */
		uint64_t carext                      : 1;  /**< R/W1C/H - Carrier-extend error. (SGMII/1000Base-X only) */
		uint64_t minerr                      : 1;  /**< R/W1C/H - PAUSE frame was received with length \< minFrameSize. Frame length checks are typically
                                                                 handled in NIC, but PAUSE frames are normally discarded before being inspected by NIC.
                                                                 Total frame DA+SA+TL+DATA+PAD+FCS \< 64. */
#else
		uint64_t minerr                      : 1;
		uint64_t carext                      : 1;
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t ovrerr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t falerr                      : 1;
		uint64_t coldet                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_int_s  cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_s  cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_s  cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_int_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_INT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_INT(...) bdk_bgxx_gmp_gmi_rxx_int_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_INT(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_INT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_INT(...) "BGXX_GMP_GMI_RXX_INT"


/**
 * RSL - bgx#_gmp_gmi_rx#_int_ena_w1c
 */
typedef union bdk_bgxx_gmp_gmi_rxx_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. SGMII/1000Base-X only. */
		uint64_t coldet                      : 1;  /**< R/W1C/H - Collision detection. Collisions can only occur in half-duplex mode. A collision is assumed
                                                                 by the receiver when the slottime (BGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not
                                                                 satisfied. In 10/100 mode, this will result in a frame \< SLOTTIME. In 1000 mode, it could
                                                                 result either in frame \< SLOTTIME or a carrier extend error with the SLOTTIME. These
                                                                 conditions are visible by 1) transfer ended before slottime - COLDET or 2) carrier extend
                                                                 error - CAREXT. */
		uint64_t falerr                      : 1;  /**< R/W1C/H - False-carrier error, or carrier-extend error after slottime is satisfied. SGMII/1000Base-X only. */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcode. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence.
                                                                 Does not check the number of PREAMBLE cycles. */
		uint64_t ovrerr                      : 1;  /**< R/W1C/H - Internal data aggregation overflow. This interrupt should never assert. SGMII/1000Base-X only. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Data-reception error. Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error: frame was received with length \> sys_length.
                                                                 An RX Jabber error indicates that a packet was received which is longer than the maximum
                                                                 allowed packet as defined by the system. GMI truncates the packet at the JABBER count.
                                                                 Failure to do so could lead to system instability. */
		uint64_t carext                      : 1;  /**< R/W1C/H - Carrier-extend error. (SGMII/1000Base-X only) */
		uint64_t minerr                      : 1;  /**< R/W1C/H - PAUSE frame was received with length \< minFrameSize. Frame length checks are typically
                                                                 handled in NIC, but PAUSE frames are normally discarded before being inspected by NIC.
                                                                 Total frame DA+SA+TL+DATA+PAD+FCS \< 64. */
#else
		uint64_t minerr                      : 1;
		uint64_t carext                      : 1;
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t ovrerr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t falerr                      : 1;
		uint64_t coldet                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038010ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(...) bdk_bgxx_gmp_gmi_rxx_int_ena_w1c_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1C(...) "BGXX_GMP_GMI_RXX_INT_ENA_W1C"


/**
 * RSL - bgx#_gmp_gmi_rx#_int_ena_w1s
 */
typedef union bdk_bgxx_gmp_gmi_rxx_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. SGMII/1000Base-X only. */
		uint64_t coldet                      : 1;  /**< R/W1C/H - Collision detection. Collisions can only occur in half-duplex mode. A collision is assumed
                                                                 by the receiver when the slottime (BGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not
                                                                 satisfied. In 10/100 mode, this will result in a frame \< SLOTTIME. In 1000 mode, it could
                                                                 result either in frame \< SLOTTIME or a carrier extend error with the SLOTTIME. These
                                                                 conditions are visible by 1) transfer ended before slottime - COLDET or 2) carrier extend
                                                                 error - CAREXT. */
		uint64_t falerr                      : 1;  /**< R/W1C/H - False-carrier error, or carrier-extend error after slottime is satisfied. SGMII/1000Base-X only. */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcode. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence.
                                                                 Does not check the number of PREAMBLE cycles. */
		uint64_t ovrerr                      : 1;  /**< R/W1C/H - Internal data aggregation overflow. This interrupt should never assert. SGMII/1000Base-X only. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Data-reception error. Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error: frame was received with length \> sys_length.
                                                                 An RX Jabber error indicates that a packet was received which is longer than the maximum
                                                                 allowed packet as defined by the system. GMI truncates the packet at the JABBER count.
                                                                 Failure to do so could lead to system instability. */
		uint64_t carext                      : 1;  /**< R/W1C/H - Carrier-extend error. (SGMII/1000Base-X only) */
		uint64_t minerr                      : 1;  /**< R/W1C/H - PAUSE frame was received with length \< minFrameSize. Frame length checks are typically
                                                                 handled in NIC, but PAUSE frames are normally discarded before being inspected by NIC.
                                                                 Total frame DA+SA+TL+DATA+PAD+FCS \< 64. */
#else
		uint64_t minerr                      : 1;
		uint64_t carext                      : 1;
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t ovrerr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t falerr                      : 1;
		uint64_t coldet                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038018ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(...) bdk_bgxx_gmp_gmi_rxx_int_ena_w1s_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_INT_ENA_W1S(...) "BGXX_GMP_GMI_RXX_INT_ENA_W1S"


/**
 * RSL - bgx#_gmp_gmi_rx#_int_w1s
 */
typedef union bdk_bgxx_gmp_gmi_rxx_int_w1s {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t ifgerr                      : 1;  /**< R/W1C/H - Interframe gap violation. Does not necessarily indicate a failure. SGMII/1000Base-X only. */
		uint64_t coldet                      : 1;  /**< R/W1C/H - Collision detection. Collisions can only occur in half-duplex mode. A collision is assumed
                                                                 by the receiver when the slottime (BGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not
                                                                 satisfied. In 10/100 mode, this will result in a frame \< SLOTTIME. In 1000 mode, it could
                                                                 result either in frame \< SLOTTIME or a carrier extend error with the SLOTTIME. These
                                                                 conditions are visible by 1) transfer ended before slottime - COLDET or 2) carrier extend
                                                                 error - CAREXT. */
		uint64_t falerr                      : 1;  /**< R/W1C/H - False-carrier error, or carrier-extend error after slottime is satisfied. SGMII/1000Base-X only. */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcode. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence.
                                                                 Does not check the number of PREAMBLE cycles. */
		uint64_t ovrerr                      : 1;  /**< R/W1C/H - Internal data aggregation overflow. This interrupt should never assert. SGMII/1000Base-X only. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Data-reception error. Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - FCS/CRC error. Frame was received with FCS/CRC error. */
		uint64_t jabber                      : 1;  /**< R/W1C/H - System-length error: frame was received with length \> sys_length.
                                                                 An RX Jabber error indicates that a packet was received which is longer than the maximum
                                                                 allowed packet as defined by the system. GMI truncates the packet at the JABBER count.
                                                                 Failure to do so could lead to system instability. */
		uint64_t carext                      : 1;  /**< R/W1C/H - Carrier-extend error. (SGMII/1000Base-X only) */
		uint64_t minerr                      : 1;  /**< R/W1C/H - PAUSE frame was received with length \< minFrameSize. Frame length checks are typically
                                                                 handled in NIC, but PAUSE frames are normally discarded before being inspected by NIC.
                                                                 Total frame DA+SA+TL+DATA+PAD+FCS \< 64. */
#else
		uint64_t minerr                      : 1;
		uint64_t carext                      : 1;
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t ovrerr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t falerr                      : 1;
		uint64_t coldet                      : 1;
		uint64_t ifgerr                      : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_int_w1s_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_w1s_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_int_w1s_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_int_w1s_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_INT_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038008ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_INT_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_INT_W1S(...) bdk_bgxx_gmp_gmi_rxx_int_w1s_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_INT_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_INT_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_INT_W1S(...) "BGXX_GMP_GMI_RXX_INT_W1S"


/**
 * RSL - bgx#_gmp_gmi_rx#_jabber
 *
 * This register specifies the maximum size for packets, beyond which the GMI truncates.
 *
 */
typedef union bdk_bgxx_gmp_gmi_rxx_jabber {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_jabber_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cnt                         : 16; /**< R/W - Byte count for jabber check. Failing packets set the JABBER interrupt and are optionally
                                                                 sent with opcode = JABBER. GMI truncates the packet to CNT bytes.
                                                                 CNT must be 8-byte aligned such that CNT\<2:0\> = 000. */
#else
		uint64_t cnt                         : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_jabber_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_jabber_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_jabber_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_jabber_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_JABBER(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_JABBER(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038038ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_JABBER", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_JABBER(...) bdk_bgxx_gmp_gmi_rxx_jabber_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_JABBER(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_JABBER(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_JABBER(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_JABBER(...) "BGXX_GMP_GMI_RXX_JABBER"


/**
 * RSL - bgx#_gmp_gmi_rx#_udd_skp
 *
 * This register specifies the amount of user-defined data (UDD) added before the start of the
 * L2C data.
 *
 * INTERNAL: Notes:
 * (1) The skip bytes are part of the packet and will be sent down the NCB
 * packet interface and will be handled by NIC.
 *
 * (2) The system can determine if the UDD bytes are included in the FCS check
 * by using the FCSSEL field - if the FCS check is enabled.
 *
 * (3) Assume that the preamble/sfd is always at the start of the frame - even
 * before UDD bytes.  In most cases, there will be no preamble in these
 * cases since it will be packet interface in direct communication to
 * another packet interface (MAC to MAC) without a PHY involved.
 *
 * (4) We can still do address filtering and control packet filtering is the
 * user desires.
 *
 * (5) UDD_SKP must be 0 in half-duplex operation unless
 * BGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] is clear.  If BGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] is
 * clear,
 * then UDD_SKP will normally be 8.
 *
 * (6) In all cases, the UDD bytes will be sent down the packet interface as
 * part of the packet.  The UDD bytes are never stripped from the actual
 * packet.
 */
typedef union bdk_bgxx_gmp_gmi_rxx_udd_skp {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_rxx_udd_skp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t fcssel                      : 1;  /**< R/W - Include the skip bytes in the FCS calculation.
                                                                 0 = All skip bytes are included in FCS.
                                                                 1 = The skip bytes are not included in FCS.

                                                                 When BGX()_GMP_GMI_TX()_CTL[HG_EN] is set, this field must be 0.
                                                                 The skip bytes are part of the packet and are sent down the NCB packet interface and are
                                                                 handled by NIC. The system can determine if the UDD bytes are included in the FCS check by
                                                                 using the FCSSEL field, if the FCS check is enabled. */
		uint64_t reserved_7_7                : 1;
		uint64_t len                         : 7;  /**< R/W - Amount of user-defined data before the start of the L2C data, in bytes.
                                                                 Setting to 0 means L2C comes first; maximum value is 64.
                                                                 LEN must be 0x0 in half-duplex operation.

                                                                 If LEN != 0, then BGX()_GMP_GMI_RX()_FRM_CHK[MINERR] will be disabled and
                                                                 BGX()_GMP_GMI_RX()_INT[MINERR] will be zero. */
#else
		uint64_t len                         : 7;
		uint64_t reserved_7_7                : 1;
		uint64_t fcssel                      : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_rxx_udd_skp_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_udd_skp_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_rxx_udd_skp_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_rxx_udd_skp_t;

static inline uint64_t BDK_BGXX_GMP_GMI_RXX_UDD_SKP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_RXX_UDD_SKP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038048ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_RXX_UDD_SKP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_RXX_UDD_SKP(...) bdk_bgxx_gmp_gmi_rxx_udd_skp_t
#define bustype_BDK_BGXX_GMP_GMI_RXX_UDD_SKP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_RXX_UDD_SKP(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_RXX_UDD_SKP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_RXX_UDD_SKP(...) "BGXX_GMP_GMI_RXX_UDD_SKP"


/**
 * RSL - bgx#_gmp_gmi_smac#
 */
typedef union bdk_bgxx_gmp_gmi_smacx {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_smacx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t smac                        : 48; /**< R/W - The SMAC field is used for generating and accepting control PAUSE packets. */
#else
		uint64_t smac                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_smacx_s    cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_smacx_s    cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_smacx_s    cn88xxp1; */
} bdk_bgxx_gmp_gmi_smacx_t;

static inline uint64_t BDK_BGXX_GMP_GMI_SMACX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_SMACX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038230ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_SMACX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_SMACX(...) bdk_bgxx_gmp_gmi_smacx_t
#define bustype_BDK_BGXX_GMP_GMI_SMACX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_SMACX(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_SMACX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_SMACX(...) "BGXX_GMP_GMI_SMACX"


/**
 * RSL - bgx#_gmp_gmi_tx#_append
 */
typedef union bdk_bgxx_gmp_gmi_txx_append {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_append_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t force_fcs                   : 1;  /**< R/W - Append the Ethernet FCS on each PAUSE packet. */
		uint64_t fcs                         : 1;  /**< R/W - Append the Ethernet FCS on each packet. */
		uint64_t pad                         : 1;  /**< R/W - Append PAD bytes such that minimum-sized packet is transmitted. */
		uint64_t preamble                    : 1;  /**< R/W - Prepend the Ethernet preamble on each transfer. */
#else
		uint64_t preamble                    : 1;
		uint64_t pad                         : 1;
		uint64_t fcs                         : 1;
		uint64_t force_fcs                   : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_append_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_append_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_append_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_append_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_APPEND(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_APPEND(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038218ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_APPEND", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_APPEND(...) bdk_bgxx_gmp_gmi_txx_append_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_APPEND(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_APPEND(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_APPEND(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_APPEND(...) "BGXX_GMP_GMI_TXX_APPEND"


/**
 * RSL - bgx#_gmp_gmi_tx#_burst
 */
typedef union bdk_bgxx_gmp_gmi_txx_burst {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_burst_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t burst                       : 16; /**< R/W - Burst (refer to 802.3 to set correctly). Only valid for 1000Mb/s half-duplex operation as
                                                                 follows:
                                                                 half duplex/1000Mb/s: 0x2000
                                                                 all other modes: 0x0
                                                                 SGMII/1000Base-X only. */
#else
		uint64_t burst                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_burst_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_burst_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_burst_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_burst_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_BURST(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_BURST(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038228ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_BURST", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_BURST(...) bdk_bgxx_gmp_gmi_txx_burst_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_BURST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_BURST(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_BURST(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_BURST(...) "BGXX_GMP_GMI_TXX_BURST"


/**
 * RSL - bgx#_gmp_gmi_tx#_ctl
 */
typedef union bdk_bgxx_gmp_gmi_txx_ctl {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t xsdef_en                    : 1;  /**< R/W - Enables the excessive-deferral check for statistics and interrupts. SGMII/1000Base-X half-
                                                                 duplex only. */
		uint64_t xscol_en                    : 1;  /**< R/W - Enables the excessive-collision check for statistics and interrupts. SGMII/1000Base-X
                                                                 half-duplex only. */
#else
		uint64_t xscol_en                    : 1;
		uint64_t xsdef_en                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_ctl_s  cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_ctl_s  cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_ctl_s  cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_ctl_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038270ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_CTL(...) bdk_bgxx_gmp_gmi_txx_ctl_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_CTL(...) "BGXX_GMP_GMI_TXX_CTL"


/**
 * RSL - bgx#_gmp_gmi_tx#_int
 */
typedef union bdk_bgxx_gmp_gmi_txx_int {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t ptp_lost                    : 1;  /**< R/W1C/H - A packet with a PTP request was not able to be sent due to XSCOL. */
		uint64_t late_col                    : 1;  /**< R/W1C/H - TX late collision. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xsdef                       : 1;  /**< R/W1C/H - TX excessive deferral. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xscol                       : 1;  /**< R/W1C/H - TX excessive collisions. (SGMII/1000BASE-X half-duplex only) */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xscol                       : 1;
		uint64_t xsdef                       : 1;
		uint64_t late_col                    : 1;
		uint64_t ptp_lost                    : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_int_s  cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_s  cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_s  cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_int_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038500ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_INT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_INT(...) bdk_bgxx_gmp_gmi_txx_int_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_INT(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_INT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_INT(...) "BGXX_GMP_GMI_TXX_INT"


/**
 * RSL - bgx#_gmp_gmi_tx#_int_ena_w1c
 */
typedef union bdk_bgxx_gmp_gmi_txx_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t ptp_lost                    : 1;  /**< R/W1C/H - A packet with a PTP request was not able to be sent due to XSCOL. */
		uint64_t late_col                    : 1;  /**< R/W1C/H - TX late collision. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xsdef                       : 1;  /**< R/W1C/H - TX excessive deferral. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xscol                       : 1;  /**< R/W1C/H - TX excessive collisions. (SGMII/1000BASE-X half-duplex only) */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xscol                       : 1;
		uint64_t xsdef                       : 1;
		uint64_t late_col                    : 1;
		uint64_t ptp_lost                    : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038510ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(...) bdk_bgxx_gmp_gmi_txx_int_ena_w1c_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1C(...) "BGXX_GMP_GMI_TXX_INT_ENA_W1C"


/**
 * RSL - bgx#_gmp_gmi_tx#_int_ena_w1s
 */
typedef union bdk_bgxx_gmp_gmi_txx_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t ptp_lost                    : 1;  /**< R/W1C/H - A packet with a PTP request was not able to be sent due to XSCOL. */
		uint64_t late_col                    : 1;  /**< R/W1C/H - TX late collision. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xsdef                       : 1;  /**< R/W1C/H - TX excessive deferral. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xscol                       : 1;  /**< R/W1C/H - TX excessive collisions. (SGMII/1000BASE-X half-duplex only) */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xscol                       : 1;
		uint64_t xsdef                       : 1;
		uint64_t late_col                    : 1;
		uint64_t ptp_lost                    : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038518ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(...) bdk_bgxx_gmp_gmi_txx_int_ena_w1s_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_INT_ENA_W1S(...) "BGXX_GMP_GMI_TXX_INT_ENA_W1S"


/**
 * RSL - bgx#_gmp_gmi_tx#_int_w1s
 */
typedef union bdk_bgxx_gmp_gmi_txx_int_w1s {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t ptp_lost                    : 1;  /**< R/W1C/H - A packet with a PTP request was not able to be sent due to XSCOL. */
		uint64_t late_col                    : 1;  /**< R/W1C/H - TX late collision. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xsdef                       : 1;  /**< R/W1C/H - TX excessive deferral. (SGMII/1000BASE-X half-duplex only) */
		uint64_t xscol                       : 1;  /**< R/W1C/H - TX excessive collisions. (SGMII/1000BASE-X half-duplex only) */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xscol                       : 1;
		uint64_t xsdef                       : 1;
		uint64_t late_col                    : 1;
		uint64_t ptp_lost                    : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_int_w1s_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_w1s_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_int_w1s_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_int_w1s_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_INT_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038508ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_INT_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_INT_W1S(...) bdk_bgxx_gmp_gmi_txx_int_w1s_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_INT_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_INT_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_INT_W1S(...) "BGXX_GMP_GMI_TXX_INT_W1S"


/**
 * RSL - bgx#_gmp_gmi_tx#_min_pkt
 */
typedef union bdk_bgxx_gmp_gmi_txx_min_pkt {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_min_pkt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t min_size                    : 8;  /**< R/W - Minimum frame size in bytes before the FCS is applied.
                                                                 Padding is only appended when BGX()_GMP_GMI_TX()_APPEND[PAD] for the corresponding
                                                                 LMAC is set.

                                                                 In SGMII mode, packets are padded to MIN_SIZE+1. The reset value pads to 60 bytes. */
#else
		uint64_t min_size                    : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_min_pkt_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_min_pkt_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_min_pkt_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_min_pkt_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_MIN_PKT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_MIN_PKT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038240ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_MIN_PKT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_MIN_PKT(...) bdk_bgxx_gmp_gmi_txx_min_pkt_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_MIN_PKT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_MIN_PKT(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_MIN_PKT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_MIN_PKT(...) "BGXX_GMP_GMI_TXX_MIN_PKT"


/**
 * RSL - bgx#_gmp_gmi_tx#_pause_pkt_interval
 *
 * This register specifies how often PAUSE packets are sent.
 *
 * INTERNAL: Notes:
 * Choosing proper values of BGX()_GMP_GMI_TX_PAUSE_PKT_TIME[PTIME] and
 * BGX()_GMP_GMI_TX_PAUSE_PKT_INTERVAL[INTERVAL] can be challenging to the system
 * designer.  It is suggested that TIME be much greater than INTERVAL and
 * BGX()_GMP_GMI_TX_PAUSE_ZERO[SEND] be set.  This allows a periodic refresh of the PAUSE
 * count and then when the backpressure condition is lifted, a PAUSE packet
 * with TIME==0 will be sent indicating that Octane is ready for additional
 * data.
 *
 * If the system chooses to not set BGX()_GMP_GMI_TX_PAUSE_ZERO[SEND], then it is
 * suggested that TIME and INTERVAL are programmed such that they satisify the
 * following rule:
 *
 * _ INTERVAL \<= TIME - (largest_pkt_size + IFG + pause_pkt_size)
 *
 * where largest_pkt_size is that largest packet that the system can send
 * (normally 1518B), IFG is the interframe gap and pause_pkt_size is the size
 * of the PAUSE packet (normally 64B).
 */
typedef union bdk_bgxx_gmp_gmi_txx_pause_pkt_interval {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_pause_pkt_interval_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t interval                    : 16; /**< R/W - Arbitrate for a 802.3 PAUSE packet or CBFC PAUSE packet every (INTERVAL * 512) bit-times.
                                                                 Normally, 0 \< INTERVAL \< BGX()_GMP_GMI_TX()_PAUSE_PKT_TIME[PTIME].

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
#else
		uint64_t interval                    : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_pause_pkt_interval_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_pkt_interval_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_pkt_interval_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_pause_pkt_interval_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038248ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(...) bdk_bgxx_gmp_gmi_txx_pause_pkt_interval_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(...) "BGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL"


/**
 * RSL - bgx#_gmp_gmi_tx#_pause_pkt_time
 */
typedef union bdk_bgxx_gmp_gmi_txx_pause_pkt_time {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_pause_pkt_time_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t ptime                       : 16; /**< R/W - Provides the pause_time field placed in outbound 802.3 PAUSE packets or CBFC PAUSE packets
                                                                 in 512 bit-times. Normally, P_TIME \>
                                                                 BGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL[INTERVAL]. For programming information see
                                                                 BGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL. */
#else
		uint64_t ptime                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_pause_pkt_time_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_pkt_time_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_pkt_time_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_pause_pkt_time_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038238ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(...) bdk_bgxx_gmp_gmi_txx_pause_pkt_time_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(...) "BGXX_GMP_GMI_TXX_PAUSE_PKT_TIME"


/**
 * RSL - bgx#_gmp_gmi_tx#_pause_togo
 */
typedef union bdk_bgxx_gmp_gmi_txx_pause_togo {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_pause_togo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t ptime                       : 16; /**< RO/H - Amount of time remaining to backpressure, from the standard 802.3 PAUSE timer. */
#else
		uint64_t ptime                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_pause_togo_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_togo_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_togo_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_pause_togo_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038258ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(...) bdk_bgxx_gmp_gmi_txx_pause_togo_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_PAUSE_TOGO(...) "BGXX_GMP_GMI_TXX_PAUSE_TOGO"


/**
 * RSL - bgx#_gmp_gmi_tx#_pause_zero
 */
typedef union bdk_bgxx_gmp_gmi_txx_pause_zero {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_pause_zero_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t send                        : 1;  /**< R/W - Send PAUSE-zero enable.When this bit is set, and the backpressure condition is clear, it
                                                                 allows sending a PAUSE packet with pause_time of 0 to enable the channel. */
#else
		uint64_t send                        : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_pause_zero_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_zero_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_pause_zero_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_pause_zero_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038260ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(...) bdk_bgxx_gmp_gmi_txx_pause_zero_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_PAUSE_ZERO(...) "BGXX_GMP_GMI_TXX_PAUSE_ZERO"


/**
 * RSL - bgx#_gmp_gmi_tx#_sgmii_ctl
 */
typedef union bdk_bgxx_gmp_gmi_txx_sgmii_ctl {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_sgmii_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t align                       : 1;  /**< R/W - Align the transmission to even cycles: (SGMII/1000BASE-X half-duplex only)
                                                                 Recommended value is: ALIGN = !BGX()_GMP_GMI_TX()_APPEND[PREAMBLE].
                                                                 (See Transmit Conversion to Code groups, Transmit Conversion to Code Groups for a complete
                                                                 discussion.)

                                                                 _ 0 = Data can be sent on any cycle. In this mode, the interface functions at maximum
                                                                 bandwidth. It is possible for the TX PCS machine to drop the first byte of the TX frame.
                                                                 When BGX()_GMP_GMI_TX()_APPEND[PREAMBLE] is set, the first byte is a preamble
                                                                 byte, which can be dropped to compensate for an extended IPG.

                                                                 _ 1 = Data is only sent on even cycles. In this mode, there can be bandwidth implications
                                                                 when sending odd-byte packets as the IPG can extend an extra cycle. There will be no loss
                                                                 of data. */
#else
		uint64_t align                       : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_sgmii_ctl_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_sgmii_ctl_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_sgmii_ctl_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_sgmii_ctl_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038300ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_SGMII_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(...) bdk_bgxx_gmp_gmi_txx_sgmii_ctl_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(...) "BGXX_GMP_GMI_TXX_SGMII_CTL"


/**
 * RSL - bgx#_gmp_gmi_tx#_slot
 */
typedef union bdk_bgxx_gmp_gmi_txx_slot {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_slot_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t slot                        : 10; /**< R/W - Slottime (refer to Std 802.3 to set correctly):
                                                                 10/100 Mbs: Set SLOT to 0x40.
                                                                 1000 Mbs: Set SLOT to 0x200.

                                                                 SGMII/1000Base-X only. */
#else
		uint64_t slot                        : 10;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_slot_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_slot_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_slot_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_slot_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_SLOT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_SLOT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038220ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_SLOT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_SLOT(...) bdk_bgxx_gmp_gmi_txx_slot_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_SLOT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_SLOT(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_SLOT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_SLOT(...) "BGXX_GMP_GMI_TXX_SLOT"


/**
 * RSL - bgx#_gmp_gmi_tx#_soft_pause
 */
typedef union bdk_bgxx_gmp_gmi_txx_soft_pause {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_soft_pause_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t ptime                       : 16; /**< R/W - Back off the TX bus for (PTIME * 512) bit-times. */
#else
		uint64_t ptime                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_soft_pause_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_soft_pause_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_soft_pause_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_soft_pause_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038250ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(...) bdk_bgxx_gmp_gmi_txx_soft_pause_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_SOFT_PAUSE(...) "BGXX_GMP_GMI_TXX_SOFT_PAUSE"


/**
 * RSL - bgx#_gmp_gmi_tx#_thresh
 */
typedef union bdk_bgxx_gmp_gmi_txx_thresh {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_txx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t cnt                         : 11; /**< R/W - Number of 128-bit words to accumulate in the TX FIFO before sending on the packet
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0.

                                                                 10G/40G Mode, CNT = 0x100. In all modes, this register cannot exceed the TX FIFO depth as
                                                                 follows:
                                                                 _ BGX()_CMR_TX_LMACS = 0,1:  CNT maximum = 0x7FF.
                                                                 _ BGX()_CMR_TX_LMACS = 2:    CNT maximum = 0x3FF.
                                                                 _ BGX()_CMR_TX_LMACS = 3,4:  CNT maximum = 0x1FF. */
#else
		uint64_t cnt                         : 11;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_txx_thresh_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_thresh_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_txx_thresh_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_txx_thresh_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TXX_THRESH(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TXX_THRESH(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0038210ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TXX_THRESH", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TXX_THRESH(...) bdk_bgxx_gmp_gmi_txx_thresh_t
#define bustype_BDK_BGXX_GMP_GMI_TXX_THRESH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TXX_THRESH(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TXX_THRESH(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_GMI_TXX_THRESH(...) "BGXX_GMP_GMI_TXX_THRESH"


/**
 * RSL - bgx#_gmp_gmi_tx_col_attempt
 */
typedef union bdk_bgxx_gmp_gmi_tx_col_attempt {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_tx_col_attempt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t limit                       : 5;  /**< R/W - Number of collision attempts allowed. (SGMII/1000BASE-X half-duplex only.) */
#else
		uint64_t limit                       : 5;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_tx_col_attempt_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_col_attempt_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_col_attempt_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_tx_col_attempt_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0039010ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(...) bdk_bgxx_gmp_gmi_tx_col_attempt_t
#define bustype_BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(p1) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_GMP_GMI_TX_COL_ATTEMPT(...) "BGXX_GMP_GMI_TX_COL_ATTEMPT"


/**
 * RSL - bgx#_gmp_gmi_tx_ifg
 *
 * Consider the following when programming IFG1 and IFG2:
 * * For 10/100/1000 Mb/s half-duplex systems that require IEEE 802.3 compatibility, IFG1 must be
 * in the range of 1-8, IFG2 must be in the range of 4-12, and the IFG1 + IFG2 sum must be 12.
 * * For 10/100/1000 Mb/s full-duplex systems that require IEEE 802.3 compatibility, IFG1 must be
 * in the range of 1-11, IFG2 must be in the range of 1-11, and the IFG1 + IFG2 sum must be 12.
 * For all other systems, IFG1 and IFG2 can be any value in the range of 1-15, allowing for a
 * total possible IFG sum of 2-30.
 */
typedef union bdk_bgxx_gmp_gmi_tx_ifg {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_tx_ifg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t ifg2                        : 4;  /**< R/W - Remainder of interFrameGap timing, equal to interFrameGap - IFG1 (in IFG2 * 8 bits). If
                                                                 CRS is detected during IFG2, the interFrameSpacing timer is not reset and a frame is
                                                                 transmitted once the timer expires. */
		uint64_t ifg1                        : 4;  /**< R/W - First portion of interFrameGap timing, in the range of 0 to 2/3 (in IFG2 * 8 bits). If CRS
                                                                 is detected during IFG1, the interFrameSpacing timer is reset and a frame is not
                                                                 transmitted. */
#else
		uint64_t ifg1                        : 4;
		uint64_t ifg2                        : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_tx_ifg_s   cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_ifg_s   cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_ifg_s   cn88xxp1; */
} bdk_bgxx_gmp_gmi_tx_ifg_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TX_IFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TX_IFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0039000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TX_IFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TX_IFG(...) bdk_bgxx_gmp_gmi_tx_ifg_t
#define bustype_BDK_BGXX_GMP_GMI_TX_IFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TX_IFG(p1) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TX_IFG(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_GMP_GMI_TX_IFG(...) "BGXX_GMP_GMI_TX_IFG"


/**
 * RSL - bgx#_gmp_gmi_tx_jam
 *
 * This register provides the pattern used in JAM bytes.
 *
 */
typedef union bdk_bgxx_gmp_gmi_tx_jam {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_tx_jam_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t jam                         : 8;  /**< R/W - JAM pattern. (SGMII/1000BASE-X half-duplex only.) */
#else
		uint64_t jam                         : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_tx_jam_s   cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_jam_s   cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_jam_s   cn88xxp1; */
} bdk_bgxx_gmp_gmi_tx_jam_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TX_JAM(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TX_JAM(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0039008ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TX_JAM", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TX_JAM(...) bdk_bgxx_gmp_gmi_tx_jam_t
#define bustype_BDK_BGXX_GMP_GMI_TX_JAM(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TX_JAM(p1) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TX_JAM(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_GMP_GMI_TX_JAM(...) "BGXX_GMP_GMI_TX_JAM"


/**
 * RSL - bgx#_gmp_gmi_tx_lfsr
 *
 * This register shows the contents of the linear feedback shift register (LFSR), which is used
 * to implement truncated binary exponential backoff.
 */
typedef union bdk_bgxx_gmp_gmi_tx_lfsr {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_tx_lfsr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t lfsr                        : 16; /**< R/W/H - Contains the current state of the LFSR, which is used to feed random numbers to compute
                                                                 truncated binary exponential backoff. (SGMII/1000Base-X half-duplex only.) */
#else
		uint64_t lfsr                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_tx_lfsr_s  cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_lfsr_s  cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_lfsr_s  cn88xxp1; */
} bdk_bgxx_gmp_gmi_tx_lfsr_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TX_LFSR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TX_LFSR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0039028ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TX_LFSR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TX_LFSR(...) bdk_bgxx_gmp_gmi_tx_lfsr_t
#define bustype_BDK_BGXX_GMP_GMI_TX_LFSR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TX_LFSR(p1) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TX_LFSR(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_GMP_GMI_TX_LFSR(...) "BGXX_GMP_GMI_TX_LFSR"


/**
 * RSL - bgx#_gmp_gmi_tx_pause_pkt_dmac
 */
typedef union bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t dmac                        : 48; /**< R/W - The DMAC field, which is placed is outbound PAUSE packets. */
#else
		uint64_t dmac                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0039018ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(...) bdk_bgxx_gmp_gmi_tx_pause_pkt_dmac_t
#define bustype_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(p1) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(...) "BGXX_GMP_GMI_TX_PAUSE_PKT_DMAC"


/**
 * RSL - bgx#_gmp_gmi_tx_pause_pkt_type
 *
 * This register provides the PTYPE field that is placed in outbound PAUSE packets.
 *
 */
typedef union bdk_bgxx_gmp_gmi_tx_pause_pkt_type {
	uint64_t u;
	struct bdk_bgxx_gmp_gmi_tx_pause_pkt_type_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t ptype                       : 16; /**< R/W - The PTYPE field placed in outbound PAUSE packets. */
#else
		uint64_t ptype                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_gmi_tx_pause_pkt_type_s cn85xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_pause_pkt_type_s cn88xx; */
	/* struct bdk_bgxx_gmp_gmi_tx_pause_pkt_type_s cn88xxp1; */
} bdk_bgxx_gmp_gmi_tx_pause_pkt_type_t;

static inline uint64_t BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0039020ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(...) bdk_bgxx_gmp_gmi_tx_pause_pkt_type_t
#define bustype_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(p1) (p1)
#define arguments_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(...) "BGXX_GMP_GMI_TX_PAUSE_PKT_TYPE"


/**
 * RSL - bgx#_gmp_pcs_an#_adv
 */
typedef union bdk_bgxx_gmp_pcs_anx_adv {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_anx_adv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t np                          : 1;  /**< RO/H - Next page capable. This feature is not supported; this field is always 0. */
		uint64_t reserved_14_14              : 1;
		uint64_t rem_flt                     : 2;  /**< R/W/H - Remote fault.
                                                                 0x0 = Link OK, XMIT = DATA.
                                                                 0x1 = Link failure (loss of sync, XMIT !=DATA).
                                                                 0x2 = Local device offline.
                                                                 0x3 = Autonegotiation error; failure to complete autonegotiation. AN error is set if
                                                                 resolution function precludes operation with link partner. */
		uint64_t reserved_9_11               : 3;
		uint64_t pause                       : 2;  /**< R/W - PAUSE frame flow capability across link, exchanged during autonegotiation as follows:
                                                                 0x0 = No PAUSE.
                                                                 0x1 = Symmetric PAUSE.
                                                                 0x2 = Asymmetric PAUSE.
                                                                 0x3 = Both symmetric and asymmetric PAUSE to local device. */
		uint64_t hfd                         : 1;  /**< R/W - Half-duplex. When set, local device is half-duplex capable. */
		uint64_t fd                          : 1;  /**< R/W - Full-duplex. When set, local device is full-duplex capable. */
		uint64_t reserved_0_4                : 5;
#else
		uint64_t reserved_0_4                : 5;
		uint64_t fd                          : 1;
		uint64_t hfd                         : 1;
		uint64_t pause                       : 2;
		uint64_t reserved_9_11               : 3;
		uint64_t rem_flt                     : 2;
		uint64_t reserved_14_14              : 1;
		uint64_t np                          : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_anx_adv_s  cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_adv_s  cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_adv_s  cn88xxp1; */
} bdk_bgxx_gmp_pcs_anx_adv_t;

static inline uint64_t BDK_BGXX_GMP_PCS_ANX_ADV(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_ANX_ADV(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030010ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_ANX_ADV", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_ANX_ADV(...) bdk_bgxx_gmp_pcs_anx_adv_t
#define bustype_BDK_BGXX_GMP_PCS_ANX_ADV(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_ANX_ADV(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_ANX_ADV(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_ANX_ADV(...) "BGXX_GMP_PCS_ANX_ADV"


/**
 * RSL - bgx#_gmp_pcs_an#_ext_st
 */
typedef union bdk_bgxx_gmp_pcs_anx_ext_st {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_anx_ext_st_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t thou_xfd                    : 1;  /**< RO/H - When set, PHY is 1000 BASE-X full duplex capable. */
		uint64_t thou_xhd                    : 1;  /**< RO/H - When set, PHY is 1000 BASE-X half duplex capable. */
		uint64_t thou_tfd                    : 1;  /**< RO/H - When set, PHY is 1000 BASE-T full duplex capable. */
		uint64_t thou_thd                    : 1;  /**< RO/H - When set, PHY is 1000 BASE-T half duplex capable. */
		uint64_t reserved_0_11               : 12;
#else
		uint64_t reserved_0_11               : 12;
		uint64_t thou_thd                    : 1;
		uint64_t thou_tfd                    : 1;
		uint64_t thou_xhd                    : 1;
		uint64_t thou_xfd                    : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_anx_ext_st_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_ext_st_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_ext_st_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_anx_ext_st_t;

static inline uint64_t BDK_BGXX_GMP_PCS_ANX_EXT_ST(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_ANX_EXT_ST(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030028ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_ANX_EXT_ST", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_ANX_EXT_ST(...) bdk_bgxx_gmp_pcs_anx_ext_st_t
#define bustype_BDK_BGXX_GMP_PCS_ANX_EXT_ST(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_ANX_EXT_ST(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_ANX_EXT_ST(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_ANX_EXT_ST(...) "BGXX_GMP_PCS_ANX_EXT_ST"


/**
 * RSL - bgx#_gmp_pcs_an#_lp_abil
 *
 * This is the autonegotiation Link partner ability register 5 as per IEEE 802.3, Clause 37.
 *
 */
typedef union bdk_bgxx_gmp_pcs_anx_lp_abil {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_anx_lp_abil_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t np                          : 1;  /**< RO/H - 0 = Link partner not next page capable.
                                                                 1 = Link partner next page capable. */
		uint64_t ack                         : 1;  /**< RO/H - When set, indicates acknowledgement received. */
		uint64_t rem_flt                     : 2;  /**< RO/H - Link partner's link status as follows:
                                                                 0x0 = Link OK.
                                                                 0x1 = Offline.
                                                                 0x2 = Link failure.
                                                                 0x3 = Autonegotiation error. */
		uint64_t reserved_9_11               : 3;
		uint64_t pause                       : 2;  /**< RO/H - Link partner PAUSE setting as follows:
                                                                 0x0 = No PAUSE.
                                                                 0x1 = Symmetric PAUSE.
                                                                 0x2 = Asymmetric PAUSE.
                                                                 0x3 = Both symmetric and asymmetric PAUSE to local device. */
		uint64_t hfd                         : 1;  /**< RO/H - Half-duplex. When set, link partner is half-duplex capable. */
		uint64_t fd                          : 1;  /**< RO/H - Full-duplex. When set, link partner is full-duplex capable. */
		uint64_t reserved_0_4                : 5;
#else
		uint64_t reserved_0_4                : 5;
		uint64_t fd                          : 1;
		uint64_t hfd                         : 1;
		uint64_t pause                       : 2;
		uint64_t reserved_9_11               : 3;
		uint64_t rem_flt                     : 2;
		uint64_t ack                         : 1;
		uint64_t np                          : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_anx_lp_abil_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_lp_abil_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_lp_abil_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_anx_lp_abil_t;

static inline uint64_t BDK_BGXX_GMP_PCS_ANX_LP_ABIL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_ANX_LP_ABIL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030018ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_ANX_LP_ABIL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_ANX_LP_ABIL(...) bdk_bgxx_gmp_pcs_anx_lp_abil_t
#define bustype_BDK_BGXX_GMP_PCS_ANX_LP_ABIL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_ANX_LP_ABIL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_ANX_LP_ABIL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_ANX_LP_ABIL(...) "BGXX_GMP_PCS_ANX_LP_ABIL"


/**
 * RSL - bgx#_gmp_pcs_an#_results
 *
 * This register is not valid when BGX()_GMP_PCS_MISC()_CTL[AN_OVRD] is set to 1. If
 * BGX()_GMP_PCS_MISC()_CTL[AN_OVRD] is set to 0 and
 * BGX()_GMP_PCS_AN()_RESULTS[AN_CPT] is set to 1, this register is valid.
 */
typedef union bdk_bgxx_gmp_pcs_anx_results {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_anx_results_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t pause                       : 2;  /**< RO/H - PAUSE selection ('don't care' for SGMII) as follows:
                                                                 0x0 = Disable PAUSE, TX and RX.
                                                                 0x1 = Enable PAUSE frames, RX only.
                                                                 0x2 = Enable PAUSE frames, TX only.
                                                                 0x3 = Enable PAUSE frames, TX and RX. */
		uint64_t spd                         : 2;  /**< RO/H - Link speed selection as follows:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
		uint64_t an_cpt                      : 1;  /**< RO/H - Autonegotiation completed.
                                                                 1 = Autonegotiation completed.
                                                                 0 = Autonegotiation not completed or failed. */
		uint64_t dup                         : 1;  /**< RO/H - Duplex mode. 1 = full duplex, 0 = half duplex. */
		uint64_t link_ok                     : 1;  /**< RO/H - Link status: 1 = link up (OK), 1 = link down. */
#else
		uint64_t link_ok                     : 1;
		uint64_t dup                         : 1;
		uint64_t an_cpt                      : 1;
		uint64_t spd                         : 2;
		uint64_t pause                       : 2;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_anx_results_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_results_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_anx_results_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_anx_results_t;

static inline uint64_t BDK_BGXX_GMP_PCS_ANX_RESULTS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_ANX_RESULTS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030020ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_ANX_RESULTS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_ANX_RESULTS(...) bdk_bgxx_gmp_pcs_anx_results_t
#define bustype_BDK_BGXX_GMP_PCS_ANX_RESULTS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_ANX_RESULTS(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_ANX_RESULTS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_ANX_RESULTS(...) "BGXX_GMP_PCS_ANX_RESULTS"


/**
 * RSL - bgx#_gmp_pcs_int#
 */
typedef union bdk_bgxx_gmp_pcs_intx {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_intx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Code group sync failure debug help. DBG_SYNC interrupt fires when code group
                                                                 synchronization state machine makes a transition from SYNC_ACQUIRED_1 state to
                                                                 SYNC_ACQUIRED_2 state. (See IEEE 802.3-2005, figure 37-9). It indicates that a bad code
                                                                 group was received after code group synchronization was achieved. This interrupt should be
                                                                 disabled during normal link operation. Use it as a debug help feature only. */
		uint64_t dup                         : 1;  /**< R/W1C/H - Set whenever duplex mode changes on the link. */
		uint64_t sync_bad                    : 1;  /**< R/W1C/H - Set by hardware whenever RX sync state machine reaches a bad state. Should never be set
                                                                 during normal operation. */
		uint64_t an_bad                      : 1;  /**< R/W1C/H - Set by hardware whenever autonegotiation state machine reaches a bad state. Should never
                                                                 be set during normal operation. */
		uint64_t rxlock                      : 1;  /**< R/W1C/H - Set by hardware whenever code group sync or bit lock failure occurs. Cannot fire in loopback1 mode. */
		uint64_t rxbad                       : 1;  /**< R/W1C/H - Set by hardware whenever RX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t rxerr                       : 1;  /**< R/W1C/H - Set whenever RX receives a code group error in 10-bit to 8-bit decode logic. Cannot fire
                                                                 in loopback1 mode. */
		uint64_t txbad                       : 1;  /**< R/W1C/H - Set by hardware whenever TX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t txfifo                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO overflow condition. */
		uint64_t txfifu                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO underflow condition. */
		uint64_t an_err                      : 1;  /**< R/W1C/H - Autonegotiation error; AN resolution function failed. */
		uint64_t xmit                        : 1;  /**< R/W1C/H - Set whenever hardware detects a change in the XMIT variable. XMIT variable states are
                                                                 IDLE, CONFIG and DATA. */
		uint64_t lnkspd                      : 1;  /**< R/W1C/H - Set by hardware whenever link speed has changed. */
#else
		uint64_t lnkspd                      : 1;
		uint64_t xmit                        : 1;
		uint64_t an_err                      : 1;
		uint64_t txfifu                      : 1;
		uint64_t txfifo                      : 1;
		uint64_t txbad                       : 1;
		uint64_t rxerr                       : 1;
		uint64_t rxbad                       : 1;
		uint64_t rxlock                      : 1;
		uint64_t an_bad                      : 1;
		uint64_t sync_bad                    : 1;
		uint64_t dup                         : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_intx_s     cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_s     cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_s     cn88xxp1; */
} bdk_bgxx_gmp_pcs_intx_t;

static inline uint64_t BDK_BGXX_GMP_PCS_INTX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_INTX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030080ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_INTX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_INTX(...) bdk_bgxx_gmp_pcs_intx_t
#define bustype_BDK_BGXX_GMP_PCS_INTX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_INTX(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_INTX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_INTX(...) "BGXX_GMP_PCS_INTX"


/**
 * RSL - bgx#_gmp_pcs_int#_ena_w1c
 */
typedef union bdk_bgxx_gmp_pcs_intx_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_intx_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Code group sync failure debug help. DBG_SYNC interrupt fires when code group
                                                                 synchronization state machine makes a transition from SYNC_ACQUIRED_1 state to
                                                                 SYNC_ACQUIRED_2 state. (See IEEE 802.3-2005, figure 37-9). It indicates that a bad code
                                                                 group was received after code group synchronization was achieved. This interrupt should be
                                                                 disabled during normal link operation. Use it as a debug help feature only. */
		uint64_t dup                         : 1;  /**< R/W1C/H - Set whenever duplex mode changes on the link. */
		uint64_t sync_bad                    : 1;  /**< R/W1C/H - Set by hardware whenever RX sync state machine reaches a bad state. Should never be set
                                                                 during normal operation. */
		uint64_t an_bad                      : 1;  /**< R/W1C/H - Set by hardware whenever autonegotiation state machine reaches a bad state. Should never
                                                                 be set during normal operation. */
		uint64_t rxlock                      : 1;  /**< R/W1C/H - Set by hardware whenever code group sync or bit lock failure occurs. Cannot fire in loopback1 mode. */
		uint64_t rxbad                       : 1;  /**< R/W1C/H - Set by hardware whenever RX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t rxerr                       : 1;  /**< R/W1C/H - Set whenever RX receives a code group error in 10-bit to 8-bit decode logic. Cannot fire
                                                                 in loopback1 mode. */
		uint64_t txbad                       : 1;  /**< R/W1C/H - Set by hardware whenever TX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t txfifo                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO overflow condition. */
		uint64_t txfifu                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO underflow condition. */
		uint64_t an_err                      : 1;  /**< R/W1C/H - Autonegotiation error; AN resolution function failed. */
		uint64_t xmit                        : 1;  /**< R/W1C/H - Set whenever hardware detects a change in the XMIT variable. XMIT variable states are
                                                                 IDLE, CONFIG and DATA. */
		uint64_t lnkspd                      : 1;  /**< R/W1C/H - Set by hardware whenever link speed has changed. */
#else
		uint64_t lnkspd                      : 1;
		uint64_t xmit                        : 1;
		uint64_t an_err                      : 1;
		uint64_t txfifu                      : 1;
		uint64_t txfifo                      : 1;
		uint64_t txbad                       : 1;
		uint64_t rxerr                       : 1;
		uint64_t rxbad                       : 1;
		uint64_t rxlock                      : 1;
		uint64_t an_bad                      : 1;
		uint64_t sync_bad                    : 1;
		uint64_t dup                         : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_intx_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_ena_w1c_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_intx_ena_w1c_t;

static inline uint64_t BDK_BGXX_GMP_PCS_INTX_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_INTX_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030090ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_INTX_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_INTX_ENA_W1C(...) bdk_bgxx_gmp_pcs_intx_ena_w1c_t
#define bustype_BDK_BGXX_GMP_PCS_INTX_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_INTX_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_INTX_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_INTX_ENA_W1C(...) "BGXX_GMP_PCS_INTX_ENA_W1C"


/**
 * RSL - bgx#_gmp_pcs_int#_ena_w1s
 */
typedef union bdk_bgxx_gmp_pcs_intx_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_intx_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Code group sync failure debug help. DBG_SYNC interrupt fires when code group
                                                                 synchronization state machine makes a transition from SYNC_ACQUIRED_1 state to
                                                                 SYNC_ACQUIRED_2 state. (See IEEE 802.3-2005, figure 37-9). It indicates that a bad code
                                                                 group was received after code group synchronization was achieved. This interrupt should be
                                                                 disabled during normal link operation. Use it as a debug help feature only. */
		uint64_t dup                         : 1;  /**< R/W1C/H - Set whenever duplex mode changes on the link. */
		uint64_t sync_bad                    : 1;  /**< R/W1C/H - Set by hardware whenever RX sync state machine reaches a bad state. Should never be set
                                                                 during normal operation. */
		uint64_t an_bad                      : 1;  /**< R/W1C/H - Set by hardware whenever autonegotiation state machine reaches a bad state. Should never
                                                                 be set during normal operation. */
		uint64_t rxlock                      : 1;  /**< R/W1C/H - Set by hardware whenever code group sync or bit lock failure occurs. Cannot fire in loopback1 mode. */
		uint64_t rxbad                       : 1;  /**< R/W1C/H - Set by hardware whenever RX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t rxerr                       : 1;  /**< R/W1C/H - Set whenever RX receives a code group error in 10-bit to 8-bit decode logic. Cannot fire
                                                                 in loopback1 mode. */
		uint64_t txbad                       : 1;  /**< R/W1C/H - Set by hardware whenever TX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t txfifo                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO overflow condition. */
		uint64_t txfifu                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO underflow condition. */
		uint64_t an_err                      : 1;  /**< R/W1C/H - Autonegotiation error; AN resolution function failed. */
		uint64_t xmit                        : 1;  /**< R/W1C/H - Set whenever hardware detects a change in the XMIT variable. XMIT variable states are
                                                                 IDLE, CONFIG and DATA. */
		uint64_t lnkspd                      : 1;  /**< R/W1C/H - Set by hardware whenever link speed has changed. */
#else
		uint64_t lnkspd                      : 1;
		uint64_t xmit                        : 1;
		uint64_t an_err                      : 1;
		uint64_t txfifu                      : 1;
		uint64_t txfifo                      : 1;
		uint64_t txbad                       : 1;
		uint64_t rxerr                       : 1;
		uint64_t rxbad                       : 1;
		uint64_t rxlock                      : 1;
		uint64_t an_bad                      : 1;
		uint64_t sync_bad                    : 1;
		uint64_t dup                         : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_intx_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_ena_w1s_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_intx_ena_w1s_t;

static inline uint64_t BDK_BGXX_GMP_PCS_INTX_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_INTX_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030098ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_INTX_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_INTX_ENA_W1S(...) bdk_bgxx_gmp_pcs_intx_ena_w1s_t
#define bustype_BDK_BGXX_GMP_PCS_INTX_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_INTX_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_INTX_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_INTX_ENA_W1S(...) "BGXX_GMP_PCS_INTX_ENA_W1S"


/**
 * RSL - bgx#_gmp_pcs_int#_w1s
 */
typedef union bdk_bgxx_gmp_pcs_intx_w1s {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_intx_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Code group sync failure debug help. DBG_SYNC interrupt fires when code group
                                                                 synchronization state machine makes a transition from SYNC_ACQUIRED_1 state to
                                                                 SYNC_ACQUIRED_2 state. (See IEEE 802.3-2005, figure 37-9). It indicates that a bad code
                                                                 group was received after code group synchronization was achieved. This interrupt should be
                                                                 disabled during normal link operation. Use it as a debug help feature only. */
		uint64_t dup                         : 1;  /**< R/W1C/H - Set whenever duplex mode changes on the link. */
		uint64_t sync_bad                    : 1;  /**< R/W1C/H - Set by hardware whenever RX sync state machine reaches a bad state. Should never be set
                                                                 during normal operation. */
		uint64_t an_bad                      : 1;  /**< R/W1C/H - Set by hardware whenever autonegotiation state machine reaches a bad state. Should never
                                                                 be set during normal operation. */
		uint64_t rxlock                      : 1;  /**< R/W1C/H - Set by hardware whenever code group sync or bit lock failure occurs. Cannot fire in loopback1 mode. */
		uint64_t rxbad                       : 1;  /**< R/W1C/H - Set by hardware whenever RX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t rxerr                       : 1;  /**< R/W1C/H - Set whenever RX receives a code group error in 10-bit to 8-bit decode logic. Cannot fire
                                                                 in loopback1 mode. */
		uint64_t txbad                       : 1;  /**< R/W1C/H - Set by hardware whenever TX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
		uint64_t txfifo                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO overflow condition. */
		uint64_t txfifu                      : 1;  /**< R/W1C/H - Set whenever hardware detects a TX FIFO underflow condition. */
		uint64_t an_err                      : 1;  /**< R/W1C/H - Autonegotiation error; AN resolution function failed. */
		uint64_t xmit                        : 1;  /**< R/W1C/H - Set whenever hardware detects a change in the XMIT variable. XMIT variable states are
                                                                 IDLE, CONFIG and DATA. */
		uint64_t lnkspd                      : 1;  /**< R/W1C/H - Set by hardware whenever link speed has changed. */
#else
		uint64_t lnkspd                      : 1;
		uint64_t xmit                        : 1;
		uint64_t an_err                      : 1;
		uint64_t txfifu                      : 1;
		uint64_t txfifo                      : 1;
		uint64_t txbad                       : 1;
		uint64_t rxerr                       : 1;
		uint64_t rxbad                       : 1;
		uint64_t rxlock                      : 1;
		uint64_t an_bad                      : 1;
		uint64_t sync_bad                    : 1;
		uint64_t dup                         : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_intx_w1s_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_w1s_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_intx_w1s_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_intx_w1s_t;

static inline uint64_t BDK_BGXX_GMP_PCS_INTX_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_INTX_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030088ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_INTX_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_INTX_W1S(...) bdk_bgxx_gmp_pcs_intx_w1s_t
#define bustype_BDK_BGXX_GMP_PCS_INTX_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_INTX_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_INTX_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_INTX_W1S(...) "BGXX_GMP_PCS_INTX_W1S"


/**
 * RSL - bgx#_gmp_pcs_link#_timer
 *
 * This is the 1.6 ms nominal Link timer register.
 *
 */
typedef union bdk_bgxx_gmp_pcs_linkx_timer {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_linkx_timer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< R/W - (Coprocessor clock period * 1024) * COUNT should be 1.6 ms for SGMII and 10 ms otherwise,
                                                                 which is the link timer used in autonegotiation. Reset assumes a 700 MHz coprocessor
                                                                 clock for 1.6 ms link timer. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_linkx_timer_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_linkx_timer_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_linkx_timer_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_linkx_timer_t;

static inline uint64_t BDK_BGXX_GMP_PCS_LINKX_TIMER(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_LINKX_TIMER(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030040ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_LINKX_TIMER", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_LINKX_TIMER(...) bdk_bgxx_gmp_pcs_linkx_timer_t
#define bustype_BDK_BGXX_GMP_PCS_LINKX_TIMER(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_LINKX_TIMER(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_LINKX_TIMER(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_LINKX_TIMER(...) "BGXX_GMP_PCS_LINKX_TIMER"


/**
 * RSL - bgx#_gmp_pcs_misc#_ctl
 *
 * INTERNAL:
 * SGMII bit [12] is really a misnomer, it is a decode  of pi_qlm_cfg pins to indicate SGMII or
 * 1000Base-X modes.
 *
 * Repeat note from SGM_AN_ADV register
 * NOTE: The SGMII AN Advertisement Register above will be sent during Auto Negotiation if the
 * MAC_PHY mode bit in misc_ctl_reg is set (1=PHY mode). If the bit is not set (0=MAC mode), the
 * tx_config_reg[14] becomes ACK bit and [0] is always 1.
 * All other bits in tx_config_reg sent will be 0. The PHY dictates the Auto Negotiation results.
 * SGMII Misc Control Register
 */
typedef union bdk_bgxx_gmp_pcs_miscx_ctl {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_miscx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t sgmii                       : 1;  /**< RO/H - SGMII mode.
                                                                 0 = other mode selected.
                                                                 1 = SGMII or 1000BASE-X mode selected.

                                                                 See GSER()_LANE_MODE[LMODE]. */
		uint64_t gmxeno                      : 1;  /**< R/W - GMI enable override. When set, forces GMI to appear disabled. The enable/disable status of
                                                                 GMI is checked only at SOP of every packet. */
		uint64_t loopbck2                    : 1;  /**< R/W - Sets external loopback mode to return RX data back out via the TX data path. 0 = No
                                                                 loopback, 1 = Loopback.
                                                                 LOOPBCK1 and LOOPBCK2 modes may not be supported simultaneously. */
		uint64_t mac_phy                     : 1;  /**< R/W - MAC/PHY.
                                                                 0 = MAC.
                                                                 1 = PHY decides the TX_CONFIG_REG value to be sent during autonegotiation. */
		uint64_t mode                        : 1;  /**< R/W - Mode bit.

                                                                 _ 0 = SGMII mode is selected and the following note applies.
                                                                 The SGMII AN advertisement register (BGX()_GMP_PCS_SGM()_AN_ADV) is sent during
                                                                 autonegotiation if BGX()_GMP_PCS_MISC()_CTL[MAC_PHY] = 1 (PHY mode). If [MAC_PHY]
                                                                 = 0 (MAC mode), the TX_CONFIG_REG\<14\> becomes ACK bit and \<0\> is always 1. All other bits
                                                                 in TX_CONFIG_REG sent are 0. The PHY dictates the autonegotiation results.

                                                                 _ 1 = 1000Base-X mode is selected. Autonegotiation follows IEEE 802.3 clause 37. */
		uint64_t an_ovrd                     : 1;  /**< R/W - Autonegotiation results override:
                                                                 0 = Disable.
                                                                 1 = Enable override. Autonegotiation is allowed to happen but the results are ignored
                                                                 when this bit is set.  Duplex and Link speed values are set from BGX()_GMP_PCS_MISC()_CTL. */
		uint64_t samp_pt                     : 7;  /**< R/W - Byte number in elongated frames for 10/100 Mb/s operation for data sampling on RX side in
                                                                 PCS. Recommended values are 0x5 for 100 Mb/s operation and 0x32 for 10 Mb/s operation.

                                                                 For 10 Mb/s operation, this field should be set to a value less than 99 and greater than
                                                                 0.
                                                                 If set out of this range, a value of 50 is used for actual sampling internally without
                                                                 affecting the CSR field.

                                                                 For 100 Mb/s operation this field should be set to a value less than 9 and greater than 0.
                                                                 If set out of this range, a value of 5 is used for actual sampling internally without
                                                                 affecting the CSR field. */
#else
		uint64_t samp_pt                     : 7;
		uint64_t an_ovrd                     : 1;
		uint64_t mode                        : 1;
		uint64_t mac_phy                     : 1;
		uint64_t loopbck2                    : 1;
		uint64_t gmxeno                      : 1;
		uint64_t sgmii                       : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_miscx_ctl_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_miscx_ctl_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_miscx_ctl_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_miscx_ctl_t;

static inline uint64_t BDK_BGXX_GMP_PCS_MISCX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_MISCX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030078ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_MISCX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_MISCX_CTL(...) bdk_bgxx_gmp_pcs_miscx_ctl_t
#define bustype_BDK_BGXX_GMP_PCS_MISCX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_MISCX_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_MISCX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_MISCX_CTL(...) "BGXX_GMP_PCS_MISCX_CTL"


/**
 * RSL - bgx#_gmp_pcs_mr#_control
 */
typedef union bdk_bgxx_gmp_pcs_mrx_control {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_mrx_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t reset                       : 1;  /**< R/W/H - Set to reset.
                                                                 0 = Normal operation.
                                                                 1 = Software PCS reset.

                                                                 The bit returns to 0 after PCS has been reset. Takes 32 coprocessor-clock cycles to reset
                                                                 PCS. */
		uint64_t loopbck1                    : 1;  /**< R/W - Enable loopback:
                                                                   0 = Normal operation.
                                                                   1 = Internal loopback mode.

                                                                 The loopback mode returns loopback TX data from GMII TX back to GMII RX interface. The
                                                                 loopback happens in the PCS module. Autonegotiation is disabled even if AN_EN is set
                                                                 during loopback. */
		uint64_t spdlsb                      : 1;  /**< R/W - Least-significant bit of the link-speed field, i.e. SPD\<0\>. Refer to SPDMSB. */
		uint64_t an_en                       : 1;  /**< R/W - Autonegotiation enable. */
		uint64_t pwr_dn                      : 1;  /**< R/W - Power down:
                                                                 0 = Normal operation.
                                                                 1 = Power down (hardware reset). */
		uint64_t reserved_10_10              : 1;
		uint64_t rst_an                      : 1;  /**< R/W/H - Reset autonegotiation. When set, if AN_EN = 1 and
                                                                 BGX()_GMP_PCS_MR()_STATUS[AN_ABIL] = 1, autonegotiation begins. Otherwise,
                                                                 software write requests are ignored and this bit remains at 0. This bit clears itself to
                                                                 0, when autonegotiation starts. */
		uint64_t dup                         : 1;  /**< R/W - Duplex mode:
                                                                   0 = half duplex; effective only if autonegotiation is disabled.
                                                                   1 = full duplex.

                                                                 If BGX()_GMP_PCS_MR()_STATUS \<15:9\> and
                                                                 BGX()_GMP_PCS_AN()_ADV\<15:12\> allow only one duplex mode, this bit corresponds to
                                                                 that value and any attempts to write are ignored. */
		uint64_t coltst                      : 1;  /**< R/W - Enable COL signal test.
                                                                 During COL test, the COL signal reflects the GMII TX_EN signal with less than 16BT delay. */
		uint64_t spdmsb                      : 1;  /**< R/W - Link speed most-significant bit, i.e SPD\<1\>; effective only if autonegotiation is
                                                                 disabled.

                                                                 \<pre\>
                                                                 [SPDMSB]   [SPDLSB]   Link Speed
                                                                  0          0         10 Mb/s
                                                                  0          1         100 Mb/s
                                                                  1          0         1000 Mb/s
                                                                  1          1         reserved
                                                                 \</pre\> */
		uint64_t uni                         : 1;  /**< R/W - Unidirectional (Std 802.3-2005, Clause 66.2). When set to 1, this bit overrides AN_EN and
                                                                 disables the autonegotiation variable mr_an_enable. Used in both 1000BASE-X and SGMII
                                                                 modes. */
		uint64_t reserved_0_4                : 5;
#else
		uint64_t reserved_0_4                : 5;
		uint64_t uni                         : 1;
		uint64_t spdmsb                      : 1;
		uint64_t coltst                      : 1;
		uint64_t dup                         : 1;
		uint64_t rst_an                      : 1;
		uint64_t reserved_10_10              : 1;
		uint64_t pwr_dn                      : 1;
		uint64_t an_en                       : 1;
		uint64_t spdlsb                      : 1;
		uint64_t loopbck1                    : 1;
		uint64_t reset                       : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_mrx_control_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_mrx_control_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_mrx_control_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_mrx_control_t;

static inline uint64_t BDK_BGXX_GMP_PCS_MRX_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_MRX_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_MRX_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_MRX_CONTROL(...) bdk_bgxx_gmp_pcs_mrx_control_t
#define bustype_BDK_BGXX_GMP_PCS_MRX_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_MRX_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_MRX_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_MRX_CONTROL(...) "BGXX_GMP_PCS_MRX_CONTROL"


/**
 * RSL - bgx#_gmp_pcs_mr#_status
 *
 * Bits \<15:9\> in this register indicate the ability to operate when
 * BGX()_GMP_PCS_MISC()_CTL[MAC_PHY] is set to MAC mode. Bits \<15:9\> are always read as
 * 0, indicating that the chip cannot operate in the corresponding modes. The field [RM_FLT] is a
 * 'don't care' when the selected mode is SGMII.
 */
typedef union bdk_bgxx_gmp_pcs_mrx_status {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_mrx_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t hun_t4                      : 1;  /**< RO/H - Indicates 100BASE-T4 capable. */
		uint64_t hun_xfd                     : 1;  /**< RO/H - Indicates 100BASE-X full duplex. */
		uint64_t hun_xhd                     : 1;  /**< RO/H - Indicates 100BASE-X half duplex. */
		uint64_t ten_fd                      : 1;  /**< RO/H - Indicates 10Mb/s full duplex. */
		uint64_t ten_hd                      : 1;  /**< RO/H - Indicates 10Mb/s half duplex. */
		uint64_t hun_t2fd                    : 1;  /**< RO/H - Indicates 100BASE-T2 full duplex. */
		uint64_t hun_t2hd                    : 1;  /**< RO/H - Indicates 100BASE-T2 half duplex. */
		uint64_t ext_st                      : 1;  /**< RO/H - Extended status information. When set to 1, indicates that additional status data is
                                                                 available in BGX()_GMP_PCS_AN()_EXT_ST. */
		uint64_t reserved_7_7                : 1;
		uint64_t prb_sup                     : 1;  /**< RO/H - Preamble not needed.
                                                                 0 = Cannot accept frames without preamble bytes.
                                                                 1 = Can work without preamble bytes at the beginning of frames. */
		uint64_t an_cpt                      : 1;  /**< RO/H - Indicates autonegotiation is complete; the contents of the
                                                                 BGX()_GMP_PCS_AN()_RESULTS are valid. */
		uint64_t rm_flt                      : 1;  /**< RO/H - Indicates remote fault condition occurred. This bit implements a latching-high behavior.
                                                                 It is cleared when software reads this register or when
                                                                 BGX()_GMP_PCS_MR()_CONTROL[RESET] is asserted.
                                                                 See BGX()_GMP_PCS_AN()_ADV[REM_FLT] for fault conditions. */
		uint64_t an_abil                     : 1;  /**< RO/H - Indicates autonegotiation capable. */
		uint64_t lnk_st                      : 1;  /**< RO/H - Link state:
                                                                   0 = link down.
                                                                   1 = link up.

                                                                 Set during autonegotiation process. Set whenever XMIT = DATA. Latching-low behavior when
                                                                 link goes down. Link down value of the bit stays low until software reads the register. */
		uint64_t reserved_1_1                : 1;
		uint64_t extnd                       : 1;  /**< RO/H - This field is always 0, extended capability registers not present. */
#else
		uint64_t extnd                       : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t lnk_st                      : 1;
		uint64_t an_abil                     : 1;
		uint64_t rm_flt                      : 1;
		uint64_t an_cpt                      : 1;
		uint64_t prb_sup                     : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t ext_st                      : 1;
		uint64_t hun_t2hd                    : 1;
		uint64_t hun_t2fd                    : 1;
		uint64_t ten_hd                      : 1;
		uint64_t ten_fd                      : 1;
		uint64_t hun_xhd                     : 1;
		uint64_t hun_xfd                     : 1;
		uint64_t hun_t4                      : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_mrx_status_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_mrx_status_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_mrx_status_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_mrx_status_t;

static inline uint64_t BDK_BGXX_GMP_PCS_MRX_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_MRX_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030008ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_MRX_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_MRX_STATUS(...) bdk_bgxx_gmp_pcs_mrx_status_t
#define bustype_BDK_BGXX_GMP_PCS_MRX_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_MRX_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_MRX_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_MRX_STATUS(...) "BGXX_GMP_PCS_MRX_STATUS"


/**
 * RSL - bgx#_gmp_pcs_rx#_states
 */
typedef union bdk_bgxx_gmp_pcs_rxx_states {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_rxx_states_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t rx_bad                      : 1;  /**< RO/H - Receive state machine is in an illegal state. */
		uint64_t rx_st                       : 5;  /**< RO/H - Receive state-machine state. */
		uint64_t sync_bad                    : 1;  /**< RO/H - Receive synchronization state machine is in an illegal state. */
		uint64_t sync                        : 4;  /**< RO/H - Receive synchronization state-machine state. */
		uint64_t an_bad                      : 1;  /**< RO/H - Autonegotiation state machine is in an illegal state. */
		uint64_t an_st                       : 4;  /**< RO/H - Autonegotiation state-machine state. */
#else
		uint64_t an_st                       : 4;
		uint64_t an_bad                      : 1;
		uint64_t sync                        : 4;
		uint64_t sync_bad                    : 1;
		uint64_t rx_st                       : 5;
		uint64_t rx_bad                      : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_rxx_states_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_rxx_states_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_rxx_states_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_rxx_states_t;

static inline uint64_t BDK_BGXX_GMP_PCS_RXX_STATES(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_RXX_STATES(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030058ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_RXX_STATES", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_RXX_STATES(...) bdk_bgxx_gmp_pcs_rxx_states_t
#define bustype_BDK_BGXX_GMP_PCS_RXX_STATES(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_RXX_STATES(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_RXX_STATES(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_RXX_STATES(...) "BGXX_GMP_PCS_RXX_STATES"


/**
 * RSL - bgx#_gmp_pcs_rx#_sync
 */
typedef union bdk_bgxx_gmp_pcs_rxx_sync {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_rxx_sync_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t sync                        : 1;  /**< RO/H - When set, code group synchronization achieved. */
		uint64_t bit_lock                    : 1;  /**< RO/H - When set, bit lock achieved. */
#else
		uint64_t bit_lock                    : 1;
		uint64_t sync                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_rxx_sync_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_rxx_sync_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_rxx_sync_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_rxx_sync_t;

static inline uint64_t BDK_BGXX_GMP_PCS_RXX_SYNC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_RXX_SYNC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030050ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_RXX_SYNC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_RXX_SYNC(...) bdk_bgxx_gmp_pcs_rxx_sync_t
#define bustype_BDK_BGXX_GMP_PCS_RXX_SYNC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_RXX_SYNC(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_RXX_SYNC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_RXX_SYNC(...) "BGXX_GMP_PCS_RXX_SYNC"


/**
 * RSL - bgx#_gmp_pcs_sgm#_an_adv
 *
 * This is the SGMII autonegotiation advertisement register (sent out as TX_CONFIG_REG). This
 * register is sent during autonegotiation if
 * BGX()_GMP_PCS_MISC()_CTL[MAC_PHY] is set (1 = PHY mode). If the bit is not set (0 =
 * MAC mode), the TX_CONFIG_REG\<14\> becomes ACK bit and \<0\> is always 1. All other bits in
 * TX_CONFIG_REG sent will be 0. The PHY dictates the autonegotiation results.
 */
typedef union bdk_bgxx_gmp_pcs_sgmx_an_adv {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_sgmx_an_adv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t link                        : 1;  /**< R/W - Link status: 1 = Link up, 0 = Link down. */
		uint64_t ack                         : 1;  /**< RO/H - Autonegotiation acknowledgement. */
		uint64_t reserved_13_13              : 1;
		uint64_t dup                         : 1;  /**< R/W - Duplex mode: 1 = full duplex, 0 = half duplex */
		uint64_t speed                       : 2;  /**< R/W - Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
		uint64_t reserved_1_9                : 9;
		uint64_t one                         : 1;  /**< RO/H - Always set to match TX_CONFIG_REG\<0\>. */
#else
		uint64_t one                         : 1;
		uint64_t reserved_1_9                : 9;
		uint64_t speed                       : 2;
		uint64_t dup                         : 1;
		uint64_t reserved_13_13              : 1;
		uint64_t ack                         : 1;
		uint64_t link                        : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_sgmx_an_adv_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_sgmx_an_adv_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_sgmx_an_adv_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_sgmx_an_adv_t;

static inline uint64_t BDK_BGXX_GMP_PCS_SGMX_AN_ADV(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_SGMX_AN_ADV(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030068ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_SGMX_AN_ADV", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_SGMX_AN_ADV(...) bdk_bgxx_gmp_pcs_sgmx_an_adv_t
#define bustype_BDK_BGXX_GMP_PCS_SGMX_AN_ADV(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_SGMX_AN_ADV(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_SGMX_AN_ADV(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_SGMX_AN_ADV(...) "BGXX_GMP_PCS_SGMX_AN_ADV"


/**
 * RSL - bgx#_gmp_pcs_sgm#_lp_adv
 *
 * This is the SGMII Link partner advertisement register (received as RX_CONFIG_REG).
 *
 */
typedef union bdk_bgxx_gmp_pcs_sgmx_lp_adv {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_sgmx_lp_adv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t link                        : 1;  /**< RO/H - Link status: 1 = Link up, 0 = Link down. */
		uint64_t reserved_13_14              : 2;
		uint64_t dup                         : 1;  /**< RO/H - Duplex mode: 1 = Full duplex, 0 = Half duplex */
		uint64_t speed                       : 2;  /**< RO/H - Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
		uint64_t reserved_1_9                : 9;
		uint64_t one                         : 1;  /**< RO/H - Always set to match TX_CONFIG_REG\<0\> */
#else
		uint64_t one                         : 1;
		uint64_t reserved_1_9                : 9;
		uint64_t speed                       : 2;
		uint64_t dup                         : 1;
		uint64_t reserved_13_14              : 2;
		uint64_t link                        : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_sgmx_lp_adv_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_sgmx_lp_adv_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_sgmx_lp_adv_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_sgmx_lp_adv_t;

static inline uint64_t BDK_BGXX_GMP_PCS_SGMX_LP_ADV(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_SGMX_LP_ADV(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030070ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_SGMX_LP_ADV", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_SGMX_LP_ADV(...) bdk_bgxx_gmp_pcs_sgmx_lp_adv_t
#define bustype_BDK_BGXX_GMP_PCS_SGMX_LP_ADV(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_SGMX_LP_ADV(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_SGMX_LP_ADV(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_SGMX_LP_ADV(...) "BGXX_GMP_PCS_SGMX_LP_ADV"


/**
 * RSL - bgx#_gmp_pcs_tx#_states
 */
typedef union bdk_bgxx_gmp_pcs_txx_states {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_txx_states_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t xmit                        : 2;  /**< RO/H - 0x0 = Undefined.
                                                                 0x1 = Config.
                                                                 0x2 = Idle.
                                                                 0x3 = Data. */
		uint64_t tx_bad                      : 1;  /**< RO/H - Transmit state machine in an illegal state. */
		uint64_t ord_st                      : 4;  /**< RO/H - Transmit ordered set state-machine state. */
#else
		uint64_t ord_st                      : 4;
		uint64_t tx_bad                      : 1;
		uint64_t xmit                        : 2;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_txx_states_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_txx_states_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_txx_states_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_txx_states_t;

static inline uint64_t BDK_BGXX_GMP_PCS_TXX_STATES(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_TXX_STATES(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030060ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_TXX_STATES", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_TXX_STATES(...) bdk_bgxx_gmp_pcs_txx_states_t
#define bustype_BDK_BGXX_GMP_PCS_TXX_STATES(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_TXX_STATES(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_TXX_STATES(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_TXX_STATES(...) "BGXX_GMP_PCS_TXX_STATES"


/**
 * RSL - bgx#_gmp_pcs_tx_rx#_polarity
 *
 * BGX()_GMP_PCS_TX_RX()_POLARITY[AUTORXPL] shows correct polarity needed on the link
 * receive path after code group synchronization is achieved.
 */
typedef union bdk_bgxx_gmp_pcs_tx_rxx_polarity {
	uint64_t u;
	struct bdk_bgxx_gmp_pcs_tx_rxx_polarity_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t rxovrd                      : 1;  /**< R/W - RX polarity override.
                                                                 0 = AUTORXPL determines polarity.
                                                                 1 = RXPLRT determines polarity. */
		uint64_t autorxpl                    : 1;  /**< RO/H - Auto RX polarity detected:
                                                                 0 = Normal polarity.
                                                                 1 = Inverted polarity.

                                                                 This bit always represents the correct RX polarity setting needed for successful RX path
                                                                 operation, once a successful code group sync is obtained. */
		uint64_t rxplrt                      : 1;  /**< R/W - RX polarity: 0 = Normal polarity, 1 = Inverted polarity. */
		uint64_t txplrt                      : 1;  /**< R/W - TX polarity: 0 = Normal polarity, 1 = Inverted polarity. */
#else
		uint64_t txplrt                      : 1;
		uint64_t rxplrt                      : 1;
		uint64_t autorxpl                    : 1;
		uint64_t rxovrd                      : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_gmp_pcs_tx_rxx_polarity_s cn85xx; */
	/* struct bdk_bgxx_gmp_pcs_tx_rxx_polarity_s cn88xx; */
	/* struct bdk_bgxx_gmp_pcs_tx_rxx_polarity_s cn88xxp1; */
} bdk_bgxx_gmp_pcs_tx_rxx_polarity_t;

static inline uint64_t BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0030048ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_GMP_PCS_TX_RXX_POLARITY", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(...) bdk_bgxx_gmp_pcs_tx_rxx_polarity_t
#define bustype_BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(p1,p2) (p1)
#define arguments_BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_GMP_PCS_TX_RXX_POLARITY(...) "BGXX_GMP_PCS_TX_RXX_POLARITY"


/**
 * RSL - bgx#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the BGX_INT_VEC_E
 * enumeration.
 */
typedef union bdk_bgxx_msix_pbax {
	uint64_t u;
	struct bdk_bgxx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated BGX_MSIX_VEC()_CTL, enumerated by BGX_INT_VEC_E.
                                                                 Bits that have no associated BGX_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_bgxx_msix_pbax_s        cn85xx; */
	/* struct bdk_bgxx_msix_pbax_s        cn88xx; */
	/* struct bdk_bgxx_msix_pbax_s        cn88xxp1; */
} bdk_bgxx_msix_pbax_t;

static inline uint64_t BDK_BGXX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000087E0E04F0000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_MSIX_PBAX(...) bdk_bgxx_msix_pbax_t
#define bustype_BDK_BGXX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_BGXX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_MSIX_PBAX(...) "BGXX_MSIX_PBAX"


/**
 * RSL - bgx#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the BGX_INT_VEC_E enumeration.
 *
 */
typedef union bdk_bgxx_msix_vecx_addr {
	uint64_t u;
	struct bdk_bgxx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's BGX_MSIX_VEC()_ADDR, BGX_MSIX_VEC()_CTL, and corresponding
                                                                 bit of BGX_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCBGX_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCBGX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_bgxx_msix_vecx_addr_s   cn85xx; */
	/* struct bdk_bgxx_msix_vecx_addr_s   cn88xx; */
	/* struct bdk_bgxx_msix_vecx_addr_s   cn88xxp1; */
} bdk_bgxx_msix_vecx_addr_t;

static inline uint64_t BDK_BGXX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 29)))
		return 0x000087E0E0400000ull + (param1 & 1) * 0x1000000ull + (param2 & 31) * 0x10ull;
	csr_fatal("BDK_BGXX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_MSIX_VECX_ADDR(...) bdk_bgxx_msix_vecx_addr_t
#define bustype_BDK_BGXX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_BGXX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_MSIX_VECX_ADDR(...) "BGXX_MSIX_VECX_ADDR"


/**
 * RSL - bgx#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the BGX_INT_VEC_E enumeration.
 *
 */
typedef union bdk_bgxx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_bgxx_msix_vecx_ctl_s {
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
	/* struct bdk_bgxx_msix_vecx_ctl_s    cn85xx; */
	/* struct bdk_bgxx_msix_vecx_ctl_s    cn88xx; */
	/* struct bdk_bgxx_msix_vecx_ctl_s    cn88xxp1; */
} bdk_bgxx_msix_vecx_ctl_t;

static inline uint64_t BDK_BGXX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 29)))
		return 0x000087E0E0400008ull + (param1 & 1) * 0x1000000ull + (param2 & 31) * 0x10ull;
	csr_fatal("BDK_BGXX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_MSIX_VECX_CTL(...) bdk_bgxx_msix_vecx_ctl_t
#define bustype_BDK_BGXX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_MSIX_VECX_CTL(...) "BGXX_MSIX_VECX_CTL"


/**
 * RSL - bgx#_smu#_cbfc_ctl
 */
typedef union bdk_bgxx_smux_cbfc_ctl {
	uint64_t u;
	struct bdk_bgxx_smux_cbfc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t phys_en                     : 16; /**< R/W - Physical backpressure enable. Determines which classes/channels will have physical
                                                                 backpressure PAUSE packets. The value placed in the class enable vector field of the
                                                                 PFC/CBFC PAUSE packet is PHYS_EN | LOGL_EN. */
		uint64_t logl_en                     : 16; /**< R/W - Logical backpressure enable. Determines which classes/channels will have logical
                                                                 backpressure PAUSE packets. The value placed in the class enable vector field of the
                                                                 PFC/CBFC PAUSE packet is PHYS_EN | LOGL_EN. */
		uint64_t reserved_4_31               : 28;
		uint64_t bck_en                      : 1;  /**< R/W - Forward PFC/CBFC PAUSE information to the backpressure block. */
		uint64_t drp_en                      : 1;  /**< R/W - Drop-control enable. When set, drop PFC/CBFC PAUSE frames. */
		uint64_t tx_en                       : 1;  /**< R/W - Transmit enable. When set, allow for PFC/CBFC PAUSE packets. Must be clear in HiGig2 mode
                                                                 i.e. when BGX()_SMU()_TX_CTL[HG_EN] = 1 and BGX()_SMU()_RX_UDD_SKP[LEN] =
                                                                 16. */
		uint64_t rx_en                       : 1;  /**< R/W - Receive enable. When set, allow for PFC/CBFC PAUSE packets. Must be clear in HiGig2 mode
                                                                 i.e. when BGX()_SMU()_TX_CTL[HG_EN] = 1 and BGX()_SMU()_RX_UDD_SKP[LEN] =
                                                                 16. */
#else
		uint64_t rx_en                       : 1;
		uint64_t tx_en                       : 1;
		uint64_t drp_en                      : 1;
		uint64_t bck_en                      : 1;
		uint64_t reserved_4_31               : 28;
		uint64_t logl_en                     : 16;
		uint64_t phys_en                     : 16;
#endif
	} s;
	/* struct bdk_bgxx_smux_cbfc_ctl_s    cn85xx; */
	/* struct bdk_bgxx_smux_cbfc_ctl_s    cn88xx; */
	/* struct bdk_bgxx_smux_cbfc_ctl_s    cn88xxp1; */
} bdk_bgxx_smux_cbfc_ctl_t;

static inline uint64_t BDK_BGXX_SMUX_CBFC_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_CBFC_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020218ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_CBFC_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_CBFC_CTL(...) bdk_bgxx_smux_cbfc_ctl_t
#define bustype_BDK_BGXX_SMUX_CBFC_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_CBFC_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_CBFC_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_CBFC_CTL(...) "BGXX_SMUX_CBFC_CTL"


/**
 * RSL - bgx#_smu#_ctrl
 */
typedef union bdk_bgxx_smux_ctrl {
	uint64_t u;
	struct bdk_bgxx_smux_ctrl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t tx_idle                     : 1;  /**< RO/H - TX machine is idle. This indication pertains to the framer FSM and ignores the effects on
                                                                 the data-path controls or values which occur when BGX()_SMU()_TX_CTL[LS_BYP] is
                                                                 set. */
		uint64_t rx_idle                     : 1;  /**< RO/H - RX machine is idle. */
#else
		uint64_t rx_idle                     : 1;
		uint64_t tx_idle                     : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_smux_ctrl_s        cn85xx; */
	/* struct bdk_bgxx_smux_ctrl_s        cn88xx; */
	/* struct bdk_bgxx_smux_ctrl_s        cn88xxp1; */
} bdk_bgxx_smux_ctrl_t;

static inline uint64_t BDK_BGXX_SMUX_CTRL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_CTRL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020200ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_CTRL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_CTRL(...) bdk_bgxx_smux_ctrl_t
#define bustype_BDK_BGXX_SMUX_CTRL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_CTRL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_CTRL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_CTRL(...) "BGXX_SMUX_CTRL"


/**
 * RSL - bgx#_smu#_ext_loopback
 *
 * In loopback mode, the IFG1+IFG2 of local and remote parties must match exactly; otherwise one
 * of the two sides' loopback FIFO will overrun: BGX()_SMU()_TX_INT[LB_OVRFLW].
 */
typedef union bdk_bgxx_smux_ext_loopback {
	uint64_t u;
	struct bdk_bgxx_smux_ext_loopback_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t en                          : 1;  /**< R/W - Loopback enable. Puts the packet interface in external loopback mode where the RX lines
                                                                 are reflected on the TX lines. */
		uint64_t thresh                      : 4;  /**< R/W - Threshold on the TX FIFO. Software must only write the typical value. Any other value
                                                                 causes loopback mode not to function correctly. */
#else
		uint64_t thresh                      : 4;
		uint64_t en                          : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_smux_ext_loopback_s cn85xx; */
	/* struct bdk_bgxx_smux_ext_loopback_s cn88xx; */
	/* struct bdk_bgxx_smux_ext_loopback_s cn88xxp1; */
} bdk_bgxx_smux_ext_loopback_t;

static inline uint64_t BDK_BGXX_SMUX_EXT_LOOPBACK(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_EXT_LOOPBACK(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020208ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_EXT_LOOPBACK", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_EXT_LOOPBACK(...) bdk_bgxx_smux_ext_loopback_t
#define bustype_BDK_BGXX_SMUX_EXT_LOOPBACK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_EXT_LOOPBACK(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_EXT_LOOPBACK(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_EXT_LOOPBACK(...) "BGXX_SMUX_EXT_LOOPBACK"


/**
 * RSL - bgx#_smu#_hg2_control
 *
 * HiGig2 TX- and RX-enable are normally set together for HiGig2 messaging. Setting just the TX
 * or RX bit results in only the HG2 message transmit or receive capability.
 *
 * Setting [PHYS_EN] and [LOGL_EN] to 1 allows link PAUSE or backpressure to PKO as per the
 * received HiGig2 message. Setting these fields to 0 disables link PAUSE and backpressure to PKO
 * in response to received messages.
 *
 * BGX()_SMU()_TX_CTL[HG_EN] must be set (to enable HiGig) whenever either [HG2TX_EN] or
 * [HG2RX_EN] are set. BGX()_SMU()_RX_UDD_SKP[LEN] must be set to 16 (to select HiGig2)
 * whenever either [HG2TX_EN] or [HG2RX_EN] are set.
 *
 * BGX()_CMR_RX_OVR_BP[EN\<0\>] must be set and BGX()_CMR_RX_OVR_BP[BP\<0\>] must be cleared
 * to 0 (to forcibly disable hardware-automatic 802.3 PAUSE packet generation) with the HiGig2
 * Protocol when BGX()_SMU()_HG2_CONTROL[HG2TX_EN] = 0. (The HiGig2 protocol is indicated
 * by BGX()_SMU()_TX_CTL[HG_EN] = 1 and BGX()_SMU()_RX_UDD_SKP[LEN]=16.) Hardware
 * can only autogenerate backpressure via HiGig2 messages (optionally, when HG2TX_EN = 1) with
 * the HiGig2 protocol.
 */
typedef union bdk_bgxx_smux_hg2_control {
	uint64_t u;
	struct bdk_bgxx_smux_hg2_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t hg2tx_en                    : 1;  /**< R/W - Enable transmission of HG2 physical and logical messages. When set, also disables hardware
                                                                 autogenerated (802.3 and PFC/CBFC) PAUSE frames. (CNXXXX cannot generate proper 802.3 or
                                                                 PFC/CBFC PAUSE frames in HiGig2 mode.) */
		uint64_t hg2rx_en                    : 1;  /**< R/W - Enable extraction and processing of HG2 message packet from RX flow. Physical and logical
                                                                 PAUSE information is used to PAUSE physical-link, backpressure PKO. This field must be set
                                                                 when HiGig2 messages are present in the receive stream. This bit is also forwarded to CMR
                                                                 so it can generate the required deferring signals to SMU TX and backpressure signals to
                                                                 PKO. */
		uint64_t phys_en                     : 1;  /**< R/W - Physical-link PAUSE enable for received HiGig2 physical PAUSE message. This bit enables
                                                                 the SMU TX to CMR HG2 deferring counter to be set every time SMU RX receives and filters
                                                                 out a valid physical HG2 message. */
		uint64_t logl_en                     : 16; /**< R/W - 16-bit XOF enables for received HiGig2 messages or PFC/CBFC packets. This field is NOT
                                                                 used by SMU at all. It is forwarded to CMR without alteration. It appears here for
                                                                 backward compatibility. */
#else
		uint64_t logl_en                     : 16;
		uint64_t phys_en                     : 1;
		uint64_t hg2rx_en                    : 1;
		uint64_t hg2tx_en                    : 1;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_bgxx_smux_hg2_control_s cn85xx; */
	/* struct bdk_bgxx_smux_hg2_control_s cn88xx; */
	/* struct bdk_bgxx_smux_hg2_control_s cn88xxp1; */
} bdk_bgxx_smux_hg2_control_t;

static inline uint64_t BDK_BGXX_SMUX_HG2_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_HG2_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020210ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_HG2_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_HG2_CONTROL(...) bdk_bgxx_smux_hg2_control_t
#define bustype_BDK_BGXX_SMUX_HG2_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_HG2_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_HG2_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_HG2_CONTROL(...) "BGXX_SMUX_HG2_CONTROL"


/**
 * RSL - bgx#_smu#_rx_bad_col_hi
 */
typedef union bdk_bgxx_smux_rx_bad_col_hi {
	uint64_t u;
	struct bdk_bgxx_smux_rx_bad_col_hi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t val                         : 1;  /**< R/W1C/H - Set when BGX()_SMU()_RX_INT[PCTERR] is set. */
		uint64_t state                       : 8;  /**< RO/H - When BGX()_SMU()_RX_INT[PCTERR] is set, contains the receive state at the time of
                                                                 the error. */
		uint64_t lane_rxc                    : 8;  /**< RO/H - When BGX()_SMU()_RX_INT[PCTERR] is set, contains the column at the time of the error. */
#else
		uint64_t lane_rxc                    : 8;
		uint64_t state                       : 8;
		uint64_t val                         : 1;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_bad_col_hi_s cn85xx; */
	/* struct bdk_bgxx_smux_rx_bad_col_hi_s cn88xx; */
	/* struct bdk_bgxx_smux_rx_bad_col_hi_s cn88xxp1; */
} bdk_bgxx_smux_rx_bad_col_hi_t;

static inline uint64_t BDK_BGXX_SMUX_RX_BAD_COL_HI(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_BAD_COL_HI(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020058ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_BAD_COL_HI", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_BAD_COL_HI(...) bdk_bgxx_smux_rx_bad_col_hi_t
#define bustype_BDK_BGXX_SMUX_RX_BAD_COL_HI(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_BAD_COL_HI(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_BAD_COL_HI(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_BAD_COL_HI(...) "BGXX_SMUX_RX_BAD_COL_HI"


/**
 * RSL - bgx#_smu#_rx_bad_col_lo
 */
typedef union bdk_bgxx_smux_rx_bad_col_lo {
	uint64_t u;
	struct bdk_bgxx_smux_rx_bad_col_lo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t lane_rxd                    : 64; /**< RO/H - When BGX()_SMU()_RX_INT[PCTERR] is set, LANE_RXD contains the XAUI/RXAUI column at
                                                                 the time of the error. */
#else
		uint64_t lane_rxd                    : 64;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_bad_col_lo_s cn85xx; */
	/* struct bdk_bgxx_smux_rx_bad_col_lo_s cn88xx; */
	/* struct bdk_bgxx_smux_rx_bad_col_lo_s cn88xxp1; */
} bdk_bgxx_smux_rx_bad_col_lo_t;

static inline uint64_t BDK_BGXX_SMUX_RX_BAD_COL_LO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_BAD_COL_LO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020050ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_BAD_COL_LO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_BAD_COL_LO(...) bdk_bgxx_smux_rx_bad_col_lo_t
#define bustype_BDK_BGXX_SMUX_RX_BAD_COL_LO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_BAD_COL_LO(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_BAD_COL_LO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_BAD_COL_LO(...) "BGXX_SMUX_RX_BAD_COL_LO"


/**
 * RSL - bgx#_smu#_rx_ctl
 */
typedef union bdk_bgxx_smux_rx_ctl {
	uint64_t u;
	struct bdk_bgxx_smux_rx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t status                      : 2;  /**< RO/H - Link status.
                                                                 0x0 = Link OK.
                                                                 0x1 = Local fault.
                                                                 0x2 = Remote fault.
                                                                 0x3 = Reserved. */
#else
		uint64_t status                      : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_ctl_s      cn85xx; */
	/* struct bdk_bgxx_smux_rx_ctl_s      cn88xx; */
	/* struct bdk_bgxx_smux_rx_ctl_s      cn88xxp1; */
} bdk_bgxx_smux_rx_ctl_t;

static inline uint64_t BDK_BGXX_SMUX_RX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020048ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_CTL(...) bdk_bgxx_smux_rx_ctl_t
#define bustype_BDK_BGXX_SMUX_RX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_CTL(...) "BGXX_SMUX_RX_CTL"


/**
 * RSL - bgx#_smu#_rx_decision
 *
 * This register specifies the byte count used to determine when to accept or to filter a packet.
 * As each byte in a packet is received by BGX, the L2 byte count (i.e. the number of bytes from
 * the beginning of the L2 header (DMAC)) is compared against CNT. In normal operation, the L2
 * header begins after the PREAMBLE + SFD (BGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 1) and any
 * optional UDD skip data (BGX()_SMU()_RX_UDD_SKP[LEN]).
 */
typedef union bdk_bgxx_smux_rx_decision {
	uint64_t u;
	struct bdk_bgxx_smux_rx_decision_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t cnt                         : 5;  /**< R/W - The byte count to decide when to accept or filter a packet. Refer to SMU Decisions. */
#else
		uint64_t cnt                         : 5;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_decision_s cn85xx; */
	/* struct bdk_bgxx_smux_rx_decision_s cn88xx; */
	/* struct bdk_bgxx_smux_rx_decision_s cn88xxp1; */
} bdk_bgxx_smux_rx_decision_t;

static inline uint64_t BDK_BGXX_SMUX_RX_DECISION(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_DECISION(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020038ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_DECISION", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_DECISION(...) bdk_bgxx_smux_rx_decision_t
#define bustype_BDK_BGXX_SMUX_RX_DECISION(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_DECISION(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_DECISION(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_DECISION(...) "BGXX_SMUX_RX_DECISION"


/**
 * RSL - bgx#_smu#_rx_frm_chk
 *
 * The CSRs provide the enable bits for a subset of errors passed to CMR encoded.
 *
 */
typedef union bdk_bgxx_smux_rx_frm_chk {
	uint64_t u;
	struct bdk_bgxx_smux_rx_frm_chk_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t skperr                      : 1;  /**< R/W - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W - Frame was received with data-reception error. */
		uint64_t reserved_6_6                : 1;
		uint64_t fcserr_c                    : 1;  /**< R/W - Control frame was received with FCS/CRC error. */
		uint64_t fcserr_d                    : 1;  /**< R/W - Data frame was received with FCS/CRC error. */
		uint64_t jabber                      : 1;  /**< R/W - Frame was received with length \> sys_length. */
		uint64_t reserved_0_2                : 3;
#else
		uint64_t reserved_0_2                : 3;
		uint64_t jabber                      : 1;
		uint64_t fcserr_d                    : 1;
		uint64_t fcserr_c                    : 1;
		uint64_t reserved_6_6                : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_frm_chk_s  cn85xx; */
	/* struct bdk_bgxx_smux_rx_frm_chk_s  cn88xx; */
	/* struct bdk_bgxx_smux_rx_frm_chk_s  cn88xxp1; */
} bdk_bgxx_smux_rx_frm_chk_t;

static inline uint64_t BDK_BGXX_SMUX_RX_FRM_CHK(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_FRM_CHK(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020028ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_FRM_CHK", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_FRM_CHK(...) bdk_bgxx_smux_rx_frm_chk_t
#define bustype_BDK_BGXX_SMUX_RX_FRM_CHK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_FRM_CHK(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_FRM_CHK(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_FRM_CHK(...) "BGXX_SMUX_RX_FRM_CHK"


/**
 * RSL - bgx#_smu#_rx_frm_ctl
 *
 * This register controls the handling of the frames.
 * The CTL_BCK/CTL_DRP bits control how the hardware handles incoming PAUSE packets. The most
 * common modes of operation:
 * _ CTL_BCK = 1, CTL_DRP = 1: hardware handles everything
 * _ CTL_BCK = 0, CTL_DRP = 0: software sees all PAUSE frames
 * _ CTL_BCK = 0, CTL_DRP = 1: all PAUSE frames are completely ignored
 *
 * These control bits should be set to CTL_BCK = 0, CTL_DRP = 0 in half-duplex mode. Since PAUSE
 * packets only apply to full duplex operation, any PAUSE packet would constitute an exception
 * which should be handled by the processing cores. PAUSE packets should not be forwarded.
 */
typedef union bdk_bgxx_smux_rx_frm_ctl {
	uint64_t u;
	struct bdk_bgxx_smux_rx_frm_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t ptp_mode                    : 1;  /**< R/W - Timestamp mode. When PTP_MODE is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the BGX()_SMU()_RX_JABBER,
                                                                 BGX()_SMU()_RX_DECISION, and BGX()_SMU()_RX_UDD_SKP do not require any
                                                                 adjustment as they operate on the received packet size. When the packet reaches NIC, its
                                                                 size reflects the additional bytes. */
		uint64_t reserved_6_11               : 6;
		uint64_t ctl_smac                    : 1;  /**< R/W - Control PAUSE frames can match station SMAC. */
		uint64_t ctl_mcst                    : 1;  /**< R/W - Control PAUSE frames can match globally assigned multicast address. */
		uint64_t ctl_bck                     : 1;  /**< R/W - Forward PAUSE information to TX block. */
		uint64_t ctl_drp                     : 1;  /**< R/W - Drop control PAUSE frames. */
		uint64_t pre_strp                    : 1;  /**< R/W - Strip off the preamble (when present).

                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If PTP_MODE = 1 and PRE_CHK = 1, PRE_STRP must be 1.

                                                                 When PRE_CHK is set (indicating that the PREAMBLE will be sent), PRE_STRP determines if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
		uint64_t pre_chk                     : 1;  /**< R/W - Check the preamble for correctness.
                                                                 This port is configured to send a valid 802.3 PREAMBLE to begin every frame. BGX checks
                                                                 that a valid PREAMBLE is received (based on PRE_FREE). When a problem does occur within
                                                                 the PREAMBLE sequence, the frame is marked as bad and not sent into the core. The
                                                                 BGX()_SMU()_RX_INT[PCTERR] interrupt is also raised.

                                                                 When BGX()_SMU()_TX_CTL[HG_EN] is set, PRE_CHK must be 0.

                                                                 If PTP_MODE = 1 and PRE_CHK = 1, PRE_STRP must be 1. */
#else
		uint64_t pre_chk                     : 1;
		uint64_t pre_strp                    : 1;
		uint64_t ctl_drp                     : 1;
		uint64_t ctl_bck                     : 1;
		uint64_t ctl_mcst                    : 1;
		uint64_t ctl_smac                    : 1;
		uint64_t reserved_6_11               : 6;
		uint64_t ptp_mode                    : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_frm_ctl_s  cn85xx; */
	/* struct bdk_bgxx_smux_rx_frm_ctl_s  cn88xx; */
	/* struct bdk_bgxx_smux_rx_frm_ctl_s  cn88xxp1; */
} bdk_bgxx_smux_rx_frm_ctl_t;

static inline uint64_t BDK_BGXX_SMUX_RX_FRM_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_FRM_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020020ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_FRM_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_FRM_CTL(...) bdk_bgxx_smux_rx_frm_ctl_t
#define bustype_BDK_BGXX_SMUX_RX_FRM_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_FRM_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_FRM_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_FRM_CTL(...) "BGXX_SMUX_RX_FRM_CTL"


/**
 * RSL - bgx#_smu#_rx_int
 *
 * SMU Interrupt Register.
 *
 */
typedef union bdk_bgxx_smux_rx_int {
	uint64_t u;
	struct bdk_bgxx_smux_rx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t hg2cc                       : 1;  /**< R/W1C/H - HiGig2 received message CRC or control-character error. Set when either a CRC8 error is
                                                                 detected, or when a control character is found in the message bytes after the K.SOM.
                                                                 HG2CC has higher priority than HG2FLD, which means that a HiGig2 message that results in
                                                                 HG2CC getting set never sets HG2FLD. */
		uint64_t hg2fld                      : 1;  /**< R/W1C/H - HiGig2 received message field error:

                                                                 MSG_TYPE field not 0x0, i.e. it is not a flow-control message, which is the only defined
                                                                 type for HiGig2.

                                                                 FWD_TYPE field not 0x0, i.e. it is not a link-level message, which is the only defined
                                                                 type for HiGig2.

                                                                 FC_OBJECT field is neither 0x0 for physical link, nor 0x2 for logical link. Those are the
                                                                 only two defined types in HiGig2 */
		uint64_t bad_term                    : 1;  /**< R/W1C/H - Frame is terminated by control character other than /T/. (XAUI/RXAUI mode only) The error
                                                                 propagation control character /E/ will be included as part of the frame and does not cause
                                                                 a frame termination. */
		uint64_t bad_seq                     : 1;  /**< R/W1C/H - Reserved sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rem_fault                   : 1;  /**< R/W1C/H - Remote-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t loc_fault                   : 1;  /**< R/W1C/H - Local-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcodes. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol. In XAUI/RXAUI mode, the column of data that was bad is logged in
                                                                 BGX()_SMU()_RX_BAD_COL_LO and BGX()_SMU()_RX_BAD_COL_HI.
                                                                 PCTERR checks that the frame begins with a valid
                                                                 PREAMBLE sequence. Does not check the number of PREAMBLE cycles. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - Frame was received with FCS/CRC error */
		uint64_t jabber                      : 1;  /**< R/W1C/H - Frame was received with length \> sys_length. An RX Jabber error indicates that a packet
                                                                 was received which is longer than the maximum allowed packet as defined by the system. BGX
                                                                 terminates the packet with an EOP on the beat on which JABBER was exceeded. The beat on
                                                                 which JABBER was exceeded is left unchanged and all subsequent data beats are dropped.
                                                                 Failure to truncate could lead to system instability. */
#else
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t loc_fault                   : 1;
		uint64_t rem_fault                   : 1;
		uint64_t bad_seq                     : 1;
		uint64_t bad_term                    : 1;
		uint64_t hg2fld                      : 1;
		uint64_t hg2cc                       : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_int_s      cn85xx; */
	/* struct bdk_bgxx_smux_rx_int_s      cn88xx; */
	/* struct bdk_bgxx_smux_rx_int_s      cn88xxp1; */
} bdk_bgxx_smux_rx_int_t;

static inline uint64_t BDK_BGXX_SMUX_RX_INT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_INT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_INT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_INT(...) bdk_bgxx_smux_rx_int_t
#define bustype_BDK_BGXX_SMUX_RX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_INT(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_INT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_INT(...) "BGXX_SMUX_RX_INT"


/**
 * RSL - bgx#_smu#_rx_int_ena_w1c
 */
typedef union bdk_bgxx_smux_rx_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_smux_rx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t hg2cc                       : 1;  /**< R/W1C/H - HiGig2 received message CRC or control-character error. Set when either a CRC8 error is
                                                                 detected, or when a control character is found in the message bytes after the K.SOM.
                                                                 HG2CC has higher priority than HG2FLD, which means that a HiGig2 message that results in
                                                                 HG2CC getting set never sets HG2FLD. */
		uint64_t hg2fld                      : 1;  /**< R/W1C/H - HiGig2 received message field error:

                                                                 MSG_TYPE field not 0x0, i.e. it is not a flow-control message, which is the only defined
                                                                 type for HiGig2.

                                                                 FWD_TYPE field not 0x0, i.e. it is not a link-level message, which is the only defined
                                                                 type for HiGig2.

                                                                 FC_OBJECT field is neither 0x0 for physical link, nor 0x2 for logical link. Those are the
                                                                 only two defined types in HiGig2 */
		uint64_t bad_term                    : 1;  /**< R/W1C/H - Frame is terminated by control character other than /T/. (XAUI/RXAUI mode only) The error
                                                                 propagation control character /E/ will be included as part of the frame and does not cause
                                                                 a frame termination. */
		uint64_t bad_seq                     : 1;  /**< R/W1C/H - Reserved sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rem_fault                   : 1;  /**< R/W1C/H - Remote-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t loc_fault                   : 1;  /**< R/W1C/H - Local-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcodes. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol. In XAUI/RXAUI mode, the column of data that was bad is logged in
                                                                 BGX()_SMU()_RX_BAD_COL_LO and BGX()_SMU()_RX_BAD_COL_HI.
                                                                 PCTERR checks that the frame begins with a valid
                                                                 PREAMBLE sequence. Does not check the number of PREAMBLE cycles. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - Frame was received with FCS/CRC error */
		uint64_t jabber                      : 1;  /**< R/W1C/H - Frame was received with length \> sys_length. An RX Jabber error indicates that a packet
                                                                 was received which is longer than the maximum allowed packet as defined by the system. BGX
                                                                 terminates the packet with an EOP on the beat on which JABBER was exceeded. The beat on
                                                                 which JABBER was exceeded is left unchanged and all subsequent data beats are dropped.
                                                                 Failure to truncate could lead to system instability. */
#else
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t loc_fault                   : 1;
		uint64_t rem_fault                   : 1;
		uint64_t bad_seq                     : 1;
		uint64_t bad_term                    : 1;
		uint64_t hg2fld                      : 1;
		uint64_t hg2cc                       : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_smux_rx_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_smux_rx_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_smux_rx_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_SMUX_RX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020010ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_INT_ENA_W1C(...) bdk_bgxx_smux_rx_int_ena_w1c_t
#define bustype_BDK_BGXX_SMUX_RX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_INT_ENA_W1C(...) "BGXX_SMUX_RX_INT_ENA_W1C"


/**
 * RSL - bgx#_smu#_rx_int_ena_w1s
 */
typedef union bdk_bgxx_smux_rx_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_smux_rx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t hg2cc                       : 1;  /**< R/W1C/H - HiGig2 received message CRC or control-character error. Set when either a CRC8 error is
                                                                 detected, or when a control character is found in the message bytes after the K.SOM.
                                                                 HG2CC has higher priority than HG2FLD, which means that a HiGig2 message that results in
                                                                 HG2CC getting set never sets HG2FLD. */
		uint64_t hg2fld                      : 1;  /**< R/W1C/H - HiGig2 received message field error:

                                                                 MSG_TYPE field not 0x0, i.e. it is not a flow-control message, which is the only defined
                                                                 type for HiGig2.

                                                                 FWD_TYPE field not 0x0, i.e. it is not a link-level message, which is the only defined
                                                                 type for HiGig2.

                                                                 FC_OBJECT field is neither 0x0 for physical link, nor 0x2 for logical link. Those are the
                                                                 only two defined types in HiGig2 */
		uint64_t bad_term                    : 1;  /**< R/W1C/H - Frame is terminated by control character other than /T/. (XAUI/RXAUI mode only) The error
                                                                 propagation control character /E/ will be included as part of the frame and does not cause
                                                                 a frame termination. */
		uint64_t bad_seq                     : 1;  /**< R/W1C/H - Reserved sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rem_fault                   : 1;  /**< R/W1C/H - Remote-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t loc_fault                   : 1;  /**< R/W1C/H - Local-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcodes. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol. In XAUI/RXAUI mode, the column of data that was bad is logged in
                                                                 BGX()_SMU()_RX_BAD_COL_LO and BGX()_SMU()_RX_BAD_COL_HI.
                                                                 PCTERR checks that the frame begins with a valid
                                                                 PREAMBLE sequence. Does not check the number of PREAMBLE cycles. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - Frame was received with FCS/CRC error */
		uint64_t jabber                      : 1;  /**< R/W1C/H - Frame was received with length \> sys_length. An RX Jabber error indicates that a packet
                                                                 was received which is longer than the maximum allowed packet as defined by the system. BGX
                                                                 terminates the packet with an EOP on the beat on which JABBER was exceeded. The beat on
                                                                 which JABBER was exceeded is left unchanged and all subsequent data beats are dropped.
                                                                 Failure to truncate could lead to system instability. */
#else
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t loc_fault                   : 1;
		uint64_t rem_fault                   : 1;
		uint64_t bad_seq                     : 1;
		uint64_t bad_term                    : 1;
		uint64_t hg2fld                      : 1;
		uint64_t hg2cc                       : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_smux_rx_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_smux_rx_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_smux_rx_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_SMUX_RX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020018ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_INT_ENA_W1S(...) bdk_bgxx_smux_rx_int_ena_w1s_t
#define bustype_BDK_BGXX_SMUX_RX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_INT_ENA_W1S(...) "BGXX_SMUX_RX_INT_ENA_W1S"


/**
 * RSL - bgx#_smu#_rx_int_w1s
 */
typedef union bdk_bgxx_smux_rx_int_w1s {
	uint64_t u;
	struct bdk_bgxx_smux_rx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t hg2cc                       : 1;  /**< R/W1C/H - HiGig2 received message CRC or control-character error. Set when either a CRC8 error is
                                                                 detected, or when a control character is found in the message bytes after the K.SOM.
                                                                 HG2CC has higher priority than HG2FLD, which means that a HiGig2 message that results in
                                                                 HG2CC getting set never sets HG2FLD. */
		uint64_t hg2fld                      : 1;  /**< R/W1C/H - HiGig2 received message field error:

                                                                 MSG_TYPE field not 0x0, i.e. it is not a flow-control message, which is the only defined
                                                                 type for HiGig2.

                                                                 FWD_TYPE field not 0x0, i.e. it is not a link-level message, which is the only defined
                                                                 type for HiGig2.

                                                                 FC_OBJECT field is neither 0x0 for physical link, nor 0x2 for logical link. Those are the
                                                                 only two defined types in HiGig2 */
		uint64_t bad_term                    : 1;  /**< R/W1C/H - Frame is terminated by control character other than /T/. (XAUI/RXAUI mode only) The error
                                                                 propagation control character /E/ will be included as part of the frame and does not cause
                                                                 a frame termination. */
		uint64_t bad_seq                     : 1;  /**< R/W1C/H - Reserved sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rem_fault                   : 1;  /**< R/W1C/H - Remote-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t loc_fault                   : 1;  /**< R/W1C/H - Local-fault sequence detected. (XAUI/RXAUI mode only) */
		uint64_t rsverr                      : 1;  /**< R/W1C/H - Reserved opcodes. */
		uint64_t pcterr                      : 1;  /**< R/W1C/H - Bad preamble/protocol. In XAUI/RXAUI mode, the column of data that was bad is logged in
                                                                 BGX()_SMU()_RX_BAD_COL_LO and BGX()_SMU()_RX_BAD_COL_HI.
                                                                 PCTERR checks that the frame begins with a valid
                                                                 PREAMBLE sequence. Does not check the number of PREAMBLE cycles. */
		uint64_t skperr                      : 1;  /**< R/W1C/H - Skipper error. */
		uint64_t rcverr                      : 1;  /**< R/W1C/H - Frame was received with data-reception error. */
		uint64_t fcserr                      : 1;  /**< R/W1C/H - Frame was received with FCS/CRC error */
		uint64_t jabber                      : 1;  /**< R/W1C/H - Frame was received with length \> sys_length. An RX Jabber error indicates that a packet
                                                                 was received which is longer than the maximum allowed packet as defined by the system. BGX
                                                                 terminates the packet with an EOP on the beat on which JABBER was exceeded. The beat on
                                                                 which JABBER was exceeded is left unchanged and all subsequent data beats are dropped.
                                                                 Failure to truncate could lead to system instability. */
#else
		uint64_t jabber                      : 1;
		uint64_t fcserr                      : 1;
		uint64_t rcverr                      : 1;
		uint64_t skperr                      : 1;
		uint64_t pcterr                      : 1;
		uint64_t rsverr                      : 1;
		uint64_t loc_fault                   : 1;
		uint64_t rem_fault                   : 1;
		uint64_t bad_seq                     : 1;
		uint64_t bad_term                    : 1;
		uint64_t hg2fld                      : 1;
		uint64_t hg2cc                       : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_int_w1s_s  cn85xx; */
	/* struct bdk_bgxx_smux_rx_int_w1s_s  cn88xx; */
	/* struct bdk_bgxx_smux_rx_int_w1s_s  cn88xxp1; */
} bdk_bgxx_smux_rx_int_w1s_t;

static inline uint64_t BDK_BGXX_SMUX_RX_INT_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_INT_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020008ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_INT_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_INT_W1S(...) bdk_bgxx_smux_rx_int_w1s_t
#define bustype_BDK_BGXX_SMUX_RX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_INT_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_INT_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_INT_W1S(...) "BGXX_SMUX_RX_INT_W1S"


/**
 * RSL - bgx#_smu#_rx_jabber
 *
 * This register specifies the maximum size for packets, beyond which the SMU truncates. In
 * XAUI/RXAUI mode, port 0 is used for checking.
 *
 * INTERNAL:
 * The packet that will be sent to the packet input logic will have an
 * additionl 8 bytes if BGX()_SMU()_RX_FRM_CTL[PRE_CHK] is set and
 * BGX()_SMU()_RX_FRM_CTL[PRE_STRP] is clear.  The max packet that will be sent is
 * defined as:
 *
 * _ max_sized_packet = BGX()_SMU()_RX_JABBER[CNT]+((BGX()_SMU()_RX_FRM_CTL[PRE_CHK] &
 * !BGX()_SMU()_RX_FRM_CTL[PRE_STRP])*8)
 */
typedef union bdk_bgxx_smux_rx_jabber {
	uint64_t u;
	struct bdk_bgxx_smux_rx_jabber_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t cnt                         : 16; /**< R/W - Byte count for jabber check. Failing packets set the JABBER interrupt and are optionally
                                                                 sent with opcode = JABBER. BGX truncates the packet to CNT+1 to CNT+8 bytes.
                                                                 CNT must be 8-byte aligned such that CNT[2:0] = 000. */
#else
		uint64_t cnt                         : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_jabber_s   cn85xx; */
	/* struct bdk_bgxx_smux_rx_jabber_s   cn88xx; */
	/* struct bdk_bgxx_smux_rx_jabber_s   cn88xxp1; */
} bdk_bgxx_smux_rx_jabber_t;

static inline uint64_t BDK_BGXX_SMUX_RX_JABBER(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_JABBER(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020030ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_JABBER", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_JABBER(...) bdk_bgxx_smux_rx_jabber_t
#define bustype_BDK_BGXX_SMUX_RX_JABBER(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_JABBER(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_JABBER(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_JABBER(...) "BGXX_SMUX_RX_JABBER"


/**
 * RSL - bgx#_smu#_rx_udd_skp
 */
typedef union bdk_bgxx_smux_rx_udd_skp {
	uint64_t u;
	struct bdk_bgxx_smux_rx_udd_skp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t fcssel                      : 1;  /**< R/W - Include the skip bytes in the FCS calculation.
                                                                 0 = All skip bytes are included in FCS.
                                                                 1 = The skip bytes are not included in FCS.

                                                                 When BGX()_SMU()_TX_CTL[HG_EN] is set, this field must be 0.
                                                                 The skip bytes are part of the packet and are sent through the NCB packet interface and
                                                                 are handled by NIC. The system can determine if the UDD bytes are included in the FCS
                                                                 check by using the FCSSEL field, if the FCS check is enabled. */
		uint64_t reserved_7_7                : 1;
		uint64_t len                         : 7;  /**< R/W - Amount of user-defined data before the start of the L2C data, in bytes.
                                                                 Setting to 0 means L2C comes first; maximum value is 64.
                                                                 LEN must be 0x0 in half-duplex operation.

                                                                 When BGX()_SMU()_TX_CTL[HG_EN] is set, this field must be set to 12 or 16
                                                                 (depending on HiGig header size) to account for the HiGig header.
                                                                 LEN = 12 selects HiGig/HiGig+; LEN = 16 selects HiGig2. */
#else
		uint64_t len                         : 7;
		uint64_t reserved_7_7                : 1;
		uint64_t fcssel                      : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_bgxx_smux_rx_udd_skp_s  cn85xx; */
	/* struct bdk_bgxx_smux_rx_udd_skp_s  cn88xx; */
	/* struct bdk_bgxx_smux_rx_udd_skp_s  cn88xxp1; */
} bdk_bgxx_smux_rx_udd_skp_t;

static inline uint64_t BDK_BGXX_SMUX_RX_UDD_SKP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_RX_UDD_SKP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020040ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_RX_UDD_SKP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_RX_UDD_SKP(...) bdk_bgxx_smux_rx_udd_skp_t
#define bustype_BDK_BGXX_SMUX_RX_UDD_SKP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_RX_UDD_SKP(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_RX_UDD_SKP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_RX_UDD_SKP(...) "BGXX_SMUX_RX_UDD_SKP"


/**
 * RSL - bgx#_smu#_smac
 */
typedef union bdk_bgxx_smux_smac {
	uint64_t u;
	struct bdk_bgxx_smux_smac_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t smac                        : 48; /**< R/W - The SMAC field is used for generating and accepting control PAUSE packets. */
#else
		uint64_t smac                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_smux_smac_s        cn85xx; */
	/* struct bdk_bgxx_smux_smac_s        cn88xx; */
	/* struct bdk_bgxx_smux_smac_s        cn88xxp1; */
} bdk_bgxx_smux_smac_t;

static inline uint64_t BDK_BGXX_SMUX_SMAC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_SMAC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020108ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_SMAC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_SMAC(...) bdk_bgxx_smux_smac_t
#define bustype_BDK_BGXX_SMUX_SMAC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_SMAC(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_SMAC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_SMAC(...) "BGXX_SMUX_SMAC"


/**
 * RSL - bgx#_smu#_tx_append
 *
 * For more details on the interactions between FCS and PAD, see also the description of
 * BGX()_SMU()_TX_MIN_PKT[MIN_SIZE].
 */
typedef union bdk_bgxx_smux_tx_append {
	uint64_t u;
	struct bdk_bgxx_smux_tx_append_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t fcs_c                       : 1;  /**< R/W - Append the Ethernet FCS on each PAUSE packet. PAUSE packets are normally padded to 60
                                                                 bytes. If BGX()_SMU()_TX_MIN_PKT[MIN_SIZE] exceeds 59, then FCS_C is not used. */
		uint64_t fcs_d                       : 1;  /**< R/W - Append the Ethernet FCS on each data packet. */
		uint64_t pad                         : 1;  /**< R/W - Append PAD bytes such that minimum-sized packet is transmitted. */
		uint64_t preamble                    : 1;  /**< R/W - Prepend the Ethernet preamble on each transfer. When BGX()_SMU()_TX_CTL[HG_EN] is
                                                                 set, PREAMBLE must be 0. */
#else
		uint64_t preamble                    : 1;
		uint64_t pad                         : 1;
		uint64_t fcs_d                       : 1;
		uint64_t fcs_c                       : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_append_s   cn85xx; */
	/* struct bdk_bgxx_smux_tx_append_s   cn88xx; */
	/* struct bdk_bgxx_smux_tx_append_s   cn88xxp1; */
} bdk_bgxx_smux_tx_append_t;

static inline uint64_t BDK_BGXX_SMUX_TX_APPEND(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_APPEND(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020100ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_APPEND", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_APPEND(...) bdk_bgxx_smux_tx_append_t
#define bustype_BDK_BGXX_SMUX_TX_APPEND(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_APPEND(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_APPEND(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_APPEND(...) "BGXX_SMUX_TX_APPEND"


/**
 * RSL - bgx#_smu#_tx_ctl
 */
typedef union bdk_bgxx_smux_tx_ctl {
	uint64_t u;
	struct bdk_bgxx_smux_tx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_31_63              : 33;
		uint64_t spu_mrk_cnt                 : 20; /**< R/W - 40GBASE-R transmit marker interval count. Specifies the interval (number of 66-bit BASE-R
                                                                 blocks) at which the LMAC transmit logic inserts 40GBASE-R alignment markers. An internal
                                                                 counter in SMU is initialized to this value, counts down for each BASE-R block transmitted
                                                                 by the LMAC, and wraps back to the initial value from 0. The LMAC transmit logic inserts
                                                                 alignment markers for lanes 0, 1, 2 and 3, respectively, in the last four BASE-R blocks
                                                                 before the counter wraps (3, 2, 1, 0). The default value corresponds to an alignment
                                                                 marker period of 16363 blocks (exclusive) per lane, as specified in 802.3ba-2010. The
                                                                 default value should always be used for normal operation. */
		uint64_t hg_pause_hgi                : 2;  /**< R/W - HGI field for hardware-generated HiGig PAUSE packets. */
		uint64_t hg_en                       : 1;  /**< R/W - Enable HiGig mode.
                                                                 When this field is set and BGX()_SMU()_RX_UDD_SKP[LEN] = 12, the interface is in
                                                                 HiGig/HiGig+ mode and the following must be set:
                                                                 * BGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 0.
                                                                 * BGX()_SMU()_RX_UDD_SKP[FCSSEL] = 0.
                                                                 * BGX()_SMU()_RX_UDD_SKP[LEN] = 12.
                                                                 * BGX()_SMU()_TX_APPEND[PREAMBLE] = 0.

                                                                 When this field is set and BGX()_SMU()_RX_UDD_SKP[LEN] = 16, the interface is in
                                                                 HiGig2 mode and the following must be set:
                                                                 * BGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 0.
                                                                 * BGX()_SMU()_RX_UDD_SKP[FCSSEL] = 0.
                                                                 * BGX()_SMU()_RX_UDD_SKP[LEN] = 16.
                                                                 * BGX()_SMU()_TX_APPEND[PREAMBLE] = 0.
                                                                 * BGX()_SMU()_CBFC_CTL[RX_EN] = 0.
                                                                 * BGX()_SMU()_CBFC_CTL[TX_EN] = 0. */
		uint64_t l2p_bp_conv                 : 1;  /**< R/W - If set, causes TX to generate 802.3 pause packets when CMR applies logical backpressure
                                                                 (XOFF), if and only if BGX()_SMU()_CBFC_CTL[TX_EN] is clear and
                                                                 BGX()_SMU()_HG2_CONTROL[HG2TX_EN] is clear. */
		uint64_t ls_byp                      : 1;  /**< R/W - Bypass the link status, as determined by the XGMII receiver, and set the link status of
                                                                 the transmitter to LS. */
		uint64_t ls                          : 2;  /**< R/W - Link status.
                                                                 0 = Link OK; link runs normally. RS passes MAC data to PCS.
                                                                 1 = Local fault. RS layer sends continuous remote fault sequences.
                                                                 2 = Remote fault. RS layer sends continuous idle sequences.
                                                                 3 = Link drain. RS layer drops full packets to allow BGX and PKO to drain their FIFOs. */
		uint64_t reserved_2_3                : 2;
		uint64_t uni_en                      : 1;  /**< R/W - Enable unidirectional mode (IEEE Clause 66). */
		uint64_t dic_en                      : 1;  /**< R/W - Enable the deficit idle counter for IFG averaging. */
#else
		uint64_t dic_en                      : 1;
		uint64_t uni_en                      : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t ls                          : 2;
		uint64_t ls_byp                      : 1;
		uint64_t l2p_bp_conv                 : 1;
		uint64_t hg_en                       : 1;
		uint64_t hg_pause_hgi                : 2;
		uint64_t spu_mrk_cnt                 : 20;
		uint64_t reserved_31_63              : 33;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_ctl_s      cn85xx; */
	/* struct bdk_bgxx_smux_tx_ctl_s      cn88xx; */
	/* struct bdk_bgxx_smux_tx_ctl_s      cn88xxp1; */
} bdk_bgxx_smux_tx_ctl_t;

static inline uint64_t BDK_BGXX_SMUX_TX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020178ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_CTL(...) bdk_bgxx_smux_tx_ctl_t
#define bustype_BDK_BGXX_SMUX_TX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_CTL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_CTL(...) "BGXX_SMUX_TX_CTL"


/**
 * RSL - bgx#_smu#_tx_ifg
 *
 * Programming IFG1 and IFG2:
 * * For XAUI/RXAUI/10Gbs/40Gbs systems that require IEEE 802.3 compatibility, the IFG1+IFG2 sum
 * must be 12.
 * * In loopback mode, the IFG1+IFG2 of local and remote parties must match exactly; otherwise
 * one of the two sides' loopback FIFO will overrun: BGX()_SMU()_TX_INT[LB_OVRFLW].
 */
typedef union bdk_bgxx_smux_tx_ifg {
	uint64_t u;
	struct bdk_bgxx_smux_tx_ifg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t ifg2                        : 4;  /**< R/W - 1/2 of the interframe gap timing (in IFG2*8 bits). */
		uint64_t ifg1                        : 4;  /**< R/W - 1/2 of the interframe gap timing (in IFG1*8 bits). */
#else
		uint64_t ifg1                        : 4;
		uint64_t ifg2                        : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_ifg_s      cn85xx; */
	/* struct bdk_bgxx_smux_tx_ifg_s      cn88xx; */
	/* struct bdk_bgxx_smux_tx_ifg_s      cn88xxp1; */
} bdk_bgxx_smux_tx_ifg_t;

static inline uint64_t BDK_BGXX_SMUX_TX_IFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_IFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020160ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_IFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_IFG(...) bdk_bgxx_smux_tx_ifg_t
#define bustype_BDK_BGXX_SMUX_TX_IFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_IFG(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_IFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_IFG(...) "BGXX_SMUX_TX_IFG"


/**
 * RSL - bgx#_smu#_tx_int
 */
typedef union bdk_bgxx_smux_tx_int {
	uint64_t u;
	struct bdk_bgxx_smux_tx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t lb_ovrflw                   : 1;  /**< R/W1C/H - TX loopback overflow. */
		uint64_t lb_undflw                   : 1;  /**< R/W1C/H - TX loopback underflow. */
		uint64_t fake_commit                 : 1;  /**< R/W1C/H - TX SMU started a packet with PTP on SOP and has not seen a commit for it from TX SPU after
                                                                 2^SMU_TX_PTP_TIMEOUT_WIDTH (2^8) cycles so it faked a commit to CMR. */
		uint64_t xchange                     : 1;  /**< R/W1C/H - Link status changed. This denotes a change to BGX()_SMU()_RX_CTL[STATUS]. */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xchange                     : 1;
		uint64_t fake_commit                 : 1;
		uint64_t lb_undflw                   : 1;
		uint64_t lb_ovrflw                   : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_int_s      cn85xx; */
	/* struct bdk_bgxx_smux_tx_int_s      cn88xx; */
	/* struct bdk_bgxx_smux_tx_int_s      cn88xxp1; */
} bdk_bgxx_smux_tx_int_t;

static inline uint64_t BDK_BGXX_SMUX_TX_INT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_INT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020140ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_INT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_INT(...) bdk_bgxx_smux_tx_int_t
#define bustype_BDK_BGXX_SMUX_TX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_INT(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_INT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_INT(...) "BGXX_SMUX_TX_INT"


/**
 * RSL - bgx#_smu#_tx_int_ena_w1c
 */
typedef union bdk_bgxx_smux_tx_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_smux_tx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t lb_ovrflw                   : 1;  /**< R/W1C/H - TX loopback overflow. */
		uint64_t lb_undflw                   : 1;  /**< R/W1C/H - TX loopback underflow. */
		uint64_t fake_commit                 : 1;  /**< R/W1C/H - TX SMU started a packet with PTP on SOP and has not seen a commit for it from TX SPU after
                                                                 2^SMU_TX_PTP_TIMEOUT_WIDTH (2^8) cycles so it faked a commit to CMR. */
		uint64_t xchange                     : 1;  /**< R/W1C/H - Link status changed. This denotes a change to BGX()_SMU()_RX_CTL[STATUS]. */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xchange                     : 1;
		uint64_t fake_commit                 : 1;
		uint64_t lb_undflw                   : 1;
		uint64_t lb_ovrflw                   : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_smux_tx_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_SMUX_TX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020150ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_INT_ENA_W1C(...) bdk_bgxx_smux_tx_int_ena_w1c_t
#define bustype_BDK_BGXX_SMUX_TX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_INT_ENA_W1C(...) "BGXX_SMUX_TX_INT_ENA_W1C"


/**
 * RSL - bgx#_smu#_tx_int_ena_w1s
 */
typedef union bdk_bgxx_smux_tx_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_smux_tx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t lb_ovrflw                   : 1;  /**< R/W1C/H - TX loopback overflow. */
		uint64_t lb_undflw                   : 1;  /**< R/W1C/H - TX loopback underflow. */
		uint64_t fake_commit                 : 1;  /**< R/W1C/H - TX SMU started a packet with PTP on SOP and has not seen a commit for it from TX SPU after
                                                                 2^SMU_TX_PTP_TIMEOUT_WIDTH (2^8) cycles so it faked a commit to CMR. */
		uint64_t xchange                     : 1;  /**< R/W1C/H - Link status changed. This denotes a change to BGX()_SMU()_RX_CTL[STATUS]. */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xchange                     : 1;
		uint64_t fake_commit                 : 1;
		uint64_t lb_undflw                   : 1;
		uint64_t lb_ovrflw                   : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_smux_tx_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_SMUX_TX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020158ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_INT_ENA_W1S(...) bdk_bgxx_smux_tx_int_ena_w1s_t
#define bustype_BDK_BGXX_SMUX_TX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_INT_ENA_W1S(...) "BGXX_SMUX_TX_INT_ENA_W1S"


/**
 * RSL - bgx#_smu#_tx_int_w1s
 */
typedef union bdk_bgxx_smux_tx_int_w1s {
	uint64_t u;
	struct bdk_bgxx_smux_tx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t lb_ovrflw                   : 1;  /**< R/W1C/H - TX loopback overflow. */
		uint64_t lb_undflw                   : 1;  /**< R/W1C/H - TX loopback underflow. */
		uint64_t fake_commit                 : 1;  /**< R/W1C/H - TX SMU started a packet with PTP on SOP and has not seen a commit for it from TX SPU after
                                                                 2^SMU_TX_PTP_TIMEOUT_WIDTH (2^8) cycles so it faked a commit to CMR. */
		uint64_t xchange                     : 1;  /**< R/W1C/H - Link status changed. This denotes a change to BGX()_SMU()_RX_CTL[STATUS]. */
		uint64_t undflw                      : 1;  /**< R/W1C/H - TX underflow. */
#else
		uint64_t undflw                      : 1;
		uint64_t xchange                     : 1;
		uint64_t fake_commit                 : 1;
		uint64_t lb_undflw                   : 1;
		uint64_t lb_ovrflw                   : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_int_w1s_s  cn85xx; */
	/* struct bdk_bgxx_smux_tx_int_w1s_s  cn88xx; */
	/* struct bdk_bgxx_smux_tx_int_w1s_s  cn88xxp1; */
} bdk_bgxx_smux_tx_int_w1s_t;

static inline uint64_t BDK_BGXX_SMUX_TX_INT_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_INT_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020148ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_INT_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_INT_W1S(...) bdk_bgxx_smux_tx_int_w1s_t
#define bustype_BDK_BGXX_SMUX_TX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_INT_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_INT_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_INT_W1S(...) "BGXX_SMUX_TX_INT_W1S"


/**
 * RSL - bgx#_smu#_tx_min_pkt
 */
typedef union bdk_bgxx_smux_tx_min_pkt {
	uint64_t u;
	struct bdk_bgxx_smux_tx_min_pkt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t min_size                    : 8;  /**< R/W - Min frame in bytes inclusive of FCS, if applied. Padding is only appended when
                                                                 BGX()_SMU()_TX_APPEND[PAD] for the corresponding port is set. When FCS is added to
                                                                 a packet which was padded, the FCS always appears in the 4 octets preceding /T/ or /E/. */
#else
		uint64_t min_size                    : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_min_pkt_s  cn85xx; */
	/* struct bdk_bgxx_smux_tx_min_pkt_s  cn88xx; */
	/* struct bdk_bgxx_smux_tx_min_pkt_s  cn88xxp1; */
} bdk_bgxx_smux_tx_min_pkt_t;

static inline uint64_t BDK_BGXX_SMUX_TX_MIN_PKT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_MIN_PKT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020118ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_MIN_PKT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_MIN_PKT(...) bdk_bgxx_smux_tx_min_pkt_t
#define bustype_BDK_BGXX_SMUX_TX_MIN_PKT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_MIN_PKT(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_MIN_PKT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_MIN_PKT(...) "BGXX_SMUX_TX_MIN_PKT"


/**
 * RSL - bgx#_smu#_tx_pause_pkt_dmac
 *
 * This register provides the DMAC value that is placed in outbound PAUSE packets.
 *
 */
typedef union bdk_bgxx_smux_tx_pause_pkt_dmac {
	uint64_t u;
	struct bdk_bgxx_smux_tx_pause_pkt_dmac_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t dmac                        : 48; /**< R/W - The DMAC field that is placed in outbound PAUSE packets. */
#else
		uint64_t dmac                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_pause_pkt_dmac_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_dmac_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_dmac_s cn88xxp1; */
} bdk_bgxx_smux_tx_pause_pkt_dmac_t;

static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020168ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(...) bdk_bgxx_smux_tx_pause_pkt_dmac_t
#define bustype_BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_PAUSE_PKT_DMAC(...) "BGXX_SMUX_TX_PAUSE_PKT_DMAC"


/**
 * RSL - bgx#_smu#_tx_pause_pkt_interval
 *
 * This register specifies how often PAUSE packets are sent.
 *
 */
typedef union bdk_bgxx_smux_tx_pause_pkt_interval {
	uint64_t u;
	struct bdk_bgxx_smux_tx_pause_pkt_interval_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t hg2_intra_en                : 1;  /**< R/W - Allow intrapacket HiGig2 message generation. Relevant only if HiGig2 message generation is enabled. */
		uint64_t hg2_intra_interval          : 16; /**< R/W - Arbitrate for a HiGig2 message, every (INTERVAL*512) bit-times whilst sending regular
                                                                 packet data. Relevant only if HiGig2 message generation and HG2_INTRA_EN are both set.
                                                                 Normally, 0 \< INTERVAL \< BGX()_SMU()_TX_PAUSE_PKT_TIME.

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
		uint64_t interval                    : 16; /**< R/W - Arbitrate for a 802.3 PAUSE packet, HiGig2 message, or PFC/CBFC PAUSE packet every
                                                                 (INTERVAL * 512) bit-times.
                                                                 Normally, 0 \< INTERVAL \< BGX()_SMU()_TX_PAUSE_PKT_TIME[PTIME].

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
#else
		uint64_t interval                    : 16;
		uint64_t hg2_intra_interval          : 16;
		uint64_t hg2_intra_en                : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_pause_pkt_interval_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_interval_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_interval_s cn88xxp1; */
} bdk_bgxx_smux_tx_pause_pkt_interval_t;

static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020120ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(...) bdk_bgxx_smux_tx_pause_pkt_interval_t
#define bustype_BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_PAUSE_PKT_INTERVAL(...) "BGXX_SMUX_TX_PAUSE_PKT_INTERVAL"


/**
 * RSL - bgx#_smu#_tx_pause_pkt_time
 */
typedef union bdk_bgxx_smux_tx_pause_pkt_time {
	uint64_t u;
	struct bdk_bgxx_smux_tx_pause_pkt_time_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t p_time                      : 16; /**< R/W - Provides the pause_time field placed in outbound 802.3 PAUSE packets, HiGig2 messages, or
                                                                 PFC/CBFC PAUSE packets in 512 bit-times. Normally, P_TIME \>
                                                                 BGX()_SMU()_TX_PAUSE_PKT_INTERVAL[INTERVAL]. See programming notes in
                                                                 BGX()_SMU()_TX_PAUSE_PKT_INTERVAL. */
#else
		uint64_t p_time                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_pause_pkt_time_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_time_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_time_s cn88xxp1; */
} bdk_bgxx_smux_tx_pause_pkt_time_t;

static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020110ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(...) bdk_bgxx_smux_tx_pause_pkt_time_t
#define bustype_BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_PAUSE_PKT_TIME(...) "BGXX_SMUX_TX_PAUSE_PKT_TIME"


/**
 * RSL - bgx#_smu#_tx_pause_pkt_type
 *
 * This register provides the P_TYPE field that is placed in outbound PAUSE packets.
 *
 */
typedef union bdk_bgxx_smux_tx_pause_pkt_type {
	uint64_t u;
	struct bdk_bgxx_smux_tx_pause_pkt_type_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t p_type                      : 16; /**< R/W - The P_TYPE field that is placed in outbound PAUSE packets. */
#else
		uint64_t p_type                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_pause_pkt_type_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_type_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_pause_pkt_type_s cn88xxp1; */
} bdk_bgxx_smux_tx_pause_pkt_type_t;

static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020170ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(...) bdk_bgxx_smux_tx_pause_pkt_type_t
#define bustype_BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_PAUSE_PKT_TYPE(...) "BGXX_SMUX_TX_PAUSE_PKT_TYPE"


/**
 * RSL - bgx#_smu#_tx_pause_togo
 */
typedef union bdk_bgxx_smux_tx_pause_togo {
	uint64_t u;
	struct bdk_bgxx_smux_tx_pause_togo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t msg_time                    : 16; /**< RO/H - Amount of time remaining to backpressure, from the HiGig2 physical message PAUSE timer
                                                                 (only valid on port0). */
		uint64_t p_time                      : 16; /**< RO/H - Amount of time remaining to backpressure, from the standard 802.3 PAUSE timer. */
#else
		uint64_t p_time                      : 16;
		uint64_t msg_time                    : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_pause_togo_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_pause_togo_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_pause_togo_s cn88xxp1; */
} bdk_bgxx_smux_tx_pause_togo_t;

static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_TOGO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_TOGO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020130ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_PAUSE_TOGO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_PAUSE_TOGO(...) bdk_bgxx_smux_tx_pause_togo_t
#define bustype_BDK_BGXX_SMUX_TX_PAUSE_TOGO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_PAUSE_TOGO(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_PAUSE_TOGO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_PAUSE_TOGO(...) "BGXX_SMUX_TX_PAUSE_TOGO"


/**
 * RSL - bgx#_smu#_tx_pause_zero
 */
typedef union bdk_bgxx_smux_tx_pause_zero {
	uint64_t u;
	struct bdk_bgxx_smux_tx_pause_zero_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t send                        : 1;  /**< R/W - Send PAUSE-zero enable. When this bit is set, and the backpressure condition is clear, it
                                                                 allows sending a PAUSE packet with pause_time of 0 to enable the channel. */
#else
		uint64_t send                        : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_pause_zero_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_pause_zero_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_pause_zero_s cn88xxp1; */
} bdk_bgxx_smux_tx_pause_zero_t;

static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_ZERO(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_PAUSE_ZERO(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020138ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_PAUSE_ZERO", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_PAUSE_ZERO(...) bdk_bgxx_smux_tx_pause_zero_t
#define bustype_BDK_BGXX_SMUX_TX_PAUSE_ZERO(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_PAUSE_ZERO(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_PAUSE_ZERO(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_PAUSE_ZERO(...) "BGXX_SMUX_TX_PAUSE_ZERO"


/**
 * RSL - bgx#_smu#_tx_soft_pause
 */
typedef union bdk_bgxx_smux_tx_soft_pause {
	uint64_t u;
	struct bdk_bgxx_smux_tx_soft_pause_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t p_time                      : 16; /**< R/W - Back off the TX bus for (P_TIME * 512) bit-times */
#else
		uint64_t p_time                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_soft_pause_s cn85xx; */
	/* struct bdk_bgxx_smux_tx_soft_pause_s cn88xx; */
	/* struct bdk_bgxx_smux_tx_soft_pause_s cn88xxp1; */
} bdk_bgxx_smux_tx_soft_pause_t;

static inline uint64_t BDK_BGXX_SMUX_TX_SOFT_PAUSE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_SOFT_PAUSE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020128ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_SOFT_PAUSE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_SOFT_PAUSE(...) bdk_bgxx_smux_tx_soft_pause_t
#define bustype_BDK_BGXX_SMUX_TX_SOFT_PAUSE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_SOFT_PAUSE(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_SOFT_PAUSE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_SOFT_PAUSE(...) "BGXX_SMUX_TX_SOFT_PAUSE"


/**
 * RSL - bgx#_smu#_tx_thresh
 */
typedef union bdk_bgxx_smux_tx_thresh {
	uint64_t u;
	struct bdk_bgxx_smux_tx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t cnt                         : 11; /**< R/W - Number of 128-bit words to accumulate in the TX FIFO before sending on the packet
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0.

                                                                 In 10G/40G mode, CNT = 0x100.

                                                                 In all modes, this register cannot exceed the TX FIFO depth as follows.
                                                                 _ BGX()_CMR_TX_PRTS = 0,1:  CNT maximum = 0x7FF.
                                                                 _ BGX()_CMR_TX_PRTS = 2:    CNT maximum = 0x3FF.
                                                                 _ BGX()_CMR_TX_PRTS = 3,4:  CNT maximum = 0x1FF. */
#else
		uint64_t cnt                         : 11;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_bgxx_smux_tx_thresh_s   cn85xx; */
	/* struct bdk_bgxx_smux_tx_thresh_s   cn88xx; */
	/* struct bdk_bgxx_smux_tx_thresh_s   cn88xxp1; */
} bdk_bgxx_smux_tx_thresh_t;

static inline uint64_t BDK_BGXX_SMUX_TX_THRESH(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SMUX_TX_THRESH(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0020180ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SMUX_TX_THRESH", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SMUX_TX_THRESH(...) bdk_bgxx_smux_tx_thresh_t
#define bustype_BDK_BGXX_SMUX_TX_THRESH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SMUX_TX_THRESH(p1,p2) (p1)
#define arguments_BDK_BGXX_SMUX_TX_THRESH(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SMUX_TX_THRESH(...) "BGXX_SMUX_TX_THRESH"


/**
 * RSL - bgx#_spu#_an_adv
 *
 * Software programs this register with the contents of the AN-link code word base page to be
 * transmitted during autonegotiation. (See Std 802.3 section 73.6 for details.) Any write
 * operations to this register prior to completion of autonegotiation, as indicated by
 * BGX()_SPU()_AN_STATUS[AN_COMPLETE], should be followed by a renegotiation in order for
 * the new values to take effect. Renegotiation is initiated by setting
 * BGX()_SPU()_AN_CONTROL[AN_RESTART]. Once autonegotiation has completed, software can
 * examine this register along with BGX()_SPU()_AN_LP_BASE to determine the highest
 * common denominator technology.
 */
typedef union bdk_bgxx_spux_an_adv {
	uint64_t u;
	struct bdk_bgxx_spux_an_adv_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t fec_req                     : 1;  /**< R/W - FEC requested. */
		uint64_t fec_able                    : 1;  /**< R/W - FEC ability. */
		uint64_t arsv                        : 19; /**< R/W - Technology ability. Reserved bits, should always be 0. */
		uint64_t a100g_cr10                  : 1;  /**< R/W - 100GBASE-CR10 ability. Should always be 0; 100GBASE-R is not supported. */
		uint64_t a40g_cr4                    : 1;  /**< R/W - 40GBASE-CR4 ability. */
		uint64_t a40g_kr4                    : 1;  /**< R/W - 40GBASE-KR4 ability. */
		uint64_t a10g_kr                     : 1;  /**< R/W - 10GBASE-KR ability. */
		uint64_t a10g_kx4                    : 1;  /**< R/W - 10GBASE-KX4 ability. */
		uint64_t a1g_kx                      : 1;  /**< R/W - 1000BASE-KX ability. Should always be 0; autonegotiation is not supported for 1000Base-KX. */
		uint64_t t                           : 5;  /**< R/W/H - Transmitted nonce. This field is automatically updated with a pseudo-random value on entry
                                                                 to the AN ability detect state. */
		uint64_t np                          : 1;  /**< R/W - Next page. Always 0; extended next pages are not used for 10G+ autonegotiation. */
		uint64_t ack                         : 1;  /**< RO/H - Acknowledge. Always 0 in this register. */
		uint64_t rf                          : 1;  /**< R/W - Remote fault. */
		uint64_t xnp_able                    : 1;  /**< R/W - Extended next page ability. */
		uint64_t asm_dir                     : 1;  /**< R/W - Asymmetric PAUSE. */
		uint64_t pause                       : 1;  /**< R/W - PAUSE ability. */
		uint64_t e                           : 5;  /**< R/W - Echoed nonce. Provides the echoed-nonce value to use when ACK = 0 in transmitted DME page.
                                                                 Should always be 0x0. */
		uint64_t s                           : 5;  /**< R/W - Selector. Should be 0x1 (encoding for IEEE Std 802.3). */
#else
		uint64_t s                           : 5;
		uint64_t e                           : 5;
		uint64_t pause                       : 1;
		uint64_t asm_dir                     : 1;
		uint64_t xnp_able                    : 1;
		uint64_t rf                          : 1;
		uint64_t ack                         : 1;
		uint64_t np                          : 1;
		uint64_t t                           : 5;
		uint64_t a1g_kx                      : 1;
		uint64_t a10g_kx4                    : 1;
		uint64_t a10g_kr                     : 1;
		uint64_t a40g_kr4                    : 1;
		uint64_t a40g_cr4                    : 1;
		uint64_t a100g_cr10                  : 1;
		uint64_t arsv                        : 19;
		uint64_t fec_able                    : 1;
		uint64_t fec_req                     : 1;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_adv_s      cn85xx; */
	/* struct bdk_bgxx_spux_an_adv_s      cn88xx; */
	/* struct bdk_bgxx_spux_an_adv_s      cn88xxp1; */
} bdk_bgxx_spux_an_adv_t;

static inline uint64_t BDK_BGXX_SPUX_AN_ADV(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_ADV(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100D8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_ADV", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_ADV(...) bdk_bgxx_spux_an_adv_t
#define bustype_BDK_BGXX_SPUX_AN_ADV(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_ADV(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_ADV(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_ADV(...) "BGXX_SPUX_AN_ADV"


/**
 * RSL - bgx#_spu#_an_bp_status
 *
 * The contents of this register (with the exception of the static BP_AN_ABLE bit) are updated
 * during autonegotiation and are valid when BGX()_SPU()_AN_STATUS[AN_COMPLETE] is set.
 * At that time, one of the port type bits (A100G_CR10, A40G_CR4, A40G_KR4, A10G_KR, A10G_KX4,
 * A1G_KX) will be set depending on the AN priority resolution. If a BASE-R type is negotiated,
 * then the FEC bit will be set to indicate that FEC operation has been negotiated, and will be
 * clear otherwise.
 */
typedef union bdk_bgxx_spux_an_bp_status {
	uint64_t u;
	struct bdk_bgxx_spux_an_bp_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t n100g_cr10                  : 1;  /**< RO/H - 100GBASE-CR10 negotiated; expected to always be 0; 100GBASE-R is not supported. */
		uint64_t reserved_7_7                : 1;
		uint64_t n40g_cr4                    : 1;  /**< RO/H - 40GBASE-CR4 negotiated. */
		uint64_t n40g_kr4                    : 1;  /**< RO/H - 40GBASE-KR4 negotiated. */
		uint64_t fec                         : 1;  /**< RO/H - BASE-R FEC negotiated. */
		uint64_t n10g_kr                     : 1;  /**< RO/H - 10GBASE-KR negotiated. */
		uint64_t n10g_kx4                    : 1;  /**< RO/H - 10GBASE-KX4 or CX4 negotiated (XAUI). */
		uint64_t n1g_kx                      : 1;  /**< RO/H - 1000BASE-KX negotiated. */
		uint64_t bp_an_able                  : 1;  /**< RO - Backplane or BASE-R copper AN Ability; always 1. */
#else
		uint64_t bp_an_able                  : 1;
		uint64_t n1g_kx                      : 1;
		uint64_t n10g_kx4                    : 1;
		uint64_t n10g_kr                     : 1;
		uint64_t fec                         : 1;
		uint64_t n40g_kr4                    : 1;
		uint64_t n40g_cr4                    : 1;
		uint64_t reserved_7_7                : 1;
		uint64_t n100g_cr10                  : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_bp_status_s cn85xx; */
	/* struct bdk_bgxx_spux_an_bp_status_s cn88xx; */
	/* struct bdk_bgxx_spux_an_bp_status_s cn88xxp1; */
} bdk_bgxx_spux_an_bp_status_t;

static inline uint64_t BDK_BGXX_SPUX_AN_BP_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_BP_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100F8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_BP_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_BP_STATUS(...) bdk_bgxx_spux_an_bp_status_t
#define bustype_BDK_BGXX_SPUX_AN_BP_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_BP_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_BP_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_BP_STATUS(...) "BGXX_SPUX_AN_BP_STATUS"


/**
 * RSL - bgx#_spu#_an_control
 */
typedef union bdk_bgxx_spux_an_control {
	uint64_t u;
	struct bdk_bgxx_spux_an_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t an_reset                    : 1;  /**< R/W1S/H - Autonegotiation reset. Setting this bit or BGX()_SPU()_CONTROL1[RESET] to 1
                                                                 causes the following to happen:
                                                                 * Resets the logical PCS (LPCS)
                                                                 * Sets the Std 802.3 PCS, FEC and AN registers for the LPCS to their default states
                                                                 * Resets the associated SerDes lanes.

                                                                 It takes up to 32 coprocessor-clock cycles to reset the LPCS, after which RESET is
                                                                 automatically cleared. */
		uint64_t reserved_14_14              : 1;
		uint64_t xnp_en                      : 1;  /**< R/W - Extended next-page enable. */
		uint64_t an_en                       : 1;  /**< R/W - Autonegotiation enable. This bit should not be set when
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is set to RXAUI; autonegotiation is not supported
                                                                 in RXAUI mode. */
		uint64_t reserved_10_11              : 2;
		uint64_t an_restart                  : 1;  /**< R/W1S/H - Autonegotiation restart. Writing a 1 to this bit restarts the autonegotiation process if
                                                                 AN_EN is also set. This is a self-clearing bit. */
		uint64_t reserved_0_8                : 9;
#else
		uint64_t reserved_0_8                : 9;
		uint64_t an_restart                  : 1;
		uint64_t reserved_10_11              : 2;
		uint64_t an_en                       : 1;
		uint64_t xnp_en                      : 1;
		uint64_t reserved_14_14              : 1;
		uint64_t an_reset                    : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_control_s  cn85xx; */
	/* struct bdk_bgxx_spux_an_control_s  cn88xx; */
	/* struct bdk_bgxx_spux_an_control_s  cn88xxp1; */
} bdk_bgxx_spux_an_control_t;

static inline uint64_t BDK_BGXX_SPUX_AN_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100C8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_CONTROL(...) bdk_bgxx_spux_an_control_t
#define bustype_BDK_BGXX_SPUX_AN_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_CONTROL(...) "BGXX_SPUX_AN_CONTROL"


/**
 * RSL - bgx#_spu#_an_lp_base
 *
 * This register captures the contents of the latest AN link code word base page received from
 * the link partner during autonegotiation. (See Std 802.3 section 73.6 for details.)
 * BGX()_SPU()_AN_STATUS[PAGE_RX] is set when this register is updated by hardware.
 */
typedef union bdk_bgxx_spux_an_lp_base {
	uint64_t u;
	struct bdk_bgxx_spux_an_lp_base_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t fec_req                     : 1;  /**< RO/H - FEC requested. */
		uint64_t fec_able                    : 1;  /**< RO/H - FEC ability. */
		uint64_t arsv                        : 19; /**< RO/H - Technology ability. Reserved bits, should always be 0. */
		uint64_t a100g_cr10                  : 1;  /**< RO/H - 100GBASE-CR10 ability. */
		uint64_t a40g_cr4                    : 1;  /**< RO/H - 40GBASE-CR4 ability. */
		uint64_t a40g_kr4                    : 1;  /**< RO/H - 40GBASE-KR4 ability. */
		uint64_t a10g_kr                     : 1;  /**< RO/H - 10GBASE-KR ability. */
		uint64_t a10g_kx4                    : 1;  /**< RO/H - 10GBASE-KX4 ability. */
		uint64_t a1g_kx                      : 1;  /**< RO/H - 1000BASE-KX ability. */
		uint64_t t                           : 5;  /**< RO/H - Transmitted nonce. */
		uint64_t np                          : 1;  /**< RO/H - Next page. */
		uint64_t ack                         : 1;  /**< RO/H - Acknowledge. */
		uint64_t rf                          : 1;  /**< RO/H - Remote fault. */
		uint64_t xnp_able                    : 1;  /**< RO/H - Extended next page ability. */
		uint64_t asm_dir                     : 1;  /**< RO/H - Asymmetric PAUSE. */
		uint64_t pause                       : 1;  /**< RO/H - PAUSE ability. */
		uint64_t e                           : 5;  /**< RO/H - Echoed nonce. */
		uint64_t s                           : 5;  /**< RO/H - Selector. */
#else
		uint64_t s                           : 5;
		uint64_t e                           : 5;
		uint64_t pause                       : 1;
		uint64_t asm_dir                     : 1;
		uint64_t xnp_able                    : 1;
		uint64_t rf                          : 1;
		uint64_t ack                         : 1;
		uint64_t np                          : 1;
		uint64_t t                           : 5;
		uint64_t a1g_kx                      : 1;
		uint64_t a10g_kx4                    : 1;
		uint64_t a10g_kr                     : 1;
		uint64_t a40g_kr4                    : 1;
		uint64_t a40g_cr4                    : 1;
		uint64_t a100g_cr10                  : 1;
		uint64_t arsv                        : 19;
		uint64_t fec_able                    : 1;
		uint64_t fec_req                     : 1;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_lp_base_s  cn85xx; */
	/* struct bdk_bgxx_spux_an_lp_base_s  cn88xx; */
	/* struct bdk_bgxx_spux_an_lp_base_s  cn88xxp1; */
} bdk_bgxx_spux_an_lp_base_t;

static inline uint64_t BDK_BGXX_SPUX_AN_LP_BASE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_LP_BASE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100E0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_LP_BASE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_LP_BASE(...) bdk_bgxx_spux_an_lp_base_t
#define bustype_BDK_BGXX_SPUX_AN_LP_BASE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_LP_BASE(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_LP_BASE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_LP_BASE(...) "BGXX_SPUX_AN_LP_BASE"


/**
 * RSL - bgx#_spu#_an_lp_xnp
 *
 * This register captures the contents of the latest next page code word received from the link
 * partner during autonegotiation, if any. See section 802.3 section 73.7.7 for details.
 */
typedef union bdk_bgxx_spux_an_lp_xnp {
	uint64_t u;
	struct bdk_bgxx_spux_an_lp_xnp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t u                           : 32; /**< RO/H - Unformatted code field. */
		uint64_t np                          : 1;  /**< RO/H - Next page. */
		uint64_t ack                         : 1;  /**< RO/H - Acknowledge. */
		uint64_t mp                          : 1;  /**< RO/H - Message page. */
		uint64_t ack2                        : 1;  /**< RO/H - Acknowledge 2. */
		uint64_t toggle                      : 1;  /**< RO/H - Toggle. */
		uint64_t m_u                         : 11; /**< RO/H - Message/unformatted code field. */
#else
		uint64_t m_u                         : 11;
		uint64_t toggle                      : 1;
		uint64_t ack2                        : 1;
		uint64_t mp                          : 1;
		uint64_t ack                         : 1;
		uint64_t np                          : 1;
		uint64_t u                           : 32;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_lp_xnp_s   cn85xx; */
	/* struct bdk_bgxx_spux_an_lp_xnp_s   cn88xx; */
	/* struct bdk_bgxx_spux_an_lp_xnp_s   cn88xxp1; */
} bdk_bgxx_spux_an_lp_xnp_t;

static inline uint64_t BDK_BGXX_SPUX_AN_LP_XNP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_LP_XNP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100F0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_LP_XNP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_LP_XNP(...) bdk_bgxx_spux_an_lp_xnp_t
#define bustype_BDK_BGXX_SPUX_AN_LP_XNP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_LP_XNP(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_LP_XNP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_LP_XNP(...) "BGXX_SPUX_AN_LP_XNP"


/**
 * RSL - bgx#_spu#_an_status
 */
typedef union bdk_bgxx_spux_an_status {
	uint64_t u;
	struct bdk_bgxx_spux_an_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t prl_flt                     : 1;  /**< RO - Parallel detection fault. Always 0; SPU does not support parallel detection as part of the
                                                                 autonegotiation protocol. */
		uint64_t reserved_8_8                : 1;
		uint64_t xnp_stat                    : 1;  /**< RO/H - Extended next-page status. */
		uint64_t page_rx                     : 1;  /**< R/W1C/H - Page received. This latching-high bit is set when a new page has been received and stored
                                                                 in BGX()_SPU()_AN_LP_BASE or BGX()_SPU()_AN_LP_XNP; stays set until a 1 is
                                                                 written by software, autonegotiation is disabled or restarted, or next page exchange is
                                                                 initiated. Note that in order to avoid read side effects, this is implemented as a
                                                                 write-1-to-clear bit, rather than latching high read-only as specified in 802.3. */
		uint64_t an_complete                 : 1;  /**< RO/H - Autonegotiation complete. Set when the autonegotiation process has been completed and
                                                                 the link is up and running using the negotiated highest common denominator (HCD)
                                                                 technology. If AN is enabled (BGX()_SPU()_AN_CONTROL[AN_EN] = 1) and this bit is
                                                                 read as a zero, it indicates that the AN process has not been completed, and the contents
                                                                 of BGX()_SPU()_AN_LP_BASE, BGX()_SPU()_AN_XNP_TX, and
                                                                 BGX()_SPU()_AN_LP_XNP are as defined by the current state of the autonegotiation
                                                                 protocol, or as written for manual configuration. This bit is always zero when AN is
                                                                 disabled (BGX()_SPU()_AN_CONTROL[AN_EN] = 0). */
		uint64_t rmt_flt                     : 1;  /**< RO - Remote fault: Always 0. */
		uint64_t an_able                     : 1;  /**< RO - Autonegotiation ability: Always 1. */
		uint64_t link_status                 : 1;  /**< R/W1S/H - Link status. This bit captures the state of the link_status variable as defined in 802.3
                                                                 section 73.9.1. When set, indicates that a valid link has been established. When clear,
                                                                 indicates that the link has been invalid after this bit was last set by software. Latching
                                                                 low bit; stays clear until a 1 is written by software. Note that in order to avoid read
                                                                 side effects, this is implemented as a write-1-to-set bit, rather than latching low read-
                                                                 only as specified in 802.3. */
		uint64_t reserved_1_1                : 1;
		uint64_t lp_an_able                  : 1;  /**< RO/H - Link partner autonegotiation ability. Set to indicate that the link partner is able to
                                                                 participate in the autonegotiation function, and cleared otherwise. */
#else
		uint64_t lp_an_able                  : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t link_status                 : 1;
		uint64_t an_able                     : 1;
		uint64_t rmt_flt                     : 1;
		uint64_t an_complete                 : 1;
		uint64_t page_rx                     : 1;
		uint64_t xnp_stat                    : 1;
		uint64_t reserved_8_8                : 1;
		uint64_t prl_flt                     : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_status_s   cn85xx; */
	/* struct bdk_bgxx_spux_an_status_s   cn88xx; */
	/* struct bdk_bgxx_spux_an_status_s   cn88xxp1; */
} bdk_bgxx_spux_an_status_t;

static inline uint64_t BDK_BGXX_SPUX_AN_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100D0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_STATUS(...) bdk_bgxx_spux_an_status_t
#define bustype_BDK_BGXX_SPUX_AN_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_STATUS(...) "BGXX_SPUX_AN_STATUS"


/**
 * RSL - bgx#_spu#_an_xnp_tx
 *
 * Software programs this register with the contents of the AN message next page or unformatted
 * next page link code word to be transmitted during autonegotiation. Next page exchange occurs
 * after the base link code words have been exchanged if either end of the link segment sets the
 * NP bit to 1, indicating that it has at least one next page to send. Once initiated, next page
 * exchange continues until both ends of the link segment set their NP bits to 0. See section
 * 802.3 section 73.7.7 for details.
 */
typedef union bdk_bgxx_spux_an_xnp_tx {
	uint64_t u;
	struct bdk_bgxx_spux_an_xnp_tx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t u                           : 32; /**< R/W - Unformatted code field. When the MP bit is set, this field contains the 32-bit unformatted
                                                                 code field of the message next page. When MP is clear, this field contains the upper 32
                                                                 bits of the 43-bit unformatted code field of the unformatted next page. */
		uint64_t np                          : 1;  /**< R/W - Next page. */
		uint64_t ack                         : 1;  /**< RO/H - Acknowledge: Always 0 in this register. */
		uint64_t mp                          : 1;  /**< R/W - Message page. Set to indicate that this register contains a message next page. Clear to
                                                                 indicate that the register contains an unformatted next page. */
		uint64_t ack2                        : 1;  /**< R/W - Acknowledge 2. Indicates that the receiver is able to act on the information (or perform
                                                                 the task) defined in the message. */
		uint64_t toggle                      : 1;  /**< R/W - This bit is ignored by hardware. The value of the TOGGLE bit in transmitted next pages is
                                                                 automatically generated by hardware. */
		uint64_t m_u                         : 11; /**< R/W - Message/Unformatted code field: When the MP bit is set, this field contains the message
                                                                 code field (M) of the message next page. When MP is clear, this field contains the lower
                                                                 11 bits of the 43-bit unformatted code field of the unformatted next page. */
#else
		uint64_t m_u                         : 11;
		uint64_t toggle                      : 1;
		uint64_t ack2                        : 1;
		uint64_t mp                          : 1;
		uint64_t ack                         : 1;
		uint64_t np                          : 1;
		uint64_t u                           : 32;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_an_xnp_tx_s   cn85xx; */
	/* struct bdk_bgxx_spux_an_xnp_tx_s   cn88xx; */
	/* struct bdk_bgxx_spux_an_xnp_tx_s   cn88xxp1; */
} bdk_bgxx_spux_an_xnp_tx_t;

static inline uint64_t BDK_BGXX_SPUX_AN_XNP_TX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_AN_XNP_TX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100E8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_AN_XNP_TX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_AN_XNP_TX(...) bdk_bgxx_spux_an_xnp_tx_t
#define bustype_BDK_BGXX_SPUX_AN_XNP_TX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_AN_XNP_TX(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_AN_XNP_TX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_AN_XNP_TX(...) "BGXX_SPUX_AN_XNP_TX"


/**
 * RSL - bgx#_spu#_br_algn_status
 *
 * This register implements the Std 802.3 multilane BASE-R PCS alignment status 1-4 registers
 * (3.50-3.53). It is valid only when the LPCS type is 40GBASE-R
 * (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), and always returns 0x0 for all other LPCS
 * types. Std 802.3 bits that are not applicable to 40GBASE-R (e.g. status bits for PCS lanes
 * 19-4) are not implemented and marked as reserved. PCS lanes 3-0 are valid and are mapped to
 * physical SerDes lanes based on the programming of BGX()_CMR()_CONFIG[[LANE_TO_SDS].
 */
typedef union bdk_bgxx_spux_br_algn_status {
	uint64_t u;
	struct bdk_bgxx_spux_br_algn_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t marker_lock                 : 4;  /**< RO/H - Marker-locked status for PCS lanes 3-0.
                                                                 0 = Not locked.
                                                                 1 = Locked. */
		uint64_t reserved_13_31              : 19;
		uint64_t alignd                      : 1;  /**< RO/H - All lanes are locked and aligned. This bit returns 1 when the logical PCS has locked and
                                                                 aligned all associated receive lanes; returns 0 otherwise. For all other PCS types, this
                                                                 bit always returns 0. */
		uint64_t reserved_4_11               : 8;
		uint64_t block_lock                  : 4;  /**< RO/H - Block-lock status for PCS lanes 3-0:
                                                                 0 = Not locked.
                                                                 1 = Locked. */
#else
		uint64_t block_lock                  : 4;
		uint64_t reserved_4_11               : 8;
		uint64_t alignd                      : 1;
		uint64_t reserved_13_31              : 19;
		uint64_t marker_lock                 : 4;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_algn_status_s cn85xx; */
	/* struct bdk_bgxx_spux_br_algn_status_s cn88xx; */
	/* struct bdk_bgxx_spux_br_algn_status_s cn88xxp1; */
} bdk_bgxx_spux_br_algn_status_t;

static inline uint64_t BDK_BGXX_SPUX_BR_ALGN_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_ALGN_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010050ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_ALGN_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_ALGN_STATUS(...) bdk_bgxx_spux_br_algn_status_t
#define bustype_BDK_BGXX_SPUX_BR_ALGN_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_ALGN_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_ALGN_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_ALGN_STATUS(...) "BGXX_SPUX_BR_ALGN_STATUS"


/**
 * RSL - bgx#_spu#_br_bip_err_cnt
 *
 * This register implements the Std 802.3 BIP error-counter registers for PCS lanes 0-3
 * (3.200-3.203). It is valid only when the LPCS type is 40GBASE-R
 * (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), and always returns 0x0 for all other LPCS
 * types. The counters are indexed by the RX PCS lane number based on the Alignment Marker
 * detected on each lane and captured in BGX()_SPU()_BR_LANE_MAP. Each counter counts the
 * BIP errors for its PCS lane, and is held at all ones in case of overflow. The counters are
 * reset to all 0s when this register is read by software.
 *
 * The reset operation takes precedence over the increment operation; if the register is read on
 * the same clock cycle as an increment operation, the counter is reset to all 0s and the
 * increment operation is lost. The counters are writable for test purposes, rather than read-
 * only as specified in Std 802.3.
 */
typedef union bdk_bgxx_spux_br_bip_err_cnt {
	uint64_t u;
	struct bdk_bgxx_spux_br_bip_err_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bip_err_cnt_ln3             : 16; /**< RC/W/H - BIP error counter for lane on which PCS lane 3 markers are received. */
		uint64_t bip_err_cnt_ln2             : 16; /**< RC/W/H - BIP error counter for lane on which PCS lane 2 markers are received. */
		uint64_t bip_err_cnt_ln1             : 16; /**< RC/W/H - BIP error counter for lane on which PCS lane 1 markers are received. */
		uint64_t bip_err_cnt_ln0             : 16; /**< RC/W/H - BIP error counter for lane on which PCS lane 0 markers are received. */
#else
		uint64_t bip_err_cnt_ln0             : 16;
		uint64_t bip_err_cnt_ln1             : 16;
		uint64_t bip_err_cnt_ln2             : 16;
		uint64_t bip_err_cnt_ln3             : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_bip_err_cnt_s cn85xx; */
	/* struct bdk_bgxx_spux_br_bip_err_cnt_s cn88xx; */
	/* struct bdk_bgxx_spux_br_bip_err_cnt_s cn88xxp1; */
} bdk_bgxx_spux_br_bip_err_cnt_t;

static inline uint64_t BDK_BGXX_SPUX_BR_BIP_ERR_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_BIP_ERR_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010058ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_BIP_ERR_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_BIP_ERR_CNT(...) bdk_bgxx_spux_br_bip_err_cnt_t
#define bustype_BDK_BGXX_SPUX_BR_BIP_ERR_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_BIP_ERR_CNT(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_BIP_ERR_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_BIP_ERR_CNT(...) "BGXX_SPUX_BR_BIP_ERR_CNT"


/**
 * RSL - bgx#_spu#_br_lane_map
 *
 * This register implements the Std 802.3 lane 0-3 mapping registers (3.400-3.403). It is valid
 * only when the LPCS type is 40GBASE-R (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), and always
 * returns 0x0 for all other LPCS types. The LNx_MAPPING field for each programmed PCS lane
 * (called service interface in 802.3ba-2010) is valid when that lane has achieved alignment
 * marker lock on the receive side (i.e. the associated
 * BGX()_SPU()_BR_ALGN_STATUS[MARKER_LOCK] = 1), and is invalid otherwise. When valid, it
 * returns the actual detected receive PCS lane number based on the received alignment marker
 * contents received on that service interface.
 *
 * The mapping is flexible because Std 802.3 allows multilane BASE-R receive lanes to be re-
 * ordered. Note that for the transmit side, each PCS lane is mapped to a physical SerDes lane
 * based on the programming of BGX()_CMR()_CONFIG[LANE_TO_SDS]. For the receive side,
 * BGX()_CMR()_CONFIG[LANE_TO_SDS] specifies the service interface to physical SerDes
 * lane mapping, and this register specifies the PCS lane to service interface mapping.
 */
typedef union bdk_bgxx_spux_br_lane_map {
	uint64_t u;
	struct bdk_bgxx_spux_br_lane_map_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_54_63              : 10;
		uint64_t ln3_mapping                 : 6;  /**< RO/H - PCS lane number received on service interface 3 */
		uint64_t reserved_38_47              : 10;
		uint64_t ln2_mapping                 : 6;  /**< RO/H - PCS lane number received on service interface 2 */
		uint64_t reserved_22_31              : 10;
		uint64_t ln1_mapping                 : 6;  /**< RO/H - PCS lane number received on service interface 1 */
		uint64_t reserved_6_15               : 10;
		uint64_t ln0_mapping                 : 6;  /**< RO/H - PCS lane number received on service interface 0 */
#else
		uint64_t ln0_mapping                 : 6;
		uint64_t reserved_6_15               : 10;
		uint64_t ln1_mapping                 : 6;
		uint64_t reserved_22_31              : 10;
		uint64_t ln2_mapping                 : 6;
		uint64_t reserved_38_47              : 10;
		uint64_t ln3_mapping                 : 6;
		uint64_t reserved_54_63              : 10;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_lane_map_s cn85xx; */
	/* struct bdk_bgxx_spux_br_lane_map_s cn88xx; */
	/* struct bdk_bgxx_spux_br_lane_map_s cn88xxp1; */
} bdk_bgxx_spux_br_lane_map_t;

static inline uint64_t BDK_BGXX_SPUX_BR_LANE_MAP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_LANE_MAP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010060ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_LANE_MAP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_LANE_MAP(...) bdk_bgxx_spux_br_lane_map_t
#define bustype_BDK_BGXX_SPUX_BR_LANE_MAP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_LANE_MAP(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_LANE_MAP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_LANE_MAP(...) "BGXX_SPUX_BR_LANE_MAP"


/**
 * RSL - bgx#_spu#_br_pmd_control
 */
typedef union bdk_bgxx_spux_br_pmd_control {
	uint64_t u;
	struct bdk_bgxx_spux_br_pmd_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t train_en                    : 1;  /**< R/W - BASE-R training enable */
		uint64_t train_restart               : 1;  /**< R/W1S/H - BASE-R training restart. Writing a 1 to this bit restarts the training process if the
                                                                 TRAIN_EN bit in this register is also set. This is a self-clearing bit. Software should
                                                                 wait a minimum of 1.7ms after BGX()_SPU()_INT[TRAINING_FAILURE] is set before
                                                                 restarting the training process. */
#else
		uint64_t train_restart               : 1;
		uint64_t train_en                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_pmd_control_s cn85xx; */
	/* struct bdk_bgxx_spux_br_pmd_control_s cn88xx; */
	/* struct bdk_bgxx_spux_br_pmd_control_s cn88xxp1; */
} bdk_bgxx_spux_br_pmd_control_t;

static inline uint64_t BDK_BGXX_SPUX_BR_PMD_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_PMD_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010068ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_PMD_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_PMD_CONTROL(...) bdk_bgxx_spux_br_pmd_control_t
#define bustype_BDK_BGXX_SPUX_BR_PMD_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_PMD_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_PMD_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_PMD_CONTROL(...) "BGXX_SPUX_BR_PMD_CONTROL"


/**
 * RSL - bgx#_spu#_br_pmd_ld_cup
 *
 * This register implements 802.3 MDIO register 1.153 for 10GBASE-R (when
 * BGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R)
 * and MDIO registers 1.1300-1.1303 for 40GBASE-R (when
 * LMAC_TYPE = 40G_R). It is automatically cleared at the start of training. When link training
 * is in progress, each field reflects the contents of the coefficient update field in the
 * associated lane's outgoing training frame. The fields in this register are read/write even
 * though they are specified as read-only in 802.3.
 *
 * If BGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is set, then this register must be updated
 * by software during link training and hardware updates are disabled. If
 * BGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is clear, this register is automatically
 * updated by hardware, and it should not be written by software. The lane fields in this
 * register are indexed by logical PCS lane ID.
 *
 * The lane 0 field (LN0_*) is valid for both
 * 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*, LN3_*) are only valid for
 * 40GBASE-R.
 */
typedef union bdk_bgxx_spux_br_pmd_ld_cup {
	uint64_t u;
	struct bdk_bgxx_spux_br_pmd_ld_cup_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln3_cup                     : 16; /**< R/W/H - PCS lane 3 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln2_cup                     : 16; /**< R/W/H - PCS lane 2 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln1_cup                     : 16; /**< R/W/H - PCS lane 1 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln0_cup                     : 16; /**< R/W/H - PCS lane 0 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. */
#else
		uint64_t ln0_cup                     : 16;
		uint64_t ln1_cup                     : 16;
		uint64_t ln2_cup                     : 16;
		uint64_t ln3_cup                     : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_pmd_ld_cup_s cn85xx; */
	/* struct bdk_bgxx_spux_br_pmd_ld_cup_s cn88xx; */
	/* struct bdk_bgxx_spux_br_pmd_ld_cup_s cn88xxp1; */
} bdk_bgxx_spux_br_pmd_ld_cup_t;

static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LD_CUP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LD_CUP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010088ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_PMD_LD_CUP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_PMD_LD_CUP(...) bdk_bgxx_spux_br_pmd_ld_cup_t
#define bustype_BDK_BGXX_SPUX_BR_PMD_LD_CUP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_PMD_LD_CUP(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_PMD_LD_CUP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_PMD_LD_CUP(...) "BGXX_SPUX_BR_PMD_LD_CUP"


/**
 * RSL - bgx#_spu#_br_pmd_ld_rep
 *
 * This register implements 802.3 MDIO register 1.154 for 10GBASE-R (when
 * BGX()_CMR()_CONFIG[LMAC_TYPE] = IOG_R) and MDIO registers 1.1400-1.1403 for 40GBASE-R
 * (when LMAC_TYPE = 40G_R). It is automatically cleared at the start of training. Each field
 * reflects the contents of the status report field in the associated lane's outgoing training
 * frame. The fields in this register are read/write even though they are specified as read-only
 * in 802.3. If BGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is set, then this register must
 * be updated by software during link training and hardware updates are disabled. If
 * BGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is clear, this register is automatically
 * updated by hardware, and it should not be written by software. The lane fields in this
 * register are indexed by logical PCS lane ID.
 *
 * The lane 0 field (LN0_*) is valid for both
 * 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*, LN3_*) are only valid for
 * 40GBASE-R.
 */
typedef union bdk_bgxx_spux_br_pmd_ld_rep {
	uint64_t u;
	struct bdk_bgxx_spux_br_pmd_ld_rep_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln3_rep                     : 16; /**< R/W/H - PCS lane 3 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln2_rep                     : 16; /**< R/W/H - PCS lane 2 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln1_rep                     : 16; /**< R/W/H - PCS lane 1 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln0_rep                     : 16; /**< R/W/H - PCS lane 0 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. */
#else
		uint64_t ln0_rep                     : 16;
		uint64_t ln1_rep                     : 16;
		uint64_t ln2_rep                     : 16;
		uint64_t ln3_rep                     : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_pmd_ld_rep_s cn85xx; */
	/* struct bdk_bgxx_spux_br_pmd_ld_rep_s cn88xx; */
	/* struct bdk_bgxx_spux_br_pmd_ld_rep_s cn88xxp1; */
} bdk_bgxx_spux_br_pmd_ld_rep_t;

static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LD_REP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LD_REP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010090ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_PMD_LD_REP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_PMD_LD_REP(...) bdk_bgxx_spux_br_pmd_ld_rep_t
#define bustype_BDK_BGXX_SPUX_BR_PMD_LD_REP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_PMD_LD_REP(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_PMD_LD_REP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_PMD_LD_REP(...) "BGXX_SPUX_BR_PMD_LD_REP"


/**
 * RSL - bgx#_spu#_br_pmd_lp_cup
 *
 * This register implements 802.3 MDIO register 1.152 for 10GBASE-R (when
 * BGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R)
 * and MDIO registers 1.1100-1.1103 for 40GBASE-R (when
 * LMAC_TYPE = 40G_R). It is automatically cleared at the start of training. Each field reflects
 * the contents of the coefficient update field in the lane's most recently received training
 * frame. This register should not be written when link training is enabled, i.e. when TRAIN_EN
 * is set BR_PMD_CONTROL. The lane fields in this register are indexed by logical PCS lane ID.
 *
 * The lane 0 field (LN0_*) is valid for both 10GBASE-R and 40GBASE-R. The remaining fields
 * (LN1_*, LN2_*, LN3_*) are only valid for 40GBASE-R.
 */
typedef union bdk_bgxx_spux_br_pmd_lp_cup {
	uint64_t u;
	struct bdk_bgxx_spux_br_pmd_lp_cup_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln3_cup                     : 16; /**< R/W/H - PCS lane 3 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln2_cup                     : 16; /**< R/W/H - PCS lane 2 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln1_cup                     : 16; /**< R/W/H - PCS lane 1 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln0_cup                     : 16; /**< R/W/H - PCS lane 0 coefficient update: format defined by BGX_SPU_BR_TRAIN_CUP_S. */
#else
		uint64_t ln0_cup                     : 16;
		uint64_t ln1_cup                     : 16;
		uint64_t ln2_cup                     : 16;
		uint64_t ln3_cup                     : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_pmd_lp_cup_s cn85xx; */
	/* struct bdk_bgxx_spux_br_pmd_lp_cup_s cn88xx; */
	/* struct bdk_bgxx_spux_br_pmd_lp_cup_s cn88xxp1; */
} bdk_bgxx_spux_br_pmd_lp_cup_t;

static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LP_CUP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LP_CUP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010078ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_PMD_LP_CUP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_PMD_LP_CUP(...) bdk_bgxx_spux_br_pmd_lp_cup_t
#define bustype_BDK_BGXX_SPUX_BR_PMD_LP_CUP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_PMD_LP_CUP(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_PMD_LP_CUP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_PMD_LP_CUP(...) "BGXX_SPUX_BR_PMD_LP_CUP"


/**
 * RSL - bgx#_spu#_br_pmd_lp_rep
 *
 * This register implements 802.3 MDIO register 1.153 for 10GBASE-R (when
 * BGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R)
 * and MDIO registers 1.1200-1.1203 for 40GBASE-R (when
 * LMAC_TYPE = 40G_R). It is automatically cleared at the start of training. Each field reflects
 * the contents of the status report field in the associated lane's most recently received
 * training frame. The lane fields in this register are indexed by logical PCS lane ID.
 *
 * The lane
 * 0 field (LN0_*) is valid for both 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*,
 * LN3_*) are only valid for 40GBASE-R.
 */
typedef union bdk_bgxx_spux_br_pmd_lp_rep {
	uint64_t u;
	struct bdk_bgxx_spux_br_pmd_lp_rep_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln3_rep                     : 16; /**< RO/H - PCS lane 3 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln2_rep                     : 16; /**< RO/H - PCS lane 2 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln1_rep                     : 16; /**< RO/H - PCS lane 1 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
		uint64_t ln0_rep                     : 16; /**< RO/H - PCS lane 0 status report: format defined by BGX_SPU_BR_TRAIN_REP_S. */
#else
		uint64_t ln0_rep                     : 16;
		uint64_t ln1_rep                     : 16;
		uint64_t ln2_rep                     : 16;
		uint64_t ln3_rep                     : 16;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_pmd_lp_rep_s cn85xx; */
	/* struct bdk_bgxx_spux_br_pmd_lp_rep_s cn88xx; */
	/* struct bdk_bgxx_spux_br_pmd_lp_rep_s cn88xxp1; */
} bdk_bgxx_spux_br_pmd_lp_rep_t;

static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LP_REP(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_PMD_LP_REP(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010080ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_PMD_LP_REP", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_PMD_LP_REP(...) bdk_bgxx_spux_br_pmd_lp_rep_t
#define bustype_BDK_BGXX_SPUX_BR_PMD_LP_REP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_PMD_LP_REP(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_PMD_LP_REP(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_PMD_LP_REP(...) "BGXX_SPUX_BR_PMD_LP_REP"


/**
 * RSL - bgx#_spu#_br_pmd_status
 *
 * The lane fields in this register are indexed by logical PCS lane ID. The lane 0 field (LN0_*)
 * is valid for both 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*, LN3_*) are only
 * valid for 40GBASE-R.
 */
typedef union bdk_bgxx_spux_br_pmd_status {
	uint64_t u;
	struct bdk_bgxx_spux_br_pmd_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t ln3_train_status            : 4;  /**< RO/H - PCS lane 3 link training status. Format defined by BGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
		uint64_t ln2_train_status            : 4;  /**< RO/H - PCS lane 2 link training status. Format defined by BGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
		uint64_t ln1_train_status            : 4;  /**< RO/H - PCS lane 1 link training status. Format defined by BGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
		uint64_t ln0_train_status            : 4;  /**< RO/H - PCS lane 0 link training status. Format defined by BGX_SPU_BR_LANE_TRAIN_STATUS_S. */
#else
		uint64_t ln0_train_status            : 4;
		uint64_t ln1_train_status            : 4;
		uint64_t ln2_train_status            : 4;
		uint64_t ln3_train_status            : 4;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_pmd_status_s cn85xx; */
	/* struct bdk_bgxx_spux_br_pmd_status_s cn88xx; */
	/* struct bdk_bgxx_spux_br_pmd_status_s cn88xxp1; */
} bdk_bgxx_spux_br_pmd_status_t;

static inline uint64_t BDK_BGXX_SPUX_BR_PMD_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_PMD_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010070ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_PMD_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_PMD_STATUS(...) bdk_bgxx_spux_br_pmd_status_t
#define bustype_BDK_BGXX_SPUX_BR_PMD_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_PMD_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_PMD_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_PMD_STATUS(...) "BGXX_SPUX_BR_PMD_STATUS"


/**
 * RSL - bgx#_spu#_br_status1
 */
typedef union bdk_bgxx_spux_br_status1 {
	uint64_t u;
	struct bdk_bgxx_spux_br_status1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t rcv_lnk                     : 1;  /**< RO/H - BASE-R receive link status.
                                                                 0 = BASE-R PCS receive-link down.
                                                                 1 = BASE-R PCS receive-link up

                                                                 This bit is a reflection of the PCS_status variable defined in Std 802.3 sections
                                                                 49.2.14.1 and 82.3.1. */
		uint64_t reserved_4_11               : 8;
		uint64_t prbs9                       : 1;  /**< RO - 10GBASE-R PRBS9 pattern testing ability. Always 0; PRBS9 pattern testing is not supported. */
		uint64_t prbs31                      : 1;  /**< RO - 10GBASE-R PRBS31 pattern testing ability. Always 0; PRBS31 pattern testing is not supported. */
		uint64_t hi_ber                      : 1;  /**< RO/H - BASE-R PCS high bit-error rate.
                                                                 0 = 64B/66B receiver is detecting a bit-error rate of \< 10.4.
                                                                 1 = 64B/66B receiver is detecting a bit-error rate of \>= 10.4.

                                                                 This bit is a direct reflection of the state of the HI_BER variable in the 64B/66B state
                                                                 diagram and is defined in Std 802.3 sections 49.2.13.2.2 and 82.2.18.2.2. */
		uint64_t blk_lock                    : 1;  /**< RO/H - BASE-R PCS block lock.
                                                                 0 = No block lock.
                                                                 1 = 64B/66B receiver for BASE-R has block lock.

                                                                 This bit is a direct reflection of the state of the BLOCK_LOCK variable in the 64B/66B
                                                                 state diagram and is defined in Std 802.3 sections 49.2.13.2.2 and 82.2.18.2.2.
                                                                 For a multilane logical PCS (i.e. 40GBASE-R), this bit indicates that the receiver has
                                                                 both block lock and alignment for all lanes and is identical to
                                                                 BGX()_SPU()_BR_ALGN_STATUS[ALIGND]. */
#else
		uint64_t blk_lock                    : 1;
		uint64_t hi_ber                      : 1;
		uint64_t prbs31                      : 1;
		uint64_t prbs9                       : 1;
		uint64_t reserved_4_11               : 8;
		uint64_t rcv_lnk                     : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_status1_s  cn85xx; */
	/* struct bdk_bgxx_spux_br_status1_s  cn88xx; */
	/* struct bdk_bgxx_spux_br_status1_s  cn88xxp1; */
} bdk_bgxx_spux_br_status1_t;

static inline uint64_t BDK_BGXX_SPUX_BR_STATUS1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_STATUS1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010030ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_STATUS1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_STATUS1(...) bdk_bgxx_spux_br_status1_t
#define bustype_BDK_BGXX_SPUX_BR_STATUS1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_STATUS1(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_STATUS1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_STATUS1(...) "BGXX_SPUX_BR_STATUS1"


/**
 * RSL - bgx#_spu#_br_status2
 *
 * This register implements a combination of the following Std 802.3 registers:
 * * BASE-R PCS status 2 (MDIO address 3.33).
 * * BASE-R BER high-order counter (MDIO address 3.44).
 * * Errored-blocks high-order counter (MDIO address 3.45).
 *
 * Note that the relative locations of some fields have been moved from Std 802.3 in order to
 * make the register layout more software friendly: the BER counter high-order and low-order bits
 * from sections 3.44 and 3.33 have been combined into the contiguous, 22-bit BER_CNT field;
 * likewise, the errored-blocks counter high-order and low-order bits from section 3.45 have been
 * combined into the contiguous, 22-bit ERR_BLKS field.
 */
typedef union bdk_bgxx_spux_br_status2 {
	uint64_t u;
	struct bdk_bgxx_spux_br_status2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_62_63              : 2;
		uint64_t err_blks                    : 22; /**< RC/W/H - Errored-blocks counter. This is the BASE-R errored-blocks counter as defined by the
                                                                 errored_block_count variable specified in Std 802.3 sections 49.2.14.2 and 82.2.18.2.4. It
                                                                 increments by 1 on each block for which the BASE-R receive state machine, specified in Std
                                                                 802.3 diagrams 49-15 and 82-15, enters the RX_E state.
                                                                 Back-to-back blocks in the RX_E state are counted as transitions from RX_E to RX_E and
                                                                 keep incrementing the counter. The counter is reset to all 0s after this register is read
                                                                 by software.

                                                                 The reset operation takes precedence over the increment operation: if the register is read
                                                                 on the same clock cycle as an increment operation, the counter is reset to all 0s and the
                                                                 increment operation is lost.

                                                                 This field is writable for test purposes, rather than read-only as specified in Std 802.3. */
		uint64_t reserved_38_39              : 2;
		uint64_t ber_cnt                     : 22; /**< RC/W/H - Bit-error-rate counter. This is the BASE-R BER counter as defined by the BER_COUNT
                                                                 variable in Std 802.3 sections 49.2.14.2 and 82.2.18.2.4. The counter is reset to all 0s
                                                                 after this register is read by software, and is held at all 1s in case of overflow.
                                                                 The reset operation takes precedence over the increment operation: if the register is read
                                                                 on the same clock cycle an increment operation, the counter is reset to all 0s and the
                                                                 increment operation is lost.

                                                                 This field is writable for test purposes, rather than read-only as specified in Std 802.3. */
		uint64_t latched_lock                : 1;  /**< R/W1S/H - Latched-block lock.
                                                                 0 = No block.
                                                                 1 = 64B/66B receiver for BASE-R has block lock.

                                                                 This is a latching-low version of BGX()_SPU()_BR_STATUS1[BLK_LOCK]; it stays clear
                                                                 until the register is read by software.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-set
                                                                 bit, rather than latching low read-only as specified in 802.3. */
		uint64_t latched_ber                 : 1;  /**< R/W1C/H - Latched-high bit-error rate.
                                                                 0 = Not a high BER.
                                                                 1 = 64B/66B receiver is detecting a high BER.

                                                                 This is a latching-high version of BGX()_SPU()_BR_STATUS1[HI_BER]; it stays set until
                                                                 the register is read by software.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-clear
                                                                 bit, rather than latching high read-only as specified in 802.3. */
		uint64_t reserved_0_13               : 14;
#else
		uint64_t reserved_0_13               : 14;
		uint64_t latched_ber                 : 1;
		uint64_t latched_lock                : 1;
		uint64_t ber_cnt                     : 22;
		uint64_t reserved_38_39              : 2;
		uint64_t err_blks                    : 22;
		uint64_t reserved_62_63              : 2;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_status2_s  cn85xx; */
	/* struct bdk_bgxx_spux_br_status2_s  cn88xx; */
	/* struct bdk_bgxx_spux_br_status2_s  cn88xxp1; */
} bdk_bgxx_spux_br_status2_t;

static inline uint64_t BDK_BGXX_SPUX_BR_STATUS2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_STATUS2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010038ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_STATUS2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_STATUS2(...) bdk_bgxx_spux_br_status2_t
#define bustype_BDK_BGXX_SPUX_BR_STATUS2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_STATUS2(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_STATUS2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_STATUS2(...) "BGXX_SPUX_BR_STATUS2"


/**
 * RSL - bgx#_spu#_br_tp_control
 *
 * Refer to the test pattern methodology described in 802.3 sections 49.2.8 and 82.2.10.
 *
 */
typedef union bdk_bgxx_spux_br_tp_control {
	uint64_t u;
	struct bdk_bgxx_spux_br_tp_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t scramble_tp                 : 1;  /**< R/W - Select scrambled idle test pattern. This bit selects the transmit test pattern used when
                                                                 TX_TP_EN is set:
                                                                 0 = Square wave test pattern.
                                                                 1 = Scrambled idle test pattern. */
		uint64_t prbs9_tx                    : 1;  /**< RO - 10GBASE-R PRBS9 TP transmit enable. Always 0; PRBS9 pattern testing is not supported. */
		uint64_t prbs31_rx                   : 1;  /**< RO - 10GBASE-R PRBS31 TP receive enable. Always 0; PRBS31 pattern testing is not supported. */
		uint64_t prbs31_tx                   : 1;  /**< RO - 10GBASE-R PRBS31 TP transmit enable. Always 0; PRBS31 pattern is not supported. */
		uint64_t tx_tp_en                    : 1;  /**< R/W - Transmit-test-pattern enable. */
		uint64_t rx_tp_en                    : 1;  /**< R/W - Receive-test-pattern enable. The only supported receive test pattern is the scrambled idle
                                                                 test pattern. Setting this bit enables checking of that receive pattern. */
		uint64_t tp_sel                      : 1;  /**< RO/H - Square/PRBS test pattern select. Always 1 to select square wave test pattern; PRBS test
                                                                 patterns are not supported. */
		uint64_t dp_sel                      : 1;  /**< RO - Data pattern select. Always 0; PRBS test patterns are not supported. */
#else
		uint64_t dp_sel                      : 1;
		uint64_t tp_sel                      : 1;
		uint64_t rx_tp_en                    : 1;
		uint64_t tx_tp_en                    : 1;
		uint64_t prbs31_tx                   : 1;
		uint64_t prbs31_rx                   : 1;
		uint64_t prbs9_tx                    : 1;
		uint64_t scramble_tp                 : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_tp_control_s cn85xx; */
	/* struct bdk_bgxx_spux_br_tp_control_s cn88xx; */
	/* struct bdk_bgxx_spux_br_tp_control_s cn88xxp1; */
} bdk_bgxx_spux_br_tp_control_t;

static inline uint64_t BDK_BGXX_SPUX_BR_TP_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_TP_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010040ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_TP_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_TP_CONTROL(...) bdk_bgxx_spux_br_tp_control_t
#define bustype_BDK_BGXX_SPUX_BR_TP_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_TP_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_TP_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_TP_CONTROL(...) "BGXX_SPUX_BR_TP_CONTROL"


/**
 * RSL - bgx#_spu#_br_tp_err_cnt
 *
 * This register provides the BASE-R PCS test-pattern error counter.
 *
 */
typedef union bdk_bgxx_spux_br_tp_err_cnt {
	uint64_t u;
	struct bdk_bgxx_spux_br_tp_err_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t err_cnt                     : 16; /**< RC/W/H - Error counter. This 16-bit counter contains the number of errors received during a pattern
                                                                 test. These bits are reset to all 0s when this register is read by software, and they are
                                                                 held at all 1s in the case of overflow.

                                                                 The test pattern methodology is described in Std 802.3, Sections 49.2.12 and 82.2.10. This
                                                                 counter counts either block errors or bit errors dependent on the test mode (see Section
                                                                 49.2.12). The reset operation takes precedence over the increment operation; if the
                                                                 register is read on the same clock cycle as an increment operation, the counter is reset
                                                                 to all 0s and the increment operation is lost. This field is writable for test purposes,
                                                                 rather than read-only as specified in Std 802.3. */
#else
		uint64_t err_cnt                     : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_spux_br_tp_err_cnt_s cn85xx; */
	/* struct bdk_bgxx_spux_br_tp_err_cnt_s cn88xx; */
	/* struct bdk_bgxx_spux_br_tp_err_cnt_s cn88xxp1; */
} bdk_bgxx_spux_br_tp_err_cnt_t;

static inline uint64_t BDK_BGXX_SPUX_BR_TP_ERR_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BR_TP_ERR_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010048ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BR_TP_ERR_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BR_TP_ERR_CNT(...) bdk_bgxx_spux_br_tp_err_cnt_t
#define bustype_BDK_BGXX_SPUX_BR_TP_ERR_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BR_TP_ERR_CNT(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BR_TP_ERR_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BR_TP_ERR_CNT(...) "BGXX_SPUX_BR_TP_ERR_CNT"


/**
 * RSL - bgx#_spu#_bx_status
 */
typedef union bdk_bgxx_spux_bx_status {
	uint64_t u;
	struct bdk_bgxx_spux_bx_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t alignd                      : 1;  /**< RO/H - 10GBASE-X lane-alignment status.
                                                                 0 = receive lanes not aligned.
                                                                 1 = receive lanes aligned. */
		uint64_t pattst                      : 1;  /**< RO - Pattern-testing ability. Always 0; 10GBASE-X pattern is testing not supported. */
		uint64_t reserved_4_10               : 7;
		uint64_t lsync                       : 4;  /**< RO/H - Lane synchronization. BASE-X lane synchronization status for PCS lanes 3-0. Each bit is
                                                                 set when the associated lane is code-group synchronized, and clear otherwise. If the PCS
                                                                 type is RXAUI (i.e. the associated BGX()_CMR()_CONFIG[LMAC_TYPE] = RXAUI), then
                                                                 only lanes 1-0 are valid. */
#else
		uint64_t lsync                       : 4;
		uint64_t reserved_4_10               : 7;
		uint64_t pattst                      : 1;
		uint64_t alignd                      : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_spux_bx_status_s   cn85xx; */
	/* struct bdk_bgxx_spux_bx_status_s   cn88xx; */
	/* struct bdk_bgxx_spux_bx_status_s   cn88xxp1; */
} bdk_bgxx_spux_bx_status_t;

static inline uint64_t BDK_BGXX_SPUX_BX_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_BX_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010028ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_BX_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_BX_STATUS(...) bdk_bgxx_spux_bx_status_t
#define bustype_BDK_BGXX_SPUX_BX_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_BX_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_BX_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_BX_STATUS(...) "BGXX_SPUX_BX_STATUS"


/**
 * RSL - bgx#_spu#_control1
 */
typedef union bdk_bgxx_spux_control1 {
	uint64_t u;
	struct bdk_bgxx_spux_control1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t reset                       : 1;  /**< R/W1S/H - Reset. Setting this bit or BGX()_SPU()_AN_CONTROL[AN_RESET] to 1 causes the
                                                                 following to happen:
                                                                 * Resets the logical PCS (LPCS)
                                                                 * Sets the Std 802.3 PCS, FEC and AN registers for the LPCS to their default states
                                                                 * Resets the associated SerDes lanes.

                                                                 It takes up to 32 coprocessor-clock cycles to reset the LPCS, after which RESET is
                                                                 automatically cleared. */
		uint64_t loopbck                     : 1;  /**< R/W - TX-to-RX loopback enable. When set, transmit data for each SerDes lane is looped back as
                                                                 receive data. */
		uint64_t spdsel1                     : 1;  /**< RO/H - Speed select 1: always 1. */
		uint64_t reserved_12_12              : 1;
		uint64_t lo_pwr                      : 1;  /**< R/W - Low power enable. When set, the LPCS is disabled (overriding the associated
                                                                 BGX()_CMR()_CONFIG[ENABLE]), and the SerDes lanes associated with the LPCS are
                                                                 reset. */
		uint64_t reserved_7_10               : 4;
		uint64_t spdsel0                     : 1;  /**< RO/H - Speed select 0: always 1. */
		uint64_t spd                         : 4;  /**< RO - '"Speed selection.
                                                                 Note that this is a read-only field rather than read/write as
                                                                 specified in 802.3.
                                                                 The LPCS speed is instead configured by the associated
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]. The read values returned by this field are as
                                                                 follows:

                                                                 \<pre\>
                                                                   LMAC_TYPE   Speed       SPD Read Value    Comment
                                                                   ------------------------------------------------------
                                                                   XAUI        10G/20G     0x0               20G if DXAUI
                                                                   RXAUI       10G         0x0
                                                                   10G_R       10G         0x0
                                                                   40G_R       40G         0x3
                                                                   Other       -           X
                                                                 \</pre\>' */
		uint64_t reserved_0_1                : 2;
#else
		uint64_t reserved_0_1                : 2;
		uint64_t spd                         : 4;
		uint64_t spdsel0                     : 1;
		uint64_t reserved_7_10               : 4;
		uint64_t lo_pwr                      : 1;
		uint64_t reserved_12_12              : 1;
		uint64_t spdsel1                     : 1;
		uint64_t loopbck                     : 1;
		uint64_t reset                       : 1;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_spux_control1_s    cn85xx; */
	/* struct bdk_bgxx_spux_control1_s    cn88xx; */
	/* struct bdk_bgxx_spux_control1_s    cn88xxp1; */
} bdk_bgxx_spux_control1_t;

static inline uint64_t BDK_BGXX_SPUX_CONTROL1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_CONTROL1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010000ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_CONTROL1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_CONTROL1(...) bdk_bgxx_spux_control1_t
#define bustype_BDK_BGXX_SPUX_CONTROL1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_CONTROL1(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_CONTROL1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_CONTROL1(...) "BGXX_SPUX_CONTROL1"


/**
 * RSL - bgx#_spu#_control2
 */
typedef union bdk_bgxx_spux_control2 {
	uint64_t u;
	struct bdk_bgxx_spux_control2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t pcs_type                    : 3;  /**< RO/H - PCS type selection.
                                                                 Note that this is a read-only field rather than read/write as
                                                                 specified in 802.3.
                                                                 The LPCS speed is instead configured by the associated
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]. The read values returned by this field are as
                                                                 follows:

                                                                 \<pre\>
                                                                               PCS_TYPE
                                                                   LMAC_TYPE   Read Value      Comment
                                                                   -------------------------------------------------
                                                                   XAUI        0x1             10GBASE-X PCS type
                                                                   RXAUI       0x1             10GBASE-X PCS type
                                                                   10G_R       0x0             10GBASE-R PCS type
                                                                   40G_R       0x4             40GBASE-R PCS type
                                                                   Other       Undefined       Reserved
                                                                 \</pre\> */
#else
		uint64_t pcs_type                    : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_bgxx_spux_control2_s    cn85xx; */
	/* struct bdk_bgxx_spux_control2_s    cn88xx; */
	/* struct bdk_bgxx_spux_control2_s    cn88xxp1; */
} bdk_bgxx_spux_control2_t;

static inline uint64_t BDK_BGXX_SPUX_CONTROL2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_CONTROL2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010018ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_CONTROL2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_CONTROL2(...) bdk_bgxx_spux_control2_t
#define bustype_BDK_BGXX_SPUX_CONTROL2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_CONTROL2(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_CONTROL2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_CONTROL2(...) "BGXX_SPUX_CONTROL2"


/**
 * RSL - bgx#_spu#_fec_abil
 */
typedef union bdk_bgxx_spux_fec_abil {
	uint64_t u;
	struct bdk_bgxx_spux_fec_abil_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t err_abil                    : 1;  /**< RO/H - BASE-R FEC error-indication ability. Always 1 when the LPCS type is BASE-R,
                                                                 i.e. BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4. Always 0 otherwise. */
		uint64_t fec_abil                    : 1;  /**< RO/H - BASE-R FEC ability. Always 1 when the LPCS type is BASE-R,
                                                                 i.e. BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4. Always 0 otherwise. */
#else
		uint64_t fec_abil                    : 1;
		uint64_t err_abil                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_spux_fec_abil_s    cn85xx; */
	/* struct bdk_bgxx_spux_fec_abil_s    cn88xx; */
	/* struct bdk_bgxx_spux_fec_abil_s    cn88xxp1; */
} bdk_bgxx_spux_fec_abil_t;

static inline uint64_t BDK_BGXX_SPUX_FEC_ABIL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_FEC_ABIL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010098ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_FEC_ABIL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_FEC_ABIL(...) bdk_bgxx_spux_fec_abil_t
#define bustype_BDK_BGXX_SPUX_FEC_ABIL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_FEC_ABIL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_FEC_ABIL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_FEC_ABIL(...) "BGXX_SPUX_FEC_ABIL"


/**
 * RSL - bgx#_spu#_fec_control
 */
typedef union bdk_bgxx_spux_fec_control {
	uint64_t u;
	struct bdk_bgxx_spux_fec_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t err_en                      : 1;  /**< R/W - BASE-R FEC error-indication enable. This bit corresponds to FEC_Enable_Error_to_PCS
                                                                 variable for BASE-R as defined in 802.3 Clause 74. When FEC is enabled (per FEC_EN bit in
                                                                 this register) and this bit is set, the FEC decoder on the receive side signals an
                                                                 uncorrectable FEC error to the BASE-R decoder by driving a value of 2'b11 on the sync bits
                                                                 for some of the 32 64B/66B blocks belonging to the uncorrectable FEC block. See
                                                                 802.3-2008/802.3ba-2010 section 74.7.4.5.1 for more details. */
		uint64_t fec_en                      : 1;  /**< R/W - BASE-R FEC enable. When this bit is set and the LPCS type is BASE-R
                                                                 (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), forward error correction is enabled. FEC is
                                                                 disabled otherwise. Forward error correction is defined in IEEE Std
                                                                 802.3-2008/802.3ba-2010 Clause 74. */
#else
		uint64_t fec_en                      : 1;
		uint64_t err_en                      : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_bgxx_spux_fec_control_s cn85xx; */
	/* struct bdk_bgxx_spux_fec_control_s cn88xx; */
	/* struct bdk_bgxx_spux_fec_control_s cn88xxp1; */
} bdk_bgxx_spux_fec_control_t;

static inline uint64_t BDK_BGXX_SPUX_FEC_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_FEC_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100A0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_FEC_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_FEC_CONTROL(...) bdk_bgxx_spux_fec_control_t
#define bustype_BDK_BGXX_SPUX_FEC_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_FEC_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_FEC_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_FEC_CONTROL(...) "BGXX_SPUX_FEC_CONTROL"


/**
 * RSL - bgx#_spu#_fec_corr_blks01
 *
 * This register is valid only when the LPCS type is BASE-R
 * (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4). The FEC corrected-block counters are
 * defined in Std 802.3 section 74.8.4.1. Each corrected-blocks counter increments by 1 for a
 * corrected FEC block, i.e. an FEC block that has been received with invalid parity on the
 * associated PCS lane and has been corrected by the FEC decoder. The counter is reset to all 0s
 * when the register is read, and held at all 1s in case of overflow.
 *
 * The reset operation takes precedence over the increment operation; if the register is read on
 * the same clock cycle as an increment operation, the counter is reset to all 0s and the
 * increment operation is lost. The counters are writable for test purposes, rather than read-
 * only as specified in Std 802.3.
 */
typedef union bdk_bgxx_spux_fec_corr_blks01 {
	uint64_t u;
	struct bdk_bgxx_spux_fec_corr_blks01_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln1_corr_blks               : 32; /**< RC/W/H - PCS Lane 1 FEC corrected blocks.
                                                                 * For 10GBASE-R, reserved.
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_corrected_blocks_counter_1 variable
                                                                 (registers 1.302-1.303). */
		uint64_t ln0_corr_blks               : 32; /**< RC/W/H - PCS Lane 0 FEC corrected blocks.
                                                                 * For 10GBASE-R, corresponds to the Std 802.3 FEC_corrected_blocks_counter variable
                                                                 (registers 1.172-1.173).
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_corrected_blocks_counter_0 variable
                                                                 (registers 1.300-1.301). */
#else
		uint64_t ln0_corr_blks               : 32;
		uint64_t ln1_corr_blks               : 32;
#endif
	} s;
	/* struct bdk_bgxx_spux_fec_corr_blks01_s cn85xx; */
	/* struct bdk_bgxx_spux_fec_corr_blks01_s cn88xx; */
	/* struct bdk_bgxx_spux_fec_corr_blks01_s cn88xxp1; */
} bdk_bgxx_spux_fec_corr_blks01_t;

static inline uint64_t BDK_BGXX_SPUX_FEC_CORR_BLKS01(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_FEC_CORR_BLKS01(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100A8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_FEC_CORR_BLKS01", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_FEC_CORR_BLKS01(...) bdk_bgxx_spux_fec_corr_blks01_t
#define bustype_BDK_BGXX_SPUX_FEC_CORR_BLKS01(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_FEC_CORR_BLKS01(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_FEC_CORR_BLKS01(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_FEC_CORR_BLKS01(...) "BGXX_SPUX_FEC_CORR_BLKS01"


/**
 * RSL - bgx#_spu#_fec_corr_blks23
 *
 * This register is valid only when the LPCS type is 40GBASE-R
 * (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4). The FEC corrected-block counters are defined in
 * Std 802.3 section 74.8.4.1. Each corrected-blocks counter increments by 1 for a corrected FEC
 * block, i.e. an FEC block that has been received with invalid parity on the associated PCS lane
 * and has been corrected by the FEC decoder. The counter is reset to all 0s when the register is
 * read, and held at all 1s in case of overflow.
 *
 * The reset operation takes precedence over the increment operation; if the register is read on
 * the same clock cycle as an increment operation, the counter is reset to all 0s and the
 * increment operation is lost. The counters are writable for test purposes, rather than read-
 * only as specified in Std 802.3.
 */
typedef union bdk_bgxx_spux_fec_corr_blks23 {
	uint64_t u;
	struct bdk_bgxx_spux_fec_corr_blks23_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln3_corr_blks               : 32; /**< RC/W/H - PCS Lane 3 FEC corrected blocks. Correspond to the Std 802.3
                                                                 FEC_corrected_blocks_counter_3 variable (registers 1.306-1.307). */
		uint64_t ln2_corr_blks               : 32; /**< RC/W/H - PCS Lane 2 FEC corrected blocks. Correspond to the Std 802.3
                                                                 FEC_corrected_blocks_counter_3 variable (registers 1.304-1.305). */
#else
		uint64_t ln2_corr_blks               : 32;
		uint64_t ln3_corr_blks               : 32;
#endif
	} s;
	/* struct bdk_bgxx_spux_fec_corr_blks23_s cn85xx; */
	/* struct bdk_bgxx_spux_fec_corr_blks23_s cn88xx; */
	/* struct bdk_bgxx_spux_fec_corr_blks23_s cn88xxp1; */
} bdk_bgxx_spux_fec_corr_blks23_t;

static inline uint64_t BDK_BGXX_SPUX_FEC_CORR_BLKS23(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_FEC_CORR_BLKS23(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100B0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_FEC_CORR_BLKS23", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_FEC_CORR_BLKS23(...) bdk_bgxx_spux_fec_corr_blks23_t
#define bustype_BDK_BGXX_SPUX_FEC_CORR_BLKS23(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_FEC_CORR_BLKS23(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_FEC_CORR_BLKS23(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_FEC_CORR_BLKS23(...) "BGXX_SPUX_FEC_CORR_BLKS23"


/**
 * RSL - bgx#_spu#_fec_uncorr_blks01
 *
 * This register is valid only when the LPCS type is BASE-R
 * (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4). The FEC corrected-block counters are
 * defined in Std 802.3 section 74.8.4.2. Each uncorrected-blocks counter increments by 1 for an
 * uncorrected FEC block, i.e. an FEC block that has been received with invalid parity on the
 * associated PCS lane and has not been corrected by the FEC decoder. The counter is reset to all
 * 0s when the register is read, and held at all 1s in case of overflow.
 *
 * The reset operation takes precedence over the increment operation; if the register is read on
 * the same clock cycle as an increment operation, the counter is reset to all 0s and the
 * increment operation is lost. The counters are writable for test purposes, rather than read-
 * only as specified in Std 802.3.
 */
typedef union bdk_bgxx_spux_fec_uncorr_blks01 {
	uint64_t u;
	struct bdk_bgxx_spux_fec_uncorr_blks01_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln1_uncorr_blks             : 32; /**< RC/W/H - PCS Lane 1 FEC corrected blocks.
                                                                 * For 10GBASE-R, reserved.
                                                                 * For 40GBASE-R, corresponds to the Std 802.3 FEC_uncorrected_blocks_counter_1 variable
                                                                 (registers 1.702-1.703). */
		uint64_t ln0_uncorr_blks             : 32; /**< RC/W/H - PCS Lane 0 FEC uncorrected blocks.
                                                                 * For 10GBASE-R, corresponds to the Std 802.3 FEC_uncorrected_blocks_counter variable
                                                                 (registers 1.174-1.175).
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_uncorrected_blocks_counter_0 variable
                                                                 (registers 1.700-1.701). */
#else
		uint64_t ln0_uncorr_blks             : 32;
		uint64_t ln1_uncorr_blks             : 32;
#endif
	} s;
	/* struct bdk_bgxx_spux_fec_uncorr_blks01_s cn85xx; */
	/* struct bdk_bgxx_spux_fec_uncorr_blks01_s cn88xx; */
	/* struct bdk_bgxx_spux_fec_uncorr_blks01_s cn88xxp1; */
} bdk_bgxx_spux_fec_uncorr_blks01_t;

static inline uint64_t BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100B8ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_FEC_UNCORR_BLKS01", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(...) bdk_bgxx_spux_fec_uncorr_blks01_t
#define bustype_BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_FEC_UNCORR_BLKS01(...) "BGXX_SPUX_FEC_UNCORR_BLKS01"


/**
 * RSL - bgx#_spu#_fec_uncorr_blks23
 *
 * This register is valid only when the LPCS type is 40GBASE-R
 * (BGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4). The FEC uncorrected-block counters are defined
 * in Std 802.3 section 74.8.4.2. Each corrected-blocks counter increments by 1 for an
 * uncorrected FEC block, i.e. an FEC block that has been received with invalid parity on the
 * associated PCS lane and has not been corrected by the FEC decoder. The counter is reset to all
 * 0s when the register is read, and held at all 1s in case of overflow.
 *
 * The reset operation takes precedence over the increment operation; if the register is read on
 * the same clock cycle as an increment operation, the counter is reset to all 0s and the
 * increment operation is lost. The counters are writable for test purposes, rather than read-
 * only as specified in Std 802.3.
 */
typedef union bdk_bgxx_spux_fec_uncorr_blks23 {
	uint64_t u;
	struct bdk_bgxx_spux_fec_uncorr_blks23_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ln3_uncorr_blks             : 32; /**< RC/W/H - PCS Lane 3 FEC uncorrected blocks. Corresponds to the Std 802.3
                                                                 FEC_uncorrected_blocks_counter_3 variable (registers 1.706-1.707). */
		uint64_t ln2_uncorr_blks             : 32; /**< RC/W/H - PCS Lane 2 FEC uncorrected blocks. Corresponds to the Std 802.3
                                                                 FEC_uncorrected_blocks_counter_3 variable (registers 1.704-1.705). */
#else
		uint64_t ln2_uncorr_blks             : 32;
		uint64_t ln3_uncorr_blks             : 32;
#endif
	} s;
	/* struct bdk_bgxx_spux_fec_uncorr_blks23_s cn85xx; */
	/* struct bdk_bgxx_spux_fec_uncorr_blks23_s cn88xx; */
	/* struct bdk_bgxx_spux_fec_uncorr_blks23_s cn88xxp1; */
} bdk_bgxx_spux_fec_uncorr_blks23_t;

static inline uint64_t BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E00100C0ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_FEC_UNCORR_BLKS23", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(...) bdk_bgxx_spux_fec_uncorr_blks23_t
#define bustype_BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_FEC_UNCORR_BLKS23(...) "BGXX_SPUX_FEC_UNCORR_BLKS23"


/**
 * RSL - bgx#_spu#_int
 */
typedef union bdk_bgxx_spux_int {
	uint64_t u;
	struct bdk_bgxx_spux_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t training_failure            : 1;  /**< R/W1C/H - BASE-R PMD training failure. Set when BASE-R PMD link training has failed on the 10GBASE-R
                                                                 lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t training_done               : 1;  /**< R/W1C/H - BASE-R PMD training done. Set when the 10GBASE-R lane or all 40GBASE-R lanes have
                                                                 successfully completed BASE-R PMD link training. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t an_complete                 : 1;  /**< R/W1C/H - Autonegotiation complete. Set when BGX()_SPU()_AN_STATUS[AN_COMPLETE] is set,
                                                                 indicating that the autonegotiation process has been completed and the link is up and
                                                                 running using the negotiated highest common denominator (HCD) technology. */
		uint64_t an_link_good                : 1;  /**< R/W1C/H - Autonegotiation link good. Set when the an_link_good variable is set as defined in
                                                                 802.3-2008 Figure 73-11, indicating that autonegotiation has completed. */
		uint64_t an_page_rx                  : 1;  /**< R/W1C/H - Autonegotiation page received. This bit is set along with
                                                                 BGX()_SPU()_AN_STATUS[PAGE_RX] when a new page has been received and stored in
                                                                 BGX()_SPU()_AN_LP_BASE or BGX()_SPU()_AN_LP_XNP. */
		uint64_t fec_uncorr                  : 1;  /**< R/W1C/H - Uncorrectable FEC error. Set when an FEC block with an uncorrectable error is received on
                                                                 the 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t fec_corr                    : 1;  /**< R/W1C/H - Correctable FEC error. Set when an FEC block with a correctable error is received on the
                                                                 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t bip_err                     : 1;  /**< R/W1C/H - 40GBASE-R bit interleaved parity error. Set when a BIP error is detected on any lane.
                                                                 Valid if the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE] is 40GBASE-R, and
                                                                 never set otherwise. */
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Sync failure debug. This interrupt is provided for link problem debugging help. It is set
                                                                 as follows based on the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE], and
                                                                 whether FEC is enabled or disabled by BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions from
                                                                 SYNC_ACQUIRED_1 to SYNC_ACQUIRED_2 (see 802.3-2008 Figure 48-7).
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: Set when sh_invalid_cnt increments to 1 while
                                                                 block_lock is 1 (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: Set when parity_invalid_cnt increments to 1
                                                                 while fec_block_lock is 1 (see 802.3-2008 Figure 74-8). */
		uint64_t algnlos                     : 1;  /**< R/W1C/H - Loss of lane alignment. Set when lane-to-lane alignment is lost. This is only valid if the
                                                                 logical PCS is a multilane type (i.e. XAUI, RXAUI or 40GBASE-R is selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]), and is never set otherwise. */
		uint64_t synlos                      : 1;  /**< R/W1C/H - Loss of lane sync. Lane code-group or block synchronization is lost on one or more lanes
                                                                 associated with the LMAC/LPCS. Set as follows based on the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE], and whether FEC is enabled or disabled by
                                                                 BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions to LOSS_OF_SYNC
                                                                 (see 802.3-2008 Figure 48-7)
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: set when the block_lock variable is cleared on
                                                                 the 10G lane or any 40G lane (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: set when the fec_block_lock variable is cleared
                                                                 on the 10G lane or any 40G lane (see 802.3-2008 Figure 74-8). */
		uint64_t bitlckls                    : 1;  /**< R/W1C/H - Bit lock lost on one or more lanes associated with the LMAC/LPCS. */
		uint64_t err_blk                     : 1;  /**< R/W1C/H - Errored block received. Set when an errored BASE-R block is received as described for
                                                                 BGX()_SPU()_BR_STATUS2[ERR_BLKS]. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t rx_link_down                : 1;  /**< R/W1C/H - Set when the receive link goes down, which is the same condition that sets
                                                                 BGX()_SPU()_STATUS2[RCVFLT]. */
		uint64_t rx_link_up                  : 1;  /**< R/W1C/H - Set when the receive link comes up, which is the same condition that allows the setting of
                                                                 BGX()_SPU()_STATUS1[RCV_LNK]. */
#else
		uint64_t rx_link_up                  : 1;
		uint64_t rx_link_down                : 1;
		uint64_t err_blk                     : 1;
		uint64_t bitlckls                    : 1;
		uint64_t synlos                      : 1;
		uint64_t algnlos                     : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t bip_err                     : 1;
		uint64_t fec_corr                    : 1;
		uint64_t fec_uncorr                  : 1;
		uint64_t an_page_rx                  : 1;
		uint64_t an_link_good                : 1;
		uint64_t an_complete                 : 1;
		uint64_t training_done               : 1;
		uint64_t training_failure            : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_spux_int_s         cn85xx; */
	/* struct bdk_bgxx_spux_int_s         cn88xx; */
	/* struct bdk_bgxx_spux_int_s         cn88xxp1; */
} bdk_bgxx_spux_int_t;

static inline uint64_t BDK_BGXX_SPUX_INT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_INT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010220ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_INT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_INT(...) bdk_bgxx_spux_int_t
#define bustype_BDK_BGXX_SPUX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_INT(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_INT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_INT(...) "BGXX_SPUX_INT"


/**
 * RSL - bgx#_spu#_int_ena_w1c
 */
typedef union bdk_bgxx_spux_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_spux_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t training_failure            : 1;  /**< R/W1C/H - BASE-R PMD training failure. Set when BASE-R PMD link training has failed on the 10GBASE-R
                                                                 lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t training_done               : 1;  /**< R/W1C/H - BASE-R PMD training done. Set when the 10GBASE-R lane or all 40GBASE-R lanes have
                                                                 successfully completed BASE-R PMD link training. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t an_complete                 : 1;  /**< R/W1C/H - Autonegotiation complete. Set when BGX()_SPU()_AN_STATUS[AN_COMPLETE] is set,
                                                                 indicating that the autonegotiation process has been completed and the link is up and
                                                                 running using the negotiated highest common denominator (HCD) technology. */
		uint64_t an_link_good                : 1;  /**< R/W1C/H - Autonegotiation link good. Set when the an_link_good variable is set as defined in
                                                                 802.3-2008 Figure 73-11, indicating that autonegotiation has completed. */
		uint64_t an_page_rx                  : 1;  /**< R/W1C/H - Autonegotiation page received. This bit is set along with
                                                                 BGX()_SPU()_AN_STATUS[PAGE_RX] when a new page has been received and stored in
                                                                 BGX()_SPU()_AN_LP_BASE or BGX()_SPU()_AN_LP_XNP. */
		uint64_t fec_uncorr                  : 1;  /**< R/W1C/H - Uncorrectable FEC error. Set when an FEC block with an uncorrectable error is received on
                                                                 the 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t fec_corr                    : 1;  /**< R/W1C/H - Correctable FEC error. Set when an FEC block with a correctable error is received on the
                                                                 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t bip_err                     : 1;  /**< R/W1C/H - 40GBASE-R bit interleaved parity error. Set when a BIP error is detected on any lane.
                                                                 Valid if the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE] is 40GBASE-R, and
                                                                 never set otherwise. */
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Sync failure debug. This interrupt is provided for link problem debugging help. It is set
                                                                 as follows based on the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE], and
                                                                 whether FEC is enabled or disabled by BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions from
                                                                 SYNC_ACQUIRED_1 to SYNC_ACQUIRED_2 (see 802.3-2008 Figure 48-7).
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: Set when sh_invalid_cnt increments to 1 while
                                                                 block_lock is 1 (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: Set when parity_invalid_cnt increments to 1
                                                                 while fec_block_lock is 1 (see 802.3-2008 Figure 74-8). */
		uint64_t algnlos                     : 1;  /**< R/W1C/H - Loss of lane alignment. Set when lane-to-lane alignment is lost. This is only valid if the
                                                                 logical PCS is a multilane type (i.e. XAUI, RXAUI or 40GBASE-R is selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]), and is never set otherwise. */
		uint64_t synlos                      : 1;  /**< R/W1C/H - Loss of lane sync. Lane code-group or block synchronization is lost on one or more lanes
                                                                 associated with the LMAC/LPCS. Set as follows based on the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE], and whether FEC is enabled or disabled by
                                                                 BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions to LOSS_OF_SYNC
                                                                 (see 802.3-2008 Figure 48-7)
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: set when the block_lock variable is cleared on
                                                                 the 10G lane or any 40G lane (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: set when the fec_block_lock variable is cleared
                                                                 on the 10G lane or any 40G lane (see 802.3-2008 Figure 74-8). */
		uint64_t bitlckls                    : 1;  /**< R/W1C/H - Bit lock lost on one or more lanes associated with the LMAC/LPCS. */
		uint64_t err_blk                     : 1;  /**< R/W1C/H - Errored block received. Set when an errored BASE-R block is received as described for
                                                                 BGX()_SPU()_BR_STATUS2[ERR_BLKS]. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t rx_link_down                : 1;  /**< R/W1C/H - Set when the receive link goes down, which is the same condition that sets
                                                                 BGX()_SPU()_STATUS2[RCVFLT]. */
		uint64_t rx_link_up                  : 1;  /**< R/W1C/H - Set when the receive link comes up, which is the same condition that allows the setting of
                                                                 BGX()_SPU()_STATUS1[RCV_LNK]. */
#else
		uint64_t rx_link_up                  : 1;
		uint64_t rx_link_down                : 1;
		uint64_t err_blk                     : 1;
		uint64_t bitlckls                    : 1;
		uint64_t synlos                      : 1;
		uint64_t algnlos                     : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t bip_err                     : 1;
		uint64_t fec_corr                    : 1;
		uint64_t fec_uncorr                  : 1;
		uint64_t an_page_rx                  : 1;
		uint64_t an_link_good                : 1;
		uint64_t an_complete                 : 1;
		uint64_t training_done               : 1;
		uint64_t training_failure            : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_spux_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_spux_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_spux_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_spux_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_SPUX_INT_ENA_W1C(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_INT_ENA_W1C(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010230ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_INT_ENA_W1C", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_INT_ENA_W1C(...) bdk_bgxx_spux_int_ena_w1c_t
#define bustype_BDK_BGXX_SPUX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_INT_ENA_W1C(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_INT_ENA_W1C(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_INT_ENA_W1C(...) "BGXX_SPUX_INT_ENA_W1C"


/**
 * RSL - bgx#_spu#_int_ena_w1s
 */
typedef union bdk_bgxx_spux_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_spux_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t training_failure            : 1;  /**< R/W1C/H - BASE-R PMD training failure. Set when BASE-R PMD link training has failed on the 10GBASE-R
                                                                 lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t training_done               : 1;  /**< R/W1C/H - BASE-R PMD training done. Set when the 10GBASE-R lane or all 40GBASE-R lanes have
                                                                 successfully completed BASE-R PMD link training. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t an_complete                 : 1;  /**< R/W1C/H - Autonegotiation complete. Set when BGX()_SPU()_AN_STATUS[AN_COMPLETE] is set,
                                                                 indicating that the autonegotiation process has been completed and the link is up and
                                                                 running using the negotiated highest common denominator (HCD) technology. */
		uint64_t an_link_good                : 1;  /**< R/W1C/H - Autonegotiation link good. Set when the an_link_good variable is set as defined in
                                                                 802.3-2008 Figure 73-11, indicating that autonegotiation has completed. */
		uint64_t an_page_rx                  : 1;  /**< R/W1C/H - Autonegotiation page received. This bit is set along with
                                                                 BGX()_SPU()_AN_STATUS[PAGE_RX] when a new page has been received and stored in
                                                                 BGX()_SPU()_AN_LP_BASE or BGX()_SPU()_AN_LP_XNP. */
		uint64_t fec_uncorr                  : 1;  /**< R/W1C/H - Uncorrectable FEC error. Set when an FEC block with an uncorrectable error is received on
                                                                 the 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t fec_corr                    : 1;  /**< R/W1C/H - Correctable FEC error. Set when an FEC block with a correctable error is received on the
                                                                 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t bip_err                     : 1;  /**< R/W1C/H - 40GBASE-R bit interleaved parity error. Set when a BIP error is detected on any lane.
                                                                 Valid if the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE] is 40GBASE-R, and
                                                                 never set otherwise. */
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Sync failure debug. This interrupt is provided for link problem debugging help. It is set
                                                                 as follows based on the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE], and
                                                                 whether FEC is enabled or disabled by BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions from
                                                                 SYNC_ACQUIRED_1 to SYNC_ACQUIRED_2 (see 802.3-2008 Figure 48-7).
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: Set when sh_invalid_cnt increments to 1 while
                                                                 block_lock is 1 (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: Set when parity_invalid_cnt increments to 1
                                                                 while fec_block_lock is 1 (see 802.3-2008 Figure 74-8). */
		uint64_t algnlos                     : 1;  /**< R/W1C/H - Loss of lane alignment. Set when lane-to-lane alignment is lost. This is only valid if the
                                                                 logical PCS is a multilane type (i.e. XAUI, RXAUI or 40GBASE-R is selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]), and is never set otherwise. */
		uint64_t synlos                      : 1;  /**< R/W1C/H - Loss of lane sync. Lane code-group or block synchronization is lost on one or more lanes
                                                                 associated with the LMAC/LPCS. Set as follows based on the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE], and whether FEC is enabled or disabled by
                                                                 BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions to LOSS_OF_SYNC
                                                                 (see 802.3-2008 Figure 48-7)
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: set when the block_lock variable is cleared on
                                                                 the 10G lane or any 40G lane (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: set when the fec_block_lock variable is cleared
                                                                 on the 10G lane or any 40G lane (see 802.3-2008 Figure 74-8). */
		uint64_t bitlckls                    : 1;  /**< R/W1C/H - Bit lock lost on one or more lanes associated with the LMAC/LPCS. */
		uint64_t err_blk                     : 1;  /**< R/W1C/H - Errored block received. Set when an errored BASE-R block is received as described for
                                                                 BGX()_SPU()_BR_STATUS2[ERR_BLKS]. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t rx_link_down                : 1;  /**< R/W1C/H - Set when the receive link goes down, which is the same condition that sets
                                                                 BGX()_SPU()_STATUS2[RCVFLT]. */
		uint64_t rx_link_up                  : 1;  /**< R/W1C/H - Set when the receive link comes up, which is the same condition that allows the setting of
                                                                 BGX()_SPU()_STATUS1[RCV_LNK]. */
#else
		uint64_t rx_link_up                  : 1;
		uint64_t rx_link_down                : 1;
		uint64_t err_blk                     : 1;
		uint64_t bitlckls                    : 1;
		uint64_t synlos                      : 1;
		uint64_t algnlos                     : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t bip_err                     : 1;
		uint64_t fec_corr                    : 1;
		uint64_t fec_uncorr                  : 1;
		uint64_t an_page_rx                  : 1;
		uint64_t an_link_good                : 1;
		uint64_t an_complete                 : 1;
		uint64_t training_done               : 1;
		uint64_t training_failure            : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_spux_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_spux_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_spux_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_spux_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_SPUX_INT_ENA_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_INT_ENA_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010238ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_INT_ENA_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_INT_ENA_W1S(...) bdk_bgxx_spux_int_ena_w1s_t
#define bustype_BDK_BGXX_SPUX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_INT_ENA_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_INT_ENA_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_INT_ENA_W1S(...) "BGXX_SPUX_INT_ENA_W1S"


/**
 * RSL - bgx#_spu#_int_w1s
 */
typedef union bdk_bgxx_spux_int_w1s {
	uint64_t u;
	struct bdk_bgxx_spux_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t training_failure            : 1;  /**< R/W1C/H - BASE-R PMD training failure. Set when BASE-R PMD link training has failed on the 10GBASE-R
                                                                 lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t training_done               : 1;  /**< R/W1C/H - BASE-R PMD training done. Set when the 10GBASE-R lane or all 40GBASE-R lanes have
                                                                 successfully completed BASE-R PMD link training. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
		uint64_t an_complete                 : 1;  /**< R/W1C/H - Autonegotiation complete. Set when BGX()_SPU()_AN_STATUS[AN_COMPLETE] is set,
                                                                 indicating that the autonegotiation process has been completed and the link is up and
                                                                 running using the negotiated highest common denominator (HCD) technology. */
		uint64_t an_link_good                : 1;  /**< R/W1C/H - Autonegotiation link good. Set when the an_link_good variable is set as defined in
                                                                 802.3-2008 Figure 73-11, indicating that autonegotiation has completed. */
		uint64_t an_page_rx                  : 1;  /**< R/W1C/H - Autonegotiation page received. This bit is set along with
                                                                 BGX()_SPU()_AN_STATUS[PAGE_RX] when a new page has been received and stored in
                                                                 BGX()_SPU()_AN_LP_BASE or BGX()_SPU()_AN_LP_XNP. */
		uint64_t fec_uncorr                  : 1;  /**< R/W1C/H - Uncorrectable FEC error. Set when an FEC block with an uncorrectable error is received on
                                                                 the 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t fec_corr                    : 1;  /**< R/W1C/H - Correctable FEC error. Set when an FEC block with a correctable error is received on the
                                                                 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t bip_err                     : 1;  /**< R/W1C/H - 40GBASE-R bit interleaved parity error. Set when a BIP error is detected on any lane.
                                                                 Valid if the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE] is 40GBASE-R, and
                                                                 never set otherwise. */
		uint64_t dbg_sync                    : 1;  /**< R/W1C/H - Sync failure debug. This interrupt is provided for link problem debugging help. It is set
                                                                 as follows based on the LPCS type selected by BGX()_CMR()_CONFIG[LMAC_TYPE], and
                                                                 whether FEC is enabled or disabled by BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions from
                                                                 SYNC_ACQUIRED_1 to SYNC_ACQUIRED_2 (see 802.3-2008 Figure 48-7).
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: Set when sh_invalid_cnt increments to 1 while
                                                                 block_lock is 1 (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: Set when parity_invalid_cnt increments to 1
                                                                 while fec_block_lock is 1 (see 802.3-2008 Figure 74-8). */
		uint64_t algnlos                     : 1;  /**< R/W1C/H - Loss of lane alignment. Set when lane-to-lane alignment is lost. This is only valid if the
                                                                 logical PCS is a multilane type (i.e. XAUI, RXAUI or 40GBASE-R is selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE]), and is never set otherwise. */
		uint64_t synlos                      : 1;  /**< R/W1C/H - Loss of lane sync. Lane code-group or block synchronization is lost on one or more lanes
                                                                 associated with the LMAC/LPCS. Set as follows based on the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE], and whether FEC is enabled or disabled by
                                                                 BGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions to LOSS_OF_SYNC
                                                                 (see 802.3-2008 Figure 48-7)
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: set when the block_lock variable is cleared on
                                                                 the 10G lane or any 40G lane (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: set when the fec_block_lock variable is cleared
                                                                 on the 10G lane or any 40G lane (see 802.3-2008 Figure 74-8). */
		uint64_t bitlckls                    : 1;  /**< R/W1C/H - Bit lock lost on one or more lanes associated with the LMAC/LPCS. */
		uint64_t err_blk                     : 1;  /**< R/W1C/H - Errored block received. Set when an errored BASE-R block is received as described for
                                                                 BGX()_SPU()_BR_STATUS2[ERR_BLKS]. Valid if the LPCS type selected by
                                                                 BGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
		uint64_t rx_link_down                : 1;  /**< R/W1C/H - Set when the receive link goes down, which is the same condition that sets
                                                                 BGX()_SPU()_STATUS2[RCVFLT]. */
		uint64_t rx_link_up                  : 1;  /**< R/W1C/H - Set when the receive link comes up, which is the same condition that allows the setting of
                                                                 BGX()_SPU()_STATUS1[RCV_LNK]. */
#else
		uint64_t rx_link_up                  : 1;
		uint64_t rx_link_down                : 1;
		uint64_t err_blk                     : 1;
		uint64_t bitlckls                    : 1;
		uint64_t synlos                      : 1;
		uint64_t algnlos                     : 1;
		uint64_t dbg_sync                    : 1;
		uint64_t bip_err                     : 1;
		uint64_t fec_corr                    : 1;
		uint64_t fec_uncorr                  : 1;
		uint64_t an_page_rx                  : 1;
		uint64_t an_link_good                : 1;
		uint64_t an_complete                 : 1;
		uint64_t training_done               : 1;
		uint64_t training_failure            : 1;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_spux_int_w1s_s     cn85xx; */
	/* struct bdk_bgxx_spux_int_w1s_s     cn88xx; */
	/* struct bdk_bgxx_spux_int_w1s_s     cn88xxp1; */
} bdk_bgxx_spux_int_w1s_t;

static inline uint64_t BDK_BGXX_SPUX_INT_W1S(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_INT_W1S(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010228ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_INT_W1S", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_INT_W1S(...) bdk_bgxx_spux_int_w1s_t
#define bustype_BDK_BGXX_SPUX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_INT_W1S(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_INT_W1S(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_INT_W1S(...) "BGXX_SPUX_INT_W1S"


/**
 * RSL - bgx#_spu#_lpcs_states
 */
typedef union bdk_bgxx_spux_lpcs_states {
	uint64_t u;
	struct bdk_bgxx_spux_lpcs_states_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t br_rx_sm                    : 3;  /**< RO/H - BASE-R receive state machine state */
		uint64_t reserved_10_11              : 2;
		uint64_t bx_rx_sm                    : 2;  /**< RO/H - BASE-X receive state machine state */
		uint64_t deskew_am_found             : 4;  /**< RO/H - 40GBASE-R deskew state machine alignment marker found flag per logical PCS lane ID. */
		uint64_t reserved_3_3                : 1;
		uint64_t deskew_sm                   : 3;  /**< RO/H - BASE-X and 40GBASE-R deskew state machine state */
#else
		uint64_t deskew_sm                   : 3;
		uint64_t reserved_3_3                : 1;
		uint64_t deskew_am_found             : 4;
		uint64_t bx_rx_sm                    : 2;
		uint64_t reserved_10_11              : 2;
		uint64_t br_rx_sm                    : 3;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_bgxx_spux_lpcs_states_s cn85xx; */
	/* struct bdk_bgxx_spux_lpcs_states_s cn88xx; */
	/* struct bdk_bgxx_spux_lpcs_states_s cn88xxp1; */
} bdk_bgxx_spux_lpcs_states_t;

static inline uint64_t BDK_BGXX_SPUX_LPCS_STATES(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_LPCS_STATES(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010208ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_LPCS_STATES", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_LPCS_STATES(...) bdk_bgxx_spux_lpcs_states_t
#define bustype_BDK_BGXX_SPUX_LPCS_STATES(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_LPCS_STATES(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_LPCS_STATES(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_LPCS_STATES(...) "BGXX_SPUX_LPCS_STATES"


/**
 * RSL - bgx#_spu#_misc_control
 *
 * "* RX logical PCS lane polarity vector [3:0] = XOR_RXPLRT[3:0] ^ {4{RXPLRT}}.
 * * TX logical PCS lane polarity vector [3:0] = XOR_TXPLRT[3:0] ^ {4{TXPLRT}}.
 *
 * In short, keep RXPLRT and TXPLRT cleared, and use XOR_RXPLRT and XOR_TXPLRT fields to define
 * the polarity per logical PCS lane. Only bit 0 of vector is used for 10GBASE-R, and only bits
 * 1:0 of vector are used for RXAUI."
 */
typedef union bdk_bgxx_spux_misc_control {
	uint64_t u;
	struct bdk_bgxx_spux_misc_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t rx_packet_dis               : 1;  /**< R/W - Receive packet disable. Software can set or clear this bit at any time to gracefully
                                                                 disable or re-enable packet reception by the LPCS. If this bit is set while a packet is
                                                                 being received, the packet is completed and all subsequent received packets are discarded
                                                                 by the LPCS. Similarly, if this bit is cleared while a received packet is being discarded,
                                                                 packet reception resumes after the current packet is fully discarded. When set for a
                                                                 40GBASE-R or 10GBASE-R LMAC/LPCS type (selected by BGX()_CMR()_CONFIG[LMAC_TYPE]),
                                                                 received errors and faults will be ignored while receive packets are discarded; idles will
                                                                 be sent to the MAC layer (SMU) and the errored blocks counter
                                                                 (BGX()_SPU()_BR_STATUS2[ERR_BLKS]) will not increment. */
		uint64_t skip_after_term             : 1;  /**< R/W - Enable sending of Idle Skip after Terminate. This bit is meaningful when the logical PCS
                                                                 type is XAUI or RXAUI (selected by BGX()_CMR()_CONFIG[LMAC_TYPE]), and has no
                                                                 effect otherwise. When set, the LMAC/LPCS transmits more Idle Skip columns for clock
                                                                 compensation. Typically set in HiGig/HiGig2 modes; clear otherwise. This field can be set
                                                                 to ensure sufficient density of XAUI Idle Skip (||R||) columns with a small transmit
                                                                 inter-frame gap (IFG) in order to allow the link partner's receiver to delete ||R||
                                                                 columns as needed for clock rate compensation. It is usually set when the LMAC's transmit
                                                                 IFG is set to 8 bytes in HiGig/HiGig2 modes (i.e. BGX()_SMU()_TX_IFG[IFG1] +
                                                                 BGX()_SMU()_TX_IFG[IFG2] = 8), and should be cleared when the transmit IFG is
                                                                 greater than 8 bytes. When this bit is set, the SPU will send an ||R|| column after a
                                                                 ||T0|| column (terminate in lane 0) if no ||R|| was sent in the previous IFG. This is a
                                                                 minor deviation from the functionality specified in 802.3-2008 Figure 48-6 (PCS transmit
                                                                 source state diagram), whereby the state will transition directly from SEND_DATA to
                                                                 SEND_RANDOM_R after ||T0|| if no ||R|| was transmitted in the previous IFG. Sending ||R||
                                                                 after ||T0|| only (and not ||T1||, |T2|| or ||T3||) ensures that the check_end function at
                                                                 the receiving end, as defined in 802.3-2008 sub-clause 48.2.6.1.4, does not detect an
                                                                 error due to this functional change. When this bit is clear, the LMAC will fully conform
                                                                 to the functionality specified in Figure 48-6. */
		uint64_t intlv_rdisp                 : 1;  /**< R/W - RXAUI interleaved running disparity. This bit is meaningful when the logical PCS type is
                                                                 RXAUI (BGX()_CMR()_CONFIG[LMAC_TYPE] = RXAUI), and has no effect otherwise. It
                                                                 selects which disparity calculation to use when combining or splitting the RXAUI lanes, as
                                                                 follows:

                                                                 _ 0 = Common running disparity. Common running disparity is computed for even and odd
                                                                 code-
                                                                 groups of an RXAUI lane, i.e. interleave lanes before PCS layer as described in the Dune
                                                                 Networks/Broadcom RXAUI v2.1 specification. This obeys 6.25GHz SerDes disparity.

                                                                 _ 1 = Interleaved running disparity: Running disparity is computed separately for even and
                                                                 odd code-groups of an RXAUI lane, i.e. interleave lanes after PCS layer as described in
                                                                 the Marvell RXAUI Interface specification. This does not obey 6.25GHz SerDes disparity. */
		uint64_t xor_rxplrt                  : 4;  /**< R/W - RX polarity control per logical PCS lane */
		uint64_t xor_txplrt                  : 4;  /**< R/W - TX polarity control per logical PCS lane */
		uint64_t rxplrt                      : 1;  /**< R/W - Receive polarity. 1 = inverted polarity, 0 = normal polarity. */
		uint64_t txplrt                      : 1;  /**< R/W - Transmit polarity. 1 = inverted polarity, 0 = normal polarity. */
#else
		uint64_t txplrt                      : 1;
		uint64_t rxplrt                      : 1;
		uint64_t xor_txplrt                  : 4;
		uint64_t xor_rxplrt                  : 4;
		uint64_t intlv_rdisp                 : 1;
		uint64_t skip_after_term             : 1;
		uint64_t rx_packet_dis               : 1;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_bgxx_spux_misc_control_s cn85xx; */
	/* struct bdk_bgxx_spux_misc_control_s cn88xx; */
	/* struct bdk_bgxx_spux_misc_control_s cn88xxp1; */
} bdk_bgxx_spux_misc_control_t;

static inline uint64_t BDK_BGXX_SPUX_MISC_CONTROL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_MISC_CONTROL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010218ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_MISC_CONTROL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_MISC_CONTROL(...) bdk_bgxx_spux_misc_control_t
#define bustype_BDK_BGXX_SPUX_MISC_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_MISC_CONTROL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_MISC_CONTROL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_MISC_CONTROL(...) "BGXX_SPUX_MISC_CONTROL"


/**
 * RSL - bgx#_spu#_spd_abil
 */
typedef union bdk_bgxx_spux_spd_abil {
	uint64_t u;
	struct bdk_bgxx_spux_spd_abil_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t hundredgb                   : 1;  /**< RO - 100G capable. Always 0. */
		uint64_t fortygb                     : 1;  /**< RO/H - 40G capable. Always 1. */
		uint64_t tenpasst                    : 1;  /**< RO - 10PASS-TS/2BASE-TL capable. Always 0. */
		uint64_t tengb                       : 1;  /**< RO/H - 10G capable. Always 1. */
#else
		uint64_t tengb                       : 1;
		uint64_t tenpasst                    : 1;
		uint64_t fortygb                     : 1;
		uint64_t hundredgb                   : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_spux_spd_abil_s    cn85xx; */
	/* struct bdk_bgxx_spux_spd_abil_s    cn88xx; */
	/* struct bdk_bgxx_spux_spd_abil_s    cn88xxp1; */
} bdk_bgxx_spux_spd_abil_t;

static inline uint64_t BDK_BGXX_SPUX_SPD_ABIL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_SPD_ABIL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010010ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_SPD_ABIL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_SPD_ABIL(...) bdk_bgxx_spux_spd_abil_t
#define bustype_BDK_BGXX_SPUX_SPD_ABIL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_SPD_ABIL(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_SPD_ABIL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_SPD_ABIL(...) "BGXX_SPUX_SPD_ABIL"


/**
 * RSL - bgx#_spu#_status1
 */
typedef union bdk_bgxx_spux_status1 {
	uint64_t u;
	struct bdk_bgxx_spux_status1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t flt                         : 1;  /**< RO/H - Fault condition detected.
                                                                 This bit is a logical OR of BGX()_SPU()_STATUS2[XMTFLT, RCVFLT]. */
		uint64_t reserved_3_6                : 4;
		uint64_t rcv_lnk                     : 1;  /**< R/W1S/H - PCS receive link status:
                                                                   0 = receive link down.
                                                                   1 = receive link up.

                                                                 This is a latching-low bit; it stays clear until the register is read by software.

                                                                 For a BASE-X logical PCS type (in the associated BGX()_CMR()_CONFIG[LMAC_TYPE] =
                                                                 XAUI or RXAUI), this is a latching-low version of BGX()_SPU()_BX_STATUS[ALIGND].

                                                                 For a BASE-R logical PCS type (in the associated BGX()_CMR()_CONFIG[LMAC_TYPE] =
                                                                 10G_R or 40G_R), this is a latching-low version of
                                                                 BGX()_SPU()_BR_STATUS1[RCV_LNK].

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-set
                                                                 bit, rather than latching low read-only as specified in 802.3. */
		uint64_t lpable                      : 1;  /**< RO - Low-power ability. Always returns 1 to indicate that the LPCS supports low-power mode. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t lpable                      : 1;
		uint64_t rcv_lnk                     : 1;
		uint64_t reserved_3_6                : 4;
		uint64_t flt                         : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_spux_status1_s     cn85xx; */
	/* struct bdk_bgxx_spux_status1_s     cn88xx; */
	/* struct bdk_bgxx_spux_status1_s     cn88xxp1; */
} bdk_bgxx_spux_status1_t;

static inline uint64_t BDK_BGXX_SPUX_STATUS1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_STATUS1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010008ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_STATUS1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_STATUS1(...) bdk_bgxx_spux_status1_t
#define bustype_BDK_BGXX_SPUX_STATUS1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_STATUS1(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_STATUS1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_STATUS1(...) "BGXX_SPUX_STATUS1"


/**
 * RSL - bgx#_spu#_status2
 */
typedef union bdk_bgxx_spux_status2 {
	uint64_t u;
	struct bdk_bgxx_spux_status2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t dev                         : 2;  /**< RO/H - Device present. Always returns 0x2 to indicate a device is present at this address. */
		uint64_t reserved_12_13              : 2;
		uint64_t xmtflt                      : 1;  /**< RO/H - Transmit fault. Always returns 0. */
		uint64_t rcvflt                      : 1;  /**< R/W1C/H - Receive fault: 1 = receive fault, 0 = no receive fault. Latching high bit; stays set until
                                                                 software writes a 1.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-clear
                                                                 bit, rather than latching high read-only as specified in 802.3. */
		uint64_t reserved_6_9                : 4;
		uint64_t hundredgb_r                 : 1;  /**< RO - 100GBASE-R capable. Always 0. */
		uint64_t fortygb_r                   : 1;  /**< RO/H - 40GBASE-R capable. Always 1. */
		uint64_t tengb_t                     : 1;  /**< RO - 10GBASE-T capable. Always 0. */
		uint64_t tengb_w                     : 1;  /**< RO - 10GBASE-W capable. Always 0. */
		uint64_t tengb_x                     : 1;  /**< RO/H - 10GBASE-X capable. Always 1. */
		uint64_t tengb_r                     : 1;  /**< RO/H - 10GBASE-R capable. Always 1. */
#else
		uint64_t tengb_r                     : 1;
		uint64_t tengb_x                     : 1;
		uint64_t tengb_w                     : 1;
		uint64_t tengb_t                     : 1;
		uint64_t fortygb_r                   : 1;
		uint64_t hundredgb_r                 : 1;
		uint64_t reserved_6_9                : 4;
		uint64_t rcvflt                      : 1;
		uint64_t xmtflt                      : 1;
		uint64_t reserved_12_13              : 2;
		uint64_t dev                         : 2;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_bgxx_spux_status2_s     cn85xx; */
	/* struct bdk_bgxx_spux_status2_s     cn88xx; */
	/* struct bdk_bgxx_spux_status2_s     cn88xxp1; */
} bdk_bgxx_spux_status2_t;

static inline uint64_t BDK_BGXX_SPUX_STATUS2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPUX_STATUS2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010020ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x100000ull;
	csr_fatal("BDK_BGXX_SPUX_STATUS2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPUX_STATUS2(...) bdk_bgxx_spux_status2_t
#define bustype_BDK_BGXX_SPUX_STATUS2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPUX_STATUS2(p1,p2) (p1)
#define arguments_BDK_BGXX_SPUX_STATUS2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPUX_STATUS2(...) "BGXX_SPUX_STATUS2"


/**
 * RSL - bgx#_spu_bist_status
 *
 * This register provides memory BIST status from the SPU RX_BUF lane FIFOs.
 *
 */
typedef union bdk_bgxx_spu_bist_status {
	uint64_t u;
	struct bdk_bgxx_spu_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t rx_buf_bist_status          : 4;  /**< RO/H - SPU RX_BUF BIST status for lanes 3-0. One bit per SerDes lane, set to indicate BIST
                                                                 failure for the associated RX_BUF lane FIFO. */
#else
		uint64_t rx_buf_bist_status          : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_bgxx_spu_bist_status_s  cn85xx; */
	/* struct bdk_bgxx_spu_bist_status_s  cn88xx; */
	/* struct bdk_bgxx_spu_bist_status_s  cn88xxp1; */
} bdk_bgxx_spu_bist_status_t;

static inline uint64_t BDK_BGXX_SPU_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010330ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_BIST_STATUS(...) bdk_bgxx_spu_bist_status_t
#define bustype_BDK_BGXX_SPU_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_BIST_STATUS(p1) (p1)
#define arguments_BDK_BGXX_SPU_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_BIST_STATUS(...) "BGXX_SPU_BIST_STATUS"


/**
 * RSL - bgx#_spu_dbg_control
 */
typedef union bdk_bgxx_spu_dbg_control {
	uint64_t u;
	struct bdk_bgxx_spu_dbg_control_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t ms_clk_period               : 12; /**< R/W - Millisecond clock period. Specifies the number of microsecond clock ticks per millisecond,
                                                                 minus 1. The default value of 999 (0x3E7) should be used during normal operation; other
                                                                 values may be used for test/debug purposes. */
		uint64_t us_clk_period               : 12; /**< R/W - Microsecond clock period. Specifies the number of SCLK cycles per microseconds, minus 1.
                                                                 For example, if SCLK runs at 1.3 GHz, the number of SCLK cycles per microsecond is 1,300
                                                                 so the value of this field should be 1,299 (0x513). This is used by the BASE-R BER monitor
                                                                 timers. */
		uint64_t reserved_31_31              : 1;
		uint64_t br_ber_mon_dis              : 1;  /**< R/W - BASE-R bit error rate monitor disable. This bit should be clear for normal operation.
                                                                 Setting it disables the BASE-R BER monitor state machine defined in 802.3-2008 Figure
                                                                 49-13 for 10GBASE-R and 802.3ba-2010 Figure 82-13 for 40GBASE-R. */
		uint64_t an_nonce_match_dis          : 1;  /**< R/W - Autonegotiation nonce match disable. This bit should be clear for normal operation.
                                                                 Setting it disables Nonce Match check by forcing nonce_match variable to 0 in the Auto-
                                                                 Negotiation arbitration state diagram, as defined in 802.3-2008 Figure 73-11. This bit can
                                                                 be set by software for test purposes, e.g. for running autonegotiation in loopback mode. */
		uint64_t timestamp_norm_dis          : 1;  /**< R/W - 40GBASE-R RX timestamp normalization disable. This bit controls the generation of the
                                                                 receive SOP timestamp passed to the SMU sub-block for a 40GBASE-R LMAC/LPCS. When this bit
                                                                 is clear, SPU normalizes the receive SOP timestamp in order to compensate for lane-to-lane
                                                                 skew on a 40GBASE-R link, as described below. When this bit is set, timestamp
                                                                 normalization is disabled and SPU directly passes the captured SOP timestamp values to
                                                                 SMU.

                                                                 In 40GBASE-R mode, a packet's SOP block can be transferred on any of the LMAC's lanes. In
                                                                 the presence of lane-to-lane skew, the SOP delay from transmit (by the link partner) to
                                                                 receive by SPU varies depending on which lane is used by the SOP block. This variation
                                                                 reduces the accuracy of the received SOP timestamp relative to when it was transmitted by
                                                                 the link partner.

                                                                 SPU captures the timestamp of the alignment marker received on each SerDes lane during
                                                                 align/skew detection; the captured value can be read from the SerDes lane's
                                                                 BGX()_SPU_SDS()_SKEW_STATUS[SKEW_STATUS] field (AM_TIMESTAMP sub-field). If
                                                                 alignment markers are transmitted at about the same time on all lanes by the link partner,
                                                                 then the difference between the AM_TIMESTAMP values for a pair of lanes represents the
                                                                 approximate skew between those lanes.

                                                                 SPU uses the 40GBASE-R LMAC's programmed PCS lane 0 as a reference and computes the
                                                                 AM_TIMESTAMP delta of every other lane relative to PCS lane 0. When normalization is
                                                                 enabled, SPU adjusts the timestamp of a received SOP by subtracting the receiving lane's
                                                                 AM_TIMESTAMP delta from the captured timestamp value. The adjusted/normalized timestamp
                                                                 value is then passed to SMU along with the SOP.

                                                                 Software can determine the actual maximum skew of a 40GBASE-R link by examining the
                                                                 AM_TIMESTAMP values in the BGX()_SPU_SDS()_SKEW_STATUS registers, and decide if
                                                                 timestamp normalization should be enabled or disabled to improve PTP accuracy.
                                                                 Normalization improves accuracy for larger skew values but reduces the accuracy (due to
                                                                 timestamp measurement errors) for small skew values. */
		uint64_t rx_buf_flip_synd            : 8;  /**< R/W - Flip SPU RX_BUF FIFO ECC bits. Two bits per SerDes lane; used to inject single-bit and
                                                                 double-bit errors into the ECC field on writes to the associated SPU RX_BUF lane FIFO, as
                                                                 follows:
                                                                 0x0 = Normal operation.
                                                                 0x1 = SBE on ECC bit 0.
                                                                 0x2 = SBE on ECC bit 1.
                                                                 0x3 = DBE on ECC bits 1:0. */
		uint64_t br_pmd_train_soft_en        : 1;  /**< R/W - Enable BASE-R PMD software controlled link training. This bit configures the operation
                                                                 mode for BASE-R link training for all LMACs and lanes. When this bit is set along with
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] for a given LMAC, the BASE-R link training
                                                                 protocol for that LMAC is executed under software control, whereby the contents the
                                                                 BGX()_SPU()_BR_PMD_LD_CUP and BGX()_SPU()_BR_PMD_LD_REP registers are
                                                                 updated by software. When this bit is clear and
                                                                 BGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is set, the link training protocol is fully
                                                                 automated in hardware, whereby the contents BGX()_SPU()_BR_PMD_LD_CUP and
                                                                 BGX()_SPU()_BR_PMD_LD_REP registers are automatically updated by hardware. */
		uint64_t an_arb_link_chk_en          : 1;  /**< R/W - Enable link status checking by autonegotiation arbitration state machine. When Auto-
                                                                 Negotiation is enabled (BGX()_SPU()_AN_CONTROL[AN_EN] is set), this bit controls
                                                                 the behavior of the autonegotiation arbitration state machine when it reaches the AN GOOD
                                                                 CHECK state after DME pages are successfully exchanged, as defined in Figure 73-11 in
                                                                 802.3-2008.

                                                                 When this bit is set and the negotiated highest common denominator (HCD) technology
                                                                 matches BGX()_CMR()_CONFIG[LMAC_TYPE], the autonegotiation arbitration SM
                                                                 performs the actions defined for the AN GOOD CHECK state in Figure 73-11, i.e. run the
                                                                 link_fail_inhibit timer and eventually transition to the AN GOOD or TRANSMIT DISABLE
                                                                 state.

                                                                 When this bit is clear or the HCD technology does not match LMAC_TYPE, the AN arbitration
                                                                 SM stays in the AN GOOD CHECK state, with the expectation that software will perform the
                                                                 appropriate actions to complete the autonegotiation protocol, as follows:

                                                                 * If this bit is clear and the HCD technology matches LMAC_TYPE, clear AN_EN in
                                                                 AN_CONTROL.

                                                                 * Otherwise, disable the LPCS by clearing the BGX()_CMR()_CONFIG[ENABLE], clear
                                                                 BGX()_SPU()_AN_CONTROL[AN_EN], reconfigure the LPCS with the correct LMAC_TYPE,
                                                                 and re-enable the LPCS by setting BGX()_CMR()_CONFIG[ENABLE].

                                                                 In both cases, software should implement the link_fail_inhibit timer and verify the link
                                                                 status as specified for the AN GOOD CHECK state. */
		uint64_t rx_buf_cor_dis              : 1;  /**< R/W - When set, disables ECC correction on all SPU RX_BUF FIFOs. */
		uint64_t scramble_dis                : 1;  /**< R/W - BASE-R scrambler/descrambler disable. Setting this bit to 1 disables the BASE-R scrambler
                                                                 & descrambler functions and FEC PN-2112 scrambler & descrambler functions for debug
                                                                 purposes. */
		uint64_t reserved_15_15              : 1;
		uint64_t marker_rxp                  : 15; /**< R/W - BASE-R alignment marker receive period. For a multilane BASE-R logical PCS (i.e.
                                                                 40GBASE-R), this field specifies the expected alignment marker receive period per lane,
                                                                 i.e. the expected number of received 66b non-marker blocks between consecutive markers on
                                                                 the same lane. The default value corresponds to a period of 16363 blocks (exclusive) as
                                                                 specified in 802.3ba-2010. Must be greater than 64. */
#else
		uint64_t marker_rxp                  : 15;
		uint64_t reserved_15_15              : 1;
		uint64_t scramble_dis                : 1;
		uint64_t rx_buf_cor_dis              : 1;
		uint64_t an_arb_link_chk_en          : 1;
		uint64_t br_pmd_train_soft_en        : 1;
		uint64_t rx_buf_flip_synd            : 8;
		uint64_t timestamp_norm_dis          : 1;
		uint64_t an_nonce_match_dis          : 1;
		uint64_t br_ber_mon_dis              : 1;
		uint64_t reserved_31_31              : 1;
		uint64_t us_clk_period               : 12;
		uint64_t ms_clk_period               : 12;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_bgxx_spu_dbg_control_s  cn85xx; */
	/* struct bdk_bgxx_spu_dbg_control_s  cn88xx; */
	/* struct bdk_bgxx_spu_dbg_control_s  cn88xxp1; */
} bdk_bgxx_spu_dbg_control_t;

static inline uint64_t BDK_BGXX_SPU_DBG_CONTROL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_DBG_CONTROL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010300ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_DBG_CONTROL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_DBG_CONTROL(...) bdk_bgxx_spu_dbg_control_t
#define bustype_BDK_BGXX_SPU_DBG_CONTROL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_DBG_CONTROL(p1) (p1)
#define arguments_BDK_BGXX_SPU_DBG_CONTROL(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_DBG_CONTROL(...) "BGXX_SPU_DBG_CONTROL"


/**
 * RSL - bgx#_spu_mem_int
 */
typedef union bdk_bgxx_spu_mem_int {
	uint64_t u;
	struct bdk_bgxx_spu_mem_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t rx_buf_sbe                  : 4;  /**< R/W1C/H - SPU RX_BUF single-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a single-bit ECC error. */
		uint64_t rx_buf_dbe                  : 4;  /**< R/W1C/H - SPU RX_BUF double-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a double-bit ECC error. */
#else
		uint64_t rx_buf_dbe                  : 4;
		uint64_t rx_buf_sbe                  : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_spu_mem_int_s      cn85xx; */
	/* struct bdk_bgxx_spu_mem_int_s      cn88xx; */
	/* struct bdk_bgxx_spu_mem_int_s      cn88xxp1; */
} bdk_bgxx_spu_mem_int_t;

static inline uint64_t BDK_BGXX_SPU_MEM_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_MEM_INT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010310ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_MEM_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_MEM_INT(...) bdk_bgxx_spu_mem_int_t
#define bustype_BDK_BGXX_SPU_MEM_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_MEM_INT(p1) (p1)
#define arguments_BDK_BGXX_SPU_MEM_INT(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_MEM_INT(...) "BGXX_SPU_MEM_INT"


/**
 * RSL - bgx#_spu_mem_int_ena_w1c
 */
typedef union bdk_bgxx_spu_mem_int_ena_w1c {
	uint64_t u;
	struct bdk_bgxx_spu_mem_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t rx_buf_sbe                  : 4;  /**< R/W1C/H - SPU RX_BUF single-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a single-bit ECC error. */
		uint64_t rx_buf_dbe                  : 4;  /**< R/W1C/H - SPU RX_BUF double-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a double-bit ECC error. */
#else
		uint64_t rx_buf_dbe                  : 4;
		uint64_t rx_buf_sbe                  : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_spu_mem_int_ena_w1c_s cn85xx; */
	/* struct bdk_bgxx_spu_mem_int_ena_w1c_s cn88xx; */
	/* struct bdk_bgxx_spu_mem_int_ena_w1c_s cn88xxp1; */
} bdk_bgxx_spu_mem_int_ena_w1c_t;

static inline uint64_t BDK_BGXX_SPU_MEM_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_MEM_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010320ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_MEM_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_MEM_INT_ENA_W1C(...) bdk_bgxx_spu_mem_int_ena_w1c_t
#define bustype_BDK_BGXX_SPU_MEM_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_MEM_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_BGXX_SPU_MEM_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_MEM_INT_ENA_W1C(...) "BGXX_SPU_MEM_INT_ENA_W1C"


/**
 * RSL - bgx#_spu_mem_int_ena_w1s
 */
typedef union bdk_bgxx_spu_mem_int_ena_w1s {
	uint64_t u;
	struct bdk_bgxx_spu_mem_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t rx_buf_sbe                  : 4;  /**< R/W1C/H - SPU RX_BUF single-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a single-bit ECC error. */
		uint64_t rx_buf_dbe                  : 4;  /**< R/W1C/H - SPU RX_BUF double-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a double-bit ECC error. */
#else
		uint64_t rx_buf_dbe                  : 4;
		uint64_t rx_buf_sbe                  : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_spu_mem_int_ena_w1s_s cn85xx; */
	/* struct bdk_bgxx_spu_mem_int_ena_w1s_s cn88xx; */
	/* struct bdk_bgxx_spu_mem_int_ena_w1s_s cn88xxp1; */
} bdk_bgxx_spu_mem_int_ena_w1s_t;

static inline uint64_t BDK_BGXX_SPU_MEM_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_MEM_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010328ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_MEM_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_MEM_INT_ENA_W1S(...) bdk_bgxx_spu_mem_int_ena_w1s_t
#define bustype_BDK_BGXX_SPU_MEM_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_MEM_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_BGXX_SPU_MEM_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_MEM_INT_ENA_W1S(...) "BGXX_SPU_MEM_INT_ENA_W1S"


/**
 * RSL - bgx#_spu_mem_int_w1s
 */
typedef union bdk_bgxx_spu_mem_int_w1s {
	uint64_t u;
	struct bdk_bgxx_spu_mem_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t rx_buf_sbe                  : 4;  /**< R/W1C/H - SPU RX_BUF single-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a single-bit ECC error. */
		uint64_t rx_buf_dbe                  : 4;  /**< R/W1C/H - SPU RX_BUF double-bit error for lanes 3-0. One bit per physical SerDes lane. Each bit is
                                                                 set when the associated RX_BUF lane FIFO detects a double-bit ECC error. */
#else
		uint64_t rx_buf_dbe                  : 4;
		uint64_t rx_buf_sbe                  : 4;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_bgxx_spu_mem_int_w1s_s  cn85xx; */
	/* struct bdk_bgxx_spu_mem_int_w1s_s  cn88xx; */
	/* struct bdk_bgxx_spu_mem_int_w1s_s  cn88xxp1; */
} bdk_bgxx_spu_mem_int_w1s_t;

static inline uint64_t BDK_BGXX_SPU_MEM_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_MEM_INT_W1S(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010318ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_MEM_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_MEM_INT_W1S(...) bdk_bgxx_spu_mem_int_w1s_t
#define bustype_BDK_BGXX_SPU_MEM_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_MEM_INT_W1S(p1) (p1)
#define arguments_BDK_BGXX_SPU_MEM_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_MEM_INT_W1S(...) "BGXX_SPU_MEM_INT_W1S"


/**
 * RSL - bgx#_spu_mem_status
 *
 * This register provides memory ECC status from the SPU RX_BUF lane FIFOs.
 *
 */
typedef union bdk_bgxx_spu_mem_status {
	uint64_t u;
	struct bdk_bgxx_spu_mem_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t rx_buf_ecc_synd             : 32; /**< RO/H - SPU RX_BUF ECC syndromes for lanes 3-0. 8-bit syndrome sub-field per SerDes lane. Each
                                                                 8-bit sub-field contains the syndrome of the latest single-bit or double-bit ECC error
                                                                 detected by the associated RX_BUF lane FIFO, i.e. it is loaded when the corresponding
                                                                 RX_BUF_SBE or RX_BUF_DBE bit is set in the SPU MEM_INT register. */
#else
		uint64_t rx_buf_ecc_synd             : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_bgxx_spu_mem_status_s   cn85xx; */
	/* struct bdk_bgxx_spu_mem_status_s   cn88xx; */
	/* struct bdk_bgxx_spu_mem_status_s   cn88xxp1; */
} bdk_bgxx_spu_mem_status_t;

static inline uint64_t BDK_BGXX_SPU_MEM_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_MEM_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0E0010308ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_BGXX_SPU_MEM_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_MEM_STATUS(...) bdk_bgxx_spu_mem_status_t
#define bustype_BDK_BGXX_SPU_MEM_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_MEM_STATUS(p1) (p1)
#define arguments_BDK_BGXX_SPU_MEM_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_BGXX_SPU_MEM_STATUS(...) "BGXX_SPU_MEM_STATUS"


/**
 * RSL - bgx#_spu_sds#_skew_status
 *
 * This register provides SerDes lane skew status. One register per physical SerDes lane.
 *
 */
typedef union bdk_bgxx_spu_sdsx_skew_status {
	uint64_t u;
	struct bdk_bgxx_spu_sdsx_skew_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t skew_status                 : 32; /**< RO/H - Format defined by BGX_SPU_SDS_SKEW_STATUS_S. */
#else
		uint64_t skew_status                 : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_bgxx_spu_sdsx_skew_status_s cn85xx; */
	/* struct bdk_bgxx_spu_sdsx_skew_status_s cn88xx; */
	/* struct bdk_bgxx_spu_sdsx_skew_status_s cn88xxp1; */
} bdk_bgxx_spu_sdsx_skew_status_t;

static inline uint64_t BDK_BGXX_SPU_SDSX_SKEW_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_SDSX_SKEW_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010340ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_BGXX_SPU_SDSX_SKEW_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_SDSX_SKEW_STATUS(...) bdk_bgxx_spu_sdsx_skew_status_t
#define bustype_BDK_BGXX_SPU_SDSX_SKEW_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_SDSX_SKEW_STATUS(p1,p2) (p1)
#define arguments_BDK_BGXX_SPU_SDSX_SKEW_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPU_SDSX_SKEW_STATUS(...) "BGXX_SPU_SDSX_SKEW_STATUS"


/**
 * RSL - bgx#_spu_sds#_states
 *
 * This register provides SerDes lane states. One register per physical SerDes lane.
 *
 */
typedef union bdk_bgxx_spu_sdsx_states {
	uint64_t u;
	struct bdk_bgxx_spu_sdsx_states_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_52_63              : 12;
		uint64_t am_lock_invld_cnt           : 2;  /**< RO/H - 40GBASE-R alignment marker lock state machine invalid AM counter. */
		uint64_t am_lock_sm                  : 2;  /**< RO/H - 40GBASE-R alignment marker lock state machine state. */
		uint64_t reserved_45_47              : 3;
		uint64_t train_sm                    : 3;  /**< RO/H - Link training state machine state. */
		uint64_t train_code_viol             : 1;  /**< RO/H - Link training code violation in received control channel. */
		uint64_t train_frame_lock            : 1;  /**< RO/H - Link training frame lock status. */
		uint64_t train_lock_found_1st_marker : 1;  /**< RO/H - Link training lock state machine found first marker flag. */
		uint64_t train_lock_bad_markers      : 3;  /**< RO/H - Link training lock state machine bad markers counter. */
		uint64_t reserved_35_35              : 1;
		uint64_t an_arb_sm                   : 3;  /**< RO/H - Autonegotiation arbitration state machine state. */
		uint64_t an_rx_sm                    : 2;  /**< RO/H - Autonegotiation receive state machine state. */
		uint64_t reserved_29_29              : 1;
		uint64_t fec_block_sync              : 1;  /**< RO/H - FEC block sync status. */
		uint64_t fec_sync_cnt                : 4;  /**< RO/H - FEC block sync state machine good/bad parity block counter. */
		uint64_t reserved_23_23              : 1;
		uint64_t br_sh_invld_cnt             : 7;  /**< RO/H - BASE-R lock state machine invalid sync header counter. */
		uint64_t br_block_lock               : 1;  /**< RO/H - BASE-R block lock status. */
		uint64_t br_sh_cnt                   : 11; /**< RO/H - BASE-R lock state machine sync header counter */
		uint64_t bx_sync_sm                  : 4;  /**< RO/H - BASE-X PCS synchronization state machine state */
#else
		uint64_t bx_sync_sm                  : 4;
		uint64_t br_sh_cnt                   : 11;
		uint64_t br_block_lock               : 1;
		uint64_t br_sh_invld_cnt             : 7;
		uint64_t reserved_23_23              : 1;
		uint64_t fec_sync_cnt                : 4;
		uint64_t fec_block_sync              : 1;
		uint64_t reserved_29_29              : 1;
		uint64_t an_rx_sm                    : 2;
		uint64_t an_arb_sm                   : 3;
		uint64_t reserved_35_35              : 1;
		uint64_t train_lock_bad_markers      : 3;
		uint64_t train_lock_found_1st_marker : 1;
		uint64_t train_frame_lock            : 1;
		uint64_t train_code_viol             : 1;
		uint64_t train_sm                    : 3;
		uint64_t reserved_45_47              : 3;
		uint64_t am_lock_sm                  : 2;
		uint64_t am_lock_invld_cnt           : 2;
		uint64_t reserved_52_63              : 12;
#endif
	} s;
	/* struct bdk_bgxx_spu_sdsx_states_s  cn85xx; */
	/* struct bdk_bgxx_spu_sdsx_states_s  cn88xx; */
	/* struct bdk_bgxx_spu_sdsx_states_s  cn88xxp1; */
} bdk_bgxx_spu_sdsx_states_t;

static inline uint64_t BDK_BGXX_SPU_SDSX_STATES(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_BGXX_SPU_SDSX_STATES(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 3)))
		return 0x000087E0E0010360ull + (param1 & 1) * 0x1000000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_BGXX_SPU_SDSX_STATES", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_BGXX_SPU_SDSX_STATES(...) bdk_bgxx_spu_sdsx_states_t
#define bustype_BDK_BGXX_SPU_SDSX_STATES(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_BGXX_SPU_SDSX_STATES(p1,p2) (p1)
#define arguments_BDK_BGXX_SPU_SDSX_STATES(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_BGXX_SPU_SDSX_STATES(...) "BGXX_SPU_SDSX_STATES"

#endif /* __BDK_CSRS_BGX__ */
