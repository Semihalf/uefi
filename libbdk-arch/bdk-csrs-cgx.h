#ifndef __BDK_CSRS_CGX_H__
#define __BDK_CSRS_CGX_H__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
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
 * Cavium CGX.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration cgx_bar_e
 *
 * CGX Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_CGX_BAR_E_CGXX_PF_BAR0(a) (0x87e0e8000000ll + 0x1000000ll * (a))
#define BDK_CGX_BAR_E_CGXX_PF_BAR0_SIZE 0x400000ull
#define BDK_CGX_BAR_E_CGXX_PF_BAR4(a) (0x87e0e8400000ll + 0x1000000ll * (a))
#define BDK_CGX_BAR_E_CGXX_PF_BAR4_SIZE 0x400000ull

/**
 * Enumeration cgx_int_vec_e
 *
 * CGX MSI-X Vector Enumeration
 * Enumeration the MSI-X interrupt vectors.
 */
#define BDK_CGX_INT_VEC_E_CMRX_INT(a) (0 + 7 * (a))
#define BDK_CGX_INT_VEC_E_CMR_MEM_INT (0x1c)
#define BDK_CGX_INT_VEC_E_GMPX_GMI_RX_INT(a) (5 + 7 * (a))
#define BDK_CGX_INT_VEC_E_GMPX_GMI_TX_INT(a) (6 + 7 * (a))
#define BDK_CGX_INT_VEC_E_GMPX_PCS_INT(a) (4 + 7 * (a))
#define BDK_CGX_INT_VEC_E_SMUX_RX_INT(a) (2 + 7 * (a))
#define BDK_CGX_INT_VEC_E_SMUX_TX_INT(a) (3 + 7 * (a))
#define BDK_CGX_INT_VEC_E_SPUX_INT(a) (1 + 7 * (a))
#define BDK_CGX_INT_VEC_E_SPU_MEM_INT (0x1d)

/**
 * Enumeration cgx_lmac_types_e
 *
 * CGX LMAC Type Enumeration
 * Enumerates the LMAC Types that CGX supports.
 */
#define BDK_CGX_LMAC_TYPES_E_FORTYG_R (4)
#define BDK_CGX_LMAC_TYPES_E_QSGMII (6)
#define BDK_CGX_LMAC_TYPES_E_RGMII (5)
#define BDK_CGX_LMAC_TYPES_E_RXAUI (2)
#define BDK_CGX_LMAC_TYPES_E_SGMII (0)
#define BDK_CGX_LMAC_TYPES_E_TENG_R (3)
#define BDK_CGX_LMAC_TYPES_E_XAUI (1)

/**
 * Enumeration cgx_opcode_e
 *
 * INTERNAL: CGX Error Opcode Enumeration
 *
 * Enumerates the error opcodes created by CGX and presented to NCSI/NIC.
 */
#define BDK_CGX_OPCODE_E_RE_FCS (7)
#define BDK_CGX_OPCODE_E_RE_FCS_RCV (8)
#define BDK_CGX_OPCODE_E_RE_JABBER (2)
#define BDK_CGX_OPCODE_E_RE_NONE (0)
#define BDK_CGX_OPCODE_E_RE_PARTIAL (1)
#define BDK_CGX_OPCODE_E_RE_RX_CTL (0xb)
#define BDK_CGX_OPCODE_E_RE_SKIP (0xc)
#define BDK_CGX_OPCODE_E_RE_TERMINATE (9)

/**
 * Enumeration cgx_spu_br_train_cst_e
 *
 * CGX Training Coefficient Status Enumeration
 * 2-bit status for each coefficient as defined in 802.3-2008, Table 72-5.
 */
#define BDK_CGX_SPU_BR_TRAIN_CST_E_MAXIMUM (3)
#define BDK_CGX_SPU_BR_TRAIN_CST_E_MINIMUM (2)
#define BDK_CGX_SPU_BR_TRAIN_CST_E_NOT_UPDATED (0)
#define BDK_CGX_SPU_BR_TRAIN_CST_E_UPDATED (1)

/**
 * Enumeration cgx_spu_br_train_cup_e
 *
 * CGX Training Coefficient Enumeration
 * 2-bit command for each coefficient as defined in 802.3-2008, Table 72-4.
 */
#define BDK_CGX_SPU_BR_TRAIN_CUP_E_DECREMENT (1)
#define BDK_CGX_SPU_BR_TRAIN_CUP_E_HOLD (0)
#define BDK_CGX_SPU_BR_TRAIN_CUP_E_INCREMENT (2)
#define BDK_CGX_SPU_BR_TRAIN_CUP_E_RSV_CMD (3)

/**
 * Structure cgx_spu_br_lane_train_status_s
 *
 * CGX Lane Training Status Structure
 * This is the group of lane status bits for a single lane in the BASE-R PMD status register
 * (MDIO address 1.151) as defined in 802.3ba-2010, Table 45-55.
 */
union bdk_cgx_spu_br_lane_train_status_s
{
    uint32_t u;
    struct bdk_cgx_spu_br_lane_train_status_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_4_31         : 28;
        uint32_t training_failure      : 1;  /**< [  3:  3] Link training failure. */
        uint32_t training              : 1;  /**< [  2:  2] Link training state.
                                                                 0 = Training in progress.
                                                                 1 = Training has completed. */
        uint32_t frame_lock            : 1;  /**< [  1:  1] Frame lock status. Set when training frame delineation has been detected. */
        uint32_t rx_trained            : 1;  /**< [  0:  0] Receiver trained status.
                                                                 0 = Receiver training.
                                                                 1 = Receiver trained and ready to receive data for the lane. */
#else /* Word 0 - Little Endian */
        uint32_t rx_trained            : 1;  /**< [  0:  0] Receiver trained status.
                                                                 0 = Receiver training.
                                                                 1 = Receiver trained and ready to receive data for the lane. */
        uint32_t frame_lock            : 1;  /**< [  1:  1] Frame lock status. Set when training frame delineation has been detected. */
        uint32_t training              : 1;  /**< [  2:  2] Link training state.
                                                                 0 = Training in progress.
                                                                 1 = Training has completed. */
        uint32_t training_failure      : 1;  /**< [  3:  3] Link training failure. */
        uint32_t reserved_4_31         : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgx_spu_br_lane_train_status_s_s cn; */
};

/**
 * Structure cgx_spu_br_train_cup_s
 *
 * CGX Lane Training Coeffiecient Structure
 * This is the coefficient update field of the BASE-R link training packet as defined in
 * 802.3-2008, Table 72-4.
 */
union bdk_cgx_spu_br_train_cup_s
{
    uint32_t u;
    struct bdk_cgx_spu_br_train_cup_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_14_31        : 18;
        uint32_t preset                : 1;  /**< [ 13: 13] Preset. Set to indicate that all TX coefficients be set to a state where equalization is
                                                                 turned off, i.e. the precursor (k = -1) and postcursor (k = +1) coefficients should be set
                                                                 to 0 and the main
                                                                 (k = 0) coefficient should be set to its maximum value. */
        uint32_t init                  : 1;  /**< [ 12: 12] Initialize. Set to indicate that the TX coefficients should be set to meet the conditions
                                                                 defined in 802.3-2008 sub-clause 72.6.10.4.2. */
        uint32_t reserved_6_11         : 6;
        uint32_t post_cup              : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t main_cup              : 2;  /**< [  3:  2] Main (k = 0) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t pre_cup               : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
#else /* Word 0 - Little Endian */
        uint32_t pre_cup               : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t main_cup              : 2;  /**< [  3:  2] Main (k = 0) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t post_cup              : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t reserved_6_11         : 6;
        uint32_t init                  : 1;  /**< [ 12: 12] Initialize. Set to indicate that the TX coefficients should be set to meet the conditions
                                                                 defined in 802.3-2008 sub-clause 72.6.10.4.2. */
        uint32_t preset                : 1;  /**< [ 13: 13] Preset. Set to indicate that all TX coefficients be set to a state where equalization is
                                                                 turned off, i.e. the precursor (k = -1) and postcursor (k = +1) coefficients should be set
                                                                 to 0 and the main
                                                                 (k = 0) coefficient should be set to its maximum value. */
        uint32_t reserved_14_31        : 18;
#endif /* Word 0 - End */
    } s;
    struct bdk_cgx_spu_br_train_cup_s_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t reserved_14_15        : 2;
        uint32_t preset                : 1;  /**< [ 13: 13] Preset. Set to indicate that all TX coefficients be set to a state where equalization is
                                                                 turned off, i.e. the precursor (k = -1) and postcursor (k = +1) coefficients should be set
                                                                 to 0 and the main
                                                                 (k = 0) coefficient should be set to its maximum value. */
        uint32_t init                  : 1;  /**< [ 12: 12] Initialize. Set to indicate that the TX coefficients should be set to meet the conditions
                                                                 defined in 802.3-2008 sub-clause 72.6.10.4.2. */
        uint32_t reserved_6_11         : 6;
        uint32_t post_cup              : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t main_cup              : 2;  /**< [  3:  2] Main (k = 0) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t pre_cup               : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
#else /* Word 0 - Little Endian */
        uint32_t pre_cup               : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t main_cup              : 2;  /**< [  3:  2] Main (k = 0) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t post_cup              : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient update. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CUP_E. */
        uint32_t reserved_6_11         : 6;
        uint32_t init                  : 1;  /**< [ 12: 12] Initialize. Set to indicate that the TX coefficients should be set to meet the conditions
                                                                 defined in 802.3-2008 sub-clause 72.6.10.4.2. */
        uint32_t preset                : 1;  /**< [ 13: 13] Preset. Set to indicate that all TX coefficients be set to a state where equalization is
                                                                 turned off, i.e. the precursor (k = -1) and postcursor (k = +1) coefficients should be set
                                                                 to 0 and the main
                                                                 (k = 0) coefficient should be set to its maximum value. */
        uint32_t reserved_14_15        : 2;
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } cn;
};

/**
 * Structure cgx_spu_br_train_rep_s
 *
 * CGX Training Report Structure
 * This is the status report field of the BASE-R link training packet as defined in 802.3-2008,
 * Table 72-5.
 */
union bdk_cgx_spu_br_train_rep_s
{
    uint32_t u;
    struct bdk_cgx_spu_br_train_rep_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t rx_ready              : 1;  /**< [ 15: 15] Receiver ready. Set to indicate that the local receiver has determined that training is
                                                                 complete and is prepared to receive data. */
        uint32_t reserved_6_14         : 9;
        uint32_t post_cst              : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CST_E. */
        uint32_t main_cst              : 2;  /**< [  3:  2] Main (k = 0) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CST_E. */
        uint32_t pre_cst               : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CST_E. */
#else /* Word 0 - Little Endian */
        uint32_t pre_cst               : 2;  /**< [  1:  0] Pre-cursor (k = -1) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CST_E. */
        uint32_t main_cst              : 2;  /**< [  3:  2] Main (k = 0) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CST_E. */
        uint32_t post_cst              : 2;  /**< [  5:  4] Post-cursor (k = +1) coefficient status. Valid when PRESET = INIT = 0. Enumerated by
                                                                 CGX_SPU_BR_TRAIN_CST_E. */
        uint32_t reserved_6_14         : 9;
        uint32_t rx_ready              : 1;  /**< [ 15: 15] Receiver ready. Set to indicate that the local receiver has determined that training is
                                                                 complete and is prepared to receive data. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgx_spu_br_train_rep_s_s cn; */
};

/**
 * Structure cgx_spu_sds_cu_s
 *
 * INTERNAL: CGX Training Coeffiecient Structure
 *
 * This structure is similar to CGX_SPU_BR_TRAIN_CUP_S format, but with reserved fields removed
 * and [RCVR_READY] field added.
 */
union bdk_cgx_spu_sds_cu_s
{
    uint32_t u;
    struct bdk_cgx_spu_sds_cu_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t rcvr_ready            : 1;  /**< [  8:  8] See CGX_SPU_BR_TRAIN_REP_S[RX_READY]. */
        uint32_t preset                : 1;  /**< [  7:  7] See CGX_SPU_BR_TRAIN_CUP_S[PRESET]. */
        uint32_t initialize            : 1;  /**< [  6:  6] See CGX_SPU_BR_TRAIN_CUP_S[INIT]. */
        uint32_t post_cu               : 2;  /**< [  5:  4] See CGX_SPU_BR_TRAIN_CUP_S[POST_CUP]. */
        uint32_t main_cu               : 2;  /**< [  3:  2] See CGX_SPU_BR_TRAIN_CUP_S[MAIN_CUP]. */
        uint32_t pre_cu                : 2;  /**< [  1:  0] See CGX_SPU_BR_TRAIN_CUP_S[PRE_CUP]. */
#else /* Word 0 - Little Endian */
        uint32_t pre_cu                : 2;  /**< [  1:  0] See CGX_SPU_BR_TRAIN_CUP_S[PRE_CUP]. */
        uint32_t main_cu               : 2;  /**< [  3:  2] See CGX_SPU_BR_TRAIN_CUP_S[MAIN_CUP]. */
        uint32_t post_cu               : 2;  /**< [  5:  4] See CGX_SPU_BR_TRAIN_CUP_S[POST_CUP]. */
        uint32_t initialize            : 1;  /**< [  6:  6] See CGX_SPU_BR_TRAIN_CUP_S[INIT]. */
        uint32_t preset                : 1;  /**< [  7:  7] See CGX_SPU_BR_TRAIN_CUP_S[PRESET]. */
        uint32_t rcvr_ready            : 1;  /**< [  8:  8] See CGX_SPU_BR_TRAIN_REP_S[RX_READY]. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgx_spu_sds_cu_s_s cn; */
};

/**
 * Structure cgx_spu_sds_skew_status_s
 *
 * CGX Skew Status Structure
 * Provides receive skew information detected for a physical SerDes lane when it is assigned to a
 * multilane LMAC/LPCS. Contents are valid when RX deskew is done for the associated LMAC/LPCS.
 */
union bdk_cgx_spu_sds_skew_status_s
{
    uint32_t u;
    struct bdk_cgx_spu_sds_skew_status_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t lane_skew             : 5;  /**< [ 24: 20] Lane skew. The SerDes lane's receive skew/delay in number of code-groups (BASE-X) or
                                                                 blocks (40GBASE-R) relative to the earliest (least delayed) lane of the LMAC/LPCS. */
        uint32_t reserved_18_19        : 2;
        uint32_t am_lane_id            : 2;  /**< [ 17: 16] Alignment Marker ID. Valid for 40GBASE-R only. This is the PCS lane number of the
                                                                 alignment marker received on the SerDes lane. */
        uint32_t reserved_12_15        : 4;
        uint32_t am_timestamp          : 12; /**< [ 11:  0] Alignment marker PTP timestamp. Valid for 40GBASE-R only. Contains the lower 12 bits of
                                                                 the PTP timestamp of the alignment marker received on the SerDes lane during align/skew
                                                                 detection. */
#else /* Word 0 - Little Endian */
        uint32_t am_timestamp          : 12; /**< [ 11:  0] Alignment marker PTP timestamp. Valid for 40GBASE-R only. Contains the lower 12 bits of
                                                                 the PTP timestamp of the alignment marker received on the SerDes lane during align/skew
                                                                 detection. */
        uint32_t reserved_12_15        : 4;
        uint32_t am_lane_id            : 2;  /**< [ 17: 16] Alignment Marker ID. Valid for 40GBASE-R only. This is the PCS lane number of the
                                                                 alignment marker received on the SerDes lane. */
        uint32_t reserved_18_19        : 2;
        uint32_t lane_skew             : 5;  /**< [ 24: 20] Lane skew. The SerDes lane's receive skew/delay in number of code-groups (BASE-X) or
                                                                 blocks (40GBASE-R) relative to the earliest (least delayed) lane of the LMAC/LPCS. */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgx_spu_sds_skew_status_s_s cn; */
};

/**
 * Structure cgx_spu_sds_sr_s
 *
 * INTERNAL: CGX Lane Training Coefficient Structure
 *
 * Similar to CGX_SPU_BR_TRAIN_REP_S format, but with reserved and RX_READY fields removed.
 */
union bdk_cgx_spu_sds_sr_s
{
    uint32_t u;
    struct bdk_cgx_spu_sds_sr_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_6_31         : 26;
        uint32_t post_status           : 2;  /**< [  5:  4] See CGX_SPU_BR_TRAIN_REP_S[POST_CST]. */
        uint32_t main_status           : 2;  /**< [  3:  2] See CGX_SPU_BR_TRAIN_REP_S[MAIN_CST]. */
        uint32_t pre_status            : 2;  /**< [  1:  0] See CGX_SPU_BR_TRAIN_REP_S[PRE_CST]. */
#else /* Word 0 - Little Endian */
        uint32_t pre_status            : 2;  /**< [  1:  0] See CGX_SPU_BR_TRAIN_REP_S[PRE_CST]. */
        uint32_t main_status           : 2;  /**< [  3:  2] See CGX_SPU_BR_TRAIN_REP_S[MAIN_CST]. */
        uint32_t post_status           : 2;  /**< [  5:  4] See CGX_SPU_BR_TRAIN_REP_S[POST_CST]. */
        uint32_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgx_spu_sds_sr_s_s cn; */
};

/**
 * Register (RSL) cgx#_cmr#_config
 *
 * CGX CMR Configuration Registers
 * Logical MAC/PCS configuration registers; one per LMAC. The maximum number of LMACs (and
 * maximum LMAC ID) that can be enabled by these registers is limited by
 * CGX()_CMR_RX_LMACS[LMACS] and CGX()_CMR_TX_LMACS[LMACS]. When multiple LMACs are
 * enabled, they must be configured with the same [LMAC_TYPE] value.
 *
 * Internal:
 * <pre>
 * Typical configurations:
 *   ---------------------------------------------------------------------------
 *   Configuration           LMACS  Register             [ENABLE]    [LMAC_TYPE]
 *   ---------------------------------------------------------------------------
 *   1x40GBASE-R4            1      CGXn_CMR0_CONFIG     1           4
 *                                  CGXn_CMR1_CONFIG     0           --
 *                                  CGXn_CMR2_CONFIG     0           --
 *                                  CGXn_CMR3_CONFIG     0           --
 *   ---------------------------------------------------------------------------
 *   4x10GBASE-R             4      CGXn_CMR0_CONFIG     1           3
 *                                  CGXn_CMR1_CONFIG     1           3
 *                                  CGXn_CMR2_CONFIG     1           3
 *                                  CGXn_CMR3_CONFIG     1           3
 *   ---------------------------------------------------------------------------
 *   2xRXAUI                 2      CGXn_CMR0_CONFIG     1           2
 *                                  CGXn_CMR1_CONFIG     1           2
 *                                  CGXn_CMR2_CONFIG     0           --
 *                                  CGXn_CMR3_CONFIG     0           --
 *   ---------------------------------------------------------------------------
 *   1x10GBASE-X/XAUI/DXAUI  1      CGXn_CMR0_CONFIG     1           1
 *                                  CGXn_CMR1_CONFIG     0           --
 *                                  CGXn_CMR2_CONFIG     0           --
 *                                  CGXn_CMR3_CONFIG     0           --
 *   ---------------------------------------------------------------------------
 *   4xSGMII/1000BASE-X      4      CGXn_CMR0_CONFIG     1           0
 *                                  CGXn_CMR1_CONFIG     1           0
 *                                  CGXn_CMR2_CONFIG     1           0
 *                                  CGXn_CMR3_CONFIG     1           0
 *   ---------------------------------------------------------------------------
 *   QSGMII                  4      CGXn_CMR0_CONFIG     1           6
 *                                  CGXn_CMR1_CONFIG     1           6
 *                                  CGXn_CMR2_CONFIG     1           6
 *                                  CGXn_CMR3_CONFIG     1           6
 *   ---------------------------------------------------------------------------
 * </pre>
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_18_63        : 46;
        uint64_t p2x_select            : 1;  /**< [ 17: 17](R/W) Selects interior side P2X interface over which the LMAC will communicate:
                                                                 <pre>
                                                                   [P2X_SELECT]      Name      Connected block
                                                                   -------------------------------------------
                                                                   0                 P2X0      NIC
                                                                   1                 P2X1      Reserved.
                                                                 </pre> */
        uint64_t x2p_select            : 1;  /**< [ 16: 16](R/W) Selects interior side X2P interface over which the LMAC will communicate:
                                                                 <pre>
                                                                   [X2P_SELECT]      Name      Connected block
                                                                   -------------------------------------------
                                                                   0                 X2P0      NIC
                                                                   1                 X2P1      Reserved.
                                                                 </pre> */
        uint64_t enable                : 1;  /**< [ 15: 15](R/W) Logical MAC/PCS enable. This is the master enable for the LMAC. When clear, all the
                                                                 dedicated CGX context state for the LMAC (state machines, FIFOs, counters, etc.) is reset,
                                                                 and LMAC access to shared CGX resources (data path, SerDes lanes) is disabled.

                                                                 When set, LMAC operation is enabled, including link bring-up, synchronization, and
                                                                 transmit/receive of idles and fault sequences. Note that configuration registers for an
                                                                 LMAC are not reset when this bit is clear, allowing software to program them before
                                                                 setting this bit to enable the LMAC. This bit together with [LMAC_TYPE] is also used to
                                                                 enable the clocking to the GMP and/or blocks of the Super path (SMU and SPU). CMR clocking
                                                                 is enabled when any of the paths are enabled. */
        uint64_t data_pkt_rx_en        : 1;  /**< [ 14: 14](R/W) Data packet receive enable. When [ENABLE] = 1 and [DATA_PKT_RX_EN] = 1, the reception of
                                                                 data
                                                                 packets is enabled in the MAC layer. When [ENABLE] = 1 and [DATA_PKT_RX_EN] = 0, the MAC
                                                                 layer
                                                                 drops received data and flow-control packets. */
        uint64_t data_pkt_tx_en        : 1;  /**< [ 13: 13](R/W) Data packet transmit enable. When [ENABLE] = 1 and [DATA_PKT_TX_EN] = 1, the transmission
                                                                 of
                                                                 data
                                                                 packets is enabled in the MAC layer. When [ENABLE] = 1 and [DATA_PKT_TX_EN] = 0, the MAC
                                                                 layer
                                                                 suppresses the transmission of new data and packets for the LMAC. */
        uint64_t int_beat_gen          : 1;  /**< [ 12: 12](R/W) Internal beat generation. This bit is used for debug/test purposes and should be clear
                                                                 during normal operation. When set, the LMAC's PCS layer ignores RXVALID and
                                                                 TXREADY/TXCREDIT from the associated SerDes lanes, internally generates fake (idle)
                                                                 RXVALID and TXCREDIT pulses, and suppresses transmission to the SerDes. */
        uint64_t mix_en                : 1;  /**< [ 11: 11](R/W) Must be 0. */
        uint64_t lmac_type             : 3;  /**< [ 10:  8](R/W) Logical MAC/PCS/prt type:

                                                                 <pre>
                                                                   LMAC_TYPE  Name       Description            NUM_PCS_LANES
                                                                   ----------------------------------------------------------
                                                                   0x0        SGMII      SGMII/1000BASE-X             1
                                                                   0x1        XAUI       10GBASE-X/XAUI or DXAUI      4
                                                                   0x2        RXAUI      Reduced XAUI                 2
                                                                   0x3        10G_R      10GBASE-R                    1
                                                                   0x4        40G_R      40GBASE-R                    4
                                                                   0x5        --         Reserved                     -
                                                                   0x6        QSGMII     QSGMII                       1
                                                                   Other      --         Reserved                     -
                                                                 </pre>

                                                                 NUM_PCS_LANES specifies the number of PCS lanes that are valid for
                                                                 each type. Each valid PCS lane is mapped to a physical SerDes lane
                                                                 based on the programming of [LANE_TO_SDS].

                                                                 This field must be programmed to its final value before [ENABLE] is set, and must not
                                                                 be changed when [ENABLE] = 1. */
        uint64_t lane_to_sds           : 8;  /**< [  7:  0](R/W) PCS lane-to-SerDes mapping.
                                                                 This is an array of 2-bit values that map each logical PCS lane to a
                                                                 physical SerDes lane, as follows:

                                                                 <pre>
                                                                   Bits    Description            Reset value
                                                                   ------------------------------------------
                                                                   <7:6>   PCS Lane 3 SerDes ID       0x3
                                                                   <5:4>   PCS Lane 2 SerDes ID       0x2
                                                                   <3:2>   PCS Lane 1 SerDes ID       0x1
                                                                   <1:0>   PCS Lane 0 SerDes ID       0x0
                                                                 </pre>

                                                                 PCS lanes 0 through NUM_PCS_LANES-1 are valid, where NUM_PCS_LANES is a function of the
                                                                 logical MAC/PCS type (see [LMAC_TYPE]). For example, when [LMAC_TYPE] = SGMII,
                                                                 then NUM_PCS_LANES = 1, PCS lane 0 is valid and the associated physical SerDes lanes
                                                                 are selected by bits <1:0>.

                                                                 For 40GBASE-R ([LMAC_TYPE] = 40G_R), all four PCS lanes are valid, and the PCS lane IDs
                                                                 determine the block distribution order and associated alignment markers on the transmit
                                                                 side. This is not necessarily the order in which PCS lanes receive data because 802.3
                                                                 allows multilane BASE-R receive lanes to be reordered. When a lane (called service
                                                                 interface in 802.3ba-2010) has achieved alignment marker lock on the receive side (i.e.
                                                                 the associated CGX()_SPU()_BR_ALGN_STATUS[MARKER_LOCK] = 1), then the actual
                                                                 detected RX PCS lane number is recorded in the corresponding
                                                                 CGX()_SPU()_BR_LANE_MAP[LNx_MAPPING].

                                                                 For QSGMII, [LANE_TO_SDS]<1:0> for LMAC 0 selects the physical SerDes lane shared by four
                                                                 LMACs, and [LANE_TO_SDS]<1:0> must be unique for each of the four LMACs.

                                                                 This field must be programmed to its final value before [ENABLE] is set, and
                                                                 must not be changed when [ENABLE] = 1. */
#else /* Word 0 - Little Endian */
        uint64_t lane_to_sds           : 8;  /**< [  7:  0](R/W) PCS lane-to-SerDes mapping.
                                                                 This is an array of 2-bit values that map each logical PCS lane to a
                                                                 physical SerDes lane, as follows:

                                                                 <pre>
                                                                   Bits    Description            Reset value
                                                                   ------------------------------------------
                                                                   <7:6>   PCS Lane 3 SerDes ID       0x3
                                                                   <5:4>   PCS Lane 2 SerDes ID       0x2
                                                                   <3:2>   PCS Lane 1 SerDes ID       0x1
                                                                   <1:0>   PCS Lane 0 SerDes ID       0x0
                                                                 </pre>

                                                                 PCS lanes 0 through NUM_PCS_LANES-1 are valid, where NUM_PCS_LANES is a function of the
                                                                 logical MAC/PCS type (see [LMAC_TYPE]). For example, when [LMAC_TYPE] = SGMII,
                                                                 then NUM_PCS_LANES = 1, PCS lane 0 is valid and the associated physical SerDes lanes
                                                                 are selected by bits <1:0>.

                                                                 For 40GBASE-R ([LMAC_TYPE] = 40G_R), all four PCS lanes are valid, and the PCS lane IDs
                                                                 determine the block distribution order and associated alignment markers on the transmit
                                                                 side. This is not necessarily the order in which PCS lanes receive data because 802.3
                                                                 allows multilane BASE-R receive lanes to be reordered. When a lane (called service
                                                                 interface in 802.3ba-2010) has achieved alignment marker lock on the receive side (i.e.
                                                                 the associated CGX()_SPU()_BR_ALGN_STATUS[MARKER_LOCK] = 1), then the actual
                                                                 detected RX PCS lane number is recorded in the corresponding
                                                                 CGX()_SPU()_BR_LANE_MAP[LNx_MAPPING].

                                                                 For QSGMII, [LANE_TO_SDS]<1:0> for LMAC 0 selects the physical SerDes lane shared by four
                                                                 LMACs, and [LANE_TO_SDS]<1:0> must be unique for each of the four LMACs.

                                                                 This field must be programmed to its final value before [ENABLE] is set, and
                                                                 must not be changed when [ENABLE] = 1. */
        uint64_t lmac_type             : 3;  /**< [ 10:  8](R/W) Logical MAC/PCS/prt type:

                                                                 <pre>
                                                                   LMAC_TYPE  Name       Description            NUM_PCS_LANES
                                                                   ----------------------------------------------------------
                                                                   0x0        SGMII      SGMII/1000BASE-X             1
                                                                   0x1        XAUI       10GBASE-X/XAUI or DXAUI      4
                                                                   0x2        RXAUI      Reduced XAUI                 2
                                                                   0x3        10G_R      10GBASE-R                    1
                                                                   0x4        40G_R      40GBASE-R                    4
                                                                   0x5        --         Reserved                     -
                                                                   0x6        QSGMII     QSGMII                       1
                                                                   Other      --         Reserved                     -
                                                                 </pre>

                                                                 NUM_PCS_LANES specifies the number of PCS lanes that are valid for
                                                                 each type. Each valid PCS lane is mapped to a physical SerDes lane
                                                                 based on the programming of [LANE_TO_SDS].

                                                                 This field must be programmed to its final value before [ENABLE] is set, and must not
                                                                 be changed when [ENABLE] = 1. */
        uint64_t mix_en                : 1;  /**< [ 11: 11](R/W) Must be 0. */
        uint64_t int_beat_gen          : 1;  /**< [ 12: 12](R/W) Internal beat generation. This bit is used for debug/test purposes and should be clear
                                                                 during normal operation. When set, the LMAC's PCS layer ignores RXVALID and
                                                                 TXREADY/TXCREDIT from the associated SerDes lanes, internally generates fake (idle)
                                                                 RXVALID and TXCREDIT pulses, and suppresses transmission to the SerDes. */
        uint64_t data_pkt_tx_en        : 1;  /**< [ 13: 13](R/W) Data packet transmit enable. When [ENABLE] = 1 and [DATA_PKT_TX_EN] = 1, the transmission
                                                                 of
                                                                 data
                                                                 packets is enabled in the MAC layer. When [ENABLE] = 1 and [DATA_PKT_TX_EN] = 0, the MAC
                                                                 layer
                                                                 suppresses the transmission of new data and packets for the LMAC. */
        uint64_t data_pkt_rx_en        : 1;  /**< [ 14: 14](R/W) Data packet receive enable. When [ENABLE] = 1 and [DATA_PKT_RX_EN] = 1, the reception of
                                                                 data
                                                                 packets is enabled in the MAC layer. When [ENABLE] = 1 and [DATA_PKT_RX_EN] = 0, the MAC
                                                                 layer
                                                                 drops received data and flow-control packets. */
        uint64_t enable                : 1;  /**< [ 15: 15](R/W) Logical MAC/PCS enable. This is the master enable for the LMAC. When clear, all the
                                                                 dedicated CGX context state for the LMAC (state machines, FIFOs, counters, etc.) is reset,
                                                                 and LMAC access to shared CGX resources (data path, SerDes lanes) is disabled.

                                                                 When set, LMAC operation is enabled, including link bring-up, synchronization, and
                                                                 transmit/receive of idles and fault sequences. Note that configuration registers for an
                                                                 LMAC are not reset when this bit is clear, allowing software to program them before
                                                                 setting this bit to enable the LMAC. This bit together with [LMAC_TYPE] is also used to
                                                                 enable the clocking to the GMP and/or blocks of the Super path (SMU and SPU). CMR clocking
                                                                 is enabled when any of the paths are enabled. */
        uint64_t x2p_select            : 1;  /**< [ 16: 16](R/W) Selects interior side X2P interface over which the LMAC will communicate:
                                                                 <pre>
                                                                   [X2P_SELECT]      Name      Connected block
                                                                   -------------------------------------------
                                                                   0                 X2P0      NIC
                                                                   1                 X2P1      Reserved.
                                                                 </pre> */
        uint64_t p2x_select            : 1;  /**< [ 17: 17](R/W) Selects interior side P2X interface over which the LMAC will communicate:
                                                                 <pre>
                                                                   [P2X_SELECT]      Name      Connected block
                                                                   -------------------------------------------
                                                                   0                 P2X0      NIC
                                                                   1                 P2X1      Reserved.
                                                                 </pre> */
        uint64_t reserved_18_63        : 46;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_config_s cn; */
} bdk_cgxx_cmrx_config_t;

static inline uint64_t BDK_CGXX_CMRX_CONFIG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_CONFIG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000000ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_CONFIG", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_CONFIG(a,b) bdk_cgxx_cmrx_config_t
#define bustype_BDK_CGXX_CMRX_CONFIG(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_CONFIG(a,b) "CGXX_CMRX_CONFIG"
#define device_bar_BDK_CGXX_CMRX_CONFIG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_CONFIG(a,b) (a)
#define arguments_BDK_CGXX_CMRX_CONFIG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_int
 *
 * CGX CMR Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1C/H) TX channel out-of-range from NIC interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1C/H) RX overflow. */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1C/H) RX PAUSE packet was dropped due to full RXB FIFO or during partner reset. */
#else /* Word 0 - Little Endian */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1C/H) RX PAUSE packet was dropped due to full RXB FIFO or during partner reset. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1C/H) RX overflow. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1C/H) Reserved.
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1C/H) TX channel out-of-range from NIC interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_int_s cn; */
} bdk_cgxx_cmrx_int_t;

static inline uint64_t BDK_CGXX_CMRX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000040ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_INT(a,b) bdk_cgxx_cmrx_int_t
#define bustype_BDK_CGXX_CMRX_INT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_INT(a,b) "CGXX_CMRX_INT"
#define device_bar_BDK_CGXX_CMRX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_INT(a,b) (a)
#define arguments_BDK_CGXX_CMRX_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_int_ena_w1c
 *
 * CGX CMR Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[NIC_NXC]. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[PKO_NXC].
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[OVERFLW]. */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[PAUSE_DRP]. */
#else /* Word 0 - Little Endian */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[PAUSE_DRP]. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[OVERFLW]. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[PKO_NXC].
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR(0..3)_INT[NIC_NXC]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_int_ena_w1c_s cn; */
} bdk_cgxx_cmrx_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_CMRX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000050ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_INT_ENA_W1C(a,b) bdk_cgxx_cmrx_int_ena_w1c_t
#define bustype_BDK_CGXX_CMRX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_INT_ENA_W1C(a,b) "CGXX_CMRX_INT_ENA_W1C"
#define device_bar_BDK_CGXX_CMRX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_CMRX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_int_ena_w1s
 *
 * CGX CMR Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[NIC_NXC]. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[PKO_NXC].
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[OVERFLW]. */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[PAUSE_DRP]. */
#else /* Word 0 - Little Endian */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[PAUSE_DRP]. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[OVERFLW]. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[PKO_NXC].
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR(0..3)_INT[NIC_NXC]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_int_ena_w1s_s cn; */
} bdk_cgxx_cmrx_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_CMRX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000058ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_INT_ENA_W1S(a,b) bdk_cgxx_cmrx_int_ena_w1s_t
#define bustype_BDK_CGXX_CMRX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_INT_ENA_W1S(a,b) "CGXX_CMRX_INT_ENA_W1S"
#define device_bar_BDK_CGXX_CMRX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_CMRX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_int_w1s
 *
 * CGX CMR Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[NIC_NXC]. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[PKO_NXC].
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[OVERFLW]. */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[PAUSE_DRP]. */
#else /* Word 0 - Little Endian */
        uint64_t pause_drp             : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[PAUSE_DRP]. */
        uint64_t overflw               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[OVERFLW]. */
        uint64_t pko_nxc               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[PKO_NXC].
                                                                 Internal:
                                                                 TX channel out-of-range from PKO interface.
                                                                 Reported on this LMAC for ids in the range of LMAC_ID+4, LMAC_ID+8 and LMAC_ID+12.
                                                                 Reported regardless of LMAC enable or P2X_SELECT association for this LMAC. */
        uint64_t nic_nxc               : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_CMR(0..3)_INT[NIC_NXC]. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_int_w1s_s cn; */
} bdk_cgxx_cmrx_int_w1s_t;

static inline uint64_t BDK_CGXX_CMRX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000048ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_INT_W1S(a,b) bdk_cgxx_cmrx_int_w1s_t
#define bustype_BDK_CGXX_CMRX_INT_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_INT_W1S(a,b) "CGXX_CMRX_INT_W1S"
#define device_bar_BDK_CGXX_CMRX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_INT_W1S(a,b) (a)
#define arguments_BDK_CGXX_CMRX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_prt_cbfc_ctl
 *
 * CGX CMR LMAC PFC Control Registers
 * See XOFF definition listed under CGX()_SMU()_CBFC_CTL.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_prt_cbfc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t phys_bp               : 16; /**< [ 31: 16](R/W) When the hardware is backpressuring any LMACs. (from either DFC or PFC packets or
                                                                 CGX()_CMR()_TX_OVR_BP[TX_CHAN_BP]) and all channels indicated by [PHYS_BP] are
                                                                 backpressured,
                                                                 simulate physical backpressure by deferring all packets on the transmitter.
                                                                 (i.e. signal to the mac an assertion of physical backpressure).
                                                                 If LMAC_TYPE != SGMII/QSGMII, CGX()_SMU()_CBFC_CTL[RX_EN] or
                                                                 CGX()_SMU()_HG2_CONTROL[HG2RX_EN]
                                                                 additionally need to be set. */
        uint64_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_15         : 16;
        uint64_t phys_bp               : 16; /**< [ 31: 16](R/W) When the hardware is backpressuring any LMACs. (from either DFC or PFC packets or
                                                                 CGX()_CMR()_TX_OVR_BP[TX_CHAN_BP]) and all channels indicated by [PHYS_BP] are
                                                                 backpressured,
                                                                 simulate physical backpressure by deferring all packets on the transmitter.
                                                                 (i.e. signal to the mac an assertion of physical backpressure).
                                                                 If LMAC_TYPE != SGMII/QSGMII, CGX()_SMU()_CBFC_CTL[RX_EN] or
                                                                 CGX()_SMU()_HG2_CONTROL[HG2RX_EN]
                                                                 additionally need to be set. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_prt_cbfc_ctl_s cn; */
} bdk_cgxx_cmrx_prt_cbfc_ctl_t;

static inline uint64_t BDK_CGXX_CMRX_PRT_CBFC_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_PRT_CBFC_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000508ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_PRT_CBFC_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_PRT_CBFC_CTL(a,b) bdk_cgxx_cmrx_prt_cbfc_ctl_t
#define bustype_BDK_CGXX_CMRX_PRT_CBFC_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_PRT_CBFC_CTL(a,b) "CGXX_CMRX_PRT_CBFC_CTL"
#define device_bar_BDK_CGXX_CMRX_PRT_CBFC_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_PRT_CBFC_CTL(a,b) (a)
#define arguments_BDK_CGXX_CMRX_PRT_CBFC_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_bp_drop
 *
 * CGX Receive Backpressure Drop Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_bp_drop_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t mark                  : 7;  /**< [  6:  0](R/W) Number of eight-byte cycles to reserve in the RX FIFO. When the number of free
                                                                 entries in the RX FIFO is less than or equal to [MARK], incoming packet data is
                                                                 dropped. [MARK] additionally indicates the number of entries to reserve in the RX FIFO for
                                                                 closing partially received packets. [MARK] should typically be programmed to its reset
                                                                 value; failure to program correctly can lead to system instability. */
#else /* Word 0 - Little Endian */
        uint64_t mark                  : 7;  /**< [  6:  0](R/W) Number of eight-byte cycles to reserve in the RX FIFO. When the number of free
                                                                 entries in the RX FIFO is less than or equal to [MARK], incoming packet data is
                                                                 dropped. [MARK] additionally indicates the number of entries to reserve in the RX FIFO for
                                                                 closing partially received packets. [MARK] should typically be programmed to its reset
                                                                 value; failure to program correctly can lead to system instability. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_bp_drop_s cn; */
} bdk_cgxx_cmrx_rx_bp_drop_t;

static inline uint64_t BDK_CGXX_CMRX_RX_BP_DROP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_BP_DROP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000c8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_BP_DROP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_BP_DROP(a,b) bdk_cgxx_cmrx_rx_bp_drop_t
#define bustype_BDK_CGXX_CMRX_RX_BP_DROP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_BP_DROP(a,b) "CGXX_CMRX_RX_BP_DROP"
#define device_bar_BDK_CGXX_CMRX_RX_BP_DROP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_BP_DROP(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_BP_DROP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_bp_off
 *
 * CGX Receive Backpressure Off Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_bp_off_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t mark                  : 7;  /**< [  6:  0](R/W) Low watermark (number of eight-byte cycles to deassert backpressure). Level is also used
                                                                 to exit the overflow dropping state. */
#else /* Word 0 - Little Endian */
        uint64_t mark                  : 7;  /**< [  6:  0](R/W) Low watermark (number of eight-byte cycles to deassert backpressure). Level is also used
                                                                 to exit the overflow dropping state. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_bp_off_s cn; */
} bdk_cgxx_cmrx_rx_bp_off_t;

static inline uint64_t BDK_CGXX_CMRX_RX_BP_OFF(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_BP_OFF(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000d8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_BP_OFF", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_BP_OFF(a,b) bdk_cgxx_cmrx_rx_bp_off_t
#define bustype_BDK_CGXX_CMRX_RX_BP_OFF(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_BP_OFF(a,b) "CGXX_CMRX_RX_BP_OFF"
#define device_bar_BDK_CGXX_CMRX_RX_BP_OFF(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_BP_OFF(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_BP_OFF(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_bp_on
 *
 * CGX Receive Backpressure On Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_bp_on_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t mark                  : 12; /**< [ 11:  0](R/W) High watermark. Buffer depth in multiple of 16-bytes, at which CGX will
                                                                 assert backpressure for each individual LMAC. Must satisfy:

                                                                   CGX()_CMR()_RX_BP_OFF[MARK] <= CGX()_CMR()_RX_BP_ON[MARK] <
                                                                   (FIFO_SIZE - CGX()_CMR()_RX_BP_DROP[MARK]).

                                                                 A value of 0x0 immediately asserts backpressure.

                                                                 The recommended value is 1/4th the size of the per-LMAC RX FIFO_SIZE as
                                                                 determined by CGX()_CMR_RX_LMACS[LMACS]. For example in SGMII mode with
                                                                 four LMACs of type SGMII, where CGX()_CMR_RX_LMACS[LMACS]=0x4, there is
                                                                 16 KB of buffering. The recommended 1/4th size of that 16 KB is 4 KB, which
                                                                 in units of 16 bytes gives [MARK] = 0x100 (the reset value). */
#else /* Word 0 - Little Endian */
        uint64_t mark                  : 12; /**< [ 11:  0](R/W) High watermark. Buffer depth in multiple of 16-bytes, at which CGX will
                                                                 assert backpressure for each individual LMAC. Must satisfy:

                                                                   CGX()_CMR()_RX_BP_OFF[MARK] <= CGX()_CMR()_RX_BP_ON[MARK] <
                                                                   (FIFO_SIZE - CGX()_CMR()_RX_BP_DROP[MARK]).

                                                                 A value of 0x0 immediately asserts backpressure.

                                                                 The recommended value is 1/4th the size of the per-LMAC RX FIFO_SIZE as
                                                                 determined by CGX()_CMR_RX_LMACS[LMACS]. For example in SGMII mode with
                                                                 four LMACs of type SGMII, where CGX()_CMR_RX_LMACS[LMACS]=0x4, there is
                                                                 16 KB of buffering. The recommended 1/4th size of that 16 KB is 4 KB, which
                                                                 in units of 16 bytes gives [MARK] = 0x100 (the reset value). */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_bp_on_s cn; */
} bdk_cgxx_cmrx_rx_bp_on_t;

static inline uint64_t BDK_CGXX_CMRX_RX_BP_ON(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_BP_ON(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000d0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_BP_ON", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_BP_ON(a,b) bdk_cgxx_cmrx_rx_bp_on_t
#define bustype_BDK_CGXX_CMRX_RX_BP_ON(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_BP_ON(a,b) "CGXX_CMRX_RX_BP_ON"
#define device_bar_BDK_CGXX_CMRX_RX_BP_ON(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_BP_ON(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_BP_ON(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_bp_status
 *
 * CGX CMR Receive Backpressure Status Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_bp_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t bp                    : 1;  /**< [  0:  0](RO/H) Per-LMAC backpressure status.
                                                                 0 = LMAC is not backpressured.
                                                                 1 = LMAC is backpressured. */
#else /* Word 0 - Little Endian */
        uint64_t bp                    : 1;  /**< [  0:  0](RO/H) Per-LMAC backpressure status.
                                                                 0 = LMAC is not backpressured.
                                                                 1 = LMAC is backpressured. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_bp_status_s cn; */
} bdk_cgxx_cmrx_rx_bp_status_t;

static inline uint64_t BDK_CGXX_CMRX_RX_BP_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_BP_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000f0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_BP_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_BP_STATUS(a,b) bdk_cgxx_cmrx_rx_bp_status_t
#define bustype_BDK_CGXX_CMRX_RX_BP_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_BP_STATUS(a,b) "CGXX_CMRX_RX_BP_STATUS"
#define device_bar_BDK_CGXX_CMRX_RX_BP_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_BP_STATUS(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_BP_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_dmac_ctl
 *
 * CGX CMR Receive DMAC Address-Control Register
 * Internal:
 * "* ALGORITHM
 * Here is some pseudo code that represents the address filter behavior.
 * dmac_addr_filter(uint8 prt, uint48 dmac) {
 * for (lmac=0, lmac<4, lmac++) {
 *   if (is_bcst(dmac))                               // broadcast accept
 *     return (CGX()_CMR({lmac})_RX_DMAC_CTL[BCST_ACCEPT] ? ACCEPT : REJECT);
 *   if (is_mcst(dmac) && CGX()_CMR({lmac})_RX_DMAC_CTL[MCST_MODE] == 0)   // multicast reject
 *     return REJECT;
 *   if (is_mcst(dmac) && CGX()_CMR({lmac})_RX_DMAC_CTL[MCST_MODE] == 1)   // multicast accept
 *     return ACCEPT;
 *   else        // DMAC CAM filter
 *     cam_hit = 0;
 *   for (i=0; i<32; i++) {
 *     cam = CGX()_CMR_RX_DMAC({i})_CAM;
 *     if (cam[EN] && cam[ID] == {lmac} && cam[ADR] == dmac) {
 *       cam_hit = 1;
 *       break;
 *     }
 *   }
 *   if (cam_hit) {
 *     return (CGX()_CMR({lmac})_RX_DMAC_CTL[CAM_ACCEPT] ? ACCEPT : REJECT);
 *   else
 *     return (CGX()_CMR({lmac})_RX_DMAC_CTL[CAM_ACCEPT] ? REJECT : ACCEPT);
 *   }
 * }"
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_dmac_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t cam_accept            : 1;  /**< [  3:  3](R/W) Allow or deny DMAC address filter.
                                                                 0 = Reject the packet on DMAC CAM address match.
                                                                 1 = Accept the packet on DMAC CAM address match. */
        uint64_t mcst_mode             : 2;  /**< [  2:  1](R/W) Multicast mode.
                                                                 0x0 = Force reject all multicast packets.
                                                                 0x1 = Force accept all multicast packets.
                                                                 0x2 = Use the address filter CAM.
                                                                 0x3 = Reserved. */
        uint64_t bcst_accept           : 1;  /**< [  0:  0](R/W) Allow or deny broadcast packets.
                                                                 0 = Reject all broadcast packets.
                                                                 1 = Accept all broadcast Packets. */
#else /* Word 0 - Little Endian */
        uint64_t bcst_accept           : 1;  /**< [  0:  0](R/W) Allow or deny broadcast packets.
                                                                 0 = Reject all broadcast packets.
                                                                 1 = Accept all broadcast Packets. */
        uint64_t mcst_mode             : 2;  /**< [  2:  1](R/W) Multicast mode.
                                                                 0x0 = Force reject all multicast packets.
                                                                 0x1 = Force accept all multicast packets.
                                                                 0x2 = Use the address filter CAM.
                                                                 0x3 = Reserved. */
        uint64_t cam_accept            : 1;  /**< [  3:  3](R/W) Allow or deny DMAC address filter.
                                                                 0 = Reject the packet on DMAC CAM address match.
                                                                 1 = Accept the packet on DMAC CAM address match. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_dmac_ctl_s cn; */
} bdk_cgxx_cmrx_rx_dmac_ctl_t;

static inline uint64_t BDK_CGXX_CMRX_RX_DMAC_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_DMAC_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000e8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_DMAC_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_DMAC_CTL(a,b) bdk_cgxx_cmrx_rx_dmac_ctl_t
#define bustype_BDK_CGXX_CMRX_RX_DMAC_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_DMAC_CTL(a,b) "CGXX_CMRX_RX_DMAC_CTL"
#define device_bar_BDK_CGXX_CMRX_RX_DMAC_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_DMAC_CTL(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_DMAC_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_fifo_len
 *
 * CGX CMR Receive FIFO Length Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_fifo_len_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t busy                  : 1;  /**< [ 13: 13](RO/H) Indicates if GMP and CMR are busy processing a packet. Used when bringing an LMAC
                                                                 down since in low bandwidth cases, as the FIFO length may often appear to be 0x0. */
        uint64_t fifo_len              : 13; /**< [ 12:  0](RO/H) Per-LMAC FIFO length. Useful for determining if FIFO is empty when bringing an LMAC down. */
#else /* Word 0 - Little Endian */
        uint64_t fifo_len              : 13; /**< [ 12:  0](RO/H) Per-LMAC FIFO length. Useful for determining if FIFO is empty when bringing an LMAC down. */
        uint64_t busy                  : 1;  /**< [ 13: 13](RO/H) Indicates if GMP and CMR are busy processing a packet. Used when bringing an LMAC
                                                                 down since in low bandwidth cases, as the FIFO length may often appear to be 0x0. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_fifo_len_s cn; */
} bdk_cgxx_cmrx_rx_fifo_len_t;

static inline uint64_t BDK_CGXX_CMRX_RX_FIFO_LEN(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_FIFO_LEN(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000108ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_FIFO_LEN", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_FIFO_LEN(a,b) bdk_cgxx_cmrx_rx_fifo_len_t
#define bustype_BDK_CGXX_CMRX_RX_FIFO_LEN(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_FIFO_LEN(a,b) "CGXX_CMRX_RX_FIFO_LEN"
#define device_bar_BDK_CGXX_CMRX_RX_FIFO_LEN(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_FIFO_LEN(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_FIFO_LEN(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_id_map
 *
 * CGX CMR Receive ID Map Register
 * These registers set the RX LMAC ID mapping for X2P/NIC.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_id_map_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t rid                   : 7;  /**< [ 14:  8](R/W) Reserved.
                                                                 Internal:
                                                                 Defeatured. Reassembly ID for Octeon PKI; not used in CN8XXX.
                                                                 Reassembly ID map for this LMAC. A shared pool of 96 reassembly IDs (RIDs) exists for all
                                                                 MACs.

                                                                 The RID for this LMAC must be constrained such that it does not overlap with any other MAC
                                                                 in the system. Its reset value has been chosen such that this condition is satisfied:

                                                                 _ RID reset value = 4*(CGX_ID + 1) + LMAC_ID

                                                                 Changes to RID must only occur when the LMAC is quiescent (i.e. the LMAC receive interface
                                                                 is down and the RX FIFO is empty). */
        uint64_t unused                : 2;  /**< [  7:  6](RAZ) Reserved bits. */
        uint64_t pknd                  : 6;  /**< [  5:  0](R/W) Port kind for this LMAC. */
#else /* Word 0 - Little Endian */
        uint64_t pknd                  : 6;  /**< [  5:  0](R/W) Port kind for this LMAC. */
        uint64_t unused                : 2;  /**< [  7:  6](RAZ) Reserved bits. */
        uint64_t rid                   : 7;  /**< [ 14:  8](R/W) Reserved.
                                                                 Internal:
                                                                 Defeatured. Reassembly ID for Octeon PKI; not used in CN8XXX.
                                                                 Reassembly ID map for this LMAC. A shared pool of 96 reassembly IDs (RIDs) exists for all
                                                                 MACs.

                                                                 The RID for this LMAC must be constrained such that it does not overlap with any other MAC
                                                                 in the system. Its reset value has been chosen such that this condition is satisfied:

                                                                 _ RID reset value = 4*(CGX_ID + 1) + LMAC_ID

                                                                 Changes to RID must only occur when the LMAC is quiescent (i.e. the LMAC receive interface
                                                                 is down and the RX FIFO is empty). */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_id_map_s cn; */
} bdk_cgxx_cmrx_rx_id_map_t;

static inline uint64_t BDK_CGXX_CMRX_RX_ID_MAP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_ID_MAP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000060ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_ID_MAP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_ID_MAP(a,b) bdk_cgxx_cmrx_rx_id_map_t
#define bustype_BDK_CGXX_CMRX_RX_ID_MAP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_ID_MAP(a,b) "CGXX_CMRX_RX_ID_MAP"
#define device_bar_BDK_CGXX_CMRX_RX_ID_MAP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_ID_MAP(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_ID_MAP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_logl_xoff
 *
 * CGX CMR Receive Logical XOFF Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_logl_xoff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t xoff                  : 16; /**< [ 15:  0](R/W1S/H) Together with CGX()_CMR()_RX_LOGL_XON, defines type of channel backpressure to
                                                                 apply to the MAC. In the case of SMU, Do not write when HiGig2 is
                                                                 enabled. Writing 1 sets the same physical register as that which is cleared by
                                                                 CGX()_CMR()_RX_LOGL_XON[XON]. An XOFF value of 1 will cause a backpressure on
                                                                 the MAC. */
#else /* Word 0 - Little Endian */
        uint64_t xoff                  : 16; /**< [ 15:  0](R/W1S/H) Together with CGX()_CMR()_RX_LOGL_XON, defines type of channel backpressure to
                                                                 apply to the MAC. In the case of SMU, Do not write when HiGig2 is
                                                                 enabled. Writing 1 sets the same physical register as that which is cleared by
                                                                 CGX()_CMR()_RX_LOGL_XON[XON]. An XOFF value of 1 will cause a backpressure on
                                                                 the MAC. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_logl_xoff_s cn; */
} bdk_cgxx_cmrx_rx_logl_xoff_t;

static inline uint64_t BDK_CGXX_CMRX_RX_LOGL_XOFF(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_LOGL_XOFF(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000f8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_LOGL_XOFF", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_LOGL_XOFF(a,b) bdk_cgxx_cmrx_rx_logl_xoff_t
#define bustype_BDK_CGXX_CMRX_RX_LOGL_XOFF(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_LOGL_XOFF(a,b) "CGXX_CMRX_RX_LOGL_XOFF"
#define device_bar_BDK_CGXX_CMRX_RX_LOGL_XOFF(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_LOGL_XOFF(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_LOGL_XOFF(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_logl_xon
 *
 * CGX CMR Receive Logical XON Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_logl_xon_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t xon                   : 16; /**< [ 15:  0](R/W1C/H) Together with CGX()_CMR()_RX_LOGL_XOFF, defines type of channel backpressure to
                                                                 apply. Do not write when HiGig2 is enabled. Writing 1 clears the same physical register as
                                                                 that which is set by XOFF. An XON value of 1 means only NIC channel BP can cause a
                                                                 backpressure on the MAC. */
#else /* Word 0 - Little Endian */
        uint64_t xon                   : 16; /**< [ 15:  0](R/W1C/H) Together with CGX()_CMR()_RX_LOGL_XOFF, defines type of channel backpressure to
                                                                 apply. Do not write when HiGig2 is enabled. Writing 1 clears the same physical register as
                                                                 that which is set by XOFF. An XON value of 1 means only NIC channel BP can cause a
                                                                 backpressure on the MAC. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_logl_xon_s cn; */
} bdk_cgxx_cmrx_rx_logl_xon_t;

static inline uint64_t BDK_CGXX_CMRX_RX_LOGL_XON(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_LOGL_XON(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000100ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_LOGL_XON", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_LOGL_XON(a,b) bdk_cgxx_cmrx_rx_logl_xon_t
#define bustype_BDK_CGXX_CMRX_RX_LOGL_XON(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_LOGL_XON(a,b) "CGXX_CMRX_RX_LOGL_XON"
#define device_bar_BDK_CGXX_CMRX_RX_LOGL_XON(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_LOGL_XON(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_LOGL_XON(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_pause_drop_time
 *
 * CGX CMR Receive Pause Drop-Time Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_pause_drop_time_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t pause_time            : 16; /**< [ 15:  0](R/W1C/H) Time extracted from the dropped PAUSE packet dropped due to RXB FIFO full or during partner reset. */
#else /* Word 0 - Little Endian */
        uint64_t pause_time            : 16; /**< [ 15:  0](R/W1C/H) Time extracted from the dropped PAUSE packet dropped due to RXB FIFO full or during partner reset. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_pause_drop_time_s cn; */
} bdk_cgxx_cmrx_rx_pause_drop_time_t;

static inline uint64_t BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000068ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_PAUSE_DROP_TIME", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(a,b) bdk_cgxx_cmrx_rx_pause_drop_time_t
#define bustype_BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(a,b) "CGXX_CMRX_RX_PAUSE_DROP_TIME"
#define device_bar_BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_PAUSE_DROP_TIME(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat0
 *
 * CGX Receive Status Register 0
 * These registers provide a count of received packets that meet the following conditions:
 * * are not recognized as PAUSE packets.
 * * are not dropped due DMAC filtering.
 * * are not dropped due FIFO full status.
 * * do not have any other OPCODE (FCS, Length, etc).
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of received packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of received packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat0_s cn; */
} bdk_cgxx_cmrx_rx_stat0_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000070ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT0", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT0(a,b) bdk_cgxx_cmrx_rx_stat0_t
#define bustype_BDK_CGXX_CMRX_RX_STAT0(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT0(a,b) "CGXX_CMRX_RX_STAT0"
#define device_bar_BDK_CGXX_CMRX_RX_STAT0(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT0(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat1
 *
 * CGX Receive Status Register 1
 * These registers provide a count of octets of received packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of received packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of received packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat1_s cn; */
} bdk_cgxx_cmrx_rx_stat1_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000078ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT1(a,b) bdk_cgxx_cmrx_rx_stat1_t
#define bustype_BDK_CGXX_CMRX_RX_STAT1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT1(a,b) "CGXX_CMRX_RX_STAT1"
#define device_bar_BDK_CGXX_CMRX_RX_STAT1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT1(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat2
 *
 * CGX Receive Status Register 2
 * These registers provide a count of all packets received that were recognized as flow-control
 * or PAUSE packets. PAUSE packets with any kind of error are counted in
 * CGX()_CMR()_RX_STAT8 (error stats register). Pause packets can be optionally dropped
 * or forwarded based on CGX()_SMU()_RX_FRM_CTL[CTL_DRP]/CGX()_GMP_GMI_RX_FRM_CTL[CTL_DRP].
 * This count increments regardless of whether the packet is dropped. PAUSE packets are never
 * counted in CGX()_CMR()_RX_STAT0.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of received PAUSE packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of received PAUSE packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat2_s cn; */
} bdk_cgxx_cmrx_rx_stat2_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000080ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT2", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT2(a,b) bdk_cgxx_cmrx_rx_stat2_t
#define bustype_BDK_CGXX_CMRX_RX_STAT2(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT2(a,b) "CGXX_CMRX_RX_STAT2"
#define device_bar_BDK_CGXX_CMRX_RX_STAT2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT2(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT2(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat3
 *
 * CGX Receive Status Register 3
 * These registers provide a count of octets of received PAUSE and control packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of received PAUSE packets. [CNT] will wrap and is cleared if LMAC is disabled
                                                                 with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of received PAUSE packets. [CNT] will wrap and is cleared if LMAC is disabled
                                                                 with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat3_s cn; */
} bdk_cgxx_cmrx_rx_stat3_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT3(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT3(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000088ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT3", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT3(a,b) bdk_cgxx_cmrx_rx_stat3_t
#define bustype_BDK_CGXX_CMRX_RX_STAT3(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT3(a,b) "CGXX_CMRX_RX_STAT3"
#define device_bar_BDK_CGXX_CMRX_RX_STAT3(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT3(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT3(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat4
 *
 * CGX Receive Status Register 4
 * These registers provide a count of all packets received that were dropped by the DMAC filter.
 * Packets that match the DMAC are dropped and counted here regardless of whether they were ERR
 * packets, but does not include those reported in CGX()_CMR()_RX_STAT6. These packets
 * are never counted in CGX()_CMR()_RX_STAT0. Eight-byte packets as the result of
 * truncation or other means are not dropped by CNXXXX and will never appear in this count.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of filtered DMAC packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of filtered DMAC packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat4_s cn; */
} bdk_cgxx_cmrx_rx_stat4_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT4(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT4(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000090ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT4", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT4(a,b) bdk_cgxx_cmrx_rx_stat4_t
#define bustype_BDK_CGXX_CMRX_RX_STAT4(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT4(a,b) "CGXX_CMRX_RX_STAT4"
#define device_bar_BDK_CGXX_CMRX_RX_STAT4(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT4(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT4(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat5
 *
 * CGX Receive Status Register 5
 * These registers provide a count of octets of filtered DMAC packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of filtered DMAC packets. [CNT] will wrap and is cleared if LMAC is disabled
                                                                 with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of filtered DMAC packets. [CNT] will wrap and is cleared if LMAC is disabled
                                                                 with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat5_s cn; */
} bdk_cgxx_cmrx_rx_stat5_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT5(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT5(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000098ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT5", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT5(a,b) bdk_cgxx_cmrx_rx_stat5_t
#define bustype_BDK_CGXX_CMRX_RX_STAT5(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT5(a,b) "CGXX_CMRX_RX_STAT5"
#define device_bar_BDK_CGXX_CMRX_RX_STAT5(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT5(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT5(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat6
 *
 * CGX Receive Status Register 6
 * These registers provide a count of all packets received that were dropped due to a full
 * receive FIFO. They do not count any packet that is truncated at the point of overflow and sent
 * on to the NIC. These registers count all entire packets dropped by the FIFO for a given LMAC
 * regardless of DMAC or PAUSE type.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of dropped packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of dropped packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat6_s cn; */
} bdk_cgxx_cmrx_rx_stat6_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT6(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT6(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000a0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT6", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT6(a,b) bdk_cgxx_cmrx_rx_stat6_t
#define bustype_BDK_CGXX_CMRX_RX_STAT6(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT6(a,b) "CGXX_CMRX_RX_STAT6"
#define device_bar_BDK_CGXX_CMRX_RX_STAT6(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT6(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT6(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat7
 *
 * CGX Receive Status Register 7
 * These registers provide a count of octets of received packets that were dropped due to a full
 * receive FIFO.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of dropped packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of dropped packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat7_s cn; */
} bdk_cgxx_cmrx_rx_stat7_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT7(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT7(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000a8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT7", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT7(a,b) bdk_cgxx_cmrx_rx_stat7_t
#define bustype_BDK_CGXX_CMRX_RX_STAT7(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT7(a,b) "CGXX_CMRX_RX_STAT7"
#define device_bar_BDK_CGXX_CMRX_RX_STAT7(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT7(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT7(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_stat8
 *
 * CGX Receive Status Register 8
 * These registers provide a count of all packets received with some error that were not dropped
 * either due to the DMAC filter or lack of room in the receive FIFO.
 * This does not include packets which were counted in
 * CGX()_CMR()_RX_STAT2, CGX()_CMR()_RX_STAT4 nor
 * CGX()_CMR()_RX_STAT6.
 *
 * Which statistics are updated on control packet errors and drops are shown below:
 *
 * <pre>
 * if dropped {
 *   if !errored STAT8
 *   if overflow STAT6
 *   else if dmac drop STAT4
 *   else if filter drop STAT2
 * } else {
 *   if errored STAT2
 *   else STAT8
 * }
 * </pre>
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_stat8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of error packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of error packets. [CNT] will wrap and is cleared if LMAC is disabled with
                                                                 CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_stat8_s cn; */
} bdk_cgxx_cmrx_rx_stat8_t;

static inline uint64_t BDK_CGXX_CMRX_RX_STAT8(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_STAT8(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000b0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_STAT8", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_STAT8(a,b) bdk_cgxx_cmrx_rx_stat8_t
#define bustype_BDK_CGXX_CMRX_RX_STAT8(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_STAT8(a,b) "CGXX_CMRX_RX_STAT8"
#define device_bar_BDK_CGXX_CMRX_RX_STAT8(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_STAT8(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_STAT8(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_rx_weight
 *
 * CGX CMR Receive-Weight Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_rx_weight_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t weight                : 4;  /**< [  3:  0](R/W) For the weighted round robin algorithm in CMR RXB, weight to assign for this LMAC relative
                                                                 to other LMAC weights. Defaults to round-robin (non-weighted minimum setting of 0x1). A
                                                                 setting of 0x0 effectively takes the LMAC out of eligibility. */
#else /* Word 0 - Little Endian */
        uint64_t weight                : 4;  /**< [  3:  0](R/W) For the weighted round robin algorithm in CMR RXB, weight to assign for this LMAC relative
                                                                 to other LMAC weights. Defaults to round-robin (non-weighted minimum setting of 0x1). A
                                                                 setting of 0x0 effectively takes the LMAC out of eligibility. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_rx_weight_s cn; */
} bdk_cgxx_cmrx_rx_weight_t;

static inline uint64_t BDK_CGXX_CMRX_RX_WEIGHT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_RX_WEIGHT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80000e0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_RX_WEIGHT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_RX_WEIGHT(a,b) bdk_cgxx_cmrx_rx_weight_t
#define bustype_BDK_CGXX_CMRX_RX_WEIGHT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_RX_WEIGHT(a,b) "CGXX_CMRX_RX_WEIGHT"
#define device_bar_BDK_CGXX_CMRX_RX_WEIGHT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_RX_WEIGHT(a,b) (a)
#define arguments_BDK_CGXX_CMRX_RX_WEIGHT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_channel
 *
 * CGX CMR Transmit-Channels Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_channel_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t msk                   : 16; /**< [ 31: 16](R/W) Backpressure channel mask. CGX can completely ignore the channel backpressure for channel
                                                                 specified by this field. Any channel in which MSK<n> is set never sends backpressure
                                                                 information to PKO. */
        uint64_t dis                   : 16; /**< [ 15:  0](R/W) Credit return backpressure disable. CGX stops returning channel credits for any
                                                                 channel that is backpressured. These bits can be used to override that. If
                                                                 [DIS]<n> is set, channel credits may flow back regardless of the backpressure
                                                                 for that channel. */
#else /* Word 0 - Little Endian */
        uint64_t dis                   : 16; /**< [ 15:  0](R/W) Credit return backpressure disable. CGX stops returning channel credits for any
                                                                 channel that is backpressured. These bits can be used to override that. If
                                                                 [DIS]<n> is set, channel credits may flow back regardless of the backpressure
                                                                 for that channel. */
        uint64_t msk                   : 16; /**< [ 31: 16](R/W) Backpressure channel mask. CGX can completely ignore the channel backpressure for channel
                                                                 specified by this field. Any channel in which MSK<n> is set never sends backpressure
                                                                 information to PKO. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_channel_s cn; */
} bdk_cgxx_cmrx_tx_channel_t;

static inline uint64_t BDK_CGXX_CMRX_TX_CHANNEL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_CHANNEL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000500ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_CHANNEL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_CHANNEL(a,b) bdk_cgxx_cmrx_tx_channel_t
#define bustype_BDK_CGXX_CMRX_TX_CHANNEL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_CHANNEL(a,b) "CGXX_CMRX_TX_CHANNEL"
#define device_bar_BDK_CGXX_CMRX_TX_CHANNEL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_CHANNEL(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_CHANNEL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_fifo_len
 *
 * CGX CMR Transmit FIFO Length Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_fifo_len_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t lmac_idle             : 1;  /**< [ 14: 14](RO/H) Idle signal to identify when all credits and other pipeline buffers are also cleared out
                                                                 and LMAC can be considered IDLE in the CGX CMR TX. */
        uint64_t fifo_len              : 14; /**< [ 13:  0](RO/H) Per-LMAC TXB main FIFO length. Useful for determining if main FIFO is empty when bringing
                                                                 an LMAC down. */
#else /* Word 0 - Little Endian */
        uint64_t fifo_len              : 14; /**< [ 13:  0](RO/H) Per-LMAC TXB main FIFO length. Useful for determining if main FIFO is empty when bringing
                                                                 an LMAC down. */
        uint64_t lmac_idle             : 1;  /**< [ 14: 14](RO/H) Idle signal to identify when all credits and other pipeline buffers are also cleared out
                                                                 and LMAC can be considered IDLE in the CGX CMR TX. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_fifo_len_s cn; */
} bdk_cgxx_cmrx_tx_fifo_len_t;

static inline uint64_t BDK_CGXX_CMRX_TX_FIFO_LEN(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_FIFO_LEN(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000518ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_FIFO_LEN", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_FIFO_LEN(a,b) bdk_cgxx_cmrx_tx_fifo_len_t
#define bustype_BDK_CGXX_CMRX_TX_FIFO_LEN(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_FIFO_LEN(a,b) "CGXX_CMRX_TX_FIFO_LEN"
#define device_bar_BDK_CGXX_CMRX_TX_FIFO_LEN(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_FIFO_LEN(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_FIFO_LEN(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_hg2_status
 *
 * CGX CMR Transmit HiGig2 Status Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_hg2_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t xof                   : 16; /**< [ 31: 16](RO/H) 16-bit XOF back pressure vector from HiGig2 message packet or from PFC packets. Non-
                                                                 zero only when logical back pressure is active. All bits are 0 when [LGTIM2GO] = 0x0. */
        uint64_t lgtim2go              : 16; /**< [ 15:  0](RO/H) Logical packet flow back pressure time remaining. Initial value set from XOF time field of
                                                                 HiGig2 message packet received or a function of the enabled and current timers for
                                                                 PFC packets. Nonzero only when logical back pressure is active. */
#else /* Word 0 - Little Endian */
        uint64_t lgtim2go              : 16; /**< [ 15:  0](RO/H) Logical packet flow back pressure time remaining. Initial value set from XOF time field of
                                                                 HiGig2 message packet received or a function of the enabled and current timers for
                                                                 PFC packets. Nonzero only when logical back pressure is active. */
        uint64_t xof                   : 16; /**< [ 31: 16](RO/H) 16-bit XOF back pressure vector from HiGig2 message packet or from PFC packets. Non-
                                                                 zero only when logical back pressure is active. All bits are 0 when [LGTIM2GO] = 0x0. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_hg2_status_s cn; */
} bdk_cgxx_cmrx_tx_hg2_status_t;

static inline uint64_t BDK_CGXX_CMRX_TX_HG2_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_HG2_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000510ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_HG2_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_HG2_STATUS(a,b) bdk_cgxx_cmrx_tx_hg2_status_t
#define bustype_BDK_CGXX_CMRX_TX_HG2_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_HG2_STATUS(a,b) "CGXX_CMRX_TX_HG2_STATUS"
#define device_bar_BDK_CGXX_CMRX_TX_HG2_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_HG2_STATUS(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_HG2_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_ovr_bp
 *
 * CGX CMR Transmit-Channels Backpressure Override Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_ovr_bp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t tx_chan_bp            : 16; /**< [ 15:  0](R/W) Per-channel backpressure status sent to NIC. Also see CGX()_PRT_CBFC_CTL for
                                                                 details on impact to physical backpressure.
                                                                 0 = Channel is available.
                                                                 1 = Channel is backpressured. */
#else /* Word 0 - Little Endian */
        uint64_t tx_chan_bp            : 16; /**< [ 15:  0](R/W) Per-channel backpressure status sent to NIC. Also see CGX()_PRT_CBFC_CTL for
                                                                 details on impact to physical backpressure.
                                                                 0 = Channel is available.
                                                                 1 = Channel is backpressured. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_ovr_bp_s cn; */
} bdk_cgxx_cmrx_tx_ovr_bp_t;

static inline uint64_t BDK_CGXX_CMRX_TX_OVR_BP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_OVR_BP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000520ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_OVR_BP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_OVR_BP(a,b) bdk_cgxx_cmrx_tx_ovr_bp_t
#define bustype_BDK_CGXX_CMRX_TX_OVR_BP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_OVR_BP(a,b) "CGXX_CMRX_TX_OVR_BP"
#define device_bar_BDK_CGXX_CMRX_TX_OVR_BP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_OVR_BP(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_OVR_BP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat0
 *
 * CGX CMR Transmit Statistics Registers 0
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t xscol                 : 48; /**< [ 47:  0](R/W/H) Number of packets dropped (never successfully sent) due to excessive collision. Defined by
                                                                 CGX()_GMP_GMI_TX_COL_ATTEMPT[LIMIT]. Half-duplex mode only and does not account for late
                                                                 collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t xscol                 : 48; /**< [ 47:  0](R/W/H) Number of packets dropped (never successfully sent) due to excessive collision. Defined by
                                                                 CGX()_GMP_GMI_TX_COL_ATTEMPT[LIMIT]. Half-duplex mode only and does not account for late
                                                                 collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat0_s cn; */
} bdk_cgxx_cmrx_tx_stat0_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000600ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT0", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT0(a,b) bdk_cgxx_cmrx_tx_stat0_t
#define bustype_BDK_CGXX_CMRX_TX_STAT0(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT0(a,b) "CGXX_CMRX_TX_STAT0"
#define device_bar_BDK_CGXX_CMRX_TX_STAT0(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT0(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat1
 *
 * CGX CMR Transmit Statistics Registers 1
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t xsdef                 : 48; /**< [ 47:  0](R/W/H) A count of the number of times any frame was deferred for an excessive period of time.
                                                                 See maxDeferTime in the IEEE 802.3 specification. Half-duplex mode only and not updated
                                                                 for late collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t xsdef                 : 48; /**< [ 47:  0](R/W/H) A count of the number of times any frame was deferred for an excessive period of time.
                                                                 See maxDeferTime in the IEEE 802.3 specification. Half-duplex mode only and not updated
                                                                 for late collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat1_s cn; */
} bdk_cgxx_cmrx_tx_stat1_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000608ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT1(a,b) bdk_cgxx_cmrx_tx_stat1_t
#define bustype_BDK_CGXX_CMRX_TX_STAT1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT1(a,b) "CGXX_CMRX_TX_STAT1"
#define device_bar_BDK_CGXX_CMRX_TX_STAT1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT1(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat10
 *
 * CGX CMR Transmit Statistics Registers 10
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist4                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 256-511. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist4                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 256-511. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat10_s cn; */
} bdk_cgxx_cmrx_tx_stat10_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT10(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT10(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000650ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT10", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT10(a,b) bdk_cgxx_cmrx_tx_stat10_t
#define bustype_BDK_CGXX_CMRX_TX_STAT10(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT10(a,b) "CGXX_CMRX_TX_STAT10"
#define device_bar_BDK_CGXX_CMRX_TX_STAT10(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT10(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT10(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat11
 *
 * CGX CMR Transmit Statistics Registers 11
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat11_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist5                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 512-1023. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist5                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 512-1023. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat11_s cn; */
} bdk_cgxx_cmrx_tx_stat11_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT11(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT11(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000658ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT11", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT11(a,b) bdk_cgxx_cmrx_tx_stat11_t
#define bustype_BDK_CGXX_CMRX_TX_STAT11(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT11(a,b) "CGXX_CMRX_TX_STAT11"
#define device_bar_BDK_CGXX_CMRX_TX_STAT11(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT11(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT11(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat12
 *
 * CGX CMR Transmit Statistics Registers 12
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat12_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist6                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 1024-1518. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist6                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 1024-1518. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat12_s cn; */
} bdk_cgxx_cmrx_tx_stat12_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT12(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT12(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000660ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT12", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT12(a,b) bdk_cgxx_cmrx_tx_stat12_t
#define bustype_BDK_CGXX_CMRX_TX_STAT12(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT12(a,b) "CGXX_CMRX_TX_STAT12"
#define device_bar_BDK_CGXX_CMRX_TX_STAT12(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT12(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT12(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat13
 *
 * CGX CMR Transmit Statistics Registers 13
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat13_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist7                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count > 1518. Packet length is the sum of all data
                                                                 transmitted on the wire for the given packet including packet data, pad bytes, FCS bytes,
                                                                 and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist7                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count > 1518. Packet length is the sum of all data
                                                                 transmitted on the wire for the given packet including packet data, pad bytes, FCS bytes,
                                                                 and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat13_s cn; */
} bdk_cgxx_cmrx_tx_stat13_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT13(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT13(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000668ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT13", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT13(a,b) bdk_cgxx_cmrx_tx_stat13_t
#define bustype_BDK_CGXX_CMRX_TX_STAT13(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT13(a,b) "CGXX_CMRX_TX_STAT13"
#define device_bar_BDK_CGXX_CMRX_TX_STAT13(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT13(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT13(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat14
 *
 * CGX CMR Transmit Statistics Registers 14
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat14_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t bcst                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent to broadcast DMAC, excluding PAUSE or PFC control packets generated
                                                                 by CGX. Does not include MCST packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap.

                                                                 Note that CGX determines if the packet is MCST or BCST from the DMAC of the packet. CGX
                                                                 assumes that the DMAC lies in the first six bytes of the packet as per the 802.3 frame
                                                                 definition. If the system requires additional data before the L2 header, the MCST and BCST
                                                                 counters may not reflect reality and should be ignored by software. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t bcst                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent to broadcast DMAC, excluding PAUSE or PFC control packets generated
                                                                 by CGX. Does not include MCST packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap.

                                                                 Note that CGX determines if the packet is MCST or BCST from the DMAC of the packet. CGX
                                                                 assumes that the DMAC lies in the first six bytes of the packet as per the 802.3 frame
                                                                 definition. If the system requires additional data before the L2 header, the MCST and BCST
                                                                 counters may not reflect reality and should be ignored by software. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat14_s cn; */
} bdk_cgxx_cmrx_tx_stat14_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT14(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT14(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000670ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT14", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT14(a,b) bdk_cgxx_cmrx_tx_stat14_t
#define bustype_BDK_CGXX_CMRX_TX_STAT14(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT14(a,b) "CGXX_CMRX_TX_STAT14"
#define device_bar_BDK_CGXX_CMRX_TX_STAT14(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT14(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT14(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat15
 *
 * CGX CMR Transmit Statistics Registers 15
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat15_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t mcst                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent to multicast DMAC, excluding PAUSE or PFC control packets generated
                                                                 by CGX. Does not include BCST packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap.

                                                                 Note that CGX determines if the packet is MCST or BCST from the DMAC of the packet. CGX
                                                                 assumes that the DMAC lies in the first six bytes of the packet as per the 802.3 frame
                                                                 definition. If the system requires additional data before the L2 header, then the MCST and
                                                                 BCST counters may not reflect reality and should be ignored by software. Cleared if LMAC
                                                                 is disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t mcst                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent to multicast DMAC, excluding PAUSE or PFC control packets generated
                                                                 by CGX. Does not include BCST packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap.

                                                                 Note that CGX determines if the packet is MCST or BCST from the DMAC of the packet. CGX
                                                                 assumes that the DMAC lies in the first six bytes of the packet as per the 802.3 frame
                                                                 definition. If the system requires additional data before the L2 header, then the MCST and
                                                                 BCST counters may not reflect reality and should be ignored by software. Cleared if LMAC
                                                                 is disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat15_s cn; */
} bdk_cgxx_cmrx_tx_stat15_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT15(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT15(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000678ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT15", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT15(a,b) bdk_cgxx_cmrx_tx_stat15_t
#define bustype_BDK_CGXX_CMRX_TX_STAT15(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT15(a,b) "CGXX_CMRX_TX_STAT15"
#define device_bar_BDK_CGXX_CMRX_TX_STAT15(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT15(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT15(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat16
 *
 * CGX CMR Transmit Statistics Registers 16
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat16_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t undflw                : 48; /**< [ 47:  0](R/W/H) Number of underflow packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 48; /**< [ 47:  0](R/W/H) Number of underflow packets.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat16_s cn; */
} bdk_cgxx_cmrx_tx_stat16_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT16(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT16(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000680ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT16", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT16(a,b) bdk_cgxx_cmrx_tx_stat16_t
#define bustype_BDK_CGXX_CMRX_TX_STAT16(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT16(a,b) "CGXX_CMRX_TX_STAT16"
#define device_bar_BDK_CGXX_CMRX_TX_STAT16(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT16(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT16(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat17
 *
 * CGX CMR Transmit Statistics Registers 17
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat17_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t ctl                   : 48; /**< [ 47:  0](R/W/H) Number of PAUSE or PFC control packets generated by CGX. It does not include control
                                                                 packets forwarded or generated by the cores. Does not track the number of generated HG2
                                                                 messages.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t ctl                   : 48; /**< [ 47:  0](R/W/H) Number of PAUSE or PFC control packets generated by CGX. It does not include control
                                                                 packets forwarded or generated by the cores. Does not track the number of generated HG2
                                                                 messages.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat17_s cn; */
} bdk_cgxx_cmrx_tx_stat17_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT17(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT17(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000688ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT17", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT17(a,b) bdk_cgxx_cmrx_tx_stat17_t
#define bustype_BDK_CGXX_CMRX_TX_STAT17(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT17(a,b) "CGXX_CMRX_TX_STAT17"
#define device_bar_BDK_CGXX_CMRX_TX_STAT17(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT17(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT17(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat2
 *
 * CGX CMR Transmit Statistics Registers 2
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t mcol                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent with multiple collisions. Must be less than
                                                                 CGX()_GMP_GMI_TX_COL_ATTEMPT[LIMIT]. Half-duplex mode only and not updated
                                                                 for late collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t mcol                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent with multiple collisions. Must be less than
                                                                 CGX()_GMP_GMI_TX_COL_ATTEMPT[LIMIT]. Half-duplex mode only and not updated
                                                                 for late collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat2_s cn; */
} bdk_cgxx_cmrx_tx_stat2_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000610ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT2", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT2(a,b) bdk_cgxx_cmrx_tx_stat2_t
#define bustype_BDK_CGXX_CMRX_TX_STAT2(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT2(a,b) "CGXX_CMRX_TX_STAT2"
#define device_bar_BDK_CGXX_CMRX_TX_STAT2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT2(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT2(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat3
 *
 * CGX CMR Transmit Statistics Registers 3
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t scol                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent with a single collision. Half-duplex mode only and not updated
                                                                 for late collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t scol                  : 48; /**< [ 47:  0](R/W/H) Number of packets sent with a single collision. Half-duplex mode only and not updated
                                                                 for late collisions.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat3_s cn; */
} bdk_cgxx_cmrx_tx_stat3_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT3(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT3(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000618ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT3", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT3(a,b) bdk_cgxx_cmrx_tx_stat3_t
#define bustype_BDK_CGXX_CMRX_TX_STAT3(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT3(a,b) "CGXX_CMRX_TX_STAT3"
#define device_bar_BDK_CGXX_CMRX_TX_STAT3(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT3(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT3(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat4
 *
 * CGX CMR Transmit Statistics Registers 4
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t octs                  : 48; /**< [ 47:  0](R/W/H) Number of total octets sent on the interface, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Does not count octets from frames that were truncated due to collisions
                                                                 in half-duplex mode.
                                                                 Octet counts are the sum of all data transmitted on the wire including packet data, pad
                                                                 bytes, FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND
                                                                 cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t octs                  : 48; /**< [ 47:  0](R/W/H) Number of total octets sent on the interface, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Does not count octets from frames that were truncated due to collisions
                                                                 in half-duplex mode.
                                                                 Octet counts are the sum of all data transmitted on the wire including packet data, pad
                                                                 bytes, FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND
                                                                 cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat4_s cn; */
} bdk_cgxx_cmrx_tx_stat4_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT4(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT4(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000620ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT4", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT4(a,b) bdk_cgxx_cmrx_tx_stat4_t
#define bustype_BDK_CGXX_CMRX_TX_STAT4(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT4(a,b) "CGXX_CMRX_TX_STAT4"
#define device_bar_BDK_CGXX_CMRX_TX_STAT4(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT4(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT4(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat5
 *
 * CGX CMR Transmit Statistics Registers 5
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t pkts                  : 48; /**< [ 47:  0](R/W/H) Number of total frames sent on the interface, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Does not count octets from frames that were truncated due to collisions
                                                                 in half-duplex mode.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t pkts                  : 48; /**< [ 47:  0](R/W/H) Number of total frames sent on the interface, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Does not count octets from frames that were truncated due to collisions
                                                                 in half-duplex mode.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat5_s cn; */
} bdk_cgxx_cmrx_tx_stat5_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT5(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT5(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000628ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT5", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT5(a,b) bdk_cgxx_cmrx_tx_stat5_t
#define bustype_BDK_CGXX_CMRX_TX_STAT5(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT5(a,b) "CGXX_CMRX_TX_STAT5"
#define device_bar_BDK_CGXX_CMRX_TX_STAT5(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT5(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT5(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat6
 *
 * CGX CMR Transmit Statistics Registers 6
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist0                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count < 64, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Packet length is the sum of all data transmitted on the wire for the
                                                                 given packet including packet data, pad bytes, FCS bytes, and JAM bytes. The octet counts
                                                                 do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist0                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count < 64, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Packet length is the sum of all data transmitted on the wire for the
                                                                 given packet including packet data, pad bytes, FCS bytes, and JAM bytes. The octet counts
                                                                 do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat6_s cn; */
} bdk_cgxx_cmrx_tx_stat6_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT6(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT6(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000630ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT6", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT6(a,b) bdk_cgxx_cmrx_tx_stat6_t
#define bustype_BDK_CGXX_CMRX_TX_STAT6(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT6(a,b) "CGXX_CMRX_TX_STAT6"
#define device_bar_BDK_CGXX_CMRX_TX_STAT6(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT6(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT6(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat7
 *
 * CGX CMR Transmit Statistics Registers 7
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist1                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count of 64, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Packet length is the sum of all data transmitted on the wire for the
                                                                 given packet including packet data, pad bytes, FCS bytes, and JAM bytes. The octet counts
                                                                 do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist1                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count of 64, excluding PAUSE or PFC control packets
                                                                 generated by CGX. Packet length is the sum of all data transmitted on the wire for the
                                                                 given packet including packet data, pad bytes, FCS bytes, and JAM bytes. The octet counts
                                                                 do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat7_s cn; */
} bdk_cgxx_cmrx_tx_stat7_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT7(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT7(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000638ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT7", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT7(a,b) bdk_cgxx_cmrx_tx_stat7_t
#define bustype_BDK_CGXX_CMRX_TX_STAT7(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT7(a,b) "CGXX_CMRX_TX_STAT7"
#define device_bar_BDK_CGXX_CMRX_TX_STAT7(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT7(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT7(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat8
 *
 * CGX CMR Transmit Statistics Registers 8
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist2                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 65-127. Packet length is the sum of all
                                                                 data transmitted on the wire for the given packet including packet data, pad bytes, FCS
                                                                 bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist2                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 65-127. Packet length is the sum of all
                                                                 data transmitted on the wire for the given packet including packet data, pad bytes, FCS
                                                                 bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat8_s cn; */
} bdk_cgxx_cmrx_tx_stat8_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT8(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT8(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000640ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT8", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT8(a,b) bdk_cgxx_cmrx_tx_stat8_t
#define bustype_BDK_CGXX_CMRX_TX_STAT8(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT8(a,b) "CGXX_CMRX_TX_STAT8"
#define device_bar_BDK_CGXX_CMRX_TX_STAT8(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT8(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT8(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr#_tx_stat9
 *
 * CGX CMR Transmit Statistics Registers 9
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmrx_tx_stat9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t hist3                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 128-255. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
#else /* Word 0 - Little Endian */
        uint64_t hist3                 : 48; /**< [ 47:  0](R/W/H) Number of packets sent with an octet count between 128-255. Packet length is the sum of
                                                                 all data transmitted on the wire for the given packet including packet data, pad bytes,
                                                                 FCS bytes, and JAM bytes. The octet counts do not include PREAMBLE byte or EXTEND cycles.

                                                                 Not cleared on read; cleared on a write with 0x0. Counters will wrap. Cleared if LMAC is
                                                                 disabled with CGX()_CMR()_CONFIG[ENABLE]=0. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmrx_tx_stat9_s cn; */
} bdk_cgxx_cmrx_tx_stat9_t;

static inline uint64_t BDK_CGXX_CMRX_TX_STAT9(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMRX_TX_STAT9(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8000648ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_CMRX_TX_STAT9", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMRX_TX_STAT9(a,b) bdk_cgxx_cmrx_tx_stat9_t
#define bustype_BDK_CGXX_CMRX_TX_STAT9(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMRX_TX_STAT9(a,b) "CGXX_CMRX_TX_STAT9"
#define device_bar_BDK_CGXX_CMRX_TX_STAT9(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMRX_TX_STAT9(a,b) (a)
#define arguments_BDK_CGXX_CMRX_TX_STAT9(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr_bad
 *
 * CGX CMR Bad Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_bad_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t rxb_nxl               : 1;  /**< [  0:  0](R/W1C/H) Receive side LMAC ID > CGX()_CMR_RX_LMACS. */
#else /* Word 0 - Little Endian */
        uint64_t rxb_nxl               : 1;  /**< [  0:  0](R/W1C/H) Receive side LMAC ID > CGX()_CMR_RX_LMACS. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_bad_s cn; */
} bdk_cgxx_cmr_bad_t;

static inline uint64_t BDK_CGXX_CMR_BAD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_BAD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8001020ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_BAD", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_BAD(a) bdk_cgxx_cmr_bad_t
#define bustype_BDK_CGXX_CMR_BAD(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_BAD(a) "CGXX_CMR_BAD"
#define device_bar_BDK_CGXX_CMR_BAD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_BAD(a) (a)
#define arguments_BDK_CGXX_CMR_BAD(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_bist_status
 *
 * CGX Built-in Self-Test Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_27_63        : 37;
        uint64_t status                : 27; /**< [ 26:  0](RO/H) '"BIST results. Hardware sets a bit to 1 for memory that fails; 0 indicates pass or never
                                                                 run.'

                                                                 Internal:
                                                                 "<0> = cgx#.rxb.infif_gmp.
                                                                 <1> = cgx#.rxb.infif_smu.
                                                                 <2> = cgx#.rxb.fif_bnk00.
                                                                 <3> = cgx#.rxb.fif_bnk01.
                                                                 <4> = cgx#.rxb.fif_bnk10.
                                                                 <5> = cgx#.rxb.fif_bnk11.
                                                                 <6> = cgx#.rxb.pki_skd_fif.
                                                                 <7> = cgx#.rxb.nic_skd_fif.
                                                                 <8> = cgx#.rxb_mix0_fif.
                                                                 <9> = cgx#.rxb_mix1_fif.
                                                                 <10> = 0.
                                                                 <11> = cgx#.txb_fif_mem0.
                                                                 <12> = cgx#.txb_fif_mem1.
                                                                 <13> = cgx#.txb_fif_mem2.
                                                                 <14> = cgx#.txb_fif_mem3.
                                                                 <15> = cgx#.txb_skd_m0_pko_fif.
                                                                 <16> = cgx#.txb_skd_m1_pko_fif.
                                                                 <17> = cgx#.txb_skd_m2_pko_fif.
                                                                 <18> = cgx#.txb_skd_m3_pko_fif.
                                                                 <19> = cgx#.txb_skd_m0_nic_fif.
                                                                 <20> = cgx#.txb_skd_m1_nic_fif.
                                                                 <21> = cgx#.txb_skd_m2_nic_fif.
                                                                 <22> = cgx#.txb_skd_m3_nic_fif.
                                                                 <23> = cgx#.txb_mix0_fif.
                                                                 <24> = cgx#.txb_mix1_fif.
                                                                 <25> = cgx#.txb_ncsi_fif.
                                                                 <26> = 0." */
#else /* Word 0 - Little Endian */
        uint64_t status                : 27; /**< [ 26:  0](RO/H) '"BIST results. Hardware sets a bit to 1 for memory that fails; 0 indicates pass or never
                                                                 run.'

                                                                 Internal:
                                                                 "<0> = cgx#.rxb.infif_gmp.
                                                                 <1> = cgx#.rxb.infif_smu.
                                                                 <2> = cgx#.rxb.fif_bnk00.
                                                                 <3> = cgx#.rxb.fif_bnk01.
                                                                 <4> = cgx#.rxb.fif_bnk10.
                                                                 <5> = cgx#.rxb.fif_bnk11.
                                                                 <6> = cgx#.rxb.pki_skd_fif.
                                                                 <7> = cgx#.rxb.nic_skd_fif.
                                                                 <8> = cgx#.rxb_mix0_fif.
                                                                 <9> = cgx#.rxb_mix1_fif.
                                                                 <10> = 0.
                                                                 <11> = cgx#.txb_fif_mem0.
                                                                 <12> = cgx#.txb_fif_mem1.
                                                                 <13> = cgx#.txb_fif_mem2.
                                                                 <14> = cgx#.txb_fif_mem3.
                                                                 <15> = cgx#.txb_skd_m0_pko_fif.
                                                                 <16> = cgx#.txb_skd_m1_pko_fif.
                                                                 <17> = cgx#.txb_skd_m2_pko_fif.
                                                                 <18> = cgx#.txb_skd_m3_pko_fif.
                                                                 <19> = cgx#.txb_skd_m0_nic_fif.
                                                                 <20> = cgx#.txb_skd_m1_nic_fif.
                                                                 <21> = cgx#.txb_skd_m2_nic_fif.
                                                                 <22> = cgx#.txb_skd_m3_nic_fif.
                                                                 <23> = cgx#.txb_mix0_fif.
                                                                 <24> = cgx#.txb_mix1_fif.
                                                                 <25> = cgx#.txb_ncsi_fif.
                                                                 <26> = 0." */
        uint64_t reserved_27_63        : 37;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_bist_status_s cn; */
} bdk_cgxx_cmr_bist_status_t;

static inline uint64_t BDK_CGXX_CMR_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000460ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_BIST_STATUS(a) bdk_cgxx_cmr_bist_status_t
#define bustype_BDK_CGXX_CMR_BIST_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_BIST_STATUS(a) "CGXX_CMR_BIST_STATUS"
#define device_bar_BDK_CGXX_CMR_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_BIST_STATUS(a) (a)
#define arguments_BDK_CGXX_CMR_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_chan_msk_and
 *
 * CGX CMR Backpressure Channel Mask AND Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_chan_msk_and_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t msk_and               : 64; /**< [ 63:  0](R/W) Assert physical backpressure when the backpressure channel vector combined with [MSK_AND]
                                                                 indicates backpressure as follows:
                                                                 _ phys_bp_msk_and = [MSK_AND]<x:y> != 0 && (chan_vector<x:y> & [MSK_AND]<x:y>) ==
                                                                 [MSK_AND]<x:y>
                                                                 _ phys_bp = phys_bp_msk_or || phys_bp_msk_and

                                                                 x/y are as follows:
                                                                 _ LMAC 0: <x:y> = <15:0>.
                                                                 _ LMAC 1: <x:y> = <31:16>.
                                                                 _ LMAC 2: <x:y> = <47:32>.
                                                                 _ LMAC 3: <x:y> = <63:48>. */
#else /* Word 0 - Little Endian */
        uint64_t msk_and               : 64; /**< [ 63:  0](R/W) Assert physical backpressure when the backpressure channel vector combined with [MSK_AND]
                                                                 indicates backpressure as follows:
                                                                 _ phys_bp_msk_and = [MSK_AND]<x:y> != 0 && (chan_vector<x:y> & [MSK_AND]<x:y>) ==
                                                                 [MSK_AND]<x:y>
                                                                 _ phys_bp = phys_bp_msk_or || phys_bp_msk_and

                                                                 x/y are as follows:
                                                                 _ LMAC 0: <x:y> = <15:0>.
                                                                 _ LMAC 1: <x:y> = <31:16>.
                                                                 _ LMAC 2: <x:y> = <47:32>.
                                                                 _ LMAC 3: <x:y> = <63:48>. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_chan_msk_and_s cn; */
} bdk_cgxx_cmr_chan_msk_and_t;

static inline uint64_t BDK_CGXX_CMR_CHAN_MSK_AND(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_CHAN_MSK_AND(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000450ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_CHAN_MSK_AND", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_CHAN_MSK_AND(a) bdk_cgxx_cmr_chan_msk_and_t
#define bustype_BDK_CGXX_CMR_CHAN_MSK_AND(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_CHAN_MSK_AND(a) "CGXX_CMR_CHAN_MSK_AND"
#define device_bar_BDK_CGXX_CMR_CHAN_MSK_AND(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_CHAN_MSK_AND(a) (a)
#define arguments_BDK_CGXX_CMR_CHAN_MSK_AND(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_chan_msk_or
 *
 * CGX Backpressure Channel Mask OR Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_chan_msk_or_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t msk_or                : 64; /**< [ 63:  0](R/W) Assert physical backpressure when the backpressure channel vector combined with [MSK_OR]
                                                                 indicates backpressure as follows:

                                                                 _ phys_bp_msk_or = (chan_vector<x:y> & [MSK_OR]<x:y>) != 0
                                                                 _ phys_bp = phys_bp_msk_or || phys_bp_msk_and

                                                                 x/y are as follows:
                                                                 _ LMAC 0: <x:y> = <15:0>.
                                                                 _ LMAC 1: <x:y> = <31:16>.
                                                                 _ LMAC 2: <x:y> = <47:32>.
                                                                 _ LMAC 3: <x:y> = <63:48>. */
#else /* Word 0 - Little Endian */
        uint64_t msk_or                : 64; /**< [ 63:  0](R/W) Assert physical backpressure when the backpressure channel vector combined with [MSK_OR]
                                                                 indicates backpressure as follows:

                                                                 _ phys_bp_msk_or = (chan_vector<x:y> & [MSK_OR]<x:y>) != 0
                                                                 _ phys_bp = phys_bp_msk_or || phys_bp_msk_and

                                                                 x/y are as follows:
                                                                 _ LMAC 0: <x:y> = <15:0>.
                                                                 _ LMAC 1: <x:y> = <31:16>.
                                                                 _ LMAC 2: <x:y> = <47:32>.
                                                                 _ LMAC 3: <x:y> = <63:48>. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_chan_msk_or_s cn; */
} bdk_cgxx_cmr_chan_msk_or_t;

static inline uint64_t BDK_CGXX_CMR_CHAN_MSK_OR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_CHAN_MSK_OR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000458ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_CHAN_MSK_OR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_CHAN_MSK_OR(a) bdk_cgxx_cmr_chan_msk_or_t
#define bustype_BDK_CGXX_CMR_CHAN_MSK_OR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_CHAN_MSK_OR(a) "CGXX_CMR_CHAN_MSK_OR"
#define device_bar_BDK_CGXX_CMR_CHAN_MSK_OR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_CHAN_MSK_OR(a) (a)
#define arguments_BDK_CGXX_CMR_CHAN_MSK_OR(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_eco
 *
 * INTERNAL: CGX ECO Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t eco_ro                : 32; /**< [ 63: 32](RO) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) Internal:
                                                                 Reserved for ECO usage. */
        uint64_t eco_ro                : 32; /**< [ 63: 32](RO) Internal:
                                                                 Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_eco_s cn; */
} bdk_cgxx_cmr_eco_t;

static inline uint64_t BDK_CGXX_CMR_ECO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_ECO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8001028ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_ECO", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_ECO(a) bdk_cgxx_cmr_eco_t
#define bustype_BDK_CGXX_CMR_ECO(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_ECO(a) "CGXX_CMR_ECO"
#define device_bar_BDK_CGXX_CMR_ECO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_ECO(a) (a)
#define arguments_BDK_CGXX_CMR_ECO(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_global_config
 *
 * CGX CMR Global Configuration Register
 * These registers configure the global CMR, PCS, and MAC.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_global_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t cmr_x2p1_reset        : 1;  /**< [ 11: 11](R/W) If the master block connected to X2P interface 1 is reset, software also needs
                                                                 to reset the X2P interface in the CGX by setting this bit. It resets the X2P
                                                                 interface state in the CGX (skid FIFO and pending requests to the master block)
                                                                 and prevents the RXB FIFOs for all LMACs from pushing data to the
                                                                 interface. Because the X2P and NCSI interfaces share the main RXB FIFOs it will
                                                                 also impact the NCSI interface therefore it is required to set [CMR_NCSI_DROP]
                                                                 bit first before setting this bit.

                                                                 Clearing this does not reset the X2P interface nor NCSI interface.  After the
                                                                 master block comes out of reset, software should clear this bit. */
        uint64_t cmr_ncsi_reset        : 1;  /**< [ 10: 10](R/W) Interface reset for the CMR NCSI block.
                                                                 Upon power up the CMR NCSI is in reset and the companion CNXXXX NCSI block will be
                                                                 commanded by the
                                                                 external BMC to enable one of the CNXXXX CGX NCSI interfaces for passing network traffic.
                                                                 Only one NCSI interface can be enabled in CNXXXX.  The BMC/NCSI will then proceed to
                                                                 configure
                                                                 the rest of the CGX csr for pass through traffic.

                                                                 When set, will reset the CMR NCSI interface effectively disabling it at a traffic boundary
                                                                 should traffic be flowing.  This bit will not reset the main RXB fifos. */
        uint64_t cmr_ncsi_drop         : 1;  /**< [  9:  9](R/W) NCSI drop.
                                                                 1 = Cleanly drop traffic going into the NCSI block of CGX.  Must set asserted
                                                                 with with [CMR_X2P_RESET]=1 (in the same write operation) to avoid partial packets
                                                                 to the NCSI interface while performing a X2P partner reset.
                                                                 0 = Allow traffic to flow through the NCSI block. */
        uint64_t ncsi_lmac_id          : 2;  /**< [  8:  7](R/W) Logical MAC ID that carries NCSI traffic for both RX and TX side of CMR.  On the RX side
                                                                 is
                                                                 also the LMAC_ID that is eligible for steering. */
        uint64_t fcs_strip             : 1;  /**< [  6:  6](R/W) A setting of 1 means the CGX strip the FCS bytes of every packet.  For packets less than 4
                                                                 bytes, the packet will be removed.
                                                                 A setting of 0 means the CGX will not modify or remove the FCS bytes. */
        uint64_t interleave_mode       : 1;  /**< [  5:  5](RAZ) Reserved. */
        uint64_t cmr_mix1_reset        : 1;  /**< [  4:  4](R/W) Must be 0. */
        uint64_t cmr_mix0_reset        : 1;  /**< [  3:  3](R/W) Must be 0. */
        uint64_t cmr_x2p_reset         : 1;  /**< [  2:  2](R/W) If the master block connected to X2P interface 0 is reset, software also needs
                                                                 to reset the X2P interface in the CGX by setting this bit. It resets the X2P
                                                                 interface state in the CGX (skid FIFO and pending requests to the master block)
                                                                 and prevents the RXB FIFOs for all LMACs from pushing data to the
                                                                 interface. Because the X2P and NCSI interfaces share the main RXB FIFOs it will
                                                                 also impact the NCSI interface therefore it is required to set [CMR_NCSI_DROP]
                                                                 bit first before setting this bit.

                                                                 Clearing this does not reset the X2P interface nor NCSI interface.  After the
                                                                 master block comes out of reset, software should clear this bit. */
        uint64_t cgx_clk_enable        : 1;  /**< [  1:  1](R/W) The global clock enable for CGX. Setting this bit overrides clock enables set by
                                                                 CGX()_CMR()_CONFIG[ENABLE] and CGX()_CMR()_CONFIG[LMAC_TYPE], essentially
                                                                 turning on clocks for the entire CGX. Setting this bit to 0 results in not overriding
                                                                 clock enables set by CGX()_CMR()_CONFIG[ENABLE] and
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]. */
        uint64_t pmux_sds_sel          : 1;  /**< [  0:  0](R/W) SerDes/GSER output select. Must be 0. */
#else /* Word 0 - Little Endian */
        uint64_t pmux_sds_sel          : 1;  /**< [  0:  0](R/W) SerDes/GSER output select. Must be 0. */
        uint64_t cgx_clk_enable        : 1;  /**< [  1:  1](R/W) The global clock enable for CGX. Setting this bit overrides clock enables set by
                                                                 CGX()_CMR()_CONFIG[ENABLE] and CGX()_CMR()_CONFIG[LMAC_TYPE], essentially
                                                                 turning on clocks for the entire CGX. Setting this bit to 0 results in not overriding
                                                                 clock enables set by CGX()_CMR()_CONFIG[ENABLE] and
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]. */
        uint64_t cmr_x2p_reset         : 1;  /**< [  2:  2](R/W) If the master block connected to X2P interface 0 is reset, software also needs
                                                                 to reset the X2P interface in the CGX by setting this bit. It resets the X2P
                                                                 interface state in the CGX (skid FIFO and pending requests to the master block)
                                                                 and prevents the RXB FIFOs for all LMACs from pushing data to the
                                                                 interface. Because the X2P and NCSI interfaces share the main RXB FIFOs it will
                                                                 also impact the NCSI interface therefore it is required to set [CMR_NCSI_DROP]
                                                                 bit first before setting this bit.

                                                                 Clearing this does not reset the X2P interface nor NCSI interface.  After the
                                                                 master block comes out of reset, software should clear this bit. */
        uint64_t cmr_mix0_reset        : 1;  /**< [  3:  3](R/W) Must be 0. */
        uint64_t cmr_mix1_reset        : 1;  /**< [  4:  4](R/W) Must be 0. */
        uint64_t interleave_mode       : 1;  /**< [  5:  5](RAZ) Reserved. */
        uint64_t fcs_strip             : 1;  /**< [  6:  6](R/W) A setting of 1 means the CGX strip the FCS bytes of every packet.  For packets less than 4
                                                                 bytes, the packet will be removed.
                                                                 A setting of 0 means the CGX will not modify or remove the FCS bytes. */
        uint64_t ncsi_lmac_id          : 2;  /**< [  8:  7](R/W) Logical MAC ID that carries NCSI traffic for both RX and TX side of CMR.  On the RX side
                                                                 is
                                                                 also the LMAC_ID that is eligible for steering. */
        uint64_t cmr_ncsi_drop         : 1;  /**< [  9:  9](R/W) NCSI drop.
                                                                 1 = Cleanly drop traffic going into the NCSI block of CGX.  Must set asserted
                                                                 with with [CMR_X2P_RESET]=1 (in the same write operation) to avoid partial packets
                                                                 to the NCSI interface while performing a X2P partner reset.
                                                                 0 = Allow traffic to flow through the NCSI block. */
        uint64_t cmr_ncsi_reset        : 1;  /**< [ 10: 10](R/W) Interface reset for the CMR NCSI block.
                                                                 Upon power up the CMR NCSI is in reset and the companion CNXXXX NCSI block will be
                                                                 commanded by the
                                                                 external BMC to enable one of the CNXXXX CGX NCSI interfaces for passing network traffic.
                                                                 Only one NCSI interface can be enabled in CNXXXX.  The BMC/NCSI will then proceed to
                                                                 configure
                                                                 the rest of the CGX csr for pass through traffic.

                                                                 When set, will reset the CMR NCSI interface effectively disabling it at a traffic boundary
                                                                 should traffic be flowing.  This bit will not reset the main RXB fifos. */
        uint64_t cmr_x2p1_reset        : 1;  /**< [ 11: 11](R/W) If the master block connected to X2P interface 1 is reset, software also needs
                                                                 to reset the X2P interface in the CGX by setting this bit. It resets the X2P
                                                                 interface state in the CGX (skid FIFO and pending requests to the master block)
                                                                 and prevents the RXB FIFOs for all LMACs from pushing data to the
                                                                 interface. Because the X2P and NCSI interfaces share the main RXB FIFOs it will
                                                                 also impact the NCSI interface therefore it is required to set [CMR_NCSI_DROP]
                                                                 bit first before setting this bit.

                                                                 Clearing this does not reset the X2P interface nor NCSI interface.  After the
                                                                 master block comes out of reset, software should clear this bit. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_global_config_s cn; */
} bdk_cgxx_cmr_global_config_t;

static inline uint64_t BDK_CGXX_CMR_GLOBAL_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_GLOBAL_CONFIG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000008ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_GLOBAL_CONFIG", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_GLOBAL_CONFIG(a) bdk_cgxx_cmr_global_config_t
#define bustype_BDK_CGXX_CMR_GLOBAL_CONFIG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_GLOBAL_CONFIG(a) "CGXX_CMR_GLOBAL_CONFIG"
#define device_bar_BDK_CGXX_CMR_GLOBAL_CONFIG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_GLOBAL_CONFIG(a) (a)
#define arguments_BDK_CGXX_CMR_GLOBAL_CONFIG(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_mem_ctrl
 *
 * CGX CMR Memory Control Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_mem_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t txb_fif_m3_syn        : 2;  /**< [ 41: 40](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem3. */
        uint64_t txb_fif_m3_cdis       : 1;  /**< [ 39: 39](R/W) ECC-correction disable for the TXB main mem3. */
        uint64_t txb_fif_m2_syn        : 2;  /**< [ 38: 37](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem2. */
        uint64_t txb_fif_m2_cdis       : 1;  /**< [ 36: 36](R/W) ECC-correction disable for the TXB main mem2. */
        uint64_t txb_ncsi_synd         : 2;  /**< [ 35: 34](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_ncsi_cor_dis      : 1;  /**< [ 33: 33](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m3_synd      : 2;  /**< [ 32: 31](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_skid_m3_cor_dis   : 1;  /**< [ 30: 30](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m2_synd      : 2;  /**< [ 29: 28](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_skid_m2_cor_dis   : 1;  /**< [ 27: 27](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m1_synd      : 2;  /**< [ 26: 25](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_skid_m1_cor_dis   : 1;  /**< [ 24: 24](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m0_synd      : 2;  /**< [ 23: 22](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO. */
        uint64_t txb_skid_m0_cor_dis   : 1;  /**< [ 21: 21](R/W) ECC-correction disable for the TXB SKID FIFO. */
        uint64_t txb_fif_m1_syn        : 2;  /**< [ 20: 19](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem1. */
        uint64_t txb_fif_m1_cdis       : 1;  /**< [ 18: 18](R/W) ECC-correction disable for the TXB main mem1. */
        uint64_t txb_fif_m0_syn        : 2;  /**< [ 17: 16](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem0. */
        uint64_t txb_fif_m0_cdis       : 1;  /**< [ 15: 15](R/W) ECC-correction disable for the TXB main mem0. */
        uint64_t rxb_skid_synd         : 2;  /**< [ 14: 13](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB SKID FIFO. */
        uint64_t rxb_skid_cor_dis      : 1;  /**< [ 12: 12](R/W) ECC-correction disable for the RXB SKID FIFO. */
        uint64_t rxb_fif_bk1_syn1      : 2;  /**< [ 11: 10](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank1 srf1. */
        uint64_t rxb_fif_bk1_cdis1     : 1;  /**< [  9:  9](R/W) ECC-correction disable for the RXB main bank1 srf1. */
        uint64_t rxb_fif_bk1_syn0      : 2;  /**< [  8:  7](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank1 srf0. */
        uint64_t rxb_fif_bk1_cdis0     : 1;  /**< [  6:  6](R/W) ECC-correction disable for the RXB main bank1 srf0. */
        uint64_t rxb_fif_bk0_syn1      : 2;  /**< [  5:  4](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank0 srf1. */
        uint64_t rxb_fif_bk0_cdis1     : 1;  /**< [  3:  3](R/W) ECC-correction disable for the RXB main bank0 srf1. */
        uint64_t rxb_fif_bk0_syn0      : 2;  /**< [  2:  1](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank0 srf0. */
        uint64_t rxb_fif_bk0_cdis0     : 1;  /**< [  0:  0](R/W) ECC-correction disable for the RXB main bank0 srf0. */
#else /* Word 0 - Little Endian */
        uint64_t rxb_fif_bk0_cdis0     : 1;  /**< [  0:  0](R/W) ECC-correction disable for the RXB main bank0 srf0. */
        uint64_t rxb_fif_bk0_syn0      : 2;  /**< [  2:  1](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank0 srf0. */
        uint64_t rxb_fif_bk0_cdis1     : 1;  /**< [  3:  3](R/W) ECC-correction disable for the RXB main bank0 srf1. */
        uint64_t rxb_fif_bk0_syn1      : 2;  /**< [  5:  4](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank0 srf1. */
        uint64_t rxb_fif_bk1_cdis0     : 1;  /**< [  6:  6](R/W) ECC-correction disable for the RXB main bank1 srf0. */
        uint64_t rxb_fif_bk1_syn0      : 2;  /**< [  8:  7](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank1 srf0. */
        uint64_t rxb_fif_bk1_cdis1     : 1;  /**< [  9:  9](R/W) ECC-correction disable for the RXB main bank1 srf1. */
        uint64_t rxb_fif_bk1_syn1      : 2;  /**< [ 11: 10](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB main bank1 srf1. */
        uint64_t rxb_skid_cor_dis      : 1;  /**< [ 12: 12](R/W) ECC-correction disable for the RXB SKID FIFO. */
        uint64_t rxb_skid_synd         : 2;  /**< [ 14: 13](R/W) Syndrome to flip and generate single-bit/double-bit error for RXB SKID FIFO. */
        uint64_t txb_fif_m0_cdis       : 1;  /**< [ 15: 15](R/W) ECC-correction disable for the TXB main mem0. */
        uint64_t txb_fif_m0_syn        : 2;  /**< [ 17: 16](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem0. */
        uint64_t txb_fif_m1_cdis       : 1;  /**< [ 18: 18](R/W) ECC-correction disable for the TXB main mem1. */
        uint64_t txb_fif_m1_syn        : 2;  /**< [ 20: 19](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem1. */
        uint64_t txb_skid_m0_cor_dis   : 1;  /**< [ 21: 21](R/W) ECC-correction disable for the TXB SKID FIFO. */
        uint64_t txb_skid_m0_synd      : 2;  /**< [ 23: 22](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO. */
        uint64_t txb_skid_m1_cor_dis   : 1;  /**< [ 24: 24](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m1_synd      : 2;  /**< [ 26: 25](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_skid_m2_cor_dis   : 1;  /**< [ 27: 27](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m2_synd      : 2;  /**< [ 29: 28](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_skid_m3_cor_dis   : 1;  /**< [ 30: 30](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_skid_m3_synd      : 2;  /**< [ 32: 31](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_ncsi_cor_dis      : 1;  /**< [ 33: 33](R/W) ECC-correction disable for the TXB SKID FIFO */
        uint64_t txb_ncsi_synd         : 2;  /**< [ 35: 34](R/W) Syndrome to flip and generate single-bit/double-bit for TXB SKID FIFO */
        uint64_t txb_fif_m2_cdis       : 1;  /**< [ 36: 36](R/W) ECC-correction disable for the TXB main mem2. */
        uint64_t txb_fif_m2_syn        : 2;  /**< [ 38: 37](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem2. */
        uint64_t txb_fif_m3_cdis       : 1;  /**< [ 39: 39](R/W) ECC-correction disable for the TXB main mem3. */
        uint64_t txb_fif_m3_syn        : 2;  /**< [ 41: 40](R/W) Syndrome to flip and generate single-bit/double-bit error for TXB main mem3. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_mem_ctrl_s cn; */
} bdk_cgxx_cmr_mem_ctrl_t;

static inline uint64_t BDK_CGXX_CMR_MEM_CTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_MEM_CTRL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000030ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_MEM_CTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_MEM_CTRL(a) bdk_cgxx_cmr_mem_ctrl_t
#define bustype_BDK_CGXX_CMR_MEM_CTRL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_MEM_CTRL(a) "CGXX_CMR_MEM_CTRL"
#define device_bar_BDK_CGXX_CMR_MEM_CTRL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_MEM_CTRL(a) (a)
#define arguments_BDK_CGXX_CMR_MEM_CTRL(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_mem_int
 *
 * CGX CMR Memory Interrupt Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_mem_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1C/H) TXB Main FIFO Mem3 single-bit error. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1C/H) TXB Main FIFO Mem3 double-bit error. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1C/H) TXB Main FIFO Mem2 single-bit error. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1C/H) TXB Main FIFO Mem2 double-bit error. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1C/H) TXB SKID NIC FIFO single-bit error */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1C/H) TXB SKID FIFO single-bit error */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1C/H) TXB SKID NIC FIFO single-bit error */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1C/H) TXB SKID NCSI FIFO single-bit error */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1C/H) TXB SKID NCSI FIFO double-bit error */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1C/H) TXB SKID PKO FIFO single-bit error */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1C/H) TXB SKID PKO FIFO double-bit error */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1C/H) TXB SKID PKO FIFO single-bit error */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1C/H) TXB SKID PKO FIFO double-bit error */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1C/H) TXB SKID PKO FIFO single-bit error */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1C/H) TXB SKID PKO FIFO double-bit error */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1C/H) RX SMU INFIFO overflow. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1C/H) RX GMP INFIFO overflow. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1C/H) TXB SKID PKO FIFO single-bit error. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1C/H) TXB SKID PKO FIFO double-bit error. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1C/H) TXB Main FIFO Mem1 single-bit error. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1C/H) TXB Main FIFO Mem1 double-bit error. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1C/H) TXB Main FIFO Mem0 single-bit error. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1C/H) TXB Main FIFO Mem0 double-bit error. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1C/H) RXB NIC SKID FIFO single-bit error. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1C/H) RXB NIC SKID FIFO double-bit error. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1C/H) RXB PKI SKID FIFO single-bit error. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1C/H) RXB PKI SKID FIFO double-bit error. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1C/H) RXB main FIFO bank1 srf1 single-bit error. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1C/H) RXB main FIFO bank1 srf1 double-bit error. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1C/H) RXB main FIFO bank1 srf0 single-bit error. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1C/H) RXB main FIFO bank1 srf0 double-bit error. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1C/H) RXB main FIFO bank0 srf1 single-bit error. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1C/H) RXB main FIFO bank0 srf1 double-bit error. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1C/H) RXB main FIFO bank0 srf0 single-bit error. */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1C/H) RXB main FIFO bank0 srf0 double-bit error. */
#else /* Word 0 - Little Endian */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1C/H) RXB main FIFO bank0 srf0 double-bit error. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1C/H) RXB main FIFO bank0 srf0 single-bit error. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1C/H) RXB main FIFO bank0 srf1 double-bit error. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1C/H) RXB main FIFO bank0 srf1 single-bit error. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1C/H) RXB main FIFO bank1 srf0 double-bit error. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1C/H) RXB main FIFO bank1 srf0 single-bit error. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1C/H) RXB main FIFO bank1 srf1 double-bit error. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1C/H) RXB main FIFO bank1 srf1 single-bit error. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1C/H) RXB PKI SKID FIFO double-bit error. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1C/H) RXB PKI SKID FIFO single-bit error. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1C/H) RXB NIC SKID FIFO double-bit error. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1C/H) RXB NIC SKID FIFO single-bit error. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1C/H) TXB Main FIFO Mem0 double-bit error. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1C/H) TXB Main FIFO Mem0 single-bit error. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1C/H) TXB Main FIFO Mem1 double-bit error. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1C/H) TXB Main FIFO Mem1 single-bit error. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1C/H) TXB SKID PKO FIFO double-bit error. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1C/H) TXB SKID PKO FIFO single-bit error. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1C/H) RX GMP INFIFO overflow. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1C/H) RX SMU INFIFO overflow. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1C/H) TXB SKID PKO FIFO double-bit error */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1C/H) TXB SKID PKO FIFO single-bit error */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1C/H) TXB SKID PKO FIFO double-bit error */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1C/H) TXB SKID PKO FIFO single-bit error */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1C/H) TXB SKID PKO FIFO double-bit error */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1C/H) TXB SKID PKO FIFO single-bit error */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1C/H) TXB SKID NCSI FIFO double-bit error */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1C/H) TXB SKID NCSI FIFO single-bit error */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1C/H) TXB SKID NIC FIFO single-bit error */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1C/H) TXB SKID FIFO single-bit error */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1C/H) TXB SKID NIC FIFO double-bit error */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1C/H) TXB SKID NIC FIFO single-bit error */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1C/H) TXB Main FIFO Mem2 double-bit error. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1C/H) TXB Main FIFO Mem2 single-bit error. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1C/H) TXB Main FIFO Mem3 double-bit error. */
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1C/H) TXB Main FIFO Mem3 single-bit error. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_mem_int_s cn; */
} bdk_cgxx_cmr_mem_int_t;

static inline uint64_t BDK_CGXX_CMR_MEM_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_MEM_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000010ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_MEM_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_MEM_INT(a) bdk_cgxx_cmr_mem_int_t
#define bustype_BDK_CGXX_CMR_MEM_INT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_MEM_INT(a) "CGXX_CMR_MEM_INT"
#define device_bar_BDK_CGXX_CMR_MEM_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_MEM_INT(a) (a)
#define arguments_BDK_CGXX_CMR_MEM_INT(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_mem_int_ena_w1c
 *
 * CGX CMR Memory Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_mem_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_SBE]. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_DBE]. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_SBE]. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_DBE]. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_SBE]. */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_DBE]. */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_SBE]. */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_DBE]. */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_SBE]. */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_DBE]. */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_SBE]. */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_DBE]. */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_SBE]. */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_DBE]. */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_SBE]. */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_DBE]. */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_SBE]. */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_DBE]. */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_SBE]. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_DBE]. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[SMU_IN_OVERFL]. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[GMP_IN_OVERFL]. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_SBE]. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_DBE]. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_SBE]. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_DBE]. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_SBE]. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_DBE]. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_SBE]. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_DBE]. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_SBE]. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_DBE]. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE1]. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE1]. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE0]. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE0]. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE1]. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE1]. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE0]. */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE0]. */
#else /* Word 0 - Little Endian */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE0]. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE0]. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE1]. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE1]. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE0]. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE0]. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE1]. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE1]. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_DBE]. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_SBE]. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_DBE]. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_SBE]. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_DBE]. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_SBE]. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_DBE]. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_SBE]. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_DBE]. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_SBE]. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[GMP_IN_OVERFL]. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[SMU_IN_OVERFL]. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_DBE]. */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_SBE]. */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_DBE]. */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_SBE]. */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_DBE]. */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_SBE]. */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_DBE]. */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_SBE]. */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_DBE]. */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_SBE]. */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_DBE]. */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_SBE]. */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_DBE]. */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_SBE]. */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_DBE]. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_SBE]. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_DBE]. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_SBE]. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_DBE]. */
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1C/H) Reads or clears enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_SBE]. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_mem_int_ena_w1c_s cn; */
} bdk_cgxx_cmr_mem_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_CMR_MEM_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_MEM_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000020ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_MEM_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_MEM_INT_ENA_W1C(a) bdk_cgxx_cmr_mem_int_ena_w1c_t
#define bustype_BDK_CGXX_CMR_MEM_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_MEM_INT_ENA_W1C(a) "CGXX_CMR_MEM_INT_ENA_W1C"
#define device_bar_BDK_CGXX_CMR_MEM_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_MEM_INT_ENA_W1C(a) (a)
#define arguments_BDK_CGXX_CMR_MEM_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_mem_int_ena_w1s
 *
 * CGX CMR Memory Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_mem_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_SBE]. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_DBE]. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_SBE]. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_DBE]. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_SBE]. */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_DBE]. */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_SBE]. */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_DBE]. */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_SBE]. */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_DBE]. */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_SBE]. */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_DBE]. */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_SBE]. */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_DBE]. */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_SBE]. */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_DBE]. */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_SBE]. */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_DBE]. */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_SBE]. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_DBE]. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[SMU_IN_OVERFL]. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[GMP_IN_OVERFL]. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_SBE]. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_DBE]. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_SBE]. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_DBE]. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_SBE]. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_DBE]. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_SBE]. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_DBE]. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_SBE]. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_DBE]. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE1]. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE1]. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE0]. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE0]. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE1]. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE1]. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE0]. */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE0]. */
#else /* Word 0 - Little Endian */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE0]. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE0]. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE1]. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE1]. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE0]. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE0]. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE1]. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE1]. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_DBE]. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_SBE]. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_DBE]. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_SBE]. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_DBE]. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_SBE]. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_DBE]. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_SBE]. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_DBE]. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_SBE]. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[GMP_IN_OVERFL]. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[SMU_IN_OVERFL]. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_DBE]. */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_SBE]. */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_DBE]. */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_SBE]. */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_DBE]. */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_SBE]. */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_DBE]. */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_NCSI_SBE]. */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_DBE]. */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_SBE]. */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_DBE]. */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_SBE]. */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_DBE]. */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_SBE]. */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_DBE]. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_SBE]. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_DBE]. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_SBE]. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_DBE]. */
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets enable for CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_SBE]. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_mem_int_ena_w1s_s cn; */
} bdk_cgxx_cmr_mem_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_CMR_MEM_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_MEM_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000028ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_MEM_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_MEM_INT_ENA_W1S(a) bdk_cgxx_cmr_mem_int_ena_w1s_t
#define bustype_BDK_CGXX_CMR_MEM_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_MEM_INT_ENA_W1S(a) "CGXX_CMR_MEM_INT_ENA_W1S"
#define device_bar_BDK_CGXX_CMR_MEM_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_MEM_INT_ENA_W1S(a) (a)
#define arguments_BDK_CGXX_CMR_MEM_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_mem_int_w1s
 *
 * CGX CMR Memory Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_mem_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_40_63        : 24;
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_SBE]. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_DBE]. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_SBE]. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_DBE]. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_SBE]. */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_DBE]. */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_SBE]. */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_DBE]. */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_SBE]. */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_DBE]. */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_SBE]. */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_DBE]. */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_NCSI_SBE]. */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_NCSI_DBE]. */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_SBE]. */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_DBE]. */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_SBE]. */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_DBE]. */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_SBE]. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_DBE]. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[SMU_IN_OVERFL]. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[GMP_IN_OVERFL]. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_SBE]. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_DBE]. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_SBE]. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_DBE]. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_SBE]. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_DBE]. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_SBE]. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_DBE]. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_SBE]. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_DBE]. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE1]. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE1]. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE0]. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE0]. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE1]. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE1]. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE0]. */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE0]. */
#else /* Word 0 - Little Endian */
        uint64_t rxb_fif_bk0_dbe0      : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE0]. */
        uint64_t rxb_fif_bk0_sbe0      : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE0]. */
        uint64_t rxb_fif_bk0_dbe1      : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_DBE1]. */
        uint64_t rxb_fif_bk0_sbe1      : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK0_SBE1]. */
        uint64_t rxb_fif_bk1_dbe0      : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE0]. */
        uint64_t rxb_fif_bk1_sbe0      : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE0]. */
        uint64_t rxb_fif_bk1_dbe1      : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_DBE1]. */
        uint64_t rxb_fif_bk1_sbe1      : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_FIF_BK1_SBE1]. */
        uint64_t rxb_pki_skid_dbe      : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_DBE]. */
        uint64_t rxb_pki_skid_sbe      : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_PKI_SKID_SBE]. */
        uint64_t rxb_nic_skid_dbe      : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_DBE]. */
        uint64_t rxb_nic_skid_sbe      : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[RXB_NIC_SKID_SBE]. */
        uint64_t txb_fif_m0_dbe        : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_DBE]. */
        uint64_t txb_fif_m0_sbe        : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M0_SBE]. */
        uint64_t txb_fif_m1_dbe        : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_DBE]. */
        uint64_t txb_fif_m1_sbe        : 1;  /**< [ 15: 15](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M1_SBE]. */
        uint64_t txb_skid_m0_pko_dbe   : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_DBE]. */
        uint64_t txb_skid_m0_pko_sbe   : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_PKO_SBE]. */
        uint64_t gmp_in_overfl         : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[GMP_IN_OVERFL]. */
        uint64_t smu_in_overfl         : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[SMU_IN_OVERFL]. */
        uint64_t txb_skid_m1_pko_dbe   : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_DBE]. */
        uint64_t txb_skid_m1_pko_sbe   : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_PKO_SBE]. */
        uint64_t txb_skid_m2_pko_dbe   : 1;  /**< [ 22: 22](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_DBE]. */
        uint64_t txb_skid_m2_pko_sbe   : 1;  /**< [ 23: 23](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_PKO_SBE]. */
        uint64_t txb_skid_m3_pko_dbe   : 1;  /**< [ 24: 24](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_DBE]. */
        uint64_t txb_skid_m3_pko_sbe   : 1;  /**< [ 25: 25](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_PKO_SBE]. */
        uint64_t txb_ncsi_dbe          : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_NCSI_DBE]. */
        uint64_t txb_ncsi_sbe          : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_NCSI_SBE]. */
        uint64_t txb_skid_m0_nic_dbe   : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_DBE]. */
        uint64_t txb_skid_m0_nic_sbe   : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M0_NIC_SBE]. */
        uint64_t txb_skid_m1_nic_dbe   : 1;  /**< [ 30: 30](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_DBE]. */
        uint64_t txb_skid_m1_nic_sbe   : 1;  /**< [ 31: 31](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M1_NIC_SBE]. */
        uint64_t txb_skid_m2_nic_dbe   : 1;  /**< [ 32: 32](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_DBE]. */
        uint64_t txb_skid_m2_nic_sbe   : 1;  /**< [ 33: 33](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M2_NIC_SBE]. */
        uint64_t txb_skid_m3_nic_dbe   : 1;  /**< [ 34: 34](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_DBE]. */
        uint64_t txb_skid_m3_nic_sbe   : 1;  /**< [ 35: 35](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_SKID_M3_NIC_SBE]. */
        uint64_t txb_fif_m2_dbe        : 1;  /**< [ 36: 36](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_DBE]. */
        uint64_t txb_fif_m2_sbe        : 1;  /**< [ 37: 37](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M2_SBE]. */
        uint64_t txb_fif_m3_dbe        : 1;  /**< [ 38: 38](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_DBE]. */
        uint64_t txb_fif_m3_sbe        : 1;  /**< [ 39: 39](R/W1S/H) Reads or sets CGX(0..3)_CMR_MEM_INT[TXB_FIF_M3_SBE]. */
        uint64_t reserved_40_63        : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_mem_int_w1s_s cn; */
} bdk_cgxx_cmr_mem_int_w1s_t;

static inline uint64_t BDK_CGXX_CMR_MEM_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_MEM_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000018ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_MEM_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_MEM_INT_W1S(a) bdk_cgxx_cmr_mem_int_w1s_t
#define bustype_BDK_CGXX_CMR_MEM_INT_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_MEM_INT_W1S(a) "CGXX_CMR_MEM_INT_W1S"
#define device_bar_BDK_CGXX_CMR_MEM_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_MEM_INT_W1S(a) (a)
#define arguments_BDK_CGXX_CMR_MEM_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_nic_nxc_adr
 *
 * CGX CMR NIC NXC Exception Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_nic_nxc_adr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t lmac_id               : 4;  /**< [ 15: 12](RO/H) Logged LMAC ID associated with NXC exceptions associated with NIC. */
        uint64_t channel               : 12; /**< [ 11:  0](RO/H) Logged channel for NXC exceptions associated with NIC. */
#else /* Word 0 - Little Endian */
        uint64_t channel               : 12; /**< [ 11:  0](RO/H) Logged channel for NXC exceptions associated with NIC. */
        uint64_t lmac_id               : 4;  /**< [ 15: 12](RO/H) Logged LMAC ID associated with NXC exceptions associated with NIC. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_nic_nxc_adr_s cn; */
} bdk_cgxx_cmr_nic_nxc_adr_t;

static inline uint64_t BDK_CGXX_CMR_NIC_NXC_ADR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_NIC_NXC_ADR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8001030ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_NIC_NXC_ADR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_NIC_NXC_ADR(a) bdk_cgxx_cmr_nic_nxc_adr_t
#define bustype_BDK_CGXX_CMR_NIC_NXC_ADR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_NIC_NXC_ADR(a) "CGXX_CMR_NIC_NXC_ADR"
#define device_bar_BDK_CGXX_CMR_NIC_NXC_ADR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_NIC_NXC_ADR(a) (a)
#define arguments_BDK_CGXX_CMR_NIC_NXC_ADR(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_pko_nxc_adr
 *
 * CGX CMR PKO NXC Exception Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_pko_nxc_adr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t lmac_id               : 4;  /**< [ 15: 12](RO/H) Logged LMAC ID associated with NXC exceptions associated with PKO. */
        uint64_t channel               : 12; /**< [ 11:  0](RO/H) Logged channel for NXC exceptions associated with PKO. */
#else /* Word 0 - Little Endian */
        uint64_t channel               : 12; /**< [ 11:  0](RO/H) Logged channel for NXC exceptions associated with PKO. */
        uint64_t lmac_id               : 4;  /**< [ 15: 12](RO/H) Logged LMAC ID associated with NXC exceptions associated with PKO. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_pko_nxc_adr_s cn; */
} bdk_cgxx_cmr_pko_nxc_adr_t;

static inline uint64_t BDK_CGXX_CMR_PKO_NXC_ADR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_PKO_NXC_ADR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8001018ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_PKO_NXC_ADR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_PKO_NXC_ADR(a) bdk_cgxx_cmr_pko_nxc_adr_t
#define bustype_BDK_CGXX_CMR_PKO_NXC_ADR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_PKO_NXC_ADR(a) "CGXX_CMR_PKO_NXC_ADR"
#define device_bar_BDK_CGXX_CMR_PKO_NXC_ADR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_PKO_NXC_ADR(a) (a)
#define arguments_BDK_CGXX_CMR_PKO_NXC_ADR(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_dmac#_cam
 *
 * CGX CMR Receive CAM Registers
 * These registers provide access to the 32 DMAC CAM entries in CGX.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_dmacx_cam_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_51_63        : 13;
        uint64_t id                    : 2;  /**< [ 50: 49](R/W) Logical MAC ID that this DMAC CAM address applies to. CGX has 32 DMAC CAM entries that can
                                                                 be accessed with the CGX()_CMR_RX_DMAC()_CAM CSRs. These 32 DMAC entries can be used by
                                                                 any of the four SGMII MACs or the 10G/40G MACs using these register bits.

                                                                 A typical configuration is to provide eight CAM entries per LMAC ID, which is configured
                                                                 using the following settings:
                                                                 * LMAC interface 0: CGX()_CMR_RX_DMAC(0..7)_CAM[ID] = 0x0.
                                                                 * LMAC interface 1: CGX()_CMR_RX_DMAC(8..15)_CAM[ID] = 0x1.
                                                                 * LMAC interface 2: CGX()_CMR_RX_DMAC(16..23)_CAM[ID] = 0x2.
                                                                 * LMAC interface 3: CGX()_CMR_RX_DMAC(24..31)_CAM[ID] = 0x3. */
        uint64_t en                    : 1;  /**< [ 48: 48](R/W) CAM entry enable for this DMAC address.
                                                                 1 = Include this address in the matching algorithm.
                                                                 0 = Don't include this address in the matching algorithm. */
        uint64_t adr                   : 48; /**< [ 47:  0](R/W) DMAC address in the CAM used for matching. Specified in network byte order, i.e.
                                                                 ADR<47:40> is for the first DMAC byte on the wire. The CAM matches against unicast or
                                                                 multicast DMAC addresses. All CGX()_CMR_RX_DMAC()_CAM CSRs can be used in any of the LMAC
                                                                 combinations such that any CGX MAC can use any of the 32 common DMAC entries. */
#else /* Word 0 - Little Endian */
        uint64_t adr                   : 48; /**< [ 47:  0](R/W) DMAC address in the CAM used for matching. Specified in network byte order, i.e.
                                                                 ADR<47:40> is for the first DMAC byte on the wire. The CAM matches against unicast or
                                                                 multicast DMAC addresses. All CGX()_CMR_RX_DMAC()_CAM CSRs can be used in any of the LMAC
                                                                 combinations such that any CGX MAC can use any of the 32 common DMAC entries. */
        uint64_t en                    : 1;  /**< [ 48: 48](R/W) CAM entry enable for this DMAC address.
                                                                 1 = Include this address in the matching algorithm.
                                                                 0 = Don't include this address in the matching algorithm. */
        uint64_t id                    : 2;  /**< [ 50: 49](R/W) Logical MAC ID that this DMAC CAM address applies to. CGX has 32 DMAC CAM entries that can
                                                                 be accessed with the CGX()_CMR_RX_DMAC()_CAM CSRs. These 32 DMAC entries can be used by
                                                                 any of the four SGMII MACs or the 10G/40G MACs using these register bits.

                                                                 A typical configuration is to provide eight CAM entries per LMAC ID, which is configured
                                                                 using the following settings:
                                                                 * LMAC interface 0: CGX()_CMR_RX_DMAC(0..7)_CAM[ID] = 0x0.
                                                                 * LMAC interface 1: CGX()_CMR_RX_DMAC(8..15)_CAM[ID] = 0x1.
                                                                 * LMAC interface 2: CGX()_CMR_RX_DMAC(16..23)_CAM[ID] = 0x2.
                                                                 * LMAC interface 3: CGX()_CMR_RX_DMAC(24..31)_CAM[ID] = 0x3. */
        uint64_t reserved_51_63        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_dmacx_cam_s cn; */
} bdk_cgxx_cmr_rx_dmacx_cam_t;

static inline uint64_t BDK_CGXX_CMR_RX_DMACX_CAM(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_DMACX_CAM(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=31)))
        return 0x87e0e8000200ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x1f);
    __bdk_csr_fatal("CGXX_CMR_RX_DMACX_CAM", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_DMACX_CAM(a,b) bdk_cgxx_cmr_rx_dmacx_cam_t
#define bustype_BDK_CGXX_CMR_RX_DMACX_CAM(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_DMACX_CAM(a,b) "CGXX_CMR_RX_DMACX_CAM"
#define device_bar_BDK_CGXX_CMR_RX_DMACX_CAM(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_DMACX_CAM(a,b) (a)
#define arguments_BDK_CGXX_CMR_RX_DMACX_CAM(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_lmacs
 *
 * CGX CMR Receive Logical MACs Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_lmacs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t lmacs                 : 3;  /**< [  2:  0](R/W) Number of LMACS. Specifies the number of LMACs that can be enabled.
                                                                 This determines the logical RX buffer size per LMAC and the maximum
                                                                 LMAC ID that can be used:

                                                                 0x0 = Reserved.
                                                                 0x1 = CGX()_CONST[TX_FIFOSZ] bytes per LMAC, maximum LMAC ID is 0.
                                                                 0x2 = CGX()_CONST[TX_FIFOSZ]/2 bytes per LMAC, maximum LMAC ID is 1.
                                                                 0x3 = CGX()_CONST[TX_FIFOSZ]/4 bytes per LMAC, maximum LMAC ID is 2.
                                                                 0x4 = CGX()_CONST[TX_FIFOSZ]/4 bytes per LMAC, maximum LMAC ID is 3.
                                                                 0x5-0x7 = Reserved.

                                                                 Note the maximum LMAC ID is determined by the smaller of
                                                                 CGX()_CMR_RX_LMACS[LMACS] and CGX()_CMR_TX_LMACS[LMACS]. The two fields
                                                                 should be set to the same value for normal operation. */
#else /* Word 0 - Little Endian */
        uint64_t lmacs                 : 3;  /**< [  2:  0](R/W) Number of LMACS. Specifies the number of LMACs that can be enabled.
                                                                 This determines the logical RX buffer size per LMAC and the maximum
                                                                 LMAC ID that can be used:

                                                                 0x0 = Reserved.
                                                                 0x1 = CGX()_CONST[TX_FIFOSZ] bytes per LMAC, maximum LMAC ID is 0.
                                                                 0x2 = CGX()_CONST[TX_FIFOSZ]/2 bytes per LMAC, maximum LMAC ID is 1.
                                                                 0x3 = CGX()_CONST[TX_FIFOSZ]/4 bytes per LMAC, maximum LMAC ID is 2.
                                                                 0x4 = CGX()_CONST[TX_FIFOSZ]/4 bytes per LMAC, maximum LMAC ID is 3.
                                                                 0x5-0x7 = Reserved.

                                                                 Note the maximum LMAC ID is determined by the smaller of
                                                                 CGX()_CMR_RX_LMACS[LMACS] and CGX()_CMR_TX_LMACS[LMACS]. The two fields
                                                                 should be set to the same value for normal operation. */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_lmacs_s cn; */
} bdk_cgxx_cmr_rx_lmacs_t;

static inline uint64_t BDK_CGXX_CMR_RX_LMACS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_LMACS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000468ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_RX_LMACS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_LMACS(a) bdk_cgxx_cmr_rx_lmacs_t
#define bustype_BDK_CGXX_CMR_RX_LMACS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_LMACS(a) "CGXX_CMR_RX_LMACS"
#define device_bar_BDK_CGXX_CMR_RX_LMACS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_LMACS(a) (a)
#define arguments_BDK_CGXX_CMR_RX_LMACS(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_ovr_bp
 *
 * CGX CMR Receive-Ports Backpressure Override Registers
 * Per-LMAC backpressure override register.
 * For SMU, CGX()_CMR_RX_OVR_BP[EN]<0> must be set to one and CGX()_CMR_RX_OVR_BP[BP]<0> must be
 * cleared to zero (to forcibly disable hardware-automatic 802.3 PAUSE packet generation) with
 * the HiGig2 Protocol when CGX()_SMU()_HG2_CONTROL[HG2TX_EN]=0. (The HiGig2 protocol is
 * indicated by CGX()_SMU()_TX_CTL[HG_EN]=1 and CGX()_SMU()_RX_UDD_SKP[LEN]=16).
 * Hardware can only auto-generate backpressure through HiGig2 messages (optionally, when
 * CGX()_SMU()_HG2_CONTROL[HG2TX_EN]=1) with the HiGig2 protocol.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_ovr_bp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t en                    : 4;  /**< [ 11:  8](R/W) Per-LMAC enable backpressure override.
                                                                 0 = Don't enable.
                                                                 1 = Enable override.

                                                                 Bit<8> represents LMAC 0, ..., bit<11> represents LMAC 3. */
        uint64_t bp                    : 4;  /**< [  7:  4](R/W) Per-LMAC backpressure status to use:
                                                                 0 = LMAC is available.
                                                                 1 = LMAC should be backpressured.

                                                                 Bit<4> represents LMAC 0, ..., bit<7> represents LMAC 3. */
        uint64_t ign_fifo_bp           : 4;  /**< [  3:  0](R/W) Ignore CGX()_CMR()_RX_BP_ON[MARK] when computing backpressure. CMR does not backpressure
                                                                 the
                                                                 MAC due to the FIFO length passing CGX()_CMR()_RX_BP_ON[MARK]. */
#else /* Word 0 - Little Endian */
        uint64_t ign_fifo_bp           : 4;  /**< [  3:  0](R/W) Ignore CGX()_CMR()_RX_BP_ON[MARK] when computing backpressure. CMR does not backpressure
                                                                 the
                                                                 MAC due to the FIFO length passing CGX()_CMR()_RX_BP_ON[MARK]. */
        uint64_t bp                    : 4;  /**< [  7:  4](R/W) Per-LMAC backpressure status to use:
                                                                 0 = LMAC is available.
                                                                 1 = LMAC should be backpressured.

                                                                 Bit<4> represents LMAC 0, ..., bit<7> represents LMAC 3. */
        uint64_t en                    : 4;  /**< [ 11:  8](R/W) Per-LMAC enable backpressure override.
                                                                 0 = Don't enable.
                                                                 1 = Enable override.

                                                                 Bit<8> represents LMAC 0, ..., bit<11> represents LMAC 3. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_ovr_bp_s cn; */
} bdk_cgxx_cmr_rx_ovr_bp_t;

static inline uint64_t BDK_CGXX_CMR_RX_OVR_BP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_OVR_BP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000470ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_RX_OVR_BP", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_OVR_BP(a) bdk_cgxx_cmr_rx_ovr_bp_t
#define bustype_BDK_CGXX_CMR_RX_OVR_BP(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_OVR_BP(a) "CGXX_CMR_RX_OVR_BP"
#define device_bar_BDK_CGXX_CMR_RX_OVR_BP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_OVR_BP(a) (a)
#define arguments_BDK_CGXX_CMR_RX_OVR_BP(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_stat10
 *
 * CGX Receive Status Register 10
 * This register provide a count of octets of dropped at the NCSI interface.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_stat10_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of dropped NCSI packets. [CNT] will wrap and is cleared if NCSI is reset with
                                                                 CGX()_CMR_GLOBAL_CONFIG[CMR_NCSI_RESET]. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Octet count of dropped NCSI packets. [CNT] will wrap and is cleared if NCSI is reset with
                                                                 CGX()_CMR_GLOBAL_CONFIG[CMR_NCSI_RESET]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_stat10_s cn; */
} bdk_cgxx_cmr_rx_stat10_t;

static inline uint64_t BDK_CGXX_CMR_RX_STAT10(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_STAT10(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e80000c0ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_RX_STAT10", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_STAT10(a) bdk_cgxx_cmr_rx_stat10_t
#define bustype_BDK_CGXX_CMR_RX_STAT10(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_STAT10(a) "CGXX_CMR_RX_STAT10"
#define device_bar_BDK_CGXX_CMR_RX_STAT10(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_STAT10(a) (a)
#define arguments_BDK_CGXX_CMR_RX_STAT10(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_stat9
 *
 * CGX Receive Status Register 9
 * This registers provides a count of packets dropped at the NCSI interface.
 * The count of dropped NCSI packets is not accounted for in any other stats
 * registers.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_stat9_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of dropped packets. [CNT] will wrap and is cleared if NCSI is reset with
                                                                 CGX()_CMR_GLOBAL_CONFIG[CMR_NCSI_RESET]. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 48; /**< [ 47:  0](R/W/H) Count of dropped packets. [CNT] will wrap and is cleared if NCSI is reset with
                                                                 CGX()_CMR_GLOBAL_CONFIG[CMR_NCSI_RESET]. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_stat9_s cn; */
} bdk_cgxx_cmr_rx_stat9_t;

static inline uint64_t BDK_CGXX_CMR_RX_STAT9(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_STAT9(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e80000b8ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_RX_STAT9", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_STAT9(a) bdk_cgxx_cmr_rx_stat9_t
#define bustype_BDK_CGXX_CMR_RX_STAT9(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_STAT9(a) "CGXX_CMR_RX_STAT9"
#define device_bar_BDK_CGXX_CMR_RX_STAT9(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_STAT9(a) (a)
#define arguments_BDK_CGXX_CMR_RX_STAT9(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_steering#
 *
 * CGX CMR Receive Steering Registers
 * These registers, along with CGX()_CMR_RX_STEERING_VETYPE(), provide eight filters for
 * identifying and steering NCSI receive traffic.
 *
 * Steering is done for the designated LMAC specified by CGX()_CMR_GLOBAL_CONFIG[NCSI_LMAC_ID].
 * The steering algorithm is applied after the RX DMAC filter specified by
 * CGX()_CMR()_RX_DMAC_CTL and CGX()_CMR_RX_DMAC()_CAM. As such, the DMAC filter and steering
 * filters should be set in a consistent manner.
 *
 * Internal:
 * "* ALGORITHM
 * // Steering of RX packets for LMAC identified by CGX()_CMR_GLOBAL_CONFIG[NCSI_LMAC_ID].
 * rx_steering(uint48 pkt_dmac, uint16 pkt_etype, uint16 pkt_vlan_id) {
 *    for (int i = 0; i < 8; i++) {
 *       steer = CGX()_CMR_RX_STEERING(i);
 *       vetype = CGX()_CMR_RX_STEERING_VETYPE(i);
 *       if (steer[MCST_EN] || steer[DMAC_EN] || vetype[VLAN_EN] || vetype[VLAN_TAG_EN]) {
 *          // Filter is enabled.
 *          if (   (!steer[MCST_EN] || is_mcst(pkt_dmac))
 *              && (!steer[DMAC_EN] || pkt_dmac != steer[DMAC])
 *              && (!vetype[VLAN_EN] || pkt_vlan_id != vetype[VLAN_ID])
 *              && (!vetype[VLAN_TAG_EN] || pkt_etype != vetype[VLAN_ETYPE]) )
 *          {
 *             // Filter match (all enabled matching criteria are met).
 *             return steer[DEST];
 *          }
 *       }
 *    }
 *    return CGX()_CMR_RX_STEERING_DEFAULT[DEST]; // No match
 * }"
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_steeringx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t dest                  : 2;  /**< [ 51: 50](R/W) Destination for traffic that meets all criteria of the matching algorithm:
                                                                 0x0 = Steer this traffic exclusively to NCSI.
                                                                 0x1 = Steer this traffic exclusively to NIC.
                                                                 0x2 = Steer this traffic to BOTH NIC and NCSI.
                                                                 0x3 = Steer this traffic to the bit bucket (drop). */
        uint64_t mcst_en               : 1;  /**< [ 49: 49](R/W) Enable for identifying multicast packets:
                                                                 1 = Include multicast packets in the matching algorithm.
                                                                 0 = Do not include multicast packets in the matching algorithm. */
        uint64_t dmac_en               : 1;  /**< [ 48: 48](R/W) Enable DMAC address check:
                                                                 1 = Include DMAC address checking in the matching algorithm.
                                                                 0 = Do not include DMAC address checking in the matching algorithm. */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) DMAC address used for the matching algorithm when [DMAC_EN] is set. Broadcast can be
                                                                 specified with value 0xFFFF_FFFFFFFF. */
#else /* Word 0 - Little Endian */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) DMAC address used for the matching algorithm when [DMAC_EN] is set. Broadcast can be
                                                                 specified with value 0xFFFF_FFFFFFFF. */
        uint64_t dmac_en               : 1;  /**< [ 48: 48](R/W) Enable DMAC address check:
                                                                 1 = Include DMAC address checking in the matching algorithm.
                                                                 0 = Do not include DMAC address checking in the matching algorithm. */
        uint64_t mcst_en               : 1;  /**< [ 49: 49](R/W) Enable for identifying multicast packets:
                                                                 1 = Include multicast packets in the matching algorithm.
                                                                 0 = Do not include multicast packets in the matching algorithm. */
        uint64_t dest                  : 2;  /**< [ 51: 50](R/W) Destination for traffic that meets all criteria of the matching algorithm:
                                                                 0x0 = Steer this traffic exclusively to NCSI.
                                                                 0x1 = Steer this traffic exclusively to NIC.
                                                                 0x2 = Steer this traffic to BOTH NIC and NCSI.
                                                                 0x3 = Steer this traffic to the bit bucket (drop). */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_steeringx_s cn; */
} bdk_cgxx_cmr_rx_steeringx_t;

static inline uint64_t BDK_CGXX_CMR_RX_STEERINGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_STEERINGX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=7)))
        return 0x87e0e8000300ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("CGXX_CMR_RX_STEERINGX", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_STEERINGX(a,b) bdk_cgxx_cmr_rx_steeringx_t
#define bustype_BDK_CGXX_CMR_RX_STEERINGX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_STEERINGX(a,b) "CGXX_CMR_RX_STEERINGX"
#define device_bar_BDK_CGXX_CMR_RX_STEERINGX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_STEERINGX(a,b) (a)
#define arguments_BDK_CGXX_CMR_RX_STEERINGX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_steering_default
 *
 * CGX CMR Receive Steering Default Destination Register
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_steering_default_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t dest                  : 2;  /**< [  1:  0](R/W) Destination for traffic that does not match any of the steering filters specified by
                                                                 CGX()_CMR_RX_STEERING() and and CGX()_CMR_RX_STEERING_VETYPE():
                                                                 0x0 = Steer traffic exclusively to NCSI.
                                                                 0x1 = Steer traffic exclusively to NIC.
                                                                 0x2 = Steer traffic to BOTH NIC and NCSI.
                                                                 0x3 = Steer traffic to the bit bucket (drop). */
#else /* Word 0 - Little Endian */
        uint64_t dest                  : 2;  /**< [  1:  0](R/W) Destination for traffic that does not match any of the steering filters specified by
                                                                 CGX()_CMR_RX_STEERING() and and CGX()_CMR_RX_STEERING_VETYPE():
                                                                 0x0 = Steer traffic exclusively to NCSI.
                                                                 0x1 = Steer traffic exclusively to NIC.
                                                                 0x2 = Steer traffic to BOTH NIC and NCSI.
                                                                 0x3 = Steer traffic to the bit bucket (drop). */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_steering_default_s cn; */
} bdk_cgxx_cmr_rx_steering_default_t;

static inline uint64_t BDK_CGXX_CMR_RX_STEERING_DEFAULT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_STEERING_DEFAULT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8000448ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_RX_STEERING_DEFAULT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_STEERING_DEFAULT(a) bdk_cgxx_cmr_rx_steering_default_t
#define bustype_BDK_CGXX_CMR_RX_STEERING_DEFAULT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_STEERING_DEFAULT(a) "CGXX_CMR_RX_STEERING_DEFAULT"
#define device_bar_BDK_CGXX_CMR_RX_STEERING_DEFAULT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_STEERING_DEFAULT(a) (a)
#define arguments_BDK_CGXX_CMR_RX_STEERING_DEFAULT(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_cmr_rx_steering_vetype#
 *
 * CGX CMR Receive VLAN Ethertype Register
 * These registers, along with CGX()_CMR_RX_STEERING(), provide eight filters for identifying and
 * steering NCSI receive traffic.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_rx_steering_vetypex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t vlan_en               : 1;  /**< [ 29: 29](R/W) Enable VLAN ID check:
                                                                 1 = Include VLAN ID checking in the matching algorithm.
                                                                 0 = Do not include VLAN ID checking in the matching algorithm. */
        uint64_t vlan_id               : 12; /**< [ 28: 17](R/W) VLAN ID used for the matching algorithm when [VLAN_EN] is set. */
        uint64_t vlan_tag_en           : 1;  /**< [ 16: 16](R/W) Enable VLAN tag Ethertype check:
                                                                 1 = Include VLAN tag Ethertype checking in the matching algorithm.
                                                                 0 = Do not include VLAN tag Ethertype checking in the matching algorithm. */
        uint64_t vlan_etype            : 16; /**< [ 15:  0](R/W) VLAN Ethertype for the matching algorithm when [VLAN_TAG_EN] is set.
                                                                 802.1Q and 802.1ad specify several Ethertypes used to identify VLAN tagged and VLAN double
                                                                 tagged packets. CGX will always match against the tag immediately following the SMAC
                                                                 address of the L2 header. */
#else /* Word 0 - Little Endian */
        uint64_t vlan_etype            : 16; /**< [ 15:  0](R/W) VLAN Ethertype for the matching algorithm when [VLAN_TAG_EN] is set.
                                                                 802.1Q and 802.1ad specify several Ethertypes used to identify VLAN tagged and VLAN double
                                                                 tagged packets. CGX will always match against the tag immediately following the SMAC
                                                                 address of the L2 header. */
        uint64_t vlan_tag_en           : 1;  /**< [ 16: 16](R/W) Enable VLAN tag Ethertype check:
                                                                 1 = Include VLAN tag Ethertype checking in the matching algorithm.
                                                                 0 = Do not include VLAN tag Ethertype checking in the matching algorithm. */
        uint64_t vlan_id               : 12; /**< [ 28: 17](R/W) VLAN ID used for the matching algorithm when [VLAN_EN] is set. */
        uint64_t vlan_en               : 1;  /**< [ 29: 29](R/W) Enable VLAN ID check:
                                                                 1 = Include VLAN ID checking in the matching algorithm.
                                                                 0 = Do not include VLAN ID checking in the matching algorithm. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_rx_steering_vetypex_s cn; */
} bdk_cgxx_cmr_rx_steering_vetypex_t;

static inline uint64_t BDK_CGXX_CMR_RX_STEERING_VETYPEX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_RX_STEERING_VETYPEX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=7)))
        return 0x87e0e8000400ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x7);
    __bdk_csr_fatal("CGXX_CMR_RX_STEERING_VETYPEX", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_CMR_RX_STEERING_VETYPEX(a,b) bdk_cgxx_cmr_rx_steering_vetypex_t
#define bustype_BDK_CGXX_CMR_RX_STEERING_VETYPEX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_RX_STEERING_VETYPEX(a,b) "CGXX_CMR_RX_STEERING_VETYPEX"
#define device_bar_BDK_CGXX_CMR_RX_STEERING_VETYPEX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_RX_STEERING_VETYPEX(a,b) (a)
#define arguments_BDK_CGXX_CMR_RX_STEERING_VETYPEX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_cmr_tx_lmacs
 *
 * CGX CMR Transmit Logical MACs Registers
 * This register sets the number of LMACs allowed on the TX interface. The value is important for
 * defining the partitioning of the transmit FIFO.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_cmr_tx_lmacs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t lmacs                 : 3;  /**< [  2:  0](R/W) Number of LMACS: Specifies the number of LMACs that can be enabled.
                                                                 This determines the logical TX buffer size per LMAC and the maximum
                                                                 LMAC ID that can be used:

                                                                 0x0 = Reserved.
                                                                 0x1 = 48 KB per LMAC, maximum LMAC ID is 0.
                                                                 0x2 = 24 KB per LMAC, maximum LMAC ID is 1.
                                                                 0x3 = 12 KB per LMAC, maximum LMAC ID is 2.
                                                                 0x4 = 12 KB per LMAC, maximum LMAC ID is 3.
                                                                 0x5-0x7 = Reserved.

                                                                 The maximum LMAC ID is determined by the smaller of CGX()_CMR_RX_LMACS[LMACS]
                                                                 and CGX()_CMR_TX_LMACS[LMACS]. The two fields should be set to the same value for
                                                                 normal operation.' */
#else /* Word 0 - Little Endian */
        uint64_t lmacs                 : 3;  /**< [  2:  0](R/W) Number of LMACS: Specifies the number of LMACs that can be enabled.
                                                                 This determines the logical TX buffer size per LMAC and the maximum
                                                                 LMAC ID that can be used:

                                                                 0x0 = Reserved.
                                                                 0x1 = 48 KB per LMAC, maximum LMAC ID is 0.
                                                                 0x2 = 24 KB per LMAC, maximum LMAC ID is 1.
                                                                 0x3 = 12 KB per LMAC, maximum LMAC ID is 2.
                                                                 0x4 = 12 KB per LMAC, maximum LMAC ID is 3.
                                                                 0x5-0x7 = Reserved.

                                                                 The maximum LMAC ID is determined by the smaller of CGX()_CMR_RX_LMACS[LMACS]
                                                                 and CGX()_CMR_TX_LMACS[LMACS]. The two fields should be set to the same value for
                                                                 normal operation.' */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_cmr_tx_lmacs_s cn; */
} bdk_cgxx_cmr_tx_lmacs_t;

static inline uint64_t BDK_CGXX_CMR_TX_LMACS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CMR_TX_LMACS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8001000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CMR_TX_LMACS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CMR_TX_LMACS(a) bdk_cgxx_cmr_tx_lmacs_t
#define bustype_BDK_CGXX_CMR_TX_LMACS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CMR_TX_LMACS(a) "CGXX_CMR_TX_LMACS"
#define device_bar_BDK_CGXX_CMR_TX_LMACS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CMR_TX_LMACS(a) (a)
#define arguments_BDK_CGXX_CMR_TX_LMACS(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_const
 *
 * CGX CONST Registers
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_const_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t lmacs                 : 8;  /**< [ 31: 24](RO) Number of LMACs. */
        uint64_t tx_fifosz             : 24; /**< [ 23:  0](RO) Number of bytes of transmit buffering in entire CGX. This buffering may be split
                                                                 between LMACs; see CGX()_CMR_TX_LMACS[LMACS]. */
#else /* Word 0 - Little Endian */
        uint64_t tx_fifosz             : 24; /**< [ 23:  0](RO) Number of bytes of transmit buffering in entire CGX. This buffering may be split
                                                                 between LMACs; see CGX()_CMR_TX_LMACS[LMACS]. */
        uint64_t lmacs                 : 8;  /**< [ 31: 24](RO) Number of LMACs. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_const_s cn; */
} bdk_cgxx_const_t;

static inline uint64_t BDK_CGXX_CONST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CONST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8040000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CONST", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CONST(a) bdk_cgxx_const_t
#define bustype_BDK_CGXX_CONST(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CONST(a) "CGXX_CONST"
#define device_bar_BDK_CGXX_CONST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CONST(a) (a)
#define arguments_BDK_CGXX_CONST(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_const1
 *
 * CGX CONST1 Registers
 * This register contains constants for software discovery.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_const1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t res_types             : 24; /**< [ 31:  8](RO) Reserved for more LMAC TYPES. */
        uint64_t types                 : 8;  /**< [  7:  0](RO) LMAC types supported. Each bit if set corresponds to that value of CGX_LMAC_TYPES_E being
                                                                 supported.
                                                                 E.g. TYPES<0> if set indicates CGX_LMAC_TYPES_E::SGMII is supported. */
#else /* Word 0 - Little Endian */
        uint64_t types                 : 8;  /**< [  7:  0](RO) LMAC types supported. Each bit if set corresponds to that value of CGX_LMAC_TYPES_E being
                                                                 supported.
                                                                 E.g. TYPES<0> if set indicates CGX_LMAC_TYPES_E::SGMII is supported. */
        uint64_t res_types             : 24; /**< [ 31:  8](RO) Reserved for more LMAC TYPES. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_const1_s cn; */
} bdk_cgxx_const1_t;

static inline uint64_t BDK_CGXX_CONST1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_CONST1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8040008ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_CONST1", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_CONST1(a) bdk_cgxx_const1_t
#define bustype_BDK_CGXX_CONST1(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_CONST1(a) "CGXX_CONST1"
#define device_bar_BDK_CGXX_CONST1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_CONST1(a) (a)
#define arguments_BDK_CGXX_CONST1(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi#_led_extension
 *
 * CGX GMP_GMI LED Extension Time Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmix_led_extension_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t extension             : 8;  /**< [  7:  0](R/W) Extension number of cycles for activity LED illumination. The same register is
                                                                 used for both RX and TX.

                                                                 * For RX, LED is on for the data transfer length through minimum IFG +
                                                                   [EXTENSION] number of coprocessor-clock cycles.

                                                                 * For TX, LED on for data transfers through transtion to IDLE + [EXTENSION]
                                                                   number of coprocessor-clock cycles.

                                                                 * The LED will also stay on for special half-dupe states involving collision
                                                                 resolution. */
#else /* Word 0 - Little Endian */
        uint64_t extension             : 8;  /**< [  7:  0](R/W) Extension number of cycles for activity LED illumination. The same register is
                                                                 used for both RX and TX.

                                                                 * For RX, LED is on for the data transfer length through minimum IFG +
                                                                   [EXTENSION] number of coprocessor-clock cycles.

                                                                 * For TX, LED on for data transfers through transtion to IDLE + [EXTENSION]
                                                                   number of coprocessor-clock cycles.

                                                                 * The LED will also stay on for special half-dupe states involving collision
                                                                 resolution. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmix_led_extension_s cn; */
} bdk_cgxx_gmp_gmix_led_extension_t;

static inline uint64_t BDK_CGXX_GMP_GMIX_LED_EXTENSION(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMIX_LED_EXTENSION(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038180ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMIX_LED_EXTENSION", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMIX_LED_EXTENSION(a,b) bdk_cgxx_gmp_gmix_led_extension_t
#define bustype_BDK_CGXX_GMP_GMIX_LED_EXTENSION(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMIX_LED_EXTENSION(a,b) "CGXX_GMP_GMIX_LED_EXTENSION"
#define device_bar_BDK_CGXX_GMP_GMIX_LED_EXTENSION(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMIX_LED_EXTENSION(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMIX_LED_EXTENSION(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi#_tx_eee
 *
 * CGX GMP GMI TX EEE Configure Registers
 * These registers control when GMP_GMI TX requests to enter or exist LPI. Those registers take
 * effect only
 * when EEE is supported and enabled for a given LMAC.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmix_tx_eee_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t tx_lpi                : 1;  /**< [ 60: 60](RO) GMP_GMI TX is in LPI state. */
        uint64_t idle_cnt              : 28; /**< [ 59: 32](RO) The current IDLE counter value is only valid when [AUTO_LPI] is set. The counter will be
                                                                 increased during
                                                                 IDLE state while 128 bits have been transimitted. The counter will be saturated at
                                                                 [IDLE_THRESH]. */
        uint64_t auto_lpi              : 1;  /**< [ 31: 31](R/W) GMP_GMI TX will send LPI requests to SPU when the bit is set and IDLE counter reaches
                                                                 [IDLE_THRESH].
                                                                 While in LPI state, GMP_GMI TX will switch to send IDLE once TX has packets (including
                                                                 flow
                                                                 control
                                                                 packets) to send or [WAKEUP] is set by S/W. */
        uint64_t wakeup                : 1;  /**< [ 30: 30](R/W/H) [WAKEUP] is valid only when [AUTO_LPI] is set and only writeable by S/W when TX is in LPI
                                                                 state. While GMP_GMI TX
                                                                 is in LPI state, S/W can use this bit to switch SMU TX from sending LPI to sending IDLE to
                                                                 SPU. [WAKEUP] will
                                                                 be automatically cleared by H/W when the switching is initiated by H/W. */
        uint64_t force_lpi             : 1;  /**< [ 29: 29](R/W) [FORCE_LPI] is only valid when [AUTO_LPI] is cleared. GMP_GMI TX will send LPI requests to
                                                                 SPU immediately after the current packet is transmitted when the bit is set. While in LPI
                                                                 mode,
                                                                 GMP_GMI  TX will switch to send IDLE once the bit is cleared. */
        uint64_t reserved_28           : 1;
        uint64_t idle_thresh           : 28; /**< [ 27:  0](R/W) IDLE Threshold. [IDLE_THRESH] is only used when [AUTO_LPI] is set. GMP_GMI TX will send
                                                                 LPI
                                                                 requests to SPU when
                                                                 the idle counter reaches this thredhold. The unit of value is a 128-bit word (or a SPU
                                                                 heart beat). Note that
                                                                 active flow control of a enabled LMAC will keep the corresponding LMAC NOT idle. */
#else /* Word 0 - Little Endian */
        uint64_t idle_thresh           : 28; /**< [ 27:  0](R/W) IDLE Threshold. [IDLE_THRESH] is only used when [AUTO_LPI] is set. GMP_GMI TX will send
                                                                 LPI
                                                                 requests to SPU when
                                                                 the idle counter reaches this thredhold. The unit of value is a 128-bit word (or a SPU
                                                                 heart beat). Note that
                                                                 active flow control of a enabled LMAC will keep the corresponding LMAC NOT idle. */
        uint64_t reserved_28           : 1;
        uint64_t force_lpi             : 1;  /**< [ 29: 29](R/W) [FORCE_LPI] is only valid when [AUTO_LPI] is cleared. GMP_GMI TX will send LPI requests to
                                                                 SPU immediately after the current packet is transmitted when the bit is set. While in LPI
                                                                 mode,
                                                                 GMP_GMI  TX will switch to send IDLE once the bit is cleared. */
        uint64_t wakeup                : 1;  /**< [ 30: 30](R/W/H) [WAKEUP] is valid only when [AUTO_LPI] is set and only writeable by S/W when TX is in LPI
                                                                 state. While GMP_GMI TX
                                                                 is in LPI state, S/W can use this bit to switch SMU TX from sending LPI to sending IDLE to
                                                                 SPU. [WAKEUP] will
                                                                 be automatically cleared by H/W when the switching is initiated by H/W. */
        uint64_t auto_lpi              : 1;  /**< [ 31: 31](R/W) GMP_GMI TX will send LPI requests to SPU when the bit is set and IDLE counter reaches
                                                                 [IDLE_THRESH].
                                                                 While in LPI state, GMP_GMI TX will switch to send IDLE once TX has packets (including
                                                                 flow
                                                                 control
                                                                 packets) to send or [WAKEUP] is set by S/W. */
        uint64_t idle_cnt              : 28; /**< [ 59: 32](RO) The current IDLE counter value is only valid when [AUTO_LPI] is set. The counter will be
                                                                 increased during
                                                                 IDLE state while 128 bits have been transimitted. The counter will be saturated at
                                                                 [IDLE_THRESH]. */
        uint64_t tx_lpi                : 1;  /**< [ 60: 60](RO) GMP_GMI TX is in LPI state. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmix_tx_eee_s cn; */
} bdk_cgxx_gmp_gmix_tx_eee_t;

static inline uint64_t BDK_CGXX_GMP_GMIX_TX_EEE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMIX_TX_EEE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038800ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMIX_TX_EEE", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMIX_TX_EEE(a,b) bdk_cgxx_gmp_gmix_tx_eee_t
#define bustype_BDK_CGXX_GMP_GMIX_TX_EEE(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMIX_TX_EEE(a,b) "CGXX_GMP_GMIX_TX_EEE"
#define device_bar_BDK_CGXX_GMP_GMIX_TX_EEE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMIX_TX_EEE(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMIX_TX_EEE(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_prt#_cfg
 *
 * CGX GMP GMI LMAC Configuration Registers
 * This register controls the configuration of the LMAC.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_prtx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t tx_idle               : 1;  /**< [ 13: 13](RO/H) TX machine is idle. */
        uint64_t rx_idle               : 1;  /**< [ 12: 12](RO/H) RX machine is idle. */
        uint64_t reserved_9_11         : 3;
        uint64_t speed_msb             : 1;  /**< [  8:  8](R/W) Link speed MSB (SGMII/QSGMII/1000Base-X only). See [SPEED]. */
        uint64_t reserved_4_7          : 4;
        uint64_t slottime              : 1;  /**< [  3:  3](R/W) Slot time for half-duplex operation
                                                                 (SGMII/QSGMII/1000Base-X only):
                                                                 0 = 512 bit times (10/100 Mb/s operation).
                                                                 1 = 4096 bit times (1000 Mb/s operation). */
        uint64_t duplex                : 1;  /**< [  2:  2](R/W) Duplex mode
                                                                 (SGMII/QSGMII/1000Base-X only):
                                                                 0 = half-duplex (collisions/extensions/bursts):
                                                                 1 = full-duplex. */
        uint64_t speed                 : 1;  /**< [  1:  1](R/W) Link Speed LSB (SGMII/QSGMII/1000Base-X only):
                                                                 _ [SPEED_MSB,SPEED] = 0x0: 100 Mb/s operation.
                                                                 _ [SPEED_MSB,SPEED] = 0x1: 1000 Mb/s operation.
                                                                 _ [SPEED_MSB,SPEED] = 0x2: 10 Mb/s operation.
                                                                 _ [SPEED_MSB,SPEED] = 0x3: Reserved. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t speed                 : 1;  /**< [  1:  1](R/W) Link Speed LSB (SGMII/QSGMII/1000Base-X only):
                                                                 _ [SPEED_MSB,SPEED] = 0x0: 100 Mb/s operation.
                                                                 _ [SPEED_MSB,SPEED] = 0x1: 1000 Mb/s operation.
                                                                 _ [SPEED_MSB,SPEED] = 0x2: 10 Mb/s operation.
                                                                 _ [SPEED_MSB,SPEED] = 0x3: Reserved. */
        uint64_t duplex                : 1;  /**< [  2:  2](R/W) Duplex mode
                                                                 (SGMII/QSGMII/1000Base-X only):
                                                                 0 = half-duplex (collisions/extensions/bursts):
                                                                 1 = full-duplex. */
        uint64_t slottime              : 1;  /**< [  3:  3](R/W) Slot time for half-duplex operation
                                                                 (SGMII/QSGMII/1000Base-X only):
                                                                 0 = 512 bit times (10/100 Mb/s operation).
                                                                 1 = 4096 bit times (1000 Mb/s operation). */
        uint64_t reserved_4_7          : 4;
        uint64_t speed_msb             : 1;  /**< [  8:  8](R/W) Link speed MSB (SGMII/QSGMII/1000Base-X only). See [SPEED]. */
        uint64_t reserved_9_11         : 3;
        uint64_t rx_idle               : 1;  /**< [ 12: 12](RO/H) RX machine is idle. */
        uint64_t tx_idle               : 1;  /**< [ 13: 13](RO/H) TX machine is idle. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_prtx_cfg_s cn; */
} bdk_cgxx_gmp_gmi_prtx_cfg_t;

static inline uint64_t BDK_CGXX_GMP_GMI_PRTX_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_PRTX_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038020ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_PRTX_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_PRTX_CFG(a,b) bdk_cgxx_gmp_gmi_prtx_cfg_t
#define bustype_BDK_CGXX_GMP_GMI_PRTX_CFG(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_PRTX_CFG(a,b) "CGXX_GMP_GMI_PRTX_CFG"
#define device_bar_BDK_CGXX_GMP_GMI_PRTX_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_PRTX_CFG(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_PRTX_CFG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_decision
 *
 * CGX GMP Packet-Decision Registers
 * This register specifies the byte count used to determine when to accept or to filter a packet.
 * As each byte in a packet is received by GMI, the L2 byte count is compared against
 * [CNT]. In normal operation, the L2 header begins after the
 * PREAMBLE + SFD (CGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] = 1) and any optional UDD skip
 * data (CGX()_GMP_GMI_RX()_UDD_SKP[LEN]).
 *
 * Internal:
 * Notes:
 * As each byte in a packet is received by GMI, the L2 byte count is compared
 * against the [CNT].  The L2 byte count is the number of bytes
 * from the beginning of the L2 header (DMAC).  In normal operation, the L2
 * header begins after the PREAMBLE+SFD (CGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK]=1) and any
 * optional UDD skip data (CGX()_GMP_GMI_RX()_UDD_SKP[LEN]).
 * When CGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] is clear, PREAMBLE+SFD are prepended to the
 * packet and would require UDD skip length to account for them.
 *
 * Full Duplex:
 * _   L2 Size <  [CNT] - Accept packet. No filtering is applied.
 * _   L2 Size >= [CNT] - Apply filter. Accept packet based on PAUSE packet filter.
 *
 * Half Duplex:
 * _   L2 Size <  [CNT] - Drop packet. Packet is unconditionally dropped.
 * _   L2 Size >= [CNT] - Accept packet.
 *
 * where L2_size = MAX(0, total_packet_size - CGX()_GMP_GMI_RX()_UDD_SKP[LEN] -
 *                        ((CGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK]==1)*8))
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_decision_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t cnt                   : 5;  /**< [  4:  0](R/W) The byte count used to decide when to accept or filter a packet. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 5;  /**< [  4:  0](R/W) The byte count used to decide when to accept or filter a packet. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_decision_s cn; */
} bdk_cgxx_gmp_gmi_rxx_decision_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_DECISION(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_DECISION(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038040ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_DECISION", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_DECISION(a,b) bdk_cgxx_gmp_gmi_rxx_decision_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_DECISION(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_DECISION(a,b) "CGXX_GMP_GMI_RXX_DECISION"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_DECISION(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_DECISION(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_DECISION(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_frm_chk
 *
 * CGX GMP Frame Check Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_frm_chk_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t skperr                : 1;  /**< [  8:  8](R/W) Skipper error. */
        uint64_t rcverr                : 1;  /**< [  7:  7](R/W) Frame was received with data-reception error. */
        uint64_t reserved_5_6          : 2;
        uint64_t fcserr                : 1;  /**< [  4:  4](R/W) Frame was received with FCS/CRC error. */
        uint64_t jabber                : 1;  /**< [  3:  3](R/W) Frame was received with length > sys_length. */
        uint64_t reserved_2            : 1;
        uint64_t carext                : 1;  /**< [  1:  1](R/W) Carrier extend error. SGMII/QSGMII/1000Base-X only. */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W) PAUSE frame was received with length < minFrameSize. */
#else /* Word 0 - Little Endian */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W) PAUSE frame was received with length < minFrameSize. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W) Carrier extend error. SGMII/QSGMII/1000Base-X only. */
        uint64_t reserved_2            : 1;
        uint64_t jabber                : 1;  /**< [  3:  3](R/W) Frame was received with length > sys_length. */
        uint64_t fcserr                : 1;  /**< [  4:  4](R/W) Frame was received with FCS/CRC error. */
        uint64_t reserved_5_6          : 2;
        uint64_t rcverr                : 1;  /**< [  7:  7](R/W) Frame was received with data-reception error. */
        uint64_t skperr                : 1;  /**< [  8:  8](R/W) Skipper error. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_frm_chk_s cn; */
} bdk_cgxx_gmp_gmi_rxx_frm_chk_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_FRM_CHK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_FRM_CHK(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038030ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_FRM_CHK", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_FRM_CHK(a,b) bdk_cgxx_gmp_gmi_rxx_frm_chk_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_FRM_CHK(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_FRM_CHK(a,b) "CGXX_GMP_GMI_RXX_FRM_CHK"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_FRM_CHK(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_FRM_CHK(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_FRM_CHK(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_frm_ctl
 *
 * CGX GMP Frame Control Registers
 * This register controls the handling of the frames.
 * The [CTL_BCK] and [CTL_DRP] bits control how the hardware handles incoming PAUSE packets. The
 * most
 * common modes of operation:
 * _ [CTL_BCK] = 1, [CTL_DRP] = 1: hardware handles everything.
 * _ [CTL_BCK] = 0, [CTL_DRP] = 0: software sees all PAUSE frames.
 * _ [CTL_BCK] = 0, [CTL_DRP] = 1: all PAUSE frames are completely ignored.
 *
 * These control bits should be set to [CTL_BCK] = 0, [CTL_DRP] = 0 in half-duplex mode. Since
 * PAUSE
 * packets only apply to full duplex operation, any PAUSE packet would constitute an exception
 * which should be handled by the processing cores. PAUSE packets should not be forwarded.
 *
 * Internal:
 * Notes:
 * [PRE_STRP]:
 * When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP]
 * determines if the PREAMBLE+SFD bytes are thrown away or sent to the Octane
 * core as part of the packet.
 * In either mode, the PREAMBLE+SFD bytes are not counted toward the packet
 * size when checking against the MIN and MAX bounds.  Furthermore, the bytes
 * are skipped when locating the start of the L2 header for DMAC and Control
 * frame recognition.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_frm_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t rx_fc_type            : 1;  /**< [ 13: 13](R/W) Receive side flow control type select.
                                                                 0 = GMI MAC receives and processes ITU G.999.1 pause frames.
                                                                 1 = GMI MAC receives and processes 802.3 pause frames. */
        uint64_t ptp_mode              : 1;  /**< [ 12: 12](R/W) Timestamp mode. When [PTP_MODE] is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the CGX()_GMP_GMI_RX()_JABBER,
                                                                 CGX()_GMP_GMI_RX()_DECISION, CGX()_GMP_GMI_RX()_UDD_SKP, and
                                                                 CGX()_CMR()_RX_STAT0..CGX()_CMR()_RX_STAT8
                                                                 do not require any adjustment as they operate on the received
                                                                 packet size. When the packet reaches NIC, its size reflects the additional bytes. */
        uint64_t reserved_11           : 1;
        uint64_t null_dis              : 1;  /**< [ 10: 10](R/W) When set, do not modify the MOD bits on NULL ticks due to partial packets. */
        uint64_t pre_align             : 1;  /**< [  9:  9](R/W) When set, PREAMBLE parser aligns the SFD byte regardless of the number of previous
                                                                 PREAMBLE nibbles. In this mode, [PRE_STRP] should be set to account for the variable
                                                                 nature of the PREAMBLE. [PRE_CHK] must be set to enable this and all PREAMBLE features.
                                                                 SGMII at 10/100Mbs only. */
        uint64_t reserved_7_8          : 2;
        uint64_t pre_free              : 1;  /**< [  6:  6](RO/H) When set, PREAMBLE checking is less strict. GMI will begin the frame at the first SFD.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features. SGMII/QSGMII/1000Base-X
                                                                 only. */
        uint64_t ctl_smac              : 1;  /**< [  5:  5](R/W) Control PAUSE frames can match station SMAC. */
        uint64_t ctl_mcst              : 1;  /**< [  4:  4](R/W) Control PAUSE frames can match globally assigned multicast address. */
        uint64_t ctl_bck               : 1;  /**< [  3:  3](R/W) Forward PAUSE information to TX block. */
        uint64_t ctl_drp               : 1;  /**< [  2:  2](R/W) Drop control-PAUSE frames. */
        uint64_t pre_strp              : 1;  /**< [  1:  1](R/W) Strip off the preamble (when present).
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If [PTP_MODE]=1 and [PRE_CHK]=1, [PRE_STRP] must be 1.

                                                                 When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP] determines
                                                                 if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
        uint64_t pre_chk               : 1;  /**< [  0:  0](R/W) Check the preamble for correctness. This port is configured to send a valid 802.3 PREAMBLE
                                                                 to begin every frame. GMI checks that a valid PREAMBLE is received (based on [PRE_FREE]).
                                                                 When a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The CGX()_GMP()_RX_INT[PCTERR] interrupt is also raised. */
#else /* Word 0 - Little Endian */
        uint64_t pre_chk               : 1;  /**< [  0:  0](R/W) Check the preamble for correctness. This port is configured to send a valid 802.3 PREAMBLE
                                                                 to begin every frame. GMI checks that a valid PREAMBLE is received (based on [PRE_FREE]).
                                                                 When a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The CGX()_GMP()_RX_INT[PCTERR] interrupt is also raised. */
        uint64_t pre_strp              : 1;  /**< [  1:  1](R/W) Strip off the preamble (when present).
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If [PTP_MODE]=1 and [PRE_CHK]=1, [PRE_STRP] must be 1.

                                                                 When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP] determines
                                                                 if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
        uint64_t ctl_drp               : 1;  /**< [  2:  2](R/W) Drop control-PAUSE frames. */
        uint64_t ctl_bck               : 1;  /**< [  3:  3](R/W) Forward PAUSE information to TX block. */
        uint64_t ctl_mcst              : 1;  /**< [  4:  4](R/W) Control PAUSE frames can match globally assigned multicast address. */
        uint64_t ctl_smac              : 1;  /**< [  5:  5](R/W) Control PAUSE frames can match station SMAC. */
        uint64_t pre_free              : 1;  /**< [  6:  6](RO/H) When set, PREAMBLE checking is less strict. GMI will begin the frame at the first SFD.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features. SGMII/QSGMII/1000Base-X
                                                                 only. */
        uint64_t reserved_7_8          : 2;
        uint64_t pre_align             : 1;  /**< [  9:  9](R/W) When set, PREAMBLE parser aligns the SFD byte regardless of the number of previous
                                                                 PREAMBLE nibbles. In this mode, [PRE_STRP] should be set to account for the variable
                                                                 nature of the PREAMBLE. [PRE_CHK] must be set to enable this and all PREAMBLE features.
                                                                 SGMII at 10/100Mbs only. */
        uint64_t null_dis              : 1;  /**< [ 10: 10](R/W) When set, do not modify the MOD bits on NULL ticks due to partial packets. */
        uint64_t reserved_11           : 1;
        uint64_t ptp_mode              : 1;  /**< [ 12: 12](R/W) Timestamp mode. When [PTP_MODE] is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the CGX()_GMP_GMI_RX()_JABBER,
                                                                 CGX()_GMP_GMI_RX()_DECISION, CGX()_GMP_GMI_RX()_UDD_SKP, and
                                                                 CGX()_CMR()_RX_STAT0..CGX()_CMR()_RX_STAT8
                                                                 do not require any adjustment as they operate on the received
                                                                 packet size. When the packet reaches NIC, its size reflects the additional bytes. */
        uint64_t rx_fc_type            : 1;  /**< [ 13: 13](R/W) Receive side flow control type select.
                                                                 0 = GMI MAC receives and processes ITU G.999.1 pause frames.
                                                                 1 = GMI MAC receives and processes 802.3 pause frames. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    struct bdk_cgxx_gmp_gmi_rxx_frm_ctl_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t rx_fc_type            : 1;  /**< [ 13: 13](R/W) Receive side flow control type select.
                                                                 0 = GMI MAC receives and processes ITU G.999.1 pause frames.
                                                                 1 = GMI MAC receives and processes 802.3 pause frames. */
        uint64_t ptp_mode              : 1;  /**< [ 12: 12](R/W) Timestamp mode. When [PTP_MODE] is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the CGX()_GMP_GMI_RX()_JABBER,
                                                                 CGX()_GMP_GMI_RX()_DECISION, CGX()_GMP_GMI_RX()_UDD_SKP, and
                                                                 CGX()_CMR()_RX_STAT0..CGX()_CMR()_RX_STAT8
                                                                 do not require any adjustment as they operate on the received
                                                                 packet size. When the packet reaches NIC, its size reflects the additional bytes. */
        uint64_t reserved_11           : 1;
        uint64_t null_dis              : 1;  /**< [ 10: 10](R/W) When set, do not modify the MOD bits on NULL ticks due to partial packets. */
        uint64_t pre_align             : 1;  /**< [  9:  9](R/W) When set, PREAMBLE parser aligns the SFD byte regardless of the number of previous
                                                                 PREAMBLE nibbles. In this mode, [PRE_STRP] should be set to account for the variable
                                                                 nature of the PREAMBLE. [PRE_CHK] must be set to enable this and all PREAMBLE features.
                                                                 SGMII at 10/100Mbs only. */
        uint64_t reserved_8            : 1;
        uint64_t reserved_7            : 1;
        uint64_t pre_free              : 1;  /**< [  6:  6](RO/H) When set, PREAMBLE checking is less strict. GMI will begin the frame at the first SFD.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features. SGMII/QSGMII/1000Base-X
                                                                 only. */
        uint64_t ctl_smac              : 1;  /**< [  5:  5](R/W) Control PAUSE frames can match station SMAC. */
        uint64_t ctl_mcst              : 1;  /**< [  4:  4](R/W) Control PAUSE frames can match globally assigned multicast address. */
        uint64_t ctl_bck               : 1;  /**< [  3:  3](R/W) Forward PAUSE information to TX block. */
        uint64_t ctl_drp               : 1;  /**< [  2:  2](R/W) Drop control-PAUSE frames. */
        uint64_t pre_strp              : 1;  /**< [  1:  1](R/W) Strip off the preamble (when present).
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If [PTP_MODE]=1 and [PRE_CHK]=1, [PRE_STRP] must be 1.

                                                                 When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP] determines
                                                                 if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
        uint64_t pre_chk               : 1;  /**< [  0:  0](R/W) Check the preamble for correctness. This port is configured to send a valid 802.3 PREAMBLE
                                                                 to begin every frame. GMI checks that a valid PREAMBLE is received (based on [PRE_FREE]).
                                                                 When a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The CGX()_GMP()_RX_INT[PCTERR] interrupt is also raised. */
#else /* Word 0 - Little Endian */
        uint64_t pre_chk               : 1;  /**< [  0:  0](R/W) Check the preamble for correctness. This port is configured to send a valid 802.3 PREAMBLE
                                                                 to begin every frame. GMI checks that a valid PREAMBLE is received (based on [PRE_FREE]).
                                                                 When a problem does occur within the PREAMBLE sequence, the frame is marked as bad and not
                                                                 sent into the core. The CGX()_GMP()_RX_INT[PCTERR] interrupt is also raised. */
        uint64_t pre_strp              : 1;  /**< [  1:  1](R/W) Strip off the preamble (when present).
                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If [PTP_MODE]=1 and [PRE_CHK]=1, [PRE_STRP] must be 1.

                                                                 When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP] determines
                                                                 if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
        uint64_t ctl_drp               : 1;  /**< [  2:  2](R/W) Drop control-PAUSE frames. */
        uint64_t ctl_bck               : 1;  /**< [  3:  3](R/W) Forward PAUSE information to TX block. */
        uint64_t ctl_mcst              : 1;  /**< [  4:  4](R/W) Control PAUSE frames can match globally assigned multicast address. */
        uint64_t ctl_smac              : 1;  /**< [  5:  5](R/W) Control PAUSE frames can match station SMAC. */
        uint64_t pre_free              : 1;  /**< [  6:  6](RO/H) When set, PREAMBLE checking is less strict. GMI will begin the frame at the first SFD.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features. SGMII/QSGMII/1000Base-X
                                                                 only. */
        uint64_t reserved_7            : 1;
        uint64_t reserved_8            : 1;
        uint64_t pre_align             : 1;  /**< [  9:  9](R/W) When set, PREAMBLE parser aligns the SFD byte regardless of the number of previous
                                                                 PREAMBLE nibbles. In this mode, [PRE_STRP] should be set to account for the variable
                                                                 nature of the PREAMBLE. [PRE_CHK] must be set to enable this and all PREAMBLE features.
                                                                 SGMII at 10/100Mbs only. */
        uint64_t null_dis              : 1;  /**< [ 10: 10](R/W) When set, do not modify the MOD bits on NULL ticks due to partial packets. */
        uint64_t reserved_11           : 1;
        uint64_t ptp_mode              : 1;  /**< [ 12: 12](R/W) Timestamp mode. When [PTP_MODE] is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the CGX()_GMP_GMI_RX()_JABBER,
                                                                 CGX()_GMP_GMI_RX()_DECISION, CGX()_GMP_GMI_RX()_UDD_SKP, and
                                                                 CGX()_CMR()_RX_STAT0..CGX()_CMR()_RX_STAT8
                                                                 do not require any adjustment as they operate on the received
                                                                 packet size. When the packet reaches NIC, its size reflects the additional bytes. */
        uint64_t rx_fc_type            : 1;  /**< [ 13: 13](R/W) Receive side flow control type select.
                                                                 0 = GMI MAC receives and processes ITU G.999.1 pause frames.
                                                                 1 = GMI MAC receives and processes 802.3 pause frames. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } cn;
} bdk_cgxx_gmp_gmi_rxx_frm_ctl_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_FRM_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_FRM_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038028ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_FRM_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_FRM_CTL(a,b) bdk_cgxx_gmp_gmi_rxx_frm_ctl_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_FRM_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_FRM_CTL(a,b) "CGXX_GMP_GMI_RXX_FRM_CTL"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_FRM_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_FRM_CTL(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_FRM_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_ifg
 *
 * CGX GMI Minimum Interframe-Gap Cycles Registers
 * This register specifies the minimum number of interframe-gap (IFG) cycles between packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_ifg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t ifg                   : 4;  /**< [  3:  0](R/W) Min IFG (in IFG * 8 bits) between packets used to determine IFGERR. Normally IFG is 96
                                                                 bits. Values 0x1 or smaller are illegal.

                                                                 Note that in some operating modes, IFG cycles can be inserted or removed in order to
                                                                 achieve clock rate adaptation. For these reasons, the default value is slightly
                                                                 conservative and does not check up to the full 96 bits of IFG.
                                                                 (SGMII/QSGMII/1000Base-X only) */
#else /* Word 0 - Little Endian */
        uint64_t ifg                   : 4;  /**< [  3:  0](R/W) Min IFG (in IFG * 8 bits) between packets used to determine IFGERR. Normally IFG is 96
                                                                 bits. Values 0x1 or smaller are illegal.

                                                                 Note that in some operating modes, IFG cycles can be inserted or removed in order to
                                                                 achieve clock rate adaptation. For these reasons, the default value is slightly
                                                                 conservative and does not check up to the full 96 bits of IFG.
                                                                 (SGMII/QSGMII/1000Base-X only) */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_ifg_s cn; */
} bdk_cgxx_gmp_gmi_rxx_ifg_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_IFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_IFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038058ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_IFG", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_IFG(a,b) bdk_cgxx_gmp_gmi_rxx_ifg_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_IFG(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_IFG(a,b) "CGXX_GMP_GMI_RXX_IFG"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_IFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_IFG(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_IFG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_int
 *
 * CGX GMP GMI RX Interrupt Registers
 * '"These registers allow interrupts to be sent to the control processor.
 * * Exception conditions <10:0> can also set the rcv/opcode in the received packet's work-queue
 * entry. CGX()_GMP_GMI_RX()_FRM_CHK provides a bit mask for configuring which conditions
 * set the error.
 * In half duplex operation, the expectation is that collisions will appear as either MINERR or
 * CAREXT errors.'
 *
 * Internal:
 * Notes:
 * (1) exception conditions 10:0 can also set the rcv/opcode in the received
 * packet's workQ entry.  The CGX()_GMP_GMI_RX()_FRM_CHK register provides a bit mask
 * for configuring which conditions set the error.
 *
 * (2) in half duplex operation, the expectation is that collisions will appear
 * as either MINERR o r CAREXT errors.
 *
 * (3) JABBER An RX jabber error indicates that a packet was received which
 * is longer than the maximum allowed packet as defined by the
 * system.  GMI will truncate the packet at the JABBER count.
 * Failure to do so could lead to system instabilty.
 *
 * (4) NIBERR This error is illegal at 1000Mbs speeds
 * (CGX()_GMP_GMI_PRT()_CFG[SPEED]==0) and will never assert.
 *
 * (5) MINERR total frame DA+SA+TL+DATA+PAD+FCS < 64
 *
 * (6) ALNERR Indicates that the packet received was not an integer number of
 * bytes.  If FCS checking is enabled, ALNERR will only assert if
 * the FCS is bad.  If FCS checking is disabled, ALNERR will
 * assert in all non-integer frame cases.
 *
 * (7) Collisions Collisions can only occur in half-duplex mode.  A collision
 * is assumed by the receiver when the slottime
 * (CGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not satisfied.  In 10/100 mode,
 * this will result in a frame < SLOTTIME.  In 1000 mode, it
 * could result either in frame < SLOTTIME or a carrier extend
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
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1C/H) Wake-on-LAN packet detected. */
        uint64_t reserved_12_15        : 4;
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1C/H) Interframe gap violation. Does not necessarily indicate a failure. SGMII/QSGMII/1000Base-X only. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1C/H) Collision detection. Collisions can only occur in half-duplex mode. A collision is assumed
                                                                 by the receiver when the slottime (CGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not
                                                                 satisfied. In 10/100 mode, this will result in a frame < SLOTTIME. In 1000 mode, it could
                                                                 result either in frame < SLOTTIME or a carrier extend error with the SLOTTIME. These
                                                                 conditions are visible by 1) transfer ended before slottime - COLDET or 2) carrier extend
                                                                 error - CAREXT. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1C/H) False-carrier error, or carrier-extend error after slottime is satisfied.
                                                                 SGMII/QSGMII/1000Base-X only. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1C/H) Reserved opcode. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1C/H) Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence.
                                                                 Does not check the number of PREAMBLE cycles. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1C/H) Internal data aggregation overflow. This interrupt should never assert.
                                                                 SGMII/QSGMII/1000Base-X only. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1C/H) Skipper error. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1C/H) Data-reception error. Frame was received with data-reception error. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1C/H) FCS/CRC error. Frame was received with FCS/CRC error. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1C/H) System-length error: frame was received with length > sys_length.
                                                                 An RX Jabber error indicates that a packet was received which is longer than the maximum
                                                                 allowed packet as defined by the system. GMI truncates the packet at the JABBER count.
                                                                 Failure to do so could lead to system instability. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1C/H) Carrier-extend error. (SGMII/QSGMII/1000Base-X only) */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1C/H) PAUSE frame was received with length < minFrameSize. Frame length checks are typically
                                                                 handled in NIC, but PAUSE frames are normally discarded before being inspected by NIC.
                                                                 Total frame DA+SA+TL+DATA+PAD+FCS < 64. */
#else /* Word 0 - Little Endian */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1C/H) PAUSE frame was received with length < minFrameSize. Frame length checks are typically
                                                                 handled in NIC, but PAUSE frames are normally discarded before being inspected by NIC.
                                                                 Total frame DA+SA+TL+DATA+PAD+FCS < 64. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1C/H) Carrier-extend error. (SGMII/QSGMII/1000Base-X only) */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1C/H) System-length error: frame was received with length > sys_length.
                                                                 An RX Jabber error indicates that a packet was received which is longer than the maximum
                                                                 allowed packet as defined by the system. GMI truncates the packet at the JABBER count.
                                                                 Failure to do so could lead to system instability. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1C/H) FCS/CRC error. Frame was received with FCS/CRC error. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1C/H) Data-reception error. Frame was received with data-reception error. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1C/H) Skipper error. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1C/H) Internal data aggregation overflow. This interrupt should never assert.
                                                                 SGMII/QSGMII/1000Base-X only. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1C/H) Bad preamble/protocol error. Checks that the frame begins with a valid PREAMBLE sequence.
                                                                 Does not check the number of PREAMBLE cycles. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1C/H) Reserved opcode. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1C/H) False-carrier error, or carrier-extend error after slottime is satisfied.
                                                                 SGMII/QSGMII/1000Base-X only. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1C/H) Collision detection. Collisions can only occur in half-duplex mode. A collision is assumed
                                                                 by the receiver when the slottime (CGX()_GMP_GMI_PRT()_CFG[SLOTTIME]) is not
                                                                 satisfied. In 10/100 mode, this will result in a frame < SLOTTIME. In 1000 mode, it could
                                                                 result either in frame < SLOTTIME or a carrier extend error with the SLOTTIME. These
                                                                 conditions are visible by 1) transfer ended before slottime - COLDET or 2) carrier extend
                                                                 error - CAREXT. */
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1C/H) Interframe gap violation. Does not necessarily indicate a failure. SGMII/QSGMII/1000Base-X only. */
        uint64_t reserved_12_15        : 4;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1C/H) Wake-on-LAN packet detected. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_int_s cn; */
} bdk_cgxx_gmp_gmi_rxx_int_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038000ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_INT(a,b) bdk_cgxx_gmp_gmi_rxx_int_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_INT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_INT(a,b) "CGXX_GMP_GMI_RXX_INT"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_INT(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_int_ena_w1c
 *
 * CGX GMP GMI RX Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[WOL_RCVD]. */
        uint64_t reserved_12_15        : 4;
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[IFGERR]. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[COLDET]. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FALERR]. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RSVERR]. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[PCTERR]. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[OVRERR]. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[SKPERR]. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RCVERR]. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FCSERR]. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[JABBER]. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[CAREXT]. */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[MINERR]. */
#else /* Word 0 - Little Endian */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[MINERR]. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[CAREXT]. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[JABBER]. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FCSERR]. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RCVERR]. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[SKPERR]. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[OVRERR]. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[PCTERR]. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RSVERR]. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FALERR]. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[COLDET]. */
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[IFGERR]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[WOL_RCVD]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_int_ena_w1c_s cn; */
} bdk_cgxx_gmp_gmi_rxx_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038010ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(a,b) bdk_cgxx_gmp_gmi_rxx_int_ena_w1c_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(a,b) "CGXX_GMP_GMI_RXX_INT_ENA_W1C"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_int_ena_w1s
 *
 * CGX GMP GMI RX Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[WOL_RCVD]. */
        uint64_t reserved_12_15        : 4;
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[IFGERR]. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[COLDET]. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FALERR]. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RSVERR]. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[PCTERR]. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[OVRERR]. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[SKPERR]. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RCVERR]. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FCSERR]. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[JABBER]. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[CAREXT]. */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[MINERR]. */
#else /* Word 0 - Little Endian */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[MINERR]. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[CAREXT]. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[JABBER]. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FCSERR]. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RCVERR]. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[SKPERR]. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[OVRERR]. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[PCTERR]. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[RSVERR]. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[FALERR]. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[COLDET]. */
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[IFGERR]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_RX(0..3)_INT[WOL_RCVD]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_int_ena_w1s_s cn; */
} bdk_cgxx_gmp_gmi_rxx_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038018ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(a,b) bdk_cgxx_gmp_gmi_rxx_int_ena_w1s_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(a,b) "CGXX_GMP_GMI_RXX_INT_ENA_W1S"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_int_w1s
 *
 * CGX GMP GMI RX Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[WOL_RCVD]. */
        uint64_t reserved_12_15        : 4;
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[IFGERR]. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[COLDET]. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[FALERR]. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[RSVERR]. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[PCTERR]. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[OVRERR]. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[SKPERR]. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[RCVERR]. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[FCSERR]. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[JABBER]. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[CAREXT]. */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[MINERR]. */
#else /* Word 0 - Little Endian */
        uint64_t minerr                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[MINERR]. */
        uint64_t carext                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[CAREXT]. */
        uint64_t jabber                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[JABBER]. */
        uint64_t fcserr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[FCSERR]. */
        uint64_t rcverr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[RCVERR]. */
        uint64_t skperr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[SKPERR]. */
        uint64_t ovrerr                : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[OVRERR]. */
        uint64_t pcterr                : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[PCTERR]. */
        uint64_t rsverr                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[RSVERR]. */
        uint64_t falerr                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[FALERR]. */
        uint64_t coldet                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[COLDET]. */
        uint64_t ifgerr                : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[IFGERR]. */
        uint64_t reserved_12_15        : 4;
        uint64_t wol_rcvd              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_RX(0..3)_INT[WOL_RCVD]. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_int_w1s_s cn; */
} bdk_cgxx_gmp_gmi_rxx_int_w1s_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038008ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_INT_W1S(a,b) bdk_cgxx_gmp_gmi_rxx_int_w1s_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_INT_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_INT_W1S(a,b) "CGXX_GMP_GMI_RXX_INT_W1S"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_INT_W1S(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_jabber
 *
 * CGX GMP Maximum Packet-Size Registers
 * This register specifies the maximum size for packets, beyond which the GMI truncates.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_jabber_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W) Byte count for jabber check. Failing packets set the JABBER interrupt and are optionally
                                                                 sent with opcode = JABBER. GMI truncates the packet to [CNT] bytes.
                                                                 [CNT] must be 8-byte aligned such that CNT<2:0> = 000. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W) Byte count for jabber check. Failing packets set the JABBER interrupt and are optionally
                                                                 sent with opcode = JABBER. GMI truncates the packet to [CNT] bytes.
                                                                 [CNT] must be 8-byte aligned such that CNT<2:0> = 000. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_jabber_s cn; */
} bdk_cgxx_gmp_gmi_rxx_jabber_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_JABBER(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_JABBER(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038038ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_JABBER", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_JABBER(a,b) bdk_cgxx_gmp_gmi_rxx_jabber_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_JABBER(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_JABBER(a,b) "CGXX_GMP_GMI_RXX_JABBER"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_JABBER(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_JABBER(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_JABBER(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_udd_skp
 *
 * CGX GMP GMI User-Defined Data Skip Registers
 * This register specifies the amount of user-defined data (UDD) added before the start of the
 * L2C data.
 *
 * Internal:
 * Notes:
 * (1) The skip bytes are part of the packet and will be handled by NIC.
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
 * (5) CGX()_GMP_GMI_RX()_UDD_SKP[LEN] must be 0 in half-duplex operation unless
 * CGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] is clear.  If CGX()_GMP_GMI_RX()_FRM_CTL[PRE_CHK] is
 * clear,
 * then CGX()_GMP_GMI_RX()_UDD_SKP[LEN] will normally be 8.
 *
 * (6) In all cases, the UDD bytes will be sent down the packet interface as
 * part of the packet.  The UDD bytes are never stripped from the actual
 * packet.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_udd_skp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t fcssel                : 1;  /**< [  8:  8](R/W) Include the skip bytes in the FCS calculation.
                                                                 0 = All skip bytes are included in FCS.
                                                                 1 = The skip bytes are not included in FCS.

                                                                 The skip bytes are part of the packet and are
                                                                 handled by NIC. The system can determine if the UDD bytes are included in the FCS check by
                                                                 using [FCSSEL], if the FCS check is enabled. */
        uint64_t reserved_7            : 1;
        uint64_t len                   : 7;  /**< [  6:  0](R/W) Amount of user-defined data before the start of the L2C data, in bytes.
                                                                 Setting to 0 means L2C comes first; maximum value is 64.
                                                                 LEN must be 0x0 in half-duplex operation.

                                                                 If LEN != 0, then CGX()_GMP_GMI_RX()_FRM_CHK[MINERR] will be disabled and
                                                                 CGX()_GMP_GMI_RX()_INT[MINERR] will be zero. */
#else /* Word 0 - Little Endian */
        uint64_t len                   : 7;  /**< [  6:  0](R/W) Amount of user-defined data before the start of the L2C data, in bytes.
                                                                 Setting to 0 means L2C comes first; maximum value is 64.
                                                                 LEN must be 0x0 in half-duplex operation.

                                                                 If LEN != 0, then CGX()_GMP_GMI_RX()_FRM_CHK[MINERR] will be disabled and
                                                                 CGX()_GMP_GMI_RX()_INT[MINERR] will be zero. */
        uint64_t reserved_7            : 1;
        uint64_t fcssel                : 1;  /**< [  8:  8](R/W) Include the skip bytes in the FCS calculation.
                                                                 0 = All skip bytes are included in FCS.
                                                                 1 = The skip bytes are not included in FCS.

                                                                 The skip bytes are part of the packet and are
                                                                 handled by NIC. The system can determine if the UDD bytes are included in the FCS check by
                                                                 using [FCSSEL], if the FCS check is enabled. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_udd_skp_s cn; */
} bdk_cgxx_gmp_gmi_rxx_udd_skp_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_UDD_SKP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_UDD_SKP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038048ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_UDD_SKP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_UDD_SKP(a,b) bdk_cgxx_gmp_gmi_rxx_udd_skp_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_UDD_SKP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_UDD_SKP(a,b) "CGXX_GMP_GMI_RXX_UDD_SKP"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_UDD_SKP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_UDD_SKP(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_UDD_SKP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_wol_ctrl0
 *
 * CGX GMP_GMI RX Wake-on-LAN Control 0 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_wol_ctrl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t pswd_len              : 4;  /**< [ 51: 48](R/W) The byte length of the optional Wake-on-LAN password. A value of 0 indicates a password
                                                                 is not supported. When non-zero, the least significant bytes of
                                                                 CGX()_GMP_GMI_RX()_WOL_CTRL1
                                                                 are used for the password match. Values 0x9 to 0xF are reserved. */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The MAC address to compare against received Wake-on-LAN packets. */
#else /* Word 0 - Little Endian */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The MAC address to compare against received Wake-on-LAN packets. */
        uint64_t pswd_len              : 4;  /**< [ 51: 48](R/W) The byte length of the optional Wake-on-LAN password. A value of 0 indicates a password
                                                                 is not supported. When non-zero, the least significant bytes of
                                                                 CGX()_GMP_GMI_RX()_WOL_CTRL1
                                                                 are used for the password match. Values 0x9 to 0xF are reserved. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_wol_ctrl0_s cn; */
} bdk_cgxx_gmp_gmi_rxx_wol_ctrl0_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038808ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_WOL_CTRL0", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(a,b) bdk_cgxx_gmp_gmi_rxx_wol_ctrl0_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(a,b) "CGXX_GMP_GMI_RXX_WOL_CTRL0"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_rx#_wol_ctrl1
 *
 * CGX GMP_GMI RX Wake-on-LAN Control 1 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_rxx_wol_ctrl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pswd                  : 64; /**< [ 63:  0](R/W) The optional password to compare against received Wake-on-LAN packets. The length of the
                                                                 valid password is indicated by CGX()_GMP_GMI_RX()_WOL_CTRL0[PSWD_LEN]. */
#else /* Word 0 - Little Endian */
        uint64_t pswd                  : 64; /**< [ 63:  0](R/W) The optional password to compare against received Wake-on-LAN packets. The length of the
                                                                 valid password is indicated by CGX()_GMP_GMI_RX()_WOL_CTRL0[PSWD_LEN]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_rxx_wol_ctrl1_s cn; */
} bdk_cgxx_gmp_gmi_rxx_wol_ctrl1_t;

static inline uint64_t BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038810ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_RXX_WOL_CTRL1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(a,b) bdk_cgxx_gmp_gmi_rxx_wol_ctrl1_t
#define bustype_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(a,b) "CGXX_GMP_GMI_RXX_WOL_CTRL1"
#define device_bar_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_RXX_WOL_CTRL1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_smac#
 *
 * CGX GMI SMAC Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_smacx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t smac                  : 48; /**< [ 47:  0](R/W) The SMAC field is used for generating and accepting control PAUSE packets. */
#else /* Word 0 - Little Endian */
        uint64_t smac                  : 48; /**< [ 47:  0](R/W) The SMAC field is used for generating and accepting control PAUSE packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_smacx_s cn; */
} bdk_cgxx_gmp_gmi_smacx_t;

static inline uint64_t BDK_CGXX_GMP_GMI_SMACX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_SMACX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038230ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_SMACX", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_SMACX(a,b) bdk_cgxx_gmp_gmi_smacx_t
#define bustype_BDK_CGXX_GMP_GMI_SMACX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_SMACX(a,b) "CGXX_GMP_GMI_SMACX"
#define device_bar_BDK_CGXX_GMP_GMI_SMACX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_SMACX(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_SMACX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_append
 *
 * CGX GMI TX Append Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_append_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t force_fcs             : 1;  /**< [  3:  3](R/W) Append the Ethernet FCS on each PAUSE packet. */
        uint64_t fcs                   : 1;  /**< [  2:  2](R/W) Append the Ethernet FCS on each packet. */
        uint64_t pad                   : 1;  /**< [  1:  1](R/W) Append PAD bytes such that minimum-sized packet is transmitted. */
        uint64_t preamble              : 1;  /**< [  0:  0](R/W) Prepend the Ethernet preamble on each transfer. */
#else /* Word 0 - Little Endian */
        uint64_t preamble              : 1;  /**< [  0:  0](R/W) Prepend the Ethernet preamble on each transfer. */
        uint64_t pad                   : 1;  /**< [  1:  1](R/W) Append PAD bytes such that minimum-sized packet is transmitted. */
        uint64_t fcs                   : 1;  /**< [  2:  2](R/W) Append the Ethernet FCS on each packet. */
        uint64_t force_fcs             : 1;  /**< [  3:  3](R/W) Append the Ethernet FCS on each PAUSE packet. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_append_s cn; */
} bdk_cgxx_gmp_gmi_txx_append_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_APPEND(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_APPEND(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038218ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_APPEND", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_APPEND(a,b) bdk_cgxx_gmp_gmi_txx_append_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_APPEND(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_APPEND(a,b) "CGXX_GMP_GMI_TXX_APPEND"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_APPEND(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_APPEND(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_APPEND(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_burst
 *
 * CGX GMI TX Burst-Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_burst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t burst                 : 16; /**< [ 15:  0](R/W) Burst (refer to 802.3 to set correctly). Only valid for 1000Mb/s half-duplex operation as
                                                                 follows:
                                                                 half duplex/1000Mb/s: 0x2000
                                                                 all other modes: 0x0
                                                                 SGMII/QSGMII/1000Base-X only. */
#else /* Word 0 - Little Endian */
        uint64_t burst                 : 16; /**< [ 15:  0](R/W) Burst (refer to 802.3 to set correctly). Only valid for 1000Mb/s half-duplex operation as
                                                                 follows:
                                                                 half duplex/1000Mb/s: 0x2000
                                                                 all other modes: 0x0
                                                                 SGMII/QSGMII/1000Base-X only. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_burst_s cn; */
} bdk_cgxx_gmp_gmi_txx_burst_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_BURST(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_BURST(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038228ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_BURST", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_BURST(a,b) bdk_cgxx_gmp_gmi_txx_burst_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_BURST(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_BURST(a,b) "CGXX_GMP_GMI_TXX_BURST"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_BURST(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_BURST(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_BURST(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_ctl
 *
 * CGX GMI Transmit Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t link_drain            : 1;  /**< [  3:  3](R/W) Enable dropping of full packets to allow CGX and NIC to drain their FIFOs. */
        uint64_t tx_fc_type            : 1;  /**< [  2:  2](R/W) Transmit side flow control type select.
                                                                 0 = GMI MAC transmits ITU G.999.1 pause frames.
                                                                 1 = GMI MAC transmits 802.3 pause frames. */
        uint64_t xsdef_en              : 1;  /**< [  1:  1](R/W) Enables the excessive-deferral check for statistics and interrupts. SGMII/1000Base-X half-
                                                                 duplex only. */
        uint64_t xscol_en              : 1;  /**< [  0:  0](R/W) Enables the excessive-collision check for statistics and interrupts. SGMII/1000Base-X
                                                                 half-duplex only. */
#else /* Word 0 - Little Endian */
        uint64_t xscol_en              : 1;  /**< [  0:  0](R/W) Enables the excessive-collision check for statistics and interrupts. SGMII/1000Base-X
                                                                 half-duplex only. */
        uint64_t xsdef_en              : 1;  /**< [  1:  1](R/W) Enables the excessive-deferral check for statistics and interrupts. SGMII/1000Base-X half-
                                                                 duplex only. */
        uint64_t tx_fc_type            : 1;  /**< [  2:  2](R/W) Transmit side flow control type select.
                                                                 0 = GMI MAC transmits ITU G.999.1 pause frames.
                                                                 1 = GMI MAC transmits 802.3 pause frames. */
        uint64_t link_drain            : 1;  /**< [  3:  3](R/W) Enable dropping of full packets to allow CGX and NIC to drain their FIFOs. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_ctl_s cn; */
} bdk_cgxx_gmp_gmi_txx_ctl_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038270ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_CTL(a,b) bdk_cgxx_gmp_gmi_txx_ctl_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_CTL(a,b) "CGXX_GMP_GMI_TXX_CTL"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_CTL(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_int
 *
 * CGX GMI TX Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1C/H) A packet with a PTP request was not able to be sent due to XSCOL. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1C/H) TX late collision. (SGMII/1000BASE-X half-duplex only) */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1C/H) TX excessive deferral. (SGMII/1000BASE-X half-duplex only) */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1C/H) TX excessive collisions. (SGMII/1000BASE-X half-duplex only) */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) TX underflow. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) TX underflow. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1C/H) TX excessive collisions. (SGMII/1000BASE-X half-duplex only) */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1C/H) TX excessive deferral. (SGMII/1000BASE-X half-duplex only) */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1C/H) TX late collision. (SGMII/1000BASE-X half-duplex only) */
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1C/H) A packet with a PTP request was not able to be sent due to XSCOL. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_int_s cn; */
} bdk_cgxx_gmp_gmi_txx_int_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038500ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_INT(a,b) bdk_cgxx_gmp_gmi_txx_int_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_INT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_INT(a,b) "CGXX_GMP_GMI_TXX_INT"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_INT(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_int_ena_w1c
 *
 * CGX GMI TX Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[PTP_LOST]. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[LATE_COL]. */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSDEF]. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSCOL]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[UNDFLW]. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[UNDFLW]. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSCOL]. */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSDEF]. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[LATE_COL]. */
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[PTP_LOST]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_int_ena_w1c_s cn; */
} bdk_cgxx_gmp_gmi_txx_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038510ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(a,b) bdk_cgxx_gmp_gmi_txx_int_ena_w1c_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(a,b) "CGXX_GMP_GMI_TXX_INT_ENA_W1C"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_int_ena_w1s
 *
 * CGX GMI TX Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[PTP_LOST]. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[LATE_COL]. */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSDEF]. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSCOL]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[UNDFLW]. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[UNDFLW]. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSCOL]. */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSDEF]. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[LATE_COL]. */
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_GMI_TX(0..3)_INT[PTP_LOST]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_int_ena_w1s_s cn; */
} bdk_cgxx_gmp_gmi_txx_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038518ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(a,b) bdk_cgxx_gmp_gmi_txx_int_ena_w1s_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(a,b) "CGXX_GMP_GMI_TXX_INT_ENA_W1S"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_int_w1s
 *
 * CGX GMI TX Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[PTP_LOST]. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[LATE_COL]. */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSDEF]. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSCOL]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[UNDFLW]. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[UNDFLW]. */
        uint64_t xscol                 : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSCOL]. */
        uint64_t xsdef                 : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[XSDEF]. */
        uint64_t late_col              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[LATE_COL]. */
        uint64_t ptp_lost              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_GMP_GMI_TX(0..3)_INT[PTP_LOST]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_int_w1s_s cn; */
} bdk_cgxx_gmp_gmi_txx_int_w1s_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038508ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_INT_W1S(a,b) bdk_cgxx_gmp_gmi_txx_int_w1s_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_INT_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_INT_W1S(a,b) "CGXX_GMP_GMI_TXX_INT_W1S"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_INT_W1S(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_min_pkt
 *
 * CGX GMI TX Minimum-Size-Packet Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_min_pkt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t min_size              : 8;  /**< [  7:  0](R/W) Minimum frame size in bytes before the FCS is applied.
                                                                 Padding is only appended when CGX()_GMP_GMI_TX()_APPEND[PAD] for the corresponding
                                                                 LMAC is set.

                                                                 When LMAC_TYPE=SGMII/QSGMII, packets are padded to [MIN_SIZE]+1. The reset value pads to
                                                                 60
                                                                 bytes. */
#else /* Word 0 - Little Endian */
        uint64_t min_size              : 8;  /**< [  7:  0](R/W) Minimum frame size in bytes before the FCS is applied.
                                                                 Padding is only appended when CGX()_GMP_GMI_TX()_APPEND[PAD] for the corresponding
                                                                 LMAC is set.

                                                                 When LMAC_TYPE=SGMII/QSGMII, packets are padded to [MIN_SIZE]+1. The reset value pads to
                                                                 60
                                                                 bytes. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_min_pkt_s cn; */
} bdk_cgxx_gmp_gmi_txx_min_pkt_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_MIN_PKT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_MIN_PKT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038240ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_MIN_PKT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_MIN_PKT(a,b) bdk_cgxx_gmp_gmi_txx_min_pkt_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_MIN_PKT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_MIN_PKT(a,b) "CGXX_GMP_GMI_TXX_MIN_PKT"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_MIN_PKT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_MIN_PKT(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_MIN_PKT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_pause_pkt_interval
 *
 * CGX GMI TX PAUSE-Packet Transmission-Interval Registers
 * This register specifies how often PAUSE packets are sent.
 * Internal:
 * Notes:
 * Choosing proper values of CGX()_GMP_GMI_TX()_PAUSE_PKT_TIME[PTIME] and
 * CGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL[INTERVAL] can be challenging to the system
 * designer.  It is suggested that TIME be much greater than INTERVAL and
 * CGX()_GMP_GMI_TX()_PAUSE_ZERO[SEND] be set.  This allows a periodic refresh of the PAUSE
 * count and then when the backpressure condition is lifted, a PAUSE packet
 * with TIME==0 will be sent indicating that Octane is ready for additional
 * data.
 *
 * If the system chooses to not set CGX()_GMP_GMI_TX()_PAUSE_ZERO[SEND], then it is
 * suggested that TIME and INTERVAL are programmed such that they satisify the
 * following rule:
 *
 * _ INTERVAL <= TIME - (largest_pkt_size + IFG + pause_pkt_size)
 *
 * where largest_pkt_size is that largest packet that the system can send
 * (normally 1518B), IFG is the interframe gap and pause_pkt_size is the size
 * of the PAUSE packet (normally 64B).
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_pause_pkt_interval_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t interval              : 16; /**< [ 15:  0](R/W) Arbitrate for a 802.3 PAUSE packet every ([INTERVAL] * 512)
                                                                 bit-times. Normally, 0 < [INTERVAL] < CGX()_GMP_GMI_TX()_PAUSE_PKT_TIME[PTIME].

                                                                 [INTERVAL] = 0 only sends a single PAUSE packet for each backpressure event.
                                                                 CGX()_GMP_GMI_TX()_PAUSE_ZERO[SEND] must be 1 when [INTERVAL] = 0.
                                                                 [INTERVAL] should be 0x0 if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
#else /* Word 0 - Little Endian */
        uint64_t interval              : 16; /**< [ 15:  0](R/W) Arbitrate for a 802.3 PAUSE packet every ([INTERVAL] * 512)
                                                                 bit-times. Normally, 0 < [INTERVAL] < CGX()_GMP_GMI_TX()_PAUSE_PKT_TIME[PTIME].

                                                                 [INTERVAL] = 0 only sends a single PAUSE packet for each backpressure event.
                                                                 CGX()_GMP_GMI_TX()_PAUSE_ZERO[SEND] must be 1 when [INTERVAL] = 0.
                                                                 [INTERVAL] should be 0x0 if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_pause_pkt_interval_s cn; */
} bdk_cgxx_gmp_gmi_txx_pause_pkt_interval_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038248ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(a,b) bdk_cgxx_gmp_gmi_txx_pause_pkt_interval_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(a,b) "CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_INTERVAL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_pause_pkt_time
 *
 * CGX GMI TX PAUSE Packet PAUSE-Time Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_pause_pkt_time_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ptime                 : 16; /**< [ 15:  0](R/W) Provides the pause_time field placed in outbound 802.3 PAUSE packets
                                                                 in 512 bit-times. Normally, [PTIME] >
                                                                 CGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL[INTERVAL]. For programming information see
                                                                 CGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL.
                                                                 [PTIME] should be 0x0 if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
#else /* Word 0 - Little Endian */
        uint64_t ptime                 : 16; /**< [ 15:  0](R/W) Provides the pause_time field placed in outbound 802.3 PAUSE packets
                                                                 in 512 bit-times. Normally, [PTIME] >
                                                                 CGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL[INTERVAL]. For programming information see
                                                                 CGX()_GMP_GMI_TX()_PAUSE_PKT_INTERVAL.
                                                                 [PTIME] should be 0x0 if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_pause_pkt_time_s cn; */
} bdk_cgxx_gmp_gmi_txx_pause_pkt_time_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038238ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(a,b) bdk_cgxx_gmp_gmi_txx_pause_pkt_time_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(a,b) "CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_PAUSE_PKT_TIME(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_pause_togo
 *
 * CGX GMI TX Time-to-Backpressure Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_pause_togo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ptime                 : 16; /**< [ 15:  0](RO/H) Amount of time remaining to backpressure, from the standard 802.3 PAUSE timer. */
#else /* Word 0 - Little Endian */
        uint64_t ptime                 : 16; /**< [ 15:  0](RO/H) Amount of time remaining to backpressure, from the standard 802.3 PAUSE timer. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_pause_togo_s cn; */
} bdk_cgxx_gmp_gmi_txx_pause_togo_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038258ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_PAUSE_TOGO", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(a,b) bdk_cgxx_gmp_gmi_txx_pause_togo_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(a,b) "CGXX_GMP_GMI_TXX_PAUSE_TOGO"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_PAUSE_TOGO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_pause_zero
 *
 * CGX GMI TX PAUSE-Zero-Enable Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_pause_zero_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t send                  : 1;  /**< [  0:  0](R/W) Send PAUSE-zero enable. When this bit is set, and the backpressure condition is clear, it
                                                                 allows sending a PAUSE packet with pause_time of 0 to enable the channel.
                                                                 [SEND] should be set if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
#else /* Word 0 - Little Endian */
        uint64_t send                  : 1;  /**< [  0:  0](R/W) Send PAUSE-zero enable. When this bit is set, and the backpressure condition is clear, it
                                                                 allows sending a PAUSE packet with pause_time of 0 to enable the channel.
                                                                 [SEND] should be set if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_pause_zero_s cn; */
} bdk_cgxx_gmp_gmi_txx_pause_zero_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038260ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_PAUSE_ZERO", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(a,b) bdk_cgxx_gmp_gmi_txx_pause_zero_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(a,b) "CGXX_GMP_GMI_TXX_PAUSE_ZERO"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_PAUSE_ZERO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_sgmii_ctl
 *
 * CGX SGMII Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_sgmii_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t align                 : 1;  /**< [  0:  0](R/W) Align the transmission to even cycles: (SGMII/1000BASE-X half-duplex only)
                                                                 Recommended value is: ALIGN = !CGX()_GMP_GMI_TX()_APPEND[PREAMBLE].
                                                                 (See Transmit Conversion to Code groups, Transmit Conversion to Code Groups for a complete
                                                                 discussion.)

                                                                 _ 0 = Data can be sent on any cycle. In this mode, the interface functions at maximum
                                                                 bandwidth. It is possible for the TX PCS machine to drop the first byte of the TX frame.
                                                                 When CGX()_GMP_GMI_TX()_APPEND[PREAMBLE] is set, the first byte is a preamble
                                                                 byte, which can be dropped to compensate for an extended IPG.

                                                                 _ 1 = Data is only sent on even cycles. In this mode, there can be bandwidth implications
                                                                 when sending odd-byte packets as the IPG can extend an extra cycle. There will be no loss
                                                                 of data. */
#else /* Word 0 - Little Endian */
        uint64_t align                 : 1;  /**< [  0:  0](R/W) Align the transmission to even cycles: (SGMII/1000BASE-X half-duplex only)
                                                                 Recommended value is: ALIGN = !CGX()_GMP_GMI_TX()_APPEND[PREAMBLE].
                                                                 (See Transmit Conversion to Code groups, Transmit Conversion to Code Groups for a complete
                                                                 discussion.)

                                                                 _ 0 = Data can be sent on any cycle. In this mode, the interface functions at maximum
                                                                 bandwidth. It is possible for the TX PCS machine to drop the first byte of the TX frame.
                                                                 When CGX()_GMP_GMI_TX()_APPEND[PREAMBLE] is set, the first byte is a preamble
                                                                 byte, which can be dropped to compensate for an extended IPG.

                                                                 _ 1 = Data is only sent on even cycles. In this mode, there can be bandwidth implications
                                                                 when sending odd-byte packets as the IPG can extend an extra cycle. There will be no loss
                                                                 of data. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_sgmii_ctl_s cn; */
} bdk_cgxx_gmp_gmi_txx_sgmii_ctl_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038300ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_SGMII_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(a,b) bdk_cgxx_gmp_gmi_txx_sgmii_ctl_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(a,b) "CGXX_GMP_GMI_TXX_SGMII_CTL"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_SGMII_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_slot
 *
 * CGX GMI TX Slottime Counter Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_slot_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t slot                  : 10; /**< [  9:  0](R/W) Slottime (refer to Std 802.3 to set correctly):
                                                                 10/100 Mbs: Set SLOT to 0x40.
                                                                 1000 Mbs: Set SLOT to 0x200.

                                                                 SGMII/QSGMII/1000Base-X only. */
#else /* Word 0 - Little Endian */
        uint64_t slot                  : 10; /**< [  9:  0](R/W) Slottime (refer to Std 802.3 to set correctly):
                                                                 10/100 Mbs: Set SLOT to 0x40.
                                                                 1000 Mbs: Set SLOT to 0x200.

                                                                 SGMII/QSGMII/1000Base-X only. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_slot_s cn; */
} bdk_cgxx_gmp_gmi_txx_slot_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_SLOT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_SLOT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038220ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_SLOT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_SLOT(a,b) bdk_cgxx_gmp_gmi_txx_slot_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_SLOT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_SLOT(a,b) "CGXX_GMP_GMI_TXX_SLOT"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_SLOT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_SLOT(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_SLOT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_soft_pause
 *
 * CGX GMI TX Software PAUSE Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_soft_pause_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ptime                 : 16; /**< [ 15:  0](R/W) Back off the TX bus for ([PTIME] * 512) bit-times.
                                                                 [PTIME] should be 0x0 if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
#else /* Word 0 - Little Endian */
        uint64_t ptime                 : 16; /**< [ 15:  0](R/W) Back off the TX bus for ([PTIME] * 512) bit-times.
                                                                 [PTIME] should be 0x0 if CGX()_GMP_GMI_TX()_CTL[TX_FC_TYPE] is clear (G.999.1). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_soft_pause_s cn; */
} bdk_cgxx_gmp_gmi_txx_soft_pause_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038250ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_SOFT_PAUSE", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(a,b) bdk_cgxx_gmp_gmi_txx_soft_pause_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(a,b) "CGXX_GMP_GMI_TXX_SOFT_PAUSE"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_SOFT_PAUSE(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx#_thresh
 *
 * CGX GMI TX Threshold Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_txx_thresh_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t cnt                   : 11; /**< [ 10:  0](R/W) Number of 128-bit words to accumulate in the TX FIFO before sending on the packet
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0. The recommended setting for

                                                                 In all modes, this register cannot exceed the TX FIFO depth configured by
                                                                 CGX()_CMR_TX_LMACS[LMACS]. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 11; /**< [ 10:  0](R/W) Number of 128-bit words to accumulate in the TX FIFO before sending on the packet
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0. The recommended setting for

                                                                 In all modes, this register cannot exceed the TX FIFO depth configured by
                                                                 CGX()_CMR_TX_LMACS[LMACS]. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_txx_thresh_s cn; */
} bdk_cgxx_gmp_gmi_txx_thresh_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TXX_THRESH(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TXX_THRESH(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8038210ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TXX_THRESH", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TXX_THRESH(a,b) bdk_cgxx_gmp_gmi_txx_thresh_t
#define bustype_BDK_CGXX_GMP_GMI_TXX_THRESH(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TXX_THRESH(a,b) "CGXX_GMP_GMI_TXX_THRESH"
#define device_bar_BDK_CGXX_GMP_GMI_TXX_THRESH(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TXX_THRESH(a,b) (a)
#define arguments_BDK_CGXX_GMP_GMI_TXX_THRESH(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx_col_attempt
 *
 * CGX TX Collision Attempts Before Dropping Frame Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_tx_col_attempt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t limit                 : 5;  /**< [  4:  0](R/W) Number of collision attempts allowed. (SGMII/1000BASE-X half-duplex only.) */
#else /* Word 0 - Little Endian */
        uint64_t limit                 : 5;  /**< [  4:  0](R/W) Number of collision attempts allowed. (SGMII/1000BASE-X half-duplex only.) */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_tx_col_attempt_s cn; */
} bdk_cgxx_gmp_gmi_tx_col_attempt_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8039010ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TX_COL_ATTEMPT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(a) bdk_cgxx_gmp_gmi_tx_col_attempt_t
#define bustype_BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(a) "CGXX_GMP_GMI_TX_COL_ATTEMPT"
#define device_bar_BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(a) (a)
#define arguments_BDK_CGXX_GMP_GMI_TX_COL_ATTEMPT(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx_ifg
 *
 * CGX GMI TX Interframe-Gap Cycles Registers
 * Consider the following when programming IFG1 and IFG2:
 * * For 10/100/1000 Mb/s half-duplex systems that require IEEE 802.3 compatibility, IFG1 must be
 * in the range of 1-8, IFG2 must be in the range of 4-12, and the IFG1 + IFG2 sum must be 12.
 * * For 10/100/1000 Mb/s full-duplex systems that require IEEE 802.3 compatibility, IFG1 must be
 * in the range of 1-11, IFG2 must be in the range of 1-11, and the IFG1 + IFG2 sum must be 12.
 * For all other systems, IFG1 and IFG2 can be any value in the range of 1-15, allowing for a
 * total possible IFG sum of 2-30.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_tx_ifg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ifg2                  : 4;  /**< [  7:  4](R/W) Remainder of interFrameGap timing, equal to interFrameGap - IFG1 (in IFG2 * 8 bits). If
                                                                 CRS is detected during IFG2, the interFrameSpacing timer is not reset and a frame is
                                                                 transmitted once the timer expires. */
        uint64_t ifg1                  : 4;  /**< [  3:  0](R/W) First portion of interFrameGap timing, in the range of 0 to 2/3 (in IFG2 * 8 bits). If CRS
                                                                 is detected during IFG1, the interFrameSpacing timer is reset and a frame is not
                                                                 transmitted. */
#else /* Word 0 - Little Endian */
        uint64_t ifg1                  : 4;  /**< [  3:  0](R/W) First portion of interFrameGap timing, in the range of 0 to 2/3 (in IFG2 * 8 bits). If CRS
                                                                 is detected during IFG1, the interFrameSpacing timer is reset and a frame is not
                                                                 transmitted. */
        uint64_t ifg2                  : 4;  /**< [  7:  4](R/W) Remainder of interFrameGap timing, equal to interFrameGap - IFG1 (in IFG2 * 8 bits). If
                                                                 CRS is detected during IFG2, the interFrameSpacing timer is not reset and a frame is
                                                                 transmitted once the timer expires. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_tx_ifg_s cn; */
} bdk_cgxx_gmp_gmi_tx_ifg_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TX_IFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TX_IFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8039000ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TX_IFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TX_IFG(a) bdk_cgxx_gmp_gmi_tx_ifg_t
#define bustype_BDK_CGXX_GMP_GMI_TX_IFG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TX_IFG(a) "CGXX_GMP_GMI_TX_IFG"
#define device_bar_BDK_CGXX_GMP_GMI_TX_IFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TX_IFG(a) (a)
#define arguments_BDK_CGXX_GMP_GMI_TX_IFG(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx_jam
 *
 * CGX GMI TX JAM Pattern Registers
 * This register provides the pattern used in JAM bytes.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_tx_jam_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t jam                   : 8;  /**< [  7:  0](R/W) JAM pattern. (SGMII/1000BASE-X half-duplex only.) */
#else /* Word 0 - Little Endian */
        uint64_t jam                   : 8;  /**< [  7:  0](R/W) JAM pattern. (SGMII/1000BASE-X half-duplex only.) */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_tx_jam_s cn; */
} bdk_cgxx_gmp_gmi_tx_jam_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TX_JAM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TX_JAM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8039008ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TX_JAM", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TX_JAM(a) bdk_cgxx_gmp_gmi_tx_jam_t
#define bustype_BDK_CGXX_GMP_GMI_TX_JAM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TX_JAM(a) "CGXX_GMP_GMI_TX_JAM"
#define device_bar_BDK_CGXX_GMP_GMI_TX_JAM(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TX_JAM(a) (a)
#define arguments_BDK_CGXX_GMP_GMI_TX_JAM(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx_lfsr
 *
 * CGX GMI TX LFSR Registers
 * This register shows the contents of the linear feedback shift register (LFSR), which is used
 * to implement truncated binary exponential backoff.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_tx_lfsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t lfsr                  : 16; /**< [ 15:  0](R/W/H) Contains the current state of the LFSR, which is used to feed random numbers to compute
                                                                 truncated binary exponential backoff. (SGMII/1000Base-X half-duplex only.) */
#else /* Word 0 - Little Endian */
        uint64_t lfsr                  : 16; /**< [ 15:  0](R/W/H) Contains the current state of the LFSR, which is used to feed random numbers to compute
                                                                 truncated binary exponential backoff. (SGMII/1000Base-X half-duplex only.) */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_tx_lfsr_s cn; */
} bdk_cgxx_gmp_gmi_tx_lfsr_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TX_LFSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TX_LFSR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8039028ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TX_LFSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TX_LFSR(a) bdk_cgxx_gmp_gmi_tx_lfsr_t
#define bustype_BDK_CGXX_GMP_GMI_TX_LFSR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TX_LFSR(a) "CGXX_GMP_GMI_TX_LFSR"
#define device_bar_BDK_CGXX_GMP_GMI_TX_LFSR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TX_LFSR(a) (a)
#define arguments_BDK_CGXX_GMP_GMI_TX_LFSR(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx_pause_pkt_dmac
 *
 * CGX TX PAUSE-Packet DMAC-Field Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_tx_pause_pkt_dmac_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The DMAC field, which is placed in outbound PAUSE packets. */
#else /* Word 0 - Little Endian */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The DMAC field, which is placed in outbound PAUSE packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_tx_pause_pkt_dmac_s cn; */
} bdk_cgxx_gmp_gmi_tx_pause_pkt_dmac_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8039018ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(a) bdk_cgxx_gmp_gmi_tx_pause_pkt_dmac_t
#define bustype_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(a) "CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC"
#define device_bar_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(a) (a)
#define arguments_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_DMAC(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_gmi_tx_pause_pkt_type
 *
 * CGX GMI TX PAUSE-Packet-PTYPE Field Registers
 * This register provides the PTYPE field that is placed in outbound PAUSE packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_gmi_tx_pause_pkt_type_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ptype                 : 16; /**< [ 15:  0](R/W) The PTYPE field placed in outbound PAUSE packets. */
#else /* Word 0 - Little Endian */
        uint64_t ptype                 : 16; /**< [ 15:  0](R/W) The PTYPE field placed in outbound PAUSE packets. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_gmi_tx_pause_pkt_type_s cn; */
} bdk_cgxx_gmp_gmi_tx_pause_pkt_type_t;

static inline uint64_t BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8039020ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(a) bdk_cgxx_gmp_gmi_tx_pause_pkt_type_t
#define bustype_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(a) "CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE"
#define device_bar_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(a) (a)
#define arguments_BDK_CGXX_GMP_GMI_TX_PAUSE_PKT_TYPE(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs#_tx_lpi_timing
 *
 * CGX GMP GMI  TX EEE LPI Timing Parameters Registers
 * Transmitter LPI timing parameters Tsl, Tql and Tul
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcsx_tx_lpi_timing_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tsl                   : 16; /**< [ 63: 48](R/W) Local Sleep Time from entering the TX_SLEEP state to when tx_quiet is set to TRUE
                                                                 Reset value gives 20us with a 1200Mhz clock. */
        uint64_t tul                   : 16; /**< [ 47: 32](R/W) Local Refresh Time from entry into the TX_REFRESH state to entry into the TX_QUIET state.
                                                                 Reset value gives 20us with a 1200Mhz clock. */
        uint64_t reserved_24_31        : 8;
        uint64_t tql                   : 24; /**< [ 23:  0](R/W) Local Quiet Time from when tx_quiet is set to TRUE to entry into the TX_REFRESH state
                                                                 Reset value gives 2.55ms with a 1200Mhz clock. */
#else /* Word 0 - Little Endian */
        uint64_t tql                   : 24; /**< [ 23:  0](R/W) Local Quiet Time from when tx_quiet is set to TRUE to entry into the TX_REFRESH state
                                                                 Reset value gives 2.55ms with a 1200Mhz clock. */
        uint64_t reserved_24_31        : 8;
        uint64_t tul                   : 16; /**< [ 47: 32](R/W) Local Refresh Time from entry into the TX_REFRESH state to entry into the TX_QUIET state.
                                                                 Reset value gives 20us with a 1200Mhz clock. */
        uint64_t tsl                   : 16; /**< [ 63: 48](R/W) Local Sleep Time from entering the TX_SLEEP state to when tx_quiet is set to TRUE
                                                                 Reset value gives 20us with a 1200Mhz clock. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcsx_tx_lpi_timing_s cn; */
} bdk_cgxx_gmp_pcsx_tx_lpi_timing_t;

static inline uint64_t BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030800ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCSX_TX_LPI_TIMING", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(a,b) bdk_cgxx_gmp_pcsx_tx_lpi_timing_t
#define bustype_BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(a,b) "CGXX_GMP_PCSX_TX_LPI_TIMING"
#define device_bar_BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCSX_TX_LPI_TIMING(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_an#_adv
 *
 * CGX GMP PCS Autonegotiation Advertisement Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_anx_adv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page capable. This feature is not supported; this field is always 0. */
        uint64_t reserved_14           : 1;
        uint64_t rem_flt               : 2;  /**< [ 13: 12](R/W/H) Remote fault.
                                                                 0x0 = Link OK, XMIT = DATA.
                                                                 0x1 = Link failure (loss of sync, XMIT !=DATA).
                                                                 0x2 = Local device offline.
                                                                 0x3 = Autonegotiation error; failure to complete autonegotiation. AN error is set if
                                                                 resolution function precludes operation with link partner. */
        uint64_t reserved_9_11         : 3;
        uint64_t pause                 : 2;  /**< [  8:  7](R/W) PAUSE frame flow capability across link, exchanged during autonegotiation as follows:
                                                                 0x0 = No PAUSE.
                                                                 0x1 = Symmetric PAUSE.
                                                                 0x2 = Asymmetric PAUSE.
                                                                 0x3 = Both symmetric and asymmetric PAUSE to local device. */
        uint64_t hfd                   : 1;  /**< [  6:  6](R/W) Half-duplex. When set, local device is half-duplex capable. */
        uint64_t fd                    : 1;  /**< [  5:  5](R/W) Full-duplex. When set, local device is full-duplex capable. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t fd                    : 1;  /**< [  5:  5](R/W) Full-duplex. When set, local device is full-duplex capable. */
        uint64_t hfd                   : 1;  /**< [  6:  6](R/W) Half-duplex. When set, local device is half-duplex capable. */
        uint64_t pause                 : 2;  /**< [  8:  7](R/W) PAUSE frame flow capability across link, exchanged during autonegotiation as follows:
                                                                 0x0 = No PAUSE.
                                                                 0x1 = Symmetric PAUSE.
                                                                 0x2 = Asymmetric PAUSE.
                                                                 0x3 = Both symmetric and asymmetric PAUSE to local device. */
        uint64_t reserved_9_11         : 3;
        uint64_t rem_flt               : 2;  /**< [ 13: 12](R/W/H) Remote fault.
                                                                 0x0 = Link OK, XMIT = DATA.
                                                                 0x1 = Link failure (loss of sync, XMIT !=DATA).
                                                                 0x2 = Local device offline.
                                                                 0x3 = Autonegotiation error; failure to complete autonegotiation. AN error is set if
                                                                 resolution function precludes operation with link partner. */
        uint64_t reserved_14           : 1;
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page capable. This feature is not supported; this field is always 0. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_anx_adv_s cn; */
} bdk_cgxx_gmp_pcs_anx_adv_t;

static inline uint64_t BDK_CGXX_GMP_PCS_ANX_ADV(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_ANX_ADV(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030010ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_ANX_ADV", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_ANX_ADV(a,b) bdk_cgxx_gmp_pcs_anx_adv_t
#define bustype_BDK_CGXX_GMP_PCS_ANX_ADV(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_ANX_ADV(a,b) "CGXX_GMP_PCS_ANX_ADV"
#define device_bar_BDK_CGXX_GMP_PCS_ANX_ADV(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_ANX_ADV(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_ANX_ADV(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_an#_ext_st
 *
 * CGX GMO PCS Autonegotiation Extended Status Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_anx_ext_st_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t thou_xfd              : 1;  /**< [ 15: 15](RO/H) When set, PHY is 1000 BASE-X full duplex capable. */
        uint64_t thou_xhd              : 1;  /**< [ 14: 14](RO/H) When set, PHY is 1000 BASE-X half duplex capable. */
        uint64_t thou_tfd              : 1;  /**< [ 13: 13](RO/H) When set, PHY is 1000 BASE-T full duplex capable. */
        uint64_t thou_thd              : 1;  /**< [ 12: 12](RO/H) When set, PHY is 1000 BASE-T half duplex capable. */
        uint64_t reserved_0_11         : 12;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_11         : 12;
        uint64_t thou_thd              : 1;  /**< [ 12: 12](RO/H) When set, PHY is 1000 BASE-T half duplex capable. */
        uint64_t thou_tfd              : 1;  /**< [ 13: 13](RO/H) When set, PHY is 1000 BASE-T full duplex capable. */
        uint64_t thou_xhd              : 1;  /**< [ 14: 14](RO/H) When set, PHY is 1000 BASE-X half duplex capable. */
        uint64_t thou_xfd              : 1;  /**< [ 15: 15](RO/H) When set, PHY is 1000 BASE-X full duplex capable. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_anx_ext_st_s cn; */
} bdk_cgxx_gmp_pcs_anx_ext_st_t;

static inline uint64_t BDK_CGXX_GMP_PCS_ANX_EXT_ST(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_ANX_EXT_ST(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030028ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_ANX_EXT_ST", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_ANX_EXT_ST(a,b) bdk_cgxx_gmp_pcs_anx_ext_st_t
#define bustype_BDK_CGXX_GMP_PCS_ANX_EXT_ST(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_ANX_EXT_ST(a,b) "CGXX_GMP_PCS_ANX_EXT_ST"
#define device_bar_BDK_CGXX_GMP_PCS_ANX_EXT_ST(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_ANX_EXT_ST(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_ANX_EXT_ST(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_an#_lp_abil
 *
 * CGX GMP PCS Autonegotiation Link Partner Ability Registers
 * This is the autonegotiation Link partner ability register 5 as per IEEE 802.3, Clause 37.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_anx_lp_abil_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page capable:
                                                                 0 = Link partner not next page capable.
                                                                 1 = Link partner next page capable. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) When set, indicates acknowledgement received. */
        uint64_t rem_flt               : 2;  /**< [ 13: 12](RO/H) Link partner's link status as follows:
                                                                 0x0 = Link OK.
                                                                 0x1 = Offline.
                                                                 0x2 = Link failure.
                                                                 0x3 = Autonegotiation error. */
        uint64_t reserved_9_11         : 3;
        uint64_t pause                 : 2;  /**< [  8:  7](RO/H) Link partner PAUSE setting as follows:
                                                                 0x0 = No PAUSE.
                                                                 0x1 = Symmetric PAUSE.
                                                                 0x2 = Asymmetric PAUSE.
                                                                 0x3 = Both symmetric and asymmetric PAUSE to local device. */
        uint64_t hfd                   : 1;  /**< [  6:  6](RO/H) Half-duplex. When set, link partner is half-duplex capable. */
        uint64_t fd                    : 1;  /**< [  5:  5](RO/H) Full-duplex. When set, link partner is full-duplex capable. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t fd                    : 1;  /**< [  5:  5](RO/H) Full-duplex. When set, link partner is full-duplex capable. */
        uint64_t hfd                   : 1;  /**< [  6:  6](RO/H) Half-duplex. When set, link partner is half-duplex capable. */
        uint64_t pause                 : 2;  /**< [  8:  7](RO/H) Link partner PAUSE setting as follows:
                                                                 0x0 = No PAUSE.
                                                                 0x1 = Symmetric PAUSE.
                                                                 0x2 = Asymmetric PAUSE.
                                                                 0x3 = Both symmetric and asymmetric PAUSE to local device. */
        uint64_t reserved_9_11         : 3;
        uint64_t rem_flt               : 2;  /**< [ 13: 12](RO/H) Link partner's link status as follows:
                                                                 0x0 = Link OK.
                                                                 0x1 = Offline.
                                                                 0x2 = Link failure.
                                                                 0x3 = Autonegotiation error. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) When set, indicates acknowledgement received. */
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page capable:
                                                                 0 = Link partner not next page capable.
                                                                 1 = Link partner next page capable. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_anx_lp_abil_s cn; */
} bdk_cgxx_gmp_pcs_anx_lp_abil_t;

static inline uint64_t BDK_CGXX_GMP_PCS_ANX_LP_ABIL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_ANX_LP_ABIL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030018ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_ANX_LP_ABIL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_ANX_LP_ABIL(a,b) bdk_cgxx_gmp_pcs_anx_lp_abil_t
#define bustype_BDK_CGXX_GMP_PCS_ANX_LP_ABIL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_ANX_LP_ABIL(a,b) "CGXX_GMP_PCS_ANX_LP_ABIL"
#define device_bar_BDK_CGXX_GMP_PCS_ANX_LP_ABIL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_ANX_LP_ABIL(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_ANX_LP_ABIL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_an#_results
 *
 * CGX GMP PCS Autonegotiation Results Registers
 * This register is not valid when CGX()_GMP_PCS_MISC()_CTL[AN_OVRD] is set to 1. If
 * CGX()_GMP_PCS_MISC()_CTL[AN_OVRD] is set to 0 and
 * CGX()_GMP_PCS_AN()_RESULTS[AN_CPT] is set to 1, this register is valid.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_anx_results_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t pause                 : 2;  /**< [  6:  5](RO/H) PAUSE selection ('don't care' for SGMII/QSGMII) as follows:
                                                                 0x0 = Disable PAUSE, TX and RX.
                                                                 0x1 = Enable PAUSE frames, RX only.
                                                                 0x2 = Enable PAUSE frames, TX only.
                                                                 0x3 = Enable PAUSE frames, TX and RX. */
        uint64_t spd                   : 2;  /**< [  4:  3](RO/H) Link speed selection as follows:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t an_cpt                : 1;  /**< [  2:  2](RO/H) Autonegotiation completed.
                                                                 1 = Autonegotiation completed.
                                                                 0 = Autonegotiation not completed or failed. */
        uint64_t dup                   : 1;  /**< [  1:  1](RO/H) Duplex mode. 1 = full duplex, 0 = half duplex. */
        uint64_t link_ok               : 1;  /**< [  0:  0](RO/H) Link status: 1 = link up (OK), 1 = link down. */
#else /* Word 0 - Little Endian */
        uint64_t link_ok               : 1;  /**< [  0:  0](RO/H) Link status: 1 = link up (OK), 1 = link down. */
        uint64_t dup                   : 1;  /**< [  1:  1](RO/H) Duplex mode. 1 = full duplex, 0 = half duplex. */
        uint64_t an_cpt                : 1;  /**< [  2:  2](RO/H) Autonegotiation completed.
                                                                 1 = Autonegotiation completed.
                                                                 0 = Autonegotiation not completed or failed. */
        uint64_t spd                   : 2;  /**< [  4:  3](RO/H) Link speed selection as follows:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t pause                 : 2;  /**< [  6:  5](RO/H) PAUSE selection ('don't care' for SGMII/QSGMII) as follows:
                                                                 0x0 = Disable PAUSE, TX and RX.
                                                                 0x1 = Enable PAUSE frames, RX only.
                                                                 0x2 = Enable PAUSE frames, TX only.
                                                                 0x3 = Enable PAUSE frames, TX and RX. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_anx_results_s cn; */
} bdk_cgxx_gmp_pcs_anx_results_t;

static inline uint64_t BDK_CGXX_GMP_PCS_ANX_RESULTS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_ANX_RESULTS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030020ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_ANX_RESULTS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_ANX_RESULTS(a,b) bdk_cgxx_gmp_pcs_anx_results_t
#define bustype_BDK_CGXX_GMP_PCS_ANX_RESULTS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_ANX_RESULTS(a,b) "CGXX_GMP_PCS_ANX_RESULTS"
#define device_bar_BDK_CGXX_GMP_PCS_ANX_RESULTS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_ANX_RESULTS(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_ANX_RESULTS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_int#
 *
 * CGX GMP PCS Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1C/H) Code group sync failure debug help. CGX()_GMP_PCS_INT()[DBG_SYNC] interrupt fires when
                                                                 code group
                                                                 synchronization state machine makes a transition from SYNC_ACQUIRED_1 state to
                                                                 SYNC_ACQUIRED_2 state. (See IEEE 802.3-2005, figure 37-9). It indicates that a bad code
                                                                 group was received after code group synchronization was achieved. This interrupt should be
                                                                 disabled during normal link operation. Use it as a debug help feature only. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1C/H) Set whenever duplex mode changes on the link. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1C/H) Set by hardware whenever RX sync state machine reaches a bad state. Should never be set
                                                                 during normal operation. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1C/H) Set by hardware whenever autonegotiation state machine reaches a bad state. Should never
                                                                 be set during normal operation. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1C/H) Set by hardware whenever code group sync or bit lock failure occurs. Cannot fire in loopback1 mode. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1C/H) Set by hardware whenever RX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1C/H) Set whenever RX receives a code group error in 10-bit to 8-bit decode logic. Cannot fire
                                                                 in loopback1 mode. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1C/H) Set by hardware whenever TX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1C/H) Set whenever hardware detects a TX FIFO overflow condition. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1C/H) Set whenever hardware detects a TX FIFO underflow condition. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1C/H) Autonegotiation error; AN resolution function failed. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1C/H) Set whenever hardware detects a change in the XMIT variable. XMIT variable states are
                                                                 IDLE, CONFIG and DATA. */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1C/H) Set by hardware whenever link speed has changed. */
#else /* Word 0 - Little Endian */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1C/H) Set by hardware whenever link speed has changed. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1C/H) Set whenever hardware detects a change in the XMIT variable. XMIT variable states are
                                                                 IDLE, CONFIG and DATA. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1C/H) Autonegotiation error; AN resolution function failed. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1C/H) Set whenever hardware detects a TX FIFO underflow condition. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1C/H) Set whenever hardware detects a TX FIFO overflow condition. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1C/H) Set by hardware whenever TX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1C/H) Set whenever RX receives a code group error in 10-bit to 8-bit decode logic. Cannot fire
                                                                 in loopback1 mode. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1C/H) Set by hardware whenever RX state machine reaches a bad state. Should never be set during
                                                                 normal operation. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1C/H) Set by hardware whenever code group sync or bit lock failure occurs. Cannot fire in loopback1 mode. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1C/H) Set by hardware whenever autonegotiation state machine reaches a bad state. Should never
                                                                 be set during normal operation. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1C/H) Set by hardware whenever RX sync state machine reaches a bad state. Should never be set
                                                                 during normal operation. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1C/H) Set whenever duplex mode changes on the link. */
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1C/H) Code group sync failure debug help. CGX()_GMP_PCS_INT()[DBG_SYNC] interrupt fires when
                                                                 code group
                                                                 synchronization state machine makes a transition from SYNC_ACQUIRED_1 state to
                                                                 SYNC_ACQUIRED_2 state. (See IEEE 802.3-2005, figure 37-9). It indicates that a bad code
                                                                 group was received after code group synchronization was achieved. This interrupt should be
                                                                 disabled during normal link operation. Use it as a debug help feature only. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_intx_s cn; */
} bdk_cgxx_gmp_pcs_intx_t;

static inline uint64_t BDK_CGXX_GMP_PCS_INTX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_INTX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030080ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_INTX", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_INTX(a,b) bdk_cgxx_gmp_pcs_intx_t
#define bustype_BDK_CGXX_GMP_PCS_INTX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_INTX(a,b) "CGXX_GMP_PCS_INTX"
#define device_bar_BDK_CGXX_GMP_PCS_INTX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_INTX(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_INTX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_int#_ena_w1c
 *
 * CGX GMP PCS Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_intx_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[DBG_SYNC]. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[DUP]. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[SYNC_BAD]. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_BAD]. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXLOCK]. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXBAD]. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXERR]. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXBAD]. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFO]. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFU]. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_ERR]. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[XMIT]. */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[LNKSPD]. */
#else /* Word 0 - Little Endian */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[LNKSPD]. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[XMIT]. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_ERR]. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFU]. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFO]. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXBAD]. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXERR]. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXBAD]. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXLOCK]. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_BAD]. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[SYNC_BAD]. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[DUP]. */
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for CGX(0..3)_GMP_PCS_INT(0..3)[DBG_SYNC]. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_intx_ena_w1c_s cn; */
} bdk_cgxx_gmp_pcs_intx_ena_w1c_t;

static inline uint64_t BDK_CGXX_GMP_PCS_INTX_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_INTX_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030090ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_INTX_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_INTX_ENA_W1C(a,b) bdk_cgxx_gmp_pcs_intx_ena_w1c_t
#define bustype_BDK_CGXX_GMP_PCS_INTX_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_INTX_ENA_W1C(a,b) "CGXX_GMP_PCS_INTX_ENA_W1C"
#define device_bar_BDK_CGXX_GMP_PCS_INTX_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_INTX_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_INTX_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_int#_ena_w1s
 *
 * CGX GMP PCS Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_intx_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[DBG_SYNC]. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[DUP]. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[SYNC_BAD]. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_BAD]. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXLOCK]. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXBAD]. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXERR]. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXBAD]. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFO]. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFU]. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_ERR]. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[XMIT]. */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[LNKSPD]. */
#else /* Word 0 - Little Endian */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[LNKSPD]. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[XMIT]. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_ERR]. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFU]. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFO]. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[TXBAD]. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXERR]. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXBAD]. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[RXLOCK]. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[AN_BAD]. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[SYNC_BAD]. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[DUP]. */
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for CGX(0..3)_GMP_PCS_INT(0..3)[DBG_SYNC]. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_intx_ena_w1s_s cn; */
} bdk_cgxx_gmp_pcs_intx_ena_w1s_t;

static inline uint64_t BDK_CGXX_GMP_PCS_INTX_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_INTX_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030098ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_INTX_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_INTX_ENA_W1S(a,b) bdk_cgxx_gmp_pcs_intx_ena_w1s_t
#define bustype_BDK_CGXX_GMP_PCS_INTX_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_INTX_ENA_W1S(a,b) "CGXX_GMP_PCS_INTX_ENA_W1S"
#define device_bar_BDK_CGXX_GMP_PCS_INTX_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_INTX_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_INTX_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_int#_w1s
 *
 * CGX GMP PCS Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_intx_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[DBG_SYNC]. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[DUP]. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[SYNC_BAD]. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[AN_BAD]. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[RXLOCK]. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[RXBAD]. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[RXERR]. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[TXBAD]. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFO]. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFU]. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[AN_ERR]. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[XMIT]. */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[LNKSPD]. */
#else /* Word 0 - Little Endian */
        uint64_t lnkspd                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[LNKSPD]. */
        uint64_t xmit                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[XMIT]. */
        uint64_t an_err                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[AN_ERR]. */
        uint64_t txfifu                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFU]. */
        uint64_t txfifo                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[TXFIFO]. */
        uint64_t txbad                 : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[TXBAD]. */
        uint64_t rxerr                 : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[RXERR]. */
        uint64_t rxbad                 : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[RXBAD]. */
        uint64_t rxlock                : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[RXLOCK]. */
        uint64_t an_bad                : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[AN_BAD]. */
        uint64_t sync_bad              : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[SYNC_BAD]. */
        uint64_t dup                   : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[DUP]. */
        uint64_t dbg_sync              : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets CGX(0..3)_GMP_PCS_INT(0..3)[DBG_SYNC]. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_intx_w1s_s cn; */
} bdk_cgxx_gmp_pcs_intx_w1s_t;

static inline uint64_t BDK_CGXX_GMP_PCS_INTX_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_INTX_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030088ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_INTX_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_INTX_W1S(a,b) bdk_cgxx_gmp_pcs_intx_w1s_t
#define bustype_BDK_CGXX_GMP_PCS_INTX_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_INTX_W1S(a,b) "CGXX_GMP_PCS_INTX_W1S"
#define device_bar_BDK_CGXX_GMP_PCS_INTX_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_INTX_W1S(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_INTX_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_link#_timer
 *
 * CGX GMP PCS Link Timer Registers
 * This is the 1.6 ms nominal link timer register.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_linkx_timer_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t count                 : 16; /**< [ 15:  0](R/W) (Coprocessor clock period * 1024) * [COUNT] should be 1.6 ms for SGMII/QSGMII and 10 ms
                                                                 otherwise,
                                                                 which is the link timer used in autonegotiation. Reset assumes a 1200 MHz coprocessor
                                                                 clock for 1.6 ms link timer.

                                                                 Internal:
                                                                 FIXME use rst__gbl_100mhz_sclk_edge. */
#else /* Word 0 - Little Endian */
        uint64_t count                 : 16; /**< [ 15:  0](R/W) (Coprocessor clock period * 1024) * [COUNT] should be 1.6 ms for SGMII/QSGMII and 10 ms
                                                                 otherwise,
                                                                 which is the link timer used in autonegotiation. Reset assumes a 1200 MHz coprocessor
                                                                 clock for 1.6 ms link timer.

                                                                 Internal:
                                                                 FIXME use rst__gbl_100mhz_sclk_edge. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_linkx_timer_s cn; */
} bdk_cgxx_gmp_pcs_linkx_timer_t;

static inline uint64_t BDK_CGXX_GMP_PCS_LINKX_TIMER(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_LINKX_TIMER(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030040ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_LINKX_TIMER", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_LINKX_TIMER(a,b) bdk_cgxx_gmp_pcs_linkx_timer_t
#define bustype_BDK_CGXX_GMP_PCS_LINKX_TIMER(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_LINKX_TIMER(a,b) "CGXX_GMP_PCS_LINKX_TIMER"
#define device_bar_BDK_CGXX_GMP_PCS_LINKX_TIMER(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_LINKX_TIMER(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_LINKX_TIMER(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_misc#_ctl
 *
 * CGX GMP SGMII Miscellaneous Control Registers
 * Internal:
 * SGMII bit [12] is really a misnomer, it is a decode  of pi_qlm_cfg pins to indicate SGMII or
 * 1000Base-X modes.
 *
 * Note: The SGMII AN Advertisement Register above will be sent during Auto Negotiation if
 * [MAC_PHY] is set (1=PHY mode). If the bit is not set (0=MAC mode), the
 * tx_Config_Reg<14> becomes ACK bit and tx_Config_Reg<0> is always 1.
 * All other bits in tx_Config_Reg sent will be 0. The PHY dictates the Auto Negotiation results.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_miscx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t qsgmii_comma_wd_en    : 1;  /**< [ 32: 32](R/W) QSGMII comma watchdog byte counter enable. */
        uint64_t qsgmii_comma_wd       : 16; /**< [ 31: 16](R/W) QSGMII comma watchdog byte counter. This counter is used in QSGMII mode and
                                                                 counts incoming bytes to ensure state transitions in the PCS receive side state
                                                                 machine when disparity enable is turned off and bad code groups and commas are
                                                                 not communicated from the code group processor after code group lock. */
        uint64_t reserved_14_15        : 2;
        uint64_t disp_en               : 1;  /**< [ 13: 13](R/W) Disparity check enable.  When LMAC_TYPE=QSGMII the running disparity check should be
                                                                 disabled
                                                                 to
                                                                 prevent propogation across ports.
                                                                 0 = disable disparity check
                                                                 1 = enable disparity checking

                                                                 See GSER()_LANE_MODE[LMODE]. */
        uint64_t sgmii                 : 1;  /**< [ 12: 12](RO/H) SGMII mode.
                                                                 0 = other mode selected.
                                                                 1 = SGMII or 1000BASE-X mode selected.

                                                                 See GSER()_LANE_MODE[LMODE]. */
        uint64_t gmxeno                : 1;  /**< [ 11: 11](R/W) GMI enable override. When set, forces GMI to appear disabled. The enable/disable status of
                                                                 GMI is checked only at SOP of every packet. */
        uint64_t loopbck2              : 1;  /**< [ 10: 10](R/W) Sets external loopback mode to return RX data back out via the TX data path. 0 = No
                                                                 loopback, 1 = Loopback.
                                                                 LOOPBCK1 and LOOPBCK2 modes may not be supported simultaneously. */
        uint64_t mac_phy               : 1;  /**< [  9:  9](R/W) MAC/PHY.
                                                                 0 = MAC.
                                                                 1 = PHY decides the tx_Config_Reg value to be sent during autonegotiation. */
        uint64_t mode                  : 1;  /**< [  8:  8](R/W) Mode bit.

                                                                 _ 0 = SGMII mode is selected and the following note applies.
                                                                 The SGMII AN advertisement register (CGX()_GMP_PCS_SGM()_AN_ADV) is sent during
                                                                 autonegotiation if CGX()_GMP_PCS_MISC()_CTL[MAC_PHY] = 1 (PHY mode). If [MAC_PHY]
                                                                 = 0 (MAC mode), the tx_Config_Reg<14> becomes ACK bit and <0> is always 1. All other bits
                                                                 in tx_Config_Reg sent are 0. The PHY dictates the autonegotiation results.

                                                                 _ 1 = 1000Base-X mode is selected. Autonegotiation follows IEEE 802.3 clause 37. */
        uint64_t an_ovrd               : 1;  /**< [  7:  7](R/W) Autonegotiation results override:
                                                                 0 = Disable.
                                                                 1 = Enable override. Autonegotiation is allowed to happen but the results are ignored
                                                                 when this bit is set.  Duplex and Link speed values are set from CGX()_GMP_PCS_MISC()_CTL. */
        uint64_t samp_pt               : 7;  /**< [  6:  0](R/W) Byte number in elongated frames for 10/100 Mb/s operation for data sampling on RX side in
                                                                 PCS. Recommended values are 0x5 for 100 Mb/s operation and 0x32 for 10 Mb/s operation.

                                                                 For 10 Mb/s operation, this field should be set to a value less than 99 and greater than
                                                                 0.
                                                                 If set out of this range, a value of 50 is used for actual sampling internally without
                                                                 affecting the CSR field.

                                                                 For 100 Mb/s operation this field should be set to a value less than 9 and greater than 0.
                                                                 If set out of this range, a value of 5 is used for actual sampling internally without
                                                                 affecting the CSR field. */
#else /* Word 0 - Little Endian */
        uint64_t samp_pt               : 7;  /**< [  6:  0](R/W) Byte number in elongated frames for 10/100 Mb/s operation for data sampling on RX side in
                                                                 PCS. Recommended values are 0x5 for 100 Mb/s operation and 0x32 for 10 Mb/s operation.

                                                                 For 10 Mb/s operation, this field should be set to a value less than 99 and greater than
                                                                 0.
                                                                 If set out of this range, a value of 50 is used for actual sampling internally without
                                                                 affecting the CSR field.

                                                                 For 100 Mb/s operation this field should be set to a value less than 9 and greater than 0.
                                                                 If set out of this range, a value of 5 is used for actual sampling internally without
                                                                 affecting the CSR field. */
        uint64_t an_ovrd               : 1;  /**< [  7:  7](R/W) Autonegotiation results override:
                                                                 0 = Disable.
                                                                 1 = Enable override. Autonegotiation is allowed to happen but the results are ignored
                                                                 when this bit is set.  Duplex and Link speed values are set from CGX()_GMP_PCS_MISC()_CTL. */
        uint64_t mode                  : 1;  /**< [  8:  8](R/W) Mode bit.

                                                                 _ 0 = SGMII mode is selected and the following note applies.
                                                                 The SGMII AN advertisement register (CGX()_GMP_PCS_SGM()_AN_ADV) is sent during
                                                                 autonegotiation if CGX()_GMP_PCS_MISC()_CTL[MAC_PHY] = 1 (PHY mode). If [MAC_PHY]
                                                                 = 0 (MAC mode), the tx_Config_Reg<14> becomes ACK bit and <0> is always 1. All other bits
                                                                 in tx_Config_Reg sent are 0. The PHY dictates the autonegotiation results.

                                                                 _ 1 = 1000Base-X mode is selected. Autonegotiation follows IEEE 802.3 clause 37. */
        uint64_t mac_phy               : 1;  /**< [  9:  9](R/W) MAC/PHY.
                                                                 0 = MAC.
                                                                 1 = PHY decides the tx_Config_Reg value to be sent during autonegotiation. */
        uint64_t loopbck2              : 1;  /**< [ 10: 10](R/W) Sets external loopback mode to return RX data back out via the TX data path. 0 = No
                                                                 loopback, 1 = Loopback.
                                                                 LOOPBCK1 and LOOPBCK2 modes may not be supported simultaneously. */
        uint64_t gmxeno                : 1;  /**< [ 11: 11](R/W) GMI enable override. When set, forces GMI to appear disabled. The enable/disable status of
                                                                 GMI is checked only at SOP of every packet. */
        uint64_t sgmii                 : 1;  /**< [ 12: 12](RO/H) SGMII mode.
                                                                 0 = other mode selected.
                                                                 1 = SGMII or 1000BASE-X mode selected.

                                                                 See GSER()_LANE_MODE[LMODE]. */
        uint64_t disp_en               : 1;  /**< [ 13: 13](R/W) Disparity check enable.  When LMAC_TYPE=QSGMII the running disparity check should be
                                                                 disabled
                                                                 to
                                                                 prevent propogation across ports.
                                                                 0 = disable disparity check
                                                                 1 = enable disparity checking

                                                                 See GSER()_LANE_MODE[LMODE]. */
        uint64_t reserved_14_15        : 2;
        uint64_t qsgmii_comma_wd       : 16; /**< [ 31: 16](R/W) QSGMII comma watchdog byte counter. This counter is used in QSGMII mode and
                                                                 counts incoming bytes to ensure state transitions in the PCS receive side state
                                                                 machine when disparity enable is turned off and bad code groups and commas are
                                                                 not communicated from the code group processor after code group lock. */
        uint64_t qsgmii_comma_wd_en    : 1;  /**< [ 32: 32](R/W) QSGMII comma watchdog byte counter enable. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_miscx_ctl_s cn; */
} bdk_cgxx_gmp_pcs_miscx_ctl_t;

static inline uint64_t BDK_CGXX_GMP_PCS_MISCX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_MISCX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030078ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_MISCX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_MISCX_CTL(a,b) bdk_cgxx_gmp_pcs_miscx_ctl_t
#define bustype_BDK_CGXX_GMP_PCS_MISCX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_MISCX_CTL(a,b) "CGXX_GMP_PCS_MISCX_CTL"
#define device_bar_BDK_CGXX_GMP_PCS_MISCX_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_MISCX_CTL(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_MISCX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_mr#_control
 *
 * CGX GMP PCS Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_mrx_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t reset                 : 1;  /**< [ 15: 15](R/W/H) Set to reset.
                                                                 0 = Normal operation.
                                                                 1 = Software PCS reset.

                                                                 The bit returns to 0 after PCS has been reset. Takes 32 coprocessor-clock cycles to reset
                                                                 PCS.   This bit, when set, also drains the tx gmi fifo and can be used as a fifo draining
                                                                 mechanism for both SerDes reset conditions and for XCV reset conditions. */
        uint64_t loopbck1              : 1;  /**< [ 14: 14](R/W) Enable loopback:
                                                                   0 = Normal operation.
                                                                   1 = Internal loopback mode.

                                                                 The loopback mode returns loopback TX data from GMII TX back to GMII RX interface. The
                                                                 loopback happens in the PCS module. Autonegotiation is disabled even if [AN_EN] is set
                                                                 during loopback. */
        uint64_t spdlsb                : 1;  /**< [ 13: 13](R/W) Least-significant bit of the link-speed field, i.e. SPD<0>. Refer to SPDMSB. */
        uint64_t an_en                 : 1;  /**< [ 12: 12](R/W) Autonegotiation enable. */
        uint64_t pwr_dn                : 1;  /**< [ 11: 11](R/W) Power down:
                                                                   0 = Normal operation.
                                                                   1 = Power down (hardware reset). */
        uint64_t reserved_10           : 1;
        uint64_t rst_an                : 1;  /**< [  9:  9](R/W/H) Reset autonegotiation. When set, if [AN_EN] = 1 and
                                                                 CGX()_GMP_PCS_MR()_STATUS[AN_ABIL] = 1, autonegotiation begins. Otherwise,
                                                                 software write requests are ignored and this bit remains at 0. This bit clears itself to
                                                                 0, when autonegotiation starts. */
        uint64_t dup                   : 1;  /**< [  8:  8](R/W) Duplex mode:
                                                                   0 = half duplex; effective only if autonegotiation is disabled.
                                                                   1 = full duplex.

                                                                 If CGX()_GMP_PCS_MR()_STATUS <15:9> and
                                                                 CGX()_GMP_PCS_AN()_ADV<15:12> allow only one duplex mode, this bit corresponds to
                                                                 that value and any attempts to write are ignored. */
        uint64_t coltst                : 1;  /**< [  7:  7](R/W) Enable COL signal test.
                                                                 During COL test, the COL signal reflects the GMII TX_EN signal with less than 16BT delay. */
        uint64_t spdmsb                : 1;  /**< [  6:  6](R/W) Link speed most-significant bit, i.e SPD<1>; effective only if autonegotiation is
                                                                 disabled.

                                                                 <pre>
                                                                 [SPDMSB]   [SPDLSB]   Link Speed
                                                                  0          0         10 Mb/s
                                                                  0          1         100 Mb/s
                                                                  1          0         1000 Mb/s
                                                                  1          1         reserved
                                                                 </pre> */
        uint64_t uni                   : 1;  /**< [  5:  5](R/W) Unidirectional (Std 802.3-2005, Clause 66.2). When set to 1, this bit overrides [AN_EN]
                                                                 and
                                                                 disables the autonegotiation variable mr_an_enable. Used in both 1000BASE-X and
                                                                 SGMII/QSGMII
                                                                 modes. */
        uint64_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_4          : 5;
        uint64_t uni                   : 1;  /**< [  5:  5](R/W) Unidirectional (Std 802.3-2005, Clause 66.2). When set to 1, this bit overrides [AN_EN]
                                                                 and
                                                                 disables the autonegotiation variable mr_an_enable. Used in both 1000BASE-X and
                                                                 SGMII/QSGMII
                                                                 modes. */
        uint64_t spdmsb                : 1;  /**< [  6:  6](R/W) Link speed most-significant bit, i.e SPD<1>; effective only if autonegotiation is
                                                                 disabled.

                                                                 <pre>
                                                                 [SPDMSB]   [SPDLSB]   Link Speed
                                                                  0          0         10 Mb/s
                                                                  0          1         100 Mb/s
                                                                  1          0         1000 Mb/s
                                                                  1          1         reserved
                                                                 </pre> */
        uint64_t coltst                : 1;  /**< [  7:  7](R/W) Enable COL signal test.
                                                                 During COL test, the COL signal reflects the GMII TX_EN signal with less than 16BT delay. */
        uint64_t dup                   : 1;  /**< [  8:  8](R/W) Duplex mode:
                                                                   0 = half duplex; effective only if autonegotiation is disabled.
                                                                   1 = full duplex.

                                                                 If CGX()_GMP_PCS_MR()_STATUS <15:9> and
                                                                 CGX()_GMP_PCS_AN()_ADV<15:12> allow only one duplex mode, this bit corresponds to
                                                                 that value and any attempts to write are ignored. */
        uint64_t rst_an                : 1;  /**< [  9:  9](R/W/H) Reset autonegotiation. When set, if [AN_EN] = 1 and
                                                                 CGX()_GMP_PCS_MR()_STATUS[AN_ABIL] = 1, autonegotiation begins. Otherwise,
                                                                 software write requests are ignored and this bit remains at 0. This bit clears itself to
                                                                 0, when autonegotiation starts. */
        uint64_t reserved_10           : 1;
        uint64_t pwr_dn                : 1;  /**< [ 11: 11](R/W) Power down:
                                                                   0 = Normal operation.
                                                                   1 = Power down (hardware reset). */
        uint64_t an_en                 : 1;  /**< [ 12: 12](R/W) Autonegotiation enable. */
        uint64_t spdlsb                : 1;  /**< [ 13: 13](R/W) Least-significant bit of the link-speed field, i.e. SPD<0>. Refer to SPDMSB. */
        uint64_t loopbck1              : 1;  /**< [ 14: 14](R/W) Enable loopback:
                                                                   0 = Normal operation.
                                                                   1 = Internal loopback mode.

                                                                 The loopback mode returns loopback TX data from GMII TX back to GMII RX interface. The
                                                                 loopback happens in the PCS module. Autonegotiation is disabled even if [AN_EN] is set
                                                                 during loopback. */
        uint64_t reset                 : 1;  /**< [ 15: 15](R/W/H) Set to reset.
                                                                 0 = Normal operation.
                                                                 1 = Software PCS reset.

                                                                 The bit returns to 0 after PCS has been reset. Takes 32 coprocessor-clock cycles to reset
                                                                 PCS.   This bit, when set, also drains the tx gmi fifo and can be used as a fifo draining
                                                                 mechanism for both SerDes reset conditions and for XCV reset conditions. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_mrx_control_s cn; */
} bdk_cgxx_gmp_pcs_mrx_control_t;

static inline uint64_t BDK_CGXX_GMP_PCS_MRX_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_MRX_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030000ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_MRX_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_MRX_CONTROL(a,b) bdk_cgxx_gmp_pcs_mrx_control_t
#define bustype_BDK_CGXX_GMP_PCS_MRX_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_MRX_CONTROL(a,b) "CGXX_GMP_PCS_MRX_CONTROL"
#define device_bar_BDK_CGXX_GMP_PCS_MRX_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_MRX_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_MRX_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_mr#_status
 *
 * CGX GMP PCS Status Registers
 * Bits <15:9> in this register indicate the ability to operate when
 * CGX()_GMP_PCS_MISC()_CTL[MAC_PHY] is set to MAC mode. Bits <15:9> are always read as
 * 0, indicating that the chip cannot operate in the corresponding modes. The field [RM_FLT] is a
 * 'don't care' when the selected mode is SGMII/QSGMII.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_mrx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t hun_t4                : 1;  /**< [ 15: 15](RO/H) Indicates 100BASE-T4 capable. */
        uint64_t hun_xfd               : 1;  /**< [ 14: 14](RO/H) Indicates 100BASE-X full duplex. */
        uint64_t hun_xhd               : 1;  /**< [ 13: 13](RO/H) Indicates 100BASE-X half duplex. */
        uint64_t ten_fd                : 1;  /**< [ 12: 12](RO/H) Indicates 10Mb/s full duplex. */
        uint64_t ten_hd                : 1;  /**< [ 11: 11](RO/H) Indicates 10Mb/s half duplex. */
        uint64_t hun_t2fd              : 1;  /**< [ 10: 10](RO/H) Indicates 100BASE-T2 full duplex. */
        uint64_t hun_t2hd              : 1;  /**< [  9:  9](RO/H) Indicates 100BASE-T2 half duplex. */
        uint64_t ext_st                : 1;  /**< [  8:  8](RO/H) Extended status information. When set to 1, indicates that additional status data is
                                                                 available in CGX()_GMP_PCS_AN()_EXT_ST. */
        uint64_t reserved_7            : 1;
        uint64_t prb_sup               : 1;  /**< [  6:  6](RO/H) Preamble not needed.
                                                                 0 = Cannot accept frames without preamble bytes.
                                                                 1 = Can work without preamble bytes at the beginning of frames. */
        uint64_t an_cpt                : 1;  /**< [  5:  5](RO/H) Indicates autonegotiation is complete; the contents of the
                                                                 CGX()_GMP_PCS_AN()_RESULTS are valid. */
        uint64_t rm_flt                : 1;  /**< [  4:  4](RO/H) Indicates remote fault condition occurred. This bit implements a latching-high behavior.
                                                                 It is cleared when software reads this register or when
                                                                 CGX()_GMP_PCS_MR()_CONTROL[RESET] is asserted.
                                                                 See CGX()_GMP_PCS_AN()_ADV[REM_FLT] for fault conditions. */
        uint64_t an_abil               : 1;  /**< [  3:  3](RO/H) Indicates autonegotiation capable. */
        uint64_t lnk_st                : 1;  /**< [  2:  2](RO/H) Link state:
                                                                   0 = link down.
                                                                   1 = link up.

                                                                 Set during autonegotiation process. Set whenever XMIT = DATA. Latching-low behavior when
                                                                 link goes down. Link down value of the bit stays low until software reads the register. */
        uint64_t reserved_1            : 1;
        uint64_t extnd                 : 1;  /**< [  0:  0](RO/H) This field is always 0, extended capability registers not present. */
#else /* Word 0 - Little Endian */
        uint64_t extnd                 : 1;  /**< [  0:  0](RO/H) This field is always 0, extended capability registers not present. */
        uint64_t reserved_1            : 1;
        uint64_t lnk_st                : 1;  /**< [  2:  2](RO/H) Link state:
                                                                   0 = link down.
                                                                   1 = link up.

                                                                 Set during autonegotiation process. Set whenever XMIT = DATA. Latching-low behavior when
                                                                 link goes down. Link down value of the bit stays low until software reads the register. */
        uint64_t an_abil               : 1;  /**< [  3:  3](RO/H) Indicates autonegotiation capable. */
        uint64_t rm_flt                : 1;  /**< [  4:  4](RO/H) Indicates remote fault condition occurred. This bit implements a latching-high behavior.
                                                                 It is cleared when software reads this register or when
                                                                 CGX()_GMP_PCS_MR()_CONTROL[RESET] is asserted.
                                                                 See CGX()_GMP_PCS_AN()_ADV[REM_FLT] for fault conditions. */
        uint64_t an_cpt                : 1;  /**< [  5:  5](RO/H) Indicates autonegotiation is complete; the contents of the
                                                                 CGX()_GMP_PCS_AN()_RESULTS are valid. */
        uint64_t prb_sup               : 1;  /**< [  6:  6](RO/H) Preamble not needed.
                                                                 0 = Cannot accept frames without preamble bytes.
                                                                 1 = Can work without preamble bytes at the beginning of frames. */
        uint64_t reserved_7            : 1;
        uint64_t ext_st                : 1;  /**< [  8:  8](RO/H) Extended status information. When set to 1, indicates that additional status data is
                                                                 available in CGX()_GMP_PCS_AN()_EXT_ST. */
        uint64_t hun_t2hd              : 1;  /**< [  9:  9](RO/H) Indicates 100BASE-T2 half duplex. */
        uint64_t hun_t2fd              : 1;  /**< [ 10: 10](RO/H) Indicates 100BASE-T2 full duplex. */
        uint64_t ten_hd                : 1;  /**< [ 11: 11](RO/H) Indicates 10Mb/s half duplex. */
        uint64_t ten_fd                : 1;  /**< [ 12: 12](RO/H) Indicates 10Mb/s full duplex. */
        uint64_t hun_xhd               : 1;  /**< [ 13: 13](RO/H) Indicates 100BASE-X half duplex. */
        uint64_t hun_xfd               : 1;  /**< [ 14: 14](RO/H) Indicates 100BASE-X full duplex. */
        uint64_t hun_t4                : 1;  /**< [ 15: 15](RO/H) Indicates 100BASE-T4 capable. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_mrx_status_s cn; */
} bdk_cgxx_gmp_pcs_mrx_status_t;

static inline uint64_t BDK_CGXX_GMP_PCS_MRX_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_MRX_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030008ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_MRX_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_MRX_STATUS(a,b) bdk_cgxx_gmp_pcs_mrx_status_t
#define bustype_BDK_CGXX_GMP_PCS_MRX_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_MRX_STATUS(a,b) "CGXX_GMP_PCS_MRX_STATUS"
#define device_bar_BDK_CGXX_GMP_PCS_MRX_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_MRX_STATUS(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_MRX_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_rx#_states
 *
 * CGX GMP PCS RX State-Machines States Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_rxx_states_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t rx_bad                : 1;  /**< [ 15: 15](RO/H) Receive state machine is in an illegal state. */
        uint64_t rx_st                 : 5;  /**< [ 14: 10](RO/H) Receive state-machine state. */
        uint64_t sync_bad              : 1;  /**< [  9:  9](RO/H) Receive synchronization state machine is in an illegal state. */
        uint64_t sync                  : 4;  /**< [  8:  5](RO/H) Receive synchronization state-machine state. */
        uint64_t an_bad                : 1;  /**< [  4:  4](RO/H) Autonegotiation state machine is in an illegal state. */
        uint64_t an_st                 : 4;  /**< [  3:  0](RO/H) Autonegotiation state-machine state. */
#else /* Word 0 - Little Endian */
        uint64_t an_st                 : 4;  /**< [  3:  0](RO/H) Autonegotiation state-machine state. */
        uint64_t an_bad                : 1;  /**< [  4:  4](RO/H) Autonegotiation state machine is in an illegal state. */
        uint64_t sync                  : 4;  /**< [  8:  5](RO/H) Receive synchronization state-machine state. */
        uint64_t sync_bad              : 1;  /**< [  9:  9](RO/H) Receive synchronization state machine is in an illegal state. */
        uint64_t rx_st                 : 5;  /**< [ 14: 10](RO/H) Receive state-machine state. */
        uint64_t rx_bad                : 1;  /**< [ 15: 15](RO/H) Receive state machine is in an illegal state. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_rxx_states_s cn; */
} bdk_cgxx_gmp_pcs_rxx_states_t;

static inline uint64_t BDK_CGXX_GMP_PCS_RXX_STATES(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_RXX_STATES(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030058ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_RXX_STATES", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_RXX_STATES(a,b) bdk_cgxx_gmp_pcs_rxx_states_t
#define bustype_BDK_CGXX_GMP_PCS_RXX_STATES(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_RXX_STATES(a,b) "CGXX_GMP_PCS_RXX_STATES"
#define device_bar_BDK_CGXX_GMP_PCS_RXX_STATES(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_RXX_STATES(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_RXX_STATES(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_rx#_sync
 *
 * CGX GMP PCS Code Group Synchronization Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_rxx_sync_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t sync                  : 1;  /**< [  1:  1](RO/H) When set, code group synchronization achieved. */
        uint64_t bit_lock              : 1;  /**< [  0:  0](RO/H) When set, bit lock achieved. */
#else /* Word 0 - Little Endian */
        uint64_t bit_lock              : 1;  /**< [  0:  0](RO/H) When set, bit lock achieved. */
        uint64_t sync                  : 1;  /**< [  1:  1](RO/H) When set, code group synchronization achieved. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_rxx_sync_s cn; */
} bdk_cgxx_gmp_pcs_rxx_sync_t;

static inline uint64_t BDK_CGXX_GMP_PCS_RXX_SYNC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_RXX_SYNC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030050ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_RXX_SYNC", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_RXX_SYNC(a,b) bdk_cgxx_gmp_pcs_rxx_sync_t
#define bustype_BDK_CGXX_GMP_PCS_RXX_SYNC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_RXX_SYNC(a,b) "CGXX_GMP_PCS_RXX_SYNC"
#define device_bar_BDK_CGXX_GMP_PCS_RXX_SYNC(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_RXX_SYNC(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_RXX_SYNC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_sgm#_an_adv
 *
 * CGX GMP PCS SGMII Autonegotiation Advertisement Registers
 * This is the SGMII autonegotiation advertisement register (sent out as tx_Config_Reg<15:0> as
 * defined in IEEE 802.3 clause 37). This register is sent during autonegotiation if
 * CGX()_GMP_PCS_MISC()_CTL[MAC_PHY] is set (1 = PHY mode). If the bit is not set (0 =
 * MAC mode), then tx_Config_Reg<14> becomes ACK bit and tx_Config_Reg<0> is always 1. All other
 * bits in tx_Config_Reg sent will be 0. The PHY dictates the autonegotiation results.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_sgmx_an_adv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t link                  : 1;  /**< [ 15: 15](R/W) Link status: 1 = Link up. 0 = Link down. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Autonegotiation acknowledgement. */
        uint64_t reserved_13           : 1;
        uint64_t dup                   : 1;  /**< [ 12: 12](R/W) Duplex mode: 1 = full duplex, 0 = half duplex. */
        uint64_t speed                 : 2;  /**< [ 11: 10](R/W) Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t reserved_1_9          : 9;
        uint64_t one                   : 1;  /**< [  0:  0](RO/H) Always set to match tx_Config_Reg<0>. */
#else /* Word 0 - Little Endian */
        uint64_t one                   : 1;  /**< [  0:  0](RO/H) Always set to match tx_Config_Reg<0>. */
        uint64_t reserved_1_9          : 9;
        uint64_t speed                 : 2;  /**< [ 11: 10](R/W) Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t dup                   : 1;  /**< [ 12: 12](R/W) Duplex mode: 1 = full duplex, 0 = half duplex. */
        uint64_t reserved_13           : 1;
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Autonegotiation acknowledgement. */
        uint64_t link                  : 1;  /**< [ 15: 15](R/W) Link status: 1 = Link up. 0 = Link down. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_sgmx_an_adv_s cn; */
} bdk_cgxx_gmp_pcs_sgmx_an_adv_t;

static inline uint64_t BDK_CGXX_GMP_PCS_SGMX_AN_ADV(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_SGMX_AN_ADV(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030068ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_SGMX_AN_ADV", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_SGMX_AN_ADV(a,b) bdk_cgxx_gmp_pcs_sgmx_an_adv_t
#define bustype_BDK_CGXX_GMP_PCS_SGMX_AN_ADV(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_SGMX_AN_ADV(a,b) "CGXX_GMP_PCS_SGMX_AN_ADV"
#define device_bar_BDK_CGXX_GMP_PCS_SGMX_AN_ADV(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_SGMX_AN_ADV(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_SGMX_AN_ADV(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_sgm#_lp_adv
 *
 * CGX GMP PCS SGMII Link-Partner-Advertisement Registers
 * This is the SGMII link partner advertisement register (received as rx_Config_Reg<15:0> as
 * defined in IEEE 802.3 clause 37).
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_sgmx_lp_adv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t link                  : 1;  /**< [ 15: 15](RO/H) Link status: 1 = Link up. 0 = Link down. */
        uint64_t reserved_13_14        : 2;
        uint64_t dup                   : 1;  /**< [ 12: 12](RO/H) Duplex mode: 1 = Full duplex, 0 = Half duplex. */
        uint64_t speed                 : 2;  /**< [ 11: 10](RO/H) Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t reserved_1_9          : 9;
        uint64_t one                   : 1;  /**< [  0:  0](RO/H) Always set to match tx_Config_Reg<0> */
#else /* Word 0 - Little Endian */
        uint64_t one                   : 1;  /**< [  0:  0](RO/H) Always set to match tx_Config_Reg<0> */
        uint64_t reserved_1_9          : 9;
        uint64_t speed                 : 2;  /**< [ 11: 10](RO/H) Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t dup                   : 1;  /**< [ 12: 12](RO/H) Duplex mode: 1 = Full duplex, 0 = Half duplex. */
        uint64_t reserved_13_14        : 2;
        uint64_t link                  : 1;  /**< [ 15: 15](RO/H) Link status: 1 = Link up. 0 = Link down. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    struct bdk_cgxx_gmp_pcs_sgmx_lp_adv_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t link                  : 1;  /**< [ 15: 15](RO/H) Link status: 1 = Link up. 0 = Link down. */
        uint64_t reserved_14           : 1;
        uint64_t reserved_13           : 1;
        uint64_t dup                   : 1;  /**< [ 12: 12](RO/H) Duplex mode: 1 = Full duplex, 0 = Half duplex. */
        uint64_t speed                 : 2;  /**< [ 11: 10](RO/H) Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t reserved_1_9          : 9;
        uint64_t one                   : 1;  /**< [  0:  0](RO/H) Always set to match tx_Config_Reg<0> */
#else /* Word 0 - Little Endian */
        uint64_t one                   : 1;  /**< [  0:  0](RO/H) Always set to match tx_Config_Reg<0> */
        uint64_t reserved_1_9          : 9;
        uint64_t speed                 : 2;  /**< [ 11: 10](RO/H) Link speed:
                                                                 0x0 = 10 Mb/s.
                                                                 0x1 = 100 Mb/s.
                                                                 0x2 = 1000 Mb/s.
                                                                 0x3 = Reserved. */
        uint64_t dup                   : 1;  /**< [ 12: 12](RO/H) Duplex mode: 1 = Full duplex, 0 = Half duplex. */
        uint64_t reserved_13           : 1;
        uint64_t reserved_14           : 1;
        uint64_t link                  : 1;  /**< [ 15: 15](RO/H) Link status: 1 = Link up. 0 = Link down. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } cn;
} bdk_cgxx_gmp_pcs_sgmx_lp_adv_t;

static inline uint64_t BDK_CGXX_GMP_PCS_SGMX_LP_ADV(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_SGMX_LP_ADV(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030070ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_SGMX_LP_ADV", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_SGMX_LP_ADV(a,b) bdk_cgxx_gmp_pcs_sgmx_lp_adv_t
#define bustype_BDK_CGXX_GMP_PCS_SGMX_LP_ADV(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_SGMX_LP_ADV(a,b) "CGXX_GMP_PCS_SGMX_LP_ADV"
#define device_bar_BDK_CGXX_GMP_PCS_SGMX_LP_ADV(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_SGMX_LP_ADV(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_SGMX_LP_ADV(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_tx#_states
 *
 * CGX GMP PCS TX State-Machines States Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_txx_states_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_7_63         : 57;
        uint64_t xmit                  : 2;  /**< [  6:  5](RO/H) 0x0 = Undefined.
                                                                 0x1 = Config.
                                                                 0x2 = Idle.
                                                                 0x3 = Data. */
        uint64_t tx_bad                : 1;  /**< [  4:  4](RO/H) Transmit state machine in an illegal state. */
        uint64_t ord_st                : 4;  /**< [  3:  0](RO/H) Transmit ordered set state-machine state. */
#else /* Word 0 - Little Endian */
        uint64_t ord_st                : 4;  /**< [  3:  0](RO/H) Transmit ordered set state-machine state. */
        uint64_t tx_bad                : 1;  /**< [  4:  4](RO/H) Transmit state machine in an illegal state. */
        uint64_t xmit                  : 2;  /**< [  6:  5](RO/H) 0x0 = Undefined.
                                                                 0x1 = Config.
                                                                 0x2 = Idle.
                                                                 0x3 = Data. */
        uint64_t reserved_7_63         : 57;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_txx_states_s cn; */
} bdk_cgxx_gmp_pcs_txx_states_t;

static inline uint64_t BDK_CGXX_GMP_PCS_TXX_STATES(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_TXX_STATES(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030060ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_TXX_STATES", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_TXX_STATES(a,b) bdk_cgxx_gmp_pcs_txx_states_t
#define bustype_BDK_CGXX_GMP_PCS_TXX_STATES(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_TXX_STATES(a,b) "CGXX_GMP_PCS_TXX_STATES"
#define device_bar_BDK_CGXX_GMP_PCS_TXX_STATES(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_TXX_STATES(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_TXX_STATES(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_gmp_pcs_tx_rx#_polarity
 *
 * CGX GMP PCS TX/RX Polarity Registers
 * CGX()_GMP_PCS_TX_RX()_POLARITY[AUTORXPL] shows correct polarity needed on the link
 * receive path after code group synchronization is achieved.  When LMAC_TYPE=QSGMII, only lane 0
 * polarity data and settings are relevant and settings for lanes 1, 2 and 3 are unused.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_gmp_pcs_tx_rxx_polarity_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t rxovrd                : 1;  /**< [  3:  3](R/W) RX polarity override.
                                                                 0 = AUTORXPL determines polarity.
                                                                 1 = [RXPLRT] determines polarity. */
        uint64_t autorxpl              : 1;  /**< [  2:  2](RO/H) Auto RX polarity detected:
                                                                 0 = Normal polarity.
                                                                 1 = Inverted polarity.

                                                                 This bit always represents the correct RX polarity setting needed for successful RX path
                                                                 operation, once a successful code group sync is obtained. */
        uint64_t rxplrt                : 1;  /**< [  1:  1](R/W) RX polarity: 0 = Normal polarity, 1 = Inverted polarity. */
        uint64_t txplrt                : 1;  /**< [  0:  0](R/W) TX polarity: 0 = Normal polarity, 1 = Inverted polarity. */
#else /* Word 0 - Little Endian */
        uint64_t txplrt                : 1;  /**< [  0:  0](R/W) TX polarity: 0 = Normal polarity, 1 = Inverted polarity. */
        uint64_t rxplrt                : 1;  /**< [  1:  1](R/W) RX polarity: 0 = Normal polarity, 1 = Inverted polarity. */
        uint64_t autorxpl              : 1;  /**< [  2:  2](RO/H) Auto RX polarity detected:
                                                                 0 = Normal polarity.
                                                                 1 = Inverted polarity.

                                                                 This bit always represents the correct RX polarity setting needed for successful RX path
                                                                 operation, once a successful code group sync is obtained. */
        uint64_t rxovrd                : 1;  /**< [  3:  3](R/W) RX polarity override.
                                                                 0 = AUTORXPL determines polarity.
                                                                 1 = [RXPLRT] determines polarity. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_gmp_pcs_tx_rxx_polarity_s cn; */
} bdk_cgxx_gmp_pcs_tx_rxx_polarity_t;

static inline uint64_t BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8030048ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_GMP_PCS_TX_RXX_POLARITY", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(a,b) bdk_cgxx_gmp_pcs_tx_rxx_polarity_t
#define bustype_BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(a,b) "CGXX_GMP_PCS_TX_RXX_POLARITY"
#define device_bar_BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(a,b) (a)
#define arguments_BDK_CGXX_GMP_PCS_TX_RXX_POLARITY(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_msix_pba#
 *
 * CGX MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the CGX_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CGX()_MSIX_VEC()_CTL, enumerated by CGX_INT_VEC_E.
                                                                 Bits that have no associated CGX_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated CGX()_MSIX_VEC()_CTL, enumerated by CGX_INT_VEC_E.
                                                                 Bits that have no associated CGX_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_msix_pbax_s cn; */
} bdk_cgxx_msix_pbax_t;

static inline uint64_t BDK_CGXX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b==0)))
        return 0x87e0e84f0000ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("CGXX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_MSIX_PBAX(a,b) bdk_cgxx_msix_pbax_t
#define bustype_BDK_CGXX_MSIX_PBAX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_MSIX_PBAX(a,b) "CGXX_MSIX_PBAX"
#define device_bar_BDK_CGXX_MSIX_PBAX(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_CGXX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_CGXX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_msix_vec#_addr
 *
 * CGX MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the CGX_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's CGX()_MSIX_VEC()_ADDR, CGX()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CGX()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_CGX()_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or nonsecure states.
                                                                 1 = This vector's CGX()_MSIX_VEC()_ADDR, CGX()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of CGX()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the nonsecure world.

                                                                 If PCCPF_CGX()_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC])
                                                                 is set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) IOVA to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_msix_vecx_addr_s cn; */
} bdk_cgxx_msix_vecx_addr_t;

static inline uint64_t BDK_CGXX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=29)))
        return 0x87e0e8400000ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x1f);
    __bdk_csr_fatal("CGXX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_MSIX_VECX_ADDR(a,b) bdk_cgxx_msix_vecx_addr_t
#define bustype_BDK_CGXX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_MSIX_VECX_ADDR(a,b) "CGXX_MSIX_VECX_ADDR"
#define device_bar_BDK_CGXX_MSIX_VECX_ADDR(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_CGXX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_CGXX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_msix_vec#_ctl
 *
 * CGX MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the CGX_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_msix_vecx_ctl_s cn; */
} bdk_cgxx_msix_vecx_ctl_t;

static inline uint64_t BDK_CGXX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=29)))
        return 0x87e0e8400008ll + 0x1000000ll * ((a) & 0x3) + 0x10ll * ((b) & 0x1f);
    __bdk_csr_fatal("CGXX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_MSIX_VECX_CTL(a,b) bdk_cgxx_msix_vecx_ctl_t
#define bustype_BDK_CGXX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_MSIX_VECX_CTL(a,b) "CGXX_MSIX_VECX_CTL"
#define device_bar_BDK_CGXX_MSIX_VECX_CTL(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_CGXX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_CGXX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_cbfc_ctl
 *
 * CGX SMU PFC Control Registers
 * Internal:
 * INTERNAL: XOFF for a specific class/channel <i> is XOFF<i> = ([PHYS_EN]<i> & cmr_rx_phys_bp) |
 * ([LOGL_EN]<i> & cmr_rx_logl_xoff<i>).
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_cbfc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t phys_en               : 16; /**< [ 63: 48](R/W) Physical backpressure enable. Determines which classes/channels in the class enable vector
                                                                 field of a transmitted PFC packet can be asserted due to RX physical backpressure. */
        uint64_t logl_en               : 16; /**< [ 47: 32](R/W) Logical backpressure enable. Determines which classes/channels in the class enable vector
                                                                 field of a transmitted PFC packet can be asserted due to RX logical backpressure. */
        uint64_t reserved_4_31         : 28;
        uint64_t bck_en                : 1;  /**< [  3:  3](R/W) Forward PFC information to the backpressure block. */
        uint64_t drp_en                : 1;  /**< [  2:  2](R/W) Drop-control enable. When set, drop PFC frames. */
        uint64_t tx_en                 : 1;  /**< [  1:  1](R/W) Transmit enable. When set, allow for PFC packets. Must be clear in HiGig2 mode
                                                                 i.e. when CGX()_SMU()_TX_CTL[HG_EN] = 1 and CGX()_SMU()_RX_UDD_SKP[LEN] =
                                                                 16. */
        uint64_t rx_en                 : 1;  /**< [  0:  0](R/W) Receive enable. When set, allow for PFC packets. Must be clear in HiGig2 mode
                                                                 i.e. when CGX()_SMU()_TX_CTL[HG_EN] = 1 and CGX()_SMU()_RX_UDD_SKP[LEN] =
                                                                 16. */
#else /* Word 0 - Little Endian */
        uint64_t rx_en                 : 1;  /**< [  0:  0](R/W) Receive enable. When set, allow for PFC packets. Must be clear in HiGig2 mode
                                                                 i.e. when CGX()_SMU()_TX_CTL[HG_EN] = 1 and CGX()_SMU()_RX_UDD_SKP[LEN] =
                                                                 16. */
        uint64_t tx_en                 : 1;  /**< [  1:  1](R/W) Transmit enable. When set, allow for PFC packets. Must be clear in HiGig2 mode
                                                                 i.e. when CGX()_SMU()_TX_CTL[HG_EN] = 1 and CGX()_SMU()_RX_UDD_SKP[LEN] =
                                                                 16. */
        uint64_t drp_en                : 1;  /**< [  2:  2](R/W) Drop-control enable. When set, drop PFC frames. */
        uint64_t bck_en                : 1;  /**< [  3:  3](R/W) Forward PFC information to the backpressure block. */
        uint64_t reserved_4_31         : 28;
        uint64_t logl_en               : 16; /**< [ 47: 32](R/W) Logical backpressure enable. Determines which classes/channels in the class enable vector
                                                                 field of a transmitted PFC packet can be asserted due to RX logical backpressure. */
        uint64_t phys_en               : 16; /**< [ 63: 48](R/W) Physical backpressure enable. Determines which classes/channels in the class enable vector
                                                                 field of a transmitted PFC packet can be asserted due to RX physical backpressure. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_cbfc_ctl_s cn; */
} bdk_cgxx_smux_cbfc_ctl_t;

static inline uint64_t BDK_CGXX_SMUX_CBFC_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_CBFC_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020218ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_CBFC_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_CBFC_CTL(a,b) bdk_cgxx_smux_cbfc_ctl_t
#define bustype_BDK_CGXX_SMUX_CBFC_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_CBFC_CTL(a,b) "CGXX_SMUX_CBFC_CTL"
#define device_bar_BDK_CGXX_SMUX_CBFC_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_CBFC_CTL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_CBFC_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_ctrl
 *
 * CGX SMU Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_ctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t tx_idle               : 1;  /**< [  1:  1](RO/H) TX machine is idle. This indication pertains to the framer FSM and ignores the effects on
                                                                 the data-path controls or values which occur when CGX()_SMU()_TX_CTL[LS_BYP] is
                                                                 set. */
        uint64_t rx_idle               : 1;  /**< [  0:  0](RO/H) RX machine is idle. */
#else /* Word 0 - Little Endian */
        uint64_t rx_idle               : 1;  /**< [  0:  0](RO/H) RX machine is idle. */
        uint64_t tx_idle               : 1;  /**< [  1:  1](RO/H) TX machine is idle. This indication pertains to the framer FSM and ignores the effects on
                                                                 the data-path controls or values which occur when CGX()_SMU()_TX_CTL[LS_BYP] is
                                                                 set. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_ctrl_s cn; */
} bdk_cgxx_smux_ctrl_t;

static inline uint64_t BDK_CGXX_SMUX_CTRL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_CTRL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020200ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_CTRL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_CTRL(a,b) bdk_cgxx_smux_ctrl_t
#define bustype_BDK_CGXX_SMUX_CTRL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_CTRL(a,b) "CGXX_SMUX_CTRL"
#define device_bar_BDK_CGXX_SMUX_CTRL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_CTRL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_CTRL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_ext_loopback
 *
 * CGX SMU External Loopback Registers
 * In loopback mode, the IFG1+IFG2 of local and remote parties must match exactly; otherwise one
 * of the two sides' loopback FIFO will overrun: CGX()_SMU()_TX_INT[LB_OVRFLW].
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_ext_loopback_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t en                    : 1;  /**< [  4:  4](R/W) Loopback enable. Puts the packet interface in external loopback mode where the RX lines
                                                                 are reflected on the TX lines. */
        uint64_t thresh                : 4;  /**< [  3:  0](R/W) Threshold on the TX FIFO. Software must only write the typical value. Any other value
                                                                 causes loopback mode not to function correctly. */
#else /* Word 0 - Little Endian */
        uint64_t thresh                : 4;  /**< [  3:  0](R/W) Threshold on the TX FIFO. Software must only write the typical value. Any other value
                                                                 causes loopback mode not to function correctly. */
        uint64_t en                    : 1;  /**< [  4:  4](R/W) Loopback enable. Puts the packet interface in external loopback mode where the RX lines
                                                                 are reflected on the TX lines. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_ext_loopback_s cn; */
} bdk_cgxx_smux_ext_loopback_t;

static inline uint64_t BDK_CGXX_SMUX_EXT_LOOPBACK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_EXT_LOOPBACK(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020208ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_EXT_LOOPBACK", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_EXT_LOOPBACK(a,b) bdk_cgxx_smux_ext_loopback_t
#define bustype_BDK_CGXX_SMUX_EXT_LOOPBACK(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_EXT_LOOPBACK(a,b) "CGXX_SMUX_EXT_LOOPBACK"
#define device_bar_BDK_CGXX_SMUX_EXT_LOOPBACK(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_EXT_LOOPBACK(a,b) (a)
#define arguments_BDK_CGXX_SMUX_EXT_LOOPBACK(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_hg2_control
 *
 * CGX SMU HiGig2 Control Registers
 * HiGig2 TX- and RX-enable are normally set together for HiGig2 messaging. Setting just the TX
 * or RX bit results in only the HG2 message transmit or receive capability.
 *
 * Setting [PHYS_EN] and [LOGL_EN] to 1 allows link PAUSE or backpressure to PKO as per the
 * received HiGig2 message. Setting these fields to 0 disables link PAUSE and backpressure to PKO
 * in response to received messages.
 *
 * CGX()_SMU()_TX_CTL[HG_EN] must be set (to enable HiGig) whenever either [HG2TX_EN] or
 * [HG2RX_EN] are set. CGX()_SMU()_RX_UDD_SKP[LEN] must be set to 16 (to select HiGig2)
 * whenever either [HG2TX_EN] or [HG2RX_EN] are set.
 *
 * CGX()_CMR_RX_OVR_BP[EN]<0> must be set and CGX()_CMR_RX_OVR_BP[BP]<0> must be cleared
 * to 0 (to forcibly disable hardware-automatic 802.3 PAUSE packet generation) with the HiGig2
 * Protocol when [HG2TX_EN] = 0. (The HiGig2 protocol is indicated
 * by CGX()_SMU()_TX_CTL[HG_EN] = 1 and CGX()_SMU()_RX_UDD_SKP[LEN]=16.) Hardware
 * can only autogenerate backpressure via HiGig2 messages (optionally, when [HG2TX_EN] = 1) with
 * the HiGig2 protocol.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_hg2_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_19_63        : 45;
        uint64_t hg2tx_en              : 1;  /**< [ 18: 18](R/W) Enable transmission of HG2 physical and logical messages. When set, also disables hardware
                                                                 autogenerated 802.3 PAUSE and PFC frames. (CNXXXX cannot generate proper 802.3 or
                                                                 PFC frames in HiGig2 mode.) */
        uint64_t hg2rx_en              : 1;  /**< [ 17: 17](R/W) Enable extraction and processing of HG2 message packet from RX flow. Physical and logical
                                                                 PAUSE information is used to PAUSE physical-link, backpressure PKO. This field must be set
                                                                 when HiGig2 messages are present in the receive stream. This bit is also forwarded to CMR
                                                                 so it can generate the required deferring signals to SMU TX and backpressure signals to
                                                                 PKO. */
        uint64_t phys_en               : 1;  /**< [ 16: 16](R/W) Physical-link backpressure enable for received physical HiGig2 messages. This bit enables
                                                                 the SMU TX to CMR HG2 deferring counter to be set every time SMU RX receives and filters
                                                                 out a valid physical HG2 message. */
        uint64_t logl_en               : 16; /**< [ 15:  0](R/W) 16-bit logical-link backpressure enables for received HiGig2 messages or PFC packets. */
#else /* Word 0 - Little Endian */
        uint64_t logl_en               : 16; /**< [ 15:  0](R/W) 16-bit logical-link backpressure enables for received HiGig2 messages or PFC packets. */
        uint64_t phys_en               : 1;  /**< [ 16: 16](R/W) Physical-link backpressure enable for received physical HiGig2 messages. This bit enables
                                                                 the SMU TX to CMR HG2 deferring counter to be set every time SMU RX receives and filters
                                                                 out a valid physical HG2 message. */
        uint64_t hg2rx_en              : 1;  /**< [ 17: 17](R/W) Enable extraction and processing of HG2 message packet from RX flow. Physical and logical
                                                                 PAUSE information is used to PAUSE physical-link, backpressure PKO. This field must be set
                                                                 when HiGig2 messages are present in the receive stream. This bit is also forwarded to CMR
                                                                 so it can generate the required deferring signals to SMU TX and backpressure signals to
                                                                 PKO. */
        uint64_t hg2tx_en              : 1;  /**< [ 18: 18](R/W) Enable transmission of HG2 physical and logical messages. When set, also disables hardware
                                                                 autogenerated 802.3 PAUSE and PFC frames. (CNXXXX cannot generate proper 802.3 or
                                                                 PFC frames in HiGig2 mode.) */
        uint64_t reserved_19_63        : 45;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_hg2_control_s cn; */
} bdk_cgxx_smux_hg2_control_t;

static inline uint64_t BDK_CGXX_SMUX_HG2_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_HG2_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020210ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_HG2_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_HG2_CONTROL(a,b) bdk_cgxx_smux_hg2_control_t
#define bustype_BDK_CGXX_SMUX_HG2_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_HG2_CONTROL(a,b) "CGXX_SMUX_HG2_CONTROL"
#define device_bar_BDK_CGXX_SMUX_HG2_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_HG2_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_HG2_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_bad_col_hi
 *
 * CGX SMU RX Bad Column High Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_bad_col_hi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_17_63        : 47;
        uint64_t val                   : 1;  /**< [ 16: 16](R/W1C/H) Set when CGX()_SMU()_RX_INT[PCTERR] is set. */
        uint64_t state                 : 8;  /**< [ 15:  8](RO/H) When CGX()_SMU()_RX_INT[PCTERR] is set, contains the receive state at the time of
                                                                 the error. */
        uint64_t lane_rxc              : 8;  /**< [  7:  0](RO/H) When CGX()_SMU()_RX_INT[PCTERR] is set, contains the column at the time of the error. */
#else /* Word 0 - Little Endian */
        uint64_t lane_rxc              : 8;  /**< [  7:  0](RO/H) When CGX()_SMU()_RX_INT[PCTERR] is set, contains the column at the time of the error. */
        uint64_t state                 : 8;  /**< [ 15:  8](RO/H) When CGX()_SMU()_RX_INT[PCTERR] is set, contains the receive state at the time of
                                                                 the error. */
        uint64_t val                   : 1;  /**< [ 16: 16](R/W1C/H) Set when CGX()_SMU()_RX_INT[PCTERR] is set. */
        uint64_t reserved_17_63        : 47;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_bad_col_hi_s cn; */
} bdk_cgxx_smux_rx_bad_col_hi_t;

static inline uint64_t BDK_CGXX_SMUX_RX_BAD_COL_HI(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_BAD_COL_HI(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020058ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_BAD_COL_HI", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_BAD_COL_HI(a,b) bdk_cgxx_smux_rx_bad_col_hi_t
#define bustype_BDK_CGXX_SMUX_RX_BAD_COL_HI(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_BAD_COL_HI(a,b) "CGXX_SMUX_RX_BAD_COL_HI"
#define device_bar_BDK_CGXX_SMUX_RX_BAD_COL_HI(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_BAD_COL_HI(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_BAD_COL_HI(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_bad_col_lo
 *
 * CGX SMU RX Bad Column Low Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_bad_col_lo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t lane_rxd              : 64; /**< [ 63:  0](RO/H) When CGX()_SMU()_RX_INT[PCTERR] is set, [LANE_RXD] contains the XAUI/RXAUI column at
                                                                 the time of the error. */
#else /* Word 0 - Little Endian */
        uint64_t lane_rxd              : 64; /**< [ 63:  0](RO/H) When CGX()_SMU()_RX_INT[PCTERR] is set, [LANE_RXD] contains the XAUI/RXAUI column at
                                                                 the time of the error. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_bad_col_lo_s cn; */
} bdk_cgxx_smux_rx_bad_col_lo_t;

static inline uint64_t BDK_CGXX_SMUX_RX_BAD_COL_LO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_BAD_COL_LO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020050ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_BAD_COL_LO", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_BAD_COL_LO(a,b) bdk_cgxx_smux_rx_bad_col_lo_t
#define bustype_BDK_CGXX_SMUX_RX_BAD_COL_LO(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_BAD_COL_LO(a,b) "CGXX_SMUX_RX_BAD_COL_LO"
#define device_bar_BDK_CGXX_SMUX_RX_BAD_COL_LO(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_BAD_COL_LO(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_BAD_COL_LO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_ctl
 *
 * CGX SMU RX Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t status                : 2;  /**< [  1:  0](RO/H) Link status.
                                                                 0x0 = Link OK.
                                                                 0x1 = Local fault.
                                                                 0x2 = Remote fault.
                                                                 0x3 = Reserved. */
#else /* Word 0 - Little Endian */
        uint64_t status                : 2;  /**< [  1:  0](RO/H) Link status.
                                                                 0x0 = Link OK.
                                                                 0x1 = Local fault.
                                                                 0x2 = Remote fault.
                                                                 0x3 = Reserved. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_ctl_s cn; */
} bdk_cgxx_smux_rx_ctl_t;

static inline uint64_t BDK_CGXX_SMUX_RX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020048ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_CTL(a,b) bdk_cgxx_smux_rx_ctl_t
#define bustype_BDK_CGXX_SMUX_RX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_CTL(a,b) "CGXX_SMUX_RX_CTL"
#define device_bar_BDK_CGXX_SMUX_RX_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_CTL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_decision
 *
 * CGX SMU Packet Decision Registers
 * This register specifies the byte count used to determine when to accept or to filter a packet.
 * As each byte in a packet is received by CGX, the L2 byte count (i.e. the number of bytes from
 * the beginning of the L2 header (DMAC)) is compared against CNT. In normal operation, the L2
 * header begins after the PREAMBLE + SFD (CGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 1) and any
 * optional UDD skip data (CGX()_SMU()_RX_UDD_SKP[LEN]).
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_decision_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t cnt                   : 5;  /**< [  4:  0](R/W) The byte count to decide when to accept or filter a packet. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 5;  /**< [  4:  0](R/W) The byte count to decide when to accept or filter a packet. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_decision_s cn; */
} bdk_cgxx_smux_rx_decision_t;

static inline uint64_t BDK_CGXX_SMUX_RX_DECISION(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_DECISION(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020038ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_DECISION", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_DECISION(a,b) bdk_cgxx_smux_rx_decision_t
#define bustype_BDK_CGXX_SMUX_RX_DECISION(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_DECISION(a,b) "CGXX_SMUX_RX_DECISION"
#define device_bar_BDK_CGXX_SMUX_RX_DECISION(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_DECISION(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_DECISION(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_frm_chk
 *
 * CGX SMU RX Frame Check Registers
 * The CSRs provide the enable bits for a subset of errors passed to CMR encoded.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_frm_chk_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t skperr                : 1;  /**< [  8:  8](R/W) Skipper error. */
        uint64_t rcverr                : 1;  /**< [  7:  7](R/W) Frame was received with data-reception error. */
        uint64_t reserved_6            : 1;
        uint64_t fcserr_c              : 1;  /**< [  5:  5](R/W) Control frame was received with FCS/CRC error. */
        uint64_t fcserr_d              : 1;  /**< [  4:  4](R/W) Data frame was received with FCS/CRC error. */
        uint64_t jabber                : 1;  /**< [  3:  3](R/W) Frame was received with length > sys_length. */
        uint64_t reserved_0_2          : 3;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_2          : 3;
        uint64_t jabber                : 1;  /**< [  3:  3](R/W) Frame was received with length > sys_length. */
        uint64_t fcserr_d              : 1;  /**< [  4:  4](R/W) Data frame was received with FCS/CRC error. */
        uint64_t fcserr_c              : 1;  /**< [  5:  5](R/W) Control frame was received with FCS/CRC error. */
        uint64_t reserved_6            : 1;
        uint64_t rcverr                : 1;  /**< [  7:  7](R/W) Frame was received with data-reception error. */
        uint64_t skperr                : 1;  /**< [  8:  8](R/W) Skipper error. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_frm_chk_s cn; */
} bdk_cgxx_smux_rx_frm_chk_t;

static inline uint64_t BDK_CGXX_SMUX_RX_FRM_CHK(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_FRM_CHK(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020028ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_FRM_CHK", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_FRM_CHK(a,b) bdk_cgxx_smux_rx_frm_chk_t
#define bustype_BDK_CGXX_SMUX_RX_FRM_CHK(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_FRM_CHK(a,b) "CGXX_SMUX_RX_FRM_CHK"
#define device_bar_BDK_CGXX_SMUX_RX_FRM_CHK(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_FRM_CHK(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_FRM_CHK(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_frm_ctl
 *
 * CGX SMU RX Frame Control Registers
 * This register controls the handling of the frames.
 * The [CTL_BCK] and [CTL_DRP] bits control how the hardware handles incoming PAUSE packets. The
 * most
 * common modes of operation:
 * _ [CTL_BCK] = 1, [CTL_DRP] = 1: hardware handles everything
 * _ [CTL_BCK] = 0, [CTL_DRP] = 0: software sees all PAUSE frames
 * _ [CTL_BCK] = 0, [CTL_DRP] = 1: all PAUSE frames are completely ignored
 *
 * These control bits should be set to [CTL_BCK] = 0, [CTL_DRP] = 0 in half-duplex mode. Since
 * PAUSE
 * packets only apply to full duplex operation, any PAUSE packet would constitute an exception
 * which should be handled by the processing cores. PAUSE packets should not be forwarded.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_frm_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t ptp_mode              : 1;  /**< [ 12: 12](R/W) Timestamp mode. When [PTP_MODE] is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the CGX()_SMU()_RX_JABBER,
                                                                 CGX()_SMU()_RX_DECISION, and CGX()_SMU()_RX_UDD_SKP do not require any
                                                                 adjustment as they operate on the received packet size. When the packet reaches NIC, its
                                                                 size reflects the additional bytes. */
        uint64_t reserved_6_11         : 6;
        uint64_t ctl_smac              : 1;  /**< [  5:  5](R/W) Control PAUSE frames can match station SMAC. */
        uint64_t ctl_mcst              : 1;  /**< [  4:  4](R/W) Control PAUSE frames can match globally assigned multicast address. */
        uint64_t ctl_bck               : 1;  /**< [  3:  3](R/W) Forward PAUSE information to TX block. */
        uint64_t ctl_drp               : 1;  /**< [  2:  2](R/W) Drop control PAUSE frames. */
        uint64_t pre_strp              : 1;  /**< [  1:  1](R/W) Strip off the preamble (when present).

                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If [PTP_MODE] = 1 and [PRE_CHK] = 1, [PRE_STRP] must be 1.

                                                                 When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP] determines
                                                                 if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
        uint64_t pre_chk               : 1;  /**< [  0:  0](R/W) Check the preamble for correctness.
                                                                 This port is configured to send a valid 802.3 PREAMBLE to begin every frame. CGX checks
                                                                 that a valid PREAMBLE is received. When a problem does occur within
                                                                 the PREAMBLE sequence, the frame is marked as bad and not sent into the core. The
                                                                 CGX()_SMU()_RX_INT[PCTERR] interrupt is also raised.

                                                                 When CGX()_SMU()_TX_CTL[HG_EN] is set, [PRE_CHK] must be 0.

                                                                 If [PTP_MODE] = 1 and [PRE_CHK] = 1, [PRE_STRP] must be 1. */
#else /* Word 0 - Little Endian */
        uint64_t pre_chk               : 1;  /**< [  0:  0](R/W) Check the preamble for correctness.
                                                                 This port is configured to send a valid 802.3 PREAMBLE to begin every frame. CGX checks
                                                                 that a valid PREAMBLE is received. When a problem does occur within
                                                                 the PREAMBLE sequence, the frame is marked as bad and not sent into the core. The
                                                                 CGX()_SMU()_RX_INT[PCTERR] interrupt is also raised.

                                                                 When CGX()_SMU()_TX_CTL[HG_EN] is set, [PRE_CHK] must be 0.

                                                                 If [PTP_MODE] = 1 and [PRE_CHK] = 1, [PRE_STRP] must be 1. */
        uint64_t pre_strp              : 1;  /**< [  1:  1](R/W) Strip off the preamble (when present).

                                                                 0 = PREAMBLE + SFD is sent to core as part of frame.
                                                                 1 = PREAMBLE + SFD is dropped.
                                                                 [PRE_CHK] must be set to enable this and all PREAMBLE features.

                                                                 If [PTP_MODE] = 1 and [PRE_CHK] = 1, [PRE_STRP] must be 1.

                                                                 When [PRE_CHK] is set (indicating that the PREAMBLE will be sent), [PRE_STRP] determines
                                                                 if
                                                                 the PREAMBLE+SFD bytes are thrown away or sent to the core as part of the packet. In
                                                                 either mode, the PREAMBLE+SFD bytes are not counted toward the packet size when checking
                                                                 against the MIN and MAX bounds. Furthermore, the bytes are skipped when locating the start
                                                                 of the L2 header for DMAC and control frame recognition. */
        uint64_t ctl_drp               : 1;  /**< [  2:  2](R/W) Drop control PAUSE frames. */
        uint64_t ctl_bck               : 1;  /**< [  3:  3](R/W) Forward PAUSE information to TX block. */
        uint64_t ctl_mcst              : 1;  /**< [  4:  4](R/W) Control PAUSE frames can match globally assigned multicast address. */
        uint64_t ctl_smac              : 1;  /**< [  5:  5](R/W) Control PAUSE frames can match station SMAC. */
        uint64_t reserved_6_11         : 6;
        uint64_t ptp_mode              : 1;  /**< [ 12: 12](R/W) Timestamp mode. When [PTP_MODE] is set, a 64-bit timestamp is prepended to every incoming
                                                                 packet.

                                                                 The timestamp bytes are added to the packet in such a way as to not modify the packet's
                                                                 receive byte count. This implies that the CGX()_SMU()_RX_JABBER,
                                                                 CGX()_SMU()_RX_DECISION, and CGX()_SMU()_RX_UDD_SKP do not require any
                                                                 adjustment as they operate on the received packet size. When the packet reaches NIC, its
                                                                 size reflects the additional bytes. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_frm_ctl_s cn; */
} bdk_cgxx_smux_rx_frm_ctl_t;

static inline uint64_t BDK_CGXX_SMUX_RX_FRM_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_FRM_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020020ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_FRM_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_FRM_CTL(a,b) bdk_cgxx_smux_rx_frm_ctl_t
#define bustype_BDK_CGXX_SMUX_RX_FRM_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_FRM_CTL(a,b) "CGXX_SMUX_RX_FRM_CTL"
#define device_bar_BDK_CGXX_SMUX_RX_FRM_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_FRM_CTL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_FRM_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_int
 *
 * CGX SMU Receive Interrupt Registers
 * SMU Interrupt Register.
 * Internal:
 * Exception conditions <9> and <4:0> can also set the rcv/opcode in the received packet's work
 * queue entry. CGX()_SMU()_RX_FRM_CHK provides a bit mask for configuring which
 * conditions set the error.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1C/H) HiGig2 received message CRC or control-character error. Set when either a CRC8 error is
                                                                 detected, or when a control character is found in the message bytes after the K.SOM.
                                                                 HG2CC has higher priority than HG2FLD, which means that a HiGig2 message that results in
                                                                 HG2CC getting set never sets HG2FLD. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1C/H) HiGig2 received message field error:

                                                                 MSG_TYPE field not 0x0, i.e. it is not a flow-control message, which is the only defined
                                                                 type for HiGig2.

                                                                 FWD_TYPE field not 0x0, i.e. it is not a link-level message, which is the only defined
                                                                 type for HiGig2.

                                                                 FC_OBJECT field is neither 0x0 for physical link, nor 0x2 for logical link. Those are the
                                                                 only two defined types in HiGig2 */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1C/H) Frame is terminated by control character other than /T/. (XAUI/RXAUI mode only) The error
                                                                 propagation control character /E/ will be included as part of the frame and does not cause
                                                                 a frame termination. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1C/H) Reserved sequence detected. (XAUI/RXAUI mode only) */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1C/H) Remote-fault sequence detected. (XAUI/RXAUI mode only) */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1C/H) Local-fault sequence detected. (XAUI/RXAUI mode only) */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1C/H) Reserved opcodes. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1C/H) Bad preamble/protocol. In XAUI/RXAUI mode, the column of data that was bad is logged in
                                                                 CGX()_SMU()_RX_BAD_COL_LO and CGX()_SMU()_RX_BAD_COL_HI.
                                                                 PCTERR checks that the frame begins with a valid
                                                                 PREAMBLE sequence. Does not check the number of PREAMBLE cycles. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1C/H) Skipper error. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1C/H) Frame was received with data-reception error. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1C/H) Frame was received with FCS/CRC error */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Frame was received with length > sys_length. An RX Jabber error indicates that a packet
                                                                 was received which is longer than the maximum allowed packet as defined by the system. CGX
                                                                 terminates the packet with an EOP on the beat on which JABBER was exceeded. The beat on
                                                                 which JABBER was exceeded is left unchanged and all subsequent data beats are dropped.
                                                                 Failure to truncate could lead to system instability. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Frame was received with length > sys_length. An RX Jabber error indicates that a packet
                                                                 was received which is longer than the maximum allowed packet as defined by the system. CGX
                                                                 terminates the packet with an EOP on the beat on which JABBER was exceeded. The beat on
                                                                 which JABBER was exceeded is left unchanged and all subsequent data beats are dropped.
                                                                 Failure to truncate could lead to system instability. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1C/H) Frame was received with FCS/CRC error */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1C/H) Frame was received with data-reception error. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1C/H) Skipper error. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1C/H) Bad preamble/protocol. In XAUI/RXAUI mode, the column of data that was bad is logged in
                                                                 CGX()_SMU()_RX_BAD_COL_LO and CGX()_SMU()_RX_BAD_COL_HI.
                                                                 PCTERR checks that the frame begins with a valid
                                                                 PREAMBLE sequence. Does not check the number of PREAMBLE cycles. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1C/H) Reserved opcodes. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1C/H) Local-fault sequence detected. (XAUI/RXAUI mode only) */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1C/H) Remote-fault sequence detected. (XAUI/RXAUI mode only) */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1C/H) Reserved sequence detected. (XAUI/RXAUI mode only) */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1C/H) Frame is terminated by control character other than /T/. (XAUI/RXAUI mode only) The error
                                                                 propagation control character /E/ will be included as part of the frame and does not cause
                                                                 a frame termination. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1C/H) HiGig2 received message field error:

                                                                 MSG_TYPE field not 0x0, i.e. it is not a flow-control message, which is the only defined
                                                                 type for HiGig2.

                                                                 FWD_TYPE field not 0x0, i.e. it is not a link-level message, which is the only defined
                                                                 type for HiGig2.

                                                                 FC_OBJECT field is neither 0x0 for physical link, nor 0x2 for logical link. Those are the
                                                                 only two defined types in HiGig2 */
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1C/H) HiGig2 received message CRC or control-character error. Set when either a CRC8 error is
                                                                 detected, or when a control character is found in the message bytes after the K.SOM.
                                                                 HG2CC has higher priority than HG2FLD, which means that a HiGig2 message that results in
                                                                 HG2CC getting set never sets HG2FLD. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_int_s cn; */
} bdk_cgxx_smux_rx_int_t;

static inline uint64_t BDK_CGXX_SMUX_RX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020000ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_INT(a,b) bdk_cgxx_smux_rx_int_t
#define bustype_BDK_CGXX_SMUX_RX_INT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_INT(a,b) "CGXX_SMUX_RX_INT"
#define device_bar_BDK_CGXX_SMUX_RX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_INT(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_int_ena_w1c
 *
 * CGX SMU Receive Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2CC]. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2FLD]. */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_TERM]. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_SEQ]. */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[REM_FAULT]. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[LOC_FAULT]. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[RSVERR]. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[PCTERR]. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[SKPERR]. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[RCVERR]. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[JABBER]. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[FCSERR]. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[RCVERR]. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[SKPERR]. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[PCTERR]. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[RSVERR]. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[LOC_FAULT]. */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[REM_FAULT]. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_SEQ]. */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_TERM]. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2FLD]. */
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2CC]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_int_ena_w1c_s cn; */
} bdk_cgxx_smux_rx_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_SMUX_RX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020010ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_INT_ENA_W1C(a,b) bdk_cgxx_smux_rx_int_ena_w1c_t
#define bustype_BDK_CGXX_SMUX_RX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_INT_ENA_W1C(a,b) "CGXX_SMUX_RX_INT_ENA_W1C"
#define device_bar_BDK_CGXX_SMUX_RX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_int_ena_w1s
 *
 * CGX SMU Receive Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2CC]. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2FLD]. */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_TERM]. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_SEQ]. */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[REM_FAULT]. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[LOC_FAULT]. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[RSVERR]. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[PCTERR]. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[SKPERR]. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[RCVERR]. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[JABBER]. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[FCSERR]. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[RCVERR]. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[SKPERR]. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[PCTERR]. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[RSVERR]. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[LOC_FAULT]. */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[REM_FAULT]. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_SEQ]. */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[BAD_TERM]. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2FLD]. */
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_RX_INT[HG2CC]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_int_ena_w1s_s cn; */
} bdk_cgxx_smux_rx_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_SMUX_RX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020018ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_INT_ENA_W1S(a,b) bdk_cgxx_smux_rx_int_ena_w1s_t
#define bustype_BDK_CGXX_SMUX_RX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_INT_ENA_W1S(a,b) "CGXX_SMUX_RX_INT_ENA_W1S"
#define device_bar_BDK_CGXX_SMUX_RX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_int_w1s
 *
 * CGX SMU Receive Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_12_63        : 52;
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[HG2CC]. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[HG2FLD]. */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[BAD_TERM]. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[BAD_SEQ]. */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[REM_FAULT]. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[LOC_FAULT]. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[RSVERR]. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[PCTERR]. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[SKPERR]. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[RCVERR]. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[FCSERR]. */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[JABBER]. */
#else /* Word 0 - Little Endian */
        uint64_t jabber                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[JABBER]. */
        uint64_t fcserr                : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[FCSERR]. */
        uint64_t rcverr                : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[RCVERR]. */
        uint64_t skperr                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[SKPERR]. */
        uint64_t pcterr                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[PCTERR]. */
        uint64_t rsverr                : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[RSVERR]. */
        uint64_t loc_fault             : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[LOC_FAULT]. */
        uint64_t rem_fault             : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[REM_FAULT]. */
        uint64_t bad_seq               : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[BAD_SEQ]. */
        uint64_t bad_term              : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[BAD_TERM]. */
        uint64_t hg2fld                : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[HG2FLD]. */
        uint64_t hg2cc                 : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_RX_INT[HG2CC]. */
        uint64_t reserved_12_63        : 52;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_int_w1s_s cn; */
} bdk_cgxx_smux_rx_int_w1s_t;

static inline uint64_t BDK_CGXX_SMUX_RX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020008ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_INT_W1S(a,b) bdk_cgxx_smux_rx_int_w1s_t
#define bustype_BDK_CGXX_SMUX_RX_INT_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_INT_W1S(a,b) "CGXX_SMUX_RX_INT_W1S"
#define device_bar_BDK_CGXX_SMUX_RX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_INT_W1S(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_jabber
 *
 * CGX SMU Maximum Packet-Size Registers
 * This register specifies the maximum size for packets, beyond which the SMU truncates. In
 * XAUI/RXAUI mode, port 0 is used for checking.
 *
 * Internal:
 * The packet that will be sent to the packet input logic will have an
 * additionl 8 bytes if CGX()_SMU()_RX_FRM_CTL[PRE_CHK] is set and
 * CGX()_SMU()_RX_FRM_CTL[PRE_STRP] is clear.  The max packet that will be sent is
 * defined as:
 *
 * _ max_sized_packet = CGX()_SMU()_RX_JABBER[CNT]+((CGX()_SMU()_RX_FRM_CTL[PRE_CHK] &
 * !CGX()_SMU()_RX_FRM_CTL[PRE_STRP])*8)
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_jabber_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W) Byte count for jabber check. Failing packets set the JABBER interrupt and are optionally
                                                                 sent with opcode = JABBER. CGX truncates the packet to CNT+1 to CNT+8 bytes.
                                                                 CNT must be 8-byte aligned such that CNT<2:0> = 000. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 16; /**< [ 15:  0](R/W) Byte count for jabber check. Failing packets set the JABBER interrupt and are optionally
                                                                 sent with opcode = JABBER. CGX truncates the packet to CNT+1 to CNT+8 bytes.
                                                                 CNT must be 8-byte aligned such that CNT<2:0> = 000. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_jabber_s cn; */
} bdk_cgxx_smux_rx_jabber_t;

static inline uint64_t BDK_CGXX_SMUX_RX_JABBER(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_JABBER(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020030ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_JABBER", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_JABBER(a,b) bdk_cgxx_smux_rx_jabber_t
#define bustype_BDK_CGXX_SMUX_RX_JABBER(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_JABBER(a,b) "CGXX_SMUX_RX_JABBER"
#define device_bar_BDK_CGXX_SMUX_RX_JABBER(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_JABBER(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_JABBER(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_udd_skp
 *
 * CGX SMU User-Defined Data Skip Registers
 * Internal:
 * (1) The skip bytes are part of the packet and will be sent down the NCB
 * packet interface and will be handled by NIC.
 * (2) The system can determine if the UDD bytes are included in the FCS check
 * by using the FCSSEL field if the FCS check is enabled.
 *
 * (3) Assume that the preamble/sfd is always at the start of the frame even
 * before UDD bytes.  In most cases, there will be no preamble in these
 * cases since it will be packet interface in direct communication to
 * another packet interface (MAC to MAC) without a PHY involved.
 *
 * (4) We can still do address filtering and control packet filtering if the
 * user desires.
 *
 * (6) In all cases, the UDD bytes will be sent down the packet interface as
 * part of the packet.  The UDD bytes are never stripped from the actual
 * packet.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_udd_skp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t fcssel                : 1;  /**< [  8:  8](R/W) Include the skip bytes in the FCS calculation.
                                                                 0 = All skip bytes are included in FCS.
                                                                 1 = The skip bytes are not included in FCS.

                                                                 When CGX()_SMU()_TX_CTL[HG_EN] is set, this field must be 0.
                                                                 The skip bytes are part of the packet and are sent through the NCB packet interface and
                                                                 are handled by NIC. The system can determine if the UDD bytes are included in the FCS
                                                                 check by using the FCSSEL field, if the FCS check is enabled. */
        uint64_t reserved_7            : 1;
        uint64_t len                   : 7;  /**< [  6:  0](R/W) Amount of user-defined data before the start of the L2C data, in bytes.
                                                                 Setting to 0 means L2C comes first; maximum value is 64.
                                                                 LEN must be 0x0 in half-duplex operation.

                                                                 When CGX()_SMU()_TX_CTL[HG_EN] is set, this field must be set to 12 or 16
                                                                 (depending on HiGig header size) to account for the HiGig header.
                                                                 LEN = 12 selects HiGig/HiGig+; LEN = 16 selects HiGig2. */
#else /* Word 0 - Little Endian */
        uint64_t len                   : 7;  /**< [  6:  0](R/W) Amount of user-defined data before the start of the L2C data, in bytes.
                                                                 Setting to 0 means L2C comes first; maximum value is 64.
                                                                 LEN must be 0x0 in half-duplex operation.

                                                                 When CGX()_SMU()_TX_CTL[HG_EN] is set, this field must be set to 12 or 16
                                                                 (depending on HiGig header size) to account for the HiGig header.
                                                                 LEN = 12 selects HiGig/HiGig+; LEN = 16 selects HiGig2. */
        uint64_t reserved_7            : 1;
        uint64_t fcssel                : 1;  /**< [  8:  8](R/W) Include the skip bytes in the FCS calculation.
                                                                 0 = All skip bytes are included in FCS.
                                                                 1 = The skip bytes are not included in FCS.

                                                                 When CGX()_SMU()_TX_CTL[HG_EN] is set, this field must be 0.
                                                                 The skip bytes are part of the packet and are sent through the NCB packet interface and
                                                                 are handled by NIC. The system can determine if the UDD bytes are included in the FCS
                                                                 check by using the FCSSEL field, if the FCS check is enabled. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_udd_skp_s cn; */
} bdk_cgxx_smux_rx_udd_skp_t;

static inline uint64_t BDK_CGXX_SMUX_RX_UDD_SKP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_UDD_SKP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020040ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_UDD_SKP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_UDD_SKP(a,b) bdk_cgxx_smux_rx_udd_skp_t
#define bustype_BDK_CGXX_SMUX_RX_UDD_SKP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_UDD_SKP(a,b) "CGXX_SMUX_RX_UDD_SKP"
#define device_bar_BDK_CGXX_SMUX_RX_UDD_SKP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_UDD_SKP(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_UDD_SKP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_wol_ctrl0
 *
 * CGX SMU RX Wake-on-LAN Control 0 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_wol_ctrl0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t pswd_len              : 4;  /**< [ 51: 48](R/W) Byte length of the optional wake-on-LAN password. A value of 0x0 indicates a
                                                                 password is not enabled. When non-zero, the least significant bytes of
                                                                 CGX()_SMU()_RX_WOL_CTRL1 are used for the password match. Values 0x9 to 0xF are
                                                                 reserved. */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The MAC address to compare against received wake-on-LAN packets. */
#else /* Word 0 - Little Endian */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The MAC address to compare against received wake-on-LAN packets. */
        uint64_t pswd_len              : 4;  /**< [ 51: 48](R/W) Byte length of the optional wake-on-LAN password. A value of 0x0 indicates a
                                                                 password is not enabled. When non-zero, the least significant bytes of
                                                                 CGX()_SMU()_RX_WOL_CTRL1 are used for the password match. Values 0x9 to 0xF are
                                                                 reserved. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_wol_ctrl0_s cn; */
} bdk_cgxx_smux_rx_wol_ctrl0_t;

static inline uint64_t BDK_CGXX_SMUX_RX_WOL_CTRL0(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_WOL_CTRL0(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020190ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_WOL_CTRL0", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_WOL_CTRL0(a,b) bdk_cgxx_smux_rx_wol_ctrl0_t
#define bustype_BDK_CGXX_SMUX_RX_WOL_CTRL0(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_WOL_CTRL0(a,b) "CGXX_SMUX_RX_WOL_CTRL0"
#define device_bar_BDK_CGXX_SMUX_RX_WOL_CTRL0(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_WOL_CTRL0(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_WOL_CTRL0(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_rx_wol_ctrl1
 *
 * CGX SMU RX Wake-on-LAN Control 1 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_rx_wol_ctrl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pswd                  : 64; /**< [ 63:  0](R/W) The optional password to compare against received Wake-on-LAN packets. The length of the
                                                                 valid password is indicated by CGX()_SMU()_RX_WOL_CTRL0[PSWD_LEN]. */
#else /* Word 0 - Little Endian */
        uint64_t pswd                  : 64; /**< [ 63:  0](R/W) The optional password to compare against received Wake-on-LAN packets. The length of the
                                                                 valid password is indicated by CGX()_SMU()_RX_WOL_CTRL0[PSWD_LEN]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_rx_wol_ctrl1_s cn; */
} bdk_cgxx_smux_rx_wol_ctrl1_t;

static inline uint64_t BDK_CGXX_SMUX_RX_WOL_CTRL1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_RX_WOL_CTRL1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020198ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_RX_WOL_CTRL1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_RX_WOL_CTRL1(a,b) bdk_cgxx_smux_rx_wol_ctrl1_t
#define bustype_BDK_CGXX_SMUX_RX_WOL_CTRL1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_RX_WOL_CTRL1(a,b) "CGXX_SMUX_RX_WOL_CTRL1"
#define device_bar_BDK_CGXX_SMUX_RX_WOL_CTRL1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_RX_WOL_CTRL1(a,b) (a)
#define arguments_BDK_CGXX_SMUX_RX_WOL_CTRL1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_smac
 *
 * CGX SMU SMAC Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_smac_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t smac                  : 48; /**< [ 47:  0](R/W) The SMAC field is used for generating and accepting control PAUSE packets. */
#else /* Word 0 - Little Endian */
        uint64_t smac                  : 48; /**< [ 47:  0](R/W) The SMAC field is used for generating and accepting control PAUSE packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_smac_s cn; */
} bdk_cgxx_smux_smac_t;

static inline uint64_t BDK_CGXX_SMUX_SMAC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_SMAC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020108ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_SMAC", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_SMAC(a,b) bdk_cgxx_smux_smac_t
#define bustype_BDK_CGXX_SMUX_SMAC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_SMAC(a,b) "CGXX_SMUX_SMAC"
#define device_bar_BDK_CGXX_SMUX_SMAC(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_SMAC(a,b) (a)
#define arguments_BDK_CGXX_SMUX_SMAC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_append
 *
 * CGX SMU TX Append Control Registers
 * For more details on the interactions between FCS and PAD, see also the description of
 * CGX()_SMU()_TX_MIN_PKT[MIN_SIZE].
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_append_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t fcs_c                 : 1;  /**< [  3:  3](R/W) Append the Ethernet FCS on each PAUSE packet. PAUSE packets are normally padded to 60
                                                                 bytes. If CGX()_SMU()_TX_MIN_PKT[MIN_SIZE] exceeds 59, then [FCS_C] is not used. */
        uint64_t fcs_d                 : 1;  /**< [  2:  2](R/W) Append the Ethernet FCS on each data packet. */
        uint64_t pad                   : 1;  /**< [  1:  1](R/W) Append PAD bytes such that minimum-sized packet is transmitted. */
        uint64_t preamble              : 1;  /**< [  0:  0](R/W) Prepend the Ethernet preamble on each transfer. When CGX()_SMU()_TX_CTL[HG_EN] is
                                                                 set, PREAMBLE must be 0. */
#else /* Word 0 - Little Endian */
        uint64_t preamble              : 1;  /**< [  0:  0](R/W) Prepend the Ethernet preamble on each transfer. When CGX()_SMU()_TX_CTL[HG_EN] is
                                                                 set, PREAMBLE must be 0. */
        uint64_t pad                   : 1;  /**< [  1:  1](R/W) Append PAD bytes such that minimum-sized packet is transmitted. */
        uint64_t fcs_d                 : 1;  /**< [  2:  2](R/W) Append the Ethernet FCS on each data packet. */
        uint64_t fcs_c                 : 1;  /**< [  3:  3](R/W) Append the Ethernet FCS on each PAUSE packet. PAUSE packets are normally padded to 60
                                                                 bytes. If CGX()_SMU()_TX_MIN_PKT[MIN_SIZE] exceeds 59, then [FCS_C] is not used. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_append_s cn; */
} bdk_cgxx_smux_tx_append_t;

static inline uint64_t BDK_CGXX_SMUX_TX_APPEND(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_APPEND(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020100ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_APPEND", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_APPEND(a,b) bdk_cgxx_smux_tx_append_t
#define bustype_BDK_CGXX_SMUX_TX_APPEND(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_APPEND(a,b) "CGXX_SMUX_TX_APPEND"
#define device_bar_BDK_CGXX_SMUX_TX_APPEND(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_APPEND(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_APPEND(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_ctl
 *
 * CGX SMU Transmit Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_31_63        : 33;
        uint64_t spu_mrk_cnt           : 20; /**< [ 30: 11](R/W) 40GBASE-R transmit marker interval count. Specifies the interval (number of 66-bit BASE-R
                                                                 blocks) at which the LMAC transmit logic inserts 40GBASE-R alignment markers. An internal
                                                                 counter in SMU is initialized to this value, counts down for each BASE-R block transmitted
                                                                 by the LMAC, and wraps back to the initial value from 0. The LMAC transmit logic inserts
                                                                 alignment markers for lanes 0, 1, 2 and 3, respectively, in the last four BASE-R blocks
                                                                 before the counter wraps (3, 2, 1, 0). The default value corresponds to an alignment
                                                                 marker period of 16363 blocks (exclusive) per lane, as specified in 802.3ba-2010. The
                                                                 default value should always be used for normal operation. */
        uint64_t hg_pause_hgi          : 2;  /**< [ 10:  9](R/W) HGI field for hardware-generated HiGig PAUSE packets. */
        uint64_t hg_en                 : 1;  /**< [  8:  8](R/W) Enable HiGig mode.
                                                                 When this field is set and CGX()_SMU()_RX_UDD_SKP[LEN] = 12, the interface is in
                                                                 HiGig/HiGig+ mode and the following must be set:
                                                                 * CGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[FCSSEL] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[LEN] = 12.
                                                                 * CGX()_SMU()_TX_APPEND[PREAMBLE] = 0.

                                                                 When this field is set and CGX()_SMU()_RX_UDD_SKP[LEN] = 16, the interface is in
                                                                 HiGig2 mode and the following must be set:
                                                                 * CGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[FCSSEL] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[LEN] = 16.
                                                                 * CGX()_SMU()_TX_APPEND[PREAMBLE] = 0.
                                                                 * CGX()_SMU()_CBFC_CTL[RX_EN] = 0.
                                                                 * CGX()_SMU()_CBFC_CTL[TX_EN] = 0. */
        uint64_t l2p_bp_conv           : 1;  /**< [  7:  7](R/W) If set, causes TX to generate 802.3 pause packets when CMR applies logical backpressure
                                                                 (XOFF), if and only if CGX()_SMU()_CBFC_CTL[TX_EN] is clear and
                                                                 CGX()_SMU()_HG2_CONTROL[HG2TX_EN] is clear. */
        uint64_t ls_byp                : 1;  /**< [  6:  6](R/W) Bypass the link status, as determined by the XGMII receiver, and set the link status of
                                                                 the transmitter to LS. */
        uint64_t ls                    : 2;  /**< [  5:  4](R/W) Link status.
                                                                 0 = Link OK; link runs normally. RS passes MAC data to PCS.
                                                                 1 = Local fault. RS layer sends continuous remote fault sequences.
                                                                 2 = Remote fault. RS layer sends continuous idle sequences.
                                                                 3 = Link drain. RS layer drops full packets to allow CGX and PKO to drain their FIFOs. */
        uint64_t reserved_3            : 1;
        uint64_t x4a_dis               : 1;  /**< [  2:  2](R/W) Disable 4-byte SOP align (effectively force 8-byte SOP align) for all 10G variants
                                                                 (XAUI, RXAUI, 10G). */
        uint64_t uni_en                : 1;  /**< [  1:  1](R/W) Enable unidirectional mode (IEEE Clause 66). */
        uint64_t dic_en                : 1;  /**< [  0:  0](R/W) Enable the deficit idle counter for IFG averaging. */
#else /* Word 0 - Little Endian */
        uint64_t dic_en                : 1;  /**< [  0:  0](R/W) Enable the deficit idle counter for IFG averaging. */
        uint64_t uni_en                : 1;  /**< [  1:  1](R/W) Enable unidirectional mode (IEEE Clause 66). */
        uint64_t x4a_dis               : 1;  /**< [  2:  2](R/W) Disable 4-byte SOP align (effectively force 8-byte SOP align) for all 10G variants
                                                                 (XAUI, RXAUI, 10G). */
        uint64_t reserved_3            : 1;
        uint64_t ls                    : 2;  /**< [  5:  4](R/W) Link status.
                                                                 0 = Link OK; link runs normally. RS passes MAC data to PCS.
                                                                 1 = Local fault. RS layer sends continuous remote fault sequences.
                                                                 2 = Remote fault. RS layer sends continuous idle sequences.
                                                                 3 = Link drain. RS layer drops full packets to allow CGX and PKO to drain their FIFOs. */
        uint64_t ls_byp                : 1;  /**< [  6:  6](R/W) Bypass the link status, as determined by the XGMII receiver, and set the link status of
                                                                 the transmitter to LS. */
        uint64_t l2p_bp_conv           : 1;  /**< [  7:  7](R/W) If set, causes TX to generate 802.3 pause packets when CMR applies logical backpressure
                                                                 (XOFF), if and only if CGX()_SMU()_CBFC_CTL[TX_EN] is clear and
                                                                 CGX()_SMU()_HG2_CONTROL[HG2TX_EN] is clear. */
        uint64_t hg_en                 : 1;  /**< [  8:  8](R/W) Enable HiGig mode.
                                                                 When this field is set and CGX()_SMU()_RX_UDD_SKP[LEN] = 12, the interface is in
                                                                 HiGig/HiGig+ mode and the following must be set:
                                                                 * CGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[FCSSEL] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[LEN] = 12.
                                                                 * CGX()_SMU()_TX_APPEND[PREAMBLE] = 0.

                                                                 When this field is set and CGX()_SMU()_RX_UDD_SKP[LEN] = 16, the interface is in
                                                                 HiGig2 mode and the following must be set:
                                                                 * CGX()_SMU()_RX_FRM_CTL[PRE_CHK] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[FCSSEL] = 0.
                                                                 * CGX()_SMU()_RX_UDD_SKP[LEN] = 16.
                                                                 * CGX()_SMU()_TX_APPEND[PREAMBLE] = 0.
                                                                 * CGX()_SMU()_CBFC_CTL[RX_EN] = 0.
                                                                 * CGX()_SMU()_CBFC_CTL[TX_EN] = 0. */
        uint64_t hg_pause_hgi          : 2;  /**< [ 10:  9](R/W) HGI field for hardware-generated HiGig PAUSE packets. */
        uint64_t spu_mrk_cnt           : 20; /**< [ 30: 11](R/W) 40GBASE-R transmit marker interval count. Specifies the interval (number of 66-bit BASE-R
                                                                 blocks) at which the LMAC transmit logic inserts 40GBASE-R alignment markers. An internal
                                                                 counter in SMU is initialized to this value, counts down for each BASE-R block transmitted
                                                                 by the LMAC, and wraps back to the initial value from 0. The LMAC transmit logic inserts
                                                                 alignment markers for lanes 0, 1, 2 and 3, respectively, in the last four BASE-R blocks
                                                                 before the counter wraps (3, 2, 1, 0). The default value corresponds to an alignment
                                                                 marker period of 16363 blocks (exclusive) per lane, as specified in 802.3ba-2010. The
                                                                 default value should always be used for normal operation. */
        uint64_t reserved_31_63        : 33;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_ctl_s cn; */
} bdk_cgxx_smux_tx_ctl_t;

static inline uint64_t BDK_CGXX_SMUX_TX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020178ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_CTL(a,b) bdk_cgxx_smux_tx_ctl_t
#define bustype_BDK_CGXX_SMUX_TX_CTL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_CTL(a,b) "CGXX_SMUX_TX_CTL"
#define device_bar_BDK_CGXX_SMUX_TX_CTL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_CTL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_eee
 *
 * CGX SMU TX EEE Configure Registers
 * These registers control when SMU TX requests to enter or exist LPI. Those registers
 * take effect only when EEE is supported and enabled for a given LMAC.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_eee_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_61_63        : 3;
        uint64_t tx_lpi                : 1;  /**< [ 60: 60](RO) SMU TX is in LPI state. */
        uint64_t idle_cnt              : 28; /**< [ 59: 32](RO) The current idle counter value is only valid when [AUTO_LPI] is set. The counter
                                                                 will be increased during idle state while 128 bits have been transimitted. The
                                                                 counter will be saturated at [IDLE_THRESH]. */
        uint64_t auto_lpi              : 1;  /**< [ 31: 31](R/W) SMU TX will send LPI requests to SPU when the bit is set and the idle counter
                                                                 reaches [IDLE_THRESH]. While in LPI state, SMU TX will switch to send idle once
                                                                 the transmitter has packets (including flow control packets) to send or [WAKEUP]
                                                                 is set by software. */
        uint64_t wakeup                : 1;  /**< [ 30: 30](R/W/H) [WAKEUP] is valid only when [AUTO_LPI] is set and only writeable by software
                                                                 when the transmitter is in LPI state. While SMU transmitter is in LPI state,
                                                                 software can use this bit to switch SMU TX from sending LPI to sending idle to
                                                                 SPU. [WAKEUP] will be automatically cleared by CGX when the switching is
                                                                 initiated by CGX. */
        uint64_t force_lpi             : 1;  /**< [ 29: 29](R/W) [FORCE_LPI] is only valid when [AUTO_LPI] is cleared. SMU TX will send LPI
                                                                 requests to SPU immediately after the current packet is transmitted when the bit
                                                                 is set. While in LPI mode, SMU transmitter will switch to send idle once the bit
                                                                 is cleared. */
        uint64_t reserved_28           : 1;
        uint64_t idle_thresh           : 28; /**< [ 27:  0](R/W) Idle threshold. [IDLE_THRESH] is only used when [AUTO_LPI] is set. SMU
                                                                 transmitter will send LPI requests to SPU when the idle counter reaches this
                                                                 thredhold. The units of this value are 128-bit word (or a SPU heart beat). Note
                                                                 that active flow control of a enabled LMAC will keep the corresponding LMAC not
                                                                 idle. */
#else /* Word 0 - Little Endian */
        uint64_t idle_thresh           : 28; /**< [ 27:  0](R/W) Idle threshold. [IDLE_THRESH] is only used when [AUTO_LPI] is set. SMU
                                                                 transmitter will send LPI requests to SPU when the idle counter reaches this
                                                                 thredhold. The units of this value are 128-bit word (or a SPU heart beat). Note
                                                                 that active flow control of a enabled LMAC will keep the corresponding LMAC not
                                                                 idle. */
        uint64_t reserved_28           : 1;
        uint64_t force_lpi             : 1;  /**< [ 29: 29](R/W) [FORCE_LPI] is only valid when [AUTO_LPI] is cleared. SMU TX will send LPI
                                                                 requests to SPU immediately after the current packet is transmitted when the bit
                                                                 is set. While in LPI mode, SMU transmitter will switch to send idle once the bit
                                                                 is cleared. */
        uint64_t wakeup                : 1;  /**< [ 30: 30](R/W/H) [WAKEUP] is valid only when [AUTO_LPI] is set and only writeable by software
                                                                 when the transmitter is in LPI state. While SMU transmitter is in LPI state,
                                                                 software can use this bit to switch SMU TX from sending LPI to sending idle to
                                                                 SPU. [WAKEUP] will be automatically cleared by CGX when the switching is
                                                                 initiated by CGX. */
        uint64_t auto_lpi              : 1;  /**< [ 31: 31](R/W) SMU TX will send LPI requests to SPU when the bit is set and the idle counter
                                                                 reaches [IDLE_THRESH]. While in LPI state, SMU TX will switch to send idle once
                                                                 the transmitter has packets (including flow control packets) to send or [WAKEUP]
                                                                 is set by software. */
        uint64_t idle_cnt              : 28; /**< [ 59: 32](RO) The current idle counter value is only valid when [AUTO_LPI] is set. The counter
                                                                 will be increased during idle state while 128 bits have been transimitted. The
                                                                 counter will be saturated at [IDLE_THRESH]. */
        uint64_t tx_lpi                : 1;  /**< [ 60: 60](RO) SMU TX is in LPI state. */
        uint64_t reserved_61_63        : 3;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_eee_s cn; */
} bdk_cgxx_smux_tx_eee_t;

static inline uint64_t BDK_CGXX_SMUX_TX_EEE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_EEE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020188ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_EEE", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_EEE(a,b) bdk_cgxx_smux_tx_eee_t
#define bustype_BDK_CGXX_SMUX_TX_EEE(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_EEE(a,b) "CGXX_SMUX_TX_EEE"
#define device_bar_BDK_CGXX_SMUX_TX_EEE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_EEE(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_EEE(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_ifg
 *
 * CGX SMU TX Interframe-Gap Cycles Registers
 * Programming IFG1 and IFG2:
 * * For XAUI/RXAUI/10Gbs/40Gbs systems that require IEEE 802.3 compatibility, the IFG1+IFG2 sum
 * must be 12.
 * * In loopback mode, the IFG1+IFG2 of local and remote parties must match exactly; otherwise
 * one of the two sides' loopback FIFO will overrun: CGX()_SMU()_TX_INT[LB_OVRFLW].
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_ifg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t ifg2                  : 4;  /**< [  7:  4](R/W) 1/2 of the interframe gap timing (in IFG2*8 bits). */
        uint64_t ifg1                  : 4;  /**< [  3:  0](R/W) 1/2 of the interframe gap timing (in IFG1*8 bits). */
#else /* Word 0 - Little Endian */
        uint64_t ifg1                  : 4;  /**< [  3:  0](R/W) 1/2 of the interframe gap timing (in IFG1*8 bits). */
        uint64_t ifg2                  : 4;  /**< [  7:  4](R/W) 1/2 of the interframe gap timing (in IFG2*8 bits). */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_ifg_s cn; */
} bdk_cgxx_smux_tx_ifg_t;

static inline uint64_t BDK_CGXX_SMUX_TX_IFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_IFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020160ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_IFG", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_IFG(a,b) bdk_cgxx_smux_tx_ifg_t
#define bustype_BDK_CGXX_SMUX_TX_IFG(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_IFG(a,b) "CGXX_SMUX_TX_IFG"
#define device_bar_BDK_CGXX_SMUX_TX_IFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_IFG(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_IFG(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_int
 *
 * CGX SMU TX Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1C/H) TX loopback overflow. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1C/H) TX loopback underflow. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1C/H) TX SMU started a packet with PTP on SOP and has not seen a commit for it from TX SPU after
                                                                 256 cycles so it faked a commit to CMR. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1C/H) Link status changed. This denotes a change to CGX()_SMU()_RX_CTL[STATUS]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) TX underflow. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) TX underflow. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1C/H) Link status changed. This denotes a change to CGX()_SMU()_RX_CTL[STATUS]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1C/H) TX SMU started a packet with PTP on SOP and has not seen a commit for it from TX SPU after
                                                                 256 cycles so it faked a commit to CMR. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1C/H) TX loopback underflow. */
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1C/H) TX loopback overflow. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_int_s cn; */
} bdk_cgxx_smux_tx_int_t;

static inline uint64_t BDK_CGXX_SMUX_TX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020140ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_INT(a,b) bdk_cgxx_smux_tx_int_t
#define bustype_BDK_CGXX_SMUX_TX_INT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_INT(a,b) "CGXX_SMUX_TX_INT"
#define device_bar_BDK_CGXX_SMUX_TX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_INT(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_int_ena_w1c
 *
 * CGX SMU TX Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_OVRFLW]. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_UNDFLW]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[FAKE_COMMIT]. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[XCHANGE]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[UNDFLW]. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[UNDFLW]. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[XCHANGE]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[FAKE_COMMIT]. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_UNDFLW]. */
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_OVRFLW]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_int_ena_w1c_s cn; */
} bdk_cgxx_smux_tx_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_SMUX_TX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020150ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_INT_ENA_W1C(a,b) bdk_cgxx_smux_tx_int_ena_w1c_t
#define bustype_BDK_CGXX_SMUX_TX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_INT_ENA_W1C(a,b) "CGXX_SMUX_TX_INT_ENA_W1C"
#define device_bar_BDK_CGXX_SMUX_TX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_int_ena_w1s
 *
 * CGX SMU TX Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_OVRFLW]. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_UNDFLW]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[FAKE_COMMIT]. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[XCHANGE]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[UNDFLW]. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[UNDFLW]. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[XCHANGE]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[FAKE_COMMIT]. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_UNDFLW]. */
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SMU(0..3)_TX_INT[LB_OVRFLW]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_int_ena_w1s_s cn; */
} bdk_cgxx_smux_tx_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_SMUX_TX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020158ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_INT_ENA_W1S(a,b) bdk_cgxx_smux_tx_int_ena_w1s_t
#define bustype_BDK_CGXX_SMUX_TX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_INT_ENA_W1S(a,b) "CGXX_SMUX_TX_INT_ENA_W1S"
#define device_bar_BDK_CGXX_SMUX_TX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_int_w1s
 *
 * CGX SMU TX Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_5_63         : 59;
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[LB_OVRFLW]. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[LB_UNDFLW]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[FAKE_COMMIT]. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[XCHANGE]. */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[UNDFLW]. */
#else /* Word 0 - Little Endian */
        uint64_t undflw                : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[UNDFLW]. */
        uint64_t xchange               : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[XCHANGE]. */
        uint64_t fake_commit           : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[FAKE_COMMIT]. */
        uint64_t lb_undflw             : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[LB_UNDFLW]. */
        uint64_t lb_ovrflw             : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_SMU(0..3)_TX_INT[LB_OVRFLW]. */
        uint64_t reserved_5_63         : 59;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_int_w1s_s cn; */
} bdk_cgxx_smux_tx_int_w1s_t;

static inline uint64_t BDK_CGXX_SMUX_TX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020148ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_INT_W1S(a,b) bdk_cgxx_smux_tx_int_w1s_t
#define bustype_BDK_CGXX_SMUX_TX_INT_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_INT_W1S(a,b) "CGXX_SMUX_TX_INT_W1S"
#define device_bar_BDK_CGXX_SMUX_TX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_INT_W1S(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_min_pkt
 *
 * CGX SMU TX Minimum-Size-Packet Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_min_pkt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t min_size              : 8;  /**< [  7:  0](R/W) Min frame in bytes inclusive of FCS, if applied. Padding is only appended when
                                                                 CGX()_SMU()_TX_APPEND[PAD] for the corresponding port is set. When FCS is added to
                                                                 a packet which was padded, the FCS always appears in the 4 octets preceding /T/ or /E/. */
#else /* Word 0 - Little Endian */
        uint64_t min_size              : 8;  /**< [  7:  0](R/W) Min frame in bytes inclusive of FCS, if applied. Padding is only appended when
                                                                 CGX()_SMU()_TX_APPEND[PAD] for the corresponding port is set. When FCS is added to
                                                                 a packet which was padded, the FCS always appears in the 4 octets preceding /T/ or /E/. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_min_pkt_s cn; */
} bdk_cgxx_smux_tx_min_pkt_t;

static inline uint64_t BDK_CGXX_SMUX_TX_MIN_PKT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_MIN_PKT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020118ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_MIN_PKT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_MIN_PKT(a,b) bdk_cgxx_smux_tx_min_pkt_t
#define bustype_BDK_CGXX_SMUX_TX_MIN_PKT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_MIN_PKT(a,b) "CGXX_SMUX_TX_MIN_PKT"
#define device_bar_BDK_CGXX_SMUX_TX_MIN_PKT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_MIN_PKT(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_MIN_PKT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_pause_pkt_dmac
 *
 * CGX SMU TX PAUSE-Packet DMAC-Field Registers
 * This register provides the DMAC value that is placed in outbound PAUSE packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_pause_pkt_dmac_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The DMAC field that is placed in outbound PAUSE packets. */
#else /* Word 0 - Little Endian */
        uint64_t dmac                  : 48; /**< [ 47:  0](R/W) The DMAC field that is placed in outbound PAUSE packets. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_pause_pkt_dmac_s cn; */
} bdk_cgxx_smux_tx_pause_pkt_dmac_t;

static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020168ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_PAUSE_PKT_DMAC", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(a,b) bdk_cgxx_smux_tx_pause_pkt_dmac_t
#define bustype_BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(a,b) "CGXX_SMUX_TX_PAUSE_PKT_DMAC"
#define device_bar_BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_PAUSE_PKT_DMAC(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_pause_pkt_interval
 *
 * CGX SMU TX PAUSE-Packet Transmission-Interval Registers
 * This register specifies how often PAUSE packets are sent.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_pause_pkt_interval_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t hg2_intra_en          : 1;  /**< [ 32: 32](R/W) Allow intrapacket HiGig2 message generation. Relevant only if HiGig2 message generation is enabled. */
        uint64_t hg2_intra_interval    : 16; /**< [ 31: 16](R/W) Arbitrate for a HiGig2 message, every (INTERVAL*512) bit-times whilst sending regular
                                                                 packet data. Relevant only if HiGig2 message generation and [HG2_INTRA_EN] are both set.
                                                                 Normally, 0 < INTERVAL < CGX()_SMU()_TX_PAUSE_PKT_TIME.

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
        uint64_t interval              : 16; /**< [ 15:  0](R/W) Arbitrate for a 802.3 PAUSE packet, HiGig2 message, or PFC packet every
                                                                 (INTERVAL * 512) bit-times.
                                                                 Normally, 0 < INTERVAL < CGX()_SMU()_TX_PAUSE_PKT_TIME[P_TIME].

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
#else /* Word 0 - Little Endian */
        uint64_t interval              : 16; /**< [ 15:  0](R/W) Arbitrate for a 802.3 PAUSE packet, HiGig2 message, or PFC packet every
                                                                 (INTERVAL * 512) bit-times.
                                                                 Normally, 0 < INTERVAL < CGX()_SMU()_TX_PAUSE_PKT_TIME[P_TIME].

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
        uint64_t hg2_intra_interval    : 16; /**< [ 31: 16](R/W) Arbitrate for a HiGig2 message, every (INTERVAL*512) bit-times whilst sending regular
                                                                 packet data. Relevant only if HiGig2 message generation and [HG2_INTRA_EN] are both set.
                                                                 Normally, 0 < INTERVAL < CGX()_SMU()_TX_PAUSE_PKT_TIME.

                                                                 INTERVAL = 0 only sends a single PAUSE packet for each backpressure event. */
        uint64_t hg2_intra_en          : 1;  /**< [ 32: 32](R/W) Allow intrapacket HiGig2 message generation. Relevant only if HiGig2 message generation is enabled. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_pause_pkt_interval_s cn; */
} bdk_cgxx_smux_tx_pause_pkt_interval_t;

static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020120ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_PAUSE_PKT_INTERVAL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(a,b) bdk_cgxx_smux_tx_pause_pkt_interval_t
#define bustype_BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(a,b) "CGXX_SMUX_TX_PAUSE_PKT_INTERVAL"
#define device_bar_BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_PAUSE_PKT_INTERVAL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_pause_pkt_time
 *
 * CGX SMU TX PAUSE Packet Time Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_pause_pkt_time_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t p_time                : 16; /**< [ 15:  0](R/W) Provides the pause_time field placed in outbound 802.3 PAUSE packets, HiGig2 messages, or
                                                                 PFC packets in 512 bit-times. Normally, [P_TIME] >
                                                                 CGX()_SMU()_TX_PAUSE_PKT_INTERVAL[INTERVAL]. See programming notes in
                                                                 CGX()_SMU()_TX_PAUSE_PKT_INTERVAL. */
#else /* Word 0 - Little Endian */
        uint64_t p_time                : 16; /**< [ 15:  0](R/W) Provides the pause_time field placed in outbound 802.3 PAUSE packets, HiGig2 messages, or
                                                                 PFC packets in 512 bit-times. Normally, [P_TIME] >
                                                                 CGX()_SMU()_TX_PAUSE_PKT_INTERVAL[INTERVAL]. See programming notes in
                                                                 CGX()_SMU()_TX_PAUSE_PKT_INTERVAL. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_pause_pkt_time_s cn; */
} bdk_cgxx_smux_tx_pause_pkt_time_t;

static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020110ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_PAUSE_PKT_TIME", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(a,b) bdk_cgxx_smux_tx_pause_pkt_time_t
#define bustype_BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(a,b) "CGXX_SMUX_TX_PAUSE_PKT_TIME"
#define device_bar_BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_PAUSE_PKT_TIME(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_pause_pkt_type
 *
 * CGX SMU TX PAUSE-Packet P_TYPE-Field Registers
 * This register provides the P_TYPE field that is placed in outbound PAUSE packets.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_pause_pkt_type_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t p_type                : 16; /**< [ 15:  0](R/W) The P_TYPE field that is placed in outbound PAUSE packets. */
#else /* Word 0 - Little Endian */
        uint64_t p_type                : 16; /**< [ 15:  0](R/W) The P_TYPE field that is placed in outbound PAUSE packets. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_pause_pkt_type_s cn; */
} bdk_cgxx_smux_tx_pause_pkt_type_t;

static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020170ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_PAUSE_PKT_TYPE", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(a,b) bdk_cgxx_smux_tx_pause_pkt_type_t
#define bustype_BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(a,b) "CGXX_SMUX_TX_PAUSE_PKT_TYPE"
#define device_bar_BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_PAUSE_PKT_TYPE(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_pause_togo
 *
 * CGX SMU TX Time-to-Backpressure Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_pause_togo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t msg_time              : 16; /**< [ 31: 16](RO/H) Amount of time remaining to backpressure, from the HiGig2 physical message PAUSE timer
                                                                 (only valid on port0). */
        uint64_t p_time                : 16; /**< [ 15:  0](RO/H) Amount of time remaining to backpressure, from the standard 802.3 PAUSE timer. */
#else /* Word 0 - Little Endian */
        uint64_t p_time                : 16; /**< [ 15:  0](RO/H) Amount of time remaining to backpressure, from the standard 802.3 PAUSE timer. */
        uint64_t msg_time              : 16; /**< [ 31: 16](RO/H) Amount of time remaining to backpressure, from the HiGig2 physical message PAUSE timer
                                                                 (only valid on port0). */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_pause_togo_s cn; */
} bdk_cgxx_smux_tx_pause_togo_t;

static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_TOGO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_TOGO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020130ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_PAUSE_TOGO", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_PAUSE_TOGO(a,b) bdk_cgxx_smux_tx_pause_togo_t
#define bustype_BDK_CGXX_SMUX_TX_PAUSE_TOGO(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_PAUSE_TOGO(a,b) "CGXX_SMUX_TX_PAUSE_TOGO"
#define device_bar_BDK_CGXX_SMUX_TX_PAUSE_TOGO(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_PAUSE_TOGO(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_PAUSE_TOGO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_pause_zero
 *
 * CGX SMU TX PAUSE Zero Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_pause_zero_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t send                  : 1;  /**< [  0:  0](R/W) Send PAUSE-zero enable. When this bit is set, and the backpressure condition is clear, it
                                                                 allows sending a PAUSE packet with pause_time of 0 to enable the channel. */
#else /* Word 0 - Little Endian */
        uint64_t send                  : 1;  /**< [  0:  0](R/W) Send PAUSE-zero enable. When this bit is set, and the backpressure condition is clear, it
                                                                 allows sending a PAUSE packet with pause_time of 0 to enable the channel. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_pause_zero_s cn; */
} bdk_cgxx_smux_tx_pause_zero_t;

static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_ZERO(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_PAUSE_ZERO(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020138ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_PAUSE_ZERO", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_PAUSE_ZERO(a,b) bdk_cgxx_smux_tx_pause_zero_t
#define bustype_BDK_CGXX_SMUX_TX_PAUSE_ZERO(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_PAUSE_ZERO(a,b) "CGXX_SMUX_TX_PAUSE_ZERO"
#define device_bar_BDK_CGXX_SMUX_TX_PAUSE_ZERO(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_PAUSE_ZERO(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_PAUSE_ZERO(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_soft_pause
 *
 * CGX SMU TX Soft PAUSE Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_soft_pause_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t p_time                : 16; /**< [ 15:  0](R/W) Back off the TX bus for ([P_TIME] * 512) bit-times */
#else /* Word 0 - Little Endian */
        uint64_t p_time                : 16; /**< [ 15:  0](R/W) Back off the TX bus for ([P_TIME] * 512) bit-times */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_soft_pause_s cn; */
} bdk_cgxx_smux_tx_soft_pause_t;

static inline uint64_t BDK_CGXX_SMUX_TX_SOFT_PAUSE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_SOFT_PAUSE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020128ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_SOFT_PAUSE", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_SOFT_PAUSE(a,b) bdk_cgxx_smux_tx_soft_pause_t
#define bustype_BDK_CGXX_SMUX_TX_SOFT_PAUSE(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_SOFT_PAUSE(a,b) "CGXX_SMUX_TX_SOFT_PAUSE"
#define device_bar_BDK_CGXX_SMUX_TX_SOFT_PAUSE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_SOFT_PAUSE(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_SOFT_PAUSE(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_smu#_tx_thresh
 *
 * CGX SMU TX Threshold Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_smux_tx_thresh_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t cnt                   : 11; /**< [ 10:  0](R/W) Number of 128-bit words to accumulate in the TX FIFO before sending on the packet
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0.

                                                                 In all modes, this register cannot exceed the TX FIFO depth configured by
                                                                 CGX()_CMR_TX_LMACS[LMACS]. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 11; /**< [ 10:  0](R/W) Number of 128-bit words to accumulate in the TX FIFO before sending on the packet
                                                                 interface. This field should be large enough to prevent underflow on the packet interface
                                                                 and must never be set to 0x0.

                                                                 In all modes, this register cannot exceed the TX FIFO depth configured by
                                                                 CGX()_CMR_TX_LMACS[LMACS]. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_smux_tx_thresh_s cn; */
} bdk_cgxx_smux_tx_thresh_t;

static inline uint64_t BDK_CGXX_SMUX_TX_THRESH(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SMUX_TX_THRESH(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8020180ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SMUX_TX_THRESH", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SMUX_TX_THRESH(a,b) bdk_cgxx_smux_tx_thresh_t
#define bustype_BDK_CGXX_SMUX_TX_THRESH(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SMUX_TX_THRESH(a,b) "CGXX_SMUX_TX_THRESH"
#define device_bar_BDK_CGXX_SMUX_TX_THRESH(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SMUX_TX_THRESH(a,b) (a)
#define arguments_BDK_CGXX_SMUX_TX_THRESH(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_adv
 *
 * CGX SPU Autonegotiation Advertisement Registers
 * Software programs this register with the contents of the AN-link code word base page to be
 * transmitted during autonegotiation. (See Std 802.3 section 73.6 for details.) Any write
 * operations to this register prior to completion of autonegotiation, as indicated by
 * CGX()_SPU()_AN_STATUS[AN_COMPLETE], should be followed by a renegotiation in order for
 * the new values to take effect. Renegotiation is initiated by setting
 * CGX()_SPU()_AN_CONTROL[AN_RESTART]. Once autonegotiation has completed, software can
 * examine this register along with CGX()_SPU()_AN_LP_BASE to determine the highest
 * common denominator technology.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_adv_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t fec_req               : 1;  /**< [ 47: 47](R/W) FEC requested. */
        uint64_t fec_able              : 1;  /**< [ 46: 46](R/W) FEC ability. */
        uint64_t arsv                  : 19; /**< [ 45: 27](R/W) Technology ability. Reserved bits, should always be 0. */
        uint64_t a100g_cr10            : 1;  /**< [ 26: 26](R/W) 100GBASE-CR10 ability. Should always be 0; 100GBASE-R is not supported. */
        uint64_t a40g_cr4              : 1;  /**< [ 25: 25](R/W) 40GBASE-CR4 ability. */
        uint64_t a40g_kr4              : 1;  /**< [ 24: 24](R/W) 40GBASE-KR4 ability. */
        uint64_t a10g_kr               : 1;  /**< [ 23: 23](R/W) 10GBASE-KR ability. */
        uint64_t a10g_kx4              : 1;  /**< [ 22: 22](R/W) 10GBASE-KX4 ability. */
        uint64_t a1g_kx                : 1;  /**< [ 21: 21](R/W) 1000BASE-KX ability. Should always be 0; autonegotiation is not supported for 1000Base-KX. */
        uint64_t t                     : 5;  /**< [ 20: 16](R/W/H) Transmitted nonce. This field is automatically updated with a pseudo-random value on entry
                                                                 to the AN ability detect state. */
        uint64_t np                    : 1;  /**< [ 15: 15](R/W) Next page. Always 0; extended next pages are not used for 10G+ autonegotiation. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge. Always 0 in this register. */
        uint64_t rf                    : 1;  /**< [ 13: 13](R/W) Remote fault. */
        uint64_t xnp_able              : 1;  /**< [ 12: 12](R/W) Extended next page ability. */
        uint64_t asm_dir               : 1;  /**< [ 11: 11](R/W) Asymmetric PAUSE. */
        uint64_t pause                 : 1;  /**< [ 10: 10](R/W) PAUSE ability. */
        uint64_t e                     : 5;  /**< [  9:  5](R/W) Echoed nonce. Provides the echoed-nonce value to use when ACK = 0 in transmitted DME page.
                                                                 Should always be 0x0. */
        uint64_t s                     : 5;  /**< [  4:  0](R/W) Selector. Should be 0x1 (encoding for IEEE Std 802.3). */
#else /* Word 0 - Little Endian */
        uint64_t s                     : 5;  /**< [  4:  0](R/W) Selector. Should be 0x1 (encoding for IEEE Std 802.3). */
        uint64_t e                     : 5;  /**< [  9:  5](R/W) Echoed nonce. Provides the echoed-nonce value to use when ACK = 0 in transmitted DME page.
                                                                 Should always be 0x0. */
        uint64_t pause                 : 1;  /**< [ 10: 10](R/W) PAUSE ability. */
        uint64_t asm_dir               : 1;  /**< [ 11: 11](R/W) Asymmetric PAUSE. */
        uint64_t xnp_able              : 1;  /**< [ 12: 12](R/W) Extended next page ability. */
        uint64_t rf                    : 1;  /**< [ 13: 13](R/W) Remote fault. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge. Always 0 in this register. */
        uint64_t np                    : 1;  /**< [ 15: 15](R/W) Next page. Always 0; extended next pages are not used for 10G+ autonegotiation. */
        uint64_t t                     : 5;  /**< [ 20: 16](R/W/H) Transmitted nonce. This field is automatically updated with a pseudo-random value on entry
                                                                 to the AN ability detect state. */
        uint64_t a1g_kx                : 1;  /**< [ 21: 21](R/W) 1000BASE-KX ability. Should always be 0; autonegotiation is not supported for 1000Base-KX. */
        uint64_t a10g_kx4              : 1;  /**< [ 22: 22](R/W) 10GBASE-KX4 ability. */
        uint64_t a10g_kr               : 1;  /**< [ 23: 23](R/W) 10GBASE-KR ability. */
        uint64_t a40g_kr4              : 1;  /**< [ 24: 24](R/W) 40GBASE-KR4 ability. */
        uint64_t a40g_cr4              : 1;  /**< [ 25: 25](R/W) 40GBASE-CR4 ability. */
        uint64_t a100g_cr10            : 1;  /**< [ 26: 26](R/W) 100GBASE-CR10 ability. Should always be 0; 100GBASE-R is not supported. */
        uint64_t arsv                  : 19; /**< [ 45: 27](R/W) Technology ability. Reserved bits, should always be 0. */
        uint64_t fec_able              : 1;  /**< [ 46: 46](R/W) FEC ability. */
        uint64_t fec_req               : 1;  /**< [ 47: 47](R/W) FEC requested. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_adv_s cn; */
} bdk_cgxx_spux_an_adv_t;

static inline uint64_t BDK_CGXX_SPUX_AN_ADV(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_ADV(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100d8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_ADV", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_ADV(a,b) bdk_cgxx_spux_an_adv_t
#define bustype_BDK_CGXX_SPUX_AN_ADV(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_ADV(a,b) "CGXX_SPUX_AN_ADV"
#define device_bar_BDK_CGXX_SPUX_AN_ADV(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_ADV(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_ADV(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_bp_status
 *
 * CGX SPU Autonegotiation Backplane Ethernet & BASE-R Copper Status Registers
 * The contents of this register are updated
 * during autonegotiation and are valid when CGX()_SPU()_AN_STATUS[AN_COMPLETE] is set.
 * At that time, one of the port type bits ([N100G_CR10], [N40G_CR4], [N40G_KR4], [N10G_KR],
 * [N10G_KX4],
 * [N1G_KX]) will be set depending on the AN priority resolution. If a BASE-R type is negotiated,
 * then [FEC] will be set to indicate that FEC operation has been negotiated, and will be
 * clear otherwise.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_bp_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_9_63         : 55;
        uint64_t n100g_cr10            : 1;  /**< [  8:  8](RO/H) 100GBASE-CR10 negotiated; expected to always be 0; 100GBASE-R is not supported. */
        uint64_t reserved_7            : 1;
        uint64_t n40g_cr4              : 1;  /**< [  6:  6](RO/H) 40GBASE-CR4 negotiated. */
        uint64_t n40g_kr4              : 1;  /**< [  5:  5](RO/H) 40GBASE-KR4 negotiated. */
        uint64_t fec                   : 1;  /**< [  4:  4](RO/H) BASE-R FEC negotiated. */
        uint64_t n10g_kr               : 1;  /**< [  3:  3](RO/H) 10GBASE-KR negotiated. */
        uint64_t n10g_kx4              : 1;  /**< [  2:  2](RO/H) 10GBASE-KX4 or CX4 negotiated (XAUI). */
        uint64_t n1g_kx                : 1;  /**< [  1:  1](RO/H) 1000BASE-KX negotiated. */
        uint64_t bp_an_able            : 1;  /**< [  0:  0](RO) Backplane or BASE-R copper AN Ability; always 1. */
#else /* Word 0 - Little Endian */
        uint64_t bp_an_able            : 1;  /**< [  0:  0](RO) Backplane or BASE-R copper AN Ability; always 1. */
        uint64_t n1g_kx                : 1;  /**< [  1:  1](RO/H) 1000BASE-KX negotiated. */
        uint64_t n10g_kx4              : 1;  /**< [  2:  2](RO/H) 10GBASE-KX4 or CX4 negotiated (XAUI). */
        uint64_t n10g_kr               : 1;  /**< [  3:  3](RO/H) 10GBASE-KR negotiated. */
        uint64_t fec                   : 1;  /**< [  4:  4](RO/H) BASE-R FEC negotiated. */
        uint64_t n40g_kr4              : 1;  /**< [  5:  5](RO/H) 40GBASE-KR4 negotiated. */
        uint64_t n40g_cr4              : 1;  /**< [  6:  6](RO/H) 40GBASE-CR4 negotiated. */
        uint64_t reserved_7            : 1;
        uint64_t n100g_cr10            : 1;  /**< [  8:  8](RO/H) 100GBASE-CR10 negotiated; expected to always be 0; 100GBASE-R is not supported. */
        uint64_t reserved_9_63         : 55;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_bp_status_s cn; */
} bdk_cgxx_spux_an_bp_status_t;

static inline uint64_t BDK_CGXX_SPUX_AN_BP_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_BP_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100f8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_BP_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_BP_STATUS(a,b) bdk_cgxx_spux_an_bp_status_t
#define bustype_BDK_CGXX_SPUX_AN_BP_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_BP_STATUS(a,b) "CGXX_SPUX_AN_BP_STATUS"
#define device_bar_BDK_CGXX_SPUX_AN_BP_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_BP_STATUS(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_BP_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_control
 *
 * CGX SPU Autonegotiation Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t an_reset              : 1;  /**< [ 15: 15](R/W1S/H) Autonegotiation reset. Setting this bit or CGX()_SPU()_CONTROL1[RESET] to 1
                                                                 causes the following to happen:
                                                                 * Resets the logical PCS (LPCS)
                                                                 * Sets the Std 802.3 PCS, FEC and AN registers for the LPCS to their default states
                                                                 * Resets the associated SerDes lanes.

                                                                 It takes up to 32 coprocessor-clock cycles to reset the LPCS, after which RESET is
                                                                 automatically cleared. */
        uint64_t reserved_14           : 1;
        uint64_t xnp_en                : 1;  /**< [ 13: 13](R/W) Extended next-page enable. */
        uint64_t an_en                 : 1;  /**< [ 12: 12](R/W) Autonegotiation enable. This bit should not be set when
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is set to RXAUI; autonegotiation is not supported
                                                                 in RXAUI mode. */
        uint64_t reserved_10_11        : 2;
        uint64_t an_restart            : 1;  /**< [  9:  9](R/W1S/H) Autonegotiation restart. Writing a 1 to this bit restarts the autonegotiation process if
                                                                 [AN_EN] is also set. This is a self-clearing bit. */
        uint64_t reserved_0_8          : 9;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_8          : 9;
        uint64_t an_restart            : 1;  /**< [  9:  9](R/W1S/H) Autonegotiation restart. Writing a 1 to this bit restarts the autonegotiation process if
                                                                 [AN_EN] is also set. This is a self-clearing bit. */
        uint64_t reserved_10_11        : 2;
        uint64_t an_en                 : 1;  /**< [ 12: 12](R/W) Autonegotiation enable. This bit should not be set when
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is set to RXAUI; autonegotiation is not supported
                                                                 in RXAUI mode. */
        uint64_t xnp_en                : 1;  /**< [ 13: 13](R/W) Extended next-page enable. */
        uint64_t reserved_14           : 1;
        uint64_t an_reset              : 1;  /**< [ 15: 15](R/W1S/H) Autonegotiation reset. Setting this bit or CGX()_SPU()_CONTROL1[RESET] to 1
                                                                 causes the following to happen:
                                                                 * Resets the logical PCS (LPCS)
                                                                 * Sets the Std 802.3 PCS, FEC and AN registers for the LPCS to their default states
                                                                 * Resets the associated SerDes lanes.

                                                                 It takes up to 32 coprocessor-clock cycles to reset the LPCS, after which RESET is
                                                                 automatically cleared. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_control_s cn; */
} bdk_cgxx_spux_an_control_t;

static inline uint64_t BDK_CGXX_SPUX_AN_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100c8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_CONTROL(a,b) bdk_cgxx_spux_an_control_t
#define bustype_BDK_CGXX_SPUX_AN_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_CONTROL(a,b) "CGXX_SPUX_AN_CONTROL"
#define device_bar_BDK_CGXX_SPUX_AN_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_lp_base
 *
 * CGX SPU Autonegotiation Link-Partner Base-Page Ability Registers
 * This register captures the contents of the latest AN link code word base page received from
 * the link partner during autonegotiation. (See Std 802.3 section 73.6 for details.)
 * CGX()_SPU()_AN_STATUS[PAGE_RX] is set when this register is updated by hardware.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_lp_base_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t fec_req               : 1;  /**< [ 47: 47](RO/H) FEC requested. */
        uint64_t fec_able              : 1;  /**< [ 46: 46](RO/H) FEC ability. */
        uint64_t arsv                  : 19; /**< [ 45: 27](RO/H) Technology ability. Reserved bits, should always be 0. */
        uint64_t a100g_cr10            : 1;  /**< [ 26: 26](RO/H) 100GBASE-CR10 ability. */
        uint64_t a40g_cr4              : 1;  /**< [ 25: 25](RO/H) 40GBASE-CR4 ability. */
        uint64_t a40g_kr4              : 1;  /**< [ 24: 24](RO/H) 40GBASE-KR4 ability. */
        uint64_t a10g_kr               : 1;  /**< [ 23: 23](RO/H) 10GBASE-KR ability. */
        uint64_t a10g_kx4              : 1;  /**< [ 22: 22](RO/H) 10GBASE-KX4 ability. */
        uint64_t a1g_kx                : 1;  /**< [ 21: 21](RO/H) 1000BASE-KX ability. */
        uint64_t t                     : 5;  /**< [ 20: 16](RO/H) Transmitted nonce. */
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge. */
        uint64_t rf                    : 1;  /**< [ 13: 13](RO/H) Remote fault. */
        uint64_t xnp_able              : 1;  /**< [ 12: 12](RO/H) Extended next page ability. */
        uint64_t asm_dir               : 1;  /**< [ 11: 11](RO/H) Asymmetric PAUSE. */
        uint64_t pause                 : 1;  /**< [ 10: 10](RO/H) PAUSE ability. */
        uint64_t e                     : 5;  /**< [  9:  5](RO/H) Echoed nonce. */
        uint64_t s                     : 5;  /**< [  4:  0](RO/H) Selector. */
#else /* Word 0 - Little Endian */
        uint64_t s                     : 5;  /**< [  4:  0](RO/H) Selector. */
        uint64_t e                     : 5;  /**< [  9:  5](RO/H) Echoed nonce. */
        uint64_t pause                 : 1;  /**< [ 10: 10](RO/H) PAUSE ability. */
        uint64_t asm_dir               : 1;  /**< [ 11: 11](RO/H) Asymmetric PAUSE. */
        uint64_t xnp_able              : 1;  /**< [ 12: 12](RO/H) Extended next page ability. */
        uint64_t rf                    : 1;  /**< [ 13: 13](RO/H) Remote fault. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge. */
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page. */
        uint64_t t                     : 5;  /**< [ 20: 16](RO/H) Transmitted nonce. */
        uint64_t a1g_kx                : 1;  /**< [ 21: 21](RO/H) 1000BASE-KX ability. */
        uint64_t a10g_kx4              : 1;  /**< [ 22: 22](RO/H) 10GBASE-KX4 ability. */
        uint64_t a10g_kr               : 1;  /**< [ 23: 23](RO/H) 10GBASE-KR ability. */
        uint64_t a40g_kr4              : 1;  /**< [ 24: 24](RO/H) 40GBASE-KR4 ability. */
        uint64_t a40g_cr4              : 1;  /**< [ 25: 25](RO/H) 40GBASE-CR4 ability. */
        uint64_t a100g_cr10            : 1;  /**< [ 26: 26](RO/H) 100GBASE-CR10 ability. */
        uint64_t arsv                  : 19; /**< [ 45: 27](RO/H) Technology ability. Reserved bits, should always be 0. */
        uint64_t fec_able              : 1;  /**< [ 46: 46](RO/H) FEC ability. */
        uint64_t fec_req               : 1;  /**< [ 47: 47](RO/H) FEC requested. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_lp_base_s cn; */
} bdk_cgxx_spux_an_lp_base_t;

static inline uint64_t BDK_CGXX_SPUX_AN_LP_BASE(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_LP_BASE(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100e0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_LP_BASE", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_LP_BASE(a,b) bdk_cgxx_spux_an_lp_base_t
#define bustype_BDK_CGXX_SPUX_AN_LP_BASE(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_LP_BASE(a,b) "CGXX_SPUX_AN_LP_BASE"
#define device_bar_BDK_CGXX_SPUX_AN_LP_BASE(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_LP_BASE(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_LP_BASE(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_lp_xnp
 *
 * CGX SPU Autonegotiation Link Partner Extended Next Page Ability Registers
 * This register captures the contents of the latest next page code word received from the link
 * partner during autonegotiation, if any. See section 802.3 section 73.7.7 for details.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_lp_xnp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t u                     : 32; /**< [ 47: 16](RO/H) Unformatted code field. */
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge. */
        uint64_t mp                    : 1;  /**< [ 13: 13](RO/H) Message page. */
        uint64_t ack2                  : 1;  /**< [ 12: 12](RO/H) Acknowledge 2. */
        uint64_t toggle                : 1;  /**< [ 11: 11](RO/H) Toggle. */
        uint64_t m_u                   : 11; /**< [ 10:  0](RO/H) Message/unformatted code field. */
#else /* Word 0 - Little Endian */
        uint64_t m_u                   : 11; /**< [ 10:  0](RO/H) Message/unformatted code field. */
        uint64_t toggle                : 1;  /**< [ 11: 11](RO/H) Toggle. */
        uint64_t ack2                  : 1;  /**< [ 12: 12](RO/H) Acknowledge 2. */
        uint64_t mp                    : 1;  /**< [ 13: 13](RO/H) Message page. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge. */
        uint64_t np                    : 1;  /**< [ 15: 15](RO/H) Next page. */
        uint64_t u                     : 32; /**< [ 47: 16](RO/H) Unformatted code field. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_lp_xnp_s cn; */
} bdk_cgxx_spux_an_lp_xnp_t;

static inline uint64_t BDK_CGXX_SPUX_AN_LP_XNP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_LP_XNP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100f0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_LP_XNP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_LP_XNP(a,b) bdk_cgxx_spux_an_lp_xnp_t
#define bustype_BDK_CGXX_SPUX_AN_LP_XNP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_LP_XNP(a,b) "CGXX_SPUX_AN_LP_XNP"
#define device_bar_BDK_CGXX_SPUX_AN_LP_XNP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_LP_XNP(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_LP_XNP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_status
 *
 * CGX SPU Autonegotiation Status Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_10_63        : 54;
        uint64_t prl_flt               : 1;  /**< [  9:  9](RO) Parallel detection fault. Always 0; SPU does not support parallel detection as part of the
                                                                 autonegotiation protocol. */
        uint64_t reserved_8            : 1;
        uint64_t xnp_stat              : 1;  /**< [  7:  7](RO/H) Extended next-page status. */
        uint64_t page_rx               : 1;  /**< [  6:  6](R/W1C/H) Page received. This latching-high bit is set when a new page has been received and stored
                                                                 in CGX()_SPU()_AN_LP_BASE or CGX()_SPU()_AN_LP_XNP; stays set until a 1 is
                                                                 written by software, autonegotiation is disabled or restarted, or next page exchange is
                                                                 initiated. Note that in order to avoid read side effects, this is implemented as a
                                                                 write-1-to-clear bit, rather than latching high read-only as specified in 802.3. */
        uint64_t an_complete           : 1;  /**< [  5:  5](RO/H) Autonegotiation complete. Set when the autonegotiation process has been completed and
                                                                 the link is up and running using the negotiated highest common denominator (HCD)
                                                                 technology. If AN is enabled (CGX()_SPU()_AN_CONTROL[AN_EN] = 1) and this bit is
                                                                 read as a zero, it indicates that the AN process has not been completed, and the contents
                                                                 of CGX()_SPU()_AN_LP_BASE, CGX()_SPU()_AN_XNP_TX, and
                                                                 CGX()_SPU()_AN_LP_XNP are as defined by the current state of the autonegotiation
                                                                 protocol, or as written for manual configuration. This bit is always zero when AN is
                                                                 disabled (CGX()_SPU()_AN_CONTROL[AN_EN] = 0). */
        uint64_t rmt_flt               : 1;  /**< [  4:  4](RO) Remote fault: Always 0. */
        uint64_t an_able               : 1;  /**< [  3:  3](RO) Autonegotiation ability: Always 1. */
        uint64_t link_status           : 1;  /**< [  2:  2](R/W1S/H) Link status. This bit captures the state of the link_status variable as defined in 802.3
                                                                 section 73.9.1. When set, indicates that a valid link has been established. When clear,
                                                                 indicates that the link has been invalid after this bit was last set by software. Latching
                                                                 low bit; stays clear until a 1 is written by software. Note that in order to avoid read
                                                                 side effects, this is implemented as a write-1-to-set bit, rather than latching low read-
                                                                 only as specified in 802.3. */
        uint64_t reserved_1            : 1;
        uint64_t lp_an_able            : 1;  /**< [  0:  0](RO/H) Link partner autonegotiation ability. Set to indicate that the link partner is able to
                                                                 participate in the autonegotiation function, and cleared otherwise. */
#else /* Word 0 - Little Endian */
        uint64_t lp_an_able            : 1;  /**< [  0:  0](RO/H) Link partner autonegotiation ability. Set to indicate that the link partner is able to
                                                                 participate in the autonegotiation function, and cleared otherwise. */
        uint64_t reserved_1            : 1;
        uint64_t link_status           : 1;  /**< [  2:  2](R/W1S/H) Link status. This bit captures the state of the link_status variable as defined in 802.3
                                                                 section 73.9.1. When set, indicates that a valid link has been established. When clear,
                                                                 indicates that the link has been invalid after this bit was last set by software. Latching
                                                                 low bit; stays clear until a 1 is written by software. Note that in order to avoid read
                                                                 side effects, this is implemented as a write-1-to-set bit, rather than latching low read-
                                                                 only as specified in 802.3. */
        uint64_t an_able               : 1;  /**< [  3:  3](RO) Autonegotiation ability: Always 1. */
        uint64_t rmt_flt               : 1;  /**< [  4:  4](RO) Remote fault: Always 0. */
        uint64_t an_complete           : 1;  /**< [  5:  5](RO/H) Autonegotiation complete. Set when the autonegotiation process has been completed and
                                                                 the link is up and running using the negotiated highest common denominator (HCD)
                                                                 technology. If AN is enabled (CGX()_SPU()_AN_CONTROL[AN_EN] = 1) and this bit is
                                                                 read as a zero, it indicates that the AN process has not been completed, and the contents
                                                                 of CGX()_SPU()_AN_LP_BASE, CGX()_SPU()_AN_XNP_TX, and
                                                                 CGX()_SPU()_AN_LP_XNP are as defined by the current state of the autonegotiation
                                                                 protocol, or as written for manual configuration. This bit is always zero when AN is
                                                                 disabled (CGX()_SPU()_AN_CONTROL[AN_EN] = 0). */
        uint64_t page_rx               : 1;  /**< [  6:  6](R/W1C/H) Page received. This latching-high bit is set when a new page has been received and stored
                                                                 in CGX()_SPU()_AN_LP_BASE or CGX()_SPU()_AN_LP_XNP; stays set until a 1 is
                                                                 written by software, autonegotiation is disabled or restarted, or next page exchange is
                                                                 initiated. Note that in order to avoid read side effects, this is implemented as a
                                                                 write-1-to-clear bit, rather than latching high read-only as specified in 802.3. */
        uint64_t xnp_stat              : 1;  /**< [  7:  7](RO/H) Extended next-page status. */
        uint64_t reserved_8            : 1;
        uint64_t prl_flt               : 1;  /**< [  9:  9](RO) Parallel detection fault. Always 0; SPU does not support parallel detection as part of the
                                                                 autonegotiation protocol. */
        uint64_t reserved_10_63        : 54;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_status_s cn; */
} bdk_cgxx_spux_an_status_t;

static inline uint64_t BDK_CGXX_SPUX_AN_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100d0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_STATUS(a,b) bdk_cgxx_spux_an_status_t
#define bustype_BDK_CGXX_SPUX_AN_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_STATUS(a,b) "CGXX_SPUX_AN_STATUS"
#define device_bar_BDK_CGXX_SPUX_AN_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_STATUS(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_an_xnp_tx
 *
 * CGX SPU Autonegotiation Extended Next Page Transmit Registers
 * Software programs this register with the contents of the AN message next page or unformatted
 * next page link code word to be transmitted during autonegotiation. Next page exchange occurs
 * after the base link code words have been exchanged if either end of the link segment sets the
 * NP bit to 1, indicating that it has at least one next page to send. Once initiated, next page
 * exchange continues until both ends of the link segment set their NP bits to 0. See section
 * 802.3 section 73.7.7 for details.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_an_xnp_tx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t u                     : 32; /**< [ 47: 16](R/W) Unformatted code field. When the MP bit is set, this field contains the 32-bit unformatted
                                                                 code field of the message next page. When MP is clear, this field contains the upper 32
                                                                 bits of the 43-bit unformatted code field of the unformatted next page. */
        uint64_t np                    : 1;  /**< [ 15: 15](R/W) Next page. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge: Always 0 in this register. */
        uint64_t mp                    : 1;  /**< [ 13: 13](R/W) Message page. Set to indicate that this register contains a message next page. Clear to
                                                                 indicate that the register contains an unformatted next page. */
        uint64_t ack2                  : 1;  /**< [ 12: 12](R/W) Acknowledge 2. Indicates that the receiver is able to act on the information (or perform
                                                                 the task) defined in the message. */
        uint64_t toggle                : 1;  /**< [ 11: 11](R/W) This bit is ignored by hardware. The value of the TOGGLE bit in transmitted next pages is
                                                                 automatically generated by hardware. */
        uint64_t m_u                   : 11; /**< [ 10:  0](R/W) Message/unformatted code field: When the MP bit is set, this field contains the message
                                                                 code field (M) of the message next page. When MP is clear, this field contains the lower
                                                                 11 bits of the 43-bit unformatted code field of the unformatted next page. */
#else /* Word 0 - Little Endian */
        uint64_t m_u                   : 11; /**< [ 10:  0](R/W) Message/unformatted code field: When the MP bit is set, this field contains the message
                                                                 code field (M) of the message next page. When MP is clear, this field contains the lower
                                                                 11 bits of the 43-bit unformatted code field of the unformatted next page. */
        uint64_t toggle                : 1;  /**< [ 11: 11](R/W) This bit is ignored by hardware. The value of the TOGGLE bit in transmitted next pages is
                                                                 automatically generated by hardware. */
        uint64_t ack2                  : 1;  /**< [ 12: 12](R/W) Acknowledge 2. Indicates that the receiver is able to act on the information (or perform
                                                                 the task) defined in the message. */
        uint64_t mp                    : 1;  /**< [ 13: 13](R/W) Message page. Set to indicate that this register contains a message next page. Clear to
                                                                 indicate that the register contains an unformatted next page. */
        uint64_t ack                   : 1;  /**< [ 14: 14](RO/H) Acknowledge: Always 0 in this register. */
        uint64_t np                    : 1;  /**< [ 15: 15](R/W) Next page. */
        uint64_t u                     : 32; /**< [ 47: 16](R/W) Unformatted code field. When the MP bit is set, this field contains the 32-bit unformatted
                                                                 code field of the message next page. When MP is clear, this field contains the upper 32
                                                                 bits of the 43-bit unformatted code field of the unformatted next page. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_an_xnp_tx_s cn; */
} bdk_cgxx_spux_an_xnp_tx_t;

static inline uint64_t BDK_CGXX_SPUX_AN_XNP_TX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_AN_XNP_TX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100e8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_AN_XNP_TX", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_AN_XNP_TX(a,b) bdk_cgxx_spux_an_xnp_tx_t
#define bustype_BDK_CGXX_SPUX_AN_XNP_TX(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_AN_XNP_TX(a,b) "CGXX_SPUX_AN_XNP_TX"
#define device_bar_BDK_CGXX_SPUX_AN_XNP_TX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_AN_XNP_TX(a,b) (a)
#define arguments_BDK_CGXX_SPUX_AN_XNP_TX(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_algn_status
 *
 * CGX SPU Multilane BASE-R PCS Alignment-Status Registers
 * This register implements the Std 802.3 multilane BASE-R PCS alignment status 1-4 registers
 * (3.50-3.53). It is valid only when the LPCS type is 40GBASE-R
 * (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), and always returns 0x0 for all other LPCS
 * types. Std 802.3 bits that are not applicable to 40GBASE-R (e.g. status bits for PCS lanes
 * 19-4) are not implemented and marked as reserved. PCS lanes 3-0 are valid and are mapped to
 * physical SerDes lanes based on the programming of CGX()_CMR()_CONFIG[LANE_TO_SDS].
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_algn_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_36_63        : 28;
        uint64_t marker_lock           : 4;  /**< [ 35: 32](RO/H) Marker-locked status for PCS lanes 3-0.
                                                                 0 = Not locked.
                                                                 1 = Locked. */
        uint64_t reserved_13_31        : 19;
        uint64_t alignd                : 1;  /**< [ 12: 12](RO/H) All lanes are locked and aligned. This bit returns 1 when the logical PCS has locked and
                                                                 aligned all associated receive lanes; returns 0 otherwise. For all other PCS types, this
                                                                 bit always returns 0. */
        uint64_t reserved_4_11         : 8;
        uint64_t block_lock            : 4;  /**< [  3:  0](RO/H) Block-lock status for PCS lanes 3-0:
                                                                   0 = Not locked.
                                                                   1 = Locked. */
#else /* Word 0 - Little Endian */
        uint64_t block_lock            : 4;  /**< [  3:  0](RO/H) Block-lock status for PCS lanes 3-0:
                                                                   0 = Not locked.
                                                                   1 = Locked. */
        uint64_t reserved_4_11         : 8;
        uint64_t alignd                : 1;  /**< [ 12: 12](RO/H) All lanes are locked and aligned. This bit returns 1 when the logical PCS has locked and
                                                                 aligned all associated receive lanes; returns 0 otherwise. For all other PCS types, this
                                                                 bit always returns 0. */
        uint64_t reserved_13_31        : 19;
        uint64_t marker_lock           : 4;  /**< [ 35: 32](RO/H) Marker-locked status for PCS lanes 3-0.
                                                                 0 = Not locked.
                                                                 1 = Locked. */
        uint64_t reserved_36_63        : 28;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_algn_status_s cn; */
} bdk_cgxx_spux_br_algn_status_t;

static inline uint64_t BDK_CGXX_SPUX_BR_ALGN_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_ALGN_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010050ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_ALGN_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_ALGN_STATUS(a,b) bdk_cgxx_spux_br_algn_status_t
#define bustype_BDK_CGXX_SPUX_BR_ALGN_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_ALGN_STATUS(a,b) "CGXX_SPUX_BR_ALGN_STATUS"
#define device_bar_BDK_CGXX_SPUX_BR_ALGN_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_ALGN_STATUS(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_ALGN_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_bip_err_cnt
 *
 * CGX SPU 40GBASE-R BIP Error-Counter Registers
 * This register implements the Std 802.3 BIP error-counter registers for PCS lanes 0-3
 * (3.200-3.203). It is valid only when the LPCS type is 40GBASE-R
 * (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), and always returns 0x0 for all other LPCS
 * types. The counters are indexed by the RX PCS lane number based on the Alignment Marker
 * detected on each lane and captured in CGX()_SPU()_BR_LANE_MAP. Each counter counts the
 * BIP errors for its PCS lane, and is held at all ones in case of overflow. The counters are
 * reset to all 0s when this register is read by software.
 *
 * The reset operation takes precedence over the increment operation; if the register is read on
 * the same clock cycle as an increment operation, the counter is reset to all 0s and the
 * increment operation is lost. The counters are writable for test purposes, rather than read-
 * only as specified in Std 802.3.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_bip_err_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t bip_err_cnt_ln3       : 16; /**< [ 63: 48](RC/W/H) BIP error counter for lane on which PCS lane 3 markers are received. */
        uint64_t bip_err_cnt_ln2       : 16; /**< [ 47: 32](RC/W/H) BIP error counter for lane on which PCS lane 2 markers are received. */
        uint64_t bip_err_cnt_ln1       : 16; /**< [ 31: 16](RC/W/H) BIP error counter for lane on which PCS lane 1 markers are received. */
        uint64_t bip_err_cnt_ln0       : 16; /**< [ 15:  0](RC/W/H) BIP error counter for lane on which PCS lane 0 markers are received. */
#else /* Word 0 - Little Endian */
        uint64_t bip_err_cnt_ln0       : 16; /**< [ 15:  0](RC/W/H) BIP error counter for lane on which PCS lane 0 markers are received. */
        uint64_t bip_err_cnt_ln1       : 16; /**< [ 31: 16](RC/W/H) BIP error counter for lane on which PCS lane 1 markers are received. */
        uint64_t bip_err_cnt_ln2       : 16; /**< [ 47: 32](RC/W/H) BIP error counter for lane on which PCS lane 2 markers are received. */
        uint64_t bip_err_cnt_ln3       : 16; /**< [ 63: 48](RC/W/H) BIP error counter for lane on which PCS lane 3 markers are received. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_bip_err_cnt_s cn; */
} bdk_cgxx_spux_br_bip_err_cnt_t;

static inline uint64_t BDK_CGXX_SPUX_BR_BIP_ERR_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_BIP_ERR_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010058ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_BIP_ERR_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_BIP_ERR_CNT(a,b) bdk_cgxx_spux_br_bip_err_cnt_t
#define bustype_BDK_CGXX_SPUX_BR_BIP_ERR_CNT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_BIP_ERR_CNT(a,b) "CGXX_SPUX_BR_BIP_ERR_CNT"
#define device_bar_BDK_CGXX_SPUX_BR_BIP_ERR_CNT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_BIP_ERR_CNT(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_BIP_ERR_CNT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_lane_map
 *
 * CGX SPU 40GBASE-R Lane-Mapping Registers
 * This register implements the Std 802.3 lane 0-3 mapping registers (3.400-3.403). It is valid
 * only when the LPCS type is 40GBASE-R (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), and always
 * returns 0x0 for all other LPCS types. The LNx_MAPPING field for each programmed PCS lane
 * (called service interface in 802.3ba-2010) is valid when that lane has achieved alignment
 * marker lock on the receive side (i.e. the associated
 * CGX()_SPU()_BR_ALGN_STATUS[MARKER_LOCK] = 1), and is invalid otherwise. When valid, it
 * returns the actual detected receive PCS lane number based on the received alignment marker
 * contents received on that service interface.
 *
 * The mapping is flexible because Std 802.3 allows multilane BASE-R receive lanes to be re-
 * ordered. Note that for the transmit side, each PCS lane is mapped to a physical SerDes lane
 * based on the programming of CGX()_CMR()_CONFIG[LANE_TO_SDS]. For the receive side,
 * CGX()_CMR()_CONFIG[LANE_TO_SDS] specifies the service interface to physical SerDes
 * lane mapping, and this register specifies the PCS lane to service interface mapping.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_lane_map_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_54_63        : 10;
        uint64_t ln3_mapping           : 6;  /**< [ 53: 48](RO/H) PCS lane number received on service interface 3 */
        uint64_t reserved_38_47        : 10;
        uint64_t ln2_mapping           : 6;  /**< [ 37: 32](RO/H) PCS lane number received on service interface 2 */
        uint64_t reserved_22_31        : 10;
        uint64_t ln1_mapping           : 6;  /**< [ 21: 16](RO/H) PCS lane number received on service interface 1 */
        uint64_t reserved_6_15         : 10;
        uint64_t ln0_mapping           : 6;  /**< [  5:  0](RO/H) PCS lane number received on service interface 0 */
#else /* Word 0 - Little Endian */
        uint64_t ln0_mapping           : 6;  /**< [  5:  0](RO/H) PCS lane number received on service interface 0 */
        uint64_t reserved_6_15         : 10;
        uint64_t ln1_mapping           : 6;  /**< [ 21: 16](RO/H) PCS lane number received on service interface 1 */
        uint64_t reserved_22_31        : 10;
        uint64_t ln2_mapping           : 6;  /**< [ 37: 32](RO/H) PCS lane number received on service interface 2 */
        uint64_t reserved_38_47        : 10;
        uint64_t ln3_mapping           : 6;  /**< [ 53: 48](RO/H) PCS lane number received on service interface 3 */
        uint64_t reserved_54_63        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_lane_map_s cn; */
} bdk_cgxx_spux_br_lane_map_t;

static inline uint64_t BDK_CGXX_SPUX_BR_LANE_MAP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_LANE_MAP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010060ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_LANE_MAP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_LANE_MAP(a,b) bdk_cgxx_spux_br_lane_map_t
#define bustype_BDK_CGXX_SPUX_BR_LANE_MAP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_LANE_MAP(a,b) "CGXX_SPUX_BR_LANE_MAP"
#define device_bar_BDK_CGXX_SPUX_BR_LANE_MAP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_LANE_MAP(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_LANE_MAP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_pmd_control
 *
 * CGX SPU 40GBASE-R PMD Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_pmd_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t train_en              : 1;  /**< [  1:  1](R/W) BASE-R training enable. */
        uint64_t train_restart         : 1;  /**< [  0:  0](R/W1S/H) BASE-R training restart. Writing a 1 to this bit restarts the training process if
                                                                 [TRAIN_EN] is also set. This is a self-clearing bit. Software should
                                                                 wait a minimum of 1.7ms after CGX()_SPU()_INT[TRAINING_FAILURE] is set before
                                                                 restarting the training process. */
#else /* Word 0 - Little Endian */
        uint64_t train_restart         : 1;  /**< [  0:  0](R/W1S/H) BASE-R training restart. Writing a 1 to this bit restarts the training process if
                                                                 [TRAIN_EN] is also set. This is a self-clearing bit. Software should
                                                                 wait a minimum of 1.7ms after CGX()_SPU()_INT[TRAINING_FAILURE] is set before
                                                                 restarting the training process. */
        uint64_t train_en              : 1;  /**< [  1:  1](R/W) BASE-R training enable. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_pmd_control_s cn; */
} bdk_cgxx_spux_br_pmd_control_t;

static inline uint64_t BDK_CGXX_SPUX_BR_PMD_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_PMD_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010068ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_PMD_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_PMD_CONTROL(a,b) bdk_cgxx_spux_br_pmd_control_t
#define bustype_BDK_CGXX_SPUX_BR_PMD_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_PMD_CONTROL(a,b) "CGXX_SPUX_BR_PMD_CONTROL"
#define device_bar_BDK_CGXX_SPUX_BR_PMD_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_PMD_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_PMD_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_pmd_ld_cup
 *
 * CGX SPU 40GBASE-R PMD Local Device Coefficient Update Registers
 * This register implements 802.3 MDIO register 1.153 for 10GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R)
 * and MDIO registers 1.1300-1.1303 for 40GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 40G_R). It is automatically cleared at the start of training.
 * When link training
 * is in progress, each field reflects the contents of the coefficient update field in the
 * associated lane's outgoing training frame. The fields in this register are read/write even
 * though they are specified as read-only in 802.3.
 *
 * If CGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is set, then this register must be updated
 * by software during link training and hardware updates are disabled. If
 * CGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is clear, this register is automatically
 * updated by hardware, and it should not be written by software. The lane fields in this
 * register are indexed by logical PCS lane ID.
 *
 * The lane 0 field (LN0_*) is valid for both
 * 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*, LN3_*) are only valid for
 * 40GBASE-R.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_pmd_ld_cup_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln3_cup               : 16; /**< [ 63: 48](R/W/H) PCS lane 3 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_cup               : 16; /**< [ 47: 32](R/W/H) PCS lane 2 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln1_cup               : 16; /**< [ 31: 16](R/W/H) PCS lane 1 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln0_cup               : 16; /**< [ 15:  0](R/W/H) PCS lane 0 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. */
#else /* Word 0 - Little Endian */
        uint64_t ln0_cup               : 16; /**< [ 15:  0](R/W/H) PCS lane 0 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. */
        uint64_t ln1_cup               : 16; /**< [ 31: 16](R/W/H) PCS lane 1 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_cup               : 16; /**< [ 47: 32](R/W/H) PCS lane 2 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln3_cup               : 16; /**< [ 63: 48](R/W/H) PCS lane 3 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_pmd_ld_cup_s cn; */
} bdk_cgxx_spux_br_pmd_ld_cup_t;

static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LD_CUP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LD_CUP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010088ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_PMD_LD_CUP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_PMD_LD_CUP(a,b) bdk_cgxx_spux_br_pmd_ld_cup_t
#define bustype_BDK_CGXX_SPUX_BR_PMD_LD_CUP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_PMD_LD_CUP(a,b) "CGXX_SPUX_BR_PMD_LD_CUP"
#define device_bar_BDK_CGXX_SPUX_BR_PMD_LD_CUP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_PMD_LD_CUP(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_PMD_LD_CUP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_pmd_ld_rep
 *
 * CGX SPU 40GBASE-R PMD Local Device Status Report Registers
 * This register implements 802.3 MDIO register 1.154 for 10GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R) and MDIO registers 1.1400-1.1403 for 40GBASE-R
 * (when CGX()_CMR()_CONFIG[LMAC_TYPE] = 40G_R). It is automatically cleared at the start of
 * training. Each field
 * reflects the contents of the status report field in the associated lane's outgoing training
 * frame. The fields in this register are read/write even though they are specified as read-only
 * in 802.3. If CGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is set, then this register must
 * be updated by software during link training and hardware updates are disabled. If
 * CGX()_SPU_DBG_CONTROL[BR_PMD_TRAIN_SOFT_EN] is clear, this register is automatically
 * updated by hardware, and it should not be written by software. The lane fields in this
 * register are indexed by logical PCS lane ID.
 *
 * The lane 0 field (LN0_*) is valid for both
 * 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*, LN3_*) are only valid for
 * 40GBASE-R.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_pmd_ld_rep_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln3_rep               : 16; /**< [ 63: 48](R/W/H) PCS lane 3 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_rep               : 16; /**< [ 47: 32](R/W/H) PCS lane 2 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln1_rep               : 16; /**< [ 31: 16](R/W/H) PCS lane 1 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln0_rep               : 16; /**< [ 15:  0](R/W/H) PCS lane 0 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. */
#else /* Word 0 - Little Endian */
        uint64_t ln0_rep               : 16; /**< [ 15:  0](R/W/H) PCS lane 0 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. */
        uint64_t ln1_rep               : 16; /**< [ 31: 16](R/W/H) PCS lane 1 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_rep               : 16; /**< [ 47: 32](R/W/H) PCS lane 2 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln3_rep               : 16; /**< [ 63: 48](R/W/H) PCS lane 3 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_pmd_ld_rep_s cn; */
} bdk_cgxx_spux_br_pmd_ld_rep_t;

static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LD_REP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LD_REP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010090ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_PMD_LD_REP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_PMD_LD_REP(a,b) bdk_cgxx_spux_br_pmd_ld_rep_t
#define bustype_BDK_CGXX_SPUX_BR_PMD_LD_REP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_PMD_LD_REP(a,b) "CGXX_SPUX_BR_PMD_LD_REP"
#define device_bar_BDK_CGXX_SPUX_BR_PMD_LD_REP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_PMD_LD_REP(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_PMD_LD_REP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_pmd_lp_cup
 *
 * CGX SPU 40GBASE-R PMD Link Partner Coefficient Update Registers
 * This register implements 802.3 MDIO register 1.152 for 10GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R)
 * and MDIO registers 1.1100-1.1103 for 40GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 40G_R). It is automatically cleared at the start of training.
 * Each field reflects
 * the contents of the coefficient update field in the lane's most recently received training
 * frame. This register should not be written when link training is enabled, i.e. when
 * CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is set. The lane fields in this register are indexed by
 * logical PCS lane ID.
 *
 * The lane 0 field (LN0_*) is valid for both 10GBASE-R and 40GBASE-R. The remaining fields
 * (LN1_*, LN2_*, LN3_*) are only valid for 40GBASE-R.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_pmd_lp_cup_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln3_cup               : 16; /**< [ 63: 48](R/W/H) PCS lane 3 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_cup               : 16; /**< [ 47: 32](R/W/H) PCS lane 2 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln1_cup               : 16; /**< [ 31: 16](R/W/H) PCS lane 1 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln0_cup               : 16; /**< [ 15:  0](R/W/H) PCS lane 0 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. */
#else /* Word 0 - Little Endian */
        uint64_t ln0_cup               : 16; /**< [ 15:  0](R/W/H) PCS lane 0 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. */
        uint64_t ln1_cup               : 16; /**< [ 31: 16](R/W/H) PCS lane 1 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_cup               : 16; /**< [ 47: 32](R/W/H) PCS lane 2 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln3_cup               : 16; /**< [ 63: 48](R/W/H) PCS lane 3 coefficient update: format defined by CGX_SPU_BR_TRAIN_CUP_S. Not valid for
                                                                 10GBASE-R. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_pmd_lp_cup_s cn; */
} bdk_cgxx_spux_br_pmd_lp_cup_t;

static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LP_CUP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LP_CUP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010078ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_PMD_LP_CUP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_PMD_LP_CUP(a,b) bdk_cgxx_spux_br_pmd_lp_cup_t
#define bustype_BDK_CGXX_SPUX_BR_PMD_LP_CUP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_PMD_LP_CUP(a,b) "CGXX_SPUX_BR_PMD_LP_CUP"
#define device_bar_BDK_CGXX_SPUX_BR_PMD_LP_CUP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_PMD_LP_CUP(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_PMD_LP_CUP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_pmd_lp_rep
 *
 * CGX SPU 40GBASE-R PMD Link Partner Status Report Registers
 * This register implements 802.3 MDIO register 1.153 for 10GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 10G_R)
 * and MDIO registers 1.1200-1.1203 for 40GBASE-R (when
 * CGX()_CMR()_CONFIG[LMAC_TYPE] = 40G_R). It is automatically cleared at the start of training.
 * Each field reflects
 * the contents of the status report field in the associated lane's most recently received
 * training frame. The lane fields in this register are indexed by logical PCS lane ID.
 *
 * The lane
 * 0 field (LN0_*) is valid for both 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*,
 * LN3_*) are only valid for 40GBASE-R.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_pmd_lp_rep_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln3_rep               : 16; /**< [ 63: 48](RO/H) PCS lane 3 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_rep               : 16; /**< [ 47: 32](RO/H) PCS lane 2 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln1_rep               : 16; /**< [ 31: 16](RO/H) PCS lane 1 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln0_rep               : 16; /**< [ 15:  0](RO/H) PCS lane 0 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. */
#else /* Word 0 - Little Endian */
        uint64_t ln0_rep               : 16; /**< [ 15:  0](RO/H) PCS lane 0 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. */
        uint64_t ln1_rep               : 16; /**< [ 31: 16](RO/H) PCS lane 1 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln2_rep               : 16; /**< [ 47: 32](RO/H) PCS lane 2 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
        uint64_t ln3_rep               : 16; /**< [ 63: 48](RO/H) PCS lane 3 status report: format defined by CGX_SPU_BR_TRAIN_REP_S. Not valid for
                                                                 10GBASE-R. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_pmd_lp_rep_s cn; */
} bdk_cgxx_spux_br_pmd_lp_rep_t;

static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LP_REP(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_PMD_LP_REP(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010080ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_PMD_LP_REP", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_PMD_LP_REP(a,b) bdk_cgxx_spux_br_pmd_lp_rep_t
#define bustype_BDK_CGXX_SPUX_BR_PMD_LP_REP(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_PMD_LP_REP(a,b) "CGXX_SPUX_BR_PMD_LP_REP"
#define device_bar_BDK_CGXX_SPUX_BR_PMD_LP_REP(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_PMD_LP_REP(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_PMD_LP_REP(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_pmd_status
 *
 * CGX SPU 40GBASE-R PMD Status Registers
 * The lane fields in this register are indexed by logical PCS lane ID. The lane 0 field (LN0_*)
 * is valid for both 10GBASE-R and 40GBASE-R. The remaining fields (LN1_*, LN2_*, LN3_*) are only
 * valid for 40GBASE-R.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_pmd_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t ln3_train_status      : 4;  /**< [ 15: 12](RO/H) PCS lane 3 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
        uint64_t ln2_train_status      : 4;  /**< [ 11:  8](RO/H) PCS lane 2 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
        uint64_t ln1_train_status      : 4;  /**< [  7:  4](RO/H) PCS lane 1 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
        uint64_t ln0_train_status      : 4;  /**< [  3:  0](RO/H) PCS lane 0 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. */
#else /* Word 0 - Little Endian */
        uint64_t ln0_train_status      : 4;  /**< [  3:  0](RO/H) PCS lane 0 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. */
        uint64_t ln1_train_status      : 4;  /**< [  7:  4](RO/H) PCS lane 1 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
        uint64_t ln2_train_status      : 4;  /**< [ 11:  8](RO/H) PCS lane 2 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
        uint64_t ln3_train_status      : 4;  /**< [ 15: 12](RO/H) PCS lane 3 link training status. Format defined by CGX_SPU_BR_LANE_TRAIN_STATUS_S. Not
                                                                 valid for 10GBASE-R. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_pmd_status_s cn; */
} bdk_cgxx_spux_br_pmd_status_t;

static inline uint64_t BDK_CGXX_SPUX_BR_PMD_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_PMD_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010070ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_PMD_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_PMD_STATUS(a,b) bdk_cgxx_spux_br_pmd_status_t
#define bustype_BDK_CGXX_SPUX_BR_PMD_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_PMD_STATUS(a,b) "CGXX_SPUX_BR_PMD_STATUS"
#define device_bar_BDK_CGXX_SPUX_BR_PMD_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_PMD_STATUS(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_PMD_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_status1
 *
 * CGX SPU BASE-R Status 1 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_status1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t rcv_lnk               : 1;  /**< [ 12: 12](RO/H) BASE-R receive link status.
                                                                 0 = BASE-R PCS receive-link down.
                                                                 1 = BASE-R PCS receive-link up.

                                                                 This bit is a reflection of the PCS_status variable defined in Std 802.3 sections
                                                                 49.2.14.1 and 82.3.1. */
        uint64_t reserved_4_11         : 8;
        uint64_t prbs9                 : 1;  /**< [  3:  3](RO) 10GBASE-R PRBS9 pattern testing ability. Always 0; PRBS9 pattern testing is not supported. */
        uint64_t prbs31                : 1;  /**< [  2:  2](RO) 10GBASE-R PRBS31 pattern testing ability. Always 0; PRBS31 pattern testing is not supported. */
        uint64_t hi_ber                : 1;  /**< [  1:  1](RO/H) BASE-R PCS high bit-error rate.
                                                                 0 = 64/66 bit receiver is detecting a bit-error rate of < 10.4.
                                                                 1 = 64/66 bit receiver is detecting a bit-error rate of >= 10.4.

                                                                 This bit is a direct reflection of the state of the HI_BER variable in the 64 B/66 B state
                                                                 diagram and is defined in Std 802.3 sections 49.2.13.2.2 and 82.2.18.2.2. */
        uint64_t blk_lock              : 1;  /**< [  0:  0](RO/H) BASE-R PCS block lock.
                                                                 0 = No block lock.
                                                                 1 = 64/66 bit receiver for BASE-R has block lock.

                                                                 This bit is a direct reflection of the state of the BLOCK_LOCK variable in the 64 B/66 B
                                                                 state diagram and is defined in Std 802.3 sections 49.2.13.2.2 and 82.2.18.2.2.
                                                                 For a multilane logical PCS (i.e. 40GBASE-R), this bit indicates that the receiver has
                                                                 both block lock and alignment for all lanes and is identical to
                                                                 CGX()_SPU()_BR_ALGN_STATUS[ALIGND]. */
#else /* Word 0 - Little Endian */
        uint64_t blk_lock              : 1;  /**< [  0:  0](RO/H) BASE-R PCS block lock.
                                                                 0 = No block lock.
                                                                 1 = 64/66 bit receiver for BASE-R has block lock.

                                                                 This bit is a direct reflection of the state of the BLOCK_LOCK variable in the 64 B/66 B
                                                                 state diagram and is defined in Std 802.3 sections 49.2.13.2.2 and 82.2.18.2.2.
                                                                 For a multilane logical PCS (i.e. 40GBASE-R), this bit indicates that the receiver has
                                                                 both block lock and alignment for all lanes and is identical to
                                                                 CGX()_SPU()_BR_ALGN_STATUS[ALIGND]. */
        uint64_t hi_ber                : 1;  /**< [  1:  1](RO/H) BASE-R PCS high bit-error rate.
                                                                 0 = 64/66 bit receiver is detecting a bit-error rate of < 10.4.
                                                                 1 = 64/66 bit receiver is detecting a bit-error rate of >= 10.4.

                                                                 This bit is a direct reflection of the state of the HI_BER variable in the 64 B/66 B state
                                                                 diagram and is defined in Std 802.3 sections 49.2.13.2.2 and 82.2.18.2.2. */
        uint64_t prbs31                : 1;  /**< [  2:  2](RO) 10GBASE-R PRBS31 pattern testing ability. Always 0; PRBS31 pattern testing is not supported. */
        uint64_t prbs9                 : 1;  /**< [  3:  3](RO) 10GBASE-R PRBS9 pattern testing ability. Always 0; PRBS9 pattern testing is not supported. */
        uint64_t reserved_4_11         : 8;
        uint64_t rcv_lnk               : 1;  /**< [ 12: 12](RO/H) BASE-R receive link status.
                                                                 0 = BASE-R PCS receive-link down.
                                                                 1 = BASE-R PCS receive-link up.

                                                                 This bit is a reflection of the PCS_status variable defined in Std 802.3 sections
                                                                 49.2.14.1 and 82.3.1. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_status1_s cn; */
} bdk_cgxx_spux_br_status1_t;

static inline uint64_t BDK_CGXX_SPUX_BR_STATUS1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_STATUS1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010030ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_STATUS1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_STATUS1(a,b) bdk_cgxx_spux_br_status1_t
#define bustype_BDK_CGXX_SPUX_BR_STATUS1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_STATUS1(a,b) "CGXX_SPUX_BR_STATUS1"
#define device_bar_BDK_CGXX_SPUX_BR_STATUS1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_STATUS1(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_STATUS1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_status2
 *
 * CGX SPU BASE-R Status 2 Registers
 * This register implements a combination of the following Std 802.3 registers:
 * * BASE-R PCS status 2 (MDIO address 3.33).
 * * BASE-R BER high-order counter (MDIO address 3.44).
 * * Errored-blocks high-order counter (MDIO address 3.45).
 *
 * Note that the relative locations of some fields have been moved from Std 802.3 in order to
 * make the register layout more software friendly: the BER counter high-order and low-order bits
 * from sections 3.44 and 3.33 have been combined into the contiguous, 22-bit [BER_CNT] field;
 * likewise, the errored-blocks counter high-order and low-order bits from section 3.45 have been
 * combined into the contiguous, 22-bit [ERR_BLKS] field.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_status2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t err_blks              : 22; /**< [ 61: 40](RC/W/H) Errored-blocks counter. This is the BASE-R errored-blocks counter as defined by the
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
        uint64_t reserved_38_39        : 2;
        uint64_t ber_cnt               : 22; /**< [ 37: 16](RC/W/H) Bit-error-rate counter. This is the BASE-R BER counter as defined by the BER_COUNT
                                                                 variable in Std 802.3 sections 49.2.14.2 and 82.2.18.2.4. The counter is reset to all 0s
                                                                 after this register is read by software, and is held at all 1s in case of overflow.
                                                                 The reset operation takes precedence over the increment operation: if the register is read
                                                                 on the same clock cycle an increment operation, the counter is reset to all 0s and the
                                                                 increment operation is lost.

                                                                 This field is writable for test purposes, rather than read-only as specified in Std 802.3. */
        uint64_t latched_lock          : 1;  /**< [ 15: 15](R/W1S/H) Latched-block lock.
                                                                 0 = No block.
                                                                 1 = 64/66 bit receiver for BASE-R has block lock.

                                                                 This is a latching-low version of CGX()_SPU()_BR_STATUS1[BLK_LOCK]; it stays clear
                                                                 until the register is read by software.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-set
                                                                 bit, rather than latching low read-only as specified in 802.3. */
        uint64_t latched_ber           : 1;  /**< [ 14: 14](R/W1C/H) Latched-high bit-error rate.
                                                                 0 = Not a high BER.
                                                                 1 = 64/66 bit receiver is detecting a high BER.

                                                                 This is a latching-high version of CGX()_SPU()_BR_STATUS1[HI_BER]; it stays set until
                                                                 the register is read by software.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-clear
                                                                 bit, rather than latching high read-only as specified in 802.3. */
        uint64_t reserved_0_13         : 14;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_13         : 14;
        uint64_t latched_ber           : 1;  /**< [ 14: 14](R/W1C/H) Latched-high bit-error rate.
                                                                 0 = Not a high BER.
                                                                 1 = 64/66 bit receiver is detecting a high BER.

                                                                 This is a latching-high version of CGX()_SPU()_BR_STATUS1[HI_BER]; it stays set until
                                                                 the register is read by software.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-clear
                                                                 bit, rather than latching high read-only as specified in 802.3. */
        uint64_t latched_lock          : 1;  /**< [ 15: 15](R/W1S/H) Latched-block lock.
                                                                 0 = No block.
                                                                 1 = 64/66 bit receiver for BASE-R has block lock.

                                                                 This is a latching-low version of CGX()_SPU()_BR_STATUS1[BLK_LOCK]; it stays clear
                                                                 until the register is read by software.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-set
                                                                 bit, rather than latching low read-only as specified in 802.3. */
        uint64_t ber_cnt               : 22; /**< [ 37: 16](RC/W/H) Bit-error-rate counter. This is the BASE-R BER counter as defined by the BER_COUNT
                                                                 variable in Std 802.3 sections 49.2.14.2 and 82.2.18.2.4. The counter is reset to all 0s
                                                                 after this register is read by software, and is held at all 1s in case of overflow.
                                                                 The reset operation takes precedence over the increment operation: if the register is read
                                                                 on the same clock cycle an increment operation, the counter is reset to all 0s and the
                                                                 increment operation is lost.

                                                                 This field is writable for test purposes, rather than read-only as specified in Std 802.3. */
        uint64_t reserved_38_39        : 2;
        uint64_t err_blks              : 22; /**< [ 61: 40](RC/W/H) Errored-blocks counter. This is the BASE-R errored-blocks counter as defined by the
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
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_status2_s cn; */
} bdk_cgxx_spux_br_status2_t;

static inline uint64_t BDK_CGXX_SPUX_BR_STATUS2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_STATUS2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010038ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_STATUS2", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_STATUS2(a,b) bdk_cgxx_spux_br_status2_t
#define bustype_BDK_CGXX_SPUX_BR_STATUS2(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_STATUS2(a,b) "CGXX_SPUX_BR_STATUS2"
#define device_bar_BDK_CGXX_SPUX_BR_STATUS2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_STATUS2(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_STATUS2(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_tp_control
 *
 * CGX SPU BASE-R Test-Pattern Control Registers
 * Refer to the test pattern methodology described in 802.3 sections 49.2.8 and 82.2.10.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_tp_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t scramble_tp           : 1;  /**< [  7:  7](R/W) Select scrambled idle test pattern. This bit selects the transmit test pattern used when
                                                                 [TX_TP_EN] is set:
                                                                 0 = Square wave test pattern.
                                                                 1 = Scrambled idle test pattern. */
        uint64_t prbs9_tx              : 1;  /**< [  6:  6](RO) 10GBASE-R PRBS9 TP transmit enable. Always 0; PRBS9 pattern testing is not supported. */
        uint64_t prbs31_rx             : 1;  /**< [  5:  5](RO) 10GBASE-R PRBS31 TP receive enable. Always 0; PRBS31 pattern testing is not supported. */
        uint64_t prbs31_tx             : 1;  /**< [  4:  4](RO) 10GBASE-R PRBS31 TP transmit enable. Always 0; PRBS31 pattern is not supported. */
        uint64_t tx_tp_en              : 1;  /**< [  3:  3](R/W) Transmit-test-pattern enable. */
        uint64_t rx_tp_en              : 1;  /**< [  2:  2](R/W) Receive-test-pattern enable. The only supported receive test pattern is the scrambled idle
                                                                 test pattern. Setting this bit enables checking of that receive pattern. */
        uint64_t tp_sel                : 1;  /**< [  1:  1](RO/H) Square/PRBS test pattern select. Always 1 to select square wave test pattern; PRBS test
                                                                 patterns are not supported. */
        uint64_t dp_sel                : 1;  /**< [  0:  0](RO) Data pattern select. Always 0; PRBS test patterns are not supported. */
#else /* Word 0 - Little Endian */
        uint64_t dp_sel                : 1;  /**< [  0:  0](RO) Data pattern select. Always 0; PRBS test patterns are not supported. */
        uint64_t tp_sel                : 1;  /**< [  1:  1](RO/H) Square/PRBS test pattern select. Always 1 to select square wave test pattern; PRBS test
                                                                 patterns are not supported. */
        uint64_t rx_tp_en              : 1;  /**< [  2:  2](R/W) Receive-test-pattern enable. The only supported receive test pattern is the scrambled idle
                                                                 test pattern. Setting this bit enables checking of that receive pattern. */
        uint64_t tx_tp_en              : 1;  /**< [  3:  3](R/W) Transmit-test-pattern enable. */
        uint64_t prbs31_tx             : 1;  /**< [  4:  4](RO) 10GBASE-R PRBS31 TP transmit enable. Always 0; PRBS31 pattern is not supported. */
        uint64_t prbs31_rx             : 1;  /**< [  5:  5](RO) 10GBASE-R PRBS31 TP receive enable. Always 0; PRBS31 pattern testing is not supported. */
        uint64_t prbs9_tx              : 1;  /**< [  6:  6](RO) 10GBASE-R PRBS9 TP transmit enable. Always 0; PRBS9 pattern testing is not supported. */
        uint64_t scramble_tp           : 1;  /**< [  7:  7](R/W) Select scrambled idle test pattern. This bit selects the transmit test pattern used when
                                                                 [TX_TP_EN] is set:
                                                                 0 = Square wave test pattern.
                                                                 1 = Scrambled idle test pattern. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_tp_control_s cn; */
} bdk_cgxx_spux_br_tp_control_t;

static inline uint64_t BDK_CGXX_SPUX_BR_TP_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_TP_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010040ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_TP_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_TP_CONTROL(a,b) bdk_cgxx_spux_br_tp_control_t
#define bustype_BDK_CGXX_SPUX_BR_TP_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_TP_CONTROL(a,b) "CGXX_SPUX_BR_TP_CONTROL"
#define device_bar_BDK_CGXX_SPUX_BR_TP_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_TP_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_TP_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_br_tp_err_cnt
 *
 * CGX SPU BASE-R Test-Pattern Error-Count Registers
 * This register provides the BASE-R PCS test-pattern error counter.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_br_tp_err_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t err_cnt               : 16; /**< [ 15:  0](RC/W/H) Error counter. This 16-bit counter contains the number of errors received during a pattern
                                                                 test. These bits are reset to all 0s when this register is read by software, and they are
                                                                 held at all 1s in the case of overflow.

                                                                 The test pattern methodology is described in Std 802.3, Sections 49.2.12 and 82.2.10. This
                                                                 counter counts either block errors or bit errors dependent on the test mode (see Section
                                                                 49.2.12). The reset operation takes precedence over the increment operation; if the
                                                                 register is read on the same clock cycle as an increment operation, the counter is reset
                                                                 to all 0s and the increment operation is lost. This field is writable for test purposes,
                                                                 rather than read-only as specified in Std 802.3. */
#else /* Word 0 - Little Endian */
        uint64_t err_cnt               : 16; /**< [ 15:  0](RC/W/H) Error counter. This 16-bit counter contains the number of errors received during a pattern
                                                                 test. These bits are reset to all 0s when this register is read by software, and they are
                                                                 held at all 1s in the case of overflow.

                                                                 The test pattern methodology is described in Std 802.3, Sections 49.2.12 and 82.2.10. This
                                                                 counter counts either block errors or bit errors dependent on the test mode (see Section
                                                                 49.2.12). The reset operation takes precedence over the increment operation; if the
                                                                 register is read on the same clock cycle as an increment operation, the counter is reset
                                                                 to all 0s and the increment operation is lost. This field is writable for test purposes,
                                                                 rather than read-only as specified in Std 802.3. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_br_tp_err_cnt_s cn; */
} bdk_cgxx_spux_br_tp_err_cnt_t;

static inline uint64_t BDK_CGXX_SPUX_BR_TP_ERR_CNT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BR_TP_ERR_CNT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010048ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BR_TP_ERR_CNT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BR_TP_ERR_CNT(a,b) bdk_cgxx_spux_br_tp_err_cnt_t
#define bustype_BDK_CGXX_SPUX_BR_TP_ERR_CNT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BR_TP_ERR_CNT(a,b) "CGXX_SPUX_BR_TP_ERR_CNT"
#define device_bar_BDK_CGXX_SPUX_BR_TP_ERR_CNT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BR_TP_ERR_CNT(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BR_TP_ERR_CNT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_bx_status
 *
 * CGX SPU BASE-X Status Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_bx_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t alignd                : 1;  /**< [ 12: 12](RO/H) 10GBASE-X lane-alignment status.
                                                                 0 = receive lanes not aligned.
                                                                 1 = receive lanes aligned. */
        uint64_t pattst                : 1;  /**< [ 11: 11](RO) Pattern-testing ability. Always 0; 10GBASE-X pattern is testing not supported. */
        uint64_t reserved_4_10         : 7;
        uint64_t lsync                 : 4;  /**< [  3:  0](RO/H) Lane synchronization. BASE-X lane synchronization status for PCS lanes 3-0. Each bit is
                                                                 set when the associated lane is code-group synchronized, and clear otherwise. If the PCS
                                                                 type is RXAUI (i.e. the associated CGX()_CMR()_CONFIG[LMAC_TYPE] = RXAUI), then
                                                                 only lanes 1-0 are valid. */
#else /* Word 0 - Little Endian */
        uint64_t lsync                 : 4;  /**< [  3:  0](RO/H) Lane synchronization. BASE-X lane synchronization status for PCS lanes 3-0. Each bit is
                                                                 set when the associated lane is code-group synchronized, and clear otherwise. If the PCS
                                                                 type is RXAUI (i.e. the associated CGX()_CMR()_CONFIG[LMAC_TYPE] = RXAUI), then
                                                                 only lanes 1-0 are valid. */
        uint64_t reserved_4_10         : 7;
        uint64_t pattst                : 1;  /**< [ 11: 11](RO) Pattern-testing ability. Always 0; 10GBASE-X pattern is testing not supported. */
        uint64_t alignd                : 1;  /**< [ 12: 12](RO/H) 10GBASE-X lane-alignment status.
                                                                 0 = receive lanes not aligned.
                                                                 1 = receive lanes aligned. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_bx_status_s cn; */
} bdk_cgxx_spux_bx_status_t;

static inline uint64_t BDK_CGXX_SPUX_BX_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_BX_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010028ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_BX_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_BX_STATUS(a,b) bdk_cgxx_spux_bx_status_t
#define bustype_BDK_CGXX_SPUX_BX_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_BX_STATUS(a,b) "CGXX_SPUX_BX_STATUS"
#define device_bar_BDK_CGXX_SPUX_BX_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_BX_STATUS(a,b) (a)
#define arguments_BDK_CGXX_SPUX_BX_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_control1
 *
 * CGX SPU Control 1 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_control1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t reset                 : 1;  /**< [ 15: 15](R/W1S/H) Reset. Setting this bit or CGX()_SPU()_AN_CONTROL[AN_RESET] to 1 causes the
                                                                 following to happen:
                                                                 * Resets the logical PCS (LPCS)
                                                                 * Sets the Std 802.3 PCS, FEC and AN registers for the LPCS to their default states
                                                                 * Resets the associated SerDes lanes.

                                                                 It takes up to 32 coprocessor-clock cycles to reset the LPCS, after which RESET is
                                                                 automatically cleared. */
        uint64_t loopbck               : 1;  /**< [ 14: 14](R/W) TX-to-RX loopback enable. When set, transmit data for each SerDes lane is looped back as
                                                                 receive data. */
        uint64_t spdsel1               : 1;  /**< [ 13: 13](RO/H) Speed select 1: always 1. */
        uint64_t reserved_12           : 1;
        uint64_t lo_pwr                : 1;  /**< [ 11: 11](R/W) Low power enable. When set, the LPCS is disabled (overriding the associated
                                                                 CGX()_CMR()_CONFIG[ENABLE]), and the SerDes lanes associated with the LPCS are
                                                                 reset. */
        uint64_t reserved_7_10         : 4;
        uint64_t spdsel0               : 1;  /**< [  6:  6](RO/H) Speed select 0: always 1. */
        uint64_t spd                   : 4;  /**< [  5:  2](RO/H) '"Speed selection.
                                                                 Note that this is a read-only field rather than read/write as
                                                                 specified in 802.3.
                                                                 The LPCS speed is instead configured by the associated
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]. The read values returned by this field are as
                                                                 follows:

                                                                 <pre>
                                                                   LMAC_TYPE   Speed       SPD Read Value    Comment
                                                                   ------------------------------------------------------
                                                                   XAUI        10G/20G     0x0               20G if DXAUI
                                                                   RXAUI       10G         0x0
                                                                   10G_R       10G         0x0
                                                                   40G_R       40G         0x3
                                                                   Other       -           X
                                                                 </pre>' */
        uint64_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_1          : 2;
        uint64_t spd                   : 4;  /**< [  5:  2](RO/H) '"Speed selection.
                                                                 Note that this is a read-only field rather than read/write as
                                                                 specified in 802.3.
                                                                 The LPCS speed is instead configured by the associated
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]. The read values returned by this field are as
                                                                 follows:

                                                                 <pre>
                                                                   LMAC_TYPE   Speed       SPD Read Value    Comment
                                                                   ------------------------------------------------------
                                                                   XAUI        10G/20G     0x0               20G if DXAUI
                                                                   RXAUI       10G         0x0
                                                                   10G_R       10G         0x0
                                                                   40G_R       40G         0x3
                                                                   Other       -           X
                                                                 </pre>' */
        uint64_t spdsel0               : 1;  /**< [  6:  6](RO/H) Speed select 0: always 1. */
        uint64_t reserved_7_10         : 4;
        uint64_t lo_pwr                : 1;  /**< [ 11: 11](R/W) Low power enable. When set, the LPCS is disabled (overriding the associated
                                                                 CGX()_CMR()_CONFIG[ENABLE]), and the SerDes lanes associated with the LPCS are
                                                                 reset. */
        uint64_t reserved_12           : 1;
        uint64_t spdsel1               : 1;  /**< [ 13: 13](RO/H) Speed select 1: always 1. */
        uint64_t loopbck               : 1;  /**< [ 14: 14](R/W) TX-to-RX loopback enable. When set, transmit data for each SerDes lane is looped back as
                                                                 receive data. */
        uint64_t reset                 : 1;  /**< [ 15: 15](R/W1S/H) Reset. Setting this bit or CGX()_SPU()_AN_CONTROL[AN_RESET] to 1 causes the
                                                                 following to happen:
                                                                 * Resets the logical PCS (LPCS)
                                                                 * Sets the Std 802.3 PCS, FEC and AN registers for the LPCS to their default states
                                                                 * Resets the associated SerDes lanes.

                                                                 It takes up to 32 coprocessor-clock cycles to reset the LPCS, after which RESET is
                                                                 automatically cleared. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_control1_s cn; */
} bdk_cgxx_spux_control1_t;

static inline uint64_t BDK_CGXX_SPUX_CONTROL1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_CONTROL1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010000ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_CONTROL1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_CONTROL1(a,b) bdk_cgxx_spux_control1_t
#define bustype_BDK_CGXX_SPUX_CONTROL1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_CONTROL1(a,b) "CGXX_SPUX_CONTROL1"
#define device_bar_BDK_CGXX_SPUX_CONTROL1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_CONTROL1(a,b) (a)
#define arguments_BDK_CGXX_SPUX_CONTROL1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_control2
 *
 * CGX SPU Control 2 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_control2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_3_63         : 61;
        uint64_t pcs_type              : 3;  /**< [  2:  0](RO/H) PCS type selection.
                                                                 Note that this is a read-only field rather than read/write as
                                                                 specified in 802.3.
                                                                 The LPCS speed is instead configured by the associated
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]. The read values returned by this field are as
                                                                 follows:

                                                                 <pre>
                                                                               [PCS_TYPE]
                                                                   LMAC_TYPE   Read Value      Comment
                                                                   -------------------------------------------------
                                                                   XAUI        0x1             10GBASE-X PCS type
                                                                   RXAUI       0x1             10GBASE-X PCS type
                                                                   10G_R       0x0             10GBASE-R PCS type
                                                                   40G_R       0x4             40GBASE-R PCS type
                                                                   Other       Undefined       Reserved
                                                                 </pre> */
#else /* Word 0 - Little Endian */
        uint64_t pcs_type              : 3;  /**< [  2:  0](RO/H) PCS type selection.
                                                                 Note that this is a read-only field rather than read/write as
                                                                 specified in 802.3.
                                                                 The LPCS speed is instead configured by the associated
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]. The read values returned by this field are as
                                                                 follows:

                                                                 <pre>
                                                                               [PCS_TYPE]
                                                                   LMAC_TYPE   Read Value      Comment
                                                                   -------------------------------------------------
                                                                   XAUI        0x1             10GBASE-X PCS type
                                                                   RXAUI       0x1             10GBASE-X PCS type
                                                                   10G_R       0x0             10GBASE-R PCS type
                                                                   40G_R       0x4             40GBASE-R PCS type
                                                                   Other       Undefined       Reserved
                                                                 </pre> */
        uint64_t reserved_3_63         : 61;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_control2_s cn; */
} bdk_cgxx_spux_control2_t;

static inline uint64_t BDK_CGXX_SPUX_CONTROL2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_CONTROL2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010018ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_CONTROL2", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_CONTROL2(a,b) bdk_cgxx_spux_control2_t
#define bustype_BDK_CGXX_SPUX_CONTROL2(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_CONTROL2(a,b) "CGXX_SPUX_CONTROL2"
#define device_bar_BDK_CGXX_SPUX_CONTROL2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_CONTROL2(a,b) (a)
#define arguments_BDK_CGXX_SPUX_CONTROL2(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_fec_abil
 *
 * CGX SPU Forward Error Correction Ability Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_fec_abil_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t err_abil              : 1;  /**< [  1:  1](RO/H) BASE-R FEC error-indication ability. Always 1 when the LPCS type is BASE-R,
                                                                 i.e. CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4. Always 0 otherwise. */
        uint64_t fec_abil              : 1;  /**< [  0:  0](RO/H) BASE-R FEC ability. Always 1 when the LPCS type is BASE-R,
                                                                 i.e. CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4. Always 0 otherwise. */
#else /* Word 0 - Little Endian */
        uint64_t fec_abil              : 1;  /**< [  0:  0](RO/H) BASE-R FEC ability. Always 1 when the LPCS type is BASE-R,
                                                                 i.e. CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4. Always 0 otherwise. */
        uint64_t err_abil              : 1;  /**< [  1:  1](RO/H) BASE-R FEC error-indication ability. Always 1 when the LPCS type is BASE-R,
                                                                 i.e. CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4. Always 0 otherwise. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_fec_abil_s cn; */
} bdk_cgxx_spux_fec_abil_t;

static inline uint64_t BDK_CGXX_SPUX_FEC_ABIL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_FEC_ABIL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010098ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_FEC_ABIL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_FEC_ABIL(a,b) bdk_cgxx_spux_fec_abil_t
#define bustype_BDK_CGXX_SPUX_FEC_ABIL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_FEC_ABIL(a,b) "CGXX_SPUX_FEC_ABIL"
#define device_bar_BDK_CGXX_SPUX_FEC_ABIL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_FEC_ABIL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_FEC_ABIL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_fec_control
 *
 * CGX SPU Forward Error Correction Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_fec_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t err_en                : 1;  /**< [  1:  1](R/W) BASE-R FEC error-indication enable. This bit corresponds to FEC_Enable_Error_to_PCS
                                                                 variable for BASE-R as defined in 802.3 Clause 74. When FEC is enabled ([FEC_EN] is set)
                                                                 and this bit is set, the FEC decoder on the receive side signals an
                                                                 uncorrectable FEC error to the BASE-R decoder by driving a value of 2'b11 on the sync bits
                                                                 for some of the 32 64/66 bit blocks belonging to the uncorrectable FEC block. See
                                                                 802.3-2008/802.3ba-2010 section 74.7.4.5.1 for more details. */
        uint64_t fec_en                : 1;  /**< [  0:  0](R/W) BASE-R FEC enable. When this bit is set and the LPCS type is BASE-R
                                                                 (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), forward error correction is enabled. FEC is
                                                                 disabled otherwise. Forward error correction is defined in IEEE Std
                                                                 802.3-2008/802.3ba-2010 Clause 74. */
#else /* Word 0 - Little Endian */
        uint64_t fec_en                : 1;  /**< [  0:  0](R/W) BASE-R FEC enable. When this bit is set and the LPCS type is BASE-R
                                                                 (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4), forward error correction is enabled. FEC is
                                                                 disabled otherwise. Forward error correction is defined in IEEE Std
                                                                 802.3-2008/802.3ba-2010 Clause 74. */
        uint64_t err_en                : 1;  /**< [  1:  1](R/W) BASE-R FEC error-indication enable. This bit corresponds to FEC_Enable_Error_to_PCS
                                                                 variable for BASE-R as defined in 802.3 Clause 74. When FEC is enabled ([FEC_EN] is set)
                                                                 and this bit is set, the FEC decoder on the receive side signals an
                                                                 uncorrectable FEC error to the BASE-R decoder by driving a value of 2'b11 on the sync bits
                                                                 for some of the 32 64/66 bit blocks belonging to the uncorrectable FEC block. See
                                                                 802.3-2008/802.3ba-2010 section 74.7.4.5.1 for more details. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_fec_control_s cn; */
} bdk_cgxx_spux_fec_control_t;

static inline uint64_t BDK_CGXX_SPUX_FEC_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_FEC_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100a0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_FEC_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_FEC_CONTROL(a,b) bdk_cgxx_spux_fec_control_t
#define bustype_BDK_CGXX_SPUX_FEC_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_FEC_CONTROL(a,b) "CGXX_SPUX_FEC_CONTROL"
#define device_bar_BDK_CGXX_SPUX_FEC_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_FEC_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_FEC_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_fec_corr_blks01
 *
 * CGX SPU FEC Corrected-Blocks Counters 0/1 Registers
 * This register is valid only when the LPCS type is BASE-R
 * (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4). The FEC corrected-block counters are
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
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_fec_corr_blks01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln1_corr_blks         : 32; /**< [ 63: 32](RC/W/H) PCS Lane 1 FEC corrected blocks.
                                                                 * For 10GBASE-R, reserved.
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_corrected_blocks_counter_1 variable
                                                                 (registers 1.302-1.303). */
        uint64_t ln0_corr_blks         : 32; /**< [ 31:  0](RC/W/H) PCS Lane 0 FEC corrected blocks.
                                                                 * For 10GBASE-R, corresponds to the Std 802.3 FEC_corrected_blocks_counter variable
                                                                 (registers 1.172-1.173).
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_corrected_blocks_counter_0 variable
                                                                 (registers 1.300-1.301). */
#else /* Word 0 - Little Endian */
        uint64_t ln0_corr_blks         : 32; /**< [ 31:  0](RC/W/H) PCS Lane 0 FEC corrected blocks.
                                                                 * For 10GBASE-R, corresponds to the Std 802.3 FEC_corrected_blocks_counter variable
                                                                 (registers 1.172-1.173).
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_corrected_blocks_counter_0 variable
                                                                 (registers 1.300-1.301). */
        uint64_t ln1_corr_blks         : 32; /**< [ 63: 32](RC/W/H) PCS Lane 1 FEC corrected blocks.
                                                                 * For 10GBASE-R, reserved.
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_corrected_blocks_counter_1 variable
                                                                 (registers 1.302-1.303). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_fec_corr_blks01_s cn; */
} bdk_cgxx_spux_fec_corr_blks01_t;

static inline uint64_t BDK_CGXX_SPUX_FEC_CORR_BLKS01(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_FEC_CORR_BLKS01(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100a8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_FEC_CORR_BLKS01", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_FEC_CORR_BLKS01(a,b) bdk_cgxx_spux_fec_corr_blks01_t
#define bustype_BDK_CGXX_SPUX_FEC_CORR_BLKS01(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_FEC_CORR_BLKS01(a,b) "CGXX_SPUX_FEC_CORR_BLKS01"
#define device_bar_BDK_CGXX_SPUX_FEC_CORR_BLKS01(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_FEC_CORR_BLKS01(a,b) (a)
#define arguments_BDK_CGXX_SPUX_FEC_CORR_BLKS01(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_fec_corr_blks23
 *
 * CGX SPU FEC Corrected-Blocks Counters 2/3 Registers
 * This register is valid only when the LPCS type is 40GBASE-R
 * (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4). The FEC corrected-block counters are defined in
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
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_fec_corr_blks23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln3_corr_blks         : 32; /**< [ 63: 32](RC/W/H) PCS Lane 3 FEC corrected blocks. Correspond to the Std 802.3
                                                                 FEC_corrected_blocks_counter_3 variable (registers 1.306-1.307). */
        uint64_t ln2_corr_blks         : 32; /**< [ 31:  0](RC/W/H) PCS Lane 2 FEC corrected blocks. Correspond to the Std 802.3
                                                                 FEC_corrected_blocks_counter_3 variable (registers 1.304-1.305). */
#else /* Word 0 - Little Endian */
        uint64_t ln2_corr_blks         : 32; /**< [ 31:  0](RC/W/H) PCS Lane 2 FEC corrected blocks. Correspond to the Std 802.3
                                                                 FEC_corrected_blocks_counter_3 variable (registers 1.304-1.305). */
        uint64_t ln3_corr_blks         : 32; /**< [ 63: 32](RC/W/H) PCS Lane 3 FEC corrected blocks. Correspond to the Std 802.3
                                                                 FEC_corrected_blocks_counter_3 variable (registers 1.306-1.307). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_fec_corr_blks23_s cn; */
} bdk_cgxx_spux_fec_corr_blks23_t;

static inline uint64_t BDK_CGXX_SPUX_FEC_CORR_BLKS23(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_FEC_CORR_BLKS23(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100b0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_FEC_CORR_BLKS23", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_FEC_CORR_BLKS23(a,b) bdk_cgxx_spux_fec_corr_blks23_t
#define bustype_BDK_CGXX_SPUX_FEC_CORR_BLKS23(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_FEC_CORR_BLKS23(a,b) "CGXX_SPUX_FEC_CORR_BLKS23"
#define device_bar_BDK_CGXX_SPUX_FEC_CORR_BLKS23(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_FEC_CORR_BLKS23(a,b) (a)
#define arguments_BDK_CGXX_SPUX_FEC_CORR_BLKS23(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_fec_uncorr_blks01
 *
 * CGX SPU FEC Uncorrected-Blocks Counters 0/1 Registers
 * This register is valid only when the LPCS type is BASE-R
 * (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x3 or 0x4). The FEC corrected-block counters are
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
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_fec_uncorr_blks01_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln1_uncorr_blks       : 32; /**< [ 63: 32](RC/W/H) PCS Lane 1 FEC corrected blocks.
                                                                 * For 10GBASE-R, reserved.
                                                                 * For 40GBASE-R, corresponds to the Std 802.3 FEC_uncorrected_blocks_counter_1 variable
                                                                 (registers 1.702-1.703). */
        uint64_t ln0_uncorr_blks       : 32; /**< [ 31:  0](RC/W/H) PCS Lane 0 FEC uncorrected blocks.
                                                                 * For 10GBASE-R, corresponds to the Std 802.3 FEC_uncorrected_blocks_counter variable
                                                                 (registers 1.174-1.175).
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_uncorrected_blocks_counter_0 variable
                                                                 (registers 1.700-1.701). */
#else /* Word 0 - Little Endian */
        uint64_t ln0_uncorr_blks       : 32; /**< [ 31:  0](RC/W/H) PCS Lane 0 FEC uncorrected blocks.
                                                                 * For 10GBASE-R, corresponds to the Std 802.3 FEC_uncorrected_blocks_counter variable
                                                                 (registers 1.174-1.175).
                                                                 * For 40GBASE-R, correspond to the Std 802.3 FEC_uncorrected_blocks_counter_0 variable
                                                                 (registers 1.700-1.701). */
        uint64_t ln1_uncorr_blks       : 32; /**< [ 63: 32](RC/W/H) PCS Lane 1 FEC corrected blocks.
                                                                 * For 10GBASE-R, reserved.
                                                                 * For 40GBASE-R, corresponds to the Std 802.3 FEC_uncorrected_blocks_counter_1 variable
                                                                 (registers 1.702-1.703). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_fec_uncorr_blks01_s cn; */
} bdk_cgxx_spux_fec_uncorr_blks01_t;

static inline uint64_t BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100b8ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_FEC_UNCORR_BLKS01", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(a,b) bdk_cgxx_spux_fec_uncorr_blks01_t
#define bustype_BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(a,b) "CGXX_SPUX_FEC_UNCORR_BLKS01"
#define device_bar_BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(a,b) (a)
#define arguments_BDK_CGXX_SPUX_FEC_UNCORR_BLKS01(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_fec_uncorr_blks23
 *
 * CGX SPU FEC Uncorrected-Blocks Counters 2/3 Registers
 * This register is valid only when the LPCS type is 40GBASE-R
 * (CGX()_CMR()_CONFIG[LMAC_TYPE] = 0x4). The FEC uncorrected-block counters are defined
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
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_fec_uncorr_blks23_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t ln3_uncorr_blks       : 32; /**< [ 63: 32](RC/W/H) PCS Lane 3 FEC uncorrected blocks. Corresponds to the Std 802.3
                                                                 FEC_uncorrected_blocks_counter_3 variable (registers 1.706-1.707). */
        uint64_t ln2_uncorr_blks       : 32; /**< [ 31:  0](RC/W/H) PCS Lane 2 FEC uncorrected blocks. Corresponds to the Std 802.3
                                                                 FEC_uncorrected_blocks_counter_3 variable (registers 1.704-1.705). */
#else /* Word 0 - Little Endian */
        uint64_t ln2_uncorr_blks       : 32; /**< [ 31:  0](RC/W/H) PCS Lane 2 FEC uncorrected blocks. Corresponds to the Std 802.3
                                                                 FEC_uncorrected_blocks_counter_3 variable (registers 1.704-1.705). */
        uint64_t ln3_uncorr_blks       : 32; /**< [ 63: 32](RC/W/H) PCS Lane 3 FEC uncorrected blocks. Corresponds to the Std 802.3
                                                                 FEC_uncorrected_blocks_counter_3 variable (registers 1.706-1.707). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_fec_uncorr_blks23_s cn; */
} bdk_cgxx_spux_fec_uncorr_blks23_t;

static inline uint64_t BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e80100c0ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_FEC_UNCORR_BLKS23", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(a,b) bdk_cgxx_spux_fec_uncorr_blks23_t
#define bustype_BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(a,b) "CGXX_SPUX_FEC_UNCORR_BLKS23"
#define device_bar_BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(a,b) (a)
#define arguments_BDK_CGXX_SPUX_FEC_UNCORR_BLKS23(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_int
 *
 * CGX SPU Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1C/H) BASE-R PMD training failure. Set when BASE-R PMD link training has failed on the 10GBASE-R
                                                                 lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1C/H) BASE-R PMD training done. Set when the 10GBASE-R lane or all 40GBASE-R lanes have
                                                                 successfully completed BASE-R PMD link training. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1C/H) Autonegotiation complete. Set when CGX()_SPU()_AN_STATUS[AN_COMPLETE] is set,
                                                                 indicating that the autonegotiation process has been completed and the link is up and
                                                                 running using the negotiated highest common denominator (HCD) technology. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1C/H) Autonegotiation link good. Set when the an_link_good variable is set as defined in
                                                                 802.3-2008 Figure 73-11, indicating that autonegotiation has completed. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1C/H) Autonegotiation page received. This bit is set along with
                                                                 CGX()_SPU()_AN_STATUS[PAGE_RX] when a new page has been received and stored in
                                                                 CGX()_SPU()_AN_LP_BASE or CGX()_SPU()_AN_LP_XNP. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1C/H) Uncorrectable FEC error. Set when an FEC block with an uncorrectable error is received on
                                                                 the 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1C/H) Correctable FEC error. Set when an FEC block with a correctable error is received on the
                                                                 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1C/H) 40GBASE-R bit interleaved parity error. Set when a BIP error is detected on any lane.
                                                                 Valid if the LPCS type selected by CGX()_CMR()_CONFIG[LMAC_TYPE] is 40GBASE-R, and
                                                                 never set otherwise. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1C/H) Sync failure debug. This interrupt is provided for link problem debugging help. It is set
                                                                 as follows based on the LPCS type selected by CGX()_CMR()_CONFIG[LMAC_TYPE], and
                                                                 whether FEC is enabled or disabled by CGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions from
                                                                 SYNC_ACQUIRED_1 to SYNC_ACQUIRED_2 (see 802.3-2008 Figure 48-7).
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: Set when sh_invalid_cnt increments to 1 while
                                                                 BLOCK_LOCK is 1 (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: Set when parity_invalid_cnt increments to 1
                                                                 while fec_block_lock is 1 (see 802.3-2008 Figure 74-8). */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1C/H) Loss of lane alignment. Set when lane-to-lane alignment is lost. This is only valid if the
                                                                 logical PCS is a multilane type (i.e. XAUI, RXAUI or 40GBASE-R is selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]), and is never set otherwise. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1C/H) Loss of lane sync. Lane code-group or block synchronization is lost on one or more lanes
                                                                 associated with the LMAC/LPCS. Set as follows based on the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE], and whether FEC is enabled or disabled by
                                                                 CGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions to LOSS_OF_SYNC
                                                                 (see 802.3-2008 Figure 48-7)
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: set when the BLOCK_LOCK variable is cleared on
                                                                 the 10G lane or any 40G lane (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: set when the fec_block_lock variable is cleared
                                                                 on the 10G lane or any 40G lane (see 802.3-2008 Figure 74-8). */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1C/H) Bit lock lost on one or more lanes associated with the LMAC/LPCS. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1C/H) Errored block received. Set when an errored BASE-R block is received as described for
                                                                 CGX()_SPU()_BR_STATUS2[ERR_BLKS]. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1C/H) Set when the receive link goes down, which is the same condition that sets
                                                                 CGX()_SPU()_STATUS2[RCVFLT]. */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1C/H) Set when the receive link comes up, which is the same condition that allows the setting of
                                                                 CGX()_SPU()_STATUS1[RCV_LNK]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1C/H) Set when the receive link comes up, which is the same condition that allows the setting of
                                                                 CGX()_SPU()_STATUS1[RCV_LNK]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1C/H) Set when the receive link goes down, which is the same condition that sets
                                                                 CGX()_SPU()_STATUS2[RCVFLT]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1C/H) Errored block received. Set when an errored BASE-R block is received as described for
                                                                 CGX()_SPU()_BR_STATUS2[ERR_BLKS]. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1C/H) Bit lock lost on one or more lanes associated with the LMAC/LPCS. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1C/H) Loss of lane sync. Lane code-group or block synchronization is lost on one or more lanes
                                                                 associated with the LMAC/LPCS. Set as follows based on the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE], and whether FEC is enabled or disabled by
                                                                 CGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions to LOSS_OF_SYNC
                                                                 (see 802.3-2008 Figure 48-7)
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: set when the BLOCK_LOCK variable is cleared on
                                                                 the 10G lane or any 40G lane (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: set when the fec_block_lock variable is cleared
                                                                 on the 10G lane or any 40G lane (see 802.3-2008 Figure 74-8). */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1C/H) Loss of lane alignment. Set when lane-to-lane alignment is lost. This is only valid if the
                                                                 logical PCS is a multilane type (i.e. XAUI, RXAUI or 40GBASE-R is selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE]), and is never set otherwise. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1C/H) Sync failure debug. This interrupt is provided for link problem debugging help. It is set
                                                                 as follows based on the LPCS type selected by CGX()_CMR()_CONFIG[LMAC_TYPE], and
                                                                 whether FEC is enabled or disabled by CGX()_SPU()_FEC_CONTROL[FEC_EN]:
                                                                 * XAUI or RXAUI: Set when any lane's PCS synchronization state transitions from
                                                                 SYNC_ACQUIRED_1 to SYNC_ACQUIRED_2 (see 802.3-2008 Figure 48-7).
                                                                 * 10GBASE-R or 40GBASE-R with FEC disabled: Set when sh_invalid_cnt increments to 1 while
                                                                 BLOCK_LOCK is 1 (see 802.3-2008 Figure 49-12 and 802.3ba-2010 Figure 82-20).
                                                                 * 10GBASE-R or 40GBASE-R with FEC enabled: Set when parity_invalid_cnt increments to 1
                                                                 while fec_block_lock is 1 (see 802.3-2008 Figure 74-8). */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1C/H) 40GBASE-R bit interleaved parity error. Set when a BIP error is detected on any lane.
                                                                 Valid if the LPCS type selected by CGX()_CMR()_CONFIG[LMAC_TYPE] is 40GBASE-R, and
                                                                 never set otherwise. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1C/H) Correctable FEC error. Set when an FEC block with a correctable error is received on the
                                                                 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1C/H) Uncorrectable FEC error. Set when an FEC block with an uncorrectable error is received on
                                                                 the 10GBASE-R lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R, and never set otherwise. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1C/H) Autonegotiation page received. This bit is set along with
                                                                 CGX()_SPU()_AN_STATUS[PAGE_RX] when a new page has been received and stored in
                                                                 CGX()_SPU()_AN_LP_BASE or CGX()_SPU()_AN_LP_XNP. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1C/H) Autonegotiation link good. Set when the an_link_good variable is set as defined in
                                                                 802.3-2008 Figure 73-11, indicating that autonegotiation has completed. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1C/H) Autonegotiation complete. Set when CGX()_SPU()_AN_STATUS[AN_COMPLETE] is set,
                                                                 indicating that the autonegotiation process has been completed and the link is up and
                                                                 running using the negotiated highest common denominator (HCD) technology. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1C/H) BASE-R PMD training done. Set when the 10GBASE-R lane or all 40GBASE-R lanes have
                                                                 successfully completed BASE-R PMD link training. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1C/H) BASE-R PMD training failure. Set when BASE-R PMD link training has failed on the 10GBASE-R
                                                                 lane or any 40GBASE-R lane. Valid if the LPCS type selected by
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE] is 10GBASE-R or 40GBASE-R and
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is 1, and never set otherwise. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_int_s cn; */
} bdk_cgxx_spux_int_t;

static inline uint64_t BDK_CGXX_SPUX_INT(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_INT(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010220ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_INT", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_INT(a,b) bdk_cgxx_spux_int_t
#define bustype_BDK_CGXX_SPUX_INT(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_INT(a,b) "CGXX_SPUX_INT"
#define device_bar_BDK_CGXX_SPUX_INT(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_INT(a,b) (a)
#define arguments_BDK_CGXX_SPUX_INT(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_int_ena_w1c
 *
 * CGX SPU Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_FAILURE]. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_DONE]. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[AN_COMPLETE]. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[AN_LINK_GOOD]. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[AN_PAGE_RX]. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[FEC_UNCORR]. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[FEC_CORR]. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[BIP_ERR]. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[DBG_SYNC]. */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[ALGNLOS]. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[SYNLOS]. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[BITLCKLS]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[ERR_BLK]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_DOWN]. */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_UP]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_UP]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_DOWN]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[ERR_BLK]. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[BITLCKLS]. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[SYNLOS]. */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[ALGNLOS]. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[DBG_SYNC]. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[BIP_ERR]. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[FEC_CORR]. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[FEC_UNCORR]. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[AN_PAGE_RX]. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[AN_LINK_GOOD]. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[AN_COMPLETE]. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_DONE]. */
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_FAILURE]. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_int_ena_w1c_s cn; */
} bdk_cgxx_spux_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_SPUX_INT_ENA_W1C(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_INT_ENA_W1C(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010230ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_INT_ENA_W1C", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_INT_ENA_W1C(a,b) bdk_cgxx_spux_int_ena_w1c_t
#define bustype_BDK_CGXX_SPUX_INT_ENA_W1C(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_INT_ENA_W1C(a,b) "CGXX_SPUX_INT_ENA_W1C"
#define device_bar_BDK_CGXX_SPUX_INT_ENA_W1C(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_INT_ENA_W1C(a,b) (a)
#define arguments_BDK_CGXX_SPUX_INT_ENA_W1C(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_int_ena_w1s
 *
 * CGX SPU Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_FAILURE]. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_DONE]. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[AN_COMPLETE]. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[AN_LINK_GOOD]. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[AN_PAGE_RX]. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[FEC_UNCORR]. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[FEC_CORR]. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[BIP_ERR]. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[DBG_SYNC]. */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[ALGNLOS]. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[SYNLOS]. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[BITLCKLS]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[ERR_BLK]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_DOWN]. */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_UP]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_UP]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[RX_LINK_DOWN]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[ERR_BLK]. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[BITLCKLS]. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[SYNLOS]. */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[ALGNLOS]. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[DBG_SYNC]. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[BIP_ERR]. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[FEC_CORR]. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[FEC_UNCORR]. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[AN_PAGE_RX]. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[AN_LINK_GOOD]. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[AN_COMPLETE]. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_DONE]. */
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU(0..3)_INT[TRAINING_FAILURE]. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_int_ena_w1s_s cn; */
} bdk_cgxx_spux_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_SPUX_INT_ENA_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_INT_ENA_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010238ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_INT_ENA_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_INT_ENA_W1S(a,b) bdk_cgxx_spux_int_ena_w1s_t
#define bustype_BDK_CGXX_SPUX_INT_ENA_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_INT_ENA_W1S(a,b) "CGXX_SPUX_INT_ENA_W1S"
#define device_bar_BDK_CGXX_SPUX_INT_ENA_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_INT_ENA_W1S(a,b) (a)
#define arguments_BDK_CGXX_SPUX_INT_ENA_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_int_w1s
 *
 * CGX SPU Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[TRAINING_FAILURE]. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[TRAINING_DONE]. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[AN_COMPLETE]. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[AN_LINK_GOOD]. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[AN_PAGE_RX]. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[FEC_UNCORR]. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[FEC_CORR]. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[BIP_ERR]. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[DBG_SYNC]. */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[ALGNLOS]. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[SYNLOS]. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[BITLCKLS]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[ERR_BLK]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[RX_LINK_DOWN]. */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[RX_LINK_UP]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_link_up            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[RX_LINK_UP]. */
        uint64_t rx_link_down          : 1;  /**< [  1:  1](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[RX_LINK_DOWN]. */
        uint64_t err_blk               : 1;  /**< [  2:  2](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[ERR_BLK]. */
        uint64_t bitlckls              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[BITLCKLS]. */
        uint64_t synlos                : 1;  /**< [  4:  4](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[SYNLOS]. */
        uint64_t algnlos               : 1;  /**< [  5:  5](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[ALGNLOS]. */
        uint64_t dbg_sync              : 1;  /**< [  6:  6](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[DBG_SYNC]. */
        uint64_t bip_err               : 1;  /**< [  7:  7](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[BIP_ERR]. */
        uint64_t fec_corr              : 1;  /**< [  8:  8](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[FEC_CORR]. */
        uint64_t fec_uncorr            : 1;  /**< [  9:  9](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[FEC_UNCORR]. */
        uint64_t an_page_rx            : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[AN_PAGE_RX]. */
        uint64_t an_link_good          : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[AN_LINK_GOOD]. */
        uint64_t an_complete           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[AN_COMPLETE]. */
        uint64_t training_done         : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[TRAINING_DONE]. */
        uint64_t training_failure      : 1;  /**< [ 14: 14](R/W1S/H) Reads or sets CGX(0..3)_SPU(0..3)_INT[TRAINING_FAILURE]. */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_int_w1s_s cn; */
} bdk_cgxx_spux_int_w1s_t;

static inline uint64_t BDK_CGXX_SPUX_INT_W1S(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_INT_W1S(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010228ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_INT_W1S", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_INT_W1S(a,b) bdk_cgxx_spux_int_w1s_t
#define bustype_BDK_CGXX_SPUX_INT_W1S(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_INT_W1S(a,b) "CGXX_SPUX_INT_W1S"
#define device_bar_BDK_CGXX_SPUX_INT_W1S(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_INT_W1S(a,b) (a)
#define arguments_BDK_CGXX_SPUX_INT_W1S(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_lpcs_states
 *
 * CGX SPU BASE-X Transmit/Receive States Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_lpcs_states_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_15_63        : 49;
        uint64_t br_rx_sm              : 3;  /**< [ 14: 12](RO/H) BASE-R receive state machine state */
        uint64_t reserved_10_11        : 2;
        uint64_t bx_rx_sm              : 2;  /**< [  9:  8](RO/H) BASE-X receive state machine state */
        uint64_t deskew_am_found       : 4;  /**< [  7:  4](RO/H) 40GBASE-R deskew state machine alignment marker found flag per logical PCS lane ID. */
        uint64_t reserved_3            : 1;
        uint64_t deskew_sm             : 3;  /**< [  2:  0](RO/H) BASE-X and 40GBASE-R deskew state machine state */
#else /* Word 0 - Little Endian */
        uint64_t deskew_sm             : 3;  /**< [  2:  0](RO/H) BASE-X and 40GBASE-R deskew state machine state */
        uint64_t reserved_3            : 1;
        uint64_t deskew_am_found       : 4;  /**< [  7:  4](RO/H) 40GBASE-R deskew state machine alignment marker found flag per logical PCS lane ID. */
        uint64_t bx_rx_sm              : 2;  /**< [  9:  8](RO/H) BASE-X receive state machine state */
        uint64_t reserved_10_11        : 2;
        uint64_t br_rx_sm              : 3;  /**< [ 14: 12](RO/H) BASE-R receive state machine state */
        uint64_t reserved_15_63        : 49;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_lpcs_states_s cn; */
} bdk_cgxx_spux_lpcs_states_t;

static inline uint64_t BDK_CGXX_SPUX_LPCS_STATES(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_LPCS_STATES(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010208ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_LPCS_STATES", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_LPCS_STATES(a,b) bdk_cgxx_spux_lpcs_states_t
#define bustype_BDK_CGXX_SPUX_LPCS_STATES(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_LPCS_STATES(a,b) "CGXX_SPUX_LPCS_STATES"
#define device_bar_BDK_CGXX_SPUX_LPCS_STATES(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_LPCS_STATES(a,b) (a)
#define arguments_BDK_CGXX_SPUX_LPCS_STATES(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_misc_control
 *
 * CGX SPU Miscellaneous Control Registers
 * "* RX logical PCS lane polarity vector <3:0> = [XOR_RXPLRT]<3:0> ^ {4{[RXPLRT]}}.
 * * TX logical PCS lane polarity vector <3:0> = [XOR_TXPLRT]<3:0> ^ {4{[TXPLRT]}}.
 *
 * In short, keep [RXPLRT] and [TXPLRT] cleared, and use [XOR_RXPLRT] and [XOR_TXPLRT] fields to
 * define
 * the polarity per logical PCS lane. Only bit 0 of vector is used for 10GBASE-R, and only bits
 * 1:0 of vector are used for RXAUI."
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_misc_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_13_63        : 51;
        uint64_t rx_packet_dis         : 1;  /**< [ 12: 12](R/W) Receive packet disable. Software can set or clear this bit at any time to gracefully
                                                                 disable or re-enable packet reception by the LPCS. If this bit is set while a packet is
                                                                 being received, the packet is completed and all subsequent received packets are discarded
                                                                 by the LPCS. Similarly, if this bit is cleared while a received packet is being discarded,
                                                                 packet reception resumes after the current packet is fully discarded. When set for a
                                                                 40GBASE-R or 10GBASE-R LMAC/LPCS type (selected by CGX()_CMR()_CONFIG[LMAC_TYPE]),
                                                                 received errors and faults will be ignored while receive packets are discarded; idles will
                                                                 be sent to the MAC layer (SMU) and the errored blocks counter
                                                                 (CGX()_SPU()_BR_STATUS2[ERR_BLKS]) will not increment. */
        uint64_t skip_after_term       : 1;  /**< [ 11: 11](R/W) Enable sending of idle skip after terminate. This bit is meaningful when the logical PCS
                                                                 type is XAUI or RXAUI (selected by CGX()_CMR()_CONFIG[LMAC_TYPE]), and has no
                                                                 effect otherwise. When set, the LMAC/LPCS transmits more idle skip columns for clock
                                                                 compensation. Typically set in HiGig/HiGig2 modes; clear otherwise. This field can be set
                                                                 to ensure sufficient density of XAUI idle skip (||R||) columns with a small transmit
                                                                 inter-frame gap (IFG) in order to allow the link partner's receiver to delete ||R||
                                                                 columns as needed for clock rate compensation. It is usually set when the LMAC's transmit
                                                                 IFG is set to 8 bytes in HiGig/HiGig2 modes (i.e. CGX()_SMU()_TX_IFG[IFG1] +
                                                                 CGX()_SMU()_TX_IFG[IFG2] = 8), and should be cleared when the transmit IFG is
                                                                 greater than 8 bytes. When this bit is set, the SPU will send an ||R|| column after a
                                                                 ||T0|| column (terminate in lane 0) if no ||R|| was sent in the previous IFG. This is a
                                                                 minor deviation from the functionality specified in 802.3-2008 Figure 48-6 (PCS transmit
                                                                 source state diagram), whereby the state will transition directly from SEND_DATA to
                                                                 SEND_RANDOM_R after ||T0|| if no ||R|| was transmitted in the previous IFG. Sending ||R||
                                                                 after ||T0|| only (and not ||T1||, |T2|| or ||T3||) ensures that the check_end function at
                                                                 the receiving end, as defined in 802.3-2008 sub-clause 48.2.6.1.4, does not detect an
                                                                 error due to this functional change. When this bit is clear, the LMAC will fully conform
                                                                 to the functionality specified in Figure 48-6. */
        uint64_t intlv_rdisp           : 1;  /**< [ 10: 10](R/W) RXAUI interleaved running disparity. This bit is meaningful when the logical PCS type is
                                                                 RXAUI (CGX()_CMR()_CONFIG[LMAC_TYPE] = RXAUI), and has no effect otherwise. It
                                                                 selects which disparity calculation to use when combining or splitting the RXAUI lanes, as
                                                                 follows:

                                                                 _ 0 = Common running disparity. Common running disparity is computed for even and odd
                                                                 code-
                                                                 groups of an RXAUI lane, i.e. interleave lanes before PCS layer as described in the Dune
                                                                 Networks/Broadcom RXAUI v2.1 specification. This obeys 6.25GHz SerDes disparity.

                                                                 _ 1 = Interleaved running disparity: Running disparity is computed separately for even and
                                                                 odd code-groups of an RXAUI lane, i.e. interleave lanes after PCS layer as described in
                                                                 the Marvell RXAUI Interface specification. This does not obey 6.25GHz SerDes disparity. */
        uint64_t xor_rxplrt            : 4;  /**< [  9:  6](R/W) RX polarity control per logical PCS lane */
        uint64_t xor_txplrt            : 4;  /**< [  5:  2](R/W) TX polarity control per logical PCS lane */
        uint64_t rxplrt                : 1;  /**< [  1:  1](R/W) Receive polarity. 1 = inverted polarity, 0 = normal polarity. */
        uint64_t txplrt                : 1;  /**< [  0:  0](R/W) Transmit polarity. 1 = inverted polarity, 0 = normal polarity. */
#else /* Word 0 - Little Endian */
        uint64_t txplrt                : 1;  /**< [  0:  0](R/W) Transmit polarity. 1 = inverted polarity, 0 = normal polarity. */
        uint64_t rxplrt                : 1;  /**< [  1:  1](R/W) Receive polarity. 1 = inverted polarity, 0 = normal polarity. */
        uint64_t xor_txplrt            : 4;  /**< [  5:  2](R/W) TX polarity control per logical PCS lane */
        uint64_t xor_rxplrt            : 4;  /**< [  9:  6](R/W) RX polarity control per logical PCS lane */
        uint64_t intlv_rdisp           : 1;  /**< [ 10: 10](R/W) RXAUI interleaved running disparity. This bit is meaningful when the logical PCS type is
                                                                 RXAUI (CGX()_CMR()_CONFIG[LMAC_TYPE] = RXAUI), and has no effect otherwise. It
                                                                 selects which disparity calculation to use when combining or splitting the RXAUI lanes, as
                                                                 follows:

                                                                 _ 0 = Common running disparity. Common running disparity is computed for even and odd
                                                                 code-
                                                                 groups of an RXAUI lane, i.e. interleave lanes before PCS layer as described in the Dune
                                                                 Networks/Broadcom RXAUI v2.1 specification. This obeys 6.25GHz SerDes disparity.

                                                                 _ 1 = Interleaved running disparity: Running disparity is computed separately for even and
                                                                 odd code-groups of an RXAUI lane, i.e. interleave lanes after PCS layer as described in
                                                                 the Marvell RXAUI Interface specification. This does not obey 6.25GHz SerDes disparity. */
        uint64_t skip_after_term       : 1;  /**< [ 11: 11](R/W) Enable sending of idle skip after terminate. This bit is meaningful when the logical PCS
                                                                 type is XAUI or RXAUI (selected by CGX()_CMR()_CONFIG[LMAC_TYPE]), and has no
                                                                 effect otherwise. When set, the LMAC/LPCS transmits more idle skip columns for clock
                                                                 compensation. Typically set in HiGig/HiGig2 modes; clear otherwise. This field can be set
                                                                 to ensure sufficient density of XAUI idle skip (||R||) columns with a small transmit
                                                                 inter-frame gap (IFG) in order to allow the link partner's receiver to delete ||R||
                                                                 columns as needed for clock rate compensation. It is usually set when the LMAC's transmit
                                                                 IFG is set to 8 bytes in HiGig/HiGig2 modes (i.e. CGX()_SMU()_TX_IFG[IFG1] +
                                                                 CGX()_SMU()_TX_IFG[IFG2] = 8), and should be cleared when the transmit IFG is
                                                                 greater than 8 bytes. When this bit is set, the SPU will send an ||R|| column after a
                                                                 ||T0|| column (terminate in lane 0) if no ||R|| was sent in the previous IFG. This is a
                                                                 minor deviation from the functionality specified in 802.3-2008 Figure 48-6 (PCS transmit
                                                                 source state diagram), whereby the state will transition directly from SEND_DATA to
                                                                 SEND_RANDOM_R after ||T0|| if no ||R|| was transmitted in the previous IFG. Sending ||R||
                                                                 after ||T0|| only (and not ||T1||, |T2|| or ||T3||) ensures that the check_end function at
                                                                 the receiving end, as defined in 802.3-2008 sub-clause 48.2.6.1.4, does not detect an
                                                                 error due to this functional change. When this bit is clear, the LMAC will fully conform
                                                                 to the functionality specified in Figure 48-6. */
        uint64_t rx_packet_dis         : 1;  /**< [ 12: 12](R/W) Receive packet disable. Software can set or clear this bit at any time to gracefully
                                                                 disable or re-enable packet reception by the LPCS. If this bit is set while a packet is
                                                                 being received, the packet is completed and all subsequent received packets are discarded
                                                                 by the LPCS. Similarly, if this bit is cleared while a received packet is being discarded,
                                                                 packet reception resumes after the current packet is fully discarded. When set for a
                                                                 40GBASE-R or 10GBASE-R LMAC/LPCS type (selected by CGX()_CMR()_CONFIG[LMAC_TYPE]),
                                                                 received errors and faults will be ignored while receive packets are discarded; idles will
                                                                 be sent to the MAC layer (SMU) and the errored blocks counter
                                                                 (CGX()_SPU()_BR_STATUS2[ERR_BLKS]) will not increment. */
        uint64_t reserved_13_63        : 51;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_misc_control_s cn; */
} bdk_cgxx_spux_misc_control_t;

static inline uint64_t BDK_CGXX_SPUX_MISC_CONTROL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_MISC_CONTROL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010218ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_MISC_CONTROL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_MISC_CONTROL(a,b) bdk_cgxx_spux_misc_control_t
#define bustype_BDK_CGXX_SPUX_MISC_CONTROL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_MISC_CONTROL(a,b) "CGXX_SPUX_MISC_CONTROL"
#define device_bar_BDK_CGXX_SPUX_MISC_CONTROL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_MISC_CONTROL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_MISC_CONTROL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_spd_abil
 *
 * CGX SPU PCS Speed Ability Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_spd_abil_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t hundredgb             : 1;  /**< [  3:  3](RO) 100G capable. Always 0. */
        uint64_t fortygb               : 1;  /**< [  2:  2](RO/H) 40G capable. Always 1. */
        uint64_t tenpasst              : 1;  /**< [  1:  1](RO) 10PASS-TS/2BASE-TL capable. Always 0. */
        uint64_t tengb                 : 1;  /**< [  0:  0](RO/H) 10G capable. Always 1. */
#else /* Word 0 - Little Endian */
        uint64_t tengb                 : 1;  /**< [  0:  0](RO/H) 10G capable. Always 1. */
        uint64_t tenpasst              : 1;  /**< [  1:  1](RO) 10PASS-TS/2BASE-TL capable. Always 0. */
        uint64_t fortygb               : 1;  /**< [  2:  2](RO/H) 40G capable. Always 1. */
        uint64_t hundredgb             : 1;  /**< [  3:  3](RO) 100G capable. Always 0. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_spd_abil_s cn; */
} bdk_cgxx_spux_spd_abil_t;

static inline uint64_t BDK_CGXX_SPUX_SPD_ABIL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_SPD_ABIL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010010ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_SPD_ABIL", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_SPD_ABIL(a,b) bdk_cgxx_spux_spd_abil_t
#define bustype_BDK_CGXX_SPUX_SPD_ABIL(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_SPD_ABIL(a,b) "CGXX_SPUX_SPD_ABIL"
#define device_bar_BDK_CGXX_SPUX_SPD_ABIL(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_SPD_ABIL(a,b) (a)
#define arguments_BDK_CGXX_SPUX_SPD_ABIL(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_status1
 *
 * CGX SPU Status 1 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_status1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t flt                   : 1;  /**< [  7:  7](RO/H) Fault condition detected.
                                                                 This bit is a logical OR of CGX()_SPU()_STATUS2[XMTFLT, RCVFLT]. */
        uint64_t reserved_3_6          : 4;
        uint64_t rcv_lnk               : 1;  /**< [  2:  2](R/W1S/H) PCS receive link status:
                                                                   0 = receive link down.
                                                                   1 = receive link up.

                                                                 This is a latching-low bit; it stays clear until the register is read by software.

                                                                 For a BASE-X logical PCS type (in the associated CGX()_CMR()_CONFIG[LMAC_TYPE] =
                                                                 XAUI or RXAUI), this is a latching-low version of CGX()_SPU()_BX_STATUS[ALIGND].

                                                                 For a BASE-R logical PCS type (in the associated CGX()_CMR()_CONFIG[LMAC_TYPE] =
                                                                 10G_R or 40G_R), this is a latching-low version of
                                                                 CGX()_SPU()_BR_STATUS1[RCV_LNK].

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-set
                                                                 bit, rather than latching low read-only as specified in 802.3. */
        uint64_t lpable                : 1;  /**< [  1:  1](RO) Low-power ability. Always returns 1 to indicate that the LPCS supports low-power mode. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t lpable                : 1;  /**< [  1:  1](RO) Low-power ability. Always returns 1 to indicate that the LPCS supports low-power mode. */
        uint64_t rcv_lnk               : 1;  /**< [  2:  2](R/W1S/H) PCS receive link status:
                                                                   0 = receive link down.
                                                                   1 = receive link up.

                                                                 This is a latching-low bit; it stays clear until the register is read by software.

                                                                 For a BASE-X logical PCS type (in the associated CGX()_CMR()_CONFIG[LMAC_TYPE] =
                                                                 XAUI or RXAUI), this is a latching-low version of CGX()_SPU()_BX_STATUS[ALIGND].

                                                                 For a BASE-R logical PCS type (in the associated CGX()_CMR()_CONFIG[LMAC_TYPE] =
                                                                 10G_R or 40G_R), this is a latching-low version of
                                                                 CGX()_SPU()_BR_STATUS1[RCV_LNK].

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-set
                                                                 bit, rather than latching low read-only as specified in 802.3. */
        uint64_t reserved_3_6          : 4;
        uint64_t flt                   : 1;  /**< [  7:  7](RO/H) Fault condition detected.
                                                                 This bit is a logical OR of CGX()_SPU()_STATUS2[XMTFLT, RCVFLT]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_status1_s cn; */
} bdk_cgxx_spux_status1_t;

static inline uint64_t BDK_CGXX_SPUX_STATUS1(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_STATUS1(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010008ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_STATUS1", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_STATUS1(a,b) bdk_cgxx_spux_status1_t
#define bustype_BDK_CGXX_SPUX_STATUS1(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_STATUS1(a,b) "CGXX_SPUX_STATUS1"
#define device_bar_BDK_CGXX_SPUX_STATUS1(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_STATUS1(a,b) (a)
#define arguments_BDK_CGXX_SPUX_STATUS1(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu#_status2
 *
 * CGX SPU Status 2 Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spux_status2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t dev                   : 2;  /**< [ 15: 14](RO/H) Device present. Always returns 0x2 to indicate a device is present at this address. */
        uint64_t reserved_12_13        : 2;
        uint64_t xmtflt                : 1;  /**< [ 11: 11](RO/H) Transmit fault. Always returns 0. */
        uint64_t rcvflt                : 1;  /**< [ 10: 10](R/W1C/H) Receive fault: 1 = receive fault, 0 = no receive fault. Latching high bit; stays set until
                                                                 software writes a 1.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-clear
                                                                 bit, rather than latching high read-only as specified in 802.3. */
        uint64_t reserved_6_9          : 4;
        uint64_t hundredgb_r           : 1;  /**< [  5:  5](RO) 100GBASE-R capable. Always 0. */
        uint64_t fortygb_r             : 1;  /**< [  4:  4](RO/H) 40GBASE-R capable. Always 1. */
        uint64_t tengb_t               : 1;  /**< [  3:  3](RO) 10GBASE-T capable. Always 0. */
        uint64_t tengb_w               : 1;  /**< [  2:  2](RO) 10GBASE-W capable. Always 0. */
        uint64_t tengb_x               : 1;  /**< [  1:  1](RO/H) 10GBASE-X capable. Always 1. */
        uint64_t tengb_r               : 1;  /**< [  0:  0](RO/H) 10GBASE-R capable. Always 1. */
#else /* Word 0 - Little Endian */
        uint64_t tengb_r               : 1;  /**< [  0:  0](RO/H) 10GBASE-R capable. Always 1. */
        uint64_t tengb_x               : 1;  /**< [  1:  1](RO/H) 10GBASE-X capable. Always 1. */
        uint64_t tengb_w               : 1;  /**< [  2:  2](RO) 10GBASE-W capable. Always 0. */
        uint64_t tengb_t               : 1;  /**< [  3:  3](RO) 10GBASE-T capable. Always 0. */
        uint64_t fortygb_r             : 1;  /**< [  4:  4](RO/H) 40GBASE-R capable. Always 1. */
        uint64_t hundredgb_r           : 1;  /**< [  5:  5](RO) 100GBASE-R capable. Always 0. */
        uint64_t reserved_6_9          : 4;
        uint64_t rcvflt                : 1;  /**< [ 10: 10](R/W1C/H) Receive fault: 1 = receive fault, 0 = no receive fault. Latching high bit; stays set until
                                                                 software writes a 1.

                                                                 Note that in order to avoid read side effects, this is implemented as a write-1-to-clear
                                                                 bit, rather than latching high read-only as specified in 802.3. */
        uint64_t xmtflt                : 1;  /**< [ 11: 11](RO/H) Transmit fault. Always returns 0. */
        uint64_t reserved_12_13        : 2;
        uint64_t dev                   : 2;  /**< [ 15: 14](RO/H) Device present. Always returns 0x2 to indicate a device is present at this address. */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spux_status2_s cn; */
} bdk_cgxx_spux_status2_t;

static inline uint64_t BDK_CGXX_SPUX_STATUS2(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPUX_STATUS2(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010020ll + 0x1000000ll * ((a) & 0x3) + 0x100000ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPUX_STATUS2", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPUX_STATUS2(a,b) bdk_cgxx_spux_status2_t
#define bustype_BDK_CGXX_SPUX_STATUS2(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPUX_STATUS2(a,b) "CGXX_SPUX_STATUS2"
#define device_bar_BDK_CGXX_SPUX_STATUS2(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPUX_STATUS2(a,b) (a)
#define arguments_BDK_CGXX_SPUX_STATUS2(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu_bist_status
 *
 * CGX SPU BIST Status Registers
 * This register provides memory BIST status from the SPU receive buffer lane FIFOs.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t rx_buf_bist_status    : 4;  /**< [  3:  0](RO/H) SPU receive buffer BIST status for lanes 3-0. One bit per SerDes lane, set to indicate
                                                                 BIST
                                                                 failure for the associated receive buffer lane FIFO. */
#else /* Word 0 - Little Endian */
        uint64_t rx_buf_bist_status    : 4;  /**< [  3:  0](RO/H) SPU receive buffer BIST status for lanes 3-0. One bit per SerDes lane, set to indicate
                                                                 BIST
                                                                 failure for the associated receive buffer lane FIFO. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_bist_status_s cn; */
} bdk_cgxx_spu_bist_status_t;

static inline uint64_t BDK_CGXX_SPU_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010330ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_BIST_STATUS(a) bdk_cgxx_spu_bist_status_t
#define bustype_BDK_CGXX_SPU_BIST_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_BIST_STATUS(a) "CGXX_SPU_BIST_STATUS"
#define device_bar_BDK_CGXX_SPU_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_BIST_STATUS(a) (a)
#define arguments_BDK_CGXX_SPU_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_dbg_control
 *
 * CGX SPU Debug Control Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_dbg_control_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_56_63        : 8;
        uint64_t ms_clk_period         : 12; /**< [ 55: 44](R/W) Millisecond clock period. Specifies the number of microsecond clock ticks per millisecond,
                                                                 minus 1. The default value of 999 (0x3E7) should be used during normal operation; other
                                                                 values may be used for test/debug purposes. */
        uint64_t us_clk_period         : 12; /**< [ 43: 32](R/W) Microsecond clock period. Specifies the number of SCLK cycles per microseconds, minus 1.
                                                                 For example, if SCLK runs at 1.3 GHz, the number of SCLK cycles per microsecond is 1,300
                                                                 so the value of this field should be 1,299 (0x513). This is used by the BASE-R BER monitor
                                                                 timers. */
        uint64_t reserved_31           : 1;
        uint64_t br_ber_mon_dis        : 1;  /**< [ 30: 30](R/W) BASE-R bit error rate monitor disable. This bit should be clear for normal operation.
                                                                 Setting it disables the BASE-R BER monitor state machine defined in 802.3-2008 Figure
                                                                 49-13 for 10GBASE-R and 802.3ba-2010 Figure 82-13 for 40GBASE-R. */
        uint64_t an_nonce_match_dis    : 1;  /**< [ 29: 29](R/W) Autonegotiation nonce match disable. This bit should be clear for normal operation.
                                                                 Setting it disables Nonce Match check by forcing nonce_match variable to 0 in the
                                                                 autonegotiation arbitration state diagram, as defined in 802.3-2008 Figure 73-11. This bit
                                                                 can
                                                                 be set by software for test purposes, e.g. for running autonegotiation in loopback mode. */
        uint64_t timestamp_norm_dis    : 1;  /**< [ 28: 28](R/W) 40GBASE-R RX timestamp normalization disable. This bit controls the generation of the
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
                                                                 CGX()_SPU_SDS()_SKEW_STATUS[SKEW_STATUS] field (CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP]
                                                                 sub-field). If
                                                                 alignment markers are transmitted at about the same time on all lanes by the link partner,
                                                                 then the difference between the CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] values for a pair
                                                                 of lanes represents the
                                                                 approximate skew between those lanes.

                                                                 SPU uses the 40GBASE-R LMAC's programmed PCS lane 0 as a reference and computes the
                                                                 CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] delta of every other lane relative to PCS lane 0.
                                                                 When normalization is
                                                                 enabled, SPU adjusts the timestamp of a received SOP by subtracting the receiving lane's
                                                                 CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] delta from the captured timestamp value. The
                                                                 adjusted/normalized timestamp
                                                                 value is then passed to SMU along with the SOP.

                                                                 Software can determine the actual maximum skew of a 40GBASE-R link by examining the
                                                                 CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] values in the CGX()_SPU_SDS()_SKEW_STATUS
                                                                 registers, and decide if
                                                                 timestamp normalization should be enabled or disabled to improve PTP accuracy.
                                                                 Normalization improves accuracy for larger skew values but reduces the accuracy (due to
                                                                 timestamp measurement errors) for small skew values. */
        uint64_t rx_buf_flip_synd      : 8;  /**< [ 27: 20](R/W) Flip SPU receive buffer FIFO ECC bits. Two bits per SerDes lane; used to inject single-bit
                                                                 and
                                                                 double-bit errors into the ECC field on writes to the associated SPU receive buffer lane
                                                                 FIFO, as
                                                                 follows:
                                                                 0x0 = Normal operation.
                                                                 0x1 = SBE on ECC bit 0.
                                                                 0x2 = SBE on ECC bit 1.
                                                                 0x3 = DBE on ECC bits 1:0. */
        uint64_t br_pmd_train_soft_en  : 1;  /**< [ 19: 19](R/W) Enable BASE-R PMD software controlled link training. This bit configures the operation
                                                                 mode for BASE-R link training for all LMACs and lanes. When this bit is set along with
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] for a given LMAC, the BASE-R link training
                                                                 protocol for that LMAC is executed under software control, whereby the contents the
                                                                 CGX()_SPU()_BR_PMD_LD_CUP and CGX()_SPU()_BR_PMD_LD_REP registers are
                                                                 updated by software. When this bit is clear and
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is set, the link training protocol is fully
                                                                 automated in hardware, whereby the contents CGX()_SPU()_BR_PMD_LD_CUP and
                                                                 CGX()_SPU()_BR_PMD_LD_REP registers are automatically updated by hardware. */
        uint64_t an_arb_link_chk_en    : 1;  /**< [ 18: 18](R/W) Enable link status checking by autonegotiation arbitration state machine. When
                                                                 autonegotiation is enabled (CGX()_SPU()_AN_CONTROL[AN_EN] is set), this bit controls
                                                                 the behavior of the autonegotiation arbitration state machine when it reaches the AN GOOD
                                                                 CHECK state after DME pages are successfully exchanged, as defined in Figure 73-11 in
                                                                 802.3-2008.

                                                                 When this bit is set and the negotiated highest common denominator (HCD) technology
                                                                 matches CGX()_CMR()_CONFIG[LMAC_TYPE], the autonegotiation arbitration SM
                                                                 performs the actions defined for the AN GOOD CHECK state in Figure 73-11, i.e. run the
                                                                 link_fail_inhibit timer and eventually transition to the AN GOOD or TRANSMIT DISABLE
                                                                 state.

                                                                 When this bit is clear or the HCD technology does not match CGX()_CMR()_CONFIG[LMAC_TYPE],
                                                                 the AN arbitration
                                                                 SM stays in the AN GOOD CHECK state, with the expectation that software will perform the
                                                                 appropriate actions to complete the autonegotiation protocol, as follows:

                                                                 * If this bit is clear and the HCD technology matches CGX()_CMR()_CONFIG[LMAC_TYPE], clear
                                                                 CGX()_SPU()_AN_CONTROL[AN_EN].

                                                                 * Otherwise, disable the LPCS by clearing the CGX()_CMR()_CONFIG[ENABLE], clear
                                                                 CGX()_SPU()_AN_CONTROL[AN_EN], reconfigure the LPCS with the correct
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE],
                                                                 and re-enable the LPCS by setting CGX()_CMR()_CONFIG[ENABLE].

                                                                 In both cases, software should implement the link_fail_inhibit timer and verify the link
                                                                 status as specified for the AN GOOD CHECK state. */
        uint64_t rx_buf_cor_dis        : 1;  /**< [ 17: 17](R/W) When set, disables ECC correction on all SPU receive buffer FIFOs. */
        uint64_t scramble_dis          : 1;  /**< [ 16: 16](R/W) BASE-R scrambler/descrambler disable. Setting this bit to 1 disables the BASE-R scrambler
                                                                 & descrambler functions and FEC PN-2112 scrambler & descrambler functions for debug
                                                                 purposes. */
        uint64_t reserved_15           : 1;
        uint64_t marker_rxp            : 15; /**< [ 14:  0](R/W) BASE-R alignment marker receive period. For a multilane BASE-R logical PCS (i.e.
                                                                 40GBASE-R), this field specifies the expected alignment marker receive period per lane,
                                                                 i.e. the expected number of received 66b non-marker blocks between consecutive markers on
                                                                 the same lane. The default value corresponds to a period of 16363 blocks (exclusive) as
                                                                 specified in 802.3ba-2010. Must be greater than 64. */
#else /* Word 0 - Little Endian */
        uint64_t marker_rxp            : 15; /**< [ 14:  0](R/W) BASE-R alignment marker receive period. For a multilane BASE-R logical PCS (i.e.
                                                                 40GBASE-R), this field specifies the expected alignment marker receive period per lane,
                                                                 i.e. the expected number of received 66b non-marker blocks between consecutive markers on
                                                                 the same lane. The default value corresponds to a period of 16363 blocks (exclusive) as
                                                                 specified in 802.3ba-2010. Must be greater than 64. */
        uint64_t reserved_15           : 1;
        uint64_t scramble_dis          : 1;  /**< [ 16: 16](R/W) BASE-R scrambler/descrambler disable. Setting this bit to 1 disables the BASE-R scrambler
                                                                 & descrambler functions and FEC PN-2112 scrambler & descrambler functions for debug
                                                                 purposes. */
        uint64_t rx_buf_cor_dis        : 1;  /**< [ 17: 17](R/W) When set, disables ECC correction on all SPU receive buffer FIFOs. */
        uint64_t an_arb_link_chk_en    : 1;  /**< [ 18: 18](R/W) Enable link status checking by autonegotiation arbitration state machine. When
                                                                 autonegotiation is enabled (CGX()_SPU()_AN_CONTROL[AN_EN] is set), this bit controls
                                                                 the behavior of the autonegotiation arbitration state machine when it reaches the AN GOOD
                                                                 CHECK state after DME pages are successfully exchanged, as defined in Figure 73-11 in
                                                                 802.3-2008.

                                                                 When this bit is set and the negotiated highest common denominator (HCD) technology
                                                                 matches CGX()_CMR()_CONFIG[LMAC_TYPE], the autonegotiation arbitration SM
                                                                 performs the actions defined for the AN GOOD CHECK state in Figure 73-11, i.e. run the
                                                                 link_fail_inhibit timer and eventually transition to the AN GOOD or TRANSMIT DISABLE
                                                                 state.

                                                                 When this bit is clear or the HCD technology does not match CGX()_CMR()_CONFIG[LMAC_TYPE],
                                                                 the AN arbitration
                                                                 SM stays in the AN GOOD CHECK state, with the expectation that software will perform the
                                                                 appropriate actions to complete the autonegotiation protocol, as follows:

                                                                 * If this bit is clear and the HCD technology matches CGX()_CMR()_CONFIG[LMAC_TYPE], clear
                                                                 CGX()_SPU()_AN_CONTROL[AN_EN].

                                                                 * Otherwise, disable the LPCS by clearing the CGX()_CMR()_CONFIG[ENABLE], clear
                                                                 CGX()_SPU()_AN_CONTROL[AN_EN], reconfigure the LPCS with the correct
                                                                 CGX()_CMR()_CONFIG[LMAC_TYPE],
                                                                 and re-enable the LPCS by setting CGX()_CMR()_CONFIG[ENABLE].

                                                                 In both cases, software should implement the link_fail_inhibit timer and verify the link
                                                                 status as specified for the AN GOOD CHECK state. */
        uint64_t br_pmd_train_soft_en  : 1;  /**< [ 19: 19](R/W) Enable BASE-R PMD software controlled link training. This bit configures the operation
                                                                 mode for BASE-R link training for all LMACs and lanes. When this bit is set along with
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] for a given LMAC, the BASE-R link training
                                                                 protocol for that LMAC is executed under software control, whereby the contents the
                                                                 CGX()_SPU()_BR_PMD_LD_CUP and CGX()_SPU()_BR_PMD_LD_REP registers are
                                                                 updated by software. When this bit is clear and
                                                                 CGX()_SPU()_BR_PMD_CONTROL[TRAIN_EN] is set, the link training protocol is fully
                                                                 automated in hardware, whereby the contents CGX()_SPU()_BR_PMD_LD_CUP and
                                                                 CGX()_SPU()_BR_PMD_LD_REP registers are automatically updated by hardware. */
        uint64_t rx_buf_flip_synd      : 8;  /**< [ 27: 20](R/W) Flip SPU receive buffer FIFO ECC bits. Two bits per SerDes lane; used to inject single-bit
                                                                 and
                                                                 double-bit errors into the ECC field on writes to the associated SPU receive buffer lane
                                                                 FIFO, as
                                                                 follows:
                                                                 0x0 = Normal operation.
                                                                 0x1 = SBE on ECC bit 0.
                                                                 0x2 = SBE on ECC bit 1.
                                                                 0x3 = DBE on ECC bits 1:0. */
        uint64_t timestamp_norm_dis    : 1;  /**< [ 28: 28](R/W) 40GBASE-R RX timestamp normalization disable. This bit controls the generation of the
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
                                                                 CGX()_SPU_SDS()_SKEW_STATUS[SKEW_STATUS] field (CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP]
                                                                 sub-field). If
                                                                 alignment markers are transmitted at about the same time on all lanes by the link partner,
                                                                 then the difference between the CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] values for a pair
                                                                 of lanes represents the
                                                                 approximate skew between those lanes.

                                                                 SPU uses the 40GBASE-R LMAC's programmed PCS lane 0 as a reference and computes the
                                                                 CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] delta of every other lane relative to PCS lane 0.
                                                                 When normalization is
                                                                 enabled, SPU adjusts the timestamp of a received SOP by subtracting the receiving lane's
                                                                 CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] delta from the captured timestamp value. The
                                                                 adjusted/normalized timestamp
                                                                 value is then passed to SMU along with the SOP.

                                                                 Software can determine the actual maximum skew of a 40GBASE-R link by examining the
                                                                 CGX_SPU_SDS_SKEW_STATUS_S[AM_TIMESTAMP] values in the CGX()_SPU_SDS()_SKEW_STATUS
                                                                 registers, and decide if
                                                                 timestamp normalization should be enabled or disabled to improve PTP accuracy.
                                                                 Normalization improves accuracy for larger skew values but reduces the accuracy (due to
                                                                 timestamp measurement errors) for small skew values. */
        uint64_t an_nonce_match_dis    : 1;  /**< [ 29: 29](R/W) Autonegotiation nonce match disable. This bit should be clear for normal operation.
                                                                 Setting it disables Nonce Match check by forcing nonce_match variable to 0 in the
                                                                 autonegotiation arbitration state diagram, as defined in 802.3-2008 Figure 73-11. This bit
                                                                 can
                                                                 be set by software for test purposes, e.g. for running autonegotiation in loopback mode. */
        uint64_t br_ber_mon_dis        : 1;  /**< [ 30: 30](R/W) BASE-R bit error rate monitor disable. This bit should be clear for normal operation.
                                                                 Setting it disables the BASE-R BER monitor state machine defined in 802.3-2008 Figure
                                                                 49-13 for 10GBASE-R and 802.3ba-2010 Figure 82-13 for 40GBASE-R. */
        uint64_t reserved_31           : 1;
        uint64_t us_clk_period         : 12; /**< [ 43: 32](R/W) Microsecond clock period. Specifies the number of SCLK cycles per microseconds, minus 1.
                                                                 For example, if SCLK runs at 1.3 GHz, the number of SCLK cycles per microsecond is 1,300
                                                                 so the value of this field should be 1,299 (0x513). This is used by the BASE-R BER monitor
                                                                 timers. */
        uint64_t ms_clk_period         : 12; /**< [ 55: 44](R/W) Millisecond clock period. Specifies the number of microsecond clock ticks per millisecond,
                                                                 minus 1. The default value of 999 (0x3E7) should be used during normal operation; other
                                                                 values may be used for test/debug purposes. */
        uint64_t reserved_56_63        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_dbg_control_s cn; */
} bdk_cgxx_spu_dbg_control_t;

static inline uint64_t BDK_CGXX_SPU_DBG_CONTROL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_DBG_CONTROL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010300ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_DBG_CONTROL", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_DBG_CONTROL(a) bdk_cgxx_spu_dbg_control_t
#define bustype_BDK_CGXX_SPU_DBG_CONTROL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_DBG_CONTROL(a) "CGXX_SPU_DBG_CONTROL"
#define device_bar_BDK_CGXX_SPU_DBG_CONTROL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_DBG_CONTROL(a) (a)
#define arguments_BDK_CGXX_SPU_DBG_CONTROL(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_mem_int
 *
 * CGX SPU Memory Interrupt Registers
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_mem_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1C/H) SPU receive buffer single-bit error for lanes 3-0. One bit per physical SerDes lane. Each
                                                                 bit is set when the associated receive buffer lane FIFO detects a single-bit ECC error. */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1C/H) SPU receive buffer double-bit error for lanes 3-0. One bit per physical SerDes lane. Each
                                                                 bit is set when the associated receive buffer lane FIFO detects a double-bit ECC error. */
#else /* Word 0 - Little Endian */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1C/H) SPU receive buffer double-bit error for lanes 3-0. One bit per physical SerDes lane. Each
                                                                 bit is set when the associated receive buffer lane FIFO detects a double-bit ECC error. */
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1C/H) SPU receive buffer single-bit error for lanes 3-0. One bit per physical SerDes lane. Each
                                                                 bit is set when the associated receive buffer lane FIFO detects a single-bit ECC error. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_mem_int_s cn; */
} bdk_cgxx_spu_mem_int_t;

static inline uint64_t BDK_CGXX_SPU_MEM_INT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_MEM_INT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010310ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_MEM_INT", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_MEM_INT(a) bdk_cgxx_spu_mem_int_t
#define bustype_BDK_CGXX_SPU_MEM_INT(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_MEM_INT(a) "CGXX_SPU_MEM_INT"
#define device_bar_BDK_CGXX_SPU_MEM_INT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_MEM_INT(a) (a)
#define arguments_BDK_CGXX_SPU_MEM_INT(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_mem_int_ena_w1c
 *
 * CGX SPU Memory Interrupt Enable Clear Registers
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_mem_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_SBE]. */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_DBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_DBE]. */
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1C/H) Reads or clears enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_SBE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_mem_int_ena_w1c_s cn; */
} bdk_cgxx_spu_mem_int_ena_w1c_t;

static inline uint64_t BDK_CGXX_SPU_MEM_INT_ENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_MEM_INT_ENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010320ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_MEM_INT_ENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_MEM_INT_ENA_W1C(a) bdk_cgxx_spu_mem_int_ena_w1c_t
#define bustype_BDK_CGXX_SPU_MEM_INT_ENA_W1C(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_MEM_INT_ENA_W1C(a) "CGXX_SPU_MEM_INT_ENA_W1C"
#define device_bar_BDK_CGXX_SPU_MEM_INT_ENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_MEM_INT_ENA_W1C(a) (a)
#define arguments_BDK_CGXX_SPU_MEM_INT_ENA_W1C(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_mem_int_ena_w1s
 *
 * CGX SPU Memory Interrupt Enable Set Registers
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_mem_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_SBE]. */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_DBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_DBE]. */
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1S/H) Reads or sets enable for CGX(0..3)_SPU_MEM_INT[RX_BUF_SBE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_mem_int_ena_w1s_s cn; */
} bdk_cgxx_spu_mem_int_ena_w1s_t;

static inline uint64_t BDK_CGXX_SPU_MEM_INT_ENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_MEM_INT_ENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010328ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_MEM_INT_ENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_MEM_INT_ENA_W1S(a) bdk_cgxx_spu_mem_int_ena_w1s_t
#define bustype_BDK_CGXX_SPU_MEM_INT_ENA_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_MEM_INT_ENA_W1S(a) "CGXX_SPU_MEM_INT_ENA_W1S"
#define device_bar_BDK_CGXX_SPU_MEM_INT_ENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_MEM_INT_ENA_W1S(a) (a)
#define arguments_BDK_CGXX_SPU_MEM_INT_ENA_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_mem_int_w1s
 *
 * CGX SPU Memory Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_mem_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1S/H) Reads or sets CGX(0..3)_SPU_MEM_INT[RX_BUF_SBE]. */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1S/H) Reads or sets CGX(0..3)_SPU_MEM_INT[RX_BUF_DBE]. */
#else /* Word 0 - Little Endian */
        uint64_t rx_buf_dbe            : 4;  /**< [  3:  0](R/W1S/H) Reads or sets CGX(0..3)_SPU_MEM_INT[RX_BUF_DBE]. */
        uint64_t rx_buf_sbe            : 4;  /**< [  7:  4](R/W1S/H) Reads or sets CGX(0..3)_SPU_MEM_INT[RX_BUF_SBE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_mem_int_w1s_s cn; */
} bdk_cgxx_spu_mem_int_w1s_t;

static inline uint64_t BDK_CGXX_SPU_MEM_INT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_MEM_INT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010318ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_MEM_INT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_MEM_INT_W1S(a) bdk_cgxx_spu_mem_int_w1s_t
#define bustype_BDK_CGXX_SPU_MEM_INT_W1S(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_MEM_INT_W1S(a) "CGXX_SPU_MEM_INT_W1S"
#define device_bar_BDK_CGXX_SPU_MEM_INT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_MEM_INT_W1S(a) (a)
#define arguments_BDK_CGXX_SPU_MEM_INT_W1S(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_mem_status
 *
 * CGX SPU Memory Status Registers
 * This register provides memory ECC status from the SPU receive buffer lane FIFOs.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_mem_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t rx_buf_ecc_synd       : 32; /**< [ 31:  0](RO/H) SPU receive buffer ECC syndromes for lanes 3-0. 8-bit syndrome sub-field per SerDes lane.
                                                                 Each
                                                                 8-bit sub-field contains the syndrome of the latest single-bit or double-bit ECC error
                                                                 detected by the associated receive buffer lane FIFO, i.e. it is loaded when the
                                                                 corresponding
                                                                 CGX()_SPU_MEM_INT[RX_BUF_SBE] or CGX()_SPU_MEM_INT[RX_BUF_DBE] bit is set. */
#else /* Word 0 - Little Endian */
        uint64_t rx_buf_ecc_synd       : 32; /**< [ 31:  0](RO/H) SPU receive buffer ECC syndromes for lanes 3-0. 8-bit syndrome sub-field per SerDes lane.
                                                                 Each
                                                                 8-bit sub-field contains the syndrome of the latest single-bit or double-bit ECC error
                                                                 detected by the associated receive buffer lane FIFO, i.e. it is loaded when the
                                                                 corresponding
                                                                 CGX()_SPU_MEM_INT[RX_BUF_SBE] or CGX()_SPU_MEM_INT[RX_BUF_DBE] bit is set. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_mem_status_s cn; */
} bdk_cgxx_spu_mem_status_t;

static inline uint64_t BDK_CGXX_SPU_MEM_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_MEM_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && (a<=3))
        return 0x87e0e8010308ll + 0x1000000ll * ((a) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_MEM_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_CGXX_SPU_MEM_STATUS(a) bdk_cgxx_spu_mem_status_t
#define bustype_BDK_CGXX_SPU_MEM_STATUS(a) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_MEM_STATUS(a) "CGXX_SPU_MEM_STATUS"
#define device_bar_BDK_CGXX_SPU_MEM_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_MEM_STATUS(a) (a)
#define arguments_BDK_CGXX_SPU_MEM_STATUS(a) (a),-1,-1,-1

/**
 * Register (RSL) cgx#_spu_sds#_skew_status
 *
 * CGX SPU SerDes Lane Skew Status Registers
 * This register provides SerDes lane skew status. One register per physical SerDes lane.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_sdsx_skew_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t skew_status           : 32; /**< [ 31:  0](RO/H) Format defined by CGX_SPU_SDS_SKEW_STATUS_S. */
#else /* Word 0 - Little Endian */
        uint64_t skew_status           : 32; /**< [ 31:  0](RO/H) Format defined by CGX_SPU_SDS_SKEW_STATUS_S. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_sdsx_skew_status_s cn; */
} bdk_cgxx_spu_sdsx_skew_status_t;

static inline uint64_t BDK_CGXX_SPU_SDSX_SKEW_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_SDSX_SKEW_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010340ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_SDSX_SKEW_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPU_SDSX_SKEW_STATUS(a,b) bdk_cgxx_spu_sdsx_skew_status_t
#define bustype_BDK_CGXX_SPU_SDSX_SKEW_STATUS(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_SDSX_SKEW_STATUS(a,b) "CGXX_SPU_SDSX_SKEW_STATUS"
#define device_bar_BDK_CGXX_SPU_SDSX_SKEW_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_SDSX_SKEW_STATUS(a,b) (a)
#define arguments_BDK_CGXX_SPU_SDSX_SKEW_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (RSL) cgx#_spu_sds#_states
 *
 * CGX SPU SerDes States Registers
 * This register provides SerDes lane states. One register per physical SerDes lane.
 */
typedef union
{
    uint64_t u;
    struct bdk_cgxx_spu_sdsx_states_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_52_63        : 12;
        uint64_t am_lock_invld_cnt     : 2;  /**< [ 51: 50](RO/H) 40GBASE-R alignment marker lock state machine invalid AM counter. */
        uint64_t am_lock_sm            : 2;  /**< [ 49: 48](RO/H) 40GBASE-R alignment marker lock state machine state. */
        uint64_t reserved_45_47        : 3;
        uint64_t train_sm              : 3;  /**< [ 44: 42](RO/H) Link training state machine state. */
        uint64_t train_code_viol       : 1;  /**< [ 41: 41](RO/H) Link training code violation in received control channel. */
        uint64_t train_frame_lock      : 1;  /**< [ 40: 40](RO/H) Link training frame lock status. */
        uint64_t train_lock_found_1st_marker : 1;/**< [ 39: 39](RO/H) Link training lock state machine found first marker flag. */
        uint64_t train_lock_bad_markers : 3; /**< [ 38: 36](RO/H) Link training lock state machine bad markers counter. */
        uint64_t reserved_35           : 1;
        uint64_t an_arb_sm             : 3;  /**< [ 34: 32](RO/H) Autonegotiation arbitration state machine state. */
        uint64_t an_rx_sm              : 2;  /**< [ 31: 30](RO/H) Autonegotiation receive state machine state. */
        uint64_t reserved_29           : 1;
        uint64_t fec_block_sync        : 1;  /**< [ 28: 28](RO/H) FEC block sync status. */
        uint64_t fec_sync_cnt          : 4;  /**< [ 27: 24](RO/H) FEC block sync state machine good/bad parity block counter. */
        uint64_t reserved_23           : 1;
        uint64_t br_sh_invld_cnt       : 7;  /**< [ 22: 16](RO/H) BASE-R lock state machine invalid sync header counter. */
        uint64_t br_block_lock         : 1;  /**< [ 15: 15](RO/H) BASE-R block lock status. */
        uint64_t br_sh_cnt             : 11; /**< [ 14:  4](RO/H) BASE-R lock state machine sync header counter */
        uint64_t bx_sync_sm            : 4;  /**< [  3:  0](RO/H) BASE-X PCS synchronization state machine state */
#else /* Word 0 - Little Endian */
        uint64_t bx_sync_sm            : 4;  /**< [  3:  0](RO/H) BASE-X PCS synchronization state machine state */
        uint64_t br_sh_cnt             : 11; /**< [ 14:  4](RO/H) BASE-R lock state machine sync header counter */
        uint64_t br_block_lock         : 1;  /**< [ 15: 15](RO/H) BASE-R block lock status. */
        uint64_t br_sh_invld_cnt       : 7;  /**< [ 22: 16](RO/H) BASE-R lock state machine invalid sync header counter. */
        uint64_t reserved_23           : 1;
        uint64_t fec_sync_cnt          : 4;  /**< [ 27: 24](RO/H) FEC block sync state machine good/bad parity block counter. */
        uint64_t fec_block_sync        : 1;  /**< [ 28: 28](RO/H) FEC block sync status. */
        uint64_t reserved_29           : 1;
        uint64_t an_rx_sm              : 2;  /**< [ 31: 30](RO/H) Autonegotiation receive state machine state. */
        uint64_t an_arb_sm             : 3;  /**< [ 34: 32](RO/H) Autonegotiation arbitration state machine state. */
        uint64_t reserved_35           : 1;
        uint64_t train_lock_bad_markers : 3; /**< [ 38: 36](RO/H) Link training lock state machine bad markers counter. */
        uint64_t train_lock_found_1st_marker : 1;/**< [ 39: 39](RO/H) Link training lock state machine found first marker flag. */
        uint64_t train_frame_lock      : 1;  /**< [ 40: 40](RO/H) Link training frame lock status. */
        uint64_t train_code_viol       : 1;  /**< [ 41: 41](RO/H) Link training code violation in received control channel. */
        uint64_t train_sm              : 3;  /**< [ 44: 42](RO/H) Link training state machine state. */
        uint64_t reserved_45_47        : 3;
        uint64_t am_lock_sm            : 2;  /**< [ 49: 48](RO/H) 40GBASE-R alignment marker lock state machine state. */
        uint64_t am_lock_invld_cnt     : 2;  /**< [ 51: 50](RO/H) 40GBASE-R alignment marker lock state machine invalid AM counter. */
        uint64_t reserved_52_63        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_cgxx_spu_sdsx_states_s cn; */
} bdk_cgxx_spu_sdsx_states_t;

static inline uint64_t BDK_CGXX_SPU_SDSX_STATES(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_CGXX_SPU_SDSX_STATES(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN9XXX) && ((a<=3) && (b<=3)))
        return 0x87e0e8010360ll + 0x1000000ll * ((a) & 0x3) + 8ll * ((b) & 0x3);
    __bdk_csr_fatal("CGXX_SPU_SDSX_STATES", 2, a, b, 0, 0);
}

#define typedef_BDK_CGXX_SPU_SDSX_STATES(a,b) bdk_cgxx_spu_sdsx_states_t
#define bustype_BDK_CGXX_SPU_SDSX_STATES(a,b) BDK_CSR_TYPE_RSL
#define basename_BDK_CGXX_SPU_SDSX_STATES(a,b) "CGXX_SPU_SDSX_STATES"
#define device_bar_BDK_CGXX_SPU_SDSX_STATES(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_CGXX_SPU_SDSX_STATES(a,b) (a)
#define arguments_BDK_CGXX_SPU_SDSX_STATES(a,b) (a),(b),-1,-1

#endif /* __BDK_CSRS_CGX_H__ */
